#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_8005DF48;

M2C_UNK VSync(M2C_UNK);
extern struct S_D_800B97C0 { s16 f_0; u16 f_2; s32 f_4; s32 f_8; s32 f_C; s32 f_10; } D_800B97C0;

void* SetDefDispEnv(void* env, s32 x, s32 y, s32 w, s32 h);
void* SetDefDrawEnv(void* env, s32 x, s32 y, s32 w, s32 h);
void SetDispMask(s32 mask);
void SetGeomOffset(s32 ofx, s32 ofy);
extern M2C_UNK D_800EC360;
extern struct S_D_800EC350 { u8 pad_0[0x8104]; s32 f_8104; u8 pad_8108[0x24]; u8 f_812C; u8 pad_812D[0x13]; u32 f_8140; } g_Game;
extern struct S_D_800EC1E0 { u8 pad_0[0x30]; s32 f_30, f_34, f_38; u8 pad_3C[0x22]; u16 f_5E; u8 pad_60[0x10]; s32 f_70; u8 pad_74[0x6C]; u32 f_E0; } g_Spike;

void Gfx_WaitFlip(void);

void ResetCallback(void);
void InitGeom(void);
void Sound_Init(void);
void Sound_InitState(void);
s32 CdInit(void);
s32 func_800110B0(void);
void MemCard_Start(void);
void PadInitDirect(u8* pad1, u8* pad2);
void PadStartCom(void);
void func_8002F1F0(s32);
void func_80012CA0(s32);
void func_8008C01C(void);
void Gfx_InitProjection(void);
void DrawSyncCallback(void (*func)(void));
void VSyncCallback(void (*func)(void));
void Cd_InitFileTable(void);
void Timing_SampleHBlanks(void);
void Game_VSyncCallback(void);
extern u8 D_800E52D0[2][0x22]; /* controller buffers */
extern s32 D_800E54E0;

M2C_UNK DrawSync(M2C_UNK);
M2C_UNK PadStopCom();
M2C_UNK ResetGraph(M2C_UNK);
M2C_UNK StopCallback();
M2C_UNK StopRCnt(M2C_UNK);
M2C_UNK MemCard_Stop();
M2C_UNK Sound_Shutdown();
extern s16 g_TimerOn;
extern s16 g_ClockStopFrames;
extern s32 D_800A8A58;
void Gfx_VSyncFlip(void);
s32 TimeTrial_ClockRunning(void);
void func_8001300C(void);
void Seq_Tick(void);
void func_80088578(void);
void PutDispEnv(void *);
void PutDrawEnv(void *);
void DrawOTag(void *);
void ClearOTagR(u32 *, s32);
struct S_D_800EC350_8005DF48 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8005DF48 db[2]; };
extern s32 g_FrameHBlanks;
extern struct S_D_800E3890 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; u8 pad1C[0x4C]; s32 f_68; } D_800E3890;
extern s32 D_800E3894;
extern u16 D_800EC23E;
struct Game_8005D890 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x22]; u16 stage; u8 pad8128[2]; u16 f_812A; u16 f_812C; u8 pad812E[4]; u16 f_8132; };
s32 Game_SetMode(s32, s32, s32);
void Cd_Update(void);
s32 Zone_CheckSpike(s32);
s32 Cd_GetAreaFileSector(s32);
void func_8007A14C(void);
s32 func_800116C0(void);
void func_80094F40(void);
void TimeLimit_Update(void);
void func_80095464(void);
void func_800954C4(void);
void func_800955C8(void);

void System_Init(void) {
    ResetCallback();
    InitGeom();
    Sound_Init();
    Sound_InitState();
    CdInit();
    func_800110B0();
    MemCard_Start();
    PadInitDirect(D_800E52D0[0], D_800E52D0[1]);
    PadStartCom();
    func_8002F1F0(0);
    func_80012CA0(0);
    func_8008C01C();
    Gfx_InitProjection();
    DrawSyncCallback(Timing_SampleHBlanks);
    VSyncCallback(Game_VSyncCallback);
    D_800E54E0 = 0;
    Cd_InitFileTable();
}

s32 func_8005CDFC(void) {
    return 0;
}

/* New game: resets the game state counters and starts the subsystems.
 */
INCLUDE_ASM("asm/nonmatchings/game/8005CD50", Game_NewGameReset);

