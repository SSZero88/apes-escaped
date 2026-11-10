#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK Object_KeepAwayFromSpike(s32, M2C_UNK);
M2C_UNK Object_ApplyHit();
M2C_UNK Object_HitFeedback(void *);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
M2C_UNK Object_FlyAboveFloor(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void Effect_SpawnAt(s32, SVECTOR *);
extern u8 D_800B1C28[];

void Brute_SpawnHitBurst(void *arg0, s32 dx, s32 dy, s32 dz) {
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
        Shockwave_Spawn(&v, D_800B1C28, 1, i * 2, &r);
    }
}

extern struct { u8 pad0[0x24]; s32 x; u8 pad28[4]; s32 z; } g_Spike_8013D100 asm("g_Spike");
s32 Math_Atan2(s32, s32);
void Brute_SpawnHitBurst(void *arg0, s32 dx, s32 dy, s32 dz);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);

s32 Brute_CheckHit(u8 *arg0) {
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
    Brute_SpawnHitBurst(arg0, 0, -200, 0);
    Object_PlaySound(arg0, 0xB4);
    Sound_PlayFixed(0x5F);
    Sound_PlayFixed(0x15);
    return 1;
}

s16 Object_FloorAt(void *, s16, s16, s16);

s32 Brute_FloorDropAhead(u8 *o) {
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

s32 Brute_FloorDropAhead(u8 *o);
void Object_StepGrowShrink(void *, s32, s32, s32);

void Brute_SetSlideVelocity(void *arg0, s32 arg1, s32 arg2) {
    Object_StepGrowShrink(arg0, 0, 0, (s16)arg1);
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * ((s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13)) >> 0xC);
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * ((s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13)) >> 0xC);
    if (arg2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x94) = M2C_FIELD(arg0, s16 *, 0x94) * -1;
        M2C_FIELD(arg0, s16 *, 0x98) = M2C_FIELD(arg0, s16 *, 0x98) * -1;
    }
    Brute_FloorDropAhead(arg0);
}

s32 func_8013D2FC_8013D3B4(void *, s32, s32) asm("Brute_SetSlideVelocity");
s32 Object_WouldLeaveHome_8013D3B4(void *, s32) asm("Object_WouldLeaveHome");
void Object_ApplyVelocity(void *);

s32 Brute_StepKnockback(u8 *o) {
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

void Brute_StepRecoil(void *arg0) {
    if (!(M2C_FIELD(arg0, u16 *, 0xE2) & 1)) {
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 0x10) {
            Brute_SetSlideVelocity(arg0, -5, 0);
        } else {
            Brute_SetSlideVelocity(arg0, -10, 1);
        }
        Object_ApplyVelocity(arg0);
    }
}

extern struct { u8 pad0[0x24]; s32 x; u8 pad28[4]; s32 z; } g_Spike_8013D520 asm("g_Spike");

/* called without all its arguments (old-style declaration), so defined old-style */
s32 Brute_SpikeOutsideHome(arg0)
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

