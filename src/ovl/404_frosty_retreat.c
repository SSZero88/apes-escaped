#include "common.h"
#include "m2c_macros.h"

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
s32 func_8013D1E0();
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s32 func_8013FA40(s32);
M2C_UNK func_8013FA60(void *, M2C_UNK);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D000);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D0EC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D144);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D1E0);

s32 func_8013D210(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013D240(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013D27C(void *arg0) {
    if ((func_8013D210(arg0) == 0) && (func_8013D240(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D2D0);

void func_8013D430(s32 arg0) {
    if (func_8013D1E0() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013D474(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013D4B4(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D51C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D804);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D89C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013DB40);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013DD40);

void func_8013DF78(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E018);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E0E0);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E128);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E164);

s32 func_8013E2A4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E2E0);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E320);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E360);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E528);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E554);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E5E4);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E674);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E698);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E778);

void func_8013EC60(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013ECA0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013ECE4);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013ED60);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013EF7C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F0EC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F178);

void func_8013F1B0(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F278);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F39C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F3EC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F460);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F7F8);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F8BC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F91C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F9D4);

void func_8013FA20(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x10000);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FA40);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FA60);

void func_8013FAB8(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0xBC)) * 0xA));
    M2C_FIELD(arg0, u16 *, 0xD6) = (u16) (M2C_FIELD(arg0, u16 *, 0xD6) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0xC0)) * 0xA));
    func_8013FA60(arg0 + 0xD4, 0x17C);
    func_8013FA60(arg0 + 0xD6, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FB54);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FC04);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FC4C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FCE0);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FFC8);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140124);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140738);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140864);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8014090C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140AFC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8014163C);
