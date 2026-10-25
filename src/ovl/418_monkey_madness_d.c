#include "common.h"
#include "m2c_macros.h"

M2C_UNK VectorNormalSS(void *, void *);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_800573A0(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void Object_TurnToward(void *, s16, s16, s16, s16);
M2C_UNK func_8013E214();
M2C_UNK func_8013E52C();
extern struct S_g_Game { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xE4]; s32 f_820C; u8 pad_8210[0x4]; s32 f_8214; } g_Game;
s32 func_800889A4();

extern struct S_D_800E7880 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; } D_800E7880;

M2C_UNK Object_PlaySound(void *, M2C_UNK);
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
extern M2C_UNK D_801434C0;
extern M2C_UNK D_801434C4;
s32 SaveByte_Get(M2C_UNK);
extern s32 D_800B4D64;

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D000);

void func_8006D568(void *);

void func_8013D374(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x8F) != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        M2C_FIELD(arg0, u16 *, 0xBC) += M2C_FIELD(arg0, u16 *, 0x94);
        M2C_FIELD(arg0, u16 *, 0xBE) += M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0xC0) += M2C_FIELD(arg0, u16 *, 0x98);
        v.vx = M2C_FIELD(arg0, u16 *, 0xBC);
        v.vy = M2C_FIELD(arg0, u16 *, 0xBE);
        v.vz = M2C_FIELD(arg0, u16 *, 0xC0);
        func_8006D568(&v);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x50, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        if (M2C_FIELD(arg0, u8 *, 0x8F) >= 0x33) {
            M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        }
    }
}

void func_8013D444(void *arg0) {
    u8 st;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        st = M2C_FIELD(arg0, u8 *, 0x7F);
        if (st == 2 && M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4) + 7) {
            M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x96) = (M2C_FIELD(arg0, s16 *, 0x62) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0xBC) = M2C_FIELD(arg0, u16 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94) * 2;
            M2C_FIELD(arg0, s16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96) * 2;
            M2C_FIELD(arg0, s16 *, 0xC0) = M2C_FIELD(arg0, u16 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98) * 2;
            Object_PlaySound(arg0, 0x4D);
            M2C_FIELD(arg0, s8 *, 0x8F) = 1;
            M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        }
    }
}

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013D540(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_8013D574(void *arg0) {
    if (func_8013D540(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8013D5C8(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D630);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013D810);

extern struct { u8 pad_0[0x8126]; u16 f_8126; } g_Game_8013DC1C asm("g_Game");
s32 func_8005BB5C(s32);
void func_80051E98(void *, s32);
void Object_TurnTowardSpike(void *);

void func_8013DC1C(u8 *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 100;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(arg0, s16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0xE0) |= 8;
    }
    if (SaveByte_Get(5) >= 5 || (func_8005BB5C(6) >= 5 && g_Game_8013DC1C.f_8126 == 0x4C)) {
        func_80051E98(arg0, 0);
    } else {
        Object_TurnTowardSpike(arg0);
    }
}

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

void func_8013DF40(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, 0x1000);
    func_800573A0(arg0, 0, 0, 0);
    Sound_PlayFixed(0x5F);
    Sound_PlayFixed(0x15);
    Object_PlaySound(arg0, 0xB6);
}

s32 func_8013DFEC(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        func_8013DF40(arg0);
        return 1;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        func_8013DF40(arg0);
        M2C_FIELD(arg0, u8 *, 0xDC) = 0x63;
        return 1;
    }
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E05C asm("g_Spike");
s32 rcos_8013E05C(s32) asm("rcos");
s32 rsin_8013E05C(s32) asm("rsin");
s32 Math_Atan2(s32, s32);
M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK func_80055AA0(void *, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);
void Object_StepOrbitAngle(void *, s32);

void func_8013E05C(u8 *arg0) {
    s32 ang;
    s32 bob;
    s32 r;
    s32 h;

    ang = Math_Atan2(M2C_FIELD(arg0, s32 *, 0x24) - g_Spike_8013E05C.x, M2C_FIELD(arg0, s32 *, 0x2C) - g_Spike_8013E05C.z);
    bob = rsin_8013E05C(M2C_FIELD(arg0, s16 *, 0xAA)) / 32;
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 40, 20, 0);
    }
    ang = (ang + 0x200) % 0x1000;
    r = bob + 300;
    func_80055AA0(arg0, (u16)g_Spike_8013E05C.x + ((rcos_8013E05C(ang) * r) >> 12), (u16)g_Spike_8013E05C.z + ((rsin_8013E05C(ang) * r) >> 12), M2C_FIELD(arg0, s16 *, 0xA8) >> 3);
    Object_StepOrbitAngle(arg0, 16);
    h = M2C_FIELD(arg0, s32 *, 0x28) + 0xB4;
    M2C_FIELD(arg0, s16 *, 0x96) = (g_Spike_8013E05C.y - h - bob) >> 3;
    Object_ApplyVelocity(arg0);
}

