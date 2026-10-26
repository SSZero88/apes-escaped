#include "common.h"
#include "m2c_macros.h"

M2C_UNK VectorNormalSS(void *, void *);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_800573A0(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void Object_TurnToward(void *, s16, s16, s16, s16);
extern struct S_g_Game { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xE4]; s32 f_820C; u8 pad_8210[0x4]; s32 f_8214; } g_Game;
s32 func_800889A4();

extern struct S_D_800E7880 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; } D_800E7880;

M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Object_SpawnEffect(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
s32 Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
void *Collision_GetShape(s32);
M2C_UNK Object_Destroy(void *);
M2C_UNK func_800880D0(M2C_UNK, s16);
extern M2C_UNK D_801434C0;
extern M2C_UNK D_801434C4;
s32 SaveByte_Get(M2C_UNK);
extern s32 D_800B4D64;

typedef struct { u8 pad[0x40]; s32 f_40; } Ob_8013D000;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013D000;
typedef struct { s16 x0, y0, z0, w0, x1, y1, z1; } Scr_8013D000;
s32 func_8013FA8C(s32 *arg0, void **arg1);
s32 VectorNormalSS_8013D000(void *, void *) asm("VectorNormalSS");
s32 Math_Atan2_8013D000(s32, s32) asm("Math_Atan2");
void RotMatrixZYX_8013D000(SVECTOR *, Mat_8013D000 *) asm("RotMatrixZYX");
void Matrix_RotateY_8013D000(s32, Mat_8013D000 *) asm("Matrix_RotateY");
void ApplyMatrixSV_8013D000(Mat_8013D000 *, SVECTOR *, SVECTOR *) asm("ApplyMatrixSV");
void func_80047558(void *, s32, s32, s32);
void func_80047464(void *, s32, s32, s32);

void func_8013D000(u8 *o) {
    SVECTOR n;
    SVECTOR r;
    SVECTOR v;
    Mat_8013D000 m;
    s16 *a;
    s16 *b;
    Scr_8013D000 *sp = (Scr_8013D000 *)0x1F800000;
    s32 t;
    s32 c;
    s32 z;

    func_8013FA8C((s32 *)&a, (void **)&b);
    n.vx = a[3];
    n.vy = a[4];
    n.vz = a[5];
    VectorNormalSS_8013D000(&n, &n);
    ((Ob_8013D000 *)o)->f_40 = (Math_Atan2_8013D000(-a[3], -a[5]) + 0x1000) % 0x1000;
    r.vx = -(a[3] * 4096) / 36000;
    r.vy = -(a[4] * 4096) / 36000;
    r.vz = -(a[5] * 4096) / 36000;
    RotMatrixZYX_8013D000(&r, &m);
    Matrix_RotateY_8013D000(0x400, &m);
    v.vx = 0;
    v.vy = 0;
    v.vz = -0x1000;
    ApplyMatrixSV_8013D000(&m, &v, &v);
    sp->x1 = a[0] + v.vx / 4;
    sp->y1 = a[1] + v.vy / 3 - 300;
    sp->z1 = a[2] + v.vz / 4;
    func_80047558(o, 4, 2, 4);
    sp->x0 = a[0] - v.vx / 3;
    sp->y0 = a[1] - v.vy / 3 - 550;
    sp->y0 += b[1] / 2;
    sp->z0 = a[2] - v.vz / 3;
    func_80047464(o, 2, 4, 2);
    t = -((v.vz * M2C_FIELD(o, s16 *, 0x1A) - v.vx * M2C_FIELD(o, s16 *, 0x1E)) >> 12) / 8;
    t = t < -10 ? -10 : (t > 10 ? 10 : t);
    M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s32 *, 0x2C) * 7 / 8 + t;
    M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s32 *, 0x2C) < -700 ? -700 : (M2C_FIELD(o, s32 *, 0x2C) > 700 ? 700 : M2C_FIELD(o, s32 *, 0x2C));
    *(SVECTOR *)(o + 0x1A) = v;
}

void func_8006D568(void *);

void func_8013D374(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x8F) != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        M2C_FIELD(arg0, u16 *, 0xBC) += M2C_FIELD(arg0, u16 *, 0x94);
        M2C_FIELD(arg0, u16 *, 0xBE) += M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0xC0) += M2C_FIELD(arg0, u16 *, 0x98);
        v.vx = M2C_FIELD(arg0, u16 *, 0xBC);
        v.vy = M2C_FIELD(arg0, u16 *, 0xBE);
        v.vz = M2C_FIELD(arg0, u16 *, 0xC0);
        func_8006D568(&v);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x50, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        if (M2C_FIELD(arg0, u8 *, 0x8F) >= 0x33) {
            M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        }
    }
}

