#include "common.h"
#include "m2c_macros.h"
#include "gte.h"
typedef struct { u8 pad0[0x10]; s16 x; s16 y; s16 z; } Scratch_8001F4D4;
typedef struct { u8 pad0[8]; u16 f_8; } S_20A20_80020A20;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } V_8001F434_8001F434;

s32 VectorNormalSS(void *v0, void *v1);

extern struct S_D_800EBFA0 { u8 pad0[0x24]; s16 f_24; s16 pad26; s16 f_28; } D_800EBFA0;

extern s32 D_800B8AB0;
extern s32 g_Game;

/* Walks the 4096-entry ordering table from the back and, for each run of empty entries
 * (each just pointing at the previous one), links the run's first entry straight to the next
 * non-empty one, so the GPU skips the run. */
void Ot_SkipEmptyRuns(u32 *ot) {
    u32 *p;
    u32 *start = 0;
    ot = (u32 *)((u32)ot & 0xFFFFFF);
    for (p = ot + 0xFFF; ot < p; p--) {
        if (start == 0) {
            if ((*p & 0xFFFFFF) == (u32)(p - 1)) {
                start = p;
            }
        } else if ((*p & 0xFFFFFF) != (u32)(p - 1)) {
            *start = (*start & 0xFF000000) | ((u32)p & 0xFFFFFF);
            start = 0;
        }
    }
}

/* Ripple effect: for the `n` vertices higher than `lim` (vy > lim), adds a small offset to vx
 * and vy from a triangle wave over (frame + vz/64 + vy/4) & 15. */
void Mesh_WaveVertices(V_8001F434_8001F434 *p, s32 n, s32 lim) {
    s32 frame = g_Game;
    s32 i;
    s32 k;
    for (i = 0; i < n; i++) {
        if (lim < p[i].f_2) {
            k = (frame + p[i].f_4 / 64 + p[i].f_2 / 4) & 0xF;
            if (k >= 8) {
                k = 15 - k;
            }
            p[i].f_0 += k >> 1;
            p[i].f_2 += k >> 2;
        }
    }
}

void func_8001F4D4(SVECTOR *p, s32 n, s32 c, s32 r)
{
  Scratch_8001F4D4 *sc = (Scratch_8001F4D4 *) 0x1F800000;
  s32 i;
  s32 r2;
  s16 *py;
  s32 cx = (s16) c;
  s32 cy = c >> 16;
  sc->z = 0;
  r2 = r * r;
  ;
  for (i = 0; i < n; i++)
  {
    sc->x = p->vx - cx;
    sc->y = (*(&p->vy)) - cy;
    if (r2 < VectorNormalSS(&sc->x, &sc->x))
    {
      p->vx = cx + ((sc->x * r) >> 12);
      *(&p->vy) = cy + ((sc->y * r) >> 12);
    }
    py += 4;
    p++;
  }

}

