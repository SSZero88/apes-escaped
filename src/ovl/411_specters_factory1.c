#include "common.h"
#include "m2c_macros.h"

M2C_UNK Matrix_FromDirection(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
M2C_UNK Model_CalcKeyedJointMatrices(void *, M2C_UNK);
M2C_UNK Model_DrawAuto(void *, M2C_UNK *, void *);
s32 Object_IsOffScreen(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK g_ProjVerts;
extern M2C_UNK D_80141788;
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; s32 f_820C; } g_Game;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
M2C_UNK Link_Activate(s16, void *);

M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
void Bomb_UpdateAll(void);
extern struct S_D_80141738 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80141738[];
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
void *Collision_GetShape(s32);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);
extern struct S_D_80141948 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80141948[];

extern SVECTOR D_80141730;
extern struct { u8 pad0[0x60]; SVECTOR f_60; } g_Spike_8013D000 asm("g_Spike");
void Camera_ExitLook(void);
void Camera_ExitRadarLive(void);

void func_8013D000(void) {
    D_80141730 = g_Spike_8013D000.f_60;
    Camera_ExitLook();
    Camera_ExitRadarLive();
}

typedef struct { u32 tag; u32 tpage; u32 rgbc; u32 xy; u32 uvclut; u32 wh; } Spr_8013F058;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013F058 asm("g_Game");

void func_8013D058(void) {
    Spr_8013F058 *p;
    u32 *ot;
    s32 t;
    s32 b;

    t = g_Game_8013F058.frame & 0x1F;
    b = g_Game_8013F058.frame & 8;
    if (t >= 16) {
        t = 31 - t;
    }
    t = t * 8 + 0x60;
    p = (Spr_8013F058 *)g_Game_8013F058.prim;
    ot = &g_Game_8013F058.db[g_Game_8013F058.cur].ot[1];
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100021B;
    p->rgbc = (t << 16) | (t << 8) | t | 0x66000000;
    p->xy = 0x6800A4;
    p->wh = 0x200038;
    p->uvclut = (b << 10) | 0x7CED00A0;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    g_Game_8013F058.prim = (u8 *)(p + 1);
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x28]; s16 f40; u8 pad42[2]; s16 f44; } Scr_8013F148;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013F148;
void Camera_UpdateOrientation(void *);
void Camera_HandleManualInput(void *);
void Camera_KeepAboveFloor(void *);
void Matrix_LookAt(void *, void *, void *, s32);
void ApplyMatrixSV(void *, void *, void *);
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
s32 rcos_8013F148(s32) asm("rcos");
s32 rsin_8013F148(s32) asm("rsin");
extern s32 D_800E5478;
extern SVECTOR D_800EC240[2];
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
void Matrix_LookAt(void *, void *, void *, s32);

