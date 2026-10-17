#include "common.h"
#include "m2c_macros.h"
#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[0x2C]; } S_820C_8009B578_8009B578;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0xA]; S_820C_8009B578_8009B578 *f_70; s32 f_74; s16 f_78; s16 f_7A; s16 f_7C; u8 pad7E[2]; s16 f_80; s16 f_82; s16 f_84; u8 pad86[2]; s32 f_88; } S_O_8009B578_8009B578;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x5F]; s8 f_8F; } S_4DC4_8009B6C8;

extern struct S_D_800EC1E0 { u8 pad_0[0xE0]; s32 f_E0; } g_Spike;
struct S_D_800EC350_8009B578 { u8 pad0[0x820C]; S_820C_8009B578_8009B578 *f_820C; };
extern M2C_UNK g_Game;
extern S_O_8009B578_8009B578 *D_800B4DC4;
extern struct S_D_800F5120 { u32 f_0; } g_GadgetState;
s32 rsin(s32);
s32 rcos(s32);
struct g_Spike_8009B6C8 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; u8 pad34[4]; s32 f_38; u8 pad3C[0x34]; s32 f_70; };
#define G_SPIKE_8009B6C8 ((struct g_Spike_8009B6C8 *)&g_Spike)

void func_8009B3B0(void) {
    g_Spike.f_E0 = (s32) (g_Spike.f_E0 | 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/8009B3B0_vehicle", func_8009B3CC);

INCLUDE_RODATA("asm/nonmatchings/game/8009B3B0_vehicle", jtbl_800A6840);
INCLUDE_RODATA("asm/nonmatchings/game/8009B3B0_vehicle", jtbl_800A6840_pad);


void func_8009B578(s32 type, s32 idx, s32 ang) {
    S_O_8009B578_8009B578 *o = D_800B4DC4;
    o->f_70 = &((struct S_D_800EC350_8009B578 *)&g_Game)->f_820C[idx];
    o->f_74 = idx;
    o->f_80 = o->f_60 = rsin(ang);
    o->f_84 = o->f_64 = rcos(ang);
    o->f_82 = o->f_62 = 0;
    o->f_88 = type;
    o->f_78 = o->f_24 = o->f_70->f_0;
    o->f_7A = o->f_28 = o->f_70->f_2;
    o->f_7C = o->f_2C = o->f_70->f_4;
    switch (type) {
    case 1:
        g_GadgetState.f_0 |= 4;
        o->f_70->f_6 = 0x80;
        o->f_70->f_8 = 0xC0;
        o->f_70->f_A = 0x80;
        break;
    case 2:
        g_GadgetState.f_0 |= 8;
        o->f_70->f_6 = 0x80;
        o->f_70->f_8 = 0x80;
        o->f_70->f_A = 0x80;
        break;
    }
}

/* Every frame after the vehicle (D_800B4DC4) update: while Spike is within 64 units of it in
   X and Z and inside a Y window around it, its +0x8F counter counts down to 2; if the counter is
   0 and Spike's state nibble (+0x70 & 0xF0) is 0x40, his X/Z velocity is zeroed. Away from it,
   the counter resets to 0. */
void Vehicle_UpdateSpikeOnTop(void) {
    S_4DC4_8009B6C8 *o = (*(S_4DC4_8009B6C8 * *)&D_800B4DC4);
    s32 ox, sx, oz, sz;
    if ((u32)(o->f_28 - G_SPIKE_8009B6C8->f_28 + 0x200) > 0x600) {
fail:
        o->f_8F = 0;
        return;
    }
    ox = o->f_24;
    sx = G_SPIKE_8009B6C8->f_24;
    oz = o->f_2C;
    sz = G_SPIKE_8009B6C8->f_2C;
    if (ABSDIFF(ox, sx) >= 0x41 || ABSDIFF(oz, sz) >= 0x41) {
        goto fail;
    }
    if (o->f_8F >= 3) {
        o->f_8F--;
    }
    if (o->f_8F <= 0 && (G_SPIKE_8009B6C8->f_70 & 0xF0) == 0x40) {
        G_SPIKE_8009B6C8->f_30 = 0;
        G_SPIKE_8009B6C8->f_38 = 0;
    }
}