void func_8013D444(void *arg0) {
    u8 st;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        st = M2C_FIELD(arg0, u8 *, 0x7F);
        if (st == 2 && M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4) + 7) {
            M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x96) = (M2C_FIELD(arg0, s16 *, 0x62) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0xBC) = M2C_FIELD(arg0, u16 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94) * 2;
            M2C_FIELD(arg0, s16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96) * 2;
            M2C_FIELD(arg0, s16 *, 0xC0) = M2C_FIELD(arg0, u16 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98) * 2;
            Object_PlaySound(arg0, 0x4D);
            M2C_FIELD(arg0, s8 *, 0x8F) = 1;
            M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        }
    }
}

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013D540(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_8013D574(void *arg0) {
    if (func_8013D540(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8013D5C8(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

void func_80058134();
void func_80054220(void *);
void func_8013D374(void *arg0);
void func_8013D444(void *arg0);
void func_8013D574(void *arg0);
void func_8013D5C8(void *arg0);
typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_8013D630;

void func_8013D630(u8 *e) {
    u8 state;

    if (!M2C_FIELD(e, Flags_8013D630 *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(e, s16 *, 0x44) = 0x3C;
        M2C_FIELD(e, s16 *, 0x48) = 0x201;
        M2C_FIELD(e, s16 *, 0x4A) = 0x8202;
        M2C_FIELD(e, s16 *, 0x46) = 0x64;
        e[0xCD] = 3;
        e[0xDC] = 5;
        e[0xC9] = 0;
        e[0x7F] = 0;
        M2C_FIELD(e, s16 *, 0x9C) -= 200;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C);
        M2C_FIELD(e, Flags_8013D630 *, 0xE0).mode = 2;
        M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
        M2C_FIELD(e, Flags_8013D630 *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    func_8013D5C8(e);
    switch (e[0x80]) {
    case 1:
        if (e[0xC9] == 0) {
            func_8013D574(e);
        }
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            if (e[0xC9] != 0) {
                e[0xC9]--;
            }
        }
        break;
    case 2:
        func_8013D444(e);
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            if (e[0x7F] == 2) {
                e[0x80] = 1;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
                e[0xC9] = 5;
            } else {
                e[0x7F] = 2;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
            }
        }
        break;
    }
    func_8013D374(e);
    func_80054220(e);
}

typedef struct { u16 start; u16 end; } Rng_8013D810;
typedef struct { u8 pad_0[0x5C]; u16 frame; u8 pad_5E[0x2A]; Rng_8013D810 *anim; } Obj_8013D810;
typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 28; } Flags_8013D810;
extern struct { u8 pad_0[0x8126]; u16 f_8126; } g_Game_8013D810 asm("g_Game");
extern u8 D_800E77E2;
extern s32 D_800EC208;
extern u16 g_RandSeed;
extern u16 D_800AE8F2;
void func_80055F1C(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
s32 func_8005588C_8013D810(void *, s32) asm("func_8005588C");
void Object_ChaseSpike(void *, s32);
s32 rsin_8013D810(s32) asm("rsin");
M2C_UNK Object_ApplyVelocity(void *);
s32 Object_DetachLink_8013D810(void *, s32) asm("Object_DetachLink");
s32 Object_AddAttackSphereNear_8013D810(void *, s32, s32, s32, s32, s32, s32) asm("Object_AddAttackSphereNear");
void Object_PlaySound_8013D810(void *, s32) asm("Object_PlaySound");
s32 Math_WithinSquare(s32, s32, s32);
M2C_UNK func_80055AA0(void *, s16, s16, s32);

void func_8013D810(u8 *e) {
    s32 d;

    if (!M2C_FIELD(e, Flags_8013D810 *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x71;
        M2C_FIELD(e, s16 *, 0x4A) = 0x8101;
        M2C_FIELD(e, s16 *, 0xAA) = 0;
        M2C_FIELD(e, s16 *, 0x48) = 0;
        e[0xC8] = 6;
        e[0xDC] = 0;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 0x32;
        func_80055F1C(e, 0x12);
        e[0x7F] = 1;
        M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
        M2C_FIELD(e, Flags_8013D810 *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    switch (e[0x80]) {
    case 1:
        if (g_Game_8013D810.f_8126 == 0x33 && D_800E77E2 != 1) {
            break;
        }
        if (M2C_FIELD(e, s16 *, 0x9C) < D_800EC208 && D_800EC208 - M2C_FIELD(e, s16 *, 0x9C) < 0x800 && Object_SpikeInFront(e, 0x168, -0x1000, 0x400)) {
            e[0x80] = 2;
            e[0x7F] = 0;
            ((Obj_8013D810 *)e)->frame = ((Obj_8013D810 *)e)->anim[0].start;
            func_8005588C_8013D810(e, (s32)((u32)((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5 >> 6) + 0x28);
        }
        break;
    case 2:
        Object_ChaseSpike(e, 0x12);
        M2C_FIELD(e, s16 *, 0xAA) = (M2C_FIELD(e, s16 *, 0xAA) + 0xAA) % 0x1000;
        d = (-(M2C_FIELD(e, s32 *, 0x28) + 0x100) + D_800EC208) >> 3;
        if ((d < 0 ? -d : d) > 50) {
            d = d > 0 ? 50 : -50;
        }
        M2C_FIELD(e, s16 *, 0x96) = d + ((rsin_8013D810(M2C_FIELD(e, s16 *, 0xAA)) * 30) >> 12);
        Object_ApplyVelocity(e);
        if (Object_DetachLink_8013D810(e, 0) != 6) {
            M2C_FIELD(e, s32 *, 0xB4) = Object_AddAttackSphereNear_8013D810(e, 0x32, M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, s16 *, 0x28), M2C_FIELD(e, s16 *, 0x2C), M2C_FIELD(e, s16 *, 0x48), M2C_FIELD(e, s16 *, 0x4A));
            if (M2C_FIELD(e, u16 *, 0x5C) == M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2]) {
                if (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) {
                    Object_PlaySound_8013D810(e, 0x70);
                } else {
                    Object_PlaySound_8013D810(e, 0x71);
                }
            }
            if (func_8005588C_8013D810(e, -1) != 0) {
                break;
            }
        }
        e[0x80] = 3;
        break;
    case 3:
        d = (M2C_FIELD(e, s16 *, 0x9C) - M2C_FIELD(e, s32 *, 0x28)) >> 2;
        if (Math_WithinSquare(M2C_FIELD(e, s16 *, 0x9A) - M2C_FIELD(e, s32 *, 0x24), M2C_FIELD(e, s16 *, 0x9E) - M2C_FIELD(e, s32 *, 0x2C), 0x32) && (d < 0 ? -d : d) < 20) {
            e[0x80] = 1;
            e[0x7F] = 1;
            M2C_FIELD(e, s16 *, 0x96) = 0;
            M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 0x32;
            M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
            break;
        }
        func_80055AA0(e, M2C_FIELD(e, s16 *, 0x9A), M2C_FIELD(e, s16 *, 0x9E), 0x12);
        M2C_FIELD(e, s16 *, 0xAA) = (M2C_FIELD(e, s16 *, 0xAA) + 0xAA) % 0x1000;
        if ((d < 0 ? -d : d) > 20) {
            d = d > 0 ? 20 : -20;
        }
        M2C_FIELD(e, s16 *, 0x96) = d + ((rsin_8013D810(M2C_FIELD(e, s16 *, 0xAA)) * 30) >> 12);
        Object_ApplyVelocity(e);
        break;
    }
}

extern struct { u8 pad_0[0x8126]; u16 f_8126; } g_Game_8013DC1C asm("g_Game");
s32 func_8005BB5C(s32);
void func_80051E98(void *, s32);
void Object_TurnTowardSpike(void *);

void func_8013DC1C(u8 *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 100;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(arg0, s16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0xE0) |= 8;
    }
    if (SaveByte_Get(5) >= 5 || (func_8005BB5C(6) >= 5 && g_Game_8013DC1C.f_8126 == 0x4C)) {
        func_80051E98(arg0, 0);
    } else {
        Object_TurnTowardSpike(arg0);
    }
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 28; } Flags_8013DCE4;
void Object_PlaceAtPathPoint(void *, s32);
void Object_SetAnim(void *, u8, u8);
void func_8005866C(void *, s32);
void *func_80056BC4_8013DCE4(s16, void *, s16) asm("func_80056BC4");

void func_8013DCE4(u8 *e) {
    s32 v[3];

    if (!M2C_FIELD(e, Flags_8013DCE4 *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0x48) = 0;
        M2C_FIELD(e, s16 *, 0x4A) = 0xC101;
        M2C_FIELD(e, s16 *, 0xA0) = 0;
        if (M2C_FIELD(e, u16 *, 0x8C) != 0) {
            Object_PlaceAtPathPoint(e, 0);
            func_8005866C(e, 1);
        }
        e[0x7F] = 2;
        M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
        M2C_FIELD(e, Flags_8013DCE4 *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    switch (e[0xCF]) {
    case 1:
        if (e[0x80] == 1) {
            v[0] = M2C_FIELD(e, s32 *, 0x24) + ((M2C_FIELD(e, s16 *, 0x60) * 25) >> 9);
            v[1] = M2C_FIELD(e, s32 *, 0x28) - 400;
            v[2] = M2C_FIELD(e, s32 *, 0x2C) + ((M2C_FIELD(e, s16 *, 0x64) * 25) >> 9);
            func_80056BC4_8013DCE4(0x6F, v, M2C_FIELD(e, s8 *, 0xCB));
        }
        Object_SetAnim(e, 2, 4);
        Object_PlaySound(e, 0x77);
        break;
    case 3:
        if (e[0x80] != 1) {
            Object_SetAnim(e, 2, 3);
        }
        break;
    }
    e[0xCF] = 0;
    if (e[0x80] == 2 && M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
        switch (e[0x7F]) {
        case 1:
        case 3:
            e[0x80] = 1;
            e[0x7F] = 2;
            M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
            break;
        case 4:
            e[0x7F] = 1;
            M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
            break;
        }
    }
}

void func_8013DEEC(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    if (var_s0 > 0) {
        do {
            Object_SpawnEffect(arg0, 0x2B, 0, 0, 0);
            var_s0 -= 1;
        } while (var_s0 > 0);
    }
}

void func_8013DF40(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, 0x1000);
    func_800573A0(arg0, 0, 0, 0);
    Sound_PlayFixed(0x5F);
    Sound_PlayFixed(0x15);
    Object_PlaySound(arg0, 0xB6);
}

s32 func_8013DFEC(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        func_8013DF40(arg0);
        return 1;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        func_8013DF40(arg0);
        M2C_FIELD(arg0, u8 *, 0xDC) = 0x63;
        return 1;
    }
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E05C asm("g_Spike");
s32 rcos_8013E05C(s32) asm("rcos");
s32 rsin_8013E05C(s32) asm("rsin");
s32 Math_Atan2(s32, s32);
M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK func_80055AA0(void *, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);
void Object_StepOrbitAngle(void *, s32);

void func_8013E05C(u8 *arg0) {
    s32 ang;
    s32 bob;
    s32 r;
    s32 h;

    ang = Math_Atan2(M2C_FIELD(arg0, s32 *, 0x24) - g_Spike_8013E05C.x, M2C_FIELD(arg0, s32 *, 0x2C) - g_Spike_8013E05C.z);
    bob = rsin_8013E05C(M2C_FIELD(arg0, s16 *, 0xAA)) / 32;
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 40, 20, 0);
    }
    ang = (ang + 0x200) % 0x1000;
    r = bob + 300;
    func_80055AA0(arg0, (u16)g_Spike_8013E05C.x + ((rcos_8013E05C(ang) * r) >> 12), (u16)g_Spike_8013E05C.z + ((rsin_8013E05C(ang) * r) >> 12), M2C_FIELD(arg0, s16 *, 0xA8) >> 3);
    Object_StepOrbitAngle(arg0, 16);
    h = M2C_FIELD(arg0, s32 *, 0x28) + 0xB4;
    M2C_FIELD(arg0, s16 *, 0x96) = (g_Spike_8013E05C.y - h - bob) >> 3;
    Object_ApplyVelocity(arg0);
}

void func_8013E1B4(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0xE0) & 1) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) == 0)) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    }
}

