#include "common.h"
#include "m2c_macros.h"

s32 func_800569C4(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Objects;
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
M2C_UNK func_80052864(void *);
s32 Object_SpikeInFront(void *, s32, s32, s16);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
M2C_UNK VectorNormalSS(void *, void *);

M2C_UNK func_80051E98(void *, M2C_UNK);
M2C_UNK func_80088120(s8);
M2C_UNK func_8013F1CC(void *);
void Object_SpawnEffect(void *, s16, s32, s32, s32);
M2C_UNK Object_CameraShake(void *, M2C_UNK);

s32 SaveByte_Get(M2C_UNK);
M2C_UNK Effect_SpawnAt(M2C_UNK, s32);
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_DropPickups(void *);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_8013DD64(void *);
M2C_UNK func_800525E0();
M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_HeadTowardSpike(void *, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s32);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_800573A0(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801401D4(void *arg0);
extern s32 D_80145D24;
extern M2C_UNK D_80145D30;
s32 Spike_WithinRadiusXZ(s16, s16, s16);
s32 func_8013D118(void);
void func_80140530(void *arg0);
extern s32 D_80145D20;
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_80145D40;
extern struct S_D_800E77A0 { u8 pad_0[0x1]; u8 f_1; } D_800E77A0;
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s16 Sound_Play(M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = func_800569C4(0x64, 1);
    if (temp_v0 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0 * 0xE4)), 0);
    }
    temp_v0_2 = func_800569C4(0x65, 1);
    if (temp_v0_2 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0_2 * 0xE4)), 0);
    }
    temp_v0_3 = func_800569C4(0x51, 1);
    if (temp_v0_3 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0_3 * 0xE4)), 0);
    }
}

s32 func_8005BB5C(s32);

s32 func_8013D0C8(void) {
    s32 r;

    r = 0;
    if (SaveByte_Get(1) >= 2 || func_8005BB5C(1) >= 2) {
        r = 1;
    }
    return r;
}

s32 func_8013D118(void) {
    return SaveByte_Get(1) == 5;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D13C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D230);

typedef struct { u8 pad0[0x10]; s8 f; u8 pad11[3]; } Slot_406;
extern s32 D_80144F30;
extern Slot_406 *D_80144F34;

s32 func_8013D4F8(void) {
    s32 i;

    for (i = 0; i < D_80144F30; i++) {
        if (D_80144F34[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D54C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D628);

void func_8013D740(s16 *p) {
    p[0] += p[4];
    p[1] += p[5];
    p[2] += p[6];
    Effect_SpawnAt(0x2B, p);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D794);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DAFC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DC04);

void func_8013DD40(s32 arg0) {
    Effect_SpawnAt(4, arg0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DD64);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DF2C);

void func_8013E134(void) {
    Link_SendEvent(8, 6, 0);
}

void func_8013E15C(void *arg0) {
    Object_PlaySound(arg0, 0x60);
}

void func_8013E17C(void *arg0) {
    func_8013E15C(arg0);
    M2C_FIELD(arg0, s8 *, 0x80) = 0xD;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    func_8005588C(arg0, 0x5A);
    func_8013DD64(arg0);
    Object_DropPickups(arg0);
    Object_DisableCollision(arg0);
}

void func_8013E1D0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

void func_8013E1F4(void *arg0, s32 arg1) {
    u32 temp_s1;

    temp_s1 = (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C;
    if (temp_s1 == 0xB) {
        if ((Object_SpikeInFront(arg0, 0xB4, 0, 0) != 0) && (arg1 == 0)) {
            M2C_FIELD(arg0, s8 *, 0x80) = (s8) temp_s1;
            M2C_FIELD(arg0, s8 *, 0x7F) = 8;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x20);
            Object_DisableCollision(arg0);
            Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, 0x1000);
            Object_PlaySound(arg0, 0x67);
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
            return;
        }
        func_80052864(arg0);
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
        func_8013E1D0(arg0);
    }
}

s32 func_80056010(void *, M2C_UNK, M2C_UNK, M2C_UNK);

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013E308(obj)
    void *obj;
{
    return (s16)func_80056010(obj, 0x19, 4, 0);
}

s32 func_8013E334(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6 || Object_DetachLink(arg0, 1) == 6) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E384);

