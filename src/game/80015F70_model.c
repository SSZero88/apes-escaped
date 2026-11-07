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
void func_8001CE54();
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

typedef struct { s16 vx, vy, vz, pad; } SV_16294;
typedef struct { u8 pad0[0x12]; u16 nVerts; } Hdr_16294;
typedef struct { Hdr_16294 *hdr; u8 pad4[8]; SV_16294 *verts; u8 pad10[0xC]; s32 flags; } Mdl_16294;
typedef struct { u32 sxy; s32 sz; } Proj_16294;
typedef struct { SV_16294 t; SV_16294 v[3]; } Scr_16294;
typedef struct { s16 x, y; } __attribute__((aligned(4))) XY_16294;
#define gte_ldv3m_16294(v) __asm__ volatile ("lwc2 $0, %0; lwc2 $1, %1; lwc2 $2, %2; lwc2 $3, %3; lwc2 $4, %4; lwc2 $5, %5" : : "m"(*(s32 *)&(v)[0].vx), "m"((v)[0].vz), "m"(*(s32 *)&(v)[1].vx), "m"((v)[1].vz), "m"(*(s32 *)&(v)[2].vx), "m"((v)[2].vz))
#define gte_ldv3c_16294(p) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(p))
#define gte_rtpt_16294() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxyz3_16294(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 8(%0); swc2 $14, 16(%0); swc2 $17, 4(%0); swc2 $18, 12(%0); swc2 $19, 20(%0)" : : "r"(p) : "memory")

void func_80016294(Mdl_16294 *m, Proj_16294 *out) {
    Scr_16294 *sc;
    SV_16294 *p;
    register SV_16294 *q asm("$4");
    s32 n;
    s32 tx, ty, tz;
    s32 i;
    s32 k;

    sc = (Scr_16294 *)0x1F8003C8;
    __asm__("" : "=r"(sc) : "0"(sc));
    n = m->hdr->nVerts;
    p = m->verts;
    __asm__ volatile("");
    tx = sc->t.vx;
    ty = sc->t.vy;
    tz = sc->t.vz;
    __asm__ volatile("");
    k = (m->flags >> 10) & 3;
    switch (k) {
    case 1:
        {
            s32 a, b, c, d, e, f;
            d = p[0].vz; e = p[0].vy; f = p[0].vx;
            a = tx + d; b = ty + e; c = tz - f;
            sc->v[0].vx = a; sc->v[0].vy = b; sc->v[0].vz = c;
            d = p[1].vz; e = p[1].vy; f = p[1].vx;
            a = tx + d; b = ty + e; c = tz - f;
            sc->v[1].vx = a; sc->v[1].vy = b; sc->v[1].vz = c;
            d = p[2].vz; e = p[2].vy; f = p[2].vx;
            __asm__ volatile("");
            i = 0;
            a = tx + d; b = ty + e; c = tz - f;
            sc->v[2].vx = a; sc->v[2].vy = b; sc->v[2].vz = c;
        }
        for (; i < n; i += 3) {
            SV_16294 *r;
            gte_ldv3m_16294(sc->v);
            gte_rtpt_16294();
            q = p + 3;
            sc->v[0].vx = q->vz + tx;
            sc->v[0].vy = q->vy + ty;
            sc->v[0].vz = tz - q->vx;
            r = p + 4;
            sc->v[1].vx = r->vz + tx;
            sc->v[1].vy = r->vy + ty;
            sc->v[1].vz = tz - r->vx;
            r = p + 5;
            sc->v[2].vx = r->vz + tx;
            sc->v[2].vy = r->vy + ty;
            sc->v[2].vz = tz - r->vx;
            gte_stsxyz3_16294(out);
            out += 3;
            p = q;
        }
        break;
    case 2:
        sc->v[0].vx = tx - p[0].vx;
        sc->v[0].vy = p[0].vy + ty;
        sc->v[0].vz = tz - p[0].vz;
        sc->v[1].vx = tx - p[1].vx;
        sc->v[1].vy = p[1].vy + ty;
        sc->v[1].vz = tz - p[1].vz;
        sc->v[2].vx = tx - p[2].vx;
        sc->v[2].vy = p[2].vy + ty;
        sc->v[2].vz = tz - p[2].vz;
        for (i = 0; i < n; i += 3) {
            SV_16294 *r;
            gte_ldv3m_16294(sc->v);
            gte_rtpt_16294();
            q = p + 3;
            sc->v[0].vx = tx - q->vx;
            sc->v[0].vy = q->vy + ty;
            sc->v[0].vz = tz - q->vz;
            r = p + 4;
            sc->v[1].vx = tx - r->vx;
            sc->v[1].vy = r->vy + ty;
            sc->v[1].vz = tz - r->vz;
            r = p + 5;
            sc->v[2].vx = tx - r->vx;
            sc->v[2].vy = r->vy + ty;
            sc->v[2].vz = tz - r->vz;
            gte_stsxyz3_16294(out);
            out += 3;
            p = q;
        }
        break;
    case 3:
        i = 0;
        sc->v[0].vx = tx - p[0].vz;
        sc->v[0].vy = p[0].vy + ty;
        sc->v[0].vz = p[0].vx + tz;
        sc->v[1].vx = tx - p[1].vz;
        sc->v[1].vy = p[1].vy + ty;
        sc->v[1].vz = p[1].vx + tz;
        sc->v[2].vx = tx - p[2].vz;
        sc->v[2].vy = p[2].vy + ty;
        sc->v[2].vz = p[2].vx + tz;
        for (; i < n; i += 3) {
            SV_16294 *r;
            gte_ldv3m_16294(sc->v);
            gte_rtpt_16294();
            q = p + 3;
            sc->v[0].vx = tx - q->vz;
            sc->v[0].vy = q->vy + ty;
            sc->v[0].vz = q->vx + tz;
            r = p + 4;
            sc->v[1].vx = tx - r->vz;
            sc->v[1].vy = r->vy + ty;
            sc->v[1].vz = r->vx + tz;
            r = p + 5;
            sc->v[2].vx = tx - r->vz;
            sc->v[2].vy = r->vy + ty;
            sc->v[2].vz = r->vx + tz;
            gte_stsxyz3_16294(out);
            out += 3;
            p = q;
        }
        break;
    default:
        i = 0;
        {
            XY_16294 a; s32 z, x, y;
            a = *(XY_16294 *)&p[0]; z = p[0].vz; y = a.y; x = a.x;
            sc->v[0].vx = tx + x; sc->v[0].vy = ty + y; sc->v[0].vz = tz + z;
            a = *(XY_16294 *)&p[1]; z = p[1].vz; y = a.y; x = a.x;
            sc->v[1].vx = tx + x; sc->v[1].vy = ty + y; sc->v[1].vz = tz + z;
            a = *(XY_16294 *)&p[2]; z = p[2].vz; y = a.y; x = a.x;
            sc->v[2].vx = tx + x; sc->v[2].vy = ty + y; sc->v[2].vz = tz + z;
        }
        if (i < n) {
            SV_16294 *vv = sc->v;
            q = p;
            do {
                XY_16294 a; s32 z, x, y; SV_16294 *r2;
                gte_ldv3c_16294(vv);
                gte_rtpt_16294();
                r2 = q + 3;
                a = *(XY_16294 *)r2; z = r2->vz; y = a.y; x = a.x;
                sc->v[0].vx = x + tx; sc->v[0].vy = y + ty; sc->v[0].vz = z + tz;
                a = *(XY_16294 *)&q[4]; z = q[4].vz; y = a.y; x = a.x;
                sc->v[1].vx = x + tx; sc->v[1].vy = y + ty; sc->v[1].vz = z + tz;
                a = *(XY_16294 *)&q[5]; z = q[5].vz; y = a.y; x = a.x;
                sc->v[2].vx = x + tx; sc->v[2].vy = y + ty; sc->v[2].vz = z + tz;
                gte_stsxyz3_16294(out);
                out += 3;
                q = r2;
                i += 3;
            } while (i < n);
        }
        break;
    }
}

/* Projects a vertex-animated (morphing) model blended between two key frames (time>>12, fraction &0xFFF) via GTE gpf; per-arm block-local frame index, pinned next-frame/out pointers. Local GTE macros *_PMF. */
typedef struct { u32 flags; u8 pad4[2]; u16 nFrames; u8 pad8[4]; u16 timesOfs; u8 padE[4]; u16 nVerts; } MorphHdr_PMF;
typedef struct { MorphHdr_PMF *hdr; u8 pad4[8]; SVECTOR *frames; u8 pad10[8]; u16 frame; } Morph_PMF;
typedef struct { u32 sxy; s32 sz; } Proj_PMF;
typedef struct { SVECTOR org; SVECTOR v; } Scr_PMF;
#define gte_ldIR0_PMF(r) __asm__ volatile ("mtc2 %0, $8" : : "r"(r))
#define gte_ldIR1_PMF(r) __asm__ volatile ("mtc2 %0, $9" : : "r"(r))
#define gte_ldIR2_PMF(r) __asm__ volatile ("mtc2 %0, $10" : : "r"(r))
#define gte_ldIR3_PMF(r) __asm__ volatile ("mtc2 %0, $11" : : "r"(r))
#define gte_gpf12_PMF() __asm__ volatile ("nop; nop; gpf 1")
#define gte_stMAC1_PMF(r) __asm__ volatile ("mfc2 %0, $25" : "=r"(r))
#define gte_stMAC2_PMF(r) __asm__ volatile ("mfc2 %0, $26" : "=r"(r))
#define gte_stMAC3_PMF(r) __asm__ volatile ("mfc2 %0, $27" : "=r"(r))
#define gte_ldv0_PMF(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_PMF() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_PMF(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stsz_PMF(p) __asm__ volatile ("swc2 $19, 0(%0)" : : "r"(p) : "memory")

void Model_ProjectMorphFrame(Morph_PMF *m, Proj_PMF *out) {
    Scr_PMF *scr = (Scr_PMF *)0x1F8003C8;
    MorphHdr_PMF *h = m->hdr;
    s32 n = h->nVerts;
    SVECTOR *a;
    SVECTOR *bb;
    register Proj_PMF *o asm("$5") = out;
    u32 t; u16 *tt;
    s32 i, c, d, e;

    if (h->flags & 0x2000) {
        t = m->frame;
        {
        s32 f = t >> 12;
        a = &m->frames[f * n];
        if (f == h->nFrames - 1) {
            bb = m->frames;
        } else {
            bb = a + n;
        }
        }
    } else {
        tt = (u16 *)((u8 *)h + h->timesOfs * 4); t = tt[m->frame + 1];
        {
        s32 f = t >> 12;
        a = &m->frames[f * n];
        if (f == h->nFrames - 1) {
            bb = m->frames;
        } else {
            bb = a + n;
        }
        }
    }
    t &= 0xFFF;
    {
    register SVECTOR *b asm("$4") = bb;
    for (i = 0; i < n; i++) {
        c = a[i].vx;
        e = b->vx;
        gte_ldIR0_PMF(t);
        d = e - c;
        scr->v.vx = scr->org.vx + c;
        gte_ldIR1_PMF(d);
        c = a[i].vy;
        e = b->vy;
        d = e - c;
        scr->v.vy = scr->org.vy + c;
        gte_ldIR2_PMF(d);
        c = a[i].vz;
        e = b->vz;
        d = e - c;
        scr->v.vz = scr->org.vz + c;
        gte_ldIR3_PMF(d);
        gte_gpf12_PMF();
        gte_stMAC1_PMF(c);
        gte_stMAC2_PMF(e);
        gte_stMAC3_PMF(d);
        scr->v.vx += c;
        scr->v.vy += e;
        scr->v.vz += d;
        gte_ldv0_PMF(&scr->v);
        gte_rtps_PMF();
        gte_stsxy_PMF(&o->sxy);
        gte_stsz_PMF(&o->sz);
        o++;
        b++;
    }
    }
}

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

typedef struct { u8 pad0[4]; u16 nBones; u16 nVerts; } Hdr_16B98;
typedef struct { u16 count; u16 start; u8 pad4[8]; } Bone_16B98;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_16B98;
typedef struct { Hdr_16B98 *hdr; u8 pad4[8]; Bone_16B98 *bones; SVECTOR *verts; MAT_16B98 *mats; } Mdl_16B98;
typedef struct { u8 pad0[6]; u16 uv; } Out_16B98;
s32 abs(s32);
/* Model_CalcEnvMapUVs64 for a boned model: each bone's normals (stored after the vertices) are
   turned by that bone's matrix before the same 64x64 environment-map UVs are worked out. */
#define m ((Mdl_16B98 *)mv)

