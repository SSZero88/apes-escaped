#include "common.h"
#include "m2c_macros.h"
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x28]; s16 f_58; } S_Obj_8008AA6C_8008AA6C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; u8 pad10[0x10]; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; s16 f_28; s16 f_2A; s16 f_2C; s16 f_2E; } S_Plat_8008A91C_8008A91C;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[0xA]; } S_4D64_8008A91C_8008A91C;
typedef struct { u8 pad0[0x60]; s16 f_60; s16 f_62; s16 f_64; } S_EC1E0_8008A91C_8008A91C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x28]; s16 f_58; } S_Obj_8008ABB0_8008ABB0;
typedef struct { u8 pad0[0x10]; u16 f_10; } S_P_8008ABB0_8008ABB0;
typedef struct { u8 pad0[0x10]; u16 f_10; u8 pad12[0x18]; s16 f_2A; s16 f_2C; s16 f_2E; u8 pad30[6]; s16 f_36; } S_P_8008B228_8008B228;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[2]; s16 f_1C; u8 pad1E[2]; s16 f_20; u8 pad22[0x10]; s16 f_32; s16 f_34; s16 f_36; } Blk_80088F2C_80088F2C;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; s16 f_16; u8 pad18[8]; } Mdl_80088F2C_80088F2C;
typedef struct { u8 pad0[0x2A]; s16 rx; s16 ry; s16 rz; u8 pad30[6]; s16 f_36; } S_P_8008AD14_8008AD14;
typedef struct { s16 vx, vy, vz, pad; } SV_8008AD14_8008AD14;
typedef struct { s16 x; s16 y; s16 z; s16 hx; s16 hy; s16 hz; u8 padC[6]; u16 flags; u8 pad14[8]; u16 speed; u8 pad1E[0xC]; u16 dx; u16 dy; u16 dz; } Plat_8008A4B0_8008A4B0;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; s32 vx; s32 vy; s32 vz; u8 pad3C[0xA]; s16 f_46; u8 pad48[0x28]; s32 f_70; } Body_8008A4B0_8008A4B0;
typedef struct { u8 pad0[0x12]; u8 type; u8 pad13[5]; u16 f_18; u8 pad1A[0x16]; s16 f_30; u8 pad32[6]; } Zone_88AB8_80088AB8;
typedef struct { s16 vx, vy, vz, pad; } SV_892C4_800892C4;
typedef struct { s16 x, y, z, hx, hy, hz, f_C; u16 next; } Wp_892C4_800892C4;
typedef struct { s16 x, y, z; u8 pad6[6]; s16 f_C; s16 f_E; u8 pad10[0x10]; s16 f_20; s16 f_22; s16 f_24; s16 f_26; s16 f_28; u8 pad2A[8]; s16 f_32; } Plat_892C4_800892C4;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[0xA]; } Mdl_892C4_800892C4;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; u16 f_16; u8 pad18[8]; } S_4D64_8008BDB4;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[6]; s16 f_C; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0xA]; s16 f_24; s16 f_26; s16 f_28; u8 pad2A[8]; s16 f_32; } S_8BDB4_8008BDB4;
typedef struct { s16 x, y, z; u8 pad6[2]; u16 f_8; u8 padA[2]; s16 f_C; s16 f_E; u8 pad10[2]; u16 f_12; u8 pad14[6]; s16 f_1A; s16 f_1C; u8 pad1E[2]; s16 f_20; s16 f_22; u8 pad24[0xE]; s16 f_32; s16 f_34; } Plat_895F0_800895F0;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[6]; void *f_1C; } Mdl_895F0_800895F0;
typedef struct { s16 x, y, z; u8 pad6[0x32]; } Obj_895F0_800895F0;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[4]; u16 f_10; } S_P_8008BE4C_8008BE4C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u16 f_8; u16 f_A; u8 padC[2]; s16 f_E; } S_Ev_8008B7F8_8008B7F8;
typedef struct { u8 pad0[0x18]; u16 f_18; u8 pad1A[0x1E]; } S_820C_8008B7F8_8008B7F8;
typedef struct { u8 pad0[0xE]; u16 f_E; } S_8214_8008B7F8_8008B7F8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[0x12]; u16 f_18; u8 pad1A[0x16]; s16 f_30; } S_P_8008B7F8_8008B7F8;

extern s32 D_800B3384;
extern M2C_UNK g_RcCar;
void Camera_Translate(s32, s32, s32);
extern s16 D_800EC238;
extern S_4D64_8008A91C_8008A91C *D_800B4D64;
s32 Platform_CarryRiders(s32 unused, SVECTOR *d, s16 id);
s16 func_800889EC(u16 *b);
/* Moves a rider (Spike / RC car) with a rotating platform: rotates its offset d from the centre c
 * by the platform's turn this frame about Y (+0x2C), X (+0x2A) or Z (+0x2E) - the angle comes from
 * Platform_TurnStep(speed, +0x36) - and writes the new position to out. For X/Z turns a result that
 * rounds back to the old coordinate is pushed by 1 so slow turns still move. Returns 0. */
