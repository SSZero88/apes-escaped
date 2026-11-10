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
void Fx_DrawFadeRing(void *, s32, s32, s32);
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

extern u8 g_Game[];
typedef struct { s16 x, y, z; u8 life; u8 kind; } Dust_6D5A8;
typedef struct { s32 seed; s32 sxy; s32 z; SVECTOR v; } Scr_6D5A8;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6D5A8;
#define ADDPRIM_BF_6D5A8(ot, p) (((PTag_6D5A8 *)(p))->addr = ((PTag_6D5A8 *)(ot))->addr, ((PTag_6D5A8 *)(ot))->addr = (u32)(p))
#define RND_6D5A8() (scr->seed = scr->seed * 5 + 1)
extern Dust_6D5A8 D_800BADA0_6D5A8[] asm("D_800BADA0");
extern u8 *D_800EC354_6D5A8 asm("D_800EC354");
extern u16 g_RandSeed_6D5A8 asm("g_RandSeed");
extern u8 D_800E78C0_6D5A8[] asm("g_ViewMatrix");
void SetRotMatrix_6D5A8(void *) asm("SetRotMatrix");
void SetTransMatrix_6D5A8(void *) asm("SetTransMatrix");
#define gte_ldv0_6D5A8(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_n6D5A8() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_6D5A8(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6D5A8(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

/* Dust clouds: each live entry of the 32 in D_800BADA0 jitters (unless kind 1) by its own random
   sequence (seeded from g_RandSeed in the scratch pad), then three puffs scattered round it are
   drawn as additive sprites sized 2 * life + 4 (kind 2) or 3 * life + 0x10, brightness 2 * life +
   0x10, with the 5-frame dust animation picked by life; life counts down by 1 a frame. */
void func_8006D5A8(void) {
    Scr_6D5A8 *scr = (Scr_6D5A8 *)0x1F800000;
    Dust_6D5A8 *e;
    u32 *p;
    u32 *ot;
    s32 i, j, c, col, r, tp, tw, x;
    s16 y;
    u8 w, h;
    s16 x0, y0;

    SetRotMatrix_6D5A8(D_800E78C0_6D5A8);
    SetTransMatrix_6D5A8(D_800E78C0_6D5A8);
    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (u32 *)G_DRAW.prim;
    scr->seed = g_RandSeed_6D5A8;
    for (i = 31, e = D_800BADA0_6D5A8; i >= 0; i--, e++) {
        if (e->life == 0) {
            continue;
        }
        c = (u8)(e->life * 2 + 0x10);
        col = (c << 16) | (c << 8) | (c + 8);
        tp = 0x3C;
        if (e->kind != 1) {
            { s32 d = (RND_6D5A8() & 0xF) + 0xFFF9; e->x += d; }
            { s32 d = (RND_6D5A8() & 0xF) + 0xFFE4; e->y += d; }
            { s32 d = (RND_6D5A8() & 0xF) + 0xFFF9; e->z += d; }
        }
        if (e->kind == 2) {
            r = e->life * 2 + 4;
        } else {
            r = e->life * 3 + 0x10;
        }
        for (j = 2; j >= 0; j--) {
            scr->v.vx = e->x + (RND_6D5A8() & 0xF) - 7;
            scr->v.vy = e->y + (RND_6D5A8() & 0x1F) - 0x10;
            scr->v.vz = e->z + (RND_6D5A8() & 0xF) - 7;
            gte_ldv0_6D5A8(&scr->v);
            gte_rtps_n6D5A8();
            gte_stsxy_6D5A8(&scr->sxy);
            gte_stszotz_6D5A8(&scr->z);
            x = (u16)scr->sxy;
            y = scr->sxy >> 16;
            if ((u16)(x + 0x20) >= 0x1C1 || y < -0x20 || y >= 0x111 || (u32)(scr->z - 1) >= 0xFFF) {
                continue;
            }
            w = r * 0x148 / scr->z;
            h = r * 0x148 * 0x11D00 / 0x16800 / scr->z;
            ((u8 *)p)[3] = 9;
            p[1] = col | 0x2E000000;
            tw = (tp << 16) | 0xC800;
            x0 = x - (w >> 1);
            y0 = y - (h >> 1);
            p[2] = (y0 << 16) | (x0 & 0xFFFF);
            p[4] = (y0 << 16) | (x0 + w);
            p[6] = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p[8] = ((y0 + h) << 16) | (x0 + w);
            p[3] = ((4 - (e->life >> 1)) * 0x30) | 0x7C2CC800;
            p[5] = ((4 - (e->life >> 1)) * 0x30 + 0x2F) | tw;
            ((u16 *)p)[0xE] = ((4 - (e->life >> 1)) * 0x30) | -0x200;
            ((u16 *)p)[0x12] = ((4 - (e->life >> 1)) * 0x30 + 0x2F) | -0x200;
            ADDPRIM_BF_6D5A8(ot + scr->z, p);
            p += 10;
        }
        e->life--;
    }
    D_800EC354_6D5A8 = (u8 *)p;
}

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
extern u8 g_ViewMatrix[];
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
    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
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

