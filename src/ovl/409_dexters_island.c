#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

extern s32 D_80142A60;
s32 rsin(s16, s32);
extern struct S_D_800E77A0 { u8 pad_0[0x8]; u16 f_8; s16 f_A; u16 f_C; } D_800E77A0;
M2C_UNK Collision_Remove(M2C_UNK *);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK GuidedAmmo_RemoveTarget(M2C_UNK *);
M2C_UNK Sound_FreeSlot(s8);
extern M2C_UNK D_80142CD8;
extern struct S_D_80142CA0 { u8 pad_0[0x2C]; u32 f_2C; } D_80142CA0;
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s16 Floor_GetHeight(s32, s32, s32);
M2C_UNK Shadow_Draw(void *, s16, M2C_UNK, s32);
M2C_UNK Object_CameraShake(s32, M2C_UNK);
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
M2C_UNK Object_ApplyHit();
M2C_UNK Object_HitFeedback(void *);
void func_8013E5FC(void *arg0);

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[6]; s32 h; } g_Spike_8013D000 asm("g_Spike");
void Camera_EaseLookAt(void *, s32, s32, s32);
void Camera_EaseEye(void *, s32, s32, s32);

void func_8013D000(void *arg0) {
    u16 x = g_Spike_8013D000.x;
    SVECTOR *s = (SVECTOR *)0x1F800000;
    u16 y = g_Spike_8013D000.y;
    u16 z = g_Spike_8013D000.z;
    s32 h;

    s[2].vx = x;
    s[2].vy = y;
    s[2].vz = z;
    h = g_Spike_8013D000.h;
    s[1].vx = x - 0x100;
    s[1].vy = -(h + 0x60) + y;
    s[1].vz = z;
    s[0].vx = x + 0x100;
    s[0].vz = z;
    s[0].vy = -(h * 4 + 0x60) + y;
    Camera_EaseLookAt(arg0, 3, 3, 3);
    Camera_EaseEye(arg0, 3, 3, 3);
}

void func_8013D0A0(void) {
    D_80142A60 = 0;
}

void func_8013D0AC(void) {
    D_80142A60 = 1;
}

void func_8013D0BC(void) {
    D_80142A60 = 0;
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013D0C8;
extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike_8013D0C8 asm("g_Spike");
typedef struct { u8 pad_0[0x28]; s32 y; u8 pad_2C[0xB4]; u32 f_E0; } Mk_8013D0C8;
extern Mk_8013D0C8 D_800E6DD4_8013D0C8 asm("D_800E6DD4");
void VectorNormalSS_8013D0C8(void *, void *) asm("VectorNormalSS");

void func_8013D0C8(u8 *c) {
    SVECTOR v;
    Mk_8013D0C8 *d;

    ((Scr_8013D0C8 *)0x1F800000)->spike.vx = g_Spike_8013D0C8.f_24;
    ((Scr_8013D0C8 *)0x1F800000)->spike.vy = g_Spike_8013D0C8.f_28;
    ((Scr_8013D0C8 *)0x1F800000)->spike.vz = g_Spike_8013D0C8.f_2C;
    v.vx = ((Scr_8013D0C8 *)0x1F800000)->spike.vx - 0x4C4;
    v.vy = ((Scr_8013D0C8 *)0x1F800000)->spike.vy + 0x10D6;
    v.vz = ((Scr_8013D0C8 *)0x1F800000)->spike.vz - 0xA4F;
    d = &D_800E6DD4_8013D0C8;
    VectorNormalSS_8013D0C8(&v, &v);
    M2C_FIELD(c, s16 *, 0x14) = (M2C_FIELD(c, s16 *, 0x14) * 7 + (M2C_FIELD(c, s16 *, 0xC) + (v.vy + 0xA3E) / 2)) / 8;
    if (((d->f_E0 >> 4) & 1) && D_80142A60 != 0) {
        M2C_FIELD(c, s16 *, 0xC) = (M2C_FIELD(c, s16 *, 0xC) * 3 + (d->y - 800)) / 4;
        if (M2C_FIELD(c, s16 *, 0xC) < -0x1156) {
            M2C_FIELD(c, s16 *, 0xC) = -0x1156;
        }
        if (d->y - 0x80 < M2C_FIELD(c, s16 *, 0x14)) {
            M2C_FIELD(c, s16 *, 0x14) = (M2C_FIELD(c, s16 *, 0x14) - (0x80 - d->y)) / 2;
        }
        if (M2C_FIELD(c, s16 *, 0x14) < -0x1256) {
            M2C_FIELD(c, s16 *, 0x14) = -0x1256;
        }
    } else {
        M2C_FIELD(c, s16 *, 0xC) = (M2C_FIELD(c, s16 *, 0xC) * 3 - 0x1156) / 4;
    }
    M2C_FIELD(c, s16 *, 0xA) = 0x4C4;
    M2C_FIELD(c, s16 *, 0xE) = 0xA4F;
    M2C_FIELD(c, s16 *, 0x12) = M2C_FIELD(c, s16 *, 0xA) + (v.vx - 0x7C2) / 2;
    M2C_FIELD(c, s16 *, 0x16) = M2C_FIELD(c, s16 *, 0xE) + (v.vz + 0x98B) / 2;
}

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

extern s32 D_800EC208;
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013D3FC(void *arg0) {
    s32 var_a1;

    s32 t;

    t = D_800EC208 + 0xAA;
    var_a1 = 0;
    if ((u32) (M2C_FIELD(arg0, s16 *, 0x1E) - t) < 0x32U) {
        var_a1 = Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), 0xC8) == 0;
    }
    return var_a1;
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013D4BC asm("g_Game");
extern u8 D_800E77E2;
void Object_ApplyVelocity(void *);
void Object_PlaceAtPathPoint(void *, s32);
s32 Object_FollowPath(void *, s16, s8, s8);
void Object_FacePathPoint(void *, s32);
s16 func_8013D2B8(void *arg0, s16 arg1, s16 arg2);
void func_8013D3D0(void *arg0);
void func_8013D454(void *arg0);
void func_8013D4A8(void *arg0);

void func_8013D4BC(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(o, u8 *, 0x8E) = 0;
        M2C_FIELD(o, s16 *, 0x44) = 0;
        M2C_FIELD(o, s16 *, 0x48) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
            Object_PlaceAtPathPoint(o, 0);
            Object_FacePathPoint(o, 1);
            M2C_FIELD(o, s16 *, 0x9C) = M2C_FIELD(o, s32 *, 0x28) -= 100;
        }
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        M2C_FIELD(g_Game_8013D4BC.f_820C + M2C_FIELD(o, u16 *, 0x70) * 0x38, s16 *, 6) = 0xFA;
        M2C_FIELD(g_Game_8013D4BC.f_820C + M2C_FIELD(o, u16 *, 0x70) * 0x38, s16 *, 0xA) = 0xFA;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (D_800E77E2 == 1) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            Object_Timer(o, 0x28);
        }
        break;
    case 2:
        if (Object_Timer(o, -1) == 0) {
            if (Object_FollowPath(o, func_8013D2B8(o, 0x34, 8), 0, 0) != 0 && M2C_FIELD(o, u8 *, 0x8E) == 3) {
                M2C_FIELD(o, u8 *, 0x80) = 3;
                func_8013D454(o);
            }
            Object_ApplyVelocity(o);
        }
        break;
    case 3:
        if (func_8013D3FC(o) != 0) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            Object_Timer(o, 0x1E);
        }
        break;
    case 4:
        if (Object_Timer(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
        }
        break;
    case 5:
        Object_FollowPath(o, func_8013D2B8(o, 0x34, 8), 0, 0);
        if (M2C_FIELD(o, u8 *, 0x8E) == 0) {
            func_8013D4A8(o);
        }
        Object_ApplyVelocity(o);
        break;
    }
    func_8013D3D0(o);
}

typedef struct { s32 x, y, z; u8 pad0C[0x14]; s16 f20, f22, f24, f26; } Col_8013D72C;
typedef struct { s16 x, y, z; } SV_8013D72C;
extern Col_8013D72C D_80142CA0_8013D72C asm("D_80142CA0");
extern SV_8013D72C D_80142CD8_8013D72C asm("D_80142CD8");
s32 Collision_Set(s32, void *, void *);
void GuidedAmmo_AddTarget(void *);

void func_8013D72C(void *arg0) {
    Col_8013D72C *c = &D_80142CA0_8013D72C;
    s32 dz = (M2C_FIELD(arg0, s16 *, 0x64) * 0x19) >> 6;
    D_80142CA0_8013D72C.x = M2C_FIELD(arg0, s32 *, 0x24) + ((M2C_FIELD(arg0, s16 *, 0x60) * 0x19) >> 6);
    c->y = M2C_FIELD(arg0, s32 *, 0x28);
    c->z = M2C_FIELD(arg0, s32 *, 0x2C) + dz;
    c->f24 = 0;
    c->f26 = -0x4000;
    c->f20 = 0x2BC;
    c->f22 = 0x59C;
    Collision_Set(4, c, arg0);
    D_80142CD8_8013D72C.x = D_80142CA0_8013D72C.x;
    D_80142CD8_8013D72C.y = c->y - 0x2CE;
    D_80142CD8_8013D72C.z = c->z;
    GuidedAmmo_AddTarget(&D_80142CD8_8013D72C);
}

