"""Extract files from a PS1 MODE2/2352 .bin image (ISO9660).
Usage: python tools/extract_iso.py <image.bin> <outdir>
.STR/.XA streaming files (Mode 2 Form 2) are skipped; they are FMV/audio only."""
import os, struct, sys

def main(img, out):
    f = open(img, 'rb')
    def sec(n):
        f.seek(n * 2352 + 24)
        return f.read(2048)
    pvd = sec(16)
    assert pvd[1:6] == b'CD001'
    root = pvd[156:190]
    def walk(lba, size, rel):
        data = b''.join(sec(lba + i) for i in range((size + 2047) // 2048))
        i = 0
        while i < len(data):
            l = data[i]
            if l == 0:
                i = (i // 2048 + 1) * 2048
                continue
            r = data[i:i + l]; i += l
            elba, esz = struct.unpack('<I', r[2:6])[0], struct.unpack('<I', r[10:14])[0]
            name = r[33:33 + r[32]]
            if name in (b'\0', b'\1'):
                continue
            name = name.decode().split(';')[0]
            path = os.path.join(rel, name)
            if r[25] & 2:
                os.makedirs(os.path.join(out, path), exist_ok=True)
                walk(elba, esz, path)
            elif name.upper().endswith(('.STR', '.XA')):
                print('skip  ', path)
            else:
                body = b''.join(sec(elba + k) for k in range((esz + 2047) // 2048))[:esz]
                open(os.path.join(out, path), 'wb').write(body)
                print('wrote ', path, esz)
    os.makedirs(out, exist_ok=True)
    walk(struct.unpack('<I', root[2:6])[0], struct.unpack('<I', root[10:14])[0], '')

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
