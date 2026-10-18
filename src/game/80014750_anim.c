#include "common.h"
#include "m2c_macros.h"
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80014750;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80014750_8001484C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8001484C_8001484C;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80014750_80014A84;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8001484C_80014A84;
typedef struct { s32 x : 10; s32 y : 12; s32 z : 10; } Pk_8001526C_8001526C;
typedef struct { u8 pad0[4]; Pk_8001526C_8001526C pos; Pk_8001526C_8001526C rot[1]; } Frame_8001526C_8001526C;
typedef struct { u8 pad0[4]; u16 n; } Hdr_8001526C_8001526C;
typedef struct { u8 pad0[4]; s16 x; s16 y; s16 z; } Root_8001526C_8001526C;
typedef struct { Hdr_8001526C_8001526C *hdr; u8 pad4[8]; Root_8001526C_8001526C *root; } Model_8001526C_8001526C;
typedef struct { s32 x : 10; s32 y : 12; s32 z : 10; } Pk_8001526C_80014FA0;
typedef struct { u8 pad0[4]; Pk_8001526C_80014FA0 pos; Pk_8001526C_80014FA0 rot[1]; } Frame_8001526C_80014FA0;
typedef struct { u8 pad0[4]; u16 n; } Hdr_8001526C_80014FA0;
typedef struct { u8 pad0[4]; s16 x; s16 y; s16 z; } Root_8001526C_80014FA0;
typedef struct { Hdr_8001526C_80014FA0 *hdr; u8 pad4[8]; Root_8001526C_80014FA0 *root; u8 pad10[8]; u32 *anim; } Model_8001526C_80014FA0;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80014750_80015D58;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_800147D0;
typedef struct { s32 x : 10; s32 y : 12; s32 z : 10; } PK_80014D70;
typedef struct { u8 pad0[4]; u16 f_4; } S_AnimHdr_80014D70;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; } S_Out_80014D70;
typedef struct { S_AnimHdr_80014D70 *f_0; u8 pad4[8]; S_Out_80014D70 *f_C; u8 pad10[8]; PK_80014D70 *f_18; u8 pad1C[0x40]; u16 f_5C; } S_14D70_80014D70;
typedef struct { u8 pad0[6]; u16 f_6; u16 f_8; u8 padA[2]; } S_Hdr_80015D10;
typedef struct { S_Hdr_80015D10 *f_0; s32 *f_4; s32 *f_8; s32 *f_C; } S_HdrOut_80015D10;
typedef struct { u32 *f_0; u32 *f_4; u8 *f_8; u8 *f_C; u8 pad10[8]; u16 f_18; u16 f_1A; } S_15C34_80015C34;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u16 f_6; } AnimE_14E34_80014E34;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u16 f_5E; u8 pad60[0x10C]; AnimE_14E34_80014E34 *f_16C; } Model_14E34_80014E34;
typedef struct { u8 pad0[4]; u16 f_4; u16 f_6; u16 f_8; u16 f_A; u8 data[4]; } Hdr_80015BA0_80015BA0;
typedef struct { Hdr_80015BA0_80015BA0 *f_0; u8 *f_4; u8 *f_8; u8 *f_C; u8 *f_10; void *f_14; } Out_80015BA0_80015BA0;
typedef struct { u8 pad0[4]; u16 f_4; u16 f_6; u16 f_8; u8 padA[2]; } S_Hdr_80015AC0;
typedef struct { S_Hdr_80015AC0 *f_0; u8 *f_4; u8 *f_8; u8 *f_C; u8 *f_10; void *f_14; } S_HdrOut_80015AC0;
typedef struct { u8 pad0[4]; u16 f_4; u16 f_6; u16 f_8; u8 padA[2]; } S_Hdr_80015B30;
typedef struct { S_Hdr_80015B30 *f_0; u8 *f_4; u8 *f_8; u8 *f_C; u8 *f_10; void *f_14; } S_HdrOut_80015B30;

s32 rcos(s32);
s32 rsin(s32);
MAT_80014750 *MulMatrix(MAT_80014750 *, MAT_80014750 *);

/* Points a model instance at mesh data h: +0 header, +4 data after the 24-byte header,
 * +0xC / +8 the two tables at word offsets h[4] / h[5]; meshes with flag bits 0xF0 are left
 * unbound. When the 0x300000 bits are set, +0x1A gets 1 for flag 0x4000 and 2 for 0x8000. */
