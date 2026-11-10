#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

typedef struct { u16 start; u16 end; } Rng_8013D770;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013D770;
s32 Object_Timer(void *, s32);
void Object_DebugStub(void *, s32);
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
s32 Floor_GetHeight_8013D770(s32, s32, s32) asm("Floor_GetHeight");
s32 rcos_8013D770(s32) asm("rcos");
s32 rsin_8013D770(s32) asm("rsin");
void Shadow_Draw(void *, s32, s32, s32);

void Swinger_Update(u8 *o) {
    s32 f;
    s32 ang;
    s32 dx;
    s32 dz;
    Vec_8013D770 v;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x3C;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 0x64;
        M2C_FIELD(o, s16 *, 0x4A) = -0x3EFF;
        M2C_FIELD(o, s16 *, 0x48) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C) - 0xD7;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x200;
        M2C_FIELD(o, volatile u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D770 **, 0x88)[0].start;
        if ((u8)(M2C_FIELD(o, u8 *, 0x7E) - 0x59) < 3) {
            M2C_FIELD(o, volatile u32 *, 0xE0) |= 0x80000;
            M2C_FIELD(o, u16 *, 0x5C) = ((*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88))) + (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2))) >> 1;
        } else {
            M2C_FIELD(o, u32 *, 0xE0) &= ~0x80000;
        }
        Object_Timer(o, 0);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xC9)) {
        M2C_FIELD(o, u8 *, 0xC9)--;
    } else {
        Object_Timer(o, 0x16);
        if (Spike_WithinRadiusXZ(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), 0x400)) {
            Object_PlaySound(o, 0x81);
        }
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 19) & 1) {
        f = M2C_FIELD(o, u16 *, 0x5C) - 2;
        if (f < (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)))) {
            { s32 d = (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88))) - f; s32 e = (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) + 1; f = e - d; }
        }
        M2C_FIELD(o, u16 *, 0x5C) = f;
    }
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 2) & 1)) {
        ang = ((M2C_FIELD(o, u16 *, 0x5C) - (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)))) << 12) / ((*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) - (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88))) + 1);
        ang = (ang + 0x5FA) % 4096;
        dx = rcos_8013D770(ang) * 797 >> 12;
        dz = rsin_8013D770(ang) * 797 >> 12;
        Object_AddAttackSphereNear(o, 0x78, M2C_FIELD(o, u16 *, 0x24) + dx, M2C_FIELD(o, s16 *, 0x28), (s16)(M2C_FIELD(o, u16 *, 0x2C) + dz), 1, 0x203);
        v.vx = M2C_FIELD(o, s32 *, 0x24) + dx;
        v.vy = M2C_FIELD(o, s32 *, 0x28);
        v.vz = M2C_FIELD(o, s32 *, 0x2C) + dz;
        Shadow_Draw(&v, Floor_GetHeight_8013D770(v.vx, v.vy, v.vz), 100, *(s32 *)0x1F8003FC);
    }
}

void Obj_PlaySoundIfSpikeNear(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

extern u16 g_RandSeed2;
extern u16 g_RandSeed;
extern u32 D_8013DF28[];
extern s32 D_8013DDE0[];
extern s32 D_800B1F1C[];
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
void Object_ApplyVelocity(void *);
void Object_PlaceRandomAroundHome(void *, s16);
s32 Object_Timer(void *, s32);
void Shockwave_Spawn(void *, s32 *, s32, s32, s32);
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
void Obj_PlaySoundIfSpikeNear(void *arg0, M2C_UNK arg1);
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x10]; u16 frame; u8 pad5E[0x21]; u8 anim; u8 pad80[8]; u16 *anims; u8 pad8C[8]; s16 vx, vy, vz; u8 pad9A[2]; s16 floor; u8 pad9E[2]; s16 fA0; u8 padA2[0xE]; s16 fB0; u8 padB2[0x17]; u8 timer; u8 padCA[0x16]; u32 b0:1, b1:1, b2:1, b3:1; } Obj_8013DAEC;

void Lobber_Update(Obj_8013DAEC *e) {
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
        e->vy = -0x78 - (s32)((u32)(((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 5);
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
            Shockwave_Spawn(&v, D_8013DDE0, 1, 0, 0);
            Shockwave_Spawn(&v, D_800B1F1C, 1, 0, 0);
            for (i = 0; i < 0x10; i++) {
                Effect_Spawn(0xCA, &v.vx, D_8013DF28, 0);
            }
            Object_PlaceRandomAroundHome(e, 0x12C);
            e->vz = 0;
            e->vx = 0;
            e->y = e->floor;
            e->vy = -0x78 - (s32)((u32)(((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) * 5) >> 5);
            Object_Timer(e, 0x1E);
            Obj_PlaySoundIfSpikeNear(e, 0x94);
            Obj_PlaySoundIfSpikeNear(e, 0x43);
        }
    } else {
        e->timer--;
    }
}
