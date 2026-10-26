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

typedef struct { s16 x, y, w, h; } Rect_80136208;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; u8 pad8122[2]; u16 f_8124; u16 f_8126; u8 pad8128[0x32]; u16 f_815A; u8 pad815C[0x170]; u8 f_82CC; u8 f_82CD; } g_Game_80136208 asm("g_Game");
extern struct { u8 pad0[6]; s16 f6; u32 *f8; s32 fC; SVECTOR eye; SVECTOR at; u8 pad20[8]; s16 sub; s16 pad2A; s16 buf; u8 pad2E[0x2A]; s32 f58; } D_80139B20_80136208 asm("D_80139B20");
extern struct { u8 pad0[0x24]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_80136208 asm("D_800EBFA0");
extern s16 D_80139B24;
extern s16 D_80139540;
extern s16 D_80139542;
extern u8 D_80139544[];
extern u8 D_80139564[];
extern u8 D_80139584[];
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
void func_8008C01C(void);
s32 func_80011194(void *);
void func_80138F38(void);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_801368FC(void);
void func_80137CA8(void);
void Cd_Update(void);
s32 func_8001231C(void);
s32 Sound_UnloadBanks(s32);
s32 func_800964B0(s32);
s32 func_80096568(s32);

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
    func_8008C01C();
    DrawSync(0);
    D_80139B24 = 0x3FDF;
    switch (g_Game_80136208.f_8126) {
    case 0x13:
    case 0x24:
        func_80011194(D_80139584);
        D_80139B24 = 0x1B;
        break;
    case 0xFF:
        func_80011194(D_80139564);
        break;
    default:
        func_80011194(D_80139544);
        break;
    }
    g_Game_80136208.cur = 0;
    func_80138F38();
    D_80139540 = 0;
    D_80139B20_80136208.f6 = 0x26;
    D_80139B20_80136208.fC = 0x20;
    D_80139B20_80136208.eye.vz = -0x1000;
    D_80139B20_80136208.eye.vx = 0;
    D_80139B20_80136208.eye.vy = 0;
    D_80139B20_80136208.at.vx = 0;
    D_80139B20_80136208.at.vy = 0;
    D_80139B20_80136208.at.vz = 0;
    D_80139B20_80136208.f58 = 0;
    g_Game_80136208.db[1].env[0x18] = 1;
    g_Game_80136208.db[0].env[0x18] = 1;
    g_Game_80136208.db[1].env[0x19] = 0;
    g_Game_80136208.db[0].env[0x19] = 0;
    g_Game_80136208.db[1].env[0x1A] = 0;
    g_Game_80136208.db[0].env[0x1A] = 0;
    g_Game_80136208.db[1].env[0x1B] = 0;
    g_Game_80136208.db[0].env[0x1B] = 0;
    func_80138B0C();
    do {
        func_8001325C(0);
        g_Game_80136208.frame++;
        Gfx_BeginFrame();
        D_80139B20_80136208.f8 = g_Game_80136208.db[g_Game_80136208.cur].hud;
        if (func_801368FC() < 0) {
            break;
        }
        DrawSync(0);
        VSync(2);
        switch (D_80139540) {
        case 1:
            s = D_80139B20_80136208.sub;
            if (s == 0) {
                func_80137CA8();
                PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
                D_80139B20_80136208.sub = 1;
                D_80139B20_80136208.buf = g_Game_80136208.cur;
            } else if (s == 1) {
                g_Game_80136208.db[1].env[0x18] = 0;
                g_Game_80136208.db[0].env[0x18] = 0;
                PutDispEnv(&g_Game_80136208.db[D_80139B20_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80139B20_80136208.buf ^ 1)].env);
            } else if (s == 2) {
                PutDispEnv(&g_Game_80136208.db[D_80139B20_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80139B20_80136208.buf ^ 1)].env);
                g_Game_80136208.db[1].env[0x18] = 1;
                g_Game_80136208.db[0].env[0x18] = 1;
                D_80139540 = s;
            }
            break;
        case 3:
            if (D_80139B20_80136208.sub == 0) {
                PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
                g_Game_80136208.db[1].env[0x18] = 0;
                g_Game_80136208.db[0].env[0x18] = 0;
                D_80139B20_80136208.sub = 1;
                D_80139B20_80136208.buf = g_Game_80136208.cur;
            } else if (D_80139B20_80136208.sub == 1) {
                PutDispEnv(&g_Game_80136208.db[D_80139B20_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80139B20_80136208.buf ^ 1)].env);
            } else if (D_80139B20_80136208.sub == 2) {
                PutDispEnv(&g_Game_80136208.db[D_80139B20_80136208.buf].env[0x5C]);
                PutDrawEnv(g_Game_80136208.db[(s16)(D_80139B20_80136208.buf ^ 1)].env);
                D_80139540 = 4;
            }
            break;
        default:
            PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
            PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
            break;
        }
        DrawOTag(&g_Game_80136208.db[g_Game_80136208.cur].ot[0xFFF]);
        Cd_Update();
    } while (D_80139540 != 4);
    DrawSync(0);
    VSync(0);
    func_8001231C();
    Sound_UnloadBanks(1);
    if (D_80139542 != 0) {
        g_Game_80136208.f_8126 = 0xFF;
        return 0;
    }
    if (g_Game_80136208.mode == 0x14) {
        g_Game_80136208.mode = 9;
        return 0;
    }
    g_Game_80136208.mode = 0xD;
    if (g_Game_80136208.f_8126 == 0xFF) {
        return 0;
    }
    switch (g_Game_80136208.f_8124) {
    case 6:
        if (func_800964B0(0x13) & 1) {
            return 0;
        }
        g_Game_80136208.f_8126 = 0x13;
        g_Game_80136208.mode = 0x17;
        g_Game_80136208.f_82CC = 2;
        g_Game_80136208.f_82CD = 0;
        break;
    case 13:
        if (func_800964B0(0x24) & 1) {
            return 0;
        }
        g_Game_80136208.f_8126 = 0x24;
        g_Game_80136208.mode = 0x17;
        g_Game_80136208.f_82CC = 5;
        g_Game_80136208.f_82CD = 0;
        break;
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
        if (func_80096568(4) != 0) {
            return 0;
        }
        g_Game_80136208.mode = 0x1A;
        g_Game_80136208.f_815A = 4;
        break;
    case 17:
        if (func_80096568(1) != 0) {
            return 0;
        }
        g_Game_80136208.mode = 0x1A;
        g_Game_80136208.f_815A = 1;
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_801368FC);

