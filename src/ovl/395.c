#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8008DDB0(s16, s16);
M2C_UNK func_8008DDC8(s32);
extern M2C_UNK D_80138CA0;
M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_80138CEC;

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
  u8 *new_var;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      new_var = var_a0;
      if ((*new_var) == 0)
      {
        var_v1 += 1;
        var_v0 = var_v1 < arg1;
      }
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136208);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136954);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137214);

void func_80137334(s32 arg0) {
    func_8008DDB0(M2C_FIELD(&D_80138CA0, s16 *, 0), M2C_FIELD(&D_80138CA0, s16 *, 2));
    func_8008DDC8(arg0);
    func_8008DDB0((s16) ((u16) M2C_FIELD(&D_80138CA0, s16 *, 0) + 1), M2C_FIELD(&D_80138CA0, s16 *, 2));
    func_8008DDC8(arg0);
}

extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; } g_Game;
typedef struct { s16 x, y, w, h; } Rect_801373A4;
void SetDrawMove(void *p, void *rect, s32 x, s32 y);
extern s32 D_80138CFC;
extern u8 *D_800EC354;

void func_801373A4(void) {
    u8 *p;
    u32 *ot;
    Rect_801373A4 r;
    s32 k;

    k = 0;
    if (D_80138CFC >= 6 && D_80138CFC < 100) {
        switch (D_80138CFC % 15) {
        case 0:
            k = 1;
            break;
        case 7:
            k = 2;
            break;
        }
    }
    if (k != 0) {
        p = G_DRAW.prim;
        r.w = 0x10;
        r.h = 0x10;
        r.x = 0x230;
        ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
        switch (k) {
        case 1:
            r.y = 0x70;
            break;
        case 2:
            r.y = 0xB0;
            break;
        }
        SetDrawMove(p, &r, 0x230, 0x30);
        ADD_PRIM_R(ot, p, "$2", "$3");
        p += 0x18;
        D_800EC354 = p;
    }
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801374D0);

void SetDrawStp(void *, s32);

void func_80137CD4(void) {
    u8 *p;
    u32 *ot;

    p = G_DRAW.prim;
    SetDrawStp(p, 1);
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    G_DRAW.prim = p + 0xC;
}

typedef struct { s16 x, y, w, h; } Rect_391;
void SetDrawMove(void *p, void *rect, s32 x, s32 y);

void func_80137D4C(s32 row)
{
  u8 *p;
  u32 *ot;
  Rect_391 r;
  u8 *new_var;
  p = (*((GameDraw *) (&g_Game))).prim;
  r.w = 0x10;
  r.h = 0x40;
  r.x = 0x230;
  r.y = (row * 64) + 0x40;
  SetDrawMove(p, &r, 0x230, 0);
  ot = &(*((GameDraw *) (&g_Game))).db[(*((GameDraw *) (&g_Game))).cur].ot[0xFFF];
  __asm__ volatile("lwl " "$4" ", 2(%0)\n\tsll " "$3" ", %2, 8\n\tswl " "$3" ", 2(%0)\n\tswl " "$4" ", %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$4", "$3");
  p = p + 0x18;
  new_var = p;
  (*((GameDraw *) (&g_Game))).prim = new_var;
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137DF0);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801380D8);

extern u32 *D_80138CD0;

void func_801383B8(void) {
    u32 *b = (u32 *)0x80154000;

    D_80138CD0 = b + M2C_FIELD(b, u16 *, 0x1C);
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801383D8);

void func_80138468(void) {
    Cd_PlayXaTrack(D_80138CEC);
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80138490);
