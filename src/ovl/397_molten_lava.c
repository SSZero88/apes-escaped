#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Pad { u8 pad_0[0x1BC]; s16 f_1BC; s16 f_1BE; } g_Pad;
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x6]; u16 f_2C; } g_Spike;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

void * Object_AddAttackSphere(void *, s16, s16, s16, s16, s16, s16);
M2C_UNK Object_OrbitAround(void *, s16, s16, s32, s32);
extern s32 D_8014115C;
s16 Object_AnimWave(void *, s16, s16, s32);

extern s32 g_TRexHitFlag;
s32 Collision_GetShape(s32);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK Object_SetupKnockback(void *, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 func_8013D000(void);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);

s32 func_8013D000(void) {
    if ((g_Pad.f_1BC >= 0x321) || (g_Pad.f_1BE >= 0x321)) {
        return 1;
    }
    return 0;
}

extern u16 g_RandSeed;
extern u8 D_80141064[];
extern s32 D_800B1CD0[];
void Rock_SpawnBurst(SVECTOR *, void *);
void Camera_StartShake(s32);
void Effect_SpawnAt(s32, SVECTOR *);
void Shockwave_Spawn(void *, s32 *, s32, s32, s32);

void func_8013D040(void *arg0) {
    SVECTOR v;
    SVECTOR w;
    s32 i;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((M2C_FIELD(arg0, s16 *, 0x60) * 5) >> 5);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((M2C_FIELD(arg0, s16 *, 0x64) * 5) >> 5);
    Object_PlaySound(arg0, 0x4D);
    Rock_SpawnBurst(&v, D_80141064);
    Camera_StartShake(2);
    for (i = 0; i < 32; i++) {
        w.vx = v.vx + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 4);
        w.vy = v.vy + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 4);
        w.vz = v.vz + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 4);
        Effect_SpawnAt(6, &w);
    }
    Effect_SpawnAt(0x113, &v);
    Shockwave_Spawn(&v, D_800B1CD0, 2, 0, (s32)((u8 *)arg0 + 0x60));
}

void func_8013D1B0(void) {
}

void func_8013D1B8(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere(arg0, 0x12C, M2C_FIELD(temp_v0, s16 *, 0), M2C_FIELD(temp_v0, s16 *, 2), (s32) M2C_FIELD(temp_v0, s16 *, 4), 1, 0x202);
}

void func_8013D208(void *arg0, s16 r) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x78);

    v.vx = p[0];
    v.vy = p[1] + 0x64;
    v.vz = p[2];
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereAt(arg0, &v, r);
}

extern s32 D_80141154;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[7]; u16 *f_88; } Obj_8013D260;
u32 Object_DetachLink(void *, s32);
s16 Object_PathPointNear(void *, void *, s16, u8);
void *memset(void *, s32, s32);
void func_8013D040(void *arg0);
void func_8013D1B8(void *arg0);
void func_8013D208(void *arg0, s16 r);

void func_8013D260(u8 *o) {
    SVECTOR w;
    SVECTOR v;
    u32 r;

    r = Object_DetachLink(o, 0);
    switch (r) {
    case 10:
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        if (M2C_FIELD(o, u8 *, 0x81) != 0) {
            if (--M2C_FIELD(o, u8 *, 0x81) == 0) {
                Object_PlaySound(o, 0x4E);
            }
        }
        M2C_FIELD(o, u8 *, 0x80) = 5;
        M2C_FIELD(o, u8 *, 0x7F) = 6;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        func_8013D040(o);
        D_80141154 = 1;
        break;
    case 6:
        if (Object_PathPointNear(o, o + 0x24, 0x2BC, M2C_FIELD(o, u8 *, 0x8E))) {
            ((Obj_8013D260 *)o)->f_80 = 5;
            ((Obj_8013D260 *)o)->f_7F = 5;
            ((Obj_8013D260 *)o)->f_5C = ((Obj_8013D260 *)o)->f_88[((Obj_8013D260 *)o)->f_7F * 2];
            D_80141154 = 1;
            func_8013D040(o);
        } else if (M2C_FIELD(o, u8 *, 0x80) == 3) {
            M2C_FIELD(o, u8 *, 0x80) = 8;
            M2C_FIELD(o, u8 *, 0x7F) = 7;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8013D208(o, 0x78);
            memset(&v, 0, 8);
            v.vx = M2C_FIELD(o, u16 *, 0x24) + M2C_FIELD(o, s16 *, 0x60) / 6;
            v.vy = M2C_FIELD(o, u16 *, 0x28) - 0x100;
            v.vz = M2C_FIELD(o, u16 *, 0x2C) + M2C_FIELD(o, s16 *, 0x64) / 6;
            w = v;
            Effect_SpawnAt(0x114, &w);
            Sound_PlayFixed(0x5F);
        }
        break;
    default:
        if (M2C_FIELD(o, u8 *, 0x80) == 3) {
        func_8013D208(o, 0x78);
        } else {
        func_8013D1B8(o);
        }
        break;
    }
}

s32 Math_Atan2(s32, s32);
s32 rcos_8013D468(s32) asm("rcos");
s32 rsin_8013D468(s32) asm("rsin");
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2a[2]; u16 z; } g_Spike_8013D468 asm("g_Spike");
void func_8013D208(void *arg0, s16 r);

void func_8013D468(u8 *a) {
    u16 base;
    s32 ang;
    s32 x;

    base = *(u16 *)(M2C_FIELD(a, u8 *, 0x7F) * 4 + M2C_FIELD(a, u8 **, 0x88));
    if (M2C_FIELD(a, u16 *, 0x5C) < base + 0x2C) {
        func_8013D208(a, 300);
    } else if (M2C_FIELD(a, u16 *, 0x5C) == base + 0x2D) {
        ang = Math_Atan2(M2C_FIELD(a, s16 *, 0x60), M2C_FIELD(a, s16 *, 0x64));
        ang = (ang + 0x1638) % 4096;
        x = (s16)(g_Spike_8013D468.x - ((rcos_8013D468(ang) * 100) >> 12));
        Object_AddAttackSphere(a, 300, x, g_Spike_8013D468.y + 100, g_Spike_8013D468.z - ((rsin_8013D468(ang) * 100) >> 12), 0, 0x100);
    }
}

void Object_CameraShake(void *, s32);

void TRex_Footsteps(u8 *a)
{
  u16 *anim;
  s32 f;
  if (a[0x7F] < 2)
  {
    Object_CameraShake(a, 0);
    anim = (u16 *) ((*((u8 **) (((s8 *) a) + 0x88))) + (a[0x7F] * ((long long) 4)));
    f = (*((u16 *) (((s8 *) a) + 0x5C))) - anim[0];
    if (f == 5)
    {
      Object_PlaySound(a, 0xAC);
    }
    else
      if (f == (((anim[1] - anim[0]) / 2) + 5))
    {
      Object_PlaySound(a, 0xAD);
    }
  }
}