typedef struct { s16 x, y, z; s8 life; u8 pad7; s8 vx, vy, vz; u8 padB; } Spark_6E1C0;
typedef struct { s32 z; s32 sxy[3]; SVECTOR v[3]; } Scr_6E1C0;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6E1C0;
#define ADDPRIM_BF_6E1C0(ot, p) (((PTag_6E1C0 *)(p))->addr = ((PTag_6E1C0 *)(ot))->addr, ((PTag_6E1C0 *)(ot))->addr = (u32)(p))
extern Spark_6E1C0 D_800BAEA0_6E1C0[] asm("D_800BAEA0");
extern struct { u8 pad0[0x24]; s32 x, y, z, vx, vy, vz; u8 pad3C[0x22]; u16 state; } g_Spike_6E1C0 asm("g_Spike");
void memset(void *, s32, s32);
#define gte_ldv3c_6E1C0(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_n6E1C0() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_6E1C0(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6E1C0(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

/* Spike's sparks. In state 6 a flare is spawned at Spike moving against his velocity. Then each of
   the 8 sparks in D_800BAEA0 still alive moves by its velocity, loses a frame of life and is drawn
   as two crossed translucent gouraud triangles of half-size life + 1 with a tail 6 velocities long. */
void func_8006E1C0(void) {
    Scr_6E1C0 *scr = (Scr_6E1C0 *)0x1F800000;
    SVECTOR pos, vel, t;
    Spark_6E1C0 *e;
    u32 *p;
    u32 *ot;
    s32 i, j, s;

    if (g_Spike_6E1C0.state == 6) {
        memset(&vel, 0, 8);
        vel.vx = g_Spike_6E1C0.x;
        vel.vy = g_Spike_6E1C0.y;
        vel.vz = g_Spike_6E1C0.z;
        pos = vel;
        memset(&t, 0, 8);
        t.vx = -g_Spike_6E1C0.vx;
        t.vz = -g_Spike_6E1C0.vz;
        vel = t;
        Flare_Spawn((s16 *)&pos, (s16 *)&vel, 0);
    }
    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (u32 *)G_DRAW.prim;
    for (i = 7; i >= 0; i--) {
        e = &D_800BAEA0_6E1C0[i];
        if (e->life == 0) {
            continue;
        }
        e->x += e->vx;
        e->y += e->vy;
        e->z += e->vz;
        s = e->life + 1;
        e->life--;
        scr->v[0].vx = e->x - s;
        scr->v[0].vy = e->y - s;
        scr->v[0].vz = e->z - s;
        scr->v[1].vx = e->x + s;
        scr->v[1].vy = e->y + s;
        scr->v[1].vz = e->z + s;
        scr->v[2].vx = e->x + e->vx * 6;
        scr->v[2].vy = e->y + e->vy * 6;
        scr->v[2].vz = e->z + e->vz * 6;
        for (j = 2; j > 0; j--) {
            gte_ldv3c_6E1C0(scr->v);
            gte_rtpt_n6E1C0();
            gte_stsxy3c_6E1C0(scr->sxy);
            gte_stszotz_6E1C0(&scr->z);
            if ((u32)(scr->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 7;
                p[1] = 0xE1000220;
                p[2] = 0x336E5A3C;
                p[4] = 0x6E5A3C;
                p[6] = 0;
                p[3] = scr->sxy[0];
                p[5] = scr->sxy[1];
                p[7] = scr->sxy[2];
                ADDPRIM_BF_6E1C0(ot + scr->z, p);
                scr->v[0].vx = D_800BAEA0_6E1C0[i].x + s;
                scr->v[1].vx = D_800BAEA0_6E1C0[i].x - s;
                scr->v[0].vy = D_800BAEA0_6E1C0[i].y + s;
                scr->v[1].vy = D_800BAEA0_6E1C0[i].y - s;
                p += 8;
            }
        }
    }
    D_800EC354 = (u8 *)p;
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_6E5B4;
typedef struct { MAT_6E5B4 m; SVECTOR v; s32 z; s32 nz; u32 vert[144]; } Scr_6E5B4;
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad2; u32 xy3; u16 uv3; u16 pad3; } FT4_6E5B4;
typedef struct { u32 tag; u32 code; u32 w; } DrMode_6E5B4;
typedef struct { u16 clut; u8 u0; u8 v0; u8 du; u8 dv; } Tex_6E5B4;
extern MAT_6E5B4 D_800AE840;
extern Tex_6E5B4 D_800B1B44[];
extern s32 D_800EC35C;
extern struct { s32 f_0; } g_Game_6E5B4 asm("g_Game");
void *RotMatrixY(s32, void *);
void *CompMatrix(void *, void *, void *);
void SetRotMatrix(void *);
void SetTransMatrix(void *);
#define GD_6E5B4 (*(GameDraw *)&g_Game_6E5B4)
#define gte_ldv0_6E5B4(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_6E5B4() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_6E5B4(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6E5B4(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
#define gte_ldsxy3_6E5B4(a, b, c) __asm__ volatile ("mtc2 %0, $12; nop; mtc2 %2, $14; nop; mtc2 %1, $13" : : "r"(a), "r"(b), "r"(c))
#define gte_nclip_6E5B4() __asm__ volatile ("nop; nop; nclip")
#define gte_stopz_6E5B4(p) __asm__ volatile ("swc2 $24, 0(%0)" : : "r"(p) : "memory")
typedef struct { u32 addr : 24; u32 len : 8; } PT_6E5B4;
#define ADDP_6E5B4(o, q) (((PT_6E5B4 *)(q))->addr = ((PT_6E5B4 *)(o))->addr, ((PT_6E5B4 *)(o))->addr = (u32)(q))

void Fx_DrawFadeRing(void *arg0, s32 r, s32 flags, s32 color) {
    long long ll; /* each ll = i adds ~4 insns to loop.c's count but leaves only a CLOBBER later; asm def at end gives ll a GPR class (no stack slot) */
    SVECTOR *pos = (SVECTOR *)arg0;
    Scr_6E5B4 *scr = (Scr_6E5B4 *)0x1F800000;
    u32 *sxy;
    s32 i, j, a, c;

    scr->m = D_800AE840;
    scr->m.m[2][2] = r;
    scr->m.m[1][1] = r;
    scr->m.m[0][0] = r;
    RotMatrixY(-((g_Game_6E5B4.f_0 << 6) & 0xFFF), &scr->m); sxy = scr->vert;
    scr->m.t[0] = pos->vx;
    scr->m.t[1] = pos->vy;
    scr->m.t[2] = pos->vz;
    CompMatrix(g_ViewMatrix, &scr->m, &scr->m);
    SetRotMatrix(&scr->m);
    SetTransMatrix(&scr->m);
    for (i = 0; i < 12; i++) {
        a = (i << 11) / 11 - 0x400;
        c = rcos(a);
        scr->v.vy = rsin(a);
        for (j = 0; j < 12; j++) {
            a = (j << 12) / 11;
            scr->v.vx = rcos(a) * c / 4096;
            scr->v.vz = rsin(a) * c / 4096;
            gte_ldv0_6E5B4(&scr->v);
            gte_rtps_6E5B4();
            gte_stsxy_6E5B4(sxy);
            sxy++;
        }
    }
    gte_stszotz_6E5B4(&scr->z);
    scr->z -= (u32)r >> 2;
    if (scr->z <= 0) {
        scr->z = 1;
    }
    if (scr->z < 0x800) {
        Tex_6E5B4 *e, *tb;
        u32 *ot;
        FT4_6E5B4 *p;
        u16 clut, u0, v0;
        u8 du, dv;
        s32 k, n, t;
        u8 uc, un, vc, vn;

        tb = D_800B1B44; e = &tb[flags & 0xFF];
        ot = GD_6E5B4.db[GD_6E5B4.cur].ot;
        p = (FT4_6E5B4 *)GD_6E5B4.prim;
        clut = e->clut;
        u0 = e->u0;
        v0 = e->v0;
        du = e->du;
        dv = e->dv;

        if (!(flags & 0x100)) {
            k = 0;
            vc = v0;
            for (i = 0; i < 0x84; i += 12) {
                k++;
                vn = v0 + dv * k / 11;
                uc = u0;
                for (j = i, t = 0; j < i + 12; j++) {
                    n = j + 1;
                    if (n >= i + 12) {
                        n = i;
                    }
                    gte_ldsxy3_6E5B4(scr->vert[j], scr->vert[n], scr->vert[j + 12]);
                    gte_nclip_6E5B4();
                    gte_stopz_6E5B4(&scr->nz);
                    ((u8 *)p)[3] = 9;
                    t++;
                    un = (u8)u0 + du * t / 11;
                    p->code = color | 0x2E000000;
                    p->xy0 = scr->vert[j];
                    p->xy1 = scr->vert[n];
                    p->xy2 = scr->vert[j + 12];
                    p->xy3 = scr->vert[n + 12];
                    p->uv0 = (vc << 8) | uc | (clut << 16);
                    p->uv1 = (vc << 8) | (un - 1) | 0x3C0000;
                    p->uv2 = uc | ((vn - 1) << 8);
                    p->uv3 = ((vn - 1) << 8) | (un - 1);
                    uc = un;
                    ADDP_6E5B4(&ot[scr->z], p);
                    p++;
                }
                vc = vn;
                __asm__("" :: "r"(vc));

            }
        }
        if (flags & 0x200) {
            u32 tp = D_800EC35C != 0 ? 0x112 : 0x102;
            DrMode_6E5B4 *d = (DrMode_6E5B4 *)p;
            u8 vv = 0, tu;
            ((u8 *)d)[3] = 2;
            d->code = 0xE6000000;
            d->w = 0;
            ADDP_6E5B4(&ot[1], d);
            p = (FT4_6E5B4 *)(d + 1);
            for (i = 0; i < 0x84; vv += 0x14, i += 12) {
                for (tu = 0, j = i; j < i + 12; tu += 0x15, j++) {
                    n = j + 1;
                    if (n >= i + 12) {
                        n = i;
                    }
                    gte_ldsxy3_6E5B4(scr->vert[j], scr->vert[n], scr->vert[j + 12]);
                    gte_nclip_6E5B4();
                    gte_stopz_6E5B4(&scr->nz);
                    if (scr->nz < 0) {
                        ((u8 *)p)[3] = 9;
                        p->code = 0x2F000000;
                        p->xy0 = scr->vert[j];
                        p->xy1 = scr->vert[n];
                        p->xy2 = scr->vert[j + 12];
                        p->xy3 = scr->vert[n + 12];
                        p->uv0 = (vv << 8) | tu;
                        p->uv1 = (vv << 8) | (tu + 0x14) | (tp << 16);
                        p->uv2 = tu | ((vv + 0x13) << 8);
                        p->uv3 = ((vv + 0x13) << 8) | (tu + 0x14);
                        ADDP_6E5B4(&ot[1], p);
                        p++;
                    }
                } __asm__("" :: "r"(ot)); ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i; ll = i;
            }
            d = (DrMode_6E5B4 *)p;
            ((u8 *)d)[3] = 2;
            d->code = 0xE6000001;
            d->w = 0;
            ADDP_6E5B4(&ot[1], d);
            p = (FT4_6E5B4 *)(d + 1);
        }
        GD_6E5B4.prim = (u8 *)p; __asm__("" :: "r"(scr), "r"(scr), "r"(scr), "r"(scr), "r"(scr), "r"(scr), "r"(scr), "r"(scr)); __asm__("" :: "r"(scr), "r"(scr)); 
    } __asm__ volatile("" : "=r"(ll));
}

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

typedef struct { s16 vx, vy, vz; u8 timer; u8 pad7; } Ripple_6EFAC;
typedef struct { s32 z; s32 pad4; SVECTOR v[4]; s32 sxy[4]; } Scr_6EFAC;
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad1E; u32 xy3; u16 uv3; u16 pad26; } FT4_6EFAC;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6EFAC;
#define ADDPRIM_BF(ot, p) (((PTag_6EFAC *)(p))->addr = ((PTag_6EFAC *)(ot))->addr, ((PTag_6EFAC *)(ot))->addr = (u32)(p))
extern Ripple_6EFAC D_800F4E90_6EFAC[] asm("D_800F4E90");
void SetRotMatrix(void *);
void SetTransMatrix(void *);
#define gte_ldv3c_6EFAC(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_n6EFAC() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_6EFAC(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_ldv0_6EFAC(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_n6EFAC() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_6EFAC(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6EFAC(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

