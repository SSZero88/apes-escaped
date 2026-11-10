#include "common.h"
#include "m2c_macros.h"

M2C_UNK VectorNormalSS(void *, void *);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
s32 Object_IsFacingDir(void *, M2C_UNK, M2C_UNK, s16, s32);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
extern s32 g_Game;
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013D000;
extern struct { s16 f0; u8 pad2[6]; s16 f8; s16 fA; s16 fC; } D_800E68C0_8013D000 asm("D_800E68C0");
extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike_8013D000 asm("g_Spike");
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
s32 rcos_8013D000(s32) asm("rcos");
s32 rsin_8013D000(s32) asm("rsin");

void func_8013D000(void *arg0) {
    SVECTOR v;
    s32 t;
    s32 a;
    Scr_8013D000 *sc = (Scr_8013D000 *)0x1F800000;

    sc->spike.vx = g_Spike_8013D000.f_24;
    sc->spike.vy = g_Spike_8013D000.f_28;
    sc->spike.vz = g_Spike_8013D000.f_2C;
    func_8004B8F4(arg0, 2, &v);
    t = D_800E68C0_8013D000.f0 - sc->spike.vx + D_800E68C0_8013D000.f8;
    v.vy += D_800E68C0_8013D000.fA;
    if (D_800E68C0_8013D000.f8 * 2 < t) {
        t = D_800E68C0_8013D000.f8 * 2 - 1;
    } else if (t < 0) {
        t = 0;
    }
    a = (t << 11) / (D_800E68C0_8013D000.f8 * 2);
    sc->eye.vx = v.vx + ((rcos_8013D000(a) * D_800E68C0_8013D000.f8 / 8) >> 12);
    sc->eye.vz = v.vz - ((rsin_8013D000(a) * D_800E68C0_8013D000.fC / 8) >> 12);
    sc->eye.vx = g_Spike_8013D000.f_24;
    sc->eye.vz = g_Spike_8013D000.f_2C;
    sc->eye.vy = v.vy - 0x1EA;
    func_80047558(arg0, 4, 4, 4);
    sc->at.vx = v.vx + ((rcos_8013D000(a) * D_800E68C0_8013D000.f8) >> 12);
    sc->at.vz = v.vz - ((rsin_8013D000(a) * D_800E68C0_8013D000.fC) >> 12);
    sc->at.vy = v.vy - 0x400;
    func_80047464(arg0, 4, 4, 4);
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013D20C;
extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike_8013D20C asm("g_Spike");
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013D20C;
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
void Matrix_SetIdentity(void *);
void RotMatrixY(s32, void *);
void ApplyMatrixSV(void *, void *, void *);
void VectorNormalSS_8013D20C(void *, void *) asm("VectorNormalSS");

void func_8013D20C(void *arg0) {
    SVECTOR v;
    SVECTOR d;
    Mat_8013D20C m;
    s32 k;
    s32 t;
    s32 u;

    ((Scr_8013D20C *)0x1F800000)->spike.vx = g_Spike_8013D20C.f_24;
    ((Scr_8013D20C *)0x1F800000)->spike.vy = g_Spike_8013D20C.f_28;
    ((Scr_8013D20C *)0x1F800000)->spike.vz = g_Spike_8013D20C.f_2C;
    func_8004B8F4(arg0, 2, &v);
    d.vy = 0;
    d.vx = ((Scr_8013D20C *)0x1F800000)->spike.vz - v.vz;
    d.vz = v.vx - ((Scr_8013D20C *)0x1F800000)->spike.vx;
    VectorNormalSS_8013D20C(&d, &d);
    Matrix_SetIdentity(&m);
    RotMatrixY(0x5B, &m);
    ApplyMatrixSV(&m, &d, &d);
    k = 0x514;
    t = (d.vx * k) >> 12;
    u = (d.vz * k) >> 12;
    ((Scr_8013D20C *)0x1F800000)->eye.vx = ((Scr_8013D20C *)0x1F800000)->spike.vx + t;
    ((Scr_8013D20C *)0x1F800000)->eye.vy = ((Scr_8013D20C *)0x1F800000)->spike.vy + 0x100;
    ((Scr_8013D20C *)0x1F800000)->eye.vz = ((Scr_8013D20C *)0x1F800000)->spike.vz + u;
    ((Scr_8013D20C *)0x1F800000)->at.vx = ((Scr_8013D20C *)0x1F800000)->spike.vx - t;
    ((Scr_8013D20C *)0x1F800000)->at.vy = ((Scr_8013D20C *)0x1F800000)->spike.vy - 0x3E8;
    ((Scr_8013D20C *)0x1F800000)->at.vz = ((Scr_8013D20C *)0x1F800000)->spike.vz - u;
    func_80047558(arg0, 2, 0x10, 2);
    func_80047464(arg0, 2, 0x10, 2);
}

extern u8 D_80141B54[];
void func_80070284(SVECTOR *, void *, s32, s32, SVECTOR *);
void Effect_SpawnAt(s32, SVECTOR *);

void func_8013D358(s16 x, s16 y, s16 z) {
    SVECTOR v;
    SVECTOR d;

    v.vx = x;
    v.vy = y - 0x80;
    v.vz = z;
    d.vz = -0x1000;
    d.vx = 0;
    d.vy = 0;
    func_80070284(&v, D_80141B54, 1, 4, &d);
    Effect_SpawnAt(0x112, &v);
}

extern u8 D_80141B00[];
s32 Floor_GetHeight_8013D3BC(s16, s16, s16) asm("Floor_GetHeight");
extern u16 g_RandSeed;

void func_8013D3BC(s16 x, s16 y, s16 z) {
    SVECTOR v;
    s16 h;
    s32 i;

    h = Floor_GetHeight_8013D3BC(x, y, z) - 0x10;
    v.vx = x;
    v.vy = h;
    v.vz = z;
    func_80070284(&v, D_80141B00, 1, 4, 0);
    for (i = 24; i >= 0; i--) {
        v.vx = x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2;
        v.vy = h + ((g_RandSeed = g_RandSeed * 5 + 1) >> 11);
        v.vz = z + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2;
        Effect_SpawnAt(0x16, &v);
    }
}

void func_8006D568(void *);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);

