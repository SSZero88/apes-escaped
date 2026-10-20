#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D028(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D050(void) {
    Pad_Vibrate(1, 0x78, 2);
}

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

void func_8013D078(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D10C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D1AC);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D324);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D43C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D57C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D708);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D804);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D810);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D860);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DE14);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DE38);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DEEC);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E4D8);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E500);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E650);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E8C0);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E8E4);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E97C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013EE04);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F4F0);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F520);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F694);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F848);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FC74);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FC8C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FD74);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140280);

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80141880");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D88(SVECTOR *arg0, s32 arg1) {
    s32 i;
    u16 x = arg0->vx;
    u16 y = arg0->vy;
    u16 z = arg0->vz;
    s16 floor = Floor_GetHeight(arg0->vx, arg0->vy, arg0->vz);

    for (i = 15; i >= 0; i--) {
        if (D_80144590_8013D028[i].life == 0) {
            D_80144590_8013D028[i].life = (RAND() >> 8 & 0x1F) + 0x28;
            D_80144590_8013D028[i].floor = floor;
            D_80144590_8013D028[i].x = x + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].y = y - ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].z = z + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].vx = ((RAND() >> 8) - 0x80) / 8;
            D_80144590_8013D028[i].vy = -(RAND() >> 8 & 0x1F) - 0x18;
            D_80144590_8013D028[i].vz = ((RAND() >> 8) - 0x80) / 8;
            if (--arg1 == 0) {
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140F78);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80141418);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8014149C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801414F8);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801416D8);

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6", D_80141850);
