#include "common.h"

typedef struct { s16 vx, vy, vz, pad; } SV_986E0;
typedef struct { s32 x, y, z; u8 padC[0xC]; s16 f_18; s16 f_1A; s16 f_1C; u8 pad1E[2]; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; u8 pad28[4]; u32 f_2C; } Col_986E0;
typedef struct { u8 pad0[4]; s16 state; s16 f_6; s32 power; Col_986E0 *hit[3]; s16 f_18; s16 f_1A; s16 f_1C; u8 pad1E[2]; s16 snd1; s16 snd2; } Hoop_986E0;
typedef struct { u8 pad0[0x28]; u8 m[0x14]; s32 f_3C; u8 pad40[4]; s32 f_44; u8 pad48[0x1E]; u16 f_66; u8 pad68[0x10]; u16 f_78; u8 pad7A[2]; u16 f_7C; } SC_986E0;
typedef struct { u8 pad0[0x182]; u16 f_182; u8 pad184[0x18]; s16 f_19C; u8 pad19E[2]; s16 f_1A0; u8 pad1A2[0x12]; u16 f_1B4; u8 pad1B6[6]; u16 f_1BC; } Pad_986E0;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x5C]; s16 f_8C; u8 pad8E[0x92]; s32 f_120; s32 f_124; s32 f_128; } Spk_986E0;
typedef struct { u8 pad0[4]; u16 f_4; } Cam_986E0;
extern struct { s32 f_0; u8 pad4[0x80FC]; s32 f_8100; u8 pad8104[0x4E]; u16 f_8152; } g_Game;
extern Hoop_986E0 g_GadgetState;
extern s32 D_800F5128;
extern s16 D_800F513A;
extern Pad_986E0 g_Pad;
extern Spk_986E0 g_Spike;
extern s16 g_SpikeHealth;
extern u16 D_800EC23E;
extern Cam_986E0 *D_800EC0A0;
extern u8 D_800F4730[][0x20];
void Hoop_UpdateModel(void);
s32 Sound_Stop(s32, s32);
s16 Sound_Play(s32, s32);
void func_8004637C(void *);
s32 func_8007CA48(s32);
void CompMatrix(void *, void *, void *);
void func_8007CD0C(s32);
void Effect_SpawnAt(s32, void *);
void Spike_SetState(s32);
void func_80087BA4(s32, s32, s32, s32);
void Pad_Vibrate(s32, s32, s32);
Col_986E0 *CollShape_Alloc(void);
s32 rsin(s32);
s32 rcos(s32);
void Collision_Set(s32, Col_986E0 *, void *);
/* The Super Hoop gadget (g_GadgetState). Idle (state 0): while the hoop is the active gadget,
 * rotating the right stick (scratchpad +0x78) winds up its power; above 0x140 it starts spinning
 * (state 1, loop sound 0x2C). Spinning: effect 9 at Spike, three hit shapes (collision kind 6)
 * placed around him with rsin/rcos; when one of them is hit Spike is knocked back along it
 * (Spike_SetState(0x24)) and the hoop loses 0x3C power. Power drains by 3 a frame (it stops at
 * 0) and sets the loop sound pitch. The model is updated by Hoop_UpdateModel. */
