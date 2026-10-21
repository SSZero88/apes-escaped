#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80136000);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013606C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801375C0);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137714);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013786C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137950);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801382D8);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801383EC);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80138468);

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 D_800E78C0;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);

void func_80138560(SVECTOR *eye, SVECTOR *at) {
    VEC_391 d;
    VEC_391 n;
    s32 nx;
    s32 nz;
    s32 ny;
    s32 h;

    D_800E78C0.t[0] = -eye->vx;
    D_800E78C0.t[1] = -eye->vy;
    D_800E78C0.t[2] = -eye->vz;
    d.vx = at->vx - eye->vx;
    d.vy = 0;
    d.vz = at->vz - eye->vz;
    if (d.vx == 0 && d.vz == 0) {
        d.vz = 0x1000;
    }
    VectorNormal(&d, &n);
    nx = -n.vx;
    nz = n.vz;
    d.vy = at->vy - eye->vy;
    VectorNormal(&d, &n);
    ny = n.vy;
    h = SquareRoot0(n.vz * n.vz + n.vx * n.vx);
    D_800E78C0.m[0][0] = nz;
    D_800E78C0.m[0][1] = 0;
    D_800E78C0.m[0][2] = nx;
    D_800E78C0.m[1][0] = (nx * ny) >> 12;
    D_800E78C0.m[1][1] = h;
    D_800E78C0.m[1][2] = -(ny * nz) >> 12;
    D_800E78C0.m[2][0] = -(h * nx) >> 12;
    D_800E78C0.m[2][1] = ny;
    D_800E78C0.m[2][2] = (h * nz) >> 12;
    ApplyMatrixLV(&D_800E78C0, D_800E78C0.t, D_800E78C0.t);
    CompMatrix(&D_800AF0A0, &D_800E78C0, &D_800E78C0);
}

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80138700);

u8 *func_801387FC(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      var_v0 = var_v1 < arg1;
      if ((*var_a0) == 0)
      {
        var_v1 += 1;
      }
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013882C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013886C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013893C);