void func_8013D148(void *c) {
    Scr_8013F148 *scr = (Scr_8013F148 *)0x1F800000;
    SVECTOR v;
    Mat_8013F148 m;
    s32 t;

    Camera_UpdateOrientation(c);
    M2C_FIELD(c, s32 *, 0x38) = (M2C_FIELD(c, s32 *, 0x38) * 3 + 0x400) / 4;
    Camera_HandleManualInput(c);
    if (!(D_800E5478 & 0xA000)) {
        M2C_FIELD(c, s32 *, 0x4C) = M2C_FIELD(c, s32 *, 0x4C) * 3 / 4;
    }
    t = M2C_FIELD(c, s32 *, 0x4C) + 0x1000;
    M2C_FIELD(c, s32 *, 0x40) = (M2C_FIELD(c, s32 *, 0x48) + t) % 0x1000;
    M2C_FIELD(c, u8 *, 0x34) = 0;
    M2C_FIELD(c, u8 *, 0x32) = 0;
    Matrix_LookAt(&D_800EC240[0], &D_800EC240[1], &m, 0);
    v.vx = 0;
    v.vy = 0;
    v.vz = -M2C_FIELD(c, u16 *, 0x38);
    ApplyMatrixSV(&m, &v, &v);
    scr->eye.vx = scr->spike.vx + scr->f40 / 16;
    scr->eye.vy = scr->spike.vy + (s16)(v.vy - 0x3C);
    scr->eye.vz = scr->spike.vz + scr->f44 / 16;
    scr->at.vx = scr->eye.vx + ((rcos_8013F148(M2C_FIELD(c, s32 *, 0x40)) * M2C_FIELD(c, s32 *, 0x38)) >> 12);
    scr->at.vy = scr->spike.vy - (s16)(v.vy + 0x140);
    scr->at.vz = scr->eye.vz + ((rsin_8013F148(M2C_FIELD(c, s32 *, 0x40)) * M2C_FIELD(c, s32 *, 0x38)) >> 12);
    Camera_EaseLookAt(c, 2, 8, 2);
    Camera_EaseEye(c, 2, 4, 2);
    M2C_FIELD(c, s16 *, 0xC) += M2C_FIELD(c, s16 *, 0x6C);
    Camera_KeepAboveFloor(c);
    M2C_FIELD(c, s32 *, 0x44) = M2C_FIELD(c, s32 *, 0x40);
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

void Robot_DrawPart(s32 arg0) {
    void *temp_s0;

    temp_s0 = (void *)((u8 *)&D_80141788 + (arg0 * 0x70));
    if (Object_IsOffScreen(temp_s0 + 0x24, 0, 0) == 0) {
        Matrix_FromDirection(temp_s0 + 0x60, M2C_FIELD(temp_s0, s32 *, 0x14));
        Model_CalcKeyedJointMatrices(temp_s0, 3);
        Model_ProjectBonedVerts(temp_s0);
        Model_DrawAuto((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &g_ProjVerts, temp_s0);
    }
}

typedef struct { u8 pad0[0xC]; s16 f; u8 pad[0x6]; } Slot_411;
extern Slot_411 D_80141738_s[4] asm("D_80141738");

s32 Bomb_FindFree(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_80141738_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, pad12; } Drip_8013D4FC;
extern Drip_8013D4FC D_80141738_8013D4FC[4] asm("D_80141738");
extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013D4FC asm("g_Spike");
s32 Bomb_FindFree(void);
s32 rcos_8013D4FC(s32) asm("rcos");
s32 rsin_8013D4FC(s32) asm("rsin");
s32 Vec_Length_8013D4FC(s32, s32, s32) asm("Vec_Length");
s32 VectorNormalSS_8013D4FC(void *, void *) asm("VectorNormalSS");
void Object_PlaySound_8013D4FC(void *, s32) asm("Object_PlaySound");

void Bomb_Throw(u8 *o, s16 side, s16 drop, s16 fwd, s32 aimed) {
    Drip_8013D4FC *p;
    s32 i;
    s32 a;
    s16 c;
    s16 s;
    s32 d;
    s32 n;
    s32 t;
    s32 h;
    SVECTOR v;

    i = Bomb_FindFree();
    if (i == -1) {
        return;
    }
    p = &D_80141738_8013D4FC[i];
    a = (M2C_FIELD(o, s16 *, 0xAC) + 0x1000 + M2C_FIELD(o, s16 *, 0xB2)) % 0x1000;
    c = rcos_8013D4FC(a);
    s = rsin_8013D4FC(a);
    { s32 cf = c * fwd; cf >>= 12; p->x = ((s * side) >> 12) + (M2C_FIELD(o, u16 *, 0x24) + cf); }
    p->y = M2C_FIELD(o, u16 *, 0x28) - drop;
    { s32 sf = (s * fwd) >> 12; p->z = ((-(c * side)) >> 12) + (M2C_FIELD(o, u16 *, 0x2C) + sf); }
    p->active++;
    d = Vec_Length_8013D4FC(g_Spike_8013D4FC.x - p->x, 0, g_Spike_8013D4FC.z - p->z);
    if (aimed != 0) {
        if (d > 0x400) {
            v.vx = (u16)g_Spike_8013D4FC.x - p->x;
            v.vy = 0;
            v.vz = (u16)g_Spike_8013D4FC.z - p->z;
            VectorNormalSS_8013D4FC(&v, &v);
            p->vx = v.vx / 72;
            p->vz = v.vz / 72;
            n = d / 56;
            p->grav = 1;
            if (n == 0) {
                p->vy = 0;
            } else {
                p->vy = (g_Spike_8013D4FC.y - (h = p->y + 0x80)) / n - n / 2;
            }
        } else {
            v.vx = (u16)g_Spike_8013D4FC.x - p->x;
            v.vy = -(p->y + 0x80) + g_Spike_8013D4FC.y;
            v.vz = (u16)g_Spike_8013D4FC.z - p->z;
            VectorNormalSS_8013D4FC(&v, &v);
            p->vx = v.vx / 72;
            p->vy = v.vy / 72;
            p->vz = v.vz / 72;
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
            t = g_Spike_8013D4FC.y - h;
            if (t < -100) {
                t = -100;
            }
            p->vy = t / n - n;
        }
    }
    p->owner = M2C_FIELD(o, s8 *, 0xCB);
    Object_PlaySound_8013D4FC(o, 0x77);
}

s32 Shot_IsBelowFloor(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Shot_SpawnTrail(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void Effect_SpawnAt(s32, SVECTOR *);

void Shot_SpawnSplash(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, pad12; } Drip_8013DA0C;
typedef struct { s16 x, y, z; } V3_8013DA0C;
extern Drip_8013DA0C D_80141738_8013DA0C[4] asm("D_80141738");
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013DA0C;
extern M_8013DA0C D_801418D8_8013DA0C asm("D_801418D8");
typedef struct { u8 pad[0x28]; s32 y; u8 pad2C[0xB4 - 0x2C]; s32 f_B4; u8 padB8[0xE4 - 0xB8]; } Obj_8013DA0C;
extern Obj_8013DA0C g_Objects_8013DA0C[] asm("g_Objects");
s32 VectorNormalSS_8013DA0C(void *, void *) asm("VectorNormalSS");
s32 Object_AddAttackSphere_8013DA0C(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void Robot_DrawPart(s32 arg0);
s32 Shot_IsBelowFloor(void *arg0);
void Shot_SpawnTrail(SVECTOR *arg0);
void Shot_SpawnSplash(SVECTOR *arg0);

void Bomb_UpdateAll(void) {
    Drip_8013DA0C *p;
    M_8013DA0C *m;
    Obj_8013DA0C *o;
    s32 i;
    s32 r;
    V3_8013DA0C s;
    V3_8013DA0C v;

    m = &D_801418D8_8013DA0C;
    for (i = 3; i >= 0; i--) {
        p = &D_80141738_8013DA0C[i];
        if (p->active != 0) {
            p->active++;
            p->vy += p->grav;
            o = &g_Objects_8013DA0C[p->owner];
            Shot_SpawnTrail((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            r = Object_DetachLink(o, 0);
            if (Shot_IsBelowFloor(p) || o->y + 0x600 < p->y || r == 6) {
                v.x = p->x;
                v.y = p->y;
                v.z = p->z;
                s = v;
                Sound_PlayAt(0x4D, &s);
                p->active = 0;
                Shot_SpawnSplash((SVECTOR *)p);
                continue;
            }
            m->x = p->x;
            m->y = p->y;
            m->z = p->z;
            m->vx = p->vx;
            m->vy = p->vy;
            m->vz = p->vz;
            VectorNormalSS_8013DA0C(&m->vx, &m->vx);
            Robot_DrawPart(3);
            o->f_B4 = Object_AddAttackSphere_8013DA0C(o, 100, p->x, p->y, p->z, 0x201, 0x203);
        }
    }
}

void Bomb_InitPool(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80141738[i].f_C = 0;
    }
    Hook_Add(&Bomb_UpdateAll);
}

extern u8 D_801413F0[];

void func_8013DC58(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    Shockwave_Spawn(m, D_801413F0, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_8013DC94 asm("g_Game");
extern u8 D_8014139C[];

void func_8013DC94(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_8013DC94 & 1) {
        Shockwave_Spawn(m, D_8014139C, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8013DCE0(void *arg0) {
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

void func_8013DD60(void *arg0) {
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

void func_8013DE38(void *arg0) {
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

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 20; u32 mode : 2; u32 b26 : 6; } Flags_8013E150;
typedef struct { u16 start; u16 end; } Rng_8013E150;
extern struct { u8 pad_0[0x24]; u16 x; u16 p26; u16 y; u16 p2A; u16 z; } g_Spike_8013E150 asm("g_Spike");
void Object_ClampAnimFrame_8013E150(void *, s32) asm("Object_ClampAnimFrame");
void Object_PlaySound_8013E150(void *, s32) asm("Object_PlaySound");
void Object_TurnToward_8013E150(void *, s16, s16, s16, s16) asm("Object_TurnToward");
s32 Object_SpikeInFront(void *, s32, s32, s32);
void Object_OrbitHome(void *, s16);
void Object_InitOrbit(void *, s32);
void func_80058134_8013E150(void *, s32) asm("Object_DebugStub");
s32 func_80057140_8013E150(void *, s32, s32) asm("Object_AddAttachPoint");
void func_8013DC58(void *arg0);
void func_8013DC94(void *arg0);
void func_8013DCE0(void *arg0);
void func_8013DD60(void *arg0);
void func_8013DE38(void *arg0);
void Swooper_Hover(void *arg0);
void Swooper_ReturnHome(void *arg0);
void Swooper_StepDive(void *arg0);
s32 Swooper_CheckHit(void *arg0);

void Swooper_Update(u8 *o) {
    if (!M2C_FIELD(o, Flags_8013E150 *, 0xE0).init) {
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
        M2C_FIELD(o, Flags_8013E150 *, 0xE0).mode = 2;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013E150 **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, s32 *, 0x74) = func_80057140_8013E150(o, 0xA, 0x9C);
        M2C_FIELD(o, s32 *, 0x78) = func_80057140_8013E150(o, 6, 0x70);
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, Flags_8013E150 *, 0xE0).init = 1;
    }
    func_80058134_8013E150(o, M2C_FIELD(o, s16 *, 0x44));
    if (Swooper_CheckHit(o) == 0) {
        switch (M2C_FIELD(o, u8 *, 0x80)) {
        case 1:
            Object_OrbitHome(o, 8);
            Object_SeekHeight(o, 8);
            Swooper_Hover(o);
            if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
                func_8013DE38(o);
            }
            break;
        case 2:
            Object_ClampAnimFrame_8013E150(o, M2C_FIELD(o, Rng_8013E150 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            Object_TurnToward_8013E150(o, g_Spike_8013E150.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013E150.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
            func_8013DD60(o);
            func_8013DCE0(o);
            if (Object_Timer(o, -1) == 0) {
                M2C_FIELD(o, u8 *, 0x80) = 3;
                M2C_FIELD(o, s16 *, 0xA8) = 0;
                M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
                M2C_FIELD(o, u16 *, 0xBC) = g_Spike_8013E150.x;
                M2C_FIELD(o, u16 *, 0xC0) = g_Spike_8013E150.z;
                M2C_FIELD(o, u16 *, 0xBE) = g_Spike_8013E150.y - 0xC8;
                M2C_FIELD(o, u8 *, 0x8F) = 0;
                func_8013DC58(o);
            }
            break;
        case 3:
            Object_ClampAnimFrame_8013E150(o, M2C_FIELD(o, Rng_8013E150 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
                if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                    Object_PlaySound_8013E150(o, 0xA6);
                }
            }
            Swooper_StepDive(o);
            func_8013DD60(o);
            func_8013DCE0(o);
            func_8013DC94(o);
            break;
        case 4:
            Swooper_ReturnHome(o);
            break;
        }
    }
}

extern u8 D_80141788_8013E464[] asm("D_80141788");

void Robot_InitParts(void *arg0) {
    Shot_InitModel(arg0, D_80141788_8013E464, 0x85);
    Shot_InitModel(arg0, D_80141788_8013E464 + 0x70, 0x86);
    Shot_InitModel(arg0, D_80141788_8013E464 + 0xE0, 0xB4);
    Shot_InitModel(arg0, D_80141788_8013E464 + 0x150, 0x87);
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
    Bomb_InitPool();
}

typedef struct { u8 b[0x54]; } FxDef_411;
extern u32 g_Game_8013E4D8 asm("g_Game");
extern FxDef_411 D_80141444[][2];
void *memset(void *, s32, s32);

void Robot_SpawnGroundRings(void *arg0, s32 n) {
    SVECTOR w;
    SVECTOR v;

    if ((g_Game_8013E4D8 & 3) == 0) {
        memset(&v, 0, 8);
        v.vx = M2C_FIELD(arg0, u16 *, 0x9A);
        v.vy = M2C_FIELD(arg0, u16 *, 0x9C);
        v.vz = M2C_FIELD(arg0, u16 *, 0x9E);
        w = v;
        Shockwave_Spawn(&w, &D_80141444[n][0], 1, 0, 0);
        Shockwave_Spawn(&w, &D_80141444[n][1], 1, 0, 0);
    }
}

typedef struct { u8 pad0[0x5C]; u16 frame; } Anim_8013E5C0;
extern Anim_8013E5C0 D_80141788_8013E5C0 asm("D_80141788");
void Object_EnableCollision(void *);
void Robot_SpawnGroundRings(void *arg0, s32 n);

s32 func_8013E5C0(u8 *o) {
    Anim_8013E5C0 *a = &D_80141788_8013E5C0;

    switch (o[0x8F]) {
    case 0:
        if (++a->frame == 1) {
            o[0x7C] = Sound_ReserveSlot(0x70AE, 0x1000, o + 0x24);
        } else if (a->frame == 0x18) {
            Sound_FreeSlot(o[0x7C]);
            Object_PlaySound(o, 0x5C);
        }
        if (a->frame < 0x14) {
            Robot_SpawnGroundRings(o, 0);
        } else {
            Robot_SpawnGroundRings(o, 1);
        }
        if (a->frame >= 0x27) {
            o[0xC8] = 10;
            o[0x8F] = 1;
            o[0x7C] = Sound_ReserveSlot(0x70AE, 0x1000, o + 0x24);
            Object_EnableCollision(o);
            Object_Timer(o, 0xD);
        }
        return 0;
    case 1:
        Robot_SpawnGroundRings(o, 1);
        M2C_FIELD(o, s32 *, 0x28) -= 8;
        if (Object_Timer(o, -1) == 0) {
            Sound_FreeSlot(o[0x7C]);
            o[0x8F] = 2;
        }
        return 0;
    case 2:
        if (a->frame >= 0x37) {
            return 1;
        }
        if (++a->frame == 0x18) {
            Object_PlaySound(o, 0x5E);
        }
        return 0;
    }
    return 0;
}

typedef struct { s16 a[4]; } Q_8013E77C;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x2C]; u16 f_5C; u16 f_5E; Q_8013E77C rot; u8 pad_68[0x18]; u8 f_80; u8 pad_81[0x47]; u8 f_C8; u8 pad_C9[0x17]; s32 f_E0; } O_8013E77C;
extern O_8013E77C D_80141868_8013E77C asm("D_80141868");
void Robot_DrawPart(s32 arg0);

void func_8013E77C(O_8013E77C *arg0) {
    O_8013E77C *d = &D_80141868_8013E77C;
    u16 t;

    if (arg0->f_C8 == 0) {
        return;
    }
    if (!(arg0->f_E0 & 1)) {
        return;
    }
    if (arg0->f_5E == 1) {
        return;
    }
    d->x = arg0->x;
    d->y = arg0->y;
    d->z = arg0->z;
    d->rot = arg0->rot;
    t = d->f_5C;
    d->f_5C = t + 1;
    if (arg0->f_80 == 5) {
        if ((u16)(t - 2) >= 0x10) {
            d->f_5C = 4;
        }
    } else if ((u16)(t + 1) >= 4) {
        d->f_5C = 0;
    }
    Robot_DrawPart(2);
}

s32 Robot_CheckHit(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x1200) != 0)) {
        if ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) == 0x800) {
            return 1;
        }
        Object_PlaySound(arg0, 0x67);
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

void func_8013E8E4(void *arg0) {
    s32 temp_v1;
    u8 temp_a1;

    if (M2C_FIELD(arg0, u8 *, 0x81) != 0) {
        temp_a1 = M2C_FIELD(arg0, u8 *, 0xCF);
        if (temp_a1 == 1) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0xE0);
            if (!(temp_v1 & 1)) {
                M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 | 1);
                M2C_FIELD(arg0, s8 *, 0x80) = 2;
                M2C_FIELD(arg0, u8 *, 0x7F) = 0U;
                M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0);
                return;
            }
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 & ~1);
            M2C_FIELD(arg0, s8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = temp_a1;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x5E) = 2;
    }
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_80140298 asm("g_Spike");
void Object_SpawnEffect(void *, s16, s32, s32, s32);
void Object_TurnToward_8013E970(void *, s16, s16, s16, s16) asm("Object_TurnToward");
s32 func_8014018C_80140298() asm("Robot_CheckHit");

s32 func_8013E970(u8 *e) {
    SVECTOR v;
    SVECTOR t;

    if (e[0x80] != 5 && e[0x80] != 2 && func_8014018C_80140298()) {
        memset(&t, 0, 8);
        t.vx = M2C_FIELD(e, u16 *, 0x24);
        t.vy = M2C_FIELD(e, u16 *, 0x28);
        t.vz = M2C_FIELD(e, u16 *, 0x2C);
        v = t;
        Effect_SpawnAt(5, &v);
        Effect_SpawnAt(0x108, &v);
        M2C_FIELD(e, s16 *, 0x5E) = 0;
        if (e[0x81] != 0) {
            if (--e[0x81] != 0 && (M2C_FIELD(e, u32 *, 0xE0) & 1)) {
                e[0x80] = 5;
                e[0x7F] = 4;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[8];
                Object_PlaySound(e, 0x78);
            } else {
                e[0x81] = 0;
                Object_SpawnEffect(e, 0x102, 0, 300, 0);
                Object_PlaySound(e, 0x79);
                M2C_FIELD(e, s16 *, 0x5E) = 2;
                M2C_FIELD(e, s16 *, 0x96) = -0x5A;
                e[0x80] = 6;
                M2C_FIELD(e, s16 *, 0xD4) = M2C_FIELD(e, s16 *, 0xD6) = 0;
                M2C_FIELD(e, u32 *, 0xE0) &= ~1;
                e[0x7F] = 1;
                M2C_FIELD(e, u32 *, 0xE0) = (M2C_FIELD(e, u32 *, 0xE0) & 0xFF3FFFFF) | 0x400000;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
                Object_SetModel(e, 0x8D);
            }
            Object_TurnToward_8013E970(e, g_Spike_80140298.x - M2C_FIELD(e, u16 *, 0x24), g_Spike_80140298.z - M2C_FIELD(e, u16 *, 0x2C), 0, 0x1000);
            return 1;
        }
        Object_PlaySound(e, 0x60);
        return 1;
    }
    return 0;
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void Robot_DrawHeadLight(void *arg0, s32 on) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = p[1] + 0xF0;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Monkey_DrawHelmetLight(&v, 2, on != 0);
}

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013EBC4 asm("g_Spike");
s32 Vec_Length(s32, s32, s32);

s32 Robot_ThrowSpeed(void *arg0) {
    s32 d = Vec_Length(g_Spike_8013EBC4.x - M2C_FIELD(arg0, s32 *, 0x24), 0, g_Spike_8013EBC4.z - M2C_FIELD(arg0, s32 *, 0x2C));

    if (d < 0x400) {
        return 0x1E;
    }
    return d * 50 / 3584;
}

void func_8013EC50(void *arg0) {
    u8 temp_v0;

    if ((M2C_FIELD(arg0, u8 *, 0xC8) != 0) && (M2C_FIELD(arg0, u8 *, 0x80) != 7)) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x7D) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xC8), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x7D) >> 0xB)), 0, 0x100);
    }
}

