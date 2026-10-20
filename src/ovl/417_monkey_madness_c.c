#include "common.h"
#include "m2c_macros.h"

s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_801409FC;
s32 func_8013DF60();
M2C_UNK func_8013DFF4(void *);
extern s32 D_80140CF8;
M2C_UNK Collision_Remove(void *);
M2C_UNK func_8007CDC4(void *);
M2C_UNK Collision_Set(M2C_UNK, void *, void *);
M2C_UNK func_8007CD88(void *);
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80056BC4(M2C_UNK, M2C_UNK, s8);
s32 Collision_GetShape(s32);
s32 Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK func_800525A0(void *, s32);
M2C_UNK func_80052864(void *);
M2C_UNK func_8013D180(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8013F5F8(void *);
extern s32 D_80140D40;
extern void *D_80140D4C;

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D000);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D180);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D280);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D2D0);

void func_8013D374(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70AF, 0x1000, arg0 + 0x24);
    }
}

void func_8013D3B4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D3E4);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D43C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D4D8);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D538);

void func_8013D62C(void *arg0) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x74);
    Effect_Spawn(0xCA, temp_s1, &D_801409FC, 0);
    Effect_Spawn(0xCB, temp_s1, &D_801409FC, 0);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D684);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D738);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D8F0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D910);

void func_8013DA44(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7E) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7E) = Sound_ReserveSlot(0x70AF, 0x1000, arg0 + 0x24);
    }
}

void func_8013DA84(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7E);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
        M2C_FIELD(arg0, s8 *, 0x7E) = -1;
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DAC8);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DCC4);

void func_8013DD64(void *arg0) {
    u16 temp_v1;
    void *temp_a0;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    temp_a0 = (M2C_FIELD(arg0, u8 *, 0x71) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((u16) M2C_FIELD(temp_a0, u16 *, 2) < (u32) (temp_v1 & 0xFFFF)) {
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a0, u16 *, 0);
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DDAC);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DF10);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DF60);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DFF4);

void func_8013E034(void *arg0) {
    s32 temp_v0;
    u8 temp_v0_2;

    temp_v0 = func_8013DF60();
    if (temp_v0 != 0) {
        D_80140CF8 = (s32) M2C_FIELD(arg0, u8 *, 0x70);
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x7D);
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, u8 *, 0x7D) = (u8) (temp_v0_2 - 1);
        return;
    }
    if (temp_v0 != 0) {
        func_8013DFF4(arg0);
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E098);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E1A4);

void func_8013E27C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x73) = 0;
    if (M2C_FIELD(arg0, s8 *, 0x7A) != 0) {
        Collision_Remove(arg0 + 0x24);
        func_8007CDC4(arg0 + 0x1C);
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
}

void func_8013E2C4(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7A) == 0) {
        Collision_Set(4, arg0 + 0x24, arg0);
        func_8007CD88(arg0 + 0x1C);
        M2C_FIELD(arg0, s8 *, 0x7A) = 1;
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E310);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E3B8);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E44C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E4E0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E650);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E730);

void func_8013E7A0(void) {
    Link_SendEvent(6, 0, 0);
}

void func_8013E7C8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x38;
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 4;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x10);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E7F0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E814);

void func_8013E83C(void *arg0) {
    func_80056BC4(0x39, 0, M2C_FIELD(arg0, s8 *, 0xCB));
}

void func_8013E864(void) {
    Link_SendEvent(0xB, 1, 0);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E88C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E8CC);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EAD4);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EBC0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EC24);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EC70);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013ED4C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EE4C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F37C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F450);

void func_8013F490(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void func_8013F4D4(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) != -1) {
        func_8013F490(arg0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(arg1 | 0x7000, 0x1000, arg0 + 0x24);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F528);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F5F8);

void func_8013F64C(void *arg0) {
    if ((D_80140D40 != 0) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0)) {
        func_800525A0(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        func_8013F5F8(arg0);
        D_80140D40 = 0;
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
        M2C_FIELD(arg0, s8 *, 0x84) = 0x14;
        func_80052864(arg0);
        func_8013D180(arg0, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F6FC);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F7A8);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013FE04);

s32 func_8013FE5C(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(D_80140D4C, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(D_80140D4C, s32 *, 0x2C);
    temp_a1 = arg1 + 0x800;
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < (temp_a1 * temp_a1);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013FEB0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013FEF0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013FF58);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8014001C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140070);

s32 func_80140264(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140278);

s32 func_801403BC(void) {
    return 0;
}

s32 func_801403C4(void) {
    return 0;
}

s32 func_801403CC(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_801403DC);

s32 func_80140564(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140574);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140710);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_801407AC);
