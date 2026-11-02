#include "common.h"
#include "m2c_macros.h"

typedef struct { volatile u8 data; u8 pad[3]; volatile u16 stat; u16 pad2; volatile u16 mode; volatile u16 ctrl; volatile u16 misc; volatile u16 baud; } Sio_80142040;
extern Sio_80142040 *D_801424C0;
extern volatile s32 *D_801424C4;
extern u32 D_801424D4;
extern u32 D_801424D8;
void func_80142114(s32);

s32 func_80142040(s32 a0) {
    D_801424C0->ctrl = 0;
    func_80142114(0x91);
    D_801424C0->ctrl = a0 ? 0x3003 : 0x1003;
    if (D_801424C0->stat & 0x200) {
        D_801424C0->ctrl |= 0x10;
        if (D_801424C0->stat & 0x200) {
            D_801424C0->data = 1;
            while (!(D_801424C0->stat & 2)) {
            }
            D_801424C0->data;
            return 0;
        }
        *D_801424C4 = ~0x80;
    }
    return 1;
}

void func_80142114(s32 a0) {
    D_801424D4 = *(volatile u16 *)0x1F801120;
    D_801424D8 = a0;
}

s32 func_80142134(void) {
    u32 t = *(volatile u16 *)0x1F801120;
    if (t < D_801424D4) {
        if (*(volatile u16 *)0x1F801128 != 0) {
            t += *(volatile u16 *)0x1F801128;
        } else {
            t += 0x10000;
        }
    }
    if (*(volatile u16 *)0x1F801124 & 0x200) {
        return (t - D_801424D4) >= D_801424D8;
    }
    return ((t - D_801424D4) >> 3) >= D_801424D8;
}

extern s32 D_801424D0;
static inline s32 Timeout_801421D4(void) { u32 t = *(volatile u16 *)0x1F801120; if (t < D_801424D4) { if (*(volatile u16 *)0x1F801128 != 0) { t += *(volatile u16 *)0x1F801128; } else { t += 0x10000; } } if (*(volatile u16 *)0x1F801124 & 0x200) { return (t - D_801424D4) >= D_801424D8; } return ((t - D_801424D4) >> 3) >= D_801424D8; }

s32 func_801421D4(s32 a0) {
    s32 r;

    D_801424D0 = D_801424C0->data;
    if (a0 < 0) {
        while (!(D_801424C0->stat & 1)) {
        }
        while (!Timeout_801421D4()) {
        }
        D_801424C0->data = ~a0;
    } else {
        D_801424C0->data = a0;
        {
            u32 t = *(volatile u16 *)0x1F801120;
            s32 st;
            {
                volatile s32 *q = D_801424C4;
                Sio_80142040 *p = D_801424C0;

                *q = ~0x80;
                st = p->stat;
            }
            D_801424D8 = 0x3C;
            D_801424D4 = t;
            if (st & 0x80) {
                do {
                    if (func_80142134()) {
                        r = 0;
                        goto out;
                    }
                } while (D_801424C0->stat & 0x80);
            }
        }
        D_801424C0->ctrl |= 0x10;
        r = 1;
    out:
        if (r == 0) return -0x300 - D_801424D0;
    }
    return D_801424D0;
}

extern s32 D_80145270;
extern volatile s32 D_801450C8;
extern s32 D_801450DC;
extern u8 D_801451D1;

s32 func_8014236C(s32 a0, s32 *a1, s32 *a2) {
    if (D_80145270 == 0 || D_801450C8 == 1) {
        if (a1) *a1 = 0;
        if (a2) *a2 = 0;
        return -1;
    }
    if (a0 == 0) {
        while (D_801450C8 < 5) {
        }
    }
    *a1 = D_80145270;
    if (a2) {
        switch (D_801450C8) {
        case 2:
        case 4:
            *a2 = 0;
            return 0;
        case 0x11:
            if (D_801450DC == 1) { *a2 = 1; } else { *a2 = 2; }
            break;
        case 0x21:
            *a2 = 2;
            break;
        default:
            if (D_801451D1 == 8) { *a2 = 3; } else { *a2 = 0; }
            break;
        }
    } else {
        if (D_801450C8 == 2) return 0;
        if (D_801450C8 == 4) return 0;
    }
    D_80145270 = 0;
    return 1;
}
__asm__(".section .text\n\t.align 4");
