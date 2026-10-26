#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8013973C(s32, s32, M2C_UNK);
M2C_UNK func_8013B9B0(void *, M2C_UNK *, s32, M2C_UNK *);
extern M2C_UNK D_800E7D00;
extern struct S_D_8013C550 { u8 pad_0[0x4]; s32 f_4; } D_8013C550;
extern struct S_D_8013C558 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } D_8013C558;
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; } g_Game;
M2C_UNK func_8013980C(s32, s32);

M2C_UNK StSetRing(s32, s32);
M2C_UNK StSetStream(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
s32 func_8008C09C(s32);
extern s32 D_8013C1A8;
s32 CdControl(s32, void *, void *);
s32 CdRead2(M2C_UNK);
M2C_UNK CdSync(M2C_UNK, M2C_UNK);
extern s32 D_8013C544;
extern s32 D_8013C548;
M2C_UNK func_8008C064(s32);
extern s32 D_8013C560;
extern s32 D_8013C564;
extern s32 D_8013C574;
M2C_UNK Model_BindMesh();
M2C_UNK func_80015AC0();
extern s32 D_8013C760;
M2C_UNK CdGetSector(s32, s32);
M2C_UNK CdReadyCallback(s32);
extern s32 D_8013C770;
extern s32 D_8013C774;
extern s32 D_8013C778;
extern s32 D_8013C77C;
extern M2C_UNK D_8013C7B0;

void func_80136000(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    if (var_s0 == 0) {
        var_s0 = 0x28;
    }
    if (D_8013C1A8 == 0) {
        D_8013C1A8 = func_8008C09C(var_s0 << 0xB);
    }
    StSetRing(D_8013C1A8, var_s0);
    StSetStream(0, 0, -1, 0, 0);
}

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BEF0);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF00);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF10);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF24);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF38);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF4C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF60);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF74);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF88);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BF9C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BFB0);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BFC4);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BFD8);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013BFEC);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C000);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C014);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C028);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C03C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C050);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", jtbl_8013C058);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C07C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C090);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C150);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C1A8);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C1AC);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C1B8);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C244);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C250);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C254);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136074);

void func_80136454(s32 arg0, M2C_UNK arg1) {
    do {
loop_1:
        if (CdControl(2, arg0, 0) == 0) {
            goto loop_1;
        }
        CdSync(0, 0);
    } while (CdRead2(arg1) == 0);
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801364B0);

typedef struct { u8 r, g, b, cd; } Col_384b;
extern s32 D_8013C488;
extern s32 D_8013C48C;
extern s32 D_8013C490;
extern s32 D_8013C494;
extern Col_384b D_8013C498;
extern Col_384b D_8013C49C;
extern struct { u8 pad0[0x1C]; Col_384b f_1C; Col_384b f_20; s32 f_24; s32 f_28; } D_800EBFA0_80136604 asm("D_800EBFA0");
s32 VSyncCallback(void *);
s32 func_800315D0(void);

void func_80136604(void)
{
  struct 
  {
    u8 pad0[0x1C];
    Col_384b f_1C;
    Col_384b f_20;
    s32 f_24;
    s32 f_28;
  } *new_var;
  D_8013C488 = VSyncCallback(0);
  D_8013C48C = func_800315D0();
  new_var = &D_800EBFA0_80136604;
  D_8013C498 = (*new_var).f_20;
  D_8013C49C = (*new_var).f_1C;
  D_8013C490 = (*new_var).f_24;
  D_8013C494 = D_800EBFA0_80136604.f_28;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[0xE]; u32 f_10; u8 pad14[8]; } Fmv_8013668C;
extern Fmv_8013668C *D_8013C484_8013668C asm("D_8013C484");
extern Fmv_8013668C D_8013C090[];
extern s32 D_8013C4B0;
extern s32 D_8013C4B4;
void func_8008C01C(void);
void func_800A3750(s32);
void func_8013990C(void *);
void func_80137D20(void);
void func_80136000(s32 arg0, s32 arg1);
void func_80086248(s32);
s32 CdControlB(s32, void *, void *);
void func_80136EA8(void);
void func_80136BD4(void);

