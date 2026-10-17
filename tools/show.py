"""Print a function's asm (compact) and its transformed m2c draft (run in the container).
Usage: python3 tools/show.py func_80012345 [--no-asm]"""
import glob, re, sys

src = open('tools/auto_decomp.py').read().replace('\nmain()\n', '\n')
ad = {}
exec(compile(src, 'auto_decomp', 'exec'), ad)

name = sys.argv[1]
path = glob.glob(f'asm/nonmatchings/**/{name}.s', recursive=True)[0]
if '--no-asm' not in sys.argv:
    for l in open(path):
        l = re.sub(r'/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s*', r'\1 ', l.rstrip())
        if l.strip() and not l.startswith(('nonmatching', 'glabel', 'endlabel')):
            print(l)
    print()
code = ad['m2c'](path)
if not code:
    print('(m2c failed)')
    sys.exit()
d, b = ad['split_decls'](code, name)
b = ad['fix_struct_copies'](ad['fix_unsigned_consts'](ad['fix_params'](b)))
s = ad['structify'](d, ad['fix_addr_offsets'](b))
if s:
    d, b = s
print('\n'.join(d) + '\n\n' + b)
