"""Put hand-matched functions into their src file directly (no struct merging).

For each function: its draft (wip/_norm/<f>.c, else wip/<f>.c) is split into declarations and
the function. The function replaces its INCLUDE_ASM line; declarations the file doesn't have
yet (by name) go after the last top-of-file declaration. A declaration whose name the file
already declares differently is reported and the function is skipped, unless it's only a
prototype (the file's version wins) or `--force` is given for that name.
Nothing is verified here: run ./make.sh and tools/verify_all.py afterwards.
Usage: python tools/hand_apply.py func_A func_B ...
"""
import os, re, subprocess, sys

sys.path.insert(0, os.path.dirname(__file__))
from auto_decomp import decl_name  # noqa: E402

TOP_DECL_RE = re.compile(r'^(extern |typedef |struct |\w[\w \*]*\bfunc_\w+\(.*\);$|\w[\w \*]*\b\w+\(.*\);$)')


def name_of(line):
    m = re.match(r'^typedef .*?(\w+);$', line)
    if m:
        return m.group(1)
    return decl_name(line.replace('extern ', ''))


def split_draft(text, name):
    """Declarations before the definition of `name`, and the definition itself (its opening
    brace may be on the signature line or, as the permuter writes it, on the next one)."""
    decls, body = [], []
    lines = text.splitlines()
    i = 0
    while i < len(lines):
        l = lines[i]
        if re.match(rf'^\w[\w \*]*\b{name}\([^;]*$', l):
            body = lines[i:]
            break
        if l.strip():
            decls.append(l)
        i += 1
    return decls, '\n'.join(body).rstrip() + '\n'


def same_int_array(old, new):
    """Both `extern [su]N D_X[...]` with the same N: only signedness differs, use the file's."""
    a = re.match(r'^extern ([su])(8|16|32) ([A-Za-z_]\w*)\[\w*\];$', old)
    b = re.match(r'^extern ([su])(8|16|32) ([A-Za-z_]\w*)\[\w*\];$', new)
    return a and b and a.group(2) == b.group(2) and a.group(3) == b.group(3)


def alias(decl, body, suffix):
    """The file declares this global differently: keep the file's declaration and have the new
    function reach the global through its own view of it, a cast of its address. A field
    or element access through `((T *)&D_X)` compiles to the same symbol+offset code.
    Returns (new body, type declaration to add or None), or None if the draft line isn't a global."""
    m = re.match(r'^extern struct (\w+) \{ (.*) \} ([A-Za-z_]\w*)(\[\w*\])?;$', decl)
    if m:
        g = m.group(3)
        t = f'struct {m.group(1)}_{suffix}'
        view = f'(({t} *)&{g})'
        body = re.sub(rf'\bstruct {m.group(1)}\b(?!_)', t, body)  # the draft's own pointers to it

        def sub(mm):
            amp, nxt = mm.group(1) or '', mm.group(2) or ''
            if nxt == '.':
                return f'{amp}{view}->'
            if nxt == '[':
                return f'{amp}{view}['
            return view  # the whole object (&D_X) or its decayed address (D_X)
        body = re.sub(rf'(&)?(?<!\w){g}\b(\.|\[)?', sub, body)
        return body, f'{t} {{ {m.group(2)} }};'
    m = re.match(r'^extern ([\w ]+?\**)\s*([A-Za-z_]\w*)(\[\w*\])?;$', decl)
    if m:
        typ, g, arr = m.group(1).strip(), m.group(2), m.group(3)
        view = f'(({typ} *)&{g})' if arr else f'(*({typ} *)&{g})'
        body = re.sub(rf'(?<![\w&]){g}\b', view, body)
        body = re.sub(rf'&{g}\b(?!\))', f'&{view}', body)
        return body, None
    return None


def main():
    touched = set()
    for name in sys.argv[1:]:
        draft = next((p for p in (f'wip/_norm/{name}.c', f'wip/{name}.c') if os.path.exists(p)), None)
        src = next((p for p in sorted(os.listdir('src/game')) if f', {name});' in open(f'src/game/{p}').read()), None)
        if not draft or not src:
            print(f'SKIP {name}: no draft or not INCLUDE_ASM')
            continue
        src = f'src/game/{src}'
        text = open(src).read()
        decls, body = split_draft(open(draft).read(), name)
        have = {}
        for l in text.splitlines():
            if l.startswith(('extern ', 'typedef ')) or (l.endswith(');') and not l.startswith((' ', 'INCLUDE'))):
                n = name_of(l)
                if n:
                    have[n] = l
        game_h = open('include/game.h').read() if '#include "game.h"' in text else ''
        add, bad = [], []
        for d in decls:
            n = name_of(d)
            if n == name:
                continue
            if n and re.search(rf'\b{n}\b[^\n]*;', game_h) and (n.startswith('D_') or n[0].isupper()):
                continue  # declared by game.h
            old = have.get(n)
            if old is None:
                add.append(d)
            elif old != d and not re.search(r'\b\w+\([^;]*\);$', d):
                bad.append((old, d))  # prototypes: the file's version wins
        still = []
        for o, d in bad:
            if same_int_array(o, d):
                text = text.replace(o, d)  # take the draft's signedness; verify_all checks the rest
                continue
            r = alias(d, body, name[5:])
            if r is None:
                still.append((o, d))
            else:
                body, typedecl = r
                if typedecl:
                    add.append(typedecl)
        if still:
            print(f'CONFLICT {name} ({src}):')
            for o, d in still:
                print(f'   file:  {o}\n   draft: {d}')
            continue
        inc = re.search(rf'^INCLUDE_ASM\("([^"]+)", {name}\);\n', text, re.M)
        text = text[:inc.start()] + body + text[inc.end():]
        if 'switch' in body:  # the C switch now emits its own jump table
            for t in set(re.findall(r'\b(jtbl_[0-9A-F]{8})\b', open(f'{inc.group(1)}/{name}.s').read())):
                text = re.sub(rf'^INCLUDE_RODATA\("[^"]+", {t}\);\n', '', text, flags=re.M)
        if add:
            # after the last declaration line before the first function/INCLUDE
            first = re.search(r'^(INCLUDE_|\w[\w \*]*\([^;]*\{$)', text, re.M).start()
            head = text[:first]
            ins = head.rstrip('\n') + '\n' + '\n'.join(add) + '\n\n'
            text = ins + text[first:]
        open(src, 'w', newline='\n').write(text)
        touched.add(src)
        print(f'APPLIED {name} -> {src}' + (f' (+{len(add)} decls)' if add else ''))
    if touched:
        subprocess.run([sys.executable, os.path.join(os.path.dirname(__file__), 'fix_protos.py'), *sorted(touched)])


main()
