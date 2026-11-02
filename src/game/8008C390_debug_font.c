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

extern u8 g_Game_8CC80[] asm("g_Game");
#define G_DRAW_8CC80 (*(GameDraw *)g_Game_8CC80)
typedef struct { u32 addr : 24; u32 len : 8; } PTag_8CC80;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8CC80;
typedef struct { u32 tag; u32 code; } DrTpage_8CC80;
typedef struct { u16 x; u16 pad; u16 y; } DbgCursor_8CC80;
extern s16 D_800B34BC[][12];
extern u8 D_800B3450[][2];
extern DbgCursor_8CC80 D_800DF7D8_8CC80 asm("D_800DF7D8");
#define ADD_PRIM_C_8CC80(ot, p) (((PTag_8CC80 *)(p))->addr = ((PTag_8CC80 *)(ot))->addr, ((PTag_8CC80 *)(ot))->addr = (u32)(p))

/* Draws word `word` of the debug font's word table D_800B34BC (rows of glyph ids, ended by a
   negative id) at the debug console cursor D_800DF7D8: 24x24 glyphs (id 21 is 32x16, ids >= 30
   16x16), id 49 doesn't advance. Words 0-6 use texture page 0x298, the rest 0x20D. */
void DebugFont_DrawWord(s16 word) {
    Sprt_8CC80 *p = (Sprt_8CC80 *)G_DRAW_8CC80.prim;
    u32 *ot = (G_DRAW_8CC80.db[G_DRAW_8CC80.cur].hud);
    s16 i;
    s32 x = 0;
    s32 w, h;
    s16 c;
    DrTpage_8CC80 *t;

    for (i = 0; D_800B34BC[word][i] >= 0; i++) {
        c = D_800B34BC[word][i];
        *(u32 *)&p->r0 = 0x808080;
        ((u8 *)p)[3] = 4;
        p->code = 0x64;
        if (c < 30) {
            if (c == 21) {
                w = 0x20;
                h = 0x10;
            } else {
                w = h = 0x18;
            }
            p->clut = 0x3C9C;
        } else {
            w = h = 0x10;
            p->clut = 0x1874;
        }
        p->u0 = D_800B3450[c][0];
        p->v0 = D_800B3450[c][1];
        if (c == 21) {
            p->w = w;
            p->h = h;
            p->x0 = D_800DF7D8_8CC80.x + x;
            p->y0 = D_800DF7D8_8CC80.y + 8;
        } else {
            p->w = w;
            p->h = h;
            p->x0 = D_800DF7D8_8CC80.x + x;
            p->y0 = D_800DF7D8_8CC80.y;
        }
        ADD_PRIM_C_8CC80(ot, p);
        p++;
        if (c != 49) {
            x += w;
        }
    }
    { u32 code;
    if (word < 7) { __asm__("" : "=r"(t) : "0"(p)); code = 0xE1000298; } else { __asm__("" : "=r"(t) : "0"(p)); code = 0xE100020D; }
    ((u8 *)t)[3] = 1;
    t->code = code; }
    __asm__ volatile("");
    ADD_PRIM_C_8CC80(ot, t);
    t++;
    G_DRAW_8CC80.prim = (void *)t;
}

