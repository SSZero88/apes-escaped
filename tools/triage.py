"""Classify why remaining asm functions don't auto-match (run in the container).

For a sample of INCLUDE_ASM functions: m2c failure, compile failure, wrong size
(with the size difference), or same size (number of differing instructions).
Usage: python3 tools/triage.py [--sample 60] [--max-size 0x400] [--seed 1]
"""
import argparse, collections, glob, os, random, re, sys

src = open('tools/auto_decomp.py').read().replace('\nmain()\n', '\n')
ad = {}
exec(compile(src, 'auto_decomp', 'exec'), ad)

ap = argparse.ArgumentParser()
ap.add_argument('--sample', type=int, default=60)
ap.add_argument('--max-size', type=lambda x: int(x, 0), default=0x400)
ap.add_argument('--seed', type=int, default=1)
ap.add_argument('--only', default='')
args = ap.parse_args()

funcs = []
for c in sorted(glob.glob('src/game/*.c')):
    for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', open(c).read()):
        asm = open(f'{folder}/{name}.s').read()
        if ad['SKIP_RE'].search(asm):
            continue
        addr, size = ad['func_info'](name)
        if size <= args.max_size:
            funcs.append((name, folder, addr, size))
if args.only:
    funcs = [f for f in funcs if f[0] in args.only.split(',')]
else:
    random.seed(args.seed)
    funcs = random.sample(funcs, min(args.sample, len(funcs)))

stats = collections.Counter()
for name, folder, addr, size in funcs:
    code = ad['m2c'](f'{folder}/{name}.s')
    if not code:
        stats['m2c-fail'] += 1
        print(f'{name} {size:#x}: m2c failed')
        continue
    decls, body = ad['split_decls'](code, name)
    body = ad['fix_unsigned_consts'](ad['fix_params'](body))
    tu = '#include "common.h"\n#include "m2c_macros.h"\n\n' + '\n'.join(decls) + '\n\n' + body
    ok, err = ad['compile_c'](tu, '2.8.1-psx', '/tmp/tri.o')
    if not ok:
        stats['compile-fail'] += 1
        print(f'{name} {size:#x}: compile error: {err.strip().splitlines()[-1] if err.strip() else "?"}')
        continue
    data, _ = ad['func_code']('/tmp/tri.o', name)
    ours = len(data or b'')
    if ours != size:
        stats['size'] += 1
        print(f'{name} {size:#x}: size {ours:#x} ({ours - size:+d} bytes)')
    else:
        stats['same-size'] += 1
        print(f'{name} {size:#x}: same size, {ad["diff_count"]("/tmp/tri.o", name, addr, size)} diffs')
print(dict(stats))
