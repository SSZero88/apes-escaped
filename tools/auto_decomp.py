"""Automatic first-pass decompiler (run inside the build container).

For every game function still in INCLUDE_ASM form:
  1. draft C with m2c (--valid-syntax, so it always compiles)
  2. compile the draft alone with the original-era compiler
  3. compare machine code against the original exe (relocated fields masked)
Matching drafts are written into src/ in place of their INCLUDE_ASM line.
The full build + sha1 check (make) is the final arbiter.

Usage: python3 tools/auto_decomp.py [--max-size 0x400] [--compiler 2.8.1-psx] [--dry-run] [--only func,...]
"""
import argparse, glob, json, multiprocessing, os, re, subprocess, sys, tempfile
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

VRAM, OFF = 0x80010000, 0x800
ORIG = open('iso/SCUS_944.23', 'rb').read()
SKIP_RE = re.compile(r'\b(mtc2|mfc2|ctc2|cfc2|lwc2|swc2)\b|handwritten|\bsyscall\b')
INC_RE = re.compile(r'INCLUDE_ASM\("([^"]+)", (\w+)\);\n')
DECL_NAME_RE = re.compile(r'(\w+)\s*(\(|\[|;|=)')


def sh(cmd, inp=None):
    return subprocess.run(cmd, shell=True, input=inp, capture_output=True, text=True)


def compile_c(src_text, compiler, out_o):
    cpp = ('mips-linux-gnu-cpp -Iinclude -Isrc -undef -Wall -lang-c -fno-builtin -D__GNUC__=2 -Dmips '
           '-D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C')
    cmd = (f'{cpp} - | /opt/cc/{compiler}/cc1 -quiet -mcpu=3000 -fgnu-linker -mgas -gcoff -w -O2 -mhard-float -G0 '
           f'| python3 /work/tools/maspsx/maspsx.py --aspsx-version=2.79 --expand-div --use-comm-section '
           f'| mips-linux-gnu-as -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -EL -o {out_o}')
    r = subprocess.run(['bash', '-o', 'pipefail', '-c', cmd], input=src_text, capture_output=True, text=True)
    return r.returncode == 0, r.stderr


def func_code(o_path, name):
    with open(o_path, 'rb') as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name('.symtab')
        sym = next((s for s in symtab.iter_symbols() if s.name == name), None)
        if sym is None:
            return None, None
        sec = elf.get_section(sym['st_shndx'])
        data = sec.data()[sym['st_value']:sym['st_value'] + sym['st_size']]
        masks = {}
        for rs in elf.iter_sections():
            if isinstance(rs, RelocationSection) and rs.name in ('.rel.text', '.rela.text'):
                rsyms = elf.get_section(rs['sh_link'])
                for r in rs.iter_relocations():
                    off = r['r_offset'] - sym['st_value']
                    if 0 <= off < sym['st_size']:
                        t = r['r_info_type']
                        target = rsyms.get_symbol(r['r_info_sym'])
                        if t == 4 and target['st_info']['type'] == 'STT_SECTION' and target['st_shndx'] == sym['st_shndx']:
                            # `j` to a label in this function: its offset from the function start
                            # must match too (GCC uses the section symbol + addend for local labels)
                            word = int.from_bytes(data[off:off + 4], 'little')
                            masks[off] = ('local', ((word & 0x3FFFFFF) << 2) - sym['st_value'])
                        else:
                            masks[off] = 0xFC000000 if t == 4 else 0xFFFF0000  # R_MIPS_26 / HI16,LO16
        return data, masks


def diff_count(o_path, name, addr, size):
    """Number of differing instruction words, or None if sizes differ."""
    data, masks = func_code(o_path, name)
    if data is None or len(data) != size:
        return None
    orig = ORIG[addr - VRAM + OFF: addr - VRAM + OFF + size]
    n = 0
    for i in range(0, size, 4):
        m = masks.get(i, 0xFFFFFFFF)
        a = int.from_bytes(data[i:i + 4], 'little')
        b = int.from_bytes(orig[i:i + 4], 'little')
        if isinstance(m, tuple):
            n += (a >> 26) != (b >> 26) or m[1] != (((b & 0x3FFFFFF) << 2) | (addr & 0xF0000000)) - addr
        else:
            n += (a & m) != (b & m)
    return n


def matches(o_path, name, addr, size):
    data, masks = func_code(o_path, name)
    if data is None or len(data) != size:
        return False
    orig = ORIG[addr - VRAM + OFF: addr - VRAM + OFF + size]
    for i in range(0, size, 4):
        a = int.from_bytes(data[i:i + 4], 'little')
        b = int.from_bytes(orig[i:i + 4], 'little')
        m = masks.get(i, 0xFFFFFFFF)
        if isinstance(m, tuple):  # local jump: compare where it lands within the function
            if (a & 0xFC000000) != (b & 0xFC000000):
                return False
            orig_target = (((b & 0x3FFFFFF) << 2) | (addr & 0xF0000000)) - addr
            if m[1] != orig_target:
                return False
            continue
        if (a & m) != (b & m):
            return False
    return True


BASE_CTX = None


def base_ctx():
    """common.h + m2c_macros.h preprocessed into a context m2c can parse."""
    global BASE_CTX
    if BASE_CTX is None:
        hdr = open('include/common.h').read() + open('include/m2c_macros.h').read()
        hdr = re.sub(r'^#include .*$', '', hdr, flags=re.M)
        BASE_CTX = sh('mips-linux-gnu-cpp -P -undef -DM2CTX -', inp=hdr).stdout
    return BASE_CTX


