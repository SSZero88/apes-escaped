#include "common.h"
#include "common.h"
typedef struct { s16 x, y, w, h; } RECT_800690E8_800690E8;
typedef struct { u8 f_0; u8 f_1; u8 pad2[2]; u16 f_4; u16 f_6; u16 f_8; u16 f_A; u8 f_C; u8 f_D; u8 padE[2]; } E_800690E8_800690E8;
void *func_8008C09C(s32);
extern struct S_D_800B98F0 { s32 f_0; E_800690E8_800690E8 *f_4; } D_800B98F0;
void MoveImage(RECT_800690E8_800690E8 *, s32, s32);

INCLUDE_ASM("asm/nonmatchings/game/80068D10", func_80068D10);

INCLUDE_RODATA("asm/nonmatchings/game/80068D10", D_800A5BD0);
INCLUDE_RODATA("asm/nonmatchings/game/80068D10", D_800A5BE0);


/* Decode 4-bit pixels from byte runs: each source byte is (colour << 4 | count), giving
   count + 1 pixels of that colour, until n bytes of output are filled. */
u8 *Image_DecodeNibbleRuns(u8 *src, u32 n) {
    u32 j = 0;
    u8 *dst = func_8008C09C(n);
    u32 k;
    u32 cnt;
    u32 val;
    while ((j >> 1) < n) {
        cnt = *src & 0xF;
        val = *src >> 4;
        for (k = 0; k <= cnt; k++, j++) {
            u8 *d = &dst[j >> 1];
            u32 b = *d;
            if (j & 1) {
                b &= 0xF0;
                b |= val;
            } else {
                b &= 0xF;
                b |= val << 4;
            }
            *d = b;
        }
        src++;
    }
    return dst;
}

/* Decodes run-length encoded 4-bit pixels: a byte whose two nibbles are equal
 * starts a run (the next byte + 2 is its length); other bytes are two pixels.
 */
u8 *Image_DecodeRle4(u8 *src, u32 n) {
    u32 i;
    u8 *dst;
    u32 j;
    u32 hi, lo;
    u8 *p;
    u32 c;
    i = 0;
    dst = func_8008C09C(n);
    while (i / 2 < n) {
        hi = *src >> 4;
        lo = *src & 0xF;
        if (hi == lo) {
            src++;
            for (j = 0; j < *src + 2; j++) {
                p = dst + i / 2;
                c = *p;
                if (i & 1) {
                    c &= 0xF0;
                    c |= hi;
                } else {
                    c &= 0xF;
                    c |= lo << 4;
                }
                *p = c;
                i++;
            }
            src++;
        } else {
            p = dst + i / 2;
            if (i & 1) {
                c = *p;
                i += 2;
                c &= 0xF0;
                c |= hi;
                *p = c;
                p++;
                c = *p;
                c &= 0xF;
                c |= lo << 4;
                *p = c;
            } else {
                *p = *src;
                i += 2;
            }
            src++;
        }
    }
    return dst;
}

void func_800690E8(E_800690E8_800690E8 *e) {
    RECT_800690E8_800690E8 r;

    if (e == NULL) {
        D_800B98F0.f_0 = 0;
        D_800B98F0.f_4 = NULL;
        return;
    }
    D_800B98F0.f_4 = e;
    while (e->f_0 != 0) {
        switch (e->f_0) {
        case 1:
            if (e->f_1 != 1) {
                break;
            }
        case 2:
            r.x = e->f_4;
            r.y = e->f_6;
            r.w = e->f_C;
            r.h = e->f_D;
            MoveImage(&r, e->f_8, e->f_A);
            break;
        }
        D_800B98F0.f_0++;
        e++;
    }
}

extern u8 g_Game[];
typedef struct { u8 type; u8 off; u8 pad2[2]; u16 dx, dy, sx, sy; u8 w, h; u8 a, b; } TexAnim_691F8;
typedef struct { s16 x, y, w, h; } Rect_691F8;
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_691F8;
void SetDrawMove(void *p, void *rect, s32 x, s32 y);
#define LINK(p) \
    ((P_TAG_691F8 *)(p))->addr = ((P_TAG_691F8 *)ot)->addr; \
    ((P_TAG_691F8 *)ot)->addr = (u32)(p);

/* Texture animations of the stage (D_800B98F0 list, 16-byte entries up to type 0), as VRAM moves at
   the back of the OT: 2 scrolls a texture by frame * speed / 4 (two moves when it wraps), 1 copies a
   frame every n frames, 3 copies from the current display buffer */
void Tex_UpdateAnims(void) {
    TexAnim_691F8 *e;
    u8 *p;
    u32 *ot;
    s32 frame;
    s32 off;
    Rect_691F8 r;

    if (D_800B98F0.f_0 == 0) {
        return;
    }
    e = (TexAnim_691F8 *)D_800B98F0.f_4;
    p = G_DRAW.prim;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    frame = *(s32 *)g_Game;
    for (; e->type != 0; e++) {
        switch (e->type) {
        case 2:
            off = frame * e->b / 4 % e->h;
            if (e->a == 0) {
                off = e->h - off;
            }
            r.x = e->sx;
            r.y = e->sy + off;
            r.w = e->w;
            r.h = e->h - off;
            SetDrawMove(p, &r, e->dx, e->dy);
            LINK(p);
            p += 0x18;
            if (off != 0) {
                r.y = e->sy;
                r.h = off;
                SetDrawMove(p, &r, e->dx, e->dy + e->h - off);
                LINK(p);
                p += 0x18;
            }
            break;
        case 1:
            if (e->off == 0 && (frame + e->a) % e->b == 0) {
                r.x = e->dx;
                r.y = e->dy;
                r.w = e->w;
                r.h = e->h;
                SetDrawMove(p, &r, e->sx, e->sy);
                LINK(p);
                p += 0x18;
            }
            break;
        case 3:
            off = (G_DRAW.cur != 0) << 8;
            r.x = e->dx;
            r.y = e->dy + off;
            r.w = e->w;
            r.h = e->h;
            SetDrawMove(p, &r, e->sx, e->sy);
            LINK(p);
            p += 0x18;
            break;
        }
    }
    G_DRAW.prim = p;
}
