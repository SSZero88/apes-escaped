#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { u8 pad0[0xA]; s16 unkA; s16 unkC; u8 unkE; u8 padF[5]; s16 unk14; u8 pad16[0x38]; u8 unk4E; u8 pad4F[5]; } S_BAF00;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_80070130_80070130;
typedef struct { SVECTOR f_0; u8 pad8[0x18]; MAT_80070130_80070130 f_20; u8 pad40[0xE]; u8 f_4E; u8 pad4F[5]; } S_Obj_80070130_80070130;
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; s16 f_22; u16 f_24; u16 f_26; u8 pad28[4]; u32 f_2C; } Coll_8006FEE8_8006FEE8;
typedef struct { s16 vx, vy, vz, pad; } SV_70D94_80070D94;
typedef struct { u8 f_0; u8 f_1; u16 f_2; } PuffGfx_80070D94;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_71370_80071370;
typedef struct { s16 vx, vy, vz; } SV3_71370_80071370;
typedef struct { u8 pad[0x20]; } Mdl_71370_80071370;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_71370_80071370;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; Db_71370_80071370 db[2]; } Game_71370_80071370;

extern u8 D_800B1BD0;

extern struct S_D_800BAF00 { u8 pad_0[0x4A]; s8 f_4A; u8 pad_4B[0x9]; } g_Shockwaves[];

extern s8 D_800B205C;
extern M2C_UNK D_800BB840;

void func_80070130(SVECTOR *pos, S_Obj_80070130_80070130 *tmpl, s32 n, s32 base, s32 step, s32 flag);
extern struct S_D_800BB920 { u8 pad_0[0x3C]; s8 f_3C; u8 pad_3D[0x7]; } D_800BB920[];
extern MAT_80070130_80070130 D_800B1BB0;
void Matrix_FromDirection(s32, MAT_80070130_80070130 *);
S_BAF00 *func_8006FE7C(void);
int abs(int);
void Shockwave_Draw(struct S_D_800BAF00 *);
Coll_8006FEE8_8006FEE8 *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);
struct S_D_800BAF00_8006FEE8 { s16 x, y, z; u8 pad6[2]; u16 f_8; u8 padA[6]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[6]; s32 f_1C; u8 pad20[0x20]; s32 f_40; s16 f_44; s16 f_46; s16 f_48; u8 life; u8 armed; u16 f_4C; u8 delay; u8 pad4F; Coll_8006FEE8_8006FEE8 *coll; };
extern u32 D_800B2054[];
extern u16 g_RandSeed;
struct S_D_800BB840_80070B70 { u32 *f_0; void *f_4; s16 f_8; s16 f_A; s16 f_C; u8 padE[2]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[2]; u8 f_18; u8 f_19; s16 f_1A; };
extern u8 D_800B1B78[];
void func_8006F3D0(SV_70D94_80070D94 *, s32, u8 *, s32);
struct S_D_800BB840_80070D94 { PuffGfx_80070D94 *f_0; void *f_4; s16 f_8; s16 f_A; s16 f_C; u8 padE[2]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[2]; s8 f_18; u8 f_19; u16 f_1A; };
extern Game_71370_80071370 g_Game;
extern Mdl_71370_80071370 *D_800B4D64;
extern MAT_71370_80071370 D_800E78C0;
extern u8 D_800E7D00[];
void RotMatrixZYX(SV3_71370_80071370 *, MAT_71370_80071370 *);
void MulMatrix0(MAT_71370_80071370 *, MAT_71370_80071370 *, MAT_71370_80071370 *);
void CompMatrix(MAT_71370_80071370 *, MAT_71370_80071370 *, MAT_71370_80071370 *);
void Model_ProjectVertsAlt(Mdl_71370_80071370 *, MAT_71370_80071370 *, u8 *);
void func_80017E5C(u32 *, u8 *, Mdl_71370_80071370 *);
void Effect_SpawnAt(s32, void *);
struct S_D_800BB920_80071370 { MAT_71370_80071370 base; SV3_71370_80071370 rot; u8 pad26[2]; SV3_71370_80071370 rv; u8 pad2E[2]; s16 x, y, z; s16 vx; s16 vy; s16 vz; s8 bounces; u8 timer; s16 floor; s16 model; u8 pad42[2]; };

INCLUDE_ASM("asm/nonmatchings/game/8006FA10", Shockwave_Draw);

void func_8006FE54(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        g_Shockwaves[i].f_4A = 0;
    }
}