JTBL_RE = re.compile(r'%lo\((jtbl_[0-9A-F]{8})\)')


def with_jtbls(asm, asm_path):
    """Append the function's jump tables (from their INCLUDE_RODATA files) for m2c, with
    entries as labels and a label at each target, so m2c can rebuild the switch."""
    tbls = sorted(set(JTBL_RE.findall(asm)))
    if not tbls:
        return asm
    folder = os.path.dirname(asm_path)
    targets, extra = set(), ['.section .rodata']
    for t in tbls:
        p = f'{folder}/{t}.s'
        if not os.path.exists(p):
            return None
        s = re.sub(r'^(?:nonmatching|\.align).*\n', '', open(p).read(), flags=re.M)
        s = re.sub(r'^.*\.word 0x00000000\n', '', s, flags=re.M)  # alignment padding after the table
        targets |= set(re.findall(r'\.word 0x([0-9A-F]{8})', s))
        extra.append(re.sub(r'\.word 0x([0-9A-F]{8})', r'.word .L\1', s))
    lines = []
    for l in asm.splitlines():
        m = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/', l)
        if m and m.group(1) in targets and f'.L{m.group(1)}:' not in asm:
            lines.append(f'.L{m.group(1)}:')
        lines.append(l)
    return '\n'.join(lines) + '\n' + '\n'.join(extra) + '\n'


def m2c(asm_path, ctx_extra=()):
    with open(asm_path) as fh:
        asm = with_jtbls(re.sub(r'^nonmatching .*\n', '', fh.read(), flags=re.M), asm_path)
    if asm is None:
        return None
    with tempfile.NamedTemporaryFile('w', suffix='.s', delete=False) as t:
        t.write(asm)
    with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False) as c:
        c.write(base_ctx() + '\n' + '\n'.join(ctx_extra) + '\n')
    r = sh(f'python3 -m m2c.main --target mipsel-gcc-c --valid-syntax --globals=used --context {c.name} {t.name}')
    os.unlink(t.name)
    os.unlink(c.name)
    if r.returncode != 0 or 'M2C_ERROR' in r.stdout:
        return None
    return r.stdout


def split_decls(code, name):
    """Split m2c output into (top-level declaration lines, function definition text)."""
    m = re.search(rf'^[^\n;]*\b{name}\([^;]*?\{{', code, re.M | re.S)
    if not m:
        return None, None
    decls = [l for l in code[:m.start()].splitlines() if l.strip() and not l.startswith('//')]
    decls = [re.sub(r'\s*/\* extern \*/', '', l).rstrip() for l in decls]
    return decls, code[m.start():].strip() + '\n'


def decl_name(line):
    # name of declared identifier: last identifier before ( [ ; =  (skip function-pointer oddities)
    m = re.match(r'\s*(?:extern )?struct \w+ \{.*\} (\w+)(?:\[\])?;$', line)
    if m:  # structify() output
        return m.group(1)
    names = DECL_NAME_RE.findall(line)
    return names[0][0] if names else None


SIGS = None


def sigs():
    global SIGS
    if SIGS is None:
        SIGS = json.load(open('build/sigs.json')) if os.path.exists('build/sigs.json') else {}
    return SIGS


def callee_protos(asm, name):
    """Prototypes (from the signature database) for every function this asm calls."""
    called = sorted(set(re.findall(r'\b(?:jal|j)\s+(\w+)', asm)) | set(re.findall(r'%(?:hi|lo)\((func_[0-9A-F]{8})\)', asm)))
    return tuple(sigs()[c] for c in called if c in sigs() and c != name)


def variants(asm, name):
    """Extra declarations (given to m2c as context and to the compiler) to try, in order."""
    protos = callee_protos(asm, name)
    syms = sorted(set(re.findall(r'%(?:hi|lo)\((D_[0-9A-F]{8})\)', asm)))
    arrays = tuple(f'extern s32 {s}[];' for s in syms)
    yield ()
    if syms:  # unknown globals as word arrays: fixes m2c's pointer-arithmetic scaling
        yield arrays
    if protos:  # known callee signatures: fixes pass-through arguments
        yield protos
        if syms:
            yield protos + arrays


PTR_DECL_RE = re.compile(r'^    [\w ]+?\s*\*+\s*(\w+);$', re.M)


def fix_ptr_steps(body):
    """m2c writes pointer increments in bytes; C scales them. Make them byte steps."""
    ptrs = set(PTR_DECL_RE.findall(body))
    if not ptrs:
        return body
    def sub(m):
        v, op, e = m.group(1), m.group(2), m.group(3)
        if v not in ptrs:
            return m.group(0)
        return f'{m.group(0)[:len(m.group(0)) - len(m.group(0).lstrip())]}{v} = (void *)((u8 *){v} {op} ({e}));'
    return re.sub(r'^\s*(\w+) ([+-])= ([^;]+);', sub, body, flags=re.M)


PARAMS_RE = re.compile(r'^([^\n;]*?\b(\w+)\()([^)]*)(\)\s*\{)', re.M)


def fix_params(body):
    """m2c names parameters by register (arg1 = $a1) and drops unused leading ones; restore them."""
    m = PARAMS_RE.search(body)
    if not m or m.group(3).strip() in ('', 'void'):
        return body
    params = [p.strip() for p in m.group(3).split(',')]
    idx = []
    for p in params:
        a = re.search(r'\barg(\d)$', p)
        if not a:
            return body
        idx.append(int(a.group(1)))
    if idx == list(range(len(idx))):
        return body
    have = dict(zip(idx, params))
    full = [have.get(i, f's32 arg{i}') for i in range(max(idx) + 1)]
    return body[:m.start(3)] + ', '.join(full) + body[m.end(3):]


