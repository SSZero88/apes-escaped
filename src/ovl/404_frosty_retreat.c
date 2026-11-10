#include "common.h"
#include "m2c_macros.h"

void Object_PlaySound(void *, s32);

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK Object_KeepAwayFromSpike(s32, M2C_UNK);
M2C_UNK Object_ApplyHit();
M2C_UNK Object_HitFeedback(void *);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
M2C_UNK Object_FlyAboveFloor(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013D000 asm("g_Spike");
s32 Vec_Length(s32, s32, s32);

void func_8013D000(void *arg0) {
    s32 v;

    M2C_FIELD(arg0, s16 *, 0x96) = -(M2C_FIELD(arg0, s16 *, 0xA8) + 7) * 0xB;
    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        v = Vec_Length(g_Spike_8013D000.x - M2C_FIELD(arg0, s32 *, 0x24), 0,
                       g_Spike_8013D000.z - M2C_FIELD(arg0, s32 *, 0x2C)) / 22;
    } else {
        v = 0x11;
    }
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    M2C_FIELD(arg0, u8 *, 0xDD) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) | 0x400) & ~0x20;
    M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * v) >> 12;
    M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * v) >> 12;
    Object_PlaySound(arg0, 0x68);
}

s32 Object_AddAttackSphereNear_8013D0EC(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");

void func_8013D0EC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear_8013D0EC(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void Shockwave_Spawn(SVECTOR *, void *, s32, s32, s32);
extern u8 D_80141850[];

void func_8013D144(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        Shockwave_Spawn(&v, D_80141850, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013D1E0(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 func_8013D210(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013D240(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013D27C(void *arg0) {
    if ((func_8013D210(arg0) == 0) && (func_8013D240(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 func_8013D210(void *arg0);
s32 func_8013D240(void *arg0);
void func_8013D27C(void *arg0);
void func_8013D0EC(void *arg0);
void Object_TurnTowardSpike_8013D2D0(void *) asm("Object_TurnTowardSpike");
void Object_TurnToward_8013D2D0(void *, s16, s16, s32, s32) asm("Object_TurnToward");
s32 func_800572CC_8013D2D0(void *) asm("Object_UpdateLeap");
s32 Object_DetachLink_8013D2D0(void *, s32) asm("Object_DetachLink");

void func_8013D2D0(void *arg0) {
    if (func_8013D1E0(arg0)) {
        if (func_8013D210(arg0)) {
            Object_TurnTowardSpike_8013D2D0(arg0);
            M2C_FIELD(arg0, s16 *, 0xA8) = 1;
        } else {
            Object_TurnToward_8013D2D0(arg0, M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24),
                                       M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C), 0,
                                       M2C_FIELD(arg0, s16 *, 0xB0));
            M2C_FIELD(arg0, s16 *, 0xA8) = 0;
            if (func_8013D240(arg0)) {
                M2C_FIELD(arg0, u8 *, 0x80) = 5;
                M2C_FIELD(arg0, u8 *, 0x7F) = 4;
                M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + 0x10);
            }
        }
        if (M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 8) {
            func_8013D000(arg0);
        }
    } else {
        M2C_FIELD(arg0, u16 *, 0x96) += M2C_FIELD(arg0, u16 *, 0xA8);
        func_8013D27C(arg0);
        if (M2C_FIELD(arg0, u8 *, 0xDD) == 0 && func_800572CC_8013D2D0(arg0)) {
            M2C_FIELD(arg0, u8 *, 0xDD) = 1;
        }
    }
    if (Object_DetachLink_8013D2D0(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        Object_Timer(arg0, 0x1E);
    } else {
        func_8013D0EC(arg0);
    }
}

void func_8013D430(s32 arg0) {
    if (func_8013D1E0() != 0) {
        Object_KeepAwayFromSpike(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013D474(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013D4B4(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        Object_ApplyHit();
        Object_HitFeedback(arg0);
    }
}

typedef struct { u16 f0; u16 f2; } Anim_8013D51C;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0x4]; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1F]; u8 f_7D; u8 pad7E[0x1]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[0x6]; Anim_8013D51C *anim; u8 pad8C[0xE]; s16 f_9A; u8 pad9C[0x2]; s16 f_9E; s16 f_A0; u8 padA2[0x2]; s16 f_A4; u8 padA6[0x2]; s16 f_A8; u8 padAA[0x6]; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 padC9[0x13]; u8 f_DC; u8 f_DD; u8 padDE[0x2]; u32 f_E0; } Obj_8013D51C;
extern u16 g_RandSeed;
void func_80058134_8013D51C(void *, s32) asm("Object_DebugStub");
void func_8013D144(void *arg0);
void func_8013D2D0(void *arg0);
void func_8013D430(s32 arg0);
void func_8013D474(void *arg0);
void func_8013D4B4(void *arg0);

void func_8013D51C(Obj_8013D51C *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        o->f_B0 = 0x5B;
        o->f_A0 = 100;
        o->f_44 = 100;
        o->f_4A = -0x4000;
        o->f_81 = 12;
        o->f_7D = 7;
        o->f_C8 = 6;
        o->f_DC = 1;
        o->f_DD = 1;
        o->f_7F = 0;
        o->f_A8 = 0;
        o->f_E0 &= ~0x1000;
        o->f_5C = o->anim[0].f0;
        Object_Timer(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        o->f_E0 |= 8;
    }
    func_8013D474(o);
    func_80058134_8013D51C(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 3;
    }
    switch (o->f_80) {
    case 1:
        if (Spike_WithinRadiusXZ(o->f_9A, o->f_9E, o->f_A4)) {
            o->f_80 = 2;
            o->f_7F = 2;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        if (Object_Timer(o, -1) == 0 && o->f_5C >= o->anim[o->f_7F].f2) {
            if (o->f_7F == 0) {
                o->f_7F = 1;
                o->f_5C = o->anim[o->f_7F].f0;
            } else {
                o->f_7F = 0;
                o->f_5C = o->anim[o->f_7F].f0;
                Object_Timer(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 10);
            }
        }
        break;
    case 2:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 3;
            o->f_7F = 3;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        break;
    case 3:
        func_8013D2D0(o);
        break;
    case 4:
        func_8013D430((s32)o);
        if (Object_Timer(o, -1) == 0) {
            o->f_80 = 3;
        }
        break;
    case 5:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 1;
            o->f_7F = 0;
            o->f_5C = o->anim[o->f_7F].f0;
            Object_Timer(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        }
        break;
    }
    func_8013D144(o);
    func_8013D4B4(o);
}

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_404;
s32 Hook_Add(void *);
void func_8013DB40(void);
extern Mdl_404 D_80141950_s[] asm("D_80141950");

void func_8013D804(void) {
    s32 i;
    Mdl_404 *m;

    if (Hook_Add(func_8013DB40) == 1) {
        for (i = 0; i < 16; i++) {
            m = &D_80141950_s[i];
            Object_SetModel(m, 0x40);
            Object_GetAnimTable(m, 0x40);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f82; u8 life; s16 scale; s16 floor; } Debris_8013D89C;
extern Debris_8013D89C D_80141950_8013D89C[] asm("D_80141950");
extern u16 g_RandSeed2;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x9B]; u8 fCB; } Obj_8013D89C;

void func_8013D89C(Obj_8013D89C *o) {
    s32 i;
    Debris_8013D89C *d;
    s32 sc;

    for (i = 0; i < 16; i++) {
        d = &D_80141950_8013D89C[i];
        d->x = o->x + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->y = o->y - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8);
        d->z = o->z + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 3;
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 3;
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 3 - 0x20;
        d->wx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) << 4) & 0x3000) / 360;
        d->wy = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) << 4) & 0x3000) / 360;
        d->wz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) << 4) & 0x3000) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 30;
        d->f82 = M2C_FIELD(o, u8 *, 0xCB);
        d->floor = (u16)o->y - 50;
        sc = 0x1000 / (i % 3 + 4);
        d->scale = sc;
    }
}

