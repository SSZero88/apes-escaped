#include "common.h"
#include "m2c_macros.h"

s32 rsin(s16, s32);
extern struct S_D_800E77A0 { u8 pad_0[0x8]; s16 f_8; s16 f_A; s16 f_C; } D_800E77A0;
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D000);

s16 func_8013D0B0(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_a0;
    u16 temp_v0_3;
    void *temp_v0_2;

    temp_v0_2 = (M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88);
    temp_v0_3 = M2C_FIELD(temp_v0_2, u16 *, 0);
    temp_a1 = M2C_FIELD(temp_v0_2, u16 *, 2) - temp_v0_3;
    temp_lo = (s32) (((s32) (M2C_FIELD(arg0, u16 *, 0x5C) - temp_v0_3) % temp_a1) << 0xC) / temp_a1;
    temp_v0 = temp_lo + 0xC00;
    var_a0 = temp_v0;
    if (temp_v0 < 0) {
        var_a0 = temp_lo + 0x1BFF;
    }
    return (s16) (((s32) (rsin((s16) (temp_v0 - ((var_a0 >> 0xC) << 0xC)), temp_a1) * (arg1 - arg2)) >> 0xD) + ((s32) (arg1 + arg2) / 2));
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D1C4);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D224);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D294);

void func_8013D3B8(void *arg0) {
    D_800E77A0.f_A = (s16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0xB4);
    D_800E77A0.f_8 = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x60) * 0x96) >> 0xC));
    D_800E77A0.f_C = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x64) * 0x96) >> 0xC));
}

void func_8013D430(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (temp_v0 - 1);
        return;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x8F) = 0xAU;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere(arg0, 0xC8, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xAF) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xFA), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0xAF) >> 0xB)), 0, 0x101);
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D518);

void func_8013D660(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D700);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D7C8);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D81C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D858);

s32 func_8013D990(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D9CC);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DA0C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DA94);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DC70);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DC9C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DD2C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DDBC);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DE20);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DEF8);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DF54);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E1E0);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E33C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E950);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013F0C0);