TYPE_SIZE = {'s8': 1, 'u8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4, 'f32': 4, 'M2C_UNK': 4,
             'char': 1, 'short': 2, 'int': 4, 'void': 4,
             'SVECTOR': 8, 'S16x6': 12, 'S16x8': 16, 'S16x10': 20, 'S16x12': 24, 'S16x16': 32}
TYPE_ALIGN = {'SVECTOR': 2, 'S16x6': 2, 'S16x8': 2, 'S16x10': 2, 'S16x12': 2, 'S16x16': 2}
FIELD_RE = re.compile(r'M2C_FIELD\(&(D_[0-9A-F]{8}), ([\w ]+?\*+), (0x[0-9A-Fa-f]+|\d+)\)')
AFIELD_RE = re.compile(r'M2C_FIELD\(\(\((?P<i>\w+) \* (?P<k>0x[0-9A-Fa-f]+|\d+)\) \+ &(?P<g>D_[0-9A-F]{8})\), '
                       r'(?P<t>[\w ]+?\*+), (?P<off>0x[0-9A-Fa-f]+|\d+)\)')


def structify(decls, body):
    """Turn byte-offset accesses on globals into fields of a real struct.
    GCC addresses a struct global once (la base; op off(base)), which the original
    code does and M2C_FIELD casts don't."""
    acc, stride = {}, {}
    for m in AFIELD_RE.finditer(body):  # arrays of structs: (i * size) + &D_X
        g, k = m.group('g'), int(m.group('k'), 0)
        if stride.setdefault(g, k) != k:
            return None
    for g, t, off in FIELD_RE.findall(body) + [(m.group('g'), m.group('t'), m.group('off')) for m in AFIELD_RE.finditer(body)]:
        t = t[:-1].strip()  # the field type is the pointee
        size = 4 if t.endswith('*') else TYPE_SIZE.get(t)
        if size is None:
            return None
        acc.setdefault(g, {}).setdefault(int(off, 0), set()).add((t, size))
    if not acc or (set(stride) & {g for g, _, _ in FIELD_RE.findall(body)}):
        return None
    new_decls = [d for d in decls if decl_name(d.replace('extern ', '')) not in acc]
    for g, fields in sorted(acc.items()):
        parts, pos = [], 0
        for off in sorted(fields):
            t0, s0 = next(iter(fields[off]))
            if len(fields[off]) != 1 or off < pos or off % TYPE_ALIGN.get(t0, s0):
                return None  # overlapping or unaligned: needs a union, leave to a human
            t, size = next(iter(fields[off]))
            if off > pos:
                parts.append(f'u8 pad_{pos:X}[0x{off - pos:X}];')
            parts.append(f'{t} f_{off:X};')
            pos = off + size
        if g in stride:
            if pos > stride[g]:
                return None
            if pos < stride[g]:
                parts.append(f'u8 pad_{pos:X}[0x{stride[g] - pos:X}];')
        new_decls.append(f'extern struct S_{g} {{ {" ".join(parts)} }} {g}{"[]" if g in stride else ""};')
    body = AFIELD_RE.sub(lambda m: f'{m.group("g")}[{m.group("i")}].f_{int(m.group("off"), 0):X}', body)
    body = FIELD_RE.sub(lambda m: f'{m.group(1)}.f_{int(m.group(3), 0):X}', body)
    names = '|'.join(acc)
    if re.search(rf'\b({names})\b(?!\.f_|\[)', re.sub(rf'&\s*({names})\b', '', body)):
        return None  # the global is also used whole; a struct type would change that
    return new_decls, body


ADDR_OFF_RE = re.compile(r'&(D_[0-9A-F]{8}) \+ (0x[0-9A-Fa-f]+|\d+)\b')


ADDR_EXPR_RE = re.compile(r'\(([^()]*(?:\([^()]*\)[^()]*)*)\) \+ &(D_[0-9A-F]{8})\b')
BYTE_CONST_RE = re.compile(r', s8 \*, (\w+)\) = (0x[89A-Fa-f][0-9A-Fa-f]|12[89]|1[3-9]\d|2[0-5]\d);')
HALF_CONST_RE = re.compile(r', s16 \*, (\w+)\) = (0x[89A-Fa-f][0-9A-Fa-f]{3});')


ADDR_VAR_RE = re.compile(r'(?<![\w.>)\]])\b([a-z_]\w*) \+ &(D_[0-9A-F]{8})\b')
INDEX_RE = re.compile(r'M2C_FIELD\(\((\w+) \+ \((\w+) \* (\d+)\)\), ([\w ]+?\*+), (0x[0-9A-Fa-f]+|\d+)\)')


def fix_addr_offsets(body):
    """m2c's `&D_X + N` / `(expr) + &D_X` / `var + &D_X` mean bytes past D_X; C would
    scale by the element size."""
    body = ADDR_OFF_RE.sub(r'(void *)((u8 *)&\1 + \2)', body)
    body = ADDR_VAR_RE.sub(r'(void *)((u8 *)&\2 + \1)', body)
    return ADDR_EXPR_RE.sub(r'(void *)((u8 *)&\2 + (\1))', body)


