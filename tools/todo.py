"""List remaining asm game functions, smallest first, skipping ones already handled.

Skips functions with a finished wip/<f>.perm.c, ones queued in wip/_perm_queue.txt, and
near misses (<= --near diffs) the permuter batch will take.
Usage: python tools/todo.py [-n 30] [--near 10] [--with-gte]
"""
import argparse, glob, os, re

ap = argparse.ArgumentParser()
ap.add_argument('-n', type=int, default=30)
ap.add_argument('--near', type=int, default=10)
ap.add_argument('--with-gte', action='store_true')
args = ap.parse_args()

queued = set(open('wip/_perm_queue.txt').read().split()) if os.path.exists('wip/_perm_queue.txt') else set()
near = set()
if os.path.exists('build/near_misses.txt'):
    for l in open('build/near_misses.txt'):
        f = l.split()
        if len(f) == 3 and f[0].isdigit() and int(f[0]) <= args.near:
            near.add(f[2])
gte = re.compile(r'\b(mtc2|mfc2|ctc2|cfc2|lwc2|swc2)\b')
out = []
for c in glob.glob('src/game/*.c'):
    for d, n in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', open(c).read()):
        if os.path.exists(f'wip/{n}.perm.c') or n in queued or n in near:
            continue
        s = open(f'{d}/{n}.s').read()
        if not args.with_gte and gte.search(s):
            continue
        size = int(re.search(r'nonmatching \w+, (0x[0-9A-F]+)', s).group(1), 16)
        out.append((size, n))
for size, n in sorted(out)[:args.n]:
    print(f'{size:#6x} {n}')
print(f'({len(out)} remaining)')
