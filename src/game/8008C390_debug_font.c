#include "common.h"
#include "m2c_macros.h"

extern struct { u8 pad0[0x82BA]; s16 unk82BA; } g_Game;
void DebugFont_Printf(void);

extern struct S_D_800DF7D8 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; u8 f_20; u8 f_21; u8 f_22; } D_800DF7D8;



INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A6460);

void func_8008C390(void) {
    D_800DF7D8.f_0 = 0;
    D_800DF7D8.f_4 = 0x10;
    D_800DF7D8.f_8 = 0;
    D_800DF7D8.f_C = 0;
    D_800DF7D8.f_20 = 0x80;
    D_800DF7D8.f_21 = 0x80;
    D_800DF7D8.f_22 = 0x80;
}

void func_8008C3C0(s32 arg0, s32 arg1) {
    D_800DF7D8.f_0 = arg0;
    D_800DF7D8.f_4 = arg1;
    D_800DF7D8.f_8 = 0;
    D_800DF7D8.f_C = 0;
}

void func_8008C3DC(void) {
    D_800DF7D8.f_10 = (s32) D_800DF7D8.f_0;
    D_800DF7D8.f_14 = (s32) D_800DF7D8.f_4;
    D_800DF7D8.f_18 = (s32) D_800DF7D8.f_8;
    D_800DF7D8.f_1C = (s32) D_800DF7D8.f_C;
}

void func_8008C408(void) {
    D_800DF7D8.f_0 = (s32) D_800DF7D8.f_10;
    D_800DF7D8.f_4 = (s32) D_800DF7D8.f_14;
    D_800DF7D8.f_8 = (s32) D_800DF7D8.f_18;
    D_800DF7D8.f_C = (s32) D_800DF7D8.f_1C;
}

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_PutChar);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_Printf);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawBox);

void func_8008CBFC(s32 a0, ...) {
    s32 old = g_Game.unk82BA;
    g_Game.unk82BA = 1;
    DebugFont_Printf();
    func_8008C3C0(0, 0);
    g_Game.unk82BA = old;
}

void func_8008CC60(s32 arg0, s32 arg1) {
    func_8008C3C0(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawWord);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawIcon);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", func_8008D064);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", MinigameMenu_Main);

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A6464);


INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", MinigameMenu_Update);

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A646C);
INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A647C);

