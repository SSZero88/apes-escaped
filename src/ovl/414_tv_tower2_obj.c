#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

extern struct S_D_80143F08 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80143F08[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 Boss_LoopVoiceA;
s32 Sound_Play(M2C_UNK, s32);
extern s32 Boss_LoopVoiceB;
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80143718;
extern M2C_UNK D_80144570;
extern M2C_UNK D_80144598;
extern M2C_UNK D_80143AF0;
M2C_UNK Camera_StartShake(M2C_UNK);
extern M2C_UNK D_80143D70;
extern s8 D_80143F04;

s32 LevelObj_RestartTimer(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[4]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; } g_Game_8013D014 asm("g_Game");
extern s32 D_800EC20C;
extern u16 D_800E69BE_8013D014 asm("D_800E69BE");
void Overlay_Request(s32);
s32 Overlay_GetState(void);
void Boss_Start(void);
void Music_Play(void);
void Sound_UnloadBanks(s32);
void Game_SetMode(s32, s32, s32);

s32 Boss_StartSequence(s16 *p) {
    if (g_Game_8013D014.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        if (D_800EC20C < -0x7FF) {
            return 0;
        }
        Overlay_Request(0);
        p[1] = 1;
        Sound_UnloadBanks(2);
        break;
    case 1:
        if (Overlay_GetState() != 0) {
            return 0;
        }
        p[1] = 3;
        Boss_Start();
        Music_Play();
        return 0;
    case 2:
        if (D_800EC20C < -0x7FF) {
            return 0;
        }
        p[1] = 3;
        Boss_Start();
        return 0;
    case 3:
        if (D_800E69BE_8013D014 == 1) {
            Overlay_Request(1);
            p[1] = 4;
            Sound_UnloadBanks(2);
        }
        break;
    case 4:
        if (Overlay_GetState() != 0) {
            return 0;
        }
        p[1] = 5;
        Music_Play();
        Game_SetMode(0x12, g_Game_8013D014.f_8126, g_Game_8013D014.f_812A);
        break;
    case 5:
        break;
    }
    return 0;
}

s32 Boss_LinkReached4(void) {
    return M2C_FIELD(g_Game.f_8220, s16 *, 0x1A) >= 4;
}

/* object types handled by this level: {init, update, draw}, zero-terminated */
s32 Switch_Init();
s32 ToggleSwitch_Update();
s32 SlideDoor_Init();
s32 SlideDoor_Update();
__asm__(".section .rodata\n\t.balign 16\n\t.section .text");
void *D_8013D1C0[12] = {
    Switch_Init, ToggleSwitch_Update, 0,
    LevelObj_RestartTimer, Boss_StartSequence, 0,
    SlideDoor_Init, SlideDoor_Update, 0,
    0, 0, 0,
};