/* Water ripples (D_800F4E90, 8 entries set by Ripple_Spawn): each live one counts its timer down
   and is drawn as a flat textured square on the water, half-size 0x18 + 12 * timer (so it grows as
   it fades), its colour (8, 12, 16) * timer, additive, when on screen. */
void Ripple_DrawAll(void) {
    Scr_6EFAC *scr = (Scr_6EFAC *)0x1F800000;
    Ripple_6EFAC *r;
    FT4_6EFAC *p;
    u32 *ot;
    s32 i, s, x, y;
    register s32 t asm("$3");

    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (FT4_6EFAC *)G_DRAW.prim;
    for (i = 7; i >= 0; i--) {
        r = &D_800F4E90_6EFAC[i];
        { s32 c = r->timer;
        if (c == 0) {
            continue;
        }
        __asm__("" : "=r"(t) : "0"(c)); }
        r->timer = t - 1;
        s = t * 12 + 0x18;
        scr->v[0].vx = r->vx - s;
        scr->v[0].vy = r->vy;
        scr->v[0].vz = r->vz - s;
        scr->v[1].vx = r->vx + s;
        scr->v[1].vy = r->vy;
        scr->v[1].vz = r->vz - s;
        scr->v[2].vx = r->vx - s;
        scr->v[2].vy = r->vy;
        scr->v[2].vz = r->vz + s;
        scr->v[3].vx = r->vx + s;
        scr->v[3].vy = r->vy;
        scr->v[3].vz = r->vz + s;
        gte_ldv3c_6EFAC(scr->v);
        gte_rtpt_n6EFAC();
        gte_stsxy3c_6EFAC(scr->sxy);
        gte_ldv0_6EFAC(&scr->v[3]);
        gte_rtps_n6EFAC();
        gte_stsxy_6EFAC(&scr->sxy[3]);
        gte_stszotz_6EFAC(&scr->z);
        y = scr->sxy[3];
        x = (s16)y;
        y >>= 16;
        if ((u32)(x + 0x20) >= 0x1C1 || y < -0x20 || y >= 0x111 || (u32)(scr->z - 1) >= 0xFFF) {
            continue;
        }
        { s32 c = r->timer;
        ((u8 *)p)[3] = 9;
        p->code = (c << 20) | ((c * 3) << 10) | (c << 3) | 0x2E000000; }
        p->xy0 = scr->sxy[0];
        p->xy1 = scr->sxy[1];
        p->xy2 = scr->sxy[2];
        p->xy3 = scr->sxy[3];
        p->uv0 = 0x7CAC00C0;
        p->uv2 = 0x2FC0;
        p->uv1 = 0x7C00EF;
        p->uv3 = 0x2FEF;
        ADDPRIM_BF(ot + scr->z, p);
        p++;
    }
    D_800EC354 = (u8 *)p;
}

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