void Brute_GiveUpChase(void *arg0) {
    if (Brute_SpikeOutsideHome() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

s32 Brute_StepKnockback(u8 *o);
void Object_AddDamageSphereAt(void *, void *, s16, s16);
void Object_CameraShake(void *, s32);
void Pad_Vibrate(s32, s32, s32);
void Rock_SpawnBurst(void *, void *);
extern s32 D_800B1CD0[];
extern u8 D_80141164[];

void Brute_UpdateLanding(u8 *o) {
    SVECTOR v;
    SVECTOR p;
    s32 i;

    if (Brute_StepKnockback(o)) {
        M2C_FIELD(o, s16 *, 0x44) = 1;
        v.vx = M2C_FIELD(o, u16 *, 0x24);
        v.vy = M2C_FIELD(o, u16 *, 0x28) - M2C_FIELD(o, s16 *, 0x46) / 2;
        v.vz = M2C_FIELD(o, u16 *, 0x2C);
        Object_AddDamageSphereAt(o, &v, 300, 0x204);
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
        Shockwave_Spawn(&v, D_800B1CD0, 1, 0, o + 0x60);
        Rock_SpawnBurst(&v, D_80141164);
        Rock_SpawnBurst(&v, D_80141164 + 0xC);
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

extern u32 g_Game_8013D7AC asm("g_Game");
extern u16 g_RandSeed2;
void Effect_SpawnAt_8013D7AC(s32, SVECTOR *) asm("Effect_SpawnAt");
#define RAND2_8013D7AC() (g_RandSeed2 = g_RandSeed2 * 5 + 1)

void Brute_SpawnBreath(u8 *o, SVECTOR *p) {
    SVECTOR v;
    s32 n;

    if (o[0x7F] == 2) {
        n = 15;
    } else if (o[0x7F] == 4) {
        n = 60;
    } else {
        n = 30;
    }
    if (g_Game_8013D7AC % n < 5) {
        v.vx = p->vx + (M2C_FIELD(o, s16 *, 0x60) * 75 >> 11) + ((s32)((RAND2_8013D7AC() >> 8) * 5U >> 6) - 10);
        { s32 t = (s32)((RAND2_8013D7AC() >> 8) * 5U >> 6) + 0x28; v.vy = p->vy + t; }
        { s32 r = (RAND2_8013D7AC() >> 8); v.vz = p->vz + (M2C_FIELD(o, s16 *, 0x64) * 75 >> 11) + ((s32)(r * 5U >> 6) - 10); }
        Effect_SpawnAt_8013D7AC(4, &v);
    }
}

extern struct { u32 f_0; } g_Game_8013D904 asm("g_Game");

void Brute_UpdateModel(u8 *o) {
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
        Object_SetModel(o, a);
        M2C_FIELD(o, u8 *, 0xDD) = a;
    }
}

#define ANIM_8013D9EC(a) ((u16 *)(M2C_FIELD(a, u8 **, 0x88) + (a)[0x7F] * 4))

void Brute_BlendToAnim(u8 *a, u8 next) {
    u16 *an = (u16 *)(a[0x7F] * 4 + (u32)M2C_FIELD(a, u8 **, 0x88));
    s32 len = an[1];
    s32 st = an[0];
    s32 cur;
    s32 d;

    len -= st;
    cur = M2C_FIELD(a, u16 *, 0x5C);
    d = cur - st;
    if (len / 2 < d) {
        M2C_FIELD(a, u16 *, 0x5C) = cur + 2;
        if (M2C_FIELD(a, u16 *, 0x5C) >= ANIM_8013D9EC(a)[1]) {
            a[0x7F] = next;
            M2C_FIELD(a, u16 *, 0x5C) = ANIM_8013D9EC(a)[0];
        }
    } else if (st >= cur - 3) {
        a[0x7F] = next;
        M2C_FIELD(a, u16 *, 0x5C) = ANIM_8013D9EC(a)[0];
    } else {
        M2C_FIELD(a, u16 *, 0x5C) = cur - 3;
    }
}

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 Brute_TryAttack(void *arg0) {
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

void Brute_StepFlying(u8 *o) {
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

void Brute_FootstepShake(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1 || d == f2) {
        Object_PlaySound(arg0, 0x43);
        Camera_StartShake(0);
    }
}

M2C_UNK Object_PlaceAtPathPoint(void *, M2C_UNK);
s32 Object_AddAttachPoint(void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_FacePathPoint(void *, M2C_UNK);

void Brute_Init(void *arg0)
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
    Object_FacePathPoint(arg0, 1);
  }
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) | 0x2000);
  *((s32 *) (((s8 *) arg0) + 0x74)) = Object_AddAttachPoint(arg0, 9, 0);
  *((s8 *) (((s8 *) arg0) + 0x7C)) = -1;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 4;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = (u16) (*((u16 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x88)))) + 0x10)));
}

