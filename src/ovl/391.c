#include "common.h"
#include "m2c_macros.h"

M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_80139B6C;
extern struct S_g_Game { u8 pad_0[0x8126]; u16 f_8126; } g_Game;

M2C_UNK func_8008DDB0(s16, s16);
M2C_UNK func_8008DDC8(s32);
extern M2C_UNK D_80139B20;

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

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80136208);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801368FC);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801372D0);

void func_801373F8(s32 arg0) {
    func_8008DDB0(M2C_FIELD(&D_80139B20, s16 *, 0), M2C_FIELD(&D_80139B20, s16 *, 2));
    func_8008DDC8(arg0);
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137438);

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801374C8);

void SetDrawStp(void *, s32);

void func_80137CA8(void) {
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

void func_80137D20(s32 row)
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

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137DC4);

extern GameDraw g_Game_80137F4C asm("g_Game");
extern struct { u8 pad0[0x48]; s32 hidden; } D_80139B20_80137F4C asm("D_80139B20");
extern u8 D_800E7D00_80137F4C[] asm("D_800E7D00");
typedef struct { s16 frame, end; } Anim_80137F4C;
typedef struct { u8 pad0[0x14]; s16 *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u16 anim; s16 rx, ry, rz; u8 pad66[0xA]; s16 next; u16 flags; Anim_80137F4C *anims; s16 trx, try, trz, rsteps; s16 tx, ty, tz, steps; } Model_80137F4C;
void VectorNormalSS(void *v0, void *v1);
void func_80014804(s16 *, s16 *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4_80137F4C(void *, void *, void *) asm("func_80017CD4");

void func_80137F4C(Model_80137F4C *base) {
    Model_80137F4C *m;
    SVECTOR v;
    s32 i;
    s32 n;
    s32 bit;
    s32 dx, dy, dz;
    s32 x, y, z;
    s32 k, px, py, pz;

    for (i = 0; i < 5; i++) {
        m = &base[i];
        if (!(m->flags & 1)) {
            continue;
        }
        bit = 1 << i;
        if (D_80139B20_80137F4C.hidden & bit) {
            continue;
        }
        n = m->rsteps;
        if (n > 0) {
            dx = (m->trx - m->rx) / n;
            dy = (m->try - m->ry) / n;
            dz = (m->trz - m->rz) / n;
            m->rsteps = --n;
            m->rx += dx;
            m->ry += dy;
            m->rz += dz;
        }
        k = m->steps;
        if (k > 0) {
            px = (m->tx - (x = m->x)) / k;
            py = (m->ty - (y = m->y)) / k;
            z = m->z;
            pz = (m->tz - z) / k;
            m->steps = --k;
            m->x = x + px;
            m->y = y + py;
            m->z = z + pz;
        }
        VectorNormalSS(&m->rx, &v);
        func_80014804((s16 *)&v, m->mat);
        m->frame++;
        if (m->anims[m->anim].end < m->frame) {
            m->frame = m->anims[m->next].frame;
            m->anim = m->next;
        }
        func_80015780(m, 1);
        Model_ProjectBonedVerts(m);
        func_80017CD4_80137F4C(g_Game_80137F4C.db[g_Game_80137F4C.cur].ot, D_800E7D00_80137F4C, m);
    }
}

extern u8 *D_800EC354;
typedef struct { u32 tag; u32 rgbc; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt8_80138258;

void func_80138258(s32 x0, s32 y0, s32 w, s32 h) {
    Sprt8_80138258 *p;
    u32 *ot;
    s32 x, y;
    s32 u, v;

    p = (Sprt8_80138258 *)G_DRAW.prim;
    ot = G_DRAW.ot;
    for (y = 0; y < h; y += 8) {
        for (x = 0; x < w; x += 8) {
            p->rgbc = 0x606060;
            ((u8 *)p)[3] = 3;
            ((u8 *)p)[7] = 0x76;
            p->x0 = x0 + x;
            p->y0 = y0 + y;
            p->clut = 0x77AB;
            if (x == 0) {
                u = 0x80;
            } else if (x + 8 >= w) {
                u = 0x90;
            } else {
                u = 0x88;
            }
            p->u0 = u;
            if (y == 0) {
                v = 0xA0;
            } else if (y + 8 >= h) {
                v = 0xB0;
            } else {
                v = 0xA8;
            }
            p->v0 = v;
            ADD_PRIM_ASM2(ot, p);
            p++;
        }
    }
    ((u8 *)p)[3] = 1;
    p->rgbc = 0xE100025A;
    ADD_PRIM_ASM(ot, p);
    p = (Sprt8_80138258 *)((u8 *)p + 8);
    D_800EC354 = (u8 *)p;
}

extern struct { u8 pad0[4]; u8 *prim; u32 *ot; u8 pad0C[0x8114]; u16 f_8120; u8 pad8122[2]; u16 f_8124; } g_Game_8013836C asm("g_Game");
extern s32 D_80139AB0;
s32 func_80096580(s32);
void func_80138258(s32 x0, s32 y0, s32 w, s32 h);

void func_8013836C(void) {
    SprtTp *p;
    u32 *ot;
    s32 r;
    s32 mode;
    u16 uv;
    u16 clut;

    p = (SprtTp *)g_Game_8013836C.prim;
    ot = g_Game_8013836C.ot;
    if (D_80139AB0 == 0) {
        D_80139AB0 = 1;
    }
    mode = g_Game_8013836C.f_8120;
    r = func_80096580(g_Game_8013836C.f_8124);
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000238;
    p->code = 0x67;
    p->x0 = 0x1E;
    p->y0 = 0x1E;
    p->w = 0x100;
    p->h = 0x20;
    switch (mode) {
    case 12:
        if (r >= 2) {
            uv = 0x2000;
            clut = 0x3FA7;
        } else {
            uv = 0;
            clut = 0x3F67;
        }
        break;
    case 20:
        uv = 0x4000;
        clut = 0x3F27;
        break;
    }
    *(u16 *)&p->u0 = uv;
    p->clut = clut;
    ADD_PRIM_ASM2(ot, p);
    p++;
    D_800EC354 = (u8 *)p;
    func_80138258(0x18, 0x16, 0x110, 0x30);
}

extern struct { s16 x, y; u8 pad4[8]; s32 f_C; } D_80139B20_801384A0 asm("D_80139B20");
extern u8 D_80139AB4[];
extern struct { u8 pad0[0x8124]; u16 stage; u8 pad8126[0x1A]; s32 time; u32 best; } g_Game_801384A0 asm("g_Game");
s16 *Stage_GetTargetTimes(u32);
void func_801372D0();
void Hud_DrawTime(s32, s32, u32);
void Hud_DrawTimeMedal(s32, s32, u32, s16 *);

void func_801384A0(void) {
    s32 t = g_Game_801384A0.time;
    s16 *times = Stage_GetTargetTimes(g_Game_801384A0.stage);

    D_80139B20_801384A0.f_C = 0x10;
    D_80139B20_801384A0.x = 0x20;
    D_80139B20_801384A0.y = 0x50;
    func_801372D0(func_801361D8(D_80139AB4, 0));
    Hud_DrawTime(0x88, 0x50, t);
    D_80139B20_801384A0.x = 0x20;
    D_80139B20_801384A0.y = 0x68;
    func_801372D0(func_801361D8(D_80139AB4, 1));
    Hud_DrawTime(0x88, 0x68, g_Game_801384A0.best);
    if (t < g_Game_801384A0.best) {
        D_80139B20_801384A0.x = 0x40;
        D_80139B20_801384A0.y = 0xD0;
        func_801372D0(func_801361D8(D_80139AB4, 6));
    }
    if (times[0] >= t) {
        D_80139B20_801384A0.x = 0x20;
        D_80139B20_801384A0.y = 0x90;
        func_801372D0(func_801361D8(D_80139AB4, 2));
        D_80139B20_801384A0.x = 0x78;
        D_80139B20_801384A0.y = 0xB0;
        if (times[2] >= t) {
            func_801372D0(func_801361D8(D_80139AB4, 3));
        } else if (times[1] >= t) {
            func_801372D0(func_801361D8(D_80139AB4, 4));
        } else {
            func_801372D0(func_801361D8(D_80139AB4, 5));
        }
        Hud_DrawTimeMedal(0x68, 0xA8, t, times);
    }
}

void func_80138660(void) {
    s32 var_a0;

    if (g_Game.f_8126 == 0xFF) {
        var_a0 = 0x17;
        goto block_3;
    }
    var_a0 = D_80139B6C;
    if (var_a0 != 0) {
block_3:
        Cd_PlayXaTrack(var_a0);
    }
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801386B8);

extern s8 D_80139B00[];
extern s16 D_80139542;

void func_80138A9C(void) {
    s32 ok = 1;
    s32 i;

    for (i = 0; D_80139B00[i] > 0; i++) {
        if (func_80096580(D_80139B00[i]) < 2) {
            ok = 0;
            break;
        }
    }
    D_80139542 = ok;
}

typedef struct { s16 x, y; s32 z; } Pt_391;
void *func_8008C09C(s32);
s32 rcos(s32);
s32 rsin(s32);
extern Pt_391 *D_80139E28_80138B0C asm("D_80139E28");

void func_80138B0C(void)
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

typedef struct { u32 xy; u32 c; } Cell_80138C24;
extern Cell_80138C24 *D_80139E28_80138C24 asm("D_80139E28");
extern s32 g_Game_80138C24 asm("g_Game");

void func_80138C24(void) {
    Cell_80138C24 *p;
    Cell_80138C24 *r;
    Cell_80138C24 *l;
    s32 i;
    s32 j;
    s32 a0;
    s32 a1;
    s32 a2;

    p = D_80139E28_80138C24 + 11 * 16;
    for (i = 12; i >= 2; i--, p -= 32) {
        for (j = 0; j < 16; p++, j++) {
            r = p + 1;
            if (j == 15) {
                r = p - 15;
            }
            l = p - 1;
            if (j == 0) {
                l = p + 15;
            }
            ((u8 *)&p->c)[0] = (((u8 *)&r[-16].c)[0] + ((u8 *)&l[-16].c)[0] + ((u8 *)&p[-16].c)[0] * 2) >> 2;
            ((u8 *)&p->c)[1] = (((u8 *)&r[-16].c)[1] + ((u8 *)&l[-16].c)[1] + ((u8 *)&p[-16].c)[1] * 2) >> 2;
            ((u8 *)&p->c)[2] = (((u8 *)&r[-16].c)[2] + ((u8 *)&l[-16].c)[2] + ((u8 *)&p[-16].c)[2] * 2) >> 2;
        }
    }
    p = D_80139E28_80138C24;
    for (i = 15; i >= 0; i--) {
        p[i].c = 0;
    }
    a0 = g_Game_80138C24;
    if (a0 & 0xFF) {
        for (i = 0; i < 16; i++) {
            p[i].c += ((rsin((a0 << 5) + i * 0x100) + 0x1000) * 4) & 0xFF00;
        }
        for (i = 0, a1 = (g_Game_80138C24 << 5) + 0x555; i < 16; a1 += 0x100, i++) {
            p[i].c += ((rsin(a1) + 0x1000) >> 6) & 0xFF;
        }
        for (i = 0, a2 = (g_Game_80138C24 << 5) + 0xAAA; i < 16; a2 += 0x100, i++) {
            p[i].c += (((rsin(a2) + 0x1000) >> 6) & 0xFF) << 16;
        }
    }
}

typedef struct { u32 xy; u32 c; } GridPt_391;
typedef struct { u32 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4_391;
extern GridPt_391 *D_80139E28;
void func_80138C24(void);

void func_80138E20(void) {
    PolyG4_391 *p;
    u32 *ot;
    GridPt_391 *g;
    GridPt_391 *n;
    s32 i;
    s32 j;

    p = (PolyG4_391 *)G_DRAW.prim;
    ot = G_DRAW.ot + 0xFFF;
    g = D_80139E28;
    func_80138C24();
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

extern struct { u8 pad0[0x48]; s32 flags; s32 msg; s32 result; } D_80139B20_80138F38 asm("D_80139B20");
extern struct { u8 pad0[0x8120]; u16 mode; u8 pad8122[2]; u16 f_8124; u16 stage; u8 pad8128[4]; u16 f_812C; u8 pad812E[0x12]; u32 time; u32 best; } g_Game_80138F38 asm("g_Game");
s32 SaveByte_Get(s32);
s32 Stage_GetWorld(s32);

void func_80138F38(void) {
    s16 *times;
    s32 rb, rt;

    D_80139B20_80138F38.flags = 0;
    D_80139B20_80138F38.msg = 0;
    D_80139B20_80138F38.result = 0;
    if (g_Game_80138F38.mode == 12 || g_Game_80138F38.mode == 20) {
        if (func_80096580(0x11) > 0 && SaveByte_Get(4) != 5) {
            D_80139B20_80138F38.flags |= 1;
        }
        if (func_80096580(0x11) > 0 && SaveByte_Get(5) != 5) {
            D_80139B20_80138F38.flags |= 2;
        }
    }
    switch (g_Game_80138F38.mode) {
    case 12:
        if (!(D_80139B20_80138F38.flags & 2)) {
            if (func_80096580(g_Game_80138F38.f_8124) >= 2) {
                D_80139B20_80138F38.msg = 0x20;
            } else {
                D_80139B20_80138F38.msg = 0x1F;
            }
        }
        break;
    case 20:
        times = Stage_GetTargetTimes(Stage_GetWorld(g_Game_80138F38.stage));
        rb = 0;
        rt = rb;
        if ((u32)times[0] < g_Game_80138F38.time) {
            D_80139B20_80138F38.result = 4;
            if (!(D_80139B20_80138F38.flags & 2)) {
                D_80139B20_80138F38.msg = 0x25;
            }
            break;
        }
        if (!((u32)times[0] < g_Game_80138F38.best)) {
            if ((u32)times[1] < g_Game_80138F38.best) {
                rb = 1;
            } else if ((u32)times[2] >= g_Game_80138F38.best) {
                rb = 3;
            } else {
                rb = 2;
            }
        }
        if (!((u32)times[0] < g_Game_80138F38.time)) {
            if ((u32)times[1] < g_Game_80138F38.time) {
                rt = 1;
            } else if ((u32)times[2] >= g_Game_80138F38.time) {
                rt = 3;
            } else {
                rt = 2;
            }
        }
        if (rb >= rt) {
            if (g_Game_80138F38.time < g_Game_80138F38.best) {
                if (!(D_80139B20_80138F38.flags & 2)) {
                    D_80139B20_80138F38.msg = 0x24;
                }
                D_80139B20_80138F38.result = 3;
            } else {
                D_80139B20_80138F38.msg = 0;
                D_80139B20_80138F38.result = 8;
            }
            break;
        }
        switch (rt) {
        case 1:
            D_80139B20_80138F38.msg = 0x21;
            D_80139B20_80138F38.result = 5;
            break;
        case 2:
            D_80139B20_80138F38.msg = 0x22;
            D_80139B20_80138F38.result = 6;
            break;
        case 3:
            D_80139B20_80138F38.msg = 0x23;
            D_80139B20_80138F38.result = 7;
            break;
        }
        if (D_80139B20_80138F38.flags & 2) {
            D_80139B20_80138F38.msg = 0;
        }
        break;
    case 25:
        if (g_Game_80138F38.f_812C == 8) {
            D_80139B6C = 0x2A;
        } else {
            D_80139B6C = 0x29;
        }
        break;
    }
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_801392B0;
typedef struct { u8 pad_0[4]; s16 x, y, z; u8 pad_A[0xB]; u8 rot; } Obj_801392B0;
typedef struct { u8 *f0; u8 pad[0xC]; } Mdl_801392B0;
extern Mdl_801392B0 D_800F4C30[];
extern u8 D_800E7D00_801392B0[] asm("D_800E7D00");
extern void *D_800EC358;
void Matrix_RotateY(s32, Mat_801392B0 *);
void Model_ProjectVerts(Mdl_801392B0 *, Mat_801392B0 *, void *);
void Model_CalcEnvMapUVs64(Mdl_801392B0 *);
void func_8001CE54(void *, void *, Mdl_801392B0 *);

void func_801392B0(s32 id, Obj_801392B0 *o) {
    Mat_801392B0 m;
    Mdl_801392B0 *mdl;
    void *buf;

    func_8004637C(&m);
    m.t[0] = o->x;
    m.t[1] = o->y;
    m.t[2] = o->z;
    Matrix_RotateY(o->rot << 6, &m);
    CompMatrix(&D_800E78C0, &m, &m);
    mdl = &D_800F4C30[id];
    buf = *(u16 *)(mdl->f0 + 0xA) != 0 ? (void *)0x1F800080 : D_800E7D00_801392B0;
    Model_ProjectVerts(mdl, &m, buf);
    Model_CalcEnvMapUVs64(mdl);
    *(u8 *)0x1F8003F4 = 2;
    func_8001CE54(D_800EC358, buf, mdl);
}

extern struct { u8 f_0; u8 pad_1[0x8125]; u16 f_8126; } g_Game_8013939C asm("g_Game");
typedef struct { u8 pad_0[4]; s16 x, y, z; u8 pad_A[0xB]; u8 rot; u8 pad_16[2]; } Obj_8013939C;
s32 func_800964B0(s32);

void func_8013939C(void) {
    Obj_8013939C o;
    s32 i;
    u16 mode = g_Game_8013939C.f_8126;

    switch (mode) {
    case 0x13:
        if ((func_800964B0(0x13) & 0x18) != 0x18) {
            return;
        }
        break;
    case 0x24:
        if ((func_800964B0(0x24) & 0x18) != 0x18) {
            return;
        }
        break;
    }
    for (i = 0; i < 5; i++) {
        o.x = i * 0x100 - 0x200;
        o.y = 0;
        o.z = 0x500;
        o.rot = g_Game_8013939C.f_0 + i * 8;
        func_801392B0(0xD, &o);
    }
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
