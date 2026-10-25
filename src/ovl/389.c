#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_80146000);

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_8014607C);

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_80146230);

INCLUDE_ASM("asm/ovl/389/nonmatchings/389", func_80146500);

extern u8 g_Game[];
extern u8 *D_800EC354;
extern u8 D_801469D0[];
void SetDrawTPage(void *p, s32 dfe, s32 dtd, s32 tpage);
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; } Sprt16_8014666C;

void func_8014666C(u8 *s, s32 x, s32 y, s32 pal) {
    Sprt16_8014666C *p;
    u32 *ot;
    u8 c;

    p = (Sprt16_8014666C *)G_DRAW.prim;
    ot = G_DRAW.ot;
    while ((c = *s) != 0) {
        ((u8 *)p)[3] = 3;
        p->code = 0x7D;
        p->x0 = x;
        p->y0 = y;
        p->u0 = (c & 0xF) << 4;
        p->v0 = c & 0xF0;
        p->clut = ((pal + 0x100) << 6) | 0x1B;
        ADD_PRIM_ASM(ot, p);
        p++;
        s++;
        x += D_801469D0[c];
    }
    SetDrawTPage(p, 0, 1, 0x16);
    ADD_PRIM_ASM2(ot, p);
    p++;
    D_800EC354 = (u8 *)p;
}