typedef struct { u16 start; u16 end; } Anim_8013DE5C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[4]; u32 f_50; u8 pad54[8]; u16 f_5C; u8 pad5E[2]; SVECTOR f_60; u8 pad68[0xC]; SVECTOR *f_74; u8 pad78[4]; s8 f_7C; u8 pad7D[2]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[6]; Anim_8013DE5C *f_88; u8 pad8C[0xE]; s16 f_9A; u8 pad9C[2]; s16 f_9E; u8 padA0[6]; s16 f_A6; u8 padA8[8]; s16 f_B0; u8 padB2[0x2E]; u32 f_E0; } O_8013DE5C;
extern struct { u32 f_0; } g_Game_8013DE5C asm("g_Game");
extern u16 D_800EC23E;
extern SVECTOR Fx_SpikeChestPos;
extern u8 Shockwave_Templates[];
extern u8 D_80141150[];
extern u8 D_80141158[];
s32 Brute_CheckHit(u8 *arg0);
void Brute_StepRecoil(void *arg0);
void Brute_GiveUpChase(void *arg0);
void Brute_UpdateLanding(u8 *o);
void Brute_SpawnBreath(u8 *o, SVECTOR *p);
void Brute_UpdateModel(u8 *o);
void Brute_BlendToAnim(u8 *a, u8 next);
s32 Brute_TryAttack(void *arg0);
void Brute_StepFlying(u8 *o);
void Brute_FootstepShake(void *arg0, s32 f1, s32 f2);
void Effect_Spawn_8013DE5C(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
s32 Math_WithinSquare_8013DE5C(s32, s32, s32) asm("Math_WithinSquare");
s32 Object_AddAttackSphereNear_8013DE5C(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
void Object_ChaseSpike_8013DE5C(void *, s32) asm("Object_ChaseSpike");
s32 Object_SpikeNearXZ_8013DE5C(void *, s32) asm("Object_SpikeNearXZ");
void Object_TurnTowardSpike_8013DE5C(void *) asm("Object_TurnTowardSpike");
s8 Sound_ReserveSlot_8013DE5C(s32, s32, void *) asm("Sound_ReserveSlot");
void func_80055AA0_8013DE5C(void *, s32, s32, s32) asm("Object_StepTowardXZ");
void func_80058134_8013DE5C(void *, s32) asm("Object_DebugStub");
void func_80070284_8013DE5C(void *, void *, s32, s32, void *) asm("Shockwave_Spawn");
void func_80088120_8013DE5C(s32) asm("Sound_FreeSlot");

void Brute_Update(O_8013DE5C *o) {
    SVECTOR v;
    s32 t;
    s32 n;
    s32 f;

    if (!((o->f_E0 >> 3) & 1)) {
        Brute_Init(o);
        o->f_E0 |= 8;
    }
    func_80058134_8013DE5C(o, o->f_44);
    if (o->f_7F == 2) {
        o->f_B0 = 0x2D;
    } else {
        o->f_B0 = 0x16;
    }
    Brute_SpawnBreath((u8 *)o, o->f_74);
    switch (o->f_80) {
    case 1:
        if (o->f_7C == -1) {
            o->f_7C = Sound_ReserveSlot_8013DE5C(0x70B3, 0x1000, &o->f_24);
        }
        if (Object_SpikeNearXZ_8013DE5C(o, o->f_A6)) {
            o->f_80 = 2;
            o->f_7F = 5;
            o->f_5C = o->f_88[5].start;
            if (o->f_7C != -1) {
                func_80088120_8013DE5C(o->f_7C);
            }
            o->f_7C = -1;
            Object_PlaySound(o, 0xB4);
        }
        break;
    case 2:
        if (++o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 3;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 3:
        Brute_FootstepShake(o, 0x10, 0x38);
        Object_ChaseSpike_8013DE5C(o, 5);
        Object_ApplyVelocity(o);
        if (Brute_TryAttack(o) == 0 && Brute_CheckHit((u8 *)o) == 0 && o->f_5C >= o->f_88[o->f_7F].end) {
            if (Object_SpikeNearXZ_8013DE5C(o, 0x600)) {
                o->f_80 = 18;
                o->f_7F = 15;
                o->f_5C = o->f_88[15].start;
            }
            Brute_GiveUpChase(o);
        }
        break;
    case 18:
        Object_ChaseSpike_8013DE5C(o, 5);
        Object_ApplyVelocity(o);
        if (Brute_TryAttack(o) == 0 && Brute_CheckHit((u8 *)o) == 0 && o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 4;
            o->f_7F = 2;
            o->f_5C = o->f_88[2].start;
        }
        break;
    case 4:
        Brute_FootstepShake(o, 9, 0x10);
        Object_ChaseSpike_8013DE5C(o, 0x1E);
        Object_ApplyVelocity(o);
        Brute_TryAttack(o);
        Brute_CheckHit((u8 *)o);
        Brute_GiveUpChase(o);
        break;
    case 5:
        Object_TurnTowardSpike_8013DE5C(o);
        if (Brute_CheckHit((u8 *)o) == 0) {
            if (o->f_7F != 3) {
                Brute_BlendToAnim((u8 *)o, 3);
            } else {
                t = o->f_5C - o->f_88[o->f_7F].start;
                if (t == 0x14 || t == 0x21) {
                    Object_PlaySound(o, 0x6D);
                }
                if (t == 0x18 || t == 0x25) {
                    Object_AddAttackSphereNear_8013DE5C(o, 0xC8, o->f_24 + (o->f_60.vx * 0x7D >> 10), o->f_28 - o->f_46 / 2, (s16)(o->f_2C + (o->f_60.vz * 0x7D >> 10)), o->f_48, o->f_4A);
                }
                if ((t == 0x19 || t == 0x26) && (o->f_50 >> 28) == 6 && (D_800EC23E < 0x1D0 || D_800EC23E > 0x210)) {
                    Rock_SpawnBurst(&Fx_SpikeChestPos, D_80141158);
                    Effect_SpawnAt(0x112, &Fx_SpikeChestPos);
                    func_80070284_8013DE5C(&Fx_SpikeChestPos, Shockwave_Templates, 1, 0, &o->f_60);
                }
                if (o->f_5C >= o->f_88[o->f_7F].end) {
                    o->f_80 = 14;
                    o->f_7F = 1;
                    o->f_5C = o->f_88[1].start;
                }
            }
        }
        break;
    case 14:
        if (Brute_CheckHit((u8 *)o) == 0 && o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 3;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 6:
        if (o->f_5C == o->f_88[o->f_7F].end && o->f_7F != 7) {
            o->f_7F = 7;
            o->f_5C = o->f_88[7].start;
        }
        Brute_StepFlying((u8 *)o);
        break;
    case 7:
        Brute_UpdateLanding((u8 *)o);
        break;
    case 8:
        Brute_StepRecoil(o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_44 = 0x118;
            o->f_80 = 9;
            o->f_7F = 10;
            o->f_5C = o->f_88[10].start;
        }
        break;
    case 9:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 10;
            o->f_7F = 9;
            o->f_5C = o->f_88[9].start;
        }
        break;
    case 10:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 3;
            o->f_7F = 0;
            o->f_5C = o->f_88[0].start;
        }
        break;
    case 11:
        if (o->f_7F == 0) {
            Brute_FootstepShake(o, 0x10, 0x38);
            if (Brute_SpikeOutsideHome(o) == 0) {
                o->f_80 = 18;
                o->f_7F = 15;
                o->f_5C = o->f_88[15].start;
            } else {
                func_80055AA0_8013DE5C(o, o->f_9A, o->f_9E, 5);
            }
        } else {
            func_80055AA0_8013DE5C(o, o->f_9A, o->f_9E, 0x1E);
        }
        Object_ApplyVelocity(o);
        if (Math_WithinSquare_8013DE5C(o->f_9A - o->f_24, o->f_9E - o->f_2C, 0xC8)) {
            o->f_80 = 20;
        }
        Brute_CheckHit((u8 *)o);
        break;
    case 20:
        Object_ApplyVelocity(o);
        Brute_CheckHit((u8 *)o);
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            if (Brute_SpikeOutsideHome(o)) {
                o->f_80 = 19;
                o->f_7F = 5;
                o->f_5C = o->f_88[5].start;
                o->f_5C = o->f_88[o->f_7F].end - 1;
            } else {
                o->f_80 = 3;
                o->f_7F = 0;
                o->f_5C = o->f_88[0].start;
            }
        }
        break;
    case 19:
        o->f_5C -= 2;
        if (o->f_5C <= o->f_88[o->f_7F].start) {
            o->f_80 = 1;
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
        }
        break;
    case 12:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_44 = 0x118;
            o->f_80 = 13;
            o->f_7F = 12;
            o->f_5C = o->f_88[12].start;
            Object_Timer(o, 0x78);
        }
        break;
    case 13:
        if (Object_Timer(o, -1) == 0) {
            o->f_80 = 17;
            o->f_7F = 13;
            o->f_5C = o->f_88[13].start;
            o->f_81 = 3;
            Object_PlaySound(o, 0xB4);
        }
        break;
    case 17:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            o->f_80 = 9;
            o->f_7F = 10;
            o->f_5C = o->f_88[10].start;
        }
        break;
    }
    Brute_UpdateModel((u8 *)o);
    if (o->f_7F == 12 || o->f_7F == 8) {
        f = g_Game_8013DE5C.f_0 & 3;
        v.vx = o->f_24 + o->f_60.vx / 16;
        v.vy = o->f_28 - 0x1B8;
        v.vz = o->f_2C + o->f_60.vz / 16;
        if (f == 0) {
            Effect_Spawn_8013DE5C(0xC8, &v, D_80141150, 0);
        } else if (f == 2) {
            Effect_Spawn_8013DE5C(0xC9, &v, D_80141150, 0);
        }
    }
}

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013D000 asm("g_Spike");
s32 Vec_Length(s32, s32, s32);