s32 Object_SpikeBehind(s32, M2C_UNK, M2C_UNK, s16);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 func_8013D648(s32 arg0, s16 arg1, s32 arg2) {
    s32 var_s1;

    var_s1 = Object_SpikeInFront(arg0, 0x5A, 0xB50, arg1);
    if (arg2 != 0) {
        var_s1 |= Object_SpikeBehind(arg0, 0x5A, 0xB50, arg1) * 2;
    }
    return var_s1;
}

M2C_UNK Object_ApplyVelocity(void *);
s16 Object_PathPointNear(void *, void *, s16, u8);
s32 Object_FollowPath(void *, s16, s8, s8);

s16 func_8013D6C4(void *arg0, s16 arg1, s16 arg2, s8 arg3) {
    Object_FollowPath(arg0, arg1, 0, arg3);
    Object_ApplyVelocity(arg0);
    return Object_PathPointNear(arg0, arg0 + 0x24, arg2, M2C_FIELD(arg0, u8 *, 0x8E));
}

void Object_TurnToward(void *, s16, s16, s32, s32);

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013D730(arg0, away)
    void *arg0;
    s32 away;
{
    u16 *t = (u16 *)(M2C_FIELD(arg0, u8 **, 0x90) + M2C_FIELD(arg0, u8 *, 0x8E) * 8);

    if (away) {
        Object_TurnToward(arg0, M2C_FIELD(arg0, u16 *, 0x24) - t[0], M2C_FIELD(arg0, u16 *, 0x2C) - t[2], 0,
                          M2C_FIELD(arg0, s16 *, 0xB0));
    } else {
        Object_TurnToward(arg0, t[0] - M2C_FIELD(arg0, u16 *, 0x24), t[2] - M2C_FIELD(arg0, u16 *, 0x2C), 0,
                          M2C_FIELD(arg0, s16 *, 0xB0));
    }
}

void func_8013D7B4(arg0, away)
    void *arg0;
    s32 away;
{
    func_8013D730(arg0, away);
}

void func_8013D7D4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0xAE);
}

void TRex_HeavyImpact(u8 *a)
{
  u8 *new_var;
  a[0x80] = 4;
  a[0x7F] = 8;
  *((u16 *) (((s8 *) a) + 0x5C)) = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) a) + 0x88)))) + 0x20));
  *((s16 *) (((s8 *) a) + 0x94)) /= 2;
  if (1)
  {
    *((s16 *) (((s8 *) a) + 0x98)) /= 2;
    Object_CameraShake(a, 1);
  }
  new_var = a;
  Object_PlaySound(new_var, 0x98);
  Object_PlaySound(new_var, 0xB4);
  Object_Timer(a, 0x1F);
}

void Object_NextPathPoint(void *, s8);

void func_8013D8AC(u8 *a)
{
  s32 r = func_8013D648((s32) a, 0x600, 1);
  struct 
  {
    u32 pad : 6;
    u32 b6 : 1;
  } *fl = (void *) (a + 0xE0);
  if (r & 1)
  {
    func_8013D7D4(a);
    func_8013D7B4(a, 0);
  }
  else
    if (r & 2)
  {
    a[0x80] = 6;
    a[0x7F] = 4;
    *((u16 *) (((s8 *) a) + 0x5C)) = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) a) + 0x88)))) + 0x10));
    fl->b6 ^= 1;
    Object_NextPathPoint(a, 0);
    func_8013D7B4(a, 1);
    return;
  }
}

typedef struct { u8 pad0[0x8E]; u8 f8E; u8 f8F; u8 pad90[0x50]; u32 fE0; } Obj_8013D95C;
extern s32 D_80141150;
s32 Object_AddAttachPoint(void *, s32, s32);
void Object_PlaceAtPathPoint(void *, s32);
void Object_FacePathPoint(void *, s32);

void func_8013D95C(u8 *o) {
    u16 *t;

    M2C_FIELD(o, s16 *, 0xB0) = 0x2D;
    M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
    M2C_FIELD(o, s16 *, 0x46) = 1000;
    M2C_FIELD(o, s16 *, 0xA0) = 300;
    M2C_FIELD(o, u8 *, 0x81) = 4;
    M2C_FIELD(o, s16 *, 0x44) = 300;
    M2C_FIELD(o, s16 *, 0x48) = 0;
    ((Obj_8013D95C *)o)->fE0 &= ~0x1000;
    ((Obj_8013D95C *)o)->fE0 &= ~0x8000;
    M2C_FIELD(o, u8 *, 0x8F) = 0;
    ((Obj_8013D95C *)o)->fE0 &= ~0x40;
    M2C_FIELD(o, u8 *, 0x8E) = 0;
    D_80141154 = 0;
    ((Obj_8013D95C *)o)->fE0 |= 0x2200;
    M2C_FIELD(o, s32 *, 0x74) = Object_AddAttachPoint(o, 0xD, -1);
    M2C_FIELD(o, s32 *, 0x78) = Object_AddAttachPoint(o, 6, 0x3E);
    Object_PlaceAtPathPoint(o, 0);
    Object_FacePathPoint(o, 1);
    t = M2C_FIELD(o, u16 **, 0x88);
    D_80141150 = 0;
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *t;
}

void Object_DebugStub(void *, s32);
void Object_SpawnEffect(void *, s32, s32, s32, s32);
void func_8013D1B0_8013DA44(void *) asm("func_8013D1B0");
void func_8013D95C_8013DA44(void) asm("func_8013D95C");
void func_8013D260(u8 *o);
void func_8013D468(u8 *a);
s32 func_8013D648(s32 arg0, s16 arg1, s32 arg2);
s16 func_8013D6C4(void *arg0, s16 arg1, s16 arg2, s8 arg3);
void func_8013D7D4(void *arg0);
typedef struct { u8 pad0[0x5C]; u16 frame; } Obj_8013DA44;
#define END_8013DA44(o) (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2))

