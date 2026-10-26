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

void Object_PlaceAtPathPoint(void *, s32);
void func_8005866C(void *, s32);
s32 func_800585D0(void *, s32, s32, s32);
void func_8013D6CC(void *arg0);
void func_8013D738(s32 arg0);
void func_8013D764(void *arg0);
void func_8013D834(void *arg0);
void func_8013D868(void *arg0);

void func_8013D8CC(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(o, u8 *, 0x83) = 2;
        M2C_FIELD(o, u8 *, 0xC8) = 0xF;
        M2C_FIELD(o, u8 *, 0x7D) = 0xA;
        {
            register s32 k50 asm("$3") = 0x50;
            M2C_FIELD(o, s16 *, 0xA0) = k50;
            M2C_FIELD(o, s16 *, 0x44) = k50;
        }
        {
            register s32 k3 asm("$3") = 3;
            M2C_FIELD(o, u8 *, 0xCD) = k3;
            M2C_FIELD(o, u8 *, 0x81) = k3;
        }
        M2C_FIELD(o, u8 *, 0xDC) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~0x1000) | 0x200000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        if (M2C_FIELD(o, u16 *, 0x8C)) {
            Object_PlaceAtPathPoint(o, 0);
            func_8005866C(o, 1);
        }
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82)) {
        return;
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x100000;
        if (!M2C_FIELD(o, u8 *, 0x81)) {
            func_8013D868(o);
            return;
        }
    }
    func_8013D834(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (!Object_SpikeOutOfRange(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s16 *, 0x9E), M2C_FIELD(o, s16 *, 0xA4))) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            { s32 one = 1; M2C_FIELD(o, u8 *, 0x8E) = one; }
            M2C_FIELD(o, u32 *, 0xE0) |= 0x1000;
        }
        break;
    case 2:
        if (func_800585D0(o, 0x32, 0, 1)) {
            func_8013D6CC(o);
        } else {
            func_8013D738((s32)o);
        }
        if (Object_DetachLink(o, 0) == 6) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[4];
            Object_PlaySound((s32)o, 0xB1);
        } else {
            M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphereNear(o, 0x82, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, u16 *, 0x28) - 0x64, M2C_FIELD(o, s16 *, 0x2C), 1, 0x202);
        }
        break;
    case 3:
        func_8013D6EC((s32)o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1]) {
            func_8013D6CC(o);
        }
        break;
    case 4:
        func_8013D764(o);
        break;
    case 5:
        if (M2C_FIELD(o, s16 *, 0xAE) == 0 && M2C_FIELD(o, u8 *, 0x7F) != 0) {
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
            func_8005588C(o, 0x3C);
            M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        }
        if (!func_8005588C(o, -1) && M2C_FIELD(o, u8 *, 0x7F) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
        }
        break;
    }
}

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

typedef struct { SVECTOR a; SVECTOR b; u8 f_10; u8 f_11; u8 f_12; u8 f_13; } Spark_8013DC78;
extern Spark_8013DC78 D_80141418_8013DC78[] asm("D_80141418");
s32 func_8013DC3C(void);

void func_8013DC78(void *a_, void *b_, s32 c) {
    SVECTOR *a = a_;
    SVECTOR *b = b_;
    s32 i = func_8013DC3C();
    Spark_8013DC78 *p;

    if (i != -1) {
        p = &D_80141418_8013DC78[i];
        p->a.vx = a->vx;
        p->a.vy = a->vy;
        p->a.vz = a->vz;
        p->b.vx = b->vx;
        p->b.vy = b->vy;
        p->b.vz = b->vz;
        p->f_10 = 6;
        p->f_12 = c;
    }
}

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

extern struct { s32 f0, f4, f8, fC, f10, f14; } D_801413F0_8013E020 asm("D_801413F0");
extern u8 D_800E77A0_8013E020[] asm("D_800E77A0");
u8 *Collision_GetShape_8013E020(s16) asm("Collision_GetShape");
s32 func_800525A0_8013E020(void *, void *) asm("func_800525A0");
void func_8005240C_8013E020(void *, void *) asm("func_8005240C");
void Object_PlaySound_8013E020(void *, s32) asm("Object_PlaySound");

