#include "common.h"
#include "m2c_macros.h"

M2C_UNK Link_Activate(s16, void *);
extern struct S_g_Game { u8 pad_0[0x8160]; u16 f_8160; u8 pad_8162[0xAA]; s32 f_820C; } g_Game;
s32 func_800978E0(s16);

M2C_UNK Model_BindStageMesh(s32, s16);
M2C_UNK Stage_CountCaughtMonkeys(s32 *);
extern s32 g_StageMeshes;
M2C_UNK Collision_Set(M2C_UNK, void *, M2C_UNK *);
extern struct S_D_8013DCE0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x8]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[0x14]; s16 f_60; s16 f_62; s16 f_64; } D_8013DCE0;
s32 SpecterCoin_Count();
s32 func_800964B0(M2C_UNK);

s32 LevelObj_RestartTimer2(s16 *p) {
    p[3] = 0;
    p[1] = p[4];
    return 0;
}

s32 Save_AllLevelsComplete(void);
s32 Overlay_GetState(void);

s32 func_8013DD64(s16 *p) {
    switch (p[1]) {
    case 0:
        if (Save_AllLevelsComplete() != 0) {
            p[1] = 1;
        }
        break;
    case 1:
        if (Overlay_GetState() == 0) {
            p[1] = 5;
        }
        break;    case 2:
        break;
    }
    return 0;
}

s32 func_8013DDDC(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

typedef struct { u8 pad_0[0x100]; s32 f_100; u8 pad_104[0x22]; u16 f_126; u8 pad_128[2]; u16 f_12A; u8 pad_12C[0x26]; u16 f_152; } GameHi_8013DE28;
extern u8 g_Game_8013DE28[] asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; s32 f_30; u8 pad_34[4]; s32 f_38; u8 pad_3C[0x1C]; s16 f_58; } g_Spike_8013DE28 asm("g_Spike");
void Spike_SetPlayMode(s32);
s32 Game_SetMode(s32, s32, s32);

s32 func_8013DE28(s16 *p) {
    u8 *base = g_Game_8013DE28;
    GameHi_8013DE28 *g = (GameHi_8013DE28 *)(base + 0x8000);
    s32 id = p[2];

    if (p[3] == 0) {
        if (g_Spike_8013DE28.f_58 == id && g->f_152 != 0xB) {
            Spike_SetPlayMode(0xB);
            g->f_100 = 6;
            Game_SetMode(7, g->f_126, g->f_12A);
            p[3] = 1;
            p[5] = g_Spike_8013DE28.x;
            p[6] = g_Spike_8013DE28.z;
        }
    } else {
        g_Spike_8013DE28.x = p[5];
        g_Spike_8013DE28.z = p[6];
        g_Spike_8013DE28.f_38 = 0;
        g_Spike_8013DE28.f_30 = 0;
    }
    return 0;
}

typedef struct { u8 pad_0[0x100]; s32 f_100; u8 pad_104[0x22]; u16 f_126; u8 pad_128[2]; u16 f_12A; } GameHi_8013DEFC;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x22]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; u8 pad_812C[0x32]; s16 f_815E; } g_Game_8013DEFC asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; s32 f_30; u8 pad_34[4]; s32 f_38; } g_Spike_8013DEFC asm("g_Spike");
extern s16 D_800EC238_8013DEFC asm("g_SpikeStandObj");
s32 func_8013E2DC(void);

s32 func_8013DEFC(s16 *p) {
    u8 *base = (u8 *)&g_Game_8013DEFC;
    GameHi_8013DEFC *g = (GameHi_8013DEFC *)(base + 0x8000);
    s32 id = p[2];

    if (p[3] == 0) {
        if (D_800EC238_8013DEFC == id && func_8013E2DC() >= p[4]) {
            Spike_SetPlayMode(0xB);
            g->f_100 = 6;
            if (p[5] == 2) {
                Game_SetMode(0x1E, g->f_126, g->f_12A);
            } else {
                Game_SetMode(0x15, g->f_126, g->f_12A);
            }
            g_Game_8013DEFC.f_815E = p[5];
            p[3] = 1;
            p[6] = g_Spike_8013DEFC.x;
            p[7] = g_Spike_8013DEFC.z;
        }
    } else {
        g_Spike_8013DEFC.x = p[6];
        g_Spike_8013DEFC.z = p[7];
        g_Spike_8013DEFC.f_38 = 0;
        g_Spike_8013DEFC.f_30 = 0;
    }
    return 0;
}

typedef struct { u8 pad_0[0x100]; s32 f_100; u8 pad_104[0x22]; u16 f_126; u8 pad_128[2]; u16 f_12A; u8 pad_12C[0x26]; u16 f_152; } GameHi_8013E014;
extern u8 g_Game_8013E014[] asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; s32 f_30; u8 pad_34[4]; s32 f_38; u8 pad_3C[0x1C]; s16 f_58; } g_Spike_8013E014 asm("g_Spike");

s32 func_8013E014(s16 *p) {
    u8 *base = g_Game_8013E014;
    GameHi_8013E014 *g = (GameHi_8013E014 *)(base + 0x8000);
    s32 id = p[2];

    if (p[3] == 0) {
        if (g_Spike_8013E014.f_58 == id && g->f_152 != 0xB) {
            Spike_SetPlayMode(0xB);
            g->f_100 = 6;
            Game_SetMode(0x17, g->f_126, g->f_12A);
            p[3] = 1;
            p[5] = g_Spike_8013E014.x;
            p[6] = g_Spike_8013E014.z;
        }
    } else {
        g_Spike_8013E014.x = p[5];
        g_Spike_8013E014.z = p[6];
        g_Spike_8013E014.f_38 = 0;
        g_Spike_8013E014.f_30 = 0;
    }
    return 0;
}

s32 func_8013E0E8(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (func_800978E0(M2C_FIELD(arg0, s16 *, 8)) != 0) {
        Model_BindStageMesh(g_StageMeshes + (M2C_FIELD(arg0, s16 *, 0xC) << 5), M2C_FIELD(arg0, s16 *, 0xE));
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E178 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; s32 f_30; u8 pad_34[4]; s32 f_38; u8 pad_3C[0x1C]; s16 f_58; } g_Spike_8013E178 asm("g_Spike");

s32 func_8013E178(s16 *p) {
    u8 *e = g_Game_8013E178.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (g_Spike_8013E178.f_58 == p[2] && func_800978E0(p[4]) != 0 && p[3] == 0) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 1;
            p[3] = 1;
            p[10] = g_Spike_8013E178.x;
            p[11] = g_Spike_8013E178.z;
        }
        break;
    case 1:
        g_Spike_8013E178.x = p[10];
        g_Spike_8013E178.z = p[11];
        g_Spike_8013E178.f_38 = 0;
        g_Spike_8013E178.f_30 = 0;
        break;
    }
    return 0;
}

s32 func_8013E280(s16 *p) {
    s32 n = p[4];

    if (func_8013E2DC() >= n) {
        Model_BindStageMesh(g_StageMeshes + p[6] * 32, p[7]);
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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013E334 asm("g_Game");
extern s16 D_800EC238_8013E334 asm("g_SpikeStandObj");
s32 Sound_PlayAt_8013E334() asm("Sound_PlayAt");

s32 func_8013E334(s16 *p) {
    s32 id = p[2];
    u8 *e = g_Game_8013E334.f_820C + id * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238_8013E334 == id && p[3] == 0) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 1;
            p[3] = 1;
        }
        break;
    case 1:
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 2;
            if (p[4] >= 0) {
                Sound_PlayAt_8013E334(p[4], e, id, p);
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}
