#include "common.h"
#include "m2c_macros.h"

extern void *D_8013FD60;
extern struct S_D_8013F3E0 { u8 *f_0; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s32 f_C; s32 f_10; u8 *f_14; u8 pad18[4]; s32 f_1C; u8 pad20[0xC]; s32 f_2C; s32 f_30; } D_8013F3E0;
M2C_UNK Seq_Tick();
M2C_UNK func_80088578();
extern struct S_D_8013FC80 { u16 f_0; u8 pad_2[0x6]; s32 f_8; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; u16 f_16; } D_8013FC80;
extern s32 D_8013FB98;
s32 func_8008C09C(M2C_UNK);
extern M2C_UNK D_8013FCE0;
extern void *D_8013FCE4;
extern s32 D_8013FBF0;
extern struct S_D_8013F418 { s32 f_0; u8 pad_4[0x74]; } D_8013F418[];
extern M2C_UNK D_8013FC08;
extern M2C_UNK D_8013FD70;
extern struct S_D_8013FCF0 { u8 pad_0[0x6]; s16 f_6; u8 pad_8[0x4]; } D_8013FCF0[];
extern s32 D_8013FD2C;
extern struct S_D_8013FE60 { u8 pad_0[0x24]; s32 f_24; s32 f_28; u8 pad_2C[0x6C]; s32 f_98; s32 f_9C; u8 pad_A0[0x6C]; s32 f_10C; s32 f_110; u8 pad_114[0x6C]; s32 f_180; s32 f_184; u8 pad_188[0x6C]; s32 f_1F4; s32 f_1F8; } D_8013FE60;
extern s16 D_8013FD40;
extern M2C_UNK D_8013FD58;
M2C_UNK Msg_PutChar(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8008DDB0(s16, s16);
void func_80138350(s32 arg0);
M2C_UNK func_801384CC(s32, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_8013EF8C;
M2C_UNK func_80138368(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
M2C_UNK func_8013E940(M2C_UNK, M2C_UNK, s32);
extern M2C_UNK D_8013EB60;
extern M2C_UNK D_8013EB6C;
extern M2C_UNK D_8013EFC8;

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80136000);

void func_8013609C(void) {
    D_8013F3E0.f_2C = 0xC350;
    D_8013F3E0.f_30 = 0x4E20;
    M2C_FIELD(D_8013FD60, s32 *, 4) = 0xC350;
    M2C_FIELD(D_8013FD60, s32 *, 8) = 0x4E20;
}

void func_801360C8(void) {
    M2C_FIELD(D_8013FD60, s32 *, 4) = (s32) D_8013F3E0.f_2C;
    M2C_FIELD(D_8013FD60, s32 *, 8) = (s32) D_8013F3E0.f_30;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801360F0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013626C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801364CC);

void func_801365A8(void) {
    Seq_Tick();
    func_80088578();
}

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EA90);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801365D0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80136704);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAAC);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAB0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801369F4);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD0);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD4);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD8);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAE8);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAEC);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAF0);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB00);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB08);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB10);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", jtbl_8013EB18);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB60);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB6C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80136F30);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB94);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB9C);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", jtbl_8013EBA8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137654);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137874);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137934);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137F50);

void func_801380B4(void) {
    s32 var_v1;
    void *var_v0;

    D_8013FC80.f_14 = 0;
    var_v1 = 5;
    var_v0 = (void *)((u8 *)&D_8013FC80.f_0 + 0x3C);
    do {
        M2C_FIELD(var_v0, s16 *, 0x20) = 0;
        var_v1 -= 1;
        var_v0 -= 0xC;
    } while (var_v1 >= 0);
}

void func_801380E0(s16 arg0, s16 arg1, s32 arg2, s16 arg3) {
    D_8013FC80.f_C = arg0;
    D_8013FC80.f_E = arg1;
    D_8013FC80.f_8 = arg2;
    D_8013FC80.f_10 = arg3;
    D_8013FC80.f_14 = 1;
    D_8013FC80.f_12 = 0;
    D_8013FC80.f_16 = (u16) D_8013FC80.f_0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138110);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013825C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801382C0);

void func_80138350(s32 arg0) {
    D_8013FC80.f_0 = ((arg0 + 0xF0) << 6) | 0x37;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138368);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801384CC);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801385B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801385F4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138860);

