"""Set up (and optionally run) decomp-permuter for one near-miss function (run in the container).

Usage: python3 tools/permute.py <func> <draft.c> [--run SECONDS] [-j 8]

Creates build/perm/<func>/ with
  base.c      the draft, preprocessed together with game.h/m2c_macros.h
  target.o    the original function, assembled from asm/nonmatchings
  compile.sh  the exact cpp | cc1 | maspsx | as pipeline
With --run, permutes for that many seconds and reports the best result; any
score-0 output is a match (check it with tools/check_c.py, then integrate).
"""
import argparse, glob, os, re, shutil, subprocess, sys

ap = argparse.ArgumentParser()
ap.add_argument('func')
ap.add_argument('draft')
ap.add_argument('--run', type=int, default=0)
ap.add_argument('-j', type=int, default=os.cpu_count())
args = ap.parse_args()

asm_path = glob.glob(f'asm/nonmatchings/**/{args.func}.s', recursive=True)[0]
d = f'build/perm/{args.func}'
shutil.rmtree(d, ignore_errors=True)
os.makedirs(d)

CPP = ('mips-linux-gnu-cpp -P -Iinclude -Isrc -undef -lang-c -fno-builtin -D__GNUC__=2 -Dmips -D__mips__ '
       '-D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C')
# as check_c.py: game.h first (drafts using Monkey / D_800B4D08), common.h if that doesn't compile
for hdr in ('game.h', 'common.h'):
    tu = f'#include "{hdr}"\n#include "m2c_macros.h"\n\n' + open(args.draft).read()
    r = subprocess.run(CPP + ' -DPERMUTER -DM2CTX -', shell=True, input=tu, capture_output=True, text=True)
    if r.returncode:
        continue
    c = subprocess.run('/opt/cc/2.8.1-psx/cc1 -quiet -w -O2 -mhard-float -G0 -o /dev/null', shell=True,
                       input=r.stdout, capture_output=True, text=True)
    if c.returncode == 0:
        break
if r.returncode:
    sys.exit(r.stderr)
open(f'{d}/base.c', 'w').write(r.stdout)

s = f'{d}/target.s'
open(s, 'w').write('.include "include/macro.inc"\n.set noat\n.set noreorder\n.section .text\n'
                   f'.include "{asm_path}"\n')
r = subprocess.run(['mips-linux-gnu-as', '-Iinclude', '-march=r3000', '-mtune=r3000', '-no-pad-sections',
                    '-EL', '-G0', '-o', f'{d}/target.o', s], capture_output=True, text=True)
if r.returncode:
    sys.exit(r.stderr)

open(f'{d}/compile.sh', 'w').write(
    '#!/bin/bash\nset -o pipefail\n'
    '/opt/cc/2.8.1-psx/cc1 -quiet -mcpu=3000 -fgnu-linker -mgas -gcoff -w -O2 -mhard-float -G0 < "$1" '
    '| python3 /work/tools/maspsx/maspsx.py --aspsx-version=2.79 --expand-div --use-comm-section '
    # GTE opcodes (rtpt, cc, ...) are macros from macro.inc, which the build gets via include_asm.h
    '| { echo \'.include "/work/include/macro.inc"\'; cat; } '
    '| mips-linux-gnu-as -I/work/include -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -EL -o "$3"\n')
os.chmod(f'{d}/compile.sh', 0o755)
open(f'{d}/settings.toml', 'w').write(f'func_name = "{args.func}"\ncompiler_type = "gcc"\n')
print(f'set up {d}')

if args.run:
    # own process group, so its worker processes die with it on timeout
    p = subprocess.Popen(['python3', '/opt/permuter/permuter.py', d, '-j', str(args.j), '--stop-on-zero', '--best-only'],
                         start_new_session=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    try:
        p.wait(timeout=args.run)
    except subprocess.TimeoutExpired:
        os.killpg(p.pid, 9)
        p.wait()
    outs = sorted(glob.glob(f'{d}/output-*'), key=lambda p: int(re.match(r'.*output-(\d+)', p).group(1)))
    print('best:', outs[0] if outs else 'none')
    if outs and re.match(r'.*output-0-', outs[0]):
        # keep the draft's own declarations, take the permuted function
        src = open(f'{outs[0]}/source.c').read()
        m = re.search(rf'^[^\n;]*\b{args.func}\([^;{{]*\)\s*\{{', src, re.M)
        depth, i = 0, src.index('{', m.end() - 1)
        for j in range(i, len(src)):
            depth += {'{': 1, '}': -1}.get(src[j], 0)
            if depth == 0:
                break
        draft = open(args.draft).read()
        dm = re.search(rf'^[^\n;]*\b{args.func}\([^;{{]*\)\s*\{{', draft, re.M)
        out = draft[:dm.start()] + src[m.start():j + 1] + '\n'
        open(f'wip/{args.func}.perm.c', 'w').write(out)
        print(f'MATCH -> wip/{args.func}.perm.c')
