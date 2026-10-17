"""List gaps (padding) between functions in the asm: candidate original file boundaries."""
import glob, re, collections
funcs = []
for p in glob.glob('asm/nonmatchings/*/*.s') + glob.glob('asm/*.s'):
    for m in re.finditer(r'^nonmatching (\w+), (0x[0-9A-F]+)\n\nglabel \1\n    /\* [0-9A-F]+ ([0-9A-F]{8})', open(p).read(), re.M):
        funcs.append((int(m.group(3), 16), int(m.group(2), 16), m.group(1), p))
funcs.sort()
c = collections.Counter()
for (a, s, n, p), (na, _, nn, _) in zip(funcs, funcs[1:]):
    g = na - (a + s)
    if g:
        c[(g, na % 16)] += 1
        print(f'{a+s:08X} gap {g:2d} -> {nn} @ {na:08X} (mod16={na%16}) [{p.split("/")[-2] if "nonmatchings" in p else p}]')
print(len(funcs), 'funcs', dict(c))
