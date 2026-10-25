#include "common.h"
#include "m2c_macros.h"

INCLUDE_RODATA("asm/ovl/386/nonmatchings/386_title_menu", D_801376F0);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136000);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013654C);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013674C);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136AC0);

extern s32 D_80137810;
s32 func_80136D00(void);
void func_80136F54(void);

s32 func_80136C5C(void) {
    switch (D_80137810) {
    case 0:
        if (func_80136D00() >= 0) {
            break;
        }
        return -1;
    case 1:
        return -3;
    case 2:
        return -6;
    case 3:
        break;
    case 4:
        func_80136F54();
        return 0;
    case 5:
        return -4;
    case 6:
        return -5;
    case 7:
        break;
    case 8:
        return -8;
    case 9:
        return -10;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136D00);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136F54);

extern s16 D_80137818;
extern s16 D_8013781A;

s32 func_801374E4(void) {
    switch (D_80137818) {
    case 1:
        return 0;
    case 0:
        func_801375C4();
        if (--D_8013781A < 0) {
            D_80137818 = 1;
            D_8013781A = 0;
        }
        return 0;
    case 2:
    case 3:
        func_801375C4();
        if (++D_8013781A >= 0x1F) {
            D_80137818 = 1;
            D_8013781A = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

extern u8 g_Game[];
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; s16 w, h; } Tile_801375C4;

s32 func_801375C4(void) {
    u8 *p;
    u32 *ot;
    s32 c;

    p = G_DRAW.prim;
    c = (D_8013781A * 255) / 30;
    p[3] = 3;
    ((Tile_801375C4 *)p)->code = 0x62;
    ((Tile_801375C4 *)p)->w = 0x180;
    ((Tile_801375C4 *)p)->x0 = 0;
    ((Tile_801375C4 *)p)->y0 = 0;
    ((Tile_801375C4 *)p)->h = 0xF0;
    ((Tile_801375C4 *)p)->b0 = c;
    ((Tile_801375C4 *)p)->g0 = c;
    ((Tile_801375C4 *)p)->r0 = c;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x10;
    if (D_80137818 == 0 || D_80137818 == 3) {
        p[3] = 1;
        ((u32 *)p)[1] = 0xE1000220;
    } else {
        p[3] = 1;
        ((u32 *)p)[1] = 0xE1000240;
    }
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}
