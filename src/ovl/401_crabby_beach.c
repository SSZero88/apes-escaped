#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
void CamPoint_GetLookPoint(void *, s32, void *);
void VectorNormalSS(void *, void *);
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

void func_8013D168(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 10;
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
u32 Object_DetachLink(void *, s32);
void func_8013D168(void *arg0);
void Object_SpawnImpactFx(void *, s32, s32, s32);
void Object_ApplyHit(void *);
void Object_HitFeedback(void *);

void func_8013D1BC(u8 *a) {

    if (M2C_FIELD(a, u8 *, 0x80) == 6) {
        return;
    }
    if (Object_DetachLink(a, 0) == 6) {
        func_8013D168(a);
    }
    switch (M2C_FIELD(a, u8 *, 0x80)) {
    case 1:
    case 2:
        M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear(a, 100, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, s16 *, 0x28), M2C_FIELD(a, s16 *, 0x2C), M2C_FIELD(a, s16 *, 0x48), M2C_FIELD(a, s16 *, 0x4A));
    default:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB) {
            Object_PlaySound(a, 0x67);
            Object_SpawnImpactFx(a, 0, 0, 0);
            func_8013D168(a);
        }
        break;
    case 3:
    case 4:
    case 5:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB && !(M2C_FIELD(a, u8 *, 0xE0) >> 7)) {
            Object_ApplyHit(a);
            Object_HitFeedback(a);
        }
        break;
    }
}

extern u16 g_RandSeed;
s16 func_80055DC0_8013D2E0(void *, s16, s16) asm("Object_Wander");
void Object_StepOnGroundFixed(void *);

void func_8013D2E0(void *arg0) {
    if (func_80055DC0_8013D2E0(arg0, M2C_FIELD(arg0, s16 *, 0xA8), 0x400)) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        M2C_FIELD(arg0, s16 *, 0x94) = M2C_FIELD(arg0, s16 *, 0x94) * -1;
        M2C_FIELD(arg0, s16 *, 0x98) = M2C_FIELD(arg0, s16 *, 0x98) * -1;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x96) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        if (M2C_FIELD(arg0, s16 *, 0xA8) == 20) {
            M2C_FIELD(arg0, s16 *, 0xA8) = 35;
            M2C_FIELD(arg0, u16 *, 0x94) *= 2;
            M2C_FIELD(arg0, u16 *, 0x98) *= 2;
        } else {
            M2C_FIELD(arg0, s16 *, 0xA8) = 20;
            if (M2C_FIELD(arg0, s16 *, 0x94) * M2C_FIELD(arg0, s16 *, 0x94) + M2C_FIELD(arg0, s16 *, 0x98) * M2C_FIELD(arg0, s16 *, 0x98) >= 26) {
                M2C_FIELD(arg0, s16 *, 0x94) >>= 1;
                M2C_FIELD(arg0, s16 *, 0x98) >>= 1;
            }
        }
    }
    Object_StepOnGroundFixed(arg0);
}

s32 Object_SpikeWithin(void *, s32);

void func_8013D444(void *arg0)
{
  int new_var;
  s32 new_var2;
  new_var2 = Object_SpikeWithin(arg0, 0x96);
  new_var = 0x46;
  *((s16 *) (((s8 *) arg0) + new_var)) = (new_var2) ? (-0x3C) : (0x3C);
  if (Object_SpikeWithin(arg0, 0x64))
  {
    *((u32 *) (((s8 *) arg0) + 0xE0)) |= 0x80;
  }
  else
  {
    *((u32 *) (((s8 *) arg0) + 0xE0)) &= ~0x80;
  }
}

s32 Object_WouldLeaveHome(void *, s16);
s16 Object_FloorAt(void *, s32, s32, s32);

