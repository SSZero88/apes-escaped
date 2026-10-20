#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 func_8013D1CC();
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D000);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D0D0);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D1CC);

void func_8013D200(void *arg0) {
    if (func_8013D1CC() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D254);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D2BC);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D49C);

void func_8013D514(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D5F0);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D670);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D714);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D950);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D9A4);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DA34);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DAFC);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DC70);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DD08);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DDD8);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DE90);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DFAC);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E170);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E208);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E3A4);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E4A8);

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E54C);