typedef struct { s16 x, y, z; } Rot_404;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_404 r; u8 pad82; u8 life; s16 scale; s16 floor; } Debris_404;
extern Debris_404 D_80141950[16];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;
extern u8 D_800E7D00_8013DB40[] asm("g_ProjVerts");
s32 Object_IsOffScreen(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void ScaleMatrix_8013DB40(void *, void *) asm("ScaleMatrix");
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void Model_DrawAuto(void *, void *, void *);

void func_8013DB40(void) {
    s32 i;
    Debris_404 *d;
    s32 s[3];
    SVECTOR v;

    for (i = 0; i < 16; i++) {
        d = &D_80141950[i];
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
                ScaleMatrix_8013DB40(d->mat, s);
                Model_CalcKeyedJointMatrices(d, 3);
                Model_ProjectBonedVerts(d);
                Model_DrawAuto(g_Game.f_80 + g_Game.f_C * 0x4078, D_800E7D00_8013DB40, d);
            }
        }
    }
}

extern struct { u8 pad0; u8 f_1; } D_800E77A0_8013DD40 asm("D_800E77A0");
void func_80058134_8013DD40(void *, s32) asm("Object_DebugStub");
void func_800585D0_8013DD40(void *, s32, s32, s32) asm("Object_FollowPath");
void Object_PlaceAtPathPoint_8013DD40(void *, s32) asm("Object_PlaceAtPathPoint");
void func_8005866C_8013DD40(void *, s32) asm("Object_FacePathPoint");
s16 Object_PathPointNear_8013DD40(void *, void *, s16, u8) asm("Object_PathPointNear");
void Object_ApplyVelocity_8013DD40(void *) asm("Object_ApplyVelocity");
s32 Object_AddAttackSphereNear_8013DD40(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
void func_80051E98_8013DD40(void *, s32) asm("Object_Despawn");
void func_8013D804(void);

void func_8013DD40(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0xA0) = 0x190;
        M2C_FIELD(o, s16 *, 0x44) = 1;
        M2C_FIELD(o, s16 *, 0x46) = 0x320;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, u8 *, 0x8E) = 1;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, u8 *, 0x8F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, s16 *, 0xAA) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        Object_PlaceAtPathPoint_8013DD40(o, 0);
        func_8005866C_8013DD40(o, 2);
        func_8013D804();
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013DD40(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(o, u8 *, 0x8E) == 2) {
            M2C_FIELD(o, s8 *, 0x7C) = Sound_ReserveSlot(0x707C, 0x1000, o + 0x24);
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x8F) = 0x11;
        }
    case 2:
        if (M2C_FIELD(o, u8 *, 0x8F) != 0) {
            M2C_FIELD(o, u8 *, 0x8F)--;
        }
        func_800585D0_8013DD40(o, M2C_FIELD(o, u8 *, 0x8E) == 1 ? 0x6E : 0x28, 0, 1);
        if (Object_PathPointNear_8013DD40(o, o + 0x24, 0x64, M2C_FIELD(o, u8 *, 0x8C) - 1)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            break;
        }
        Object_ApplyVelocity_8013DD40(o);
        Object_AddAttackSphereNear_8013DD40(o, 0x190, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, u16 *, 0x28) - 0x190, M2C_FIELD(o, s16 *, 0x2C), 0xA01, 0x200);
        M2C_FIELD(o, s16 *, 0xAE) = 0;
        break;
    case 3:
        func_8013D89C(o);
        Sound_FreeSlot(M2C_FIELD(o, s8 *, 0x7C));
        Object_PlaySound(o, 0xBD);
        D_800E77A0_8013DD40.f_1--;
        func_80051E98_8013DD40(o, 0);
        break;
    }
}

void func_8013DF78(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80142270[];

void func_8013E018(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80142270 + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game.f_80 + g_Game.f_C * 0x4078, &g_ProjVerts, m);
    }
}

typedef struct { u8 pad0[0xC]; s16 active; u8 padE[6]; } Drip_404;
extern Drip_404 D_801421D0_s[8] asm("D_801421D0");

