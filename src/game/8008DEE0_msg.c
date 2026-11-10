#include "common.h"
#include "m2c_macros.h"

void Msg_Update(void);
void Msg_DrawWindow(void);
extern struct S_D_800F5A00 { u8 f_0; u8 pad_1[0x1]; u16 f_2; u32 f_4; u32 f_8; u8 pad_C[0x4]; s16 f_10; s16 f_12; s16 f_14; s8 f_16; } g_MsgBox;

M2C_UNK Msg_PutChar(u16, u16, M2C_UNK);
u32 Msg_ReadChar(u32, u16 *);
M2C_UNK Msg_SetPos(M2C_UNK, M2C_UNK);


void Msg_Reset(void) {
    g_MsgBox.f_0 = 0;
}

void Msg_Open(void) {
    g_MsgBox.f_16 = 0;
    g_MsgBox.f_0 = 1;
    g_MsgBox.f_2 = 0x1F0;
    g_MsgBox.f_10 = 0x80;
    g_MsgBox.f_12 = 1;
    g_MsgBox.f_14 = 0;
}

void Msg_SetText(s32 arg0) {
    g_MsgBox.f_16 = 1;
    g_MsgBox.f_4 = arg0;
    g_MsgBox.f_8 = arg0;
}

u8 Msg_IsOpen(void) {
    return g_MsgBox.f_0;
}

void Msg_Frame(void) {
    if (g_MsgBox.f_0 != 0) {
        Msg_Update();
        Msg_DrawWindow();
    }
}

void Msg_DrawPage(void)
{
  unsigned int sp10;
  s32 var_v0;
  long temp_s1;
  u32 temp_s2;
  u32 var_s0;
  Msg_SetPos(0x20, 0x28);
  var_s0 = g_MsgBox.f_8;
  temp_s2 = g_MsgBox.f_4;
  temp_s1 = g_MsgBox.f_2;
  ;
  loop_1:
  if ((var_s0 < temp_s2) != 0)
  {
    var_s0 = Msg_ReadChar(var_s0, &sp10);
    Msg_PutChar(sp10, temp_s1, 1);
    var_v0 = var_s0 < temp_s2;
    goto loop_1;
  }

}

