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
s32 CdControl(M2C_UNK, s32, M2C_UNK);
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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013668C);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801367DC);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136884);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801369E0);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136EA8);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80136FF0);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80137248);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80137878);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801378F0);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80137DB4);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138094);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013818C);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138404);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138670);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138980);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80138F90);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80139124);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_801391C8);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_80139668);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013A460);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013A684);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013A8A0);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013AAF0);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013ADA0);

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

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013BA80);

s32 func_8013BB8C(void) {
    return 6;
}

void *func_8013BB94(s32 arg0) {
    return (void *)((u8 *)&D_8013C7B0 + (arg0 * 8));
}

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013BBA8);

INCLUDE_ASM("asm/ovl/384/nonmatchings/384_fmv", func_8013BD1C);
