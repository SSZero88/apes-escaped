#include "common.h"
#include "m2c_macros.h"

extern struct S_D_8013FAD0 { u8 pad_0[0xB]; s8 f_B; } D_8013FAD0[];
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Puff_Spawn(s32, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
extern M2C_UNK D_8013FB90;
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
void func_8013E22C(void *arg0);
void *Collision_GetShape(s32);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK func_800525A0(void *, void *);
M2C_UNK func_80052864(void *);
M2C_UNK func_8005588C(void *, M2C_UNK);
void func_8013E26C(void *arg0);

s32 func_8013D000(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_8013FAD0[i].f_B = 0;
    }
    return 0;
}

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_8013FAD0");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D028(SVECTOR *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013D218);

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_8013D6B8(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_8013D028(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

void Effect_SpawnAt(s32, SVECTOR *);
s32 rcos_8013EF18(s32) asm("rcos");
s32 rsin_8013EF18(s32) asm("rsin");
extern u16 D_800AE8F2;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2() (D_800AE8F2 = D_800AE8F2 * 5 + 1)

void func_8013D73C(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    r = RAND() >> 8;
    a = (M2C_FIELD(arg0, s16 *, 0xAC) + (r << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013EF18(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (RAND2() >> 8) - 300;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013EF18(a) << 8) >> 12);
    Effect_SpawnAt(7, &v);
}

void func_8013D840(s32 arg0) {
    u16 temp_v0;

    Puff_Spawn(arg0 + 0x24, 1, 0, 0x12C);
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

void func_8006D548(SVECTOR *);
s32 rcos_8013F084(s32) asm("rcos");
s32 rsin_8013F084(s32) asm("rsin");

void func_8013D8A8(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    r = RAND() >> 8;
    a = (M2C_FIELD(arg0, s16 *, 0xAC) + (r << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F084(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (RAND2() >> 9) - 200;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F084(a) << 8) >> 12);
    func_8006D548(&v);
}

s32 rcos_8013D9A8(s32) asm("rcos");
s32 rsin_8013D9A8(s32) asm("rsin");

void func_8013D9A8(void *arg0) {
    SVECTOR v;
    s32 a;



    a = (M2C_FIELD(arg0, s16 *, 0xAC) + ((RAND() >> 8) << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013D9A8(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - ((RAND() >> 9) + 0xFA);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013D9A8(a) << 8) >> 12);
    Effect_SpawnAt(0x102, &v);
    Object_PlaySound(arg0, 0x6C);
    Object_PlaySound(arg0, 0x4D);
}

extern u32 g_Game_8013DAC8 asm("g_Game");

void func_8013DAC8(void *arg0) {
    if (g_Game_8013DAC8 % 5 == 0 || g_Game_8013DAC8 % 17 == 0) {
        func_8013D9A8(arg0);
    }
}

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013DB34);

void func_8013DC3C(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_8013FB90;
    do {
        M2C_FIELD(var_v0, s8 *, 0x18) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x30));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad0[0x14]; s32 b; u8 f_18; u8 pad19[7]; s32 a; SVECTOR v; s32 c; } Ev_423;
extern Ev_423 D_8013FB90_8013DC60[4] asm("D_8013FB90");

void func_8013DC60(s32 a, SVECTOR *v, s32 b, s32 c) {
    s32 i;
    Ev_423 *e;

    for (i = 3, e = D_8013FB90_8013DC60; i >= 0; i--, e++) {
        if (e->f_18 == 0) {
            e->f_18 = 1;
            e->a = a;
            e->v = *v;
            e->b = b;
            e->c = c;
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013DCC8);

typedef struct { u8 pad0[8]; s16 f_8, f_A; } Pt_423;
extern Pt_423 D_8013FC50[5];
void func_80014804(void *, void *);
void func_80015780(void *, s32);
void func_80051620(void *, s32, s32, Pt_423 *);

void func_8013E134(void *arg0) {
    s32 i;
    Pt_423 *e;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    func_80014804((u8 *)arg0 + 0x60, M2C_FIELD(arg0, void **, 0x14));
    func_80015780(arg0, 3);
    for (i = 4; i >= 0; i--) {
        e = &D_8013FC50[i];
        func_80051620(arg0, e->f_8, e->f_A, e);
    }
}

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013E1C4);

void func_8013E22C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, arg0 + 0x24);
    }
}

void func_8013E26C(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

typedef struct { s16 x, y, z; u8 pad6[6]; } Pt_8013E2B0;
extern Pt_8013E2B0 D_8013FC68[3];
extern u8 D_8013F998[];
void VectorNormalSS(void *, void *);
void func_80070284(void *, void *, s32, s32, void *);

void func_8013E2B0(u8 *e, s32 n) {
    SVECTOR v;
    SVECTOR s;
    Pt_8013E2B0 *p1;
    Pt_8013E2B0 *p2;
    u8 *k;
    s32 dz, dx;

    if ((M2C_FIELD(e, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    v.vx = D_8013FC68[2].x - D_8013FC68[1].x;
    p1 = &D_8013FC68[1];
    p2 = &D_8013FC68[2];
    v.vy = p2->y - p1->y;
    v.vz = p2->z - p1->z;
    VectorNormalSS(&v, &v);
    k = D_8013F998 + n * 0x54;
    dz = -((M2C_FIELD(e, s16 *, 0x64) * 75) >> 11);
    dx = (M2C_FIELD(e, s16 *, 0x60) * 75) >> 11;
    s.vx = (D_8013FC68[0].x + p1->x) / 2 + dz;
    s.vy = (D_8013FC68[0].y + p1->y) / 2;
    s.vz = (D_8013FC68[0].z + p1->z) / 2 + dx;
    func_80070284(&s, k, 1, 0, &v);
    s.vx = (D_8013FC68[0].x + p1->x) / 2 - dz;
    s.vz = (D_8013FC68[0].z + p1->z) / 2 - dx;
    func_80070284(&s, k, 1, 0, &v);
}

extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013E494 asm("g_Spike");
typedef struct { u16 x, y, z, pad; } Pt_8013E494;

/* called without its flag argument (old-style declaration), so defined old-style */
s32 func_8013E494(e, flag)
    u8 *e;
    s32 flag;
{
    SVECTOR a, b, c;
    Pt_8013E494 *pts;
    s32 n;
    Pt_8013E494 *p1, *p0;
    s32 d1, d2;

    if (e[0x8E] == 0) {
        return 1;
    }
    if (e[0x8E] == M2C_FIELD(e, u16 *, 0x8C) - 1) {
        return M2C_FIELD(e, u16 *, 0x8C) - 2;
    }
    n = e[0x8E];
    pts = M2C_FIELD(e, Pt_8013E494 **, 0x90);
    p1 = &pts[n + 1];
    p0 = &pts[n - 1];
    a.vx = g_Spike_8013E494.x - M2C_FIELD(e, u16 *, 0x24);
    a.vy = g_Spike_8013E494.y - M2C_FIELD(e, u16 *, 0x28);
    a.vz = g_Spike_8013E494.z - M2C_FIELD(e, u16 *, 0x2C);
    b.vx = p1->x - M2C_FIELD(e, u16 *, 0x24);
    b.vy = p1->y - M2C_FIELD(e, u16 *, 0x28);
    b.vz = p1->z - M2C_FIELD(e, u16 *, 0x2C);
    c.vx = p0->x - M2C_FIELD(e, u16 *, 0x24);
    c.vy = p0->y - M2C_FIELD(e, u16 *, 0x28);
    c.vz = p0->z - M2C_FIELD(e, u16 *, 0x2C);
    VectorNormalSS(&a, &a);
    VectorNormalSS(&b, &b);
    VectorNormalSS(&c, &c);
    d1 = (a.vx * b.vx + a.vz * b.vz) / 4096;
    d2 = (a.vx * c.vx + a.vz * c.vz) / 4096;
    if (flag != 0) {
        if (d2 < d1) {
            return e[0x8E] - 1;
        }
    } else {
        if (d2 >= d1) {
            return e[0x8E] - 1;
        }
    }
    return e[0x8E] + 1;
}

s32 func_8013E494();
void VectorNormalSS(void *, void *);
void Object_TurnToward(void *, s16, s16, s16, s16);

void func_8013E670(u8 *e, s32 flag) {
    s16 *pt;

    M2C_FIELD(e, u8 *, 0x8E) = func_8013E494(e);
    pt = (s16 *)(M2C_FIELD(e, u8 **, 0x90) + M2C_FIELD(e, u8 *, 0x8E) * 8);
    M2C_FIELD(e, s16 *, 0x94) = pt[0] - M2C_FIELD(e, s16 *, 0x24);
    M2C_FIELD(e, s16 *, 0x96) = pt[1] - M2C_FIELD(e, s16 *, 0x9C);
    M2C_FIELD(e, s16 *, 0x98) = pt[2] - M2C_FIELD(e, s16 *, 0x2C);
    VectorNormalSS(e + 0x94, e + 0x94);
    if (flag) {
        Object_TurnToward(e, -M2C_FIELD(e, s16 *, 0x94), -M2C_FIELD(e, s16 *, 0x98), 0, M2C_FIELD(e, s16 *, 0xB0));
    } else {
        Object_TurnToward(e, M2C_FIELD(e, s16 *, 0x94), M2C_FIELD(e, s16 *, 0x98), 0, M2C_FIELD(e, s16 *, 0xB0));
    }
}

void func_8013E740(void *arg0) {
    s32 temp_v0_2;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0xA8) - 0x46;
    M2C_FIELD(arg0, u16 *, 0xA8) = temp_v0;
    if ((s16) temp_v0 < 0) {
        M2C_FIELD(arg0, u16 *, 0xA8) = 0U;
    }
    temp_v0_2 = (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x94) * temp_v0_2) >> 0xC));
    M2C_FIELD(arg0, u16 *, 0x9C) = (u16) (M2C_FIELD(arg0, u16 *, 0x9C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x96) * temp_v0_2) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x98) * temp_v0_2) >> 0xC));
}

