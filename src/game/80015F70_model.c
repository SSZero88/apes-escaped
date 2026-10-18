#include "common.h"
#include "m2c_macros.h"
#include "gte.h"
#define gte_ldFCR(r) __asm__ volatile ("ctc2 %0, $21" : : "r"(r))
#define gte_ldFCG(r) __asm__ volatile ("ctc2 %0, $22" : : "r"(r))
#define gte_ldFCB(r) __asm__ volatile ("ctc2 %0, $23" : : "r"(r))
typedef struct { u8 f_0; u8 f_1; u8 pad2; u8 f_3; u8 pad4[8]; s32 f_C; s32 f_10; u16 f_14; u16 f_16; u8 f_18; u8 f_19; u8 f_1A; u8 f_1B; } S_Chunk_80015F70_80015F70;
typedef struct { u8 pad0[0x16]; u16 f_16; } S_Hdr_80015F70_80015F70;
typedef struct { S_Hdr_80015F70_80015F70 *f_0; s32 *f_4; S_Chunk_80015F70_80015F70 *f_8; } S_Model_80015F70_80015F70;
typedef struct { u8 pad0[4]; s32 f_4; u8 pad8[4]; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; u16 f_20; u8 pad22[2]; u16 f_24; u8 pad26[2]; s32 f_28; u16 f_2C; u8 pad2E[2]; u16 f_30; } S_Out_80015F70_80015F70;
typedef struct { s16 f_0; s16 f_2; s32 f_4; } S_1D4A8_8001D4A8;
typedef struct { u8 pad0[0xC]; u16 f_C; } S_Anim_80016E68;
typedef struct { S_Anim_80016E68 *f_0; u8 pad4[0x14]; u16 f_18; u16 f_1A; } S_16E68_80016E68;

M2C_UNK Model_CalcEnvMapUVs(void **);
typedef struct { u8 pad0[0x8]; u16 f_8; u8 padA[4]; u16 f_E; } S_Hdr_17E5C;
typedef struct { S_Hdr_17E5C *f_0; s32 *f_4; u8 *f_8; } S_Model_17E5C;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } S_Scr_17E5C;
extern struct { u8 pad0[0x1C]; u8 f_1C; u8 f_1D; u8 f_1E; u8 pad1F[5]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;

void func_80017CD4(s32, s32, S_Model_17E5C *);
M2C_UNK func_8001CE54(s32, M2C_UNK, void **);
void Model_DrawPrims(s32, u8 *, s32);
u8 *Model_AddF3(s32, u8 *, s32);
u8 *Model_AddFT3(s32, u8 *, s32);
u8 *Model_AddF4(s32, u8 *, s32);
u8 *Model_AddFT4(s32, u8 *, s32);
u8 *Model_AddG3(s32, u8 *, s32);
u8 *Model_AddGT3(s32, u8 *, s32);
u8 *Model_AddG4(s32, u8 *, s32);
u8 *Model_AddGT4(s32, u8 *, s32);

/* Finds the n-th primitive of the given GPU type (POLY_FT4 / POLY_GT4) in a model
 * and copies its texture info.
 */
extern struct { s32 f_0; } g_Game;
extern s32 D_800EA060[];
extern s32 D_800AE860[];

s32 Model_FindPrim(S_Model_80015F70_80015F70 *m, S_Out_80015F70_80015F70 *out, s32 type, s32 idx) {
    S_Chunk_80015F70_80015F70 *c = m->f_8;
    s32 *tbl = m->f_4;
    s32 n = m->f_0->f_16;
    s32 k = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        if (c->f_3 == type) {
            if (k == idx) {
                switch (type & 0xFC) {
                case 0x2C:
                    out->f_4 = tbl[c->f_18];
                    out->f_C = c->f_C;
                    out->f_14 = c->f_10;
                    *(u16 *)&out->f_1C = c->f_14;
                    out->f_24 = c->f_16;
                    return 1;
                case 0x3C:
                    out->f_4 = tbl[c->f_18];
                    out->f_10 = tbl[c->f_19];
                    out->f_1C = tbl[c->f_1A];
                    out->f_28 = tbl[c->f_1B];
                    out->f_C = c->f_C;
                    out->f_18 = c->f_10;
                    out->f_24 = c->f_14;
                    out->f_30 = c->f_16;
                    return 1;
                default:
                    return 0;
                }
            }
            k++;
        }
        c = (S_Chunk_80015F70_80015F70 *)((u8 *)c + c->f_1 * 4);
    }
    return 0;
}

