#include "common.h"
#include "m2c_macros.h"

extern M2C_UNK D_800E7D00;
extern struct S_D_8013C550 { u8 pad_0[0x4]; s32 f_4; } D_8013C550;
extern struct S_D_8013C558 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } D_8013C558;
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; } g_Game;

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

typedef struct { u8 pad0[0x14]; u32 f_14; u8 pos[4]; } Fmv_80136074;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80136074 asm("g_Game");
extern struct { u8 pad0[0x158]; u16 f_158; u8 pad15A[2]; s32 f_15C; } g_Pad_80136074 asm("g_Pad");
extern Fmv_80136074 *D_8013C484_80136074 asm("D_8013C484");
extern void (*D_8013C1AC_80136074[])(u8 *, u8 *) asm("D_8013C1AC");
extern DrawBuf D_800F03D0_80136074[] asm("D_800F03D0");
extern s32 D_8013C4B0_80136074 asm("D_8013C4B0");
extern s32 D_8013C4B4_80136074 asm("D_8013C4B4");
s32 func_8013668C(s32 *mode, s32 idx);
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
void func_80136454(s32, s32);
s32 func_80136E00(void *, void *);
void func_801369E0(s32 arg0);
void SetDispMask(s32 mask);
s32 VSync_80136074(s32) asm("VSync");
void Gfx_BeginFrame(void);
void func_80139E00(void);
void func_80069BEC(void);
void Fx_UpdateAll(void);
u32 StFreeRing(u32 *base);
s32 StRingStatus(s16 *, s16 *);
void DrawSync(s32);
void *PutDispEnv(void *env);
void *PutDrawEnv(void *env);
void DrawOTag(u32 *p);
void func_8001325C(s32);
__asm__(".section .rodata\n\t.globl D_8013C480\nD_8013C480:\n\t.word 0x00000000\n\t.section .text");
extern s32 D_8013C480;

s32 func_80136074(s32 idx) {
    u8 *ring;
    u32 *head;
    s16 st0;
    s16 st1;
    u8 *rec;
    s32 skip;
    u32 pad;
    u32 old;
    register u32 lag asm("$18");
    s32 now;
    s32 n;
    s32 code;

    skip = 0;
    pad = 0;
    lag = 0;
    while (func_8013668C(&D_8013C480, idx) != 0) {
    }
    CdIntToPos(CdPosToInt(D_8013C484_80136074->pos) + 5, D_8013C484_80136074->pos);
    func_80136454((s32)D_8013C484_80136074->pos, D_8013C480);
    if (func_80136E00(&ring, &head) != 0) {
        code = 2;
fail:
        func_801369E0(code);
        return 1;
    }
    SetDispMask(1);
    now = VSync_80136074(-1);
    g_Game_80136074.frame = 1;
    while (1) {
        Gfx_BeginFrame();
        for (rec = ring; *(u16 *)rec != 0; rec += *(u16 *)rec * 2) {
            D_8013C1AC_80136074[rec[2]](rec, rec + 4);
        }
        func_80139E00();
        func_80069BEC();
        Fx_UpdateAll();
        if (*(u16 *)(rec + 2) == 0xFFFF) {
            break;
        }
        if (D_8013C484_80136074->f_14 != 0 && g_Game_80136074.frame >= D_8013C484_80136074->f_14) {
            code = 0;
            goto fail;
        }
        StFreeRing((u32 *)ring);
        if (old != pad && (pad & 0x860)) {
            code = 1;
            goto fail;
        }
        g_Game_80136074.frame++;
        if (func_80136E00(&ring, &head) != 0) {
            code = 1;
            goto fail;
        }
        if (skip) {
            skip = 0;
            n = lag >> 1;
            lag -= n * 2;
            do {
                StRingStatus(&st0, &st1);
                if (st1 >= 4) {
                    StFreeRing((u32 *)ring);
                    if (func_80136E00(&ring, &head) != 0) {
                        code = 1;
                        goto fail;
                    }
                }
            } while (--n);
        }
        DrawSync(0);
        VSync_80136074(D_8013C4B4_80136074);
        D_8013C4B4_80136074 = D_8013C4B0_80136074;
        PutDispEnv(&g_Game_80136074.db[g_Game_80136074.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136074.db[g_Game_80136074.cur].env);
        {
        register s32 then asm("$16") = now;
        now = VSync_80136074(-1);
        { register s32 d asm("$2") = now - then; lag += d; }
        }
        if (lag >= 3) {
            skip = 1;
        }
        DrawOTag(&g_Game_80136074.db[g_Game_80136074.cur].ot[0xFFF]);
        { register DrawBuf *b asm("$6") = D_800F03D0_80136074; DrawOTag(b[g_Game_80136074.cur].env); }
        func_8001325C(0);
        old = pad;
        pad = g_Pad_80136074.f_158 | (g_Pad_80136074.f_15C << 16);
    }
    DrawSync(0);
    VSync_80136074(D_8013C4B4_80136074);
    PutDispEnv(&g_Game_80136074.db[g_Game_80136074.cur].env[0x5C]);
    PutDrawEnv(g_Game_80136074.db[g_Game_80136074.cur].env);
    func_801369E0(0);
    return 0;
}

void func_80136454(s32 arg0, M2C_UNK arg1) {
    do {
loop_1:
        if (CdControl(2, arg0, 0) == 0) {
            goto loop_1;
        }
        CdSync(0, 0);
    } while (CdRead2(arg1) == 0);
}

extern struct { u8 pad0[0x158]; u16 f_158; u8 pad15A[2]; s32 f_15C; } g_Pad_801364B0 asm("g_Pad");
s32 CdControlB(s32, void *, void *);
s32 CdReady(s32 mode, u8 *result);
s32 CdPosToInt(void *p);
void func_8001325C(s32);

void func_801364B0(u8 *pos, u8 *end, u8 mode, s32 seek) {
    u8 result[8];
    u8 loc[8];
    u8 param[4];
    s32 last;
    u32 i;
    s32 r;

    __asm__ volatile("");
    param[0] = 1;
    param[1] = mode;
    *(u16 *)&param[2] = 0;
    CdPosToInt(pos);
    last = CdPosToInt(end);
    do {
        if (seek) {
            i = 0;
            do {
                CdControl(0xD, param, 0);
                CdControl(0x15, pos, 0);
                CdControl(0x1B, 0, 0);
                r = CdSync(0, 0);
                i++;
                if (r == 2) {
                    break;
                }
            } while (i < 100);
            CdReady(0, 0);
            seek = 0;
        }
        CdControl(0x10, 0, result);
        loc[0] = result[0];
        loc[1] = result[1];
        loc[2] = result[2];
        if ((u32)last < (u32)CdPosToInt(loc)) {
            seek = 1;
        }
        func_8001325C(0);
    } while ((g_Pad_801364B0.f_158 | (g_Pad_801364B0.f_15C << 16)) == 0);
    CdControlB(9, 0, 0);
}

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
    Fmv_LoadModelTable((void *)0x80148000);
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

typedef struct { s16 x, y, w, h; } Rect_80136BD4;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_80136BD4;
typedef struct { u8 pad0[0x10]; u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1; u32 rest : 28; } Fmv_80136BD4;
typedef struct { Rect_80136BD4 clip; s16 ofs[2]; Rect_80136BD4 tw; u16 tpage; u8 dtd, dfe, isbg, r0, g0, b0; u32 dr_env[16]; } DrawEnv_80136BD4;
typedef struct { Rect_80136BD4 disp; Rect_80136BD4 screen; u8 isinter, isrgb24, pad0, pad1; } DispEnv_80136BD4;
typedef struct { DrawEnv_80136BD4 draw; DispEnv_80136BD4 disp; u32 ot[0x1000]; u32 hud; u8 *primbase; } Db_80136BD4;
extern struct { u8 pad0[0x10]; Db_80136BD4 db[2]; } g_Game_80136BD4 asm("g_Game");
extern Rect_80136BD4 D_8013C050;
extern Fmv_80136BD4 *D_8013C484_80136BD4 asm("D_8013C484");
extern struct { u8 pad0[0x1C]; s32 f_1C; u8 f_20, f_21, f_22, f_23; s32 f_24; s32 f_28; } D_800EBFA0_80136BD4 asm("D_800EBFA0");
void *memset(void *, s32, s32);
void SetGeomOffset(s32 ofx, s32 ofy);
void SetDefDrawEnv(void *, s32, s32, s32, s32);
void *SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetBackColor(s32, s32, s32);
void SetColorMatrix(void *);

void func_80136BD4(void) {
    s32 o[2];
    Rect_80136BD4 r;
    Mat_80136BD4 cm;
    u16 *scr;
    s32 f;
    Db_80136BD4 *d0;
    Db_80136BD4 *d1;

    r = D_8013C050;
    memset(&cm, 0, 0x20);
    func_8002FAF0(0x148);
    SetGeomOffset(0xC0, 0x78);
    scr = (u16 *)0x1F800000;
    if (D_8013C484_80136BD4->b3 == 1) {
        o[0] = 0x1E;
        o[1] = 0x3C;
    } else {
        o[1] = 0;
        o[0] = 0;
    }
    d0 = &g_Game_80136BD4.db[0];
    SetDefDrawEnv(&d0->draw, 0, o[0], 0x180, 0xF0 - o[1]);
    SetDefDispEnv(&d0->disp, 0, 0x100, 0x180, 0xF0);
    d1 = &g_Game_80136BD4.db[1];
    g_Game_80136BD4.db[0].draw.ofs[1] = 0;
    g_Game_80136BD4.db[0].draw.ofs[0] = 0;
    SetDefDrawEnv(&d1->draw, 0, o[0] + 0x100, 0x180, 0xF0 - o[1]);
    SetDefDispEnv(&g_Game_80136BD4.db[1].disp, 0, 0, 0x180, 0xF0);
    g_Game_80136BD4.db[1].draw.ofs[1] = 0x100;
    g_Game_80136BD4.db[1].draw.ofs[0] = 0;
    g_Game_80136BD4.db[0].primbase = (u8 *)0x801C6000;
    g_Game_80136BD4.db[1].primbase = (u8 *)0x801DF000;
    g_Game_80136BD4.db[1].draw.dtd = 1;
    g_Game_80136BD4.db[0].draw.dtd = 1;
    g_Game_80136BD4.db[1].draw.dfe = 0;
    g_Game_80136BD4.db[0].draw.dfe = 0;
    f = D_8013C484_80136BD4->b2;
    g_Game_80136BD4.db[1].disp.isinter = 0;
    g_Game_80136BD4.db[0].disp.isinter = 0;
    d0->draw.r0 = 0;
    d0->draw.g0 = 0;
    d0->draw.b0 = 0;
    d1->draw.r0 = 0;
    d1->draw.g0 = 0;
    d1->draw.b0 = 0;
    D_800EBFA0_80136BD4.f_23 = 0;
    D_800EBFA0_80136BD4.f_22 = 0xFF;
    D_800EBFA0_80136BD4.f_21 = 0xFF;
    D_800EBFA0_80136BD4.f_20 = 0xFF;
    g_Game_80136BD4.db[1].draw.isbg = f;
    g_Game_80136BD4.db[0].draw.isbg = f;
    SetBackColor(0xFF, 0xFF, 0xFF);
    SetColorMatrix(&cm);
    D_800EBFA0_80136BD4.f_24 = 0;
    D_800EBFA0_80136BD4.f_28 = 0x2000;
    scr[0x1E0] = D_800EBFA0_80136BD4.f_24;
    scr[0x1E1] = D_800EBFA0_80136BD4.f_28;
    D_800EBFA0_80136BD4.f_1C = 0;
    DrawSync(0);
}

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

typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[0xC]; u32 f_10; } Fmv_80136FF0;
extern Fmv_80136FF0 *D_8013C484_80136FF0 asm("D_8013C484");
extern GameDraw g_Game_80136FF0 asm("g_Game");
extern void *jtbl_8013C058[];
s32 VSync_80136FF0(s32) asm("VSync");
void func_80138354(void *arg0, u8 *c);