void System_Shutdown(void) {
    DrawSync(0);
    Sound_Shutdown();
    MemCard_Stop();
    StopRCnt(0xF2000000);
    StopRCnt(0xF2000001);
    StopRCnt(0xF2000002);
    StopRCnt(0xF2000003);
    ResetGraph(3);
    PadStopCom();
    StopCallback();
}

void Game_VSyncCallback(void) {
    Gfx_VSyncFlip();
    if (TimeTrial_ClockRunning() != 0) {
        g_Game.f_8140++;
        if (g_Game.f_8140 > 359999) {
            g_Game.f_8140 = 359999;
        }
    }
    if (D_800A8A58 == 0) {
        func_8001300C();
    }
    Seq_Tick();
    func_80088578();
}

void Timing_SampleHBlanks(void)
{
  s32 t;
  g_FrameHBlanks = (t = VSync(1));
}

s32 Gfx_InitDisplay(void)
{
  void *temp_s2;
  void *temp_v0;
  void *new_var;
  SetGeomOffset(0xC0, 0x78);
  SetDefDrawEnv(&D_800EC360, 0, 0, 0x180, 0xF0);
  temp_s2 = (void *) (((u8 *) (&D_800EC360)) + 0x4078);
  SetDefDrawEnv(temp_s2, 0, 0x100, 0x180, 0xF0);
  SetDefDispEnv((void *) (((u8 *) (&D_800EC360)) + 0x5C), 0, 0x100, 0x180, 0xF0);
  SetDefDispEnv((void *) (((u8 *) (&D_800EC360)) + 0x40D4), 0, 0, 0x180, 0xF0);
  temp_v0 = &D_800EC360;
  temp_v0 = temp_v0 - 0x10;
  new_var = (void *) (((u8 *) (&D_800EC360)) + 0x7FF0);
  *((s8 *) (((s8 *) temp_v0) + 0x409E)) = 1;
  *((s8 *) (((s8 *) temp_v0) + 0x26)) = 1;
  *((s8 *) (((s8 *) temp_v0) + 0x40A0)) = 0;
  *((s8 *) (((s8 *) temp_v0) + 0x28)) = 0;
  *((s8 *) (((s8 *) temp_v0) + 0x40F4)) = 0;
  *((s8 *) (((s8 *) temp_v0) + 0x7C)) = 0;
  *((s16 *) (((s8 *) temp_v0) + 0x40EE)) = 0;
  *((s16 *) (((s8 *) temp_v0) + 0x76)) = 0;
  *((s16 *) (((s8 *) temp_v0) + 0x40F2)) = 0xF0;
  *((s16 *) (((s8 *) temp_v0) + 0x7A)) = 0xF0;
  *((s32 *) (((s8 *) temp_v0) + 0x4084)) = 0x801A8000;
  *((s32 *) (((s8 *) new_var) + 0xFC)) = 0x801D0000;
  *(((s8 *) (&D_800EC360)) + 0x19) = 0;
  *((s8 *) (((s8 *) (&D_800EC360)) + 0x1A)) = 0;
  *((s8 *) (((s8 *) (&D_800EC360)) + 0x1B)) = 0;
  *((s8 *) (((s8 *) temp_s2) + 0x19)) = 0;
  *((s8 *) (((s8 *) temp_s2) + 0x1A)) = 0;
  *((s8 *) (((s8 *) temp_s2) + 0x1B)) = 0;
  SetDispMask(1);
  return 0;
}

typedef struct { s16 x, y, w, h; } RECT_5D100;
struct Game_5D100 { u8 pad0[0xC]; u16 f_C; u8 padE[0x1A]; u8 f_28; u8 pad29[0x4077]; u8 f_40A0; u8 pad40A1[0x405F];
    s32 f_100; u8 pad104[0x1C]; u16 f_120; u16 f_122; u16 f_124; u16 f_126; u8 pad128[2]; u16 f_12A; u16 f_12C; u8 pad12E[2]; u16 f_130; u16 f_132; u16 f_134; u16 f_136; u8 pad138[4]; u16 f_13C; u8 pad13E[2]; s32 f_140; u8 pad144[0xC]; u16 f_150; u8 pad152[6]; u16 f_158; u8 pad15A[0xC]; u16 f_166; };
