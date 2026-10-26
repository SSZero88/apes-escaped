#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern Rect_80136000 D_80136CE0_80136000 asm("D_80136CE0");
extern u8 D_80136CF8[];
extern s16 D_80136CF0;
extern s16 D_80136CF2;
extern s16 D_80136CF4;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; s16 f_8120; u8 pad8122[0x198]; u16 f_82BA; } g_Game_80136000 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136000 asm("g_Pad");
void func_80011194(void *);
s32 func_800116C0();
void Cd_Update(void);
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
void ClearImage();
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_80136A24(void);
M2C_UNK Sound_PlayFixed(M2C_UNK);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_80136000(void) {
    Rect_80136000 r;

    r = D_80136CE0_80136000;
    func_80011194(D_80136CF8);
    while (func_800116C0() >= 0) {
        Cd_Update();
        VSync(2);
    }
    DrawSync(0);
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136000.db[1].env[0x18] = 1;
    g_Game_80136000.db[0].env[0x18] = 1;
    { u8 *e = g_Game_80136000.db[0].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    { u8 *e = g_Game_80136000.db[1].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    g_Game_80136000.cur = 0;
    D_80136CF2 = 0;
    g_Game_80136000.f_82BA |= 2;
    D_80136CF4 = 0x1E;
    for (;;) {
        func_8001325C(2);
        Gfx_BeginFrame();
        if (func_80136A24() < 0) {
            if (D_80136CF0 == 1) {
                break;
            }
            D_80136CF0 = 1;
            D_80136CF2 = 0;
            D_80136CF4 = 0x1E;
        }
        if (D_80136CF2 == 1 && (g_Pad_80136000.f_160 & g_Pad_80136000.f_158 & 0x860)) {
            Sound_PlayFixed(2);
            D_80136CF2 = 2;
            D_80136CF4 = 0;
        }
        func_801362B8();
        DrawSync(0);
        VSync(2);
        g_Game_80136000.frame++;
        PutDispEnv(&g_Game_80136000.db[g_Game_80136000.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136000.db[g_Game_80136000.cur].env);
        DrawOTag(&g_Game_80136000.db[g_Game_80136000.cur].ot[0xFFF]);
    }
    g_Game_80136000.f_8120 = 0xD;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

extern GameDraw g_Game_801362B8 asm("g_Game");
extern u8 *D_800EC354_801362B8 asm("D_800EC354");
extern u8 D_80136D18[12][0x20];
s32 Text_GetWidth2(u8 *);
void func_8008DDB0(s16, s16);
void func_8008DDC8(u8 *);

s32 func_801362B8(void) {
    u8 *p = g_Game_801362B8.prim;
    s32 w;
    s32 x;
    s32 t;
    s32 w0, w1, w2;

    if (D_80136CF0 == 0) {
        func_8008DDB0(0x28, 0x46);
        func_8008DDC8(D_80136D18[0]);
        w0 = Text_GetWidth2(D_80136D18[0]);
        x = w0 + 0x30;
        func_8008DDB0(x, 0x46);
        func_8008DDC8(D_80136D18[1]);
        t = Text_GetWidth2(D_80136D18[1]);
        w0 += 0x38;
        x = w0 + t;
        func_8008DDB0(x, 0x46);
        func_8008DDC8(D_80136D18[2]);
        t = Text_GetWidth2(D_80136D18[2]);
        x += 8 + t;
        func_8008DDB0(x, 0x46);
        func_8008DDC8(D_80136D18[3]);

        func_8008DDB0(0x28, 0x5A);
        func_8008DDC8(D_80136D18[4]);
        w1 = Text_GetWidth2(D_80136D18[4]);
        x = w1 + 0x30;
        func_8008DDB0(x, 0x5A);
        func_8008DDC8(D_80136D18[5]);
        t = Text_GetWidth2(D_80136D18[5]);
        w1 += 0x38;
        x = w1 + t;
        func_8008DDB0(x, 0x5A);
        func_8008DDC8(D_80136D18[6]);
        t = Text_GetWidth2(D_80136D18[6]);
        x += 8 + t;
        func_8008DDB0(x, 0x5A);
        func_8008DDC8(D_80136D18[7]);

        func_8008DDB0(0x28, 0x6E);
        func_8008DDC8(D_80136D18[8]);
        w2 = Text_GetWidth2(D_80136D18[8]);
        x = w2 + 0x30;
        func_8008DDB0(x, 0x6E);
        func_8008DDC8(D_80136D18[9]);
        t = Text_GetWidth2(D_80136D18[9]);
        w2 += 0x38;
        x = w2 + t;
        func_8008DDB0(x, 0x6E);
        func_8008DDC8(D_80136D18[10]);
        t = Text_GetWidth2(D_80136D18[10]);
        x += 0xC + t;
        func_8008DDB0(x, 0x6E);
        func_8008DDC8(D_80136D18[11]);

        p = g_Game_801362B8.prim;
        M2C_FIELD(p, u32 *, 4) = 0x808080;
        p[3] = 4;
        p[7] = 0x64;
        M2C_FIELD(p, s16 *, 0x8) = 0xC0;
        M2C_FIELD(p, s16 *, 0xA) = 0x60;
        M2C_FIELD(p, s16 *, 0x10) = 0xC0;
        M2C_FIELD(p, s16 *, 0x12) = 0x80;
        M2C_FIELD(p, u16 *, 0xE) = 0x3FD8;
        p[0xC] = 0;
        p[0xD] = 0;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 0x14;
        p[3] = 1;
        M2C_FIELD(p, u32 *, 4) = 0xE1000286;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 8;
    } else {
        M2C_FIELD(p, u32 *, 4) = 0x808080;
        p[3] = 4;
        p[7] = 0x64;
        M2C_FIELD(p, s16 *, 0x8) = 0x20;
        M2C_FIELD(p, s16 *, 0xA) = 0;
        M2C_FIELD(p, s16 *, 0x10) = 0xFF;
        M2C_FIELD(p, s16 *, 0x12) = 0xF0;
        M2C_FIELD(p, u16 *, 0xE) = 0x3F98;
        p[0xC] = 0;
        p[0xD] = 0;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 0x14;
        p[3] = 1;
        M2C_FIELD(p, u32 *, 4) = 0xE1000288;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 8;
        M2C_FIELD(p, u32 *, 4) = 0x808080;
        p[3] = 4;
        p[7] = 0x64;
        M2C_FIELD(p, s16 *, 0x8) = 0x11F;
        M2C_FIELD(p, s16 *, 0xA) = 0;
        M2C_FIELD(p, s16 *, 0x10) = 0x40;
        M2C_FIELD(p, s16 *, 0x12) = 0xF0;
        M2C_FIELD(p, u16 *, 0xE) = 0x3F98;
        p[0xC] = 0;
        p[0xD] = 0;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 0x14;
        p[3] = 1;
        M2C_FIELD(p, u32 *, 4) = 0xE100028A;
        { register u32 *ot asm("$3") = g_Game_801362B8.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p += 8;
    }
    D_800EC354_801362B8 = p;
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_8013668C;
extern Rect_8013668C D_80136CE0;
extern u8 D_80136D08[];
extern s16 D_80136CF2;
extern s16 D_80136CF4;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; s16 f_8120; u8 pad8122[0x198]; u16 f_82BA; } g_Game_8013668C asm("g_Game");
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013668C asm("g_Pad");
void func_80011194(void *);
s32 func_800116C0();
void Cd_Update(void);
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
void ClearImage();
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_80136A24(void);
M2C_UNK Sound_PlayFixed(M2C_UNK);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_8013668C(void) {
    Rect_8013668C r;

    r = D_80136CE0;
    func_80011194(D_80136D08);
    while (func_800116C0() >= 0) {
        Cd_Update();
        VSync(2);
    }
    DrawSync(0);
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_8013668C.db[1].env[0x18] = 1;
    g_Game_8013668C.db[0].env[0x18] = 1;
    { u8 *e = g_Game_8013668C.db[0].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    { u8 *e = g_Game_8013668C.db[1].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    g_Game_8013668C.cur = 0;
    D_80136CF2 = 0;
    g_Game_8013668C.f_82BA |= 2;
    D_80136CF4 = 0x1E;
    while (func_8001325C(0), Gfx_BeginFrame(), func_80136A24() >= 0) {
        if (D_80136CF2 == 1 && (g_Pad_8013668C.f_160 & g_Pad_8013668C.f_158 & 0x860)) {
            Sound_PlayFixed(2);
            D_80136CF2 = 2;
            D_80136CF4 = 0;
        }
        func_8013690C();
        DrawSync(0);
        VSync(2);
        g_Game_8013668C.frame++;
        PutDispEnv(&g_Game_8013668C.db[g_Game_8013668C.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013668C.db[g_Game_8013668C.cur].env);
        DrawOTag(&g_Game_8013668C.db[g_Game_8013668C.cur].ot[0xFFF]);
    }
    g_Game_8013668C.f_8120 = 3;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

extern GameDraw g_Game_8013690C asm("g_Game");

s32 func_8013690C(void) {
    u8 *p = g_Game_8013690C.prim;

    M2C_FIELD(p, u32 *, 4) = 0x808080;
    p[3] = 4;
    p[7] = 0x64;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0x10) = 0xFF;
    M2C_FIELD(p, s16 *, 0x12) = 0xF0;
    M2C_FIELD(p, u16 *, 0xE) = 0;
    p[0xC] = 0;
    p[0xD] = 0;
    { register u32 *ot asm("$4") = g_Game_8013690C.ot; ADD_PRIM_R(ot, p, "$5", "$3"); }
    p += 0x14;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000306;
    { register u32 *ot asm("$4") = g_Game_8013690C.ot; ADD_PRIM_R(ot, p, "$5", "$3"); }
    p += 8;
    M2C_FIELD(p, u32 *, 4) = 0x808080;
    p[3] = 4;
    p[7] = 0x64;
    M2C_FIELD(p, s16 *, 0x8) = 0xFF;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0x10) = 0xC0;
    M2C_FIELD(p, s16 *, 0x12) = 0xF0;
    M2C_FIELD(p, u16 *, 0xE) = 0;
    p[0xC] = 0;
    p[0xD] = 0;
    { register u32 *ot asm("$4") = g_Game_8013690C.ot; ADD_PRIM_R(ot, p, "$5", "$3"); }
    p += 0x14;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE100030A;
    { register u32 *ot asm("$4") = g_Game_8013690C.ot; ADD_PRIM_R(ot, p, "$5", "$3"); }
    p += 8;
    g_Game_8013690C.prim = p;
    return 0;
}

extern s16 D_80136CF2;
extern s16 D_80136CF4;

s32 func_80136A24(void) {
    switch (D_80136CF2) {
    case 1:
        return 0;
    case 0:
        func_80136AFC();
        if (--D_80136CF4 < 0) {
            D_80136CF2 = 1;
            D_80136CF4 = 0;
        }
        return 0;
    case 2:
        func_80136AFC();
        if (++D_80136CF4 >= 0x1F) {
            D_80136CF2 = 1;
            D_80136CF4 = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

extern GameDraw g_Game;

s32 func_80136AFC(void) {
    u8 *p = G_DRAW.prim;
    s32 v = D_80136CF4 * 255 / 30;

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

extern u8 *D_800EC354_80136BF4 asm("D_800EC354");
extern u8 D_80136E98[];
void SetDrawTPage(void *, s32, s32, s32);

void func_80136BF4(u8 *str, s32 x, s32 y, s32 clut) {
    u8 *p = G_DRAW.prim;
    u32 *ot = G_DRAW.ot;
    u32 c;

    while ((c = *str) != 0) {
        p[3] = 3;
        p[7] = 0x7D;
        M2C_FIELD(p, s16 *, 0x8) = x;
        M2C_FIELD(p, s16 *, 0xA) = y;
        p[0xC] = (c & 0xF) << 4;
        p[0xD] = c & 0xF0;
        M2C_FIELD(p, u16 *, 0xE) = ((clut + 0x100) << 6) | 0x1B;
        ADD_PRIM_ASM(ot, p);
        p += 0x10;
        str++;
        x += D_80136E98[c];
    }
    SetDrawTPage(p, 0, 1, 0x16);
    ADD_PRIM_ASM2(ot, p);
    p += 8;
    D_800EC354_80136BF4 = p;
}