void func_80138934(void) {
    s32 *var_v0;
    s32 var_v1;

    var_v0 = &D_8013FB98;
    var_v1 = 0xF;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (4));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138958);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801389E4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138C30);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138FD4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139098);

void func_80139444(void) {
    M2C_FIELD(&D_8013FCE0, s32 *, 0) = func_8008C09C(0x120);
    M2C_FIELD(&D_8013FCE0, s32 *, 4) = func_8008C09C(0x180);
}

void func_80139480(void) {
    s32 var_v0;
    void *var_v1;

    var_v1 = D_8013FCE0;
    var_v0 = 0x17;
    do {
        M2C_FIELD(var_v1, s8 *, 7) = 0;
        var_v0 -= 1;
        var_v1 += 0xC;
    } while (var_v0 >= 0);
}

void func_801394A4(void) {
    s32 var_v0;
    void *var_v1;

    var_v1 = D_8013FCE4;
    var_v0 = 0x1F;
    do {
        M2C_FIELD(var_v1, s8 *, 7) = 0;
        var_v0 -= 1;
        var_v1 += 0xC;
    } while (var_v0 >= 0);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801394C8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801395B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013966C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801396F4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013978C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139840);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139888);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139A74);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139BF8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139F80);

void func_8013A29C(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_8013F418[i].f_0 = 0;
    }
    D_8013FBF0 = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A2C8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A548);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A6CC);

void func_8013A760(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 *var_a0;
    s32 *var_a1;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_a2 = (s32) (arg2 + 3) >> 2;
    var_v1 = 0;
    if (temp_a2 > 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 = (void *)((u8 *)var_a1 + (4));
            var_v1 += 1;
            *var_a0 = temp_v0;
            var_a0 = (void *)((u8 *)var_a0 + (4));
        } while (var_v1 < temp_a2);
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A794);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A8C0);

typedef struct { u8 pad0[0xD]; u8 f_D; u8 padE[0x1A]; s32 f_28; u8 pad2C[4]; s16 f_30; u8 pad32[6]; } A_427;
typedef struct { u8 pad0[0x54]; s32 f_54; u8 pad58[0x1C]; } B_427;
extern A_427 D_8013FC08_8013AE1C[] asm("D_8013FC08");
extern B_427 D_8013FD70_8013AE1C[] asm("D_8013FD70");

void func_8013AE1C(s32 i) {
    A_427 *a = &D_8013FC08_8013AE1C[i];
    B_427 *b = &D_8013FD70_8013AE1C[i];

    a->f_D = 0;
    b->f_54 = 0;
    a->f_30 = 3;
    a->f_28 = 0;
}

void func_8013AE64(s32 arg0) {
    s32 var_v0;
    void *temp_a0;
    void *temp_v1;

    temp_v1 = (void *)((u8 *)&D_8013FD70 + (arg0 * 0x74));
    temp_a0 = (void *)((u8 *)&D_8013FC08 + (arg0 * 0x38));
    if (M2C_FIELD(temp_a0, s16 *, 0x30) <= 0) {
        M2C_FIELD(temp_a0, s8 *, 0xD) = 0;
        return;
    }
    M2C_FIELD(temp_a0, s16 *, 0x30) = (s16) ((u16) M2C_FIELD(temp_a0, s16 *, 0x30) - 1);
    M2C_FIELD(temp_v1, s32 *, 0x54) = 0;
    if (arg0 == 0) {
        M2C_FIELD(temp_v1, s32 *, 0x24) = 0x1F4;
        var_v0 = 0x12C;
    } else {
        M2C_FIELD(temp_v1, s32 *, 0x24) = -0x1F4;
        var_v0 = -0x3C;
    }
    M2C_FIELD(temp_v1, s32 *, 0x28) = var_v0;
    M2C_FIELD(temp_v1, s32 *, 0x2C) = 0x3D8;
    M2C_FIELD(temp_v1, s16 *, 0x6A) = 0x1000;
    M2C_FIELD(temp_v1, s16 *, 0x64) = -0x1000;
    M2C_FIELD(temp_v1, s16 *, 0x68) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x6C) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x60) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x62) = 0;
    M2C_FIELD(temp_a0, s8 *, 0xD) = 2;
    M2C_FIELD(temp_a0, s8 *, 0xE) = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013AF14);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013AFC0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B14C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B444);

