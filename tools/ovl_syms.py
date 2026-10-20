"""Record every function start of each overlay in ovl/<file>.sym.txt (from the func_XXXXXXXX names in
its src/ovl files), so a re-split finds the same functions: splat doesn't disassemble functions
that are already C, and their calls were what marked some neighbours' starts.
Keeps existing lines (named symbols). Usage: python3 tools/ovl_syms.py"""
import glob, os, re

for y in sorted(glob.glob('ovl/*.yaml')):
    n = os.path.basename(y)[:-5]
    srcs = [f for f in glob.glob('src/ovl/*.c') if re.fullmatch(rf'{n}[a-h]?(_\w+)?', os.path.basename(f)[:-2])]
    names = set()
    for f in srcs:
        names |= set(re.findall(r'\bfunc_([0-9A-F]{8})\b', open(f).read()))
    p = f'ovl/{n}.sym.txt'
    old = open(p).read().splitlines() if os.path.exists(p) else []
    have = {re.match(r'(\w+) =', l).group(1) for l in old if re.match(r'\w+ =', l)}
    ytext = open(y).read()
    lo = int(re.search(r'vram: (0x[0-9A-F]+)', ytext).group(1), 16)
    hi = lo + int(re.findall(r'^  - \[(0x[0-9A-F]+)\]$', ytext, re.M)[-1], 16)
    add = [f'func_{a} = 0x{a}; // type:func' for a in sorted(names)
           if f'func_{a}' not in have and lo <= int(a, 16) < hi]  # calls into SCUS have func_ names too
    open(p, 'w', newline='').write('\n'.join(old + add) + '\n')
