#include "common.h"
#include "gte.h"
#include "m2c_macros.h"
#define SPAD ((u8 *)0x1F800000)
#define DIGIT(d) ((d) < 6 ? (d) + 0x6A : (d) + 0x74)
#include "common.h"
typedef struct { u8 pad0[8]; s32 unk8; void *unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C; u8 unk20; } S_7D23C;
typedef struct { s16 x, y, w, h; } RECT16_8007F848;
typedef struct { s16 vx, vy, vz, pad; } SV_828F8_800828F8;
typedef struct { s16 vx, vy, vz, pad; } SV_7F5E4_8007F5E4;
typedef struct { s32 vx, vy, vz, pad; } V_7F5E4_8007F5E4;

extern M2C_UNK g_GadgetState;

void func_8005DD28(void);

void func_8007D110(void);
s32 func_8007D118(void *p, s32 size);

M2C_UNK func_800864B4(s32 *);
extern s32 D_800BEF90;

extern s16 D_800BEF60;
extern s16 D_800BEF62;
extern s16 D_800BEF64;
extern s32 g_CheatInput;
extern struct S_D_800BEF74 { s8 f_0; u8 f_1; s16 f_2; } D_800BEF74;
extern M2C_UNK D_800BEF78;
M2C_UNK Gfx_WaitFlip();
M2C_UNK Gadget_StopSounds(s8);
s32 PauseMenu_Update();
extern s8 g_CurrentGadget;
extern s32 D_800BEF80;
extern s32 D_800BEF7C;
extern s32 D_800EC35C;
void LoadImage(RECT16_8007F848 *, u32 *);
extern struct S_D_800EC350 { u8 pad0[0x8122]; u16 f_8122; u8 pad8124[2]; u16 f_8126; } g_Game;
extern struct S_D_800E5320_8007F40C { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad;
extern struct S_D_800F4350 { u8 pad0[0x154]; s16 f_154; s16 f_156; } D_800F4350;
extern M2C_UNK g_Spike;
struct S_D_800EC1E0_8007F40C { u8 pad0[0x148]; s16 f_148; };
extern u32 g_CheatCodes[];
void Sound_PlayFixed();
extern u8 D_800B2734[];
void func_8007F8F4(s32);
struct S_D_800BEF78_8007F9D0 { s32 done; s32 n; };
extern struct S_D_800B264C { s16 x, y, x2, y2; u8 pad8[4]; } D_800B264C[];
struct Game_82A04 { u8 pad0[0x816A]; u16 f_816A; };
extern u8 D_800B26D0[];
extern u8 D_800B269C[];
void Menu_DrawSpinningModel(s32 x, s32 y);
void Text_Draw(u8 *, s32, s32, s32);
void Menu_DrawWindow(s32, s32, s32, s32);
s32 func_80096580(s32);
s32 Save_GetCurrentCompletion(void);
void func_8008DDB0(s32, s32);
void func_8008DDC8(u8 *);
struct Game_828F8 { s32 frame; s32 f_4; u32 *ot; };
extern u8 g_ProjVerts[];
extern u8 D_800F4D00[];
extern struct S_D_800AF0A0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800AF0A0;
void Matrix_SetIdentity(struct S_D_800AF0A0 *);
s32 rsin(s32 a);
s32 rcos(s32 a);
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Model_ProjectVerts(void *, struct S_D_800AF0A0 *, u8 *);
void Model_CalcEnvMapUVs64(void *);
void Model_DrawEnvMapped(u32 *, u8 *, void *);
struct Game_7F5E4 { s32 frame; s32 prim; };
extern s16 D_800BEF76;
extern struct S_D_800F4CA0 { u8 b[16]; } D_800F4CA0[];
extern s32 D_800EC354;
s32 func_80082030(s32 a);
void Model_DrawOnScreen(struct S_D_800F4CA0 *, SV_7F5E4_8007F5E4 *, SV_7F5E4_8007F5E4 *, V_7F5E4_8007F5E4 *);

INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", D_800A60B0);

void func_8007D0F0(void) {
    D_800BEF60 = 0;
    D_800BEF62 = 0;
    D_800BEF64 = 1;
}

void func_8007D110(void) {
}

s32 func_8007D118(void *p, s32 size) {
    switch (size) {
    case 0:
        return *(s8 *)p;
    case 1:
        return *(s16 *)p;
    case 2:
        return *(s32 *)p;
    case 3:
        return *(u8 *)p;
    }
}

void func_8007D188(void *p, s32 v, s32 size) {
    switch (size) {
    case 1:
        *(s16 *)p = v;
        break;
    case 2:
        *(s32 *)p = v;
        break;
    case 0:
    case 3:
        *(u8 *)p = v;
        break;
    }
}

void DebugItem_Init(S_7D23C *s, s32 a, s32 b) {
    s->unk20 = b;
    s->unkC = func_8007D110;
    s->unk8 = a;
    s->unk18 = func_8007D118(a, b);
    s->unk10 = -9999;
    s->unk14 = 9999;
    s->unk1C = 1;
}

void func_8007D23C(S_7D23C *s, s32 a, s32 b) {
    s->unk20 = b;
    s->unkC = func_8007D110;
    s->unk8 = a;
    s->unk18 = func_8007D118(a, b);
    s->unk1C = 1;
    s->unk10 = 0;
    s->unk14 = 1;
}

void DebugItem_SetRange(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
}

void func_8007D29C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}

void func_8007D2A4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
}

s32 func_8007D2AC(u8 *arg0) {
    u8 *p = arg0;

    if (*arg0 == 0x60) {
        arg0 += 2;
    }
    while (*p++ != 0) {
    }
    return p - arg0;
}

typedef struct { u16 flags; u8 pad2[2]; u8 *text; u8 pad8[0x1C]; } MenuItem_8007D2D8;
typedef struct { s16 x; s16 y; MenuItem_8007D2D8 *items; } MenuDef_8007D2D8;
typedef struct { MenuDef_8007D2D8 def; s16 w; s16 h; u8 f_C; u8 f_D; s8 n; s8 sel; s16 f_10; s16 f_12; s16 f_14; s16 f_16; s16 f_18; s16 f_1A; s16 f_1C; s8 f_1E; u8 f_1F; u8 pad20[2]; s16 f_22; s16 f_24; u8 pad26[6]; } Menu_8007D2D8;
extern u16 D_800BEF60_7D2D8 asm("D_800BEF60");
extern Menu_8007D2D8 D_800F5270[];
s32 func_8007D2AC(u8 *arg0);

s32 func_8007D2D8(MenuDef_8007D2D8 *def) {
    MenuItem_8007D2D8 *it = def->items;
    s32 maxw = 0;
    s32 w;
    Menu_8007D2D8 *m;

    if (D_800BEF60_7D2D8 >= 6) {
        return -1;
    }
    m = &D_800F5270[D_800BEF60_7D2D8];
    m->def = *def;
    m->f_C = 1;
    m->f_D = 2;
    m->f_18 = 0x11;
    m->f_1A = 0xF;
    m->f_1E = -1;
    m->sel = -1;
    m->f_12 = 0;
    m->f_10 = 0;
    m->f_1F = 0;
    m->f_1C = 0x5C2;
    m->n = 0;
    while (it->flags != 0) {
        w = func_8007D2AC(it->text);
        if (it->flags & 0x6000) {
            w += 5;
        }
        if (maxw < w) {
            maxw = w;
        }
        if (m->sel == -1 && (it->flags & 0x8000)) {
            m->sel = m->n;
        }
        it++;
        m->n++;
    }
    if (m->sel == -1) {
        m->f_C = 2;
    } else {
        m->f_18 += 0x12;
        D_800BEF62 = D_800BEF60_7D2D8;
    }
    m->f_22 = m->def.x + m->f_18;
    m->f_24 = m->def.y + m->f_1A;
    m->w = m->f_18 + (maxw + 1) * 8;
    m->h = (m->f_1A + m->n * 5) * 2 - 5;
    { s16 y = m->def.y; if (m->def.y + m->h < 0xF0) m->def.y = y; else m->def.y = 0xE8 - m->h; }
    m->f_14 = 0;
    m->f_16 = m->h / 4;
    if (m->f_16 < 0x10) {
        m->f_16 = 0x10;
    }
    D_800BEF60_7D2D8++;
    return D_800BEF60_7D2D8 - 1;
}

typedef struct { s16 x, y, w, h; } Rect_d530;
typedef struct { Rect_d530 r[4]; } Rect4_d530;
typedef struct { u16 flags; u8 pad2[2]; u8 *text; void *ptr; s32 (*cb)(s32); s32 min; s32 max; s32 def; s32 step; u8 size; u8 pad21[3]; } Item_d530;
typedef struct { s16 x; s16 y; Item_d530 *items; } MenuDef_d530;
typedef struct { s16 x; s16 y; Item_d530 *items; s16 w; s16 h; u8 state; u8 mode; s8 n; s8 sel; u16 t0; u16 t1; s16 open; s16 speed; s16 tx; s16 ty; s16 scale; s8 child; s8 redraw; u8 pad20[2]; s16 cx; s16 cy; u8 pad26[2]; s32 val; } Menu_d530;
typedef struct { u8 pad0[2]; s16 clip_y; u8 pad4[0x5A]; s16 disp_y; u8 pad60[0x10]; u32 ot[0x1000]; u32 hud[2]; } DBuf_d530;
typedef struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DBuf_d530 db[2]; u8 pad8100[0x26]; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 f_812C; u8 pad812D[0x18D]; u16 f_82BA; } Game_d530;
typedef struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 trig; } Pad_d530;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4_d530;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_d530;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_d530;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_d530;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_d530;
typedef struct { s16 vx, vy, vz, pad; } SVec_d530;
typedef struct { s32 vx, vy, vz, pad; } Vec_d530;
extern Game_d530 g_Game_d530 asm("g_Game");
extern Pad_d530 g_Pad_d530 asm("g_Pad");
extern u16 D_800BEF60_d530 asm("D_800BEF60");
extern u16 D_800BEF62_d530 asm("D_800BEF62");
extern u16 D_800BEF64_d530 asm("D_800BEF64");
extern Menu_d530 D_800F5270_d530[] asm("D_800F5270");
extern Item_d530 D_800B21D0[];
extern u8 D_800F4C50[];
extern char D_800A60B4[];
extern char D_800A60BC[];
extern char D_800A60C0[];
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void func_8008C390(void);
s32 Stage_UpdateAreaState(void);
void SetDrawMove(void *p, void *rect, s32 x, s32 y);
void SetDrawArea(void *p, void *r);
void SetDrawTPage(void *p, s32 dfe, s32 dtd, s32 tpage);
void DrawPrim(void *p);
void func_8008C3C0(s32, s32);
void DebugFont_Printf(char *, ...);
void func_8007D188(void *p, s32 v, s32 size);
s32 func_8007D2D8_d530(MenuDef_d530 *def) asm("func_8007D2D8");
s32 Game_SetMode(s32, s32, s32);
void Sound_PlayFixed_d530(s32) asm("Sound_PlayFixed");
void RotMatrixZYX_d530(SVec_d530 *, Mat_d530 *) asm("RotMatrixZYX");
void ScaleMatrix_d530(Mat_d530 *, Vec_d530 *) asm("ScaleMatrix");
void Model_ProjectVerts_d530(void *, Mat_d530 *, void *) asm("Model_ProjectVerts");
void func_80017CD4_d530(u32 *, void *, void *) asm("Model_Draw");
void Ot_SkipEmptyRuns(u32 *);
s32 DrawSync(s32);
s32 VSync(s32);
void *PutDrawEnv_d530(void *) asm("PutDrawEnv");
void *PutDispEnv_d530(void *) asm("PutDispEnv");
void DrawOTag_d530(u32 *) asm("DrawOTag");
#define G_d530 g_Game_d530
#define ADDP_d530(n) (((PTag_d530 *)G_d530.prim)->addr = ((PTag_d530 *)&G_d530.db[G_d530.cur].ot[n])->addr, ((PTag_d530 *)&G_d530.db[G_d530.cur].ot[n])->addr = (u32)G_d530.prim)
#define PG4_d530 ((PolyG4_d530 *)G_d530.prim)
#define PFT4_d530 ((PolyFT4_d530 *)G_d530.prim)
#define SPRT_d530 ((Sprt_d530 *)G_d530.prim)

