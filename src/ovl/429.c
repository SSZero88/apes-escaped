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

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad2; s16 x3, y3; u8 u3, v3; u16 pad3; } PolyFT4_80136554;
extern struct { u32 frame; PolyFT4_80136554 *prim; u32 *ot; } g_Game_80136554 asm("g_Game");
extern PolyFT4_80136554 *D_800EC354_80136554 asm("D_800EC354");

s32 func_80136554(s32 x, s32 y, s32 w, s32 h) {
    PolyFT4_80136554 *p = g_Game_80136554.prim;
    u32 *ot = g_Game_80136554.ot;
    s32 i;
    s32 yy = y;

    for (i = 0; i < 9; i++) {
        ((u8 *)p)[3] = 9;
        p->code = 0x2E;
        p->r0 = 0x40;
        p->g0 = 0x40;
        p->b0 = 0x40;
        switch (i) {
        case 0:
            p->x0 = x; p->y0 = yy; p->x1 = x + 8; p->y1 = yy;
            p->x2 = x; p->y2 = yy + 8; p->x3 = x + 8; p->y3 = yy + 8;
            p->u0 = 0x80; p->v0 = 0xA0; p->u1 = 0x88; p->v1 = 0xA0;
            p->u2 = 0x80; p->v2 = 0xA8; p->u3 = 0x88; p->v3 = 0xA8;
            break;
        case 1:
            p->x0 = x + 8; p->y0 = yy; p->x1 = x + (s16)(w - 8); p->y1 = yy;
            p->x2 = x + 8; p->y2 = yy + 8; p->x3 = x + (s16)(w - 8); p->y3 = yy + 8;
            p->u0 = 0x88; p->v0 = 0xA0; p->u1 = 0x90; p->v1 = 0xA0;
            p->u2 = 0x88; p->v2 = 0xA8; p->u3 = 0x90; p->v3 = 0xA8;
            break;
        case 2:
            p->x0 = x + w - 8; p->y0 = yy; p->x1 = x + w; p->y1 = yy;
            p->x2 = x + w - 8; p->y2 = yy + 8; p->x3 = x + w; p->y3 = yy + 8;
            p->u0 = 0x90; p->v0 = 0xA0; p->u1 = 0x98; p->v1 = 0xA0;
            p->u2 = 0x90; p->v2 = 0xA8; p->u3 = 0x98; p->v3 = 0xA8;
            break;
        case 3:
            p->x0 = x; p->y0 = yy + 8; p->x1 = x + 8; p->y1 = yy + 8;
            p->x2 = x; p->y2 = yy + (s16)(h - 8); p->x3 = x + 8; p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x80; p->v0 = 0xA8; p->u1 = 0x88; p->v1 = 0xA8;
            p->u2 = 0x80; p->v2 = 0xB0; p->u3 = 0x88; p->v3 = 0xB0;
            break;
        case 4:
            p->x0 = x + 8; p->y0 = yy + 8; p->x1 = x + (s16)(w - 8); p->y1 = yy + 8;
            p->x2 = x + 8; p->y2 = yy + (s16)(h - 8); p->x3 = x + (s16)(w - 8); p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x88; p->v0 = 0xA8; p->u1 = 0x90; p->v1 = 0xA8;
            p->u2 = 0x88; p->v2 = 0xB0; p->u3 = 0x90; p->v3 = 0xB0;
            break;
        case 5:
            p->x0 = x + w - 8; p->y0 = yy + 8; p->x1 = x + w; p->y1 = yy + 8;
            p->x2 = x + w - 8; p->y2 = yy + (s16)(h - 8); p->x3 = x + w; p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x90; p->v0 = 0xA8; p->u1 = 0x98; p->v1 = 0xA8;
            p->u2 = 0x90; p->v2 = 0xB0; p->u3 = 0x98; p->v3 = 0xB0;
            break;
        case 6:
            p->x0 = x; p->y0 = yy + h - 8; p->x1 = x + 8; p->y1 = yy + h - 8;
            p->x2 = x; p->y2 = yy + h; p->x3 = x + 8; p->y3 = yy + h;
            p->u0 = 0x80; p->v0 = 0xB0; p->u1 = 0x88; p->v1 = 0xB0;
            p->u2 = 0x80; p->v2 = 0xB8; p->u3 = 0x88; p->v3 = 0xB8;
            break;
        case 7:
            p->x0 = x + 8; p->y0 = yy + h - 8; p->x1 = x + (s16)(w - 8); p->y1 = yy + h - 8;
            p->x2 = x + 8; p->y2 = yy + h; p->x3 = x + (s16)(w - 8); p->y3 = yy + h;
            p->u0 = 0x88; p->v0 = 0xB0; p->u1 = 0x90; p->v1 = 0xB0;
            p->u2 = 0x88; p->v2 = 0xB8; p->u3 = 0x90; p->v3 = 0xB8;
            break;
        case 8:
            p->x0 = x + w - 8; p->y0 = yy + h - 8; p->x1 = x + w; p->y1 = yy + h - 8;
            p->x2 = x + w - 8; p->y2 = yy + h; p->x3 = x + w; p->y3 = yy + h;
            p->u0 = 0x90; p->v0 = 0xB0; p->u1 = 0x98; p->v1 = 0xB0;
            p->u2 = 0x90; p->v2 = 0xB8; p->u3 = 0x98; p->v3 = 0xB8;
            break;
        }
        p->clut = 0x77AB;
        p->tpage = 0x5A;
        ADD_PRIM_ASM(ot, p);
        p++;
        __asm__ volatile("" : : "r"(x), "r"(x));
    }
    D_800EC354_80136554 = p;
    return 0;
}

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