UCOPY_RE = re.compile(r'^(\s*)M2C_FIELD\((.+?), M2C_UNK \*, (0x[0-9A-Fa-f]+|\d+)\) = '
                      r'M2C_UNALIGNED32\(M2C_FIELD\((.+?), M2C_UNK \*, (0x[0-9A-Fa-f]+|\d+)\)\);$')
COPY_TYPES = {2: 'SVECTOR', 3: 'S16x6', 4: 'S16x8', 5: 'S16x10', 6: 'S16x12', 8: 'S16x16'}


def fix_struct_copies(body):
    """Runs of unaligned word copies (lwl/lwr, swl/swr) between the same two bases are one
    assignment of a 2-byte-aligned struct (SVECTOR for 8 bytes)."""
    lines, out, i = body.split('\n'), [], 0
    while i < len(lines):
        m = UCOPY_RE.match(lines[i])
        if not m:
            out.append(lines[i])
            i += 1
            continue
        ind, dst, doff, src, soff = m.groups()
        n = 1
        while i + n < len(lines):
            m2 = UCOPY_RE.match(lines[i + n])
            if not (m2 and m2.group(2) == dst and m2.group(4) == src
                    and int(m2.group(3), 0) == int(doff, 0) + 4 * n and int(m2.group(5), 0) == int(soff, 0) + 4 * n):
                break
            n += 1
        t = COPY_TYPES.get(n)
        if t is None:
            out.extend(lines[i:i + n])
        else:
            out.append(f'{ind}M2C_FIELD({dst}, {t} *, {doff}) = M2C_FIELD({src}, {t} *, {soff});')
        i += n
    return '\n'.join(out)


SCRATCH_RE = re.compile(r'\(([\w ]+?\*+)\)\s*0x1F80([0-9A-Fa-f]{4})\b')


def fix_scratchpad(body):
    """Scratchpad (0x1F800000) accesses through one base pointer, as the original code does
    (one lui, then offsets), instead of a constant address per access."""
    if not SCRATCH_RE.search(body):
        return body
    body = SCRATCH_RE.sub(lambda m: f'({m.group(1)})(scratch + 0x{m.group(2).upper()})', body)
    return re.sub(r'\)\s*\{\n', ') {\n    u8 *scratch = (u8 *)0x1F800000;\n', body, count=1)


REV_LOOP_RE = re.compile(
    r'^(?P<ind>[ \t]*)(?P<cnt>\w+) = (?P<n>0x[0-9A-Fa-f]+|\d+);\n'
    r'[ \t]*(?P<ptr>\w+) = &(?P<g>D_[0-9A-F]{8}) \+ (?P<start>0x[0-9A-Fa-f]+|\d+);\n'
    r'[ \t]*do \{\n(?P<body>.*?)\n[ \t]*\} while \((?P=cnt) >= 0\);', re.M | re.S)


def fix_reverse_loops(decls, body):
    """GCC's strength-reduced `for (i = N; i >= 0; i--) D_X[i].f = v;` comes out of m2c
    as a pointer walking backwards from &D_X + N * stride. Rebuild the indexed loop over
    an array of structs (declared in structify's format, so later matches can widen it)."""
    m = REV_LOOP_RE.search(body)
    if not m:
        return None
    ind, cnt, ptr, g = m.group('ind'), m.group('cnt'), m.group('ptr'), m.group('g')
    n, start = int(m.group('n'), 0), int(m.group('start'), 0)
    stride, stores = None, []
    for line in m.group('body').split('\n'):
        l = line.strip()
        if l == f'{cnt} -= 1;':
            continue
        sm = re.match(rf'{ptr} -= \(?(0x[0-9A-Fa-f]+|\d+)\)?;$', l)
        if sm:
            stride = int(sm.group(1), 0)
            continue
        fm = re.match(rf'M2C_FIELD\({ptr}, ([\w ]+?)\s*\*, (0x[0-9A-Fa-f]+|\d+)\) = (.+);$', l)
        if fm:
            stores.append((fm.group(1), int(fm.group(2), 0), fm.group(3)))
            continue
        fm = re.match(rf'\*{ptr} = (.+);$', l)
        if fm:
            stores.append((None, 0, fm.group(1)))
            continue
        return None  # anything else in the loop: leave it alone
    if not stride or not stores or start != n * stride:
        return None
    fields = {}
    for t, off, _ in stores:
        if t is None:
            t = {1: 's8', 2: 's16', 4: 's32'}.get(stride, 's32') if stride <= 4 else 's32'
        size = 4 if t.endswith('*') else TYPE_SIZE.get(t)
        if size is None or not merge_field(fields, off, (t, size)):
            return None
    line = struct_line(g, fields, True, stride)
    if line is None:
        return None
    loop = (f'{ind}for (i = {n}; i >= 0; i--) {{\n' +
            ''.join(f'{ind}    {g}[i].f_{off:X} = {v};\n' for t, off, v in stores) + f'{ind}}}')
    body = body[:m.start()] + loop + body[m.end():]
    body = re.sub(rf'^[ \t]*[\w \*]+?\b({cnt}|{ptr});\n', '', body, flags=re.M)  # their declarations
    body = re.sub(r'\)\s*\{\n', ') {\n    s32 i;\n', body, count=1)
    decls = [d for d in decls if decl_name(d.replace('extern ', '')) != g] + [line]
    return decls, body


def fix_indexing(body):
    """`M2C_FIELD((p + (i * 4)), T *, off)` with sizeof(T) == 4 is an array element:
    `((T *)((u8 *)p + off))[i]`. GCC 2.8 treats integer and address arithmetic differently."""
    def sub(m):
        p, i, k, t, off = m.groups()
        t = t[:-1].strip()
        size = 4 if t.endswith('*') else TYPE_SIZE.get(t)
        if size != int(k):
            return m.group(0)
        return f'(({t} *)((u8 *){p} + {off}))[{i}]'
    return INDEX_RE.sub(sub, body)