M2C_UNK Model_CalcEnvMapUVs(void **mv) {
    Out_16B98 *base = (Out_16B98 *)D_800EA060;
    SVECTOR *nrms = &m->verts[m->hdr->nVerts];
    MAT_16B98 *mats = m->mats;
    s32 b, i, end;
    s32 x, y, z, w, r, hi;
    register s32 u asm("$2");
    register s32 t asm("$3");

    for (b = 0; b < m->hdr->nBones; b++) {
        gte_SetRotMatrix_(&mats[b + 1]);
        gte_SetTransMatrix_(&mats[b + 1]);
        t = m->bones[b].start;
        for (i = t, end = t + m->bones[b].count; i < end; i++) {
            __asm__ volatile("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(&nrms[i]));
            __asm__ volatile("nop; nop; rtv0");
            __asm__ volatile("mfc2 %0, $27" : "=r"(z));
            __asm__ volatile("mfc2 %0, $26" : "=r"(y));
            __asm__ volatile("mfc2 %0, $25" : "=r"(x));
            z = abs(z);
            u = ((z * -(y * 40)) >> 24) + 0x1F;
            __asm__("addu %0,%1,$0" : "=r"(t) : "r"(u));
            r = u;
            if (t >= 0) {
                register s32 c asm("$2") = t < 0x40;
                if (!c) {
                    r = 0x3F;
                }
            } else {
                r = 0;
            }
            w = x * 40; u = ((z * w) >> 24) + 0x1F;
            __asm__("addu %0,%1,$0" : "=r"(t) : "r"(u));
            if (t >= 0) {
                register s32 c asm("$2");
                hi = r;
                r = u;
                c = t < 0x40;
                if (!c) {
                    r = 0x3F;
                }
            } else {
                hi = r;
                r = 0;
            }
            base[i].uv = r | (hi << 8);
        }
    }
}
#undef m

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

typedef struct { u32 flags; u16 nFrames; u8 pad6[6]; u16 timesOfs; u16 nColors; } CHdr_17EFC;
typedef struct { CHdr_17EFC *hdr; u32 *colors; u8 *prims; u8 padC[0xC]; u16 frame; } CMdl_17EFC;
typedef struct { u32 rgb[0xF0]; u16 f_3C0; u16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_17EFC;
extern struct { u8 pad0[0x1C]; u8 f_1C; u8 f_1D; u8 f_1E; u8 pad1F[5]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0_17EFC asm("D_800EBFA0");
#define gte_ldFCR_17EFC(r) __asm__ volatile ("ctc2 %0, $21" : : "r"(r))
#define gte_ldFCG_17EFC(r) __asm__ volatile ("ctc2 %0, $22" : : "r"(r))
#define gte_ldFCB_17EFC(r) __asm__ volatile ("ctc2 %0, $23" : : "r"(r))
#define gte_ldRGBw_17EFC(p) __asm__ volatile ("lw $15, 0(%0); nop; mtc2 $15, $6" : : "r"(p) : "$15")
#define gte_dpcs_17EFC(t) __asm__ volatile ("nop; mtc2 %0, $8; nop; nop; dpcs" : : "r"(t))

void func_80017EFC(s32 ot, s32 arg, CMdl_17EFC *m, s32 mode) {
    u8 *prims = m->prims;
    CHdr_17EFC *h = m->hdr;
    Scr_17EFC *sc = (Scr_17EFC *)0x1F800000;
    u32 *a, *b, *src, *out;
    u16 *times;
    u32 t, c, fr, fg, fb;
    s32 f, i, n;
    u32 idx;

    sc->f_3F4 = mode;
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    if (h->flags & 0x100000) {
        times = (u16 *)((u8 *)h + h->timesOfs * 4);
        idx = m->frame;
        if (h->flags & 0x2000) {
            t = idx;
        } else {
            t = times[idx + 1];
        }
        f = t >> 12;
        a = &m->colors[f * h->nColors];
        if (f == h->nFrames - 1) {
            b = m->colors;
        } else {
            b = a + h->nColors;
        }
        t &= 0xFFF;
        __asm__("" : : "r"(t));
        for (i = 0; i < h->nColors; i++) {
            c = *b;
            gte_ldRGBw_17EFC(a);
            fr = (c << 4) & 0xFF0;
            gte_ldFCR_17EFC(fr);
            fr = (c >> 4) & 0xFF0;
            gte_ldFCG_17EFC(fr);
            fr = (c >> 12) & 0xFF0;
            gte_ldFCB_17EFC(fr);
            gte_dpcs_17EFC(t);
            a++; b++;
            gte_stRGB2(&sc->rgb[i]);
        }
        gte_ldFCR_17EFC(D_800EBFA0_17EFC.f_1C);
        gte_ldFCG_17EFC(D_800EBFA0_17EFC.f_1D);
        gte_ldFCB_17EFC(D_800EBFA0_17EFC.f_1E);
    } else {
        n = h->nColors;
        src = m->colors;
        for (i = 0; i < n; i++) {
            { register s32 one asm("$15") = 0x1000; gte_ldIR(one, 0, 0); }
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2(&sc->rgb[i]);
        }
    }
    Model_DrawPrims(ot, prims, arg);
}

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

extern u8 *D_800EC354_Model_AddG4 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddG4;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u8 pad3C4[4]; union { u32 w; u8 c[4]; } cidx; union { u32 w; struct { s16 x, y; } s; } sxy[4]; s32 otz; s32 opz; s32 opz2; union { u32 w; u8 b[4]; } hdr; u32 idx01; u32 idx23; u8 flags; u8 fog; } MdlScratch_Model_AddG4;
/* Model Gouraud quads (code 0x38 run). Each quad is tested as two triangles (nclip of v0-v1-v2 and
   of v1-v2-v3): both facing gives a POLY_G4, one facing gives that half as a POLY_G3, neither is
   culled. Past the fog start each vertex colour is depth-cued (dpcs) by its own depth. */
#define DPCS_G4(r, k) { s32 z; __asm__ volatile("mfc2 %0, $" #r : "=r"(z)); __asm__ volatile("lwc2 $6, %1; nop; mtc2 %0, $8; nop; nop; dpcs" : : "r"(z), "m"(*(MS->color + (k)))); }

u8 *Model_AddG4(s32 otArg, u8 *primArg, s32 vtxArg)
{
    register u8 *prim asm("$5") = primArg;
    u32 *ot = (u32 *)otArg;
    ScrVtx_Model_AddG4 *vtx = (ScrVtx_Model_AddG4 *)vtxArg;
    register MdlScratch_Model_AddG4 *MS asm("$10");
    u8 *p;
    u32 a, b, c, d;
    u32 *o;
    s32 J;

    __asm__("" : "=r"(MS) : "0"(0x1F800000));
    p = D_800EC354_Model_AddG4;
    do {
        {
        register u32 w0 asm("$3"), w1 asm("$4");
        w0 = *(u32 *)(prim + 4);
        w1 = *(u32 *)(prim + 8);
        a = w0 & 0xFFFF;
        b = w0 >> 16;
        MS->idx01 = w0;
        __asm__ volatile("");
        c = w1 & 0xFFFF;
        a = vtx[a].sxy;
        b = vtx[b].sxy;
        __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13" : : "r"(a), "r"(b));
        MS->idx23 = w1;
        __asm__ volatile("");
        d = w1 >> 16;
        c = vtx[c].sxy;
        d = vtx[d].sxy;
        __asm__("" : : "r"(a), "r"(a));
        }
        MS->sxy[0].w = a;
        MS->sxy[1].w = b;
        __asm__ volatile("mtc2 %0, $14" : : "r"(c));
        MS->sxy[2].w = c;
        MS->sxy[3].w = d;
        __asm__ volatile("nclip");
        {
            register s32 mn asm("$8"), mx asm("$9"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.x;
            mx = MS->sxy[1].s.x;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.x;
            }
            x = MS->sxy[2].s.x;
            y = MS->sxy[3].s.x;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.x;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0x181) goto skip;
        }
        __asm__ volatile("swc2 $24, %0" : "=m"(MS->opz));
        __asm__ volatile("lwc2 $12, %0" : : "m"(MS->sxy[3]));
        __asm__ volatile("nop; nop; nclip");
        {
            register s32 mn asm("$8"), mx asm("$9"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.y;
            mx = MS->sxy[1].s.y;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.y;
            }
            x = MS->sxy[2].s.y;
            y = MS->sxy[3].s.y;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.y;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0xF1) goto skip;
        }
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz2) : "memory");
        {
            s32 j0;
            J = (s16)((volatile u16 *)&MS->idx01)[1];
            j0 = (s16)((volatile u16 *)&MS->idx01)[0];
            __asm__ volatile("lwc2 $16, %0" : : "m"(vtx[j0].sz));
            __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[J].sz));
        }
        {
            s32 j2;
            J = (s16)((volatile u16 *)&MS->idx23)[1];
            j2 = (s16)((volatile u16 *)&MS->idx23)[0];
            __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j2].sz));
            __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[J].sz));
        }
        __asm__ volatile("nop; nop; avsz4");
        __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
        if (MS->otz < 0x1B) {
            goto skip;
        }
        {
            s32 n, z0, z1, z2, z3;
            __asm__("" : : "r"(J));
            n = MS->fogNear << 2;
            __asm__ volatile("mfc2 %0, $16; mfc2 %1, $17; mfc2 %2, $18; mfc2 %3, $19" : "=r"(z0), "=r"(z1), "=r"(z2), "=r"(z3));
            z0 = (z0 - n) << 2;
            z1 = (z1 - n) << 2;
            z2 = (z2 - n) << 2;
            z3 = (z3 - n) << 2;
            if (z0 < 0) z0 = 0;
            __asm__ volatile("mtc2 %0, $16" : : "r"(z0));
            if (z1 < 0) z1 = 0;
            __asm__ volatile("mtc2 %0, $17" : : "r"(z1));
            if (z2 < 0) z2 = 0;
            __asm__ volatile("mtc2 %0, $18" : : "r"(z2));
            if (z3 < 0) z3 = 0;
            __asm__ volatile("mtc2 %0, $19" : : "r"(z3));
            if ((z0 == 0 && z1 == 0 && z2 == 0 && z3 == 0)
                || (z0 >= 0x1001 && z1 >= 0x1001 && z2 >= 0x1001 && z3 >= 0x1001)
                || (MS->flags & 1)) {
                MS->fog = 0;
            } else {
                MS->fog = 1;
            }
        }
        if (!(MS->flags & 1) && MS->fogNear < MS->otz && !MS->fog) {
            goto skip;
        }
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        MS->hdr.w = *(u32 *)prim;
        if (!(MS->flags & 4) && MS->fogNear < MS->otz) {
            MS->hdr.b[3] |= 2;
            MS->hdr.b[2] &= 0x60;
        }
        switch (((MS->opz >> 31) & 2) | (MS->opz2 > 0)) {
        case 0:
            MS->cidx.w = *(u32 *)(prim + 12);
            __asm__("" : "=r"(o) : "0"(ot));
            if (!(MS->flags & 1)) o = ot + MS->otz;
            ADD_PRIM_R(o, p, "$3", "$2");
            if (MS->hdr.b[3] & 2) {
                *(u32 *)(p + 4) = ((MS->hdr.b[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 9;
                p += 4;
            } else {
                p[3] = 8;
            }
            if (MS->fog) {
                {
                u32 k;
                k = MS->cidx.c[0];
                DPCS_G4(16, k);
                k = MS->cidx.c[1];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                DPCS_G4(17, k);
                k = MS->cidx.c[2];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 12)));
                DPCS_G4(18, k);
                k = MS->cidx.c[3];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 20)));
                DPCS_G4(19, k);
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                }
            } else {
                { u32 k0 = MS->cidx.c[0]; J = MS->cidx.c[1];
                __asm__ volatile("lwc2 $20, %0" : : "m"(*(MS->color + k0)));
                __asm__ volatile("lwc2 $21, %0" : : "m"(*(MS->color + J))); }
                { u32 k2 = MS->cidx.c[2]; __asm__ volatile(""); J = MS->cidx.c[3];
                __asm__ volatile("swc2 $20, %0" : "=m"(*(u32 *)(p + 4)));
                __asm__ volatile("swc2 $21, %0" : "=m"(*(u32 *)(p + 12)));
                __asm__ volatile("lwc2 $20, %0" : : "m"(*(MS->color + k2)));
                __asm__ volatile("lwc2 $21, %0" : : "m"(*(MS->color + J))); }
                __asm__ volatile("nop; swc2 $20, %0; swc2 $21, %1" : "=m"(*(u32 *)(p + 20)), "=m"(*(u32 *)(p + 28)));
            }
            *(u32 *)(p + 8) = MS->sxy[0].w;
            p[7] = MS->hdr.b[3];
            prim += 0x10;
            __asm__ volatile("swc2 $12, 32(%0); swc2 $13, 16(%0); swc2 $14, 24(%0)" : : "r"(p) : "memory");
            p += 0x24;
            break;
        case 1:
            MS->cidx.w = *(u32 *)(prim + 12);
            __asm__("" : "=r"(o) : "0"(ot));
            if (!(MS->flags & 1)) o = ot + MS->otz;
            ADD_PRIM_R(o, p, "$3", "$2");
            if (MS->hdr.b[3] & 2) {
                *(u32 *)(p + 4) = ((MS->hdr.b[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 7;
                p += 4;
            } else {
                p[3] = 6;
            }
            if (MS->fog) {
                {
                u32 k;
                k = MS->cidx.c[0];
                DPCS_G4(16, k);
                k = MS->cidx.c[1];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                DPCS_G4(17, k);
                k = MS->cidx.c[2];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 12)));
                DPCS_G4(18, k);
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 20)));
                }
            } else {
                { u32 k0 = MS->cidx.c[0], k1 = MS->cidx.c[1], k2 = MS->cidx.c[2];
                __asm__ volatile("lwc2 $20, %0" : : "m"(*(MS->color + k0)));
                __asm__ volatile("lwc2 $21, %0" : : "m"(*(MS->color + k1)));
                __asm__ volatile("lwc2 $22, %0" : : "m"(*(MS->color + k2))); }
                __asm__ volatile("nop; swc2 $20, %0" : "=m"(*(u32 *)(p + 4)));
                __asm__ volatile("swc2 $21, %0" : "=m"(*(u32 *)(p + 12)));
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 20)));
            }
            *(u32 *)(p + 8) = MS->sxy[0].w;
            prim += 0x10;
            __asm__ volatile("swc2 $13, %0" : "=m"(*(u32 *)(p + 16)));
            __asm__ volatile("swc2 $14, %0" : "=m"(*(u32 *)(p + 24)));
            goto tri;
        case 2:
            o = ot;
            MS->cidx.w = *(u32 *)(prim + 12);
            if (!(MS->flags & 1)) o += MS->otz;
            ADD_PRIM_R(o, p, "$3", "$2");
            if (MS->hdr.b[3] & 2) {
                *(u32 *)(p + 4) = ((MS->hdr.b[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 7;
                p += 4;
            } else {
                p[3] = 6;
            }
            if (MS->fog) {
                {
                u32 k;
                k = MS->cidx.c[1];
                DPCS_G4(16, k);
                k = MS->cidx.c[2];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                DPCS_G4(17, k);
                k = MS->cidx.c[3];
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 12)));
                DPCS_G4(18, k);
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 20)));
                }
                prim += 0x10;
            } else {
                { u32 k0 = MS->cidx.c[1], k1 = MS->cidx.c[2], k2 = MS->cidx.c[3];
                __asm__ volatile("lwc2 $20, %0" : : "m"(*(MS->color + k0)));
                __asm__ volatile("lwc2 $21, %0" : : "m"(*(MS->color + k1)));
                __asm__ volatile("lwc2 $22, %0" : : "m"(*(MS->color + k2))); }
                __asm__ volatile("nop; swc2 $20, %0" : "=m"(*(u32 *)(p + 4)));
                __asm__ volatile("swc2 $21, %0" : "=m"(*(u32 *)(p + 12)));
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 20)));
                prim += 0x10;
            }
            __asm__ volatile("swc2 $12, %0" : "=m"(*(u32 *)(p + 24)));
            __asm__ volatile("swc2 $13, %0" : "=m"(*(u32 *)(p + 8)));
            __asm__ volatile("swc2 $14, %0" : "=m"(*(u32 *)(p + 16)));
        tri:
            p[7] = MS->hdr.b[3] ^ 8;
            p += 0x1C;
            break;
        case 3:
        skip:
            prim += 0x10;
        }
    } while ((prim[3] & 0xFC) == 0x38);
    D_800EC354_Model_AddG4 = p;
    return prim;
}

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

