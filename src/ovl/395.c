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

typedef struct { s16 x, y, w, h; } Rect_80136208;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; u8 pad8122[4]; u16 stage; } g_Game_80136208 asm("g_Game");
extern struct { u8 pad0[4]; s16 f4; s16 f6; u32 *f8; s32 fC; SVECTOR eye; SVECTOR at; u8 pad20[8]; s16 sub; s16 pad2A; s16 buf; u8 pad2E[0x1A]; s32 f48; s32 f4C; } D_80138CA0_80136208 asm("D_80138CA0");
extern struct { u8 pad0[0x24]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_80136208 asm("D_800EBFA0");
extern struct { u8 pad0[8]; s16 f8; u8 padA[6]; s16 f10; } D_801389B4_80136208 asm("D_801389B4");
extern struct { u8 pad0[0xA1]; u8 f_A1; u8 f_A2; } g_GadgetState_80136208 asm("g_GadgetState");
extern s16 D_801389B0;
extern s32 D_80138CE8;
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
s32 DrawSync(s32 mode);
s32 VSync(s32 mode);
void *PutDispEnv(void *env);
void *PutDrawEnv(void *env);
void DrawOTag(u32 *p);
void func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
s32 func_80011194(void *);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_80136954(void);
void func_80137CD4(void);
void Cd_Update(void);
s32 func_8001231C(void);
s32 Sound_UnloadBanks(s32);
s32 Cd_StartFileLoad(s32, s32);
s32 func_800116C0(void);

s32 func_80136208(void) {
    Rect_80136208 r = { 0, 0, 0x180, 0x200 };
    s32 s;

    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    func_8002FAF0(0x148);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_80136208.f24 = 0;
    D_800EBFA0_80136208.f28 = 0x1000;
    D_800EBFA0_80136208.f2C = 0x1000;
    DrawSync(0);
    D_80138CE8 = 0;
    switch (g_Game_80136208.stage) {
    case 2:
        g_Game_80136208.stage = 0x62;
        D_80138CA0_80136208.f48 = 8;
        D_80138CA0_80136208.f4C = 0x18;
        break;
    case 6:
        g_Game_80136208.stage = 0x5C;
        D_80138CA0_80136208.f48 = 2;
        D_801389B4_80136208.f10 = 0x30;
        D_80138CA0_80136208.f4C = 0x19;
        break;
    case 15:
        g_Game_80136208.stage = 0x5D;
        D_80138CA0_80136208.f48 = 3;
        g_GadgetState_80136208.f_A1 = 7;
        g_GadgetState_80136208.f_A2 = 3;
        D_801389B4_80136208.f10 = 0x31;
        D_80138CA0_80136208.f4C = 0x1A;
        break;
    case 20:
        g_Game_80136208.stage = 0x5E;
        D_80138CA0_80136208.f48 = 4;
        D_801389B4_80136208.f10 = 0x32;
        D_80138CA0_80136208.f4C = 0x1B;
        break;
    case 30:
        g_Game_80136208.stage = 0x60;
        D_80138CA0_80136208.f48 = 6;
        D_801389B4_80136208.f10 = 0x33;
        D_80138CA0_80136208.f4C = 0x1C;
        break;
    case 53:
        g_Game_80136208.stage = 0x61;
        D_80138CA0_80136208.f48 = 7;
        D_801389B4_80136208.f8 = 0x24;
        D_801389B4_80136208.f10 = 0x34;
        D_80138CA0_80136208.f4C = 0x1D;
        break;
    default:
        g_Game_80136208.stage = 0x5F;
        D_80138CA0_80136208.f48 = 5;
        D_801389B4_80136208.f10 = 0x35;
        D_80138CA0_80136208.f4C = 0x1E;
        break;
    }
    func_80011194(&D_801389B4_80136208);
    g_Game_80136208.cur = 0;
    D_80138CA0_80136208.f4 = 0x3FDF;
    D_80138CA0_80136208.f6 = 0x26;
    D_80138CA0_80136208.fC = 0x20;
    D_80138CA0_80136208.eye.vz = -0x1000;
    D_801389B0 = 0;
    D_80138CA0_80136208.eye.vx = 0;
    D_80138CA0_80136208.eye.vy = 0;
    D_80138CA0_80136208.at.vx = 0;
    D_80138CA0_80136208.at.vy = 0;
    D_80138CA0_80136208.at.vz = 0;
    g_Game_80136208.db[1].env[0x18] = 1;
    g_Game_80136208.db[0].env[0x18] = 1;
    g_Game_80136208.db[1].env[0x19] = 0;
    g_Game_80136208.db[0].env[0x19] = 0;
    g_Game_80136208.db[1].env[0x1A] = 0;
    g_Game_80136208.db[0].env[0x1A] = 0;
    g_Game_80136208.db[1].env[0x1B] = 8;
    g_Game_80136208.db[0].env[0x1B] = 8;
    g_Game_80136208.mode = 0x11;
    do {
        func_8001325C(0);
        g_Game_80136208.frame++;
        Gfx_BeginFrame();
        D_80138CA0_80136208.f8 = g_Game_80136208.db[g_Game_80136208.cur].hud;
        if (func_80136954() < 0) {
            break;
        }
        DrawSync(0);
        VSync(2);
        switch (D_801389B0) {
        case 1:
            s = D_80138CA0_80136208.sub;
            if (s == 0) {
                func_80137CD4();
                PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
                D_80138CA0_80136208.sub = 1;
                D_80138CA0_80136208.buf = g_Game_80136208.cur;
            } else if (s == 1) {
                g_Game_80136208.db[1].env[0x18] = 0;
                g_Game_80136208.db[0].env[0x18] = 0;
                PutDispEnv(&g_Game_80136208.db[D_80138CA0_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80138CA0_80136208.buf ^ 1)].env);
            } else if (s == 2) {
                PutDispEnv(&g_Game_80136208.db[D_80138CA0_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80138CA0_80136208.buf ^ 1)].env);
                g_Game_80136208.db[1].env[0x18] = 1;
                g_Game_80136208.db[0].env[0x18] = 1;
                D_801389B0 = s;
            }
            break;
        case 3:
            if (D_80138CA0_80136208.sub == 0) {
                PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
                g_Game_80136208.db[1].env[0x18] = 0;
                g_Game_80136208.db[0].env[0x18] = 0;
                D_80138CA0_80136208.sub = 1;
                D_80138CA0_80136208.buf = g_Game_80136208.cur;
            } else if (D_80138CA0_80136208.sub == 1) {
                PutDispEnv(&g_Game_80136208.db[D_80138CA0_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80138CA0_80136208.buf ^ 1)].env);
            } else if (D_80138CA0_80136208.sub == 2) {
                PutDispEnv(&g_Game_80136208.db[D_80138CA0_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80138CA0_80136208.buf ^ 1)].env);
                D_801389B0 = 4;
            }
            break;
        default:
            PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
            PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
            break;
        }
        DrawOTag(&g_Game_80136208.db[g_Game_80136208.cur].ot[0xFFF]);
        Cd_Update();
    } while (D_801389B0 != 4);
    DrawSync(0);
    VSync(0);
    func_8001231C();
    Sound_UnloadBanks(1);
    Cd_StartFileLoad(1, g_Game_80136208.stage);
    while (func_800116C0() == 0) {
        Cd_Update();
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136954);