void func_8007D530(void) {
    s32 i;
    s16 clipy, dispy;
    s32 cur;
    u16 saved;
    s32 quit = 0;
    Rect_d530 r;
    Menu_d530 *m;

    if (D_800BEF60_d530 == 0) {
        return;
    }
    saved = G_d530.f_82BA;
    cur = G_d530.cur;
    G_d530.f_82BA = 1;
    dispy = G_d530.db[cur].disp_y;
    clipy = G_d530.db[cur].clip_y;
    r.x = 0;
    r.y = clipy;
    r.w = 0x17F;
    r.h = 0xEF;
    SetDrawMove(G_d530.prim, &r, 0, dispy);
    DrawPrim(G_d530.prim);
    G_d530.prim += 0x18;
    for (;;) {
        func_8001325C(0);
        if (g_Pad_d530.trig & g_Pad_d530.held & 0x140) break;
        if (G_d530.f_812C == 7) break;
        if (quit) break;
        m = D_800F5270_d530;
        G_d530.frame++;
        Gfx_BeginFrame();
        func_8008C390();
        Stage_UpdateAreaState();
        for (i = 0; i < D_800BEF60_d530; i++, m++) {
            if (m->state == 0) continue;
            m->t0++;
            m->t1++;
            if (m->t1 > 0xFFFD) m->t1 = 0xFFFE;
            if (m->mode == 2) {
                s32 y, k, d;
                s32 tp, cl;
                m->mode = 1;
                r.x = 0;
                r.w = 0x180;
                r.y = 0;
                r.h = 0x200;
                SetDrawArea(G_d530.prim, &r);
                ADDP_d530(0xFFE);
                G_d530.prim += 0xC;
                SetDrawTPage(G_d530.prim, 0, 1, 0x1C);
                ADDP_d530(0xFFD);
                G_d530.prim += 8;
                y = m->y + ((clipy == G_d530.db[1].clip_y) ? 0x100 : -0x100);
                ((u8 *)G_d530.prim)[3] = 8;
                PG4_d530->code = 0x3B;
                PG4_d530->x0 = m->x;
                PG4_d530->y0 = y;
                PG4_d530->x1 = m->x + m->w;
                PG4_d530->y1 = y;
                PG4_d530->x2 = m->x;
                PG4_d530->y2 = m->h + y;
                PG4_d530->x3 = m->x + m->w;
                PG4_d530->y3 = m->h + y;
                PG4_d530->r0 = 0;
                PG4_d530->g0 = 0xF0;
                PG4_d530->b0 = 0xDC;
                PG4_d530->r1 = 0;
                PG4_d530->g1 = 0x3E;
                PG4_d530->b1 = 0x2D;
                PG4_d530->r2 = 0;
                PG4_d530->g2 = 0x2D;
                PG4_d530->b2 = 0x5F;
                PG4_d530->r3 = 0;
                PG4_d530->g3 = 0xA;
                PG4_d530->b3 = 0x28;
                ADDP_d530(0xFFC);
                G_d530.prim += 0x24;
                {
                    Rect4_d530 rr = { { { m->x, y, 7, m->h },
                                        { m->x + m->w - 1, m->h + y, -7, ~m->h },
                                        { m->x, y, m->w, 5 },
                                        { m->x + m->w, m->h + y, -m->w, -6 } } };
                    tp = 0x5C;
                    cl = 0x7F2C;
                    for (k = 0; k < 2; k++) {
                        d = k * 4 - 0x11;
                        ((u8 *)G_d530.prim)[3] = 8;
                        PG4_d530->code = 0x3B;
                        PG4_d530->x0 = m->x + k * (m->w - 7);
                        PG4_d530->y0 = y + 5;
                        PG4_d530->x1 = m->x + k * (m->w - 7) + 7;
                        PG4_d530->y1 = y + 5;
                        PG4_d530->x2 = m->x + k * (m->w - 7);
                        PG4_d530->y2 = y - d;
                        PG4_d530->x3 = m->x + k * (m->w - 7) + 7;
                        PG4_d530->y3 = y - d;
                        PG4_d530->r0 = 0x4C;
                        PG4_d530->g0 = 0x4C;
                        PG4_d530->b0 = 0x42;
                        PG4_d530->r1 = 0x42;
                        PG4_d530->g1 = 0x42;
                        PG4_d530->b1 = 0x38;
                        PG4_d530->r2 = 0x10;
                        PG4_d530->g2 = 0x10;
                        PG4_d530->b2 = 6;
                        PG4_d530->r3 = 0;
                        PG4_d530->g3 = 0;
                        PG4_d530->b3 = 0;
                        ADDP_d530(0xFFB);
                        G_d530.prim += 0x24;
                    }
                    for (k = 3; k >= 0; k--) {
                        Rect_d530 *q;
                        ((u8 *)G_d530.prim)[3] = 9;
                        PFT4_d530->code = 0x2D;
                        PFT4_d530->x0 = rr.r[k].x;
                        PFT4_d530->y0 = rr.r[k].y;
                        PFT4_d530->x1 = rr.r[k].x + rr.r[k].w;
                        PFT4_d530->y1 = rr.r[k].y;
                        PFT4_d530->x2 = rr.r[k].x;
                        PFT4_d530->y2 = rr.r[k].y + rr.r[k].h;
                        PFT4_d530->x3 = rr.r[k].x + rr.r[k].w;
                        PFT4_d530->y3 = rr.r[k].y + rr.r[k].h;
                        if (k < 2) {
                            PFT4_d530->u0 = 0xF0;
                            PFT4_d530->v0 = 0x88;
                            PFT4_d530->u1 = 0xF8;
                            PFT4_d530->v1 = 0x88;
                            PFT4_d530->u2 = 0xF0;
                            PFT4_d530->v2 = 0xC8;
                            PFT4_d530->u3 = 0xF8;
                            PFT4_d530->v3 = 0xC8;
                        } else {
                            PFT4_d530->u0 = 0xB8;
                            PFT4_d530->v0 = 0x80;
                            PFT4_d530->u1 = 0xF8;
                            PFT4_d530->v1 = 0x80;
                            PFT4_d530->u2 = 0xB8;
                            PFT4_d530->v2 = 0x88;
                            PFT4_d530->u3 = 0xF8;
                            PFT4_d530->v3 = 0x88;
                        }
                        ADDP_d530(0xFFB);
                        PFT4_d530->tpage = tp;
                        PFT4_d530->clut = cl;
                        G_d530.prim += 0x28;
                    }
                }
            }
            if (m->redraw == 0 && i != D_800BEF62_d530 && m->mode == 0 && m->t1 >= 0x15) continue;
            if (m->t1 < 0x15) {
                s32 o = m->open * 96 / m->h;
                s32 xx = o - 0x76;
                if (m->x + m->w / 2 + xx > 0) {
                    s32 yy;
                    r.x = m->x + m->w / 2 + xx;
                    yy = o - 0x6A;
                    r.y = clipy + (m->y + yy);
                    r.w = 0x12;
                    r.h = 0x12;
                    SetDrawMove(G_d530.prim, &r, m->x + m->w / 2 + xx, m->y + yy + dispy);
                    ADDP_d530(0xFF8);
                    G_d530.prim += 0x18;
                }
            }
            m->speed = m->speed * 9 / 10;
            if (m->speed < 2) m->speed = 2;
            m->open += m->speed;
            if (m->h < m->open) m->open = m->h;
            if (m->mode != 0) {
                s32 j, yo, n;
                r.x = m->x;
                r.y = m->y + clipy;
                r.w = m->w;
                r.h = m->open;
                SetDrawMove(G_d530.prim, &r, m->x, m->y + dispy);
                ADDP_d530(0xFFA);
                G_d530.prim += 0x18;
                for (j = 0; j < m->n; j++) {
                    func_8008C3C0(m->x + m->tx, m->y + (m->ty + j * 10) * m->open / m->h);
                    if (m->items[j].ptr == NULL && (m->items[j].flags & 0x8000)) {
                        DebugFont_Printf(D_800A60B4, m->items[j].text);
                    } else {
                        DebugFont_Printf(D_800A60BC, m->items[j].text);
                    }
                }
            }
            if (m->open == m->h) m->mode = 0;
            {
                s32 o = m->open * 96 / m->h;
                s32 xx = o - 0x76;
                if (m->x + m->w / 2 + xx > 0) {
                    SetDrawTPage(G_d530.prim, 0, 1, 0x1C);
                    ADDP_d530(0xFF7);
                    G_d530.prim += 8;
                    ((u8 *)G_d530.prim)[3] = 4;
                    SPRT_d530->code = 0x65;
                    SPRT_d530->x0 = m->x + m->w / 2 + xx;
                    { s32 yy = o - 0x6A; SPRT_d530->y0 = m->y + yy; }
                    SPRT_d530->w = 0x12;
                    SPRT_d530->h = 0x12;
                    SPRT_d530->u0 = (m->t1 < 0x15) ? ((m->mode == 0) ? (m->t0 & 3) * 24 : 0) : 0;
                    SPRT_d530->v0 = 0xA8;
                    SPRT_d530->clut = 0x7D2C;
                    ADDP_d530(0xFF6);
                    G_d530.prim += 0x14;
                }
            }
            if (m->redraw != 0 || (i == D_800BEF62_d530 && *(u16 *)&m->state == 1)) {
                s32 j, yo, io;
                r.x = m->x;
                r.y = m->cy + clipy - 1;
                r.w = m->w;
                r.h = 10;
                SetDrawMove(G_d530.prim, &r, m->x, m->cy + dispy - 1);
                ADDP_d530(0xFF0);
                G_d530.prim += 0x18;
                r.x = m->cx - 0xC;
                r.y = m->cy + clipy - 0xD;
                r.w = 0x18;
                r.h = 0x1A;
                SetDrawMove(G_d530.prim, &r, m->cx - 0xC, m->cy + dispy - 0xD);
                ADDP_d530(0xFF0);
                G_d530.prim += 0x18;
                for (j = 0; j < m->n; j++) {
                    Item_d530 *it = &m->items[j];
                    func_8008C3C0(m->x + m->tx, m->y + m->ty + j * 10);
                    switch (it->flags) {
                    case 0xC005:
                    case 0xC008:
                        DebugFont_Printf(D_800A60C0, it->text, func_8007D118(it->ptr, it->size));
                        break;
                    case 0x2006:
                        DebugFont_Printf(D_800A60C0, it->text, m->val);
                        break;
                    default:
                        if (it->ptr == NULL && (it->flags & 0x8000)) {
                            DebugFont_Printf(D_800A60B4, it->text);
                        } else {
                            DebugFont_Printf(D_800A60BC, it->text);
                        }
                        break;
                    }
                }
                if (m->mode == 0) m->redraw = 0;
                if (m->state == 1) {
                    Mat_d530 mat;
                    SVec_d530 rot;
                    Vec_d530 sc;
                    MenuDef_d530 d;
                    if (!(g_Pad_d530.held & 0xF000)) {
                        D_800BEF64_d530 = 1;
                    } else if (--D_800BEF64_d530 == 0) {
                        u32 pad;
                        Sound_PlayFixed_d530(1);
                        if (g_Pad_d530.trig & g_Pad_d530.held) D_800BEF64_d530 = 0x14; else D_800BEF64_d530 = 3;
                        pad = g_Pad_d530.held;
                        if (pad & 0x1000) {
                            do {
                                if (--m->sel < 0) m->sel += m->n;
                            } while (!(m->items[m->sel].flags & 0x8000));
                        } else if (pad & 0x4000) {
                            do {
                                if (++m->sel > m->n) m->sel = 0;
                            } while (!(m->items[m->sel].flags & 0x8000));
                        } else if (pad & 0xA000) {
                            Item_d530 *it = (Item_d530 *)(m->sel * sizeof(Item_d530) + (s32)m->items);
                            if (it->flags == 0xC005 || it->flags == 0xC008) {
                                s32 st = it->step;
                                s32 v;
                                if (pad & 8) st += st * 9;
                                v = st;
                                if (!(pad & 0x2000)) v = -v;
                                v = v + func_8007D118(it->ptr, it->size) / v * v;
                                if (v < m->items[m->sel].min) v = m->items[m->sel].max;
                                else if (m->items[m->sel].max < v) v = m->items[m->sel].min;
                                func_8007D188(m->items[m->sel].ptr, v, m->items[m->sel].size);
                                if (m->items[m->sel].flags != 0xC008) {
                                    s32 res = m->items[m->sel].cb(v);
                                    if (res == 1) {
                                        m->redraw = res;
                                        m->mode = res;
                                    }
                                }
                            }
                        }
                        if (m->child != -1) {
                            D_800F5270_d530[m->child].redraw = 1;
                            D_800F5270_d530[m->child].val = m->items[m->sel].def;
                        }
                    }
                    if (g_Pad_d530.trig & g_Pad_d530.held & 0x8A0) {
                        switch (m->items[m->sel].flags) {
                        case 0x8004:
                            Game_SetMode(7, G_d530.f_8126, G_d530.f_812A);
                            Sound_PlayFixed_d530(3);
                            break;
                        case 0x8007:
                        case 0xC008:
                            if (m->items[m->sel].cb != NULL) {
                                s32 res = m->items[m->sel].cb(func_8007D118(m->items[m->sel].ptr, m->items[m->sel].size));
                                if (res == 1) {
                                    m->redraw = res;
                                    m->mode = res;
                                }
                                if (!(g_Pad_d530.held & 0x80)) Sound_PlayFixed_d530(2);
                            }
                            break;
                        case 0x8002:
                        case 0x8003:
                            if (m->items[m->sel].ptr == NULL) {
                                Sound_PlayFixed_d530(0x24);
                                Sound_PlayFixed_d530(0x21);
                            } else {
                                s32 c;
                                d.x = m->x + m->w + 4;
                                d.y = m->y - 4;
                                d.items = m->items[m->sel].ptr;
                                c = func_8007D2D8_d530(&d);
                                if (m->items[m->sel].flags == 0x8003) {
                                    d.x = m->x + 4;
                                    d.y = m->y + m->h + 8;
                                    d.items = D_800B21D0;
                                    D_800F5270_d530[c].child = func_8007D2D8_d530(&d);
                                    D_800F5270_d530[D_800F5270_d530[c].child].redraw = 1;
                                    D_800F5270_d530[D_800F5270_d530[c].child].val = D_800F5270_d530[c].items->def;
                                }
                                if (m->items[m->sel].cb != NULL) {
                                    m->items[m->sel].cb(0);
                                }
                            }
                            break;
                        default:
                            quit = 1;
                            break;
                        }
                    }
                    if (g_Pad_d530.trig & g_Pad_d530.held & 2) {
                        func_8007D188(m->items[m->sel].ptr, m->items[m->sel].def, m->items[m->sel].size);
                    }
                    m->cx = m->x + m->tx - 0xE;
                    m->cy = m->y + m->ty + m->sel * 10;
                    {
                        u32 c, ci;
                        rot.vx = (((m->t0 + 0x50) >> 1) << 12) / 360 % 1024;
                        if (rot.vx > 0x200) rot.vx = 0x400 - rot.vx;
                        rot.vx = (rot.vx + 0xF00) % 0x1000;
                        rot.vy = (m->t0 * 3 << 12) / 360 % 0x1000;
                        rot.vz = 0;
                        RotMatrixZYX_d530(&rot, &mat);
                        mat.t[0] = m->cx - 0xC0;
                        mat.t[1] = m->cy - 0x76;
                        mat.t[2] = 0x180;
                        sc.vx = sc.vy = sc.vz = m->scale;
                        ScaleMatrix_d530(&mat, &sc);
                        Model_ProjectVerts_d530(D_800F4C50, &mat, g_ProjVerts);
                        func_80017CD4_d530(G_d530.db[G_d530.cur].ot, g_ProjVerts, D_800F4C50);
                        ((u8 *)G_d530.prim)[3] = 8;
                        PG4_d530->code = 0x38;
                        PG4_d530->x0 = m->cx + 10;
                        PG4_d530->y0 = m->cy - 1;
                        PG4_d530->x1 = m->cx + (s16)(m->w - 0x20);
                        PG4_d530->y1 = m->cy - 1;
                        PG4_d530->x2 = m->cx + 10;
                        PG4_d530->y2 = m->cy + 9;
                        PG4_d530->x3 = m->cx + (s16)(m->w - 0x20);
                        PG4_d530->y3 = m->cy + 9;
                        c = (m->t0 & 0x7F) * 4;
                        if (c >= 0x100) c = 0x1FF - c;
                        ci = c ^ 0xFF;
                        *(u32 *)&PG4_d530->r0 = ((c << 16) | (ci << 8)) | 0x39000000;
                        *(u32 *)&PG4_d530->r1 = c | (ci << 16);
                        *(u32 *)&PG4_d530->r2 = (c << 8) | ci;
                        *(u32 *)&PG4_d530->r3 = (c << 16) | (ci << 8);
                        ADDP_d530(0xFEF);
                        G_d530.prim += 0x24;
                    }
                }
            }
        }
        Ot_SkipEmptyRuns(G_d530.db[G_d530.cur].ot);
        DrawSync(0);
        VSync(0);
        PutDrawEnv_d530(&G_d530.db[cur ^ 1]);
        PutDispEnv_d530((u8 *)&G_d530.db[cur] + 0x5C);
        DrawOTag_d530(G_d530.ot + 0xFFF);
    }
    D_800BEF60_d530 = 0;
    D_800BEF62_d530 = 0;
    G_d530.f_82BA = saved;
    func_8001325C(0);
}

INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", D_800A60B4);
INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", D_800A60BC);
INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", D_800A60C0);


void func_8007F400(void) {
    g_CheatInput = 0;
}

/* Pause-screen cheat codes. Each newly pressed D-pad or shoulder button is shifted
 * in as a digit (Up 1, Down 2, Left 3, Right 4, L1 5, L2 6, R1 7, R2 8); when the last 8
 * presses equal one of the 5 codes: explosive ammo capacity 49/99, guided capacity 49/99, or Spike's
 * idle animation. See docs/findings.md.
 */
void Cheat_CheckCodes(void) {
    u32 b = g_Pad.f_158 & g_Pad.f_160;
    s32 k = 0;
    s32 i;
    if (b & 0x1000) {
        k = 1;
    }
    if (b & 0x4000) {
        k = 2;
    }
    if (b & 0x8000) {
        k = 3;
    }
    if (b & 0x2000) {
        k = 4;
    }
    if (b & 4) {
        k = 5;
    }
    if (b & 1) {
        k = 6;
    }
    if (b & 8) {
        k = 7;
    }
    if (b & 2) {
        k = 8;
    }
    if (k == 0) {
        return;
    }
    (*(u32 *)&g_CheatInput) = ((*(u32 *)&g_CheatInput) << 4) | k;
    for (i = 0; i < 5; i++) {
        if ((*(u32 *)&g_CheatInput) == g_CheatCodes[i]) {
            switch (i) {
            case 0:
                D_800F4350.f_154 = 49;
                break;
            case 1:
                D_800F4350.f_156 = 49;
                break;
            case 2:
                D_800F4350.f_154 = 99;
                break;
            case 3:
                D_800F4350.f_156 = 99;
                break;
            case 4:
                ((struct S_D_800EC1E0_8007F40C *)&g_Spike)->f_148 = 0x37A;
                break;
            }
            Sound_PlayFixed(0xD);
            (*(u32 *)&g_CheatInput) = 0;
            return;
        }
    }
}



void func_8007F560(s8 arg0) {
    D_800BEF74.f_0 = arg0;
}

void func_8007F56C(s32 a) {
    D_800BEF74.f_1 = 0;
    func_8007F400();
    if (a != 1) {
        a = 1;
        D_800BEF74.f_1 = 1;
        D_800BEF74.f_2 = a;
    } else {
        D_800BEF74.f_2 = 0xF;
        func_8005DD28();
    }
    D_800BEF74.f_0 = a;
}

s8 func_8007F5D4(void) {
    return D_800BEF74.f_0;
}

/* Pause menu: draws menu model D_800F4CA0[kind 0/1/2 -> 2/3/1, else 0] at screen offset (x, y) from
 * the centre into the primitive buffer prim, returning the new buffer end. mode >= 0 spins it with
 * the frame counter. The pause state D_800BEF74 sets the scale: 2 shrinks the menu in (also pulling
 * x, y in), 1 and 3 scale by the timer f_2 (mode -1 grows instead). If func_80082030 says the
 * item is unavailable here, 0x1F8003C8 is set (drawn dimmed) and it does not spin. */
s32 PauseMenu_DrawItemModel(s32 x, s32 y, s32 kind, s32 mode, s32 prim) {
    SV_7F5E4_8007F5E4 pos;
    SV_7F5E4_8007F5E4 rot;
    V_7F5E4_8007F5E4 scale;
    s32 s;
    s32 t;
    s32 u;
    u8 *sp = (u8 *)0x1F800000;

    if (mode >= 0) {
        rot.vx = rcos((*(struct Game_7F5E4 *)&g_Game).frame << 6) >> 4;
        rot.vy = rsin((*(struct Game_7F5E4 *)&g_Game).frame << 6) >> 4;
        rot.vz = 0;
    } else {
        rot.vx = 0;
        rot.vy = 0;
        rot.vz = 0;
    }
    switch (D_800BEF74.f_0) {
    case 1:
        u = 0x1000 - (D_800BEF74.f_2 << 8);
        scale.vx = u;
        scale.vy = u;
        scale.vz = u;
    case 3:
        if (mode == -1) {
            t = D_800BEF76 * 3 << 9;
        } else {
            t = 0x1000 - (D_800BEF76 << 8);
        }
        scale.vx = t;
        scale.vy = t;
        scale.vz = t;
        break;
    case 2:
        s = 0x1000 - (D_800BEF74.f_2 << 6);
        if (s < 0x800) {
            s = 0x800;
        }
        x = x * s >> 12;
        y = y * s >> 12;
        scale.vx = s;
        scale.vy = s;
        scale.vz = s;
        break;
    }
    pos.vx = x + 0xC0;
    pos.vy = y + 0x78;
    pos.vz = 0x148;
    D_800EC354 = prim;
    switch (kind) {
    case 0:
        kind = 2;
        break;
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 1;
        break;
    default:
        kind = 0;
        break;
    }
    if (func_80082030(kind)) {
        *(s32 *)(sp + 0x3C8) = 0;
    } else {
        *(s32 *)(sp + 0x3C8) = 1;
        rot.vx = 0;
        rot.vy = 0;
        rot.vz = 0;
    }
    Model_DrawOnScreen(&D_800F4CA0[kind], &pos, &rot, &scale);
    return D_800EC354;
}

void func_8007F830(void) {
    M2C_FIELD(&D_800BEF78, s32 *, 0) = 0;
    M2C_FIELD(&D_800BEF78, s32 *, 4) = 0xEF;
}

void func_8007F848(void) {
    RECT16_8007F848 r;
    s32 n = D_800BEF7C;
    r.x = 0;
    r.w = 0x180;
    if (n > 0) {
        r.h = n;
        r.y = (D_800EC35C != 0) << 8;
        LoadImage(&r, (u32 *)0x801A8000);
    }
    if (n < 0xF0) {
        r.h = 0xF0 - n;
        r.y = D_800EC35C != 0 ? n + 0x100 : n;
        LoadImage(&r, (u32 *)(0x801A8000 + (n + 2) * 0x300));
    }
}

typedef struct { s16 off; s16 shift; } S_Tap_7F8F4;
extern S_Tap_7F8F4 D_800B2704[9];

void func_8007F8F4(s32 row)
{
  u16 *p = ((u16 *) 0x801A8002) + (row * 0x180);
  s32 x;
  s32 j;
  register s32 r asm("$8");
  register s32 g asm("$9");
  register s32 b asm("$10");
  s32 ir1;
  s32 ir2;
  s32 ir3;
  s32 v;
  for (x = 0; x < 0x17E; x++)
  {
    r = 0;
    g = 0;
    b = 0;
    for (j = 0; j < 9; j++)
    {
      s32 sh;
      asm volatile("mtc2 %0, $28" : : "r"(p[D_800B2704[j].off]));
      sh = D_800B2704[j].shift;
      asm volatile("mfc2 %0, $9" : "=r"(ir1));
      asm volatile("mfc2 %0, $10" : "=r"(ir2));
      asm volatile("mfc2 %0, $11" : "=r"(ir3));
      r += ir1 << sh;
      g += ir2 << sh;
      b += ir3 << sh;
    }

    r >>= 4;
    g >>= 4;
    b >>= 4;
    asm volatile("mtc2 %0, $9; nop; mtc2 %1, $10; nop; mtc2 %2, $11" : : "r"(r), "r"(g), "r"(b));
    asm volatile("nop; nop; nop; mfc2 %0, $29; nop" : "=r"(v));
    p[0x300] = v;
    p++;
  }

}

void func_8007F9D0(void) {
    s32 i;
    s32 lim;
    if (((struct S_D_800BEF78_8007F9D0 *)&D_800BEF78)->done == 0) {
        i = ((struct S_D_800BEF78_8007F9D0 *)&D_800BEF78)->n;
        lim = 0;
        if (i >= 4) {
            lim = i - 4;
        }
        for (; i >= lim; i--) {
            func_8007F8F4(i);
        }
        ((struct S_D_800BEF78_8007F9D0 *)&D_800BEF78)->n = lim;
        if (lim == 0) {
            ((struct S_D_800BEF78_8007F9D0 *)&D_800BEF78)->done = 1;
        }
    }
}