s32 func_8013668C(s32 *mode, s32 idx) {
    func_8013BA80(0);
    func_80136604();
    func_8008C01C();
    func_800A3750(1);
    D_8013C484_8013668C = &D_8013C090[idx];
    if (func_80136884(idx) != 0) {
        return 1;
    }
    D_8013C4B0 = D_8013C4B4 = D_8013C484_8013668C->f_0;
    func_8013990C((void *)0x80148000);
    func_80137D20();
    func_80136000(0, D_8013C484_8013668C->f_1);
    *mode = 0x120;
    if (D_8013C484_8013668C->f_10 & 1) {
        *mode = 0x1A0;
    }
    if ((D_8013C484_8013668C->f_10 >> 1) & 1) {
        *mode |= 0x48;
        func_80136E68(1);
    }
    func_80086248(-1);
    while (CdControlB(0xC, 0, 0) == 0) {
    }
    func_80136EA8();
    func_80136BD4();
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_801367DC;
typedef struct { u8 pad0[0x6E]; u16 y; u8 pad70[0x4078 - 0x70]; } Db_801367DC;
extern struct { u8 pad0[0xC]; s32 f_C; } g_Game_801367DC asm("g_Game");
void MoveImage(Rect_801367DC *, s32, s32);

void func_801367DC(void) {
    Rect_801367DC r;
    Rect_801367DC c;

    c.x = 0;
    c.y = ((Db_801367DC *)&g_Game_801367DC)[g_Game_801367DC.f_C].y;
    c.w = 0x180;
    c.h = 0xF0;
    r = c;
    MoveImage(&r, 0, (s16)((Db_801367DC *)&g_Game_801367DC)[g_Game_801367DC.f_C ^ 1].y);
}

typedef struct { u8 b[4]; } Loc_80136884;
typedef struct { Loc_80136884 pos; u32 size; char name[16]; } File_80136884;
typedef struct { s32 a, b, c; } Tri_80136884;
typedef struct { u8 pad0[4]; char *f_4; char *f_8; Tri_80136884 f_C; Loc_80136884 f_18; } Fmv_80136884;
typedef struct { s32 f_0; s32 f_4; u8 pad8[8]; s32 f_10; s32 f_14; Tri_80136884 f_18; } Hdr_80136884;
extern Fmv_80136884 *D_8013C484_80136884 asm("D_8013C484");
void *CdSearchFile(void *fp, char *name);
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 func_8013AE80(void);
void func_80068D10(s32);

s32 func_80136884(void) {
    File_80136884 fp;
    Hdr_80136884 *h;
    s32 base;
    s32 tex;

    tex = 0x80148024;
    h = (Hdr_80136884 *)0x80148000;
    while (CdSearchFile(&fp, D_8013C484_80136884->f_4) == 0) {
    }
    fp.size = 0x800;
    func_8013ADA0((s32)h, &fp);
    while (func_8013AE80() != 0) {
    }
    D_8013C484_80136884->f_C = h->f_18;
    base = CdPosToInt(&fp);
    if (h->f_4 != 0) {
        CdIntToPos(base + h->f_0, &fp);
        fp.size = h->f_4;
        func_8013ADA0(tex, &fp);
        while (func_8013AE80() != 0) {
        }
        func_80068D10(tex);
    }
    CdIntToPos(base + h->f_10, &fp);
    fp.size = h->f_14;
    func_8013ADA0(0x80148000, &fp);
    while (func_8013AE80() != 0) {
    }
    while (CdSearchFile(&fp, D_8013C484_80136884->f_8) == 0) {
    }
    D_8013C484_80136884->f_18 = fp.pos;
    return 0;
}

typedef struct { u8 r, g, b, cd; } Col_801369E0;
extern struct { u8 pad0[0x10]; DrawBuf db[2]; u8 pad8100[0x5A]; u16 f_815A; } g_Game_801369E0 asm("g_Game");
extern struct { u8 pad0[0x1C]; Col_801369E0 f_1C; Col_801369E0 f_20; s32 f_24; s32 f_28; } D_800EBFA0_801369E0 asm("D_800EBFA0");
extern Col_801369E0 D_8013C498_801369E0 asm("D_8013C498");
extern Col_801369E0 D_8013C49C_801369E0 asm("D_8013C49C");
extern u8 D_8013C150[];
void StUnSetRing(void);
void func_801364B0(u8 *pos, u8 *end, u8 mode, s32 seek);
void func_80136FF0();
void func_80139DAC(void);
s32 func_8002FAF0(s32);
void func_8013AA70(void);
void func_8013BA80(s32 load);
void DrawSync(s32);

void func_801369E0(s32 arg0) {
    u8 loc0[4];
    u8 loc1[4];
    s32 base;

    StUnSetRing();
    if (g_Game_801369E0.f_815A == 6 && arg0 == 0) {
        base = CdPosToInt(D_8013C150);
        loc0[0] = 0;
        loc0[1] = 0x25;
        loc0[2] = 0x33;
        CdIntToPos(base + CdPosToInt(loc0), loc0);
        loc1[0] = 2;
        loc1[1] = 0x42;
        loc1[2] = 0x33;
        CdIntToPos(base + CdPosToInt(loc1), loc1);
        func_801364B0(loc0, loc1, 1, 0);
    }
    func_80086248(2);
    func_80136E68(0);
    while (CdControl(9, 0, 0) == 0) {
    }
    func_80136E68(0);
    while (CdControl(9, 0, 0) == 0) {
    }
    func_80136FF0(arg0);
    func_80139DAC();
    func_8008C064(D_8013C1A8);
    D_8013C1A8 = 0;
    VSyncCallback((void *)D_8013C488);
    func_8002FAF0(D_8013C48C);
    g_Game_801369E0.db[0].hud[1] = 0x801A8000;
    g_Game_801369E0.db[1].hud[1] = 0x801C1000;
    D_800EBFA0_801369E0.f_24 = D_8013C490;
    D_800EBFA0_801369E0.f_28 = D_8013C494;
    D_800EBFA0_801369E0.f_20 = D_8013C498_801369E0;
    D_800EBFA0_801369E0.f_1C = D_8013C49C_801369E0;
    func_8013AA70();
    func_8013BA80(1);
    DrawSync(0);
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136BD4);

s32 StGetNext(void *, void *);

s32 func_80136E00(void *a, void *b) {
    u32 i = 0;

    while (StGetNext(a, b) != 0) {
        if (i++ > 0x16E360) {
            return 1;
        }
    }
    return 0;
}

s32 CdControlB(s32, void *, void *);

void func_80136E68(u8 chan)
{
  struct 
  {
    u8 file;
    u8 chan;
    u16 pad;
  } f;
  if (chan)
  {
    f.file = 1;
    f.chan = chan;
    f.pad = 0;
  }
  else
  {
    f.file = 1;
    f.chan = chan;
    f.pad = 0;
  }
  while (CdControlB(0xD, &f, 0) == 0)
  {
  }

}

typedef struct { u8 pad0[0x10]; u32 f_10; } Fmv_80136EA8;
extern Fmv_80136EA8 *D_8013C484;
void func_801367DC(void);
void DrawSync(s32);
void VSync(s32);
void Gfx_BeginFrame(void);
void Screen_DrawLetterbox(s32, s32, s32);
void *PutDispEnv(void *);
void *PutDrawEnv(void *);
void DrawOTag(u32 *);

void func_80136EA8(void) {
    s32 i;

    i = 0;
    if ((D_8013C484->f_10 >> 3) & 1) {
        G_DRAW.cur ^= 1;
        func_801367DC();
        DrawSync(i);
        G_DRAW.db[1].env[0x18] = 0;
        G_DRAW.db[0].env[0x18] = 0;
        for (; i < 0x100; i += 4) {
            Gfx_BeginFrame();
            Screen_DrawLetterbox(0x1E, 0x1E, i);
            DrawSync(0);
            VSync(0);
            PutDispEnv(&G_DRAW.db[G_DRAW.cur].env[0x5C]);
            PutDrawEnv(G_DRAW.db[G_DRAW.cur].env);
            DrawOTag(&G_DRAW.db[G_DRAW.cur].ot[0xFFF]);
        }
        G_DRAW.db[1].env[0x18] = 1;
        G_DRAW.db[0].env[0x18] = 1;
    }
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136FF0);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80137248);

