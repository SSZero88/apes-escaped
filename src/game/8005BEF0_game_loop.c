#include "game.h"
#include "m2c_macros.h"
#define GM_5BF70 ((struct Game_5BF70 *)&g_Game)
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_8005CB9C;
typedef struct { P_TAG_8005CB9C tag; u8 r0, g0, b0, code; s16 x0, y0, x1, y1, x2, y2, x3, y3; } POLY_F4_8005CB9C;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_8005CB9C;
typedef struct { s16 x; s16 y; void *items; } S_Menu;
typedef struct { u8 pad[0x24]; } S_7D23C;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u8 rest[0x4008]; } DB_5BF70_8005BF70;

extern struct S_D_800EC350 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8005CB9C db[2]; } g_Game;
extern u32 D_800F4610;

extern s32 D_800B000C;
extern s32 D_800B0174;
void func_8007D2D8(S_Menu *);
extern void *D_800B00EC;
extern S_7D23C D_800AFF10[];
extern u8 D_800F4614[];

extern M2C_UNK D_800AFEC8;
extern M2C_UNK *D_800B00C8;
extern M2C_UNK D_800B01BC;

void func_8005CA34(void);
M2C_UNK DebugItem_Init(M2C_UNK *, M2C_UNK *, M2C_UNK);
M2C_UNK func_8007D29C(M2C_UNK *, M2C_UNK *);
extern M2C_UNK D_800AFC1C;
extern struct S_D_800EC010 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; s32 f_20; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; s32 f_3C; s32 f_40; s32 f_44; } D_800EC010;
s32 func_8005CA84(void);

M2C_UNK func_8005E000(M2C_UNK, M2C_UNK);
extern void *D_800B0080;
extern struct S_D_800AFB68 { u8 pad[0x24]; } D_800AFB68[];
void func_8005CB9C(void);
struct Game_5BF70 { s32 f_0; s32 f_4; u32 *f_8; s32 f_C; DB_5BF70_8005BF70 db[2]; s32 f_8100; u8 pad8104[0x1C]; u16 f_8120; u16 f_8122; u16 f_8124; u16 f_8126; u8 pad8128[2]; u16 f_812A; u16 f_812C; u8 pad812E[6]; u16 f_8134; u16 f_8136; u8 pad8138[4]; u16 f_813C; u8 pad813E[0x12]; u16 f_8150; u16 f_8152; u8 pad8154[6]; u16 f_815A; u8 pad815C[2]; u16 f_815E; u8 pad8160[0x150]; s32 f_82B0; };
extern u16 g_RandSeed;
extern u16 D_800AE8F2;
extern s32 D_800A8A58;
extern u8 D_800AFB60[];
extern struct { u32 f_0; } g_GadgetState;
extern void (*D_800B4DCC)(s32);
extern void (*D_800B4DD0)(s32);
extern s32 D_800F5A90;
extern s32 D_800B97B0;
extern u32 D_800EC230;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad;
void Game_SetMode(s32, s32, s32);
void func_8005DDE0(void);
void func_8001325C(s32);
void Stage_UpdateAreaState(void);
s32 Pause_Update(void);
void Gfx_BeginFrame(void);
void func_8007D530(void);
void func_8008DF4C(void);
void Overlay_Update(void);
void func_8008C390(void);
s32 ScreenWipe_Update(void);
void Text_Draw(void *, s32, s32, s32);
void func_80047BD0(void);
void Light_SetColorMode(s32, s32, s32, s32);
void Spike_Draw(void);
void Spike_Update(void);
void Vehicle_UpdateSpikeOnTop(void);
void RcCar_Update(void);
void func_80099AE0(void);
void Projectile_Frame(void);
void Object_Frame(void);
void Monkey_UpdateFrame(void);
void func_8005ACE8(void);
void func_80043A8C(void);
void Pickup_Frame(void);
void Tip_DrawAll(void);
void func_80016F34(void);
void func_80069BEC(void);
void Fx_UpdateAll(void);
void CenterSign_Draw(void);
void Zone_UpdateAll(void);
void Link_UpdateArea(void);
void Spike_UpdateBlink(void);
void Collision_UpdateAll(void);
void func_8008686C(void);
void Hud_Draw(void);
void Tex_UpdateAnims(void);
s32 VSync(s32);
s32 func_8005DC78(void);
s32 func_8004D104(void);
void func_8007292C(void);
void func_8007F56C(s32);
void DrawSync(s32);
void PutDispEnv(void *);
void PutDrawEnv(void *);
void DrawOTag(void *);
s32 func_8007F5D4(void);
void func_8005DEE0(void *, void *, void *, s32);
void Gfx_WaitFlip(void);
void Sound_UnloadBanks(s32);
void Gadget_RestoreSlots(void);
void func_800963DC(s32, s32);
void func_8008745C(void);
void Record_UpdateBestTime(void);
void Save_StoreGame(void);
s32 Game_IsTimed(void);
void func_80095CEC(void);
void Minigame_Run(s32);
void func_80095D44(void);
void Tutorial_Complete(void);
void Tutorial_SetNextStage(void);
u16 World_FirstStage(s32);
void Cd_ReadFile(s32, void *);
void Cd_WaitIdle(s32);
void Sound_LoadBanks(s32);
void Cd_StartFileLoad(s32, s32);
s32 func_800116C0(void);
void Cd_Update(void);