/* MATCH (r36): check_c MATCH + full SCUS link OK with both INCLUDE_RODATA deletions. Note: D_800F51C4 is g_GadgetState.owned (0x800F5120+0xA4). */
void Cheat_CheckCodes(void);
void func_8007F830(void);
void func_8007F848(void);
void func_8007F9D0(void);
typedef struct { s16 x, y, w, h; } Rect_pm;
typedef struct { s32 vx, vy, vz, pad; } Vec_pm;
typedef struct { s16 vx, vy, vz, pad; } SVec_pm;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 hud[2]; } DBuf_pm;
typedef struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DBuf_pm db[2]; u8 pad8100[0x22]; u16 f_8122; u8 pad8124[0x18]; u16 f_813C; u8 pad813E[2]; s32 f_8140; } Game_pm;
typedef struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 trig; u8 pad164[4]; u32 rep; } Pad_pm;
typedef struct { s8 state; s8 f_1; s16 t; } Pause_pm;
typedef struct { u8 pad0[0x88]; s8 slot[4]; u8 pad8C[0x18]; u32 owned; } GState_pm;
typedef struct { s16 f_0; u8 pad2[2]; s16 f_4; u8 pad6[0x16]; s16 f_1C; u8 pad1E[2]; s32 f_20; } HudSt_pm;
typedef struct { u8 b[16]; } Mdl_pm;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; u32 xy; u32 uvc; u32 wh; } HiSpr_pm;
extern Game_pm g_Game_pm asm("g_Game");
extern Pad_pm g_Pad_pm asm("g_Pad");
extern Pause_pm D_800BEF74_pm asm("D_800BEF74");
extern GState_pm g_GadgetState_pm asm("g_GadgetState");
extern HudSt_pm D_800F4DB0;
extern u8 *D_800B25A0[][5];
extern Mdl_pm g_GadgetModels[];
extern struct S_D_800AF0A0 D_800E78C0_pm asm("g_ViewMatrix");
extern u8 D_800B267C[];
extern u8 D_800B2690[];
extern u8 D_800B2694[];
extern u8 D_800B2698[];
extern u8 D_800B26BC[];
void DrawSync_pm(s32) asm("DrawSync");
void VSync_pm(s32) asm("VSync");
void *PutDispEnv_pm(void *) asm("PutDispEnv");
void *PutDrawEnv_pm(void *) asm("PutDrawEnv");
s32 StoreImage_pm(void *, u32 *) asm("StoreImage");
u32 *ClearOTagR_pm(u32 *, s32) asm("ClearOTagR");
void DrawOTag_pm(u32 *) asm("DrawOTag");
s32 func_8008C09C(s32);
void func_8008C064(s32);
void func_80095244(s32, void *);
void func_80095600(s32, s32);
void func_800958C0(s32);
s32 Game_IsTimed(void);
void func_80081B9C(s32 mode);
void func_8008227C(s32 arg0);
void func_8005DD18(void);
void Sound_PlayFixed_pm(s32) asm("Sound_PlayFixed");
void func_80081D54(void);
s32 PauseMenu_DrawItemModel_pm(s32, s32, s32, s32, s32, u32 *) asm("PauseMenu_DrawItemModel");
void func_80082D40(void);
s32 Text_GetWidth(u8 *s);
void Menu_DrawCaps(s32 x, s32 y, s32 w);
void RotMatrixZ_pm(s32, void *) asm("RotMatrixZ");
void RotMatrixY_pm(s32, void *) asm("RotMatrixY");
void RotMatrixX_pm(s32, void *) asm("RotMatrixX");
void ScaleMatrix_pm(void *, void *) asm("ScaleMatrix");
s32 func_8008DE68_pm(u8 *, s32) asm("func_8008DE68");
void MagicPunch_Draw(void *, s32, s32);
void Radar_DrawModel(void *, void *, void *, s32);
void Club_Draw(void *, s32, s32);
void func_80017CD4_pm(u32 *, void *, void *) asm("Model_Draw");
void Model_DrawWireframe(u32 *, void *, void *);
s32 func_80066F50(void);
s32 Gadget_Select(s32, s32);
void func_80081144(s32, s8);
void Hud_DrawGadgets(void);
void SetPriority_pm(void *, s32, s32) asm("SetPriority");
void Menu_DrawStatusScreen(void);
void PauseMenu_DrawStageInfo(void);
s32 OptionsMenu_Update(void);
void Hud_DrawTimerClock(s32, s32, s32);
void Hud_DrawTime(s32, s32, u32);
s32 func_8005DD34(void);
void func_8005FFD4(s32);
void Hud_DrawMonkeyHeads(s32, s32);
void Hud_DrawHealth(void);
void Hud_DrawLivesIcon(s32, s32);
void Hud_DrawBigDigit(s32, s32, s32);
void Hud_DrawBigNumber(s32, s32, s32);
void func_8005FD80(void);
void Hud_UpdateStatusIcons(void);
void Cd_Update(void);
void bios_printf_pm(char *, ...) asm("bios_printf");
void func_800729CC(void);
#define gte_SetGeomScreen_pm(h) __asm__ volatile ("ctc2 %0, $26" : : "r"(h))
#define G_pm g_Game_pm
#define PS_pm D_800BEF74_pm
#define PAD_pm (g_Pad_pm.held & g_Pad_pm.trig)
#define ADDPRIM_pm(ot, p) { u32 _a, _b; __asm__ volatile("lwl %0, 2(%2)\n\tsll %1, %4, 8\n\tswl %1, 2(%2)\n\tswl %0, %3" : "=&r"(_a), "=&r"(_b) : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p)); }

