#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "game.h"
#include "common.h"
#define D_978FC (*(struct S_D_800EC350_800978FC *)&g_Game)
#define D_96E0C ((struct S_D_800EC350_80096E0C *)&g_Game)
#define SP_95030 ((struct Spike_80095030 *)&g_Spike)
#define GM_95030 ((struct Game_80095030 *)&g_Game)
#define GM_97820 ((struct Game_97820 *)&g_Game)
#define SV ((S_Save_80095B3C_80095B3C *)&g_SaveBlock)
typedef struct { u8 f_0; u8 f_1; u8 pad_2[0xE]; } S_Rec16;
typedef struct { u8 pad0[0x28]; u8 f_28[32]; u8 f_48[32]; u16 f_68[128]; u8 pad168[0x500]; u32 f_668; u32 f_66C[8]; u8 pad68C[4]; u32 f_690[32]; u8 pad710[0x90]; } S_Save_80098088;
typedef struct { u8 f_0; u8 f_1; u8 f_2; u8 f_3; u8 f_4; u8 pad_5[0xB]; } S_Rec16_80097D0C_80097D0C;
typedef struct { s32 f_0; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; } S_Info_80097D0C_80097D0C;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 f_3; u8 f_4; u8 pad5[0xB]; } Stage_966B4_800966B4;
typedef struct { s16 f_0; u8 pad2[0x26]; u8 f_28[32]; u8 f_48[32]; u16 f_68[128]; u8 pad168[0x18C]; u8 f_2F4[0x2F0]; u8 pad5E4[0x80]; s32 f_664; s32 f_668; s32 f_66C[8]; s32 f_68C; s32 f_690[32]; s32 f_710; u8 pad714[4]; s32 f_718; } S_Save_80095B3C_80095B3C;

extern u32 g_BestTimes[32];
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x1C]; u16 f_8120; u16 f_8122; u16 f_8124; s16 f_8126; u8 pad_8128[0x2]; u16 f_812A; u8 pad_812C[0x2]; s16 f_812E; u8 pad_8130[0x10]; u32 f_8140; u32 f_8144; u8 pad_8148[0x1E]; s16 f_8166; u8 pad_8168[0x2]; u16 f_816A; u8 pad_816C[0x1A]; s16 f_8186; s16 f_8188; u8 pad_818A[0x142]; s8 f_82CC; s8 f_82CD; } g_Game;
s32 SpecterCoin_IsCollected(s32);

extern u8 D_800DFC98[32];

M2C_UNK Game_SetMode(M2C_UNK, u16, u16);

extern u8 D_800DFC70[32];
extern u8 D_800DFC88;

extern M2C_UNK D_800DFDD8;
extern s32 D_800DFDD0;


M2C_UNK Spike_PlaceAtSpawn(M2C_UNK, s16, M2C_UNK);
M2C_UNK func_8004BC5C();
extern s16 D_800B37E0;
extern s16 D_800B37E2;
M2C_UNK Spike_SetState(M2C_UNK);
M2C_UNK Spike_SetPlayMode(M2C_UNK);
extern struct S_D_800EC1E0 { u8 pad_0[0xE0]; s32 f_E0; } g_Spike;
s32 func_8005FD80();
extern struct S_D_800F4DB0 { u8 pad_0[0x20]; s32 f_20; } D_800F4DB0;
extern s32 D_800E072C;

M2C_UNK func_8005ADF8();
M2C_UNK Link_SaveStates();
extern u32 D_800DFCC0[];

extern s16 D_800B3858[];

extern s16 D_800B3810[];

M2C_UNK func_8004D73C();
M2C_UNK func_8004BBF0();
M2C_UNK func_8008760C();
extern M2C_UNK g_SaveBlock;
extern M2C_UNK D_800E0030;
extern u8 D_800DF820[][8];
extern M2C_UNK D_800DFB70;
s32 func_80010CA4();
extern s32 D_800DFDF8;
extern s32 D_800DFDFC;
extern s32 D_800E0730;
extern s16 D_800B38B8;
extern s16 D_800E0010;
extern s32 D_800DFDCC;
extern u16 D_800DFFE0[];
extern struct S_D_800DFE00 { u8 pad[0x18]; } D_800DFE00[];
s32 Stage_GetWorld(s32);
s32 World_FirstStage(s32 i);
s32 Game_IsTimed();
void Save_GetCompletion(S_Save_80098088 *);
extern s16 D_800B37E6;
extern s16 D_800B37E4;
void Cd_PlayXaTrack(s32);
struct S_D_800EC350_80094F48 { u32 f_0; u8 pad4[0x80FC]; s32 f_8100; u8 pad8104[0x1E]; u16 f_8122; u16 f_8124; u16 f_8126; };
extern Monkey g_Monkeys[];
struct S_D_800DFE00 *func_80097E88(s32 a, s32 *out);
struct S_D_800EC350_80097504 { u8 pad_0[0x8126]; u16 f_8126; u16 f_8128; };
extern s16 D_800B38BA;
extern s16 D_800B38BC;
extern s16 D_800B37F0[];
s32 func_800978E0(s32 arg0);
s32 func_80096580(s32 arg0);
s32 func_800977BC(s32 a);
s32 func_80096514();
struct S_D_800EC350_800976B8 { u8 pad_0[0x8126]; u16 f_8126; };
struct S_D_800EC350_80097D0C { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0x44]; u16 f_8166; u8 pad_8168[2]; u16 f_816A; };
/* Best time for `stage`; stages 0x18..0x1D share one entry (see Record_UpdateBestTime). */
s32 Record_GetBestTime(s32 stage);
s32 func_800965EC(s32 arg0);
struct S_D_800EC350_800978FC { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[4]; u16 f_8126; };
s32 func_800976B8(s32 a, s32 b);
struct S_D_800EC350_800972E0 { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[4]; u8 f_812C; u8 pad_812D[0x3F]; u8 f_816C[8]; };
/* Starts level lvl: sets the world (+0x8122) and stage (+0x8124) for it, resets several
 * subsystems, and when lvl is the stage's first area (D_800B3858) loads the stage's monkey
 * setup: count (+0x8128) and counters from the stage table at 0x80102400, the monkey list from
 * the loaded stage header, and the caught flags per area (D_800DFE00; cleared in mode 0x13 except
 * stages 0x1B/0x1C, which take them from D_800DFF20). Stages 0x1F/0x20/0x22, world 3 and other
 * levels get no monkeys; stage 0x21 gets one (race). */
