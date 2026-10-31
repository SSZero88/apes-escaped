#include "common.h"
#include "m2c_macros.h"

void func_80139628(u8 *);
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

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_80136208;
extern GameDraw g_Game_80136208 asm("g_Game");

s32 func_80136208(void) {
    register u8 *p asm("$14");
    u8 *base;
    u32 *ot;

    p = g_Game_80136208.prim;
    *(u32 *)&((Sprt_80136208 *)p)->r0 = 0x808080;
    p[3] = 4;
    ((Sprt_80136208 *)p)->code = 0x64;
    ((Sprt_80136208 *)p)->x0 = 0;
    ((Sprt_80136208 *)p)->y0 = 0;
    ((Sprt_80136208 *)p)->u0 = 0;
    ((Sprt_80136208 *)p)->v0 = 0;
    ((Sprt_80136208 *)p)->w = 0xFF;
    ((Sprt_80136208 *)p)->h = 0xF0;
    ((Sprt_80136208 *)p)->clut = 0x3C5C;
    base = (u8 *)&g_Game_80136208 + 0x80;
    ot = &((u32 *)(base + g_Game_80136208.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x14;
    p[3] = 1;
    ((u32 *)p)[1] = 0xE1000307;
    ot = &((u32 *)(base + g_Game_80136208.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 8;
    *(u32 *)&((Sprt_80136208 *)p)->r0 = 0x808080;
    p[3] = 4;
    ((Sprt_80136208 *)p)->code = 0x64;
    ((Sprt_80136208 *)p)->x0 = 0xFF;
    ((Sprt_80136208 *)p)->y0 = 0;
    ((Sprt_80136208 *)p)->u0 = 0;
    ((Sprt_80136208 *)p)->v0 = 0;
    ((Sprt_80136208 *)p)->w = 0x80;
    ((Sprt_80136208 *)p)->h = 0xF0;
    ((Sprt_80136208 *)p)->clut = 0x3C5C;
    ot = &((u32 *)(base + g_Game_80136208.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x14;
    p[3] = 1;
    ((u32 *)p)[1] = 0xE100030B;
    ot = &((u32 *)(base + g_Game_80136208.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 8;
    g_Game_80136208.prim = p;
    return 0;
}

typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad2; s16 x3, y3; u8 u3, v3; u16 pad3; } Ft4_80136394;
extern struct { u32 frame; } g_Game_80136394 asm("g_Game");
#define GD_80136394 (*(GameDraw *)&g_Game_80136394)
extern u8 *D_800EC354;

s32 func_80136394(s32 x, s32 y, s16 n, s16 lit) {
    Ft4_80136394 *p;
    u32 *ot;
    s32 i;
    s32 y0;

    p = (Ft4_80136394 *)GD_80136394.prim;
    i = 0;
    y0 = y;
    if (n > 0) {
    y += 0x18;
    do {
        s32 xx = x + i * 16;
        *(u32 *)&p->r0 = 0x808080;
        p->len = 9;
        p->code = 0x2C;
        p->x0 = xx;
        p->y0 = y0;
        p->x1 = xx + 0x18;
        p->y1 = y0;
        p->x2 = xx;
        p->y2 = y;
        p->x3 = xx + 0x18;
        p->y3 = y;
        if ((g_Game_80136394.frame & 0xF) >= 9) {
            p->u0 = (i < lit) ? 0x80 : 0xA0;
            p->v0 = 0x20;
            p->u1 = (i < lit) ? 0xA0 : 0xC0;
            p->v1 = 0x20;
            p->u2 = (i < lit) ? 0x80 : 0xA0;
            p->v2 = 0x40;
            p->u3 = (i < lit) ? 0xA0 : 0xC0;
            p->v3 = 0x40;
        } else {
            p->u0 = (i < lit) ? 0x80 : 0xA0;
            p->v0 = 0;
            p->u1 = (i < lit) ? 0xA0 : 0xC0;
            p->v1 = 0;
            p->u2 = (i < lit) ? 0x80 : 0xA0;
            p->v2 = 0x20;
            p->u3 = (i < lit) ? 0xA0 : 0xC0;
            p->v3 = 0x20;
        }
        p->clut = 0x18B4;
        p->tpage = 0xD;
        ot = &GD_80136394.db[GD_80136394.cur].ot[0];
        ADD_PRIM_R(ot, p, "$4", "$3");
        p++;
    } while (++i < n);
    }
    D_800EC354 = (u8 *)p;
    return 0;
}

/* near-miss: only 'sra t7,a0,16' (the s16 dir copy for the final switch) is scheduled one slot later than in the original */
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x, y, w, h; } Tile_80136588;
extern s16 D_8013AECC;
#define ADDPRIM_80136588(ot, p) __asm__ volatile("lwl $4, 2(%0)\n\tsll $3, %2, 8\n\tswl $3, 2(%0)\n\tswl $4, %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$4", "$3", "memory")
extern struct { s32 frame; Tile_80136588 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80136588 asm("g_Game");

s32 func_80136588(s16 dir) {
    Tile_80136588 *p;
    u32 *ot;
    s32 ofs;
    s32 k;
    s32 y1;
    s32 d;

    ofs = dir < 0 ? 0x100 : 0;
    y1 = ofs + 0x6A;
    p = g_Game_80136588.prim;
    p->r0 = p->g0 = p->b0 = 0;
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    p->x = 0;
    p->y = D_8013AECC + y1;
    p->w = 0x180;
    d = dir;
    __asm__("" : : "r"(d));
    p->h = 0x88 - D_8013AECC;
    ot = g_Game_80136588.db[g_Game_80136588.cur].ot;
    ADDPRIM_80136588(ot, p);
    p++;
    p->r0 = p->g0 = p->b0 = 0;
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    p->x = 0;
    p->y = ofs;
    p->w = 0x180;
    p->h = 0x6A - D_8013AECC;
    ot = g_Game_80136588.db[g_Game_80136588.cur].ot;
    ADDPRIM_80136588(ot, p);
    p++;
    p->r0 = p->g0 = p->b0 = 0;
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    p->x = 0;
    p->y = ofs;
    p->w = 0xC0 - D_8013AECC * 384 / 152;
    p->h = 0xF0;
    ot = g_Game_80136588.db[g_Game_80136588.cur].ot;
    ADDPRIM_80136588(ot, p);
    p++;
    p->r0 = p->g0 = p->b0 = 0;
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    k = D_8013AECC * 384 / 152;
    p->x = k + 0xC0;
    p->y = ofs;
    p->w = 0xC0 - k;
    p->h = 0xF0;
    ot = g_Game_80136588.db[g_Game_80136588.cur].ot;
    ADDPRIM_80136588(ot, p);
    p++;
    g_Game_80136588.prim = p;
    switch (d) {
    case 0:
        D_8013AECC = 0;
        break;
    case 1:
        D_8013AECC += 2;
        if (D_8013AECC >= 0x4D) {
            D_8013AECC = 0x4C;
            return 1;
        }
        break;
    case -1:
        D_8013AECC -= 2;
        if (D_8013AECC < 0) {
            D_8013AECC = 0;
            return -1;
        }
        break;
    }
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_8013683C;
extern Rect_8013683C D_8013ADB0;
extern s32 D_8013AE60;
extern s32 D_8013B9E0;
extern s8 D_8013B450[];
extern u8 D_8013AED0[];
extern u8 D_800F4458[];
extern struct { u8 pad0[0x8120]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x1C]; u32 best; u8 pad8148[0x12]; u16 f_815A; } g_Game_8013683C asm("g_Game");
s32 func_80136A1C(void);
s32 SaveByte_Get(s32);
s32 Stage_GetWorld(s32);
s32 Stage_GetInfo(u32, void *);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);

s32 func_8013683C(void) {
    Rect_8013683C r;
    s32 w;
    s32 c;
    u8 *s;
    u8 *d;

    r = D_8013ADB0;
    D_8013AE60 = 0;
    if (g_Game_8013683C.mode == 8) {
        func_80136A1C();
        g_Game_8013683C.mode = 10;
        D_8013AE60 = 0;
        D_8013B9E0 = 0;
    }
    if (g_Game_8013683C.stage == 6 && SaveByte_Get(0xB) != 5) {
        ClearImage(&r, 0, 0, 0);
        DrawSync(0);
        g_Game_8013683C.mode = 0x1A;
        g_Game_8013683C.f_815A = 7;
        return 0;
    }
    func_801375B4();
    if (g_Game_8013683C.mode == 0x12) {
        g_Game_8013683C.mode = 0x13;
    } else if (g_Game_8013683C.mode == 0x17) {
        g_Game_8013683C.mode = 0x18;
    } else {
        g_Game_8013683C.mode = 0xB;
    }
    w = Stage_GetWorld(g_Game_8013683C.stage);
    c = D_8013B450[w];
    if (c != -1) {
        s = func_801361D8(D_8013AED0, c);
        d = D_800F4458;
        while (*s) {
            *d++ = *s++;
        }
        *d = 0;
    }
    Stage_GetInfo(w, (void *)0x1F800000);
    g_Game_8013683C.best = *(u32 *)0x1F800000;
    DrawSync(0);
    VSync(0);
    return 0;
}

INCLUDE_RODATA("asm/ovl/392/nonmatchings/392", D_8013ADB0);

extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x26]; u16 stage; } g_Game_80136A1C asm("g_Game");
extern struct { u8 pad0[4]; s16 f4; s16 f6; u8 pad8[4]; s32 fC; u8 pad10[0x10]; u8 *f20; u8 pad24[4]; s16 sub; s16 pad2A; s16 buf; u8 pad2E[0x1A]; s32 f48; } D_8013B998_6A1C asm("D_8013B998");
extern struct { u8 pad0[0x24]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_6A1C asm("D_800EBFA0");
extern struct { u8 pad0[8]; u16 f8; u8 padA[6]; u16 f10; } D_8013AE84_6A1C asm("D_8013AE84");
extern u8 *D_8013B9B8_6A1C asm("D_8013B9B8");
extern u8 D_8013B228[];
extern u8 D_8013B290[];
extern u8 D_8013B2D0[];
extern u8 D_8013B310[];
extern u8 D_8013B350[];
extern u8 D_8013B390[];
extern u8 D_8013B408[];
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
void func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
void func_8008C01C(void);
s32 func_80010CA4(s32);
void func_80011194(void *);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void func_8008C390(void);
s32 func_80137198(void);
void func_80139710(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
void Cd_Update(void);
void func_800964DC(s32);

s32 func_80136A1C(void) {
    Rect_8013683C r;
    u16 add;
    s32 s;

    r = D_8013ADB0;
    Gfx_InitDisplay();
    add = 0;
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    func_8002FAF0(0x148);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_6A1C.f24 = 0;
    D_800EBFA0_6A1C.f28 = 0x1000;
    D_800EBFA0_6A1C.f2C = 0x1000;
    DrawSync(0);
    func_8008C01C();
    D_8013B998_6A1C.f20 = D_8013B228;
    D_8013B998_6A1C.f48 = 0;
    switch (func_80010CA4(g_Game_80136A1C.stage)) {
    case 2:
        add = 2;
        D_8013B9B8_6A1C = D_8013B290;
        break;
    case 4:
        add = 4;
        D_8013B9B8_6A1C = D_8013B2D0;
        break;
    case 5:
        add = 6;
        D_8013B9B8_6A1C = D_8013B310;
        break;
    case 7:
        add = 8;
        D_8013B9B8_6A1C = D_8013B350;
        break;
    case 10:
        add = 10;
        D_8013B9B8_6A1C = D_8013B390;
        break;
    case 11:
        add = 12;
        D_8013B998_6A1C.f20 = D_8013B408;
        D_8013B998_6A1C.f48 = 1;
        break;
    }
    D_8013AE84_6A1C.f8 += add;
    D_8013AE84_6A1C.f10 += add;
    func_80011194(&D_8013AE84_6A1C);
    D_8013B998_6A1C.f4 = 0x3FDF;
    D_8013B998_6A1C.f6 = 6;
    D_8013B998_6A1C.fC = 0x10;
    g_Game_80136A1C.db[1].env[0x18] = 1;
    g_Game_80136A1C.db[0].env[0x18] = 1;
    g_Game_80136A1C.db[1].env[0x19] = 0;
    g_Game_80136A1C.db[0].env[0x19] = 0;
    g_Game_80136A1C.db[1].env[0x1A] = 0;
    g_Game_80136A1C.db[0].env[0x1A] = 0;
    g_Game_80136A1C.db[1].env[0x1B] = 8;
    g_Game_80136A1C.db[0].env[0x1B] = 8;
    while (func_8001325C(0), Gfx_BeginFrame(), func_8008C390(), func_80137198() >= 0) {
        DrawSync(0);
        VSync(2);
        g_Game_80136A1C.frame++;
        if (D_8013AE60 == 1 || D_8013AE60 == 3) {
            s = D_8013B998_6A1C.sub;
            if (s == 0) {
                func_80139710();
                PutDispEnv(&g_Game_80136A1C.db[g_Game_80136A1C.cur].env[0x5C]);
                PutDrawEnv(g_Game_80136A1C.db[g_Game_80136A1C.cur].env);
                D_8013B998_6A1C.sub = 1;
                D_8013B998_6A1C.buf = g_Game_80136A1C.cur;
            } else if (s == 1) {
                g_Game_80136A1C.db[1].env[0x18] = 0;
                g_Game_80136A1C.db[0].env[0x18] = 0;
                PutDispEnv(&g_Game_80136A1C.db[D_8013B998_6A1C.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136A1C.db[(s16)(D_8013B998_6A1C.buf ^ 1)].env);
            } else if (s == 2) {
                PutDispEnv(&g_Game_80136A1C.db[D_8013B998_6A1C.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136A1C.db[(s16)(D_8013B998_6A1C.buf ^ 1)].env);
                g_Game_80136A1C.db[1].env[0x18] = 1;
                g_Game_80136A1C.db[0].env[0x18] = 1;
                D_8013AE60 = s;
            }
        } else {
            PutDispEnv(&g_Game_80136A1C.db[g_Game_80136A1C.cur].env[0x5C]);
            PutDrawEnv(g_Game_80136A1C.db[g_Game_80136A1C.cur].env);
        }
        DrawOTag(&g_Game_80136A1C.db[g_Game_80136A1C.cur].ot[0xFFF]);
        Cd_Update();
    }
    func_800964DC(g_Game_80136A1C.stage);
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_80136EAC;
extern GameDraw g_Game_80136EAC asm("g_Game");
extern s32 D_8013B9F4;
extern u8 *D_800EC354;

void func_80136EAC(void) {
    Rect_80136EAC r;
    u8 *p;
    u32 *ot;
    s32 t;
    s32 k;

    p = g_Game_80136EAC.prim;
    t = D_8013B9F4;
    ot = &g_Game_80136EAC.db[g_Game_80136EAC.cur].ot[0xFFF];
    if (t == 4) {
        r.w = 0x10;
        r.h = 0x30;
        r.x = 0x1E0;
        r.y = 0x40;
        SetDrawMove(p, &r, 0x1C0, 0xD0);
        ADD_PRIM_ASM(ot, p);
        p += 0x18;
        r.w = 0x10;
        r.h = 0x10;
        r.x = 0x1E0;
        r.y = 0x70;
        SetDrawMove(p, &r, 0x1E0, 0xC0);
        ADD_PRIM_ASM(ot, p);
        p += 0x18;
        g_Game_80136EAC.prim = p;
        return;
    }
    k = 0;
    if ((u32)(t - 6) < 0x72A) {
        switch (t % 15) {
        case 0:
            k = 1;
            break;
        case 7:
            k = 2;
            break;
        }
        if (k != 0) {
            r.w = 0x10;
            r.h = 0x10;
            r.y = 0xC0;
            switch (k) {
            case 1:
                r.x = 0x1D0;
                break;
            case 2:
                r.x = 0x1E0;
                break;
            }
            SetDrawMove(p, &r, 0x1E0, 0x70);
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
        k = 0;
        switch (t % 60) {
        case 7:
        case 13:
            k = 1;
            break;
        case 10:
            k = 2;
            break;
        case 16:
            k = 3;
            break;
        }
        if (k != 0) {
            r.w = 0x10;
            r.h = 0x30;
            r.y = 0xD0;
            switch (k) {
            case 1:
                r.x = 0x1D0;
                break;
            case 2:
                r.x = 0x1E0;
                break;
            case 3:
                r.x = 0x1C0;
                break;
            }
            SetDrawMove(p, &r, 0x1E0, 0x40);
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    D_800EC354 = p;
}

extern struct { u8 pad0[0x10]; SVECTOR eye; SVECTOR at; u8 pad20[8]; s16 sub; s16 timer; u8 pad2C[0x1C]; s32 f_48; } D_8013B998_80137198 asm("D_8013B998");
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x26]; u16 stage; } g_Game_80137198 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 mask; } g_Pad_80137198 asm("g_Pad");
extern s16 D_8013B478;
extern s16 D_8013B47A;
extern s16 *D_8013B9B8;
extern u8 D_8013B6F0[];
s32 func_800116C0(void);
void Sound_ResumeStreams(void);
s32 func_80010CA4(s32);
void func_801380DC(void);
void func_80138118(void);
void func_80136000(SVECTOR *eye, SVECTOR *at);
void func_80016F34(void);
s32 Sound_PlayFixed(s32);
void Sound_UnloadBanks(s32);
void func_80136EAC(void);
void func_8013A3C4(void);

s32 func_80137198(void) {
    s32 a, b;
    u8 *p;

    switch (D_8013AE60) {
    case 0:
        if (D_8013B478 != 0 && func_800116C0() < 0) {
            Sound_ResumeStreams();
            D_8013B478 = 0;
        }
        D_8013B47A += 2;
        if (D_8013B47A < 0x79) {
            return 0;
        }
        if (D_8013B478 != 0) {
            return 0;
        }
        D_8013B47A = 0;
        func_80138138(func_80010CA4(g_Game_80137198.stage) == 10 ? 2 : 1);
        if (D_8013B998_80137198.f_48 != 0) {
            func_801380DC();
        }
        func_80138118();
        func_801385B0();
        func_80136000(&D_8013B998_80137198.eye, &D_8013B998_80137198.at);
        func_80016F34();
        func_801399A4(D_8013B6F0);
        D_8013AE60 = 1;
        D_8013B998_80137198.sub = 0;
        D_8013B998_80137198.timer = 0;
        Sound_PlayFixed(0xAC);
        return 0;
    case 1:
        b = D_8013B998_80137198.timer;
        if (b < 6) {
            a = b * 192 / 5;
            b = 2;
            if (a > 0xC0) {
                a = 0xC0;
            }
        } else {
            b = (b - 5) * 30;
            a = 0xC0;
            if (b > 0x80) {
                b = 0x80;
            }
        }
        func_80139FB8(a, b);
        if (++D_8013B998_80137198.timer < 11) {
            return 0;
        }
        D_8013B998_80137198.sub = 2;
        return 0;
    case 2:
        if ((g_Pad_80137198.held & g_Pad_80137198.mask & 0x860) || *D_8013B9B8 == 0x3FC0) {
            Sound_PlayFixed(0xAD);
            D_8013B478 = 1;
            D_8013AE60 = 3;
            D_8013B998_80137198.sub = 0;
            D_8013B998_80137198.timer = 10;
        }
        break;
    case 3:
        if (D_8013B998_80137198.sub < 2) {
            b = D_8013B998_80137198.timer;
            if (b < 6) {
                a = b * 192 / 5;
                b = 2;
                if (a > 0xC0) {
                    a = 0xC0;
                }
            } else {
                b = (b - 5) * 30;
                a = 0xC0;
                if (b > 0x80) {
                    b = 0x80;
                }
            }
            func_8013A10C(a, b);
        }
        if (--D_8013B998_80137198.timer < 0) {
            Sound_UnloadBanks(1);
            return -1;
        }
        return 0;
    }
    func_801385B0();
    func_80136000(&D_8013B998_80137198.eye, &D_8013B998_80137198.at);
    func_80016F34();
    func_801399A4(D_8013B6F0);
    if (func_80010CA4(g_Game_80137198.stage) == 10) {
        func_80136EAC();
    }
    p = g_Game_80137198.prim;
    p[3] = 3;
    *(u32 *)(p + 4) = 0;
    p[7] = 0x60;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xC) = 0xF00180;
    ADD_PRIM_R(&g_Game_80137198.db[g_Game_80137198.cur].ot[0xFFF], p, "$5", "$3");
    g_Game_80137198.prim = p + 0x10;
    func_8013A3C4();
    return 0;
}

extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x20]; s32 f_8148; s32 f_814C; } g_Game_801375B4 asm("g_Game");
extern struct { u8 pad0[4]; s16 f4; s16 f6; u32 *f8; s32 fC; SVECTOR eye; SVECTOR at; u8 pad20[8]; s16 sub; s16 pad2A; s16 buf; u8 pad2E[0x2A]; s32 f58; } D_8013B998_801375B4 asm("D_8013B998");
extern struct { u8 pad0[0x24]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_801375B4 asm("D_800EBFA0");
extern struct { s16 f0; u8 pad2[0xE]; s16 f10; } D_8013AE64_801375B4 asm("D_8013AE64");
extern u16 g_RandSeed;
extern u16 D_800AE8F2;
extern u8 D_8013B008[];
extern u8 D_8013B0A8[];
extern u8 D_8013B148[];
s32 func_80096580(s32);
s32 Stage_GetTargetTimes(u32);
void Spike_SetBlinkFrame(s32);
s32 func_80137C88(void);

s32 func_801375B4(void) {
    Rect_8013683C r;
    s16 *t;
    s32 w;
    s32 best;
    s32 s;

    r = D_8013ADB0;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    func_8002FAF0(0x148);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_801375B4.f24 = 0;
    D_800EBFA0_801375B4.f28 = 0x1000;
    D_800EBFA0_801375B4.f2C = 0x1000;
    DrawSync(0);
    func_8008C01C();
    func_8013A7A8();
    switch (g_Game_801375B4.stage) {
    case 0x13:
    case 0x24:
        D_8013AE64_801375B4.f0 = 0x1B;
        D_8013AE64_801375B4.f10 = 0x26;
        D_8013B9B8 = (s16 *)D_8013B148;
        break;
    case 0x2D:
    case 0x3F:
    case 0x45:
    case 0x57:
        if (g_Game_801375B4.mode == 0x12 || func_80096580(Stage_GetWorld(g_Game_801375B4.stage)) > 0) {
            D_8013B9B8 = (s16 *)D_8013B008;
        } else {
            D_8013AE64_801375B4.f10 = 0x27;
            D_8013B9B8 = (s16 *)D_8013B0A8;
        }
        break;
    default:
        D_8013B9B8 = (s16 *)D_8013B008;
        break;
    }
    func_80011194(&D_8013AE64_801375B4);
    g_Game_801375B4.cur = 0;
    D_8013B998_801375B4.f4 = 0x1B;
    D_8013B998_801375B4.f6 = 0x26;
    D_8013B998_801375B4.fC = 0x10;
    D_8013B998_801375B4.f58 = 0;
    g_Game_801375B4.db[1].env[0x18] = 1;
    g_Game_801375B4.db[0].env[0x18] = 1;
    g_Game_801375B4.db[1].env[0x19] = 0;
    g_Game_801375B4.db[0].env[0x19] = 0;
    g_Game_801375B4.db[1].env[0x1A] = 0;
    g_Game_801375B4.db[0].env[0x1A] = 0;
    g_Game_801375B4.db[1].env[0x1B] = 8;
    g_Game_801375B4.db[0].env[0x1B] = 8;
    g_Game_801375B4.f_814C = -1;
    if (g_Game_801375B4.mode == 0x12) {
        w = Stage_GetWorld(g_Game_801375B4.stage);
        t = (s16 *)Stage_GetTargetTimes(w);
        Stage_GetInfo(w, (void *)0x1F800000);
        g_Game_801375B4.f_8148 = t[0];
        best = *(s32 *)0x1F800000;
        if (best != -1) {
            if (t[2] >= best) {
                g_Game_801375B4.f_8148 = -1;
                g_Game_801375B4.f_814C = t[3];
            } else if (t[1] >= best) {
                g_Game_801375B4.f_8148 = t[2];
            } else if (t[0] >= best) {
                g_Game_801375B4.f_8148 = t[1];
            }
        }
    } else {
        g_Game_801375B4.f_8148 = -1;
    }
    for (;;) {
        func_8001325C(0);
        g_RandSeed = g_RandSeed * 5 + 1;
        D_800AE8F2 = D_800AE8F2 * 5 + 1;
        Gfx_BeginFrame();
        D_8013B998_801375B4.f8 = g_Game_801375B4.db[g_Game_801375B4.cur].hud;
        g_Game_801375B4.frame++;
        func_8008C390();
        Spike_SetBlinkFrame(0);
        if (func_80137C88() < 0) {
            break;
        }
        DrawSync(0);
        VSync(2);
        switch (D_8013AE60) {
        case 1:
            s = D_8013B998_801375B4.sub;
            if (s == 0) {
                func_80139710();
                PutDispEnv(&g_Game_801375B4.db[g_Game_801375B4.cur].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[g_Game_801375B4.cur].env);
                D_8013B998_801375B4.sub = 1;
                D_8013B998_801375B4.buf = g_Game_801375B4.cur;
            } else if (s == 1) {
                g_Game_801375B4.db[1].env[0x18] = 0;
                g_Game_801375B4.db[0].env[0x18] = 0;
                PutDispEnv(&g_Game_801375B4.db[D_8013B998_801375B4.buf].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[(s16)(D_8013B998_801375B4.buf ^ 1)].env);
            } else if (s == 2) {
                PutDispEnv(&g_Game_801375B4.db[D_8013B998_801375B4.buf].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[(s16)(D_8013B998_801375B4.buf ^ 1)].env);
                g_Game_801375B4.db[1].env[0x18] = 1;
                g_Game_801375B4.db[0].env[0x18] = 1;
                D_8013AE60 = s;
            }
            break;
        case 3:
            if (D_8013B998_801375B4.sub == 0) {
                PutDispEnv(&g_Game_801375B4.db[g_Game_801375B4.cur].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[g_Game_801375B4.cur].env);
                g_Game_801375B4.db[1].env[0x18] = 0;
                g_Game_801375B4.db[0].env[0x18] = 0;
                D_8013B998_801375B4.sub = 1;
                D_8013B998_801375B4.buf = g_Game_801375B4.cur;
            } else if (D_8013B998_801375B4.sub == 1) {
                PutDispEnv(&g_Game_801375B4.db[D_8013B998_801375B4.buf].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[(s16)(D_8013B998_801375B4.buf ^ 1)].env);
            } else if (D_8013B998_801375B4.sub == 2) {
                PutDispEnv(&g_Game_801375B4.db[D_8013B998_801375B4.buf].env[0x5C]);
                PutDrawEnv(g_Game_801375B4.db[(s16)(D_8013B998_801375B4.buf ^ 1)].env);
            }
            break;
        default:
            PutDispEnv(&g_Game_801375B4.db[g_Game_801375B4.cur].env[0x5C]);
            PutDrawEnv(g_Game_801375B4.db[g_Game_801375B4.cur].env);
            break;
        }
        DrawOTag(&g_Game_801375B4.db[g_Game_801375B4.cur].ot[0xFFF]);
        DrawOTag(g_Game_801375B4.db[g_Game_801375B4.cur].hud);
        Cd_Update();
    }
    DrawSync(0);
    VSync(0);
    return 0;
}

extern struct { u8 pad0[0x8120]; u16 f_8120; u8 pad8122[2]; u16 f_8124; u16 stage; u8 pad8128[0x1A4]; u8 f_82CC; u8 f_82CD; } g_Game_80137C88 asm("g_Game");
extern s16 D_8013B480;
extern s16 D_8013B482;
extern s16 D_8013AEA8;
extern s16 D_8013AEA4[];
s32 Cd_StartFileLoad(s32, s32);
void func_8013AABC(void);

s32 func_80137C88(void) {
    s32 a, b;
    s32 pad[2];

    switch (D_8013AE60) {
    case 0:
        if (D_8013B480 != 0 && func_800116C0() < 0) {
            Sound_ResumeStreams();
            D_8013B480 = 0;
        }
        D_8013B482 += 2;
        if (D_8013B482 < 0x79) {
            return 0;
        }
        if (D_8013B480 != 0) {
            return 0;
        }
        D_8013B482 = 0;
        func_80138138(2);
        switch (g_Game_80137C88.f_8120) {
        case 0x12:
            D_8013AEA8 = 3;
            break;
        case 0x11:
            break;
        case 0x17:
            D_8013AEA4[2] = 4;
            D_8013AEA4[6] = 5;
            D_8013AEA4[10] = 6;
            ((s8 *)D_8013AEA4)[0x1E] = -1;
            switch (g_Game_80137C88.f_8124) {
            case 7:
                g_Game_80137C88.f_82CC = 2;
                g_Game_80137C88.f_82CD = 0;
                break;
            case 14:
                g_Game_80137C88.f_82CC = 5;
                g_Game_80137C88.f_82CD = 0;
                break;
            }
            break;
        }
        func_801385B0();
        func_80136000(&D_8013B998_80137198.eye, &D_8013B998_80137198.at);
        func_801399A4(D_8013B6F0);
        D_8013AE60 = 1;
        D_8013B998_80137198.sub = 0;
        D_8013B998_80137198.timer = 0;
        Sound_PlayFixed(0xAC);
        return 0;
    case 1:
        b = D_8013B998_80137198.timer;
        if (b < 6) {
            a = b * 192 / 5;
            b = 2;
            if (a > 0xC0) {
                a = 0xC0;
            }
        } else {
            b = (b - 5) * 30;
            a = 0xC0;
            if (b > 0x80) {
                b = 0x80;
            }
        }
        func_80139FB8(a, b);
        if (++D_8013B998_80137198.timer < 11) {
            return 0;
        }
        D_8013B998_80137198.sub = 2;
        return 0;
    case 2:
        if ((g_Pad_80137198.held & g_Pad_80137198.mask & 0x860) || *D_8013B9B8 == 0x3FC0) {
            Sound_PlayFixed(0xAD);
            D_8013B480 = 2;
            D_8013AE60 = 3;
            D_8013B998_80137198.sub = 0;
            D_8013B998_80137198.timer = 10;
        }
        break;
    case 3:
        if (D_8013B480 == 1 && func_800116C0() < 0) {
            D_8013B480 = 0;
        }
        if (D_8013B998_80137198.sub < 2) {
            b = D_8013B998_80137198.timer;
            if (b < 6) {
                a = b * 192 / 5;
                b = 2;
                if (a > 0xC0) {
                    a = 0xC0;
                }
            } else {
                b = (b - 5) * 30;
                a = 0xC0;
                if (b > 0x80) {
                    b = 0x80;
                }
            }
            func_8013A10C(a, b);
            if (--D_8013B998_80137198.timer < 0) {
                D_8013B998_80137198.sub = 2;
                Cd_StartFileLoad(1, g_Game_80137C88.stage);
                D_8013B480 = 1;
                if (g_Game_80137C88.stage != 0x13 && g_Game_80137C88.stage != 0x24) {
                    Sound_UnloadBanks(1);
                }
            }
        }
        if (D_8013B480 == 0) {
            D_8013B480 = 1;
            return -1;
        }
        return 0;
    }
    func_801385B0();
    func_80136000(&D_8013B998_80137198.eye, &D_8013B998_80137198.at);
    func_801399A4(D_8013B6F0);
    func_8013AABC();
    return 0;
}

extern u8 *D_800B4D64;
void Model_BindMesh(void *, void *);

void func_801380DC(void) {
    u32 *b = (u32 *)0x80154000;

    Model_BindMesh(D_800B4D64 + 0x80, b + M2C_FIELD(b, u16 *, 0x38));
}

extern u32 *D_8013B9C8;

void func_80138118(void) {
    u32 *b = (u32 *)0x80154000;

    D_8013B9C8 = b + M2C_FIELD(b, u16 *, 0x34);
}

typedef struct { u16 mesh, f_2, f_4, f_6, f_8, pad; } Ent_80138138;
typedef struct { u32 *f_0; u8 pad4[0xC]; u16 f_10, f_12, f_14, f_16; u8 pad18[4]; u32 f_1C; } Obj_80138138;
typedef struct { u8 pad0[0x18]; u8 *f_18; u8 pad1C[0x40]; s16 f_5C, f_5E, f_60, f_62, f_64; u8 pad66[0xA]; s16 f_70, f_72; u8 *f_74; u8 pad78[0x10]; } Act_80138138;
extern struct { u8 pad0[0x8224]; u8 *f_8224; Ent_80138138 *f_8228; u8 pad822C[0x54]; s32 f_8280; } g_Game_80138138 asm("g_Game");
extern Act_80138138 D_8013B6F0_80138138[] asm("D_8013B6F0");
void Zone_SetTable(s32 *);
void *func_8008C09C(s32);
void func_80015AC0(void *, u8 *);

s32 func_80138138(s32 n) {
    u8 *b;
    s32 i;
    Obj_80138138 *o;
    u8 *t;
    u8 *t2;

    b = (u8 *)0x80154000;
    g_Game_80138138.f_8224 = b + M2C_FIELD(b, u16 *, 0x2C) * 4;
    g_Game_80138138.f_8228 = (Ent_80138138 *)(b + M2C_FIELD(b, u16 *, 0x30) * 4 + 4);
    g_Game_80138138.f_8280 = *(s32 *)(b + M2C_FIELD(b, u16 *, 0x30) * 4);
    Zone_SetTable(0);
    D_800B4D64 = func_8008C09C((g_Game_80138138.f_8280 + 1) << 5);
    for (i = 0; i < g_Game_80138138.f_8280; i++) {
        {
        register Obj_80138138 *o asm("$4") = (Obj_80138138 *)(i * 32 + (s32)D_800B4D64);
        o->f_10 = g_Game_80138138.f_8228[i].f_4;
        o->f_14 = g_Game_80138138.f_8228[i].f_8;
        o->f_12 = g_Game_80138138.f_8228[i].f_6;
        o->f_16 = 0;
        Model_BindMesh(o, g_Game_80138138.f_8224 + M2C_FIELD(g_Game_80138138.f_8224 + g_Game_80138138.f_8228[i].mesh * 4, u16 *, 4) * 4);
        }
        o = (Obj_80138138 *)(i * 32 + (s32)D_800B4D64);
        o->f_1C = g_Game_80138138.f_8228[i].f_2;
        *o->f_0 &= 0xFFFF1FFF;
        o->f_16 = 0xFFFF;
    }
    for (i = 0; i < n; i++) {
        func_80015AC0(&D_8013B6F0_80138138[i], b + M2C_FIELD(b + i * 4, u16 *, 4) * 4);
        t = (u8 *)(M2C_FIELD(b + i * 4, u16 *, 0x18) * 4) + (u32)b;
        D_8013B6F0_80138138[i].f_18 = t + *(s32 *)t * 4 + 4;
        t2 = b + M2C_FIELD(b + i * 4, u16 *, 0x18) * 4 + 4;
        D_8013B6F0_80138138[i].f_5C = 0;
        D_8013B6F0_80138138[i].f_5E = 0;
        D_8013B6F0_80138138[i].f_70 = 0;
        D_8013B6F0_80138138[i].f_72 = 0;
        D_8013B6F0_80138138[i].f_60 = 0;
        D_8013B6F0_80138138[i].f_62 = 0;
        D_8013B6F0_80138138[i].f_64 = -0x1000;
        D_8013B6F0_80138138[i].f_74 = t2;
    }
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_80138370;
extern s16 D_8013B48C;
extern s16 D_8013B48A;
extern s16 D_8013B484[];
extern u16 g_RandSeed;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80138370 asm("g_Game");

s32 func_80138370(void) {
    Sprt_80138370 *p;
    u32 *ot;
    s32 k;

    if (D_8013B48C > 0) {
        D_8013B48C--;
        if (D_8013B48C % 10 >= 6) {
            return 0;
        }
    } else {
        D_8013B48A = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 3;
        D_8013B48C = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 11 + 1) * 20;
    }
    k = D_8013B48A + 2;
    if (k >= 3) {
        k = D_8013B48A - 1;
    }
    p = (Sprt_80138370 *)g_Game_80138370.prim;
    *(u32 *)&p->r0 = 0x808080;
    ((u8 *)p)[3] = 4;
    p->code = 0x64;
    p->x0 = D_8013B484[D_8013B48A];
    p->y0 = D_8013B48A * 40 + 0x3C;
    p->u0 = 0;
    p->v0 = k * 13 - 0x50;
    p->w = 0x38;
    p->h = 0xD;
    p->clut = 0x5B;
    ot = g_Game_80138370.db[g_Game_80138370.cur].ot;
    ADD_PRIM_R(ot, p, "$4", "$3");
    p++;
    ((u8 *)p)[3] = 1;
    ((u32 *)p)[1] = 0xE100020D;
    ot = g_Game_80138370.db[g_Game_80138370.cur].ot;
    ADD_PRIM_R(ot, p, "$4", "$3");
    g_Game_80138370.prim = (u8 *)p + 8;
    return 0;
}

typedef struct { u8 pad0[0x5C]; u16 frame; u16 anim; u8 pad60[0x10]; s16 next; u16 flags; s16 (*anims)[2]; s16 tr[3]; s16 rsteps; s16 tp[3]; s16 psteps; } Mdl_801385B0;
typedef struct { u16 x; u16 y; u16 str; s8 type; s8 on; } Txt_801385B0;
extern struct { s16 x, y; u8 pad4[8]; s32 fC; SVECTOR eye; SVECTOR at; s16 *pc; s16 *mark; u8 pad28[0xC]; s16 eyeT[3]; s16 eyeN; s16 atT[3]; s16 atN; s32 wait; u8 pad48[8]; u16 f50; u8 pad52[6]; s32 flags; s32 timer; } D_8013B998_801385B0 asm("D_8013B998");
extern Mdl_801385B0 D_8013B6F0_801385B0[] asm("D_8013B6F0");
extern Txt_801385B0 D_8013AEA4_801385B0[] asm("D_8013AEA4");
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x26]; u16 stage; } g_Game_801385B0 asm("g_Game");
void Cd_PlayXaTrack();
void func_80139248(void);
void func_801394D0(void);

void func_801385B0(void) {
    s16 *p;
    s32 f;
    s32 t;
    u16 op;
    s32 v;
    s32 n, dx, dy, dz;
    s32 ex, ey, ez;
    s32 xa;
    s32 st;
    Txt_801385B0 *e;

    f = D_8013B998_801385B0.flags;
    p = D_8013B998_801385B0.pc;
    if (f & 1) {
        t = D_8013B998_801385B0.timer;
        if (t <= 0xFFFE) {
            t++;
        }
        D_8013B998_801385B0.timer = t;
        D_8013B998_801385B0.flags = f | 2;
    }
    while (*p != 0x3FC0) {
        op = *p;
        switch (op & 0x3FC0) {
        case 0x40:
            {
            s16 i = op & 0x3F;
            switch (i) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                p++;
                D_8013B6F0_801385B0[i].tp[0] = *p;
                p++;
                D_8013B6F0_801385B0[i].tp[1] = *p;
                p++;
                D_8013B6F0_801385B0[i].tp[2] = *p;
                p++;
                D_8013B6F0_801385B0[i].psteps = *p;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                break;
            case 17:
                p++;
                D_8013B998_801385B0.eye.vx = *p;
                p++;
                D_8013B998_801385B0.eye.vy = *p;
                p++;
                D_8013B998_801385B0.eye.vz = *p;
                break;
            case 16:
                p++;
                D_8013B998_801385B0.at.vx = *p;
                p++;
                D_8013B998_801385B0.at.vy = *p;
                p++;
                D_8013B998_801385B0.at.vz = *p;
                break;
            case 19:
                p++;
                D_8013B998_801385B0.eyeT[0] = *p;
                p++;
                D_8013B998_801385B0.eyeT[1] = *p;
                p++;
                D_8013B998_801385B0.eyeT[2] = *p;
                p++;
                D_8013B998_801385B0.eyeN = *p;
                break;
            case 18:
                p++;
                D_8013B998_801385B0.atT[0] = *p;
                p++;
                D_8013B998_801385B0.atT[1] = *p;
                p++;
                D_8013B998_801385B0.atT[2] = *p;
                p++;
                D_8013B998_801385B0.atN = *p;
                break;
            }
            }
            break;
        case 0x80:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_8013B6F0_801385B0[i].tr[0] = *p;
                p++;
                D_8013B6F0_801385B0[i].tr[1] = *p;
                p++;
                D_8013B6F0_801385B0[i].tr[2] = *p;
                p++;
                D_8013B6F0_801385B0[i].rsteps = *p;
            }
            }
            break;
        case 0x0:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_8013B6F0_801385B0[i].flags = *p;
            }
            }
            break;
        case 0x140:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_8013B6F0_801385B0[i].next = *p;
            }
            }
            break;
        case 0x180:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                v = *p;
                D_8013B6F0_801385B0[i].anim = v;
                D_8013B6F0_801385B0[i].frame = D_8013B6F0_801385B0[i].anims[v][0];
                D_8013B6F0_801385B0[i].next = v;
            }
            }
            break;
        case 0x1C0:
            p++;
            D_8013B998_801385B0.wait = *p;
            break;
        case 0x200:
            if (D_8013B998_801385B0.wait != 0) {
                D_8013B998_801385B0.wait--;
                goto done;
            }
            break;
        case 0xC0:
            p++;
            D_8013AEA4_801385B0[*p].on = 1;
            break;
        case 0x240:
            D_8013B998_801385B0.mark = p + 1;
            break;
        case 0x280:
            p = D_8013B998_801385B0.mark;
            goto done2;
        case 0x300:
            D_8013B998_801385B0.flags = 1;
            break;
        case 0x340:
            if (!(D_8013B998_801385B0.flags & 2)) {
                D_8013B998_801385B0.wait--;
                goto done;
            }
            break;
        case 0x380:
            if ((u32)D_8013B998_801385B0.timer < (u32)p[1]) {
                goto done2;
            }
            p++;
            break;
        case 0x3C0:
            st = g_Game_801385B0.stage;
            if (st == 0x13 || st == 0x24) {
                Cd_PlayXaTrack(0x28);
            } else {
                xa = 0;
                switch (func_80010CA4(st)) {
                case 2:
                    xa = 1;
                    break;
                case 3:
                    break;
                case 4:
                    xa = 2;
                    break;
                case 5:
                    xa = 3;
                    break;
                case 6:
                    break;
                case 7:
                    xa = 4;
                    break;
                case 8:
                case 9:
                    break;
                case 10:
                    xa = 5;
                    break;
                case 11:
                    xa = 6;
                    break;
                }
                Cd_PlayXaTrack(xa | 0x10);
            }
            break;
        }
        p++;
    }
