"""Run after splat: give each game object its own .rodata, at its original address.

splat emits the whole data region as one asm file. PsyQ's linker laid out every
object's .rodata in object order after all .text, so this:
  1. moves each game file's rodata symbols (jump tables, strings, constants) out of
     asm/data/data.data.s into asm/nonmatchings/game/<file>/<sym>.s, which the C file
     pulls in with INCLUDE_RODATA (so a decompiled switch can emit its own table instead);
  2. moves library-owned runs into asm/data/rodata_<addr>.s;
  3. rewrites the linker script to place game/<file>.o(.rodata) and those runs there.
Run boundaries come from rodata_runs.txt (see tools/gen_rodata_segments.py).
"""
import os, re

LD = 'scus_944.23.ld'
DATA = 'asm/data/data.data.s'

runs = []
for line in open('rodata_runs.txt'):
    line = line.split('#')[0].split()
    if line:
        runs.append((int(line[0], 16), line[1]))
end = next(a for a, o in runs if o == 'end')
runs = [r for r in runs if r[1] != 'end']

text = open(DATA).read()
first = text.index('\n.align 2\nnonmatching ') if '\n.align 2\nnonmatching ' in text[:2000] else text.index('\nnonmatching ')
header, body = text[:first + 1], text[first + 1:]
# blocks: [.align N\n] nonmatching X ... enddlabel X\n\n
blocks = re.findall(r'((?:\.align \d+\n)?nonmatching (\w+).*?^enddlabel \2\n\n?)', body, re.S | re.M)
assert ''.join(b for b, _ in blocks) == body, 'unexpected data asm layout'

def addr_of(name):
    return int(name.split('_')[-1], 16)

keep, lib_runs = [], {}
for block, name in blocks:
    a = addr_of(name)
    if a >= end:
        keep.append(block)
        continue
    start, owner = max((r for r in runs if r[0] <= a), key=lambda r: r[0])
    if owner == 'lib':
        lib_runs.setdefault(start, []).append(block)
    else:
        d = f'asm/nonmatchings/{owner}'
        os.makedirs(d, exist_ok=True)
        pad = None
        if name.startswith('jtbl_'):
            # trailing zero words are never table entries (those are code addresses):
            # keep them as their own symbol, so the bytes stay when the switch is decompiled
            # and the compiler emits only the table itself
            m = re.search(r'((?:^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) 00000000 \*/ \.word 0x00000000\n)+)(enddlabel)', block, re.M)
            if m:
                block = block[:m.start(1)] + block[m.start(3):]
                pad = (f'nonmatching {name}_pad\n\ndlabel {name}_pad\n' + m.group(1) + f'enddlabel {name}_pad\n')
        open(f'{d}/{name}.s', 'w').write(block)
        if pad:
            open(f'{d}/{name}_pad.s', 'w').write(pad)

open(DATA, 'w').write(header + ''.join(keep))
for start, blocks_ in lib_runs.items():
    open(f'asm/data/rodata_{start:08X}.s', 'w').write(
        '.include "macro.inc"\n\n.section .rodata, "a"\n\n' + ''.join(blocks_))

ld = open(LD).read()
ld = re.sub(r'^\s*build/(?:src/game/\w+|asm/lib_\w+)\.o\(\.rodata\);\n', '', ld, flags=re.M)
place = ''.join(f'        build/src/{o}.o(.rodata);\n' if o != 'lib' else f'        build/asm/data/rodata_{a:08X}.o(.rodata);\n'
                for a, o in runs)
ld, n = re.subn(r'^(\s*)build/asm/data/data\.data\.o\(\.data\);\n', lambda m: place + m.group(0), ld, flags=re.M)
assert n == 1
open(LD, 'w').write(ld)
print(f'post_split: {len(runs)} rodata runs placed')
