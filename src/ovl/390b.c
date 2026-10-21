#include "common.h"
#include "m2c_macros.h"

extern s16 D_800E3880;
extern s16 D_8013C5B4;
void func_8013784C(s32, s32);

s32 func_8013B400(void) {
    switch (D_800E3880) {
    case 0:
        func_8013784C(1, D_8013C5B4);
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2C, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B47C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B550);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B6C4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013BC64);
