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

typedef struct { u8 pad0[4]; u16 nBones; } MdlHdr_16A6C;
typedef struct { u16 count; u16 start; u8 pad4[8]; } Bone_16A6C;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_16A6C;
typedef struct { MdlHdr_16A6C *hdr; u8 pad4[8]; Bone_16A6C *bones; SVECTOR *verts; MAT_16A6C *mats; } Mdl_16A6C;
typedef struct { u32 sxy; s32 sz; } Proj_16A6C;
extern Proj_16A6C D_800E7D00_16A6C[] asm("D_800E7D00");

/* Projects a boned model's vertices into D_800E7D00: each bone's run of vertices (count, start)
   goes through that bone's matrix (mats[bone + 1]), three at a time as in Model_ProjectVerts. */
void Model_ProjectBonedVerts(Mdl_16A6C *mdl) {
    Proj_16A6C *proj;
    MAT_16A6C *mats;
    s32 nb;
    SVECTOR *vs;
    Bone_16A6C *bones;
    s32 k, i, a, b, c;
    register s32 end asm("$10");

    mats = mdl->mats;
    vs = mdl->verts;
    nb = mdl->hdr->nBones;
    bones = mdl->bones;
    proj = D_800E7D00_16A6C;

    for (k = 0; k < nb; k++) {
        gte_SetRotMatrix_(&mats[k + 1]);
        gte_SetTransMatrix_(&mats[k + 1]);
        i = bones[k].start;
        { register s32 cnt asm("$2") = bones[k].count; end = i + cnt; }
        {
        register SVECTOR *v asm("$3") = (SVECTOR *)(i * 8 + (s32)vs);
        register Proj_16A6C *pp asm("$4");
        a = *(s32 *)&v[0];
        b = *(s32 *)&v[1];
        c = *(s32 *)&v[2];
        if (i < end) {
            pp = (Proj_16A6C *)(i * 8 + (s32)proj);
            do {
                gte_ldVXY3_(a, b, c);
                gte_ldVZ3_(v);
                gte_rtpt_n();
                a = *(s32 *)&v[3];
                b = *(s32 *)&v[4];
                c = *(s32 *)&v[5];
                gte_stsxyz3_(pp);
                pp += 3;
                i += 3;
                v += 3;
            } while (i < end);
        }
        }
    }
}

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

extern u8 *D_800EC354_Model_AddG3 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddG3;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u8 pad3C4[4]; u8 cidx[4]; union { u32 w; struct { s16 x, y; } s; } sxy[3]; u8 pad3D8[4]; s32 otz; s32 opz; u8 pad3E4[4]; union { u32 w; u8 b[4]; } hdr; union { u32 w; u16 h[2]; } idx01; union { u32 w; u16 h[2]; } idx2; u8 flags; } MdlScratch_Model_AddG3;

