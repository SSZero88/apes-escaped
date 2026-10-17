"""Map each data-segment symbol to the game/lib file(s) whose functions reference it.

Prints runs of consecutive symbols with the same owner, in address order, so the
.rodata block of each original object (which PsyQ's linker lays out in object order,
after all .text) shows up as a run of increasing file addresses.
Usage: python tools/rodata_owners.py [--limit 0x800A5000]
"""
import argparse, glob, os, re

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=lambda x: int(x, 0), default=0x800B5000)
args = ap.parse_args()

syms = [(int(a, 16), n) for n, a in re.findall(r'^dlabel ((?:D|jtbl)_([0-9A-F]{8}))', open('asm/data/data.data.s').read(), re.M)]
syms.sort()
refs = {}
for path in glob.glob('asm/nonmatchings/**/*.s', recursive=True):
    owner = os.path.basename(os.path.dirname(path))
    for n in set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', open(path).read())):
        refs.setdefault(n, set()).add(owner)
for path in glob.glob('src/**/*.c', recursive=True):
    owner = os.path.splitext(os.path.basename(path))[0]
    body = re.sub(r'INCLUDE_ASM\([^)]*\);', '', open(path).read())
    for n in set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', body)):
        refs.setdefault(n, set()).add(owner)
for path in glob.glob('asm/*.s'):
    owner = os.path.splitext(os.path.basename(path))[0]
    for n in set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', open(path).read())):
        refs.setdefault(n, set()).add(owner)

run = None
for addr, name in syms:
    if addr >= args.limit:
        break
    own = ','.join(sorted(refs.get(name, {'?'})))
    if run and run[2] == own:
        run[1] = addr; run[3] += 1
    else:
        if run: print(f'{run[0]:08X}-{run[1]:08X} {run[3]:4} {run[2]}')
        run = [addr, addr, own, 1]
print(f'{run[0]:08X}-{run[1]:08X} {run[3]:4} {run[2]}')
