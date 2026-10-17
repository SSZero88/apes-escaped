"""Make a src file's prototypes agree with the functions it defines.

Drafts bring guessed prototypes for their callees (`M2C_UNK func_X();`, `s32 func_X(void *, s16);`).
Once func_X is itself defined in the file, GCC rejects any declaration that disagrees with
the definition. This rewrites each top-of-file declaration of a defined function to the
definition's own signature, and moves typedef lines above everything else in that block so
the signature's types are declared first. A definition written K&R style (`f()`) keeps
`ret f();` declarations.
Usage: python tools/fix_protos.py src/game/XXXXXXXX.c ...
"""
import re, sys

DEF_RE = re.compile(r'^(\w[\w \*]*?\**\s*\b(func_[0-9A-F]{8}))\(([^;{]*)\)\s*\{$', re.M)
TYPEDEF_LINE_RE = re.compile(r'^typedef [^\n]*?\b(\w+);$', re.M)


def draft_typedefs():
    """typedef name -> line, from the normalized drafts (names there carry their function's suffix)."""
    import glob
    out = {}
    for p in glob.glob('wip/_norm/*.c'):
        for m in TYPEDEF_LINE_RE.finditer(open(p).read()):
            out.setdefault(m.group(1), m.group(0))
    return out

DRAFT_TDS = draft_typedefs()

for path in sys.argv[1:]:
    text = open(path).read()
    first = re.search(r'^(INCLUDE_ASM|INCLUDE_RODATA|\w[\w \*]*\([^;]*\)\s*\{$|\w[\w \*]*\([^;]*\)\n\{)', text, re.M).start()
    head, rest = text[:first], text[first:]
    sigs = {}
    for m in DEF_RE.finditer(rest):
        sigs[m.group(2)] = f'{m.group(1)}({m.group(3)});'
    lines = head.split('\n')
    out_t, out_o, changed = [], [], 0
    for l in lines:
        m = re.match(r'^[\w \*]*\b(func_[0-9A-F]{8})\([^;]*\);$', l) or re.match(r'^extern [\w \*]*\b(func_[0-9A-F]{8});$', l)
        if m and m.group(1) in sigs and l != sigs[m.group(1)]:
            l = sigs[m.group(1)]
            changed += 1
        (out_t if l.startswith('typedef ') else out_o).append(l)
    # typedefs a draft's declarations or code still name but that never made it into the file
    have = {m.group(1) for m in TYPEDEF_LINE_RE.finditer('\n'.join(out_t))}
    while True:
        used = set(re.findall(r'\b([A-Za-z]\w*_[0-9A-F]{8})\b', '\n'.join(out_t + out_o) + rest))
        missing = sorted(n for n in used - have if n in DRAFT_TDS)
        if not missing:
            break
        for n in missing:
            out_t.insert(0, DRAFT_TDS[n])  # in front: other typedefs may use it
            have.add(n)
        changed += len(missing)
    # includes stay first, then typedefs, then the rest
    inc = [l for l in out_o if l.startswith('#')]
    other = [l for l in out_o if not l.startswith('#')]
    head = '\n'.join(inc + out_t + other)
    open(path, 'w', newline='\n').write(head + rest)
    print(f'{path}: {changed} prototypes rewritten')