typedef struct { u8 pad0[8]; s16 x; s16 y; u8 padC[0x406C]; } Buf_80137878;
extern struct { u8 pad0[0x10]; Buf_80137878 db[2]; } g_Game_80137878 asm("g_Game");
void SetDefDrawEnv(void *, s32, s32, s32, s32);

void func_80137878(void) {
    SetDefDrawEnv(&g_Game_80137878.db[0], 0, 0x1E, 0x180, 0xB4);
    SetDefDrawEnv(&g_Game_80137878.db[1], 0, 0x11E, 0x180, 0xB4);
    g_Game_80137878.db[0].y = 0;
    g_Game_80137878.db[0].x = 0;
    g_Game_80137878.db[1].x = 0;
    g_Game_80137878.db[1].y = 0x100;
}

typedef struct { u32 *f_0; u8 pad4[0x1C]; } Ent_801378F0;
extern Ent_801378F0 *D_800B4D64_801378F0 asm("D_800B4D64");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x180]; s32 f_8280; } g_Game_801378F0 asm("g_Game");
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } D_800EBFA0_801378F0 asm("D_800EBFA0");
extern s32 D_8013C4A0;
extern s32 D_8013C4A4;
s32 func_8002FAF0(s32);
void StUnSetRing(void);
void func_80139DAC(void);
s32 Stage_SpecialSetup(void);
s32 Gfx_InitDisplay(void);

void func_801378F0(s32 arg0, u8 *tbl) {
    s32 i;
    Ent_801378F0 *e;

    if (tbl != NULL) {
        i = g_Game_801378F0.f_8280 - 1;
        if (i >= 0) {
        e = D_800B4D64_801378F0;
        do {
            *e[i].f_0 = (*e[i].f_0 & 0xFFF0FFFF) | (tbl[i] << 16);
        } while (--i >= 0);
        }
        func_8008C064((s32)tbl);
    }
    func_8002FAF0(D_8013C48C);
    StUnSetRing();
    while (CdControl(9, 0, 0) == 0) {
    }
    func_80139DAC();
    func_8008C064(D_8013C1A8);
    Stage_SpecialSetup();
    Gfx_InitDisplay();
    DrawSync(0);
    VSync(D_8013C4B4);
    PutDispEnv(&g_Game_801378F0.db[g_Game_801378F0.cur].env[0x5C]);
    PutDrawEnv(g_Game_801378F0.db[g_Game_801378F0.cur].env);
    D_800EBFA0_801378F0.f_24 = D_8013C4A0;
    D_800EBFA0_801378F0.f_28 = D_8013C4A4;
    D_800EBFA0_801378F0.f_2C = D_8013C4A4 * 4 + 0x400;
}

typedef struct { s16 x, y, w, h; } Rect_384;
void ClearImage(Rect_384 *, s32, s32, s32);
void DrawSync(s32);
void VSync(s32);

void func_80137A64(void) {
    Rect_384 r;

    r.w = 0x180;
    r.x = 0;
    r.y = 0;
    r.h = 0x200;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
}

__asm__(".section .text\n.balign 16");

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C484);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C488);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C48C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C490);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C494);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C498);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C49C);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C4A0);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C4A4);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C4B0);

INCLUDE_RODATA("asm/ovl/384/nonmatchings/384_fmv", D_8013C4B4);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80137AC0);

void func_80137D20(void) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0;

    func_801398B0(&sp10, &sp14);
    temp_v0 = func_8008C09C((sp10 * 8) + (sp14 * 4));
    D_8013C544 = temp_v0;
    D_8013C548 = temp_v0 + (sp14 * 4);
}

void func_80137D74(void) {
    func_8008C064(D_8013C544);
    func_8008C064(D_8013C548);
}

void func_80137DAC(void) {
}

/* func_8013B9B0 prototype is the one at the top of src/ovl/384_fmv.c */
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_80137DB4;
extern Mat_80137DB4 D_800E78C0_80137DB4 asm("D_800E78C0");
extern struct { void (*f_0)(u8 *, s16 *); s16 *f_4; } D_8013C550_80137DB4 asm("D_8013C550");
extern struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } D_8013C558_80137DB4 asm("D_8013C558");
extern s32 D_800E7D00_80137DB4 asm("D_800E7D00");
extern struct { u8 pad0[0x20]; u8 r, g, b; } D_800EBFA0_80137DB4 asm("D_800EBFA0");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_80137DB4 asm("g_Game");
s32 func_801398D0(s16 i);
u8 func_80139DE4(s32 i);
void CompMatrix(void *, void *, void *);
void Model_ProjectVertsAlt(void *, void *, void *);

