#include "common.h"
#include "m2c_macros.h"

s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_801409FC;
extern s32 D_80140CF8;
M2C_UNK Collision_Remove(void *);
M2C_UNK func_8007CDC4(void *);
M2C_UNK Collision_Set(M2C_UNK, void *, void *);
M2C_UNK func_8007CD88(void *);
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80056BC4(M2C_UNK, M2C_UNK, s8);
s32 Collision_GetShape(s32);
s32 Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK func_800525A0(void *, s32);
M2C_UNK func_80052864(void *);
extern s32 D_80140D40;
extern void *D_80140D4C;

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D000);

extern u16 g_RandSeed;
void Effect_SpawnAt(s32, SVECTOR *);
extern u8 D_800B1C28[];
void func_80070284(SVECTOR *, void *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D180(void *arg0, s32 dx, s32 dy, s32 dz) {
    SVECTOR v;
    SVECTOR r;
    s32 i;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + dx;
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) + dy;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + dz;
    Effect_SpawnAt(0x113, &v);
    for (i = 0; i < 3; i++) {
        r.vx = (RAND() >> 4) & 0xFF0;
        r.vy = (RAND() >> 4) & 0xFF0;
        r.vz = (RAND() >> 4) & 0xFF0;
        func_80070284(&v, D_800B1C28, 1, i * 2, &r);
    }
}

s32 SaveByte_Get(s32);
s32 func_8005BB5C(s32);

s32 func_8013D280(void) {
    s32 r;

    r = 0;
    if (SaveByte_Get(4) >= 4 || func_8005BB5C(0) >= 4) {
        r = 1;
    }
    return r;
}

void *memset(void *, s32, s32);
void Pickup_Drop(s32, SVECTOR *, s32, s32);

void func_8013D2D0(s32 *p) {
    SVECTOR w;
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = p[0];
    v.vy = p[1] - 0x32;
    v.vz = p[2];
    w = v;
    Pickup_Drop(1, &w, 3, 1);
    Pickup_Drop(3, &w, 3, 0);
}

void func_8013D374(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70AF, 0x1000, arg0 + 0x24);
    }
}

void func_8013D3B4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
}

M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);

void func_8013D3E4(s32 arg0) {
    func_8013D180(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    Sound_PlayFixed(0x15);
    func_80051E98(arg0, 1);
    func_8013D3B4(arg0);
}

s32 Object_AddAttackSphere(void *, s32, s16, s16, s32, s32, s32);
void func_80051E98(void *, s32);

void func_8013D43C(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(0x102, &v);
    Object_PlaySound(arg0, 0x6E);
    Object_AddAttackSphere(arg0, 0x12C, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, u16 *, 0x1E) - 0x64,
                           M2C_FIELD(arg0, s16 *, 0x20), 0x201, 0x201);
    func_80051E98(arg0, 1);
    func_8013D3B4(arg0);
}

void func_8013D2D0(s32 *p);
void func_8013D3E4(s32 arg0);
void func_8013D43C(void *arg0);

void func_8013D4D8(void *arg0) {
    u32 t = M2C_FIELD(arg0, u32 *, 0x50) >> 28;

    if (t == 11) {
        func_8013D2D0((s32 *)((u8 *)arg0 + 0x24));
        func_8013D3E4((s32)arg0);
    } else if (t == 1) {
        func_8013D43C(arg0);
    }
}

extern s32 D_800EC208;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[6]; s16 z; } g_Spike_8013D538 asm("g_Spike");
void Object_TurnToward(void *, s16, s16, s16, s16);

void func_8013D538(u8 *arg0) {
    s32 d = D_800EC208 - M2C_FIELD(arg0, s32 *, 0x28) - 0x32;

    if (ABS(d) >= 13) {
        if (d > 0) {
            M2C_FIELD(arg0, s32 *, 0x28) += 12;
        } else if (d < 0) {
            M2C_FIELD(arg0, s32 *, 0x28) -= 12;
        }
    }
    Object_TurnToward(arg0, g_Spike_8013D538.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike_8013D538.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, M2C_FIELD(arg0, s16 *, 0xB0));
    M2C_FIELD(arg0, s32 *, 0x24) += (M2C_FIELD(arg0, s16 *, 0x60) * 35) >> 12;
    M2C_FIELD(arg0, s32 *, 0x2C) += (M2C_FIELD(arg0, s16 *, 0x64) * 35) >> 12;
}

void func_8013D62C(void *arg0) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x74);
    Effect_Spawn(0xCA, temp_s1, &D_801409FC, 0);
    Effect_Spawn(0xCB, temp_s1, &D_801409FC, 0);
}

void *func_80057140(void *, s16, s16);
void func_80055F1C(void *, s32);

