#include "common.h"
#include "m2c_macros.h"
#include "common.h"

u8 *func_8008C09C(s32 size);
extern char D_800A6340[];
extern char D_800A6350[];
void bios_printf(const char *, ...);
void bios_exit(s32) __attribute__((noreturn));

extern s32 D_800BF790;
extern struct S_D_800BF690 { s32 f_0; } D_800BF690[];


extern s32 D_800DF798;
extern u8 D_800BF798[];
u8 *Mem_AllocFailed(s32 size);

void* func_8008C000(s32 size) {
    return (u8*)&D_800DF798 - ((size + 3) >> 2) * 4;
}

void func_8008C01C(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_800BF690[i].f_0 = 0;
    }
    D_800BF790 = 0;
    D_800DF798 = 0x80102800;
}

void func_8008C058(s32 arg0) {
    D_800DF798 = arg0;
}

void func_8008C064(s32 arg0) {
    s32 *var_v1;
    s32 var_a1;

    var_a1 = 0;
    var_v1 = &D_800BF690[0].f_0;
    do {
        if (*var_v1 == arg0) {
            *var_v1 = 0;
        }
        var_a1 += 1;
        var_v1 = (void *)((u8 *)var_v1 + (4));
    } while (var_a1 < 0x40);
}

u8 *func_8008C09C(s32 size)
{
  s32 n = (size + 0x7FF) / 0x800;
  s32 i;
  s32 run;
  s32 start;
  s32 j;
  s32 k;
  s32 *new_var;
  u8 *p;
  if (n == 0)
  {
    return (void *) 0;
  }
  if ((64 - D_800BF790) < n)
  {
    Mem_AllocFailed(size);
  }
  run = 0;
  for (i = D_800BF790; i < 64; i++)
  {
    if (((u8 * *)&D_800BF690)[i] == ((void *) 0))
    {
      if ((++run) == n)
      {
        j = i;
        k = j - run;
        p = D_800BF798 + ((k + 1) * 0x800);
        for (start = k; (*(new_var = &start)) < j; j--)
        {
          ((u8 * *)&D_800BF690)[j] = p;
        }

        D_800BF790 = 0;
        return p;
      }
    }
    else
    {
      run = 0;
    }
  }

  return Mem_AllocFailed(size);
}

/* Bump allocator in the work area; prints an error and stops when it runs out.
 */
void *Mem_Alloc(s32 size) {
    u8 *cur = D_800DF798;
    if ((u32)(cur + size) <= 0x801027FF) {
        D_800DF798 = cur + (((size + 3) >> 2) << 2);
        return cur;
    }
    return func_8008C09C(size);
}

/* Debug: draws 64 one-pixel bars coloured from a status table.
 */
extern u8 g_Game[];
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_8C214;
typedef struct { u8 r, g, b, cd; } CVec_8C214;
typedef struct { P_TAG_8C214 tag; CVec_8C214 c; s16 x0, y0, x1, y1; } LineF2_8C214;

/* Debug: a strip of 64 one-pixel lines at x 0x118, one per D_800BF690 slot: black when the slot
   is empty, else coloured by its flag bits 0x800 / 0x1000 / 0x2000 (red / green / blue) */
void Debug_DrawMeter(void) {
    s32 i;
    CVec_8C214 c;
    u32 *ot = G_DRAW.db[G_DRAW.cur].ot;
    LineF2_8C214 *p = (LineF2_8C214 *)G_DRAW.prim;

    for (i = 0; i < 64; i++) {
        if (D_800BF690[i].f_0 == 0) {
            c.r = 0;
            c.g = 0;
            c.b = 0;
        } else {
            c.r = (((u32)D_800BF690[i].f_0 & 0x800) >> 4) + 0x40;
            c.g = (((u32)D_800BF690[i].f_0 & 0x1000) >> 5) + 0x40;
            c.b = (((u32)D_800BF690[i].f_0 & 0x2000) >> 6) + 0x40;
        }
    *(u32 *)&p->c = *(u32 *)&c;
        p->x1 = i + 0x118;
        p->x0 = i + 0x118;
        p->y0 = 10;
        p->y1 = 0x1A;
        p->tag.len = 3;
        p->c.cd = 0x40;
        p->tag.addr = ((P_TAG_8C214 *)ot)->addr;
        ((P_TAG_8C214 *)ot)->addr = (u32)p;
        p++;
    }
    G_DRAW.prim = (u8 *)p;
}

/* "Smalloc Error!": prints the requested size and stops.
 */
u8 *Mem_AllocFailed(s32 size) {
    bios_printf(D_800A6340);
    bios_printf(D_800A6350, size, D_800BF790);
    bios_exit(1);
}

INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6340);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6350);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6370);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6380);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6390);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63A0);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63AC);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63B8);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63C4);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63D4);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63E4);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A63F4);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6400);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6410);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6420);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6430);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6440);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6450);
INCLUDE_RODATA("asm/nonmatchings/game/8008C000", D_800A6458);

