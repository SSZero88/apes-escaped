#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern Rect_80136000 D_80136A80;
extern s32 D_80136B40;
extern s32 D_80136B4C;
extern s32 D_80136B50;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; s16 f_8120; u8 pad8122[0x198]; u16 f_82BA; } g_Game_80136000 asm("g_Game");
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void func_8008C390(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_80136000(void) {
    Rect_80136000 r;

    r = D_80136A80;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136000.db[1].env[0x18] = 1;
    g_Game_80136000.db[0].env[0x18] = 1;
    D_80136B40 = 0;
    g_Game_80136000.cur = 0;
    D_80136B4C = 0;
    D_80136B50 = 0;
    g_Game_80136000.f_82BA |= 2;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8008C390(), func_801361BC() >= 0) {
        DrawSync(0);
        VSync(0);
        g_Game_80136000.frame++;
        PutDispEnv(&g_Game_80136000.db[g_Game_80136000.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136000.db[g_Game_80136000.cur].env);
        DrawOTag(&g_Game_80136000.db[g_Game_80136000.cur].ot[0xFFF]);
    }
    g_Game_80136000.f_8120 = 3;
    return 0;
}

extern s32 D_80136B4C;
s32 func_80136244(void);

s32 func_801361BC(void)
{
  int new_var;
  switch (D_80136B4C)
  {
    case 0:
      new_var = func_80136244() < 0;
      if (new_var)
    {
      new_var = 1;
      return -new_var;
    }
      return 0;

    case 1:
      func_80136698();
      return 0;

    case 2:
      func_8013684C();
      return 0;

  }

  return 0;
}

INCLUDE_ASM("asm/ovl/387/nonmatchings/387_sound_test", func_80136244);

/* returns s32 0: change the file prototype at the top of 387_sound_test.c to s32 func_80136698(void); */
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; u8 pad164[4]; u32 repeat; } g_Pad_80136698 asm("g_Pad");
extern u8 D_80136ABC[];
extern u8 D_80136ACC[];
extern u8 D_80136AE4[];
extern u8 D_80136AF8[];
extern s32 D_80136B44;
extern s32 D_80136FD0;
extern s32 D_80136FD4;
extern s32 D_80136FD8;
void func_8008C3C0(s32, s32);
void DebugFont_Printf(u8 *, ...);
s32 Sound_PlayFixed(s32);
void func_800A342C(s32);
s32 func_80088548(s32, s32 *, s32 *);

s32 func_80136698(void) {
    u32 b;

    func_8008C3C0(0x82, 0x46);
    DebugFont_Printf(D_80136ABC);
    func_8008C3C0(0x82, 0xC4);
    DebugFont_Printf(D_80136ACC);
    func_8008C3C0(0x82, 0xD2);
    DebugFont_Printf(D_80136AE4);
    if (g_Pad_80136698.held & g_Pad_80136698.pressed & PAD_START) {
        Sound_PlayFixed(2);
        D_80136B4C = 0;
        return 0;
    }
    b = g_Pad_80136698.repeat;
    if (b & PAD_UP) {
        Sound_PlayFixed(0);
        if (--D_80136B44 < 0) {
            D_80136B44 = 0xAB;
        }
    } else if (b & PAD_DOWN) {
        Sound_PlayFixed(0);
        if (++D_80136B44 >= 0xAC) {
            D_80136B44 = 0;
        }
    } else if (b & PAD_SQUARE) {
        D_80136FD8 = Sound_PlayFixed(D_80136B44);
    } else if (b & PAD_CIRCLE) {
        D_80136FD8 = Sound_PlayFixed(D_80136B44);
    } else if (b & PAD_SELECT) {
        func_800A342C(0);
    }
    func_80088548(D_80136B44, &D_80136FD0, &D_80136FD4);
    func_8008C3C0(0x82, 0x82);
    DebugFont_Printf(D_80136AF8, D_80136B44, D_80136FD0, D_80136FD4, D_80136FD8);
    return 0;
}

/* returns s32 0: change the file prototype at the top of 387_sound_test.c to s32 func_8013684C(void); needs func_80136698's draft (decls of func_8008C3C0, DebugFont_Printf, Sound_PlayFixed, func_800A342C, func_80088548) merged above */
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; u8 pad164[4]; u32 repeat; } g_Pad_8013684C asm("g_Pad");
extern u8 D_80136B18[];
extern u8 D_80136B28[];
extern s32 D_80136B48;
void Sound_SetVolumes(s32, s32);
void Sound_UnloadBanks(s32);
extern u8 D_80136ACC_684C[] asm("D_80136ACC");
extern u8 D_80136AE4_684C[] asm("D_80136AE4");
extern u8 D_80136AF8_684C[] asm("D_80136AF8");
extern s32 D_80136B44_684C asm("D_80136B44");
extern s32 D_80136FDC;
extern s32 D_80136FE0;
extern s32 D_80136FE4;

s32 func_8013684C(void) {
    u32 b;

    func_8008C3C0(0x82, 0x46);
    DebugFont_Printf(D_80136B18);
    func_8008C3C0(0x82, 0xB4);
    DebugFont_Printf(D_80136B28);
    func_8008C3C0(0x82, 0xC4);
    DebugFont_Printf(D_80136ACC_684C);
    func_8008C3C0(0x82, 0xD2);
    DebugFont_Printf(D_80136AE4_684C);
    if (g_Pad_8013684C.held & g_Pad_8013684C.pressed & PAD_START) {
        Sound_PlayFixed(2);
        D_80136B4C = 0;
        Sound_UnloadBanks(1);
        return 0;
    }
    b = g_Pad_8013684C.repeat;
    if (b & PAD_UP) {
        Sound_PlayFixed(0);
        if (--D_80136B44_684C < 0xAC) {
            D_80136B44_684C = 0xC4;
        }
    } else if (b & PAD_DOWN) {
        Sound_PlayFixed(0);
        if (++D_80136B44_684C >= 0xC5) {
            D_80136B44_684C = 0xAC;
        }
    } else if (b & PAD_R1) {
        if (D_80136B48) {
            Sound_SetVolumes(0x7F, 0x30);
        } else {
            Sound_SetVolumes(0x7F, 0);
        }
        D_80136B48 = !D_80136B48;
    } else if (b & PAD_SQUARE) {
        D_80136FE4 = Sound_PlayFixed(D_80136B44_684C);
    } else if (b & PAD_CIRCLE) {
        D_80136FE4 = Sound_PlayFixed(D_80136B44_684C);
    } else if (b & PAD_SELECT) {
        func_800A342C(0);
    }
    func_80088548(D_80136B44_684C, &D_80136FDC, &D_80136FE0);
    func_8008C3C0(0x82, 0x82);
    DebugFont_Printf(D_80136AF8_684C, D_80136B44_684C, D_80136FDC, D_80136FE0, D_80136FE4);
    return 0;
}
