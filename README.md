# apes-escaped

A matching decompilation of **Ape Escape** (PlayStation, USA, `SCUS-944.23`).

"Matching" means the C source here compiles, with the original 1998-era compiler,
back into a byte-for-byte identical copy of the game's executable
(`sha1 3c9ea80a785e68660b241468ee97b753650618c0`). Functions not yet
decompiled are included as assembly, so the build always produces a
working, identical executable.

No game data is included. You need your own copy of the disc.

## Status

Run `python tools/progress.py`.

- Whole executable: splits, rebuilds and matches.
- Game code (about 509 KB): about 1,430 functions in 64 C files that follow the original
  object-file boundaries. 1,257 functions (58.3% by size) are matching C so far: the main loop and
  game modes, Spike's states and gadgets, monkey AI, pickups, the HUD and menus, the camera, the
  sound sequencer and most of the GPU draw code (see `docs/findings.md` and `docs/names.txt`).
- Work in progress lives in `wip/` (gitignored): `wip/_perm_queue.txt` lists near misses
  for the permuter (hand-written drafts in `wip/_hand/`), and `wip/_gte/` holds unfinished GTE drafts.
- PsyQ SDK code (about 83 KB): 89 library objects / 278 functions identified
  automatically by signature, from PsyQ 4.5 with some older objects. These stay as asm.
- Not started: level overlays in `KKIIDDZZ.DAT` (loaded at `0x80136000`),
  `MINIGAME/MINI1.EXE`, `MINIGAME/MINI2.EXE`.

## Setup

Requirements: Docker, Python 3 (on the host, for a few helper scripts), Git Bash.

```sh
# 1. extract the disc (skips FMV .STR files)
python tools/extract_iso.py "path/to/Ape Escape (USA).bin" iso

# 2. build the toolchain image: binutils, splat, maspsx, m2c, PsyQ-era GCCs
docker build -t apes-escaped-build docker

# 3. PsyQ signatures (used once, to name library functions)
git clone --depth 1 https://github.com/lab313ru/psx_psyq_signatures tools/sigs/repo

# 4. split the exe into asm/ and build. It must print "build/SCUS_944.23: OK"
./make.sh split
./make.sh -j8
```

`./make.sh` runs `make` inside the container. `./make.sh split` regenerates `asm/`
and the linker script from `scus_944.23.yaml`. It never overwrites files in `src/`.

## Playing and testing a build

```sh
echo "C:/path/to/Ape Escape (USA).bin" > disc.path   # once (gitignored)
./play.sh          # build, then write the exe into a copy: build/disc/ApeEscape.cue
./play.sh run      # ... and open it in RetroArch
./play.sh test     # ... and boot it headlessly next to the original disc, comparing screenshots
```

- `tools/patch_disc.py` writes the exe over its own sectors in a copy of the disc and
  recomputes EDC/ECC. Patching the matching build reproduces the original `.bin` bit for bit.
- `tools/boot_test.py` runs RetroArch (Beetle PSX core, `%APPDATA%\RetroArch` or `RETROARCH=`)
  from power-on with no input for N frames per run and screenshots the last frame.
  Runs are deterministic, so identical discs give identical screenshots. It runs in real time
  (4500 frames is 75 s). Your RetroArch config and saves are not touched.
- `tools/check_shift.py` (run by `play.sh`) lists every symbol a modified build moved.
  **Moving code is the main hazard of editing.** The level overlays in `KKIIDDZZ.DAT` call
  into the exe at fixed addresses, and some data words are raw addresses that splat didn't
  turn into symbols, so neither follows a moved function. Keep edits the same size,
  or within the alignment padding at the end of their file, until the overlays are split too.

## Layout

| Path | What |
|---|---|
| `scus_944.23.yaml` | splat config: segment and file layout of the exe |
| `symbol_addrs.txt` | known symbol names (library functions plus game names as they are found) |
| `src/game/ADDR_name.c` | game code, one file per original object file: start address plus a short subject (`80032E30_monkey.c`); `tools/rename_segments.py` holds the names and renames the C file, its asm folder and every path together |
| `include/common.h` | basic types plus the 16-byte `.text` alignment each original object had |
| `include/game.h` | shared game structs and globals, as they get understood |
| `include/psyq.h` | PsyQ library prototypes |
| `asm/` | generated; `asm/nonmatchings/` holds per-function asm used by `INCLUDE_ASM` |
| `tools/` | helper scripts (see below) |

## Toolchain facts (worked out the hard way)

- Compiler: **GCC 2.8.1 (PSX build)** with `-O2 -G0`, assembled through
  `maspsx` (`--aspsx-version=2.79 --expand-div`). 2.8.1 matched 179 of 831 small test
  functions against 81 for 2.7.2.
- `-mhard-float` too (this cc1 defaults to soft-float). The game has no float code, but
  hard-float leaves the FPU registers unfixed, which raises loop.c's hoisting threshold
  (`(1 + n_non_fixed_regs)`), so constants like `li s5,1` move out of loops containing calls
  the way the original's do. Found from functions that only matched with it; every earlier
  match still matches. `wip/loopdump.sh` prints cc1's loop decisions (`-dL`) for a draft.
- maspsx is vendored in `tools/maspsx` with one patch (`tools/maspsx/PATCHED.md`): a
  load-delay `nop` before a label goes before the label, as the original assembler did.
- No `$gp`-relative data, so `-G0`.
- Each original object's `.text` is 16-byte aligned (zero padding between objects).
  That padding is how the 64 file boundaries were found (`tools/find_gaps.py`).
- `main` is compiled by GCC with an implicit `__main()` call (`0x800143B0`).
- Library asm objects are forced to 4-byte alignment after assembling (see Makefile),
  because the sound library follows the last game file with no padding.