extern u8 *D_800EC354_Model_AddF4 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddF4;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u8 pad3C4[4]; union { u32 w; u8 c[4]; } cidx; union { u32 w; struct { s16 x, y; } s; } sxy[4]; s32 otz; s32 opz; s32 opz2; union { u32 w; u8 b[4]; } hdr; u32 idx01; u32 idx23; u8 flags; } MdlScratch_Model_AddF4;

/* Model flat quads (code 0x28 run). Each quad is tested as two triangles (nclip of v0-v1-v2 and
   of v1-v2-v3): both facing gives a POLY_F4, one facing gives that half as a POLY_F3, neither is
   culled. Otherwise as Model_AddF3. Returns the next run. */
u8 *Model_AddF4(s32 otArg, u8 *prim, s32 vtxArg)
{
    u32 *ot = (u32 *)otArg;
    ScrVtx_Model_AddF4 *vtx = (ScrVtx_Model_AddF4 *)vtxArg;
    register MdlScratch_Model_AddF4 *MS asm("$10");
    u8 *p;
    u32 w0, w1, a, b, c, d;
    u32 *o;
    s32 f;
    s32 i0;
    s32 J;

    __asm__("" : "=r"(MS) : "0"(0x1F800000));
    p = D_800EC354_Model_AddF4;
    do {
        {
        register u32 w0 asm("$3"), w1 asm("$4");
        w0 = *(u32 *)(prim + 4);
        w1 = *(u32 *)(prim + 8);
        a = w0 & 0xFFFF;
        b = w0 >> 16;
        MS->idx01 = w0;
        __asm__ volatile("");
        c = w1 & 0xFFFF;
        a = vtx[a].sxy;
        b = vtx[b].sxy;
        __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13" : : "r"(a), "r"(b));
        MS->idx23 = w1;
        __asm__ volatile("");
        d = w1 >> 16;
        c = vtx[c].sxy;
        d = vtx[d].sxy;
        __asm__("" : : "r"(a), "r"(a), "m"(prim[3]), "m"(prim[3]), "m"(prim[3]), "m"(prim[3]), "m"(prim[3]));
        }
        MS->sxy[0].w = a;
        MS->sxy[1].w = b;
        __asm__ volatile("mtc2 %0, $14" : : "r"(c));
        MS->sxy[2].w = c;
        MS->sxy[3].w = d;
        __asm__ volatile("nclip");
        {
            register s32 mn asm("$8"), mx asm("$9"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.x;
            mx = MS->sxy[1].s.x;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.x;
            }
            x = MS->sxy[2].s.x;
            y = MS->sxy[3].s.x;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.x;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0x181) goto skip;
        }
        {
            register s32 mn asm("$8"), mx asm("$9"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.y;
            mx = MS->sxy[1].s.y;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.y;
            }
            x = MS->sxy[2].s.y;
            y = MS->sxy[3].s.y;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.y;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0xF1) goto skip;
        }
        __asm__ volatile("swc2 $24, %0" : "=m"(MS->opz), "=r"(J));
        __asm__ volatile("lwc2 $12, %0" : : "m"(MS->sxy[3]));
        __asm__ volatile("nop; nop; nclip");
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz2) : "memory");
        {
            s32 j0;
            J = (s16)((volatile u16 *)&MS->idx01)[1];
            j0 = (s16)((volatile u16 *)&MS->idx01)[0];
            __asm__ volatile("lwc2 $16, %0" : : "m"(vtx[j0].sz));
            __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[J].sz));
        }
        {
            s32 j2;
            J = (s16)((volatile u16 *)&MS->idx23)[1];
            j2 = (s16)((volatile u16 *)&MS->idx23)[0];
            __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j2].sz));
            __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[J].sz));
        }
        __asm__ volatile("nop; nop; avsz4");
        __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
        if (MS->otz < 0x1B) {
            goto skip;
        }
        if (!(MS->flags & 1) && MS->otz - MS->fogNear > 0x100) {
            goto skip;
        }
        __asm__ volatile("" ::: "memory");
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        switch (((MS->opz >> 31) & 2) | (MS->opz2 > 0)) {
        case 0:
            if (MS->flags & 1) o = ot; else o = &ot[MS->otz];
            ADD_PRIM_R(o, p, "$3", "$2");
            if (prim[3] & 2) {
                *(u32 *)(p + 4) = ((prim[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 6;
                p += 4;
            } else {
                p[3] = 5;
            }
            i0 = (MS->otz - MS->fogNear) * MS->fogScale;
            MS->cidx.w = *(u32 *)(prim + 12);
            MS->otz = i0 >> 12;
            if (MS->otz >= 0) {
                if (MS->otz > 0x1000) f = 0x1000;
                else f = MS->otz;
            } else {
                f = 0;
            }
            MS->otz = f;
            __asm__ volatile("lwc2 $6, %0" : : "m"(MS->color[MS->cidx.c[0]]));
            __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpcs" : : "r"(f));
            __asm__ volatile("swc2 $22, 0(%0)" : : "r"(p + 4) : "memory");
            *(u32 *)(p + 8) = MS->sxy[0].w;
            __asm__ volatile("swc2 $12, 20(%0); swc2 $13, 12(%0); swc2 $14, 16(%0)" : : "r"(p) : "memory");
            p[7] = prim[3];
            p += 0x18;
            prim += 0x10;
            break;
        case 1:
            if (MS->flags & 1) o = ot; else o = &ot[MS->otz];
            ADD_PRIM_R(o, p, "$3", "$2");
            if (MS->hdr.b[3] & 2) {
                *(u32 *)(p + 4) = ((MS->hdr.b[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 5;
                p += 4;
            } else {
                p[3] = 4;
            }
            i0 = (MS->otz - MS->fogNear) * MS->fogScale;
            MS->cidx.w = *(u32 *)(prim + 12);
            MS->otz = i0 >> 12;
            if (MS->otz >= 0) {
                if (MS->otz > 0x1000) f = 0x1000;
                else f = MS->otz;
            } else {
                f = 0;
            }
            MS->otz = f;
            __asm__ volatile("lwc2 $6, %0" : : "m"(MS->color[MS->cidx.c[0]]));
            __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpcs" : : "r"(f));
            {
                u32 t = MS->sxy[0].w;
                __asm__ volatile("swc2 $13, %0; swc2 $14, %1" : "=m"(*(u32 *)(p + 12)), "=m"(*(u32 *)(p + 16)));
                *(u32 *)(p + 8) = t;
            }
            __asm__ volatile("swc2 $22, 0(%0)" : : "r"(p + 4) : "memory");
            p[7] = 0x20;
            goto tri;
        case 2:
            o = ot;
            if (!(MS->flags & 1)) {
                o += MS->otz;
            }
            ADD_PRIM_R(o, p, "$3", "$2");
            if (MS->hdr.b[3] & 2) {
                *(u32 *)(p + 4) = ((MS->hdr.b[2] << 2) & 0x9FF) | 0xE1000200;
                p[3] = 5;
                p += 4;
            } else {
                p[3] = 4;
            }
            i0 = (MS->otz - MS->fogNear) * MS->fogScale;
            MS->cidx.w = *(u32 *)(prim + 12);
            MS->otz = i0 >> 12;
            if (MS->otz >= 0) {
                if (MS->otz > 0x1000) f = 0x1000;
                else f = MS->otz;
            } else {
                f = 0;
            }
            MS->otz = f;
            __asm__ volatile("lwc2 $6, %0" : : "m"(MS->color[MS->cidx.c[0]]));
            __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpcs" : : "r"(f));
            __asm__ volatile("swc2 $12, %0; swc2 $13, %1; swc2 $14, %2" : "=m"(*(u32 *)(p + 16)), "=m"(*(u32 *)(p + 8)), "=m"(*(u32 *)(p + 12)));
            __asm__ volatile("swc2 $22, 0(%0)" : : "r"(p + 4) : "memory");
            p[7] = 0x20;
        tri:
            p += 0x14;
        case 3:
        skip:
            prim += 0x10;
        }
    } while ((prim[3] & 0xFC) == 0x28);
    D_800EC354_Model_AddF4 = p;
    return prim;
}

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

extern u8 *D_800EC354_Model_AddGT3 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddGT3;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u16 clut; u8 pad3C6[2]; u8 cidx[4]; union { u32 w; struct { s16 x, y; } s; } sxy[3]; u8 pad3D8[4]; s32 otz; s32 opz; u8 pad3E4[4]; union { u32 w; u8 b[4]; } hdr; union { u32 w; u16 h[2]; } idx01; union { u32 w; u16 h[2]; } idx2; u8 flags; u8 mode; u16 tpage; } MdlScratch_Model_AddGT3;

/* Model Gouraud textured triangles (code 0x34 run): POLY_GT3s, past the fog start depth-cued per
   vertex and, for semi-transparent ones, with a second white-fogged POLY_G3 on top (as
   Model_AddFT3). Returns the next run. */
u8 *Model_AddGT3(s32 otArg, u8 *primArg, s32 vtxArg)
{
    u32 *ot = (u32 *)otArg;
    u8 *prim = primArg;
    register ScrVtx_Model_AddGT3 *vtx asm("$12") = (ScrVtx_Model_AddGT3 *)vtxArg;
    register MdlScratch_Model_AddGT3 *MS asm("$7");
    u8 *p;
    u32 w0, w1, a, b, c;
    u32 *o;

    __asm__("" : "=r"(MS) : "0"(0x1F800000));
    p = D_800EC354_Model_AddGT3;
    do {
        __asm__("" :: "r"(prim), "r"(prim), "r"(prim), "r"(prim), "r"(prim));
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
            register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$6"); s32 lo;
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
            register s32 x0 asm("$4"); s32 x1, x2; register s32 hi asm("$6"); s32 lo;
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
            {
                u32 h = *(u32 *)prim;
                u16 tp = *(u16 *)(prim + 0x12);
                fn = MS->fogNear << 2;
                MS->hdr.w = h;
                MS->tpage = tp;
            }
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
        *(u32 *)MS->cidx = *(u32 *)(prim + 0x18);
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        if (MS->mode != 0) {
            if (!(MS->flags & 4)) {
                u8 h = MS->hdr.b[3];
                if (!(h & 2)) {
                    MS->hdr.b[3] = h | 2;
                    if (MS->hdr.b[2] != 0) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                    else MS->tpage = MS->tpage & 0xFF9F;
                }
            }
            {
                u32 c0, z, t;
                c0 = MS->cidx[0];
                __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                t = MS->sxy[0].w;
                __asm__ volatile("nop; nop; dpcs");
                c0 = MS->cidx[1];
                *(u32 *)(p + 8) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                t = MS->sxy[1].w;
                __asm__ volatile("nop; nop; dpcs");
                c0 = MS->cidx[2];
                p[3] = 9;
                *(u32 *)(p + 20) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                t = MS->sxy[2].w;
                __asm__ volatile("nop; nop; dpcs");
                p[7] = MS->hdr.b[3];
                *(u32 *)(p + 32) = t;
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
            }
            {
                u32 uv0, uv1; u16 uv2;
                uv0 = *(u32 *)(prim + 12); uv0 += MS->clut << 16;
                uv1 = *(u16 *)(prim + 16) | (MS->tpage << 16);
                uv2 = *(u16 *)(prim + 20);
                *(u32 *)(p + 12) = uv0;
                *(u32 *)(p + 24) = uv1;
                *(u16 *)(p + 36) = uv2;
            }
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
                p[3] = 7;
                *(u32 *)(p + 4) = 0xE1000240;
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
            __asm__ volatile("swc2 $12, %0; swc2 $13, %1; swc2 $14, %2" : "=m"(*(u32 *)(p + 8)), "=m"(*(u32 *)(p + 20)), "=m"(*(u32 *)(p + 32)));
            {
                u32 c0, c1, c2, v1, v2;
                c0 = MS->cidx[0];
                c1 = MS->cidx[1];
                c2 = MS->cidx[2];
                *(u32 *)(p + 4) = *(MS->color + c0);
                v2 = *(MS->color + c2);
                v1 = *(MS->color + c1);
                p[3] = 9;
                *(u32 *)(p + 16) = v1;
                *(u32 *)(p + 28) = v2;
            }
            p[7] = MS->hdr.b[3];
            {
                u32 uv0, uv1; u16 uv2;
                uv0 = *(u32 *)(prim + 12); uv0 += MS->clut << 16;
                uv1 = *(u16 *)(prim + 16) | (MS->tpage << 16);
                uv2 = *(u16 *)(prim + 20);
                *(u32 *)(p + 12) = uv0;
                *(u32 *)(p + 24) = uv1;
                *(u16 *)(p + 36) = uv2;
            }
            o = ot;
            if (!(MS->flags & 1)) {
                o += MS->otz;
            }
            ADD_PRIM_R(o, p, "$3", "$2");
            p += 0x28;
        }
        prim += 0x1C;
    } while ((prim[3] & 0xFC) == 0x34);
    D_800EC354_Model_AddGT3 = p;
    return prim;
}

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


extern u8 *D_800EC354_Model_AddFT4 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddFT4;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u16 clut; u8 pad3C6[2]; union { u32 w; u8 c[4]; } cidx; union { u32 w; struct { s16 x, y; } s; } sxy[4]; s32 otz; s32 opz; s32 opz2; union { u32 w; u8 b[4]; } hdr; u32 idx01; u32 idx23; u8 flags; u8 mode; u16 tpage; } MdlScratch_Model_AddFT4;
typedef struct { u32 sxy0; u16 z0; u16 pad0; u32 sxy1; u16 z1; u16 pad1; u32 sxy2; u16 z2; u16 pad2; u32 sxy3; u16 z3; u16 pad3; u32 color; u32 uv0; u32 uv1; u32 uv23; u8 code; } SubQuad_Model_AddFT4;
u8 *Model_SubdivideFT4(u32 *, u8 *, SubQuad_Model_AddFT4 *, s32);

/* Model flat textured quads (code 0x2C run). Each quad is tested as two triangles (nclip of v0-v1-v2 and
   of v3-v1-v2): both facing gives a quad - depth-cued POLY_GT4 (+ white-fogged POLY_G4 for
   semi-transparent ones) past the fog start, else a POLY_FT4, or, when big on screen (area >= 5000)
   and opaque, it is copied to the scratch pad at 0x1F800280 and handed to the subdivider
   Model_SubdivideFT4 (1 or 2 levels). One facing half gives that half as a GT3/FT3. Returns the next run. */
u8 *Model_AddFT4(s32 otArg, u8 *primArg, s32 vtxArg)
{
    register u32 *ot asm("$20") = (u32 *)otArg;
    u8 *prim = primArg;
    register ScrVtx_Model_AddFT4 *vtx asm("$21") = (ScrVtx_Model_AddFT4 *)vtxArg;
    register MdlScratch_Model_AddFT4 *MS asm("$16") = (MdlScratch_Model_AddFT4 *)0x1F800000;
    u8 *p;
    u32 *o;
    s32 J;

    p = D_800EC354_Model_AddFT4;
    {
    register s32 nine asm("$22") = 9;
    register SubQuad_Model_AddFT4 *SQ asm("$19") = (SubQuad_Model_AddFT4 *)0x1F800280;
    register s32 seven asm("$23") = 7;
    do {
        {
        register u32 w0 asm("$3"), w1 asm("$4"); u32 a, b, c, d;
        w0 = *(u32 *)(prim + 4);
        w1 = *(u32 *)(prim + 8);
        a = w0 & 0xFFFF;
        b = w0 >> 16;
        MS->idx01 = w0;
        __asm__ volatile("");
        c = w1 & 0xFFFF;
        a = vtx[a].sxy;
        b = vtx[b].sxy;
        __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13" : : "r"(a), "r"(b));
        MS->idx23 = w1;
        __asm__ volatile("");
        d = w1 >> 16;
        c = vtx[c].sxy;
        d = vtx[d].sxy;
        MS->sxy[0].w = a;
        MS->sxy[1].w = b;
        __asm__ volatile("mtc2 %0, $14" : : "r"(c));
        MS->sxy[2].w = c;
        MS->sxy[3].w = d;
        }
        __asm__ volatile("nclip");
        {
            register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.x;
            mx = MS->sxy[1].s.x;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.x;
            }
            x = MS->sxy[2].s.x;
            y = MS->sxy[3].s.x;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.x;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0x181) goto skip;
        }
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz) : "memory");
        __asm__ volatile("lwc2 $12, 0(%0)" : : "r"(&MS->sxy[3]));
        __asm__ volatile("nop; nop; nclip");
        {
            register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.y;
            mx = MS->sxy[1].s.y;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.y;
            }
            x = MS->sxy[2].s.y;
            y = MS->sxy[3].s.y;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.y;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0xF1) goto skip;
        }
        {
            u32 h = *(u32 *)prim;
            u16 t = *(u16 *)(prim + 0x12);
            MS->hdr.w = h;
            MS->tpage = t;
        }
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz2) : "memory");
        {
            s32 j0;
            J = (s16)((volatile u16 *)&MS->idx01)[1];
            j0 = (s16)((volatile u16 *)&MS->idx01)[0];
            __asm__ volatile("lwc2 $16, %0" : : "m"(vtx[j0].sz));
            __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[J].sz));
        }
        {
            s32 j2;
            J = (s16)((volatile u16 *)&MS->idx23)[1];
            j2 = (s16)((volatile u16 *)&MS->idx23)[0];
            __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j2].sz));
            __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[J].sz));
        }
        __asm__ volatile("nop; nop; avsz4");
        __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
        if (MS->otz < 0x1B) {
            goto skip;
        }
        {
            s32 n, z0, z1, z2, z3;
            n = MS->fogNear << 2;
            __asm__ volatile("mfc2 %0, $16; mfc2 %1, $17; mfc2 %2, $18; mfc2 %3, $19" : "=r"(z0), "=r"(z1), "=r"(z2), "=r"(z3));
            z0 = (z0 - n) << 2;
            z1 = (z1 - n) << 2;
            z2 = (z2 - n) << 2;
            z3 = (z3 - n) << 2;
            if (z0 < 0) z0 = 0;
            __asm__ volatile("mtc2 %0, $16" : : "r"(z0));
            if (z1 < 0) z1 = 0;
            __asm__ volatile("mtc2 %0, $17" : : "r"(z1));
            if (z2 < 0) z2 = 0;
            __asm__ volatile("mtc2 %0, $18" : : "r"(z2));
            if (z3 < 0) z3 = 0;
            __asm__ volatile("mtc2 %0, $19" : : "r"(z3));
            if ((z0 == 0 && z1 == 0 && z2 == 0 && z3 == 0)
                || (z0 >= 0x1001 && z1 >= 0x1001 && z2 >= 0x1001 && z3 >= 0x1001)
                || (MS->flags & 1)) {
                MS->mode = 0;
            } else {
                MS->mode = ((MS->flags & 4) || (MS->hdr.b[3] & 2) || MS->hdr.b[2] == 0) ? 1 : 3;
            }
        }
        if (!(MS->flags & 1) && MS->fogNear < MS->otz && MS->mode == 0) {
            goto skip;
        }
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        if (MS->opz > 0) {
            if (MS->opz2 < 0) {
                /* both halves face the camera: a quad */
                if (MS->mode != 0) {
                    if (!(MS->flags & 4)) {
                        u8 h = MS->hdr.b[3];
                        if (!(h & 2)) {
                            MS->hdr.b[3] = h | 2;
                            if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                            else MS->tpage = MS->tpage & 0xFF9F;
                        }
                    }
                    MS->cidx.w = *(u32 *)(prim + 0x18);
                    {
                        u32 c0, z;
                        c0 = MS->cidx.c[0];
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("swc2 $12, %0" : "=m"(*(u32 *)(p + 44)));
                        __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("swc2 $13, %0" : "=m"(*(u32 *)(p + 20)));
                        __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                        __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                        __asm__ volatile("swc2 $14, %0" : "=m"(*(u32 *)(p + 32)));
                        __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 40)));
                    }
                    *(u32 *)(p + 8) = MS->sxy[0].w;
                    *(u32 *)(p + 12) = *(u32 *)(prim + 12) + (MS->clut << 16);
                    *(u32 *)(p + 24) = *(u16 *)(prim + 16) | (MS->tpage << 16);
                    *(u16 *)(p + 36) = *(u16 *)(prim + 20);
                    *(u16 *)(p + 48) = *(u16 *)(prim + 22);
                    p[3] = 12;
                    p[7] = MS->hdr.b[3] | 0x10;
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
                    p += 0x34;
                    if (!(MS->mode & 2)) goto skip;
                    {
                        u32 z;
                        s32 white = -1;
                        __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[0].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 12) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[1].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 4) = 0xE1000240;
                        p[3] = nine;
                        p[11] = 0x3A;
                        *(u32 *)(p + 20) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[2].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 28) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
                        __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[3].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 36) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 32)));
                    }
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
                    p += 0x28;
                } else if (MS->opz - MS->opz2 < 5000 || (MS->hdr.b[3] & 2) || (MS->flags & 2)) {
                    *(u32 *)(p + 4) = *(MS->color + prim[0x18]);
                    *(u32 *)(p + 8) = MS->sxy[0].w;
                    __asm__ volatile("swc2 $12, %0; swc2 $13, %1; swc2 $14, %2" : "=m"(*(u32 *)(p + 32)), "=m"(*(u32 *)(p + 16)), "=m"(*(u32 *)(p + 24)));
                    *(u32 *)(p + 12) = *(u32 *)(prim + 12) + (MS->clut << 16);
                    *(u32 *)(p + 20) = *(u16 *)(prim + 16) | (MS->tpage << 16);
                    *(u16 *)(p + 28) = *(u16 *)(prim + 20);
                    *(u16 *)(p + 36) = *(u16 *)(prim + 22);
                    p[3] = nine;
                    p[7] = MS->hdr.b[3];
                    o = ot;
                    if (!(MS->flags & 1)) {
                        o = ot + MS->otz;
                    }
                    ADD_PRIM_R(o, p, "$3", "$2");
                    p += 0x28;
                } else {
                    /* big and near: subdivide */
                    s32 n = 1;
                    __asm__ volatile("" : : "r"(n));
                    {
                        s32 j; u32 z; u32 s2, s3, s0_, s1_;
                        j = (s16)((volatile u16 *)&MS->idx23)[0];
                        z = *(u16 *)&vtx[j].sz;
                        j = (s16)((volatile u16 *)&MS->idx23)[1];
                        SQ->z2 = z;
                        z = *(u16 *)&vtx[j].sz;
                        j = (s16)((volatile u16 *)&MS->idx01)[0];
                        SQ->z3 = z;
                        z = *(u16 *)&vtx[j].sz;
                        j = (s16)((volatile u16 *)&MS->idx01)[1];
                        SQ->z0 = z;
                        s2 = MS->sxy[2].w;
                        s3 = MS->sxy[3].w;
                        s0_ = MS->sxy[0].w;
                        s1_ = MS->sxy[1].w;
                        { u32 zz = *(u16 *)&vtx[j].sz;
                        SQ->sxy2 = s2;
                        SQ->sxy3 = s3;
                        SQ->sxy0 = s0_;
                        SQ->sxy1 = s1_;
                        SQ->z1 = zz; }
                    }
                    SQ->color = *(MS->color + prim[0x18]);
                    SQ->uv0 = *(u32 *)(prim + 12);
                    SQ->uv1 = *(u32 *)(prim + 16);
                    {
                        s32 oz = MS->opz;
                        u8 c = MS->hdr.b[3];
                        register u32 t asm("$4") = *(u32 *)(prim + 20);
                        SQ->code = c;
                        SQ->uv23 = t;
                        if (oz > 20000) n = 2;
                    }
                    { register SubQuad_Model_AddFT4 *q asm("$6"); __asm__("" : "=r"(q) : "0"(0x1F800280)); p = Model_SubdivideFT4(ot, p, q, n); }
                }
            } else {
                /* first half only: v0 v1 v2 */
                if (MS->mode != 0) {
                    if (!(MS->flags & 4)) {
                        u8 h = MS->hdr.b[3];
                        if (!(h & 2)) {
                            MS->hdr.b[3] = h | 2;
                            if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                            else MS->tpage = MS->tpage & 0xFF9F;
                        }
                    }
                    MS->cidx.w = *(u32 *)(prim + 0x18);
                    {
                        u32 c0, z;
                        c0 = MS->cidx.c[0];
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + c0)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
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
                    p[3] = nine;
                    p[7] = (MS->hdr.b[3] & 3) | 0x34;
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
                    p += 0x28;
                    if (!(MS->mode & 2)) goto skip;
                    {
                        u32 z;
                        s32 white = -1;
                        __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[0].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 12) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[1].w;
                        __asm__ volatile("nop; nop; dpcs");
                        *(u32 *)(p + 4) = 0xE1000240;
                        p[3] = seven;
                        p[11] = 0x32;
                        *(u32 *)(p + 20) = z;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
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
                    p[3] = seven;
                    p[7] = MS->hdr.b[3] ^ 8;
                    o = ot;
                    if (!(MS->flags & 1)) {
                        o = ot + MS->otz;
                    }
                    ADD_PRIM_R(o, p, "$3", "$2");
                    p += 0x20;
                }
            }
        } else if (MS->opz2 < 0) {
            /* second half only: v1 v2 v3 */
            if (MS->mode != 0) {
                if (!(MS->flags & 4)) {
                    u8 h = MS->hdr.b[3];
                    if (!(h & 2)) {
                        MS->hdr.b[3] = h | 2;
                        if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                        else MS->tpage = MS->tpage & 0xFF9F;
                    }
                }
                MS->cidx.w = *(u32 *)(prim + 0x18);
                {
                    u32 c0, z;
                    c0 = MS->cidx.c[0];
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
                    __asm__ volatile("swc2 $13, %0" : "=m"(*(u32 *)(p + 8)));
                    __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                    __asm__ volatile("nop; nop; dpcs");
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                    __asm__ volatile("swc2 $14, %0" : "=m"(*(u32 *)(p + 20)));
                    __asm__ volatile("swc2 $12, %0" : "=m"(*(u32 *)(p + 32)));
                }
                {
                    u32 u1 = *(u16 *)(prim + 16), cl = *(u16 *)(prim + 14), u2 = *(u16 *)(prim + 20), tp = MS->tpage, c2 = MS->clut;
                    u16 u3 = *(u16 *)(prim + 22);
                    p[3] = nine;
                    *(u32 *)(p + 12) = (u1 | (cl << 16)) + (c2 << 16);
                    *(u32 *)(p + 24) = u2 | (tp << 16);
                    *(u16 *)(p + 36) = u3;
                }
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
                    z = MS->sxy[1].w;
                    __asm__ volatile("nop; nop; dpcs");
                    *(u32 *)(p + 12) = z;
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                    __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    z = MS->sxy[2].w;
                    __asm__ volatile("nop; nop; dpcs");
                    *(u32 *)(p + 4) = 0xE1000240;
                    p[3] = seven;
                    p[11] = 0x32;
                    *(u32 *)(p + 20) = z;
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                    __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    z = MS->sxy[3].w;
                    __asm__ volatile("nop; nop; dpcs");
                    *(u32 *)(p + 28) = z;
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
                }
                ADD_PRIM_R(ot + MS->otz, p, "$4", "$3");
                p += 0x20;
            } else {
                *(u32 *)(p + 4) = *(MS->color + prim[0x18]);
                __asm__ volatile("swc2 $13, %0; swc2 $14, %1; swc2 $12, %2" : "=m"(*(u32 *)(p + 8)), "=m"(*(u32 *)(p + 16)), "=m"(*(u32 *)(p + 24)));
                {
                    u32 u1 = *(u16 *)(prim + 16), cl = *(u16 *)(prim + 14), u2 = *(u16 *)(prim + 20), tp = MS->tpage, c2 = MS->clut;
                    u16 u3 = *(u16 *)(prim + 22);
                    p[3] = seven;
                    *(u32 *)(p + 12) = (u1 | (cl << 16)) + (c2 << 16);
                    *(u32 *)(p + 20) = u2 | (tp << 16);
                    *(u16 *)(p + 28) = u3;
                }
                p[7] = MS->hdr.b[3] ^ 8;
                o = ot;
                if (!(MS->flags & 1)) {
                    o += MS->otz;
                }
                ADD_PRIM_R(o, p, "$3", "$2");
                p += 0x20;
            }
        }
    skip:
        prim += 0x1C;
        { register s32 c asm("$3") = 0x2C; if ((prim[3] & 0xFC) != c) break; }
    } while (1);
    __asm__ volatile("" : "=r"(MS));
    }
    D_800EC354_Model_AddFT4 = p;
    return prim;
}