void Hopper_StartJump(void *arg0) {
    s32 v;

    M2C_FIELD(arg0, s16 *, 0x96) = -(M2C_FIELD(arg0, s16 *, 0xA8) + 7) * 0xB;
    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        v = Vec_Length(g_Spike_8013D000.x - M2C_FIELD(arg0, s32 *, 0x24), 0,
                       g_Spike_8013D000.z - M2C_FIELD(arg0, s32 *, 0x2C)) / 22;
    } else {
        v = 0x11;
    }
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    M2C_FIELD(arg0, u8 *, 0xDD) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) | 0x400) & ~0x20;
    M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * v) >> 12;
    M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * v) >> 12;
    Object_PlaySound(arg0, 0x68);
}

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

void Hopper_AddAttackSphere(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void Shockwave_Spawn(SVECTOR *, void *, s32, s32, s32);
extern u8 D_8014117C[];

void Hopper_LandShockwave(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        Shockwave_Spawn(&v, D_8014117C, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 Hopper_IsOnGround(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 Hopper_SpikeInHome(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 Hopper_IsAtHome(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void Hopper_SnapHome(void *arg0) {
    if ((Hopper_SpikeInHome(arg0) == 0) && (Hopper_IsAtHome(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 Hopper_SpikeInHome(void *arg0);
s32 Hopper_IsAtHome(void *arg0);
void Hopper_SnapHome(void *arg0);
void Hopper_AddAttackSphere(void *arg0);
void Object_TurnTowardSpike(void *);
void Object_TurnToward(void *, s16, s16, s32, s32);
s32 Object_UpdateLeap(void *);
s32 Object_DetachLink(void *, s32);

void Hopper_UpdateHopping(u8 *o) {
    if (Hopper_IsOnGround(o) != 0) {
        if (Hopper_SpikeInHome(o) != 0) {
            Object_TurnTowardSpike(o);
            M2C_FIELD(o, s16 *, 0xA8) = 1;
        } else {
            Object_TurnToward(o, M2C_FIELD(o, u16 *, 0x9A) - M2C_FIELD(o, u16 *, 0x24), M2C_FIELD(o, u16 *, 0x9E) - M2C_FIELD(o, u16 *, 0x2C), 0, M2C_FIELD(o, s16 *, 0xB0));
            M2C_FIELD(o, s16 *, 0xA8) = 0;
            if (Hopper_IsAtHome(o) != 0) {
                o[0x80] = 5;
                o[0x7F] = 4;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(o[0x7F] * 4 + M2C_FIELD(o, u8 **, 0x88));
            }
        }
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(o[0x7F] * 4 + M2C_FIELD(o, u8 **, 0x88)) + 8) {
            Hopper_StartJump(o);
        }
    } else {
        M2C_FIELD(o, s16 *, 0x96) += M2C_FIELD(o, s16 *, 0xA8);
        Hopper_SnapHome(o);
        if (o[0xDD] == 0 && Object_UpdateLeap(o) != 0) {
            o[0xDD] = 1;
        }
    }
    if (Object_DetachLink(o, 0) == 6) {
        o[0x80] = 4;
        Object_Timer(o, 0x1E);
    } else {
        Hopper_AddAttackSphere(o);
    }
}

void Hopper_StepGround(s32 arg0) {
    if (Hopper_IsOnGround() != 0) {
        Object_KeepAwayFromSpike(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void Hopper_UpdateHeight(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void Hopper_CheckHit(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        Object_ApplyHit();
        Object_HitFeedback(arg0);
    }
}

typedef struct { u16 f0; u16 f2; } Anim_8013ECD4;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0x4]; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1F]; u8 f_7D; u8 pad7E[0x1]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[0x6]; Anim_8013ECD4 *anim; u8 pad8C[0xE]; s16 f_9A; u8 pad9C[0x2]; s16 f_9E; s16 f_A0; u8 padA2[0x2]; s16 f_A4; u8 padA6[0x2]; s16 f_A8; u8 padAA[0x6]; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 padC9[0x13]; u8 f_DC; u8 f_DD; u8 padDE[0x2]; u32 f_E0; } Obj_8013ECD4;
void func_80058134_8013ECD4(void *, s32) asm("Object_DebugStub");
void Hopper_LandShockwave(void *arg0);
void Hopper_UpdateHopping(u8 *o);
void Hopper_StepGround(s32 arg0);
void Hopper_UpdateHeight(void *arg0);
void Hopper_CheckHit(void *arg0);

void Hopper_Update(Obj_8013ECD4 *o) {
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
        Object_Timer(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        o->f_E0 |= 8;
    }
    Hopper_UpdateHeight(o);
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
        if (Object_Timer(o, -1) == 0 && o->f_5C >= o->anim[o->f_7F].f2) {
            if (o->f_7F == 0) {
                o->f_7F = 1;
                o->f_5C = o->anim[o->f_7F].f0;
            } else {
                o->f_7F = 0;
                o->f_5C = o->anim[o->f_7F].f0;
                Object_Timer(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 10);
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
        Hopper_UpdateHopping((u8 *)o);
        break;
    case 4:
        Hopper_StepGround((s32)o);
        if (Object_Timer(o, -1) == 0) {
            o->f_80 = 3;
        }
        break;
    case 5:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 1;
            o->f_7F = 0;
            o->f_5C = o->anim[o->f_7F].f0;
            Object_Timer(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        }
        break;
    }
    Hopper_LandShockwave(o);
    Hopper_CheckHit(o);
}

typedef struct { u16 start; u16 end; } Rng_8013EFBC;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013EFBC;
void Object_DebugStub(void *, s32);
s32 Floor_GetHeight_8013EFBC(s32, s32, s32) asm("Floor_GetHeight");
s32 rcos_8013EFBC(s32) asm("rcos");
s32 rsin_8013EFBC(s32) asm("rsin");
void Shadow_Draw(void *, s32, s32, s32);

void Swinger_Update(u8 *o) {
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
        Object_Timer(o, 0);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xC9)) {
        M2C_FIELD(o, u8 *, 0xC9)--;
    } else {
        Object_Timer(o, 0x16);
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

void Shot_InitModel(void *arg0, void *arg1, M2C_UNK arg2) {
    Object_SetModel(arg1, arg2);
    Object_GetAnimTable(arg1, arg2);
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
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_DrawAuto(void *, void *, void *);
s32 Object_IsOffScreen(void *, s32, s32);
extern M2C_UNK g_ProjVerts;
extern u8 Shot_Model[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F38C asm("g_Game");

void Shot_DrawModel(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = Shot_Model + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game_8013F38C.f_80 + g_Game_8013F38C.f_C * 0x4078, &g_ProjVerts, m);
    }
}

typedef struct { u8 pad0[0xC]; s16 active; u8 padE[6]; } Drip_405;
extern Drip_405 D_801412E0_s[8] asm("Shot_Pool");

void Shot_InitPool(void *arg0) {
    s32 i;

    Shot_InitModel(arg0, Shot_Model, 0x83);
    for (i = 7; i >= 0; i--) {
        D_801412E0_s[i].active = 0;
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("Shot_Pool");

s32 Shot_FindFree(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013F4D8;
extern Drip_8013F4D8 D_801412E0_8013F4D8[8] asm("Shot_Pool");
s32 Shot_FindFree(void);

M2C_UNK Shot_Spawn(void *arg0, M2C_UNK dy, M2C_UNK r) {
    u8 *o = arg0;
    s32 i;
    Drip_8013F4D8 *d;
    s16 c;
    s16 s;

    i = Shot_FindFree();
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

s32 Shot_IsBelowFloor(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void Shot_SpawnTrail(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void Shot_SpawnSplash(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013F6D4;
extern Drip_8013F6D4 D_801412E0_8013F6D4[8] asm("Shot_Pool");
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013F6D4;
extern M_8013F6D4 D_80141380_8013F6D4 asm("Shot_Model");
s32 Object_DetachLink_8013F6D4(void *, s32) asm("Object_DetachLink");
s32 Object_AddAttackSphere_8013F6D4(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void VectorNormalSS(void* v0, void* v1);
void Shot_DrawModel(s32 arg0, s32 arg1);
s32 Shot_IsBelowFloor(void *arg0);
void Shot_SpawnTrail(SVECTOR *arg0);
void Shot_SpawnSplash(SVECTOR *arg0);

void Shot_UpdateAll(void *arg0) {
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
            Shot_SpawnTrail((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            r = Object_DetachLink_8013F6D4(arg0, 0);
            if (Shot_IsBelowFloor(p) || M2C_FIELD(arg0, s32 *, 0x28) + 0x600 < p->y || r == 6) {
                p->active = 0;
                Shot_SpawnSplash((SVECTOR *)p);
                Object_PlaySound(arg0, 0x4D);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->vx = p->vx;
                m->vy = p->vy;
                m->vz = p->vz;
                VectorNormalSS(&m->vx, &m->vx);
                Shot_DrawModel(0, 3);
                M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere_8013F6D4(arg0, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void Spitter_SpawnPuff(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void Object_SpawnHitSpark(void *, s32, s32, s32);

void Spitter_CheckHit(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_SpawnHitSpark(arg0, 0, 0, 0);
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void Spitter_PopUp(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    Spitter_SpawnPuff(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}


void Spitter_Fire(void *obj) {
    Shot_Spawn(obj, 0x46, 0xA0);
}

void Object_DisableCollision(void *);

void Spitter_Init(void *arg0) {
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
    Object_Timer(arg0, (s16)(M2C_FIELD(arg0, s16 *, 0x9A) % 60) + 0x3C);
    Shot_InitPool(arg0);
    Object_DisableCollision(arg0);
}

typedef struct { u16 start; u16 end; } Anim_8013FAEC;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0xA]; u32 f_50; u8 pad54[0x8]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[0x7]; Anim_8013FAEC *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[0x3E]; u32 f_E0; } O_8013FAEC;
void Shot_UpdateAll(void *arg0);
void Spitter_SpawnPuff(void *arg0);
void Spitter_CheckHit(void *arg0);
void Spitter_PopUp(void *arg0);
void Spitter_Fire(void *obj);
void Spitter_Init(void *arg0);
M2C_UNK Object_StepOnGroundFixed_8013FAEC(void *) asm("Object_StepOnGroundFixed");
void Object_TurnTowardSpike_8013FAEC(void *) asm("Object_TurnTowardSpike");
void func_80058134_8013FAEC(void *, s32) asm("Object_DebugStub");
void func_80055C7C_8013FAEC(void *, s32) asm("Object_FleeSpike");
void func_80055D28_8013FAEC(void *, s32, s32) asm("Object_SetRandomHeading");
void Object_EnableCollision_8013FAEC(void *) asm("Object_EnableCollision");
s32 Object_SpikeInFront_8013FAEC(void *, s32, s32, s32) asm("Object_SpikeInFront");
s32 Object_SpikeNearXZ_8013FAEC(void *, s32) asm("Object_SpikeNearXZ");

void Spitter_Update(O_8013FAEC *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        Spitter_Init(o);
        o->f_E0 |= 8;
    }
    func_80058134_8013FAEC(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 6;
        o->f_7F = 0;
        o->f_5C = o->f_88[0].start;
        Spitter_SpawnPuff(o);
    }
    switch (o->f_80) {
    case 1:
        o->f_5C = o->f_88[o->f_7F].start;
        func_80055C7C_8013FAEC(o, 0x3C);
        Object_StepOnGroundFixed_8013FAEC(o);
        if (Object_Timer(o, -1) == 0) {
            Spitter_PopUp(o);
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
            Spitter_SpawnPuff(o);
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
            Spitter_SpawnPuff(o);
            break;
        }
        if (o->f_5C == o->f_88[o->f_7F].start + 0x14) {
            Spitter_Fire(o);
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
                Spitter_SpawnPuff(o);
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
            Object_Timer(o, 0x2D);
            o->f_80 = 1;
            o->f_7F = 1;
            o->f_5C = o->f_88[1].start;
            func_80055D28_8013FAEC(o, 0x3C, 0);
            Spitter_SpawnPuff(o);
        }
        break;
    }
    Spitter_CheckHit(o);
    Shot_UpdateAll(o);
}

s32 Math_Atan2(s32, s32);

void Swooper_StartReturn(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void Swooper_StartAlert(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void Swooper_ReturnHome(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    Object_FlyAboveFloor(arg0, 0x14);
}

s32 Object_DetachLink(void *, s32);
void Object_StepGrowShrink(void *, s32, s32, s32);

void Swooper_StepDive(u8 *arg0) {
    s16 *v;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        Swooper_StartReturn(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (Object_StepToward3D(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), M2C_FIELD(arg0, s16 *, 0xA8) >> 3) != 0) {
        Swooper_StartReturn(arg0);
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

void Swooper_StartDive(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F21C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F21C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F21C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void Swooper_UpdateKnockedDown(void *arg0) {
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
void Object_InitOrbit(void *, s32);
void func_80058134_80140348(void *, s32) asm("Object_DebugStub");
void Swooper_UpdateKnockedDown(void *arg0);
void Object_OrbitHome(void *, s32);
void Object_TurnToward_80140348(void *, s16, s16, s32, s32) asm("Object_TurnToward");
void Swooper_StartDive(void *arg0);
void Swooper_StartReturn(void *arg0);
void Swooper_ReturnHome(void *arg0);
void Swooper_StartAlert(void *arg0);
void ObjKind4D_IdleSounds(void *);
#define ANIM_80140348(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void Swooper_Update(u8 *o) {
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
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_80140348(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0xC00000;
        Swooper_UpdateKnockedDown(o);
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_OrbitHome(o, 8);
        Object_SeekHeight(o, 8);
        Object_FlyAboveFloor(o, 20);
        if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
            Swooper_StartAlert(o);
        }
        break;
    case 2:
        Object_TurnToward_80140348(o, g_Spike_80140348.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80140348.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] - 10) {
            Swooper_StartDive(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
            if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                Object_PlaySound(o, 0xA6);
            }
        }
        Swooper_StepDive(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            Swooper_StartReturn(o);
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] && M2C_FIELD(o, u8 *, 0x7F) != 4) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_80140348(o, 4)[0];
        }
        break;
    case 4:
        Swooper_ReturnHome(o);
        break;
    case 5:
        Object_TurnToward_80140348(o, g_Spike_80140348.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80140348.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_80140348(o, M2C_FIELD(o, u8 *, 0x7F))[1] && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            if (Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
                Swooper_StartAlert(o);
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, u8 *, 0xC9) = 0;
            }
        }
        break;
    }
    ObjKind4D_IdleSounds(o);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

s32 FallPlatform_Init(void *arg0) {
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
extern s16 g_SpikeStandObj;
extern u8 *g_StageMeshes;
void Sound_PlayAt(s32, void *);
s32 SquareRoot0(s32);

s32 FallPlatform_Update(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140730.f_820C + p[2] * 0x38);
    s32 dx, dy, dz;
    SVECTOR unused;

    switch (p[1]) {
    case 0:
        if (g_SpikeStandObj == p[2]) {
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
                M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x12) = e[1];
                M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x16) = 0;
            }
        } else {
            e[1] += p[3];
            if (e[7] >= 0) {
                M2C_FIELD(g_StageMeshes + e[7] * 32, s16 *, 0x12) = e[1];
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
                M2C_FIELD(g_StageMeshes + e[7] * 32, u16 *, 0x16) = 0xFFFF;
            }
        }
        break;
    }
    return 0;
}

s32 SteamVent_Init(s16 *p) {
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

s32 SteamVent_Update(s16 *p) {
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

s32 HotSprings_AmbientBubbles(u8 *arg0) {
    if (g_Game_80140F94 % 10 == 0) {
        Sound_PlayAt(((RAND() >> 8) & 3) + 0xB6, arg0 + 8);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