typedef struct { s16 x, y, w, h; } R_8005BEF0;
extern R_8005BEF0 D_800A5740;
extern s32 D_800EBFC4;
extern s32 D_800EC35C;
extern u8 D_800E78C0[];
/* func_8005BEF0: (re)initialise the display: Gfx_InitDisplay, clear VRAM rect D_800A5740 to black,
 * reset the GTE matrix D_800E78C0 and clear D_800EBFC4 / D_800EC35C. Matches only with the callees
 * left undeclared here (with prototypes the registers of the struct copy shift by one). */
s32 func_8005BEF0(void) {
    R_8005BEF0 r = D_800A5740;
    Gfx_InitDisplay();
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    func_8004637C(D_800E78C0);
    D_800EBFC4 = 0;
    D_800EC35C = 0;
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5740);


/* The in-stage main loop. Per frame: advances the random seeds, runs the pause menu, Spike (or
 * the scripted player when g_Game+0x8100 bit 0 is set), the gadget callbacks, RC car and every
 * object subsystem, then swaps the draw buffers. Mode 6 (area change) only updates the area
 * load. When the screen wipe reports the stage is over it unloads, and from the mode that ended
 * the stage (g_Game+0x812C) chooses the next menu screen (g_Game+0x8120). */
s32 Game_MainLoop(void) {
    s32 r;
    u32 b;
    s32 a;
    s32 t;
    u16 k;
    void (*fn)(s32);

    func_8005BEF0();
    Game_SetMode(1, GM_5BF70->f_8126, 0);
    func_8005DDE0();
    for (;;) {
        func_8001325C(1);
        g_RandSeed = g_RandSeed * 5 + 1;
        D_800AE8F2 = D_800AE8F2 * 5 + 1;
        if ((u8)GM_5BF70->f_812C == 6) {
            Stage_UpdateAreaState();
        } else {
            switch (Pause_Update()) {
            case 3:
                Game_SetMode(7, GM_5BF70->f_8126, GM_5BF70->f_812A);
                break;
            case 2:
                Game_SetMode(0x1C, GM_5BF70->f_8126, GM_5BF70->f_812A);
                break;
            case 1:
                break;
            }
            Gfx_BeginFrame();
            func_8007D530();
            func_8008DF4C();
            Overlay_Update();
            (*(struct Game_5BF70 *)&g_Game).f_0++;
            func_8008C390();
            if (ScreenWipe_Update() < 0) {
                break;
            }
            if (D_800A8A58 != 0 && ((*(struct Game_5BF70 *)&g_Game).f_0 & 0x10)) {
                Text_Draw(D_800AFB60, 300, 210, 2);
            }
            func_80047BD0();
            Light_SetColorMode(1, 0, 0, 0);
            if (GM_5BF70->f_8100 & 1) {
                Spike_Draw();
            } else {
                Spike_Update();
            }
            if (g_GadgetState.f_0 & 0xC) {
                if (g_GadgetState.f_0 & 8) {
                    if (GM_5BF70->f_8150 == 3) {
                        goto skip;
                    }
                    fn = D_800B4DCC;
                } else {
                    if (GM_5BF70->f_8150 == 1) {
                        goto skip;
                    }
                    fn = D_800B4DD0;
                }
                fn(0);
                Vehicle_UpdateSpikeOnTop();
            }
        skip:
            if (D_800F5A90 != 0) {
                if (!(GM_5BF70->f_8100 & 1)) {
                    RcCar_Update();
                }
                func_80099AE0();
            }
            Projectile_Frame();
            Object_Frame();
            Monkey_UpdateFrame();
            func_8005ACE8();
            func_80043A8C();
            Pickup_Frame();
            Tip_DrawAll();
            func_80016F34();
            func_80069BEC();
            Fx_UpdateAll();
            CenterSign_Draw();
            Zone_UpdateAll();
            Link_UpdateArea();
            Spike_UpdateBlink();
            if (GM_5BF70->f_8150 != 8 && GM_5BF70->f_8150 != 0xD && !(GM_5BF70->f_8100 & 1)) {
                Collision_UpdateAll();
            }
            func_8008686C();
            Stage_UpdateAreaState();
            Hud_Draw();
            Tex_UpdateAnims();
            t = VSync(1) - GM_5BF70->f_82B0;
            D_800B97B0 = t;
            if (t <= 0) {
                D_800B97B0 = t + 0xFFFF;
            }
        }
        if (func_8005DC78() && !func_8004D104() && GM_5BF70->f_8152 != 0xB && (D_800EC230 >> 28) != 8) {
            b = g_Pad.f_160 & g_Pad.f_158;
            if (b & 0x800) {
                func_8007292C();
                a = 1;
                goto pause;
            }
            if ((b & 0x100) && GM_5BF70->f_8124 != 7 && GM_5BF70->f_8124 != 0xE) {
                func_8007292C();
                a = 10;
            pause:
                func_8007F56C(a);
                Sound_PlayFixed(2);
            }
        }
        if ((u8)GM_5BF70->f_812C == 6) {
            DrawSync(0);
            VSync(2);
            if (GM_5BF70->f_8136 != 0) {
                PutDispEnv((*(struct Game_5BF70 *)&g_Game).db[(*(struct Game_5BF70 *)&g_Game).f_C].disp);
                PutDrawEnv((*(struct Game_5BF70 *)&g_Game).db[(*(struct Game_5BF70 *)&g_Game).f_C].draw);
                GM_5BF70->f_8136 = 0;
            } else {
                PutDispEnv((*(struct Game_5BF70 *)&g_Game).db[GM_5BF70->f_8134].disp);
                PutDrawEnv((*(struct Game_5BF70 *)&g_Game).db[GM_5BF70->f_8134 ^ 1].draw);
            }
            DrawOTag((*(struct Game_5BF70 *)&g_Game).f_8 + 0xFFF);
            continue;
        }
        if (func_8007F5D4()) {
            *(*(struct Game_5BF70 *)&g_Game).f_8 |= 0xFFFFFF;
        }
        func_8005DEE0((*(struct Game_5BF70 *)&g_Game).db[(*(struct Game_5BF70 *)&g_Game).f_C].draw, (*(struct Game_5BF70 *)&g_Game).db[(*(struct Game_5BF70 *)&g_Game).f_C].disp, (*(struct Game_5BF70 *)&g_Game).f_8 + 0xFFF, 0);
    }
    Gfx_WaitFlip();
    if (GM_5BF70->f_8122 != 3) {
        Sound_UnloadBanks(1);
    }
    r = GM_5BF70->f_8126;
    if (r == 0x13 || r == 0x24 || (u32)(r - 0x5C) < 7) {
        Gadget_RestoreSlots();
    }
    switch (GM_5BF70->f_812C) {
    case 8:
        if (GM_5BF70->f_8122 == 3) {
            func_800963DC(GM_5BF70->f_8126, 8);
            func_8008745C();
        }
        Record_UpdateBestTime();
        Save_StoreGame();
        if (Game_IsTimed()) {
            if (GM_5BF70->f_8120 != 0x13 || GM_5BF70->f_8122 == 3) {
                GM_5BF70->f_8120 = 0x19;
            } else {
                GM_5BF70->f_8120 = 0x14;
            }
        } else {
            GM_5BF70->f_8120 = 0xC;
        }
        break;
    case 29:
        Save_StoreGame();
        GM_5BF70->f_8120 = 0x1E;
        break;
    case 9:
        GM_5BF70->f_813C = 5;
        Save_StoreGame();
        GM_5BF70->f_8120 = 0xF;
        break;
    case 21:
        func_80095CEC();
        Minigame_Run(GM_5BF70->f_815E);
        GM_5BF70->f_8120 = 0xD;
        break;
    case 30:
        func_80095CEC();
        GM_5BF70->f_8120 = 0x21;
        break;
    case 23:
        func_80095CEC();
        func_80095D44();
        GM_5BF70->f_8120 = 0x15;
        break;
    case 22:
        Tutorial_Complete();
        Save_StoreGame();
        Tutorial_SetNextStage();
        break;
    case 26:
        func_800963DC(GM_5BF70->f_8126, 0x1A);
        Save_StoreGame();
        func_8008745C();
        GM_5BF70->f_8120 = 0x19;
        break;
    case 7:
        if (GM_5BF70->f_8120 == 0xB) {
            Save_StoreGame();
        } else if (GM_5BF70->f_8120 == 0x13) {
            func_80095D44();
        } else if (GM_5BF70->f_8120 == 0x18) {
            func_800963DC(GM_5BF70->f_8126, 7);
            Save_StoreGame();
            GM_5BF70->f_8120 = 0xD;
            break;
        } else if (GM_5BF70->f_8120 == 0xD) {
            if ((u32)(GM_5BF70->f_8126 - 0x5C) < 7) {
                GM_5BF70->f_8120 = 0xD;
                break;
            }
            func_80095CEC();
        }
        GM_5BF70->f_8120 = 9;
        break;
    case 27:
        if (GM_5BF70->f_8120 == 0xB) {
            Save_StoreGame();
        } else if (GM_5BF70->f_8120 == 0x13) {
            func_80095D44();
        }
        GM_5BF70->f_8120 = 0x1A;
        GM_5BF70->f_815A = 3;
        break;
    case 31:
        func_80095CEC();
        GM_5BF70->f_8120 = 0x1A;
        GM_5BF70->f_815A = 8;
        break;
    case 28:
        func_80095D44();
        if ((u16)(GM_5BF70->f_8124 - 0x18) < 6) {
            GM_5BF70->f_8124 = 0x18;
        }
        k = GM_5BF70->f_8126 = World_FirstStage(GM_5BF70->f_8124);
        if (k == 0x13 || k == 0x24) {
            Sound_UnloadBanks(1);
            VSync(0);
            Cd_ReadFile(0x1B, (void *)0x80146000);
            Cd_WaitIdle(0);
            Sound_LoadBanks(2);
        }
        Cd_StartFileLoad(1, GM_5BF70->f_8126);
        while (!func_800116C0()) {
            Cd_Update();
            VSync(2);
        }
        break;
    case 32:
        GM_5BF70->f_8120 = 0x1A;
        GM_5BF70->f_815A = 2;
        break;
    case 34:
        GM_5BF70->f_8120 = 3;
        break;
    default:
        Save_StoreGame();
        GM_5BF70->f_8120 = 0xD;
        break;
    }
    DrawSync(0);
    VSync(0);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57B8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57BC);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57C0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57C4);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57C8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57D0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57D8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57E0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57E8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57F0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A57F8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5800);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5808);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5810);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5818);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5820);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5828);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5830);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5838);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5840);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5848);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5850);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5858);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5860);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5868);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5870);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5878);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5880);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5888);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5890);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A5898);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58A0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58A8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58B0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58B8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58C0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58C8);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58D0);