void func_8013E020(void *arg0) {
    u8 *sh;

    if ((u8)(M2C_FIELD(arg0, u8 *, 0x80) - 1) < 2) {
        return;
    }
    if (D_801413F0_8013E020.f4 != 0) {
        return;
    }
    if (D_801413F0_8013E020.f0 == 2) {
        return;
    }
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) != 11) {
        return;
    }
    sh = Collision_GetShape_8013E020(M2C_FIELD(arg0, u16 *, 0x50) & 0xFFF);
    if ((M2C_FIELD(sh, s16 *, 0x24) & 0xFF00) == 0xD00) {
        return;
    }
    func_800525A0_8013E020(arg0, sh);
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        func_8005240C_8013E020(arg0, sh);
        D_801413F0_8013E020.f0 = 2;
        D_801413F0_8013E020.f8 = 0;
        D_801413F0_8013E020.fC = 0;
        D_800E77A0_8013E020[1]--;
    } else {
        D_801413F0_8013E020.f0 = 1;
    }
    D_801413F0_8013E020.f10 = M2C_FIELD(arg0, u8 *, 0x8F);
    D_801413F0_8013E020.f4 = 20;
    D_801413F0_8013E020.f14 = 1;
    M2C_FIELD(arg0, u8 *, 0x84) = 20;
    func_800573A0(arg0, (s16)(M2C_FIELD(sh, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0x24)),
                  (s16)(M2C_FIELD(sh, u16 *, 4) - M2C_FIELD(arg0, u16 *, 0x28)),
                  (s16)(M2C_FIELD(sh, u16 *, 8) - M2C_FIELD(arg0, u16 *, 0x2C)));
    Object_PlaySound_8013E020(arg0, 0x15);
    Object_PlaySound_8013E020(arg0, 0xB1);
}

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

extern s32 D_80141408;

void func_8013E22C(void *arg0, void *arg1) {
    s32 v;
    s32 t;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) >> 19) & 1) {
        v = M2C_FIELD(arg1, s16 *, 0xAC) + D_80141408;
    } else {
        t = D_80141408 - 0x1000;
        v = M2C_FIELD(arg1, s16 *, 0xAC) - t;
    }
    M2C_FIELD(arg0, volatile s16 *, 0xAC) = v % 4096;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(M2C_FIELD(arg0, s16 *, 0xAC));
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
}

extern struct { s32 f0, f4, f8, fC, f10, f14; } D_801413F0_8013E2BC asm("D_801413F0");
extern u8 g_Objects_8013E2BC[] asm("g_Objects");
void func_8013DE6C(void *arg0);
void func_8013DF40(u8 *o);
void func_8013E020(void *arg0);
void func_8013E1A0(void *arg0);
void Object_ClampAnimFrame(void *, s32);
#define ANIM_8013E2BC(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_8013E2BC(u8 *o) {
    u8 *m = g_Objects_8013E2BC + M2C_FIELD(o, s8 *, 0xCA) * 0xE4;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        M2C_FIELD(o, u8 *, 0xC8) = 0x10;
        M2C_FIELD(o, u8 *, 0x81) = 0x12;
        M2C_FIELD(o, s16 *, 0x44) = 0x8C;
        M2C_FIELD(o, s16 *, 0x46) = 0x118;
        M2C_FIELD(o, u8 *, 0x81) = 0xC;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~0x1000) | 0x200000;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0xDC) = 0;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~0x80000) | ((M2C_FIELD(o, u8 *, 0x8F) & 1) << 19);
        func_8013E22C(o, m);
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013E2BC(o, 0)[0];
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        return;
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 20) & 1) {
        func_8013DE6C(o);
        return;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013E020(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(m, u8 *, 0x80) == 2) {
            M2C_FIELD(o, u8 *, 0x80) = M2C_FIELD(m, u8 *, 0x80);
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013E2BC(o, 1)[0];
        }
        break;
    case 2:
        if (M2C_FIELD(m, u8 *, 0x80) == 3) {
            M2C_FIELD(o, u8 *, 0x80) = M2C_FIELD(m, u8 *, 0x80);
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013E2BC(o, 2)[0];
        }
        break;
    case 3:
        func_8013E22C(o, m);
        func_8013DF40(o);
        if (D_801413F0_8013E2BC.f0 != 0) {
            func_8013E1A0(o);
        }
        break;
    case 4:
        Object_ClampAnimFrame(o, ANIM_8013E2BC(o, M2C_FIELD(o, u8 *, 0x7F))[1]);
        func_8013E22C(o, m);
        func_8013DF40(o);
        if (D_801413F0_8013E2BC.f0 != 1) {
            func_8013E1A0(o);
        }
        break;
    case 5:
        func_8013DF40(o);
        if (D_801413F0_8013E2BC.f10 < M2C_FIELD(o, u8 *, 0x8F)) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) + D_801413F0_8013E2BC.fC;
        }
        if (D_801413F0_8013E2BC.f0 == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013E2BC(o, 2)[0];
        }
        break;
    }
}

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

