#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_8013C5E0;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013C5E0;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013C5E0 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 held; } g_Pad_8013C5E0 asm("g_Pad");
void Gfx_InitDisplay(void);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void DebugFont_Init(void);
void DebugFont_Locate(s32, s32);
void DebugFont_PrintfAlways(u8 *);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
s32 Sound_PlayFixed(s32);

s32 func_8013C5E0(void) {
    Rect_8013C5E0 r = {0, 0, 384, 512};

    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_8013C5E0.db[1].env[0x18] = 1;
    g_Game_8013C5E0.db[0].env[0x18] = 1;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[0])->r0 = 0;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[0])->g0 = 0;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[0])->b0 = 0x7F;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[1])->r0 = 0;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[1])->g0 = 0;
    ((DrawEnv_8013C5E0 *)&g_Game_8013C5E0.db[1])->b0 = 0x7F;
    g_Game_8013C5E0.cur = 0;
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        DebugFont_Init();
        DebugFont_Locate(0x8C, 0x6E);
        DebugFont_PrintfAlways("Now working.\n");
        DebugFont_Locate(0x82, 0xB4);
        DebugFont_PrintfAlways("Push START key.\n");
        if (g_Pad_8013C5E0.held & PAD_START) {
            break;
        }
        DrawSync(0);
        VSync(0);
        g_Game_8013C5E0.frame++;
        PutDispEnv(&g_Game_8013C5E0.db[g_Game_8013C5E0.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013C5E0.db[g_Game_8013C5E0.cur].env);
        DrawOTag(&g_Game_8013C5E0.db[g_Game_8013C5E0.cur].ot[0xFFF]);
    }
    Sound_PlayFixed(2);
    return 0;
}
__asm__(".section .text\n\t.balign 16");
