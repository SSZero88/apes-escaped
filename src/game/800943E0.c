#include "common.h"
#include "m2c_macros.h"
#define SP_94C10 ((struct Act_80094C10 *)&g_Spike)
#define RC_94C10 ((struct Act_80094C10 *)&g_RcCar)
#define GM_94C10 ((struct Game_80094C10 *)&g_Game)
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; u8 padC[0xC]; } S_8220_80094A48;
typedef struct { s16 x, y, z; u8 pad6[8]; s16 f_E; u8 pad10[0x28]; } Solid_80094C10_80094C10;
typedef struct { s16 f_0; u8 pad2[2]; s16 f_4; u8 pad6[4]; s16 f_A; u8 padC[0xC]; } Link_80094C10_80094C10;
typedef struct { u8 pad0[0x10]; s16 x, y, z; u8 pad16[0xA]; } Mdl_80094C10_80094C10;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; s16 f_C; u16 f_E; u16 f_10; u16 f_12; } T_8009468C_8009468C;
typedef struct { u16 x, y, z; u8 pad6[0x12]; u16 f_18; u8 pad1A[0x18]; s16 f_32; u8 pad34[4]; } O_8009468C_8009468C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; s16 f_C; u8 padE[2]; s16 f_10; u16 f_12; u16 f_14; u16 f_16; } T_800943E0_800943E0;
typedef struct { u16 x, y, z; u8 pad6[0x12]; u16 f_18; u8 pad1A[0x18]; s16 f_32; u8 pad34[4]; } O_800943E0_800943E0;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; u8 padC[0xC]; } S_8220_80094AE0;

/* Moves the stage object of link record g_Game+0x8220[idx] by (dx, dy, dz): Spike (and the camera,
 * via Camera_Translate) and the RC car move with it while standing in it (Box_ContainsPoint), and so
 * does its model D_800B4D64[obj +0xE]. A type-0xB link continues to the record in its +0xA, so a
 * whole chain of objects moves together. */
s32 Platform_MoveChain(s32 idx, s16 dx, s16 dy, s16 dz);

extern s32 D_800B4D64;

s32 func_80094B6C(s16 i, s16 *a, s16 *b);
extern struct S_D_800EC350 { u8 pad_0[0x820C]; s32 f_820C; u8 pad_8210[0x10]; s32 f_8220; } g_Game;
extern s16 D_800EC238;
struct Act_80094C10 { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s32 f_70; };
struct Game_80094C10 { u8 pad0[0x820C]; Solid_80094C10_80094C10 *f_820C; u8 pad8210[0x10]; Link_80094C10_80094C10 *f_8220; };
extern M2C_UNK g_Spike;
extern M2C_UNK g_RcCar;
s32 Box_ContainsPoint(Solid_80094C10_80094C10 *, s32, s32, s32);
void Camera_Translate(s32, s32, s32);
struct Game_8009468C { u8 pad0[0x820C]; O_8009468C_8009468C *f_820C; };
s32 func_80094A48(s32 i);
s32 Monkey_AnyInBox();
void Sound_PlayAt(s32, O_8009468C_8009468C *);
struct Game_800943E0 { u8 pad0[0x820C]; O_800943E0_800943E0 *f_820C; };
s32 func_800949BC(s16 arg0, s16 arg1);

/* Toggle switch (two positions). State 0 (up) / 2 (down): a fresh press - Spike standing on it
 * (g_Spike+0x58) or Monkey_AnyInBox, while not still held (+6) - starts it moving (state 1 / 3),
 * plays sound 0x9C and notifies the linked object (func_800949BC(t->f_A, 1 / 3)); stepping off
 * clears the hold. States 1 / 3 move it (func_80094B6C) until it settles (counter +0x32), then
 * click (sound 0x9C) into state 2 / 0. Returns 0. */
struct Game_80094AE0 { u8 pad0[0x8220]; S_8220_80094AE0 *f_8220; };
#define GM_80094AE0 ((struct Game_80094AE0 *)&g_Game)

