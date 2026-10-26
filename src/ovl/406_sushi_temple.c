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

void * func_80056BC4(s16, s32, s16);
void func_8005866C(void *, s32);
M2C_UNK func_80058134(void *, s16);
void func_8013D000(void *arg0);

void func_8013D04C(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0x44) = 0x118;
        M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, s16 *, 0x46) = -0x12C;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
        func_80056BC4(0x3B, 0, M2C_FIELD(o, s8 *, 0xCB));
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
            func_8005866C(o, 1);
        }
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013D000(o);
        break;
    case 2:
        M2C_FIELD(o, s16 *, 0x5E) = 1;
        if (M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2] + 0x14 < M2C_FIELD(o, u16 *, 0x5C)) {
            func_8013D000(o);
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    }
}

typedef struct { u8 pad[0xE4]; } Obj_8013D1BC;
extern Obj_8013D1BC g_Objects_8013D1BC[] asm("g_Objects");

void func_8013D1BC(u8 *o) {
    u8 *t = (u8 *)&g_Objects_8013D1BC[M2C_FIELD(o, s8 *, 0xCA)];

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x44;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x42000;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        M2C_FIELD(o, u8 *, 0x7F) = 3;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        if (M2C_FIELD(o, u32 *, 0xE0) & 1) {
            M2C_FIELD(o, u8 *, 0xC8) = 0;
        } else {
            M2C_FIELD(o, u8 *, 0xC8) = 10;
        }
        M2C_FIELD(o, u8 *, 0xCF) = 0;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~1) | ((M2C_FIELD(o, u32 *, 0xE0) & 1) ^ 1);
    }
    if (M2C_FIELD(t, u8 *, 0x80) == 2) {
        M2C_FIELD(o, u8 *, 0xC8) = 0;
    }
}

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

extern u16 g_RandSeed;
extern s32 D_8013F7F4[];
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
void Object_DisableCollision(void *);
void Object_EnableCollision(void *);
void Object_PlaceAtPathPoint(void *, s32);
s32 func_800585D0(void *, s32, s32, s32);
void Object_StepOnGroundFixed(void *);
void Object_StepOnGround(void *, s32);
void Object_SetForwardVelocity(void *, s16);
s32 Object_WouldLeaveHome(void *, s32);
void Object_SpawnEffect(void *, s32, s32, s32, s32);
s32 Object_DetachLink(void *, s32);
s32 rcos_8013D9C4(s32) asm("rcos");
s32 rsin_8013D9C4(s32) asm("rsin");
void func_8013D2B0(void *arg0);