void func_80136FF0(s32 arg0) {
    u8 col[4];
    u8 rec[8];
    s32 i;
    s32 n;
    u32 k;

    n = 0x100;
    if (!((D_8013C484_80136FF0->f_10 >> 3) & 1)) {
        n = (arg0 != 0) << 8;
    }
    k = D_8013C484_80136FF0->f_3;
    __asm__("" : : "i"(&&c1), "i"(&&c2), "i"(&&c0));
    if (k >= 9) {
        goto start;
    }
    goto *jtbl_8013C058[k];
c1:
    __asm__ volatile(".L80137068:");
    col[3] = 1;
    goto start;
c2:
    __asm__ volatile(".L80137074:");
    col[3] = 2;
    goto start;
c0:
    __asm__ volatile(".L80137080:");
    n = 1;
    col[3] = 0;
start:
    DrawSync(0);
    i = 0;
    VSync_80136FF0(D_8013C4B4);
    PutDispEnv(&g_Game_80136FF0.db[g_Game_80136FF0.cur].env[0x5C]);
    PutDrawEnv(g_Game_80136FF0.db[g_Game_80136FF0.cur].env);
    func_801367DC();
    SetDefDrawEnv(&g_Game_80136FF0.db[0], i, i, 0x180, 0xF0);
    SetDefDrawEnv(&g_Game_80136FF0.db[1], i, 0x100, 0x180, 0xF0);
    g_Game_80136FF0.db[1].env[0x18] = 0;
    g_Game_80136FF0.db[0].env[0x18] = 0;
    Gfx_BeginFrame();
    DrawSync(i);
    for (; i < n; i += 4) {
        col[2] = i;
        col[1] = i;
        col[0] = i;
        func_80138354(rec, col);
        DrawSync(0);
        VSync_80136FF0(D_8013C4B4);
        PutDispEnv(&g_Game_80136FF0.db[g_Game_80136FF0.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136FF0.db[g_Game_80136FF0.cur].env);
        DrawOTag(&g_Game_80136FF0.db[g_Game_80136FF0.cur].ot[0xFFF]);
        if (col[3] == 0) {
            return;
        }
        Gfx_BeginFrame();
    }
    g_Game_80136FF0.db[1].env[0x18] = 1;
    g_Game_80136FF0.db[0].env[0x18] = 1;
}

typedef struct { s32 name; s32 f4; u32 flags; s32 fC; u8 file[0x18]; } FmvEnt_80137248;
typedef struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x26]; u16 f_8126; u8 pad8128[0x158]; s32 f_8280; } Game_80137248;
typedef struct { u32 *f_0; u8 pad4[0x1C]; } Ent_80137248;
extern Game_80137248 g_Game_80137248 asm("g_Game");
extern struct { u8 pad0[0x158]; u16 f_158; u8 pad15A[2]; s32 f_15C; } g_Pad_80137248 asm("g_Pad");
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } D_800EBFA0_80137248 asm("D_800EBFA0");
extern struct { u8 pad0[8]; void *f_8; s32 f_C; s32 f_10; } D_800F5AA0_80137248 asm("D_800F5AA0");
extern Ent_80137248 *D_800B4D64_80137248 asm("D_800B4D64");
extern FmvEnt_80137248 D_8013C244_80137248[] asm("D_8013C244");
extern void (*D_8013C1AC_80137248[])(u8 *, u8 *) asm("D_8013C1AC");
extern void *D_8013C1B8_80137248 asm("D_8013C1B8");
extern u32 D_8013C250_80137248 asm("D_8013C250");
extern char D_8013C07C_80137248[] asm("D_8013C07C");
extern u8 D_800EC3D0_80137248[] asm("D_800EC3D0");
#define G2_80137248 (*(Game_80137248 *)(D_800EC3D0_80137248 - 0x80))
extern s32 D_8013C4A0;
extern s32 D_8013C4A4;
s32 VSync_80137248(s32) asm("VSync");
void Gfx_WaitFlip(void);
void bios_printf(char *, ...);
void bios_exit(s32);
void *Cd_GetFileEntry(void *, s32);
void func_80137878(void);
void func_80136000(s32, s32);
void func_8013A8A0(s32 *);
void func_80138094();
void func_80136E68(u8);
void func_80136454(s32, s32);
s32 func_80136E00(void *, void *);
void func_80137A64(void);
void func_80016F34(void);
void Hud_Draw(void);
void func_8005ACE8(void);
void func_80069BEC(void);
void Fx_UpdateAll(void);
void Tex_UpdateAnims(void);
u32 StFreeRing(u32 *base);
s32 StRingStatus(s16 *, s16 *);
void func_801378F0(s32, u8 *);

