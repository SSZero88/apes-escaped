#include "common.h"
#include "m2c_macros.h"

s32 Floor_GetHeight(s32, s32, s32);

extern struct S_D_800B4D30 { s32 f_0; void * f_4; } D_800B4D30;
extern struct S_D_800EBFA0 { u16 w; u16 h; u8 pad4[4]; u32 *cells; } D_800EBFA0;
void *Mem_Alloc(s32 size);

void Zone_SetTable(s32 *arg0)
{
  void *new_var;
  s32 new_var2;
  new_var = (void *) 0;
  if (arg0 == new_var)
  {
    D_800B4D30.f_0 = 0;
    return;
  }
  new_var = arg0;
  new_var2 = (s32) (*arg0);
  D_800B4D30.f_4 = (void *) (new_var + 4);
  D_800B4D30.f_0 = new_var2;
}

s16 func_800433B0(s32 a0, s32 a1, s32 a2, s16 *out)
{
  u8 *scratch = (u8 *) 0x1F8003F0;
  s32 r = Floor_GetHeight(a0, a1, a2);
  char new_var;
  out[new_var = 1] = *((s16 *) (scratch + 0xE));
  out[0] = *((s16 *) (scratch + 0xC));
  return r;
}

INCLUDE_ASM("asm/nonmatchings/game/80043380_zone", Floor_GetHeight);

/* Builds a half-resolution byte map of the cell grid D_800EBFA0 (w x h cells of u32 flags):
 * each output byte covers a 2x2 block of cells and is 0xFF when none of the four has bit 0
 * set, else 0. The map is allocated with Mem_Alloc and returned. */
u8 *Grid_BuildHalfResMap(void) {
    u8 *out = Mem_Alloc((D_800EBFA0.w >> 1) * (D_800EBFA0.h >> 1));
    s32 y, x;
    for (y = 0; y < D_800EBFA0.h >> 1; y++) {
        for (x = 0; x < D_800EBFA0.w >> 1; x++) {
            s32 w = D_800EBFA0.w;
            s32 w2 = w * 2;
            if (!(D_800EBFA0.cells[x * 2 + y * w2] & 1) && !(D_800EBFA0.cells[x * 2 + y * w2 + 1] & 1) &&
                !(D_800EBFA0.cells[x * 2 + (y * 2 + 1) * w] & 1) && !(D_800EBFA0.cells[x * 2 + (y * 2 + 1) * w + 1] & 1)) {
                out[y * D_800EBFA0.w / 2 + x] = 0xFF;
            } else {
                out[y * D_800EBFA0.w / 2 + x] = 0;
            }
        }
    }
    return out;
}

INCLUDE_ASM("asm/nonmatchings/game/80043380_zone", func_80043A8C);

INCLUDE_ASM("asm/nonmatchings/game/80043380_zone", func_80044EF4);

INCLUDE_ASM("asm/nonmatchings/game/80043380_zone", func_80045BE4);

/* Zone lookup by position (has an original bug on the y axis).
 */
/* An axis-aligned box: centre, half-extents and the flags it contributes. */
typedef struct { s16 x, y, z, hx, hy, hz; u16 flags; s16 pad; } Zone;

/* OR together the flags of every zone box containing (x, y, z). With no hit, returns
   0xFFFF if `def` is set, else 0x8000. Note the original bug: a negative dy is replaced
   by -dx, not -dy. */
s32 Zone_FindAt(s32 x, s32 y, s32 z, s32 def) {
    s32 i;
    s32 r = 0;
    s32 n = D_800B4D30.f_0;
    Zone *p = D_800B4D30.f_4;
    for (i = 0; i < n; p++, i++) {
        s32 dx = p->x - x;
        s32 dy = p->y - y;
        s32 dz = p->z - z;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dx;
        if (dz < 0) dz = -dz;
        if (dx < p->hx && dy < p->hy && dz < p->hz) {
            r |= p->flags;
        }
    }
    if (r == 0) {
        if (!def) r = 0x8000;
        else r = 0xFFFF;
    }
    return r;
}