done:
done2:
    D_8013B998_801385B0.pc = p;
    n = D_8013B998_801385B0.eyeN;
    if (n > 0) {
        dx = (D_8013B998_801385B0.eyeT[0] - D_8013B998_801385B0.eye.vx) / n;
        dy = (D_8013B998_801385B0.eyeT[1] - D_8013B998_801385B0.eye.vy) / n;
        dz = (D_8013B998_801385B0.eyeT[2] - D_8013B998_801385B0.eye.vz) / n;
        D_8013B998_801385B0.eyeN = --n;
        D_8013B998_801385B0.eye.vx += dx;
        D_8013B998_801385B0.eye.vy += dy;
        D_8013B998_801385B0.eye.vz += dz;
    }
    n = D_8013B998_801385B0.atN;
    if (n > 0) {
        ex = (D_8013B998_801385B0.atT[0] - D_8013B998_801385B0.at.vx) / n;
        ey = (D_8013B998_801385B0.atT[1] - D_8013B998_801385B0.at.vy) / n;
        ez = (D_8013B998_801385B0.atT[2] - D_8013B998_801385B0.at.vz) / n;
        D_8013B998_801385B0.atN = --n;
        D_8013B998_801385B0.at.vx += ex;
        D_8013B998_801385B0.at.vy += ey;
        D_8013B998_801385B0.at.vz += ez;
    }
    for (e = D_8013AEA4_801385B0; e->on >= 0; e++) {
        if ((u8)e->on == 0) {
            continue;
        }
        D_8013B998_801385B0.x = e->x;
        D_8013B998_801385B0.y = e->y;
        switch (e->type) {
        case 0:
            func_80139248();
            break;
        case 1:
            break;
        case 2:
            if (g_Game_801385B0.frame % 30 < 15) {
                func_801394D0();
                if (g_Game_801385B0.stage != 0x13 && g_Game_801385B0.stage != 0x24 && g_Game_801385B0.frame % 30 == 0) {
                    Sound_PlayFixed(0xAF);
                }
            }
            break;
        }
    }
}

