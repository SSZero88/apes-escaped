#include "common.h"

/* forward declarations: command callbacks referenced before their definitions */
s32 func_80142B50(s32 a0);
s32 func_80142D98(s32 a0);
s32 func_801431DC(void);
s32 func_8014358C(void);
s32 func_80143B38(void);
s32 func_80143CA4(s32 a0);
s32 func_801445CC(s32 a0);
s32 func_80144710(s32 a0);
s32 func_80144AC0(u8 a0);
s32 func_80144EC0(s32 a0);
s32 func_801432B4(s32 a0);
s32 func_80143690(s32 a0);
#include "m2c_macros.h"

extern s32 D_801450C8;
extern volatile s32 D_801450CC;
extern s32 D_801450D0;
extern s32 D_801450DC;
extern s32 D_801450E0;
extern s32 D_801450F8;
extern s32 D_801450FC;
extern u8 *D_80145100;
extern s32 D_80145104;
extern s32 *D_80145108;
extern s32 *D_8014510C;
extern s32 D_80145110;
extern s32 D_80145114;
extern s32 D_80145118;
extern s32 D_8014511C;
extern void *D_80145120;
extern void *D_80145124;
extern s32 D_80145270;
void func_80145280(s32, u8 *, s32, s32 *);
s32 func_80142808(void);
s32 func_8014284C(s32);
s32 func_801429B4(void);
s32 func_80142A68(s32);

inline s32 func_801424E0(s32 a0) {
    if (!(D_801450C8 & 1)) return 0;
    D_801450DC = 0;
    D_801450E0 = 0;
    D_8014511C = 0;
    D_801450CC = 0;
    D_801450D0 = a0;
    return 1;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142530);

s32 func_8014275C(s32 a0, s32 a1) {
    if (!func_801424E0(a0)) return 0;
    D_80145110 = -1;
    D_80145270 = 1;
    D_80145120 = func_80142808;
    D_80145124 = func_8014284C;
    D_80145108 = (s32 *)a1;
    D_801450C8 = 2;
    return 1;
}

s32 func_80142808(void) {
    register s32 r asm("$2");

    switch (D_801450CC) {
    case 2:
        r = 0x59;
        break;
    case 4:
    case 5:
        __asm__("" : "=r"(r) : "0"(0xFF));
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_8014284C);

s32 func_801428E0(s32 a0, s32 a1, s32 a2) {
    if (a1 >= 0) {
        if (a1 >= 16) return 0;
        D_80145110 = a1;
    } else {
        D_80145110 = -2;
    }
    if (!func_801424E0(a0)) return 0;
    D_80145100 = (u8 *)&D_80145118;
    D_80145120 = func_801429B4;
    D_80145118 = a2;
    D_80145270 = 2;
    D_80145124 = func_80142A68;
    D_801450C8 = 2;
    return 1;
}

s32 func_801429B4(void) {
    switch (D_801450CC) {
    case 2:
        return 0x59;
    case 4:
        return ((u8 *)&D_80145110)[1];
    case 5:
        return ((u8 *)&D_80145110)[0];
    }
    if (D_801450CC < 6) return 0;
    if (D_801450CC >= 10) return 0;
    return D_80145100[D_801450CC - 6];
}

s32 func_80142A68(s32 a0) {
    if (D_801450E0 == 3) D_8014511C = a0 & 0xFF;
    return 0;
}

s32 func_80142B30(void);

s32 func_80142A90(s32 a0, s32 a1) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 3;
        D_80145120 = func_80142B30;
        D_80145124 = func_80142B50;
        D_80145100 = (u8 *)a1;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_80142B30(void) {
    if (D_801450CC == 2) {
        __asm__("");
        return 0x5B;
    }
    return 0;
}

s32 func_80142B50(s32 a0) {
    register s32 r asm("$2");
    s32 s = D_801450E0;
    if (s == 5) {
        D_8014511C = 8;
        __asm__("" : "=r"(r) : "0"(0));
        return r;
    }
    if ((u32)(s - 6) < 4) {
        D_80145100[9 - s] = a0;
    } else if ((u32)(s - 10) < 3) {
        D_80145100[0x11 - s] = a0;
    } else if (s == 13) {
        D_80145100[4] = a0 - 1;
    } else {
        return 0;
    }
    return 0;
}

s32 func_80142CF8(void);

s32 func_80142BE4(s32 a0, s32 a1, s32 a2, s32 a3) {
    register s32 r asm("$2");

    if (func_80144F80(0, a2) && func_80144F80(0, a2 + a3 - 1) && func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 4;
        D_80145120 = func_80142CF8;
        D_80145124 = func_80142D98;
        D_80145100 = (u8 *)a1;
        D_80145110 = a2;
        D_80145114 = a3;
        D_801450C8 = 2;
        __asm__ volatile("" : : "r"(a3));
    } else {
        r = 0;
    }
    return r;
}

s32 func_80142CF8(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5B;
    case 3:
        return 1;
    case 5:
        return ((u8 *)&D_80145110)[0];
    case 6:
        return ((u8 *)&D_80145110)[1];
    case 7:
        return ((u8 *)&D_80145110)[2];
    case 8:
        return ((u8 *)&D_80145110)[3];
    case 9:
        return D_80145114;
    }
    return 0;
}

