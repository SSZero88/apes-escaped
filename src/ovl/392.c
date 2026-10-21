#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_80139628(s32);
extern M2C_UNK D_8013B490;
extern M2C_UNK D_8013B998;

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
  if (0 < arg1)
  {
    do
    {
      var_v0 = var_v1 < arg1;
      if (arg1)
      {
      }
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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136208);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136394);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136588);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013683C);

INCLUDE_RODATA("asm/ovl/392/nonmatchings/392", D_8013ADB0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136A1C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136EAC);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80137198);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801375B4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80137C88);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801380DC);

extern u32 *D_8013B9C8;

void func_80138118(void) {
    u32 *b = (u32 *)0x80154000;

    D_8013B9C8 = b + M2C_FIELD(b, u16 *, 0x34);
}

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138138);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138370);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801385B0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138E04);

void func_8013912C(void *arg0, s32 arg1) {
    if ((arg1 > 0) && (M2C_FIELD(arg0, s16 *, 0) >= 0)) {
        M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 2);
        M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 4);
        func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 0)));
        if ((arg1 >= 2) && (M2C_FIELD(arg0, s16 *, 6) >= 0)) {
            M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 8);
            M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
            func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 6)));
            if ((arg1 >= 3) && (M2C_FIELD(arg0, s16 *, 0xC) >= 0)) {
                M2C_FIELD(&D_8013B998, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
                M2C_FIELD(&D_8013B998, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
                func_80139628(func_801361D8(&D_8013B490, M2C_FIELD(arg0, s16 *, 0xC)));
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139248);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801394D0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139628);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139710);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801397F4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801399A4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139E0C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139EE0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139FB8);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A10C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A334);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A3C4);

typedef struct { s16 x, y; s32 z; } Pt_391;
void *func_8008C09C(s32);
s32 rcos(s32);
s32 rsin(s32);
extern Pt_391 *D_80139E28_80138B0C asm("D_8013B9F8");

void func_8013A7A8(void)
{
  Pt_391 *p;
  s32 r;
  s32 k;
  s32 a;
  s32 a0;
  s32 rad;
  p = (D_80139E28_80138B0C = func_8008C09C(0x600));
  for (a0 = 0, r = 0; r < 12; r++, a0 += 0x80)
  {
    rad = ((r * r) * 300) / 144;
    for (k = 0, a = a0; k < 16; k++)
    {
      p->x = ((rcos(a) * rad) >> 12) + 0xC0;
      p->y = ((rsin(a) * rad) >> 12) + 0x78;
      p->z = 0;
      a += 0x100;
      p++;
    }

  }

}

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A8C0);

typedef struct { u32 xy; u32 c; } GridPt_391;
typedef struct { u32 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4_391;
extern struct S_g_Game { u8 pad_0[0x8126]; u16 f_8126; } g_Game;
extern GridPt_391 *D_8013B9F8;
void func_8013A8C0(void);

void func_8013AABC(void) {
    PolyG4_391 *p;
    u32 *ot;
    GridPt_391 *g;
    GridPt_391 *n;
    s32 i;
    s32 j;

    p = (PolyG4_391 *)G_DRAW.prim;
    ot = G_DRAW.ot + 0xFFF;
    g = D_8013B9F8;
    func_8013A8C0();
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 16; j++) {
            if (j == 15) {
                n = g - 15;
            } else {
                n = g + 1;
            }
            p->c0 = g[0].c;
            p->c1 = n[0].c;
            p->c2 = g[16].c;
            p->c3 = n[16].c;
            ((u8 *)p)[3] = 8;
            ((u8 *)p)[7] = 0x38;
            p->xy0 = g[0].xy;
            p->xy1 = n[0].xy;
            p->xy2 = g[16].xy;
            p->xy3 = n[16].xy;
            ADD_PRIM_R(ot, p, "$3", "$2");
            p++;
            g++;
        }
    }
    G_DRAW.prim = (u8 *)p;
}

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013ABD4);
