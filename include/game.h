#ifndef GAME_H
#define GAME_H

#include "common.h"

/* Structs here are partially understood; unkXX fields are named by offset. */

typedef struct MonkeyAnimEntry {
    /* 0x0 */ u16 f_0;
    /* 0x2 */ u16 f_2;
    /* 0x4 */ u8 pad4[4];
} MonkeyAnimEntry;

/* One monkey (0x250 bytes). Monkey_InitAll sets up 8 of them at g_Monkeys, next to the
   "Too many monkeys in one area" check; g_CurMonkey points at the one being updated. */
typedef struct Monkey {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ SVECTOR *f_10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ s32 f_18;
    /* 0x01C */ s32 f_1C;
    /* 0x020 */ u8 pad20[0x4];
    /* 0x024 */ s32 f_24; /* position */
    /* 0x028 */ s32 f_28;
    /* 0x02C */ s32 f_2C;
    /* 0x030 */ u8 pad30[0x16];
    /* 0x046 */ s16 f_46;
    /* 0x048 */ u8 pad48[0x14];
    /* 0x05C */ u16 f_5C;
    /* 0x05E */ u8 pad5E[0x2];
    /* 0x060 */ s16 f_60;
    /* 0x062 */ s16 f_62;
    /* 0x064 */ s16 f_64;
    /* 0x066 */ u8 pad66[0x2];
    /* 0x068 */ SVECTOR f_68;
    /* 0x070 */ s16 f_70; /* velocity */
    /* 0x072 */ s16 f_72;
    /* 0x074 */ s16 f_74;
    /* 0x076 */ u8 pad76[0x2];
    /* 0x078 */ u8 f_78; /* state */
    /* 0x079 */ u8 f_79;
    /* 0x07A */ u8 f_7A;
    /* 0x07B */ u8 f_7B;
    /* 0x07C */ u8 f_7C;
    /* 0x07D */ u8 pad7D[0x15];
    /* 0x092 */ s16 f_92;
    /* 0x094 */ s16 f_94;
    /* 0x096 */ s16 f_96;
    /* 0x098 */ u8 pad98[0x2];
    /* 0x09A */ s16 f_9A;
    /* 0x09C */ u8 f_9C[0x20]; /* turn matrix */
    /* 0x0BC */ s16 f_BC;
    /* 0x0BE */ u8 padBE[0x2];
    /* 0x0C0 */ s16 f_C0;
    /* 0x0C2 */ u8 padC2[0x2];
    /* 0x0C4 */ s16 f_C4;
    /* 0x0C6 */ u8 padC6[0xE];
    /* 0x0D4 */ s8 f_D4;
    /* 0x0D5 */ u8 f_D5; /* model detail level */
    /* 0x0D6 */ u8 padD6[0x2];
    /* 0x0D8 */ u8 f_D8;
    /* 0x0D9 */ u8 padD9[0x9];
    /* 0x0E2 */ u8 f_E2;
    /* 0x0E3 */ u8 padE3[0x1];
    /* 0x0E4 */ s16 f_E4;
    /* 0x0E6 */ s16 f_E6;
    /* 0x0E8 */ u8 padE8[0x2];
    /* 0x0EA */ s16 f_EA;
    /* 0x0EC */ u16 f_EC;
    /* 0x0EE */ s16 f_EE;
    /* 0x0F0 */ s16 f_F0;
    /* 0x0F2 */ u16 f_F2;
    /* 0x0F4 */ u16 f_F4;
    /* 0x0F6 */ u8 padF6[0x2A];
    /* 0x120 */ s16 f_120;
    /* 0x122 */ u8 pad122[0x2];
    /* 0x124 */ s16 f_124;
    /* 0x126 */ u16 f_126;
    /* 0x128 */ s16 f_128;
    /* 0x12A */ u8 pad12A[0x2];
    /* 0x12C */ s32 f_12C;
    /* 0x130 */ s32 f_130;
    /* 0x134 */ s32 f_134;
    /* 0x138 */ u8 pad138[0x4];
    /* 0x13C */ s32 f_13C;
    /* 0x140 */ s32 f_140;
    /* 0x144 */ s32 f_144;
    /* 0x148 */ u8 pad148[0x10];
    /* 0x158 */ s16 f_158;
    /* 0x15A */ u8 pad15A[0x12];
    /* 0x16C */ MonkeyAnimEntry *f_16C;
    /* 0x170 */ s16 f_170;
    /* 0x172 */ s16 f_172;
    /* 0x174 */ u8 pad174[0x2];
    /* 0x176 */ s16 f_176[0x32]; /* distance via each link */
    /* 0x1DA */ u8 f_1DA[0x32];
    /* 0x20C */ s32 f_20C;
    /* 0x210 */ s32 f_210; /* distance to Spike (Monkey_SelectActive) */
    /* 0x214 */ u8 pad214[0x8];
    /* 0x21C */ s32 f_21C;
    /* 0x220 */ u8 pad220[0x2];
    /* 0x222 */ u8 f_222;
    /* 0x223 */ u8 pad223[0x5];
    /* 0x228 */ u32 f_228;
    /* 0x22C */ u16 f_22C;
    /* 0x22E */ u8 pad22E[0x14];
    /* 0x242 */ s16 f_242;
    /* 0x244 */ s16 f_244;
    /* 0x246 */ s16 f_246;
    /* 0x248 */ u32 f_248;
    /* 0x24C */ u32 f_24C;
} Monkey;

