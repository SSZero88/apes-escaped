#include "common.h"
#include "m2c_macros.h"

s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
extern s32 D_800EC208;

s32 rsin(s16, s32);
extern struct S_D_800E77A0 { u8 pad_0[0x8]; s16 f_8; s16 f_A; s16 f_C; } D_800E77A0;
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D000);

s16 func_8013D0B0(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_a0;
    u16 temp_v0_3;
    void *temp_v0_2;

    temp_v0_2 = (M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88);
    temp_v0_3 = M2C_FIELD(temp_v0_2, u16 *, 0);
    temp_a1 = M2C_FIELD(temp_v0_2, u16 *, 2) - temp_v0_3;
    temp_lo = (s32) (((s32) (M2C_FIELD(arg0, u16 *, 0x5C) - temp_v0_3) % temp_a1) << 0xC) / temp_a1;
    temp_v0 = temp_lo + 0xC00;
    var_a0 = temp_v0;
    if (temp_v0 < 0) {
        var_a0 = temp_lo + 0x1BFF;
    }
    return (s16) (((s32) (rsin((s16) (temp_v0 - ((var_a0 >> 0xC) << 0xC)), temp_a1) * (arg1 - arg2)) >> 0xD) + ((s32) (arg1 + arg2) / 2));
}

s32 func_8013D1C4(void) {
    s32 var_a0;
    s32 var_v0;

    var_v0 = D_800E77A0.f_A - D_800EC208;
    var_v0 = __builtin_abs(var_v0);
    var_a0 = 0;
    if (var_v0 < 0x32) {
        var_a0 = Spike_WithinRadiusXZ(D_800E77A0.f_8, D_800E77A0.f_C, 0xC8) != 0;
    }
    return var_a0;
}

s32 func_8013D224(void) {
    s32 var_v0;
    s32 var_v0_2;

    var_v0_2 = D_800E77A0.f_A - D_800EC208;
    var_v0_2 = __builtin_abs(var_v0_2);
    if ((var_v0_2 >= 0x33) || (var_v0 = 0, (Spike_WithinRadiusXZ(D_800E77A0.f_8, D_800E77A0.f_C, 0xFA) == 0))) {
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D294);

void func_8013D3B8(void *arg0) {
    D_800E77A0.f_A = (s16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0xB4);
    D_800E77A0.f_8 = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x60) * 0x96) >> 0xC));
    D_800E77A0.f_C = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x64) * 0x96) >> 0xC));
}

void func_8013D430(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (temp_v0 - 1);
        return;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x8F) = 0xAU;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere(arg0, 0xC8, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xAF) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xFA), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0xAF) >> 0xB)), 0, 0x101);
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013D518);

void func_8013D660(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void Matrix_FromDirection(void *, s32);
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern u8 D_8013F340[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void func_8013D700(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_8013F340 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_8013F2A0");
void func_8013DA94(void);
void Hook_Add(void *);

void func_8013D7C8(void *arg0) {
    s32 i;

    func_8013D660(arg0, D_8013F340, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(func_8013DA94);
}

s32 func_8013D81C(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

s16 rcos(s16);
s16 rsin_8013D858(s16) asm("rsin");
extern u8 D_8013F2A0[];

void func_8013D858(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = func_8013D81C();
  if (i != (-1))
  {
    p = D_8013F2A0 + (i * 0x14);
    c = rcos(*((s16 *) (((s8 *) arg0) + 0xAC)));
    s = rsin_8013D858(*((s16 *) (((s8 *) arg0) + 0xAC)));
    *((s16 *) (((s8 *) p) + 0)) = (*((u16 *) (((s8 *) arg0) + 0x24))) + ((c * arg2) >> 12);
    *((s16 *) (((s8 *) p) + 2)) = (*((u16 *) (((s8 *) arg0) + 0x28))) - arg1;
    *((s16 *) (((s8 *) p) + 4)) = (*((u16 *) (((s8 *) arg0) + 0x2C))) + ((s * arg2) >> 12);
    *((s16 *) (((s8 *) p) + 6)) = c / 48;
    *((s16 *) (((s8 *) p) + 0xA)) = s / 48;
    *((s16 *) (((s8 *) p) + 8)) = -0x28;
    *((u16 *) (((s8 *) p) + 0xC)) += 1;
    *((s16 *) (((s8 *) p) + 0xE)) = *((s8 *) (((s8 *) arg0) + 0xCB));
  }
}

s32 func_8013D990(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013D9CC(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DA0C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DA94);

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013DC70(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800525E0(void *);
void func_80052864(void *);
void func_800573A0(void *, s32, s32, s32);

void func_8013DC9C(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013DD2C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013DC70(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

void Object_PlaySound(void *, s32);

void func_8013DDBC(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        func_8013D858(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

void Object_DisableCollision(void *);
s32 func_8005588C(void *, s32);

void func_8013DE20(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
    M2C_FIELD(arg0, s8 *, 0xCD) = 5;
    M2C_FIELD(arg0, s8 *, 0x7D) = 8;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0xE;
    M2C_FIELD(arg0, s8 *, 0xDC) = 1;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, s16 *, 0xA0) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    func_8005588C(arg0, M2C_FIELD(arg0, s16 *, 0x9A) % 60 + 60);
    Object_DisableCollision(arg0);
}

void Object_TurnTowardSpike(void *);

s32 func_8013DEF8(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        func_8013DC70(arg0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013DF54);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E1E0);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E33C);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013E950);

INCLUDE_ASM("asm/ovl/396/nonmatchings/396_primordial_ooze", func_8013F0C0);
