"""Write build/scus_syms.txt: every global symbol of the built SCUS ELF as a splat symbol_addrs line,
so the overlay splits name their calls and loads into SCUS (run in the container after make)."""
import re, subprocess

out = subprocess.run(['mips-linux-gnu-nm', '-n', 'build/scus_944.23.elf'], capture_output=True, text=True).stdout
lines, seen = [], set()
for line in out.splitlines():
    m = re.match(r'(?:ffffffff)?([0-9a-f]{8}) ([TDBRA]) (\S+)$', line)
    if not m or '.' in m.group(3) or m.group(3).startswith(('.', '_gp', '__')) or m.group(3).endswith(('_START', '_END', '_SIZE', '_VRAM', '_ROM_START', '_ROM_END')):
        continue
    addr = int(m.group(1), 16)
    if not 0x80010000 <= addr < 0x80136000:
        continue
    if addr in seen:
        continue  # aliases (e.g. a struct and its array view): keep the first
    seen.add(addr)
    kind = ' // type:func' if m.group(2) == 'T' else ''
    lines.append(f'{m.group(3)} = 0x{addr:08X};{kind}\n')
open('build/scus_syms.txt', 'w').write(''.join(lines))
print(len(lines), 'symbols')