s16 Object_PathPointNear(void *, void *, s32, s32);

s32 func_8013E7CC(u8 *e, s32 spd) {
    s32 s;

    if (Object_PathPointNear(e, e + 0x24, spd * 2, M2C_FIELD(e, u8 *, 0x8E)) != 0) {
        return 1;
    }
    if ((M2C_FIELD(e, s16 *, 0xA8) >> 3) < spd) {
        M2C_FIELD(e, s16 *, 0xA8) += 0x32;
    }
    s = M2C_FIELD(e, s16 *, 0xA8) >> 3;
    M2C_FIELD(e, s32 *, 0x24) += (M2C_FIELD(e, s16 *, 0x94) * s) >> 12;
    M2C_FIELD(e, s16 *, 0x9C) += (M2C_FIELD(e, s16 *, 0x96) * s) >> 12;
    M2C_FIELD(e, s32 *, 0x2C) += (M2C_FIELD(e, s16 *, 0x98) * s) >> 12;
    return 0;
}

void func_8013E8A0(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x800) != 0) {
        func_8013E670(arg0, 1);
        M2C_FIELD(arg0, s8 *, 0x7F) = 7;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x40);
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x1C);
    } else {
        func_8013E670(arg0, 0);
        M2C_FIELD(arg0, s8 *, 0x7F) = 4;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~0x40);
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x10);
    }
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    func_8013E22C(arg0);
}