typedef struct { u8 pad0[4]; s16 a; u8 pad6[2]; s16 b; u8 padA[4]; s16 c; u8 str[8]; } Scr_80138E04;
typedef struct { s16 x, y; u16 clut, tpage; u32 *ot; } TextPos_80138E04;
extern TextPos_80138E04 D_8013B998_8E04 asm("D_8013B998");
extern struct { u8 pad0[4]; u8 *prim; u8 pad8[0x811E]; u16 stage; } g_Game_80138E04 asm("g_Game");
s32 func_80097FB0(s32);

void func_80138E04(void) {
    Scr_80138E04 *sc = (Scr_80138E04 *)0x1F800000;
    u8 *s = sc->str;
    SprtTp *p;
    s32 v, t;
    register u32 *ot asm("$4");

    v = sc->a;
    t = v / 10;
    v = v - t * 10;
    s[0] = t ? t + 0x6A : 0xFF;
    s[1] = v < 6 ? v + 0x6A : v + 0x74;
    s[2] = 0x8D;
    v = sc->b;
    if (v >= 10) {
        t = v / 10;
        v = v - t * 10;
        s[3] = t + 0x6A;
        s[4] = v < 6 ? v + 0x6A : v + 0x74;
        s[5] = 0;
    } else {
        s[3] = v < 6 ? v + 0x6A : v + 0x74;
        s[4] = 0;
    }
    D_8013B998_8E04.x = 0x40;
    D_8013B998_8E04.y = 0xB8;
    func_80139628(s);
    v = func_80097FB0(Stage_GetWorld(g_Game_80138E04.stage));
    t = v / 10;
    v = v - t * 10;
    s[0] = t ? t + 0x6A : 0xFF;
    s[1] = v < 6 ? v + 0x6A : v + 0x74;
    s[2] = 0x8D;
    v = sc->c;
    if (v >= 10) {
        t = v / 10;
        v = v - t * 10;
        s[3] = t + 0x6A;
        s[4] = v < 6 ? v + 0x6A : v + 0x74;
        s[5] = 0;
    } else {
        s[3] = v < 6 ? v + 0x6A : v + 0x74;
        s[4] = 0;
    }
    D_8013B998_8E04.x = 0xB4;
    D_8013B998_8E04.y = 0xB8;
    func_80139628(s);
    p = (SprtTp *)g_Game_80138E04.prim;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    p->tpage = 0xE100023D;
    p->x0 = 0x94;
    p->y0 = 0xB0;
    p->u0 = 0x80;
    p->v0 = 0x60;
    p->clut = 0x7177;
    p->w = 0x20;
    p->h = 0x20;
    ot = D_8013B998_8E04.ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    p->tpage = 0xE100022F;
    p->u0 = 0xA0;
    p->v0 = 0x40;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    p->x0 = 0x20;
    p->y0 = 0xB0;
    p->clut = 0x3A7F;
    p->w = 0x20;
    p->h = 0x20;
    ot = D_8013B998_8E04.ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    g_Game_80138E04.prim = (u8 *)p;
}

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

