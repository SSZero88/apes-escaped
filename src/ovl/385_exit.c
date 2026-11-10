#include "common.h"
#include "m2c_macros.h"

extern u8 CdCheck_Params[];
extern u8 CdCheck_Result;
extern u8 D_80137230_b asm("CdCheck_Params");
extern u8 D_80137239;
s32 CdCheck_SendCommand(s32);
void CdCheck_ShowExitScreen(void);
s32 VSync(s32);

s32 CdCheck_Run(s32 a, s32 b, s32 c) {
    register s32 ret asm("s0") = 0;
    u8 *p;
    u8 *q;
    u8 pad[8];

    D_80137230_b = 0x20;
    if (CdCheck_SendCommand(5) < 0) goto fail;
    if (CdCheck_SendCommand(0) < 0) goto fail;
    if (CdCheck_Result & 0xF0) goto fail;
    if (!(CdCheck_Result & 2)) {
        if (CdCheck_SendCommand(1) < 0) goto fail;
    }
    __asm__("" : "=r"(p) : "0"(CdCheck_Params));
    p[0] = a;
    p[1] = b;
    p[2] = c;
    if (CdCheck_SendCommand(2) < 0) goto fail;
    p[0] = 1;
    if (CdCheck_SendCommand(4) < 0) goto fail;
    VSync(3);
    if (CdCheck_SendCommand(3) < 0) goto fail;
    if (CdCheck_SendCommand(6) < 0) goto fail;
    if (CdCheck_SendCommand(7) < 0) goto fail;
    p[0] = 4;
    if (CdCheck_SendCommand(8) < 0) goto fail;
    VSync(200);
    p[0] = 5;
    if (CdCheck_SendCommand(8) < 0) goto fail;
    __asm__("" : "=r"(q) : "0"(&D_80137239));
    if (*q) {
        if (CdCheck_SendCommand(0) < 0) goto fail;
        if (q[-1] & 0x10) {
fail:
            ret = -1;
        } else {
            CdCheck_ShowExitScreen();
        }
    }
end:
    if (CdCheck_SendCommand(9) < 0) ret = -1;
    return ret;
}

extern u8 CdCheck_Commands[][4];
extern volatile u8 *D_80137220;
extern volatile u8 *D_80137224;
extern volatile u8 *D_80137228;
extern volatile u8 *D_8013722C;
extern u8 CdCheck_Params[];
extern u8 D_80137238_t[] asm("CdCheck_Result");

static inline void Ack_80136AEC(void) {
    s32 i;
    s32 *p;

    *D_80137220 = 1;
    *D_8013722C = 7;
    for (i = 0, p = 0; i < 4; i++) *p = i;
}

s32 CdCheck_SendCommand(s32 n) {
    s32 i;
    s32 total;
    u8 nw;
    register s32 st asm("$5");
    s32 a;
    s32 err;
    volatile u8 *q;
    register s32 ret asm("$2");

    Ack_80136AEC();
    *D_80137220 = 1;
    *D_80137228 = 0x18;
    *D_80137220 = 0;
    {
        s32 n4 = n * 4;
        i = 0;
        if (((u8 *)CdCheck_Commands + 1)[n4] != 0) do { *D_80137228 = CdCheck_Params[i]; i++; } while (i < ((u8 *)CdCheck_Commands + 1)[n4]);
    }
    *D_80137220 = 0;
    *D_80137224 = CdCheck_Commands[n][0];
    __asm__("" : : "r"(n), "r"(n));
    st = 0;
    total = 0;
    nw = CdCheck_Commands[n][3];
    if (nw != 0) do {
        *D_80137220 = 1;
        q = D_8013722C;
        do { a = *q & 7; st = a; } while (a != (*q & 7));
        if ((u8)st) {
            total += (u8)st;
            Ack_80136AEC();
        }
    } while (total < nw);
    err = 0;
    if (st == 5) {
        err = -1;
        __asm__ volatile("");
    }
    if (err < 0) {
        ret = -1;
    } else {
        i = 0;
        if (CdCheck_Commands[n][2] != 0) do { D_80137238_t[i] = *D_80137224; i++; } while (i < CdCheck_Commands[n][2]);
        ret = 0;
    }
    *D_80137220 = 1;
    *D_80137228 = 0x1F;
    return ret;
}