extern u8 D_800E77A1;
void Object_PlaySound_8013E680(void *, s32) asm("Object_PlaySound");
void Object_DisableCollision(void *);
void func_8013E5BC(void *arg0);
void func_8013E600(void);

void func_8013E680(void *arg0) {
    if (D_801413F0_8013E020.f14 != 0) {
        D_801413F0_8013E020.f14 = 0;
        switch (D_801413F0_8013E020.f0) {
        case 1:
            M2C_FIELD(arg0, u8 *, 0x80) = 4;
            func_8005588C(arg0, 0x14);
            Object_PlaySound_8013E680(arg0, 0xB1);
            func_8013E5BC(arg0);
            break;
        case 2:
            M2C_FIELD(arg0, u8 *, 0x80) = 5;
            if (D_800E77A1 == 0) {
                func_8005588C(arg0, 0x50);
                Object_DisableCollision(arg0);
            } else {
                func_8005588C(arg0, 5);
                M2C_FIELD(arg0, u8 *, 0x8F) = 0;
                func_8013E600();
            }
            func_8013E5BC(arg0);
            break;
        }
    }
}

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

extern struct { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20; } D_801413F0_8013E86C asm("D_801413F0");
extern u32 g_Game_8013E86C asm("g_Game");
s32 Object_SpikeOutOfRange_8013E86C(void *, s32, s32, s32, s32) asm("Object_SpikeOutOfRange");
void func_8005866C(void *, s32);
void func_8013DBF8(void);
void func_8013DF08(void);
void func_8013E57C(void *arg0);
void func_8013E74C(u8 *o);
void func_8013E810_8013E86C(void *) asm("func_8013E810");