s32 rsin(s16);
void Object_StepOrbitAngle(void *, s16);

void func_8013E948(void *arg0)
{
  int new_var;
  new_var = 0xC8;
  Object_StepOrbitAngle(arg0, 0x10);
  *((s32 *) (((s8 *) arg0) + 0x28)) = (s32) ((*((s16 *) (((s8 *) arg0) + 0x9C))) - ((((s32) (rsin(*((s16 *) (((s8 *) arg0) + 0xAA))) << 7)) >> 0xC) + new_var));
}

typedef struct { s16 x, y, z; u8 pad6[6]; } Pt_8013E994;
extern Pt_8013E994 D_8013FC50_8013E994[2] asm("D_8013FC50");
void func_8013DC60(s32 a, SVECTOR *v, s32 b, s32 c);

void func_8013E994(u8 *e) {
    SVECTOR v;
    s32 dx;
    s32 dz;
    Pt_8013E994 *p;

    if (M2C_FIELD(e, u16 *, 0x5C) != *(u16 *)(M2C_FIELD(e, u8 **, 0x88) + M2C_FIELD(e, u8 *, 0x7F) * 4) + 0xD) {
        return;
    }
    if ((M2C_FIELD(e, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    dx = (M2C_FIELD(e, s16 *, 0x64) * 55) >> 11;
    M2C_FIELD(e, s16 *, 0xBC) = D_8013FC50_8013E994[0].x + dx;
    M2C_FIELD(e, s16 *, 0xBE) = D_8013FC50_8013E994[0].y;
    dz = -((M2C_FIELD(e, s16 *, 0x60) * 55) >> 11);
    M2C_FIELD(e, s16 *, 0xC0) = D_8013FC50_8013E994[0].z + dz;
    p = &D_8013FC50_8013E994[1];
    M2C_FIELD(e, s16 *, 0xC2) = p->x - dx;
    M2C_FIELD(e, s16 *, 0xC4) = p->y;
    M2C_FIELD(e, s16 *, 0xC6) = p->z - dz;
    v.vx = M2C_FIELD(e, s16 *, 0x60);
    v.vy = 0x578;
    v.vz = M2C_FIELD(e, s16 *, 0x64);
    VectorNormalSS(&v, &v);
    v.vx /= 16;
    v.vy /= 16;
    v.vz /= 16;
    func_8013DC60((s32)(e + 0xBC), &v, (s32)e, 0x8F);
    func_8013DC60((s32)(e + 0xC2), &v, (s32)e, 0x8F);
}

void func_8013EB00(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    func_8005588C(arg0, 0x3C);
}

void func_8013EB3C(void *arg0) {
    u32 temp_s1;
    u8 temp_v0;
    void *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (temp_v0 - 1);
        return;
    }
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 9) && (temp_s1 = (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C, (temp_s1 == 0xB)) && (temp_v0_2 = Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), ((M2C_FIELD(temp_v0_2, s16 *, 0x24) & 0xFF00) != 0xD00))) {
        func_800525A0(arg0, temp_v0_2);
        M2C_FIELD(arg0, s8 *, 0x84) = 0x14;
        func_8013E26C(arg0);
        func_80052864(arg0);
        if (M2C_FIELD(arg0, u8 *, 0x81) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 9U;
            M2C_FIELD(arg0, s8 *, 0x7F) = (s8) temp_s1;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x2C);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x80) = 0xAU;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_DisableCollision(arg0);
        func_8005588C(arg0, 0x3C);
    }
}

