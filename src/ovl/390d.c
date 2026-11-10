#include "common.h"
#include "m2c_macros.h"


typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FB30;
extern u8 D_8014147C[];
extern u8 D_801414E8[];
void SaveMenu_DrawText(u8 *, s32, s32, s32);

s32 func_8013FB30(s32 n) {
    SaveMenu_DrawText(D_8014147C + n * 0x24, ((Item_8013FB30 *)(D_8014147C - 4))[n].x, ((Item_8013FB30 *)(D_8014147C - 4))[n].y, 1);
    switch (n) {
    case 0: {
        u8 *b = D_801414E8;
        Item_8013FB30 *p = (Item_8013FB30 *)(b - 4);
        SaveMenu_DrawText(b, p[0].x, p[0].y, 0);
        SaveMenu_DrawText(b + 0x24, p[1].x, p[1].y, 0);
        break;
    }
    case 1: {
        u8 *b = D_801414E8 + 0x48;
        Item_8013FB30 *p = (Item_8013FB30 *)(b - 0x4C);
        SaveMenu_DrawText(b, p[2].x, p[2].y, 0);
        break;
    }
    case 2: {
        u8 *b = D_801414E8 + 0x6C;
        Item_8013FB30 *p = (Item_8013FB30 *)(b - 0x70);
        SaveMenu_DrawText(b, p[3].x, p[3].y, 0);
        break;
    }
    }
    return 0;
}

extern u8 D_80141554[];

u8 *func_8013FC20(void) {
    return D_80141554;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FC2C;
extern u8 D_80141578[];
#define D_80141574 ((Item_8013FC2C *)(D_80141578 - 4))
void SaveMenu_DrawText(u8 *, s32, s32, s32);

s32 func_8013FC2C(s32 sel, s16 *flags) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (flags[i] == 1) {
            if (i == sel) {
                SaveMenu_DrawText(D_80141574[sel].body, D_80141574[sel].x, D_80141574[sel].y, 1);
            } else {
                SaveMenu_DrawText(D_80141574[i].body, D_80141574[i].x, D_80141574[i].y, 0);
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

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FD50;
extern u8 D_80141704[];
#define D_80141700 ((Item_8013FD50 *)(D_80141704 - 4))

s32 func_8013FD50(s16 *flags) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (flags[i] == 1) {
            SaveMenu_DrawText(D_80141700[i].body, D_80141700[i].x, D_80141700[i].y, 0);
        }
    }
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FDE4;
extern u8 D_80141824[];
#define D_80141820 ((Item_8013FDE4 *)(D_80141824 - 4))

s32 func_8013FDE4(s32 sel, s16 *flags) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (flags[i] == 1) {
            if (sel == i) {
                SaveMenu_DrawText(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 1);
            } else {
                SaveMenu_DrawText(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 0);
            }
        }
    }
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FEA0;
extern u8 D_801418FC[];

s32 func_8013FEA0(void) {
    u8 *b = D_801418FC;
    Item_8013FEA0 *p = (Item_8013FEA0 *)(b - 4);
    SaveMenu_DrawText(b, p[0].x, p[0].y, 0);
    SaveMenu_DrawText(b + 0x24, p[1].x, p[1].y, 0);
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FEFC;
extern Item_8013FEFC D_80140470[];
extern struct { u32 frame; } g_Game_8013FEFC asm("g_Game");

s32 func_8013FEFC(s32 n) {
    s32 base;
    s32 i;

    base = 0x2A;
    if (n == 1) {
        base = 0;
    }
    for (i = 0; i < 3; i++) {
        if (D_80140470[base + i].x != -2 || g_Game_8013FEFC.frame % 20 < 11) {
            SaveMenu_DrawText(D_80140470[base + i].body, D_80140470[base + i].x, D_80140470[base + i].y, 0);
        }
    }
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FFEC;
extern u8 D_80141434[];
void Menu_DrawCaps(s32, s32, s32);

s32 func_8013FFEC(s32 sel) {
    u8 *b = D_80141434;
    Item_8013FFEC *p = (Item_8013FFEC *)(b - 4);
    SaveMenu_DrawText(b, p[0].x, p[0].y, sel == 0);
    SaveMenu_DrawText(b + 0x24, p[1].x, p[1].y, sel);
    Menu_DrawCaps(0xC0, p[0].y + sel * 20, 0x4C);
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_80140074;
extern u8 D_80141650[];

s32 func_80140074(s32 n) {
    u8 *b = D_80141650;
    Item_80140074 *p = (Item_80140074 *)(b - 4);
    SaveMenu_DrawText(b, p[0].x, p[0].y, 0);
    if (n == 1) {
        SaveMenu_DrawText(b + 0x48, p[2].x, p[2].y, 0);
    } else {
        SaveMenu_DrawText(b + 0x24, p[1].x, p[1].y, 0);
    }
    return 0;
}

typedef struct { s16 x, y; u8 text[0x20]; } Line_390b;
extern Line_390b D_801416B8[2];
void SaveMenu_DrawText(u8 *, s32, s32, s32);

s32 func_801400F4(s32 n) {
    s32 off;

    D_801416B8[0].text[4] = n + 0x6B;
    off = n * 48;
    SaveMenu_DrawText(D_801416B8[0].text, D_801416B8[0].x, D_801416B8[0].y + off, 1);
    SaveMenu_DrawText(D_801416B8[1].text, D_801416B8[1].x, D_801416B8[1].y + off, 0);
    return 0;
}

typedef struct { s16 x, y; u8 body[0x20]; } Item_8014016C;
typedef struct { s16 start, count; } Range_8014016C;
extern Item_8014016C D_80140470_8014016C[] asm("D_80140470");
extern Range_8014016C D_80141940[];
extern s16 SaveMenu_Screen;
extern struct { u8 pad_0[6]; s16 f_6; } D_800E3880_8014016C asm("g_MemCard");
extern u8 D_800E1A18[];
extern struct { u32 frame; } g_Game_8014016C asm("g_Game");
s32 SaveMenu_GetTextWidth(u8 *);

s32 func_8014016C(void) {
    s32 start;
    s32 i;
    s32 k;
    s32 w;
    s32 x;

    switch (SaveMenu_Screen) {
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
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
    case 46:
    case 47:
    case 48:
    case 49:
        start = D_80141940[SaveMenu_Screen].start;
        for (i = 0; i < D_80141940[SaveMenu_Screen].count; i++) {
            k = start + i;
            if (D_80140470_8014016C[k].x == -2 && g_Game_8014016C.frame % 20 >= 11) {
                continue;
            }
            if (D_80140470_8014016C[k].x == -3) {
                w = (SaveMenu_GetTextWidth(D_800E1A18 + D_800E3880_8014016C.f_6 * 0x7A0) + SaveMenu_GetTextWidth(D_80140470_8014016C[k].body)) / 2;
                x = 0xC0 - w;
                SaveMenu_DrawText(D_800E1A18 + D_800E3880_8014016C.f_6 * 0x7A0, x, D_80140470_8014016C[k].y, 0);
                SaveMenu_DrawText(D_80140470_8014016C[k].body, x + SaveMenu_GetTextWidth(D_800E1A18 + D_800E3880_8014016C.f_6 * 0x7A0), D_80140470_8014016C[k].y, 0);
            } else {
                SaveMenu_DrawText(D_80140470_8014016C[k].body, D_80140470_8014016C[k].x, D_80140470_8014016C[k].y, 0);
            }
        }
        break;
    }
    return 0;
}
__asm__(".section .text\n\t.balign 16");