S_BAF00 *func_8006FE7C(void) {
    S_BAF00 *p = &g_Shockwaves[D_800B1BD0];
    p->unkE = 0x10;
    p->unk4E = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unk14 = 0;
    D_800B1BD0 = (D_800B1BD0 + 1) % 16;
    return p;
}

/* Updates the 16 shockwave rings (g_Shockwaves, 0x54 bytes each): after an optional delay each
 * ring lives `life` frames, rising and spreading with damped velocities (x7/8, x15/16 per frame).
 * While armed it registers a ring-shaped collision entry (type 0x10, radii +0x10 / +0x12); it
 * disarms once that entry has been turned into a hit (type 6). */
void Shockwave_UpdateAll(void)
{
  s32 i;
  struct S_D_800BAF00_8006FEE8 *e;
  s32 d;
  short r;
  for (i = 15, e = ((struct S_D_800BAF00_8006FEE8 *)&g_Shockwaves); i >= 0; i--, e++)
  {
    if (e->life == 0)
    {
      continue;
    }
    if (e->delay != 0)
    {
      e->delay--;
      continue;
    }
    e->life--;
    Shockwave_Draw(e);
    e->f_1C -= e->f_40;
    e->f_8 += e->f_44;
    e->f_10 += e->f_46;
    e->f_12 += e->f_48;
    e->f_14 = (e->f_14 * 7) / 8;
    e->f_44 = (e->f_44 * 7) / 8;
    e->f_46 = (e->f_46 * 15) / 16;
    e->f_48 = (e->f_48 * 15) / 16;
    if ((e->coll != 0) && ((e->coll->f_2C >> 28) == 6))
    {
      e->armed = 0;
      continue;
    }
    if (e->armed == 0)
    {
      continue;
    }
    if ((e->coll = CollShape_Alloc()) == 0)
    {
      continue;
    }
    d = abs((s16) (e->f_10 - e->f_12));
    r = (((s16) d) < 0x49) ? (d) : (d - 0x40);
    e->coll->x = e->x;
    e->coll->y = e->y;
    e->coll->z = e->z;
    e->coll->f_20 = (e->f_10 + e->f_12) / 2;
    e->coll->f_22 = r;
    e->coll->f_24 = e->f_4C | 1;
    e->coll->f_26 = 0x200;
    Collision_Set(0x10, e->coll, 0);
  }

}

void func_80070130(SVECTOR *pos, S_Obj_80070130_80070130 *tmpl, s32 n, s32 base, s32 step, s32 flag) {
    MAT_80070130_80070130 m;
    MAT_80070130_80070130 *mp;
    S_Obj_80070130_80070130 *o;
    if (flag != 0) {
        mp = &m;
        Matrix_FromDirection(flag, mp);
    } else {
        mp = &D_800B1BB0;
    }
    if (n <= 0) {
        return;
    }
loop:
    o = func_8006FE7C();
    *o = *tmpl;
    o->f_0 = *pos;
    o->f_4E = base + (n - 1) * step;
    o->f_20 = *mp;
    n--;
    if (n > 0) {
        goto loop;
    }
}

void func_80070284(void *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80070130(arg0, arg1, arg2, arg3, 6, arg4);
}

INCLUDE_ASM("asm/nonmatchings/game/8006FA10", func_800702B0);

INCLUDE_ASM("asm/nonmatchings/game/8006FA10", func_80070560);

/* Frees all 8 puff slots and resets the next-slot index. */
void Puff_ClearAll(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_800BB840;
    do {
        M2C_FIELD(var_v0, s8 *, 0x18) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x1C));
    } while (var_v1 >= 0);
    D_800B205C = 0;
}

/* Spawns a particle in the 8-entry ring D_800BB840 (next slot D_800B205C): graphic
 * D_800B2054[flags & 0xFF], follows pos, kind, random spin +0x1A, random velocity
 * (x/z +-speed/2, y up to -speed) and, with flags 0x100, a mirrored second velocity, otherwise a
 * second random one at twice the scale. Lives 7 frames. */
