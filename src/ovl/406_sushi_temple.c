#include "common.h"
#include "m2c_macros.h"

s32 Math_Atan2(s32, s32);
extern struct S_g_Spike { u8 pad_0[0x24]; s32 f_24; u8 pad_28[0x4]; s32 f_2C; } g_Spike;
extern s32 D_800B4D64;
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Fx_Explosion(void *, s16, M2C_UNK);
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK, void *);

void Object_SetAnim(void *, u8, u8);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

void func_8013D000(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        Object_SetAnim(arg0, 2, 1);
        Object_PlaySound(arg0, 0xAC);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D04C);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D1BC);

void func_8013D2B0(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    s32 var_v1;

    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6) - 0x32) != 0) {
        temp_v0 = Math_Atan2(g_Spike.f_24 - M2C_FIELD(arg0, s32 *, 0x24), g_Spike.f_2C - M2C_FIELD(arg0, s32 *, 0x2C));
        var_v1 = temp_v0 + 0x1000;
        var_v0 = var_v1;
        if (var_v1 < 0) {
            var_v0 = temp_v0 + 0x1FFF;
        }
    } else {
        temp_v0_2 = Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C));
        var_v1 = temp_v0_2 + 0x1100;
        var_v0 = var_v1;
        if (var_v1 < 0) {
            var_v0 = temp_v0_2 + 0x20FF;
        }
    }
    M2C_FIELD(arg0, s16 *, 0xAC) = (s16) (var_v1 - ((var_v0 >> 0xC) << 0xC));
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D368);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D77C);

typedef struct { u8 pad0[0x10]; s8 f; u8 pad11[3]; } Slot_406;
extern s32 D_8013F8B0;
extern Slot_406 *D_8013F8B4;

s32 func_8013D8A4(void) {
    s32 i;

    for (i = 0; i < D_8013F8B0; i++) {
        if (D_8013F8B4[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D8F8);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013D9C4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DAFC);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DBF4);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DC70);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DD94);

void func_8013DE4C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 7;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x1C);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013DE84);

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_80052134(void *, M2C_UNK);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_8013DC70(s16, s16, s16);

void func_8013DF60(void *arg0) {
    func_8013DC70(M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C));
    Object_PlaySound(arg0, 0xB1);
    M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
    func_8005588C(arg0, 0x3C);
    func_80052038(arg0, 0x6E);
    func_80052134(arg0, 0x6E);
    M2C_FIELD(arg0, s16 *, 0xD4) = 0xC00;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & 0xFF3FFFFF) | 0x400000);
    M2C_FIELD(arg0, s32 *, 0x28) -= 0x1F4;
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E004);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E058);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013E134);

void func_8013E9EC(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013EA38);

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
void func_8006D548(SVECTOR *);