void func_8013D368(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 0x78;
        M2C_FIELD(o, s16 *, 0x46) = 0x118;
        M2C_FIELD(o, u8 *, 0xCD) = 2;
        M2C_FIELD(o, u8 *, 0x81) = 0xC;
        M2C_FIELD(o, u8 *, 0xDC) = 0xA;
        M2C_FIELD(o, s16 *, 0xA8) = 0;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision(o);
        Object_PlaceAtPathPoint(o, 0);
        func_8005866C(o, 1);
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        M2C_FIELD(o, u8 *, 0x8E) = 1;
        M2C_FIELD(o, u8 *, 0x8F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (Spike_WithinRadiusXZ(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), M2C_FIELD(o, s16 *, 0xA4))) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0xC8) = 6;
            M2C_FIELD(o, u8 *, 0x8F) = 0;
            Object_EnableCollision(o);
        }
        break;
    case 2:
        if (func_800585D0(o, 0x28, 0, 0)) {
            M2C_FIELD(o, s16 *, 0xAE) = 0;
            func_8013D2B0(o);
            M2C_FIELD(o, u8 *, 0x80) = 3;
        } else {
            Object_StepOnGroundFixed(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88))) {
            Object_PlaySound(o, D_8013F7F4[((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1]);
        }
        Object_SetForwardVelocity(o, 0x28);
        Object_StepOnGroundFixed(o);
        if (!func_8005588C(o, -1) && Object_WouldLeaveHome(o, -0x1F4)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            Object_PlaySound(o, 0x98);
            M2C_FIELD(o, s16 *, 0xA8) = 0x140;
        }
        break;
    case 4:
        if (M2C_FIELD(o, s16 *, 0xA8) != 0) {
            M2C_FIELD(o, s16 *, 0xA8) -= 10;
            if (M2C_FIELD(o, s16 *, 0xA8) < 0) {
                M2C_FIELD(o, s16 *, 0xA8) = 0;
            }
            Object_SetForwardVelocity(o, M2C_FIELD(o, s16 *, 0xA8) >> 3);
            Object_StepOnGround(o, 0x64);
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
            func_8013D2B0(o);
            M2C_FIELD(o, s16 *, 0x60) = rcos_8013D9C4(M2C_FIELD(o, s16 *, 0xAC));
            M2C_FIELD(o, s16 *, 0x64) = rsin_8013D9C4(M2C_FIELD(o, s16 *, 0xAC));
            func_8005588C(o, 0x1E);
        }
        break;
    }
    if (M2C_FIELD(o, u8 *, 0x80) != 1) {
        Object_SpawnEffect(o, 5, -((M2C_FIELD(o, s16 *, 0x60) * 25) >> 9), 0, -((M2C_FIELD(o, s16 *, 0x64) * 25) >> 9));
        if (Object_DetachLink(o, 0) == 6) {
            Object_DisableCollision(o);
            M2C_FIELD(o, u8 *, 0x8F) = 0x3C;
        }
        if (M2C_FIELD(o, u8 *, 0x8F)) {
            if (--M2C_FIELD(o, u8 *, 0x8F) == 0) {
                Object_EnableCollision(o);
            }
        } else if (!((M2C_FIELD(o, u32 *, 0xE0) >> 2) & 1)) {
            M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphereNear(o, M2C_FIELD(o, u16 *, 0x44) + 0x32, M2C_FIELD(o, s16 *, 0x1C), M2C_FIELD(o, s16 *, 0x1E), M2C_FIELD(o, s16 *, 0x20), M2C_FIELD(o, s16 *, 0x48), M2C_FIELD(o, s16 *, 0x4A));
        }
    }
}

typedef struct { u8 pad[0xE4]; } Obj_8013D77C;
typedef struct { u8 pad0[0x10]; s8 a; s8 b; s8 c; u8 pad13; } Slot_8013D77C;
extern Obj_8013D77C g_Objects_8013D77C[] asm("g_Objects");
extern Slot_8013D77C *D_8013F8B4_8013D77C asm("D_8013F8B4");
extern s32 D_8013F8B0;
extern s16 D_800E77E0;
extern u8 D_8013F8B8_8013D77C[] asm("D_8013F8B8");
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
void func_8013DAFC(void);
void Hook_Add(void *);

void func_8013D77C(void) {
    s32 i;
    u8 *m;

    D_8013F8B4_8013D77C = (Slot_8013D77C *)&g_Objects_8013D77C[D_800E77E0];
    D_8013F8B0 = (16 - D_800E77E0) * sizeof(Obj_8013D77C) / sizeof(Slot_8013D77C);
    if (D_8013F8B0 > 32) {
        D_8013F8B0 = 32;
    }
    for (i = D_8013F8B0 - 1; i >= 0; i--) {
        D_8013F8B4_8013D77C[i].a = 0;
        D_8013F8B4_8013D77C[i].b = 0;
        D_8013F8B4_8013D77C[i].c = -1;
    }
    m = D_8013F8B8_8013D77C;
    func_80052038(m, 0x6D);
    func_800520A8(m, 0x6D);
    M2C_FIELD(m, s16 *, 0x5C) = 0;
    M2C_FIELD(m, s16 *, 0x66) = 3;
    M2C_FIELD(m, s16 *, 0x62) = 0;
    Hook_Add(func_8013DAFC);
}

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