void func_8013E86C(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, u8 *, 0xC8) = 0x10;
        M2C_FIELD(o, s16 *, 0x44) = 0xC8;
        M2C_FIELD(o, s16 *, 0x46) = 0x12C;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        func_8013E74C(o);
        D_801413F0_8013E86C.f0 = 0;
        D_801413F0_8013E86C.f14 = 0;
        D_801413F0_8013E86C.f4 = 0;
        D_801413F0_8013E86C.f1C = 0;
        D_801413F0_8013E86C.f18 = 0;
        D_801413F0_8013E86C.f20 = 0;
        func_8013DBF8();
        if (M2C_FIELD(o, u16 *, 0x8C)) {
            func_8005866C(o, 1);
        }
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    if (D_801413F0_8013E86C.f4) {
        D_801413F0_8013E86C.f4--;
    }
    func_8013E680(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (!Object_SpikeOutOfRange_8013E86C(o, M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C), 0x300)) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            func_8005588C(o, 0x1E);
        }
        break;
    case 2:
        if (!func_8005588C(o, -1)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            func_8013E57C(o);
        }
        break;
    case 3:
        func_8013E810_8013E86C(o);
        break;
    case 4:
        func_8013E810_8013E86C(o);
        if (g_Game_8013E86C % 5 == 0 && (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1)) {
            Object_PlaySound_8013E020(o, 0xB1);
        }
        if (!func_8005588C(o, -1)) {
            D_801413F0_8013E86C.f0 = 0;
            M2C_FIELD(o, u8 *, 0x80) = 3;
            func_8013E57C(o);
        }
        break;
    case 5:
        if (!func_8005588C(o, -1)) {
            if (D_800E77A0[1]) {
                D_801413F0_8013E86C.f8 += 4;
                D_801413F0_8013E86C.fC += D_801413F0_8013E86C.f8;
                if (D_801413F0_8013E86C.fC >= 0x118) {
                    M2C_FIELD(o, u8 *, 0x8F)++;
                    D_801413F0_8013E86C.fC = 0x118;
                    if (D_800E77A0[1]) {
                        Object_PlaySound_8013E020(o, 0xB1);
                    }
                    if (M2C_FIELD(o, u8 *, 0x8F) >= 4) {
                        D_801413F0_8013E86C.f0 = 0;
                        M2C_FIELD(o, u8 *, 0x80) = 3;
                        D_801413F0_8013E86C.f4 = 2;
                        D_801413F0_8013E86C.f20 += 2;
                        if (D_800E77A0[1]) {
                            func_8013E57C(o);
                        }
                    } else {
                        D_801413F0_8013E86C.f8 = -(D_801413F0_8013E86C.f8 / 4);
                    }
                }
            } else {
                func_8013DF08();
                D_801413F0_8013E86C.f0 = 0;
                M2C_FIELD(o, u8 *, 0x80) = 3;
            }
        }
        break;
    }
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

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

int abs(int);
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013EE70 asm("g_Spike");
s32 Vec_Length(s32, s32, s32);
void Object_OrbitAround(void *, s16, s16, s16, s16);
void Object_PlaySound_8013EE70(void *, s32) asm("Object_PlaySound");

void func_8013EE70(void *arg0) {
    u8 *o = arg0;
    s32 d;
    s32 r;
    s16 speed;

    d = Vec_Length(g_Spike_8013EE70.x - M2C_FIELD(o, s16 *, 0x9A), 0, g_Spike_8013EE70.z - M2C_FIELD(o, s16 *, 0x9E));
    r = M2C_FIELD(o, s16 *, 0xA6);
    if (r + 0x600 < d) {
        speed = 8;
    } else if (d < r) {
        speed = 0x20;
    } else {
        speed = (0x600 - d) / 64 + 8;
    }
    Object_OrbitAround(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), M2C_FIELD(o, s16 *, 0xA6), speed);
    if (abs(M2C_FIELD(o, s16 *, 0xAA) - M2C_FIELD(o, s16 *, 0xD4)) > 0x800) Object_PlaySound_8013EE70(o, 0x2B);
    M2C_FIELD(o, s16 *, 0xD4) = M2C_FIELD(o, s16 *, 0xAA);
}

void func_8013EBBC(void *arg0, s16 x, s16 y, s16 z);
s32 func_8013EC28(void *arg0, s32 arg1, s32 arg2);