typedef Monkey Unk800B4D08;

/* Monkey type ids (MonkeyKind.f_0), named by shorts colour (docs/findings.md). Light blue / yellow follow
 * from the stage data plus the user's notes: id 2 is the only type in level 1 (calm light blue) and the
 * only one with the laser window (5), from stage 9 in Thick Jungle; id 3 first appears in Thick Jungle.
 * Black = type 5 is still a guess. */
enum MonkeyType {
    MONKEY_RED = 0x0,          /* very aggressive: mgun, missile, scratch */
    MONKEY_DARK_BLUE = 0x40,   /* fastest, runs away; banana, scratch */
    MONKEY_LIGHT_BLUE = 0x80,  /* calm, from stage 1; banana, scratch; laser (window 5) in many areas from stage 9 */
    MONKEY_YELLOW = 0xC0,      /* normal, from level 4 Thick Jungle; banana, scratch */
    MONKEY_GREEN = 0x100,      /* homing missiles only, widest sight */
    MONKEY_TYPE5 = 0x140,      /* mgun, scratch; first in level 13 (probably black, unconfirmed) */
    MONKEY_WHITE = 0x180       /* window 5 (laser-type gun), banana, scratch; first in Dexter's Island */
};

/* Per-kind monkey parameters (0x88 bytes each), indexed by Monkey.f_7C. */
typedef struct MonkeyKind {
    /* 0x00 */ u16 f_0;
    /* 0x02 */ u8 pad2[0x2];
    /* 0x04 */ s16 f_4;
    /* 0x06 */ u8 pad6[0x4];
    /* 0x0A */ s16 f_A;
    /* 0x0C */ u8 padC[0x7C];
} MonkeyKind;

/* 0x18-byte records at D_800B4D00 (count D_800B4D18); f_14 is indexed by Monkey.f_7B. */
typedef struct Unk800B4D00 {
    /* 0x00 */ u32 f_0;
    /* 0x04 */ u8 pad4[0x6];
    /* 0x0A */ u8 f_A;
    /* 0x0B */ u8 f_B;
    /* 0x0C */ u16 *f_C;
    /* 0x10 */ u16 f_10;
    /* 0x12 */ u16 f_12;
    /* 0x14 */ u8 f_14[4];
} Unk800B4D00;

extern MonkeyKind *g_MonkeyKinds;
extern Unk800B4D00 *D_800B4D00;
extern s16 D_800B4D18;

extern Monkey *g_CurMonkey; /* the monkey being updated */
extern Monkey *g_MonkeyTarget; /* set to &g_Spike (Spike?) by Monkey_InitAll; only its position is used so far */


/* Top-level game mode table (800AFA30): each mode loads an overlay then runs. */
typedef struct GameMode {
    s32 (*func)(void);
    s32 overlay; /* < 0: none */
} GameMode;

extern GameMode D_800AFA30[];

#define OVERLAY_ADDR 0x80136000

#endif
