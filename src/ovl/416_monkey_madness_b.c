#include "common.h"
#include "m2c_macros.h"

extern struct S_D_80142368 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80142368[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142728;
s32 Sound_Play(M2C_UNK, s32);
M2C_UNK func_8013D440(M2C_UNK, M2C_UNK *, void *);
extern M2C_UNK D_80141D20;
extern M2C_UNK D_801421C0;
M2C_UNK func_8013EF0C(M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80142260;
extern struct S_D_80141880 { u8 pad_0[0x10]; s32 f_10; s32 f_14; } D_80141880;
extern M2C_UNK D_801418A0;

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D000);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D06C);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D2A0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D3F0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D440);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D4E0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D63C);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D77C);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D890);

void func_8013D8BC(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80142368[i].f_A = 0;
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D8E4);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DA4C);

void func_8013DE1C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DE44(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DE6C(void) {
    Pad_Vibrate(1, 0x78, 2);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DE94);

void func_8013DF28(void) {
    D_80142728 = -1;
}

void func_8013DF38(s32 arg0) {
    D_80142728 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013DF60(void *obj) {
    if (D_80142728 != -1) {
        Sound_Stop(obj, D_80142728);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DF90);

void func_8013E14C(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 7;
    var_s1 = &D_80141D20;
    var_s0 = (void *)((u8 *)&D_80141D20 + 0x7C);
    do {
        func_8013D440(2, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 -= 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x94));
        var_s1 = (void *)((u8 *)var_s1 + (0x94));
    } while (var_s2 >= 0);
}

void func_8013E1AC(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_80141D20;
    do {
        M2C_FIELD(var_v0, s8 *, 0x84) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x94));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E1D0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E2BC);

void func_8013EC5C(void) {
    func_8013D440(3, &D_801421C0, (void *)((u8 *)&D_801421C0 + 0x70));
    M2C_FIELD(&D_801421C0, s8 *, 0x78) = 0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EC94);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013ECD4);

void func_8013EE74(void) {
    func_8013EF00(1);
    func_8013EF0C(&D_80142260, 0);
    D_80141880.f_14 = 0x1E;
    D_80141880.f_10 = 0;
}

M2C_UNK Sound_PlayFixed(M2C_UNK);

void func_8013EEB8(void) {
    M2C_FIELD(&D_80141880, s8 *, 0) = 0;
    func_8013EE74();
    M2C_FIELD(&D_80141880, s32 *, 0x18) = 0;
    M2C_FIELD(&D_80141880, s32 *, 0x14) = 0x5A;
    func_8013DF38(0xB1);
    Sound_PlayFixed(4);
}

extern s8 D_80141881;

void func_8013EF00(s8 arg0) {
    D_80141881 = arg0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EF0C);

void func_8013EF44(void *arg0) {
    u16 temp_a0;
    u16 temp_v1;
    void *temp_a2;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((temp_v1 & 0xFFFF) == M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74)), u16 *, 2)) {
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
    }
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x5C);
    temp_a2 = (M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    if ((u16) M2C_FIELD(temp_a2, u16 *, 2) < temp_a0) {
        if (M2C_FIELD(arg0, u8 *, 0x7B) == 1) {
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (temp_a0 - 1);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a2, u16 *, 0);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EFCC);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F0E0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F1AC);

void func_8013F544(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    var_s1 = &D_801418A0;
    var_s0 = (void *)((u8 *)&D_801418A0 + 0x7C);
    do {
        func_8013D440(1, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x90));
        var_s1 = (void *)((u8 *)var_s1 + (0x90));
    } while (var_s2 < 8);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F5A8);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F6F8);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F954);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013FA2C);