extern u8 *D_800EC354;
extern u8 D_80138B90[];
typedef struct { s16 x, y; u16 clut, tpage; u32 *ot; s32 scale; } Pen_80137214;
extern Pen_80137214 D_80138CA0_80137214 asm("D_80138CA0");
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80137214;

void func_80137214(u8 *s) {
    PolyFT4_80137214 *p;
    s32 x, y, sc;
    u32 c;
    u8 u, v;

    p = (PolyFT4_80137214 *)D_800EC354;
    x = D_80138CA0_80137214.x;
    y = D_80138CA0_80137214.y;
    sc = D_80138CA0_80137214.scale;
    while ((c = *s) != 0) {
        p->x1 = x + sc;
        p->x3 = x + sc;
        u = (c & 0xF) << 4;
        v = c & 0xF0;
        p->u0 = u;
        p->u2 = u;
        p->v0 = v;
        p->v1 = v;
        u += 15;
        v += 15;
        ((u8 *)p)[3] = 9;
        p->code = 0x2F;
        p->x0 = x;
        p->x2 = x;
        p->y0 = y;
        p->y1 = y;
        p->y2 = y + sc;
        p->y3 = y + sc;
        p->u1 = u;
        p->u3 = u;
        p->v2 = v;
        p->v3 = v;
        p->clut = D_80138CA0_80137214.clut;
        p->tpage = D_80138CA0_80137214.tpage;
        { register u32 *ot asm("$3") = D_80138CA0_80137214.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p++;
        x += (D_80138B90[c] * sc) / 16;
        s++;
    }
    D_80138CA0_80137214.x = x;
    D_800EC354 = (u8 *)p;
}

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

typedef struct { u8 pad0[0x5C]; u16 frame; u16 anim; u8 pad60[0x10]; s16 next; u16 flags; s16 (*anims)[2]; s16 tr[3]; s16 rsteps; s16 tp[3]; s16 psteps; } Mdl_801374D0;
typedef struct { s32 n; struct { s16 a; s16 b; s32 c; } e[1]; } Tbl_801374D0;
typedef struct { u16 x; u16 y; u16 str; s8 type; s8 on; } Txt_801374D0;
extern struct { s16 x, y; u8 pad4[8]; s32 fC; SVECTOR eye; SVECTOR at; s16 *pc; s16 *mark; u8 pad28[8]; Tbl_801374D0 *tbl; s16 eyeT[3]; s16 eyeN; s16 atT[3]; s16 atN; s32 wait; s32 f48; u8 pad4C[0xC]; s32 flags; s32 timer; } D_80138CA0_801374D0 asm("D_80138CA0");
extern Mdl_801374D0 D_80138D00[];
extern Txt_801374D0 D_80138B7C[];
extern u8 D_80138AAC[];
void func_80138468(void);
void func_801373A4(void);
void func_80137214(u8 *s);
void func_80137334(s32 arg0);
void func_801380D8(void);

void func_801374D0(void) {
    s16 *p;
    s32 f;
    s32 t;
    u16 op;
    s32 v;
    s32 n, dx, dy, dz;
    s32 ex, ey, ez;
    Txt_801374D0 *e;
    s32 found;
    s32 k;
    Tbl_801374D0 *tbl;
    s32 cnt;
    struct { s16 a; s16 b; s32 c; } *ent;

    f = D_80138CA0_801374D0.flags;
    p = D_80138CA0_801374D0.pc;
    if (f & 1) {
        found = 0;
        tbl = D_80138CA0_801374D0.tbl;
        t = D_80138CA0_801374D0.timer;
        cnt = tbl->n;
        ent = tbl->e;
        if (t <= 0xFFFE) {
            t++;
        }
        for (k = 0; k < cnt; k++) {
            if (t <= ent[k].b) {
                found = 1;
            }
        }
        D_80138CA0_801374D0.timer = t;
        if (!found) {
            D_80138CA0_801374D0.flags |= 2;
        }
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
                D_80138D00[i].tp[0] = *p;
                p++;
                D_80138D00[i].tp[1] = *p;
                p++;
                D_80138D00[i].tp[2] = *p;
                p++;
                D_80138D00[i].psteps = *p;
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
                D_80138CA0_801374D0.eye.vx = *p;
                p++;
                D_80138CA0_801374D0.eye.vy = *p;
                p++;
                D_80138CA0_801374D0.eye.vz = *p;
                break;
            case 16:
                p++;
                D_80138CA0_801374D0.at.vx = *p;
                p++;
                D_80138CA0_801374D0.at.vy = *p;
                p++;
                D_80138CA0_801374D0.at.vz = *p;
                break;
            case 19:
                p++;
                D_80138CA0_801374D0.eyeT[0] = *p;
                p++;
                D_80138CA0_801374D0.eyeT[1] = *p;
                p++;
                D_80138CA0_801374D0.eyeT[2] = *p;
                p++;
                D_80138CA0_801374D0.eyeN = *p;
                break;
            case 18:
                p++;
                D_80138CA0_801374D0.atT[0] = *p;
                p++;
                D_80138CA0_801374D0.atT[1] = *p;
                p++;
                D_80138CA0_801374D0.atT[2] = *p;
                p++;
                D_80138CA0_801374D0.atN = *p;
                break;
            }
            }
            break;
        case 0x80:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80138D00[i].tr[0] = *p;
                p++;
                D_80138D00[i].tr[1] = *p;
                p++;
                D_80138D00[i].tr[2] = *p;
                p++;
                D_80138D00[i].rsteps = *p;
            }
            }
            break;
        case 0x0:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80138D00[i].flags = *p;
            }
            }
            break;
        case 0x140:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80138D00[i].next = *p;
            }
            }
            break;
        case 0x180:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                v = *p;
                D_80138D00[i].anim = v;
                D_80138D00[i].frame = D_80138D00[i].anims[v][0];
                D_80138D00[i].next = v;
            }
            }
            break;
        case 0x1C0:
            p++;
            D_80138CA0_801374D0.wait = *p;
            break;
        case 0x200:
            if (D_80138CA0_801374D0.wait != 0) {
                D_80138CA0_801374D0.wait--;
                goto done;
            }
            break;
        case 0xC0:
            p++;
            D_80138B7C[*p].on = 1;
            break;
        case 0x100:
            p++;
            D_80138B7C[*p].on = 0;
            break;
        case 0x240:
            D_80138CA0_801374D0.mark = p + 1;
            break;
        case 0x280:
            p = D_80138CA0_801374D0.mark;
            goto done2;
        case 0x2C0:
            p++;
            func_80137D4C(*p);
            p++;
            continue;
        case 0x300:
            D_80138CA0_801374D0.flags = 1;
            break;
        case 0x340:
            if (!(D_80138CA0_801374D0.flags & 2)) {
                D_80138CA0_801374D0.wait--;
                goto done;
            }
            break;
        case 0x3C0:
            func_80138468();
            break;
        }
        p++;
    }
