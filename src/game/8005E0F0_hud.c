#include "common.h"
#include "m2c_macros.h"
typedef struct { s16 vx, vy, vz, pad; } SV_5FD80_8005FD80;

extern struct S_D_800EC1E0 { u8 pad0[0xE8]; s16 f_E8; s16 f_EA; u8 padEC[4]; u8 f_F0; } g_Spike;

extern s16 D_800F4DCC;
extern struct S_D_800F4DB0 { u8 pad_0[0x14]; s16 f_14; s16 f_16; u8 pad_18[0x4]; s16 f_1C; u8 pad_1E[0x2]; s32 f_20; } g_HudState;
extern struct S_D_800EC350 { u8 pad0[0x8124]; u16 f_8124; } g_Game;
void Hud_ShowHealth(s32 arg0);
void Hud_DrawBigDigit(s32, s32, s32);
struct Game_5FD80 { u16 f_0; u8 pad2[0x8166]; s16 f_8168; };
extern u8 D_800F4DB2;
extern s8 D_800B0200[];
extern struct S_D_800A5A10 { s32 w[4]; } D_800A5A10;
extern u8 D_800F4D20[];
void Sound_PlayFixed(s32);
void memset(void *, s32, s32);
void Model_DrawOnScreen(void *, SV_5FD80_8005FD80 *, SV_5FD80_8005FD80 *, struct S_D_800A5A10 *);
struct S_D_800F4DB0_8005FD80 { s16 f_0; u8 f_2; u8 f_3; };

extern struct { u8 pad0[0x8140]; s32 time; } g_GameT asm("g_Game");
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; s16 w, h; } Tile_5E0F0;
typedef struct { u8 pad0[0x18]; u32 groundCol; u32 skyCol; u8 pad20[0xA]; u16 fog; } Stage_5E0F0;
typedef struct { u8 pad0[0x8124]; u16 area; u8 pad8126[6]; u8 f_812C; u8 pad812D[0x13]; s32 time; u8 pad8144[0x50]; Stage_5E0F0 *stage; } GameH_5E0F0;
#define GH (*(GameH_5E0F0 *)&g_Game)
extern s16 D_800E78CE;
extern u8 D_800E6908;
s32 Overlay_GetState(void);
s32 Game_IsTimed(void);
void Hud_DrawTimerClock(s32, s32, s32);
void Hud_DrawTime(s32, s32, u32);
s32 TimeTrial_GetClockStop(void);
void Hud_DrawClockStopBar(s32);
void Hud_DrawHealth(void);
void Hud_DrawGadgets(void);
void Hud_DrawLives(void);
void Hud_UpdateStatusIcons(void);
void Hud_UpdateMonkeyHeads(void);
void Hud_UpdateChips(void);
void func_8013D424(s32);
void Tex_DrawFogLevels(s32);
#define gte_ldIR_5E0F0(r1, r2, r3) __asm__ volatile ("mtc2 %0, $9; nop; mtc2 %1, $10; nop; mtc2 %2, $11" : : "r"(r1), "r"(r2), "r"(r3))
#define gte_ldRGB_5E0F0(p) __asm__ volatile ("lwc2 $6, 0(%0)" : : "r"(p))
#define gte_stRGB2_5E0F0(p) __asm__ volatile ("swc2 $22, 0(%0)" : : "r"(p))
#define gte_cc_5E0F0() __asm__ volatile ("cc")

/* Per-frame HUD. Unless g_Game+0x812C is 0xB, 7 or 9: first two background tiles, sky above and ground
   below a horizon at 0x78 - camera pitch / 16 (0..0xEF), in the stage's colours (+0x1C, +0x18) run
   through the GTE colour step, at the back of the ordering table. Then, unless an overlay is up, the
   timer (timed modes), health, gadgets (also in areas 0x1F/0x20), lives, status icons (not in first
   person), the menu countdown and Hud_UpdateChips, as the g_HudState+0x20 flags say; area-specific extras
   for areas 7 and 0xE, and the fog levels when the stage has fog. */
