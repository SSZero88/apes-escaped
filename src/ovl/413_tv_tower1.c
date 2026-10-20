#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013FB40;
extern struct S_D_80144640 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80144640[];
void *Collision_GetShape(s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
s32 func_80141A20(s32);
M2C_UNK func_80141A40(void *, M2C_UNK);
s16 rcos(s16);
s16 rsin(s16);
extern struct S_D_80144858 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80144858[];

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D000);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D08C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D19C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D210);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D31C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D3C4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D46C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D548);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D620);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D6D0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D8D8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D94C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DBF0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DC5C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DD64);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DE4C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DEB4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DF6C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E004);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E120);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E20C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E2A8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E3A4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E59C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E64C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E704);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E774);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EA44);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EB94);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013ED24);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EDA0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EE2C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EF2C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EF7C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F000);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F058);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F148);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F37C);

void func_8013F4B0(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F550);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F5F4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F630);

s32 func_8013FA7C(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FAC0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FB00);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FB40);

void func_8013FD48(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80144640[i].f_C = 0;
    }
    Hook_Add(&func_8013FB40);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FD8C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FE00);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FEE8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801400A4);

s32 func_8014018C(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x1200) != 0)) {
        if ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) == 0x800) {
            return 1;
        }
        Object_PlaySound(arg0, 0x67);
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

void func_8014020C(void *arg0) {
    s32 temp_v1;
    u8 temp_a1;

    if (M2C_FIELD(arg0, u8 *, 0x81) != 0) {
        temp_a1 = M2C_FIELD(arg0, u8 *, 0xCF);
        if (temp_a1 == 1) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0xE0);
            if (!(temp_v1 & 1)) {
                M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 | 1);
                M2C_FIELD(arg0, s8 *, 0x80) = 2;
                M2C_FIELD(arg0, u8 *, 0x7F) = 0U;
                M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0);
                return;
            }
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 & ~1);
            M2C_FIELD(arg0, s8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = temp_a1;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x5E) = 2;
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140298);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801404A4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801404EC);

void func_80140578(void *arg0) {
    u8 temp_v0;

    if ((M2C_FIELD(arg0, u8 *, 0xC8) != 0) && (M2C_FIELD(arg0, u8 *, 0x80) != 7)) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x7D) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xC8), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x7D) >> 0xB)), 0, 0x100);
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140670);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801407DC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140DAC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140E94);

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_80140FA0(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140FD4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014102C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014105C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141214);

void func_8014124C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_800525E0();
        func_80052864(arg0);
    }
}

void func_80141290(void *arg0) {
    func_80052038(arg0, 6);
    M2C_FIELD(arg0, s8 *, 0x8F) = 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801412BC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801412FC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014173C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141840);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801418D8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141998);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801419F0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141A20);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141A40);

void func_80141A98(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_80141A20(M2C_FIELD(arg0, s16 *, 0xA8) - M2C_FIELD(arg0, s16 *, 0xC2)) * 0x14));
    func_80141A40(arg0 + 0xD4, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xC2) = (s16) (u16) M2C_FIELD(arg0, s16 *, 0xA8);
}

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_TurnTowardSpike(void *);
s32 Object_WouldLeaveHome(void *, M2C_UNK);
M2C_UNK func_80055718(void *, s16, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_80141AF8(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x1E, 0x14, 0);
    }
    func_80055718(arg0, arg1, arg2, arg3, (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13);
    Object_TurnTowardSpike(arg0);
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

void func_80141BB0(void *arg0) {
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAC) + M2C_FIELD(arg0, s16 *, 0xB0);
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_v1 + 0xFFF;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0);
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141C1C);

void func_80141C74(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        if (Object_DetachLink(arg0, 0) == 6) {
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x202);
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141CFC);

s32 func_80142058(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_80144858[i].f_A = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80142080);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80142200);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014263C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801426B0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014283C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801428E4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801431B0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801433F0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80143F38);