s32 PauseMenu_Update(void) {
    struct S_D_800AF0A0 m;
    struct S_D_800AF0A0 m2;
    s32 bufs[2];
    Rect_pm r;
    Vec_pm sc;
    SVec_pm sv;
    struct S_D_800AF0A0 m3;
    SVec_pm rot;
    u32 *ot;
    s32 h;
    s32 i;
    s32 sel;
    register s32 ret asm("$21");
    u8 *prim;

    DrawSync_pm(0);
    VSync_pm(0);
    PutDispEnv_pm((u8 *)&G_pm.db[G_pm.cur ^ 1] + 0x5C);
    PutDrawEnv_pm(&G_pm.db[G_pm.cur ^ 1]);
    __asm__ volatile("cfc2 %0, $26" : "=r"(h));
    gte_SetGeomScreen_pm(0x148);
    r.w = 0x180;
    r.h = 0xF0;
    r.x = 0;
    r.y = (G_pm.cur != 0) << 8;
    StoreImage_pm(&r, (u32 *)0x801A8000);
    DrawSync_pm(0);
    func_8007F830();
    bufs[0] = func_8008C09C(0x9000);
    bufs[1] = func_8008C09C(0x9000);
    D_800F4DB0.f_20 |= 0x10;
    func_80095244(1, &D_800F4DB0);
    func_80095600(1, 0);
    if (Game_IsTimed() == 0) {
        func_800958C0(1);
    }
    func_80081B9C(0);
    func_80081B9C(1);
    func_8008227C(1);
    DrawSync_pm(0);
    VSync_pm(2);
    do {
        func_8001325C(2);
        G_pm.cur ^= 1;
        G_pm.frame++;
        ClearOTagR_pm(G_pm.db[G_pm.cur].ot, 0x1000);
        G_pm.prim = (u8 *)bufs[G_pm.cur];
        *G_pm.db[G_pm.cur].hud = 0xFFFFFF;
        ot = G_pm.db[G_pm.cur].ot;
        G_pm.ot = ot;
        func_8008C390();
        prim = G_pm.prim;
        if (PS_pm.f_1 != 0) {
            PS_pm.f_1 = 0;
            if (func_80082030(0)) {
                ret = 0;
                sel = 0;
                PS_pm.state = 10;
                PS_pm.t = 0;
                func_80081B9C(2);
                func_8005DD18();
            } else {
                PS_pm.t = 0xF;
                PS_pm.state = 1;
            }
        }
        switch (PS_pm.state) {
        case 2:
            Cheat_CheckCodes();
            if (PS_pm.t < 0x100) {
                PS_pm.t++;
            }
            ret = 0;
            func_8008DDB0(0x100, 0xAA);
            func_8008DDC8(D_800B269C);
            func_80081D54();
            prim = G_pm.prim;
            { s32 c;
            for (i = 0; i < 4; i++) {
                s32 a = i << 10;
                s32 b;
                c = rcos(a) / 52;
                b = rsin(a);
                __asm__("" :: "r"(a), "r"(a), "r"(a));
                prim = (u8 *)PauseMenu_DrawItemModel_pm(c, b / 74, i, PS_pm.t, (s32)prim, ot);
            }
            if ((PAD_pm & 0x20) && ({ __asm__("" :: "r"(c)); func_80082030(2); })) {
                Sound_PlayFixed_pm(3);
                PS_pm.state = 11;
                PS_pm.t = 0;
                func_80081B9C(3);
            }
            }
            if ((PAD_pm & 0x80) && func_80082030(1)) {
                Sound_PlayFixed_pm(3);
                sel = 1;
                PS_pm.state = 4;
                PS_pm.t = 0;
                func_80081B9C(4);
            }
            if (PAD_pm & 0x10) {
                if (func_80082030(0)) {
                    ret = 0;
                    sel = 0;
                    PS_pm.state = 10;
                    PS_pm.t = 0;
                    func_80081B9C(2);
                    Sound_PlayFixed_pm(3);
                }
            }
            if (PAD_pm & 0x40) {
                if (func_80082030(3)) {
                    ret = 0;
                    sel = 0;
                    PS_pm.state = 12;
                    PS_pm.t = 0;
                    func_80081B9C(5);
                    Sound_PlayFixed_pm(3);
                    func_80082D40();
                }
            }
            if (PAD_pm & 0xC00) {
                ret = 0;
                PS_pm.state = 3;
                PS_pm.t = 0;
                Sound_PlayFixed_pm(1);
            }
            break;
        case 1:
            for (i = 0; i < 4; i++) {
                prim = (u8 *)PauseMenu_DrawItemModel_pm(rcos((PS_pm.t << 7) + (i << 10)) / (0x34 - PS_pm.t * 2), rsin((PS_pm.t << 7) + (i << 10)) / (0x4A - PS_pm.t * 2), i, 0, (s32)prim, ot);
            }
            if (--PS_pm.t == 0) {
                PS_pm.state = 2;
            }
            if (PAD_pm & 0x800) {
                PS_pm.state = 3;
                ret = 0;
                Sound_PlayFixed_pm(0x10);
            }
            break;
        case 3:
            for (i = 0; i < 4; i++) {
                prim = (u8 *)PauseMenu_DrawItemModel_pm(rcos((PS_pm.t << 7) + (i << 10)) / (0x34 - PS_pm.t * 2), rsin((PS_pm.t << 7) + (i << 10)) / (0x4A - PS_pm.t * 2), i, 0x20, (s32)prim, ot);
            }
            if (++PS_pm.t >= 0x10) {
                switch (ret) {
                case 1:
                    PS_pm.state = 11;
                    break;
                case 4:
                    PS_pm.state = 10;
                    sel = 0;
                    break;
                default:
                    PS_pm.state = 0;
                    break;
                }
            }
            break;
        case 4: {
            s32 w;
            u32 pad;
            G_pm.prim = prim;
            Text_Draw(D_800B267C, (0x180 - Text_GetWidth(D_800B267C)) >> 1, 0x64, 2);
            Text_Draw(D_800B2690, (0x180 - Text_GetWidth(D_800B2690)) >> 1, 0x78, 2);
            Text_Draw(D_800B2694, (0x180 - Text_GetWidth(D_800B2694)) >> 1, 0x8C, 2);
            Text_Draw(D_800B2698, (0x180 - Text_GetWidth(D_800B2698)) >> 1, 0xA0, 2);
            if (Game_IsTimed()) {
                Text_Draw(D_800B26BC, (0x180 - Text_GetWidth(D_800B26BC)) >> 1, 0xB4, 2);
            }
            pad = g_Pad_pm.rep;
            if (pad & 0x5000) {
                Sound_PlayFixed_pm(0);
                if (pad & 0x1000) {
                    sel--;
                } else {
                    sel++;
                }
            }
            if (Game_IsTimed()) {
                sel = (sel + 3) % 3;
            } else {
                sel = (sel + 2) & 1;
            }
            w = 0x60;
            switch (sel) {
            case 0:
                w = Text_GetWidth(D_800B2694) + 0x30;
                break;
            case 1:
                w = Text_GetWidth(D_800B2698) + 0x30;
                break;
            case 2:
                w = Text_GetWidth(D_800B26BC) + 0x30;
                break;
            }
            Menu_DrawCaps(0xC0, sel * 20 + 0x8C, w);
            __asm__ volatile("lw %0, %1" : "=r"(prim) : "m"(G_pm.prim));
            Menu_DrawWindow(0x5C, 0x50, 0xC0, Game_IsTimed() ? 0x80 : 0x70);
            func_80081D54();
            prim = G_pm.prim;
            if (PAD_pm & 0x8F0) {
                switch (sel) {
                case 0:
                    PS_pm.state = 3;
                    ret = 3;
                    Sound_PlayFixed_pm(3);
                    break;
                case 1:
                    PS_pm.state = 2;
                    PS_pm.t = 0x100;
                    Sound_PlayFixed_pm(1);
                    break;
                case 2:
                    PS_pm.state = 3;
                    ret = 2;
                    Sound_PlayFixed_pm(3);
                    break;
                }
                func_80081B9C(1);
            }
            break;
        }
        case 10: {
            s32 pad;
            func_8005DD18();
            G_pm.prim = prim;
            for (i = 0; i < 8; i++) {
                s32 row, col, c3, r3; s16 cx; s16 cy;
                struct S_D_800AF0A0 *mp, *lm;
                Matrix_SetIdentity(&m);
                row = i / 4;
                col = i - row * 4;
                c3 = col * 3; r3 = row * 3;
                m.t[0] = c3 * 32 - 0x100;
                m.t[1] = r3 * 32 - 0x40;
                m.t[2] = 0x290;
                RotMatrixZ_pm(0x8C8, &m);
                __asm__("" :: "r"(r3));
                RotMatrixY_pm((G_pm.frame + i) << 5, &m);
                if (i == sel) {
                    HiSpr_pm *p = (HiSpr_pm *)G_pm.prim;
                    s32 pulse = G_pm.frame & 0xF;
                    s32 j, k;
                    s16 yy, xx;
                    if (pulse >= 8) {
                        pulse = (pulse - 8) ^ 7;
                    }
                    pulse >>= 1;
                    cx = c3 * 16 + 0x30;
                    cy = r3 * 16 + 0x40;
                    for (yy = cy - pulse, j = 0; j < 0x11; yy += (pulse + 0x10) + pulse, j += 0x10) {
                        for (xx = cx - pulse, k = 0; k < 0x11; k += 0x10, xx += (pulse + 0x10) + pulse) {
                            ((u8 *)p)[3] = 5;
                            p->tpage = 0xE100023D;
                            p->code = 0x65;
                            p->xy = (yy << 16) | xx;
                            { u32 t = (k + 0x80) | 0x70F70000; p->uvc = ((j + 0x40) << 8) | t; }
                            p->wh = 0x100010;
                            ADDPRIM_pm(ot, p);
                            p++;
                            __asm__(""); __asm__(""); __asm__(""); /* sets global-alloc priorities of the j/yy loop vars */
                        }
                    }
                    G_pm.prim = (u8 *)p;
                    if ((1 << i) & g_GadgetState_pm.owned) {
                        u8 **nm = (u8 **)((u8 *)D_800B25A0 + i * 20);
                        s32 w = func_8008DE68_pm(nm[0], 0);
                        w = w / 2 - 0x10;
                        func_8008DDB0((s16)(cx - w), (s16)(cy + 0x20));
                        func_8008DDC8(nm[0]);
                        func_8008DDB0(0x10, 0xA8);
                        func_8008DDC8(nm[1]);
                        func_8008DDB0(0x10, 0xB8);
                        func_8008DDC8(nm[2]);
                        func_8008DDB0(0x10, 0xC8);
                        func_8008DDC8(nm[3]);
                    }
                } else {
                    sc.vx = 0x800;
                    sc.vy = 0x800;
                    sc.vz = 0x800;
                    ScaleMatrix_pm(&m, &sc);
                }
                mp = &m;
                m2 = m;
                CompMatrix(&D_800AF0A0, mp, mp);
                lm = &m2;
                if ((1 << i) & g_GadgetState_pm.owned) {
                    Mdl_pm *mdl;
                    switch (i) {
                    case 0:
                        MagicPunch_Draw(mp, 0, 0x800);
                        break;
                    case 2:
                        { s32 a = G_pm.frame << 6;
                        sv.vz = rcos(a);
                        sv.vx = rsin(a); }
                        if (sel == i) {
                            sv.vy = 0;
                        } else {
                            sv.vy = 0x800;
                        }
                        D_800E78C0_pm = D_800AF0A0;
                        Radar_DrawModel(&m, &m2, &sv, G_pm.frame << 7);
                        break;
                    case 7:
                        mdl = &g_GadgetModels[7];
                        Model_ProjectVerts(mdl, mp, g_ProjVerts);
                        func_80017CD4_pm(ot, g_ProjVerts, mdl);
                        m.t[0] += 0x40;
                        RotMatrixX_pm(0x800, mp);
                        Model_ProjectVerts(&g_GadgetModels[11], mp, g_ProjVerts);
                        func_80017CD4_pm(ot, g_ProjVerts, &g_GadgetModels[11]);
                        break;
                    case 5:
                        Matrix_SetIdentity(&m3);
                        m3.t[1] = -0xC8;
                        rot.vx = 0x400;
                        rot.vy = 0;
                        rot.vz = 0;
                        RotMatrixZYX(&rot, &m3);
                        CompMatrix(lm, &m3, &m3);
                        Club_Draw(&m3, 0x555, 0);
                        break;
                    default:
                        { Mdl_pm *md = &g_GadgetModels[i];
                        Model_ProjectVerts(md, &m, g_ProjVerts);
                        func_80017CD4_pm(ot, g_ProjVerts, md); }
                        break;
                    }
                } else {
                    Model_ProjectVerts(g_GadgetModels, mp, g_ProjVerts);
                    Model_DrawWireframe(ot, g_ProjVerts, g_GadgetModels);
                }
            }
            func_8008DDB0(0x114, 0x8A);
            func_8008DDC8(D_800B269C);
            prim = G_pm.prim;
            pad = PAD_pm;
            if (pad & 0xF000) {
                Sound_PlayFixed_pm(0);
                if (pad & 0x8000) {
                    sel = (sel & 3) ? sel - 1 : sel + 3;
                } else if (pad & 0x2000) {
                    sel = ((sel & 3) == 3) ? sel - 3 : sel + 1;
                } else if (pad & 0x1000) {
                    sel = (sel >> 2) ? sel - 4 : sel + 4;
                } else if (pad & 0x4000) {
                    sel = (sel >> 2) ? sel - 4 : sel + 4;
                } else {
                    goto f0;
                }
            } else {
            f0:
                if (pad & 0xF0) {
                    s32 snd;
                    if (func_80066F50()) {
                        if (pad & 0x10) {
                            if (!((1 << ret) & g_GadgetState_pm.owned)) goto bad;
                            if (g_CurrentGadget == g_GadgetState_pm.slot[0]) Gadget_Select(ret, g_CurrentGadget);
                            func_80081144(ret, g_GadgetState_pm.slot[0]);
                            snd = 0x24;
                            g_GadgetState_pm.slot[0] = ret;
                        } else if (pad & 0x80) {
                            if (!((1 << ret) & g_GadgetState_pm.owned)) goto bad;
                            if (g_CurrentGadget == g_GadgetState_pm.slot[1]) Gadget_Select(ret, g_CurrentGadget);
                            func_80081144(ret, g_GadgetState_pm.slot[1]);
                            snd = 0x24;
                            g_GadgetState_pm.slot[1] = ret;
                        } else if (pad & 0x20) {
                            if (!((1 << ret) & g_GadgetState_pm.owned)) goto bad;
                            if (g_CurrentGadget == g_GadgetState_pm.slot[2]) Gadget_Select(ret, g_CurrentGadget);
                            func_80081144(ret, g_GadgetState_pm.slot[2]);
                            snd = 0x24;
                            g_GadgetState_pm.slot[2] = ret;
                        } else if (pad & 0x40) {
                            if (!((1 << ret) & g_GadgetState_pm.owned)) goto bad;
                            if (g_CurrentGadget == g_GadgetState_pm.slot[3]) Gadget_Select(ret, g_CurrentGadget);
                            func_80081144(ret, g_GadgetState_pm.slot[3]);
                            snd = 0x24;
                            g_GadgetState_pm.slot[3] = ret;
                        } else {
                            goto wrap;
                        }
                    } else {
                    bad:
                        snd = 0x30;
                    }
                    Sound_PlayFixed_pm(snd);
                }
            }
        wrap:
            if (sel >= 8) {
                sel %= 8;
            }
            G_pm.prim = prim;
            Hud_DrawGadgets();
            __asm__("addu %0,%1,$0" : "=r"(ret) : "r"(sel));
            func_80081D54();
            Menu_DrawWindow(8, 0x38, 0x100, 0x68);
            Menu_DrawWindow(8, 0xA2, 0x170, 0x40);
            prim = G_pm.prim;
            SetPriority_pm(prim, 0, 0);
            { register u32 *_q asm("$3") = &ot[0xFFE]; __asm__ volatile("lwl $4, 2(%0)\n\tsll $2, %1, 8\n\tswl $2, 2(%0)\n\tswl $4, 2(%1)" : : "r"(_q), "r"(prim) : "$2", "$4"); }
            prim += 0xC;
            if (PAD_pm & 0x800) {
                PS_pm.state = 2;
                PS_pm.t = 0x100;
                func_80081B9C(1);
                Sound_PlayFixed_pm(1);
                func_8005DD28();
            }
            if (PAD_pm & 0x100) {
                ret = 0;
                PS_pm.state = 3;
                PS_pm.t = 0;
                Sound_PlayFixed_pm(1);
                func_8005DD28();
            }
            break;
        }
        case 11:
            G_pm.prim = prim;
            if (G_pm.f_8122 == 0xD) {
                Menu_DrawStatusScreen();
            } else {
                PauseMenu_DrawStageInfo();
            }
            func_80081D54();
            if (PAD_pm & 0x8F0) {
                PS_pm.state = 2;
                PS_pm.t = 0x100;
                func_80081B9C(1);
                Sound_PlayFixed_pm(1);
            }
            prim = G_pm.prim;
            break;
        case 12:
            G_pm.prim = prim;
            if (OptionsMenu_Update() == -1) {
                PS_pm.state = 2;
                PS_pm.t = 0x100;
                func_80081B9C(1);
            }
            prim = G_pm.prim;
            break;
        }
        G_pm.prim = prim;
        if (Game_IsTimed()) {
            s32 v;
            Hud_DrawTimerClock(0x90, 0x20, G_pm.f_8140);
            Hud_DrawTime(0xA0, 0x20, G_pm.f_8140);
            v = func_8005DD34();
            if (v != 0) {
                func_8005FFD4(v);
            }
        }
        switch (PS_pm.state) {
        case 4:
        case 10:
        case 11:
        case 12:
            break;
        default:
            Hud_DrawMonkeyHeads(0x136, 0xC0);
            D_800F4DB0.f_1C = 0x14;
            Hud_DrawHealth();
            Hud_DrawLivesIcon(0x14, 0xC0);
            Hud_DrawBigDigit(0x34, 0xC8, -1);
            Hud_DrawBigNumber(0x4C, 0xC8, G_pm.f_813C - 1);
            if (!Game_IsTimed()) {
                D_800F4DB0.f_0 = 0x51;
                func_8005FD80();
            }
            D_800F4DB0.f_4 = -0x1C;
            Hud_UpdateStatusIcons();
            break;
        }
        prim = G_pm.prim;
        SetPriority_pm(prim, 0, 0);
        { register u32 *_q asm("$3") = &ot[0xFFF]; __asm__ volatile("lwl $4, 2(%0)\n\tsll $2, %1, 8\n\tswl $2, 2(%0)\n\tswl $4, 2(%1)" : : "r"(_q), "r"(prim) : "$2", "$4"); }
        Cd_Update();
        func_8007F9D0();
        DrawSync_pm(0);
        VSync_pm(2);
        PutDispEnv_pm((u8 *)&G_pm.db[G_pm.cur] + 0x5C);
        PutDrawEnv_pm(&G_pm.db[G_pm.cur]);
        func_8007F848();
        DrawOTag_pm(&G_pm.db[G_pm.cur].ot[0xFFF]);
        DrawOTag_pm(G_pm.db[G_pm.cur].hud);
        if ((u32)(bufs[G_pm.cur] + 0x9000) < (u32)G_pm.prim) {
            static const char s_pm[20] = "packet fllow!!\n";
            bios_printf_pm((char *)s_pm);
        }
        if (PS_pm.state == 0) {
            gte_SetGeomScreen_pm(h);
            PS_pm.state = 0;
            DrawSync_pm(0);
            break;
        }
    } while (1);
    VSync_pm(0);
    func_8008C064(bufs[0]);
    func_8008C064(bufs[1]);
    func_8005DD18();
    func_800729CC();
    return ret;
}



