"""Build a function-signature database for m2c context (run inside the container).

Signatures come from (in priority order):
  1. functions already decompiled in src/ (their real definitions)
  2. include/psyq.h (hand-written PsyQ library prototypes)
  3. m2c's own inference on each remaining asm function, iterated so that
     pass-through arguments propagate from callees to callers.
Output: build/sigs.json  {name: "prototype;"}

Usage: python3 tools/gen_sigs.py [--iters 2]
"""
import argparse, glob, json, multiprocessing, os, re, subprocess, tempfile

DEF_RE = re.compile(r'^((?:static\s+)?[A-Za-z_][\w \*]*?\**\s*\b(func_[0-9A-F]{8}|\w+)\s*\(([^;{)]*)\))\s*\{', re.M)
PROTO_RE = re.compile(r'^([A-Za-z_][\w \*]*?\**\s*\b(\w+)\s*\([^;{]*\))\s*;', re.M)


def m2c_sig(job):
    name, asm_path, ctx = job
    asm = re.sub(r'^nonmatching .*\n', '', open(asm_path).read(), flags=re.M)
    with tempfile.NamedTemporaryFile('w', suffix='.s', delete=False) as t:
        t.write(asm)
    r = subprocess.run(['python3', '-m', 'm2c.main', '--target', 'mipsel-gcc-c', '--valid-syntax',
                        '--context', ctx, t.name], capture_output=True, text=True)
    os.unlink(t.name)
    m = re.search(rf'^([^\n;]*\b{name}\([^;{{]*\))\s*\{{', r.stdout, re.M)
    return name, (fix_params(m.group(1).strip()) + ';') if m else None


def fix_params(proto):
    """m2c names parameters by register (arg1 = $a1) and drops unused leading ones; restore them."""
    m = re.search(r'\(([^()]*)\)$', proto)
    if not m or m.group(1).strip() in ('', 'void'):
        return proto
    params = [p.strip() for p in m.group(1).split(',')]
    idx = [re.search(r'\barg(\d)$', p) for p in params]
    if not all(idx):
        return proto
    idx = [int(a.group(1)) for a in idx]
    if idx == list(range(len(idx))):
        return proto
    have = dict(zip(idx, params))
    return proto[:m.start(1)] + ', '.join(have.get(i, f's32 arg{i}') for i in range(max(idx) + 1)) + ')'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--iters', type=int, default=2)
    args = ap.parse_args()

    fixed = {}
    for c in glob.glob('src/**/*.c', recursive=True):
        for m in DEF_RE.finditer(open(c).read()):
            if m.group(2) not in ('if', 'while', 'for', 'switch'):
                fixed[m.group(2)] = m.group(1).replace('static ', '').strip() + ';'
    if os.path.exists('include/psyq.h'):
        for m in PROTO_RE.finditer(open('include/psyq.h').read()):
            fixed.setdefault(m.group(2), m.group(1).strip() + ';')

    asm_funcs = {}
    for c in glob.glob('src/**/*.c', recursive=True):
        for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', open(c).read()):
            asm_funcs[name] = f'{folder}/{name}.s'

    hdr = open('include/common.h').read() + open('include/m2c_macros.h').read()
    hdr = re.sub(r'^#include .*$', '', hdr, flags=re.M)
    base = subprocess.run(['mips-linux-gnu-cpp', '-P', '-undef', '-DM2CTX', '-'], input=hdr,
                          capture_output=True, text=True).stdout

    sigs = dict(fixed)
    pool = multiprocessing.Pool(os.cpu_count())
    for it in range(args.iters):
        ctx = '/tmp/sigs_ctx.c'
        with open(ctx, 'w') as fh:
            fh.write(base + '\n' + '\n'.join(sigs.values()) + '\n')
        # a function must not see its own (possibly wrong) prototype
        jobs = [(n, p, ctx) for n, p in asm_funcs.items()]
        changed = 0
        for name, sig in pool.map(m2c_sig, jobs, chunksize=8):
            if sig and sigs.get(name) != sig:
                sigs[name] = sig
                changed += 1
        print(f'iter {it}: {changed} signatures changed, {len(sigs)} total', flush=True)
    os.makedirs('build', exist_ok=True)
    json.dump(sigs, open('build/sigs.json', 'w'), indent=0, sort_keys=True)


main()