extern struct { u8 pad0[0x8120]; u16 f_8120; u8 pad8122[4]; u16 f_8126; u8 pad8128[0x20]; s32 f_8148; } g_Game_80139248 asm("g_Game");
extern s16 D_8013B53C[];
extern s16 D_8013B54E[];
extern s16 D_8013B560[];
extern s16 D_8013B572[];
extern s16 D_8013B584[];
extern s16 D_8013B596[];
extern s16 D_8013B5CC[];
extern s16 D_8013B7EA;
s32 Stage_GetTargetTimes(u32);
void Hud_DrawTime(s32, s32, u32);
void Hud_DrawTimeMedal(s32, s32, u32, s16 *);
void func_8013912C(void *arg0, s32 arg1);
void func_801397F4(s32 x, s32 y, s32 val);
void func_80138E04(void);

void func_80139248(void) {
    s32 w;
    s32 n;
    s32 times;
    s32 t;
    s32 s;
    u16 *info;

    s = g_Game_80139248.f_8126;
    if (s == 0x13 || s == 0x24) {
        func_8013912C(D_8013B5CC, 3);
    } else {
        info = (u16 *)0x1F800000;
        w = Stage_GetWorld(s);
        Stage_GetInfo(w, info);
        switch (g_Game_80139248.f_8120) {
        case 0xA:
            switch ((s16)info[8]) {
            case 0:
                if (w == 0x11 || (u32)(w - 0x16) < 9) {
                    func_8013912C(D_8013B596, 2);
                } else if ((s16)info[2] > 0) {
                    n = (s16)info[3] - (s16)info[2];
                    func_8013912C(D_8013B54E, 3);
                    func_801397F4(0x30, 0x58, n);
                } else {
                    n = (s16)info[3];
                    func_8013912C(D_8013B53C, 3);
                    func_801397F4(0x80, 0x58, n);
                }
                break;
            case 1:
                Stage_GetInfo(0x18, info + 0xA);
                if ((s16)info[0x12] > 0) {
                    n = (s16)info[4] - (s16)info[2];
                    func_8013912C(D_8013B572, 3);
                    func_801397F4(0x90, 0x58, n);
                } else {
                    func_8013912C(D_8013B560, 2);
                    D_8013B7EA = 0;
                }
                break;
            case 2:
                func_8013912C(D_8013B584, 2);
                D_8013B7EA = 0;
                break;
            }
            func_80138E04();
            break;
        case 0x12:
            n = (s16)info[5];
            func_8013912C(D_8013B53C, 3);
            func_801397F4(0x80, 0x58, n);
            times = Stage_GetTargetTimes(w);
            t = g_Game_80139248.f_8148;
            if (t != -1) {
                Hud_DrawTime(0x104, 0xC0, t);
                Hud_DrawTimeMedal(0xEC, 0xB8, t, (s16 *)times);
                func_8013912C((u8 *)D_8013B53C + 0x7E, 1);
            }
            break;
        case 0x13:
            break;
        }
    }
}

