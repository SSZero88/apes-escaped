#include "common.h"
#include "m2c_macros.h"
typedef struct { s16 vx, vy, vz, pad; } SV_5FD80_8005FD80;

extern struct S_D_800EC1E0 { u8 pad0[0xE8]; s16 f_E8; s16 f_EA; u8 padEC[4]; u8 f_F0; } g_Spike;

extern s16 D_800F4DCC;
extern struct S_D_800F4DB0 { u8 pad_0[0x14]; s16 f_14; s16 f_16; u8 pad_18[0x4]; s16 f_1C; u8 pad_1E[0x2]; s32 f_20; } D_800F4DB0;
extern struct S_D_800EC350 { u8 pad0[0x8124]; u16 f_8124; } g_Game;
void func_8005E42C(s32 arg0);
void Hud_DrawBigDigit(s32, s32, s32);
struct Game_5FD80 { u16 f_0; u8 pad2[0x8166]; s16 f_8168; };
extern u8 D_800F4DB2;
extern s8 D_800B0200[];
extern struct S_D_800A5A10 { s32 w[4]; } D_800A5A10;
extern u8 D_800F4D20[];
void Sound_PlayFixed(s32);
void func_800A3740(void *, s32, s32);
void Model_DrawOnScreen(void *, SV_5FD80_8005FD80 *, SV_5FD80_8005FD80 *, struct S_D_800A5A10 *);
struct S_D_800F4DB0_8005FD80 { s16 f_0; u8 f_2; u8 f_3; };

INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", Hud_Draw);

void func_8005E42C(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        D_800F4DCC = 0;
        break;
    case 1:
        if (D_800F4DB0.f_20 & 0x10) {
            if (D_800F4DB0.f_1C >= 0x15) {
                D_800F4DB0.f_1C = 0x14;
            }
        } else {
            D_800F4DB0.f_1C = 0;
        }
        break;
    }
    D_800F4DB0.f_20 = (s32) (D_800F4DB0.f_20 | 0x10);
}

extern s8 D_800B01E0[][2];

/* Health: one 32x32 cookie per point of g_Spike.f_E8 (positions from D_800B01E0, drawn last
   to first), then the 71x63 frame behind them */
