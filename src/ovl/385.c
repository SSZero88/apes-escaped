#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136000);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_801362A4);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385", func_80136424);

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
