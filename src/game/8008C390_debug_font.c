#include "common.h"
#include "m2c_macros.h"

extern struct { u8 pad0[0x82BA]; s16 unk82BA; } g_Game;
void DebugFont_Printf(void);

extern struct S_D_800DF7D8 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; u8 f_20; u8 f_21; u8 f_22; } D_800DF7D8;



INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A6460);

void func_8008C390(void) {
    D_800DF7D8.f_0 = 0;
    D_800DF7D8.f_4 = 0x10;
    D_800DF7D8.f_8 = 0;
    D_800DF7D8.f_C = 0;
    D_800DF7D8.f_20 = 0x80;
    D_800DF7D8.f_21 = 0x80;
    D_800DF7D8.f_22 = 0x80;
}

void func_8008C3C0(s32 arg0, s32 arg1) {
    D_800DF7D8.f_0 = arg0;
    D_800DF7D8.f_4 = arg1;
    D_800DF7D8.f_8 = 0;
    D_800DF7D8.f_C = 0;
}

void func_8008C3DC(void) {
    D_800DF7D8.f_10 = (s32) D_800DF7D8.f_0;
    D_800DF7D8.f_14 = (s32) D_800DF7D8.f_4;
    D_800DF7D8.f_18 = (s32) D_800DF7D8.f_8;
    D_800DF7D8.f_1C = (s32) D_800DF7D8.f_C;
}

void func_8008C408(void) {
    D_800DF7D8.f_0 = (s32) D_800DF7D8.f_10;
    D_800DF7D8.f_4 = (s32) D_800DF7D8.f_14;
    D_800DF7D8.f_8 = (s32) D_800DF7D8.f_18;
    D_800DF7D8.f_C = (s32) D_800DF7D8.f_1C;
}

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_PutChar);

typedef char *va_list_8C474;
#define VA_START(ap, last) (ap = (va_list_8C474)&last + 4)
#define VA_ARG(ap, t) (*(t *)((ap += 4) - 4))
typedef struct { u8 pad0[0x82BA]; s16 debugText; } GameDbg_8C474;
extern s32 D_800DF7FC;
extern s32 D_800DF800;
void DebugFont_PutChar(s32 c);
void DebugFont_Printf_Va(s8 *fmt, ...) asm("DebugFont_Printf");

/* Debug-font printf. The font uses the game's text codes (ASCII - 0x20): `\n` starts a new line,
   "`N" switches to colour N, %d (with an optional width digit, right-aligned), %x, %s (which may
   contain "`N" too) and %c. Ends with a draw-mode primitive (texture page D_800DF800) linked into the
   HUD ordering table. Prints nothing unless g_Game + 0x82BA is set. */
void DebugFont_Printf_Va(s8 *fmt, ...) {
    s8 buf[32];
    va_list_8C474 ap;
    u32 *ot;
    s32 width;
    s32 i, n, neg;
    s32 c;
    s32 v;
    u32 u, u2;
    s8 *s;
    u32 *p;

    width = 0;
    ot = G_HUD_OT;
    if (((GameDbg_8C474 *)&g_Game)->debugText != 0) {
        VA_START(ap, fmt);
        D_800DF800 = 0x1F;
        D_800DF7FC = 0;
        c = fmt[0];
        i = 1;
        while (c != 0) {
            switch (c) {
            case '\n':
                D_800DF7D8.f_8 = 0;
                D_800DF7D8.f_C++;
                break;
            case '`':
                D_800DF7FC = fmt[i++] - '0';
                break;
            case '%':
                c = fmt[i++];
                if ((u32)(c - '1') < 9) {
                    width = c - '0';
                    c = fmt[i++];
                }
                switch (c) {
                case 'd':
                    n = 0;
                    v = VA_ARG(ap, s32);
                    neg = 0;
                    if (v < 0) {
                        neg = 1;
                        v = -v;
                    }
                    do {
                        buf[n++] = v % 10 + 0x10;
                        v /= 10;
                    } while (v != 0);
                    if (neg) {
                        buf[n++] = '-' - 0x20;
                    }
                    if (width != 0) {
                        D_800DF7D8.f_8 += (width - n) * 8;
                    }
                    for (n--; n >= 0; n--) {
                        width = 0;
                        DebugFont_PutChar(buf[n]);
                    }
                    break;
                case 'x':
                    n = 0;
                    u = VA_ARG(ap, u32);
                    do {
                        u2 = u & 0xF;
                        buf[n++] = u2 < 10 ? u2 + 0x10 : u2 + 0x17;
                        u >>= 4;
                    } while (u != 0);
                    for (n--; n >= 0; n--) {
                        DebugFont_PutChar(buf[n]);
                    }
                    break;
                case 's':
                    s = VA_ARG(ap, s8 *);
                    while (*s != 0) {
                        if (*s == '`') {
                            s++;
                            D_800DF7FC = *s++ - '0';
                        }
                        DebugFont_PutChar(*s++ - 0x20);
                    }
                    break;
                case 'c':
                    DebugFont_PutChar(VA_ARG(ap, s32) - 0x20);
                    break;
                }
                break;
            default:
                DebugFont_PutChar(c - 0x20);
                break;
            }
            c = fmt[i++];
        }
        p = (u32 *)G_DRAW.prim;
        ((u8 *)p)[3] = 1;
        p[1] = (D_800DF800 & 0x9FF) | 0xE1000200;
        p[0] = (p[0] & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        G_DRAW.prim = (u8 *)(p + 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawBox);

void func_8008CBFC(s32 a0, ...) {
    s32 old = g_Game.unk82BA;
    g_Game.unk82BA = 1;
    DebugFont_Printf();
    func_8008C3C0(0, 0);
    g_Game.unk82BA = old;
}

void func_8008CC60(s32 arg0, s32 arg1) {
    func_8008C3C0(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawWord);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", DebugFont_DrawIcon);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", func_8008D064);

INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", MinigameMenu_Main);

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A6464);


INCLUDE_ASM("asm/nonmatchings/game/8008C390_debug_font", MinigameMenu_Update);

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A646C);
INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A647C);

