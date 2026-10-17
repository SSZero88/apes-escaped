#include "common.h"
#include "m2c_macros.h"

extern struct { u8 pad0[0x816A]; s16 unk816A; } g_Game;

typedef struct { u8 unk0; u8 unk1; } S_U8x2;
S_U8x2 *func_800962E8(void);

void SpecterCoin_ClearAll(void) {
    S_U8x2 *p = func_800962E8();
    s32 i;
    for (i = 0; i < 128; i++) {
        p[i].unk0 = 0xFF;
        p[i].unk1 = 0;
    }
}

s32 SpecterCoin_IsCollected(u16 a) {
    S_U8x2 *p = func_800962E8();
    s32 i;
    for (i = 0; i < 128; i++) {
        if (p[i].unk0 == 0xFF) {
            break;
        }
        if (p[i].unk0 == a) {
            return 1;
        }
    }
    return 0;
}

void SpecterCoin_Add(s32 id)
{
  S_U8x2 *p = func_800962E8();
  s32 i;
  if (g_Game.unk816A >= 0x7F)
  {
 do { return; } while (0);
  }
  if (SpecterCoin_IsCollected(id) != 0)
  {
    return;
  }
  for (i = 0; i < 0x7F; i++)
  {
    u8 v = p[i].unk0;
 do { if (1) { if (v == 0xFF) { p[i].unk0 = id; p[i].unk1 = 1; p[i + 1].unk0 = v; return; } } } while (0);
  }

}

s32 SpecterCoin_Count(void) {
    S_U8x2 *p = func_800962E8();
    s32 n = 0;
    s32 i;
    for (i = 0; i < 128; i++) {
        if (p[i].unk0 == 0xFF) {
            break;
        }
        n++;
    }
    return n;
}