/* Model Gouraud triangles (code 0x30 run): like Model_AddF3 with three vertex colours (dpct) */
u8 *Model_AddG3(s32 otArg, u8 *primArg, s32 vtxArg)
{
  register u8 *prim asm("$5") = primArg;
  u32 *ot = (u32 *)otArg;
  ScrVtx_Model_AddG3 *vtx = (ScrVtx_Model_AddG3 *)vtxArg;
  register MdlScratch_Model_AddG3 *MS asm("$9");
  u8 *p;
  u32 w0;
  u32 w1;
  u32 b;
  u32 a;
  u32 c;
  u32 *o;
  s32 f;
  s32 i0;
  p = D_800EC354_Model_AddG3;
  __asm__("" : "=r"(MS) : "0"(0x1F800000));
  do
  {
    w0 = *((u32 *) (prim + 4));
    w1 = *((u32 *) (prim + 8));
    MS->idx01.w = w0;
    a = w0 & 0xFFFF;
    a = vtx[a].sxy;
    b = w0 >> 16;
    b = vtx[b].sxy;
    c = w1 & 0xFFFF;
    MS->idx2.w = w1;
    c = vtx[c].sxy;
    __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13; nop; mtc2 %2, $14" : : "r"(a), "r"(b), "r"(c));
    MS->sxy[0].w = a;
    MS->sxy[1].w = b;
    MS->sxy[2].w = c;
    __asm__ volatile("nclip");
    {
      register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
      x0 = MS->sxy[0].s.x;
      x1 = MS->sxy[1].s.x;
      x2 = MS->sxy[2].s.x;
      if (x1 < x0) {
        hi = x2;
        if (hi < x0) hi = x0;
        lo = x2;
        if (x1 < x2) lo = x1;
      } else {
        hi = x2;
        if (hi < x1) hi = x1;
        lo = x2;
        if (x0 < x2) lo = x0;
      }
      if (hi < 0 || lo >= 0x181) goto skip;
    }
    {
      register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
      x0 = MS->sxy[0].s.y;
      x1 = MS->sxy[1].s.y;
      x2 = MS->sxy[2].s.y;
      if (x1 < x0) {
        hi = x2;
        if (hi < x0) hi = x0;
        lo = x2;
        if (x1 < x2) lo = x1;
      } else {
        hi = x2;
        if (hi < x1) hi = x1;
        lo = x2;
        if (x0 < x2) lo = x0;
      }
      if (hi < 0 || lo >= 0xF1) goto skip;
    }
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz) : "memory");
    {
    s32 j0;
    s32 j1;
    s32 j2;
    j0 = (s16)((volatile u16 *)&MS->idx01)[0];
    j1 = (s16)((volatile u16 *)&MS->idx01)[1];
    j2 = (s16)((volatile u16 *)&MS->idx2)[0];
    __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[j0].sz));
    __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j1].sz));
    __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[j2].sz));
    }
    __asm__ volatile("nop; nop; avsz3");
    __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
    if (MS->opz < 0 || MS->otz < 0x1B) {
      goto skip;
    }
    if (!(MS->flags & 1) && MS->otz - MS->fogNear > 0x100) {
    skip:
      prim += 0x10;
      continue;
    }
    MS->hdr.w = *(u32 *)prim;
    *(u32 *)MS->cidx = *(u32 *)(prim + 12);
    {
      u32 c0, c1, c2;
      c0 = MS->cidx[0];
      c1 = MS->cidx[1];
      c2 = MS->cidx[2];
      __asm__ volatile("lwc2 $20, %0" : : "m"(*(MS->color + c0)));
      __asm__ volatile("lwc2 $21, %0" : : "m"(*(MS->color + c1)));
      __asm__ volatile("lwc2 $22, %0" : : "m"(*(MS->color + c2)));
    }
    if (!(MS->flags & 4) && MS->fogNear < MS->otz) {
      MS->hdr.b[3] |= 2;
      MS->hdr.b[2] &= 0x60;
    }
    if (MS->otz >= 0xFC0) {
      MS->otz = 0xFBF;
    }
    o = ot;
    if (!(MS->flags & 1)) {
      o += MS->otz;
    }
    ADD_PRIM_R(o, p, "$3", "$2");
    i0 = (MS->otz - MS->fogNear) * MS->fogScale;
    MS->otz = i0 >> 12;
    if (MS->otz >= 0) {
      if (MS->otz > 0x1000) f = 0x1000;
      else f = MS->otz;
    } else {
      f = 0;
    }
    MS->otz = f;
    if (MS->fogScale != 0) {
      __asm__ volatile("mtc2 %0, $8; nop; nop; dpct" : : "r"(f));
    }
    if (MS->hdr.b[3] & 2) {
      *((u32 *)(p + 4)) = (MS->hdr.b[2] << 2) | 0xE1000200;
      p[3] = 7;
      p += 4;
    } else {
      p[3] = 6;
    }
    prim += 0x10;
    __asm__ volatile("swc2 $20, 4(%0); swc2 $21, 12(%0); swc2 $22, 20(%0)" : : "r"(p) : "memory");
    __asm__ volatile("swc2 $12, 8(%0); swc2 $13, 16(%0); swc2 $14, 24(%0)" : : "r"(p) : "memory");
    p[7] = MS->hdr.b[3];
    p += 0x1C;
  } while ((prim[3] & 0xFC) == 0x30);
  D_800EC354_Model_AddG3 = p;
  return prim;
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddG4);

extern u8 *D_800EC354_Model_AddF3 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddF3;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u8 pad3C4[8]; union { u32 w; struct { s16 x, y; } s; } sxy[3]; u8 pad3D8[4]; s32 otz; s32 opz; u8 pad3E4[8]; u32 idx01; u32 idx2; u8 flags; } MdlScratch_Model_AddF3;