void func_8013D4F0(void *arg0) {
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

void func_8013D5C0(void *arg0) {
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

s32 func_8013D6BC(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_8013D6F0(void *arg0) {
    if (func_8013D6BC(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8013D744(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_8013D630;
void func_80054220(void *);
void func_8013D4F0(void *arg0);
void func_8013D5C0(void *arg0);
void func_8013D6F0(void *arg0);
void func_8013D744(void *arg0);

void func_8013D7AC(u8 *e) {
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
    func_8013D744(e);
    switch (e[0x80]) {
    case 1:
        if (e[0xC9] == 0) {
            func_8013D6F0(e);
        }
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            if (e[0xC9] != 0) {
                e[0xC9]--;
            }
        }
        break;
    case 2:
        func_8013D5C0(e);
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
    func_8013D4F0(e);
    func_80054220(e);
}

void func_8013D98C(void *arg0) {
    Object_AddAttackSphereNear(arg0, 0x12C, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, u16 *, 0x28) - 0x12C,
                               M2C_FIELD(arg0, s16 *, 0x2C), 0xA01, 0x200);
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 2; u32 b6 : 1; u32 b7 : 5; u32 b12 : 1; u32 b13 : 19; } Flags_8013D9D8;
typedef struct { u16 start; u16 end; } Rng_8013D9D8;
extern struct { u8 pad0; u8 f_1; } D_800E77A0_8013D9D8 asm("D_800E77A0");
void func_80058134(void *, s32);
void Object_PlaceAtPathPoint(void *, s32);
void func_8005866C(void *, s32);
void func_800585D0(void *, s32, s32, s32);
void Object_ApplyVelocity(void *);
s32 func_8005588C(void *, s32);
void func_80051E98(void *, s32);
void func_8013D98C(void *arg0);

void func_8013D9D8(u8 *o) {
    s32 st;

    if (!M2C_FIELD(o, Flags_8013D9D8 *, 0xE0).init) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x190;
        M2C_FIELD(o, Flags_8013D9D8 *, 0xE0).b12 = 0;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, u8 *, 0x8F) = 0;
        M2C_FIELD(o, s16 *, 0x44) = 1;
        M2C_FIELD(o, s16 *, 0x46) = 0x320;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0xAA) = 0;
        M2C_FIELD(o, u8 *, 0x8E) = 1;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        Object_PlaceAtPathPoint(o, 0);
        func_8005866C(o, 1);
        M2C_FIELD(o, s16 *, 0x9C) = M2C_FIELD(o, s32 *, 0x28);
        M2C_FIELD(o, s16 *, 0x96) = 100;
        M2C_FIELD(o, s32 *, 0x28) += 1000;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D9D8 **, 0x88)[0].start;
        M2C_FIELD(o, Flags_8013D9D8 *, 0xE0).init = 1;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    switch (st = M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, s16 *, 0x96) -= 7;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        if (M2C_FIELD(o, s32 *, 0x28) <= M2C_FIELD(o, s16 *, 0x9C)) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = st;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D9D8 **, 0x88)[1].start;
        }
        func_8013D98C(o);
        break;
    case 2:
        func_8013D98C(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013D9D8 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            M2C_FIELD(o, s8 *, 0x7C) = Sound_ReserveSlot(0x707C, 0x1000, o + 0x24);
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = st;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013D9D8 **, 0x88)[2].start;
        }
        break;
    case 3:
        func_800585D0(o, 0x28, 0, 1);
        if (M2C_FIELD(o, u8 *, 0x8E) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, s16 *, 0x96) = 0;
            M2C_FIELD(o, s16 *, 0xAE) = 0;
            func_8005588C(o, 0x14);
        } else {
            Object_ApplyVelocity(o);
        }
        func_8013D98C(o);
        break;
    case 4:
        M2C_FIELD(o, s16 *, 0x96) += 8;
        Object_ApplyVelocity(o);
        if (!func_8005588C(o, -1)) {
            func_80088120(M2C_FIELD(o, s8 *, 0x7C));
            D_800E77A0_8013D9D8.f_1--;
            func_80051E98(o, 0);
        }
        break;
    }
}

typedef struct { u16 start; u16 end; } Rng_8013DC64;
extern struct { u8 pad0; u8 f_1; } D_800E77A0_8013DC64 asm("D_800E77A0");
s32 Object_DetachLink_8013DC64(void *, s32) asm("Object_DetachLink");
M2C_UNK Object_DisableCollision();
void func_80058134(void *, s32);
void Object_EnableCollision(void *);
M2C_UNK func_80051E98_8013DC64(void *, M2C_UNK) asm("func_80051E98");
void func_8013D3BC(s16 x, s16 y, s16 z);

void func_8013DC64(u8 *o) {

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(o, s16 *, 0x44) = 200;
        M2C_FIELD(o, s16 *, 0xA0) = 200;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013DC64 **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013DC64 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013DC64 **, 0x88)[1].start;
            Object_PlaySound(o, 0x79);
            M2C_FIELD(o, u32 *, 0xE0) &= ~1;
            M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphereNear(o, 250, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C), 0xA01, 0x203);
            func_8013D3BC(M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C));
        }
        break;
    case 2:
        if (Object_DetachLink_8013DC64(o, 0) == 6) {
            M2C_FIELD(o, u32 *, 0xE0) |= 1;
        }
        if (!(M2C_FIELD(o, u32 *, 0xE0) & 1)) {
            if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, Rng_8013DC64 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].start + 1) {
                M2C_FIELD(o, u32 *, 0xE0) |= 0x4002;
                Object_EnableCollision(o);
            } else if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, Rng_8013DC64 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].start + 0x2A) {
                Object_DisableCollision(o);
                M2C_FIELD(o, u32 *, 0xE0) &= ~0x4000;
                M2C_FIELD(o, u32 *, 0xE0) &= ~2;
            }
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013DC64 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
            func_80051E98_8013DC64(o, 0);
            D_800E77A0_8013DC64.f_1--;
        }
        break;
    }
}

void func_8013DE8C(u8 *o) {
    if (M2C_FIELD(o, u8 *, 0x7F) == 4) {
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4 + 2)) {
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 8);
        }
    } else if (Spike_WithinRadiusXZ(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 200)) {
        M2C_FIELD(o, u8 *, 0x7F) = 4;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x10);
    }
    Object_AddAttackSphereNear(o, 100, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x1E), M2C_FIELD(o, s16 *, 0x2C), 1, 0x202);
}

s16 func_80058400(void *, u8, s8, s16);

void func_8013DF50(u8 *o) {
    u16 n;

    if (func_80058400(o, M2C_FIELD(o, u8 *, 0x8E), 1, 0x32)) {
        if ((M2C_FIELD(o, u32 *, 0xE0) >> 6) & 1) {
            if (M2C_FIELD(o, u8 *, 0x8E) == 0) {
                M2C_FIELD(o, u8 *, 0x8E)++;
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = 3;
                M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[6];
                return;
            }
            M2C_FIELD(o, u8 *, 0x8E)--;
        } else {
            n = M2C_FIELD(o, u16 *, 0x8C);
            if (M2C_FIELD(o, u8 *, 0x8E) == n - 1) {
                M2C_FIELD(o, u8 *, 0x8E) = n - 2;
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = 3;
                M2C_FIELD(o, u32 *, 0xE0) |= 0x40;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[6];
                return;
            }
            M2C_FIELD(o, u8 *, 0x8E)++;
        }
    }
    Object_ApplyVelocity(o);
}

s32 func_8013E044(void *arg0) {
    s32 var_s0;

    var_s0 = 0;
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x1200) != 0) {
        var_s0 = Object_IsFacingDir(arg0, 0x5A, 0xB50, (s16) (g_Spike.f_24 - (u16) M2C_FIELD(arg0, s32 *, 0x24)), (s32) (s16) (g_Spike.f_2C - (u16) M2C_FIELD(arg0, s32 *, 0x2C))) != 0;
    }
    return var_s0;
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_8013E0D0;
typedef struct { u16 start; u16 end; } Rng_8013E0D0;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x2C]; u16 anim; u16 pad5E; u16 f60; u16 pad62; u16 f64; u8 pad66[0x19]; u8 seg; u8 state; u8 pad81[7]; Rng_8013E0D0 *rng; u8 pad8C[2]; u8 f8E; u8 pad8F; s16 *path; u8 pad94[0xC]; s16 fA0; u8 padA2[0xC]; s16 fAE; s16 fB0; u8 padB2[0x2E]; Flags_8013E0D0 fl; } Obj_8013E0D0;
extern s32 D_80141BA8[];
void Object_TurnToward(void *, s16, s16, s16, s16);
s32 func_8013E044(void *arg0);
void func_8013DE8C(u8 *o);