void func_80081144(s32 arg0, s8 arg1)
{
  M2C_UNK *var_v1;
  s32 var_a2;
  var_a2 = 0;
  var_v1 = &g_GadgetState;
  do
  {
    var_v1 = (void *) (((u8 *) (&g_GadgetState)) + var_a2);
    if ((*((s8 *) (((s8 *) var_v1) + 0x88))) == arg0)
    {
      *((s8 *) (((s8 *) var_v1) + 0x88)) = arg1;
    }
    var_a2 += 1;
  }
  while (var_a2 < 4);
}

typedef struct { u32 tag; u32 c0; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PolyF4_81180;
extern s16 g_AirTimer;

void Hud_DrawAirMeter(void) {
    union { SprtTp *s; PolyF4_81180 *q; u8 *b; } p;
    u32 *ot = G_HUD_OT;
    s32 n;
    u32 col;
    register s32 a asm("$17");
    s32 s;
    s32 c;
    s32 t; s32 u;
    s32 i;

    p.b = G_DRAW.prim;
    ((u8 *)p.s)[3] = 5;
    p.s->code = 0x67;
    p.s->x0 = 0x118;
    p.s->y0 = 0x1C;
    p.s->v0 = 0xC0;
    p.s->w = 0x40;
    p.s->h = 0x40;
    p.s->clut = 0x766B;
    p.s->tpage = 0xE100023A;
    p.s->u0 = 0;
    ADD_PRIM_ASM(ot, p.s);
    n = g_AirTimer;
    __asm__ volatile("");
    p.s++;
    col = 0xFF;
    if (n >= 150) {
        col = 0xFF3030;
        if (n < 300) {
            col = 0xFFFF;
        }
    }
    a = -0x800;
    s = rsin(a);
    c = rcos(a);
    for (i = 0; i < n; i += 15) {
        a += 0x40;
        ((u8 *)p.q)[3] = 5;
        p.q->c0 = col;
        ((u8 *)p.q)[7] = 0x28;
        p.q->y0 = 0x3C - ((s * 28) >> 12);
        p.q->y1 = 0x3C - ((s * 12) >> 12);
        p.q->x0 = ((c * 28) >> 12) + 0x138;
        p.q->x1 = ((c * 12) >> 12) + 0x138;
        u = rsin(a);
        p.q->y2 = 0x3C - ((u * 28) >> 12);
        p.q->y3 = 0x3C - ((u * 12) >> 12);
        t = rcos(a);
        p.q->x2 = ((t * 28) >> 12) + 0x138;
        p.q->x3 = ((t * 12) >> 12) + 0x138;
        ADD_PRIM_ASM(ot, p.q);
        p.q++;
        c = t; s = u;
    }
    D_800EC354 = (s32)p.b;
}

typedef struct { u8 pad0[0x98]; s16 x; s16 f_9A; s16 f_9C; u8 pad9E[2]; u8 sel; u8 n1; u8 n2; } SlingHud_813D8;
extern SlingHud_813D8 g_GadgetState_813D8 asm("g_GadgetState");
#define SH_813D8 g_GadgetState_813D8
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; u32 wh; } SprtTpU_813D8;
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u16 uv, clut; u32 wh; } SprtTpV_813D8;
extern u32 D_800B2728[3];
extern s16 D_800F51BC;
SprtTpU_813D8 *Hud_DrawSmallNumber_813D8(s32 x, s32 y, s32 n, SprtTpU_813D8 *p) asm("Hud_DrawSmallNumber");

void Hud_DrawSlingAmmo(void) {
    u32 *ot = G_HUD_OT;
    SprtTpU_813D8 *p = (SprtTpU_813D8 *)G_DRAW.prim;
    s32 x = SH_813D8.x;
    s32 y;
    s32 i;
    s32 n;

    for (i = 0, y = 0x5A; i < 3; i++, y += 12) {
        p->code = 0x65;
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE100021A;
        p->x0 = x + 0x15;
        p->y0 = y;
        p->uvclut = D_800B2728[i];
        p->wh = 0x100010;
        ADD_PRIM_ASM(ot, p);
        p++;
        switch (i) {
        case 1:
            n = SH_813D8.n1;
            break;
        case 2:
            n = SH_813D8.n2;
            break;
        default:
            n = -1;
            break;
        }
        p = Hud_DrawSmallNumber_813D8(x + 0x25, y + 3, n, p);
        if (i == SH_813D8.sel) {
            ((SprtTpV_813D8 *)p)->uv = 0xA040;
            ((u8 *)p)[3] = 5;
            p->tpage = 0xE100021A;
            p->code = 0x67;
            p->x0 = x + 0xE;
            p->y0 = y;
            p->wh = 0x100030;
            ((SprtTpV_813D8 *)p)->clut = 0x786B;
            ADD_PRIM_ASM(ot, p);
            p++;
            p->tpage = 0xE100025A;
            ((SprtTpV_813D8 *)p)->uv = 0xB040;
            ((u8 *)p)[3] = 5;
            p->code = 0x67;
            p->x0 = x + 0xE;
            p->y0 = y;
            p->wh = 0x100030;
            ((SprtTpV_813D8 *)p)->clut = 0x78AB;
            ADD_PRIM_ASM(ot, p);
            p++;
        }
    }
    if (SH_813D8.f_9C > 0) {
        SH_813D8.x = x - 10;
        if (x < 0x136) {
            SH_813D8.x = 0x12C;
        }
    } else {
        SH_813D8.x += 10;
        SH_813D8.x += x;
        if (x > 0x190) {
            SH_813D8.x = 0x190;
            SH_813D8.f_9C = 0;
        }
    }
    if (g_CurrentGadget != 3) {
        D_800F51BC = -1;
    }
    if (SH_813D8.f_9A > 0) {
        SH_813D8.f_9A--;
    }
    D_800EC354 = (s32)p;
}

extern struct { u8 pad0[0xF2]; s8 gadget; } g_Spike_81664 asm("g_Spike");
typedef struct { u8 pad0[0x88]; s8 slots[4]; u8 pad8C[8]; s16 cursorX; s16 cursorY; } GadgetHud_81664;
typedef struct { s16 x, y; } HudPos_81664;
extern HudPos_81664 D_800B2234_81664[] asm("D_800B2234");
typedef struct { u8 u, v; u16 clut; } GadgetIcon_81664;
extern GadgetIcon_81664 D_800B2254[];
typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } SprtTp_81664;
s32 Spike_IsUnderwater(void);
s32 func_80066F50(void);
extern GadgetHud_81664 g_GadgetState_81664 asm("g_GadgetState");
#define GH_81664 g_GadgetState_81664

