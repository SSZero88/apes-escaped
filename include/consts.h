#ifndef CONSTS_H
#define CONSTS_H

/* Named values for numbers that show up in the game code. These are #defines/enums so they cost
 * nothing in the build (a `static const` variable could be placed in .rodata and break the match). */

/* Pad buttons (g_Pad +0x158 held, +0x160 pressed this frame), PsyQ layout. */
#define PAD_L2       0x0001
#define PAD_R2       0x0002
#define PAD_L1       0x0004
#define PAD_R1       0x0008
#define PAD_TRIANGLE 0x0010
#define PAD_CIRCLE   0x0020
#define PAD_CROSS    0x0040
#define PAD_SQUARE   0x0080
#define PAD_SELECT   0x0100
#define PAD_L3       0x0200
#define PAD_R3       0x0400 /* also the Water Net shot */
#define PAD_START    0x0800
#define PAD_UP       0x1000
#define PAD_RIGHT    0x2000
#define PAD_DOWN     0x4000
#define PAD_LEFT     0x8000
#define PAD_HISTORY_LEN 40 /* g_Pad +0xA4: ring of the last 40 frames' new presses, write index +0x170 */

/* Screen and ordering table. */
#define SCREEN_W     384     /* 0x180: both draw buffers are 384x240 (Gfx_InitDisplay) */
#define SCREEN_H     240     /* 0xF0 */
#define OT_LEN       0x1000  /* entries per draw buffer's ordering table */
#define OT_MAX_Z     0xFC0   /* deepest slot the model code uses */

/* Fixed point: 1.0 in the GTE's 4.12 format (also a full turn in angle units). */
#define ONE          0x1000

/* CPU scratch pad (1 KB of fast RAM), used as a per-frame work area by the model code. */
#define SCRATCH      0x1F800000

#endif
