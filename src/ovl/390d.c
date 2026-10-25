#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013F630);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013F808);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013F9F8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FB14);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FB30);

extern u8 D_80141554[];

u8 *func_8013FC20(void) {
    return D_80141554;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FC2C);

extern u8 D_80141800[];

u8 *func_8013FD44(void) {
    return D_80141800;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FD50);

typedef struct { s16 x, y; u8 body[0x20]; } Item_8013FDE4;
extern u8 D_80141824[];
#define D_80141820 ((Item_8013FDE4 *)(D_80141824 - 4))

s32 func_8013FDE4(s32 sel, s16 *flags) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (flags[i] == 1) {
            if (sel == i) {
                func_80136000(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 1);
            } else {
                func_80136000(D_80141820[i].body, D_80141820[i].x, D_80141820[i].y, 0);
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FEA0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FEFC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8013FFEC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_80140074);

typedef struct { s16 x, y; u8 text[0x20]; } Line_390b;
extern Line_390b D_801416B8[2];
void func_80136000(u8 *, s32, s32, s32);

s32 func_801400F4(s32 n) {
    s32 off;

    D_801416B8[0].text[4] = n + 0x6B;
    off = n * 48;
    func_80136000(D_801416B8[0].text, D_801416B8[0].x, D_801416B8[0].y + off, 1);
    func_80136000(D_801416B8[1].text, D_801416B8[1].x, D_801416B8[1].y + off, 0);
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", func_8014016C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d", jtbl_801403B0);

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390d", D_80144FE0);