void Object_DisableCollision(void *);
void Object_EnableCollision(void *);
void func_8013DEEC(s32 arg0, s32 arg1);
s32 func_8013DFEC(void *arg0);
void func_8013E05C(u8 *arg0);
void func_8013E1B4(void *arg0);
s32 func_8005588C(void *, s32);
void Object_DropPickups(void *);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013E214(e)
    u8 *e;
{
    if (((M2C_FIELD(e, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x2D;
        M2C_FIELD(e, s16 *, 0x44) = 0x78;
        M2C_FIELD(e, s16 *, 0x46) = 0x96;
        e[0xC8] = 0;
        e[0xC9] = 0;
        e[0xDC] = 1;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(e, u32 *, 0xE0) &= ~1;
        Object_DisableCollision(e);
        e[0x7F] = 2;
        e[0x80] = 1;
        M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
        M2C_FIELD(e, u32 *, 0xE0) |= 8;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    func_8013E1B4(e);
    switch (e[0x80]) {
    case 1:
        Object_TurnTowardSpike(e);
        if (!(M2C_FIELD(e, u32 *, 0xE0) & 1)) {
            if (Object_SpikeOutOfRange(e, M2C_FIELD(e, s16 *, 0x9A), M2C_FIELD(e, s32 *, 0x28), M2C_FIELD(e, s16 *, 0x9E), M2C_FIELD(e, s16 *, 0xA4)) == 0) {
                e[0x80] = 2;
                func_8005588C(e, 0x28);
                M2C_FIELD(e, u32 *, 0xE0) |= 1;
            }
        }
        break;
    case 2:
        Object_TurnTowardSpike(e);
        func_8013DEEC((s32)e, 1);
        if (e[0xC9] != 0) {
            if (--e[0xC9] == 1) {
                e[0x80] = 3;
                func_8005588C(e, 8);
            }
        }
        break;
    case 3:
        Object_TurnTowardSpike(e);
        func_8013DEEC((s32)e, 2);
        e[0xC8] = (8 - e[0xC9]) / 2;
        if (func_8005588C(e, -1) == 0) {
            e[0x80] = 4;
            e[0xC8] = 4;
            Object_EnableCollision(e);
            M2C_FIELD(e, s16 *, 0xA8) = 0;
            M2C_FIELD(e, s16 *, 0xAA) = 0;
            M2C_FIELD(e, u32 *, 0xE0) |= 0x10000;
            Object_PlaySound(e, 0xB5);
            func_8005588C(e, 0xF0);
        }
        break;
    case 4:
        func_8013E05C(e);
        func_8013DEEC((s32)e, 2);
        if (func_8013DFEC(e) == 0) {
            M2C_FIELD(e, s32 *, 0xB4) = Object_AddAttackSphereNear(e, 0xAA, M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, s16 *, 0x28), M2C_FIELD(e, s16 *, 0x2C), 1, 0x201);
            if (func_8005588C(e, -1) == 0) {
                e[0x80] = 1;
                func_8005588C(e, 0x28);
                e[0xC8] = 0;
                M2C_FIELD(e, s32 *, 0x24) = M2C_FIELD(e, s16 *, 0x9A);
                M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C);
                M2C_FIELD(e, s32 *, 0x2C) = M2C_FIELD(e, s16 *, 0x9E);
                Object_DisableCollision(e);
            }
        }
        break;
    case 5:
        break;
    case 6:
        func_8013DEEC((s32)e, 2);
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            func_80051E98(e, 1);
            Object_DropPickups(e);
        }
        break;
    }
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 8; u32 b12 : 1; u32 b13 : 3; u32 b16 : 1; u32 b17 : 15; } Flags_8013E52C;
typedef struct { u8 pad_0[0x60]; SVECTOR dir; u8 pad_68[0x44]; u16 f_AC; u8 pad_AE[0x36]; } Obj_8013E52C;
extern Obj_8013E52C g_Objects_8013E52C[] asm("g_Objects");
s32 func_8005588C(void *, s32);
void Object_DropPickups(void *);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
void func_8013DEEC(s32 arg0, s32 arg1);
s32 func_8013DFEC(void *arg0);
void func_8013E05C(u8 *arg0);

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013E52C(e)
    u8 *e;
{
    if (!M2C_FIELD(e, Flags_8013E52C *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x2D;
        M2C_FIELD(e, s16 *, 0x44) = 0x78;
        M2C_FIELD(e, s16 *, 0x46) = 0x96;
        e[0xC9] = 0;
        e[0xDC] = 1;
        *(volatile u8 *)(e + 0xC8) = 0;
        e[0xC8] = 4;
        M2C_FIELD(e, Flags_8013E52C *, 0xE0).b12 = 0;
        M2C_FIELD(e, s16 *, 0xA8) = 0;
        M2C_FIELD(e, s16 *, 0xAA) = 0;
        M2C_FIELD(e, Flags_8013E52C *, 0xE0).b16 = 1;
        M2C_FIELD(e, SVECTOR *, 0x60) = g_Objects_8013E52C[M2C_FIELD(e, s8 *, 0xCA)].dir;
        M2C_FIELD(e, u16 *, 0xAC) = g_Objects_8013E52C[M2C_FIELD(e, s8 *, 0xCA)].f_AC;
        Object_PlaySound(e, 0xB5);
        func_8005588C(e, 0x14);
        e[0x7F] = 2;
        e[0x80] = 1;
        M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
        M2C_FIELD(e, Flags_8013E52C *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    switch (e[0x80]) {
    case 1:
        func_8013DEEC((s32)e, 2);
        if (func_8005588C(e, -1) == 0) {
            e[0x80] = 4;
            func_8005588C(e, 0xF0);
        }
        break;
    case 4:
        func_8013E05C(e);
        func_8013DEEC((s32)e, 2);
        if (func_8013DFEC(e) == 0) {
            M2C_FIELD(e, s32 *, 0xB4) = Object_AddAttackSphereNear(e, 0xAA, M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, s16 *, 0x28), M2C_FIELD(e, s16 *, 0x2C), 1, 0x201);
            if (func_8005588C(e, -1) == 0) {
                func_80051E98(e, 0);
            }
        }
        break;
    case 6:
        func_8013DEEC((s32)e, 2);
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            func_80051E98(e, 1);
            Object_DropPickups(e);
        }
        break;
    }
}

void func_8013E7A4(void) {
    if (g_Game.f_8126 == 0x4C) {
        func_8013E52C();
        return;
    }
    func_8013E214();
}

s16 Object_FloorAt(void *, s32, s32, s32);
extern s32 D_800EC208;

s32 func_8013E7F4(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

void func_8013E86C(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

void func_8013E948(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
u32 Object_DetachLink(void *, s32);

void func_8013E9C8(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

void Object_PlaySound_8013D714(void *, s32) asm("Object_PlaySound");
s32 func_800563E0(void *, s32);
void func_80058134_8013D714(void *, s32) asm("func_80058134");
void func_8013E86C(void *arg0);
void func_8013E948(void *arg0);
void func_8013E9C8(void *arg0);

void func_8013EA6C(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(arg0, s16 *, 0x48) = 1;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x58;
        M2C_FIELD(arg0, s16 *, 0x46) = 0x114;
        M2C_FIELD(arg0, u8 *, 0xCD) = 4;
        M2C_FIELD(arg0, u8 *, 0xDC) = 0;
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013D714(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    switch (M2C_FIELD(arg0, u8 *, 0x80)) {
    case 1:
        if (func_8013E7F4(arg0) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = 1;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[2];
            M2C_FIELD(arg0, s16 *, 0x96) = 4;
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 1, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C), M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 2:
        if ((s16)func_800563E0(arg0, 0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
            Object_PlaySound_8013D714(arg0, 0xA2);
        }
        M2C_FIELD(arg0, s16 *, 0x96) += 6;
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 1 && M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    case 3:
        func_8013E9C8(arg0);
        func_8013E86C(arg0);
        func_8013E948(arg0);
        break;
    case 4:
        if (M2C_FIELD(arg0, u16 *, 0x5C) >= M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    }
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013ECA8(void *arg0, s32 n) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - n * 11 - 0xC8;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(0x2D, &v);
}

void *Object_AddAttackSphere(void *, s16, s16, s16, s16, s16, s16);

void func_8013ED00(u8 *a, void *b) {
    s32 f = M2C_FIELD(a, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(a, u8 **, 0x88) + a[0x7F] * 4);

    if (f == 0x2A) {
        Object_PlaySound(a, 0x1A);
    }
    if (!(M2C_FIELD(a, u32 *, 0xE0) & 1) && f >= 0x30 && f < 0x36) {
        if (Object_DetachLink(a, 0) == 6) {
            M2C_FIELD(a, u32 *, 0xE0) |= 1;
        } else {
            M2C_FIELD(a, void **, 0xB4) = Object_AddAttackSphere(b, 0x12C,
                M2C_FIELD(a, s16 *, 0x24) + ((M2C_FIELD(a, s16 *, 0x60) * 25) >> 9),
                M2C_FIELD(a, s16 *, 0x28) - 0xC8,
                M2C_FIELD(a, s16 *, 0x2C) + ((M2C_FIELD(a, s16 *, 0x64) * 25) >> 9),
                1, 0x203);
        }
    }
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013EE30 asm("g_Spike");

void func_8013EE30(u8 *arg0, u8 *arg1) {
    s32 dx = g_Spike_8013EE30.x - M2C_FIELD(arg0, s32 *, 0x24);
    s32 dz = g_Spike_8013EE30.z - M2C_FIELD(arg0, s32 *, 0x2C);
    s32 d = dx * dx + dz * dz;
    s32 near = 0x40000;

    if (d > 0x240000 || M2C_FIELD(arg1, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x80) != 6 && d < near) {
        M2C_FIELD(arg0, u8 *, 0x80) = 6;
        M2C_FIELD(arg0, u8 *, 0x7F) = 2;
        M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 8);
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~1;
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x10000;
    }
}

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK func_80055AA0(void *, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013EEF4(void *arg0, s32 arg1, s32 arg2)
{
  int new_var;
  if (((*((u16 *) (((s8 *) arg0) + 0xE2))) & 1) == arg1)
  {
    Object_StepGrowShrink(arg0, 0x32, 0xA, 0);
  }
  new_var = 0x24;
  if (arg2 != 0)
  {
    func_80055AA0(arg0, *((s16 *) (((s8 *) (&g_Spike)) + new_var)), *((s16 *) (((s8 *) (&g_Spike)) + 0x2C)), ((s32) ((*((u16 *) (((s8 *) arg0) + 0xA8))) << 0x10)) >> 0x13);
    *((s16 *) (((s8 *) arg0) + 0x96)) = (s16) (((s32) ((*((s32 *) (((s8 *) (&g_Spike)) + 0x28))) - (*((s32 *) (((s8 *) arg0) + 0x28))))) >> 2);
  }
  else
  {
    *((s16 *) (((s8 *) arg0) + 0x96)) = 0;
    *((s16 *) (((s8 *) arg0) + 0xAE)) = 0;
  }
  Object_ApplyVelocity(arg0);
}

void func_80052038(void *, s32);

void func_8013EF94(void *arg0) {
    u16 end = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88) + 2);

    if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 10) {
        func_80052038(arg0, 0xB1);
    } else if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 8) {
        func_80052038(arg0, 0x18);
    } else if (M2C_FIELD(arg0, u16 *, 0x5C) == end - 2) {
        func_80052038(arg0, 0xB3);
    }
}

typedef struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0xB0]; u32 f_E0; } Obj_8013EFF8;
extern Obj_8013EFF8 g_Objects_8013EFF8[] asm("g_Objects");
extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike_8013EFF8 asm("g_Spike");
void func_8013ECA8(void *arg0, s32 n);
void func_8013ED00(u8 *a, void *b);
void func_8013EE30(u8 *arg0, u8 *arg1);
void func_8013EF94(void *arg0);

void func_8013EFF8(u8 *e) {
    Obj_8013EFF8 *p = &g_Objects_8013EFF8[M2C_FIELD(e, s8 *, 0xCA)];
    u8 n;

    if (((M2C_FIELD(e, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x44;
        e[0x80] = 1;
        e[0x7F] = 0;
        M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
        func_80052038(e, 0xB2);
        M2C_FIELD(e, s32 *, 0x24) = p->x;
        M2C_FIELD(e, s32 *, 0x2C) = p->z;
        M2C_FIELD(e, s32 *, 0x28) = p->y - 0x96;
        e[0x8F] = 0;
        e[0xC8] = 0xA;
        Object_TurnToward(e, g_Spike_8013EFF8.f_24 - M2C_FIELD(e, u16 *, 0x24), g_Spike_8013EFF8.f_2C - M2C_FIELD(e, u16 *, 0x2C), 0, 0x1000);
        Object_PlaySound(e, 0xB6);
        M2C_FIELD(e, u32 *, 0xE0) |= 8;
    }
    switch (e[0x80]) {
    case 1:
        Object_TurnTowardSpike(e);
        e[0x8F] += 2;
        func_8013ECA8(e, (u8)(e[0x8F] - 1));
        func_8013EF94(e);
        if (M2C_FIELD(e, u16 *, 0x5C) >= *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88) + 2)) {
            e[0x80] = 4;
            e[0x7F] = 1;
            M2C_FIELD(e, u16 *, 0x5C) = *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88));
            M2C_FIELD(e, s16 *, 0xA8) = 0;
            M2C_FIELD(e, u32 *, 0xE0) |= 0x10000;
            func_8005588C(e, 0x14);
            func_80052038(e, 0xB0);
        }
        break;
    case 4:
        func_8013EEF4(e, 1, 1);
        func_8013EE30(e, (u8 *)p);
        break;
    case 6:
        if (M2C_FIELD(e, s16 *, 0xA8) != 0) {
            func_8013EEF4(e, 0, M2C_FIELD(e, u16 *, 0x5C) < *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88)) + 0x2A);
        } else {
            Object_TurnTowardSpike(e);
        }
        func_8013ED00(e, p);
        func_8013EE30(e, (u8 *)p);
        if (M2C_FIELD(e, u16 *, 0x5C) >= *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88) + 2)) {
            e[0x80] = 5;
            e[0x7F] = 1;
            M2C_FIELD(e, u16 *, 0x5C) = *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88));
        }
        break;
    case 5:
        e[0x8F] = (e[0x8F] + 1) % 4;
        switch (e[0x8F]) {
        case 0:
            e[0xC8] = 0xA;
            func_80052038(e, 0xB0);
            break;
        case 1:
            func_80052038(e, 0xB1);
            break;
        case 2:
            func_80052038(e, 0xB2);
            break;
        case 3:
            func_80051E98(e, 0);
            p->f_E0 |= 1;
            break;
        }
        break;
    }
}

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_418;
s32 Hook_Add(void *);
void func_8013F618(void);
void func_800520A8(void *, s32);
extern Mdl_418 D_80142C40_s[] asm("D_80142C40");

