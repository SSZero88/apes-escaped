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
void func_8013734C(s16, u8 *);
void func_80136FF0(void);
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

extern s16 D_801391A8;
s32 func_801374DC(void);
void func_801378C4(void);

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

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801374DC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801378C4);

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
