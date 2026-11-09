#include "common.h"
#include "m2c_macros.h"

s32 Floor_GetHeight(s32, s32, s32);

extern struct S_D_800B4D30 { s32 f_0; void * f_4; } D_800B4D30;
extern struct S_D_800EBFA0 { u16 w; u16 h; u8 pad4[4]; u32 *cells; } D_800EBFA0;
void *Mem_Alloc(s32 size);

void Zone_SetTable(s32 *arg0)
{
  void *new_var;
  s32 new_var2;
  new_var = (void *) 0;
  if (arg0 == new_var)
  {
    D_800B4D30.f_0 = 0;
    return;
  }
  new_var = arg0;
  new_var2 = (s32) (*arg0);
  D_800B4D30.f_4 = (void *) (new_var + 4);
  D_800B4D30.f_0 = new_var2;
}

s16 func_800433B0(s32 a0, s32 a1, s32 a2, s16 *out)
{
  u8 *scratch = (u8 *) 0x1F8003F0;
  s32 r = Floor_GetHeight(a0, a1, a2);
  char new_var;
  out[new_var = 1] = *((s16 *) (scratch + 0xE));
  out[0] = *((s16 *) (scratch + 0xC));
  return r;
}

typedef struct { s16 f_0, f_2, f_4, f_6; u16 f_8; s16 f_A, f_C, f_E; } Hit_FGH;
extern struct { u16 w; u16 h; u8 pad4[4]; u32 *cells; u8 padC[8]; s16 *heights; } D_800EBFA0_FGH asm("D_800EBFA0");
extern struct { u8 pad0[0x8194]; u32 *f_8194; } g_Game_FGH asm("g_Game");
s32 func_8004D8C0(s32, s32, s32);

s32 Floor_GetHeight(s32 x, s32 y, s32 z) {
    Hit_FGH *hit = (Hit_FGH *)0x1F8003F0;
    s16 slope[2];
    s32 h[5];
    s16 res;
    s32 ax;
    s16 cx, cz;
    s32 fx, fz;
    u32 cell;
    u32 type;
    s32 idx;
    s16 d;
    s32 t;
    s16 obj;
    u16 w;
    u16 hh;
    s32 lx, lz, j;
    s16 *hp;

    hit->f_0 = -1;
    hit->f_2 = 0;
    hit->f_4 = 0;
    hit->f_6 = 0;
    hit->f_A = 0;
    hit->f_8 = 0;
    hit->f_E = 0;
    hit->f_C = 0;
    res = 0x4000;
    if (!(*g_Game_FGH.f_8194 & 2)) {
        w = D_800EBFA0_FGH.w;
        hh = D_800EBFA0_FGH.h;
        ax = x + (w << 8);
        cz = (z + (hh << 8)) >> 9;
        cx = ax >> 9;
        if (cx >= w || cz >= hh || cx < 0 || cz < 0) {
            return 0;
        }
        cell = D_800EBFA0_FGH.cells[cz * w + cx];
        lx = ax & 0x1FF;
        lz = (z + (D_800EBFA0_FGH.h << 8)) & 0x1FF;
        type = ((lx < lz) << 1) | (0x200 - lx < lz);
        fx = ax & 0x1FF;
        fz = (z + (D_800EBFA0_FGH.h << 8)) & 0x1FF;
        hit->f_8 = cell >> 16;
        if ((cell >> 11) & 1) {
            u32 tt = type | 0x80; type = tt | ((cell >> 8) & 0x70);
        }
        idx = (w + 1) * cz + cx;
        *(volatile s32 *)&h[0] = D_800EBFA0_FGH.heights[idx];
        h[1] = D_800EBFA0_FGH.heights[idx + 1];
        idx += w + 1;
        h[2] = D_800EBFA0_FGH.heights[idx];
        h[3] = D_800EBFA0_FGH.heights[idx + 1];
        h[4] = D_800EBFA0_FGH.heights[(w + 1) * (*(volatile u16 *)&D_800EBFA0_FGH.h + 1) + cz * w + cx];
        switch (type) {
        case 0:
        case 0x90:
        case 0xA0:
            slope[0] = h[1] - h[0];
            slope[1] = (h[4] - slope[0] / 2 - h[0]) * 2;
            res = h[0] + fx * slope[0] / 512 + fz * slope[1] / 512;
            break;
        case 1:
        case 0xA1:
        case 0xB1:
            slope[1] = h[3] - h[1];
            slope[0] = (h[1] + slope[1] / 2 - h[4]) * 2;
            res = h[1] + -slope[0] * (0x200 - fx) / 512 + fz * slope[1] / 512;
            break;
        case 2:
        case 0x92:
        case 0xC2:
            slope[1] = h[2] - h[0];
            slope[0] = (h[4] - h[0] - slope[1] / 2) * 2;
            res = h[0] + fx * slope[0] / 512 + fz * slope[1] / 512;
            break;
        case 3:
        case 0xB3:
        case 0xC3:
            slope[0] = h[3] - h[2];
            slope[1] = (h[2] + slope[0] / 2 - h[4]) * 2;
            res = h[2] + fx * slope[0] / 512 + -slope[1] * (0x200 - fz) / 512;
            break;
        default:
            res = 0x4000;
            slope[0] = 0;
            slope[1] = 0;
            break;
        }
    }
    if (y < (s16)res) {
        obj = func_8004D8C0(x, y, z);
    } else {
        obj = func_8004D8C0(x, (s16)res, z);
    }
    if (obj > (s16)res) {
        hit->f_C = slope[0];
        hit->f_E = slope[1];
        if (y < (s16)res) {
            hit->f_8 &= 0xFFE0;
        }
        return (s16)res;
    }
    if (y < obj) {
        hit->f_8 &= 0xFFE0;
    }
    return obj;
}

