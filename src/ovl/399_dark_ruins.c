#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);

M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
M2C_UNK Object_ChaseSpike(void *, M2C_UNK);
s32 Object_DetachLink(void *, M2C_UNK);
s32 Object_SpikeOutOfRange(void *, s16, s32, s16, s32);
M2C_UNK Object_StepOnGroundFixed(void *);
M2C_UNK func_80051E98(void *, M2C_UNK);
s32 func_8005588C(void *, M2C_UNK);
M2C_UNK func_80055DC0(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_80056128(void *, M2C_UNK);
s32 func_800572CC(void *);
M2C_UNK func_80058134(void *, s16);
M2C_UNK Object_PlaySound(s32, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_ApplyVelocity();
void func_8013D6EC(s32 arg0);
M2C_UNK Hook_Add(M2C_UNK *);
void func_8013DDD8(void);
extern struct S_D_80141418 { u8 pad_0[0x10]; s8 f_10; u8 pad_11[0x3]; } D_80141418[];
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
extern struct S_D_801413F0 { u8 pad_0[0x18]; s32 f_18; u8 pad_1C[0x4]; s32 f_20; } D_801413F0;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
s32 rcos(s16);
s32 rsin(s16);

void func_80052038_8013D000(void *, s32) asm("func_80052038");
void func_80052134_8013D000(void *, s32) asm("func_80052134");

void func_8013D000(u8 *a) {
    func_80052038_8013D000(a, 0x69);
    func_80052134_8013D000(a, 0x69);
    M2C_FIELD(a, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(a, u8 *, 0xCD) = 2;
    M2C_FIELD(a, s16 *, 0x48) = 1;
    switch (M2C_FIELD(a, u8 *, 0x7E)) {
    case 0x67:
        M2C_FIELD(a, u8 *, 0xC8) = 16;
        M2C_FIELD(a, s16 *, 0x44) = 0x6E;
        M2C_FIELD(a, s16 *, 0xA0) = 0x50;
        M2C_FIELD(a, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(a, u8 *, 0x81) = 0x1E;
        M2C_FIELD(a, u8 *, 0x80) = 1;
        M2C_FIELD(a, u8 *, 0x7F) = 0;
        M2C_FIELD(a, u16 *, 0x5C) = *M2C_FIELD(a, u16 **, 0x88);
        break;
    case 0x68:
        M2C_FIELD(a, u8 *, 0xC8) = 12;
        M2C_FIELD(a, s16 *, 0x44) = 0x37;
        M2C_FIELD(a, s16 *, 0xA0) = 0x28;
        M2C_FIELD(a, s16 *, 0x4A) = -0x7DFE;
        M2C_FIELD(a, u8 *, 0x81) = 0x14;
        M2C_FIELD(a, u8 *, 0x80) = 2;
        M2C_FIELD(a, u8 *, 0x7F) = 2;
        M2C_FIELD(a, u16 *, 0x5C) = M2C_FIELD(a, u16 **, 0x88)[4];
        break;
    case 0x69:
        M2C_FIELD(a, u8 *, 0xC8) = 7;
        M2C_FIELD(a, s16 *, 0x44) = 0x1B;
        M2C_FIELD(a, s16 *, 0xA0) = 0x14;
        M2C_FIELD(a, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(a, u8 *, 0x81) = 2;
        M2C_FIELD(a, u8 *, 0xDC) = 0;
        M2C_FIELD(a, u8 *, 0x80) = 2;
        M2C_FIELD(a, u8 *, 0x7F) = 2;
        M2C_FIELD(a, u16 *, 0x5C) = M2C_FIELD(a, u16 **, 0x88)[4];
        break;
    }
}

extern s16 D_800E77E0;
extern u8 g_Objects_8013D130[] asm("g_Objects");

u8 *func_8013D130(u8 *arg0, s32 type, s32 flag) {
    s32 i;
    u8 *o;

    for (i = 0; i < D_800E77E0; i++) {
        o = g_Objects_8013D130 + i * 0xE4;
        if (M2C_FIELD(arg0, s8 *, 0xCB) != i && o[0x7E] == type && ((M2C_FIELD(o, u32 *, 0xE0) >> 4) & 1) == flag &&
            M2C_FIELD(o, s16 *, 0x9A) == M2C_FIELD(arg0, s16 *, 0x9A) && M2C_FIELD(o, s32 *, 0x9C) == M2C_FIELD(arg0, s32 *, 0x9C)) {
            return o;
        }
    }
    return 0;
}

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013D1CC(arg0)
    void *arg0;
{
    if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x68) {
        return func_8013D130(arg0, 0x67, 1);
    }
    return 0;
}

void func_8013D200(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x96) = -0x2D;
    M2C_FIELD(arg0, s16 *, 0x94) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & ~0x20) | 0x400);
}

M2C_UNK func_80056AE4(void *, void *, s8);

void func_8013D228(void *arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_s3;
    void *temp_v0;

    temp_s3 = (s32) (M2C_FIELD(arg0, s16 *, 0x64) * -0xF) >> 0xC;
    temp_s2 = (s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 0xC;
    temp_v0 = func_8013D130(arg0, arg1, 0);
    if (temp_v0 != NULL) {
        func_80056AE4(temp_v0, arg0 + 0x24, M2C_FIELD(arg0, s8 *, 0xCB));
        func_8013D200(temp_v0, temp_s3, temp_s2);
    }
    M2C_FIELD(arg0, s8 *, 0x7E) = arg1;
    func_8013D200(arg0, -temp_s3, -temp_s2);
    func_8013D000(arg0);
}


void func_8013D2DC(void *arg0) {
    u8 s = M2C_FIELD(arg0, u8 *, 0x7E);
    if (s == 0x67) {
        func_8013D228(arg0, 0x68);
    } else if (s == 0x68) {
        func_8013D228(arg0, 0x69);
    }
    func_800573A0(arg0, 0, 0, 0);
}

void func_800573A0(void *, s32, s32, s32);

void func_8013D33C(s32 arg0) {
    func_800573A0(arg0, 0, 0, 0);
    func_80051E98(arg0, 1);
}

void func_8013D378(void *arg0) {
    s32 var_a1;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x7E);
    var_a1 = 0x118;
    if (temp_v1 != 0x67) {
        var_a1 = 0x46;
        if (temp_v1 == 0x68) {
            var_a1 = 0x8C;
        }
    }
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = var_a1;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = ((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) * 2) + var_a1;
}

void func_8013D3D8(u8 *a) {
    s32 f;

    if (a[0x80] != 2) {
        f = M2C_FIELD(a, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(a, u8 **, 0x88) + a[0x7F] * 4);
        if (f == 6 && Spike_WithinRadiusXZ(M2C_FIELD(a, s32 *, 0x24), M2C_FIELD(a, s32 *, 0x2C), 0x800)) {
            Object_PlaySound(a, 0x68);
        } else if (f == 0x15) {
            Object_SpawnEffect(a, 5, 0, 0, 0);
        }
    }
}

void func_8013D484(void *arg0) {
    u8 temp_v1;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        if (func_8013D1CC() != 0) {
            func_80051E98(arg0, 0);
            return;
        }
        func_8013D000(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) | 8);
        goto block_4;
    }