s32 func_80137248(s32 idx) {
    s16 st0;
    s16 st1;
    u32 *head;
    u8 *ring;
    u8 *rec;
    register u8 *tbl asm("$22");
    s32 unk;
    s32 mode;
    s32 i;
    u32 pad;
    s32 now;
    u32 lag;
    register s32 skip asm("$23");
    u32 old;
    s32 n;

    skip = 0;
    tbl = 0;
    pad = 0;
    lag = 0;
    Gfx_WaitFlip();
    __asm__("" : "=r"(unk));
    D_8013C48C = func_800315D0();
    if (D_800F5AA0_80137248.f_8 == 0) {
        bios_printf(D_8013C07C_80137248);
        bios_exit(1);
    }
    Cd_GetFileEntry(D_8013C244_80137248[idx].file, D_8013C244_80137248[idx].name);
    mode = 0x120;
    func_80137878();
    func_80136000(0, 0);
    Fmv_LoadModelTable(D_800F5AA0_80137248.f_8);
    switch (idx) {
    case 1:
    case 3:
    case 8:
        D_800F5AA0_80137248.f_C = D_800F5AA0_80137248.f_10;
        break;
    case 12:
        tbl = (u8 *)func_8008C09C(g_Game_80137248.f_8280);
        for (i = g_Game_80137248.f_8280 - 1; i >= 0; i--) {
            tbl[i] = (*D_800B4D64_80137248[i].f_0 & 0xF0000) >> 16;
            *D_800B4D64_80137248[i].f_0 |= 0xF0000;
        }
        break;
    }
    if (D_800F5AA0_80137248.f_C != 0) {
        func_8013A8A0((s32 *)D_800F5AA0_80137248.f_C);
    }
    if (idx == 6) {
        D_8013C1B8_80137248 = func_80138094;
    }
    if ((D_8013C244_80137248[idx].flags >> 1) & 1) {
        mode |= 0x48;
        func_80136E68(1);
    }
    func_80086248(-1);
    while (CdControlB(0xC, 0, 0) == 0) {
    }
    func_80136454((s32)CdIntToPos(CdPosToInt(D_8013C244_80137248[idx].file) + 5, D_8013C244_80137248[idx].file), mode);
    if (func_80136E00(&ring, &head) != 0) {
        goto fail;
    }
    {
        s32 a = D_800EBFA0_80137248.f_24;
        s32 b = D_800EBFA0_80137248.f_28;
        D_800EBFA0_80137248.f_24 = 0xF000;
        D_800EBFA0_80137248.f_28 = 0x1000;
        D_800EBFA0_80137248.f_2C = 0x4400;
        D_8013C4A0 = a;
        D_8013C4A4 = b;
    }
    func_80137A64();
    D_8013C4B4 = 2;
    now = VSync_80137248(-1);
    g_Game_80137248.frame = 1;
    do {
        Gfx_BeginFrame();
        for (rec = ring; *(u16 *)rec != 0; rec += *(u16 *)rec * 2) {
            D_8013C1AC_80137248[rec[2]](rec, rec + 4);
        }
        func_80016F34();
        Hud_Draw();
        if (g_Game_80137248.f_8126 != 0x46) {
            func_8005ACE8();
        }
        func_80069BEC();
        Fx_UpdateAll();
        Tex_UpdateAnims();
        if (*(u16 *)(rec + 2) == 0xFFFF) {
            goto done;
        }
        if (D_8013C250_80137248 != 0 && g_Game_80137248.frame >= D_8013C250_80137248) {
            goto fail;
        }
        StFreeRing((u32 *)ring);
        g_Game_80137248.frame++;
        while (func_80136E00(&ring, &head) != 0) {
        }
        if (skip) {
            n = lag >> 1;
            skip = 0;
    __asm__("" : "=r"(unk));
            lag -= n * 2;
            do {
                StRingStatus(&st0, &st1);
                if (st1 >= 4) {
                    StFreeRing((u32 *)ring);
                    while (func_80136E00(&ring, &head) != 0) {
                    }
                }
            } while (--n);
        }
        DrawSync(0);
        {
        register s32 then asm("$16") = now;
        VSync_80137248(D_8013C4B4);
        PutDispEnv(&g_Game_80137248.db[g_Game_80137248.cur].env[0x5C]);
        PutDrawEnv(g_Game_80137248.db[g_Game_80137248.cur].env);
        now = VSync_80137248(-1);
        { register s32 d asm("$2") = now - then; lag += d; }
        }
        if (lag >= 3) {
            skip = 1;
        }
        DrawOTag(&g_Game_80137248.db[g_Game_80137248.cur].ot[0xFFF]);
        func_8001325C(0);
        old = pad;
        pad = g_Pad_80137248.f_158 | (g_Pad_80137248.f_15C << 16);
    } while (old == pad || !(pad & 0x860));
fail:
    func_801378F0(unk, tbl);
    return 1;
done:
    DrawSync(0);
    VSync_80137248(D_8013C4B4);
    PutDispEnv(&G2_80137248.db[G2_80137248.cur].env[0x5C]);
    PutDrawEnv(G2_80137248.db[G2_80137248.cur].env);
    DrawOTag(&G2_80137248.db[G2_80137248.cur].ot[0xFFF]);
    G2_80137248.cur ^= 1;
    func_801378F0(unk, tbl);
    Gfx_BeginFrame();
    return 0;
}

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

extern struct { u8 pad0[0x8120]; u16 f_8120; u8 pad8122[4]; u16 f_8126; u8 pad8128[0x32]; u16 f_815A; } g_Game_80137AC0 asm("g_Game");
s32 func_80136074(s32);
s32 Cd_StartFileLoad(s32, s32);
s32 func_800116C0(void);
void Cd_Update(void);
s32 func_80096540(s32);
s32 SaveByte_Set(s32, s32);