void func_8013E0E0(void *arg0) {
    s32 i;

    func_8013DF78(arg0, D_80142270, 0x83);
    for (i = 7; i >= 0; i--) {
        D_801421D0_s[i].active = 0;
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801421D0");

s32 func_8013E128(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013E164;
extern Drip_8013E164 D_801421D0_8013E164[8] asm("D_801421D0");
s32 func_8013E128(void);

M2C_UNK func_8013E164(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 i;
    Drip_8013E164 *p;
    s16 c;
    s16 s;

    i = func_8013E128();
    if (i != -1) {
        p = &D_801421D0_8013E164[i];
        c = rcos(M2C_FIELD(arg0, s16 *, 0xAC));
        s = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
        p->x = M2C_FIELD(arg0, s16 *, 0x24) + ((c * (s16)arg2) >> 12);
        p->y = M2C_FIELD(arg0, s16 *, 0x28) - arg1;
        p->z = M2C_FIELD(arg0, s16 *, 0x2C) + ((s * (s16)arg2) >> 12);
        p->vx = c / 48;
        p->vz = s / 48;
        p->vy = -40;
        p->active++;
        p->unkE = M2C_FIELD(arg0, s8 *, 0xCB);
        Object_PlaySound(arg0, 0x77);
    }
}

s32 func_8013E2A4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013E2E0(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013E320(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013E360;
extern Drip_8013E360 D_801421D0_8013E360[8] asm("D_801421D0");
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013E360;
extern M_8013E360 D_80142270_8013E360 asm("D_80142270");
s32 Object_DetachLink_8013E360(void *, s32) asm("Object_DetachLink");
s32 Object_AddAttackSphere_8013E360(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void VectorNormalSS(void* v0, void* v1);
void func_8013E018(s32 arg0, s32 arg1);
s32 func_8013E2A4(void *arg0);
void func_8013E2E0(SVECTOR *arg0);
void func_8013E320(SVECTOR *arg0);

void func_8013E360(void *arg0) {
    Drip_8013E360 *p;
    M_8013E360 *m;
    s32 i;
    s32 r;

    m = &D_80142270_8013E360;
    for (i = 7; i >= 0; i--) {
        p = &D_801421D0_8013E360[i];
        if (p->active != 0 && p->unkE == M2C_FIELD(arg0, s8 *, 0xCB)) {
            p->active++;
            p->vy += 4;
            func_8013E2E0((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            r = Object_DetachLink_8013E360(arg0, 0);
            if (func_8013E2A4(p) || M2C_FIELD(arg0, s32 *, 0x28) + 0x600 < p->y || r == 6) {
                p->active = 0;
                func_8013E320((SVECTOR *)p);
                Object_PlaySound(arg0, 0x4D);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->vx = p->vx;
                m->vy = p->vy;
                m->vz = p->vz;
                VectorNormalSS(&m->vx, &m->vx);
                func_8013E018(0, 3);
                M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere_8013E360(arg0, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013E528(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void Object_SpawnHitSpark(void *, s32, s32, s32);

void func_8013E554(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_SpawnHitSpark(arg0, 0, 0, 0);
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013E5E4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013E528(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}


void func_8013E674(void *obj) {
    func_8013E164(obj, 0x46, 0xA0);
}

void Object_DisableCollision(void *);

void func_8013E698(void *arg0) {
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
    Object_Timer(arg0, (s16)(M2C_FIELD(arg0, s16 *, 0x9A) % 60) + 0x3C);
    func_8013E0E0(arg0);
    Object_DisableCollision(arg0);
}

typedef struct { u16 start; u16 end; } Anim_8013E778;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0xA]; u32 f_50; u8 pad54[0x8]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[0x7]; Anim_8013E778 *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[0x3E]; u32 f_E0; } O_8013E778;
void func_8013E360(void *arg0);
void func_8013E528(void *arg0);
void func_8013E554(void *arg0);
void func_8013E5E4(void *arg0);
void func_8013E674(void *obj);
void func_8013E698(void *arg0);
M2C_UNK Object_StepOnGroundFixed_8013E778(void *) asm("Object_StepOnGroundFixed");
void Object_TurnTowardSpike_8013E778(void *) asm("Object_TurnTowardSpike");
void func_80058134_8013E778(void *, s32) asm("Object_DebugStub");
void func_80055C7C_8013E778(void *, s32) asm("Object_FleeSpike");
void func_80055D28_8013E778(void *, s32, s32) asm("Object_SetRandomHeading");
void Object_EnableCollision_8013E778(void *) asm("Object_EnableCollision");
s32 Object_SpikeInFront_8013E778(void *, s32, s32, s32) asm("Object_SpikeInFront");
s32 Object_SpikeNearXZ_8013E778(void *, s32) asm("Object_SpikeNearXZ");

void func_8013E778(O_8013E778 *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        func_8013E698(o);
        o->f_E0 |= 8;
    }
    func_80058134_8013E778(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 6;
        o->f_7F = 0;
        o->f_5C = o->f_88[0].start;
        func_8013E528(o);
    }
    switch (o->f_80) {
    case 1:
        o->f_5C = o->f_88[o->f_7F].start;
        func_80055C7C_8013E778(o, 0x3C);
        Object_StepOnGroundFixed_8013E778(o);
        if (Object_Timer(o, -1) == 0) {
            func_8013E5E4(o);
            Object_EnableCollision_8013E778(o);
        }
        break;
    case 3:
        o->f_A0 += 5;
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 2;
            o->f_7F = 2;
            o->f_5C = o->f_88[2].start;
        }
        break;
    case 2:
        if (Object_SpikeInFront_8013E778(o, 0x168, -0x1000, 0x800)) {
            o->f_80 = 7;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
            Object_PlaySound(o, 0x61);
            break;
        }
        if (Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x300)) {
            o->f_80 = 8;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 8:
        Object_TurnTowardSpike_8013E778(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
            func_8013E528(o);
        }
        break;
    case 7:
        Object_TurnTowardSpike_8013E778(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 4;
            o->f_7F = 3;
            o->f_5C = o->f_88[3].start;
        }
        break;
    case 4:
        Object_TurnTowardSpike_8013E778(o);
        if ((o->f_50 >> 28) == 6 || !Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x800) || Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x300)) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
            func_8013E528(o);
            break;
        }
        if (o->f_5C == o->f_88[o->f_7F].start + 0x14) {
            func_8013E674(o);
        }
        break;
    case 5:
        if (Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x300) || !Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x800) || !Object_SpikeNearXZ_8013E778(o, 0x600)) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            if (Object_SpikeInFront_8013E778(o, 0xB4, 0, 0x800)) {
                o->f_80 = 4;
                o->f_7F = 3;
                o->f_5C = o->f_88[3].start;
                Object_TurnTowardSpike_8013E778(o);
            } else {
                o->f_80 = 6;
                o->f_7F = 0;
                o->f_5C = o->f_88[0].start;
                func_8013E528(o);
            }
        }
        break;
    case 6:
        if (o->f_A0 != 0) {
            o->f_A0 -= 5;
        }
        Object_DisableCollision(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_A0 = 0;
            Object_Timer(o, 0x2D);
            o->f_80 = 1;
            o->f_7F = 1;
            o->f_5C = o->f_88[1].start;
            func_80055D28_8013E778(o, 0x3C, 0);
            func_8013E528(o);
        }
        break;
    }
    func_8013E554(o);
    func_8013E360(o);
}

void func_8013EC60(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013ECA0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013ECE4(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

void func_80058134_8013ED60(void *, s32) asm("Object_DebugStub");
void func_80052038_8013ED60(void *, s32) asm("Object_SetModel");
void Object_DisableCollision_8013ED60(void *) asm("Object_DisableCollision");
void Object_EnableCollision_8013ED60(void *) asm("Object_EnableCollision");
void Object_PlaySound_8013ED60(void *, s32) asm("Object_PlaySound");
void func_8013EC60(void *arg0);
void func_8013ECA0(void *arg0);
void func_8013ECE4(void *arg0);

void func_8013ED60(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 0xFA;
        M2C_FIELD(o, s16 *, 0x46) = 0x200;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision_8013ED60(o);
        func_80052038_8013ED60(o, 0x84);
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        M2C_FIELD(o, u8 *, 0x80) = 2;
        M2C_FIELD(o, u8 *, 0x7F) = 1;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        Object_EnableCollision_8013ED60(o);
        func_80052038_8013ED60(o, 0x84);
        Object_PlaySound_8013ED60(o, 0x5C);
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    func_80058134_8013ED60(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, s16 *, 0xC2) = 0x12C;
            func_8013EC60(o);
            func_8013ECE4(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8013ECA0(o);
            Object_PlaySound_8013ED60(o, 0x5E);
        }
        break;
    case 4:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80052038_8013ED60(o, 0x19);
            Object_DisableCollision_8013ED60(o);
        }
        break;
    }
}

typedef struct { u16 start; u16 end; } Rng_8013EF7C;
typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 20; u32 mode : 2; u32 b26 : 6; } Flags_8013EF7C;
void Object_SetAnim_8013EF7C(void *, s32, s32) asm("Object_SetAnim");
void func_80058134_8013EF7C(void *, s32) asm("Object_DebugStub");
void func_8005866C_8013EF7C(void *, s32) asm("Object_FacePathPoint");

void func_8013EF7C(u8 *o) {
    if (!M2C_FIELD(o, Flags_8013EF7C *, 0xE0).init) {
        M2C_FIELD(o, s16 *, 0x44) = 0x118;
        M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, Flags_8013EF7C *, 0xE0).mode = 1;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013EF7C **, 0x88)[0].start;
        if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
            func_8005866C_8013EF7C(o, 1);
        }
        M2C_FIELD(o, Flags_8013EF7C *, 0xE0).init = 1;
    }
    func_80058134_8013EF7C(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        Object_SetAnim_8013EF7C(o, 2, 1);
        M2C_FIELD(o, u8 *, 0xC9) = 0x32;
    }
    if (M2C_FIELD(o, u8 *, 0xC9) != 0) {
        if (--M2C_FIELD(o, u8 *, 0xC9) == 0) {
            Object_SetAnim_8013EF7C(o, 2, 3);
        }
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    if (M2C_FIELD(o, u8 *, 0x80) == 2 && M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013EF7C **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
        M2C_FIELD(o, u8 *, 0x80) = 1;
        if (M2C_FIELD(o, u8 *, 0x7F) == 3) {
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013EF7C **, 0x88)[0].start;
        } else {
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013EF7C **, 0x88)[2].start;
        }
    }
}

