"""Give one overlay's symbols readable names (tools/rename.py does SCUS; overlay func_/D_ names
repeat across overlays, so this only touches the one overlay).

Usage: python tools/ovl_rename.py OVL names.txt      (lines: old_name new_name   # comment)
       python tools/ovl_rename.py OVL old_name new_name

Replaces the old name as a whole word in src/ovl/OVL*.c, asm/ovl/OVL/ (including the
nonmatchings/<file>/<name>.s file name) and ovl/OVL.sym.txt, adding `new_name = 0xADDR;` there
when it has no line yet, so a re-split keeps it. SCUS is left alone: its calls into overlay
addresses stay func_XXXXXXXX. Run make afterwards: names don't change the code.
"""
import glob, os, re, sys


def pairs_from_args():
    if len(sys.argv) == 4:
        return [(sys.argv[2], sys.argv[3])]
    out = []
    for line in open(sys.argv[2]):
        line = line.split('#')[0].split()
        if len(line) == 2:
            out.append(tuple(line))
    return out


def main():
    n = sys.argv[1]
    pairs = pairs_from_args()
    names = dict(pairs)
    srcs = [f for f in glob.glob('src/ovl/*.c') if re.fullmatch(rf'{n}[a-h]?(_\w+)?', os.path.basename(f)[:-2])]
    asms = glob.glob(f'asm/ovl/{n}/**/*.s', recursive=True)
    symp = f'ovl/{n}.sym.txt'
    sym = open(symp).read()
    for old, new in pairs:
        if not re.fullmatch(r'[A-Za-z_]\w*', new):
            sys.exit(f'bad name {new!r}')
        if re.search(rf'\b{new}\b', sym) or any(re.search(rf'\b{new}\b', open(f).read()) for f in srcs):
            sys.exit(f'{new} is already used in overlay {n}')
    word = re.compile(r'\b(' + '|'.join(map(re.escape, names)) + r')\b')
    changed = 0
    for p in srcs + asms + [symp]:
        s = open(p, encoding='utf-8').read()
        t = word.sub(lambda m: names[m.group(1)], s)
        if t != s:
            open(p, 'w', encoding='utf-8', newline='\n').write(t)
            changed += 1
    for old, new in pairs:
        for p in glob.glob(f'asm/ovl/{n}/nonmatchings/**/{old}.s', recursive=True):
            os.rename(p, os.path.join(os.path.dirname(p), f'{new}.s'))
    sym = open(symp).read()
    add = []
    for old, new in pairs:
        m = re.fullmatch(r'(func|D)_([0-9A-F]{8})', old)
        if m and not re.search(rf'^{new} = ', sym, re.M):
            add.append(f'{new} = 0x{m.group(2)}; // type:{"func" if m.group(1) == "func" else "data"}')
    if add:
        open(symp, 'a', newline='\n').write(('' if sym.endswith('\n') else '\n') + '\n'.join(add) + '\n')
    for p in srcs:  # INCLUDE_ASM'd .s files aren't make dependencies
        os.utime(p)
    print(f'{len(pairs)} names, {changed} files changed, {len(add)} sym.txt entries added')


main()