void func_8013D684(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, u8 *, 0xC8) = 5;
    M2C_FIELD(arg0, s16 *, 0x44) = 0x50;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x82;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) - 0x12C;
    M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x2000;
    M2C_FIELD(arg0, void **, 0x74) = func_80057140(arg0, 7, 0x5E);
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
    func_80055F1C(arg0, 6);
    M2C_FIELD(arg0, u8 *, 0x80) = 1;
    M2C_FIELD(arg0, u8 *, 0x7F) = 0;
    M2C_FIELD(arg0, s16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D738);

void func_8013D8F0(void *arg0, s32 a) {
    M2C_FIELD(arg0, u8 *, 0x71) = a;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x71) * 4 + M2C_FIELD(arg0, u8 **, 0x74));
}

typedef struct { u8 b[0x84]; } O_8013D910;
extern O_8013D910 D_80140A60[];
void func_80052038(void *, s32);
u8 *func_800520A8(void *, s32);

void func_8013D910(void) {
    u8 *o;
    s32 i;
    s32 m;

    for (i = 4; i >= 0; i--) {
        o = D_80140A60[i].b;
        switch (i % 3) {
        case 0:
            m = 0x5F;
            break;
        case 1:
            m = 0x61;
            break;
        case 2:
            m = 0x63;
            break;
        }
        func_80052038(o, m);
        M2C_FIELD(o, u8 **, 0x74) = func_800520A8(o, 0x5F);
        M2C_FIELD(o, s16 *, 0x44) = 0x50;
        M2C_FIELD(o, s16 *, 0x46) = 0x82;
        M2C_FIELD(o, s16 *, 0x66) = 3;
        M2C_FIELD(o, s16 *, 0x4A) = 0x8103;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        o[0x70] = i;
        o[0x73] = 0;
        o[0x72] = 1;
        o[0x7A] = 0;
        o[0x7D] = i * 0x33;
        M2C_FIELD(o, s8 *, 0x7E) = -1;
        func_8013D8F0(o, 0);
    }
}

void func_8013DA44(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7E) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7E) = Sound_ReserveSlot(0x70AF, 0x1000, arg0 + 0x24);
    }
}

void func_8013DA84(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7E);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
        M2C_FIELD(arg0, s8 *, 0x7E) = -1;
    }
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013DAC8;
extern struct { u32 frame; u8 pad_4[0x8]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013DAC8 asm("g_Game");
extern u8 D_800E7D00[];
s32 Floor_GetHeight_8013DAC8(s32, s32, s32) asm("Floor_GetHeight");
void Shadow_Draw_8013DAC8(void *, s16, s32, s32) asm("Shadow_Draw");
void func_80014804(s16 *, s16 *);
void *RotMatrixX(s32 r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void *ScaleMatrix(void *m, void *v);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80051AA4(u32 *, u8 *, void *, s32);

void func_8013DAC8(u8 *e, s32 size, s8 *spin) {
    s32 v[4];
    s32 sc;
    s32 shade;

    Shadow_Draw_8013DAC8(e + 0x24, Floor_GetHeight_8013DAC8(M2C_FIELD(e, s32 *, 0x24), M2C_FIELD(e, s32 *, 0x28), M2C_FIELD(e, s32 *, 0x2C)), 100, *(s32 *)0x1F8003FC);
    func_80014804((s16 *)(e + 0x60), M2C_FIELD(e, s16 **, 0x14));
    if (*spin != 0) {
        Mat_8013DAC8 m = { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } }, { 0, 0, 0 } };
        s32 r = g_Game_8013DAC8.frame % 5;

        if (r >= 3) {
            r = 5 - r;
        }
        shade = (r * 255) / 2;
        (*spin)--;
        RotMatrixX(0x1000 - *spin * 10, &m);
        CompMatrix(M2C_FIELD(e, void **, 0x14), &m, M2C_FIELD(e, void **, 0x14));
    } else {
        shade = 0;
    }
    sc = (size << 12) / 10;
    v[2] = sc;
    v[1] = sc;
    v[0] = sc;
    ScaleMatrix(M2C_FIELD(e, void **, 0x14), v);
    func_80015780(e, 3);
    Model_ProjectBonedVerts(e);
    func_80051AA4((u32 *)(g_Game_8013DAC8.f_80 + g_Game_8013DAC8.f_C * 0x4078), D_800E7D00, e, shade);
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mtx_417;
extern Mtx_417 D_800F4810;
extern u32 D_801409FC_8013DCC4[] asm("D_801409FC");
void *ApplyMatrixSV(void *, void *, void *);
void Effect_Spawn_8013DCC4(s32, s16 *, u32 *, s16 **) asm("Effect_Spawn");

void func_8013DCC4(void *arg0) {
    SVECTOR v;

    ApplyMatrixSV(&D_800F4810, M2C_FIELD(arg0, u8 **, 0x10) + 0x2F0, &v);
    v.vx += D_800F4810.t[0];
    v.vy += D_800F4810.t[1];
    v.vz += D_800F4810.t[2];
    Effect_Spawn_8013DCC4(0xCA, &v.vx, D_801409FC_8013DCC4, 0);
    Effect_Spawn_8013DCC4(0xCB, &v.vx, D_801409FC_8013DCC4, 0);
}

void func_8013DD64(void *arg0) {
    u16 temp_v1;
    void *temp_a0;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    temp_a0 = (M2C_FIELD(arg0, u8 *, 0x71) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((u16) M2C_FIELD(temp_a0, u16 *, 2) < (u32) (temp_v1 & 0xFFFF)) {
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a0, u16 *, 0);
    }
}

extern struct { u32 f_0; } g_Game_8013DDAC asm("g_Game");
extern s32 D_80140CF4;
s32 rcos_8013DDAC(s32) asm("rcos");
s32 rsin_8013DDAC(s32) asm("rsin");

void func_8013DDAC(u8 *arg0, u8 *arg1) {
    s32 *pos = (s32 *)(arg0 + 0x24);
    s32 ang;
    s32 dy;

    ang = (M2C_FIELD(arg1, s16 *, 0xAA) + (arg0[0x70] << 12) / D_80140CF4) % 0x1000;
    M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg1, s32 *, 0x24) + ((rcos_8013DDAC(ang) * 300) >> 12);
    pos[2] = M2C_FIELD(arg1, s32 *, 0x2C) + ((rsin_8013DDAC(ang) * 300) >> 12);
    dy = ((rsin_8013DDAC((ang + ((g_Game_8013DDAC.f_0 % 60) << 12) / 60) & 0xFFF) * 100) >> 12) - 600;
    pos[1] = M2C_FIELD(arg1, s32 *, 0x28) + dy;
}