s32 func_80137AC0(void) {
    VSync(2);
    func_80136074(g_Game_80137AC0.f_815A);
    Cd_StartFileLoad(0, 0xC);
    while (func_800116C0() == 0) {
        Cd_Update();
        VSync(2);
    }
    switch (g_Game_80137AC0.f_815A) {
    case 0:
        g_Game_80137AC0.f_8120 = 8;
        g_Game_80137AC0.f_8126 = 1;
        break;
    case 1:
        g_Game_80137AC0.f_8120 = 0xD;
        func_80096540(1);
        break;
    case 2:
        g_Game_80137AC0.f_8120 = 3;
        break;
    case 3:
        g_Game_80137AC0.f_8120 = 0xB;
        g_Game_80137AC0.f_8126 = 0x4E;
        Cd_StartFileLoad(1, 0x4E);
        while (func_800116C0() == 0) {
            Cd_Update();
            VSync(2);
        }
        break;
    case 4:
        g_Game_80137AC0.f_8120 = 0x1D;
        func_80096540(4);
        break;
    case 5:
        g_Game_80137AC0.f_8120 = 0xD;
        func_80096540(5);
        break;
    case 6:
        g_Game_80137AC0.f_8120 = 0x23;
        break;
    case 7:
        SaveByte_Set(0xB, 5);
        g_Game_80137AC0.f_8120 = 0xA;
        g_Game_80137AC0.f_8126 = 6;
        break;
    case 8:
        g_Game_80137AC0.f_8120 = 0xB;
        g_Game_80137AC0.f_8126 = 0x56;
        Cd_StartFileLoad(1, 0x56);
        while (func_800116C0() == 0) {
            Cd_Update();
            VSync(2);
        }
        break;
    }
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text\n\t.balign 16");

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

extern GameDraw g_Game_80138354 asm("g_Game");

void func_80138354(void *arg0, u8 *c) {
    u8 *p = g_Game_80138354.prim;
    u32 code;

    ADD_PRIM_R(g_Game_80138354.db[g_Game_80138354.cur].ot, p, "$6", "$3");
    code = ((c[3] & 3) << 5) | 0xE1000000;
    p[3] = 4;
    *(u32 *)(p + 4) = code;
    p += 4;
    *(s16 *)(p + 0xC) = 0x180;
    *(s32 *)(p + 8) = 0;
    *(s16 *)(p + 0xE) = 0xF0;
    p[4] = c[0];
    p[5] = c[1];
    p[6] = c[2];
    p[7] = 0x63;
    g_Game_80138354.prim = p + 0x10;
}

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

typedef struct { s16 x, y, w, h; } Rect_80138730;
typedef struct { Rect_80138730 a; Rect_80138730 b; s16 bx, by; s16 ax, ay; Rect_80138730 c; } Win_80138730;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80138730 asm("g_Game");
extern s32 D_8013C530;
extern u32 *D_8013C540_80138730 asm("D_8013C540");

void func_80138730(void *arg0, Win_80138730 *w) {
    u8 *p;
    Rect_80138730 r;
    register u32 *ot asm("$3");

    p = g_Game_80138730.prim;
    if (D_8013C530 != g_Game_80138730.frame) {
        D_8013C530 = g_Game_80138730.frame;
        D_8013C540_80138730 = &g_Game_80138730.db[g_Game_80138730.cur].ot[0xFFF];
    }
    if (w->c.w != 0) {
        SetDrawMove(p, (void *)&w->c, 0x370, 0x40);
        ot = D_8013C540_80138730;
    ADD_PRIM_R(ot, p, "$4", "$2");
        D_8013C540_80138730 = (u32 *)p;
        p += 0x18;
    }
    r.x = w->a.x - (s16)(w->c.x - 0x370);
    r.y = w->a.y - (s16)(w->c.y - 0x40);
    r.w = w->a.w;
    r.h = w->a.h;
    SetDrawMove(p, (void *)&r, w->ax, w->ay);
    ot = D_8013C540_80138730;
    ADD_PRIM_R(ot, p, "$4", "$2");
    D_8013C540_80138730 = (u32 *)p;
    p += 0x18;
    r.x = w->b.x - (s16)(w->c.x - 0x370);
    r.y = w->b.y - (s16)(w->c.y - 0x40);
    r.w = w->b.w;
    r.h = w->b.h;
    SetDrawMove(p, (void *)&r, w->bx, w->by);
    ot = D_8013C540_80138730;
    ADD_PRIM_R(ot, p, "$4", "$2");
    D_8013C540_80138730 = (u32 *)p;
    p += 0x18;
    g_Game_80138730.prim = p;
}

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

void Effect_SpawnAt(s32, void *);

void func_80138A6C(void *arg0, s16 *e) {
    s16 *p = e;
    switch (e[0]) {
    case 0:
        Effect_SpawnAt(e[1] + 4, e + 2);
        break;
    case 1:
        Effect_SpawnAt(0x106, p + 2);
        break;
    case 2:
        break;
    }
}

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

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_80138B40;
extern GameDraw g_Game_80138B40 asm("g_Game");

void func_80138B40(void) {
    register Sprt_80138B40 *p asm("$15");
    s32 y;
    u32 *ot;

    p = (Sprt_80138B40 *)g_Game_80138B40.prim;
    {
        u8 *b = (u8 *)&g_Game_80138B40;
        y = *(s16 *)(b + g_Game_80138B40.cur * 0x4078 + 0x6E); /* db[cur].disp.disp.y */
    }
    ((u8 *)p)[3] = 4;
    p->code = 0x67;
    p->x0 = 0x100;
    p->y0 = 0;
    p->w = 0x80;
    p->h = 0xF0;
    p->u0 = 0;
    p->v0 = 0;
    ot = (u32 *)(g_Game_80138B40.cur * 0x4078 + ((u8 *)&g_Game_80138B40 + 0x80));
    ADD_PRIM_R(ot, p, "$4", "$3");
    p++;
    ((u8 *)p)[3] = 1;
    ((u32 *)p)[1] = 0xE1000000 | 0x200 | 0 | ((((2 & 3) << 7) | ((0 & 3) << 5) | ((y & 0x100) >> 4) | ((0x100 & 0x3FF) >> 6) | ((y & 0x200) << 2)) & 0x9FF);
    ot = (u32 *)(g_Game_80138B40.cur * 0x4078 + ((u8 *)&g_Game_80138B40 + 0x80));
    ADD_PRIM_R(ot, p, "$4", "$3");
    p = (Sprt_80138B40 *)((u8 *)p + 8);
    ((u8 *)p)[3] = 4;
    p->code = 0x67;
    p->x0 = 0;
    p->y0 = 0;
    p->w = 0x100;
    p->h = 0xF0;
    p->u0 = 0;
    p->v0 = 0;
    ot = (u32 *)(g_Game_80138B40.cur * 0x4078 + ((u8 *)&g_Game_80138B40 + 0x80));
    ADD_PRIM_R(ot, p, "$4", "$3");
    p++;
    ((u8 *)p)[3] = 1;
    ((u32 *)p)[1] = 0xE1000000 | 0x200 | 0 | ((((2 & 3) << 7) | ((0 & 3) << 5) | ((y & 0x100) >> 4) | ((0 & 0x3FF) >> 6) | ((y & 0x200) << 2)) & 0x9FF);
    ot = (u32 *)(g_Game_80138B40.cur * 0x4078 + ((u8 *)&g_Game_80138B40 + 0x80));
    ADD_PRIM_R(ot, p, "$4", "$3");
    p = (Sprt_80138B40 *)((u8 *)p + 8);
    g_Game_80138B40.prim = (u8 *)p;
}

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

void func_80138D60(void *arg0, u16 *arg1) {
    s32 key;
    s32 model;

    key = (s32)(arg1 + 2);
    model = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_80137F64;
    D_8013C550.f_4 = key;
    func_8013973C(key, model, 1);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = *arg1 << 6;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, model, &D_8013C558);
}