typedef struct { u8 pad0[0x12]; u16 nVerts; } MdlHdr_16100;
typedef struct { MdlHdr_16100 *hdr; u8 pad4[8]; SVECTOR *verts; } Mdl_16100;
typedef struct { u32 sxy; s32 sz; } Proj_16100;
#define gte_SetRotMatrix_(m) __asm__ volatile ( \
    "lw $12, 0(%0); lw $13, 4(%0); ctc2 $12, $0; ctc2 $13, $1; lw $12, 8(%0); lw $13, 12(%0); lw $14, 16(%0); ctc2 $12, $2; ctc2 $13, $3; ctc2 $14, $4" \
    : : "r"(m) : "$12", "$13", "$14")
#define gte_SetTransMatrix_(m) __asm__ volatile ( \
    "lw $12, 20(%0); lw $13, 24(%0); ctc2 $12, $5; lw $14, 28(%0); ctc2 $13, $6; ctc2 $14, $7" \
    : : "r"(m) : "$12", "$13", "$14")
#define gte_ldVXY3_(a, b, c) __asm__ volatile ("mtc2 %0, $0; nop; mtc2 %1, $2; nop; mtc2 %2, $4" : : "r"(a), "r"(b), "r"(c))
#define gte_ldVZ3_(v) __asm__ volatile ("lwc2 $1, %0; lwc2 $3, %1; lwc2 $5, %2" : : "m"((v)[0].vz), "m"((v)[1].vz), "m"((v)[2].vz))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxyz3_(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $17, 4(%0); swc2 $13, 8(%0); swc2 $18, 12(%0); swc2 $14, 16(%0); swc2 $19, 20(%0)" : : "r"(p) : "memory")

/* Model_ProjectVerts for a model whose vertex count is at header +0x12 (read before the matrix
   is loaded). */
void Model_ProjectVertsAlt(Mdl_16100 *mdl, void *m, Proj_16100 *out) {
    s32 i = 0;
    SVECTOR *vs = mdl->verts;
    SVECTOR *v;
    s32 n = mdl->hdr->nVerts;
    s32 a, b, c;

    gte_SetRotMatrix_(m);
    gte_SetTransMatrix_(m);
    a = *(s32 *)&vs[0];
    b = *(s32 *)&vs[1];
    c = *(s32 *)&vs[2];
    for (; i < n; i += 3) {
        v = &vs[i];
        gte_ldVXY3_(a, b, c);
        gte_ldVZ3_(v);
        gte_rtpt_n();
        a = *(s32 *)&v[3];
        b = *(s32 *)&v[4];
        c = *(s32 *)&v[5];
        gte_stsxyz3_(out);
        out += 3;
    }
}

typedef struct { u8 pad0[6]; u16 nVerts; } MdlHdr_161C0;
typedef struct { MdlHdr_161C0 *hdr; u8 pad4[8]; SVECTOR *verts; } Mdl_161C0;
typedef struct { u32 sxy; s32 sz; } Proj_161C0;

/* Projects a model's vertices through matrix m into out (screen point and depth per vertex),
   three at a time, fetching the next triple's x/y words while the GTE works. */