void Hud_Draw(void) {
    Stage_5E0F0 *st = GH.stage;
    Tile_5E0F0 *p;
    s32 hz;
    s32 t;

    if (GH.f_812C == 0xB || GH.f_812C == 7 || GH.f_812C == 9) {
        return;
    }
    hz = 0x78 - D_800E78CE / 16;
    if (hz >= 0) { t = 0xEF; if (hz < 0xF0) t = hz; } else t = 0;
    hz = t;
    { s32 h2 = hz;
    p = (Tile_5E0F0 *)G_DRAW.prim;
    gte_ldIR_5E0F0(0x1000, 0, 0);
    gte_ldRGB_5E0F0(&st->skyCol);
    p->x0 = 0;
    p->y0 = 0;
    gte_cc_5E0F0();
    p->w = 0x200;
    p->h = h2;
    gte_stRGB2_5E0F0(&p->r0);
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    ADD_PRIM_R(&G_DRAW.ot[0xFFF], p, "$5", "$4");
    p++;
    gte_ldIR_5E0F0(0x1000, 0, 0);
    gte_ldRGB_5E0F0(&st->groundCol);
    p->x0 = 0;
    p->y0 = h2;
    gte_cc_5E0F0();
    p->h = 0xF0 - h2;
    p->w = 0x200;
    gte_stRGB2_5E0F0(&p->r0);
    ((u8 *)p)[3] = 3;
    p->code = 0x60;
    ADD_PRIM_R(&G_DRAW.ot[0xFFF], p, "$5", "$4");
    G_DRAW.prim = (u8 *)(p + 1); }
    if (Overlay_GetState() != 0) {
        return;
    }
    {
    s32 ar = GH.area;
    if (ar >= 0x21) {
        goto main;
    }
    if (ar >= 0x1F) {
        goto gadgets;
    }
    }
main:
    if (D_800E6908 == 1) {
        goto lives;
    }
    if (Game_IsTimed() != 0) {
        s32 k;
        { u8 *g = (u8 *)&g_GameT; u32 kk; __asm__("" : "=r"(g) : "0"(g)); __asm__("" : "=r"(kk) : "0"(0x8000)); 
        Hud_DrawTimerClock(0x90, 0x20, *(s32 *)(g + kk + 0x140));
        Hud_DrawTime(0xA0, 0x20, *(s32 *)(g + kk + 0x140)); }
        k = TimeTrial_GetClockStop();
        if (k != 0) {
            Hud_DrawClockStopBar(k);
        }
    }
    if (g_HudState.f_20 & 0x10) {
        Hud_DrawHealth();
    }
    if (!(g_HudState.f_20 & 0x20)) {
        goto lives;
    }
gadgets:
    Hud_DrawGadgets();
lives:
    if (g_HudState.f_20 & 8) {
        Hud_DrawLives();
    }
    if ((g_HudState.f_20 & 2) && D_800E6908 != 1) {
        Hud_UpdateStatusIcons();
    }
    if (g_HudState.f_20 & 4) {
        Hud_UpdateMonkeyHeads();
    }
    if (g_HudState.f_20 & 1) {
        Hud_UpdateChips();
    }
    if (g_Game.f_8124 == 7) {
        func_8013D424(0);
    } else if (g_Game.f_8124 == 0xE) {
        func_8013D424(1);
    }
    if (st->fog != 0) {
        Tex_DrawFogLevels(0);
    }
}

void Hud_ShowHealth(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        D_800F4DCC = 0;
        break;
    case 1:
        if (g_HudState.f_20 & 0x10) {
            if (g_HudState.f_1C >= 0x15) {
                g_HudState.f_1C = 0x14;
            }
        } else {
            g_HudState.f_1C = 0;
        }
        break;
    }
    g_HudState.f_20 = (s32) (g_HudState.f_20 | 0x10);
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
    Hud_ShowHealth(1);
    g_HudState.f_14 = dmg;
    g_HudState.f_16 = 12;
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
  Hud_ShowHealth(1);
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
void *Mem_AllocPages(s32 size);
void Mem_Free(void *p);
s32 DrawSync(s32 mode);
s32 LoadImage(void *rect, u32 *p);
s32 StoreImage(void *rect, u32 *p);

/* Depth fog for a texture: saves rect r in D_800B98D0[idx] and builds 7 copies of the image at
   (0x240 + (k % 4) * 16, 0x100 + (k / 4) * 128) with each opaque pixel k/8 of the way to the fog
   colour (k = 1..7). Tex_DrawFogLevels copies them back over the texture at increasing depths. */
void Tex_MakeFogLevels(Rect_5E7EC *r, s32 idx, CVec_5E7EC fog) {
    Rect_5E7EC dst = D_800A5A00;
    s16 *src = Mem_AllocPages(0x1000);
    u16 *out = Mem_AllocPages(0x1000);
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
    Mem_Free(src);
    Mem_Free(out);
}

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A00);


