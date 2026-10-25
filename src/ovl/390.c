#include "common.h"
#include "m2c_macros.h"

M2C_UNK Seq_Tick();
M2C_UNK func_8001300C();
M2C_UNK func_80088578();
M2C_UNK func_80141B34();
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_80139A68();
M2C_UNK func_80139CF0();
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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80136ED8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80137104);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_8013758C);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80138DC0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_801391B0);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139570);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139A68);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139CF0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139F08);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390", func_80139FC8);

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
