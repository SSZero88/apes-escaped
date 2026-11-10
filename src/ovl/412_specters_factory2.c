#include "common.h"
#include "m2c_macros.h"

M2C_UNK Matrix_FromDirection(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
M2C_UNK Model_CalcKeyedJointMatrices(void *, M2C_UNK);
M2C_UNK Model_DrawAuto(void *, M2C_UNK *, void *);
s32 Object_IsOffScreen(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK g_ProjVerts;
extern M2C_UNK D_80141E40;
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; s32 f_820C; u8 pad_8210[0x10]; s32 f_8220; } g_Game;
M2C_UNK func_80141090(void *);
extern s32 g_StageMeshes;

M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
void Bomb_UpdateAll(void);
extern struct S_D_80141DF0 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80141DF0[];
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
extern s32 D_80142000;
M2C_UNK Fx_DrawFadeRing(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_AddAttackSphereAt(void *, s32, M2C_UNK);
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s32);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
void CamPoint_GetLookPoint(void *, s32, void *);
extern struct { u8 pad0[0xA]; s16 f_A; } D_800E68C0;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike;

void func_8013D000(void *arg0) {
    SVECTOR v;

    ((Scr_401 *)0x1F800000)->spike.vx = g_Spike.x;
    ((Scr_401 *)0x1F800000)->spike.vy = g_Spike.y;
    ((Scr_401 *)0x1F800000)->spike.vz = g_Spike.z;
    CamPoint_GetLookPoint(arg0, 2, &v);
    v.vy += D_800E68C0.f_A;
    ((Scr_401 *)0x1F800000)->eye.vx = ((Scr_401 *)0x1F800000)->spike.vx;
    ((Scr_401 *)0x1F800000)->eye.vy = g_Spike.y - 0x100;
    ((Scr_401 *)0x1F800000)->eye.vz = ((Scr_401 *)0x1F800000)->spike.vz;
    Camera_EaseLookAt(arg0, 6, 6, 6);
    ((Scr_401 *)0x1F800000)->at.vx = (v.vx * 7 + ((Scr_401 *)0x1F800000)->spike.vx) / 8;
    ((Scr_401 *)0x1F800000)->at.vy = v.vy - D_800E68C0.f_A * 2;
    ((Scr_401 *)0x1F800000)->dir.vx = ((Scr_401 *)0x1F800000)->spike.vx - M2C_FIELD(arg0, s16 *, 0xA);
    ((Scr_401 *)0x1F800000)->dir.vy = 0;
    ((Scr_401 *)0x1F800000)->dir.vz = ((Scr_401 *)0x1F800000)->spike.vz - M2C_FIELD(arg0, s16 *, 0xE);
    VectorNormalSS(&((Scr_401 *)0x1F800000)->dir, &((Scr_401 *)0x1F800000)->dir);
    ((Scr_401 *)0x1F800000)->at.vz = ((Scr_401 *)0x1F800000)->spike.vz - ((Scr_401 *)0x1F800000)->dir.vz / 3;
    Camera_EaseEye(arg0, 6, 6, 6);
}

void Shot_InitModel(void *arg0, void *arg1, M2C_UNK arg2) {
    Object_SetModel(arg1, arg2);
    Object_GetAnimTable(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void Mech_DrawShot(s32 arg0) {
    void *temp_s0;

    temp_s0 = (void *)((u8 *)&D_80141E40 + (arg0 * 0x70));
    if (Object_IsOffScreen(temp_s0 + 0x24, 0, 0) == 0) {
        Matrix_FromDirection(temp_s0 + 0x60, M2C_FIELD(temp_s0, s32 *, 0x14));
        Model_CalcKeyedJointMatrices(temp_s0, 3);
        Model_ProjectBonedVerts(temp_s0);
        Model_DrawAuto((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &g_ProjVerts, temp_s0);
    }
}

typedef struct { u8 pad0[0xC]; s16 f; u8 pad[0x6]; } Slot_411;
extern Slot_411 D_80141738_s[4] asm("D_80141DF0");

s32 Bomb_FindFree(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_80141738_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, tag; } Drip_8013D2E8;
extern Drip_8013D2E8 D_80141DF0_8013D2E8[4] asm("D_80141DF0");
extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013D2E8 asm("g_Spike");
extern u8 D_800E77F0;
s32 Bomb_FindFree(void);
s32 rcos_8013D2E8(s32) asm("rcos");
s32 rsin_8013D2E8(s32) asm("rsin");
s32 Vec_Length_8013D2E8(s32, s32, s32) asm("Vec_Length");
s32 VectorNormalSS_8013D2E8(void *, void *) asm("VectorNormalSS");
void Object_PlaySound_8013D2E8(void *, s32) asm("Object_PlaySound");

void Bomb_Throw(arg0, side, drop, fwd, aimed, tag)
    void *arg0;
    s16 side;
    s16 drop;
    s16 fwd;
    s32 aimed;
    s32 tag;
{
    Drip_8013D2E8 *p;
    s32 i;
    s32 a;
    s16 c;
    s16 s;
    s32 d;
    s32 n;
    s32 t;
    s32 h;
    s32 sp;
    SVECTOR v;

    i = Bomb_FindFree();
    if (i == -1) {
        return;
    }
    p = &D_80141DF0_8013D2E8[i];
    a = (M2C_FIELD(arg0, s16 *, 0xAC) + 0x1000 + M2C_FIELD(arg0, s16 *, 0xB2)) % 0x1000;
    c = rcos_8013D2E8(a);
    s = rsin_8013D2E8(a);
    { s32 cf = c * (s16)fwd; cf >>= 12; p->x = ((s * (s16)side) >> 12) + (M2C_FIELD(arg0, u16 *, 0x24) + cf); }
    p->y = M2C_FIELD(arg0, u16 *, 0x28) - drop;
    { s32 sf = ((s * (s16)fwd) >> 12); p->z = ((-(c * (s16)side)) >> 12) + (M2C_FIELD(arg0, u16 *, 0x2C) + sf); }
    p->active++;
    d = Vec_Length_8013D2E8(g_Spike_8013D2E8.x - p->x, 0, g_Spike_8013D2E8.z - p->z);
    if (aimed != 0) {
        if (d > 0x400) {
            sp = 100;
            if ((D_800E77F0 + 6) << 9 < d) {
                sp = 50;
            }
            v.vx = (u16)g_Spike_8013D2E8.x - p->x;
            v.vy = 0;
            v.vz = (u16)g_Spike_8013D2E8.z - p->z;
            VectorNormalSS_8013D2E8(&v, &v);
            p->vx = v.vx / sp;
            p->vz = v.vz / sp;
            n = d / (0x1000 / sp);
            p->grav = 1;
            if (n == 0) {
                p->vy = 0;
            } else {
                p->vy = (g_Spike_8013D2E8.y - (h = p->y + 0x80)) / n - n / 2;
            }
        } else {
            v.vx = (u16)g_Spike_8013D2E8.x - p->x;
            v.vy = -(p->y + 0x80) + g_Spike_8013D2E8.y;
            v.vz = (u16)g_Spike_8013D2E8.z - p->z;
            VectorNormalSS_8013D2E8(&v, &v);
            p->vx = v.vx / 100;
            p->vy = v.vy / 100;
            p->vz = v.vz / 100;
            p->grav = 0;
        }
    } else {
        n = d / 85;
        p->grav = 2;
        p->vx = c / 48;
        p->vz = s / 48;
        if (n == 0) {
            p->vy = 0;
        } else {
            h = p->y + 0x80;
            t = g_Spike_8013D2E8.y - h;
            if (t < -100) {
                t = -100;
            }
            p->vy = t / n - n;
        }
    }
    p->owner = M2C_FIELD(arg0, s8 *, 0xCB);
    p->tag = tag;
    Object_PlaySound_8013D2E8(arg0, 0x77);
}

s32 Shot_IsBelowFloor(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void Shot_SpawnTrail(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void Shot_SpawnSplash(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

typedef struct { s16 x; s16 y; s16 z; } V3_8013D890;
void Shot_SpawnSplash(SVECTOR *arg0);
void Sound_PlayAt(s32, void *);
void Pickup_Drop(s32, SVECTOR *, s32, s32);

void Bomb_Land(SVECTOR *arg0, s32 drop) {
    V3_8013D890 s;
    V3_8013D890 v;
    SVECTOR c;

    v.x = arg0->vx;
    v.y = arg0->vy;
    v.z = arg0->vz;
    s = v;
    arg0[1].vz = 0;
    Shot_SpawnSplash(arg0);
    Sound_PlayAt(0x4D, &s);
    if (drop && arg0[2].vy != 0) {
        g_RandSeed = g_RandSeed * 5 + 1;
        if (g_RandSeed >> 8 < 0x80) {
            c.vx = arg0->vx;
            c.vy = arg0->vy;
            c.vz = arg0->vz;
            Pickup_Drop(1, &c, 3, 0);
        }
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, pad12; } Drip_8013D974;
extern Drip_8013D974 D_80141DF0_8013D974[4] asm("D_80141DF0");
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013D974;
extern M_8013D974 D_80141F90_8013D974 asm("D_80141F90");
typedef struct { u8 pad[0x28]; s32 y; u8 pad2C[0xB4 - 0x2C]; s32 f_B4; u8 padB8[0xE4 - 0xB8]; } Obj_8013D974;
extern Obj_8013D974 g_Objects_8013D974[] asm("g_Objects");
s32 VectorNormalSS_8013D974(void *, void *) asm("VectorNormalSS");
void Mech_DrawShot(s32 arg0);
s32 Shot_IsBelowFloor(void *arg0);
void Shot_SpawnTrail(SVECTOR *arg0);
void Bomb_Land(SVECTOR *arg0, s32 drop);

void Bomb_UpdateAll(void) {
    Drip_8013D974 *p;
    M_8013D974 *m;
    Obj_8013D974 *o;
    s32 i;

    m = &D_80141F90_8013D974;
    for (i = 3; i >= 0; i--) {
        p = &D_80141DF0_8013D974[i];
        if (p->active != 0) {
            p->active++;
            p->vy += p->grav;
            o = &g_Objects_8013D974[p->owner];
            Shot_SpawnTrail((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (Object_DetachLink(o, 0) == 6 || o->y + 0x600 < p->y) {
                Bomb_Land((SVECTOR *)p, 0);
            }
            if (Shot_IsBelowFloor(p)) {
                Bomb_Land((SVECTOR *)p, 1);
                continue;
            }
            m->x = p->x;
            m->y = p->y;
            m->z = p->z;
            m->vx = p->vx;
            m->vy = p->vy;
            m->vz = p->vz;
            VectorNormalSS_8013D974(&m->vx, &m->vx);
            Mech_DrawShot(3);
            o->f_B4 = Object_AddAttackSphere(o, 100, p->x, p->y, p->z, 0x201, 0x203);
        }
    }
}

void Bomb_InitPool(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80141DF0[i].f_C = 0;
    }
    Hook_Add(&Bomb_UpdateAll);
}

extern u8 D_80141AA4[];
void Shockwave_Spawn(void *, void *, s32, s32, void *);

void func_8013DB7C(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    Shockwave_Spawn(m, D_80141AA4, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_80140110 asm("g_Game");
extern u8 D_80141A50[];

void func_8013DBB8(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_80140110 & 1) {
        Shockwave_Spawn(m, D_80141A50, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8013DC04(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x24, 1, 0, 0x64);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_8013DC84(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
}

s32 Math_Atan2(s32, s32);

void Swooper_StartReturn(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013DD5C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    Object_PlaySound(arg0, 0x6F);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    Object_Timer(arg0, 0xA);
}

s32 Object_FlyAboveFloor(void *, s32);

void Swooper_Hover(void *arg0) {
    Object_FlyAboveFloor(arg0, 0x14);
}

void Swooper_ReturnHome(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    Swooper_Hover(arg0);
}

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
M2C_UNK Object_ApplyVelocity(void *);
s16 Object_FloorAt(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepGrowShrink(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK VectorNormalSS(void *, void *);

void Swooper_StepDive(void *arg0) {
    void *temp_a0;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        goto block_8;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (Object_StepToward3D(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13) != 0) {
        Swooper_StartReturn(arg0);
    } else {
        M2C_FIELD(arg0, u16 *, 0x60) = (u16) M2C_FIELD(arg0, u16 *, 0x94);
        temp_a0 = arg0 + 0x60;
        M2C_FIELD(temp_a0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(temp_a0, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x98);
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & 0xFF3FFFFF) | 0x800000);
        VectorNormalSS(temp_a0, temp_a0);
        Object_ApplyVelocity(arg0);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x103);
    }
    if (Object_FloorAt(arg0, 0, 0, 0) < M2C_FIELD(arg0, s32 *, 0x28)) {
block_8:
        Swooper_StartReturn(arg0);
    }
}

void Object_ApplyHit(void *);
void Object_HitFeedback(void *);

s32 Swooper_CheckHit(void *arg0) {
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

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 20; u32 mode : 2; u32 b26 : 6; } Flags_8013E074;
typedef struct { u16 start; u16 end; } Rng_8013E074;
extern struct { u8 pad_0[0x24]; u16 x; u16 p26; u16 y; u16 p2A; u16 z; } g_Spike_8013E074 asm("g_Spike");
void Object_ClampAnimFrame_8013E074(void *, s32) asm("Object_ClampAnimFrame");
void Object_PlaySound_8013E074(void *, s32) asm("Object_PlaySound");
void Object_TurnToward_8013E074(void *, s16, s16, s16, s16) asm("Object_TurnToward");
s32 Object_SpikeInFront(void *, s32, s32, s32);
void Object_OrbitHome(void *, s16);
void Object_InitOrbit(void *, s32);
void func_80058134_8013E074(void *, s32) asm("Object_DebugStub");
s32 func_80057140_8013E074(void *, s32, s32) asm("Object_AddAttachPoint");
void func_8013DB7C(void *arg0);
void func_8013DBB8(void *arg0);
void func_8013DC04(void *arg0);
void func_8013DC84(void *arg0);
void func_8013DD5C(void *arg0);
void Swooper_Hover(void *arg0);
void Swooper_ReturnHome(void *arg0);
void Swooper_StepDive(void *arg0);
s32 Swooper_CheckHit(void *arg0);

void Swooper_Update(u8 *o) {
    if (!M2C_FIELD(o, Flags_8013E074 *, 0xE0).init) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x64;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x46) = 0x64;
        M2C_FIELD(o, s16 *, 0x44) = 0x3C;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0xDC) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, s16 *, 0x9C) -= 0xC8;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, Flags_8013E074 *, 0xE0).mode = 2;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013E074 **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, s32 *, 0x74) = func_80057140_8013E074(o, 0xA, 0x9C);
        M2C_FIELD(o, s32 *, 0x78) = func_80057140_8013E074(o, 6, 0x70);
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, Flags_8013E074 *, 0xE0).init = 1;
    }
    func_80058134_8013E074(o, M2C_FIELD(o, s16 *, 0x44));
    if (Swooper_CheckHit(o) == 0) {
        switch (M2C_FIELD(o, u8 *, 0x80)) {
        case 1:
            Object_OrbitHome(o, 8);
            Object_SeekHeight(o, 8);
            Swooper_Hover(o);
            if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
                func_8013DD5C(o);
            }
            break;
        case 2:
            Object_ClampAnimFrame_8013E074(o, M2C_FIELD(o, Rng_8013E074 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            Object_TurnToward_8013E074(o, g_Spike_8013E074.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013E074.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
            func_8013DC84(o);
            func_8013DC04(o);
            if (Object_Timer(o, -1) == 0) {
                M2C_FIELD(o, u8 *, 0x80) = 3;
                M2C_FIELD(o, s16 *, 0xA8) = 0;
                M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
                M2C_FIELD(o, u16 *, 0xBC) = g_Spike_8013E074.x;
                M2C_FIELD(o, u16 *, 0xC0) = g_Spike_8013E074.z;
                M2C_FIELD(o, u16 *, 0xBE) = g_Spike_8013E074.y - 0xC8;
                M2C_FIELD(o, u8 *, 0x8F) = 0;
                func_8013DB7C(o);
            }
            break;
        case 3:
            Object_ClampAnimFrame_8013E074(o, M2C_FIELD(o, Rng_8013E074 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
                if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                    Object_PlaySound_8013E074(o, 0xA6);
                }
            }
            Swooper_StepDive(o);
            func_8013DC84(o);
            func_8013DC04(o);
            func_8013DBB8(o);
            break;
        case 4:
            Swooper_ReturnHome(o);
            break;
        }
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[8]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; s16 life; } Debris_8013E388;
extern Debris_8013E388 D_80142008_8013E388[] asm("D_80142008");
extern u16 g_RandSeed2;
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Obj_8013E388;

void Mech_InitDebris(void *o) {
    s32 i;
    Debris_8013E388 *d;
    s32 k;

    for (i = 0; i < 6; i++) {
        d = &D_80142008_8013E388[i];
        k = i + 0x72;
        Object_SetModel(d, k);
        Object_GetAnimTable(d, k);
        d->f5C = 0;
        d->f62 = 0;
        d->f60 = 0;
        d->f64 = 0x1000;
        d->f66 = 3;
        d->x = ((Obj_8013E388 *)o)->x + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->y = ((Obj_8013E388 *)o)->y - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8);
        d->z = ((Obj_8013E388 *)o)->z + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x40;
        d->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 2;
    }
}

typedef struct { s16 x, y, z; } Rot_8013E674;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_8013E674 r; s16 life; } Debris_8013E674;
extern Debris_8013E674 D_80142008[6];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013E674 asm("g_Game");
void RotMatrixYXZ(void *, void *);
void Dust_SpawnDrift(SVECTOR *);

void Mech_UpdateDebris(u8 *arg0) {
    s32 i;
    Debris_8013E674 *d;
    SVECTOR v;

    for (i = 0; i < 6; i++) {
        d = &D_80142008[i];
        if (d->life != 0) {
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            v.vx = d->x;
            v.vy = d->y;
            v.vz = d->z;
            if (M2C_FIELD(arg0, s16 *, 0x9C) < d->y) {
                d->life = 0;
                v.vy = M2C_FIELD(arg0, s16 *, 0x9C) - 0x32;
                Effect_SpawnAt(0x102, &v);
                Object_PlaySound(arg0, 0x6E);
                continue;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (Object_IsOffScreen(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                Model_CalcKeyedJointMatrices(d, 3);
                Model_ProjectBonedVerts(d);
                Model_DrawAuto(g_Game_8013E674.f_80 + g_Game_8013E674.f_C * 0x4078, &g_ProjVerts, d);
                Effect_SpawnAt(7, &v);
                Dust_SpawnDrift(&v);
            }
        }
    }
}

void Mech_StartLoopSound(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, arg0 + 0x24);
    }
}

void Obj_StopLoopSound(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

extern u8 D_80141B10[];

void func_8013E908(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x40;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Shockwave_Spawn(&v, D_80141B10, 1, 0, 0);
    Shockwave_Spawn(&v, D_80141B10 + 0x54, 1, 0, 0);
}

extern u8 D_80141BB8[];

void func_8013E97C(void *pos) {
    SVECTOR d = { 0, -0x1000, 0 };

    Shockwave_Spawn(pos, D_80141BB8, 1, 0, &d);
}

extern u32 g_Game_8013E9D8 asm("g_Game");
void func_8013E97C(void *pos);

void func_8013E9D8(u8 *arg0) {
    SVECTOR v;
    s16 x, z;
    s32 dx, dz;
    s32 a, b;

    if (!(g_Game_8013E9D8 & 1)) {
        a = M2C_FIELD(arg0, s16 *, 0x60);
        x = M2C_FIELD(arg0, u16 *, 0x24);
        b = M2C_FIELD(arg0, s16 *, 0x64);
        z = M2C_FIELD(arg0, u16 *, 0x2C);
        x -= (a * 35) >> 9;
        dx = (b * 65) >> 11;
        z -= (b * 35) >> 9;
        dz = (-a * 65) >> 11;
        v.vx = x + dx;
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, u16 *, 0x96) - 300;
        v.vz = z + dz;
        func_8013E97C(&v);
        v.vx = x - dx;
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, u16 *, 0x96) - 300;
        v.vz = z - dz;
        func_8013E97C(&v);
    }
}

extern u8 D_80141AF8[];
void Rock_SpawnBurst(SVECTOR *, void *);
void Fx_DebrisExplosion(s32, s32, s32);

void Mech_Explode(u8 *o) {
    SVECTOR v;

    v.vx = M2C_FIELD(o, s32 *, 0x24);
    v.vy = M2C_FIELD(o, s32 *, 0x28);
    v.vz = M2C_FIELD(o, s32 *, 0x2C);
    Rock_SpawnBurst(&v, D_80141AF8);
    Rock_SpawnBurst(&v, D_80141AF8 + 0xC);
    Object_PlaySound(o, 0x4D);
    Fx_DebrisExplosion((s16)M2C_FIELD(o, s32 *, 0x24), (s16)M2C_FIELD(o, s32 *, 0x28), (s16)M2C_FIELD(o, s32 *, 0x2C));
    M2C_FIELD(o, s8 *, 0x80) = 0x15;
    M2C_FIELD(o, s8 *, 0xC8) = 0;
    M2C_FIELD(o, s16 *, 0x5E) = 1;
    Object_Timer(o, 0x3C);
    Mech_InitDebris(o);
    Object_DropPickups(o);
    Object_DisableCollision(o);
}

void Mech_StartJump(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x88);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, s8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_v1, u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) ((s32) -(arg1 * (s16) (((M2C_FIELD(temp_v1, u16 *, 0x12) + 5) - M2C_FIELD(temp_v1, u16 *, 0x10)) - 1)) / 2);
}

void func_8013EBF4(void *arg0, s16 *v) {
    s32 s = M2C_FIELD(arg0, s16 *, 0x60);
    s32 a = s * v[2];
    s32 c = M2C_FIELD(arg0, s16 *, 0x64);
    s32 b = c * v[2];
    s32 d = c * v[0];
    s32 e = -s * v[0];
    u16 px = M2C_FIELD(arg0, u16 *, 0x24);
    u16 py = M2C_FIELD(arg0, u16 *, 0x28);
    u16 pz = M2C_FIELD(arg0, u16 *, 0x2C);

    v[1] = py - v[1];
    v[0] = px + (a >> 12) + (d >> 12);
    v[2] = pz + (b >> 12) + (e >> 12);
}


void Mech_SpawnSideEffects(void *arg0, s16 x, s16 y, s32 z, s32 fx) {
    SVECTOR v;

    v.vx = x;
    v.vy = y;
    v.vz = z;
    func_8013EBF4(arg0, &v);
    Effect_SpawnAt(fx, &v);
    v.vx = -x;
    v.vy = y;
    v.vz = z;
    func_8013EBF4(arg0, &v);
    Effect_SpawnAt(fx, &v);
}


void func_8013ED10(void *arg0, s16 n) {
    Mech_SpawnSideEffects(arg0, n * 50 + 0x104, 500 - n * 10, -0x14, 5);
}

void Mech_ExhaustBlast(u8 *o) {
    s32 n = (s16)(M2C_FIELD(o, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4));

    if (n < 5) {
        if (n == 1) {
            Object_PlaySound(o, 0x82);
        }
        Mech_SpawnSideEffects(o, n * 50 + 0x104, 400 - n * 10, -0x14, 5);
    }
}


void func_8013EE38(void *arg0, s16 n) {
    Bomb_Throw(arg0, 0xC8, n, 0xC8, 1, 1);
    Bomb_Throw(arg0, -0xC8, n, 0xC8, 1, 0);
}

s32 Object_AddDamageSphereAt(void *, SVECTOR *, s32, s32);

void Mech_AddBodySphere(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u32 *, 0xE0) & 1) {
        return;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        return;
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x190;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddDamageSphereAt(arg0, &v, 0x104, 0x201);
}

void func_8013EF34(void *arg0) {
    s32 var_t0;
    s32 var_v1;

    if (D_80142000 != 0) {
        D_80142000 -= 1;
        return;
    }
    if (Object_DetachLink(arg0, 1) == 6) {
        if (M2C_FIELD(arg0, u8 *, 0x80) != 0x11) {
            D_80142000 = 0xA;
        }
    } else if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        var_t0 = 0x101;
        if (M2C_FIELD(arg0, u8 *, 0x80) == 0x11) {
            var_t0 = 0x203;
            var_v1 = 0x801;
        } else {
            var_v1 = 0x800;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphere(arg0, 0x104, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x190), (s32) M2C_FIELD(arg0, s16 *, 0x2C), var_v1, var_t0);
    }
}

void Mech_FlashHit(void *arg0) {
    s32 a;

    if (M2C_FIELD(arg0, u8 *, 0x8F) <= 0x3C) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        if (M2C_FIELD(arg0, u8 *, 0x8F) & 1) {
            a = 0x3F;
        } else {
            a = 0x8E;
        }
    } else {
        a = 0x3F;
    }
    Object_SetModel(arg0, a);
}

s32 rcos_8013F058(s32) asm("rcos");
s32 rsin_8013F058(s32) asm("rsin");

void func_8013F058(u8 *arg0, s32 arg1) {
    SVECTOR v;
    s32 ang;
    u16 r;

    if (arg1 != 0) {
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        ang = (M2C_FIELD(arg0, s16 *, 0xAC) + ((r >> 8) << 12) / 1020 + 0x600) % 0x1000;
    } else {
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        ang = (M2C_FIELD(arg0, s16 *, 0xAC) + ((r >> 8) << 12) / 510 + 0xC00) % 0x1000;
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F058(ang) << 8) >> 12);
    r = (&g_RandSeed)[1] * 5 + 1;
    (&g_RandSeed)[1] = r;
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (r >> 8) - 200;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F058(ang) << 8) >> 12);
    Effect_SpawnAt(7, &v);
}