void Effect_SpawnAt(s32, SVECTOR *);
void Object_PlaySound_8013F264(void *, s32) asm("Object_PlaySound");
s32 rcos_8013F264(s32) asm("rcos");
s32 rsin_8013F264(s32) asm("rsin");
extern u32 g_Game_8013F264 asm("g_Game");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013ED48(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    if (g_Game_8013F264 % 5 == 0 || g_Game_8013F264 % 17 == 0) {

        a = (M2C_FIELD(arg0, s16 *, 0xAC) + ((RAND() >> 8) << 12) / 510 + 0xC00) % 0x1000;
        v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F264(a) << 8) >> 12);
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) - ((RAND() >> 9) + 0xFA);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F264(a) << 8) >> 12);
        Effect_SpawnAt(0x102, &v);
        Object_PlaySound_8013F264(arg0, 0x4D);
        Object_PlaySound_8013F264(arg0, 0x6C);
    }
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013EEB4 asm("g_Spike");
extern u32 g_Game_8013EEB4 asm("g_Game");
extern u16 g_RandSeed2;
M2C_UNK func_80058134_8013EEB4(void *, s16) asm("Object_DebugStub");
void *func_80057140_8013EEB4(void *, s32, s32) asm("Object_AddAttachPoint");
void Fx_DebrisExplosion_8013EEB4(s32, s32, s32) asm("Fx_DebrisExplosion");
void Object_DisableCollision_8013EEB4(void *) asm("Object_DisableCollision");
void Object_FacePathPoint(void *, s32);
void Object_ClampAnimFrame(void *, s32);
void Object_TurnToward_8013EEB4(void *, s16, s16, s16, s16) asm("Object_TurnToward");
s32 Object_SpikeInFront_8013EEB4(void *, s32, s32, s16) asm("Object_SpikeInFront");
void Bomb_Throw(u8 *o, s16 side, s16 drop, s16 fwd, s32 aimed);
void Robot_InitParts(void *arg0);
s32 func_8013E5C0(u8 *o);
void func_8013E8E4(void *arg0);
s32 func_8013E970(u8 *e);
void Robot_DrawHeadLight(void *arg0, s32 on);
s32 Robot_ThrowSpeed(void *arg0);
void func_8013EC50(void *arg0);
void func_8013ED48(void *arg0);
#define ANIM_8013EEB4(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))
#define RAND_8013EEB4() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2_8013EEB4() (g_RandSeed2 = g_RandSeed2 * 5 + 1)