void func_8013F380(void) {
    s32 i;
    Mdl_418 *m;

    if (Hook_Add(func_8013F618) == 1) {
        for (i = 0; i < 16; i++) {
            m = &D_80142C40_s[i];
            func_80052038(m, 0xB5);
            func_800520A8(m, 0xB5);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f_82; u8 life; s16 scale; s16 floor; } Debris_8013F418;
extern Debris_8013F418 D_80142C40_8013F418[16] asm("D_80142C40");
extern u16 g_RandSeed;
#define RAND_8013F418() (g_RandSeed = g_RandSeed * 5 + 1)
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x9B]; u8 f_CB; } Obj_8013F418;

M2C_UNK func_8013F418(void *arg0) {
#define e_8013F418 ((Obj_8013F418 *)arg0)
    s32 i;
    Debris_8013F418 *d;

    for (i = 0; i < 16; i++) {
        d = &D_80142C40_8013F418[i];
        d->x = e_8013F418->x;
        d->y = e_8013F418->y;
        d->z = e_8013F418->z;
        d->vx = (((u16)RAND_8013F418() >> 8) - 0x80) / 8;
        d->vz = (((u16)RAND_8013F418() >> 8) - 0x80) / 8;
        d->vy = -((u16)RAND_8013F418() >> 8) / 5 - 0x20;
        d->wx = ((RAND_8013F418() << 4) & 0xF000) / 360;
        d->wy = ((RAND_8013F418() << 4) & 0xF000) / 360;
        d->wz = ((RAND_8013F418() << 4) & 0xF000) / 360;
        d->rx = d->ry = d->rz = 0;
        d->life = 30;
        d->f_82 = e_8013F418->f_CB;
        d->floor = *(u16 *)&e_8013F418->y - 0x32;
        d->scale = 0x1000 / (i % 4 + 1);
    }
}
#undef e_8013F418

typedef struct { s16 x, y, z; } Rot_404;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_404 r; u8 pad82; u8 life; s16 scale; s16 floor; } Debris_404;
extern Debris_404 D_80142C40[16];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F618 asm("g_Game");
extern u8 D_800E7D00_8013DB40[] asm("D_800E7D00");
s32 func_80051410(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void ScaleMatrix_8013DB40(void *, void *) asm("ScaleMatrix");
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80016EBC(void *, void *, void *);
void Model_ProjectBonedVerts(void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);

void func_8013F618(void) {
    s32 i;
    Debris_404 *d;
    s32 s[3];
    SVECTOR v;

    for (i = 0; i < 16; i++) {
        d = &D_80142C40[i];
        if (d->life != 0) {
            d->life--;
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            if (d->floor < d->y) {
                d->y = d->floor;
                d->vy = -(d->vy / 2);
                v.vx = d->x;
                v.vy = d->y;
                v.vz = d->z;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (func_80051410(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                s[0] = s[1] = s[2] = d->scale;
                ScaleMatrix_8013DB40(d->mat, s);
                func_80015780(d, 3);
                Model_ProjectBonedVerts(d);
                func_80016EBC(g_Game_8013F618.f_80 + g_Game_8013F618.f_C * 0x4078, D_800E7D00_8013DB40, d);
            }
        }
    }
}

void func_8013F818(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) != 0xD00)) {
        Object_PlaySound(arg0, 0x15);
        func_8013F418(arg0);
        Object_Destroy(arg0);
        Object_PlaySound(arg0, 0x69);
        M2C_FIELD(arg0, s8 *, 0x81) = 0;
    }
}

s32 rsin_8013F894(s32) asm("rsin");
typedef struct { u32 active : 1; u32 b1 : 2; u32 init : 1; u32 b4 : 8; u32 b12 : 1; u32 b13 : 19; } Flags_8013F894;
s32 Spike_WithinRadiusXZ_8013F894(s32, s32, s32) asm("Spike_WithinRadiusXZ");
void *func_80056BC4(s16, s32, s16);
void func_8013F380(void);
void func_8013F818(void *arg0);

