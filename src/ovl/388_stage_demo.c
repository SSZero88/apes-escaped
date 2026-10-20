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

INCLUDE_ASM("asm/ovl/388/nonmatchings/388_stage_demo", func_80136350);
