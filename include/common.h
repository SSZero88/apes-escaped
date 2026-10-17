#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

#ifndef M2CTX
/* PsyQ aligned every object's .text and .rodata to 16 bytes */
__asm__(".section .rodata\n\t.align 4\n.section .text\n\t.align 4\n");
#endif

/* 2-byte-aligned structs: GCC copies these with lwl/lwr pairs, as the original code does.
 * SVECTOR is PsyQ's (libgte) short vector; S16xN cover other short-array structs. */
typedef struct { short vx, vy, vz, pad; } SVECTOR;
typedef struct { short v[6]; } S16x6;
typedef struct { short v[8]; } S16x8;
typedef struct { short v[10]; } S16x10;
typedef struct { short v[12]; } S16x12;
typedef struct { short v[16]; } S16x16;

/* matches the original's codegen (each branch compares separately), see Box_NearPoint */
#define ABS(x) (((x) >= 0) ? (x) : -(x))

/* Links primitive p into the ordering-table entry *ot (addPrim). The original is an inline-asm
   macro, nothing in C compiles to it: lwl t1,2(ot); sll t2,p,8; swl t2,2(ot); swl t1,2(p).
   Most functions use the form with compiler-chosen temps (Hud_DrawTimeMedal); a few use a copy with
   a1/a0 hardcoded (Hud_DrawLivesIcon). */
#define ADD_PRIM_ASM(ot, p) \
    { unsigned int _t1, _t2; \
      __asm__ volatile("lwl %0, %2\n\tsll %1, %4, 8\n\tswl %1, %2\n\tswl %0, %3" \
                       : "=&r"(_t1), "=&r"(_t2) : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p)); }
/* the same with the temps in the other operand order, which some functions need (MonkeyInfo_DrawStatPips) */
#define ADD_PRIM_ASM2(ot, p) \
    { unsigned int _t1, _t2; \
      __asm__ volatile("lwl %1, %2\n\tsll %0, %4, 8\n\tswl %0, %2\n\tswl %1, %3" \
                       : "=&r"(_t2), "=&r"(_t1) : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p)); }
/* the first form wrapped in do { } while (0): same code, different register allocation around
   it (Menu_DrawCaps) */
#define ADD_PRIM_ASM_DW(ot, p) \
    do { unsigned int _t1, _t2; \
      __asm__ volatile("lwl %0, %2\n\tsll %1, %4, 8\n\tswl %1, %2\n\tswl %0, %3" \
                       : "=&r"(_t1), "=&r"(_t2) : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p)); } while (0)
#define ADD_PRIM_ASM_A01(ot, p) \
    __asm__ volatile("lwl $5, %0\n\tsll $4, %2, 8\n\tswl $4, %0\n\tswl $5, %1" \
                     : : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p) : "$4", "$5")
/* addPrim with hard temp registers A (lwl) and B (sll), e.g. ADD_PRIM_R(ot, p, "$3", "$2"), and the
   OT entry address as a register operand (Hud_DrawTimerClock) */
#define ADD_PRIM_R(ot, p, A, B) \
    __asm__ volatile("lwl " A ", 2(%0)\n\tsll " B ", %2, 8\n\tswl " B ", 2(%0)\n\tswl " A ", %1" \
                     : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : A, B)
/* hard a0/v1 temps with the OT entry address as a register operand (Shadow_Draw) */
#define ADD_PRIM_A0V1(ot, p) \
    __asm__ volatile("lwl $4, 2(%0)\n\tsll $3, %2, 8\n\tswl $3, 2(%0)\n\tswl $4, %1" \
                     : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p) : "$3", "$4")

/* The display part of g_Game: +4 next free primitive, +8 current OT pointer, +0xC current buffer
   (0/1), +0x10 the two display buffers (stride 0x4078). Each starts with its DRAWENV (0x5C) and
   DISPENV (0x14), then the depth-sorted world OT and a 2-entry HUD OT. G_DRAW needs g_Game. */
typedef struct { unsigned char env[0x70]; unsigned int ot[0x1000]; unsigned int hud[2]; } DrawBuf;
typedef struct { unsigned char pad0[4]; unsigned char *prim; unsigned int *ot; int cur; DrawBuf db[2]; } GameDraw;
#define G_DRAW (*(GameDraw *)&g_Game)
#define G_HUD_OT (G_DRAW.db[G_DRAW.cur].hud)

/* SPRT preceded by a draw-mode (texpage) word, linked as one 5-word primitive */
typedef struct { unsigned int tag; unsigned int tpage; unsigned char r0, g0, b0, code; short x0, y0; unsigned char u0, v0; unsigned short clut; short w, h; } SprtTp;

typedef signed char        s8;
typedef unsigned char      u8;
typedef signed short       s16;
typedef unsigned short     u16;
typedef signed int         s32;
typedef unsigned int       u32;
typedef signed long long   s64;
typedef unsigned long long u64;
typedef float              f32;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
