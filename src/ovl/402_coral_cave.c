#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8013D770(void *);
s16 rcos(s16);
s16 rsin(s16);
s32 func_80055AA0(void *, s16, s16, s16);
s32 func_8013D968(s32 *arg0, s32 arg1, s32 arg2);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);

typedef struct { s16 f0; s16 x, y, z; s16 f8; u16 fA; u8 padC[4]; } Src_8013E1E0;
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 padF[9]; s16 f18; s16 f1A; u8 pad1C[4]; } Pt_8013E1E0;
extern struct { u8 pad0[0x824C]; u8 *f_824C; } g_Game_8013E1E0 asm("g_Game");
extern u8 D_80141750;
extern Pt_8013E1E0 D_80141350[];
s32 Floor_GetHeight_8013E1E0(s32, s32, s32) asm("Floor_GetHeight");

s32 func_8013D000(void) {
    u8 *h;
    Src_8013E1E0 *src;
    s32 i;

    h = g_Game_8013E1E0.f_824C;
    D_80141750 = 0;
    src = (Src_8013E1E0 *)(h + 8);
    if (*(u16 *)h == 0x452E && h[2] == 0x46) {
    } else {
        return 1;
    }
    D_80141750 = h[4];
    if (D_80141750 > 32) {
        D_80141750 = 32;
    }
    for (i = 0; i < D_80141750; i++) {
        D_80141350[i].fE = 0;
        D_80141350[i].x8 = D_80141350[i].x = src[i].x;
        D_80141350[i].yA = D_80141350[i].y = src[i].y;
        D_80141350[i].zC = D_80141350[i].z = src[i].z;
        D_80141350[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x200, src[i].z);
        if (D_80141350[i].floor < src[i].y) {
            D_80141350[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x1000, src[i].z);
        }
        D_80141350[i].f18 = 1;
        D_80141350[i].f1A = src[i].fA;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D15C);

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013D770);

void func_8013D850(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAC);
    temp_v1 = temp_a0 + 0x800;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x17FF;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0);
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    func_8013D770(arg0);
}

extern s32 D_800EC208;

s32 func_8013D8BC(u8 *a)
{
  if (!Object_SpikeInFront(a, 0x5A, 0xB50, 0x400))
  {
    return 0;
  }
  if (Object_SpikeInFront(a, 0x5A, 0xB50, 0x100))
  {
    return 0;
  }
  if ((((D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))) >= 0) ? (D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))) : (-(D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))))) > 0x400)
  {
    return 0;
  }
  if ((*((u16 *) (((s8 *) a) + 0x8C))) != 0)
  {
    return 1;
  }
  if (Object_WouldLeaveHome(a, 0))
  {
    return 0;
  }
  if (D_800EC208)
  {
    return 1;
  }
  else
  {
    return 1;
  }
}

s32 func_8013D968(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < arg2) {
        *arg0 = arg2;
        return 0;
    }
    if (arg1 < temp_v1) {
        *arg0 = arg1;
        return 0;
    }
    return 1;
}

u16 Water_Query(s32, s32, s32);
s16 Object_FloorAt_8013D9A4(void *, s32, s32, s32) asm("Object_FloorAt");
extern u32 g_Game_8013D9A4 asm("g_Game");
extern s32 D_800B1D24;
void func_80070284(void *, s32 *, s32, s32, s32);

void func_8013D9A4(u8 *a, s32 dv, s32 off) {
    SVECTOR v;
    s32 y;
    s32 h;

    y = off + dv;
    if (Water_Query(M2C_FIELD(a, s32 *, 0x24), y, M2C_FIELD(a, s32 *, 0x2C)) >> 12 == 1) {
        if (ABS(M2C_FIELD(a, s16 *, 0x96) + dv) < 0x300) {
            h = Object_FloorAt_8013D9A4(a, 0, 0, 0) - 0x96;
            if (h < y + 300) {
                M2C_FIELD(a, s32 *, 0x28) = h;
            } else {
                M2C_FIELD(a, s32 *, 0x28) = y + 300;
                M2C_FIELD(a, s16 *, 0x96) += dv;
            }
        }
    } else {
        if (g_Game_8013D9A4 % 30 == 0 || g_Game_8013D9A4 % 30 == 5) {
            v.vx = M2C_FIELD(a, u16 *, 0x24);
            v.vy = -0x8E4;
            v.vz = M2C_FIELD(a, u16 *, 0x2C);
            func_80070284(&v, &D_800B1D24, 1, 0, 0);
        }
    }
}