typedef struct { u16 x, px, y, py; } Con16_8CF04;
#define C16 (*(Con16_8CF04 *)&D_800DF7D8)
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_8CF04;
typedef struct { P_TAG_8CF04 tag; u32 rgbc; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8CF04;
typedef struct { P_TAG_8CF04 tag; u32 code; } DrTpage_8CF04;

void DebugFont_DrawIcon(s16 n) {
    Sprt_8CF04 *p = (Sprt_8CF04 *)G_DRAW.prim;
    u32 *ot = G_HUD_OT;
    s32 r;
    s16 col;

    p->rgbc = 0x808080;
    p->tag.len = 4;
    ((u8 *)p)[7] = 0x64;
    p->clut = 0x3FDC;
    p->w = 0x18;
    p->h = 0x18;
    p->u0 = (n % 5) * 24;
    p->v0 = (n / 5) * 24 - 0x80;
    p->x0 = C16.x;
    p->y0 = C16.y;
    p->tag.addr = ((P_TAG_8CF04 *)ot)->addr;
    ((P_TAG_8CF04 *)ot)->addr = (u32)p;
    p++;
    {
        DrTpage_8CF04 *t = (DrTpage_8CF04 *)p;
        t->tag.len = 1;
        t->code = 0xE100028D;
        t->tag.addr = ((P_TAG_8CF04 *)ot)->addr;
        ((P_TAG_8CF04 *)ot)->addr = (u32)t;
        t++;
        G_DRAW.prim = (u8 *)t;
    }
}

extern void *D_800DF7A0[8];
extern s16 D_800DF7C0[8];
extern u8 D_800DF7D0[8];
extern u8 D_800B35C4;
void DebugFont_Printf_8D064(void *fmt, s16 v) asm("DebugFont_Printf");

/* Timed debug messages: a == -1 clears the 8-slot ring; p == NULL ages every queued message one frame
   (saturating at 255) and prints those younger than 80 frames; otherwise queues format p with value a. */
void func_8008D064(void *p, s32 a) {
    s32 i;
    if (a == -1) {
        for (i = 7; i >= 0; i--) {
            D_800DF7A0[i] = 0;
        }
        D_800B35C4 = 0;
    } else if (p == 0) {
        for (i = 0; i < D_800B35C4; i++) {
            if (D_800DF7A0[i] != 0) {
                { u8 *q = &D_800DF7D0[i]; *q = *q + (*q ? *q < 0xFF : 0); }
                if (D_800DF7D0[i] < 0x50) {
                    DebugFont_Printf_8D064(D_800DF7A0[i], D_800DF7C0[i]);
                }
            }
        }
    } else {
        D_800DF7A0[D_800B35C4] = p;
        D_800DF7C0[D_800B35C4] = a;
        D_800DF7D0[D_800B35C4] = 1;
        D_800B35C4 = (D_800B35C4 + 1) % 8;
    }
}

typedef struct { s16 x, y, w, h; } RECT_8D1F0;
typedef struct { u8 pad0[0x18]; u8 isbg; u8 pad19[0x43]; u8 disp[0x14]; } Env_8D1F0;
typedef struct { Env_8D1F0 env; u32 ot[0x1000]; u32 hud[2]; } Db_8D1F0;
typedef struct { u32 frame; u8 *prim; u32 *ot; s32 cur; Db_8D1F0 db[2]; u8 pad8100[0x20]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x34]; u16 f_815C; } Game_8D1F0;
extern u32 g_GameW_8D1F0 asm("g_Game");
#define G_8D1F0 (*(Game_8D1F0 *)&g_GameW_8D1F0)
extern RECT_8D1F0 D_800A6464;
extern s32 D_800B35D0;
extern s32 D_800B35D4[];
extern s32 D_800B3600[];
extern s32 D_800B3618;
extern s32 D_800B361C;
extern s32 D_800B3620[];
void Gfx_InitDisplay(void);
void ResetGraph(s32);
s32 ClearImage(void *, s32, s32, s32);
void DrawSync(s32);
void VSync(s32);
void PutDispEnv(void *);
void PutDrawEnv(void *);
void DrawOTag(void *);
void Gfx_BeginFrame(void);
void func_8001325C(s32);
void func_8008C390(void);
s32 MinigameMenu_Update(void);
void Minigame_Run(s32);
void Cd_ReadFile(s32, s32);
void Cd_WaitIdle(s32);
void Cd_StartFileLoad(s32, s32);
void Cd_Update(void);
s32 func_800116C0(void);
s32 Stage_ResetActors(s32);
void func_80136074(s32);
void func_80137654(void);

s32 MinigameMenu_Main(void) {
    RECT_8D1F0 r[2];
    register s32 sel asm("$16");

    r[0] = D_800A6464;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r[0], 0, 0, 0);
    DrawSync(0);
    G_8D1F0.db[1].env.isbg = 1;
    G_8D1F0.db[0].env.isbg = 1;
    G_8D1F0.cur = 0;
    D_800B3620[3] = D_800B35D4[D_800B3618];
    D_800B35D0 = 0;
    D_800B3620[4] = D_800B3600[D_800B361C];
    while (1) {
        func_8001325C(0);
        Gfx_BeginFrame();
        func_8008C390();
        sel = MinigameMenu_Update();
        if (sel >= 0) {
            break;
        }
        DrawSync(0);
        VSync(0);
        g_GameW_8D1F0++;
        PutDispEnv(G_8D1F0.db[G_8D1F0.cur].env.disp);
        PutDrawEnv(&G_8D1F0.db[G_8D1F0.cur].env);
        DrawOTag(&G_8D1F0.db[G_8D1F0.cur].ot[0xFFF]);
    }
    if (sel != 999) {
        if (sel < 2) {
            Minigame_Run(sel);
        } else switch (sel) {
        case 3:
            Cd_ReadFile(0x180, 0x80136000);
            Cd_WaitIdle(0);
            func_80136074(D_800B3618);
            G_8D1F0.mode = sel;
            break;
        case 2:
            Cd_ReadFile(0x1AB, 0x80136000);
            Cd_WaitIdle(0);
            func_80137654();
            G_8D1F0.mode = 3;
            break;
        case 4:
            G_8D1F0.stage = D_800B361C + 0x63;
            G_8D1F0.mode = 0x24;
            G_8D1F0.f_815C = D_800B361C;
            Stage_ResetActors(G_8D1F0.stage);
            Cd_StartFileLoad(1, G_8D1F0.stage);
            while (func_800116C0() == 0) {
                Cd_Update();
                VSync(2);
            }
            break;
        }
    } else {
        G_8D1F0.mode = 3;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A6464);


