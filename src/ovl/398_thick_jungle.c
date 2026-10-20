#include "common.h"
#include "m2c_macros.h"

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_DisableCollision();
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK func_8005588C(void *, M2C_UNK);
extern s8 D_80142860;
s32 Math_Atan2(s32, s32, s16);
s16 rcos(s16);
s16 rsin(s16);
extern struct S_D_800E77A0 { u8 pad_0[0x1]; u8 f_1; } D_800E77A0;
M2C_UNK Collision_Set(M2C_UNK, M2C_UNK *, s32);
M2C_UNK func_8013F844();
extern struct S_D_80143170 { u8 pad_0[0x20]; s16 f_20; s16 f_22; s16 f_24; s16 f_26; } D_80143170;
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013FA20;
extern struct S_D_801431B0 { u8 pad_0[0x10]; s32 f_10; } D_801431B0[];
s32 func_8013F948();
s32 Spike_WithinRadiusXZ(s32 x, s32 z, s32 r);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, s32);
M2C_UNK func_80088120(s8);
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
M2C_UNK Object_TurnTowardSpike(void *);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D000);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D040);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D080);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D0EC);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D274);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D300);

void func_8013D430(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, (s16) (M2C_FIELD(arg0, u16 *, 0x24) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * arg1) >> 0xC)), M2C_FIELD(arg0, s16 *, 0x28), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) - ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * arg1) >> 0xC)), (s32) arg2, (s32) arg3);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D4C8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D520);

void func_8013D608(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 7;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    Object_DisableCollision();
    Object_PlaySound(arg0, 0x9A);
    func_8005588C(arg0, 0xC);
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D660);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D790);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D914);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013DE24);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013DE78);

void func_8013DF48(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v0 = &D_80142860;
    var_v1 = 0x3F;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 += 0x24;
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013DF6C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E068);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E1E0);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E560);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E688);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E768);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E7EC);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E848);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E8A8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E9D8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013EEB8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013EFDC);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F020);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F1F8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F354);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F448);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F56C);

void func_8013F608(void *arg0) {
    s16 temp_a2;
    s16 temp_v0_3;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    void *temp_v0;

    M2C_FIELD(arg0, s16 *, 0xA0) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x48) = 1;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x3DFD;
    M2C_FIELD(arg0, s16 *, 0x44) = 0xE6;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x258;
    M2C_FIELD(arg0, s8 *, 0xDC) = 7;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    M2C_FIELD(arg0, s8 *, 0xC9) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~0x1000);
    M2C_FIELD(arg0, u8 *, 0x8F) = (u8) D_800E77A0.f_1;
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 + 1);
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    if (M2C_FIELD(arg0, u16 *, 0x8C) != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x90);
        temp_a2 = M2C_FIELD(temp_v0, s16 *, 8);
        temp_v0_2 = Math_Atan2(temp_a2 - M2C_FIELD(temp_v0, s16 *, 0), M2C_FIELD(temp_v0, s16 *, 0xC) - M2C_FIELD(temp_v0, s16 *, 4), temp_a2);
        temp_v1 = temp_v0_2 + 0x1400;
        var_v0 = temp_v1;
        if (temp_v1 < 0) {
            var_v0 = temp_v0_2 + 0x23FF;
        }
        temp_v0_3 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
        M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0_3;
        M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0_3);
        M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
        M2C_FIELD(arg0, s16 *, 0x62) = 0;
    }
    Object_DisableCollision(arg0);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F71C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F844);

void func_8013F8A4(s32 arg0) {
    D_80143170.f_26 = -0x4000;
    D_80143170.f_20 = 0x258;
    D_80143170.f_24 = 0;
    D_80143170.f_22 = 0x320;
    func_8013F844();
    Collision_Set(4, &D_80143170, arg0);
}

void func_8013F904(void) {
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_801431B0[i].f_10 = 0;
    }
    Hook_Add(&func_8013FA20);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F948);

void func_8013F984(void *arg0, void *arg1) {
    s32 temp_v0;
    void *temp_v1;

    temp_v0 = func_8013F948();
    if (temp_v0 != -1) {
        temp_v1 = (void *)((u8 *)&D_801431B0 + (temp_v0 * 0x14));
        M2C_FIELD(temp_v1, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
        M2C_FIELD(temp_v1, SVECTOR *, 8) = M2C_FIELD(arg1, SVECTOR *, 0);
        M2C_FIELD(temp_v1, s32 *, 0x10) = 3;
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FA20);

void func_8013FA90(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xC3) >> 9));
    M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x64);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0xC3) >> 9));
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FAF4);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FD9C);

void func_8013FDF0(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0x280;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & 0xFFFEFFFF);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FE4C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FE94);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FF1C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140044);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801400B0);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140150);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140214);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801402E8);

void func_80140504(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70B4, 0x1000, arg0 + 0x24);
}

void func_80140538(void *arg0) {
    func_80088120(M2C_FIELD(arg0, s8 *, 0x7C));
}

M2C_UNK func_80051E98(s32, M2C_UNK);
M2C_UNK func_800573A0(s32, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8014055C(s32 arg0) {
    func_80140538(arg0);
    func_800573A0(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    func_80051E98(arg0, 1);
}

M2C_UNK func_800525E0(void *);
M2C_UNK func_80052864(void *);

void func_801405AC(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_80140538(arg0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801405F8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140684);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801406D8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140760);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801407F8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140A70);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140BC8);

void func_80140E9C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_80140EDC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140F20);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140F9C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801411B8);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801412C4);

void func_801413AC(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x400) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801413F8);

void func_80141504(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0) {
        Object_TurnTowardSpike(arg0);
        return;
    }
    Object_TurnToward(arg0, (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80141588);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8014186C);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801423AC);
