#include "common.h"

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_sio", func_801421D4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_sio", func_8014236C);