void func_80137DB4(u8 *arg0, s16 *arg1) {
    Mat_80137DB4 m;
    s32 model;

    model = func_801398D0(arg0[3]);
    D_8013C550_80137DB4.f_0 = func_80137DB4;
    D_8013C550_80137DB4.f_4 = arg1;
    func_80139668(&m, arg1, 1);
    CompMatrix(&D_800E78C0_80137DB4, &m, &m);
    Model_ProjectVertsAlt((void *)model, &m, &D_800E7D00_80137DB4);
    D_8013C558_80137DB4.f_0 = 4;
    D_8013C558_80137DB4.f_2 = 0;
    D_8013C558_80137DB4.f_4 = 1;
    D_8013C558_80137DB4.f_6 = 2;
    D_8013C558_80137DB4.f_0 = 0;
    D_8013C558_80137DB4.f_2 = 0;
    D_8013C558_80137DB4.f_4 = 0;
    D_8013C558_80137DB4.f_6 = 0;
    if (func_80139DE4(arg0[3]) & 1) {
        SetBackColor(0xFF, 0xFF, 0xFF);
        func_8013B9B0((u8 *)(g_Game_80137DB4.cur * 0x4078 + (u8 *)&g_Game_80137DB4 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80137DB4, model, (M2C_UNK *)&D_8013C558_80137DB4);
        SetBackColor(D_800EBFA0_80137DB4.r, D_800EBFA0_80137DB4.g, D_800EBFA0_80137DB4.b);
    } else {
        func_8013B9B0((u8 *)(g_Game_80137DB4.cur * 0x4078 + (u8 *)&g_Game_80137DB4 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80137DB4, model, (M2C_UNK *)&D_8013C558_80137DB4);
    }
}

void func_80137F64(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_s0;

    temp_s0 = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    temp_a1 = temp_s0;
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_80137F64;
    D_8013C550.f_4 = arg1;
    func_8013973C(arg1, temp_a1, 1);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = 0;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, temp_s0, &D_8013C558);
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_384;
extern Mat_384 D_800E78C0;
extern Mat_384 D_800AF0A0;
s32 func_8002FAF0(s32);
void CompMatrix(void *, void *, void *);
typedef struct { s32 f_0; Mat_384 m; } CamKey_384;

void func_8013800C(void *arg0, CamKey_384 *k)
{
  Mat_384 *new_var;
  func_8002FAF0(k->f_0);
  D_800E78C0 = k->m;
  new_var = &D_800AF0A0;
  CompMatrix(new_var, &D_800E78C0, &D_800E78C0);
}

void ScaleMatrix(void *, void *);
void func_8004637C(void *);
typedef struct { s32 vx, vy, vz, pad; } Vec_80138094;

void func_80138094(void *arg0, CamKey_384 *k) {
    Mat_384 m;
    Vec_80138094 v;
    s32 s;

    func_8002FAF0(0x148);
    s = 0x148000 / k->f_0;
    v.vx = s;
    v.vy = s;
    v.vz = s;
    func_8004637C(&m);
    ScaleMatrix(&m, &v);
    D_800E78C0 = k->m;
    CompMatrix(&m, &D_800E78C0, &D_800E78C0);
    CompMatrix(&D_800AF0A0, &D_800E78C0, &D_800E78C0);
}

typedef struct { s16 x, y; u16 w, h; } Rect_8013818C;
typedef struct { Rect_8013818C r; u16 n; } Src_8013818C;
void SetDrawMove(void *, Rect_8013818C *, s32, s32);

void func_8013818C(void *arg0, Src_8013818C *s) {
    Rect_8013818C r;
    s16 pos[2];
    u8 *p;
    u32 *ot;
    s32 n;

    r = s->r;
    n = s->n;
    *(s32 *)pos = *(s32 *)&r;
    r.x += r.w * n;
    p = G_DRAW.prim;
    SetDrawMove(p, &r, pos[0], pos[1]);
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    G_DRAW.prim = p + 0x18;
}

void func_80138254(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_s0;

    temp_s0 = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    temp_a1 = temp_s0;
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_80138254;
    D_8013C550.f_4 = arg1;
    func_8013973C(arg1, temp_a1, 0);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = 0;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, temp_s0, &D_8013C558);
}

typedef struct { u8 r, g, b, pad; } Col_384;
extern struct { u8 pad0[0x20]; Col_384 back; } D_800EBFA0;
void SetBackColor(s32, s32, s32);

void func_801382FC(void *arg0, Col_384 *c) {
    D_800EBFA0.back = *c;
    SetBackColor(D_800EBFA0.back.r, D_800EBFA0.back.g, D_800EBFA0.back.b);
}

void func_80138344(void) {
}

void func_8013834C(void) {
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138354);

void func_801383FC(void) {
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_80138404;
extern Mat_80138404 D_800E78C0_80138404 asm("D_800E78C0");
extern struct { void (*f_0)(u8 *, Mat_80138404 *); Mat_80138404 *f_4; } D_8013C550_80138404 asm("D_8013C550");
extern struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } D_8013C558_80138404 asm("D_8013C558");
extern s32 D_800E7D00_80138404 asm("D_800E7D00");
extern struct { u8 pad0[0x20]; u8 r, g, b; } D_800EBFA0_80138404 asm("D_800EBFA0");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_80138404 asm("g_Game");

void func_80138404(u8 *arg0, Mat_80138404 *arg1) {
    Mat_80138404 m;
    s32 model;

    model = func_801398D0(arg0[3]);
    m = *arg1;
    D_8013C550_80138404.f_0 = func_80138404;
    D_8013C550_80138404.f_4 = arg1;
    CompMatrix(&D_800E78C0_80138404, &m, &m);
    Model_ProjectVertsAlt((void *)model, &m, &D_800E7D00_80138404);
    D_8013C558_80138404.f_0 = 0;
    D_8013C558_80138404.f_2 = 0;
    D_8013C558_80138404.f_4 = 0;
    D_8013C558_80138404.f_6 = 0;
    if (func_80139DE4(arg0[3]) & 1) {
        SetBackColor(0xFF, 0xFF, 0xFF);
        func_8013B9B0((u8 *)(g_Game_80138404.cur * 0x4078 + (u8 *)&g_Game_80138404 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80138404, model, (M2C_UNK *)&D_8013C558_80138404);
        SetBackColor(D_800EBFA0_80138404.r, D_800EBFA0_80138404.g, D_800EBFA0_80138404.b);
    } else {
        func_8013B9B0((u8 *)(g_Game_80138404.cur * 0x4078 + (u8 *)&g_Game_80138404 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80138404, model, (M2C_UNK *)&D_8013C558_80138404);
    }
}

void func_801385CC(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_s0;

    temp_s0 = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    temp_a1 = temp_s0;
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_801385CC;
    D_8013C550.f_4 = arg1;
    func_8013980C(arg1, temp_a1);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = 0;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, temp_s0, &D_8013C558);
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4_80138670;

void func_80138670(void *arg0, u32 *col) {
    PolyG4_80138670 *p;
    u32 *ot;

    p = (PolyG4_80138670 *)G_DRAW.prim;
    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 0x180;
    p->y1 = 0;
    p->x2 = 0;
    p->y2 = 0xF0;
    p->x3 = 0x180;
    p->y3 = 0xF0;
    *(u32 *)&p->r0 = col[0];
    *(u32 *)&p->r1 = col[1];
    *(u32 *)&p->r2 = col[2];
    *(u32 *)&p->r3 = col[3];
    ((u8 *)p)[3] = 8;
    p->code = 0x38;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    ADD_PRIM_R(ot, p, "$5", "$4");
    G_DRAW.prim += 0x24;
}

void func_80138728(void) {
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138730);

void func_801388D8(void) {
}

void func_801388E0(void) {
}

void func_801388E8(void) {
}

extern u8 D_800F5AA3;
void *memset(void *, s32, s32);
void func_80138980(void);

void func_801388F0(void *arg0, SVECTOR *p) {
    s32 unused[16]; /* stack space the original reserves but this code never touches */
    SVECTOR w;
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = p->vx;
    v.vy = p->vy;
    v.vz = p->vz;
    w = v;
    if (D_800F5AA3 == 7) {
        func_80138980();
    }
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80138980;

void func_80138980(void) {
    PolyFT4_80138980 *p;
    u32 *ot;

    p = (PolyFT4_80138980 *)G_DRAW.prim;
    ((u8 *)p)[3] = 9;
    p->code = 0x2C;
    p->r0 = 0x80;
    p->g0 = 0x80;
    p->b0 = 0x80;
    p->x0 = 0xDC;
    p->y0 = 0xAA;
    p->x1 = 0x16C;
    p->y1 = 0xAA;
    p->x2 = 0xDC;
    p->y2 = 0xCE;
    p->x3 = 0x16C;
    p->y3 = 0xCE;
    p->u0 = 0x40;
    p->v0 = 0xC0;
    p->u1 = 0xFF;
    p->v1 = 0xC0;
    p->u2 = 0x40;
    p->v2 = 0xEF;
    p->u3 = 0xFF;
    p->v3 = 0xEF;
    p->tpage = 0x2C;
    p->clut = 0x3830;
    p->code = (p->code & 0xFE) | 2;
    ot = &G_DRAW.db[G_DRAW.cur].ot[1];
    ADD_PRIM_R(ot, p, "$5", "$4");
    G_DRAW.prim = (u8 *)(p + 1);
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138A6C);

void SetDrawStp(void *, s32);

void func_80138AC8(void) {
    u8 *p;
    u32 *ot;

    p = G_DRAW.prim;
    SetDrawStp(p, 1);
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    ADD_PRIM_R(ot, p, "$4", "$3");
    G_DRAW.prim = p + 0xC;
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138B40);

void func_80138CDC(void) {
}

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void func_8006F274(SVECTOR *, SVECTOR *, s32);

void func_80138CE4(void *arg0, s16 *src)
{
  s16 *new_var;
  SVECTOR v;
  SVECTOR w;
  v.vx = src[0];
  v.vy = src[1];
  v.vz = src[2];
  w.vx = src[3];
  w.vy = src[4];
  new_var = &src[5];
  w.vz = *new_var;
  func_8006F274(&v, &w, ((g_RandSeed = (g_RandSeed * 5) + 1) >> 4) & 0xFF0);
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138D60);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138E1C);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138ED8);

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_80138F90;
extern Mat_80138F90 D_800E78C0_80138F90 asm("D_800E78C0");
extern struct { void (*f_0)(u8 *, s16 *); s16 *f_4; } D_8013C550_80138F90 asm("D_8013C550");
extern struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } D_8013C558_80138F90 asm("D_8013C558");
extern s32 D_800E7D00_80138F90 asm("D_800E7D00");
extern struct { u8 pad0[0x20]; u8 r, g, b; } D_800EBFA0_80138F90 asm("D_800EBFA0");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_80138F90 asm("g_Game");
s32 func_801398D0(s16 i);
u8 func_80139DE4(s32 i);
void Model_ProjectVertsAlt(void *, void *, void *);

void func_80138F90(u8 *arg0, s16 *arg1) {
    Mat_80138F90 m;
    s32 model;

    model = func_801398D0(arg0[3]);
    D_8013C550_80138F90.f_0 = func_80138F90;
    D_8013C550_80138F90.f_4 = arg1;
    func_80139668(&m, arg1, 0);
    CompMatrix(&D_800E78C0_80138F90, &m, &m);
    Model_ProjectVertsAlt((void *)model, &m, &D_800E7D00_80138F90);
    D_8013C558_80138F90.f_0 = 0;
    D_8013C558_80138F90.f_2 = 0;
    D_8013C558_80138F90.f_4 = 0;
    D_8013C558_80138F90.f_6 = 0;
    if (func_80139DE4(arg0[3]) & 1) {
        SetBackColor(0xFF, 0xFF, 0xFF);
        func_8013B9B0((u8 *)(g_Game_80138F90.cur * 0x4078 + (u8 *)&g_Game_80138F90 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80138F90, model, (M2C_UNK *)&D_8013C558_80138F90);
        SetBackColor(D_800EBFA0_80138F90.r, D_800EBFA0_80138F90.g, D_800EBFA0_80138F90.b);
    } else {
        func_8013B9B0((u8 *)(g_Game_80138F90.cur * 0x4078 + (u8 *)&g_Game_80138F90 + 0x80) + ((*(u16 **)model)[1] & 0xF) * 16,
                      &D_800E7D00_80138F90, model, (M2C_UNK *)&D_8013C558_80138F90);
    }
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80139124);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801391C8);

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_80139668;
typedef struct { s32 vx, vy, vz, pad; } Vec_80139668;
void RotMatrixZYX(void *, void *);
void ScaleMatrix(void *, void *);

void func_80139668(Mat_80139668 *m, s16 *a, s32 mode) {
    Vec_80139668 v;

    if (mode == 1) {
        RotMatrixZYX(a + 6, m);
        v.vx = a[0];
        v.vy = a[1];
        v.vz = a[2];
        ScaleMatrix(m, &v);
        m->t[0] = a[3];
        m->t[1] = a[4];
        m->t[2] = a[5];
    } else {
        RotMatrixZYX(a + 3, m);
        m->t[0] = a[0];
        m->t[1] = a[1];
        m->t[2] = a[2];
    }
}

void func_80139724(void) {
}

void func_8013972C(void) {
}

void func_80139734(void) {
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013973C);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013980C);