void func_8013DF10(void *arg0, void *arg1) {
    func_8013DDAC(arg0, arg1);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
}

void VectorNormalSS(SVECTOR *, SVECTOR *);

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013DF60(a, b)
    void *a;
    void *b;
{
    SVECTOR d;
    s32 dx = M2C_FIELD(a, s32 *, 0x24) - M2C_FIELD(b, s32 *, 0x24);
    s32 dz = M2C_FIELD(a, s32 *, 0x2C) - M2C_FIELD(b, s32 *, 0x2C);

    d.vy = 0;
    d.vx = dx;
    d.vz = dz;
    VectorNormalSS(&d, &d);
    return (d.vx * M2C_FIELD(b, s16 *, 0xC2) + d.vz * M2C_FIELD(b, s16 *, 0xC6)) / 4096 >= 0xF77;
}


void func_8013DFF4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x72) = 2;
    M2C_FIELD(arg0, s8 *, 0x7D) = 0x46;
    func_8013D8F0(arg0, 1);
    func_8013DA44(arg0);
}

void func_8013E034(void *arg0) {
    s32 temp_v0;
    u8 temp_v0_2;

    temp_v0 = func_8013DF60();
    if (temp_v0 != 0) {
        D_80140CF8 = (s32) M2C_FIELD(arg0, u8 *, 0x70);
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x7D);
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, u8 *, 0x7D) = (u8) (temp_v0_2 - 1);
        return;
    }
    if (temp_v0 != 0) {
        func_8013DFF4(arg0);
    }
}

s32 Math_Atan2(s32, s32);
s32 rcos(s32);
s32 rsin(s32);

void func_8013E098(u8 *a, s16 x, s16 z) {
    s32 cur = Math_Atan2(M2C_FIELD(a, s16 *, 0x60), M2C_FIELD(a, s16 *, 0x64));
    s32 tgt = Math_Atan2(x, z);
    s32 d;
    s32 t;
    s32 ad;
    s32 s;
    s32 step;

    t = cur - 0x3000;
    d = (tgt - t) % 0x1000;
    if (d != 0) {
        s = (d > 0) ? 1 : -1;
        ad = ABS(d);
        if (ad > 0x800) {
            ad = 0x1000 - ad;
            s = -s;
        }
        step = 0x5B;
        if (ad < step) {
            step = ad;
        }
        cur = (cur + s * step + 0x1000) % 0x1000;
        M2C_FIELD(a, s16 *, 0x60) = rcos(cur);
        M2C_FIELD(a, s16 *, 0x64) = rsin(cur);
    }
}

extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[6]; u16 f_2C; } g_Spike_8013E1A4 asm("g_Spike");

void func_8013E1A4(u8 *e) {
    s32 d = D_800EC208 - M2C_FIELD(e, s32 *, 0x28) - 0x32;

    if (ABS(d) > 12) {
        if (d > 0) {
            M2C_FIELD(e, s32 *, 0x28) += 12;
        } else if (d < 0) {
            M2C_FIELD(e, s32 *, 0x28) -= 12;
        }
    }
    func_8013E098(e, g_Spike_8013E1A4.f_24 - M2C_FIELD(e, u16 *, 0x24), g_Spike_8013E1A4.f_2C - M2C_FIELD(e, u16 *, 0x2C));
    M2C_FIELD(e, s32 *, 0x24) += (M2C_FIELD(e, s16 *, 0x60) * 5) >> 9;
    M2C_FIELD(e, s32 *, 0x2C) += (M2C_FIELD(e, s16 *, 0x64) * 5) >> 9;
}

