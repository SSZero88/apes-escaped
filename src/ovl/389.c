#include "common.h"
#include "m2c_macros.h"

extern s32 CutsceneTest_State;
s32 CutsceneTest_RunMenu(void);
s32 CutsceneTest_PlayEntry(void);

s32 CutsceneTest_Main(void) {
    s32 s;

    CutsceneTest_State = 0;
    for (;;) {
        s = CutsceneTest_State;
    again:
        switch (s) {
        case 0:
            if (CutsceneTest_RunMenu() < 0) {
                return 0;
            }
            break;
        case 1:
            CutsceneTest_PlayEntry();
            break;
        default:
            goto again;
        }
    }
}

typedef struct { s16 x, y, w, h; } Rect_8014607C;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8014607C;
extern Rect_8014607C D_80146760;
extern s32 CutsceneTest_Cursor;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8014607C asm("g_Game");
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 CutsceneTest_UpdateMenu(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
void Cd_Update(void);

s32 CutsceneTest_RunMenu(void) {
    Rect_8014607C r;
    s32 v;

    r = D_80146760;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0x7F);
    DrawSync(0);
    g_Game_8014607C.db[1].env[0x18] = 1;
    g_Game_8014607C.db[0].env[0x18] = 1;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[0])->r0 = 0;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[0])->g0 = 0;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[0])->b0 = 0x7F;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[1])->r0 = 0;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[1])->g0 = 0;
    ((DrawEnv_8014607C *)&g_Game_8014607C.db[1])->b0 = 0x7F;
    g_Game_8014607C.cur = 0;
    CutsceneTest_Cursor = 0;
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        v = CutsceneTest_UpdateMenu();
        if (v != 0) {
            break;
        }
        DrawSync(0);
        VSync(0);
        g_Game_8014607C.frame++;
        PutDispEnv(&g_Game_8014607C.db[g_Game_8014607C.cur].env[0x5C]);
        PutDrawEnv(g_Game_8014607C.db[g_Game_8014607C.cur].env);
        DrawOTag(&g_Game_8014607C.db[g_Game_8014607C.cur].ot[0xFFF]);
        Cd_Update();
    }
    if (v < 0) {
        return -1;
    }
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4_80146230;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80146230 asm("g_Pad");
extern struct { s32 frame; PolyG4_80146230 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80146230 asm("g_Game");
extern s32 CutsceneTest_State;
extern u8 CutsceneTest_TitleText[];
extern u8 CutsceneTest_RowText[];
s32 Sound_PlayFixed(s32);
void CutsceneTest_DrawText(u8 *s, s32 x, s32 y, s32 pal);

s32 CutsceneTest_UpdateMenu(void) {
    s32 i;
    u32 *ot;

    if ((g_Pad_80146230.f_160 & g_Pad_80146230.f_158) & 0x860) {
        Sound_PlayFixed(2);
        CutsceneTest_State = 1;
        return 1;
    }
    if ((g_Pad_80146230.f_160 & g_Pad_80146230.f_158) & 0x100) {
        return -1;
    }
    if ((g_Pad_80146230.f_160 & g_Pad_80146230.f_158) & 0x1000) {
        Sound_PlayFixed(0);
        if (--CutsceneTest_Cursor < 0) {
            CutsceneTest_Cursor = 0xB;
        }
    }
    if ((g_Pad_80146230.f_160 & g_Pad_80146230.f_158) & 0x4000) {
        Sound_PlayFixed(0);
        if (++CutsceneTest_Cursor >= 0xC) {
            CutsceneTest_Cursor = 0;
        }
    }
    CutsceneTest_DrawText(CutsceneTest_TitleText, 0xA0, 0x28, 0);
    for (i = 0; i < 12; i++) {
        CutsceneTest_DrawText(CutsceneTest_RowText + i * 16, 0x6E, 0x46 + i * 20, 1);
    }
    ((u8 *)g_Game_80146230.prim)[3] = 8;
    g_Game_80146230.prim->code = 0x38;
    g_Game_80146230.prim->code |= 2;
    g_Game_80146230.prim->x0 = 0x6E;
    g_Game_80146230.prim->y0 = CutsceneTest_Cursor * 20 + 0x46;
    g_Game_80146230.prim->x1 = 0x104;
    g_Game_80146230.prim->y1 = CutsceneTest_Cursor * 20 + 0x46;
    g_Game_80146230.prim->x2 = 0x6E;
    g_Game_80146230.prim->y2 = CutsceneTest_Cursor * 20 + 0x56;
    g_Game_80146230.prim->x3 = 0x104;
    g_Game_80146230.prim->y3 = CutsceneTest_Cursor * 20 + 0x56;
    g_Game_80146230.prim->r0 = 0xF5;
    g_Game_80146230.prim->g0 = 0xDC;
    g_Game_80146230.prim->b0 = 0xC8;
    g_Game_80146230.prim->r1 = 0xE6;
    g_Game_80146230.prim->g1 = 0x46;
    g_Game_80146230.prim->b1 = 0x28;
    g_Game_80146230.prim->r2 = 0xC4;
    g_Game_80146230.prim->g2 = 0x46;
    g_Game_80146230.prim->b2 = 0x3C;
    g_Game_80146230.prim->r3 = 0x5F;
    g_Game_80146230.prim->g3 = 0xA;
    g_Game_80146230.prim->b3 = 8;
    ot = g_Game_80146230.db[g_Game_80146230.cur].ot;
    __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)" : : "r"(ot), "m"(g_Game_80146230.prim) : "$2", "$5", "memory");
    g_Game_80146230.prim++;
    return 0;
}