void func_8013D7FC(void *arg0) {
    if (((u32) D_80142CA0.f_2C >> 0x1C) == 0xB) {
        Collision_Remove(&D_80142CA0);
        GuidedAmmo_RemoveTarget(&D_80142CD8);
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Sound_PlayFixed(0xAC);
        Sound_PlayFixed(0xAD);
        Sound_FreeSlot(M2C_FIELD(arg0, s8 *, 0x7C));
    }
}

typedef struct { u16 start; u16 end; } Rng_8013D884;
extern struct { s32 x; u8 pad4[4]; s32 z; } D_80142CA0_8013D884 asm("D_80142CA0");
void Object_PlaceAtPathPoint(void *, s32);
void Object_FacePathPoint(void *, s32);
s8 Sound_ReserveSlot_8013D884(s32, s32, void *) asm("Sound_ReserveSlot");
s32 Spike_WithinRadiusXZ_8013D884(s32, s32, s32) asm("Spike_WithinRadiusXZ");
M2C_UNK Object_Timer(void *, M2C_UNK);
void func_8013D72C(void *arg0);
void func_8013D7FC(void *arg0);

void func_8013D884(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 1;
        M2C_FIELD(o, s16 *, 0x46) = -100;
        M2C_FIELD(o, u8 *, 0xC8) = 25;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~0x1000) | 0x200;
        Object_PlaceAtPathPoint(o, 0);
        Object_FacePathPoint(o, 1);
        func_8013D72C(o);
        M2C_FIELD(o, s8 *, 0x7C) = Sound_ReserveSlot_8013D884(0x70B5, 0x1F40, &D_80142CA0_8013D884);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D884 **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013D7FC(o);
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013D884 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D884 **, 0x88)[2].start;
            Object_Timer(o, 240);
        }
        break;
    case 3:
        if (Object_Timer(o, -1) == 0 && Spike_WithinRadiusXZ_8013D884(D_80142CA0_8013D884.x, D_80142CA0_8013D884.z, 0x600) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D884 **, 0x88)[1].end - 2;
            func_8013D72C(o);
            Sound_PlayFixed(0xAD);
        }
        break;
    case 4:
        M2C_FIELD(o, u16 *, 0x5C) -= 2;
        if (M2C_FIELD(o, Rng_8013D884 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].start >= M2C_FIELD(o, u16 *, 0x5C)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D884 **, 0x88)[0].start;
            M2C_FIELD(o, s8 *, 0x7C) = Sound_ReserveSlot_8013D884(0x70B5, 0x1F40, &D_80142CA0_8013D884);
        }
        break;
    }
}

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
            Object_SetModel(m, k);
            Object_GetAnimTable(m, k);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f82; u8 life; s16 floor; s16 scale; } Debris_8013DB44;
extern Debris_8013DB44 D_80142CE0_8013DB44[] asm("D_80142CE0");
extern u16 g_RandSeed;
extern u16 g_RandSeed2;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 f60; u8 pad62[2]; s16 f64; u8 pad66[0x65]; u8 fCB; } Obj_8013DB44;

M2C_UNK func_8013DB44(void *o) {
    s32 i;
    Debris_8013DB44 *d;

    for (i = 0; i < 20; i++) {
        d = &D_80142CE0_8013DB44[i];
        d->x = ((Obj_8013DB44 *)o)->x + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->y = ((Obj_8013DB44 *)o)->y - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8);
        d->z = ((Obj_8013DB44 *)o)->z + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4 + (((Obj_8013DB44 *)o)->f60 * 5 >> 11);
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4 + (((Obj_8013DB44 *)o)->f64 * 5 >> 11);
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x20;
        d->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 30;
        d->f82 = ((Obj_8013DB44 *)o)->fCB;
        d->floor = (u16)((Obj_8013DB44 *)o)->y - 50;
        d->scale = (i % 3 + 2) << 12;
    }
}

typedef struct { s16 x, y, z; } Rot_8013DE2C;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_8013DE2C r; u8 pad82; u8 life; s16 floor; s16 scale; } Debris_8013DE2C;
extern Debris_8013DE2C D_80142CE0_8013DE2C[] asm("D_80142CE0");
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013DE2C asm("g_Game");
extern u8 D_800E7D00_8013DE2C[] asm("g_ProjVerts");
s32 Object_IsOffScreen(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void Model_DrawAuto(void *, void *, void *);

void func_8013DE2C(void) {
    s32 i;
    Debris_8013DE2C *d;
    s32 s[3];
    SVECTOR v;

    for (i = 0; i < 20; i++) {
        d = &D_80142CE0_8013DE2C[i];
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
            if (Object_IsOffScreen(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                s[0] = s[1] = s[2] = d->scale;
                ScaleMatrix(d->mat, s);
                Model_CalcKeyedJointMatrices(d, 3);
                Model_ProjectBonedVerts(d);
                Model_DrawAuto(g_Game_8013DE2C.f_80 + g_Game_8013DE2C.f_C * 0x4078, D_800E7D00_8013DE2C, d);
            }
        }
    }
}

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

M2C_UNK func_80051E98_8013E11C(void *, M2C_UNK) asm("Object_Despawn");
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
        Sound_FreeSlot(temp_a0);
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

typedef struct { u8 pad0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[0x6]; s32 f_28; u8 pad2C[0x18]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x2]; s16 f_60; u8 pad62[0x2]; s16 f_64; u8 pad66[0x16]; s8 f_7C; u8 pad7D[0x2]; u8 f_7F; u8 f_80; u8 pad81[0xB]; u8 f_8C; u8 pad8D[0x1]; u8 f_8E; u8 f_8F; u8 pad90[0x4]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x6]; s16 f_A0; u8 padA2[0x8]; s16 f_AA; u8 padAC[0x2]; s16 f_AE; u8 padB0[0x18]; u8 f_C8; u8 padC9[0x14]; u8 f_DD; u8 padDE[0x2]; u32 f_E0; } O_8013E200;
M2C_UNK Object_CameraShake_8013E200(void *, M2C_UNK) asm("Object_CameraShake");
M2C_UNK Object_PlaySound_8013E200(void *, M2C_UNK) asm("Object_PlaySound");
void func_8013E11C(void *arg0);
void func_8013E19C(void *arg0);
void func_8013E02C(void *arg0, s16 arg1, s32 arg2, s32 arg3);
void func_8013DA9C_8013E200() asm("func_8013DA9C");
void func_80058134_8013E200(void *, s32) asm("Object_DebugStub");
s16 Object_FloorAt_8013E200(void *, s32, s32, s32) asm("Object_FloorAt");
s32 Sound_ReserveSlot_8013E200(s32, s32, void *) asm("Sound_ReserveSlot");
s32 func_800585D0_8013E200(void *, s32, s32, s32) asm("Object_FollowPath");
s16 Object_PathPointNear_8013E200(void *, void *, s32, s32) asm("Object_PathPointNear");
u32 Object_DetachLink_8013E200(void *, s32) asm("Object_DetachLink");

void func_8013E200(O_8013E200 *o) {
    s32 flags;
    s32 f;

    if (!((o->f_E0 >> 3) & 1)) {
        o->f_A0 = 300;
        o->f_8F = 0;
        o->f_44 = 1;
        o->f_46 = 800;
        o->f_4A = -0x7EFD;
        o->f_48 = 1;
        o->f_8E = 1;
        o->f_E0 &= ~0x40;
        Object_PlaceAtPathPoint(o, 0);
        Object_FacePathPoint(o, 1);
        o->f_C8 = 8;
        o->f_96 = 0;
        o->f_8F = 0;
        o->f_AA = 0;
        o->f_AE = 0;
        o->f_28 -= 2000;
        o->f_94 = o->f_60 * 49 >> 12;
        o->f_98 = o->f_64 * 49 >> 12;
        o->f_DD = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1;
        o->f_7C = -1;
        func_8013DA9C_8013E200(o);
        o->f_7F = 1;
        o->f_5C = M2C_FIELD(o, u16 **, 0x88)[2];
        o->f_E0 |= 8;
    }
    func_80058134_8013E200(o, o->f_44);
    o->f_A0 = 300 - (o->f_28 - o->f_1E) * 100 / 1024;
    if (o->f_DD == 0 && o->f_5C == 0) {
        Object_SpawnEffect(o, 6, 0, 0, 0);
        Object_PlaySound_8013E200(o, 0xAF);
        Object_CameraShake_8013E200(o, 0);
    }
    switch (o->f_80) {
    case 1:
        flags = 0;
        o->f_96 += 7;
        Object_ApplyVelocity(o);
        f = Object_FloorAt_8013E200(o, 0, 0, 0);
        if (f < o->f_28) {
            o->f_28 = f;
            o->f_8F++;
            switch (o->f_DD) {
            case 0:
                o->f_98 = 0;
                o->f_96 = 0;
                o->f_94 = 0;
                o->f_80 = 2;
                o->f_7F = 0;
                o->f_5C = M2C_FIELD(o, u16 **, 0x88)[0];
                break;
            case 1:
                Object_SpawnEffect(o, 6, 0, 0, 0);
                Object_PlaySound_8013E200(o, 0xAF);
                Object_CameraShake_8013E200(o, 0);
                if (o->f_8F == 5) {
                    o->f_98 = 0;
                    o->f_96 = 0;
                    o->f_94 = 0;
                    o->f_80 = 2;
                    o->f_7F = 1;
                    o->f_5C = M2C_FIELD(o, u16 **, 0x88)[2];
                    o->f_7C = Sound_ReserveSlot_8013E200(0x707C, 0x1000, (u8 *)o + 0x24);
                } else {
                    o->f_96 = -o->f_96 / 2;
                }
                flags = 0xA00;
                break;
            }
        }
        Object_AddAttackSphereNear(o, 0xC8, o->f_1C, o->f_1E, o->f_20, flags | 1, 0x201);
        break;
    case 2:
        func_800585D0_8013E200(o, 0x31, 0, 1);
        if (Object_PathPointNear_8013E200(o, (u8 *)o + 0x24, 0xC8, (u8)(o->f_8C - 1))) {
            func_8013E11C(o);
        } else {
            if (o->f_DD == 0) {
                func_8013E02C(o, 0x10, 0xC8, 0);
            }
            Object_ApplyVelocity(o);
        }
        if (Object_DetachLink_8013E200(o, 0) == 6) {
            Object_Timer(o, 10);
        }
        if (Object_Timer(o, -1) == 0) {
            func_8013E19C(o);
        }
        break;
    }
}