void func_8013E27C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x73) = 0;
    if (M2C_FIELD(arg0, s8 *, 0x7A) != 0) {
        Collision_Remove(arg0 + 0x24);
        func_8007CDC4(arg0 + 0x1C);
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
}

void func_8013E2C4(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7A) == 0) {
        Collision_Set(4, arg0 + 0x24, arg0);
        func_8007CD88(arg0 + 0x1C);
        M2C_FIELD(arg0, s8 *, 0x7A) = 1;
    }
}

typedef struct { u8 b[0x84]; } O_8013E310;
extern O_8013E310 D_80140A60_8013E310[] asm("D_80140A60");

void func_8013E310(s32 arg0) {
    u8 idx = arg0;
    s32 j = D_80140CF8;
    s32 n;
    u8 *o;

    if (idx == D_80140CF4 - 1) {
        return;
    }
    if (idx >= j) {
        j = idx + 1;
    }
    for (n = D_80140CF4 - 1; idx < n; n--) {
        o = D_80140A60_8013E310[j].b;
        if (o[0x73] != 0 && o[0x72] == 1) {
            o[0x7D] = 0;
            return;
        }
        if (++j >= D_80140CF4) {
            j = idx + 1;
        }
    }
}

s32 Object_AddAttackSphere(void *, s32, s16, s16, s32, s32, s32);

void func_8013E3B8(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(0x102, &v);
    Sound_PlayFixed(0x6E);
    Object_AddAttackSphere(arg0, 0x12C, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, u16 *, 0x1E) - 0x64,
                           M2C_FIELD(arg0, s16 *, 0x20), 0x201, 0x201);
    func_8013E27C(arg0);
    func_8013DA84(arg0);
}

void func_800573A0(void *, s32, s32, s32);

void func_8013E44C(void *arg0) {
    u32 s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;

    if (s == 0xB) {
        func_800573A0(arg0, 0, 0, 0);
        Sound_PlayFixed(0x5F);
        Sound_PlayFixed(0x15);
        func_8013E27C(arg0);
        func_8013E310(M2C_FIELD(arg0, u8 *, 0x70));
        func_8013D2D0((u8 *)arg0 + 0x24);
        func_8013DA84(arg0);
    } else if (s == 1) {
        func_8013E3B8(arg0);
    }
}

void func_8013DF10(void *arg0, void *arg1);
void func_8013E44C(void *arg0);
void func_8013E034(void *arg0);
void func_8013E3B8(void *arg0);
void func_8013DD64(void *arg0);
void func_8013DCC4(void *arg0);
s32 func_80051410(void *, s32, s32);

void func_8013E4E0(void *arg0) {
    s32 i;
    u8 *o;

    for (i = D_80140CF4 - 1; i >= 0; i--) {
        o = D_80140A60[i].b;
        if (M2C_FIELD(o, u8 *, 0x73) == 0) {
            continue;
        }
        switch (M2C_FIELD(o, u8 *, 0x72)) {
        case 1:
            func_8013DF10(o, arg0);
            func_8013E44C(o);
            ((void (*)(void *, void *))func_8013E034)(o, arg0);
            break;
        case 2:
            if (M2C_FIELD(o, u8 *, 0x7D) != 0) {
                M2C_FIELD(o, u8 *, 0x7D)--;
            } else {
                func_8013E3B8(o);
            }
            if (M2C_FIELD(o, u16 *, 0x5C) == ((u16 *)(M2C_FIELD(o, u8 *, 0x71) * 4 + M2C_FIELD(o, u8 **, 0x74)))[1]) {
                M2C_FIELD(o, u16 *, 0x5C)--;
            }
            func_8013E1A4(o);
            func_8013E44C(o);
            break;
        }
        func_8013DD64(o);
        if (M2C_FIELD(o, u8 *, 0x73) != 0 && func_80051410(o + 0x24, 0, 0) == 0) {
            func_8013DAC8(o, M2C_FIELD(o, u8 *, 0x73), o + 0x7C);
            if (M2C_FIELD(o, u8 *, 0x72) == 2) {
                func_8013DCC4(o);
            }
        }
    }
}

void func_8013D8F0(void *arg0, s32 a);
void func_8013E2C4(void *arg0);

void func_8013E650(s32 arg0, s32 arg1) {
    SVECTOR v;
    s32 q;
    u8 *o;

    q = arg1 / 5;
    arg1 = 5 - arg1 % 5;
    o = D_80140A60[q].b;
    M2C_FIELD(o, u8 *, 0x73) = arg1;
    M2C_FIELD(o, u8 *, 0x72) = 1;
    func_8013D8F0(o, 0);
    if (arg1 == 5) {
        v.vx = M2C_FIELD(o, u16 *, 0x24);
        v.vy = M2C_FIELD(o, u16 *, 0x28);
        v.vz = M2C_FIELD(o, u16 *, 0x2C);
        Effect_SpawnAt(5, &v);
        func_8013E2C4(o);
        M2C_FIELD(o, u8 *, 0x7D) = q * 51;
    }
}

