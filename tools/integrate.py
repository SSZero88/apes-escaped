"""Move a checked function from wip/<func>.c into its src file.

Usage: python tools/integrate.py func_80012345 [func_...]

The wip file holds top-level declarations followed by the function definition.
Declarations not already present in the target file are added below its #includes;
the INCLUDE_ASM line for the function is replaced by the definition.
Run make afterwards: the sha1 check is the final word.
"""
import glob, re, sys


def find_src(func):
    for p in glob.glob('src/**/*.c', recursive=True):
        s = open(p, encoding='utf-8').read()
        if re.search(rf'INCLUDE_ASM\("[^"]+", {func}\);', s):
            return p, s
    sys.exit(f'{func}: no INCLUDE_ASM found in src/')


def split(code, func):
    m = re.search(rf'^[^\n;]*\b{func}\([^;]*?\{{', code, re.M | re.S)
    if not m:
        sys.exit(f'{func}: definition not found in wip file')
    decls = [l.rstrip() for l in code[:m.start()].splitlines() if l.strip()]
    return decls, code[m.start():].strip() + '\n'


for func in sys.argv[1:]:
    decls, body = split(open(f'wip/{func}.c', encoding='utf-8').read(), func)
    path, text = find_src(func)
    lines = set(text.splitlines())
    new = [d for d in decls if d not in lines]
    text = re.sub(rf'INCLUDE_ASM\("[^"]+", {func}\);\n', lambda m: body, text, count=1)
    if new:
        # after the last #include line
        incs = list(re.finditer(r'^#include .*\n', text, re.M))
        at = incs[-1].end() if incs else 0
        text = text[:at] + '\n' + '\n'.join(new) + '\n' + text[at:]
    open(path, 'w', encoding='utf-8').write(text)
    print(f'{func} -> {path} (+{len(new)} decls)')