/* entry 0 (the back) of the current buffer's world OT, addressed from g_Game + 0x80 */
#define OT_8D514 (*(PT_8D514 *)(G_DRAW.cur * 0x4078 + ((u8 *)&G_DRAW + 0x80)))
#define P_8D514 ((PolyG4_8D514 *)G_DRAW.prim)
typedef struct { u32 addr : 24; u32 len : 8; } PT_8D514;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4_8D514;
typedef struct { u8 pad0[0x158]; s32 held; u8 pad15C[4]; s32 pressed; } Pad_8D514;
extern Pad_8D514 g_Pad_8D514 asm("g_Pad");
extern char D_800A646C[];
extern char D_800A647C[];
extern s32 D_800B35D0;
extern s32 D_800B35D4[];
extern s32 D_800B3600[];
extern s32 D_800B3618;
extern s32 D_800B361C;
extern s32 D_800B3620[];
extern s32 D_800B362C;
extern s32 D_800B3630;
void func_8008CC60(s32, s32);
s32 Sound_PlayFixed(s32);

/* The minigame menu (two rows of D_800B3620 text under the D_800A646C title, a translucent Gouraud
   bar behind the selected row). Start returns the row (MinigameMenu_Main runs that minigame),
   Select returns 999 (back), up/down move the cursor. Returns -1 while nothing is chosen. The cursor
   only reaches rows 0-1, so the left/right selectors for rows 3 and 4 (D_800B35D4 / D_800B3600 lists)
   never run. */
s32 MinigameMenu_Update(void) {
    s32 i;
    s32 btn;

    func_8008CC60(0x82, 0x46);
    func_8008CBFC(D_800A646C);
    for (i = 0; i < 2; i++) {
        func_8008CC60(0xA0, i * 0xF + 0x6C);
        func_8008CBFC(D_800A647C, D_800B3620[i]);
    }

    ((u8 *)P_8D514)[3] = 8;
    P_8D514->code = 0x38;
    P_8D514->code |= 2;
    P_8D514->x0 = 0x90;
    {s32 by = D_800B35D0 * 0xF;
    P_8D514->y0 = by + 0x6E;
    P_8D514->x1 = 0x108;
    P_8D514->y1 = by + 0x6E;
    P_8D514->x2 = 0x90;
    P_8D514->y2 = by + 0x75;
    P_8D514->x3 = 0x108;
    P_8D514->y3 = by + 0x75;}
    P_8D514->r0 = 0xF5;
    P_8D514->g0 = 0xDC;
    P_8D514->b0 = 0xC8;
    P_8D514->r1 = 0xE6;
    P_8D514->g1 = 0x46;
    P_8D514->b1 = 0x28;
    P_8D514->r2 = 0xC4;
    P_8D514->g2 = 0x46;
    P_8D514->b2 = 0x3C;
    P_8D514->r3 = 0x5F;
    P_8D514->g3 = 0xA;
    P_8D514->b3 = 8;
    ((PT_8D514 *)P_8D514)->addr = OT_8D514.addr;
    OT_8D514.addr = (u32)P_8D514;
    G_DRAW.prim = (u8 *)(P_8D514 + 1);
    if ((g_Pad_8D514.pressed & g_Pad_8D514.held) & 0x800) {
        Sound_PlayFixed(2);
        if (D_800B35D0 < 2) {
            return D_800B35D0;
        }
    } else if ((g_Pad_8D514.pressed & g_Pad_8D514.held) & 0x100) {
        Sound_PlayFixed(2);
        return 999;
    } else if ((g_Pad_8D514.pressed & g_Pad_8D514.held) & 0x1000) {
        Sound_PlayFixed(0);
        if (--D_800B35D0 < 0) {
            D_800B35D0 = 1;
        }
    } else if ((g_Pad_8D514.pressed & g_Pad_8D514.held) & 0x4000) {
        Sound_PlayFixed(0);
        if (++D_800B35D0 >= 2) {
            D_800B35D0 = 0;
        }
    }
    if (D_800B35D0 == 3) {
        for (i = 0; D_800B35D4[i] != 0; i++) {
        }
        btn = g_Pad_8D514.pressed & g_Pad_8D514.held;
        i--;
        if (btn & 0x8000) {
            D_800B3618--;
        } else if (btn & 0x2000) {
            D_800B3618++;
        }
        if (D_800B3618 < 0) {
            D_800B3618 = 0;
        } else if (i < D_800B3618) {
            D_800B3618 = i;
        }
        D_800B362C = D_800B35D4[D_800B3618];
    }
    if (D_800B35D0 == 4) {
        for (i = 0; D_800B3600[i] != 0; i++) {
        }
        btn = g_Pad_8D514.pressed & g_Pad_8D514.held;
        i--;
        if (btn & 0x8000) {
            D_800B361C--;
        } else if (btn & 0x2000) {
            D_800B361C++;
        }
        if (D_800B361C < 0) {
            D_800B361C = 0;
        } else if (i < D_800B361C) {
            D_800B361C = i;
        }
        D_800B3630 = D_800B3600[D_800B361C];
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A646C);
INCLUDE_RODATA("asm/nonmatchings/game/8008C390_debug_font", D_800A647C);