s32 func_80142D98(s32 a0) {
    s32 s = D_801450E0;
    if (s == 9) {
        D_8014511C = D_80145114 + 1;
    } else if (s == 10) {
        if (D_8014511C >= 3) {
            s32 t;
            func_80145280(0, D_80145100, D_8014511C - 2, &D_80145104);
            D_801450E0 += D_8014511C - 2;
            D_801450DC += D_8014511C - 2;
            D_8014511C = 2;
        }
    } else if (s >= 11) {
        D_80145100[s - 11] = a0;
    }
    return 0;
}

s32 func_80142F90(void);
s32 func_80143054(void);

s32 func_80142E7C(s32 a0, s32 a1, s32 a2, s32 a3) {
    register s32 r asm("$2");

    if (func_80144F80(1, a2) && func_80144F80(1, a2 + a3 - 1) && func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 5;
        D_80145120 = func_80142F90;
        D_80145124 = func_80143054;
        D_80145100 = (u8 *)a1;
        D_80145110 = a2;
        D_80145114 = a3;
        D_801450C8 = 2;
        __asm__ volatile("" : : "r"(a3));
    } else {
        r = 0;
    }
    return r;
}

s32 func_80142F90(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5C;
    case 3:
        return 1;
    case 5:
        return ((u8 *)&D_80145110)[0];
    case 6:
        return ((u8 *)&D_80145110)[1];
    case 7:
        return ((u8 *)&D_80145110)[2];
    case 8:
        return ((u8 *)&D_80145110)[3];
    case 9:
        return D_80145114;
    case 4:
    case 10:
        break;
    default:
        return D_80145100[D_801450CC - 11];
    }
    return 0;
}

s32 func_80143054(void) {
    s32 s = D_801450E0;
    if (s == 9) {
        D_8014511C = D_80145114 + 1;
    } else if (s == 10) {
        if (D_8014511C >= 3) {
            func_80145280(1, D_80145100 + 1, D_8014511C - 2, &D_80145104);
            D_801450E0 += D_8014511C - 2;
            D_801450DC += D_8014511C - 2;
            D_8014511C = 2;
        }
    }
    return 0;
}

s32 func_8014311C(s32 a0, s32 a1, s32 a2, s32 a3) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 0xE;
        D_80145120 = func_801431DC;
        D_80145124 = func_801432B4;
        D_80145110 = a1;
        D_80145100 = (u8 *)a2;
        D_80145108 = (s32 *)a3;
        D_80145114 = 0;
        D_80145118 = 0;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_801431DC(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5B;
    case 3:
        return D_80145110;
    case 5:
        return *D_80145100;
    }
    if (D_801450CC < 5) return 0;
    if (D_80145118 != 0) return 0;
    if (D_801450CC >= D_80145114 + 5) return 0;
    return D_80145100[D_801450CC - 5];
}

typedef struct { volatile u8 data; u8 pad[3]; volatile u16 stat; } Sio_801432B4;
extern Sio_801432B4 *D_801450C0;
extern volatile s32 *D_801450C4;
extern u8 D_80145130[];
extern u8 D_801451D0[];
void func_80142114(s32);
s32 func_80142134(void);
s32 func_801421D4();