void Robot_Update(u8 *e) {
    SVECTOR v;

    if (!((M2C_FIELD(e, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(e, s16 *, 0x4A) = -0x3EFF;
        e[0x81] = 5;
        M2C_FIELD(e, s16 *, 0x48) = 0;
        e[0xC8] = 0;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(e, u32 *, 0xE0) = (M2C_FIELD(e, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x8000;
        M2C_FIELD(e, u32 *, 0xE0) &= ~1;
        M2C_FIELD(e, s16 *, 0x44) = 0xFA;
        M2C_FIELD(e, u32 *, 0xE0) &= ~1;
        { register u32 t asm("$3"); M2C_FIELD(e, s16 *, 0x46) = 0x1EA; t = M2C_FIELD(e, u32 *, 0xE0) | 0x2000; M2C_FIELD(e, u32 *, 0xE0) = t; }
        M2C_FIELD(e, void **, 0x74) = func_80057140_8013EEB4(e, 7, 0xD9);
        Object_DisableCollision_8013EEB4(e);
        e[0xDE] = 0;
        if (M2C_FIELD(e, u16 *, 0x8C) != 0) {
            Object_FacePathPoint(e, 1);
        }
        e[0x7F] = 2;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C);
        M2C_FIELD(e, u16 *, 0x9C) -= 0x68;
        M2C_FIELD(e, u16 *, 0x5C) = ANIM_8013EEB4(e, 2)[0];
        Robot_InitParts(e);
        M2C_FIELD(e, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013EEB4(e, M2C_FIELD(e, s16 *, 0x44));
    if (func_8013E970(e) == 0) {
        func_8013E8E4(e);
        e[0xCF] = 0;
        switch (e[0x80]) {
        case 5:
            if (M2C_FIELD(e, u16 *, 0x5C) >= ANIM_8013EEB4(e, e[0x7F])[1]) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_8013EEB4(e, 0)[0];
                Object_Timer(e, 0);
            }
            break;
        case 6:
            M2C_FIELD(e, s16 *, 0x5E) = 2;
            M2C_FIELD(e, u16 *, 0x96) += 7;
            M2C_FIELD(e, s32 *, 0x28) += M2C_FIELD(e, s16 *, 0x96);
            M2C_FIELD(e, u16 *, 0xD4) += 5;
            M2C_FIELD(e, u16 *, 0xD6) += 5;
            func_8013ED48(e);
            Object_ClampAnimFrame(e, ANIM_8013EEB4(e, e[0x7F])[1]);
            if (M2C_FIELD(e, s16 *, 0x9C) + 100 < M2C_FIELD(e, s32 *, 0x28)) {
                M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 100;
                e[0x80] = 7;
                Object_PlaySound(e, 0x4D);
                Fx_DebrisExplosion_8013EEB4(M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, s16 *, 0x28), M2C_FIELD(e, s16 *, 0x2C));
            }
            break;
        case 7:
            M2C_FIELD(e, s16 *, 0x5E) = 2;
            Object_ClampAnimFrame(e, ANIM_8013EEB4(e, e[0x7F])[1]);
            if (g_Game_8013EEB4 % 20 < 5) {
                v.vx = M2C_FIELD(e, u16 *, 0x24) + ((RAND2_8013EEB4() >> 8) - 0x80) * 2;
                v.vy = M2C_FIELD(e, u16 *, 0x28) - (RAND2_8013EEB4() >> 8) - 0x12C;
                v.vz = M2C_FIELD(e, u16 *, 0x2C) + ((RAND2_8013EEB4() >> 8) - 0x80) * 2;
                Effect_SpawnAt(7, &v);
                Puff_Spawn(e + 0x24, 1, 0, 0x100);
                if (((RAND_8013EEB4() >> 8) & 0xF) == 0) {
                    Object_PlaySound(e, 0x5B);
                }
            }
            break;
        case 2:
            if (!(M2C_FIELD(e, u32 *, 0xE0) & 1)) {
                e[0xC8] = 0;
                M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 0x68;
                Object_DisableCollision_8013EEB4(e);
                e[0xDE] = 0;
                Robot_InitParts(e);
                if (M2C_FIELD(e, s8 *, 0x7C) != -1) {
                    Sound_FreeSlot(M2C_FIELD(e, s8 *, 0x7C));
                }
                M2C_FIELD(e, s8 *, 0x7C) = -1;
            } else if (func_8013E5C0(e)) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_8013EEB4(e, 0)[0];
                Object_Timer(e, 15);
            }
            break;
        case 3:
            Object_TurnToward_8013EEB4(e, (s16)(g_Spike_8013EEB4.x - M2C_FIELD(e, u16 *, 0x24)), (s16)(g_Spike_8013EEB4.z - M2C_FIELD(e, u16 *, 0x2C)), 0, M2C_FIELD(e, s16 *, 0xB0));
            Robot_DrawHeadLight(e, 0);
            if (Object_Timer(e, -1) == 0 && Object_SpikeInFront_8013EEB4(e, 0x5A, 0xB50, 0x1200)) {
                e[0x80] = 4;
                e[0x7F] = 3;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_8013EEB4(e, 3)[0];
            }
            break;
        case 4:
            Object_TurnToward_8013EEB4(e, (s16)(g_Spike_8013EEB4.x - M2C_FIELD(e, u16 *, 0x24)), (s16)(g_Spike_8013EEB4.z - M2C_FIELD(e, u16 *, 0x2C)), 0, M2C_FIELD(e, s16 *, 0xB0));
            if (M2C_FIELD(e, u16 *, 0x5C) == ANIM_8013EEB4(e, e[0x7F])[0] + 15) {
                Bomb_Throw(e, 0, 0xC8, 0x1C2, 0);
            }
            Robot_DrawHeadLight(e, 1);
            if (M2C_FIELD(e, u16 *, 0x5C) >= ANIM_8013EEB4(e, e[0x7F])[1]) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_8013EEB4(e, 0)[0];
                Object_Timer(e, Robot_ThrowSpeed(e));
            }
            break;
        }
        func_8013EC50(e);
    }
    Robot_DrawPart(0);
    Robot_DrawPart(1);
    func_8013E77C(e);
}

s32 Object_AddAttackSphereNear_8013F484(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
void Dust_SpawnDrift(SVECTOR *);

void func_8013F484(void *arg0, s16 x, s16 y, s16 z) {
    SVECTOR v;

    v.vx = x;
    v.vy = y;
    v.vz = z;
    Dust_SpawnDrift(&v);
    Object_AddAttackSphereNear_8013F484(arg0, M2C_FIELD(arg0, u16 *, 0x44) + 0x32, v.vx, v.vy, v.vz,
                               M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
}

s32 Object_AddAttackSphereNear_8013F4F0(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
M2C_UNK Object_PlaySound_8013F4F0(s32, M2C_UNK) asm("Object_PlaySound");

s32 func_8013F4F0(void *arg0, s32 arg1, s32 arg2) {
    SVECTOR v;

    if (arg2 == 2) {
        Object_PlaySound_8013F4F0(arg0, 0x79);
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x1C);
    v.vy = M2C_FIELD(arg0, u16 *, 0x1E);
    v.vz = M2C_FIELD(arg0, u16 *, 0x20);
    Object_AddAttackSphereNear_8013F4F0(arg0, arg2 * 0x118 / arg1, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
    return arg2 == arg1;
}

void Orbiter_Init(void *arg0)
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
extern M2C_UNK D_800B1C28;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void Orbiter_Recover(void *arg0)
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
  Shockwave_Spawn(&v, &D_800B1C28, 1, 0xC, 0);
}

s32 Vec_Length(s32, s32, s32);
void Object_OrbitAround(void *, s16, s16, s16, s16);
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013EFE4 asm("g_Spike");

void Orbiter_Circle(void *arg0) {
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

void func_8013F484(void *arg0, s16 x, s16 y, s16 z);
s32 func_8013F4F0(void *arg0, s32 arg1, s32 arg2);
void Orbiter_Circle(void *arg0);
void Object_DebugStub(void *, s32);
void Object_Despawn(void *, s32);
void Object_DropPickups(void *);
typedef struct { u16 start; u16 end; } Rng_8013F7E0;

void Orbiter_Update(u8 *arg0) {
    u16 end;

    if (!(M2C_FIELD(arg0, u32 *, 0xE0) >> 3 & 1)) {
        Orbiter_Init(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (!(M2C_FIELD(arg0, u32 *, 0xE0) >> 2 & 1)) {
        func_8013F484(arg0, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), M2C_FIELD(arg0, s16 *, 0x20));
    }
    if (arg0[0x82] != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x96) > 0) {
            Orbiter_Recover(arg0);
        }
    } else {
        switch (arg0[0x80]) {
        case 1:
            Orbiter_Circle(arg0);
            break;
        case 2:
            end = M2C_FIELD(arg0, Rng_8013F7E0 **, 0x88)[arg0[0x7F]].end;
            if (M2C_FIELD(arg0, u16 *, 0x5C) == end) {
                arg0[0x8F]++;
                M2C_FIELD(arg0, u16 *, 0x5C) = end - 1;
                if (func_8013F4F0(arg0, 8, arg0[0x8F])) {
                    Object_Despawn(arg0, 1);
                    Object_DropPickups(arg0);
                }
            }
            break;
        }
    }
}

void Obj_StartLoopSound(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
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

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void Obj_BigExplosion(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

M2C_UNK Object_DisableCollision();
void func_80052038_80140F9C(void *, s32) asm("Object_SetModel");
void Obj_StartLoopSound(void *arg0);
void Obj_StopLoopSound(void *arg0);
void Obj_BigExplosion(void *arg0);

void TriggeredBlast_Update(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 0xFA;
        M2C_FIELD(o, s16 *, 0x46) = 0x200;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        M2C_FIELD(o, u8 *, 0x80) = 2;
        M2C_FIELD(o, u8 *, 0x7F) = 1;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        Object_EnableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        Object_PlaySound(o, 0x5C);
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, s16 *, 0xC2) = 0x12C;
            Obj_StartLoopSound(o);
            Obj_BigExplosion(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Obj_StopLoopSound(o);
            Object_PlaySound(o, 0x5E);
        }
        break;
    case 4:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80052038_80140F9C(o, 0x19);
            Object_DisableCollision(o);
        }
        break;
    }
}

s32 func_8013FC48(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_80141948[i].f_A = 0;
    }
    return 0;
}

typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Spark_411;

void func_8013FC70(SVECTOR *pos, s32 n) {
    s32 i;
    Spark_411 *p;
    s16 x;
    s16 y;
    s16 z;

    x = pos->vx;
    y = pos->vy;
    z = pos->vz;
    for (i = 63; i >= 0; i--) {
        p = &D_80141948[i];
        if (p->life == 0) {
            p->life = ((RAND() >> 8) & 0x1F) + 0x28;
            p->x = x + ((RAND() >> 8) - 0x80);
            p->y = y - ((RAND() >> 8) - 0x80);
            p->z = z + ((RAND() >> 8) - 0x80);
            p->vx = ((RAND() >> 8) - 0x80) / 4;
            p->vy = -((RAND() >> 8) & 0x3F) - 8;
            p->vz = ((RAND() >> 8) - 0x80) / 4;
            if (--n == 0) {
                return;
            }
        }
    }
}

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013FDF0;
typedef struct { Mat_8013FDF0 m; Mat_8013FDF0 w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013FDF0;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_8013FDF0;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013FDF0;
#define ADDPRIM_BF_8013FDF0(ot, p) (((PTag_8013FDF0 *)(p))->addr = ((PTag_8013FDF0 *)(ot))->addr, ((PTag_8013FDF0 *)(ot))->addr = (u32)(p))
#define gte_ldv3c_8013FDF0(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_8013FDF0() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_8013FDF0(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_8013FDF0(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Part_8013FDF0 D_80141948_8013FDF0[] asm("D_80141948");
extern Mat_8013FDF0 D_800E78C0_8013FDF0 asm("g_ViewMatrix");
extern u16 g_RandSeed_8013FDF0 asm("g_RandSeed");
extern GameDraw g_Game_8013FDF0 asm("g_Game");
void SetRotMatrix_8013FDF0(Mat_8013FDF0 *) asm("SetRotMatrix");
void SetTransMatrix_8013FDF0(Mat_8013FDF0 *) asm("SetTransMatrix");
void RotMatrixZYX_8013FDF0(SVECTOR *, Mat_8013FDF0 *) asm("RotMatrixZYX");
void CompMatrix_8013FDF0(Mat_8013FDF0 *, Mat_8013FDF0 *, Mat_8013FDF0 *) asm("CompMatrix");
#define SCR_8013FDF0 ((Scr_8013FDF0 *)0x1F800000)

s32 func_8013FDF0(void) {
    s32 i;
    s32 r;
    Part_8013FDF0 *e;
    u32 *p;
    u32 *ot;
    Scr_8013FDF0 *sc;

    sc = SCR_8013FDF0;
    sc->w = D_800E78C0_8013FDF0;
    r = ((u16)(g_RandSeed_8013FDF0 = g_RandSeed_8013FDF0 * 5 + 1) >> 8 & 0xF) + 8;
    sc->v[0][0].vx = -r;
    sc->v[0][0].vy = -r;
    sc->v[0][0].vz = 0;
    sc->v[0][1].vx = r;
    sc->v[0][1].vy = -r;
    sc->v[0][1].vz = 0;
    sc->v[0][2].vx = 0;
    sc->v[0][2].vy = r;
    sc->v[0][2].vz = 0;
    sc->v[1][0].vx = -r * 2;
    sc->v[1][0].vy = -r * 2;
    sc->v[1][0].vz = 0;
    sc->v[1][1].vx = r * 2;
    sc->v[1][1].vy = -r * 2;
    sc->v[1][1].vz = 0;
    sc->v[1][2].vx = 0;
    sc->v[1][2].vy = r * 2;
    sc->v[1][2].vz = 0;
    sc->v[2][0].vx = -r / 3;
    sc->v[2][0].vy = -r * 2;
    sc->v[2][0].vz = 0;
    sc->v[2][1].vx = r / 3;
    sc->v[2][1].vy = -r * 2;
    sc->v[2][1].vz = 0;
    sc->v[2][2].vx = 0;
    sc->v[2][2].vy = r * 3;
    sc->v[2][2].vz = 0;
    sc->v[3][0].vx = -r / 2;
    sc->v[3][0].vy = -r / 2;
    sc->v[3][0].vz = 0;
    sc->v[3][1].vx = r / 2;
    sc->v[3][1].vy = -r / 2;
    sc->v[3][1].vz = 0;
    sc->v[3][2].vx = 0;
    sc->v[3][2].vy = r / 2;
    sc->v[3][2].vz = 0;
    p = (u32 *)g_Game_8013FDF0.prim;
    ot = g_Game_8013FDF0.db[g_Game_8013FDF0.cur].ot;
    for (i = 63; i >= 0; i--) {
        e = &D_80141948_8013FDF0[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            e->vy += 3;
            sc->rot.vx = (e->life << 7) & 0xFFF;
            sc->rot.vy = (e->life << 7) & 0xFFF;
            sc->rot.vz = (e->life << 7) & 0xFFF;
            RotMatrixZYX_8013FDF0(&sc->rot, &sc->m);
            sc->m.t[0] = e->x;
            sc->m.t[1] = e->y;
            sc->m.t[2] = e->z;
            CompMatrix_8013FDF0(&sc->w, &sc->m, &sc->m);
            SetRotMatrix_8013FDF0(&sc->m);
            SetTransMatrix_8013FDF0(&sc->m);
            gte_ldv3c_8013FDF0(sc->v[i & 3]);
            gte_rtpt_8013FDF0();
            gte_stsxy3c_8013FDF0(sc->sxy);
            gte_stszotz_8013FDF0(&sc->z);
            if ((u32)(sc->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 6;
                p[1] = 0x32648080;
                p[3] = 0x405050;
                p[5] = 0x182020;
                p[2] = sc->sxy[0];
                p[4] = sc->sxy[1];
                p[6] = sc->sxy[2];
                ADDPRIM_BF_8013FDF0(ot + sc->z, p);
                p += 7;
                ((u8 *)p)[3] = 1;
                p[1] = 0xE1000220;
                ADDPRIM_BF_8013FDF0(ot + sc->z, p);
                p += 2;
            }
        }
    }
    g_Game_8013FDF0.prim = (u8 *)p;
    return 0;
}

M2C_UNK Shockwave_Spawn(s32, M2C_UNK *, M2C_UNK, M2C_UNK, s32);
extern M2C_UNK D_800B1C7C;

void func_8014022C(s32 arg0, s32 arg1) {
    func_8013FC70(arg0, 0x20);
    Shockwave_Spawn(arg0, &D_800B1C7C, 1, 0, arg1);
    Shockwave_Spawn(arg0, (u8 *)&D_800B1C7C + 0x2A0, 1, 0, arg1);
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801402A0 asm("g_Game");

s32 func_801402A0(s16 *p) {
    u8 *e = g_Game_801402A0.f_820C + p[2] * 0x38;
    s32 m;

    if (p[5] == 0) {
        m = p[7];
        p[1] = 0;
    } else {
        m = p[8];
        Link_Activate(p[6], p);
        p[1] = 1;
    }
    func_80140404(M2C_FIELD(e, s16 *, 0xE), m, p[7], p[8]);
    func_80140454(p, e, 0x80);
    return 0;
}

s32 func_80140350(void *arg0) {
    s16 temp_a1;
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if ((M2C_FIELD(arg0, s16 *, 2) == 0) && (M2C_FIELD(temp_s0, s16 *, 0x1E) >= 0)) {
        Link_Activate(M2C_FIELD(arg0, s16 *, 0xC), arg0);
        M2C_FIELD(arg0, s16 *, 2) = 1;
        func_80140454(arg0, temp_s0, 0x100);
        Sound_PlayAt(0x75, temp_s0);
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x10);
        func_80140404(M2C_FIELD(temp_s0, s16 *, 0xE), temp_a1, M2C_FIELD(arg0, s16 *, 0xE), temp_a1);
    }
    return 0;
}

extern u8 *g_StageMeshes;
void Model_BindStageMesh(void *, s32);

s32 func_80140404(s16 i, s16 m, s16 c, s16 d) {
    if (c >= 0 && d >= 0 && i >= 0) {
        Model_BindStageMesh(g_StageMeshes + i * 32, m);
    }
    return 0;
}

s32 func_80140454(s16 *p, s16 *v, s32 d) {
    switch (p[4]) {
    case 0x28:
        if (p[1] == 0) {
            v[2] -= d;
        } else {
            v[2] += d;
        }
        break;
    case 0x29:
        if (p[1] == 0) {
            v[0] -= d;
        } else {
            v[0] += d;
        }
        break;
    default:
        return 0;
    case 0x33:
        if (p[1] == 0) {
            v[1] -= d;
        } else {
            v[1] += d;
        }
        break;
    }
    return 0;
}

extern struct S_g_Game_80140538 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140538 asm("g_Game");

s32 func_80140538(s16 *p)
{
  s16 *new_var;
  u8 *e;
  e = g_Game_80140538.f_8220 + (6 * (4 * p[4]));
  new_var = p;
  if ((*((s16 *) (((s8 *) e) + 0x16))) > new_var[5])
  {
    p[1] = 2;
  }
  else
  {
    p[1] = 0;
  }
  return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x1C]; u16 f_8120; u8 pad_8122[0x2E]; u16 f_8150; u8 pad_8152[0xCE]; u8 *f_8220; } g_Game_80140590 asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_80140590(s16 *p) {
    u8 *e;

    switch (p[1]) {
    case 0:
        e = g_Game_80140590.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(e, s16 *, 0x16) > p[5] && g_Game_80140590.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_80140590.f_8150 == 0) {
            Link_Activate(p[7], p);
            Link_Activate(p[8], p);
            p[1] = 2;
            if (g_Game_80140590.f_8120 != 0x13) {
                if (p[6] > 0) {
                    CamFlyby_StartSegment(p[6] - 1);
                }
                g_Game_80140590.f_8100 = 7;
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_801406A0(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 2);
    M2C_FIELD(arg0, s16 *, 2) = 1;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(temp_v1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0x10) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 4);
    return 0;
}

void Link_MoveChainWith(s32, void *, s16 *);

s32 func_80140714(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;
    s16 f;

    switch (p[1]) {
    case 0:
        break;
    case 1:
        f = M2C_FIELD(e, s16 *, 0x32);
        if (f == 0x55 || f == 0xBD) {
            Sound_PlayAt(0x9C, e);
        }
        Link_MoveChainWith(p[5], e, p + 7);
        break;
    }
    return 0;
}

extern u8 *D_800B4DC4;

void Vehicle_ResetToStart(void) {
    u8 *o;

    o = D_800B4DC4;
    M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 0) = M2C_FIELD(o, s16 *, 0x78);
    M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 2) = M2C_FIELD(o, s16 *, 0x7A);
    M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 4) = M2C_FIELD(o, s16 *, 0x7C);
    M2C_FIELD(M2C_FIELD(o, u8 **, 0x70), u16 *, 0x18) &= 0x7FFF;
    M2C_FIELD(o, SVECTOR *, 0x60) = M2C_FIELD(o, SVECTOR *, 0x80);
    M2C_FIELD(o, s16 *, 0x6A) = 0x1000;
    M2C_FIELD(o, s16 *, 0x68) = 0;
    M2C_FIELD(o, s16 *, 0x6C) = 0;
    M2C_FIELD(o, u8 *, 0x8E) = 6;
}

typedef struct { u16 b0 : 1; u16 b1 : 3; } BF_8014085C;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8014085C;
typedef struct { u8 pad_0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad_22[2]; s32 x; s32 y; s32 z; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x14]; u32 f_50; u8 pad_54[0xC]; SVECTOR f_60; SVECTOR f_68; s32 f_70; u8 pad_74[0x90]; s16 f_104; s16 f_106; s32 f_108; s32 f_10C; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad_130[8]; s16 f_138; s16 f_13A; } Spike_8014085C;
typedef struct { u8 pad_0[0x14]; void *f_14; u8 pad_18[4]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad_22[2]; s32 x; s32 y; s32 z; u8 pad_30[0x5C]; u8 f_8C; u8 f_8D; s8 f_8E; u8 pad_8F; u8 f_90[4]; } Veh_8014085C;
extern Spike_8014085C g_Spike_8014085C asm("g_Spike");
extern Veh_8014085C *D_800B4DC4_8014085C asm("D_800B4DC4");
extern struct { u8 pad_0[0x8]; u8 *f_8; u8 pad_C[0x8146]; u16 f_8152; u8 pad_8154[0x104]; s16 f_8258; s16 f_825A; s16 f_825C; u8 pad_825E[2]; s16 f_8260; s16 f_8262; s16 f_8264; } g_Game_8014085C asm("g_Game");
extern struct { u8 pad_0[0xA1]; s8 f_A1; u8 pad_A2; s8 f_A3; u8 pad_A4[0xB4]; u32 f_158; u8 pad_15C[4]; u32 f_160; } g_Pad_8014085C asm("g_Pad");
extern struct { u8 pad_0[0x46]; u8 f_46; } D_800E68D0_8014085C asm("g_CameraState");
extern u8 D_800E6916_8014085C asm("D_800E6916");
extern SVECTOR D_800F4B30_8014085C[2] asm("g_JointAngles");
extern u32 D_800E5478_8014085C asm("D_800E5478");
extern u8 D_800F4730_8014085C[] asm("g_JointWorldMatrices");
extern u8 D_80141718_8014085C[] asm("D_80141718");
extern u8 D_80141720_8014085C[] asm("D_80141720");
extern u8 D_80141728_8014085C[] asm("D_80141728");
extern u8 D_800E9C60_8014085C[] asm("g_ModelMatrices");
extern u8 D_800E7D00_8014085C[] asm("g_ProjVerts");
s16 func_800433B0_8014085C(s32, s32, s32, s16 *) asm("Floor_GetHeightAndSlope");
s16 Water_Query_8014085C(s32, s32, s32) asm("Water_Query");
s32 rsin_8014085C(s32) asm("rsin");
s32 rcos_8014085C(s32) asm("rcos");
void *ApplyMatrixSV_8014085C(void *, void *, void *) asm("ApplyMatrixSV");
void func_80014804_8014085C(void *, void *) asm("Matrix_FromFacingXZ");
s32 VectorNormalSS_8014085C(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
s32 func_800463A4_8014085C(s32, s32, s32) asm("Math_StepToward");
void Matrix_LookAt_8014085C(void *, void *, void *, s32) asm("Matrix_LookAt");
void Model_CalcJointMatrices_8014085C(void *, s32) asm("Model_CalcJointMatrices");
void Model_ProjectBonedVerts_8014085C(void *) asm("Model_ProjectBonedVerts");
void func_80017CD4_8014085C(void *, void *, void *) asm("Model_Draw");
void func_8004637C_8014085C(void *) asm("Matrix_SetIdentity");
void *CompMatrix_8014085C(void *, void *, void *) asm("CompMatrix");
void Model_ProjectVerts_8014085C(void *, void *, void *) asm("Model_ProjectVerts");
void Effect_SpawnAt_8014085C(s32, void *) asm("Effect_SpawnAt");
void func_8006D548_8014085C(void *) asm("Dust_SpawnDrift");
void SetRotMatrix_8014085C(void *) asm("SetRotMatrix");
void SetTransMatrix_8014085C(void *) asm("SetTransMatrix");
void RotTransSV_8014085C(void *, void *, s32 *) asm("RotTransSV");
s32 Projectile_Spawn_8014085C(void *, void *, s32) asm("Projectile_Spawn");
u8 *Collision_GetShape_8014085C(s32) asm("Collision_GetShape");
s32 Sound_PlayFixed_8014085C(s32) asm("Sound_PlayFixed");
void Spike_SetPlayMode_8014085C(s32) asm("Spike_SetPlayMode");
void func_8004B83C_8014085C(void) asm("func_8004B83C");
void Camera_EnterAim_8014085C(void) asm("Camera_EnterAim");
void func_80048748_8014085C(void) asm("Camera_ExitRadarLive");
void Camera_ExitAim_8014085C(void) asm("Camera_ExitAim");
#define RAND_8014085C() (g_RandSeed = g_RandSeed * 5 + 1)

void Vehicle_UpdateDriving(void) {
    SVECTOR v;
    SVECTOR b;
    Mat_8014085C m;
    SVECTOR u;
    SVECTOR w;
    s32 flag;
    Veh_8014085C *veh;
    s32 a;
    s32 t0, t1, t2, x, y, z;
    u32 k;

    veh = D_800B4DC4_8014085C;
    g_Spike_8014085C.f_12C = func_800433B0_8014085C(g_Spike_8014085C.x, g_Spike_8014085C.y, g_Spike_8014085C.z, &g_Spike_8014085C.f_104);
    g_Spike_8014085C.f_114 = (g_Spike_8014085C.f_30 << 12) + g_Spike_8014085C.f_108;
    g_Spike_8014085C.f_11C = (g_Spike_8014085C.f_38 << 12) + g_Spike_8014085C.f_110;
    g_Spike_8014085C.f_13A = g_Spike_8014085C.f_138;
    g_Spike_8014085C.f_138 = Water_Query_8014085C(g_Spike_8014085C.x, g_Spike_8014085C.y, g_Spike_8014085C.z);
    g_Spike_8014085C.f_70 = 2;
    g_Spike_8014085C.f_128 = 0;
    g_Spike_8014085C.f_120 = 0;
    g_Spike_8014085C.f_110 = 0;
    g_Spike_8014085C.f_108 = 0;
    g_Spike_8014085C.f_10C += 0x7000;
    g_Spike_8014085C.f_124 = g_Spike_8014085C.f_118 = (g_Spike_8014085C.f_34 << 12) + g_Spike_8014085C.f_10C;
    *(volatile s32 *)&g_Spike_8014085C.f_10C = 0;
    if (D_800E6916_8014085C != 1 && g_Spike_8014085C.f_12C <= g_Spike_8014085C.y) {
        a = (-g_Pad_8014085C.f_A3 + g_Pad_8014085C.f_A1) / 4;
        m.m[0][0] = rcos_8014085C(a);
        m.m[0][1] = 0;
        m.m[0][2] = -rsin_8014085C(a);
        m.m[1][0] = 0;
        m.m[1][1] = 0x1000;
        m.m[1][2] = 0;
        m.m[2][0] = rsin_8014085C(a);
        m.m[2][1] = 0;
        m.m[2][2] = rcos_8014085C(a);
        if (g_Game_8014085C.f_8152 != 0xB) {
            ApplyMatrixSV_8014085C(&m, &g_Spike_8014085C.f_60, &g_Spike_8014085C.f_60);
        }
        func_80014804_8014085C(&g_Spike_8014085C.f_60, &m);
        v.vy = 0;
        v.vx = 0;
        v.vz = -(g_Pad_8014085C.f_A3 + g_Pad_8014085C.f_A1) / 2;
        ApplyMatrixSV_8014085C(&m, &v, &v);
        if (g_Game_8014085C.f_8152 != 0xB) {
            g_Spike_8014085C.f_108 += v.vx << 10;
            g_Spike_8014085C.f_110 += v.vz << 10;
        }
    }
    v.vy = 0x200;
    v.vx = -g_Spike_8014085C.f_104;
    v.vz = -g_Spike_8014085C.f_106;
    VectorNormalSS_8014085C(&v, &v);
    v.vx = func_800463A4_8014085C(g_Spike_8014085C.f_68.vx, v.vx, 0x40);
    v.vy = func_800463A4_8014085C(g_Spike_8014085C.f_68.vy, v.vy, 0x40);
    v.vz = func_800463A4_8014085C(g_Spike_8014085C.f_68.vz, v.vz, 0x40);
    t0 = g_Spike_8014085C.f_120 + g_Spike_8014085C.f_108;
    g_Spike_8014085C.f_120 = t0;
    t1 = g_Spike_8014085C.f_124 + g_Spike_8014085C.f_10C;
    t2 = g_Spike_8014085C.f_128 + g_Spike_8014085C.f_110;
    g_Spike_8014085C.f_124 = t1;
    g_Spike_8014085C.f_128 = t2;
    x = t0 / 4096;
    g_Spike_8014085C.f_30 = x;
    y = t1 / 4096;
    g_Spike_8014085C.f_34 = y;
    z = t2 / 4096;
    g_Spike_8014085C.f_38 = z;
    g_Spike_8014085C.f_108 = t0 - (x << 12);
    g_Spike_8014085C.f_10C = t1 - (y << 12);
    g_Spike_8014085C.f_110 = t2 - (z << 12);
    g_Spike_8014085C.f_114 = x;
    g_Spike_8014085C.f_11C = z;
    g_Spike_8014085C.f_118 = y;
    VectorNormalSS_8014085C(&v, &g_Spike_8014085C.f_68);
    if (D_800E68D0_8014085C.f_46 != 1) {
        Matrix_LookAt_8014085C(&g_Spike_8014085C.f_60, &g_Spike_8014085C.f_68, veh->f_14, 0);
        veh->x = g_Spike_8014085C.x;
        veh->y = g_Spike_8014085C.y;
        veh->z = g_Spike_8014085C.z;
        g_Spike_8014085C.f_1C = veh->f_1C = g_Spike_8014085C.x;
        g_Spike_8014085C.f_1E = veh->f_1E = g_Spike_8014085C.y - 0x80;
        g_Spike_8014085C.f_20 = veh->f_20 = g_Spike_8014085C.z;
        D_800F4B30_8014085C[0].vx = 0;
        D_800F4B30_8014085C[0].vy = 0;
        D_800F4B30_8014085C[0].vz = 0;
        D_800F4B30_8014085C[1].vx = 0;
        D_800F4B30_8014085C[1].vy = 0;
        D_800F4B30_8014085C[1].vz = 0;
        Model_CalcJointMatrices_8014085C(veh, 3);
        Model_ProjectBonedVerts_8014085C(veh);
        func_80017CD4_8014085C(g_Game_8014085C.f_8 + 0x80, D_800E7D00_8014085C, veh);
        func_8004637C_8014085C(&m);
        m.t[2] = 0x20;
        m.t[1] = -0xC8;
        CompMatrix_8014085C(D_800E9C60_8014085C, &m, &m);
        Model_ProjectVerts_8014085C(veh->f_90, &m, D_800E7D00_8014085C);
        func_80017CD4_8014085C(g_Game_8014085C.f_8, D_800E7D00_8014085C, veh->f_90);
    }
    if (veh->f_8E < 5 && D_800E68D0_8014085C.f_46 != 1) {
        u.vx = veh->f_1C + (((u16)RAND_8014085C() >> 8) - 0x80);
        u.vy = veh->f_1E - ((u16)RAND_8014085C() >> 9);
        u.vz = veh->f_20 + (((u16)RAND_8014085C() >> 8) - 0x80);
        Effect_SpawnAt_8014085C(7, &u);
        if (veh->f_8E < 3) {
            func_8006D548_8014085C(&u);
        }
    }
    if (g_Game_8014085C.f_8152 != 0xB) {
        if (D_800E6916_8014085C != 1) {
            if ((D_800E5478_8014085C & 0x400) && veh->f_8C >= 0x1F) {
                SetRotMatrix_8014085C(D_800F4730_8014085C);
                SetTransMatrix_8014085C(D_800F4730_8014085C);
                RotTransSV_8014085C(D_80141718_8014085C, &v, &flag);
                ApplyMatrixSV_8014085C(D_800F4730_8014085C, D_80141728_8014085C, &b);
                Projectile_Spawn_8014085C(&v, &b, 5);
                veh->f_8C = 0;
            } else {
                veh->f_8C++;
            }
            if ((D_800E5478_8014085C & 0x200) && veh->f_8D >= 6) {
                SetRotMatrix_8014085C(D_800F4730_8014085C);
                SetTransMatrix_8014085C(D_800F4730_8014085C);
                RotTransSV_8014085C(D_80141720_8014085C, &v, &flag);
                ApplyMatrixSV_8014085C(D_800F4730_8014085C, D_80141728_8014085C, &b);
                Projectile_Spawn_8014085C(&v, &b, 4);
                veh->f_8D = 0;
            } else {
                veh->f_8D++;
            }
        } else {
            w.vx = g_Game_8014085C.f_8260 - g_Game_8014085C.f_8258;
            w.vy = g_Game_8014085C.f_8262 - g_Game_8014085C.f_825A;
            w.vz = g_Game_8014085C.f_8264 - g_Game_8014085C.f_825C;
            VectorNormalSS_8014085C(&w, &w);
            if ((D_800E5478_8014085C & 0x400) && veh->f_8C >= 0x1F) {
                Projectile_Spawn_8014085C(&veh->f_1C, &w, 5);
                veh->f_8C = 0;
            } else {
                veh->f_8C++;
            }
            if ((D_800E5478_8014085C & 0x200) && veh->f_8D >= 6) {
                Projectile_Spawn_8014085C(&veh->f_1C, &w, 4);
                veh->f_8D = 0;
            } else {
                veh->f_8D++;
            }
        }
    }
    if (g_Spike_8014085C.y >= g_Spike_8014085C.f_12C) {
        s32 bb;
        u32 kk = *(u16 *)0x1F8003F8;
        bb = (kk >> 1) & 7;
        if ((kk & 1) && !bb) {
            veh->f_8E = 0;
        }
    }
    if ((g_Spike_8014085C.f_50 >> 28) == 0xB) {
        s32 dmg = M2C_FIELD(Collision_GetShape_8014085C(M2C_FIELD(&g_Spike_8014085C, u16 *, 0x50) & 0xFFF), u16 *, 0x24) & 0xF;
        veh->f_8E -= dmg;
        Sound_PlayFixed_8014085C(0x78);
    }
    if (veh->f_8E <= 0) {
        Spike_SetPlayMode_8014085C(0);
        return;
    }
    if (D_800E6916_8014085C != 1 && g_Game_8014085C.f_8152 != 0xB) {
        k = g_Pad_8014085C.f_158 & g_Pad_8014085C.f_160;
        if (k & 0xA) {
            Spike_SetPlayMode_8014085C(0);
            func_8004B83C_8014085C();
        } else if (k & 1) {
            Camera_EnterAim_8014085C();
            func_80048748_8014085C();
        }
    } else if ((g_Pad_8014085C.f_158 & g_Pad_8014085C.f_160) & 1) {
        Camera_ExitAim_8014085C();
    }
}

typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[4]; s16 px, py, pz; u8 pad22[2]; s32 x, y, z; u8 pad30[0x30]; SVECTOR rot; SVECTOR f68; u16 *f70; u16 f74; u8 pad76[0x18]; s8 hp; } Boss_80141128;
extern struct { u8 pad_0[0x8290]; u16 f_8290; } g_Game_80141128 asm("g_Game");
extern struct { s16 x, y, z; } g_JointAngles;
extern void *g_GameOt;
extern u8 D_800E7D00_80141128[] asm("g_ProjVerts");
s16 Floor_GetHeight_80141128(s32, s32, s32) asm("Floor_GetHeight");
void Matrix_LookAt(void *, void *, void *, s32);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts_80141128(void *) asm("Model_ProjectBonedVerts");
void Model_Draw(void *, void *, void *);
s32 Sound_PlayFixed_80141128(s32) asm("Sound_PlayFixed");
void Fx_DebrisExplosion(s32, s32, s32);
void Vehicle_ResetToStart(void);

void Vehicle_UpdateParked(s32 arg0) {
    Boss_80141128 *b = D_800B4DC4;
    s32 h;
    u16 k;
    s32 j;
    SVECTOR v;

    if (arg0 == 1) {
        Vehicle_ResetToStart();
        return;
    }
    g_Game_80141128.f_8290 = b->f74;
    h = Floor_GetHeight_80141128(b->x, b->y, b->z);
    if (b->y < h) {
        if (h - b->y > 0x20) {
            b->y += 0x20;
        } else {
            b->y = h;
        }
        b->f70[1] = b->y;
    } else {
        k = *(u16 *)0x1F8003F8;
        j = (k >> 1) & 7;
        if ((k & 1) && j == 0) {
            b->hp = 0;
        }
        b->y = h;
        b->f70[1] = b->y;
    }
    b->px = b->x;
    b->py = b->y - 0x80;
    b->pz = b->z;
    Matrix_LookAt(&b->rot, &b->f68, b->mat, 0);
    g_JointAngles.x = 0;
    g_JointAngles.y = 0;
    g_JointAngles.z = 0;
    Model_CalcJointMatrices(b, 1);
    Model_ProjectBonedVerts_80141128(b);
    Model_Draw(g_GameOt, D_800E7D00_80141128, b);
    if (b->hp <= 0) {
        Sound_PlayFixed_80141128(0x79);
        Fx_DebrisExplosion(b->px, b->py, b->pz);
        Vehicle_ResetToStart();
        return;
    }
    if (b->hp < 5) {
        v.vx = b->px + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        v.vy = b->py - ((g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        v.vz = b->pz + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        Effect_SpawnAt(7, &v);
        if (b->hp < 3) {
            Dust_SpawnDrift(&v);
        }
    }
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
