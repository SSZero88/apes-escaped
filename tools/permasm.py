"""Undo tools/permute.py's hide_asm: replace each __permasm(N) in stdin with asm statement N
from the JSON list given as the argument, and print the result."""
import json, re, sys

stmts = json.load(open(sys.argv[1]))
src = sys.stdin.read().replace('void __permasm(int);\n', '', 1)
sys.stdout.write(re.sub(r'__permasm\((\d+)\)', lambda m: stmts[int(m.group(1))], src))
