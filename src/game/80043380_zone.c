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

typedef struct { u32 sxy; s16 z; s16 pad; } V_80045BE4;
typedef struct { u32 color[0x80]; V_80045BE4 v[4]; u8 pad220[0x88]; s32 nc0; s32 nc1; s32 otz; u8 idx[4]; } Scr_80045BE4;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80045BE4;
typedef struct { Tag_80045BE4 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } G4_80045BE4;
typedef struct { u8 pad0[4]; G4_80045BE4 *prim; u32 *ot; s32 cur; struct { u8 env[0x70]; Tag_80045BE4 ot[0x1000]; u32 hud[2]; } db[2]; } Draw_80045BE4;
typedef struct { u8 pad0[0x24]; s32 fogScale; s32 fogNear; } Fog_80045BE4;
extern Draw_80045BE4 g_Game_80045BE4 asm("g_Game");
extern Fog_80045BE4 D_800EBFA0_80045BE4 asm("D_800EBFA0");
#define S_5BE4 S
#define MAX_5BE4(a, b) ((a) > (b) ? (a) : (b))

void func_80045BE4(void) {
    s32 t;
    Scr_80045BE4 *S = (Scr_80045BE4 *)0x1F800000;
    __asm__ volatile("mtc2 %0, $12; nop; mtc2 %2, $14; nop; mtc2 %1, $13" : : "r"(S_5BE4->v[0].sxy), "r"(S_5BE4->v[1].sxy), "r"(S_5BE4->v[2].sxy));
    __asm__ volatile("nop; nop; nclip");
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&((Scr_80045BE4 *)0x1F800000)->nc0) : "memory");
    __asm__ volatile("mtc2 %0, $12" : : "r"(S_5BE4->v[3].sxy));
    __asm__ volatile("nop; nop; nclip");
    __asm__ volatile("swc2 $24, 0(%0)" : : "r"(&((Scr_80045BE4 *)0x1F800000)->nc1) : "memory");
    switch (((S_5BE4->nc0 >> 31) & 2) | (S_5BE4->nc1 > 0)) {
    case 0:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[0].z, S_5BE4->v[1].z);
        S_5BE4->otz = MAX_5BE4(S_5BE4->otz, S_5BE4->v[2].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[3].z ? S_5BE4->otz >> 2 : S_5BE4->v[3].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[0].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[2].sxy;
        g_Game_80045BE4.prim->xy3 = S_5BE4->v[3].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = t;
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[0]]), "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]));
        __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpct" : : "r"(t));
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        __asm__ volatile("lwc2 $6, 0(%0); nop; nop; dpcs" : : "r"(&S_5BE4->color[S_5BE4->idx[3]]));
        __asm__ volatile("swc2 $22, 0(%0)" : : "r"(&g_Game_80045BE4.prim->c3) : "memory");
        g_Game_80045BE4.prim->tag.len = 8;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x38;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x24);
        return;
    case 1:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[0].z, S_5BE4->v[1].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[2].z ? S_5BE4->otz >> 2 : S_5BE4->v[2].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[0].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[2].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = t;
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[0]]), "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]));
        __asm__ volatile("nop; mtc2 %0, $8; nop; nop; dpct" : : "r"(t));
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        g_Game_80045BE4.prim->tag.len = 6;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x30;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x1C);
        return;
    case 2:
        S_5BE4->otz = MAX_5BE4(S_5BE4->v[1].z, S_5BE4->v[2].z);
        S_5BE4->otz = S_5BE4->otz > S_5BE4->v[3].z ? S_5BE4->otz >> 2 : S_5BE4->v[3].z >> 2;
        g_Game_80045BE4.prim->xy0 = S_5BE4->v[1].sxy;
        g_Game_80045BE4.prim->xy1 = S_5BE4->v[2].sxy;
        g_Game_80045BE4.prim->xy2 = S_5BE4->v[3].sxy;
        t = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0xFFF ? 0xFFF : S_5BE4->otz); S_5BE4->otz = t;
        { __asm__ volatile("lwl $5, 2(%0); lw $2, %1; nop; sll $2, $2, 8; swl $2, 2(%0); lw $2, %1; nop; swl $5, 2($2)" : : "r"(&g_Game_80045BE4.db[g_Game_80045BE4.cur].ot[t]), "m"(g_Game_80045BE4.prim) : "$2", "$5", "memory"); }
        __asm__ volatile("lwc2 $20, 0(%0); lwc2 $21, 0(%1); lwc2 $22, 0(%2); lwc2 $6, 0(%2)" : : "r"(&S_5BE4->color[S_5BE4->idx[1]]), "r"(&S_5BE4->color[S_5BE4->idx[2]]), "r"(&S_5BE4->color[S_5BE4->idx[3]]));
        S_5BE4->otz = ((S_5BE4->otz - D_800EBFA0_80045BE4.fogNear) * D_800EBFA0_80045BE4.fogScale) >> 12;
        { s32 f = S_5BE4->otz < 0 ? 0 : (S_5BE4->otz > 0x1000 ? 0x1000 : S_5BE4->otz); S_5BE4->otz = f;
        __asm__ volatile("mtc2 %0, $8; nop; nop; dpct" : : "r"(f)); }
        __asm__ volatile("swc2 $20, 0(%0); swc2 $21, 0(%1); swc2 $22, 0(%2)" : : "r"(&g_Game_80045BE4.prim->c0), "r"(&g_Game_80045BE4.prim->c1), "r"(&g_Game_80045BE4.prim->c2) : "memory");
        g_Game_80045BE4.prim->tag.len = 6;
        ((u8 *)g_Game_80045BE4.prim)[7] = 0x30;
        g_Game_80045BE4.prim = (G4_80045BE4 *)((u8 *)g_Game_80045BE4.prim + 0x1C);
        return;
    }
}

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