void Model_BindMesh(S_15C34_80015C34 *o, u32 *h);
extern struct S_D_800EC350 { u8 pad_0[0x8224]; s32 f_8224; } g_Game;
void VectorNormalSS(void *in, void *out);
extern struct S_D_800F4B30 { s16 x; s16 y; s16 z; s16 pad; } D_800F4B30[];
void SetBackColor(s32 rbk, s32 gbk, s32 bbk);
void SetColorMatrix(void* m);
extern MAT_80014750_80015D58 D_800EBFF0;
extern MAT_80014750_80015D58 D_800E78E0;
void Matrix_Copy(s32 *d, s32 *s);
struct S_D_800F4B30_80014D70 { s16 x, y, z, pad; };
void Anim_BlendFrameIndex();
extern u8 D_800E9C60[];

void Matrix_RotateY(s32 ang, MAT_80014750 *m) {
    MAT_80014750 r;
    r.m[0][0] = rcos(ang);
    r.m[0][1] = 0;
    r.m[0][2] = -rsin(ang);
    r.m[1][0] = 0;
    r.m[1][1] = 0x1000;
    r.m[1][2] = 0;
    r.m[2][0] = rsin(ang);
    r.m[2][1] = 0;
    r.m[2][2] = rcos(ang);
    MulMatrix(m, &r);
}

void func_800147D0(s16 *v, MAT_800147D0 *m) {
    m->m[0][0] = v[0];
    m->m[0][1] = 0;
    m->m[0][2] = 0;
    m->m[1][1] = v[1];
    m->m[1][0] = 0;
    m->m[1][2] = 0;
    m->m[2][2] = v[2];
    m->m[2][0] = 0;
    m->m[2][1] = 0;
}

void func_80014804(s16 *v, s16 *m) {
    m[0] = m[8] = -v[2];
    m[2] = -v[0];
    m[6] = v[0];
    m[4] = 0x1000;
    m[7] = 0;
    m[5] = 0;
    m[3] = 0;
    m[1] = 0;
}

/* Rotation matrix looking along dir: z = -normalize(dir), x = normalize(up x z) with up = +Y
 * (or +Z when dir is vertical), y = z x x; written as the matrix columns. */
void Matrix_FromDirection(SVEC_8001484C_8001484C *dir, MAT_80014750_8001484C *m) {
    SVEC_8001484C_8001484C x;
    SVEC_8001484C_8001484C y;
    SVEC_8001484C_8001484C z;

    VectorNormalSS(dir, &z);
    z.vx = -z.vx;
    z.vy = -z.vy;
    z.vz = -z.vz;
    if (z.vx == 0 && z.vz == 0) {
        y.vy = 0;
        y.vx = 0;
        y.vz = 0x1000;
    } else {
        y.vz = 0;
        y.vx = 0;
        y.vy = 0x1000;
    }
    x.vx = (y.vy * z.vz - y.vz * z.vy) / 4096;
    x.vy = (y.vz * z.vx - y.vx * z.vz) / 4096;
    x.vz = (y.vx * z.vy - y.vy * z.vx) / 4096;
    VectorNormalSS(&x, &x);
    y.vx = (z.vy * x.vz - z.vz * x.vy) / 4096;
    y.vy = (z.vz * x.vx - z.vx * x.vz) / 4096;
    y.vz = (z.vx * x.vy - z.vy * x.vx) / 4096;
    m->m[0][0] = x.vx;
    m->m[1][0] = x.vy;
    m->m[2][0] = x.vz;
    m->m[0][1] = y.vx;
    m->m[1][1] = y.vy;
    m->m[2][1] = y.vz;
    m->m[0][2] = z.vx;
    m->m[1][2] = z.vy;
    m->m[2][2] = z.vz;
}

/* Rotation matrix from a direction and an up vector: z = -normalize(dir), x = normalize(up x z).
 * mode 0 keeps up exact (z = x x up), mode 1 keeps dir exact (y = z x x). */