void func_8013EF54(void *arg0) {
    u16 t;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        func_8013ED0C(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        func_8013EBBC(arg0, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), M2C_FIELD(arg0, s16 *, 0x20));
    }
    if (M2C_FIELD(arg0, u8 *, 0x82) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x96) > 0) {
            func_8013ED7C(arg0);
        }
    } else {
        switch (M2C_FIELD(arg0, u8 *, 0x80)) {
        case 1:
            func_8013EE70(arg0);
            break;
        case 2:
            t = *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4 + 2);
            if (M2C_FIELD(arg0, u16 *, 0x5C) == t) {
                M2C_FIELD(arg0, u8 *, 0x8F)++;
                M2C_FIELD(arg0, u16 *, 0x5C) = t - 1;
                if (func_8013EC28(arg0, 8, M2C_FIELD(arg0, u8 *, 0x8F))) {
                    func_80051E98(arg0, 1);
                    Object_DropPickups(arg0);
                }
            }
            break;
        }
    }
}

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

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F408 asm("g_Spike");
void func_80055E6C(void *, s16);
void func_80055F1C(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
s16 Object_FloorAt(void *, s16, s16, s16);
void func_80054220(void *);
void func_8013F12C(void *arg0);
void func_8013F17C(void *arg0);
void func_8013F19C(void *arg0);
void func_8013F260(u8 *a);
s32 func_8013F384(void *arg0);

void func_8013F408(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 0x3C;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 0x64;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0xDC) = 1;
        M2C_FIELD(o, s16 *, 0x9C) -= 200;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        func_80055F1C(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    if (func_8013F384(o)) {
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_80055E6C(o, 8);
        Object_SeekHeight(o, 8);
        func_8013F17C(o);
        if (!func_8005588C(o, -1) && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
            func_8013F12C(o);
        }
        break;
    case 2:
        Object_TurnToward(o, g_Spike_8013F408.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013F408.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1] - 10) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, s16 *, 0xA8) = 0;
            M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
            M2C_FIELD(o, u16 *, 0xBC) = g_Spike_8013F408.x;
            M2C_FIELD(o, u16 *, 0xC0) = g_Spike_8013F408.z;
            M2C_FIELD(o, u16 *, 0xBE) = g_Spike_8013F408.y - 200;
            M2C_FIELD(o, u8 *, 0x8F) = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3 && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            Object_PlaySound_8013F260(o, 0xA6);
        }
        func_8013F260(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            func_8013F0A0(o);
        } else if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1] && M2C_FIELD(o, u8 *, 0x7F) == 2) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[8];
        }
        break;
    case 4:
        func_8013F19C(o);
        break;
    }
    func_80054220(o);
}

typedef struct { s16 x, y, z, sx, sy, sz; s16 pad0C; s16 mdl; u8 pad10[8]; u16 flags; u8 pad1A[2]; s16 f1C; u8 pad1E[0x16]; s16 f34; s16 f36; } Ent_8013F6FC;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013F6FC asm("g_Game");
s32 Model_SetTurnAngle(s16, s16, s32);

s32 func_8013F6FC(s16 *p) {
    Ent_8013F6FC *e = (Ent_8013F6FC *)(g_Game_8013F6FC.f_820C + p[2] * 0x38);
    s16 t;

    switch (p[1]) {
    case 0:
        if (e->f34 != 0 || e->f36 != 0) {
            p[1] = 1;
            p[3] = 0;
            e->flags |= 0x8000;
            e->z -= e->sz / 2;
            p[4] = 7;
        }
        break;
    case 1:
        p[3] += 0x80;
        if (p[3] >= 0x400) {
            p[3] = 0x400;
            p[1] = 2;
            switch (p[4]) {
            case 6:
                t = e->sz;
                e->sz = e->sy / 2;
                e->z += e->sy / 2;
                e->y += t;
                e->sy = t * 2;
                break;
            case 2:
                t = e->sx;
                e->sx = e->sy / 2;
                e->x -= e->sy / 2;
                e->y += t;
                e->sy = t * 2;
                break;
            case 7:
                t = e->sz;
                e->sz = e->sy / 2;
                e->z -= e->sy / 2;
                e->y += t;
                e->sy = t * 2;
                break;
            case 3:
                t = e->sx;
                e->sx = e->sy / 2;
                e->x += e->sy / 2;
                e->y += t;
                e->sy = t * 2;
                break;
            }
            e->f1C = 0x20;
        }
    case 2:
        Model_SetTurnAngle(p[4], e->mdl, p[3]);
        break;
    }
    return 0;
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013FA8C asm("g_Game");
extern u8 *D_800B4D64_8013FA8C asm("D_800B4D64");
int abs(int);
void Camera_StartShake(s32);
void Pad_Vibrate(s32, s32, s32);
void Fx_Explosion(s16 *, s32, s32);

s32 func_8013FA8C(s16 *p) {
    s16 *e;
    s16 *e2;

    if (p[5] >= 0) {
        e = (s16 *)(g_Game_8013FA8C.f_820C + p[2] * 0x38);
        e2 = (s16 *)(g_Game_8013FA8C.f_820C + p[5] * 0x38);
        if (p[1] == 0) {
                        if (abs(e2[0] - e[0]) >= e[3]) {
                return 0;
            }
                        if (abs(e2[2] - e[2]) >= e[5]) {
                return 0;
            }
                        if (abs(e2[1] - e[1]) < e[4] + 0x80) {
                p[1] = 1;
                Camera_StartShake(0);
                Pad_Vibrate(0, 1, 3);
                M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64_8013FA8C + e[7] * 32, s16 *, 0x16) = 0;
                }
                Fx_Explosion(e, e[7], 1);
                M2C_FIELD(e2, u16 *, 0x18) |= 0x8000;
                if (e2[7] >= 0) {
                    M2C_FIELD(D_800B4D64_8013FA8C + e2[7] * 32, s16 *, 0x16) = 0;
                }
                Fx_Explosion(e2, e2[7], 1);
            }
        }
    }
    return 0;
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FC64 asm("g_Game");
extern u32 D_80141240[];
s32 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);
void Sound_UpdateVoice3D(s32, s32, s32, void *);
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
void *RotMatrixZYX(void *r, void *m);