/* Model flat triangles (code 0x20 run): for each POLY_F3 of the model, fetches the three projected
   vertices, skips it if off screen, back-facing (nclip), too near (otz < 27) or, unless scratch
   flag bit 0, too deep past the fog start; then depth-cues its colour (dpcs) and adds it to the OT
   (at its depth unless flag bit 0), with a texpage prefix for semi-transparent ones. Returns the
   first primitive of the next run. */
u8 *Model_AddF3(s32 otArg, u8 *prim, s32 vtxArg)
{
  u32 *ot = (u32 *)otArg;
  ScrVtx_Model_AddF3 *vtx = (ScrVtx_Model_AddF3 *)vtxArg;
  MdlScratch_Model_AddF3 *MS;
  u8 *p;
  u32 w0;
  u32 w1;
  u32 b;
  u32 a;
  u32 c;
  u32 *o;
  s32 f;
  s32 i0;
  s32 i1;
  s32 i2;
  __asm__("" : "=r"(MS) : "0"(0x1F800000));
  p = D_800EC354_Model_AddF3;
  do
  {
    w0 = *((u32 *) (prim + 4));
    w1 = *((u32 *) (prim + 8));
    MS->idx01 = w0;
    a = w0 & 0xFFFF;
    a = vtx[a].sxy;
    b = w0 >> 16;
    b = vtx[b].sxy;
    c = w1 & 0xFFFF;
    MS->idx2 = w1;
    c = vtx[c].sxy;
    __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13; nop; mtc2 %2, $14" : : "r"(a), "r"(b), "r"(c));
    MS->sxy[0].w = a;
    MS->sxy[1].w = b;
    MS->sxy[2].w = c;
    __asm__ volatile("nclip");
    {
      register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
    x0 = MS->sxy[0].s.x;
    x1 = MS->sxy[1].s.x;
    x2 = MS->sxy[2].s.x;
    if (x1 < x0)
    {
      hi = x2;
      if (hi < x0)
      {
        hi = x0;
      }
      lo = x2;
      if (x1 < x2)
      {
        lo = x1;
      }
    }
    else
    {
      hi = x2;
      if (hi < x1)
      {
        hi = x1;
      }
      lo = x2;
      if (x0 < x2)
      {
        lo = x0;
      }
    }
    if ((hi < 0) || (lo >= 0x181))
    {
      goto skip;
    }
    }
    {
      register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
    x0 = MS->sxy[0].s.y;
    x1 = MS->sxy[1].s.y;
    x2 = MS->sxy[2].s.y;
    if (x1 < x0)
    {
      hi = x2;
      if (hi < x0)
      {
        hi = x0;
      }
      lo = x2;
      if (x1 < x2)
      {
        lo = x1;
      }
    }
    else
    {
      hi = x2;
      if (hi < x1)
      {
        hi = x1;
      }
      lo = x2;
      if (x0 < x2)
      {
        lo = x0;
      }
    }
    if ((hi < 0) || (lo >= 0xF1))
    {
      goto skip;
    }
    }
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz) : "memory");
    i0 = (s16) ((volatile u16 *) (&MS->idx01))[0];
    i1 = (s16) ((volatile u16 *) (&MS->idx01))[1];
    i2 = (s16) ((volatile u16 *) (&MS->idx2))[0];
    __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[i0].sz));
    __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[i1].sz));
    __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[i2].sz));
    __asm__ volatile("nop; nop; avsz3");
    __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
    if ((MS->opz < 0) || (MS->otz < 0x1B))
    {
      goto skip;
    }
    if ((!(MS->flags & 1)) && ((MS->otz - MS->fogNear) > 0x100))
    {
      skip:
      prim += 0x10;

      continue;
    }
    if (MS->otz >= 0xFC0)
    {
      MS->otz = 0xFBF;
    }
    o = ot;
    if (!(MS->flags & 1))
    {
      o += MS->otz;
    }
    ADD_PRIM_R(o, p, "$3", "$2");
    i0 = (MS->otz - MS->fogNear) * MS->fogScale;
    MS->otz = ((s32) i0) >> 12;
    __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + prim[12])));
    if (MS->otz >= 0)
    {
      if (MS->otz > 0x1000)
      {
        f = 0x1000;
      }
      else
      {
        f = MS->otz;
      }
    }
    else
    {
      f = 0;
    }
    MS->otz = f;
    __asm__ volatile("mtc2 %0, $8; nop; nop; dpcs" : : "r"(f));
    if (prim[3] & 2)
    {
      *((u32 *) (p + 4)) = (prim[2] << 2) | 0xE1000200;
      p[3] = 5;
      p += 4;
    }
    else
    {
      p[3] = 4;
    }
    __asm__ volatile("swc2 $22, 0(%0)" : : "r"(p + 4) : "memory");
    __asm__ volatile("swc2 $12, 8(%0); swc2 $13, 12(%0); swc2 $14, 16(%0)" : : "r"(p) : "memory");
    p[7] = prim[3];
    p += 0x14;
    prim += 0x10;
  }
  while ((prim[3] & 0xFC) == 0x20);
  D_800EC354_Model_AddF3 = p;
  return prim;
}

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddF4);

