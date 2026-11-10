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

extern M2C_UNK Shockwave_Templates;

void func_8013F0C0(void);
void memset(void *, s32, s32);

M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern M2C_UNK Fx_ExplosionSmoke;

void Fx_GroundBlast(s16 x, s16 y, s16 z);
extern struct S_D_800EC1E0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x24]; u16 f_60; u16 pad62; u16 f_64; u8 pad_66[0xC6]; s32 f_12C; } g_Spike;

void* ApplyMatrixSV(void* m, void* v0, void* v1);
extern struct S_D_800BAD90 { u16 f_0; u16 f_2; u16 f_4; u8 pad_6[0x2]; s8 f_8; s8 f_9; } RcCar_Exhaust;
extern s32 D_800EC0DC;

extern M2C_UNK Fx_SpikeChestPos;
M2C_UNK Shockwave_Spawn(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_800B1C28;
extern M2C_UNK D_800EC240;

M2C_UNK Effect_SpawnAt(M2C_UNK, s32);
extern s32 D_800BAD70;
extern struct S_D_800BAD78 { u8 f_0; u8 f_1; u8 pad2; u8 f_3; s16 f_4; s16 f_6; } Spike_WaterFx;
s32 Game_IsPlaying();
void Fx_UpdateExplosionSmoke(void);
void Spike_UpdateWaterFx(void);
/* A timed damage effect on Spike (Spike_WaterFx: kind +2, frames left +6). Kind 1: two random
 * particles (0x24 and 3) around him each frame; kind 2: particle 2 plus 7 / 0x1C on alternate
 * frames and Dust_SpawnSmall every 4 frames; kind 3: Puff_Spawn every 4 frames. When the timer
 * runs out his tint (g_Spike+0xF8, D_800EC2D8) goes back to white. Started by
 * Spike_StartDamageEffect from Spike_HandleHit by damage type: 0x300 -> kind 1, 0x200 -> kind 2
 * (most likely the electric shock: the shockwave rings and spinning arm deal type 0x200),
 * 0x400 -> kind 3. See docs/findings.md. */
void Spike_UpdateDamageEffect(void);
void Ripple_DrawAll(void);
s32 Floor_GetHeight(s32, s32, s32);
extern u16 g_RandSeed;
extern struct S_D_800EC350 { s32 f_0; u8 pad_4[0x8122]; u16 f_8126; } g_Game;
extern struct S_D_800E68D0 { u8 pad0[0x32]; u8 f_32; u8 pad33[0x13]; u8 f_46; } g_CameraState;
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
extern M2C_UNK Fx_SpikePos;
void Dust_SpawnSmall(SVECTOR *);
void Puff_Spawn(void *, s32, s32, s32);
extern struct S_D_800BAD60 { s16 vx, vy, vz, pad; } D_800BAD60;
struct Spike_8006C92C { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[0xD2]; s16 f_100; };
extern u8 D_800B1A8C[];
extern u8 D_800B1A38[];
void Fx_SpawnFadeRing(void *, s32, s32, s32);
extern s16 D_800EC2E0;
extern u8 D_800B1990[];
extern u16 g_RandSeed2;
extern s16 D_800BAD7C;
extern u8 D_800E6902;
void Spike_WaterSplashOut(void);
extern u8 D_800B1894[];
struct S_D_800BAD68_8006B168 { SV_6B168_8006B168 pos; s32 timer; };
extern struct S_D_800BAD80 { u8 timer; u8 pad1[3]; SV_6C6D4_8006C6D4 pos; } D_800BAD80;
extern u8 D_800B1AE0[];
extern u8 D_800B193C[];
extern u8 D_800B1F1C[];

typedef struct { s16 vx, vy, vz, pad; s32 cx, cz; s32 z; s32 sxy; } Scr_6ABF0;
typedef struct { u8 pad0[0x825A]; s16 f_825A; } Game_6ABF0;
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad1E; u32 xy3; u16 uv3; u16 pad26; } FT4_6ABF0;
extern u8 g_ViewMatrix[];
#define RAND_6ABF0() (g_RandSeed = g_RandSeed * 5 + 1)
extern Game_6ABF0 g_Game_6ABF0 asm("g_Game");
extern u16 D_800B1890_6ABF0[] asm("D_800B1890");
extern u8 *D_800EC354_6ABF0 asm("g_GamePrim");
#define GD_6ABF0 (*(GameDraw *)&g_Game_6ABF0)
#define gte_ldv0_6ABF0(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_6ABF0() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_6ABF0(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6ABF0(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

