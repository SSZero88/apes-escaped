"""Insert INCLUDE_RODATA lines for each game file's .rodata symbols (one-time migration).

For every game run in rodata_runs.txt, each data symbol in its range
gets `INCLUDE_RODATA("asm/nonmatchings/game/X", D_...);` in src/game/X.c, placed after
the first function (asm or C) that references it, and never before an earlier symbol's
line, so the object's .rodata keeps the original address order. A function's own jump
tables and constants thus sit right after it; decompiling it means deleting those lines.

Usage: python3 tools/add_include_rodata.py <old data.data.s> <old asm/nonmatchings dir>
       (the asm from a split with the single data segment, before the rodata split)
"""
import glob, os, re, sys

VRAM, OFF = 0x80010000, 0x800
data_s, nonmatch = sys.argv[1], sys.argv[2]

runs = []
for line in open('rodata_runs.txt'):
    line = line.split('#')[0].split()
    if line:
        runs.append((int(line[0], 16), line[1]))
syms = sorted((int(a, 16), n) for n, a in re.findall(r'^dlabel ((?:D|jtbl)_([0-9A-F]{8}))', open(data_s).read(), re.M))

for i, (lo, name) in enumerate(runs):
    if not name.startswith('game/'):
        continue
    hi = runs[i + 1][0]
    mine = [n for a, n in syms if lo <= a < hi]
    if not mine:
        continue
    path = f'src/{name}.c'
    text = open(path).read()
    lines = text.split('\n')
    folder = f'asm/nonmatchings/{name}'
    # function at each line: INCLUDE_ASM or a C definition
    func_lines = []  # (line index of the function's last line, function name)
    starts = {}
    for j, l in enumerate(lines):
        m = re.match(r'INCLUDE_ASM\("[^"]+", (\w+)\);', l)
        if m:
            func_lines.append((j, m.group(1)))
            starts[m.group(1)] = j
            continue
        m = re.match(r'^\w[\w \*]*?\b(\w+)\([^;]*\)\s*\{?\s*$', l)
        if m and m.group(1) not in ('if', 'while', 'for', 'switch'):
            k = j
            while k < len(lines) and lines[k] != '}':
                k += 1
            func_lines.append((k, m.group(1)))
            starts[m.group(1)] = j
    def refs(fn):
        p = f'{nonmatch}/{name}/{fn}.s'
        if os.path.exists(p):
            return open(p).read()
        m = re.search(rf'^\w[^\n;]*\b{fn}\([^;]*$.*?^\}}', text, re.M | re.S)
        return m.group(0) if m else ''
    bodies = {fn: refs(fn) for _, fn in func_lines}
    inserts = {}  # line index -> [INCLUDE_RODATA lines]
    last = -1
    for sym in mine:
        anchor = next((j for j, fn in func_lines if re.search(rf'\b{sym}\b', bodies[fn])), None)
        at = max(anchor if anchor is not None else last, last)
        if at < 0:  # nothing references it before any function: put it before the first one
            at = starts[func_lines[0][1]] - 1 if func_lines else len(lines) - 1
        inserts.setdefault(at, []).append(f'INCLUDE_RODATA("{folder}", {sym});')
        last = at
    out = []
    for j, l in enumerate(lines):
        out.append(l)
        if j in inserts:
            out.append('')
            out.extend(inserts[j])
            out.append('')
    open(path, 'w', newline='\n').write('\n'.join(out))
    print(f'{path}: {len(mine)} rodata symbols')
