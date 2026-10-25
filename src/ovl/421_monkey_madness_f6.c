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

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D1AC asm("g_Game");
extern s16 D_800E69BE;
extern u8 D_80140470[];
extern struct { s32 f_0; s32 f_4; u8 f_8; u8 pad9[3]; s32 f_C; s32 f_10; u8 pad14[4]; s16 f_18; s16 f_1A; u8 pad1C[0x1E]; u8 f_3A; u8 f_3B; u8 f_3C; } D_801408C0_8013D1AC asm("D_801408C0");
s32 Collision_Set(s32, void *, void *);
void func_8013D10C(s32, void *, void *);
void func_8013F4F0(void);
void func_8013E8C0(void);
void func_8013DE14(void);
void func_8013E4D8(void);
void func_8013D804(void);

void func_8013D1AC(void) {
    s32 i;
    u8 *e;
    u8 *m;
    u8 *h;

    h = g_Game_8013D1AC.f_8244;
    D_800E69BE = 0;
    m = h + M2C_FIELD(h, s32 *, 8);
    for (i = 0, e = D_80140470; i < 8; i++, e += 0x80) {
        func_8013D10C(i, e, e + 0x70);
        M2C_FIELD(e, s32 *, 0x28) = -0x3600;
        M2C_FIELD(e, s32 *, 0x74) = 0;
        M2C_FIELD(e, s32 *, 0x24) = 0;
        M2C_FIELD(e, s32 *, 0x2C) = 0x12B8;
        M2C_FIELD(e, s16 *, 0x60) = 0;
        M2C_FIELD(e, s16 *, 0x62) = 0;
        M2C_FIELD(e, s16 *, 0x64) = -0x1000;
        if (*(u16 *)m == 0xD4) {
            Collision_Set(5, e + 0x24, e);
            M2C_FIELD(e, s16 *, 0x48) = 0;
            M2C_FIELD(e, s16 *, 0x4A) = -0x4000;
            M2C_FIELD(e, s16 *, 0x44) = 0x230;
            M2C_FIELD(e, s16 *, 0x46) = 0x384;
        }
        m += 0x20;
    }
    D_801408C0_8013D1AC.f_8 = 1;
    D_801408C0_8013D1AC.f_0 = 0;
    D_801408C0_8013D1AC.f_4 = 0;
    D_801408C0_8013D1AC.f_C = 0;
    D_801408C0_8013D1AC.f_10 = 0;
    D_801408C0_8013D1AC.f_18 = 0;
    D_801408C0_8013D1AC.f_1A = 0;
    D_801408C0_8013D1AC.f_3A = 1;
    D_801408C0_8013D1AC.f_3B = 6;
    D_801408C0_8013D1AC.f_3C = 0;
    func_8013F4F0();
    func_8013E8C0();
    func_8013DE14();
    func_8013E4D8();
    func_8013D804();
}

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

extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; } g_Spike_8013D708 asm("g_Spike");
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; } Shape_8013D708;
typedef struct { Shape_8013D708 *shape; s16 x, y, z; } Coll_8013D708;

void func_8013D708(Coll_8013D708 *c, void *owner, s32 arg2) {
    s32 dx = g_Spike_8013D708.x - c->x;
    s32 dz = g_Spike_8013D708.z - c->z;
    Shape_8013D708 *s;

    if (dx * dx + dz * dz > 0x24000) {
        c->shape = 0;
        return;
    }
    s = CollShape_Alloc();
    c->shape = s;
    if (s != 0) {
        c->shape->x = c->x;
        c->shape->y = c->y;
        c->shape->z = c->z;
        c->shape->f_20 = arg2;
        c->shape->f_24 = 1;
        c->shape->f_26 = 0x200;
        Collision_Set(7, c->shape, owner);
    }
}

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

typedef struct { s32 f_0; SVECTOR v[8]; SVECTOR pos; u8 pad4C[8]; u8 f_54; u8 pad55[3]; s16 f_58; u8 pad5A[2]; } Slot_8013DE38;
extern Slot_8013DE38 D_80140948_8013DE38[4] asm("D_80140948");
extern struct { u8 pad0[0x24]; SVECTOR v; } D_801408C0_8013DE38 asm("D_801408C0");