void func_8013E1B4(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0xE0) & 1) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) == 0)) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E214);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E52C);

void func_8013E7A4(void) {
    if (g_Game.f_8126 == 0x4C) {
        func_8013E52C();
        return;
    }
    func_8013E214();
}

s16 Object_FloorAt(void *, s32, s32, s32);
extern s32 D_800EC208;

s32 func_8013E7F4(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

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

void func_8013E948(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
u32 Object_DetachLink(void *, s32);

void func_8013E9C8(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EA6C);

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013ECA8(void *arg0, s32 n) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - n * 11 - 0xC8;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(0x2D, &v);
}

void *Object_AddAttackSphere(void *, s16, s16, s16, s16, s16, s16);

void func_8013ED00(u8 *a, void *b) {
    s32 f = M2C_FIELD(a, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(a, u8 **, 0x88) + a[0x7F] * 4);

    if (f == 0x2A) {
        Object_PlaySound(a, 0x1A);
    }
    if (!(M2C_FIELD(a, u32 *, 0xE0) & 1) && f >= 0x30 && f < 0x36) {
        if (Object_DetachLink(a, 0) == 6) {
            M2C_FIELD(a, u32 *, 0xE0) |= 1;
        } else {
            M2C_FIELD(a, void **, 0xB4) = Object_AddAttackSphere(b, 0x12C,
                M2C_FIELD(a, s16 *, 0x24) + ((M2C_FIELD(a, s16 *, 0x60) * 25) >> 9),
                M2C_FIELD(a, s16 *, 0x28) - 0xC8,
                M2C_FIELD(a, s16 *, 0x2C) + ((M2C_FIELD(a, s16 *, 0x64) * 25) >> 9),
                1, 0x203);
        }
    }
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013EE30 asm("g_Spike");

void func_8013EE30(u8 *arg0, u8 *arg1) {
    s32 dx = g_Spike_8013EE30.x - M2C_FIELD(arg0, s32 *, 0x24);
    s32 dz = g_Spike_8013EE30.z - M2C_FIELD(arg0, s32 *, 0x2C);
    s32 d = dx * dx + dz * dz;
    s32 near = 0x40000;

    if (d > 0x240000 || M2C_FIELD(arg1, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x80) != 6 && d < near) {
        M2C_FIELD(arg0, u8 *, 0x80) = 6;
        M2C_FIELD(arg0, u8 *, 0x7F) = 2;
        M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 8);
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~1;
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x10000;
    }
}

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK func_80055AA0(void *, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013EEF4(void *arg0, s32 arg1, s32 arg2)
{
  int new_var;
  if (((*((u16 *) (((s8 *) arg0) + 0xE2))) & 1) == arg1)
  {
    Object_StepGrowShrink(arg0, 0x32, 0xA, 0);
  }
  new_var = 0x24;
  if (arg2 != 0)
  {
    func_80055AA0(arg0, *((s16 *) (((s8 *) (&g_Spike)) + new_var)), *((s16 *) (((s8 *) (&g_Spike)) + 0x2C)), ((s32) ((*((u16 *) (((s8 *) arg0) + 0xA8))) << 0x10)) >> 0x13);
    *((s16 *) (((s8 *) arg0) + 0x96)) = (s16) (((s32) ((*((s32 *) (((s8 *) (&g_Spike)) + 0x28))) - (*((s32 *) (((s8 *) arg0) + 0x28))))) >> 2);
  }
  else
  {
    *((s16 *) (((s8 *) arg0) + 0x96)) = 0;
    *((s16 *) (((s8 *) arg0) + 0xAE)) = 0;
  }
  Object_ApplyVelocity(arg0);
}

void func_80052038(void *, s32);

void func_8013EF94(void *arg0) {
    u16 end = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88) + 2);

    if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 10) {
        func_80052038(arg0, 0xB1);
    } else if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 8) {
        func_80052038(arg0, 0x18);
    } else if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 2) {
        func_80052038(arg0, 0xB3);
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EFF8);

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_418;
s32 Hook_Add(void *);
void func_8013F618(void);
void func_800520A8(void *, s32);
extern Mdl_418 D_80142C40_s[] asm("D_80142C40");