extern u8 D_8013F184[];

void func_8013B4B4(void) {
    D_8013F3E0.f_0 = D_8013F184;
    D_8013F3E0.f_6 = 0x1000;
    D_8013F3E0.f_14 = "LEVEL 000";
    D_8013F3E0.f_C = 0;
    D_8013F3E0.f_4 = 0;
    D_8013F3E0.f_8 = 0;
    D_8013F3E0.f_10 = 0;
    D_8013F3E0.f_1C = 0x12C;
}

s32 func_8013B4F8(void) {
    s32 *var_a0;
    s32 var_a1;
    s32 var_v1;

    var_a0 = &D_8013F418;
    var_a1 = 0;
    var_v1 = 0xF;
    do {
        if (*var_a0 != 0) {
            var_a1 += 1;
        }
        var_v1 -= 1;
        var_a0 = (void *)((u8 *)var_a0 + (0x78));
    } while (var_v1 >= 0);
    return var_a1;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B530);

void func_8013B890(void) {
    s32 i;

    for (i = 4; i >= 0; i--) {
        D_8013FCF0[i].f_6 = 0;
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B8B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B92C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013BAC0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013BC28);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013BE5C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013C0E4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013C368);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013C4D4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013C5F0);

void func_8013C7F0(void) {
    D_8013FD2C = 0;
}

extern u8 D_8013FD2C_8013C7FC[] asm("D_8013FD2C");

void func_8013C7FC(s32 i, u8 v) {
    D_8013FD2C_8013C7FC[i] = v;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013C810);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013CA94);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013CBF0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013CDB0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D044);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D1F0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D528);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D578);

void func_8013D8B8(void) {
    D_8013FE60.f_24 = 0x600;
    D_8013FE60.f_28 = -0x300;
    D_8013FE60.f_98 = 0x780;
    D_8013FE60.f_9C = -0x180;
    D_8013FE60.f_10C = 0x900;
    D_8013FE60.f_180 = 0xA80;
    D_8013FE60.f_184 = 0x180;
    D_8013FE60.f_1F4 = 0xC00;
    D_8013FE60.f_110 = 0;
    D_8013FE60.f_1F8 = 0x300;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D910);

void func_8013DAF0(s32 arg0, s32 arg1) {
    func_80138350(2);
    func_801384CC(arg0 - 8, arg1, &D_8013EF8C, 0x808080);
    func_8008DDB0((s16) (arg0 + 0x28), (s16) (arg1 - 4));
    Msg_PutChar(0x101, 0x1F0, 0);
    Msg_PutChar(0x104, 0x1F0, 0);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013DB7C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013DEFC);

void func_8013DF7C(void) {
    D_8013FD40 = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013DF88);

void func_8013E700(void) {
    M2C_FIELD(&D_8013FD58, s16 *, 0) = 0;
    M2C_FIELD(&D_8013FD58, s32 *, 4) = -1;
    M2C_FIELD(&D_8013FD58, s16 *, 2) = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013E71C);

void func_8013E874(s32 arg0, s32 arg1, s8 arg2, s16 arg3) {
    void *temp_v1;

    temp_v1 = (void *)((u8 *)&D_8013FC08 + (arg0 * 0x38));
    if (M2C_FIELD(temp_v1, s16 *, 0x32) != 0) {
        switch (arg1) {                             /* irregular */
        case 0:
            M2C_FIELD(temp_v1, s8 *, 0xA) = arg2;
            M2C_FIELD(temp_v1, s16 *, 0x34) = arg3;
            return;
        case 1:
            M2C_FIELD(temp_v1, s8 *, 0xB) = arg2;
            M2C_FIELD(temp_v1, s16 *, 0x36) = arg3;
            break;
        }
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013E8D0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013E940);

void func_8013E9E0(void) {
    func_80138350(2);
    func_80138368(0x7E, 0x34, &D_8013EFC8, 0x808080);
    func_80138350(0);
    func_80138368(0x7E, 0x4A, &D_8013EB60, 0x808080);
    func_8013E940(0x66, 0x62, D_8013F3E0.f_2C);
    func_80138350(0);
    func_80138368(0x48, 0x8C, &D_8013EB6C, 0x808080);
    func_8013E940(0x66, 0xA4, D_8013F3E0.f_30);
}
