#include "common.h"
#include "m2c_macros.h"
typedef struct { SVECTOR unk0; s16 unk8; u8 unkA; u8 unkB; s16 unkC; s16 unkE; } S_F5010;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006F274_8006F274;
/* 8 fading rings (Fx_SpawnFadeRing): position, shape arg, timer, start delay, radius, target radius */

extern struct S_D_800F4E90 { s16 f_0; s16 f_2; s16 f_4; u8 f_6; u8 pad7; } D_800F4E90[];
extern u16 g_RandSeed;

extern u8 D_800B1B40;
extern M2C_UNK D_800BADA0;

extern S_F5010 D_800F5010[8];
extern u8 D_800B1B74;

extern struct S_D_800BAEA0 { u8 pad_0[0x6]; s8 f_6; u8 pad_7[0x5]; } D_800BAEA0[];

void func_8006D4C0(void *arg0, s8 arg1);
extern struct S_D_800F4ED0 { u8 pad0[6]; u16 f_6; } g_HoopSparks[];
extern M2C_UNK D_800B1B90;
void func_8006F3D0(SVEC_8006F274_8006F274 *, s32, void *, s32);
struct S_D_800F5010_8006ED78 { SVECTOR f_0; s16 f_8; u8 f_A; u8 f_B; s16 f_C; s16 f_E; };
void Fx_DrawFadeRing(struct S_D_800F5010 *, s32, s32, s32);
struct S_D_800F5010_8006EE3C { SVECTOR f_0; u16 f_8; u8 f_A; u8 f_B; u16 f_C; u16 f_E; };
extern u8 D_800B1B40_1;
struct S_D_800BAEA0_8006E054 { s16 f_0; s16 f_2; s16 f_4; u8 f_6; u8 pad7; u8 f_8; u8 f_9; u8 f_A; u8 padB; };

void func_8006D4C0(void *arg0, s8 arg1)
{
  s32 temp_v1;
  s32 var_v0;
  u8 *new_var;
  void *temp_v0;
  temp_v0 = (void *) (((u8 *) (&D_800BADA0)) + (D_800B1B40 * 8));
  *((SVECTOR *) (((s8 *) temp_v0) + 0)) = *((SVECTOR *) (((s8 *) arg0) + 0));
  new_var = (u8 *) (&D_800BADA0);
  *((s8 *) (((s8 *) ((void *) (new_var + (D_800B1B40 * 8)))) + 6)) = 9;
  *((s8 *) (((s8 *) ((void *) (new_var + (D_800B1B40 * 8)))) + 7)) = arg1;
  temp_v1 = D_800B1B40 + 1;
  var_v0 = temp_v1;
  if (temp_v1 < 0)
  {
    var_v0 = D_800B1B40 + 0x20;
  }
  D_800B1B40 = temp_v1 - (var_v0 & 0x1E0);
}

void func_8006D548(s32 arg0) {
    func_8006D4C0(arg0, 0);
}

void func_8006D568(s32 arg0) {
    func_8006D4C0(arg0, 1);
}

void func_8006D588(s32 arg0) {
    func_8006D4C0(arg0, 2);
}

INCLUDE_ASM("asm/nonmatchings/game/8006D4C0", func_8006D5A8);

void func_8006DAC8(void) {
    s32 i;
    struct S_D_800F4ED0 *p = g_HoopSparks;
    for (i = 39; i >= 0; i--) {
        p->f_6 &= 0xFFE0;
        p++;
    }
}

#include "gte.h"
extern u8 g_Game[];
extern u8 *D_800EC354;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_6DAF8;
typedef struct { u32 tag; u32 rgbc; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2, pad2; u32 xy3; u16 uv3, pad3; } PolyFT4_6DAF8;
typedef struct { s16 x, y, z; u16 flags; } Spark_6DAF8;
#define SPK_TIMER(e) (*(u8 *)&(e)->flags & 0x1F)
#define SPK_SET_TIMER(e, v) { s32 _v = (v); (e)->flags = ((e)->flags & 0xFFE0) | _v; }
#define SPK_SIZE(e) (((e)->flags >> 5) & 7)
#define SPK_SET_SIZE(e, v) { s32 _v = (v) << 5; (e)->flags = ((e)->flags & 0xFF1F) | _v; }
extern Spark_6DAF8 D_800F4ED0_6DAF8[40] asm("g_HoopSparks");
extern struct { u8 pad0[0x1C]; SVECTOR rot; s32 x; s32 y; s32 z; s32 vx; s32 vy; s32 vz; u8 pad3C[0xB6]; s8 gadget; } g_Spike_6DAF8 asm("g_Spike");
extern struct { u8 pad0[4]; s16 f_4; u8 pad6[2]; s32 f_8; } g_GadgetState_6DAF8 asm("g_GadgetState");
typedef struct { s32 rand; s32 otz; u32 sxy; u32 padC; s32 dx, dy, dz; SVECTOR base; s32 noSpawn; s32 radius; } Scratch_6DAF8;
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
extern u8 D_800E78C0[];
s32 func_8005DC78(void);
s32 rcos(s32);
s32 rsin(s32);
#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")