s32 Math_Atan2(s32, s32);

void func_8013F0EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013F178(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_8013F1B0(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    Object_FlyAboveFloor(arg0, 0x14);
}

s32 Object_AddAttackSphereNear_8013F278(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
s32 Object_DetachLink_8013F278(void *, s32) asm("Object_DetachLink");
void Object_PlaySound_8013F278(void *, s32) asm("Object_PlaySound");
void Object_ApplyVelocity_8013F278(void *) asm("Object_ApplyVelocity");
s32 func_80055718_8013F278(void *, s16, s16, s16, s32) asm("Object_StepToward3D");
s32 Object_StepGrowShrink_8013F278(void *, s16, s16, s16) asm("Object_StepGrowShrink");
void func_8013F0EC(void *arg0);

void func_8013F278(u8 *a) {
    s16 *v;

    if (Object_DetachLink_8013F278(a, 0) == 6) {
        Object_PlaySound_8013F278(a, 0x5F);
        func_8013F0EC(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink_8013F278(a, 0x53, 0x37, 0);
    }
    if (func_80055718_8013F278(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        func_8013F0EC(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity_8013F278(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear_8013F278(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F39C asm("g_Spike");

void func_8013F39C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F39C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F39C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F39C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void func_8013F3EC(void *arg0) {
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

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013F460 asm("g_Spike");
void Object_InitOrbit(void *, s32);
void func_80058134_8013F460(void *, s32) asm("Object_DebugStub");
void func_8013F3EC(void *arg0);
void Object_OrbitHome(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
void Object_TurnToward_8013F460(void *, s16, s16, s32, s32) asm("Object_TurnToward");
void func_8013F39C(void *arg0);
void func_8013F278(u8 *a);
void func_8013F1B0(void *arg0);
void func_8013F178(void *arg0);
void ObjKind4D_IdleSounds(void *);
#define ANIM_8013F460(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_8013F460(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 50;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 60;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 100;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0x81) = 6;
        M2C_FIELD(o, u8 *, 0xDC) = 8;
        M2C_FIELD(o, s16 *, 0x9C) -= 200;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x200000;
        M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F460(o, 0)[0];
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013F460(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0xC00000;
        func_8013F3EC(o);
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_OrbitHome(o, 8);
        Object_SeekHeight(o, 8);
        Object_FlyAboveFloor(o, 20);
        if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
            func_8013F178(o);
        }
        break;
    case 2:
        Object_TurnToward_8013F460(o, g_Spike_8013F460.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013F460.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F460(o, M2C_FIELD(o, u8 *, 0x7F))[1] - 10) {
            func_8013F39C(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
            if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                Object_PlaySound(o, 0xA6);
            }
        }
        func_8013F278(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            func_8013F0EC(o);
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F460(o, M2C_FIELD(o, u8 *, 0x7F))[1] && M2C_FIELD(o, u8 *, 0x7F) != 4) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F460(o, 4)[0];
        }
        break;
    case 4:
        func_8013F1B0(o);
        break;
    case 5:
        Object_TurnToward_8013F460(o, g_Spike_8013F460.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013F460.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F460(o, M2C_FIELD(o, u8 *, 0x7F))[1] && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            if (Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
                func_8013F178(o);
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, u8 *, 0xC9) = 0;
            }
        }
        break;
    }
    ObjKind4D_IdleSounds(o);
}

extern struct { u32 f_0; } g_Game_8013F7F8 asm("g_Game");
extern u16 g_RandSeed;
void func_80052038_8013F7F8(void *, s32) asm("Object_SetModel");
void Puff_Spawn(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ_8013F7F8(s32, s32, s32) asm("Spike_WithinRadiusXZ");

void func_8013F7F8(u8 *o, s32 a) {
    if (a) {
        func_80052038_8013F7F8(o, 0x12);
    } else {
        func_80052038_8013F7F8(o, 0xA7);
    }
    Puff_Spawn(o + 0x24, 1, 0, 200);
    if (Spike_WithinRadiusXZ_8013F7F8(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x600)) {
        if (g_Game_8013F7F8.f_0 % 5 == 0 || (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) == 0) {
            Object_PlaySound(o, 0x5B);
        }
    }
}

extern s32 D_800EC208;
extern s32 D_801422E0;
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013F8BC(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA6)) == 0) {
        var_v0 = D_800EC208 >= D_801422E0;
    }
    return var_v0;
}

extern s32 D_800EC204;
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F91C asm("g_Spike");

s32 func_8013F91C(u8 *o, s32 r) {
    s32 ret = 0;

    if (ABS(D_800EC204 - M2C_FIELD(o, s32 *, 0x24)) < r
        && ABS(g_Spike_8013F91C.y - M2C_FIELD(o, s32 *, 0x28) + 0xD7) < r
        && ABS(g_Spike_8013F91C.z - M2C_FIELD(o, s32 *, 0x2C)) < r) {
        ret = 1;
    }
    return ret;
}

extern u16 g_RandSeed;

void func_8013F9D4(void *arg0) {
    u16 temp_a1;

    M2C_FIELD(arg0, s8 *, 0x80) = 1;
    temp_a1 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_a1;
    Object_Timer(arg0, ((u32) (temp_a1 & 0xFFFF) >> 9) + 0x40);
}

void func_8013FA20(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x10000);
}

s32 func_8013FA40(s32 x) {
    if (x == 0) {
        return 0;
    }
    if (x > 0) {
        return 1;
    }
    return -1;
}

void func_8013FA60(s16 *p, s32 lim) {
    if (*p > 0) {
        *p -= 5;
        if (*p > lim) {
            *p = lim;
        }
    } else if (*p < 0) {
        *p += 5;
        if (*p < -lim) {
            *p = -lim;
        }
    }
}

void func_8013FAB8(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0xBC)) * 0xA));
    M2C_FIELD(arg0, u16 *, 0xD6) = (u16) (M2C_FIELD(arg0, u16 *, 0xD6) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0xC0)) * 0xA));
    func_8013FA60(arg0 + 0xD4, 0x17C);
    func_8013FA60(arg0 + 0xD6, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x2C);
}

