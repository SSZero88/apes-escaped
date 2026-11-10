#include "common.h"
#include "common.h"
typedef struct { s16 x, y, w, h; } RECT_800690E8_800690E8;
typedef struct { u8 f_0; u8 f_1; u8 pad2[2]; u16 f_4; u16 f_6; u16 f_8; u16 f_A; u8 f_C; u8 f_D; u8 padE[2]; } E_800690E8_800690E8;
void *Mem_AllocPages(s32);
extern struct S_D_800B98F0 { s32 f_0; E_800690E8_800690E8 *f_4; } Tex_Anims;
void MoveImage(RECT_800690E8_800690E8 *, s32, s32);

typedef struct { s16 x, y, w, h; } RECT_68D10;
void DebugMsg_Queue(char *, s32);
s32 LoadImage2(void *rect, u32 *p);
s32 DrawSync(s32);
void bios_printf(const char *, ...);
void bios_exit(s32) __attribute__((noreturn));
u8 *Image_DecodeNibbleRuns(u8 *src, u32 n);
u8 *Image_DecodeRle4(u8 *src, u32 n);
void Mem_Free(void *);
extern char D_800A5BD0[];
extern char D_800A5BE0[];

void Tex_LoadPack(u32 *p) {
    s32 n = 0;
    u32 id;
    u32 size;

    for (;;) {
        /* asm-opaque 0x10000 keeps the lui ahead of the load (the original's loop-top order) */
        { u32 k; __asm__ volatile("" : "=r"(k) : "0"(0x10000)); id = *p; k |= 0x10;
          if (id == k) goto L1;
          if (id <= k) { if (id == 0x10) goto L0; goto Ld; }
          if (id == 0x20010) goto L1;
          goto Ld; }
        {
        Ld:
            DebugMsg_Queue(D_800A5BD0, n);
            return;
        L0:
            p++;
            n++;
            switch (*p & 0xF) {
            case 2:
                p++;
                LoadImage2(p + 1, p + 3);
                p += *p >> 2;
                DrawSync(0);
                break;
            case 8:
            case 9:
                p++;
                LoadImage2(p + 1, p + 3);
                p += *p >> 2;
                DrawSync(0);
                LoadImage2(p + 1, p + 3);
                p += *p >> 2;
                DrawSync(0);
                break;
            default:
                bios_printf(D_800A5BE0, *p);
                bios_exit(1);
            }
            continue;
        L1:
            p++;
            n++;
            if ((*p & 0xF) == 8) {
                p++;
                LoadImage2(p + 1, p + 3);
                p += *p >> 2;
                DrawSync(0);
                size = ((RECT_68D10 *)(p + 1))->w * ((RECT_68D10 *)(p + 1))->h * 2;
                if (id >> 16 == 1) {
                    id = (u32)Image_DecodeNibbleRuns((u8 *)(p + 3), size);
                } else {
                    id = (u32)Image_DecodeRle4((u8 *)(p + 3), size);
                }
                LoadImage2(p + 1, (u32 *)id);
                Mem_Free((void *)id);
                p += *p >> 2;
                DrawSync(0);
            } else {
                bios_printf(D_800A5BE0, *p);
                bios_exit(1);
            }
            continue;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80068D10_texture", D_800A5BD0);
INCLUDE_RODATA("asm/nonmatchings/game/80068D10_texture", D_800A5BE0);


/* Decode 4-bit pixels from byte runs: each source byte is (colour << 4 | count), giving
   count + 1 pixels of that colour, until n bytes of output are filled. */
u8 *Image_DecodeNibbleRuns(u8 *src, u32 n) {
    u32 j = 0;
    u8 *dst = Mem_AllocPages(n);
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
    dst = Mem_AllocPages(n);
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

void Tex_InitAnims(E_800690E8_800690E8 *e) {
    RECT_800690E8_800690E8 r;

    if (e == NULL) {
        Tex_Anims.f_0 = 0;
        Tex_Anims.f_4 = NULL;
        return;
    }
    Tex_Anims.f_4 = e;
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
        Tex_Anims.f_0++;
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

/* Texture animations of the stage (Tex_Anims list, 16-byte entries up to type 0), as VRAM moves at
   the back of the OT: 2 scrolls a texture by frame * speed / 4 (two moves when it wraps), 1 copies a
   frame every n frames, 3 copies from the current display buffer */
void Tex_UpdateAnims(void) {
    TexAnim_691F8 *e;
    u8 *p;
    u32 *ot;
    s32 frame;
    s32 off;
    Rect_691F8 r;

    if (Tex_Anims.f_0 == 0) {
        return;
    }
    e = (TexAnim_691F8 *)Tex_Anims.f_4;
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
