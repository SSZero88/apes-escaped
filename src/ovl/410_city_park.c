#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Pad { u8 pad_0[0x1BC]; s16 f_1BC; s16 f_1BE; } g_Pad;

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_SetForwardVelocity(void *, M2C_UNK);
void Object_TurnToward(void *, s16, s16, s16, s16);

s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_8006F274(M2C_UNK, M2C_UNK *, u16);
M2C_UNK func_8013E310(void *, M2C_UNK *, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801418F8;
extern u16 g_Game;
M2C_UNK Math_WithinSquare(s32, s32, M2C_UNK);
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Puff_Spawn(s32, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
M2C_UNK Object_ChaseSpike(void *, M2C_UNK);
s32 Object_SpikeOutOfRange(void *, s16, s32, s16, s32);
M2C_UNK Object_StepOnGroundFixed(void *);
s32 func_8005588C(void *, M2C_UNK);
M2C_UNK func_80055DC0(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_80056128(void *, M2C_UNK);
s32 func_800572CC(void *);
M2C_UNK func_80058134(void *, s16);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
s32 rcos(s16);
s32 rsin(s16);

extern struct { u8 pad_0[0x824C]; u8 *f_824C; } g_Game_8013D000 asm("g_Game");
typedef struct { s16 pos[3]; s16 y; s16 home[3]; u8 f_E; u8 pad_F[9]; s16 f_18; s16 f_1A; u8 pad_1C[4]; } Pt_8013D000;
extern u8 D_801418F0;
extern Pt_8013D000 D_801414F0[];
s16 Floor_GetHeight(s32, s32, s32);

s32 func_8013D000(void) {
    u8 *hdr = g_Game_8013D000.f_824C;
    s16 *s;
    u8 *data;
    Pt_8013D000 *o;
    s32 i;

    D_801418F0 = 0;
    data = hdr + 8;
    if (M2C_FIELD(hdr, u16 *, 0) != 0x452E || hdr[2] != 0x46) {
        return 1;
    }
    D_801418F0 = hdr[4];
    if (D_801418F0 > 32) {
        D_801418F0 = 32;
    }
    i = 0;
    if (D_801418F0 == 0) {
        return 0;
    }
    o = D_801414F0;
    s = (s16 *)data;
loop:
    {
        o->f_E = 0;
        o->home[0] = o->pos[0] = s[1];
        o->home[1] = o->pos[1] = s[2];
        o->home[2] = o->pos[2] = s[3];
        o->y = Floor_GetHeight(s[1], s[2] + 0x200, s[3]);
        if (o->y < s[2]) {
            o->y = Floor_GetHeight(s[1], s[2] + 0x1000, s[3]);
        }
        o->f_18 = 1;
        o->f_1A = s[5];
        s += 8;
        i++;
        o++;
    }
    if (i < D_801418F0) {
        goto loop;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013D15C);

s32 func_8013D770(void) {
    if ((g_Pad.f_1BC >= 0x641) || (g_Pad.f_1BE >= 0x641)) {
        return 1;
    }
    return 0;
}

void func_8013D7B0(void) {
}

void func_8013D7B8(void) {
}

M2C_UNK func_800573A0(s32, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013D7C0(s32 arg0) {
    func_8013D7B8();
    func_800573A0(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    func_80051E98(arg0, 1);
}

M2C_UNK func_800525E0(void *);
M2C_UNK func_80052864(void *);

void func_8013D810(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_8013D7B8();
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

s32 rsin_801405F8(s16) asm("rsin");
void Object_StepOrbitAngle(void *, s16);

void func_8013D85C(void *arg0, s32 v, s32 lim) {
    Object_StepOrbitAngle(arg0, 0x3C);
    if (__builtin_abs(v) > lim) {
        v = v > 0 ? lim : -lim;
    }
    M2C_FIELD(arg0, s16 *, 0x96) = v + ((rsin_801405F8(M2C_FIELD(arg0, s16 *, 0xAA)) * 0x1E) >> 12);
}

extern s32 D_800EC208;

void func_8013D8E8(void *arg0)
{
  int new_var;
  int new_var2;
  new_var = 0x28;
  Object_ChaseSpike(arg0, 0x12);
  new_var2 = (*((s32 *) (((s8 *) arg0) + new_var))) + 0x100;
  func_8013D85C(arg0, ((s32) (D_800EC208 - new_var2)) >> 3, 0x32);
  Object_ApplyVelocity(arg0);
}

void func_8013D93C(void *arg0) {
    Object_TurnToward(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
    Object_SetForwardVelocity(arg0, 0x12);
    func_8013D85C(arg0, (s32) (M2C_FIELD(arg0, s16 *, 0x9C) - M2C_FIELD(arg0, s32 *, 0x28)) >> 2, 0x14);
    Object_ApplyVelocity(arg0);
}

void func_80055F1C(void *, s32);

void func_8013D9C4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x7D;
    M2C_FIELD(arg0, s16 *, 0x48) = 1;
    M2C_FIELD(arg0, s16 *, 0x4A) = 0x103;
    M2C_FIELD(arg0, u8 *, 0xC8) = 4;
    M2C_FIELD(arg0, s16 *, 0x44) = 0x1E;
    M2C_FIELD(arg0, u8 *, 0x7D) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x32;
    M2C_FIELD(arg0, s16 *, 0xAA) = 0;
    M2C_FIELD(arg0, u8 *, 0xDC) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
    func_8013D7B0();
    func_80055F1C(arg0, 0x32);
    M2C_FIELD(arg0, u8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013DA5C);

extern u8 D_801411D0[];

void func_8013DCD4(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x1E;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    func_80070284(&v, D_801411D0, 1, 0, 0);
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013DD24);

typedef struct { s16 x, y, z; } Rot_8013E010;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_8013E010 r; s16 life; } Debris_8013E010;
extern Debris_8013E010 D_80141908[7];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013E010 asm("g_Game");
extern u8 D_800E7D00[];
s32 func_80051410(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void func_80015780(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
void func_80016EBC(void *, void *, void *);
void Effect_SpawnAt(s32, SVECTOR *);
void func_8006D548(SVECTOR *);

void func_8013E010(u8 *arg0) {
    s32 i;
    Debris_8013E010 *d;
    SVECTOR v;

    for (i = 0; i < 7; i++) {
        d = &D_80141908[i];
        if (d->life != 0) {
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            v.vx = d->x;
            v.vy = d->y;
            v.vz = d->z;
            if (M2C_FIELD(arg0, s16 *, 0x9C) < d->y) {
                d->life = 0;
                v.vy = M2C_FIELD(arg0, s16 *, 0x9C) - 0x32;
                Effect_SpawnAt(0x102, &v);
                Object_PlaySound((s32)arg0, 0x6E);
                continue;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (func_80051410(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                func_80015780(d, 3);
                Model_ProjectBonedVerts(d);
                func_80016EBC(g_Game_8013E010.f_80 + g_Game_8013E010.f_C * 0x4078, D_800E7D00, d);
                Effect_SpawnAt(7, &v);
                func_8006D548(&v);
            }
        }
    }
}

void func_8013E220(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7066, 0x1000, arg0 + 0x24);
    }
}

void func_8013E260(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void func_8013E2A4(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x74), s16 *, 8) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x74), s16 *, 0xA) = 0xCA;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), s16 *, 8) = 0x11;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), s16 *, 0xA) = 0;
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x74), s16 *, 8) = 0x11;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x74), s16 *, 0xA) = 0xD7;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), s16 *, 8) = 0x11;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), s16 *, 0xA) = 0xD9;
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E310);