void func_8013ED30(void *arg0, s16 x, s16 y, s16 z) {
    SVECTOR v;

    v.vx = x;
    v.vy = y;
    v.vz = z;
    func_8006D548(&v);
    Object_AddAttackSphereNear(arg0, M2C_FIELD(arg0, u16 *, 0x44) + 0x32, v.vx, v.vy, v.vz,
                               M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
}

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

s32 func_8013ED9C(void *arg0, s32 arg1, s32 arg2) {
    SVECTOR v;

    if (arg2 == 2) {
        Object_PlaySound(arg0, 0x79);
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x1C);
    v.vy = M2C_FIELD(arg0, u16 *, 0x1E);
    v.vz = M2C_FIELD(arg0, u16 *, 0x20);
    Object_AddAttackSphereNear(arg0, arg2 * 0x118 / arg1, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
    return arg2 == arg1;
}

void func_8013EE80(void *arg0)
{
  *((s16 *) (((s8 *) arg0) + 0xA0)) = 0x32;
  *((s16 *) (((s8 *) arg0) + 0xB0)) = 0x88;
  *((s16 *) (((s8 *) arg0) + 0x44)) = 0x3C;
  *((u8 *) (((s8 *) arg0) + 0xC8)) = 6;
  *((s16 *) (((s8 *) arg0) + 0x48)) = 0x201;
  *((s16 *) (((s8 *) arg0) + 0x4A)) = -0x7DFD;
  *((u8 *) (((s8 *) arg0) + 0xCD)) = 1;
  *((u8 *) (((s8 *) arg0) + 0xDC)) = 2;
  *((u8 *) (((s8 *) arg0) + 0x80)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x46)) = 0;
  *((s16 *) (((s8 *) arg0) + 0xA8)) = 0;
  *((u8 *) (((s8 *) arg0) + 0x7F)) = 0;
  *((u32 *) (((s8 *) arg0) + 0xE0)) |= 0x200000;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = *(*((u16 **) (((s8 *) arg0) + 0x88)));
}

M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern M2C_UNK D_800B1C28;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013EEF0 asm("g_Spike");

void func_8013EEF0(void *arg0)
{
  SVECTOR v;
  u16 new_var;
  *((s8 *) (((s8 *) arg0) + 0x80)) = 2;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 3;
  new_var = *((u16 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x88)))) + 0xC));
  *((s8 *) (((s8 *) arg0) + 0x82)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE0)) &= ~0x100000;
  *((s32 *) (((s8 *) arg0) + 0xE0)) &= ~0x1000;
  *((s8 *) (((s8 *) arg0) + 0x8F)) = 0;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var;
  Object_TurnToward(arg0, g_Spike_8013EEF0.x - (*((u16 *) (((s8 *) arg0) + 0x24))), (&g_Spike_8013EEF0)->z - (*((u16 *) (((s8 *) arg0) + 0x2C))), 0, 0x1000);
  v.vx = *((u16 *) (((s8 *) arg0) + 0x24));
  v.vy = *((u16 *) (((s8 *) arg0) + 0x28));
  v.vz = *((u16 *) (((s8 *) arg0) + 0x2C));
  Fx_SpawnFadeRing(&v, 0, 0x1B0, 0xC);
  v.vy -= 0x80;
  func_80070284(&v, &D_800B1C28, 1, 0xC, 0);
}

s32 Vec_Length(s32, s32, s32);
void Object_OrbitAround(void *, s16, s16, s16, s16);
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013EFE4 asm("g_Spike");

void func_8013EFE4(void *arg0) {
    s32 d;
    s32 r;
    s16 speed;

    d = Vec_Length(g_Spike_8013EFE4.x - M2C_FIELD(arg0, s16 *, 0x9A), 0, g_Spike_8013EFE4.z - M2C_FIELD(arg0, s16 *, 0x9E));
    r = M2C_FIELD(arg0, s16 *, 0xA6);
    if (r + 0x600 < d) {
        speed = 8;
    } else if (d < r) {
        speed = 0x20;
    } else {
        speed = (0x600 - d) / 64 + 8;
    }
    Object_OrbitAround(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6), speed);
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F08C);

s32 func_8013F1D8(void *arg0) {
    s16 temp_a0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 0xA) == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 1;
        temp_a0 = M2C_FIELD(temp_a1, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
        M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a1, u16 *, 0x18) | 0x8000);
    }
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

s32 func_8013F264(void *arg0) {
    s16 temp_a1;
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if ((M2C_FIELD(arg0, s16 *, 2) == 0) && (M2C_FIELD(temp_s0, s16 *, 0x1E) >= 0) && (((u16) M2C_FIELD(temp_s0, s16 *, 0x1E) & 0x700) == 0x700)) {
        M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_s0, u16 *, 0x18) | 0x8000);
        M2C_FIELD(arg0, s16 *, 2) = 1;
        Pad_Vibrate(0, 1, 3, arg0);
        temp_a1 = M2C_FIELD(temp_s0, s16 *, 0xE);
        if (temp_a1 >= 0) {
            M2C_FIELD(((temp_a1 << 5) + D_800B4D64), s16 *, 0x16) = 0;
            Fx_Explosion(temp_s0, M2C_FIELD(temp_s0, s16 *, 0xE), 1);
            Camera_StartShake(0);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F330);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F400);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F574);

INCLUDE_ASM("asm/ovl/406/nonmatchings/406_sushi_temple", func_8013F5D4);