typedef struct { s16 x, y, w, h; } Rect_80136AB8;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; s16 f_8120; u8 pad8122[0x40]; s16 f_8162; } g_Game_80136AB8 asm("g_Game");
extern u8 D_801391C8[];
extern s16 D_801391B6;
extern s16 D_801391BA;
void func_80011194(void *);
s32 func_800116C0();
void Cd_Update(void);
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_80136AB8(void) {
    Rect_80136AB8 r = { 0, 0, 0x180, 0x200 };

    func_80011194(D_801391C8);
    while (func_800116C0() >= 0) {
        Cd_Update();
    }
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136AB8.db[1].env[0x18] = 1;
    g_Game_80136AB8.db[0].env[0x18] = 1;
    { u8 *e = g_Game_80136AB8.db[0].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    { u8 *e = g_Game_80136AB8.db[1].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    g_Game_80136AB8.cur = 0;
    func_80136CC4();
    while (func_8001325C(2), Gfx_BeginFrame(), func_80138AEC() >= 0) {
        if (func_80137470() < 0) {
            D_801391B6 = 2;
        }
        DrawSync(0);
        VSync(0);
        g_Game_80136AB8.frame++;
        PutDispEnv(&g_Game_80136AB8.db[g_Game_80136AB8.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136AB8.db[g_Game_80136AB8.cur].env);
        DrawOTag(&g_Game_80136AB8.db[g_Game_80136AB8.cur].ot[0xFFF]);
    }
    g_Game_80136AB8.f_8162 = D_801391BA;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136AB8.f_8120 = 0x15;
    return 0;
}

extern struct { u8 pad0[0x2CC]; s8 world; s8 stage; } D_800F4350_80136CC4 asm("D_800F4350");
extern struct { u8 pad0[0x1C]; s32 f_1C; u8 pad20[4]; s32 f_24; s32 f_28; s32 f_2C; } D_800EBFA0_80136CC4 asm("D_800EBFA0");
typedef struct { u16 off; u8 type; u8 pad; } Ent_80136CC4;
extern s16 D_801391AA;
extern s16 D_801391AC;
extern s16 D_801391AE;
extern s16 D_801391B0;
extern s16 D_801391B2;
extern s16 D_801391B8;
extern s16 D_801391BC;
extern s16 D_801391BE;
extern s32 D_801391C0;
extern s32 D_801391C4;
extern u8 D_80139200[];
extern u8 D_80139214[];
extern u8 D_80139340[];
extern u8 D_80139468[];
extern u8 D_80139470[];
extern s32 D_80139478;
extern void *D_8013947C;
extern u8 D_800E78C0_80136CC4[] asm("D_800E78C0");
s32 func_80096580(s32);
s32 func_80138ABC(void);
s32 Save_SumStageMonkeys(u8 *);
void func_8008C01C(void);
u8 *func_8008C09C(s32);
void Model_BindMesh(void *, u32 *);
void func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
void Stage_ApplyFog(void);
void func_8004637C(void *);

s32 func_80136CC4(void) {
    s32 i;
    u8 n;
    u8 *p;
    u8 *base = (u8 *)0x80154000;

    D_801391AA = 0;
    if (func_80096580(0x18) > 0) {
        D_801391AA = 1;
    }
    D_801391AC = func_80138ABC();
    D_801391AE = Save_SumStageMonkeys(0);
    func_8013734C(D_801391AE, D_80139468);
    if (D_801391AA != 0) {
        func_8013734C(D_801391AC, D_80139470);
    } else {
        D_80139470[0] = 0x7F;
        D_80139470[1] = 0x7F;
        D_80139470[2] = 0;
    }
    D_801391BC = 1;
    for (i = 1; i < 25; i++) {
        D_80139340[i] = 0;
        if (func_80096580(i) >= 2) {
            D_80139340[i] = 1;
        }
        if (func_80096580(i) > 0) {
            D_801391BC = i;
        }
    }
    D_801391B0 = 0;
    D_801391B2 = 0;
    D_801391BE = 0;
    D_801391BA = 0;
    for (i = 0; D_80139200[i] < 25; i++) {
        if (D_80139214[D_800F4350_80136CC4.stage + D_800F4350_80136CC4.world * 3] == D_80139200[i]) {
            D_801391BA = i;
            break;
        }
    }
    while (D_80139200[D_801391BA] > D_801391BC) {
        D_801391BA--;
    }
    D_801391B6 = 0;
    D_801391B8 = 0x1E;
    func_80136FF0();
    func_8008C01C();
    n = *base;
    D_8013947C = func_8008C09C(n << 5);
    for (i = 1; i <= n; i++) {
        if (((Ent_80136CC4 *)base)[i].type == 2) {
            Model_BindMesh((u8 *)D_8013947C + (i - 1) * 0x20, (u32 *)base + ((Ent_80136CC4 *)base)[i].off);
        }
    }
    func_8002FAF0(0xA4);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_80136CC4.f_24 = 0;
    D_800EBFA0_80136CC4.f_28 = 0x1000;
    D_800EBFA0_80136CC4.f_2C = 0x1000;
    D_800EBFA0_80136CC4.f_1C = 0;
    Stage_ApplyFog();
    func_8004637C(D_800E78C0_80136CC4);
    D_801391C0 = 0;
    D_801391C4 = 0x10;
    D_80139478 = (s32)func_8008C09C(0x4800);
    return 0;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_80136FF0;
typedef struct { u16 id; u8 pad2[0x86]; } Mk_80136FF0;
typedef struct { s16 f_0; u16 f_2; u8 *f_4; } Slot_80136FF0;
extern Slot_80136FF0 D_80139368_80136FF0[] asm("D_80139368");
extern s16 D_801391B4;
s32 World_FirstStage(s32);
u8 *func_800962A4_80136FF0(void) asm("func_800962A4");

s32 func_80136FF0(void) {
    s32 i, j, n, base, k;
    u8 *types;
    u8 *mk;
    Mk_80136FF0 *mks;

    D_801391B0 = 0;
    D_801391B2 = 0;
    D_801391B4 = 0;
    for (i = 0; i < 32; i++) {
        D_80139368_80136FF0[i].f_4 = 0;
        D_80139368_80136FF0[i].f_0 = 0;
        D_80139368_80136FF0[i].f_2 = 0;
    }
    n = ((Ent_80136FF0 *)0x80102400)[D_80139200[D_801391BA]].f_0;
    if (D_80139200[D_801391BA] == 0x18) {
        for (i = 0x19; i < 0x1E; i++) {
            n += ((Ent_80136FF0 *)0x80102400)[i].f_0;
        }
    }
    mks = (Mk_80136FF0 *)0x80158000;
    base = World_FirstStage(D_80139200[D_801391BA]);
    types = func_800962A4_80136FF0();
    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            k = (base + i) * 8 + j;
            mk = (u8 *)(k * 0x88 + (s32)mks);
            if (*(u16 *)mk == 0x7B) {
                break;
            }
            if ((u32)(types[k] - 2) < 2) {
                D_80139368_80136FF0[D_801391B4].f_0 = 1;
            }
            D_80139368_80136FF0[D_801391B4].f_2 = *(u16 *)mk;
            D_80139368_80136FF0[D_801391B4].f_4 = mk;
            if (++D_801391B4 >= 0x19) {
                D_801391B4 = 0x18;
            }
        }
    }
    return 0;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_801371C0;
typedef struct { u16 f_0; u8 pad2[0x86]; } Stage_801371C0;

s32 func_801371C0(s32 base) {
    Ent_801371C0 *ent = (Ent_801371C0 *)0x80102400;
    Stage_801371C0 *st = (Stage_801371C0 *)0x80158000;
    s32 total = 0;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 first;
    s32 c;

    for (i = 0; i < D_801391BA; i++) {
        c = D_80139200[i];
        n = ent[c].f_0;
        if (c == 0x18) {
            for (j = 0x19; j < 0x1E; j++) {
                n += ent[j].f_0;
            }
        }
        first = World_FirstStage(D_80139200[i]);
        for (j = 0; j < n; j++) {
            for (k = 0; k < 8; k++) {
                if (st[(first + j) * 8 + k].f_0 == 0x7B) {
                    break;
                }
                total++;
            }
        }
    }
    return total + base;
}

M2C_UNK Cd_ReadFilePart(M2C_UNK, s32, M2C_UNK, s32);
extern s16 D_801391B6;
extern s32 D_80139478;

s32 func_80137308(void *obj) {
    D_801391B6 = 4;
    Cd_ReadFilePart(0x54, func_801371C0(obj) * 7, 7, D_80139478);
    return 0;
}

extern u8 D_801391E0[];

s32 func_8013734C(s32 n, u8 *out) {
    s32 k;
    s32 m;
    s32 h;
    u8 *tb = D_801391E0;

    m = (s16)n;
    h = m / 100;
    out[0] = tb[(s16)h];
    k = n;
    if (out[0] == 0x6A) {
        out[0] = 0xEF;
    }
    out[1] = tb[(s16)((s16)(m - h * 100) / 10)];
    if (out[0] == 0xEF && out[1] == 0x6A) {
        out[1] = out[0];
    }
    out[2] = D_801391E0[(s16)((s16)k % 10)];
    out[3] = 0;
    return 0;
}

extern s16 D_801391A8;
s32 func_801374DC(void);
s32 func_801378C4(void);

s32 func_80137470(void) {
    switch (D_801391A8) {
    case 0:
        break;
    case 1:
        if (func_801374DC() < 0) {
            return -1;
        }
        break;
    case 2:
        func_801378C4();
        break;
    }
    return 0;
}

int abs(int);
typedef struct { s16 x, y; u8 s[0x20]; } Label_801374DC;
typedef struct { s16 f_0; s16 pad2[3]; } Rec_801374DC;
extern struct { u8 pad0[0x158]; s32 held; s32 pad15C; s32 pressed; s32 pad164; s32 rep; } g_Pad_801374DC asm("g_Pad");
extern s32 D_800E5488;
extern s16 D_801391B4;
extern u8 D_801391EC[];
extern s8 D_80139180[];
extern u8 D_80139100[];
extern u8 D_80138FC8[];
extern u8 D_80138F84[];
extern Rec_801374DC D_80139368[];
void func_80136000(u8 *s, s32 x, s32 y, s32 c);
s32 func_80136120(u8 *s);
s32 func_80137C04(void);
s32 func_80137D40(void);
s32 func_80137EF8(void);
s32 func_80136160(s32, s32, s32, s32);
s32 func_80138978(void);
s32 func_80137308(void *obj);
s32 Sound_PlayFixed(s32);

s32 func_801374DC(void) {
    u8 *a;
    u8 *b;
    Label_801374DC *t;
    s32 pad;
    u8 *q;

    a = func_80136A88(D_80139100, D_801391EC[D_801391BA]);
    b = func_80136A88(D_80138FC8, D_80139180[D_80139200[D_801391BA]]);
    func_80136000(a, 0xC0 - func_80136120(a) / 2, 0x18, 1);
    func_80136000(b, 0xC0 - func_80136120(b) / 2, 0x2A, 0);
    func_80137C04();
    q = D_80138F84;
    t = (Label_801374DC *)(q - 4);
    func_80136000(t->s, t->x, t->y, 0);
    func_80136000(t[1].s, t[1].x, t[1].y, 0);
    func_80137D40();
    func_80137EF8();
    func_80136160(0xC, 0x40, 0x160, 0x90);
    func_80138978();
    if (D_801391B6 != 1) {
        return 0;
    }
    if (D_801391BE != 0) {
        if (D_801391BE > 0) {
            D_801391BE--;
        }
        if (D_801391BE < 0) {
            D_801391BE++;
        }
        if (abs(D_801391BE) == 15) {
            func_80136FF0();
        }
        return 0;
    }
    pad = g_Pad_801374DC.pressed & g_Pad_801374DC.held;
    if (pad & PAD_START) {
        Sound_PlayFixed(1);
        return -1;
    }
    if (pad & PAD_CIRCLE) {
        if (D_80139368[D_801391B0].f_0 == 1) {
            Sound_PlayFixed(3);
            func_80137308((void *)D_801391B0);
            return 0;
        }
        Sound_PlayFixed(0x30);
        return 0;
    }
    if (g_Pad_801374DC.rep == PAD_L1) {
        if (--D_801391BA < 0) {
            D_801391BA = 0;
        } else {
            Sound_PlayFixed(0xB);
            D_801391BE = -30;
        }
    }
    if (D_800E5488 == PAD_R1 && D_801391BE == 0 && D_80139200[D_801391BA + 1] <= D_801391BC) {
        D_801391BA++;
        Sound_PlayFixed(0xB);
        D_801391BE = 30;
    }
    if (D_800E5488 == PAD_LEFT) {
        if (--D_801391B0 < 0) {
            D_801391B0 = 0;
            return 0;
        }
    } else if (D_800E5488 == PAD_UP) {
        s16 old = D_801391B0;
        if ((D_801391B0 -= 8) < 0) {
            D_801391B0 = old;
            return 0;
        }
    } else if (D_800E5488 == PAD_RIGHT) {
        if (++D_801391B0 >= D_801391B4) {
            D_801391B0 = D_801391B4 - 1;
            return 0;
        }
    } else if (D_800E5488 == PAD_DOWN) {
        s16 old = D_801391B0;
        if ((D_801391B0 += 8) >= D_801391B4) {
            D_801391B0 = old;
            return 0;
        }
    } else {
        return 0;
    }
    Sound_PlayFixed(0);
    return 0;
}

typedef struct { s16 f_0; u8 pad2[6]; } Row_801378C4;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_801378C4 asm("g_Pad");
extern Row_801378C4 D_80139368_801378C4[] asm("D_80139368");
void func_80138428();
s32 func_801388A4(void);
s32 func_80136FF0(void);

s32 func_801378C4(void) {
    u8 *a;
    u8 *b;
    s32 i;
    u32 pad;

    a = func_80136A88(D_80139100, D_801391EC[D_801391BA]);
    b = func_80136A88(D_80138FC8, D_80139180[D_80139200[D_801391BA]]);
    func_80136000(a, 0xC0 - func_80136120(a) / 2, 0x18, 1);
    func_80136000(b, 0xC0 - func_80136120(b) / 2, 0x2A, 0);
    func_80137D40();
    func_80138428();
    func_801388A4();
    func_80136160(0xC, 0x40, 0x160, 0xA0);
    func_80138978();
    if (D_801391B6 != 1) {
        return 0;
    }
    pad = g_Pad_801378C4.f_160 & g_Pad_801378C4.f_158;
    if (pad & 0x2000) {
        D_801391B2 = D_801391B4;
        for (i = D_801391B0 + 1; i < D_801391B4; i++) {
            if (D_80139368_801378C4[i].f_0 == 1) {
                D_801391B2 = i;
                break;
            }
        }
        if (D_801391B2 >= D_801391B4) {
            Sound_PlayFixed(0);
            if (D_80139200[D_801391BA + 1] <= D_801391BC) {
                D_801391BA++;
                func_80136FF0();
                D_801391B2 = 0;
                D_801391B0 = 0;
            } else {
                D_801391B0 = D_801391B2 = D_801391B4 - 1;
            }
            D_801391A8 = 1;
        } else {
            Sound_PlayFixed(0);
            func_80137308((void *)(s32)D_801391B2);
        }
    } else if (pad & 0x8000) {
        D_801391B2 = -1;
        for (i = D_801391B0 - 1; i >= 0; i--) {
            if (D_80139368_801378C4[i].f_0 == 1) {
                D_801391B2 = i;
                break;
            }
        }
        if (D_801391B2 < 0) {
            Sound_PlayFixed(0);
            if (--D_801391BA >= 0) {
                func_80136FF0();
                D_801391B0 = D_801391B2 = D_801391B4 - 1;
            } else {
                D_801391BA = 0;
                D_801391B2 = 0;
                D_801391B0 = 0;
            }
            D_801391A8 = 1;
        } else {
            Sound_PlayFixed(0);
            func_80137308((void *)(s32)D_801391B2);
        }
        return 0;
    } else if (pad & 0xFFFF) {
        Sound_PlayFixed(1);
        D_801391A8 = 1;
    }
    return 0;
}

s32 func_80137C04(void) {
    u8 *p = G_DRAW.prim;

    p[3] = 4;
    p[7] = 0x65;
    M2C_FIELD(p, u16 *, 0xE) = 0x7C5D;
    M2C_FIELD(p, s16 *, 0x8) = 0x64;
    M2C_FIELD(p, s16 *, 0xA) = 0xD0;
    M2C_FIELD(p, s16 *, 0x10) = 0x13;
    M2C_FIELD(p, s16 *, 0x12) = 0x11;
    p[0xC] = 0;
    p[0xD] = 0x98;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$4");
    p += 0x14;
    M2C_FIELD(p, u16 *, 0xE) = 0x7C1D;
    M2C_FIELD(p, s16 *, 0x8) = 0xDC;
    p[3] = 4;
    p[7] = 0x65;
    M2C_FIELD(p, s16 *, 0xA) = 0xD0;
    M2C_FIELD(p, s16 *, 0x10) = 0x13;
    M2C_FIELD(p, s16 *, 0x12) = 0x11;
    p[0xC] = 0;
    p[0xD] = 0x80;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$4");
    p += 0x14;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000217;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$4");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

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

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX_801368E8;
extern s32 D_801391C0;
extern s32 D_801391C4;
extern void *D_8013947C;
extern u8 D_800E7D00[];
void func_801368E8(SVECTOR *eye, SVECTOR *at);
void func_8002FAF0(s32);

s32 func_80138978(void) {
    MATRIX_801368E8 m;
    SVECTOR eye;
    SVECTOR at;

    at.vy = 0;
    at.vx = 0;
    at.vz = 0xA40;
    eye.vy = 0;
    eye.vz = 0;
    eye.vx = 0;
    func_801368E8(&eye, &at);
    func_8002FAF0(0xA4);
    func_8004637C(&m);
    RotMatrixZ(D_801391C0 / 8, &m);
    RotMatrixY(D_801391C0 / 8, &m);
    RotMatrixX(D_801391C0 / 8, &m);
    Model_ProjectVertsAlt(D_8013947C, &m, D_800E7D00);
    Model_DrawLit((s32)&G_DRAW.db[G_DRAW.cur].ot[0xFFF], (s32)D_800E7D00, D_8013947C);
    D_801391C4 = func_800463A4(D_801391C4, 0x10, 0x20);
    D_801391C0 += D_801391C4;
    return 0;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_390;

s32 func_80138ABC(void) {
    s32 i;
    s32 s;

    for (i = s = 0; i < 30; i++) {
        s += ((Ent_390 *)0x80102400)[i].f_1;
    }
    return s;
}

extern s16 D_801391B8;
extern s16 D_801391A8;
extern s16 D_801391B0;
extern s16 D_801391B2;
s32 func_80138C44(void);
s32 func_80138D7C(void);
void Cd_WaitIdle_80138AEC(s32) asm("Cd_WaitIdle");

s32 func_80138AEC(void) {
    switch (D_801391B6) {
    case 0:
    case 3:
        func_80138C44();
        if (--D_801391B8 < 0) {
            D_801391B6 = 1;
            D_801391B8 = 0;
        }
        break;
    case 1:
        break;
    case 2:
        func_80138C44();
        if (++D_801391B8 >= 0x1F) {
            D_801391B6 = 1;
            D_801391B8 = 0;
            return -1;
        }
        break;
    case 4:
        Cd_Update();
        func_80138C44();
        if (++D_801391B8 >= 0x10) {
            if (D_801391A8 == 2) {
                D_801391B0 = D_801391B2;
            }
            D_801391A8 = 2;
            Cd_WaitIdle_80138AEC(0);
            func_80138D7C();
            D_801391B6 = 3;
            D_801391B8 = 15;
            return 0;
        }
        break;
    }
    return 0;
}

s32 func_80138C44(void) {
    u8 *p = G_DRAW.prim;
    u8 c;
    s32 tpage = 0x40;

    if (D_801391B6 == 3 || D_801391B6 == 4) {
        c = D_801391B8 * 17;
        p[6] = c;
        p[5] = c;
        p[4] = c;
    } else {
        c = D_801391B8 * 255 / 30;
        p[6] = c;
        p[5] = c;
        p[4] = c;
    }
    p[3] = 3;
    p[7] = 0x62;
    M2C_FIELD(p, s16 *, 0xC) = 0x180;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0xE) = 0xF0;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$4", "$3");
    p += 0x10;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000000 | 0x200 | (tpage & 0x9FF);
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$4", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

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