extern u32 g_Game_8013EC44 asm("g_Game");

void func_8013EC44(u8 *a) {
    if (g_Game_8013EC44 & 1) {
        if (a[0x81] < 5) {
            func_8013D73C(a);
            func_8013D73C(a);
            func_8013D8A8(a);
            func_8013D8A8(a);
            func_8013D840((s32)a);
        } else if (a[0x81] < 10) {
            func_8013D73C(a);
            func_8013D73C(a);
            func_8013D840((s32)a);
        } else if (a[0x81] < 15) {
            func_8013D73C(a);
        }
    }
}

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013ECE8);

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013EDBC);

s32 func_8013F360(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    return 0;
}

typedef struct { s16 x, y, z; u8 pad6[0x12]; u16 flags; u8 pad1A[0x1E]; } Ent_8013F370;
extern struct { u8 frame; u8 pad1[0x812B]; u8 f_812C; u8 pad812D[0xDF]; Ent_8013F370 *f_820C; u8 pad8210[0x48]; SVECTOR f_8258; } g_Game_8013F370 asm("g_Game");
extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013F370 asm("g_Spike");
extern u8 D_800E6908;
void func_8006F274(void *, void *, s32);
s32 func_8013F6BC();
s32 Vec_Length(s32, s32, s32);
s16 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);
s32 Sound_UpdateVoice3D(s32, s32, s16, s32);

s32 func_8013F370(s16 *a) {
    s16 box[6];
    SVECTOR p0;
    SVECTOR p1;
    Ent_8013F370 *e;
    s16 i;

    e = &g_Game_8013F370.f_820C[a[2]];
    e->flags |= 0x8000;
    box[0] = e->x;
    box[1] = e->y + 0x100;
    box[2] = e->z;
    box[3] = a[5];
    box[4] = a[6];
    box[5] = a[7];
    func_8013F6BC(a[4], box, 0x80);
    for (i = 0; i < 6; i++) {
        p0.vx = e->x - a[5];
        p0.vy = e->y - (a[6] - 0x100) * i / 6;
        p0.vz = e->z;
        p1.vx = e->x + a[5];
        p1.vy = e->y - (a[6] - 0x100) * i / 6;
        p1.vz = e->z;
        func_8006F274(&p0, &p1, g_Game_8013F370.frame * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        func_8006F274(&p0, &p1, g_Game_8013F370.frame * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
    }
    if (g_Game_8013F370.f_812C == 0x18 || D_800E6908 == 1) {
        p0 = g_Game_8013F370.f_8258;
    } else {
        p0.vx = g_Spike_8013F370.x;
        p0.vy = g_Spike_8013F370.y;
        p0.vz = g_Spike_8013F370.z;
    }
    box[1] = e->y - a[6] / 2;
    if (Vec_Length(p0.vx - box[0], p0.vy - box[1], p0.vz - box[2]) < 0x1000) {
        if (a[0xB] < 0) {
            a[0xB] = Sound_Play(1, 0x66);
        } else {
            Sound_UpdateVoice3D(0x66, a[0xB], 0x1000, (s32)box);
        }
    } else if (a[0xB] >= 0) {
        Sound_Stop(0x66, a[0xB]);
        a[0xB] = -1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/423/nonmatchings/423_monkey_madness_f4", func_8013F6BC);
