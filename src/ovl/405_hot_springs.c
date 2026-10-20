#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

s32 func_8013D520();
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
s32 func_8013E998();
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D000);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D100);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D230);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D2FC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D3B4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D4B8);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D520);

void func_8013D578(void *arg0) {
    if (func_8013D520() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D5BC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D7AC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D904);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D9EC);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 func_8013DA9C(void *arg0) {
    if (Object_SpikeInFront(arg0, 0x5A, 0xB50, 0x300) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(((M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, void **, 0x88)), u16 *, 2)) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 3U;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        }
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
        Object_PlaySound(arg0, 0xB4);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DB2C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DD04);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DD5C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DE5C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E7B8);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E8A4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E8FC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E998);

s32 func_8013E9C8(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013E9F8(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013EA34(void *arg0) {
    if ((func_8013E9C8(arg0) == 0) && (func_8013E9F8(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013EA88);

void func_8013EBE8(s32 arg0) {
    if (func_8013E998() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013EC2C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013EC6C(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013ECD4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013EFBC);

void func_8013F2EC(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F38C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F454);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F49C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F4D8);

s32 func_8013F618(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F654);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F694);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F6D4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F89C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F8C8);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F958);

M2C_UNK func_8013F4D8(void *, M2C_UNK, M2C_UNK);

void func_8013F9E8(void *obj) {
    func_8013F4D8(obj, 0x46, 0xA0);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013FA0C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013FAEC);

s32 Math_Atan2(s32, s32);

void func_8013FFD4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_80140060(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_80140098(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140160);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140284);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_801402D4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140348);

s32 func_801406E0(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(temp_v1, u16 *, 0x26) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140730);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140968);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_801409B0);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140F94);
