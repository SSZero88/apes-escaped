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

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_ProjectVertsAlt);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_ProjectVerts);

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

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_DrawLit);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4598);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4598_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddFT4);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", Model_AddGT4);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001C2E8);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4610);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4610_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001C918);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4688);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4688_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001CE54);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4700);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4700_pad);


void func_8001D4A8(S_1D4A8_8001D4A8 *a, s32 n) {
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

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001D530);

INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4778);
INCLUDE_RODATA("asm/nonmatchings/game/80015F70_model", jtbl_800A4778_pad);


INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001DB74);

INCLUDE_ASM("asm/nonmatchings/game/80015F70_model", func_8001E828);