extern u8 *D_800EC354_Model_AddGT4 asm("D_800EC354");
typedef struct { u32 sxy; s32 sz; } ScrVtx_Model_AddGT4;
typedef struct { u32 color[0xF0]; u16 fogScale, fogNear; u16 clut; u16 uvoff; union { u32 w; u8 c[4]; } cidx; union { u32 w; struct { s16 x, y; } s; } sxy[4]; s32 otz; s32 opz; s32 opz2; union { u32 w; u8 b[4]; } hdr; u32 idx01; u32 idx23; u8 flags; u8 mode; u16 tpage; } MdlScratch_Model_AddGT4;
typedef struct { u32 sxy0; u16 z0; u16 pad0; u32 sxy1; u16 z1; u16 pad1; u32 sxy2; u16 z2; u16 pad2; u32 sxy3; u16 z3; u16 pad3; u32 color[4]; u32 uv0; u32 uv1; u32 uv23; u8 code; } SubQuad_Model_AddGT4;
u8 *Model_SubdivideGT4(u32 *, u8 *, SubQuad_Model_AddGT4 *, s32);

/* Model Gouraud textured quads (code 0x3C run); same culling/fog/subdivision scheme as Model_AddFT4
   with per-vertex colours (and the scratch UV offset at 0x3C6 added on the quad paths). Big near quads
   go to the subdivider Model_SubdivideGT4. */