void func_8013E4C4(void *arg0, s32 n) {
    M2C_FIELD(arg0, u8 *, 0x7F) = n;
    M2C_FIELD(arg0, u8 *, 0x80) = 4;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E500);

void func_8013E654(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1 || d == f2) {
        Object_PlaySound(arg0, 0xB8);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E6A4);

void func_8013E7A8(void *arg0) {
    u32 f;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 0xB) {
        f = M2C_FIELD(arg0, u32 *, 0xE0) & 1;
        M2C_FIELD(arg0, u8 *, 0x80) = 0xC;
        if (f == 1) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0xC;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x30);
        } else {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0xD;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x34);
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x80) = 3;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

void func_8013E814(void *arg0) {
    Object_HeadTowardSpike(arg0, func_8013E308());
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), 0x2BC) == 0) {
        func_8013E4C4(arg0, 0xB);
    }
    Object_ApplyVelocity(arg0);
    func_8013E654(arg0, 0, 0x12);
}

extern s32 D_800EC208;

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013E888(arg0)
    void *arg0;
{
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28),
                               M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) == 0 &&
        M2C_FIELD(arg0, s32 *, 0x28) - 0x12C < D_800EC208) {
        return 1;
    }
    return 0;
}

void func_8013E8EC(void *arg0) {
    if (func_8013E888() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E930);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013EA4C);

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_408;
s32 Hook_Add(void *);
void func_8013F4B4(void);
void func_80052038(void *, s32);
void func_800520A8(void *, s32);
extern Mdl_408 D_80145280_s[] asm("D_80145280");

void func_8013F124(void) {
    s32 i;
    Mdl_408 *m;
    s32 k;

    if (Hook_Add(func_8013F4B4) == 1) {
        for (i = 0; i < 20; i++) {
            m = &D_80145280_s[i];
            k = (i & 1) + 0xA1;
            func_80052038(m, k);
            func_800520A8(m, k);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F1CC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F4B4);

void func_8013F65C(void *arg0) {
    s8 temp_a0;

    Object_SpawnEffect(arg0, 6, 0, 0x80, 0);
    func_8013F1CC(arg0);
    Object_PlaySound(arg0, 0x4D);
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 - 1);
    func_80051E98(arg0, 0);
    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
}

void func_8013F6DC(void *arg0) {
    s32 var_a0;

    var_a0 = 0;
    if (M2C_FIELD(arg0, u8 *, 0xDD) != 0) {
        var_a0 = 0xA00;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x20), var_a0 | 1, 0x201);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FB20);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FF2C);

void func_8014006C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
}

void func_80140088(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x80) = 7;
    if (arg1 != 0) {
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801400B4);

void func_801401D4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

unsigned long func_801401F8(void *arg0)
{
  if (((*((u32 *) (((s8 *) arg0) + 0x50))) >> 28) == 6)
  {
    *((u8 *) (((s8 *) arg0) + 0x80)) = 8;
    *((u8 *) (((s8 *) arg0) + 0x7F)) = 0xA;
    *((u16 *) (((s8 *) arg0) + 0x5C)) = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x88)))) + 0x28));
    Object_PlaySound(arg0, 0xB5);
  }
}

s32 func_80140244(void *arg0) {
    if ((D_80145D24 != 0) || (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) != 0xB)) {
        return 0;
    }
    func_800573A0(arg0, 0, 0, 0);
    Sound_PlayFixed(0x60);
    Sound_PlayFixed(0x15);
    Object_PlaySound(arg0, 0xB4);
    M2C_FIELD(arg0, s8 *, 0x7F) = 5;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
    func_801401D4(arg0);
    return 1;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801402D8);

s16 func_80140358(void *obj) {
    if (D_80145D24 != 0) {
        return func_80056010(obj, 0x28, 4, 0);
    }
    return func_80056010(obj, 0x14, 4, 0);
}

void func_80140398(s32 arg0, s32 arg1) {
    Puff_Spawn(arg0, 0, 0, arg1 + 0xFA);
}

