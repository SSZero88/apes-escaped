"""Compare build/SCUS_944.23 to the original exe function-by-function.
Usage (in container): python3 tools/diff_funcs.py [-a]   (-a: list all mismatches)"""
import subprocess, sys
ORIG, BUILT, ELF = 'iso/SCUS_944.23', 'build/SCUS_944.23', 'build/scus_944.23.elf'
VRAM, OFF = 0x80010000, 0x800
o, b = open(ORIG, 'rb').read(), open(BUILT, 'rb').read()
syms = []
for line in subprocess.run(['mips-linux-gnu-nm', '-S', '-n', ELF], capture_output=True, text=True).stdout.splitlines():
    p = line.split()
    if len(p) == 4 and p[2] in 'Tt':
        syms.append((int(p[0], 16) & 0xFFFFFFFF, int(p[1], 16), p[3]))
bad = 0
for addr, size, name in syms:
    s = addr - VRAM + OFF
    if o[s:s + size] != b[s:s + size]:
        bad += 1
        nd = sum(o[s + i:s + i + 4] != b[s + i:s + i + 4] for i in range(0, size, 4))
        print(f'MISMATCH {name} @ {addr:08X} size 0x{size:X}: {nd} words differ')
        if '-a' not in sys.argv:
            break
if len(o) != len(b):
    print(f'size differs: orig 0x{len(o):X} built 0x{len(b):X}')
print('OK' if not bad and o == b else f'{bad} mismatching function(s)' if bad else 'functions OK, data differs')
