#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_393;
void Gfx_InitDisplay(void);
void ResetGraph(s32);
void ClearImage(Rect_393 *, s32, s32, s32);
void DrawSync(s32);
typedef struct { u8 pad0[0x12C]; s16 world[24]; } StageSet_393;
extern StageSet_393 D_80138A20[];

s32 func_80136000(void) {
    Rect_393 r = { 0, 0, 0x180, 0x200 };

    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013606C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801375C0);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137714);

extern u8 g_Game[];
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013786C;
extern Mat_8013786C D_800E78C0_8013786C asm("D_800E78C0");
extern u8 D_800E7D00_8013786C[] asm("D_800E7D00");
void func_8004637C(Mat_8013786C *);
void RotMatrix(void *, Mat_8013786C *);
void CompMatrix(Mat_8013786C *, Mat_8013786C *, Mat_8013786C *);
void Model_ProjectVerts(void *, Mat_8013786C *, void *);
void Model_CalcEnvMapUVs64(void *);
void func_8001CE54(void *, void *, void *);

void func_8013786C(s16 *pos, void *rot, void *mdl) {
    Mat_8013786C m;
    u8 *sc = (u8 *)0x1F800000;

    sc[0x3F4] = 1;
    *(s16 *)(sc + 0x3C6) = 0;
    *(s16 *)(sc + 0x3C4) = 0;
    func_8004637C(&m);
    m.t[2] = pos[2];
    m.t[0] = pos[0];
    m.t[1] = pos[1];
    RotMatrix(rot, &m);
    CompMatrix(&D_800E78C0_8013786C, &m, &m);
    Model_ProjectVerts(mdl, &m, D_800E7D00_8013786C);
    Model_CalcEnvMapUVs64(mdl);
    func_8001CE54(g_Game + 0x80 + G_DRAW.cur * 0x4078, D_800E7D00_8013786C, mdl);
}

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137950);

extern u8 D_80139914[];
s32 Stage_GetWorld(s32);
s32 func_80096580_801382D8(s32) asm("func_80096580");
extern s8 D_801399A8[][4];
extern s8 D_801399D4[];

s32 func_801382D8(s32 world, s32 stage) {
    s32 i;
    s32 r;

    if (Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]) == 1) {
        return 1;
    }
    if (world < 9) {
        return func_80096580_801382D8(D_801399A8[world][stage]) > 0;
    }
    r = 1;
    for (i = 0; D_801399D4[i] > 0; i++) {
        if (func_80096580_801382D8(D_801399D4[i]) < 2) {
            r = 0;
            break;
        }
    }
    return r;
}

extern u8 D_80139914[];
s32 Stage_GetWorld(s32);
void func_80096580(s32);

void func_801383EC(s32 world, s32 stage) {
    func_80096580(Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]));
}

typedef struct { u8 pad0[0xE]; u16 f_E; } Info_80138468;

s32 func_80138468(s32 world, s32 stage) {
    s32 w;

    w = Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]);
    Stage_GetInfo(w, (void *)0x1F800000);
    switch (w) {
    case 14:
        return func_800964B0(0x24) & 0x10;
    case 7:
        return func_800964B0(0x13) & 0x10;
    case 30:
        return 0;
    default:
        return func_80097FB0(w) == (s16)((volatile Info_80138468 *)0x1F800000)->f_E;
    }
}

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

extern u16 D_800AE8F2;
extern u8 *D_800EC354;
extern u8 D_80139BF0[];
typedef struct { s16 x, y; u16 clut; u16 tpage; u32 *ot; } Pen_80138700;
extern Pen_80138700 D_80139CF0;

void func_80138700(u8 *s) {
    SprtTp *p;
    u32 c;
    u32 r;

    p = (SprtTp *)D_800EC354;
    while ((c = *s) != 0) {
        ((u8 *)p)[3] = 5;
        p->tpage = (D_80139CF0.tpage & 0x9FF) | 0xE1000200;
        p->code = 0x67;
        r = ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) & 1;
        p->x0 = D_80139CF0.x;
        p->y0 = D_80139CF0.y - r;
        p->u0 = (c & 0xF) << 4;
        p->v0 = c & 0xF0;
        p->clut = D_80139CF0.clut;
        p->w = 0x10;
        p->h = 0x10;
        { register u32 *ot asm("$3") = D_80139CF0.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p++;
        D_80139CF0.x += D_80139BF0[c];
        s++;
    }
    D_800EC354 = (u8 *)p;
}

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

extern u8 D_80139BF0[];

s32 func_8013882C(u8 *s) {
    s32 w;

    w = 0;
    for (; *s != 0; s++) {
        w += D_80139BF0[*s];
    }
    return w;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; } Tile1_8013886C;

void func_8013886C(void) {
    s32 seed = 0;
    s32 i;
    s32 x;
    Tile1_8013886C *p;
    u32 *ot;

    p = (Tile1_8013886C *)G_DRAW.prim;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    for (i = 0; i < 300; i++) {
        x = seed = (seed * 87 + 1) & 0x1FF;
        seed = (seed * 87 + 1) & 0x1FF;
        *(u32 *)&p->r0 = 0xFFFFFF;
        ((u8 *)p)[3] = 2;
        p->code = 0x68;
        p->x0 = x;
        p->y0 = seed;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    G_DRAW.prim = (u8 *)p;
}

typedef struct { s16 x, y; } Pt_8013893C;
s32 VectorNormalSS(SVECTOR *, SVECTOR *);
s32 rsin(s32);
s32 rcos(s32);

s32 func_8013893C(s32 x, s32 y) {
    SVECTOR d;
    Pt_8013893C p;
    s32 r;

    d.vx = 0xC0 - x;
    d.vy = 0x78 - y;
    d.vz = 0;
    r = SquareRoot0(VectorNormalSS(&d, &d)) << 5;
    p.x = x + (rsin(r) >> 16);
    p.y = y + (rcos(r) >> 16);
    return *(s32 *)&p;
}
