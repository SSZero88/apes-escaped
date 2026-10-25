#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D028(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D050(void) {
    Pad_Vibrate(1, 0x78, 2);
}

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

void func_8013D078(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D10C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D1AC);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D324);

extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013D43C asm("g_Game");
extern u8 D_800E78C0[];
extern u8 D_800E7D00[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void Matrix_FromDirection(void *, void *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_8013D324(void *, void *, void *, s32);

s32 func_8013D43C(u8 *a, void *scale, s32 c) {
    SVECTOR v;
    s32 sxy;
    s16 x;
    s16 y;
    s32 p;
    s32 z;

    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    v.vx = M2C_FIELD(a, s32 *, 0x24);
    v.vy = M2C_FIELD(a, s32 *, 0x28);
    v.vz = M2C_FIELD(a, s32 *, 0x2C);
    z = RotTransPers(&v, &sxy, &p, &p);
    x = sxy;
    y = sxy >> 16;
    if (x < -0x80 || x > 0x200 || y < -0x80 || y > 0x1B8 || z > 0x1000 || z <= 0) {
        return 1;
    }
    Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
    ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
    func_80015780(a, 3);
    Model_ProjectBonedVerts(a);
    func_8013D324(g_Game_8013D43C.f_80 + g_Game_8013D43C.f_C * 0x4078, D_800E7D00, a, c);
    return 0;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D57C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D708);

extern u8 D_80140944;

void func_8013D804(void) {
    D_80140944 = 0;
}

extern struct { SVECTOR v; u8 pad8[0x3C]; u8 f_44; u8 pad45; s16 f_46; } D_80140900;

void func_8013D810(SVECTOR *v) {
    if (D_80140900.f_44 == 0) {
        D_80140900.f_44 = 1;
        D_80140900.f_46 = 0x32;
        D_80140900.v = *v;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D860);

typedef struct { u8 pad0[0x54]; u8 f_54; u8 pad55[7]; } Slot_421;
extern Slot_421 D_80140948[4];

void func_8013DE14(void) {
    s32 i;
    Slot_421 *p;

    for (i = 3, p = D_80140948; i >= 0; i--, p++) {
        p->f_54 = 0;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DE38);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013DEEC);

typedef struct { u8 pad0[0x1C]; u8 f_1C; u8 pad1D[7]; } Slot_421b;
extern Slot_421b D_80140AB8[16];
extern u8 D_80140CF8;

void func_8013E4D8(void) {
    s32 i;
    Slot_421b *p;

    for (i = 15, p = D_80140AB8; i >= 0; i--, p++) {
        p->f_1C = 0;
    }
    D_80140CF8 = 0;
}

typedef struct {
    SVECTOR pos;
    s32 f_8;
    SVECTOR vel;
    SVECTOR vel0;
    u8 f_1C;
    u8 f_1D;
    s16 f_1E;
    u8 f_20;
    u8 f_21;
    u8 pad_22[2];
} Spark_8013E500;
extern Spark_8013E500 D_80140AB8_E500[] asm("D_80140AB8");

void func_8013E500(SVECTOR *pos, s32 a1, s32 rnd, u8 a3, u8 a4) {
    Spark_8013E500 *e = &D_80140AB8_E500[D_80140CF8];

    e->f_1C = 8;
    e->f_1D = 1;
    e->pos = *pos;
    e->f_8 = a1;
    e->f_1E = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
    e->f_20 = a3;
    e->f_21 = a4;
    if (rnd == 0) {
        e->vel.vx = 0;
        e->vel.vy = 0;
        e->vel.vz = 0;
    } else {
        e->vel.vx = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0x10;
        e->vel.vy = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) - 7;
        e->vel.vz = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0x10;
    }
    e->vel0 = e->vel;
    D_80140CF8 = (D_80140CF8 + 1) % 16;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E650);

typedef struct { u8 pad0[6]; u8 f_6; u8 pad7[5]; } Slot_421c;
extern Slot_421c D_80140D00[4];

void func_8013E8C0(void) {
    s32 i;
    Slot_421c *p;

    for (i = 3, p = D_80140D00; i >= 0; i--, p++) {
        p->f_6 = 0;
    }
}

typedef struct { s16 x, y, z; u8 f6, f7, f8; u8 pad9[3]; } Puff_421;
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
void Sound_PlayFixed(s32);

void func_8013E8E4(void) {
    s32 i;
    Puff_421 *e;

    for (i = 3, e = D_80140D00; i >= 0; i--, e++) {
        if (e->f6 == 0) {
            e->f6 = 1;
            e->f7 = 0x1B;
            e->x = g_Spike.f_24;
            e->y = g_Spike.f_28 - 0x40;
            e->z = g_Spike.f_2C;
            e->f8 = 0x40;
            Sound_PlayFixed(0x18);
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E97C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013EE04);

extern struct { s32 f_0; s32 f_4; u8 pad8[0x12]; u8 f_1A[18]; } D_80140D30;

void func_8013F4F0(void) {
    s32 i;

    for (i = 0; i < 18; i++) {
        D_80140D30.f_1A[i] = 0;
        D_80140D30.f_0 = 0;
        D_80140D30.f_4 = 0;
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F520);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F694);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F848);

extern struct { u8 pad0[4]; s32 f_4; u8 pad8[0x32]; u8 f_3A; } D_801408C0;

void func_8013FC74(void) {
    D_801408C0.f_3A = 0;
    D_801408C0.f_4 = 0x1E;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FC8C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FD74);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140280);

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80141880");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D88(SVECTOR *arg0, s32 arg1) {
    s32 i;
    u16 x = arg0->vx;
    u16 y = arg0->vy;
    u16 z = arg0->vz;
    s16 floor = Floor_GetHeight(arg0->vx, arg0->vy, arg0->vz);

    for (i = 15; i >= 0; i--) {
        if (D_80144590_8013D028[i].life == 0) {
            D_80144590_8013D028[i].life = (RAND() >> 8 & 0x1F) + 0x28;
            D_80144590_8013D028[i].floor = floor;
            D_80144590_8013D028[i].x = x + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].y = y - ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].z = z + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].vx = ((RAND() >> 8) - 0x80) / 8;
            D_80144590_8013D028[i].vy = -(RAND() >> 8 & 0x1F) - 0x18;
            D_80144590_8013D028[i].vz = ((RAND() >> 8) - 0x80) / 8;
            if (--arg1 == 0) {
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140F78);

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_80141418(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_80140D88(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

s32 SaveByte_Get(s32);

s32 func_8014149C(s16 *p)
{
  s32 v;
  p[1] = p[4];
  p[3] = 0;
  v = p[1];
  if ((v == 5) && (SaveByte_Get(3) != v))
  {
    p[1] = 2;
  }
  return 0;
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801414F8);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_801416D8);

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6", D_80141850);
