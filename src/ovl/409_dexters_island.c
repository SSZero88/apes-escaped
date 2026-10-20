#include "common.h"
#include "m2c_macros.h"

extern s32 D_80142A60;
s32 rsin(s16, s32);
extern struct S_D_800E77A0 { u8 pad_0[0x8]; u16 f_8; s16 f_A; u16 f_C; } D_800E77A0;
M2C_UNK Collision_Remove(M2C_UNK *);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8007CDC4(M2C_UNK *);
M2C_UNK func_80088120(s8);
extern M2C_UNK D_80142CD8;
extern struct S_D_80142CA0 { u8 pad_0[0x2C]; u32 f_2C; } D_80142CA0;
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s16 Floor_GetHeight(s32, s32, s32);
M2C_UNK Shadow_Draw(void *, s16, M2C_UNK, s32);
M2C_UNK Object_CameraShake(s32, M2C_UNK);
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK func_8013F78C();
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
void func_8013E5FC(void *arg0);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D000);

void func_8013D0A0(void) {
    D_80142A60 = 0;
}

void func_8013D0AC(void) {
    D_80142A60 = 1;
}

void func_8013D0BC(void) {
    D_80142A60 = 0;
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D0C8);

s16 func_8013D2B8(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_a0;
    u16 temp_v1;
    void *temp_v0_2;

    temp_v0_2 = (M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88);
    temp_v1 = M2C_FIELD(temp_v0_2, u16 *, 0);
    temp_a1 = M2C_FIELD(temp_v0_2, u16 *, 2) - temp_v1;
    temp_lo = (s32) (((s32) ((M2C_FIELD(arg0, u16 *, 0x5C) - temp_v1) + 0x1A) % temp_a1) << 0xC) / temp_a1;
    temp_v0 = temp_lo + 0xC00;
    var_a0 = temp_v0;
    if (temp_v0 < 0) {
        var_a0 = temp_lo + 0x1BFF;
    }
    return (s16) (((s32) (rsin((s16) (temp_v0 - ((var_a0 >> 0xC) << 0xC)), temp_a1) * (arg1 - arg2)) >> 0xD) + ((s32) (arg1 + arg2) / 2));
}

void func_8013D3D0(void *arg0) {
    D_800E77A0.f_A = (s16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0xAA);
    D_800E77A0.f_8 = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    D_800E77A0.f_C = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D3FC);

void Object_TurnToward(void *, s16, s16, s16, s16);

void func_8013D454(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x90);
    Object_TurnToward(arg0, (s16) (M2C_FIELD(temp_v0, u16 *, 0x10) - M2C_FIELD(temp_v0, u16 *, 0)), (s16) (M2C_FIELD(temp_v0, u16 *, 0x14) - M2C_FIELD(temp_v0, u16 *, 4)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
}

void func_8013D4A8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x8E) = 2;
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D4BC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D72C);

void func_8013D7FC(void *arg0) {
    if (((u32) D_80142CA0.f_2C >> 0x1C) == 0xB) {
        Collision_Remove(&D_80142CA0);
        func_8007CDC4(&D_80142CD8);
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Sound_PlayFixed(0xAC);
        Sound_PlayFixed(0xAD);
        func_80088120(M2C_FIELD(arg0, s8 *, 0x7C));
    }
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013D884);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013DA9C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013DB44);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013DE2C);

M2C_UNK Object_StepOrbitAngle(void *, s16);
s32 rsin_8013E02C(s16) asm("rsin");

void func_8013E02C(void *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 temp_s4;
    s32 temp_v0;

    temp_s4 = (s32) (rsin_8013E02C(M2C_FIELD(arg0, s16 *, 0xAA)) * arg2) >> 0xC;
    Object_StepOrbitAngle(arg0, arg1);
    if (arg3 == 0) {
        temp_v0 = ((s32) (rsin_8013E02C(M2C_FIELD(arg0, s16 *, 0xAA)) * arg2) >> 0xC) - temp_s4;
        M2C_FIELD(arg0, u16 *, 0x94) = (u16) (M2C_FIELD(arg0, u16 *, 0x94) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
        M2C_FIELD(arg0, u16 *, 0x98) = (u16) (M2C_FIELD(arg0, u16 *, 0x98) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) ((s32) (rsin_8013E02C(M2C_FIELD(arg0, s16 *, 0xAA)) * arg2) >> 0xC);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013E11C);

void func_8013E19C(void *arg0) {
    s32 var_a0;

    var_a0 = 0;
    if (M2C_FIELD(arg0, u8 *, 0xDD) != 0) {
        var_a0 = 0xA00;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x20), var_a0 | 1, 0x201);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013E200);

void func_8013E5FC(void *arg0) {
    func_80088120(M2C_FIELD(arg0, s8 *, 0x7C));
}

M2C_UNK func_80051E98(s32, M2C_UNK);
M2C_UNK func_800573A0(s32, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013E620(s32 arg0) {
    func_8013E5FC(arg0);
    func_800573A0(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    func_80051E98(arg0, 1);
}

void func_8013E670(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_800525E0();
        func_80052864(arg0);
        func_8013E5FC(arg0);
    }
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013E6BC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013EB6C);

void func_8013EC9C(void *arg0, M2C_UNK arg1) {
    Shadow_Draw(arg0, Floor_GetHeight(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8)), arg1, *(s32 *)0x1F8003FC);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013ECF8);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013EE1C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013EF98);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013F010);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013F138);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013F1D0);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013F2CC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013F78C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013FAB8);

void func_8013FC78(s32 arg0) {
    func_8013F78C();
    Object_CameraShake(arg0, 2);
    Object_PlaySound(arg0, 0xB6);
}

extern M2C_UNK D_801438A8;

void func_8013FCB4(void *arg0) {
    func_80052038(arg0, 0x82);
    Collision_Remove(M2C_FIELD(arg0, s32 *, 0xB4));
    func_8007CDC4(&D_801438A8);
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013FD00);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013FDD0);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013FE88);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8013FFA8);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801401E8);

void func_80140234(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(temp_v1, s16 *, 2) + 0xBE);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140264);

M2C_UNK Object_DisableCollision(void *);
u32 Object_DetachLink(void *, s32);

void func_8014045C(void *arg0) {
    u32 temp_v1;

    temp_v1 = (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C;
    if (temp_v1 != 0xB) {
        if (temp_v1 != 1) {
            if (Object_DetachLink(arg0, 0) == 6) {
                goto block_3;
            }
        } else {
            goto block_4;
        }
    } else {
block_3:
block_4:
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        Object_DisableCollision(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x190, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x190), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0xA01, 0x200);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801404FC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140590);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140624);

void func_80140898(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140938);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140A00);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140A54);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140A90);

s32 func_80140BC8(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140C0C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140C4C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140CAC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140E88);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140EB4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140F44);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140FD4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141038);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141110);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8014116C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801413F8);

void func_80141484(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
}

s32 func_800563E0(void *, s32);

void func_801414D4(void *arg0) {
    func_800563E0(arg0, 0x14);
}

M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin_801414F4(s16) asm("rsin");

void func_801414F4(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin_801414F4(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_801414D4(arg0);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801415B8);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801416DC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141760);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141A54);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141AD0);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141BE4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141C38);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141D38);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141DB8);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80141E44);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80142088);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80142164);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801422FC);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801423F8);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801426D4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8014277C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801427C4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80142810);