M2C_UNK Object_ApplyVelocity(void *);
s32 Object_WouldLeaveHome(void *, M2C_UNK);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013FB54(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x1E, 0x14, 0);
    }
    Object_StepToward3D(arg0, arg1, arg2, arg3, (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13);
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

void func_8013FC04(void *arg0) {
    if (Object_StepToward3D(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9C), M2C_FIELD(arg0, s16 *, 0x9E), 0xA) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
u32 Object_DetachLink(void *, s32);

void func_8013FC4C(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        if (Object_DetachLink(arg0, 0) == 6) {
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xD7), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x202);
    }
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_8013FCE0;
typedef struct { u16 start; u16 end; } Rng_8013FCE0;
typedef struct { u8 pad0[0x5C]; u16 frame; } Obj_8013FCE0;
void func_8013F7F8(u8 *o, s32 a);
s32 func_8013F8BC(void *arg0);
s32 func_8013F91C(u8 *o, s32 r);
void func_8013F9D4(void *arg0);
void func_8013FA20(void *arg0);
void func_8013FAB8(void *arg0);
void func_8013FB54_8013FCE0(void *, s32, s32, s32) asm("func_8013FB54");
void func_8013FC04(void *arg0);
void func_8013FC4C(void *arg0);

void func_8013FCE0(u8 *o) {
    if (!M2C_FIELD(o, Flags_8013FCE0 *, 0xE0).init) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        D_801422E0 = -0x764;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, Flags_8013FCE0 *, 0xE0).mode = 1;
        ((Obj_8013FCE0 *)o)->frame = M2C_FIELD(o, Rng_8013FCE0 **, 0x88)[0].start;
        ((Obj_8013FCE0 *)o)->frame = (s32)(M2C_FIELD(o, Rng_8013FCE0 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8)) / 255;
        Object_Timer(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 0x40);
        M2C_FIELD(o, Flags_8013FCE0 *, 0xE0).init = 1;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (func_8013F8BC(o)) {
            func_8013FA20(o);
        } else {
            func_8013FC04(o);
        }
        if (!Object_Timer(o, -1)) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            Object_Timer(o, 0xF);
        }
        break;
    case 2:
        if (func_8013F8BC(o)) {
            func_8013FA20(o);
            func_8013F7F8(o, 1);
        } else {
            func_8013F7F8(o, g_Game_8013F7F8.f_0 & 1);
            func_8013FC04(o);
        }
        if (!Object_Timer(o, -1)) {
            func_8013F9D4(o);
            func_8013F7F8(o, 1);
        }
        break;
    case 3:
        if (func_8013F8BC(o)) {
            func_8013FB54_8013FCE0(o, g_Spike_8013F91C.x, g_Spike_8013F91C.y + 0xD7, g_Spike_8013F91C.z);
            if (func_8013F91C(o, 0x96)) {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u32 *, 0xE0) &= ~1;
                Object_Timer(o, 0x1E);
            }
        } else {
            func_8013F9D4(o);
        }
        break;
    case 4:
        func_8013F7F8(o, g_Game_8013F7F8.f_0 & 1);
        func_8013FC4C(o);
        if (!Object_Timer(o, -1)) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            func_8013F7F8(o, 1);
            Object_Timer(o, 0x3C);
        }
        break;
    case 5:
        if (!Object_Timer(o, -1)) {
            func_8013F9D4(o);
        }
        break;
    }
    M2C_FIELD(o, s16 *, 0xAE) = 0;
    func_8013FAB8(o);
}

typedef struct { s16 f0; s16 x, y, z; s16 f8; u16 fA; u8 padC[4]; } Src_8013FFC8;
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 padF[9]; s16 f18; s16 f1A; u8 pad1C[4]; } Pt_8013FFC8;
extern struct { u8 pad0[0x824C]; u8 *f_824C; } g_Game_8013FFC8 asm("g_Game");
extern u8 D_801426E8;
extern Pt_8013FFC8 D_801422E8[];
s32 Floor_GetHeight_8013FFC8(s32, s32, s32) asm("Floor_GetHeight");

s32 func_8013FFC8(void) {
    u8 *h;
    Src_8013FFC8 *src;
    s32 i;

    h = g_Game_8013FFC8.f_824C;
    D_801426E8 = 0;
    src = (Src_8013FFC8 *)(h + 8);
    if (*(u16 *)h == 0x452E && h[2] == 0x46) {
    } else {
        return 1;
    }
    D_801426E8 = h[4];
    if (D_801426E8 > 32) {
        D_801426E8 = 32;
    }
    for (i = 0; i < D_801426E8; i++) {
        D_801422E8[i].fE = 0;
        D_801422E8[i].x8 = D_801422E8[i].x = src[i].x;
        D_801422E8[i].yA = D_801422E8[i].y = src[i].y;
        D_801422E8[i].zC = D_801422E8[i].z = src[i].z;
        D_801422E8[i].floor = Floor_GetHeight_8013FFC8(src[i].x, src[i].y + 0x200, src[i].z);
        if (D_801422E8[i].floor < src[i].y) {
            D_801422E8[i].floor = Floor_GetHeight_8013FFC8(src[i].x, src[i].y + 0x1000, src[i].z);
        }
        D_801422E8[i].f18 = 1;
        D_801422E8[i].f1A = src[i].fA;
    }
    return 0;
}

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80140124;
typedef struct { s16 x, y, z, floor; s16 x0, y0, z0; u8 active; u8 state; s16 f10; s16 vy; s16 f14; u8 phase; u8 pad17; s16 delay; u16 delay0; u8 u, v, f1E, f1F; } Drip_80140124;
typedef struct { s32 z; s32 sxy; } Scr_80140124;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_80140124;
#define ADDPRIM_BF_80140124(ot, p) (((PTag_80140124 *)(p))->addr = ((PTag_80140124 *)(ot))->addr, ((PTag_80140124 *)(ot))->addr = (u32)(p))
#define gte_stszotz_80140124(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern u8 D_801426E8_80140124 asm("D_801426E8");
extern Drip_80140124 D_801422E8_80140124[] asm("D_801422E8");
void Sound_PlayAt_80140124(s32, void *) asm("Sound_PlayAt");
extern Mat_80140124 D_800E78C0_80140124 asm("g_ViewMatrix");
extern GameDraw g_Game_80140124 asm("g_Game");
void SetRotMatrix_80140124(Mat_80140124 *) asm("SetRotMatrix");
void SetTransMatrix_80140124(Mat_80140124 *) asm("SetTransMatrix");
#define SCR_80140124 ((Scr_80140124 *)0x1F800000)