INCLUDE_RODATA("asm/nonmatchings/game/8005BEF0_game_loop", D_800A58D8);


s32 func_8005C98C(void) {
    func_8005E000(1, 0xFF00FF);
    return 0;
}

void func_8005C9B4(void) {
    S_Menu m;
    m.x = 0x14;
    m.y = 0x46;
    m.items = &D_800B000C;
    func_8007D2D8(&m);
    m.x = 0x10E;
    m.y = 0xBE;
    m.items = &D_800B0174;
    func_8007D2D8(&m);
}

void Sound_PlayFixed(void);

s32 func_8005CA14(void) {
    Sound_PlayFixed();
    return 0;
}

void func_8005CA34(void)
{
  M2C_UNK *new_var;
  new_var = &D_800AFEC8;
  D_800B00C8 = new_var;
  DebugItem_Init(&D_800AFEC8, &D_800B01BC, 1);
  new_var = &func_8005CA14;
  func_8007D29C(&D_800AFEC8, new_var);
}

s32 func_8005CA84(void) {
    D_800EC010.f_4 = 0xAD;
    D_800EC010.f_8 = -0x672;
    D_800EC010.f_C = -0x29E;
    D_800EC010.f_10 = -0x690;
    D_800EC010.f_14 = 0x500;
    D_800EC010.f_18 = 1;
    D_800EC010.f_1C = 0xC8;
    D_800EC010.f_20 = 0x780;
    D_800EC010.f_24 = 0x3F2;
    D_800EC010.f_28 = 0x64;
    D_800EC010.f_2C = 0x50;
    D_800EC010.f_30 = 0x3C;
    D_800EC010.f_34 = -0x76C;
    D_800EC010.f_38 = -0x15AE;
    D_800EC010.f_3C = -0x1158;
    D_800EC010.f_40 = -0x78;
    D_800EC010.f_44 = 0xA5A;
    return 1;
}