s32 ToggleSwitch_Update(T_800943E0_800943E0 *t) {
    O_800943E0_800943E0 *o = &(*(struct Game_800943E0 *)&g_Game).f_820C[t->f_4];
    switch (t->f_2) {
    case 0:
        if ((D_800EC238 == t->f_4 || Monkey_AnyInBox(o)) && t->f_6 == 0) {
            o->f_18 = (o->f_18 & 0xFFF0) | 2;
            t->f_6 = 1;
            t->f_2 = 1;
            t->f_12 = o->x;
            t->f_14 = o->y;
            t->f_16 = o->z;
            Sound_PlayAt(0x9C, o);
            if (t->f_A >= 0) {
                func_800949BC(t->f_A, 1);
            }
        } else if (D_800EC238 < 0 && t->f_6 != 0) {
            t->f_6 = 0;
        }
        break;
    case 1:
        if (t->f_10 >= 0) {
            func_80094B6C(t->f_10, o, &t->f_12);
        }
        if (o->f_32 >= t->f_C * 2 + 1) {
            o->f_18 = (o->f_18 & 0xFFF0) | 1;
            t->f_2 = 2;
            Sound_PlayAt(0x9C, o);
            t->f_6 = D_800EC238 == t->f_4;
        }
        break;
    case 2:
        if ((D_800EC238 == t->f_4 || Monkey_AnyInBox(o)) && t->f_6 == 0) {
            o->f_18 = (o->f_18 & 0xFFF0) | 2;
            t->f_2 = 3;
            t->f_6 = 1;
            t->f_12 = o->x;
            t->f_14 = o->y;
            t->f_16 = o->z;
            Sound_PlayAt(0x9C, o);
            if (t->f_A >= 0) {
                func_800949BC(t->f_A, 3);
            }
        } else if (D_800EC238 < 0 && t->f_6 != 0) {
            t->f_6 = 0;
        }
        break;
    case 3:
        if (t->f_10 >= 0) {
            func_80094B6C(t->f_10, o, &t->f_12);
        }
        if (o->f_32 == 1) {
            o->f_18 = (o->f_18 & 0xFFF0) | 1;
            t->f_2 = 0;
            Sound_PlayAt(0x9C, o);
            t->f_6 = D_800EC238 == t->f_4;
        }
        break;
    }
    return 0;
}

/* Floor switch (stage object g_Game+0x820C[t->f_4]). State 0: when not already held (t->f_6)
 * and Spike stands on it (g_Spike+0x58), Monkey_AnyInBox says so, or link t->f_A reports a press,
 * it is pressed: object state 2, start position saved, sound 0x9C, state 1. State 1 moves it
 * (func_80094B6C) until its counter +0x32 reaches t->f_C*2+1, then it pops back (state 1 on the
 * object, sound 0x9C) and stays held while still stood on. Returns 0. */
s32 FloorSwitch_Update(T_8009468C_8009468C *t) {
    O_8009468C_8009468C *o = &(*(struct Game_8009468C *)&g_Game).f_820C[t->f_4];
    s32 pressed;
    switch (t->f_2) {
    case 0:
        pressed = func_80094A48(t->f_A);
        if (t->f_6 == 0 && (D_800EC238 == t->f_4 || Monkey_AnyInBox(o) || pressed)) {
            o->f_18 = (o->f_18 & 0xFFF0) | 2;
            t->f_6 = 1;
            t->f_2 = 1;
            t->f_E = o->x;
            t->f_10 = o->y;
            t->f_12 = o->z;
            Sound_PlayAt(0x9C, o);
        } else if (D_800EC238 != t->f_4 && !pressed) {
            t->f_6 = 0;
        }
        break;
    case 1:
        func_80094B6C(t->f_A, o, &t->f_E);
        if (o->f_32 >= t->f_C * 2 + 1) {
            o->f_18 = (o->f_18 & 0xFFF0) | 1;
            t->f_2 = 0;
            Sound_PlayAt(0x9C, o);
            if (t->f_A >= 0) {
                pressed = func_80094A48(t->f_A);
            }
            if (D_800EC238 != t->f_4 && !pressed) { t->f_6 = 0; } else { t->f_6 = 1; }
        }
        break;
    }
    return 0;
}

s32 func_80094850(void *arg0) {
    s16 temp_a0;
    s16 temp_a0_2;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x14);
    if (M2C_FIELD(arg0, s16 *, 8) == 0) {
        temp_a0 = M2C_FIELD(temp_a1, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    if ((s16) M2C_FIELD(arg0, u16 *, 0x14) == 1) {
        temp_a0_2 = M2C_FIELD(temp_a1, s16 *, 0xE);
        if (temp_a0_2 >= 0) {
            M2C_FIELD(((temp_a0_2 << 5) + D_800B4D64), u16 *, 0x16) = 0xFFFF;
        }
        M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 2);
    }
    return 0;
}