void func_8013F894(u8 *e) {
    s32 t;

    if (!M2C_FIELD(e, Flags_8013F894 *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x5B;
        e[0xC8] = 5;
        M2C_FIELD(e, s16 *, 0x44) = 0x50;
        M2C_FIELD(e, s16 *, 0x46) = 0xE6;
        e[0x81] = 6;
        e[0x7D] = 9;
        e[0xDC] = 1;
        M2C_FIELD(e, Flags_8013F894 *, 0xE0).active = 0;
        t = M2C_FIELD(e, s16 *, 0xAC) + 0x800;
        M2C_FIELD(e, Flags_8013F894 *, 0xE0).b12 = 0;
        M2C_FIELD(e, s16 *, 0xAC) = t % 0x1000;
        M2C_FIELD(e, s16 *, 0x60) = rcos(M2C_FIELD(e, s16 *, 0xAC));
        M2C_FIELD(e, s16 *, 0x64) = rsin_8013F894(M2C_FIELD(e, s16 *, 0xAC));
        func_8013F380();
        e[0x7F] = 0;
        M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
        M2C_FIELD(e, Flags_8013F894 *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    switch (e[0x80]) {
    case 1:
        if (Spike_WithinRadiusXZ_8013F894(M2C_FIELD(e, s32 *, 0x24), M2C_FIELD(e, s32 *, 0x2C), 0x600)) {
            e[0x80] = 2;
            e[0x7F] = 1;
            M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
        }
        break;
    case 2:
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            e[0x80] = 3;
            e[0x7F] = 0;
            M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
            func_80056BC4(0x18, 0, M2C_FIELD(e, s8 *, 0xCB));
            M2C_FIELD(e, Flags_8013F894 *, 0xE0).active = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(e, Flags_8013F894 *, 0xE0).active) {
            e[0x80] = 1;
        }
        break;
    }
    func_8013F818(e);
}

s32 func_8013FA8C(s32 *arg0, void **arg1) {
    s16 temp_a0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (func_800889A4() * 0x38);
    if (M2C_FIELD(temp_a1, u8 *, 0x12) == 0xD) {
        temp_a0 = M2C_FIELD(temp_a1, s16 *, 0x22);
        if (temp_a0 >= 0) {
            *arg0 = g_Game.f_8214 + (temp_a0 * 0x10);
            *arg1 = temp_a1 + 0x32;
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_8013FB20;
extern Snd_8013FB20 D_801434C0_8013FB20 asm("D_801434C0");
extern Snd_8013FB20 D_801434C4_8013FB20 asm("D_801434C4");
extern Snd_8013FB20 D_801434C8_8013FB20 asm("D_801434C8");
s32 func_80087BA4(s32, s16, s16, s16);

s32 func_8013FB20(s32 arg0) {
    if (arg0 == 0) {
        if (D_801434C0_8013FB20.id >= 0) {
            func_80087BA4(0xAD, D_801434C0_8013FB20.id, 0, 0x3C);
        }
        if (D_801434C4_8013FB20.id >= 0) {
            func_80087BA4(0xAE, D_801434C4_8013FB20.id, 0, 0x3C);
        }
        if (D_801434C8_8013FB20.id >= 0) {
            func_80087BA4(0xAC, D_801434C8_8013FB20.id, 0, 0x3C);
        }
    } else {
        if (D_801434C0_8013FB20.id >= 0) {
            func_80087BA4(0xAD, D_801434C0_8013FB20.id, 1, 1);
        }
        if (D_801434C4_8013FB20.id >= 0) {
            func_80087BA4(0xAE, D_801434C4_8013FB20.id, 1, 1);
        }
        if (D_801434C8_8013FB20.id >= 0) {
            func_80087BA4(0xAC, D_801434C8_8013FB20.id, 1, 1);
        }
    }
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_8013FC00;
extern Snd_8013FC00 D_801434C0_8013FC00 asm("D_801434C0");
extern Snd_8013FC00 D_801434C4_8013FC00 asm("D_801434C4");
extern Snd_8013FC00 D_801434C8_8013FC00 asm("D_801434C8");
extern s16 D_801434CC;
extern s16 D_801434CE;
extern s16 D_801434D0;
extern s16 D_801434D2;
typedef struct { u8 pad_0[0xC]; u16 f_C; u8 pad_E[0x24]; s16 f_32; s16 f_34; s16 f_36; } Ent_8013FC00;
extern struct { s16 a; s16 b; } D_800B4DB0_8013FC00 asm("D_800B4DB0");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; s32 f_20[3]; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; } D_800E7880_8013FC00 asm("D_800E7880");
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; u8 f_812C; u8 pad_812D[0x23]; s16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; } g_Game_8013FC00 asm("g_Game");
s32 Sound_PlayTracked(s32, s32);
s32 func_80088280(s16);
s32 func_801409E8(u8 *arg0, s32 *out);

s32 func_8013FC00(s32 idx) {
    u16 st;

    if (g_Game_8013FC00.f_812C == 1) {
        D_801434C0_8013FC00.id = -1;
        D_801434C0_8013FC00.on = 0;
        D_801434C4_8013FC00.id = -1;
        D_801434C4_8013FC00.on = 0;
        D_800B4DB0_8013FC00.a = 0x1000;
        D_800B4DB0_8013FC00.b = 0x1000;
        D_800E7880_8013FC00.f_34 = 0;
        D_800E7880_8013FC00.f_38 = 0;
    } else {
        D_801434C0_8013FC00.id = func_80088280(0x50AD);
        if (D_801434C0_8013FC00.id >= 0) {
            D_801434C0_8013FC00.on = 1;
        } else {
            D_801434C0_8013FC00.on = 0;
        }
        D_801434C4_8013FC00.id = func_80088280(0x50AE);
        if (D_801434C4_8013FC00.id >= 0) {
            D_801434C4_8013FC00.on = 1;
        } else {
            D_801434C4_8013FC00.on = 0;
        }
    }
    D_801434C8_8013FC00.id = -1;
    D_801434C8_8013FC00.on = 0;
    st = g_Game_8013FC00.f_8126;
    if (st == 0x49 || st == 0x4A || (st == 0x4B && g_Game_8013FC00.f_812A == 0)) {
        g_Game_8013FC00.f_8150 = 2;
        if (D_801434C0_8013FC00.id < 0) {
            D_801434C0_8013FC00.id = Sound_PlayTracked(0, 0x50AD);
            D_801434C0_8013FC00.on = 1;
        }
        if (D_801434C4_8013FC00.id < 0) {
            D_801434C4_8013FC00.id = Sound_PlayTracked(0, 0x50AE);
            D_801434C4_8013FC00.on = 1;
        }
    }
    D_801434CC = 0;
    ((Ent_8013FC00 *)(g_Game_8013FC00.f_820C + idx * 0x38))->f_32 = ((Ent_8013FC00 *)(g_Game_8013FC00.f_820C + idx * 0x38))->f_C;
    D_801434CE = 0;
    ((Ent_8013FC00 *)(g_Game_8013FC00.f_820C + idx * 0x38))->f_34 = 0;
    D_801434D0 = 0;
    ((Ent_8013FC00 *)(g_Game_8013FC00.f_820C + idx * 0x38))->f_36 = 0;
    D_801434D2 = 0;
    D_800E7880_8013FC00.f_0 = 0;
    D_800E7880_8013FC00.f_8 = 0;
    D_800E7880_8013FC00.f_4 = 0;
    D_800E7880_8013FC00.f_C = 0;
    D_800E7880_8013FC00.f_14 = 0;
    D_800E7880_8013FC00.f_10 = 0;
    D_800E7880_8013FC00.f_18 = 0;
    D_800E7880_8013FC00.f_2C = 0;
    D_800E7880_8013FC00.f_30 = 0xFFFF;
    D_800E7880_8013FC00.f_1C = -1;
    func_801409E8(g_Game_8013FC00.f_820C + idx * 0x38, D_800E7880_8013FC00.f_20);
    return 0;
}

int abs(int);
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013FE4C;
extern struct { u8 pad_0[0x8214]; s16 *f_8214; } g_Game_8013FE4C asm("g_Game");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; } D_800E7880_8013FE4C asm("D_800E7880");
extern s32 D_800E7898;
extern u8 *D_800B4D64_8013FE4C asm("D_800B4D64");
extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013FE4C asm("g_Spike");
void RotMatrixZYX_8013FE4C(SVECTOR *, Mat_8013FE4C *) asm("RotMatrixZYX");
void MulMatrix2_8013FE4C(Mat_8013FE4C *, Mat_8013FE4C *) asm("MulMatrix2");
void MulMatrix_8013FE4C(Mat_8013FE4C *, Mat_8013FE4C *) asm("MulMatrix");
void func_80066DAC(void *, s32, s32, s32);
s16 func_800889EC(void *);
s32 func_80140430(u8 *e);
s32 func_801408CC(u8 *e);

s32 func_8013FE4C(u8 *e) {
    SVECTOR r;
    Mat_8013FE4C m2;
    Mat_8013FE4C m3;
    Mat_8013FE4C *m;
    s16 *pt;
    s16 x;
    s16 y;
    s16 z;
    s32 k;
    s32 t;

    if (M2C_FIELD(e, s16 *, 0x22) < 0) {
        return 0;
    }
    pt = g_Game_8013FE4C.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 8;
    x = pt[0] + D_800E7880_8013FE4C.f_0;
    y = pt[1] + D_800E7880_8013FE4C.f_8;
    z = pt[2] + D_800E7880_8013FE4C.f_4;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_8013FE4C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x10) = x;
        M2C_FIELD(D_800B4D64_8013FE4C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x12) = y;
        M2C_FIELD(D_800B4D64_8013FE4C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x14) = z;
        if ((*M2C_FIELD(D_800B4D64_8013FE4C + M2C_FIELD(e, s16 *, 0xE) * 32, u32 **, 0) & 0xF) == 3) {
            if (M2C_FIELD(e, s16 *, 0x36) != 4) {
                g_Spike_8013FE4C.x = x;
                g_Spike_8013FE4C.y = y;
                g_Spike_8013FE4C.z = z;
            }
            r.vx = (-pt[3] / 100 * 4096) / 360;
            r.vy = (-pt[4] / 100 * 4096) / 360;
            r.vz = (-pt[5] / 100 * 4096) / 360;
            m = M2C_FIELD(D_800B4D64_8013FE4C + M2C_FIELD(e, s16 *, 0xE) * 32, Mat_8013FE4C **, 0x1C);
            RotMatrixZYX_8013FE4C(&r, m);
            r.vx = 0;
            r.vy = 0;
            r.vz = 0;
            if (D_801434CC == 0) {
                if (D_800E7880_8013FE4C.f_14 != 0) {
                    r.vz = (D_800E7880_8013FE4C.f_14 * 30 / 128 * 4096) / 360;
                }
                if (D_800E7880_8013FE4C.f_18 != 0) {
                    r.vx = D_800E7880_8013FE4C.f_18;
                }
            } else {
                r.vz = (D_801434D0 * 4096) / 360;
                r.vx = (D_801434CE * 4096) / 360;
                D_801434D0 += 30;
                D_801434CE += 10;
            }
            RotMatrixZYX_8013FE4C(&r, &m2);
            MulMatrix2_8013FE4C(m, &m2);
            k = D_800E7898;
            m3.m[2][2] = 0x1000;
            m3.m[0][0] = 0x1000;
            m3.m[0][1] = 0;
            m3.m[2][0] = 0;
            m3.m[0][2] = 0;
            m3.m[1][0] = 0;
            m3.m[1][2] = 0;
            m3.m[2][1] = k * 6;
            m3.m[1][1] = 0x1000 - abs(k * 2);
            MulMatrix_8013FE4C(&m2, &m3);
            *m = m2;
            if (M2C_FIELD(e, s16 *, 0x36) != 4) {
                func_80066DAC(m, 0, -M2C_FIELD(e, s16 *, 0x8), 0);
            }
        }
    }
    M2C_FIELD(e, s16 *, 0x0) = x;
    M2C_FIELD(e, s16 *, 0x2) = y;
    M2C_FIELD(e, s16 *, 0x4) = z;
    M2C_FIELD(e, s16 *, 0x20) = func_800889EC(e);
    switch (M2C_FIELD(e, s16 *, 0x36)) {
    case 0:
    case 4:
        func_80140430(e);
        return 0;
    case 1:
        func_801408CC(e);
        return 0;
    case 2:
        func_80140988(e);
    case 3:
        break;
    }
    return 0;
}

s32 func_801402D8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x36) = 3;
    M2C_FIELD(arg0, u16 *, 0x18) = (u16) ((M2C_FIELD(arg0, u16 *, 0x18) & 0xFFF0) | 1);
    return 0;
}

s32 func_801402F8(void) {
    func_800880D0(0x50AD, M2C_FIELD(&D_801434C0, s16 *, 0));
    M2C_FIELD(&D_801434C0, s16 *, 2) = 0;
    func_800880D0(0x50AE, M2C_FIELD(&D_801434C4, s16 *, 0));
    M2C_FIELD(&D_801434C4, s16 *, 2) = 0;
    D_800E7880.f_0 = 0;
    D_800E7880.f_8 = 0;
    D_800E7880.f_4 = 0;
    D_800E7880.f_C = 0;
    D_800E7880.f_14 = 0;
    D_800E7880.f_10 = 0;
    D_800E7880.f_18 = 0;
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_80140374;
extern Snd_80140374 D_801434C0_80140374 asm("D_801434C0");
extern Snd_80140374 D_801434C4_80140374 asm("D_801434C4");
extern struct { s16 a; s16 b; } D_800B4DB0_80140374 asm("D_800B4DB0");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; u8 pad_1C[0x18]; s32 f_34; } D_800E7880_80140374 asm("D_800E7880");
s32 Sound_PlayTracked(s32, s32);

s32 func_80140374(u8 *e) {
    M2C_FIELD(e, s16 *, 0x36) = 4;
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    D_801434C0_80140374.id = Sound_PlayTracked(0, 0x50AD);
    D_801434C0_80140374.on = 1;
    D_801434C4_80140374.id = Sound_PlayTracked(0, 0x50AE);
    D_801434C4_80140374.on = 1;
    D_800E7880_80140374.f_0 = 0;
    D_800E7880_80140374.f_8 = 0;
    D_800E7880_80140374.f_4 = 0;
    D_800E7880_80140374.f_C = 0;
    D_800E7880_80140374.f_14 = 0;
    D_800E7880_80140374.f_10 = 0;
    D_800E7880_80140374.f_18 = 0;
    D_800E7880_80140374.f_34 = 0;
    D_800B4DB0_80140374.a = 0x1000;
    D_800B4DB0_80140374.b = 0x1000;
    return D_801434C0_80140374.id;
}

typedef struct { s16 id; s16 on; } Snd_80140430;
typedef struct { u8 pad_0[0x22]; s16 f_22; u8 pad_24[0xE]; s16 f_32; s16 f_34; s16 f_36; } Ent_80140430;
typedef struct { s16 x; s16 y; s16 z; s16 pad6[3]; s16 f_C; s16 next; } Node_80140430;
extern Snd_80140430 D_801434C0_80140430 asm("D_801434C0");
extern Snd_80140430 D_801434C4_80140430 asm("D_801434C4");
extern s16 D_80142C3C;
extern s16 D_80142C3E;
extern s32 D_800E7888;
extern s32 D_800EC214;
extern struct { s16 a; s16 b; } D_800B4DB0_80140430 asm("D_800B4DB0");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; s32 f_20; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; } D_800E7880_80140430 asm("D_800E7880");
extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xC2]; Node_80140430 *f_8214; } g_Game_80140430 asm("g_Game");
s32 SquareRoot0(s32);
void func_80087C28(s32, s16, s32);
void func_800880D0_80140430(s32, s32) asm("func_800880D0");
void Camera_StartShake(s32);
void Sound_PlayFixed_80140430(s32) asm("Sound_PlayFixed");
void Pad_Vibrate(s32, s32, s32);

