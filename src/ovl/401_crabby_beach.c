#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D000);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D168);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D1BC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D2E0);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D444);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D4AC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D5FC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D67C);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D8C0);

void func_8013D938(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

s32 Spike_WithinRadiusXZ(s32, s32, s32);

void func_8013DA14(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
u32 Object_DetachLink(void *, s32);

void func_8013DA94(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013DB38);

void func_8013DD74(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013DDB4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013DDF8);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013DE74);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E090);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E0F4);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E1E4);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E278);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E424);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E52C);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E76C);
