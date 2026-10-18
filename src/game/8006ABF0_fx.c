#include "common.h"
#include "m2c_macros.h"
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#include "common.h"
#include "common.h"
#define SP_6BFB8 ((struct Spike_8006BFB8 *)&g_Spike)
#define SP_6C334 ((struct Spike_8006C334 *)&g_Spike)
#define RAND_6C334() (g_RandSeed = g_RandSeed * 5 + 1)
#define SPIKE_6C92C ((struct Spike_8006C92C *)&g_Spike)
#define SPK ((SP_6BA2C_8006BA2C *)&g_Spike)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006B570;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006B70C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006B848_8006B848;
typedef struct { u8 pad0[0xA]; u16 f_A; u8 padC[4]; u16 f_10; } SCR_8006B848_8006B848;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006C58C_8006C58C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x5C]; u8 f_8C; u8 f_8D; } Obj_8006BFB8_8006BFB8;
typedef struct { s16 vx, vy, vz, pad; } SV_8006CC28_8006CC28;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; s32 vx; s32 vy; s32 vz; u8 pad3C[0x34]; s32 f_70; u8 pad74[0xB8]; s32 f_12C; u8 pad130[0x8]; u16 f_138; u8 pad13A[0x2]; s16 water; } SP_6BA2C_8006BA2C;
typedef struct { s16 vx, vy, vz, pad; } SV_6BA2C_8006BA2C;
typedef struct { u8 pad0[0xA]; u16 f_A; u8 padC[4]; u16 f_10; } SCR_6BA2C_8006BA2C;
typedef struct { s16 vx, vy, vz, pad; } SV_6B168_8006B168;
typedef struct { s16 vx, vy, vz, pad; } SV_6C6D4_8006C6D4;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006B3F0_8006B3F0;

extern M2C_UNK D_800B1BD4;

void func_8013F0C0(void);
void memset(void *, s32, s32);

M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern M2C_UNK D_800BAD68;

void Fx_GroundBlast(s16 x, s16 y, s16 z);
extern struct S_D_800EC1E0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x24]; u16 f_60; u16 pad62; u16 f_64; u8 pad_66[0xC6]; s32 f_12C; } g_Spike;

void* ApplyMatrixSV(void* m, void* v0, void* v1);
extern struct S_D_800BAD90 { u16 f_0; u16 f_2; u16 f_4; u8 pad_6[0x2]; s8 f_8; s8 f_9; } D_800BAD90;
extern s32 D_800EC0DC;

