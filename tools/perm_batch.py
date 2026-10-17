"""Run decomp-permuter over the near-miss list, then integrate every match (run in the container).

Usage: python3 tools/perm_batch.py [--time 90] [--max-diff 10] [-j 12]

Reads build/near_misses.txt ("<diff> <size> <func>"), skips functions already in C,
permutes each remaining one from its wip/<func>.c draft for --time seconds (fewest
differences first), and finally runs auto_decomp.py --from-wip on the winners, which
verifies every touched file before writing it.
"""
import argparse, glob, os, re, subprocess

ap = argparse.ArgumentParser()
ap.add_argument('--time', type=int, default=90)
ap.add_argument('--max-diff', type=int, default=10)
ap.add_argument('-j', type=int, default=12)
args = ap.parse_args()

asm_left = set()
for c in glob.glob('src/**/*.c', recursive=True):
    asm_left |= set(re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', open(c).read()))

todo = []
for line in open('build/near_misses.txt'):
    if not re.match(r'\d+ 0x[0-9a-f]+ func_[0-9A-F]{8}$', line.strip()):
        continue  # written concurrently by worker processes; skip torn lines
    diff, size, name = line.split()
    if int(diff) <= args.max_diff and name in asm_left and os.path.exists(f'wip/{name}.c'):
        todo.append((int(diff), int(size, 16), name))
if os.path.exists('wip/_perm_queue.txt'):  # hand-written near misses
    for name in open('wip/_perm_queue.txt').read().split():
        if name in asm_left and (os.path.exists(f'wip/_hand/{name}.c') or os.path.exists(f'wip/{name}.c')):
            todo.append((0, 0, name))
todo = sorted(set(todo))
print(f'{len(todo)} functions to permute, {args.time}s each', flush=True)

won = []
for i, (diff, size, name) in enumerate(todo):
    if os.path.exists(f'wip/{name}.perm.c'):
        won.append(name)
        continue
    draft = f'wip/_hand/{name}.c' if os.path.exists(f'wip/_hand/{name}.c') else f'wip/{name}.c'
    r = subprocess.run(['python3', 'tools/permute.py', name, draft, '--run', str(args.time), '-j', str(args.j)],
                       capture_output=True, text=True)
    ok = os.path.exists(f'wip/{name}.perm.c')
    if ok:
        won.append(name)
    best = re.findall(r'best: \S*output-(\d+)', r.stdout)
    print(f'[{i + 1}/{len(todo)}] {name} ({diff} diffs, {size:#x}): '
          f'{"MATCH" if ok else "best score " + (best[0] if best else "?")}', flush=True)

print(f'{len(won)} permuter matches; integrating', flush=True)
if won:
    subprocess.run(['python3', 'tools/auto_decomp.py', '--from-wip', '--max-size', '0x10000', '--only', ','.join(won)])