s32 Stage_Begin(s32 lvl);
void func_800848B0(void);
void func_80050AFC(void);
void func_8005AD90(void);
struct S_D_800EC350_80096E0C { u8 pad_0[0x8124]; u16 f_8124; u16 f_8126; u16 f_8128; u8 pad_812A[0x3C]; u16 f_8166; u8 pad_8168[4]; u8 f_816C[8]; };
void Monkey_UpdateSlotStatus(void);
struct S_D_800F4DB0_80095600 { u8 pad0[4]; s16 f_4; u8 pad6[6]; s16 f_C; s16 f_E; s16 f_10; u8 pad12[0xE]; s32 f_20; };
struct Game_800954C4 { u8 pad0[0x8126]; s16 stage; u8 pad8128[2]; u16 f_812A; };
struct Game_80095030 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x22]; u16 stage; u8 pad8128[2]; u16 f_812A; u16 mode; };
struct Spike_80095030 { u8 pad0[0x100]; s16 f_100; };
void Sound_PlayFixed(s32);
void CenterSign_ShowDigit(s32);
void func_8005DD18(void);
s32 func_80097620(void);
s32 func_80095600(s32 a, s32 b);
s32 func_80095244(s32 a);
void func_8005E42C(s32);
void Hud_DrawBigDigit(s32 x, s32 y, s32 n);
void Hud_DrawBigNumber(s32 x, s32 y, s32 n);
void Hud_DrawLivesIcon(s32 x, s32 y);
struct S_D_800EC350_80095690 { u8 pad_0[0x813C]; u16 f_813C; };
struct S_D_800F4DB0_80095690_80095690 { u8 pad_0[4]; s16 f_4; u8 pad_6[6]; s16 f_C; s16 f_E; s16 f_10; u8 pad_12[0xE]; s32 f_20; };
extern u8 D_800B38C0[];
struct Game_97820 { u8 pad0[0x8126]; u16 f_8126; };
void Gadget_Unlock(s32);
struct S_D_800F4DB0_800958C0 { s16 f_0; u8 pad2[0x1E]; s32 f_20; };
struct S_D_800F4DB0_80095244 { u8 pad0[8]; s16 f_8; s16 f_A; u8 padC[0x14]; s32 f_20; };
struct Game_966B4 { u8 pad0[0x8120]; u16 f_8120; u16 f_8122; u16 f_8124; u8 pad8126[2]; u16 f_8128; u8 pad812A[2]; u8 f_812C; u8 pad812D; u16 f_812E; u8 pad8130[0x2C]; u16 f_815C; u8 pad815E[2]; u16 f_8160; u8 pad8162[4]; u16 f_8166; u8 pad8168[4]; u8 f_816C[8]; u8 pad8174[0x12]; u16 f_8186; u16 f_8188; u16 f_818A; u8 *f_818C; };
extern u16 D_800B38AC[];
extern s32 D_801544CC;
extern u8 D_800DFF20[][24];
extern u8 D_800DFCB0;
void func_8003317C(void);
void func_800847C4(void);
void func_800509A4(void);
void func_80086148(void);
extern s16 D_800B389C[];
struct S_D_800EC350_80095B3C { u8 pad_0[0x8124]; u16 f_8124; u8 pad_8126[0x32]; u16 f_8158; };
void func_80095D44(void);
s32 func_80095CEC(void);

s32 func_80094F20(void) {
    func_8004D73C();
    return 0;
}

s32 func_80094F40(void) {
    return 0;
}

s32 Stage_StartTimerAndMusic(void) {
    D_800B37E6 = 0x5A;
    if (Game_IsTimed() == 0) {
        ((struct S_D_800EC350_80094F48 *)&g_Game)->f_8100 = 0;
        D_800B37E4 = 0;
    } else if (((struct S_D_800EC350_80094F48 *)&g_Game)->f_8122 != 3) {
        ((struct S_D_800EC350_80094F48 *)&g_Game)->f_8100 = 0;
        D_800B37E4 = 2;
    } else {
        D_800B37E4 = 1;
    }
    if (((struct S_D_800EC350_80094F48 *)&g_Game)->f_8124 != 0x1F && ((struct S_D_800EC350_80094F48 *)&g_Game)->f_8126 != 0x4E && ((struct S_D_800EC350_80094F48 *)&g_Game)->f_8126 != 0x56 && ((struct S_D_800EC350_80094F48 *)&g_Game)->f_8124 != 0x21) {
        Cd_PlayXaTrack(((struct S_D_800EC350_80094F48 *)&g_Game)->f_0 % 5 + 4);
    }
    return 0;
}

/* A countdown (state D_800B37E4, frames left D_800B37E6, 30 per second). While it runs it beeps
 * (sound 6) and shows the seconds left (CenterSign_ShowDigit(s + 1)) once a second; at 0 it plays
 * sound 7 and goes to state 3, which ends the stage via Game_SetMode(mode | 3, ...) and, when
 * func_80097620 says so, resets the HUD counters. State 0 first counts g_Spike+0x100 down;
 * state 2 counts it down alongside the timer. */
s32 TimeLimit_Update(void) {
    s32 t;
    switch (D_800B37E4) {
    case 0:
        if (--SP_95030->f_100 <= 0) {
            D_800B37E4 = 3;
        }
        break;
    case 2:
        t = SP_95030->f_100;
        if (t > 0) {
            t--;
            if (t == 0) {
                Spike_SetPlayMode(0);
                Spike_SetPlayMode(0xB);
            }
            SP_95030->f_100 = t;
        }
    case 1:
        if (D_800B37E6 == 0) {
            Sound_PlayFixed(7);
            CenterSign_ShowDigit(1);
            GM_95030->f_8100 = 0;
            D_800B37E4 = 3;
        } else if (D_800B37E6 % 30 == 0) {
            Sound_PlayFixed(6);
            CenterSign_ShowDigit(D_800B37E6 / 30 + 1);
        }
        D_800B37E6--;
        break;
    case 3:
        func_8005DD18();
        Game_SetMode((GM_95030->mode & 0x6000) | 3, GM_95030->stage, GM_95030->f_812A);
        Spike_SetPlayMode(0);
        if (func_80097620() != 0) {
            func_80095600(0, 0);
            func_80095244(0);
            func_8005E42C(0);
        }
        D_800B37E4 = 4;
        break;
    }
    return 0;
}

s32 func_80095244(s32 a) {
    struct S_D_800F4DB0_80095244 *p;

    p = ((struct S_D_800F4DB0_80095244 *)&D_800F4DB0);
    if (a == 0) {
        p->f_8 = 0x28;
    } else {
        p->f_8 = 0;
    }
    p = ((struct S_D_800F4DB0_80095244 *)&D_800F4DB0);
    if (a != 0) {
        p->f_A = 2;
    } else {
        p->f_A = 0;
    }
    ((struct S_D_800F4DB0_80095244 *)&D_800F4DB0)->f_20 |= 4;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80094F20_stage", func_8009529C);

INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A6780);
INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A6780_pad);


s32 func_8009543C(void) {
    func_8004BBF0();
    func_8008760C();
    return 0;
}

s32 func_80095464(void) {
    return 0;
}

s32 func_8009546C(void) {
    D_800B37E0 = 0x50;
    D_800B37E2 = 0;
    g_Game.f_8100 = 0;
    Spike_PlaceAtSpawn(1, g_Game.f_8126, 1);
    func_8004BC5C();
    return 0;
}

/* Per frame: Spike_PlaceAtSpawn(1, stage, 1); a small state machine in D_800B37E2 waits 80 frames
 * (counter D_800B37E0), then calls Game_SetMode(0x14, stage, g_Game+0x812A) each frame. */
s32 func_800954C4(void) {
    struct Game_800954C4 *g = (struct Game_800954C4 *)&(*(M2C_UNK *)&g_Game);
    Spike_PlaceAtSpawn(1, g->stage, 1);
    switch (D_800B37E2) {
    case 0:
        D_800B37E2 = 2;
        D_800B37E0 = 0x50;
        break;
    case 2:
        if (--D_800B37E0 < 0) {
            D_800B37E2 = 4;
        }
        break;
    case 4:
        Game_SetMode(0x14, (u16)g->stage, g->f_812A);
        break;
    }
    return 0;
}

