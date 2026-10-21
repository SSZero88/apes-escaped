#include "common.h"
#include "m2c_macros.h"

extern M2C_UNK D_80138338;

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136000);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_8013626C);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136494);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136590);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136624);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136730);

void func_80136E58(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0x5F;
    var_v0 = &D_80138338;
    do {
        M2C_FIELD(var_v0, s8 *, 4) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0xC));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136E7C);

typedef struct { s16 x, y; s32 z; } Pt_391;
void *func_8008C09C(s32);
s32 rcos(s32);
s32 rsin(s32);
extern Pt_391 *D_80139E28_80138B0C asm("D_801387B8");

void func_80137374(void)
{
  Pt_391 *p;
  s32 r;
  s32 k;
  s32 a;
  s32 a0;
  s32 rad;
  p = (D_80139E28_80138B0C = func_8008C09C(0x600));
  for (a0 = 0, r = 0; r < 12; r++, a0 += 0x80)
  {
    rad = ((r * r) * 300) / 144;
    for (k = 0, a = a0; k < 16; k++)
    {
      p->x = ((rcos(a) * rad) >> 12) + 0xC0;
      p->y = ((rsin(a) * rad) >> 12) + 0x78;
      p->z = 0;
      a += 0x100;
      p++;
    }

  }

}

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_8013748C);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_801376EC);
