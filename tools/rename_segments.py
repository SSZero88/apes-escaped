"""Rename game C segments from <ADDR> to <ADDR>_<name> everywhere (run from the repo root, on the host).

Usage: python tools/rename_segments.py [--dry-run]
Moves src/game/<ADDR>.c and asm/nonmatchings/game/<ADDR>/, and rewrites the segment path in the splat
config, linker script, .d file, rodata_runs.txt and the INCLUDE_ASM / INCLUDE_RODATA paths in src/.
Segments already renamed are skipped, so the script can be re-run after adding names."""
import os, re, sys

NAMES = {
    '80010000': 'memcard', '80010B50': 'cd', '80014750': 'anim', '80015F70': 'model',
    '8001F3A0': 'draw_fx', '80031B60': 'stage_load', '80032E30': 'monkey', '80043060': 'debug_item',
    '80043380': 'zone', '80046340': 'math', '80046670': 'camera', '80048DD0': 'camera2',
    '8004B880': 'camera3', '8004D0F0': 'cam_flyby', '8004D880': 'cam_point', '8004D8C0': 'collision',
    '80050580': 'object_draw', '80052D70': 'object', '800592E0': 'enemy_shot', '8005AB00': 'stage_special',
    '8005AD90': 'link', '8005BDC0': 'system', '8005BEF0': 'game_loop', '8005CD50': 'game_mode',
    '8005E000': 'debug_cpu', '8005E0F0': 'hud', '80060780': 'spike', '80068D10': 'texture',
    '80069500': 'effect', '8006ABF0': 'fx', '8006D4C0': 'fx_draw', '8006FA10': 'shockwave',
    '800715A0': 'tip', '80071D20': 'collide', '80079B10': 'screen_wipe', '8007A180': 'gadget',
    '8007CD60': 'guided_ammo', '8007D0F0': 'menu', '80083470': 'pickup', '800848C0': 'specter_coin',
    '80084A60': 'projectile', '80085230': 'projectile2', '80086040': 'sound', '80088670': 'platform',
    '8008C000': 'mem', '8008C390': 'debug_font', '8008D9D0': 'msg_text', '8008DEE0': 'msg',
    '8008E5C0': 'door', '8008FC30': 'box', '80090EB0': 'shock_box', '80093740': 'hazard',
    '800943E0': 'switch', '80094F20': 'stage', '80098330': 'center_sign', '800986E0': 'hoop',
    '80098FB0': 'time_net', '80099360': 'rc_car', '80099D20': 'radar', '8009A800': 'melee',
    '8009AD60': 'slingback', '8009B3B0': 'vehicle', '8009B7A0': 'overlay', '8009BA90': 'seq',
}
dry = '--dry-run' in sys.argv
CFG = ['scus_944.23.yaml', 'scus_944.23.ld', 'scus_944.23.d', 'rodata_runs.txt']

def sub_file(path, pairs):
    if not os.path.exists(path):
        return 0
    s = open(path, encoding='utf-8').read()
    t = s
    for a, b in pairs:
        t = re.sub(r'game/%s(?=[/."\]\s,)])' % a, 'game/' + b, t)
    if t != s and not dry:
        open(path, 'w', encoding='utf-8', newline='').write(t)
    return t != s

pairs = []
for a, n in NAMES.items():
    new = '%s_%s' % (a, n)
    if not os.path.exists('src/game/%s.c' % a):
        continue
    pairs.append((a, new))
    print(a, '->', new)
    if not dry:
        os.rename('src/game/%s.c' % a, 'src/game/%s.c' % new)
        if os.path.isdir('asm/nonmatchings/game/' + a):
            os.rename('asm/nonmatchings/game/' + a, 'asm/nonmatchings/game/' + new)
for f in CFG:
    print(f, 'updated' if sub_file(f, pairs) else 'unchanged')
for f in os.listdir('src/game'):
    sub_file(os.path.join('src/game', f), pairs)
print(len(pairs), 'segments renamed' + (' (dry run)' if dry else ''))
