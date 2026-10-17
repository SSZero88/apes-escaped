#include "common.h"
#include "m2c_macros.h"

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_8005E008;
typedef struct { P_TAG_8005E008 tag; u8 r0, g0, b0, code; s16 x0, y0; s16 w, h; } TILE_8005E008;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_8005E008;
extern struct S_D_800EC350 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8005E008 db[2]; } g_Game;

void func_8005E000(void) {
}

/* Debug: draws a CPU-load bar (blue, yellow, then red as it grows).
 */
void Debug_DrawCpuMeter(s32 v) {
    TILE_8005E008 *p = (TILE_8005E008 *)g_Game.prim;
    u32 *ot = g_Game.db[g_Game.cur].ot;
    p->tag.len = 3;
    p->code = 0x60;
    p->y0 = 0xE6;
    p->h = 4;
    p->r0 = 0;
    p->g0 = 0;
    p->b0 = 0;
    p->x0 = 0;
    p->w = v;
    if (v < 200) {
        p->b0 = 0xFF;
    } else if (v < 400) {
        p->r0 = 0xFF;
        p->g0 = 0xFF;
    } else {
        p->r0 = 0xFF;
    }
    p->tag.addr = ((P_TAG_8005E008 *)ot)->addr;
    ((P_TAG_8005E008 *)ot)->addr = (u32)p;
    p++;
    g_Game.prim = (u8 *)p;
}