extern s32 D_8013C56C;
extern s32 D_8013C570;

void func_801398B0(s32 *arg0, s32 *arg1) {
    *arg0 = D_8013C56C;
    *arg1 = D_8013C570;
}

extern s32 *D_8013C564_801398D0 asm("D_8013C564");

s32 func_801398D0(s16 i) {
    return D_8013C564_801398D0[i];
}

u8 func_801398F0(s32 arg0) {
    return M2C_FIELD(((arg0 * 4) + D_8013C560), u8 *, 3);
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013990C);

void func_80139DAC(void) {
    func_8008C064(D_8013C574);
    func_8008C064(D_8013C564);
}

extern u8 *D_8013C574_80139DE4 asm("D_8013C574");

u8 func_80139DE4(s32 i) {
    return D_8013C574_80139DE4[i];
}

extern u32 D_8013C568;
extern u8 *D_8013C574_80139E00 asm("D_8013C574");

void func_80139E00(void) {
    u32 i;

    for (i = 0; i < D_8013C568; i++) {
        D_8013C574_80139E00[i] = 0;
    }
}

void func_80139E44(void *arg0) {
    void *temp_v1;

    Model_BindMesh();
    temp_v1 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_v1, u16 *, 8) = (u16) M2C_FIELD(temp_v1, u16 *, 0xE);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 4);
}