void func_8013F1C0(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x1C, 0, 0, 0x12C);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

s32 rcos_8013F240(s32) asm("rcos");
s32 rsin_8013F240(s32) asm("rsin");
void Dust_SpawnDrift(SVECTOR *);

void func_8013F240(u8 *arg0, s32 arg1) {
    SVECTOR v;
    s32 ang;
    u16 r;

    if (arg1 != 0) {
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        ang = (M2C_FIELD(arg0, s16 *, 0xAC) + ((r >> 8) << 12) / 1020 + 0x600) % 0x1000;
    } else {
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        ang = (M2C_FIELD(arg0, s16 *, 0xAC) + ((r >> 8) << 12) / 510 + 0xC00) % 0x1000;
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F240(ang) << 8) >> 12);
    r = (&g_RandSeed)[1] * 5 + 1;
    (&g_RandSeed)[1] = r;
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (r >> 9) - 300;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F240(ang) << 8) >> 12);
    Dust_SpawnDrift(&v);
}

extern u32 g_Game_8013F3A4 asm("g_Game");
void func_8013F1C0(void *arg0);

void Mech_SmokeByDamage(u8 *arg0) {
    u8 v;

    if (arg0[0x80] != 0x15 && (g_Game_8013F3A4 & 1)) {
        v = arg0[0x81];
        if (v < 5) {
            func_8013F058(arg0, 1);
            func_8013F058(arg0, 1);
            func_8013F058(arg0, 0);
            func_8013F240(arg0, 1);
            func_8013F240(arg0, 0);
            func_8013F1C0(arg0);
            func_8013F1C0(arg0);
        } else if (v < 10) {
            func_8013F058(arg0, 1);
            func_8013F058(arg0, 0);
            func_8013F240(arg0, 1);
            func_8013F1C0(arg0);
        } else if (v < 15) {
            func_8013F058(arg0, 1);
            func_8013F240(arg0, 1);
        } else if (v < 20) {
            func_8013F058(arg0, 1);
        }
    }
}

extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike_8013F4B4 asm("g_Spike");
typedef struct { u16 start; u16 end; } Rng_8013F4B4;
s16 *Collision_GetShape_8013F4B4(s32) asm("Collision_GetShape");
s32 Collision_GetId(s32);
s32 Object_SpikeBehind(void *, s32, s32, s16);
void Obj_StopLoopSound(void *arg0);
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
s32 Sound_PlayFixed(s32);
void Object_SpawnImpactFx(void *, s32, s32, s32);

void Mech_CheckHit(u8 *o) {
    s16 *s;

    if (M2C_FIELD(o, u32 *, 0x50) >> 28 != 0xB) {
        return;
    }
    if (o[0x81] == 0 || o[0x80] == 6) {
        return;
    }
    s = Collision_GetShape_8013F4B4(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
    if (Collision_GetId(M2C_FIELD(o, u16 *, 0x50) & 0xFFF) != 2 && Object_SpikeBehind(o, 0xB4, 0, 0)) {
        o[0x8F] = 0;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        Object_ApplyHit(o);
        Object_HitFeedback(o);
        Obj_StopLoopSound(o);
        if (o[0x81] != 0) {
            o[0x80] = 0x14;
            o[0x7F] = o[0xCD];
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013F4B4 **, 0x88)[o[0x7F]].start;
            o[0xCE] = o[0x7F];
        } else {
            o[0x80] = 5;
            Object_Timer(o, 0x1E);
            o[0x82] = 0;
        }
        Object_TurnToward(o, M2C_FIELD(o, u16 *, 0x24) - g_Spike_8013F4B4.x, M2C_FIELD(o, u16 *, 0x2C) - g_Spike_8013F4B4.z, 0, 0x1000);
        return;
    }
    Sound_PlayFixed(0x67);
    Object_SpawnImpactFx(o, (s16)(s[0] - M2C_FIELD(o, u16 *, 0x24)), (s16)(M2C_FIELD(o, u16 *, 0x28) - s[2]), (s16)(s[4] - M2C_FIELD(o, u16 *, 0x2C)));
}

