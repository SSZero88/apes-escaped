#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/387/nonmatchings/387_sound_test", func_80136000);

extern s32 D_80136B4C;
s32 func_80136244(void);
void func_80136698(void);
void func_8013684C(void);

s32 func_801361BC(void)
{
  int new_var;
  switch (D_80136B4C)
  {
    case 0:
      new_var = func_80136244() < 0;
      if (new_var)
    {
      new_var = 1;
      return -new_var;
    }
      return 0;

    case 1:
      func_80136698();
      return 0;

    case 2:
      func_8013684C();
      return 0;

  }

  return 0;
}

INCLUDE_ASM("asm/ovl/387/nonmatchings/387_sound_test", func_80136244);

INCLUDE_ASM("asm/ovl/387/nonmatchings/387_sound_test", func_80136698);

INCLUDE_ASM("asm/ovl/387/nonmatchings/387_sound_test", func_8013684C);