s32 func_80095588(void) {
    Spike_SetPlayMode(0xB);
    Spike_SetState(0);
    g_Spike.f_E0 = (s32) (g_Spike.f_E0 | 0x20);
    return 0;
}

s32 func_800955C8(void) {
    Game_SetMode(8, g_Game.f_8126, g_Game.f_812A);
    return 0;
}

s32 func_80095600(s32 a, s32 b) {
    ((struct S_D_800F4DB0_80095600 *)&D_800F4DB0)->f_C = a ? 0 : 0x28;
    ((struct S_D_800F4DB0_80095600 *)&D_800F4DB0)->f_E = a ? 2 : 0;
    ((struct S_D_800F4DB0_80095600 *)&D_800F4DB0)->f_10 = b ? 0x34 : 0;
    ((struct S_D_800F4DB0_80095600 *)&D_800F4DB0)->f_4 = a ? -0x14 : 0;
    ((struct S_D_800F4DB0_80095600 *)&D_800F4DB0)->f_20 |= 8;
    return 0;
}

/* Lives counter at the bottom left (icon, "x", lives - 1 from g_Game+0x813C). D_800F4DB0.f_E
 * steps 0 -> 1 slide up (f_C -2 per frame) -> 2 hold 40 frames -> 3 slide down -> 4 done (clears
 * flag 8 of f_20). After a 1-up f_10 counts down: from 25 to 9 the old number blinks, below 9 the
 * new one bounces. f_4 gets the panel's offset for other HUD parts. Returns 0. */
