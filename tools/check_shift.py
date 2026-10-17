"""List code/data that a modified build moved away from its original address (run in the container).

Auto-named symbols (func_8005BEE4, D_800AFA30, jtbl_..., ...) carry their original
address in the name, and named ones are listed in symbol_addrs.txt, so the built ELF
alone tells us what moved. Anything moved is only safe if every reference to it is
relinked; references from the KKIIDDZZ.DAT overlays and from data words splat didn't
symbolize are NOT, so a moved function they use will make the game crash.

Usage: python3 tools/check_shift.py [build/scus_944.23.elf]
Exit status 1 if anything moved.
"""
import re, subprocess, sys

elf = sys.argv[1] if len(sys.argv) > 1 else 'build/scus_944.23.elf'
known = {}
for line in open('symbol_addrs.txt'):
    m = re.match(r'\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)', line)
    if m:
        known[m.group(1)] = int(m.group(2), 16)

out = subprocess.run(['mips-linux-gnu-nm', elf], capture_output=True, text=True, check=True).stdout
moved = []
for line in out.splitlines():
    parts = line.split()
    if len(parts) != 3:
        continue
    addr, name = int(parts[0], 16) & 0xFFFFFFFF, parts[2]
    m = re.search(r'_([0-9A-F]{8})$', name)
    want = int(m.group(1), 16) if m and name.split('_')[0] in ('func', 'D', 'jtbl', 'jlabel', 'L') else known.get(name)
    if want is not None and want != addr:
        moved.append((want, addr, name))

for want, addr, name in sorted(moved):
    print(f'{name}: {want:#010x} -> {addr:#010x} ({addr - want:+#x})')
print(f'{len(moved)} symbols moved' if moved else 'no symbols moved')
sys.exit(1 if moved else 0)