typedef struct { u8 b[8]; } B8_8013D8F8;
typedef struct { B8_8013D8F8 a; B8_8013D8F8 b; s8 f; u8 pad11; s8 g; u8 pad13; } Slot_8013D8F8;
extern Slot_8013D8F8 *D_8013F8B4_8013D8F8 asm("D_8013F8B4");
s32 func_8013D8A4(void);

s32 func_8013D8F8(s32 g, B8_8013D8F8 *a, B8_8013D8F8 *b) {
    s32 i = func_8013D8A4();

    if (i == -1) {
        return -1;
    }
    D_8013F8B4_8013D8F8[i].f = 20;
    D_8013F8B4_8013D8F8[i].a = *a;
    D_8013F8B4_8013D8F8[i].b = *b;
    D_8013F8B4_8013D8F8[i].g = g;
    return i;
}

typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x; s32 y; s32 z; u8 pad30[0x30]; s16 rx; s16 ry; s16 rz; } Mdl_8013D9C4;
typedef struct { s16 x, y, z; } Pos_8013D9C4;
extern Mdl_8013D9C4 D_8013F8B8;
extern u8 D_800E7D00[];
s32 func_80051410(void *, s32, s32);
s32 rcos_8013D9C4(s32) asm("rcos");
s32 rsin_8013D9C4(s32) asm("rsin");
void func_80014804_8013D9C4(void *, void *) asm("func_80014804");
void func_80015780_8013D9C4(void *, s32) asm("func_80015780");
void Model_ProjectBonedVerts_8013D9C4(void *) asm("Model_ProjectBonedVerts");
void func_80016EBC_8013D9C4(void *, void *, void *) asm("func_80016EBC");
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

void func_8013D9C4(void *o, Pos_8013D9C4 *s, s16 f) {
    Mdl_8013D9C4 *m = &D_8013F8B8;
    s32 a;

    m->x = s->x;
    m->y = s->y;
    m->z = s->z;
    if (func_80051410(&m->x, 0, 0) == 0) {
        a = (s16)(f % 8) << 9;
        m->rx = rcos_8013D9C4(a);
        m->rz = rsin_8013D9C4(a);
        func_80014804_8013D9C4(&m->rx, m->mat);
        func_80015780_8013D9C4(m, 3);
        Model_ProjectBonedVerts_8013D9C4(m);
        func_80016EBC_8013D9C4(G_DRAW.db[G_DRAW.cur].ot, D_800E7D00, m);
        Object_AddAttackSphereNear(o, 0x32, s->x, s->y, s->z, 1, 0x202);
    }
}

typedef struct { s16 x, y, z, pad6; s16 vx, vy, vz, padE; s8 f; s8 g; s8 h; s8 k; } Slot_8013DAFC;
typedef struct { u8 pad[0xE4]; } Obj_8013DAFC;
extern Obj_8013DAFC g_Objects_8013DAFC[] asm("g_Objects");
extern Slot_8013DAFC *D_8013F8B4_8013DAFC asm("D_8013F8B4");

void func_8013DAFC(void) {
    s32 i;
    Slot_8013DAFC *s;

    for (i = 0; i < D_8013F8B0; i++) {
        s = &D_8013F8B4_8013DAFC[i];
        if (s->f != 0) {
            if (--s->f != 0) {
                s->x += s->vx;
                s->y += s->vy;
                s->z += s->vz;
                func_8013D9C4(&g_Objects_8013DAFC[s->h], s, s->f);
            }
        }
    }
}

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);

s32 func_8013DBF4(void *arg0) {
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28),
                               M2C_FIELD(arg0, s32 *, 0x2C), 0x300) == 0 ||
        Object_SpikeInFront(arg0, 0x5A, 0xB50, 0x600) != 0) {
        M2C_FIELD(arg0, u8 *, 0x80) = 3;
        M2C_FIELD(arg0, u8 *, 0x7F) = 4;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x10);
        return 1;
    }
    return 0;
}

