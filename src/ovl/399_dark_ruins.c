#include "common.h"
#include "m2c_macros.h"

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
M2C_UNK Object_ChaseSpike(void *, M2C_UNK);
s32 Object_DetachLink(void *, M2C_UNK);
s32 Object_SpikeOutOfRange(void *, s16, s32, s16, s32);
M2C_UNK Object_StepOnGroundFixed(void *);
M2C_UNK func_80051E98(void *, M2C_UNK);
s32 func_8005588C(void *, M2C_UNK);
M2C_UNK func_80055DC0(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_80056128(void *, M2C_UNK);
s32 func_800572CC(void *);
M2C_UNK func_80058134(void *, s16);
M2C_UNK func_8013D000(void *);
s32 func_8013D1CC();
M2C_UNK func_8013D2DC(void *);
M2C_UNK func_8013D33C(void *);
M2C_UNK func_8013D378(void *);
M2C_UNK func_8013D3D8(void *);
M2C_UNK Object_PlaySound(s32, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_ApplyVelocity();
void func_8013D6EC(s32 arg0);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013DDD8;
extern struct S_D_80141418 { u8 pad_0[0x10]; s8 f_10; u8 pad_11[0x3]; } D_80141418[];
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
extern struct S_D_801413F0 { u8 pad_0[0x18]; s32 f_18; u8 pad_1C[0x4]; s32 f_20; } D_801413F0;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8013F17C(void *);
s32 rcos(s16);
s32 rsin(s16);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D000);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D130);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D1CC);

void func_8013D200(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x96) = -0x2D;
    M2C_FIELD(arg0, s16 *, 0x94) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & ~0x20) | 0x400);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D228);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D2DC);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D33C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D378);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D3D8);

void func_8013D484(void *arg0) {
    u8 temp_v1;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        if (func_8013D1CC() != 0) {
            func_80051E98(arg0, 0);
            return;
        }
        func_8013D000(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) | 8);
        goto block_4;
    }
block_4:
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 0x14) & 1) {
        func_8013D2DC(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFFEFFFFF);
    }
    func_8013D378(arg0);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x80);
    switch (temp_v1) {                              /* irregular */
    case 1:
        if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0) {
            Object_ChaseSpike(arg0, 0xE);
        } else {
            func_80055DC0(arg0, 0xE, 0);
        }
        Object_StepOnGroundFixed(arg0);
        if (Object_DetachLink(arg0, 0) == 6) {
            if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x69) {
                func_8013D33C(arg0);
            } else {
                M2C_FIELD(arg0, u8 *, 0x80) = 3U;
                func_8005588C(arg0, 0x3C);
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) ((u16) M2C_FIELD(arg0, s32 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 3:
        func_80056128(arg0, 0xE);
        Object_StepOnGroundFixed(arg0);
        if (func_8005588C(arg0, -1) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
        }
        break;
    case 2:
        if (func_800572CC(arg0) != 0) {
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
            M2C_FIELD(arg0, s16 *, 0x96) = 0;
            M2C_FIELD(arg0, s16 *, 0x94) = 0;
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
        }
        break;
    }
    func_8013D3D8(arg0);
}

void func_8013D6CC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
}

void func_8013D6EC(s32 arg0) {
    u16 temp_v0;

    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 7)) {
        Object_PlaySound(arg0, 0xB1);
    }
}

void func_8013D738(s32 arg0) {
    Object_ApplyVelocity();
    func_8013D6EC(arg0);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D764);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D834);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D868);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D8CC);

void func_8013DBF8(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_80141418[i].f_10 = 0;
    }
    Hook_Add(&func_8013DDD8);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DC3C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DC78);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DD24);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DDD8);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DE6C);

void func_8013DF08(void) {
    Link_SendEvent(4, 3, 0);
    Link_SendEvent(7, 0x11, 0);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DF40);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E020);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E1A0);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E22C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E2BC);

void func_8013E57C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70B0, 0x1000, arg0 + 0x24);
    }
}

void func_8013E5BC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E600);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E680);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E74C);

void func_8013E810(void) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = D_801413F0.f_18 + (((D_801413F0.f_20 + 3) << 0xC) / 360);
    var_v0 = temp_a0;
    if (temp_a0 < 0) {
        var_v0 = temp_a0 + 0xFFF;
    }
    D_801413F0.f_18 = (s32) (temp_a0 - ((var_v0 >> 0xC) << 0xC));
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E86C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EBBC);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EC28);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013ED0C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013ED7C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EE70);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EF54);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F0A0);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F12C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F17C);

void func_8013F19C(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013F17C(arg0);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F260);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F384);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F408);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F6FC);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F9C0);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013FA8C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013FC18);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013FC64);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140098);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801400E4);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140368);

s32 func_8014060C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8014061C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801406D4);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140768);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8014090C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801409D8);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140B50);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140BF4);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140CF8);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140D4C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80141034);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801410F4);