def fix_unsigned_consts(body):
    """A byte/halfword store of a constant >= 0x80/0x8000 was declared unsigned in the original."""
    body = BYTE_CONST_RE.sub(r', u8 *, \1) = \2;', body)
    return HALF_CONST_RE.sub(r', u16 *, \1) = \2;', body)


FROM_WIP = False


def try_func(job):
    name, folder, addr, size, compiler = job
    asm_path = f'{folder}/{name}.s'
    best = None
    drafts = []
    if FROM_WIP:  # only a finished draft from wip/ (e.g. a permuter result)
        for path in (f'wip/{name}.perm.c', f'wip/{name}.c'):
            if os.path.exists(path):
                text = open(path).read()
                m = re.search(rf'^[^\n;]*\b{name}\([^;{{]*\)\s*\{{', text, re.M)
                if m:
                    decls = [l for l in text[:m.start()].splitlines() if l.strip()]
                    drafts.append((decls, text[m.start():].strip() + '\n'))
                break
        asm_path = None
    for extra in (variants(open(asm_path).read(), name) if asm_path else ()):
        code = m2c(asm_path, extra)
        if not code:
            continue
        decls, body = split_decls(code, name)
        if body is None:
            continue
        body = fix_struct_copies(fix_unsigned_consts(fix_params(body)))
        cands = [(list(extra) + decls, body)]
        rl = fix_reverse_loops(list(extra) + decls, body)
        if rl:
            cands.append(rl)
        fixed = fix_ptr_steps(body)
        if fixed != body:
            cands.append((list(extra) + decls, fixed))
        for d, b in list(cands):
            fb = fix_addr_offsets(b)
            if fb != b:
                cands.append((d, fb))
        for d, b in list(cands):
            fb = fix_indexing(b)
            if fb != b:
                cands.append((d, fb))
        for d, b in list(cands):
            fb = fix_scratchpad(b)
            if fb != b:
                cands.append((d, fb))
        for d, b in list(cands):
            s = structify(d, b)
            if s:
                cands.append(s)
        drafts += cands
    for decls, body in drafts:
        tu = '#include "common.h"\n#include "m2c_macros.h"\n\n' + '\n'.join(decls) + '\n\n' + body
        o = f'/tmp/ad_{os.getpid()}.o'
        good, _ = compile_c(tu, compiler, o)
        if not good:
            continue
        if matches(o, name, addr, size):
            return decls, body
        d = diff_count(o, name, addr, size)
        if d is not None and (best is None or d < best):
            best = d
            best_tu = '\n'.join(decls) + '\n\n' + body
    if best is not None:
        with open('build/near_misses.txt', 'a') as fh:
            fh.write(f'{best} {size:#x} {name}\n')
        if os.environ.get('SAVE_WIP'):
            os.makedirs('wip', exist_ok=True)
            with open(f'wip/{name}.c', 'w') as fh:
                fh.write(best_tu)
    return None


STRUCT_DECL_RE = re.compile(r'^extern struct S_(\w+) \{ (.*) \} (\w+)(\[\])?;$')
PAD_RE = re.compile(r'u8 pad\w*\[(0x[0-9A-Fa-f]+|\d+)\]$')


def parse_struct(line):
    """(global, {off: (type, size)}, size, is_array, {off: name}) of a one-line struct declaration."""
    m = STRUCT_DECL_RE.match(line)
    if not m:
        return None
    fields, names, pos = {}, {}, 0
    for f in m.group(2).split(';'):
        f = f.strip()
        if not f:
            continue
        pm = PAD_RE.match(f)
        if pm:
            pos += int(pm.group(1), 0)
            continue
        t, n = f.rsplit(' ', 1)
        size = 4 if t.endswith('*') else TYPE_SIZE.get(t)
        if size is None:
            return None
        fields[pos], names[pos] = (t, size), n
        pos += size
    return m.group(3), fields, pos, bool(m.group(4)), names


def merge_field(fields, off, f, prefer_new=False):
    """Add field f = (type, size) at off. Same-size types that differ only in signedness
    keep the existing type: m2c's signedness is often a guess (plain copies load with lhu
    whatever the type), the existing code is proven to match with it, and verify_file()
    recompiles the new function with it. False on a real conflict."""
    old = fields.setdefault(off, f)
    if old == f:
        return True
    ok = old[1] == f[1] and old[0].lstrip('su') == f[0].lstrip('su') and old[0][0] in 'su' and f[0][0] in 'su'
    if ok and prefer_new:
        fields[off] = f
    return ok


def merge_struct(a, b, prefer_new=False):
    """Merge struct declaration b into the file's a. Returns (line, {b's field name: a's})
    or None if they disagree. a's field names win."""
    pa, pb = parse_struct(a), parse_struct(b)
    if not pa or not pb or pa[0] != pb[0] or pa[3] != pb[3] or (pa[3] and pa[2] != pb[2]):
        return None
    fields, names, ren = dict(pa[1]), dict(pa[4]), {}
    for off, f in pb[1].items():
        if not merge_field(fields, off, f, prefer_new):
            return None
        names.setdefault(off, pb[4][off])
        if names[off] != pb[4][off]:
            ren[pb[4][off]] = names[off]
    line = struct_line(pa[0], fields, pa[3], max(pa[2], pb[2]), names)
    return (line, ren) if line else None


