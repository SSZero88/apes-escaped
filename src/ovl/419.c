#include "common.h"
#include "m2c_macros.h"

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 4;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x4E3;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/419/nonmatchings/419", func_8013D020);

INCLUDE_ASM("asm/ovl/419/nonmatchings/419", func_8013D1C4);