s32 func_801432B4(s32 a0) {
    s32 s = D_801450E0;
    u8 c;
    register s32 b asm("$3") = a0;

    if (s == 4) {
        register s32 t asm("$2") = (u8)b;
        D_80145114 = t;
    }
    if (s < 4) return 0;
    if (s == D_80145114 + 4) {
        while (!(D_801450C0->stat & 2)) {
        }
        {
            register s32 *p asm("$6") = &D_801450E0;
            s32 i = *p;
            register s32 c1 asm("$2");

            D_80145118 = 1;
            D_80145100 = (u8 *)D_80145108;
            c1 = D_801450C0->data;
            D_801451D0[i] = c1;
            i++;
            __asm__("" : "=r"(c1) : "0"(c1));
            c = c1;
            D_8014511C = c;
            *p = i;
        }
        if (c == 0) return 0;
        D_801450CC += 1;
        func_80142114(0x1AE);
        while (!(*D_801450C4 & 0x80)) {
            if (func_80142134()) return -1;
        }
        {
            register s32 c2 asm("$2") = ((s32 (*)(void))D_80145120)();
            register s32 *p asm("$5") = &D_801450DC;
            s32 i = *p;

            D_80145130[i] = c2;
            *p = i + 1;
            c = c2;
        }
        if (func_801421D4(c) < 0) {
            __asm__("");
            return -2;
        }
        return 0;
    } else if (s == D_80145114 + 5) {
        if (D_8014511C >= 3) {
            func_80145280(0, D_80145100, D_8014511C - 2, &D_80145104);
            D_801450E0 += D_8014511C - 2;
            D_801450DC += D_8014511C - 2;
            D_8014511C = 2;
        }
        return 0;
    } else if (s > D_80145114 + 5) {
        D_80145100[s - D_80145114 - 6] = a0;
    }
    return 0;
}

s32 func_801434CC(s32 a0, s32 a1, s32 a2, s32 a3) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 0xF;
        D_80145120 = func_8014358C;
        D_80145124 = func_80143690;
        D_80145110 = a1;
        D_80145100 = (u8 *)a2;
        D_80145108 = (s32 *)a3;
        D_80145114 = 0;
        D_80145118 = 0;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_8014358C(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5C;
    case 3:
        return D_80145110;
    case 5:
        return *D_80145100;
    }
    if (D_801450CC < 5) return 0;
    if (D_80145118 == 0) {
        if (D_801450CC >= D_80145114 + 5) return 0;
        return D_80145100[D_801450CC - 5];
    }
    return D_80145100[D_801450CC - D_80145114 - 6];
}

typedef struct { volatile u8 data; u8 pad[3]; volatile u16 stat; } Sio_80143690;
extern Sio_80143690 *D_801450C0_80143690 asm("D_801450C0");
extern volatile s32 *D_801450C4_80143690 asm("D_801450C4");
extern u8 D_801451D0_80143690[] asm("D_801451D0");
extern u8 D_80145130_80143690[] asm("D_80145130");

s32 func_80143690(s32 a0) {
    s32 e = D_801450E0;
    s32 n;

    if (e == 4) {
        D_80145114 = a0 & 0xFF;
    }
    if (e < 4) return 0;
    n = D_80145114;
    if (e == n + 4) {
        u8 c;
        s32 v;
        while (!(D_801450C0_80143690->stat & 2)) {
        }
        {
            s32 one = 1;
            s32 *pe = &D_801450E0;
            s32 i = *pe;
            s32 *q = D_80145108;
            Sio_80143690 *p = D_801450C0_80143690;
            __asm__ volatile("" : : "r"(one), "r"(i), "r"(q), "r"(p));
            D_80145118 = one;
            D_80145100 = (u8 *)q;
            c = p->data;
            D_801451D0_80143690[i++] = c;
            D_8014511C = c;
            *pe = i;
        }
        if (c == 0) return 0;
        D_801450CC += 1;
        func_80142114(0x1AE);
        while (!(*D_801450C4_80143690 & 0x80)) {
            if (func_80142134()) return -1;
        }
        v = ((s32 (*)(void))D_80145120)();
        {
            s32 *pd = &D_801450DC;
            s32 i = *pd;
            D_80145130_80143690[i] = v;
            *pd = i + 1;
        }
        if (func_801421D4(v & 0xFF) < 0) {
            __asm__("");
            return -2;
        }
        return 0;
    } else if (e == n + 5) {
        if (D_8014511C >= 3) {
            s32 e2, t;
            func_80145280(1, D_80145100 + 1, D_8014511C - 2, &D_80145104);
            e2 = D_801450E0;
            t = D_8014511C;
            D_8014511C = 2;
            D_801450E0 = e2 + (t - 2);
            D_801450DC += t - 2;
        }
    }
    return 0;
}

