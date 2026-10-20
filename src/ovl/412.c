#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013D974;
extern struct S_D_80141DF0 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80141DF0[];
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_8013DDA8(void *);
s32 rcos(s16);
s32 rsin(s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
extern s32 D_80142000;
M2C_UNK Fx_DrawFadeRing(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_AddAttackSphereAt(void *, s32, M2C_UNK);
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s32);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D000);

void func_8013D168(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D208);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D2AC);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D2E8);

s32 func_8013D7CC(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D810);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D850);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D890);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013D974);

void func_8013DB38(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80141DF0[i].f_C = 0;
    }
    Hook_Add(&func_8013D974);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DB7C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DBB8);

void func_8013DC04(void *arg0) {
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

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DC84);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DCD0);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DD5C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DDA8);

void func_8013DDC8(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013DDA8(arg0);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DE8C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013DFF0);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E074);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E388);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E674);

void func_8013E884(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, arg0 + 0x24);
    }
}

void func_8013E8C4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E908);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E97C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013E9D8);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013EADC);

void func_8013EB94(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x88);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, s8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_v1, u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) ((s32) -(arg1 * (s16) (((M2C_FIELD(temp_v1, u16 *, 0x12) + 5) - M2C_FIELD(temp_v1, u16 *, 0x10)) - 1)) / 2);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013EBF4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013EC78);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013ED10);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013ED7C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013EE38);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013EEA8);

void func_8013EF34(void *arg0) {
    s32 var_t0;
    s32 var_v1;

    if (D_80142000 != 0) {
        D_80142000 -= 1;
        return;
    }
    if (Object_DetachLink(arg0, 1) == 6) {
        if (M2C_FIELD(arg0, u8 *, 0x80) != 0x11) {
            D_80142000 = 0xA;
        }
    } else if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        var_t0 = 0x101;
        if (M2C_FIELD(arg0, u8 *, 0x80) == 0x11) {
            var_t0 = 0x203;
            var_v1 = 0x801;
        } else {
            var_v1 = 0x800;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphere(arg0, 0x104, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x190), (s32) M2C_FIELD(arg0, s16 *, 0x2C), var_v1, var_t0);
    }
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F010);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F058);

void func_8013F1C0(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x1C, 0, 0, 0x12C);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F240);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F3A4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F4B4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F660);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F724);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F760);

void func_8013F80C(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x74);
    Fx_DrawFadeRing(temp_s0, 0xC8, 4, 0x645050);
    Object_AddAttackSphereAt(arg0, temp_s0, 0xC8);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F860);

void func_8013F9C0(void *arg0, s32 arg1) {
    Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6) + arg1);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013F9F4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013FA24);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8013FB34);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80140BD0);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80140CDC);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80140D60);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80140F9C);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80141090);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80141134);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_801413D8);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80141494);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_8014173C);

s32 func_801417C8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 0x14) = -1;
    return 0;
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_801417DC);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412", func_80141960);