block_4:
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 0x14) & 1) {
        func_8013D2DC(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFFEFFFFF);
    }
    func_8013D378(arg0);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x80);
    switch (temp_v1) {                              /* irregular */
    case 1:
        if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0) {
            Object_ChaseSpike(arg0, 0xE);
        } else {
            func_80055DC0(arg0, 0xE, 0);
        }
        Object_StepOnGroundFixed(arg0);
        if (Object_DetachLink(arg0, 0) == 6) {
            if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x69) {
                func_8013D33C(arg0);
            } else {
                M2C_FIELD(arg0, u8 *, 0x80) = 3U;
                func_8005588C(arg0, 0x3C);
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) ((u16) M2C_FIELD(arg0, s32 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 3:
        func_80056128(arg0, 0xE);
        Object_StepOnGroundFixed(arg0);
        if (func_8005588C(arg0, -1) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
        }
        break;
    case 2:
        if (func_800572CC(arg0) != 0) {
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
            M2C_FIELD(arg0, s16 *, 0x96) = 0;
            M2C_FIELD(arg0, s16 *, 0x94) = 0;
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
        }
        break;
    }
    func_8013D3D8(arg0);
}

void func_8013D6CC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
}

void func_8013D6EC(s32 arg0) {
    u16 temp_v0;

    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 7)) {
        Object_PlaySound(arg0, 0xB1);
    }
}

void func_8013D738(s32 arg0) {
    Object_ApplyVelocity();
    func_8013D6EC(arg0);
}