u8 *Model_AddGT4(s32 otArg, u8 *primArg, s32 vtxArg)
{ u32 *p3;
    register u32 *ot asm("$20") = (u32 *)otArg;
    u8 *prim = primArg;
    register ScrVtx_Model_AddGT4 *vtx asm("$21") = (ScrVtx_Model_AddGT4 *)vtxArg;
    register MdlScratch_Model_AddGT4 *MS asm("$16") = (MdlScratch_Model_AddGT4 *)0x1F800000;
    u8 *p;
    u32 *o;
    s32 J;

    p = D_800EC354_Model_AddGT4;
    {
    register s32 nine asm("$22") = 9;
    register SubQuad_Model_AddGT4 *SQ asm("$19") = (SubQuad_Model_AddGT4 *)0x1F800280;
    do {
        {
        register u32 w0 asm("$3"), w1 asm("$4"); u32 a, b, c, d;
        w0 = *(u32 *)(prim + 4);
        w1 = *(u32 *)(prim + 8);
        a = w0 & 0xFFFF;
        b = w0 >> 16;
        MS->idx01 = w0;
        __asm__ volatile("");
        c = w1 & 0xFFFF;
        a = vtx[a].sxy;
        b = vtx[b].sxy;
        __asm__ volatile("mtc2 %0, $12; nop; mtc2 %1, $13" : : "r"(a), "r"(b));
        MS->idx23 = w1;
        __asm__ volatile("");
        d = w1 >> 16;
        c = vtx[c].sxy;
        d = vtx[d].sxy;
        MS->sxy[0].w = a;
        MS->sxy[1].w = b;
        __asm__ volatile("mtc2 %0, $14" : : "r"(c));
        MS->sxy[2].w = c;
        MS->sxy[3].w = d;
        }
        __asm__ volatile("nclip");
        {
            register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.x;
            mx = MS->sxy[1].s.x;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.x;
            }
            x = MS->sxy[2].s.x;
            y = MS->sxy[3].s.x;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.x;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0x181) goto skip;
        }
        __asm__ volatile("swc2 $24, %0" : "=m"(MS->opz));
        __asm__ volatile("lwc2 $12, %0" : : "m"(MS->sxy[3]));
        __asm__ volatile("nop; nop; nclip");
        {
            register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
            mn = MS->sxy[0].s.y;
            mx = MS->sxy[1].s.y;
            if (mx < mn) {
                mx = mn;
                __asm__ volatile("" ::: "memory");
                mn = MS->sxy[1].s.y;
            }
            x = MS->sxy[2].s.y;
            y = MS->sxy[3].s.y;
            if (y < x) {
                y = x;
                __asm__ volatile("" ::: "memory");
                x = MS->sxy[3].s.y;
            }
            hi = y;
            if (hi < mx) hi = mx;
            lo = x;
            if (mn < lo) lo = mn;
            if (hi < 0 || lo >= 0xF1) goto skip;
        }
        {
            u32 h = *(u32 *)prim;
            u16 t = *(u16 *)(prim + 0x12);
            MS->hdr.w = h;
            MS->tpage = t;
        }
        __asm__ volatile("swc2 $24, %0" : "=m"(MS->opz2));
        {
            s32 j0;
            J = (s16)((volatile u16 *)&MS->idx01)[1];
            j0 = (s16)((volatile u16 *)&MS->idx01)[0];
            __asm__ volatile("lwc2 $16, %0" : : "m"(vtx[j0].sz));
            __asm__ volatile("lwc2 $17, %0" : : "m"(vtx[J].sz));
        }
        {
            s32 j2;
            J = (s16)((volatile u16 *)&MS->idx23)[1];
            j2 = (s16)((volatile u16 *)&MS->idx23)[0];
            __asm__ volatile("lwc2 $18, %0" : : "m"(vtx[j2].sz));
            __asm__ volatile("lwc2 $19, %0" : : "m"(vtx[J].sz));
        }
        __asm__ volatile("nop; nop; avsz4");
        __asm__ volatile("swc2 $7, %0" : "=m"(MS->otz));
        if (MS->otz < 0x1B) {
            goto skip;
        }
        {
            s32 n, z0, z1, z2, z3;
            n = MS->fogNear << 2;
            __asm__ volatile("mfc2 %0, $16; mfc2 %1, $17; mfc2 %2, $18; mfc2 %3, $19" : "=r"(z0), "=r"(z1), "=r"(z2), "=r"(z3));
            z0 = (z0 - n) << 2;
            z1 = (z1 - n) << 2;
            z2 = (z2 - n) << 2;
            z3 = (z3 - n) << 2;
            if (z0 < 0) z0 = 0;
            __asm__ volatile("mtc2 %0, $16" : : "r"(z0));
            if (z1 < 0) z1 = 0;
            __asm__ volatile("mtc2 %0, $17" : : "r"(z1));
            if (z2 < 0) z2 = 0;
            __asm__ volatile("mtc2 %0, $18" : : "r"(z2));
            if (z3 < 0) z3 = 0;
            __asm__ volatile("mtc2 %0, $19" : : "r"(z3));
            if ((z0 == 0 && z1 == 0 && z2 == 0 && z3 == 0)
                || (z0 >= 0x1001 && z1 >= 0x1001 && z2 >= 0x1001 && z3 >= 0x1001)
                || (MS->flags & 1)) {
                MS->mode = 0;
            } else {
                MS->mode = ((MS->flags & 4) || (MS->hdr.b[3] & 2) || MS->hdr.b[2] == 0) ? 1 : 3;
            }
        }
        if (!(MS->flags & 1) && MS->fogNear < MS->otz && MS->mode == 0) {
            goto skip;
        }
        if (MS->otz >= 0xFC0) {
            MS->otz = 0xFBF;
        }
        MS->cidx.w = *(u32 *)(prim + 0x18);
        if (MS->opz > 0) {
            if (MS->opz2 < 0) {
                /* both halves face the camera: a quad */
                if (MS->mode != 0) {
                    if (!(MS->flags & 4)) {
                        u8 h = MS->hdr.b[3];
                        if (!(h & 2)) {
                            MS->hdr.b[3] = h | 2;
                            if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                            else MS->tpage = MS->tpage & 0xFF9F;
                        }
                    }
                    {
                        u32 k, z;
                        k = MS->cidx.c[0];
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        {
                            u32 uv = *(u32 *)(prim + 12);
                            u32 s0w = MS->sxy[0].w;
                            __asm__ volatile("nop; dpcs");
                            k = MS->cidx.c[1];
                            *(u32 *)(p + 12) = uv + MS->uvoff + (MS->clut << 16);
                            *(u32 *)(p + 8) = s0w;
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        {
                            u32 u1 = *(u16 *)(prim + 16);
                            u32 off = MS->uvoff;
                            __asm__ volatile("nop; dpcs");
                            k = MS->cidx.c[2];
                            *(u32 *)(p + 24) = (u1 + off) | (MS->tpage << 16);
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        {
                            u32 w = *(u32 *)(prim + 20);
                            u32 off = MS->uvoff;
                            __asm__ volatile("nop; dpcs");
                            k = MS->cidx.c[3];
                            { u32 hi = w >> 16;
                            w = w & 0xFFFF;
                            *(u16 *)(p + 36) = w + off;
                            *(u16 *)(p + 48) = hi + off; }
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                        __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        p[3] = 12;
                        __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                        p[7] = MS->hdr.b[3];
                        __asm__ volatile("dpcs");
                    }
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                    __asm__ volatile("swc2 $22, 40(%0); swc2 $12, 44(%0); swc2 $13, 20(%0); swc2 $14, 32(%0)" : : "r"(p) : "memory");
                    p += 0x34;
                    if (!(MS->mode & 2)) goto skip;
                    {
                        u32 z, a, b;
                        s32 white = -1;
                        __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[0].w;
                        b = MS->sxy[1].w;
                        __asm__ volatile("nop; dpcs");
                        *(u32 *)(p + 12) = z;
                        *(u32 *)(p + 20) = b;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[2].w;
                        b = MS->sxy[3].w;
                        __asm__ volatile("nop; dpcs");
                        *(u32 *)(p + 4) = 0xE1000240;
                        p[3] = nine;
                        p[11] = 0x3A;
                        *(u32 *)(p + 28) = z;
                        *(u32 *)(p + 36) = b;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
                        __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                    }
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 32)));
                    p += 0x28;
                } else if (MS->opz - MS->opz2 < 5000 || (MS->hdr.b[3] & 2) || (MS->flags & 2)) {
                    {
                        u32 k0 = MS->cidx.c[0], k1 = MS->cidx.c[1]; register u32 a asm("$4"); u32 b;
                        a = *(MS->color + k0);
                        b = *(MS->color + k1);
                        __asm__("" :: "r"(k1));
                        *(u32 *)(p + 4) = a;
                        *(u32 *)(p + 16) = b;
                    }
                    {
                        u32 k0 = MS->cidx.c[2], k1 = MS->cidx.c[3]; register u32 a asm("$4"); u32 b;
                        a = *(MS->color + k0);
                        b = *(MS->color + k1);
                        __asm__("" :: "r"(k1));
                        *(u32 *)(p + 28) = a;
                        *(u32 *)(p + 40) = b;
                    }
                    {
                        u32 off = MS->uvoff, uv0 = *(u32 *)(prim + 12), cl = MS->clut, s0w = MS->sxy[0].w;
                        u32 uv1 = *(u16 *)(prim + 16), tp = MS->tpage;
                        *(u32 *)(p + 12) = uv0 + off + (cl << 16);
                        *(u32 *)(p + 24) = (uv1 + off) | (tp << 16);
                        *(u32 *)(p + 8) = s0w;
                    }
                    {
                        u32 off = MS->uvoff, w = *(u32 *)(prim + 20);
                        __asm__ volatile("swc2 $12, %0; swc2 $13, %1; swc2 $14, %2" : "=m"(*(u32 *)(p + 44)), "=m"(*(u32 *)(p + 20)), "=m"(*(u32 *)(p + 32)));
                        *(u16 *)(p + 48) = (w >> 16) + off;
                        __asm__ volatile("");
                        p[3] = 12;
                        __asm__ volatile("");
                        *(u16 *)(p + 36) = w + off;
                    }
                    p[7] = MS->hdr.b[3];
                    o = ot;
                    if (!(MS->flags & 1)) {
                        o = ot + MS->otz;
                    }
                    ADD_PRIM_R(o, p, "$3", "$2");
                    p += 0x34;
                } else {
                    /* big and near: subdivide */
                    s32 n;
                    {
                        s32 j; u32 z; u32 s2, s3, s0_, s1_;
                        u32 c0; register u32 c1 asm("$7");
                        u32 *pc0, *pc1;
                                                u32 ca, cb;
                        u32 zz, zb;
                        c0 = MS->cidx.c[0];
                        c1 = MS->cidx.c[1];
                        pc0 = (u32 *)(c0 << 2);
                        j = (s16)((volatile u16 *)&MS->idx23)[0];
                        z = *(u16 *)&vtx[j].sz;
                        c0 = MS->cidx.c[2];
                        pc1 = (u32 *)(c1 << 2);
                        j = (s16)((volatile u16 *)&MS->idx23)[1];
                        c1 = MS->cidx.c[3];
                        pc0 = (u32 *)((u32)pc0 + (u32)MS);
                        pc1 = (u32 *)((u32)pc1 + (u32)MS);
                        SQ->z2 = z;
                        SQ->z3 = *(u16 *)&vtx[j].sz;
                        ca = *pc0;
                        cb = *pc1;
                        SQ->color[0] = ca;
                        ca = *(MS->color + c0);
                        SQ->color[1] = cb;
                        j = (s16)((volatile u16 *)&MS->idx01)[0];
                        p3 = (u32 *)(c1 << 2); cb = *(volatile u32 *)((u32)p3 + (u32)MS);
                        zb = *(u16 *)&vtx[j].sz;
                        j = (s16)((volatile u16 *)&MS->idx01)[1];
                        SQ->z0 = zb;
                        s2 = MS->sxy[2].w;
                        s3 = MS->sxy[3].w;
                        s0_ = MS->sxy[0].w;
                        s1_ = MS->sxy[1].w;
                        zz = *(u16 *)&vtx[j].sz;
                        SQ->color[2] = ca;
                        SQ->color[3] = cb; __asm__("" :: "r"(cb));
                        SQ->sxy2 = s2;
                        SQ->sxy3 = s3;
                        SQ->sxy0 = s0_;
                        SQ->sxy1 = s1_;
                        SQ->z1 = zz;
                    }
                    n = 1; SQ->uv0 = *(u32 *)(prim + 12);
                    SQ->uv1 = *(u32 *)(prim + 16);
                    {
                        s32 oz = MS->opz;
                        register u32 t asm("$4") = *(u32 *)(prim + 20);
                        u8 c = MS->hdr.b[3];
                        SQ->code = c;
                        SQ->uv23 = t;
                        if (oz > 20000) n = 2;
                    }
                    { register SubQuad_Model_AddGT4 *q asm("$6"); __asm__("" : "=r"(q) : "0"(0x1F800280)); p = Model_SubdivideGT4(ot, p, q, n); }
                }
            } else {
                /* first half only: v0 v1 v2 */
                if (MS->mode != 0) {
                    if (!(MS->flags & 4)) {
                        u8 h = MS->hdr.b[3];
                        if (!(h & 2)) {
                            MS->hdr.b[3] = h | 2;
                            if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                            else MS->tpage = MS->tpage & 0xFF9F;
                        }
                    }
                    {
                        u32 k, z;
                        k = MS->cidx.c[0];
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        {
                            u32 a = MS->sxy[0].w, b = MS->sxy[1].w;
                            __asm__ volatile("nop; dpcs");
                            k = MS->cidx.c[1];
                            {
                                u32 c = MS->sxy[2].w;
                                *(u32 *)(p + 8) = a;
                                *(u32 *)(p + 20) = b;
                                *(u32 *)(p + 32) = c;
                            }
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        p[3] = nine;
                        __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                        {
                            u32 uv = *(u32 *)(prim + 12) + (MS->clut << 16);
                            __asm__ volatile("dpcs");
                            k = MS->cidx.c[2];
                            *(u32 *)(p + 12) = uv + MS->uvoff;
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        {
                            u32 u1 = *(u16 *)(prim + 16);
                            u32 off = MS->uvoff;
                            __asm__ volatile("nop; dpcs");
                            { u32 tp = MS->tpage;
                            u32 u2 = *(u16 *)(prim + 20);
                            __asm__ volatile("");
                            *(u32 *)(p + 24) = (u1 | (tp << 16)) + off;
                            *(u16 *)(p + 36) = u2 + off; }
                        }
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                    }
                    p[7] = MS->hdr.b[3] ^ 8;
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                    p += 0x28;
                    if (!(MS->mode & 2)) goto skip;
                    {
                        u32 z, a, b, c;
                        s32 white = -1;
                        __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                        __asm__ volatile("mfc2 %0, $16" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        z = MS->sxy[0].w;
                        b = MS->sxy[1].w;
                        __asm__ volatile("nop; dpcs");
                        c = MS->sxy[2].w;
                        *(u32 *)(p + 12) = z;
                        *(u32 *)(p + 20) = b;
                        *(u32 *)(p + 28) = c;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                        __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                        p[3] = 7;
                        *(u32 *)(p + 4) = 0xE1000240;
                        p[11] = 0x32;
                        __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                        __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                        __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                        __asm__ volatile("nop; nop; dpcs");
                    }
                    ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
                    p += 0x20;
                } else {
                    {
                        u32 k0 = MS->cidx.c[0], k1 = MS->cidx.c[1], k2; register u32 a asm("$4"); u32 b;
                        a = *(MS->color + k0);
                        k2 = MS->cidx.c[2];
                        *(u32 *)(p + 4) = a;
                        a = *(MS->color + k2);
                        b = *(MS->color + k1);
                        *(u32 *)(p + 16) = b;
                        *(u32 *)(p + 28) = a;
                    }
                    {
                        u32 s0w = MS->sxy[0].w;
                        __asm__ volatile("swc2 $13, %0; swc2 $14, %1" : "=m"(*(u32 *)(p + 20)), "=m"(*(u32 *)(p + 32)));
                        *(u32 *)(p + 8) = s0w;
                    }
                    {
                        u32 uv0 = *(u32 *)(prim + 12), uv1 = *(u16 *)(prim + 16), tp = MS->tpage, cl = MS->clut;
                        u16 uv2 = *(u16 *)(prim + 20);
                        p[3] = nine;
                        *(u32 *)(p + 12) = uv0 + (cl << 16);
                        *(u32 *)(p + 24) = uv1 | (tp << 16);
                        *(u16 *)(p + 36) = uv2;
                    }
                    p[7] = MS->hdr.b[3] ^ 8;
                    o = ot;
                    if (!(MS->flags & 1)) {
                        o = ot + MS->otz;
                    }
                    ADD_PRIM_R(o, p, "$3", "$2");
                    p += 0x28;
                }
            }
        } else if (MS->opz2 < 0) {
            /* second half only: v1 v2 v3 */
            if (MS->mode != 0) {
                if (!(MS->flags & 4)) {
                    u8 h = MS->hdr.b[3];
                    if (!(h & 2)) {
                        MS->hdr.b[3] = h | 2;
                        if (MS->hdr.b[2]) MS->tpage = (MS->tpage & 0xFF9F) | 0x20;
                        else MS->tpage = MS->tpage & 0xFF9F;
                    }
                }
                {
                    u32 k, z;
                    k = MS->cidx.c[1];
                    __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                    __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    {
                        u32 a = MS->sxy[1].w, b = MS->sxy[2].w;
                        __asm__ volatile("nop; dpcs");
                        k = MS->cidx.c[2];
                        {
                            u32 c = MS->sxy[3].w;
                            *(u32 *)(p + 8) = a;
                            *(u32 *)(p + 20) = b;
                            *(u32 *)(p + 32) = c;
                        }
                    }
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 4)));
                    __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                    __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    {
                        u32 uv = *(u16 *)(prim + 16) | (*(u16 *)(prim + 14) << 16);
                        __asm__ volatile("dpcs");
                        {
                            u32 cl = MS->clut, u2 = *(u16 *)(prim + 20), tp = MS->tpage;
                            u16 u3 = *(u16 *)(prim + 22);
                            *(u32 *)(p + 12) = uv + (cl << 16);
                            *(u32 *)(p + 24) = u2 | (tp << 16);
                            *(u16 *)(p + 36) = u3;
                        }
                        k = MS->cidx.c[3];
                    }
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                    __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                    __asm__ volatile("lwc2 $6, %0" : : "m"(*(MS->color + k)));
                    p[3] = nine;
                    __asm__ volatile("mtc2 %0, $8" : : "r"(z));
                    p[7] = MS->hdr.b[3] ^ 8;
                    __asm__ volatile("dpcs");
                }
                ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 28)));
                p += 0x28;
                if (!(MS->mode & 2)) goto skip;
                {
                    u32 z, a, b;
                    s32 white = -1;
                    __asm__ volatile("mtc2 %0, $6; nop" : : "r"(white));
                    __asm__ volatile("mfc2 %0, $17" : "=r"(z));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    z = MS->sxy[1].w;
                    b = MS->sxy[2].w;
                    __asm__ volatile("nop; dpcs");
                    *(u32 *)(p + 12) = z;
                    *(u32 *)(p + 20) = b;
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 8)));
                    __asm__ volatile("mfc2 %0, $18" : "=r"(z));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    z = MS->sxy[3].w;
                    __asm__ volatile("nop; nop; dpcs");
                    p[3] = 7;
                    *(u32 *)(p + 4) = 0xE1000240;
                    p[11] = 0x32;
                    *(u32 *)(p + 28) = z;
                    __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 16)));
                    __asm__ volatile("mfc2 %0, $19" : "=r"(z));
                    __asm__ volatile("nop; mtc2 %0, $8" : : "r"(z));
                    __asm__ volatile("nop; nop; dpcs");
                }
                ADD_PRIM_R(ot + MS->otz, p, "$4", "$3"); __asm__("" : "=r"(p3)); __asm__("" :: "r"(p3));
                __asm__ volatile("swc2 $22, %0" : "=m"(*(u32 *)(p + 24)));
                p += 0x20;
            } else {
                {
                    u32 k0 = MS->cidx.c[1], k1 = MS->cidx.c[2], k2; register u32 a asm("$4"); u32 b;
                    a = *(MS->color + k0);
                    k2 = MS->cidx.c[3];
                    *(u32 *)(p + 4) = a;
                    a = *(MS->color + k2);
                    b = *(MS->color + k1);
                    *(u32 *)(p + 16) = b;
                    *(u32 *)(p + 28) = a;
                }
                __asm__ volatile("swc2 $13, %0; swc2 $14, %1; swc2 $12, %2" : "=m"(*(u32 *)(p + 8)), "=m"(*(u32 *)(p + 20)), "=m"(*(u32 *)(p + 32)));
                {
                    u32 u1 = *(u16 *)(prim + 16), cl = *(u16 *)(prim + 14), u2 = *(u16 *)(prim + 20), tp = MS->tpage, c2 = MS->clut;
                    u16 u3 = *(u16 *)(prim + 22);
                    p[3] = nine;
                    *(u32 *)(p + 12) = (u1 | (cl << 16)) + (c2 << 16);
                    *(u32 *)(p + 24) = u2 | (tp << 16);
                    *(u16 *)(p + 36) = u3;
                }
                p[7] = MS->hdr.b[3] ^ 8;
                o = ot;
                if (!(MS->flags & 1)) {
                    o += MS->otz;
                }
                ADD_PRIM_R(o, p, "$3", "$2");
                p += 0x28;
            }
        }
    skip:
        prim += 0x1C;
        { register s32 c asm("$3") = 0x3C; if ((prim[3] & 0xFC) != c) break; }
    } while (1);
    __asm__ volatile("" : "=r"(MS));
    }
    D_800EC354_Model_AddGT4 = p;
    return prim;
}

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