s32 rsin_8013DAD8(s16) asm("rsin");
extern s32 D_800EC208;
void Object_StepOrbitAngle(void *, s16);

void func_8013DAD8(void *arg0) {
    s32 sp10;
    s32 temp_s0;

    sp10 = D_800EC208 - M2C_FIELD(arg0, s32 *, 0x28);
    Object_StepOrbitAngle(arg0, 8);
    temp_s0 = (s32) (rsin_8013DAD8(M2C_FIELD(arg0, s16 *, 0xAA)) * 0xC8) >> 0xC;
    func_8013D968(&sp10, 5, -5);
    func_8013D9A4(arg0, sp10, M2C_FIELD(arg0, s16 *, 0x9C) + M2C_FIELD(arg0, s16 *, 0x96) + temp_s0);
}

void func_8013DB6C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 2;
    M2C_FIELD(arg0, u8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x108;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x10000;
}

s32 func_8013DBAC(void *arg0, s16 arg1) {
    s32 sp10;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x90) + (M2C_FIELD(arg0, u8 *, 0x8E) * 8);
    sp10 = M2C_FIELD(temp_s0, s16 *, 2) - M2C_FIELD(arg0, s32 *, 0x28);
    func_8013D968(&sp10, 0xA, -0xA);
    M2C_FIELD(arg0, u16 *, 0x96) = (u16) sp10;
    return func_80055AA0(arg0, M2C_FIELD(temp_s0, s16 *, 0), M2C_FIELD(temp_s0, s16 *, 4), arg1) != 0;
}

void Object_ApplyVelocity(void *);

s32 func_8013DC34(u8 *o, s32 a) {
    s32 r = 0;

    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        if (func_8013DBAC(o, a)) {
            func_8013DB6C(o);
            r = 1;
        }
        Object_ApplyVelocity(o);
    } else {
        if (func_80055AA0(o, M2C_FIELD(o, s16 *, 0xBC), M2C_FIELD(o, s16 *, 0xC0), a)) {
            func_8013DB6C(o);
            r = 1;
        }
        func_8013DAD8(o);
        M2C_FIELD(o, s32 *, 0x24) += M2C_FIELD(o, s16 *, 0x94);
        M2C_FIELD(o, s32 *, 0x2C) += M2C_FIELD(o, s16 *, 0x98);
    }
    return r;
}

s32 func_8013DCF8(u8 *a, s32 r) {
    s32 ret = 0;
    s32 c;
    s32 dx;
    s32 dz;

    if (M2C_FIELD(a, u16 *, 0x8C) != 0) {
        dx = M2C_FIELD(a, s16 *, 0xBC) - M2C_FIELD(a, s32 *, 0x24);
        dz = M2C_FIELD(a, s16 *, 0xC0) - M2C_FIELD(a, s32 *, 0x2C);
        c = dx * dx + dz * dz < r * r;
    } else {
        func_8013DAD8(a);
        c = Object_WouldLeaveHome(a, 0);
    }
    if (c) {
        func_8013DB6C(a);
        ret = 1;
    }
    return ret;
}

void Object_SetForwardVelocity(void *, s16);

void func_8013DDA8(void *arg0, s16 speed) {
    Object_SetForwardVelocity(arg0, speed);
    M2C_FIELD(arg0, s32 *, 0x24) += M2C_FIELD(arg0, s16 *, 0x94);
    M2C_FIELD(arg0, s32 *, 0x2C) += M2C_FIELD(arg0, s16 *, 0x98);
    func_8013DCF8(arg0, speed);
}

