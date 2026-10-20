"""Write ovl/<file>.yaml (splat config) and ovl/overlays.sha1 for every code overlay in iso/ovl/.

Each overlay is .text, then .rodata (switch jump tables), then .data, padded with zeros to whole
sectors. Text ends after the last `jr ra` and its delay slot; rodata runs to the last jump table
entry after it; everything after is data. A few overlays have more parts (PARTS): further C
programs each with their own data, hand-written asm after the data, or stale bytes from an older
build left in the sector padding (nothing refers to them; kept as a binary blob). Each part is its
own splat segment so the linker keeps the file order. Existing yamls are kept unless --force.
Usage: python3 tools/gen_ovl_yaml.py [--force] [file ...]
"""
import hashlib, os, struct, sys

MODE_ADDR, WORLD_ADDR = 0x80136000, 0x8013D000
WORLD = range(396, 427)
BASE = {389: 0x80146000}  # loaded by another overlay, not the mode table; found from its own calls
# file names (src/ovl/<file>_<name>.c): the level or game mode, from docs/findings.md
NAMES = {
    384: 'fmv',
    386: 'title_menu',
    387: 'sound_test',
    388: 'stage_demo',
    393: 'stage_select',
    427: 'minigame_menu',
    428: 'str_player',
    396: 'primordial_ooze',
    397: 'molten_lava',
    398: 'thick_jungle',
    399: 'dark_ruins',
    400: 'cryptic_relics',
    401: 'crabby_beach',
    402: 'coral_cave',
    403: 'snowy_mammoth',
    404: 'frosty_retreat',
    405: 'hot_springs',
    406: 'sushi_temple',
    407: 'wabi_sabi_wall',
    408: 'crumbling_castle',
    409: 'dexters_island',
    410: 'city_park',
    411: 'specters_factory1',
    412: 'specters_factory2',
    413: 'tv_tower1',
    414: 'tv_tower2',
    415: 'monkey_madness_a',
    416: 'monkey_madness_b',
    417: 'monkey_madness_c',
    418: 'monkey_madness_d',
    419: 'monkey_madness_e',
    420: 'monkey_madness_f',
    421: 'monkey_madness_f6',
    422: 'monkey_madness_f9',
    423: 'monkey_madness_f4',
    424: 'peak_point_matrix',
    425: 'races',
    426: 'time_station',
}
PARTS = {
    385: [(0, 'c'), (0x1280, 'asm')],  # + CPU debug-register (breakpoint) setup
    390: [(0, 'c'), (0x5400, 'c'), (0x65E0, 'c'), (0x9630, 'c'), (0xF280, 'asm')],  # + exception handler
    422: [(0, 'c'), (0x8660, 'bin')],
    424: [(0, 'c'), (0x5B40, 'bin')],
}

TEMPLATE = """name: '{n}'
sha1: {sha1}
options:
  basename: '{n}'
  target_path: iso/ovl/{n}.bin
  elf_path: build/ovl/{n}.elf
  base_path: ..
  platform: psx
  compiler: PSYQ
  asm_path: asm/ovl/{n}
  src_path: src/ovl
  build_path: build
  ld_script_path: ovl/{n}.ld
  find_file_boundaries: True
  subalign: null
  ld_align_section_vram_end: False
  ld_align_segment_vram_end: False
  o_as_suffix: True
  use_legacy_include_asm: False
  section_order: [".text", ".rodata", ".data", ".bss"]
  auto_link_sections: [".data", ".rodata", ".bss"]
  symbol_addrs_path:
    - build/scus_syms.txt
    - ovl/{n}.sym.txt
  undefined_funcs_auto_path: ovl/{n}.undef_funcs.txt
  undefined_syms_auto_path: ovl/{n}.undef_syms.txt
  extensions_path: tools/splat_ext
  asset_path: asm/ovl/{n}/assets
  string_encoding: ASCII
  data_string_encoding: ASCII
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2
segments:
{segs}  - [0x{size:X}]
"""
NL = '\n'


def layout(w, vram, lo, hi):
    """(text_end, rodata_end or None) of the part of w from offset lo to hi. Rodata ends after the
    last jump table entry: a pointer into the middle of a function (data tables point at starts)."""
    is_jr = lambda x: x in (0x03E00008, 0x03400008)  # jr ra, jr k0
    text_end = (max(i for i in range(lo // 4, hi // 4) if is_jr(w[i])) + 2) * 4
    starts = {vram + lo}
    for i in range(lo // 4, text_end // 4):
        if is_jr(w[i]):
            k = i + 2
            while k < text_end // 4 and w[k] == 0:
                k += 1
            starts.add(vram + k * 4)
        if w[i] >> 26 == 3:
            starts.add(((w[i] & 0x3FFFFFF) << 2) | 0x80000000)
    is_case = lambda x: vram + lo <= x < vram + text_end and x not in starts
    ro_end = None
    for j in range(text_end // 4, hi // 4):
        if is_case(w[j]):
            ro_end = (j + 1) * 4
    if ro_end is not None and ro_end % 8 and w[ro_end // 4] == 0:
        ro_end += 4  # the table's pad word
    return text_end, ro_end


def segments(n, b, vram):
    w = struct.unpack(f'<{len(b) // 4}I', b)
    parts = PARTS.get(n, [(0, 'c')])
    out = []
    for k, (lo, kind) in enumerate(parts):
        hi = parts[k + 1][0] if k + 1 < len(parts) else len(b)
        name = (str(n) if k == 0 else f'{n}{"abcdefgh"[k]}') + (f'_{NAMES[n]}' if n in NAMES else '')
        if kind == 'bin':
            out.append(f'  - [0x{lo:X}, bin, {name}]')
            continue
        out += [f'  - name: ovl{name}', '    type: code', f'    start: 0x{lo:X}', f'    vram: 0x{vram + lo:08X}',
                '    subsegments:', f'      - [0x{lo:X}, {kind}, {name}]']
        text_end, ro_end = layout(w, vram, lo, hi)
        if ro_end:
            # a C file's .rodata is 16-aligned; the zeros before it stay with the text
            ro_start = (text_end + 15) & ~15
            if any(w[text_end // 4:ro_start // 4]):
                ro_start = text_end
            out.append(f'      - [0x{ro_start:X}, .rodata, {name}]')
        if (ro_end or text_end) < hi:
            out.append(f'      - [0x{ro_end or text_end:X}, data, {name}]')
    return NL.join(out) + NL


def main(args):
    force = '--force' in args
    files = [int(a) for a in args if a != '--force'] or sorted(int(f[:-4]) for f in os.listdir('iso/ovl'))
    for n in files:
        b = open(f'iso/ovl/{n}.bin', 'rb').read()
        vram = BASE.get(n, WORLD_ADDR if n in WORLD else MODE_ADDR)
        y = f'ovl/{n}.yaml'
        if force or not os.path.exists(y):
            open(y, 'w', newline='').write(TEMPLATE.format(n=n, sha1=hashlib.sha1(b).hexdigest(),
                                                          segs=segments(n, b, vram), size=len(b)))
        if not os.path.exists(f'ovl/{n}.sym.txt'):
            open(f'ovl/{n}.sym.txt', 'w').close()
    with open('ovl/overlays.sha1', 'w', newline='') as f:
        for y in sorted(os.listdir('ovl')):
            if y.endswith('.yaml'):
                n = y[:-5]
                f.write(f"{hashlib.sha1(open(f'iso/ovl/{n}.bin', 'rb').read()).hexdigest()}  build/ovl/{n}.bin{NL}")


if __name__ == '__main__':
    main(sys.argv[1:])