s32 func_80140430(u8 *e) {
    Node_80140430 *cur;
    Node_80140430 *nxt;
    s16 idx;
    s16 dy;
    s32 d;

    if (D_80142C3E == 0) {
        D_80142C3C = 0x6E;
        D_80142C3E = 2;
    } else {
        D_80142C3C = 0;
        D_80142C3E--;
    }
    idx = ((Ent_80140430 *)e)->f_22;
    cur = &g_Game_80140430.f_8214[idx];
    ((Ent_80140430 *)e)->f_22 = cur->next;
    nxt = &g_Game_80140430.f_8214[((Ent_80140430 *)e)->f_22];
    ((Ent_80140430 *)e)->f_32++;
    if (D_800E7880_80140430.f_1C == -1) {
        if (nxt->f_C <= 0) {
            ((Ent_80140430 *)e)->f_32 = 0;
        } else if (((Ent_80140430 *)e)->f_32 >= D_800E7880_80140430.f_20 && ((Ent_80140430 *)e)->f_32 <= D_800E7880_80140430.f_20 + 15 && D_800E7880_80140430.f_20 >= 0 && D_800E7880_80140430.f_8 != 0) {
            D_80142C3C = 0xF0;
            D_80142C3E = 5;
            ((Ent_80140430 *)e)->f_22 = D_800E7880_80140430.f_28;
            D_800E7880_80140430.f_1C = 0;
        }
    } else if (nxt->f_C <= 0) {
        D_80142C3C = 0xF0;
        ((Ent_80140430 *)e)->f_22 = D_800E7880_80140430.f_24;
        D_800E7880_80140430.f_1C = -1;
        D_80142C3E = 5;
        dy = g_Game_80140430.f_8214[((Ent_80140430 *)e)->f_22].y - g_Game_80140430.f_8214[idx].y;
        if (dy > 0) {
            D_800E7880_80140430.f_8 -= dy;
        }
    }
    if (D_801434C0_80140430.on != 0 && D_800E7880_80140430.f_8 == 0) {
        d = SquareRoot0((cur->x - nxt->x) * (cur->x - nxt->x) + (cur->y - nxt->y) * (cur->y - nxt->y) + (cur->z - nxt->z) * (cur->z - nxt->z));
        D_800E7880_80140430.f_38 = d;
        D_800B4DB0_80140430.b = D_800B4DB0_80140430.a + (d - D_800E7880_80140430.f_34) * 12;
        if (D_800B4DB0_80140430.b >= 0x2000) {
            D_800B4DB0_80140430.b = 0x1FFF;
        }
        if (D_800B4DB0_80140430.b < 0) {
            D_800B4DB0_80140430.b = 0;
        }
        if (D_800B4DB0_80140430.a != D_800B4DB0_80140430.b) {
            func_80087C28(0xAD, D_801434C0_80140430.id, D_800B4DB0_80140430.b);
        }
        D_800E7880_80140430.f_34 = D_800E7880_80140430.f_38;
        D_800B4DB0_80140430.a = D_800B4DB0_80140430.b;
    }
    if (D_800E7880_80140430.f_8 < 0) {
        D_80142C3C = 0;
        D_800E7880_80140430.f_14 += 0x10;
        D_800E7880_80140430.f_8 += D_800E7880_80140430.f_14;
        if (D_800E7880_80140430.f_8 >= 0) {
            D_800E7880_80140430.f_8 = 0;
            D_800E7880_80140430.f_14 = 0;
            if (D_801434C0_80140430.on == 0) {
                D_801434C0_80140430.id = Sound_PlayTracked(0, 0x50AD);
                func_80087C28(0xAD, D_801434C0_80140430.id, D_800B4DB0_80140430.b);
                D_801434C0_80140430.on = 1;
                D_800B4DB0_80140430.a = 0x1000;
                D_800B4DB0_80140430.b = 0x1000;
                D_800E7880_80140430.f_34 = 0;
            }
            if (D_801434C4_80140430.on == 0) {
                D_801434C4_80140430.id = Sound_PlayTracked(0, 0x50AE);
                D_801434C4_80140430.on = 1;
            }
            Camera_StartShake(0);
            Sound_PlayFixed_80140430(0x19);
            D_80142C3C = 0xF0;
            D_80142C3E = 5;
        }
    } else if (D_800EC214 < 0 && D_801434D2 == 0 && ((Ent_80140430 *)e)->f_36 != 4) {
        D_800E7880_80140430.f_14 = -0x80;
        D_800E7880_80140430.f_8 = -0x80;
        if (D_801434C0_80140430.on != 0) {
            func_800880D0_80140430(0x50AD, D_801434C0_80140430.id);
            D_801434C0_80140430.on = 0;
        }
        if (D_801434C4_80140430.on != 0) {
            func_800880D0_80140430(0x50AE, D_801434C4_80140430.id);
            D_801434C4_80140430.on = 0;
        }
    } else {
        D_800E7888 = 0;
    }
    if (D_80142C3C > 0 && g_Game_80140430.f_8150 == 2) {
        Pad_Vibrate(1, D_80142C3C, D_80142C3E);
    }
    if (((Ent_80140430 *)e)->f_36 != 4) {
        D_800EC214 = 0;
    }
    return 0;
}

extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; } D_800E7880_801408CC asm("D_800E7880");
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; } g_Game_801408CC asm("g_Game");
void Pad_Vibrate(s32, s32, s32);
void Game_SetMode();

s32 func_801408CC(u8 *e) {
    Pad_Vibrate(0, 1, 2);
    D_800E7880_801408CC.f_14 += 0x10;
    D_800E7880_801408CC.f_8 += D_800E7880_801408CC.f_14;
    D_800E7880_801408CC.f_0 += D_800E7880_801408CC.f_C / 2;
    D_800E7880_801408CC.f_4 += D_800E7880_801408CC.f_10 / 2;
    if (D_800E7880_801408CC.f_8 > 0x800) {
        Game_SetMode(0xA, g_Game_801408CC.f_8126, g_Game_801408CC.f_812A);
        M2C_FIELD(e, s16 *, 0x36) = 2;
    }
    return 0;
}

s32 func_80140988(void) {
    s32 temp_v1;

    temp_v1 = D_800E7880.f_14 + 0x10;
    D_800E7880.f_8 = (s32) (D_800E7880.f_8 + temp_v1);
    D_800E7880.f_14 = temp_v1;
    D_800E7880.f_0 = (s32) (D_800E7880.f_0 + ((s32) D_800E7880.f_C / 2));
    D_800E7880.f_4 = (s32) (D_800E7880.f_4 + ((s32) (D_800E7880.f_10 + ((u32) D_800E7880.f_10 >> 0x1F)) >> 1));
    return 0;
}

typedef struct { s16 type; s16 sub; s16 v[5]; s16 next; } Node_801409E8;
extern struct { u8 pad_0[0x218]; Node_801409E8 *f_218; } D_800F4350_801409E8 asm("D_800F4350");

s32 func_801409E8(u8 *arg0, s32 *out) {
    Node_801409E8 *n;
    s16 i;

    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = 0xFFFF;
    i = M2C_FIELD(arg0, s16 *, 0x30);
    if (i < 0) {
        return 0;
    }
    do {
        n = &D_800F4350_801409E8.f_218[i];
        if (n->type == 7) {
            if (n->sub == 0x50) {
                out[0] = n->v[1];
                out[1] = n->v[2];
                out[2] = n->v[3];
            } else if (n->sub == 0x53) {
                out[3] = n->v[0];
            } else if (n->sub == 0x45) {
                out[4] = n->v[0];
            }
        }
        i = n->next;
    } while (i >= 0);
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_80140AC4;
extern Snd_80140AC4 D_801434C0_80140AC4 asm("D_801434C0");
extern Snd_80140AC4 D_801434C4_80140AC4 asm("D_801434C4");
extern u8 *D_800B4D64_80140AC4 asm("D_800B4D64");
extern struct { u8 pad_0[0x812A]; u16 f_812A; u8 pad_812C[0x24]; s16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; u8 pad_8210[4]; u8 *f_8214; } g_Game_80140AC4 asm("g_Game");

s32 func_80140AC4(s16 *p) {
    u8 *e = g_Game_80140AC4.f_820C + p[2] * 0x38;
    u8 *n;
    s32 i;
    SVECTOR r;
    u8 *tbl;

    p[3] = 0;
    if (g_Game_80140AC4.f_812A == 0) {
        D_801434C0_80140AC4.id = -1;
        D_801434C0_80140AC4.on = 0;
        D_801434C4_80140AC4.id = -1;
        D_801434C4_80140AC4.on = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        p[1] = 0;
        p[6] = M2C_FIELD(e, u16 *, 0x22);
        for (i = 0; i < p[5]; i++) {
            n = g_Game_80140AC4.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 16;
            M2C_FIELD(e, u16 *, 0x22) = M2C_FIELD(n, u16 *, 0xE);
        }
        tbl = D_800B4D64_80140AC4;
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x10) = M2C_FIELD(n, u16 *, 0);
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x12) = M2C_FIELD(n, u16 *, 2);
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x14) = M2C_FIELD(n, u16 *, 4);
        M2C_FIELD(e, u16 *, 0) = M2C_FIELD(n, u16 *, 0);
        M2C_FIELD(e, u16 *, 2) = M2C_FIELD(n, u16 *, 2);
        M2C_FIELD(e, u16 *, 4) = M2C_FIELD(n, u16 *, 4);
        r.vx = -(M2C_FIELD(n, s16 *, 6) << 12) / 36000;
        r.vy = -(M2C_FIELD(n, s16 *, 8) << 12) / 36000;
        r.vz = -(M2C_FIELD(n, s16 *, 0xA) << 12) / 36000;
        RotMatrixZYX(&r, M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
    } else {
        p[1] = 2;
        M2C_FIELD(e, u16 *, 0x22) = p[6];
        g_Game_80140AC4.f_8150 = 2;
        if (D_801434C0_80140AC4.id < 0) {
            D_801434C0_80140AC4.id = Sound_PlayTracked(0, 0x50AD);
            D_801434C0_80140AC4.on = 1;
        }
        if (D_801434C4_80140AC4.id < 0) {
            D_801434C4_80140AC4.id = Sound_PlayTracked(0, 0x50AE);
            D_801434C4_80140AC4.on = 1;
        }
    }
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_80140D18;
extern Snd_80140D18 D_801434C0_80140D18 asm("D_801434C0");
extern Snd_80140D18 D_801434C4_80140D18 asm("D_801434C4");
extern Snd_80140D18 D_801434C8_80140D18 asm("D_801434C8");
extern struct { s16 a; s16 b; } D_800B4DB0_80140D18 asm("D_800B4DB0");
extern struct { u8 pad_0[0x34]; s32 f_34; s32 f_38; } D_800E7880_80140D18 asm("D_800E7880");
extern struct { u8 pad_0[0x8150]; s16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; } g_Game_80140D18 asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x, y, z; s32 f30, f34, f38; } g_Spike_80140D18 asm("g_Spike");
extern s16 D_800EC238;
s32 Sound_Play(s32, s32);
void Sound_Stop(s32, s32);
void Spike_SetPlayMode(s32);
s32 func_801402D8(void *arg0);
s32 func_801402F8(void);