def rename_fields(g, ren, body):
    for old, new in ren.items():
        body = re.sub(rf'(\b{g}\b(?:\[[^\]]*\])?\.){old}\b', rf'\g<1>{new}', body)
    return body


SCALAR_DECL_RE = re.compile(r'^extern ([\w ]+?\**) (D_[0-9A-F]{8});$')


def view_fields(decl, g, code):
    """The fields of global g implied by one declaration plus the code that uses it, or None."""
    p = parse_struct(decl)
    if p:
        return p[1], p[3], p[2]
    m = SCALAR_DECL_RE.match(decl)
    if not m:
        return None
    t = m.group(1).strip()
    uses = [(tt[:-1].strip(), off) for gg, tt, off in FIELD_RE.findall(code) if gg == g]
    bare = re.search(rf'\b{g}\b(?!\s*[.\[])', re.sub(rf'M2C_FIELD\(&{g},', '', code))
    fields = {}
    if t == 'M2C_UNK':
        if bare and not uses:
            return None
    elif t.endswith('*') or t in TYPE_SIZE:
        fields[0] = (t, 4 if t.endswith('*') else TYPE_SIZE[t])
    else:
        return None
    for tt, off in uses:
        size = 4 if tt.endswith('*') else TYPE_SIZE.get(tt)
        if size is None or fields.setdefault(int(off, 0), (tt, size)) != (tt, size):
            return None
    return fields, False, 0


def struct_line(g, fields, is_array, stride, names=None):
    parts, pos = [], 0
    for off in sorted(fields):
        t, size = fields[off]
        if off < pos:
            return None
        if off > pos:
            parts.append(f'u8 pad_{pos:X}[0x{off - pos:X}];')
        parts.append(f'{t} {(names or {}).get(off, f"f_{off:X}")};')
        pos = off + size
    if is_array and pos < stride:
        parts.append(f'u8 pad_{pos:X}[0x{stride - pos:X}];')
    return f'extern struct S_{g} {{ {" ".join(parts)} }} {g}{"[]" if is_array else ""};'


def to_struct_uses(g, code, is_array=False):
    """Rewrite scalar/M2C_FIELD uses of g into struct-field uses (of element 0 for arrays)."""
    e = f'{g}[0]' if is_array else g
    code = re.sub(rf'M2C_FIELD\(&{g}, [\w ]+?\*+, (0x[0-9A-Fa-f]+|\d+)\)', lambda m: f'{e}.f_{int(m.group(1), 0):X}', code)
    return re.sub(rf'\b{g}\b(?!\s*[.\[])', f'{e}.f_0', code)


def unify(old, new, g, file_code, body, prefer_new=False):
    """One struct declaration covering both views of global g, or None."""
    a, b = view_fields(old, g, file_code), view_fields(new, g, body)
    pn = parse_struct(new)
    if a and pn and pn[3] and not a[1] and a[0] and set(a[0]) == {0} and pn[1].get(0) == a[0][0]:
        return new  # scalar T and an array of records starting with T: the array view covers both
    if not a or not b or a[1] or b[1]:  # other arrays of structs: leave to merge_struct
        return None
    fields = dict(a[0])
    for off, f in b[0].items():
        if not merge_field(fields, off, f, prefer_new):
            return None
    p = parse_struct(old)
    if p and any(not n.startswith('f_') for n in p[4].values()):
        return None  # named fields: the new scalar view would need renaming; leave it
    return struct_line(g, fields, False, 0)


def func_info(name):
    """(addr, size) of a game function from its asm/nonmatchings file."""
    path = glob.glob(f'asm/nonmatchings/**/{name}.s', recursive=True)
    if not path:
        return None
    s = open(path[0]).read()
    mm = re.search(r'^nonmatching \w+, (0x[0-9A-F]+)', s, re.M)
    am = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', s)
    return int(am.group(1), 16), int(mm.group(1), 16)


def rodata_start(src):
    """Original address of this game file's .rodata (rodata_runs.txt), or None."""
    owner = os.path.splitext(src)[0].replace('src/', '', 1)
    for line in open('rodata_runs.txt'):
        f = line.split('#')[0].split()
        if len(f) == 2 and f[1] == owner:
            return int(f[0], 16)
    return None


def rodata_matches(o_path, start):
    """The object's .rodata equals the original bytes at start (relocated words masked)."""
    with open(o_path, 'rb') as fh:
        elf = ELFFile(fh)
        sec = elf.get_section_by_name('.rodata')
        if sec is None or sec.data_size == 0:
            return True
        if start is None:
            return False
        data = bytearray(sec.data())
        for rs in elf.iter_sections():
            if isinstance(rs, RelocationSection) and rs.name in ('.rel.rodata', '.rela.rodata'):
                for r in rs.iter_relocations():
                    data[r['r_offset']:r['r_offset'] + 4] = ORIG[start - VRAM + OFF + r['r_offset']:][:4]
    return bytes(data) == ORIG[start - VRAM + OFF:][:len(data)]



def symbol_addr(name):
    """Address of a renamed symbol from symbol_addrs.txt, or None."""
    for line in open('symbol_addrs.txt'):
        m = re.match(rf'^{re.escape(name)} = (0x[0-9A-Fa-f]+);', line)
        if m:
            return int(m.group(1), 16)
    return None