extern u8 D_801450F0[];
s32 func_8014358C(void);

s32 func_80143884(s32 a0, u8 *a1) {
    u8 *p;
    u8 t;
    if (!func_801424E0(a0)) return 0;
    p = D_801450F0;
    __asm__("" : "=r"(p) : "0"(p));
    D_80145110 = 0;
    D_80145100 = 0;
    D_80145108 = (s32 *)p;
    D_80145114 = 0;
    D_80145118 = 0;
    p[0] = a1[3];
    p[1] = a1[2];
    p[2] = a1[1];
    p[3] = a1[0];
    p[4] = a1[7];
    p[5] = a1[6];
    p[6] = a1[5];
    t = a1[4];
    D_80145270 = 0x12;
    D_80145120 = func_8014358C;
    D_80145124 = func_80143690;
    D_801450C8 = 2;
    p[7] = t + 1;
    return 1;
}

s32 func_801439A4(s32 a0, s32 a1) {
    register s32 r asm("$2");
    s32 two;

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        two = 2;
        __asm__ volatile("" : : "r"(two));
        D_80145270 = 0x10;
        D_80145120 = func_801431DC;
        D_80145110 = two;
        D_80145100 = 0;
        D_80145108 = (s32 *)a1;
        D_80145114 = 0;
        D_80145118 = 0;
        D_80145124 = func_801432B4;
        D_801450C8 = two;
    } else {
        r = 0;
    }
    return r;
}

extern s32 D_801450D4;
extern s32 D_801450D8;

s32 func_80143A64(s32 a0, s32 a1) {
    if (!func_801424E0(a0)) return 0;
    {
    s32 two = 2;
    __asm__ volatile("" : : "r"(two));
    D_801450D4 = 4;
    D_80145270 = 0x11;
    D_80145120 = func_80143B38;
    D_80145110 = two;
    D_80145100 = 0;
    D_80145108 = (s32 *)a1;
    D_80145114 = 0;
    D_80145118 = 0;
    D_801450D8 = 0;
    D_80145124 = func_80143CA4;
    D_801450C8 = two;
    }
    return 1;
}

s32 func_80143B38(void) {
    if (D_801450D4 == 1) {
        switch (D_801450CC) {
        case 2:
            return 0x5C;
        case 3:
            return D_80145110;
        }
        if (D_801450CC < 5) return 0;
        if (D_80145118 == 0) {
            if (D_801450CC >= D_80145114 + 5) return 0;
            return D_80145100[D_801450CC - 5];
        }
        return D_80145100[D_801450CC - D_80145114 - 6];
    }
    switch (D_801450CC) {
    case 2:
        return 0x59;
    case 3:
        break;
    case 4:
    case 5:
        {
            register s32 r asm("$2") = 0xFF;
            if (D_801450D4 == 4) return r;
        }
        __asm__("");
        return 0;
    case 6:
        return 0x20;
    case 7:
        {
            register s32 r asm("$2") = 1;
            if (D_801450D4 != 0) return r;
        }
        break;
    }
    return 0;
}

typedef struct { volatile u8 data; u8 pad[3]; volatile u16 stat; } Sio_80143CA4;
extern Sio_80143CA4 *D_801450C0_80143CA4 asm("D_801450C0");
extern volatile s32 *D_801450C4_80143CA4 asm("D_801450C4");
extern u8 D_801451D0_80143CA4[] asm("D_801451D0");
extern u8 D_80145130_80143CA4[] asm("D_80145130");
extern u8 D_80145104_80143CA4 asm("D_80145104");