typedef struct { u32 sxy; u16 z; u16 pad; } Vtx_1CE54;
typedef struct { u8 pad0[8]; u8 *prims; } Mdl_1CE54;
typedef struct { u16 x, y; } XY_1CE54;
typedef struct { u8 pad0[0x3CC]; XY_1CE54 sxy[4]; s32 z; s32 opz[2]; u8 pad3E8[4]; u16 idx[4]; u8 mode; } Scr_1CE54;
typedef struct { u32 tag; u8 r0, g0, b0, code; u32 xy0; u16 uv0; u16 clut; u32 xy1; u16 uv1; u16 tpage; u32 xy2; u16 uv2; u16 pad; u32 xy3; u16 uv3; u16 pad2; } Poly_1CE54;
typedef struct { u16 uv; u8 pad2[6]; } Uv_1CE54;
extern Uv_1CE54 D_800EA066[];
extern u8 *D_800EC354_1CE54 asm("D_800EC354");
#define gte_ldsxy3_1CE54(p) __asm__ volatile ("lwc2 $12, 0(%0); lwc2 $13, 4(%0); lwc2 $14, 8(%0)" : : "r"(p))
#define gte_ldsxy0_1CE54(r) __asm__ volatile ("mtc2 %0, $12" : : "r"(r))
#define gte_nclip_1CE54() __asm__ volatile ("nop; nop; nclip")
#define gte_stopz_1CE54(p) __asm__ volatile ("swc2 $24, 0(%0)" : : "r"(p) : "memory")
#define gte_stsxy3_ft3_1CE54(p) __asm__ volatile ("swc2 $12, 8(%0); swc2 $13, 16(%0); swc2 $14, 24(%0)" : : "r"(p) : "memory")
#define gte_stsxy3_1CE54(a, b, c) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 0(%1); swc2 $14, 0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory")

