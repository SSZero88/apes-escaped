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
void func_80016D60(void *);
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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", func_8007D2D8);

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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", func_8007F8F4);

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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", Hud_DrawAirMeter);

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", Hud_DrawSlingAmmo);

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", Hud_DrawGadgets);

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



INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", func_80081D54);

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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", PauseMenu_DrawStageInfo);

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
    func_80016D60(mdl);
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

INCLUDE_ASM("asm/nonmatchings/game/8007D0F0_menu", OptionsMenu_Update);

INCLUDE_RODATA("asm/nonmatchings/game/8007D0F0_menu", jtbl_800A6140);
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