void func_8013DA44(u8 *o) {
    s32 a;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013D95C_8013DA44();
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xCF) == 4) {
        M2C_FIELD(o, u8 *, 0x81) = 0;
        M2C_FIELD(o, u8 *, 0xCF) = 0;
    }
    M2C_FIELD(o, s16 *, 0xB0) = 0x2D;
    TRex_Footsteps(o);
    func_8013D1B0_8013DA44(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_FollowPath(o, 0x14, 0, 1);
        Object_ApplyVelocity(o);
        if (!Object_Timer(o, -1)) {
            func_8013D8AC(o);
        }
        break;
    case 6:
        if (M2C_FIELD(o, u16 *, 0x5C) >= END_8013DA44(o)) {
            a = M2C_FIELD(o, s16 *, 0xAC);
            M2C_FIELD(o, s16 *, 0x60) = M2C_FIELD(o, s16 *, 0x60) * -1;
            M2C_FIELD(o, s16 *, 0x64) = M2C_FIELD(o, s16 *, 0x64) * -1;
            M2C_FIELD(o, s16 *, 0xAC) = (a + 0x800) % 4096;
            func_8013D7D4(o);
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= END_8013DA44(o)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
        }
        break;
    case 3:
        if (func_8013D6C4(o, 0x3E, 0x12C, 0) || !func_8013D648((s32)o, 0xA00, 0)) {
            TRex_HeavyImpact(o);
        } else {
            func_8013D260(o);
        }
        break;
    case 4:
        func_8013D260(o);
        Object_ApplyVelocity(o);
        Object_SpawnEffect(o, 6, 0, 0, 0);
        if (M2C_FIELD(o, u8 *, 0x7F) == 8 && M2C_FIELD(o, u16 *, 0x5C) == END_8013DA44(o)) {
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[6];
        }
        if (M2C_FIELD(o, u8 *, 0xC9) == 0 || --M2C_FIELD(o, u8 *, 0xC9) == 0
            || Object_PathPointNear(o, o + 0x24, 0x32, M2C_FIELD(o, u8 *, 0x8E))) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, s16 *, 0x98) = 0;
            M2C_FIELD(o, s16 *, 0x96) = 0;
            M2C_FIELD(o, s16 *, 0x94) = 0;
            M2C_FIELD(o, u8 *, 0x7F) = 9;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[18];
        }
        break;
    case 5:
        if (M2C_FIELD(o, u8 *, 0x7F) == 9) {
            func_8013D260(o);
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= END_8013DA44(o)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            ((Obj_8013DA44 *)o)->frame = *M2C_FIELD(o, u16 **, 0x88);
            if (D_80141154) {
                D_80141154 = 0;
                Object_Timer(o, 0x5A);
            }
        }
        break;
    case 8:
        func_8013D468(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= END_8013DA44(o)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    }
    if (!M2C_FIELD(o, u8 *, 0x81)) {
        M2C_FIELD(o, s16 *, 0x5E) = 1;
    }
}

extern s32 g_TRexTurnHeading;

/* Probably the T-rex (walks a square path, charges Spike, needs a few hits before the riding
 * monkey falls off). When the hit flag g_TRexHitFlag is set and it is not already in hit state 2,
 * plays the hit animation and counts down a[0x81]; on the last hit it stores its heading
 * turned 180 degrees in g_TRexTurnHeading and plays sound 0x4E. Clears the hit flag every call. */
void TRex_CountHit(u8 *a) {
    if (g_TRexHitFlag != 0 && a[0x80] != 2) {
        a[0x80] = 2;
        a[0x7F] = 2;
        M2C_FIELD(a, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(a, u8 **, 0x88), u16 *, 8);
        M2C_FIELD(a, s16 *, 0x5E) = 2;
        if (a[0x81] != 0) {
            if (--a[0x81] == 0) {
                g_TRexTurnHeading = (M2C_FIELD(a, s16 *, 0xAA) + 0x800) % 0x1000;
                Object_PlaySound(a, 0x4E);
            }
        }
    }
    g_TRexHitFlag = 0;
}

extern struct { s32 x, y, z; u8 padC[0x14]; s16 w, h; } D_80141168_8013DE98 asm("g_TRexHeadBox");
extern u8 D_800E77E5;
void Debug_DrawWorldQuad(void *, s32, s32);

void TRex_UpdateHeadBox(u8 *a) {
    D_80141168_8013DE98.x = M2C_FIELD(a, s32 *, 0x24) + ((M2C_FIELD(a, s16 *, 0x60) * 115) >> 10);
    D_80141168_8013DE98.y = M2C_FIELD(a, s32 *, 0x28) - 0x104;
    D_80141168_8013DE98.z = M2C_FIELD(a, s32 *, 0x2C) + ((M2C_FIELD(a, s16 *, 0x64) * 115) >> 10);
    if (D_800E77E5 >= 2) {
        Debug_DrawWorldQuad(&D_80141168_8013DE98, D_80141168_8013DE98.w, D_80141168_8013DE98.h);
    }
}

void func_8013DF3C(void *o_, SVECTOR *v) {
    u8 *o = o_;
    s32 c = M2C_FIELD(o, s16 *, 0x60);
    s32 s = M2C_FIELD(o, s16 *, 0x64);
    s32 z = v->vz;
    s32 x = v->vx;
    s32 cz = (c * z) >> 12;
    s32 sz = (s * z) >> 12;
    s32 sx = (s * x) >> 12;
    s32 cx = (c * x) >> 12;
    v->vx = M2C_FIELD(o, s16 *, 0x24) + cz - sx;
    v->vy = M2C_FIELD(o, s16 *, 0x28) + v->vy;
    v->vz = M2C_FIELD(o, s16 *, 0x2C) + sz + cx;
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013DFC4(void *arg0, s32 n, s16 x, s32 z) {
    SVECTOR v;

    v.vx = x;
    v.vy = n * 20 - 0x32;
    v.vz = z - n * 20;
    func_8013DF3C(arg0, &v);
    Effect_SpawnAt(5, &v);
}

void func_8013DFC4(void *arg0, s32 n, s16 x, s32 z);

void func_8013E010(void *arg0) {
    s32 d;
    u32 n;

    d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
    switch (M2C_FIELD(arg0, u8 *, 0x7F)) {
    case 1:
        n = d - 4;
        if (n < 5) {
            func_8013DFC4(arg0, n, 0xBE, -0x6E);
            func_8013DFC4(arg0, n, -0xBE, 0xE6);
        } else {
            n = d - 0x11;
            if (n < 5) {
                func_8013DFC4(arg0, n, -0xBE, -0x6E);
                func_8013DFC4(arg0, n, 0xBE, 0xE6);
            }
        }
        break;
    case 2:
        n = d - 0x46;
        if (n < 5) {
            func_8013DFC4(arg0, n, -0xBE, 0xE6);
            func_8013DFC4(arg0, n, 0xBE, 0xE6);
        }
        break;
    case 4:
        func_8013DFC4(arg0, 0, -0xBE, 0xE6);
        func_8013DFC4(arg0, 0, 0xBE, 0xE6);
        func_8013DFC4(arg0, 0, -0xBE, -0x6E);
        func_8013DFC4(arg0, 0, 0xBE, -0x6E);
        break;
    }
}

void func_8013E174(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1) {
        Object_PlaySound(arg0, 0xAC);
    } else if (d == f2) {
        Object_PlaySound(arg0, 0xAD);
    }
}

void func_8013E1C4(void *arg0) {
    switch (M2C_FIELD(arg0, u8 *, 0x7F)) {
    case 0:
        func_8013E174(arg0, 0x10, 0x2E);
        break;
    case 1:
        func_8013E174(arg0, 5, 0x12);
        break;
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
extern M2C_UNK g_TRexHeadBox;
u32 Object_DetachLink(void *, s32);

void func_8013E214(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0xC9) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x12C, M2C_FIELD(&g_TRexHeadBox, s16 *, 0), M2C_FIELD(&g_TRexHeadBox, s16 *, 4), (s32) M2C_FIELD(&g_TRexHeadBox, s16 *, 8), 1, 0x203);
}

void func_8013E284(void *arg0) {
    Object_OrbitAround(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), D_8014115C, (s32) Object_AnimWave(arg0, 5, 2, 6));
}