s32 Platform_RotatePoint(S_P_8008AD14_8008AD14 *p, SV_8008AD14_8008AD14 *c, SV_8008AD14_8008AD14 *d, s32 *out);
extern s32 D_800B3388;
extern struct S_D_800EC1E0 { u8 pad0[0x30]; s16 f_30; u8 pad32[6]; s16 f_38; u8 pad3A[0x36]; s32 f_70; } g_Spike;
struct Game_80088F2C { u8 pad0[0x8126]; u16 stage; };
extern struct Game_80088F2C g_Game;
s32 func_8008B3A4(Blk_80088F2C_80088F2C *, s32, s32, s16 *);
void Sound_PlayFixed(s32);
s32 rcos(s32);
s32 rsin(s32);
s32 Platform_TurnStep(s16 period, s16 t);
void func_8013FC18(s32, s32);
void Spike_SetState(s32);
struct S_D_800EC350_8008A4B0 { u8 pad_0[0x8126]; u16 f_8126; };
struct Game_88AB8 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x108]; Zone_88AB8_80088AB8 *f_820C; u8 pad8210[0x74]; s16 f_8284; u8 pad8286[0xA]; s16 f_8290; };
extern Zone_88AB8_80088AB8 *D_800B3340;
extern void (*D_800B3344[])(Zone_88AB8_80088AB8 *, s16);
extern s32 D_800B3380;
s32 Platform_ProcessEvents();
struct Game_892C4 { u8 pad0[0x8214]; Wp_892C4_800892C4 *f_8214; };
s32 Platform_RotateRiders(S_P_8008ABB0_8008ABB0 *p, SVECTOR *c, s16 id);
s32 func_8008B060(Plat_892C4_800892C4 *);
s32 func_8008B228(S_P_8008B228_8008B228 *p);
struct Game_895F0 { u8 pad0[0x820C]; Obj_895F0_800895F0 *f_820C; };
void RotMatrixZYX(SVECTOR *, void *);
struct S_D_800F4350_8008B7F8 { u8 pad0[0x20C]; S_820C_8008B7F8_8008B7F8 *f_20C; u8 pad210[4]; S_8214_8008B7F8_8008B7F8 *f_214; S_Ev_8008B7F8_8008B7F8 *f_218; };
extern M2C_UNK D_800F4350;
s32 Vec_Length(s32, s32, s32);
void Platform_RunTrigger(S_P_8008B7F8_8008B7F8 *, S_Ev_8008B7F8_8008B7F8 *, s32, s16);
struct S_D_800EC1E0_8008B7F8 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };

INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", func_80088670);

s32 func_800889A4(void) {
    return D_800B3384;
}

s32 func_800889B4(s16 a, s16 b) {
    if (a < 0) {
        if (b < 0) {
            return 1;
        }
        return 0x1000;
    }
    if (b < 0) {
        return 0x10;
    }
    return 0x100;
}

s16 func_800889EC(u16 *b)
{
  u16 b0 = b[0];
  u16 b3 = b[3];
  u16 b2 = b[2];
  u16 b5 = b[5];
  s16 x1 = b0 + b3;
  s16 z1 = b2 + b5;
  s16 x0;
  s16 z0;
  unsigned short r = func_800889B4(x1, z1);
  x0 = b0 - b3;
  r |= func_800889B4(x0, z1);
  z0 = b2 - b5;
  r |= func_800889B4(x0, z0);
  r |= func_800889B4(x1, z0);
  return r;
}

