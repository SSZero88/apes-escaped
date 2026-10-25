#include "common.h"
#include "m2c_macros.h"

M2C_UNK VectorNormalSS(void *, void *);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
extern s32 D_800B4D64;
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; u8 pad_8210[0x10]; s32 f_8220; } g_Game;
M2C_UNK Sound_PlayFixed(M2C_UNK, void *);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);

void func_8006D568(void *);

void func_8013D000(void *arg0) {
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

void func_8013D0D0(void *arg0) {
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

s32 func_8013D1CC(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_8013D200(void *arg0) {
    if (func_8013D1CC(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8013D254(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D2BC);

s16 Object_FloorAt(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);
extern s32 D_800EC208;
s32 Spike_WithinRadiusXZ(s32, s32, s32);

s32 func_8013D49C(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

void func_8013D514(void *arg0) {
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

s32 Spike_WithinRadiusXZ(s32, s32, s32);

void func_8013D5F0(void *arg0) {
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

void func_8013D670(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D714);

s32 func_8013D950(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 1;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013D9A4);

s32 func_8013DA34(void *arg0) {
    s16 temp_a0;
    s16 temp_a0_2;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x14);
    if (M2C_FIELD(arg0, s16 *, 8) == 0) {
        temp_a0 = M2C_FIELD(temp_a1, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    if ((s16) M2C_FIELD(arg0, u16 *, 0x14) == 1) {
        temp_a0_2 = M2C_FIELD(temp_a1, s16 *, 0xE);
        if (temp_a0_2 >= 0) {
            M2C_FIELD(((temp_a0_2 << 5) + D_800B4D64), u16 *, 0x16) = 0xFFFF;
        }
        M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 2);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DAFC);

s32 func_8013DC70(s32 arg0, s16 arg1) {
    s16 temp_a0;
    void *temp_a2;
    void *temp_v1;

    temp_a2 = g_Game.f_8220 + (arg0 * 0x18);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(temp_a2, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 2);
    if (M2C_FIELD(temp_a2, s16 *, 8) == 0) {
        temp_a0 = M2C_FIELD(temp_v1, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), u16 *, 0x16) = 0xFFFF;
        }
    }
    M2C_FIELD(temp_a2, s16 *, 2) = arg1;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013DD08 asm("g_Game");

s32 func_8013DD08(s16 *p) {
    u8 *e = g_Game_8013DD08.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    if (p[4] == 0) {
        p[1] = 0;
        M2C_FIELD(e, s16 *, 0x14) = 0;
        M2C_FIELD(e, u16 *, 0x12) &= 0xF0FF;
    } else {
        M2C_FIELD(e, u16 *, 0x14) = p[5];
        M2C_FIELD(e, u16 *, 0x12) &= 0xF0FF;
        if (p[5] & 0xE) {
            M2C_FIELD(e, u16 *, 0x12) |= 0x400;
        } else {
            M2C_FIELD(e, u16 *, 0x12) |= 0x500;
        }
        func_8008FC30(p[6], p);
        p[1] = 2;
    }
    p[3] = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013DDD8 asm("g_Game");

s32 func_8013DDD8(s16 *p) {
    u8 *e = g_Game_8013DDD8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        M2C_FIELD(e, s16 *, 0x14) = 0;
        break;
    case 1:
        M2C_FIELD(e, u16 *, 0x14) = p[5];
        M2C_FIELD(e, u16 *, 0x12) &= 0xF0FF;
        if (p[5] & 0xE) {
            M2C_FIELD(e, u16 *, 0x12) |= 0x400;
        } else {
            M2C_FIELD(e, u16 *, 0x12) |= 0x500;
        }
        func_8008FC30(p[6], p);
        p[1] = 2;
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013DE90 asm("g_Game");
extern u8 *D_800B4D64_8013DE90 asm("D_800B4D64");
s32 func_8008FC30(s16, void *);

s32 func_8013DE90(s16 *p) {
    u8 *e = g_Game_8013DE90.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
        M2C_FIELD(e, s16 *, 0x14) = 1;
        M2C_FIELD(e, u16 *, 0x12) = (M2C_FIELD(e, u16 *, 0x12) & 0xF0FF) | 0x500;
    } else {
        p[1] = 2;
        func_8008FC30(p[6], p);
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013DE90 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x12) &= 0xF0FF;
        M2C_FIELD(e, u16 *, 0x2) += p[8];
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013DE90 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x12) += p[8];
        }
        p[3] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013DFAC);

s32 func_8013E170(void *arg0) {
    s16 temp_a1;
    void *temp_a0;

    temp_a0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (((u16) M2C_FIELD(arg0, u16 *, 8) >> 8) == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
        M2C_FIELD(arg0, s16 *, 6) = 3;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
        M2C_FIELD(arg0, s16 *, 0x16) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 2;
        temp_a1 = M2C_FIELD(temp_a0, s16 *, 0xE);
        if (temp_a1 >= 0) {
            M2C_FIELD(((temp_a1 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
        M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x18) | 0x8000);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E208);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E3A4 asm("g_Game");
extern u8 *D_800B4D64_8013E3A4 asm("D_800B4D64");
void func_8013E54C(u8 *);

s32 func_8013E3A4(s16 *p) {
    u8 *e = g_Game_8013E3A4.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[3] = 0;
    p[1] = p[10];
    if (p[4] == 0) {
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013E3A4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    if (p[10] == 1) {
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013E3A4 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        p[1] = 2;
        while (M2C_FIELD(e, s16 *, 0x32) < p[6] * 2 + 1) {
            func_8013E54C(e);
        }
    }
    return 0;
}

s32 func_8013E4A8(void *arg0) {
    void *temp_a0;

    temp_a0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 2) == 1) {
        if (M2C_FIELD(temp_a0, s16 *, 0x32) >= (M2C_FIELD(arg0, s16 *, 0xC) * 2)) {
            M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a0, u16 *, 0x18) & 0xFFF0) | 1);
            M2C_FIELD(arg0, s16 *, 2) = 2;
        }
        if (M2C_FIELD(temp_a0, s16 *, 0x32) == (M2C_FIELD(arg0, s16 *, 0x16) * 2)) {
            Sound_PlayFixed(0x2A, arg0);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/400/nonmatchings/400_cryptic_relics", func_8013E54C);
