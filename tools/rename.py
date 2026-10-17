"""Give symbols readable names everywhere at once.

Usage: python tools/rename.py names.txt      (lines: old_name new_name   # comment)
       python tools/rename.py old_name new_name

For each pair, the old name is replaced as a whole word in src/, include/, asm/ (including
the asm/nonmatchings/<file>/<name>.s file name), the splat config files, docs/, README.md and
wip/ drafts, and `new_name = 0xADDR;` is added to symbol_addrs.txt so a re-split keeps it.
The address comes from the old name (func_XXXXXXXX / D_XXXXXXXX). Run ./make.sh afterwards:
names don't change the code, so the build must still say OK.
"""
import glob, os, re, sys

TEXT_GLOBS = ['src/**/*.c', 'src/**/*.h', 'include/**/*.h', 'asm/**/*.s', 'docs/**/*.md',
              'README.md', 'wip/**/*.c', 'wip/**/*.txt', 'wip/_try/*', 'symbol_addrs.txt',
              'undefined_funcs_auto.txt', 'undefined_syms_auto.txt', 'scus_944.23.ld']


def pairs_from_args():
    if len(sys.argv) == 3:
        return [(sys.argv[1], sys.argv[2])]
    out = []
    for line in open(sys.argv[1]):
        line = line.split('#')[0].split()
        if len(line) == 2:
            out.append(tuple(line))
    return out


def main():
    pairs = pairs_from_args()
    for old, new in pairs:
        if not re.fullmatch(r'[A-Za-z_]\w*', new):
            sys.exit(f'bad name {new!r}')
    names = {old: new for old, new in pairs}
    taken = set(re.findall(r'^(\w+)\s*=', open('symbol_addrs.txt').read(), re.M))
    for old, new in pairs:
        if new in taken or glob.glob(f'asm/nonmatchings/**/{new}.s', recursive=True):
            sys.exit(f'{new} is already used')
    word = re.compile(r'\b(' + '|'.join(map(re.escape, names)) + r')\b')
    files = set()
    for g in TEXT_GLOBS:
        files.update(p for p in glob.glob(g, recursive=True) if os.path.isfile(p))
    changed = 0
    for p in sorted(files):
        try:
            s = open(p, encoding='utf-8').read()
        except UnicodeDecodeError:
            continue
        t = word.sub(lambda m: names[m.group(1)], s)
        if t != s:
            open(p, 'w', encoding='utf-8', newline='\n').write(t)
            changed += 1
    for old, new in pairs:
        for p in glob.glob(f'asm/nonmatchings/**/{old}.s', recursive=True):
            os.rename(p, os.path.join(os.path.dirname(p), f'{new}.s'))
    sym = open('symbol_addrs.txt').read()
    add = []
    for old, new in pairs:
        m = re.fullmatch(r'(func|D)_([0-9A-F]{8})', old)
        if m and not re.search(rf'^{new} = ', sym, re.M):
            kind = 'func' if m.group(1) == 'func' else 'data'
            add.append(f'{new} = 0x{m.group(2)}; // type:{kind}')
    if add:
        with open('symbol_addrs.txt', 'a', newline='\n') as f:
            if not sym.endswith('\n'):
                f.write('\n')
            f.write('\n'.join(add) + '\n')
    for p in glob.glob('src/**/*.c', recursive=True):  # INCLUDE_ASM'd .s files aren't make dependencies
        os.utime(p)
    print(f'{len(pairs)} names, {changed} files changed, {len(add)} symbol_addrs entries added')


main()