void func_8013E2D8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 4) {
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x14);
        M2C_FIELD(arg0, u8 *, 0x81) = 0;
        M2C_FIELD(arg0, u8 *, 0xCF) = 0;
        func_8013E284(arg0);
    }
}

extern struct { s32 x, y, z; u8 padC[0x14]; s16 f20, f22, f24, f26; } g_TRexHeadBox_8013E320 asm("g_TRexHeadBox");
typedef struct { u8 pad0[0xA6]; s16 f_A6; } Obj_8013E320;
void TRex_UpdateHeadBox(u8 *a);
s32 Collision_Set(s32, void *, void *);
void Object_PlaceRandomAroundHome(void *, s16);
void *func_80056BC4_8013E320(s32, void *, s32) asm("Object_SpawnPooled");

void func_8013E320(o)
    u8 *o;
{
    M2C_FIELD(o, s16 *, 0xA0) = 0x12C;
    M2C_FIELD(o, s16 *, 0x44) = 0x12C;
    M2C_FIELD(o, s16 *, 0x46) = 0x258;
    M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
    M2C_FIELD(o, s16 *, 0xB0) = 0x16;
    M2C_FIELD(o, u8 *, 0x81) = 3;
    g_TRexHitFlag = 0;
    M2C_FIELD(o, s16 *, 0x48) = 0;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x200;
    Object_PlaceRandomAroundHome(o, ((Obj_8013E320 *)o)->f_A6);
    D_8014115C = 1000;
    M2C_FIELD(o, s16 *, 0xA8) = 0;
    g_TRexHeadBox_8013E320.f20 = 0xA0;
    g_TRexHeadBox_8013E320.f22 = 0x118;
    g_TRexHeadBox_8013E320.f24 = 1;
    g_TRexHeadBox_8013E320.f26 = -0x7EFD;
    TRex_UpdateHeadBox(o);
    Collision_Set(5, &g_TRexHeadBox_8013E320, o);
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
    func_80056BC4_8013E320(0x30, o + 0x24, M2C_FIELD(o, s8 *, 0xCB));
}

void func_80058134_8013FA24(void *, s32) asm("Object_DebugStub");
void TRex_CountHit(u8 *a);
void TRex_UpdateHeadBox(u8 *a);
void func_8013E010(void *arg0);
void func_8013E1C4(void *arg0);
void func_8013E214(void *arg0);
void func_8013E284(void *arg0);
void func_8013E2D8(void *arg0);
#define ANIM_8013E40C(o, i) (*(u16 *)((i) * 4 + M2C_FIELD(o, u8 **, 0x88)))
#define AEND_8013E40C(o, i) (*(u16 *)((i) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2))

void func_8013E40C(u8 *o) {
    s32 a;
    s32 g;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013E320();
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013FA24(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013E2D8(o);
    func_8013E1C4(o);
    func_8013E010(o);
    TRex_CountHit(o);
    if (!M2C_FIELD(o, u8 *, 0x81)) {
        M2C_FIELD(o, s16 *, 0x5E) = 1;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013E284(o);
        if (!M2C_FIELD(o, u8 *, 0x81)) {
            a = M2C_FIELD(o, s16 *, 0xAA);
            g = g_TRexTurnHeading;
            if ((a - g >= 0) ? (a - g < 5) : (g - a < 5)) {
                M2C_FIELD(o, u8 *, 0x80) = 5;
            }
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) == ANIM_8013E40C(o, M2C_FIELD(o, u8 *, 0x7F)) + 0x1E) {
            Object_PlaySound(o, 0xAF);
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= AEND_8013E40C(o, M2C_FIELD(o, u8 *, 0x7F))) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            Object_Timer(o, 0xB4);
        }
        break;
    case 3:
        Object_OrbitAround(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), D_8014115C, 7);
        func_8013E214(o);
        if (!Object_Timer(o, -1) && M2C_FIELD(o, u16 *, 0x5C) >= AEND_8013E40C(o, M2C_FIELD(o, u8 *, 0x7F))) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[8];
            M2C_FIELD(o, s16 *, 0xA8) = 0x38;
        }
        break;
    case 4:
        if (M2C_FIELD(o, s16 *, 0xA8) != 0) {
            M2C_FIELD(o, s16 *, 0xA8)--;
        }
        Object_OrbitAround(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), D_8014115C, M2C_FIELD(o, s16 *, 0xA8) >> 3);
        if (M2C_FIELD(o, u16 *, 0x5C) >= AEND_8013E40C(o, M2C_FIELD(o, u8 *, 0x7F))) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    case 5:
        switch (M2C_FIELD(o, u8 *, 0x7F)) {
        case 0:
            func_8013E284(o);
            break;
        case 7:
            if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, u16 **, 0x88)[14] + 0xA) {
                Object_PlaySound(o, 0xAF);
            }
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= AEND_8013E40C(o, M2C_FIELD(o, u8 *, 0x7F))) {
            switch (M2C_FIELD(o, u8 *, 0x7F)) {
            case 0:
                M2C_FIELD(o, u8 *, 0x7F) = 6;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[12];
                break;
            case 6:
                M2C_FIELD(o, u8 *, 0x7F) = 5;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[10];
                break;
            default:
                if ((u16)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 10) < 4) {
                    M2C_FIELD(o, u8 *, 0x7F) = 7;
                    M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[14];
                } else {
                    M2C_FIELD(o, u8 *, 0x7F) = 5;
                    M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[10];
                }
                break;
            }
        }
        break;
    }
    TRex_UpdateHeadBox(o);
}

void func_8013E7D8(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0xC8) != 0) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0xAA;
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        Effect_SpawnAt(0x10B, &v);
    }
}

typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x54]; u8 f_80; u8 pad81[0xE]; u8 f_8F; u8 pad90[4]; s16 f_94; s16 f_96; s16 f_98; } Obj_8013E82C;
s16 Object_FloorAt(void *, s16, s16, s16);

void func_8013E82C(Obj_8013E82C *a) {
    s16 h;

    h = Object_FloorAt(a, 0, 0, 0);
    a->f_96 += 7;
    Object_ApplyVelocity(a);
    if (h < a->f_28) {
        a->f_28 = h;
        if (a->f_8F == 2) {
            a->f_80 = a->f_8F;
            a->f_96 = 0;
            Object_Timer(a, 0x28);
        } else {
            a->f_96 = -a->f_96 / 3;
            a->f_8F++;
            a->f_94 /= 2;
            a->f_98 /= 2;
            Object_PlaySound(a, 0x51);
        }
    }
}

void func_8013E934(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) - ((s32) -(M2C_FIELD(arg1, s16 *, 0x64) * 0x28) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_a2, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + ((s32) -(M2C_FIELD(arg1, s16 *, 0x60) * 0x28) >> 0xC));
}

void Object_Despawn(void *, s32);

/* T-rex slams its head into a platform: impact effect 0x102 at its position, clears a[0x82]
 * and flag 0x100000, sound 0x6E, and a short-lived attack sphere around the impact.
 * called without all its arguments (old-style declaration), so defined old-style */