def game_funcs(text):
    """Names of the game functions defined in a src file: func_XXXXXXXX, main, and renamed
    ones (they have an asm/nonmatchings file or a symbol_addrs.txt entry)."""
    out = []
    for name in re.findall(r'^\w[\w \*]*?\b(\w+)\([^;]*$', text, re.M):
        if re.fullmatch(r'func_[0-9A-F]{8}|main', name) or func_info(name) or symbol_addr(name) is not None:
            out.append(name)
    return out


def game_func_info(o, name):
    """(addr, size) to compare a compiled function against."""
    info = func_info(name)
    if info is None:
        # already C when asm/ was split, so no asm file: the name (or symbol_addrs.txt) gives
        # the address, and the compiled size must reproduce the original bytes there
        if name == 'main':
            addr = 0x8005BDC0
        elif name.startswith('func_'):
            addr = int(name[5:], 16)
        else:
            addr = symbol_addr(name)
        data, _ = func_code(o, name)
        info = (addr, len(data or b''))
    return info

def verify_file(text, compiler, src=None):
    """Compile a whole src file; True if every C-defined function in it still matches
    (and, given the file name, its .rodata too)."""
    o = f'/tmp/vf_{os.getpid()}.o'
    good, _ = compile_c(text, compiler, o)
    if not good:
        return False
    for name in game_funcs(text):
        if not matches(o, name, *game_func_info(o, name)):
            return False
    return src is None or rodata_matches(o, rodata_start(src))


def own_proto(n, text):
    m = re.search(rf'^(\w[^;{{\n]*\b{n}\([^;{{]*\))\s*\{{', text, re.M)
    return m.group(1).replace('static ', '') + ';' if m else None


def recheck_with(decls, body, name, addr, size, compiler, file_decls, defined, text=''):
    """Recompile a matched draft with the file's own declarations substituted.
    Returns (decls, new_decls) if it still matches, else None."""
    if name in file_decls and not file_decls[name].startswith(('extern', '<')):
        file_decls = {k: v for k, v in file_decls.items() if k != name}  # a prototype of itself is harmless
    if name in file_decls:
        return None
    use_game_h = False
    out, new = [], {}
    for d in decls:
        n = decl_name(d.replace('extern ', ''))
        if n is None or n == name:
            out.append(d)
        elif n in defined:
            p = own_proto(n, text)
            if p is None:
                return None
            out.append(p)  # defined in this file: use its real signature
        elif n in file_decls:
            if file_decls[n] == '<game.h>':
                use_game_h = True
            else:
                out.append(file_decls[n])
        else:
            out.append(d)
            new[n] = d
    hdr = '#include "game.h"\n' if use_game_h else '#include "common.h"\n'
    tu = hdr + '#include "m2c_macros.h"\n\n' + '\n'.join(out) + '\n\n' + body
    o = f'/tmp/ad_recheck.o'
    good, _ = compile_c(tu, compiler, o)
    if good and matches(o, name, addr, size):
        return out, new
    return None