void Effect_SpawnAt(s32, SVECTOR *);
extern u16 g_RandSeed;

M2C_UNK func_8013DC70(s16 x, s16 y, s16 z) {
    SVECTOR v;
    s32 i;

    v.vx = x;
    v.vy = y;
    v.vz = z;
    Effect_SpawnAt(6, &v);
    for (i = 3; i > 0; i--) {
        v.vx = x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2;
        v.vy = y + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2;
        v.vz = z + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2;
        Effect_SpawnAt(6, &v);
    }
}

extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013DD94 asm("g_Spike");
s16 Object_FloorAt(void *, s16, s16, s16);

void func_8013DD94(u8 *o) {
    SVECTOR v;

    v.vx = M2C_FIELD(o, s16 *, 0x9A) - g_Spike_8013DD94.x;
    v.vy = 0;
    v.vz = M2C_FIELD(o, s16 *, 0x9E) - g_Spike_8013DD94.z;
    VectorNormalSS(&v, &v);
    M2C_FIELD(o, s32 *, 0x24) = g_Spike_8013DD94.x + ((v.vx << 14) >> 16);
    M2C_FIELD(o, s32 *, 0x2C) = g_Spike_8013DD94.z + ((v.vz << 14) >> 16);
    M2C_FIELD(o, s32 *, 0x28) = Object_FloorAt(o, 0, 0, 0) - 0x400;
    M2C_FIELD(o, s16 *, 0x98) = 0;
    M2C_FIELD(o, s16 *, 0x96) = 0;
    M2C_FIELD(o, s16 *, 0x94) = 0;
}

void func_8013DE4C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 7;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x1C);
    }
}

extern s32 D_800EC208;

void func_8013DE84(u8 *o) {
    SVECTOR a;
    SVECTOR b;

    if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
        a.vx = M2C_FIELD(o, s32 *, 0x24);
        a.vy = M2C_FIELD(o, s32 *, 0x28) - 0x82;
        a.vz = M2C_FIELD(o, s32 *, 0x2C);
        b.vx = (M2C_FIELD(o, s16 *, 0x60) * 5) >> 8;
        b.vy = (D_800EC208 - M2C_FIELD(o, s32 *, 0x28)) / 20;
        b.vz = (M2C_FIELD(o, s16 *, 0x64) * 5) >> 8;
        func_8013D8F8(M2C_FIELD(o, s8 *, 0xCB), &a, &b);
        M2C_FIELD(o, u8 *, 0x8F)++;
        Object_PlaySound(o, 0xB2);
    }
}

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_80052134(void *, M2C_UNK);
M2C_UNK func_8005588C(void *, M2C_UNK);

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

void func_8013E004(void *arg0) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == 2 || d == 8) {
        Object_PlaySound(arg0, 0xB4);
    }
}

s32 func_8013E058(u8 *o) {
    u8 *sh;

    if (M2C_FIELD(o, u8 *, 0x81) == 0 || M2C_FIELD(o, u8 *, 0x80) == 1 || M2C_FIELD(o, u8 *, 0x80) == 11) {
        return 0;
    }
    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) == 11) {
        sh = (u8 *)Collision_GetShape(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
        Object_DisableCollision(o);
        if (func_800525A0(o, sh)) {
            func_8005240C(o, sh);
            func_80052864(o);
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 8);
            M2C_FIELD(o, s32 *, 0x50) = 0;
            return 1;
        } else {
            func_8013DF60(o);
            M2C_FIELD(o, s32 *, 0x50) = 0;
            return 0;
        }
    }
}