M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);

void Mech_JumpHome(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x80) != 0xF) {
        M2C_FIELD(arg0, u8 *, 0x80) = 0xFU;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x96) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        Object_SetModel(arg0, 0x3F);
        M2C_FIELD(arg0, s8 *, 0x82) = 0;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s16 *, 0x9C) + 0x538);
        Mech_StartJump(arg0, 5);
        Object_TurnToward(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
        Object_Timer(arg0, 0x14);
    }
}

void Mech_StartCharge(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (arg1 * 8);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & 0xFFFEFFFF);
    Object_PlaySound(arg0, 0xA8);
}

s32 Mech_StepCharge(u8 *a, s16 n) {
    s32 s;

    if (Object_StepGrowShrink(a, 0, 0, n)) {
        return 1;
    }
    s = M2C_FIELD(a, s16 *, 0xA8) >> 3;
    M2C_FIELD(a, s32 *, 0x24) += (M2C_FIELD(a, s16 *, 0x60) * s) >> 12;
    M2C_FIELD(a, s32 *, 0x2C) += (M2C_FIELD(a, s16 *, 0x64) * s) >> 12;
    if (s >= 11) {
        Mech_SpawnSideEffects(a, 0xB4, 0x32, 0, 5);
    }
    return 0;
}

void func_8013F80C(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x74);
    Fx_DrawFadeRing(temp_s0, 0xC8, 4, 0x645050);
    Object_AddAttackSphereAt(arg0, temp_s0, 0xC8);
}

