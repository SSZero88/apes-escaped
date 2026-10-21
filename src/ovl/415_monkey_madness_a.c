#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D000);

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D0FC);

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D2A0);

s32 func_8013D300(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D308);

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D388);

s32 SaveByte_Get(s32);
void func_80010CDC(s32);

s32 func_8013D66C(void) {
    if (SaveByte_Get(8) == 5) {
        func_80010CDC(1);
    } else {
        func_80010CDC(0);
    }
    return 0;
}

/* the original text ends with three words of padding after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
