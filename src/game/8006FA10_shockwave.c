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
extern MAT_71370_80071370 g_ViewMatrix;
extern u8 g_ProjVerts[];
void RotMatrixZYX(SV3_71370_80071370 *, MAT_71370_80071370 *);
void MulMatrix0(MAT_71370_80071370 *, MAT_71370_80071370 *, MAT_71370_80071370 *);
void CompMatrix(MAT_71370_80071370 *, MAT_71370_80071370 *, MAT_71370_80071370 *);
void Model_ProjectVertsAlt(Mdl_71370_80071370 *, MAT_71370_80071370 *, u8 *);
void Model_DrawSubdiv(u32 *, u8 *, Mdl_71370_80071370 *);
void Effect_SpawnAt(s32, void *);
struct S_D_800BB920_80071370 { MAT_71370_80071370 base; SV3_71370_80071370 rot; u8 pad26[2]; SV3_71370_80071370 rv; u8 pad2E[2]; s16 x, y, z; s16 vx; s16 vy; s16 vz; s8 bounces; u8 timer; s16 floor; s16 model; u8 pad42[2]; };

struct S_D_800BAF00;
typedef struct { s16 x, y, z; u8 pad6[2]; s16 h; s16 cx; s16 cy; u8 n; u8 padF; s16 r0; s16 r1; s16 rotZ; u16 clut; u8 u0; u8 v0; u8 uw; u8 vh; u32 color; MAT_71370_80071370 m; } Shock_6FA10;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_6FA10;
#define ADDPRIM_BF_6FA10(ot, p) (((PTag_6FA10 *)(p))->addr = ((PTag_6FA10 *)(ot))->addr, ((PTag_6FA10 *)(ot))->addr = (u32)(p))
typedef struct { s32 z[33]; s32 sxy[33][2]; MAT_71370_80071370 m; SVECTOR a; SVECTOR b; } Scr_6FA10;
#define SCR_M_6FA10 (&scr->m)
#define SCR_A_6FA10 (&scr->a)
#define SCR_B_6FA10 (&scr->b)
extern u8 *D_800EC354;
void Matrix_SetIdentity(MAT_71370_80071370 *);
void RotMatrixZ(s32, MAT_71370_80071370 *);
void SetRotMatrix(MAT_71370_80071370 *);
void SetTransMatrix(MAT_71370_80071370 *);
s32 rcos(s32);
s32 rsin(s32);
#define gte_ldv0_6FA10(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_6FA10() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_6FA10(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_6FA10(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

/* Draws one shockwave ring: n + 1 points round its outer (r0, centred cx, cy, raised h) and inner
   (r1) circles, in the ring's own matrix turned by rotZ, at its position, are projected into the
   scratch pad (screen points at +0x84, depths at +0), and each of the n segments with an on-screen
   depth becomes an additive FT4 whose texture runs u0 .. u0 + uw across the ring. */
