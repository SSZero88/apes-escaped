"""Replace INCLUDE_ASM(...) for a function with C code.
Usage: python tools/apply.py <func_name> <file_with_c>   (use '-' for stdin)
       python tools/apply.py --revert <func_name>       (restore INCLUDE_ASM)"""
import glob, re, sys

def find_src(func):
    for p in glob.glob('src/**/*.c', recursive=True):
        s = open(p, encoding='utf-8').read()
        if re.search(rf'INCLUDE_ASM\("[^"]+", {func}\);', s) or re.search(rf'^\S[^;]*\b{func}\(', s, re.M):
            return p, s
    sys.exit(f'{func}: not found in src/')

if sys.argv[1] == '--revert':
    func = sys.argv[2]; p, s = find_src(func)
    seg = p[4:-2]
    # remove a C function body starting at a line containing "func(" and ending at a line "}"
    m = re.search(rf'^[^\n;]*\b{func}\([^;]*?\n}}\n', s, re.M | re.S)
    if not m: sys.exit('no C body found')
    s = s[:m.start()] + f'INCLUDE_ASM("asm/nonmatchings/{seg}", {func});\n' + s[m.end():]
    open(p, 'w', encoding='utf-8').write(s); print('reverted', func, 'in', p); sys.exit()

func, src = sys.argv[1], sys.argv[2]
code = (sys.stdin.read() if src == '-' else open(src, encoding='utf-8').read()).strip() + '\n'
p, s = find_src(func)
pat = re.compile(rf'INCLUDE_ASM\("[^"]+", {func}\);\n')
if not pat.search(s): sys.exit(f'{func}: no INCLUDE_ASM in {p}')
s = pat.sub(lambda m: code, s, count=1)
open(p, 'w', encoding='utf-8').write(s); print('applied', func, 'to', p)