#define GB ((struct Game_5D100 *)&g_Game)
#undef G
#define G ((struct Game_5D100 *)&g_Game)
extern s32 D_800E38A0;
extern s32 D_800E3898;
extern s16 g_ClockStopFrames;
extern s16 g_SpikeHealth;
struct Spk_5D100 { u8 pad0[0x30]; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0xB6]; u8 f_F2; u8 f_F3; };
#define SPK_5D100 ((struct Spk_5D100 *)&g_Spike)
void func_8005DD28(void);
void Stage_Begin(s32);
void Spike_Init(void);
void func_80031B60(s32, s32);
void Spike_SetPlayMode(s32);
void ClearImage(RECT_5D100 *, s32, s32, s32);
void func_8005DD18(void);
void Area_Enter(s32);
void Sound_UnloadBanks(s32);
s32 func_80086F00(s32, s32);
void func_8008745C(void);
void Sound_PlayFixed(s32);
void func_80094F20(void);
void Stage_StartTimerAndMusic(void);
void SaveByte_Set(s32, s32);
void Stage_SaveStatus(void);
void func_8008760C(void);
void Camera_ExitLook(void);
void Camera_ExitAim(void);
void func_80097BFC(void);
void Stage_StoreClearState(s32);
void Cd_SeekAreaFile(s32);
void Area_SaveProgress(s32);
s32 Stage_PairInSharedSet(s32, s32);
void Cd_ReadCurrentFile(void);
void Gfx_WaitFlip(void);
void func_8009543C(void);
void func_8009546C(void);
void Cd_PlayXaTrack(s32);
void func_80095588(void);
void func_8013EA24(void);
s32 Game_SetMode(s32 mode, s32 stage, s32 area) {
    s32 a1;
    s32 a2;
    RECT_5D100 r = { 0, 0, 0x180, 0x200 };

    if ((u8)G->f_12C == 0x20 || (u8)G->f_12C == 0x22) {
        return 0;
    }
    G->f_12C = mode;
    switch ((u8)mode) {
    case 1:
        D_800E3890.f_4 = -1;
        D_800E3890.f_8 = 0;
        D_800E3890.f_10 = -1;
        func_8005DD28();
        g_ClockStopFrames = 0;
        G->f_140 = 0;
        if (G->f_126 != 0x56) {
            Stage_Begin(stage);
            Spike_Init();
        }
        func_80031B60(stage, area);
        G->f_130 = 1;
        G->f_132 = 0x30;
        if (G->f_122 == 3) {
            break;
        }
        if (G->f_126 == 0x4E) {
            break;
        }
        if (G->f_126 == 0x56) {
            break;
        }
        if (G->f_124 == 0x21) {
            break;
        }
        Spike_SetPlayMode(0xC);
        break;
    case 2:
        ClearImage(&r, 0, 0, 0);
        DrawSync(0);
        func_8005DD18();
        Area_Enter(stage);
        if (stage == 0x35 || stage == 0x18) {
            Sound_UnloadBanks(2);
        }
        if (func_80086F00(stage, G->f_126)) {
            Sound_UnloadBanks(3);
        }
        if ((u32)(stage - 0x36) < 2 || stage == 0x19 || stage == 0x49) {
            func_8008745C();
        }
        func_80031B60(stage, area);
        G->f_130 = 4;
        G->f_132 = 0x18;
        Sound_PlayFixed(0x7B);
        break;
    case 13:
        func_8005DD18();
        g_ClockStopFrames = 0;
        Area_Enter(stage);
        if (stage != 0x35 && stage != 0x18 && stage != 0x57 && stage != 0x48) {
            func_8008745C();
        }
        Spike_Init();
        func_80031B60(stage, area);
        GB->f_40A0 = 0;
        GB->f_28 = 0;
        G->f_130 = 1;
        G->f_132 = 0x30;
        break;
    case 24:
        func_80094F20();
        break;
    case 25:
        Stage_StartTimerAndMusic();
        break;
    case 27:
        SaveByte_Set(10, 5);
    case 7:
        Stage_SaveStatus();
    case 21:
    case 23:
    case 28:
    case 30:
        if ((u8)mode != 0x1B) {
            Spike_SetPlayMode(0xD);
            G->f_100 = 6;
        } else {
            Spike_SetPlayMode(0xB);
        }
    case 26:
    case 31:
    case 32:
    case 34:
        func_8008760C();
        G->f_130 = 2;
        G->f_132 = 0;
        Camera_ExitLook();
        Camera_ExitAim();
        if ((u8)mode == 0x20 || (u8)mode == 0x22) {
            Spike_SetPlayMode(0xB);
        }
        break;
    case 29:
        func_80097BFC();
        Stage_StoreClearState(G->f_124);
    case 22:
        G->f_100 = -1;
        SPK_5D100->f_38 = 0;
        SPK_5D100->f_34 = 0;
        SPK_5D100->f_30 = 0;
        func_8008760C();
        G->f_130 = 2;
        G->f_132 = 0;
        break;
    case 9:
        func_8008760C();
        if (++G->f_158 >= 0x100) {
            G->f_158 = 0xFF;
        }
    case 8:
        if (G->f_124 == 0x21) {
            Game_SetMode(0x20, G->f_126, G->f_12A);
            break;
        }
        if ((u8)mode == 8) {
            Stage_StoreClearState(G->f_124);
        }
        Stage_SaveStatus();
        G->f_130 = 2;
        G->f_132 = 0;
        break;
    case 3:
    case 12:
        D_800E3890.f_4 = -1;
        D_800E3890.f_10 = -1;
        break;
    case 4:
        D_800E38A0 = -1;
        Cd_SeekAreaFile(stage);
        break;
    case 6:
        func_8005DD28();
        Area_SaveProgress(stage);
        if (Stage_PairInSharedSet((s16)G->f_126, (s16)stage)) {
            Sound_UnloadBanks(1);
        }
        Sound_PlayFixed(0x7B);
        Cd_ReadCurrentFile();
        G->f_132 = 0;
        if (G->f_150 == 1) {
            SPK_5D100->f_F2 = SPK_5D100->f_F3;
        }
        Gfx_WaitFlip();
        G->f_136 = 1;
        G->f_134 = GB->f_C;
        break;
    case 10:
        func_8005DD28();
        if (G->f_124 == 0x21) {
            Game_SetMode(0x20, G->f_126, G->f_12A);
            break;
        }
        if (G->f_122 == 3) {
            Game_SetMode(0x1A, G->f_126, G->f_12A);
            break;
        }
        if ((u16)(G->f_124 - 0x1F) >= 2 && G->f_120 != 0x13) {
            G->f_13C--;
        }
        if (G->f_120 == 0x13) {
            func_8005DD44(10);
        }
        GB->f_40A0 = 1;
        GB->f_28 = 1;
        if (G->f_13C == 0) {
            Game_SetMode(9, G->f_126, G->f_12A);
            break;
        }
        D_800E3898 = 0;
        Game_SetMode(0xB, G->f_126, G->f_12A);
        break;
    case 11:
        func_8005DD28();
        D_800E3890.f_4 = -1;
        D_800E3890.f_8 = 0;
        D_800E3890.f_10 = -1;
        Area_SaveProgress(stage);
        func_8008760C();
        g_SpikeHealth = 0;
        G->f_130 = 3;
        G->f_132 = 0;
        Cd_SeekAreaFile(stage);
        break;
    case 16:
        G->f_166++;
        Spike_SetPlayMode(8);
        break;
    case 17:
        Game_SetMode(3, G->f_126, G->f_12A);
        break;
    case 18:
        func_8005DD28();
        func_80097BFC();
        func_8009543C();
        break;
    case 19:
        Spike_SetPlayMode(9);
        func_8009546C();
        Cd_PlayXaTrack(0x39);
        break;
    case 20:
        func_80095588();
        break;
    case 33:
        func_8013EA24();
        G->f_100 = 1;
        break;
    }
    return 0;
}