typedef struct { s16 x, y, z; s16 dx, dy, dz; } V_8013E3B4;
extern V_8013E3B4 D_801418F8_8013E3B4 asm("D_801418F8");
extern struct { u8 pad_0[0x24]; u16 x; u16 p26; u16 y; u16 p2A; u16 z; } g_Spike_8013E3B4 asm("g_Spike");

void func_8013E3B4(u8 *arg0) {
    s16 *a = M2C_FIELD(arg0, s16 **, 0x74);
    s16 *b = M2C_FIELD(arg0, s16 **, 0x78);
    s16 y;

    D_801418F8_8013E3B4.x = (a[0] + b[0]) / 2;
    D_801418F8_8013E3B4.y = y = (a[1] + b[1]) / 2;
    y += 0x7D;
    D_801418F8_8013E3B4.z = (a[2] + b[2]) / 2;
    D_801418F8_8013E3B4.dx = g_Spike_8013E3B4.x - D_801418F8_8013E3B4.x;
    D_801418F8_8013E3B4.dy = g_Spike_8013E3B4.y - y;
    D_801418F8_8013E3B4.dz = g_Spike_8013E3B4.z - D_801418F8_8013E3B4.z;
    VectorNormalSS(&D_801418F8_8013E3B4.dx, &D_801418F8_8013E3B4.dx);
    D_801418F8_8013E3B4.dx = D_801418F8_8013E3B4.dx * 15 >> 10;
    D_801418F8_8013E3B4.dy = D_801418F8_8013E3B4.dx * 15 >> 10;
    D_801418F8_8013E3B4.dz = D_801418F8_8013E3B4.dx * 15 >> 10;
}

