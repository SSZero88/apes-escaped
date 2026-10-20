#include "common.h"
#include "m2c_macros.h"

M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_80139B6C;
extern struct S_g_Game { u8 pad_0[0x8126]; u16 f_8126; } g_Game;

M2C_UNK func_8008DDB0(s16, s16);
M2C_UNK func_8008DDC8(s32);
extern M2C_UNK D_80139B20;

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80136000);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801361D8);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80136208);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801368FC);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801372D0);

void func_801373F8(s32 arg0) {
    func_8008DDB0(M2C_FIELD(&D_80139B20, s16 *, 0), M2C_FIELD(&D_80139B20, s16 *, 2));
    func_8008DDC8(arg0);
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137438);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801374C8);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137CA8);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137D20);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137DC4);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137F4C);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138258);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_8013836C);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801384A0);

void func_80138660(void) {
    s32 var_a0;

    if (g_Game.f_8126 == 0xFF) {
        var_a0 = 0x17;
        goto block_3;
    }
    var_a0 = D_80139B6C;
    if (var_a0 != 0) {
block_3:
        Cd_PlayXaTrack(var_a0);
    }
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801386B8);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138A9C);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138B0C);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138C24);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138E20);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80138F38);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801392B0);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_8013939C);
