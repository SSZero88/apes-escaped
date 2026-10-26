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

typedef struct { u8 pad0[0x14]; void *f14; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u16 anim; SVECTOR rot; u8 pad68[8]; s16 next; u16 flags; s16 (*anims)[2]; s16 tr[3]; s16 rsteps; s16 tp[3]; s16 psteps; } Mdl_80137DF0;
typedef struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } Game_80137DF0;
extern Game_80137DF0 g_Game_80137DF0 asm("g_Game");
extern u8 D_800E7D00[];
void VectorNormalSS(void *, void *);
void func_80014804(void *, void *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4(void *, void *, void *);

void func_80137DF0(Mdl_80137DF0 *arr) {
    Mdl_80137DF0 *o;
    SVECTOR m;
    s32 i;
    s32 n;
    s32 m2;
    s32 dx, dy, dz;
    s32 x, y, z;
    s16 (*an)[2];

    for (i = 0; i < 5; i++) {
        o = &arr[i];
        if (!(o->flags & 1)) {
            continue;
        }
        n = o->rsteps;
        if (n > 0) {
            o->rot.vx += (o->tr[0] - o->rot.vx) / n;
            o->rot.vy += (o->tr[1] - o->rot.vy) / n;
            o->rot.vz += (o->tr[2] - o->rot.vz) / n;
            o->rsteps = --n;
        }
        m2 = o->psteps;
        if (m2 > 0) {
            o->x += (o->tp[0] - o->x) / m2;
            o->y += (o->tp[1] - o->y) / m2;
            o->z += (o->tp[2] - o->z) / m2;
            o->psteps = --m2;
        }
        VectorNormalSS(&o->rot, &m);
        func_80014804(&m, o->f14);
        an = o->anims;
        o->frame++;
        if (an[o->anim][1] < o->frame) {
            o->frame = an[o->next][0];
            o->anim = o->next;
        }
        func_80015780(o, 1);
        Model_ProjectBonedVerts(o);
        func_80017CD4(g_Game_80137DF0.db[g_Game_80137DF0.cur].ot, D_800E7D00, o);
    }
}

typedef struct { s16 m[3][3]; s32 t[3]; } MAT_801380D8;
typedef struct { u8 b[0x10]; } Mdl_801380D8;
extern MAT_801380D8 D_800E78C0_801380D8 asm("D_800E78C0");
extern MAT_801380D8 D_800AF0A0_801380D8 asm("D_800AF0A0");
extern MAT_801380D8 D_800AE840;
extern s32 D_80138CE8;
extern Mdl_801380D8 D_800EC060[];
extern Mdl_801380D8 D_800EC0D0;
typedef struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } Game_801380D8;
extern Game_801380D8 g_Game_801380D8 asm("g_Game");
void *memset(void *, s32, s32);
s32 rsin(s32);
s32 rcos(s32);
void *RotMatrixX(s32 r, void *m);
void *RotMatrixY(s32 r, void *m);
void *RotMatrixZ(s32 r, void *m);
void *RotMatrixZYX(void *r, void *m);
void Club_Draw(void *, s32, s32);
void Model_ProjectVerts(void *, void *, void *);
void Radar_DrawModel(void *, void *, void *, s32);

void func_801380D8(void) {
    MAT_801380D8 m;
    SVECTOR q;
    SVECTOR r;
    MAT_801380D8 m2;
    u32 *ot;
    s32 st;
    s32 a;

    st = D_80138CE8;
    ot = g_Game_801380D8.db[g_Game_801380D8.cur].ot;
    D_800E78C0_801380D8 = D_800AF0A0_801380D8;
    m = D_800AE840;
    m.t[0] = 0x40;
    m.t[1] = 0x10;
    m.t[2] = 0x148;
    RotMatrixZ(0x8C8, &m);
    RotMatrixY(g_Game_801380D8.frame << 4, &m);
    switch (st) {
    case 2:
        a = g_Game_801380D8.frame << 6;
        memset(&r, 0, 8);
        r.vx = rsin(a);
        r.vz = rcos(a);
        q = r;
        m.t[1] = 0x56;
        m.t[2] = 0x200;
        Radar_DrawModel(&m, &m, &q, g_Game_801380D8.frame << 7);
        return;
    case 7:
        m.t[2] = 0x200;
        Model_ProjectVerts(&D_800EC0D0, &m, D_800E7D00);
        func_80017CD4(ot, D_800E7D00, &D_800EC0D0);
        m.t[0] += 0x40;
        m.t[1] += 0x40;
        RotMatrixX(0x800, &m);
        Model_ProjectVerts(&D_800EC0D0 + 4, &m, D_800E7D00);
        func_80017CD4(ot, D_800E7D00, &D_800EC0D0 + 4);
        return;
    case 5:
        func_8004637C(&m2);
        m2.t[1] = -200;
        r.vx = 0x400;
        r.vy = 0;
        r.vz = 0;
        RotMatrixZYX(&r, &m2);
        CompMatrix(&m, &m2, &m2);
        Club_Draw(&m2, 0x555, 0);
        return;
    default:
        Model_ProjectVerts(&D_800EC060[st], &m, D_800E7D00);
        func_80017CD4(ot, D_800E7D00, &D_800EC060[st]);
        return;
    }
}

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