void Monkey_DrawHelmetLight(SVECTOR *pos, s32 kind, s32 near) {
    void SetRotMatrix(void *m); void SetTransMatrix(void *m);
    Scr_6ABF0 *scr = (Scr_6ABF0 *)0x1F800000;
    s32 a;
    s32 n;
    s32 i;
    s32 j;
    s32 sx;
    s16 sy;
    s32 base;
    s32 w;
    s32 h;
    u32 ww;
    u32 hh;
    u32 r;
    u32 g;
    u32 b;
    u32 r2;
    u32 rb;
    u32 rc;
    u32 top;
    u32 bot;
    u32 xa;
    u32 xb;
    u32 xy0;
    u32 xy1;
    u32 xy2;
    u32 xy3;
    FT4_6ABF0 *p;
    u32 *ot;
    u32 m24;

    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    a = (*(s32 *)&g_Game_6ABF0 & 0xF) << 8;
    scr->cx = rcos(a) * 0x30 >> 12;
    scr->cz = rsin(a) * 0x30 >> 12;
    if (!near || ABS(pos->vy - g_Game_6ABF0.f_825A) >= 0x335) {
        n = 1;
    } else {
        n = 4;
    }
    p = (FT4_6ABF0 *)GD_6ABF0.prim;
    ot = GD_6ABF0.db[GD_6ABF0.cur].ot;
    for (i = 0; i < n; i++) {
        for (j = -1; j < 2; j += 2) {
            scr->vx = pos->vx + scr->cx * i * j;
            scr->vy = pos->vy - 0xD6;
            scr->vz = pos->vz + scr->cz * i * j;
            gte_ldv0_6ABF0(scr);
            gte_rtps_6ABF0();
            gte_stsxy_6ABF0(&scr->sxy);
            gte_stszotz_6ABF0(&scr->z);
            sx = (u16)scr->sxy;
            sy = scr->sxy >> 16;
            if ((u32)(scr->z - 1) >= 0xFFF || (u16)(sx + 0x20) >= 0x1C1 || sy < -0x20 || sy >= 0x111) {
                continue;
            }
            base = i * 4 + (s16)((RAND_6ABF0() >> 8 & 7) + 6);
            w = base + (RAND_6ABF0() >> 8 & 0xF) * i / 4;
            h = base + (RAND_6ABF0() >> 8 & 0xF) * i / 4;
            hh = (u32)(h * 0x148 * 0x11D00) / 0x16800 / scr->z;
            ww = (u32)(w * 0x148) / scr->z;
            rb = RAND_6ABF0() >> 8;
            top = (sy - (s16)hh) << 16;
            xa = ((s16)sx - (s16)ww) & 0xFFFF;
            xy0 = top | xa;
            xb = (s16)sx + (s16)ww;
            xy1 = top | xb;
            bot = (sy + (s16)hh) << 16;
            xy2 = bot | xa;
            r2 = (g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8 & 0x1F;
            xy3 = bot | xb;
            rc = rb & 0x1F;
            switch (kind) {
            case 0:
            default:
                r = 0x18;
                g = r2 + 0x18;
                b = rc + 0x40;
                break;
            case 1:
                r = rc + 0x28;
                g = r2 + 0x20;
                b = 0x10;
                break;
            case 2:
                r = rc + 0x38;
                g = 0x14;
                b = (r2 >> 1) + 8;
                break;
            }
            if (n >= 2) {
                r = (r >> 2) + ((r * (n - i + 1)) >> 2);
                g = (g >> 2) + ((g * (n - i + 1)) >> 2);
                b = (b >> 2) + ((b * (n - i + 1)) >> 2);
            }
            m24 = 0xFFFFFF;
            ((u8 *)p)[3] = 9;
            p->code = (b << 16) | (g << 8) | r | 0x2E000000;
            p->xy0 = xy0;
            p->xy1 = xy1;
            p->xy2 = xy2;
            p->xy3 = xy3;
            p->uv0 = D_800B1890_6ABF0[(i & 3) == 2] << 16;
            p->uv1 = 0x3B003F;
            p->uv2 = 0x3F00;
            p->uv3 = 0x3F3F;
            p->tag = (p->tag & 0xFF000000) | (ot[scr->z] & m24);
            ot[scr->z] = (ot[scr->z] & 0xFF000000) | ((u32)p & m24);
            p++;
            __asm__("" :: "r"(m24));
        }
    }
    D_800EC354_6ABF0 = (u8 *)p;
}

void Fx_UpdateExplosionSmoke(void) {
    struct S_D_800BAD68_8006B168 *e = ((struct S_D_800BAD68_8006B168 *)&Fx_ExplosionSmoke);
    SV_6B168_8006B168 p;

    if (e->timer == 0) {
        return;
    }
    p = e->pos;
    if ((--e->timer & 3) == 0) {
        p.vy = e->pos.vy - (RAND() >> 9);
        Shockwave_Spawn(&p, D_800B1894, 1, 0, 0);
        p.vy = e->pos.vy - (RAND() >> 9);
        Shockwave_Spawn(&p, D_800B1894 + 0x54, 1, 0, 0);
    }
    p.vx = ((struct S_D_800BAD68_8006B168 *)&Fx_ExplosionSmoke)->pos.vx + ((RAND() >> 8) - 0x80);
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
    Shockwave_Spawn(arg0, &D_800B1C28, 2, 0, 0);
    M2C_FIELD(&Fx_ExplosionSmoke, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
    M2C_FIELD(&Fx_ExplosionSmoke, s32 *, 8) = 0x10F;
    Camera_StartShake(1);
    Sound_PlayFixed(0xA7);
}

void Fx_SpawnHitSpark(s32 arg0) {
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
    Shockwave_Spawn((M2C_UNK *)&p, (M2C_UNK *)D_800B1F1C, 1, 0, 0);
    p.vy -= 0x20;
    Shockwave_Spawn((M2C_UNK *)&p, (M2C_UNK *)(D_800B1F1C - 0x24C), 1, 0, 0);
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
  Shockwave_Spawn((M2C_UNK *) (&p), &Shockwave_Templates, 1, 4, 0);
  Camera_StartShake(1);
  for (i = 24; i >= 0; i--)
  {
    p.vx = x + (((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) - 0x80);
    p.vy = h + ((g_RandSeed = (g_RandSeed * 5) + 1) >> 10);
    (&p)->vz = z + (((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) - 0x80);
    Effect_SpawnAt(0x16, &p);
  }

}

void Spike_FxFloorPuff(void) {
    s16 v[3];
    v[0] = g_Spike.f_24;
    v[1] = Floor_GetHeight(g_Spike.f_24, g_Spike.f_28, g_Spike.f_2C);
    v[2] = g_Spike.f_2C;
    Effect_SpawnAt(5, v);
}

void Spike_FxNone(void) {
}

void Spike_FxRunDust(void) {
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

void Spike_ResetFx(void) {
    Spike_WaterFx.f_0 = 0;
    Spike_WaterFx.f_1 = 0;
    Spike_WaterFx.f_3 = 0;
    Spike_WaterFx.f_6 = 0;
    D_800BAD70 = 0;
}

void Fx_UpdateSpikeEffects(void) {
    Fx_UpdateExplosionSmoke();
    if (Game_IsPlaying() != 0) {
        Spike_UpdateWaterFx();
        Spike_UpdateDamageEffect();
        Ripple_DrawAll();
    }
}

void Spike_WaterSplashIn(void) {
    SVEC_8006B848_8006B848 n;
    SVEC_8006B848_8006B848 v;
    SCR_8006B848_8006B848 *sc = (SCR_8006B848_8006B848 *)0x1F8003D4;
    struct S_D_800BAD78 *d = &Spike_WaterFx;

    if (Spike_WaterFx.f_0 == 0) {
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
        Spike_WaterFx.f_0 = ((struct S_D_800EC1E0_8006B848 *)&g_Spike)->f_34 / 2;
        if (Spike_WaterFx.f_0 > 20) {
            Spike_WaterFx.f_0 = 20;
        }
    }
}

void Spike_WaterSplashOut(void) {
    s16 v[3];
    s32 id;
    v[0] = g_Spike.f_24;
    v[1] = Spike_WaterFx.f_4;
    v[2] = g_Spike.f_2C;
    Effect_SpawnAt(0x101, v);
    id = 0x74;
    if (ABS(g_Spike.f_34) > 16 && g_Spike.f_12C - g_Spike.f_28 < 0xC0) {
        id = 0x9D;
    }
    Sound_PlayFixed(id);
    Spike_WaterFx.f_1 = 0x34;
    Spike_WaterFx.f_0 = 0;
}

s32 Spike_IsDeepInWater(void)
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
 * Spike_WaterFx.f_3): on entry reads the surface height and, if falling fast from 0x31..0x8F
 * above it, makes a splash (0x101) and sound 0x9D. Then drips (Spike_WaterFx.f_0 frames, effects
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
    d = &Spike_WaterFx;
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
    d2 = &Spike_WaterFx;
    d2->f_3 = in;
    if (D_800E6902 == 1) {
        return;
    }
    if (Spike_WaterFx.f_0 != 0) {
        Spike_WaterFx.f_0--;
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
        Spike_WaterFx.f_1--;
    }
    if (Spike_WaterFx.f_3 == 0) {
        return;
    }
    p = SPK;
    mv = (p->vx != 0) | (p->vz != 0);
    if (p->y - 0x100 < p->water && p->water < p->y - 0x40) {
        if ((p->f_70 & 0xF0) == 0x40 && p->vy < 0 && Spike_WaterFx.f_1 == 0 && p->y - p->water < 0xC8) {
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
                Shockwave_Spawn(&u, ((u8 *)&D_800B1D24), 1, 0, 0);
            }
            if (mv || Spike_WaterFx.f_0 != 0) {
                Effect_SpawnAt(0x14, ((u8 *)&Fx_SpikePos));
            }
        }
    }
    if (SPK->y - 0x80 < SPK->water) {
        if (((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8 & 0x1F) == 0) {
            u.vx = SPK->x;
            u.vy = D_800BAD7C;
            u.vz = SPK->z;
            Shockwave_Spawn(&u, ((u8 *)&D_800B1D24), 1, 0, 0);
        }
    }
    if (SPK->water < SPK->y - 0x80) {
        if (mv || Spike_WaterFx.f_0 != 0) {
            Effect_SpawnAt(0x14, ((u8 *)&Fx_SpikePos));
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

void Spike_GroundBlast(void) {
    Fx_GroundBlast(g_Spike.f_24, g_Spike.f_28, g_Spike.f_2C);
}

/* Spike's foot dust (user: shows with every gadget except the Monkey Radar and RC car, which take
 * over control, so it runs with his normal movement; the Super Hoop's dust trail is likely this too).
 * Body object D_800B4DC4. Every other frame: Ripple_Spawn behind him
 * (offset by velocity / 64), and a Shockwave_Spawn dust puff every 8 frames, or every 16 while the
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
            Shockwave_Spawn(&p, &D_800B1D24, 1, 0, 0);
        }
    }
    p.vy = o->y;
    if (D_800B4DC4->f_8D & 0x10) {
        p.vx = o->x - SP_6BFB8->vz / 20;
        p.vz = o->z + SP_6BFB8->vx / 20;
        Shockwave_Spawn(&p, &D_800B1D24, 1, 0, 0);
        Effect_SpawnAt(0x10F, &p);
    }
    if (D_800B4DC4->f_8C & 0x10) {
        p.vx = o->x + SP_6BFB8->vz / 20;
        p.vz = o->z - SP_6BFB8->vx / 20;
        Shockwave_Spawn(&p, &D_800B1D24, 1, 0, 0);
        Effect_SpawnAt(0x10F, &p);
    }
}

void Spike_FxDripBurst(void) {
    s32 i;
    s16 v[3];
    for (i = 0; i < 10; i++) {
        v[0] = g_Spike.f_24 + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 0x40;
        v[1] = g_Spike.f_28 - 0x80;
        v[2] = g_Spike.f_2C + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 0x40;
        Effect_SpawnAt(0x12, v);
    }
}

void Spike_FxHit(void) {
    Effect_SpawnAt(0x10C, &Fx_SpikeChestPos);
}

void Spike_StartDamageEffect(s32 a)
{
  int new_var2;
  s32 new_var;
  ((struct S_D_800BAD78_8006C2E8 *)&Spike_WaterFx)->f_2 = a;
  ((struct S_D_800BAD78_8006C2E8 *)&Spike_WaterFx)->f_6 = (new_var2 = 0x32);
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
    if ((*(struct St_8006C334 *)&Spike_WaterFx).timer == 0) {
        (*(u32 *)&D_800EC2D8) = 0xFFFFFF;
        return;
    }
    (*(struct St_8006C334 *)&Spike_WaterFx).timer--;
    switch ((*(struct St_8006C334 *)&Spike_WaterFx).kind) {
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
        Effect_SpawnAt(((*(struct St_8006C334 *)&Spike_WaterFx).timer & 1) ? 7 : 0x1C, &p);
        if (!(D_800BAD7E & 3)) {
            Dust_SpawnSmall(&p);
        }
        break;
    case 3:
        if (!((*(struct St_8006C334 *)&Spike_WaterFx).timer & 3)) {
            Puff_Spawn(&Fx_SpikePos, 0, 0, 0x40);
        }
        break;
    }
}

void Spike_FxBump(void) {
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
    Shockwave_Spawn(&n, D_800B1E74, 1, 0, &a);
    for (i = 0; i < 2; i++) {
        Effect_SpawnAt(4, &n);
        Effect_SpawnAt(3, &n);
    }
}

typedef struct { s16 vx; s16 vy; s16 vz; } SV_6C6A4;
typedef struct { u8 pad0[8]; u8 f_8; u8 pad9[3]; SV_6C6A4 pos; } S_BAD78_6C6A4;
#define BAD78_6C6A4 (*(S_BAD78_6C6A4 *)&Spike_WaterFx)
void Fx_StartBlastSequence(s16 *a) {
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
            Shockwave_Spawn(&p, D_800B1A8C, 1, i, &r);
        }
        Shockwave_Spawn(&p, D_800B1AE0, 1, 0, 0);
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
        Shockwave_Spawn(&p, D_800B1A38, 2, 3, 0);
    }
    if (t == 1) {
        for (i = 0; i < 20; i++) {
            Effect_SpawnAt(0x29, &p);
        }
        Effect_SpawnAt(0x112, &p);
        Effect_SpawnAt(0x109, &p);
        Effect_SpawnAt(0x108, &p);
        Shockwave_Spawn(&p, D_800B193C, 1, 2, 0);
        Shockwave_Spawn(&p, D_800B193C + 0x54, 1, 0, 0);
        Sound_PlayFixed(0x3A);
        Sound_PlayFixed(0x3B);
        Sound_PlayFixed(0x3C);
    }
    D_800BAD80.timer = --t;
}

/* Timed effects for a Spike sequence driven by the frame counter g_Spike+0x100 (called from
 * Spike_DrawWarpA while D_800EC2E0 < 0x1E): every frame a random point around Spike (D_800BAD60);
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
    pos = ((u8 *)&Fx_SpikeChestPos);
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
            Shockwave_Spawn(pos, D_800B1A8C, 1, i * 2, &r);
        }
    }
    if (kind == 0x12) {
        Fx_SpawnFadeRing(pos, 1, -0xE6, 0);
        Shockwave_Spawn(pos, ((u8 *)&D_800B1C28), 1, 0, ((u8 *)&D_800EC240));
    }
    if (kind == 10) {
        Fx_SpawnFadeRing(pos, 1, 0xF0, 0);
        Shockwave_Spawn(pos, D_800B1A38, 1, 4, 0);
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

/* Shorter companion of func_8006C92C, run by Spike_DrawWarpB for the first 16 frames of a Spike
 * sequence (frame counter g_Spike+0x100 = D_800EC2E0): particle 0x112 every 4th frame before
 * frame 8; frame 1: four rotated pieces (D_800B1A8C), effects D_800B1A38 / D_800B1C28 and sound
 * 0xC; frame 7: 40 particles 0x29, effect D_800B1990 and sound 0xA. */
void func_8006CC28(void) {
    SV_8006CC28_8006CC28 r;
    s32 t = D_800EC2E0;
    u8 *pos = ((u8 *)&Fx_SpikeChestPos);
    s32 i;
    if (t < 8 && !(t & 3)) {
        Effect_SpawnAt(0x112, pos);
    }
    if (t == 1) {
        for (i = 0; i < 4; i++) {
            r.vx = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            r.vz = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            Shockwave_Spawn(pos, D_800B1A8C, 1, i * 2, &r);
        }
        Fx_SpawnFadeRing(pos, 1, 0xE0, 0);
        Shockwave_Spawn(pos, D_800B1A38, 2, 4, 0);
        Shockwave_Spawn(pos, ((u8 *)&D_800B1C28), 1, 0, ((u8 *)&D_800EC240));
        Sound_PlayFixed(0xC);
    }
    if (t == 7) {
        for (i = 0; i < 0x28; i++) {
            Effect_SpawnAt(0x29, pos);
        }
        Shockwave_Spawn(pos, D_800B1990, 1, 0, 0);
        Sound_PlayFixed(0xA);
    }
}

void Fx_GadgetSwitch(void) {
    s16 v[3];
    if (g_CameraState.f_32 == 1 || g_CameraState.f_46 == 1) {
        return;
    }
    v[0] = ((struct S_D_800B4D88_8006CDE0 *)&Fx_SpikeChestPos)->f_0 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_60 / 64 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_30 * 4;
    v[1] = ((struct S_D_800B4D88_8006CDE0 *)&Fx_SpikeChestPos)->f_2 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_34 * 4;
    v[2] = ((struct S_D_800B4D88_8006CDE0 *)&Fx_SpikeChestPos)->f_4 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_64 / 64 + ((struct S_D_800EC1E0_8006CDE0 *)&g_Spike)->f_38 * 4;
    Effect_SpawnAt(0x115, v);
}

void Spike_FxKnockback(void) {
    Shockwave_Spawn(&Fx_SpikeChestPos, &D_800B1C28, 1, 0, &D_800EC240);
    Effect_SpawnAt(0x116, &Fx_SpikeChestPos);
}

void SkyFlyer_FxTrail(void) {
    s16 v[3];
    v[0] = g_Spike.f_24 + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
    v[1] = g_Spike.f_28 - 0x100;
    v[2] = g_Spike.f_2C + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80;
    Effect_SpawnAt(0x30, v);
    if (!(g_Game.f_0 & 3)) {
        Effect_SpawnAt(4, v);
    }
}

void RcCar_ResetExhaust(void) {
    RcCar_Exhaust.f_8 = 0;
    RcCar_Exhaust.f_9 = 0x10;
}

void RcCar_SetExhaustPoint(void *arg0) {
    ApplyMatrixSV(arg0, D_800EC0DC + 0x60, &RcCar_Exhaust.f_0);
    RcCar_Exhaust.f_0 = (u16) (RcCar_Exhaust.f_0 + M2C_FIELD(arg0, u16 *, 0x14));
    RcCar_Exhaust.f_2 = (u16) (RcCar_Exhaust.f_2 + M2C_FIELD(arg0, u16 *, 0x18));
    RcCar_Exhaust.f_4 = (u16) (RcCar_Exhaust.f_4 + M2C_FIELD(arg0, u16 *, 0x1C));
}

typedef struct { s16 vx, vy, vz, pad; } SV_6D044;
typedef struct { s16 vx, vy, vz; u8 pad6[3]; u8 k; } Smoke_6D044;
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Car_6D044;
typedef struct { s32 z; s32 sxy; } Scr_6D044;
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad1E; u32 xy3; u16 uv3; u16 pad26; } FT4_6D044;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6D044;
extern Smoke_6D044 D_800BAD90_6D044 asm("RcCar_Exhaust");
extern Car_6D044 g_RcCar_6D044 asm("g_RcCar");
extern struct { s32 frame; u8 pad4[0x814C]; u16 f_8150; } g_Game_6D044 asm("g_Game");
extern u8 g_Game_6D044b asm("g_Game");
extern s8 g_CurrentGadget;
extern u8 D_800B1BA0[];
extern u8 g_ViewMatrix[];
s32 Spike_IsUnderwater(void);
void Fx_DrawRibbon(SV_6D044 *, s32, void *, s32);
void SetRotMatrix(void *);
void SetTransMatrix(void *);

/* RC Car exhaust smoke. While the RC Car is the current gadget (not in menu state 0xA, not with
   D_800E6902, Game_IsPlaying() true, Spike not underwater): on odd frames spawns two pairs of puffs
   (Fx_DrawRibbon, kind D_800B1BA0, size 2-5) on the line from the car (0x20 up) to the trailing
   point RcCar_Exhaust, at weights stepping by 2/16 from the cycling counter +9; on even frames draws
   a 3-frame animated sprite at the trailing point, sized by its depth. */
void RcCar_UpdateExhaust(void)
{
  Scr_6D044 *scr = (Scr_6D044 *) 0x1F800000;
  Smoke_6D044 *s;
  SV_6D044 pts[2];
  SV_6D044 *p;
  SV_6D044 *q;
  s32 frame;
  s32 k;
  s32 i;
  s32 j;
  s32 w;
  register s32 hy asm("$9");
  s32 hx;
  short x;
  s32 y;
  s32 u;
  FT4_6D044 *f;
  u32 *ot;
  if (((((g_CurrentGadget != 7) || (g_Game_6D044.f_8150 == 0xA)) || (D_800E6902 == 1)) || (Game_IsPlaying() == 0)) || (Spike_IsUnderwater() != 0))
  {
    return;
  }
  s = &D_800BAD90_6D044;
  k = s->k;
  s->k = (k + 1) % 12;
  frame = g_Game_6D044.frame;
  if (frame & 1)
  {
    for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
      {
        pts[j].vx = ((g_RcCar_6D044.x * k) + (s->vx * (16 - k))) / 16;
        pts[j].vy = (((g_RcCar_6D044.y - 0x20) * k) + (s->vy * (16 - k))) / 16;
        pts[j].vz = ((g_RcCar_6D044.z * k) + (s->vz * (16 - k))) / 16;
        k += 2;
      }

      Fx_DrawRibbon(pts, 2, D_800B1BA0, (((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) & 3) + 2);
      k = (k + 5) % 14;
    }

  }
  if (!(frame & 1))
  {
    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    asm volatile("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(s));
    asm volatile("nop; nop; rtps");
    asm volatile("swc2 $14, 0(%0)" : : "r"(&scr->sxy) : "memory");
    asm volatile("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(&scr->z) : "$12", "memory");
    if (((u32) (scr->z - 1)) < 0xFFF)
    {
      hy = 0x616 / scr->z;
      u = (((frame >> 1) % 3) * 16) - 0x2F;
      hx = 0x668 / scr->z;
      f = (FT4_6D044 *) (*((GameDraw *) (&g_Game_6D044b))).prim;
      x = (s16) scr->sxy;
      y = scr->sxy >> 16;
      ot = (*((GameDraw *) (&g_Game_6D044b))).db[(*((GameDraw *) (&g_Game_6D044b))).cur].ot;
      ((u8 *) f)[3] = 9;
      f->code = 0x2F000000;
      f->uv0 = ((u8) u) | 0x7EAC3800;
      f->uv1 = (((u8) u) + 0xE) | 0x3C3800;
      f->uv2 = (u & 0xFF) | 0x4600;
      f->uv3 = ((u & 0xFF) + 0xE) | 0x4600;
      { register s32 t0 asm("$4") = (y - hy) << 16; s32 t1 = (y + hy) << 16; register s32 l0 asm("$3") = (x - hx) & 0xFFFF; s32 l1 = (x + hx) & 0xFFFF;
      f->xy0 = t0 | l0; f->xy1 = t0 | l1; f->xy2 = t1 | l0; f->xy3 = t1 | l1; }
      ((PTag_6D044 *) f)->addr = ((PTag_6D044 *) (ot + scr->z))->addr, ((PTag_6D044 *) (ot + scr->z))->addr = (u32) f;
      (*((GameDraw *) (&g_Game_6D044b))).prim = (u8 *) (f + 1);
    }
  }
}