typedef struct { u8 b[0x84]; } O_8013E730;
extern O_8013E730 D_80140A60_8013E730[] asm("D_80140A60");

void func_8013E730(void) {
    s32 i;
    u8 *o;

    for (i = D_80140CF4 - 1; i >= 0; i--) {
        o = D_80140A60_8013E730[i].b;
        if (M2C_FIELD(o, u8 *, 0x73) != 0) {
            func_8013E3B8(o);
        }
    }
}

void func_8013E7A0(void) {
    Link_SendEvent(6, 0, 0);
}

void func_8013E7C8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x38;
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 4;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x10);
}

void func_8013E7F0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 6;
    M2C_FIELD(arg0, u8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
}

void func_8013E814(void *arg0)
{
  s8 *new_var;
  u16 new_var2;
  *((u8 *) (((s8 *) arg0) + 0x80)) = 3;
  *((u8 *) (((s8 *) arg0) + 0x7F)) = 5;
  new_var2 = *((u16 *) ((new_var = (s8 *) (*((u8 **) (((s8 *) arg0) + 0x88)))) + 0x14));
  D_80140D40 = 0;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var2;
}

void func_8013E83C(void *arg0) {
    func_80056BC4(0x39, 0, M2C_FIELD(arg0, s8 *, 0xCB));
}

void func_8013E864(void) {
    Link_SendEvent(0xB, 1, 0);
}

void func_80051E98(void *, s32);
extern M2C_UNK D_80140D00;
extern M2C_UNK D_80140D38;

void func_8013E88C(void *arg0) {
    func_80051E98(arg0, 0);
    Collision_Remove(&D_80140D00);
    func_8007CDC4(&D_80140D38);
    func_8013E730();
}

extern u32 D_80140D2C;
extern s32 D_80140D44;
void func_800525E0();
void func_8013E7C8(void *arg0);
void func_8013E83C(void *arg0);
void func_8013E88C(void *arg0);