void func_8013E0D0(u8 *arg0) {
    Obj_8013E0D0 *o = (Obj_8013E0D0 *)arg0;
    if (!o->fl.init) {
        register s16 *pp asm("$2");
        Rng_8013E0D0 *rg;
        rg = o->rng;
        o->fA0 = 0x32;
        o->fB0 = 0x16;
        __asm__ volatile("");
        pp = o->path;
        __asm__("" : : "r"(pp));
        o->f8E = 0;
        o->seg = 0;
        o->anim = rg[0].start;
        o->x = pp[0];
        o->y = pp[1];
        o->z = pp[2];
        { s16 *pp = *(s16 * volatile *)&o->path; Object_TurnToward(o, pp[4] - (u16)o->x, pp[6] - (u16)o->z, 0, o->fB0); }
        o->fl.init = 1;
    }
    switch (o->state) {
    case 1:
        if (func_8013E044(o)) {
            o->state = 2;
            o->seg = 1;
            o->anim = o->rng[1].start;
        }
        break;
    case 2:
        if (o->anim >= o->rng[o->seg].end) {
            o->state = 3;
            o->seg = 2;
            o->anim = o->rng[2].start;
        }
        break;
    case 3:
        func_8013DE8C((u8 *)o);
        func_8013DF50((u8 *)o);
        if (!func_8005588C(o, -1)) {
            Object_PlaySound(o, D_80141BA8[((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1]);
            func_8005588C(o, (((g_RandSeed = g_RandSeed * 5 + 1) >> 11)) + 0x1E);
        }
        break;
    case 4:
        if (o->anim >= o->rng[o->seg].end) {
            o->state = 5;
            o->seg = 0;
            o->anim = o->rng[0].start;
            Object_TurnToward(o, -o->f60, -o->f64, 0, o->fB0);
        }
        break;
    case 5:
        if (o->fAE == 0) {
            o->state = 1;
        }
        break;
    }
}

void func_8013E358(void *arg0) {
    if ((Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x800) != 0) && !(g_Game & 3)) {
        Object_PlaySound(arg0, 0x12);
    }
}

void func_80059304(SVECTOR *, void *, s32, s32);

void func_8013E3AC(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((M2C_FIELD(arg0, s16 *, 0x60) * 65) >> 10);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) + 0x64;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((M2C_FIELD(arg0, s16 *, 0x64) * 65) >> 10);
    func_80059304(&v, arg0, 10, 1);
    Object_PlaySound(arg0, 0x64);
    Effect_SpawnAt(7, &v);
}

s32 func_8013E43C(s32 v, s32 lim) {
    if (__builtin_abs(v) <= lim) {
        return v;
    }
    if (v > 0) {
        return lim;
    }
    return -lim;
}

s32 func_8013E43C(s32 v, s32 lim);

void func_8013E46C(void *pos, void *out, s32 v, s32 lim, s32 step) {
    s16 n;

    n = *(s16 *)pos += func_8013E43C(v, step);
    if (lim < n) {
        *(s16 *)pos = lim;
    } else if (n < -lim) {
        *(s16 *)pos = -lim;
    }
    *(s16 *)out = *(s16 *)pos;
    if (*(s16 *)pos < 0) {
        (*(s16 *)pos)++;
    } else if (*(s16 *)pos > 0) {
        (*(s16 *)pos)--;
    }
}

extern u32 g_Game_8013E51C asm("g_Game");
s32 rsin(s32);

void func_8013E51C(u8 *a, s32 y) {
    s32 s = rsin(((g_Game_8013E51C % 60) << 12) / 60);

    func_8013E46C(a + 0xA8, a + 0x96, y - M2C_FIELD(a, s32 *, 0x28) + ((s * 50) >> 12), 0x14, 4);
}

s32 func_8005588C(void *, s32);

void func_8013E5C4(void *arg0)
{
  u16 new_var3;
  int new_var;
  s8 *new_var2;
  *((s8 *) (((s8 *) arg0) + 0x80)) = 1;
  new_var = 0x3C;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 0;
  new_var3 = (u16) (*(*((u16 **) (((s8 *) arg0) + 0x88))));
  new_var2 = ((s8 *) arg0) + 0xB0;
  *((s16 *) new_var2) = 0x5B;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var3;
  func_8005588C(arg0, new_var);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; } Spike_407;
extern Spike_407 g_Spike_8013E604 asm("g_Spike");
s32 Math_WithinSquare(s32, s32, s32);
s16 Object_FloorAt(void *, s32, s32, s32);

s32 func_8013E604(void *a) {
    Spike_407 *sp;

    if (Math_WithinSquare(M2C_FIELD(a, s32 *, 0x24) - M2C_FIELD(a, s16 *, 0x9A), M2C_FIELD(a, s32 *, 0x2C) - M2C_FIELD(a, s16 *, 0x9E),
                          M2C_FIELD(a, s16 *, 0xA6) + 0x400)) {
        sp = &g_Spike_8013E604;
        if (Object_FloorAt(a, 0, 0, 0) >= sp->y && M2C_FIELD(a, s16 *, 0x9C) < sp->y) {
            return 0;
        }
    }
    func_8013E5C4(a);
    return 1;
}

void func_8013E6A8(s16 *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;

    if (arg2 != 0) {
        if (*arg0 < (arg1 * 8)) {
            *arg0 = (u16) *arg0 + 0xA;
        }
    } else {
        temp_v0 = (u16) *arg0 - 5;
        *arg0 = temp_v0;
        if ((s16) temp_v0 < 0) {
            *arg0 = 0;
        }
    }
}

extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; } g_Spike_8013E6F8 asm("g_Spike");
void func_8013E6A8(s16 *arg0, s32 arg1, s32 arg2);
void Object_TurnToward(void *, s16, s16, s16, s16);
void Object_SetForwardVelocity(void *, s16);

void func_8013E6F8(u8 *o) {
    s32 dx = g_Spike_8013E6F8.x - M2C_FIELD(o, s32 *, 0x24);
    s32 dz = g_Spike_8013E6F8.z - M2C_FIELD(o, s32 *, 0x2C);

    if (dx * dx + dz * dz < 0x9C40) {
        func_8013E6A8((s16 *)(o + 0xC6), 20, 0);
        if (M2C_FIELD(o, u8 *, 0x80) != 5) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            func_8005588C(o, 0x3C);
        }
    } else {
        func_8013E6A8((s16 *)(o + 0xC6), 20, 1);
        Object_TurnToward(o, dx, dz, 0, M2C_FIELD(o, s16 *, 0xB0));
    }
    Object_SetForwardVelocity(o, M2C_FIELD(o, s16 *, 0xC6) >> 3);
}

typedef struct { u16 start; u16 end; } Rng_8013E7E8;
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Spike_8013E7E8;
extern Spike_8013E7E8 g_Spike_8013E7E8 asm("g_Spike");
extern s32 D_800EC208;
void func_80055E6C(void *, s16);
void func_80055F1C(void *, s32);
void Object_ApplyVelocity(void *);
void func_8013E358(void *arg0);
void func_8013E3AC(void *arg0);
void func_8013E51C(u8 *a, s32 y);
s32 func_8013E604(void *a);
void func_8013E6F8(u8 *o);

void func_8013E7E8(u8 *o) {
    Spike_8013E7E8 *sp;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = 0x103;
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0x44) = 0x96;
        M2C_FIELD(o, s16 *, 0x46) = 0x82;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, u8 *, 0xCD) = 2;
        M2C_FIELD(o, u8 *, 0xDC) = 5;
        M2C_FIELD(o, s16 *, 0xA8) = 0;
        func_80055F1C(o, 0xC);
        func_8013E5C4(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013E358(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_80055E6C(o, 0xC);
        func_8013E51C(o, M2C_FIELD(o, s16 *, 0x9C));
        Object_ApplyVelocity(o);
        if (!func_8005588C(o, -1) && Spike_WithinRadiusXZ(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x500)) {
            sp = &g_Spike_8013E7E8;
            if (Object_FloorAt(o, 0, 0, 0) >= sp->y && M2C_FIELD(o, s32 *, 0x28) < sp->y) {
                M2C_FIELD(o, u8 *, 0x80) = 2;
                M2C_FIELD(o, s16 *, 0xC6) = 0;
            }
        }
        break;
    case 2:
        func_8013E6F8(o);
        func_8013E51C(o, D_800EC208 - 0x200);
        Object_ApplyVelocity(o);
        func_8013E604(o);
        break;
    case 5:
        func_8013E6F8(o);
        func_8013E51C(o, D_800EC208 - 0x200);
        Object_ApplyVelocity(o);
        if (!func_8013E604(o) && !func_8005588C(o, -1)) {
            if (M2C_FIELD(o, u8 *, 0x7F) == 1) {
                if (M2C_FIELD(o, u16 *, 0x5C) == M2C_FIELD(o, Rng_8013E7E8 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].start + 0x13) {
                    func_8013E3AC(o);
                }
                if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013E7E8 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
                    func_8013E5C4(o);
                }
            } else if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, Rng_8013E7E8 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end) {
                M2C_FIELD(o, u8 *, 0x7F) = 1;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013E7E8 **, 0x88)[1].start;
            }
        }
        break;
    }
}