typedef struct { s32 a; s32 b; void *c; } Entry_80146500;
extern Entry_80146500 CutsceneTest_Entries[];
extern s32 CutsceneTest_Cursor;
extern s32 CutsceneTest_State;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80146500 asm("g_Game");
s32 Cd_StartLoadList(void *);
s32 Cd_PollLoadList(void);
void Cd_Update(void);
s32 Gfx_ResetDisplay(void);
void Stage_Load(s32, s32);
void Overlay_Request(s32);
void Overlay_Update(void);
void Gfx_BeginFrame(void);
s32 Overlay_GetState(void);
s32 DrawSync(s32 mode);
void Gfx_QueueFlip(s32, s32, s32, s32);
void func_8001325C(s32);

s32 CutsceneTest_PlayEntry(void) {
    Cd_StartLoadList(CutsceneTest_Entries[CutsceneTest_Cursor].c);
    while (Cd_PollLoadList() >= 0) {
        Cd_Update();
    }
    Gfx_ResetDisplay();
    Stage_Load(CutsceneTest_Entries[CutsceneTest_Cursor].a, 0);
    Overlay_Request(CutsceneTest_Entries[CutsceneTest_Cursor].b);
    while (1) {
        func_8001325C(1);
        Overlay_Update();
        g_Game_80146500.frame++;
        Gfx_BeginFrame();
        if (Overlay_GetState() == 0) {
            break;
        }
        Cd_Update();
        DrawSync(0);
        Gfx_QueueFlip((s32)g_Game_80146500.db[g_Game_80146500.cur].env, (s32)&g_Game_80146500.db[g_Game_80146500.cur].env[0x5C],
                      (s32)(g_Game_80146500.ot + 0xFFF), (s32)g_Game_80146500.db[g_Game_80146500.cur].hud);
    }
    CutsceneTest_State = 0;
    return 0;
}

extern u8 g_Game[];
extern u8 *g_GamePrim;
extern u8 CutsceneTest_GlyphWidths[];
void SetDrawTPage(void *p, s32 dfe, s32 dtd, s32 tpage);
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt16_8014666C;

void CutsceneTest_DrawText(u8 *s, s32 x, s32 y, s32 pal) {
    Sprt16_8014666C *p;
    u32 *ot;
    u8 c;

    p = (Sprt16_8014666C *)G_DRAW.prim;
    ot = G_DRAW.ot;
    while ((c = *s) != 0) {
        ((u8 *)p)[3] = 3;
        p->code = 0x7D;
        p->x0 = x;
        p->y0 = y;
        p->u0 = (c & 0xF) << 4;
        p->v0 = c & 0xF0;
        p->clut = ((pal + 0x100) << 6) | 0x1B;
        ADD_PRIM_ASM(ot, p);
        p++;
        s++;
        x += CutsceneTest_GlyphWidths[c];
    }
    SetDrawTPage(p, 0, 1, 0x16);
    ADD_PRIM_ASM2(ot, p);
    p++;
    g_GamePrim = (u8 *)p;
}