void func_80138E1C(void *arg0, u16 *arg1) {
    s32 key;
    s32 model;

    key = (s32)(arg1 + 2);
    model = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_80137F64;
    D_8013C550.f_4 = key;
    func_8013973C(key, model, 0);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = *arg1 << 6;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, model, &D_8013C558);
}

void func_80138ED8(void *arg0, u16 *arg1) {
    s32 key;
    s32 model;

    key = (s32)(arg1 + 2);
    model = func_801398D0(M2C_FIELD(arg0, u8 *, 3));
    M2C_FIELD(&D_8013C550, void (**)(void *, s32), 0) = func_801385CC;
    D_8013C550.f_4 = key;
    func_8013980C(key, model);
    D_8013C558.f_0 = 0;
    D_8013C558.f_2 = *arg1 << 6;
    D_8013C558.f_4 = 2;
    D_8013C558.f_6 = 0;
    func_8013B9B0((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, model, &D_8013C558);
}

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

void SetFarColor(s32, s32, s32);
void DpqColor(void *, s32, void *);

void func_80139124(u8 *arg0, u8 *col) {
    s32 i;
    s32 *model;
    s32 n;
    u32 *src;
    u32 *dst;
    s32 p;

    i = 0;
    model = (s32 *)func_801398D0(arg0[3]);
    n = *(u16 *)(model[0] + 8);
    SetFarColor(col[0], col[1], col[2]);
    src = (u32 *)model[6];
    dst = (u32 *)model[1];
    p = *(s32 *)(col + 4);
    for (; i < n; i++) {
        DpqColor(src++, p, dst++);
    }
}

typedef struct { s16 x, y, w, h; } Rect_801391C8;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_801391C8;
typedef struct { SVECTOR v[4]; SVECTOR b[4]; } Quads_801391C8;
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_801391C8;
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; s16 x1, y1; s16 x2, y2; s16 x3, y3; } PolyF4_801391C8;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_801391C8 asm("g_Game");
extern Quads_801391C8 D_8013C4F0_801391C8 asm("D_8013C4F0");
extern Mat_801391C8 D_800AF0A0_801391C8 asm("D_800AF0A0");
extern s32 D_8013C534;
void *MulMatrix0(void *, void *, void *);
void ApplyMatrixSV(void *, void *, void *);
#define ADDPRIM1_801391C8(ot, p) __asm__ volatile("addiu %0, %0, 4\n\tlwl $4, 2(%0)\n\tsll $3, %2, 8\n\tswl $3, 2(%0)\n\tswl $4, %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$3", "$4")

void func_801391C8(u8 *arg0, s32 *arg1) {
    Rect_801391C8 r;
    Rect_801391C8 r2;
    Mat_801391C8 m;
    Quads_801391C8 q;
    PolyFT4_801391C8 *p;
    PolyF4_801391C8 *f;
    u8 *d;
    s32 s;
    s32 i;

    s = *arg1;
    __asm__ volatile("");
    r2.x = 0;
    { register u8 *e asm("$2") = (u8 *)(g_Game_801391C8.cur * 0x4078) + (s32)&g_Game_801391C8; r2.y = *(s16 *)(e + 0x6E); }
    r2.w = 0x180;
    r2.h = 0xF0;
    r = r2;
    m.m[0][0] = s;
    m.m[0][1] = 0;
    m.m[0][2] = 0;
    m.m[1][0] = 0;
    m.m[1][1] = s;
    m.m[1][2] = 0;
    m.m[2][0] = 0;
    m.m[2][1] = 0;
    m.m[2][2] = s;
    memset(m.t, 0, 12);
    q = D_8013C4F0_801391C8;
    MulMatrix0(&D_800AF0A0_801391C8, &m, &m);
    for (i = 3; i >= 0; i--) {
        ApplyMatrixSV(&m, &q.v[i], &q.v[i]);
        q.v[i].vx += 0xC0;
        q.v[i].vy += 0x78;
    }
    p = (PolyFT4_801391C8 *)g_Game_801391C8.prim;
    p->len = 9;
    p->code = 0x2D;
    p->x0 = q.v[0].vx;
    p->y0 = q.v[0].vy;
    p->x1 = q.v[1].vx;
    p->y1 = q.v[1].vy;
    p->x2 = q.v[2].vx;
    p->y2 = q.v[2].vy;
    p->x3 = q.v[3].vx;
    p->y3 = q.v[3].vy;
    p->u0 = 0;
    p->v0 = 0x1E;
    p->u1 = 0xBF;
    p->v1 = 0x1E;
    p->u2 = 0;
    p->v2 = 0xD1;
    p->u3 = 0xBF;
    p->v3 = 0xD1;
    p->tpage = 0x10A;
    ADD_PRIM_R(&g_Game_801391C8.db[g_Game_801391C8.cur].ot[1], p, "$3", "$2");
    p++;
    for (i = 3; i >= 0; i--) {
        ApplyMatrixSV(&m, &q.b[i], &q.b[i]);
        q.b[i].vx += 0xC0;
        q.b[i].vy += 0x78;
    }
    p->len = 9;
    p->code = 0x2D;
    p->x0 = q.b[0].vx;
    p->y0 = q.b[0].vy;
    p->x1 = q.b[1].vx;
    p->y1 = q.b[1].vy;
    p->x2 = q.b[2].vx;
    p->y2 = q.b[2].vy;
    p->x3 = q.b[3].vx;
    p->y3 = q.b[3].vy;
    p->u0 = 0;
    p->v0 = 0x1E;
    p->u1 = 0xBF;
    p->v1 = 0x1E;
    p->u2 = 0;
    p->v2 = 0xD1;
    p->u3 = 0xBF;
    p->v3 = 0xD1;
    p->tpage = 0x10D;
    ADDPRIM1_801391C8((u32 *)(g_Game_801391C8.cur * 0x4078 + ((u8 *)&g_Game_801391C8 + 0x80)), p);
    p++;
    f = (PolyF4_801391C8 *)p;
    f->len = 5;
    f->code = 0x28;
    f->r0 = 1;
    f->g0 = 1;
    f->b0 = 1;
    f->x0 = 0;
    f->y0 = 0;
    f->x1 = 0x180;
    f->y1 = 0;
    f->x2 = 0;
    f->y2 = 0xF0;
    f->x3 = 0x180;
    f->y3 = 0xF0;
    ADDPRIM1_801391C8((u32 *)(g_Game_801391C8.cur * 0x4078 + ((u8 *)&g_Game_801391C8 + 0x80)), f);
    d = (u8 *)(f + 1);
    g_Game_801391C8.prim = d;
    if (D_8013C534 != 0) {
        D_8013C534 = 0;
        SetDrawMove(d, &r, 0x280, 0);
        ADDPRIM1_801391C8((u32 *)(g_Game_801391C8.cur * 0x4078 + ((u8 *)&g_Game_801391C8 + 0x80)), d);
    }
}

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

extern Mat_80139668 D_800E9C80_8013973C[] asm("D_800E9C80");
void Model_ProjectBonedVerts(void *);

M2C_UNK func_8013973C(key, model, n) s16 *key; u8 **model; M2C_UNK n; {
    s32 i;
    s32 step = n * 3 + 6;

    for (i = 0; i < *(u16 *)(*model + 4); i++, key += step) {
        func_80139668(&D_800E9C80_8013973C[i], key, n);
        CompMatrix(&D_800E78C0, &D_800E9C80_8013973C[i], &D_800E9C80_8013973C[i]);
    }
    Model_ProjectBonedVerts(model);
}