extern M2C_UNK D_800B4D88;
M2C_UNK func_80070284(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_800B1C28;
extern M2C_UNK D_800EC240;

M2C_UNK Effect_SpawnAt(M2C_UNK, s32);
extern s32 D_800BAD70;
extern struct S_D_800BAD78 { u8 f_0; u8 f_1; u8 pad2; u8 f_3; s16 f_4; s16 f_6; } D_800BAD78;
s32 func_8005DC78();
void Fx_UpdateExplosionSmoke(void);
void Spike_UpdateWaterFx(void);
/* A timed damage effect on Spike (D_800BAD78: kind +2, frames left +6). Kind 1: two random
 * particles (0x24 and 3) around him each frame; kind 2: particle 2 plus 7 / 0x1C on alternate
 * frames and func_8006D588 every 4 frames; kind 3: Puff_Spawn every 4 frames. When the timer
 * runs out his tint (g_Spike+0xF8, D_800EC2D8) goes back to white. Started by
 * Spike_StartDamageEffect from Spike_HandleHit by damage type: 0x300 -> kind 1, 0x200 -> kind 2
 * (most likely the electric shock: the shockwave rings and spinning arm deal type 0x200),
 * 0x400 -> kind 3. See docs/findings.md. */
void Spike_UpdateDamageEffect(void);
M2C_UNK Ripple_DrawAll();
s32 Floor_GetHeight(s32, s32, s32);
extern u16 g_RandSeed;
extern struct S_D_800EC350 { s32 f_0; u8 pad_4[0x8122]; u16 f_8126; } g_Game;
extern struct S_D_800E68D0 { u8 pad0[0x32]; u8 f_32; u8 pad33[0x13]; u8 f_46; } D_800E68D0;
struct S_D_800EC1E0_8006CDE0 { u8 pad0[0x30]; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x24]; s16 f_60; s16 pad62; s16 f_64; };
struct S_D_800B4D88_8006CDE0 { u16 f_0; u16 f_2; u16 f_4; };
extern u8 D_800BAD7B;
struct S_D_800EC1E0_8006B9F8 { u8 pad_0[0x28]; s32 f_28; u8 pad_2C[0x110]; s16 f_13C; };
extern s32 D_800EC2D8;
struct S_D_800BAD78_8006C2E8 { u8 pad0[2]; u8 f_2; u8 pad3[3]; s16 f_6; };
extern s16 D_800B4D90;
void Water_Query(s32, s32, s32);
struct S_D_800EC1E0_8006B848 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[4]; s32 f_34; };
extern u8 D_800B1E74[];
struct S_D_800EC1E0_8006C58C { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; };
struct Spike_8006BFB8 { u8 pad0[0x60]; s16 vx; s16 pad62; s16 vz; };
struct Pad_8006BFB8 { u8 pad0[0x180]; u16 f_180; u16 f_182; };
extern Obj_8006BFB8_8006BFB8 *D_800B4DC4;
extern M2C_UNK g_Pad;
extern M2C_UNK D_800B1D24;
void Ripple_Spawn(SVECTOR *);
struct St_8006C334 { u8 pad0[2]; u8 kind; u8 pad3[3]; u16 timer; };
struct Spike_8006C334 { u8 pad0[0x24]; s32 x, y, z; };
extern u16 D_800BAD7E;
extern M2C_UNK D_800B4D80;
void func_8006D588(SVECTOR *);
void Puff_Spawn(void *, s32, s32, s32);
extern struct S_D_800BAD60 { s16 vx, vy, vz, pad; } D_800BAD60;
struct Spike_8006C92C { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[0xD2]; s16 f_100; };
extern u8 D_800B1A8C[];
extern u8 D_800B1A38[];
void Fx_SpawnFadeRing(void *, s32, s32, s32);
extern s16 D_800EC2E0;
extern u8 D_800B1990[];
extern u16 D_800AE8F2;
extern s16 D_800BAD7C;
extern u8 D_800E6902;
void Spike_WaterSplashOut(void);
extern u8 D_800B1894[];
struct S_D_800BAD68_8006B168 { SV_6B168_8006B168 pos; s32 timer; };
extern struct S_D_800BAD80 { u8 timer; u8 pad1[3]; SV_6C6D4_8006C6D4 pos; } D_800BAD80;
extern u8 D_800B1AE0[];
extern u8 D_800B193C[];
extern u8 D_800B1F1C[];

INCLUDE_ASM("asm/nonmatchings/game/8006ABF0_fx", Monkey_DrawHelmetLight);

void Fx_UpdateExplosionSmoke(void) {
    struct S_D_800BAD68_8006B168 *e = ((struct S_D_800BAD68_8006B168 *)&D_800BAD68);
    SV_6B168_8006B168 p;

    if (e->timer == 0) {
        return;
    }
    p = e->pos;
    if ((--e->timer & 3) == 0) {
        p.vy = e->pos.vy - (RAND() >> 9);
        func_80070284(&p, D_800B1894, 1, 0, 0);
        p.vy = e->pos.vy - (RAND() >> 9);
        func_80070284(&p, D_800B1894 + 0x54, 1, 0, 0);
    }
    p.vx = ((struct S_D_800BAD68_8006B168 *)&D_800BAD68)->pos.vx + ((RAND() >> 8) - 0x80);
    p.vy = e->pos.vy - (RAND() >> 8) * 2;
    p.vz = e->pos.vz + ((RAND() >> 8) - 0x80);
    Effect_SpawnAt(5, &p);
    Effect_SpawnAt(0x2B, &p);
}

