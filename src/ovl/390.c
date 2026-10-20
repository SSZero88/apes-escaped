#include "common.h"
#include "m2c_macros.h"

M2C_UNK Seq_Tick();
M2C_UNK func_8001300C();
M2C_UNK func_80088578();
M2C_UNK func_80141B34();
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_80139A68();
M2C_UNK func_80139CF0();
s32 func_8013A400();
s32 func_8013A43C();
M2C_UNK func_8013FB30(s16);
extern s32 D_800E5488;
extern s16 D_8013AF52;
extern s16 D_8013AF66;
extern s16 D_8013AF6C;
M2C_UNK MemCard_Request(M2C_UNK, M2C_UNK);
extern s16 D_8013AF56;
extern struct S_D_800E3880 { s16 f_0; u8 pad_2[0x4]; s16 f_6; s16 f_8; } D_800E3880;
M2C_UNK func_80136160(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136000);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136120);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136160);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136554);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801368E8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136A88);

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390", D_8013A9CC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136AB8);

void func_80136D58(void) {
    func_8001300C();
    Seq_Tick();
    func_80088578();
    func_80141B34();
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136D90);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136ED8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137104);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013730C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137424);

s16 func_80137454(void) {
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v0_2;

    func_8013FB30(D_8013AF52);
    func_80139CF0();
    func_80139A68();
    if (D_8013AF66 == 1) {
        if (func_8013A43C() != 0) {
            Sound_PlayFixed(1);
            return 3;
        }
        if (func_8013A400() != 0) {
            Sound_PlayFixed(3);
            return D_8013AF52;
        }
        temp_a0 = D_8013AF6C == 0;
        if (D_800E5488 == 0x8000) {
            temp_v0 = (u16) D_8013AF52 - 1;
            D_8013AF52 = temp_v0;
            if (temp_v0 < temp_a0) {
                D_8013AF52 = temp_a0;
            } else {
                Sound_PlayFixed(0);
            }
        }
        if (D_800E5488 == 0x2000) {
            temp_v0_2 = (u16) D_8013AF52 + 1;
            D_8013AF52 = temp_v0_2;
            if (temp_v0_2 >= 3) {
                D_8013AF52 = 2;
            } else {
                Sound_PlayFixed(0);
            }
        }
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013758C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801377F8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013784C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137C84);

s32 func_80137DA8(s32 arg0) {
    M2C_UNK var_a0;

    MemCard_Request(8, 0);
    MemCard_Request(7, 0);
    D_800E3880.f_6 = 0;
    D_800E3880.f_8 = 0;
    D_800E3880.f_0 = 1;
    if (arg0 == 0) {
        D_8013AF56 = 0;
        var_a0 = 0;
    } else {
        var_a0 = 0x11;
    }
    MemCard_Request(var_a0, 0);
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137E1C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137E4C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013829C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801383E0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801384BC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80138524);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801385EC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801386CC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80138744);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801387FC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013888C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80138DC0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801391B0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013946C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139570);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801399E4);

s32 func_80139A3C(void) {
    func_80136160(0xC, 0x14, 0x160, 0xC4);
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139A68);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139CF0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139F08);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139FC8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A400);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A43C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A478);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A634);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A70C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A804);
