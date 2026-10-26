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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136208);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136394);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136588);

typedef struct { s16 x, y, w, h; } Rect_8013683C;
extern Rect_8013683C D_8013ADB0;
extern s32 D_8013AE60;
extern s32 D_8013B9E0;
extern s8 D_8013B450[];
extern u8 D_8013AED0[];
extern u8 D_800F4458[];
extern struct { u8 pad0[0x8120]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x1C]; u32 best; u8 pad8148[0x12]; u16 f_815A; } g_Game_8013683C asm("g_Game");
void func_80136A1C(void);
void func_801375B4(void);
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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80136A1C);

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
void func_80138138();
void func_801380DC(void);
void func_80138118(void);
void func_801385B0();
void func_80136000(SVECTOR *eye, SVECTOR *at);
void func_80016F34(void);
void func_801399A4();
s32 Sound_PlayFixed(s32);
void func_80139FB8();
void func_8013A10C();
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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801375B4);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80137C88);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80138138);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801385B0);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801394D0);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_801399A4);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139EE0);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_80139FB8);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A10C);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A334);

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A3C4);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013A8C0);

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

INCLUDE_ASM("asm/ovl/392/nonmatchings/392", func_8013ABD4);