s32 func_80140D18(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140D18.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            g_Game_80140D18.f_8150 = 2;
            e[0x1B] = 0;
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[1] = 1;
            D_801434C8_80140D18.id = Sound_Play(0, 0xAC);
            D_801434C8_80140D18.on = 1;
            D_801434C0_80140D18.id = Sound_PlayTracked(0, 0x50AD);
            D_801434C0_80140D18.on = 1;
            D_801434C4_80140D18.id = Sound_PlayTracked(0, 0x50AE);
            D_801434C4_80140D18.on = 1;
            D_800B4DB0_80140D18.a = 0x1000;
            D_800B4DB0_80140D18.b = 0x1000;
            D_800E7880_80140D18.f_34 = 0;
            D_800E7880_80140D18.f_38 = 0;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] > 0x20) {
            Sound_Stop(0xAC, D_801434C8_80140D18.id);
            D_801434C8_80140D18.on = 0;
            D_801434C8_80140D18.id = -1;
            p[1] = 2;
        }
        break;
    case 2:
        if (e[0x11] == p[5] + p[6]) {
            p[1] = 3;
            func_801402D8(e);
            func_801402F8();
            Spike_SetPlayMode(0);
            g_Spike_80140D18.x = e[0];
            g_Spike_80140D18.y = e[1] - e[4];
            g_Spike_80140D18.z = e[2];
            g_Spike_80140D18.f30 = 0;
            g_Spike_80140D18.f34 = 0;
            g_Spike_80140D18.f38 = 0;
        }
        break;
    case 3:
        if (D_800EC238 != p[2]) {
            p[1] = 0;
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x812A]; u16 f_812A; u8 pad_812C[0xE0]; u8 *f_820C; } g_Game_80140F30 asm("g_Game");
extern u8 *D_800B4D64_80140F30 asm("D_800B4D64");
s32 func_801402F8(void);

s32 func_80140F30(s16 *p) {
    u8 *e = g_Game_80140F30.f_820C + p[2] * 0x38;

    if (g_Game_80140F30.f_812A == 0) {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    } else {
        p[1] = 5;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80140F30 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        func_801402D8(e);
        func_801402F8();
    }
    p[3] = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140FE0 asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x, y, z; s32 f30, f34, f38; } g_Spike_80140FE0 asm("g_Spike");
extern u8 *D_800B4D64_80140FE0 asm("D_800B4D64");
typedef struct { s16 id; s16 on; } Snd_80140FE0;
extern Snd_80140FE0 D_801434C0_80140FE0 asm("D_801434C0");
extern Snd_80140FE0 D_801434C4_80140FE0 asm("D_801434C4");
extern s16 D_800EC238;
s32 func_801402D8(void *arg0);
s32 func_80140374(u8 *e);
void Spike_SetPlayMode(s32);
s32 func_80087BA4(s32, s16, s16, s16);

s32 func_80140FE0(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140FE0.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (p[4] == e[0x19]) {
            p[1] = 1;
            func_801402D8(e);
            func_801402F8();
            Spike_SetPlayMode(0);
            g_Spike_80140FE0.x = e[0];
            g_Spike_80140FE0.y = e[1] - e[4];
            g_Spike_80140FE0.z = e[2];
            g_Spike_80140FE0.f30 = 0;
            g_Spike_80140FE0.f34 = 0;
            g_Spike_80140FE0.f38 = 0;
        }
        break;
    case 1:
        if (D_800EC238 != p[2]) {
            p[1] = 3;
            p[3] = 0;
            p[6] = func_80140374((u8 *)e);
        }
        break;
    case 2:
        break;
    case 3:
        if (p[5] == e[0x19]) {
            p[1] = 4;
            if (e[7] >= 0) {
                M2C_FIELD(D_800B4D64_80140FE0 + e[7] * 32, s16 *, 0x16) = 0;
            }
            func_801402D8(e);
            p[3] = 0x3C;
        }
        break;
    case 4:
        func_80087BA4(0xAD, D_801434C0_80140FE0.id, p[3], 0x3C);
        func_80087BA4(0xAE, D_801434C4_80140FE0.id, p[3], 0x3C);
        if (--p[3] <= 0) {
            p[1] = 5;
            func_801402F8();
        }
        break;
    case 5:
        break;
    }
    return 0;
}

s32 func_8014119C(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    p[3] = 0;
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[1] = 0;
    return 0;
}

typedef struct { s16 id; s16 on; } Snd_801411E8;
extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; } g_Game_801411E8 asm("g_Game");
extern s16 D_800EC238;
extern Snd_801411E8 D_801434C8;
extern Snd_801411E8 D_801434C0_801411E8 asm("D_801434C0");
extern Snd_801411E8 D_801434C4_801411E8 asm("D_801434C4");
extern struct { s16 a; s16 b; } D_800B4DB0;
extern struct { u8 pad_0[0x34]; s32 f_34; s32 f_38; } D_800E7880_801411E8 asm("D_800E7880");
s32 Sound_Play(s32, s32);
s32 Sound_PlayTracked(s32, s32);
void Sound_Stop(s32, s32);

s32 func_801411E8(s16 *p) {
    u8 *e = g_Game_801411E8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            g_Game_801411E8.f_8150 = 2;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 1;
            D_801434C8.id = Sound_Play(0, 0xAC);
            D_801434C8.on = 1;
            D_801434C0_801411E8.id = Sound_PlayTracked(0, 0x50AD);
            D_801434C0_801411E8.on = 1;
            D_801434C4_801411E8.id = Sound_PlayTracked(0, 0x50AE);
            D_801434C4_801411E8.on = 1;
            D_800B4DB0.a = 0x1000;
            D_800B4DB0.b = 0x1000;
            D_800E7880_801411E8.f_34 = 0;
            D_800E7880_801411E8.f_38 = 0;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] > 32) {
            Sound_Stop(0xAC, D_801434C8.id);
            D_801434C8.on = 0;
            D_801434C8.id = -1;
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_8014134C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8014134C asm("g_Game");
typedef struct { u8 pad_0[0x20C]; u8 *f_820C; u8 pad_210[0x10]; u8 *f_8220; } G_8014134C;
extern G_8014134C D_800F4350_8014134C asm("D_800F4350");
extern u8 *D_800B4D64_8014134C asm("D_800B4D64");

s32 func_8014134C(s16 *p) {
    G_8014134C *g;
    u8 *d;
    u8 *t;
    s32 i;
    u8 *e = g_Game_8014134C.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[1] = p[10];
    p[3] = 0;
    if (p[4] == 0 && M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_8014134C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    if (p[10] == 1) {
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8014134C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        i = p[5];
        p[7] = M2C_FIELD(e, u16 *, 0);
        p[8] = M2C_FIELD(e, u16 *, 2);
        p[9] = M2C_FIELD(e, u16 *, 4);
        if (i >= 0) {
            g = &D_800F4350_8014134C;
            d = D_800B4D64_8014134C;
            do {
                t = g->f_8220 + i * 0x18;
                e = g->f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
                if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                    M2C_FIELD(d + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
                }
            } while ((i = M2C_FIELD(t, s16 *, 0xA)) >= 0);
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_801414A0;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_801414A0 *f_8220; } g_Game_801414A0 asm("g_Game");
extern u8 *D_800B4D64_801414A0 asm("D_800B4D64");
void CamFlyby_StartSegment(s32);

s32 func_801414A0(s16 *p) {
    u8 *e;
    S18_801414A0 *t;
    s32 i;
    u8 *d;

    if (p[2] < 0) {
        return 0;
    }
    CamFlyby_StartSegment(0);
    g_Game_801414A0.f_8100 = 7;
    e = g_Game_801414A0.f_820C + p[2] * 0x38;
    p[1] = 1;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_801414A0 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
    }
    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    p[7] = M2C_FIELD(e, s16 *, 0);
    p[8] = M2C_FIELD(e, s16 *, 2);
    p[9] = M2C_FIELD(e, s16 *, 4);
    i = p[5];
    if (i >= 0) {
        d = D_800B4D64_801414A0;
        do {
        t = g_Game_801414A0.f_8220 + i;
        e = g_Game_801414A0.f_820C + t->f[2] * 0x38;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(d + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        i = t->f[5];
        } while (i >= 0);
    }
    return 0;
}

s32 func_801415D4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

extern struct { s32 f_0; u8 pad_4[0x8122]; u16 f_8126; u8 pad_8128[0x2]; u16 f_812A; u8 pad_812C[0xE0]; u8 *f_820C; } g_Game_801415E0 asm("g_Game");
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; } D_800E7880_801415E0 asm("D_800E7880");
extern s16 D_801434C0_801415E0[2] asm("D_801434C0");
extern s16 D_801434C4_801415E0[2] asm("D_801434C4");
extern s16 g_SpikeHealth;
extern u8 *D_800B4D64_801415E0 asm("D_800B4D64");
s32 func_8005DC78(void);
void Spike_TakeDamage(s32);
void Cd_PlayXaTrack(s32);
void func_800880D0_801415E0(s32, s32) asm("func_800880D0");
void Sound_PlayFixed_801415E0(s32) asm("Sound_PlayFixed");
void Effect_SpawnAt_801415E0(s32, void *) asm("Effect_SpawnAt");

s32 func_801415E0(s16 *p) {
    u8 *e = g_Game_801415E0.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (M2C_FIELD(e, s16 *, 0x32) != p[4]) {
            break;
        }
        if (D_800E7888 < -0xFF) {
            break;
        }
        if (func_8005DC78() == 0) {
            break;
        }
        Pad_Vibrate(0, 1, 3);
        Camera_StartShake(1);
        Spike_TakeDamage(1);
        if (g_SpikeHealth <= 0) {
            p[1] = 1;
            p[3] = 0;
            Game_SetMode(10, g_Game_801415E0.f_8126, g_Game_801415E0.f_812A);
            if (g_Game_801415E0.f_0 & 1) {
                Cd_PlayXaTrack(0xD);
            } else {
                Cd_PlayXaTrack(0xF);
            }
            D_801434CC = 1;
            D_801434CE = 0;
            D_801434D0 = 0;
            if (D_800E7880_801415E0.f_8 < 0) {
                D_800E7880_801415E0.f_14 -= 0x80;
            } else {
                D_800E7880_801415E0.f_14 = -0x80;
                D_800E7880_801415E0.f_8 = -0x80;
                if (D_801434C0_801415E0[1] != 0) {
                    func_800880D0_801415E0(0x50AD, D_801434C0_801415E0[0]);
                    D_801434C0_801415E0[1] = 0;
                }
                if (D_801434C4_801415E0[1] != 0) {
                    func_800880D0_801415E0(0x50AE, D_801434C4_801415E0[0]);
                    D_801434C4_801415E0[1] = 0;
                }
            }
        } else {
            Sound_PlayFixed_801415E0(0x8B);
        }
        e = g_Game_801415E0.f_820C + p[5] * 0x38;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_801415E0 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            Effect_SpawnAt_801415E0(0x102, e);
            Sound_PlayFixed_801415E0(0x4D);
            Sound_PlayFixed_801415E0(0x5F);
        }
        break;
    case 1:
        p[3]++;
        if ((s16)(p[3] % 10) == 0) {
            Camera_StartShake(1);
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                Effect_SpawnAt_801415E0(0x102, e);
                Sound_PlayFixed_801415E0(0x4D);
                Sound_PlayFixed_801415E0(0x5F);
            }
        }
        if (p[3] >= 0x1F) {
            p[1] = 2;
        }
        goto tail;
    case 2:
        p[3]++;
        if ((s16)(p[3] % 10) == 0) {
            Camera_StartShake(1);
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                Effect_SpawnAt_801415E0(0x102, e);
                Sound_PlayFixed_801415E0(0x4D);
                Sound_PlayFixed_801415E0(0x5F);
            }
        }
    tail:
        if (D_800E7880_801415E0.f_8 == 0) {
            D_800E7880_801415E0.f_14 = -0x80;
            D_800E7880_801415E0.f_8 = -0x80;
            if (D_801434C0_801415E0[1] != 0) {
                func_800880D0_801415E0(0x50AD, D_801434C0_801415E0[0]);
                D_801434C0_801415E0[1] = 0;
            }
            if (D_801434C4_801415E0[1] != 0) {
                func_800880D0_801415E0(0x50AE, D_801434C4_801415E0[0]);
                D_801434C4_801415E0[1] = 0;
            }
        }
        break;
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; u8 pad_4[6]; s16 f_A; u8 pad_C[0xC]; } T_801419AC;
typedef struct { u8 pad_0[0x16]; s16 f_16; u8 pad_18[8]; } V_801419AC;
typedef struct { u8 pad_0[0xE]; s16 f_E; u8 pad_10[8]; u16 f_18; u8 pad_1A[0x1E]; } E_801419AC;
extern struct { u8 pad_0[0x20C]; E_801419AC *f_20C; u8 pad_210[0x10]; T_801419AC *f_220; } D_800F4350_801419AC asm("D_800F4350");
extern V_801419AC *D_800B4D64_801419AC asm("D_800B4D64");