extern u8 *D_800EC354;
extern u8 D_801399B0[];
typedef struct { s16 x, y; u16 clut, tpage; u32 *ot; s32 scale; } Pen_801372D0;
extern Pen_801372D0 D_80139B20_801372D0 asm("D_80139B20");
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_801372D0;

void func_801372D0(u8 *s) {
    PolyFT4_801372D0 *p;
    s32 x, y, sc;
    u32 c;
    u8 u, v;

    p = (PolyFT4_801372D0 *)D_800EC354;
    x = D_80139B20_801372D0.x;
    y = D_80139B20_801372D0.y;
    sc = D_80139B20_801372D0.scale;
    while ((c = *s) != 0) {
        p->x1 = x + sc - 1;
        p->x3 = x + sc - 1;
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
        p->y2 = y + sc - 1;
        p->y3 = y + sc - 1;
        p->u1 = u;
        p->u3 = u;
        p->v2 = v;
        p->v3 = v;
        p->clut = D_80139B20_801372D0.clut;
        p->tpage = D_80139B20_801372D0.tpage;
        { register u32 *ot asm("$3") = D_80139B20_801372D0.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p++;
        x += (D_801399B0[c] * sc) / 16;
        s++;
    }
    D_80139B20_801372D0.x = x;
    D_800EC354 = (u8 *)p;
}

void func_801373F8(s32 arg0) {
    func_8008DDB0(M2C_FIELD(&D_80139B20, s16 *, 0), M2C_FIELD(&D_80139B20, s16 *, 2));
    func_8008DDC8(arg0);
}

INCLUDE_ASM("asm/ovl/391/nonmatchings/391", func_80137438);

typedef struct { u8 pad0[0x5C]; u16 frame; u16 anim; u8 pad60[0x10]; s16 next; u16 flags; s16 (*anims)[2]; s16 tr[3]; s16 rsteps; s16 tp[3]; s16 psteps; } Mdl_801374C8;
typedef struct { u16 x; u16 y; u16 str; s8 type; s8 on; } Txt_801374C8;
extern struct { s16 x, y; u8 pad4[8]; s32 fC; SVECTOR eye; SVECTOR at; s16 *pc; s16 *mark; u8 pad28[0xC]; s16 eyeT[3]; s16 eyeN; s16 atT[3]; s16 atN; s32 wait; u8 pad48[8]; u16 f50; u8 pad52[6]; s32 flags; s32 timer; } D_80139B20_801374C8 asm("D_80139B20");
extern Mdl_801374C8 D_80139B80[];
extern Txt_801374C8 D_8013995C[];
extern u8 D_80139930[];
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; } g_Game_801374C8 asm("g_Game");
void func_80138660(void);
void func_801373F8(s32 arg0);
void func_801372D0(u8 *s);
void func_80137DC4(void);
void func_8013836C(void);
void func_8013939C(void);
void func_801384A0(void);

