#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8008FC30(s16, void *);
extern struct S_g_Game { u8 pad_0[0x8160]; u16 f_8160; u8 pad_8162[0xAA]; s32 f_820C; } g_Game;
s32 func_800978E0(s16);

M2C_UNK Model_BindStageMesh(s32, s16);
M2C_UNK Stage_CountCaughtMonkeys(s32 *);
extern s32 D_800B4D64;
M2C_UNK Collision_Set(M2C_UNK, void *, M2C_UNK *);
extern struct S_D_8013DCE0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x8]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[0x14]; s16 f_60; s16 f_62; s16 f_64; } D_8013DCE0;
s32 SpecterCoin_Count();
s32 func_800964B0(M2C_UNK);

s32 func_8013D000(void *arg0) {
    s32 sp10;
    s32 var_s0;

    if ((M2C_FIELD(arg0, s16 *, 0xC) >= 0) && (M2C_FIELD(arg0, s16 *, 0xE) >= 0)) {
        Stage_CountCaughtMonkeys(&sp10);
        var_s0 = 0;
        if (M2C_FIELD(arg0, s16 *, 8) > 0) {
            do {
                if (var_s0 < sp10) {
                    Model_BindStageMesh(D_800B4D64 + ((M2C_FIELD(arg0, s16 *, 0xC) + var_s0) << 5), M2C_FIELD(arg0, s16 *, 0xE));
                }
                var_s0 += 1;
            } while (var_s0 < M2C_FIELD(arg0, s16 *, 8));
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D0B4 asm("g_Game");
extern u8 *D_800B4D64_8013D0B4 asm("D_800B4D64");

s32 func_8013D0B4(s16 *p) {
    u8 *e;
    u8 *t;

    if (p[4] < 0) {
        return 0;
    }
    e = g_Game_8013D0B4.f_820C + p[2] * 0x38;
    t = g_Game_8013D0B4.f_8220 + p[4] * 0x18;
    if (p[1] == 0 && M2C_FIELD(t, s16 *, 2) == 1) {
        p[1] = 1;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013D0B4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013D158 asm("g_Game");
extern u8 *D_800B4D64_8013D158 asm("D_800B4D64");

s32 func_8013D158(s16 *p) {
    u8 *e = g_Game_8013D158.f_820C + p[2] * 0x38;

    p[1] = 0;
    p[3] = 0;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        if (p[4] == 0) {
            Model_BindStageMesh(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, p[7]);
        } else {
            Model_BindStageMesh(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, p[8]);
        }
        M2C_FIELD(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013D208);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013D5C0);

extern struct { u8 pad_0[0x220]; u8 *f_220; } D_800F4350_8013D7E8 asm("D_800F4350");
typedef struct { u8 pad_0[0x7A]; u8 f_7A; u8 pad_7B[0x250 - 0x7B]; } Monkey_8013D7E8;
extern Monkey_8013D7E8 g_Monkeys_8013D7E8[] asm("g_Monkeys");

s32 func_8013D7E8(s16 *p) {
    s32 n = 0;
    s32 i;
    s16 *t;

    for (i = 2; i < 8; i++) {
        t = (s16 *)(D_800F4350_8013D7E8.f_220 + p[i + 4] * 0x18);
        if (t[1] != 0) {
            if (t[4] != 0) {
                g_Monkeys_8013D7E8[t[4] - 1].f_7A = 2;
            }
            n++;
        }
    }
    if (n == 3) {
        func_8008FC30(p[5], p);
    }
    return 0;
}

s32 func_8013D8A8(void *arg0) {
    if ((s32) g_Game.f_8160 >= M2C_FIELD(arg0, s16 *, 0xA)) {
        func_8008FC30(M2C_FIELD(arg0, s16 *, 8), arg0);
    }
    return 0;
}

s32 func_8013D8F8(void *arg0) {
    D_8013DCE0.f_44 = 0x40;
    D_8013DCE0.f_46 = 0x100;
    D_8013DCE0.f_30 = 0;
    D_8013DCE0.f_34 = 0;
    D_8013DCE0.f_38 = 0;
    D_8013DCE0.f_48 = 0;
    D_8013DCE0.f_4A = 0;
    D_8013DCE0.f_60 = 0x1000;
    D_8013DCE0.f_62 = 0;
    D_8013DCE0.f_64 = 0;
    D_8013DCE0.f_24 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x10);
    D_8013DCE0.f_28 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x12);
    D_8013DCE0.f_2C = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + D_800B4D64), s16 *, 0x14);
    Collision_Set(3, (void *)((u8 *)&D_8013DCE0 + 0x24), &D_8013DCE0);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) D_8013DCE0.f_28;
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013D9D4);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013DB30);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013DD64);

s32 func_8013DDDC(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013DE28);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013DEFC);

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013E014);

s32 func_8013E0E8(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (func_800978E0(M2C_FIELD(arg0, s16 *, 8)) != 0) {
        Model_BindStageMesh(D_800B4D64 + (M2C_FIELD(arg0, s16 *, 0xC) << 5), M2C_FIELD(arg0, s16 *, 0xE));
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013E178);

s32 func_8013E280(s16 *p) {
    s32 n = p[4];

    if (func_8013E2DC() >= n) {
        Model_BindStageMesh(D_800B4D64 + p[6] * 32, p[7]);
    }
    return 0;
}

s32 func_8013E2DC(void) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = SpecterCoin_Count();
    if (func_800964B0(0x13) & 0x10) {
        var_s0 += 5;
    }
    var_v0 = var_s0;
    if (func_800964B0(0x24) & 0x10) {
        var_v0 = var_s0 + 5;
    }
    return var_v0;
}

INCLUDE_ASM("asm/ovl/426/nonmatchings/426_time_station", func_8013E334);
