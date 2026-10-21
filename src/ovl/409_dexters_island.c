#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

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

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_408;
void func_8013DE2C(void);
extern Mdl_408 D_80145280_s[] asm("D_80142CE0");

void func_8013DA9C(void) {
    s32 i;
    Mdl_408 *m;
    s32 k;

    if (Hook_Add(func_8013DE2C) == 1) {
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

M2C_UNK func_80051E98_8013E11C(void *, M2C_UNK) asm("func_80051E98");
M2C_UNK func_8013DB44(void *);
void Object_SpawnEffect(void *, s16, s32, s32, s32);
M2C_UNK Object_PlaySound_8013E11C(void *, M2C_UNK) asm("Object_PlaySound");
extern struct S_D_800E77A0_8013E11C { u8 pad_0[0x1]; u8 f_1; } D_800E77A0_8013E11C asm("D_800E77A0");

void func_8013E11C(void *arg0) {
    s8 temp_a0;

    Object_SpawnEffect(arg0, 6, 0, 0x80, 0);
    func_8013DB44(arg0);
    Object_PlaySound_8013E11C(arg0, 0x4D);
    D_800E77A0_8013E11C.f_1 = (u8) (D_800E77A0_8013E11C.f_1 - 1);
    func_80051E98_8013E11C(arg0, 0);
    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
}

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

void Matrix_FromDirection(void *, s32);
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern u8 D_80144190[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140938 asm("g_Game");

void func_80140938(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80144190 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game_80140938.f_80 + g_Game_80140938.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801440F0");
void func_80140CAC(void);
void Hook_Add(void *);

void func_80140A00(void *arg0) {
    s32 i;

    func_80140898(arg0, D_80144190, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(func_80140CAC);
}

s32 func_80140A54(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

s16 rsin_8013D858(s16) asm("rsin");
extern u8 D_801440F0[];

void func_80140A90(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = func_80140A54();
  if (i != (-1))
  {
    p = D_801440F0 + (i * 0x14);
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

s32 func_80140BC8(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_80140C0C(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140C4C);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140CAC);

void func_80140E88(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_80140EB4(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_80140F44(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_80140E88(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80140FD4);

void func_80141038(void *arg0) {
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

s32 func_80141110(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        func_80140E88(arg0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_8014116C);

s32 Math_Atan2(s32, s32);

void func_801413F8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

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

s32 func_801416DC(void *arg0) {
    u8 old;

    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
        old = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0xCE) = old;
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800525E0(arg0);
        func_80052864(arg0);
        return 1;
    }
    return 0;
}

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

s32 func_8014277C(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_801427C4);

INCLUDE_ASM("asm/ovl/409/nonmatchings/409_dexters_island", func_80142810);