void func_8013E49C(void *arg0, M2C_UNK arg1) {
    u16 temp_v0;
    u16 temp_v0_2;

    if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(((M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88)), u16 *, 2)) {
        temp_v0 = M2C_FIELD(&D_801418F8, u16 *, 0) + M2C_FIELD(&D_801418F8, u16 *, 6);
        M2C_FIELD(&D_801418F8, u16 *, 0) = temp_v0;
        temp_v0_2 = temp_v0 + M2C_FIELD(&D_801418F8, u16 *, 8);
        M2C_FIELD(&D_801418F8, u16 *, 0) = temp_v0_2;
        M2C_FIELD(&D_801418F8, u16 *, 0) = (u16) (temp_v0_2 + M2C_FIELD(&D_801418F8, u16 *, 0xA));
    } else {
        func_8013E3B4(arg0);
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
    }
    func_8013E310(arg0, &D_801418F8, 0x78, 0x78);
    func_8006F274(arg1, &D_801418F8, g_Game);
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E580);

void Effect_SpawnAt(s32, SVECTOR *);
void Object_TurnTowardSpike(void *);
s32 Sound_PlayFixed(s32);
typedef struct { u16 start; u16 end; } Rng_8013E6F4;

void func_8013E6F4(u8 *arg0) {
    SVECTOR v;
    s32 t;
    Rng_8013E6F4 *f;

    t = M2C_FIELD(arg0, u16 *, 0x5C);
    f = (Rng_8013E6F4 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, s32 *, 0x88));

    if (t < f->start + 0x3F) {
        Object_TurnTowardSpike(arg0);
    } else if (t < f->end - 0x14) {
        M2C_FIELD(arg0, s32 *, 0xE0) &= ~1;
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = M2C_FIELD(arg0, u16 *, 0x28);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        Object_AddAttackSphereNear(arg0, 0x258, v.vx, v.vy, v.vz, 1, 0x203);
        if (M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, Rng_8013E6F4 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F)].end - 0x16) {
            v.vy += 0x50;
            Effect_SpawnAt(0x117, &v);
            Sound_PlayFixed(0x67);
        }
    }
}

void func_8013E804(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 9;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x24);
}

void func_8013E824(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 4;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0xCE) = 9;
}

void func_8013E804(void *arg0);
void *Collision_GetShape(s32);
s32 Collision_GetId(s32);
typedef struct { u16 start; u16 end; } Rng_8013E848;

s32 func_8013E848(u8 *arg0) {
    u8 *s;
    s32 id;

    if (M2C_FIELD(arg0, u32 *, 0xE0) >> 20 & 1) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x100000;
        if (arg0[0x81] == 0) {
            arg0[0x80] = 12;
            arg0[0x7F] = 4;
            M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(arg0, Rng_8013E848 **, 0x88)[4].start;
            func_8005588C(arg0, 0x1E);
        } else {
            func_8013E804(arg0);
        }
        return 0;
    }
    if (arg0[0xDD] != 0) {
        if (M2C_FIELD(arg0, u32 *, 0x50) >> 28 != 11) {
            return 0;
        }
        s = Collision_GetShape(M2C_FIELD(arg0, u16 *, 0x50) & 0xFFF);
        id = Collision_GetId(M2C_FIELD(arg0, u16 *, 0x50) & 0xFFF);
        if ((M2C_FIELD(s, s16 *, 0x24) & 0xFF00) != 0xD00 && id != 2) {
            arg0[0xCE] = arg0[0x7F];
            arg0[0x7F] = arg0[0xCD];
            M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(arg0, Rng_8013E848 **, 0x88)[arg0[0x7F]].start;
            func_800525E0(arg0);
            func_80052864(arg0);
            arg0[0xDD] = 0;
            return 1;
        }
    }
    return 0;
}

