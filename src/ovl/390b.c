#include "common.h"
#include "m2c_macros.h"

extern s16 D_800E3880;
extern s16 D_8013C5B4;
void func_8013784C(s32, s32);

s32 func_8013B400(void) {
    switch (D_800E3880) {
    case 0:
        func_8013784C(1, D_8013C5B4);
        break;
    case -7:
        func_8013784C(2, 0);
        break;
    case -2:
    case -1:
        func_8013784C(0x2C, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern struct { u8 pad_0[6]; s16 f_6; } D_800E3880_8013B47C asm("D_800E3880");
extern u8 D_800E1880[];
extern u8 D_8013C5C0[];
void func_8014016C(void);
s32 func_80139F08(void);
void func_80139A3C(s32);
void func_80139A68(void);
void MemCard_Request(s32, s32);

s32 func_8013B47C(void) {
    s32 r;
    s32 i;

    func_8014016C();
    r = func_80139F08();
    func_80139A3C(4);
    func_80139A68();
    if (r != 0) {
        if (r == 1) {
            for (i = 0; i < 16; i++) {
                D_800E1880[i + D_800E3880_8013B47C.f_6 * 0x7A0 + 0x198] = D_8013C5C0[i];
            }
            MemCard_Request(2, 0);
            func_8013784C(0x11, 0);
            return 0;
        }
        func_8013784C(1, D_8013C5B4);
    }
    return 0;
}

extern struct { u8 pad_0[6]; s16 f_6; } D_800E3880_8013B550 asm("D_800E3880");
extern s16 D_8013C5A8;
extern s16 D_8013C5AA;
extern s16 D_8013C5AC;
extern s16 D_8013C5AE;
extern s16 D_8013C5B0;
extern s16 D_8013C5B2;
extern s16 D_8013AF50;
extern struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; } D_8013C540;
extern s16 D_8013C5D0[];
u8 *func_8013FD44(void);

s32 func_8013B550(void) {
    s32 i;
    u8 *s;

    D_8013C5A8 = 0;
    D_8013C5AA = 0;
    D_8013C5AE = 0;
    D_8013C5AC = 4;
    D_8013C5B2 = 0xB;
    D_8013C5B0 = 0x2C;
    D_8013C540.f_4 = 1;
    D_8013C540.f_6 = -1;
    D_8013C540.f_8 = -1;
    D_8013C5B4 = D_8013AF50;
    if (D_800E1880[D_800E3880_8013B550.f_6 * 0x7A0 + 0x198] == 0) {
        s = func_8013FD44();
        s[4] = i + 0x6B;
        for (i = 0; i < 16; i++) {
            D_8013C5C0[i] = s[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            D_8013C5C0[i] = D_800E1880[i + D_800E3880_8013B550.f_6 * 0x7A0 + 0x198];
        }
    }
    for (i = 4; i >= 0; i--) {
        D_8013C5D0[i] = 0;
    }
    return 0;
}

extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; } g_Pad_8013B6C4 asm("g_Pad");
extern u8 D_8013C550[];
extern s32 D_800E5488;
s32 Sound_PlayFixed(s32);

s32 func_8013B6C4(void) {
    s32 i;
    u32 b;

    for (i = 0; i < 5; i++) {
        if (D_8013C5D0[i] > 0) {
            D_8013C5D0[i]--;
        } else {
            D_8013C5D0[i] = 0;
        }
    }
    b = g_Pad_8013B6C4.pressed & g_Pad_8013B6C4.held;
    if (b & 0x800) {
        Sound_PlayFixed(2);
        return 1;
    }
    if (b & 0x60) {
        Sound_PlayFixed(3);
        D_8013C5C0[D_8013C5AA] = D_8013C550[D_8013C5A8 + D_8013C5AE];
        if (++D_8013C5AA >= 5) {
            D_8013C5AA = 4;
        }
        if (g_Pad_8013B6C4.pressed & g_Pad_8013B6C4.held & 0x20) {
            D_8013C5D0[1] = 4;
        } else {
            D_8013C5D0[0] = 4;
        }
    } else if (b & 0x80) {
        Sound_PlayFixed(1);
        D_8013C5C0[D_8013C5AA] = 0xEF;
        if (--D_8013C5AA < 0) {
            D_8013C5AA = 0;
        }
        D_8013C5D0[4] = 4;
    } else if (b & 0x8) {
        Sound_PlayFixed(0xB);
        D_8013C5D0[3] = 4;
        switch (D_8013C5AC) {
        case 0:
            D_8013C5AC = 1;
            D_8013C5AE = 0x5A;
            D_8013C5B0 = 0x5A;
            D_8013C5B2 = 0xF;
            D_8013C540.f_4 = -1;
            D_8013C540.f_6 = 1;
            D_8013C5A8 = 0;
            break;
        case 1:
            D_8013C5AC = 2;
            D_8013C5AE = 0xB4;
            D_8013C5B0 = 0x2C;
            D_8013C5B2 = 0xB;
            D_8013C540.f_6 = -1;
            D_8013C540.f_8 = 1;
            D_8013C5A8 = 0;
            break;
        case 2:
            D_8013C5AC = 0;
            D_8013C5AE = 0;
            D_8013C5B0 = 0x5A;
            D_8013C5B2 = 0xF;
            D_8013C540.f_8 = -1;
            D_8013C540.f_4 = 1;
            D_8013C5A8 = 0;
            break;
        case 3:
            D_8013C5AC = 4;
            D_8013C5AE = 0;
            D_8013C540.f_4 = 1;
            D_8013C540.f_6 = -1;
            break;
        case 4:
            D_8013C5AC = 3;
            D_8013C5AE = 0x2C;
            D_8013C540.f_4 = -1;
            D_8013C540.f_6 = 1;
            break;
        }
    } else if (b & 0x4) {
        Sound_PlayFixed(0xB);
        D_8013C5D0[2] = 4;
        switch (D_8013C5AC) {
        case 2:
            D_8013C5AC = 1;
            D_8013C5AE = 0x5A;
            D_8013C5B0 = 0x5A;
            D_8013C5B2 = 0xF;
            D_8013C540.f_8 = -1;
            D_8013C540.f_6 = 1;
            D_8013C5A8 = 0;
            break;
        case 0:
            D_8013C5AC = 2;
            D_8013C5AE = 0xB4;
            D_8013C5B0 = 0x2C;
            D_8013C5B2 = 0xB;
            D_8013C540.f_4 = -1;
            D_8013C540.f_8 = 1;
            D_8013C5A8 = 0;
            break;
        case 1:
            D_8013C5AC = 0;
            D_8013C5AE = 0;
            D_8013C5B0 = 0x5A;
            D_8013C5B2 = 0xF;
            D_8013C540.f_6 = -1;
            D_8013C540.f_4 = 1;
            D_8013C5A8 = 0;
            break;
        case 3:
            D_8013C5AC = 4;
            D_8013C5AE = 0;
            D_8013C540.f_4 = 1;
            D_8013C540.f_6 = -1;
            break;
        case 4:
            D_8013C5AC = 3;
            D_8013C5AE = 0x2C;
            D_8013C540.f_4 = -1;
            D_8013C540.f_6 = 1;
            break;
        }
    }
    if (D_800E5488 == 0x1000) {
        Sound_PlayFixed(0);
        if ((D_8013C5A8 -= D_8013C5B2) < 0) {
            D_8013C5A8 += D_8013C5B0;
        }
    }
    if (D_800E5488 == 0x4000) {
        Sound_PlayFixed(0);
        if ((D_8013C5A8 += D_8013C5B2) >= D_8013C5B0) {
            D_8013C5A8 -= D_8013C5B0;
        }
    }
    if (D_800E5488 == 0x2000) {
        Sound_PlayFixed(0);
        if (++D_8013C5A8 >= D_8013C5B0) {
            D_8013C5A8 = 0;
        }
    }
    if (D_800E5488 == 0x8000) {
        Sound_PlayFixed(0);
        if (--D_8013C5A8 < 0) {
            D_8013C5A8 = D_8013C5B0 - 1;
        }
    }
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, pad1; s16 x1, y1; u8 r2, g2, b2, pad2; s16 x2, y2; u8 r3, g3, b3, pad3; s16 x3, y3; } PolyG4_8013BC64;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, pad1; s16 x1, y1; u8 r2, g2, b2, pad2; s16 x2, y2; } PolyG3_8013BC64;
extern u8 g_Game[];
extern u8 D_8013C550[];
void Menu_DrawCaps(s32, s32, s32);
void func_8013FD50(void *);
void func_80136000(u8 *s, s32 x, s32 y, s32 c);
s32 func_8013946C(s32 i, s32 x, s32 y);
#define G4_8013BC64 ((PolyG4_8013BC64 *)G_DRAW.prim)
#define G3_8013BC64 ((PolyG3_8013BC64 *)G_DRAW.prim)
#define ADDPRIM_8013BC64(OT) __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(OT), "m"(G_DRAW.prim) : "$2", "$4", "memory")
#define ADDPRIM2_8013BC64(OT) __asm__ volatile("lwl $4, 2(%0)\n\tlw $3, %1\n\tsll $3, $3, 8\n\tswl $3, 2(%0)\n\tlw %0, %1\n\tswl $4, 2(%0)" : : "r"(OT), "m"(G_DRAW.prim) : "$3", "$4", "memory")

s32 func_8013BC64(void) {
    u8 buf[2];
    s32 i;
    s32 x, y;
    s16 cur, col, row;

    if (D_8013C5AC < 2) {
        col = D_8013C5A8 % 15;
        row = D_8013C5A8 / 15;
        y = row * 20 + 0x3E;
        x = col * 16 + (s16)(col / 5) * 20 + 0x32;
    } else {
        col = D_8013C5A8 % 11;
        row = D_8013C5A8 / 11;
        x = col * 16 + 0x64;
        y = row * 20 + 0x52;
    }
    Menu_DrawCaps(x + 8, y - 2, 0x20);
    func_8013FD50(&D_8013C540);
    for (i = 0; i < 5; i++) {
        buf[0] = D_8013C5C0[i];
        buf[1] = 0;
        func_80136000(buf, i * 16 + 0xAE, 0x20, 1);
    }
    for (i = 0; i < D_8013C5B0; i++) {
        if (D_8013C5AC < 2) {
            y = i / 15 * 20 + 0x3E;
            x = (i % 15) * 16 + (i % 15) / 5 * 20 + 0x32;
        } else {
            x = (i % 11) * 16 + 0x64;
            y = i / 11 * 20 + 0x52;
        }
        buf[0] = D_8013C550[i + D_8013C5AE];
        buf[1] = 0;
        if (i == D_8013C5A8) {
            func_80136000(buf, x, y - 2, 0);
        } else {
            func_80136000(buf, x, y, 1);
        }
    }
    for (i = 0; i < 5; i++) {
        ((u8 *)G4_8013BC64)[3] = 8;
        G4_8013BC64->code = 0x38;
        G4_8013BC64->x0 = i * 16 + 0xB0;
        G4_8013BC64->y0 = 0x30;
        G4_8013BC64->x1 = i * 16 + 0xBC;
        G4_8013BC64->y1 = 0x30;
        G4_8013BC64->x2 = i * 16 + 0xB0;
        G4_8013BC64->y2 = 0x34;
        G4_8013BC64->x3 = i * 16 + 0xBC;
        G4_8013BC64->y3 = 0x34;
        if (D_8013C5AA == i) {
            G4_8013BC64->r0 = 0xF5;
            G4_8013BC64->g0 = 0xDC;
            G4_8013BC64->b0 = 0xC8;
            G4_8013BC64->r1 = 0xE6;
            G4_8013BC64->g1 = 0x46;
            G4_8013BC64->b1 = 0x28;
            G4_8013BC64->r2 = 0xC4;
            G4_8013BC64->g2 = 0x46;
            G4_8013BC64->b2 = 0x3C;
            G4_8013BC64->r3 = 0x5F;
            G4_8013BC64->g3 = 0x0A;
            G4_8013BC64->b3 = 0x08;
        } else {
            G4_8013BC64->r0 = 0xC8;
            G4_8013BC64->g0 = 0xDC;
            G4_8013BC64->b0 = 0xF5;
            G4_8013BC64->r1 = 0x28;
            G4_8013BC64->g1 = 0x46;
            G4_8013BC64->b1 = 0xE6;
            G4_8013BC64->r2 = 0x3C;
            G4_8013BC64->g2 = 0x46;
            G4_8013BC64->b2 = 0xC4;
            G4_8013BC64->r3 = 0x08;
            G4_8013BC64->g3 = 0x0A;
            G4_8013BC64->b3 = 0x5F;
        }
        ADDPRIM_8013BC64(&G_DRAW.db[G_DRAW.cur].ot[0]);
        G_DRAW.prim += 0x24;
    }
    ((u8 *)G3_8013BC64)[3] = 6;
    G3_8013BC64->code = 0x31;
    G3_8013BC64->x0 = 0x37;
    G3_8013BC64->x1 = 0x3F;
    G3_8013BC64->x2 = 0x3F;
    G3_8013BC64->y0 = 0xC8;
    G3_8013BC64->y1 = 0xC0;
    G3_8013BC64->y2 = 0xD0;
    G3_8013BC64->r0 = 0xC8;
    G3_8013BC64->g0 = 0xDC;
    G3_8013BC64->b0 = 0xF5;
    G3_8013BC64->r1 = 0x28;
    G3_8013BC64->g1 = 0x46;
    G3_8013BC64->b1 = 0xE6;
    G3_8013BC64->r2 = 0x3C;
    G3_8013BC64->g2 = 0x46;
    G3_8013BC64->b2 = 0xC4;
    ADDPRIM2_8013BC64(&G_DRAW.db[G_DRAW.cur].ot[0]);
    G_DRAW.prim += 0x1C;
    ((u8 *)G3_8013BC64)[3] = 6;
    G3_8013BC64->code = 0x31;
    G3_8013BC64->x0 = 0x9B;
    G3_8013BC64->x1 = 0x93;
    G3_8013BC64->x2 = 0x93;
    G3_8013BC64->y0 = 0xC8;
    G3_8013BC64->y1 = 0xD0;
    G3_8013BC64->y2 = 0xC0;
    G3_8013BC64->r0 = 0xC8;
    G3_8013BC64->g0 = 0xDC;
    G3_8013BC64->b0 = 0xF5;
    G3_8013BC64->r1 = 0x28;
    G3_8013BC64->g1 = 0x46;
    G3_8013BC64->b1 = 0xE6;
    G3_8013BC64->r2 = 0x3C;
    G3_8013BC64->g2 = 0x46;
    G3_8013BC64->b2 = 0xC4;
    ADDPRIM2_8013BC64(&G_DRAW.db[G_DRAW.cur].ot[0]);
    G_DRAW.prim += 0x1C;
    func_8013946C(0, 0x10C, D_8013C5D0[0] + 0x20);
    func_8013946C(1, 0x120, D_8013C5D0[1] + 0x20);
    func_8013946C(3, 0xC2, D_8013C5D0[4] + 0xC0);
    func_8013946C(4, 0x22, D_8013C5D0[2] + 0xC0);
    func_8013946C(5, 0x9C, D_8013C5D0[3] + 0xC0);
    func_8013946C(6, 0x10F, 0xC0);
    G_DRAW.prim[3] = 1;
    *(u32 *)(G_DRAW.prim + 4) = 0xE1000217;
    ADDPRIM2_8013BC64(&G_DRAW.db[G_DRAW.cur].ot[0]);
    G_DRAW.prim += 8;
    func_80139A3C(3);
    func_80139A68();
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
