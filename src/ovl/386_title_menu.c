#include "common.h"
#include "m2c_macros.h"

INCLUDE_RODATA("asm/ovl/386/nonmatchings/386_title_menu", D_801376F0);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_80136000);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013654C);

INCLUDE_ASM("asm/ovl/386/nonmatchings/386_title_menu", func_8013674C);

typedef struct { u8 pad0[0x18]; u8 *f_18; u8 pad1C[0x40]; s16 f_5C; s16 f_5E; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0xA]; s16 f_70; s16 f_72; u8 *f_74; u8 pad78[0x10]; } Obj_80136AC0;
typedef struct { u8 pad0[0x10]; } Spr_80136AC0;
typedef struct { u8 pad0[0x1C]; s32 f_1C; } Mesh_80136AC0;
extern Obj_80136AC0 D_80137850[];
extern Spr_80136AC0 D_80137960[];
extern Mesh_80136AC0 D_801378A0[];
void func_8008C01C(void);
void func_80015AC0(void *, u8 *);
void func_80015B30(void *, u8 *);
void func_80015D10(void *, void *);
void Model_BindMesh(void *, u32 *);

void func_80136AC0(u8 *b) {
    u8 *buf = b;
    Obj_80136AC0 *o;
    s32 *t;
    u8 *m;
    s32 i;
    s32 j;

    func_8008C01C();
    for (i = 0; i < 4; i += 2) {
        o = &D_80137850[i >> 1];
        if (i == 0) {
            func_80015B30(o, buf + ((u16 *)buf)[2] * 4);
        } else {
            func_80015AC0(o, buf + ((u16 *)buf)[i * 2 + 2] * 4);
        }
        t = (s32 *)(((u16 *)buf)[i * 2 + 4] * 4 + (s32)buf);
        o->f_18 = (u8 *)(t + *t + 1);
        m = buf + ((u16 *)buf)[i * 2 + 4] * 4 + 4;
        o->f_5C = 0;
        o->f_5E = 0;
        o->f_70 = 0;
        o->f_72 = 0;
        o->f_60 = 0;
        o->f_62 = 0;
        o->f_64 = -0x1000;
        o->f_74 = m;
    }
    for (i = 4; i < 6; i++) {
        func_80015D10(&D_80137960[i], buf + ((u16 *)buf)[i * 2 + 2] * 4);
    }
    for (i = 6, j = 0; i < 7; i++, j += 0x20) {
        Model_BindMesh(&D_801378A0[i], (u32 *)(buf + ((u16 *)buf)[i * 2 + 2] * 4));
        ((Mesh_80136AC0 *)((u8 *)&D_801378A0[6] + j))->f_1C = 0;
    }
}

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

extern struct { u32 frame; SprtTp *prim; u32 *ot; } g_Game_80136D00 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136D00 asm("g_Pad");
extern s32 D_8013784C;
extern s16 D_80137818;
extern s16 D_8013781C;
s32 Sound_PlayFixed(s32);

s32 func_80136D00(void) {
    SprtTp *p;
    u32 *ot;
    u32 btn;
    u32 bob;

    p = g_Game_80136D00.prim;
    bob = g_Game_80136D00.frame / 4 % 3;
    ot = g_Game_80136D00.ot;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100023A;
    p->code = 0x65;
    p->y0 = D_8013784C * 24 + (bob + 0x80);
    p->x0 = 0x7C;
    *(u32 *)&p->u0 = 0x7DEBA0A0;
    p->w = 0x20;
    p->h = 0x20;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    p->tpage = 0xE100022B;
    p->x0 = 0x90;
    p->w = 0x60;
    *(u16 *)&p->u0 = 0x20A0;
    p->h = 0x20;
    p->y0 = 0x98;
    p->clut = D_8013784C == 0 ? 0x3E2F : 0x3E6F;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    *(u16 *)&p->u0 = 0xA0;
    p->tpage = 0xE100022B;
    p->x0 = 0x90;
    p->y0 = 0xA8;
    p->w = 0x60;
    p->h = 0x20;
    p->clut = D_8013784C == 0 ? 0x3E6F : 0x3E2F;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    g_Game_80136D00.prim = p;
    if (D_80137818 == 1) {
        btn = g_Pad_80136D00.f_160 & g_Pad_80136D00.f_158;
        if (btn & 0x860) {
            Sound_PlayFixed(2);
            if (D_8013784C == 0) {
                D_80137810 = 2;
            } else {
                if (D_8013784C != 1) {
                    return 0;
                }
                D_80137810 = 1;
            }
        } else if (btn & 0x1000) {
            Sound_PlayFixed(0);
            if (--D_8013784C < 0) {
                D_8013784C = 1;
            }
            D_8013781C = 0;
        } else {
            if (!(btn & 0x4000)) {
                return 0;
            }
            Sound_PlayFixed(0);
            if (++D_8013784C >= 2) {
                D_8013784C = 0;
            }
            D_8013781C = 0;
        }
    }
    return 0;
}

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