- `.rodata` (`0x800A37F0`..`0x800A6AB0`) is each object's rodata in object order, also
  16-byte aligned per object. `rodata_runs.txt` records where each object's run starts.
  After splat runs, `tools/post_split.py` cuts each game file's rodata symbols into
  `asm/nonmatchings/game/<file>/<sym>.s` and links `<file>.o(.rodata)` at its original
  address. The C file pulls the symbols in with `INCLUDE_RODATA`, placed right after the
  function that uses them. A decompiled `switch` emits its own jump table, so its
  `INCLUDE_RODATA` line is deleted (auto_decomp does this).

## What the code does so far

- `__start` (`0x800A3660`): clears BSS `0x800B4C60`..`0x800F760C`, sets `$sp`/`$gp`, jumps to `main`.
- `main` (`src/game/8005BDC0_system.c`): calls `System_Init` (hardware init: callbacks,
  GTE, CD, pads, memory card), then loops over the **game-mode table** at
  `0x800AFA30`. Each entry is `{handler, overlay id}`. The overlay is loaded to
  `0x80136000`, then the handler runs until it returns < 0. The current mode lives in
  `g_Game.mode` (`+0x8120`).
- Changing the start mode in `main` (tested with `./play.sh test`): mode 1 boots the same
  as mode 0 (logos, then the Specter intro), mode 3 stays on a white screen and modes 5 and 7
  on black. Later modes probably need state set up by earlier ones.

## Decompiling workflow

```sh
# automatic pass: m2c draft -> compile alone -> compare to original; writes matches into src/
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/auto_decomp.py --max-size 0x2000
#   SAVE_WIP=1 also saves the best non-matching draft of each function to wip/<func>.c
#   build/near_misses.txt lists "<differing instructions> <size> <func>"; start with the smallest

# refresh the signature database used as m2c context (after decompiling more functions)
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/gen_sigs.py

# by hand: draft, edit, check one function in isolation (prints a side-by-side diff)
docker run --rm -v "$(pwd -W):/work" apes-escaped-build tools/m2c.sh func_80012345 > wip/func_80012345.c
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/check_c.py func_80012345 wip/func_80012345.c

# move a matching wip function into src/, then do the full verified build
python tools/integrate.py func_80012345
./make.sh -j8
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/diff_funcs.py -a   # if it fails
```

```sh
# brute-force near misses with decomp-permuter (random rewrites until the code matches)
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/permute.py func_80012345 wip/func_80012345.c --run 120
#   a score-0 result is saved as wip/<func>.perm.c; integrate it (verified) with:
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/auto_decomp.py --from-wip --only func_80012345
# or the whole near-miss list, fewest differences first:
docker run --rm -v "$(pwd -W):/work" apes-escaped-build python3 tools/perm_batch.py --time 90 --max-diff 10
```

`auto_decomp.py` already fixes these common m2c patterns by itself (each as a variant it tries):
- `fix_params`: restores unused leading parameters m2c drops (`f(void *arg1)` → `f(s32 arg0, void *arg1)`).
- `structify`: byte-offset accesses on a global (`M2C_FIELD(&D_X, s16 *, 0x24)`) become fields of a
  generated `extern struct S_D_X {...} D_X;`, including arrays of structs. GCC addresses a struct
  global once and uses field offsets, which the casts don't reproduce. The structs are per file,
  and later matches widen them (`merge_struct`, which keeps hand-given field names) or turn
  earlier scalar uses into fields (`unify`).
