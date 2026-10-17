"""Compile one C function in isolation and diff against the original (in container).
Usage: python3 tools/check_c.py <func_name> <file.c> [compiler]
file.c holds any declarations plus the function; common.h/game.h/m2c_macros.h are pre-included."""
import glob, re, subprocess, sys
sys.argv, args = sys.argv[:1], sys.argv[1:]
import importlib.util
spec = importlib.util.spec_from_file_location('ad', 'tools/auto_decomp.py')
src = open('tools/auto_decomp.py').read().replace('\nmain()\n', '\n')
ad = {}
exec(compile(src, 'auto_decomp', 'exec'), ad)
name, cfile = args[0], args[1]
compiler = args[2] if len(args) > 2 else '2.8.1-psx'
asm_path = glob.glob(f'asm/nonmatchings/**/{name}.s', recursive=True)[0]
asm = open(asm_path).read()
size = int(re.search(r'^nonmatching \w+, (0x[0-9A-F]+)', asm, re.M).group(1), 16)
addr = int(re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', asm).group(1), 16)
tu = '#include "game.h"\n#include "m2c_macros.h"\n\n' + open(cfile).read()
ok, err = ad['compile_c'](tu, compiler, '/tmp/check.o')
if not ok:  # drafts from auto_decomp are written against common.h only
    err0 = err
    tu = '#include "common.h"\n#include "m2c_macros.h"\n\n' + open(cfile).read()
    ok, err = ad['compile_c'](tu, compiler, '/tmp/check.o')
if not ok:
    print('[with game.h]', err0, '[with common.h]', err, sep=chr(10)); sys.exit(2)
if ad['matches']('/tmp/check.o', name, addr, size):
    print(f'MATCH {name}'); sys.exit(0)
data, masks = ad['func_code']('/tmp/check.o', name)
orig = ad['ORIG'][addr - 0x80010000 + 0x800:][:size]
def dis(b, base):
    open('/tmp/d.bin', 'wb').write(b)
    out = subprocess.run(['mips-linux-gnu-objdump', '-D', '-b', 'binary', '-m', 'mips:3000', '-EL', '--adjust-vma', hex(base), '/tmp/d.bin'], capture_output=True, text=True).stdout
    return [l.split('\t', 2)[-1] for l in out.splitlines() if re.match(r'\s*[0-9a-f]+:\t', l)]
a, b = dis(orig, addr), dis(data or b'', addr)
print(f'NO MATCH {name}: orig {size:#x} bytes, ours {len(data or b""):#x} bytes')
for i in range(max(len(a), len(b))):
    x = a[i] if i < len(a) else ''; y = b[i] if i < len(b) else ''
    mark = '!!' if x.split()[:1] != y.split()[:1] else '~~' if x != y else '  '
    print(f'{mark} {x:40s} | {y}')
sys.exit(1)