void func_8013E8CC(u8 *e) {
    u32 hit;
    u32 kind;

    if (D_80140D40 != 0) {
        hit = D_80140D2C;
        kind = hit >> 28;
        if (kind == 0xB) {
            M2C_FIELD(e, u32 *, 0x50) = hit;
            func_800525E0(e);
            func_80052864(e);
            Object_PlaySound((s32)e, 0xAD);
            M2C_FIELD(e, u32 *, 0x50) = 0;
            if (e[0x81] < 13) {
                D_80140CF4 = 5;
            }
            if (e[0x81] == 0) {
                e[0x7F] = kind;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[0x16];
            } else if (e[0x80] == 4 || e[0x80] == 5) {
                e[0x7F] = 9;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[0x12];
                e[0xCE] = 10;
            } else if (e[0x80] == 6 || e[0x80] == 7) {
                e[0x7F] = 1;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
                e[0xCE] = 0;
            } else {
                e[0x7F] = 1;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
                e[0xCE] = 4;
            }
            D_80140D40 = 0;
            func_80052038(e, 0xA5);
            goto tick;
        }
    }
    if ((M2C_FIELD(e, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x100000;
        func_80052038(e, 0x56);
        if (e[0x81] == 0) {
            func_8013E83C(e);
            func_8013E88C(e);
        } else if (e[0x80] == 4 || e[0x80] == 5) {
            e[0x80] = 5;
            e[0xC9] = 0;
        } else if (e[0x80] == 6 || e[0x80] == 7) {
            D_80140D44 = 30;
        } else {
            func_8013E7C8(e);
        }
    }
tick:
    if (D_80140D44 != 0) {
        if (--D_80140D44 == 0) {
            D_80140D40 = 1;
        }
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
void Object_DisableCollision(void *);
void Object_EnableCollision(void *);

void func_8013EAD4(u8 *e) {
    if (e[0x8F] != 0) {
        if (--e[0x8F] == 0) {
            Object_EnableCollision(e);
        }
    } else if (Object_DetachLink(e, 0) == 6) {
        Object_PlaySound((s32)e, 0x1C);
        e[0x8F] = 0x1E;
        e[0x80] = 7;
        M2C_FIELD(e, s16 *, 0xB0) = 0x38;
        e[0xC9] = 0x14;
        Object_DisableCollision(e);
    } else if ((u8)(e[0x80] - 6) < 2) {
        M2C_FIELD(e, s32 *, 0xB4) = Object_AddAttackSphereNear(e, 0x10E, M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, u16 *, 0x28) - 0xA0, M2C_FIELD(e, s16 *, 0x2C), 1, 0x203);
    }
}

s32 rcos_8013EBC0(s32) asm("rcos");
s32 rsin_8013EBC0(s32) asm("rsin");

void func_8013EBC0(void *arg0) {
    s32 a = (M2C_FIELD(arg0, s16 *, 0xAC) + 0xC00) % 4096;

    M2C_FIELD(arg0, s16 *, 0xC2) = rcos_8013EBC0(a);
    M2C_FIELD(arg0, s16 *, 0xC6) = rsin_8013EBC0(a);
}

extern struct { s32 x, y, z; } D_80140D00_8013EC24 asm("D_80140D00");
extern struct { s16 x, y, z; } D_80140D38_8013EC24 asm("D_80140D38");

void func_8013EC24(void *arg0) {
    D_80140D00_8013EC24.x = M2C_FIELD(arg0, s32 *, 0x24);
    D_80140D00_8013EC24.y = M2C_FIELD(arg0, s32 *, 0x28) - 0x1A4;
    D_80140D00_8013EC24.z = M2C_FIELD(arg0, s32 *, 0x2C);
    D_80140D38_8013EC24.x = D_80140D00_8013EC24.x;
    D_80140D38_8013EC24.y = D_80140D00_8013EC24.y - 0xB4;
    D_80140D38_8013EC24.z = D_80140D00_8013EC24.z;
}

s32 func_8013D280(void);
void func_8013E864(void);
void Object_StepOrbitAngle(void *, s16);
s32 Object_WouldLeaveHome(void *, s16);

s32 func_8013EC70(u8 *arg0) {
    s32 d;

    if (func_8013D280()) {
        func_8013E88C(arg0);
        return 1;
    }
    if (M2C_FIELD(arg0, u8 *, 0x82) != 0) {
        d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        if (Object_WouldLeaveHome(arg0, 0)) {
            M2C_FIELD(arg0, s16 *, 0x94) = 0;
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
        }
        func_8013EC24(arg0);
        Object_StepOrbitAngle(arg0, 0x1C);
        func_8013EBC0(arg0);
        func_8013E4E0(arg0);
        if (M2C_FIELD(arg0, u8 *, 0x81) == 0 && d == 0x20) {
            func_8013E864();
            M2C_FIELD(arg0, u8 *, 0xC8) = 0;
            return 1;
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013ED4C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EE4C);

void func_8013F37C(u8 *e) {
    if (e[0x8F] != 0) {
        if (--e[0x8F] == 0) {
            Object_EnableCollision(e);
        }
    } else if (Object_DetachLink(e, 0) == 6) {
        Object_PlaySound((s32)e, 0x1C);
        e[0x8F] = 0x1E;
        Object_DisableCollision(e);
        e[0xC9] = 0;
    } else if (e[0x7F] == 1) {
        M2C_FIELD(e, s32 *, 0xB4) = Object_AddAttackSphereNear(e, 0xC8, M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, u16 *, 0x28) - 0xA0, M2C_FIELD(e, s16 *, 0x2C), 0xA01, 0x101);
    }
}

void func_8013F450(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(5, &v);
}

void func_8013F490(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void func_8013F4D4(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) != -1) {
        func_8013F490(arg0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(arg1 | 0x7000, 0x1000, arg0 + 0x24);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F528);

void func_80052038(void *, s32);

void func_8013F5F8(void *arg0)
{
  u8 *a = *((u8 **) (((s8 *) arg0) + 0x88));
  u16 new_var;
  *((u8 *) (((s8 *) arg0) + 0x80)) = 3;
  *((u8 *) (((s8 *) arg0) + 0x7F)) = 4;
  new_var = *((u16 *) (((s8 *) a) + 0x10));
  D_80140D40 = 0;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var;
  func_80052038(arg0, 0x56);
  func_8013F490(arg0);
}

void func_8013F64C(void *arg0) {
    if ((D_80140D40 != 0) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0)) {
        func_800525A0(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        func_8013F5F8(arg0);
        D_80140D40 = 0;
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
        M2C_FIELD(arg0, s8 *, 0x84) = 0x14;
        func_80052864(arg0);
        func_8013D180(arg0, 0, 0, 0);
    }
}

extern s32 g_Game_8013F6FC asm("g_Game");
extern u32 D_801409FC_8013F6FC asm("D_801409FC");

void func_8013F6FC(u8 *a) {
    SVECTOR v;

    v.vx = M2C_FIELD(a, u16 *, 0x24) - ((M2C_FIELD(a, s16 *, 0x60) * 125) >> 11);
    v.vy = M2C_FIELD(a, u16 *, 0x28) - 200;
    v.vz = M2C_FIELD(a, u16 *, 0x2C) - ((M2C_FIELD(a, s16 *, 0x64) * 125) >> 11);
    if ((g_Game_8013F6FC & 3) == 0) {
        Effect_Spawn(0xC8, &v.vx, &D_801409FC_8013F6FC, 0);
    } else if ((g_Game_8013F6FC & 3) == 2) {
        Effect_Spawn(0xC9, &v.vx, &D_801409FC_8013F6FC, 0);
    }
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F7A8);

s32 func_800569C4(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Objects;

void func_8013FE04(void) {
    s32 temp_v0;

    temp_v0 = func_800569C4(0x22, 1);
    if (temp_v0 != -1) {
        func_80051E98((u8 *)&g_Objects + (temp_v0 * 0xE4), 0);
    }
}

s32 func_8013FE5C(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(D_80140D4C, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(D_80140D4C, s32 *, 0x2C);
    temp_a1 = arg1 + 0x800;
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < (temp_a1 * temp_a1);
}

void func_8013FEB0(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Effect_SpawnAt(4, &v);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013FEF0);

s32 Math_Atan2(s32, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_8013FEF0(void *);
void func_80055F1C(void *, s32);

void func_8013FF58(void *arg0) {
    s32 temp_v1;
    s32 var_v0;

    M2C_FIELD(arg0, s16 *, 0xA6) = (s16) (M2C_FIELD(D_80140D4C, u16 *, 0xA6) - 0x200);
    M2C_FIELD(arg0, u16 *, 0x9A) = (u16) M2C_FIELD(D_80140D4C, u16 *, 0x9A);
    M2C_FIELD(arg0, u16 *, 0x9E) = (u16) M2C_FIELD(D_80140D4C, u16 *, 0x9E);
    func_80055F1C(arg0, 0x28);
    func_8013FEF0(arg0);
    var_v0 = Math_Atan2(M2C_FIELD(arg0, s32 *, 0x24) - (s16) M2C_FIELD(D_80140D4C, u16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x2C) - (s16) M2C_FIELD(D_80140D4C, u16 *, 0x9E));
    temp_v1 = var_v0;
    if (temp_v1 < 0) {
        var_v0 = temp_v1 + 0xFFF;
    }
    M2C_FIELD(arg0, s16 *, 0xAA) = (s16) (temp_v1 - ((var_v0 >> 0xC) << 0xC));
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
    func_8005588C(arg0, 0x14);
}

extern s32 D_80140D50;

void func_8014001C(void *arg0)
{
  u16 new_var;
  int new_var2;
  s8 *new_var3;
  if (D_80140D50 != 0)
  {
    func_8013FF58(arg0);
    *((u8 *) (((s8 *) arg0) + 0x7F)) = 1;
    new_var = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x88)))) + 4));
    D_80140D50 = 0;
    new_var2 = 0x5C;
    new_var3 = ((s8 *) arg0) + new_var2;
    *((u16 *) new_var3) = new_var;
  }
}

typedef struct { u16 start; u16 end; } Rng_80140070;
typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x18]; s16 f44; u8 pad46[0x16]; u16 f5C; u8 pad5E[0x21]; u8 f7F; u8 f80; u8 pad81[7]; Rng_80140070 *rng; u8 pad8C[0x14]; s16 fA0; u8 padA2[0xE]; s16 fB0; u8 padB2[0x16]; u8 fC8; u8 padC9[0x17]; u32 fE0; } O_80140070;
extern s32 D_80140D48;
M2C_UNK func_80058134(void *, s16);
void Object_TurnTowardSpike(void *);
s32 func_8013FE5C(void *arg0, s32 arg1);
M2C_UNK func_80055E6C(void *, M2C_UNK);
M2C_UNK Object_StepOnGroundFixed(void *);
void func_8013FEB0(void *arg0);
void func_8013FF58(void *arg0);