typedef struct { u8 pad0[0x30]; u16 z0; u16 z1; } Cam_Tex_DrawFogLevels;
typedef struct { u8 pad0[4]; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x94]; Cam_Tex_DrawFogLevels *cam; } G_Tex_DrawFogLevels;
extern G_Tex_DrawFogLevels g_Game_Tex_DrawFogLevels asm("g_Game");
extern Rect_5E7EC D_800A5A08;
void SetDrawMove(void *p, void *r, s32 x, s32 y);
/* addPrim with hard a0/v1 temps where only a0 is declared: a declared $3 would be an "explicitly used" register, which reload refuses for the /6 quotient (mfhi) */
#define ADDP_TDFL(ot, p) __asm__ volatile("lwl $4, 2(%0)\n\tsll $3, %2, 8\n\tswl $3, 2(%0)\n\tswl $4, %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$4")
#define G_TDFL g_Game_Tex_DrawFogLevels

void Tex_DrawFogLevels(s32 idx) {
    Rect_5E7EC r;
    u8 *p = G_TDFL.prim;
    Cam_Tex_DrawFogLevels *c = G_TDFL.cam;
    s32 i;
    u32 z, zz;
    s32 z0, z1, iy;

    r = D_800A5A08;
    iy = idx * 32;
    z0 = c->z0;
    z1 = c->z1;
    r.x = 0x270;
    r.y = iy + 0x180;
    SetDrawMove(p, &r, D_800B98D0[idx].x, D_800B98D0[idx].y);
    { register u32 *b asm("$5") = G_TDFL.db[0].ot; ADDP_TDFL((u32 *)((u8 *)b + G_TDFL.cur * sizeof(DrawBuf)) + 0xFFF, p); }
    p += 0x18;
    for (i = 0; i < 7; i++) {
        __asm__("" : : "r"(iy), "r"(iy), "r"(iy), "r"(iy), "r"(iy));
        __asm__("" : : "r"(iy), "r"(iy), "r"(iy), "r"(iy), "r"(iy), "r"(iy));
        r.x = (i % 4) * 16 + 0x240;
        { s32 t = (i / 4) * 128 + 0x100; r.y = iy + t; }
        SetDrawMove(p, &r, D_800B98D0[idx].x, D_800B98D0[idx].y);
        zz = i * (z1 - z0) / 6 + z0;
        z = (zz > 0x1000) ? 0x1000 : zz;
        ADDP_TDFL(&G_TDFL.db[G_TDFL.cur].ot[z], p);
        p += 0x18;
    }
    G_TDFL.prim = p;
}

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

typedef struct { s8 hist[40][4]; u8 padA0[0xD0]; u32 cur; u8 pad174[0x30]; s32 f_1A4; } PadHist2_5EF28;
#define PH_5EF28 (*(PadHist2_5EF28 *)&g_Pad)
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PolyF4_5EF28;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PolyF4Tp_5EF28;
#define DOT_5EF28(p, x, y, r) ((u8 *)(p))[3] = 5; (p)->code = 0x28; (p)->r0 = (r); (p)->g0 = 0; (p)->b0 = 0; (p)->x0 = (x); (p)->y0 = (y) + 0x19; (p)->x1 = (x) + 3; (p)->y1 = (y) + 0x19; (p)->x2 = (x); (p)->y2 = (y) + 0x1C; (p)->x3 = (x) + 3; (p)->y3 = (y) + 0x1C;
/* Debug: analog sticks of the newest and previous g_Pad history samples as 3x3 dots (red,
   dim red), plus two boxes, the second green or blue by g_Pad+0x1A4 */
#define Q_5EF28 ((PolyF4Tp_5EF28 *)p)

