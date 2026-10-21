#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013C5E0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013C7C4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013C7F0);

extern struct S_g_Game { u8 pad_0[0x813C]; u16 f_813C; u8 pad_813E[0x16]; u16 f_8154; u16 f_8156; } g_Game;
extern struct { u8 pad0[0xA1]; u8 f_A1; u8 f_A2; } g_GadgetState;
extern struct { s16 f_0, f_2, f_4, f_6, f_8, f_A; } D_8013F5E4;
s32 Save_SumStageMonkeys(s32);

s32 func_8013C8E8(void) {
    D_8013F5E4.f_0 = Save_SumStageMonkeys(0);
    D_8013F5E4.f_2 = g_Game.f_813C;
    D_8013F5E4.f_4 = g_Game.f_8154;
    D_8013F5E4.f_6 = g_Game.f_8156;
    D_8013F5E4.f_8 = g_GadgetState.f_A1;
    D_8013F5E4.f_A = g_GadgetState.f_A2;
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013C954);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013CB30);

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390c", D_8013EEE0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013CD1C);

extern s16 D_8013AF56;
extern struct { s16 f_0; u8 pad2[6]; s16 f_8; u8 padA[2]; void *f_C; } D_800E3880;
void MemCard_Request(s32, s32);

s32 func_8013D19C(void) {
    D_8013AF56 = 0x13;
    MemCard_Request(8, 0);
    D_800E3880.f_C = (void *)0x80158000;
    D_800E3880.f_0 = 1;
    D_800E3880.f_8 = 0;
    MemCard_Request(10, 0);
    return 0;
}

s32 func_8013D238(void);

s32 func_8013D1F8(void) {
    return func_8013D238() != 0;
}

s32 func_8013D218(void) {
    return func_8013D238() != 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013D238);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013D834);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013D92C);

extern s16 D_800E3880_8013DA00 asm("D_800E3880");
void func_8013CD1C(s32, s32);

s32 func_8013DA00(void) {
    switch (D_800E3880_8013DA00) {
    case -7:
        if (D_8013AF56 != 0x26) {
            func_8013CD1C(0x12, 0);
        }
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DA7C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DB48);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DBF0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DC78);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DDF0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DEB4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013DF40);

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_801444D4(s32);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E098(void) {
    s32 cmd;
    s32 res;

    MemCardSync(0, &cmd, &res);
    func_801444D4(0);
    func_8014236C(0, &cmd, &res);
    if (res == 0) {
        D_8013F284 = 0;
    } else {
        D_8013F284 = 1;
    }
    return 0;
}

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_8014464C(s32, s16 *);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E114(void) {
    s16 info[16];
    s32 cmd;
    s32 res;

    if (D_8013F284 != 0) {
        return 0;
    }
    MemCardSync(0, &cmd, &res);
    func_8014464C(0, info);
    func_8014236C(0, &cmd, &res);
    return info[0];
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013E188);

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_80144084(s32);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E22C(void) {
    s32 cmd;
    s32 res;

    if (D_8013F284 != 0) {
        return 0;
    }
    MemCardSync(0, &cmd, &res);
    func_80144084(0);
    func_8014236C(0, &cmd, &res);
    return 0;
}

void func_8013E438(void);
void func_8013E604(void);
void func_8013EBD0(void);
s32 func_8013FEA0(void);
void func_80136160(s32, s32, s32, s32);
void func_80139A68(void);

s32 func_8013E290(void) {
    func_8013E438();
    func_8013E604();
    if (D_8013AF56 == 0x1D) {
        func_8013EBD0();
        func_8013FEA0();
    }
    func_80136160(0xC, 0x14, 0x160, 0x5E);
    func_80136160(0xC, 0x6E, 0x160, 0x6A);
    func_80139A68();
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013E30C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013E438);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013E604);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013EB14);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013EBD0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390c", func_8013ED0C);