void Hud_DrawHealth(void) {
    SprtTp *p = (SprtTp *)G_DRAW.prim;
    u32 *ot = G_HUD_OT;
    s32 i;

    for (i = g_Spike.f_E8 - 1; i >= 0; i--) {
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE100020F;
        p->code = 0x67;
        p->clut = 0x367F;
        p->x0 = D_800B01E0[i][0];
    p->y0 = D_800B01E0[i][1];
        p->w = 0x20;
        p->h = 0x20;
        p->u0 = 0xE0;
        p->v0 = 0x60;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    ((u8 *)p)[3] = 5;
    p->code = 0x67;
    p->u0 = 0x80;
    p->v0 = 0x40;
    p->w = 0x47;
    p->h = 0x3F;
    p->x0 = 0x18;
    p->y0 = 0x26;
    p->tpage = 0xE100021A;
    p->clut = 0x7A2B;
    ADD_PRIM_ASM(ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

extern struct { u32 f; } D_800EC250;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4Tp;

/* Unused debug bar (no callers): a green-to-red Gouraud quad at (10, 40), 8 high, n * 32 wide, where
 * n = 8 - (low nibble of D_800EC250), or 0 when the nibble is 0. Colours: left edge green, right edge
 * (n * 30, ~(n * 30), 0). */
void Debug_DrawBar(void) {
    PolyG4Tp *p = (PolyG4Tp *)G_DRAW.prim;
    s32 n;

    ((u8 *)p)[3] = 9;
    p->code = 0x3A;
    p->tpage = 0xE1000200;
    n = D_800EC250.f & 0xF;
    if (n != 0) {
        n = 8 - n;
    }
    p->x0 = 10;
    p->y0 = 0x28;
    p->x1 = n * 32 + 10;
    p->y1 = 0x28;
    p->x2 = 10;
    p->y2 = 0x30;
    p->x3 = n * 32 + 10;
    p->y3 = 0x30;
    p->r0 = 0;
    p->g0 = 0xFF;
    p->g2 = 0xFF;
    p->b0 = 0;
    p->r2 = 0;
    p->b2 = 0;
    p->r1 = n * 30;
    p->g1 = ~(n * 30);
    p->b1 = 0;
    p->r3 = n * 30;
    p->g3 = ~(n * 30);
    p->b3 = 0;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$4", "$3");
    p++;
    G_DRAW.prim = (u8 *)p;
}

/* Spike loses `dmg` health (floored at 0) and becomes invulnerable for 60 frames;
 * the HUD shows the amount. No damage in stage modes 0x1F/0x20.
 */
void Spike_TakeDamage(s32 dmg) {
    s32 hp;
    if (dmg == 0) {
        return;
    }
    if (g_Game.f_8124 == 0x20) {
        return;
    }
    if (g_Game.f_8124 == 0x1F) {
        return;
    }
    hp = g_Spike.f_E8 - dmg;
    if (hp >= 0) {
        g_Spike.f_E8 = hp;
    } else {
        g_Spike.f_E8 = 0;
    }
    func_8005E42C(1);
    D_800F4DB0.f_14 = dmg;
    D_800F4DB0.f_16 = 12;
    g_Spike.f_EA = 60;
    g_Spike.f_F0 = 1;
}

void Spike_Heal(s32 arg0)
{
  int new_var;
  s16 temp_s0;
  s8 *new_var2;
  new_var2 = (s8 *) (&g_Spike);
  new_var = (*((s16 *) (((s8 *) (&g_Spike)) + 0xE8))) + arg0;
  temp_s0 = new_var;
  func_8005E42C(1);
  if (new_var < 6)
  {
    *((s16 *) (((s8 *) (&g_Spike)) + 0xE8)) = temp_s0;
    return;
  }
  *((s16 *) (new_var2 + 0xE8)) = 5;
}

typedef struct { s16 x, y, w, h; } Rect_5E7EC;
typedef struct { u8 r, g, b, cd; } CVec_5E7EC;
extern Rect_5E7EC D_800A5A00;
extern Rect_5E7EC D_800B98D0[];
void *func_8008C09C(s32 size);
void func_8008C064(void *p);
s32 DrawSync(s32 mode);
s32 LoadImage(void *rect, u32 *p);
s32 StoreImage(void *rect, u32 *p);

/* Depth fog for a texture: saves rect r in D_800B98D0[idx] and builds 7 copies of the image at
   (0x240 + (k % 4) * 16, 0x100 + (k / 4) * 128) with each opaque pixel k/8 of the way to the fog
   colour (k = 1..7). Tex_DrawFogLevels copies them back over the texture at increasing depths. */
void Tex_MakeFogLevels(Rect_5E7EC *r, s32 idx, CVec_5E7EC fog) {
    Rect_5E7EC dst = D_800A5A00;
    s16 *src = func_8008C09C(0x1000);
    u16 *out = func_8008C09C(0x1000);
    s32 fr, fg, fb;
    s32 k, i;
    u16 c;
    s32 stp, cr, cg, cb;
    s32 nr, ng, nb;

    StoreImage(r, (u32 *)src);
    fr = fog.r;
    fg = fog.g;
    fb = fog.b;
    D_800B98D0[idx] = *r;
    DrawSync(0);
    LoadImage(&dst, (u32 *)src);
    for (k = 1; k < 8; k++) {
        for (i = 0; i < r->w * r->h; i++) {
            c = src[i];
            stp = c >> 15;
            cr = (src[i] & 0x1F) << 3;
            cg = (c >> 2) & 0xF8;
            cb = (c >> 7) & 0xF8;
            if (c != 0) {
                nr = cr + (fr - cr) * k / 8;
                ng = cg + (fg - cg) * k / 8;
                nb = cb + (fb - cb) * k / 8;
                nr = (nr < 0) ? 0 : (nr >= 0x100) ? 0xFF : nr;
                ng = (ng < 0) ? 0 : (ng >= 0x100) ? 0xFF : ng;
                nb = (nb < 0) ? 0 : (nb >= 0x100) ? 0xFF : nb;
            } else {
                nr = cr;
                ng = cg;
                nb = cb;
            }
            out[i] = (stp << 15) | ((nb & 0xF8) << 7) | ((ng & 0xF8) << 2) | ((nr & 0xF8U) >> 3);
        }
        dst.x = (k % 4) * 16 + 0x240;
        dst.y = (k / 4) * 128 + 0x100;
        LoadImage(&dst, (u32 *)out);
        DrawSync(0);
    }
    func_8008C064(src);
    func_8008C064(out);
}

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A00);


INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", Tex_DrawFogLevels);

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A08);


typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PolyF4_5EC9C;
extern struct S_D_800E5320 { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; } g_Pad;
/* g_Pad as a history ring of 40 samples (4 bytes each), newest at .cur */
typedef struct { s8 hist[40][4]; u8 padA0[0xD0]; s32 cur; } PadHist;

/* Debug: graph of the last 38 g_Pad history samples (byte 1): red bars for the value, blue
   bars for its change from the previous sample */
void Debug_DrawPadGraph(void) {
    PolyF4_5EC9C *p = (PolyF4_5EC9C *)G_DRAW.prim;
    u32 *ot = G_DRAW.db[G_DRAW.cur].ot;
    s32 i;
    s32 k0, k1, k2;
    s32 x0, x1;
    s32 cur = (*(PadHist *)&g_Pad).cur;

    for (i = 0; i < 38; i++) {
        k0 = (cur - i + 40) % 40;
        k1 = (k0 + 39) % 40;
        k2 = (k1 + 39) % 40;
        x0 = 0x154 - i * 10;
        ((u8 *)p)[3] = 5;
        p->code = 0x28;
        p->r0 = 0;
        p->g0 = 0;
        p->b0 = 0xFF;
        p->x0 = x0;
        p->y0 = 0x78;
        p->x1 = x0;
        p->y1 = 0x78 - ((*(PadHist *)&g_Pad).hist[k1][1] / 2 - (*(PadHist *)&g_Pad).hist[k2][1] / 2);
    x1 = 0x15E - i * 10;
        p->x2 = x1;
        p->y2 = 0x78;
        p->x3 = x1;
        p->y3 = 0x78 - ((*(PadHist *)&g_Pad).hist[k0][1] / 2 - (*(PadHist *)&g_Pad).hist[k1][1] / 2);
        ADD_PRIM_ASM(ot, p);
        p++;
        ((u8 *)p)[3] = 5;
        p->code = 0x28;
        p->r0 = 0xFF;
        p->g0 = 0;
        p->b0 = 0;
        p->x0 = x0;
        p->y0 = 0x78;
        p->x1 = x0;
        p->y1 = 0x78 - (*(PadHist *)&g_Pad).hist[k1][1] / 2;
        p->x2 = x1;
        p->y2 = 0x78;
        p->x3 = x1;
        p->y3 = 0x78 - (*(PadHist *)&g_Pad).hist[k0][1] / 2;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    G_DRAW.prim = (u8 *)p;
}

INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", Debug_DrawSticks);

INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", Hud_DrawMonkeyHeads);

/* Lives counter: Spike's 32x32 face icon at (x, y), semi-transparent */
void Hud_DrawLivesIcon(s32 x, s32 y) {
    SprtTp *p = (SprtTp *)G_DRAW.prim;
    u32 *ot = G_HUD_OT;

    ((u8 *)p)[3] = 5;
    p->code = 0x67;
    p->v0 = 0x60;
    p->u0 = 0xC0;
    p->clut = 0x3AFF;
    p->w = 0x20;
    p->h = 0x20;
    p->x0 = x;
    p->tpage = 0xE100024F;
    p->y0 = y;
    ADD_PRIM_ASM_A01(ot, p);
    G_DRAW.prim = (u8 *)(p + 1);
}

typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; u32 xy; u16 uv; u16 clut; u32 wh; } SprtTpW;

/* Time attack: medal icon for record time `time` against the stage's three target times v[0..2]
   (from Stage_GetTargetTimes); beating v[0], v[1], v[2] picks CLUT row 0x1F5, 0x1F4, 0x1F3. */
void Hud_DrawTimeMedal(s32 x, s32 y, u32 time, s16 *v) {
    s32 row = 0;
    u32 *ot = G_HUD_OT;
    SprtTpW *p = (SprtTpW *)G_DRAW.prim;

    if (v[0] >= time) {
        row = 0x1F5;
    }
    if (v[1] >= time) {
        row--;
    }
    if (v[2] >= time) {
        row--;
    }
    if (row != 0) {
        p->clut = (row << 6) | 0x37;
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE100023D;
        p->code = 0x65;
        p->xy = (y << 16) | x;
        p->wh = 0x200010;
        p->uv = 0xE090;
        ADD_PRIM_ASM(ot, p);
        p++;
        G_DRAW.prim = (u8 *)p;
    }
}

typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; s16 w, h; } SprtTpUv;

