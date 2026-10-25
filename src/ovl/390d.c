#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_8013F630;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013F630;
extern Rect_8013F630 D_8013FB10;
extern s16 D_8013AF66;
extern s16 D_8013AF68;
extern s32 D_8013FB20;
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
    Rect_8013F630 r;
    s32 res;
    s32 v;

    r = D_8013FB10;
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

extern s16 D_8013FB24[];
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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013F9F8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FB14);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FB30);

extern u8 D_80141554[];

u8 *func_8013FC20(void) {
    return D_80141554;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FC2C;
extern u8 D_80141578[];
#define D_80141574 ((Item_8013FC2C *)(D_80141578 - 4))
void func_80136000(u8 *, s32, s32, s32);

s32 func_8013FC2C(s32 sel, s16 *flags) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (flags[i] == 1) {
            if (i == sel) {
                func_80136000(D_80141574[sel].body, D_80141574[sel].x, D_80141574[sel].y, 1);
            } else {
                func_80136000(D_80141574[i].body, D_80141574[i].x, D_80141574[i].y, 0);
            }
        }
    }
    Menu_DrawCaps(D_80141574[sel].x + 0x1C, D_80141574[sel].y, 0x50);
    return 0;
}

extern u8 D_80141800[];

u8 *func_8013FD44(void) {
    return D_80141800;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FD50);

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FDE4;
extern u8 D_80141824[];
#define D_80141820 ((Item_8013FDE4 *)(D_80141824 - 4))

s32 func_8013FDE4(s32 sel, s16 *flags) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (flags[i] == 1) {
            if (sel == i) {
                func_80136000(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 1);
            } else {
                func_80136000(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 0);
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FEA0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FEFC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FFEC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_80140074);

typedef struct { s16 x, y; u8 text[0x20]; } Line_390b;
extern Line_390b D_801416B8[2];
void func_80136000(u8 *, s32, s32, s32);

s32 func_801400F4(s32 n) {
    s32 off;

    D_801416B8[0].text[4] = n + 0x6B;
    off = n * 48;
    func_80136000(D_801416B8[0].text, D_801416B8[0].x, D_801416B8[0].y + off, 1);
    func_80136000(D_801416B8[1].text, D_801416B8[1].x, D_801416B8[1].y + off, 0);
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8014016C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", jtbl_801403B0);

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390d", D_80144FE0);
