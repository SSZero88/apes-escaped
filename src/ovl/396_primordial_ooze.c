#include "common.h"
#include "m2c_macros.h"

s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
extern s32 D_800EC208;

s32 rsin(s16, s32);
extern struct S_D_800E77A0 { u8 pad_0[0x8]; s16 f_8; s16 f_A; s16 f_C; } D_800E77A0;
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);

extern u16 g_RandSeed;
extern s32 D_8013F1C0;
void Shockwave_Spawn(void *, s32 *, s32, s32, s32);

void func_8013D000(u8 *a) {
    SVECTOR v;

    if (((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x3F) == 0) {
        v.vx = M2C_FIELD(a, u16 *, 0x24) - ((M2C_FIELD(a, s16 *, 0x60) * 25) >> 9);
        v.vy = M2C_FIELD(a, u16 *, 0x28);
        v.vz = M2C_FIELD(a, u16 *, 0x2C) - ((M2C_FIELD(a, s16 *, 0x64) * 25) >> 9);
        Shockwave_Spawn(&v, &D_8013F1C0, 1, 0, 0);
    }
}

s16 func_8013D0B0(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_a0;
    u16 temp_v0_3;
    void *temp_v0_2;

    temp_v0_2 = (M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88);
    temp_v0_3 = M2C_FIELD(temp_v0_2, u16 *, 0);
    temp_a1 = M2C_FIELD(temp_v0_2, u16 *, 2) - temp_v0_3;
    temp_lo = (s32) (((s32) (M2C_FIELD(arg0, u16 *, 0x5C) - temp_v0_3) % temp_a1) << 0xC) / temp_a1;
    temp_v0 = temp_lo + 0xC00;
    var_a0 = temp_v0;
    if (temp_v0 < 0) {
        var_a0 = temp_lo + 0x1BFF;
    }
    return (s16) (((s32) (rsin((s16) (temp_v0 - ((var_a0 >> 0xC) << 0xC)), temp_a1) * (arg1 - arg2)) >> 0xD) + ((s32) (arg1 + arg2) / 2));
}

s32 func_8013D1C4(void) {
    s32 var_a0;
    s32 var_v0;

    var_v0 = D_800E77A0.f_A - D_800EC208;
    var_v0 = __builtin_abs(var_v0);
    var_a0 = 0;
    if (var_v0 < 0x32) {
        var_a0 = Spike_WithinRadiusXZ(D_800E77A0.f_8, D_800E77A0.f_C, 0xC8) != 0;
    }
    return var_a0;
}

s32 func_8013D224(void) {
    s32 var_v0;
    s32 var_v0_2;

    var_v0_2 = D_800E77A0.f_A - D_800EC208;
    var_v0_2 = __builtin_abs(var_v0_2);
    if ((var_v0_2 >= 0x33) || (var_v0 = 0, (Spike_WithinRadiusXZ(D_800E77A0.f_8, D_800E77A0.f_C, 0xFA) == 0))) {
        var_v0 = 1;
    }
    return var_v0;
}

typedef struct { u16 start; u16 end; } Rng_8013D294;
void Object_PlaySound_8013D294(void *, s32) asm("Object_PlaySound");
s32 func_8013D1C4_8013D294(void *) asm("func_8013D1C4");
s32 func_8013D224(void);

void func_8013D294(void *arg0) {

    if (M2C_FIELD(arg0, u32 *, 0xE0) & 1) {
        if (func_8013D224() != 0) {
            if (M2C_FIELD(arg0, u8 *, 0x7F) != 1) {
                M2C_FIELD(arg0, u8 *, 0x7F) = 1;
                M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[2];
            }
            M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
        }
    } else if (func_8013D1C4_8013D294(arg0) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0x7F) != 1) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 1;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[2];
        }
        M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
    }
    if (M2C_FIELD(arg0, u8 *, 0x7F) == 1) {
        if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, Rng_8013D294 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F)].start + 0xF) {
            Object_PlaySound_8013D294(arg0, 0xAD);
        } else if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, Rng_8013D294 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F)].end) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        }
    }
}

