"""Turn a function definition into an old-style (K&R) one, so callers that pass fewer or
more arguments (the original code did) still compile. Only for parameters that don't
change with the default promotions (pointers, s32/u32): the generated code is the same.
Usage: python tools/knr.py src/game/X.c func_A [func_B ...]
"""
import re, sys

path, names = sys.argv[1], sys.argv[2:]
text = open(path).read()
for n in names:
    m = re.search(rf'^(\w[\w \*]*?\**\s*\b{n})\(([^;{{)]*)\)(\s*)\{{$', text, re.M)
    assert m, n
    params = [p.strip() for p in m.group(2).split(',') if p.strip() and p.strip() != 'void']
    pnames = [re.search(r'(\w+)\s*$', p).group(1) for p in params]
    for p in params:
        assert re.search(r'\*|\b[su]32\b|\bint\b', p), f'{n}: {p} would be promoted'
    new = f'{m.group(1)}({", ".join(pnames)})\n' + ''.join(f'{p};\n' for p in params) + '{'
    text = text[:m.start()] + new + text[m.end():]
    ret = m.group(1)[:-len(n)]
    # prototypes only: they start in column 0 (calls are indented)
    text = re.sub(rf'^\w[\w \*]*\b{n}\([^;{{]*\);$', f'{ret}{n}();', text, flags=re.M)
open(path, 'w', newline='\n').write(text)
print(f'{path}: {", ".join(names)} now K&R')