void func_801403C0(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x78);
    func_80140398(M2C_FIELD(arg0, s32 *, 0x74), 0);
    func_80140398(temp_s0, 0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801403FC);

void func_80140530(void *arg0) {
    M2C_FIELD(&D_80145D30, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(&D_80145D30, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    M2C_FIELD(&D_80145D30, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

extern u32 g_Game_80140554 asm("g_Game");

void func_80140554(void *arg0) {
    switch (g_Game_80140554 & 3) {
    case 0:
        func_80052038(arg0, 0x1E);
        break;
    case 1:
        func_80052038(arg0, 0x89);
        break;
    case 2:
        func_80052038(arg0, 0x8B);
        break;
    case 3:
        func_80052038(arg0, 0x8C);
        break;
    }
}

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_801405BC(void *arg0, u8 mask) {
    if (!((RAND() >> 8) & mask)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140610);

M2C_UNK func_80140610(void *, s32);

void func_80140778(void *arg0) {
    u8 temp_v1;
    u8 *a;

    if (D_80145D24 != 0) {
        func_801405BC(arg0, 0xF);
        func_80140610(arg0, D_80145D24 < 0x1E);
        D_80145D24 -= 1;
        if (M2C_FIELD(arg0, u8 *, 0x80) != 8) {
            if (Object_DetachLink(arg0, 0) == 6) {
                if (M2C_FIELD(arg0, u8 *, 0x80) != 3) {
                    a = M2C_FIELD(arg0, u8 **, 0x88);
                    D_80145D24 = 0x1F;
                    M2C_FIELD(arg0, u8 *, 0x80) = 8U;
                    M2C_FIELD(arg0, s8 *, 0x7F) = 0xA;
                    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(a, u16 *, 0x28);
                    Object_PlaySound(arg0, 0xB5);
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xFA, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x15E), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x203);
            }
        }
        if (D_80145D24 != 0) {
            temp_v1 = M2C_FIELD(arg0, u8 *, 0x80);
            if ((temp_v1 == 3) || (temp_v1 == 8)) {
                func_80140554(arg0);
                return;
            }
            goto block_12;
        }
block_12:
        func_80052038(arg0, 0x1E);
        func_8005588C(arg0, 0x78);
    }
}

void func_801408C8(void *arg0, s32 arg1) {
    Object_SpawnEffect(arg0, 5, (s16) (-((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x41) >> 0xB) * arg1), 0, (s32) (s16) (((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x41) >> 0xB) * arg1));
    Object_PlaySound(arg0, 0xB7);
    Object_CameraShake(arg0, 0);
}

void func_8014095C(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1) {
        func_801408C8(arg0, 1);
    } else if (d == f2) {
        func_801408C8(arg0, -1);
    }
}

M2C_UNK Object_StepOnGroundFixed(s32);
s32 Object_WouldLeaveHome(void *, s16);

void func_801409AC(s32 arg0, s32 arg1) {
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_StepOnGroundFixed(arg0);
        return;
    }
    if ((arg1 != 0) && (D_80145D24 >= 0x1E)) {
        D_80145D24 = 0x1D;
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140A18);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140B40);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140C54);

void func_80140EE0(void *arg0) {
    if ((func_8013D0C8() != 0) && (func_8013D118() == 0) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) != 0)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        func_8005588C(arg0, 0x3C);
        func_80140530(arg0);
        D_80145D20 = 2;
    }
}

void func_80140F5C(void) {
    Link_SendEvent(5, 1, 0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140F84);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014183C);

M2C_UNK func_8006F274(void *, void *, u16);
extern M2C_UNK D_80145D48;
extern u16 g_Game;

void func_8014194C(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F) * 0x10;
    func_8006F274((u8 *)&D_80145D48 + temp_v0, (u8 *)&D_80145D48 - 8 + temp_v0, g_Game);
}

void func_8014198C(void *arg0) {
    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn((void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10)), 0, 0, 0x64);
    }
}

void func_801419DC(void *arg0) {
    void *temp_v1;

    M2C_FIELD(arg0, u8 *, 0x8F) = (u8) D_800E77A0.f_1;
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 + 1);
    temp_v1 = (void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10));
    M2C_FIELD(temp_v1, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(temp_v1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) + 0x12C);
    M2C_FIELD(temp_v1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141A38);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141AE0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141C90);

