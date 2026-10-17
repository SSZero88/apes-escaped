#ifndef GTE_H
#define GTE_H

/*
 * Inline GTE (geometry coprocessor, cop2) macros in the style of PsyQ's inline_c.h:
 * loads/stores are bare mtc2/mfc2/lwc2/swc2 (multi-register loads separate their
 * mtc2s with nops), and every command starts with two nops. Each macro here has been
 * checked against the game's code.
 */

/* control registers */
#define gte_SetGeomScreen(h) __asm__ volatile ("ctc2 %0, $26" : : "r"(h))  /* H */
#define gte_SetZSF3(z)       __asm__ volatile ("ctc2 %0, $29" : : "r"(z))
#define gte_SetZSF4(z)       __asm__ volatile ("ctc2 %0, $30" : : "r"(z))
/* screen offset OFX/OFY; the shifts are done in C, both before either ctc2 */
#define gte_SetGeomOffset(x, y) { \
    s32 _x = (x) << 16, _y = (y) << 16; \
    __asm__ volatile ("ctc2 %0, $24" : : "r"(_x)); \
    __asm__ volatile ("ctc2 %0, $25" : : "r"(_y)); }

/* IR1..IR3 from registers */
#define gte_ldIR(r1, r2, r3) __asm__ volatile ( \
    "mtc2 %0, $9; nop; mtc2 %1, $10; nop; mtc2 %2, $11" : : "r"(r1), "r"(r2), "r"(r3))

/* the same as three statements (register allocation differs; the game uses both) */
#define gte_ldIR1(r) __asm__ volatile ("mtc2 %0, $9; nop" : : "r"(r))
#define gte_ldIR2(r) __asm__ volatile ("mtc2 %0, $10; nop" : : "r"(r))
#define gte_ldIR3(r) __asm__ volatile ("mtc2 %0, $11" : : "r"(r))

/* RGBC from memory */
#define gte_ldRGB(p) __asm__ volatile ("lwc2 $6, 0(%0)" : : "r"(p))

/* leading zero count: LZCS in, LZCR out */
#define gte_ldLZCS(r) __asm__ volatile ("mtc2 %0, $30" : : "r"(r))
#define gte_stLZCR(r) __asm__ volatile ("mfc2 %0, $31" : "=r"(r))

/* commands */
#define gte_sqr0() __asm__ volatile ("nop; nop; sqr 0")  /* MAC = IR * IR */
#define gte_cc()   __asm__ volatile ("nop; nop; cc")     /* color * light color */

/* results */
#define gte_stMAC1(r) __asm__ volatile ("mfc2 %0, $25" : "=r"(r))
#define gte_stMAC2(r) __asm__ volatile ("mfc2 %0, $26" : "=r"(r))
#define gte_stMAC3(r) __asm__ volatile ("mfc2 %0, $27" : "=r"(r))
#define gte_stRGB2(p) __asm__ volatile ("swc2 $22, 0(%0)" : : "r"(p))
/* the same with PsyQ's "memory" clobber: later loads are redone after it (func_80051AA4) */
#define gte_stRGB2_mem(p) __asm__ volatile ("swc2 $22, 0(%0)" : : "r"(p) : "memory")

/* perspective transform of one vertex (PsyQ inline_c.h forms) */
#define gte_ldv0(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")

#endif