extern Mat_384 D_800E9C80_8013980C[] asm("D_800E9C80");

M2C_UNK func_8013980C(s32 arg0, s32 arg1) {
    s32 i;
    u8 **model = (u8 **)arg1;

    for (i = 0; i < *(u16 *)(*model + 4); i++) {
        CompMatrix(&D_800E78C0, &((Mat_384 *)arg0)[i], &D_800E9C80_8013980C[i]);
    }
    Model_ProjectBonedVerts(model);
}

__asm__(".section .text\n.balign 16");

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

typedef struct { u8 pad0[2]; u16 f2; u8 pad4[2]; u16 f6; u16 f8; u8 padA[4]; u16 fE; u8 pad10[2]; u16 f12; u8 pad14[2]; u16 f16; } MdlHdr_8013990C;
typedef struct { MdlHdr_8013990C *f0; u8 *f4; u8 *f8; u8 padC[0xC]; u8 *f18; } MdlObj_8013990C;
extern u32 *D_8013C560_8013990C asm("D_8013C560");
extern MdlObj_8013990C **D_8013C564_8013990C asm("D_8013C564");
extern u32 D_8013C568_8013990C asm("D_8013C568");
extern u32 D_8013C56C_8013990C asm("D_8013C56C");
extern u32 D_8013C570_8013990C asm("D_8013C570");
void func_80139E44_8013990C(void *, void *) asm("func_80139E44");
void func_80139E88_8013990C(void *, void *) asm("func_80139E88");
s32 func_80139F38_8013990C(void *, s32) asm("func_80139F38");
s32 func_80139F6C_8013990C(void *, s32) asm("func_80139F6C");
void func_80139F0C_8013990C(u32) asm("func_80139F0C");
void func_800A3760(void *, void *, s32);
s32 func_8013B8D0(void *arg0, s32 arg1, void *arg2);

void Fmv_LoadModelTable(void *arg0) {
    u8 buf[4];
    MdlObj_8013990C **t;
    u32 cnt;
    u8 *out;
    u32 *e;
    u32 i;
    MdlObj_8013990C *obj;
    s32 n;
    s32 m;
    s32 sz;
    MdlObj_8013990C *ref;
    u16 *ent;

    out = (u8 *)0x80193800;
    cnt = ((u32 *)arg0)[0];
    e = (u32 *)arg0 + 1;
    n = 0;
    i = 0;
    D_8013C560_8013990C = e;
    D_8013C568_8013990C = cnt;
    for (; i < D_8013C568_8013990C; i++) {
        switch (((u8 *)&e[i])[3] & 0xF) {
        case 2:
            n += 0x1C;
            break;
        case 3:
        case 4:
            n += 0x1C;
            break;
        }
    }
    i = 0;
    D_8013C564_8013990C = (MdlObj_8013990C **)func_8008C09C(D_8013C568_8013990C * 4 + n);
    obj = (MdlObj_8013990C *)((u8 *)D_8013C564_8013990C + D_8013C568_8013990C * 4);
    if (D_8013C568_8013990C != 0) {
        do {
            t = D_8013C564_8013990C;
            t[i] = obj;
            switch (((u8 *)e)[3]) {
            case 2:
                func_80139E44_8013990C(obj, (u32 *)arg0 + (e[0] & 0xFFFFFF));
                {
                MdlObj_8013990C **sl = D_8013C564_8013990C;
                obj++;
                if (D_8013C56C_8013990C < sl[i]->f0->f12) {
                    D_8013C56C_8013990C = sl[i]->f0->f12;
                }
                if (D_8013C570_8013990C < sl[i]->f0->fE) {
                    D_8013C570_8013990C = sl[i]->f0->fE;
                }
                }
                break;
            case 3:
                func_80139E88_8013990C(obj, (u32 *)arg0 + (e[0] & 0xFFFFFF));
                {
                MdlObj_8013990C **sl = D_8013C564_8013990C;
                obj++;
                if (D_8013C56C_8013990C < sl[i]->f0->f6) {
                    D_8013C56C_8013990C = sl[i]->f0->f6;
                }
                if (D_8013C570_8013990C < sl[i]->f0->f8) {
                    D_8013C570_8013990C = sl[i]->f0->f8;
                }
                }
                break;
            case 4: {
                s32 cnt2;
                u8 *src;
                u8 *dst;
                u8 *src2;
                ent = (u16 *)e;
                switch (((u8 *)&D_8013C560_8013990C[((u8 *)e)[2]])[3]) {
                case 2:
                    ref = t[((u8 *)e)[2]];
                    func_80139E44_8013990C(obj, ref->f0);
                    src2 = ref->f4;
                    src = ref->f8;
                    cnt2 = ref->f0->fE;
                    obj++;
                    dst = out;
                    n = ref->f0->f16;
                    D_8013C564_8013990C[i]->f8 = out;
                    m = func_80139F6C_8013990C(src, n);
                    break;
                case 3:
                    ref = t[((u8 *)e)[2]];
                    func_80139E88_8013990C(obj, ref->f0);
                    src2 = ref->f4;
                    src = ref->f8;
                    cnt2 = ref->f0->f8;
                    obj++;
                    dst = out;
                    m = ref->f0->f2;
                    D_8013C564_8013990C[i]->f8 = out;
                    n = func_80139F38_8013990C(src, m);
                    break;
                }
                sz = n * 4;
                func_800A3760(dst, src, sz);
                out += sz;
                if (*ent & 1) {
                    buf[3] = 3;
                    buf[0] = 1;
                    buf[2] = (*ent >> 1) & 3;
                    func_8013B8D0(dst, m, buf);
                }
                if (*ent & 8) {
                    buf[3] = 4;
                    buf[1] = 0;
                    func_8013B8D0(dst, m, buf);
                }
                if (*ent & 0x10) {
                    s32 sz2;
                    ent = (u16 *)D_8013C564_8013990C[i];
                    sz2 = cnt2 * 4;
                    ((MdlObj_8013990C *)ent)->f4 = out;
                    func_800A3760(out, src2, sz2);
                    out += sz2;
                    ((MdlObj_8013990C *)ent)->f18 = out;
                    func_800A3760(out, src2, sz2);
                    out += sz2;
                }
                break;
            }
            }
            i++;
            e++;
        } while (i < D_8013C568_8013990C);
    }
    func_80139F0C_8013990C(D_8013C568_8013990C);
}

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

typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_80139FB8;
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139FB8;
extern struct { s32 frame; u32 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80139FB8 asm("g_Game");
u16 GetTPage(s32, s32, s32, s32);
extern u8 D_800EC3D0[];
#define OT_80139FB8 ((u32 *)(g_Game_80139FB8.cur * 0x4078 + ob))

void func_80139FB8(void) {
    u8 *ob;
    Sprt_80139FB8 *s;
    PolyFT4_80139FB8 *p1;
    PolyFT4_80139FB8 *p;
    u8 *env;
    s32 tp;
    s32 c;

    ob = D_800EC3D0;
    {
        register s32 b asm("$3");
        s32 t;

        D_8013C582 += (t = D_8013C580);
        b = t;
        if (D_8013C582 > 0xC0) {
            D_8013C582 = b;
        }
    }
    s = (Sprt_80139FB8 *)g_Game_80139FB8.prim;
    env = g_Game_80139FB8.db[g_Game_80139FB8.cur].env + 0x5C;
    s->len = 4;
    s->code = 0x65;
    s->x0 = 0;
    s->y0 = 0;
    s->w = 0xC0 - D_8013C582;
    s->h = 0xF0;
    s->u0 = D_8013C580;
    s->v0 = 0;
    ADD_PRIM_R(OT_80139FB8, s, "$5", "$3");
    g_Game_80139FB8.prim += sizeof(Sprt_80139FB8);

    p1 = (PolyFT4_80139FB8 *)g_Game_80139FB8.prim;
    p1->len = 9;
    p1->code = 0x2D; c = 0x2D;
    p1->x0 = 0xC0 - D_8013C582;
    p1->y0 = 0x55;
    p1->x1 = 0xD0 - D_8013C582;
    p1->y1 = 0x5F;
    p1->x2 = 0xC0 - D_8013C582;
    p1->y2 = 0x9B;
    p1->x3 = 0xD0 - D_8013C582;
    p1->y3 = 0x91;
    p1->u0 = -((u8)D_8013C582 + 0x40) + D_8013C580;
    p1->v0 = 0x55;
    p1->u1 = -((u8)D_8013C582 + 0x30) + D_8013C580;
    p1->v1 = 0x5F;
    p1->u2 = -((u8)D_8013C582 + 0x40) + D_8013C580;
    p1->v2 = 0x9B;
    p1->u3 = -((u8)D_8013C582 + 0x30) + D_8013C580;
    p1->v3 = 0x91;
    p1->tpage = GetTPage(2, 0, 0, *(s16 *)(env + 2));
    ADD_PRIM_R(OT_80139FB8, p1, "$4", "$3");
    g_Game_80139FB8.prim += sizeof(PolyFT4_80139FB8);

    s = (Sprt_80139FB8 *)g_Game_80139FB8.prim;
    s->len = 4;
    s->code = 0x65;
    s->x0 = D_8013C582 + 0xD0;
    s->y0 = 0;
    s->u0 = (u8)(D_8013C582 + 0x10 - D_8013C580);
    s->w = 0xB0;
    s->v0 = 0;
    s->h = 0xF0;
    ADD_PRIM_R(OT_80139FB8, s, "$5", "$3");
    g_Game_80139FB8.prim += sizeof(Sprt_80139FB8);

    p = (PolyFT4_80139FB8 *)g_Game_80139FB8.prim;
    p->len = 9;
    p->code = c;
    p->x0 = D_8013C582 + 0xC0;
    p->y0 = 0;
    p->x1 = D_8013C582 + 0xD0;
    p->y1 = 0;
    p->x2 = D_8013C582 + 0xC0;
    p->y2 = 0x55;
    p->x3 = D_8013C582 + 0xD0;
    p->y3 = 0x5F;
    p->u0 = (u8)D_8013C582 - D_8013C580;
    p->v0 = 0;
    p->u1 = (u8)D_8013C582 - D_8013C580 + 0x10;
    p->v1 = 0;
    p->u2 = (u8)D_8013C582 - D_8013C580;
    p->v2 = 0x55;
    p->u3 = (u8)D_8013C582 - D_8013C580 + 0x10;
    p->v3 = 0x5F;
    tp = GetTPage(2, 0, 0xC0, *(s16 *)(env + 2));
    p->tpage = tp;
    ADD_PRIM_R(OT_80139FB8, p, "$5", "$4");
    g_Game_80139FB8.prim += sizeof(PolyFT4_80139FB8);

    p = (PolyFT4_80139FB8 *)g_Game_80139FB8.prim;
    p->len = 9;
    p->code = c;
    p->x0 = D_8013C582 + 0xC0;
    p->y0 = 0x9B;
    p->x1 = D_8013C582 + 0xD0;
    p->y1 = 0x91;
    p->x2 = D_8013C582 + 0xC0;
    p->y2 = 0xF0;
    p->x3 = D_8013C582 + 0xD0;
    p->y3 = 0xF0;
    p->u0 = (u8)D_8013C582 - D_8013C580;
    p->v0 = 0x9B;
    p->u1 = (u8)D_8013C582 - D_8013C580 + 0x10;
    p->v1 = 0x91;
    p->u2 = (u8)D_8013C582 - D_8013C580;
    p->v2 = 0xF0;
    p->u3 = (u8)D_8013C582 - D_8013C580 + 0x10;
    p->v3 = 0xF0;
    p->tpage = tp;
    ADD_PRIM_R(OT_80139FB8, p, "$5", "$4");
    g_Game_80139FB8.prim += sizeof(PolyFT4_80139FB8);
}
/* an original object file starts at 0x8013A460 (16-byte aligned) */
__asm__(".section .text\n.balign 16");

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

extern SVECTOR D_8013C590_8013A684[4][15] asm("D_8013C590");
void gteMIMefunc(void *, void *, s32, s32);

u8 *func_8013A684(u32 *ot, u8 *p, s16 *c, s32 n) {
    Pt_8013A460 pos;
    s32 i;
    s32 k;
    SVECTOR *v;

    v = D_8013C590_8013A684[0];
    if (*(s32 *)&v[45].vz == 0) {
        memset(&pos, 0, 4);
        func_8013A460(&pos, 0x180, 0xF0);
    }
    for (i = 0; i < 15; i++) {
        *(s32 *)&v[i] = *(s32 *)c;
    }
    gteMIMefunc(D_8013C590_8013A684[0], D_8013C590_8013A684[1], 15, n);
    ((u8 *)&D_8013C590_8013A684[3][0])[3] = 0x29;
    for (i = 0; i < 14; i++) {
        p[3] = 5;
        *(s32 *)(p + 4) = *(s32 *)&D_8013C590_8013A684[3][0];
        *(s32 *)(p + 8) = *(s32 *)&D_8013C590_8013A684[0][i + 1];
        *(s32 *)(p + 0xC) = *(s32 *)&D_8013C590_8013A684[0][i];
        *(s16 *)(p + 0x10) = D_8013C590_8013A684[2][i + 1].vx + c[0];
        *(s16 *)(p + 0x12) = D_8013C590_8013A684[2][i + 1].vy + c[1];
        *(s16 *)(p + 0x14) = D_8013C590_8013A684[2][i].vx + c[0];
        *(s16 *)(p + 0x16) = D_8013C590_8013A684[2][i].vy + c[1];
        ADD_PRIM_R(ot, p, "$3", "$2");
        p += 0x18;
    }
    p[3] = 5;
    *(s32 *)(p + 4) = *(s32 *)&D_8013C590_8013A684[3][0];
    *(s32 *)(p + 8) = *(s32 *)&D_8013C590_8013A684[0][0];
    *(s32 *)(p + 0xC) = *(s32 *)&D_8013C590_8013A684[0][i];
    *(s16 *)(p + 0x10) = D_8013C590_8013A684[2][0].vx + c[0];
    *(s16 *)(p + 0x12) = D_8013C590_8013A684[2][0].vy + c[1];
    *(s16 *)(p + 0x14) = D_8013C590_8013A684[2][i].vx + c[0];
    *(s16 *)(p + 0x16) = D_8013C590_8013A684[2][i].vy + c[1];
    ADD_PRIM_R(ot, p, "$3", "$2");
    return p + 0x18;
}

__asm__(".section .text\n.balign 16");

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

u8 *Msg_ReadChar(u8 *, u16 *);

void func_8013AD40(u8 *s, s32 color) {
    u16 c;

    while (s = Msg_ReadChar(s, &c), c != 0) {
        Msg_PutChar(c, color, 0);
    }
}

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

typedef struct { s16 x, y, w, h; } Rect_8013AF50;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; } g_Game_8013AF50 asm("g_Game");
extern s32 D_8013C780;
extern u8 *D_800EC354;
extern u32 D_800EC35C;
int abs(int);
#define ADD_PRIM_RR_8013AF50(ot, p) { unsigned int _t1, _t2; __asm__ volatile("lwl %0, 2(%2)\n\tsll %1, %3, 8\n\tswl %1, 2(%2)\n\tswl %0, 2(%3)" : "=&r"(_t1), "=&r"(_t2) : "r"(ot), "r"(p) : "memory"); }