extern u8 *D_800EC354_Model_AddFT3 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddFT3;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u16 clut; u8 pad3C6[2]; u8 cidx[4]; union { u32 w; struct { s16 x, y; } s; } sxy[3]; u8 pad3D8[4]; s32 otz; s32 opz; u8 pad3E4[4]; union { u32 w; u8 b[4]; } hdr; union { u32 w; u16 h[2]; } idx01; union { u32 w; u16 h[2]; } idx2; u8 flags; u8 mode; u16 tpage; } MdlScratch_Model_AddFT3;

/* Model flat textured triangles (code 0x24 run). Past the fog start, unless the scratch flags
   say otherwise, each gets per-vertex depth cueing (a POLY_GT3) and, for semi-transparent ones, a
   second white-fogged POLY_G3 on top; nearer ones are plain POLY_FT3s. Returns the next run. */
u8 *Model_AddFT3(s32 otArg, u8 *prim, s32 vtxArg)
{
    u32 *ot = (u32 *)otArg;
    ScrVtx_Model_AddFT3 *vtx = (ScrVtx_Model_AddFT3 *)vtxArg;
    register MdlScratch_Model_AddFT3 *MS asm("$9");
    u8 *p;
    u32 w0, w1, a, b, c;
    u32 *o;

    __asm__("" : "=r"(MS) : "0"(0x1F800000));
    p = D_800EC354_Model_AddFT3;
    do {
        w0 = *(u32 *)(prim + 4);
        w1 = *(u32 *)(prim + 8);
        MS->idx01.w = w0;
        a = w0 & 0xFFFF;
        a = vtx[a].sxy;
        b = w0 >> 16;
        b = vtx[b].sxy;
        c = w1 & 0xFFFF;
        MS->idx2.w = w1;
        c = vtx[c].sxy;
        __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13; nop; mtc2 %2, $14" : : "r"(a), "r"(b), "r"(c));
        MS->sxy[0].w = a;
        MS->sxy[1].w = b;
        MS->sxy[2].w = c;
        __asm__ volatile("nclip");
        {
            register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
            x0 = MS->sxy[0].s.x;
            x1 = MS->sxy[1].s.x;
            x2 = MS->sxy[2].s.x;
            if (x1 < x0) {
                hi = x2;
                if (hi < x0) hi = x0;
                lo = x2;
                if (x1 < x2) lo = x1;
            } else {
                hi = x2;
                if (hi < x1) hi = x1;
                lo = x2;
                if (x0 < x2) lo = x0;
            }
            if (hi < 0 || lo >= 0x181) goto skip;
        }
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz) : "memory");
        if (MS->opz < 0) goto skip;
        {
            register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$8"); s32 lo;
            x0 = MS->sxy[0].s.y;
            x1 = MS->sxy[1].s.y;
            x2 = MS->sxy[2].s.y;
            if (x1 < x0) {
                hi = x2;
                if (hi < x0) hi = x0;
                lo = x2;
                if (x1 < x2) lo = x1;
            } else {
                hi = x2;
                if (hi < x1) hi = x1;
                lo = x2;
                if (x0 < x2) lo = x0;
            }
            if (hi < 0 || lo >= 0xF1) goto skip;
        }
        {
            s32 j0, j1, j2;
            j0 = (s16)((volatile u16 *)&MS->idx01)[0];
            j1 = (s16)((volatile u16 *)&MS->idx01)[1];
            j2 = (s16)((volatile u16 *)&MS->idx2)[0];
            __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[j0].sz));
            __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j1].sz));
            __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[j2].sz));
        }
        __asm__ volatile("nop; nop; avsz3");
        __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
        if (MS->otz < 0x1B) {
            goto skip;
        }
        {
            s32 z0, z1, z2, fn;
            fn = MS->fogNear << 2;
            MS->hdr.w = *(u32 *)prim;
            __asm__ volatile("mfc2 %0, $17" : "=r"(z0));
            __asm__ volatile("mfc2 %0, $18" : "=r"(z1));
            __asm__ volatile("mfc2 %0, $19" : "=r"(z2));
            z0 = (z0 - fn) << 2;
            z1 = (z1 - fn) << 2;
            z2 = (z2 - fn) << 2;
            if (z0 < 0) z0 = 0;
            __asm__ volatile("mtc2 %0, $17" : : "r"(z0));
            if (z1 < 0) z1 = 0;
            __asm__ volatile("mtc2 %0, $18" : : "r"(z1));
            if (z2 < 0) z2 = 0;
            __asm__ volatile("mtc2 %0, $19" : : "r"(z2));
            if ((z0 == 0 && z1 == 0 && z2 == 0) || (z0 > 0x1000 && z1 > 0x1000 && z2 > 0x1000) || (MS->flags & 1)) {
                MS->mode = 0;
            } else {
                MS->mode = ((MS->flags & 4) || (MS->hdr.b[3] & 2) || MS->hdr.b[2] == 0) ? 1 : 3;
            }
        }
        if (!(MS->flags & 1) && MS->fogNear < MS->otz && MS->mode == 0) {
        skip:
            prim += 0x1C;
            continue;
        }
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        MS->tpage = *(u16 *)(prim + 0x12);
        *(u32 *)MS->cidx = *(u32 *)(prim + 0x18);
        if (MS->mode != 0) {
            if (!(MS->flags & 4)) {
                u8 h = MS->hdr.b[3];
                if (!(h & 2)) {
                    MS->hdr.b[3] = h | 2;
                    if (MS->flags & 8) MS->tpage = MS->tpage & 0xFF9F;
                    else MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                }
            }
            {
                u32 c0, z;
                c0 = MS->cidx[0];
                __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                __asm__ volatile("nop; nop; dpcs");
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                __asm__ volatile("nop; nop; dpcs");
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                __asm__ volatile("swc2 $13, %0" : "=m"(*(u32 *)(p + 20)));
                __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                __asm__ volatile("nop; nop; dpcs");
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                __asm__ volatile("swc2 $14, %0" : "=m"(*(u32 *)(p + 32)));
            }
            *(u32 *)(p + 8) = MS->sxy[0].w;
            *(u32 *)(p + 12) = *(u32 *)(prim + 12) + (MS->clut << 16);
            *(u32 *)(p + 24) = *(u16 *)(prim + 16) | (MS->tpage << 16);
            *(u16 *)(p + 36) = *(u16 *)(prim + 20);
            p[3] = 9;
            p[7] = (MS->hdr.b[3] & 3) | 0x34;
            ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
            p += 0x28;
            if (!(MS->mode & 2)) goto skip;
            {
                u32 z;
                s32 white = -1;
                __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                z = MS->sxy[0].w;
                __asm__ volatile("nop; nop; dpcs");
                *(u32 *)(p + 12) = z;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                z = MS->sxy[1].w;
                __asm__ volatile("nop; nop; dpcs");
                *(u32 *)(p + 4) = 0xE1000240;
                p[3] = 7;
                p[11] = 0x32;
                *(u32 *)(p + 20) = z;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                z = MS->sxy[2].w;
                __asm__ volatile("nop; nop; dpcs");
                *(u32 *)(p + 28) = z;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
            }
            ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
            p += 0x20;
        } else {
            *(u32 *)(p + 4) = *(MS->color + prim[0x18]);
            *(u32 *)(p + 8) = MS->sxy[0].w;
            __asm__ volatile("swc2 $13, %0; swc2 $14, %1" : "=m"(*(u32 *)(p + 16)), "=m"(*(u32 *)(p + 24)));
            *(u32 *)(p + 12) = *(u32 *)(prim + 12) + (MS->clut << 16);
            *(u32 *)(p + 20) = *(u16 *)(prim + 16) | (MS->tpage << 16);
            *(u16 *)(p + 28) = *(u16 *)(prim + 20);
            p[3] = 7;
            p[7] = MS->hdr.b[3];
            o = ot;
            if (!(MS->flags & 1)) {
                o += MS->otz;
            }
            ADD_PRIM_R(o, p, "$3", "$2");
            p += 0x20;
        }
        prim += 0x1C;
    } while ((prim[3] & 0xFC) == 0x24);
    D_800EC354_Model_AddFT3 = p;
    return prim;
}

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
            if (((sc->sxy[0] & 0xFFFF) > SCREEN_W & (sc->sxy[1] & 0xFFFF) > SCREEN_W & (sc->sxy[2] & 0xFFFF) > SCREEN_W)
                || ((sc->sxy[0] >> 16) > SCREEN_H & (sc->sxy[1] >> 16) > SCREEN_H & (sc->sxy[2] >> 16) > SCREEN_H)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = (((s16)v[(s16)sc->idx[0]].z >> 2) + ((s16)v[(s16)sc->idx[1]].z >> 2) + ((s16)v[(s16)sc->idx[2]].z >> 2)) / 3;
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= OT_MAX_Z) ? OT_MAX_Z - 1 : sc->z);
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
            if (((sc->sxy[0] & 0xFFFF) > SCREEN_W & (sc->sxy[1] & 0xFFFF) > SCREEN_W & (sc->sxy[2] & 0xFFFF) > SCREEN_W & (sc->sxy[3] & 0xFFFF) > SCREEN_W)
                || ((sc->sxy[0] >> 16) > SCREEN_H & (sc->sxy[1] >> 16) > SCREEN_H & (sc->sxy[2] >> 16) > SCREEN_H & (sc->sxy[3] >> 16) > SCREEN_H)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = ((s16)v[(s16)sc->idx[0]].z >> 4) + ((s16)v[(s16)sc->idx[1]].z >> 4) + ((s16)v[(s16)sc->idx[2]].z >> 4) + ((s16)v[(s16)sc->idx[3]].z >> 4);
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= OT_MAX_Z) ? OT_MAX_Z - 1 : sc->z);
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
            if (((sc->sxy[0] & 0xFFFF) > SCREEN_W & (sc->sxy[1] & 0xFFFF) > SCREEN_W & (sc->sxy[2] & 0xFFFF) > SCREEN_W)
                || ((sc->sxy[0] >> 16) > SCREEN_H & (sc->sxy[1] >> 16) > SCREEN_H & (sc->sxy[2] >> 16) > SCREEN_H)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1C918(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = (((s16)v[(s16)sc->idx[0]].z >> 2) + ((s16)v[(s16)sc->idx[1]].z >> 2) + ((s16)v[(s16)sc->idx[2]].z >> 2)) / 3;
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= OT_MAX_Z) ? OT_MAX_Z - 1 : sc->z);
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
            if (((sc->sxy[0] & 0xFFFF) > SCREEN_W & (sc->sxy[1] & 0xFFFF) > SCREEN_W & (sc->sxy[2] & 0xFFFF) > SCREEN_W & (sc->sxy[3] & 0xFFFF) > SCREEN_W)
                || ((sc->sxy[0] >> 16) > SCREEN_H & (sc->sxy[1] >> 16) > SCREEN_H & (sc->sxy[2] >> 16) > SCREEN_H & (sc->sxy[3] >> 16) > SCREEN_H)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1C918(&sc->opz);
                if (sc->opz < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = ((s16)v[(s16)sc->idx[0]].z >> 4) + ((s16)v[(s16)sc->idx[1]].z >> 4) + ((s16)v[(s16)sc->idx[2]].z >> 4) + ((s16)v[(s16)sc->idx[3]].z >> 4);
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= OT_MAX_Z) ? OT_MAX_Z - 1 : sc->z);
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