s32 func_80143CA4(s32 a0) {
    s32 e;
    s32 n;
    register s32 d4 asm("$6") = D_801450D4;
    register s32 one asm("$5") = 1;

    if (d4 == one) {
        e = D_801450E0;
        if (e == 4) {
            D_80145114 = a0 & 0xFF;
        } else if (e == 13) {
            if (D_80145104_80143CA4 != 0) {
                D_801450D4 = 0;
            }
        }
        e = D_801450E0;
        if (e < 4) return 0;
        n = D_80145114;
        if (e == n + 4) {
            u8 c;
            s32 v;
            while (!(D_801450C0_80143CA4->stat & 2)) {
            }
            {
                s32 one = 1;
                s32 *pe = &D_801450E0;
                s32 i = *pe;
                s32 *q = D_80145108;
                Sio_80143CA4 *p = D_801450C0_80143CA4;
                __asm__ volatile("" : : "r"(one), "r"(i), "r"(q), "r"(p));
                D_80145118 = one;
                D_80145100 = (u8 *)q;
                c = p->data;
                D_801451D0_80143CA4[i++] = c;
                D_8014511C = c;
                *pe = i;
            }
            D_801450CC += 1;
            func_80142114(0x1AE);
            while (!(*D_801450C4_80143CA4 & 0x80)) {
                if (func_80142134()) return -1;
            }
            v = ((s32 (*)(void))D_80145120)();
            {
                s32 *pd = &D_801450DC;
                s32 i = *pd;
                D_80145130_80143CA4[i] = v;
                *pd = i + 1;
            }
            if (func_801421D4(v & 0xFF) < 0) {
                __asm__("");
                return -2;
            }
            return 0;
        } else if (e == n + 5) {
            if (D_8014511C >= 3) {
                s32 e2, t;
                func_80145280(1, D_80145100 + 1, D_8014511C - 2, &D_80145104);
                e2 = D_801450E0;
                t = D_8014511C;
                D_8014511C = 2;
                D_801450E0 = e2 + (t - 2);
                D_801450DC += t - 2;
            }
        }
        return 0;
    }
    e = D_801450E0;
    if (e == 3) {
        D_8014511C = a0 & 0xFF;
        return 0;
    }
    if (e < 3) return 0;
    if (e < 6) {
        if (d4 == 4 && (a0 & 0xFF) != 0) {
            register s32 two asm("$2") = 2;
            D_80145104_80143CA4 = one;
            D_8014511C = one;
            __asm__ volatile("");
            D_801450D4 = two;
            return 0;
        }
        D_80145104_80143CA4 = 0;
    }
    return 0;
}

s32 func_80144004(void);

s32 func_80143F54(s32 a0, s32 a1, s32 a2) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 6;
        D_80145120 = func_80144004;
        D_80145124 = func_80142A68;
        D_80145110 = a1;
        D_80145114 = a2;
        D_80145118 = 0;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_80144004(void) {
    switch (D_801450CC) {
    case 2:
        __asm__("");
        return 0x5D;
    case 4:
        return D_80145110;
    case 5:
        return D_80145118;
    case 6:
        return D_80145114;
    }
    return 0;
}

s32 func_80144084(s32 a0) {
    if (!func_801424E0(a0)) return 0;
    D_80145118 = 1;
    D_80145270 = 7;
    D_80145120 = func_80144004;
    D_80145124 = func_80142A68;
    D_801450C8 = 2;
    return 1;
}

s32 func_801441E4(void);

s32 func_80144128(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (!func_801424E0(a0)) return 0;
    D_80145110 = a1 != 0;
    D_80145114 = a2 != 0;
    D_80145118 = a3 != 0;
    D_80145270 = 8;
    D_80145120 = func_801441E4;
    D_80145124 = func_80142A68;
    D_801450C8 = 2;
    return 1;
}

s32 func_801441E4(void) {
    switch (D_801450CC) {
    case 2:
        __asm__("");
        return 0x5E;
    case 4:
        return D_80145110;
    case 5:
        return D_80145114;
    case 6:
        return D_80145118;
    }
    return 0;
}

s32 func_80144308(void);

s32 func_80144264(s32 a0, s32 a1) {
    if (!func_801424E0(a0)) return 0;
    D_80145110 = a1 != 0;
    D_80145270 = 0xD;
    D_80145120 = func_80144308;
    D_80145124 = func_80142A68;
    D_801450C8 = 2;
    return 1;
}

s32 func_80144308(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5F;
    case 4:
        return D_80145110;
    }
    return 0;
}

s32 func_80142CF8(void);

s32 func_80144344(s32 a0, u8 *a1) {
    if (!func_801424E0(a0)) return 0;
    D_80145110 = 0x6000300;
    D_80145114 = 4;
    D_80145270 = 0xA;
    D_80145120 = func_80142CF8;
    D_80145124 = func_80142D98;
    D_80145100 = a1;
    D_801450C8 = 2;
    return 1;
}