s32 Zone_UpdateAll(void) {
    s32 i;
    Zone_88AB8_80088AB8 *z;
    u32 k;
    u32 t;

    if ((*(struct Game_88AB8 *)&g_Game).f_8100 & 8) {
        return 0;
    }
    for (i = (*(struct Game_88AB8 *)&g_Game).f_8284 - 1; i >= 0; i--) {
        z = (Zone_88AB8_80088AB8 *)(i * 0x38 + (s32)(*(struct Game_88AB8 *)&g_Game).f_820C);
        D_800B3380 = i;
        k = z->f_18 & 0xF;
        if (k == 3) {
            continue;
        }
        if (k == 1) {
            if (z->f_30 >= 0) {
                Platform_ProcessEvents(z, (s16)i);
            }
            continue;
        }
        *D_800B3340 = *z;
        t = D_800B3340->type;
        if (t < 2) {
            (*(struct Game_88AB8 *)&g_Game).f_8290 = i;
        }
        D_800B3344[t](D_800B3340, i);
        Platform_ProcessEvents(D_800B3340, (s16)i);
        *(Zone_88AB8_80088AB8 *)(i * 0x38 + (u8 *)(*(struct Game_88AB8 *)&g_Game).f_820C) = *D_800B3340;
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; u8 pad10[0xC]; u16 f_1C; u8 pad1E[0x14]; s16 f_32; s16 f_34; } Blk_FallBlock;
struct Game_FallBlock { u8 pad0[0x8298]; s16 f_8298; };
/* Copies p's position to o; for type 0x4000 (p+0x10 & 0xF000) moves it by half the x/z sizes
 * (+6/+0xA) towards the corner picked by direction p+0x10 & 0xF00 (0: +x+z, 0x400: +x-z,
 * 0x800: -x-z, 0xC00: -x+z). */
s32 Block_GetCornerPos();
s32 Floor_GetHeight(s32, s32, s32);

/* Falling block: once triggered (+0x32 > 0) it shakes up and down by 32 each frame while the
 * counter runs down, then falls with gravity (+0x1C += 8) until it lands on the floor below
 * (Block_GetCornerPos / Floor_GetHeight; a floor over scratchpad kind 1 counts as none). Moves its
 * model with it; removed below y 0xC00. Returns 0. */
s32 FallBlock_Update(Blk_FallBlock *o) {
    SVECTOR p;
    s16 *scr = (s16 *)0x1F8003F0;
    s32 g;
    s32 dy;
    s16 n;
    u16 y;
    if (o->f_2 > 0xC00) {
        if (o->f_E >= 0) {
            (*(Mdl_80088F2C_80088F2C **)&D_800B4D64)[o->f_E].f_16 = 0;
        }
        return 0;
    }
    Block_GetCornerPos(o, &p);
    ((struct Game_FallBlock *)&g_Game)->f_8298 = 1;
    g = Floor_GetHeight(p.vx, p.vy, p.vz);
    if ((s16)((u16 *)scr)[4] == 1 && scr[0] < 0) {
        g = 0x7FFF;
    }
    if (o->f_32 > 0) {
        if (o->f_2 >= (s16)g) {
            o->f_1C = 0;
            o->f_34 = 0;
            return 0;
        }
        do {
            n = o->f_32 - 1;
            o->f_32 = n;
        } while (0);
        dy = (1 - (s16)(n % 2) * 2) * 32;
        if (o->f_E >= 0) {
            (*(Mdl_80088F2C_80088F2C **)&D_800B4D64)[o->f_E].f_12 += dy;
        }
        o->f_2 += dy;
        return 0;
    } else {
        dy = o->f_1C + 8;
        o->f_1C = dy;
        y = o->f_2;
        if (o->f_2 + (s16)dy > (s16)g) {
            dy = g - y;
            o->f_1C = 0;
            o->f_34 = 0;
        }
    }
    if (o->f_E >= 0) {
        (*(Mdl_80088F2C_80088F2C **)&D_800B4D64)[o->f_E].f_12 += dy;
    }
    o->f_2 += dy;
    return 0;
}

/* Pushable block. While Spike pushes it (his state kind +0x70 & 0xF0 == 0x70 and the block's
 * +0x32 >= 0) it moves by his push velocity (+0x30/+0x38), halved until the spot is free
 * (func_8008B3A4), settles onto the floor and plays a scraping sound every 24 frames
 * (0xAE in stage 0xB, 0xB1 in stages 0xF and 0x65). Otherwise it keeps sliding by its last
 * step (+0x34/+0x36) while the floor ahead is lower and falls with gravity (+0x1C += 16).
 * Below y 0xC00 it is removed. Moves its model and riders; returns 0. */
s32 PushBlock_Update(Blk_80088F2C_80088F2C *o, s16 id) {
    SVECTOR d;
    s16 h[2];
    s16 hx;
    s16 hz;
    d.vz = 0;
    d.vy = 0;
    d.vx = 0;
    if (o->f_2 > 0xC00) {
        if (o->f_E >= 0) {
            (*(Mdl_80088F2C_80088F2C * *)&D_800B4D64)[o->f_E].f_16 = 0;
        }
        o->f_18 = (o->f_18 & 0x8000) | 1;
        return 0;
    }
    if (D_800B3388 > 0) {
        D_800B3388--;
    }
    if (o->f_32 < 0 || (g_Spike.f_70 & 0xF0) != 0x70) {
        func_8008B3A4(o, 0, 0, &h[0]);
        if ((o->f_34 != 0 || o->f_36 != 0) && (func_8008B3A4(o, o->f_34, o->f_36, &h[1]), h[0] < h[1])) {
            d.vx = o->f_34; d.vz = o->f_36; h[0] = h[1];
        } else {
            d.vz = 0;
            d.vx = 0;
        }
        d.vy = o->f_1C += 0x10;
        if (o->f_2 + d.vy > h[0]) {
            d.vy = h[0] - o->f_2;
            if (d.vy == 0) {
                d.vz = 0;
                d.vx = 0;
            }
            o->f_1C = 0;
        }
        } else {
        d.vx = g_Spike.f_30;
        d.vz = g_Spike.f_38;
        while (func_8008B3A4(o, d.vx, d.vz, &h[0]) != 0) {
            hx = d.vx / 2;
            hz = d.vz / 2;
            if (hx == 0 && hz == 0) {
                d.vz = 0;
                d.vx = 0;
                break;
            }
            d.vx -= hx;
            d.vz -= hz;
        }
        o->f_1C = 0x20;
        d.vy = 0x20;
        if (h[0] < o->f_2 + 0x20) {
            d.vy = h[0] - o->f_2;
            o->f_1C = 0;
        }
        if (D_800B3388 == 0) {
            D_800B3388 = 0x18;
            if (g_Game.stage == 0xB) {
                Sound_PlayFixed(0xAE);
            } else if (g_Game.stage == 0xF || g_Game.stage == 0x65) {
                Sound_PlayFixed(0xB1);
            }
        }
    }
    if (o->f_E >= 0) {
        (*(Mdl_80088F2C_80088F2C * *)&D_800B4D64)[o->f_E].f_10 += d.vx;
        (*(Mdl_80088F2C_80088F2C * *)&D_800B4D64)[o->f_E].f_12 += d.vy;
        (*(Mdl_80088F2C_80088F2C * *)&D_800B4D64)[o->f_E].f_14 += d.vz;
    }
    Platform_CarryRiders((s32)o, &d, id);
    o->f_0 += d.vx;
    o->f_2 += d.vy;
    o->f_4 += d.vz;
    o->f_34 = d.vx;
    o->f_36 = d.vz;
    o->f_20 = func_800889EC(o);
    return 0;
}

s32 Platform_GlideToWaypoint(Plat_892C4_800892C4 *o, s32 id) {
    Wp_892C4_800892C4 *w;
    s32 dx;
    s32 dy;
    s32 dz;
    s16 nx;
    s16 ny;
    s16 nz;
    SV_892C4_800892C4 d;

    if (o->f_22 < 0) {
        return 0;
    }
    w = &(*(struct Game_892C4 *)&g_Game).f_8214[o->f_22];
    dx = o->f_C * (w->x - o->f_24) / (w->f_C * 2);
    dy = o->f_C * (w->y - o->f_26) / (w->f_C * 2);
    dz = o->f_C * (w->z - o->f_28) / (w->f_C * 2);
    nx = o->f_24 + dx;
    ny = o->f_26 + dy;
    nz = o->f_28 + dz;
    d.vx = nx - o->x;
    d.vy = ny - o->y;
    d.vz = nz - o->z;
    Platform_CarryRiders((s32)o, &d, id);
    d.vx = nx;
    d.vy = ny;
    d.vz = nz;
    Platform_RotateRiders((S_P_8008ABB0_8008ABB0 *)o, (SVECTOR *)&d, id);
    if (o->f_E >= 0) {
        (*(Mdl_892C4_800892C4 * *)&D_800B4D64)[o->f_E].f_10 = nx;
        (*(Mdl_892C4_800892C4 * *)&D_800B4D64)[o->f_E].f_12 = ny;
        (*(Mdl_892C4_800892C4 * *)&D_800B4D64)[o->f_E].f_14 = nz;
        func_8008B060(o);
    }
    o->x = nx;
    o->y = ny;
    o->z = nz;
    o->f_20 = func_800889EC(o);
    func_8008B228(o);
    o->f_C++;
    o->f_32++;
    if (o->f_C < w->f_C * 2) {
        return 0;
    }
    o->f_C = 0;
    o->f_22 = w->next;
    if ((*(struct Game_892C4 *)&g_Game).f_8214[o->f_22].f_C <= 0) {
        o->f_24 = (*(struct Game_892C4 *)&g_Game).f_8214[o->f_22].x;
        o->f_26 = (*(struct Game_892C4 *)&g_Game).f_8214[o->f_22].y;
        o->f_28 = (*(struct Game_892C4 *)&g_Game).f_8214[o->f_22].z;
        o->f_22 = (*(struct Game_892C4 *)&g_Game).f_8214[o->f_22].next;
        o->f_32 = 0;
    } else {
        o->f_24 = w->x;
        o->f_26 = w->y;
        o->f_28 = w->z;
    }
    return 0;
}

/* Moves a platform around a circle of radius f_1A centred on its start position (or on object
   f_22), one step of period f_1C per frame; f_12 & 0xF000 reverses the direction. The plane comes
   from f_12 & 0xF00: 0x100 horizontal (X/Z), 0x200 Y/Z, otherwise X/Y. Kind (f_12 & 0xFF) 5 also
   bobs up and down with its own period f_34, kind 4 offsets the model by f_8 and kind 3 turns the
   model with the angle. Riders are carried along. */
s32 Platform_UpdateOrbit(Plat_895F0_800895F0 *p, s16 id) {
    SVECTOR r;
    SVECTOR d;
    s16 kind;
    s16 axis;
    s16 cx, cy, cz;
    s16 nx, ny, nz;
    s32 a;
    s32 a2;
    s32 t;

    kind = p->f_12 & 0xFF;
    axis = p->f_12 & 0xF00;
    if (p->f_22 < 0) {
        cx = p->x;
        cy = p->y;
        cz = p->z;
    } else {
        cx = (*(struct Game_895F0 *)&g_Game).f_820C[p->f_22].x;
        cy = (*(struct Game_895F0 *)&g_Game).f_820C[p->f_22].y;
        cz = (*(struct Game_895F0 *)&g_Game).f_820C[p->f_22].z;
    }
    a = (p->f_C << 12) / p->f_1C;
    if (kind == 5) {
        a2 = (p->f_32 << 12) / p->f_34;
    }
    if (axis == 0x100) {
        nx = cx + p->f_1A * rsin(a) / 4096;
        if (kind == 5) {
            t = rsin(a2) / 32 - 0x80;
            ny = cy + t;
        } else {
            ny = cy;
        }
        nz = cz + p->f_1A * rcos(a) / 4096;
    } else if (axis == 0x200) {
        nx = cx;
        ny = cy + p->f_1A * rcos(a) / 4096;
        nz = cz + p->f_1A * rsin(a) / 4096;
    } else {
        nx = cx + p->f_1A * rcos(a) / 4096;
        ny = cy + p->f_1A * rsin(a) / 4096;
        nz = cz;
    }
    d.vx = nx - p->x;
    d.vy = ny - p->y;
    d.vz = nz - p->z;
    Platform_CarryRiders((s32)p, &d, id);
    d.vx = nx;
    d.vy = ny;
    d.vz = nz;
    Platform_RotateRiders(p, &d, id);
    if (p->f_E >= 0) {
        if (axis == 0x100) {
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_10 = nx;
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_14 = nz;
        } else if (axis == 0x200) {
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_12 = ny;
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_14 = nz;
        } else {
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_10 = nx;
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_12 = ny;
        }
        if (kind == 4) {
            (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_12 -= p->f_8;
        }
        if (func_8008B060(p) == 0 && axis == 0x100 && kind == 3) {
            r.vx = 0;
            r.vy = a;
            r.vz = 0;
            RotMatrixZYX(&r, (*(Mdl_895F0_800895F0 * *)&D_800B4D64)[p->f_E].f_1C);
        }
    }
    if (axis == 0x100) {
        p->x = nx;
        p->z = nz;
    } else if (axis == 0x200) {
        p->y = ny;
        p->z = nz;
    } else {
        p->x = nx;
        p->y = ny;
    }
    p->f_20 = func_800889EC(p);
    func_8008B228(p);
    if ((p->f_12 & 0xF000) == 0) {
        if (++p->f_C > p->f_1C) {
            p->f_C -= p->f_1C;
        }
        if (kind == 5) {
            if (++p->f_32 > p->f_34) {
                p->f_32 -= p->f_34;
            }
        }
    } else {
        if (--p->f_C < 0) {
            p->f_C += p->f_1C;
        }
        if (kind == 5) {
            if (--p->f_32 < 0) {
                p->f_32 += p->f_34;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", func_80089B10);

s32 func_80089D64(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", Platform_ReachWaypoint);

/* A moving platform (direction +0x2A/+0x2C/+0x2E times speed +0x1C per frame) carries what stands
 * in its box (half sizes +6 / +0xA, from its top +2 up to +8 above). Spike: type 0x300 adds the
 * step to his velocity (half of it while in the 0x80 state group), moves the camera and, if he is
 * in the 0x60 group and the move puts him below the floor, sets state 8; 0x800 hands the step to
 * the overlay (func_8013FC18, also for 0x300 in stage 0x1D); 0x100 moves him only in the 0xC0 group;
 * other types move him and the camera directly. The RC car is moved directly unless the type is
 * 0x300 or 0x800. Returns 0. */
s32 Platform_MoveRiders(Plat_8008A4B0_8008A4B0 *p) {
    s16 dx;
    s16 dy;
    s16 dz;
    s16 type;
    s16 yoff;

    dx = dy = dz = 0;
    type = p->flags & 0xF00;
    if ((s16)p->dx != 0) {
        dx = p->dx * p->speed;
    }
    if ((s16)p->dy != 0) {
        dy = p->dy * p->speed;
    }
    if ((s16)p->dz != 0) {
        dz = p->dz * p->speed;
    }
    yoff = 0;
    if (type == 0x300 && ((*(Body_8008A4B0_8008A4B0 *)&g_Spike).f_70 & 0xF0) == 0x60) {
        yoff = (*(Body_8008A4B0_8008A4B0 *)&g_Spike).f_46;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_Spike).x >= p->x - p->hx && (*(Body_8008A4B0_8008A4B0 *)&g_Spike).x <= p->x + p->hx && (*(Body_8008A4B0_8008A4B0 *)&g_Spike).z >= p->z - p->hz && (*(Body_8008A4B0_8008A4B0 *)&g_Spike).z <= p->z + p->hz
        && (*(Body_8008A4B0_8008A4B0 *)&g_Spike).y + yoff >= p->y - p->hy && (*(Body_8008A4B0_8008A4B0 *)&g_Spike).y + yoff <= p->y) {
        switch (type) {
        case 0x800:
            func_8013FC18(dx, dz);
            break;
        case 0x300:
            if (((struct S_D_800EC350_8008A4B0 *)&g_Game)->f_8126 == 0x1D) {
                func_8013FC18(dx, dz);
            }
            if (((*(Body_8008A4B0_8008A4B0 *)&g_Spike).f_70 & 0xF0) == 0x80) {
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vx += dx / 2;
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vy += dy / 2;
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vz += dz / 2;
            } else {
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vx += dx;
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vy += dy;
                (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vz += dz;
            }
            Camera_Translate(dx, 0, dz);
            if (((*(Body_8008A4B0_8008A4B0 *)&g_Spike).f_70 & 0xF0) == 0x60) {
                if (Floor_GetHeight((*(Body_8008A4B0_8008A4B0 *)&g_Spike).x + (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vx, (*(Body_8008A4B0_8008A4B0 *)&g_Spike).y + (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vy, (*(Body_8008A4B0_8008A4B0 *)&g_Spike).z + (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vz) > (*(Body_8008A4B0_8008A4B0 *)&g_Spike).y + (*(Body_8008A4B0_8008A4B0 *)&g_Spike).vy) {
                    Spike_SetState(8);
                }
            }
            break;
        case 0x100:
            if (((*(Body_8008A4B0_8008A4B0 *)&g_Spike).f_70 & 0xF0) != 0xC0) {
                break;
            }
        default:
            (*(Body_8008A4B0_8008A4B0 *)&g_Spike).x += dx;
            (*(Body_8008A4B0_8008A4B0 *)&g_Spike).y += dy;
            (*(Body_8008A4B0_8008A4B0 *)&g_Spike).z += dz;
            Camera_Translate(dx, dy, dz);
            break;
        }
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).f_70 == 0) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).x < p->x - p->hx) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).x > p->x + p->hx) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).z < p->z - p->hz) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).z > p->z + p->hz) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).y < p->y - p->hy) {
        return 0;
    }
    if ((*(Body_8008A4B0_8008A4B0 *)&g_RcCar).y > p->y) {
        return 0;
    }
    if (type != 0x300 && type != 0x800) {
        (*(Body_8008A4B0_8008A4B0 *)&g_RcCar).x += dx;
        (*(Body_8008A4B0_8008A4B0 *)&g_RcCar).y += dy;
        (*(Body_8008A4B0_8008A4B0 *)&g_RcCar).z += dz;
    }
    return 0;
}

