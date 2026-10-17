#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "common.h"
#include "common.h"
#include "common.h"
#define __builtin_abs(x) ((x) < 0 ? -(x) : (x))
#include "common.h"
typedef struct { s16 f_0; s16 pad2; s16 f_4; s16 f_6; s16 f_8; } S_4F438_8004F438;
typedef struct { s16 f_0; s16 f_2; s16 f_4; } S_8004E33C_8004E33C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; } S_8004F330_8004F330;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8004F330_8004F330;
typedef struct { s32 vx, vy, vz, pad; } VEC_8004F330_8004F330;
typedef struct { s16 vx, vy, vz; } SV_8004F884_8004F884;
typedef struct { s32 vx, vy, vz; } V_8004F884_8004F884;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; } S_8004F884_8004F884;
typedef struct { s32 a; s32 b; } W_8004F884_8004F884;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[4]; u8 f_10; } O_8004FC8C_8004FC8C;
typedef struct { s32 x, y, z; } P_8004FC8C_8004FC8C;
typedef struct { s16 w; s16 h; s16 d; } B_8004EA1C_8004EA1C;
typedef struct { s32 x, y, z; } P_8004EA1C_8004EA1C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[4]; u8 f_10; u8 pad11[0x13]; s16 f_24; s16 f_26; } O_8004F984_8004F984;
typedef struct { s32 x, y, z; } P_8004F984_8004F984;
typedef struct { s32 vx, vy, vz, pad; } V_8004F984_8004F984;
typedef struct { s16 vx, vy, vz, pad; } SV_8004F984_8004F984;
typedef struct { s32 x, y, z; } V3_4F000_8004F000;
typedef struct { s16 f_0; s16 pad2; s16 f_4; u8 pad6[0xA]; u8 f_10; } S_4FF20_8004FF20;
typedef struct { s16 f_0; s16 pad2; s16 f_4; s16 f_6; s16 pad8; s16 f_A; u8 padC[4]; u8 f_10; } S_4FE48_8004FE48;
typedef struct { s16 f_0; s16 f_2; s16 f_4; } S_8004FFC8_8004FFC8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; } S_8004E8F8_8004E8F8;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8004E8F8_8004E8F8;
typedef struct { s32 vx, vy, vz, pad; } VEC_8004E8F8_8004E8F8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[4]; u8 f_10; u8 pad11[0x1B]; s16 f_2C; } S_O_8004F548_8004F548;
typedef struct { s32 vx, vy, vz; } VEC_8004F548_8004F548;

s32 Vec_Length(s32, s32, s32);

/* func_8004F548: height on a ramp collision shape o at point p: kinds 0x4A/0x4C slope along x,
 * others along z (direction by f_2C: 0 / 0x5A). Within the half-length f_6 on the slope axis and
 * 0x48 across it, the height runs linearly from f_A*2 to f_8; 0 outside. */
s32 func_8004F548(S_O_8004F548_8004F548 *o, VEC_8004F548_8004F548 *p);
extern s32 D_800AF2F0;
extern s32 D_800AF2EC;
extern struct S_D_800A4DF0 { s32 v[4]; } D_800A4DF0;
s32 Geo_DiagonalDistance(s32, s32 *, SVEC_8004F330_8004F330 *, VEC_8004F330_8004F330 *);
extern s32 (*D_800AF180[])(s16, SV_8004F884_8004F884 *, V_8004F884_8004F884 *, W_8004F884_8004F884 *);
void VectorNormalS(void *, void *);
s32 ratan2(s32, s32);
/* Centre of a quarter-round corner piece 'F'..'I' (+0x10): its box centre (+0, +4) moved by the
 * half sizes (+6, +0xA) to the corner the arc is drawn around; out[0] x, out[1] z. */
s32 CurvedCorner_GetCentre(S_4FE48_8004FE48 *b, s32 *out);
s32 func_8004FC8C(O_8004FC8C_8004FC8C *o, P_8004FC8C_8004FC8C *p, s32 ext, s16 *out);
struct Game_4E444 { u8 pad0[0x8296]; s16 f_8296; };
extern struct Game_4E444 g_Game;
s32 SquareRoot0(s32);
int abs(int);
struct S_D_800EC350_8004E8F8 { u8 pad_0[0x8296]; s16 f_8296; };

INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004D8C0);

INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004DF38);

s32 func_8004E33C(s16 k, S_8004E33C_8004E33C *b, s32 *p, s32 *out) {
    s16 x;
    s16 z;

    *out = 0;
    switch (k) {
    case 0x3C:
        x = 0;
        z = -b->f_4;
        break;
    case 0x3D:
        x = -b->f_0;
        z = 0;
        break;
    case 0x3E:
        x = 0;
        z = b->f_4;
        break;
    case 0x3F:
        x = b->f_0;
        z = 0;
        break;
    default:
        x = 0;
        z = 0;
        break;
    }
    if (p[0] < x - b->f_0 || x + b->f_0 < p[0] || p[2] < z - b->f_4 || z + b->f_4 < p[2] || b->f_0 == 0 || b->f_4 == 0) {
        return 0;
    }
    *out = b->f_2;
    D_800AF2F0 = 0;
    D_800AF2EC = 0;
    return 1;
}

/* Floor height for narrow walkway tiles (only in play mode g_Game+0x8296 == 1): a 0x80-wide strip
 * along z (kinds 3/5) or x (kinds 4/6); kinds 0x2A..0x2D are corners whose arm is chosen by the
 * point's diagonal, and the centre square counts for both. Returns 1 with the top b[1]. */
s32 Surface_NarrowPathHeight(s16 kind, s16 *b, s32 *p, s32 *out) {
    s16 dir;
    s32 a;

    *out = 0;
    if (g_Game.f_8296 != 1) {
        return 0;
    }
    if (kind == 3) {
        dir = 2;
    } else if (kind == 5) {
        dir = 2;
    } else if (kind == 6) {
        dir = 1;
    } else if (kind == 4) {
        dir = 1;
    } else {
        a = p[0];
        if (a < 0) {
            a = -a;
        }
        if (a <= 0x40) {
            a = p[2];
            if (a < 0) {
                a = -a;
            }
            if (a <= 0x40) {
                dir = 3;
                goto done;
            }
        }
        switch (kind) {
        case 0x2A:
            dir = 2;
            if (p[2] > p[0]) {
                dir = 1;
            }
            break;
        case 0x2B:
            dir = 1;
            if (-p[0] < p[2]) {
                dir = 2;
            }
            break;
        case 0x2C:
            dir = 1;
            if (p[2] > p[0]) {
                dir = 2;
            }
            break;
        case 0x2D:
            dir = 2;
            if (-p[0] < p[2]) {
                dir = 1;
            }
            break;
        }
    }
done:
    if (dir == 1) {
        if ((u32)(p[0] + 0x40) > 0x80) {
            return 0;
        }
        if (b[2] < p[2] || p[2] < -b[2]) {
            return 0;
        }
    } else if (dir == 2) {
        if ((u32)(p[2] + 0x40) > 0x80) {
            return 0;
        }
        if (b[0] < p[0] || p[0] < -b[0]) {
            return 0;
        }
    }
    *out = b[1];
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004E63C);

INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", jtbl_800A4DD0);


/* func_8004E8F8: floor test for a diagonal collision shape (kinds from 0x37, direction from the
 * table D_800A4DF0): only while g_Game+0x8296 is 1, inside the box +-b->f_0 x +-b->f_4, and within
 * 0x40 of the diagonal (Geo_DiagonalDistance); then *out = height b->f_2 and it returns 1. */
