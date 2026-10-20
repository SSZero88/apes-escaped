#include "common.h"
#include "m2c_macros.h"

void Object_SetAnim(void *, u8, u8);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

void func_8013D000(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        Object_SetAnim(arg0, 2, 1);
        Object_PlaySound(arg0, 0xAC);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D04C);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D1BC);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D2B0);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D368);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D77C);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D8A4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D8F8);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D9C4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DAFC);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DBF4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DC70);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DD94);

void func_8013DE4C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 7;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x1C);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DE84);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DF60);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E004);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E058);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E134);

void func_8013E9EC(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013EA38);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013ED30);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013ED9C);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013EE80);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013EEF0);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013EFE4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F08C);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F1D8);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F264);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F330);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F400);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F574);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F5D4);