void Shockwave_Draw(struct S_D_800BAF00 *ep) {
    Shock_6FA10 *e = (Shock_6FA10 *)ep;
    Scr_6FA10 *scr = (Scr_6FA10 *)0x1F800000;
    s16 cx, cy;
    SVECTOR *va;
    s32 *zp;
    s32 *sp;
    s32 *zq, *sq;
    s32 a;
    s32 u0, q;
    u16 w;
    u8 prev, cur;
    u32 *p;
    u32 *ot;
    u32 code, v, cl, vh;
    s32 r0, r1;

    Matrix_SetIdentity(SCR_M_6FA10);
    RotMatrixZ(e->rotZ, SCR_M_6FA10);
    sp = scr->sxy[0];
    CompMatrix(&e->m, SCR_M_6FA10, SCR_M_6FA10);
    zp = scr->z;
    va = &scr->a;
    SCR_M_6FA10->t[0] = e->x;
    SCR_M_6FA10->t[1] = e->y;
    SCR_M_6FA10->t[2] = e->z;
    CompMatrix(&g_ViewMatrix, SCR_M_6FA10, SCR_M_6FA10);
    SetRotMatrix(SCR_M_6FA10);
    SetTransMatrix(SCR_M_6FA10);
    cx = e->cx;
    cy = e->cy;
    r0 = e->r0;
    r1 = e->r1;
    SCR_B_6FA10->vz = 0;
    SCR_A_6FA10->vz = e->h;
    for (a = 0x1000; a >= 0; a -= 0x1000 / ((Shock_6FA10 *)ep)->n) {
        SCR_B_6FA10->vx = rcos(a) * r1 / 4096;
        SCR_B_6FA10->vy = rsin(a) * r1 / 4096;
        SCR_A_6FA10->vx = cx + rcos(a) * r0 / 4096;
        SCR_A_6FA10->vy = cy + rsin(a) * r0 / 4096;
        gte_ldv0_6FA10(va);
        gte_rtps_6FA10();
        gte_stsxy_6FA10(sp);
        sp++;
        gte_ldv0_6FA10(SCR_B_6FA10);
        gte_rtps_6FA10();
        gte_stsxy_6FA10(sp);
        sp++;
        gte_stszotz_6FA10(zp);
        zp++;
    }
    sq = scr->sxy[0];
    zq = scr->z;
    p = (u32 *)G_DRAW.prim;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    u0 = ((Shock_6FA10 *)ep)->u0;
    cl = ((Shock_6FA10 *)ep)->clut;
    w = ((Shock_6FA10 *)ep)->uw;
    code = ((Shock_6FA10 *)ep)->color;
    vh = ((Shock_6FA10 *)ep)->vh;
    v = ((Shock_6FA10 *)ep)->v0;
    prev = u0;
    for (a = 1; a <= ((Shock_6FA10 *)ep)->n; zq++, sq += 2, a++) {
        if ((u32)(*zq - 1) < 0xFFF) {
            q = w * a / ((Shock_6FA10 *)ep)->n;
            ((u8 *)p)[3] = 9;
            p[1] = code | 0x2E000000;
            p[2] = sq[0];
            p[4] = sq[2];
            p[6] = sq[1];
            p[8] = sq[3];
            p[3] = (v << 8) | (prev & 0xFF) | (cl << 16);
            cur = u0 + q;
            p[5] = (v << 8) | (cur & 0xFF) | 0x3C0000;
            ((u16 *)p)[0xE] = (u8)prev | ((vh + v) << 8);
            ((u16 *)p)[0x12] = (u8)cur | ((vh + v) << 8);
            ADDPRIM_BF_6FA10(ot + *zq, p);
            p += 10;
        }
        prev = cur;
    }
    D_800EC354 = (u8 *)p;
}

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

typedef struct { s16 x; s16 y; s16 z; u8 state; u8 size; u8 dx; u8 dz; s16 dy; u16 f_C; u16 f_E; s32 f_10; s16 f_14; s16 f_16; s16 f_18; u8 pad1A[2]; s16 ground; u8 f_1E; u8 f_1F; } Debris_800702B0;
typedef struct { u8 count; u8 spread; u8 smin; u8 smax; u16 f_4; u16 f_6; s32 f_8; } DebrisDef_800702B0;
typedef struct { s16 vx, vy, vz, pad; } SV_800702B0;
extern Debris_800702B0 D_800BB440[];
s32 Floor_GetHeight(s32, s32, s32);
void VectorNormalSS(void *in, void *out);
#define RAND_702B0() (g_RandSeed = g_RandSeed * 5 + 1)

void func_800702B0(SV_800702B0 *pos, DebrisDef_800702B0 *p) {
    SV_800702B0 d;
    s32 ground;
    s32 n;
    s32 i;
    s32 r;
    Debris_800702B0 *s;

    ground = Floor_GetHeight(pos->vx, pos->vy, pos->vz);
    s = D_800BB440;
    n = p->count;
    for (i = 31; i >= 0; i--, s++) {
        if (s->state != 0) {
            continue;
        }
        s->state = 2;
        s->f_1E = (RAND_702B0() >> 7) & 0xFE;
        s->f_1F = (RAND_702B0() >> 8 & 0x7F) | 0x80;
        s->f_14 = 0;
        s->f_16 = 0;
        s->f_18 = 0;
        r = RAND_702B0() >> 8;
        s->size = (p->smin * r + p->smax * (0xFF - r)) >> 8;
        s->ground = ground - s->size / 2;
        s->x = pos->vx + ((((RAND_702B0() >> 8) - 0x80) * p->spread) >> 5);
        s->y = pos->vy - (s16)((((RAND_702B0() >> 8) * p->spread) >> 5) + 0x80);
        s->z = pos->vz + ((((RAND_702B0() >> 8) - 0x80) * p->spread) >> 5);
        d.vx = s->x - pos->vx;
        d.vy = (s16)(s->y + 0x80) - pos->vy;
        d.vz = s->z - pos->vz;
        VectorNormalSS(&d, &d);
        s->dx = (u16)d.vx >> 7;
        s->dy = d.vy >> 6;
        s->dz = (u16)d.vz >> 7;
        s->f_C = p->f_4;
        s->f_E = p->f_6;
        s->f_10 = p->f_8;
        if (--n == 0) {
            break;
        }
    }
}