void Debug_DrawSticks(void) {
    PolyF4_5EF28 *p = (PolyF4_5EF28 *)G_DRAW.prim;
    PolyF4Tp_5EF28 *q;
    u32 *ot = G_DRAW.db[G_DRAW.cur].ot;
    s8 *h;
    s32 lx, ly, rx, ry;
    s32 v, pos, neg;

        rx = PH_5EF28.hist[PH_5EF28.cur][2];
    lx = PH_5EF28.hist[PH_5EF28.cur][0];
    ry = -PH_5EF28.hist[PH_5EF28.cur][3];
    ly = -PH_5EF28.hist[PH_5EF28.cur][1];
    rx /= 8;
    ry /= 8;
    lx /= 8;
    ly /= 8;
    v = PH_5EF28.f_1A4 / 128;
    v = (v < -0x7F) ? -0x7F : (v >= 0x80) ? 0x7F : v;
    if (v > 0) {
        pos = v * 2;
        neg = 0;
    } else {
        pos = 0;
        neg = -v * 2;
    }
    DOT_5EF28(p, rx + 0xD7, ry, 0xFF);
    ADD_PRIM_ASM(ot, p);
    p++;
    DOT_5EF28(p, lx + 0xFB, ly, 0xFF);
    ADD_PRIM_ASM(ot, p);
    p++;
    h = PH_5EF28.hist[(PH_5EF28.cur + 39) % 40];
    rx = h[2];
    lx = h[0];
    ry = -h[3];
    ly = -h[1];
    rx /= 8;
    ry /= 8;
    lx /= 8;
    ly /= 8;
    DOT_5EF28(p, rx + 0xD7, ry, 0x80);
    ADD_PRIM_ASM(ot, p);
    p++;
    DOT_5EF28(p, lx + 0xFB, ly, 0x80);
    ADD_PRIM_ASM(ot, p);
    p++;
    ((u8 *)p)[3] = 6;
    Q_5EF28->code = 0x2A;
    Q_5EF28->tpage = 0xE1000200;
    Q_5EF28->r0 = 0;
    Q_5EF28->g0 = 0xFF;
    Q_5EF28->b0 = 0xFF;
    Q_5EF28->x0 = 0xC8;
    Q_5EF28->y0 = 10;
    Q_5EF28->x1 = 0xE8;
    Q_5EF28->y1 = 10;
    Q_5EF28->x2 = 0xC8;
    Q_5EF28->y2 = 0x2A;
    Q_5EF28->x3 = 0xE8;
    Q_5EF28->y3 = 0x2A;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p = (PolyF4_5EF28 *)((u8 *)p + 0x1C);
    ((u8 *)p)[3] = 6;
    Q_5EF28->tpage = 0xE1000200;
    Q_5EF28->code = 0x2A;
    Q_5EF28->r0 = 0;
    Q_5EF28->g0 = pos;
    Q_5EF28->b0 = neg;
    Q_5EF28->x0 = 0xEC;
    Q_5EF28->y0 = 10;
    Q_5EF28->x1 = 0x10C;
    Q_5EF28->y1 = 10;
    Q_5EF28->x2 = 0xEC;
    Q_5EF28->y2 = 0x2A;
    Q_5EF28->x3 = 0x10C;
    Q_5EF28->y3 = 0x2A;
    ADD_PRIM_ASM(ot, p);
    p = (PolyF4_5EF28 *)((u8 *)p + 0x1C);
    G_DRAW.prim = (u8 *)p;
}

typedef struct { u32 f_0; u8 pad4[0x8120]; u16 stage; u8 pad8126[8]; u16 mode; u8 pad8130[0x36]; s16 caught; u8 pad8168[0x20]; s16 total; } GameMk_Hud_DrawMonkeyHeads;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_Hud_DrawMonkeyHeads;
typedef struct { u32 tag; u32 code; } DrTpage_Hud_DrawMonkeyHeads;
#define GM_HDMH (*(GameMk_Hud_DrawMonkeyHeads *)&g_Game)

/* Monkey counter: one 32x32 head per monkey in the stage from x leftwards, the caught ones in
   the caught palette, blinking; stages 17 and 22-30 show a single head */
