"""Write a rebuilt file (normally build/SCUS_944.23) into a copy of the PS1 disc image.

Usage: python tools/patch_disc.py <original.bin> <out.bin> [--file SCUS_944.23] [--src build/SCUS_944.23]

The file is written in place over its existing sectors, with each sector's EDC/ECC
recomputed (MODE2/2352, Form 1). It may be shorter than the original, or longer as
long as it still fits in the sectors the original file used. When the size changes,
the ISO9660 directory record is updated too. A .cue file is written next to <out.bin>.
"""
import argparse, os, shutil, struct, sys

SECTOR = 2352
DATA = 24  # Mode 2 Form 1: 12 sync + 4 header + 8 subheader

# EDC/ECC tables (CD-ROM "Yellow Book" / ECMA-130), after Neill Corlett's ECM
ECC_F = [0] * 256
ECC_B = [0] * 256
EDC_LUT = [0] * 256
for i in range(256):
    j = ((i << 1) ^ (0x11D if i & 0x80 else 0)) & 0xFF
    ECC_F[i] = j
    ECC_B[i ^ j] = i
    e = i
    for _ in range(8):
        e = (e >> 1) ^ (0xD8018001 if e & 1 else 0)
    EDC_LUT[i] = e


def edc(data):
    e = 0
    for b in data:
        e = (e >> 8) ^ EDC_LUT[(e ^ b) & 0xFF]
    return e


def ecc_block(sec, major_count, minor_count, major_mult, minor_inc, dest):
    src = 0xC
    size = major_count * minor_count
    for major in range(major_count):
        index = (major >> 1) * major_mult + (major & 1)
        a = b = 0
        for _ in range(minor_count):
            t = sec[src + index]
            index += minor_inc
            if index >= size:
                index -= size
            a ^= t
            b ^= t
            a = ECC_F[a]
        a = ECC_B[ECC_F[a] ^ b]
        sec[dest + major] = a
        sec[dest + major + major_count] = a ^ b


def fix_form1(sec):
    """Recompute EDC and P/Q ECC of a Mode 2 Form 1 sector (bytearray of 2352)."""
    struct.pack_into('<I', sec, 0x818, edc(sec[0x10:0x818]))
    hdr = bytes(sec[12:16])
    sec[12:16] = b'\0\0\0\0'  # Mode 2: the header is excluded from ECC
    ecc_block(sec, 86, 24, 2, 86, 0x81C)
    ecc_block(sec, 52, 43, 86, 88, 0x8C8)
    sec[12:16] = hdr


def find_file(f, path):
    """Return (lba, size, record_lba, record_offset) of an ISO9660 file."""
    def sec(n):
        f.seek(n * SECTOR + DATA)
        return f.read(2048)
    pvd = sec(16)
    assert pvd[1:6] == b'CD001', 'not an ISO9660 MODE2/2352 image'
    lba, size = struct.unpack_from('<I', pvd, 158)[0], struct.unpack_from('<I', pvd, 166)[0]
    parts = [p.upper() for p in path.replace('\\', '/').split('/') if p]
    for depth, want in enumerate(parts):
        found = None
        for s in range((size + 2047) // 2048):
            data, i = sec(lba + s), 0
            while i < 2048 and data[i]:
                r = data[i:i + data[i]]
                name = r[33:33 + r[32]].decode('latin-1').split(';')[0].upper()
                if name == want:
                    found = (struct.unpack_from('<I', r, 2)[0], struct.unpack_from('<I', r, 10)[0],
                             lba + s, i, r[25] & 2)
                    break
                i += data[i]
            if found:
                break
        if not found:
            sys.exit(f'{path}: not found on disc')
        lba, size, rec_lba, rec_off, is_dir = found
        if depth < len(parts) - 1 and not is_dir:
            sys.exit(f'{path}: {want} is not a directory')
    return lba, size, rec_lba, rec_off


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('original')
    ap.add_argument('out')
    ap.add_argument('--file', default='SCUS_944.23', help='path of the file on the disc')
    ap.add_argument('--src', default='build/SCUS_944.23', help='new contents')
    args = ap.parse_args()

    new = open(args.src, 'rb').read()
    if os.path.abspath(args.original) != os.path.abspath(args.out):
        os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
        shutil.copyfile(args.original, args.out)

    with open(args.out, 'r+b') as f:
        lba, old_size, rec_lba, rec_off = find_file(f, args.file)
        nsec = (old_size + 2047) // 2048
        if len(new) > nsec * 2048:
            sys.exit(f'{args.src} is {len(new):#x} bytes, but only {nsec * 2048:#x} fit in place '
                     f'(the original was {old_size:#x}). Shrink it or relocate the file.')
        changed = 0
        for k in range(nsec):
            f.seek((lba + k) * SECTOR)
            sec = bytearray(f.read(SECTOR))
            assert sec[0x12] & 0x20 == 0, f'sector {lba + k} is Form 2'
            chunk = new[k * 2048:(k + 1) * 2048]
            body = chunk + bytes(2048 - len(chunk))
            if sec[DATA:DATA + 2048] == body:
                continue
            sec[DATA:DATA + 2048] = body
            fix_form1(sec)
            f.seek((lba + k) * SECTOR)
            f.write(sec)
            changed += 1
        if len(new) != old_size:
            f.seek(rec_lba * SECTOR)
            sec = bytearray(f.read(SECTOR))
            o = DATA + rec_off
            struct.pack_into('<I', sec, o + 10, len(new))
            struct.pack_into('>I', sec, o + 14, len(new))
            fix_form1(sec)
            f.seek(rec_lba * SECTOR)
            f.write(sec)
            print(f'size {old_size:#x} -> {len(new):#x}')

    cue = os.path.splitext(args.out)[0] + '.cue'
    with open(cue, 'w') as c:
        c.write(f'FILE "{os.path.basename(args.out)}" BINARY\n  TRACK 01 MODE2/2352\n    INDEX 01 00:00:00\n')
    print(f'{args.file}: {changed} of {nsec} sectors changed -> {args.out}')


if __name__ == '__main__':
    main()