def render(text, cands):
    """The src file with these accepted candidates integrated."""
    add = []
    for c in cands:
        for d in c['decls']:
            if d not in add and d + '\n' not in text:
                add.append(d)
    for c in cands:
        text = text.replace(f'INCLUDE_ASM("{c["folder"]}", {c["name"]});\n', c['body'], 1)
        for t in c.get('jtbls', ()):  # the compiled switch now emits its own table
            text = re.sub(rf'^INCLUDE_RODATA\("[^"]+", {t}\);\n', '', text, flags=re.M)
        p = own_proto(c['name'], c['body'])
        if p:  # an older guessed prototype of a now-defined function must agree with it
            text = re.sub(rf'^(?![ \t])[^\n(]*\b{c["name"]}\([^\n]*\);$', lambda m: p, text, flags=re.M)
    if '#include "m2c_macros.h"' not in text:
        text = re.sub(r'(#include "(?:common|game)\.h"\n)', r'\1#include "m2c_macros.h"\n', text, count=1)
    if add:
        text = text.replace('#include "m2c_macros.h"\n', '#include "m2c_macros.h"\n\n' + '\n'.join(add) + '\n', 1)
    for c in cands:
        for old, new in c['repl'].items():
            text = text.replace(old + '\n', new + '\n')
    lines, seen = [], set()
    for l in text.split('\n'):  # identical top-level declarations may now appear twice
        top_decl = l.startswith('extern ') or (not l.startswith((' ', '\t', '}', '#', '/')) and l.endswith(');'))
        if top_decl:
            if l in seen:
                continue
            seen.add(l)
        lines.append(l)
    tostruct = set().union(*(c['tostruct'] for c in cands))
    arrays = {g for g in tostruct if re.search(rf'\}} {g}\[\];$', '\n'.join(lines), re.M)}
    for i, l in enumerate(lines):
        if not l.startswith('extern '):
            for g in tostruct:
                lines[i] = to_struct_uses(g, lines[i], g in arrays)
    return '\n'.join(lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--max-size', type=lambda x: int(x, 0), default=0x400)
    ap.add_argument('--compiler', default='2.8.1-psx')
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--only', default='')
    ap.add_argument('--from-wip', action='store_true', help='integrate finished drafts from wip/ instead of running m2c')
    args = ap.parse_args()
    only = set(filter(None, args.only.split(',')))
    global FROM_WIP
    FROM_WIP = args.from_wip

    pool = multiprocessing.Pool(os.cpu_count())
    total = ok = 0
    for src in sorted(glob.glob('src/**/*.c', recursive=True)):
        text = open(src).read()
        file_decls = {}  # name -> decl line already present in this file (from earlier passes)
        if '#include "game.h"' in text:  # names owned by the shared header can't be redeclared
            for l in open('include/game.h').read().splitlines():
                if l.startswith('extern '):
                    n = decl_name(l.replace('extern ', ''))
                    if n:
                        file_decls[n] = '<game.h>'
        for l in text.splitlines():
            if l.startswith('extern ') or (l.endswith(');') and not l.startswith((' ', 'INCLUDE'))):
                n = decl_name(l.replace('extern ', ''))
                if n:
                    file_decls[n] = l
        defined = set(re.findall(r'^\w[\w \*]*?\b(func_\w+)\([^;]*$', text, re.M))
        accepted = []
        jobs = []
        for folder, name in INC_RE.findall(text):
            if only and name not in only:
                continue
            asm = open(f'{folder}/{name}.s').read()
            mm = re.search(r'^nonmatching \w+, (0x[0-9A-F]+)', asm, re.M)
            am = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', asm)
            size, addr = int(mm.group(1), 16), int(am.group(1), 16)
            if size > args.max_size or SKIP_RE.search(asm):
                continue
            jobs.append((name, folder, addr, size, args.compiler))
        total += len(jobs)
        for (name, folder, addr, size, _), res in zip(jobs, pool.map(try_func, jobs)):
            if res is None:
                continue
            decls, body = res
            c = {'name': name, 'folder': folder, 'repl': {}, 'tostruct': set(), 'risky': False,
                 'jtbls': set(JTBL_RE.findall(open(f'{folder}/{name}.s').read()))}
            conflict = False
            new = {}
            for i, d in enumerate(decls):
                n = decl_name(d.replace('extern ', ''))
                if n is None or n == name:
                    continue
                old = file_decls.get(n)
                merged = None
                if old and old != d and parse_struct(d) and parse_struct(old):
                    r = merge_struct(old, d)  # widen the file's struct for this global
                    if r:
                        merged, ren = r
                        alt = merge_struct(old, d, prefer_new=True)
                        if alt and alt[0] != merged:
                            c.setdefault('alt', {})[merged] = alt[0]
                        body = rename_fields(n, ren, body)  # use the file's field names
                elif old and old != d and old != '<game.h>' and n.startswith('D_') and (parse_struct(d) or parse_struct(old)):
                    merged = unify(old, d, n, text, body)  # scalar/untyped view + struct view
                    alt = unify(old, d, n, text, body, prefer_new=True)
                    if merged and alt and alt != merged:
                        c.setdefault('alt', {})[merged] = alt
                    if merged:
                        c['tostruct'].add(n)
                        if not parse_struct(d):
                            body = to_struct_uses(n, body, parse_struct(merged)[3])
                if merged:
                    c['repl'][old] = merged
                    file_decls[n] = merged
                    decls[i] = d = merged
                if (n in file_decls and file_decls[n] != d) or n in defined or (n in new and new[n] != d):
                    conflict = True
                    break
                new[n] = d
            if conflict:
                # retry using the declarations the file already has
                fixed = recheck_with(decls, body, name, addr, size, args.compiler, file_decls, defined, text)
                if fixed is not None:
                    decls, new = fixed
                else:
                    # let this draft's declarations win; verify_file() decides at the end
                    new, ok_risky = {}, True
                    bodies = text + ''.join(a['body'] for a in accepted)
                    for d in decls:
                        n = decl_name(d.replace('extern ', ''))
                        if n is None or n == name:
                            continue
                        old = file_decls.get(n)
                        if old == '<game.h>':
                            if parse_struct(d):  # the body uses generated field names
                                ok_risky = False
                                break
                            continue  # keep the header's type; the body usually doesn't care
                        if n in defined:
                            d = own_proto(n, bodies)
                            if d is None:
                                ok_risky = False
                                break
                        elif old and old != d:
                            if not n.startswith('func_'):
                                ok_risky = False  # other code in the file relies on this global's type
                                break
                            c['repl'][old] = d
                        new[n] = d
                    if not ok_risky:
                        print(f'CONFLICT {name}', flush=True)
                        continue
                    c['risky'] = True
            file_decls.update(new)
            defined.add(name)
            c['body'] = body
            c['decls'] = list(new.values())
            accepted.append(c)
            print(f'MATCH {name} ({size:#x}) {src}{" (risky)" if c["risky"] else ""}', flush=True)
        if accepted and not args.dry_run:
            full = render(text, accepted)
            if verify_file(full, args.compiler, src):
                open(src, 'w').write(full)
                ok += len(accepted)
                continue
            os.makedirs('build/failed_render', exist_ok=True)
            open(f'build/failed_render/{os.path.basename(src)}', 'w').write(full)
            # add them one at a time (safe ones first), keeping each that still verifies
            kept, dropped = [], []
            for a in sorted(accepted, key=lambda a: a['risky']):
                if verify_file(render(text, kept + [a]), args.compiler, src):
                    kept.append(a)
                    continue
                if a.get('alt'):  # signedness: let this function's view of the field win
                    b = dict(a)
                    b['repl'] = {k: a['alt'].get(v, v) for k, v in a['repl'].items()}
                    b['decls'] = [a['alt'].get(d, d) for d in a['decls']]
                    if verify_file(render(text, kept + [b]), args.compiler, src):
                        kept.append(b)
                        continue
                dropped.append(a['name'])
            if kept:
                open(src, 'w').write(render(text, kept))
                ok += len(kept)
            print(f'ROLLBACK {src}: dropped {",".join(dropped)}', flush=True)
    print(f'{ok}/{total} candidate functions matched', flush=True)


if __name__ == '__main__':
    main()