s32 func_80144400(s32 a0, s32 a1) {
    if (!func_801424E0(a0)) return 0;
    if (a1 != 0) {
        D_80145110 = 0xD800008;
    } else {
        D_80145110 = 0xD800004;
    }
    D_80145100 = (u8 *)&D_80145118;
    *D_80145100 = 2;
    D_80145114 = 1;
    D_80145270 = 9;
    D_80145120 = func_80142F90;
    D_80145124 = func_80143054;
    D_801450C8 = 2;
    return 1;
}

void func_801444D4(s32 a0) {
    func_80144500(a0, &D_801450F8, &D_801450FC);
}

s32 func_801445A8(void);

s32 func_80144500(s32 a0, s32 *a1, s32 *a2) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 0x13;
        D_80145120 = func_801445A8;
        D_80145124 = func_801445CC;
        D_80145108 = a1;
        D_8014510C = a2;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_801445A8(void) {
    register s32 r asm("$2") = 0x58;
    if (D_801450CC != 2) {
        r = 0;
        __asm__("");
    }
    return r;
}

s32 func_801445CC(s32 a0) {
    register s32 r asm("$2");

    switch (D_801450E0) {
    case 3:
        __asm__("");
        D_8014511C = a0 & 0xFF;
        break;
    case 4:
        *D_80145108 = a0 & 0xFF;
        break;
    case 5:
        *D_8014510C = a0 & 0xFF;
        break;
    }
    r = 0;
    __asm__ volatile("" : : "r"(r));
    return r;
}

s32 func_801446EC(void);

s32 func_8014464C(s32 a0, u8 *a1) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 0xC;
        D_80145120 = func_801446EC;
        D_80145124 = func_80144710;
        D_80145100 = a1;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_801446EC(void) {
    register s32 r asm("$2") = 0x5A;
    if (D_801450CC != 2) {
        r = 0;
        __asm__("");
    }
    return r;
}

s32 func_80144710(s32 a0) {
    register s32 r asm("$2");

    switch (D_801450E0) {
    case 3:
        D_8014511C = 0x12;
        break;
    case 4:
        D_80145100[1] = a0;
        break;
    case 5:
        D_80145100[0] = a0;
        break;
    case 6:
        D_80145100[0x10] = a0;
        break;
    case 7:
    case 8:
        D_80145100[D_801450E0 - 5] = a0;
        break;
    case 9:
        D_80145100[0x11] = a0;
        break;
    case 21:
        D_80145100[0xC] = a0 - 1;
        break;
    default:
        if ((u32)(D_801450E0 - 10) < 4) {
            D_80145100[D_801450E0 - 6] = a0;
        } else if ((u32)(D_801450E0 - 14) < 4) {
            D_80145100[0x19 - D_801450E0] = a0;
        } else if ((u32)(D_801450E0 - 18) < 3) {
            D_80145100[0x21 - D_801450E0] = a0;
        }
        break;
    }
    r = 0;
    __asm__ volatile("" : : "r"(r));
    return r;
}

s32 func_80144918(void);

s32 func_80144850(s32 a0, s32 a1, s32 a2) {
    D_80145110 = a1;
    if ((u32)(a1 - 1) >= 15) return 0;
    if (!func_801424E0(a0)) return 0;
    D_80145118 = a2 != 0;
    D_80145270 = 0xB;
    D_80145120 = func_80144918;
    D_80145124 = func_80144AC0;
    D_801450D4 = 1;
    D_801450C8 = 2;
    return 1;
}

extern u8 D_80145104_80144918 asm("D_80145104");
extern u8 D_80145118_80144918 asm("D_80145118");
extern u8 D_801451D3[];

s32 func_80144918(void) {
    if (D_801450D4 != 0) {
        switch (D_801450CC) {
        case 2:
            __asm__("");
            return 0x52;
        case 5:
            return ((u8 *)&D_80145110)[1];
        case 6:
            return ((u8 *)&D_80145110)[0];
        }
        return 0;
    }
    switch (D_801450CC) {
    case 2:
        D_80145104_80144918 = 0;
        return 0x57;
    case 5:
        return ((u8 *)&D_80145110)[1];
    case 6:
        return ((u8 *)&D_80145110)[0];
    case 0x85:
        D_80145104_80144918 ^= D_80145118_80144918;
        return D_80145118;
    case 0x86:
        return D_80145104_80144918;
    case 0x87:
        return ((D_80145110 >> 8) ^ D_80145110) & 0xFF;
    }
    if (D_801450CC < 7) return 0;
    if (D_801450CC >= 0x85) return 0;
    {
        u8 c = D_801451D3[D_801450CC];
        D_80145104_80144918 ^= c;
        return c;
    }
}

