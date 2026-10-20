"""Extract the code overlays from the KKIIDDZZ file table into iso/ovl/<file>.bin.

KKIIDDZZ.HED holds one word per file: start sector (low 20 bits) and size in sectors (high 12),
counted from the start of KKIIDDZZ.DAT; files past DAT's end are in KKIIDDZZ.BNS, which follows
it on the disc. Files 384-395 and 427-431 are the game-mode overlays (loaded at 0x80136000 by
the mode table D_800AFA30), 396-426 the world overlays (0x8013D000, from the stage load lists).
"""
import os, struct

OVERLAYS = list(range(384, 432))


def kfile_reader(iso='iso'):
    hed = struct.unpack('<512I', open(f'{iso}/KKIIDDZZ.HED', 'rb').read())
    dat = open(f'{iso}/KKIIDDZZ.DAT', 'rb').read()
    bns = open(f'{iso}/KKIIDDZZ.BNS', 'rb').read()
    dat_sectors = len(dat) // 2048

    def kfile(i):
        sector, size = hed[i] & 0xFFFFF, (hed[i] >> 20) * 2048
        if sector < dat_sectors:
            return dat[sector * 2048:sector * 2048 + size]
        sector -= dat_sectors
        return bns[sector * 2048:sector * 2048 + size]
    return kfile


if __name__ == '__main__':
    kfile = kfile_reader()
    os.makedirs('iso/ovl', exist_ok=True)
    for i in OVERLAYS:
        open(f'iso/ovl/{i}.bin', 'wb').write(kfile(i))
    print(f'extracted {len(OVERLAYS)} overlays to iso/ovl/')
