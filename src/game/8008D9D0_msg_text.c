#include "common.h"
#include "m2c_macros.h"

extern u8 Msg_GlyphWidths[];
u8 *Msg_ReadChar(u8 *p, u16 *out);

M2C_UNK Msg_PutChar(u16, M2C_UNK, M2C_UNK);

extern M2C_UNK Msg_Cursor;

extern u8 g_Game_8D9D0[] asm("g_Game");
#define G_DRAW_8D9D0 (*(GameDraw *)g_Game_8D9D0)
typedef struct { u16 x, y, x0; } MsgCur_8D9D0;
extern MsgCur_8D9D0 D_800DF810_8D9D0 asm("Msg_Cursor");
typedef struct { u16 clut, uv, w, h; } Glyph_8D9D0;
extern Glyph_8D9D0 Msg_Glyphs[];
extern Glyph_8D9D0 D_800B37A0;
extern Glyph_8D9D0 D_800B37C0;
typedef struct { u32 tag; u32 tpage; u32 rgbc; u32 xy; u32 uvclut; u32 wh; } SprtTp_8D9D0;
typedef struct { u32 addr : 24; u32 len : 8; } PT_8D9D0;
#define CUR_8D9D0 D_800DF810_8D9D0

M2C_UNK Msg_PutChar(u16 c, M2C_UNK pal, M2C_UNK unused) {
    SprtTp_8D9D0 *p;
    u32 *ot;
    u16 x; s32 y; s32 yy, i;
    Glyph_8D9D0 *g;
    u32 uv;

    if (c == 0xD) {
        CUR_8D9D0.x = CUR_8D9D0.x0;
        CUR_8D9D0.y += 0x12;
        return;
    }
    __asm__("" :: "r"((s32)c));
    if (!(c & 0xFF00) && (u8)c < 0x10) {
        return;
    }
    x = CUR_8D9D0.x;
    y = CUR_8D9D0.y;
    p = (SprtTp_8D9D0 *)G_DRAW_8D9D0.prim;
    ot = G_DRAW_8D9D0.db[G_DRAW_8D9D0.cur].hud;
    if (c & 0x100) { u32 mm; u32 hh;
        g = &Msg_Glyphs[c & 0xFF];
        yy = y;
        if ((c & 0xFF) == 0xB) {
            yy = y - 5;
            if (*(u32 *)g_Game_8D9D0 & 8) {
                g++;
            }
        }
        ((u8 *)p)[3] = 5;
        p->rgbc = 0x65000000;
        p->tpage = 0xE1000217;
        __asm__ ("" : "=r"(hh) : "0"(0xFF000000));         __asm__ ("" : "=r"(mm) : "0"(0xFF0000)); mm |= 0xFFFF;         p->xy = (((s16)yy - ((u32)(g->h - 0x10) >> 1)) << 16) | (x & 0xFFFF);
        p->wh = *(u32 *)&g->w;
        p->uvclut = g->uv | (g->clut << 16);
        p->tag = (p->tag & hh) | (*ot & mm);
        *ot = (*ot & hh) | ((u32)p & mm);
        p++;
        { s32 t = g->w + 2; x += t; }
    } else if (c & 0x200) {
        if ((u32)((c & 0xFF) - 1) < 10) {
            g = &D_800B37A0;
        } else {
            g = &D_800B37C0;
        }
        ((u8 *)p)[3] = 5;
        p->rgbc = 0x65000000;
        p->tpage = 0xE1000217;
        p->xy = ((y << 16) + 0xFFFF0000) | (((s16)x - 4) & 0xFFFF);
        p->wh = *(u32 *)&g->w;
        p->uvclut = g->uv | (g->clut << 16);
        ((PT_8D9D0 *)p)->addr = ((PT_8D9D0 *)ot)->addr;
        ((PT_8D9D0 *)ot)->addr = (u32)p;
        p++;
        { s32 t = g->w + 1; x += t; }
    } else {
        for (i = 0; i < 2; i++) {
            ((u8 *)p)[3] = 5;
            p->tpage = 0xE1000257;
            p->rgbc = 0x67000000;
            p->xy = (y << 16) | (((s16)x + i) & 0xFFFF);
            p->wh = Msg_GlyphWidths[c] | 0x100000;
            p->uvclut = ((c << 8) & 0x7000) | ((c % 16) << 4) | ((((pal + (c >> 7)) << 6) | 0x1C) << 16);
            ((PT_8D9D0 *)p)->addr = ((PT_8D9D0 *)ot)->addr;
            ((PT_8D9D0 *)ot)->addr = (u32)p;
            p++;
        }
        __asm__("" :: "r"(ot), "r"(ot));
        x += Msg_GlyphWidths[c];
        if (c != 0xCC && c != 0xCE) {
            x++;
        }
    }
    CUR_8D9D0.x = x;
    G_DRAW_8D9D0.prim = (u8 *)p;
    __asm__("" :: "r"(c), "r"(c), "r"(c), "r"(c), "r"(c), "r"(c), "r"(c), "r"(c), "r"(c));
    __asm__("" :: "r"(c), "r"(c), "r"(c));
}

u8 *Msg_ReadChar(u8 *p, u16 *out) {
    u16 c = *p++;
    if (c == 10) {
        c = *p++ | 0x100;
    } else if (c == 11) {
        c = *p++ | 0x200;
    }
    *out = c;
    return p;
}

void Msg_SetPos(s16 arg0, s16 arg1) {
    M2C_FIELD(&Msg_Cursor, s16 *, 0) = arg0;
    M2C_FIELD(&Msg_Cursor, s16 *, 4) = arg0;
    M2C_FIELD(&Msg_Cursor, s16 *, 2) = arg1;
}

void Msg_DrawString(s32 arg0)
{
  u16 sp10;
  s32 temp_s0;
  temp_s0 = arg0;
  loop_1:
  temp_s0 = Msg_ReadChar(temp_s0, &sp10);

  if (sp10 != 0)
  {
    Msg_PutChar(sp10, 0x1F0, 0);
    temp_s0 = temp_s0;
    goto loop_1;
  }
}

/* Same as Text_GetWidth with the width table Msg_GlyphWidths (another font). */
s32 Text_GetWidth2(u8 *s) {
    s32 w = 0;
    while (*s != 0 && *s != 0xD) {
        w += Msg_GlyphWidths[*s++];
    }
    return w;
}

s32 Msg_GetWidthUntil(u8 *p, u16 end) {
    s32 sum = 0;
    u16 c;
    while (1) {
        p = Msg_ReadChar(p, &c);
        if (c == end) {
            break;
        }
        sum += Msg_GlyphWidths[c];
    }
    return sum;
}