s32 func_8013FC64(s16 *p) {
    s16 *e;
    s32 a;
    s32 b;
    s32 spd;
    SVECTOR r;
    SVECTOR v;

    e = (s16 *)(g_Game_8013FC64.f_820C + p[2] * 0x38);
    if (p[4] >= 0) {
        a = M2C_FIELD(g_Game_8013FC64.f_8220 + p[4] * 0x18, s16 *, 2);
    }
    if (p[5] >= 0) {
        b = M2C_FIELD(g_Game_8013FC64.f_8220 + p[5] * 0x18, s16 *, 2);
    }
    if (a == 1 || b == 1) {
        if (p[1] == 2) {
            p[3] = 0;
        } else {
            p[1] = 1;
            if (D_801413E8 < 0) {
                D_801413E8 = Sound_Play(1, 0xAD);
            }
        }
    }
    v.vz = 0x1400;
    v.vx = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 3 - 0x300;
    v.vy = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 3 - 0xC00;
    switch (p[1]) {
    case 0:
        spd = 0;
        break;
    case 1:
        if (++p[3] > p[8]) {
            spd = p[7];
            p[3] = 0;
            p[1] = 2;
        } else {
            spd = p[7] * p[3] / p[8];
            Sound_UpdateVoice3D(0xAD, D_801413E8, 0x1000, D_800B4D64_8013FA8C + p[6] * 32 + 0x10);
            Effect_Spawn(0xC9, &v.vx, D_80141240, 0);
        }
        break;
    case 2:
        spd = p[7];
        if (++p[3] > p[9]) {
            p[1] = 3;
            p[3] = p[8];
        }
        Effect_Spawn(0xC8, &v.vx, D_80141240, 0);
        break;
    case 3:
        if (--p[3] < 0) {
            spd = 0;
            p[3] = 0;
            p[1] = 0;
            Sound_Stop(0xAD, D_801413E8);
            D_801413E8 = -1;
        } else {
            spd = p[7] * p[3] / p[8];
            Sound_UpdateVoice3D(0xAD, D_801413E8, 0x1000, D_800B4D64_8013FA8C + p[6] * 32 + 0x10);
            Effect_Spawn(0xC8, &v.vx, D_80141240, 0);
        }
        break;
    }
    p[10] += spd;
    if (p[10] > 360) {
        p[10] -= 360;
    }
    r.vy = 0;
    r.vx = 0;
    r.vz = (p[10] << 12) / 360;
    if ((**(u32 **)(D_800B4D64_8013FA8C + p[6] * 32) & 0xF) == 3) {
        RotMatrixZYX(&r, M2C_FIELD(D_800B4D64_8013FA8C + p[6] * 32, void **, 0x1C));
    }
    e[14] = spd * p[11] / p[7];
    return 0;
}

s32 func_80140098(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801400E4 asm("g_Spike");
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801400E4 asm("g_Game");
extern s16 D_800EC238;
s32 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);

