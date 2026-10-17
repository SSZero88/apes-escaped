#include "common.h"
#include "m2c_macros.h"

typedef struct { u8 state; u8 timer; s16 size; u8 u, v, w, h; u16 clut; u16 tpage; } CenterSign;
extern CenterSign g_CenterSign;


void CenterSign_ShowDigit(s32 a) {
    g_CenterSign.state = a;
    g_CenterSign.timer = 0x10;
    g_CenterSign.size = 0xFA;
    g_CenterSign.u = (a - 2) << 5;
    g_CenterSign.v = 0x60;
    g_CenterSign.w = 0x1F;
    g_CenterSign.h = 0x1F;
    g_CenterSign.clut = 0x7DAD;
    g_CenterSign.tpage = 0x3B;
    if (a == 1) {
        g_CenterSign.u = 0x60;
        g_CenterSign.w = 0x9F;
    }
}

void CenterSign_ShowSpecterCoin(void) {
    g_CenterSign.state = 1;
    g_CenterSign.timer = 0x18;
    g_CenterSign.size = 0xFA;
    g_CenterSign.u = 0xC0;
    g_CenterSign.v = 0x80;
    g_CenterSign.w = 0x3E;
    g_CenterSign.h = 0x3E;
    g_CenterSign.clut = 0x7E2D;
    g_CenterSign.tpage = 0x1B;
}

extern u8 g_Game[];
extern u8 *D_800EC354;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_983E8;
typedef struct { u32 tag; u32 rgbc; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2, pad2; u32 xy3; u16 uv3, pad3; } PolyFT4_983E8;
extern u8 g_SpecterCoinTimer;
s32 Game_IsTimed(void);
#define ADD_PRIM_C(ot, p) (((PTag_983E8 *)(p))->addr = ((PTag_983E8 *)(ot))->addr, ((PTag_983E8 *)(ot))->addr = (u32)(p))

/* Centre-screen sign (g_CenterSign: time-limit seconds via CenterSign_ShowDigit, the Specter coin sign (user)
   via CenterSign_ShowSpecterCoin), drawn in races or while g_SpecterCoinTimer runs: a centred semi-transparent
   quad with up to 4 shrinking afterimages while `size` halves each frame; when the timer runs out it switches to state 5
   (zooming out and fading for 8 frames), then clears. g_SpecterCoinTimer draws it bigger and brighter. */
void CenterSign_Draw(void) {
    s32 big = 0;
    PolyFT4_983E8 *p;
    u32 *ot;
    s32 n;
    s32 a;
    s32 c, w, h, x, y;

    if (g_SpecterCoinTimer != 0) {
        big = 1;
    } else if (Game_IsTimed() == 0) {
        return;
    }
    if (g_CenterSign.state == 0) {
        return;
    }
    if (--g_CenterSign.timer == 0) {
        if (g_CenterSign.state == 5) {
            g_CenterSign.state = 0;
            return;
        }
        g_CenterSign.state = 5;
        g_CenterSign.timer = 8;
        g_CenterSign.size = 0xFF;
    }

    n = 4;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    a = g_CenterSign.size;
    p = (PolyFT4_983E8 *)G_DRAW.prim;
    do {
        if (g_CenterSign.state == 5) {
            w = (0xFF - a) * 2 + 0x100;
            n = 0;
            c = g_CenterSign.timer * 8 + 0x40;
            h = (g_CenterSign.timer >> 1) + 1;
        } else {
            c = 0x80 - g_CenterSign.timer * 8;
            if (!big) {
                w = g_CenterSign.w + a;
                h = g_CenterSign.h + a;
            } else {
                w = g_CenterSign.w * 2 + a;
                h = ((g_CenterSign.h * 3) >> 1) + a;
            }
        }
        if (big) {
            c = 0xC4;
        }
        ((u8 *)p)[3] = 9;
        p->rgbc = (c << 16) | (c << 8) | c | 0x2E000000;
        x = 0xC0 - w / 2;
        y = 0x78 - h / 2;
        p->xy0 = (y << 16) | (x & 0xFFFF);
        p->xy1 = (y << 16) | ((x + w) & 0xFFFF);
        p->xy2 = ((y + h) << 16) | (x & 0xFFFF);
        p->xy3 = ((y + h) << 16) | ((x + w) & 0xFFFF);
        p->uv0 = ((g_CenterSign.v << 8) | g_CenterSign.u) | (g_CenterSign.clut << 16);
        p->uv1 = ((g_CenterSign.v << 8) | (g_CenterSign.u + g_CenterSign.w)) | (g_CenterSign.tpage << 16);
        a >>= 1;
        p->uv2 = g_CenterSign.u | ((g_CenterSign.v + g_CenterSign.h) << 8);
        p->uv3 = ((g_CenterSign.v + g_CenterSign.h) << 8) | (g_CenterSign.u + g_CenterSign.w);
        ADD_PRIM_C(ot, p);
        p++;
    } while (a != 0 && --n > 0);
    D_800EC354 = (u8 *)p;
    g_CenterSign.size >>= 1;
}