extern struct { u8 pad0[4]; SprtTp *prim; u32 *ot; u8 padC[0x8120 - 0xC]; u16 f_8120; u8 pad8122[4]; u16 f_8126; } g_Game_801394D0 asm("g_Game");

void func_801394D0(void) {
    SprtTp *p;
    u32 *ot;

    p = g_Game_801394D0.prim;
    ot = g_Game_801394D0.ot;
    *(u32 *)&p->x0 = 0x1E001E;
    switch (g_Game_801394D0.f_8126) {
    case 0x13:
        *(u32 *)&p->x0 = 0x1E003E;
        ((u8 *)p)[3] = 5;
        p->code = 0x67;
        p->tpage = 0xE100022A;
        *(u16 *)&p->u0 = 0;
        p->clut = 0x3C2B;
        *(u32 *)&p->w = 0x400100;
        break;
    case 0x24:
        *(u32 *)&p->x0 = 0x1E003E;
        ((u8 *)p)[3] = 5;
        p->code = 0x67;
        p->tpage = 0xE100022A;
        *(u16 *)&p->u0 = 0x4000;
        p->clut = 0x3C6B;
        *(u32 *)&p->w = 0x400100;
        break;
    default:
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE100022B;
        p->code = 0x65;
        *(u32 *)&p->w = 0x200100;
        *(u32 *)&p->x0 = 0x1E001E;
        switch (g_Game_801394D0.f_8120) {
        case 0xA:
            *(u16 *)&p->u0 = 0;
            p->clut = 0x3C37;
            break;
        case 0x12:
            *(u16 *)&p->u0 = 0x2000;
            p->clut = 0x3637;
            break;
        }
        break;
    }
    ADD_PRIM_ASM2(ot, p);
    p++;
    D_800EC354 = (u8 *)p;
}