s32 func_80094918(void *arg0) {
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 2) == 1) {
        func_80094B6C(M2C_FIELD(arg0, s16 *, 0xA), temp_s0, arg0 + 0xE);
        if (M2C_FIELD(temp_s0, s16 *, 0x32) >= (M2C_FIELD(arg0, s16 *, 0xC) * 2)) {
            M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_s0, u16 *, 0x18) & 0xFFF0) | 1);
            M2C_FIELD(arg0, s16 *, 2) = 2;
        }
    }
    return 0;
}

s32 func_800949BC(s16 arg0, s16 arg1) {
    void *temp_a0;
    void *temp_v1;

    temp_a0 = g_Game.f_8220 + (arg0 * 0x18);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(temp_a0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 2);
    M2C_FIELD(temp_a0, s16 *, 2) = arg1;
    M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 0);
    M2C_FIELD(temp_a0, u16 *, 0x14) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(temp_a0, u16 *, 0x16) = (u16) M2C_FIELD(temp_v1, u16 *, 4);
    return 0;
}

s32 func_80094A48(s32 i) {
    S_8220_80094A48 *r;
    if (i >= 0) {
        r = &((S_8220_80094A48 *)g_Game.f_8220)[i];
        if (r->f_4 == D_800EC238) {
            return 1;
        }
        if (r->f_0 == 11 && r->f_A >= 0 && func_80094A48(r->f_A) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_80094AE0(s32 i) {
    if (i >= 0) {
        S_8220_80094AE0 *r = &GM_80094AE0->f_8220[i];
        *(s16 *)((u8 *)r + 2) = 0;
        r->f_6 = D_800EC238 == r->f_4;
        if (r->f_0 != 11) {
            return 0;
        }
        if (r->f_A < 0) {
            return 0;
        }
        func_80094AE0(r->f_A);
    }
    return 0;
}

s32 func_80094B6C(s16 i, s16 *a, s16 *b) {
    if (i < 0) {
        return 0;
    }
    Platform_MoveChain(i, a[0] - b[0], a[1] - b[1], a[2] - b[2]);
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    return 0;
}

s32 Platform_MoveChain(s32 idx, s16 dx, s16 dy, s16 dz) {
    s16 ax = dx;
    s16 ay = dy;
    s16 az = dz;
    Link_80094C10_80094C10 *l;
    Solid_80094C10_80094C10 *o;
    if (idx < 0) {
        return 0;
    }
    l = &GM_94C10->f_8220[idx];
    o = &GM_94C10->f_820C[l->f_4];
    if (Box_ContainsPoint(o, SP_94C10->x, SP_94C10->y, SP_94C10->z) != 0) {
        SP_94C10->x += dx;
        SP_94C10->y += dy;
        SP_94C10->z += dz;
        Camera_Translate(dx, dy, dz);
    }
    if (RC_94C10->f_70 != 0 && Box_ContainsPoint(o, RC_94C10->x, RC_94C10->y, RC_94C10->z) != 0) {
        RC_94C10->x += dx;
        RC_94C10->y += dy;
        RC_94C10->z += dz;
    }
    o->x += ax;
    o->y += ay;
    o->z += az;
    if (o->f_E >= 0) {
        (*(Mdl_80094C10_80094C10 * *)&D_800B4D64)[o->f_E].x += ax;
        (*(Mdl_80094C10_80094C10 * *)&D_800B4D64)[o->f_E].y += ay;
        (*(Mdl_80094C10_80094C10 * *)&D_800B4D64)[o->f_E].z += az;
    }
    if (l->f_0 == 0xB && l->f_A >= 0) {
        Platform_MoveChain(l->f_A, ax, ay, az);
    }
    return 0;
}

typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } MonkeyBox_80094E5C;
extern u8 g_Monkeys[];

/* 1 if a spawned monkey (+0x7A == 4) stands in box b {x, y, z, half-x, height, half-z}:
   |dx| < b[3], |dz| < b[5] and b[1] - b[4] - 16 <= y < b[1]. */
s32 Monkey_AnyInBox(s16 *b) {
    s32 dz;
    s32 i;
    s32 d;
    MonkeyBox_80094E5C *m;
    for (i = 0; i < 8; i++) {
        m = &((MonkeyBox_80094E5C *)g_Monkeys)[i];
        if (m->f_7A != 4) {
            continue;
        }
        dz = m->f_2C - b[2];
        d = dz;
        if (((d < 0) ? -d : d) >= b[5]) {
            continue;
        }
        d = m->f_24 - b[0];
        if (((d < 0) ? -d : d) >= b[3]) {
            continue;
        }
        if (m->f_28 >= b[1] - b[4] - 16 && m->f_28 < b[1]) {
            return 1;
        }
    }
    return 0;
}
