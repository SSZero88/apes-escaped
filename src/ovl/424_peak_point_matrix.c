#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; } g_Game;

extern struct S_D_801423D8 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_801423D8[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142798;
s32 Sound_Play(M2C_UNK, s32);
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80141F88;
extern M2C_UNK D_801427A0;
extern M2C_UNK D_801427C0;
extern s8 D_80142320;
extern M2C_UNK D_80142940;
extern struct S_D_801429C0 { u8 pad_0[0xB]; s8 f_B; } D_801429C0[];
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Effect_SpawnAt(M2C_UNK, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_801407E4(M2C_UNK, M2C_UNK);
M2C_UNK func_8013D000(M2C_UNK, M2C_UNK *, void *);
void func_8013FFFC(void);
extern s8 D_80142322;
extern M2C_UNK D_80142338;
M2C_UNK Puff_Spawn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8013DFB0(s32 arg0);
M2C_UNK func_8013EEC0(void *, M2C_UNK);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D000);

#include "gte.h"
typedef struct { u8 pad0[0x8]; u16 n; u8 padA[2]; s32 rgb[1]; } MdlHdr_422;
typedef struct { MdlHdr_422 *hdr; s32 *f_4; u8 *prims; } Mdl_422;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_422;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;
void Model_DrawPrims(s32, u8 *, s32);

void func_8013D0A0(s32 ot, s32 arg1, Mdl_422 *m, s32 add) {
    s32 i;
    u8 *c;
    s32 *src;
    Scr_422 *sc = (Scr_422 *)0x1F800000;

    c = m->prims;
    if (add == 0) {
        src = m->hdr->rgb;
        for (i = 0; i < m->hdr->n; i++) {
            gte_ldIR(0x1000, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2_mem(&sc->rgb[i]);
        }
    } else {
        src = m->hdr->rgb;
        for (i = 0; i < m->hdr->n; i++) {
            gte_ldIR(0x800, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2(&sc->rgb[i]);
            sc->rgb[i] += add;
        }
    }
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    sc->f_3F4 = 6;
    sc->f_3C0 = D_800EBFA0.f_24;
    sc->f_3C2 = D_800EBFA0.f_28;
    Model_DrawPrims(ot, c, arg1);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D1FC);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D310);

void func_8013D33C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_801423D8[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_801423D8");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D364(SVECTOR *arg0) {
    s32 i;
    s16 x = arg0->vx;
    s16 y = arg0->vy;
    s16 z = arg0->vz;

    for (i = 0x4F; i >= 0; i--) {
        D_80143F08_8013D554[i].life = (RAND() >> 8 & 0x1F) + 0x28;
        D_80143F08_8013D554[i].x = x + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].y = y - ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].z = z + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].vx = ((RAND() >> 8) - 0x80) / 2;
        D_80143F08_8013D554[i].vy = -(RAND() >> 8 & 0x3F) - 0x20;
        D_80143F08_8013D554[i].vz = ((RAND() >> 8) - 0x80) / 2;
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D4CC);

void func_8013D89C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D8C4(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D8EC(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013D914(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

void func_8013D9A8(void) {
    D_80142798 = -1;
}

void func_8013D9B8(s32 arg0) {
    D_80142798 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013D9E0(void *obj) {
    if (D_80142798 != -1) {
        Sound_Stop(obj, D_80142798);
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013DA10);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013DB94);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013DDC4);

void func_8013DFB0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0x10;
    do {
        Effect_Spawn(0xC9, arg0, &D_80141F88, 0);
        Effect_Spawn(0xCA, arg0, &D_80141F88, 0);
        var_s0 -= 1;
    } while (var_s0 > 0);
}

void func_8013E020(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0;
    var_v0 = &D_801427A0;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x1C));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E044);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E120);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E4B4);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E8A8);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EA24);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EA9C);

void func_8013EE9C(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0x1F;
    var_v0 = &D_801427C0;
    do {
        M2C_FIELD(var_v0, s8 *, 6) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0xC));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EEC0);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013F06C);

void func_8013F370(void) {
    D_80142320 = 0;
    func_8013F398(1);
}

extern s8 D_80142321;

void func_8013F398(s8 arg0) {
    D_80142321 = arg0;
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013F3A4);

void func_8013F3DC(void *arg0) {
    u16 temp_a0;
    u16 temp_v1;
    void *temp_a2;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((temp_v1 & 0xFFFF) == M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74)), u16 *, 2)) {
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
    }
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x5C);
    temp_a2 = (M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    if ((u16) M2C_FIELD(temp_a2, u16 *, 2) < temp_a0) {
        if (M2C_FIELD(arg0, u8 *, 0x7B) == 1) {
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (temp_a0 - 1);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a2, u16 *, 0);
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013F464);

void func_8013FFFC(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_80142940;
    do {
        M2C_FIELD(var_v0, s8 *, 0xB) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x20));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_80140020);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_801400F4);

void func_80140794(void) {
    Pad_Vibrate(1, 0xAA, 6);
}

void func_801407BC(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_801429C0[i].f_B = 0;
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_801407E4);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_801409D4);

void func_80140E70(void) {
    func_8013D000(1, &D_80142338, (void *)((u8 *)&D_80142338 + 0x74));
    M2C_FIELD(&D_80142338, s32 *, 0x28) = -0xA00;
    M2C_FIELD(&D_80142338, s8 *, 0x7E) = 5;
    M2C_FIELD(&D_80142338, s8 *, 0x7C) = 1;
    M2C_FIELD(&D_80142338, s16 *, 0x92) = 0xF;
    M2C_FIELD(&D_80142338, s16 *, 0x8E) = 0x78;
    M2C_FIELD(&D_80142338, s16 *, 0x94) = -0x100;
    M2C_FIELD(&D_80142338, s16 *, 0x98) = -0x100;
    M2C_FIELD(&D_80142338, s16 *, 0x44) = 0x80;
    M2C_FIELD(&D_80142338, s16 *, 0x86) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x90) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x9E) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x9C) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x96) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x46) = 0x100;
    func_8013FFFC();
    D_80142322 = 0;
}

void func_80140F08(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x8E) = 0x168;
    M2C_FIELD(arg0, s16 *, 0x92) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0x80;
    func_801407E4(arg1, 0x20);
    Effect_SpawnAt(0x112, arg1);
    Sound_PlayFixed(0x92);
    Camera_StartShake(1);
}

void func_80140F68(void *arg0, M2C_UNK arg1) {
    s32 var_s0;

    var_s0 = 3;
    do {
        Puff_Spawn(arg1, 0, 0x101, 0x800);
        var_s0 -= 1;
    } while (var_s0 > 0);
    func_8013DFB0(arg1);
    M2C_FIELD(arg0, s16 *, 0x92) = 0xF;
    M2C_FIELD(arg0, s16 *, 0x8E) = 0x1E;
    func_8013EEC0(arg0, 0);
    Camera_StartShake(1);
    Sound_PlayFixed(0x27);
    Sound_PlayFixed(0x92);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_80140FFC);