/* Super Hoop sparkles (gadget 4), the particles seen when the hoop is activated (user): 40 particles (g_HoopSparks) that, while func_8005DC78 allows and gadget state
   +4 is 1, respawn on a ring around Spike (radius gadget state +8 / 6 + 90) with a 3-10 frame life
   and size 1-2, then drift with 2/3 of Spike's velocity; drawn as POLY_FT4 sized by size / depth. */
void SuperHoop_DrawSparkles(void) {
    Scratch_6DAF8 *sc = (Scratch_6DAF8 *)0x1F800000;
    Spark_6DAF8 *e;
    PolyFT4_6DAF8 *p;
    u32 *ot;
    s32 i, a, x, y, d, w, h, x0, y0;
    u32 xy;

    if (g_Spike_6DAF8.gadget != 4 || func_8005DC78() == 0) {
        return;
    }
    sc->noSpawn = 0;
    if (g_GadgetState_6DAF8.f_4 != 1) {
        sc->noSpawn = 1;
    }
    sc->dx = g_Spike_6DAF8.vx * 2 / 3;
    sc->dz = g_Spike_6DAF8.vz * 2 / 3;
    sc->rand = g_RandSeed;
    sc->dy = g_Spike_6DAF8.vy;
    *(SVECTOR *)0x1F80001C = g_Spike_6DAF8.rot;
    sc->radius = g_GadgetState_6DAF8.f_8 / 6 + 0x5A;
    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    e = D_800F4ED0_6DAF8;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (PolyFT4_6DAF8 *)G_DRAW.prim;
    for (i = 39; i >= 0; i--, e++) {
        if ((e->flags & 0x1F) == 0) {
            if (sc->noSpawn != 0) {
                continue;
            }
            SPK_SET_TIMER(e, ((sc->rand = sc->rand * 5 + 1) & 7) + 3);
            a = (sc->rand = sc->rand * 5 + 1) & 0xFFF;
            e->x = g_Spike_6DAF8.x + rcos(a) * sc->radius / 4096;
            e->y = sc->base.vy;
            e->z = g_Spike_6DAF8.z + rsin(a) * sc->radius / 4096;
            SPK_SET_SIZE(e, ((sc->rand = sc->rand * 5 + 1) & 1) + 1);
        } else {
            SPK_SET_TIMER(e, (SPK_TIMER(e) - 1) & 0x1F);
            if (SPK_TIMER(e) < 3) {
                SPK_SET_SIZE(e, 3);
            }
            e->x += sc->dx;
            e->y = sc->base.vy;
            e->z += sc->dz;
        }
        gte_ldv0(e);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        gte_stszotz(&sc->otz);
        xy = sc->sxy;
        x = (s16)xy;
        y = (s32)xy >> 16;
        if ((u32)(x + 32) > 0x1C0 || y < -32 || y > 0x110) {
            continue;
        }
        if ((u32)(sc->otz - 1) >= 0xFFF) {
            continue;
        }
        d = SPK_SIZE(e) * sc->otz;
        if (d == 0) {
            continue;
        }
        w = 0x3D80 / d;
        h = 0x30B0 / d;
        x0 = xy & 0xFFFF;
        x0 -= w / 2;
        y0 = y - h / 2;
        sc->sxy = (y0 << 16) | (x0 & 0xFFFF);
        ((u8 *)p)[3] = 9;
        p->rgbc = 0x2F000000;
        p->xy0 = sc->sxy;
        p->xy1 = (y0 << 16) | (x0 + w);
        p->xy2 = ((y0 + h) << 16) | (x0 & 0xFFFF);
        p->xy3 = ((y0 + h) << 16) | (x0 + w);
        p->uv0 = 0x7E2C4800;
        p->uv1 = 0x7C4817;
        p->uv2 = 0x5F00;
        p->uv3 = 0x5F17;
        ((PTag_6DAF8 *)p)->addr = ((PTag_6DAF8 *)&ot[sc->otz])->addr;
        ((PTag_6DAF8 *)&ot[sc->otz])->addr = (u32)p;
        p++;
    }
    D_800EC354 = (u8 *)p;
}

void func_8006E02C(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_800BAEA0[i].f_6 = 0;
    }
}

/* Adds an entry to the 8-slot ring D_800BAEA0 (next slot D_800B1B40_1): position a[0..2], a
 * 6-frame lifetime and the three bytes b[0..2] (probably its colour). func_8006E02C clears it. */
