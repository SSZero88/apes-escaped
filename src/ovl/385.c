#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern Rect_80136000 D_80136910_80136000 asm("D_80136910");
extern u8 D_80136920_80136000[] asm("D_80136920");
extern u8 D_800E52D0[2][0x22];
extern struct { u8 pad0[0x10]; DrawBuf db[2]; u8 pad8100[0x20]; s16 mode; u8 pad8122[0x38]; s16 f_815A; s16 f_815C; u8 pad815E[6]; s16 f_8164; } g_Game_80136000 asm("g_Game");
extern GameDraw g_Draw_80136000 asm("g_Game");
s32 VSync(s32 mode);
s32 func_80011194(void *);
s32 func_800116C0(void);
void Cd_Update(void);
void SetDispMask(s32 mask);
s32 ResetGraph(s32 mode);
s32 SetGraphDebug(s32 level);
s32 ClearImage2(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 func_80136424(void);
s32 Sound_ResumeStreams(void);
s32 func_801362A4(void);
s32 func_80136528(void);
s32 func_801366EC(void);
s32 Sound_UnloadBanks(s32);
s32 Gfx_InitDisplay(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
s32 Cd_StartFileLoad(s32, s32);

s32 func_80136000(void) {
    Rect_80136000 r = D_80136910_80136000;
    s32 t;

    VSync(0);
    t = VSync(-1);
    func_80011194(D_80136920_80136000);
    while (func_800116C0() == 0) {
        Cd_Update();
        VSync(2);
    }
    while (VSync(-1) - t < 0xF0) {
        VSync(0);
    }
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    SetGraphDebug(0);
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage(&r, 0, 0, 0);
    r.x = 0;
    r.y = 0x100;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    g_Game_80136000.f_8164 = 0;
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x200;
    func_80136424();
    Sound_ResumeStreams();
    if (func_801362A4() < 0) {
        return 0;
    }
    if (func_80136528() < 0) {
        return 0;
    }
    if (D_800E52D0[0][0] != 0 || (D_800E52D0[0][1] >> 4) != 7) {
        if (func_801366EC() < 0) {
            return 0;
        }
    }
    Sound_UnloadBanks(1);
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    Gfx_InitDisplay();
    PutDispEnv(&g_Draw_80136000.db[g_Draw_80136000.cur].env[0x5C]);
    PutDrawEnv(&g_Draw_80136000.db[g_Draw_80136000.cur]);
    Cd_StartFileLoad(0, 0xC);
    while (func_800116C0() == 0) {
        Cd_Update();
        VSync(2);
    }
    g_Game_80136000.mode = 0x1A;
    g_Game_80136000.f_815A = 2;
    g_Game_80136000.f_815C = 4;
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_801362A4;
extern struct { u8 pad0[0x20]; s32 f_20; } D_800E3890;
extern GameDraw g_Game_801362A4 asm("g_Game");
s32 ClearImage2(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
s32 Cd_StartFileLoad(s32, s32);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_800116C0(void);
void Cd_Update(void);

s32 func_801362A4(void) {
    Rect_801362A4 r;
    s32 loading;
    s32 t;

    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    r.x = 0;
    r.y = 0x100;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    Cd_StartFileLoad(0, 0);
    g_Game_801362A4.cur = 1;
    g_Game_801362A4.prim = (u8 *)g_Game_801362A4.db[g_Game_801362A4.cur].hud[1];
    PutDispEnv(&g_Game_801362A4.db[g_Game_801362A4.cur].env[0x5C]);
    t = -1;
    loading = 1;
    PutDrawEnv(g_Game_801362A4.db[g_Game_801362A4.cur].env);
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        if (loading && func_800116C0() < 0) {
            loading = 0;
        }
        if (D_800E3890.f_20 != 0 && t < 0) {
            t = 0;
        }
        if (t >= 0) {
            t++;
            if (t >= 0xD3 && loading == 0) {
                return 0;
            }
        }
        Cd_Update();
        DrawSync(0);
        VSync(0);
    }
}

extern u8 D_800EC360[];
void SetGeomOffset(s32 ofx, s32 ofy);
void *SetDefDrawEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void *SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetDispMask(s32 mask);

s32 func_80136424(void) {
    u8 *s2;
    u8 *v0;
    u8 *nv;

    SetGeomOffset(0xC0, 0x78);
    SetDefDrawEnv(D_800EC360, 0, 0, 0x280, 0x1E0);
    s2 = D_800EC360 + 0x4078;
    SetDefDrawEnv(s2, 0, 0, 0x280, 0x1E0);
    SetDefDispEnv(D_800EC360 + 0x5C, 0, 0, 0x280, 0x1E0);
    SetDefDispEnv(D_800EC360 + 0x40D4, 0, 0, 0x280, 0x1E0);
    v0 = D_800EC360;
    v0 = v0 - 0x10;
    nv = D_800EC360 + 0x7FF0;
    *(s8 *)(v0 + 0x409E) = 1;
    *(s8 *)(v0 + 0x26) = 1;
    *(s8 *)(v0 + 0x40F4) = 1;
    *(s8 *)(v0 + 0x7C) = 1;
    *(s8 *)(v0 + 0x40A0) = 0;
    *(s8 *)(v0 + 0x28) = 0;
    *(s32 *)(v0 + 0x4084) = 0x801A8000;
    *(s32 *)(nv + 0xFC) = 0x801D0000;
    D_800EC360[0x19] = 0;
    D_800EC360[0x1A] = 0;
    D_800EC360[0x1B] = 0;
    s2[0x19] = 0;
    s2[0x1A] = 0;
    s2[0x1B] = 0;
    SetDispMask(1);
    return 0;
}

/* uses Rect_801362A4, g_Game_801362A4, D_800E3890 and the decls above func_801362A4 in src/ovl/385.c */
void DrawOTag(u32 *p);

s32 func_80136528(void) {
    Rect_801362A4 r;
    s32 loading;
    s32 t;

    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    r.x = 0;
    r.y = 0x100;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    Cd_StartFileLoad(0, 6);
    t = -1;
    loading = 1;
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        if (loading && func_800116C0() < 0) {
            loading = 0;
        }
        if (D_800E3890.f_20 != 6 && t < 0) {
            t = 0;
        }
        if (t >= 0) {
            t++;
            if (t >= 0x169) {
                return 0;
            }
        }
        Cd_Update();
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_801362A4.db[g_Game_801362A4.cur].env[0x5C]);
        PutDrawEnv(g_Game_801362A4.db[g_Game_801362A4.cur].env);
        DrawOTag(&g_Game_801362A4.db[g_Game_801362A4.cur].ot[0xFFF]);
    }
}

/* uses Rect_801362A4, g_Game_801362A4 and the decls above func_801362A4 in src/ovl/385.c */
s32 Cd_ReadFile(s32, s32);
void Cd_WaitIdle(s32);
void func_80068D10(s32);

s32 func_801366EC(void) {
    Rect_801362A4 r;
    s32 t;

    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    r.x = 0;
    r.y = 0x100;
    r.w = 0x280;
    r.h = 0x100;
    ClearImage2(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    Cd_ReadFile(0x22, 0x80154000);
    Cd_WaitIdle(0);
    func_80068D10(0x80154000);
    DrawSync(0);
    VSync(2);
    t = 0;
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        if (t >= 0) {
            t++;
            if (t >= 0x2D1) {
                return 0;
            }
        }
        Cd_Update();
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_801362A4.db[g_Game_801362A4.cur].env[0x5C]);
        PutDrawEnv(g_Game_801362A4.db[g_Game_801362A4.cur].env);
        DrawOTag(&g_Game_801362A4.db[g_Game_801362A4.cur].ot[0xFFF]);
    }
}

typedef struct { s16 x, y, w, h; } Rect_385;
extern Rect_385 D_80136918;
extern struct S_g_Game { u8 pad_0[0x8120]; s16 f_8120; } g_Game;
void ClearImage(Rect_385 *, s32, s32, s32);
void DrawSync(s32);
s32 Minigame_Run(s32);

s32 func_80136894(void)
{
  Rect_385 r = D_80136918;
  ClearImage(&r, 0, 0, 0);
  DrawSync(0);
  Minigame_Run(1);
  g_Game.f_8120 = 3;
  return 0;
}

/* the first rect of this file's rodata, which the split leaves at the end of the text */
__asm__(".section .text\n.globl D_80136910\nD_80136910:\n\t.word 0");

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136914);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136AEC);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136D18);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136E60);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136FA0);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80137014);
