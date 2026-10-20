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

M2C_UNK func_8013D9A4(void *, s32, s32);
s32 rsin_8013DAD8(s16) asm("rsin");
extern s32 D_800EC208;
void Object_StepOrbitAngle(void *, s16);

void func_8013DAD8(void *arg0) {
    s32 sp10;
    s32 temp_s0;

    sp10 = D_800EC208 - M2C_FIELD(arg0, s32 *, 0x28);
    Object_StepOrbitAngle(arg0, 8);
    temp_s0 = (s32) (rsin_8013DAD8(M2C_FIELD(arg0, s16 *, 0xAA)) * 0xC8) >> 0xC;
    func_8013D968(&sp10, 5, -5);
    func_8013D9A4(arg0, sp10, M2C_FIELD(arg0, s16 *, 0x9C) + M2C_FIELD(arg0, s16 *, 0x96) + temp_s0);
}

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

s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013DF8C(void *arg0) {
    s32 temp_v0;

    Object_StepGrowShrink(arg0, 0, 0, -4);
    temp_v0 = (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

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

void Matrix_FromDirection(void *, s32);
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern u8 D_801417F8[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void func_8013ECD8(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_801417F8 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, &D_800E7D00, m);
    }
}

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

void func_800525E0(void *);
void func_80052864(void *);
void func_800573A0(void *, s32, s32, s32);

void func_8013F24C(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
void func_8013F220(void *);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013F2DC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013F220(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

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

M2C_UNK Object_DisableCollision(void *);

void func_8013F984(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    func_80052038(arg0, 0x9F);
    M2C_FIELD(arg0, s16 *, 0x5E) = 1;
    Object_DisableCollision(arg0);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F9D4);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FA50);

void func_8013FB40(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 4) {
        func_8013F984(arg0);
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

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos_801401E0(s16) asm("rcos");
s32 rsin_801401E0(s16, s32) asm("rsin");

void func_801401E0(void *arg0) {
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
    temp_a1 = (s32) (rcos_801401E0(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin_801401E0(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801402BC);

M2C_UNK Object_PlaySound(void *, M2C_UNK);

void func_8014033C(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801403E0);

s32 Math_Atan2(s32, s32);

void func_8014061C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_801406A8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
}

s32 func_800563E0(void *, s32);

void func_801406F8(void *arg0) {
    func_800563E0(arg0, 0x14);
}

M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos_80140718(s16) asm("rcos");
s32 rsin_80140718(s16) asm("rsin");

void func_80140718(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_801406F8(arg0);
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801407DC);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140900);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140984);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140C78);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140EF8);
