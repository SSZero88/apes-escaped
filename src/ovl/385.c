#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136000);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_801362A4);

extern u8 D_800EC360[];
void SetGeomOffset(s32 ofx, s32 ofy);
void *SetDefDrawEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void *SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetDispMask(s32 mask);

s32 func_80136424(void) {
    u8 *s2;
    u8 *v0;
    u8 *nv;

    SetGeomOffset(0xC0, 0x78);
    SetDefDrawEnv(D_800EC360, 0, 0, 0x280, 0x1E0);
    s2 = D_800EC360 + 0x4078;
    SetDefDrawEnv(s2, 0, 0, 0x280, 0x1E0);
    SetDefDispEnv(D_800EC360 + 0x5C, 0, 0, 0x280, 0x1E0);
    SetDefDispEnv(D_800EC360 + 0x40D4, 0, 0, 0x280, 0x1E0);
    v0 = D_800EC360;
    v0 = v0 - 0x10;
    nv = D_800EC360 + 0x7FF0;
    *(s8 *)(v0 + 0x409E) = 1;
    *(s8 *)(v0 + 0x26) = 1;
    *(s8 *)(v0 + 0x40F4) = 1;
    *(s8 *)(v0 + 0x7C) = 1;
    *(s8 *)(v0 + 0x40A0) = 0;
    *(s8 *)(v0 + 0x28) = 0;
    *(s32 *)(v0 + 0x4084) = 0x801A8000;
    *(s32 *)(nv + 0xFC) = 0x801D0000;
    D_800EC360[0x19] = 0;
    D_800EC360[0x1A] = 0;
    D_800EC360[0x1B] = 0;
    s2[0x19] = 0;
    s2[0x1A] = 0;
    s2[0x1B] = 0;
    SetDispMask(1);
    return 0;
}

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136528);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_801366EC);

typedef struct { s16 x, y, w, h; } Rect_385;
extern Rect_385 D_80136918;
extern struct S_g_Game { u8 pad_0[0x8120]; s16 f_8120; } g_Game;
void ClearImage(Rect_385 *, s32, s32, s32);
void DrawSync(s32);
s32 Minigame_Run(s32);

s32 func_80136894(void)
{
  Rect_385 r = D_80136918;
  ClearImage(&r, 0, 0, 0);
  DrawSync(0);
  Minigame_Run(1);
  g_Game.f_8120 = 3;
  return 0;
}

/* the first rect of this file's rodata, which the split leaves at the end of the text */
__asm__(".section .text\n.globl D_80136910\nD_80136910:\n\t.word 0");

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136914);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136AEC);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136D18);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136E60);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136FA0);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80137014);
