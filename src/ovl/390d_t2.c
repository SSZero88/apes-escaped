#include "common.h"
#include "m2c_macros.h"

typedef struct { volatile s32 stat; volatile s32 mask; } Intr_80141B90;
extern s32 D_80142014[];
extern Intr_80141B90 *D_8014200C;
typedef struct L_80141C40 { struct L_80141C40 *next; } L_80141C40;
extern L_80141C40 ***D_80142010;
void func_8002F210(void);
void func_8002F230(void);
void func_8002F260(s32, void *);
void func_8002F270(s32, s32);
void func_80145374(void);
void func_80141C40(s32, L_80141C40 *);

void func_80141B90(void) {
    func_8002F210();
    func_8002F260(2, D_80142014);
    func_80141C40(2, (L_80141C40 *)D_80142014);
    D_8014200C->stat = -2;
    D_8014200C->mask |= 1;
    func_8002F270(3, 0);
    func_8002F230();
}

void func_80141C00(void) {
    func_8002F210();
    func_80145374();
    func_8002F260(2, D_80142014);
    func_8002F230();
}

void func_80141C40(s32 a0, L_80141C40 *a1) {
    L_80141C40 **h = &(*D_80142010)[a0 * 2];
    L_80141C40 *p = *h;
    if (p == 0) {
        *h = a1;
    } else {
        while (p->next != 0) p = p->next;
        p->next = a1;
    }
    a1->next = 0;
}

s32 func_80141C94(void) {
    if ((D_8014200C->mask & 1) == 0 || (D_8014200C->stat & 1) == 0) return 0;
    return 1;
}

s32 func_80141CD4(void) {
    if ((D_8014200C->mask & 0x80) == 0 || (D_8014200C->stat & 0x80) == 0) return 0;
    return 1;
}

typedef struct { volatile s32 stat; volatile s32 mask; } Intr_80141D14;
extern Intr_80141D14 *D_8014200C_80141D14 asm("D_8014200C");
typedef struct { volatile s32 data; volatile s32 stat; volatile s16 mode; volatile s16 ctrl; volatile s16 misc; volatile s16 baud; } Sio_80141D14;
extern Sio_80141D14 *D_80142008_80141D14 asm("D_80142008");
extern s32 D_80142024[];
extern volatile s32 D_801450C8;
extern volatile s32 D_801450CC;
extern s32 D_801450D0;
extern s32 D_801450D8;
extern s32 D_80145270;
extern volatile s32 D_801455C4;
void func_801424E0(s32);
void func_8002F280(s32, void *);
s32 func_80141EBC(void);

s32 func_80141D14(void) {
    if (D_801450CC != 0) {
        if (D_80145270 == 0x11 && ++D_801450D8 < 3) {
            D_801450C8 = 0x11;
            func_801424E0(D_801450D0);
            {
            register s32 n asm("$4") = 1;
            D_801450C8 = 2;
            D_80142008_80141D14->ctrl = 0;
            D_8014200C_80141D14->stat = ~0x80;
            D_8014200C_80141D14->mask &= ~0x80;
            D_801450CC = 0;
            func_8002F260(n, D_80142024);
            }
        } else {
            register s32 n asm("$4") = 1;
            D_801450C8 = 0x11;
            D_801450CC = 0;
            D_8014200C_80141D14->stat = ~0x80;
            D_8014200C_80141D14->mask &= ~0x80;
            D_801450D8 = 0;
            D_80142008_80141D14->ctrl = 0;
            func_8002F260(n, D_80142024);
            {
                register Sio_80141D14 *p asm("$4") = D_80142008_80141D14;

                register s32 k asm("$3");

                D_801455C4 = 0;
                k = 0x40; p->ctrl = k;
                k = 0x88; p->baud = k;
                k = 0xD; p->mode = k;
                p->ctrl = 0;
            }
            __asm__ volatile("");
            return 0;
        }
    }
    if (D_801450C8 & 1) return 0;
    func_8002F260(1, D_80142024);
    func_8002F280(1, D_80142024);
    func_80141EBC();
    D_8014200C_80141D14->stat = ~0x80;
    D_8014200C_80141D14->mask |= 0x80;
    return 0;
}

extern s32 D_801455C8;
extern s32 D_801450D4;
extern volatile u16 *D_80142008_EBC asm("D_80142008");
extern volatile s32 *D_8014200C_EBC asm("D_8014200C");
void func_80145440();
s32 func_80142530();

s32 func_80141EBC(void) {
    s32 r;

    if (D_801455C4) {
        D_801455C8 = 1;
        func_80145440();
        D_801455C8 = 0;
        return 0;
    }
    D_801450CC += 1;
    r = func_80142530();
    if (r != 0) {
        if (r == 1) {
            D_801450C8 = 0x41;
            if (D_801450D4) {
                func_801424E0(D_801450D0);
                D_801450C8 = 2;
                D_801450D4--;
            }
            {
                register s32 n asm("$4") = 1;
                volatile u16 *a = D_80142008_EBC;
                volatile s32 *b = D_8014200C_EBC;
                a[5] = 0;
                b[0] = ~0x80;
                b[1] &= ~0x80;
                D_801450CC = 0;
                func_8002F260(n, D_80142024);
            }
        } else {
            register s32 n asm("$4") = 1;
            {
                volatile u16 *a = D_80142008_EBC;
                volatile s32 *b = D_8014200C_EBC;
                a[5] = 0;
                b[0] = ~0x80;
                b[1] &= ~0x80;
            }
            D_801450C8 = 0x21;
            D_801450CC = 0;
            func_8002F260(n, D_80142024);
        }
    }
    return 0;
}