void func_8013D3B8(void *arg0) {
    D_800E77A0.f_A = (s16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0xB4);
    D_800E77A0.f_8 = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x60) * 0x96) >> 0xC));
    D_800E77A0.f_C = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) -(M2C_FIELD(arg0, s16 *, 0x64) * 0x96) >> 0xC));
}

void func_8013D430(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (temp_v0 - 1);
        return;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x8F) = 0xAU;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere(arg0, 0xC8, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xAF) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xFA), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0xAF) >> 0xB)), 0, 0x101);
}

extern struct { u8 pad0[0x820C]; u8 *f_820C; } g_Game_8013D518 asm("g_Game");
void Object_PlaceAtPathPoint(void *, s32);
void Object_FacePathPoint(void *, s32);
void Object_FollowPath(void *, s32, s32, s32);
void Object_ApplyVelocity(void *);

void func_8013D518(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(arg0, u8 *, 0x8E) = 0;
        M2C_FIELD(arg0, s16 *, 0x44) = 0;
        M2C_FIELD(arg0, s16 *, 0x48) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
        if (M2C_FIELD(arg0, u16 *, 0x8C) != 0) {
            Object_PlaceAtPathPoint(arg0, 0);
            Object_FacePathPoint(arg0, 1);
        }
        M2C_FIELD(arg0, u32 *, 0xE0) |= 0x40;
        M2C_FIELD(g_Game_8013D518.f_820C + M2C_FIELD(arg0, u16 *, 0x70) * 0x38, s16 *, 6) = 0xFA;
        M2C_FIELD(g_Game_8013D518.f_820C + M2C_FIELD(arg0, u16 *, 0x70) * 0x38, s16 *, 0xA) = 0xFA;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_8013D3B8(arg0);
    func_8013D000(arg0);
    Object_FollowPath(arg0, func_8013D0B0(arg0, 0x14, 8), 0, 0);
    Object_ApplyVelocity(arg0);
    func_8013D294(arg0);
    func_8013D430(arg0);
}