void func_8013E980(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 1;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
}

s32 Object_SpikeOutOfRange_8013E99C(void *, s32, s32, s32, s16) asm("Object_SpikeOutOfRange");

void func_8013E99C(void *arg0) {
    if (Object_SpikeOutOfRange_8013E99C(arg0, M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(arg0, void **, 0x28), M2C_FIELD(arg0, void **, 0x2C), (void *)0x400) == 0) {
        func_8013E804(arg0);
        return;
    }
    if (Object_SpikeOutOfRange_8013E99C(arg0, M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(arg0, void **, 0x28), M2C_FIELD(arg0, void **, 0x2C), 0x800) == 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
        func_8013E2A4(arg0, 0);
        M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    }
}

void func_8013EA38(void *arg0)
{
  u16 temp_v0;
  void *temp_a0;
  if ((*((s16 *) (((s8 *) arg0) + 0xAE))) == 0)
  {
    Object_StepOnGroundFixed(arg0);
  }
  temp_a0 = (unsigned long long) (((*((u8 *) (((s8 *) arg0) + 0x7F))) * 4) + (*((s32 *) (((s8 *) arg0) + 0x88))));
  ;
  if (((*((u16 *) (((s8 *) arg0) + 0x5C))) == (*((u16 *) (((s8 *) temp_a0) + 0)))) || ((*((u16 *) (((s8 *) arg0) + 0x5C))) == (((s32) ((*((u16 *) (((s8 *) temp_a0) + 0))) + (*((u16 *) (((s8 *) temp_a0) + 2))))) >> 1)))
  {
    Object_PlaySound(arg0, 0x4B);
  }
}

s32 func_8013EABC(void *arg0) {
    return Math_WithinSquare(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0x9E), 0x32);
}

M2C_UNK func_80055AA0(void *, s16, s16, s16);
s16 func_80056010(void *, s16, s16, s32);

void func_8013EAF4(void *arg0) {
    func_80055AA0(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), func_80056010(arg0, 0x3C, 0, 0));
    func_8013EA38(arg0);
    if (func_8013EABC(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xA;
    }
}

void func_8013EB58(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x7F);
    switch (temp_v1) {                              /* irregular */
    case 6:
        M2C_FIELD(arg0, u8 *, 0x7F) = 5U;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        return;
    case 5:
        M2C_FIELD(arg0, u8 *, 0x7F) = 1U;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        return;
    case 1:
        M2C_FIELD(arg0, u8 *, 0x7F) = 2U;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
        return;
    }
}

M2C_UNK Object_ChaseSpike_8013EBD4(void *, s16) asm("Object_ChaseSpike");
s32 Object_SpikeOutOfRange_8013EBD4(void *, s32, s32, s32, s32) asm("Object_SpikeOutOfRange");

void func_8013EBD4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x7F) == 2) {
        Object_ChaseSpike_8013EBD4(arg0, func_80056010(arg0, 0x3C, 0, 0));
        func_8013EA38(arg0);
    }
    if (Object_SpikeOutOfRange_8013EBD4(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), 0x200) == 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, u8 *, 0x7F) = 3U;
        M2C_FIELD(arg0, s16 *, 0x5C) = (s16) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC) + 0x23);
    }
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        func_8013E980(arg0);
    }
}

typedef struct { u16 start; u16 end; } Rng_8013EC88;