s32 func_80140124(void) {
    Scr_80140124 *sc;
    Drip_80140124 *e;
    s32 i;
    u32 *p;
    u32 *ot;
    u16 x;
    s32 y;
    s32 y2;
    s16 w;
    s16 h;
    s16 x0;
    s16 y0;

    sc = SCR_80140124;
    if (D_801426E8_80140124 == 0) {
        return 0;
    }
    e = D_801422E8_80140124;
    for (i = 0; i < D_801426E8_80140124; i++, e++) {
        if (e->active == 0) {
            if (--e->delay == 0) {
                e->state = 0;
                e->active = 1;
                e->delay = e->delay0;
                e->x = e->x0;
                e->y = e->y0;
                e->z = e->z0;
                e->f14 = 0;
                e->f10 = 0;
                e->vy = 0;
                e->phase = 0;
                *(u32 *)&D_801422E8_80140124[i].u = 0x170F60C0;
            }
        }
    }
    e = D_801422E8_80140124;
    for (i = 0; i < D_801426E8_80140124; i++, e++) {
        if (e->active != 0) {
            switch (e->phase) {
            case 0:
                if (e->state == 10) {
                    e->u += 0x10;
                }
                if (e->state == 0x22) {
                    e->u += 0x10;
                }
                if (e->state >= 0x22) {
                    e->vy += 0xF;
                    if (e->vy > 0x60) {
                        e->vy = 0x60;
                    }
                    e->y += e->vy;
                    if (e->y > e->floor) {
                        e->y = e->floor;
                        e->state = 0;
                        *(u32 *)&e->u = 0x70F20B0;
                        e->phase++;
                        Sound_PlayAt_80140124(0xB3, e);
                    }
                }
                break;
            case 1:
                e->v += 8;
                if (e->state >= 3) {
                    e->active = 0;
                }
                break;
            }
            e->state++;
        }
    }
    SetRotMatrix_80140124(&D_800E78C0_80140124);
    SetTransMatrix_80140124(&D_800E78C0_80140124);
    e = D_801422E8_80140124;
    p = (u32 *)g_Game_80140124.prim;
    ot = g_Game_80140124.db[g_Game_80140124.cur].ot;
    for (i = 0; i < D_801426E8_80140124; i++, e++) {
        if (e->active == 0) {
            continue;
        }
        gte_ldv0(e);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        gte_stszotz_80140124(&sc->z);
        if ((u32)(sc->z - 1) >= 0x7FF) {
            continue;
        }
        x = sc->sxy & 0xFFFF;
        y = sc->sxy >> 16;
        if ((u16)(x + 0x20) >= 0x1C1 || ({ __asm__("" : "=r"(y2) : "0"(y)); y2; }) < -0x20 || y2 >= 0x111) {
            continue;
        }
        w = 0xCD0 / sc->z;
        h = 0xC2C / sc->z;
        x0 = x - w / 2;
        y0 = y - h / 2;
        switch (e->phase) {
        case 0:
            ((u8 *)p)[3] = 9;
            p[1] = 0x2E5A3728;
            p[2] = (y0 << 16) | (x0 & 0xFFFF);
            p[4] = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p[6] = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p[8] = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p[3] = (e->v << 8 | e->u) | 0x7CAC0000;
            p[5] = (e->v << 8 | (e->u + 0xF)) | 0x3C0000;
            ((u16 *)p)[14] = e->u | ((e->v + 0x17) << 8);
            ((u16 *)p)[18] = ((e->v + 0x17) << 8) | (e->u + 0xF);
            ADDPRIM_BF_80140124(ot + sc->z, p);
            p += 10;
            break;
        case 1:
            ((u8 *)p)[3] = 9;
            p[1] = 0x2E6E4B3C;
            p[2] = (y0 << 16) | (x0 & 0xFFFF);
            p[4] = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p[6] = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p[8] = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p[3] = (e->v << 8 | e->u) | 0x7CAC0000;
            p[5] = (e->v << 8 | (e->u + 0xF)) | 0x3C0000;
            ((u16 *)p)[14] = e->u | ((e->v + 7) << 8);
            ((u16 *)p)[18] = ((e->v + 7) << 8) | (e->u + 0xF);
            ADDPRIM_BF_80140124(ot + sc->z, p);
            p += 10;
            break;
        default:
            continue;
        }
    }
    g_Game_80140124.prim = (u8 *)p;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140738 asm("g_Game");
void Sound_PlayAt_80140738(s32, void *) asm("Sound_PlayAt");
s32 ShockBox_Update(s32, void *, s32);

s32 func_80140738(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140738.f_820C + p[2] * 0x38);
    s16 b[6];

    e[0xC] |= 0x8000;
    if (e[0x11] == 100) {
        Sound_PlayAt_80140738(0xB7, e);
    }
    if (p[4] >= 0) {
        if (p[4] < 2) {
            if (e[3] < 0x40) {
                return 0;
            }
        } else if (p[4] < 4) {
            if (e[5] < 0x40) {
                return 0;
            }
        }
    }
    b[0] = e[0];
    b[1] = e[1] + 0x20;
    b[2] = e[2];
    b[3] = e[3] + 0x60;
    b[4] = e[4] + 0x40;
    b[5] = e[5] + 0x60;
    ShockBox_Update(p[4], b, 0x80);
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140864 asm("g_Game");
extern u8 *D_800B4D64_80140864 asm("g_StageMeshes");

s32 func_80140864(s16 *p) {
    u8 *e = g_Game_80140864.f_820C + p[2] * 0x38;

    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        **(u32 **)(D_800B4D64_80140864 + M2C_FIELD(e, s16 *, 0xE) * 32) |= 0x2000;
    }
    M2C_FIELD(e, u16 *, 0x32) = M2C_FIELD(e, u16 *, 6);
    M2C_FIELD(e, u16 *, 0x34) = M2C_FIELD(e, u16 *, 8);
    M2C_FIELD(e, u16 *, 0x36) = M2C_FIELD(e, u16 *, 0xA);
    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 2;
        p[3] = 0x1000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8014090C asm("g_Game");
extern u8 *D_800B4D64_8014090C asm("g_StageMeshes");
void Sound_PlayAt_8014090C(s32, void *) asm("Sound_PlayAt");

s32 func_8014090C(s16 *p) {
    s16 *e = (s16 *)(g_Game_8014090C.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        p[3] += p[5];
        if (p[3] > 0x1000) {
            p[3] = 0;
            p[1] = 1;
            break;
        }
        e[4] = e[0x1A] - e[0x1A] * p[3] / 4096;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014090C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        break;
    case 1:
        p[3]++;
        if (p[6] < p[3]) {
            p[3] = 0x1000;
            p[1] = 2;
            Sound_PlayAt_8014090C(0xB4, e);
        }
        e[4] = 0;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014090C + e[7] * 32, s16 *, 0x18) = 0x1000;
        }
        break;
    case 2:
        p[3] -= p[7];
        if (p[3] < 0) {
            p[3] = 0;
            p[1] = 3;
            break;
        }
        e[4] = e[0x1A] - e[0x1A] * p[3] / 4096;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014090C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        break;
    case 3:
        p[3]++;
        if (p[8] < p[3]) {
            p[3] = 0;
            p[1] = 0;
            Sound_PlayAt_8014090C(0xB5, e);
        }
        e[4] = e[0x1A];
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014090C + e[7] * 32, s16 *, 0x18) = 0;
        }
        break;
    case 4:
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