void func_8013E5FC(void *arg0) {
    Sound_FreeSlot(M2C_FIELD(arg0, s8 *, 0x7C));
}

M2C_UNK Object_Despawn(s32, M2C_UNK);
M2C_UNK Object_SpawnHitSpark(s32, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013E620(s32 arg0) {
    func_8013E5FC(arg0);
    Object_SpawnHitSpark(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    Object_Despawn(arg0, 1);
}

void func_8013E670(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        Object_ApplyHit();
        Object_HitFeedback(arg0);
        func_8013E5FC(arg0);
    }
}

typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1E]; s8 f_7C; u8 pad7D[0x2]; u8 f_7F; u8 f_80; u8 pad81[0x15]; s16 f_96; u8 pad98[0x2]; s16 f_9A; s16 f_9C; s16 f_9E; s16 f_A0; u8 padA2[0x4]; s16 f_A6; u8 padA8[0x2]; s16 f_AA; u8 padAC[0x4]; s16 f_B0; u8 padB2[0x2]; s32 f_B4; u8 padB8[0x10]; u8 f_C8; u8 padC9[0x13]; u8 f_DC; u8 padDD[0x3]; u32 f_E0; } O_8013E6BC;
extern struct { u8 pad_0[0x28]; s32 y; } g_Spike_8013E6BC asm("g_Spike");
void func_8013E620(s32 arg0);
void func_8013E670(void *arg0);
s8 Sound_ReserveSlot_8013E6BC(s32, s32, void *) asm("Sound_ReserveSlot");
s32 Object_SpikeInFront_8013E6BC(void *, s32, s32, s32) asm("Object_SpikeInFront");
void func_80058134_8013E6BC(void *, s32) asm("Object_DebugStub");
void func_80055F1C_8013E6BC(void *, s32) asm("Object_InitOrbit");
void func_80055E6C_8013E6BC(void *, s32) asm("Object_OrbitHome");
void Object_ChaseSpike_8013E6BC(void *, s32) asm("Object_ChaseSpike");
void Object_SetForwardVelocity_8013E6BC(void *, s32) asm("Object_SetForwardVelocity");
s32 Math_WithinSquare_8013E6BC(s32, s32, s32) asm("Math_WithinSquare");
s32 Math_Atan2_8013E6BC(s32, s32) asm("Math_Atan2");
s16 Object_FloorAt_8013E6BC(void *, s32, s32, s32) asm("Object_FloorAt");
u32 Object_DetachLink_8013E6BC(void *, s32) asm("Object_DetachLink");
s32 rsin_8013E6BC(s32) asm("rsin");

void func_8013E6BC(O_8013E6BC *arg0) {
    O_8013E6BC *o = arg0;
    s32 d;
    s32 y;

    if (!((o->f_E0 >> 3) & 1)) {
        o->f_A0 = 0x32;
        o->f_B0 = 0x7D;
        o->f_48 = 1;
        o->f_4A = -0x7EFD;
        o->f_C8 = 4;
        o->f_46 = 0x64;
        o->f_AA = 0;
        o->f_DC = 0;
        o->f_E0 &= ~0x1000;
        o->f_7C = Sound_ReserveSlot_8013E6BC(0x70BA, 0x600, (u8 *)o + 0x24);
        func_80055F1C_8013E6BC(o, 0x32);
        o->f_7F = 0;
        o->f_5C = M2C_FIELD(o, u16 **, 0x88)[0];
        o->f_E0 |= 8;
    }
    func_80058134_8013E6BC(o, o->f_44);
    switch (o->f_80) {
    case 1:
        func_80055E6C_8013E6BC(o, 0x32);
        o->f_96 = 0;
        Object_ApplyVelocity(o);
        if (o->f_9C < g_Spike_8013E6BC.y && g_Spike_8013E6BC.y - o->f_9C < 0x800 && Object_FloorAt_8013E6BC(o, 0, 0, 0) >= g_Spike_8013E6BC.y && Object_SpikeInFront_8013E6BC(o, 0x168, -0x1000, 0x400)) {
            o->f_80 = 2;
            o->f_B0 = 0x71;
            Object_Timer(o, (((u32)((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 6) + 0x28);
        }
        break;
    case 2:
        Object_ChaseSpike_8013E6BC(o, 0x12);
        o->f_AA = (o->f_AA + 0xAA) % 4096;
        y = o->f_28 + 0x100;
        d = (D_800EC208 - y) >> 3;
        if (ABS(d) > 0x32) {
            d = (d > 0) ? 0x32 : -0x32;
        }
        o->f_96 = d + (rsin_8013E6BC(o->f_AA) * 30 >> 12);
        Object_ApplyVelocity(o);
        if (Object_DetachLink_8013E6BC(o, 0) == 6) {
            func_8013E620((s32)o);
            return;
        }
        o->f_B4 = Object_AddAttackSphereNear(o, 0x32, (s16)o->f_24, (s16)o->f_28, (s16)o->f_2C, o->f_48, o->f_4A);
        if (Object_FloorAt_8013E6BC(o, 0, 0, 0) < o->f_28) {
            o->f_80 = 3;
        }
        if (Object_Timer(o, -1) == 0) {
            o->f_80 = 3;
        }
        break;
    case 3:
        Object_TurnToward(o, o->f_9A - o->f_24, o->f_9E - o->f_2C, 0, o->f_B0);
        Object_SetForwardVelocity_8013E6BC(o, 0x12);
        o->f_AA = (o->f_AA + 0xAA) % 4096;
        d = (o->f_9C - o->f_28) >> 2;
        if (ABS(d) > 0x14) {
            d = (d > 0) ? 0x14 : -0x14;
        }
        o->f_96 = d + (rsin_8013E6BC(o->f_AA) * 30 >> 12);
        Object_ApplyVelocity(o);
        if (Math_WithinSquare_8013E6BC(o->f_9A - o->f_24, o->f_9E - o->f_2C, o->f_A6)) {
            if (ABS(o->f_9C - o->f_28) < 0x14) {
                o->f_AA = (Math_Atan2_8013E6BC(o->f_24 - o->f_9A, o->f_2C - o->f_9E) + 0x1400) % 4096;
                o->f_80 = 1;
                o->f_96 = 0;
                o->f_B0 = 0x7D;
                o->f_28 = o->f_9C;
            }
        }
        break;
    }
    func_8013E670(o);
}

extern u16 g_RandSeed;
s32 rcos_8013EB6C(s32) asm("rcos");
s32 rsin_8013EB6C(s32) asm("rsin");
void Effect_SpawnAt_8013EB6C(s32, SVECTOR *) asm("Effect_SpawnAt");

void func_8013EB6C(u8 *arg0) {
    s16 *p = M2C_FIELD(arg0, s16 **, 0x74);
    SVECTOR v;
    s32 i;
    s32 a;
    s32 r;
    s32 c;
    s32 t;

    for (i = 8; i > 0; i--) {
        a = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) << 12) / 255;
        r = ((g_RandSeed = g_RandSeed * 5 + 1) >> 10) + 0xB4;
        c = rcos_8013EB6C(a) * r >> 12;
        t = (g_RandSeed = g_RandSeed * 5 + 1) >> 8;
        v.vx = p[0] + c;
        v.vy = p[1] - t * 7;
        v.vz = p[2] + (rsin_8013EB6C(a) * r >> 12);
        Effect_SpawnAt_8013EB6C(0x2B, &v);
    }
}

void func_8013EC9C(void *arg0, M2C_UNK arg1) {
    Shadow_Draw(arg0, Floor_GetHeight(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8)), arg1, *(s32 *)0x1F8003FC);
}