void TRex_HeadSlam(a)
    u8 *a;
{
    SVECTOR v;

    v.vx = M2C_FIELD(a, u16 *, 0x24);
    v.vy = M2C_FIELD(a, u16 *, 0x28);
    v.vz = M2C_FIELD(a, u16 *, 0x2C);
    Effect_SpawnAt(0x102, &v);
    Object_Despawn(a, 0);
    a[0x82] = 0;
    M2C_FIELD(a, u32 *, 0xE0) &= ~0x100000;
    Object_PlaySound(a, 0x6E);
    Object_AddAttackSphereNear(a, 0x12C, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, s16 *, 0x28), M2C_FIELD(a, s16 *, 0x2C),
                               0x201, 0x202);
}

/* T-rex collision: touching object type 5 (presumably the platform it gets lured into) sets
 * the hit flag g_TRexHitFlag (see TRex_CountHit) and runs the head slam TRex_HeadSlam. */
void TRex_OnCollide(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 5) {
        g_TRexHitFlag = 1;
        TRex_HeadSlam();
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x80) == 1) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2U;
    }
}

typedef struct { u8 pad0[0x80]; u8 f_80; u8 f_81; u8 pad82[0x62]; } Obj_EA8C;
extern Obj_EA8C g_Objects_EA8C[] asm("g_Objects");
void func_8013E934(void *arg0, void *arg1);

void func_8013EA8C(u8 *a) {
    Obj_EA8C *o;

    M2C_FIELD(a, s16 *, 0xA0) = 100;
    M2C_FIELD(a, s16 *, 0x48) = 0x800;
    M2C_FIELD(a, s16 *, 0x4A) = -0x3EFF;
    M2C_FIELD(a, u8 *, 0xDB) = 4;
    M2C_FIELD(a, u8 *, 0x83) = 2;
    M2C_FIELD(a, s16 *, 0x44) = 0x50;
    M2C_FIELD(a, s16 *, 0x46) = 0xC8;
    M2C_FIELD(a, u8 *, 0x81) = 10;
    M2C_FIELD(a, u8 *, 0x8F) = 0;
    M2C_FIELD(a, u32 *, 0xE0) &= ~0x1000;
    o = &g_Objects_EA8C[M2C_FIELD(a, s8 *, 0xCA)];
    M2C_FIELD(a, u32 *, 0xE0) |= 0x200000;
    func_8013E934(a, o);
    *(SVECTOR *)(a + 0x60) = *(SVECTOR *)((u8 *)o + 0x60);
    M2C_FIELD(a, u8 *, 0xC8) = 0;
    Object_Timer(a, 0x23);
    M2C_FIELD(a, u8 *, 0x80) = 1;
    M2C_FIELD(a, u8 *, 0x7F) = 0;
    M2C_FIELD(a, u16 *, 0x5C) = *M2C_FIELD(a, u16 **, 0x88);
}

void func_8013EB8C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        Object_SetupKnockback(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        Sound_PlayFixed(0x5F);
        Sound_PlayFixed(0x15);
    }
}

typedef struct { u8 pad0[0x80]; u8 f_80; u8 f_81; u8 pad82[0x62]; } Obj_397;
extern Obj_397 g_Objects_397[] asm("g_Objects");
void Object_Despawn(void *, s32);

s32 func_8013EBE8(void *arg0, void *arg1) {
    Obj_397 *o;

    o = &g_Objects_397[M2C_FIELD(arg1, s8 *, 0xCA)];
    if (o->f_80 != 1 || o->f_81 == 0) {
        Object_Despawn(arg0, 0);
        return 1;
    }
    return 0;
}

void func_8013E7D8(void *arg0);
void func_8013EA8C(u8 *a);
void func_8013EB8C(void *arg0);
s32 func_8013EBE8(void *arg0, void *arg1);
void TRex_OnCollide(void *arg0);

void func_8013EC54(u8 *o) {
    u8 *t = (u8 *)&g_Objects_397[M2C_FIELD(o, s8 *, 0xCA)];
    s32 a;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013EA8C(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (o[0x82] != 0) {
        TRex_OnCollide(o);
        o[0x84] = 0;
        return;
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x100000;
        TRex_HeadSlam(o);
    }
    func_8013E7D8(o);
    func_8013EB8C(o);
    switch (o[0x80]) {
    case 2:
        if (Object_Timer(o, -1) == 0) {
            TRex_HeadSlam(o);
        }
        break;
    case 1:
        if (func_8013EBE8(o, t) == 0) {
            if (o[0xC9] != 0) {
                func_8013E934(o, t);
                if (--o[0xC9] == 0x1B) {
                    o[0xC8] = 10;
                }
                if (o[0xC9] == 0) {
                    a = (M2C_FIELD(t, s16 *, 0xAC) + 0x14A) % 4096;
                    M2C_FIELD(o, s16 *, 0x94) = (u32)(rcos_8013D468(a) * 5) >> 9;
                    M2C_FIELD(o, s16 *, 0x98) = (u32)(rsin_8013D468(a) * 5) >> 9;
                    M2C_FIELD(o, s16 *, 0x96) = -0x38;
                }
            } else {
                func_8013E82C(o);
            }
        }
        break;
    }
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_8013EE34(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x78);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 0);
}

void func_8013EE80(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

typedef struct { u8 pad[0xE4]; } Obj_8013EED0;
extern Obj_8013EED0 g_Objects_8013EED0[] asm("g_Objects");
void *func_80057140_8013EED0(void *, s32, s32) asm("Object_AddAttachPoint");
void *func_80056BC4_8013EED0(s32, s32, s32) asm("Object_SpawnPooled");
void func_8013EE34(void *arg0);
void func_8013EE80(void *arg0, void *arg1);

void func_8013EED0(u8 *o) {
    u8 *t = (u8 *)&g_Objects_8013EED0[M2C_FIELD(o, s8 *, 0xCA)];

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        func_8013EE80(o, t);
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, void **, 0x74) = func_80057140_8013EED0(o, 0x12, -1);
        M2C_FIELD(o, void **, 0x78) = func_80057140_8013EED0(o, 6, 0x45);
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 4;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_8013EE80(o, t);
    func_8013EE34(o);
    if (M2C_FIELD(t, u8 *, 0x81) == 0) {
        Object_Despawn(o, 0);
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(o, u8 *, 0x7F) != M2C_FIELD(t, u8 *, 0x7F) + 4) {
            M2C_FIELD(o, u8 *, 0x7F) = M2C_FIELD(t, u8 *, 0x7F) + 4;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        if (M2C_FIELD(t, u16 *, 0x5C) == 0 && Object_SpikeInFront(o, 0x5A, 0xB50, 0x600)) {
            func_8013E934(func_80056BC4_8013EED0(0x4F, 0, M2C_FIELD(o, s8 *, 0xCB)), o);
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 9;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_PlaySound(o, 0x53);
        }
        break;
    case 2:
        if (M2C_FIELD(t, u8 *, 0x80) != 1) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = M2C_FIELD(t, u8 *, 0x7F) + 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(t, u16 *, 0x5C) + M2C_FIELD(o, u16 **, 0x88)[8];
        } else if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = M2C_FIELD(t, u8 *, 0x7F) + 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(t, u16 *, 0x5C) + M2C_FIELD(o, u16 **, 0x88)[8];
        }
        break;
    }
}

