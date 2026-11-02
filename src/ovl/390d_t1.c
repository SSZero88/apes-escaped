#include "common.h"

typedef struct { u8 pad[0x94]; s32 f94; u8 pad2[0x28]; } EvCB_80141A10;
typedef struct { s32 f0; s32 f4; s32 *f8; s32 fC; EvCB_80141A10 *f10; } ToT_80141A10;

extern ToT_80141A10 *D_80141B70;
extern s32 D_80141B80;
extern s32 *D_80141B84;
extern s32 D_80141B88;
extern s16 D_80141B8C;

s32 func_8002F200(void);
void func_8002F210(void);
s32 func_8002F220(s32, s32, s32);
void func_8002F230(void);
void func_8002F240(s32);
void func_8002F250(s32);

s32 func_80141A10(s32 arg0) {
    s32 s;
    s = func_8002F200();
    func_8002F210();
    D_80141B88 = func_8002F220(arg0, 0x801EFFF0, s);
    func_8002F230();
    D_80141B8C = 1;
    { s32 i = (D_80141B88 & 0xFFFF) * 0xC0; ((EvCB_80141A10 *)((u8 *)D_80141B70->f10 + i))->f94 = 0x404; }
    D_80141B84 = D_80141B70->f8;
    D_80141B80 = *D_80141B84;
    return 0;
}

s32 func_80141AB4(void) {
    D_80141B8C = 0;
    func_8002F210();
    func_8002F240(D_80141B88);
    func_8002F230();
    return 0;
}

s32 func_80141AF0(void) {
    D_80141B8C = 0;
    return 0;
}

s32 func_80141B00(void) {
    if (D_80141B8C != 0) {
        func_8002F250(D_80141B88);
    }
    return 0;
}

s32 func_80141B34(void) {
    if (D_80141B8C != 0) {
        *D_80141B84 = D_80141B80;
    }
    return 0;
}

__asm__(".section .text\n\t.balign 16");