void Matrix_LookAt(SVEC_8001484C_80014A84 *dir, SVEC_8001484C_80014A84 *up, MAT_80014750_80014A84 *m, s32 mode) {
    SVEC_8001484C_80014A84 x;
    SVEC_8001484C_80014A84 y;
    SVEC_8001484C_80014A84 z;

    VectorNormalSS(dir, &z);
    VectorNormalSS(up, &y);
    z.vx = -z.vx;
    z.vy = -z.vy;
    z.vz = -z.vz;
    x.vx = (y.vy * z.vz - y.vz * z.vy) / 4096;
    x.vy = (y.vz * z.vx - y.vx * z.vz) / 4096;
    x.vz = (y.vx * z.vy - y.vy * z.vx) / 4096;
    VectorNormalSS(&x, &x);
    switch (mode) {
    case 0:
        z.vx = (x.vy * y.vz - x.vz * y.vy) / 4096;
        z.vy = (x.vz * y.vx - x.vx * y.vz) / 4096;
        z.vz = (x.vx * y.vy - x.vy * y.vx) / 4096;
        break;
    case 1:
        y.vx = (z.vy * x.vz - z.vz * x.vy) / 4096;
        y.vy = (z.vz * x.vx - z.vx * x.vz) / 4096;
        y.vz = (z.vx * x.vy - z.vy * x.vx) / 4096;
        break;
    }
    m->m[0][0] = x.vx;
    m->m[1][0] = x.vy;
    m->m[2][0] = x.vz;
    m->m[0][1] = y.vx;
    m->m[1][1] = y.vy;
    m->m[2][1] = y.vz;
    m->m[0][2] = z.vx;
    m->m[1][2] = z.vy;
    m->m[2][2] = z.vz;
}

/* Unpacks frame +0x5C of the model's animation data (+0x18, n + 2 packed words per frame) into
 * the joint rotations D_800F4B30 (10/12/10-bit angles) and its root offset into +0xC. */
void Anim_SetFrame(S_14D70_80014D70 *s) {
    u16 n = s->f_0->f_4;
    PK_80014D70 *frame = s->f_18 + (n + 2) * s->f_5C;
    s32 i;
    for (i = 0; i < n; i++) {
        ((struct S_D_800F4B30_80014D70 *)&D_800F4B30)[i].x = frame[2 + i].x << 2;
        ((struct S_D_800F4B30_80014D70 *)&D_800F4B30)[i].y = frame[2 + i].y << 2;
        ((struct S_D_800F4B30_80014D70 *)&D_800F4B30)[i].z = frame[2 + i].z << 2;
    }
    s->f_C->f_4 = frame[1].x;
    s->f_C->f_8 = frame[1].z;
    s->f_C->f_6 = frame[1].y;
}

/* Interpolates the model's pose for time f_5C within its current anim entry f_16C[f_5E]
 * (start time, frames per key, first key): blends key n and n+1 by the 12-bit fraction. */
void Anim_BlendCurrentEntry(Model_14E34_80014E34 *m) {
    AnimE_14E34_80014E34 *e = &m->f_16C[m->f_5E];
    s32 d = m->f_5C - e->f_0;
    s32 t = ((d << 12) / e->f_4) % 4096;
    d = d / e->f_4 + e->f_6;
    Anim_BlendFrameIndex(m, d, d + 1, t);
}

INCLUDE_ASM("asm/nonmatchings/game/80014750_anim", func_80014EF0);

/* Anim_BlendFrames between frames fa and fb of the model's animation data (m+0x18; each frame is
 * n + 2 words: header, root offset, n joint rotations). */
void Anim_BlendFrameIndex(Model_8001526C_80014FA0 *m, s32 fa, s32 fb, s32 t) {
    s32 i;
    s32 n = m->hdr->n;
    Frame_8001526C_80014FA0 *a = (Frame_8001526C_80014FA0 *)(m->anim + (n + 2) * fa);
    Frame_8001526C_80014FA0 *b = (Frame_8001526C_80014FA0 *)(m->anim + (n + 2) * fb);
    s32 u;
    s32 ra;
    s32 rb;

    for (i = 0; i < n; i++) {
        u = 0x1000 - t;
        ra = a->rot[i].x * 4;
        rb = b->rot[i].x * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].x = (ra * u + rb * t) / 4096;
        ra = a->rot[i].y * 4;
        rb = b->rot[i].y * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].y = (ra * u + rb * t) / 4096;
        ra = a->rot[i].z * 4;
        rb = b->rot[i].z * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].z = (ra * u + rb * t) / 4096;
    }
    m->root->x = (a->pos.x * (0x1000 - t) + b->pos.x * t) / 4096;
    m->root->z = (a->pos.z * (0x1000 - t) + b->pos.z * t) / 4096;
    m->root->y = (a->pos.y * (0x1000 - t) + b->pos.y * t) / 4096;
}

