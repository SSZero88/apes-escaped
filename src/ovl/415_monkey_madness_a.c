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

extern struct S_g_Game_8013D308 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D308 asm("g_Game");
s16 Sound_Play(s32, s32);

s32 func_8013D308(s16 *p) {
    u8 *e = g_Game_8013D308.f_8220 + p[4] * 0x18;

    p[3] = 0;
    if (M2C_FIELD(e, s16 *, 2) >= 2) {
        p[1] = 1;
    } else {
        p[1] = 0;
        p[11] = Sound_Play(1, 0x66);
    }
    return 0;
}

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