void func_80140070(O_80140070 *o) {
    s32 d;
    s32 s;

    if (!(o->fE0 >> 3 & 1)) {
        o->fA0 = 100;
        o->fB0 = 0xB6;
        o->f80 = 1;
        o->f7F = 0;
        o->fE0 &= ~0x1000;
        o->f5C = o->rng[0].start;
        D_80140D50 = 0;
        o->fE0 |= 8;
    }
    d = D_800EC208 - o->y;
    if (d >= 0) {
        if (d < 0x600) {
            o->fC8 = 10;
        } else {
            o->fC8 = 0;
        }
    } else if (o->y - D_800EC208 < 0x600) {
        o->fC8 = 10;
    } else {
        o->fC8 = 0;
    }
    if (func_8013D280()) {
        func_80051E98(o, 0);
        return;
    }
    func_80058134(o, o->f44);
    func_8014001C(o);
    switch (s = o->f80) {
    case 1:
        Object_TurnTowardSpike(o);
        if (D_80140D48 != 0) {
            goto f58;
        }
        break;
    case 2:
        Object_TurnTowardSpike(o);
        if (func_8005588C(o, -1) == 0 && func_8013FE5C(o, 0)) {
            o->f80 = 3;
            o->f7F = s;
            o->f5C = o->rng[2].start;
        }
        break;
    case 3:
        if (func_8013FE5C(o, 300)) {
            func_8013FEF0(o);
            func_80055E6C(o, 0x28);
            Object_StepOnGroundFixed(o);
            func_8013FEB0(o);
        } else {
        f58:
            func_8013FF58(o);
        }
        break;
    }
}