s32 func_801419AC(s16 *p) {
    s16 b[20];
    s16 a[20];
    s16 i;
    s16 j;
    s16 k;
    s16 r;
    T_801419AC *t;
    E_801419AC *e;

    for (i = 0; i < 20; i++) {
        a[i] = -1;
        b[i] = -1;
    }
    for (i = 0; i < p[4]; i++) {
        b[i] = i + 1;
        t = &D_800F4350_801419AC.f_220[a[i]];
        t->f_2 = 0;
    }
    for (i = 0; i < p[4] - p[5]; i++) {
        r = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % (p[4] - i);
        k = 0;
        for (j = 0; j < p[4]; j++) {
            if (b[j] >= 0) {
                if (r == k) {
                    k = j;
                    break;
                }
                k++;
            }
        }
        a[i] = b[k];
        b[k] = -1;
    }
    for (i = 0; i < p[4] - p[5]; i++) {
        if (a[i] >= 0) {
            t = &D_800F4350_801419AC.f_220[a[i]];
            t->f_2 = 3;
            if (t->f_A >= 0) {
                e = &D_800F4350_801419AC.f_20C[t->f_A];
                e->f_18 |= 0x8000;
                if (e->f_E >= 0) {
                    D_800B4D64_801419AC[e->f_E].f_16 = 0;
                }
            }
        }
    }
    return 0;
}

s32 func_80141C68(void) {
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80141C70 asm("g_Game");

s32 func_80141C70(s16 *p) {
    u8 *e = g_Game_80141C70.f_820C + p[2] * 0x38;
    s32 v = M2C_FIELD(e, s16 *, 0x32);

    D_801434D2 = 0;
    if (v >= p[4] && p[5] >= v) {
        D_801434D2 = 1;
    }
    return 0;
}

s32 func_80141CD4(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    if (M2C_FIELD(e, s16 *, 0x32) == p[4]) {
        Sound_PlayFixed(0x78);
    }
    return 0;
}

s32 func_80141D30(void *arg0) {
    s16 temp_a0;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    if (SaveByte_Get(5) == 5) {
        temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80141D94;
extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0x2E]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; u8 pad_8210[0x10]; S18_80141D94 *f_8220; } g_Game_80141D94 asm("g_Game");
extern u8 *D_800B4D64_80141D94 asm("D_800B4D64");
s32 Overlay_GetState_80141D94(void) asm("Overlay_GetState");
void Overlay_Request(s8);
void func_8004BD0C(void);
s32 func_800863B0(s32, s32);

s32 func_80141D94(s16 *p) {
    u8 *e;
    S18_80141D94 *t;

    if (g_Game_80141D94.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
        t = g_Game_80141D94.f_8220 + p[9];
        if (t->f[0xB] < p[7]) {
            return 0;
        }
        if (g_Game_80141D94.f_8150 != 0) {
            return 0;
        }
        p[1] = 4;
        p[3] = 0;
        if (p[8] >= 0) {
            t = g_Game_80141D94.f_8220 + p[8];
            e = g_Game_80141D94.f_820C + t->f[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_80141D94 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
        }
        if (p[6] >= 0) {
            M2C_FIELD(D_800B4D64_80141D94 + p[6] * 32, s16 *, 0x16) = 0;
        }
        func_800863B0(2, 0x28);
        Overlay_Request(5);
        return 0;
    case 4:
        if (Overlay_GetState_80141D94() != 0) {
            return 0;
        }
        p[1] = 5;
        func_8004BD0C();
        func_800863B0(0, 0);
        return 0;
    case 5:
        break;
    }
    return 0;
}

s32 func_80141F08(void *arg0) {
    s16 temp_a0;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    if (SaveByte_Get(5) == 5) {
        temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x8120]; u16 f_8120; } g_Game_80141F6C asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80141F6C asm("g_Spike");
s32 Overlay_GetState_80141F6C(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 func_800863B0(s32, s32);

s32 func_80141F6C(s16 *p) {
    if (g_Game_80141F6C.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (g_Spike_80141F6C.x < -0xEFF) {
            return 0;
        }
        if (g_Spike_80141F6C.y >= -0x5DC) {
            return 0;
        }
        if (g_Spike_80141F6C.z < -0x13FF) {
            return 0;
        }
        p[1] = 4;
        p[3] = 0;
        func_800863B0(2, 0x28);
        Overlay_Request(4);
        return 0;
    case 4:
        if (Overlay_GetState_80141F6C() != 0) {
            return 0;
        }
        p[1] = 5;
        func_800863B0(0, 0);
        break;
    case 5:
        break;
    }
    return 0;
}

void RotMatrixZYX(SVECTOR *, void *);

s32 func_80142054(s16 *p) {
    SVECTOR r;

    if (p[6] >= 0) {
        p[1] = 0;
        p[3] = 0;
        r.vy = 0;
        r.vx = 0;
        r.vz = (-p[7] << 12) / 360;
        RotMatrixZYX(&r, M2C_FIELD(D_800B4D64 + p[6] * 32, void **, 0x1C));
    } else {
        p[1] = 4;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/418/nonmatchings/418_monkey_madness_d", func_801420E8);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8014277C asm("g_Game");
extern u8 *D_800B4D64_8014277C asm("D_800B4D64");

s32 func_8014277C(s16 *p) {
    u8 *e;

    if (SaveByte_Get(5) == 5) {
        e = g_Game_8014277C.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8014277C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

s32 func_80142800(void) {
    return 0;
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80142808;
typedef struct { u16 start; u16 end; } Rng_80142808;
extern struct { u8 pad0[0x14]; Mat_80142808 *mat; void *anim; u8 pad1C[0x40]; u16 frame; s16 f5E; u8 pad60[0x2C]; s16 f8C; u8 pad8E[6]; Mat_80142808 m94; u8 padB4[0x2C]; s32 fE0; } g_Spike_80142808 asm("g_Spike");
extern void *g_SpikeAnimSets[];
extern struct { u8 pad0[0x158]; u32 f158; u8 pad15C[4]; u32 f160; } g_Pad_80142808 asm("g_Pad");
extern s32 D_800EC214;
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80142808 asm("g_Game");
extern u8 D_800E7D00_80142808[] asm("D_800E7D00");
void Anim_SetFrame(void *);
void *ApplyMatrix(void *, void *, void *);
void Matrix_RotateY(s32, void *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_80142808(void *, void *, void *) asm("func_80017CD4");

void func_80142808(void) {
    SVECTOR v;
    Rng_80142808 *r;

    g_Spike_80142808.f5E = 0;
    g_Spike_80142808.f8C = 0;
    g_Spike_80142808.frame++;
    g_Spike_80142808.anim = g_SpikeAnimSets[0];
    r = g_SpikeAnimSets[1];
    if (r->end < g_Spike_80142808.frame || g_Spike_80142808.frame < r->start) {
        g_Spike_80142808.frame = r->start;
    }
    if (g_Pad_80142808.f158 & g_Pad_80142808.f160 & 0xA) {
        D_800EC214 = -1;
    } else {
        D_800EC214 = 0;
    }
    Anim_SetFrame(&g_Spike_80142808);
    if (g_Spike_80142808.fE0 & 1) {
        *g_Spike_80142808.mat = g_Spike_80142808.m94;
        v.vx = g_Spike_80142808.m94.t[0];
        v.vy = g_Spike_80142808.m94.t[1];
        v.vz = g_Spike_80142808.m94.t[2];
        ApplyMatrix(g_Spike_80142808.mat, &v, g_Spike_80142808.mat->t);
    }
    Matrix_RotateY(0x400, g_Spike_80142808.mat);
    Model_CalcJointMatrices(&g_Spike_80142808, 7);
    Model_ProjectBonedVerts(&g_Spike_80142808);
    func_80017CD4_80142808(g_Game_80142808.f_80 + g_Game_80142808.f_C * 0x4078, D_800E7D00_80142808, &g_Spike_80142808);
    g_Spike_80142808.fE0 = 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