void func_8013EC88(u8 *o) {
    s16 *a;
    s16 *b;
    SVECTOR m1;
    SVECTOR m2;

    if (o[0x7F] == 9) {
        M2C_FIELD(o, u16 *, 0x5C)++;
        return;
    }
    if (o[0x7F] == 7) {
        return;
    }
    a = M2C_FIELD(o, s16 **, 0x74);
    b = M2C_FIELD(o, s16 **, 0x78);
    m1.vx = (M2C_FIELD(o, s32 *, 0x24) + a[0]) / 2;
    m1.vy = a[1];
    m1.vz = (M2C_FIELD(o, s32 *, 0x2C) + a[2]) / 2;
    m2.vx = (M2C_FIELD(o, s32 *, 0x24) + b[0]) / 2;
    m2.vy = b[1];
    m2.vz = (M2C_FIELD(o, s32 *, 0x2C) + b[2]) / 2;
    Object_AddAttackSphereNear(o, 0xC8, a[0], a[1], a[2], 1, 0x203);
    Object_AddAttackSphereNear(o, 0xC8, b[0], b[1], b[2], 1, 0x203);
    Object_AddAttackSphereNear(o, 0xC8, m1.vx, m1.vy, m1.vz, 1, 0x203);
    Object_AddAttackSphereNear(o, 0xC8, m2.vx, m2.vy, m2.vz, 1, 0x203);
    if (M2C_FIELD(o, u16 *, 0x5C) == (M2C_FIELD(o, Rng_8013EC88 **, 0x88)[o[0x7F]].start + M2C_FIELD(o, Rng_8013EC88 **, 0x88)[o[0x7F]].end) >> 1) {
        Object_PlaySound((s32)o, 0x14);
    }
}

void func_8013EE4C(u8 *o) {
    switch (M2C_FIELD(o, u8 *, 0x7F)) {
    case 9:
        M2C_FIELD(o, u8 *, 0x7F) = 8;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x20);
        M2C_FIELD(o, u8 *, 0xC8) = 12;
        M2C_FIELD(o, u8 *, 0xDD) = 1;
        M2C_FIELD(o, u8 *, 0x8F) = 0;
        func_8013E2A4(o, 1);
        Object_PlaySound(o, 0x14);
        break;
    case 8:
        if (++M2C_FIELD(o, u8 *, 0x8F) == 1) {
            M2C_FIELD(o, u8 *, 0x7F) = 7;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x1C);
        }
        break;
    case 7:
        func_8013E980(o);
        break;
    }
}

void Effect_SpawnAt(s32, SVECTOR *);
s32 rcos_8013EF18(s32) asm("rcos");
s32 rsin_8013EF18(s32) asm("rsin");
extern u16 D_800AE8F2;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2() (D_800AE8F2 = D_800AE8F2 * 5 + 1)

void func_8013EF18(void *arg0) {
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

void func_8013F01C(s32 arg0) {
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

void func_8013F084(void *arg0) {
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

extern u32 g_Game_8013F184 asm("g_Game");

void func_8013F184(u8 *arg0) {
    if (arg0[0x80] != 0xD && (g_Game_8013F184 & 1)) {
        if (arg0[0x81] < 5) {
            func_8013EF18(arg0);
            func_8013EF18(arg0);
            func_8013EF18(arg0);
            func_8013F084(arg0);
            func_8013F084(arg0);
            func_8013F01C(arg0);
        } else if (arg0[0x81] < 10) {
            func_8013EF18(arg0);
            func_8013EF18(arg0);
            func_8013F084(arg0);
            func_8013F01C(arg0);
        } else if (arg0[0x81] < 15) {
            func_8013EF18(arg0);
            func_8013F01C(arg0);
        } else if (arg0[0x81] < 20) {
            func_8013EF18(arg0);
        }
    }
}

void Object_PlaySound_8013F264(void *, s32) asm("Object_PlaySound");
s32 rcos_8013F264(s32) asm("rcos");
s32 rsin_8013F264(s32) asm("rsin");
extern u32 g_Game_8013F264 asm("g_Game");

void func_8013F264(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    if (g_Game_8013F264 % 5 == 0 || g_Game_8013F264 % 17 == 0) {

        a = (M2C_FIELD(arg0, s16 *, 0xAC) + ((RAND() >> 8) << 12) / 510 + 0xC00) % 0x1000;
        v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F264(a) << 8) >> 12);
        v.vy = M2C_FIELD(arg0, u16 *, 0x28) - ((RAND() >> 9) + 0xFA);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F264(a) << 8) >> 12);
        Effect_SpawnAt(0x102, &v);
        Object_PlaySound_8013F264(arg0, 0x4D);
        Object_PlaySound_8013F264(arg0, 0x6C);
    }
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013F3D0);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013F4F4);

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_80052134(void *, M2C_UNK);
typedef struct { u16 start; u16 end; } Rng_8013FA08;