s32 func_80140264(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

extern struct { u8 pad_0[0x8120]; u16 f_8120; } g_Game_80140278 asm("g_Game");
extern s32 D_800EC20C;
s32 Overlay_GetState(void);
void Overlay_Request(s8);
s32 Sound_UnloadBanks(s32);
s32 func_800863B0(s32, s32);
void func_8008745C(void);

s32 func_80140278(s16 *p) {
    if (g_Game_80140278.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        if (D_800EC20C < -0x7FF) {
            return 0;
        }
        p[1] = 1;
        p[3] = 0;
        func_800863B0(2, 0x28);
        Overlay_Request(2);
        return 0;
    case 1:
        if (Overlay_GetState() != 0) {
            return 0;
        }
        func_800863B0(0, 0);
        p[1] = 3;
        p[7] = 0;
        break;
    case 2:
        if (D_800EC20C < -0x7FF) {
            return 0;
        }
        p[1] = 3;
        p[7] = 0;
        break;
    case 3:
        if (p[7] != 0) {
            p[1] = 4;
            Sound_UnloadBanks(2);
            Overlay_Request(3);
            return 0;
        }
        break;
    case 4:
        if (Overlay_GetState() != 0) {
            return 0;
        }
        p[1] = 5;
        func_8008745C();
        break;
    case 5:
        break;
    }
    return 0;
}

s32 func_801403BC(void) {
    return 0;
}

s32 func_801403C4(void) {
    return 0;
}

s32 func_801403CC(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_801403DC;
extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0xEA]; u8 *f_820C; u8 pad_8210[0x10]; S18_801403DC *f_8220; } g_Game_801403DC asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801403DC asm("g_Spike");
extern u8 *D_800B4D64;
void Camera_StartShake(s32);
void Pad_Vibrate(s32, s32, s32);
void Fx_Explosion(s16 *, s32, s32);
s32 Vec_Length(s32, s32, s32);

s32 func_801403DC(s16 *p) {
    u8 *e;
    SVECTOR unused;

    if (g_Game_801403DC.f_8220->f_2 == 5) {
        return 0;
    }
    if (g_Game_801403DC.f_8120 == 0x13) {
        return 0;
    }
    e = g_Game_801403DC.f_820C + p[2] * 0x38;
    switch (p[1]) {
    case 0:
        break;
    case 1:
        p[1] = 3;
        Camera_StartShake(0);
        Pad_Vibrate(0, 1, 3);
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            Fx_Explosion((s16 *)e, M2C_FIELD(e, s16 *, 0xE), 1);
        }
        break;
    case 2:
        if (Vec_Length(g_Spike_801403DC.x, g_Spike_801403DC.y + 0xA00, g_Spike_801403DC.z - 0xD00) < 0x9D0 && g_Spike_801403DC.y >= -0xC2F) {
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            p[1] = 3;
        }
        break;
    }
    return 0;
}

s32 func_80140564(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

s32 SquareRoot0(s32 a);
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140574 asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x16]; s16 f46; } g_Spike_80140574 asm("g_Spike");
s32 func_80140710(s16 a, s16 b);
s32 func_801407AC(s16 a, s16 b);

s32 func_80140574(s16 *p) {
    s16 *e;
    s32 dx, dz;

    switch (p[1]) {
    case 0:
        e = (s16 *)(g_Game_80140574.f_820C + p[2] * 0x38);
        dx = g_Spike_80140574.x - e[0];
        dz = g_Spike_80140574.z - e[2];
        if ((u32)SquareRoot0(dx * dx + dz * dz) < e[3]) {
            if (g_Spike_80140574.y - g_Spike_80140574.f46 > e[1] - e[4]) {
                func_80140710(p[4], p[5]);
                p[1] = 1;
            }
        }
        break;
    case 1:
        e = (s16 *)(g_Game_80140574.f_820C + p[2] * 0x38);
        dx = g_Spike_80140574.x - e[0];
        dz = g_Spike_80140574.z - e[2];
        if ((u32)SquareRoot0(dx * dx + dz * dz) > e[3]) {
            func_801407AC(p[4], p[5]);
            p[1] = 0;
        }
        break;
    }
    return 0;
}

extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game;

s32 func_80140710(s16 a, s16 b) {
    u8 *e;

    if (b >= 0) {
        e = g_Game.f_820C + b * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    if (a < 0) {
        return 0;
    }
    func_80140710(M2C_FIELD(g_Game.f_8220 + a * 0x18, s16 *, 8), M2C_FIELD(g_Game.f_8220 + a * 0x18, s16 *, 0xA));
    return 0;
}

s32 func_801407AC(s16 a, s16 b) {
    u8 *e;

    if (b >= 0) {
        e = g_Game.f_820C + b * 0x38;
        M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
    }
    if (a < 0) {
        return 0;
    }
    func_801407AC(M2C_FIELD(g_Game.f_8220 + a * 0x18, s16 *, 8), M2C_FIELD(g_Game.f_8220 + a * 0x18, s16 *, 0xA));
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