s16 Object_FloorAt(void *, s32, s32, s32);

s32 func_80141D64(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

void func_80141DDC(void *arg0) {
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

void func_80141EB8(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

u32 Object_DetachLink(void *, s32);

void func_80141F38(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141FDC);

void func_8006D568(void *);

void func_80142218(void *arg0) {
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

void func_801422E8(void *arg0) {
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

s32 func_801423E4(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_80142418(void *arg0) {
    if (func_801423E4(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8014246C(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801424D4);

extern struct S_g_Game_801426B4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801426B4 asm("g_Game");
void func_8008FC30(s32, s16 *);

s32 func_801426B4(s16 *p) {
    u8 *e = g_Game_801426B4.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142840);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014296C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142CCC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142DB0);

extern struct S_g_Game_80142FD8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80142FD8 asm("g_Game");

s32 func_80142FD8(s16 *p) {
    u16 *e = (u16 *)(g_Game_80142FD8.f_820C + p[2] * 0x38);
    u8 *f = g_Game_80142FD8.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(f, s16 *, 2) == 1) {
        p[1] = 2;
        e[2] += p[6];
    } else {
        p[1] = 0;
        p[3] = 0;
        e[0x14] = e[2];
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143068);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014318C);

s32 func_80143240(void) {
    return 0;
}

extern struct S_g_Game_80143248 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143248 asm("g_Game");
extern s16 D_800AFA20;

s32 func_80143248(s16 *p)
{
  u8 *e = g_Game_80143248.f_820C + (p[2] * 0x38);
  s16 new_var2;
  int new_var;
  if (D_800AFA20 != 0)
  {
    new_var2 = p[4];
    *((s16 *) (((s8 *) e) + 0x1C)) = 2;
    *((s16 *) (((s8 *) e) + 0x36)) = 0;
    *((u16 *) (((s8 *) e) + 0x2C)) = new_var2;
    *((u16 *) (((s8 *) e) + 0x12)) |= 0x103;
    *((u16 *) (((s8 *) e) + 0x18)) = (new_var = ((*((u16 *) (((s8 *) e) + 0x18))) & 0xFFF0) | 2);
    *((s16 *) (((s8 *) e) + 0xC)) = ((*((s16 *) (((s8 *) e) + 0xC))) << 1) / 360;
  }
  return 0;
}

s32 func_801432E8(void) {
    return 0;
}

extern struct S_g_Game_801432F0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801432F0 asm("g_Game");

s32 func_801432F0(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game_801432F0.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 3;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143344);

s32 func_80143524(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143534);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801436A8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801437E8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801439C8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143A64);

extern struct S_g_Game_80143B14 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143B14 asm("g_Game");

s32 func_80143B14(s16 *p) {
    u8 *e = g_Game_80143B14.f_820C + p[2] * 0x38;
    s32 v = p[10];

    if (v == 1) {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        p[1] = v;
    } else {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        p[1] = 0;
    }
    return 0;
}

extern struct S_g_Game_80143B8C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143B8C asm("g_Game");
extern s16 D_800EC238;

s32 func_80143B8C(s16 *p) {
    u8 *e = g_Game_80143B8C.f_820C + p[2] * 0x38;

    if (p[1] == 0 && D_800EC238 == p[2]) {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        p[1] = 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143BF8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143CC0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143E94);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143FA8);

extern struct S_g_Game_80144240 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game_80144240 asm("g_Game");

s32 func_80144240(s16 *p) {
    u8 *e = g_Game_80144240.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144280);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144438);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801444E4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801446D4);

s32 func_8014483C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 8) = Sound_Play(1, 0xB1);
    return 0;
}

extern struct S_g_Game_80144870 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80144870 asm("g_Game");
void Sound_UpdateVoice3D(s32, s32, s32, void *);

s32 func_80144870(s16 *p) {
    Sound_UpdateVoice3D(0xB1, p[4], 0x1000, g_Game_80144870.f_820C + p[2] * 0x38);
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