void func_8013D764(void *arg0) {
    u16 temp_v1;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, void **, 0x90);
    if (func_80055718(arg0, M2C_FIELD(temp_v0, s16 *, 0), M2C_FIELD(temp_v0, s16 *, 2), M2C_FIELD(temp_v0, s16 *, 4), 0xC) != 0) {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0x90);
        Object_TurnToward(arg0, (s16) (M2C_FIELD(temp_v0_2, u16 *, 8) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(temp_v0_2, u16 *, 0xC) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
    }
    func_8013D738(arg0);
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    temp_a0 = (M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88);
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((u16) M2C_FIELD(temp_a0, u16 *, 2) < (u32) (temp_v1 & 0xFFFF)) {
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a0, u16 *, 0);
    }
}

void func_8013D834(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        Object_PlaySound(arg0, 0x15);
    }
}

extern u8 D_80141248[];
void func_800702B0(SVECTOR *, void *);
void Object_DropPickups(void *);

void func_8013D868(void *arg0) {
    SVECTOR v;

    Object_PlaySound(arg0, 0x4D);
    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    func_800702B0(&v, D_80141248);
    Object_DropPickups(arg0);
    func_80051E98(arg0, 1);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013D8CC);

void func_8013DBF8(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_80141418[i].f_10 = 0;
    }
    Hook_Add(&func_8013DDD8);
}

typedef struct { u8 pad0[0x10]; s8 f; u8 pad[0x3]; } Slot_399;
extern Slot_399 D_80141418_s[32] asm("D_80141418");

s32 func_8013DC3C(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        if (D_80141418_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013DC78);

M2C_UNK Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
extern s32 D_800EC208;
extern M2C_UNK g_Objects;

void func_8013DD24(void *arg0) {
    s16 temp_a3;
    s32 var_v0;
    void *temp_s1;

    temp_s1 = (u8 *)&g_Objects + (M2C_FIELD(arg0, s8 *, 0x12) * 0xE4);
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 4), 0xC8) != 0) {
        temp_a3 = M2C_FIELD(arg0, s16 *, 2);
        var_v0 = (temp_a3 - D_800EC208) + 0x7D;
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 < 0xC9) {
            Object_AddAttackSphere(temp_s1, 0x64, M2C_FIELD(arg0, s16 *, 0), temp_a3, (s32) M2C_FIELD(arg0, s16 *, 4), 0x201, 0x202);
        }
    }
}

typedef struct { s16 x, y, z, pad; s16 vx, vy, vz, pad2; s8 life; u8 pad11[3]; } Drop_399;

void func_8013DDD8(void) {
    s32 i;
    Drop_399 *e;

    for (i = 31; i >= 0; i--) {
        e = &D_80141418[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            func_8006D548(e);
            func_8013DD24(e);
        }
    }
}

extern u8 D_80141254[];
void *memset(void *, s32, s32);

void func_8013DE6C(void *arg0) {
    SVECTOR w;
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    w = v;
    func_800702B0(&w, D_80141254);
    Object_PlaySound(arg0, 0x4D);
    Object_DropPickups(arg0);
    func_80051E98(arg0, 1);
}

void func_8013DF08(void) {
    Link_SendEvent(4, 3, 0);
    Link_SendEvent(7, 0x11, 0);
}

void func_8013DC78(void *, void *, s32);

void func_8013DF40(u8 *o) {
    SVECTOR p;
    SVECTOR v;

    v.vx = M2C_FIELD(o, s16 *, 0x60) / 48;
    v.vy = 0;
    v.vz = M2C_FIELD(o, s16 *, 0x64) / 48;
    p.vx = M2C_FIELD(o, u16 *, 0x24) + (M2C_FIELD(o, s16 *, 0x60) * 85 >> 11);
    p.vy = M2C_FIELD(o, u16 *, 0x28) - 0x5A;
    p.vz = M2C_FIELD(o, u16 *, 0x2C) + (M2C_FIELD(o, s16 *, 0x64) * 85 >> 11);
    func_8013DC78(&p, &v, M2C_FIELD(o, s8 *, 0xCB));
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E020);

extern s32 D_801413F0_8013E1A0 asm("D_801413F0");

void func_8013E1A0(void *arg0) {
    switch (D_801413F0_8013E1A0) {
    case 0:
        M2C_FIELD(arg0, u8 *, 0x80) = 3;
        M2C_FIELD(arg0, u8 *, 0x7F) = 2;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 8);
        break;
    case 1:
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        M2C_FIELD(arg0, u8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0xC);
        M2C_FIELD(arg0, u16 *, 0x5C) += M2C_FIELD(arg0, u8 *, 0x8F);
        break;
    case 2:
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0xC);
        M2C_FIELD(arg0, u16 *, 0x5C) += M2C_FIELD(arg0, u8 *, 0x8F);
        break;
    }
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E22C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E2BC);

