#include "common.h"
#include "m2c_macros.h"

M2C_UNK Model_BindStageMesh(s32, s16);
M2C_UNK Stage_CountCaughtMonkeys(s32 *);
extern s32 D_800B4D64;
M2C_UNK Collision_Set(M2C_UNK, void *, M2C_UNK *);
extern struct S_D_8013DCE0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x8]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[0x14]; s16 f_60; s16 f_62; s16 f_64; } D_8013DCE0;
s32 SpecterCoin_Count();
s32 func_800964B0(M2C_UNK);

s32 func_8013D000(void *arg0) {
    s32 sp10;
    s32 var_s0;

    if ((M2C_FIELD(arg0, s16 *, 0xC) >= 0) && (M2C_FIELD(arg0, s16 *, 0xE) >= 0)) {
        Stage_CountCaughtMonkeys(&sp10);
        var_s0 = 0;
        if (M2C_FIELD(arg0, s16 *, 8) > 0) {
            do {
                if (var_s0 < sp10) {
                    Model_BindStageMesh(D_800B4D64 + ((M2C_FIELD(arg0, s16 *, 0xC) + var_s0) << 5), M2C_FIELD(arg0, s16 *, 0xE));
                }
                var_s0 += 1;
            } while (var_s0 < M2C_FIELD(arg0, s16 *, 8));
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D0B4);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D158);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D208);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D5C0);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D7E8);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D8A8);

s32 func_8013D8F8(void *arg0) {
    D_8013DCE0.f_44 = 0x40;
    D_8013DCE0.f_46 = 0x100;
    D_8013DCE0.f_30 = 0;
    D_8013DCE0.f_34 = 0;
    D_8013DCE0.f_38 = 0;
    D_8013DCE0.f_48 = 0;
    D_8013DCE0.f_4A = 0;
    D_8013DCE0.f_60 = 0x1000;
    D_8013DCE0.f_62 = 0;
    D_8013DCE0.f_64 = 0;
    D_8013DCE0.f_24 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x10);
    D_8013DCE0.f_28 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x12);
    D_8013DCE0.f_2C = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x14);
    Collision_Set(3, (void *)((u8 *)&D_8013DCE0 + 0x24), &D_8013DCE0);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) D_8013DCE0.f_28;
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013D9D4);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013DB30);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013DD64);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013DDDC);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013DE28);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013DEFC);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013E014);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013E0E8);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013E178);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013E280);

s32 func_8013E2DC(void) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = SpecterCoin_Count();
    if (func_800964B0(0x13) & 0x10) {
        var_s0 += 5;
    }
    var_v0 = var_s0;
    if (func_800964B0(0x24) & 0x10) {
        var_v0 = var_s0 + 5;
    }
    return var_v0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426", func_8013E334);