void func_8013D660(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_8013F340[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void func_8013D700(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_8013F340 + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game.f_80 + g_Game.f_C * 0x4078, &g_ProjVerts, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_8013F2A0");
void func_8013DA94(void);
void Hook_Add(void *);

void func_8013D7C8(void *arg0) {
    s32 i;

    func_8013D660(arg0, D_8013F340, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(func_8013DA94);
}

s32 func_8013D81C(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

s16 rcos(s16);
s16 rsin_8013D858(s16) asm("rsin");
extern u8 D_8013F2A0[];

void func_8013D858(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = func_8013D81C();
  if (i != (-1))
  {
    p = D_8013F2A0 + (i * 0x14);
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

s32 func_8013D990(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013D9CC(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013DA0C(SVECTOR *p) {
    SVECTOR v;
    s32 i;

    v.vx = p->vx;
    v.vy = p->vy;
    v.vz = p->vz;
    for (i = 0; i < 16; i++) {
        Effect_SpawnAt(10, &v);
        if (i & 1) {
            Effect_SpawnAt(0x16, &v);
        }
    }
    Effect_SpawnAt(5, &v);
    Effect_SpawnAt(0x108, &v);
}

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x88]; s32 fB4; u8 padB8[0x2C]; } Obj_8013DA94;
extern Obj_8013DA94 g_Objects_8013DA94[] asm("g_Objects");
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; SVECTOR dir; } Mdl_8013DA94;
extern Mdl_8013DA94 D_8013F340_8013DA94 asm("D_8013F340");
void VectorNormalSS(void *, void *);
void Object_PlaySound(void *, s32);

void func_8013DA94(void) {
    Drip_396 *p;
    Obj_8013DA94 *o;
    s32 i;
    Mdl_8013DA94 *m;

    m = &D_8013F340_8013DA94;
    for (i = 7; i >= 0; i--) {
        p = &D_8013F2A0_s[i];
        if (p->active != 0) {
            p->active++;
            p->vy += 4;
            o = &g_Objects_8013DA94[p->unkE];
            func_8013D9CC((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (Object_DetachLink(o, 0) == 6) {
                p->active = 0;
                func_8013DA0C((SVECTOR *)p);
                Object_PlaySound(o, 0x6B);
            } else if (func_8013D990(p) != 0 || o->y + 0x600 < p->y) {
                p->active = 0;
                func_8013DA0C((SVECTOR *)p);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->dir.vx = p->vx;
                m->dir.vy = p->vy;
                m->dir.vz = p->vz;
                VectorNormalSS(&m->dir, &m->dir);
                func_8013D700(0, 3);
                o->fB4 = Object_AddAttackSphere(o, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013DC70(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void Object_ApplyHit(void *);
void Object_HitFeedback(void *);
void Object_SpawnHitSpark(void *, s32, s32, s32);

void func_8013DC9C(void *arg0) {
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

void func_8013DD2C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013DC70(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

void Object_PlaySound(void *, s32);

void func_8013DDBC(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        func_8013D858(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

void Object_DisableCollision(void *);
s32 Object_Timer(void *, s32);

void func_8013DE20(void *arg0) {
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

s32 func_8013DEF8(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        func_8013DC70(arg0);
        return 1;
    }
    return 0;
}

void func_8013DE20(void *arg0);
void func_8013D7C8(void *arg0);
void func_8013DC70(void *arg0);
void func_8013DC9C(void *arg0);
void func_8013DD2C(void *arg0);
void func_8013DDBC(void *arg0);
s32 func_8013DEF8(void *arg0);
void Object_EnableCollision(void *);
void Object_DebugStub(void *, s32);
s16 Object_FloorAt(void *, s16, s16, s16);
void Shadow_Draw(void *, s32, s32, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);
#define ANIM_8013DF54(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_8013DF54(u8 *o) {
    s32 st;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013DE20(o);
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u8 *, 0xC9) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        func_8013D7C8(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (st = M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        Shadow_Draw(o + 0x24, Object_FloorAt(o, 0, 0, 0), M2C_FIELD(o, s16 *, 0xA0), M2C_FIELD(o, s32 *, 0xD0));
        if (Object_Timer(o, -1) == 0
            && Object_SpikeOutOfRange(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s16 *, 0x9E), 1500) == 0) {
            func_8013DD2C(o);
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
        if (func_8013DEF8(o) == 0) {
            if (M2C_FIELD(o, u16 *, 0x5C) == ANIM_8013DF54(o, M2C_FIELD(o, u8 *, 0x7F))[0] + 20) {
                func_8013DDBC(o);
            }
            if (M2C_FIELD(o, u8 *, 0x8F) >= 3) {
                M2C_FIELD(o, u8 *, 0x80) = 6;
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 0)[0];
                func_8013DC70(o);
            }
        }
        break;
    case 6:
        Object_DisableCollision(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013DF54(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013DF54(o, 1)[0];
            func_8013DC70(o);
            Object_Timer(o, 60);
        }
        break;
    }
    func_8013DC9C(o);
}

typedef struct { s16 f0; s16 x, y, z; s16 f8; u16 fA; u8 padC[4]; } Src_8013E1E0;
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 padF[9]; s16 f18; s16 f1A; u8 pad1C[4]; } Pt_8013E1E0;
extern struct { u8 pad0[0x824C]; u8 *f_824C; } g_Game_8013E1E0 asm("g_Game");
extern u8 D_8013F7B0;
extern Pt_8013E1E0 D_8013F3B0[];
s32 Floor_GetHeight_8013E1E0(s32, s32, s32) asm("Floor_GetHeight");

s32 func_8013E1E0(void) {
    u8 *h;
    Src_8013E1E0 *src;
    s32 i;

    h = g_Game_8013E1E0.f_824C;
    D_8013F7B0 = 0;
    src = (Src_8013E1E0 *)(h + 8);
    if (*(u16 *)h == 0x452E && h[2] == 0x46) {
    } else {
        return 1;
    }
    D_8013F7B0 = h[4];
    if (D_8013F7B0 > 32) {
        D_8013F7B0 = 32;
    }
    for (i = 0; i < D_8013F7B0; i++) {
        D_8013F3B0[i].fE = 0;
        D_8013F3B0[i].x8 = D_8013F3B0[i].x = src[i].x;
        D_8013F3B0[i].yA = D_8013F3B0[i].y = src[i].y;
        D_8013F3B0[i].zC = D_8013F3B0[i].z = src[i].z;
        D_8013F3B0[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x200, src[i].z);
        if (D_8013F3B0[i].floor < src[i].y) {
            D_8013F3B0[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x1000, src[i].z);
        }
        D_8013F3B0[i].f18 = 1;
        D_8013F3B0[i].f1A = src[i].fA;
    }
    return 0;
}

#include "gte.h"
#define gte_stszotz_8013E33C(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
void SetRotMatrix(void *);
void SetTransMatrix(void *);
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 fF; s16 f10; s16 f12; s16 f14; u8 f16; u8 f17; s16 f18; s16 f1A; u32 w; } Drop_8013E33C;
typedef struct { s32 otz; s32 sxy; } Scr_8013E33C;
typedef struct { u32 tag; u32 code; s32 xy0; u32 uv0; s32 xy1; u32 uv1; s32 xy2; u16 uv2; u16 pad2; s32 xy3; u16 uv3; u16 pad3; } Ft4_8013E33C;
extern u8 D_8013F7B0_8013E33C asm("D_8013F7B0");
extern Drop_8013E33C D_8013F3B0_8013E33C[] asm("D_8013F3B0");
extern u8 D_800E78C0_8013E33C[] asm("g_ViewMatrix");
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; } g_Game_8013E33C asm("g_Game");

s32 func_8013E33C(void) {
    Scr_8013E33C *sc = (Scr_8013E33C *)0x1F800000;
    Drop_8013E33C *e;
    Ft4_8013E33C *p;
    u32 *ot;
    s32 i;
    s32 otz;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 x0;
    register u32 mask asm("$15");
    register u32 c9 asm("$19");
    register u32 cuv0 asm("$18");
    register u32 cuv1 asm("$25");
    s16 y0;

    if (D_8013F7B0_8013E33C == 0) {
        return 0;
    }
    for (i = 0, e = D_8013F3B0_8013E33C; i < D_8013F7B0_8013E33C; i++, e++) {
        if (e->fE == 0) {
            if (--e->f18 == 0) {
                e->fF = 0;
                e->fE = 1;
                e->f18 = e->f1A;
                e->x = e->x8;
                e->y = e->yA;
                e->z = e->zC;
                e->f14 = 0;
                e->f10 = 0;
                e->f12 = 0;
                e->f16 = 0;
                (&D_8013F3B0_8013E33C[0].w)[i * 8] = 0x170F60C0;
            }
        }
    }
    for (i = 0, e = D_8013F3B0_8013E33C; i < D_8013F7B0_8013E33C; i++, e++) {
        if (e->fE != 0) {
            switch (e->f16) {
            case 0:
                if (e->fF == 10) {
                    ((u8 *)&e->w)[0] += 0x10;
                }
                if (e->fF == 0x22) {
                    ((u8 *)&e->w)[0] += 0x10;
                }
                if (e->fF >= 0x22) {
                    e->f12 += 0xF;
                    if (e->f12 > 0x60) {
                        e->f12 = 0x60;
                    }
                    e->y += e->f12;
                    if (e->floor < e->y) {
                        e->y = e->floor;
                        e->fF = 0;
                        e->w = 0x70F20B0;
                        e->f16++;
                    }
                }
                break;
            case 1:
                ((u8 *)&e->w)[1] += 8;
                if (e->fF >= 3) {
                    e->fE = 0;
                }
                break;
            }
            e->fF++;
        }
    }
    SetRotMatrix(D_800E78C0_8013E33C);
    SetTransMatrix(D_800E78C0_8013E33C);
    p = (Ft4_8013E33C *)g_Game_8013E33C.prim;
    ot = (u32 *)(g_Game_8013E33C.cur * 0x4078 + (u8 *)&g_Game_8013E33C + 0x80);
    i = 0;
    e = D_8013F3B0_8013E33C;
    if (i < D_8013F7B0_8013E33C) {
    c9 = 9;
    cuv0 = 0x7CAC0000;
    cuv1 = 0x3C0000;
    mask = 0xFFFFFF;
    do {
        if (e->fE == 0) {
            continue;
        }
        gte_ldv0(e);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        gte_stszotz_8013E33C(&sc->otz);
        otz = sc->otz;
        if ((u32)(otz - 1) >= 0x7FF) {
            continue;
        }
        y = sc->sxy >> 16;
        x = sc->sxy;
        if ((u16)(x + 0x20) >= 0x1C1 || y < -0x20 || y >= 0x111) {
            continue;
        }
        w = 0xCD0 / otz;
        h = 0xC2C / otz;
        x0 = x - w / 2;
        y0 = y - h / 2;
        switch (e->f16) {
        case 0:
            p->code = 0x2E5A3728;
            ((u8 *)p)[3] = c9;
            p->xy0 = (y0 << 16) | (x0 & 0xFFFF);
            p->xy1 = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p->xy2 = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p->xy3 = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p->uv0 = ((((u8 *)&e->w)[1] << 8) | ((u8 *)&e->w)[0]) | cuv0;
            p->uv1 = ((((u8 *)&e->w)[1] << 8) | (((u8 *)&e->w)[0] + 0xF)) | cuv1;
            p->uv2 = ((u8 *)&e->w)[0] | ((((u8 *)&e->w)[1] + 0x17) << 8);
            p->uv3 = ((((u8 *)&e->w)[1] + 0x17) << 8) | (((u8 *)&e->w)[0] + 0xF);
            p->tag = (p->tag & 0xFF000000) | (ot[sc->otz] & mask);
            ot[sc->otz] = (ot[sc->otz] & 0xFF000000) | ((u32)p & mask);
            p++;
            break;
        case 1:
            p->code = 0x2E6E4B3C;
            ((u8 *)p)[3] = c9;
            p->xy0 = (y0 << 16) | (x0 & 0xFFFF);
            p->xy1 = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p->xy2 = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p->xy3 = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p->uv0 = ((((u8 *)&e->w)[1] << 8) | ((u8 *)&e->w)[0]) | cuv0;
            p->uv1 = ((((u8 *)&e->w)[1] << 8) | (((u8 *)&e->w)[0] + 0xF)) | cuv1;
            p->uv2 = ((u8 *)&e->w)[0] | ((((u8 *)&e->w)[1] + 7) << 8);
            p->uv3 = ((((u8 *)&e->w)[1] + 7) << 8) | (((u8 *)&e->w)[0] + 0xF);
            p->tag = (p->tag & 0xFF000000) | (ot[sc->otz] & mask);
            ot[sc->otz] = (ot[sc->otz] & 0xFF000000) | ((u32)p & mask);
            p++;
            break;
        }
        } while (i++, e++, i < D_8013F7B0_8013E33C);
    }
    g_Game_8013E33C.prim = (u8 *)p;
    return 0;
}

#define gte_stszotz_8013E950(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
s32 Water_Query(s32, s32, s32);
typedef struct { s16 x, y, z; s8 state; u8 speed; } Drop_8013E950;
typedef struct { u8 pad0[8]; s32 sx; s32 sy; s32 otz; s32 sxy; s32 sxy2; u16 seed1; u16 seed2; SVECTOR v; SVECTOR cam; } Scr_8013E950;
extern Drop_8013E950 D_8013F7B8_8013E950[] asm("D_8013F7B8");
extern s16 D_8013FEE8_8013E950[2] asm("D_8013FEE8");
extern u8 D_800E6908_8013E950 asm("D_800E6908");
extern u32 D_800EC250_8013E950 asm("D_800EC250");
extern u8 D_800E78C0_8013E950[] asm("g_ViewMatrix");
extern u16 g_RandSeed_8013E950 asm("g_RandSeed");
extern u16 D_800AE8F2_8013E950 asm("g_RandSeed2");
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; u8 pad10[0x8258 - 0x10]; SVECTOR cam; s16 x, y, z; } g_Game_8013E950 asm("g_Game");

s32 func_8013E950(void) {
    Scr_8013E950 *sc = (Scr_8013E950 *)0x1F800000;
    Drop_8013E950 *e;
    u8 *p;
    u32 *ot;
    s32 i;
    s32 w;
    s32 h;
    s16 wx;
    s16 wz;
    s16 ground;
    s32 s;
    s32 xy;
    s32 sx;
    register u32 mask asm("$11");
    register s32 one asm("$24");
    SVECTOR *sv;
    s32 g;
    s32 wq;

    sc->cam = g_Game_8013E950.cam;
    sc->v.vx = g_Game_8013E950.x - sc->cam.vx;
    sc->v.vy = g_Game_8013E950.y - sc->cam.vy;
    sc->v.vz = g_Game_8013E950.z - sc->cam.vz;
    wx = D_8013FEE8_8013E950[0];
    wz = D_8013FEE8_8013E950[1];
    VectorNormalSS(&sc->v, &sc->v);
    sc->cam.vx += sc->v.vx >> 2;
    sc->cam.vy += sc->v.vy >> 2;
    sc->cam.vz += sc->v.vz >> 2;
    wq = (u16)Water_Query(sc->cam.vx, sc->cam.vy + 500, sc->cam.vz) >> 12;
    if ((D_800E6908_8013E950 == 1 && wq != 0) || (D_800EC250_8013E950 & 0xF0) == 0xC0 || ((D_800EC250_8013E950 & 0xF0) == 0x40 && wq != 0)) {
        ground = -0x80D;
    } else {
        ground = -0xA0D;
    }
    D_8013FEE8_8013E950[1] = -3;
    D_8013FEE8_8013E950[0] = -3;
    sc->seed1 = g_RandSeed_8013E950;
    sc->seed2 = D_800AE8F2_8013E950;
    SetRotMatrix(D_800E78C0_8013E950);
    SetTransMatrix(D_800E78C0_8013E950);
    p = g_Game_8013E950.prim;
    ot = (u32 *)(g_Game_8013E950.cur * 0x4078 + (u8 *)&g_Game_8013E950 + 0x80);
    for (i = 0xE5, e = D_8013F7B8_8013E950, one = 1, g = ground, sv = &sc->v, mask = 0xFFFFFF; i >= 0; i--, e++) {
        if (e->state == 0) {
            e->state = 1;
            e->x = (((sc->seed1 = sc->seed1 * 5 + 1) >> 8) - 0x80) * 16 + (((sc->seed2 = sc->seed2 * 5 + 1) >> 8) - 0x80) * 4;
            e->z = (((sc->seed1 = sc->seed1 * 5 + 1) >> 8) - 0x80) * 16 + (((sc->seed2 = sc->seed2 * 5 + 1) >> 8) - 0x80) * 4;
            e->y = -0x258;
            sc->seed1 = sc->seed1 * 5 + 1;
            e->speed = ((sc->seed1 >> 8) & 0x3F) + 0x80;
        }
        if (e->state == one) {
            e->x += wx;
            e->y += e->speed;
            e->z += wz;
            if (g < sc->cam.vy + e->y) {
                if ((u16)(e->x + 0x3FF) < 0x7FF && e->z >= -0x3FF && e->z < 0x400) {
                    e->y = ground - sc->cam.vy;
                    e->state = 2;
                    sc->seed1 = sc->seed1 * 5 + 1;
                    sc->seed2 = sc->seed2 * 5 + 1;
                } else {
                    e->state = 0;
                    continue;
                }
            }
        }
        sc->v.vx = sc->cam.vx + e->x;
        sc->v.vy = sc->cam.vy + e->y;
        sc->v.vz = sc->cam.vz + e->z;
        gte_ldv0(sv);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        gte_stszotz_8013E950(&sc->otz);
        xy = sc->sxy;
        __asm__ volatile("" : "=r"(sx) : "0"(xy));
        xy >>= 16;
        __asm__ volatile("" : "+r"(xy), "+r"(sx));
        sc->sx = sx & 0xFFFF;
        sc->sy = xy;
        if ((u32)(sc->sx + 0xC0) >= 0x301 || sc->otz <= 0 || sc->otz >= 0x800) {
            e->state = 0;
            continue;
        }
        s = e->state;
        if (s == one) {
            sc->v.vx -= wx;
            sc->v.vy -= (e->speed * 3) >> 1;
            sc->v.vz -= wz;
            gte_ldv0(sv);
            gte_rtps();
            gte_stsxy(&sc->sxy2);
            p[3] = 5;
            *(u32 *)(p + 4) = 0xE100027C;
            *(u32 *)(p + 8) = 0x53FEB446;
            *(s32 *)(p + 0xC) = sc->sxy;
            *(u32 *)(p + 0x10) = 0x5A3C28;
            *(s32 *)(p + 0x14) = sc->sxy2;
            *(u32 *)p = (*(u32 *)p & 0xFF000000) | (ot[sc->otz] & mask);
            ot[sc->otz] = (ot[sc->otz] & 0xFF000000) | ((u32)p & mask);
            p += 0x18;
        } else if (s >= 5) {
            e->state = 0;
        } else {
            e->state++;
            h = 0xA40 / sc->otz;
            w = 0x7B0 / sc->otz;
            p[3] = 9;
            *(u32 *)(p + 4) = 0x2F000000;
            *(s32 *)(p + 0x8) = ((sc->sy - h) << 16) | ((sc->sx - w) & 0xFFFF);
            *(s32 *)(p + 0x10) = ((sc->sy - h) << 16) | ((sc->sx + w) & 0xFFFF);
            *(s32 *)(p + 0x18) = (sc->sy << 16) | ((sc->sx - w) & 0xFFFF);
            *(s32 *)(p + 0x20) = (sc->sy << 16) | ((sc->sx + w) & 0xFFFF);
            *(u32 *)(p + 0xC) = ((e->state << 11) + 0x800) | 0x7CAC00B0;
            *(u32 *)(p + 0x14) = ((e->state << 11) + 0x800) | 0x7C00BF;
            *(u16 *)(p + 0x1C) = ((e->state * 0x800) + 0xF00) | 0xB0;
            *(u16 *)(p + 0x24) = ((e->state * 0x800) + 0xF00) | 0xBF;
            *(u32 *)p = (*(u32 *)p & 0xFF000000) | (ot[sc->otz] & mask);
            ot[sc->otz] = (ot[sc->otz] & 0xFF000000) | ((u32)p & mask);
            p += 0x28;
        }
    }
    g_Game_8013E950.prim = p;
    g_RandSeed_8013E950 = sc->seed1;
    D_800AE8F2_8013E950 = sc->seed2;
    return 0;
}

extern u16 g_RandSeed2;
extern struct { u8 pad0[0x24]; u16 x; u8 p26[2]; u16 y; u8 p2a[2]; u16 z; } g_Spike_F0C0 asm("g_Spike");
extern u32 D_8013F248;

void func_8013F0C0(void) {
    SVECTOR v;
    s32 i;

    for (i = 0; i < ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 7) + 3; i++) {
        v.vx = g_Spike_F0C0.x + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8 & 0x7F) - 0x40;
        v.vy = g_Spike_F0C0.y;
        v.vz = g_Spike_F0C0.z + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8 & 0x7F) - 0x40;
    }
    Effect_Spawn(0xC8, (s16 *)&v, &D_8013F248, 0);
}