void func_8013EA9C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013EADC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013EB20(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

M2C_UNK Object_DisableCollision();
void func_80058134(void *, s32);
void Object_EnableCollision(void *);
void func_80052038_80140F9C(void *, s32) asm("func_80052038");
void func_8013EA9C(void *arg0);
void func_8013EADC(void *arg0);
void func_8013EB20(void *arg0);

void func_8013EB9C(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 0xFA;
        M2C_FIELD(o, s16 *, 0x46) = 0x200;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        M2C_FIELD(o, u8 *, 0x80) = 2;
        M2C_FIELD(o, u8 *, 0x7F) = 1;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        Object_EnableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        Object_PlaySound(o, 0x5C);
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, s16 *, 0xC2) = 0x12C;
            func_8013EA9C(o);
            func_8013EB20(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8013EADC(o);
            Object_PlaySound(o, 0x5E);
        }
        break;
    case 4:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80052038_80140F9C(o, 0x19);
            Object_DisableCollision(o);
        }
        break;
    }
}

s32 func_8013EDB8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

extern struct { u8 pad_0[0x812C]; u8 f_812C; u8 pad_812D[0xDF]; s16 *f_820C; u8 pad_8210[0x48]; SVECTOR f_8258; } g_Game_8013EDD0 asm("g_Game");
extern struct { u8 pad_0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013EDD0 asm("g_Spike");
extern u8 D_800E6908;
s32 Vec_Length(s32, s32, s32);
s16 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);
s32 Sound_UpdateVoice3D_8013EDD0(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");

s32 func_8013EDD0(s16 *p) {
    s16 *e = (s16 *)((u8 *)g_Game_8013EDD0.f_820C + p[2] * 0x38);
    SVECTOR v;

    switch (p[1]) {
    case 0:
        if (e[0x19] >= p[5] * 2 + 1) {
            e[0x15] = e[0x15] * -1;
            p[1] = 2;
        }
        break;
    case 2:
        if (e[0x19] == 1) {
            e[0x15] = e[0x15] * -1;
            p[1] = 0;
        }
        break;
    }
    if (g_Game_8013EDD0.f_812C == 0x18 || D_800E6908 == 1) {
        v = g_Game_8013EDD0.f_8258;
    } else {
        v.vx = g_Spike_8013EDD0.x;
        v.vy = g_Spike_8013EDD0.y;
        v.vz = g_Spike_8013EDD0.z;
    }
    if (Vec_Length(v.vx - e[0], v.vy - e[1], v.vz - e[2]) < 0x1800) {
        if (p[11] < 0) {
            p[11] = Sound_Play(1, 0x7D);
        } else {
            Sound_UpdateVoice3D_8013EDD0(0x7D, p[11], 0x1800, e);
        }
    } else if (p[11] >= 0) {
        Sound_Stop(0x7D, p[11]);
        p[11] = -1;
    }
    return 0;
}

s32 func_8013EFA0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013EFB0;
extern struct { u8 pad_0[0x820C]; s16 *f_820C; } g_Game_8013EFB0 asm("g_Game");
extern u8 *D_800B4D64_8013EFB0 asm("D_800B4D64");
void Sound_PlayAt_8013EFB0(s32, void *) asm("Sound_PlayAt");
void Camera_StartShake_8013EFB0(s32) asm("Camera_StartShake");
void func_80052CEC(s32);
void RotMatrixZYX_8013EFB0(SVECTOR *, Mat_8013EFB0 *) asm("RotMatrixZYX");
void func_8013D358(s16 x, s16 y, s16 z);

s32 func_8013EFB0(s16 *p) {
    s16 *e = (s16 *)((u8 *)g_Game_8013EFB0.f_820C + p[2] * 0x38);
    s32 a = 0;
    Mat_8013EFB0 m;
    SVECTOR r;

    switch (p[1]) {
    case 0:
        if (e[0xF] >= 0) {
            p[1] = 1;
            p[3] = p[5];
            Sound_PlayAt_8013EFB0(0xAC, e);
            Camera_StartShake_8013EFB0(0);
            func_8013D358(e[0], e[1], e[2]);
            func_80052CEC(1);
        }
        break;
    case 1:
        if (--p[3] < 0) {
            p[1] = 0;
            p[3] = 0;
        }
        a = (-(p[3] << 9) / p[5]) * rsin((p[3] << 13) / p[5]) / 4096;
        break;
    }
    if (p[6] >= 0) {
        r.vy = 0;
        r.vz = 0;
        r.vx = a;
        RotMatrixZYX_8013EFB0(&r, &m);
        *M2C_FIELD(D_800B4D64_8013EFB0 + p[6] * 32, Mat_8013EFB0 **, 0x1C) = m;
    }
    return 0;
}

extern struct S_g_Game_8013F1C0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F1C0 asm("g_Game");
s16 Sound_Play(s32, s32);

s32 func_8013F1C0(s16 *p) {
    u8 *t = g_Game_8013F1C0.f_820C;
    u16 *e = (u16 *)(t + p[5] * 0x38);

    p[1] = 0;
    p[3] = 0;
    p[6] = e[0];
    p[7] = e[1];
    p[8] = e[2];
    p[10] = Sound_Play(1, 0xB2);
    return 0;
}

extern struct { u8 pad_0[0x820C]; s16 *f_820C; } g_Game_8013F240 asm("g_Game");
extern u8 *D_800B4D64_8013F240 asm("D_800B4D64");
extern s32 D_800EC20C;
s32 Sound_UpdateVoice3D_8013F240(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");
s32 ShockBox_Update(s32, void *, s32);

s32 func_8013F240(s16 *p) {
    s16 *e = (s16 *)((u8 *)g_Game_8013F240.f_820C + p[2] * 0x38);
    s16 *r = (s16 *)((u8 *)g_Game_8013F240.f_820C + p[5] * 0x38);
    u8 *d;
    s16 b[6];
    s32 n;

    e[0] += r[0] - p[6];
    e[1] += r[1] - p[7];
    e[2] += r[2] - p[8];
    if (e[7] >= 0) {
        M2C_FIELD(D_800B4D64_8013F240 + e[7] * 32, s16 *, 0x10) += r[0] - p[6];
        M2C_FIELD(D_800B4D64_8013F240 + e[7] * 32, s16 *, 0x12) += r[1] - p[7];
        M2C_FIELD(D_800B4D64_8013F240 + e[7] * 32, s16 *, 0x14) += r[2] - p[8];
    }
    Sound_UpdateVoice3D_8013F240(0xB2, p[10], 0x1000, e);
    n = 3;
    if (e[2] < D_800EC20C) {
        n = 2;
    }
    b[0] = e[0];
    b[1] = e[1] + e[4];
    b[2] = e[2];
    b[3] = e[3] + 0x60;
    b[4] = e[4] * 2;
    b[5] = e[5] + 0x60;
    ShockBox_Update(n, b, 0x80);
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F3F8 asm("g_Game");
extern u8 *D_800B4D64_8013F3F8 asm("D_800B4D64");
void func_8004BD0C(void);

s32 func_8013F3F8(s16 *p) {
    u8 *t;
    u8 *e;
    s32 v;

    p[1] = 0;
    p[3] = 0;
    v = 0;
    if (p[4] >= 0) {
        t = g_Game_8013F3F8.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(t, s16 *, 6);
    }
    if (v != 0) {
        if (p[6] >= 0) {
            t = g_Game_8013F3F8.f_8220 + p[6] * 0x18;
            M2C_FIELD(t, s16 *, 2) = 1;
            e = g_Game_8013F3F8.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013F3F8 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        }
        if (p[7] >= 0) {
            t = g_Game_8013F3F8.f_8220 + p[7] * 0x18;
            M2C_FIELD(t, s16 *, 2) = 1;
            e = g_Game_8013F3F8.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013F3F8 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        }
        func_8004BD0C();
        p[1] = 3;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x1C]; u16 f_8120; u8 pad_8122[0x2E]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F584 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; } g_Spike_8013F584 asm("g_Spike");
extern u8 *D_800B4D64_8013F584 asm("D_800B4D64");
void CamFlyby_StartSegment(s32);

s32 func_8013F584(s16 *p) {
    u8 *t;
    s16 *e;
    s32 d;
    s32 dx;
    s32 dz;

    switch (p[1]) {
    case 0:
        if (p[5] >= 0) {
            t = g_Game_8013F584.f_8220 + p[5] * 0x18;
            e = (s16 *)(g_Game_8013F584.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38);
            dx = e[0] - g_Spike_8013F584.x;
            dz = e[2] - g_Spike_8013F584.z;
            d = dx * dx + dz * dz;
            if (p[3] == 0) {
                if (d < p[8] * p[8]) {
                    p[3] = 1;
                }
            } else if (p[8] * p[8] < d) {
                if (e[2] < g_Spike_8013F584.z) {
                    M2C_FIELD(t, s16 *, 2) = 2;
                    if (e[7] >= 0) {
                        M2C_FIELD(D_800B4D64_8013F584 + e[7] * 32, u16 *, 0x16) = 0xFFFF;
                    }
                    p[1] = 1;
                }
                p[3] = 0;
            }
        }
        break;
    case 1:
        if (p[4] >= 0) {
            t = g_Game_8013F584.f_8220 + p[4] * 0x18;
            if (M2C_FIELD(t, s16 *, 6) != 0 && g_Game_8013F584.f_8150 == 8) {
                p[1] = 2;
                p[3] = 0;
            }
        }
        break;
    case 2:
        if (g_Game_8013F584.f_8150 == 0) {
            if (p[6] >= 0) {
                t = g_Game_8013F584.f_8220 + p[6] * 0x18;
                M2C_FIELD(t, s16 *, 2) = 1;
                e = (s16 *)(g_Game_8013F584.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38);
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64_8013F584 + e[7] * 32, u16 *, 0x16) = 0xFFFF;
                }
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            }
            if (p[7] >= 0) {
                t = g_Game_8013F584.f_8220 + p[7] * 0x18;
                M2C_FIELD(t, s16 *, 2) = 1;
                e = (s16 *)(g_Game_8013F584.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38);
                if (e[7] >= 0) {
                    M2C_FIELD(D_800B4D64_8013F584 + e[7] * 32, u16 *, 0x16) = 0xFFFF;
                }
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            }
            if (p[5] >= 0) {
                t = g_Game_8013F584.f_8220 + p[5] * 0x18;
                M2C_FIELD(t, s16 *, 2) = 5;
            }
            func_8004BD0C();
            p[1] = 3;
            if (g_Game_8013F584.f_8120 != 0x13) {
                CamFlyby_StartSegment(0);
                g_Game_8013F584.f_8100 = 7;
            }
        }
        break;
    }
    return 0;
}

s32 func_8013F8D4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xE) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x14) = 1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    return 0;
}

