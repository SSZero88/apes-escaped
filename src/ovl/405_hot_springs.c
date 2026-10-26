#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void Effect_SpawnAt(s32, SVECTOR *);
extern u8 D_800B1C28[];

void func_8013D000(void *arg0, s32 dx, s32 dy, s32 dz) {
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

extern struct { u8 pad0[0x24]; s32 x; u8 pad28[4]; s32 z; } g_Spike_8013D100 asm("g_Spike");
s32 Math_Atan2(s32, s32);
void func_8013D000(void *arg0, s32 dx, s32 dy, s32 dz);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);

s32 func_8013D100(u8 *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) != 11) {
        return 0;
    }
    arg0[0x80] = 6;
    arg0[0x7F] = 6;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(arg0[0x7F] * 4 + M2C_FIELD(arg0, u8 **, 0x88));
    M2C_FIELD(arg0, s16 *, 0x96) = -0x78;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x10000;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0xF0;
    M2C_FIELD(arg0, s16 *, 0xAA) = Math_Atan2(M2C_FIELD(arg0, s32 *, 0x24) - g_Spike_8013D100.x, M2C_FIELD(arg0, s32 *, 0x2C) - g_Spike_8013D100.z) % 0x1000;
    M2C_FIELD(arg0, s16 *, 0xAC) = (M2C_FIELD(arg0, s16 *, 0xAA) + 0x800) % 0x1000;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(M2C_FIELD(arg0, s16 *, 0xAC));
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    func_8013D000(arg0, 0, -200, 0);
    Object_PlaySound(arg0, 0xB4);
    Sound_PlayFixed(0x5F);
    Sound_PlayFixed(0x15);
    return 1;
}

s16 Object_FloorAt(void *, s16, s16, s16);

s32 func_8013D230(u8 *o) {
    s32 c = rcos(M2C_FIELD(o, s16 *, 0xAA)) * 200 >> 12;
    s32 s = rsin(M2C_FIELD(o, s16 *, 0xAA)) * 200 >> 12;
    s32 d = M2C_FIELD(o, s16 *, 0x9C) - Object_FloorAt(o, M2C_FIELD(o, u16 *, 0x94) + c, 0, M2C_FIELD(o, u16 *, 0x98) + s);

    if (ABS(d) > 200) {
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        return 1;
    }
    return 0;
}

s32 func_8013D230(u8 *o);
void Object_StepGrowShrink(void *, s32, s32, s32);

void func_8013D2FC(void *arg0, s32 arg1, s32 arg2) {
    Object_StepGrowShrink(arg0, 0, 0, (s16)arg1);
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * ((s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13)) >> 0xC);
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * ((s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13)) >> 0xC);
    if (arg2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x94) = M2C_FIELD(arg0, s16 *, 0x94) * -1;
        M2C_FIELD(arg0, s16 *, 0x98) = M2C_FIELD(arg0, s16 *, 0x98) * -1;
    }
    func_8013D230(arg0);
}

s32 func_8013D2FC_8013D3B4(void *, s32, s32) asm("func_8013D2FC");
s32 Object_WouldLeaveHome_8013D3B4(void *, s32) asm("Object_WouldLeaveHome");
void Object_ApplyVelocity(void *);

s32 func_8013D3B4(u8 *o) {
    s32 r;
    s32 a;
    s32 h;

    if (!(M2C_FIELD(o, u16 *, 0xE2) & 1)) {
        r = (func_8013D2FC_8013D3B4(o, -1, 0) != 0) << 1;
    } else {
        r = 1;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, s16 *, 0x98) = 0;
    }
    if (Object_WouldLeaveHome_8013D3B4(o, 0)) {
        r = 1;
    }
    if (!r) {
        Object_ApplyVelocity(o);
    }
    a = (M2C_FIELD(o, s16 *, 0xAC) + 0x16) % 0x1000;
    h = M2C_FIELD(o, s16 *, 0xAA) - 0x1000;
    if ((u32)((a - h + 0x800) % 0x1000 - 0x2AA) >= 0xAAC) {
        M2C_FIELD(o, s16 *, 0xAC) = a;
        M2C_FIELD(o, s16 *, 0x60) = rcos(a);
        M2C_FIELD(o, s16 *, 0x64) = rsin(M2C_FIELD(o, s16 *, 0xAC));
    }
    return r;
}

void Object_ApplyVelocity(void *);

void func_8013D4B8(void *arg0) {
    if (!(M2C_FIELD(arg0, u16 *, 0xE2) & 1)) {
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 0x10) {
            func_8013D2FC(arg0, -5, 0);
        } else {
            func_8013D2FC(arg0, -10, 1);
        }
        Object_ApplyVelocity(arg0);
    }
}