void Hud_DrawMonkeyHeads(s32 x, s32 y)
{
    u32 *ot = G_DRAW.db[G_DRAW.cur].hud;
    int v;
    Sprt_Hud_DrawMonkeyHeads *p = (Sprt_Hud_DrawMonkeyHeads *)G_DRAW.prim;
    s32 step;
    s32 i;

    if (GM_HDMH.mode == 1 || GM_HDMH.total == 0) {
        return;
    }
    if (GM_HDMH.mode == 2 && GM_HDMH.stage == 30) {
        return;
    }
    if ((GM_HDMH.stage == 17 || (GM_HDMH.stage >= 22 && GM_HDMH.stage < 31)) && GM_HDMH.mode != 2) {
        ((u8 *)p)[3] = 4;
        p->code = 0x65;
        p->x0 = x;
        p->y0 = y;
        v = (GM_HDMH.f_0 % 10 >= 6) ? 0x80 : 0xA0;
        p->u0 = 0xE0;
        p->clut = 0x37FF;
        p->v0 = v;
        p->w = 0x20;
        p->h = 0x20;
        ADD_PRIM_R(ot, p, "$3", "$2");
        p++;
    } else {
        step = 200 / GM_HDMH.total;
        if (step > 32) {
            step = 32;
        }
        for (i = 0; i < GM_HDMH.total; i++) {
            if (i < GM_HDMH.caught) {
                ((u8 *)p)[3] = 4;
                p->code = 0x67;
                p->x0 = x;
                p->y0 = y;
                p->v0 = (GM_HDMH.f_0 % 10 >= 6) ? 0x40 : 0x60;
                p->u0 = 0x80;
                p->clut = 0x3A3F;
                p->w = 0x20;
                p->h = 0x20;
                ADD_PRIM_R(ot, p, "$3", "$2");
            } else {
                ((u8 *)p)[3] = 4;
                p->code = 0x67;
                p->x0 = x;
                p->y0 = y;
                p->v0 = (GM_HDMH.f_0 % 10 >= 6) ? 0x40 : 0x60;
                p->u0 = 0xA0;
                p->clut = 0x3A7F;
                p->w = 0x20;
                p->h = 0x20;
                ADD_PRIM_R(ot, p, "$3", "$2");
            }
            p++;
            x -= step;
        }
    }
    {
        register u32 code asm("$3") = 0xE100020F;
        ((u8 *)p)[3] = 1;
        ((DrTpage_Hud_DrawMonkeyHeads *)p)->code = code;
    }
    ADD_PRIM_R(ot, p, "$3", "$2");
    p = (Sprt_Hud_DrawMonkeyHeads *)((u8 *)p + 8);
    G_DRAW.prim = (u8 *)p;
    __asm__("" : : "r"(ot), "r"(ot), "r"(ot), "r"(ot), "r"(ot), "r"(ot));
}

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

