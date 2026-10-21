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

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013DFEC);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013E05C);

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

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013ECA8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013ED00);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EE30);

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

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EF94);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013EFF8);

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_8013F380);

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

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_80140374);

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