s32 Object_AddAttackSphere_8013ECF8(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void func_8013EC9C(void *arg0, M2C_UNK arg1);
extern u8 D_800E77E5;
void Debug_DrawWorldQuad(void *, s32, s32);
typedef struct { u16 start; u16 end; } Rng_8013ECF8;

void func_8013ECF8(u8 *arg0) {
    s16 *a = M2C_FIELD(arg0, s16 **, 0x74);
    s32 *s = M2C_FIELD(arg0, s32 **, 0xB4);
    s32 v[3];
    Rng_8013ECF8 *f;
    s32 t;

    s[0] = a[0];
    s[1] = a[1] + 0x19;
    s[2] = a[2];
    if (arg0[0x80] == 2 && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        f = (Rng_8013ECF8 *)(arg0[0x7F] * 4 + M2C_FIELD(arg0, s32 *, 0x88));
        t = M2C_FIELD(arg0, u16 *, 0x5C);
        if (f->start + 0x10 < t && t < f->start + 0x16) {
            Object_AddAttackSphere_8013ECF8(arg0, 0xC8, a[0], a[1], a[2], 1, 0x203);
        }
    }
    func_8013EC9C(s, 0xB4);
    if (D_800E77E5 >= 2) {
        v[0] = s[0];
        v[1] = s[1];
        v[2] = s[2];
        Debug_DrawWorldQuad(v, ((s16 *)s)[0x10], ((s16 *)s)[0x11]);
    }
}

typedef struct { u8 pad0[0x24]; s16 x; u8 pad26[6]; s16 z; u8 pad2E[0x2E]; u16 f_5C; u8 pad5E[0x20]; u8 f_7E, f_7F, f_80, f_81; u8 pad82[2]; u8 f_84; u8 pad85[3]; u8 *f_88; u8 pad8C[0xA]; s16 f_96; u8 pad98[0x1C]; u8 *f_B4; } O_8013EE1C;
s32 Collision_GetShape_8013EE1C(s32) asm("Collision_GetShape");
s32 func_800525A0_8013EE1C(void *, s32) asm("Object_TakeHitDamage");
void func_8006B3CC_8013EE1C(SVECTOR *) asm("Fx_SpawnHitSpark");
M2C_UNK Object_PlaySound_8013EE1C(void *, M2C_UNK) asm("Object_PlaySound");
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[6]; s16 z; } g_Spike_8013EE1C asm("g_Spike");
extern s32 D_8014389C;
extern s32 D_80143898;

s32 func_8013EE1C(O_8013EE1C *o) {
    u8 *c;
    SVECTOR v;

    c = o->f_B4;
    if (o->f_84 != 0) {
        return 0;
    }
    if ((M2C_FIELD(c, u32 *, 0x2C) >> 28) != 0xB) {
        return 0;
    }
    Object_TurnToward(o, g_Spike_8013EE1C.x - o->x, g_Spike_8013EE1C.z - o->z, 0, 0x1000);
    if (func_800525A0_8013EE1C(o, Collision_GetShape_8013EE1C(M2C_FIELD(c, u16 *, 0x2C) & 0xFFF))) {
        if (o->f_7E == 0x2C) {
            o->f_80 = 8;
        } else {
            o->f_80 = 4;
            o->f_7F = 2;
            o->f_5C = M2C_FIELD(o->f_88, u16 *, 8);
            o->f_81 = 4;
            o->f_96 = -0xA0;
            if (++D_8014389C == 4) {
                D_80143898 = 1;
            }
        }
    } else {
        o->f_80 = 3;
        o->f_7F = 3;
        o->f_5C = M2C_FIELD(o->f_88, u16 *, 0xC);
    }
    v.vx = M2C_FIELD(c, s16 *, 0);
    v.vy = M2C_FIELD(c, s16 *, 4);
    v.vz = M2C_FIELD(c, s16 *, 8);
    func_8006B3CC_8013EE1C(&v);
    Object_PlaySound_8013EE1C(o, 0x15);
    Object_PlaySound_8013EE1C(o, 0xB8);
    o->f_84 = 20;
}

typedef struct { s32 x, y, z; u8 pad0C[0x14]; s16 f20, f22, f24, f26; u8 pad28[0x10]; } Col_8013EF98;
extern Col_8013EF98 D_80143780_8013EF98[] asm("D_80143780");
void Collision_Set_8013EF98(s32, void *, void *) asm("Collision_Set");

void func_8013EF98(void *arg0, s32 arg1) {
    Col_8013EF98 *c = &D_80143780_8013EF98[arg1];
    c->x = M2C_FIELD(arg0, s32 *, 0x24);
    c->y = M2C_FIELD(arg0, s32 *, 0x28);
    c->z = M2C_FIELD(arg0, s32 *, 0x2C);
    c->f26 = -0x4000;
    c->f20 = 0x96;
    c->f24 = 0;
    c->f22 = 0xFA;
    M2C_FIELD(arg0, void **, 0xB4) = c;
    Collision_Set_8013EF98(4, c, arg0);
}

s32 rcos_8013F010(s16) asm("rcos");
s32 rsin_8013F010(s16) asm("rsin");
typedef struct { u16 start; u16 end; } Rng_8013F010;
typedef struct { u8 pad0[0x60]; s16 f60; u8 pad62[2]; s16 f64; u8 pad66[0x19]; u8 f7F; u8 pad80[8]; Rng_8013F010 *f88; u8 pad8C[0x20]; s16 fAC; } O_8013F010;

void func_8013F010(u8 *arg0) {
    ((O_8013F010 *)arg0)->fAC = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) << 12) / 255 % 0x1000;
    ((O_8013F010 *)arg0)->f60 = rcos_8013F010(((O_8013F010 *)arg0)->fAC);
    ((O_8013F010 *)arg0)->f64 = rsin_8013F010(((O_8013F010 *)arg0)->fAC);
    M2C_FIELD(arg0, u16 *, 0x5C) = ((O_8013F010 *)arg0)->f88[arg0[0x7F]].start + ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * (((O_8013F010 *)arg0)->f88[arg0[0x7F]].end - ((O_8013F010 *)arg0)->f88[arg0[0x7F]].start) / 255;
}

extern u8 g_Objects[];

void func_8013F138(u8 *arg0) {
    u8 *o = g_Objects + M2C_FIELD(arg0, s8 *, 0xCA) * 0xE4;
    u8 t = arg0[0x7E];

    if ((t == 0x70 && o[0x81] == 0) || (t == 0x2C && arg0[0x81] == 0)) {
        Collision_Remove(M2C_FIELD(arg0, void **, 0xB4));
        GuidedAmmo_RemoveTarget(M2C_FIELD(arg0, void **, 0x74));
    }
}

extern s32 D_801438A0;
typedef struct { u8 pad[0x74]; s32 h; } O_8013F1D0;
s32 func_80057140_8013F1D0(void *, s32, s32) asm("Object_AddAttachPoint");
void func_8013EF98(void *arg0, s32 arg1);
void func_8007CD88_8013F1D0(s32) asm("GuidedAmmo_AddTarget");

void func_8013F1D0(u8 *o) {
    M2C_FIELD(o, s16 *, 0xB0) = 0x16;
    M2C_FIELD(o, s16 *, 0x46) = -0xAF0;
    M2C_FIELD(o, s16 *, 0x9C) -= 0x28A;
    M2C_FIELD(o, s16 *, 0xA0) = 0;
    M2C_FIELD(o, s16 *, 0x96) = 0;
    if (M2C_FIELD(o, u8 *, 0x7E) == 0x2C) {
        M2C_FIELD(o, u8 *, 0x81) = 12;
        M2C_FIELD(o, u8 *, 0xC8) = 15;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
    } else {
        M2C_FIELD(o, u8 *, 0x81) = 4;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u8 *, 0x80) = 6;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) - 0xC30;
    }
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
    M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
    ((O_8013F1D0 *)o)->h = func_80057140_8013F1D0(o, 0xB, -1);
    func_8013EF98(o, D_801438A0);
    D_801438A0++;
    func_8007CD88_8013F1D0(((O_8013F1D0 *)o)->h);
    func_8013F010(o);
    M2C_FIELD(o, s16 *, 0xC2) = 0;
}

typedef struct { u16 start; u16 end; } Anim_8013F2CC;
void func_8013EB6C(u8 *arg0);
void func_8013ECF8(u8 *arg0);
void func_8013F138(u8 *arg0);
void func_8013F1D0(u8 *o);
M2C_UNK Object_PlaySound_8013F2CC(void *, M2C_UNK) asm("Object_PlaySound");
M2C_UNK func_80051E98_8013F2CC(void *, M2C_UNK) asm("Object_Despawn");
void Object_TurnTowardSpike_8013F2CC(void *) asm("Object_TurnTowardSpike");
s32 func_8013EE1C_8013F2CC(void *) asm("func_8013EE1C");
s32 Spike_WithinRadiusXZ_8013F2CC(s32, s32, s32) asm("Spike_WithinRadiusXZ");
void Object_ClampAnimFrame_8013F2CC(void *, s32) asm("Object_ClampAnimFrame");
void Link_SendEvent_8013F2CC(s32, s32, s32) asm("Link_SendEvent");

