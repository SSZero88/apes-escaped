# What the code does (working notes)

Identifications so far, with the evidence. Confirmed ones get readable names via
`docs/names.txt` (applied with `tools/rename.py`); the text below now uses those names.

## Monkeys
- `Monkey_IsOffScreen`: the current monkey counts as off-screen (returns 1) unless its
  state `f_7A` is not 0/2, it is within 6000 of the camera target `g_CameraTarget`, and its
  projected position is inside x -50..434, y -25..265 with positive depth. Also stores the
  screen x and the screen y of a point 400 units above it at `+0x80/+0x82`.
- `g_Monkeys`: 8 monkey records of 0x250 bytes. `Monkey_InitAll` initialises them and prints
  "Error!!! Too many monkeys in one area. Max is %d" (max 4) when an area asks for more.
- `g_CurMonkey`: pointer to the monkey being updated (`Monkey` in `game.h`). `+0x24/0x28/0x2C`
  position, `+0x78` state (values like 0x1D, 0x3E, 0x3F are set by the per-state functions).
- `g_MonkeyTarget`: set to `&g_Spike` by the same init; the monkey code only reads its position
  (`+0x24/+0x2C`), so it's the thing monkeys look at / run from: most likely Spike.

## Spike / input
- Moving platforms: `Platform_Move(platform, id)` moves a platform record and calls
  `Platform_CarryRiders`, which carries Spike (`g_Spike`) and a second object (`g_RcCar`) by
  the platform's delta when their `+0x58` (platform they stand on) equals `id` and the delta
  is small (|dx|,|dz| <= 0x200, |dy| <= 0x400).
- `g_Spike`: big object with position at `+0x24/0x28/0x2C` (s32), rotation-ish SVECTOR at
  `+0x60`, flags at `+0xE0`. Monkeys track it (above), so probably Spike.
- `g_Pad + 0xA4`: ring buffer of 40 `u16` entries, write index at `+0x170`.
  `Pad_RecentL1/8006501C/800654AC/80065538` (and `Pad_RecentCross`) return 1 if a given value
  (4, 8, 0x10, 0x20, 0x40) was recorded in the last 10 entries, unless `*(0x1F800080)` is set.
  Those values are PS1 pad bits (L1=4, R1=8, triangle=0x10, circle=0x20, cross=0x40), so this is
  most likely a button-press history used to buffer inputs (jump is on a trigger; gadgets are
  selected with the face buttons).

## Misc
- `bios_printf`: BIOS printf (A0 table). `bios_exit`: BIOS exit (B0:0x38).
- `Mem_AllocFailed`: "Smalloc Error!" handler (prints size, then exits). `Mem_Alloc` is the
  allocator: bump pointer `D_800DF798`, limit 0x801027FF, 4-byte rounding.