void func_801374C8(void) {
    s16 *p;
    s32 f;
    s32 t;
    u16 op;
    s32 v;
    s32 n, dx, dy, dz;
    s32 ex, ey, ez;
    Txt_801374C8 *e;

    f = D_80139B20_801374C8.flags;
    p = D_80139B20_801374C8.pc;
    if (f & 1) {
        t = D_80139B20_801374C8.timer;
        if (t <= 0xFFFE) {
            t++;
        }
        D_80139B20_801374C8.timer = t;
        D_80139B20_801374C8.flags = f | 2;
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
                D_80139B80[i].tp[0] = *p;
                p++;
                D_80139B80[i].tp[1] = *p;
                p++;
                D_80139B80[i].tp[2] = *p;
                p++;
                D_80139B80[i].psteps = *p;
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
                D_80139B20_801374C8.eye.vx = *p;
                p++;
                D_80139B20_801374C8.eye.vy = *p;
                p++;
                D_80139B20_801374C8.eye.vz = *p;
                break;
            case 16:
                p++;
                D_80139B20_801374C8.at.vx = *p;
                p++;
                D_80139B20_801374C8.at.vy = *p;
                p++;
                D_80139B20_801374C8.at.vz = *p;
                break;
            case 19:
                p++;
                D_80139B20_801374C8.eyeT[0] = *p;
                p++;
                D_80139B20_801374C8.eyeT[1] = *p;
                p++;
                D_80139B20_801374C8.eyeT[2] = *p;
                p++;
                D_80139B20_801374C8.eyeN = *p;
                break;
            case 18:
                p++;
                D_80139B20_801374C8.atT[0] = *p;
                p++;
                D_80139B20_801374C8.atT[1] = *p;
                p++;
                D_80139B20_801374C8.atT[2] = *p;
                p++;
                D_80139B20_801374C8.atN = *p;
                break;
            }
            }
            break;
        case 0x80:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80139B80[i].tr[0] = *p;
                p++;
                D_80139B80[i].tr[1] = *p;
                p++;
                D_80139B80[i].tr[2] = *p;
                p++;
                D_80139B80[i].rsteps = *p;
            }
            }
            break;
        case 0x0:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80139B80[i].flags = *p;
            }
            }
            break;
        case 0x140:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                D_80139B80[i].next = *p;
            }
            }
            break;
        case 0x400:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                D_80139B80[i].next = D_80139B20_801374C8.f50;
            }
            }
            break;
        case 0x180:
            {
            s32 i = op & 0x3F;
            if (i < 5) if (i >= 0) {
                p++;
                v = *p;
                D_80139B80[i].anim = v;
                D_80139B80[i].frame = D_80139B80[i].anims[v][0];
                D_80139B80[i].next = v;
            }
            }
            break;
        case 0x1C0:
            p++;
            D_80139B20_801374C8.wait = *p;
            break;
        case 0x200:
            if (D_80139B20_801374C8.wait != 0) {
                D_80139B20_801374C8.wait--;
                goto done;
            }
            break;
        case 0x380:
            if ((u32)D_80139B20_801374C8.timer < (u32)p[1]) {
                goto done2;
            }
            p++;
            break;
        case 0xC0:
            p++;
            D_8013995C[*p].on = 1;
            break;
        case 0x240:
            D_80139B20_801374C8.mark = p + 1;
            break;
        case 0x280:
            p = D_80139B20_801374C8.mark;
            goto done2;
        case 0x2C0:
            p++;
            func_80137D20(*p);
            p++;
            continue;
        case 0x3C0:
            func_80138660();
            p++;
            continue;
        case 0x300:
            D_80139B20_801374C8.flags = 1;
            break;
        }
        p++;
    }
done:
done2:
    D_80139B20_801374C8.pc = p;
    n = D_80139B20_801374C8.eyeN;
    if (n > 0) {
        dx = (D_80139B20_801374C8.eyeT[0] - D_80139B20_801374C8.eye.vx) / n;
        dy = (D_80139B20_801374C8.eyeT[1] - D_80139B20_801374C8.eye.vy) / n;
        dz = (D_80139B20_801374C8.eyeT[2] - D_80139B20_801374C8.eye.vz) / n;
        D_80139B20_801374C8.eyeN = --n;
        D_80139B20_801374C8.eye.vx += dx;
        D_80139B20_801374C8.eye.vy += dy;
        D_80139B20_801374C8.eye.vz += dz;
    }
    n = D_80139B20_801374C8.atN;
    if (n > 0) {
        ex = (D_80139B20_801374C8.atT[0] - D_80139B20_801374C8.at.vx) / n;
        ey = (D_80139B20_801374C8.atT[1] - D_80139B20_801374C8.at.vy) / n;
        ez = (D_80139B20_801374C8.atT[2] - D_80139B20_801374C8.at.vz) / n;
        D_80139B20_801374C8.atN = --n;
        D_80139B20_801374C8.at.vx += ex;
        D_80139B20_801374C8.at.vy += ey;
        D_80139B20_801374C8.at.vz += ez;
    }
    for (e = D_8013995C; e->on >= 0; e++) {
        if ((u8)e->on == 0) {
            continue;
        }
        D_80139B20_801374C8.x = e->x;
        D_80139B20_801374C8.y = e->y;
        switch (e->type) {
        case 0:
            D_80139B20_801374C8.fC = 0x20;
            func_801372D0(func_801361D8(D_80139930, e->str));
            break;
        case 1:
            func_801373F8((s32)func_801361D8(D_80139930, e->str));
            break;
        case 2:
            func_80137DC4();
            break;
        case 3:
            func_8013836C();
            break;
        case 4:
            D_80139B20_801374C8.fC = 0x10;
            func_801372D0(func_801361D8(D_80139930, e->str));
            break;
        case 5:
            if (g_Game_801374C8.mode == 0x19) {
                func_8013939C();
            } else {
                func_801384A0();
            }
            break;
        }
    }
}

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