void func_80139E88(void *arg0, s32 arg1) {
    s32 temp_s0;

    func_80015AC0();
    temp_s0 = arg1 + 0xC;
    M2C_FIELD(arg0, s32 *, 4) = temp_s0;
    M2C_FIELD(arg0, s32 *, 0x18) = temp_s0;
}

typedef struct { s16 i; u8 v; u8 pad; } Set_384;
extern u8 *D_8013C574_80139EC4 asm("D_8013C574");

void func_80139EC4(u16 *len, Set_384 *e) {
    s32 i;
    s32 n;

    n = (u32)(*len - 2) >> 1;
    for (i = 0; i < n; i++) {
        D_8013C574_80139EC4[e[i].i] = e[i].v;
    }
}

s32 func_8008C09C_80139F0C(void) asm("func_8008C09C");

void func_80139F0C(void)
{
  s32 new_var;
  D_8013C574 = (new_var = func_8008C09C_80139F0C());
  func_80139E00();
}

s32 func_80139F38(void *arg0, s32 arg1) {
    s32 var_a2;
    s32 var_v1;
    u8 temp_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    var_a2 = 0;
    if (arg1 > 0) {
        do {
            temp_v0 = M2C_FIELD(var_a0, u8 *, 1);
            var_v1 += 1;
            var_a2 += temp_v0;
            var_a0 += temp_v0 * 4;
        } while (var_v1 < arg1);
    }
    return var_a2;
}

u32 func_80139F6C(void *arg0, u32 arg1) {
    u32 var_v1;
    u8 temp_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (arg1 != 0) {
        do {
            temp_v0 = M2C_FIELD(var_a0, u8 *, 1);
            var_v1 += temp_v0;
            var_a0 += temp_v0 * 4;
        } while (var_v1 < arg1);
    }
    return var_v1;
}

/* an original object file starts at 0x80139FA0 (16-byte aligned) */
__asm__(".section .text\n.balign 16");

extern s16 D_8013C582;
extern u8 D_8013C580;

void func_80139FA0(u8 *a) {
    u8 v = a[4];

    D_8013C582 = 0;
    D_8013C580 = v;
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80139FB8);

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013A460;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013A460;
typedef struct { s16 x, y; } Pt_8013A460;
extern Mat_8013A460 D_800AF0A0_8013A460 asm("D_800AF0A0");
extern Mat_8013A460 D_800AE840;
extern s16 D_800AF0C8;
extern SVECTOR D_8013C590[];
extern s32 D_8013C6FC;
s32 SquareRoot0(s32);
void *RotMatrixZ(s32 r, void *m);
void SetTransMatrix(void *);
void *MulMatrix0(void *, void *, void *);
void SetRotMatrix(void *);
s32 RotTrans(void *, void *, void *);