void func_8013E57C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70B0, 0x1000, arg0 + 0x24);
    }
}

void func_8013E5BC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

typedef struct { u8 pad0[0x28]; u16 y; u8 pad2A[0x54]; u8 kind; u8 pad7F[0x1D]; u16 f_9C; u8 pad9E[0x42]; u32 flags; u8 padE4[0]; } Obj_399;
extern Obj_399 g_Objects_399[] asm("g_Objects");
extern s16 D_800E77E0;

void func_8013E600(void) {
    s32 i;
    Obj_399 *o;

    for (i = D_800E77E0 - 1; i >= 0; i--) {
        o = &g_Objects_399[i];
        if (o->kind == 0x1A && (o->flags >> 4) & 1) {
            o->f_9C = o->y;
        }
    }
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E680);

extern u8 D_800E77A0[];
u8 *func_80056BC4(s32, s32 *, s32);

void func_8013E74C(u8 *o) {
    s32 pos[3];
    s32 i;

    pos[0] = M2C_FIELD(o, s32 *, 0x24);
    pos[1] = M2C_FIELD(o, s32 *, 0x28) - 0xAA;
    pos[2] = M2C_FIELD(o, s32 *, 0x2C);
    M2C_FIELD(func_80056BC4(0x1A, pos, M2C_FIELD(o, s8 *, 0xCB)), u8 *, 0x8F) = 0;
    for (i = 0; i < D_800E77A0[1] - 1; i++) {
        pos[1] -= 0x118;
        M2C_FIELD(func_80056BC4(0x1A, pos, M2C_FIELD(o, s8 *, 0xCB)), u8 *, 0x8F) = i + 1;
    }
}

void func_8013E810(void) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = D_801413F0.f_18 + (((D_801413F0.f_20 + 3) << 0xC) / 360);
    var_v0 = temp_a0;
    if (temp_a0 < 0) {
        var_v0 = temp_a0 + 0xFFF;
    }
    D_801413F0.f_18 = (s32) (temp_a0 - ((var_v0 >> 0xC) << 0xC));
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013E86C);

void func_8006D548(SVECTOR *);

void func_8013EBBC(void *arg0, s16 x, s16 y, s16 z) {
    SVECTOR v;

    v.vx = x;
    v.vy = y;
    v.vz = z;
    func_8006D548(&v);
    Object_AddAttackSphereNear(arg0, M2C_FIELD(arg0, u16 *, 0x44) + 0x32, v.vx, v.vy, v.vz,
                               M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
}

s32 func_8013EC28(void *arg0, s32 arg1, s32 arg2) {
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

void func_8013ED0C(void *arg0)
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

void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern M2C_UNK D_800B1C28;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013ED7C(void *arg0)
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
  Object_TurnToward(arg0, g_Spike.x - (*((u16 *) (((s8 *) arg0) + 0x24))), (&g_Spike)->z - (*((u16 *) (((s8 *) arg0) + 0x2C))), 0, 0x1000);
  v.vx = *((u16 *) (((s8 *) arg0) + 0x24));
  v.vy = *((u16 *) (((s8 *) arg0) + 0x28));
  v.vz = *((u16 *) (((s8 *) arg0) + 0x2C));
  Fx_SpawnFadeRing(&v, 0, 0x1B0, 0xC);
  v.vy -= 0x80;
  func_80070284(&v, &D_800B1C28, 1, 0xC, 0);
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EE70);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013EF54);

s32 Math_Atan2(s32, s32);

void func_8013F0A0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013F12C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
}

s32 func_800563E0(void *, s32);

void func_8013F17C(void *arg0) {
    func_800563E0(arg0, 0x14);
}

void func_8013F19C(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013F17C(arg0);
}

void Object_PlaySound_8013F260(void *, s32) asm("Object_PlaySound");
s32 Object_StepGrowShrink(void *, s16, s16, s16);
void func_8013F0A0(void *arg0);