s32 func_80015240(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x18) + ((M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 4) + 2) * arg1 * 4);
}

/* Interpolate two animation frames by t (0..0x1000): each joint rotation (packed x:10, y:12,
 * z:10, in 4-unit steps) goes the short way round into D_800F4B30, the root offset into m->root. */
void Anim_BlendFrames(Model_8001526C_8001526C *m, Frame_8001526C_8001526C *a, Frame_8001526C_8001526C *b, s32 t) {
    s32 i;
    s32 n = m->hdr->n;
    s32 u;
    s32 ra;
    s32 rb;

    for (i = 0; i < n; i++) {
        u = 0x1000 - t;
        ra = a->rot[i].x * 4;
        rb = b->rot[i].x * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].x = (ra * u + rb * t) / 4096;
        ra = a->rot[i].y * 4;
        rb = b->rot[i].y * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].y = (ra * u + rb * t) / 4096;
        ra = a->rot[i].z * 4;
        rb = b->rot[i].z * 4;
        if (rb - ra > 0x800) {
            ra += 0x1000;
        } else if (rb - ra < -0x800) {
            rb += 0x1000;
        }
        D_800F4B30[i].z = (ra * u + rb * t) / 4096;
    }
    m->root->x = (a->pos.x * (0x1000 - t) + b->pos.x * t) / 4096;
    m->root->z = (a->pos.z * (0x1000 - t) + b->pos.z * t) / 4096;
    m->root->y = (a->pos.y * (0x1000 - t) + b->pos.y * t) / 4096;
}

void func_800154DC(void *arg0, SVECTOR *arg1) {
    *arg1 = *(SVECTOR *)((u8 *)arg0 + 0x1C);
}

typedef struct { s16 x; s16 y; s16 z; s16 pad; } Rot_8001526C;
typedef struct { u8 pad0[4]; u16 n; } Hdr_80015504;
typedef struct { u8 pad0[4]; s16 x; s16 y; s16 z; u16 parent; } Joint_80015504;
typedef struct {
    Hdr_80015504 *hdr; u8 pad4[8]; Joint_80015504 *joints; u8 pad10[4]; MAT_80014750 *mats; u8 pad18[4];
    s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 x; s32 y; s32 z;
} Model_80015504;
extern MAT_80014750 D_800F4730_15504[] asm("D_800F4730");
extern Rot_8001526C D_800F4B30_15504[] asm("D_800F4B30");
extern MAT_80014750 D_800E78C0_15504 asm("D_800E78C0");
void RotMatrixZYX_15504(void *r, void *m) asm("RotMatrixZYX");
void CompMatrix_15504(void *a, void *b, void *c) asm("CompMatrix");

/* Model_CalcJointMatrices: sets the root translation (added when flags bit 2), then for bit 1 builds
 * the joints' world matrices in D_800F4730 (joint 0 = root; +0x1C gets joint 1's position) and for
 * bit 0 the camera-space matrices in m->mats, each joint as RotMatrixZYX(angles) + offset
 * composed onto its parent. */
