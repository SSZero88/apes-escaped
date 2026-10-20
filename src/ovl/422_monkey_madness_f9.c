#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern s16 g_SpikeHealth;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; } g_Game;

extern struct S_D_80144C18 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80144C18[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct S_D_80144FD8 { u8 pad_0[0x6]; s8 f_6; u8 pad_7[0x9]; } D_80144FD8[];
extern M2C_UNK D_801451D8;
extern s8 D_801452D8;
extern M2C_UNK D_801452E0;
extern M2C_UNK D_80145390;
extern s16 D_80144C0C;
M2C_UNK func_801406F8(M2C_UNK);
extern u16 g_RandSeed;
extern struct S_D_80144BE8 { u8 pad_0[0xC]; s8 f_C; u8 pad_D[0x3]; s16 f_10; } D_80144BE8;
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_80070284(s16 *, M2C_UNK *, M2C_UNK, M2C_UNK, s32);
M2C_UNK func_80142508(s32, M2C_UNK);
extern M2C_UNK D_801441B8;
extern struct S_D_80145430 { u8 pad_0[0x9]; s8 f_9; u8 pad_A[0x2]; } D_80145430[];

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D000);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D0A0);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D1FC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D33C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D450);

void func_8013D47C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80144C18[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80144C18");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D4A4(SVECTOR *arg0) {
    s32 i;
    s16 x = arg0->vx;
    s16 y = arg0->vy;
    s16 z = arg0->vz;

    for (i = 0x4F; i >= 0; i--) {
        D_80143F08_8013D554[i].life = (RAND() >> 8 & 0x1F) + 0x28;
        D_80143F08_8013D554[i].x = x + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].y = y - ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].z = z + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].vx = ((RAND() >> 8) - 0x80) / 2;
        D_80143F08_8013D554[i].vy = -(RAND() >> 8 & 0x3F) - 0x20;
        D_80143F08_8013D554[i].vz = ((RAND() >> 8) - 0x80) / 2;
    }
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D60C);

void func_8013D9DC(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DA04(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DA2C(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DA54(s32 arg0) {
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

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013DAE8);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013DD44);

void func_8013E070(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_80144FD8[i].f_6 = 0;
    }
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E098);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E22C);

void func_8013E4A8(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0xF;
    var_v0 = &D_801451D8;
    do {
        M2C_FIELD(var_v0, s8 *, 0xC) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x10));
    } while (var_v1 >= 0);
    D_801452D8 = 0;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E4D0);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E564);

void func_8013E7F8(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_801452E0;
    do {
        M2C_FIELD(var_v0, s8 *, 0x14) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x2C));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E81C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E8D4);

void func_8013F080(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_80145390;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x14));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F0A4);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F198);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F598);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F75C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F78C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F86C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F930);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F964);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F9FC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013FAA4);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140498);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140564);

void func_80140630(s16 arg0) {
    D_80144C0C = arg0;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8014063C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801406F8);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140738);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801407B4);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8014081C);

void func_801408AC(s32 arg0, s32 arg1) {
    u16 temp_v1;

    D_80144BE8.f_C = 0;
    func_801406F8(0);
    temp_v1 = (g_RandSeed * 5) + 1;
    D_80144BE8.f_10 = (s16) (arg0 + ((s32) (((u32) (temp_v1 & 0xFFFF) >> 8) * arg1) >> 8));
    g_RandSeed = temp_v1;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8014092C);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801409AC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140A20);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140A60);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80141F70);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801420BC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142310);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801423E8);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801424A0);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142508);

void func_80142528(s16 *arg0) {
    s16 temp_v1;
    s32 var_s0;

    temp_v1 = *arg0;
    var_s0 = 0;
    if (temp_v1 < -0x3E8) {
        var_s0 = 1;
    } else if (temp_v1 >= 0x3E9) {
        var_s0 = 2;
    }
    func_80142508(var_s0, 2);
    D_80145430[var_s0].f_9 = 0x32;
    func_80070284(arg0, &D_801441B8, 1, 0, 0);
    func_8013D4A4(arg0);
    Camera_StartShake(2);
    Sound_PlayFixed(0x80);
    Sound_PlayFixed(0x6C);
    Sound_PlayFixed(0x60);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801425EC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801428A4);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142924);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142A48);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142C40);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80143854);