/* Builds a half-resolution byte map of the cell grid D_800EBFA0 (w x h cells of u32 flags):
 * each output byte covers a 2x2 block of cells and is 0xFF when none of the four has bit 0
 * set, else 0. The map is allocated with Mem_Alloc and returned. */
u8 *Grid_BuildHalfResMap(void) {
    u8 *out = Mem_Alloc((D_800EBFA0.w >> 1) * (D_800EBFA0.h >> 1));
    s32 y, x;
    for (y = 0; y < D_800EBFA0.h >> 1; y++) {
        for (x = 0; x < D_800EBFA0.w >> 1; x++) {
            s32 w = D_800EBFA0.w;
            s32 w2 = w * 2;
            if (!(D_800EBFA0.cells[x * 2 + y * w2] & 1) && !(D_800EBFA0.cells[x * 2 + y * w2 + 1] & 1) &&
                !(D_800EBFA0.cells[x * 2 + (y * 2 + 1) * w] & 1) && !(D_800EBFA0.cells[x * 2 + (y * 2 + 1) * w + 1] & 1)) {
                out[y * D_800EBFA0.w / 2 + x] = 0xFF;
            } else {
                out[y * D_800EBFA0.w / 2 + x] = 0;
            }
        }
    }
    return out;
}

INCLUDE_ASM("asm/nonmatchings/game/80043380_zone", Floor_DrawGrid);

typedef struct { s16 x, y; s16 z, zpad; } V_80044EF4;
typedef struct { V_80044EF4 v[4]; u32 col[4]; u32 uvA; u32 uvB; u32 uvC; u8 code; u8 pad[3]; } Sub_80044EF4;
typedef struct { u32 color[0x80]; V_80044EF4 v[4]; u8 pad220[0x78]; u16 uv[4]; u8 pad2A0[8]; s32 nc0; s32 nc1; s32 otz; u8 idx[4]; u16 clut; u16 tpage; u16 code; u16 tpage2; u16 zb; u16 pad2C2; u32 *ot; u8 pad2C8[0x14]; s32 fog; u8 pad2E0[0x5C]; Sub_80044EF4 sub; u8 pad37C[0x78]; u8 f3F4; } Scr_80044EF4;
extern u8 *D_800EC354_80044EF4 asm("D_800EC354");
u8 *Model_SubdivideGT4(u32 *ot, u8 *prim, Sub_80044EF4 *s, s32 n);
#define W_4EF4(p, o) (*(u32 *)((p) + (o)))
#define H_4EF4(p, o) (*(u16 *)((p) + (o)))
#define SXY_4EF4(i) (*(u32 *)&S->v[i].x)
#define ZW_4EF4(i) (*(s32 *)&S->v[i].z)
#define LWL_4EF4(t, a) __asm__ volatile("lwl %0, 2(%1)" : "=r"(t) : "r"(a))
#define SWL_4EF4(v, a) __asm__ volatile("swl %0, 2(%1)" : : "r"(v), "r"(a))
#define COL_4EF4(i) (*(u32 *)(((u32)S->idx[i] << 2) + (s32)S))
#define MAX_4EF4(a, b) ((a) > (b) ? (a) : (b))
#define HALFT_4EF4(b) ({ u32 _c; __asm__("" : "=r"(_c) : "0"(b)); (_c & 0xFEFEFEFE) >> 1; })
#define HALFV_4EF4(b) ({ u32 _c; __asm__ volatile("" : "=r"(_c) : "0"(b)); __asm__("" :: "r"(b)); (_c & 0xFEFEFEFE) >> 1; })
#define AVGT_4EF4(a, b) ({ u32 _c; __asm__("" : "=r"(_c) : "0"(b)); (((a) & 0xFEFEFEFE) >> 1) + ((_c & 0xFEFEFEFE) >> 1); })

