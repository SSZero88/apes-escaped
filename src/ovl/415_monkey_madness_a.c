#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/415/nonmatchings/415_monkey_madness_a", func_8013D000);

extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0xA]; u8 f_812C; u8 pad_812D[0xDF]; u8 *f_820C; } g_Game_8013D0FC asm("g_Game");
extern s32 D_800EC250;
s32 SaveByte_Get(s32);
s32 Overlay_GetState_8013D0FC(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 func_800863B0(s32, s32);
s32 func_8008FC30(s16, void *);

s32 func_8013D0FC(s16 *p) {
    s32 x;
    s32 t;
    u8 *e;

    if (g_Game_8013D0FC.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        x = SaveByte_Get(5);
        if (x != 5) {
            return 0;
        }
        if (SaveByte_Get(4) != x) {
            return 0;
        }
        if (g_Game_8013D0FC.f_812C != 3) {
            return 0;
        }
        t = D_800EC250 & 0xF0;
        if (t != 0x10 && t != 0x20 && t != 0x30) {
            return 0;
        }
        p[1] = 1;
        p[3] = 0;
        e = g_Game_8013D0FC.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        func_800863B0(2, 0x28);
        Overlay_Request(6);
        return 0;
    case 1:
        if (Overlay_GetState_8013D0FC() != 0) {
            return 0;
        }
        func_800863B0(0, 0);
        p[1] = 3;
        break;
    case 2:
    case 3:
    case 4:
        if (SaveByte_Get(8) != 5) {
            return 0;
        }
        p[1] = 5;
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        break;
    case 5:
        break;
    }
    return 0;
}

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
