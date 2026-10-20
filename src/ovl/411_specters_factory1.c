#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013DA0C;
extern struct S_D_80141738 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80141738[];
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
void *Collision_GetShape(s32);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
extern struct S_D_80141948 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80141948[];

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D000);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D058);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D148);

void func_8013D37C(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D41C);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D4C0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D4FC);

s32 func_8013D948(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D98C);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013D9CC);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DA0C);

void func_8013DC14(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80141738[i].f_C = 0;
    }
    Hook_Add(&func_8013DA0C);
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DC58);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DC94);

void func_8013DCE0(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x24, 1, 0, 0x64);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DD60);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DDAC);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DE38);

s32 func_800563E0(void *, s32);

void func_8013DE84(void *arg0) {
    func_800563E0(arg0, 0x14);
}

void func_8013DEA4(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013DE84(arg0);
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013DF68);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E0CC);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E150);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E464);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E4D8);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E5C0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E77C);

s32 func_8013E864(void *arg0) {
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

void func_8013E8E4(void *arg0) {
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

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013E970);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013EB7C);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013EBC4);

void func_8013EC50(void *arg0) {
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

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013ED48);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013EEB4);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F484);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F4F0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F5D4);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F644);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F738);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F7E0);

void func_8013F92C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013F96C(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013F9B0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013FA2C);

s32 func_8013FC48(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_80141948[i].f_A = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013FC70);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8013FDF0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8014022C);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_801402A0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140350);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140404);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140454);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140538);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140590);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_801406A0);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80140714);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_801407B4);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_8014085C);

INCLUDE_ASM("asm/ovl/411/nonmatchings/411_specters_factory1", func_80141128);