/* Moves a platform by its velocity, carries Spike/the second rider along, applies
 * its rotation to Spike while he stands on it, and updates its model.
 */
s32 Platform_Move(S_Plat_8008A91C_8008A91C *p, s16 id) {
    SVECTOR d;
    d.vx = p->f_0 - p->f_24;
    d.vy = p->f_2 - p->f_26;
    d.vz = p->f_4 - p->f_28;
    Platform_CarryRiders((s32)p, &d, id);
    if (D_800EC238 == id) {
        if (p->f_2A != 0 || p->f_2C != 0 || p->f_2E != 0) {
            ((S_EC1E0_8008A91C_8008A91C *)&g_Spike)->f_60 = p->f_2A;
            ((S_EC1E0_8008A91C_8008A91C *)&g_Spike)->f_62 = p->f_2C;
            ((S_EC1E0_8008A91C_8008A91C *)&g_Spike)->f_64 = p->f_2E;
        }
    }
    if (p->f_E >= 0) {
        D_800B4D64[p->f_E].f_10 = p->f_0;
        D_800B4D64[p->f_E].f_12 = p->f_2;
        D_800B4D64[p->f_E].f_14 = p->f_4;
    }
    p->f_24 = p->f_0;
    p->f_26 = p->f_2;
    p->f_28 = p->f_4;
    p->f_20 = func_800889EC(p);
    return 0;
}