void func_8013F2CC(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013F1D0(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_TurnTowardSpike_8013F2CC(o);
        if (func_8013EE1C_8013F2CC(o) != 0) {
            break;
        }
        if (Object_Timer(o, -1) != 0) {
            break;
        }
        if (Spike_WithinRadiusXZ_8013F2CC(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), 0x400)) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
        }
        break;
    case 2:
        if (M2C_FIELD(o, u8 *, 0x7F) == 0) {
            if (++M2C_FIELD(o, u16 *, 0x5C) < M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
                break;
            }
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[1].start;
        }
        if (func_8013EE1C_8013F2CC(o) != 0) {
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].start + 0x10) {
            Object_PlaySound_8013F2CC(o, 0x1A);
        }
        if (M2C_FIELD(o, u16 *, 0x5C) < M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            break;
        }
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[0].start;
        Object_Timer(o, 0x3C);
        break;
    case 3:
        if (M2C_FIELD(o, u16 *, 0x5C) < M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            break;
        }
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[0].start;
        break;
    case 4:
        M2C_FIELD(o, s16 *, 0x96) += 4;
        if (M2C_FIELD(o, s16 *, 0x96) > 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[0].start;
            M2C_FIELD(o, s16 *, 0x96) = 0;
            M2C_FIELD(o, u8 *, 0xC8) = 0;
            M2C_FIELD(o, s16 *, 0xC2) = 600;
        } else {
            M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        }
        break;
    case 5:
        if (D_80143898 != 0) {
            M2C_FIELD(o, u8 *, 0x80) = 6;
            break;
        }
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
            break;
        }
        D_8014389C--;
        M2C_FIELD(o, u8 *, 0x80) = 7;
        M2C_FIELD(o, u8 *, 0x7F) = 4;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[4].start;
        M2C_FIELD(o, u8 *, 0xC8) = 0xF;
        M2C_FIELD(o, u8 *, 0x84) = 0;
        func_8013F010(o);
        break;
    case 6:
        if (D_80143898 == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, s16 *, 0xC2) = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 60) / 255;
        }
        break;
    case 7:
        M2C_FIELD(o, s16 *, 0x96) += 4;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        if (M2C_FIELD(o, s16 *, 0x9C) < M2C_FIELD(o, s32 *, 0x28)) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Anim_8013F2CC **, 0x88)[0].start;
            Object_PlaySound_8013F2CC(o, 0xB7);
        }
        break;
    case 8:
        M2C_FIELD(o, u8 *, 0x84) = 1;
        if (M2C_FIELD(o, u16 *, 0x5C) < M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            break;
        }
        Object_SetModel(o, 0xA6);
        M2C_FIELD(o, u8 *, 0x80) = 9;
        Object_PlaySound_8013F2CC(o, 0x3B);
        Object_Timer(o, 0x28);
        M2C_FIELD(o, u16 *, 0x5C)--;
        break;
    case 9:
        Object_ClampAnimFrame_8013F2CC(o, M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
        if (M2C_FIELD(o, u8 *, 0xC9) > 0x14) {
            func_8013EB6C(o);
        }
        if (Object_Timer(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 10;
            M2C_FIELD(o, s16 *, 0x96) = 0;
        }
        break;
    case 10:
        Object_ClampAnimFrame_8013F2CC(o, M2C_FIELD(o, Anim_8013F2CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
        M2C_FIELD(o, s16 *, 0x96) -= 2;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        if (M2C_FIELD(o, s32 *, 0x28) < M2C_FIELD(o, s16 *, 0x9C) - 0xC30) {
            func_80051E98_8013F2CC(o, 1);
            Link_SendEvent_8013F2CC(0xC, 2, 0);
        }
        break;
    }
    func_8013ECF8(o);
    func_8013F138(o);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[8]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f82; u8 life; } Debris_8013F78C;
extern Debris_8013F78C D_801438B0_8013F78C[] asm("D_801438B0");
extern s32 D_80143780[3];
void Hook_Add_8013F78C(void *) asm("Hook_Add");
void func_8013FAB8(void);

/* called without its argument (old-style declaration), so defined old-style */
M2C_UNK func_8013F78C(o)
    u8 *o;
{
    s32 i;
    Debris_8013F78C *d;
    s32 k;
    s32 *c = D_80143780;

    for (i = 0; i < 16; i++) {
        d = &D_801438B0_8013F78C[i];
        k = (i & 1) + 0xA3;
        Object_SetModel(d, k);
        Object_GetAnimTable(d, k);
        d->f5C = 0;
        d->f62 = 0;
        d->f60 = 0;
        d->f64 = 0x1000;
        d->f66 = 3;
        d->x = c[0] + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->y = c[1] - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8);
        d->z = c[2] + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 6;
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 6;
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x40;
        d->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 60;
        d->f82 = o[0xCB];
    }
    Hook_Add_8013F78C(func_8013FAB8);
}

typedef struct { u8 pad0[0x14]; s32 mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 rvx, rvy, rvz; s16 rx, ry, rz; u8 pad82; u8 timer; } Deb_8013FAB8;
void Model_ProjectBonedVerts(void *);
void RotMatrixYXZ(void *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_DrawAuto(void *, void *, void *);
s32 Object_IsOffScreen(void *, s32, s32);
extern M2C_UNK g_ProjVerts;
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013FAB8 asm("g_Game");
extern Deb_8013FAB8 D_801438B0_8013FAB8[] asm("D_801438B0");

void func_8013FAB8(void) {
    s32 i;
    Deb_8013FAB8 *m;

    for (i = 0; i < 16; i++) {
        m = &D_801438B0_8013FAB8[i];
        if (m->timer != 0) {
            m->timer--;
            m->x += m->vx;
            m->y += m->vy;
            m->z += m->vz;
            m->vy += 7;
            if (m->y >= -0xA00) {
                m->y = -0xA00;
                m->vy = -(m->vy / 2);
            }
            m->rx = (m->rx + m->rvx) % 4096;
            m->ry = (m->ry + m->rvy) % 4096;
            m->rz = (m->rz + m->rvz) % 4096;
            if (Object_IsOffScreen(&m->x, 0, 0) == 0) {
                RotMatrixYXZ(&m->rx, (void *)m->mat);
                Model_CalcKeyedJointMatrices(m, 3);
                Model_ProjectBonedVerts(m);
                Model_DrawAuto(g_Game_8013FAB8.f_80 + g_Game_8013FAB8.f_C * 0x4078, &g_ProjVerts, m);
            }
        }
    }
}

void func_8013FC78(s32 arg0) {
    func_8013F78C();
    Object_CameraShake(arg0, 2);
    Object_PlaySound(arg0, 0xB6);
}

extern M2C_UNK D_801438A8;

void func_8013FCB4(void *arg0) {
    Object_SetModel(arg0, 0x82);
    Collision_Remove(M2C_FIELD(arg0, s32 *, 0xB4));
    GuidedAmmo_RemoveTarget(&D_801438A8);
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
}

void func_8006B3CC_8013FD00(SVECTOR *) asm("Fx_SpawnHitSpark");

s32 func_8013FD00(u8 *o) {
    u8 *s = M2C_FIELD(o, u8 **, 0xB4);
    SVECTOR v;

    if ((M2C_FIELD(s, u32 *, 0x2C) >> 28) != 11) {
        return 0;
    }
    if (M2C_FIELD(o, u8 *, 0x84) != 0) {
        return 0;
    }
    v.vx = M2C_FIELD(s, s32 *, 0);
    v.vy = M2C_FIELD(s, s32 *, 4);
    v.vz = M2C_FIELD(s, s32 *, 8);
    func_8006B3CC_8013FD00(&v);
    Object_PlaySound(o, 0x15);
    Object_PlaySound(o, 0xB9);
    M2C_FIELD(o, u8 *, 0x84) = 20;
    if (Object_TakeHitDamage(o, (u8 *)Collision_GetShape(M2C_FIELD(s, u16 *, 0x2C) & 0xFFF))) {
        func_8013FC78(o);
        func_8013FCB4(o);
    }
    return 1;
}

extern struct { s16 x, y, z; } D_801438A8_8013FDD0 asm("D_801438A8");
extern u8 D_800E77E5;

void func_8013FDD0(u8 *o) {
    s16 *a = M2C_FIELD(o, s16 **, 0x74);
    s32 *s = M2C_FIELD(o, s32 **, 0xB4);
    s32 v[3];

    D_801438A8_8013FDD0.x = s[0] = a[0];
    D_801438A8_8013FDD0.y = s[1] = a[1] + 0xBE;
    D_801438A8_8013FDD0.z = s[2] = a[2];
    D_801438A8_8013FDD0.y -= 0xC8;
    func_8013EC9C(s, 0x17C);
    if (D_800E77E5 >= 2) {
        v[0] = s[0];
        v[1] = s[1];
        v[2] = s[2];
        Debug_DrawWorldQuad(v, ((s16 *)s)[0x10], ((s16 *)s)[0x11]);
    }
}

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x70]; s16 f9C; } O_8013FE88;
s32 func_80057140_8013FE88(void *, s32, s32) asm("Object_AddAttachPoint");
void func_8007CD88_8013FE88(void *) asm("GuidedAmmo_AddTarget");
void func_80056BC4_8013FE88(s32, s32, s8) asm("Object_SpawnPooled");

