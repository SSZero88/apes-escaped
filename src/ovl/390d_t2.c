#include "common.h"

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

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t2", func_80141D14);

INCLUDE_ASM("asm/ovl/390/nonmatchings/390d_t2", func_80141EBC);
