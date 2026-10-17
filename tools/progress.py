"""Decompilation progress: game code bytes in C vs still INCLUDE_ASM."""
import glob, re

GAME_RANGES = [(0x80010000, 0x80012C70), (0x80014750, 0x80020AB0), (0x80031B60, 0x800A1C04)]
total = sum(hi - lo for lo, hi in GAME_RANGES)

left = {}
for c in glob.glob('src/**/*.c', recursive=True):
    for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)", (\w+)\);', open(c).read()):
        s = open(f'{folder}/{name}.s').read()
        left[name] = int(re.search(r'^nonmatching \w+, (0x[0-9A-F]+)', s, re.M).group(1), 16)

todo = sum(left.values())
done = total - todo
c_funcs = sum(len(re.findall(r'^[a-zA-Z_][\w \*]*\b\w+\([^;{]*\)\s*\{', open(c).read(), re.M))
              for c in glob.glob('src/**/*.c', recursive=True))
print(f'game code: {c_funcs} functions in C, {len(left)} still asm; '
      f'{done:#x}/{total:#x} bytes ({100 * done / total:.2f}%) decompiled to matching C')
