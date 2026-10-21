#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
void VectorNormalSS(void *, void *);
extern struct { u8 pad0[0xA]; s16 f_A; } D_800E68C0;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike;

void func_8013D000(void *arg0) {
    SVECTOR v;

    ((Scr_401 *)0x1F800000)->spike.vx = g_Spike.x;
    ((Scr_401 *)0x1F800000)->spike.vy = g_Spike.y;
    ((Scr_401 *)0x1F800000)->spike.vz = g_Spike.z;
    func_8004B8F4(arg0, 2, &v);
    v.vy += D_800E68C0.f_A;
    ((Scr_401 *)0x1F800000)->eye.vx = ((Scr_401 *)0x1F800000)->spike.vx;
    ((Scr_401 *)0x1F800000)->eye.vy = g_Spike.y - 0x100;
    ((Scr_401 *)0x1F800000)->eye.vz = ((Scr_401 *)0x1F800000)->spike.vz;
    func_80047558(arg0, 6, 6, 6);
    ((Scr_401 *)0x1F800000)->at.vx = (v.vx * 7 + ((Scr_401 *)0x1F800000)->spike.vx) / 8;
    ((Scr_401 *)0x1F800000)->at.vy = v.vy - D_800E68C0.f_A * 2;
    ((Scr_401 *)0x1F800000)->dir.vx = ((Scr_401 *)0x1F800000)->spike.vx - M2C_FIELD(arg0, s16 *, 0xA);
    ((Scr_401 *)0x1F800000)->dir.vy = 0;
    ((Scr_401 *)0x1F800000)->dir.vz = ((Scr_401 *)0x1F800000)->spike.vz - M2C_FIELD(arg0, s16 *, 0xE);
    VectorNormalSS(&((Scr_401 *)0x1F800000)->dir, &((Scr_401 *)0x1F800000)->dir);
    ((Scr_401 *)0x1F800000)->at.vz = ((Scr_401 *)0x1F800000)->spike.vz - ((Scr_401 *)0x1F800000)->dir.vz / 3;
    func_80047464(arg0, 6, 6, 6);
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

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D1BC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D2E0);

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

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D4AC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D5FC);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013D67C);

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

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013DB38);

void func_8013DD74(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013DDB4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
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

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013DE74);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E090);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E0F4);

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

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E278);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E424);

INCLUDE_ASM("asm/ovl/401/nonmatchings/401_crabby_beach", func_8013E52C);

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
