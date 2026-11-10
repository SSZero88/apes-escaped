#include "common.h"
#include "m2c_macros.h"

extern s32 g_StageMeshes;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xB6]; s32 f_820C; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
M2C_UNK Effect_Spawn(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK);
extern M2C_UNK Fx_SpikeChestPos;
extern M2C_UNK D_80141640;
extern struct S_D_80141880 { u8 pad_0[0x2]; u16 f_2; s16 f_4; u8 pad_6[0x2]; s16 f_8; u8 pad_A[0x6]; s32 f_10; s32 f_14; } D_80141880;
extern struct S_g_Spike { u8 pad_0[0x2C]; s32 f_2C; s32 f_30; u8 pad_34[0x4]; s32 f_38; } g_Spike;

extern struct S_D_80142368 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80142368[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142728;
s32 Sound_Play(M2C_UNK, s32);
extern M2C_UNK D_80141D20;
extern M2C_UNK D_801421C0;
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
        M2C_FIELD(((temp_a0 << 5) + g_StageMeshes), s16 *, 0x16) = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013D06C asm("g_Game");
extern u8 *D_800B4D64_8013D06C asm("g_StageMeshes");
extern s32 D_800EC204;
extern u16 D_800E69BE_8013D06C asm("D_800E69BE");
s32 Overlay_GetState_8013D06C(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 Sound_UnloadBanks(s32);
s32 Music_SetVolume(s32, s32);
void func_8013EEB8(void);

s32 func_8013D06C(s16 *p) {
    u8 *e;

    switch (p[1]) {
    case 0:
        if (D_800EC204 >= -0x1BF) {
            p[1] = 1;
            p[3] = 0;
            e = g_Game_8013D06C.f_820C + p[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            if (p[6] >= 0) {
                M2C_FIELD(D_800B4D64_8013D06C + p[6] * 32, u16 *, 0x16) = 0xFFFF;
            }
            Music_SetVolume(2, 0x28);
            Overlay_Request(7);
        }
        break;
    case 1:
        if (Overlay_GetState_8013D06C() == 0) {
            Music_SetVolume(0, 0);
            p[1] = 3;
            func_8013EEB8();
        }
        break;
    case 2:
        if (D_800EC204 >= -0x1BF) {
            p[1] = 3;
            e = g_Game_8013D06C.f_820C + p[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            if (p[6] >= 0) {
                M2C_FIELD(D_800B4D64_8013D06C + p[6] * 32, u16 *, 0x16) = 0xFFFF;
            }
            func_8013EEB8();
        }
        break;
    case 3:
        if (D_800E69BE_8013D06C == 1) {
            p[1] = 4;
            e = g_Game_8013D06C.f_820C + p[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            if (p[6] >= 0) {
                M2C_FIELD(D_800B4D64_8013D06C + p[6] * 32, u16 *, 0x16) = 0;
            }
            Sound_UnloadBanks(2);
            Overlay_Request(8);
        }
        break;
    case 4:
        if (Overlay_GetState_8013D06C() == 0) {
            p[1] = 5;
        }
        break;
    case 5:
        break;
    }
    return 0;
}

int abs(int);
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D2A0 asm("g_Spike");
extern u8 *D_800B4D64_8013D2A0 asm("g_StageMeshes");
void Model_BindStageMesh(void *, s32);

s32 func_8013D2A0(s16 *p) {
    switch (p[1]) {
    case 0:
        if (abs(g_Spike_8013D2A0.x - 0x620) < 0x3A0 && abs(g_Spike_8013D2A0.y + 0xA00) < 0x100 && abs(g_Spike_8013D2A0.z + 0xDC0) < 0x1C0) {
            p[1] = 1;
            Model_BindStageMesh(D_800B4D64_8013D2A0 + p[6] * 32, p[7]);
        }
        break;
    case 1:
        if (!(abs(g_Spike_8013D2A0.x - 0x620) < 0x3A0 && abs(g_Spike_8013D2A0.y + 0xA00) < 0x100 && abs(g_Spike_8013D2A0.z + 0xDC0) < 0x1C0)) {
            p[1] = 0;
            Model_BindStageMesh(D_800B4D64_8013D2A0 + p[6] * 32, p[8]);
        }
        break;
    }
    return 0;
}

__asm__(".section .text\n.balign 16");

/* object types handled by this level: {init, update, draw}, zero-terminated */
s32 Link_InitNone();
__asm__(".section .rodata\n\t.balign 16\n\t.section .text");
void *D_8013D410[9] = {
    func_8013D000, func_8013D06C, 0,
    Link_InitNone, func_8013D2A0, 0,
    0, 0, 0,
};