typedef struct { u16 start; u16 end; } Anim_8013E134;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x14]; s16 f_44; s16 f_46; u8 pad48[0x14]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 f_81; u8 f_82; u8 pad83[0x5]; Anim_8013E134 *f_88; u8 pad8C[0x3]; u8 f_8F; u8 pad90[0x4]; s16 f_94; s16 f_96; s16 f_98; s16 f_9A; u8 pad9C[0x2]; s16 f_9E; s16 f_A0; u8 padA2[0x2]; s16 f_A4; s16 f_A6; u8 padA8[0x6]; s16 f_AE; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 f_C9; u8 padCA[0x3]; u8 f_CD; u8 padCE[0x6]; s16 f_D4; u8 padD6[0x6]; u8 f_DC; u8 padDD[0x3]; u32 f_E0; } O_8013E134;
void Object_ApplyVelocity(void *);
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
void Object_TurnTowardSpike_8013E134(void *) asm("Object_TurnTowardSpike");
void Object_ClampAnimFrame_8013E134(void *, s32) asm("Object_ClampAnimFrame");
s32 func_80055C7C_8013E134(void *, s32) asm("func_80055C7C");
void func_8013D77C(void);
s32 func_8013DBF4(void *arg0);
M2C_UNK func_8013DC70(s16 x, s16 y, s16 z);
void func_8013DD94(u8 *o);
void func_8013DE4C(void *arg0);
void func_8013DE84(u8 *o);
void func_8013E004(void *arg0);
s32 func_8013E058(u8 *o);

