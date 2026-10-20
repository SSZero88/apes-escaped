#include "common.h"
#include "m2c_macros.h"

M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_8013705C;

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136000);

u8 *func_801361D8(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      var_v0 = var_v1 < arg1;
      if ((*var_a0) == 0)
      {
        var_v1 += 1;
      }
      var_a0 += 1;
      var_v0 = var_v1 < arg1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136208);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136724);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136780);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_801368CC);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136AA0);

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136C04);

void func_80136C6C(void) {
    Cd_PlayXaTrack(D_8013705C);
}

INCLUDE_ASM("asm/ovl/394/nonmatchings/394", func_80136C94);
