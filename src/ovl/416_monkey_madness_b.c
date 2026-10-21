#include "common.h"
#include "m2c_macros.h"

extern s32 D_800B4D64;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xB6]; s32 f_820C; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
M2C_UNK Effect_Spawn(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_800B4D88;
extern M2C_UNK D_80141640;
extern struct S_D_80141880 { u8 pad_0[0x2]; u16 f_2; s16 f_4; u8 pad_6[0x2]; s16 f_8; u8 pad_A[0x6]; s32 f_10; s32 f_14; } D_80141880;
extern struct S_g_Spike { u8 pad_0[0x2C]; s32 f_2C; s32 f_30; u8 pad_34[0x4]; s32 f_38; } g_Spike;

extern struct S_D_80142368 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80142368[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142728;
s32 Sound_Play(M2C_UNK, s32);
M2C_UNK func_8013D440(M2C_UNK, M2C_UNK *, void *);
extern M2C_UNK D_80141D20;
extern M2C_UNK D_801421C0;
M2C_UNK func_8013EF0C(M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80142260;
extern M2C_UNK D_801418A0;

s32 func_8013D000(void *arg0) {
    s16 temp_a0;
    void *temp_v1;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
    if (temp_a0 >= 0) {
        M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D06C);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D2A0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D3F0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D440);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D4E0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D63C);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D77C);

void func_8013D77C(void *, s32, s32, s32, s32);

void func_8013D890(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    func_8013D77C(arg0, arg1, arg2, 0, arg3);
}

void func_8013D8BC(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80142368[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80142368");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D8E4(SVECTOR *arg0) {
    s32 i;
    s16 x = arg0->vx;
    s16 y = arg0->vy;
    s16 z = arg0->vz;

    for (i = 0x4F; i >= 0; i--) {
        D_80143F08_8013D554[i].life = (RAND() >> 8 & 0x1F) + 0x28;
        D_80143F08_8013D554[i].x = x + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].y = y - ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].z = z + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].vx = ((RAND() >> 8) - 0x80) / 2;
        D_80143F08_8013D554[i].vy = -(RAND() >> 8 & 0x3F) - 0x20;
        D_80143F08_8013D554[i].vz = ((RAND() >> 8) - 0x80) / 2;
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DA4C);

void func_8013DE1C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DE44(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DE6C(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DE94(s32 arg0) {
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

void func_8013DF28(void) {
    D_80142728 = -1;
}

void func_8013DF38(s32 arg0) {
    D_80142728 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013DF60(void *obj) {
    if (D_80142728 != -1) {
        Sound_Stop(obj, D_80142728);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DF90);

void func_8013E14C(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 7;
    var_s1 = &D_80141D20;
    var_s0 = (void *)((u8 *)&D_80141D20 + 0x7C);
    do {
        func_8013D440(2, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 -= 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x94));
        var_s1 = (void *)((u8 *)var_s1 + (0x94));
    } while (var_s2 >= 0);
}

void func_8013E1AC(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_80141D20;
    do {
        M2C_FIELD(var_v0, s8 *, 0x84) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x94));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E1D0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E2BC);

void func_8013EC5C(void) {
    func_8013D440(3, &D_801421C0, (void *)((u8 *)&D_801421C0 + 0x70));
    M2C_FIELD(&D_801421C0, s8 *, 0x78) = 0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EC94);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013ECD4);

void func_8013EE74(void) {
    func_8013EF00(1);
    func_8013EF0C(&D_80142260, 0);
    D_80141880.f_14 = 0x1E;
    D_80141880.f_10 = 0;
}

M2C_UNK Sound_PlayFixed(M2C_UNK);

void func_8013EEB8(void) {
    M2C_FIELD(&D_80141880, s8 *, 0) = 0;
    func_8013EE74();
    M2C_FIELD(&D_80141880, s32 *, 0x18) = 0;
    M2C_FIELD(&D_80141880, s32 *, 0x14) = 0x5A;
    func_8013DF38(0xB1);
    Sound_PlayFixed(4);
}

extern s8 D_80141881;

void func_8013EF00(s8 arg0) {
    D_80141881 = arg0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EF0C);

void func_8013EF44(void *arg0) {
    u16 temp_a0;
    u16 temp_v1;
    void *temp_a2;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((temp_v1 & 0xFFFF) == M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74)), u16 *, 2)) {
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
    }
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x5C);
    temp_a2 = (M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    if ((u16) M2C_FIELD(temp_a2, u16 *, 2) < temp_a0) {
        if (M2C_FIELD(arg0, u8 *, 0x7B) == 1) {
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (temp_a0 - 1);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a2, u16 *, 0);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013EFCC);

void func_8013F0E0(void) {
    if (D_80141880.f_2 != 0) {
        D_80141880.f_2 = (u16) (D_80141880.f_2 - 1);
        g_Spike.f_30 = (s32) D_80141880.f_4;
        g_Spike.f_38 = (s32) D_80141880.f_8;
        if (g_Spike.f_2C >= -0xC3F) {
            g_Spike.f_2C = -0xC40;
        }
        if (g_Spike.f_2C < -0x1FA4) {
            g_Spike.f_2C = -0x1FB8;
        }
        D_80141880.f_4 = (s16) ((s32) (D_80141880.f_4 * 7) / 8);
        D_80141880.f_8 = (s16) ((s32) (D_80141880.f_8 * 7) / 8);
        Effect_Spawn(0xCE, &D_800B4D88, &D_80141640, 0);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F1AC);

void func_8013F544(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    var_s1 = &D_801418A0;
    var_s0 = (void *)((u8 *)&D_801418A0 + 0x7C);
    do {
        func_8013D440(1, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x90));
        var_s1 = (void *)((u8 *)var_s1 + (0x90));
    } while (var_s2 < 8);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F5A8);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F6F8);

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_414;
typedef struct { P_TAG_414 tag; u32 rgbc; u32 xy; u32 wh; } TILE_414;
typedef struct { P_TAG_414 tag; u32 code; } DR_MODE_414;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_414;
struct Game_414 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_414 db[2]; };

void func_8013F954(s32 c)
{
  TILE_414 *p = (TILE_414 *) ((struct Game_414 *)&g_Game)->prim;
  u32 *ot = ((struct Game_414 *)&g_Game)->db[((struct Game_414 *)&g_Game)->cur].ot;
  DR_MODE_414 *m;
  p->tag.len = 3;
  p->rgbc = c | 0x62000000;
  p->xy = 0;
  p->wh = 0xF00180;
  p->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) p;
  p = (TILE_414 *) (p - -1);
  m = (DR_MODE_414 *) p;
  m->tag.len = 1;
  m->code = 0xE1000220;
  m->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) m;
  ((struct Game_414 *)&g_Game)->prim = (u8 *) (m + 1);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013FA2C);