void func_8013F100(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 5) {
        Object_PlaySound(arg0, 0xB2);
    }
}

s32 rcos_8013F144(s32) asm("rcos");
s32 rsin_8013F144(s32) asm("rsin");
s32 Math_ISqrt(s32);
void Object_SetVelocityToward(void *, void *, s32, s16);

void func_8013F144(u8 *a) {
    s32 d;

    M2C_FIELD(a, s16 *, 0xAA) = (M2C_FIELD(a, s16 *, 0xAA) + 11) % 4096;
    M2C_FIELD(a, s16 *, 0x94) = M2C_FIELD(a, u16 *, 0x9A) + ((rcos_8013F144(M2C_FIELD(a, s16 *, 0xAA)) * M2C_FIELD(a, s16 *, 0xA6)) >> 12) - M2C_FIELD(a, u16 *, 0x24);
    M2C_FIELD(a, s16 *, 0x98) = M2C_FIELD(a, u16 *, 0x9E) + ((rsin_8013F144(M2C_FIELD(a, s16 *, 0xAA)) * M2C_FIELD(a, s16 *, 0xA6)) >> 12) - M2C_FIELD(a, u16 *, 0x2C);
    M2C_FIELD(a, s16 *, 0x96) = M2C_FIELD(a, u16 *, 0x9C) + 500 - M2C_FIELD(a, u16 *, 0x28);
    d = Math_ISqrt(M2C_FIELD(a, s16 *, 0x94) * M2C_FIELD(a, s16 *, 0x94) + M2C_FIELD(a, s16 *, 0x98) * M2C_FIELD(a, s16 *, 0x98) + M2C_FIELD(a, s16 *, 0x96) * M2C_FIELD(a, s16 *, 0x96));
    if (d > 20) {
        d = 20;
    }
    Object_SetVelocityToward(a, a + 0x94, d, 0);
    Object_ApplyVelocity(a);
}

void func_8013F26C(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x80) - 2) >= 2U) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0)) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2U;
        M2C_FIELD(arg0, s8 *, 0x7F) = 2;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
        Object_PlaySound(arg0, 0xB3);
        M2C_FIELD(arg0, u16 *, 0xC2) = (u16) g_Spike.f_24;
        M2C_FIELD(arg0, u16 *, 0xC6) = (u16) g_Spike.f_2C;
    }
}

void func_8013F300(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x74);
    M2C_FIELD(arg1, s16 *, 0) = (s16) ((M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(temp_a2, s16 *, 0) * 2)) / 3);
    M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1A4);
    M2C_FIELD(arg1, s16 *, 4) = (s16) ((M2C_FIELD(arg0, s32 *, 0x2C) + (M2C_FIELD(temp_a2, s16 *, 4) * 2)) / 3);
}

s32 Object_AddAttackSphereAt(void *, SVECTOR *, s32);

void func_8013F368(void *arg0) {
    SVECTOR v;

    func_8013F300(arg0, &v);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereAt(arg0, &v, 0xC8);
}

extern s32 D_800EC204;
extern s32 D_800EC208;
extern s32 D_800EC20C;

s32 func_8013F3A4(u8 *o) {
    s16 v[4];
    s32 r;

    func_8013F300(o, v);
    r = 0;
    if (ABS(D_800EC204 - v[0]) < 0x80
        && ABS(D_800EC208 + (500 - M2C_FIELD(o, s32 *, 0x28))) < 0x80
        && ABS(D_800EC20C - v[2]) < 0x80) {
        r = 1;
    }
    return r;
}

void func_8013F300(void *arg0, void *arg1);
s32 func_8013F3A4(u8 *o);
void func_8013F100(void *arg0);
s16 Object_FloorAt(void *, s16, s16, s16);
void VectorNormalSS(void *, void *);

void func_8013F484(void *arg0) {
    SVECTOR v;
    SVECTOR p;
    s32 fl;
    s32 d;

    func_8013F300(arg0, &p);
    fl = Object_FloorAt(arg0, 0, 0, 0);
    d = (fl - (M2C_FIELD(arg0, s32 *, 0x28) - 500)) >> 2;
    if (d > 50) {
        d = 50;
    }
    M2C_FIELD(arg0, s16 *, 0x96) = d;
    v.vx = M2C_FIELD(arg0, u16 *, 0xC2) - p.vx;
    v.vy = 0;
    v.vz = M2C_FIELD(arg0, u16 *, 0xC6) - p.vz;
    if (v.vx * v.vx + v.vz * v.vz >= 0xE11) {
        VectorNormalSS(&v, &v);
        M2C_FIELD(arg0, s16 *, 0x94) = (v.vx * 15) >> 10;
        M2C_FIELD(arg0, s16 *, 0x98) = (v.vz * 15) >> 10;
    } else {
        M2C_FIELD(arg0, s16 *, 0x94) = v.vx;
        M2C_FIELD(arg0, s16 *, 0x98) = v.vz;
    }
    Object_ApplyVelocity(arg0);
    if (func_8013F3A4(arg0)) {
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        M2C_FIELD(arg0, s16 *, 0xAA) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
    } else if (fl < M2C_FIELD(arg0, s32 *, 0x28) - 0x1B4) {
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
    }
    func_8013F100(arg0);
}

void func_8013F5FC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) & 1) {
        if ((M2C_FIELD(arg0, u8 *, 0x80) == 7) && ((func_8013D000() << 0x10) != 0)) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
            Object_Timer(arg0, 0x3C);
            return;
        }
        func_8013F368(arg0);
    }
}

s32 Object_StepToward3D(void *, s16, s16, s16, s32);
void func_8013F144(u8 *a);
void func_8013F26C(void *arg0);
void func_8013F484(void *arg0);
void func_8013F5FC(void *arg0);