typedef struct { u8 pad[0xAC]; s16 f_AC; } Obj_8013F860;
extern u32 g_Game_8013F860 asm("g_Game");
s32 rcos_8013F860(s32) asm("rcos");
s32 rsin_8013F860(s32) asm("rsin");

void Mech_SpawnSparks(u8 *arg0) {
    SVECTOR v;
    s32 ang;
    u16 r;

    if (g_Game_8013F860 % 5 == 0 || g_Game_8013F860 % 17 == 0) {
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        ang = (((Obj_8013F860 *)arg0)->f_AC + ((r >> 8) << 12) / 510 + 0xC00) % 0x1000;
        v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F860(ang) << 8) >> 12);
        r = g_RandSeed * 5 + 1;
        g_RandSeed = r;
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) - ((r >> 9) + 250);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F860(ang) << 8) >> 12);
        Effect_SpawnAt(0x102, &v);
        Object_PlaySound(arg0, 0x4D);
    }
}

void func_8013F9C0(void *arg0, s32 arg1) {
    Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6) + arg1);
}

extern M2C_UNK D_80141F90;

void func_8013F9F4(void *obj) {
    Shot_InitModel(obj, &D_80141F90, 0xA0);
    Bomb_InitPool();
}

typedef struct { u8 pad[0xE0]; u32 b0:6; u32 b6:1; u32 b7:5; u32 b12:1; u32 b13:1; u32 b14:7; u32 b21:1; u32 b22:2; u32 b24:2; u32 b26:6; } Obj_8013FA24;
s32 Object_AddAttachPoint(void *, s32, s32);
void Object_PlaceAtPathPoint(void *, s32);
void Object_FacePathPoint(void *, s32);
void func_8013F9F4(void *obj);

void Mech_Init(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0xA0) = 200;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    arg0[0x81] = 20;
    arg0[0x7D] = 10;
    M2C_FIELD(arg0, s16 *, 0x46) = 700;
    M2C_FIELD(arg0, s16 *, 0x48) = 0x800;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x3EFF;
    M2C_FIELD(arg0, s16 *, 0x44) = 200;
    arg0[0xCD] = 1;
    ((Obj_8013FA24 *)arg0)->b21 = 1;
    arg0[0xDC] = 6;
    ((Obj_8013FA24 *)arg0)->b24 = 1;
    ((Obj_8013FA24 *)arg0)->b13 = 1;
    M2C_FIELD(arg0, s32 *, 0x74) = Object_AddAttachPoint(arg0, 0x16, 0x14E);
    M2C_FIELD(arg0, s16 *, 0xA4) = 800;
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
    arg0[0x8E] = 1;
    ((Obj_8013FA24 *)arg0)->b6 = 0;
    D_80142000 = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
    if (M2C_FIELD(arg0, u16 *, 0x8C) != 0) {
        Object_PlaceAtPathPoint(arg0, 0);
        Object_FacePathPoint(arg0, 1);
    }
    func_8013F9F4(arg0);
}

typedef struct { u16 start; u16 end; } Anim_8013FB34;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x14]; s16 f_44; u8 pad46[0xA]; s32 f_50; u8 pad54[8]; u16 f_5C; u8 pad5E[2]; SVECTOR f_60; u8 pad68[0x17]; u8 f_7F; u8 f_80; u8 pad81; u8 f_82; u8 pad83[5]; Anim_8013FB34 *f_88; u8 pad8C[8]; s16 f_94; s16 f_96; s16 f_98; s16 f_9A; s16 f_9C; s16 f_9E; u8 padA0[6]; s16 f_A6; u8 padA8[6]; s16 f_AE; s16 f_B0; u8 padB2[2]; s32 f_B4; u8 padB8[0x11]; u8 f_C9; u8 padCA[5]; u8 f_CF; u8 padD0[0x10]; u32 f_E0; } O_8013FB34;
extern struct { u32 f_0; u8 pad4[0x814C]; u16 f_8150; } g_Game_8013FB34 asm("g_Game");
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013FB34 asm("g_Spike");
extern s32 D_800EC208;
void Object_ClampAnimFrame_8013FB34(void *, s32) asm("Object_ClampAnimFrame");
void func_80058134_8013FB34(void *, s32) asm("Object_DebugStub");
s32 Object_SpikeOutOfRange_8013FB34(void *, s32, s32, s32, s32) asm("Object_SpikeOutOfRange");
void Object_StepOnGroundFixed_8013FB34(void *) asm("Object_StepOnGroundFixed");
void Object_ChaseSpike_8013FB34(void *, s32) asm("Object_ChaseSpike");
void Object_TurnTowardSpike_8013FB34(void *) asm("Object_TurnTowardSpike");
void Object_CameraShake_8013FB34(void *, s32) asm("Object_CameraShake");
s32 Object_WouldLeaveHome_8013FB34(void *, s32) asm("Object_WouldLeaveHome");
void func_80051E98_8013FB34(void *, s32) asm("Object_Despawn");
void func_80055AA0_8013FB34(void *, s32, s32, s32) asm("Object_StepTowardXZ");
s32 func_8013F80C_8013FB34(void *) asm("func_8013F80C");
s32 func_8013F9C0_8013FB34(void *, s32) asm("func_8013F9C0");
void Mech_UpdateDebris(u8 *arg0);
void Mech_StartLoopSound(void *arg0);
void func_8013E908(void *arg0);
void func_8013E9D8(u8 *arg0);
void Mech_Explode(u8 *o);
void Mech_StartJump(void *arg0, s32 arg1);
void func_8013ED10(void *arg0, s16 n);
void Mech_ExhaustBlast(u8 *o);
void func_8013EE38(void *arg0, s16 n);
void Mech_AddBodySphere(void *arg0);
void func_8013EF34(void *arg0);
void Mech_FlashHit(void *arg0);
void Mech_SmokeByDamage(u8 *arg0);
void Mech_CheckHit(u8 *o);
void Mech_StartCharge(void *arg0, s32 arg1);
s32 Mech_StepCharge(u8 *a, s16 n);
void Mech_SpawnSparks(u8 *arg0);
void Mech_Init(u8 *arg0);
#define ABS_8013FB34(x) ((x) < 0 ? -(x) : (x))

