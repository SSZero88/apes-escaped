#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 func_8013D540();
M2C_UNK Object_SpawnEffect(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
s32 Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
void *Collision_GetShape(s32);
M2C_UNK Object_Destroy(void *);
M2C_UNK func_8013F418(void *);
M2C_UNK func_800880D0(M2C_UNK, s16);
extern M2C_UNK D_800E7880;
extern M2C_UNK D_801434C0;
extern M2C_UNK D_801434C4;
s32 SaveByte_Get(M2C_UNK);
extern s32 D_800B4D64;

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D000);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D374);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D444);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D540);

void func_8013D574(void *arg0) {
    if (func_8013D540() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D5C8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D630);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D810);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013DC1C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013DCE4);

void func_8013DEEC(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    if (var_s0 > 0) {
        do {
            Object_SpawnEffect(arg0, 0x2B, 0, 0, 0);
            var_s0 -= 1;
        } while (var_s0 > 0);
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013DF40);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013DFEC);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E05C);

void func_8013E1B4(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0xE0) & 1) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) == 0)) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E214);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E52C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E7A4);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E7F4);

void func_8013E86C(void *arg0) {
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

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E948);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E9C8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EA6C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013ECA8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013ED00);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EE30);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EEF4);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EF94);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EFF8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F380);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F418);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F618);

void func_8013F818(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) != 0xD00)) {
        Object_PlaySound(arg0, 0x15);
        func_8013F418(arg0);
        Object_Destroy(arg0);
        Object_PlaySound(arg0, 0x69);
        M2C_FIELD(arg0, s8 *, 0x81) = 0;
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F894);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013FA8C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013FB20);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013FC00);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013FE4C);

s32 func_801402D8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x36) = 3;
    M2C_FIELD(arg0, u16 *, 0x18) = (u16) ((M2C_FIELD(arg0, u16 *, 0x18) & 0xFFF0) | 1);
    return 0;
}

s32 func_801402F8(void) {
    func_800880D0(0x50AD, M2C_FIELD(&D_801434C0, s16 *, 0));
    M2C_FIELD(&D_801434C0, s16 *, 2) = 0;
    func_800880D0(0x50AE, M2C_FIELD(&D_801434C4, s16 *, 0));
    M2C_FIELD(&D_801434C4, s16 *, 2) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 0) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 8) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 4) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 0xC) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 0x14) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 0x10) = 0;
    M2C_FIELD(&D_800E7880, s32 *, 0x18) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140374);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140430);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801408CC);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140988);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801409E8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140AC4);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140D18);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140F30);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140FE0);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8014119C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801411E8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8014134C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801414A0);

s32 func_801415D4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801415E0);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801419AC);

s32 func_80141C68(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80141C70);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80141CD4);

s32 func_80141D30(void *arg0) {
    s16 temp_a0;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    if (SaveByte_Get(5) == 5) {
        temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80141D94);

s32 func_80141F08(void *arg0) {
    s16 temp_a0;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    if (SaveByte_Get(5) == 5) {
        temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80141F6C);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80142054);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801420E8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8014277C);

s32 func_80142800(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80142808);
