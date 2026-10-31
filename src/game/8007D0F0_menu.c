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
extern u8 D_800E7D00[];
extern u8 D_800F4D00[];
extern struct S_D_800AF0A0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800AF0A0;
void func_8004637C(struct S_D_800AF0A0 *);
s32 rsin(s32 a);
s32 rcos(s32 a);
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Model_ProjectVerts(void *, struct S_D_800AF0A0 *, u8 *);
void Model_CalcEnvMapUVs64(void *);
void func_8001CE54(u32 *, u8 *, void *);
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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", func_8007D530);

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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", PauseMenu_Update);

INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", D_800A60E4);
INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", jtbl_800A60F8);


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
    u8 *buf = D_800E7D00;
    u8 *mdl = D_800F4D00;

    gte_SetGeomOffset(x, y);
    func_8004637C(&m);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x800;
    ((SV_828F8_800828F8 *)D_800E7D00)->vx = -rsin((*(struct Game_828F8 *)&g_Game).frame << 6) >> 4;
    ((SV_828F8_800828F8 *)buf)->vy = -rcos((*(struct Game_828F8 *)&g_Game).frame << 6) >> 4;
    ((SV_828F8_800828F8 *)buf)->vz = 0;
    RotMatrixZYX(buf, &m);
    CompMatrix(&D_800AF0A0, &m, &m);
    Model_ProjectVerts(mdl, &m, buf);
    Model_CalcEnvMapUVs64(mdl);
    *(u8 *)0x1F8003F4 = 2;
    func_8001CE54((*(struct Game_828F8 *)&g_Game).ot, buf, mdl);
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
