#include "common.h"
#include "m2c_macros.h"

extern u8 D_800B3640[];
u8 *Msg_ReadChar(u8 *p, u16 *out);

M2C_UNK Msg_PutChar(u16, M2C_UNK, M2C_UNK);

extern M2C_UNK D_800DF810;

INCLUDE_ASM("asm/nonmatchings/game/8008D9D0", Msg_PutChar);

u8 *Msg_ReadChar(u8 *p, u16 *out) {
    u16 c = *p++;
    if (c == 10) {
        c = *p++ | 0x100;
    } else if (c == 11) {
        c = *p++ | 0x200;
    }
    *out = c;
    return p;
}

void func_8008DDB0(s16 arg0, s16 arg1) {
    M2C_FIELD(&D_800DF810, s16 *, 0) = arg0;
    M2C_FIELD(&D_800DF810, s16 *, 4) = arg0;
    M2C_FIELD(&D_800DF810, s16 *, 2) = arg1;
}

void func_8008DDC8(s32 arg0)
{
  u16 sp10;
  s32 temp_s0;
  temp_s0 = arg0;
  loop_1:
  temp_s0 = Msg_ReadChar(temp_s0, &sp10);

  if (sp10 != 0)
  {
    Msg_PutChar(sp10, 0x1F0, 0);
    temp_s0 = temp_s0;
    goto loop_1;
  }
}

/* Same as Text_GetWidth with the width table D_800B3640 (another font). */
s32 Text_GetWidth2(u8 *s) {
    s32 w = 0;
    while (*s != 0 && *s != 0xD) {
        w += D_800B3640[*s++];
    }
    return w;
}

s32 func_8008DE68(u8 *p, u16 end) {
    s32 sum = 0;
    u16 c;
    while (1) {
        p = Msg_ReadChar(p, &c);
        if (c == end) {
            break;
        }
        sum += D_800B3640[c];
    }
    return sum;
}