/* One 24x24 HUD digit 0-9 at (x, y); n = -1 draws glyph 10 (the "x" of the lives counter).
   Glyphs sit 3 per row from v = 0xA0 in the order 1..9, 0, x. */
void Hud_DrawBigDigit(s32 x, s32 y, s32 n) {
    u32 *ot = G_HUD_OT;
    SprtTpUv *p = (SprtTpUv *)G_DRAW.prim;

    if (n == -1) {
        n = 10;
    } else {
        n = (n + 9) % 10;
    }
    ((u8 *)p)[3] = 5;
    p->code = 0x67;
    p->w = 0x18;
    p->h = 0x18;
    p->tpage = 0xE100021D;
    p->x0 = x;
    p->y0 = y;
    p->uvclut = 0x7C370000 | (((n / 3) * 24 + 0xA0) << 8) | ((n % 3) * 24);
    ADD_PRIM_ASM(ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

/* number n (up to 4 digits, no leading zeros) in 24x24 digits, 24 px apart from x */
void Hud_DrawBigNumber(s32 x, s32 y, s32 n) {
    s32 d = 1000;
    do {
        if (n >= d || d == 1) {
            Hud_DrawBigDigit(x, y, n / d);
            x += 0x18;
        }
        n %= d;
        d /= 10;
    } while (d > 0);
}

/* one 8x16 glyph from the small font (4 per row from u 0x50, v 0xA0: digits, then ' " -) */
#define SMALL_GLYPH(g)                                                                   \
    ((u8 *)p)[3] = 5;                                                                     \
    p->tpage = 0xE100025D;                                                                \
    p->code = 0x65;                                                                       \
    p->x0 = x;                                                                            \
    p->y0 = y;                                                                            \
    p->w = 8;                                                                             \
    p->h = 16;                                                                            \
    p->uvclut = 0x7C770000 | ((((g) / 4) * 16 + 0xA0) << 8) | (((g) % 4) * 8 + 0x50);   \
    ADD_PRIM_ASM(ot, p);                                                                  \
    p++;                                                                                  \
    x += 8;

/* Time t (frames at 60/s) as m'ss"cc in small digits; t = -1 shows dashes (no record) */
void Hud_DrawTime(s32 x, s32 y, u32 t) {
    u32 *ot = G_HUD_OT;
    SprtTpUv *p = (SprtTpUv *)G_DRAW.prim;
    s32 i;
    s32 v, hi, lo, sep;

    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            v = t / 3600;
            sep = 10;
            hi = v / 10;
            lo = v % 10;
            break;
        case 1:
            v = (t / 60) % 60;
            sep = 11;
            hi = v / 10;
            lo = v % 10;
            break;
        case 2:
            v = ((t % 60) * 101) / 60;
            sep = 0;
            hi = v / 10;
            lo = v % 10;
            break;
        }
        if (t == -1) {
            lo = hi = 12;
        }
        SMALL_GLYPH(hi);
        SMALL_GLYPH(lo);
        if (sep != 0) {
            SMALL_GLYPH(sep);
        }
    }
    G_DRAW.prim = (u8 *)p;
}