s32 func_8004E8F8(s16 k, S_8004E8F8_8004E8F8 *b, s32 *p, s32 *out) {
    struct S_D_800A4DF0 tbl = D_800A4DF0;
    VEC_8004E8F8_8004E8F8 r;
    SVEC_8004E8F8_8004E8F8 sv;
    s32 d;

    *out = 0;
    if (((struct S_D_800EC350_8004E8F8 *)&g_Game)->f_8296 != 1) {
        return 0;
    }
    if (p[0] < -b->f_0 || b->f_0 < p[0]) {
        return 0;
    }
    if (p[2] < -b->f_4 || b->f_4 < p[2]) {
        return 0;
    }
    sv.vx = sv.vy = sv.vz = 0;
    d = Geo_DiagonalDistance(k | tbl.v[k - 0x37], p, &sv, &r);
    d = abs(d);
    if (d > 0x40) {
        return 0;
    }
    *out = b->f_2;
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", D_800A4DF0);


/* Surface height of a sloped piece at local point p inside its box (half sizes b->w, b->d):
 * kinds 7, 9, 10, 8 are 45-degree slopes rising towards -z, +z, -x, +x (out[0] = height,
 * and the downhill push D_800AF2F0 / D_800AF2EC = +-0x200); kinds 64, 66, 67, 65 are the same
 * slopes as walls: only below the previous height (old out[0]) minus the slope, giving the top
 * b->h in out[0] and the slope height in out[1]. Returns 0 outside (or above), else 1. */
s32 Surface_SlopeHeight(s16 type, B_8004EA1C_8004EA1C *b, P_8004EA1C_8004EA1C *p, s32 *out) {
    s32 old = out[0];
    s32 v;
    out[0] = 0;
    if (p->x < -b->w || b->w < p->x || p->z < -b->d || b->d < p->z) {
        return 0;
    }
    switch (type) {
    case 7:
        out[0] = p->z + 0x100;
        D_800AF2F0 = -0x200;
        D_800AF2EC = 0;
        break;
    case 9:
        out[0] = -p->z + 0x100;
        D_800AF2F0 = 0x200;
        D_800AF2EC = 0;
        break;
    case 10:
        out[0] = p->x + 0x100;
        D_800AF2EC = -0x200;
        D_800AF2F0 = 0;
        break;
    case 8:
        out[0] = -p->x + 0x100;
        D_800AF2EC = 0x200;
        D_800AF2F0 = 0;
        break;
    case 64:
        { s32 l = old - 0x100; l -= p->z; if (p->y >= l) {
            return 0;
        } }
        out[0] = b->h;
        D_800AF2EC = 0;
        D_800AF2F0 = 0;
        out[1] = p->z + 0x100;
        return 1;
    case 66:
        { s32 l = old - 0x100; l += p->z; if (p->y >= l) {
            return 0;
        } }
        out[0] = b->h;
        D_800AF2EC = 0;
        D_800AF2F0 = 0;
        out[1] = -p->z + 0x100;
        return 1;
    case 67:
        { s32 l = old - 0x100; l -= p->x; if (p->y >= l) {
            return 0;
        } }
        out[0] = b->h;
        v = p->x;
        D_800AF2EC = 0;
        D_800AF2F0 = 0;
        v += 0x100;
        out[1] = v;
        return 1;
    case 65:
        { s32 l = old - 0x100; l += p->x; if (p->y >= l) {
            return 0;
        } }
        out[0] = b->h;
        v = p->x;
        D_800AF2EC = 0;
        D_800AF2F0 = 0;
        v = -v;
        v += 0x100;
        out[1] = v;
        return 1;
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", jtbl_800A4E00_pad);


s32 Coll_HalfCylinderHeight_EC3C(s16, s16 *, s32 *, s32 *) asm("Coll_HalfCylinderHeight");
/* func_8004EC3C: floor test for collision shape kinds 0x24/0x25 (half cylinders, via
 * Coll_HalfCylinderHeight) and round floors (within radius e[0] of p: height e[1]); kinds
 * 0x46-0x49, 0x52-0x54 have no floor here. The no-op kind++/kind-- is a permuter find needed for
 * the register allocation. */
s32 func_8004EC3C(u16 kind, s16 *e, s32 *p, s32 *out) {
    s32 h;

    *out = 0;
    if ((u16)(kind - 0x46) < 4) {
        kind++;
        kind--;
        goto miss;
    }
    if ((u16)(kind - 0x24) < 2) {
        if (Coll_HalfCylinderHeight_EC3C(kind, e, p, &h)) {
            *out = h;
            return 1;
        }
    } else {
        if ((u16)(kind - 0x53) < 2) {
            return 0;
        }
        if ((s16)kind == 0x52) {
            return 0;
        }
    }
    if (Vec_Length(p[0], 0, p[2]) < e[0]) {
        D_800AF2F0 = 0;
        D_800AF2EC = 0;
        *out = e[1];
        return 1;
    }
miss:
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004ED30);

INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", jtbl_800A4EF8);


INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004EE94);

INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", jtbl_800A4F18);
INCLUDE_RODATA("asm/nonmatchings/game/8004D8C0_collision", jtbl_800A4F18_pad);


s32 Coll_RampHeight(s16 kind, s16 *e, V3_4F000_8004F000 *p, s32 *h) {
    if (p->x < -e[0] || e[0] < p->x || p->z < -e[2] || e[2] < p->z) {
        return 0;
    }
    *h = 0;
    if (e[0] < 0x41 || e[2] < 0x41) {
        *h = e[1];
        D_800AF2EC = 0;
        D_800AF2F0 = 0;
        return 1;
    }
    switch (kind) {
    case 0x55:
        *h = e[1] / 2 + e[1] / 2 * p->z / e[2];
        D_800AF2EC = 0;
        D_800AF2F0 = (-e[1] << 9) / (e[2] * 2);
        break;
    case 0x57:
        *h = e[1] / 2 - e[1] / 2 * p->z / e[2];
        D_800AF2EC = 0;
        D_800AF2F0 = (e[1] << 9) / (e[2] * 2);
        break;
    case 0x58:
        *h = e[1] / 2 + e[1] / 2 * p->x / e[0];
        D_800AF2EC = (-e[1] << 9) / (e[0] * 2);
        D_800AF2F0 = 0;
        break;
    case 0x56:
        *h = e[1] / 2 - e[1] / 2 * p->x / e[0];
        D_800AF2EC = (e[1] << 9) / (e[0] * 2);
        D_800AF2F0 = 0;
        break;
    }
    return 1;
}

s32 func_8004F330(s16 k, S_8004F330_8004F330 *b, s32 *p, s32 *out) {
    struct S_D_800A4DF0 tbl = D_800A4DF0;
    VEC_8004F330_8004F330 r;
    SVEC_8004F330_8004F330 sv;

    *out = 0;
    if (p[0] < -b->f_0 || b->f_0 < p[0]) {
        return 0;
    }
    if (p[2] < -b->f_4 || b->f_4 < p[2]) {
        return 0;
    }
    sv.vx = sv.vy = sv.vz = 0;
    if (Geo_DiagonalDistance(k | tbl.v[k - 0x26], p, &sv, &r) > 0) {
        return 0;
    }
    D_800AF2EC = 0;
    D_800AF2F0 = 0;
    *out = b->f_2;
    return 1;
}

s32 func_8004F438(S_4F438_8004F438 *a, s32 *pos, s32 *out) {
    s32 w;
    s32 ang;
    *out = 0;
    w = a->f_6 * 75 / 1000;
    if (w < 0x40) {
        w = 0x40;
    }
    ang = Vec_Length(a->f_0 - pos[0], 0, a->f_4 - pos[2]);
    if (a->f_6 - w / 2 >= ang || ang >= a->f_6 + w / 2) {
        return 0;
    }
    *out = a->f_8;
    return 1;
}

s32 func_8004F514(void *arg0, void *arg1, s32 *arg2) {
    s32 temp_v0;

    *arg2 = 0;
    temp_v0 = func_8004F548(arg0, arg1);
    *arg2 = temp_v0;
    return temp_v0 != 0;
}

s32 func_8004F548(S_O_8004F548_8004F548 *o, VEC_8004F548_8004F548 *p) {
    s32 lim = 0x48;
    s32 ox = o->f_0;
    s32 px = p->vx;
    s32 oz = o->f_4;
    s32 pz = p->vz;
    s32 dx = px - ox;
    s32 dz = pz - oz;
    s32 h;
    s32 w;
    s32 t;
    if (o->f_10 == 0x4A || o->f_10 == 0x4C) {
        h = o->f_6;
        if (abs(dx) > h || abs(dz) > lim) {
            return 0;
        }
        if (o->f_2C == 0) {
            t = (ox + h) - px;
        } else {
            t = px - (ox - h);
        }
        return o->f_A * 2 + (o->f_8 - o->f_A * 2) * t / (o->f_6 * 2);
    } else {
        w = o->f_6;
        if (abs(dz) > w || abs(dx) > lim) {
            return 0;
        }
        if (o->f_2C == 0x5A) {
            t = (oz + w) - pz;
        } else {
            t = pz - (oz - w);
        }
        return o->f_A * 2 + (o->f_8 - o->f_A * 2) * t / (o->f_6 * 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8004D8C0_collision", func_8004F6E8);

s32 func_8004F884(s32 idx, S_8004F884_8004F884 *s, V_8004F884_8004F884 *p, s32 *out) {
    SV_8004F884_8004F884 sv[2];
    s32 unused[2];
    W_8004F884_8004F884 w;
    V_8004F884_8004F884 v;
    s32 ret;

    v.vx = p->vx - s->f_0;
    v.vy = p->vy;
    v.vz = p->vz - s->f_4;
    sv[1].vx = s->f_6;
    sv[1].vy = s->f_8;
    sv[1].vz = s->f_A;
    w.a = s->f_2;
    ret = D_800AF180[idx](idx, &sv[1], &v, &w);
    if ((u32)(idx - 0x40) < 4) {
        out[0] = s->f_2 - w.b;
        out[1] = w.a - w.b;
    } else {
        out[0] = s->f_2;
        out[1] = w.a;
    }
    return ret;
}

/* Quarter-round corner piece ('F'..'I', see func_8004FC8C): ring of radius +6 +- +0x24 around the
 * corner centre (CurvedCorner_GetCentre). Returns the floor height at p, interpolated from +0x26 to +8
 * along the arc, and the slope direction scaled by the height change in out[0..1]; -1 if p is
 * too far below, -2 off the ring (q[0] = p's radius), -3 outside the corner box. */
s32 Coll_CurvedCorner(O_8004F984_8004F984 *o, P_8004F984_8004F984 *p, s32 *q, s16 *out) {
    V_8004F984_8004F984 v;
    SV_8004F984_8004F984 n;
    s32 c[2];
    s16 angs[2];
    s32 r;
    s32 outer;
    s32 inner;
    s32 d;
    s32 a;
    s32 x;
    s32 h;

    r = q[0];
    if (o->f_2 < -q[2] + p->y) {
        return -1;
    }
    CurvedCorner_GetCentre(o, c);
    inner = o->f_6 - o->f_24;
    outer = o->f_24 + o->f_6;
    if (outer == 0) {
        outer = 1;
    }
    d = Vec_Length(c[0] - p->x, 0, c[1] - p->z);
    if (inner + r < ABS(outer - d)) {
        return -2;
    }
    if (func_8004FC8C(o, p, r, angs) < 0) {
        return -3;
    }
    v.vx = p->x - c[0];
    v.vy = 0;
    v.vz = p->z - c[1];
    VectorNormalS(&v, &n);
    a = ratan2(n.vz, n.vx);
    if (a < 0) {
        a += 0x1000;
    }
    if ((a & 0x3FF) == 0) {
        if (a == angs[0]) {
            a++;
        } else if (a == angs[1]) {
            a--;
        }
        if (a < 0) {
            a += 0x1000;
        }
    }
    h = o->f_26 + (o->f_8 - o->f_26) * (a % 0x400) / 1024;
    v.vx = p->z - c[1];
    v.vy = 0;
    v.vz = p->x - c[0];
    VectorNormalS(&v, &n);
    out[0] = (o->f_8 - o->f_26) * n.vx / 4096 * 204800 / (outer * 628);
    out[1] = (o->f_26 - o->f_8) * n.vz / 4096 * 204800 / (outer * 628);
    return h;
}

/* Corner region test for records of type 'F'..'I' (+0x10): is point p inside the box of half
 * size +6/+0xA around (+0, +4), extended by ext towards one corner? On a hit writes that corner's
 * angle range to out[0..1] ('F' 0x800-0xC00, 'G' 0x400-0x800, 'H' 0-0x400, 'I' 0xC00-0) and
 * returns 0; a miss returns -1, other types 0. Used by Coll_CurvedCorner. */
s32 func_8004FC8C(O_8004FC8C_8004FC8C *o, P_8004FC8C_8004FC8C *p, s32 ext, s16 *out) {
    s32 w = o->f_6;
    s32 d = o->f_A;
    s32 we = w + ext;
    s32 de = d + ext;
    switch (o->f_10) {
    case 'F':
        if (o->f_0 + w < p->x || p->x < o->f_0 - we || o->f_4 + d < p->z || p->z < o->f_4 - de) {
            return -1;
        }
        out[0] = 0x800;
        out[1] = 0xC00;
        break;
    case 'G':
        if (o->f_0 + w < p->x || p->x < o->f_0 - we || o->f_4 + de < p->z || p->z < o->f_4 - d) {
            return -1;
        }
        out[0] = 0x400;
        out[1] = 0x800;
        break;
    case 'H':
        if (o->f_0 + we < p->x || p->x < o->f_0 - w || o->f_4 + de < p->z || p->z < o->f_4 - d) {
            return -1;
        }
        out[0] = 0;
        out[1] = 0x400;
        break;
    case 'I':
        if (o->f_0 + we < p->x || p->x < o->f_0 - w || o->f_4 + d < p->z || p->z < o->f_4 - de) {
            return -1;
        }
        out[0] = 0xC00;
        out[1] = 0;
        break;
    default:
        return 0;
    }
    return 0;
}

s32 CurvedCorner_GetCentre(S_4FE48_8004FE48 *b, s32 *out) {
    switch (b->f_10) {
    case 0x46:
        out[0] = b->f_0 + b->f_6;
        out[1] = b->f_4 + b->f_A;
        goto miss;
    case 0x47:
        out[0] = b->f_0 + b->f_6;
        out[1] = b->f_4 - b->f_A;
        goto miss;
    case 0x48:
        out[0] = b->f_0 - b->f_6;
        out[1] = b->f_4 - b->f_A;
        goto miss;
    case 0x49:
        out[0] = b->f_0 - b->f_6;
        out[1] = b->f_4 + b->f_A;
        miss:
        return 0;
    }
    goto miss;
}

/* Edge pieces 'N'..'Q' (+0x10): 1 if pos is beyond the edge line (z < +4, x < +0, z > +4, x > +0). */
s32 Coll_PastEdge(S_4FF20_8004FF20 *s, s32 *pos) {
    switch (s->f_10) {
    case 0x4E:
        if (pos[2] < s->f_4) {
            return 1;
        }
        goto miss;
    case 0x4F:
        if (pos[0] < s->f_0) {
            return 1;
        }
        goto miss;
    case 0x50:
        if (s->f_4 < pos[2]) {
            return 1;
        }
        goto miss;
    case 0x51:
        if (s->f_0 < pos[0]) {
            return 1;
        }
        miss:
        return 0;
    }
    goto miss;
}

/* Height test for a half-cylinder piece (box half extents b->f_0 x, b->f_4 z): kind 0x24 has its
 * axis along x (height sqrt(f_4^2 - z^2)), the other kind along z (sqrt(f_0^2 - x^2)). Writes the
 * surface height to *out and returns 1 when the point is inside the footprint with p[1] <= height.
 * The odd double `return 0` branch is what the permuter found to match the original's layout. */
s32 Coll_HalfCylinderHeight(s16 k, S_8004FFC8_8004FFC8 *b, s32 *p, s32 *out)
{
  s32 d;
  s32 z;
  s32 w;
  s32 x;
  s32 a;
  s32 h;
  *out = 0;
  z = p[2];
  w = b->f_4;
  if (w < ((z >= 0) ? (z) : (-z)))
  {
    return 0;
  }
  x = p[0];
  h = b->f_0;
  if (h < ((x >= 0) ? (x) : (-x)))
  {
    if (out || x)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  if (k == 0x24)
  {
    d = SquareRoot0((w * w) - (z * z));
    if (d < p[1])
    {
      return 0;
    }
    *out = d;
    D_800AF2EC = 0;
  }
  else
  {
    d = SquareRoot0((h * h) - (x * x));
    if (d < p[1])
    {
      return 0;
    }
    *out = d;
    D_800AF2F0 = 0;
  }
  return 1;
}

typedef struct { s32 x, y, z; } V3_500D8;
extern struct { s32 v; } SlideX_500D8 asm("D_800AF2EC");

/* Height of a cylinder-shaped surface (a log or rounded top) at point p, relative to a box with half
   extents e: kind 0x53 curves across z (height sqrt(r^2 - z^2), radius e[2] +- 0x100), the other
   kind across x; it also sets the slide push D_800AF2EC / D_800AF2F0 on the curved part. Returns
   whether there is a surface (*h != 0). */
s32 Surface_CylinderHeight(s16 kind, s16 *e, V3_500D8 *p, s32 *h) {
    s32 d;
    s32 r;
    s32 t;
    s32 t_s0;

    *h = 0;
    if (kind == 0x53) {
        if (ABS(p->z) > e[2] + 0x100) {
            return 0;
        }
        if (ABS(p->x) > e[0]) {
            return 0;
        }
        d = Vec_Length(p->y, 0, p->z);
        if (p->y < 0) {
            if (e[2] - 0x100 < d) {
                *h = SquareRoot0((e[2] + 0x100) * (e[2] + 0x100) - p->z * p->z);
            } else {
                *h = -SquareRoot0((e[2] - 0x100) * (e[2] - 0x100) - p->z * p->z);
            }
        } else {
            if (e[2] + 0x100 < d) {
                *h = 0;
            } else if (d < e[2] - 0xC0) {
                *h = -SquareRoot0((e[2] - 0x100) * (e[2] - 0x100) - p->z * p->z);
            } else {
                *h = -SquareRoot0((e[2] + 0x100) * (e[2] + 0x100) - p->z * p->z);
            }
        }
        SlideX_500D8.v = 0;
        if (*h < 0) {
            t_s0 = ABS(*h) + 0x100;
            D_800AF2F0 = (e[2] - t_s0) * 3 * 1024 / (e[2] - 0x100);
            if (p->z > 0) {
                D_800AF2F0 = -D_800AF2F0;
            }
            if (ABS(D_800AF2F0) < 0x80) {
                D_800AF2F0 = 0;
            }
        } else {
            D_800AF2F0 = 0;
        }
    } else {
        if (ABS(p->x) > e[0] + 0x100) {
            return 0;
        }
        if (ABS(p->z) > e[2]) {
            return 0;
        }
        d = Vec_Length(p->y, 0, p->x);
        if (p->y < 0) {
            if (e[0] - 0x100 < d) {
                *h = SquareRoot0((e[0] + 0x100) * (e[0] + 0x100) - p->x * p->x);
            } else {
                *h = -SquareRoot0((e[0] - 0x100) * (e[0] - 0x100) - p->x * p->x);
            }
        } else {
            if (e[0] + 0x100 < d) {
                *h = 0;
            } else if (d < e[0] - 0xC0) {
                *h = -SquareRoot0((e[0] - 0x100) * (e[0] - 0x100) - p->x * p->x);
            } else {
                *h = -SquareRoot0((e[0] + 0x100) * (e[0] + 0x100) - p->x * p->x);
            }
        }
        D_800AF2F0 = 0;
        if (*h < 0) {
            t = ABS(*h) + 0x100;
            SlideX_500D8.v = (e[0] - t) * 3 * 1024 / (e[0] - 0x100);
            if (p->x > 0) {
                SlideX_500D8.v = -SlideX_500D8.v;
            }
            if (ABS(SlideX_500D8.v) < 0x80) {
                SlideX_500D8.v = 0;
            }
        } else {
            SlideX_500D8.v = 0;
        }
    }
    return *h != 0;
}

s32 Coll_HeightOverlap(s32 y, s32 h, s32 oy, s32 oh) {
    if (y - 0x60 > oy - oh && y - 0x60 < oy) {
        return 1;
    }
    if (h < 0x60) {
        return 0;
    }
    if (y - h / 2 > oy - oh && y - h / 2 < oy) {
        return 1;
    }
    if (y - h > oy - oh && y - h < oy) {
        return 1;
    }
    if (y - 0x60 > oy - oh && y - h < oy - oh) {
        return 1;
    }
    if (y - 0x60 > oy - oh / 2 && y - h < oy - oh / 2) {
        return 1;
    }
    if (y - 0x60 > oy && y - h < oy) {
        return 1;
    }
    return 0;
}
