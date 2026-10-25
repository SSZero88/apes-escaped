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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B550);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013B6C4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390b", func_8013BC64);