void Model_CalcJointMatrices(Model_80015504 *m, s32 flags) {
    s32 n = m->hdr->n;
    MAT_80014750 *mats = m->mats;
    Joint_80015504 *j;
    Joint_80015504 *k;
    s32 i;

    if (flags & 4) {
        mats->t[0] += m->x;
        mats->t[1] += m->y;
        mats->t[2] += m->z;
    } else {
        mats->t[0] = m->x;
        mats->t[1] = m->y;
        mats->t[2] = m->z;
    }
    if (flags & 2) {
        j = m->joints;
        D_800F4730_15504[0] = *mats;
        for (i = 0; i < n; i++, j++) {
            RotMatrixZYX_15504(&D_800F4B30_15504[i], &D_800F4730_15504[i + 1]);
            D_800F4730_15504[i + 1].t[0] = j->x;
            D_800F4730_15504[i + 1].t[1] = j->y;
            D_800F4730_15504[i + 1].t[2] = j->z;
            CompMatrix_15504(&D_800F4730_15504[j->parent], &D_800F4730_15504[i + 1], &D_800F4730_15504[i + 1]);
        }
        m->f_1C = D_800F4730_15504[1].t[0];
        m->f_1E = D_800F4730_15504[1].t[1];
        m->f_20 = D_800F4730_15504[1].t[2];
    }
    if (flags & 1) {
        k = m->joints;
        CompMatrix_15504(&D_800E78C0_15504, mats, mats);
        for (i = 0; i < n; k++, i++) {
            RotMatrixZYX_15504(&D_800F4B30_15504[i], &mats[i + 1]);
            mats[i + 1].t[0] = k->x;
            mats[i + 1].t[1] = k->y;
            mats[i + 1].t[2] = k->z;
            CompMatrix_15504(&mats[k->parent], &mats[i + 1], &mats[i + 1]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80014750_anim", func_80015780);

/* func_80015AC0 / func_80015B30 / func_80015BA0: bind a multi-part model (header h: +4 n4, +6 n6,
 * +8 n8, +0xA flag) to an object: +0 header, +4 data at h+0xC, +0xC after n8 words, +0x10 after
 * n8 + 3*n4 words, +8 = +0x10 + n6 entries of 8 bytes (AC0, monkeys by LOD), 16 bytes (B30, Spike)
 * or 8/16 by the header flag (BA0); +0x14 = D_800E9C60. Matched with the header re-read through
 * o->f_0 rather than the parameter. */
void func_80015AC0(S_HdrOut_80015AC0 *o, u8 *p) {
    S_Hdr_80015AC0 *q;
    s32 n;
    o->f_0 = (S_Hdr_80015AC0 *)p;
    o->f_C = p + (((S_Hdr_80015AC0 *)p)->f_8 * 4 + 0xC);
    n = o->f_0->f_8;
    q = o->f_0;
    p += (n + q->f_4 * 3) * 4 + 0xC;
    o->f_10 = p;
    q = o->f_0;
    o->f_8 = p + q->f_6 * 8;
    o->f_4 = (u8 *)o->f_0 + 0xC;
    o->f_14 = &(*(s32 *)&D_800E9C60);
}

void func_80015B30(S_HdrOut_80015B30 *o, u8 *p) {
    S_Hdr_80015B30 *q;
    s32 n;
    o->f_0 = (S_Hdr_80015B30 *)p;
    o->f_C = p + (((S_Hdr_80015B30 *)p)->f_8 * 4 + 0xC);
    n = o->f_0->f_8;
    q = o->f_0;
    p += (n + q->f_4 * 3) * 4 + 0xC;
    o->f_10 = p;
    q = o->f_0;
    o->f_8 = p + q->f_6 * 16;
    o->f_4 = (u8 *)o->f_0 + 0xC;
    o->f_14 = &(*(s32 *)&D_800E9C60);
}

void func_80015BA0(Out_80015BA0_80015BA0 *o, Hdr_80015BA0_80015BA0 *h) {
    Hdr_80015BA0_80015BA0 *q;
    s32 n;
    o->f_0 = h;
    o->f_C = (u8 *)h + (h->f_8 * 4 + 0xC);
    n = o->f_0->f_8;
    q = o->f_0;
    o->f_10 = (u8 *)h + ((n + q->f_4 * 3) * 4 + 0xC);
    o->f_4 = o->f_0->data;
    q = o->f_0;
    if (q->f_A != 0) {
        o->f_8 = o->f_10 + q->f_6 * 16;
    } else {
        o->f_8 = o->f_10 + q->f_6 * 8;
    }
    o->f_14 = D_800E9C60;
}

void Model_BindMesh(S_15C34_80015C34 *o, u32 *h)
{
  u32 fl;
  u8 *p;
  u8 *q;
  o->f_0 = h;
  fl = h[0];
  if (fl & 0xF0)
  {
    return;
  }
  o->f_4 = h + 6;
  p = (u8 *) o->f_0;
  q = p;
  p += (*((u16 *) (p + 0x10))) * 4;
 do { o->f_C = p; o->f_8 = q + ((*((u16 *) (q + 0x14))) * 4); } while (0);
  if (fl & 0x300000)
  {
    o->f_18 = 0;
    o->f_1A = 0;
    if (fl & 0x4000)
    {
      o->f_1A = 1;
    }
    if (fl & 0x8000)
    {
      o->f_1A |= 2;
    }
  }
}

/* Binds entry n of the stage mesh table (g_Game + 0x8224) to model m. */
void Model_BindStageMesh(void *arg0, s32 arg1) {
    Model_BindMesh(arg0, g_Game.f_8224 + (M2C_FIELD(((arg1 * 4) + g_Game.f_8224), u16 *, 4) * 4));
}

void func_80015D10(S_HdrOut_80015D10 *o, S_Hdr_80015D10 *h) {
    o->f_0 = h;
    o->f_8 = (s32 *)(h + 1) + (h->f_6 * 2 + h->f_8);
    o->f_C = (s32 *)(h + 1) + h->f_8;
    o->f_4 = (s32 *)(o->f_0 + 1);
}

void Light_SetColorMode(s32 mode, s32 r, s32 g, s32 b) {
    MAT_80014750_80015D58 *m;
    switch (mode) {
    case 0:
        SetBackColor(0, 0, 0);
        D_800EBFF0.m[0][0] = 0x1000;
        D_800EBFF0.m[1][0] = 0x1000;
        D_800EBFF0.m[2][0] = 0x1000;
        D_800EBFF0.m[0][1] = 0x1000;
        D_800EBFF0.m[1][1] = 0x1000;
        D_800EBFF0.m[2][1] = 0x1000;
        D_800EBFF0.m[0][2] = 0;
        D_800EBFF0.m[1][2] = 0;
        D_800EBFF0.m[2][2] = 0;
        SetColorMatrix(&D_800EBFF0);
        return;
    case 1:
        SetBackColor(0, 0, 0);
        if (((struct { u8 p[0x8000]; u8 q[0x27C]; u32 v; } *)&g_Game)->v >> 12 == mode) {
            D_800EBFF0.m[0][0] = 0xAAA;
            D_800EBFF0.m[1][0] = 0xAAA;
            D_800EBFF0.m[2][0] = 0x1000;
        } else {
            D_800EBFF0.m[0][0] = 0x1000;
            D_800EBFF0.m[1][0] = 0x1000;
            D_800EBFF0.m[2][0] = 0x1000;
        }
        D_800EBFF0.m[0][1] = 0x1000;
        D_800EBFF0.m[1][1] = 0x1000;
        D_800EBFF0.m[2][1] = 0x1000;
        D_800EBFF0.m[0][2] = 0;
        D_800EBFF0.m[1][2] = 0;
        D_800EBFF0.m[2][2] = 0;
        SetColorMatrix(&D_800EBFF0);
        return;
    case 2:
        Matrix_Copy((s32 *)&D_800E78E0, (s32 *)&D_800EBFF0);
        SetBackColor(0, 0, 0);
        D_800EBFF0.m[0][0] = r;
        D_800EBFF0.m[1][0] = g;
        D_800EBFF0.m[2][0] = b;
        D_800EBFF0.m[0][1] = 0x1000;
        D_800EBFF0.m[1][1] = 0x1000;
        D_800EBFF0.m[2][1] = 0x1000;
        D_800EBFF0.m[0][2] = 0;
        D_800EBFF0.m[1][2] = 0;
        D_800EBFF0.m[2][2] = 0;
        SetColorMatrix(&D_800EBFF0);
        return;
    case 3:
        Matrix_Copy((s32 *)&D_800EBFF0, (s32 *)&D_800E78E0);
        SetColorMatrix(&D_800E78E0);
        return;
    }
}

/* Copy a 0x20-byte MATRIX (rotation + translation) word by word. */
void Matrix_Copy(s32 *d, s32 *s) {
    s32 a, b, c;
    a = s[0]; b = s[1]; c = s[2];
    d[0] = a; d[1] = b; d[2] = c;
    a = s[3]; b = s[4];
    d[3] = a; d[4] = b;
    a = s[5]; b = s[6]; c = s[7];
    d[5] = a; d[6] = b; d[7] = c;
}