void func_8013FA08(u8 *arg0) {
    func_80052038(arg0, 0x69);
    func_80052134(arg0, 0x69);
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    arg0[0xCD] = 2;
    M2C_FIELD(arg0, s16 *, 0x48) = 1;
    switch (arg0[0x7E]) {
    case 0x67:
        arg0[0xC8] = 16;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x6E;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x50;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7DFD;
        arg0[0x81] = 30;
        arg0[0x80] = 1;
        arg0[0x7F] = 0;
        M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(arg0, Rng_8013FA08 **, 0x88)[0].start;
        break;
    case 0x68:
        arg0[0xC8] = 12;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x37;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x28;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7DFE;
        arg0[0x81] = 20;
        arg0[0x80] = 2;
        arg0[0x7F] = 2;
        M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(arg0, Rng_8013FA08 **, 0x88)[2].start;
        break;
    case 0x69:
        arg0[0xC8] = 7;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x1B;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x14;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
        arg0[0x81] = 2;
        arg0[0xDC] = 0;
        arg0[0x80] = 2;
        arg0[0x7F] = 2;
        M2C_FIELD(arg0, s16 *, 0x5C) = M2C_FIELD(arg0, Rng_8013FA08 **, 0x88)[2].start;
        break;
    }
}

extern s16 D_800E77E0;
extern u8 g_Objects_8013D130[] asm("g_Objects");
extern s16 D_800E77E0;

u8 *func_8013FB38(u8 *arg0, s32 type, s32 flag) {
    s32 i;
    u8 *o;

    for (i = 0; i < D_800E77E0; i++) {
        o = g_Objects_8013D130 + i * 0xE4;
        if (M2C_FIELD(arg0, s8 *, 0xCB) != i && o[0x7E] == type && ((M2C_FIELD(o, u32 *, 0xE0) >> 4) & 1) == flag &&
            M2C_FIELD(o, s16 *, 0x9A) == M2C_FIELD(arg0, s16 *, 0x9A) && M2C_FIELD(o, s32 *, 0x9C) == M2C_FIELD(arg0, s32 *, 0x9C)) {
            return o;
        }
    }
    return 0;
}

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013FBD4(arg0)
    void *arg0;
{
    if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x68) {
        return func_8013FB38(arg0, 0x67, 1);
    }
    return 0;
}

void func_8013FC08(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x96) = -0x2D;
    M2C_FIELD(arg0, s16 *, 0x94) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & ~0x20) | 0x400);
}

M2C_UNK func_80056AE4(void *, void *, s8);

void func_8013FC30(void *arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_s3;
    void *temp_v0;

    temp_s3 = (s32) (M2C_FIELD(arg0, s16 *, 0x64) * -0xF) >> 0xC;
    temp_s2 = (s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 0xC;
    temp_v0 = func_8013FB38(arg0, arg1, 0);
    if (temp_v0 != NULL) {
        func_80056AE4(temp_v0, arg0 + 0x24, M2C_FIELD(arg0, s8 *, 0xCB));
        func_8013FC08(temp_v0, temp_s3, temp_s2);
    }
    M2C_FIELD(arg0, s8 *, 0x7E) = arg1;
    func_8013FC08(arg0, -temp_s3, -temp_s2);
    func_8013FA08(arg0);
}


void func_8013FCE4(void *arg0) {
    u8 s = M2C_FIELD(arg0, u8 *, 0x7E);
    if (s == 0x67) {
        func_8013FC30(arg0, 0x68);
    } else if (s == 0x68) {
        func_8013FC30(arg0, 0x69);
    }
    func_800573A0(arg0, 0, 0, 0);
}

void func_8013FD44(s32 arg0) {
    func_800573A0(arg0, 0, 0, 0);
    func_80051E98(arg0, 1);
}

void func_8013FD80(void *arg0) {
    s32 var_a1;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x7E);
    var_a1 = 0x118;
    if (temp_v1 != 0x67) {
        var_a1 = 0x46;
        if (temp_v1 == 0x68) {
            var_a1 = 0x8C;
        }
    }
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = var_a1;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = ((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) * 2) + var_a1;
}

