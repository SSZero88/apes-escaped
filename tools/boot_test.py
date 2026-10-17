"""Boot a disc image headlessly in RetroArch and take screenshots at given frame counts.

Usage: python tools/boot_test.py <disc.cue> [--frames 1500,3000,4500] [--out build/boot/<name>]
                                [--compare other.cue] [--core mednafen_psx]

Each frame count is a separate run from power-on, unthrottled and muted, with no
controller input, so runs are deterministic. With --compare the other disc is run
the same way and screenshots are compared pixel by pixel; the exit status is
1 if any differ. Your own RetroArch config, saves and states are never touched:
saves go to a fresh temporary folder and the config is not saved on exit.

RetroArch is looked for in %APPDATA%\\RetroArch, or set RETROARCH=<path to retroarch.exe>.
"""
import argparse, os, shutil, subprocess, sys, tempfile, zlib, struct


def ra_exe():
    exe = os.environ.get('RETROARCH') or os.path.join(os.environ.get('APPDATA', ''), 'RetroArch', 'retroarch.exe')
    if not os.path.exists(exe):
        sys.exit(f'RetroArch not found at {exe}; set RETROARCH=<path to retroarch.exe>')
    return exe


def png_pixels(path):
    """Decode a non-interlaced 8-bit RGB/RGBA PNG (what RetroArch writes) to raw rows."""
    data = open(path, 'rb').read()
    assert data[:8] == b'\x89PNG\r\n\x1a\n', path
    i, idat, w = 8, b'', None
    while i < len(data):
        n, typ = struct.unpack('>I4s', data[i:i + 8])
        body = data[i + 8:i + 8 + n]
        if typ == b'IHDR':
            w, h, depth, ctype = struct.unpack('>IIBB', body[:10])
            bpp = {2: 3, 6: 4}[ctype]
        elif typ == b'IDAT':
            idat += body
        i += 12 + n
    raw, stride, prev, out = zlib.decompress(idat), w * bpp, bytearray(w * bpp), []
    for y in range(h):
        f, line = raw[y * (stride + 1)], bytearray(raw[y * (stride + 1) + 1:(y + 1) * (stride + 1)])
        for x in range(stride):
            a = line[x - bpp] if x >= bpp else 0
            b, c = prev[x], prev[x - bpp] if x >= bpp else 0
            if f == 1: line[x] = (line[x] + a) & 255
            elif f == 2: line[x] = (line[x] + b) & 255
            elif f == 3: line[x] = (line[x] + (a + b) // 2) & 255
            elif f == 4:
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                line[x] = (line[x] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 255
        out.append(bytes(line))
        prev = line
    return (w, h), out


def run(cue, frames, png, core):
    exe = ra_exe()
    radir = os.path.dirname(exe)
    tmp = tempfile.mkdtemp(prefix='apes_boot_')
    try:
        cfg = os.path.join(tmp, 'test.cfg')
        with open(cfg, 'w') as c:
            c.write('\n'.join(f'{k} = "{v}"' for k, v in {
                'config_save_on_exit': 'false', 'video_vsync': 'false', 'audio_sync': 'false',
                'audio_enable': 'false', 'savefile_directory': tmp, 'savestate_directory': tmp,
                'savestate_auto_load': 'false', 'savestate_auto_save': 'false',
                'pause_nonactive': 'false', 'video_fullscreen': 'false',
                'sort_savefiles_enable': 'false', 'sort_savestates_enable': 'false',
                'history_list_enable': 'false', 'game_specific_options': 'false',
                'global_core_options': 'true', 'core_options_path': os.path.join(tmp, 'core.opt'),
            }.items()) + '\n')
        # note: this RetroArch rejects "--opt=value"; pass values as separate arguments
        args = [exe, '-L', os.path.join(radir, 'cores', f'{core}_libretro.dll'), '--appendconfig', cfg,
                '--max-frames', str(frames), '--max-frames-ss', '--max-frames-ss-path', os.path.abspath(png),
                os.path.abspath(cue)]
        if os.path.exists(png):
            os.remove(png)
        r = subprocess.run(args, cwd=radir, capture_output=True, text=True, errors='replace', timeout=900)
        if not os.path.exists(png):
            sys.exit(f'no screenshot from RetroArch (exit {r.returncode}):\n{r.stderr[-2000:]}')
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('cue')
    ap.add_argument('--frames', default='1500,3000,4500')
    ap.add_argument('--out')
    ap.add_argument('--compare')
    ap.add_argument('--core', default='mednafen_psx')
    args = ap.parse_args()
    frames = [int(x) for x in args.frames.split(',')]

    def shots(cue, out):
        os.makedirs(out, exist_ok=True)
        paths = []
        for n in frames:
            p = os.path.join(out, f'frame{n:05d}.png')
            run(cue, n, p, args.core)
            print(f'  {p}')
            paths.append(p)
        return paths

    name = lambda c: os.path.splitext(os.path.basename(c))[0]
    out = args.out or os.path.join('build', 'boot', name(args.cue))
    print(f'{args.cue}:')
    a = shots(args.cue, out)
    if not args.compare:
        return
    print(f'{args.compare}:')
    b = shots(args.compare, out + '_vs_' + name(args.compare))
    differ = 0
    for n, pa, pb in zip(frames, a, b):
        if open(pa, "rb").read() == open(pb, "rb").read():
            print(f"frame {n}: identical")
            continue
        (sa, ra), (sb, rb) = png_pixels(pa), png_pixels(pb)
        if sa != sb:
            print(f'frame {n}: DIFFERENT size {sa} vs {sb}')
            differ += 1
            continue
        rows = sum(x != y for x, y in zip(ra, rb))
        print(f'frame {n}: ' + ('identical' if not rows else f'DIFFERENT ({rows} of {sa[1]} rows)'))
        differ += rows > 0
    sys.exit(1 if differ else 0)


if __name__ == '__main__':
    main()
