#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8013D770(void *);
s16 rcos(s16);
s16 rsin(s16);
s32 func_80055AA0(void *, s16, s16, s16);
s32 func_8013D968(s32 *arg0, s32 arg1, s32 arg2);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_8013F984();

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D000);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D15C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D770);

void func_8013D850(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAC);
    temp_v1 = temp_a0 + 0x800;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x17FF;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0);
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    func_8013D770(arg0);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D8BC);

s32 func_8013D968(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < arg2) {
        *arg0 = arg2;
        return 0;
    }
    if (arg1 < temp_v1) {
        *arg0 = arg1;
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D9A4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DAD8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DB6C);

s32 func_8013DBAC(void *arg0, s16 arg1) {
    s32 sp10;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x90) + (M2C_FIELD(arg0, u8 *, 0x8E) * 8);
    sp10 = M2C_FIELD(temp_s0, s16 *, 2) - M2C_FIELD(arg0, s32 *, 0x28);
    func_8013D968(&sp10, 0xA, -0xA);
    M2C_FIELD(arg0, u16 *, 0x96) = (u16) sp10;
    return func_80055AA0(arg0, M2C_FIELD(temp_s0, s16 *, 0), M2C_FIELD(temp_s0, s16 *, 4), arg1) != 0;
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DC34);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DCF8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DDA8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DE0C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DEA8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DF04);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013DF8C);

void func_8013E004(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) - 0x14);
    }
    temp_v0 = ((s32) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) << 0x10) >> 0x13) + 0x21;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) - ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E068);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E3A0);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E3F4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E518);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E67C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E6E4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E834);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E8B4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EAF8);

void func_8013EC38(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013ECD8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EDA0);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EDF4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EE30);

s32 func_8013EF68(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EFA4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EFE4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F044);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F220);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F24C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F2DC);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F36C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F3D0);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F4A8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F504);

void func_8013F790(void *arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x80) != 3) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x19) >> 9)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xBE), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x19) >> 9)), 0, 0x100);
    }
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F878);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F984);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F9D4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FA50);

void func_8013FB40(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 4) {
        func_8013F984();
        M2C_FIELD(arg0, u8 *, 0xCF) = 0U;
    }
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FB7C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FEF8);

void func_8013FF44(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v1, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FF9C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140168);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801401E0);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801402BC);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8014033C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801403E0);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8014061C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801406A8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801406F8);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140718);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801407DC);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140900);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140984);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140C78);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140EF8);
