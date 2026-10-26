#include "common.h"
#include "m2c_macros.h"

extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0xEA]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D000 asm("g_Game");

s32 func_8013D000(s16 *p) {
    u8 *e;
    p[1] = p[4];
    p[3] = 0;
    if (g_Game_8013D000.f_8120 == 0x13) {
        return 0;
    }
    if (p[1] == 5) {
        e = g_Game_8013D000.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        e = g_Game_8013D000.f_8220 + p[7] * 0x18;
        M2C_FIELD(e, s16 *, 0xC) = 1;
        e = g_Game_8013D000.f_8220 + p[8] * 0x18;
        M2C_FIELD(e, s16 *, 0xC) = 1;
    } else if ((u16)(p[1] - 2) < 2) {
        e = g_Game_8013D000.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0xA]; u8 f_812C; u8 pad_812D[0xDF]; u8 *f_820C; } g_Game_8013D0FC asm("g_Game");
extern s32 D_800EC250;
s32 SaveByte_Get(s32);
s32 Overlay_GetState_8013D0FC(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 func_800863B0(s32, s32);
s32 func_8008FC30(s16, void *);

s32 func_8013D0FC(s16 *p) {
    s32 x;
    s32 t;
    u8 *e;

    if (g_Game_8013D0FC.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        x = SaveByte_Get(5);
        if (x != 5) {
            return 0;
        }
        if (SaveByte_Get(4) != x) {
            return 0;
        }
        if (g_Game_8013D0FC.f_812C != 3) {
            return 0;
        }
        t = D_800EC250 & 0xF0;
        if (t != 0x10 && t != 0x20 && t != 0x30) {
            return 0;
        }
        p[1] = 1;
        p[3] = 0;
        e = g_Game_8013D0FC.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        func_800863B0(2, 0x28);
        Overlay_Request(6);
        return 0;
    case 1:
        if (Overlay_GetState_8013D0FC() != 0) {
            return 0;
        }
        func_800863B0(0, 0);
        p[1] = 3;
        break;
    case 2:
    case 3:
    case 4:
        if (SaveByte_Get(8) != 5) {
            return 0;
        }
        p[1] = 5;
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        break;
    case 5:
        break;
    }
    return 0;
}

extern struct S_g_Game { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0x116]; u8 *f_8238; } g_Game;
s32 SaveByte_Get(s32);

s32 func_8013D2A0(void) {
    if (g_Game.f_8120 == 0x13) {
        return 0;
    }
    if (SaveByte_Get(10) != 5) {
        M2C_FIELD(g_Game.f_8238, s32 *, 0xA0) = 4;
    }
    return 0;
}

s32 func_8013D300(void) {
    return 0;
}

extern struct S_g_Game_8013D308 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D308 asm("g_Game");
s16 Sound_Play(s32, s32);

s32 func_8013D308(s16 *p) {
    u8 *e = g_Game_8013D308.f_8220 + p[4] * 0x18;

    p[3] = 0;
    if (M2C_FIELD(e, s16 *, 2) >= 2) {
        p[1] = 1;
    } else {
        p[1] = 0;
        p[11] = Sound_Play(1, 0x66);
    }
    return 0;
}

/* only diff: in the loop the -(i+1)*0x2C0/6 result lands in v1 (orig) vs v0 (ours), swapping a subu/sh pair */
typedef struct { s16 f_0; s16 f_2; u8 pad_4[0x14]; } T_8013D388;
typedef struct { s32 x, y, z; u8 pad_C[0xC]; SVECTOR r; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013D388;
extern struct { u8 f_0; u8 pad_1[0x821F]; T_8013D388 *f_8220; } g_Game_8013D388 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D388 asm("g_Spike");
extern u16 g_RandSeed;
Shape_8013D388 *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);
void Sound_Stop(s32, s32);
s32 Sound_UpdateVoice3D_8013D388(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");
void func_8006F274(void *, void *, u16);

s32 func_8013D388(s16 *p) {
    SVECTOR a;
    SVECTOR b;
    SVECTOR c;
    s32 pos[3];
    Shape_8013D388 *s;
    s32 i;
    s32 v;
    s32 w;
    s32 x;
    s32 z;
    s32 d;
    T_8013D388 *t;

    if (p[1] == 0) {
        t = &g_Game_8013D388.f_8220[p[4]];
        if (t->f_2 >= 2) {
            p[1] = 1;
            Sound_Stop(0x66, p[11]);
        } else {
        for (i = 0; i < 5; i++) {
            b.vx = 0xD80;
            a.vx = 0xD80;
            w = -((i + 1) * 0x2C0) / 6;
            a.vz = -0x300;
            b.vz = -0x700;
            b.vy = w;
            a.vy = w;
            func_8006F274(&a, &b, g_Game_8013D388.f_0 * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8));
            func_8006F274(&a, &b, g_Game_8013D388.f_0 * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        }
        c.vx = 0xD00;
        c.vy = -0x12E;
        c.vz = -0x500;
        Sound_UpdateVoice3D_8013D388(0x66, p[11], 0x1800, &c);
        x = g_Spike_8013D388.x;
        v = x - 0xD80;
        if (v < 0) {
            v = -v;
        }
        if (v <= 0x100) {
            z = g_Spike_8013D388.z;
            d = ABS(z + 0x500);
            if (d <= 0x200) {
                c.vz = 0;
                c.vy = 0;
                c.vx = 0;
                pos[0] = x;
                pos[2] = z;
                pos[1] = g_Spike_8013D388.y;
                if (d <= 0x1C0) {
                    pos[0] = x + 0x40;
                    c.vx = -0x1000;
                } else if (z >= -0x4FF) {
                    pos[2] = z - 0x40;
                    c.vz = 0x1000;
                } else {
                    pos[2] = z + 0x40;
                    c.vz = -0x1000;
                }
                s = CollShape_Alloc();
                if (s != NULL) {
                    s->r = c;
                    s->x = pos[0];
                    s->y = pos[1];
                    s->z = pos[2];
                    s->f_20 = 0x80;
                    s->f_24 = 0x401;
                    s->f_26 = 0x202;
                    Collision_Set(6, s, NULL);
                }
            }
        }
        }
    }
    return 0;
}

s32 SaveByte_Get(s32);
void func_80010CDC(s32);

s32 func_8013D66C(void) {
    if (SaveByte_Get(8) == 5) {
        func_80010CDC(1);
    } else {
        func_80010CDC(0);
    }
    return 0;
}

/* the original text ends with three words of padding after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
