#include "common.h"
#include "m2c_macros.h"

M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_8013705C;

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 D_800E78C0;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);
void CompMatrix(void *, void *, void *);
void func_8004637C(void *);
void ScaleMatrixL(void *, void *);

void func_80136000(SVECTOR *eye, SVECTOR *at) {
    VEC_391 d;
    VEC_391 n;
    MAT_391 m;
    VEC_391 s;
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
    func_8004637C(&m);
    s.vx = 0x2000;
    s.vy = 0x2000;
    s.vz = 0x2000;
    ScaleMatrixL(&m, &s);
    CompMatrix(&m, &D_800E78C0, &D_800E78C0);
}

u8 *func_801361D8(u8 *arg0, s32 arg1)
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
      var_a0 += 1;
      var_v0 = var_v1 < arg1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136208);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136724);

extern struct { u8 pad0[0x8280]; s32 f_8280; } g_Game_80136780 asm("g_Game");
extern s32 D_800B4D64;
typedef struct { u8 pad0[0x18]; u8 *f_18; u8 pad1C[0x40]; s16 f_5C, f_5E, f_60, f_62, f_64; u8 pad66[0xA]; s16 f_70, f_72; u8 *f_74; u8 pad78[0x10]; } Obj_80136780;
extern Obj_80136780 D_80136F00[];
u8 *func_8008C09C(s32);
void Model_BindMesh(void *, u32 *);
void func_80015AC0(void *, u8 *);

s32 func_80136780(void) {
    u8 *h;
    s32 i;
    Obj_80136780 *e;
    u8 *q;

    h = (u8 *)0x80154000;
    g_Game_80136780.f_8280 = 2;
    D_800B4D64 = (s32)func_8008C09C(0x40);
    for (i = 0; i < g_Game_80136780.f_8280; i++) {
        Model_BindMesh((void *)(D_800B4D64 + i * 0x20), (u32 *)(h + *(u16 *)(h + i * 4 + 0x14) * 4));
    }
    for (i = 0; i < 2; i++) {
        func_80015AC0(&D_80136F00[i], h + *(u16 *)(h + i * 4 + 4) * 4);
        q = (u8 *)(*(u16 *)(h + i * 4 + 0xC) * 4 + (s32)h);
        D_80136F00[i].f_18 = q + *(s32 *)q * 4 + 4;
        D_80136F00[i].f_74 = h + *(u16 *)(h + i * 4 + 0xC) * 4 + 4;
        D_80136F00[i].f_5C = 0;
        D_80136F00[i].f_5E = 0;
        D_80136F00[i].f_70 = 0;
        D_80136F00[i].f_72 = 0;
        D_80136F00[i].f_60 = 0;
        D_80136F00[i].f_62 = 0;
        D_80136F00[i].f_64 = -0x1000;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_801368CC);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136AA0);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136C04);

void func_80136C6C(void) {
    Cd_PlayXaTrack(D_8013705C);
}

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136C94);
