#include "common.h"
#include "m2c_macros.h"

M2C_UNK Seq_Tick();
M2C_UNK func_8001300C();
M2C_UNK func_80088578();
M2C_UNK func_80141B34();
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8013FB30(s16);
extern s32 D_800E5488;
extern s16 D_8013AF52;
extern s16 D_8013AF66;
extern s16 D_8013AF6C;
M2C_UNK MemCard_Request(M2C_UNK, M2C_UNK);
extern s16 D_8013AF56;
extern struct S_D_800E3880 { s16 f_0; u8 pad_2[0x4]; s16 f_6; s16 f_8; } D_800E3880;
M2C_UNK func_80136160(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

extern u8 g_Game[];
extern u8 D_8013B024[];

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
        x += D_8013B024[ch];
    }
    G_DRAW.prim = (u8 *)p;
}

s32 func_80136120(u8 *s) {
    s32 w;

    w = 0;
    for (; *s != 0; s++) {
        w += D_8013B024[*s];
    }
    return w;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136160);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136554);

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

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390", D_8013A9CC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136AB8);

void func_80136D58(void) {
    func_8001300C();
    Seq_Tick();
    func_80088578();
    func_80141B34();
}

extern u8 D_800E78C0_80136D90[] asm("D_800E78C0");
extern struct { u8 pad0[0x1C]; s32 f_1C; u8 pad20[4]; s32 f_24; s32 f_28; s32 f_2C; } D_800EBFA0_80136D90 asm("D_800EBFA0");
extern s32 D_8013B214;
extern s32 D_8013AF70;
extern s32 D_8013AF74;
extern s16 D_8013AF6A;
extern s16 D_8013AF68;
void func_8008C01C(void);
u8 *func_8008C09C(s32);
void Model_BindMesh(void *, u32 *);
s32 func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
void Stage_ApplyFog(void);
void func_8004637C(void *);