void Mech_Update(O_8013FB34 *o) {
    s32 t;
    s32 m;
    s32 s, c, v;

    if (!((o->f_E0 >> 3) & 1)) {
        Mech_Init((u8 *)o);
        o->f_80 = 1;
        o->f_7F = 9;
        o->f_5C = o->f_88[9].start;
        o->f_E0 |= 8;
    }
    func_80058134_8013FB34(o, o->f_44);
    if (o->f_CF == 4) {
        func_80051E98_8013FB34(o, 1);
        return;
    }
    if (o->f_82 != 0) {
        Mech_FlashHit(o);
        return;
    }
    switch (o->f_80) {
    case 1:
        Object_StepOnGroundFixed_8013FB34(o);
        if (!Object_SpikeOutOfRange_8013FB34(o, o->f_9A, o->f_28, o->f_9E, o->f_A6) && D_800EC208 - o->f_28 < 200) {
            o->f_80 = 2;
            o->f_7F = 9;
            o->f_5C = o->f_88[9].start;
            Mech_StartCharge(o, 0x55);
            goto clear;
        }
        break;
    case 2:
        if (Mech_StepCharge((u8 *)o, -10)) {
            o->f_80 = 3;
            o->f_7F = 10;
            o->f_5C = o->f_88[10].start;
            o->f_E0 &= ~1;
        } else {
            Mech_AddBodySphere(o);
        }
        break;
    case 3:
        Mech_ExhaustBlast((u8 *)o);
        Object_ChaseSpike_8013FB34(o, 8);
        Object_StepOnGroundFixed_8013FB34(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 4;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 4:
        if ((o->f_5C - o->f_88[o->f_7F].start) % ((o->f_88[o->f_7F].end - o->f_88[o->f_7F].start) / 2) == 2) {
            Object_PlaySound(o, 0xA9);
            Object_CameraShake_8013FB34(o, 0);
        }
        if (Object_WouldLeaveHome_8013FB34(o, -100)) {
            if (func_8013F9C0_8013FB34(o, 0)) {
                func_80055AA0_8013FB34(o, o->f_9A, o->f_9E, 8);
            } else {
                o->f_80 = 23;
                o->f_7F = 10;
                o->f_5C = o->f_88[10].end - 1;
                o->f_B0 = 0x5B;
            }
        } else {
            Object_ChaseSpike_8013FB34(o, 8);
            if (Object_SpikeInFront(o, 0xB4, 0, 0)) {
                if (Object_SpikeOutOfRange_8013FB34(o, o->f_24, o->f_28, o->f_2C, 0x400)) {
                    o->f_80 = 19;
                    o->f_7F = 10;
                    o->f_5C = o->f_88[10].end - 1;
                    o->f_B0 = 0x5B;
                    Object_Timer(o, 0x3C);
                } else if (Object_SpikeInFront(o, 0x78, 0x804, 0x200)) {
                    o->f_80 = 9;
                    o->f_7F = 6;
                    o->f_AE = 0;
                    o->f_E0 &= ~1;
                    o->f_5C = o->f_88[6].start;
                    Object_PlaySound(o, 0x53);
                }
            }
        }
        Object_StepOnGroundFixed_8013FB34(o);
        break;
    case 19:
        if (o->f_7F == 10) {
            Object_TurnTowardSpike_8013FB34(o);
            o->f_5C -= 3;
            if (o->f_5C < o->f_88[o->f_7F].start + 0x14) {
                o->f_7F = 9;
                o->f_5C = o->f_88[9].start;
                Object_PlaySound(o, 0x37);
            }
        } else {
            if (o->f_C9 >= 21) {
                Object_TurnTowardSpike_8013FB34(o);
            }
            if (Object_Timer(o, -1) == 0) {
                o->f_80 = 17;
                Mech_StartCharge(o, 0x82);
                o->f_AE = 0;
            }
        }
        break;
    case 17:
        if (Object_WouldLeaveHome_8013FB34(o, 0) || Mech_StepCharge((u8 *)o, -0x1E)) {
            o->f_80 = 18;
            o->f_44 = 0xC8;
            Object_Timer(o, 0x5A);
        }
        break;
    case 18:
        switch (o->f_7F) {
        case 9:
            Mech_ExhaustBlast((u8 *)o);
            if (Object_Timer(o, -1) == 0) {
                if (func_8013F9C0_8013FB34(o, 0)) {
                    o->f_7F = 10;
                    o->f_5C = o->f_88[10].start;
                } else {
                    o->f_80 = 22;
                }
            }
            break;
        case 10:
            if (++o->f_5C >= o->f_88[o->f_7F].end) {
                o->f_80 = 12;
                o->f_7F = 3;
                o->f_5C = o->f_88[3].start;
                Mech_StartJump(o, 2);
            }
            break;
        }
        break;
    case 23:
        Object_TurnTowardSpike_8013FB34(o);
        o->f_5C -= 3;
        if (o->f_5C < o->f_88[o->f_7F].start + 0x14) {
            o->f_7F = 9;
            o->f_5C = o->f_88[9].start;
            o->f_80 = 22;
        }
        break;
    case 22:
        Object_TurnTowardSpike_8013FB34(o);
        switch (o->f_7F) {
        case 9:
            m = g_Game_8013FB34.f_0 % 60;
            if (func_8013F9C0_8013FB34(o, 0)) {
                o->f_7F = 10;
                o->f_5C = o->f_88[10].start;
            } else if (!func_8013F9C0_8013FB34(o, 0)) {
                if (m == 0) {
                    func_8013EE38(o, 0x122);
                } else if (m < 10) {
                    func_8013ED10(o, m);
                }
            }
            break;
        case 10:
            if (o->f_5C >= o->f_88[10].end) {
                o->f_80 = 4;
                o->f_7F = 0;
                o->f_5C = o->f_88[0].start;
            }
            break;
        }
        break;
    case 12:
        if (o->f_88[o->f_7F].end - 5 < o->f_5C) {
            Object_ApplyVelocity(o);
            func_8013E9D8((u8 *)o);
            o->f_96 += 2;
            Object_TurnToward(o, g_Spike_8013FB34.x - o->f_24, g_Spike_8013FB34.z - o->f_2C, 0, o->f_B0);
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 14;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
            Object_PlaySound(o, 0x8D);
            Mech_StartLoopSound(o);
        }
        break;
    case 14:
        Object_TurnToward(o, g_Spike_8013FB34.x - o->f_24, g_Spike_8013FB34.z - o->f_2C, 0, o->f_B0);
        func_8013E9D8((u8 *)o);
        Object_ApplyVelocity(o);
        o->f_96 += 2;
        if (o->f_96 >= 0) {
            Object_Timer(o, 0x2D);
            o->f_80 = 13;
            o->f_98 = 0;
            o->f_96 = 0;
            o->f_94 = 0;
        }
        break;
    case 13:
        Object_ClampAnimFrame_8013FB34(o, o->f_88[o->f_7F].end);
        if (o->f_C9 != 0) {
            func_8013E9D8((u8 *)o);
            if (o->f_C9 >= 11) {
                Object_TurnToward(o, g_Spike_8013FB34.x - o->f_24, g_Spike_8013FB34.z - o->f_2C, 0, o->f_B0);
            } else if (o->f_C9 == 10) {
                func_8013EE38(o, 0x1A4);
            } else if (o->f_C9 >= 6) {
                func_8013ED10(o, 10 - o->f_C9);
            }
        } else {
            Obj_StopLoopSound(o);
        }
        if (Object_Timer(o, -1) == 0) {
            o->f_96 += 7;
            t = Object_FloorAt(o, 0, 0, 0);
            if (t < o->f_28 + o->f_96) {
                o->f_80 = 8;
                o->f_28 = t;
                o->f_7F = 5;
                o->f_5C = o->f_88[5].start;
                Object_PlaySound(o, 0x95);
                Object_CameraShake_8013FB34(o, 0);
            } else {
                o->f_28 += o->f_96;
            }
        }
        break;
    case 20:
        Object_SetModel(o, 0x3F);
        Mech_StartJump(o, 5);
        o->f_80 = 6;
        o->f_50 = 0;
        break;
    case 6:
        if (o->f_88[o->f_7F].end - 5 < o->f_5C) {
            o->f_28 += o->f_96;
            o->f_96 += 5;
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 7;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
            Object_PlaySound(o, 0x8D);
            o->f_44 = 1;
        }
        break;
    case 7:
        func_80055AA0_8013FB34(o, o->f_9A, o->f_9E, 0x1E);
        Object_ApplyVelocity(o);
        o->f_96 += 5;
        Object_AddAttackSphere(o, 0xC8, o->f_24, o->f_28 - 0x15E, (s16)o->f_2C, 0x801, 0x201);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 8;
            o->f_7F = 5;
            o->f_5C = o->f_88[5].start;
            Object_PlaySound(o, 0x95);
            Object_CameraShake_8013FB34(o, 0);
            Object_StepOnGroundFixed_8013FB34(o);
            func_8013E908(o);
        }
        break;
    case 8:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 4;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
            o->f_44 = 0xC8;
        }
        break;
    case 9:
        {
            register s32 s9 asm("$4") = o->f_88[o->f_7F].start;
            register s32 c9 asm("$3") = o->f_5C;
            if (s9 + 0x14 < c9 && c9 < s9 + 0x18) {
                register s32 e9 asm("$2") = s9 + 0x15;
                if (c9 == e9) {
                    Object_PlaySound(o, 0x6D);
                }
                o->f_44 = 1;
                if (Object_DetachLink(o, 0) == 6) {
                    o->f_E0 |= 1;
                }
                o->f_B4 = func_8013F80C_8013FB34(o);
            } else if (o->f_E0 & 1) {
                func_8013F80C_8013FB34(o);
            }
        }
        {
            register s32 fl9 asm("$3") = Object_FloorAt(o, o->f_94, 0, o->f_98);
            register s32 y9 asm("$4") = o->f_28;
            register s32 d9 asm("$2");
            if ((d9 = y9 - fl9) >= 0 ? d9 < 200 : (d9 = fl9 - y9) < 200) {
                Object_StepOnGroundFixed_8013FB34(o);
            }
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            if ((o->f_E0 & 1) && g_Game_8013FB34.f_8150 == 7) {
                {
                    register s32 k10 asm("$2") = 10;
                    o->f_80 = k10;
                }
                o->f_7F = 7;
                v = o->f_88[7].start;
                o->f_B0 = 0x5B;
            } else {
                o->f_80 = 4;
                o->f_7F = 0;
                v = o->f_88[0].start + 0x14;
                o->f_44 = 0xC8;
                o->f_B0 = 0x16;
            }
            o->f_5C = v;
        clear:
            o->f_E0 &= ~1;
        }
        break;
    case 10:
        Object_TurnToward(o, o->f_9A - o->f_24, o->f_9E - o->f_2C, 0, o->f_B0);
        func_8013F80C_8013FB34(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 11;
            o->f_96 = 0;
            o->f_7F = 8;
            o->f_5C = o->f_88[8].start;
        }
        break;
    case 11:
        if (o->f_5C < o->f_88[o->f_7F].start + 0x14) {
            func_8013F80C_8013FB34(o);
        } else if (o->f_5C == o->f_88[o->f_7F].start + 0x20) {
            Object_AddAttackSphere(o, 0x12C, o->f_24 + (o->f_60.vx * 25 >> 9), o->f_28 - 0x190, (s16)(o->f_2C + (o->f_60.vz * 25 >> 9)), 0x801, 0x204);
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_44 = 0xC8;
            o->f_80 = 4;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 15:
        if (Object_Timer(o, -1) == 0) {
            Object_ApplyVelocity(o);
            func_8013E9D8((u8 *)o);
            if (o->f_28 < o->f_9C - 0x400) {
                func_80055AA0_8013FB34(o, o->f_9A, o->f_9E, 0x50);
                o->f_80 = 16;
            }
        }
        break;
    case 16:
        Object_ClampAnimFrame_8013FB34(o, o->f_88[o->f_7F].end);
        if (Object_Timer(o, -1) == 0) {
            s32 g;
            o->f_96 += 7;
            g = Object_FloorAt(o, 0, 0, 0);
            if (g < o->f_28 + o->f_96) {
                o->f_28 = g;
                o->f_80 = 8;
                o->f_7F = 5;
                o->f_5C = o->f_88[5].start;
                Object_PlaySound(o, 0x95);
                Object_CameraShake_8013FB34(o, 0);
            } else {
                func_80055AA0_8013FB34(o, o->f_9A, o->f_9E, 0x50);
                Object_ApplyVelocity(o);
            }
        }
        break;
    case 5:
        if (o->f_C9 < 20) {
            Mech_SpawnSparks((u8 *)o);
            if (o->f_88[o->f_7F].start + 2 < o->f_5C) {
                o->f_5C = o->f_88[o->f_7F].start;
            }
        } else {
            o->f_5C--;
            if (o->f_C9 == 20) {
                o->f_7F = 2;
                o->f_5C = o->f_88[2].start;
            }
        }
        if (Object_Timer(o, -1) == 0) {
            Mech_Explode((u8 *)o);
        }
        break;
    case 21:
        Mech_UpdateDebris((u8 *)o);
        if (Object_Timer(o, -1) == 0) {
            func_80051E98_8013FB34(o, 1);
        }
        break;
    }
    func_8013EF34(o);
    Mech_SmokeByDamage((u8 *)o);
    Mech_CheckHit((u8 *)o);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

extern struct S_g_Game_80140BD0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140BD0 asm("g_Game");
s32 ShockBox_Update(s32, void *, s32);

s32 func_80140BD0(s16 *p) {
    s16 v[6];
    s16 *e = (s16 *)(g_Game_80140BD0.f_820C + p[2] * 0x38);

    e[0xC] |= 0x8000;
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
    v[0] = e[0];
    v[1] = e[1] + 0x20;
    v[2] = e[2];
    v[3] = e[3] + 0x60;
    v[4] = e[4] + 0x40;
    v[5] = e[5] + 0x60;
    ShockBox_Update(p[4], v, 0x80);
    return 0;
}

typedef struct { u8 pad0[6]; s16 f6; u8 pad8[0x10]; } Sw_80140CDC;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; Sw_80140CDC *f_8220; } g_Game_80140CDC asm("g_Game");

