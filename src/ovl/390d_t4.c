#include "common.h"

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
s32 func_80144500(s32, s32 *, s32 *);
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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142808);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142A90);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142B30);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142B50);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142BE4);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80142E7C);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_8014311C);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801432B4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801434CC);

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143690);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143884);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801439A4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143A64);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143B38);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143CA4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80143F54);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144004);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144084);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144128);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801441E4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144264);

s32 func_80144308(void) {
    switch (D_801450CC) {
    case 2:
        return 0x5F;
    case 4:
        return D_80145110;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144344);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144400);

void func_801444D4(s32 a0) {
    func_80144500(a0, &D_801450F8, &D_801450FC);
}

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144500);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801445A8);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801445CC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_8014464C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_801446EC);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144710);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144850);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144918);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144AC0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144DF4);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144E9C);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144EC0);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t4", func_80144F80);