#undef G
#undef GB


/* Stage sub-state machine, run every frame (state g_Game+0x812C: low byte = state, 0x6000 =
 * flags passed on, 0x8000/0x4000 = reset request). In states 3-5 a Spike state 0x23/0x4A/0x2D
 * restarts the area (Game_SetMode(0xA)). State 3: when Spike enters an exit zone
 * (Zone_CheckSpike(0) = (dest << 8) | sub) goes to 4, or 5 if that area is already loaded.
 * 4: waits in the zone (stops Spike on zone kind 1), then 5 or 4 again; leaving the zone goes
 * back to 3. 5: on reaching the inner zone (Zone_CheckSpike(1)) starts loading it (state 6).
 * 6: counts frames (+0x8132) and polls the load (D_800E3890+8), then enters the new area
 * (state 2). States 18, 19, 24, 25 run func_80095464, func_800954C4, func_80094F40 and
 * TimeLimit_Update; 20 sets Spike flag 0x20 and calls func_800955C8. Returns 0. */
s32 Stage_UpdateAreaState(void) {
    s32 flags;
    s32 z;
    if ((u32)((u8)(*(struct Game_8005D890 *)&g_Game).f_812C - 3) < 3) {
        if (D_800EC23E == 0x23 || D_800EC23E == 0x4A || D_800EC23E == 0x2D) {
            Game_SetMode(0xA, (*(struct Game_8005D890 *)&g_Game).stage, (*(struct Game_8005D890 *)&g_Game).f_812A);
        }
    }
    Cd_Update();
    if (((*(struct Game_8005D890 *)&g_Game).f_812C & 0xC000) && D_800E3890.f_0 == 0) {
        D_800E3890.f_4 = -1;
        D_800E3890.f_10 = -1;
        D_800E3890.f_8 = 0;
        (*(struct Game_8005D890 *)&g_Game).f_812C &= 0x7FFF;
    }
    flags = (*(struct Game_8005D890 *)&g_Game).f_812C & 0x6000;
    switch ((*(struct Game_8005D890 *)&g_Game).f_812C & 0xFF) {
    case 3:
        z = Zone_CheckSpike(0);
        if (z >= 0) {
            if (D_800E3890.f_4 < 0) {
                D_800E3890.f_4 = 0;
                D_800E3890.f_14 = z;
                if (D_800E3890.f_10 == Cd_GetAreaFileSector(z >> 8)) {
                    Game_SetMode(flags | 5, z >> 8, z & 0xFF);
                } else {
                    Game_SetMode(flags | 4, z >> 8, z & 0xFF);
                }
            }
        } else {
            D_800E3894 = -1;
        }
        break;
    case 4:
        z = Zone_CheckSpike(0);
        if (z < 0 || D_800E3890.f_14 != z) {
            D_800E3894 = -1;
            Game_SetMode(flags | 3, (*(struct Game_8005D890 *)&g_Game).stage, (*(struct Game_8005D890 *)&g_Game).f_812A);
            break;
        }
        if (Zone_CheckSpike(1) >= 0) {
            (*(struct Game_8005D890 *)&g_Game).f_8100 = -1;
            g_Spike.f_38 = 0;
            g_Spike.f_34 = 0;
            g_Spike.f_30 = 0;
        }
        if (D_800E3890.f_0 != 0) {
            break;
        }
        if (D_800E3890.f_68 == D_800E3890.f_18) {
            D_800E3890.f_8 = 0;
            D_800E3890.f_10 = Cd_GetAreaFileSector(z >> 8);
            Game_SetMode(flags | 5, z >> 8, z & 0xFF);
        } else {
            D_800E3890.f_4 = 0;
            Game_SetMode(flags | 4, z >> 8, z & 0xFF);
        }
        break;
    case 5:
        z = Zone_CheckSpike(0);
        if (z < 0 || D_800E3890.f_14 != z) {
            D_800E3894 = -1;
            Game_SetMode(flags | 3, (*(struct Game_8005D890 *)&g_Game).stage, (*(struct Game_8005D890 *)&g_Game).f_812A);
            break;
        }
        z = Zone_CheckSpike(1);
        if (z < 0) {
            break;
        }
        D_800E3890.f_C = z;
        Game_SetMode(6, z >> 8, z & 0xFF);
        break;
    case 6:
        (*(struct Game_8005D890 *)&g_Game).f_8132++;
        func_8007A14C();
        switch (D_800E3890.f_8) {
        case 0:
        case 1:
            if (func_800116C0() < 0) {
                D_800E3890.f_8 = 2;
            }
            break;
        case 2:
            Game_SetMode(2, D_800E3890.f_C >> 8, D_800E3890.f_C & 0xFF);
            D_800E3890.f_4 = -1;
            D_800E3890.f_8 = 0;
            D_800E3890.f_10 = -1;
            break;
        }
        break;
    case 24:
        func_80094F40();
        break;
    case 25:
        TimeLimit_Update();
        break;
    case 18:
        func_80095464();
        break;
    case 19:
        func_800954C4();
        break;
    case 20:
        g_Spike.f_E0 |= 0x20;
        if (D_800E3890.f_0 == 0) {
            func_800955C8();
        }
        break;
    case 1:
    case 33:
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005CD50", jtbl_800A5970_pad);


s32 func_8005DC78(void) {
    if ((u32)(g_Game.f_812C - 3) < 3) {
        if (g_Spike.f_5E != 0x23 && g_Spike.f_5E != 0x4A && g_Spike.f_5E != 0x2D
            && (g_Spike.f_70 & 0xF0) != 0xE0) {
            return 1;
        }
    }
    return 0;
}


/* 1 unless the game mode (g_Game+0x812C) is leaving the stage from the pause menu (7 or 0x1C). */
s32 Game_NotExiting(void) {
    u8 m = g_Game.f_812C;
    if (m != 7 && m != 0x1C) {
        return 1;
    }
    return 0;
}

void func_8005DD18(void) {
    g_TimerOn = 1;
}

void func_8005DD28(void) {
    g_TimerOn = 0;
}

s16 func_8005DD34(void) {
    return g_ClockStopFrames;
}

void func_8005DD44(s16 arg0) {
    g_Game.f_8140 = (s32) (g_Game.f_8140 + (arg0 * 0x3C));
}

/* Probably Time Trial (game mode 0x13; the user: every normal stage can be replayed against monkey
   and time targets): each energy chip collected stops the clock for 60 frames (1 s). */
void TimeTrial_AddClockStop(s16 arg0) {
    g_ClockStopFrames += arg0 * 0x3C;
}

/* 0 while the clock is stopped by chips (counting the stop down), else g_TimerOn (clock on). */
s32 TimeTrial_ClockRunning(void) {
    if ((g_TimerOn != 0) && (g_ClockStopFrames != 0)) {
        g_ClockStopFrames = (u16) g_ClockStopFrames - 1;
        return 0;
    }
    return g_TimerOn;
}

void func_8005DDE0(void) {
    D_800B97C0.f_2 = 0;
    D_800B97C0.f_0 = 0;
}

void Gfx_VSyncFlip(void) {
    s32 n = (u16)D_800B97C0.f_0 + 1;
    if (D_800B97C0.f_2 == 0) {
        D_800B97C0.f_0 = n;
        return;
    }
    if (n >= 2) {
        PutDispEnv((void *)D_800B97C0.f_8);
        PutDrawEnv((void *)D_800B97C0.f_4);
        DrawOTag((void *)D_800B97C0.f_C);
        if (D_800B97C0.f_10 != 0) {
            DrawOTag((void *)D_800B97C0.f_10);
        }
        n = 0;
        D_800B97C0.f_2 = 0;
    }
    D_800B97C0.f_0 = n;
}

void Gfx_WaitFlip(void) {
    if (D_800B97C0.f_2 != 0) {
        do {
            VSync(0);
        } while (D_800B97C0.f_2 != 0);
    }
    DrawSync(0);
}

void func_8005DEE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_WaitFlip();
    D_800B97C0.f_4 = arg0;
    D_800B97C0.f_8 = arg1;
    D_800B97C0.f_C = arg2;
    D_800B97C0.f_10 = arg3;
    D_800B97C0.f_2 = 1;
}

void Gfx_BeginFrame(void)
{
  u8 *new_var;
  DrawBuf_8005DF48 *p;
  s32 b = ((struct S_D_800EC350_8005DF48 *)&g_Game)->cur ^ 1;
  p = &((struct S_D_800EC350_8005DF48 *)&g_Game)->db[b];
  ((struct S_D_800EC350_8005DF48 *)&g_Game)->cur = b;
  new_var = p->prims;
  ((struct S_D_800EC350_8005DF48 *)&g_Game)->ot = p->ot;
  ((struct S_D_800EC350_8005DF48 *)&g_Game)->prim = new_var;
  p->term = 0xFFFFFF;
  ClearOTagR(p->ot, 0x1000);
  p->ot[0] = (p->ot[0] & 0xFF000000) | (((u32) (&p->term)) & 0xFFFFFF);
}

s32 func_8005DFDC(void) {
    return g_Game.f_8104;
}