void func_8013F694(u8 *o) {
    s32 a;
    u16 r;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        r = g_RandSeed * 5 + 1;
        a = (s32)(((r >> 8) * 3) << 12) / 360;
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        g_RandSeed = r;
        M2C_FIELD(o, s16 *, 0xAA) = a % 4096;
        M2C_FIELD(o, s16 *, 0x4A) = -0x3F00;
        M2C_FIELD(o, s16 *, 0x48) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u8 *, 0xC8) = 0x1E;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, void **, 0x74) = func_80057140_8013EED0(o, 0x11, 0xA1);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013F144(o);
        if (!Object_Timer(o, -1)) {
            func_8013F26C(o);
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
        }
        break;
    case 3:
        func_8013F484(o);
        break;
    case 4:
        func_8013F100(o);
        if (func_8013F3A4(o)) {
            M2C_FIELD(o, s16 *, 0xAA) = 0;
            M2C_FIELD(o, u32 *, 0xE0) |= 1;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[8];
        }
        break;
    case 5:
        M2C_FIELD(o, s32 *, 0x28) -= 0x32;
        if (M2C_FIELD(o, s32 *, 0x28) - 500 < M2C_FIELD(o, s16 *, 0x9C) - 0x334) {
            if (M2C_FIELD(o, u32 *, 0xE0) & 1) {
                M2C_FIELD(o, u8 *, 0x80) = 7;
                M2C_FIELD(o, u8 *, 0x7F) = 1;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 6;
                M2C_FIELD(o, u8 *, 0x7F) = 3;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[6];
            }
        }
        func_8013F100(o);
        break;
    case 6:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    case 7:
        func_8013F100(o);
        if (Object_StepToward3D(o, -0xEC2, M2C_FIELD(o, s16 *, 0x9C), 0x731, 0x2C)) {
            M2C_FIELD(o, u8 *, 0x80) = 8;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            M2C_FIELD(o, u32 *, 0xE0) &= ~1;
            M2C_FIELD(o, s16 *, 0x96) = 0x3E;
        } else {
            Object_ApplyVelocity(o);
        }
        break;
    case 8:
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        M2C_FIELD(o, s16 *, 0x96) -= 5;
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    }
    func_8013F5FC(o);
}

extern u16 g_RandSeed2;
void func_80058134_8013FA24(void *, s32) asm("Object_DebugStub");
void Object_SetAnim_8013FA24(void *, s32, s32) asm("Object_SetAnim");

