#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8008DDB0(s16, s16);
M2C_UNK func_8008DDC8(s32);
extern M2C_UNK D_80138CA0;
M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_80138CEC;

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136000);

u8 *func_801361D8(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 var_v1;
  u8 *new_var;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      new_var = var_a0;
      if ((*new_var) == 0)
      {
        var_v1 += 1;
        var_v0 = var_v1 < arg1;
      }
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136208);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80136954);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137214);

void func_80137334(s32 arg0) {
    func_8008DDB0(M2C_FIELD(&D_80138CA0, s16 *, 0), M2C_FIELD(&D_80138CA0, s16 *, 2));
    func_8008DDC8(arg0);
    func_8008DDB0((s16) ((u16) M2C_FIELD(&D_80138CA0, s16 *, 0) + 1), M2C_FIELD(&D_80138CA0, s16 *, 2));
    func_8008DDC8(arg0);
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801373A4);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801374D0);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137CD4);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137D4C);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80137DF0);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801380D8);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801383B8);

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_801383D8);

void func_80138468(void) {
    Cd_PlayXaTrack(D_80138CEC);
}

INCLUDE_ASM("asm/ovl/395/nonmatchings/395", func_80138490);