void func_8013F380(void) {
    s32 i;
    Mdl_418 *m;

    if (Hook_Add(func_8013F618) == 1) {
        for (i = 0; i < 16; i++) {
            m = &D_80142C40_s[i];
            func_80052038(m, 0xB5);
            func_800520A8(m, 0xB5);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F418);

typedef struct { s16 x, y, z; } Rot_404;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_404 r; u8 pad82; u8 life; s16 scale; s16 floor; } Debris_404;
extern Debris_404 D_80142C40[16];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F618 asm("g_Game");
extern u8 D_800E7D00_8013DB40[] asm("D_800E7D00");
s32 func_80051410(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void ScaleMatrix_8013DB40(void *, void *) asm("ScaleMatrix");
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80016EBC(void *, void *, void *);
void Model_ProjectBonedVerts(void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);

void func_8013F618(void) {
    s32 i;
    Debris_404 *d;
    s32 s[3];
    SVECTOR v;

    for (i = 0; i < 16; i++) {
        d = &D_80142C40[i];
        if (d->life != 0) {
            d->life--;
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            if (d->floor < d->y) {
                d->y = d->floor;
                d->vy = -(d->vy / 2);
                v.vx = d->x;
                v.vy = d->y;
                v.vz = d->z;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (func_80051410(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                s[0] = s[1] = s[2] = d->scale;
                ScaleMatrix_8013DB40(d->mat, s);
                func_80015780(d, 3);
                Model_ProjectBonedVerts(d);
                func_80016EBC(g_Game_8013F618.f_80 + g_Game_8013F618.f_C * 0x4078, D_800E7D00_8013DB40, d);
            }
        }
    }
}

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

s32 func_8013FA8C(s32 *arg0, void **arg1) {
    s16 temp_a0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (func_800889A4() * 0x38);
    if (M2C_FIELD(temp_a1, u8 *, 0x12) == 0xD) {
        temp_a0 = M2C_FIELD(temp_a1, s16 *, 0x22);
        if (temp_a0 >= 0) {
            *arg0 = g_Game.f_8214 + (temp_a0 * 0x10);
            *arg1 = temp_a1 + 0x32;
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

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
    D_800E7880.f_0 = 0;
    D_800E7880.f_8 = 0;
    D_800E7880.f_4 = 0;
    D_800E7880.f_C = 0;
    D_800E7880.f_14 = 0;
    D_800E7880.f_10 = 0;
    D_800E7880.f_18 = 0;
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_80140374;
extern Snd_80140374 D_801434C0_80140374 asm("D_801434C0");
extern Snd_80140374 D_801434C4_80140374 asm("D_801434C4");
extern struct { s16 a; s16 b; } D_800B4DB0_80140374 asm("D_800B4DB0");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; u8 pad_1C[0x18]; s32 f_34; } D_800E7880_80140374 asm("D_800E7880");
s32 Sound_PlayTracked(s32, s32);

s32 func_80140374(u8 *e) {
    M2C_FIELD(e, s16 *, 0x36) = 4;
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    D_801434C0_80140374.id = Sound_PlayTracked(0, 0x50AD);
    D_801434C0_80140374.on = 1;
    D_801434C4_80140374.id = Sound_PlayTracked(0, 0x50AE);
    D_801434C4_80140374.on = 1;
    D_800E7880_80140374.f_0 = 0;
    D_800E7880_80140374.f_8 = 0;
    D_800E7880_80140374.f_4 = 0;
    D_800E7880_80140374.f_C = 0;
    D_800E7880_80140374.f_14 = 0;
    D_800E7880_80140374.f_10 = 0;
    D_800E7880_80140374.f_18 = 0;
    D_800E7880_80140374.f_34 = 0;
    D_800B4DB0_80140374.a = 0x1000;
    D_800B4DB0_80140374.b = 0x1000;
    return D_801434C0_80140374.id;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140430);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801408CC);

s32 func_80140988(void) {
    s32 temp_v1;

    temp_v1 = D_800E7880.f_14 + 0x10;
    D_800E7880.f_8 = (s32) (D_800E7880.f_8 + temp_v1);
    D_800E7880.f_14 = temp_v1;
    D_800E7880.f_0 = (s32) (D_800E7880.f_0 + ((s32) D_800E7880.f_C / 2));
    D_800E7880.f_4 = (s32) (D_800E7880.f_4 + ((s32) (D_800E7880.f_10 + ((u32) D_800E7880.f_10 >> 0x1F)) >> 1));
    return 0;
}

typedef struct { s16 type; s16 sub; s16 v[5]; s16 next; } Node_801409E8;
extern struct { u8 pad_0[0x218]; Node_801409E8 *f_218; } D_800F4350_801409E8 asm("D_800F4350");

s32 func_801409E8(u8 *arg0, s32 *out) {
    Node_801409E8 *n;
    s16 i;

    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = 0xFFFF;
    i = M2C_FIELD(arg0, s16 *, 0x30);
    if (i < 0) {
        return 0;
    }
    do {
        n = &D_800F4350_801409E8.f_218[i];
        if (n->type == 7) {
            if (n->sub == 0x50) {
                out[0] = n->v[1];
                out[1] = n->v[2];
                out[2] = n->v[3];
            } else if (n->sub == 0x53) {
                out[3] = n->v[0];
            } else if (n->sub == 0x45) {
                out[4] = n->v[0];
            }
        }
        i = n->next;
    } while (i >= 0);
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140AC4);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140D18);

extern struct { u8 pad_0[0x812A]; u16 f_812A; u8 pad_812C[0xE0]; u8 *f_820C; } g_Game_80140F30 asm("g_Game");
extern u8 *D_800B4D64_80140F30 asm("D_800B4D64");
s32 func_801402F8(void);

s32 func_80140F30(s16 *p) {
    u8 *e = g_Game_80140F30.f_820C + p[2] * 0x38;

    if (g_Game_80140F30.f_812A == 0) {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    } else {
        p[1] = 5;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80140F30 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        func_801402D8(e);
        func_801402F8();
    }
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140FE0);

s32 func_8014119C(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    p[3] = 0;
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[1] = 0;
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_801411E8;
extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; } g_Game_801411E8 asm("g_Game");
extern s16 D_800EC238;
extern Snd_801411E8 D_801434C8;
extern Snd_801411E8 D_801434C0_801411E8 asm("D_801434C0");
extern Snd_801411E8 D_801434C4_801411E8 asm("D_801434C4");
extern struct { s16 a; s16 b; } D_800B4DB0;
extern struct { u8 pad_0[0x34]; s32 f_34; s32 f_38; } D_800E7880_801411E8 asm("D_800E7880");
s32 Sound_Play(s32, s32);
s32 Sound_PlayTracked(s32, s32);
void Sound_Stop(s32, s32);

s32 func_801411E8(s16 *p) {
    u8 *e = g_Game_801411E8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            g_Game_801411E8.f_8150 = 2;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 1;
            D_801434C8.id = Sound_Play(0, 0xAC);
            D_801434C8.on = 1;
            D_801434C0_801411E8.id = Sound_PlayTracked(0, 0x50AD);
            D_801434C0_801411E8.on = 1;
            D_801434C4_801411E8.id = Sound_PlayTracked(0, 0x50AE);
            D_801434C4_801411E8.on = 1;
            D_800B4DB0.a = 0x1000;
            D_800B4DB0.b = 0x1000;
            D_800E7880_801411E8.f_34 = 0;
            D_800E7880_801411E8.f_38 = 0;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] > 32) {
            Sound_Stop(0xAC, D_801434C8.id);
            D_801434C8.on = 0;
            D_801434C8.id = -1;
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_8014134C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8014134C asm("g_Game");
typedef struct { u8 pad_0[0x20C]; u8 *f_820C; u8 pad_210[0x10]; u8 *f_8220; } G_8014134C;
extern G_8014134C D_800F4350_8014134C asm("D_800F4350");
extern u8 *D_800B4D64_8014134C asm("D_800B4D64");

s32 func_8014134C(s16 *p) {
    G_8014134C *g;
    u8 *d;
    u8 *t;
    s32 i;
    u8 *e = g_Game_8014134C.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[1] = p[10];
    p[3] = 0;
    if (p[4] == 0 && M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_8014134C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    if (p[10] == 1) {
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8014134C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        i = p[5];
        p[7] = M2C_FIELD(e, u16 *, 0);
        p[8] = M2C_FIELD(e, u16 *, 2);
        p[9] = M2C_FIELD(e, u16 *, 4);
        if (i >= 0) {
            g = &D_800F4350_8014134C;
            d = D_800B4D64_8014134C;
            do {
                t = g->f_8220 + i * 0x18;
                e = g->f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
                if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                    M2C_FIELD(d + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
                }
            } while ((i = M2C_FIELD(t, s16 *, 0xA)) >= 0);
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_801414A0;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_801414A0 *f_8220; } g_Game_801414A0 asm("g_Game");
extern u8 *D_800B4D64_801414A0 asm("D_800B4D64");
void CamFlyby_StartSegment(s32);

s32 func_801414A0(s16 *p) {
    u8 *e;
    S18_801414A0 *t;
    s32 i;
    u8 *d;

    if (p[2] < 0) {
        return 0;
    }
    CamFlyby_StartSegment(0);
    g_Game_801414A0.f_8100 = 7;
    e = g_Game_801414A0.f_820C + p[2] * 0x38;
    p[1] = 1;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_801414A0 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
    }
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    p[7] = M2C_FIELD(e, s16 *, 0);
    p[8] = M2C_FIELD(e, s16 *, 2);
    p[9] = M2C_FIELD(e, s16 *, 4);
    i = p[5];
    if (i >= 0) {
        d = D_800B4D64_801414A0;
        do {
        t = g_Game_801414A0.f_8220 + i;
        e = g_Game_801414A0.f_820C + t->f[2] * 0x38;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(d + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        i = t->f[5];
        } while (i >= 0);
    }
    return 0;
}

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

s32 func_80141CD4(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    if (M2C_FIELD(e, s16 *, 0x32) == p[4]) {
        Sound_PlayFixed(0x78);
    }
    return 0;
}

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

extern struct { u8 pad_0[0x8120]; u16 f_8120; } g_Game_80141F6C asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80141F6C asm("g_Spike");
s32 Overlay_GetState_80141F6C(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 func_800863B0(s32, s32);

s32 func_80141F6C(s16 *p) {
    if (g_Game_80141F6C.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (g_Spike_80141F6C.x < -0xEFF) {
            return 0;
        }
        if (g_Spike_80141F6C.y >= -0x5DC) {
            return 0;
        }
        if (g_Spike_80141F6C.z < -0x13FF) {
            return 0;
        }
        p[1] = 4;
        p[3] = 0;
        func_800863B0(2, 0x28);
        Overlay_Request(4);
        return 0;
    case 4:
        if (Overlay_GetState_80141F6C() != 0) {
            return 0;
        }
        p[1] = 5;
        func_800863B0(0, 0);
        break;
    case 5:
        break;
    }
    return 0;
}

void RotMatrixZYX(SVECTOR *, void *);

s32 func_80142054(s16 *p) {
    SVECTOR r;

    if (p[6] >= 0) {
        p[1] = 0;
        p[3] = 0;
        r.vy = 0;
        r.vx = 0;
        r.vz = (-p[7] << 12) / 360;
        RotMatrixZYX(&r, M2C_FIELD(D_800B4D64 + p[6] * 32, void **, 0x1C));
    } else {
        p[1] = 4;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801420E8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8014277C);

s32 func_80142800(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80142808);