void Fx_BigExplosion(void *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        Effect_SpawnAt(0x29, arg0);
        var_s0 += 1;
    } while (var_s0 < 0x28);
    Effect_SpawnAt(0x112, arg0);
    func_80070284(arg0, &D_800B1C28, 2, 0, 0);
    M2C_FIELD(&D_800BAD68, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
    M2C_FIELD(&D_800BAD68, s32 *, 8) = 0x10F;
    Camera_StartShake(1);
    Sound_PlayFixed(0xA7);
}

void func_8006B3CC(s32 arg0) {
    Effect_SpawnAt(0x113, arg0);
}

void Fx_DebrisExplosion(x, y, z)
    s16 x, y, z;
{
    SVEC_8006B3F0_8006B3F0 p;
    s32 i;
    p.vx = x;
    p.vy = y;
    p.vz = z;
    Effect_SpawnAt(0x10D, &p);
    Fx_SpawnFadeRing(&p, 0, 800, 0);
    func_80070284((M2C_UNK *)&p, (M2C_UNK *)D_800B1F1C, 1, 0, 0);
    p.vy -= 0x20;
    func_80070284((M2C_UNK *)&p, (M2C_UNK *)(D_800B1F1C - 0x24C), 1, 0, 0);
    for (i = 0; i < 16; i++) {
        Effect_SpawnAt(0x17, &p);
    }
    for (i = 0; i < 16; i++) {
        p.vx = x + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
        p.vy = y - ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8);
        p.vz = z + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
        Effect_SpawnAt(7, &p);
    }
    Camera_StartShake(1);
}

