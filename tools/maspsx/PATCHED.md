# Local patch

Copy of maspsx (https://github.com/mkst/maspsx, commit e85ecb3, MIT licence).

One change in `maspsx/__init__.py`, `_handle_nop_before_next_instruction`: when a load is
followed by a label and then an instruction that uses the loaded register, upstream emits the
label first and the load-delay `nop` after it. Ape Escape's assembler put the `nop` before the
label, so a jump to that label skips it (seen in `func_8008F308`, `func_8004F884`). With the
patch the `nop` stays right after the load. Every function that matched before still matches.

Second change (two places in `__init__.py`, marked "Ape Escape patch"): after an expanded
`div`/`divu`/`rem`/`remu`, upstream treats the `mfhi`/`mflo` result like a load and puts a `nop`
before the next instruction if it reads that register (and, when one instruction sits between the
`mfhi` and the next `mult`/`div`, puts the hazard `nop` before that instruction rather than after
it). Across the original binary, an expanded division's result is used directly by the next
instruction about 40 times and never with a `nop` in between, so both rules are off here. The HI/LO
hazard `nop`s before a following `mult`/`div` are kept. Every function that matched before still
matches (full rebuild).

Third change (`_handle_mflo_mfhi`, marked "Ape Escape patch"): for `mflo`/`mfhi`, one instruction,
a label, then a `mult`/`div`, upstream emits the label and then the HI/LO hazard `nop`. The
original assembler put the `nop` before the label (seen in `Coll_PushWedge`, where the `d > 0`
branch jumps straight to the shared `mult`). Full rebuild still matches.
