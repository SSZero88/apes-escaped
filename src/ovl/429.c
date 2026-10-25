#include "common.h"
#include "m2c_macros.h"

extern u8 g_Game[];
extern u8 D_80139230[];

void func_80136000(u8 *s, s32 x, s32 y, s32 c) {
    SprtTp *p;
    u32 *ot;
    u32 ch;

    p = (SprtTp *)G_DRAW.prim;
    ot = G_DRAW.ot;
    if (x < 0) {
        x = 0xC0 - func_80136120(s) / 2;
    }
    while ((ch = *s) != 0) {
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE1000226;
        p->code = 0x67;
        p->x0 = x;
        p->y0 = y;
        p->u0 = (ch & 0xF) << 4;
        p->v0 = ch & 0xF0;
        p->clut = ((c + 0xF8) << 6) | 0x1C;
        p->w = 0x10;
        p->h = 0x10;
        ADD_PRIM_R(ot, p, "$3", "$2");
        p++;
        s++;
        x += D_80139230[ch];
    }
    G_DRAW.prim = (u8 *)p;
}

s32 func_80136120(u8 *s) {
    s32 w;

    w = 0;
    for (; *s != 0; s++) {
        w += D_80139230[*s];
    }
    return w;
}

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136160);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136554);

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 D_800E78C0;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);

void func_801368E8(SVECTOR *eye, SVECTOR *at) {
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

u8 *func_80136A88(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 new_var;
  int new_var2;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  new_var2 = arg1 > 0;
  var_v1 = 0;
  if (new_var2)
  {
    do
    {
      new_var = var_v1;
      var_v0 = new_var < arg1;
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

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136AB8);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136CC4);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136FF0);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801371C0);

M2C_UNK Cd_ReadFilePart(M2C_UNK, s32, M2C_UNK, s32);
s32 func_801371C0(void *);
extern s16 D_801391B6;
extern s32 D_80139478;

s32 func_80137308(void *obj) {
    D_801391B6 = 4;
    Cd_ReadFilePart(0x54, func_801371C0(obj) * 7, 7, D_80139478);
    return 0;
}

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_8013734C);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137470);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801374DC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801378C4);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137C04);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137D40);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137EF8);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138428);

s32 func_801388A4(void) {
    u8 *p = G_DRAW.prim;

    p[3] = 4;
    p[7] = 0x65;
    M2C_FIELD(p, u16 *, 0xE) = 0x3F5C;
    M2C_FIELD(p, s16 *, 0x8) = 0x28;
    M2C_FIELD(p, s16 *, 0xA) = 0x58;
    M2C_FIELD(p, s16 *, 0x10) = 0x80;
    M2C_FIELD(p, s16 *, 0x12) = 0x60;
    p[0xC] = 0;
    p[0xD] = 0;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 0x14;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000289;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138978);

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_390;

s32 func_80138ABC(void) {
    s32 i;
    s32 s;

    for (i = s = 0; i < 30; i++) {
        s += ((Ent_390 *)0x80102400)[i].f_1;
    }
    return s;
}

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138AEC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138C44);

typedef struct { s16 x, y, w, h; } RECT_80138D7C;
extern char D_80138EDC[];
void LoadImage2(RECT_80138D7C *, u32 *);
void bios_printf(char *, ...);
s32 DrawSync(s32);

s32 func_80138D7C(void) {
    u32 *p;
    RECT_80138D7C r1;
    RECT_80138D7C r2;

    p = D_80139478;
    r2.x = 0x1C0;
    r2.y = 0xFD;
    r2.w = 0x100;
    r2.h = 1;
    r1.x = 0x240;
    r1.w = 0x40;
    r1.y = 0;
    r1.h = 0x80;
    if (*p == 0x10) {
        p++;
        switch (*p & 0xF) {
        case 2:
            LoadImage2(&r1, p + 4);
            break;
        case 8:
        case 9:
            p++;
            LoadImage2(&r2, p + 3);
            p += *p >> 2;
            LoadImage2(&r1, p + 3);
            break;
        default:
            bios_printf(D_80138EDC, *p);
            break;
        }
    }
    DrawSync(0);
    return 0;
}