void Flare_Add(s16 *a, s16 *b) {
    s32 k = D_800B1B40_1;

    do {
        ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_6 = 6;
        ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_0 = a[0];
        ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_2 = a[1];
        ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_4 = a[2];
    } while (0);
    ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_8 = b[0];
    ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_9 = b[1];
    ((struct S_D_800BAEA0_8006E054 *)&D_800BAEA0)[k].f_A = b[2];
    k = (k + 1) % 8;
    D_800B1B40_1 = k;
}

void Flare_Add(s16 *a, s16 *b);

/* Adds a flare at pos with colour/velocity bytes b: mode 1 jitters x/z by -63..64 and raises it
   0x80, any other mode raises it by a random 0..255. (`k` is a zero index the original's register
   use needs.) */
void Flare_Spawn(s16 *pos, s16 *b, s32 mode) {
    s32 k;
    SVECTOR p;

    k = 0;
    switch (mode) {
    case 0:
    default:
        p.vx = pos[0];
        p.vy = pos[1] - ((g_RandSeed = g_RandSeed * 5 + 1) >> 8);
        p.vz = pos[2];
        break;
    case 1:
        p.vx = pos[k] + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 63);
        p.vy = pos[1] - 0x80;
        p.vz = pos[2] + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x7F) - 63);
        break;
    }
    Flare_Add(&p.vx, b);
}

INCLUDE_ASM("asm/nonmatchings/game/8006D4C0", func_8006E1C0);

INCLUDE_ASM("asm/nonmatchings/game/8006D4C0", Fx_DrawFadeRing);

void func_8006ED4C(void) {
    s32 i;
    for (i = 7; i >= 0; i--) {
        D_800F5010[i].unkA = 0;
    }
    D_800B1B74 = 0;
}

/* Effect command 0x33: start a fading ring in the next of 8 slots. It waits `delay` frames,
   then fades over 15. Radius: for b >= 0 it starts at b/4 and grows toward b; otherwise it
   starts at -b and shrinks toward 0. */
void Fx_SpawnFadeRing(SVECTOR *pos, s16 a, s32 b, u8 delay) {
    S_F5010 *p;
    D_800F5010[D_800B1B74].unkA = 0xF;
    p = &D_800F5010[D_800B1B74];
    p->unkB = delay;
    p->unk8 = a;
    D_800F5010[D_800B1B74].unk0 = *pos;
    if (b >= 0) {
        D_800F5010[D_800B1B74].unkE = b;
        D_800F5010[D_800B1B74].unkC = b >> 2;
    } else {
        D_800F5010[D_800B1B74].unkE = 0;
        D_800F5010[D_800B1B74].unkC = -b;
    }
    D_800B1B74 = (D_800B1B74 + 1) % 8;
}

/* Draw and age the fading rings: grey level timer*6, radius eased 1/8 toward the target. */
void Fx_UpdateFadeRings(void) {
    struct S_D_800F5010_8006EE3C *p;
    s32 i;
    u8 c;
    for (i = 0; i < 8; i++) {
        p = &((struct S_D_800F5010_8006EE3C *)&D_800F5010)[i];
        if (p->f_A == 0) {
            continue;
        }
        if (p->f_B != 0) {
            p->f_B--;
            continue;
        }
        c = p->f_A * 6;
        p->f_A--;
        Fx_DrawFadeRing(p, p->f_C, p->f_8, (c << 16) | (c << 8) | c);
        p->f_C = (p->f_C * 7 + p->f_E) / 8;
    }
}

void Ripple_Spawn(s16 *a) {
    s32 i;
    for (i = 7; i >= 0; i--) {
        if (D_800F4E90[i].f_6 == 0) {
            u16 r = g_RandSeed * 5 + 1;
            g_RandSeed = r;
            D_800F4E90[i].f_6 = ((r >> 8) & 3) + 0xC;
            D_800F4E90[i].f_0 = a[0];
            D_800F4E90[i].f_2 = a[1];
            D_800F4E90[i].f_4 = a[2];
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8006D4C0", Ripple_DrawAll);

void func_8006F274(SVEC_8006F274_8006F274 *a, SVEC_8006F274_8006F274 *b, u16 seed) {
    SVEC_8006F274_8006F274 pts[17];
    s32 i;
    SVEC_8006F274_8006F274 *p = pts;
    pts[0] = *a;
    for (i = 16; i >= 0; p++, i--) {
        p->vx = (a->vx * i + b->vx * (16 - i)) / 16;
        p->vy = (a->vy * i + b->vy * (16 - i)) / 16;
        p->vz = (a->vz * i + b->vz * (16 - i)) / 16;
        if (i >= 2) {
            p->vy += (s8)((seed = seed * 5 + 1) >> 8) / 2;
        }
    }
    func_8006F3D0(pts, 16, &D_800B1B90, 16);
}

INCLUDE_ASM("asm/nonmatchings/game/8006D4C0", func_8006F3D0);