void func_8013FE88(u8 *o) {
    s32 i;

    M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(o, u8 *, 0xC8) = 0xC;
    M2C_FIELD(o, s16 *, 0x46) = -0x960;
    M2C_FIELD(o, u8 *, 0x81) = 0x18;
    D_80143898 = 1;
    D_8014389C = 4;
    M2C_FIELD(o, s16 *, 0xA0) = 0;
    D_801438A0 = 1;
    ((O_8013FE88 *)o)->f9C -= 0x1F4;
    ((O_8013FE88 *)o)->y = ((O_8013FE88 *)o)->f9C;
    func_8013EF98(o, 0);
    M2C_FIELD(M2C_FIELD(o, u8 **, 0xB4), s16 *, 0x20) = 0x10E;
    M2C_FIELD(M2C_FIELD(o, u8 **, 0xB4), s16 *, 0x22) = 0x1D6;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
    M2C_FIELD(o, s32 *, 0x74) = func_80057140_8013FE88(o, 9, -1);
    func_8007CD88_8013FE88(&D_801438A8);
    for (i = 0; i < 4; i++) {
        func_80056BC4_8013FE88(0x70, 0, M2C_FIELD(o, s8 *, 0xCB));
    }
    func_80056BC4_8013FE88(0x30, 0, M2C_FIELD(o, s8 *, 0xCB));
    M2C_FIELD(o, u8 *, 0x80) = 1;
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
}

s32 Spike_WithinRadiusXZ_8013FFA8(s32, s32, s32) asm("Spike_WithinRadiusXZ");
M2C_UNK Object_PlaySound_8013FFA8(void *, M2C_UNK) asm("Object_PlaySound");
void Camera_StartShake_8013FFA8(s32) asm("Camera_StartShake");
void Link_SendEvent_8013FFA8(s32, s32, s32) asm("Link_SendEvent");
void func_8013FE88_8013FFA8(void) asm("func_8013FE88");
void func_8013D0A0(void);
void func_8013D0AC(void);
void func_8013D0BC(void);
void func_8013FCB4(void *arg0);
s32 func_8013FD00(u8 *o);
void func_8013FDD0(u8 *o);

void func_8013FFA8(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_8013FE88_8013FFA8();
        func_8013D0A0();
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 4) {
        M2C_FIELD(o, u8 *, 0x81) = 0;
        func_8013FCB4(o);
        M2C_FIELD(o, s32 *, 0x28) = -0xA00;
        M2C_FIELD(o, u8 *, 0xCF) = 0;
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (Spike_WithinRadiusXZ_8013FFA8(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x800)) {
            func_8013D0AC();
            M2C_FIELD(o, u8 *, 0x80) = 5;
        }
        break;
    case 2:
        if (D_80143898 != 0) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0xC8) = 12;
        }
        break;
    case 3:
        M2C_FIELD(o, s16 *, 0x96) += 3;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        if (M2C_FIELD(o, s16 *, 0x9C) < M2C_FIELD(o, s32 *, 0x28)) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
            M2C_FIELD(o, s16 *, 0x96) = 0;
            M2C_FIELD(o, u8 *, 0x80) = 4;
            Object_Timer(o, 150);
            Object_PlaySound_8013FFA8(o, 0xB7);
            func_8013D0AC();
            Camera_StartShake_8013FFA8(1);
        }
        break;
    case 4:
        if (func_8013FD00(o) == 0 && Object_Timer(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
        }
        break;
    case 5:
        M2C_FIELD(o, s16 *, 0x96) -= 2;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        if (M2C_FIELD(o, s32 *, 0x28) < M2C_FIELD(o, s16 *, 0x9C) - 2000) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) - 2000;
            M2C_FIELD(o, u8 *, 0x80) = 2;
            D_80143898 = 0;
            M2C_FIELD(o, u8 *, 0xC8) = 0;
            func_8013D0BC();
        }
        break;
    case 6:
        if (M2C_FIELD(o, s16 *, 0x9C) - 2000 < M2C_FIELD(o, s32 *, 0x28)) {
            M2C_FIELD(o, s16 *, 0x96) -= 2;
            M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        } else {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) - 2000;
        }
        Link_SendEvent_8013FFA8(13, 0, 0);
        M2C_FIELD(o, s16 *, 0x5E) = 1;
        break;
    }
    func_8013FDD0(o);
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_801401E8(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 0);
}

void func_80140234(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(temp_v1, s16 *, 2) + 0xBE);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
}

typedef struct { u16 start; u16 end; } Rng_80140264;
s32 func_80057140_80140264(void *, s32, s32) asm("Object_AddAttachPoint");
M2C_UNK func_80051E98_80140264(void *, M2C_UNK) asm("Object_Despawn");
void Object_TurnTowardSpike(void *);
void func_801401E8(void *arg0);
void func_80140234(void *arg0, void *arg1);

void func_80140264(u8 *o) {
    u8 *p = g_Objects + M2C_FIELD(o, s8 *, 0xCA) * 0xE4;

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x44;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0xC8) = 12;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x42000;
        M2C_FIELD(o, s32 *, 0x74) = func_80057140_80140264(o, 6, 0x45);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_80140264 **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(p, u8 *, 0xC8) != 0) {
        M2C_FIELD(o, u8 *, 0xC8) = 10;
    } else {
        M2C_FIELD(o, u8 *, 0xC8) = 0;
    }
    if (M2C_FIELD(p, u8 *, 0x80) == 6) {
        func_80051E98_80140264(o, 0);
    }
    Object_TurnTowardSpike(o);
    func_80140234(o, p);
    func_801401E8(o);
    if (M2C_FIELD(o, u8 *, 0xC9) != 0) {
        M2C_FIELD(o, u8 *, 0xC9)--;
    } else if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, Rng_80140264 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
        switch (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) {
        case 0:
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_80140264 **, 0x88)[2].start;
            Object_Timer(o, 20);
            break;
        case 1:
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_80140264 **, 0x88)[0].start;
            Object_Timer(o, 20);
            break;
        case 2:
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_80140264 **, 0x88)[1].start;
            Object_Timer(o, 20);
            break;
        default:
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_80140264 **, 0x88)[3].start;
            Object_Timer(o, 20);
            break;
        }
    }
}

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

extern u8 D_80142A64[];
void *memset(void *, s32, s32);
void Rock_SpawnBurst(SVECTOR *, void *);

void func_801404FC(void *arg0) {
    SVECTOR w;
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    w = v;
    Rock_SpawnBurst(&w, D_80142A64);
    Sound_FreeSlot(M2C_FIELD(arg0, s8 *, 0x7C));
    Object_PlaySound(arg0, 0x4D);
}

void func_80140590(void *arg0) {
    u8 one = 1;
    s32 r;
    s32 t;
    u16 q;

    M2C_FIELD(arg0, u8 *, 0x80) = one;
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    Object_PlaceAtPathPoint(arg0, 0);
    q = g_RandSeed * 5 + 1;
    M2C_FIELD(arg0, u16 *, 0x9C) = M2C_FIELD(arg0, u16 *, 0x28);
    g_RandSeed = q;
    r = (q >> 6) & 0x3FC;
    t = M2C_FIELD(arg0, s32 *, 0x28) - 0xBB8;
    M2C_FIELD(arg0, s32 *, 0x28) = t - r;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
    M2C_FIELD(arg0, u8 *, 0x8E) = one;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x40;
}

void Object_EnableCollision(void *);
void Object_DebugStub(void *, s32);
void func_8014045C(void *arg0);
void func_801404FC(void *arg0);

void func_80140624(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0xA0) = 0x190;
        M2C_FIELD(o, s16 *, 0x44) = 0x118;
        M2C_FIELD(o, s16 *, 0x46) = 0x2BC;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, u8 *, 0xC8) = 10;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, s16 *, 0xAA) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u8 *, 0x8E) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x40000;
        func_80140590(o);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96) += 0xE;
        if (M2C_FIELD(o, s16 *, 0x9C) < M2C_FIELD(o, s32 *, 0x28)) {
            M2C_FIELD(o, u8 *, 0x8F)++;
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
            Object_PlaySound_8013E11C(o, 0x4D);
            if (M2C_FIELD(o, u8 *, 0x8F) >= 4) {
                M2C_FIELD(o, u8 *, 0x80) = 2;
                M2C_FIELD(o, s8 *, 0x7C) = Sound_ReserveSlot_8013D884(0x707C, 0x1000, o + 0x24);
            } else {
                M2C_FIELD(o, s16 *, 0x96) = M2C_FIELD(o, s16 *, 0x96) / -3;
            }
        }
        break;
    case 2:
        Object_FollowPath(o, 0x28, 1, 1);
        Object_ApplyVelocity(o);
        func_8014045C(o);
        break;
    case 3:
        D_800E77A0_8013E11C.f_1--;
        func_801404FC(o);
        M2C_FIELD(o, u8 *, 0x80) = 4;
        Object_Timer(o, 0xF0);
        Object_DisableCollision(o);
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        break;
    case 4:
        M2C_FIELD(o, s16 *, 0x5E) = 1;
        if (Object_Timer(o, -1) == 0) {
            Object_EnableCollision(o);
            M2C_FIELD(o, u8 *, 0xC8) = 10;
            func_80140590(o);
        }
        break;
    }
}