void Hoop_Update(void) {
    SC_986E0 *sc = (SC_986E0 *) 0x1F800000;
    Hoop_986E0 *g;
    Col_986E0 *c;
    s32 p;
    u16 *camIdx;
    s32 r;
    s32 a;
    s32 sn;
    s32 sn_s0;
    s32 sn_s1;
    s32 sn_s2;
    s32 cs;
    s32 q;
    s32 v;
    s32 n;
    s32 hit;
    SV_986E0 t;
    Hoop_986E0 *h;
    Hoop_986E0 *hh;
    Hoop_986E0 *h0;
    Col_986E0 *k;
    s32 tz;
    s32 tx;
    if (g_Game.f_8100 & 1) {
        Hoop_UpdateModel();
        return;
    }
    if ((g_Game.f_8152 == 0xB) || (g_SpikeHealth == 0)) {
        sc->f_66 = 0;
        sc->f_7C = 0;
        sc->f_78 = 0;
    } else {
        sc->f_66 = g_Pad.f_182;
        sc->f_78 = g_Pad.f_1B4;
        sc->f_7C = g_Pad.f_1BC;
    }
    g = &g_GadgetState;
    switch (g->state) {
    case 0:
    default:
        if (g->snd1 != (-1)) {
            Sound_Stop(0x2C, g->snd1);
            g->snd1 = -1;
        }
        if (g->snd2 != (-1)) {
            Sound_Stop(0x2D, g->snd2);
            g->snd2 = -1;
        }
        func_8004637C(sc->m);
        g->f_6 = 0;
        if (func_8007CA48(4)) {
            p = g->power;
            g->f_18 = (g_Pad.f_19C * sc->f_66) >> 13;
            sc->f_3C = g->f_18;
            g->f_1C = (g_Pad.f_1A0 * sc->f_66) >> 13;
            sc->f_44 = g->f_1C;
            r = (((s16) sc->f_78) >= 0) ? ((s16) sc->f_78) : (-((s16) sc->f_78));
            if (p > 0x140) {
                g->state = 1;
                g->f_6 = 1;
                if (g->snd1 == (-1)) {
                    g->snd1 = Sound_Play(0, 0x2C);
                }
            }
            p = (p + r) - 8;
            if (p < 0) {
                p = 0;
            }
            D_800F5128 = p;
        } else {
            g->f_18 = 0;
            g->f_1C = 0;
        }
        D_800F513A = 0;
        CompMatrix(sc->m, D_800F4730[*(camIdx = &D_800EC0A0->f_4)], sc->m);
        switch (D_800EC23E) {
        case 0x31:
        case 0x32:
        case 0x33:
            func_8007CD0C(0);
            break;
        default:
            func_8007CD0C(1);
            Hoop_UpdateModel();
            break;
        }
        return;
    case 1:
        break;
    }
    if ((D_800EC23E == 0x8D) && (g->snd2 == (-1))) {
        g->snd2 = Sound_Play(0, 0x2D);
    }
    t.vx = g_Spike.x;
    t.vy = g_Spike.y;
    t.vz = g_Spike.z;
    Effect_SpawnAt(9, &t);
    hit = 0;
    k = g_GadgetState.hit[0];
    if ((k != 0) && (k->f_2C >> 28)) {
        hit = 1;
        g_Spike.f_120 -= k->f_18 << 5;
        tz = k->f_1C;
        g_GadgetState.power -= 0x3C;
        g_Spike.f_128 -= tz << 5;
    }
    hh = &g_GadgetState;
    k = hh->hit[1];
    if ((k != 0) && (k->f_2C >> 28)) {
        hit = 1;
        g_Spike.f_120 -= k->f_18 << 5;
        tz = k->f_1C;
        hh->power -= 0x3C;
        g_Spike.f_128 -= tz << 5;
    }
    hh = &g_GadgetState;
    k = hh->hit[2];
    if ((k != 0) && (k->f_2C >> 28)) {
        hit = 1;
        g_Spike.f_120 -= k->f_18 << 5;
        tz = k->f_1C;
        hh->power -= 0x3C;
        g_Spike.f_128 -= tz << 5;
    }
    if (hit) {
        g_Spike.f_124 += -0x8000;
        Spike_SetState(0x24);
        g_Spike.f_8C = 0;
    }
    switch (D_800EC23E) {
    case 0x31:
    case 0x32:
    case 0x33:
        func_8007CD0C(0);
        D_800F5128 = 0;
        break;
    default:
        func_8007CD0C(1);
        Hoop_UpdateModel();
        break;
    }
    n = g_GadgetState.power;
    n -= 3;
    if (n < 0) {
        g_GadgetState.state = 0;
    } else {
        if (g_GadgetState.snd1 != (-1)) {
            func_80087BA4(0x2C, g_GadgetState.snd1, (n << 3) + 0x200, 0x1000);
        }
        v = (n << 8) / 320;
        if (v > 0x78) {
            v = 0x78;
        }
        Pad_Vibrate(1, v, 2);
    }
    h = &g_GadgetState;
    a = g_Game.f_0 << 8;
    h->power = n;
    c = CollShape_Alloc();
    if (c != 0) {
        sn_s0 = rsin(a);
        cs = rcos(a);
        q = h->power;
        c->f_18 = cs;
        c->f_1A = 0;
        c->f_1C = sn_s0;
        c->x = g_Spike.x + ((cs * q) >> 14);
        c->y = g_Spike.y - 0x80;
        c->z = g_Spike.z + ((sn_s0 * q) >> 14);
        c->f_20 = 0x80;
        c->f_24 = 0x12;
        c->f_26 = 0x201;
        Collision_Set(6, c, &g_Spike);
    }
    h->hit[0] = c;
    a += 0x514;
    c = CollShape_Alloc();
    if (c != 0) {
        sn_s1 = rsin(a);
        cs = rcos(a);
        q = h->power;
        c->f_18 = cs;
        c->f_1A = 0;
        c->f_1C = sn_s1;
        c->x = g_Spike.x + ((cs * q) >> 14);
        c->y = g_Spike.y - 0x80;
        c->z = g_Spike.z + ((sn_s1 * q) >> 14);
        c->f_20 = 0x80;
        c->f_24 = 0x12;
        c->f_26 = 0x201;
        Collision_Set(6, c, &g_Spike);
    }
    h->hit[1] = c;
    a += 0x514;
    c = CollShape_Alloc();
    if (c != 0) {
        sn_s2 = rsin(a);
        cs = rcos(a);
        q = h->power;
        c->f_18 = cs;
        c->f_1A = 0;
        c->f_1C = sn_s2;
        c->x = g_Spike.x + ((cs * q) >> 14);
        c->y = g_Spike.y - 0x80;
        c->z = g_Spike.z + ((sn_s2 * q) >> 14);
        c->f_20 = 0x80;
        c->f_24 = 0x12;
        c->f_26 = 0x201;
        Collision_Set(6, c, &g_Spike);
    }
    h->hit[2] = c;
}

INCLUDE_ASM("asm/nonmatchings/game/800986E0", Hoop_UpdateModel);

