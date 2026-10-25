#include "common.h"
#include "m2c_macros.h"

extern s16 D_800E3880;
extern s16 D_8013C5B4;
void func_8013784C(s32, s32);

s32 func_8013B400(void) {
    switch (D_800E3880) {
    case 0:
        func_8013784C(1, D_8013C5B4);
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2C, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern struct { u8 pad_0[6]; s16 f_6; } D_800E3880_8013B47C asm("D_800E3880");
extern u8 D_800E1880[];
extern u8 D_8013C5C0[];
void func_8014016C(void);
s32 func_80139F08(void);
void func_80139A3C(s32);
void func_80139A68(void);
void MemCard_Request(s32, s32);

s32 func_8013B47C(void) {
    s32 r;
    s32 i;

    func_8014016C();
    r = func_80139F08();
    func_80139A3C(4);
    func_80139A68();
    if (r != 0) {
        if (r == 1) {
            for (i = 0; i < 16; i++) {
                D_800E1880[i + D_800E3880_8013B47C.f_6 * 0x7A0 + 0x198] = D_8013C5C0[i];
            }
            MemCard_Request(2, 0);
            func_8013784C(0x11, 0);
            return 0;
        }
        func_8013784C(1, D_8013C5B4);
    }
    return 0;
}

extern struct { u8 pad_0[6]; s16 f_6; } D_800E3880_8013B550 asm("D_800E3880");
extern s16 D_8013C5A8;
extern s16 D_8013C5AA;
extern s16 D_8013C5AC;
extern s16 D_8013C5AE;
extern s16 D_8013C5B0;
extern s16 D_8013C5B2;
extern s16 D_8013AF50;
extern struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; } D_8013C540;
extern s16 D_8013C5D0[];
u8 *func_8013FD44(void);

s32 func_8013B550(void) {
    s32 i;
    u8 *s;

    D_8013C5A8 = 0;
    D_8013C5AA = 0;
    D_8013C5AE = 0;
    D_8013C5AC = 4;
    D_8013C5B2 = 0xB;
    D_8013C5B0 = 0x2C;
    D_8013C540.f_4 = 1;
    D_8013C540.f_6 = -1;
    D_8013C540.f_8 = -1;
    D_8013C5B4 = D_8013AF50;
    if (D_800E1880[D_800E3880_8013B550.f_6 * 0x7A0 + 0x198] == 0) {
        s = func_8013FD44();
        s[4] = i + 0x6B;
        for (i = 0; i < 16; i++) {
            D_8013C5C0[i] = s[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            D_8013C5C0[i] = D_800E1880[i + D_800E3880_8013B550.f_6 * 0x7A0 + 0x198];
        }
    }
    for (i = 4; i >= 0; i--) {
        D_8013C5D0[i] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B6C4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013BC64);