s32 func_801400E4(s16 *p) {
    s16 *e = (s16 *)(g_Game_801400E4.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (g_Spike_801400E4.y >= -0xBFF && g_Spike_801400E4.z >= -0x1FFF) {
            p[1] = 2;
            while (e[0x19] < p[6] * 2 + 1) {
                func_80140368(e);
            }
            break;
        }
        if (D_800EC238 == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[3] = 1;
            p[1] = 1;
            Sound_PlayAt(0x80, e);
            p[0xB] = Sound_Play(0, 0x7C);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 1:
        if (e[0x19] >= p[6] * 2 + 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 2;
            Sound_PlayAt(0x80, e);
            Sound_Stop(0x7C, p[0xB]);
            p[3] = D_800EC238 == p[2];
        }
        break;
    case 2:
        if (D_800EC238 == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[1] = 3;
            p[3] = 1;
            Sound_PlayAt(0x80, e);
            p[0xB] = Sound_Play(0, 0x7C);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 3:
        if (e[0x19] == 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 0;
            Sound_PlayAt(0x80, e);
            Sound_Stop(0x7C, p[0xB]);
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}

typedef struct { s16 x, y, z; u8 pad6[6]; s16 n; s16 next; } Node_80140368;
extern struct { u8 pad_0[0x8214]; Node_80140368 *f_8214; } g_Game_80140368 asm("g_Game");
extern u8 *D_800B4D64_80140368 asm("D_800B4D64");
s16 func_800889EC(s16 *);

s32 func_80140368(s16 *e) {
    Node_80140368 *n;
    s32 x, y, z;

    if (e[0x11] < 0) {
        return 0;
    }
    n = &g_Game_80140368.f_8214[e[0x11]];
    x = ((u16 *)e)[0x12] + e[6] * (n->x - e[0x12]) / (n->n * 2);
    y = ((u16 *)e)[0x13] + e[6] * (n->y - e[0x13]) / (n->n * 2);
    z = ((u16 *)e)[0x14] + e[6] * (n->z - e[0x14]) / (n->n * 2);
    if (e[7] >= 0) {
        M2C_FIELD(D_800B4D64_80140368 + e[7] * 32, s16 *, 0x10) = x;
        M2C_FIELD(D_800B4D64_80140368 + e[7] * 32, s16 *, 0x12) = y;
        M2C_FIELD(D_800B4D64_80140368 + e[7] * 32, s16 *, 0x14) = z;
    }
    e[2] = z;
    e[0] = x;
    e[1] = y;
    e[0x10] = func_800889EC(e);
    e[6]++;
    e[0x19]++;
    if (e[6] >= n->n * 2) {
        e[6] = 0;
        e[0x11] = n->next;
        if (g_Game_80140368.f_8214[e[0x11]].n <= 0) {
            e[0x12] = g_Game_80140368.f_8214[e[0x11]].x;
            e[0x13] = g_Game_80140368.f_8214[e[0x11]].y;
            e[0x14] = g_Game_80140368.f_8214[e[0x11]].z;
            e[0x11] = g_Game_80140368.f_8214[e[0x11]].next;
            e[0x19] = 0;
        } else {
            e[0x12] = n->x;
            e[0x13] = n->y;
            e[0x14] = n->z;
        }
    }
    return 0;
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140768 asm("g_Game");
s32 Model_SetTurnAngle(s16, s16, s32);

s32 func_80140768(s16 *p) {
    u8 *e = g_Game_80140768.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        p[11] -= p[10];
        if (p[11] < 0) {
            p[11] = 0;
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        p[3]++;
        if (p[9] < p[3]) {
            p[1] = 2;
            Sound_PlayAt(0xAF, e);
        }
        break;
    case 2:
        p[11] += p[7];
        if (p[5] < p[11]) {
            p[11] = p[5];
            p[1] = 0;
        }
        break;
    }
    M2C_FIELD(e, s16 *, 0x10) = func_80092324(p, (u16 *)e);
    if (p[5] / 2 < p[11]) {
        M2C_FIELD(e, s16 *, 0x14) = 14;
    } else {
        M2C_FIELD(e, s16 *, 0x14) = 6;
    }
    if (p[4] == 1) {
        Model_SetTurnAngle(3, p[6], p[11]);
    } else {
        Model_SetTurnAngle(2, p[6], p[11]);
    }
    return 0;
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801409D8 asm("g_Game");

s32 func_801409D8(s16 *p) {
    u8 *e = g_Game_801409D8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        break;
    case 1:
        if (p[11] == p[7]) {
            Sound_PlayAt(0xAF, e);
        }
        p[11] += p[7];
        if (p[5] < p[11]) {
            p[11] = p[5];
            p[1] = 3;
        }
        break;
    case 3:
        p[11] -= p[10];
        if (p[11] < 0) {
            p[11] = 0;
            p[1] = 0;
            p[3] = 0;
        }
        break;
    }
    M2C_FIELD(e, s16 *, 0x10) = func_80092324(p, (u16 *)e);
    if (p[5] / 2 < p[11]) {
        M2C_FIELD(e, s16 *, 0x14) = 14;
    } else {
        M2C_FIELD(e, s16 *, 0x14) = 6;
    }
    if (p[4] == 1) {
        Model_SetTurnAngle(3, p[6], p[11]);
    } else {
        Model_SetTurnAngle(2, p[6], p[11]);
    }
    return 0;
}

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

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80140D4C asm("g_Spike");
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140D4C asm("g_Game");
extern u8 D_800B1D24[];
void Effect_SpawnAt(s32, void *);
void Ripple_Spawn(void *);
M2C_UNK Sound_PlayFixed(M2C_UNK);
s32 SquareRoot0(s32);

s32 func_80140D4C(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140D4C.f_820C + p[2] * 0x38);
    s32 r;
    s32 dx, dy, dz;

    switch (p[1]) {
    case 0:
        r = func_80141034(e);
        if (D_800EC238 == p[2] || r != 0) {
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] > p[4]) {
            p[1] = 2;
            p[3] = 0;
            p[0xA] = 0;
            if (p[8] != 0) {
                Effect_SpawnAt(0x100, e);
                Ripple_Spawn(e);
                func_80070284((SVECTOR *)e, D_800B1D24, 1, 0, 0);
                Sound_PlayFixed(0x72);
            }
        }
        break;
    case 2:
        p[3] += p[5];
        p[0xA] += p[3];
        if (p[0xA] > p[6]) {
            p[1] = 3;
            p[3] = 0;
            if (p[8] == 0) {
                e[0xC] |= 0x8000;
                e[1] = e[0x13];
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
                    M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x16) = 0;
                }
            } else {
                e[1] = e[0x13] + p[6];
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
                }
            }
        } else {
            e[1] = e[0x13] + p[0xA];
            if (e[7] >= 0) {
                M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
            }
        }
        break;
    case 3:
        dx = g_Spike_80140D4C.x - e[0];
        dy = g_Spike_80140D4C.y - e[1];
        dz = g_Spike_80140D4C.z - e[2];
        if (SquareRoot0(dx * dx + dy * dy + dz * dz) > p[7]) {
            p[1] = 0;
            p[3] = 0;
            if (p[8] == 0) {
                e[0xC] &= 0x7FFF;
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64 + e[7] * 32, u16 *, 0x16) = 0xFFFF;
                }
            } else {
                e[1] = e[0x13];
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
                }
            }
        }
        break;
    }
    return 0;
}

typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_80141034;
extern Monkey_80141034 g_Monkeys_80141034[] asm("g_Monkeys");

s32 func_80141034(s16 *b) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (g_Monkeys_80141034[i].f_7A == 4 && abs(g_Monkeys_80141034[i].z - b[2]) < b[5] && abs(g_Monkeys_80141034[i].x - b[0]) < b[3]
            && g_Monkeys_80141034[i].y >= b[1] - b[4] - 16 && g_Monkeys_80141034[i].y < b[1]) {
            return 1;
        }
    }
    return 0;
}

s32 func_801410F4(void *arg0) {
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(temp_a1, s16 *, 0x32) == M2C_FIELD(arg0, s16 *, 8)) {
        Sound_PlayAt(0xAE, temp_a1);
    }
    return 0;
}
