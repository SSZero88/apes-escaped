"""Run auto_decomp's verify_file() on every src file (run in the container): each C function
must compile alone to the original bytes, and each file's .rodata must match too.
Failing files are re-checked function by function and the culprits are listed.
Usage: python3 tools/verify_all.py [src/game/X.c ...]"""
import glob, os, re, sys
src = open('tools/auto_decomp.py').read()
ad = {}
exec(compile(src, 'auto_decomp', 'exec'), ad)
files = sys.argv[1:] or sorted(glob.glob('src/game/*.c'))
bad = [f for f in files if not ad['verify_file'](open(f).read(), '2.8.1-psx', f)]
for f in bad:
    text = open(f).read()
    o = f'/tmp/va_{os.getpid()}.o'
    good, err = ad['compile_c'](text, '2.8.1-psx', o)
    if not good:
        print(f'{f}: does not compile\n{err}')
        continue
    for name in ad['game_funcs'](text):
        if not ad['matches'](o, name, *ad['game_func_info'](o, name)):
            print(f'{f}: {name} differs')
    if not ad['rodata_matches'](o, ad['rodata_start'](f)):
        print(f'{f}: .rodata differs')
print('all files verify' if not bad else 'FAILING: ' + ' '.join(bad))
sys.exit(1 if bad else 0)