typedef struct { s16 f0, state, f4, timer; s16 len[5]; } Gate_8013F8FC;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013F8FC asm("g_Game");
extern u8 *D_800B4D64_8013F8FC asm("D_800B4D64");
s32 func_8013FC68(s16 a0, s16 *pos, s32 n, s32 len);
void Matrix_SetScale(void *, void *);

s32 func_8013F8FC(s16 *p) {
    s16 *e;
    u8 *m;
    s32 k;
    s16 j;
    SVECTOR v;

    e = (s16 *)(g_Game_8013F8FC.f_820C + p[2] * 0x38);
    m = D_800B4D64_8013F8FC;
    M2C_FIELD(m + p[5] * 32, s16 *, 0x10) = e[0];
    M2C_FIELD(m + p[5] * 32, s16 *, 0x12) = e[1] - e[4];
    M2C_FIELD(m + p[5] * 32, s16 *, 0x14) = e[2] + e[3];
    M2C_FIELD(m + p[6] * 32, s16 *, 0x10) = e[0];
    M2C_FIELD(m + p[6] * 32, s16 *, 0x12) = e[1] - e[4];
    M2C_FIELD(m + p[6] * 32, s16 *, 0x14) = e[2] - e[3];
    switch (p[1]) {
    case 0:
        p[3] = 0x2AA;
        p[9] = 0x2A;
        p[1] = p[10];
        break;
    case 1:
    case 3:
        k = 4;
        if (p[1] == 1) {
            k = 3;
        }
        ((Gate_8013F8FC *)p)->len[k] += p[9];
        if (((Gate_8013F8FC *)p)->len[k] >= p[3]) {
            ((Gate_8013F8FC *)p)->len[k] = p[3];
            if (k == 3) {
                p[1] = 2;
            } else {
                p[1] = 4;
            }
        }
        break;
    case 2:
    case 4:
        k = 4;
        if (p[1] == 2) {
            k = 3;
        }
        ((Gate_8013F8FC *)p)->len[k] -= p[9];
        if (((Gate_8013F8FC *)p)->len[k] <= 0x100) {
            ((Gate_8013F8FC *)p)->len[k] = 0x100;
            if (p[3] == 0x2AA) {
                p[1] = 5;
                p[3] = 0x14;
                p[10] = k;
            } else {
                p[1] = 6;
                p[3] = 0x23;
                if (k == 3) {
                    p[10] = k;
                } else {
                    p[10] = 1;
                }
            }
        }
        break;
    case 5:
        if (--p[3] < 0) {
            j = 3;
            if (p[10] == 3) {
                j = 1;
            }
            p[3] = 0x1000;
            p[1] = j;
            p[9] = 0x199;
            Sound_PlayAt_8013EFB0(0xAD, e);
        }
        break;
    case 6:
        if (--p[3] < 0) {
            p[1] = 0;
            p[3] = 0;
        }
        break;
    }
    func_8013FC68(p[3], (s16 *)(D_800B4D64_8013F8FC + p[5] * 32 + 0x10), -1, p[7]);
    func_8013FC68(p[3], (s16 *)(D_800B4D64_8013F8FC + p[6] * 32 + 0x10), 1, p[8]);
    v.vy = 0x1000;
    v.vx = 0x1000;
    v.vz = p[7];
    Matrix_SetScale(&v, M2C_FIELD(D_800B4D64_8013F8FC + p[5] * 32, void **, 0x1C));
    v.vz = p[8];
    Matrix_SetScale(&v, M2C_FIELD(D_800B4D64_8013F8FC + p[6] * 32, void **, 0x1C));
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

typedef struct { s32 x, y, z; u8 pad_C[0xC]; SVECTOR rot; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013FC68;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013FC68 asm("g_Spike");
Shape_8013FC68 *CollShape_Alloc_8013FC68(void) asm("CollShape_Alloc");
s32 Collision_Set(s32, void *, void *);

s32 func_8013FC68(s16 a0, s16 *pos, s32 n, s32 len) {
    s32 z;
    s32 h;
    SVECTOR v;
    Shape_8013FC68 *s;

    if (len == 0x100) {
        return 0;
    }
    if (a0 != 0x1000) {
        return 0;
    }
    h = len / 8;
    z = pos[2] + n * h;
    if (pos[0] - 0x300 < g_Spike_8013FC68.x && g_Spike_8013FC68.x < pos[0] + 0x300
        && g_Spike_8013FC68.y < pos[1] + 0x40 && pos[1] - 0x200 < g_Spike_8013FC68.y
        && z - h - 0x40 < g_Spike_8013FC68.z && g_Spike_8013FC68.z < z + h + 0x40) {
        v.vy = 0;
        v.vx = 0;
        v.vz = n << 12;
        s = CollShape_Alloc_8013FC68();
        if (s != NULL) {
            s->rot = v;
            s->x = g_Spike_8013FC68.x;
            s->y = g_Spike_8013FC68.y - 0x80;
            s->z = g_Spike_8013FC68.z - (n << 7);
            s->f_20 = 0x80;
            s->f_24 = 1;
            s->f_26 = 0x202;
            Collision_Set(6, s, 0);
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FDC8 asm("g_Game");
extern u8 *D_800B4D64_8013FDC8 asm("D_800B4D64");
void Pad_Vibrate(s32, s32, s32);
void Fx_Explosion_8013FDC8(void *, s32, s32) asm("Fx_Explosion");

s32 func_8013FDC8(s16 *p) {
    u8 *t;
    u8 *e;

    if (p[1] == 0) {
        t = g_Game_8013FDC8.f_8220 + p[6] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 1) {
            e = g_Game_8013FDC8.f_820C + p[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            p[1] = 2;
            Pad_Vibrate(0, 1, 3);
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013FDC8 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
                Fx_Explosion_8013FDC8(e, M2C_FIELD(e, s16 *, 0xE), 1);
                Camera_StartShake(0);
            }
        }
    }
    return 0;
}

extern struct S_g_Game_8013FEA4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FEA4 asm("g_Game");

s32 func_8013FEA4(s16 *p) {
    u8 *e = g_Game_8013FEA4.f_820C + p[2] * 0x38;
    u8 *f;

    if (p[10] != 0) {
        p[1] = 2;
    } else {
        f = g_Game_8013FEA4.f_8220 + p[5] * 0x18;
        if (M2C_FIELD(f, s16 *, 0x16) < p[6]) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 0;
            p[3] = 0;
        } else {
            p[1] = 2;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x4C]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FF40 asm("g_Game");
void CamFlyby_StartSegment(s32);
s32 Sound_PlayFixed_8013FF40(s32) asm("Sound_PlayFixed");

s32 func_8013FF40(s16 *p) {
    u8 *e;
    u8 *t;

    e = g_Game_8013FF40.f_820C + p[2] * 0x38;
    switch (p[1]) {
    case 0:
        t = g_Game_8013FF40.f_8220 + p[5] * 0x18;
        if (M2C_FIELD(t, s16 *, 0x16) >= p[6] && g_Game_8013FF40.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_8013FF40.f_8150 == 0) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 2;
            Sound_PlayFixed_8013FF40(0x9C);
            if (p[7] > 0) {
                CamFlyby_StartSegment(p[7] - 1);
                g_Game_8013FF40.f_8100 = 7;
            }
        }
        break;
    case 2:
        if (M2C_FIELD(e, s16 *, 0x32) >= p[4] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 3;
        }
        break;
    }
    return 0;
}

s32 func_801400A4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 4;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801400B8 asm("g_Game");
s32 Sound_PlayAt_801400B8(s32, void *) asm("Sound_PlayAt");
s32 func_8014019C(s16 *p);

s32 func_801400B8(s16 *p) {
    u8 *e = g_Game_801400B8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 1:
    case 4:
        break;
    case 5:
        p[3] += p[5];
        if (p[3] > 0x4AA) {
            p[3] = 0x4AA;
            p[1] = 2;
            Sound_PlayAt_801400B8(0xB1, e);
        }
        func_8014019C(p);
        break;
    case 2:
        p[3] -= p[7];
        if (p[3] < 0) {
            p[3] = 0;
            p[1] = 4;
        }
        func_8014019C(p);
        break;
    }
    return 0;
}

extern u8 *D_800B4D64;
void RotMatrixZYX(SVECTOR *, void *);

s32 func_8014019C(s16 *p) {
    SVECTOR r;

    if ((**(u32 **)(D_800B4D64 + p[6] * 32) & 0xF) != 3) {
        return 0;
    }
    {
        r.vy = 0;
        r.vx = 0;
        r.vz = (u16)p[3] * (u16)p[4];
        RotMatrixZYX(&r, M2C_FIELD(D_800B4D64 + p[6] * 32, void **, 0x1C));
    }
    return 0;
}

extern struct S_g_Game_80140224 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140224 asm("g_Game");

s32 func_80140224(s16 *p) {
    u16 *e = (u16 *)(g_Game_80140224.f_820C + p[2] * 0x38);

    e[0xC] = (e[0xC] & 0xFFF0) | 1;
    p[1] = 0;
    p[3] = 0;
    p[9] = 0;
    p[10] = -1;
    e[0x19] = e[3];
    e[0x1A] = e[4];
    e[0x1B] = e[5];
    if (p[4] >= 0) {
        u8 *f = g_Game_80140224.f_8220 + p[4] * 0x18;

        M2C_FIELD(f, u16 *, 6) = p[5];
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801402C0 asm("g_Game");
s32 Sound_UpdateVoice3D_801402C0(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");
s32 func_801404B0(u8 *e, s16 *p);

s32 func_801402C0(s16 *p) {
    u8 *e = g_Game_801402C0.f_820C + p[2] * 0x38;
    u8 *t;
    s32 v;

    v = 0;
    if (p[4] >= 0) {
        t = g_Game_801402C0.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(t, s16 *, 0x16);
    }
    switch (p[1]) {
    case 0:
        if (v < p[9]) {
            p[9] -= p[7];
            p[1] = 2;
        } else {
            p[9] = v;
            if (v >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            }
        }
        break;
    case 1:
        if (--p[3] < 0) {
            p[1] = 2;
        }
        break;
    case 2:
        p[9] -= p[7];
        if (p[9] < v) {
            p[9] = v;
            if (v >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            } else {
                p[1] = 0;
            }
        } else if (p[9] < 0) {
            p[9] = 0;
            p[1] = 0;
        }
        break;
    }
    if (p[9] != 0) {
        if (p[10] < 0) {
            p[10] = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D_801402C0(0x7F, p[10], 0x1000, e);
        }
    } else if (p[10] >= 0) {
        Sound_Stop(0x7F, p[10]);
        p[10] = -1;
    }
    func_801404B0(e, p);
    return 0;
}

extern u8 *D_800B4D64_801404B0 asm("D_800B4D64");
void func_800147D0_801404B0(s16 *, void *) asm("Matrix_SetScale");

s32 func_801404B0(u8 *e, s16 *p) {
    s16 v[3];

    if (p[8] == 0) {
        { register s32 t asm("$3"); t = M2C_FIELD(e, s16 *, 0x32) * p[9] / 4096; M2C_FIELD(e, s16 *, 6) = t; }
        v[0] = p[9];
        v[2] = 0x1000;
        v[1] = 0x1000;
    } else if (p[8] == 1) {
        v[1] = 0x1000;
        v[0] = 0x1000;
        v[2] = p[9];
        { register s32 t asm("$3"); t = M2C_FIELD(e, s16 *, 0x36) * p[9] / 4096; M2C_FIELD(e, s16 *, 0xA) = t; }
    } else {
        v[2] = 0x1000;
        v[0] = 0x1000;
        v[1] = p[9];
        { register s32 t asm("$3"); t = M2C_FIELD(e, s16 *, 0x34) * p[9] / 4096; M2C_FIELD(e, s16 *, 8) = t; }
    }
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        func_800147D0_801404B0(v, M2C_FIELD(D_800B4D64_801404B0 + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801405C4 asm("g_Game");
extern u8 *D_800B4D64_801405C4 asm("D_800B4D64");

s32 func_801405C4(s16 *p) {
    u8 *e = g_Game_801405C4.f_820C + p[2] * 0x38;

    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        **(u32 **)(D_800B4D64_801405C4 + M2C_FIELD(e, s16 *, 0xE) * 32) |= 0x2000;
    }
    M2C_FIELD(e, u16 *, 0x32) = M2C_FIELD(e, u16 *, 6);
    M2C_FIELD(e, u16 *, 0x34) = M2C_FIELD(e, u16 *, 8);
    M2C_FIELD(e, u16 *, 0x36) = M2C_FIELD(e, u16 *, 0xA);
    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 2;
        p[3] = 0x1000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8014066C asm("g_Game");
extern u8 *D_800B4D64_8014066C asm("D_800B4D64");
void Sound_PlayAt_8014066C(s32, void *) asm("Sound_PlayAt");

s32 func_8014066C(s16 *p) {
    s16 *e = (s16 *)(g_Game_8014066C.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        p[3] += p[5];
        if (p[3] > 0x1000) {
            p[3] = 0;
            p[1] = 1;
            break;
        }
        e[4] = e[0x1A] - e[0x1A] * p[3] / 4096;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014066C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        break;
    case 1:
        p[3]++;
        if (p[6] < p[3]) {
            p[3] = 0x1000;
            p[1] = 2;
            Sound_PlayAt_8014066C(0xAE, e);
        }
        e[4] = 0;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014066C + e[7] * 32, s16 *, 0x18) = 0x1000;
        }
        break;
    case 2:
        p[3] -= p[7];
        if (p[3] < 0) {
            p[3] = 0;
            p[1] = 3;
            break;
        }
        e[4] = e[0x1A] - e[0x1A] * p[3] / 4096;
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014066C + e[7] * 32, s16 *, 0x18) = p[3];
        }
        break;
    case 3:
        p[3]++;
        if (p[8] < p[3]) {
            p[3] = 0;
            p[1] = 0;
            Sound_PlayAt_8014066C(0xAF, e);
        }
        e[4] = e[0x1A];
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_8014066C + e[7] * 32, s16 *, 0x18) = 0;
        }
        break;
    }
    return 0;
}

extern u8 *D_800B4D64;
extern struct { u8 pad0[0x20C]; u8 *f_20C; } D_800F4350;

s32 func_8014087C(u8 *a) {
    s16 ids[8];
    s16 i;
    s16 n;
    s16 id;
    u8 *e;
    u8 *tbl;

    ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
    ids[1] = M2C_FIELD(a, u8 *, 0xC);
    ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
    ids[3] = M2C_FIELD(a, u8 *, 0xE);
    ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
    ids[5] = M2C_FIELD(a, u8 *, 0x10);
    ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
    ids[7] = M2C_FIELD(a, u8 *, 0x12);
    tbl = D_800B4D64;
    n = i = 0;
    for (; i < 8; i++) {
        id = ids[i];
        if (id >= 0 && id != 0xFF) {
            e = D_800F4350.f_20C + id * 0x38;
            n++;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            M2C_FIELD(e, s16 *, 0xE) += i;
            M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    M2C_FIELD(a, s16 *, 0x14) = M2C_FIELD(a, s16 *, 0xA) / n;
    M2C_FIELD(a, s16 *, 0x2) = 0;
    M2C_FIELD(a, s16 *, 0x6) = 0;
    return 0;
}

extern struct S_g_Game_801409C8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game_801409C8 asm("g_Game");

s32 func_801409C8(u8 *a) {
    s16 ids[8];
    s16 t;
    s32 r;
    s32 d;
    u8 *e;

    t = ++M2C_FIELD(a, s16 *, 0x6);
    if (t < M2C_FIELD(a, s16 *, 0xA) * 2) {
        if (t < (M2C_FIELD(a, s16 *, 0x14) / 2) * 2) {
            return 0;
        }
        ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
        ids[1] = M2C_FIELD(a, u8 *, 0xC);
        ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
        ids[3] = M2C_FIELD(a, u8 *, 0xE);
        ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
        ids[5] = M2C_FIELD(a, u8 *, 0x10);
        ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
        ids[7] = M2C_FIELD(a, u8 *, 0x12);
        r = M2C_FIELD(a, s16 *, 0x6) - (M2C_FIELD(a, s16 *, 0x14) / 2) * 2;
        d = M2C_FIELD(a, s16 *, 0x14) * 2;
        if (r % d != 0) {
            return 0;
        }
        e = g_Game_801409C8.f_820C + ids[r / d] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140B58 asm("g_Game");
void Model_SetTurnAngle(s32, s32, s32);
#define SHOW_80140B58(k, i) k = (i); if (k >= 0) { u8 *e_ = g_Game_80140B58.f_820C + k * 0x38; M2C_FIELD(e_, u16 *, 0x18) = (M2C_FIELD(e_, u16 *, 0x18) & 0xFFF0) | 1; }
#define HIDE_80140B58(k, i) k = (i); if (k >= 0) { u8 *e_ = g_Game_80140B58.f_820C + k * 0x38; M2C_FIELD(e_, u16 *, 0x18) |= 0x8000; }

s32 func_80140B58(s16 *p) {
    s32 a, b, c, d, e, f;
    s32 k;
    s32 k2;

    a = (u16)p[6] >> 8;
    b = (u16)p[6] & 0xFF;
    c = (u16)p[7] >> 8;
    d = (u16)p[7] & 0xFF;
    e = (u16)p[8] >> 8;
    f = (u16)p[8] & 0xFF;
    if (p[5] == 0) {
        p[1] = 0;
        SHOW_80140B58(k, a);
        HIDE_80140B58(k, b);
        SHOW_80140B58(k, c);
        SHOW_80140B58(k, d);
        HIDE_80140B58(k2, e);
        HIDE_80140B58(k2, f);
        p[3] = 0;
    } else {
        p[1] = 2;
        HIDE_80140B58(k, a);
        SHOW_80140B58(k, b);
        HIDE_80140B58(k, c);
        HIDE_80140B58(k, d);
        SHOW_80140B58(k2, e);
        SHOW_80140B58(k2, f);
        p[3] = 0x400;
        Model_SetTurnAngle(p[4], p[9], 0x400);
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140EB0 asm("g_Game");

s32 func_80140EB0(s16 *p) {
    s32 a, b, c, d, e, f;
    u8 *o1;
    u8 *o2;

    a = (u16)p[6] >> 8;
    b = (u16)p[6] & 0xFF;
    c = (u16)p[7] >> 8;
    d = (u16)p[7] & 0xFF;
    e = (u16)p[8] >> 8;
    f = (u16)p[8] & 0xFF;
    switch (p[1]) {
    case 0:
        o1 = g_Game_80140EB0.f_820C + c * 0x38;
        o2 = g_Game_80140EB0.f_820C + d * 0x38;
        if (M2C_FIELD(o1, s16 *, 0x1E) >= 0 || M2C_FIELD(o2, s16 *, 0x1E) >= 0) {
            p[1] = 1;
            M2C_FIELD(o1, u16 *, 0x18) |= 0x8000;
            M2C_FIELD(o2, u16 *, 0x18) |= 0x8000;
            o1 = g_Game_80140EB0.f_820C + a * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) |= 0x8000;
            p[3] = 0;
            if (M2C_FIELD(o1, s16 *, 0x1E) >= 0) {
                Sound_PlayAt_8013EFB0(0xB4, o1);
            } else {
                Sound_PlayAt_8013EFB0(0xB4, o2);
            }
        }
        break;
    case 1:
        Model_SetTurnAngle(p[4], p[9], p[3]);
        p[3] += 0x20;
        if (p[3] > 0x400) {
            p[1] = 2;
            o1 = g_Game_80140EB0.f_820C + e * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) &= 0x7FFF;
            o2 = g_Game_80140EB0.f_820C + f * 0x38;
            M2C_FIELD(o2, u16 *, 0x18) &= 0x7FFF;
            o1 = g_Game_80140EB0.f_820C + b * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) &= 0x7FFF;
        }
        break;
    case 2:
        o1 = g_Game_80140EB0.f_820C + e * 0x38;
        o2 = g_Game_80140EB0.f_820C + f * 0x38;
        if (M2C_FIELD(o1, s16 *, 0x1E) >= 0 || M2C_FIELD(o2, s16 *, 0x1E) >= 0) {
            p[1] = 3;
            M2C_FIELD(o1, u16 *, 0x18) |= 0x8000;
            M2C_FIELD(o2, u16 *, 0x18) |= 0x8000;
            o1 = g_Game_80140EB0.f_820C + b * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) |= 0x8000;
            p[3] = 0x400;
            if (M2C_FIELD(o1, s16 *, 0x1E) >= 0) {
                Sound_PlayAt_8013EFB0(0xB4, o1);
            } else {
                Sound_PlayAt_8013EFB0(0xB4, o2);
            }
        }
        break;
    case 3:
        Model_SetTurnAngle(p[4], p[9], p[3]);
        p[3] += 0x20;
        if (p[3] > 0x800) {
            p[1] = 0;
            o1 = g_Game_80140EB0.f_820C + c * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) &= 0x7FFF;
            o2 = g_Game_80140EB0.f_820C + d * 0x38;
            M2C_FIELD(o2, u16 *, 0x18) &= 0x7FFF;
            o1 = g_Game_80140EB0.f_820C + a * 0x38;
            M2C_FIELD(o1, u16 *, 0x18) &= 0x7FFF;
        }
        break;
    }
    return 0;
}

extern struct S_g_Game_80141240 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141240 asm("g_Game");

s32 func_80141240(s16 *p) {
    u8 *e = g_Game_80141240.f_820C + p[2] * 0x38;

    if (p[5] == 0) {
        p[1] = 0;
    } else {
        p[1] = 1;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801412C4 asm("g_Game");
extern u8 *D_800B4D64_801412C4 asm("D_800B4D64");
void Camera_StartShake(s32);
void Fx_Explosion_801412C4(void *, s32, s32) asm("Fx_Explosion");

s32 func_801412C4(s16 *p) {
    u8 *e = g_Game_801412C4.f_820C + p[2] * 0x38;
    s32 s;
    u8 *t;

    if (p[1] == 0) {
        t = g_Game_801412C4.f_8220 + p[4] * 0x18;
        s = M2C_FIELD(t, s16 *, 2);
        if (s == 1) {
            Camera_StartShake(0);
            Pad_Vibrate(0, 1, 3);
            p[1] = s;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_801412C4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
                Fx_Explosion_801412C4(e, M2C_FIELD(e, s16 *, 0xE), 1);
            }
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801413AC asm("g_Game");

s32 func_801413AC(s16 *p) {
    u8 *e = g_Game_801413AC.f_820C + p[2] * 0x38;

    if (p[1] == 1) {
        if (M2C_FIELD(e, s16 *, 0x32) == 1) {
            p[4] = Sound_Play(0, 0x7C);
        }
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 2;
            Sound_Stop(0x7C, p[4]);
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8014146C asm("g_Game");
extern u8 *D_800B4D64_8014146C asm("D_800B4D64");

s32 func_8014146C(s16 *p) {
    u8 *e = g_Game_8014146C.f_820C + p[2] * 0x38;
    u8 *t;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 4);
    t = g_Game_8014146C.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(t, s16 *, 2) == 3) {
        p[1] = 2;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8014146C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x12) -= M2C_FIELD(e, u16 *, 8);
        }
        M2C_FIELD(e, u16 *, 2) -= M2C_FIELD(e, u16 *, 8);
    } else {
        p[1] = 0;
        p[3] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141538 asm("g_Game");
extern u8 *D_800B4D64_80141538 asm("D_800B4D64");
s32 Sound_PlayFixed_80141538(s32) asm("Sound_PlayFixed");

s32 func_80141538(s16 *p) {
    u8 *e = g_Game_80141538.f_820C + p[2] * 0x38;
    u8 *t;
    s16 v;

    switch (p[1]) {
    case 0:
        t = g_Game_80141538.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 2) {
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        p[3] += 0x20;
        if (p[3] > M2C_FIELD(e, s16 *, 8)) {
            p[3] = M2C_FIELD(e, s16 *, 8);
            p[1] = 2;
            Sound_PlayFixed_80141538(0x81);
        }
        v = M2C_FIELD(e, u16 *, 0x26) - p[3];
        M2C_FIELD(e, s16 *, 2) = v;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80141538 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x12) = v;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xBA]; s16 *f_820C; } g_Game_8014164C asm("g_Game");
extern s16 D_800EC238;
s32 Sound_UpdateVoice3D_8014164C(s32, s32, s32, void *) asm("Sound_UpdateVoice3D");

s32 func_8014164C(s16 *p) {
    s16 *e = (s16 *)((u8 *)g_Game_8014164C.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2] && g_Game_8014164C.f_8150 == 6 && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[3] = 1;
            p[1] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
            p[4] = Sound_Play(1, 0xB5);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 1:
        if (e[0x19] >= p[6] * 2 + 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 2;
            Sound_Stop(0xB5, p[4]);
            p[3] = D_800EC238 == p[2];
        } else {
            Sound_UpdateVoice3D_8014164C(0xB5, p[4], 0x1000, e);
        }
        break;
    case 2:
        if (D_800EC238 == p[2] && g_Game_8014164C.f_8150 == 6 && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[1] = 3;
            p[3] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
            p[4] = Sound_Play(1, 0xB5);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 3:
        if (e[0x19] == 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 0;
            Sound_Stop(0xB5, p[4]);
            p[3] = D_800EC238 == p[2];
        } else {
            Sound_UpdateVoice3D_8014164C(0xB5, p[4], 0x1000, e);
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; s16 *f_820C; } g_Game_80141874 asm("g_Game");
void Sound_PlayAt_80141874(s32, void *) asm("Sound_PlayAt");

s32 func_80141874(s16 *p) {
    s16 *e = (s16 *)((u8 *)g_Game_80141874.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[3] = 1;
            p[1] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
            Sound_PlayAt_80141874(0x9C, e);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 1:
        if (e[0x19] == 0xB5) {
            Sound_PlayAt_80141874(0x9C, e);
        }
        if (e[0x19] >= p[6] * 2 + 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 2;
            goto tail;
        }
        break;
    case 2:
        if (D_800EC238 == p[2] && p[3] == 0) {
            e[0xC] = (e[0xC] & 0xFFF0) | 2;
            p[1] = 3;
            p[3] = 1;
            p[9] = e[0];
            p[10] = e[1];
            p[11] = e[2];
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 3:
        if (e[0x19] == 0xDD) {
            Sound_PlayAt_80141874(0x9C, e);
        }
        if (e[0x19] == 1) {
            e[0xC] = (e[0xC] & 0xFFF0) | 1;
            p[1] = 0;
            Sound_PlayAt_80141874(0x9C, e);
        tail:
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}
