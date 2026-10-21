#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D028(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D050(void) {
    Pad_Vibrate(1, 0x78, 2);
}

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

void func_8013D078(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D10C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D1AC);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D324);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D43C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D57C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D708);

extern u8 D_80140944;

void func_8013D804(void) {
    D_80140944 = 0;
}

extern struct { SVECTOR v; u8 pad8[0x3C]; u8 f_44; u8 pad45; s16 f_46; } D_80140900;

void func_8013D810(SVECTOR *v) {
    if (D_80140900.f_44 == 0) {
        D_80140900.f_44 = 1;
        D_80140900.f_46 = 0x32;
        D_80140900.v = *v;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D860);

typedef struct { u8 pad0[0x54]; u8 f_54; u8 pad55[7]; } Slot_421;
extern Slot_421 D_80140948[4];

void func_8013DE14(void) {
    s32 i;
    Slot_421 *p;

    for (i = 3, p = D_80140948; i >= 0; i--, p++) {
        p->f_54 = 0;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DE38);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DEEC);

typedef struct { u8 pad0[0x1C]; u8 f_1C; u8 pad1D[7]; } Slot_421b;
extern Slot_421b D_80140AB8[16];
extern u8 D_80140CF8;

void func_8013E4D8(void) {
    s32 i;
    Slot_421b *p;

    for (i = 15, p = D_80140AB8; i >= 0; i--, p++) {
        p->f_1C = 0;
    }
    D_80140CF8 = 0;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E500);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E650);

typedef struct { u8 pad0[6]; u8 f_6; u8 pad7[5]; } Slot_421c;
extern Slot_421c D_80140D00[4];

void func_8013E8C0(void) {
    s32 i;
    Slot_421c *p;

    for (i = 3, p = D_80140D00; i >= 0; i--, p++) {
        p->f_6 = 0;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E8E4);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E97C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013EE04);

extern struct { s32 f_0; s32 f_4; u8 pad8[0x12]; u8 f_1A[18]; } D_80140D30;

void func_8013F4F0(void) {
    s32 i;

    for (i = 0; i < 18; i++) {
        D_80140D30.f_1A[i] = 0;
        D_80140D30.f_0 = 0;
        D_80140D30.f_4 = 0;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F520);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F694);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F848);

extern struct { u8 pad0[4]; s32 f_4; u8 pad8[0x32]; u8 f_3A; } D_801408C0;

void func_8013FC74(void) {
    D_801408C0.f_3A = 0;
    D_801408C0.f_4 = 0x1E;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FC8C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FD74);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140280);

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80141880");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D88(SVECTOR *arg0, s32 arg1) {
    s32 i;
    u16 x = arg0->vx;
    u16 y = arg0->vy;
    u16 z = arg0->vz;
    s16 floor = Floor_GetHeight(arg0->vx, arg0->vy, arg0->vz);

    for (i = 15; i >= 0; i--) {
        if (D_80144590_8013D028[i].life == 0) {
            D_80144590_8013D028[i].life = (RAND() >> 8 & 0x1F) + 0x28;
            D_80144590_8013D028[i].floor = floor;
            D_80144590_8013D028[i].x = x + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].y = y - ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].z = z + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].vx = ((RAND() >> 8) - 0x80) / 8;
            D_80144590_8013D028[i].vy = -(RAND() >> 8 & 0x1F) - 0x18;
            D_80144590_8013D028[i].vz = ((RAND() >> 8) - 0x80) / 8;
            if (--arg1 == 0) {
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140F78);

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_80141418(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_80140D88(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8014149C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801414F8);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801416D8);

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6", D_80141850);