void func_8013E134(O_8013E134 *o) {
    s16 fl;
    s32 n;

    if (!((o->f_E0 >> 3) & 1)) {
        o->f_A0 = 0x46;
        o->f_B0 = 0xB6;
        o->f_CD = 2;
        o->f_46 = 0x104;
        o->f_44 = 0x5A;
        o->f_81 = 12;
        o->f_DC = 10;
        o->f_C8 = 0;
        {
            u32 t = o->f_E0 | 0x200000;
            *(volatile u32 *)&o->f_E0 = t;
            o->f_E0 = t & ~0x1000;
        }
        Object_DisableCollision(o);
        func_8013D77C();
        o->f_7F = 9;
        o->f_5C = o->f_88[9].start;
        o->f_E0 |= 8;
    }
    func_80058134(o, o->f_44);
    if (o->f_82 != 0) {
        if (o->f_81 == 0 && o->f_7F == 2 && o->f_5C == o->f_88[o->f_7F].start + 5) {
            o->f_7F = 3;
            o->f_5C = o->f_88[3].start;
            o->f_E0 &= ~0x200000;
        }
        return;
    }
    if (func_8013E058((u8 *)o) != 0) {
        return;
    }
    switch (o->f_80) {
    case 1:
        o->f_C8 = 0;
        if (func_8005588C(o, -1) == 0 && Spike_WithinRadiusXZ(o->f_9A, o->f_9E, o->f_A4)) {
            o->f_80 = 2;
            o->f_7F = 1;
            o->f_5C = o->f_88[1].start + 15;
            func_8013DD94((u8 *)o);
            func_8013DC70(M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C));
            Object_EnableCollision(o);
            o->f_C8 = 5;
        }
        break;
    case 2:
        Object_TurnTowardSpike_8013E134(o);
        Object_ClampAnimFrame_8013E134(o, o->f_88[o->f_7F].end);
        fl = Object_FloorAt(o, 0, 0, 0);
        o->f_96 += 14;
        o->f_28 += o->f_96;
        if (o->f_28 >= fl) {
            o->f_28 = fl;
            Object_PlaySound(o, 0xB4);
            if (func_8013DBF4(o) == 0) {
                o->f_80 = 7;
                func_8005588C(o, 0x1E);
            }
        }
        break;
    case 3:
        if (o->f_7F == 4) {
            if (o->f_5C == o->f_88[o->f_7F].start + 14) {
                Object_PlaySound(o, 0x68);
            }
            if (o->f_5C >= o->f_88[o->f_7F].end - 23) {
                o->f_7F = 5;
                o->f_5C = o->f_88[5].start;
                Object_PlaySound(o, 0xB4);
            }
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            switch (o->f_7F) {
            case 5:
                o->f_80 = 4;
                o->f_7F = 6;
                o->f_5C = o->f_88[6].start;
                func_8005588C(o, 0x3C);
                o->f_8F = 0;
                break;
            case 7:
                o->f_80 = 5;
                o->f_7F = 0;
                o->f_5C = o->f_88[0].start;
                func_8005588C(o, 0x2D);
                break;
            }
        }
        break;
    case 4:
        func_8013DE4C(o);
        if ((u8)(o->f_C9 % 10) == 0 && !((o->f_E0 >> 2) & 1)) {
            func_8013DE84((u8 *)o);
        }
        Object_TurnTowardSpike_8013E134(o);
        if (o->f_8F >= 3) {
            if (o->f_5C < o->f_88[o->f_7F].end) {
                break;
            }
            o->f_80 = 3;
            o->f_7F = 7;
            o->f_5C = o->f_88[7].start;
        }
        func_8005588C(o, -1);
        break;
    case 5:
        if (func_80055C7C_8013E134(o, 0x32)) {
            Object_StepOnGroundFixed(o);
            func_8013E004(o);
        } else {
            o->f_80 = 9;
            o->f_7F = 1;
            o->f_5C = o->f_88[1].start;
            Object_TurnToward(o, o->f_9A - M2C_FIELD(o, u16 *, 0x24), o->f_9E - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
            o->f_96 = o->f_A6 * -7 / 100;
        }
        if (func_8005588C(o, -1) == 0) {
            o->f_80 = 6;
            o->f_7F = 9;
            o->f_5C = o->f_88[9].start;
        }
        break;
    case 9:
        if (o->f_C9 != 0) {
            o->f_C9--;
        }
        if (o->f_5C >= o->f_88[o->f_7F].start + 15) {
            Object_ClampAnimFrame_8013E134(o, o->f_88[o->f_7F].end);
            if (o->f_AE == 0) {
                o->f_96 += 7;
                Object_ApplyVelocity(o);
                fl = Object_FloorAt(o, 0, 0, 0);
                if (o->f_28 >= fl) {
                    o->f_28 = fl;
                    o->f_98 = 0;
                    o->f_96 = 0;
                    o->f_94 = 0;
                    o->f_80 = 5;
                    o->f_7F = 0;
                    o->f_5C = o->f_88[0].start;
                    Object_PlaySound(o, 0xB4);
                }
            }
        }
        break;
    case 6:
        Object_TurnTowardSpike_8013E134(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            n = o->f_7F + 1;
            if (n >= 15) {
                o->f_80 = 8;
                o->f_7F = 4;
                o->f_5C = o->f_88[4].start;
                Object_DisableCollision(o);
            } else {
                o->f_7F = n;
                o->f_5C = o->f_88[o->f_7F].start;
                if (n == 10 || n == 13) {
                    o->f_80 = 7;
                    func_8005588C(o, 0x1E);
                }
            }
        }
        break;
    case 7:
        Object_TurnTowardSpike_8013E134(o);
        if (func_8013DBF4(o) == 0 && func_8005588C(o, -1) == 0 && o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 6;
            o->f_7F++;
            o->f_5C = o->f_88[o->f_7F].start;
        }
        break;
    case 8:
        if (o->f_5C >= o->f_88[o->f_7F].end - 23) {
            func_8013DC70(M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C));
            o->f_80 = 1;
            func_8005588C(o, 0x3C);
        }
        break;
    case 10:
        break;
    case 11:
        {
            s32 g = Object_FloorAt(o, 0, 0, 0);
            o->f_28 += o->f_96;
            o->f_96 += 14;
            if (g - 150 < o->f_28) {
                o->f_28 = g - 150;
            }
            if (o->f_C9 >= 57) {
                func_8013DC70(M2C_FIELD(o, s16 *, 0x24), g - (60 - o->f_C9) * 100, M2C_FIELD(o, s16 *, 0x2C));
            }
        }
        if (o->f_C9 < 20 && !(o->f_C9 & 1)) {
            o->f_C8 = 0;
        } else {
            o->f_C8 = 15;
        }
        if (func_8005588C(o, -1) == 0) {
            o->f_80 = 1;
            func_8005588C(o, 0x3C);
            func_80052038(o, 0x16);
            func_80052134(o, 0x16);
            o->f_D4 = 0;
            o->f_E0 &= 0xFF3FFFFF;
        }
        break;
    }
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