typedef struct { u8 state; u8 blink; u16 pal; u8 *p; u8 *page; u8 padC[4]; u16 t; u16 wait; u16 last; s8 f_16; } MsgSt_8DFFC;
#define MS (*(MsgSt_8DFFC *)&g_MsgBox)
extern struct S_D_800E5320_8DFFC { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad;
void Sound_PlayFixed(s32);

void Msg_Update(void) {
    s32 ok;
    u8 st;
    register u8 *q asm("$5");
    u8 *r;
    u16 last;
    MsgSt_8DFFC *m;
    u16 c;

    if (MS.state == 1 || MS.state == 5) {
        return;
    }
    Msg_DrawPage();
    st = MS.state;
    ok = (g_Pad.f_158 & g_Pad.f_160 & 0xEA) != 0;
    if (st == 4) {
        Msg_SetPos(0xB8, 0xA0);
        Msg_PutChar(0x104, 0x1F0, 1);
        if (MS.state == st && ok) {
            goto close;
        }
    }
    if (g_Pad.f_158 & g_Pad.f_160 & 0x800) {
close:
        MS.state = 5;
        MS.t = 0x80;
        Sound_PlayFixed(0);
        return;
    }
    m = &MS;
    if (MS.state == 3) {
        if (!(++m->blink & 8)) {
            Msg_SetPos(0xB8, 0xA0);
            Msg_PutChar(0x104, 0x1F0, 1);
        }
        if (ok) {
            { u8 *np = m->p + 1; MS.state = 2; m->p = np; m->page = np; }
            Sound_PlayFixed(0);
        }
        return;
    }
    goto scan;
end4:
    MS.state = 4;
    __asm__ volatile("");
    { register u8 *t asm("$2") = q - 1; m->p = t; }
    return;
end3:
    MS.state = 3;
    __asm__ volatile("");
    { register u8 *t asm("$2") = q - 1; m->p = t; }
    m->blink = 0;
    return;
scan:
    do {
        u16 *pc;
        pc = &c;
        r = (u8 *)Msg_ReadChar((u32)m->p, pc);
        pc = (u16 *)r;
        m->p = r;
        if (c == 0) break;
    } while (c != 0xF);
    m->p = r - 1;
    __asm__ volatile("");
    m = &MS;
    if (--m->wait != 0) {
        return;
    }
    m->wait = 1;
    __asm__ volatile("");
    {
    q = (u8 *)Msg_ReadChar((u32)m->p, &c);
    last = m->last;
    m->p = q;
    m->last = c;
    if ((u8)c < 0x10) {
        if (c == 0) {
            goto end4;
        } else if (c == 0xF) {
            goto end3;
        } else if (c == 0xD && last == 0xD) {
            m->wait = 0xD;
        }
    }
    }
}

extern u8 g_Game[];
typedef struct { u8 state; u8 pad1[0xF]; u16 t; u8 pad12[4]; u8 f_16; } MsgWin_8E23C;
#define MW_8E23C (*(MsgWin_8E23C *)&g_MsgBox)
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_8E23C;
typedef struct { P_TAG_8E23C tag; u32 tpage; u32 rgbc; u32 xy; u32 uvclut; u32 wh; } SprtTp_8E23C;
typedef struct { P_TAG_8E23C tag; u32 tpage; u32 c0; u32 xy0; u32 c1; u32 xy1; } LineG2Tp_8E23C;
typedef struct { P_TAG_8E23C tag; u32 tpage; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4Tp_8E23C;
#define LINK_8E23C(p) \
    (p)->tag.addr = ((P_TAG_8E23C *)ot)->addr; \
    ((P_TAG_8E23C *)ot)->addr = (u32)(p);

/* Message window: state g_MsgBox slides it in (1) and out (5) from the left as its timer +0x10
   halves each frame; draws the animated top and bottom border tiles, seven gradient line stripes
   and the gradient background */
void Msg_DrawWindow(void) {
    u32 *ot;
    union { SprtTp_8E23C *s; LineG2Tp_8E23C *l; PolyG4Tp_8E23C *g; u8 *b; } p;
    s32 x = 16;
    s32 y, i, k, u;
    u32 frame;

    MW_8E23C.t >>= 1;
    if (MW_8E23C.state == 1) {
        if (MW_8E23C.t < 2 && MW_8E23C.f_16 != 0) {
            MW_8E23C.state = 2;
        }
        x -= MW_8E23C.t * 2;
    }
    if (MW_8E23C.state == 5) {
        if (MW_8E23C.t < 2) {
            MW_8E23C.state = 0;
        }
        x -= 0x80 / (MW_8E23C.t + 1);
    }
    frame = *(u32 *)g_Game;
    p.b = G_DRAW.prim;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    y = 0x18;
    u = 0x1B - (frame % 28);
    for (i = 1; i >= 0; i--, y += 0x9C) {
        if (i == 0) {
            u = 0x1B - u;
        }
        for (k = 0; k < 0xC4; k += 0x1C) {
            p.s->tag.len = 5;
            p.s->tpage = 0xE1000217;
            p.s->rgbc = 0x65000000;
            p.s->xy = (y << 16) | ((x + k) & 0xFFFF);
            p.s->wh = 0x6001C;
            p.s->uvclut = (u + 0xC0) | 0x7EDDB000;
            LINK_8E23C(p.s);
            p.s++;
        }
    }
    for (y = 0x38, i = 7; i > 0; y += 0x12, i--) {
        p.l->tag.len = 5;
        p.l->tpage = 0xE1000217;
        p.l->c0 = 0x53AAB48C;
        p.l->xy0 = (y << 16) | ((x + 9) & 0xFFFF);
        p.l->c1 = 0x503C28;
        p.l->xy1 = (y << 16) | ((x + 0xBB) & 0xFFFF);
        LINK_8E23C(p.l);
        p.l++;
    }
    p.g->tag.len = 9;
    p.g->tpage = 0xE1000217;
    p.g->c0 = 0x3AB4AA40;
    p.g->xy0 = (x & 0xFFFF) | 0x180000;
    p.g->c1 = 0x54640C;
    p.g->xy1 = ((x + 0xC4) & 0xFFFF) | 0x180000;
    p.g->c2 = 0x543208;
    p.g->xy2 = (x & 0xFFFF) | 0xBA0000;
    p.g->c3 = 0x420C00;
    p.g->xy3 = ((x + 0xC4) & 0xFFFF) | 0xBA0000;
    LINK_8E23C(p.g);
    p.g++;
    G_DRAW.prim = p.b;
}
