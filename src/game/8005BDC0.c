#include "game.h"

/* Large global block at 800EC350; the hot fields live past +0x8000. mode indexes D_800AFA30. */
extern struct S_D_800EC350 { u8 pad_0[0x8120]; u16 mode; u8 pad_8122[0x4]; u16 unk8126; u8 pad_8128[0x4]; u16 unk812C; } g_Game;

void SetVideoMode(s32 mode);
s32 VSync(s32 mode);
void System_Init(void);
void Cd_ReadFile(s32 id, s32 addr);
void Cd_WaitIdle(s32);
void Cd_StartFileLoad(s32, s32);
s32 func_800116C0(void);
void Cd_Update(void);

int main(void) {
    s32 unused[2];

    SetVideoMode(0);
    System_Init();
    g_Game.mode = 0;
    while (1) {
        if (D_800AFA30[g_Game.mode].overlay >= 0) {
            Cd_ReadFile(D_800AFA30[g_Game.mode].overlay, OVERLAY_ADDR);
            Cd_WaitIdle(0);
        }
        if (g_Game.mode == 13) {
            if (g_Game.unk812C == 21 || g_Game.unk812C == 30) {
                g_Game.unk8126 = 0x5B;
            } else {
                g_Game.unk8126 = 0x58;
            }
            Cd_StartFileLoad(1, g_Game.unk8126);
            while (func_800116C0() == 0) {
                Cd_Update();
                VSync(2);
            }
        }
        if (D_800AFA30[g_Game.mode].func() < 0) {
            break;
        }
        Cd_Update();
    }
    return 0;
}

s32 func_8005BEE4(void) {
    return 0;
}