typedef struct { s16 x, y, w, h; } RECT_80136D18;
typedef struct { RECT_80136D18 clip; s16 ofs[2]; RECT_80136D18 tw; u16 tpage; u8 dtd, dfe, isbg, r0, g0, b0; u32 dr_env[16]; } DRAWENV_80136D18;
typedef struct { RECT_80136D18 disp; RECT_80136D18 screen; u8 isinter, isrgb24, pad0, pad1; } DISPENV_80136D18;
s32 ResetGraph(s32 mode);
s32 StopCallback(void);
void *SetDefDrawEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void *SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
s32 GetVideoMode(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawPrim(void *p);
void SetDispMask(s32 mask);
void bios_exit(void);
void CdCheck_DrawKanjiText();
void CdCheck_DrawIcon(void);
extern s32 D_80137270_w asm("D_80137270");
extern u8 CdCheck_Message[];

void CdCheck_ShowExitScreen(void) {
    DRAWENV_80136D18 draw;
    DISPENV_80136D18 disp;
    u32 prim[4];
    RECT_80136D18 r;
    s32 i;

    ResetGraph(3);
    StopCallback();
    ResetGraph(0);
    SetDefDrawEnv(&draw, 0, 0, 0x140, 0xF0);
    SetDefDispEnv(&disp, 0, 0, 0x140, 0xF0);
    {
        s32 m = GetVideoMode();
        s32 one = 1;
        if (m == one) {
            disp.screen.y = 0x11;
        }
        draw.isbg = one;
    }
    draw.r0 = 0;
    draw.g0 = 0;
    draw.b0 = 0;
    PutDrawEnv(&draw);
    PutDispEnv(&disp);
    prim[0] = 0x02000000;
    prim[1] = 0xE6000002;
    prim[2] = 0;
    DrawPrim(prim);
    D_80137270_w = 0xFFFF;
    for (i = 0; i < 2; i++) {
        r.x = i + 0x50;
        r.h = 0xF;
        r.w = 0x10;
        r.y = i + 0x5C;
        CdCheck_DrawKanjiText(CdCheck_Message, &r);
        D_80137270_w = 0x8000;
    }
    CdCheck_DrawIcon();
    SetDispMask(1);
    bios_exit();
}

void CdCheck_ExpandGlyph(u16 *dst, u8 *src, u32 range, s32 n);
void DrawSync(s32);




typedef struct { s16 x, y, w, h; } Rect_80136E60;
s32 LoadImage(void *rect, u32 *p);
s32 func_800A3710(u8 *);
s32 func_8002F1E0(s32);

void CdCheck_DrawKanjiText(u8 *s, Rect_80136E60 *r) {
    u32 buf[0x80];
    s32 n;
    s32 x0;
    s32 glyph;
    s32 a, b, z;
    s32 c;
    register u8 *p asm("s1");

    n = func_800A3710(s);
    x0 = r->x;
    for (p = s; p < s + n; p++) {
        if (*p == '\n') {
            r->x = x0;
            r->y += r->h + 3;
            continue;
        }
        if (*p & 0x80) {
            __asm__("" : "=r"(p) : "0"(p));
            c = *p;
            p++;
            a = 7;
            b = 0x1E;
            z = 0;
            glyph = func_8002F1E0(*p | (c << 8));
        }
        __asm__ volatile("" :: "r"(z));
        DrawSync(0);
        CdCheck_ExpandGlyph(buf, glyph, a, b);
        LoadImage(r, buf);
        r->x++;
        LoadImage(r, buf);
        { s16 w = r->w; s16 x = r->x; r->x = x + w; }
    }
}

extern u16 D_80137270;

void CdCheck_ExpandGlyph(u16 *dst, u8 *src, u32 range, s32 n) {
    s32 i;
    s32 b;
    s32 hi = range & 0xFFFF;
    s32 lo = range >> 16;
    register u16 *c asm("$11");

    i = 0;
    if (n > 0) {
        c = &D_80137270;
        do {
            for (b = hi; b >= lo; b--) {
                *dst++ = ((*src >> b) & 1) ? *c : 0;
            }
            src++;
        } while (++i < n);
    }
}

typedef struct { s8 v[4][2]; } Sg_80137014;
extern Sg_80137014 D_801371DC_t asm("D_801371DC");
extern u8 D_80137240[][2];
void DrawPrim(void *p);

void CdCheck_DrawIcon(void) {
    u32 prim[6];
    Sg_80137014 sg;
    s32 i, j, k;

    prim[0] = 0x05000000;
    prim[1] = 0x280000FF;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            sg = D_801371DC_t;
            for (k = 0; k < 4; k++) {
                s32 a = (k + 2) >> 2;
                s32 b = i + (k & 1);
                prim[2 + k] = ((sg.v[j][1] * D_80137240[16 - b][a] + 0x78) << 16) | (sg.v[j][0] * D_80137240[b][a] + 0xA0);
            }
            DrawPrim(prim);
        }
    }
    prim[2] = 0x500070;
    prim[3] = 0x480078;
    prim[4] = 0xA800C8;
    prim[5] = 0xA000D0;
    DrawPrim(prim);
}
