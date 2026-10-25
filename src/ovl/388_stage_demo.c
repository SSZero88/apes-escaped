#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x8120]; s16 f_8120; } g_Game;

s32 func_80136000(void) {
    func_801361D0(0);
    g_Game.f_8120 = 9;
    return 0;
}

INCLUDE_ASM("asm/ovl/388/nonmatchings/388_stage_demo", func_80136038);

typedef struct { s16 x, y, w, h; } Rect_801361D0;
extern Rect_801361D0 D_801363E0;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_801361D0 asm("g_Game");
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

M2C_UNK func_801361D0(M2C_UNK arg0) {
    Rect_801361D0 r;

    r = D_801363E0;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_801361D0.db[1].env[0x18] = 1;
    g_Game_801361D0.db[0].env[0x18] = 1;
    g_Game_801361D0.cur = 0;
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        func_8008C390();
        if (func_80136350(arg0) < 0) {
            return 0;
        }
        DrawSync(0);
        VSync(0);
        g_Game_801361D0.frame++;
        PutDispEnv(&g_Game_801361D0.db[g_Game_801361D0.cur].env[0x5C]);
        PutDrawEnv(g_Game_801361D0.db[g_Game_801361D0.cur].env);
        DrawOTag(&g_Game_801361D0.db[g_Game_801361D0.cur].ot[0xFFF]);
    }
}

extern u8 D_801363E8[];
extern u8 D_801363FC[];
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136350 asm("g_Pad");
void func_8008C3C0(s32, s32);
void DebugFont_Printf(u8 *, ...);
void Sound_PlayFixed(s32);

s32 func_80136350(s32 n) {
    func_8008C3C0(0x82, 0x46);
    DebugFont_Printf(D_801363E8, n);
    func_8008C3C0(0x82, 0xD2);
    DebugFont_Printf(D_801363FC);
    if (g_Pad_80136350.f_158 & g_Pad_80136350.f_160 & 0x800) {
        Sound_PlayFixed(2);
        return -1;
    }
    return 0;
}