- `g_RandSeed`: 16-bit random seed, `seed = seed * 5 + 1`; callers use bits 8+.
- `g_Game + 0x8140`: frame counter capped at 359999 (= 99:59:59 at 60 fps?): play time.
- `D_800B000C`, `D_800B00C8..D_800B0174`: debug menu tables; entries name `COLTEST`, `SOUND`,
  `ZAKO` (enemies), `MON COL/PRM/xN` (monkeys), `KAKERU` (Spike's Japanese name), `PAUSE`.
- Original source file names from asserts: `zako.c` (enemies, file 80050580), `item.c`
  (gadgets, file 80083470).
- `Spike_TakeDamage(dmg)`: Spike takes damage. Health is `g_Spike + 0xE8` (floored at 0); the
  HUD gets the amount at `D_800F4DB0 + 0x14` (shown for 12 frames); `+0xEA` = 60 is an
  invulnerability timer (`D_800EC2CA`, which the monkey code also checks). Ignored in game
  modes 0x1F/0x20 (`g_Game + 0x8124`).
- `g_Game` layout: `+0` frame counter, `+4` primitive write pointer, `+8` ordering table,
  `+0xC` buffer index, `+0x10` two 0x4078-byte draw buffers (OT of 0x1000 entries at `+0x70`),
  game state from `+0x8100` (see `Gfx_BeginFrame`, the per-frame buffer swap).

## Gadgets
- `g_CurrentGadget` is the current gadget number. **IDs (now well supported):** 0 Stun Club,
  1 Time Net, 2 Monkey Radar, 3 Slingback, 4 Super Hoop, 5 Magic Punch, 6 Sky Flyer, 7 RC Car.
  Evidence: `Gadget_SetupStageLoadout` gives each tutorial stage one gadget, and
  `Tutorial_SetNextStage` sends each tutorial on to a stage; the pairs agree with the user's
  acquisition order:

  | tutorial stage | gadget given | next stage | fits |
  |---|---|---|---|
  | 0x62 | 0 (only the defaults; the Water Net is not a slot gadget) | 2 | Primordial Ooze, Water Net |
  | 0x5C | 2 | 6 | Thick Jungle, Monkey Radar |
  | 0x5D | 3 | 15 | Cryptic Relics (level 6, confirmed by the user), Slingback |
  | 0x5E | 4 | 20 | Super Hoop |
  | 0x5F | 5 | the remembered stage | Magic Punch (post-game, no level of its own) |
  | 0x60 | 6 | 30 | Sky Flyer |
  | 0x61 | 7 | 53 | City Park, RC Car |

  This also fits the sounds: `Gadget_StopSounds` stops 0x1D/0x1E for gadget 6 (the Sky Flyer's
  wind-up and activated sounds, per the user), and `g_RcCar` (the second platform rider) only
  gets gravity while gadget 7 is not in hand, so it is the RC car. The selection grid order
  (user: Club, Net, Radar, Slingback, Hoop, Sky Flyer, RC Car, Magic Punch) is not the ID order.
  `Gadget_StopSounds(gadget)` (called when pausing, from `Pause_Update`) stops that gadget's
  looping sounds: 0 Club -> 0x3D (voice `g_GadgetState+0x48`), 2 Radar -> 0x25/0x26
  (`+0x14/+0x16`), 4 Hoop -> 0x2C twice (`+0x20/+0x22`), 6 Sky Flyer -> 0x1D/0x1E (`+0x4/+0x6`,
  flags `+0x8`), then the shared loop in `D_800F51D0+0x18`.
- **Magic Punch** (user): `MagicPunch_Update` stretches the punch arm lengthwise by
  `g_GadgetState+0x28` (half length to ~1.1x), pumped by an analog controller value
  (`D_800E54D4` = `g_Pad+0x1B4`, `|v| * 4` per frame) while Spike's action state is 0x8A/0x8B,
  against a constant pull back; it has a pulsing pink-red glow. `MagicPunch_AddHitSpheres` puts two
  collision spheres on the arm (bigger one at the tip, 3/8 along a smaller one).
- `SkyFlyer_Update` confirms gadget 6 = Sky Flyer: its two sounds 0x1D (wind-up, Spike action states
  0x80..0x82) and 0x1E (flying, states 0x83..0x84) are the ones `Gadget_StopSounds(6)` stops.
- `Roller_UpdateSound`: a rolling object's rumble loop (sound 0x16, pitch from its speed) and a thud
  (0x17) when it stops; the user thinks there is such a rolling object. Collision type 2 starts
  the same loop, so type 2 is that rolling object.
- `Mailbox_Update` (user: the mailboxes are how the Professor gives tips, and show an indicator
  when Spike is close): range
  `t->f_E`, effect 0x112 is the indicator above the box, `Mailbox_OpenTip(slot, sector)` reads
  the tip: one 2 KB sector of CD file 0x14 (the tips file) at the box's own offset, then opens the
  tip screen (game mode 3). In the tutorial stages it rearms every time Spike walks away and back.
  The same 4-entry table (`g_TipState+0xE4`) has kind-2 entries that instead spawn three pickups
  above themselves with a 90-frame cooldown: the cookie dispensers (user: you hit them
  and they spawn cookies), with `Pickup_Drop(1, pos, 3, 0)` spawning one pickup (type 1 = cookie?).
- **Pickups** (`Pickup_Collect`): type 1 cookie (heals, user), 2 extra life, 3 energy chip, 5 big
  energy chip (5 chips), 4 Specter coin, 6 explosive ammo, 7 guided ammo. Lives `g_Game+0x813C`
  (max 100), chips `+0x8168` (every 100 = a life, user: "collect 100 and you get an extra life"),
  Specter coins `+0x816A` (max 60). Ammo pickups add one up to the capacity at `g_Game+0x8154`
  (explosive) / `+0x8156` (guided); `D_800F4350` is `g_Game+0x8000`, so the cheat codes that set
  `D_800F4350+0x154/+0x156` to 49/99 raise these **capacities** (49 or 99 rounds max), not the
  ammo itself.
- Item drops: `Pickup_Drop(type, pos, arg, mode)` picks what to spawn (mode 0: `type` itself; else a
  weighted random pick from a table at `D_800B28A2`, by Spike's health `g_SpikeHealth` (g_Spike+0xE8), with types 7 and 2
  re-picked by helpers and type 3 coming in 2 or 3) and spawns it with `Pickup_Spawn`. In a race
  (`Game_IsTimed`) every drop becomes two type-3 items. **Type 3 = energy chip** (user: in the Jake
  stages you only get the chips that give extra lives). Type 1 is the cookie, which heals (user); the dispensers spawn it.
- `Monkey_UpdateAll`: while the RC Car is out (Spike `+0xF2 == 7`), each monkey reacts to whichever
  is closer, the car (`g_RcCar`, `D_800F5A20`) or Spike. That is how the RC car distracts monkeys.
- Pressure-plate gates (user: stand on the plate, then use the Super Hoop to reach the gate before it
  closes): `PlateGate_Update` opens the gate by the sum of its one or two plates' press depth
  (`g_Game+0x8220[...]+0x16`), loops grinding sound 0x7F while it moves and plays the gate's own
  sound when it settles; `PlateGate_Reset` puts it back.
- `Monkey_IsTargetInRange`: a monkey notices its target within its range (`+0x220`); doubled in
  monkey states 0xC and 0x24, x1.5 in state 9, halved on stages 0x4D and 0x1A while the monkey is
  at one of a few spots (`+0xF2` in a fixed list; maybe hiding places).
- **Damage types** (top byte of a hit's flags, e.g. collision `+0x26`): `Spike_HandleHit` maps
  0x300 -> effect kind 1 (sound 0x34, tint 0xFF0000), 0x200 -> kind 2 (sound 0x33, black tint),
  0x400 -> kind 3 (sound 0x35, black tint), via `Spike_StartDamageEffect(kind)` (50 frames).
  `Spike_UpdateDamageEffect` then runs the particles: kind 1 rising particles, kind 2 alternating
  sparks, kind 3 periodic `Puff_Spawn`. The expanding rings (`Shockwave_UpdateAll`, flags
  0x200) and the spinning arm (`SpinHazard_Update`, 0x203) are type 0x200, so kind 2 is most
  likely the electric shock (user: the angler fish shocks Spike underwater; its pulse would be the
  ring). Kind 1 may be lava (user: Spike can fall in lava). The low byte (3 in 0x203) is probably
  the damage amount.
- `Slingback_Fire`: selected ammo `g_GadgetState+0xA0` (0 regular, 1 explosive, 2 guided),
  counts at `+0xA1` / `+0xA2`; shot types 1 regular, 2 explosive, 3 guided. Regular ammo is
  unlimited (user). With the selected special ammo empty, a regular shot is fired. Special ammo is
  not used up when `g_Game+0x8124 == 0x20` or `+0x8120 == 0x13`; the user knows of no mode where
  explosive or guided ammo is infinite. Mode 0x13 is half of `Game_IsTimed` (the other half is
  sub-mode 3, the race stages). Without first-person view it auto-aims at the nearest target within 400.
- `Gadget_SetupForMode` (game mode `g_Game+0x812C`, sub-mode `+0x8122`): modes 0/7/8 start
  with Club + Net; mode 1 sub-mode 3 is **the race with Jake** (user: "a sorta boss fight"):
  all slots cleared except the 4th, which gets gadget 6 (the gadget in hand), or nothing on stage
  0x13. User: there are two Jake races and probably no Sky Flyer in the first, so stage 0x13 is
  the first race and the other race gives the Sky Flyer, which agrees with gadget 6 = Sky Flyer; mode 1 sub-modes 14/15 and mode 2's tutorial stages use `Gadget_SetupStageLoadout`.
- `Gadget_SetupStageLoadout`: at stage start the four slots `g_GadgetState+0x88..0x8B` are
  cleared to -1; tutorial stages put their gadget in the 4th slot (the gadget in hand); stages
  0x63..0x67 get Club (slot 1) + Net (slot 4) plus: 0x65 Slingback + RC Car (and `+0xA1 = 9`,
  `+0xA2 = 5`), 0x66 Radar + Hoop, 0x67 Sky Flyer + RC Car. These five are probably the Time
  Station minigames or other special stages (unknown).
- `Spike_UpdateGadgetLoopSound` picks a looping gadget sound (voice kept in `D_800F51D0 + 0x18/0x1A`): in Spike
  action state 0x47 it plays 0x3F or 0x73 depending on `D_800E5478 & 0xA`. `D_800E5478` is
  `g_Pad + 0x158`, the held-buttons word, so 0xA is R1|R2: the jump buttons (user: jump is
  on the triggers), except in stage mode `g_Game + 0x8152 == 0xB`; in other states it plays
  0x73 while |velocity x|+|y|+|z| >= 9. Per the user the Super Hoop has an "activated" sound plus
  a "moving" sound on top, and the Sky Flyer a wind-up and an activated sound, neither on the
  shoulder buttons, so state 0x47 is probably one of them, with the second sound while jump is held.
  With the Water Net, R1/R2 make Spike swim faster (user), which fits best: state 0x47 is likely
  swimming with the Water Net, 0x73 the normal swim loop and 0x3F the fast (R1/R2) one; the
  `+0x8152 == 0xB` exception would then be a stage where it doesn't apply. Not yet confirmed.
  Water Net controls (user): R1/R2 swim faster, L3 (pad bit 0x200) descends, R3 (0x400) shoots the net.
- `g_RcCar` is probably the RC car (user's suggestion; it is the only other thing moving
  platforms carry besides Spike): same layout as Spike's record (position at `+0x24`, platform
  id at `+0x58`), drawn by `func_80099AE0` from its own rotation/translation when `+0x70` is set,
  and given gravity (`+0x34 += 7`) while Spike's `g_CurrentGadget` is not 7.
- Super Hoop and Sky Flyer both activate the same way (user): rotate the right stick fast enough and the
  gadget activates, which starts the rumble. Only the Super Hoop leaves a trail (a dust trail) as Spike moves.
- Likely the Super Hoop (user: circling the right stick makes Spike run very fast with a soft,
  repeating rumble): `Collision_UpdateMoveRumble`. When gadget/mode `g_Game + 0x8150 == 1` and the hoop is
  active (`arg->f_C` or `arg->f_14` set, or `D_800E53C0 & 0xFF00FF00`, maybe analog input), it keeps
  sound 0xAD looping (handle in `D_800B20D4`) and vibrates in pulses: strength 0x6E for 2 frames,
  then off for 2, via `Pad_Vibrate(1, D_800B213C, D_800B213E)`. Otherwise it stops the sound.
- Guided ammo (slingback): `GuidedAmmo_UpdateLockOn` is the lock-on. It takes an aim direction (from
  `func_8004B54C` minus Spike's position when `D_800E6916 == 1`, else Spike's facing at `+0x60`),
  picks the nearest target within 400 with `GuidedAmmo_FindTarget` (32 candidate positions at
  `g_GuidedTargets`), registers it with `func_8007A48C`, then projects and draws up to 3 lock markers
  from `g_GuidedLocks` (3 entries: target pointer, countdown) via `GuidedAmmo_DrawReticle`. The user confirms
  guided ammo tracks up to 3 targets and the bullets chase them.
  The slingback has a first-person view on L2 (user); `D_800E6916 == 1` is probably that mode, so
  the lock-on aims along the view (`func_8004B54C` point minus Spike) instead of Spike's facing.
- `g_CurrentGadget` (s8): the gadget currently in hand.
- `g_GadgetState + 0x88`: four gadget slots (s8, -1 = empty), one per face button.
- `Gadget_SelectFromButtons`: gadget selection. Takes newly pressed buttons (`*(0x1F800058) & *(0x1F800054)`
  in scratchpad) and maps triangle (0x10) -> slot 0, square (0x80) -> 1, circle (0x20) -> 2,
  cross (0x40) -> 3, then calls `Gadget_Select(slot's gadget, current gadget)`.
- `Gadget_UpdateHudCursor`: finds which slot holds the current gadget and positions the HUD cursor
  (`g_GadgetState + 0x94/0x96`, default 0x148,0x48).
- `func_80065694`: true for gadgets 2, 5 and 7 (some gadget class).

## Stage records and new game
- `g_Game + 0x8140`: stage timer in frames (capped at 359999 by `Game_VSyncCallback`, the vsync
  callback). `Record_UpdateBestTime` keeps the best time per stage in `g_BestTimes[stage]` (stages
  0x18..0x1D share entry 24) and leaves the previous record in `+0x8144`.
- `g_Game + 0x8124`: current stage/area id (0x1F/0x20 are special: no damage there).
- `Game_NewGameReset`: new-game reset of the `g_Game + 0x81xx` state (sets `+0x813C` = 5,
  `+0x8154/+0x8156` = 9, clears counters), then starts the subsystems.
- `Stage_CountCaughtMonkeys`: counts monkeys in states 2-3 and compares with `D_800DFFE0[stage - first stage
  of its world]` (monkeys required per stage?).

## Drawing
- `Image_DecodeRle4(src, n)`: decodes 4-bit pixel data with run-length encoding into a buffer from
  `func_8008C09C(n)`. A byte whose two nibbles are equal starts a run: the next byte + 2 is the
  run length. Other bytes are copied as two pixels.
- `Debug_DrawMeter` draws 64 one-pixel vertical lines (LINE_F2, x = 0x118 + i, y 10..26), coloured
  from bits 11-13 of `D_800BF690[i]`: a debug meter, probably.
- GPU primitives use the PsyQ layouts and `addPrim` as a 24-bit bitfield link
  (`func_8005CB9C` builds a POLY_F4). A second form, which copies the link with `lwl/swl`,
  appears in other files (`Spike_SetBlinkFrame`, `Menu_DrawCaps`); its source shape is not known yet.
  It gates about 51 functions (`grep -l "swl .*, 0x2(" asm/nonmatchings`). The two forms live in
  different source files (none has both), so it is probably a per-file difference (a different
  P_TAG/macro definition, or those files built differently). Ruled out so far, with all five
  compilers in the image (2.7.2-cdk/-psx, 2.8.1, 2.8.1-psx, 2.91.66): the PsyQ 8-byte P_TAG,
  `unsigned long` bitfields, char/void pointer casts, packed or aligned(1)/(4) tag structs,
  3-byte struct copies and unions (they give and/or masks or byte moves, never lwl/swl).
  Experiments are in `wip/exp/`.

## Oddities
- `func_8003440C` and its twin `func_8003429C` write three different deltas to the same array element (`d[0]`), so only the
  last (z) survives: a bug in the original code, reproduced as is.

## Monkey behaviour (from the user, to map onto the code)
Monkeys flee or attack. Kinds: basic (melee only), fast runners, gun monkeys, rocket-launcher monkeys, UFO
monkeys, monkeys driving robots or other vehicles. They can jump between surfaces and can be
snuck up on. Stun club hits stun them; slingback shots stun them, and explosive ammo knocks them
down. Expect: `MonkeyKind` (g_MonkeyKinds, per kind) = these types; `Monkey.f_78` = AI state
(flee/attack/jump/stunned/knocked down); the state setters in file 80032E30 (e.g.
`func_80035D18`, `func_80035DD8`, `func_8003612C` -> 0x3E, `func_80036174` -> 0x3F) are the
reactions. Not yet confirmed which value is which.

## Monkey types by shorts colour (from the user, 2026-10-15)
- Yellow: normal monkeys; drop banana peels or hit Spike in melee.
- Red: very aggressive, may have guns (no bombs, corrected by the user).
- White: throw bombs.
- Black: aggressive, with guns.
- Green: homing-missile monkeys.
- Light blue: very calm, easy monkeys (from stage 1).
- Dark blue: fast monkeys that run away (from level 5, Dark Ruins).
- Level 4, Thick Jungle (stage id 6, from the tutorial table under Gadgets): first light-blue monkeys, some with a laser gun
  (user, correcting an earlier "black": light blue "can sometimes have laser") and UFO monkeys. The laser window (5) first appears on type id 2 in stage 9 (Thick Jungle), so light blue = id 2 (`MONKEY_LIGHT_BLUE`), which is also the only type in level 1. Id 3 (new in Thick Jungle) is then yellow.
- Level 5, Dark Ruins: first green-shorts (homing missile) monkeys. A type id that first appears in
  Dark Ruins and fires `Monkey_FireShot` (state 0x37?) should be green. The Slingback is first
  used in Cryptic Relics (user), and its tutorial (0x5D) leads to stage 15 = world 6, so `D_800A81B0.f_4`
  ("world") is the level number.
- Green shorts seem to have a larger field of vision (user, unsure). In the code the sight range is
  per kind: `Monkey_CanSeeTarget` compares the distance to Spike (`+0x20C`) with kind `+0xC`[d] (s16,
  d = the low 4 bits of `+0x70` of the object it reads first, a direction sector) and kind `+0x1A`.
  The green kind should have larger values there.
- Level 9, Coral Cave: first red-shorts (very aggressive) monkeys. Red should differ from yellow by
  its kind numbers (wider attack windows, faster chase); some may also use the gun states
  (0x21/0x38) like black.
- White shorts throw bombs: the delayed thrown action (states 0x1B/0x1C, fired just before the
  animation ends) fits them. First level: 10, Dexter's Island.
- Light blue shorts (calm, easy): from stage 1; the lowest speed/aggression numbers.
- Dark blue shorts (fast, run away): first in level 5, Dark Ruins (with green), not Cryptic Relics.
  Expect the highest speed values and the flee states. Level 6 is Cryptic Relics; the "Cryptic
  Ruins" label for stage 15 above is probably that.
To map: the shorts colour is probably selected by the kind type id (kind `+0`, values seen 0, 0x40,
0xC0, 0x140, all multiples of 0x40, so maybe a palette/CLUT row). `func_800356C0`/`func_80035750` group
0x40/0xC0 (sound 0x52 / 0x55), 0/0x140 (0x54 / 0x57), the rest (0x53 / 0x56). Expected attack states:
melee and banana peel for yellow, bomb throw for white (0x1B/0x1C?), red = aggressive, sometimes with the gun states?, gun for black (0x21/0x38 use the
enemy-shot spawner), homing missile for green (0x37 `Monkey_FireShot(3/4)`?), fleeing for dark blue.

## Monkey kind tables from the stage files (2026-10-15, wip/_try/monkeykinds.py)
- `KKIIDDZZ.HED` holds 0x1C0 words: sector (low 20 bits) and size in sectors (high 12) of each file
  in `KKIIDDZZ.DAT`. `D_800A81B0[stage]` = {file list, world}; each file entry is {u16 file, u16 type,
  u32 load address}, list ended by type 0xFFFF. The type-0 file (loaded at 0x80154000) holds the
  area's monkey block: word 0x11, kind count at +0x28, 0x88-byte kinds at +0x2A.
- `D_800A81B0[stage].f_4` is the level in play order (race/boss stages count): stage 1 -> 1, 2 -> 2,
  3-5 -> 3, 6-10 -> 4 (Thick Jungle), 11-14 -> 5 (Dark Ruins), 15-18 -> 6 (Cryptic Relics), 19 -> 7,
  20-21 -> 8, 22-23 -> 9 (Coral Cave), 24-27 -> 10 (Dexter's Island), 29 -> 11, 30-32 -> 12, 33-35 -> 13,
  36 -> 14, 37-39 -> 15, 40-44 -> 16, 45-51 -> 17, 53-55 -> 20 (City Park), ...
- Field names from the developers' monkey-parameter debug menu (`Debug_MonkeyParamMenu`, labels at
  0x800A4BE0..0x800A4CAC): `+2` Speed1, `+4` Speed2; sight distances by what Spike is doing (index =
  the low 4 bits of Spike's `+0x70`, his pose class; 1 = RUN when the RC car is the target): `+0xC` TO-MEI (invisible), `+0xE` RUN, `+0x10` WALK, `+0x12` SEISHI (still),
  `+0x14` HAI+FURI (crawling while swinging?), `+0x16` HAI (crawling), `+0x18` FUSE (lying flat),
  `+0x1A` MARU (curled up). Attack windows: 0 Mgun (state 0x21), 1 Missile (0x22), 2 Banana,
  3 Coconut (0x1B), 4 Stone (0x1C), 7 Scratch (0x37, melee); 5 (0x38) and 6 are not in the menu
  (5 is probably the bomb). Each window is {on, chance %, min, max distance}: `Monkey_AttackChance`
  returns the chance and the caller rolls 0..99 against it once Spike is in range.
- Kind `+0` is the type id / 0x40. First level and attacks of each (the attack layout is the same
  in every area):

  | id | first level | attacks | notes | colour (guess) |
  |---|---|---|---|---|
  | 2 | 1 (all of level 1) | Banana, Scratch; window 5 (laser) in many areas from stage 9 | Speed2 150 | light blue (calm; sometimes a laser) |
  | 3 | 4 Thick Jungle | Banana, Scratch | shorter sight, never a gun window | yellow (by elimination, to confirm) |
  | 1 | 5 Dark Ruins | Banana, Scratch | Speed2 350, the fastest | dark blue (fast, flees) |
  | 4 | 5 Dark Ruins | Missile only (to 3500) | the widest sight | green (homing missiles) |
  | 0 | 9 Coral Cave | Mgun, Missile, window 6, Scratch | the most attacks | red (very aggressive, guns) |
  | 6 | 10 Dexter's Island (4 in one area) | Banana, window 5 (400-6000), Scratch | MARU sight 9999 | white? (window 5 is laser-like, so maybe not bombs) |
  | 5 | 13 | Mgun, Scratch | | black (guns)? unconfirmed |

  Resolved: the level 4 laser monkeys are light blue = id 2 (window 5 from stage 9); id 3 never has a gun
  window. Earlier tables in this file that call id 2 yellow and id 3 light blue are superseded.
  Black is probably id 5 (Mgun, from level 13). Id 0
  also has attack-less records in stages 19, 29, 36 (levels 7, 11, 14: race / special stages).
  Level 1 holds only id 2.
- Kind `+0x1C` reads as four decimal digits 1-6 (id 2 light blue 1111, id 3 yellow 1111, white 2125, green 3234,
  dark blue 3413, red 4234-5544, type 5 3222-6442) and grows in later levels: probably four
  difficulty ratings (alertness, hearing, aggression...?). Other fields: `+2` 80-145, `+4` 150-350
  (speed?), `+8` 30-100, `+0xA` 1/20/50, `+0xE..+0x1A` the sight distances.
- Attack window fields: the first u16 is not an on flag but a shot multiplier: Monkey_TryReaction checks
  it is non-zero and sets the burst count `+0x222 = D_800AEBB4[k].mult * value` (1-4 in the data); the
  second is the % chance, then min/max distance to Spike. So every light blue monkey in an area with
  window 5 can fire the laser, when Spike is 400-3500 away and the roll succeeds.
- `D_800AEBB4` (wip/_try/reacttab.py), one 8-byte entry per attack window: {u8 mult, u8 state, s16 model,
  u16 flags}. mult/state: 0 {3, 0x21}, 1 {1, 0x22}, 2 {1, 0x23}, 3 {1, 0x1B}, 4 {1, 0x1C}, 5 {1, 0x38},
  6 {1, 0x39}, 7 {3, 0x37}. model: 0 -> 5, 1 -> 7, 5 -> 6, others -1. Monkey_Draw draws
  `D_800F4630[model]` for every window whose chance (kind +0x20 + 8i) is non-zero, so a monkey visibly
  holds the gun (model 5), missile launcher (7) or window-5 weapon (6) whenever its area's kind
  record enables it. flags bit 0/1/2 select which windows func_8003738C / func_80037420 /
  func_800374B8 may try (bit 2 = 0, 1, 5: the three guns).
- `D_800AEBF8[type id]` = {1, 2, 0, 2, 3, 4, 0, 0}: one more model per type drawn by Monkey_Draw (ids 2
  and 6 share 0, ids 1 and 3 share 2). It groups like the per-type sounds, so it is not the shorts
  colour; maybe the helmet or a voice/face variant.
- Window 5 (state 0x38) is a gun, not a bomb: Monkey_StateInPlace sends states 0x21 (window 0, Mgun) and
  0x38 (window 5) to the same aim-and-fire routine `func_80033E4C(mode)`. Mode 0 fires enemy-shot type 1
  every 4 frames (bullet model 0x38, effect 0x10B, sound 100, aimed 0x7D above Spike's feet); mode 5 fires
  shot type 2 every 5 frames (no bullet model, effect 0x118, colour args 0x5A/0xFF, sound 0x4F, speed x1.8).
  So window 5 is probably the laser (wip/_try/win5.py lists every record): id 2 in most areas from stage 9,
  id 6 in Dexter's Island and later. Window 0 (Mgun) is only on ids 0 and 5. To ask the user: do the white
  (id 6?) monkeys in Dexter's Island fire lasers rather than throw bombs?
- Weapons are correlated with the shorts colour but not tied to it (user, 2026-10-15). The data agrees:
  the attack windows are per area (yellow id 2 also throws stones in some level 3/4 areas and has
  window 5 in stage 9), and the light blue laser is not in the kind record at all, so it is chosen per
  monkey. The type id itself drives the per-type sounds (`func_800356C0`/`func_80035750`).
- Per-area tuning: the same id has different speed / sight / ranges in different areas (e.g. red's
  speed +4 is 210 in Coral Cave, 350 in stage 44).

## Monkey state machine (from Monkey_Update and Monkey_StateInPlace, 2026-10-14)
- `Monkey_Update` switches on `+0x78`: states 2, 3, 8, 9, 0xA, 0xC, 0x19, 0x1A, 0x23, 0x24, 0x35, 0x39 move
  (`Monkey_StateMove` once it has noticed Spike, `+0x79 == 1`, else `Monkey_StateRoam`); states 0, 1, 0xB,
  0x16-0x18, 0x1B, 0x1C, 0x21, 0x22, 0x26-0x2B, 0x37, 0x38, 0x42 play out in place (`Monkey_StateInPlace`).
- State 1 is idle: `+0x9A` counts down, then it picks 0xD, 0x10, 0x13 or 0x3A, by the direction to Spike
  (`+0x21C`) when alerted, else at random. 0xB looks like "noticed".
- Monkey types are per area, not global: `Monkey_InitAll` points `g_MonkeyKinds` at the area's
  monkey block (`g_Game+0x8240` + 0x2A) with up to 4 kind records of 0x88 bytes; `Monkey.f_7C` picks
  one. Kind `+0` is a 16-bit type id (seen values 0, 0x40, 0xC0, 0x140) that picks e.g. sound
  0x52/0x53/0x54 (`func_800356C0`). The records are in the stage files (KKIIDDZZ.DAT, not unpacked
  yet), so questions about monkey behaviour need the per-area tables first (the user notes that
  behaviour varies a lot by monkey type).
- Attacks: each kind has 8 attack windows at kind+0x1E (`{on, ?, min, max}` distance in `+0x20C`).
  State 0x21 uses window 0 and calls `func_80033E4C(0)`, 0x38 window 5 with `func_80033E4C(5)` (both
  aim at Spike and fire with `func_80059304`, the enemy-shot spawner), 0x22 window 1 calls `func_80033DF0`
  every 5 frames, 0x1C window 4 calls `func_800343B0` 10 frames before the animation ends, 0x1B window 3
  calls `func_8003440C` 25 before, and 0x37 window 7 fires `Monkey_FireShot(3)` with sound 0x48 on frames
  3 and 7 of every 10 (`Monkey_FireShot(4)` when its count `+0x222` runs out). Question for the user:
  which monkey attacks are these (gun, rocket launcher, thrown objects, UFO laser...)?
- States 0x29-0x2B move a monkey between two linked nodes flagged 0x400 (0x2A drops in an arc onto
  the floor, then 0x2B): climbing up or jumping down?

## Sound
- File 8009BA90 looks like a sequencer/sound driver: 0x120-byte channel records at `g_SeqChannels`,
  sequence data at `D_800E1854`. `SeqDriver_ReadEvent` reads events with MIDI-style running status
  (a byte with bit 7 set is a status byte and is remembered for following events), as in
  Sony's SEQ/SEP formats. Not yet confirmed whether it plays music, sound effects or both.
- `Sound_SetVolumes(a, b)`: two volumes clamped to 0..127 (`g_SoundState + 0x10/+0xE`) pushed to
  sound channels.
- `Sound_Play(mode, id)` plays sound effect `id & 0xFFF`: 8-byte entries at `g_SoundTable`
  (`f_0` picks the VAB id from `g_SoundState[]`, `f_2`/`f_4` program and tone). mode 0 and 1
  call two different key-on routines. Unless `id` has bits above 0xFFF set, the voice is
  recorded in a free slot from `Sound_AllocSlot` (0x1C-byte records at `g_SoundSlots`) so it can
  be stopped later with `Sound_Stop(id, voice)`. Failures print `D_800A6240`/`D_800A625C`
  through the printf-like `bios_printf`.
- `Seq_AllocVoice` (8009DAB4) picks one of the 24 sequencer voices (`g_SeqVoices`, 16-bit fields):
  round-robin from the last one to the first free voice; otherwise it steals by rank (`[5]`),
  preferring voices in state `[4] == 1` (released?), never locked ones (`[0xD]`).
- `func_80087EE0`: volume of a positional sound source against the listener `D_800BF688`: full
  (0x1000) within 0x800 of it, falling linearly to 0 at the source radius (+0xA, or +0xE for
  type 0x3000 sources measured in the y/z plane instead of y/x).
- `Spu_StartTransfer` sets up an SPU transfer (SPU register block at `*D_800E1874`, DMA4 registers
  at `*D_800E1840/44/48/50`): libspu-style code linked into the game file.

## Cheat codes
- `Cheat_CheckCodes` reads newly pressed buttons (`g_Pad + 0x158 & + 0x160`) each frame and
  shifts a digit per press into `g_CheatInput` (D-pad Up 1 = bit 0x1000, Down 2 = 0x4000,
  Left 3 = 0x8000, Right 4 = 0x2000, L1 5, L2 6, R1 7, R2 8; standard PsyQ pad bits). When the last 8 presses equal one of the 5 words at `g_CheatCodes`, it plays
  sound 0xD and applies:
  0. Up Down Up Down L2 R1 R2 L1: `D_800F4350 + 0x154` (explosive ammo) = 49
  1. Left Right Left Right L1 R2 R1 L2: `D_800F4350 + 0x156` (guided ammo) = 49
  2. R2 Down L2 Up Right Down Right Left: `+0x154` = 99
  3. R1 L1 Left L2 R2 Right L2 L1: `+0x156` = 99
  4. Left Up Right Down L1 L2 R1 R2: Spike's idle timer `g_Spike + 0x148` = 0x37A
  Per the user, the game has cheats that set explosive and guided bullet capacity to 99, so
  `D_800F4350 + 0x154` is explosive ammo and `+0x156` guided ammo (confirmed by the user).
  `Pickup_Collect` confirms these are capacities: an ammo pickup adds a round only while the count
  (`g_GadgetState+0xA1/+0xA2`) is below `g_Game+0x8154/+0x8156` (`D_800F4350` = `g_Game+0x8000`). Per the user, the codes found here (the 49 variants and code 4
  at least) were never publicly documented; worth confirming in an emulator. Code 4: `+0x148` is Spike's idle timer (user: idle state). `Spike_Update` adds 1 per frame
  and starts the idle animation at 0x385 (901 frames, ~15 s); code 4 sets it to 0x37A (890), so
  Spike goes idle about 11 frames after unpausing. Another path counts it down to 0.
- Where: `Cheat_CheckCodes` is called only from state 1 of the menu state machine in
  `PauseMenu_Update` (state byte `D_800BEF74`), which `Pause_Update` runs while the game is
  paused. That menu draws the strings at `D_800B269C`: "Return", "Stage", "Best time", "Retry",
  "Target time", "Success Rate", "Total Game Overs", "Ultra time" (text is stored as
  char - 0x31, 0xFF = space). So the codes are entered on the in-stage pause screen.
- Pause screen layout (from the user): top left the stage, its name below, then the monkey
  icons (caught / not caught); top right the best time; bottom right the Specter coin count.
  Not yet tied to code. "Target time" is on the status page of the pause menu in Time Trial
  (user); "Success Rate", "Total Game Overs" and "Ultra time" are not identified yet.

## Stage flow
- `Tutorial_SetNextStage`: when the current stage `g_Game + 0x8126` is 0x5C..0x62, sets the next stage
  and mode `+0x8120`: 0x62 -> 2, 0x5C -> 6, 0x5D -> 15, 0x5E -> 0x14, 0x5F -> the remembered stage
  `D_800B38BC` (mode 0x12 if `func_800976B8` says 3, else 10), 0x60 -> 0x1E, 0x61 -> 0x35. Modes are
  10 or 8. The Time Station (user) has 3 rooms: main room (stage select, save), left room (3
  minigames), right room with 7 terminals to redo the gadget tutorials, one per gadget. Seven
  stage ids here, so 0x5C..0x62 are most likely the 7 gadget tutorials, each sending you on to
  a fixed stage when finished (probably where that gadget is first used), and 0x5F back to the
  remembered stage. Which tutorial is which: see the table under Gadgets (`Gadget_SetupStageLoadout`
  gives each tutorial its gadget). Implied stage ids: 2 Primordial Ooze, 6 Thick Jungle,
  15 Cryptic Ruins, 53 City Park.
- `Pad_Vibrate(port, strength, time)` looks like controller vibration: `Collision_UpdateMoveRumble` keeps
  a looping sound (0xAD) and pulses `Pad_Vibrate(1, 0x6E, 2)` while some flag set
  (`arg->f_C`, `arg->f_14`, or pad bits `D_800E53C0 & 0xFF00FF00`) holds in mode `0x8150 == 1`.
- `g_Pad + 0x158` and `+0x160` are pad button words; `CamFlyby_StepSegments` closes something
  (text/tutorial sequence at `D_800B8CC0`) on Start/cross/circle/square (mask 0x8E0).
- `Spike_SwapGadgetState`: swaps Spike's action state (`D_800EC23E` = `g_Spike + 0x5E`) between plain
  and gadget-holding variants (0<->1, 3<->4, 5<->7, 0x13<->0x14) depending on the gadget.

## Save data / misc
- `MemCard_BuildSaveHeader`: builds the memory-card save header at `D_800E1880` ("SC" magic, 0x11 = icon
  with 1 frame, 3 blocks, title from `D_800A3910`, palette `D_800A6AB0`, icon `D_800A6AD0`).
- `Cd_ReadCurrentFile` / `Exe_Load`: CD reads (seek with a file's position, then read its sectors).
- `Debug_DrawCpuMeter(v)`: draws a bar 4 px high at y=0xE6, `v` px wide, blue < 200, yellow < 400,
  red above: very likely a debug CPU-load meter.
- `Monkey_UpdateLod`: monkey model level of detail from distance to `g_CameraTarget` (camera?):
  < 1000, < 2000, further; swaps the model through `g_Game + 0x81A4[lod]`.
- `Zone_FindAt`: zone lookup by position. It has a bug: for the y axis it negates the x distance.
- **Save percentage** (`Save_GetCompletion`, matched 2026-10-14): the score is the sum of
  - the monkeys caught over all stages (`Save_SumStageMonkeys`, one point each);
  - for every stage except 0, 7, 14, 18, 19 and 23 (hub/special stages): +15 if the stage state
    (+0x28[i]) is 1, +25 if it is 2;
  - time attack: the stage's best time (+0x690[i]) under each threshold of the record table at
    0x80102400 gives +8 / +7 / +5 (the three medal times);
  - +15 if +0x46 is 2, +15 each for save flags 0x10 and 0x1000 (+0x668);
  - +2 per entry in the 2-byte list at +0x68 until 0xFF (probably the Specter coins);
  - +8 each when the three bytes at +0x670, +0x671 and +0x674 reach 5 (the three minigames?).
  To be confirmed with the user (which stages are 0/7/14/18/19/23, what +0x46 and the flags are).

## Minigames (from the user)
Three minigames outside the core game: a twin-stick UFO shooter, a boxing game, and the "Ski Kids"
racing game. On disc: `MINIGAME/MINI1`, `MINI2`, `MINI3` (not split or decompiled yet).

## 2026-10-13 (later)
- Spike health is `g_Spike+0xE8` (s16): `Spike_Init` sets 5, `Spike_Heal` caps at 5 (cookies).
- `Gadget_Select(g, prev)` (func_8007AC64): selecting the Slingback while it is already selected
  cycles the ammo type `g_GadgetState+0xA0` (regular -> explosive -> guided, sound 3). Current and
  previous gadget are stored at `g_Spike+0xF2/+0xF3`; a change plays sound 0x24.
- View buttons (`Camera_HandleViewButtons`): L2 enters first-person look (D_800E68D0+0x32), or with
  the Slingback toggles aiming (+0x46); L1 recentres the camera / leaves aiming; L1 or L2 leaves look.
  Look is refused (sound 0x30, HUD icon blink) in game modes 0x13/0x24 and sub-modes 2-3.
- `Radar_GetSignal` (still asm): Monkey Radar strength 0..32 from uncaught monkeys in a ~30 degree
  cone ahead; with none left in the area it points at exits (stage zones) leading to areas that
  still have monkeys.
- `Spike_TryGrabLedge`: falling Spike grabs a ledge 0x81..0xFF above, one step ahead (state 0xE).
- Water Net shot (`WaterNet_Shoot` / `WaterNet_UpdateShot`): R3, grows and spins, catch sphere
  (collision kind 8), 0x15 frames.
- `PushBlock_Update`: pushable blocks (Spike state kind 0x70 = pushing), scraping sounds 0xAE in
  stage 0xB, 0xB1 in stages 0xF / 0x65.
- `CamFlyby_Update`: scripted camera paths (segments of D_800E68D0+0x60) with a fade at the end.
- Item drops (`Pickup_Drop`, still asm): the drop is picked from a table row D_800B28A2[table*25]
  indexed by Spike's current health (g_Spike+0xE8), five cumulative weights out of 100 for the
  five drop kinds D_800B28B4[0..4]; kind 3 (energy chip) drops 2-3 at once, kinds 7 and 2 are
  resolved further (func_8008373C, func_80083790). In races everything becomes 2 chips.

## Text encoding (Boot_LoadingScreen)
The game's own font uses one byte per glyph: e.g. "Now Loading..." is
`1D 3E 46 FF 1B 3E 30 33 38 3D 36 AC AC AC` (N=1D, o=3E, w=46, space=FF, L=1B, a=30, d=33,
i=38, n=3D, g=36, '.'=AC). Lowercase starts at 0x30 ('a'), uppercase 'A' is 0x10.
At boot, Boot_LoadingScreen loads file 6 and then files 1, 7, 12 while this text blinks.

## CD request queue
Cd requests are queued in a 16-entry ring (D_800E3890+0x78, 0x1C bytes each, head f_74, tail
f_76) by Cd_QueueCommand and issued by Cd_IssueRequest; Cd_PollStatus restarts looping XA music
(D_800A8530 flag 2) once the play position passes the track length.

## Monkey path nodes (D_800B4D00, 0x18 bytes)
- f_0 flags seen so far: 0x4 wait here (state 0x42, time f_10), 0x8 lookout (alert monkeys with a
  noticed target go to state 0x26/0x16; others wait while f_10 < their distance), 0x20 sets monkey
  flag 0x4000000, 0x400 special action (Node_GetJointRef, state 0x29), 0x800/0x20000/0x40000 send link
  events 0/1/2 to object f_10, 0x1000 jump (state 0x27), 0x4000 Object_SetFlagCF(f_10), 0x8000
  stop when closer than 1500, 0x10000 "end of route" (route look-ahead stops; object f_10/100
  checked with func_80052C4C), 0x80000 calm monkeys do func_80035918 (Monkey_NodeEvents).
- f_B is the link count, Node_GetLink(n, i) the i-th neighbour; f_14[kind] is a per-monkey-type
  attraction value used by Monkey_PickGoalLink to pick where a monkey heads.
- Monkey +0xF2..+0xFC is a 6-entry history of visited nodes (newest first), +0xEC the node it came
  from, +0x176[] the per-link scores from Monkey_ScoreLinks, +0x1DA[] blocked links, +0x210 its
  distance to Spike (Monkey_SelectActive keeps the 4 nearest in g_ActiveMonkeys).

## Objects
- Object_UpdateAll walks the 0xE4-byte g_Objects slots; type handlers are D_800AF350[type];
  objects 0x800 below their floor are destroyed with a poof (Object_Destroy).
- Bouncy_Update (func_8009398C): bouncy object; landing on it bounces Spike with a stage sound
  (0xB5 stage 7, 0xB3 stages 0x51/0x52/0x54, 0xB6 0x32, 0xAE 0x47), touching its side knocks him
  back and it wobbles (0xBB in stage 0x19). Question for the user: what is it in each stage?
- Platform_MoveRiders / Platform_RotatePoint carry Spike and the RC car on moving / rotating
  platforms; type 0x800 platforms hand Spike to an overlay routine (func_8013FC18).
- Camera point objects (CamPoint_Update): orbit, drift, follow-Spike and fixed-look types.
- Platform_UpdateOrbit: platforms circling a centre (own start or object +0x22) in the plane
  chosen by flags & 0xF00; kind 5 bobs, kind 4 offsets the model, kind 3 turns the model.
- Object_SpawnFromRecord sets an object up from a stage placement record and records the slot
  of placement id k in D_800E77B0.
- Puff particles: 8 slots at D_800BB840 (Puff_Spawn / Puff_UpdateAll / Puff_ClearAll), each a
  jittered 8-point strip drawn on odd frames for 7 frames.

## Collision
- Coll_PushBox / Coll_PushWedge / Coll_PushDiagonalWall / Coll_PushCurvedCorner /
  Coll_PushHalfCylinder push Spike (D_800B20B4) out of the shape kinds; Coll_PushWedge is a box cut
  along a 45-degree diagonal (sign table D_800A5D84).
- func_80078C9C (still asm) is the "what is at this point" query: 8 probe tiles (D_800B20B0,
  filled by func_8007304C), then every object, then the floor height; type handlers in the
  tables D_800B20E0 (tiles) and D_800B2108 (objects).
- Contact list D_800BEEA0 (16 entries): Contact_IsNew / Contact_Add / Contact_Expire /
  Contact_ClearSeen fire touch events once per contact.

## Stage start
- Stage_Begin(lvl): world/stage ids, subsystem resets, and for a stage's first area the monkey
  count and list (stage table 0x80102400, 16 bytes per stage: monkeys +0, +2, +3, +4) plus the
  per-area caught flags D_800DFE00 (mode 0x13 clears them, except stages 0x1B/0x1C copy them from
  D_800DFF20). Stage 0x21 gets one monkey; 0x1F/0x20/0x22 and world 3 none.

## Input
- Button-press history at g_Pad+0xA4 (40 entries, index +0x170): Pad_RecentR2/L1/R1/Triangle/
  Circle/Cross check the last 10 entries; Spike_AnimEndOnTriangle/Circle check the latest entry
  when his animation has just ended.

## Boot
- Boot_LoadingScreen shows "Now Loading..." while files 1, 7 and 12 stream; Cd_InitFileTable reads
  the KKIIDDZZ.HED file table and the XA music start sectors.

## Model draw scratchpad (0x1F800000)

Model draw functions in 80015F70 first light the model's vertex colours with the GTE and
write them to 0x1F800000 (one word per colour), then call the primitive walker
(Model_DrawPrims / Model_DrawLit) that reads them back:
- func_80017CD4, func_80017D94, func_80017E5C, func_80051AA4: `cc` (colour * light colour)
  per colour; func_80051AA4 can OR extra bits into each colour (used by Object_Draw).
- func_80017EFC (vertex-colour animation, header flag 0x100000): blends frame k>>12 to the
  next frame with `dpcs`, factor k & 0xFFF, then restores the far colour from D_800EBFA0+0x1C.
- Model_DrawLit switches on each primitive's code byte (& 0xFC, 0x20..0x3C = F3, FT3, F4,
  FT4, G3, GT3, G4, GT4), and each per-type function returns the next primitive.
- Scratch 0x3F4 (u8) = draw mode (2, 6, 7, or a caller value); 0x3C0/0x3C2 = D_800EBFA0
  +0x24/+0x28; 0x3C4 = an extra value (func_80017D94 arg 3), 0x3C6 = 0.
- func_8007F8F4 is a 9-tap colour blur on a 382-pixel 15-bit image row (taps at D_800B2704,
  {offset, shift}, sum >> 4) via the GTE IRGB/ORGB registers, written two rows down.

## HUD and 2D drawing (2026-10-16)

- addPrim is an inline-asm macro in the original (`lwl t1,2(ot); sll t2,p,8; swl t2,2(ot); swl t1,2(p)`).
  common.h has the forms that match: ADD_PRIM_ASM (compiler-chosen temps), ADD_PRIM_ASM2 (temps in the
  other operand order), ADD_PRIM_ASM_DW (do/while(0) wrapper, Menu_DrawCaps) and ADD_PRIM_ASM_A01
  (a1/a0 hardcoded, Hud_DrawLivesIcon). Which one matches differs per call site. Some functions keep
  the OT in a register (`lwl 2(ot)`) and p as a memory operand; wip/_try/apv.py and apcombo.py try them.
- g_Game display part (G_DRAW in common.h): +4 next free prim, +8 current OT pointer, +0xC buffer index,
  +0x10 two display buffers of 0x4078 bytes: DRAWENV (0x5C) + DISPENV (0x14), world OT[0x1000]
  (depth sorted, ot[0xFFF] = back), HUD OT[2]. Screen_DrawAfterimage reads DRAWENV clip.y (+2) and
  flips bit 0x100 to sample the previous frame.
- HUD (Hud_Draw): sky/ground tiles split at the horizon (y = 120 - camera m[2][1]/16) in the stage fog
  colours (g_Game+0x8194 env +0x1C/+0x18), then by D_800F4DB0+0x20 flags: 0x10 health cookies
  (Hud_DrawHealth, g_Spike+0xE8), 0x20 gadget slots (Hud_DrawGadgets), 8 lives (Hud_DrawLives), 2 status
  icons, 4/1 two more parts. Races add a lap icon + time (g_Game+0x8140).
- Gadget HUD: four face-button slots at D_800B2234 with icon uv/clut D_800B2254[gadget]; a 48x48 cursor
  eases to the slot of the current gadget (g_Spike+0xF2). Slingback (gadget 3) adds the ammo panel
  (Hud_DrawSlingAmmo: rows normal / +0xA1 / +0xA2 counts, selected +0xA0; slides in from x 400 to 300).
- Underwater (Spike_IsUnderwater: states 0x46, 0x47, 0x49, 0x4A, 0x4C) the gadget HUD is replaced by Hud_DrawAirMeter: a ring of 64
  segments, one per 15 frames of g_AirTimer (600 = 10 s, reset by Spike_ResetAir); red < 150,
  yellow < 300, else blue. (User: an air meter shows when he is underwater.)
- Monkey counter (Hud_DrawMonkeyHeads): one head per monkey of the stage (g_Game+0x8188), caught ones
  (+0x8166) in the caught palette, blinking 6 of every 10 frames. The pause screen
  (PauseMenu_DrawStageInfo) shows them in a grid of 8, dark when not available (+0x8188 present,
  +0x8186 total).
- Time attack: Hud_DrawTime draws frames as m'ss"cc (hundredths = frames * 101 / 60), Stage_GetTargetTimes
  gives 3 target times per stage, Hud_DrawTimeMedal picks CLUT row 0x1F5/0x1F4/0x1F3 by how many are beaten.
- Monkey Radar live view (user: "LIVE" over a live camera that follows the monkey) shows Radar_DrawMonkeyCard: name (kind +0x5E), fact line (+0x6A),
  "Monkey Level n" from the thousands digit of kind +0x1C, and Speed / Attack / Alert from its hundreds / tens / ones digits as 5-pip rows. The Monkey Book shows the same info with a still picture (plus level name and world above), from other code.
- Options menu (OptionsMenu_Update): vibration g_Game+0x8138, stereo +0x813A (Sound_SetStereo), two volume
  sliders D_800BEF90 +8 / +4 (0..127, steps of 8), reset row.
- Depth fog textures: Tex_MakeFogLevels builds 7 copies of a texture blended k/8 towards the fog colour
  in VRAM (0x240.., 0x100..); Tex_DrawFogLevels copies them back with DR_MOVE at increasing OT depths.
- Matching notes for draw code: many functions store the advanced prim pointer through the separate
  symbol `D_800EC354` (g_Game+4) rather than via g_Game (`lui %hi(D_800EC354)` at the end), so declare
  `extern u8 *D_800EC354` and assign it. Some use the plain libgpu C addPrim (24-bit tag bitfields,
  `and`/`or` with 0xFFFFFF/0xFF000000) instead of the asm one. Depth comes from PsyQ's `gte_stszotz`
  (mfc2 into hardcoded $12, nop, sra 2, sw). An unsigned divide whose magic has no post-shift after a
  `sll 11; srl 11` is a divide by d << 11 (the billboards func_80069920: h * 23930880 / 92160).
- Centre-screen sign (CenterSign_Draw, g_CenterSign): time-limit seconds (CenterSign_ShowDigit from
  TimeLimit_Update; n == 1 is the wide 160px sign at zero) and the 62x62 sign for the Specter coin (pickup kind 4, user);
  4 shrinking afterimages, then state 5 zooms out and fades for 8 frames.
- Super Hoop sparkles (SuperHoop_DrawSparkles, gadget 4; user: particles appear when the hoop is activated): 40 particles respawn on a ring around Spike
  while gadget state +4 is 1 (Hoop_Update state 1 = activated, spinning) (radius +8 / 6 + 90); flags word = 5-bit life, 3-bit size, written with
  hand-written mask macros (timer read through a byte, size through the halfword).
- Time Net (gadget 1, TimeNet_Update from the per-gadget switch in Spike_Draw): the grip point's
  frame-to-frame motion (x64, clamped) is stored at g_GadgetState+0x68.. and bent into the handle
  matrix and, halved, into the net matrix, so the net lags and swings behind Spike's hand (user: the net swings in a vertical arc in his hands).
- Fx_DrawGlowBeam: additive glow beam between two projected points (6 POLY_G4), width scaled by the
  GTE projection distance (cfc2 $26) over depth; used by a gadget model (8009A800) and func_800687D8.

## Open questions for the user (2026-10-14)
- Stage numbers: which stages are 0, 7, 14, 18, 19 and 23? `Save_GetCompletion` skips them for the
  per-stage +15/+25. Which stages are 0x38, 0x39, 0x45..0x48, 0x4D, 0x4E, 0x50 and 0x53 (the
  `Stage_PairInSharedSet` list that changes the area file / keeps the sound banks)?
- Save percentage: what is the save byte +0x46 == 2, flags 0x10 and 0x1000 at +0x668, the 2-byte list
  at +0x68 (+2 each; Specter coins?) and the three bytes at +0x670/+0x671/+0x674 that give +8 at 5?
- Monkey helmet light (`Monkey_UpdateHelmetLight`): levels 0 / 0x1C0 / 0x380 give light kinds 0, 1, 2 = blue (calm),
  yellow (just lost sight of Spike, before going calm) and red (alerted), per the user.
- Pickups (`Pickup_DrawAll`): kinds 1-7 use models 0xE, 0x11, 0xF, 0xD, 0x10, 0x12, 0x13. Kinds (Pickup_Collect, confirmed by the user):
  1 cookie, 2 extra life, 3 energy chip, 4 Specter coin, 5 big energy chip, 6 explosive and 7 guided Slingback ammo. `g_SpecterCoinTimer` counts down while
  model 0xD (kind 4 = Specter coin, user) spins down onto Spike with effect 0x104 every 8 frames: the coin collect animation.
- Drops (`Pickup_Drop`, `func_80083790`): a kind-2 drop becomes kind 5 when a 1..25 roll is below
  (n - 1) * 10 with n = g_Game+0x813C clamped to 1..10 (0x813C is 5 after `Game_NewGameReset`: the
  lives counter?), and while the cooldown `D_800B28B0` runs. Which items are kinds 2 and 5?
- Pause menu (`PauseMenu_DrawItemModel`): item models D_800F4CA0[0..3]; items 0/1/2 map to 2/3/1 and
  `func_80082030` greys some out per stage (stage 0x13, 0x24, 0x5C-0x62 for item 0).
- Earlier: the four-armed rotor (kinds 0x37..0x3A), stages with bumpers (0x15, 0x54) and push-blocks,
  (answered: Spike climbs trees, e.g. in level 1, states 0x38..0x3C), and the pad layout for jump/crouch (scratchpad input slots
  0x54/0x58/0x5C/0x5E/0x64/0x66/0x70/0x72/0x74/0x7C).

- Base-address reload after a join (lui/addiu repeated for the same global): GCC's
  cse-follow-jumps reuses the first base. Accessing the second use through a second `asm("sym")`
  alias of the same array forces the reload (Collision_GetId 800721B4). An `(s16)a` cast at each
  use, instead of a sign-extended local, put the `lui` ahead of the sign extension.

- Scratch-pad (0x1F800000) s16 loads, GCC 2.8: `S->field` through a constant struct pointer shares
  one `lui` base but loads s16 as `lhu; sll 16; sra 16`; a cast form like `((s16 *)S->arr)[k]`
  gives a plain `lh` but re-materialises `lui` after an `asm volatile`. The model prim builders
  (Model_AddF3 family) need both, a shared t1 base and plain `lh` for the sxy loads, with
  `lhu/sll/sra` only for the `(s16)` index truncations. Unsolved; the permuter cannot parse the
  asm operand expressions in these drafts.

- `return 0` placement: when every exit should land on a shared `move v0,zero` before the
  register restores, write the guard as an early `if (!x) return 0;` instead of wrapping the body
  in `if (x) { ... } return 0;` (Link_UpdateArea 8005B68C).

- A third addPrim form: `lwl $4, 2(%0); sll $3, p, 8; swl $3, 2(%0); swl $4, 2(p)`, with hard
  a0/v1 temps and the OT entry address as an "r" operand (`ADD_PRIM_A0V1` in 8001F3A0_draw_fx.c,
  Shadow_Draw). The "r" operand also fixes the `addu ot, z*4` operand order and keeps the
  OT address out of the z register.
- Generalised: many draw functions' addPrim uses fixed temp registers, which differ per function
  (v1/v0, a0/v1, a1/a0, a0/v0, ...). `ADD_PRIM_R(ot, p, "$3", "$2")` in common.h takes them as
  string literals (lwl temp first, sll temp second) and the OT entry address as a register
  operand. `wip/_try/hardap.py FUNC DRAFT` reads each site's registers from the original asm and
  rewrites the draft with them; that matched Hud_DrawTimerClock (8005FCA4).
- Don't add an `asm("g_Game")` alias to a function that also reaches g_Game through G_DRAW: the
  two symbol names cost an extra `lui` (ScreenWipe_DrawSpiral grew 8 bytes). Use the file's own
  g_Game declaration when it already has the field.
- GCC 2.x MEM_IN_STRUCT_P aliasing: a store through a struct pointer (p->tpage) is assumed not to
  alias a plain scalar global, so the scheduler hoists the global's load above the store. When the
  original keeps the store first (Debug_DrawBar), declare the global as a struct member
  (`extern struct { u32 f; } D_800EC250;` and read `.f`) so both accesses are in-struct.
- `bgez x, 1f; nop; negu x, x` (unfilled delay slot) is GCC's built-in `abs()` (abssi2 template),
  not `if (x < 0) x = -x` (Model_CalcEnvMapUVs64).
- Prologue saving the second argument's s-register first (`sw s2; move s2,a1; sw s1; move s1,a0`)
  when ours saves them in argument order: copy the first argument into a local at the top
  (`T *ff = f;`) and use only the copy (Spike_CreateModel).
- A delay-slot `li` copy of a constant used to store a field (`move v1,a1; sh v1,..`): store through
  a second variable (`t = 40; f = t; x = t;`), func_8009529C.
- C-side addPrim (`and` with 0xFFFFFF / 0xFF000000 instead of the lwl/swl macro) is PsyQ's own
  bitfield macro: `((P_TAG *)p)->addr = ((P_TAG *)ot)->addr; ((P_TAG *)ot)->addr = (u32)p;` with
  `struct { unsigned addr : 24; unsigned len : 8; }`. The bitfield form keeps 0xFFFFFF in a saved
  register across a loop, as the original does (EnemyShot_DrawAll draft).
- Two locals in different branches at the same stack offset: one variable reused (a VECTOR in one
  branch, cast to SVECTOR * in the other). A short array or 2-short struct takes an 8-byte slot.
- Varargs (DebugFont_Printf): the original stores a0-a3 at 0..0xC(sp) on entry and re-reads the
  format pointer from its stack slot each use. That is old-style `ap = (char *)&fmt + 4` (address
  of the last fixed argument), not `__builtin_next_arg`; `va_arg` is `*(T *)((ap += 4) - 4)`.
  Characters loaded with `lb` mean `s8` (plain `char` is unsigned here). A `%c` whose word is
  passed on without `sll/sra` is `PutChar(va_arg(ap, int) - 0x20)`, no char cast. Case bodies
  come out in source order, so put them in the order of the original's code (d, x, s, c).
- A function defined with a different prototype than the one its file already declares (here a
  `(void)` declaration used by a forwarding caller): define it under another C name with
  `asm("RealName")` on its declaration; `wip/_try/ins.py FUNC DRAFT ASMNAME` inserts it.
- A callee that returns `s16` makes the caller sign-extend the result; if the original doesn't,
  the callee returns `s32` (MinigameMenu_Update).
- `%hi(sym)` kept in its own saved register next to the full address (MinigameMenu_Main's frame
  counter): the same symbol is used both as a scalar (`g_Game` frame, `%lo(g_Game)(s2)`) and
  through its address. Declare it once as a scalar and reach the struct through a cast.
- func_8004F6E8 (floor cell lookup): `if (A || (dd = ..., B) || C) return 0;` puts the shared
  `return 0` inline after the last test, which all earlier tests branch to. A while loop that the
  original enters at its bottom test, reloading globals each pass, is a goto loop (goto check;
  loop: ...; check: if (c) goto loop;). Store-before-load ordering again needed the globals
  declared as struct members.
- RC car remote (user): a stiff antenna with 6 lines shooting out of its tip and a continuous line of
  lightning bolts from the antenna to the car. Gadget_UpdateSoftStrands (6 lagging tip points around
  their mean) may compute those lines; no caller was found, but the visible dust code has none either.
- Foot smoke (user): dust puffs appear under Spike with every gadget except the Monkey Radar and the
  RC car (both take over control while Spike stands still), so `Spike_UpdateFootEffects` runs with his
  normal movement; not a Magic Punch bug.
- Music map (start): XA streamed tracks 4..57 (D_800A8530, from archive files 0x1C0-0x1C5) are played
  only by Cd_PlayXaTrack: stage start plays one of tracks 4-8 at random (frame % 5 + 4; probably intro
  jingles or voice clips, not the stage music); Game_SetMode 19 (mode 0x13) plays track 0x39, the last
  one; a fall in game mode 0x20 plays 0xD or 0xF at random; the playing track loops if its flag bit 2
  is set. Stage music itself is probably sequenced (the stage sound pack in Sound_LoadBanks mode 2).
- Register swaps between temporaries often mean the original reused one variable for unrelated
  values: Camera_FollowRcCar matched once `a` held the x^2 term before the clamp and the clamp
  temp was written as `d` (the distance, dead by then). The permuter found the first half.
- Checked: the scratch-pad `lh` with a shared `lui` base seen in Model_AddF3 comes from no available
  compiler (2.8.1-psx, 2.8.1, 2.7.2-psx, 2.7.2-cdk, 2.91.66 all give either `lhu; sll; sra` with a
  shared base or `lh` with a fresh `lui`), so the difference is in the source, not the compiler.
- Radar_DrawMonkeyCard: reading the frame counter as a struct member (`((struct {u32 frame;} *)&g_Game)->frame`)
  instead of `*(u32 *)&g_Game` kept it after the sprite stores and fixed the size (the
  MEM_IN_STRUCT aliasing rule again).
- Pickup_Drop: computing the table pointer in the `for` initialiser
  (`for (i = 0, t = ...; i < 5; ...)`) fixed the size and most of the order (the original sets i
  and the cum[] address before the pointer).
- splat's "Handwritten function" flag only means the function has GTE instructions (`mfc2`, `cfc2`
  and so on). Most flagged functions have normal GCC prologues and match from C with small GTE asm
  macros (Debug_DrawWorldQuad, Slingback_Update, Model_DrawOnScreen). Model_Add* and Model_Project*
  look like real hand-written asm.
- When the original reloads a stack or scratch-pad value after primitive stores (z, sxy[]), but
  ours keeps it in a register or moves it past them, the original wrote the primitive through a
  plain `u32 *` (`p[2] = sxy[0]`), not a struct pointer. This is the MEM_IN_STRUCT aliasing rule
  again (Debug_DrawWorldQuad).
- `p++; G_DRAW.prim = (u8 *)p;` and `G_DRAW.prim = (u8 *)(p + 1);` allocate differently
  (Debug_DrawWorldQuad matched only with the first).
- GTE register reads (Slingback_Update): reusing one `s32` temp for IR1 and IR3 matched. The second
  read kills the first value, so later reads of that field come from memory, and the IR3 field
  still uses the register sign-extended. Separate `s16` temps keep both in registers.
- A clobbered `a3` before a call (here loaded with a value that is then stored) means the callee
  takes three arguments. Model_DrawPrims takes (ot, prims, verts).
- A copy loop that reloads its count from the model header every pass, but walks the source with
  one pointer, was `src = mdl->hdr->colors; ... scratch[i] = src[i]` (Model_DrawOnScreen).
- `sll 11; srl 11; multu 0x5B05B33; mfhi` is GCC's unsigned divide by 0x16800 (45 << 11): the
  pre-shift strips the 11 trailing zeros. func_80069920's sprite height is
  `sy * 0x148 * 0x11D00 / 0x16800` (0x148 times 19/24).
- decomp-permuter's C parser rejects arithmetic inside asm operands (`"r"(p + 0xA28)`): assign it
  to a separate pointer variable first. Reusing an existing variable changes the allocation.
- Order of the colour stores into a primitive can matter even when every store is independent
  (Slingback_Update matched once c0 came first; the permuter found it).
- Model_ProjectVerts/Alt, Model_DrawLit are compiled C too (flagged only for GTE ops). The vertex
  loop matched with the PsyQ-style register macros (`lw $12..$14; ctc2` for the matrix) and "m"
  operands for the z loads (`"m"(v[0].vz)`). Pointers that GCC strength-reduces into a second
  register offset from the first (here +40, in Tip_DrawAll +6) went away when the loop indexed
  the array (`v = &vs[i]` inside the loop, `&dst[i]`) instead of stepping a pointer.
- check_c.py now passes `-z` to objdump: without it, runs of zero words (nops) are shown as `...`
  and dropped from the diff, which hides missing or extra nops.
- A store to a fixed scratch-pad address that the original keeps before later loads of a model
  header was written through a struct (`((Scr *)0x1F800000)->mode = 7`), not `*(u8 *)0x1F8003F4`
  (Model_DrawLit; MEM_IN_STRUCT again).
- Branch layouts with the small-case test first (`slti 2; bnez; li 2; beq`) are `switch`
  statements (Tip_DrawAll box kinds and states); if/else chains put the blocks in another order.
- A value read through a second declaration of the same symbol (`extern ... g_GameT asm("g_Game")`)
  is not CSE'd with reads through the first, so the address is rebuilt (Hud_Draw's timer).
- check_c only compares .text, so a switch can "MATCH" with a wrong jump table. Always confirm the
  full build: case values must be listed exactly as the table has them. Spike_Draw's 10-entry
  gadget table needed `case 8:` on the default (so the default label is a table target and
  g_CurrentGadget is reloaded there) and `case 9: break;` (entry points at the join, not the
  default); func_8008FC30 needed `case 7:` placed before case 0x1B so 0x1B falls into its store.
- Stack temps that the original shares between two branches (same sp offsets) came from block
  initialisers (`V s = { 0x1000, expr, 0x1000 };`): GCC builds them in a reused temp slot with
  memset + stores and then copies them. memset is the BIOS A0:2A stub at 0x800A3740.
- One register-pinned local (`register u32 y asm("$4");`) was the only way to match
  func_800687D8's a0 choice for a copied coordinate.