void Model_ProjectVerts(Mdl_161C0 *mdl, void *m, Proj_161C0 *out) {
    s32 i = 0;
    SVECTOR *vs = mdl->verts;
    SVECTOR *v;
    s32 n, a, b, c;

    gte_SetRotMatrix_(m);
    gte_SetTransMatrix_(m);
    a = *(s32 *)&vs[0];
    b = *(s32 *)&vs[1];
    c = *(s32 *)&vs[2];
    n = mdl->hdr->nVerts;
    for (; i < n; i += 3) {
        v = &vs[i];
        gte_ldVXY3_(a, b, c);
        gte_ldVZ3_(v);
        gte_rtpt_n();
        a = *(s32 *)&v[3];
        b = *(s32 *)&v[4];
        c = *(s32 *)&v[5];
        gte_stsxyz3_(out);
        out += 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_80016294);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_ProjectMorphFrame);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_ProjectBonedVerts);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_CalcEnvMapUVs);

int abs(int);
typedef struct { u16 f_0; u8 pad2[4]; u16 f_6; } S_Hdr_16D60;
typedef struct { S_Hdr_16D60 *f_0; } S_Model_16D60;
typedef struct { u8 pad0[6]; u16 f_6; } S_Out_16D60;

/* Environment-map UVs for the rotated normals in a 64x64 texel area: u from the normal's y and v
   from its x, both scaled by |z| and clamped to 0..63, packed as (u << 8) | v (permuter match) */
void Model_CalcEnvMapUVs64(S_Model_16D60 *m)
{
    s32 i;
    int k;
    S_Out_16D60 *out;
    SVECTOR *nrm;
    s32 x, y, z, u, w, t;

    out = (S_Out_16D60 *)D_800EA060;
    nrm = (SVECTOR *)((u8 *)m->f_0 + m->f_0->f_0 * 4);
    for (i = 0; i < m->f_0->f_6; i++) {
        __asm__ volatile("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(&nrm[i]));
        __asm__ volatile("nop; nop; rtv0");
        __asm__ volatile("mfc2 %0, $27" : "=r"(z));
        __asm__ volatile("mfc2 %0, $26" : "=r"(y));
        __asm__ volatile("mfc2 %0, $25" : "=r"(x));
        z = abs(z);
        u = ((z * -(y * 40)) >> 24) + 0x1F;
        t = u;
        t = (t < 0) ? 0 : (t >= 0x40) ? 0x3F : t;
        u = t;
        t = ((z * (x * (k = 40))) >> 24) + 0x1F;
        w = (t < 0) ? 0 : (t >= 0x40) ? 0x3F : t;
        out[i].f_6 = (u << 8) | w;
    }
}

/* Advances an animation player's frame (+0x18) by one unless paused (flags +0x1A bit 0). Past the
 * last frame (the count stored data->f_C words into the animation data) it stays on the last
 * frame when flags bit 1 is set, otherwise wraps to frame 1. */
void Anim_StepFrame(S_16E68_80016E68 *s) {
    u32 frame = s->f_18;
    u16 flags = s->f_1A;
    u16 *q = (u16 *)((s32 *)s->f_0 + s->f_0->f_C);
    u32 nf;
    nf = frame + 1;
    if (!(flags & 1)) {
        if (*q < nf) {
            if (flags & 2) {
                nf = frame;
            } else {
                nf = 1;
            }
        }
        s->f_18 = nf;
    }
}

void func_80016EBC(s32 arg0, M2C_UNK arg1, void **arg2) {
    if (M2C_FIELD(*arg2, u16 *, 0xA) != 0) {
        Model_CalcEnvMapUVs(arg2);
        func_8001CE54(arg0, arg1, arg2);
        return;
    }
    func_80017CD4(arg0, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_80016F34);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4550);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4550_pad);


/* Lights the model's vertex colours (GTE cc) into the scratchpad, then sets the
 * scratch draw mode 2 with the D_800EBFA0 values and draws via Model_DrawPrims.
 */