extern u8 D_80145104_80144AC0 asm("D_80145104");
extern u8 D_801451DA[];

s32 func_80144AC0(u8 a0) {
    if (D_801450D4 != 0) {
        switch (D_801450E0) {
        case 2:
            if (a0 == 8) {
                D_801450D4 = 0;
                D_8014511C = 1;
                return 0;
            }
            D_8014511C = 0x8A;
            return 0;
        case 3:
            if (a0 != 0x5A) return -3;
            break;
        case 8:
            if (a0 != 0x5D) return -8;
            D_80145104_80144AC0 = 0;
            return 0;
        case 9:
            if (a0 != ((u8 *)&D_80145110)[1]) return -9;
            D_80145104_80144AC0 ^= a0;
            break;
        case 10:
            if (a0 != ((u8 *)&D_80145110)[0]) return -10;
            D_80145104_80144AC0 ^= a0;
            func_80145280(0, D_801451DA, 0x80, &D_80145104);
            D_8014511C = 2;
            D_801450E0 += 0x80;
            D_801450DC += 0x80;
            break;
        case 0x8B:
            if (a0 != D_80145104_80144AC0) return -0x8B;
            break;
        case 0x8C:
            if (a0 != 0x47) return -0x8C;
            break;
        default:
            if ((u32)(D_801450E0 - 11) < 0x80) {
                D_80145104_80144AC0 ^= a0;
            }
            return 0;
        }
    } else {
    switch (D_801450E0) {
    case 2:
        if (a0 == 8) {
            D_8014511C = 1;
            return 0;
        }
        D_8014511C = 0x88;
        __asm__("");
        return 0;
    case 3:
        __asm__("");
        if (a0 != 0x5A) return -3;
        break;
    case 5:
        func_80145280(1, D_801451DA, 0x7E, &D_80145104);
        D_8014511C = 7;
        D_801450E0 += 0x7E;
        D_801450DC += 0x7E;
        break;
    case 0x89:
        if (a0 != 0x5D) return -0x89;
        break;
    case 0x8A:
        __asm__("");
        {
            register s32 c asm("$4") = a0;
            register s32 k asm("$3") = 0x47;
            if (c != k) return -0x8A;
        }
        break;
    }
    }
    return 0;
}

s32 func_80144E9C(void);

s32 func_80144DF4(s32 a0, s32 *a1, s32 *a2) {
    register s32 r asm("$2");

    if (func_801424E0(a0)) {
        r = 1;
        __asm__ volatile("");
        D_80145270 = 0x64;
        D_80145120 = func_80144E9C;
        D_80145124 = func_80144EC0;
        D_80145108 = a1;
        D_8014510C = a2;
        D_801450C8 = 2;
    } else {
        r = 0;
    }
    return r;
}

s32 func_80144E9C(void) {
    register s32 r asm("$2") = 0x53;
    if (D_801450CC != 2) {
        r = 0;
        __asm__("");
    }
    return r;
}

s32 func_80144EC0(s32 a0) {
    switch (D_801450E0) {
    case 2:
        D_8014511C = 8;
        break;
    case 3:
        if ((a0 & 0xFF) != 0x5A) return -1;
        break;
    case 7:
        *D_80145108 = a0 & 0xFF;
        break;
    case 8:
        *D_80145108 = (*D_80145108 << 8) + (a0 & 0xFF);
        break;
    case 9:
        *D_8014510C = a0 & 0xFF;
        break;
    case 10:
        *D_8014510C = (*D_8014510C << 8) + (a0 & 0xFF);
        break;
    }
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

s32 func_80144F80(s32 a0, u32 a1) {
    a1 &= 0xFF000000;
    if (a1 == 0 || a1 == 0x06000000 || a1 - 0x0A000000 <= 0x03000000) {
        __asm__(""); return 1;
    }
    if (a1 == 0x02000000 || a1 == 0x04000000 || a1 == 0x08000000) {
        if (a0 == 0) {
            return 1;
        }
        __asm__("");
        return 0;
    }
    return 0;
}
