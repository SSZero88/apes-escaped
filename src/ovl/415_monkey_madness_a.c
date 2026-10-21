#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D000);

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D0FC);

extern struct S_g_Game { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0x116]; u8 *f_8238; } g_Game;
s32 SaveByte_Get(s32);

s32 func_8013D2A0(void) {
    if (g_Game.f_8120 == 0x13) {
        return 0;
    }
    if (SaveByte_Get(10) != 5) {
        M2C_FIELD(g_Game.f_8238, s32 *, 0xA0) = 4;
    }
    return 0;
}

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
