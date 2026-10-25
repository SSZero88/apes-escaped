#include "common.h"
#include "m2c_macros.h"

extern M2C_UNK D_80138338;

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_80136000);

INCLUDE_ASM("asm/ovl/430/nonmatchings/430", func_8013626C);

typedef struct { s16 x, y, w, h; } RECT_80136494;
void LoadImage(RECT_80136494 *, u32 *);

void func_80136494(s32 n, s32 row) {
    u32 *p = (u32 *)0x80155000;
    RECT_80136494 r;

    for (; n != 0; n--) {
        p += 2;
        p += *p >> 2;
        p += *p >> 2;
    }
    p += 2;
    r = *(RECT_80136494 *)(p + 1);
    r.x = 0x1C0;
    r.y = row + 0xFE;
    LoadImage(&r, p + 3);
    p += *p >> 2;
    r = *(RECT_80136494 *)(p + 1);
    r.x = row * 128 + 0x1C0;
    r.y = 0;
    LoadImage(&r, p + 3);
}

typedef struct { s16 x, y, w, h; } Rect_430;
extern Rect_430 D_80137838;
extern struct { u8 f_0; u8 pad1; s16 f_2; s32 f_4, f_8, f_C, f_10, f_14, f_18, f_1C, f_20; } D_80138310;
void ClearImage(Rect_430 *, s32, s32, s32);
void DrawSync(s32);

void func_80136590(void) {
    Rect_430 r;

    D_80138310.f_0 = 2;
    D_80138310.f_4 = 0;
    D_80138310.f_8 = 0x3C;
    D_80138310.f_C = 0;
    D_80138310.f_2 = 0;
    D_80138310.f_10 = 0;
    D_80138310.f_14 = 0;
    D_80138310.f_18 = 0;
    D_80138310.f_1C = 0;
    D_80138310.f_20 = 0;
    r = D_80137838;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
}

extern GameDraw g_Game;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80136624;
typedef struct { u32 tag; u32 tpage; u32 code; u32 xy; u32 uvclut; u32 wh; } Sprt_80136624;

void func_80136624(s32 y) {
    Sprt_80136624 *p = (Sprt_80136624 *)G_DRAW.prim;
    u32 *ot = &G_DRAW.db[G_DRAW.cur].ot[2];

    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000207;
    p->code = 0x65000000;
    p->xy = (y << 16) | 0x20;
    p->wh = 0x180100;
    p->uvclut = 0x3E9CC800;
    ((Tag_80136624 *)p)->addr = ((Tag_80136624 *)ot)->addr;
    ((Tag_80136624 *)ot)->addr = (u32)p;
    p++;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000208;
    p->code = 0x65000000;
    p->xy = (y << 16) | 0x120;
    p->wh = 0x180040;
    p->uvclut = 0x3E9CC800;
    ((Tag_80136624 *)p)->addr = ((Tag_80136624 *)ot)->addr;
    ((Tag_80136624 *)ot)->addr = (u32)p;
    p++;
    G_DRAW.prim = (u8 *)p;
}

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
