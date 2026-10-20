"""Decompilation progress: game code bytes in C vs still INCLUDE_ASM, for SCUS and the overlays."""
import glob, os, re


def asm_size(folder, name):
    s = open(f'{folder}/{name}.s').read()
    m = re.search(r'^nonmatching \w+, (0x[0-9A-F]+)', s, re.M)
    return int(m.group(1), 16) if m else 0


C_DEF = r'^[a-zA-Z_][\w \*]*\b(\w+)\([^;{]*\)\s*\{'

# SCUS
GAME_RANGES = [(0x80010000, 0x80012C70), (0x80014750, 0x80020AB0), (0x80031B60, 0x800A1C04)]
total = sum(hi - lo for lo, hi in GAME_RANGES)
scus_src = [c for c in glob.glob('src/**/*.c', recursive=True) if not c.replace('\\', '/').startswith('src/ovl/')]
left = {}
for c in scus_src:
    for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', open(c).read()):
        left[name] = asm_size(folder, name)
todo = sum(left.values())
done = total - todo
c_funcs = sum(len(re.findall(C_DEF, open(c).read(), re.M)) for c in scus_src)
print(f'SCUS game code: {c_funcs} functions in C, {len(left)} still asm; '
      f'{done:#x}/{total:#x} bytes ({100 * done / total:.2f}%) decompiled to matching C')

# overlays: C function sizes from the symbol pins (next function start), asm sizes from the asm files
o_done = o_todo = o_c = o_asm = 0
for sym in glob.glob('ovl/*.sym.txt'):
    o = os.path.basename(sym)[:3]
    starts = sorted(int(a, 16) for a in re.findall(r'^func_([0-9A-F]{8}) =', open(sym).read(), re.M))
    for c in glob.glob('src/ovl/*.c'):
        if not re.fullmatch(o + r'[a-h]?(_\w+)?', os.path.basename(c)[:-2]):
            continue
        t = open(c).read()
        for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', t):
            o_todo += asm_size(folder, name)
            o_asm += 1
        for name in re.findall(C_DEF, t, re.M):
            if not name.startswith('func_'):
                continue
            a = int(name[5:], 16)
            nxt = [s for s in starts if s > a]
            o_c += 1
            o_done += nxt[0] - a if nxt else 0
o_total = o_done + o_todo
print(f'overlay code: {o_c} functions in C, {o_asm} still asm; '
      f'{o_done:#x}/{o_total:#x} bytes ({100 * o_done / o_total:.2f}%) decompiled to matching C')
print(f'all: {100 * (done + o_done) / (total + o_total):.2f}%')