done:
done2:
    D_80138CA0_801374D0.pc = p;
    if (D_80138CA0_801374D0.f48 != 7) {
        func_801373A4();
    }
    n = D_80138CA0_801374D0.eyeN;
    if (n > 0) {
        dx = (D_80138CA0_801374D0.eyeT[0] - D_80138CA0_801374D0.eye.vx) / n;
        dy = (D_80138CA0_801374D0.eyeT[1] - D_80138CA0_801374D0.eye.vy) / n;
        dz = (D_80138CA0_801374D0.eyeT[2] - D_80138CA0_801374D0.eye.vz) / n;
        D_80138CA0_801374D0.eyeN = --n;
        D_80138CA0_801374D0.eye.vx += dx;
        D_80138CA0_801374D0.eye.vy += dy;
        D_80138CA0_801374D0.eye.vz += dz;
    }
    n = D_80138CA0_801374D0.atN;
    if (n > 0) {
        ex = (D_80138CA0_801374D0.atT[0] - D_80138CA0_801374D0.at.vx) / n;
        ey = (D_80138CA0_801374D0.atT[1] - D_80138CA0_801374D0.at.vy) / n;
        ez = (D_80138CA0_801374D0.atT[2] - D_80138CA0_801374D0.at.vz) / n;
        D_80138CA0_801374D0.atN = --n;
        D_80138CA0_801374D0.at.vx += ex;
        D_80138CA0_801374D0.at.vy += ey;
        D_80138CA0_801374D0.at.vz += ez;
    }
    e = D_80138B7C;
    while (e->on >= 0) {
        if ((u8)e->on == 0) {
            e++;
            continue;
        }
        D_80138CA0_801374D0.x = e->x;
        D_80138CA0_801374D0.y = e->y;
        switch (e->type) {
        case 0:
            func_80137214(func_801361D8(D_80138AAC, e->str));
            break;
        case 1:
            func_80137334((s32)func_801361D8(D_80138AAC, e->str));
            break;
        case 2:
            func_801380D8();
            break;
        }
        e++;
    }
}

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