s32 func_80136D90(void) {
    u8 *h;
    u8 n;
    s32 i;
    u8 *e;
    s32 off;

    h = (u8 *)0x80154000;
    func_8008C01C();
    n = h[0];
    i = 1;
    D_8013B214 = (s32)func_8008C09C(n << 5);
    for (; i <= n; i++) {
        if (h[i * 4 + 2] == 2) {
            Model_BindMesh((void *)(D_8013B214 + (i - 1) * 0x20), (u32 *)(h + *(u16 *)(h + i * 4) * 4));
        }
    }
    func_8002FAF0(0xA4);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_80136D90.f_24 = 0;
    D_800EBFA0_80136D90.f_28 = 0x1000;
    D_800EBFA0_80136D90.f_2C = 0x1000;
    D_800EBFA0_80136D90.f_1C = 0;
    Stage_ApplyFog();
    func_8004637C(D_800E78C0_80136D90);
    D_8013AF70 = 0;
    D_8013AF74 = 0x10;
    D_8013AF6A = -1;
    D_8013AF66 = 0;
    D_8013AF68 = 0x1E;
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_80136ED8;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_80136ED8;
extern Rect_80136ED8 D_8013A9CC;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_80136ED8 asm("g_Game");
void Gfx_InitDisplay(void);
s32 ResetGraph(s32);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_8013A634(void);
s32 func_8013730C(void);
s32 func_80137454_80136ED8(void) asm("func_80137454");
void func_80141B00(void);
void func_80141AB4(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_80136ED8(void) {
    Rect_80136ED8 r;
    s32 res;
    s32 v;

    r = D_8013A9CC;
    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_80136ED8.db[1].env[0x18] = 1;
    g_Game_80136ED8.db[0].env[0x18] = 1;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->r0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->g0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->b0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->r0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->g0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->b0 = 0;
    g_Game_80136ED8.cur = 0;
    func_8013730C();
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        v = func_80137454_80136ED8();
        if (v >= 0) {
            switch (v) {
            case 0:
                res = 0x16;
                break;
            case 1:
                res = 0xE;
                break;
            case 2:
                res = 0x1C;
                break;
            case 3:
                res = 0xD;
                break;
            }
            D_8013AF66 = 2;
        }
        DrawSync(0);
        VSync(2);
        func_80141B00();
        g_Game_80136ED8.frame++;
        PutDispEnv(&g_Game_80136ED8.db[g_Game_80136ED8.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136ED8.db[g_Game_80136ED8.cur].env);
        DrawOTag(&g_Game_80136ED8.db[g_Game_80136ED8.cur].ot[0xFFF]);
    }
    g_Game_80136ED8.f_8120 = res;
    func_80141AB4();
    MemCard_Request(9, 0);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_80137104;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_80137104;
extern Rect_80137104 D_8013A9CC_80137104 asm("D_8013A9CC");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_80137104 asm("g_Game");
s32 func_8014016C(void);
s32 func_80139F08(void);
s32 func_80139A68_80137104() asm("func_80139A68");

s32 func_80137104(void) {
    Rect_80137104 r;
    s32 res;
    s32 v;

    r = D_8013A9CC_80137104;
    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_80137104.db[1].env[0x18] = 1;
    g_Game_80137104.db[0].env[0x18] = 1;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->r0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->g0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->b0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->r0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->g0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->b0 = 0;
    D_8013AF66 = 0;
    D_8013AF68 = 0x1E;
    g_Game_80137104.cur = 0;
    D_8013AF56 = 0x23;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        func_8014016C();
        v = func_80139F08();
        func_80139A3C(4);
        func_80139A68_80137104();
        if (v != 0) {
            if (v == 2) {
                res = 0;
            } else {
                res = 0xE;
            }
            D_8013AF66 = 2;
        }
        DrawSync(0);
        VSync(2);
        g_Game_80137104.frame++;
        PutDispEnv(&g_Game_80137104.db[g_Game_80137104.cur].env[0x5C]);
        PutDrawEnv(g_Game_80137104.db[g_Game_80137104.cur].env);
        DrawOTag(&g_Game_80137104.db[g_Game_80137104.cur].ot[0xFFF]);
    }
    g_Game_80137104.f_8120 = res;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

extern s16 D_8013AF68;
extern s32 D_8013AF78;
extern u8 D_80138370[];
s32 func_80096580(s32);
s32 func_80137424(void);
s32 Save_SumStageMonkeys(s32);
void func_80137C84(s32, u8 *);
u8 *func_8013FC20(void);
void func_80141A10(void *);

s32 func_8013730C(void) {
    u8 a[8];
    u8 b[8];
    s32 has;
    s32 n;
    u8 *p;

    has = func_80096580(0x18) > 0;
    n = func_80137424();
    func_80137C84((s16)Save_SumStageMonkeys(0), a);
    if (has) {
        func_80137C84((s16)n, b);
    } else {
        b[0] = 0x7F;
        b[1] = 0x7F;
        b[2] = 0;
    }
    p = func_8013FC20();
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[4] = b[0];
    p[5] = b[1];
    p[6] = b[2];
    p[7] = 0;
    D_8013AF52 = 1;
    D_8013AF78 = -0x200;
    D_8013AF66 = 0;
    D_8013AF68 = 0x1E;
    D_8013AF6C = 0;
    func_80137DA8(1);
    func_80141A10(D_80138370);
    return 0;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_390;

s32 func_80137424(void) {
    s32 i;
    s32 s;

    for (i = s = 0; i < 30; i++) {
        s += ((Ent_390 *)0x80102400)[i].f_1;
    }
    return s;
}

s16 func_80137454(void) {
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v0_2;

    func_8013FB30(D_8013AF52);
    func_80139CF0();
    func_80139A68();
    if (D_8013AF66 == 1) {
        if (func_8013A43C() != 0) {
            Sound_PlayFixed(1);
            return 3;
        }
        if (func_8013A400() != 0) {
            Sound_PlayFixed(3);
            return D_8013AF52;
        }
        temp_a0 = D_8013AF6C == 0;
        if (D_800E5488 == 0x8000) {
            temp_v0 = (u16) D_8013AF52 - 1;
            D_8013AF52 = temp_v0;
            if (temp_v0 < temp_a0) {
                D_8013AF52 = temp_a0;
            } else {
                Sound_PlayFixed(0);
            }
        }
        if (D_800E5488 == 0x2000) {
            temp_v0_2 = (u16) D_8013AF52 + 1;
            D_8013AF52 = temp_v0_2;
            if (temp_v0_2 >= 3) {
                D_8013AF52 = 2;
            } else {
                Sound_PlayFixed(0);
            }
        }
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}

typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013758C;
extern s16 D_8013AF50;
extern s16 D_8013AF54;
extern s16 D_8013AF60;
extern s16 D_8013AF62;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_8013758C asm("g_Game");
void func_8013829C(void);
s32 func_80137E1C(void);

s32 func_8013758C(s32 from) {
    s32 res;
    s32 v;

    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_8013758C.db[1].env[0x18] = 1;
    g_Game_8013758C.db[0].env[0x18] = 1;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->r0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->g0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->b0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->r0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->g0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->b0 = 0;
    D_8013AF52 = 0;
    D_8013AF50 = 5;
    D_8013AF54 = 0;
    D_8013AF60 = 0;
    g_Game_8013758C.cur = 0;
    D_8013AF62 = 0;
    func_80137DA8(0);
    func_80141A10(func_8013829C);
    D_8013AF66 = 0;
    D_8013AF68 = 0x1E;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        v = func_80137E1C();
        if (v < 0) {
            switch (v) {
            case -4:
                if (from < 0) {
                    res = 3;
                } else if (from == 0x23) {
                    res = 0x23;
                } else {
                    res = 0x15;
                }
                break;
            case -1:
                if (from < 0) {
                    res = 0xD;
                } else if (from == 0x23) {
                    res = 0;
                } else {
                    res = 0x15;
                }
                break;
            case -2:
                res = 3;
                break;
            case -5:
                res = 0;
                break;
            }
            D_8013AF66 = 2;
        }
        DrawSync(0);
        VSync(0);
        func_80141B00();
        g_Game_8013758C.frame++;
        PutDispEnv(&g_Game_8013758C.db[g_Game_8013758C.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013758C.db[g_Game_8013758C.cur].env);
        DrawOTag(&g_Game_8013758C.db[g_Game_8013758C.cur].ot[0xFFF]);
    }
    g_Game_8013758C.f_8120 = res;
    func_80141AB4();
    MemCard_Request(9, 0);
    return 0;
}

s32 func_801377F8(u8 *p, s32 flags) {
    s32 n;
    s32 i;

    for (i = n = 0; i < 0x80; i++, p += 2) {
        if (*p == 0xFF) {
            break;
        }
        n++;
    }
    if (flags & 0x10) {
        n += 5;
    }
    if (flags & 0x1000) {
        n += 5;
    }
    return n;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013784C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137C84);

s32 func_80137DA8(s32 arg0) {
    M2C_UNK var_a0;

    MemCard_Request(8, 0);
    MemCard_Request(7, 0);
    D_800E3880.f_6 = 0;
    D_800E3880.f_8 = 0;
    D_800E3880.f_0 = 1;
    if (arg0 == 0) {
        D_8013AF56 = 0;
        var_a0 = 0;
    } else {
        var_a0 = 0x11;
    }
    MemCard_Request(var_a0, 0);
    return 0;
}

s32 func_80137E4C(void);

s32 func_80137E1C(void) {
    s32 r = func_80137E4C();

    if (r != 0) {
        return r;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137E4C);

/* NOTE: func_8013829C.s also holds a second, never-returning function at 0x80138370 (named func_80138370 here); both verified with wip/_ovl/ag/A/pair.py (each 0 diffs, total 0x144) */
s32 func_801383E0(void);
s32 func_801384BC(void);
s32 func_80138524(void);
s32 func_801385EC(void);
s32 func_801386CC(void);
s32 func_80138744(void);
s32 func_801387FC(void);
s32 func_8013B400(void);

void func_8013829C(void) {
    while (1) {
        switch (D_8013AF56) {
        case 0:
            func_801383E0();
            MemCard_Request(4, 0);
            break;
        case 2:
            func_80138744();
            MemCard_Request(4, 0);
            break;
        case 6:
            func_80138524();
            break;
        case 8:
            func_801385EC();
            break;
        case 17:
            func_8013B400();
            break;
        case 10:
            func_801387FC();
            break;
        case 12:
            func_801386CC();
            break;
        case 1:
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
        case 13:
        case 15:
        case 16:
            func_801384BC();
            MemCard_Request(4, 0);
            break;
        case 3:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
            break;
        }
    }
}

extern s16 D_800E3880_80138370 asm("D_800E3880");
extern s16 D_8013AF6C;

void func_80138370(void) {
    while (1) {
        switch (D_800E3880_80138370) {
        case -8:
        case -7:
        case -5:
        case -4:
        case -2:
        case -1:
        case 0:
            D_8013AF6C = 0;
        case -6:
        case -3:
        case 1:
            break;
        }
        MemCard_Request(0x10, 0);
    }
}

extern s16 D_800E3880_801383E0 asm("D_800E3880");
extern s16 D_800E3884;
extern s16 D_8013AF64;
void func_8013784C(s32, s32);

s32 func_801383E0(void) {
    switch (D_800E3880_801383E0) {
    case 0:
        D_8013AF64 = 0;
        if (D_800E3884 == 0) {
            MemCard_Request(1, 0);
        } else {
            func_8013784C(1, 5);
        }
        break;
    case -5:
    case -4:
        D_8013AF64 = 0;
        func_8013784C(1, 2);
        break;
    case -8:
        D_8013AF64 = 1;
        func_8013784C(1, 2);
        break;
    case -7:
        D_8013AF64 = 0;
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        D_8013AF64 = 0;
        func_8013784C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_801384BC asm("D_800E3880");
void func_8013784C(s32, s32);

s32 func_801384BC(void) {
    switch (D_800E3880_801384BC) {
    case -8:
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_80138524 asm("D_800E3880");
extern s16 D_800E3886;
extern u8 D_800E1A00[];
void func_8001078C(void *);

s32 func_80138524(void) {
    switch (D_800E3880_80138524) {
    case 0:
        func_8013784C(8, 0);
        func_8001078C(D_800E1A00 + D_800E3886 * 0x7A0);
        MemCard_Request(2, 0);
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -8:
        func_8013784C(4, 0);
        break;
    case -4:
        func_8013784C(9, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2B, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern struct { s16 f_0; s16 pad_2; s16 f_4; s16 f_6; } D_800E3880_801385EC asm("D_800E3880");

s32 func_801385EC(void) {
    switch (D_800E3880_801385EC.f_0) {
    case -5:
        MemCard_Request(5, 0);
        break;
    case 0:
        if (D_800E3880_801385EC.f_4 == 5) {
            func_8001078C(D_800E1A00 + D_800E3880_801385EC.f_6 * 0x7A0);
            MemCard_Request(2, 0);
        } else {
            func_8013784C(0xB, 0);
        }
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -8:
        func_8013784C(4, 0);
        break;
    case -4:
        func_8013784C(9, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2B, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_801386CC asm("D_800E3880");

s32 func_801386CC(void) {
    switch (D_800E3880_801386CC) {
    case 0:
        func_8013784C(1, 5);
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2D, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_80138744 asm("D_800E3880");

s32 func_80138744(void) {
    switch (D_800E3880_80138744) {
    case 0:
        D_8013AF64 = 0;
        func_8013784C(1, 5);
        break;
    case -5:
        D_8013AF64 = 0;
        func_8013784C(1, 2);
        MemCard_Request(7, 0);
        break;
    case -8:
        D_8013AF64 = 1;
        func_8013784C(1, 2);
        MemCard_Request(7, 0);
        break;
    case -2:
    case -1:
        D_8013AF64 = 0;
        func_8013784C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801387FC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013888C);

typedef struct { u8 pad0[0xC]; u32 flags; u8 t1[0x10]; u8 t2[0x10]; u8 t3[0x10]; u8 t4[0x10]; u8 pad50[0x28]; } Slot_80138DC0;
typedef struct { u8 t1[0x10]; u8 t2[0x10]; u8 pad20[0x58]; } SlotB_80138DC0;
extern Slot_80138DC0 D_8013B218[];
extern SlotB_80138DC0 D_8013B228[];
extern u8 D_8013B288[];
extern s8 D_8013AF28[];
extern u8 D_8013ADF0[];
extern u8 D_800E1A18[];
extern s16 D_8013AF5E;
s32 func_8013946C(s32 i, s32 x, s32 y);
void func_80136000(u8 *s, s32 x, s32 y, s32 c);
s32 func_80136120(u8 *s);
s32 func_801399E4(s32 n);

s32 func_80138DC0(s32 mode, s32 slot) {
    s32 x;
    s32 y;
    u8 *p;
    s32 w;
    u8 *q;

    if (mode == 0) {
        x = 0x96;
        y = slot * 48 + 0x20;
    } else {
        x = 0x6E;
        y = 0x50;
    }
    if (D_8013AF5E == 1) {
        func_8013946C(0x11, x - 0x24, y);
        func_8013946C(0x10, x - 0x24, y + 0x10);
        ((u8 *)G_DRAW.prim)[3] = 1;
        ((u32 *)G_DRAW.prim)[1] = 0xE1000208;
        __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
        G_DRAW.prim += 8;
        func_80136000(D_8013B228[slot].t1, x + 0x1E, y, 1);
        func_80136000(D_8013B228[slot].t2, x + 0x1E, y + 0x10, 1);
    } else if (D_8013AF5E == 2) {
        func_8013946C(0xF, x - 0x24, y + 0x10);
        func_8013946C(0x12, x + 0x34, y + 0x10);
        if (D_8013B218[slot].flags & 1) {
            func_8013946C(8, x - 0x24, y);
        }
        if (D_8013B218[slot].flags & 2) {
            func_8013946C(7, x - 0x12, y);
        }
        if (D_8013B218[slot].flags & 4) {
            func_8013946C(0xC, x, y);
        }
        if (D_8013B218[slot].flags & 8) {
            func_8013946C(0xB, x + 0x12, y);
        }
        if (D_8013B218[slot].flags & 0x10) {
            func_8013946C(9, x + 0x24, y);
        }
        if (D_8013B218[slot].flags & 0x40) {
            func_8013946C(0xE, x + 0x36, y);
        }
        if (D_8013B218[slot].flags & 0x80) {
            func_8013946C(0xD, x + 0x48, y);
        }
        if (D_8013B218[slot].flags & 0x20) {
            func_8013946C(0xA, x + 0x5A, y);
        }
        ((u8 *)G_DRAW.prim)[3] = 1;
        ((u32 *)G_DRAW.prim)[1] = 0xE1000208;
        __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
        G_DRAW.prim += 8;
        func_80136000(D_8013B218[slot].t3, x + 0x48, y + 0x10, 1);
        func_80136000(D_8013B218[slot].t4, x - 0x10, y + 0x10, 1);
    } else {
        p = func_80136A88(D_8013ADF0, D_8013AF28[func_801399E4(slot)]);
        func_80136000(D_800E1A18 + slot * 0x7A0, x - 0x2E, y, 1);
        func_80136000(p, x - 0x1E, y + 0x10, 0);
        q = D_8013B288 + slot * 0x78;
        w = func_80136120(q) - 0x7E;
        func_80136000(q, x - w, y, 0);
    }
    return 0;
}

/* uses the file's existing 'extern struct S_D_800E3880 {...} D_800E3880;' (checked with it prepended) */
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_801391B0;
typedef struct { u16 clut; u8 u, v; } Tex_801391B0;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_801391B0 asm("g_Pad");
extern Tex_801391B0 D_8013AFAC[];
#define P_801391B0 ((PolyFT4_801391B0 *)G_DRAW.prim)

s32 func_801391B0(void) {
    u32 *ot;

    D_8013AF5E = 0;
    if (g_Pad_801391B0.f_158 & 4) {
        D_8013AF5E = 1;
        if (g_Pad_801391B0.f_160 & g_Pad_801391B0.f_158 & 4) {
            Sound_PlayFixed(4);
        }
    } else if (g_Pad_801391B0.f_158 & 8) {
        D_8013AF5E = 2;
        if (g_Pad_801391B0.f_160 & g_Pad_801391B0.f_158 & 8) {
            Sound_PlayFixed(4);
        }
    }
    func_80138DC0(1, D_800E3880.f_6);
    func_80139570(0x38, 0x48);
    ((u8 *)P_801391B0)[3] = 9;
    P_801391B0->code = 0x2D;
    P_801391B0->clut = D_8013AFAC[D_800E3880.f_6 + 11].clut;
    P_801391B0->tpage = 0x87;
    P_801391B0->x0 = 0xF8;
    P_801391B0->y0 = 0x50;
    P_801391B0->x1 = 0x138;
    P_801391B0->y1 = 0x50;
    P_801391B0->x2 = 0xF8;
    P_801391B0->y2 = 0x70;
    P_801391B0->x3 = 0x138;
    P_801391B0->y3 = 0x70;
    P_801391B0->u0 = D_8013AFAC[D_800E3880.f_6 + 11].u;
    P_801391B0->v0 = D_8013AFAC[D_800E3880.f_6 + 11].v;
    P_801391B0->u1 = D_8013AFAC[D_800E3880.f_6 + 11].u + 0x3F;
    P_801391B0->v1 = D_8013AFAC[D_800E3880.f_6 + 11].v;
    P_801391B0->u2 = D_8013AFAC[D_800E3880.f_6 + 11].u;
    P_801391B0->v2 = D_8013AFAC[D_800E3880.f_6 + 11].v + 0x1F;
    P_801391B0->u3 = D_8013AFAC[D_800E3880.f_6 + 11].u + 0x3F;
    P_801391B0->v3 = D_8013AFAC[D_800E3880.f_6 + 11].v + 0x1F;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)" : : "r"(ot), "m"(G_DRAW.prim) : "$2", "$5", "memory");
    G_DRAW.prim += 0x28;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013946C;
typedef struct { u16 x, y, w, h; u8 u, pad9, v, padB; } Img_8013946C;
extern Img_8013946C D_8013B124[];
#define P_8013946C ((Sprt_8013946C *)G_DRAW.prim)

s32 func_8013946C(s32 i, s32 x, s32 y) {
    u32 *ot;

    ((u8 *)P_8013946C)[3] = 4;
    P_8013946C->code = 0x65;
    P_8013946C->x0 = x;
    P_8013946C->y0 = y;
    P_8013946C->clut = (D_8013B124[i].y << 6) | ((D_8013B124[i].x >> 4) & 0x3F);
    P_8013946C->w = D_8013B124[i].w;
    P_8013946C->h = D_8013B124[i].h;
    P_8013946C->u0 = D_8013B124[i].u;
    P_8013946C->v0 = D_8013B124[i].v;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)\n\tlw $2, %1\n\tnop\n\taddiu $2, $2, 0x14\n\tsw $2, %1" : : "r"(ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139570;
typedef struct { u16 clut; u8 u, v; } Tex_80139570;
#define P_80139570 ((PolyFT4_80139570 *)G_DRAW.prim)
#define ADDPRIM_80139570(R) __asm__ volatile("lwl " R ", 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl " R ", 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", R, "memory")

s32 func_80139570(s32 x, s32 y) {
    s32 i;

    ((u8 *)P_80139570)[3] = 9;
    P_80139570->code = 0x2D;
    P_80139570->clut = D_8013AFAC[0].clut;
    P_80139570->tpage = 8;
    P_80139570->x0 = x;
    P_80139570->y0 = y;
    P_80139570->x1 = x + 8;
    P_80139570->y1 = y;
    P_80139570->x2 = x;
    P_80139570->y2 = y + 0x30;
    P_80139570->x3 = x + 8;
    P_80139570->y3 = y + 0x30;
    P_80139570->u0 = D_8013AFAC[0].u;
    P_80139570->v0 = D_8013AFAC[0].v;
    P_80139570->u1 = D_8013AFAC[0].u + 7;
    P_80139570->v1 = D_8013AFAC[0].v;
    P_80139570->u2 = D_8013AFAC[0].u;
    P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
    P_80139570->u3 = D_8013AFAC[0].u + 7;
    P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
    ADDPRIM_80139570("$6");
    G_DRAW.prim += 0x28;
    for (i = 0; i < 16; i++) {
        ((u8 *)P_80139570)[3] = 9;
        P_80139570->code = 0x2D;
        P_80139570->clut = D_8013AFAC[0].clut;
        P_80139570->tpage = 8;
        P_80139570->x0 = x + 8 + i * 16;
        P_80139570->y0 = y;
        P_80139570->x1 = x + 8 + i * 16 + 16;
        P_80139570->y1 = y;
        P_80139570->x2 = x + 8 + i * 16;
        P_80139570->y2 = y + 0x30;
        P_80139570->x3 = x + 8 + i * 16 + 16;
        P_80139570->y3 = y + 0x30;
        P_80139570->u0 = D_8013AFAC[0].u + 8;
        P_80139570->v0 = D_8013AFAC[0].v;
        P_80139570->u1 = D_8013AFAC[0].u + 0x17;
        P_80139570->v1 = D_8013AFAC[0].v;
        P_80139570->u2 = D_8013AFAC[0].u + 8;
        P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
        P_80139570->u3 = D_8013AFAC[0].u + 0x17;
        P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
        ADDPRIM_80139570("$4");
        G_DRAW.prim += 0x28;
    }
    ((u8 *)P_80139570)[3] = 9;
    P_80139570->code = 0x2D;
    P_80139570->clut = D_8013AFAC[0].clut;
    P_80139570->tpage = 8;
    P_80139570->x0 = x + 0x108;
    P_80139570->y0 = y;
    P_80139570->x1 = x + 0x110;
    P_80139570->y1 = y;
    P_80139570->x2 = x + 0x108;
    P_80139570->y2 = y + 0x30;
    P_80139570->x3 = x + 0x110;
    P_80139570->y3 = y + 0x30;
    P_80139570->u0 = D_8013AFAC[0].u + 0x18;
    P_80139570->v0 = D_8013AFAC[0].v;
    P_80139570->u1 = D_8013AFAC[0].u + 0x1F;
    P_80139570->v1 = D_8013AFAC[0].v;
    P_80139570->u2 = D_8013AFAC[0].u + 0x18;
    P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
    P_80139570->u3 = D_8013AFAC[0].u + 0x1F;
    P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
    __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)\n\tlw $2, %1\n\tnop\n\taddiu $2, $2, 0x28\n\tsw $2, %1" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$5", "memory");
    return 0;
}

extern u8 D_800E1880[];

s32 func_801399E4(s32 n) {
    s32 last;
    s32 i;

    last = 1;
    for (i = 0; i < 25; i++) {
        if (D_800E1880[i + n * 0x7A0 + 0x1A8] != 0) {
            last = i;
        }
    }
    return last;
}

s32 func_80139A3C(void) {
    func_80136160(0xC, 0x14, 0x160, 0xC4);
    return 0;
}

typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80139A68;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; u16 f_8120; } g_Game_80139A68 asm("g_Game");
extern u8 D_800E7D00[];
void func_801368E8(SVECTOR *eye, SVECTOR *at);
void *RotMatrixX(s32 r, void *m);
void *RotMatrixY(s32 r, void *m);
void *RotMatrixZ(s32 r, void *m);
void Model_ProjectVertsAlt(void *, void *, void *);
void Model_DrawLit();
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 func_800463A4(s32, s32, s32);
void func_8013A804();

s32 func_80139A68(void) {
    MAT_80139A68 m;
    SVECTOR eye;
    SVECTOR at;
    SVECTOR pos;
    SVECTOR rot;
    s32 target;
    s32 i;

    at.vy = 0;
    at.vx = 0;
    at.vz = 0xA40;
    eye.vy = 0;
    eye.vz = 0;
    eye.vx = 0;
    func_801368E8(&eye, &at);
    func_8002FAF0(0xA4);
    func_8004637C(&m);
    RotMatrixZ(D_8013AF70 / 8, &m);
    RotMatrixY(D_8013AF70 / 8, &m);
    RotMatrixX(D_8013AF70 / 8, &m);
    Model_ProjectVertsAlt((void *)D_8013B214, &m, D_800E7D00);
    Model_DrawLit(&g_Game_80139A68.db[g_Game_80139A68.cur].ot[0xFFF], D_800E7D00, D_8013B214);
    if (g_Game_80139A68.f_8120 == 0x15) {
        target = -D_8013AF52 << 9;
        if (D_8013AF78 < target - 0x80) {
            D_8013AF78 += 0x80;
        } else if (target + 0x80 < D_8013AF78) {
            D_8013AF78 -= 0x80;
        } else {
            D_8013AF78 = target;
        }
        for (i = 0; i < 3; i++) {
            pos.vx = rsin(D_8013AF78 + i * 0x200) >> 1;
            pos.vy = (rcos(D_8013AF78 + i * 0x200) >> 2) - 0xC8;
            pos.vz = 0xED8 - (rcos(D_8013AF78 + i * 0x200) >> 1);
            rot.vx = 0x80;
            rot.vy = -(u16)g_Game_80139A68.frame * 8;
            rot.vz = 0;
            if (i != 0 || D_8013AF6C != 0) {
                func_8013A804(&pos, &rot, D_8013B214 + (i + 1) * 0x20, 0x1000);
            }
        }
    }
    D_8013AF74 = func_800463A4(D_8013AF74, 0x10, 0x20);
    D_8013AF70 += D_8013AF74;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139CF0;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80139CF0 asm("g_Game");

s32 func_80139CF0(void) {
    PolyFT4_80139CF0 *p;
    u32 *ot;

    p = (PolyFT4_80139CF0 *)g_Game_80139CF0.prim;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->clut = 0x3EE0;
    p->tpage = 8;
    p->x0 = 0x10A;
    p->y0 = 0xA4;
    p->x1 = 0x13A;
    p->y1 = 0xA4;
    p->x2 = 0x10A;
    p->y2 = 0xE4;
    p->x3 = 0x13A;
    p->y3 = 0xE4;
    p->u0 = 0xD0;
    p->v0 = g_Game_80139CF0.frame / 4 % 3 * 64;
    p->u1 = 0xFF;
    p->v1 = g_Game_80139CF0.frame / 4 % 3 * 64;
    p->u2 = 0xD0;
    p->v2 = g_Game_80139CF0.frame / 4 % 3 * 64 + 0x3F;
    p->u3 = 0xFF;
    p->v3 = g_Game_80139CF0.frame / 4 % 3 * 64 + 0x3F;
    ot = g_Game_80139CF0.db[g_Game_80139CF0.cur].ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    p->clut = 0x3EDF;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->tpage = 8;
    p->x0 = 0x10A;
    p->y0 = 0xA4;
    p->x1 = 0x15A;
    p->y1 = 0xA4;
    p->x2 = 0x10A;
    p->y2 = 0xE4;
    p->x3 = 0x15A;
    p->y3 = 0xE4;
    p->u0 = 0;
    p->v0 = 0x80;
    p->u1 = 0x50;
    p->v1 = 0x80;
    p->u2 = 0;
    p->v2 = 0xBF;
    p->u3 = 0x50;
    p->v3 = 0xBF;
    ot = g_Game_80139CF0.db[g_Game_80139CF0.cur].ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    g_Game_80139CF0.prim = (u8 *)p;
    return 0;
}

extern struct { u8 pad_0[0x168]; s32 f_168; } g_Pad_80139F08 asm("g_Pad");
extern s16 D_8013AF5A;
void func_8013FFEC(s32);
s32 func_8013A400(void);

s32 func_80139F08(void) {
    func_8013FFEC(D_8013AF5A);
    if (D_8013AF66 != 1) {
        return 0;
    }
    if (g_Pad_80139F08.f_168 == 0x1000) {
        Sound_PlayFixed(0);
        D_8013AF5A = D_8013AF5A == 0;
    }
    if (g_Pad_80139F08.f_168 == 0x4000) {
        Sound_PlayFixed(0);
        D_8013AF5A = D_8013AF5A == 0;
    }
    if (func_8013A400() != 0) {
        Sound_PlayFixed(3);
        return D_8013AF5A + 1;
    }
    return 0;
}

typedef struct { u8 pad0[0x180]; s16 f_180; u8 pad182[0x7A0 - 0x182]; } Slot_80139FC8;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80139FC8 asm("g_Pad");
extern struct { s16 f_0; u8 pad_2[0x4]; s16 f_6; } D_800E3880_80139FC8 asm("D_800E3880");
extern s16 D_8013AFE8[];
extern Slot_80139FC8 D_800E1880_80139FC8[] asm("D_800E1880");
s32 func_8013A400(void);
s32 func_8013A43C(void);

s32 func_80139FC8(void) {
    s32 a;

    if (D_8013AF66 != 1) {
        return 0;
    }
    D_8013AF5E = 0;
    if (g_Pad_80139FC8.f_158 & 4) {
        D_8013AF5E = 1;
        if (g_Pad_80139FC8.f_160 & g_Pad_80139FC8.f_158 & 4) {
            Sound_PlayFixed(0xB);
        }
    } else if (g_Pad_80139FC8.f_158 & 8) {
        D_8013AF5E = 2;
        if (g_Pad_80139FC8.f_160 & g_Pad_80139FC8.f_158 & 8) {
            Sound_PlayFixed(0xB);
        }
    }
    if (D_8013AF54 == 0) {
        if (D_800E5488 == 0x1000) {
            Sound_PlayFixed(0);
            do {
                if (--D_8013AF52 < 0) {
                    D_8013AF52 = 4;
                }
            } while (D_8013AFE8[D_8013AF52] != 1);
        } else if (D_800E5488 == 0x4000) {
            Sound_PlayFixed(0);
            do {
                if (++D_8013AF52 >= 5) {
                    D_8013AF52 = 0;
                }
            } while (D_8013AFE8[D_8013AF52] != 1);
        }
        if (D_8013AF52 == 0) {
            if (func_8013A400()) {
                Sound_PlayFixed(3);
                return -4;
            }
            return 0;
        }
        if (D_8013AF52 < 0) {
            return 0;
        }
        if (D_8013AF52 >= 5) {
            return 0;
        }
        if (func_8013A400()) {
            D_8013AF54 = 1;
            D_800E3886 = 0;
            Sound_PlayFixed(3);
        }
        return 0;
    }
    if (func_8013A43C()) {
        D_8013AF54 = 0;
        Sound_PlayFixed(1);
        return 0;
    }
    if (func_8013A400()) {
        if (D_8013AF52 == 1) {
            Sound_PlayFixed(3);
            if (D_800E1880_80139FC8[D_800E3886].f_180 >= 0) {
                a = 0xD;
            } else if (D_8013AF64 != 0) {
                a = 4;
            } else {
                MemCard_Request(0, 0);
                a = 6;
            }
        } else if (D_8013AF52 == 2) {
            if (D_800E1880_80139FC8[D_800E3886].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 5;
        } else if (D_8013AF52 == 3) {
            if (D_800E1880_80139FC8[D_800E3886].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 0xF;
        } else if (D_8013AF52 == 4) {
            if (D_800E1880_80139FC8[D_800E3886].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 7;
        } else {
            return 0;
        }
        func_8013784C(a, 0);
        return 0;
bad:
        Sound_PlayFixed(0x30);
        return 0;
    }
    if (D_800E5488 == 0x1000) {
        Sound_PlayFixed(0);
        if (--D_800E3880_80139FC8.f_6 < 0) {
            D_800E3880_80139FC8.f_6 = 3;
        }
    } else if (D_800E5488 == 0x4000) {
        Sound_PlayFixed(0);
        if (++D_800E3880_80139FC8.f_6 >= 4) {
            D_800E3880_80139FC8.f_6 = 0;
        }
    }
    return 0;
}

extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013A400 asm("g_Pad");

s32 func_8013A400(void) {
    if (D_8013AF66 != 1) {
        return 0;
    }
    return (g_Pad_8013A400.f_160 & g_Pad_8013A400.f_158 & 0x60) != 0;
}

extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013A43C asm("g_Pad");

s32 func_8013A43C(void) {
    if (D_8013AF66 != 1) {
        return 0;
    }
    return (g_Pad_8013A43C.f_160 & g_Pad_8013A43C.f_158 & 0x90) != 0;
}

typedef struct { s16 x, y, w, h; } Rect_8013A478;
typedef struct { Rect_8013A478 r[4]; } Rects_8013A478;
typedef struct { u32 id; u32 flag; u8 pad8[0xA18]; } Tim_8013A478;
extern Rects_8013A478 D_8013ADA8;
extern u8 D_8013AFF4[];
extern u8 D_8013ADC8[];
s32 func_801399E4(s32 n);
void LoadImage2(void *rect, void *p);
void bios_printf(u8 *, ...);

s32 func_8013A478(s16 n) {
    Rects_8013A478 rects;
    Rect_8013A478 clut;
    u32 *p;

    rects = D_8013ADA8;
    p = (u32 *)&((Tim_8013A478 *)0x80170000)[D_8013AFF4[func_801399E4(n)]];
    clut.x = 0x1C0;
    clut.y = n + 0xFC;
    clut.w = 0x100;
    clut.h = 1;
    if (*p == 0x10) {
        p++;
        switch (*p & 0xF) {
        case 2:
            LoadImage2(&rects.r[n], (u8 *)p + 0x10);
            break;
        case 8:
        case 9:
            p++;
            LoadImage2(&clut, (u8 *)p + 0xC);
            p = (u32 *)((u8 *)p + ((*p >> 2) << 2));
            LoadImage2(&rects.r[n], (u8 *)p + 0xC);
            break;
        default:
            bios_printf(D_8013ADC8, *p);
            break;
        }
    }
    return 0;
}

extern s16 D_8013AF68;

s32 func_8013A634(void) {
    switch (D_8013AF66) {
    case 1:
        return 0;
    case 0:
        func_8013A70C();
        if (--D_8013AF68 < 0) {
            D_8013AF66 = 1;
            D_8013AF68 = 0;
        }
        return 0;
    case 2:
        func_8013A70C();
        if (++D_8013AF68 >= 0x1F) {
            D_8013AF66 = 1;
            D_8013AF68 = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

s32 func_8013A70C(void) {
    u8 *p = G_DRAW.prim;
    s32 v = D_8013AF68 * 255 / 30;

    p[3] = 3;
    p[7] = 0x62;
    M2C_FIELD(p, s16 *, 0xC) = 0x180;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0xE) = 0xF0;
    p[4] = p[5] = p[6] = v;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 0x10;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000240;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013A804);