void func_8013AF50(void) {
    Rect_8013AF50 r;
    u8 *p;
    u32 *ot;
    s32 k;
    s32 y;
    s32 n;
    s32 amp;
    s32 w;
    s32 off;
    s32 i;
    s32 ofs;
    s32 half;
    s32 ofs2;
    s32 j;

    p = g_Game_8013AF50.prim;
    r.x = 0;
    r.w = 0x180;
    r.h = 1;
    ofs = ((u32)(i = 0) < g_Game_8013AF50.cur) << 8;
    r.y = ofs + 0xFE;
    ot = g_Game_8013AF50.ot;
    SetDrawMove(p, &r, i, ofs | 0xFF);
    ADD_PRIM_RR_8013AF50(ot, p);
    p += 0x18;
    k = 0x104 - g_Game_8013AF50.frame % 300;
    for (y = 1; y < 0xF0; y += 2) {
        if (abs(k - y) < 0x1A) {
            *(u32 *)(p + 4) = 0x202020;
            *(u32 *)(p + 0xC) = 0x101010;
        } else {
            *(u32 *)(p + 4) = 0x101010;
            *(u32 *)(p + 0xC) = 0x202020;
        }
        p[3] = 4;
        p[7] = 0x52;
        *(s16 *)(p + 8) = 0;
        *(s16 *)(p + 0xA) = y;
        *(s16 *)(p + 0x10) = 0x180;
        *(s16 *)(p + 0x12) = y;
        ADD_PRIM_ASM(ot, p);
        p += 0x78;
        p[3] = 1;
        *(u32 *)(p + 4) = 0xE1000240;
        ADD_PRIM_ASM(ot, p);
        p += 0x30;
    }
    D_800EC354 = p;
    n = D_8013C780--;
    if (n > 10) {
        amp = 0;
        w = 4;
    } else {
        amp = 10;
        w = 4;
        if (n <= 0) {
            D_8013C780 = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 200 + 20;
        }
    }
    __asm__ volatile("" : : "r"(w));
    ofs2 = ((u32)(j = 0) < D_800EC35C) << 8;
    for (; j < 0xF0; j += 2) {
        if (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 100 <= amp) {
            half = (u32)w >> 1;
            off = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % w + half;
            if (off < 0) {
                r.x = -off;
                r.y = (ofs + 0xFF);
                r.w = off + 0x180;
                r.h = 1;
                SetDrawMove(p, &r, 0, (j + ofs2));
                ADD_PRIM_RR_8013AF50(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (j + ofs2);
                r.w = 0x180;
                r.h = 1;
                SetDrawMove(p, &r, 0, (ofs + 0xFF));
                ADD_PRIM_RR_8013AF50(ot, p);
                p += 0x18;
            }
            if (off > 0) {
                r.x = 0;
                r.y = (ofs + 0xFF);
                r.w = 0x180 - off;
                r.h = 1;
                SetDrawMove(p, &r, off, (j + ofs2));
                ADD_PRIM_RR_8013AF50(ot, p);
                p += 0x18;
                r.x = 0;
                r.y = (j + ofs2);
                r.w = 0x180;
                r.h = 1;
                SetDrawMove(p, &r, 0, (ofs + 0xFF));
                ADD_PRIM_RR_8013AF50(ot, p);
                p += 0x18;
            }
        }
    }
    D_800EC354 = p;
}

__asm__(".section .text\n.balign 16");

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
#include "gte.h"
void Model_DrawPrims(s32, u8 *, s32);
typedef struct { u16 *f_0; s32 *f_4; u8 *f_8; } Mdl_8013B9B0;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_8013B9B0;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0_8013B9B0 asm("D_800EBFA0");

M2C_UNK func_8013B9B0(void *arg0, M2C_UNK *arg1, s32 arg2, M2C_UNK *arg3) {
    Mdl_8013B9B0 *m = (Mdl_8013B9B0 *)arg2;
    u16 *q = (u16 *)arg3;
    s32 i;
    s32 *src;
    u8 *c;
    Scr_8013B9B0 *sc = (Scr_8013B9B0 *)0x1F800000;

    c = m->f_8;
    src = m->f_4;
    for (i = 0; i < m->f_0[4]; i++) {
        gte_ldIR(0x1000, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2_mem(&sc->rgb[i]);
    }
    sc->f_3C0 = D_800EBFA0_8013B9B0.f_24;
    sc->f_3C2 = D_800EBFA0_8013B9B0.f_28;
    sc->f_3C6 = q[0];
    sc->f_3C4 = q[1];
    sc->f_3F4 = ((u8 *)q)[4];
    Model_DrawPrims((s32)arg0, c, (s32)arg1);
}

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

extern Rect_8013BBA8 D_8013C7B0_8013BD1C[] asm("D_8013C7B0");
#define getTPage_8013BD1C(tp, abr, x, y) ((((tp)&0x3)<<7)|(((abr)&0x3)<<5)|(((y)&0x100)>>4)|((((u32)(x))&0x3ff)>>6)|(((y)&0x200)<<2))
#define getMode_8013BD1C(dfe, dtd, tpage) ((0xe1000000)|((dtd)?0x0200:0)|((dfe)?0x0400:0)|((tpage)&0x9ff))
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013BD1C;
typedef struct { u8 tag[3]; u8 len; u32 code; } Tp_8013BD1C;
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; s16 w, h; } Tile_8013BD1C;

void func_8013BD1C(u32 *ot, u8 level) {
    Sprt_8013BD1C *p;
    Tp_8013BD1C *tp;
    Tile_8013BD1C *t;
    s32 i;
    register s16 c asm("$11");
    s16 x;
    Rect_8013BBA8 *r;

    r = D_8013C7B0_8013BD1C;
    __asm__("addiu %0, %1, -255" : "=r"(c) : "r"(level * 2));
    p = (Sprt_8013BD1C *)D_800EC354;
    for (i = 0; i < D_8013C7E0; i++) {
        p->len = 4;
        p->code = 0x66;
        p->r0 = level - 0x7F;
        p->g0 = level - 0x7F;
        p->b0 = level - 0x7F;
        p->x0 = i << 6;
        p->y0 = 0;
        p->u0 = r[i].x % 256;
        p->v0 = 0;
        p->w = 0x40;
        p->h = 0x100;
        ADD_PRIM_R(ot, p, "$3", "$2");
        tp = (Tp_8013BD1C *)(p + 1);
        x = r[i].x / 256 * 256;
        tp->len = 1;
        tp->code = getMode_8013BD1C(0, 1, getTPage_8013BD1C(2, 1, x, r[i].y));
        ADD_PRIM_R(ot, tp, "$3", "$2");
        p = (Sprt_8013BD1C *)(tp + 1);
    }
    t = (Tile_8013BD1C *)(tp + 1);
    t->len = 3;
    t->code = 0x62;
    if (c < 0) {
        c = 0;
    }
    t->r0 = c;
    t->g0 = c;
    t->b0 = c;
    t->x0 = 0;
    t->y0 = 0;
    t->w = 0x180;
    t->h = 0xF0;
    ADD_PRIM_R(ot, t, "$3", "$2");
    tp = (Tp_8013BD1C *)(t + 1);
    tp->len = 1;
    tp->code = 0xE1000354;
    ADD_PRIM_R(ot, tp, "$3", "$2");
    D_800EC354 = (u8 *)t;
}