extern struct { u8 pad0[0x24]; s32 x; u8 pad28[4]; s32 z; } g_Spike_8013D520 asm("g_Spike");

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013D520(arg0)
    void *arg0;
{
    s32 dx;
    s32 dz;
    s32 r;

    dx = g_Spike_8013D520.x - M2C_FIELD(arg0, s16 *, 0x9A);
    dz = g_Spike_8013D520.z - M2C_FIELD(arg0, s16 *, 0x9E);
    r = M2C_FIELD(arg0, s16 *, 0xA4) + 0xC8;
    return r * r < dx * dx + dz * dz;
}

void func_8013D578(void *arg0) {
    if (func_8013D520() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

s32 func_8013D3B4(u8 *o);
void func_8005836C(void *, void *, s16, s16);
void Object_CameraShake(void *, s32);
void Pad_Vibrate(s32, s32, s32);
void func_800702B0(void *, void *);
extern s32 D_800B1CD0[];
extern u8 D_80141164[];

void func_8013D5BC(u8 *o) {
    SVECTOR v;
    SVECTOR p;
    s32 i;

    if (func_8013D3B4(o)) {
        M2C_FIELD(o, s16 *, 0x44) = 1;
        v.vx = M2C_FIELD(o, u16 *, 0x24);
        v.vy = M2C_FIELD(o, u16 *, 0x28) - M2C_FIELD(o, s16 *, 0x46) / 2;
        v.vz = M2C_FIELD(o, u16 *, 0x2C);
        func_8005836C(o, &v, 300, 0x204);
        Object_CameraShake(o, 2);
        Pad_Vibrate(1, 0xF0, 5);
        Sound_PlayFixed(0x80);
        Sound_PlayFixed(0x79);
        for (i = 0; i < 32; i++) {
            p.vx = v.vx + ((RAND() >> 8) - 0x80) * 2;
            p.vy = v.vy + ((RAND() >> 8) - 0x80);
            p.vz = v.vz + ((RAND() >> 8) - 0x80) * 2;
            Effect_SpawnAt(6, &p);
        }
        func_80070284(&v, D_800B1CD0, 1, 0, o + 0x60);
        func_800702B0(&v, D_80141164);
        func_800702B0(&v, D_80141164 + 0xC);
        M2C_FIELD(o, u8 *, 0x80) = 8;
        M2C_FIELD(o, u8 *, 0x7F) = 8;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4);
        M2C_FIELD(o, s16 *, 0xA8) = 0x118;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x10000;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D7AC);

extern struct { u32 f_0; } g_Game_8013D904 asm("g_Game");

void func_8013D904(u8 *o) {
    s32 a;

    if (M2C_FIELD(o, u8 *, 0x7F) == 4
        || (M2C_FIELD(o, u8 *, 0x7F) == 10 && g_Game_8013D904.f_0 % 6 < 3
            && *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4) + 20 < M2C_FIELD(o, u16 *, 0x5C))) {
        a = 0x9D;
    } else if (M2C_FIELD(o, u8 *, 0x7F) == 6 || M2C_FIELD(o, u8 *, 0x7F) == 12 || M2C_FIELD(o, u8 *, 0x7F) == 8) {
        a = 0x9E;
    } else {
        a = 9;
    }
    if (a != M2C_FIELD(o, u8 *, 0xDD)) {
        func_80052038(o, a);
        M2C_FIELD(o, u8 *, 0xDD) = a;
    }
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013D9EC);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 func_8013DA9C(void *arg0) {
    if (Object_SpikeInFront(arg0, 0x5A, 0xB50, 0x300) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(((M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, void **, 0x88)), u16 *, 2)) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 3U;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        }
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
        Object_PlaySound(arg0, 0xB4);
        return 1;
    }
    return 0;
}

void *memset(void *, s32, s32);

