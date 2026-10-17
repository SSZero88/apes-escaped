"""Make each src file include its jump tables' padding symbols (idempotent; run after a split).

post_split.py cuts the zero words after a jump table into `<jtbl>_pad`. Its INCLUDE_RODATA
goes right after the table's own line, or, when the switch is already C (no table line),
right after the function the table's entries point into.
Usage: python tools/add_jtbl_pads.py
"""
import glob, os, re

for pad in sorted(glob.glob('asm/nonmatchings/game/*/jtbl_*_pad.s')):
    folder = os.path.dirname(pad).replace('\\', '/')
    fileid = os.path.basename(folder)
    sym = os.path.basename(pad)[:-2]
    tbl = sym[:-4]
    src = f'src/game/{fileid}.c'
    text = open(src).read()
    if f', {sym});' in text:
        continue
    line = f'INCLUDE_RODATA("{folder}", {sym});\n'
    tline = f'INCLUDE_RODATA("{folder}", {tbl});\n'
    if tline in text:
        text = text.replace(tline, tline + line, 1)
    else:
        target = int(re.search(r'\.word 0x([0-9A-F]{8})', open(f'{folder}/{tbl}.s').read()).group(1), 16)
        funcs = sorted((int(a, 16), a) for a in re.findall(r'^\w[^\n;]*\bfunc_([0-9A-F]{8})\([^;]*$', text, re.M))
        owner = max((f for f in funcs if f[0] <= target), default=None)
        if owner is None:
            raise SystemExit(f'{sym}: no C function owns {target:#x} in {src}')
        m = re.search(rf'^\w[^\n;]*\bfunc_{owner[1]}\([^;]*$.*?^\}}\n', text, re.M | re.S)
        text = text[:m.end()] + '\n' + line + text[m.end():]
    open(src, 'w', newline='\n').write(text)
    print(f'{src}: + {sym}')