extern struct S_g_Game g_Game;
/* addPrim with hard a0 (lwl) / v0 (sll) temps and memory operands */
#define ADD_PRIM_A0V0_80139628(ot, p) \
    __asm__ volatile("lwl $4, %0\n\tsll $2, %2, 8\n\tswl $2, %0\n\tswl $4, %1" \
                     : : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p) : "$2", "$4")
typedef struct { s16 x, y; u16 clut, tpage; u32 *ot; } TextPos_80139628;
extern TextPos_80139628 D_8013B998_9628 asm("D_8013B998");
extern u8 D_8013B5E0[];

void func_80139628(u8 *str) {
    SprtTp *p = (SprtTp *)G_DRAW.prim;
    s32 x = D_8013B998_9628.x;
    s32 y = D_8013B998_9628.y;
    u8 c = *str;

    while (c != 0) {
        *(u32 *)&p->r0 = 0x404040;
        ((u8 *)p)[3] = 5;
        p->tpage = (D_8013B998_9628.tpage & 0x9FF) | 0xE1000200;
        p->u0 = (c & 0xF) << 4;
        p->code = 0x66;
        p->x0 = x;
        p->y0 = y;
        p->v0 = c & 0xF0;
        p->clut = D_8013B998_9628.clut;
        p->w = 0x10;
        p->h = 0x10;
        ADD_PRIM_A0V0_80139628(D_8013B998_9628.ot, p);
        p++;
        str++;
        x += D_8013B5E0[c];
        c = *str;
    }
    D_8013B998_9628.x = x;
    G_DRAW.prim = (u8 *)p;
}

extern struct S_g_Game g_Game;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0, w, h; } Tile_80139710;
void SetDrawStp(void *, s32);