void func_8013E9EC(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void func_8013E9EC(void *arg0, M2C_UNK arg1);
extern u16 D_800AE8F2;
extern u32 D_8013F7E8[];
extern s32 D_8013F6A0[];
extern s32 D_800B1F1C[];
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
void Object_ApplyVelocity(void *);
void Object_PlaceRandomAroundHome(void *, s16);
s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x10]; u16 frame; u8 pad5E[0x21]; u8 anim; u8 pad80[8]; u16 *anims; u8 pad8C[8]; s16 vx, vy, vz; u8 pad9A[2]; s16 floor; u8 pad9E[2]; s16 fA0; u8 padA2[4]; s16 fA6; u8 padA8[8]; s16 fB0; u8 padB2[0x17]; u8 timer; u8 padCA[0x16]; u32 b0:1, b1:1, b2:1, b3:1; } Obj_8013EA38;

void func_8013EA38(Obj_8013EA38 *e) {
    SVECTOR v;
    s32 i;
    s32 fl;

    if (!e->b3) {
        e->fA0 = 0x32;
        e->fB0 = 0x5B;
        e->f48 = 0x201;
        e->f4A = -0x7DFE;
        e->f46 = 1;
        e->f44 = 1;
        Object_PlaceRandomAroundHome(e, 0x64);
        e->vy = -0x78 - (s32)((u32)(((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 5);
        e->anim = 0;
        e->y += 0x64;
        e->frame = e->anims[0];
        e->b3 = 1;
    }
    e->vy += 4;
    Object_ApplyVelocity(e);
    if (!e->b2) {
        v.vx = e->x;
        v.vy = e->y;
        v.vz = e->z;
        Object_AddAttackSphereNear(e, 0x64, e->x, e->y, (s16)e->z, e->f48, e->f4A);
        Effect_Spawn(0xC8, &v.vx, D_8013F7E8, 0);
        Effect_Spawn(0xC8, &v.vx, D_8013F7E8, 0);
        if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7)) {
            Effect_Spawn(0xC9, &v.vx, D_8013F7E8, 0);
        }
    }
    if (e->timer == 0) {
        fl = Object_FloorAt(e, 0, 0, 0);
        if (fl < e->y) {
            v.vx = e->x;
            v.vy = fl;
            v.vz = e->z;
            func_80070284(&v, D_8013F6A0, 1, 0, 0);
            func_80070284(&v, D_800B1F1C, 1, 0, 0);
            for (i = 0; i < 0x10; i++) {
                Effect_Spawn(0xCA, &v.vx, D_8013F7E8, 0);
            }
            Object_PlaceRandomAroundHome(e, e->fA6);
            e->vz = 0;
            e->vx = 0;
            e->y = e->floor;
            e->vy = -0x78 - (s32)((u32)(((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 5);
            func_8005588C(e, 0x1E);
            func_8013E9EC(e, 0x94);
            func_8013E9EC(e, 0x43);
        }
    } else {
        e->timer--;
    }
}

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

M2C_UNK func_80051E98(void *, M2C_UNK);
M2C_UNK func_80058134(void *, s16);
void Object_DropPickups(void *);
void func_8013ED30(void *arg0, s16 x, s16 y, s16 z);
s32 func_8013ED9C(void *arg0, s32 arg1, s32 arg2);

void func_8013F08C(void *arg0) {
    u16 t;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        func_8013EE80(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        func_8013ED30(arg0, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), M2C_FIELD(arg0, s16 *, 0x20));
    }
    if (M2C_FIELD(arg0, u8 *, 0x82) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x96) > 0) {
            func_8013EEF0(arg0);
        }
    } else {
        switch (M2C_FIELD(arg0, u8 *, 0x80)) {
        case 1:
            func_8013EFE4(arg0);
            break;
        case 2:
            t = *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4 + 2);
            if (M2C_FIELD(arg0, u16 *, 0x5C) == t) {
                M2C_FIELD(arg0, u8 *, 0x8F)++;
                M2C_FIELD(arg0, u16 *, 0x5C) = t - 1;
                if (func_8013ED9C(arg0, 8, M2C_FIELD(arg0, u8 *, 0x8F))) {
                    func_80051E98(arg0, 1);
                    Object_DropPickups(arg0);
                }
            }
            break;
        }
    }
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F330 asm("g_Game");
extern u8 *D_800B4D64_8013F330 asm("D_800B4D64");

s32 func_8013F330(s16 *p) {
    u8 *e = g_Game_8013F330.f_820C + p[2] * 0x38;
    u8 *t;
    s16 v;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    t = g_Game_8013F330.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(t, s16 *, 2) == 0) {
        p[1] = 0;
        p[3] = 0;
        M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    } else {
        p[3] = 0;
        p[1] = 2;
        v = M2C_FIELD(e, u16 *, 0) + p[5] * p[7];
        M2C_FIELD(e, s16 *, 0) = v;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013F330 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x10) = v;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F400 asm("g_Game");
extern u8 *D_800B4D64_8013F400 asm("D_800B4D64");
s32 Sound_PlayFixed_8013F400(s32) asm("Sound_PlayFixed");

s32 func_8013F400(s16 *p) {
    u8 *e = g_Game_8013F400.f_820C + p[2] * 0x38;
    u8 *t;
    s16 v;

    switch (p[1]) {
    case 0:
        t = g_Game_8013F400.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 1) {
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        if (p[3] % (p[7] / 4) == 0) {
            Sound_PlayFixed_8013F400(0xAE);
        }
        p[3] += p[6];
        if (p[3] > p[7]) {
            p[1] = 2;
            p[3] = p[7];
        }
        v = M2C_FIELD(e, u16 *, 0x24) + p[5] * p[3];
        M2C_FIELD(e, s16 *, 0) = v;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013F400 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x10) = v;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_8013F574 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F574 asm("g_Game");

s32 func_8013F574(s16 *p) {
    u8 *e;

    if (p[10] == 0) {
        p[1] = 0;
        p[10] = 0;
    } else {
        p[1] = 1;
        e = g_Game_8013F574.f_8220 + p[4] * 0x18;
        M2C_FIELD(e, s16 *, 2) = 5;
    }
    p[3] = 0;
    return 0;
}

extern struct S_g_Game_8013F5D4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F5D4 asm("g_Game");

s32 func_8013F5D4(s16 *p)
{
  u8 *b;
  u8 *c;
  if (p[1] == 0)
  {
    c = g_Game_8013F5D4.f_8220 + (p[5] * 0x18);
    if ((*((s16 *) (((s8 *) c) + 2))) == 1)
    {
      c = g_Game_8013F5D4.f_8220 + (p[6] * 0x18);
      b = c;
      if ((*((s16 *) (((s8 *) b) + 2))) == 1)
      {
        c = g_Game_8013F5D4.f_8220 + (p[4] * 0x18);
        *((s16 *) (((s8 *) c) + 2)) = 5;
        p[1] = 1;
      }
    }
  }
  return 0;
}
