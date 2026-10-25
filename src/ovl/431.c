#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/431/nonmatchings/431", func_80136000);

INCLUDE_ASM("asm/ovl/431/nonmatchings/431", func_801362B8);

INCLUDE_ASM("asm/ovl/431/nonmatchings/431", func_8013668C);

INCLUDE_ASM("asm/ovl/431/nonmatchings/431", func_8013690C);

extern s16 D_80136CF2;
extern s16 D_80136CF4;

s32 func_80136A24(void) {
    switch (D_80136CF2) {
    case 1:
        return 0;
    case 0:
        func_80136AFC();
        if (--D_80136CF4 < 0) {
            D_80136CF2 = 1;
            D_80136CF4 = 0;
        }
        return 0;
    case 2:
        func_80136AFC();
        if (++D_80136CF4 >= 0x1F) {
            D_80136CF2 = 1;
            D_80136CF4 = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

extern GameDraw g_Game;

s32 func_80136AFC(void) {
    u8 *p = G_DRAW.prim;
    s32 v = D_80136CF4 * 255 / 30;

    p[3] = 3;
    p[7] = 0x62;
    M2C_FIELD(p, s16 *, 0xC) = 0x180;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0xE) = 0xF0;
    p[4] = p[5] = p[6] = v;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 0x10;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000240;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

extern u8 *D_800EC354_80136BF4 asm("D_800EC354");
extern u8 D_80136E98[];
void SetDrawTPage(void *, s32, s32, s32);

void func_80136BF4(u8 *str, s32 x, s32 y, s32 clut) {
    u8 *p = G_DRAW.prim;
    u32 *ot = G_DRAW.ot;
    u32 c;

    while ((c = *str) != 0) {
        p[3] = 3;
        p[7] = 0x7D;
        M2C_FIELD(p, s16 *, 0x8) = x;
        M2C_FIELD(p, s16 *, 0xA) = y;
        p[0xC] = (c & 0xF) << 4;
        p[0xD] = c & 0xF0;
        M2C_FIELD(p, u16 *, 0xE) = ((clut + 0x100) << 6) | 0x1B;
        ADD_PRIM_ASM(ot, p);
        p += 0x10;
        str++;
        x += D_80136E98[c];
    }
    SetDrawTPage(p, 0, 1, 0x16);
    ADD_PRIM_ASM2(ot, p);
    p += 8;
    D_800EC354_80136BF4 = p;
}