void func_8013A460(Pt_8013A460 *pos, s16 a, s16 b) {
    SVECTOR v0;
    SVECTOR v1;
    Vec_8013A460 out;
    Mat_8013A460 m;
    Mat_8013A460 r;
    s32 flag;
    s32 i;
    s16 (*p)[4];

    memset(&v0, 0, 8);
    memset(&v1, 0, 8);
    m = D_800AF0A0_8013A460;
    r = D_800AE840;
    p = (s16 (*)[4])D_8013C590;
    *(Pt_8013A460 *)&p[45] = *pos;
    v0.vx = (b * D_800AF0C8) >> 13;
    v1.vx = b + (SquareRoot0(a * a + b * b) >> 1);
    RotMatrixZ(0x111, &r);
    SetTransMatrix(&r);
    for (i = 0; i < 15; i++) {
        MulMatrix0(&m, &r, &m);
        SetRotMatrix(&m);
        RotTrans(&v0, &out, &flag);
        p[i + 15][0] = out.vx;
        p[i + 15][1] = out.vy;
        p[i + 15][2] = 0;
        RotTrans(&v1, &out, &flag);
        p[i + 30][0] = out.vx;
        p[i + 30][1] = out.vy;
        p[i + 30][2] = 0;
    }
    D_8013C6FC = 1;
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013A684);

typedef struct { u16 lo, hi, off, n; } Sub_8013A8A0;
typedef struct { s16 x, y, w, h; } Rect_8013A8A0;
extern Sub_8013A8A0 *D_8013C758_A8A0 asm("D_8013C758");
extern s32 D_8013C710;
extern s32 D_8013C714;
extern Rect_8013A8A0 D_8013C700_A8A0 asm("D_8013C700");
extern u8 D_8013C718[];

void func_8013A8A0(s32 *data) {
    Rect_8013A8A0 r;
    u16 clut[32];
    u8 *text;
    s32 i, j, n;
    u8 lines;

    n = *data;
    D_8013C758_A8A0 = (Sub_8013A8A0 *)(data + 1);
    D_8013C710 = 0;
    D_8013C714 = n;
    for (i = 0; i < D_8013C714; i++) {
        lines = 1;
        text = (u8 *)data + D_8013C758_A8A0[i].off;
        for (j = 0; j < D_8013C758_A8A0[i].n; j++) {
            if (text[j] == 0xD && j > 0 && text[j - 1] >= 0x10) {
                text[j] = 0;
                lines++;
            }
        }
        D_8013C758_A8A0[i].n = lines;
    }
    r = D_8013C700_A8A0;
    StoreImage(&r, D_8013C718);
    for (i = 0; i < 32; i++) {
        if (i == 0 || i == 4 || i == 8 || i == 12 || i == 16 || i == 17 || i == 18 || i == 19) {
            clut[i] = 0;
        } else {
            clut[i] = 0x421;
        }
    }
    LoadImage(&r, clut);
    DrawSync(0);
}

extern Rect_384 D_8013C700;
extern u8 D_8013C718[];
void LoadImage(Rect_384 *, void *);

void func_8013AA70(void) {
    Rect_384 r = D_8013C700;

    LoadImage(&r, D_8013C718);
    DrawSync(0);
}

void func_8013AAC8(s32 *arg0, s32 arg1) {
    s32 *var_a0;
    s32 temp_a1;
    s32 var_v1;

    var_a0 = arg0;
    temp_a1 = arg1 >> 2;
    var_v1 = 0;
    if (temp_a1 > 0) {
        do {
            *var_a0 = 0;
            var_v1 += 1;
            var_a0 = (void *)((u8 *)var_a0 + (4));
        } while (var_v1 < temp_a1);
    }
}

typedef struct { u16 lo, hi, off, n; } Sub_8013AAF0;
extern Sub_8013AAF0 *D_8013C758_AAF0 asm("D_8013C758");
s32 func_8013AC98(u32 x);
s32 func_8008DE68(u8 *, u16);
void func_8008DDB0(s16, s16);
void func_8013AD40(u8 *, s32);
void Msg_PutChar(u16, s32, s32);

void func_8013AAF0(u32 frame) {
    s32 idx = D_8013C710;
    Sub_8013AAF0 *e = (Sub_8013AAF0 *)((idx << 3) + (s32)D_8013C758_AAF0);
    u8 *text = (u8 *)D_8013C758_AAF0 + (e->off - 4);
    s32 n = e->n;
    u8 *p;
    s32 i, k, w, maxw, pos, y;

    D_8013C710 = func_8013AC98(frame);
    if (D_8013C710 < 0) {
        return;
    }
    i = 0;
    maxw = 0;
    pos = 0;
    for (; i < n; i++) {
        w = func_8008DE68(text + pos, 0);
        while (text[pos]) {
            pos++;
        }
        pos++;
        if (maxw < w) {
            maxw = w;
        }
    }
    maxw = (0x180 - maxw) >> 1;
    for (k = 0; k < 2; k++) {
        pos = 0;
        y = 0xAE;
        for (i = 0; i < n; i++) {
            func_8008DDB0(maxw + k, y + k);
            func_8013AD40(text + pos, k ? 0x1F6 : 0x1F0);
            while (text[pos]) {
                pos++;
            }
            pos++;
            Msg_PutChar(0xD, 0, 0);
            y += 0x12;
        }
    }
}

typedef struct { u16 lo, hi; u8 pad4[4]; } Range_384;
extern s32 D_8013C714;
extern Range_384 *D_8013C758;

s32 func_8013AC98(u32 x) {
    s32 i;

    for (i = 0; i < D_8013C714; i++) {
        if (x >= D_8013C758[i].lo && D_8013C758[i].hi >= x) {
            return i;
        }
    }
    return -1;
}

s32 func_8013AD04(u8 *arg0) {
    s32 var_v1;
    u8 *var_a0;
    u8 temp_v0;

    var_v1 = 0;
    var_a0 = arg0 + 1;
    if (*arg0 != 0) {
        do {
            temp_v0 = *var_a0;
            if (temp_v0 == 0xD) {
                var_v1 += 1;
            }
            var_a0 += 1;
        } while (temp_v0 != 0);
    }
    return var_v1;
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013AD40);

typedef struct { u8 loc[4]; u32 size; } Req_8013ADA0;
extern volatile s32 D_8013C760_ADA0 asm("D_8013C760");
extern u32 D_8013C770_ADA0 asm("D_8013C770");
extern s32 D_8013C774_ADA0 asm("D_8013C774");
extern u32 D_8013C778_ADA0 asm("D_8013C778");
extern s32 D_8013C77C_ADA0 asm("D_8013C77C");
void func_8013AE90(s32);