void func_80140898(void *arg0, void *arg1, M2C_UNK arg2) {
    Object_SetModel(arg1, arg2);
    Object_GetAnimTable(arg1, arg2);
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
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_DrawAuto(void *, void *, void *);
s32 Object_IsOffScreen(void *, s32, s32);
extern M2C_UNK g_ProjVerts;
extern u8 D_80144190[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140938 asm("g_Game");

void func_80140938(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80144190 + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game_80140938.f_80 + g_Game_80140938.f_C * 0x4078, &g_ProjVerts, m);
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

void func_80140C4C(SVECTOR *p) {
    s32 i;
    SVECTOR v;

    for (i = 0; i < 32; i++) {
        v.vx = p->vx;
        v.vy = p->vy;
        v.vz = p->vz;
        Effect_SpawnAt(10, &v);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, owner; s32 unk10; } Drip_80140CAC;
extern Drip_80140CAC D_801440F0_80140CAC[8] asm("D_801440F0");
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; SVECTOR dir; } Mdl_80140CAC;
extern Mdl_80140CAC D_80144190_80140CAC asm("D_80144190");
s32 Object_AddAttackSphere_80140CAC(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
u32 Object_DetachLink_80140CAC(void *, s32) asm("Object_DetachLink");
void Object_PlaySound_80140CAC(void *, s32) asm("Object_PlaySound");
void VectorNormalSS_80140CAC(void *, void *) asm("VectorNormalSS");
void func_80140938(s32 arg0, s32 arg1);
s32 func_80140BC8(void *arg0);
void func_80140C0C(SVECTOR *arg0);
void func_80140C4C(SVECTOR *p);

void func_80140CAC(void) {
    s32 i;
    Drip_80140CAC *d;
    u8 *o;
    Mdl_80140CAC *m = &D_80144190_80140CAC;

    for (i = 7; i >= 0; i--) {
        d = &D_801440F0_80140CAC[i];
        if (d->active != 0) {
            d->active++;
            d->vy += 4;
            o = g_Objects + d->owner * 0xE4;
            func_80140C0C((SVECTOR *)d);
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            if (Object_DetachLink_80140CAC(o, 0) == 6) {
                d->active = 0;
                func_80140C4C((SVECTOR *)d);
                Object_PlaySound_80140CAC(o, 0x6B);
            } else if (func_80140BC8(d) || M2C_FIELD(o, s32 *, 0x28) + 0x600 < d->y) {
                d->active = 0;
                func_80140C4C((SVECTOR *)d);
            } else {
                m->x = d->x;
                m->y = d->y;
                m->z = d->z;
                m->dir.vx = d->vx;
                m->dir.vy = d->vy;
                m->dir.vz = d->vz;
                VectorNormalSS_80140CAC(&m->dir, &m->dir);
                func_80140938(0, 3);
                M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphere_80140CAC(o, 0x1E, d->x, d->y, d->z, 1, 0x203);
            }
        }
    }
}

void func_80140E88(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_80140EB4(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_SpawnHitSpark(arg0, 0, 0, 0);
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
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

void func_80140FD4(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        func_80140A90(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

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
    Object_Timer(arg0, M2C_FIELD(arg0, s16 *, 0x9A) % 60 + 60);
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

void func_80141038(void *arg0);
void func_80140A00(void *arg0);
void func_80140E88(void *arg0);
void func_80140EB4(void *arg0);
void func_80140F44(void *arg0);
void func_80140FD4(void *arg0);
s32 func_80141110(void *arg0);
void Object_EnableCollision(void *);
void Object_DebugStub(void *, s32);
s16 Object_FloorAt(void *, s16, s16, s16);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);
#define ANIM_8013DF54(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_8014116C(u8 *o) {
    s32 st;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_80141038(o);
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u8 *, 0xC9) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        func_80140A00(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (st = M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        Shadow_Draw(o + 0x24, Object_FloorAt(o, 0, 0, 0), M2C_FIELD(o, s16 *, 0xA0), M2C_FIELD(o, s32 *, 0xD0));
        if (Object_Timer(o, -1) == 0
            && Object_SpikeOutOfRange(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s16 *, 0x9E), 1500) == 0) {
            func_80140F44(o);
            M2C_FIELD(o, u8 *, 0xC8) = 14;
            Object_EnableCollision(o);
        }
        break;
    case 3:
        Object_TurnTowardSpike(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013DF54(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            if (M2C_FIELD(o, u8 *, 0x7F) == 1) {
                M2C_FIELD(o, u8 *, 0x7F) = 4;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 4)[0];
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = st;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 3)[0];
                M2C_FIELD(o, u8 *, 0x8F) = 0;
            }
        }
        break;
    case 4:
        if (func_80141110(o) == 0) {
            if (M2C_FIELD(o, u16 *, 0x5C) == ANIM_8013DF54(o, M2C_FIELD(o, u8 *, 0x7F))[0] + 20) {
                func_80140FD4(o);
            }
            if (M2C_FIELD(o, u8 *, 0x8F) >= 3) {
                M2C_FIELD(o, u8 *, 0x80) = 6;
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 0)[0];
                func_80140E88(o);
            }
        }
        break;
    case 6:
        Object_DisableCollision(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013DF54(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 1)[0];
            func_80140E88(o);
            Object_Timer(o, 60);
        }
        break;
    }
    func_80140EB4(o);
}

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

s32 Object_FlyAboveFloor(void *, s32);

void func_801414D4(void *arg0) {
    Object_FlyAboveFloor(arg0, 0x14);
}

M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin_801414F4(s16) asm("rsin");

void func_801414F4(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin_801414F4(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_801414D4(arg0);
}

void Object_StepGrowShrink_801415B8(void *, s32, s32, s32) asm("Object_StepGrowShrink");
M2C_UNK Object_PlaySound_801415B8(void *, M2C_UNK) asm("Object_PlaySound");
void func_801413F8(void *arg0);
void Object_ApplyVelocity(void *);
s32 Object_AddAttackSphereNear_801415B8(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");

void func_801415B8(u8 *arg0) {
    s16 *v;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound_801415B8(arg0, 0x5F);
        func_801413F8(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink_801415B8(arg0, 0x53, 0x37, 0);
    }
    if (Object_StepToward3D(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), M2C_FIELD(arg0, s16 *, 0xA8) >> 3) != 0) {
        func_801413F8(arg0);
        return;
    }
    v = (s16 *)(arg0 + 0x60);
    v[0] = M2C_FIELD(arg0, s16 *, 0x94);
    v[1] = M2C_FIELD(arg0, s16 *, 0x96);
    v[2] = M2C_FIELD(arg0, s16 *, 0x98);
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity(arg0);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear_801415B8(arg0, M2C_FIELD(arg0, s16 *, 0x44) + 0x32, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28) - 0x1E, M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x103);
}

s32 func_801416DC(void *arg0) {
    u8 old;

    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
        old = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0xCE) = old;
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
        return 1;
    }
    return 0;
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_80141760 asm("g_Spike");
void Object_InitOrbit(void *, s32);
void Object_OrbitHome(void *, s16);
s32 Object_SpikeInFront(void *, s32, s32, s32);
void ObjKind4D_IdleSounds(void *);
void func_80141484(void *arg0);
void func_801414D4(void *arg0);
void func_801414F4(void *arg0);
void func_801415B8(u8 *arg0);
s32 func_801416DC(void *arg0);

void func_80141760(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 0x3C;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 0x64;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0xDC) = 1;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) -= 0xC8;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (func_801416DC(o) != 0) {
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_OrbitHome(o, 8);
        Object_SeekHeight(o, 8);
        func_801414D4(o);
        if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 0x168, -0x1000, 0x400) != 0) {
            func_80141484(o);
        }
        break;
    case 2:
        Object_TurnToward(o, g_Spike_80141760.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80141760.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2) - 10) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, s16 *, 0xA8) = 0;
            M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
            M2C_FIELD(o, u16 *, 0xBC) = g_Spike_80141760.x;
            M2C_FIELD(o, u16 *, 0xC0) = g_Spike_80141760.z;
            M2C_FIELD(o, u16 *, 0xBE) = g_Spike_80141760.y - 200;
            M2C_FIELD(o, u8 *, 0x8F) = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
            if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                Object_PlaySound_8013E11C(o, 0xA6);
            }
        }
        func_801415B8(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            func_801413F8(o);
        } else if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2) && M2C_FIELD(o, u8 *, 0x7F) == 2) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + 0x10);
        }
        break;
    case 4:
        func_801414F4(o);
        break;
    }
    ObjKind4D_IdleSounds(o);
}

extern struct S_g_Game_80141A54 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x4]; u8 *f_8214; u8 pad_8218[0x8]; u8 *f_8220; } g_Game_80141A54 asm("g_Game");

s32 func_80141A54(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game_80141A54.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 0x16) >= p[5]) {
        p[1] = 2;
        e = g_Game_80141A54.f_8220 + p[7] * 0x18;
        M2C_FIELD(e, s16 *, 2) = 5;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x4C]; u16 f_8150; u8 pad_8152[0xCE]; u8 *f_8220; } g_Game_80141AD0 asm("g_Game");
void CamFlyby_StartSegment(s32);
s32 Sound_PlayFixed_80141AD0(s32) asm("Sound_PlayFixed");

