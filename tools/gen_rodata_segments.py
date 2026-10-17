"""Print splat subsegments that split the exe's .rodata per original object file.

PsyQ's linker lays out each object's .rodata in object order after all .text, so
every game file's jump tables, strings and constants form one run. A file's run starts
at the first symbol referenced only by that file's functions; symbols referenced by
nobody, by several files, or by library code stay with the run before them, and
library-owned symbols start an anonymous (asm) run.

Usage: python3 tools/gen_rodata_segments.py [--start 0x800A37F0] [--end 0x800A6AB0]
       (needs asm/ from a split with the old single data segment)
"""
import argparse, glob, os, re

VRAM, OFF = 0x80010000, 0x800

ap = argparse.ArgumentParser()
ap.add_argument('--start', type=lambda x: int(x, 0), default=0x800A37F0)
ap.add_argument('--end', type=lambda x: int(x, 0), default=0x800A6AB0)
args = ap.parse_args()

# game files in link order, from the yaml
order = re.findall(r'^\s*- \[0x[0-9A-Fa-f]+, c, (game/[0-9A-F]{8})\]', open('scus_944.23.yaml').read(), re.M)
rank = {name: i for i, name in enumerate(order)}

syms = sorted((int(a, 16), n) for n, a in re.findall(r'^dlabel ((?:D|jtbl)_([0-9A-F]{8}))',
                                                     open('asm/data/data.data.s').read(), re.M))
refs = {}
for path in glob.glob('asm/nonmatchings/game/*/*.s'):
    owner = 'game/' + os.path.basename(os.path.dirname(path))
    for n in set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', open(path).read())):
        refs.setdefault(n, set()).add(owner)
for path in glob.glob('asm/*.s'):
    owner = 'lib'
    for n in set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', open(path).read())):
        refs.setdefault(n, set()).add(owner)

runs = []  # (addr, owner or None for anonymous)
cur = None
for addr, name in syms:
    if not (args.start <= addr < args.end):
        continue
    own = refs.get(name, set())
    if len(own) == 1:
        (o,) = own
        if o == 'lib':
            if cur != 'lib':
                runs.append((addr, None))
                cur = 'lib'
        elif o != cur and (cur in (None, 'lib') or rank[o] > rank.get(cur, -1)):
            if any(r[1] == o for r in runs):
                continue  # already had a run: a stray shared reference, not a new object
            runs.append((addr, o))
            cur = o
    elif not runs:
        runs.append((addr, None))
        cur = 'lib'

for addr, owner in runs:
    off = addr - VRAM + OFF
    print(f'      - [{off:#X}, .rodata, {owner}]' if owner else f'      - [{off:#X}, rodata]')
print(f'      - [{args.end - VRAM + OFF:#X}, data, data]')