void func_8013DB2C(u8 *o) {
    SVECTOR a;
    SVECTOR v;
    s32 dx;
    s32 dz;
    s32 x;
    s32 t;
    s32 y;
    s32 fl;

    Object_StepGrowShrink(o, 0, 0, -1);
    dx = rcos(M2C_FIELD(o, s16 *, 0xAA)) * (M2C_FIELD(o, s16 *, 0xA8) >> 3) >> 12;
    dz = rsin(M2C_FIELD(o, s16 *, 0xAA)) * (M2C_FIELD(o, s16 *, 0xA8) >> 3) >> 12;
    x = M2C_FIELD(o, s32 *, 0x24) + dx;
    t = M2C_FIELD(o, s32 *, 0x2C) + dz - M2C_FIELD(o, s16 *, 0x9E);
    if ((x - M2C_FIELD(o, s16 *, 0x9A)) * (x - M2C_FIELD(o, s16 *, 0x9A)) + t * t
        < M2C_FIELD(o, s16 *, 0xA6) * M2C_FIELD(o, s16 *, 0xA6)) {
        M2C_FIELD(o, s32 *, 0x24) = x;
        M2C_FIELD(o, s32 *, 0x2C) += dz;
        memset(&v, 0, 8);
        v.vx = M2C_FIELD(o, u16 *, 0x24);
        v.vy = M2C_FIELD(o, u16 *, 0x28);
        v.vz = M2C_FIELD(o, u16 *, 0x2C);
        a = v;
        Effect_SpawnAt(9, &a);
    }
    fl = M2C_FIELD(o, s16 *, 0x9C);
    y = M2C_FIELD(o, s32 *, 0x28) + (M2C_FIELD(o, s16 *, 0x96) >> 3);
    M2C_FIELD(o, s32 *, 0x28) = y;
    M2C_FIELD(o, s16 *, 0x96) += 14;
    if (fl < y) {
        M2C_FIELD(o, s16 *, 0xA8) = 0x140;
        M2C_FIELD(o, s32 *, 0x28) = fl;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x96) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, u8 *, 0x80) = 7;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x10000;
        Object_PlaySound(o, 0x2B);
        if (M2C_FIELD(o, u8 *, 0x7F) != 7) {
            M2C_FIELD(o, u8 *, 0x7F) = 7;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4);
        }
    }
}

void Camera_StartShake(s32);

void func_8013DD04(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1 || d == f2) {
        Object_PlaySound(arg0, 0x43);
        Camera_StartShake(0);
    }
}

M2C_UNK Object_PlaceAtPathPoint(void *, M2C_UNK);
s32 func_80057140(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_8005866C(void *, M2C_UNK);

void func_8013DD5C(void *arg0)
{
  *((s16 *) (((s8 *) arg0) + 0xB0)) = 0x16;
  *((s16 *) (((s8 *) arg0) + 0x48)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x4A)) = -0x3DFD;
  *((s8 *) (((s8 *) arg0) + 0xC8)) = 7;
  *((s16 *) (((s8 *) arg0) + 0x44)) = 0x118;
  *((s8 *) (((s8 *) arg0) + 0x81)) = 3;
  *((s16 *) (((s8 *) arg0) + 0xA0)) = 0x190;
  *((u8 *) (((s8 *) arg0) + 0xDD)) = 0xFF;
  *((s16 *) (((s8 *) arg0) + 0x46)) = 0x190;
  *((s16 *) (((s8 *) arg0) + 0x98)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x96)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x94)) = 0;
  *((s16 *) (((s8 *) arg0) + 0xAC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) & (~0x1000));
  *((s16 *) (((s8 *) arg0) + 0x60)) = rcos(0);
  *((s16 *) (((s8 *) arg0) + 0x64)) = rsin(*((s16 *) (((s8 *) arg0) + 0xAC)));
  if ((*((u16 *) (((s8 *) arg0) + 0x8C))) != 0)
  {
    Object_PlaceAtPathPoint(arg0, 0);
    func_8005866C(arg0, 1);
  }
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) | 0x2000);
  *((s32 *) (((s8 *) arg0) + 0x74)) = func_80057140(arg0, 9, 0);
  *((s8 *) (((s8 *) arg0) + 0x7C)) = -1;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 4;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = (u16) (*((u16 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x88)))) + 0x10)));
}

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013DE5C);

INCLUDE_ASM("asm/ovl/405/nonmatchings/405_hot_springs", func_8013E7B8);

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

void func_8013E8A4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern u8 D_8014117C[];