void func_8013FDE0(u8 *a) {
    s32 f;

    if (a[0x80] != 2) {
        f = M2C_FIELD(a, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(a, u8 **, 0x88) + a[0x7F] * 4);
        if (f == 6 && Spike_WithinRadiusXZ(M2C_FIELD(a, s32 *, 0x24), M2C_FIELD(a, s32 *, 0x2C), 0x800)) {
            Object_PlaySound(a, 0x68);
        } else if (f == 0x15) {
            Object_SpawnEffect(a, 5, 0, 0, 0);
        }
    }
}

void func_8013FE8C(void *arg0) {
    u8 temp_v1;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        if (func_8013FBD4() != 0) {
            func_80051E98(arg0, 0);
            return;
        }
        func_8013FA08(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) | 8);
        goto block_4;
    }
block_4:
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 0x14) & 1) {
        func_8013FCE4(arg0);
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFFEFFFFF);
    }
    func_8013FD80(arg0);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x80);
    switch (temp_v1) {                              /* irregular */
    case 1:
        if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0) {
            Object_ChaseSpike(arg0, 0xE);
        } else {
            func_80055DC0(arg0, 0xE, 0);
        }
        Object_StepOnGroundFixed(arg0);
        if (Object_DetachLink(arg0, 0) == 6) {
            if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x69) {
                func_8013FD44(arg0);
            } else {
                M2C_FIELD(arg0, u8 *, 0x80) = 3U;
                func_8005588C(arg0, 0x3C);
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) ((u16) M2C_FIELD(arg0, s32 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 3:
        func_80056128(arg0, 0xE);
        Object_StepOnGroundFixed(arg0);
        if (func_8005588C(arg0, -1) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
        }
        break;
    case 2:
        if (func_800572CC(arg0) != 0) {
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
            M2C_FIELD(arg0, s16 *, 0x96) = 0;
            M2C_FIELD(arg0, s16 *, 0x94) = 0;
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
        }
        break;
    }
    func_8013FDE0(arg0);
}

extern u8 D_80141278[];
void func_80070284(void *, void *, s32, s32, void *);

