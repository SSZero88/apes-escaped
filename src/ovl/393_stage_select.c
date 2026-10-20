#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80136000);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013606C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801375C0);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137714);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013786C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80137950);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801382D8);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_801383EC);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80138468);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80138560);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_80138700);

u8 *func_801387FC(u8 *arg0, s32 arg1)
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
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013882C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013886C);

INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", func_8013893C);