void Floor_DrawQuad(s32 mask) {
    register Scr_80044EF4 *S asm("$14") = (Scr_80044EF4 *)0x1F800000;
    s32 otz;
    s32 a, sw;
    __asm__("" : "=r"(S) : "0"(S));
    a = (S->nc0 >> 31) & 2;
    __asm__ volatile("");
    { register s32 sel asm("$3") = a;
    if (S->nc1 > 0) { s32 t = a | 1; __asm__("" : "+r"(t)); sw = t & mask; } else { __asm__("" : "+r"(sel)); sw = sel & mask; }
    }
    switch (sw) {
    case 0: {
        register u8 *p asm("$7") = D_800EC354_80044EF4;
        if (mask == 0 || *(volatile s32 *)&S->nc0 - *(volatile s32 *)&S->nc1 < 5000) {
            s32 s0, s1, s2, s3, zb, t;
            __asm__ volatile("lwc2 $16, %0; lwc2 $17, %1; lwc2 $18, %2; lwc2 $19, %3" : : "m"(ZW_4EF4(0)), "m"(ZW_4EF4(1)), "m"(ZW_4EF4(2)), "m"(ZW_4EF4(3)));
            __asm__ volatile("nop; nop; avsz4");
            __asm__ volatile("swc2 $7, %0" : "=m"(S->otz));
            zb = S->zb << 2;
            __asm__ volatile("mfc2 %0, $16; mfc2 %1, $17; mfc2 %2, $18; mfc2 %3, $19" : "=r"(s0), "=r"(s1), "=r"(s2), "=r"(s3));
            s0 = (s0 - zb) << 2;
            s1 = (s1 - zb) << 2;
            s2 = (s2 - zb) << 2;
            s3 = (s3 - zb) << 2;
            if (s0 < 0) s0 = 0;
            __asm__ volatile("mtc2 %0, $16" : : "r"(s0));
            if (s1 < 0) s1 = 0;
            __asm__ volatile("mtc2 %0, $17" : : "r"(s1));
            if (s2 < 0) s2 = 0;
            __asm__ volatile("mtc2 %0, $18" : : "r"(s2));
            if (s3 < 0) s3 = 0;
            __asm__ volatile("mtc2 %0, $19" : : "r"(s3));
            if (!((s0 != 0 || s1 != 0 || s2 != 0 || s3 != 0) && (s0 < 0x1001 || s1 < 0x1001 || s2 < 0x1001 || s3 < 0x1001))) {
                S->fog = 0;
            } else {
                S->fog = 1;
            }
            { s32 z = S->zb; s32 o = S->otz;
            if (z < o && S->fog == 0) return;
            t = o < 0 ? 0 : (o > 0xFBF ? 0xFBF : o); S->otz = t; }
            if (S->fog) {
                register u8 *q asm("$5");
                S->code = 0x3E;
                S->tpage2 = (S->tpage & 0xFF9F) | 0x20;
                { s32 m = -1; __asm__ volatile("mtc2 %0, $6; nop" : : "r"(m)); }
                {
                __asm__ volatile("mfc2 %0, $16; nop" : "=r"(t));
                __asm__ volatile("mtc2 %0, $8" : : "r"(t));
                t = SXY_4EF4(0);
                __asm__ volatile("nop; nop; dpcs");
                W_4EF4(p, 0xC) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x8)));
                }
                {
                __asm__ volatile("mfc2 %0, $17; nop" : "=r"(t));
                __asm__ volatile("mtc2 %0, $8" : : "r"(t));
                t = SXY_4EF4(1);
                __asm__ volatile("nop; nop; dpcs");
                p[3] = 9;
                W_4EF4(p, 4) = 0xE1000240;
                p[0xB] = 0x3A;
                W_4EF4(p, 0x14) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x10)));
                }
                {
                __asm__ volatile("mfc2 %0, $18; nop" : "=r"(t));
                __asm__ volatile("mtc2 %0, $8" : : "r"(t));
                t = SXY_4EF4(2);
                __asm__ volatile("nop; nop; dpcs");
                W_4EF4(p, 0x1C) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x18)));
                }
                {
                __asm__ volatile("mfc2 %0, $19; nop" : "=r"(t));
                __asm__ volatile("mtc2 %0, $8" : : "r"(t));
                t = SXY_4EF4(3);
                __asm__ volatile("nop; nop; dpcs");
                W_4EF4(p, 0x24) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x20)));
                }
                { u32 *slot;
                slot = &S->ot[S->otz];
                LWL_4EF4(t, slot);
                q = p + 0x28;
                __asm__("" : "=r"(q) : "0"(q));
                SWL_4EF4((u32)q << 8, slot);
                t = ((u32)t >> 8) | 0x0C000000; W_4EF4(p, 0x28) = t;
                }
                { u32 *slot;
                slot = &S->ot[S->otz];
                LWL_4EF4(t, slot);
                SWL_4EF4((u32)p << 8, slot);
                SWL_4EF4(t, p);
                }
                p = q;
            } else {
                S->code = 0x3C;
                S->tpage2 = S->tpage;
                { u32 *slot;
                slot = &S->ot[S->otz];
                LWL_4EF4(t, slot);
                SWL_4EF4((u32)p << 8, slot);
                t = ((u32)t >> 8) | 0x0C000000; W_4EF4(p, 0) = t;
                }
            }
            { u32 a = SXY_4EF4(0), b = SXY_4EF4(1), c = SXY_4EF4(2), d = SXY_4EF4(3);
            W_4EF4(p, 0x8) = a;
            W_4EF4(p, 0x14) = b;
            W_4EF4(p, 0x20) = c;
            W_4EF4(p, 0x2C) = d; }
            if (S->fog) {
                u32 ix = S->idx[0];
                { s32 t;
                __asm__ volatile("mfc2 %0, $16" : "=r"(t));
                __asm__ volatile("lwc2 $6, %0; nop" : : "m"(*(u32 *)((ix << 2) + (s32)S)));
                __asm__ volatile("mtc2 %0, $8; nop; nop; dpcs" : : "r"(t));
                ix = S->idx[1];
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x4)));
                }
                { s32 t;
                __asm__ volatile("mfc2 %0, $17" : "=r"(t));
                __asm__ volatile("lwc2 $6, %0; nop" : : "m"(*(u32 *)((ix << 2) + (s32)S)));
                __asm__ volatile("mtc2 %0, $8; nop; nop; dpcs" : : "r"(t));
                ix = S->idx[2];
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x10)));
                }
                { s32 t;
                __asm__ volatile("mfc2 %0, $18" : "=r"(t));
                __asm__ volatile("lwc2 $6, %0; nop" : : "m"(*(u32 *)((ix << 2) + (s32)S)));
                __asm__ volatile("mtc2 %0, $8; nop; nop; dpcs" : : "r"(t));
                ix = S->idx[3];
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x1C)));
                }
                { s32 t;
                __asm__ volatile("mfc2 %0, $19" : "=r"(t));
                __asm__ volatile("lwc2 $6, %0; nop" : : "m"(*(u32 *)((ix << 2) + (s32)S)));
                __asm__ volatile("mtc2 %0, $8; nop; nop; dpcs" : : "r"(t));
                __asm__ volatile("swc2 $22, %0" : "=m"(W_4EF4(p, 0x28)));
                }
            } else {
                { u32 i0 = S->idx[0], i1 = S->idx[1]; u32 a, b;
                a = *(u32 *)((i0 << 2) + (s32)S);
                __asm__ volatile("" :: "i"(&&LA)); LA:
                b = *(u32 *)((i1 << 2) + (s32)S);
                W_4EF4(p, 0x4) = a;
                W_4EF4(p, 0x10) = b; }
                { u32 i0 = S->idx[2], i1 = S->idx[3]; u32 a, b;
                a = *(u32 *)((i0 << 2) + (s32)S);
                __asm__ volatile("" :: "i"(&&LB)); LB:
                b = *(u32 *)((i1 << 2) + (s32)S);
                W_4EF4(p, 0x1C) = a;
                W_4EF4(p, 0x28) = b; }
            }
            W_4EF4(p, 0xC) = S->uv[0] | (S->clut << 16);
            W_4EF4(p, 0x18) = S->uv[1] | (S->tpage2 << 16);
            H_4EF4(p, 0x24) = S->uv[2];
            H_4EF4(p, 0x30) = S->uv[3];
            p[7] = S->code;
            p += 0x34;
            D_800EC354_80044EF4 = p;
        } else {
            Sub_80044EF4 *D = (Sub_80044EF4 *)0x1F80033C;
            s32 m;
            u32 w0, w1, w2, w3, w4, w5, w6, w7;
            u32 c0, c1, c2, c3;
            { s32 za = S->v[0].z, zb = S->v[1].z, zc = S->v[2].z, zd = S->v[3].z;
            __asm__("" : "=r"(zc), "=r"(zb), "=r"(za) : "0"(zc), "1"(zb), "2"(za)); __asm__("" : "=r"(zd) : "0"(zd));
            m = MAX_4EF4(za, zb);
            m = MAX_4EF4(m, zc);
            otz = m > zd ? m >> 2 : zd >> 2; }
            {
            register u8 *pa asm("$5") = p;
            register s32 one asm("$7") = 1;
            register Sub_80044EF4 *DD asm("$6") = D;
            u32 i0 = S->idx[0];
            __asm__("" :: "r"(pa), "r"(one), "r"(DD));
            w0 = SXY_4EF4(0); w1 = ZW_4EF4(0); w2 = SXY_4EF4(1); w3 = ZW_4EF4(1);
            w4 = SXY_4EF4(2); w5 = ZW_4EF4(2); w6 = SXY_4EF4(3); w7 = ZW_4EF4(3);
            *(u32 *)&D->v[0].x = w0; *(s32 *)&D->v[0].z = w1;
            *(u32 *)&D->v[1].x = w2; *(s32 *)&D->v[1].z = w3;
            *(u32 *)&D->v[2].x = w4; *(s32 *)&D->v[2].z = w5;
            *(u32 *)&D->v[3].x = w6; *(s32 *)&D->v[3].z = w7;
            { u32 i1, i2, i3, cl, u0, ua;
//[
i1 = S->idx[1];
c0 = *(u32 *)((i0 << 2) + (s32)S);
i2 = S->idx[2];
c1 = *(u32 *)((i1 << 2) + (s32)S);
cl = S->clut;
c2 = *(u32 *)((i2 << 2) + (s32)S);
i3 = S->idx[3];
c3 = *(u32 *)((i3 << 2) + (s32)S);
u0 = S->uv[0];
D->col[1] = c1;
ua = u0 | (cl << 16);
D->uvA = ua;
D->col[2] = c2;
D->col[0] = c0;
D->col[3] = c3;
//]
            }
            D->uvB = S->uv[1] | (S->tpage << 16);
            D->code = 0x3C;
            S->f3F4 = 1;
            { u32 *ot = &S->ot[otz];
            D->uvC = S->uv[2] | (S->uv[3] << 16);
            D_800EC354_80044EF4 = Model_SubdivideGT4(ot, pa, DD, one); }
            }
        }
        break; }
    case 1: {
        register u8 *p asm("$8") = D_800EC354_80044EF4;
        if (*(volatile s32 *)&S->nc0 < 5000) {
            u32 t;
            s32 m;
            __asm__("" :: "r"(p));
            { s32 za = S->v[0].z, zb = S->v[1].z, zc = S->v[2].z;
            __asm__("" : "=r"(zc), "=r"(zb), "=r"(za) : "0"(zc), "1"(zb), "2"(za));
            m = MAX_4EF4(za, zb);
            m = m > zc ? m >> 2 : zc >> 2; }
            { u32 x0 = SXY_4EF4(0), x1 = SXY_4EF4(1), x2 = SXY_4EF4(2);
            W_4EF4(p, 0x8) = x0; W_4EF4(p, 0x14) = x1; W_4EF4(p, 0x20) = x2; }
            { u32 *slot = &S->ot[m]; LWL_4EF4(t, slot); SWL_4EF4((u32)p << 8, slot); SWL_4EF4(t, p); }
            { u32 x0 = COL_4EF4(0), x1 = COL_4EF4(1), x2 = COL_4EF4(2);
            W_4EF4(p, 0x4) = x0; W_4EF4(p, 0x10) = x1; W_4EF4(p, 0x1C) = x2; }
            W_4EF4(p, 0xC) = S->uv[0] | (S->clut << 16);
            W_4EF4(p, 0x18) = S->uv[1] | (S->tpage << 16);
            { u16 u = S->uv[2];
            p[3] = 9;
            p[7] = 0x34;
            H_4EF4(p, 0x24) = u; }
            p += 0x28;
            D_800EC354_80044EF4 = p;
        } else {
            Sub_80044EF4 *D = (Sub_80044EF4 *)0x1F80033C;
            s32 z0, z1, x0, x1;
            s32 tA, tB, tC, tD;
            { s32 za = S->v[0].z, zb = S->v[1].z, zc = S->v[2].z;
            __asm__("" : "=r"(zc), "=r"(zb), "=r"(za) : "0"(zc), "1"(zb), "2"(za));
            otz = MAX_4EF4(za, zb);
            otz = otz > zc ? otz >> 2 : zc >> 2; }
            { u32 i0, i1, i2, c0, c1, c2, u;
//(
tC = SXY_4EF4(2);
tA = SXY_4EF4(0);
tB = SXY_4EF4(1);
*(u32 *)&D->v[0].x = tA;
tA = ZW_4EF4(0);
*(u32 *)&D->v[2].x = tC;
tC = ZW_4EF4(2);
*(u32 *)&D->v[3].x = tB;
i0 = S->idx[0];
z0 = (s16)*(volatile u16 *)&S->v[0].z;
i1 = S->idx[1];
tB = ZW_4EF4(1);
c0 = *(u32 *)((i0 << 2) + (s32)S);
D->col[0] = c0;
i2 = S->idx[2];
c2 = *(u32 *)((i2 << 2) + (s32)S);
z1 = (s16)*(volatile u16 *)&S->v[1].z;
c1 = *(u32 *)((i1 << 2) + (s32)S);
u = *(volatile u32 *)&D->col[0];
D->col[3] = c1;
*(s32 *)&D->v[0].z = tA;
*(s32 *)&D->v[2].z = tC;
*(s32 *)&D->v[3].z = tB;
D->col[2] = c2;
D->col[1] = ((u & 0xFEFEFEFE) >> 1) + HALFV_4EF4(c1);
//)
            }
            if (z0 < 0xA4) z0 = 0xA4;
            if (z1 < 0xA4) z1 = 0xA4;
            x0 = (s16)*(volatile u16 *)&S->v[0].x; x1 = (s16)*(volatile u16 *)&S->v[1].x; tC = (s16)*(volatile u16 *)&S->v[0].y; tD = (s16)*(volatile u16 *)&S->v[1].y;
            { s32 f = x1 < x0;
            tA = x0 * z0 + x1 * z1;
            tB = tC * z0 + tD * z1;
            if (f) tB += z0 + z1; }
            __asm__("" :: "r"(tA));__asm__("" :: "r"(tB));
            __asm__("" :: "r"(tA));__asm__("" :: "r"(tB));__asm__("" :: "r"(D));__asm__("" :: "r"(tD));
            if (tC < tD) tA += z0 + z1;
            tA /= z0 + z1;
            tB /= z0 + z1;
            D->v[1].z = (z0 + z1) / 2;
            D->code = 0x3C;
            S->f3F4 = 1;
            { u32 *ot = &S->ot[otz];
            D->uvA = (S->clut << 16) | S->uv[0];
            D->uvB = (S->tpage << 16) | (((S->uv[0] & 0xFEFE) >> 1) + ((S->uv[1] & 0xFEFE) >> 1));
            D->uvC = (S->uv[1] << 16) | S->uv[2];
            D->v[1].x = tA;
            D->v[1].y = tB;
            D_800EC354_80044EF4 = Model_SubdivideGT4(ot, p, D, 1); }
        }
        break; }
    case 2: {
        register u8 *p asm("$8") = D_800EC354_80044EF4;
        if (*(volatile s32 *)&S->nc1 < -5000) {
            u32 t;
            s32 m;
            __asm__("" :: "r"(p));
            __asm__ volatile("");__asm__ volatile("");
            { s32 za = S->v[1].z, zb = S->v[2].z, zc = S->v[3].z;
            __asm__("" : "=r"(zc), "=r"(zb), "=r"(za) : "0"(zc), "1"(zb), "2"(za));
            m = MAX_4EF4(za, zb);
            m = m > zc ? m >> 2 : zc >> 2; }
            { u32 x0 = SXY_4EF4(1), x1 = SXY_4EF4(2), x2 = SXY_4EF4(3);
            W_4EF4(p, 0x8) = x0; W_4EF4(p, 0x14) = x1; W_4EF4(p, 0x20) = x2; }
            { u32 *slot = &S->ot[m]; LWL_4EF4(t, slot); SWL_4EF4((u32)p << 8, slot); SWL_4EF4(t, p); }
            { u32 x0 = COL_4EF4(1), x1 = COL_4EF4(2), x2 = COL_4EF4(3);
            W_4EF4(p, 0x4) = x0; W_4EF4(p, 0x10) = x1; W_4EF4(p, 0x1C) = x2; }
            W_4EF4(p, 0xC) = S->uv[1] | (S->clut << 16);
            W_4EF4(p, 0x18) = S->uv[2] | (S->tpage << 16);
            { u16 u = S->uv[3];
            p[3] = 9;
            p[7] = 0x34;
            H_4EF4(p, 0x24) = u; }
            p += 0x28;
            D_800EC354_80044EF4 = p;
        } else {
            Sub_80044EF4 *D = (Sub_80044EF4 *)0x1F80033C;
            s32 z0, x0, x1, z1;
            s32 tA, tB, tC, tD;
            __asm__ volatile("");__asm__ volatile("");
            { s32 za = S->v[1].z, zb = S->v[2].z, zc = S->v[3].z;
            __asm__("" : "=r"(zc), "=r"(zb), "=r"(za) : "0"(zc), "1"(zb), "2"(za));
            otz = MAX_4EF4(za, zb);
            otz = otz > zc ? otz >> 2 : zc >> 2; }
            { u32 i0, i2, i3, c0, c2, u, c1;
//{
tA = SXY_4EF4(1);
tC = SXY_4EF4(2);
tB = SXY_4EF4(3);
*(u32 *)&D->v[0].x = tA;
__asm__ volatile("");
tA = ZW_4EF4(1);
*(u32 *)&D->v[2].x = tC;
tC = ZW_4EF4(2);
*(u32 *)&D->v[3].x = tB;
i0 = S->idx[1];
c0 = *(u32 *)((i0 << 2) + (s32)S);
z0 = (s16)*(volatile u16 *)&S->v[1].z;
i2 = S->idx[2];
tB = ZW_4EF4(3);
D->col[0] = c0;
i3 = S->idx[3];
c2 = *(u32 *)((i2 << 2) + (s32)S);
c1 = *(u32 *)((i3 << 2) + (s32)S);
z1 = (s16)*(volatile u16 *)&S->v[3].z;
D->col[2] = c2;
*(s32 *)&D->v[0].z = tA;
*(s32 *)&D->v[2].z = tC;
u = *(volatile u32 *)&D->col[0];
*(s32 *)&D->v[3].z = tB;
D->col[3] = c1;
D->col[1] = ((u & 0xFEFEFEFE) >> 1) + ((c1 & 0xFEFEFEFE) >> 1);
//}
            }
            if (z0 < 0xA4) z0 = 0xA4;
            __asm__("" :: "r"(tA));
            if (z1 < 0xA4) z1 = 0xA4;
            x0 = (s16)*(volatile u16 *)&S->v[1].x; x1 = (s16)*(volatile u16 *)&S->v[3].x; tC = (s16)*(volatile u16 *)&S->v[1].y; tD = (s16)*(volatile u16 *)&S->v[3].y;
            { s32 f = x1 < x0;
            tA = x0 * z0 + x1 * z1;
            tB = tC * z0 + tD * z1;
            if (f) tB += z0 + z1; }
            __asm__("" :: "r"(tA));__asm__("" :: "r"(tB));__asm__("" :: "r"(tD));
            if (tC < tD) tA += z0 + z1;
            tA /= z0 + z1;
            tB /= z0 + z1;
            D->v[1].z = (z0 + z1) / 2;
            D->code = 0x3C;
            S->f3F4 = 1;
            { u32 *ot = &S->ot[otz];
            D->uvA = (S->clut << 16) | S->uv[1];
            D->uvB = (S->tpage << 16) | (((S->uv[1] & 0xFEFE) >> 1) + ((S->uv[3] & 0xFEFE) >> 1));
            D->uvC = (S->uv[3] << 16) | S->uv[2];
            D->v[1].x = tA;
            D->v[1].y = tB;
            D_800EC354_80044EF4 = Model_SubdivideGT4(ot, p, D, 1); }
        }
        break; }
    }
}