void func_8013DE38(s32 unused, SVECTOR *pos) {
    s32 i;
    Slot_8013DE38 *p;

    for (i = 3, p = D_80140948_8013DE38; i >= 0; i--, p++) {
        if (p->f_54 == 0) {
            p->f_54 = 1;
            p->f_58 = 1;
            p->pos = *pos;
            p->pos.vy += 0xC0;
            for (i = 0; i < 8; i++) {
                p->v[i] = D_801408C0_8013DE38.v;
            }
            return;
        }
    }
}

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

extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; u8 pad_2E[2]; s32 f_30; u8 pad_34[4]; s32 f_38; } g_Spike_8013F520 asm("g_Spike");
typedef struct { u8 pad0[0x1A]; s16 f_1A; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[0xA]; SVECTOR v; } St_8013F520;
extern SVECTOR D_801408EC;
void func_8013E500(SVECTOR *pos, s32 a1, s32 rnd, u8 a3, u8 a4);

void func_8013F520(void) {
    SVECTOR sv;
    u16 x, y, z;
    u16 t;
    s32 a;
    SVECTOR *v = &D_801408EC;
    St_8013F520 *d = (St_8013F520 *)((u8 *)v - 0x2C);

    v->vx = x = g_Spike_8013F520.x;
    y = g_Spike_8013F520.y;
    z = g_Spike_8013F520.z;
    v->vy = y - 0x80;
    v->vz = z;
    if (d->f_1A != 0) {
        t = --d->f_1A;
        g_Spike_8013F520.f_30 = d->f_1C / 2;
        g_Spike_8013F520.f_38 = a = d->f_20;
        d->f_1C = d->f_1C * 7 / 8;
        d->f_1E = d->f_1E * 7 / 8;
        d->f_20 = a * 7 / 8;
        if ((t & 3) == 0) {
            sv.vx = x + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2);
            sv.vy = y - ((g_RandSeed = g_RandSeed * 5 + 1) >> 8);
            sv.vz = z + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2);
            func_8013E500(&sv, (s32)v, 1, 8, 0x20);
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F694);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013F848);

extern struct { u8 pad0[4]; s32 f_4; u8 pad8[0x32]; u8 f_3A; } D_801408C0;

void func_8013FC74(void) {
    D_801408C0.f_3A = 0;
    D_801408C0.f_4 = 0x1E;
}

typedef struct { u8 pad0[0x24]; u16 f_24; u8 pad26[6]; u16 f_2C; u8 pad2E[0x2E]; s16 f_5C; u8 pad5E[0x22]; } Obj_8013FC8C;
extern Obj_8013FC8C D_801407F0[];
extern u8 D_80140458[];
s32 func_8013D43C(u8 *a, void *scale, s32 c);
void func_8013F694(void *, s32);
void func_8013F520(void);
void func_8013E650(void);

void func_8013FC8C(void) {
    SVECTOR v;
    s32 i;
    Obj_8013FC8C *o;
    s16 dx;
    s16 dz;

    for (i = 0; i < 1; i++) {
        D_801407F0[i].f_5C = 0;
        func_8013D43C((u8 *)&D_801407F0[i], D_80140458, 0);
    }
    o = D_801407F0;
    dx = g_Spike.f_24 - o->f_24;
    dz = g_Spike.f_2C - o->f_2C;
    v.vy = 0;
    v.vx = dx;
    v.vz = dz;
    if (dx * dx + dz * dz <= 0x19C98F) {
        func_8013F694(o, 0x14);
    }
    func_8013F520();
    func_8013E650();
}

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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801416D8 asm("g_Game");
extern s16 D_800EC238;

s32 func_801416D8(s16 *p) {
    u8 *e = g_Game_801416D8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            if (p[3] == 0) {
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
                p[3] = 1;
                p[1] = 3;
                Sound_PlayAt(0x9C, (s32)e);
            }
        } else {
            p[3] = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(e, s16 *, 0x32) == p[8] * 2 + 1 || M2C_FIELD(e, s16 *, 0x32) == p[9] * 2 + 1) {
            Sound_PlayAt(0x9C, (s32)e);
        }
        if (M2C_FIELD(e, s16 *, 0x32) >= p[7] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 0;
            Sound_PlayAt(0x9C, (s32)e);
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6", D_80141850);