s32 func_80140CDC(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140CDC.f_820C + p[2] * 0x38);

    e[0x12] = e[0];
    e[0x13] = e[1];
    e[0x14] = e[2];
    p[1] = 0;
    p[3] = 0;
    p[9] = 0;
    p[0xB] = -1;
    if (p[4] >= 0) {
        Sw_80140CDC *w = &g_Game_80140CDC.f_8220[p[4]];
        w->f6 = p[5];
    }
    return 0;
}

typedef struct { u8 pad0[0x16]; s16 f16; } Sw_80140D60;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; Sw_80140D60 *f_8220; } g_Game_80140D60 asm("g_Game");
extern u8 *D_800B4D64_80140D60 asm("g_StageMeshes");
s16 Sound_Play_80140D60(s32, s32) asm("Sound_Play");
s32 Sound_Stop_80140D60(s32, s32) asm("Sound_Stop");
s32 Sound_UpdateVoice3D_80140D60(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");

s32 func_80140D60(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140D60.f_820C + p[2] * 0x38);
    s32 s = 0;
    Sw_80140D60 *w;

    if (p[4] >= 0) {
        w = &g_Game_80140D60.f_8220[p[4]];
        s = w->f16;
    }
    switch (p[1]) {
    case 0:
        if (s < p[9]) {
            p[9] -= p[7];
            p[1] = 2;
        } else {
            p[9] = s;
            if (s >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            }
        }
        break;
    case 1:
        if (--p[3] < 0) {
            p[1] = 2;
        }
        break;
    case 2:
        p[9] -= p[7];
        if (p[9] < s) {
            p[9] = s;
            if (s >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            } else {
                p[1] = 0;
            }
        } else if (p[9] < 0) {
            p[9] = 0;
            p[1] = 0;
        }
        break;
    }
    if (p[9] > 0) {
        if (p[11] < 0) {
            p[11] = Sound_Play_80140D60(1, 0x7F);
        } else {
            Sound_UpdateVoice3D_80140D60(0x7F, p[11], 0x1800, e);
        }
    } else if (p[11] >= 0) {
        Sound_Stop_80140D60(0x7F, p[11]);
        p[11] = -1;
    }
    e[1] = e[0x13] + p[8] * p[9];
    if (e[7] >= 0) {
        M2C_FIELD(D_800B4D64_80140D60 + e[7] * 32, s16 *, 0x12) = e[0x13] + p[8] * p[9];
    }
    return 0;
}