void func_8013DE0C(void *arg0, s32 k, s16 r) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((M2C_FIELD(arg0, s16 *, 0x60) * k) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((M2C_FIELD(arg0, s16 *, 0x64) * k) >> 12);
    Object_AddAttackSphereNear(arg0, r, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
}

void func_8013DEA8(void *arg0) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == 0x14) {
        Object_PlaySound(arg0, 0xB4);
    } else if (d == 0x19) {
        Object_PlaySound(arg0, 0x69);
    }
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013DF04(void *arg0)
{
  SVECTOR v;
  v.vx = (*((u16 *) (((s8 *) arg0) + 0x24))) + (((*((s16 *) (((s8 *) arg0) + 0x60))) * 25) >> 9);
  v.vy = -0x8E4;
  v.vz = (*((u16 *) (((s8 *) arg0) + 0x2C))) + (((*((s16 *) (((s8 *) arg0) + 0x64))) * 25) >> 9);
  Effect_SpawnAt(0x100, &v);
  Object_PlaySound(arg0, 0xA3);
}

s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013DF8C(void *arg0) {
    s32 temp_v0;

    Object_StepGrowShrink(arg0, 0, 0, -4);
    temp_v0 = (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

void func_8013E004(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) - 0x14);
    }
    temp_v0 = ((s32) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) << 0x10) >> 0x13) + 0x21;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) - ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E068);

void func_8013E3A0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 10;
}

M2C_UNK Object_PlaySound(void *, M2C_UNK);
void func_8013E3A0(void *arg0);
void func_8005744C(void *, s32, s32, s32);
void func_800525E0(void *);
void func_80052864(void *);

void func_8013E3F4(u8 *a) {

    if (M2C_FIELD(a, u8 *, 0x80) == 6) {
        return;
    }
    if (Object_DetachLink(a, 0) == 6) {
        func_8013E3A0(a);
    }
    switch (M2C_FIELD(a, u8 *, 0x80)) {
    case 1:
    case 2:
        M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear(a, 100, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, s16 *, 0x28), M2C_FIELD(a, s16 *, 0x2C), M2C_FIELD(a, s16 *, 0x48), M2C_FIELD(a, s16 *, 0x4A));
    default:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB) {
            Object_PlaySound(a, 0x67);
            func_8005744C(a, 0, 0, 0);
            func_8013E3A0(a);
        }
        break;
    case 3:
    case 4:
    case 5:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB && !(M2C_FIELD(a, u8 *, 0xE0) >> 7)) {
            func_800525E0(a);
            func_80052864(a);
        }
        break;
    }
}

extern u16 g_RandSeed;
s16 func_80055DC0_8013E518(void *, s16, s16) asm("func_80055DC0");
void Object_StepOnGroundFixed(void *);

