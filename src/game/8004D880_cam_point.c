#include "common.h"
#include "m2c_macros.h"

extern s32 D_800AF140[];

void CamPoint_RunScript(s32 arg0, s32 arg1)
{
  s32 *temp_a1;
  ((M2C_UNK (*)(s32 *)) (*(&D_800AF140[arg1])))(temp_a1);
  temp_a1 = &D_800AF140[arg1];
}