typedef struct { u8 b[4]; } Stk_80140AFC;
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx_80140AFC;
typedef struct { u8 pad0[0x14]; void *f_14; s32 f_18; u8 pad1C[8]; s32 x; s32 y; s32 z; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x20]; u16 f_5C; u8 pad5E[2]; SVECTOR f_60; u8 pad68[8]; s32 f_70; u8 pad74[0x90]; u8 f_104[4]; s32 f_108; s32 f_10C; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad130[8]; u16 f_138; u16 f_13A; s16 f_13C; u16 f_13E; } Sp_80140AFC;
typedef struct { u8 pad0[0x14]; void *f_14; s32 f_18; u8 pad1C[8]; s32 x; s32 y; s32 z; u8 pad30[0x48]; s16 f_78; s16 f_7A; s16 f_7C; u8 pad7E[0xE]; u8 f_8C; u8 f_8D; u8 pad8E[0x12]; Stk_80140AFC st; s16 f_A4; s16 f_A6; s16 f_A8; s16 f_AA; } Boat_80140AFC;
typedef struct { u8 pad0[0xA0]; Stk_80140AFC st; u8 padA4[0xB4]; u32 f_158; u8 pad15C[4]; u32 f_160; u8 pad164[0x40]; s32 f_1A4; s32 f_1A8; } Pad_80140AFC;
typedef struct { u8 pad0[0xA]; u16 fA; u8 padC[4]; u16 f10; } Scr_80140AFC;
extern Sp_80140AFC g_Spike_80140AFC asm("g_Spike");
extern Pad_80140AFC g_Pad_80140AFC asm("g_Pad");
extern struct { u32 f_0; u8 pad4[8]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140AFC asm("g_Game");
extern Boat_80140AFC *D_800B4DC4_80140AFC asm("D_800B4DC4");
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_SpikeH_80140AFC asm("g_Spike");
extern Stk_80140AFC D_800E53C0;
extern s32 D_800E54C4;
extern s32 D_800E54C8;
extern s32 D_800EC014;
extern u8 D_800E6902;
extern SVECTOR g_JointAngles[3];
extern u8 D_800E7D00_80140AFC[] asm("g_ProjVerts");
s32 Floor_GetHeightAndSlope(s32, s32, s32, void *);
s32 Water_Query(s32, s32, s32);
void Sound_PlayFixed(s32);
s32 rsin_80140AFC(s32) asm("rsin");
s32 rcos_80140AFC(s32) asm("rcos");
void func_8004637C_80140AFC(Mtx_80140AFC *) asm("Matrix_SetIdentity");
void RotMatrixY_80140AFC(s32, void *) asm("RotMatrixY");
void ApplyMatrixSV_80140AFC(Mtx_80140AFC *, SVECTOR *, SVECTOR *) asm("ApplyMatrixSV");
void Spike_ClampMoveStepXZ(s32);
void Matrix_FromFacingXZ(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_80140AFC(void *, void *, void *) asm("Model_Draw");
void Anim_SetFrame(void *);
void Spike_SetPlayMode(s32);
void func_8004B83C(void);
void Spike_UpdateFootEffects(void);
#define CLAMP_80140AFC(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void func_80140AFC(void) {
    Mtx_80140AFC m;
    Boat_80140AFC *o;
    s32 rot;
    s32 spd;
    s32 ang;
    s32 a, b, c, t;
    s32 save;
    Stk_80140AFC *st;

    o = D_800B4DC4_80140AFC;
    g_Spike_80140AFC.f_12C = Floor_GetHeightAndSlope(g_Spike_80140AFC.x, g_Spike_80140AFC.y, g_Spike_80140AFC.z, g_Spike_80140AFC.f_104);
    st = &D_800E53C0;
    o->st = *st;
    g_Spike_80140AFC.f_13A = g_Spike_80140AFC.f_138;
    g_Spike_80140AFC.f_138 = Water_Query(g_Spike_80140AFC.x, g_Spike_80140AFC.y, g_Spike_80140AFC.z);
    g_Spike_80140AFC.f_128 = 0;
    g_Spike_80140AFC.f_120 = 0;
    g_Spike_80140AFC.f_70 = 1;
    if ((g_Spike_80140AFC.f_138 >> 12) == 1) {
        g_Spike_80140AFC.f_13E = ((Scr_80140AFC *)0x1F8003D4)->fA;
        g_Spike_80140AFC.f_13C = ((Scr_80140AFC *)0x1F8003D4)->fA - ((Scr_80140AFC *)0x1F8003D4)->f10;
        if (g_Spike_80140AFC.y - g_Spike_80140AFC.f_13C > 0x20) {
            g_Spike_80140AFC.f_10C -= 0x3000;
        } else if (g_Spike_80140AFC.f_34 < 0) {
            g_Spike_80140AFC.f_34 = 0;
            g_Spike_80140AFC.f_10C = 0;
        }
        o->f_78 = g_SpikeH_80140AFC.x;
        o->f_7A = g_SpikeH_80140AFC.y;
        o->f_7C = g_SpikeH_80140AFC.z;
    } else {
        if (g_Spike_80140AFC.f_12C <= g_Spike_80140AFC.y) {
            g_Spike_80140AFC.x = o->f_78;
            g_Spike_80140AFC.y = o->f_7A;
            g_Spike_80140AFC.z = o->f_7C;
            g_Spike_80140AFC.f_30 = -g_Spike_80140AFC.f_114;
            g_Spike_80140AFC.f_38 = -g_Spike_80140AFC.f_11C;
            g_Spike_80140AFC.f_34 = 0;
        }
        g_Spike_80140AFC.f_10C += D_800EC014 << 7;
    }
    g_Spike_80140AFC.f_30 = CLAMP_80140AFC(g_Spike_80140AFC.f_30, -0x20, 0x20);
    g_Spike_80140AFC.f_38 = CLAMP_80140AFC(g_Spike_80140AFC.f_38, -0x20, 0x20);
    a = (g_Spike_80140AFC.f_30 << 12) + g_Spike_80140AFC.f_108;
    b = g_Spike_80140AFC.f_110;
    c = g_Spike_80140AFC.f_10C;
    g_Spike_80140AFC.f_108 = g_Spike_80140AFC.f_10C = g_Spike_80140AFC.f_110 = 0;
    g_Spike_80140AFC.f_114 = a;
    g_Spike_80140AFC.f_11C = (g_Spike_80140AFC.f_38 << 12) + b;
    g_Spike_80140AFC.f_124 = g_Spike_80140AFC.f_118 = (g_Spike_80140AFC.f_34 << 12) + c;
    g_Spike_80140AFC.f_124 = CLAMP_80140AFC(g_Spike_80140AFC.f_124, -0x1E000, 0x1E000);
    rot = 0;
    if (D_800E6902 != 1) {
        spd = 0;
        if ((s8)st->b[1] > 100) {
            o->f_A4++;
        } else if ((s8)st->b[1] < -100) {
            o->f_A4--;
        } else {
            o->f_A4 = 0;
            o->f_A8 = 0;
        }
        if ((s8)st->b[3] > 100) {
            o->f_A6++;
        } else if ((s8)st->b[3] < -100) {
            o->f_A6--;
        } else {
            o->f_A6 = 0;
        }
        if ((o->f_A4 >= 16 && o->f_A6 >= 16) || (o->f_A4 < -15 && o->f_A6 < -15)) {
            o->f_AA = o->f_A8;
        }
        if (o->f_A4 >= 15) {
            o->f_A4 = 15;
            ang = o->f_A8 + 0x100;
            t = -rsin_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[1] = t;
            t = rcos_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[0] = t;
            o->f_A8 = ang & 0xFFF;
        } else if (o->f_A4 < -14) {
            o->f_A4 = -15;
            ang = o->f_A8 + 0xF00;
            t = -rsin_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[1] = t;
            t = rcos_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[0] = t;
            o->f_A8 = ang & 0xFFF;
        }
        if ((s8)o->st.b[0] > 80) {
            if (o->f_A4 >= 15) {
                rot -= 0x20;
                spd += 0x100;
            } else if (o->f_A4 < -14) {
                rot += 0x20;
                spd -= 0x100;
            } else {
                rot -= D_800E54C4 >> 6;
                spd += D_800E54C4 >> 4;
            }
            if (!(o->f_8C & 1)) {
                o->f_8C = 0x11;
                Sound_PlayFixed(0xB0);
            } else {
                o->f_8C = 1;
            }
        } else if (o->f_8C & 1) {
            o->f_8C = 0x10;
        } else {
            o->f_8C = 0;
        }
        if (o->f_A6 >= 15) {
            o->f_A6 = 15;
            ang = o->f_AA + 0x100;
            t = -rsin_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[3] = t;
            t = -rcos_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[2] = t;
            o->f_AA = ang & 0xFFF;
        } else if (o->f_A6 < -14) {
            o->f_A6 = -15;
            ang = o->f_AA + 0xF00;
            t = -rsin_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[3] = t;
            t = -rcos_80140AFC(ang) >> 5;
            t = CLAMP_80140AFC(t, -0x7F, 0x7F);
            o->st.b[2] = t;
            o->f_AA = ang & 0xFFF;
        }
        if ((s8)o->st.b[2] < -80) {
            if (o->f_A6 >= 15) {
                rot += 0x20;
                spd += 0x100;
            } else if (o->f_A6 < -14) {
                rot -= 0x20;
                spd -= 0x100;
            } else {
                rot -= D_800E54C8 >> 6;
                spd -= D_800E54C8 >> 4;
            }
            if (!(o->f_8D & 1)) {
                o->f_8D = 0x11;
                Sound_PlayFixed(0xB0);
            } else {
                o->f_8D = 1;
            }
        } else if (o->f_8D & 1) {
            o->f_8D = 0x10;
        } else {
            o->f_8D = 0;
        }
        func_8004637C_80140AFC(&m);
        RotMatrixY_80140AFC(rot, &m);
        ApplyMatrixSV_80140AFC(&m, &g_Spike_80140AFC.f_60, &g_Spike_80140AFC.f_60);
        g_Spike_80140AFC.f_108 += (g_Spike_80140AFC.f_60.vx * spd) >> 2;
        g_Spike_80140AFC.f_110 += (g_Spike_80140AFC.f_60.vz * spd) >> 2;
    }
    g_Spike_80140AFC.f_120 += g_Spike_80140AFC.f_108;
    g_Spike_80140AFC.f_124 += g_Spike_80140AFC.f_10C;
    g_Spike_80140AFC.f_128 += g_Spike_80140AFC.f_110;
    g_Spike_80140AFC.f_120 = CLAMP_80140AFC(g_Spike_80140AFC.f_120, -0x14000, 0x14000);
    g_Spike_80140AFC.f_128 = CLAMP_80140AFC(g_Spike_80140AFC.f_128, -0x14000, 0x14000);
    Spike_ClampMoveStepXZ(spd == 0 ? 0x2AA : 0x3000);
    g_Spike_80140AFC.f_30 = g_Spike_80140AFC.f_120 / 4096;
    g_Spike_80140AFC.f_34 = g_Spike_80140AFC.f_124 / 4096;
    g_Spike_80140AFC.f_38 = g_Spike_80140AFC.f_128 / 4096;
    g_Spike_80140AFC.f_108 = g_Spike_80140AFC.f_120 - (g_Spike_80140AFC.f_30 << 12);
    g_Spike_80140AFC.f_10C = g_Spike_80140AFC.f_124 - (g_Spike_80140AFC.f_34 << 12);
    g_Spike_80140AFC.f_110 = g_Spike_80140AFC.f_128 - (g_Spike_80140AFC.f_38 << 12);
    g_Spike_80140AFC.f_114 = g_Spike_80140AFC.f_30;
    g_Spike_80140AFC.f_11C = g_Spike_80140AFC.f_38;
    g_Spike_80140AFC.f_118 = g_Spike_80140AFC.f_34;
    Matrix_FromFacingXZ((s16 *)&g_Spike_80140AFC.f_60, o->f_14);
    o->x = g_Spike_80140AFC.x;
    o->y = g_Spike_80140AFC.y + (rsin_80140AFC(g_Game_80140AFC.f_0 << 6) >> 9);
    o->z = g_Spike_80140AFC.z;
    g_JointAngles[0].vx = 0;
    g_JointAngles[0].vy = 0x800;
    g_JointAngles[0].vz = 0;
    g_JointAngles[1].vx = 0x400 - (o->st.b[3] << 24 >> 22);
    g_JointAngles[1].vy = 0;
    g_JointAngles[1].vz = (o->st.b[2] << 24 >> 22) - 0x480;
    g_JointAngles[2].vx = (o->st.b[1] << 24 >> 22) + 0x400;
    g_JointAngles[2].vy = 0;
    g_JointAngles[2].vz = (o->st.b[0] << 24 >> 22) - 0x380;
    Model_CalcJointMatrices(o, 3);
    Model_ProjectBonedVerts(o);
    func_80017CD4_80140AFC(g_Game_80140AFC.f_80 + g_Game_80140AFC.f_C * 0x4078, D_800E7D00_80140AFC, o);
    if (++g_Spike_80140AFC.f_5C >= 30) {
        g_Spike_80140AFC.f_5C = 0;
    }
    Matrix_FromFacingXZ((s16 *)&g_Spike_80140AFC.f_60, g_Spike_80140AFC.f_14);
    RotMatrixY_80140AFC(0x800, g_Spike_80140AFC.f_14);
    save = g_Spike_80140AFC.f_18;
    g_Spike_80140AFC.f_18 = o->f_18;
    Anim_SetFrame(&g_Spike_80140AFC);
    g_Spike_80140AFC.f_18 = save;
    g_JointAngles[4].vz -= (o->st.b[2] << 24 >> 22);
    g_JointAngles[5].vz += (o->st.b[0] << 24 >> 22);
    g_JointAngles[8].vz -= (o->st.b[2] << 24 >> 23);
    g_JointAngles[9].vz += (o->st.b[0] << 24 >> 23);
    g_JointAngles[8].vy += (o->st.b[3] << 24 >> 22);
    g_JointAngles[9].vy -= (o->st.b[1] << 24 >> 22);
    Model_CalcJointMatrices(&g_Spike_80140AFC, 1);
    Model_ProjectBonedVerts(&g_Spike_80140AFC);
    func_80017CD4_80140AFC(g_Game_80140AFC.f_80 + g_Game_80140AFC.f_C * 0x4078, D_800E7D00_80140AFC, &g_Spike_80140AFC);
    if (g_Pad_80140AFC.f_158 & g_Pad_80140AFC.f_160 & 0xA) {
        Spike_SetPlayMode(0);
        func_8004B83C();
    }
    Spike_UpdateFootEffects();
}

typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[4]; s16 f10; } Scr_8014163C;
extern u8 *D_800B4DC4;
extern SVECTOR g_JointAngles[3];
extern struct { s32 f0; u8 pad4[4]; s32 f8; } g_Game_8014163C asm("g_Game");
extern u8 D_800E7D00_8014163C[] asm("g_ProjVerts");
s32 Floor_GetHeight_8014163C(s32, s32, s32) asm("Floor_GetHeight");
s32 Water_Query(s32, s32, s32);
s32 rsin_8014163C(s32) asm("rsin");
void Matrix_FromFacingXZ(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_8014163C(s32, void *, void *) asm("Model_Draw");

void func_8014163C(void) {
    u8 *o;
    s32 fl;
    s32 lvl;
    s32 y;

    o = D_800B4DC4;
    fl = Floor_GetHeight_8014163C(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C));
    if (((Water_Query(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C)) & 0xFFFF) >> 12) == 1) {
        lvl = ((Scr_8014163C *)0x1F8003D4)->fA - ((Scr_8014163C *)0x1F8003D4)->f10;
        if (M2C_FIELD(o, s32 *, 0x28) - lvl > 0x20) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s32 *, 0x28) - 12;
        } else {
            M2C_FIELD(o, s32 *, 0x28) = lvl + 0x20;
        }
        M2C_FIELD(o, u16 *, 0x78) = M2C_FIELD(o, u16 *, 0x24);
        M2C_FIELD(o, u16 *, 0x7A) = M2C_FIELD(o, u16 *, 0x28);
        M2C_FIELD(o, u16 *, 0x7C) = M2C_FIELD(o, u16 *, 0x2C);
    } else if (M2C_FIELD(o, s32 *, 0x28) >= fl) {
        M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(o, s16 *, 0x78);
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x7A);
        M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s16 *, 0x7C);
    }
    Matrix_FromFacingXZ((s16 *)(o + 0x60), M2C_FIELD(o, s16 **, 0x14));
    y = M2C_FIELD(o, s32 *, 0x28);
    M2C_FIELD(o, s32 *, 0x28) += rsin_8014163C(g_Game_8014163C.f0 << 6) >> 9;
    g_JointAngles[0].vx = 0;
    g_JointAngles[0].vy = 0x800;
    g_JointAngles[0].vz = 0;
    g_JointAngles[1].vx = 0x400;
    g_JointAngles[1].vy = 0;
    g_JointAngles[1].vz = -0x480;
    g_JointAngles[2].vx = 0x400;
    g_JointAngles[2].vy = 0;
    g_JointAngles[2].vz = -0x380;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_8014163C(g_Game_8014163C.f8, D_800E7D00_8014163C, o);
    M2C_FIELD(o, s32 *, 0x28) = y;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
