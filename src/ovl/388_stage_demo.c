#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_801361D0(M2C_UNK);
extern struct S_g_Game { u8 pad_0[0x8120]; s16 f_8120; } g_Game;

s32 func_80136000(void) {
    func_801361D0(0);
    g_Game.f_8120 = 9;
    return 0;
}

INCLUDE_ASM("asm/ovl/388/nonmatchings/388_stage_demo", func_80136038);

INCLUDE_ASM("asm/ovl/388/nonmatchings/388_stage_demo", func_801361D0);

extern u8 D_801363E8[];
extern u8 D_801363FC[];
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136350 asm("g_Pad");
void func_8008C3C0(s32, s32);
void DebugFont_Printf(u8 *, ...);
void Sound_PlayFixed(s32);

s32 func_80136350(s32 n) {
    func_8008C3C0(0x82, 0x46);
    DebugFont_Printf(D_801363E8, n);
    func_8008C3C0(0x82, 0xD2);
    DebugFont_Printf(D_801363FC);
    if (g_Pad_80136350.f_158 & g_Pad_80136350.f_160 & 0x800) {
        Sound_PlayFixed(2);
        return -1;
    }
    return 0;
}
