#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_80146000);

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_8014607C);

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_80146230);

typedef struct { s32 a; s32 b; void *c; } Entry_80146500;
extern Entry_80146500 D_80146878[];
extern s32 D_80146774;
extern s32 D_80146770;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80146500 asm("g_Game");
s32 func_80011194(void *);
s32 func_800116C0(void);
void Cd_Update(void);
s32 func_8005BEF0(void);
void func_80031B60(s32, s32);
void Overlay_Request(s32);
void Overlay_Update(void);
void Gfx_BeginFrame(void);
s32 Overlay_GetState(void);
s32 DrawSync(s32 mode);
void func_8005DEE0(s32, s32, s32, s32);
void func_8001325C(s32);

s32 func_80146500(void) {
    func_80011194(D_80146878[D_80146774].c);
    while (func_800116C0() >= 0) {
        Cd_Update();
    }
    func_8005BEF0();
    func_80031B60(D_80146878[D_80146774].a, 0);
    Overlay_Request(D_80146878[D_80146774].b);
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
        func_8005DEE0((s32)g_Game_80146500.db[g_Game_80146500.cur].env, (s32)&g_Game_80146500.db[g_Game_80146500.cur].env[0x5C],
                      (s32)(g_Game_80146500.ot + 0xFFF), (s32)g_Game_80146500.db[g_Game_80146500.cur].hud);
    }
    D_80146770 = 0;
    return 0;
}

extern u8 g_Game[];
extern u8 *D_800EC354;
extern u8 D_801469D0[];
void SetDrawTPage(void *p, s32 dfe, s32 dtd, s32 tpage);
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt16_8014666C;

void func_8014666C(u8 *s, s32 x, s32 y, s32 pal) {
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
        x += D_801469D0[c];
    }
    SetDrawTPage(p, 0, 1, 0x16);
    ADD_PRIM_ASM2(ot, p);
    p++;
    D_800EC354 = (u8 *)p;
}