s32 func_8008AA64(void) {
    return 0;
}

/* Moves Spike and the second rider object by the platform's delta `d` when they
 * stand on platform `id` and the step is small.
 */
s32 Platform_CarryRiders(s32 unused, SVECTOR *d, s16 id) {
    S_Obj_8008AA6C_8008AA6C *o;
    s32 x = d->vx;
    if (ABS(x) > 0x200) {
        return 0;
    }
    if (ABS(d->vy) > 0x400) {
        return 0;
    }
    if (ABS(d->vz) > 0x200) {
        return 0;
    }
    o = (S_Obj_8008AA6C_8008AA6C *)&g_Spike;
    if (o->f_58 == id) {
        o->f_24 += x;
        o->f_28 += d->vy;
        o->f_2C += d->vz;
        Camera_Translate(d->vx, d->vy, d->vz);
    }
    o = (S_Obj_8008AA6C_8008AA6C *)&g_RcCar;
    if (o->f_58 == id) {
        o->f_24 += d->vx;
        o->f_28 += d->vy;
        o->f_2C += d->vz;
    }
    return 0;
}

/* Rotating platforms: moves Spike and the second rider around the pivot `c`.
 */
s32 Platform_RotateRiders(S_P_8008ABB0_8008ABB0 *p, SVECTOR *c, s16 id)
{
  SVECTOR d;
  SVECTOR r;
  SVECTOR s;
  S_Obj_8008ABB0_8008ABB0 *o;
  if ((p->f_10 & 0xF000) != 0x3000)
  {
    return 0;
  }
  o = (S_Obj_8008ABB0_8008ABB0 *) (&g_Spike);
  if (o->f_58 == id)
  {
    d.vx = o->f_24 - c->vx;
    d.vy = o->f_28 - c->vy;
    d.vz = o->f_2C - c->vz;
    s.vx = o->f_24;
    s.vy = o->f_28;
    s.vz = o->f_2C;
    Platform_RotatePoint(p, c, &d, &o->f_24);
    r.vx = o->f_24 - s.vx;
    r.vy = o->f_28 - s.vy;
    r.vz = o->f_2C - s.vz;
    Camera_Translate(r.vx, r.vy, r.vz);
  }
  ;
  if (((S_Obj_8008ABB0_8008ABB0 *) (&g_RcCar))->f_58 == id)
  {
    d.vx = ((S_Obj_8008ABB0_8008ABB0 *) (&g_RcCar))->f_24 - c->vx;
    d.vy = ((S_Obj_8008ABB0_8008ABB0 *) (&g_RcCar))->f_28 - c->vy;
    d.vz = ((S_Obj_8008ABB0_8008ABB0 *) (&g_RcCar))->f_2C - c->vz;
    Platform_RotatePoint(p, c, &d, &((S_Obj_8008ABB0_8008ABB0 *) (&g_RcCar))->f_24);
  }
  return 0;
}