/* 6 diffs (hand) */
s32 Text_GetWidth2(u8 *);

s32 func_801383D8(u8 *s) {
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

void func_80138468(void) {
    Cd_PlayXaTrack(D_80138CEC);
}

typedef struct { s16 x, y, w, h; } Rect_80138490;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; } g_Game_80138490 asm("g_Game");
extern s32 D_80138C90;
extern u32 D_800EC35C;
extern u16 g_RandSeed;
int abs(int);
#define ADD_PRIM_RR_80138490(ot, p) { unsigned int _t1, _t2; __asm__ volatile("lwl %0, 2(%2)\n\tsll %1, %3, 8\n\tswl %1, 2(%2)\n\tswl %0, 2(%3)" : "=&r"(_t1), "=&r"(_t2) : "r"(ot), "r"(p) : "memory"); }

void func_80138490(void) {
    Rect_80138490 r;
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

    p = g_Game_80138490.prim;
    ot = g_Game_80138490.ot;
    k = 0x104 - g_Game_80138490.frame % 300;
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
    n = D_80138C90--;
    if (n > 10) {
        amp = 0;
        w = 4;
    } else {
        amp = 10;
        w = 4;
        if (n <= 0) {
            D_80138C90 = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 200 + 20;
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
                ADD_PRIM_RR_80138490(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (i + ofs);
                r.w = 0x180;
                r.h = one;
                SetDrawMove(p, &r, 0, 0xFE);
                ADD_PRIM_RR_80138490(ot, p);
                p += 0x18;
            }
            if (off > 0) {
                r.x = 0;
                r.y = 0xFE;
                r.w = 0x180 - off;
                r.h = one;
                SetDrawMove(p, &r, off, (i + ofs));
                ADD_PRIM_RR_80138490(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (i + ofs);
                r.w = 0x180;
                r.h = one;
                SetDrawMove(p, &r, 0, 0xFE);
                ADD_PRIM_RR_80138490(ot, p);
                p += 0x18;
            }
        }
    }
    D_800EC354 = p;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