extern u8 D_800E78C0[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Matrix_LookAt(SVECTOR *a, SVECTOR *b, void *m, s32 c);
typedef struct { s32 x, y, z; } Pos_1F604;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_1F604;
typedef struct { Mat_1F604 m; SVECTOR a, b, c, d, e; } Scr_1F604;
typedef struct { u32 tag; u8 r0, g0, b0, code; u32 xy0; u16 uv0, clut; u32 xy1; u16 uv1, tpage; u32 xy2; u16 uv2, pad2; u32 xy3; u16 uv3, pad3; } PolyFT4_1F604;
#define gte_ldv01(a, b) __asm__ volatile ("lwc2 $0, %0; lwc2 $1, %1; lwc2 $2, %2; lwc2 $3, %3" : : "m"(*(u32 *)&(a)), "m"(*((u32 *)&(a) + 1)), "m"(*(u32 *)&(b)), "m"(*((u32 *)&(b) + 1)))
#define gte_ldv2(a) __asm__ volatile ("lwc2 $4, %0; lwc2 $5, %1" : : "m"(*(u32 *)&(a)), "m"(*((u32 *)&(a) + 1)))
#define gte_rtpt_() __asm__ volatile ("rtpt")
#define gte_stSZ3_(r) __asm__ volatile ("mfc2 %0, $19; nop" : "=r"(r))
#define gte_stsxy0_(p) __asm__ volatile ("swc2 $12, %0" : "=m"(p))
#define gte_stsxy1_(p) __asm__ volatile ("swc2 $13, %0" : "=m"(p))
#define gte_stsxy2_(p) __asm__ volatile ("swc2 $14, %0" : "=m"(p))

/* Round drop shadow under an object at pos on the ground at height `ground`: two POLY_FT4 quads
   (semi-transparent) of half-width size - (ground - pos->y) / 20, turned by ang (x lo, z hi) */
void Shadow_Draw(Pos_1F604 *pos, s32 ground, s32 size, s32 ang) {
    Scr_1F604 *s = (Scr_1F604 *)0x1F800280;
    PolyFT4_1F604 *p;
    s32 d;
    s32 z;

    if (ground < pos->y) {
        return;
    }
    d = ground - pos->y;
    if (d != 0) {
        size -= d / 20;
    }
    if (size <= 0) {
        return;
    }
    s->a.vz = 0x1000;
    s->b.vx = -((ang << 16) >> 16);
    s->b.vy = 0x200;
    s->a.vx = 0;
    s->a.vy = 0;
    s->b.vz = -(ang >> 16);
    Matrix_LookAt(&s->a, &s->b, &s->m, 0);
    s->m.t[0] = pos->x;
    s->m.t[1] = ground;
    s->m.t[2] = pos->z;
    CompMatrix(D_800E78C0, &s->m, &s->m);
    SetRotMatrix(&s->m);
    SetTransMatrix(&s->m);
    s->c.vx = 0;
    s->c.vy = 0;
    s->c.vz = 0;
    gte_ldv2(s->c);
    s->a.vx = -size;
    s->a.vy = 0;
    s->a.vz = size;
    s->b.vx = size;
    s->b.vy = 0;
    s->b.vz = size;
    gte_ldv01(s->a, s->b);
    s->d.vx = size;
    s->d.vy = 0;
    s->d.vz = -size;
    gte_rtpt_();
    p = (PolyFT4_1F604 *)G_DRAW.prim;
    s->e.vx = -size;
    s->e.vy = 0;
    s->e.vz = -size;
    gte_stSZ3_(z);
    z >>= 2;
    if ((u32)(z - 1) >= 0x800) {
        return;
    }
    gte_stsxy0_(p->xy0);
    gte_stsxy1_(p->xy1);
    gte_stsxy2_(p->xy2);
    gte_stsxy0_(p[1].xy0);
    gte_stsxy2_(p[1].xy1);
    gte_ldv01(s->d, s->e);
    ((u8 *)p)[3] = 9;
    p->code = 0x2F;
    gte_rtpt_();
    p->uv0 = 0x40E0;
    p->uv1 = 0x40FF;
    p->uv2 = 0x4FEF;
    p->uv3 = 0x5FFF;
    p->clut = 0x3D3F;
    p->tpage = 0x4F;
    gte_stsxy0_(p->xy3);
    ADD_PRIM_A0V1(&G_DRAW.ot[z], p);
    p++;
    gte_stsxy0_(p->xy3);
    gte_stsxy1_(p->xy2);
    ((u8 *)p)[3] = 9;
    p->code = 0x2F;
    p->uv0 = 0x40E0;
    p->uv1 = 0x4FEF;
    p->uv2 = 0x5FE0;
    p->uv3 = 0x5FFF;
    p->clut = 0x3D3F;
    p->tpage = 0x4F;
    ADD_PRIM_A0V1(&G_DRAW.ot[z], p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

void func_8001F884(void) {
    s32 *var_v0;
    s32 var_v1;

    D_800B8AB0 = 0;
    var_v1 = 0xB;
    var_v0 = (void *)((u8 *)&D_800B8AB0 + 0xDC);
    do {
        M2C_FIELD(var_v0, s32 *, 0x14) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 - (0x14));
    } while (var_v1 >= 0);
}

typedef struct { SVECTOR a; SVECTOR b; s32 alpha; } TrailSeg_8001F8B0;
typedef struct { s32 head; TrailSeg_8001F8B0 seg[12]; } Trail_8001F8B0;
typedef struct { u8 pad0[0x34]; SVECTOR a; SVECTOR b; } GadgetLine_8001F8B0;
extern GadgetLine_8001F8B0 g_GadgetState_8001F8B0 asm("g_GadgetState");
#define TRAIL (*(Trail_8001F8B0 *)&D_800B8AB0)

/* Push the gadget's current line (the two points at g_GadgetState+0x34/+0x3C) into the
   12-entry swing trail ring at full intensity. */
void GadgetTrail_Push(void) {
    s32 n = (TRAIL.head + 1) % 12;
    TRAIL.seg[n].a = g_GadgetState_8001F8B0.a;
    TRAIL.seg[n].b = g_GadgetState_8001F8B0.b;
    TRAIL.seg[n].alpha = 0xFF;
    TRAIL.head = n;
}

extern u8 *D_800EC354;
typedef struct { u32 tag; u32 tpage; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4Tp_1F954;
#define gte_ldv3m(a, b, c) __asm__ volatile ("lwc2 $0, %0; lwc2 $1, %1; lwc2 $2, %2; lwc2 $3, %3; lwc2 $4, %4; lwc2 $5, %5" : : "m"(*(u32 *)&(a)), "m"(*((u32 *)&(a) + 1)), "m"(*(u32 *)&(b)), "m"(*((u32 *)&(b) + 1)), "m"(*(u32 *)&(c)), "m"(*((u32 *)&(c) + 1)))
#define gte_ldv0m(a) __asm__ volatile ("lwc2 $0, %0; lwc2 $1, %1" : : "m"(*(u32 *)&(a)), "m"(*((u32 *)&(a) + 1)))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_rtps_n() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy3m(a, b, c) __asm__ volatile ("swc2 $12, %0; swc2 $13, %1; swc2 $14, %2" : "=m"(a), "=m"(b), "=m"(c))
#define gte_stsxy2m(a) __asm__ volatile ("swc2 $14, %0" : "=m"(a))

void Weapon_DrawSwingTrail(void) {
    s32 cur;
    TrailSeg_8001F8B0 *e = &TRAIL.seg[TRAIL.head];
    TrailSeg_8001F8B0 *n;
    PolyG4Tp_1F954 *p;
    u32 *ot;
    s32 l;

    cur = TRAIL.head;
    if (e->alpha <= 0) {
        return;
    }
    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    p = (PolyG4Tp_1F954 *)G_DRAW.prim;
    ot = G_DRAW.ot;
    while (e->alpha > 0) {
        n = &TRAIL.seg[(cur + 11) % 12];
        if (n->alpha <= 0) {
            if (e->alpha < 0x40) {
                e->alpha = 0;
            }
            break;
        }
        gte_ldv3m(e->a, e->b, n->a);
        gte_rtpt_n();
        l = e->alpha;
        p->c0 = l << 16;
        p->c1 = (l > 16) ? (l - 16) << 16 : 0;
        p->c2 = (l > 32) ? (l - 32) << 16 : 0;
        p->c3 = (l > 48) ? (l - 48) << 16 : 0;
        gte_stsxy3m(p->xy0, p->xy1, p->xy2);
        gte_ldv0m(n->b);
        gte_rtps_n();
        ((u8 *)p)[3] = 9;
        p->tpage = 0xE1000220;
        ((u8 *)p)[11] = 0x3A;
        ADD_PRIM_ASM2(ot, p);
        gte_stsxy2m(p->xy3);
        p++;
        e->alpha -= 0x20;
        if (e->alpha <= 0) {
            e->alpha = 0;
        }
        cur = (cur + 11) % 12;
        e = &TRAIL.seg[cur];
    }
    D_800EC354 = (u8 *)p;
}

extern struct { s32 frame; } g_Game_1FB98 asm("g_Game");
typedef struct { u8 pad0[4]; u16 mat; } GadgetHdr_1FB98;
typedef struct { GadgetHdr_1FB98 *hdr; u8 pad4[8]; SVECTOR *verts; } GadgetMdl_1FB98;
extern GadgetMdl_1FB98 D_800EC060_1FB98[] asm("D_800EC060");
extern struct { u8 pad0[0xF2]; s8 gadget; } g_Spike_1FB98 asm("g_Spike");
typedef struct { u8 b[0x20]; } Mat_1FB98;
extern Mat_1FB98 D_800F4730_1FB98[] asm("D_800F4730");
extern SVECTOR D_800B8C68[6];
extern s16 D_800AE8E0[6];
extern SVECTOR D_800B8BA8[2][12];
extern s16 D_800AE8B0[12][2];
extern struct { u32 sxy; s32 sz; } D_800E7D00_1FB98[] asm("D_800E7D00");
void RotTransSV(SVECTOR *a, SVECTOR *b, s32 *flag);
#define gte_stsz(p) __asm__ volatile ("swc2 $19, 0(%0)" : : "r"(p) : "memory")

/* No caller found (no jal or pointer to it in the files searched, but the same holds for the dust code
   Spike_UpdateFootEffects, so the caller may be in packed data). Perhaps the RC car
   remote's antenna (user: a stiff antenna with 6 lines shooting out of the tip and a line of lightning
   bolts to the car), and this may compute those 6 lines. Soft strands of the gadget in hand: 6 anchor vertices of its model (D_800AE8E0) are transformed
   and averaged with last frame's (double-buffered D_800B8BA8 by frame parity), 6 tips follow them
   the same way and are pulled towards their mean, then all 12 are projected into the model's
   screen vertex buffer (D_800E7D00 slots D_800AE8B0). */
void Gadget_UpdateSoftStrands(void) {
    s32 i;
    s32 cur = g_Game_1FB98.frame & 1;
    s32 prev;
    s32 flag;
    SVECTOR avg;

    SetRotMatrix(&D_800F4730_1FB98[D_800EC060_1FB98[g_Spike_1FB98.gadget].hdr->mat]);
    prev = cur ^ 1;
    SetTransMatrix(&D_800F4730_1FB98[D_800EC060_1FB98[g_Spike_1FB98.gadget].hdr->mat]);
    for (i = 0; i < 6; i++) {
        RotTransSV(&D_800EC060_1FB98[g_Spike_1FB98.gadget].verts[D_800AE8E0[i]], &D_800B8C68[i], &flag);
    }
    for (i = 0; i < 6; i++) {
        D_800B8BA8[cur][i].vx = (D_800B8BA8[prev][i].vx + D_800B8C68[i].vx) / 2;
        D_800B8BA8[cur][i].vy = (D_800B8BA8[prev][i].vy + D_800B8C68[i].vy + 0x50) / 2;
        D_800B8BA8[cur][i].vz = (D_800B8BA8[prev][i].vz + D_800B8C68[i].vz) / 2;
    }
    for (i = 0; i < 6; i++) {
        D_800B8BA8[cur][i + 6].vx = (D_800B8BA8[prev][i + 6].vx + D_800B8BA8[cur][i].vx) / 2;
        D_800B8BA8[cur][i + 6].vy = (D_800B8BA8[prev][i + 6].vy + D_800B8BA8[cur][i].vy + 0x40) / 2;
        D_800B8BA8[cur][i + 6].vz = (D_800B8BA8[prev][i + 6].vz + D_800B8BA8[cur][i].vz) / 2;
    }
    avg.vx = (D_800B8BA8[cur][6].vx + D_800B8BA8[cur][7].vx + D_800B8BA8[cur][8].vx + D_800B8BA8[cur][9].vx + D_800B8BA8[cur][10].vx + D_800B8BA8[cur][11].vx) / 6;
    avg.vy = (D_800B8BA8[cur][6].vy + D_800B8BA8[cur][7].vy + D_800B8BA8[cur][8].vy + D_800B8BA8[cur][9].vy + D_800B8BA8[cur][10].vy + D_800B8BA8[cur][11].vy) / 6;
    avg.vz = (D_800B8BA8[cur][6].vz + D_800B8BA8[cur][7].vz + D_800B8BA8[cur][8].vz + D_800B8BA8[cur][9].vz + D_800B8BA8[cur][10].vz + D_800B8BA8[cur][11].vz) / 6;
    for (i = 6; i < 12; i++) {
        D_800B8BA8[cur][i].vx = (D_800B8BA8[cur][i].vx * 2 + avg.vx) / 3;
        D_800B8BA8[cur][i].vy = (D_800B8BA8[cur][i].vy * 2 + avg.vy) / 3;
        D_800B8BA8[cur][i].vz = (D_800B8BA8[cur][i].vz * 2 + avg.vz) / 3;
    }
    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    for (i = 0; i < 12; i++) {
        gte_ldv0(&D_800B8BA8[cur][i]);
        gte_rtps();
        gte_stsxy(&D_800E7D00_1FB98[D_800AE8B0[i][0]].sxy);
        gte_stsz(&D_800E7D00_1FB98[D_800AE8B0[i][0]].sz);
    }
}

extern struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0xE]; s16 f_74; u8 pad76[2]; s16 f_78; } g_Spike;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0, x1, y1; } LineF2_20010;