typedef struct { u16 clut; u16 tpage; u8 u; u8 v; u8 du; u8 dv; } Tex_6F3D0;
typedef struct { SVEC_8006F274_8006F274 dir; s32 sxy; s32 otz[16]; s32 w[16]; s16 sx[16]; s16 sy[16]; s16 edge[64]; } Scr_6F3D0;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6F3D0;
#define ADDPRIM_BF_6F3D0(ot, p) (((PTag_6F3D0 *)(p))->addr = ((PTag_6F3D0 *)(ot))->addr, ((PTag_6F3D0 *)(ot))->addr = (u32)(p))
#define gte_stszotz_6F3D0(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
s32 VectorNormalSS_6F3D0(void *, void *) asm("VectorNormalSS");

/* Draws a textured ribbon through up to 16 points: each point is projected (repeats of the same
   screen position are dropped), its half-width is `width` * 0xA4 / depth (0 when off-screen or too
   near), and the strip edges are offset across the screen-space direction of travel. One
   semi-transparent quad per segment, with u stepping from tex->u by tex->du over the strip. */
void func_8006F3D0(SVEC_8006F274_8006F274 *pts, s32 n, void *vtex, s32 width) {
    Scr_6F3D0 *sc = (Scr_6F3D0 *)0x1F800000;
    s32 i, prev, a, b;
    s32 *pz, *pw, *qw;
    s16 *px, *py, *pe, *qe;
    u8 *prim;
    u32 *ot;
    s32 u0, acc, q;
    u8 nu, u;
    u16 du;
    u32 v, dv, clut, tpage;

    if (n < 2) {
        return;
    }
    if (n > 16) {
        n = 16;
    }
    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    width *= 0xA4;
    {
        s32 *qz = sc->otz;
        s16 *qx = sc->sx;
        s16 *qy = sc->sy;
        SVEC_8006F274_8006F274 *p;

        prev = 0;
        for (i = n, p = pts; i > 0; i--, p++) {
        gte_ldv0(p);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        if (sc->sxy == prev) {
            n--;
            if (n < 2) {
                return;
            }
        } else {
            *qx++ = sc->sxy;
            *qy++ = sc->sxy >> 16;
            gte_stszotz_6F3D0(qz);
            qz++;
        }
        prev = sc->sxy;
        }
    }
    {
        s32 *qz = sc->otz;
        s32 *qw = sc->w;
        s16 *qx = sc->sx;
        s16 *qy = sc->sy;

        for (i = 0; i < n; i++, qx++, qy++, qw++, qz++) {
            if (*qz >= 0x1000) {
                return;
            }
            if ((u16)(*qx + 0x20) > 0x1C0 || *qy < -0x20 || *qy > 0x110 || *qz < 2) {
                *qw = 0;
            } else {
                *qw = width / *qz;
            }
        }
    }
    px = sc->sx;
    py = sc->sy;
    sc->dir.vz = 0;
    sc->dir.vx = px[1] - sc->sx[0];
    sc->dir.vy = py[1] - sc->sy[0];
    VectorNormalSS_6F3D0(&sc->dir, &sc->dir);
    {
        s32 a, b;
        a = (sc->dir.vy * sc->w[0]) >> 12;
        b = (sc->dir.vx * sc->w[0]) >> 12;
        pw = &sc->w[1];
        pe = sc->edge;
        *pe++ = sc->sx[0] - a;
        *pe++ = sc->sy[0] + b;
        *pe++ = sc->sx[0] + a;
        *pe++ = sc->sy[0] - b;
    }
    if (n >= 3) {
        for (i = 0; i < n - 2; i++) {
            sc->dir.vx = px[2] - px[0];
            sc->dir.vy = py[2] - py[0];
            if (VectorNormalSS_6F3D0(&sc->dir, &sc->dir) == 0) {
                sc->dir.vx = px[2] - px[1];
                sc->dir.vy = py[2] - py[1];
                VectorNormalSS_6F3D0(&sc->dir, &sc->dir);
            }
            {
                s32 a, b;
                a = (sc->dir.vy * *pw) >> 12;
                b = (sc->dir.vx * *pw) >> 12;
                px++;
                py++;
                pw++;
                *pe++ = *px - a;
                *pe++ = *py + b;
                *pe++ = *px + a;
                *pe++ = *py - b;
            }
        }
    }
    sc->dir.vx = px[1] - px[0];
    sc->dir.vy = py[1] - py[0];
    VectorNormalSS_6F3D0(&sc->dir, &sc->dir);
    {
        s32 a, b;
        a = (sc->dir.vy * *pw) >> 12;
        b = (sc->dir.vx * *pw) >> 12;
        px++;
        py++;
        *pe++ = *px - a;
        *pe++ = *py + b;
        *pe++ = *px + a;
        *pe = *py - b;
    }

    prim = G_DRAW.prim;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    u0 = ((Tex_6F3D0 *)vtex)->u;
    v = ((Tex_6F3D0 *)vtex)->v;
    du = ((Tex_6F3D0 *)vtex)->du;
    dv = ((Tex_6F3D0 *)vtex)->dv;
    clut = ((Tex_6F3D0 *)vtex)->clut;
    tpage = ((Tex_6F3D0 *)vtex)->tpage;
    u = u0;
    qe = sc->edge;
    qw = sc->w;
    pz = sc->otz;
    for (i = 0; i < n - 1; i++, qe += 4, qw++, pz++) {
        if (*qw != 0) {
            q = du * (i + 1) / (n - 1);
            prim[3] = 9;
            ((u32 *)prim)[1] = 0x2F000000;
            ((u32 *)prim)[2] = *(u32 *)&qe[0];
            ((u32 *)prim)[4] = *(u32 *)&qe[4];
            ((u32 *)prim)[6] = *(u32 *)&qe[2];
            ((u32 *)prim)[8] = *(u32 *)&qe[6];
            ((u32 *)prim)[3] = (v << 8) | (u & 0xFF) | (clut << 16);
            nu = u0 + q;
            ((u32 *)prim)[5] = (v << 8) | (nu & 0xFF) | (tpage << 16);
            ((u16 *)prim)[14] = (u8)u | ((dv + v) << 8);
            ((u16 *)prim)[18] = (u8)nu | ((dv + v) << 8);
            ADDPRIM_BF_6F3D0(&ot[*pz], prim);
            prim += 0x28;
            u = nu;
        }
    }
    G_DRAW.prim = prim;
}