void func_8013D4AC(void *arg0) {
    SVECTOR v;
    s16 sp;
    s32 f;

    f = M2C_FIELD(arg0, s16 *, 0xAE);
    if (f != 0) {
        if (f >= 11) {
            sp = M2C_FIELD(arg0, s16 *, 0xA8) * 2;
        } else {
            sp = M2C_FIELD(arg0, s16 *, 0xA8) * f / 10 * 2;
        }
        if (M2C_FIELD(arg0, s16 *, 0xB2) > 0) {
            v.vx = (M2C_FIELD(arg0, s16 *, 0x64) * sp) >> 12;
            v.vz = -(M2C_FIELD(arg0, s16 *, 0x60) * sp) >> 12;
        } else {
            v.vx = -(M2C_FIELD(arg0, s16 *, 0x64) * sp) >> 12;
            v.vz = (M2C_FIELD(arg0, s16 *, 0x60) * sp) >> 12;
        }
        if (Object_WouldLeaveHome(arg0, 0) == 0) {
            M2C_FIELD(arg0, s32 *, 0x24) += v.vx;
            M2C_FIELD(arg0, s32 *, 0x2C) += v.vz;
            M2C_FIELD(arg0, s32 *, 0x28) = Object_FloorAt(arg0, 0, 0, 0);
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
    }
}

typedef struct { u8 p0[0x44]; s16 f44; s16 f46; s16 f48; s16 f4A; u8 p4C[0x10]; u16 f5C; u8 p5E[0x21]; u8 f7F; u8 p80[8]; u16 *f88; u8 p8C[0x14]; s16 fA0; u8 pA2[6]; s16 fA8; u8 pAA[6]; s16 fB0; u8 pB2[0x1B]; u8 fCD; u8 pCE[0xE]; u8 fDC; u8 pDD[3]; u32 fE0; } Obj_8013D5FC;

void func_8013D5FC(void *arg0) {
    ((Obj_8013D5FC *)arg0)->fA0 = 0x32;
    ((Obj_8013D5FC *)arg0)->fB0 = 0x5B;
    ((Obj_8013D5FC *)arg0)->f44 = 0x32;
    ((Obj_8013D5FC *)arg0)->f4A = -0x7DFC;
    ((Obj_8013D5FC *)arg0)->f48 = 0x600;
    ((Obj_8013D5FC *)arg0)->f46 = 0x3C;
    ((Obj_8013D5FC *)arg0)->fCD = 2;
    ((Obj_8013D5FC *)arg0)->fDC = 0;
    ((Obj_8013D5FC *)arg0)->f7F = 0;
    ((Obj_8013D5FC *)arg0)->fE0 &= ~0x10000;
    ((Obj_8013D5FC *)arg0)->fE0 &= ~0x1000;
    *(volatile u32 *)&((Obj_8013D5FC *)arg0)->fE0 |= 0x200000;
    ((Obj_8013D5FC *)arg0)->f5C = *((Obj_8013D5FC *)arg0)->f88;
    ((Obj_8013D5FC *)arg0)->fA8 = 0x23;
}

void func_80058134_8013D67C(void *, s32) asm("Object_DebugStub");
void Object_PlaySound_8013D67C(void *, s32) asm("Object_PlaySound");
void Object_Destroy_8013D67C(void *) asm("Object_Destroy");
s32 Object_SpikeNear_8013D67C(void *, s32) asm("Object_SpikeNear");
void Object_HeadHome_8013D67C(void *, s32, s32) asm("Object_HeadHome");
void func_8013D1BC(u8 *a);
void func_8013D2E0(void *arg0);
void func_8013D4AC(void *arg0);

void func_8013D67C(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_8013D5FC(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013D67C(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        if (((M2C_FIELD(o, u32 *, 0xE0) >> 10) & 1) == 0) {
            M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFF3FFFFF) | 0x400000;
            M2C_FIELD(o, s16 *, 0xD4) = (M2C_FIELD(o, s16 *, 0xD4) + 0x1B8) % 4096;
        } else {
            M2C_FIELD(o, u32 *, 0xE0) &= 0xFF3FFFFF;
        }
        return;
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x100000;
        Object_PlaySound_8013D67C(o, 0x15);
        Object_Destroy_8013D67C(o);
    }
    func_8013D1BC(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013D2E0(o);
        break;
    case 2:
        func_8013D4AC(o);
        break;
    case 3:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    case 4:
        func_8013D444(o);
        if (Object_SpikeNear_8013D67C(o, 0x200) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, u32 *, 0xE0) &= ~0x80;
            M2C_FIELD(o, s16 *, 0x46) = 0x3C;
        }
        break;
    case 5:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_HeadHome_8013D67C(o, M2C_FIELD(o, s16 *, 0xA8), 0x400);
        }
        break;
    }
}

s16 Object_FloorAt(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);
extern s32 D_800EC208;

