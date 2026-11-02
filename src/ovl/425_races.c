#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

INCLUDE_ASM("asm/ovl/425/nonmatchings/425_races", func_8013D770);

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
