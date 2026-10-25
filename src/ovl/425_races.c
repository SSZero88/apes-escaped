#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = 0;
    return 0;
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_8013D010;
extern Monkey_8013D010 g_Monkeys_8013D010[] asm("g_Monkeys");
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; } g_Game_8013D010 asm("g_Game");
extern s32 D_800EC204;
extern s32 D_800EC20C;
s32 func_8013D290(s32 type, s32 idx);
void Game_SetMode(s32, s32, s32);

s32 func_8013D010(s16 *p) {
    s32 i;
    Monkey_8013D010 *m;

    switch (p[1]) {
    case 0:
        if (ABS(D_800EC20C - p[6]) < p[8] && ABS(D_800EC204 - p[4]) < p[7]) {
            p[1] = 1;
            g_Game_8013D010.f_812A = 2;
            Game_SetMode(0x12, g_Game_8013D010.f_8126, 2);
            func_8013D290(0xF, -1);
            break;
        }
        i = 0;
        m = g_Monkeys_8013D010;
    loop:
        if (m->f_7A == 4 && ABS(m->z - p[6]) < p[8] && ABS(m->x - p[4]) < p[7]) {
            p[1] = 2;
            p[10] = i;
            func_8013D290(0xE, (s16)i);
            break;
        }
        m++;
        i++;
        if (i < 8) {
            goto loop;
        }
        break;
    case 1:
        func_8013D290(0xF, -1);
        break;
    case 2:
        if (ABS(D_800EC20C - p[6]) < p[8] && ABS(D_800EC204 - p[4]) < p[7]) {
            p[1] = 3;
            Game_SetMode(0x1A, g_Game_8013D010.f_8126, g_Game_8013D010.f_812A);
        }
    case 3:
        func_8013D290(0xE, p[10]);
        break;
    }
    return 0;
}

typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR rot; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Shape_8013D290;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_8013D290;
extern Monkey_8013D290 g_Monkeys_8013D290[] asm("g_Monkeys");
extern u8 g_Spike_8013D290[] asm("g_Spike");
void *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 func_8013D290(s32 type, s32 idx) {
    SVECTOR v;
    s32 i;
    Monkey_8013D290 *m;
    Shape_8013D290 *s;

    v.vx = 0x1000;
    v.vz = 0;
    v.vy = 0;
    if (idx < 0) {
        for (i = 0; i < 8; i++) {
            m = &g_Monkeys_8013D290[i];
            if (m->f_7A == 4) {
                s = CollShape_Alloc();
                if (s != NULL) {
                    s->rot = v;
                    s->x = m->x;
                    s->y = m->y;
                    s->z = m->z;
                    s->f_20 = 0x200;
                    s->f_24 = 0;
                    s->f_26 = 0;
                    Collision_Set(type, s, g_Spike_8013D290);
                }
            }
        }
    } else {
        s = CollShape_Alloc();
        if (s != NULL) {
            s->rot = v;
            s->x = g_Monkeys_8013D290[idx].x;
            s->y = g_Monkeys_8013D290[idx].y;
            s->z = g_Monkeys_8013D290[idx].z;
            s->f_20 = 0x200;
            s->f_24 = 0;
            s->f_26 = 0;
            Collision_Set(type, s, g_Spike_8013D290);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/425/nonmatchings/425_races", func_8013D424);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
void VectorNormalSS(void *, void *);
extern struct { u8 pad0[0xA]; s16 f_A; } D_800E68C0;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike;

void func_8013D5C4(void *arg0) {
    SVECTOR v;

    ((Scr_401 *)0x1F800000)->spike.vx = g_Spike.x;
    ((Scr_401 *)0x1F800000)->spike.vy = g_Spike.y;
    ((Scr_401 *)0x1F800000)->spike.vz = g_Spike.z;
    func_8004B8F4(arg0, 2, &v);
    v.vy += D_800E68C0.f_A;
    ((Scr_401 *)0x1F800000)->eye.vx = ((Scr_401 *)0x1F800000)->spike.vx;
    ((Scr_401 *)0x1F800000)->eye.vy = g_Spike.y - 0x100;
    ((Scr_401 *)0x1F800000)->eye.vz = ((Scr_401 *)0x1F800000)->spike.vz;
    func_80047558(arg0, 6, 6, 6);
    ((Scr_401 *)0x1F800000)->at.vx = (v.vx * 7 + ((Scr_401 *)0x1F800000)->spike.vx) / 8;
    ((Scr_401 *)0x1F800000)->at.vy = v.vy - D_800E68C0.f_A * 2;
    ((Scr_401 *)0x1F800000)->dir.vx = ((Scr_401 *)0x1F800000)->spike.vx - M2C_FIELD(arg0, s16 *, 0xA);
    ((Scr_401 *)0x1F800000)->dir.vy = 0;
    ((Scr_401 *)0x1F800000)->dir.vz = ((Scr_401 *)0x1F800000)->spike.vz - M2C_FIELD(arg0, s16 *, 0xE);
    VectorNormalSS(&((Scr_401 *)0x1F800000)->dir, &((Scr_401 *)0x1F800000)->dir);
    ((Scr_401 *)0x1F800000)->at.vz = ((Scr_401 *)0x1F800000)->spike.vz - ((Scr_401 *)0x1F800000)->dir.vz / 3;
    func_80047464(arg0, 6, 6, 6);
}


__asm__(".section .text\n.balign 16");

INCLUDE_ASM("asm/ovl/425/nonmatchings/425_races", func_8013D730);

void func_8013DAA0(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

extern u16 D_800AE8F2;
extern u16 g_RandSeed;
extern u32 D_8013DF28[];
extern s32 D_8013DDE0[];
extern s32 D_800B1F1C[];
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
void Object_ApplyVelocity(void *);
void Object_PlaceRandomAroundHome(void *, s16);
s32 func_8005588C(void *, s32);
void func_80070284(void *, s32 *, s32, s32, s32);
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
void func_8013DAA0(void *arg0, M2C_UNK arg1);
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x10]; u16 frame; u8 pad5E[0x21]; u8 anim; u8 pad80[8]; u16 *anims; u8 pad8C[8]; s16 vx, vy, vz; u8 pad9A[2]; s16 floor; u8 pad9E[2]; s16 fA0; u8 padA2[0xE]; s16 fB0; u8 padB2[0x17]; u8 timer; u8 padCA[0x16]; u32 b0:1, b1:1, b2:1, b3:1; } Obj_8013DAEC;

void func_8013DAEC(Obj_8013DAEC *e) {
    SVECTOR v;
    s32 i;

    if (!e->b3) {
        e->fA0 = 0x32;
        e->fB0 = 0x5B;
        e->f48 = 0x201;
        e->f4A = -0x7DFE;
        e->f46 = 1;
        e->f44 = 1;
        Object_PlaceRandomAroundHome(e, 0x64);
        e->vy = -0x78 - (s32)((u32)(((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 5);
        e->anim = 0;
        e->y += 0x64;
        e->frame = e->anims[0];
        e->b3 = 1;
    }
    e->vy += 4;
    Object_ApplyVelocity(e);
    if (!e->b2) {
        v.vx = e->x;
        v.vy = e->y;
        v.vz = e->z;
        Object_AddAttackSphereNear(e, 0x64, e->x, e->y, (s16)e->z, e->f48, e->f4A);
        Effect_Spawn(0xC8, &v.vx, D_8013DF28, 0);
        Effect_Spawn(0xC8, &v.vx, D_8013DF28, 0);
        if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7)) {
            Effect_Spawn(0xC9, &v.vx, D_8013DF28, 0);
        }
    }
    if (e->timer == 0) {
        if (e->floor < e->y) {
            v.vx = e->x;
            v.vy = e->floor;
            v.vz = e->z;
            func_80070284(&v, D_8013DDE0, 1, 0, 0);
            func_80070284(&v, D_800B1F1C, 1, 0, 0);
            for (i = 0; i < 0x10; i++) {
                Effect_Spawn(0xCA, &v.vx, D_8013DF28, 0);
            }
            Object_PlaceRandomAroundHome(e, 0x12C);
            e->vz = 0;
            e->vx = 0;
            e->y = e->floor;
            e->vy = -0x78 - (s32)((u32)(((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 5);
            func_8005588C(e, 0x1E);
            func_8013DAA0(e, 0x94);
            func_8013DAA0(e, 0x43);
        }
    } else {
        e->timer--;
    }
}