void func_8013E8FC(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        func_80070284(&v, D_8014117C, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013E998(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 func_8013E9C8(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013E9F8(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013EA34(void *arg0) {
    if ((func_8013E9C8(arg0) == 0) && (func_8013E9F8(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 func_8013E9C8(void *arg0);
s32 func_8013E9F8(void *arg0);
void func_8013EA34(void *arg0);
void func_8013E7B8(void *);
void func_8013E8A4(void *arg0);
void Object_TurnTowardSpike(void *);
void Object_TurnToward(void *, s16, s16, s32, s32);
s32 func_800572CC(void *);
s32 Object_DetachLink(void *, s32);

void func_8013EA88(u8 *o) {
    if (func_8013E998(o) != 0) {
        if (func_8013E9C8(o) != 0) {
            Object_TurnTowardSpike(o);
            M2C_FIELD(o, s16 *, 0xA8) = 1;
        } else {
            Object_TurnToward(o, M2C_FIELD(o, u16 *, 0x9A) - M2C_FIELD(o, u16 *, 0x24), M2C_FIELD(o, u16 *, 0x9E) - M2C_FIELD(o, u16 *, 0x2C), 0, M2C_FIELD(o, s16 *, 0xB0));
            M2C_FIELD(o, s16 *, 0xA8) = 0;
            if (func_8013E9F8(o) != 0) {
                o[0x80] = 5;
                o[0x7F] = 4;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(o[0x7F] * 4 + M2C_FIELD(o, u8 **, 0x88));
            }
        }
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(o[0x7F] * 4 + M2C_FIELD(o, u8 **, 0x88)) + 8) {
            func_8013E7B8(o);
        }
    } else {
        M2C_FIELD(o, s16 *, 0x96) += M2C_FIELD(o, s16 *, 0xA8);
        func_8013EA34(o);
        if (o[0xDD] == 0 && func_800572CC(o) != 0) {
            o[0xDD] = 1;
        }
    }
    if (Object_DetachLink(o, 0) == 6) {
        o[0x80] = 4;
        func_8005588C(o, 0x1E);
    } else {
        func_8013E8A4(o);
    }
}

void func_8013EBE8(s32 arg0) {
    if (func_8013E998() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013EC2C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013EC6C(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

typedef struct { u16 f0; u16 f2; } Anim_8013ECD4;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0x4]; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1F]; u8 f_7D; u8 pad7E[0x1]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[0x6]; Anim_8013ECD4 *anim; u8 pad8C[0xE]; s16 f_9A; u8 pad9C[0x2]; s16 f_9E; s16 f_A0; u8 padA2[0x2]; s16 f_A4; u8 padA6[0x2]; s16 f_A8; u8 padAA[0x6]; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 padC9[0x13]; u8 f_DC; u8 f_DD; u8 padDE[0x2]; u32 f_E0; } Obj_8013ECD4;
void func_80058134_8013ECD4(void *, s32) asm("func_80058134");
void func_8013E8FC(void *arg0);
void func_8013EA88(u8 *o);
void func_8013EBE8(s32 arg0);
void func_8013EC2C(void *arg0);
void func_8013EC6C(void *arg0);

void func_8013ECD4(Obj_8013ECD4 *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        o->f_B0 = 0x5B;
        o->f_A0 = 100;
        o->f_44 = 100;
        o->f_4A = -0x4000;
        o->f_81 = 12;
        o->f_7D = 7;
        o->f_C8 = 6;
        o->f_DC = 1;
        o->f_DD = 1;
        o->f_7F = 0;
        o->f_A8 = 0;
        o->f_E0 &= ~0x1000;
        o->f_5C = o->anim[0].f0;
        func_8005588C(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        o->f_E0 |= 8;
    }
    func_8013EC2C(o);
    func_80058134_8013ECD4(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 3;
    }
    switch (o->f_80) {
    case 1:
        if (Spike_WithinRadiusXZ(o->f_9A, o->f_9E, o->f_A4)) {
            o->f_80 = 2;
            o->f_7F = 2;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        if (func_8005588C(o, -1) == 0 && o->f_5C >= o->anim[o->f_7F].f2) {
            if (o->f_7F == 0) {
                o->f_7F = 1;
                o->f_5C = o->anim[o->f_7F].f0;
            } else {
                o->f_7F = 0;
                o->f_5C = o->anim[o->f_7F].f0;
                func_8005588C(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 10);
            }
        }
        break;
    case 2:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 3;
            o->f_7F = 3;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        break;
    case 3:
        func_8013EA88((u8 *)o);
        break;
    case 4:
        func_8013EBE8((s32)o);
        if (func_8005588C(o, -1) == 0) {
            o->f_80 = 3;
        }
        break;
    case 5:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 1;
            o->f_7F = 0;
            o->f_5C = o->anim[o->f_7F].f0;
            func_8005588C(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        }
        break;
    }
    func_8013E8FC(o);
    func_8013EC6C(o);
}

typedef struct { u16 start; u16 end; } Rng_8013EFBC;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013EFBC;
void func_80058134(void *, s32);
s32 Floor_GetHeight_8013EFBC(s32, s32, s32) asm("Floor_GetHeight");
s32 rcos_8013EFBC(s32) asm("rcos");
s32 rsin_8013EFBC(s32) asm("rsin");
void Shadow_Draw(void *, s32, s32, s32);

void func_8013EFBC(u8 *o) {
    s32 f;
    s32 ang;
    s32 dx;
    s32 dz;
    Vec_8013EFBC v;

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
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_8013EFBC **, 0x88)[0].start;
        if ((u8)(M2C_FIELD(o, u8 *, 0x7E) - 0x59) < 3) {
            M2C_FIELD(o, volatile u32 *, 0xE0) |= 0x80000;
            M2C_FIELD(o, u16 *, 0x5C) = ((*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88))) + (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2))) >> 1;
        } else {
            M2C_FIELD(o, u32 *, 0xE0) &= ~0x80000;
        }
        func_8005588C(o, 0);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xC9)) {
        M2C_FIELD(o, u8 *, 0xC9)--;
    } else {
        func_8005588C(o, 0x16);
        if (Spike_WithinRadiusXZ(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), 0x800)) {
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
        dx = rcos_8013EFBC(ang) * 797 >> 12;
        dz = rsin_8013EFBC(ang) * 797 >> 12;
        Object_AddAttackSphereNear(o, 0x78, M2C_FIELD(o, u16 *, 0x24) + dx, M2C_FIELD(o, s16 *, 0x28), (s16)(M2C_FIELD(o, u16 *, 0x2C) + dz), 1, 0x203);
        v.vx = M2C_FIELD(o, s32 *, 0x24) + dx;
        v.vy = M2C_FIELD(o, s32 *, 0x28);
        v.vz = M2C_FIELD(o, s32 *, 0x2C) + dz;
        Shadow_Draw(&v, Floor_GetHeight_8013EFBC(v.vx, v.vy, v.vz), 100, *(s32 *)0x1F8003FC);
    }
}

void func_8013F2EC(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void Matrix_FromDirection(void *, s32);
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern u8 D_80141380[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F38C asm("g_Game");

void func_8013F38C(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80141380 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game_8013F38C.f_80 + g_Game_8013F38C.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { u8 pad0[0xC]; s16 active; u8 padE[6]; } Drip_405;
extern Drip_405 D_801412E0_s[8] asm("D_801412E0");

void func_8013F454(void *arg0) {
    s32 i;

    func_8013F2EC(arg0, D_80141380, 0x83);
    for (i = 7; i >= 0; i--) {
        D_801412E0_s[i].active = 0;
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801412E0");

s32 func_8013F49C(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013F4D8;
extern Drip_8013F4D8 D_801412E0_8013F4D8[8] asm("D_801412E0");
s32 func_8013F49C(void);

M2C_UNK func_8013F4D8(void *arg0, M2C_UNK dy, M2C_UNK r) {
    u8 *o = arg0;
    s32 i;
    Drip_8013F4D8 *d;
    s16 c;
    s16 s;

    i = func_8013F49C();
    if (i != -1) {
        d = &D_801412E0_8013F4D8[i];
        c = rcos(M2C_FIELD(o, s16 *, 0xAC));
        s = rsin(M2C_FIELD(o, s16 *, 0xAC));
        d->x = M2C_FIELD(o, u16 *, 0x24) + (c * (s16)r >> 12);
        d->y = M2C_FIELD(o, u16 *, 0x28) - dy;
        d->z = M2C_FIELD(o, u16 *, 0x2C) + (s * (s16)r >> 12);
        d->vx = c / 48;
        d->vz = s / 48;
        d->vy = -40;
        d->active++;
        d->unkE = M2C_FIELD(o, s8 *, 0xCB);
        Object_PlaySound(o, 0x77);
    }
}

s32 func_8013F618(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013F654(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013F694(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013F6D4;
extern Drip_8013F6D4 D_801412E0_8013F6D4[8] asm("D_801412E0");
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013F6D4;
extern M_8013F6D4 D_80141380_8013F6D4 asm("D_80141380");
s32 Object_DetachLink_8013F6D4(void *, s32) asm("Object_DetachLink");
s32 Object_AddAttackSphere_8013F6D4(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void VectorNormalSS(void* v0, void* v1);
void func_8013F38C(s32 arg0, s32 arg1);
s32 func_8013F618(void *arg0);
void func_8013F654(SVECTOR *arg0);
void func_8013F694(SVECTOR *arg0);

void func_8013F6D4(void *arg0) {
    Drip_8013F6D4 *p;
    M_8013F6D4 *m;
    s32 i;
    s32 r;

    m = &D_80141380_8013F6D4;
    for (i = 7; i >= 0; i--) {
        p = &D_801412E0_8013F6D4[i];
        if (p->active != 0 && p->unkE == M2C_FIELD(arg0, s8 *, 0xCB)) {
            p->active++;
            p->vy += 4;
            func_8013F654((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            r = Object_DetachLink_8013F6D4(arg0, 0);
            if (func_8013F618(p) || M2C_FIELD(arg0, s32 *, 0x28) + 0x600 < p->y || r == 6) {
                p->active = 0;
                func_8013F694((SVECTOR *)p);
                Object_PlaySound(arg0, 0x4D);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->vx = p->vx;
                m->vy = p->vy;
                m->vz = p->vz;
                VectorNormalSS(&m->vx, &m->vx);
                func_8013F38C(0, 3);
                M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere_8013F6D4(arg0, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013F89C(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800573A0(void *, s32, s32, s32);

void func_8013F8C8(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013F958(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013F89C(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}


void func_8013F9E8(void *obj) {
    func_8013F4D8(obj, 0x46, 0xA0);
}

void Object_DisableCollision(void *);

void func_8013FA0C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
    M2C_FIELD(arg0, u8 *, 0x7D) = 8;
    M2C_FIELD(arg0, u8 *, 0xC8) = 0xE;
    M2C_FIELD(arg0, u8 *, 0xCD) = 5;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u8 *, 0xDC) = 5;
    M2C_FIELD(arg0, s16 *, 0xA0) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    func_8005588C(arg0, (s16)(M2C_FIELD(arg0, s16 *, 0x9A) % 60) + 0x3C);
    func_8013F454(arg0);
    Object_DisableCollision(arg0);
}

typedef struct { u16 start; u16 end; } Anim_8013FAEC;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0xA]; u32 f_50; u8 pad54[0x8]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[0x7]; Anim_8013FAEC *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[0x3E]; u32 f_E0; } O_8013FAEC;
void func_8013F6D4(void *arg0);
void func_8013F89C(void *arg0);
void func_8013F8C8(void *arg0);
void func_8013F958(void *arg0);
void func_8013F9E8(void *obj);
void func_8013FA0C(void *arg0);
M2C_UNK Object_StepOnGroundFixed_8013FAEC(void *) asm("Object_StepOnGroundFixed");
void Object_TurnTowardSpike_8013FAEC(void *) asm("Object_TurnTowardSpike");
void func_80058134_8013FAEC(void *, s32) asm("func_80058134");
void func_80055C7C_8013FAEC(void *, s32) asm("func_80055C7C");
void func_80055D28_8013FAEC(void *, s32, s32) asm("func_80055D28");
void Object_EnableCollision_8013FAEC(void *) asm("Object_EnableCollision");
s32 Object_SpikeInFront_8013FAEC(void *, s32, s32, s32) asm("Object_SpikeInFront");
s32 Object_SpikeNearXZ_8013FAEC(void *, s32) asm("Object_SpikeNearXZ");

void func_8013FAEC(O_8013FAEC *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        func_8013FA0C(o);
        o->f_E0 |= 8;
    }
    func_80058134_8013FAEC(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 6;
        o->f_7F = 0;
        o->f_5C = o->f_88[0].start;
        func_8013F89C(o);
    }
    switch (o->f_80) {
    case 1:
        o->f_5C = o->f_88[o->f_7F].start;
        func_80055C7C_8013FAEC(o, 0x3C);
        Object_StepOnGroundFixed_8013FAEC(o);
        if (func_8005588C(o, -1) == 0) {
            func_8013F958(o);
            Object_EnableCollision_8013FAEC(o);
        }
        break;
    case 3:
        o->f_A0 += 5;
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 2;
            o->f_7F = 2;
            o->f_5C = o->f_88[2].start;
        }
        break;
    case 2:
        if (Object_SpikeInFront_8013FAEC(o, 0x168, -0x1000, 0x800)) {
            o->f_80 = 7;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
            Object_PlaySound(o, 0x61);
            break;
        }
        if (Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x300)) {
            o->f_80 = 8;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 8:
        Object_TurnTowardSpike_8013FAEC(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
            func_8013F89C(o);
        }
        break;
    case 7:
        Object_TurnTowardSpike_8013FAEC(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 4;
            o->f_7F = 3;
            o->f_5C = o->f_88[3].start;
        }
        break;
    case 4:
        Object_TurnTowardSpike_8013FAEC(o);
        if ((o->f_50 >> 28) == 6 || !Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x800) || Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x300)) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
            func_8013F89C(o);
            break;
        }
        if (o->f_5C == o->f_88[o->f_7F].start + 0x14) {
            func_8013F9E8(o);
        }
        break;
    case 5:
        if (Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x300) || !Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x800) || !Object_SpikeNearXZ_8013FAEC(o, 0x600)) {
            o->f_80 = 6;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            if (Object_SpikeInFront_8013FAEC(o, 0xB4, 0, 0x800)) {
                o->f_80 = 4;
                o->f_7F = 3;
                o->f_5C = o->f_88[3].start;
                Object_TurnTowardSpike_8013FAEC(o);
            } else {
                o->f_80 = 6;
                o->f_7F = 0;
                o->f_5C = o->f_88[0].start;
                func_8013F89C(o);
            }
        }
        break;
    case 6:
        if (o->f_A0 != 0) {
            o->f_A0 -= 5;
        }
        Object_DisableCollision(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_A0 = 0;
            func_8005588C(o, 0x2D);
            o->f_80 = 1;
            o->f_7F = 1;
            o->f_5C = o->f_88[1].start;
            func_80055D28_8013FAEC(o, 0x3C, 0);
            func_8013F89C(o);
        }
        break;
    }
    func_8013F8C8(o);
    func_8013F6D4(o);
}

s32 Math_Atan2(s32, s32);

void func_8013FFD4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_80140060(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_80140098(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

s32 Object_DetachLink(void *, s32);
void Object_StepGrowShrink(void *, s32, s32, s32);

void func_80140160(u8 *arg0) {
    s16 *v;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        func_8013FFD4(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), M2C_FIELD(arg0, s16 *, 0xA8) >> 3) != 0) {
        func_8013FFD4(arg0);
        return;
    }
    v = (s16 *)(arg0 + 0x60);
    v[0] = M2C_FIELD(arg0, s16 *, 0x94);
    v[1] = M2C_FIELD(arg0, s16 *, 0x96);
    v[2] = M2C_FIELD(arg0, s16 *, 0x98);
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity(arg0);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, M2C_FIELD(arg0, s16 *, 0x44) + 0x32, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28) - 0x1E, M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x103);
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F21C asm("g_Spike");

void func_80140284(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F21C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F21C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F21C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void func_801402D4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x200000;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x96) >= 0x39) {
        M2C_FIELD(arg0, u8 *, 0x82) = 0;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x100000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
    }
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_80140348 asm("g_Spike");
void func_80055F1C(void *, s32);
void func_80058134_80140348(void *, s32) asm("func_80058134");
void func_801402D4(void *arg0);
void func_80055E6C(void *, s32);
void Object_TurnToward_80140348(void *, s16, s16, s32, s32) asm("Object_TurnToward");
void func_80140284(void *arg0);
void func_8013FFD4(void *arg0);
void func_80140098(void *arg0);
void func_80140060(void *arg0);
void func_80054220(void *);
#define ANIM_80140348(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_80140348(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 50;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 60;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 100;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0x81) = 6;
        M2C_FIELD(o, u8 *, 0xDC) = 8;
        M2C_FIELD(o, s16 *, 0x9C) -= 200;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x200000;
        M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140348(o, 0)[0];
        func_80055F1C(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_80140348(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0xC00000;
        func_801402D4(o);
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_80055E6C(o, 8);
        Object_SeekHeight(o, 8);
        func_800563E0(o, 20);
        if (func_8005588C(o, -1) == 0 && Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
            func_80140060(o);
        }
        break;
    case 2:
        Object_TurnToward_80140348(o, g_Spike_80140348.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80140348.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] - 10) {
            func_80140284(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
            if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                Object_PlaySound(o, 0xA6);
            }
        }
        func_80140160(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            func_8013FFD4(o);
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] && M2C_FIELD(o, u8 *, 0x7F) != 4) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140348(o, 4)[0];
        }
        break;
    case 4:
        func_80140098(o);
        break;
    case 5:
        Object_TurnToward_80140348(o, g_Spike_80140348.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80140348.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            if (Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
                func_80140060(o);
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, u8 *, 0xC9) = 0;
            }
        }
        break;
    }
    func_80054220(o);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

s32 func_801406E0(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(temp_v1, u16 *, 0x26) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80140730 asm("g_Spike");
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140730 asm("g_Game");
extern s16 D_800EC238;
extern u8 *D_800B4D64;
void Sound_PlayAt(s32, void *);
s32 SquareRoot0(s32);

s32 func_80140730(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140730.f_820C + p[2] * 0x38);
    s32 dx, dy, dz;
    SVECTOR unused;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] > p[4]) {
            p[1] = 2;
            p[3] = 0;
            Sound_PlayAt(0xB1, e);
        }
        break;
    case 2:
        p[3] += p[5];
        if (p[3] > p[6]) {
            p[1] = 3;
            p[3] = 0;
            e[0xC] |= 0x8000;
            e[1] = e[0x13];
            if (e[7] >= 0) {
                M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
                M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x16) = 0;
            }
        } else {
            e[1] += p[3];
            if (e[7] >= 0) {
                M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
            }
        }
        break;
    case 3:
        dx = g_Spike_80140730.x - e[0];
        dy = g_Spike_80140730.y - e[1];
        dz = g_Spike_80140730.z - e[2];
        if (SquareRoot0(dx * dx + dy * dy + dz * dz) > p[7]) {
            p[1] = 0;
            p[3] = 0;
            e[0xC] &= 0x7FFF;
            if (e[7] >= 0) {
                M2C_FIELD(D_800B4D64 + e[7] * 32, u16 *, 0x16) = 0xFFFF;
            }
        }
        break;
    }
    return 0;
}

s32 func_80140968(s16 *p) {
    p[1] = 0;
    p[3] = 0;
    p[9] = -1;
    p[10] = ((RAND() >> 8) & 7) * 30;
    return 0;
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801409B0 asm("g_Spike");
s32 Sound_Play(s32, s32);
void Sound_UpdateVoice3D(s32, s32, s32, void *);
void Sound_Stop(s32, s32);
void *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 func_801409B0(s16 *p) {
    SVECTOR v;
    SVECTOR w;
    s32 i;
    u8 *c;

    switch (p[1]) {
    case 0:
        if (++p[3] > p[10]) {
            p[3] = 0;
            p[1] = 1;
        }
        break;
    case 1:
        if (++p[3] > 20) {
            p[3] = 0;
            p[1] = 2;
            p[9] = Sound_Play(1, 0xB2);
        }
        v.vx = p[4] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
        v.vy = p[5] - ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) + 0x20);
        v.vz = p[6] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
        Effect_SpawnAt(5, &v);
        break;
    case 2:
        if (++p[3] > 12) {
            p[1] = 3;
            break;
        }
        Sound_UpdateVoice3D(0xB2, p[9], 0x1000, &p[4]);
        for (i = 0; i < p[3]; i++) {
            v.vx = p[4] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
            v.vy = p[5] - ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) + 0x20) - (i << 7);
            v.vz = p[6] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
            Effect_SpawnAt(5, &v);
        }
        if ((u32)SquareRoot0((g_Spike_801409B0.x - p[4]) * (g_Spike_801409B0.x - p[4]) + (g_Spike_801409B0.z - p[6]) * (g_Spike_801409B0.z - p[6])) < 0xC0
            && g_Spike_801409B0.y < p[5] + 0x40 && p[5] - (p[3] << 7) < g_Spike_801409B0.y) {
            w.vx = g_Spike_801409B0.x - p[4];
            w.vy = g_Spike_801409B0.y - p[5];
            w.vz = g_Spike_801409B0.z - p[6];
            VectorNormalSS(&w, &w);
            c = CollShape_Alloc();
            if (c != NULL) {
                *(SVECTOR *)(c + 0x18) = w;
                M2C_FIELD(c, s32 *, 0) = p[4];
                M2C_FIELD(c, s32 *, 4) = p[5];
                M2C_FIELD(c, s32 *, 8) = p[6];
                M2C_FIELD(c, s16 *, 0x20) = 0x80;
                M2C_FIELD(c, s16 *, 0x24) = 1;
                M2C_FIELD(c, s16 *, 0x26) = 0x202;
                Collision_Set(6, c, 0);
            }
        }
        break;
    case 3:
        p[3] -= 2;
        if (p[3] < 0) {
            p[3] = 0;
            p[1] = 0;
            p[10] = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7) * 30;
            Sound_Stop(0xB2, p[9]);
            break;
        }
        Sound_UpdateVoice3D(0xB2, p[9], 0x1000, &p[4]);
        for (i = 0; i < p[3]; i++) {
            v.vx = p[4] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
            v.vy = p[5] - ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) + 0x20) - (i << 7);
            v.vz = p[6] + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F);
            Effect_SpawnAt(5, &v);
        }
        if ((u32)SquareRoot0((g_Spike_801409B0.x - p[4]) * (g_Spike_801409B0.x - p[4]) + (g_Spike_801409B0.z - p[6]) * (g_Spike_801409B0.z - p[6])) < 0xC0
            && g_Spike_801409B0.y < p[5] + 0x40 && p[5] - (p[3] << 7) < g_Spike_801409B0.y) {
            w.vx = g_Spike_801409B0.x - p[4];
            w.vy = g_Spike_801409B0.y - p[5];
            w.vz = g_Spike_801409B0.z - p[6];
            VectorNormalSS(&w, &w);
            c = CollShape_Alloc();
            if (c != NULL) {
                *(SVECTOR *)(c + 0x18) = w;
                M2C_FIELD(c, s32 *, 0) = p[4];
                M2C_FIELD(c, s32 *, 4) = g_Spike_801409B0.y;
                M2C_FIELD(c, s32 *, 8) = p[6];
                M2C_FIELD(c, s16 *, 0x20) = 0xC4;
                M2C_FIELD(c, s16 *, 0x24) = 1;
                M2C_FIELD(c, s16 *, 0x26) = 0x202;
                Collision_Set(6, c, 0);
            }
        }
        break;
    }
    return 0;
}

extern u32 g_Game_80140F94 asm("g_Game");
void Sound_PlayAt(s32, void *);

s32 func_80140F94(u8 *arg0) {
    if (g_Game_80140F94 % 10 == 0) {
        Sound_PlayAt(((RAND() >> 8) & 3) + 0xB6, arg0 + 8);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