void Puff_Spawn(void *pos, s32 kind, s32 flags, s32 speed) {
    struct S_D_800BB840_80070B70 *e = &((struct S_D_800BB840_80070B70 *)&D_800BB840)[(*(u8 *)&D_800B205C)];
    e->f_18 = 7;
    e->f_0 = &D_800B2054[flags & 0xFF];
    e->f_4 = pos;
    e->f_1A = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
    e->f_19 = kind;
    e->f_8 = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 8;
    e->f_A = (-((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) * speed) >> 8;
    e->f_C = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 8;
    if (flags & 0x100) {
        e->f_A = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 8;
        e->f_10 = -e->f_8;
        e->f_14 = -e->f_C;
        e->f_12 = -e->f_A;
    } else {
        e->f_10 = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 7;
        e->f_12 = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 7;
        e->f_14 = ((((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * speed) >> 7;
    }
    (*(u8 *)&D_800B205C) = ((*(u8 *)&D_800B205C) + 1) % 8;
}

/* Each frame, for every live puff: interpolates 8 points from pos+v1 to pos+v1+v2, jitters
   the inner points by the graphic's amplitude (seed +0x1A), draws them on odd frames, and
   counts the timer down. pos is an SVECTOR (kind 0) or a VECTOR (otherwise). */
void Puff_UpdateAll(void) {
    SV_70D94_80070D94 pts[8];
    SV_70D94_80070D94 base;
    SV_70D94_80070D94 a;
    SV_70D94_80070D94 b;
    struct S_D_800BB840_80070D94 *e;
    SV_70D94_80070D94 *p;
    s32 i;
    s32 j;
    u16 seed;

    i = 7;
    e = ((struct S_D_800BB840_80070D94 *)&D_800BB840);
    for (; i >= 0; i--, e++) {
        if (e->f_18 == 0) {
            continue;
        }
        seed = e->f_1A;
        if (e->f_19 == 0) {
            base = *(SV_70D94_80070D94 *)e->f_4;
        } else {
            base.vx = ((s32 *)e->f_4)[0];
            base.vy = ((s32 *)e->f_4)[1];
            base.vz = ((s32 *)e->f_4)[2];
        }
        a.vx = base.vx + e->f_8;
        a.vy = base.vy + e->f_A;
        a.vz = base.vz + e->f_C;
        b.vx = a.vx + e->f_10;
        b.vy = a.vy + e->f_12;
        b.vz = a.vz + e->f_14;
        p = pts;
        for (j = e->f_18; j >= 0; p++, j--) {
            p->vx = (a.vx * j + b.vx * (7 - j)) / 7;
            p->vy = (a.vy * j + b.vy * (7 - j)) / 7;
            p->vz = (a.vz * j + b.vz * (7 - j)) / 7;
            if (j > 0 && j < e->f_18) {
                seed = seed * 5 + 1;
                p->vx += ((((s16)seed >> 8) - 0x80) * e->f_0->f_2) >> 8;
                seed = seed * 5 + 1;
                p->vy += ((((s16)seed >> 8) - 0x80) * e->f_0->f_2) >> 8;
                seed = seed * 5 + 1;
                p->vz += ((((s16)seed >> 8) - 0x80) * e->f_0->f_2) >> 8;
            }
        }
        if (e->f_18 & 1) {
            func_8006F3D0(pts, e->f_18 + 1, &D_800B1B78[e->f_0->f_0 * 8], e->f_0->f_1);
        }
        e->f_18--;
    }
}

void func_800710F8(void) {
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_800BB920[i].f_3C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8006FA10", func_80071120);

/* Updates and draws the 12 debris pieces at D_800BB920: each spins by its rotation speed,
 * moves, falls (vy += 10) and on passing its floor height bounces with effect 5 (vy = -vy / 3)
 * until its bounce count runs out. On its last bounce it is drawn only every other frame. */
void Debris_UpdateAll(void) {
    MAT_71370_80071370 m;
    struct S_D_800BB920_80071370 *d;
    s32 i;
    s16 vy;

    for (i = 11, d = ((struct S_D_800BB920_80071370 *)&D_800BB920); i >= 0; i--, d++) {
        if (d->bounces == 0) {
            continue;
        }
        d->timer++;
        if (d->bounces < 2 && (d->timer & 1)) {
            continue;
        }
        RotMatrixZYX(&d->rot, &m);
        m.t[0] = d->x;
        m.t[1] = d->y;
        m.t[2] = d->z;
        MulMatrix0(&m, &d->base, &m);
        CompMatrix(&D_800E78C0, &m, &m);
        Model_ProjectVertsAlt(&D_800B4D64[d->model], &m, D_800E7D00);
        func_80017E5C(g_Game.db[g_Game.cur].ot, D_800E7D00, &D_800B4D64[d->model]);
        d->rot.vx += d->rv.vx;
        d->rot.vy += d->rv.vy;
        d->rot.vz += d->rv.vz;
        d->x += d->vx;
        d->y += d->vy;
        vy = d->vy += 10;
        d->z += d->vz;
        if (vy >= 0 && d->y > d->floor) {
            d->y = d->floor;
            Effect_SpawnAt(5, &d->x);
            if (--d->bounces != 0) {
                d->vy = -d->vy / 3;
            }
        }
    }
}
