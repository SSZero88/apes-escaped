#include "common.h"
#include "m2c_macros.h"

INCLUDE_RODATA("asm/ovl/386/nonmatchings/386_title_menu", D_801376F0);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136000);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013654C);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013674C);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136AC0);

extern s32 D_80137810;
s32 func_80136D00(void);
void func_80136F54(void);

s32 func_80136C5C(void) {
    switch (D_80137810) {
    case 0:
        if (func_80136D00() >= 0) {
            break;
        }
        return -1;
    case 1:
        return -3;
    case 2:
        return -6;
    case 3:
        break;
    case 4:
        func_80136F54();
        return 0;
    case 5:
        return -4;
    case 6:
        return -5;
    case 7:
        break;
    case 8:
        return -8;
    case 9:
        return -10;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136D00);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136F54);

extern s16 D_80137818;
extern s16 D_8013781A;
void func_801375C4(void);

s32 func_801374E4(void) {
    switch (D_80137818) {
    case 1:
        return 0;
    case 0:
        func_801375C4();
        if (--D_8013781A < 0) {
            D_80137818 = 1;
            D_8013781A = 0;
        }
        return 0;
    case 2:
    case 3:
        func_801375C4();
        if (++D_8013781A >= 0x1F) {
            D_80137818 = 1;
            D_8013781A = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_801375C4);