void func_8013F260(u8 *a) {
    s16 *v;

    if (Object_DetachLink(a, 0) == 6) {
        Object_PlaySound_8013F260(a, 0x5F);
        func_8013F0A0(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(a, 0x53, 0x37, 0);
    }
    if (func_80055718(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        func_8013F0A0(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

void func_800525E0(void *);
void func_80052864(void *);

s32 func_8013F384(void *arg0) {
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

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F408);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013F6FC);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013F9C0 asm("g_Game");
extern u8 *D_800B4D64_8013F9C0 asm("D_800B4D64");

s32 func_8013F9C0(s16 *p) {
    u8 *e = g_Game_8013F9C0.f_820C + p[2] * 0x38;
    u8 *e2;

    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 1;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013F9C0 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (p[5] >= 0) {
            e2 = g_Game_8013F9C0.f_820C + p[5] * 0x38;
            M2C_FIELD(e2, u16 *, 0x18) |= 0x8000;
            if (M2C_FIELD(e2, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013F9C0 + M2C_FIELD(e2, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013FA8C);

extern s32 D_801413E8;

s32 func_8013FC18(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    p[1] = 0;
    p[3] = 0;
    p[10] = 0;
    D_801413E8 = -1;
    M2C_FIELD(e, s16 *, 0x1C) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_8013FC64);

s32 func_80140098(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801400E4);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140368);

s32 func_8014060C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8014061C asm("g_Game");
extern s32 D_800EC20C;
extern u8 *D_800B4D64_8014061C asm("D_800B4D64");

s32 func_8014061C(s16 *p) {
    u8 *t;
    u8 *e;

    if (p[1] == 0 && p[4] < D_800EC20C) {
        p[1] = 1;
        if (p[5] >= 0) {
            t = g_Game_8014061C.f_8220 + p[5] * 0x18;
            e = g_Game_8014061C.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
            if (M2C_FIELD(t, s16 *, 2) == 1) {
                M2C_FIELD(t, s16 *, 2) = 2;
                if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                    M2C_FIELD(D_800B4D64_8014061C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
                }
            }
        }
    }
    return 0;
}

s16 func_80092324(s16 *, u16 *);

s32 func_801406D4(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    e[0x12] = e[0];
    e[0x13] = e[1];
    e[0x14] = e[2];
    e[0x19] = e[3];
    e[0x1A] = e[4];
    e[0x1B] = e[5];
    p[11] = p[5];
    p[1] = 0;
    p[3] = 0;
    e[8] = func_80092324(p, e);
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140768);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8014090C asm("g_Game");
s32 Model_SetTurnAngle(s16, s16, s32);

s32 func_8014090C(s16 *p) {
    u8 *e = g_Game_8014090C.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0x0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 0x2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 0x4);
    M2C_FIELD(e, u16 *, 0x32) = M2C_FIELD(e, u16 *, 0x6);
    M2C_FIELD(e, u16 *, 0x34) = M2C_FIELD(e, u16 *, 0x8);
    M2C_FIELD(e, u16 *, 0x36) = M2C_FIELD(e, u16 *, 0xA);
    p[1] = 0;
    p[3] = 0;
    p[11] = 0;
    M2C_FIELD(e, s16 *, 0x10) = func_80092324(p, e);
    if (p[4] == 1) {
        Model_SetTurnAngle(3, p[6], p[11]);
    } else {
        Model_SetTurnAngle(2, p[6], p[11]);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_801409D8);

extern u8 *D_800B4D64;

s32 func_80140B50(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);
    s32 d;
    u16 y;

    e[0xC] = (e[0xC] & 0xFFF0) | 1;
    e[0x14] = e[2];
    if (p[10] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 2;
        d = (s16)e[5] * 2;
        p[3] = d;
        y = e[0x14] + d;
        e[2] = y;
        if ((s16)e[7] >= 0) {
            M2C_FIELD(D_800B4D64 + (s16)e[7] * 32, u16 *, 0x14) = y;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140BF4 asm("g_Game");
extern u8 *D_800B4D64_80140BF4 asm("D_800B4D64");

s32 func_80140BF4(s16 *p) {
    u8 *e = g_Game_80140BF4.f_820C + p[2] * 0x38;
    s16 v;

    if (p[1] == 1) {
        p[3] += (M2C_FIELD(e, s16 *, 0xA) * 2) / p[6];
        if (M2C_FIELD(e, s16 *, 0xA) * 2 < p[3]) {
            p[3] = M2C_FIELD(e, s16 *, 0xA) * 2;
            p[1] = 2;
            Sound_PlayFixed(0x80);
        }
        v = M2C_FIELD(e, s16 *, 4) = M2C_FIELD(e, u16 *, 0x28) + p[3];
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80140BF4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x14) = v;
        }
    }
    return 0;
}

s32 func_80140CF8(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(temp_v1, u16 *, 0x26) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80140D4C);

INCLUDE_ASM("asm/ovl/399/nonmatchings/399_dark_ruins", func_80141034);

s32 func_801410F4(void *arg0) {
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(temp_a1, s16 *, 0x32) == M2C_FIELD(arg0, s16 *, 8)) {
        Sound_PlayAt(0xAE, temp_a1);
    }
    return 0;
}