void func_8013ADA0(s32 arg0, Req_8013ADA0 *req) {
    s32 mode;
    u32 n;

    while (D_8013C760_ADA0 != 0) {
    }
    D_8013C760_ADA0 = 1;
    D_8013C770_ADA0 = n = (req->size + 0x7FF) >> 11;
    D_8013C778_ADA0 = (req->size & 0x7FF) ? req->size - ((n - 1) << 11) : 0;
    D_8013C774_ADA0 = arg0;
    mode = 0x80;
    while (CdControl(0xE, &mode, 0) == 0) {
    }
    VSync(3);
    while (CdControl(6, req, 0) == 0) {
    }
    D_8013C77C_ADA0 = CdReadyCallback((s32)func_8013AE90);
}

s32 func_8013AE80(void) {
    return D_8013C760;
}

void func_8013AE90(s32 arg0) {
    s32 temp_a0;
    s32 temp_v0;

    temp_a0 = arg0 & 0xFF;
    if (temp_a0 == 1) {
        if (D_8013C770 != temp_a0) {
            CdGetSector(D_8013C774, 0x200);
            D_8013C774 += 0x800;
        } else {
            CdGetSector(D_8013C774, D_8013C778);
            D_8013C774 += D_8013C778 * 4;
        }
        temp_v0 = D_8013C770 - 1;
        D_8013C770 = temp_v0;
        if (temp_v0 == 0) {
            CdReadyCallback(D_8013C77C);
            D_8013C760 = 0;
        }
    }
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013AF50);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013B390);

s32 func_8013B8D0(void *arg0, s32 arg1, void *arg2) {
    s32 var_t0;
    void *var_a3;

    var_a3 = arg0;
    var_t0 = 0;
    if (arg1 > 0) {
        do {
            if (M2C_FIELD(arg2, u8 *, 3) & 1) {
                M2C_FIELD(var_a3, u8 *, 3) = (u8) ((M2C_FIELD(var_a3, u8 *, 3) & 0xFD) | (M2C_FIELD(arg2, u8 *, 0) * 2));
            }
            if (M2C_FIELD(arg2, u8 *, 3) & 2) {
                M2C_FIELD(var_a3, u8 *, 2) = (u8) ((M2C_FIELD(var_a3, u8 *, 2) & 0xE7) | (M2C_FIELD(arg2, u8 *, 2) * 8));
                if (M2C_FIELD(var_a3, u8 *, 3) & 4) {
                    M2C_FIELD(var_a3, u16 *, 0x12) = (u16) ((M2C_FIELD(var_a3, u16 *, 0x12) & 0xFF9F) | (M2C_FIELD(arg2, u8 *, 2) << 5));
                }
            }
            if (M2C_FIELD(arg2, u8 *, 3) & 4) {
                M2C_FIELD(var_a3, u8 *, 3) = (u8) (M2C_FIELD(arg2, u8 *, 1) | (M2C_FIELD(var_a3, u8 *, 3) & 0xFE));
            }
            var_t0 += 1;
            var_a3 += M2C_FIELD(var_a3, u8 *, 1) * 4;
        } while (var_t0 < arg1);
    }
    return 0;
}

/* an original object file starts at 0x8013B9B0 (16-byte aligned) */
__asm__(".section .text\n.balign 16");
INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013B9B0);

typedef struct { s16 x, y, w, h; } Rect_8013BA80;
extern Rect_8013BA80 D_8013C7B0_8013BA80[] asm("D_8013C7B0");
extern s32 D_8013C7E0;
s32 StoreImage(void *rect, u32 *p);

void func_8013BA80(s32 load) {
    u32 *buf;
    s32 i;

    buf = (u32 *)0x80196000;
    D_8013C7E0 = 6;
    if (load == 0) {
        i = 0;
        do {
            StoreImage(&D_8013C7B0_8013BA80[i], buf);
            buf += D_8013C7B0_8013BA80[i].w * D_8013C7B0_8013BA80[i].h / 2;
            i++;
        } while (i < D_8013C7E0);
    } else {
        i = 0;
        do {
            LoadImage(&D_8013C7B0_8013BA80[i], buf);
            buf += D_8013C7B0_8013BA80[i].w * D_8013C7B0_8013BA80[i].h / 2;
            i++;
        } while (i < D_8013C7E0);
    }
}

s32 func_8013BB8C(void) {
    return 6;
}

void *func_8013BB94(s32 arg0) {
    return (void *)((u8 *)&D_8013C7B0 + (arg0 * 8));
}

typedef struct { s16 x, y, w, h; } Rect_8013BBA8;
extern Rect_8013BBA8 D_8013C7B0_8013BBA8[] asm("D_8013C7B0");
extern Rect_8013BBA8 D_8013C7A0;
extern GameDraw g_Game_8013BBA8 asm("g_Game");

void func_8013BBA8(void) {
    u8 *p;
    s32 i;
    Rect_8013BBA8 r;

    GameDraw *g = &g_Game_8013BBA8;
    p = g->prim;
    r = D_8013C7A0;
    r.y = M2C_FIELD(g->db[g->cur].env, s16 *, 0xA);
    for (i = 0; i < D_8013C7E0; i++) {
        r.x = i << 6;
        SetDrawMove(p, &r, D_8013C7B0_8013BBA8[i].x, D_8013C7B0_8013BBA8[i].y);
        ADD_PRIM_R(g_Game_8013BBA8.db[g_Game_8013BBA8.cur].ot, p, "$4", "$3");
        p += 0x18;
    }
    SetDrawStp(p, 1);
    ADD_PRIM_R(g_Game_8013BBA8.db[g_Game_8013BBA8.cur].ot, p, "$5", "$3");
    g_Game_8013BBA8.prim = p + 0xC;
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013BD1C);