s32 func_80141AD0(s16 *p) {
    u8 *t;

    if (p[4] < 0) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        t = g_Game_80141AD0.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 0x16) >= p[5] && g_Game_80141AD0.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_80141AD0.f_8150 == 0) {
            t = g_Game_80141AD0.f_8220 + p[7] * 0x18;
            M2C_FIELD(t, s16 *, 2) = 5;
            CamFlyby_StartSegment(p[6] - 1);
            g_Game_80141AD0.f_8100 = 7;
            p[1] = 2;
            Sound_PlayFixed_80141AD0(0x80);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_80141BE4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141BE4 asm("g_Game");

s32 func_80141BE4(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game_80141BE4.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 1;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_80141C38 asm("g_Game");
void CamFlyby_StartSegment(s32);
s32 Sound_Play_80141C38(s32, s32) asm("Sound_Play");
s32 Sound_PlayFixed_80141C38(s32) asm("Sound_PlayFixed");
s32 Sound_Stop_80141C38(s32, s32) asm("Sound_Stop");

s32 func_80141C38(s16 *p) {
    u8 *t;

    if (p[4] < 0) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        t = g_Game_80141C38.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 1) {
            p[1] = 1;
            CamFlyby_StartSegment(p[5] - 1);
            g_Game_80141C38.f_8100 = 3;
            p[3] = 0;
            p[11] = Sound_Play_80141C38(0, 0x7C);
            Sound_PlayFixed_80141C38(0x74);
        }
        break;
    case 1:
        if (++p[3] > 0x58) {
            Sound_Stop_80141C38(0x7C, p[11]);
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

void func_80052CEC(s32);

s32 func_80141D38(s16 *p) {
    u8 *e;
    s32 v;
    u8 *g0 = (u8 *)&g_Game_80141BE4;
    s32 k = 0x8000;
    u8 *g = g0 + k;

    if (p[1] == 0) {
        e = *(u8 **)(g + 0x220) + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            func_80052CEC(1);
            p[1] = v;
        }
    }
    return 0;
}

extern u8 *g_StageMeshes;

s32 func_80141DB8(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    e[0x12] = e[0];
    e[0x13] = e[1];
    e[0x14] = e[2];
    p[1] = 4;
    p[3] = 0;
    p[5] = 0;
    if ((s16)e[7] >= 0) {
        **(u32 **)(g_StageMeshes + (s16)e[7] * 32) |= 0x2000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; s32 f_820C; } g_Game_80141E44 asm("g_Game");
s32 Sound_PlayAt(s32, s32);

s32 func_80141E44(s16 *p) {
    s16 *e = (s16 *)(g_Game_80141E44.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 5:
        if (p[3] == 0) {
            Sound_PlayAt(0xAD, (s32)e);
        }
        p[3] += 0x20;
        if (e[4] < p[3]) {
            p[3] = e[4];
            p[1] = 1;
            p[5] = 0x2000;
            if (e[7] >= 0) {
                M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x16) = 0;
            }
        } else {
            e[1] -= 0x20;
            p[5] += 0x2000 / (e[4] / 32);
            if (p[5] > 0x2000) {
                p[5] = 0x2000;
            }
        }
        if (e[7] >= 0) {
            M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x18) = p[5];
        }
        break;
    case 1:
    case 4:
        break;
    case 2:
        if (p[3] == e[4]) {
            Sound_PlayAt(0xAD, (s32)e);
        }
        p[3] -= 0x20;
        if (p[3] < 0) {
            p[3] = 0;
            p[1] = 4;
            p[5] = 0;
        } else {
            e[1] += 0x20;
            p[5] -= 0x3000 / (e[4] / 32);
            if (p[5] < 0) {
                p[5] = 0;
            }
        }
        if (e[7] >= 0) {
            M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x18) = p[5];
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80142088 asm("g_Game");
extern u8 *D_800B4D64_80142088 asm("g_StageMeshes");

s32 func_80142088(s16 *p) {
    u8 *e = g_Game_80142088.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 4);
    if (p[10] == 4) {
        p[1] = 4;
        p[3] = 0;
        p[5] = 0;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            **(u32 **)(D_800B4D64_80142088 + M2C_FIELD(e, s16 *, 0xE) * 32) |= 0x2000;
        }
    } else {
        p[1] = 1;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80142088 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80142164 asm("g_Game");
extern u8 *D_800B4D64_80142164 asm("g_StageMeshes");
s32 Sound_PlayFixed_80142164(s32, void *) asm("Sound_PlayFixed");

s32 func_80142164(s16 *p) {
    u8 *e = g_Game_80142164.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 1:
        break;
    case 4:
        break;
    case 5:
        if (p[3] == 0) {
            Sound_PlayFixed_80142164(0xAD, e);
        }
        p[3] += 0x20;
        if (p[3] > M2C_FIELD(e, s16 *, 8)) {
            p[3] = M2C_FIELD(e, s16 *, 8);
            p[1] = 1;
            p[5] = 0x2000;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_80142164 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        } else {
            M2C_FIELD(e, s16 *, 2) -= 0x20;
            p[5] += 0x2000 / (M2C_FIELD(e, s16 *, 8) / 32);
            if (p[5] > 0x2000) {
                p[5] = 0x2000;
            }
        }
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80142164 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x18) = p[5];
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801422FC asm("g_Game");
extern u8 *D_800B4D64_801422FC asm("g_StageMeshes");

s32 func_801422FC(s16 *p) {
    u8 *e = g_Game_801422FC.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 4);
    if (p[5] == 0) {
        p[1] = 0;
        p[3] = 0;
        p[4] = 0;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            **(u32 **)(D_800B4D64_801422FC + M2C_FIELD(e, s16 *, 0xE) * 32) |= 0x2000;
        }
        p[7] = M2C_FIELD(e, s16 *, 6) * 2;
        p[8] = M2C_FIELD(e, u16 *, 0xA) + 0x200;
    } else {
        p[1] = 6;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_801422FC + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

extern s32 D_800EC20C;
s32 func_801426D4(u8 *a, s16 *b);

s32 func_801423F8(s16 *p) {
    s16 *e = (s16 *)(g_Game_80141E44.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (func_801426D4((u8 *)e, &p[7])) {
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
    case 5:
        if (p[3] == 0) {
            Sound_PlayAt(0xAD, (s32)e);
        }
        p[3] += 0x40;
        if (e[4] < p[3]) {
            p[3] = e[4];
            p[4] = 0x2000;
            if (p[1] == 5) {
                p[1] = 6;
            } else {
                p[1] = 2;
            }
            if (e[7] >= 0) {
                M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x16) = 0;
            }
        } else {
            e[1] -= 0x40;
            p[4] += 0x2000 / (e[4] / 64);
            if (p[4] > 0x2000) {
                p[4] = 0x2000;
            }
        }
        if (e[7] >= 0) {
            M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x18) = p[4];
        }
        break;
    case 2:
        if (!func_801426D4((u8 *)e, &p[7])) {
            if (e[7] >= 0) {
                M2C_FIELD(g_StageMeshes + e[7] * 32, u16 *, 0x16) = 0xFFFF;
            }
            p[1] = 3;
        }
        break;
    case 3:
        if (p[3] == e[4]) {
            Sound_PlayAt(0xAD, (s32)e);
        }
        p[3] -= 0x40;
        if (p[3] < 0) {
            p[3] = 0;
            if (e[2] < D_800EC20C) {
                p[1] = 4;
            } else {
                p[1] = 0;
            }
        } else {
            e[1] += 0x40;
            p[4] -= 0x2000 / (e[4] / 64);
            if (p[4] < 0) {
                p[4] = 0;
            }
        }
        if (e[7] >= 0) {
            M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x18) = p[4];
        }
        break;
    case 4:
    case 6:
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

extern s32 D_800EC204;
extern s32 D_800EC208;
extern s32 D_800EC20C;

s32 func_801426D4(u8 *a, s16 *b) {
    if (ABS(D_800EC20C - M2C_FIELD(a, s16 *, 0x28)) < b[1]) {
        if (ABS(D_800EC204 - M2C_FIELD(a, s16 *, 0x24)) < b[0]) {
            if (D_800EC208 < M2C_FIELD(a, s16 *, 0x26) + M2C_FIELD(a, s16 *, 8) &&
                M2C_FIELD(a, s16 *, 0x26) - M2C_FIELD(a, s16 *, 8) < D_800EC208) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_8014277C(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

s32 func_801427C4(s16 *p) {
    switch (p[1]) {
    case 0:
        break;
    case 1:
        if (++p[3] > p[5]) {
            p[1] = 0;
            p[3] = 0;
        }
        break;
    }
    return 0;
}

typedef struct { s16 f[28]; } E_80142810;
extern struct { u8 pad_0[0x820C]; s16 *f_820C; } g_Game_80142810 asm("g_Game");

s32 func_80142810(s16 *p) {
    E_80142810 *e = (E_80142810 *)((u8 *)g_Game_80142810.f_820C + p[2] * 0x38);
    SVECTOR v;
    s32 step;
    s32 i;

    step = -0x900 - e->f[1];
    if (step > 0x6E8) {
        step = 0x6E8;
    }
    for (i = 0; i < 20; i++) {
        v.vx = e->f[0] + ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * e->f[3] / 255 - e->f[3] / 2;
        v.vy = -0x920 - (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) - i * step / 20;
        v.vz = e->f[2] + ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * e->f[5] / 255 - e->f[5] / 2;
        Effect_SpawnAt(5, &v);
    }
    return 0;
}