void Hud_DrawGadgets(void) {
    s32 cur = g_Spike_81664.gadget;
    u32 *ot = G_HUD_OT;
    SprtTp_81664 *p;
    s32 i;
    s32 ty, tx;
    s32 h;
    s32 off;

    if (Spike_IsUnderwater() != 0) {
        Hud_DrawAirMeter();
        return;
    }
    if (func_80066F50() == 0 || g_Spike_81664.gadget == 9) {
        return;
    }
    if (g_Spike_81664.gadget == 3) {
        Hud_DrawSlingAmmo();
    }
    p = (SprtTp_81664 *)G_DRAW.prim;
    tx = 0;
    ty = 0;
    for (i = 0; i < 4; i++) {
        if (GH_81664.slots[i] != -1) {
            p->tpage = 0xE100021E;
            ((u8 *)p)[3] = 5;
            p->code = 0x65;
            p->clut = D_800B2254[GH_81664.slots[i]].clut;
            p->x0 = D_800B2234_81664[i].x - 16;
            off = -17;
            if (GH_81664.slots[i] == cur) {
                off = -14;
            }
            p->y0 = D_800B2234_81664[i].y + off;
            p->w = 0x20;
            p->h = 0x20;
            p->u0 = D_800B2254[GH_81664.slots[i]].u;
            p->v0 = D_800B2254[GH_81664.slots[i]].v;
            ADD_PRIM_ASM(ot, p);
            p++;
        }
        p->tpage = 0xE100021D;
        p->code = 0x67;
        ((u8 *)p)[3] = 5;
        p->clut = (0x7840 + i * 0x40) | 0x37;
        p->x0 = D_800B2234_81664[i].x - 16;
        p->y0 = D_800B2234_81664[i].y - 16;
        p->w = 0x20;
        p->h = 0x20;
        p->v0 = (i / 2) * 32 + 0x40;
        if (GH_81664.slots[i] == cur) {
            p->u0 = (i % 2) * 64 + 0x20;
        } else {
            p->u0 = (i % 2) * 64;
        }
        ADD_PRIM_ASM2(ot, p);
        p++;
        if (GH_81664.slots[i] == cur) {
            tx = D_800B2234_81664[i].x - 0x18;
            ty = D_800B2234_81664[i].y - 0x17;
        }
    }
    if (tx != 0 && ty != 0) {
        tx = (GH_81664.cursorX + tx) >> 1;
        ty = (GH_81664.cursorY + ty) >> 1;
        ((u8 *)p)[3] = 5;
        p->code = 0x67;
        p->tpage = 0xE100023D;
        p->x0 = tx;
        p->y0 = ty;
        GH_81664.cursorX = tx;
        GH_81664.cursorY = ty;
        *(u16 *)&p->u0 = 0x50C0;
        *(u32 *)&p->w = 0x300030;
        p->clut = 0x363F;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    D_800EC354 = (s32)p;
}

/* Places the HUD cursor on the slot that holds the current gadget.
 */
typedef struct { u8 pad0[0x88]; s8 slots[4]; u8 pad8C[8]; s16 cursorX; s16 cursorY; } GadgetHud_8008197C;
typedef struct { s16 x, y; } HudPos_8008197C;
extern HudPos_8008197C D_800B2234[]; /* screen position of each of the four gadget slots */

/* Put the gadget cursor on the HUD slot that holds the current gadget, or at
   (0x148, 0x48) if the gadget isn't assigned to a slot. */
void Gadget_UpdateHudCursor(void) {
    s32 cur = g_CurrentGadget;
    s32 i;
    s32 x = 0x148;
    s32 y = 0x48;
    for (i = 0; i < 4; i++) {
        if (((GadgetHud_8008197C *)&g_GadgetState)->slots[i] == cur) {
            x = D_800B2234[i].x - 0x18;
            y = D_800B2234[i].y - 0x17;
            break;
        }
    }
    ((GadgetHud_8008197C *)&g_GadgetState)->cursorX = x;
    ((GadgetHud_8008197C *)&g_GadgetState)->cursorY = y;
}

typedef struct { u32 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; u32 wh; } SprtTpW_819E8;

SprtTpW_819E8 *Hud_DrawSmallNumber(s32 x, s32 y, s32 n, SprtTpW_819E8 *p) {
    u32 *ot = G_HUD_OT;
    s32 d;

    if (n == -1) {
        ((u8 *)p)[3] = 5;
        p->code = 0x65;
        p->u0 = 0x10;
        p->v0 = 0x96;
        p->tpage = 0xE100021A;
        p->x0 = x;
        p->y0 = y;
        p->clut = 0x756B;
        p->wh = 0xB0010;
        ADD_PRIM_ASM(ot, p);
        return p + 1;
    }
    d = n / 10;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100021A;
    p->code = 0x65;
    p->x0 = x;
    p->y0 = y;
    p->u0 = (d % 4) * 8;
    p->v0 = (d / 4) * 11 - 0x80;
    p->clut = 0x756B;
    p->wh = 0xB0008;
    ADD_PRIM_ASM(ot, p);
    p++;
    n = n % 10;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100021A;
    p->code = 0x65;
    p->x0 = x + 8;
    p->y0 = y;
    p->u0 = (n % 4) * 8;
    p->v0 = (n / 4) * 11 - 0x80;
    p->clut = 0x756B;
    p->wh = 0xB0008;
    ADD_PRIM_ASM(ot, p);
    return p + 1;
}

void func_80081B9C(s32 mode) {
    switch (mode) {
    case 0:
        D_800B264C[0].x2 = 0x80;
        D_800B264C[0].y2 = -0x20;
        D_800B264C[1].x2 = -0x80;
        D_800B264C[1].y2 = 0x6E;
        D_800B264C[2].x2 = 0x200;
        D_800B264C[2].y2 = 0x6E;
        D_800B264C[3].x2 = 0x80;
        D_800B264C[3].y2 = 0x120;
        break;
    case 1:
        D_800B264C[0].x = 0x80;
        D_800B264C[0].y = 0x3C;
        D_800B264C[1].x = 0x28;
        D_800B264C[1].y = 0x6E;
        D_800B264C[2].x = 0xDC;
        D_800B264C[2].y = 0x6E;
        D_800B264C[3].x = 0x80;
        D_800B264C[3].y = 0xAA;
        break;
    case 2:
        D_800B264C[0].x = 0x78;
        D_800B264C[0].y = 0x1E;
        D_800B264C[1].x = -0x80;
        D_800B264C[1].y = 0x6E;
        D_800B264C[2].x = 0x200;
        D_800B264C[2].y = 0x6E;
        D_800B264C[3].x = 0x80;
        D_800B264C[3].y = 0x120;
        break;
    case 3:
        D_800B264C[0].x = 0x80;
        D_800B264C[0].y = -0x20;
        D_800B264C[1].x = -0x80;
        D_800B264C[1].y = 0x6E;
        D_800B264C[2].x = 0x78;
        D_800B264C[2].y = 0x1E;
        D_800B264C[3].x = 0x80;
        D_800B264C[3].y = 0x120;
        break;
    case 4:
        D_800B264C[0].x = 0x80;
        D_800B264C[0].y = -0x20;
        D_800B264C[1].x = 0x78;
        D_800B264C[1].y = 0x1E;
        D_800B264C[2].x = 0x200;
        D_800B264C[2].y = 0x6E;
        D_800B264C[3].x = 0x80;
        D_800B264C[3].y = 0x120;
        break;
    case 5:
        D_800B264C[0].x = 0x80;
        D_800B264C[0].y = -0x20;
        D_800B264C[1].x = -0x80;
        D_800B264C[1].y = 0x6E;
        D_800B264C[2].x = 0x200;
        D_800B264C[2].y = 0x6E;
        D_800B264C[3].x = 0x78;
        D_800B264C[3].y = 0x1E;
        break;
    }
}



typedef struct { u32 tag; u32 rgbc; u32 xy; u32 uvclut; u32 wh; } SprtW_81D54;
typedef struct { u32 tag; u32 code; } DrTpage_81D54;
s32 Game_IsTimed(void);

void func_80081D54(void) {
    u32 *ot = G_HUD_OT;
    SprtW_81D54 *p = (SprtW_81D54 *)G_DRAW.prim;
    s32 i;
    u32 c;

    if (Game_IsTimed() && D_800BEF74.f_0 != 2) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (func_80082030(i)) {
            ((u8 *)p)[3] = 4;
            p->rgbc = 0x64808080;
        } else {
            ((u8 *)p)[3] = 4;
            p->rgbc = 0x64202020;
        }
        D_800B264C[i].x2 = (D_800B264C[i].x2 * 2 + D_800B264C[i].x) / 3;
        D_800B264C[i].y2 = (D_800B264C[i].y2 * 2 + D_800B264C[i].y) / 3;
        p->xy = ((u32 *)D_800B264C)[i * 3 + 1];
        p->uvclut = ((u32 *)D_800B264C)[i * 3 + 2];
        p->wh = 0x100080;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    ((u8 *)p)[3] = 1;
    ((DrTpage_81D54 *)p)->code = 0xE100021A;
    ADD_PRIM_ASM(ot, p);
    p = (SprtW_81D54 *)((u8 *)p + 8);
    D_800EC354 = (s32)p;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt8_81F18;
typedef struct { u32 tag; u32 code; } DrTpage_81F18;

/* Menu window box (pause/status screens): as Hud_DrawWindow but grey-modulated (0x606060) and
   linked at the back of the current OT */
void Menu_DrawWindow(s32 x, s32 y, s32 w, s32 h) {
    s32 tx, ty;
    s32 u, v;
    u32 *ot = &G_DRAW.ot[0xFFF];
    Sprt8_81F18 *p = (Sprt8_81F18 *)G_DRAW.prim;

    for (ty = 0; ty < h; ty += 8) {
        for (tx = 0; tx < w; tx += 8) {
            *(u32 *)&p->r0 = 0x606060;
            ((u8 *)p)[3] = 3;
            p->code = 0x76;
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
    ((DrTpage_81F18 *)p)->code = 0xE100025A;
    ADD_PRIM_ASM(ot, p);
    p = (Sprt8_81F18 *)((u8 *)p + 8);
    G_DRAW.prim = (u8 *)p;
}

s32 func_80082030(s32 a) {
    switch (a) {
    case 2:
        return g_Game.f_8122 != 0xF;
    case 3:
        return 1;
    case 1:
        return g_Game.f_8122 != 0xD;
    case 0:
        switch (g_Game.f_8126) {
        case 0x13:
        case 0x24:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
        case 0x60:
        case 0x61:
        case 0x62:
            return 0;
        }
        return 1;
    }
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; } Sprt16_8211C;
typedef struct { u32 tag; u32 code; } DrTpage_8211C;

/* Menu highlight bar ends: two 16x16 rounded caps at x - w/2 and x + w/2 - 16, then a texpage */
void Menu_DrawCaps(s32 x, s32 y, s32 w) {
    Sprt16_8211C *p = (Sprt16_8211C *)G_DRAW.prim;
    u32 *ot = G_DRAW.ot;

    w >>= 1;
    ((u8 *)p)[3] = 3;
    p->code = 0x7D;
    p->x0 = x - w;
    p->y0 = y;
    p->uvclut = 0x7F2BC0E0;
    ADD_PRIM_ASM_DW(ot, p);
    p++;
    ((u8 *)p)[3] = 3;
    p->code = 0x7D;
    p->x0 = x + w - 16;
    p->y0 = y;
    p->uvclut = 0x7F2BC0F0;
    ADD_PRIM_ASM_DW(ot, p);
    p++;
    ((u8 *)p)[3] = 1;
    ((DrTpage_8211C *)p)->code = 0xE100021A;
    ADD_PRIM_ASM_DW(ot, p);
    p = (Sprt16_8211C *)((u8 *)p + 8);
    G_DRAW.prim = (u8 *)p;
}

/* While paused: stops the gadget loop sounds and runs the pause menu.
 */
s32 Pause_Update(void) {
    if (D_800BEF74.f_0 != 0) {
        if (D_800BEF74.f_0 == 1) {
            Gfx_WaitFlip();
            Gadget_StopSounds(g_CurrentGadget);
            return PauseMenu_Update();
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

/* Pixel width of a string: sum of D_800B2734[c] up to the NUL or a CR (0x0D). */
s32 Text_GetWidth(u8 *s) {
    s32 w = 0;
    while (*s != 0 && *s != 0xD) {
        w += D_800B2734[*s++];
    }
    return w;
}

void func_8008227C(s32 arg0) {
    D_800BEF80 = arg0;
}

void SetDrawTPage(void *p, s32 dfe, s32 dtd, s32 tpage);
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt16_82288;

/* Draws string s at (x, y) in the 16x16 font with palette col: one sprite per char >= 0x10
   (u, v from the char code), advancing by its width in D_800B2734 */
void Text_Draw(u8 *s, s32 x, s32 y, s32 col) {
    Sprt16_82288 *p = (Sprt16_82288 *)G_DRAW.prim;
    u32 *ot = G_HUD_OT;
    u32 c;

    c = *s;
    if (c != 0) {
        do {
            if (c >= 0x10) {
                p->u0 = (c & 0xF) << 4;
                ((u8 *)p)[3] = 3;
                p->code = 0x7D;
                p->x0 = x;
                p->y0 = y;
                p->v0 = c & 0xF0;
                p->clut = ((col + 0x100) << 6) | 0x1B;
                ADD_PRIM_ASM(ot, p);
                p++;
            }
            s++;
            x += D_800B2734[c];
            c = *s;
        } while (c != 0);
    }
    SetDrawTPage(p, 0, 1, 0x36);
    ADD_PRIM_ASM2(ot, p);
    p++;
    G_DRAW.prim = (u8 *)p;
}

typedef struct { u32 frame; u8 pad4[0x8120]; u16 stage; u8 pad8126[8]; u16 f_812E; u8 pad8130[0x14]; s32 time; s32 best; s32 f_814C; u8 pad8150[0x16]; s16 caught; u8 pad8168[0x1E]; s16 total; s16 present; s16 f_818A; u8 pad818C[0x140]; s8 f_82CC; s8 f_82CD; } GameP_82398;
#define GP (*(GameP_82398 *)&g_Game)
typedef struct { u32 tag; u32 rgbc; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_82398;
typedef struct { u32 tag; u32 code; } DrTpage_82398;
extern u8 D_800B26A8[];
extern u8 D_800B26B0[];
extern u8 D_800B26C4[];
extern u8 D_800B26F4[];
extern u8 D_800B2640[];
extern u8 D_800F4458[];
s32 func_800964B0(s32);
s32 func_80097FB0(s32);
void Menu_DrawSpinningModel(s32, s32);
void Hud_DrawTime(s32, s32, u32);
void Hud_DrawTimeMedal(s32, s32, u32, s16 *);
s16 *Stage_GetTargetTimes(u32);

/* Pause screen stage info: grid of monkey heads (caught lit, the rest dimmed or dark when not in
   this area), spinning model, caught / total counter, stage name, record and best times */
void PauseMenu_DrawStageInfo(void) {
    Sprt_82398 *p = (Sprt_82398 *)G_DRAW.prim;
    u32 *ot = G_DRAW.ot;
    s32 i;
    s32 v;
    s32 cl;
    s32 a, b;
    u8 *s;
    u8 *s2;
    s32 c;

    for (i = 0; i < GP.total; i++) {
        p->x0 = (i % 8) * 24 + 0x1E;
        p->y0 = (i / 8) * 24 + 0x66;
        p->w = 0x20;
        p->h = 0x20;
        if (i < GP.caught) {
            ((u8 *)p)[3] = 4;
            ((u8 *)p)[7] = 0x67;
            v = (GP.frame % 10 >= 6) ? 0x40 : 0x60;
            p->u0 = 0x80;
            cl = 0x3A3F;
        } else {
            if (i >= GP.present && (func_80096580(GP.stage) <= 0 || GP.f_812E == 2)) {
                p->rgbc = 0x101010;
                ((u8 *)p)[3] = 4;
                ((u8 *)p)[7] = 0x64;
            } else {
                ((u8 *)p)[3] = 4;
                ((u8 *)p)[7] = 0x67;
            }
            v = (GP.frame % 10 >= 6) ? 0x40 : 0x60;
            p->u0 = 0xA0;
            cl = 0x3A7F;
        }
        p->v0 = v;
        p->clut = cl;
        ADD_PRIM_ASM2(ot, p);
        p++;
    }
    ((u8 *)p)[3] = 1;
    ((DrTpage_82398 *)p)->code = 0xE100020F;
    ADD_PRIM_ASM(ot, p);
    p = (Sprt_82398 *)((DrTpage_82398 *)p + 1);
    G_DRAW.prim = (u8 *)p;
    Menu_DrawSpinningModel(0x114, 0xB4);
    s = (u8 *)0x1F800000;
    switch (GP.stage) {
    case 7:
        b = 5;
        a = (func_800964B0(0x13) & 0x10) ? b : 0;
        break;
    case 14:
        b = 5;
        a = (func_800964B0(0x24) & 0x10) ? b : 0;
        break;
    default:
        a = func_80097FB0(GP.stage);
        b = GP.f_818A;
        break;
    }
    c = a / 10;
    s[0] = c + 0x6A;
    c = a % 10;
    s[1] = (c < 6) ? c + 0x6A : c + 0x74;
    s[2] = 0x8D;
    c = b / 10;
    s[3] = c + 0x6A;
    c = b % 10;
    s[4] = (c < 6) ? c + 0x6A : c + 0x74;
    s[5] = 0;
    Text_Draw(s, 0xF1, 0xAC, 1);
    Menu_DrawWindow(0x1E, 0x1E, 0x130, 0xB0);
    Text_Draw(D_800B269C + 2, 0x4A, 0xB4, 2);
    Text_Draw(D_800B26A8, 0x36, 0x40, 2);
    Text_Draw(D_800B26B0, 0xE6, 0x40, 2);
    s2 = (u8 *)0x1F800000;
    s2[0] = D_800B2640[GP.f_82CC + 1];
    s2[1] = 0x8B;
    s2[2] = D_800B2640[GP.f_82CD + 1];
    s2[3] = 0;
    Text_Draw(s2, 0x7C, 0x40, 2);
    s2[0] = 10;
    s2[1] = 9;
    s2[2] = 0;
    func_8008DDB0(0x36, 0xB4);
    func_8008DDC8(s2);
    if (GP.best != -1) {
        Text_Draw(D_800B26C4, 0xD6, 0x72, 2);
        Hud_DrawTime(0xF6, 0x8C, GP.best);
        Hud_DrawTimeMedal(0xDE, 0x84, GP.best, Stage_GetTargetTimes(GP.stage));
    } else if (GP.f_814C != -1) {
        Text_Draw(D_800B26F4, 0xD6, 0x72, 2);
        Hud_DrawTime(0xF6, 0x8C, GP.f_814C);
    }
    Text_Draw(D_800F4458, 0x36, 0x52, 1);
    Hud_DrawTime(0xF6, 0x5A, GP.time);
    if (GP.stage != 7 && GP.stage != 14) {
        Hud_DrawTimeMedal(0xDE, 0x52, GP.time, Stage_GetTargetTimes(GP.stage));
    }
    __asm__ volatile("" : : : "$8");
}

/* Status screen icon: moves the GTE screen offset to (x, y), draws model D_800F4D00 at depth
 * 0x800 rotating with the frame counter, then restores the offset to the screen centre (0xC0, 0x78). */
void Menu_DrawSpinningModel(s32 x, s32 y) {
    struct S_D_800AF0A0 m;
    u8 *buf = g_ProjVerts;
    u8 *mdl = D_800F4D00;

    gte_SetGeomOffset(x, y);
    Matrix_SetIdentity(&m);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x800;
    ((SV_828F8_800828F8 *)g_ProjVerts)->vx = -rsin((*(struct Game_828F8 *)&g_Game).frame << 6) >> 4;
    ((SV_828F8_800828F8 *)buf)->vy = -rcos((*(struct Game_828F8 *)&g_Game).frame << 6) >> 4;
    ((SV_828F8_800828F8 *)buf)->vz = 0;
    RotMatrixZYX(buf, &m);
    CompMatrix(&D_800AF0A0, &m, &m);
    Model_ProjectVerts(mdl, &m, buf);
    Model_CalcEnvMapUVs64(mdl);
    *(u8 *)0x1F8003F4 = 2;
    Model_DrawEnvMapped((*(struct Game_828F8 *)&g_Game).ot, buf, mdl);
    gte_SetGeomOffset(0xC0, 0x78);
}

void Menu_DrawStatusScreen(void) {
    s32 n;
    s32 len;
    s32 t;
    s32 d;
    struct Game_82A04 *g;
    u8 *sp;
    u8 *sp2;
    u8 c;

    g = &(*(struct Game_82A04 *)&g_Game);
    Menu_DrawSpinningModel(0x114, 0x70);
    n = (s16)((s16)g->f_816A / 10);
    sp = SPAD;
    if (n == 0) {
        sp[0] = 0xF;
        len = 1;
    } else {
        sp[0] = DIGIT(n);
        len = 2;
    }
    n = (s16)((s16)(*(struct Game_82A04 *)&g_Game).f_816A % 10);
    sp[1] = DIGIT(n);
    if (func_80096580(0x18) > 0) {
        len += 3;
        sp[2] = 0x8D;
        sp[3] = 0x7A;
        sp[4] = 0x6A;
        sp[5] = 0;
    } else {
        sp[2] = 0;
    }
    Text_Draw(sp, 0x115 - len * 8, 0x84, 1);
    Menu_DrawWindow(0x1E, 0x1E, 0x130, 0xB0);
    Text_Draw(D_800B26D0, 0x50, 0x50, 2);
    t = Save_GetCurrentCompletion();
    sp = SPAD;
    d = t % 10;
    t = t / 10;
    sp[4] = DIGIT(d);
    sp[3] = 0xAC;
    d = t % 10;
    t = t / 10;
    sp[2] = DIGIT(d);
    d = t % 10;
    t = t / 10;
    sp[1] = DIGIT(d);
    d = t % 10;
    sp[0] = DIGIT(d);
    sp[5] = 0xBC;
    sp[6] = 0;
    if (sp[0] == 0x6A) {
        sp[0] = 0xF;
        if (sp[1] == 0x6A) {
            sp[1] = 0xF;
        }
    }
    Text_Draw(sp, 100, 100, 1);
    Text_Draw(D_800B269C + 2, 0x4A, 0xB4, 2);
    sp2 = SPAD;
    sp2[0] = 10;
    sp2[1] = 9;
    sp2[2] = 0;
    func_8008DDB0(0x36, 0xB4);
    func_8008DDC8(SPAD);
}

void func_80082D40(void) {
    D_800BEF90 = 0;
    func_800864B4((void *)((u8 *)&D_800BEF90 + 4));
}

typedef struct { s32 sel; s32 se; s32 bgm; } Opt_82D6C;
#define OPT_82D6C (*(Opt_82D6C *)&D_800BEF90)
typedef struct { u32 f_0; u8 pad4[0x8134]; u8 vibration; u8 pad8139; u16 stereo; } GameOpt_82D6C;
#define GO_82D6C (*(GameOpt_82D6C *)&g_Game)
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; s16 w, h; } Sprt_82D6C;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; } Sprt16_82D6C;
typedef struct { u32 tag; u32 code; } DrTpage_82D6C;
extern u32 D_800B2858;
extern u32 D_800B2840[5];
extern u8 D_800B2864[];
void Menu_DrawVolumeBar(s32, s32, s32);
void Menu_DrawCaps(s32, s32, s32);
u8 *Str_GetNth(u8 *, s32);
s32 Sound_SetVolumes(s32, s32);
s32 func_80086428(s32);
s32 Sound_SetStereo(s32);

/* Options menu: vibration, stereo/mono, music and effects volume (D-pad left/right, steps of 8)
   and reset to defaults; up/down picks the row, Start leaves (returns -1) */
s32 OptionsMenu_Update(void) {
    s32 sel = OPT_82D6C.sel;
    u32 *ot = G_DRAW.ot;
    union { Sprt_82D6C *p; Sprt16_82D6C *q; DrTpage_82D6C *t; u8 *b; } u;
    s32 k, i, y, y1;
    u32 btn;
    s32 v;

    Menu_DrawWindow(0x1E, 0x1E, 0x130, 0xB0);
    u.b = G_DRAW.prim;
    u.b[3] = 4;
    u.p->code = 0x65;
    k = (GO_82D6C.f_0 >> 2) % 3;
    if (sel < 5) {
        u.p->x0 = 0x1C;
        u.p->y0 = sel * 26 - (s16)(k - 0x1C);
    } else {
        u.p->x0 = 0xDC;
        u.p->y0 = 0x9E - k;
    }
    u.p->w = 0x20;
    u.p->h = 0x20;
    u.p->uvclut = D_800B2858;
    ADD_PRIM_ASM(ot, u.p);
    u.p++;
    for (i = 0; i < 5; i++) {
        u.b[3] = 3;
        u.q->code = 0x7D;
        u.q->x0 = 0x34;
        u.q->y0 = i * 26 + 0x34;
        u.q->uvclut = D_800B2840[i];
        ADD_PRIM_ASM(ot, u.q);
        u.q++;
    }
    G_DRAW.prim = u.b;
    Menu_DrawVolumeBar(0xA8, 0x68, OPT_82D6C.bgm);
    Menu_DrawVolumeBar(0xA8, 0x82, OPT_82D6C.se);
    u.b = G_DRAW.prim;
    u.b[3] = 1;
    u.t->code = 0xE100023A;
    ADD_PRIM_ASM(ot, u.t);
    u.t++;
    G_DRAW.prim = u.b;
    for (i = 0; i < 5; i++) {
        Text_Draw(Str_GetNth(D_800B2864, i), 0x54, i * 26 + 0x34, 2);
    }
    Text_Draw(Str_GetNth(D_800B2864, 5), 0xB4, 0x34, 1);
    Text_Draw(Str_GetNth(D_800B2864, 6), 0xF0, 0x34, 1);
    Menu_DrawCaps(GO_82D6C.vibration ? 0xC4 : 0x100, 0x34, 0x40);
    Text_Draw(Str_GetNth(D_800B2864, 7), 0xB4, 0x4E, 1);
    Text_Draw(Str_GetNth(D_800B2864, 8), 0x104, 0x4E, 1);
    Menu_DrawCaps(GO_82D6C.stereo ? 0xD4 : 0x124, 0x4E, 0x58);
    Text_Draw(Str_GetNth(D_800B2864, 9), 0x104, 0xB6, 0);
    func_8008DDB0(0xE4, 0xB6);
    func_8008DDC8(Str_GetNth(D_800B2864, 0xB));
    btn = g_Pad.f_158 & g_Pad.f_160;
    switch (sel) {
    case 0:
        if (btn & 0xA0F0) {
            GO_82D6C.vibration ^= 1;
            Sound_PlayFixed(3);
        }
        break;
    case 1:
        if (btn & 0xA0F0) {
            GO_82D6C.stereo ^= 1;
            Sound_SetStereo(GO_82D6C.stereo);
            Sound_PlayFixed(3);
        }
        break;
    case 2:
        v = OPT_82D6C.bgm;
        if (btn & 0x2000) {
            v += 8;
        }
        if (btn & 0x8000) {
            v -= 8;
        }
        if (btn & 0xA000) {
            Sound_PlayFixed(0x10);
        }
        v = (v < 0) ? 0 : (v >= 0x80) ? 0x7F : v;
        OPT_82D6C.bgm = v;
        Sound_SetVolumes(OPT_82D6C.se, v);
        break;
    case 3:
        v = OPT_82D6C.se;
        if (btn & 0x2000) {
            v += 8;
        }
        if (btn & 0x8000) {
            v -= 8;
        }
        if (btn & 0xA000) {
            Sound_PlayFixed(0x10);
        }
        v = (v < 0) ? 0 : (v >= 0x80) ? 0x7F : v;
        OPT_82D6C.se = v;
        Sound_SetVolumes(v, OPT_82D6C.bgm);
        break;
    case 4:
        if (btn & 0xF0) {
            func_80086428(1);
            func_800864B4(&OPT_82D6C.se);
            GO_82D6C.vibration = 1;
            GO_82D6C.stereo = 1;
            Sound_SetStereo(1);
            Sound_PlayFixed(3);
        }
        break;
    }
    if (btn & 0x1000) {
        sel--;
        Sound_PlayFixed(0);
    }
    if (btn & 0x4000) {
        Sound_PlayFixed(0);
        sel++;
    }
    sel = (sel + 5) % 5;
    if (btn & 0x800) {
        Sound_PlayFixed(1);
        return -1;
    }
    OPT_82D6C.sel = sel;
    func_80081D54();
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", jtbl_800A6140_pad);


u8 *Str_GetNth(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      var_v0 = var_v1 < arg1;
      if ((*var_a0) == 0)
      {
        var_v1 += 1;
      }
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; } Sprt16_8332C;
typedef struct { u32 tag; u32 c0; s16 x0, y0; u32 c1; s16 x1, y1; u32 c2; s16 x2, y2; u32 c3; s16 x3, y3; } PolyG4_8332C;
extern u32 D_800B285C[2];

/* Options menu volume slider: end caps from D_800B285C, then one 8 px POLY_G4 column per 8 of
   level n, each 1 px taller than the last and shading from yellow to red */
void Menu_DrawVolumeBar(s32 x, s32 y, s32 n) {
    union { Sprt16_8332C *s; PolyG4_8332C *g; u8 *b; } p;
    u32 *ot = G_DRAW.ot;
    s32 i;
    s32 top;
    u32 c0, c1;
    s32 bot;

    p.b = G_DRAW.prim;
    ((u8 *)p.s)[3] = 3;
    p.s->code = 0x7D;
    p.s->uvclut = D_800B285C[0];
    p.s->x0 = x - 8;
    p.s->y0 = y;
    ADD_PRIM_ASM(ot, p.s);
    p.s++;
    ((u8 *)p.s)[3] = 3;
    p.s->code = 0x7D;
    p.s->uvclut = D_800B285C[1];
    p.s->x0 = x + 0x86;
    p.s->y0 = y;
    ADD_PRIM_ASM(ot, p.s);
    p.s++;
    x += 6;
    for (i = 0; i < n; i += 8) {
        bot = y + 16;
        top = (i >> 3) - 15;
        top = y - top;
        c0 = 0xFFFF - i * 0x200;
        c1 = 0xFFFF - (i + 7) * 0x200;
        p.g->c1 = c1;
        p.g->c3 = c1;
        p.g->x0 = x;
        p.g->y0 = top;
        p.g->x2 = x;
        p.g->y2 = bot;
        p.g->c0 = c0;
        p.g->c2 = c0;
        p.g->x1 = x + 7;
        p.g->y1 = top;
        p.g->x3 = x + 7;
        p.g->y3 = bot;
        ((u8 *)p.g)[3] = 8;
        ((u8 *)p.g)[7] = 0x38;
        ADD_PRIM_ASM(ot, p.g);
        p.g++;
        x += 8;
    }
    G_DRAW.prim = p.b;
}