s32 func_8013D8C0(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

void func_8013D938(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

s32 Spike_WithinRadiusXZ(s32, s32, s32);

void func_8013DA14(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
u32 Object_DetachLink(void *, s32);

void func_8013DA94(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

void Object_PlaySound_8013DB38(void *, s32) asm("Object_PlaySound");
s32 Object_FlyAboveFloor(void *, s32);
void func_80058134_8013DB38(void *, s32) asm("Object_DebugStub");
void func_8013D938(void *arg0);
void func_8013DA14(void *arg0);
void func_8013DA94(void *arg0);

void func_8013DB38(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(arg0, s16 *, 0x48) = 1;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x58;
        M2C_FIELD(arg0, s16 *, 0x46) = 0x114;
        M2C_FIELD(arg0, u8 *, 0xCD) = 4;
        M2C_FIELD(arg0, u8 *, 0xDC) = 0;
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013DB38(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    switch (M2C_FIELD(arg0, u8 *, 0x80)) {
    case 1:
        if (func_8013D8C0(arg0) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = 1;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[2];
            M2C_FIELD(arg0, s16 *, 0x96) = 4;
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 1, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C), M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 2:
        if ((s16)Object_FlyAboveFloor(arg0, 0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
            Object_PlaySound_8013DB38(arg0, 0xA2);
        }
        M2C_FIELD(arg0, s16 *, 0x96) += 6;
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 1 && M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    case 3:
        func_8013DA94(arg0);
        func_8013D938(arg0);
        func_8013DA14(arg0);
        break;
    case 4:
        if (M2C_FIELD(arg0, u16 *, 0x5C) >= M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    }
}

void func_8013DD74(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013DDB4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013DDF8(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

void func_80058134_8013DE74(void *, s32) asm("Object_DebugStub");
void func_80052038_8013DE74(void *, s32) asm("Object_SetModel");
void Object_DisableCollision_8013DE74(void *) asm("Object_DisableCollision");
void Object_EnableCollision_8013DE74(void *) asm("Object_EnableCollision");
void Object_PlaySound_8013DE74(void *, s32) asm("Object_PlaySound");
void func_8013DD74(void *arg0);
void func_8013DDB4(void *arg0);
void func_8013DDF8(void *arg0);

void func_8013DE74(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 0xFA;
        M2C_FIELD(o, s16 *, 0x46) = 0x200;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision_8013DE74(o);
        func_80052038_8013DE74(o, 0x84);
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        M2C_FIELD(o, u8 *, 0x80) = 2;
        M2C_FIELD(o, u8 *, 0x7F) = 1;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        Object_EnableCollision_8013DE74(o);
        func_80052038_8013DE74(o, 0x84);
        Object_PlaySound_8013DE74(o, 0x5C);
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    func_80058134_8013DE74(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, s16 *, 0xC2) = 0x12C;
            func_8013DD74(o);
            func_8013DDF8(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8013DDB4(o);
            Object_PlaySound_8013DE74(o, 0x5E);
        }
        break;
    case 4:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80052038_8013DE74(o, 0x19);
            Object_DisableCollision_8013DE74(o);
        }
        break;
    }
}

void func_8013E090(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0x48) = 1;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, u8 *, 0xC8) = 7;
        M2C_FIELD(arg0, s16 *, 0x4A) = 0x103;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
}

extern struct { u8 pad_0[0x812C]; u8 f_812C; u8 pad_812D[0x12B]; u16 f_8258; } g_Game_8013E0F4 asm("g_Game");
extern u8 D_800E6908;
extern s32 D_800EC204;
extern s16 D_8013E9A4;
extern s16 D_8013E9A6;
void Sound_PlayAt(s32, void *);

s32 func_8013E0F4(void) {
    SVECTOR v;

    if (g_Game_8013E0F4.f_812C == 0x18 || D_800E6908 == 1) {
        v.vx = g_Game_8013E0F4.f_8258;
    } else {
        v.vx = D_800EC204;
    }
    v.vy = -0x800;
    v.vz = -0x1200;
    if (D_8013E9A4 == 0) {
        if (D_8013E9A6 == 0x78) {
            Sound_PlayAt(0xAC, &v);
            D_8013E9A4 = 1;
            D_8013E9A6 = 0;
        }
    } else {
        if (D_8013E9A6 == 0x46) {
            Sound_PlayAt(0xAD, &v);
            D_8013E9A4 = 0;
            D_8013E9A6 = 0;
        }
    }
    {
        s16 *c = &D_8013E9A6;
        s32 r = 0;
        __asm__("" : "+r"(r));
        __asm__("" : : "r"(r), "r"(r));
        *c += 1;
        return r;
    }
}

extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game;
s16 func_80092324(s16 *, u16 *);

s32 func_8013E1E4(s16 *p) {
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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E278 asm("g_Game");
s32 Model_SetTurnAngle(s16, s16, s32);
extern struct { u8 pad_0[0x24]; s32 f_24; u8 pad_28[4]; s32 f_2C; } g_Spike_8013E278 asm("g_Spike");

s32 func_8013E278(s16 *p) {
    u8 *e = g_Game_8013E278.f_820C + p[2] * 0x38;

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
            if (g_Spike_8013E278.f_24 >= 0 || g_Spike_8013E278.f_2C < -0x7FF) Sound_PlayAt(0xB2, e);
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
    Model_SetTurnAngle(3, p[6], p[11]);
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E424 asm("g_Game");
extern u8 *D_800B4D64_8013E424 asm("g_StageMeshes");

s32 func_8013E424(s16 *p) {
    u8 *e = g_Game_8013E424.f_820C + p[2] * 0x38;
    u8 *e2;

    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 0x8);
    e2 = g_Game_8013E424.f_820C + p[5] * 0x38;
    M2C_FIELD(e2, u16 *, 0x26) = M2C_FIELD(e2, u16 *, 0x8);
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        *M2C_FIELD(D_800B4D64_8013E424 + M2C_FIELD(e, s16 *, 0xE) * 32, u32 **, 0) |= 0x2000;
    }
    if (p[10] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 4;
        p[3] = 0;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013E424 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x18) = 0x2000;
        }
        M2C_FIELD(e, s16 *, 0x8) = 0;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        M2C_FIELD(e2, s16 *, 0x8) = 0;
        M2C_FIELD(e2, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E52C asm("g_Game");
extern u8 *D_800B4D64_8013E52C asm("g_StageMeshes");
void Camera_StartShake(s32);
void Pad_Vibrate(s32, s32, s32);

s32 func_8013E52C(s16 *p) {
    s16 *e = (s16 *)(g_Game_8013E52C.f_820C + p[2] * 0x38);
    s16 *e2 = (s16 *)(g_Game_8013E52C.f_820C + p[5] * 0x38);

    switch (p[1]) {
    case 0:
        if (e[0xF] >= 0 || e2[0xF] >= 0) {
            Camera_StartShake(0);
            Pad_Vibrate(0, 1, 3);
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        p[3] += p[6];
        if (p[3] > 0x1000) {
            p[3] = 0x1000;
            p[1] = 2;
        }
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8013E52C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        e[4] = (0x2000 - p[3]) * e[0x13] / 8192;
        e2[4] = (0x2000 - p[3]) * e2[0x13] / 8192;
        break;
    case 2:
        if (e[0xF] >= 0 || e2[0xF] >= 0) {
            Camera_StartShake(0);
            Pad_Vibrate(0, 1, 3);
            p[1] = 3;
        }
        break;
    case 3:
        p[3] += p[6];
        if (p[3] > 0x2000) {
            p[3] = 0x2000;
            p[1] = 4;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            e = (s16 *)(g_Game_8013E52C.f_820C + p[5] * 0x38);
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8013E52C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        e[4] = (0x2000 - p[3]) * e[0x13] / 8192;
        e2[4] = (0x2000 - p[3]) * e2[0x13] / 8192;
        break;
    case 4:
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013E76C asm("g_Spike");
void Sound_PlayAt(s32, void *);

s32 func_8013E76C(s16 *p) {
    u8 *e;
    s16 f;

    if (g_Spike_8013E76C.x >= 0) {
        return 0;
    }
    if (g_Spike_8013E76C.z < -0x7FF) {
        return 0;
    }
    e = g_Game.f_820C + p[2] * 0x38;
    f = M2C_FIELD(e, s16 *, 0x32);
    if (f != 2 && f != 0x3C && f != 0x66 && f != 0xA0) {
        return 0;
    }
    Sound_PlayAt(0x9C, e);
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