typedef struct { u32 sxy; s16 z; s16 pad; } V_80045BE4;
typedef struct { u32 color[0x80]; V_80045BE4 v[4]; u8 pad220[0x88]; s32 nc0; s32 nc1; s32 otz; u8 idx[4]; } Scr_80045BE4;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80045BE4;
typedef struct { Tag_80045BE4 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } G4_80045BE4;
typedef struct { u8 pad0[4]; G4_80045BE4 *prim; u32 *ot; s32 cur; struct { u8 env[0x70]; Tag_80045BE4 ot[0x1000]; u32 hud[2]; } db[2]; } Draw_80045BE4;
typedef struct { u8 pad0[0x24]; s32 fogScale; s32 fogNear; } Fog_80045BE4;
extern Draw_80045BE4 g_Game_80045BE4 asm("g_Game");
extern Fog_80045BE4 D_800EBFA0_80045BE4 asm("D_800EBFA0");
#define S_5BE4 S
#define MAX_5BE4(a, b) ((a) > (b) ? (a) : (b))

void func_80045BE4(void) {
    s32 t;
    Scr_80045BE4 *S = (Scr_80045BE4 *)0x1F800000;
    __asm__ volatile("mtc2 %0, $12; nop; mtc2 %2, $14; nop; mtc2 %1, $13" : : "r"(S_5BE4->v[0].sxy), "r"(S_5BE4->v[1].sxy), "r"(S_5BE4->v[2].sxy));
    __asm__ volatile("nop; nop; nclip");
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&((Scr_80045BE4 *)0x1F800000)->nc0) : "memory");
    __asm__ volatile("mtc2 %0, $12" : : "r"(S_5BE4->v[3].sxy));
    __asm__ volatile("nop; nop; nclip");
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&((Scr_80045BE4 *)0x1F800000)->nc1) : "memory");
    switch (((S_5BE4->nc0 >> 31) & 2) | (S_5BE4->nc1 > 0)) {
    case 0:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[0].z, S_5BE4->v[1].z);
        S_5BE4->otz = MAX_5BE4(S_5BE4->otz, S_5BE4->v[2].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[3].z ? S_5BE4->otz >> 2 : S_5BE4->v[3].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[0].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[2].sxy;
        g_Game_80045BE4.prim->xy3 = S_5BE4->v[3].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = t;
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[0]]), "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]));
        __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpct" : : "r"(t));
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        __asm__ volatile("lwc2 $6, 0(%0); nop; nop; dpcs" : : "r"(&S_5BE4->color[S_5BE4->idx[3]]));
        __asm__ volatile("swc2 $22, 0(%0)" : : "r"(&g_Game_80045BE4.prim->c3) : "memory");
        g_Game_80045BE4.prim->tag.len = 8;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x38;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x24);
        return;
    case 1:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[0].z, S_5BE4->v[1].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[2].z ? S_5BE4->otz >> 2 : S_5BE4->v[2].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[0].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[2].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = t;
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[0]]), "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]));
        __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpct" : : "r"(t));
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        g_Game_80045BE4.prim->tag.len = 6;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x30;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x1C);
        return;
    case 2:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[1].z, S_5BE4->v[2].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[3].z ? S_5BE4->otz >> 2 : S_5BE4->v[3].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[2].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[3].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]), "r"(&S_5BE4->color[S_5BE4->idx[3]]));
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        { s32 f = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = f;
        __asm__ volatile("mtc2 %0, $8; nop; nop; dpct" : : "r"(f)); }
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        g_Game_80045BE4.prim->tag.len = 6;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x30;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x1C);
        return;
    }
}

/* Zone lookup by position (has an original bug on the y axis).
 */
/* An axis-aligned box: centre, half-extents and the flags it contributes. */
typedef struct { s16 x, y, z, hx, hy, hz; u16 flags; s16 pad; } Zone;

/* OR together the flags of every zone box containing (x, y, z). With no hit, returns
   0xFFFF if `def` is set, else 0x8000. Note the original bug: a negative dy is replaced
   by -dx, not -dy. */
s32 Zone_FindAt(s32 x, s32 y, s32 z, s32 def) {
    s32 i;
    s32 r = 0;
    s32 n = D_800B4D30.f_0;
    Zone *p = D_800B4D30.f_4;
    for (i = 0; i < n; p++, i++) {
        s32 dx = p->x - x;
        s32 dy = p->y - y;
        s32 dz = p->z - z;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dx;
        if (dz < 0) dz = -dz;
        if (dx < p->hx && dy < p->hy && dz < p->hz) {
            r |= p->flags;
        }
    }
    if (r == 0) {
        if (!def) r = 0x8000;
        else r = 0xFFFF;
    }
    return r;
}
