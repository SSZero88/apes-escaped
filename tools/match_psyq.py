"""Match PsyQ library signatures (lab313ru/psx_psyq_signatures) against the exe.
Usage: python tools/match_psyq.py <exe> <sigs_dir> [version]
Without version: prints the match score of each PsyQ version.
With version: prints splat symbol_addrs lines for uniquely-matched objects."""
import json, os, re, sys

TEXT_OFF, VRAM = 0x800, 0x80010000

def load(path):
    try:
        return json.load(open(path, encoding='utf-8'))
    except Exception:
        return []

def compile_sig(sig):
    toks = sig.split()
    if sum(t != '??' for t in toks) < 24:  # too short / ambiguous
        return None
    return re.compile(b''.join(b'.' if t == '??' else re.escape(bytes([int(t, 16)])) for t in toks), re.S)

def matches(exe, vdir):
    out = []
    for fn in sorted(os.listdir(vdir)):
        if not fn.endswith('.json'):
            continue
        for obj in load(os.path.join(vdir, fn)):
            if not isinstance(obj, dict): continue
            rx = compile_sig(obj.get('sig', ''))
            if not rx:
                continue
            hits = [m.start() for m in rx.finditer(exe) if m.start() % 4 == 0 and m.start() >= TEXT_OFF]
            out.append((fn, obj, hits))
    return out

def main():
    exe = open(sys.argv[1], 'rb').read()
    sd = sys.argv[2]
    if len(sys.argv) < 4:
        for v in sorted(d for d in os.listdir(sd) if d.isdigit()):
            res = matches(exe, os.path.join(sd, v))
            uniq = [r for r in res if len(r[2]) == 1]
            nbytes = sum(len(r[1]['sig'].split()) for r in uniq)
            print(f'{v}: {len(uniq)} objs, {nbytes} bytes')
        return
    seen = {}
    allm = [m for v in sys.argv[3].split(",") for m in matches(exe, os.path.join(sd, v))]
    covered = []
    for fn, obj, hits in allm:
        if len(hits) != 1:
            continue
        base = VRAM + hits[0] - TEXT_OFF
        size = len(obj.get('sig','').split())
        if any(b <= base < e or base <= b < base + size for b, e in covered):
            continue
        covered.append((base, base + size))
        for lab in obj['labels']:
            n = lab['name']
            if n.startswith(('loc_', 'text_', 'data_', 'bss_')):
                continue
            a = base + lab['offset']
            if a not in seen and n not in seen.values():
                seen[a] = n
        print(f'# {fn[:-5]}:{obj["name"]} @ {base:08X} size 0x{size:X}', file=sys.stderr)
    for a in sorted(seen):
        print(f'{seen[a]} = 0x{a:08X}; // type:func')

main()