typedef struct { s16 m[3][3]; s32 t[3]; } MAT_70560;
typedef struct { s32 vx, vy, vz, pad; } V_70560;
typedef struct { s16 vx, vy, vz, pad; } SV_70560;
typedef struct { s16 x, y, z; u8 life; u8 scale; s8 vx, vz; s16 vy; u16 clut; u16 tpage; u8 u, v, du, dv; SV_70560 rot; s16 floor; s8 spin1, spin0; } Rock_70560;
typedef struct { u8 pad0[0x40]; u32 sxy[8]; s32 otz; s32 opz; MAT_70560 m; MAT_70560 cam; } Scr_70560;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_70560;
extern Rock_70560 D_800BB440_70560[32] asm("D_800BB440");
extern SV_70560 D_800B1FC4_70560[8] asm("D_800B1FC4");
extern u32 D_800B2004_70560[8] asm("D_800B2004");
extern u8 D_800B2024_70560[12][4] asm("D_800B2024");
extern MAT_70560 D_800E78C0_70560 asm("g_ViewMatrix");
extern u32 D_800EC3D0_70560[] asm("D_800EC3D0");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; u8 pad10[0x8116]; u16 f_8126; } g_Game_70560 asm("g_Game");
void RotMatrix_70560(SV_70560 *, MAT_70560 *) asm("RotMatrix");
void ScaleMatrix_70560(MAT_70560 *, V_70560 *) asm("ScaleMatrix");
void CompMatrix_70560(MAT_70560 *, MAT_70560 *, MAT_70560 *) asm("CompMatrix");
void Effect_SpawnAt_70560(s32, void *) asm("Effect_SpawnAt");
#define gte_ldv3c_70560(p) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(p))
#define gte_ldv01c_70560(p) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0)" : : "r"(p))
#define gte_rtpt_70560() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_70560(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stsxy01c_70560(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0)" : : "r"(p) : "memory")
#define gte_stszotz_70560(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
#define gte_ldsxy3_70560(a, b, c) __asm__ volatile ("mtc2 %0, $12; nop; mtc2 %2, $14; nop; mtc2 %1, $13" : : "r"(a), "r"(b), "r"(c))
#define gte_nclip_70560() __asm__ volatile ("nop; nop; nclip")
#define gte_stopz_70560(p) __asm__ volatile ("swc2 $24, 0(%0)" : : "r"(p) : "memory")

/* Updates and draws the 32 bouncing rock fragments (D_800BB440): each active rock spins, is drawn
   as a small 8-vertex, 12-face gouraud-textured model (semi-transparent on stage 0x23), and while
   on screen falls under gravity; hitting its floor height halves its speed, bounces it up (at most
   0x30) and, until its bounces run out, spawns effect 4. */