void func_8013E518(void *arg0) {
    if (func_80055DC0_8013E518(arg0, M2C_FIELD(arg0, s16 *, 0xA8), 0x400)) {
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

void func_8013E67C(void *arg0)
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

void func_8013E6E4(void *arg0) {
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

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013E834);

void func_80058134_8013E8B4(void *, s32) asm("func_80058134");
void Object_PlaySound_8013E8B4(void *, s32) asm("Object_PlaySound");
void Object_Destroy_8013E8B4(void *) asm("Object_Destroy");
s32 Object_SpikeNear_8013E8B4(void *, s32) asm("Object_SpikeNear");
void Object_HeadHome_8013E8B4(void *, s32, s32) asm("Object_HeadHome");
void func_8013E834(void *);
void func_8013E3F4(u8 *a);
void func_8013E518(void *arg0);
void func_8013E6E4(void *arg0);

void func_8013E8B4(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_8013E834(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013E8B4(o, M2C_FIELD(o, s16 *, 0x44));
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
        Object_PlaySound_8013E8B4(o, 0x15);
        Object_Destroy_8013E8B4(o);
    }
    func_8013E3F4(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013E518(o);
        break;
    case 2:
        func_8013E6E4(o);
        break;
    case 3:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    case 4:
        func_8013E67C(o);
        if (Object_SpikeNear_8013E8B4(o, 0x200) == 0) {
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
            Object_HeadHome_8013E8B4(o, M2C_FIELD(o, s16 *, 0xA8), 0x400);
        }
        break;
    }
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013EAF8);

void func_8013EC38(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_801417F8[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void func_8013ECD8(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_801417F8 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_80141758");
void func_8013F044(void);
void Hook_Add(void *);

void func_8013EDA0(void *arg0) {
    s32 i;

    func_8013EC38(arg0, D_801417F8, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(func_8013F044);
}

s32 func_8013EDF4(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

s16 rsin_8013D858(s16) asm("rsin");
extern u8 D_80141758[];

void func_8013EE30(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = func_8013EDF4();
  if (i != (-1))
  {
    p = D_80141758 + (i * 0x14);
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

s32 func_8013EF68(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013EFA4(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013EFE4(SVECTOR *p) {
    s32 i;
    SVECTOR v;

    for (i = 0; i < 32; i++) {
        v.vx = p->vx;
        v.vy = p->vy;
        v.vz = p->vz;
        Effect_SpawnAt(10, &v);
    }
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F044);

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013F220(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800525E0(void *);
void func_80052864(void *);
void func_800573A0(void *, s32, s32, s32);

void func_8013F24C(void *arg0) {
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
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013F2DC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013F220(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

void func_8013F36C(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        func_8013EE30(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

void func_8013F3D0(void *arg0) {
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

s32 func_8013F4A8(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        func_8013F220(arg0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013F504);

void func_8013F790(void *arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x80) != 3) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x19) >> 9)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xBE), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x19) >> 9)), 0, 0x100);
    }
}

void func_80059304(SVECTOR *, void *, s32, SVECTOR *);

void func_8013F878(u8 *a, s32 mode) {
    SVECTOR p;
    SVECTOR d;

    if (mode == 0) {
        d.vx = M2C_FIELD(a, s16 *, 0x60) / 32;
        d.vy = M2C_FIELD(a, s16 *, 0x62) / 32;
        d.vz = M2C_FIELD(a, s16 *, 0x64) / 32;
        p.vx = M2C_FIELD(a, u16 *, 0x24) + ((M2C_FIELD(a, s16 *, 0x60) * 45) >> 9);
        p.vy = M2C_FIELD(a, u16 *, 0x28) - 0xBE;
        p.vz = M2C_FIELD(a, u16 *, 0x2C) + ((M2C_FIELD(a, s16 *, 0x64) * 45) >> 9);
        Object_PlaySound(a, 0x58);
        func_80059304(&p, a, 1, &d);
    } else if (mode == 2) {
        Object_PlaySound(a, 0x58);
    }
}

M2C_UNK Object_DisableCollision(void *);

void func_8013F984(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    func_80052038(arg0, 0x9F);
    M2C_FIELD(arg0, s16 *, 0x5E) = 1;
    Object_DisableCollision(arg0);
}

extern u8 D_80141200[];
void func_800702B0(SVECTOR *, void *);
void Object_CameraShake(void *, s32);

void func_8013F9D4(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x64;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    func_800702B0(&v, D_80141200);
    func_800702B0(&v, D_80141200 + 0xC);
    Object_CameraShake(arg0, 0);
    Object_PlaySound(arg0, 0x79);
}

u16 *Collision_GetShape(s16);
s32 func_800525A0(u8 *, u16 *);
void func_800573A0_8013FA50(void *, s16, s16, s16) asm("func_800573A0");
void Object_PlaySound_8013FA50(void *, s32) asm("Object_PlaySound");

s32 func_8013FA50(u8 *o) {
    u16 *s;

    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) != 11) {
        return 0;
    }
    s = Collision_GetShape(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
    func_800525A0(o, s);
    func_800573A0_8013FA50(o, s[0] - M2C_FIELD(o, u16 *, 0x24), M2C_FIELD(o, u16 *, 0x28) - s[2], s[4] - M2C_FIELD(o, u16 *, 0x2C));
    Object_PlaySound_8013FA50(o, 0x60);
    if (M2C_FIELD(o, u8 *, 0x81) != 0) {
        M2C_FIELD(o, u8 *, 0x84) = 20;
        M2C_FIELD(o, u8 *, 0x80) = 5;
        M2C_FIELD(o, u8 *, 0x7F) = 2;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x8);
    } else {
        func_8013F984(o);
        func_8013F9D4(o);
    }
    return 1;
}

void func_8013FB40(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 4) {
        func_8013F984(arg0);
        M2C_FIELD(arg0, u8 *, 0xCF) = 0U;
    }
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_8013FB7C);

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_8013FEF8(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 0);
}

void func_8013FF44(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v1, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

typedef struct { u8 pad[0xE4]; } Obj_8013FF9C;
extern Obj_8013FF9C g_Objects_8013FF9C[] asm("g_Objects");
extern s32 D_80141868;
typedef struct { u8 pad[0x88]; u16 *f_88; } Anim_8013FF9C;
s32 func_80057140(void *, s32, s32);
void func_80051E98(void *, s32);
void func_8013FEF8(void *arg0);
void func_8013FF44(void *arg0, void *arg1);

void func_8013FF9C(u8 *o) {
    u8 *t = (u8 *)&g_Objects_8013FF9C[M2C_FIELD(o, s8 *, 0xCA)];

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x44;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x42000;
        M2C_FIELD(o, s32 *, 0x74) = func_80057140(o, 6, 0x45);
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(t, u8 *, 0x80) == 3) {
        func_80051E98(o, 0);
    }
    func_8013FF44(o, t);
    func_8013FEF8(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(t, u8 *, 0x80) == 4) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_PlaySound(o, 0x52);
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            D_80141868 = 1;
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ((Anim_8013FF9C *)o)->f_88[M2C_FIELD(o, u8 *, 0x7F) * 2];
        }
        break;
    case 3:
        if (M2C_FIELD(t, u8 *, 0x80) != 2) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    }
}

s16 Object_FloorAt(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);

s32 func_80140168(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos_801401E0(s16) asm("rcos");
s32 rsin_801401E0(s16, s32) asm("rsin");

void func_801401E0(void *arg0) {
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
    temp_a1 = (s32) (rcos_801401E0(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin_801401E0(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

s32 Spike_WithinRadiusXZ(s32, s32, s32);

void func_801402BC(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

M2C_UNK Object_PlaySound(void *, M2C_UNK);

void func_8014033C(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_801403E0);

s32 Math_Atan2(s32, s32);

void func_8014061C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_801406A8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
}

s32 func_800563E0(void *, s32);

void func_801406F8(void *arg0) {
    func_800563E0(arg0, 0x14);
}

M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos_80140718(s16) asm("rcos");
s32 rsin_80140718(s16) asm("rsin");

void func_80140718(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_801406F8(arg0);
}

s32 Object_AddAttackSphereNear_801407DC(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
void Object_PlaySound_801407DC(void *, s32) asm("Object_PlaySound");
void func_8014061C(void *arg0);

void func_801407DC(u8 *a) {
    s16 *v;

    if (Object_DetachLink(a, 0) == 6) {
        Object_PlaySound_801407DC(a, 0x5F);
        func_8014061C(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(a, 0x53, 0x37, 0);
    }
    if (func_80055718(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        func_8014061C(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear_801407DC(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

s32 func_80140900(void *arg0) {
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

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140984);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140C78 asm("g_Game");
s32 Model_SetTurnAngle_80140C78(s16, s16, s32) asm("Model_SetTurnAngle");

s32 func_80140C78(s16 *p) {
    u8 *e;

    if (p[5] == 0) {
        p[1] = 0;
        if (p[6] >= 0) {
            e = g_Game_80140C78.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[7] >= 0) {
            e = g_Game_80140C78.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[8] >= 0) {
            e = g_Game_80140C78.f_820C + p[8] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[9] >= 0) {
            e = g_Game_80140C78.f_820C + p[9] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        p[3] = 0;
    } else {
        p[1] = 2;
        if (p[6] >= 0) {
            e = g_Game_80140C78.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[7] >= 0) {
            e = g_Game_80140C78.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[8] >= 0) {
            e = g_Game_80140C78.f_820C + p[8] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[9] >= 0) {
            e = g_Game_80140C78.f_820C + p[9] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        p[3] = 0x400;
        Model_SetTurnAngle_80140C78(p[4], p[10], p[3]);
        Model_SetTurnAngle_80140C78(p[4], p[11], p[3]);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/402/nonmatchings/402_coral_cave", func_80140EF8);