void func_80139710(void) {
    u8 *p;
    u8 *base;
    u32 *ot;

    p = G_DRAW.prim;
    p[3] = 3;
    *(u32 *)&((Tile_80139710 *)p)->r0 = 0;
    ((Tile_80139710 *)p)->code = 0x60;
    ((Tile_80139710 *)p)->w = 0x180;
    ((Tile_80139710 *)p)->x0 = 0;
    ((Tile_80139710 *)p)->y0 = 0;
    ((Tile_80139710 *)p)->h = 0xF0;
    base = (u8 *)&g_Game + 0x80;
    ot = &((u32 *)(base + G_DRAW.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x10;
    SetDrawStp(p, 1);
    ot = &((u32 *)(base + G_DRAW.cur * 0x4078))[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0xC;
    G_DRAW.prim = p;
}

typedef struct { u8 len[4]; u32 mode; u8 r, g, b, code; s16 x, y; u8 u, v; u16 clut; s16 w, h; } Spr_801397F4;
extern s32 D_8013B6E0;

void func_801397F4(s32 x, s32 y, s32 val) {
    Spr_801397F4 *p;
    u32 *ot;
    s32 d, e;

    if ((D_8013B6E0 >> 1) < val) {
        val = D_8013B6E0 >> 1;
        D_8013B6E0++;
    }
    p = (Spr_801397F4 *)G_DRAW.prim;
    ot = G_DRAW.ot;
    p->len[3] = 5;
    p->mode = 0xE100024B;
    p->code = 0x65;
    p->x = x;
    p->y = y;
    p->w = 0x18;
    p->h = 0x20;
    d = val / 10;
    d = d ? d - 1 : 10;
    p->clut = 0x3677;
    p->u = (d % 3) * 24;
    p->v = (d / 3) * 32 + 0x40;
    ADD_PRIM_ASM(ot, p);
    p++;
    x += 0x18;
    e = val % 10;
    p->len[3] = 5;
    p->mode = 0xE100024B;
    p->code = 0x65;
    p->x = x;
    p->y = y;
    p->w = 0x18;
    p->h = 0x20;
    e = e ? e - 1 : 9;
    p->clut = 0x3677;
    p->u = (e % 3) * 24;
    p->v = (e / 3) * 32 + 0x40;
    ADD_PRIM_ASM(ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

typedef struct { s16 start; s16 end; } Anim_801399A4;
typedef struct { u8 *model; u8 pad4[0x10]; s32 f14; u8 pad18[0xC]; s32 px, py, pz; u8 pad30[0x2C]; u16 frame; u16 anim; SVECTOR rot; u8 pad68[8]; s16 next; u16 flags; Anim_801399A4 *anims; s16 trx, try_, trz, rsteps; s16 tpx, tpy, tpz, psteps; } Ent_801399A4;
extern struct { u8 pad0[0x20]; u8 *f_20; u8 pad24[0x24]; s32 f_48; } D_8013B998_99A4 asm("D_8013B998");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 f_8120; } g_Game_801399A4 asm("g_Game");
extern u8 D_8013B008[];
extern u8 D_800EA060[];
extern u8 D_800E7D00[];
extern u8 D_800E9C80[];
void VectorNormalSS(SVECTOR *, SVECTOR *);
void func_80014804(SVECTOR *, s32);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
s32 rsin(s32);
void func_80017CD4(void *, void *, void *);
void Model_DrawWireframe(void *, void *, void *);
void Model_ProjectVertsAlt(void *, void *, void *);
void func_80017EFC(void *, void *, void *, s32);

void func_801399A4(Ent_801399A4 *arr) {
    Ent_801399A4 *e;
    SVECTOR v;
    s32 i;
    s32 n;
    s32 dx, dy, dz;
    s32 s;
    s32 x, y, z;
    s32 k, px, py, pz;

    for (i = 0; i < 5; i++) {
        e = &arr[i];
        if (!(e->flags & 1)) {
            continue;
        }
        n = e->rsteps;
        if (n > 0) {
            dx = (e->trx - e->rot.vx) / n;
            dy = (e->try_ - e->rot.vy) / n;
            dz = (e->trz - e->rot.vz) / n;
            e->rsteps = --n;
            e->rot.vx += dx;
            e->rot.vy += dy;
            e->rot.vz += dz;
        }
        k = e->psteps;
        if (k > 0) {
            px = (e->tpx - (x = e->px)) / k;
            py = (e->tpy - (y = e->py)) / k;
            z = e->pz;
            pz = (e->tpz - z) / k;
            e->psteps = --k;
            e->px = x + px;
            e->py = y + py;
            e->pz = z + pz;
        }
        VectorNormalSS(&e->rot, &v);
        func_80014804(&v, e->f14);
        e->frame++;
        if (e->anims[e->anim].end < e->frame) {
            if (e->next != -1) {
                e->frame = e->anims[e->next].start;
                e->anim = e->next;
            } else {
                e->frame--;
            }
        }
        func_80015780(e, 1);
        Model_ProjectBonedVerts(e);
        if (e->flags & 2) {
            if (g_Game_801399A4.f_8120 == 0x17) {
                continue;
            }
            if (D_8013B998_99A4.f_20 == D_8013B008) {
                s = rsin(g_Game_801399A4.frame << 4) / 80 + 0x96;
            } else {
                s = rsin(g_Game_801399A4.frame << 4) / 50 + 0x8C;
            }
            func_80139EE0(1, *(u16 *)(e->model + 6), s);
            func_80017CD4(g_Game_801399A4.ot, D_800EA060, e);
            func_80139EE0(0, *(u16 *)(e->model + 6), s);
            Model_DrawWireframe(g_Game_801399A4.ot, D_800EA060, e);
            func_80139E0C(s);
        } else {
            func_80017CD4((u32 *)(g_Game_801399A4.cur * 0x4078 + ((u8 *)&g_Game_801399A4 + 0x80)), D_800E7D00, e);
            if (D_8013B998_99A4.f_48 != 0) {
                Model_ProjectVertsAlt(D_800B4D64 + 0x80, D_800E9C80, D_800E7D00);
                func_80017EFC(g_Game_801399A4.ot, D_800E7D00, D_800B4D64 + 0x80, 0);
            }
        }
    }
}

typedef struct { s16 x, y, w, h; } Rect_80139E0C;
void SetDrawMove(void *, Rect_80139E0C *, s32, s32);

void func_80139E0C(s32 y)
{
  u8 (*new_var)[];
  Rect_80139E0C r;
  u8 *p;
  u32 *ot;
  u32 *ot2;
  ot = (*((GameDraw *) (&g_Game))).ot;
  p = (*((GameDraw *) (&g_Game))).prim;
  if ((*((GameDraw *) (&g_Game))).cur != 0)
  {
    y += 0x100;
  }
 do { r.x = 0x18; r.y = y; r.w = 0x80; r.h = 1; SetDrawMove(p, &r, 0x200, 0); __asm__ volatile("lwl " "$4" ", 2(%0)\n\tsll " "$2" ", %2, 8\n\tswl " "$2" ", 2(%0)\n\tswl " "$4" ", %1" : : "r"(ot + 0xFFE), "m"(*((u8 *)(p) + 2)), "r"(p) : "$4", "$2"); p += 0x18; r.x = 0x200; r.y = 0; SetDrawMove(p, &r, 0x18, y); } while (0);
  __asm__ volatile("lwl " "$3" ", 2(%0)\n\tsll " "$2" ", %2, 8\n\tswl " "$2" ", 2(%0)\n\tswl " "$3" ", %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$3", "$2");
  new_var = &g_Game;
  p += 0x18;
  (*((GameDraw *) new_var)).prim = p;
}

typedef struct { u16 vx, vy, vz, pad; } V_80139EE0;
extern V_80139EE0 D_800E7D00_80139EE0[] asm("D_800E7D00");
extern V_80139EE0 D_800EA060_80139EE0[] asm("D_800EA060");

void func_80139EE0(s32 mode, s32 n, s32 lim) {
    V_80139EE0 *s = D_800E7D00_80139EE0;
    V_80139EE0 *d = D_800EA060_80139EE0;
    s32 i;

    switch (mode) {
    case 0:
        for (i = 0; i < n; i++) {
            d[i].vx = s[i].vx;
            d[i].vy = (s16)s[i].vy < lim ? lim : s[i].vy;
            d[i].vz = s[i].vz;
        }
        break;
    case 1:
        for (i = 0; i < n; i++) {
            d[i].vx = s[i].vx;
            d[i].vy = (s16)s[i].vy > lim ? lim : s[i].vy;
            d[i].vz = s[i].vz;
        }
        break;
    }
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139FB8;
typedef struct { u8 pad0[0x2C]; s16 f_2C; } Txt_80139FB8;
extern Txt_80139FB8 D_8013B998_80139FB8 asm("D_8013B998");
extern GameDraw g_Game_80139FB8 asm("g_Game");

void func_80139FB8(s32 w, s32 h) {
    PolyFT4_80139FB8 *p;
    u32 *ot;
    s32 top;
    s32 bot;
    s32 right;
    s32 left;
    s32 tp;
    u32 *base;
    s32 tp2;

    tp = 0x183;
    top = -(h - 0x80);
    right = w + 0xC0;
    bot = h + 0x80;
    base = (u32 *)(g_Game_80139FB8.cur * 0x4078 + ((u8 *)&g_Game_80139FB8 + 0x80));
    p = (PolyFT4_80139FB8 *)g_Game_80139FB8.prim;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->x0 = 0xC0;
    p->y0 = top;
    p->x1 = right;
    p->y1 = top;
    p->x2 = 0xC0;
    p->y2 = bot;
    p->x3 = right;
    p->y3 = bot;
    if (D_8013B998_80139FB8.f_2C) {
        tp = 0x193;
    }
    p->tpage = tp;
    p->u0 = 0;
    p->v0 = 0;
    p->u1 = 0xC0;
    p->v1 = 0;
    p->u2 = 0;
    p->v2 = tp = 0xFF;
    p->u3 = 0xC0;
    p->v3 = tp;
    ot = base + 0xFFF;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    __asm__("" : : "r"(top), "r"(top), "r"(top));
    left = 0xC0 - w;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->x0 = left;
    p->y0 = top;
    p->x1 = 0xC0;
    p->y1 = top;
    p->x2 = left;
    p->y2 = bot;
    p->x3 = 0xC0;
    p->y3 = bot;
    if (D_8013B998_80139FB8.f_2C) {
        tp2 = 0x190;
    } else {
        tp2 = 0x180;
    }
    p->tpage = tp2;
    p->u0 = 0;
    p->v0 = 0;
    p->u1 = 0xC0;
    p->v1 = 0;
    p->u2 = 0;
    p->v2 = 0xFF;
    p->u3 = 0xC0;
    p->v3 = 0xFF;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    g_Game_80139FB8.prim = (u8 *)p;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_8013A10C;
typedef struct { u32 tag; u32 code; s16 x, y, w, h; } Tile_8013A10C;
extern struct { u8 pad0[0x2C]; s16 f_2C; } D_8013B998_8013A10C asm("D_8013B998");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013A10C asm("g_Game");

void func_8013A10C(s32 w, s32 h) {
    PolyFT4_8013A10C *p;
    Tile_8013A10C *t;
    u32 *ot;
    s32 left;
    s32 top;
    s32 bot;
    s32 right;
    s32 tp;
    u32 *base;
    u8 *cfg;
    s32 tp2;
    s32 kx;
    register u8 uc asm("$11");

    tp = 0x180;
    kx = 0xC0;
    left = kx - w;
    top = 0x80 - h;
    bot = h + 0x80;
    base = g_Game_8013A10C.db[g_Game_8013A10C.cur].ot;
    cfg = (u8 *)&D_8013B998_8013A10C;
    p = (PolyFT4_8013A10C *)g_Game_8013A10C.prim;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->x0 = left;
    p->y0 = top;
    p->x1 = 0xC0;
    p->y1 = top;
    p->x2 = left;
    p->y2 = bot;
    p->x3 = 0xC0;
    p->y3 = bot;
    uc = 0xC0;
    if (M2C_FIELD(cfg, s16 *, 0x2C)) {
        tp = 0x190;
    }
    p->tpage = tp;
    p->u0 = 0;
    p->v0 = 0;
    p->u1 = uc;
    p->v1 = 0;
    p->u2 = 0;
    p->v2 = 0xFF;
    p->u3 = uc;
    p->v3 = 0xFF;
    ot = base + 0xFFF;
    __asm__("" : : "r"(kx));
    ADD_PRIM_R(ot, p, "$2", "$3");
    p++;
    right = w + 0xC0;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->x0 = 0xC0;
    p->y0 = top;
    p->x1 = right;
    p->y1 = top;
    p->x2 = 0xC0;
    p->y2 = bot;
    p->x3 = right;
    p->y3 = bot;
    if (D_8013B998_8013A10C.f_2C) {
        tp2 = 0x193;
    } else {
        tp2 = 0x183;
    }
    p->tpage = tp2;
    p->u0 = 0;
    p->v0 = 0;
    p->u1 = uc;
    p->v1 = 0;
    p->u2 = 0;
    p->v2 = 0xFF;
    p->u3 = uc;
    p->v3 = 0xFF;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    t = (Tile_8013A10C *)p;
    t->code = 0;
    ((u8 *)t)[3] = 3;
    ((u8 *)t)[7] = 0x60;
    t->x = 0;
    t->y = 0;
    t->w = 0x180;
    t->h = top;
    ADD_PRIM_R(ot, t, "$3", "$2");
    p++;
    t = (Tile_8013A10C *)p;
    t->code = 0;
    ((u8 *)t)[3] = 3;
    ((u8 *)t)[7] = 0x60;
    t->x = 0;
    t->y = h + 0x70;
    t->w = 0x180;
    t->h = top;
    ADD_PRIM_R(ot, t, "$3", "$2");
    p++;
    t = (Tile_8013A10C *)p;
    t->code = 0;
    ((u8 *)t)[3] = 3;
    ((u8 *)t)[7] = 0x60;
    t->x = 0;
    t->y = 0;
    t->w = left;
    t->h = 0xF0;
    ADD_PRIM_R(ot, t, "$3", "$2");
    p++;
    t = (Tile_8013A10C *)p;
    t->code = 0;
    ((u8 *)t)[3] = 3;
    ((u8 *)t)[7] = 0x60;
    t->x = right;
    t->y = 0;
    t->w = left;
    t->h = 0xF0;
    ADD_PRIM_R(ot, t, "$3", "$2");
    p++;
    g_Game_8013A10C.prim = (u8 *)p;
}

/* 6 diffs (hand) */
s32 Text_GetWidth2(u8 *);

s32 func_8013A334(u8 *s) {
    s32 w;
    s32 w2;
    u8 *line;
    register s32 c asm("$3");

    w = Text_GetWidth2(s);
    line = NULL;
    for (; (c = *s) != 0; s++) {
        if (c == '\r') {
            line = s + 1;
        }
    }
    if (line != NULL) {
        w2 = Text_GetWidth2(line);
        if (w < w2) {
            w = w2;
        }
    }
    return (0x180 - w) >> 1;
}

typedef struct { s16 x, y, w, h; } Rect_8013A3C4;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; } g_Game_8013A3C4 asm("g_Game");
extern s32 D_8013B6E4;
extern u32 D_800EC35C;
int abs(int);
#define ADD_PRIM_RR_8013A3C4(ot, p) { unsigned int _t1, _t2; __asm__ volatile("lwl %0, 2(%2)\n\tsll %1, %3, 8\n\tswl %1, 2(%2)\n\tswl %0, 2(%3)" : "=&r"(_t1), "=&r"(_t2) : "r"(ot), "r"(p) : "memory"); }

void func_8013A3C4(void) {
    Rect_8013A3C4 r;
    u8 *p;
    u32 *ot;
    s32 k;
    s32 y;
    s32 n;
    s32 amp;
    s32 w;
    s32 one;
    s32 off;
    s32 i;
    s32 ofs;
    s32 half;
    s32 t;

    p = g_Game_8013A3C4.prim;
    ot = g_Game_8013A3C4.ot;
    k = 0x104 - g_Game_8013A3C4.frame % 300;
    for (y = 1; y < 0xF0; y += 2) {
        if (abs(k - y) < 0x1A) {
            *(u32 *)(p + 0xC) = 0x101010;
            *(u32 *)(p + 4) = 0x202020;
        } else {
            *(u32 *)(p + 4) = 0x101010;
            *(u32 *)(p + 0xC) = 0x202020;
        }
        p[3] = 4;
        p[7] = 0x52;
        *(s16 *)(p + 8) = 0;
        *(s16 *)(p + 0xA) = y;
        *(s16 *)(p + 0x10) = 0x180;
        *(s16 *)(p + 0x12) = y;
        ADD_PRIM_ASM(ot, p);
        p += 0x78;
        p[3] = 1;
        *(u32 *)(p + 4) = 0xE1000240;
        ADD_PRIM_ASM(ot, p);
        p += 0x30;
    }
    D_800EC354 = p;
    n = D_8013B6E4--;
    if (n > 10) {
        amp = 0;
        w = 4;
    } else {
        amp = 10;
        w = 4;
        if (n <= 0) {
            D_8013B6E4 = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 200 + 20;
        }
    }
    i = 0;
    ofs = ((u32)i < D_800EC35C) << 8;
    for (; i < 0xF0; i += 2) {
        t = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 100;
        half = (u32)w >> 1;
        one = 1;
        __asm__("" : : "r"(one), "r"(one), "r"(one), "r"(one), "r"(w), "r"(w), "r"(w), "r"(w));
        if (t <= amp) {
            off = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % w + half;
            if (off < 0) {
                r.x = -off;
                r.y = 0xFE;
                r.w = off + 0x180;
                r.h = one;
                SetDrawMove(p, &r, 0, (i + ofs));
                ADD_PRIM_RR_8013A3C4(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (i + ofs);
                r.w = 0x180;
                r.h = one;
                SetDrawMove(p, &r, 0, 0xFE);
                ADD_PRIM_RR_8013A3C4(ot, p);
                p += 0x18;
            }
            if (off > 0) {
                r.x = 0;
                r.y = 0xFE;
                r.w = 0x180 - off;
                r.h = one;
                SetDrawMove(p, &r, off, (i + ofs));
                ADD_PRIM_RR_8013A3C4(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (i + ofs);
                r.w = 0x180;
                r.h = one;
                SetDrawMove(p, &r, 0, 0xFE);
                ADD_PRIM_RR_8013A3C4(ot, p);
                p += 0x18;
            }
        }
    }
    D_800EC354 = p;
}

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

typedef struct { u32 xy; u32 c; } Cell_8013A8C0;
extern Cell_8013A8C0 *D_8013B9F8_8013A8C0 asm("D_8013B9F8");
extern s32 g_Game_8013A8C0 asm("g_Game");

void func_8013A8C0(void) {
    Cell_8013A8C0 *p;
    Cell_8013A8C0 *r;
    Cell_8013A8C0 *l;
    s32 i;
    s32 j;
    s32 a0;
    s32 a1;
    s32 a2;

    p = D_8013B9F8_8013A8C0 + 11 * 16;
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
    p = D_8013B9F8_8013A8C0;
    for (i = 15; i >= 0; i--) {
        p[i].c = 0;
    }
    a0 = g_Game_8013A8C0;
    if (a0 & 0xFF) {
        for (i = 0; i < 16; i++) {
            p[i].c += ((rsin((a0 << 5) + i * 0x100) + 0x1000) * 4) & 0xFF00;
        }
        for (i = 0, a1 = (g_Game_8013A8C0 << 5) + 0x555; i < 16; a1 += 0x100, i++) {
            p[i].c += ((rsin(a1) + 0x1000) >> 6) & 0xFF;
        }
        for (i = 0, a2 = (g_Game_8013A8C0 << 5) + 0xAAA; i < 16; a2 += 0x100, i++) {
            p[i].c += (((rsin(a2) + 0x1000) >> 6) & 0xFF) << 16;
        }
    }
}

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

#include "gte.h"
#define gte_stsxy2_8013ABD4(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stsxy1_8013ABD4(p) __asm__ volatile ("swc2 $13, 0(%0)" : : "r"(p) : "memory")
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; s16 x1, y1; } Line_8013ABD4;
extern struct { s32 frame; u8 *prim; u32 *ot; } g_Game_8013ABD4 asm("g_Game");
extern u8 D_800AF0A0_8013ABD4[] asm("D_800AF0A0");

void func_8013ABD4(void) {
    SVECTOR v0;
    SVECTOR v1;
    s32 z;
    u8 *p;
    u32 *ot;
    s32 k;
    s32 s;
    s32 a;
    s32 dx;
    s32 dy;

    p = g_Game_8013ABD4.prim;
    ot = g_Game_8013ABD4.ot + 0xFFF;
    SetRotMatrix(D_800AF0A0_8013ABD4);
    SetTransMatrix(D_800AF0A0_8013ABD4);
    for (z = ~(g_Game_8013ABD4.frame * 24) & 0xFF; z < 0x1FFF; z += 0x100) {
        s = rsin(z >> 2);
        a = z >> 1;
        dx = (rcos(a) * s) >> 17;
        dy = (rsin(a) * s) >> 17;
        v0.vx = (rcos(0) >> 4) + dx;
        v0.vy = (rsin(0) >> 4) + dy;
        v0.vz = z;
        gte_ldv0(&v0);
        gte_rtps();
        for (k = 0x20; k < 0x1001; k += 0x20) {
            v1.vx = (rcos(k) >> 4) + dx;
            v1.vy = (rsin(k) >> 4) + dy;
            v1.vz = z;
            gte_ldv0(&v1);
            gte_rtps();
            *(u32 *)&((Line_8013ABD4 *)p)->r0 = 0x8000;
            ((u8 *)p)[3] = 3;
            ((Line_8013ABD4 *)p)->code = 0x40;
            gte_stsxy2_8013ABD4(&((Line_8013ABD4 *)p)->x1);
            gte_stsxy1_8013ABD4(&((Line_8013ABD4 *)p)->x0);
            ADD_PRIM_ASM(ot, p);
            p += 0x10;
        }
        __asm__ volatile("" : : "r"(z), "r"(z));
    }
    g_Game_8013ABD4.prim = p;
}
__asm__(".section .text\n.balign 16");
