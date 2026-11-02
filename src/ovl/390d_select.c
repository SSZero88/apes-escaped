#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_8013F630;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013F630;
extern s16 D_8013AF66;
extern s16 D_8013AF68;
s32 D_8013FB20 = 2;
s16 D_8013FB24[6] = {1, 1, 1, 1, 1, 1};
extern s32 D_8013F280;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013F630 asm("g_Game");
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_8013A634(void);
s32 func_8013F808(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_8013F630(void) {
    Rect_8013F630 r = {0, 0, 384, 512};
    s32 res;
    s32 v;

    g_Game_8013F630.db[1].env[0x18] = 1;
    g_Game_8013F630.db[0].env[0x18] = 1;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[0])->r0 = 0;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[0])->g0 = 0;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[0])->b0 = 0;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[1])->r0 = 0;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[1])->g0 = 0;
    ((DrawEnv_8013F630 *)&g_Game_8013F630.db[1])->b0 = 0;
    D_8013AF68 = 0x1E;
    g_Game_8013F630.cur = 0;
    D_8013AF66 = 0;
    D_8013FB20 = 2;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        v = func_8013F808();
        if (v != 0) {
            res = v;
            D_8013AF66 = 2;
        }
        DrawSync(0);
        VSync(0);
        g_Game_8013F630.frame++;
        PutDispEnv(&g_Game_8013F630.db[g_Game_8013F630.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013F630.db[g_Game_8013F630.cur].env);
        DrawOTag(&g_Game_8013F630.db[g_Game_8013F630.cur].ot[0xFFF]);
    }
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    if (res < 0) {
        return -1;
    }
    D_8013F280 = res;
    return 0;
}

extern s32 D_800E5488;
extern GameDraw g_Game_8013F808 asm("g_Game");
s32 func_8013FDE4(s32 sel, s16 *flags);
s32 func_8013946C(s32 i, s32 x, s32 y);
s32 func_8013F9F8(s32 n);
void func_80139A3C(s32);
void func_80139A68(void);
s32 func_8013A400(void);
s32 Sound_PlayFixed(s32);

s32 func_8013F808(void) {
    u32 *ot;

    func_8013FDE4(D_8013FB20, D_8013FB24);
    func_8013946C(0, 0xFE, 0xC8);
    func_8013946C(1, 0x112, 0xC8);
    g_Game_8013F808.prim[3] = 1;
    ((u32 *)g_Game_8013F808.prim)[1] = 0xE1000217;
    ot = &g_Game_8013F808.db[g_Game_8013F808.cur].ot[0];
    __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(ot), "m"(g_Game_8013F808.prim) : "$2", "$4", "memory");
    g_Game_8013F808.prim += 8;
    func_8013F9F8(D_8013FB20 - 2);
    func_80139A3C(4);
    func_80139A68();
    if (D_8013AF66 != 1) {
        return 0;
    }
    if (D_800E5488 == 0x1000) {
        Sound_PlayFixed(0);
        if (--D_8013FB20 < 2) {
            D_8013FB20 = 4;
        }
    }
    if (D_800E5488 == 0x4000) {
        Sound_PlayFixed(0);
        if (++D_8013FB20 >= 5) {
            D_8013FB20 = 2;
        }
    }
    if (func_8013A400()) {
        switch (D_8013FB20) {
        case 2:
            Sound_PlayFixed(3);
            return -1;
        case 3:
            Sound_PlayFixed(3);
            return 1;
        case 4:
            Sound_PlayFixed(3);
            return 2;
        }
    }
    return 0;
}

extern u8 g_Game[];
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013F9F8;
typedef struct { u32 tag; u32 code; } Tpage_8013F9F8;
typedef struct { u32 frame; } Frame_8013F9F8;

s32 func_8013F9F8(s32 n) {
    u8 *p;
    u32 *ot;

    p = G_DRAW.prim;
    p[3] = 4;
    ((Sprt_8013F9F8 *)p)->code = 0x65;
    ((Sprt_8013F9F8 *)p)->x0 = 0x4C;
    ((Sprt_8013F9F8 *)p)->y0 = n * 25 + 0x51 - ((((Frame_8013F9F8 *)g_Game)->frame >> 2) % 3);
    ((Sprt_8013F9F8 *)p)->clut = 0x7DEB;
    ((Sprt_8013F9F8 *)p)->u0 = 0xA0;
    ((Sprt_8013F9F8 *)p)->v0 = 0xA0;
    ((Sprt_8013F9F8 *)p)->w = 0x20;
    ((Sprt_8013F9F8 *)p)->h = 0x20;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x14;
    p[3] = 1;
    ((Tpage_8013F9F8 *)p)->code = 0xE100023A;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}
__asm__(".section .text\n\t.balign 16");
__asm__(".section .rodata\n\t.balign 16\n\t.section .text");
