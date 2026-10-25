#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Pad { u8 pad_0[0x1BC]; s16 f_1BC; s16 f_1BE; } g_Pad;
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x6]; u16 f_2C; } g_Spike;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

void * Object_AddAttackSphere(void *, s16, s16, s16, s16, s16, s16);
M2C_UNK Object_OrbitAround(void *, s16, s16, s32, s32);
extern s32 D_8014115C;
s16 func_80056010(void *, s16, s16, s32);

extern s32 g_TRexHitFlag;
s32 Collision_GetShape(s32);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8005240C(void *, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 func_8013D000(void);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);

s32 func_8013D000(void) {
    if ((g_Pad.f_1BC >= 0x321) || (g_Pad.f_1BE >= 0x321)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D040);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D260);

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
s32 func_800585D0(void *, s16, s8, s8);

s16 func_8013D6C4(void *arg0, s16 arg1, s16 arg2, s8 arg3) {
    func_800585D0(arg0, arg1, 0, arg3);
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
  func_8005588C(a, 0x1F);
}

void func_800584C8(void *, s8);

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
    func_800584C8(a, 0);
    func_8013D7B4(a, 1);
    return;
  }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D95C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DA44);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DF3C);

void func_8013DF3C(void *, SVECTOR *);
void Effect_SpawnAt(s32, SVECTOR *);

void func_8013DFC4(void *arg0, s32 n, s16 x, s32 z) {
    SVECTOR v;

    v.vx = x;
    v.vy = n * 20 - 0x32;
    v.vz = z - n * 20;
    func_8013DF3C(arg0, &v);
    Effect_SpawnAt(5, &v);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E010);

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
    Object_OrbitAround(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), D_8014115C, (s32) func_80056010(arg0, 5, 2, 6));
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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E320);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E40C);

void func_8013E7D8(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0xC8) != 0) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0xAA;
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        Effect_SpawnAt(0x10B, &v);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E82C);

void func_8013E934(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) - ((s32) -(M2C_FIELD(arg1, s16 *, 0x64) * 0x28) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_a2, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + ((s32) -(M2C_FIELD(arg1, s16 *, 0x60) * 0x28) >> 0xC));
}

void func_80051E98(void *, s32);

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
    func_80051E98(a, 0);
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
    func_8005588C(a, 0x23);
    M2C_FIELD(a, u8 *, 0x80) = 1;
    M2C_FIELD(a, u8 *, 0x7F) = 0;
    M2C_FIELD(a, u16 *, 0x5C) = *M2C_FIELD(a, u16 **, 0x88);
}

void func_8013EB8C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_8005240C(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        Sound_PlayFixed(0x5F);
        Sound_PlayFixed(0x15);
    }
}

typedef struct { u8 pad0[0x80]; u8 f_80; u8 f_81; u8 pad82[0x62]; } Obj_397;
extern Obj_397 g_Objects_397[] asm("g_Objects");
void func_80051E98(void *, s32);

s32 func_8013EBE8(void *arg0, void *arg1) {
    Obj_397 *o;

    o = &g_Objects_397[M2C_FIELD(arg1, s8 *, 0xCA)];
    if (o->f_80 != 1 || o->f_81 == 0) {
        func_80051E98(arg0, 0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EC54);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EED0);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F484);

void func_8013F5FC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) & 1) {
        if ((M2C_FIELD(arg0, u8 *, 0x80) == 7) && ((func_8013D000() << 0x10) != 0)) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
            func_8005588C(arg0, 0x3C);
            return;
        }
        func_8013F368(arg0);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F694);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013FA24);

void func_8013FC44(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void func_8013FC90(void) {
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013FC98);

void func_8013FF84(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80141240[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140024 asm("g_Game");

void func_80140024(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80141240 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game_80140024.f_80 + g_Game_80140024.f_C * 0x4078, &D_800E7D00, m);
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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_801403C0);

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8014059C(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800525E0(void *);
void func_80052864(void *);
void func_800573A0(void *, s32, s32, s32);

void func_801405C8(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
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
    func_8005588C(arg0, M2C_FIELD(arg0, s16 *, 0x9A) % 60 + 60);
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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140880);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140B0C);

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
