#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

s32 func_8013D520();
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void Effect_SpawnAt(s32, SVECTOR *);
extern u8 D_800B1C28[];

void func_8013D000(void *arg0, s32 dx, s32 dy, s32 dz) {
    SVECTOR v;
    SVECTOR r;
    s32 i;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + dx;
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) + dy;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + dz;
    Effect_SpawnAt(0x113, &v);
    for (i = 0; i < 3; i++) {
        r.vx = (RAND() >> 4) & 0xFF0;
        r.vy = (RAND() >> 4) & 0xFF0;
        r.vz = (RAND() >> 4) & 0xFF0;
        func_80070284(&v, D_800B1C28, 1, i * 2, &r);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D100);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D230);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D2FC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D3B4);

void func_8013D2FC(void *, s32, s32);
void Object_ApplyVelocity(void *);

void func_8013D4B8(void *arg0) {
    if (!(M2C_FIELD(arg0, u16 *, 0xE2) & 1)) {
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 0x10) {
            func_8013D2FC(arg0, -5, 0);
        } else {
            func_8013D2FC(arg0, -10, 1);
        }
        Object_ApplyVelocity(arg0);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D520);

void func_8013D578(void *arg0) {
    if (func_8013D520() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D5BC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D7AC);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D904);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D9EC);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 func_8013DA9C(void *arg0) {
    if (Object_SpikeInFront(arg0, 0x5A, 0xB50, 0x300) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(((M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, void **, 0x88)), u16 *, 2)) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 3U;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        }
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
        Object_PlaySound(arg0, 0xB4);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DB2C);

void Camera_StartShake(s32);

void func_8013DD04(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1 || d == f2) {
        Object_PlaySound(arg0, 0x43);
        Camera_StartShake(0);
    }
}

M2C_UNK Object_PlaceAtPathPoint(void *, M2C_UNK);
s32 func_80057140(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_8005866C(void *, M2C_UNK);

void func_8013DD5C(void *arg0)
{
  *((s16 *) (((s8 *) arg0) + 0xB0)) = 0x16;
  *((s16 *) (((s8 *) arg0) + 0x48)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x4A)) = -0x3DFD;
  *((s8 *) (((s8 *) arg0) + 0xC8)) = 7;
  *((s16 *) (((s8 *) arg0) + 0x44)) = 0x118;
  *((s8 *) (((s8 *) arg0) + 0x81)) = 3;
  *((s16 *) (((s8 *) arg0) + 0xA0)) = 0x190;
  *((u8 *) (((s8 *) arg0) + 0xDD)) = 0xFF;
  *((s16 *) (((s8 *) arg0) + 0x46)) = 0x190;
  *((s16 *) (((s8 *) arg0) + 0x98)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x96)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x94)) = 0;
  *((s16 *) (((s8 *) arg0) + 0xAC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) & (~0x1000));
  *((s16 *) (((s8 *) arg0) + 0x60)) = rcos(0);
  *((s16 *) (((s8 *) arg0) + 0x64)) = rsin(*((s16 *) (((s8 *) arg0) + 0xAC)));
  if ((*((u16 *) (((s8 *) arg0) + 0x8C))) != 0)
  {
    Object_PlaceAtPathPoint(arg0, 0);
    func_8005866C(arg0, 1);
  }
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) | 0x2000);
  *((s32 *) (((s8 *) arg0) + 0x74)) = func_80057140(arg0, 9, 0);
  *((s8 *) (((s8 *) arg0) + 0x7C)) = -1;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 4;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = (u16) (*((u16 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x88)))) + 0x10)));
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DE5C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E7B8);

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

void func_8013E8A4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern u8 D_8014117C[];

void func_8013E8FC(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        func_80070284(&v, D_8014117C, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013E998(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 func_8013E9C8(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013E9F8(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013EA34(void *arg0) {
    if ((func_8013E9C8(arg0) == 0) && (func_8013E9F8(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013EA88);

void func_8013EBE8(s32 arg0) {
    if (func_8013E998() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013EC2C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013EC6C(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013ECD4);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013EFBC);

void func_8013F2EC(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80141380[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F38C asm("g_Game");

void func_8013F38C(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80141380 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game_8013F38C.f_80 + g_Game_8013F38C.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { u8 pad0[0xC]; s16 active; u8 padE[6]; } Drip_405;
extern Drip_405 D_801412E0_s[8] asm("D_801412E0");

void func_8013F454(void *arg0) {
    s32 i;

    func_8013F2EC(arg0, D_80141380, 0x83);
    for (i = 7; i >= 0; i--) {
        D_801412E0_s[i].active = 0;
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801412E0");

s32 func_8013F49C(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F4D8);

s32 func_8013F618(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013F654(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013F694(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013F6D4);

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013F89C(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800573A0(void *, s32, s32, s32);

void func_8013F8C8(void *arg0) {
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

void func_8013F958(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013F89C(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

M2C_UNK func_8013F4D8(void *, M2C_UNK, M2C_UNK);

void func_8013F9E8(void *obj) {
    func_8013F4D8(obj, 0x46, 0xA0);
}

void Object_DisableCollision(void *);

void func_8013FA0C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
    M2C_FIELD(arg0, u8 *, 0x7D) = 8;
    M2C_FIELD(arg0, u8 *, 0xC8) = 0xE;
    M2C_FIELD(arg0, u8 *, 0xCD) = 5;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u8 *, 0xDC) = 5;
    M2C_FIELD(arg0, s16 *, 0xA0) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    func_8005588C(arg0, (s16)(M2C_FIELD(arg0, s16 *, 0x9A) % 60) + 0x3C);
    func_8013F454(arg0);
    Object_DisableCollision(arg0);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013FAEC);

s32 Math_Atan2(s32, s32);

void func_8013FFD4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_80140060(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_80140098(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140160);

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F21C asm("g_Spike");

void func_80140284(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F21C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F21C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F21C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void func_801402D4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x200000;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x96) >= 0x39) {
        M2C_FIELD(arg0, u8 *, 0x82) = 0;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x100000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140348);

s32 func_801406E0(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(temp_v1, u16 *, 0x26) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_80140730);

s32 func_80140968(s16 *p) {
    p[1] = 0;
    p[3] = 0;
    p[9] = -1;
    p[10] = ((RAND() >> 8) & 7) * 30;
    return 0;
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_801409B0);

extern u32 g_Game_80140F94 asm("g_Game");
void Sound_PlayAt(s32, void *);

s32 func_80140F94(u8 *arg0) {
    if (g_Game_80140F94 % 10 == 0) {
        Sound_PlayAt(((RAND() >> 8) & 3) + 0xB6, arg0 + 8);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