void func_8013FA24(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x4A) = -0x3EFF;
        M2C_FIELD(o, s16 *, 0x46) = 0xDC;
        M2C_FIELD(o, s16 *, 0x44) = 0x78;
        M2C_FIELD(o, s16 *, 0xA0) = 0x96;
        M2C_FIELD(o, u8 *, 0xC8) = 0x10;
        M2C_FIELD(o, s16 *, 0x48) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013FA24(o, M2C_FIELD(o, s16 *, 0x44));
    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) == 11 && M2C_FIELD(o, u8 *, 0x7F) != 4) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        Object_SetAnim_8013FA24(o, 2, 4);
        Object_PlaySound(o, 0x15);
    }
    if (M2C_FIELD(o, u8 *, 0x80) == 1) {
        switch (M2C_FIELD(o, u8 *, 0xCF)) {
        case 1:
            if (!(M2C_FIELD(o, u32 *, 0xE0) & 1)) {
                M2C_FIELD(o, u32 *, 0xE0) |= 1;
                Object_SetAnim_8013FA24(o, 2, 6);
            } else {
                M2C_FIELD(o, u32 *, 0xE0) &= ~1;
                Object_SetAnim_8013FA24(o, 2, 4);
            }
            break;
        case 3:
            Object_SetAnim_8013FA24(o, 2, (s32)(((u32)((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 7) < 5 ? 1 : 3);
            break;
        }
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    if (M2C_FIELD(o, u8 *, 0x80) == 2) {
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            if (M2C_FIELD(o, u8 *, 0x7F) == 4) {
                M2C_FIELD(o, u8 *, 0x7F) = 5;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            } else {
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            }
        }
    }
}

void func_8013FC44(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void func_8013FC90(void) {
}

void func_8013FC44(void *arg0, M2C_UNK arg1);
extern u32 D_80141058[];
extern s32 D_80140F10[];
extern s32 D_800B1F1C[];
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
void Object_PlaceRandomAroundHome(void *, s16);
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x10]; u16 frame; u8 pad5E[0x21]; u8 anim; u8 pad80[8]; u16 *anims; u8 pad8C[8]; s16 vx, vy, vz; u8 pad9A[2]; s16 floor; u8 pad9E[2]; s16 fA0; u8 padA2[4]; s16 fA6; u8 padA8[8]; s16 fB0; u8 padB2[0x17]; u8 timer; u8 padCA[0x16]; u32 b0:1, b1:1, b2:1, b3:1; } Obj_8013FC98;

void func_8013FC98(Obj_8013FC98 *e) {
    SVECTOR v;
    s32 i;
    s32 fl;

    if (!e->b3) {
        e->fA0 = 0x32;
        e->fB0 = 0x5B;
        e->f48 = 0x201;
        e->f4A = -0x7DFE;
        Object_PlaceRandomAroundHome(e, 0x64);
        e->vy = -0x78 - (s32)((u32)(((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 5);
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
        Effect_Spawn(0xC8, &v.vx, D_80141058, 0);
        Effect_Spawn(0xC8, &v.vx, D_80141058, 0);
        if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7)) {
            Effect_Spawn(0xC9, &v.vx, D_80141058, 0);
        }
    }
    if (e->timer == 0) {
        fl = Object_FloorAt(e, 0, 0, 0);
        if (fl < e->y) {
            v.vx = e->x;
            v.vy = fl;
            v.vz = e->z;
            Shockwave_Spawn(&v, D_80140F10, 1, 0, 0);
            Shockwave_Spawn(&v, D_800B1F1C, 1, 0, 0);
            for (i = 0; i < 0x10; i++) {
                Effect_Spawn(0xCA, &v.vx, D_80141058, 0);
            }
            Object_PlaceRandomAroundHome(e, e->fA6);
            e->vz = 0;
            e->vx = 0;
            e->y = e->floor;
            e->vy = -0x78 - (s32)((u32)(((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 5);
            Object_Timer(e, 0x1E);
            func_8013FC44(e, 0x94);
            func_8013FC44(e, 0x43);
        }
    } else {
        e->timer--;
    }
}

void func_8013FF84(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80141240[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140024 asm("g_Game");

void func_80140024(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80141240 + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game_80140024.f_80 + g_Game_80140024.f_C * 0x4078, &g_ProjVerts, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801411A0");
void func_801403C0(void);
void Hook_Add(void *);

void func_801400EC(void *arg0) {
    s32 i;

    func_8013FF84(arg0, D_80141240, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(func_801403C0);
}

s32 func_80140140(void) {
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
extern u8 D_801411A0[];

void func_8014017C(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = func_80140140();
  if (i != (-1))
  {
    p = D_801411A0 + (i * 0x14);
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

s32 func_801402B4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_801402F8(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_80140338(SVECTOR *p) {
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

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x88]; s32 fB4; u8 padB8[0x2C]; } Obj_801403C0;
extern Obj_801403C0 g_Objects_801403C0[] asm("g_Objects");
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; SVECTOR dir; } Mdl_801403C0;
extern Mdl_801403C0 D_80141240_801403C0 asm("D_80141240");
void Object_PlaySound_801403C0(void *, s32) asm("Object_PlaySound");
s32 Object_AddAttackSphere_801403C0(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");

void func_801403C0(void) {
    Drip_396 *p;
    Obj_801403C0 *o;
    s32 i;
    Mdl_801403C0 *m;

    m = &D_80141240_801403C0;
    for (i = 7; i >= 0; i--) {
        p = &D_8013F2A0_s[i];
        if (p->active != 0) {
            p->active++;
            p->vy += 4;
            o = &g_Objects_801403C0[p->unkE];
            func_801402F8((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (Object_DetachLink(o, 0) == 6) {
                p->active = 0;
                func_80140338((SVECTOR *)p);
                Object_PlaySound_801403C0(o, 0x6B);
            } else if (func_801402B4(p) != 0 || o->y + 0x600 < p->y) {
                p->active = 0;
                func_80140338((SVECTOR *)p);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->dir.vx = p->vx;
                m->dir.vy = p->vy;
                m->dir.vz = p->vz;
                VectorNormalSS(&m->dir, &m->dir);
                func_80140024(0, 3);
                o->fB4 = Object_AddAttackSphere_801403C0(o, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8014059C(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void Object_ApplyHit(void *);
void Object_HitFeedback(void *);
void Object_SpawnHitSpark(void *, s32, s32, s32);

void func_801405C8(void *arg0) {
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
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_80140658 asm("g_Spike");

void func_80140658(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8014059C(arg0);
    Object_TurnToward(arg0, g_Spike_80140658.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike_80140658.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

void func_801406E8(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        func_8014017C(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

void Object_DisableCollision(void *);

void func_8014074C(void *arg0) {
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

s32 func_80140824(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        func_8014059C(arg0);
        return 1;
    }
    return 0;
}

void func_8014074C(void *arg0);
void func_801400EC(void *arg0);
void func_8014059C(void *arg0);
void func_801405C8(void *arg0);
void func_80140658(void *arg0);
void func_801406E8(void *arg0);
s32 func_80140824(void *arg0);
void Object_EnableCollision(void *);
void Object_DebugStub(void *, s32);
void Shadow_Draw(void *, s32, s32, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);
#define ANIM_80140880(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_80140880(u8 *o) {
    s32 st;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8014074C(o);
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u8 *, 0xC9) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        func_801400EC(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (st = M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        Shadow_Draw(o + 0x24, Object_FloorAt(o, 0, 0, 0), M2C_FIELD(o, s16 *, 0xA0), M2C_FIELD(o, s32 *, 0xD0));
        if (Object_Timer(o, -1) == 0
            && Object_SpikeOutOfRange(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s16 *, 0x9E), 1500) == 0) {
            func_80140658(o);
            M2C_FIELD(o, u8 *, 0xC8) = 14;
            Object_EnableCollision(o);
        }
        break;
    case 3:
        Object_TurnTowardSpike(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140880(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            if (M2C_FIELD(o, u8 *, 0x7F) == 1) {
                M2C_FIELD(o, u8 *, 0x7F) = 4;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140880(o, 4)[0];
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = st;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140880(o, 3)[0];
                M2C_FIELD(o, u8 *, 0x8F) = 0;
            }
        }
        break;
    case 4:
        if (func_80140824(o) == 0) {
            if (M2C_FIELD(o, u16 *, 0x5C) == ANIM_80140880(o, M2C_FIELD(o, u8 *, 0x7F))[0] + 20) {
                func_801406E8(o);
            }
            if (M2C_FIELD(o, u8 *, 0x8F) >= 3) {
                M2C_FIELD(o, u8 *, 0x80) = 6;
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140880(o, 0)[0];
                func_8014059C(o);
            }
        }
        break;
    case 6:
        Object_DisableCollision(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140880(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140880(o, 1)[0];
            func_8014059C(o);
            Object_Timer(o, 60);
        }
        break;
    }
    func_801405C8(o);
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_80140B0C;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2a[2]; u16 z; } g_Spike_80140B0C asm("g_Spike");
void CamPoint_GetLookPoint(void *, s32, void *);
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
s32 VectorNormalSS_80140B0C(void *, void *) asm("VectorNormalSS");
s32 SquareRoot0(s32);

void func_80140B0C(u8 *o) {
    SVECTOR v;
    SVECTOR d;
    SVECTOR w;
    s32 dist;
    s32 k;

    ((Scr_80140B0C *)0x1F800000)->spike.vx = g_Spike_80140B0C.x;
    ((Scr_80140B0C *)0x1F800000)->spike.vy = g_Spike_80140B0C.y;
    ((Scr_80140B0C *)0x1F800000)->spike.vz = g_Spike_80140B0C.z;
    CamPoint_GetLookPoint(o, 2, &v);
    d.vx = v.vx - ((Scr_80140B0C *)0x1F800000)->spike.vx;
    d.vy = 0;
    d.vz = v.vz - ((Scr_80140B0C *)0x1F800000)->spike.vz;
    VectorNormalSS_80140B0C(&d, &d);
    w = (SVECTOR){ ((Scr_80140B0C *)0x1F800000)->spike.vx - v.vx, 0, ((Scr_80140B0C *)0x1F800000)->spike.vz - v.vz };
    k = 2000;
    dist = SquareRoot0(w.vx * w.vx + w.vz * w.vz);
    if (dist > 1000) {
        k = dist * 2;
    }
    if (k > 0xD48) {
        k = 0xD48;
    }
    ((Scr_80140B0C *)0x1F800000)->eye.vx = v.vx - ((d.vx * k / 4) >> 12);
    ((Scr_80140B0C *)0x1F800000)->eye.vy = ((Scr_80140B0C *)0x1F800000)->spike.vy - 0x82;
    ((Scr_80140B0C *)0x1F800000)->eye.vz = v.vz - ((d.vz * k / 4) >> 12);
    ((Scr_80140B0C *)0x1F800000)->at.vx = v.vx - (d.vx * k >> 12);
    ((Scr_80140B0C *)0x1F800000)->at.vy = ((Scr_80140B0C *)0x1F800000)->spike.vy - 0x35C;
    ((Scr_80140B0C *)0x1F800000)->at.vz = v.vz - (d.vz * k >> 12);
    Camera_EaseLookAt(o, 8, 8, 8);
    Camera_EaseEye(o, 8, 16, 8);
    w = (SVECTOR){ M2C_FIELD(o, s16 *, 0xA) - v.vx, 0, M2C_FIELD(o, s16 *, 0xE) - v.vz };
    if (VectorNormalSS_80140B0C(&w, &w) <= 0x1DE83F) {
        M2C_FIELD(o, s16 *, 0x12) = (v.vx + w.vx * 350) >> 12;
        M2C_FIELD(o, s16 *, 0x16) = (v.vz + w.vz * 350) >> 12;
        M2C_FIELD(o, s16 *, 0xA) = (v.vx + w.vx * 1400) >> 12;
        M2C_FIELD(o, s16 *, 0xE) = (v.vz + w.vz * 1400) >> 12;
    }
}

s32 func_80140E40(void *arg0) {
    s16 temp_a0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    temp_a0 = M2C_FIELD(temp_a1, s16 *, 0x32);
    if ((temp_a0 == 1) || (temp_a0 == 0x3D) || (temp_a0 == 0xA1) || (temp_a0 == 0xDD)) {
        Sound_PlayAt(0x9C, temp_a1);
    }
    return 0;
}