s32 func_80140F9C(void *arg0) {
    s32 var_s0;
    u16 temp_v0;
    void *temp_s1;

    temp_s1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_s1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_s1, u16 *, 0x18) & 0xFFF0) | 1);
    temp_v0 = M2C_FIELD(arg0, u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(temp_s1, u16 *, 0xE) = temp_v0;
    if ((s16) temp_v0 >= 0) {
        M2C_FIELD((((s16) temp_v0 << 5) + g_StageMeshes), s16 *, 0x16) = 0;
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, s16 *, 0xA) > 0) {
        do {
            func_80141090(arg0);
            if ((M2C_FIELD(temp_s1, u16 *, 0x18) & 0xF) != 1) {
                func_80141134(temp_s1);
            }
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s16 *, 0xA));
    }
    return 0;
}

s32 func_80141090(void *arg0) {
    s16 temp_a0;
    u16 temp_v0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 2) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 6) + 1;
        M2C_FIELD(arg0, u16 *, 6) = temp_v0;
        if (M2C_FIELD(arg0, s16 *, 8) < (s16) temp_v0) {
            M2C_FIELD(arg0, s16 *, 2) = 1;
            temp_a0 = M2C_FIELD(temp_a1, s16 *, 0xE);
            if (temp_a0 >= 0) {
                M2C_FIELD(((temp_a0 << 5) + g_StageMeshes), u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 2);
        }
    }
    return 0;
}

typedef struct { s16 x, y, z; u8 pad6[6]; s16 n; s16 next; } Node_80140368;
extern struct { u8 pad_0[0x8214]; Node_80140368 *f_8214; } g_Game_80140368 asm("g_Game");
extern u8 *D_800B4D64_80140368 asm("g_StageMeshes");
s16 Box_QuadrantMask(s16 *);

s32 func_80141134(s16 *e) {
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
    e[0x10] = Box_QuadrantMask(e);
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

typedef struct { u8 pad_0[0x20C]; u8 *f_820C; u8 pad_210[0x10]; u8 *f_8220; } G_801413D8;
extern G_801413D8 D_800F4350;
extern s16 g_SpikeStandObj;
extern u8 *D_800B4D64_801413D8 asm("g_StageMeshes");

s32 func_801413D8(s16 *p) {
    s32 i;
    u8 *d;
    G_801413D8 *g;
    u8 *e;
    u8 *t;
    s32 st = p[1];
    s32 id = p[2];

    if (st == 0 && g_SpikeStandObj == id) {
        i = 0;
        g = &D_800F4350;
        d = D_800B4D64_801413D8;
        for (; i < 7; i++) {
            if (p[4 + i] < 0) {
                break;
            }
            t = g->f_8220 + p[4 + i] * 0x18;
            e = g->f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(d + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF1) | 0x8001;
        }
        p[1] = 1;
    }
    return 0;
}

extern s32 D_80142320;
s32 Sound_Play_80141494(s32, s32) asm("Sound_Play");
s32 Link_MoveChainWith(s16, s16 *, s16 *);
s32 func_8014173C(s16 arg0, s16 arg1);

s32 func_80141494(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140BD0.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (g_SpikeStandObj == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[3] = 1;
            p[1] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
            if (p[5] >= 0) {
                func_8014173C(p[5], 1);
            }
            D_80142320 = Sound_Play_80141494(0, 0xB3);
        } else if (g_SpikeStandObj < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 1:
        if (p[8] >= 0) {
            Link_MoveChainWith(p[8], e, &p[9]);
        }
        if (e[0x19] >= p[6] * 2 + 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 2;
            if (p[4] >= 0) {
                Sound_PlayAt(p[4], e);
            }
            p[3] = g_SpikeStandObj == p[2];
            Sound_Stop_80140D60(0xB3, D_80142320);
        } else {
            Sound_UpdateVoice3D_80140D60(0xB3, D_80142320, 0x1000, e);
        }
        break;
    case 2:
        if (g_SpikeStandObj == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[1] = 3;
            p[3] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
            if (p[5] >= 0) {
                func_8014173C(p[5], 3);
            }
            D_80142320 = Sound_Play_80141494(0, 0xB3);
        } else if (g_SpikeStandObj < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 3:
        if (p[8] >= 0) {
            Link_MoveChainWith(p[8], e, &p[9]);
        }
        if (e[0x19] == 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 0;
            if (p[4] >= 0) {
                Sound_PlayAt(p[4], e);
            }
            p[3] = g_SpikeStandObj == p[2];
            Sound_Stop_80140D60(0xB3, D_80142320);
        } else {
            Sound_UpdateVoice3D_80140D60(0xB3, D_80142320, 0x1000, e);
        }
        break;
    }
    return 0;
}

s32 func_8014173C(s16 arg0, s16 arg1) {
    void *temp_a0;
    void *temp_v1;

    temp_a0 = g_Game.f_8220 + (arg0 * 0x18);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(temp_a0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 2);
    M2C_FIELD(temp_a0, s16 *, 2) = arg1;
    M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 0);
    M2C_FIELD(temp_a0, u16 *, 0x14) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(temp_a0, u16 *, 0x16) = (u16) M2C_FIELD(temp_v1, u16 *, 4);
    return 0;
}

s32 func_801417C8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 0x14) = -1;
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801417DC asm("g_Spike");
s32 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);
s32 func_80087BA4_801417DC(s32, s32, s32, s32) asm("Sound_SetVoiceVolumeRatio");

s32 func_801417DC(s16 *o) {
    s32 h;

    h = o[11];
    if (h >= 0) {
        if (o[5] < g_Spike_801417DC.y || g_Spike_801417DC.z > 0xE00) {
            Sound_Stop(0xB0, h);
            o[11] = -1;
        } else {
            if (g_Spike_801417DC.z < 0x600) {
                func_80087BA4_801417DC(0xB0, h, 0x800, 0x800);
            } else {
                func_80087BA4_801417DC(0xB0, h, 0xE00 - g_Spike_801417DC.z, 0x800);
            }
        }
    } else if (g_Spike_801417DC.y < o[5] && g_Spike_801417DC.z < 0xE00) {
        o[11] = Sound_Play(1, 0xB0);
    }
    h = o[10];
    if (h >= 0) {
        if (g_Spike_801417DC.z >= 0xE00 || g_Spike_801417DC.y < -0xB00) {
            Sound_Stop(0x7C, h);
            o[10] = -1;
        } else {
            if (g_Spike_801417DC.z < 0x600) {
                func_80087BA4_801417DC(0x7C, h, 0x800, 0x800);
            } else {
                func_80087BA4_801417DC(0x7C, h, 0xE00 - g_Spike_801417DC.z, 0x800);
            }
        }
    } else if (g_Spike_801417DC.y > -0xB00 || g_Spike_801417DC.z < 0xE00) {
        o[10] = Sound_Play(1, 0x7C);
    }
    return 0;
}

extern u32 g_Game_80141960 asm("g_Game");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void Sound_PlayAt(s32, void *);

s32 func_80141960(u8 *arg0) {
    if (g_Game_80141960 % 10 == 0) {
        Sound_PlayAt(((RAND() >> 8) & 3) + 0xB6, arg0 + 8);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