s32 Platform_RotatePoint(S_P_8008AD14_8008AD14 *p, SV_8008AD14_8008AD14 *c, SV_8008AD14_8008AD14 *d, s32 *out) {
    s32 a;
    s32 cs;
    s32 sn;

    if (p->ry != 0) {
        a = Platform_TurnStep(p->ry, p->f_36);
        cs = rcos(a);
        sn = rsin(a);
        out[0] = c->vx + (d->vx * cs - d->vz * sn) / 4096;
        out[2] = c->vz + (d->vx * sn + d->vz * cs) / 4096;
    } else if (p->rx != 0) {
        a = Platform_TurnStep(p->rx, p->f_36);
        cs = rcos(a);
        sn = rsin(a);
        out[2] = c->vz + (d->vz * cs - d->vy * sn) / 4096;
        if (out[2] == c->vz + d->vz) {
            if (d->vz > 0) {
                out[2] = out[2] + 1;
            } else {
                out[2] = out[2] - 1;
            }
        }
        out[1] = c->vy + (d->vz * sn + d->vy * cs) / 4096;
    } else if (p->rz != 0) {
        a = Platform_TurnStep(p->rz, p->f_36);
        cs = rcos(a);
        sn = rsin(a);
        out[0] = c->vx + (d->vx * cs - d->vy * sn) / 4096;
        if (out[0] == c->vx + d->vx) {
            if (d->vx > 0) {
                out[0] = out[0] + 1;
            } else {
                out[0] = out[0] - 1;
            }
        }
        out[1] = c->vy + (d->vx * sn + d->vy * cs) / 4096;
    }
    return 0;
}

