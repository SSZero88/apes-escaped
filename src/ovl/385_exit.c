#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("asm/ovl/385/nonmatchings/385_exit", func_80136940);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385_exit", func_80136AEC);

INCLUDE_ASM("asm/ovl/385/nonmatchings/385_exit", func_80136D18);

typedef struct { s16 x, y, w, h; } Rect_80136E60;
s32 LoadImage(void *rect, u32 *p);
s32 func_800A3710(u8 *);
s32 func_8002F1E0(s32);

void func_80136E60(u8 *s, Rect_80136E60 *r) {
    u32 buf[0x80];
    s32 n;
    s32 x0;
    s32 glyph;
    s32 a, b, z;
    s32 c;
    register u8 *p asm("s1");

    n = func_800A3710(s);
    x0 = r->x;
    for (p = s; p < s + n; p++) {
        if (*p == '\n') {
            r->x = x0;
            r->y += r->h + 3;
            continue;
        }
        if (*p & 0x80) {
            c = *p++;
            a = 7;
            b = 0x1E;
            z = 0;
            glyph = func_8002F1E0(*p | (c << 8));
        }
        __asm__ volatile("" :: "r"(z));
        DrawSync(0);
        func_80136FA0(buf, glyph, a, b);
        LoadImage(r, buf);
        r->x++;
        LoadImage(r, buf);
        { s16 w = r->w; s16 x = r->x; r->x = x + w; }
    }
}

extern u16 D_80137270;

void func_80136FA0(u16 *dst, u8 *src, u32 range, s32 n) {
    s32 i;
    s32 b;
    s32 hi = range & 0xFFFF;
    s32 lo = range >> 16;
    register u16 *c asm("$11");

    i = 0;
    if (n > 0) {
        c = &D_80137270;
        do {
            for (b = hi; b >= lo; b--) {
                *dst++ = ((*src >> b) & 1) ? *c : 0;
            }
            src++;
        } while (++i < n);
    }
}

INCLUDE_ASM("asm/ovl/385/nonmatchings/385_exit", func_80137014);
