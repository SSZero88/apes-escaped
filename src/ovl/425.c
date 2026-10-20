#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013D010);

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013D290);

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013D424);

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013D5C4);

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013D730);

void func_8013DAA0(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ovl/425/nonmatchings/425", func_8013DAEC);