/* Race clock: the spinning clock next to the timer in Stadium/Gladiator Attack (user), an 8-frame 16x16 sprite
   (tpage 0x21D, frame t >> 3) at (x, y), drawn by Hud_Draw and PauseMenu_Update. addPrim with hard v1/v0. */
void Hud_DrawTimerClock(s32 x, s32 y, s32 t) {
    s32 f = t >> 3;
    SprtTp *p = (SprtTp *)G_DRAW.prim;
    u32 *ot = G_HUD_OT;

    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    p->x0 = x;
    p->tpage = 0xE100021D;
    p->y0 = y;
    p->u0 = (f % 4) * 16 + 0x50;
    p->v0 = ((f % 8) / 4) * 16 - 0x20;
    p->w = 16;
    p->h = 16;
    p->clut = 0x7CB7;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    G_DRAW.prim = (u8 *)p;
}

s32 func_8005FD80(void)
{
  SV_5FD80_8005FD80 pos;
  s16 count;
  SV_5FD80_8005FD80 rot;
  SV_5FD80_8005FD80 r2;
  struct S_D_800A5A10 m;
  s32 f;
  u8 n;
  s32 v;
  s32 y1;
  s32 y2;
  s32 d;
  s16 t;
  f = ((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_0;
  n = ((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_2;
  if (n != 0)
  {
    if ((--((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_3) == 0)
    {
      ((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_3 = 3;
      if ((((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_2 = n - 1) != 0)
      {
        Sound_PlayFixed(0x7A);
      }
    }
  }
  count = (*(struct Game_5FD80 *)&g_Game).f_8168;
  t = D_800F4DB2 - 100;
  v = (count - t) % 100;
  if (f > 0x5A)
  {
    return 1;
  }
  if (f > 0x50)
  {
    y1 = 30 - ((f - 0x50) * 4);
    y2 = y1;
  }
  else
    if (f > 0xE)
  {
    y1 = 30;
    y2 = y1;
  }
  else
  {
    y1 = D_800B0200[f + 2];
    y2 = D_800B0200[f];
  }
  f++;
  d = v / 10;
  Hud_DrawBigDigit(0xA6, y1 + 8, d);
  Hud_DrawBigDigit(0xBA, y2 + 8, v - (d * 10));
  func_800A3740(&pos, 0, 8);
  pos.vx = 0x96;
  pos.vy = y1 + 0x16;
  pos.vz = 0x148;
  func_800A3740(&r2, 0, 8);
  *((s32 *) 0x1F8003C8) = 2;
  r2.vy = (*(struct Game_5FD80 *)&g_Game).f_0 << 5;
  rot = r2;
  m = D_800A5A10;
  Model_DrawOnScreen(D_800F4D20, &pos, &rot, &m);
  ((struct S_D_800F4DB0_8005FD80 *)&D_800F4DB0)->f_0 = f;
  return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A10);


INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", func_8005FFD4);

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A20);
INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A28);


typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_60224;

/* Monkey info card: stat row `row` (0-2) as 5 pips at x 0x128, the first n lit; the value is
   one decimal digit of the monkey kind's +0x1C (see Radar_DrawMonkeyCard) */
void MonkeyInfo_DrawStatPips(s32 row, s32 n) {
    u32 *ot = G_HUD_OT;
    Sprt_60224 *p = (Sprt_60224 *)G_DRAW.prim;
    s32 x = 0x128;
    s32 y = row * 16 + 0x20;
    u16 clut;
    s32 i;

    if (row == 0) {
        clut = 0x796B;
    } else if (row == 1) {
        clut = 0x792B;
    } else {
        clut = 0x79AB;
    }
    for (i = 0; i < 5; i++) {
        if (i < n) {
            *(u32 *)&p->r0 = 0x808080;
        } else {
            *(u32 *)&p->r0 = 0x101010;
        }
        ((u8 *)p)[3] = 4;
        p->code = 0x64;
        p->x0 = x;
        p->y0 = y;
        p->w = 8;
        p->h = 16;
        p->clut = clut;
        p->u0 = 0x98;
        p->v0 = 0xA0;
        ADD_PRIM_ASM2(ot, p);
        p++;
        x += 8;
    }
    G_DRAW.prim = (u8 *)p;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt8_60334;
typedef struct { u32 tag; u32 code; } DrTpage_60334;

/* w x h window box at (x, y) from 8x8 tiles: corner, edge and middle tiles picked by position */
void Hud_DrawWindow(s32 x, s32 y, s32 w, s32 h) {
    s32 tx, ty;
    s32 u, v;
    u32 *ot = G_HUD_OT;
    Sprt8_60334 *p = (Sprt8_60334 *)G_DRAW.prim;

    for (ty = 0; ty < h; ty += 8) {
        for (tx = 0; tx < w; tx += 8) {
            ((u8 *)p)[3] = 3;
            p->code = 0x77;
            p->x0 = x + tx;
            p->y0 = y + ty;
            p->clut = 0x77AB;
            if (tx == 0) {
                u = 0x80;
            } else if (tx + 8 >= w) {
                u = 0x90;
            } else {
                u = 0x88;
            }
            p->u0 = u;
            if (ty == 0) {
                v = 0xA0;
            } else if (ty + 8 >= h) {
                v = 0xB0;
            } else {
                v = 0xA8;
            }
            p->v0 = v;
            ADD_PRIM_ASM2(ot, p);
            p++;
        }
    }
    ((u8 *)p)[3] = 1;
    ((DrTpage_60334 *)p)->code = 0xE100025A;
    ADD_PRIM_ASM(ot, p);
    p = (Sprt8_60334 *)((u8 *)p + 8);
    G_DRAW.prim = (u8 *)p;
}

INCLUDE_ASM("asm/nonmatchings/game/8005E0F0_hud", Radar_DrawMonkeyCard);