void func_8005CB1C(void) {
    M2C_UNK *var_s0;
    M2C_UNK *var_s1;
    u32 var_s2;

    var_s2 = 0;
    var_s1 = &D_800EC010;
    var_s0 = &D_800AFC1C;
    do {
        DebugItem_Init(var_s0, var_s1, 2);
        var_s1 = (void *)((u8 *)var_s1 + (4));
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x24));
    } while (var_s2 < 0x12U);
    func_8007D29C(&D_800AFC1C, &func_8005CA84);
    func_8005CA34();
}

void func_8005CB9C(void) {
    POLY_F4_8005CB9C *p = (POLY_F4_8005CB9C *)g_Game.prim;
    u32 *ot = &g_Game.db[g_Game.cur].ot[0xFFF];
    *(u32 *)&p->r0 = D_800F4610;
    p->tag.len = 5;
    p->code = 0x28;
    p->x0 = 0xA0;
    p->y0 = 0x72;
    p->x1 = 0xE0;
    p->y1 = 0x72;
    p->x2 = 0xA0;
    p->y2 = 0x7C;
    p->x3 = 0xE0;
    p->y3 = 0x7C;
    p->tag.addr = ((P_TAG_8005CB9C *)ot)->addr;
    ((P_TAG_8005CB9C *)ot)->addr = (u32)p;
    g_Game.prim = (u8 *)(p + 1);
}

void func_8005CC58(void)
{
  s32 i;
  void (*new_var2)(void);
  u8 *new_var;
  D_800B0080 = D_800AFB68;
  for (i = 0; 5 > i; i++)
  {
    new_var = &((u8 *)&D_800F4610)[i];
    new_var2 = func_8005CB9C;
    DebugItem_Init(&D_800AFB68[i], new_var, 3);
    if (1)
    {
      func_8007D29C(&D_800AFB68[i], new_var2);
    }
  }

}

void func_8005CCDC(void) {
    s32 i;
    D_800B00EC = D_800AFF10;
    for (i = 0; i < 6; i++) {
        DebugItem_Init(&D_800AFF10[i], &D_800F4614[i], 3);
    }
}