s32 Hud_DrawChipCounter(void)
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
  f = ((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_0;
  n = ((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_2;
  if (n != 0)
  {
    if ((--((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_3) == 0)
    {
      ((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_3 = 3;
      if ((((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_2 = n - 1) != 0)
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
  memset(&pos, 0, 8);
  pos.vx = 0x96;
  pos.vy = y1 + 0x16;
  pos.vz = 0x148;
  memset(&r2, 0, 8);
  *((s32 *) 0x1F8003C8) = 2;
  r2.vy = (*(struct Game_5FD80 *)&g_Game).f_0 << 5;
  rot = r2;
  m = D_800A5A10;
  Model_DrawOnScreen(D_800F4D20, &pos, &rot, &m);
  ((struct S_D_800F4DB0_8005FD80 *)&g_HudState)->f_0 = f;
  return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005E0F0_hud", D_800A5A10);


extern SV_5FD80_8005FD80 D_800A5A20;
extern struct S_D_800A5A10 D_800A5A28;
typedef struct { u32 tag; u32 c0; u32 xy0; u32 xy1; u32 xy2; u32 end; } LineF3_5FFD4;
extern GameDraw g_GameD_5FFD4 asm("g_Game");
typedef struct { u32 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4_5FFD4;

void Hud_DrawClockStopBar(s32 n) {
    SV_5FD80_8005FD80 pos;
    SV_5FD80_8005FD80 rot;
    SV_5FD80_8005FD80 r2;
    struct S_D_800A5A10 m;
    LineF3_5FFD4 *p = (LineF3_5FFD4 *)g_GameD_5FFD4.prim;
    u32 *ot = g_GameD_5FFD4.db[g_GameD_5FFD4.cur].hud;
    s32 w = n * 42 / 60;
    u32 c = 0xFF;
    u32 xy;
    u32 xy2;

    if (w > 0x60) {
        w = 0x60;
        c = 0xFFFF;
    }
    p->c0 = c | 0x808080;
    ((u8 *)p)[3] = 5;
    ((u8 *)p)[7] = 0x48;
    p->end = 0x55555555;
    p->xy0 = 0x3C00A0;
    p->xy1 = 0x3400A0;
    xy = (w + 0xA0) | 0x340000;
    p->xy2 = xy;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    p->c0 = c & 0x7F7F;
    xy2 = (w + 0xA0) | 0x3C0000;
    ((u8 *)p)[3] = 5;
    ((u8 *)p)[7] = 0x48;
    p->end = 0x55555555;
    p->xy0 = 0x3C00A0;
    p->xy1 = xy2;
    p->xy2 = xy;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    {
        PolyG4_5FFD4 *q = (PolyG4_5FFD4 *)p;
        q->c0 = c | 0x202020;
        q->c1 = c | 0x101010;
        q->c2 = c | 0x101010;
        ((u8 *)q)[3] = 8;
        q->c3 = c;
        q->xy0 = 0x3400A0;
        q->xy1 = xy;
        q->xy2 = 0x3C00A0;
        q->xy3 = xy2;
        ((u8 *)q)[7] = 0x38;
        ADD_PRIM_R(ot, q, "$3", "$2");
        p = (LineF3_5FFD4 *)(q + 1);
        G_DRAW.prim = (u8 *)p;
    }
    pos = D_800A5A20;
    memset(&r2, 0, 8);
    *((s32 *)0x1F8003C8) = 2;
    r2.vy = (*(struct Game_5FD80 *)&g_Game).f_0 << 6;
    rot = r2;
    m = D_800A5A28;
    Model_DrawOnScreen(D_800F4D20, &pos, &rot, &m);
}

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

typedef struct { u8 pad0[0x1C]; s16 stats; u8 pad1E[0x40]; u8 name[0xC]; u8 desc[0x1E]; } Kind_60448;
extern Kind_60448 *g_MonkeyKinds_60448 asm("g_MonkeyKinds");
typedef struct { u8 pad0[0x7C]; u8 kind; } Monkey_60448;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; u32 xy; u8 u0, v0; u16 clut; u32 wh; } SprtTpW_60448;
extern u8 g_StrLive[];
extern u8 g_StrSpeed[];
extern u8 g_StrAttack[];
extern u8 g_StrAlert[];
extern u8 g_StrMonkeyLevel[];
void func_8008227C(s32);
void Text_Draw(u8 *s, s32 x, s32 y, s32 col);
s32 Text_GetWidth(u8 *s);
void MonkeyInfo_DrawStatPips(s32 row, s32 n);
void Hud_DrawWindow(s32 x, s32 y, s32 w, s32 h);

/* Monkey Radar live view card (user: "LIVE" shows over a live camera following the monkey; the
   Monkey Book shows the same info with a still picture instead, and the level name and world above
   it): "LIVE" title with a blinking 24x24 icon, kind name (+0x5E), "Monkey Level n" from the
   thousands digit of the kind's stats, then Speed / Attack / Alert = hundreds / tens / ones digits
   as 5-pip rows (MonkeyInfo_DrawStatPips), the centred fact line (+0x6A), each in a box. */
void Radar_DrawMonkeyCard(Monkey_60448 *m) {
    Kind_60448 *k;
    s32 d;
    s32 v, h, t;
    SprtTpW_60448 *p;
    u32 *ot;
    s32 u;

    if (m == NULL) {
        return;
    }
    func_8008227C(0);
    k = &g_MonkeyKinds_60448[m->kind];
    Text_Draw(g_StrLive, 0x38, 0x18, 2);
    Text_Draw((u8 *)k + 0x5E, 0x20, 0x30, 2);
    d = (s16)((s16)(k->stats / 1000) % 10);
    g_StrMonkeyLevel[13] = (d >= 6) ? d + 0x74 : d + 0x6A;
    Text_Draw(g_StrMonkeyLevel, 0x3C, 0x40, 2);
    Text_Draw(g_StrSpeed, 0xE0, 0x20, 2);
    Text_Draw(g_StrAttack, 0xE0, 0x30, 2);
    Text_Draw(g_StrAlert, 0xE0, 0x40, 2);
    Text_Draw(k->desc, (0x180 - Text_GetWidth(k->desc)) / 2, 0xC8, 2);
    ot = G_HUD_OT;
    p = (SprtTpW_60448 *)G_DRAW.prim;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100023A;
    p->code = 0x67;
    p->wh = 0x180018;
    p->xy = 0x100020;
    u = 0;
    if (!(((struct { u32 frame; } *)&g_Game)->frame & 0x10)) {
        u = 0x18;
    }
    p->v0 = 0xA8;
    p->u0 = u;
    p->clut = 0x75EB;
    ADD_PRIM_ASM(ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
    v = k->stats;
    h = v / 100;
    MonkeyInfo_DrawStatPips(0, h % 10);
    t = v / 10;
    MonkeyInfo_DrawStatPips(1, t - h * 10);
    MonkeyInfo_DrawStatPips(2, v - t * 10);
    Hud_DrawWindow(0x1C, 0x14, 0x50, 0x18);
    Hud_DrawWindow(0x1C, 0x2C, 0xB0, 0x28);
    Hud_DrawWindow(0xDC, 0x1C, 0x80, 0x38);
    Hud_DrawWindow(0x1C, 0xC4, 0x140, 0x18);
}