/* Angle turned between frame t - 1 and t of a full turn lasting |period| frames (0x1000 per
 * turn, wrapping; a negative period turns the other way). */
s32 Platform_TurnStep(s16 period, s16 t) {
    s32 cur = (t << 12) / period;
    s32 p;

    if (period > 0) {
        p = t - 1;
        if (p < 0) {
            p += period;
        }
    } else if (period < 0) {
        p = t + 1;
        if (period < p) {
            p -= period;
        }
    }
    p = (p << 12) / period;
    if (period < 0) {
        p = -p;
        cur = -cur;
    }
    return cur - p;
}

INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", func_8008B060);

s32 func_8008B228(S_P_8008B228_8008B228 *p) {
    s16 t;
    if ((p->f_10 & 0xF000) != 0x3000) {
        return 0;
    }
    if (p->f_2C != 0) {
        if (p->f_2C > 0) {
            t = p->f_36 + 1;
            p->f_36 = t;
            if (p->f_2C < t) {
                p->f_36 = t - p->f_2C;
            }
        } else if (p->f_2C < 0) {
            t = p->f_36 - 1;
            p->f_36 = t;
            if (t < p->f_2C) {
                p->f_36 = t - p->f_2C;
            }
        }
    } else if (p->f_2A != 0) {
        if (p->f_2A > 0) {
            t = p->f_36 + 1;
            p->f_36 = t;
            if (p->f_2A < t) {
                p->f_36 = t - p->f_2A;
            }
        } else if (p->f_2A < 0) {
            t = p->f_36 - 1;
            p->f_36 = t;
            if (t < p->f_2A) {
                p->f_36 = t - p->f_2A;
            }
        }
    } else if (p->f_2E != 0) {
        if (p->f_2E > 0) {
            t = p->f_36 + 1;
            p->f_36 = t;
            if (p->f_2E < t) {
                p->f_36 = t - p->f_2E;
            }
        } else if (p->f_2E < 0) {
            t = p->f_36 - 1;
            p->f_36 = t;
            if (t < p->f_2E) {
                p->f_36 = t - p->f_2E;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", func_8008B3A4);

s32 Platform_ProcessEvents(p, id)
    S_P_8008B7F8_8008B7F8 *p;
    s16 id;
{
    struct S_D_800F4350_8008B7F8 *g;
    S_Ev_8008B7F8_8008B7F8 *e;
    s16 k = p->f_30;
    s32 d;
    if (k < 0) {
        return 0;
    }
    d = Vec_Length(((struct S_D_800EC1E0_8008B7F8 *)&g_Spike)->f_24 - p->f_0, ((struct S_D_800EC1E0_8008B7F8 *)&g_Spike)->f_28 - p->f_2, ((struct S_D_800EC1E0_8008B7F8 *)&g_Spike)->f_2C - p->f_4);
    g = (struct S_D_800F4350_8008B7F8 *)&D_800F4350;
    p->f_18 &= 0xFEFF;
    do {
        e = &g->f_218[k];
        switch (e->f_0) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
            break;
        case 3:
            Platform_RunTrigger(p, e, d, id);
            break;
        case 5:
            if (e->f_2 == 0x50 && e->f_4 >= 0 && e->f_6 >= 0) {
                if ((g->f_20C[e->f_4].f_18 & 0xF) == 1) {
                    g->f_214[e->f_6].f_E = e->f_8;
                } else {
                    g->f_214[e->f_6].f_E = e->f_A;
                }
            }
            break;
        }
        k = e->f_E;
    } while (k >= 0);
    return 0;
}



INCLUDE_ASM("asm/nonmatchings/game/80088670_platform", Platform_RunTrigger);

INCLUDE_RODATA("asm/nonmatchings/game/80088670_platform", jtbl_800A62D0);
INCLUDE_RODATA("asm/nonmatchings/game/80088670_platform", jtbl_800A62D0_pad);


s32 func_8008BDB4(S_8BDB4_8008BDB4 *a) {
    a->f_18 = (a->f_18 & 0x8000) | 1;
    a->f_0 = a->f_24;
    a->f_2 = a->f_26;
    a->f_4 = a->f_28;
    if (a->f_E >= 0) {
        (*(S_4D64_8008BDB4 * *)&D_800B4D64)[a->f_E].f_10 = a->f_0;
        (*(S_4D64_8008BDB4 * *)&D_800B4D64)[a->f_E].f_12 = a->f_2;
        (*(S_4D64_8008BDB4 * *)&D_800B4D64)[a->f_E].f_14 = a->f_4;
        (*(S_4D64_8008BDB4 * *)&D_800B4D64)[a->f_E].f_16 = 0xFFFF;
    }
    a->f_32 = 0;
    a->f_C = 0;
    return 0;
}

s32 Block_GetCornerPos(S_P_8008BE4C_8008BE4C *p, SVECTOR *o) {
    o->vx = p->f_0;
    o->vy = p->f_2;
    o->vz = p->f_4;
    if ((p->f_10 & 0xF000) != 0x4000) {
        return 0;
    }
    switch (p->f_10 & 0xF00) {
    case 0:
        o->vx += p->f_6 / 2;
        o->vz += p->f_A / 2;
        break;
    case 0x400:
        o->vx += p->f_6 / 2;
        o->vz -= p->f_A / 2;
        break;
    case 0x800:
        o->vx -= p->f_6 / 2;
        o->vz -= p->f_A / 2;
        break;
    case 0xC00:
        o->vx -= p->f_6 / 2;
        o->vz += p->f_A / 2;
        break;
    }
    return 0;
}