s32 Hud_DrawLives(void) {
    s16 off = 0;
    s32 show;
    s16 y;
    u16 lives;
    s32 n;

    switch (((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_E) {
    case 0:
        ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_E = 1;
        off = ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C = 0x28;
        break;
    case 1:
        if ((((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C -= 2) < 0) {
            ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_E = 2;
            ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C = 0x28;
        } else {
            off = ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C;
        }
        break;
    case 2:
        if (--((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C < 0) {
            ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_E = 3;
            ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C = 0x28;
        }
        break;
    case 3:
        if ((((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C -= 2) < 0) {
            ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_E = 4;
        }
        off = 0x28 - ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_C;
        if (off < 0) {
            off = 0;
        }
        break;
    case 4:
        ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_20 &= ~8;
        return 0;
    }
    Hud_DrawBigDigit(0x34, off + 200, -1);
    show = 1;
    lives = ((struct S_D_800EC350_80095690 *)&g_Game)->f_813C;
    y = off + 200;
    n = lives - 1;
    if (((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10 != 0) {
        ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10--;
        n = lives - 2;
        if (((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10 < 9) {
            y = off + 199; y += (((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10 & 1) << 1;
            n = lives - 1;
        } else if (((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10 < 0x1A) {
            show = ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_10 & 2;
        }
    }
    if (show) {
        Hud_DrawBigNumber(0x4C, y, n);
    }
    Hud_DrawLivesIcon(0x14, off + 0xC0);
    ((struct S_D_800F4DB0_80095690_80095690 *)&D_800F4DB0)->f_4 = (off < 0x1C) ? off - 0x1C : 0;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A6798_pad);


s32 func_800958C0(s32 a) {
    s32 v;
    ((struct S_D_800F4DB0_800958C0 *)&D_800F4DB0)->f_20 |= 1;
    v = ((struct S_D_800F4DB0_800958C0 *)&D_800F4DB0)->f_0;
    if (a != 0) {
        ((struct S_D_800F4DB0_800958C0 *)&D_800F4DB0)->f_0 = 0x4B;
        return 0;
    }
    if (v < 0xE) {
        return 0;
    }
    if (v < 0x50) {
        ((struct S_D_800F4DB0_800958C0 *)&D_800F4DB0)->f_0 = 8;
        return 0;
    }
    ((struct S_D_800F4DB0_800958C0 *)&D_800F4DB0)->f_0 = 0;
    return 0;
}

s32 func_80095924(void) {
    if (func_8005FD80() != 0) {
        D_800F4DB0.f_20 = (s32) (D_800F4DB0.f_20 & ~1);
    }
    return 0;
}

typedef struct {
    u16 f_0; u8 pad2[0x16]; u8 f_18[16]; u8 f_28[32]; u8 f_48[32]; u16 f_68[0x80]; s32 f_168[0x63];
    u8 f_2F4[0x2F0]; u8 pad5E4[0xAC]; s32 f_690[32]; s32 f_710; s32 f_714; u8 pad718[0x7C]; s32 f_794;
} Save_80095960;
extern Save_80095960 g_SaveBlock_95960 asm("g_SaveBlock");
extern u8 D_800DF820_95960[][8] asm("D_800DF820");
extern u8 D_800DFC70_95960[32] asm("D_800DFC70");
extern u8 D_800DFC98_95960[32] asm("D_800DFC98");
extern s32 g_BestTimes_95960[] asm("g_BestTimes");
extern u32 D_800DFCC0_95960[] asm("D_800DFCC0");
extern u32 D_800DFDD8_95960[] asm("D_800DFDD8");
extern s32 D_800DFDCC_95960 asm("D_800DFDCC");
extern s32 D_800DFDD0_95960 asm("D_800DFDD0");
extern s32 D_800DFDF8_95960 asm("D_800DFDF8");
extern s32 D_800DFDFC_95960 asm("D_800DFDFC");
s32 func_800848C0_95960(void) asm("SpecterCoin_ClearAll");
s32 func_80095D44_95960(void) asm("func_80095D44");
/* func_80095960: reset all save data for a new game: per-stage tables (D_800DF820, monkeys caught,
 * stage states, best times = -1), then the save block itself (version 1, func_80095D44 status
 * word, flags, coin list = 0xFFFF, ...). The callees are declared returning s32 here: with void
 * prototypes the registers at the end shift (the original called them as int functions). */
s32 func_80095960(void) {
    s32 i, j;
    for (i = 0; i < 0x6A; i++) {
        for (j = 0; j < 8; j++) {
            D_800DF820_95960[i][j] = 0;
        }
    }
    for (i = 0; i < 0x23; i++) {
        D_800DFC70_95960[i] = 0;
        D_800DFC98_95960[i] = 0;
        g_BestTimes_95960[i] = -1;
    }
    func_800848C0_95960();
    g_SaveBlock_95960.f_0 = 1;
    func_80095D44_95960();
    for (i = 0; i < 0x10; i++) {
        g_SaveBlock_95960.f_18[i] = 0;
    }
    for (i = 0; i < 0x2f0; i++) {
        g_SaveBlock_95960.f_2F4[i] = 0;
    }
    for (i = 0; i < 0x20; i++) {
        g_SaveBlock_95960.f_28[i] = 0;
        g_SaveBlock_95960.f_48[i] = 0;
        g_SaveBlock_95960.f_690[i] = -1;
    }
    for (i = 0; i < 0x80; i++) {
        g_SaveBlock_95960.f_68[i] = 0xFFFF;
    }
    for (i = 0; i < 0x63; i++) {
        g_SaveBlock_95960.f_168[i] = 0;
    }
    g_SaveBlock_95960.f_710 = 0;
    g_SaveBlock_95960.f_714 = 0;
    g_SaveBlock_95960.f_794 = 0;
    for (i = 0; i < 0x20; i++) {
        D_800DFCC0_95960[i] = 0;
    }
    for (i = 0; i < 0x8; i++) {
        D_800DFDD8_95960[i] = 0;
    }
    D_800DFDCC_95960 = 0;
    D_800DFDD0_95960 = 0;
    D_800DFDF8_95960 = 0;
    D_800DFDFC_95960 = 0;
    return 0;
}


s32 Save_StoreGame(void) {
    s32 i;
    u8 *src;
    SV->f_0 = World_FirstStage(((struct S_D_800EC350_80095B3C *)&g_Game)->f_8124);
    SV->f_710 = ((struct S_D_800EC350_80095B3C *)&g_Game)->f_8158;
    func_80095D44();
    SV->f_668 = D_800DFDD0;
    for (i = 0; i < 128; i++) {
        SV->f_68[i] = ((u16 *)&D_800DFB70)[i];
    }
    if (Game_IsTimed() != 0) {
        for (i = 0; i < 32; i++) {
            SV->f_690[i] = g_BestTimes[i];
        }
        return 0;
    }
    func_80095CEC();
    src = (u8 *)D_800DF820;
    for (i = 0; i < 0x2F0; i++) {
        SV->f_2F4[i] = src[i];
    }
    for (i = 0; i < 32; i++) {
        SV->f_28[i] = D_800DFC70[i];
        SV->f_48[i] = D_800DFC98[i];
    }
    for (i = 0; i < 8; i++) {
        SV->f_66C[i] = ((s32 *)&D_800DFDD8)[i];
    }
    SV->f_664 = D_800DFDCC;
    SV->f_68C = D_800DFDF8;
    SV->f_718 = D_800DFDFC;
    return 0;
}

s32 func_80095CEC(void) {
    M2C_UNK *var_v1;
    s32 *var_a0;
    s32 temp_v0;
    s32 var_a1;

    func_8005ADF8();
    Link_SaveStates();
    var_a1 = 0;
    var_a0 = D_800DFCC0;
    var_v1 = &g_SaveBlock;
    do {
        temp_v0 = *var_a0;
        var_a0 = (void *)((u8 *)var_a0 + (4));
        var_a1 += 1;
        M2C_FIELD(var_v1, s32 *, 0x5E4) = temp_v0;
        var_v1 = (void *)((u8 *)var_v1 + (4));
    } while (var_a1 < 0x20);
    return 0;
}

typedef struct { u8 pad0[2]; u16 f_2; s32 f_4; s32 f_8; u32 f_C; u32 f_10; u32 f_14; } S_80095D44;
typedef struct { u8 f_0; u8 pad1[3]; u8 f_4; u8 pad5[3]; } T_80095D44;
extern S_80095D44 g_SaveBlock_95D44 asm("g_SaveBlock");
extern struct { u8 pad_0[0x8138]; u8 f_8138; u8 pad_8139; u16 f_813A; u16 f_813C; u8 pad_813E[0x16]; u16 f_8154; u8 f_8156; u8 pad_8157[0x11]; u16 f_8168; } g_Game_95D44 asm("g_Game");
extern struct { u8 pad0[0x88]; s32 f_88; u8 pad8C[0x15]; u8 f_A1; u8 f_A2; u8 padA3; s32 f_A4; } g_GadgetState_95D44 asm("g_GadgetState");
extern s8 g_CurrentGadget_95D44 asm("g_CurrentGadget");
s32 func_800864B4_95D44(T_80095D44 *) asm("func_800864B4");
s32 func_80095D44_(void) asm("func_80095D44");
/* func_80095D44: store the current game state in the save block header: +0x14 = two bytes from
 * func_800864B4 (<< 16 / << 24) | flag 1 (g_Game+0x813A) | flag 2 (+0x8138); +2 = +0x813C (lives?)
 * | +0x8168 << 8; +4/+8 gadget state words; +0xC = current gadget << 16 | gadget bytes +0xA1/+0xA2;
 * +0x10 = g_Game+0x8154 << 8 | +0x8156. func_800864B4 must be declared returning int. */
s32 func_80095D44_(void) {
    S_80095D44 *s = &g_SaveBlock_95D44;
    T_80095D44 t;

    s->f_14 = 0;
    func_800864B4_95D44(&t);
    s->f_14 |= (t.f_0 << 16) & 0xFF0000;
    s->f_14 |= (t.f_4 << 24) & 0xFF000000;
    if (g_Game_95D44.f_813A != 0) {
        s->f_14 |= 1;
    }
    if (g_Game_95D44.f_8138 != 0) {
        s->f_14 |= 2;
    }
    s->f_2 = g_Game_95D44.f_813C | (g_Game_95D44.f_8168 << 8);
    s->f_4 = g_GadgetState_95D44.f_A4;
    s->f_8 = g_GadgetState_95D44.f_88;
    s->f_C = ((g_CurrentGadget_95D44 << 16) & 0xFF0000) | (g_GadgetState_95D44.f_A1 << 8) | g_GadgetState_95D44.f_A2;
    s->f_10 = ((g_Game_95D44.f_8154 << 8) & 0xFF00) | g_Game_95D44.f_8156;
    return 0;
}


s32 func_80095E4C(void) {
    D_800E072C = (g_Game.f_82CC << 0x10) | (g_Game.f_82CD & 0xFFFF);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80094F20_stage", func_80095E80);

/* Keeps the best time for the current stage (stages 0x18..0x1D share one entry)
 * and leaves the previous record for the results screen.
 */
s32 Record_UpdateBestTime(void) {
    if (Game_IsTimed() == 0) {
        return 0;
    }
    if (g_Game.f_8124 >= 0x18 && g_Game.f_8124 < 0x1E) {
        g_Game.f_8144 = g_BestTimes[24];
        if (g_Game.f_8140 < g_BestTimes[24]) {
            g_BestTimes[24] = g_Game.f_8140;
        }
        return 0;
    }
    g_Game.f_8144 = g_BestTimes[g_Game.f_8124];
    if (g_Game.f_8140 < g_BestTimes[g_Game.f_8124]) {
        g_BestTimes[g_Game.f_8124] = g_Game.f_8140;
    }
    return 0;
}

M2C_UNK *func_8009628C(void) {
    return &g_SaveBlock;
}

M2C_UNK *func_80096298(void) {
    return &D_800E0030;
}

M2C_UNK *func_800962A4(void) {
    return (M2C_UNK *)D_800DF820;
}

s32 Save_SumStageMonkeys(u8 *p)
{
  s32 sum;
  s32 i;
  if (p == 0)
  {
    p = D_800DFC98;
  }
  sum = 0;
  for (i = sum; i < 0x19; i++)
  {
    sum += p[i];
  }

  return sum;
}

M2C_UNK *func_800962E8(void) {
    return &D_800DFB70;
}

s32 SaveFlag_Set(s32 a) {
    D_800DFCC0[(s16)(a >> 5)] |= 1 << (a & 0x1F);
    return 0;
}

s32 SaveFlag_Test(s32 arg0) {
    return (D_800DFCC0[(s16)(arg0 >> 5)] & (1 << (arg0 & 0x1F))) != 0;
}

s32 SaveByte_Set(s32 arg0, s32 arg1)
{
  s32 *temp_a0;
  s32 temp_a2;
  u8 *new_var2;
  int new_var;
  new_var = arg0 & 3;
  new_var2 = (u8 *) (&D_800DFDD8);
  temp_a0 = (void *) (new_var2 + (arg0 & 0x3FFFC));
  temp_a2 = new_var * 8;
  *temp_a0 = ((*temp_a0) & (~(0xFF << temp_a2))) | ((arg1 & 0xFF) << temp_a2);
  return 0;
}

s32 SaveByte_Get(s32 arg0)
{
  int new_var2;
  u32 new_var;
  new_var2 = (arg0 & 3) * 8;
  return (new_var = ((u32 *)&D_800DFDD8)[(u16) (arg0 >> 2)] >> new_var2) & 0xFF;
}

s32 func_800963DC(s32 a, s32 b) {
    u16 v;
    if (a == 0x13) {
        v = 1;
        if (b == 8) {
            if (!(D_800DFDD0 & 0x10)) {
                g_Game.f_816A += 5;
                v = 9;
            }
            v |= 0x10;
        }
        D_800DFDD0 &= 0xFFF7;
    } else {
        v = 0x100;
        if (b == 8) {
            if (!(D_800DFDD0 & 0x1000)) {
                g_Game.f_816A += 5;
                v = 0x900;
            }
            v |= 0x1000;
        }
        D_800DFDD0 &= 0xF7FF;
    }
    D_800DFDD0 |= v;
    return 0;
}

u32 func_800964B0(s32 arg0)
{
  if (arg0 != 0x13)
  {
    if (arg0)
    {
      return ((u32) (D_800DFDD0 & 0xFF00)) >> 8;
    }
    else
    {
      return ((u32) (D_800DFDD0 & 0xFF00)) >> 8;
    }
  }
  return (u32) ((u8) D_800DFDD0);
}

s32 func_800964DC(void) {
    D_800DFDF8 |= 1 << func_80010CA4();
    return 0;
}

s32 func_80096514()
{
    return ((u32) D_800DFDF8 >> func_80010CA4()) & 1;
}

s32 func_80096540(s32 arg0) {
    s32 temp_v1;

    temp_v1 = D_800DFDFC | (1 << arg0);
    D_800E0730 = temp_v1;
    D_800DFDFC = temp_v1;
    return 0;
}

s32 func_80096568(s32 arg0) {
    return ((u32) D_800DFDFC >> arg0) & 1;
}

s32 func_80096580(s32 arg0) {
    if ((u32)(arg0 - 0x18) < 6) {
        return D_800DFC88;
    }
    return D_800DFC70[arg0];
}

s32 Record_GetBestTime(s32 stage) {
    if (stage >= 0x18 && stage < 0x1E) {
        return g_BestTimes[0x18];
    }
    return g_BestTimes[stage];
}

s32 func_800965EC(s32 arg0) {
    S_Rec16 *tbl = (S_Rec16 *)0x80102400;

    if ((u32)(arg0 - 0x18) < 6) {
        return 0x18;
    }
    return tbl[arg0].f_1;
}

u8 func_8009661C(s32 arg0)
{
  int new_var;
  new_var = (arg0 * 0x10) + 0x80102400;
  return *((u8 *) (((s8 *) new_var) + 3));
}

s32 Stage_StoreClearState(s32 i) {
    if (Game_IsTimed(i) != 0) {
        return 0;
    }
    if (i >= 0x18 && i < 0x1E) {
        D_800DFC88 = (u8)g_Game.f_812E;
    } else {
        D_800DFC70[i] = (u8)g_Game.f_812E;
    }
    return 0;
}

s32 Stage_Begin(s32 lvl) {
    s16 i;
    s16 j;
    s32 w;
    u8 *hdr;
    u8 *base;
    Stage_966B4_800966B4 *tbl;

    (*(struct Game_966B4 *)&g_Game).f_8122 = func_80010CA4(lvl);
    (*(struct Game_966B4 *)&g_Game).f_8124 = Stage_GetWorld(lvl);
    if ((*(struct Game_966B4 *)&g_Game).f_812C == 1) {
        (*(struct Game_966B4 *)&g_Game).f_8166 = 0;
        if ((*(struct Game_966B4 *)&g_Game).f_8120 == 0x13) {
            for (i = 0; i < 12; i++) {
                for (j = 0; j < 8; j++) {
                    D_800DFF20[i][j] = 0;
                }
            }
        }
    }
    (*(struct Game_966B4 *)&g_Game).f_8160 = 0;
    (*(u16 *)&D_800B38B8) = 1;
    func_8003317C();
    func_8005AD90();
    func_800847C4();
    func_800509A4();
    func_80086148();
    w = World_FirstStage((*(struct Game_966B4 *)&g_Game).f_8124);
    if (w == lvl) {
        if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x1F) {
            goto none;
        }
        if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x20) {
            goto none;
        }
        if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x22) {
            goto none;
        }
        if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x21) {
            goto race;
        }
        if ((*(struct Game_966B4 *)&g_Game).f_8122 == 3) {
            goto none;
        }
        base = (u8 *)(*(s32 *)0x801544CC + 0x80154000);
        tbl = (Stage_966B4_800966B4 *)0x80102400;
        (*(struct Game_966B4 *)&g_Game).f_818C = base;
        hdr = base + 0x40;
        (*(struct Game_966B4 *)&g_Game).f_8128 = tbl[(*(struct Game_966B4 *)&g_Game).f_8124].f_0;
        if ((*(struct Game_966B4 *)&g_Game).f_8120 == 0x13) {
            (*(struct Game_966B4 *)&g_Game).f_8188 = tbl[(*(struct Game_966B4 *)&g_Game).f_8124].f_4;
        } else {
            (*(struct Game_966B4 *)&g_Game).f_8188 = tbl[(*(struct Game_966B4 *)&g_Game).f_8124].f_2;
        }
        (*(struct Game_966B4 *)&g_Game).f_8186 = func_800965EC((*(struct Game_966B4 *)&g_Game).f_8124);
        for (i = 0; i < (*(struct Game_966B4 *)&g_Game).f_8128 * 2; i++) {
            D_800DFFE0[i] = ((u16 *)hdr)[i + 3];
        }
        if ((u16)((*(struct Game_966B4 *)&g_Game).f_8124 - 0x18) < 6) {
            (*(struct Game_966B4 *)&g_Game).f_818A = 0;
            for (i = 0x18; i < 0x1E; i++) {
                (*(struct Game_966B4 *)&g_Game).f_818A += tbl[i].f_3;
            }
        } else {
            (*(struct Game_966B4 *)&g_Game).f_818A = tbl[(*(struct Game_966B4 *)&g_Game).f_8124].f_3;
        }
        if (w != 0x45) {
        if ((*(struct Game_966B4 *)&g_Game).f_8120 == 0x13) {
            for (i = 0; i < 12; i++) {
                for (j = 0; j < 8; j++) {
                    D_800DFE00[i].pad[j] = 0;
                }
            }
            if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x1C) {
                for (j = 0; j < 8; j++) {
                    D_800DFE00[0].pad[j] = D_800DFF20[0][j];
                }
            } else if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x1B) {
                for (j = 0; j < 8; j++) {
                    D_800DFE00[0].pad[j] = D_800DFF20[1][j];
                    D_800DFE00[1].pad[j] = D_800DFF20[2][j];
                    D_800DFE00[2].pad[j] = D_800DFF20[3][j];
                    D_800DFE00[3].pad[j] = D_800DFF20[4][j];
                    D_800DFE00[4].pad[j] = D_800DFF20[5][j];
                }
            }
        } else {
            for (i = 0; i < (*(struct Game_966B4 *)&g_Game).f_8128; i++) {
                for (j = 0; j < 8; j++) {
                    D_800DFE00[i].pad[j] = D_800DF820[World_FirstStage((*(struct Game_966B4 *)&g_Game).f_8124) + i][j];
                }
            }
        }
        } else {
            for (i = 0; i < 12; i++) {
                for (j = 0; j < 8; j++) {
                    D_800DFE00[i].pad[j] = 0;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            (*(struct Game_966B4 *)&g_Game).f_816C[i] = D_800DFE00[lvl - World_FirstStage((*(struct Game_966B4 *)&g_Game).f_8124)].pad[i];
        }
        if ((*(struct Game_966B4 *)&g_Game).f_8120 == 0x13) {
            (*(struct Game_966B4 *)&g_Game).f_812E = 2;
        } else if ((u16)((*(struct Game_966B4 *)&g_Game).f_8124 - 0x18) < 6) {
            (*(struct Game_966B4 *)&g_Game).f_812E = D_800DFC88;
            (*(struct Game_966B4 *)&g_Game).f_8166 = D_800DFCB0;
        } else {
            (*(struct Game_966B4 *)&g_Game).f_812E = D_800DFC70[(*(struct Game_966B4 *)&g_Game).f_8124];
            (*(struct Game_966B4 *)&g_Game).f_8166 = D_800DFC98[(*(struct Game_966B4 *)&g_Game).f_8124];
        }
        (*(u16 *)&D_800E0010) = (*(struct Game_966B4 *)&g_Game).f_812E;
        goto end;
    }
none:
    if ((*(struct Game_966B4 *)&g_Game).f_8124 == 0x21) {
race:
        (*(struct Game_966B4 *)&g_Game).f_8128 = 1;
        (*(struct Game_966B4 *)&g_Game).f_8186 = D_800B38AC[(*(struct Game_966B4 *)&g_Game).f_815C];
        (*(struct Game_966B4 *)&g_Game).f_8188 = D_800B38AC[(*(struct Game_966B4 *)&g_Game).f_815C];
        (*(struct Game_966B4 *)&g_Game).f_818A = 0;
        goto end;
    }
    (*(struct Game_966B4 *)&g_Game).f_8128 = 0;
    (*(struct Game_966B4 *)&g_Game).f_8186 = 0;
    (*(struct Game_966B4 *)&g_Game).f_8188 = 0;
    (*(struct Game_966B4 *)&g_Game).f_818A = 0;
end:
    return 0;
}

/* Saves the current stage's 8 status bytes into the per-stage table and copies
 * the level group's rows to the save buffer; records the stage counter.
 */
s32 Stage_SaveStatus(void) {
    s32 i, j, k;
    if (Game_IsTimed() != 0) {
        return 0;
    }
    Monkey_UpdateSlotStatus();
    k = D_96E0C->f_8126 - World_FirstStage(D_96E0C->f_8124);
    for (j = 0; j < 8; j++) {
        D_800DFE00[k].pad[j] = D_96E0C->f_816C[j];
    }
    for (j = 0; j < D_96E0C->f_8128; j++) {
        for (i = 0; i < 8; i++) {
            D_800DF820[World_FirstStage(D_96E0C->f_8124) + j][i] = D_800DFE00[j].pad[i];
        }
    }
    if ((u16)(D_96E0C->f_8124 - 24) < 6) {
        D_800DFC98[24] = D_96E0C->f_8166;
    } else {
        D_800DFC98[D_96E0C->f_8124] = D_96E0C->f_8166;
    }
    return 0;
}

struct Game_96FAC { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; u16 f_8128; u8 pad812A[2]; u8 f_812C; u8 pad812D[0x39]; u8 f_8166; u8 pad8167[5]; u8 f_816C[8]; };
#define GM_96FAC ((struct Game_96FAC *)&g_Game)
void Pickup_SaveAreaMask(void);
void Area_SaveObjectMask(void);
/* Saves the stage's progress when leaving it for area `next`: the caught-monkey flags
 * (g_Game+0x816C) of the current area into its slot of D_800DFE00; on leaving the last area of a
 * level for the Time Station (0x45) with mode 6 they are copied into the save data
 * (D_800DF820, or the race records D_800DFF20 for races 0x1B/0x1C). */
s32 Area_SaveProgress(s32 next) {
    s16 i;
    s16 j;
    s32 r;
    u8 v;

    func_8005ADF8();
    Link_SaveStates();
    if (GM_96FAC->f_8126 == 0x45 && GM_96FAC->f_812C == 6) {
        if (Game_IsTimed()) {
            return 0;
        }
        v = GM_96FAC->f_8166;
        goto save;
    }
    Pickup_SaveAreaMask();
    Area_SaveObjectMask();
    Monkey_UpdateSlotStatus();
    r = (s16)(GM_96FAC->f_8126 - World_FirstStage(GM_96FAC->f_8124));
    for (j = 0; j < 8; j++) {
        D_800DFE00[r].pad[j] = GM_96FAC->f_816C[j];
    }
    if (next == 0x45 && World_FirstStage(GM_96FAC->f_8124) == GM_96FAC->f_8126 && GM_96FAC->f_812C == 6) {
        if (Game_IsTimed()) {
            if (GM_96FAC->f_8124 == 0x1C) {
                for (i = 0; i < 8; i++) {
                    D_800DFF20[0][i] = D_800DFE00[0].pad[i];
                }
            } else if (GM_96FAC->f_8124 == 0x1B) {
                for (i = 0; i < 8; i++) {
                    D_800DFF20[1][i] = D_800DFE00[0].pad[i];
                    D_800DFF20[2][i] = D_800DFE00[1].pad[i];
                    D_800DFF20[3][i] = D_800DFE00[2].pad[i];
                    D_800DFF20[4][i] = D_800DFE00[3].pad[i];
                    D_800DFF20[5][i] = D_800DFE00[4].pad[i];
                }
            }
            return 0;
        }
        for (j = 0; j < GM_96FAC->f_8128; j++) {
            for (i = 0; i < 8; i++) {
                D_800DF820[World_FirstStage(GM_96FAC->f_8124) + j][i] = D_800DFE00[j].pad[i];
            }
        }
        v = GM_96FAC->f_8166;
    save:
        D_800DFCB0 = v;
    }
    return 0;
}

s32 Area_Enter(s32 st) {
    s16 i;
    s16 k;
    if (st == 0x45 && ((struct S_D_800EC350_800972E0 *)&g_Game)->f_812C == 2) {
        func_8005AD90();
        return 0;
    }
    if (((struct S_D_800EC350_800972E0 *)&g_Game)->f_8126 == 0x45 && World_FirstStage(Stage_GetWorld(st)) == st) {
        if (((struct S_D_800EC350_800972E0 *)&g_Game)->f_812C == 2) {
            Stage_Begin(st);
            return 0;
        }
        D_800B38B8 = 1;
    } else if (((struct S_D_800EC350_800972E0 *)&g_Game)->f_812C == 2) {
        D_800B38B8 = 0;
    } else {
        D_800B38B8 = 1;
    }
    k = st - World_FirstStage(Stage_GetWorld(st));
    for (i = 0; i < 8; i++) {
        ((struct S_D_800EC350_800972E0 *)&g_Game)->f_816C[i] = D_800DFE00[k].pad[i];
    }
    func_800848B0();
    func_80050AFC();
    return 0;
}

/* Counts the caught monkeys and compares with the number this stage needs.
 */
struct Game_97454 { u8 pad0[0x8126]; u16 stage; };

/* Count the caught monkeys (state 2 or 3) among the eight monkey slots into *out and
   return whether that reaches this stage's requirement: D_800DFFE0 holds the count
   needed per stage, indexed from the first stage of the current world. */
s32 Stage_CountCaughtMonkeys(s32 *out) {
    s32 n = 0;
    s32 i;
    s16 k;
    for (i = 0; i < 8; i++) {
        if ((u8)(g_Monkeys[i].f_7A - 2) < 2) {
            n++;
        }
    }
    *out = n;
    k = ((struct Game_97454 *)&g_Game)->stage - World_FirstStage(Stage_GetWorld(((struct Game_97454 *)&g_Game)->stage));
    return n >= D_800DFFE0[k];
}

s32 func_80097504(void) {
    s32 i;
    s32 j;
    s32 n = 0;
    s32 base;
    s32 k;
    u8 *p;

    i = 0;
    base = World_FirstStage(Stage_GetWorld(((struct S_D_800EC350_80097504 *)&g_Game)->f_8126));
    for (; i < ((struct S_D_800EC350_80097504 *)&g_Game)->f_8128; i++) {
        if (((struct S_D_800EC350_80097504 *)&g_Game)->f_8126 == base + i) {
            for (j = 0; j < 8; j++) {
                if ((u8)(g_Monkeys[j].f_7A - 2) < 2) {
                    n++;
                }
            }
        } else {
            p = (u8 *)func_80097E88(base + i, &k);
            for (j = 0; j < 8; j++) {
                if ((u8)(p[j] - 2) < 2) {
                    n++;
                }
            }
        }
    }
    return n;
}

s32 func_80097620(void) {
    return D_800B38B8;
}

s16 func_80097630(s32 i) {
    return D_800B3810[i];
}

s32 World_FirstStage(s32 i) {
    return D_800B3858[i];
}

s16 func_80097668(void) {
    return D_800E0010;
}

/* 1 in the timed modes: g_Game+0x8120 == 0x13 (probably Time Trial: every normal stage can be
 * replayed against monkey and time targets, per the user; there chips stop the clock, see
 * TimeTrial_AddClockStop) or sub-mode +0x8122 == 3 (the race stages, Stadium / Gladiator Attack).
 * In them the item drop selector gives two energy chips and Hud_Draw shows the spinning clock by
 * the timer (Hud_DrawTimerClock). */
s32 Game_IsTimed() {
    if ((g_Game.f_8120 == 0x13) || (g_Game.f_8122 == 3)) {
        return 1;
    }
    return 0;
}

s32 func_800976B8(s32 a, s32 b) {
    if (func_800978E0(6) == 0 && func_80096580(0x18) > 0 && func_80010CA4(a) != 3) {
        ((struct S_D_800EC350_800976B8 *)&g_Game)->f_8126 = -1;
        D_800B38BA = b;
        D_800B38BC = a;
        return 2;
    }
    if (func_80096580(Stage_GetWorld(a)) == 2 && b == 0x800) {
        return 3;
    }
    if (func_800977BC(a) != 0) {
        return 2;
    }
    if (D_800B37F0[func_80010CA4(a)] == Stage_GetWorld(a) && func_80096514(a) == 0) {
        return 0;
    }
    return 1;
}

s32 func_800977BC(s32 a) {
    s32 i;
    for (i = 0; D_800B389C[i] >= 0; i++) {
        if (D_800B389C[i] == a && !((*(u32 *)&D_800DFDCC) & (1 << i))) {
            return 1;
        }
    }
    return 0;
}

/* A Time Station gadget tutorial (stages 0x5C..0x62) is finished: marks it in D_800DFDCC and
 * gives the matching gadget bit (Gadget_Unlock). */
s32 Tutorial_Complete(void) {
    s32 bit;
    D_800DFDCC |= 1 << D_800B38C0[GM_97820->f_8126 - 0x5C];
    switch (GM_97820->f_8126) {
    case 0x5C:
        bit = 4;
        break;
    case 0x5D:
        bit = 8;
        break;
    case 0x5E:
        bit = 0x10;
        break;
    case 0x5F:
        bit = 0x20;
        break;
    case 0x60:
        bit = 0x40;
        break;
    case 0x61:
        bit = 0x80;
        break;
    case 0x62:
        bit = 1;
        break;
    default:
        goto miss;
    }
    Gadget_Unlock(bit);
    miss:
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A67B0_pad);


s32 func_800978E0(s32 arg0) {
    return ((1 << arg0) & D_800DFDCC) != 0;
}

/* After a gadget tutorial (stages 0x5C..0x62, the Time Station terminals),
 * chooses the stage and mode to go to next.
 */
s32 Tutorial_SetNextStage(void) {
    switch (D_978FC.f_8126) {
    case 0x62:
        D_978FC.f_8126 = 2;
        D_978FC.f_8120 = 10;
        break;
    case 0x5C:
        D_978FC.f_8126 = 6;
        D_978FC.f_8120 = 8;
        break;
    case 0x5D:
        D_978FC.f_8126 = 15;
        D_978FC.f_8120 = 10;
        break;
    case 0x5E:
        D_978FC.f_8126 = 0x14;
        D_978FC.f_8120 = 8;
        break;
    case 0x5F:
        D_978FC.f_8126 = D_800B38BC;
        if (func_800976B8(D_800B38BC, D_800B38BA) == 3) {
            D_978FC.f_8120 = 0x12;
        } else {
            D_978FC.f_8120 = 10;
        }
        break;
    case 0x60:
        D_978FC.f_8126 = 0x1E;
        D_978FC.f_8120 = 10;
        break;
    case 0x61:
        D_978FC.f_8126 = 0x35;
        D_978FC.f_8120 = 8;
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A67D0_pad);


INCLUDE_ASM("asm/nonmatchings/game/80094F20_stage", func_80097A60);

s32 func_80097BFC(void) {
    if ((g_Game.f_8120 != 0xB) || (g_Game.f_8122 == 3)) {
        return 0;
    }
    switch (g_Game.f_8124) {
    case 17:
    case 22:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
        if (g_Game.f_8166 >= g_Game.f_8188) {
            g_Game.f_812E = 2;
        } else {
            g_Game.f_812E = 1;
        }
        break;
    case 30:
        g_Game.f_812E = 2;
        break;
    default:
        if (g_Game.f_8166 >= g_Game.f_8188) {
            g_Game.f_812E = 1;
        }
        if (g_Game.f_8166 >= g_Game.f_8186) {
            g_Game.f_812E = 2;
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80094F20_stage", jtbl_800A67F0_pad);



s32 Stage_GetInfo(u32 idx, S_Info_80097D0C_80097D0C *out) {
    S_Rec16_80097D0C_80097D0C *e;
    S_Rec16_80097D0C_80097D0C *p;
    s32 i;
    if (idx >= 32) {
        return -1;
    }
    e = (S_Rec16_80097D0C_80097D0C *)0x80102400;
    out->f_0 = Record_GetBestTime(idx);
    out->f_8 = func_800965EC(idx);
    out->f_A = e[idx].f_4;
    out->f_6 = e[idx].f_2;
    out->f_10 = func_80096580(idx);
    if (idx - 24 < 6) {
        out->f_E = 0;
        for (i = 24; i < 30; i++) {
            out->f_E += ((S_Rec16_80097D0C_80097D0C *)0x80102400)[i].f_3;
        }
    } else {
        out->f_E = e[idx].f_3;
    }
    if (((struct S_D_800EC350_80097D0C *)&g_Game)->f_8120 == 0xB || ((struct S_D_800EC350_80097D0C *)&g_Game)->f_8120 == 0x13) {
        out->f_C = ((struct S_D_800EC350_80097D0C *)&g_Game)->f_816A;
        out->f_4 = ((struct S_D_800EC350_80097D0C *)&g_Game)->f_8166;
    } else {
        out->f_C = 0;
        if (idx - 24 < 6) {
            out->f_4 = D_800DFC98[24];
        } else {
            out->f_4 = D_800DFC98[idx];
        }
    }
    return 0;
}

s32 Stage_GetTargetTimes(u32 arg0)
{
  int new_var;
  new_var = arg0 < 0x1EU;
  if (new_var)
  {
    return ((arg0 * 0x10) + 0x80102400) | 8;
  }
  if (arg0)
  {
    return 0;
  }
  else
    if (new_var)
  {
    return 0;
  }
  else
  {
    return 0;
  }
}

struct S_D_800DFE00 *func_80097E88(s32 a, s32 *out) {
    s32 k;
    if (Stage_GetWorld(a) == 0x20) {
        return 0;
    }
    if (Stage_GetWorld(a) == 0x1F) {
        return 0;
    }
    if (Stage_GetWorld(a) == 0x18) {
        return 0;
    }
    k = a - World_FirstStage(Stage_GetWorld(a));
    *out = D_800DFFE0[k];
    return &D_800DFE00[k];
}

s32 func_80097F2C(void) {
    s32 i;
    for (i = 0; i < 25; i++) {
        if (i == 0 || i == 7 || i == 14 || i == 18 || i == 19 || i == 23) {
            continue;
        }
        if (D_800DFC70[i] != 2) {
            return 0;
        }
    }
    return 1;
}

s32 func_80097FB0(s32 st) {
    u8 *t = (u8 *)0x80102400;
    s32 first;
    s32 n;
    s32 cnt;
    s32 i;
    if (st >= 0x18 && st < 0x1E) {
        first = World_FirstStage(0x18);
        n = t[0x180];
        for (i = 0x19; i < 0x1E; i++) {
            n += t[i * 16];
        }
    } else {
        first = World_FirstStage(st);
        n = t[st * 16];
    }
    cnt = 0;
    for (i = first; i < first + n; i++) {
        if (SpecterCoin_IsCollected(i) != 0) {
            cnt++;
        }
    }
    return cnt;
}

void Save_GetCurrentCompletion(void) {
    S_Save_80098088 b;
    s32 i;
    b.f_668 = (*(u32 *)&D_800DFDD0);
    for (i = 0; i < 128; i++) {
        b.f_68[i] = ((u16 *)&D_800DFB70)[i];
    }
    for (i = 0; i < 32; i++) {
        b.f_690[i] = g_BestTimes[i];
        b.f_28[i] = D_800DFC70[i];
        b.f_48[i] = D_800DFC98[i];
    }
    for (i = 0; i < 8; i++) {
        b.f_66C[i] = ((u32 *)&D_800DFDD8)[i];
    }
    Save_GetCompletion(&b);
}

typedef struct { u8 pad0[8]; s16 t2; s16 t1; s16 t0; u8 padE[2]; } Rec_8009816C;
typedef struct { u8 id; u8 v; } Pair_8009816C;
typedef struct { u8 pad0[0x28]; u8 f_28[0x1E]; u8 f_46; u8 pad47; u8 f_48[0x20]; Pair_8009816C f_68[0x80]; u8 pad168[0x500]; u32 f_668; u8 pad66C[4]; u32 f_670; u8 f_674; u8 pad675[0x1B]; u32 f_690[25]; } Save_8009816C;
s32 Save_GetCompletion_(Save_8009816C *sb) asm("Save_GetCompletion");
/* Save_GetCompletion: completion score of a save block. Monkeys caught (Save_SumStageMonkeys) +
 * per stage (except 0, 7, 14, 18, 19, 23): stage state +0x28 (1: +15, 2: +25) and the best time
 * +0x690 against the three thresholds at 0x80102400 (+8/+7/+5); +15 each for +0x46 == 2 and flags
 * 0x10/0x1000 of +0x668; +2 per entry of the +0x68 list (ended by id 0xFF); +8 for each of the
 * three values in +0x670 (two low bytes) and +0x674 that equal 5. */
s32 Save_GetCompletion_(Save_8009816C *sb) {
    s32 n = Save_SumStageMonkeys(sb->f_48);
    s32 i;
    u32 w;
    Pair_8009816C *q;

    for (i = 0; i < 25; i++) {
        if (i == 0 || i == 7 || i == 14 || i == 18 || i == 19 || i == 23) {
            continue;
        }
        if (sb->f_28[i] == 1) {
            n += 15;
        } else if (sb->f_28[i] == 2) {
            n += 25;
        }
        if (sb->f_690[i] < (u32)((Rec_8009816C *)0x80102400)[i].t0) {
            n += 8;
        } else if (sb->f_690[i] < ((Rec_8009816C *)0x80102400)[i].t1) {
            n += 7;
        } else if (sb->f_690[i] < ((Rec_8009816C *)0x80102400)[i].t2) {
            n += 5;
        }
    }
    if (sb->f_46 == 2) {
        n += 15;
    }
    if (sb->f_668 & 0x10) {
        n += 15;
    }
    if (sb->f_668 & 0x1000) {
        n += 15;
    }
    q = sb->f_68;
    for (i = 0; i < 0x80; i++) {
        if (q[i].id == 255) {
            break;
        }
        n += 2;
    }
    w = sb->f_670;
    if ((w & 0xFF) == 5) {
        n += 8;
    }
    if (((w >> 8) & 0xFF) == 5) {
        n += 8;
    }
    if (sb->f_674 == 5) {
        n += 8;
    }
    return n;
}

s32 func_80098320(void) {
    return 0;
}