void func_80070560(void) {
    Scr_70560 *sc = (Scr_70560 *)0x1F800000;
    Rock_70560 *r;
    s32 i, f;
    V_70560 s;
    u32 tp;
    s32 u, v, du, dv, clut;
    u32 semi;
    u32 *ot;
    u8 *prim;
    u8 *fp;
    u8 *ob;

    i = 31;
    r = D_800BB440_70560;
    sc->cam = D_800E78C0_70560;
    semi = (g_Game_70560.f_8126 == 0x23) << 25;
    for (; i >= 0; i--, r++) {
        ob = (u8 *)D_800EC3D0_70560;
        if (r->life == 0) {
            continue;
        }
        r->rot.vx += r->spin0;
        r->rot.vy += r->spin0;
        r->rot.vz += r->spin1;
        RotMatrix_70560(&r->rot, &sc->m);
        s.vx = r->scale << 6;
        s.vy = r->scale << 6;
        s.vz = r->scale << 6;
        ScaleMatrix_70560(&sc->m, &s);
        sc->m.t[0] = r->x;
        sc->m.t[1] = r->y;
        sc->m.t[2] = r->z;
        CompMatrix_70560(&sc->cam, &sc->m, &sc->m);
        SetRotMatrix(&sc->m);
        SetTransMatrix(&sc->m);
        gte_ldv3c_70560(&D_800B1FC4_70560[0]);
        gte_rtpt_70560();
        gte_stsxy3c_70560(&sc->sxy[0]);
        gte_stszotz_70560(&sc->otz);
        if ((u32)(sc->otz - 1) >= 0xFFF) {
            continue;
        }
        gte_ldv3c_70560(&D_800B1FC4_70560[3]);
        gte_rtpt_70560();
        gte_stsxy3c_70560(&sc->sxy[3]);
        gte_ldv01c_70560(&D_800B1FC4_70560[6]);
        gte_rtpt_70560();
        gte_stsxy01c_70560(&sc->sxy[6]);
        prim = g_Game_70560.prim;
        ot = (u32 *)(ob + g_Game_70560.cur * 0x4078);
        tp = r->tpage; u = r->u; v = r->v; du = r->du; dv = r->dv; clut = r->clut;
        for (f = 12, fp = D_800B2024_70560[0]; f > 0; f--, fp += 4) {
            gte_ldsxy3_70560(sc->sxy[fp[0]], sc->sxy[fp[1]], sc->sxy[fp[2]]);
            gte_nclip_70560();
            gte_stopz_70560(&sc->opz);
            if (sc->opz >= 0) {
                prim[3] = 9;
                ((u32 *)prim)[1] = (tp & 0x9FF) | 0xE1000200;
                { u32 c; u32 t; __asm__ volatile("" : "=r"(c) : "0"(0x34000000)); t = D_800B2004_70560[fp[0]] | c; ((u32 *)prim)[1] = semi | t; }
                ((u32 *)prim)[2] = sc->sxy[fp[0]];
                ((u32 *)prim)[3] = (v << 8) | (u16)u | (clut << 16);
                ((u32 *)prim)[4] = D_800B2004_70560[fp[1]];
                ((u32 *)prim)[5] = sc->sxy[fp[1]];
                ((u32 *)prim)[6] = (v << 8) | ((u16)u + du) | (tp << 16);
                ((u32 *)prim)[7] = D_800B2004_70560[fp[2]];
                ((u32 *)prim)[8] = sc->sxy[fp[2]];
                ((u16 *)prim)[18] = u | ((v + dv) << 8);
                ((Tag_70560 *)prim)->addr = ((Tag_70560 *)&ot[sc->otz])->addr;
                ((Tag_70560 *)&ot[sc->otz])->addr = (u32)prim;
                prim += 0x28;
            }
        }
        g_Game_70560.prim = prim;
        r->x += r->vx;
        r->y += r->vy;
        r->z += r->vz;
        r->vy += 6;
        if (r->floor < r->y) {
            r->y = r->floor;
            r->vx /= 2;
            r->vz /= 2;
            r->vy = -r->vy / 2;
            if (r->vy < -0x30) {
                r->vy = -0x30;
            }
            if (--r->life != 0) {
                Effect_SpawnAt_70560(4, r);
            }
        }
    }
}

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

typedef struct { s16 vx, vy, vz, pad; } SV_71120;
typedef struct { SV_71120 rot; SV_71120 spin; s16 x, y, z; s16 vx, vy, vz; u8 state; u8 f_1D; s16 ground; s16 f_20; s16 pad22; } Deb_71120;
typedef struct { u8 m[0x20]; Deb_71120 d; } Piece_71120;
typedef struct { s16 x, y, z, rx, ry, rz; } Off_71120;
extern Piece_71120 D_800BB920_71120[] asm("D_800BB920");
extern Off_71120 D_800B2060[];
extern u8 D_800B205D;
extern u16 D_800AE8F2;
void func_800147D0_71120(SV_71120 *, void *) asm("Matrix_SetScale");
#define RAND_71120() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2_71120() (D_800AE8F2 = D_800AE8F2 * 5 + 1)

void func_80071120(SV_71120 *pos, s32 kind) {
    s32 i;
    s32 g;
    Piece_71120 *p;
    Deb_71120 *d;
    Off_71120 *o;
    SV_71120 r;

    g = Floor_GetHeight(pos->vx, pos->vy, pos->vz);
    p = D_800BB920_71120;
    for (i = 0; i < 6; i++, p++) {
        d = &p->d;
        o = &D_800B2060[i];
        d->state = 3;
        d->f_1D = 0;
        d->x = pos->vx + o->x;
        d->y = pos->vy + o->y;
        d->z = pos->vz + o->z;
        d->vx = (RAND2_71120() >> 8 & 0x3F) - 0x20;
        d->vy = (RAND_71120() >> 8 & 0x3F) - 0x5A;
        d->vz = (RAND2_71120() >> 8 & 0x3F) - 0x20;
        d->ground = g;
        d->f_20 = kind;
        d->spin.vx = (RAND_71120() >> 8) - 0x80;
        d->spin.vy = (RAND2_71120() >> 8) - 0x80;
        d->spin.vz = (RAND_71120() >> 8) - 0x80;
        d->rot = d->spin;
        r.vx = o->rx;
        r.vy = o->ry;
        r.vz = o->rz;
        func_800147D0_71120(&r, p->m);
        D_800B205D = (D_800B205D + 1) % 12;
    }
}

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
        CompMatrix(&g_ViewMatrix, &m, &m);
        Model_ProjectVertsAlt(&D_800B4D64[d->model], &m, g_ProjVerts);
        Model_DrawSubdiv(g_Game.db[g_Game.cur].ot, g_ProjVerts, &D_800B4D64[d->model]);
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