/* Draws a model with its per-vertex texture coordinates (D_800EA066[i].uv, set up by
   Model_CycleVertexColors) as textured polys (0x25 / 0x2D, tpage 0x3D, clut 0x7037). Culling as in
   Model_DrawScreenMapped; a quad is only dropped when both of its halves face away. Scratch
   mode bit 0 puts everything in the first OT entry. */
void func_8001CE54(u32 *ot, Vtx_1CE54 *v, Mdl_1CE54 *m) {
    Scr_1CE54 *sc = (Scr_1CE54 *)0x1F800000;
    u16 clut;
    u16 tpage;
    u8 *prim;
    u8 *pr;
    u32 *o;
    u32 t;
    tpage = 0x3D;
    clut = 0x7037;
    prim = D_800EC354_1CE54;
    pr = m->prims;

    for (;;) {
        switch (pr[3] & 0xFC) {
        case 0x20:
        case 0x24:
        case 0x30:
        case 0x34:
            sc->idx[0] = ((u16 *)pr)[2];
            t = v[(s16)sc->idx[0]].sxy;
            *(u32 *)&sc->sxy[0] = t;
            sc->idx[1] = ((u16 *)pr)[3];
            t = v[(s16)sc->idx[1]].sxy;
            *(u32 *)&sc->sxy[1] = t;
            sc->idx[2] = ((u16 *)pr)[4];
            { Vtx_1CE54 *q = (Vtx_1CE54 *)((s16)sc->idx[2] * 8 + (s32)v); __asm__ volatile(""); *(u32 *)&sc->sxy[2] = q->sxy; }
            gte_ldsxy3_1CE54(sc->sxy);
            gte_nclip_1CE54();
            if (((s16)sc->sxy[0].x > 0x180 & (s16)sc->sxy[1].x > 0x180 & (s16)sc->sxy[2].x > 0x180)
                || ((s16)sc->sxy[0].y > 0xF0 & (s16)sc->sxy[1].y > 0xF0 & (s16)sc->sxy[2].y > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1CE54(&sc->opz[0]);
                if (sc->opz[0] < 0 || (s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    sc->z = (((s16)v[(s16)sc->idx[0]].z >> 2) + ((s16)v[(s16)sc->idx[1]].z >> 2) + ((s16)v[(s16)sc->idx[2]].z >> 2)) / 3;
                    sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                    { s32 z = sc->z; register u32 *oo asm("$4") = ot; if (!(sc->mode & 1)) { register s32 zz asm("$2") = z << 2; oo = (u32 *)((u8 *)ot + zz); } o = oo; }
                    ADD_PRIM_R(o, prim, "$3", "$2");
                    gte_stsxy3_ft3_1CE54(prim);
                    prim[3] = 7;
                    ((Poly_1CE54 *)prim)->code = 0x25;
                    ((Poly_1CE54 *)prim)->tpage = tpage;
                    ((Poly_1CE54 *)prim)->clut = clut;
                    ((Poly_1CE54 *)prim)->uv0 = D_800EA066[(s16)sc->idx[0]].uv;
                    ((Poly_1CE54 *)prim)->uv1 = D_800EA066[(s16)sc->idx[1]].uv;
                    ((Poly_1CE54 *)prim)->uv2 = D_800EA066[(s16)sc->idx[2]].uv;
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
            t = v[(s16)sc->idx[0]].sxy;
            *(u32 *)&sc->sxy[0] = t;
            sc->idx[1] = ((u16 *)pr)[3];
            t = v[(s16)sc->idx[1]].sxy;
            *(u32 *)&sc->sxy[1] = t;
            sc->idx[2] = ((u16 *)pr)[4];
            t = v[(s16)sc->idx[2]].sxy;
            *(u32 *)&sc->sxy[2] = t;
            sc->idx[3] = ((u16 *)pr)[5];
            { Vtx_1CE54 *q = (Vtx_1CE54 *)((s16)sc->idx[3] * 8 + (s32)v); __asm__ volatile(""); *(u32 *)&sc->sxy[3] = q->sxy; }
            gte_ldsxy3_1CE54(sc->sxy);
            gte_nclip_1CE54();
            if (((s16)sc->sxy[0].x > 0x180 & (s16)sc->sxy[1].x > 0x180 & (s16)sc->sxy[2].x > 0x180 & (s16)sc->sxy[3].x > 0x180)
                || ((s16)sc->sxy[0].y > 0xF0 & (s16)sc->sxy[1].y > 0xF0 & (s16)sc->sxy[2].y > 0xF0 & (s16)sc->sxy[3].y > 0xF0)) {
                pr += pr[1] * 4;
            } else {
                gte_stopz_1CE54(&sc->opz[0]);
                gte_ldsxy0_1CE54(*(u32 *)&sc->sxy[3]);
                gte_nclip_1CE54();
                if ((s16)v[(s16)sc->idx[0]].z < 0x1B) {
                    pr += pr[1] * 4;
                } else {
                    gte_stopz_1CE54(&sc->opz[1]);
                    if (sc->opz[0] < 0 && sc->opz[1] > 0) {
                        pr += pr[1] * 4;
                    } else {
                        sc->z = ((s16)v[(s16)sc->idx[0]].z >> 4) + ((s16)v[(s16)sc->idx[1]].z >> 4) + ((s16)v[(s16)sc->idx[2]].z >> 4) + ((s16)v[(s16)sc->idx[3]].z >> 4);
                        sc->z = (sc->z < 0) ? 0 : ((sc->z >= 0xFC0) ? 0xFBF : sc->z);
                        { s32 z = sc->z; o = (sc->mode & 1) ? ot : &ot[z]; }
                        ADD_PRIM_R(o, prim, "$3", "$2");
                        ((Poly_1CE54 *)prim)->xy0 = *(u32 *)&sc->sxy[0];
                        gte_stsxy3_1CE54(&((Poly_1CE54 *)prim)->xy3, &((Poly_1CE54 *)prim)->xy1, &((Poly_1CE54 *)prim)->xy2);
                        prim[3] = 9;
                        ((Poly_1CE54 *)prim)->code = 0x2D;
                        ((Poly_1CE54 *)prim)->tpage = tpage;
                        ((Poly_1CE54 *)prim)->clut = clut;
                        ((Poly_1CE54 *)prim)->uv0 = D_800EA066[(s16)sc->idx[0]].uv;
                        ((Poly_1CE54 *)prim)->uv1 = D_800EA066[(s16)sc->idx[1]].uv;
                        ((Poly_1CE54 *)prim)->uv2 = D_800EA066[(s16)sc->idx[2]].uv;
                        ((Poly_1CE54 *)prim)->uv3 = D_800EA066[(s16)sc->idx[3]].uv;
                        prim += 0x28;
                        pr += pr[1] * 4;
                    }
                }
            }
            break;
        default:
            goto done;
        }
    }
done:
    __asm__("" : : "r"(tpage));
    D_800EC354_1CE54 = prim;
}

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


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_SubdivideGT4);

/* Quad subdivider for big near textured quads (from Model_AddFT4): culls if wholly off one screen side, at depth 0 emits a POLY_FT4, otherwise splits into four perspective-weighted sub-quads (built in q[1]) and recurses with depth-1. */
typedef struct { s16 x, y; } XY_1E828;
typedef struct { u8 r, g, b, cd; } QC_1E828;
typedef struct { union { u32 w; XY_1E828 s; } xy; union { u32 w; struct { s16 z, pad; } s; } zw; } QV_1E828;
typedef struct { QV_1E828 v[4]; QC_1E828 col; u8 u0, v0; u16 clut; u8 u1, v1; u16 tpage; u8 u2, v2; u8 u3, v3; u8 code; u8 pad[3]; } Quad_1E828;

u8 *Model_SubdivideFT4(u32 *ot, u8 *prim, SubQuad_Model_AddFT4 *qa, s32 depth) {
    Quad_1E828 *q = (Quad_1E828 *)qa;
    MdlScratch_Model_AddFT4 *MS;
    Quad_1E828 *c;
    s32 d1;
    s32 wa, wb, xs, ys;
    u32 *o;

    __asm__ volatile("");


    { u32 w0 = q->v[0].xy.w; __asm__("lui %0, 0x1f80" : "=r"(MS)); MS->sxy[0].w = w0; }
    MS->sxy[1].w = q->v[1].xy.w; __asm__ volatile("" : "=r"(prim) : "0"(prim));
    MS->sxy[2].w = q->v[2].xy.w;
    __asm__ volatile("lwc2 $12, 0(%0); lwc2 $13, 4(%0); lwc2 $14, 8(%0)" : : "r"((void *)0x1F8003CC));
    __asm__ volatile("nop; nop; nclip");
    MS->sxy[3].w = q->v[3].xy.w;
    __asm__ volatile("" ::: "memory");
    {
        register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
        mn = MS->sxy[0].s.x;
        mx = MS->sxy[1].s.x;
        if (mx < mn) {
            mx = mn;
            __asm__ volatile("" ::: "memory");
            mn = MS->sxy[1].s.x;
        }
        x = MS->sxy[2].s.x;
        y = MS->sxy[3].s.x;
        if (y < x) {
            y = x;
            __asm__ volatile("" ::: "memory");
            x = MS->sxy[3].s.x;
        }
        hi = y;
        if (hi < mx) hi = mx;
        lo = x;
        if (mn < lo) lo = mn;
        if (hi < 0 || lo >= 0x181) goto end;
    }
    {
        register s32 mn asm("$6"), mx asm("$7"); s32 x, y, hi, lo;
        mn = MS->sxy[0].s.y;
        mx = MS->sxy[1].s.y;
        if (mx < mn) {
            mx = mn;
            __asm__ volatile("" ::: "memory");
            mn = MS->sxy[1].s.y;
        }
        x = MS->sxy[2].s.y;
        y = MS->sxy[3].s.y;
        if (y < x) {
            y = x;
            __asm__ volatile("" ::: "memory");
            x = MS->sxy[3].s.y;
        }
        hi = y;
        if (hi < mx) hi = mx;
        lo = x;
        if (mn < lo) lo = mn;
        if (hi < 0 || lo >= 0xF1) goto end;
    }
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&MS->opz) : "memory");
    if (depth == 0) {
        s32 z = ((s16)((SubQuad_Model_AddFT4 *)q)->z0 >> 4) + ((s16)((SubQuad_Model_AddFT4 *)q)->z1 >> 4) + ((s16)((SubQuad_Model_AddFT4 *)q)->z2 >> 4) + ((s16)((SubQuad_Model_AddFT4 *)q)->z3 >> 4);
        z = (z < 0) ? 0 : ((z > 0xFC0) ? 0xFC0 : z);
        o = (MS->flags & 1) ? ot : &ot[z];
        ADD_PRIM_R(o, prim, "$3", "$2");
        {
            u32 a, b; u16 h, h2;
            a = q->v[0].xy.w; b = q->v[1].xy.w; ((u32 *)prim)[2] = a; ((u32 *)prim)[4] = b;
            a = q->v[2].xy.w; b = q->v[3].xy.w; ((u32 *)prim)[6] = a; ((u32 *)prim)[8] = b;
            a = *(u32 *)&q->col; b = *(u32 *)&q->u0; ((u32 *)prim)[1] = a; ((u32 *)prim)[3] = b;
            a = *(u32 *)&q->u1; h = *(u16 *)&q->u2; ((u32 *)prim)[5] = a; h2 = *(u16 *)&q->u3; ((u16 *)prim)[14] = h;
            prim[3] = 9;
            ((u16 *)prim)[18] = h2;
            prim[7] = q->code;
        }
        prim += 0x28;
        goto end;
    }

    /* top-left quarter: v0, mid(v0,v1), mid(v2,v0), centre */
    q[1].v[0].xy.w = q->v[0].xy.w; q[1].v[0].zw.w = q->v[0].zw.w;
    q[1].col = q->col;
    *(u32 *)&q[1].u0 = *(u32 *)&q->u0;
    wa = q->v[0].zw.s.z;
    wb = q->v[1].zw.s.z;
    q[1].tpage = q->tpage;
    if (wa < 0xA4) wa = 0xA4;
    if (wb < 0xA4) wb = 0xA4;
    { s32 xs, ys;
    xs = q->v[0].xy.s.x * wa + q->v[1].xy.s.x * wb;
    ys = q->v[0].xy.s.y * wa + q->v[1].xy.s.y * wb;
    if (q->v[1].xy.s.x < q->v[0].xy.s.x) ys += wa + wb;
    if (q->v[0].xy.s.y < q->v[1].xy.s.y) xs += wa + wb;
    q[1].v[1].xy.s.x = xs / (wa + wb);
    q[1].v[1].xy.s.y = ys / (wa + wb);
    }
    q[1].v[1].zw.s.z = (wa + wb) / 2;
    q[1].u1 = (q->u0 + q->u1) >> 1;
    q[1].v1 = (q->v0 + q->v1) >> 1;
    wb = q->v[2].zw.s.z;
    if (wb < 0xA4) wb = 0xA4;
    { s32 xs, ys;
    xs = q->v[0].xy.s.x * wa + q->v[2].xy.s.x * wb;
    ys = q->v[0].xy.s.y * wa + q->v[2].xy.s.y * wb;
    if (q->v[0].xy.s.x < q->v[2].xy.s.x) ys += wa + wb;
    if (q->v[2].xy.s.y < q->v[0].xy.s.y) xs += wa + wb;
    q[1].v[2].xy.s.x = xs / (wa + wb);
    q[1].v[2].xy.s.y = ys / (wa + wb);
    }
    q[1].v[2].zw.s.z = (wa + wb) / 2;
    q[1].u2 = (q->u0 + q->u2) >> 1;
    q[1].v2 = (q->v0 + q->v2) >> 1;
    wa = q->v[1].zw.s.z;
    if (wa < 0xA4) wa = 0xA4;
    xs = (q->v[1].xy.s.x * wa + q->v[2].xy.s.x * wb) / (wa + wb);
    ys = (q->v[1].xy.s.y * wa + q->v[2].xy.s.y * wb) / (wa + wb);
    q[1].v[3].zw.s.z = (wa + wb) / 2;
    q[1].u3 = (q->u1 + q->u2) >> 1;
    q[1].v3 = (q->v1 + q->v2) >> 1;
    q[1].code = q->code;
    q[1].v[3].xy.s.x = xs;
    q[1].v[3].xy.s.y = ys;
    c = q + 1;
    d1 = depth - 1;
    prim = Model_SubdivideFT4(ot, prim, (SubQuad_Model_AddFT4 *)c, d1);

    /* top-right: mid(v0,v1), v1, centre, mid(v1,v3) */
    wa = q->v[1].zw.s.z;
    wb = q->v[3].zw.s.z;
    q[1].clut = q->clut;
    q[1].tpage = q->tpage;
    q[1].v[0].xy.w = q[1].v[1].xy.w; q[1].v[0].zw.w = q[1].v[1].zw.w;
    q[1].u0 = q[1].u1;
    q[1].v0 = q[1].v1;
    q[1].v[1].xy.w = q->v[1].xy.w; q[1].v[1].zw.w = q->v[1].zw.w;
    q[1].u1 = q->u1;
    q[1].v1 = q->v1;
    q[1].v[2].xy.w = q[1].v[3].xy.w; q[1].v[2].zw.w = q[1].v[3].zw.w;
    q[1].u2 = q[1].u3;
    q[1].v2 = q[1].v3;
    if (wa < 0xA4) wa = 0xA4;
    if (wb < 0xA4) wb = 0xA4;
    { s32 xs, ys;
    xs = q->v[1].xy.s.x * wa + q->v[3].xy.s.x * wb;
    ys = q->v[1].xy.s.y * wa + q->v[3].xy.s.y * wb;
    if (q->v[3].xy.s.x < q->v[1].xy.s.x) ys += wa + wb;
    if (q->v[1].xy.s.y < q->v[3].xy.s.y) xs += wa + wb;
    q[1].v[3].xy.s.x = xs / (wa + wb);
    q[1].v[3].xy.s.y = ys / (wa + wb);
    }
    q[1].v[3].zw.s.z = (wa + wb) / 2;
    q[1].u3 = (q->u1 + q->u3) >> 1;
    q[1].v3 = (q->v1 + q->v3) >> 1;
    prim = Model_SubdivideFT4(ot, prim, (SubQuad_Model_AddFT4 *)c, d1);

    /* bottom-right: centre, mid(v1,v3), mid(v3,v2), v3 */
    wa = q->v[2].zw.s.z;
    wb = q->v[3].zw.s.z;
    q[1].clut = q->clut;
    q[1].tpage = q->tpage;
    q[1].v[0].xy.w = q[1].v[2].xy.w; q[1].v[0].zw.w = q[1].v[2].zw.w;
    q[1].u0 = q[1].u2;
    q[1].v0 = q[1].v2;
    q[1].v[1].xy.w = q[1].v[3].xy.w; q[1].v[1].zw.w = q[1].v[3].zw.w;
    q[1].u1 = q[1].u3;
    q[1].v1 = q[1].v3;
    if (wa < 0xA4) wa = 0xA4;
    if (wb < 0xA4) wb = 0xA4;
    { s32 xs, ys;
    xs = q->v[2].xy.s.x * wa + q->v[3].xy.s.x * wb;
    ys = q->v[2].xy.s.y * wa + q->v[3].xy.s.y * wb;
    if (q->v[2].xy.s.x < q->v[3].xy.s.x) ys += wa + wb;
    if (q->v[3].xy.s.y < q->v[2].xy.s.y) xs += wa + wb;
    q[1].v[2].xy.s.x = xs / (wa + wb);
    q[1].v[2].xy.s.y = ys / (wa + wb);
    }
    q[1].v[2].zw.s.z = (wa + wb) / 2;
    q[1].u2 = (q->u2 + q->u3) >> 1;
    q[1].v2 = (q->v2 + q->v3) >> 1;
    q[1].v[3].xy.w = q->v[3].xy.w; q[1].v[3].zw.w = q->v[3].zw.w;
    q[1].u3 = q->u3;
    q[1].v3 = q->v3;
    prim = Model_SubdivideFT4(ot, prim, (SubQuad_Model_AddFT4 *)c, d1);

    /* bottom-left: mid(v2,v0), centre, v2, mid(v3,v2) */
    wa = q->v[0].zw.s.z;
    q[1].clut = q->clut;
    q[1].tpage = q->tpage;
    q[1].v[1].xy.w = q[1].v[0].xy.w; q[1].v[1].zw.w = q[1].v[0].zw.w;
    q[1].u1 = q[1].u0;
    q[1].v1 = q[1].v0;
    q[1].v[3].xy.w = q[1].v[2].xy.w; q[1].v[3].zw.w = q[1].v[2].zw.w;
    q[1].u3 = q[1].u2;
    q[1].v3 = q[1].v2;
    q[1].v[2].xy.w = q->v[2].xy.w; q[1].v[2].zw.w = q->v[2].zw.w;
    q[1].u2 = q->u2;
    q[1].v2 = q->v2;
    if (wa < 0xA4) wa = 0xA4;
    wb = q->v[2].zw.s.z;
    if (wb < 0xA4) wb = 0xA4;
    { s32 xs, ys;
    xs = q->v[0].xy.s.x * wa + q->v[2].xy.s.x * wb;
    ys = q->v[0].xy.s.y * wa + q->v[2].xy.s.y * wb;
    if (q->v[0].xy.s.x < q->v[2].xy.s.x) ys += wa + wb;
    if (q->v[2].xy.s.y < q->v[0].xy.s.y) xs += wa + wb;
    q[1].v[0].xy.s.x = xs / (wa + wb);
    q[1].v[0].xy.s.y = ys / (wa + wb);
    }
    q[1].v[0].zw.s.z = (wa + wb) / 2;
    q[1].u0 = (q->u0 + q->u2) >> 1;
    q[1].v0 = (q->v0 + q->v2) >> 1;
    prim = Model_SubdivideFT4(ot, prim, (SubQuad_Model_AddFT4 *)(q + 1), depth - 1);
end:
    return prim;
}
