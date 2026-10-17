"""Rewrite hand-written drafts into the declaration style auto_decomp merges.

Hand drafts declare their own structs (`extern struct { ... unk24 ... } D_X;`, typedefs for
array elements). auto_decomp --from-wip merges per-file struct globals only when they look
like `extern struct S_D_X { u8 pad_0[N]; T f_24; ... } D_X[];`, so this converts:
  - field names unkXX -> f_XX (everywhere in the draft),
  - `extern struct { BODY } D_X[...]` -> `extern struct S_D_X { BODY } D_X[]`,
  - `typedef struct {BODY} T; extern T D_X[...];` -> the same, with T replaced by struct S_D_X,
  - the monkey struct (S_4D08) -> Monkey from game.h,
  - any other typedef name T -> T_<func> so drafts for the same file can't clash.
Usage: python tools/hand_norm.py in.c [out.c]   (default: rewrite in place)
"""
import re, sys

src = sys.argv[1]
dst = sys.argv[2] if len(sys.argv) > 2 else src
text = open(src).read()

# the permuter writes struct declarations over several lines: make each one line again
out, buf = [], None
for l in text.split('\n'):
    if buf is not None:
        buf += ' ' + l.strip()
        if buf.count('{') == buf.count('}') and buf.rstrip().endswith(';'):
            buf = re.sub(r'\s+', ' ', buf).strip()
            buf = re.sub(r';\s*\}', '; }', re.sub(r'\{\s*', '{ ', buf))
            out.append(buf)
            buf = None
        continue
    if re.match(r'^(typedef |extern )?struct\b', l) and l.count('{') > l.count('}'):
        buf = l.strip()
        continue
    out.append(l)
text = '\n'.join(out)
# the defined function: a signature line without ';' (its '{' may be on the next line)
fname = re.findall(r'^\w[\w \*]*\b(func_[0-9A-F]{8})\([^;]*$', text, re.M)[-1]

# the monkey struct lives in game.h
text = re.sub(r'^typedef struct \{[^\n]*\} S_(4D08|16C);\n', '', text, flags=re.M)
text = re.sub(r'^extern S_4D08 \*D_800B4(D08|CF8);\n', '', text, flags=re.M)
text = re.sub(r'\bS_4D08\b', 'Monkey', text)
text = re.sub(r'\bS_16C\b', 'MonkeyAnimEntry', text)

text = re.sub(r'\bunk([0-9A-F]+)\b', r'f_\1', text)

# typedef'd element types of array/struct globals
TYPEDEF_RE = r'^typedef struct (?:\w+ )?\{{ ([^\n]*) \}} ({t});\n'
tds = {m.group(2): m.group(1) for m in re.finditer(TYPEDEF_RE.format(t=r'\w+'), text, re.M)}
names = list(tds)
# a typedef used inside another typedef must keep its place (and name) to stay declared first
inner = {t for t in names if any(re.search(rf'\b{t}\b', b) for o, b in tds.items() if o != t)}
for t in names:
    m = re.search(TYPEDEF_RE.format(t=t), text, re.M)  # fresh: earlier rewrites may have changed it
    if m is None:
        continue
    body = m.group(1)
    users = re.findall(rf'^extern {t} (D_[0-9A-F]{{8}})(\[\w*\])?;$', text, re.M)
    # a body that uses other typedefs stays a typedef: its members must be declared first
    nested = any(re.search(rf'\b{o}\b', body) for o in names if o != t) or 'struct S_' in body
    if len(users) == 1 and '(' not in body and not nested and t not in inner:
        g, arr = users[0]
        text = text.replace(m.group(0), '')
        text = re.sub(rf'^extern {t} {g}(\[\w*\])?;$',
                      f'extern struct S_{g} {{ {body} }} {g}{"[]" if arr else ""};', text, flags=re.M)
        text = re.sub(rf'\b{t}\b', f'struct S_{g}', text)
    elif t not in ('Monkey', 'MonkeyAnimEntry'):
        text = re.sub(rf'\b{t}\b', f'{t}_{fname[5:]}', text)

# anonymous struct globals
text = re.sub(r'^extern struct \{ ([^\n]*) \} (D_[0-9A-F]{8})(\[\w*\])?;$',
              lambda m: f'extern struct S_{m.group(2)} {{ {m.group(1)} }} {m.group(2)}{"[]" if m.group(3) else ""};',
              text, flags=re.M)

if 'Monkey' in text and '#include "game.h"' not in text:
    pass  # check_c/auto_decomp include game.h for files that do
open(dst, 'w', newline='\n').write(text)