void func_801400D4(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    func_80070284(m, D_80141278, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_80140110 asm("g_Game");
extern u8 D_80141224[];

void func_80140110(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_80140110 & 1) {
        func_80070284(m, D_80141224, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8014015C(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x24, 1, 0, 0x64);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_801401DC(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
}

s32 Math_Atan2(s32, s32);

void func_80140228(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_801402B4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    Object_PlaySound(arg0, 0x6F);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    func_8005588C(arg0, 0xA);
}

s32 func_800563E0(void *, s32);

void func_80140300(void *arg0) {
    func_800563E0(arg0, 0x14);
}

void func_80140320(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_80140300(arg0);
}

s16 Object_FloorAt(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepGrowShrink(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK VectorNormalSS(void *, void *);

void func_801403E4(void *arg0) {
    void *temp_a0;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        goto block_8;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13) != 0) {
        func_80140228(arg0);
    } else {
        M2C_FIELD(arg0, u16 *, 0x60) = (u16) M2C_FIELD(arg0, u16 *, 0x94);
        temp_a0 = arg0 + 0x60;
        M2C_FIELD(temp_a0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(temp_a0, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x98);
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & 0xFF3FFFFF) | 0x800000);
        VectorNormalSS(temp_a0, temp_a0);
        Object_ApplyVelocity(arg0);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x103);
    }
    if (Object_FloorAt(arg0, 0, 0, 0) < M2C_FIELD(arg0, s32 *, 0x28)) {
block_8:
        func_80140228(arg0);
    }
}

s32 func_80140548(void *arg0) {
    u8 old;

    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
        old = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0xCE) = old;
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800525E0(arg0);
        func_80052864(arg0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_801405CC);

extern struct S_g_Game_801408E0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801408E0 asm("g_Game");
extern u8 *D_800B4D64;
void RotMatrixZYX(SVECTOR *, void *);

s32 func_801408E0(s16 *p) {
    SVECTOR v;
    u8 *s;
    u16 *e = (u16 *)(g_Game_801408E0.f_820C + p[2] * 0x38);

    e[0x12] = e[0];
    e[0x13] = e[1];
    e[0x14] = e[2];
    s = g_Game_801408E0.f_8220 + p[9] * 0x18;
    if (M2C_FIELD(s, s16 *, 6) != 0) {
        p[3] = 0x400;
        p[1] = 1;
        e[0] = e[0x12] - e[3] + 0x40;
        e[4] += (s16)e[3] * 2;
        e[3] = 0x40;
        v.vy = 0;
        v.vx = 0;
        v.vz = -p[3];
        if (p[6] >= 0) {
            RotMatrixZYX(&v, M2C_FIELD(D_800B4D64 + p[6] * 32, void **, 0x1C));
        }
    } else {
        p[1] = 4;
        p[3] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801409F8 asm("g_Game");

s32 func_801409F8(s16 *p) {
    SVECTOR v;
    u16 *e = (u16 *)(g_Game_801409F8.f_820C + p[2] * 0x38);
    u8 *s;

    switch (p[1]) {
    case 4:
        s = g_Game_801409F8.f_8220 + p[9] * 0x18;
        if (M2C_FIELD(s, s16 *, 6) != 0) {
            p[1] = 5;
        }
        break;
    case 5:
        p[3] += p[4];
        if (p[3] == p[4] * 3) {
            Sound_PlayFixed(0xB7);
        }
        if (p[3] > 0x400) {
            p[3] = 0x400;
            p[1] = 1;
            e[0] = e[0x12] - e[3] + 0x40;
            e[4] += (s16)e[3] * 2;
            e[3] = 0x40;
            e[0xC] &= 0x7FFF;
        }
        v.vy = 0;
        v.vx = 0;
        v.vz = -p[3];
        if (p[6] >= 0) {
            RotMatrixZYX(&v, M2C_FIELD(D_800B4D64 + p[6] * 32, void **, 0x1C));
        }
        break;
    case 0: case 1: case 2: case 3:
        break;
    }
    return 0;
}

s32 func_80140B78(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140B84);

extern struct S_g_Game_80140E68 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140E68 asm("g_Game");
extern u8 *D_800B4D64;

s32 func_80140E68(s16 *p) {
    u8 *e = g_Game_80140E68.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    p[1] = 0;
    p[3] = 0;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    return 0;
}

extern struct S_g_Game_80140ED4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140ED4 asm("g_Game");
extern u8 D_801414C8[];
void func_800702B0(void *, void *);
void Sound_PlayAt(s32, void *);

s32 func_80140ED4(s16 *p) {
    u8 *e = g_Game_80140ED4.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (p[4] < ++p[3]) {
            p[1] = 1;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        }
        break;
    case 1:
        if (M2C_FIELD(e, s16 *, 0x32) == p[6] * 2 + 1) {
            func_800702B0(e, D_801414C8 + p[5] * 12);
            Sound_PlayAt(0x4D, e);
            Sound_PlayAt(0x5F, e);
        }
        break;
    }
    return 0;
}

extern struct S_g_Game_80140FF4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140FF4 asm("g_Game");
s16 func_80092324(s16 *, u16 *);

s32 func_80140FF4(s16 *p) {
    u16 *e = (u16 *)(g_Game_80140FF4.f_820C + p[2] * 0x38);

    e[0x12] = e[0];
    e[0x13] = e[1];
    e[0x14] = e[2];
    e[0x19] = e[3];
    e[0x1A] = e[4];
    e[0x1B] = e[5];
    p[1] = 0;
    p[3] = 0;
    p[11] = 0;
    e[8] = func_80092324(p, e);
    return 0;
}

extern struct S_g_Game_80141084 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141084 asm("g_Game");
s32 Model_SetTurnAngle(s16, s16, s32);

s32 func_80141084(s16 *p) {
    u16 *e = (u16 *)(g_Game_80141084.f_820C + p[2] * 0x38);

    if (p[1] == 1) {
        if (p[11] == 0) {
            Sound_PlayFixed(0xB8);
        }
        p[11] += p[7];
        if (p[5] < p[11]) {
            p[11] = p[5];
            p[1] = 2;
        }
    }
    e[8] = func_80092324(p, e);
    if (p[5] / 2 < p[11]) {
        e[10] = 0xE;
    } else {
        e[10] = 6;
    }
    Model_SetTurnAngle(7, p[6], p[11]);
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
