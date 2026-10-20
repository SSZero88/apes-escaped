#include "common.h"
#include "m2c_macros.h"

s32 func_801361D8(M2C_UNK *, s16);
M2C_UNK func_80139628(s32);
extern M2C_UNK D_8013B490;
extern M2C_UNK D_8013B998;

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136000);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801361D8);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136208);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136394);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136588);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013683C);

INCLUDE_RODATA("asm/ovl/392/nonmatchings/392", D_8013ADB0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136A1C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136EAC);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80137198);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801375B4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80137C88);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801380DC);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138118);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138138);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138370);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801385B0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138E04);

void func_8013912C(void *arg0, s32 arg1) {
    if ((arg1 > 0) && (M2C_FIELD(arg0, s16 *, 0) >= 0)) {
        M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 2);
        M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 4);
        func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 0)));
        if ((arg1 >= 2) && (M2C_FIELD(arg0, s16 *, 6) >= 0)) {
            M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 8);
            M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
            func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 6)));
            if ((arg1 >= 3) && (M2C_FIELD(arg0, s16 *, 0xC) >= 0)) {
                M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
                M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
                func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 0xC)));
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139248);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801394D0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139628);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139710);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801397F4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801399A4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139E0C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139EE0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139FB8);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A10C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A334);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A3C4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A7A8);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A8C0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013AABC);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013ABD4);
