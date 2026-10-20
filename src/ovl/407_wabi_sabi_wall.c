#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 func_8013D6BC();
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
extern s32 g_Game;
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D000);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D20C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D358);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D3BC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D4F0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D5C0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D6BC);

void func_8013D6F0(void *arg0) {
    if (func_8013D6BC() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D744);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D7AC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D98C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D9D8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DC64);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DE8C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DF50);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E044);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E0D0);

void func_8013E358(void *arg0) {
    if ((Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x800) != 0) && !(g_Game & 3)) {
        Object_PlaySound(arg0, 0x12);
    }
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E3AC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E43C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E46C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E51C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E5C4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E604);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E6A8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E6F8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E7E8);

void func_8013EA9C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013EADC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EB20);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EB9C);

s32 func_8013EDB8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EDD0);

s32 func_8013EFA0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EFB0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F1C0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F240);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F3F8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F584);

s32 func_8013F8D4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xE) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x14) = 1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F8FC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FC68);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FDC8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FEA4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FF40);

s32 func_801400A4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 4;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801400B8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014019C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140224);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801402C0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801404B0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801405C4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014066C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014087C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801409C8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140B58);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140EB0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80141240);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801412C4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801413AC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014146C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80141538);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014164C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80141874);