void Fx_GroundBlast(s16 x, s16 y, s16 z)
{
  SVEC_8006B570 p;
  s16 h;
  s32 i;
  h = Floor_GetHeight(x, y, z) - 16;
  p.vx = x;
  p.vy = h;
  p.vz = z;
  func_80070284((M2C_UNK *) (&p), &D_800B1BD4, 1, 4, 0);
  Camera_StartShake(1);
  for (i = 24; i >= 0; i--)
  {
    p.vx = x + (((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) - 0x80);
    p.vy = h + ((g_RandSeed = (g_RandSeed * 5) + 1) >> 10);
    (&p)->vz = z + (((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) - 0x80);
    Effect_SpawnAt(0x16, &p);
  }

}

void func_8006B6B0(void) {
    s16 v[3];
    v[0] = g_Spike.f_24;
    v[1] = Floor_GetHeight(g_Spike.f_24, g_Spike.f_28, g_Spike.f_2C);
    v[2] = g_Spike.f_2C;
    Effect_SpawnAt(5, v);
}

void func_8006B704(void) {
}

void func_8006B70C(void) {
    SVEC_8006B70C tmp;
    SVEC_8006B70C v;
    if (g_Game.f_8126 == 2) {
        func_8013F0C0();
        return;
    }
    if (g_Game.f_0 & 1) {
        memset(&v, 0, 8);
        v.vx = g_Spike.f_24 - g_Spike.f_30 * 2;
        v.vy = g_Spike.f_28 - 0x20;
        v.vz = g_Spike.f_2C - g_Spike.f_38 * 2;
        tmp = v;
        Effect_SpawnAt(4, &tmp);
    }
}

void func_8006B7DC(void) {
    D_800BAD78.f_0 = 0;
    D_800BAD78.f_1 = 0;
    D_800BAD78.f_3 = 0;
    D_800BAD78.f_6 = 0;
    D_800BAD70 = 0;
}

void Fx_UpdateSpikeEffects(void) {
    Fx_UpdateExplosionSmoke();
    if (func_8005DC78() != 0) {
        Spike_UpdateWaterFx();
        Spike_UpdateDamageEffect();
        Ripple_DrawAll();
    }
}

void Spike_WaterSplashIn(void) {
    SVEC_8006B848_8006B848 n;
    SVEC_8006B848_8006B848 v;
    SCR_8006B848_8006B848 *sc = (SCR_8006B848_8006B848 *)0x1F8003D4;
    struct S_D_800BAD78 *d = &D_800BAD78;

    if (D_800BAD78.f_0 == 0) {
        Water_Query(((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_24, ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_28, ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_2C);
        D_800B4D90 = d->f_4 = sc->f_A - sc->f_10;
        memset(&v, 0, 8);
        v.vx = ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_24;
        v.vy = d->f_4;
        v.vz = ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_2C;
        n = v;
        Effect_SpawnAt(0x100, &n);
        Sound_PlayFixed(0x72);
        d->f_1 = 0;
        D_800BAD78.f_0 = ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_34 / 2;
        if (D_800BAD78.f_0 > 20) {
            D_800BAD78.f_0 = 20;
        }
    }
}

void Spike_WaterSplashOut(void) {
    s16 v[3];
    s32 id;
    v[0] = g_Spike.f_24;
    v[1] = D_800BAD78.f_4;
    v[2] = g_Spike.f_2C;
    Effect_SpawnAt(0x101, v);
    id = 0x74;
    if (ABS(g_Spike.f_34) > 16 && g_Spike.f_12C - g_Spike.f_28 < 0xC0) {
        id = 0x9D;
    }
    Sound_PlayFixed(id);
    D_800BAD78.f_1 = 0x34;
    D_800BAD78.f_0 = 0;
}

s32 func_8006B9F8(void)
{
  int new_var;
  s32 var_v1;
  var_v1 = 0;
  if (D_800BAD7B != 0)
  {
    new_var = 0x100;
    new_var = ((struct S_D_800EC1E0_8006B9F8 *)&g_Spike)->f_13C < (((struct S_D_800EC1E0_8006B9F8 *)&g_Spike)->f_28 - new_var);
    var_v1 = new_var;
  }
  return var_v1;
}

/* Per-frame water effects for Spike. Detects entering water (f_138 >> 12 == 1, kept in
 * D_800BAD78.f_3): on entry reads the surface height and, if falling fast from 0x31..0x8F
 * above it, makes a splash (0x101) and sound 0x9D. Then drips (D_800BAD78.f_0 frames, effects
 * 0x12/0x15), bubbles (f_1 frames, 1-3 effect 0x11 per frame), and while in water a wake at
 * the surface (f_13C) when near it, random ripples (D_800B1D24) and effect 0x14 when moving. */
void Spike_UpdateWaterFx(void) {
    SCR_6BA2C_8006BA2C *sc = (SCR_6BA2C_8006BA2C *)0x1F8003D4;
    SP_6BA2C_8006BA2C *sp = SPK;
    struct S_D_800BAD78 *d;
    s32 in;
    s32 n;
    s32 dy;
    s32 mv;
    SP_6BA2C_8006BA2C *p;
    struct S_D_800BAD78 *d2;
    SV_6BA2C_8006BA2C t;
    SV_6BA2C_8006BA2C v;
    SV_6BA2C_8006BA2C u;
    SV_6BA2C_8006BA2C w;

    in = (sp->f_138 >> 12) == 1;
    d = &D_800BAD78;
    if (in != d->f_3 && in) {
        Water_Query(sp->x, sp->y, sp->z);
        D_800B4D90 = d->f_4 = sc->f_A - sc->f_10;
        if (ABS(sp->vy) > 16 && (dy = sp->f_12C - sp->y) < 0x90 && dy >= 0x31) {
            memset(&v, 0, 8);
            v.vx = sp->x;
            v.vy = d->f_4;
            v.vz = sp->z;
            t = v;
            Effect_SpawnAt(0x101, &t);
            Sound_PlayFixed(0x9D);
            d->f_1 = 0;
        }
    }
    d2 = &D_800BAD78;
    d2->f_3 = in;
    if (D_800E6902 == 1) {
        return;
    }
    if (D_800BAD78.f_0 != 0) {
        D_800BAD78.f_0--;
        t.vx = SPK->x;
        t.vy = SPK->y - 0x80;
        t.vz = SPK->z;
        Effect_SpawnAt(0x12, &t);
        Effect_SpawnAt(0x15, &t);
    }
    if (d2->f_1 != 0) {
        n = 3;
        if ((SPK->f_70 & 0xF0) == 0x40 || d2->f_1 < 10) {
            n = 1;
        }
        for (; n > 0; n--) {
            v.vx = SPK->x + (RAND() >> 8 & 0x7F) - 0x3F;
            v.vy = SPK->y - (RAND() >> 8 & 0x7F);
            v.vz = SPK->z + (RAND() >> 8 & 0x7F) - 0x3F;
            Effect_SpawnAt(0x11, &v);
        }
        D_800BAD78.f_1--;
    }
    if (D_800BAD78.f_3 == 0) {
        return;
    }
    p = SPK;
    mv = (p->vx != 0) | (p->vz != 0);
    if (p->y - 0x100 < p->water && p->water < p->y - 0x40) {
        if ((p->f_70 & 0xF0) == 0x40 && p->vy < 0 && D_800BAD78.f_1 == 0 && p->y - p->water < 0xC8) {
            Spike_WaterSplashOut();
        }
        if (!(g_Game.f_0 & 1)) {
            memset(&w, 0, 8);
            w.vx = SPK->x;
            w.vy = SPK->water;
            w.vz = SPK->z;
            u = w;
            Ripple_Spawn(&u);
            if ((RAND() >> 8 & 3) == 0) {
                func_80070284(&u, ((u8 *)&D_800B1D24), 1, 0, 0);
            }
            if (mv || D_800BAD78.f_0 != 0) {
                Effect_SpawnAt(0x14, ((u8 *)&D_800B4D80));
            }
        }
    }
    if (SPK->y - 0x80 < SPK->water) {
        if (((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8 & 0x1F) == 0) {
            u.vx = SPK->x;
            u.vy = D_800BAD7C;
            u.vz = SPK->z;
            func_80070284(&u, ((u8 *)&D_800B1D24), 1, 0, 0);
        }
    }
    if (SPK->water < SPK->y - 0x80) {
        if (mv || D_800BAD78.f_0 != 0) {
            Effect_SpawnAt(0x14, ((u8 *)&D_800B4D80));
        }
    }
}

void func_8006BF10(void) {
    s16 v[3];
    v[0] = g_Spike.f_24 - ((s16)g_Spike.f_60 >> 6);
    v[1] = g_Spike.f_28 - 0x30;
    v[2] = g_Spike.f_2C - ((s16)g_Spike.f_64 >> 6);
    Effect_SpawnAt(0x14, v);
    Effect_SpawnAt(0x15, v);
}

void func_8006BF84(void) {
    Fx_GroundBlast(g_Spike.f_24, g_Spike.f_28, g_Spike.f_2C);
}

/* Spike's foot dust (user: shows with every gadget except the Monkey Radar and RC car, which take
 * over control, so it runs with his normal movement; the Super Hoop's dust trail is likely this too).
 * Body object D_800B4DC4. Every other frame: Ripple_Spawn behind him
 * (offset by velocity / 64), and a func_80070284 dust puff every 8 frames, or every 16 while the
 * analog stick is pushed. When a foot's contact flag (object +0x8D / +0x8C, bit 0x10) is set,
 * a dust puff plus effect 0x10F to that side (velocity / 20 sideways). */
void Spike_UpdateFootEffects(void) {
    Obj_8006BFB8_8006BFB8 *o = D_800B4DC4;
    SVECTOR p;
    s32 m;
    p.vy = o->y + 0x20;
    if (!((*(s32 *)&g_Game) & 1)) {
        m = ((((struct Pad_8006BFB8 *)&g_Pad)->f_180 | ((struct Pad_8006BFB8 *)&g_Pad)->f_182) != 0) << 3;
        p.vx = o->x - SP_6BFB8->vx / 64;
        p.vz = o->z - SP_6BFB8->vz / 64;
        Ripple_Spawn(&p);
        if (!((*(s32 *)&g_Game) & (m + 7))) {
            p.vx = o->x;
            p.vz = o->z;
            func_80070284(&p, &D_800B1D24, 1, 0, 0);
        }
    }
    p.vy = o->y;
    if (D_800B4DC4->f_8D & 0x10) {
        p.vx = o->x - SP_6BFB8->vz / 20;
        p.vz = o->z + SP_6BFB8->vx / 20;
        func_80070284(&p, &D_800B1D24, 1, 0, 0);
        Effect_SpawnAt(0x10F, &p);
    }
    if (D_800B4DC4->f_8C & 0x10) {
        p.vx = o->x + SP_6BFB8->vz / 20;
        p.vz = o->z - SP_6BFB8->vx / 20;
        func_80070284(&p, &D_800B1D24, 1, 0, 0);
        Effect_SpawnAt(0x10F, &p);
    }
}

void func_8006C204(void) {
    s32 i;
    s16 v[3];
    for (i = 0; i < 10; i++) {
        v[0] = g_Spike.f_24 + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 0x40;
        v[1] = g_Spike.f_28 - 0x80;
        v[2] = g_Spike.f_2C + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 0x40;
        Effect_SpawnAt(0x12, v);
    }
}

void func_8006C2C0(void) {
    Effect_SpawnAt(0x10C, &D_800B4D88);
}

void Spike_StartDamageEffect(s32 a)
{
  int new_var2;
  s32 new_var;
  ((struct S_D_800BAD78_8006C2E8 *)&D_800BAD78)->f_2 = a;
  ((struct S_D_800BAD78_8006C2E8 *)&D_800BAD78)->f_6 = (new_var2 = 0x32);
  new_var = a;
  switch (new_var)
  {
    case 1:
      if (new_var)
    {
      D_800EC2D8 = 0xFF0000;
      break;
    }
    else
    {
      D_800EC2D8 = 0xFF0000;
      break;
    }

    case 2:

    case 3:
      D_800EC2D8 = 0;
      break;

  }

}

void Spike_UpdateDamageEffect(void) {
    SVECTOR p;
    s32 i;
    if ((*(struct St_8006C334 *)&D_800BAD78).timer == 0) {
        (*(u32 *)&D_800EC2D8) = 0xFFFFFF;
        return;
    }
    (*(struct St_8006C334 *)&D_800BAD78).timer--;
    switch ((*(struct St_8006C334 *)&D_800BAD78).kind) {
    case 1:
        for (i = 0; i < 2; i++) {
            p.vx = SP_6C334->x + ((RAND_6C334() >> 8) & 0x7F) - 0x40;
            p.vy = SP_6C334->y - ((RAND_6C334() >> 10) + 0x40);
            p.vz = SP_6C334->z + ((RAND_6C334() >> 8) & 0x7F) - 0x40;
            Effect_SpawnAt(0x24, &p);
            Effect_SpawnAt(3, &p);
        }
        break;
    case 2:
        p.vx = SP_6C334->x + ((RAND_6C334() >> 8) & 0x3F) - 0x20;
        p.vy = SP_6C334->y - (((RAND_6C334() >> 8) & 0x3F) + 0x20);
        p.vz = SP_6C334->z + ((RAND_6C334() >> 8) & 0x3F) - 0x20;
        Effect_SpawnAt(2, &p);
        Effect_SpawnAt(((*(struct St_8006C334 *)&D_800BAD78).timer & 1) ? 7 : 0x1C, &p);
        if (!(D_800BAD7E & 3)) {
            func_8006D588(&p);
        }
        break;
    case 3:
        if (!((*(struct St_8006C334 *)&D_800BAD78).timer & 3)) {
            Puff_Spawn(&D_800B4D80, 0, 0, 0x40);
        }
        break;
    }
}

void func_8006C58C(void) {
    SVEC_8006C58C_8006C58C n;
    SVEC_8006C58C_8006C58C a;
    SVEC_8006C58C_8006C58C b;
    s32 i;

    memset(&a, 0, 8);
    a.vx = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_24;
    a.vy = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_28 - 0x50;
    a.vz = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_2C;
    n = a;
    memset(&b, 0, 8);
    b.vx = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_30;
    b.vy = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_34;
    b.vz = ((struct S_D_800EC1E0_8006C58C *)&g_Spike)->f_38;
    a = b;
    func_80070284(&n, D_800B1E74, 1, 0, &a);
    for (i = 0; i < 2; i++) {
        Effect_SpawnAt(4, &n);
        Effect_SpawnAt(3, &n);
    }
}

typedef struct { s16 vx; s16 vy; s16 vz; } SV_6C6A4;
typedef struct { u8 pad0[8]; u8 f_8; u8 pad9[3]; SV_6C6A4 pos; } S_BAD78_6C6A4;
#define BAD78_6C6A4 (*(S_BAD78_6C6A4 *)&D_800BAD78)
void func_8006C6A4(s16 *a) {
    SV_6C6A4 *p = &BAD78_6C6A4.pos;
    p->vx = a[0];
    p->vy = a[2] - 0x40;
    p->vz = a[4];
    BAD78_6C6A4.f_8 = 0x1E;
}

void Fx_UpdateBlastSequence(void) {
    s32 t = D_800BAD80.timer;
    s32 i;
    SV_6C6D4_8006C6D4 p;
    SV_6C6D4_8006C6D4 r;

    if (t == 0) {
        return;
    }
    p = D_800BAD80.pos;
    if (t == 30) {
        for (i = 0; i < 3; i++) {
            r.vx = RAND() >> 4 & 0xFF0;
            r.vy = RAND() >> 4 & 0xFF0;
            r.vz = RAND() >> 4 & 0xFF0;
            func_80070284(&p, D_800B1A8C, 1, i, &r);
        }
        func_80070284(&p, D_800B1AE0, 1, 0, 0);
        Effect_SpawnAt(0x112, &p);
        Effect_SpawnAt(0x108, &p);
        Fx_SpawnFadeRing(&p, 1, -0x258, 0);
        Sound_PlayFixed(0x36);
        Sound_PlayFixed(0x37);
    }
    if (t == 18) {
        Sound_PlayFixed(0x38);
    }
    if (t == 14) {
        Sound_PlayFixed(0x39);
    }
    if (t == 5) {
        func_80070284(&p, D_800B1A38, 2, 3, 0);
    }
    if (t == 1) {
        for (i = 0; i < 20; i++) {
            Effect_SpawnAt(0x29, &p);
        }
        Effect_SpawnAt(0x112, &p);
        Effect_SpawnAt(0x109, &p);
        Effect_SpawnAt(0x108, &p);
        func_80070284(&p, D_800B193C, 1, 2, 0);
        func_80070284(&p, D_800B193C + 0x54, 1, 0, 0);
        Sound_PlayFixed(0x3A);
        Sound_PlayFixed(0x3B);
        Sound_PlayFixed(0x3C);
    }
    D_800BAD80.timer = --t;
}

/* Timed effects for a Spike sequence driven by the frame counter g_Spike+0x100 (called from
 * func_80068ADC while D_800EC2E0 < 0x1E): every frame a random point around Spike (D_800BAD60);
 * frame 1 sound 0xA; 6: 40 particles 0x29 + sound 0xB; 10: effect + sound 0xC; 0x12: effect at
 * D_800EC240; 0x14: three rotated pieces (D_800B1A8C); 0x11-0x1D: two puffs per frame (and
 * particle 0x112 every 4th); 0x1D: sounds 8 and 9. */
void func_8006C92C(void) {
    struct S_D_800BAD60 r;
    s32 kind = SPIKE_6C92C->f_100;
    s32 i;
    u8 *pos;
    D_800BAD60.vx = SPIKE_6C92C->x + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
    D_800BAD60.vy = SPIKE_6C92C->y - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 11) + 0x60);
    D_800BAD60.vz = SPIKE_6C92C->z + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
    pos = ((u8 *)&D_800B4D88);
    if (kind == 0x1D) {
        Sound_PlayFixed(8);
        Sound_PlayFixed(9);
    }
    if ((u32)(kind - 0x11) < 0xD) {
        for (i = 0; i < 2; i++) {
            Puff_Spawn(&D_800BAD60, 0, 0x101, (((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0) + 0x400);
        }
        if (!(kind & 3)) {
            Effect_SpawnAt(0x112, pos);
        }
    }
    if (kind == 0x14) {
        for (i = 0; i < 3; i++) {
            r.vx = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vz = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            func_80070284(pos, D_800B1A8C, 1, i * 2, &r);
        }
    }
    if (kind == 0x12) {
        Fx_SpawnFadeRing(pos, 1, -0xE6, 0);
        func_80070284(pos, ((u8 *)&D_800B1C28), 1, 0, ((u8 *)&D_800EC240));
    }
    if (kind == 10) {
        Fx_SpawnFadeRing(pos, 1, 0xF0, 0);
        func_80070284(pos, D_800B1A38, 1, 4, 0);
        Sound_PlayFixed(0xC);
    }
    if (kind == 6) {
        for (i = 0; i < 0x28; i++) {
            Effect_SpawnAt(0x29, pos);
        }
        Sound_PlayFixed(0xB);
    }
    if (kind == 1) {
        Sound_PlayFixed(0xA);
    }
}

/* Shorter companion of func_8006C92C, run by func_80068B1C for the first 16 frames of a Spike
 * sequence (frame counter g_Spike+0x100 = D_800EC2E0): particle 0x112 every 4th frame before
 * frame 8; frame 1: four rotated pieces (D_800B1A8C), effects D_800B1A38 / D_800B1C28 and sound
 * 0xC; frame 7: 40 particles 0x29, effect D_800B1990 and sound 0xA. */
void func_8006CC28(void) {
    SV_8006CC28_8006CC28 r;
    s32 t = D_800EC2E0;
    u8 *pos = ((u8 *)&D_800B4D88);
    s32 i;
    if (t < 8 && !(t & 3)) {
        Effect_SpawnAt(0x112, pos);
    }
    if (t == 1) {
        for (i = 0; i < 4; i++) {
            r.vx = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vz = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            func_80070284(pos, D_800B1A8C, 1, i * 2, &r);
        }
        Fx_SpawnFadeRing(pos, 1, 0xE0, 0);
        func_80070284(pos, D_800B1A38, 2, 4, 0);
        func_80070284(pos, ((u8 *)&D_800B1C28), 1, 0, ((u8 *)&D_800EC240));
        Sound_PlayFixed(0xC);
    }
    if (t == 7) {
        for (i = 0; i < 0x28; i++) {
            Effect_SpawnAt(0x29, pos);
        }
        func_80070284(pos, D_800B1990, 1, 0, 0);
        Sound_PlayFixed(0xA);
    }
}

void func_8006CDE0(void) {
    s16 v[3];
    if (D_800E68D0.f_32 == 1 || D_800E68D0.f_46 == 1) {
        return;
    }
    v[0] = ((struct S_D_800B4D88_8006CDE0 *)&D_800B4D88)->f_0 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_60 / 64 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_30 * 4;
    v[1] = ((struct S_D_800B4D88_8006CDE0 *)&D_800B4D88)->f_2 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_34 * 4;
    v[2] = ((struct S_D_800B4D88_8006CDE0 *)&D_800B4D88)->f_4 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_64 / 64 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_38 * 4;
    Effect_SpawnAt(0x115, v);
}

void func_8006CE9C(void) {
    func_80070284(&D_800B4D88, &D_800B1C28, 1, 0, &D_800EC240);
    Effect_SpawnAt(0x116, &D_800B4D88);
}

void func_8006CEF0(void) {
    s16 v[3];
    v[0] = g_Spike.f_24 + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
    v[1] = g_Spike.f_28 - 0x100;
    v[2] = g_Spike.f_2C + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
    Effect_SpawnAt(0x30, v);
    if (!(g_Game.f_0 & 3)) {
        Effect_SpawnAt(4, v);
    }
}

void func_8006CFA4(void) {
    D_800BAD90.f_8 = 0;
    D_800BAD90.f_9 = 0x10;
}

void func_8006CFBC(void *arg0) {
    ApplyMatrixSV(arg0, D_800EC0DC + 0x60, &D_800BAD90.f_0);
    D_800BAD90.f_0 = (u16) (D_800BAD90.f_0 + M2C_FIELD(arg0, u16 *, 0x14));
    D_800BAD90.f_2 = (u16) (D_800BAD90.f_2 + M2C_FIELD(arg0, u16 *, 0x18));
    D_800BAD90.f_4 = (u16) (D_800BAD90.f_4 + M2C_FIELD(arg0, u16 *, 0x1C));
}

INCLUDE_ASM("asm/nonmatchings/game/8006ABF0_fx", func_8006D044);