void func_80017CD4(s32 arg0, s32 arg1, S_Model_17E5C *arg2) {
    s32 i;
    s32 n;
    s32 *src;
    u8 *c;
    S_Scr_17E5C *sc = (S_Scr_17E5C *)0x1F800000;

    n = arg2->f_0->f_8;
    c = arg2->f_8;
    src = arg2->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(0x1000, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    sc->f_3F4 = 2;
    sc->f_3C0 = D_800EBFA0.f_24;
    sc->f_3C2 = D_800EBFA0.f_28;
    Model_DrawPrims(arg0, c, arg1);
}

/* Like func_80017CD4, with draw mode 6 and the extra value arg3 at scratch 0x3C4. */
void func_80017D94(s32 arg0, s32 arg1, S_Model_17E5C *arg2, s32 arg3) {
    s32 i;
    s32 n;
    s32 *src;
    u8 *c = arg2->f_8;
    S_Scr_17E5C *sc = (S_Scr_17E5C *)0x1F800000;

    sc->f_3C6 = 0;
    sc->f_3C4 = arg3;
    sc->f_3F4 = 6;
    sc->f_3C0 = D_800EBFA0.f_24;
    sc->f_3C2 = D_800EBFA0.f_28;
    n = arg2->f_0->f_8;
    src = arg2->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(0x1000, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    Model_DrawPrims(arg0, c, arg1);
}

/* Lights the model's n vertex colours with the GTE (cc: colour * light colour) into
 * the scratchpad, clears the scratch draw flags, then draws via Model_DrawPrims.
 */
void func_80017E5C(s32 arg0, s32 arg1, S_Model_17E5C *arg2) {
    s32 i;
    s32 n;
    s32 *src;
    u8 *c = arg2->f_8;
    S_Scr_17E5C *sc = (S_Scr_17E5C *)0x1F800000;

    sc->f_3F4 = 0;
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    n = arg2->f_0->f_E;
    src = arg2->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(0x1000, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    Model_DrawPrims(arg0, c, arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_80017EFC);

/* Draws a model's primitives, grouped by type: the textured types (FT3, FT4, GT3, GT4)
 * with the GTE far colour set to 0, then the far colour from D_800EBFA0 for F3, F4, G3
 * and G4. Each per-type function draws its run and returns the next primitive.
 */
void Model_DrawPrims(s32 ot, u8 *prim, s32 arg2) {
    s32 code = prim[3] & 0xFC;

    gte_ldFCR(0);
    gte_ldFCG(0);
    gte_ldFCB(0);
    if (code == 0x24) {
        prim = Model_AddFT3(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x2C) {
        prim = Model_AddFT4(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x34) {
        prim = Model_AddGT3(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x3C) {
        prim = Model_AddGT4(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    gte_ldFCR(D_800EBFA0.f_1C);
    gte_ldFCG(D_800EBFA0.f_1D);
    gte_ldFCB(D_800EBFA0.f_1E);
    if (code == 0x20) {
        prim = Model_AddF3(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x28) {
        prim = Model_AddF4(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x30) {
        prim = Model_AddG3(ot, prim, arg2);
        code = prim[3] & 0xFC;
    }
    if (code == 0x38) {
        Model_AddG4(ot, prim, arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddG3);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddG4);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddF3);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddF4);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddFT3);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddGT3);

typedef struct { u8 pad0[0xE]; u16 nColors; } LitHdr_1A42C;
typedef struct { u32 colors[0xFD]; u8 mode; } Scr_1A42C;
typedef struct { LitHdr_1A42C *hdr; u32 *colors; u8 *prims; } LitMdl_1A42C;

/* Draws a model's primitives with its vertex colours put through the GTE light-colour step
   (into the scratch pad, light mode 7), dispatching on each primitive's GPU code until one that
   is not a polygon. */
void Model_DrawLit(s32 ot, s32 arg, LitMdl_1A42C *m) {
    u8 *prim = m->prims;
    u32 *src;
    s32 i, n;

    ((Scr_1A42C *)0x1F800000)->mode = 7;
    n = m->hdr->nColors;
    src = m->colors;
    for (i = 0; i < n; i++) {
        gte_ldIR(0x1000, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&((u32 *)0x1F800000)[i]);
    }
    for (;;) {
        switch (prim[3] & 0xFC) {
        case 0x20:
            prim = Model_AddF3(ot, prim, arg);
            break;
        case 0x24:
            prim = Model_AddFT3(ot, prim, arg);
            break;
        case 0x28:
            prim = Model_AddF4(ot, prim, arg);
            break;
        case 0x2C:
            prim = Model_AddFT4(ot, prim, arg);
            break;
        case 0x30:
            prim = Model_AddG3(ot, prim, arg);
            break;
        case 0x34:
            prim = Model_AddGT3(ot, prim, arg);
            break;
        case 0x38:
            prim = Model_AddG4(ot, prim, arg);
            break;
        case 0x3C:
            prim = Model_AddGT4(ot, prim, arg);
            break;
        default:
            return;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4598_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddFT4);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddGT4);

typedef struct { u32 sxy; u16 z; u16 pad; } Vtx_1C2E8;
typedef struct { u8 pad0[8]; u8 *prims; } Mdl_1C2E8;
typedef struct { u8 pad0[0x3C4]; u32 sxy[4]; s32 z; s32 opz; u16 idx[4]; } Scr_1C2E8;
typedef struct { u32 tag; u8 r0, g0, b0, code; u16 x0, y0; u8 u0, v0; u16 clut; u16 x1, y1; u8 u1, v1; u16 tpage; u16 x2, y2; u8 u2, v2; u16 pad; u16 x3, y3; u8 u3, v3; u16 pad2; } Poly_1C2E8;
extern u8 *D_800EC354_1C2E8 asm("D_800EC354");
extern u8 g_Game_1C2E8 asm("g_Game");
#define gte_ldsxy3_(p) __asm__ volatile ("lwc2 $12, 0(%0); lwc2 $13, 4(%0); lwc2 $14, 8(%0)" : : "r"(p))
#define gte_nclip_() __asm__ volatile ("nop; nop; nclip")
#define gte_stopz_(p) __asm__ volatile ("swc2 $24, 0(%0)" : : "r"(p) : "memory")
#define gte_stsxy3_ft3_(p) __asm__ volatile ("swc2 $12, 8(%0); swc2 $13, 16(%0); swc2 $14, 24(%0)" : : "r"(p) : "memory")

/* Model_DrawScreenMapped: draws a model's polygons as flat textured polys (0x25 / 0x2D) whose UVs come from the
   screen position (u = x / 2 + 0x20, v = y), from the projected vertices v (screen xy + depth).
   Polygons wholly off one side of the screen, back-facing, or with a first vertex nearer than
   0x1B are skipped. */
void Model_DrawScreenMapped(u32 *ot, Vtx_1C2E8 *v, Mdl_1C2E8 *m) {
    Scr_1C2E8 *sc = (Scr_1C2E8 *)0x1F800000;
    u8 *prim = G_DRAW.prim;
    u8 *pr = m->prims;
    u16 tpage = 0x101;
    u32 a, b, c, d;

    if (G_DRAW.cur != 0) {
        tpage = 0x111;
    }
    for (;;) {
        switch (pr[3] & 0xFC) {
        case 0x20:
        case 0x24:
        case 0x30:
        case 0x34:
            sc->idx[0] = ((u16 *)pr)[2];
            sc->sxy[0] = v[(s16)sc->idx[0]].sxy;
            sc->idx[1] = ((u16 *)pr)[3];
            sc->sxy[1] = v[(s16)sc->idx[1]].sxy;
            sc->idx[2] = ((u16 *)pr)[4];
            sc->sxy[2] = v[(s16)sc->idx[2]].sxy;
            gte_ldsxy3_(sc->sxy);
            gte_nclip_();
            if (((sc->sxy[0] & 0xFFFF) > 0x180 & (sc->sxy[1] & 0xFFFF) > 0x180 & (sc->sxy[2] & 0xFFFF) > 0x180)
                || ((sc->sxy[0] >> 16) > 0xF0 & (sc->sxy[1] >> 16) > 0xF0 & (sc->sxy[2] >> 16) > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = (((s16)v[(s16)sc->idx[0]].z >> 2) + ((s16)v[(s16)sc->idx[1]].z >> 2) + ((s16)v[(s16)sc->idx[2]].z >> 2)) / 3;
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                    ADD_PRIM_R(&ot[sc->z], prim, "$4", "$2");
                    gte_stsxy3_ft3_(prim);
                    prim[3] = 7;
                    ((Poly_1C2E8 *)prim)->code = 0x25;
                    ((Poly_1C2E8 *)prim)->tpage = tpage;
                    ((Poly_1C2E8 *)prim)->u0 = (s16)((Poly_1C2E8 *)prim)->x0 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v0 = ((Poly_1C2E8 *)prim)->y0;
                    ((Poly_1C2E8 *)prim)->u1 = (s16)((Poly_1C2E8 *)prim)->x1 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v1 = ((Poly_1C2E8 *)prim)->y1;
                    ((Poly_1C2E8 *)prim)->u2 = (s16)((Poly_1C2E8 *)prim)->x2 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v2 = ((Poly_1C2E8 *)prim)->y2;
                    prim += 0x20;
                    pr += pr[1] * 4;
                }
            }
            break;
        case 0x28:
        case 0x2C:
        case 0x38:
        case 0x3C:
            sc->idx[0] = ((u16 *)pr)[2];
            sc->sxy[0] = v[(s16)sc->idx[0]].sxy;
            sc->idx[1] = ((u16 *)pr)[3];
            sc->sxy[1] = v[(s16)sc->idx[1]].sxy;
            sc->idx[2] = ((u16 *)pr)[4];
            sc->sxy[2] = v[(s16)sc->idx[2]].sxy;
            sc->idx[3] = ((u16 *)pr)[5];
            sc->sxy[3] = v[(s16)sc->idx[3]].sxy;
            gte_ldsxy3_(sc->sxy);
            gte_nclip_();
            if (((sc->sxy[0] & 0xFFFF) > 0x180 & (sc->sxy[1] & 0xFFFF) > 0x180 & (sc->sxy[2] & 0xFFFF) > 0x180 & (sc->sxy[3] & 0xFFFF) > 0x180)
                || ((sc->sxy[0] >> 16) > 0xF0 & (sc->sxy[1] >> 16) > 0xF0 & (sc->sxy[2] >> 16) > 0xF0 & (sc->sxy[3] >> 16) > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = ((s16)v[(s16)sc->idx[0]].z >> 4) + ((s16)v[(s16)sc->idx[1]].z >> 4) + ((s16)v[(s16)sc->idx[2]].z >> 4) + ((s16)v[(s16)sc->idx[3]].z >> 4);
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                    ADD_PRIM_R(&ot[sc->z], prim, "$4", "$2");
                    gte_stsxy3_ft3_(prim);
                    *(u32 *)&((Poly_1C2E8 *)prim)->x3 = sc->sxy[3];
                    prim[3] = 9;
                    ((Poly_1C2E8 *)prim)->code = 0x2D;
                    ((Poly_1C2E8 *)prim)->tpage = tpage;
                    ((Poly_1C2E8 *)prim)->u0 = (s16)((Poly_1C2E8 *)prim)->x0 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v0 = ((Poly_1C2E8 *)prim)->y0;
                    ((Poly_1C2E8 *)prim)->u1 = (s16)((Poly_1C2E8 *)prim)->x1 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v1 = ((Poly_1C2E8 *)prim)->y1;
                    ((Poly_1C2E8 *)prim)->u2 = (s16)((Poly_1C2E8 *)prim)->x2 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v2 = ((Poly_1C2E8 *)prim)->y2;
                    ((Poly_1C2E8 *)prim)->u3 = (s16)((Poly_1C2E8 *)prim)->x3 / 2 + 0x20;
                    ((Poly_1C2E8 *)prim)->v3 = ((Poly_1C2E8 *)prim)->y3;
                    prim += 0x28;
                    pr += pr[1] * 4;
                }
            }
            break;
        default:
            goto done;
        }
    }
done:
    D_800EC354_1C2E8 = prim;
}

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4610_pad);


typedef struct { u32 sxy; u16 z; u16 pad; } Vtx_1C918;
typedef struct { u8 pad0[8]; u8 *prims; } Mdl_1C918;
typedef struct { u8 pad0[0x3C4]; u32 sxy[4]; s32 z; s32 opz; u16 idx[4]; } Scr_1C918;
typedef struct { u32 tag; u8 r0, g0, b0, code; u32 xy[6]; } Line_1C918;
extern u8 *D_800EC354_1C918 asm("D_800EC354");
#define gte_ldsxy3_1C918(p) __asm__ volatile ("lwc2 $12, 0(%0); lwc2 $13, 4(%0); lwc2 $14, 8(%0)" : : "r"(p))
#define gte_nclip_1C918() __asm__ volatile ("nop; nop; nclip")
#define gte_stopz_1C918(p) __asm__ volatile ("swc2 $24, 0(%0)" : : "r"(p) : "memory")
#define gte_stsxy_3l_1C918(p) __asm__ volatile ("swc2 $12, 8(%0); swc2 $13, 12(%0); swc2 $14, 16(%0); swc2 $12, 20(%0)" : : "r"(p) : "memory")
#define gte_stsxy_4l_1C918(p) __asm__ volatile ("swc2 $12, 8(%0); swc2 $13, 12(%0); swc2 $14, 20(%0); swc2 $12, 24(%0)" : : "r"(p) : "memory")

/* Model_DrawWireframe: draws a model as a green wireframe: each visible triangle or quad becomes a closed polyline
   (v0 v1 v2 v0, or v0 v1 v3 v2 v0), with the same culling and depth as Model_DrawScreenMapped. */
void Model_DrawWireframe(u32 *ot, Vtx_1C918 *v, Mdl_1C918 *m) {
    Scr_1C918 *sc = (Scr_1C918 *)0x1F800000;
    u8 *prim = D_800EC354_1C918;
    u8 *pr = m->prims;

    for (;;) {
        switch (pr[3] & 0xFC) {
        case 0x20:
        case 0x24:
        case 0x30:
        case 0x34:
            sc->idx[0] = ((u16 *)pr)[2];
            sc->sxy[0] = v[(s16)sc->idx[0]].sxy;
            sc->idx[1] = ((u16 *)pr)[3];
            sc->sxy[1] = v[(s16)sc->idx[1]].sxy;
            sc->idx[2] = ((u16 *)pr)[4];
            sc->sxy[2] = v[(s16)sc->idx[2]].sxy;
            gte_ldsxy3_1C918(sc->sxy);
            gte_nclip_1C918();
            if (((sc->sxy[0] & 0xFFFF) > 0x180 & (sc->sxy[1] & 0xFFFF) > 0x180 & (sc->sxy[2] & 0xFFFF) > 0x180)
                || ((sc->sxy[0] >> 16) > 0xF0 & (sc->sxy[1] >> 16) > 0xF0 & (sc->sxy[2] >> 16) > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1C918(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = (((s16)v[(s16)sc->idx[0]].z >> 2) + ((s16)v[(s16)sc->idx[1]].z >> 2) + ((s16)v[(s16)sc->idx[2]].z >> 2)) / 3;
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                    ADD_PRIM_R(&ot[sc->z], prim, "$4", "$2");
                    gte_stsxy_3l_1C918(prim);
                    prim[3] = 6;
                    ((Line_1C918 *)prim)->code = 0x4C;
                    ((Line_1C918 *)prim)->xy[4] = 0x55555555;
                    ((Line_1C918 *)prim)->r0 = 0;
                    ((Line_1C918 *)prim)->g0 = 0xFF;
                    ((Line_1C918 *)prim)->b0 = 0;
                    prim += 0x1C;
                    pr += pr[1] * 4;
                }
            }
            break;
        case 0x28:
        case 0x2C:
        case 0x38:
        case 0x3C:
            sc->idx[0] = ((u16 *)pr)[2];
            sc->sxy[0] = v[(s16)sc->idx[0]].sxy;
            sc->idx[1] = ((u16 *)pr)[3];
            sc->sxy[1] = v[(s16)sc->idx[1]].sxy;
            sc->idx[2] = ((u16 *)pr)[4];
            sc->sxy[2] = v[(s16)sc->idx[2]].sxy;
            sc->idx[3] = ((u16 *)pr)[5];
            sc->sxy[3] = v[(s16)sc->idx[3]].sxy;
            gte_ldsxy3_1C918(sc->sxy);
            gte_nclip_1C918();
            if (((sc->sxy[0] & 0xFFFF) > 0x180 & (sc->sxy[1] & 0xFFFF) > 0x180 & (sc->sxy[2] & 0xFFFF) > 0x180 & (sc->sxy[3] & 0xFFFF) > 0x180)
                || ((sc->sxy[0] >> 16) > 0xF0 & (sc->sxy[1] >> 16) > 0xF0 & (sc->sxy[2] >> 16) > 0xF0 & (sc->sxy[3] >> 16) > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1C918(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = ((s16)v[(s16)sc->idx[0]].z >> 4) + ((s16)v[(s16)sc->idx[1]].z >> 4) + ((s16)v[(s16)sc->idx[2]].z >> 4) + ((s16)v[(s16)sc->idx[3]].z >> 4);
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                    ADD_PRIM_R(&ot[sc->z], prim, "$4", "$2");
                    ((Line_1C918 *)prim)->r0 = 0;
                    ((Line_1C918 *)prim)->g0 = 0xFF;
                    ((Line_1C918 *)prim)->b0 = 0;
                    gte_stsxy_4l_1C918(prim);
                    ((Line_1C918 *)prim)->xy[2] = sc->sxy[3];
                    prim[3] = 7;
                    ((Line_1C918 *)prim)->code = 0x4C;
                    ((Line_1C918 *)prim)->xy[5] = 0x55555555;
                    prim += 0x20;
                    pr += pr[1] * 4;
                }
            }
            break;
        default:
            goto done;
        }
    }
done:
    D_800EC354_1C918 = prim;
}

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4688_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001CE54);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4700);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4700_pad);


/* Model_CycleVertexColors: per-vertex colour i = palette D_800AE860[(frame + vertex +2) % 20],
 * for Model_DrawCycledColors (objects with flag bit 26). */
void Model_CycleVertexColors(S_1D4A8_8001D4A8 *a, s32 n) {
    S_1D4A8_8001D4A8 *p = a;
    s32 *d = D_800EA060;
    s32 base = g_Game.f_0;
    s32 i;
    s32 t;
    for (i = 0; i < n; i++) {
        t = base + p->f_2;
        t %= 20;
        *d = D_800AE860[t];
        p++;
        d++;
    }
}

/* Model_DrawCycledColors (hand-written asm: uses add, which GCC never emits): draws a model as
 * gouraud polys with the per-vertex colours from Model_CycleVertexColors (D_800EA060). */
INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_DrawCycledColors);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4778);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4778_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001DB74);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001E828);
