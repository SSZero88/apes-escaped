#include "game.h"
extern u8 D_800AEC20[];
extern u8 D_800F44D4[];
extern u8 D_800AEC8C[];
extern u8 D_800AEB66[];
extern struct S_D_800B000C { u8 pad0[0x2C]; void *f_2C; u8 pad30[0x20]; void *f_50; } D_800B000C;
void DebugItem_Init(void *, void *, s32);
void DebugItem_SetRange(void *, s32, s32);

/* Debug menu page for monkeys: item 0 edits D_800F44D4 (0..8), item 1 edits the
   active-monkey limit D_800AEB66 (0..4). */
void Monkey_InitDebugMenu(void) {
    u8 *a = D_800AEC20;
    void *t = &D_800B000C;
    ((struct S_D_800B000C *)t)->f_2C = a;
    ((struct S_D_800B000C *)t)->f_50 = D_800AEC8C;
    DebugItem_Init(a, D_800F44D4, 1);
    t = a + 0x24;
    DebugItem_SetRange(a, 0, 8);
    DebugItem_Init(t, D_800AEB66, 1);
    DebugItem_SetRange(t, 0, 4);
}

typedef struct { u8 pad[0x24]; } Item_800430F0;
typedef struct { u8 pad[0x88]; } Kind_800430F0;
extern Item_800430F0 D_800AEC8C_i[] asm("D_800AEC8C");
extern void *g_RadarLiveTarget;
void func_8007D29C(void *, s32 (*)());
void func_8007D2A4(void *, s32);
s32 func_80043358(void);
#define KB_430F0 ((u8 *)&((Kind_800430F0 *)g_MonkeyKinds)[m->f_7C])
extern Monkey g_Monkeys[8];
void Debug_MonkeyParamMenu_(s32 idx) asm("Debug_MonkeyParamMenu");
/* Debug_MonkeyParamMenu: the developers' debug menu for the parameters of monkey idx's kind
 * (labels at 0x800A4BE0..0x800A4CAC): "Param ID" (0..7, func_80043358 on change), the 8 sight
 * distances by Spike's pose (+0xC: TO-MEI, RUN, WALK, SEISHI, HAI+FURI, HAI, FUSE, MARU; step 10),
 * Speed1 (+2), Speed2 (+4) and the attack windows Mgun (+0x1E), Missile (+0x26), Banana (+0x2E),
 * Stone (+0x3E), Coconut (+0x36) and Scratch (+0x56). */
void Debug_MonkeyParamMenu_(s32 idx) {
    Item_800430F0 *it = D_800AEC8C_i;
    Monkey *m = &g_Monkeys[idx];
    s32 (*cb)() = func_80043358;
    s32 i;

    DebugItem_Init(it, g_RadarLiveTarget, 0);
    DebugItem_SetRange(it, 0, 7);
    func_8007D29C(it++, cb);
    it++;
    for (i = 0; i < 8; i++) {
        DebugItem_Init(it, &((s16 *)(KB_430F0 + 0xC))[i], 1);
        func_8007D2A4(it, 10);
        it++;
    }
    it++;
    DebugItem_Init(it++, KB_430F0 + 0x2, 1);
    DebugItem_Init(it++, KB_430F0 + 0x4, 1);
    DebugItem_Init(it++, KB_430F0 + 0x1E, 0);
    DebugItem_Init(it++, KB_430F0 + 0x26, 0);
    DebugItem_Init(it++, KB_430F0 + 0x2E, 0);
    DebugItem_Init(it++, KB_430F0 + 0x3E, 0);
    DebugItem_Init(it++, KB_430F0 + 0x36, 0);
    DebugItem_Init(it, KB_430F0 + 0x56, 0);
}

void Debug_MonkeyParamMenu(void);

s32 func_80043358(void) {
    Debug_MonkeyParamMenu();
    return 1;
}
