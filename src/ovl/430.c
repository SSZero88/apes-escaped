#include "common.h"
#include "m2c_macros.h"

extern M2C_UNK D_80138338;

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136000);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_8013626C);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136494);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136590);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136624);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136730);

void func_80136E58(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0x5F;
    var_v0 = &D_80138338;
    do {
        M2C_FIELD(var_v0, s8 *, 4) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0xC));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136E7C);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80137374);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_8013748C);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_801376EC);