/* Debug lines from Spike: a red LINE_F2 along (f_74, f_78) >> 3 and a yellow one along (f_60, f_64) >> 3
   from his position, projected with the camera matrix. Needs the do { } while (0) on one load. */
void Debug_DrawSpikeVectors(void) {
    LineF2_20010 *p = (LineF2_20010 *)G_DRAW.prim;
    SVECTOR v;

    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    ((u8 *)p)[3] = 3;
    p->code = 0x40;
    p->r0 = 0xFF;
    p->g0 = 0;
    p->b0 = 0;
    v.vx = g_Spike.x;
    v.vy = g_Spike.y;
    v.vz = g_Spike.z;
    gte_ldv0(&v);
    gte_rtps();
    gte_stsxy(&p->x0);
    v.vx += g_Spike.f_74 >> 3;
    v.vz += g_Spike.f_78 >> 3;
    do { gte_ldv0(&v); } while (0);
    gte_rtps();
    gte_stsxy(&p->x1);
    ADD_PRIM_A0V1(G_DRAW.db[G_DRAW.cur].ot, p);
    p++;
    ((u8 *)p)[3] = 3;
    p->code = 0x40;
    p->r0 = 0xFF;
    p->g0 = 0xFF;
    p->b0 = 0;
    v.vx = g_Spike.x;
    v.vy = g_Spike.y;
    v.vz = g_Spike.z;
    gte_ldv0(&v);
    gte_rtps();
    gte_stsxy(&p->x0);
    v.vx += g_Spike.f_60 >> 3;
    v.vz += g_Spike.f_64 >> 3;
    gte_ldv0(&v);
    gte_rtps();
    gte_stsxy(&p->x1);
    ADD_PRIM_A0V1(G_DRAW.db[G_DRAW.cur].ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

typedef struct { s16 x, y, z; } ScrPt_2020C;
typedef struct { u32 tag; u32 tpage; u32 c0; u32 xy0; u32 c1; s16 x1, y1; u32 c2; s16 x2, y2; u32 c3; s16 x3, y3; } PolyG4Tp_2020C;

/* Glowing beam between the projected points a and b ({x, y, otz}): two gouraud quads fading from
   `color` on the a-b line to black at the sides, and two fading caps at each end, additive, in the
   world OT at the nearer depth / 4 (- 20 past 20). Its half-width is `width` scaled by the GTE
   projection distance over each end's depth (at least 0xA4). */
void Fx_DrawGlowBeam(ScrPt_2020C *a, ScrPt_2020C *b, s32 width, u32 color) {
    PolyG4Tp_2020C *p = (PolyG4Tp_2020C *)G_DRAW.prim;
    u32 *ot;
    SVECTOR d;
    s32 za, zb, z, h;
    s32 ax, ay, bx, by;

    d.vx = b->x - a->x;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    d.vy = b->y - a->y;
    d.vz = 0;
    VectorNormalSS(&d, &d);
    za = a->z;
    zb = b->z;
    if (zb < za) {
        z = zb >> 2;
    } else {
        z = za >> 2;
    }
    if (z > 20) {
        z -= 20;
    }
    if ((u32)(z - 1) >= 0x800) {
        return;
    }
    ot += z;
    __asm__ volatile("cfc2 %0, $26" : "=r"(h));
    if (za < 0xA4) {
        za = 0xA4;
    }
    if (zb < 0xA4) {
        zb = 0xA4;
    }
    ax = width * d.vx * h * 3 / za;
    ay = width * d.vy * h * 3 / za;
    by = width * d.vy * h / zb;
    bx = width * d.vx * h / zb;

    p->c1 = 0;
    p->c3 = 0;
    p->c0 = color;
    p->c2 = color;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    p->xy0 = *(u32 *)a;
    *(u32 *)&p->x2 = *(u32 *)b;
    p->x1 = a->x - (ay >> 14);
    p->y1 = a->y + (ax >> 14);
    p->x3 = b->x - (by >> 12);
    p->y3 = b->y + (bx >> 12);
    ADD_PRIM_ASM(ot, p);
    p++;
    p->c1 = 0;
    p->c3 = 0;
    p->c0 = color;
    p->c2 = color;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    p->xy0 = *(u32 *)a;
    *(u32 *)&p->x2 = *(u32 *)b;
    p->x1 = a->x + (ay >> 14);
    p->y1 = a->y - (ax >> 14);
    p->x3 = b->x + (by >> 12);
    p->y3 = b->y - (bx >> 12);
    ADD_PRIM_ASM(ot, p);
    p++;
    p->c1 = 0;
    p->c3 = 0;
    p->c0 = 0;
    p->c2 = color;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    *(u32 *)&p->x2 = *(u32 *)a;
    ((s16 *)&p->xy0)[0] = a->x - (ax >> 15);
    ((s16 *)&p->xy0)[1] = a->y - (ay >> 15);
    p->x1 = ((s16 *)&p->xy0)[0] - (ay >> 15);
    p->y1 = ((s16 *)&p->xy0)[1] + (ax >> 15);
    p->x3 = a->x - (ay >> 14);
    p->y3 = a->y + (ax >> 14);
    ADD_PRIM_ASM(ot, p);
    p++;
    p->c1 = 0;
    p->c3 = 0;
    p->c0 = 0;
    p->c2 = color;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    *(u32 *)&p->x2 = *(u32 *)a;
    ((s16 *)&p->xy0)[0] = a->x - (ax >> 15);
    ((s16 *)&p->xy0)[1] = a->y - (ay >> 15);
    p->x1 = ((s16 *)&p->xy0)[0] + (ay >> 15);
    p->y1 = ((s16 *)&p->xy0)[1] - (ax >> 15);
    p->x3 = a->x + (ay >> 14);
    p->y3 = a->y - (ax >> 14);
    ADD_PRIM_ASM(ot, p);
    p++;
    p->c1 = color;
    p->c3 = 0;
    p->c0 = 0;
    p->c2 = 0;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    *(u32 *)&p->x1 = *(u32 *)b;
    ((s16 *)&p->xy0)[0] = b->x + (by >> 12);
    ((s16 *)&p->xy0)[1] = b->y - (bx >> 12);
    p->x3 = b->x + (bx >> 13);
    p->y3 = b->y + (by >> 13);
    p->x2 = p->x3 + (by >> 13);
    p->y2 = p->y3 - (bx >> 13);
    ADD_PRIM_ASM(ot, p);
    p++;
    p->c1 = color;
    p->c3 = 0;
    p->c0 = 0;
    p->c2 = 0;
    ((u8 *)p)[3] = 9;
    p->tpage = 0xE1000220;
    ((u8 *)p)[11] = 0x3A;
    *(u32 *)&p->x1 = *(u32 *)b;
    ((s16 *)&p->xy0)[0] = b->x - (by >> 12);
    ((s16 *)&p->xy0)[1] = b->y + (bx >> 12);
    p->x3 = b->x + (bx >> 13);
    p->y3 = b->y + (by >> 13);
    p->x2 = p->x3 - (by >> 13);
    p->y2 = p->y3 + (bx >> 13);
    ADD_PRIM_ASM(ot, p);
    p++;
    D_800EC354 = (u8 *)p;
}

INCLUDE_ASM("asm/nonmatchings/game/8001F3A0", Model_DrawOnScreen);

void func_80020A20(S_20A20_80020A20 **a, s16 b, s16 c, u8 d, s32 e) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 i;
    for (i = 0; i < (*a)->f_8; i++) {
        ((s32 *)scratch)[i] = e;
    }
    *(s16 *)(scratch + 0x3C6) = b;
    *(s16 *)(scratch + 0x3C4) = c;
    *(u8 *)(scratch + 0x3F4) = d;
    *(s16 *)(scratch + 0x3C0) = D_800EBFA0.f_24;
    *(s16 *)(scratch + 0x3C2) = D_800EBFA0.f_28;
}

void Gfx_InitProjection(void) {
    gte_SetGeomScreen(0x148);
    gte_SetZSF4(0x100);
    gte_SetZSF3(0x155);
}

/* the next object (PsyQ library) is only 4-byte aligned: keep this file's 16-byte padding */
__asm__(".section .text\n\t.align 4\n");