- `fix_addr_offsets`: `&D_X + N` / `(i * K) + &D_X` from m2c are byte offsets.
- `fix_unsigned_consts`: byte/halfword stores of constants ≥ 0x80/0x8000 are unsigned.
- Jump tables: the table's rodata is given to m2c (as labels), so `switch` functions decompile.
Every file it changes is recompiled whole and each C function (plus the file's `.rodata`) is
compared with the original before it's written. Candidates that break the file are dropped one by one.

Common reasons a draft doesn't match:
- **Pass-through arguments**: a function forwards its own `a0` to a callee
  (`f(a) { g(a, 0); }`). Give the callee its real prototype.
- **Pointer scaling**: m2c writes byte offsets on typed pointers; use an array of the
  right element type or a `u8*` step.
- **`u8` vs `s8`** for stored constants ≥ 0x80, **`s16` vs `s32`** parameters
  (`lh` vs `lhu`, extra `sll/sra`).
- **Branch order**: write the `if/else` in the order the asm tests it.
- **Stack frame too small**: the original had an unused local array (`s32 unused[2];`).

Patterns found while matching by hand (GCC 2.8.1 specifics):
- **Range checks**: `x < 0x3D && x >= 0x38` on one variable gets folded into one unsigned
  compare. Two separate signed compares in the asm mean nested `if`s. A `u16` compared
  signed (`lhu` then `slti`) was copied into an `s32` local first, since GCC narrows a
  compare on the `u16` itself to `sltiu`.
- **`ABS`**: `common.h`'s `ABS(x)` (`x >= 0 ? x : -x`) on an expression gives the original's
  "two branches, each compares" shape. Range tests were written as nested
  `if (ABS(...) < w)` that fall through to `return -1` (Box_NearPoint).
- **Reverse init loops**: a pointer walking backwards from `&D_X + N*stride` is
  `for (i = N; i >= 0; i--) D_X[i].field = 0;` (auto_decomp does this now).
- **Scratchpad** (`0x1F800000`): one `lui` shared by all accesses means a local base pointer
  (`u8 *scratch = (u8 *)0x1F800000;`, auto_decomp does this); a `lui` per access means plain
  constant addresses.
- **Load order across byte stores**: a word load that happens before byte stores in the asm
  was read into a local first (byte stores may alias anything, so GCC can't hoist it).
- **Table lookups**: `D_X[i].f` where `D_X` is a pointer to records (`lw` the pointer,
  then `i * size`). Write the record type; GCC's multiply-by-shifts must line up.
- **Pass-through arguments** again: a function that calls `f(a0, a1)` without touching
  `$a0`/`$a1` takes and forwards both (func_8008CC60).
- **`lhu` then `sll 16`/`sra 16`** on a value that's then used signed: it was read into a `u16`
  local (or a `u16` field) and cast, `(s16)v`. A plain `s16` gives `lh`.
- **Narrow loads**: an `s32` field stored into an `s16` compiles to `lhu` of its low half, so
  `lhu 0x24` doesn't mean the field is 16-bit (positions at `+0x24/0x28/0x2C` are `s32`).
- **Two compares that GCC would fold** (`x == 0x20 || x == 0x1F` -> one `sltiu`): write them as
  separate `if`s. In a `switch`, cases sharing a body become a range test; if the asm compares
  them one by one, give each case its own (identical) body.
- **`sltu rX, rZero, rY` with a register known to be 0** instead of `$zero`: the source compared
  against the variable itself, `ret = ret < (x & 0x200);` (func_80065214, Camera_RcCarActive family).
- **Ring buffers**: `buf[(idx + 40 - i) % 40]` keeps the original's per-iteration `i - 40`;
  `(idx - (i - 40))` or `(idx - i + 40)` let GCC hoist `idx + 40`.
- **Stack order**: locals get addresses in declaration order, first declared lowest
  (`SVECTOR tmp, v;` puts `tmp` at `sp+0x10`).
- **A parameter extended once at entry** (`sll/sra` into an `s`-register) was a wider parameter
  copied into a `s16` local; one extended at each use was declared `s16`.

Hand-written drafts live in `wip/_try/` while being matched (`tools/check_c.py` per function).
`tools/hand_norm.py` rewrites a draft's own declarations into the per-file
`extern struct S_D_X { ... f_<off> ... }` form that `auto_decomp.py --from-wip` merges, and
uses the shared structs in `game.h` (e.g. `Monkey`). `tools/hand_apply.py` puts functions in
directly when the integrator reports a conflict it can't merge. `docs/findings.md` collects
what has been identified so far (monkeys, Spike, gadgets, input history, draw buffers).

Integrating a batch (what has worked):
1. `py tools/hand_norm.py wip/_try/f.c wip/_norm/f.c` for each match (also takes permuter
   output, `wip/f.perm.c`), re-check each with `check_c.py`.
2. `auto_decomp.py --from-wip --only ...` (merges per-file structs where it can).
3. `hand_apply.py` for the rest. When the file already declares a global differently it keeps
   the file's declaration and gives the new function its own view of it,
   `((struct S_D_X_<func> *)&D_X)->field`, which compiles to the same code. It runs
   `fix_protos.py` (prototypes of now-defined functions, missing typedefs from the drafts).
4. `./make.sh`, then `verify_all.py` (names failing functions) if it doesn't say OK.

More patterns (session 3, with `-mhard-float`):
- A global updated next to stores through a pointer: declare it as a struct field
  (`D_X.f_0 |= 4`) when the original keeps the order; a plain scalar lets the scheduler move it.
- A loop whose multiply by a variable is not strength-reduced, or whose array address is
  recomputed each pass, was written with `goto` (no loop notes); keep any invariant base
  in a local before the label.
- `if (b & 0x1000) k = 1;` (with `k = 0` before) gives `andi`+`sltu`; `k = (b & 0x1000) != 0`
  gives `srl`+`andi`.
- A call result used only as `(s16)` after two branches join: declare the callee `s32` and
  the local `s16`.
- Range checks written as one `||` expression get folded into one unsigned compare; separate
  `if`s (or nested ones) keep two compares.
- A function that "returns" whatever its last call left in `v0`: declare it `s32` with no
  `return` (`func_8003B534`). A tell-tale sign: branches to the epilogue keep a `nop` in their
  delay slot where ours have the next `li v0,...`, because `v0` is live at the exit
  (`func_8003F530`, `func_8003F86C`: `void` -> `s32` with bare `return;`).
  `wip/_try/selfret.py FUNC FILE` tries that.
- `tbl[i].fn(...)` in a nested loop: indexing (not a pointer) gives the extra invariant copy
  of `&tbl[i]` seen in the inner loop (`Link_InitArea`).

Naming: identified symbols get readable names (`Subsystem_Verb` for functions, `g_Name` for
globals) listed in `docs/names.txt`. `python tools/rename.py docs/names.txt` (or `old new`)
replaces a name everywhere (C, headers, asm and its file names, configs, docs, wip drafts) and
adds it to `symbol_addrs.txt`; the build must still be byte-identical. Renamed functions get a
short comment saying what they do. `verify_all.py` checks renamed functions too.

Pitfalls seen while integrating:
- Callers that pass more or fewer arguments than a definition takes (the original code did):
  `tools/knr.py file func` turns the definition into an old-style one.
- A function returning `s16`/`u8` makes callers re-extend the result; if its body already
  returns a sign-extended load, declare it `s32` (same code, callers match).
- Permuter output was scored with relocated jumps masked: a `j` to a local label one
  instruction off "matched". `func_code`/`matches` now compare local jump targets by their
  offset in the function.
- Converting the last function of a file drops the alignment `nop`s its asm carried; if the
  next object is a 4-byte-aligned library object, end the file with
  `__asm__(".section .text\n\t.align 4\n");` (see `8001F3A0_draw_fx.c`).
- Permuter output written before a struct type existed can do pointer arithmetic on what is
  now a typed pointer (`g_CurMonkey + 0x60`); cast to `s8 *` when integrating.
- An inline `bgez x / negu x` absolute value inside a condition is GCC's builtin `abs()`
  (declare `int abs(int);`); a hand-written `x < 0 ? -x : x` or `ABS()` schedules differently
  (see `Box_IsOccupied`).
- A byte counter decremented as `addiu v0, v1, 0xFF` is `t + 0xFF` on a `u8` temp, not `t - 1`.
- A file that needs the shared `Monkey` struct can switch its `#include "common.h"` to
  `"game.h"` (done for `8008FC30_box.c`); otherwise use a byte-array view.
- The order of an array address `addu` (index + base or base + index, and which register gets
  the result) can be steered: a local pointer `T *w = base + i;` puts the result in the base's
  register (`PlateGate_Update`), and integer arithmetic `(T *)(i * 4 + (s32)base)` keeps
  index-first order (`func_80056010`).
- Our maspsx used to put a load-delay `nop` after an expanded `div`/`rem` whose result is used
  next; the original never does (checked across the binary), so the vendored copy no longer
  does (`tools/maspsx/PATCHED.md`).
- Scratchpad (0x1F800000) accesses: through a typed struct pointer GCC keeps loads from other
  pointers after the scratchpad stores (it assumes they may alias), as the original does; through
  `u8 *` plus casts it reorders them (`Camera_UpdateOrbit`).
- A `bnez` around a lone `j` into the middle of another case's code usually means the source
  repeated that code (GCC's cross-jumping merged the copies); write the code out again rather
  than using a `goto` (`Mailbox_Update`).
- A call with no extension of a narrow argument, to a function defined later in the same
  file with an `s16` parameter, means the original had no prototype in scope there. Declare
  it `void f();` and make the definition old-style (`f(a, b, sc) ... s16 sc; {`): GCC rejects
  an empty declaration followed by a prototype with an `s16` parameter, but the K&R definition
  compiles to the same code here (`MagicPunch_Draw`). `tools/knr.py` refuses `s16` parameters,
  so do it by hand and let the full build check it.
- Jump tables: GCC only builds one when there are enough case labels and the table spans from
  the lowest to the highest label. If the original's table starts below (or ends above) the
  cases that do something, add empty `case n:` labels next to the default/`break` (the entry for
  case 1 and 33 in `Stage_UpdateAreaState`, case 'A' in `Platform_RunTrigger`).
- Case bodies are emitted in source order. When a branch falls straight into another case's code
  and that case's table entry points into it, the identical body was written in both places
  and cross-jumping kept the earlier copy (`case 8` before `case 9` in `Link_SendEvent`).
- When two copies of a call tail were merged by cross-jumping but ours merges them the wrong way
  (the other copy is kept), put the call once behind a label and `goto` it from the other place,
  passing every argument through locals set before the jump, the pointer argument included
  (`k0 = p; k1 = 0x50; k2 = 0; goto spawn;` in `EnemyShot_UpdateAll`, `set20:` in
  `Game_SetMode`). A tail that is merged from the middle of a sign extension (`sll` before the
  label, `sra` after) was written out twice in the source; keep both copies and pick the `if`
  form whose branch layout matches, so the copies come out identical and merge.
- A pointer variable assigned twice (`c = &X; ... c = &X;`) loses its known base for alias
  analysis, so stores through other bases stay ordered before its loads; when the original
  interleaves those loads and stores, use a second variable for the later part
  (`Camera_BlendToSetting`, `Hoop_Update`). The opposite also happens: one shared variable
  re-pointed in each block keeps the original's conservative order.
- Which copy of a cross-jumped tail survives can depend on how the cases leave the `switch`:
  `return 0;` in each case kept the earlier copy, `break;` (with one `return 0` after the
  switch) kept the later one as in the original (`MemCard_Request`).
- A `return 0` kept as a stub (`j epilogue; move v0, zero`) that other early exits branch to,
  while the remaining exits use `bnez epilogue; move v0, zero`, is one `miss: return 0;` in the
  source with `goto miss;` from the exits that reach it; try the label at each `return 0` site
  (`wip/_try/misssearch.py`), or after the final `return 1` (`Coll_PushDiagonalWall`,
  `Coll_PushWallSegment`).
- A `move` copy of a freshly computed small value (an `or` of two `slt` results) before it is
  compared, with the original register still used for a later range check, is a narrow local:
  `s16 side = (a < b) << 1 | (c < d);` GCC drops the sign extension because the value fits, but
  keeps the copy (`Coll_PushBox`).
- A function that matches alone can lose it inside its file when `hand_apply` rewrites a global
  as `(*(T **)&X)[i]`; the plain cast `((T *)X)[i]` gives the same code as the standalone
  version (`Rotor_Update`).
- Indexing a global array through a cast (`((T *)&X)[i]`, as `hand_apply` writes when the file
  declares `X` with another type) can change loop optimisation (strength reduction of the index)
  compared with a plain `X[i]`; give the file one declaration that fits every use, e.g. a union
  of the old struct and the new view (`g_SpuUploadQueue` in `Spu_ProcessUploadQueue`).
- A top-tested loop whose loop-invariant address is recomputed every pass (not hoisted into an
  `s` register) is a `goto` loop (`loop: if (...) { ...; goto loop; }`): GCC only runs loop
  optimisation on real loops (`Spu_ProcessUploadQueue`).
- `addu base, base, index` (base register first) for an element of an array reached through a
  global pointer, where `p[i].f` gives `addu index, index, base`, comes from byte arithmetic:
  `*(u16 *)((u8 *)p + (i << 4) + 0xC)` (the sequencer's `D_800E1874` voice registers).
- A loop that strength-reduces to a pointer at a field (`addiu v1, v0, 2` before the loop, then
  `lhu 0(v1)`) walks the array with `p++` and `p->field`, not `p[i].field` (`func_8004BD0C`).
- A branch to the epilogue whose delay slot stays `nop` although the fall-through instruction
  only writes `v0` means `v0` is live at the return: the function is declared to return a value
  (`s32`) even if it has no `return` statement (`func_8003FB44`).
- GCC 2.8's alias check treats a store into a struct field (`p->f`) and a load of a plain global
  scalar as independent, so the scheduler may sink the store below the load. When the original
  keeps such a store first (or reloads struct fields after stores to globals), the access was not
  a struct member: write it as `*(s16 *)((u8 *)p + 2)` (`func_80094AE0`). Conversely, a global
  stored through a struct (`D_800F75C0.f_8` instead of a separate `D_800F75C8`) keeps a later
  struct-field load behind it.
- The two `ABS` spellings compile differently: `x >= 0 ? x : -x` (common.h) copies `x` and
  negates the copy (`move v0, a3; bgez; negu v0, v0`), `x < 0 ? -x : x` (redefined in
  80032E30_monkey.c) negates the original. Spell the ternary out when a file redefines `ABS`
  (`func_80040BDC`).
- A store common to both arms of an `if`, which ours sinks into a later call's delay slot while
  the original keeps it before the argument setup, was written in both arms (cross-jumping
  merged it at the join) (`func_8003CC3C`). Likewise a call with a different constant argument
  in each arm, where ours has one call with a ternary argument, is two calls (`func_80054220`,
  `func_80053CE8`).
- A global struct whose address is rebuilt (`lui; addiu`) at the start of each `if` block was
  reached through a local pointer re-assigned before each block (`p = &D; if (...) p->a = ..`);
  `D.f` directly gives `lui` + `%lo(D+off)` instead (`func_80095244`).
- `o = &arr[i];` at the top of a counted loop gives the original's pointer induction register;
  `for (i = 0, o = arr; ...; i++, o++)` can make GCC pick a field address as the induction
  variable instead (`Object_DrawAll`).
- A two-case `switch` whose test has an extra `slti` bound check (`beq 2; slti <3; bne 3`) has
  a third, empty `case 1: break;` (`Game_MainLoop`). A range check done as two compares
  (`slti <0x34; slti <0x31`) is a `case 0x31: case 0x32: case 0x33:` group (`Hoop_Update`).
- A `move rX, rY` where rY is known to be 0 (instead of `move rX, zero`) is a chained assignment:
  `for (i = n = 0; ...)` (`Save_SumStageMonkeys`).
- A conditional whose result the original moves into `v0` on the non-call path
  (`move v0, a1` in a delay slot, then one shared store) is an if/else into a temporary,
  `if (g < y) r = f(); else r = y; p->y = r;`, not a ternary (`Monkey_UpdateJump`).
- A `do { ... } while (0)` around a statement group (probably a macro in the original) changes
  the scheduling around it; the permuter found it for `FallBlock_Update`.
- A local struct copied from a `D_` rodata block just before a jump table's `jtbl_` symbol was an
  initializer in the original (`RECT r = { 0, 0, 0x180, 0x200 };`): GCC emits the initializer
  data before the function's jump table, while `INCLUDE_RODATA` of the block would land after it
  (`ScreenWipe_Update`).
- When an `ABS`-style test or arithmetic loads its operands in an unexpected order, try writing
  the operands in load order (`-p->x + o->x + o->z`, `Geo_DiagonalDistance`).
- A zero word that splat split off after a jump table (`jtbl_..._pad`) is sometimes emitted by
  GCC itself (when the next table is in the same function, `MemCard_Callback`: drop the
  `INCLUDE_RODATA`) and sometimes not (`Link_RestoreSaved`: keep it after the function); the
  build check tells which. A 4-case `switch` on consecutive values compiles to a `beq` chain
  without range checks when the index is cast to `u32` (`switch ((u32)res)`).
- Arguments read as `*s++` in the order the original loads them want separate block-local
  temporaries (`x = *s++; y = *s++; z = *s++; f(v, x, y, z);`), not reused outer ones
  (`Effect_Spawn`). An 8-word copy as `lw` x3 / `sw` x3, x2, x3 is three temporaries reloaded
  in groups (`Matrix_Copy`).
- A function that matches alone in `check_c.py` can still swap the load order of two operands
  once it sits in its file (the other code changes GCC's internal ordering). Moving the
  subexpression into a temporary pins the order (`s32 t = o->f_B2 + 0x1000;
  o->f_AC = (o->f_AC + t) % 0x1000;` in `Object_UpdateAll`).
- A subtraction like `r - (dx - 12)` is folded to `(r + 12) - dx` unless the inner part is a
  separate statement (`u = dx - 12; out = r - u;`, `Coll_PushWallEdge`). A bound that is negated in
  place (`t = r + 12; ... t = -t;`) keeps GCC from reusing `r + 12`.
- Register allocation follows which variables the original shared: in `Monkey_PickNextNode` all
  three loops share one counter but the middle loop has its own link variable (`next`); a small
  script that tries the combinations finds this quickly. Early returns that sit together at the
  end of a function are `goto` labels in the source (`fail:`, `found:`).
- GCC evaluates the left operand of a comparison first: if the original calls a function before
  loading the other side, put the call on the left (`if (f(...) > s->y + s->vy)`,
  `Platform_MoveRiders`). A field loaded both with `lh` (for a test) and `lhu` (for arithmetic)
  is an unsigned field tested through an `(s16)` cast.
- `hand_apply.py` may rewrite an extern array access as `((T *)&array)[i]`; that cast can stop GCC
  folding a constant index into the symbol offset. If a function that matched alone is a few
  instructions short in its file, give the file's declaration the needed fields and index the
  array directly (`Spike_StateClimb`). `py wip/filediff.py <func>` diffs the in-file compile
  against the original.
- An epilogue with `sra v0` before `lw ra` and a `nop` before `jr ra` means the return value came
  from separate `return f(...)` statements that GCC cross-jumped into one call, not a single call
  with variable arguments (`func_80058400`).
- A `%lo(D_X + 1)` byte used as a scalar counter, while other code uses `D_X` as an array, wants
  its own extern plus a linker alias (`D_800B1B40_1 = 0x800B1B41;` in `undefined_syms_auto.txt`);
  indexing the array makes GCC build a base address. Writing `p->f` straight through a global
  instead of a `T *t = &global` local can also move a shift into place (`func_80065ED4`).
- A value that sits in `a0` just before a `jal` is not always an argument: if the draft loads a
  field twice, check whether the callee takes any parameters at all (`func_80035A7C` calls
  `Monkey_RestartAnim()`; the `a0` only feeds a store in the delay slot).
- A word in the overlay area read as `lui v1,0x8015; lw v1,0x44CC(v1)` (one register) was a raw
  address, `*(s32 *)0x801544CC`, not the extern splat named `D_801544CC` (that one loads through a
  second register; `Stage_Begin`).
- When a value is copied into another register before each compare (`move v1,s8` then `bne v1,...`),
  try `s16`/`u16` for the local that holds a masked field; `s16 side`/`s16 axis`/`s16 kind`
  removed exactly those copies in `Coll_PushWedge` and `Platform_UpdateOrbit`.
- `li a3,1; sllv; and` for a bit test means the flags word is unsigned: on an `s32`, GCC turns
  `x & (1 << i)` into `(x >> i) & 1` (`srav; andi`) (`func_800977BC`).
- Stores into one global through a base of `symbol+0xC` with a negative offset for an earlier
  field (`sb v0,-4(v1)`) come from a local pointer to an inner struct (`p = &G.pos; p->vx = ...;
  G.f_8 = ...`). For short store sequences, trying every statement order is quick
  (`func_8006C6A4`).
- A run of range checks where every failing branch jumps to one shared `jr ra; nop` with `v0 = 0`
  in its delay slot (and no `jr ra` in the middle) is a single positive `&&` condition:
  `if (a >= x && x >= b && ...) return 1; return 0;`. Separate `if (...) return 0;` statements and
  `||` both give inline returns (`Box_ContainsPoint`).
- `sll/sra` kept before a `negu` whose result is only stored as a halfword: the negation went
  through an `s32` temporary (`t = -(s16)ang; r.vx = t;`); written inline GCC drops the extension
  (`Model_SetTurnAngle`, found by the permuter).
- If `hand_apply.py` reports "N prototypes rewritten" and the build then fails or shrinks, restore
  the file from the snapshot and insert the function by hand. Where the file declares a helper
  with a narrower return type than the match needs (`s16 func_8005278C`), call it through a cast,
  `((s32 (*)(void *))func_8005278C)(o)`, which still compiles to a direct `jal`
  (`Object_UpdateAction`).
- A struct copy into a global field whose destination is a separate register (`addiu t3,v0,%lo(G+0x94)`)
  and the base later rebuilt as `addiu v0,v0,%lo(G+0x94); addiu v0,v0,-0x94` was written through a
  pointer: `T *dst = &G.f; *dst = *a;` (`func_80066DAC`).
- Element addresses formed as `base + (k + j*size)` in a nested loop come from indexing one
  record's array past its end: `a->arr[k + j * sizeof(*a)]` (`Save_InitSlots`).
- An `s32` loop counter over an indexed global (`G[i].x = ...`) lets GCC create the pointers after
  the loop guard; a `u8` counter or a pointer initialised in the `for` header puts them before it
  (`Anim_SetFrame`).
- `if (p == 0) r = 0; else r = p->f;` and `r = 0; if (p) r = p->f;` compile differently: the first
  keeps the address of `p` from being reused after the `if` (`Object_DetachLink`). A permuter "match"
  that reads an uninitialised variable to get the same effect was rejected.
- `li a0,C; slt v0,a0,x; bnez` (constant in a register, compared on the left) comes from a bound
  computed from a variable that GCC only later finds constant (`ox + 0x40 < p[0]` with `ox = -0x100`);
  writing the constant directly gives `slti v0,x,C+1; beqz`. Range pairs on one value must be separate
  `if`s with `goto`s, or GCC folds them into one unsigned compare (`func_8004E63C`).
- Give library calls their real return types even when the result is ignored: declaring
  `CdIntToPos` as `void` instead of returning `CdlLOC *` changed how the caller kept its own return
  value (`Cd_GetFileEntry`). A cast in a struct-pointer table (`(T *)&g_X; c += i;`) can match where
  `&g_X[i]` doesn't (`Seq_SetTempo`).
- A branch to the epilogue with a `nop` delay slot where `return 0` would put `move v0,zero` is a bare
  `return;` in a function that otherwise returns a value; v0 is left as the last call's result
  (`Gadget_SelectFromButtons`). Keeping a scratchpad base in `s0` across a call needs an explicit
  `u8 *spad = (u8 *)0x1F800000;` with offsets from it.
- Short parameters handled inconsistently (some sign-extended at entry, others kept as `lw` words and
  extended only where passed on) come from an old-style K&R definition, `f(s, a, b) void *s; s16 a, b; {`
  (`Object_AddAttackSphereNear`). An `int` divisor that compiles to a real `div` instead of a magic
  multiply was an expression of named constants (`(hi - d) * 60 / (hi - lo)`, `Monkey_AvoidConeAngle`).
- A signed `slt` pointer compare at the bottom of a loop is a strength-reduced `int` index loop
  (`for (i = 0; i < 16; i++) a[i]...`), not a pointer loop (`Monkey_UpdateQueuedSounds`).
- A function that returns its last test value (`v0` left from an `lbu`) for unlisted cases has no final
  `return` (`Monkey_GetAlertLevel`).
- When ours merges identical branch tails (one `j` to a shared `jal f(9); li a0,0x43`) but the
  original repeats them, the original called the final function in each branch instead of setting
  a variable for one shared call (`Spike_Land`).
- `sll/sra` then `bgez` on a value whose raw form is kept elsewhere is a `(s16)` test of an `s32`;
  and a wrong `u8` local silently deletes an `abs()` (the compiler knows it is non-negative).
- A tail `if (f() != 0) return 1; if (x < y) return 1; return 0;` becomes an `slt` result, while the
  original's branch to the epilogue with `li v0,1` in the delay slot came from one combined
  `if (f() != 0 || x < y) return 1; return 0;` (`Monkey_CheckRouteAway`). Callee prototypes that return `u8`
  add an `andi` at each call; call through `(s32 (*)(...))f` when the original caller didn't mask.
- A small switch whose tree tests the middle value first (`== 1`, then `< 2`, then `== 0`) had an
  extra empty case: `case 2: break;` adds a node and changes how GCC balances the compare tree
  (`Link_UpdateFlybyTrigger`). A C89 declaration placed right after a `case` label is a syntax
  error, which `sd.py` reports as an empty diff (looks like a match); always confirm with check_c.
- A `move v0,a1` copy of a pointer just stored into a struct is a read-back of that field
  (`o->unk4 = (s32 *)(o->unk0 + 1);` right after `o->unk0 = h;`), and the order of the following
  assignments decides where it lands (`func_80015D10`). Two pointer variables holding the same
  constant (the scratchpad base) keep separate registers where one variable would be CSE'd
  (`Menu_DrawStatusScreen`).
- A state handler written `switch (s->state) { case 0: ...; break; } return 0;` compiles differently
  from `if (s->state != 0) return 0; ...` (`Link_UpdateFlybyOnSwitch`).
- Branchy `|a - b| < lim` checks that load the limit before the subtraction come from a macro
  `ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))` inside the comparison
  (`Object_SpikeOutOfYRange`, the door handler). A `lw` of an int field where ours narrows to `lhu`
  came from `x * 4` instead of `x << 2` (`Camera_FollowRcCar`).
- Judge near-misses by check_c, not by `sd.py` line counts: sd counts symbol+offset relocation
  displays (`%lo(X)` vs `24`) as differences, and check_c's `~~` lines can hide register swaps.
  `wip/_try/realdiff.py [-v] FUNC FILE` counts only structural differences (register names and
  immediates normalized), which separates real problems from permuter-only register allocation.
- A then-branch whose `j` lands in the middle of the else-branch (on a shared last statement)
  means both branches ended with the same statement, cross-jumped; writing it once after the
  `if` puts it in a new block and the scheduler hoists later loads above it (`Monkey_FireShot`).
- A two-case switch whose tree has an extra range test (`== 0x20`, then `< 0x21` to default,
  then `== 0x30`) had one more case label merged with `default`, such as `default: case 0x10:`
  (Monkey_Update's hit-type switch, `Monkey_Update`).
- Shared `return 0` paths that all jump to one block right before the epilogue came from
  `break`s out of a switch to a trailing `return 0;`; direct `return 0` statements instead branch
  to the epilogue with `move v0,zero` in the delay slot (`func_80074BBC`).
- A clamp whose middle branch keeps the raw (unextended) value, `x < lo ? lo : (x > hi ? hi : x)`
  with the compares on `(s16)x`, is a ternary on an `s32` (`func_80059304`); an `if/else if` chain
  or an `s16` variable does not give the same register flow.
- **More on `do { ... } while (0)`** (see the `FallBlock_Update` note above): the loop notes end
  GCC's CSE path (later code reloads globals and fields it already had in registers) and loop.c
  hoists addresses like `&g_CurMonkey` into `s`-registers. Suspect it when the original reloads a
  value for no visible reason, or keeps `addiu sN, hi, %lo(sym)` and then `lw 0(sN)`. Where the
  `return` sits matters: `do { f(); } while (0); return;` and `do { f(); return; } while (0);` give
  different code. `Monkey_UpdateHelmetLight` needs `do { vis = 1; } while (0)`; `Monkey_StateInPlace`
  (0x1510 bytes) matched with one around `Monkey_RestartAnim(); return;`, plus an `else { mm = CM;
  if (...) }` block where an `else if` gave different code.
  It is so common (`GuidedAmmo_FindTarget`: `do { best = len; } while (0)`, `Flare_Add`,
  `Link_InitArea`) that the original probably had macros like `#define SET(a, b) do { a = b; } while (0)`.
- When a global is already declared in the file with another type, use an alias extern
  (`extern T *D_800AF868_li[] asm("D_800AF868");`), not a cast: `((T **)D_800AF868)[i]` moved the
  `%lo` load to another register in `Link_InitArea`.
- m2c adds arguments a call doesn't have when the argument registers still hold something:
  `func_800856FC` called `Floor_GetHeight(x, y, z, 2)` because `a3` held the switch constant 2.
  Passing the extra argument forces a `li a3` and moves that constant out of `a3`; check the
  callee's real parameter count.
- Inserting a function with a `switch` by hand (named functions skip `hand_apply`): delete the
  `INCLUDE_RODATA(..., jtbl_X)` lines for its jump tables, since the compiled switch emits its own;
  otherwise the image grows and every later address shifts.
- **A callee's return type matters even when the result is unused**: declaring an int-returning
  function `void` changed register allocation around its call (`func_80095960`: `move v0,zero`
  moved and the stores used another register; `func_8005BEF0`: the struct-copy temporaries shifted
  by one). The original probably called them without a prototype (implicit int). In a file that
  already declares the callee `void`, use an alias: `s32 f_x(void) asm("f");`.
  `wip/_try/retflip.py FUNC FILE` flips each callee prototype between void and s32.
  PsyQ library functions have real return types that drafts often drop: `VectorNormal*`,
  `SquareRoot0`, `rsin`/`rcos` return `long`; `RotMatrix*`, `MulMatrix*`, `CompMatrix`,
  `ApplyMatrix*`, `ScaleMatrix*` return `MATRIX *`/`VECTOR *`; `ClearImage`, `LoadImage`, `DrawSync`
  return `int`; the BIOS memset stub `memset` returns a pointer. `func_8003C568` matched
  only after `VectorNormalSS` was declared returning `long`. `wip/_try/psyqret.py FUNC FILE`
  rewrites a draft's library prototypes with these types.
- **hand_apply can break other functions**: the prototypes it adds to the file (here a new return
  type for `Collision_GetShape`) can change how other functions in the file compile; the build then
  fails with a shorter binary. Restore the file from a snapshot, `touch` it (tar keeps the old
  mtime, so make would not rebuild it) and insert the function by hand with `asm("name")` alias
  prototypes (`func_80068634`).
- **check_c's MATCH is not the last word**: it masks relocations, so a switch whose jump table
  sends one case to a different (identical-looking) block still "matches" (a permuter result for
  `func_8008FC30` had emptied `case 7:`, which the original cross-jumps into the tail of
  `case 0x1B`). The full build's checksum is the real test; when it fails after an apply, diff
  `build/SCUS_944.23` against the original to find the address. The file context can matter too:
  `func_8005BEF0` matched alone but not in its file, where one prototype order changed its
  registers (removing any one of four prototypes fixed it).
- **One variable or several**: GCC 2.8 allocates one register per variable, so reusing a local
  across unrelated statements (or splitting one) moves registers around far away. Reusing `d`
  (`d = d / a[2] + a[3]; f(d, d + 1)`) matched `Anim_BlendCurrentEntry`; giving a clamp and a
  division result in one `case` their own fresh variables took `Monkey_Update` (0x1224 bytes) from
  60 differing lines to a match. `wip/_try/splitvar.py FUNC FILE` tries splitting each reassigned
  local at each plain assignment; `wip/_try/dowhile.py FUNC FILE` tries a `do { } while (0)` around each
  statement (not `break`/`continue`, whose meaning would change); `wip/_try/greedy.py FUNC FILE`
  repeats both and keeps the best. A lower diff count is only a hint: read what changed.
- **Clamp into a new variable**: `c = n <= 0 ? 1 : n >= 11 ? 10 : n;` (a CLAMP macro, probably)
  keeps `n` and the result in two registers (`j ...; move v1,a0`); clamping `n` in place with
  `if`/`else if` does not (`func_80083790`).
- **Two compares of the same value**: when the output tests a value and a register copy of it
  separately (`move v0,v1; slti v0,v0,8 ... slti v1,v1,8`), the source had two variables set in
  every branch before a join (`vl = x; vr = vl;` in each arm), so CSE cannot tell they are equal
  after the join (`func_80087EE0`, left/right sound volume).
- **Scalar global vs struct global**: GCC 2.8 assumes a store through a struct pointer
  (`c->f_6C = 0`) cannot alias a plain scalar global (`extern u32 D_800E5478`), so it may move the
  store past the load (into a delay slot). If the original keeps the store before the load, the
  global is really a struct member or array element: `extern struct { u32 v; } X_s asm("X")`
  (`Camera_HandleManualInput`; it also needed `lim = x; lim -= 0x404;` in two steps).
- **Switch decision trees depend on every listed case**: GCC splits the sorted case list at its
  middle, so cases that only fall into `default` still move the root. `func_800356C0` (one result
  per monkey type) only matched with all seven type ids listed (`case MONKEY_YELLOW: ...
  default:`) and with the default group placed between the two other groups (block order).
- **addPrim comes in two forms.** Most draw code links a primitive with the C bitfield form
  (`lw/and/or` with 0xFFFFFF / 0xFF000000 masks; `P_TAG { u32 addr : 24; u32 len : 8; }`).
  About 52 functions instead use a fixed 4-instruction sequence that no C form or compiler in the
  image produces: `lwl t1,2(ot); sll t2,p,8; swl t2,2(ot); swl t1,2(p)`. It is an inline-asm macro
  in the original; this reproduces it with compiler-chosen registers and offsets (`func_80099D70`,
  the Monkey Radar, matches in size with it):
  `__asm__ volatile("lwl %0, %2\n\tsll %1, %4, 8\n\tswl %1, %2\n\tswl %0, %3" : "=&r"(t1), "=&r"(t2)
  : "m"(*((u8 *)ot + 2)), "m"(*((u8 *)p + 2)), "r"(p));`

## Next steps

1. Keep going through `near_misses.txt`, then the larger functions.
2. Name things: the debug strings `zako.c` (enemies) and `item.c` give file names.
   The generated `S_D_XXXXXXXX` structs (one per file, fields `f_<offset>`) can be merged
   into shared named structs in `game.h`. `g_Game` is the big game state (`+0x8120`
   game mode). It's declared per file for now, so the automatic pass can keep widening it.
3. GTE functions (geometry coprocessor instructions) are still skipped; they need the
   PsyQ `gtemac`/inline GTE macros.
4. Unpack `KKIIDDZZ.DAT` using `KKIIDDZZ.HED` and the loader `Cd_ReadFile`, then give each
   overlay its own splat segment at `0x80136000`.
5. Do the same for the minigame executables.
