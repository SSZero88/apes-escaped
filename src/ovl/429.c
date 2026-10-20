#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136000);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136120);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136160);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136554);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801368E8);

u8 *func_80136A88(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 new_var;
  int new_var2;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  new_var2 = arg1 > 0;
  var_v1 = 0;
  if (new_var2)
  {
    do
    {
      new_var = var_v1;
      var_v0 = new_var < arg1;
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

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136AB8);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136CC4);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80136FF0);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801371C0);

M2C_UNK Cd_ReadFilePart(M2C_UNK, s32, M2C_UNK, s32);
s32 func_801371C0(void *);
extern s16 D_801391B6;
extern s32 D_80139478;

s32 func_80137308(void *obj) {
    D_801391B6 = 4;
    Cd_ReadFilePart(0x54, func_801371C0(obj) * 7, 7, D_80139478);
    return 0;
}

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_8013734C);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137470);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801374DC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801378C4);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137C04);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137D40);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80137EF8);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138428);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_801388A4);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138978);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138ABC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138AEC);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138C44);

INCLUDE_ASM("asm/ovl/429/nonmatchings/429", func_80138D7C);
