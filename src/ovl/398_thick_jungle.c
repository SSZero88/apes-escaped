#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Pad { u8 pad_0[0x1BC]; s16 f_1BC; s16 f_1BE; } g_Pad;

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_SetForwardVelocity(void *, M2C_UNK);

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_DisableCollision();
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK func_8005588C(void *, M2C_UNK);
extern s8 D_80142860;
s32 Math_Atan2(s32, s32, s16);
s16 rcos(s16);
s16 rsin(s16);
extern struct S_D_800E77A0 { u8 pad_0[0x1]; u8 f_1; } D_800E77A0;
M2C_UNK Collision_Set(M2C_UNK, M2C_UNK *, s32);
extern struct S_D_80143170 { u8 pad_0[0x20]; s16 f_20; s16 f_22; s16 f_24; s16 f_26; } D_80143170;
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013FA20;
extern struct S_D_801431B0 { u8 pad_0[0x10]; s32 f_10; } D_801431B0[];
s32 Spike_WithinRadiusXZ(s32 x, s32 z, s32 r);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, s32);
M2C_UNK func_80088120(s8);
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
M2C_UNK Object_TurnTowardSpike(void *);

s32 func_8013D000(void) {
    if ((g_Pad.f_1BC >= 0x191) || (g_Pad.f_1BE >= 0x191)) {
        return 1;
    }
    return 0;
}

s32 func_8013D040(void) {
    if ((g_Pad.f_1BC >= 0x641) || (g_Pad.f_1BE >= 0x641)) {
        return 1;
    }
    return 0;
}

void Object_SetAnim(void *, s32, s32);

void func_8013D080(void *arg0, s16 arg1) {
    Object_SetAnim(arg0, 2, arg1);
    if (arg1 == 5) {
        M2C_FIELD(arg0, s16 *, 0x46) = -0xA0;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x78;
    } else if (arg1 == 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = -0x14A;
        M2C_FIELD(arg0, s16 *, 0x44) = 0xA0;
    }
}

extern u16 D_800AE8F2;
void func_8013D080(void *arg0, s16 arg1);

void func_8013D0EC(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x5E) == 2 && M2C_FIELD(arg0, u8 *, 0x7F) != 5) {
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 0 || M2C_FIELD(arg0, u8 *, 0x7F) == 7) {
            func_8013D080(arg0, 7);
        } else {
            func_8013D080(arg0, 5);
        }
        Object_PlaySound(arg0, 0xB9);
    } else if (M2C_FIELD(arg0, u8 *, 0x80) == 1 && (M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 1) {
        func_8013D080(arg0, M2C_FIELD(arg0, u8 *, 0x7F) == 0 ? 6 : 3);
    } else {
        switch (M2C_FIELD(arg0, u8 *, 0xCF)) {
        case 1:
            if (!(M2C_FIELD(arg0, u32 *, 0xE0) & 1)) {
                M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
                func_8013D080(arg0, 1);
            } else {
                M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
                if ((u8)(M2C_FIELD(arg0, u8 *, 0x7F) - 2) < 2) {
                    func_8013D080(arg0, 5);
                }
            }
            break;
        case 3:
            if (!((u8)(M2C_FIELD(arg0, u8 *, 0x7F) - 3) < 2)) {
                func_8013D080(arg0, (s32)(((u32)((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 7) < 5 ? 3 : 4);
            }
            break;
        }
    }
    M2C_FIELD(arg0, u8 *, 0xCF) = 0;
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D274);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D300);

void func_8013D430(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, (s16) (M2C_FIELD(arg0, u16 *, 0x24) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * arg1) >> 0xC)), M2C_FIELD(arg0, s16 *, 0x28), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) - ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * arg1) >> 0xC)), (s32) arg2, (s32) arg3);
}

s32 Object_DetachLink(void *, s32);

volatile unsigned short func_8013D4C8(void *arg0)
{
  if (Object_DetachLink(arg0, 0) == 6)
  {
    *((u8 *) (((s8 *) arg0) + 0x80)) = 2;
    *((u8 *) (((s8 *) arg0) + 0x7F)) = 1;
    *((u16 *) (((s8 *) arg0) + 0x5C)) = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x88)))) + 4));
    Object_DisableCollision(arg0);
    *((s16 *) (((s8 *) arg0) + 0xAE)) = 0;
  }
}

s32 func_8013D520(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 11) & 1)) {
        switch (M2C_FIELD(o, u8 *, 0x80)) {
        case 5:
            if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 **, 0x88) + M2C_FIELD(o, u8 *, 0x7F) * 4) + 2) {
                func_8013D430(o, 0x32, 1, 0x203);
            }
            break;
        case 1:
            func_8013D4C8(o);
            if (!Spike_WithinRadiusXZ(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x400)) {
                break;
            }
        default:
            func_8013D430(o, 0, 0xB01, 0x200);
            break;
        case 7:
        case 8:
        case 9:
        case 10:
            break;
        }
    }
}

void func_8013D608(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 7;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    Object_DisableCollision();
    Object_PlaySound(arg0, 0x9A);
    func_8005588C(arg0, 0xC);
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D660);

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D790 asm("g_Spike");
extern u16 g_RandSeed;
void Object_HeadTowardSpike_8013D790(void *, s32) asm("Object_HeadTowardSpike");
s32 Object_StepOnGround_8013D790(void *, s16) asm("Object_StepOnGround");
s32 func_80055718_8013D790(void *, s32, s32, s32, s32) asm("func_80055718");
s16 func_80056010_8013D790(void *, s16, s16, s32) asm("func_80056010");

void func_8013D790(void *arg0) {
    s32 dx;
    s32 dz;
    s32 d;

    dx = M2C_FIELD(arg0, s16 *, 0x9A) - g_Spike_8013D790.x;
    dz = M2C_FIELD(arg0, s16 *, 0x9E) - g_Spike_8013D790.z;
    d = dx * dx + dz * dz;
    if (d < M2C_FIELD(arg0, s16 *, 0xA6) * M2C_FIELD(arg0, s16 *, 0xA6)) {
        M2C_FIELD(arg0, u16 *, 0x5C) += 3;
        if (M2C_FIELD(arg0, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88) + 2)) {
            M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
            Object_PlaySound(arg0, 0xBB);
        }
        Object_HeadTowardSpike_8013D790(arg0, 0x13);
        Object_StepOnGround_8013D790(arg0, 0x40);
    } else if (d >= 0x641) {
        func_80055718_8013D790(arg0, M2C_FIELD(arg0, s16 *, 0x9A), 0, M2C_FIELD(arg0, s16 *, 0x9E), func_80056010_8013D790(arg0, 0x28, 2, 0));
        Object_StepOnGround_8013D790(arg0, 0x40);
        if (M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88) + 2) - 1) {
            if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF)) {
                M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013D914);

void func_8013DE24(void *arg0, s32 y, s16 lim) {
    s16 d;

    d = y - M2C_FIELD(arg0, u16 *, 0x28);
    if (__builtin_abs(d) > lim) {
        M2C_FIELD(arg0, s16 *, 0x96) = d > 0 ? lim : -lim;
    } else {
        M2C_FIELD(arg0, s16 *, 0x96) = d;
    }
}

void func_80058134(void *, s32);
void func_80055E6C(void *, s16);

void func_8013DE78(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x48) = 2;
        M2C_FIELD(o, s16 *, 0x4A) = 0x103;
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        M2C_FIELD(o, s16 *, 0x44) = 0xDC;
        M2C_FIELD(o, s16 *, 0x46) = 0xA0;
        func_80055F1C(o, 0x13);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x80) == 1) {
        func_80055E6C(o, 0x13);
        func_8013DE24(o, M2C_FIELD(o, s16 *, 0x9C), 0x1C);
        Object_ApplyVelocity(o);
    }
}

void func_8013DF48(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v0 = &D_80142860;
    var_v1 = 0x3F;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 += 0x24;
    } while (var_v1 >= 0);
}

extern u16 g_RandSeed;
typedef struct { u8 on; u8 f1; s16 f2; SVECTOR p; SVECTOR v; s16 f14; s16 f16; s16 f18; s16 pad1a; s16 r1c; s16 r1e; s16 r20; s16 pad22; } P_DF6C;
extern P_DF6C D_80142860_DF6C[] asm("D_80142860");

void func_8013DF6C(SVECTOR *a, SVECTOR *b, s32 c) {
    s32 i;
    P_DF6C *e;

    for (i = 0, e = D_80142860_DF6C; i < 64; i++, e++) {
        if (e->on == 0) {
            e->on = 1;
            e->p = *a;
            e->v = *b;
            e->f1 = 0;
            e->f2 = c;
            e->f14 = 0;
            e->f16 = 0;
            e->f18 = 0;
            e->r1c = (g_RandSeed = g_RandSeed * 5 + 1) >> 8;
            e->r1e = (g_RandSeed = g_RandSeed * 5 + 1) >> 8;
            e->r20 = (g_RandSeed = g_RandSeed * 5 + 1) >> 8;
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E068);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E1E0);

s32 Object_SpikeInFront(void *, s32, s32, s32);
void Effect_Spawn(s32, s16 *, u32 *, s16 **);
extern struct { u8 pad_0[0x8126]; u16 f_8126; } g_Game_8013E560 asm("g_Game");
extern u32 D_801426C0;

void func_8013E560(u8 *a) {
    SVECTOR v;
    s32 x;
    s32 z;

    if (M2C_FIELD(a, s16 *, 0xA8) == 0 && !Object_SpikeInFront(a, 0x5A, 0xB50, 0x400)) {
        return;
    }
    x = M2C_FIELD(a, s16 *, 0x60);
    z = M2C_FIELD(a, s16 *, 0x64);
    v.vx = M2C_FIELD(a, u16 *, 0x24) + ((x * 15) >> 10);
    v.vy = M2C_FIELD(a, u16 *, 0x28) - 0x2C6;
    v.vz = M2C_FIELD(a, u16 *, 0x2C) + ((z * 15) >> 10);
    if (g_Game_8013E560.f_8126 == 9) {
        Effect_Spawn(0xC9, (s16 *)&v, &D_801426C0, 0);
        Effect_Spawn(0xC9, (s16 *)&v, &D_801426C0, 0);
    } else {
        Effect_Spawn(0xC8, (s16 *)&v, &D_801426C0, 0);
        Effect_Spawn(0xC8, (s16 *)&v, &D_801426C0, 0);
    }
    if (M2C_FIELD(a, s8 *, 0x7C) == -1) {
        M2C_FIELD(a, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, (s32)(a + 0x24));
        M2C_FIELD(a, s16 *, 0xA8) = 120;
    }
}

s32 *Collision_GetShape(s16);
void func_8006B3CC(SVECTOR *);
s32 func_800525A0(u8 *, s32 *);

void func_8013E688(u8 *o) {
    SVECTOR v;
    s32 *s;

    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) == 11) {
        s = Collision_GetShape(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
        v.vx = s[0];
        v.vy = s[1];
        v.vz = s[2];
        func_8006B3CC(&v);
        Object_PlaySound(o, 0xB7);
        func_800525A0(o, Collision_GetShape(M2C_FIELD(o, u16 *, 0x50) & 0xFFF));
        M2C_FIELD(o, u8 *, 0x84) = 20;
        if (M2C_FIELD(o, u8 *, 0x81) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 6;
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x10);
            func_80052038(o, 0x78);
            Object_PlaySound(o, 0xB8);
        } else {
            Object_PlaySound(o, 0xB6);
        }
    }
}

extern s32 D_80143160;

s32 func_8013E768(void *arg0) {
    s32 r = 0;

    switch (D_80143160) {
    case 1:
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x7F) = 2;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 8);
        Object_PlaySound(arg0, 0xB6);
        r = 1;
        break;
    case 2:
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
        M2C_FIELD(arg0, u8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0xB6);
        r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E7EC);

M2C_UNK func_8013E7EC(void *);
extern s32 D_80143160;

void func_8013E848(void *arg0) {
    if ((u32) (M2C_FIELD(arg0, u8 *, 0x7F) - 2) < 2U) {
        func_8013E7EC(arg0);
    } else {
        M2C_FIELD(arg0, s8 *, 0x80) = 9;
        M2C_FIELD(arg0, u8 *, 0x7F) = 9U;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x24);
        func_8005588C(arg0, 0x3C);
    }
    D_80143160 = 0;
}

extern s32 D_80143164;
extern s32 D_80143168;
s32 func_80057140(void *, s32, s32);
void func_80056BC4(s32, s32, s32);
void func_8005866C(void *, s32);
void func_80052038_8013E8A8(void *, s32) asm("func_80052038");
void Hook_Add_8013E8A8(void *) asm("Hook_Add");
void func_8013DF48(void);
extern void func_8013E1E0_8013E8A8(void) asm("func_8013E1E0");
typedef struct { u8 pad0[0x8C]; u16 f_8C; } T_8013E8A8;

void func_8013E8A8(u8 *a) {
    M2C_FIELD(a, s16 *, 0xA0) = 350;
    M2C_FIELD(a, s16 *, 0x44) = 300;
    M2C_FIELD(a, s16 *, 0x46) = 0x30C;
    M2C_FIELD(a, s16 *, 0x4A) = -0x3F00;
    M2C_FIELD(a, s16 *, 0x48) = 0;
    M2C_FIELD(a, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(a, u8 *, 0x81) = 0x24;
    M2C_FIELD(a, u32 *, 0xE0) &= ~0x8000;
    M2C_FIELD(a, s8 *, 0x7C) = -1;
    M2C_FIELD(a, u32 *, 0xE0) |= 0x2000;
    M2C_FIELD(a, s32 *, 0x74) = func_80057140(a, 10, 0x78);
    M2C_FIELD(a, s32 *, 0x78) = func_80057140(a, 9, 0x6F);
    func_80056BC4(0x50, 0, M2C_FIELD(a, s8 *, 0xCB));
    func_80056BC4(0x50, 0, M2C_FIELD(a, s8 *, 0xCB));
    D_80143164 = 0;
    D_80143160 = 0;
    D_80143168 = 0;
    M2C_FIELD(a, s16 *, 0xA8) = 0;
    if (((T_8013E8A8 *)a)->f_8C) {
        func_8005866C(a, 1);
    }
    M2C_FIELD(a, u8 *, 0x80) = 1;
    M2C_FIELD(a, u8 *, 0x7F) = 4;
    M2C_FIELD(a, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(a, u8 **, 0x88), u16 *, 0x12) - 1;
    func_80052038_8013E8A8(a, 0x78);
    func_8013DF48();
    Hook_Add_8013E8A8(func_8013E1E0_8013E8A8);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013E9D8);

extern s32 D_800B1BD4;
void Camera_StartShake(s32);
void func_80070284(void *, s32 *, s32, s32, s32);
void Effect_SpawnAt(s32, void *);

void func_8013EEB8(u8 *a) {
    SVECTOR v;
    s32 i;

    Camera_StartShake(0);
    v.vx = M2C_FIELD(a, u16 *, 0x24);
    v.vy = M2C_FIELD(a, u16 *, 0x28);
    v.vz = M2C_FIELD(a, u16 *, 0x2C);
    func_80070284(&v, &D_800B1BD4, 1, 4, 0);
    for (i = 20; i >= 0; i--) {
        v.vx = M2C_FIELD(a, u16 *, 0x24) + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        v.vy = M2C_FIELD(a, u16 *, 0x28) + ((g_RandSeed = g_RandSeed * 5 + 1) >> 10);
        v.vz = M2C_FIELD(a, u16 *, 0x2C) + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        Effect_SpawnAt(0x16, &v);
    }
    Object_PlaySound(a, 0x51);
}

M2C_UNK Object_DropPickups(s32);

void func_8013EFDC(s32 arg0) {
    func_800573A0(arg0, 0, 0, 0);
    Object_DropPickups(arg0);
    func_80051E98(arg0, 1);
}

typedef struct { u8 pad[0xE4]; } Obj_8013F020;
extern Obj_8013F020 g_Objects_8013F020[] asm("g_Objects");
extern u8 D_800B1C28[];
void func_8013F354(void *, void *);
void *memset(void *, s32, s32);

void func_8013F020(u8 *o) {
    SVECTOR a;
    SVECTOR v;
    s32 i;

    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) == 11 && D_80143168 == 0) {
        if (M2C_FIELD(o, u8 *, 0x8F) == 0) {
            D_80143160 |= 1;
        } else {
            D_80143160 |= 2;
        }
        M2C_FIELD(o, u8 *, 0x84) = 0x14;
        D_80143168 = 10;
        Object_PlaySound(o, 0xB7);
        Object_DisableCollision(o);
        func_8013F354(o, &g_Objects_8013F020[M2C_FIELD(o, s8 *, 0xCA)]);
        memset(&v, 0, 8);
        v.vx = M2C_FIELD(o, u16 *, 0x24);
        v.vy = M2C_FIELD(o, u16 *, 0x28) - 0x80;
        v.vz = M2C_FIELD(o, u16 *, 0x2C);
        a = v;
        Effect_SpawnAt(0x113, &a);
        for (i = 0; i < 3; i++) {
            v.vx = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            v.vy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            v.vz = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
            func_80070284(&a, D_800B1C28, 1, i, &v);
        }
    }
}

void *memset(void *, s32, s32);
void func_8013DF6C(SVECTOR *a, SVECTOR *b, s32 c);

void func_8013F1F8(void *arg0, void *arg1) {
    SVECTOR a;
    SVECTOR t;
    SVECTOR u;
    u16 r;
    s32 c;

    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3)) {
        memset(&t, 0, 8);
        t.vx = M2C_FIELD(arg0, u16 *, 0x24);
        t.vy = M2C_FIELD(arg0, u16 *, 0x28);
        t.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        a = t;
        memset(&u, 0, 8);
        u.vx = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) - 7;
        u.vy = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 16;
        r = g_RandSeed * 5 + 1;
        u.vz = ((r >> 8) & 0xF) - 7;
        t = u;
        c = M2C_FIELD(arg1, s16 *, 0x28);
        g_RandSeed = r;
        func_8013DF6C(&a, &t, c);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F354);

void func_8013EEB8(u8 *a);

void func_8013F448(u8 *a, u8 *b, s32 lo, s32 hi) {
    SVECTOR v;
    s32 t;

    t = M2C_FIELD(b, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(b, u8 *, 0x7F) * 4 + M2C_FIELD(b, u8 **, 0x88));
    if (D_80143164 == M2C_FIELD(a, u8 *, 0x8F)) {
        if (t >= lo && hi >= t) {
            v.vx = M2C_FIELD(a, u16 *, 0x24);
            v.vy = M2C_FIELD(a, u16 *, 0x28) - 300;
            v.vz = M2C_FIELD(a, u16 *, 0x2C);
            Object_AddAttackSphereNear(a, (s16)(M2C_FIELD(a, u16 *, 0x44) + 100), v.vx, v.vy, v.vz, 1, 0x203);
        }
        if (M2C_FIELD(b, u8 *, 0x80) == 8) {
            if (t == 0x1B || t == 0x2A || t == 0x3B || t == 0x4A) {
                func_8013EEB8(a);
            }
        }
        func_8013F1F8(a, b);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013F56C);

void func_8013F608(void *arg0) {
    s16 temp_a2;
    s16 temp_v0_3;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    void *temp_v0;

    M2C_FIELD(arg0, s16 *, 0xA0) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x48) = 1;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x3DFD;
    M2C_FIELD(arg0, s16 *, 0x44) = 0xE6;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x258;
    M2C_FIELD(arg0, s8 *, 0xDC) = 7;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    M2C_FIELD(arg0, s8 *, 0xC9) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~0x1000);
    M2C_FIELD(arg0, u8 *, 0x8F) = (u8) D_800E77A0.f_1;
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 + 1);
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    if (M2C_FIELD(arg0, u16 *, 0x8C) != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x90);
        temp_a2 = M2C_FIELD(temp_v0, s16 *, 8);
        temp_v0_2 = Math_Atan2(temp_a2 - M2C_FIELD(temp_v0, s16 *, 0), M2C_FIELD(temp_v0, s16 *, 0xC) - M2C_FIELD(temp_v0, s16 *, 4), temp_a2);
        temp_v1 = temp_v0_2 + 0x1400;
        var_v0 = temp_v1;
        if (temp_v1 < 0) {
            var_v0 = temp_v0_2 + 0x23FF;
        }
        temp_v0_3 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
        M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0_3;
        M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0_3);
        M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
        M2C_FIELD(arg0, s16 *, 0x62) = 0;
    }
    Object_DisableCollision(arg0);
}

typedef struct { u8 pad0[0x80]; u8 f_80; u8 pad81[0x63]; } Obj_8013F71C;
extern Obj_8013F71C g_Objects_8013F71C[] asm("g_Objects");
void func_8013F608(void *arg0);
void func_8013F56C(void *, void *);
void Object_EnableCollision(void *);
void func_8013EFDC(s32 arg0);
void func_8013F448(u8 *a, u8 *b, s32 lo, s32 hi);

void func_8013F71C(u8 *a) {
    Obj_8013F71C *o;

    o = &g_Objects_8013F71C[M2C_FIELD(a, s8 *, 0xCA)];
    if (!((M2C_FIELD(a, u32 *, 0xE0) >> 3) & 1)) {
        func_8013F608(a);
        M2C_FIELD(a, u32 *, 0xE0) |= 8;
    }
    func_80058134(a, M2C_FIELD(a, s16 *, 0x44));
    func_8013F56C(a, o);
    switch (o->f_80) {
    case 2:
        M2C_FIELD(a, u8 *, 0xC8) = 10;
        break;
    case 3:
        break;
    case 7:
        func_8013F448(a, (u8 *)o, 0x1B, 0x23);
        func_8013F020(a);
        break;
    case 8:
        func_8013F448(a, (u8 *)o, 0x18, 0x50);
        func_8013F020(a);
        break;
    case 4:
        Object_EnableCollision(a);
    case 5:
        func_8013F020(a);
        break;
    case 6:
        func_8013EFDC((s32)a);
        break;
    }
}

extern struct { s32 x, y, z; } D_80143170_8013F844 asm("D_80143170");

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013F844(arg0)
    void *arg0;
{
    s32 dx = M2C_FIELD(arg0, s16 *, 0x60);
    s32 dz = M2C_FIELD(arg0, s16 *, 0x64);

    D_80143170_8013F844.x = M2C_FIELD(arg0, s32 *, 0x24) + ((dx * 75) >> 9);
    D_80143170_8013F844.y = M2C_FIELD(arg0, s32 *, 0x28) + 0x212;
    D_80143170_8013F844.z = M2C_FIELD(arg0, s32 *, 0x2C) + ((dz * 75) >> 9);
}

void func_8013F8A4(s32 arg0) {
    D_80143170.f_26 = -0x4000;
    D_80143170.f_20 = 0x258;
    D_80143170.f_24 = 0;
    D_80143170.f_22 = 0x320;
    func_8013F844();
    Collision_Set(4, &D_80143170, arg0);
}

void func_8013F904(void) {
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_801431B0[i].f_10 = 0;
    }
    Hook_Add(&func_8013FA20);
}

s32 func_8013F948(void) {
    s32 i;
    for (i = 11; i >= 0; i--) {
        if (D_801431B0[i].f_10 == 0) {
            return i;
        }
    }
    return -1;
}

void func_8013F984(void *arg0, void *arg1) {
    s32 temp_v0;
    void *temp_v1;

    temp_v0 = func_8013F948();
    if (temp_v0 != -1) {
        temp_v1 = (void *)((u8 *)&D_801431B0 + (temp_v0 * 0x14));
        M2C_FIELD(temp_v1, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
        M2C_FIELD(temp_v1, SVECTOR *, 8) = M2C_FIELD(arg1, SVECTOR *, 0);
        M2C_FIELD(temp_v1, s32 *, 0x10) = 3;
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FA20);

void func_8013FA90(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0xC3) >> 9));
    M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x64);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0xC3) >> 9));
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FAF4);

void func_8013FD9C(void *arg0, s32 n) {
    if (M2C_FIELD(arg0, u8 *, 0x7F) != n &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88) + 2)) {
        M2C_FIELD(arg0, u8 *, 0x7F) = n;
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
    }
}

void func_8013FDF0(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0x280;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & 0xFFFEFFFF);
    }
}

void func_80052038(s32, s32);

void func_8013FE4C(void *arg0) {
    func_80052038(arg0, 0x52);
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
}

extern u32 g_Game_8013FE94 asm("g_Game");
void func_8013FAF4(void *, SVECTOR *);

void func_8013FE94(void *arg0) {
    SVECTOR v;

    func_8013FA90(arg0, &v);
    if (Spike_WithinRadiusXZ(v.vx, v.vz, 0x400)) {
        func_8013FAF4(arg0, &v);
        if (g_Game_8013FE94 & 1) {
            func_80052038(arg0, 0x52);
        } else {
            func_80052038(arg0, 0x8A);
        }
    } else {
        func_8013FE4C(arg0);
    }
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8013FF1C);

s32 func_80140044(void *arg0) {
    s16 *p = M2C_FIELD(arg0, s16 **, 0x90);
    s32 d1;
    s32 d2;

    d1 = (p[0] - M2C_FIELD(arg0, s32 *, 0x24)) * (p[0] - M2C_FIELD(arg0, s32 *, 0x24)) +
         (p[2] - M2C_FIELD(arg0, s32 *, 0x2C)) * (p[2] - M2C_FIELD(arg0, s32 *, 0x2C));
    d2 = (p[0] - p[4]) * (p[0] - p[4]) + (p[2] - p[6]) * (p[2] - p[6]);
    return d2 < d1;
}

M2C_UNK Object_ApplyVelocity_801400B0(void *, s32) asm("Object_ApplyVelocity");
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_801400B0(void *arg0)
{
  s32 temp_lo;
  temp_lo = Object_StepGrowShrink(arg0, 0x50, 0, -0xA);
  if ((temp_lo != 0) || (func_80140044(arg0) != 0))
  {
    *((s8 *) (((s8 *) arg0) + 0x80)) = 3;
    *((u16 *) (((s8 *) arg0) + 0xAA)) = (u16) (*((u16 *) (((s8 *) arg0) + 0xAC)));
    return;
  }
  temp_lo = (*((s16 *) (((s8 *) arg0) + 0x60))) * (((s32) ((*((u16 *) (((s8 *) arg0) + 0xA8))) << 0x10)) >> 0x13);
  *((s16 *) (((s8 *) arg0) + 0x94)) = (s16) (temp_lo >> 0xC);
  *((s16 *) (((s8 *) arg0) + 0x98)) = (s16) (((s32) ((*((s16 *) (((s8 *) arg0) + 0x64))) * (((s32) ((*((u16 *) (((s8 *) arg0) + 0xA8))) << 0x10)) >> 0x13))) >> 0xC);
  Object_ApplyVelocity_801400B0(arg0, temp_lo);
}

void Object_SetVelocityToward(void *, void *, s32, s16);

void func_80140150(u8 *o) {
    s16 v[4];
    s16 *t = M2C_FIELD(o, s16 **, 0x90);

    v[0] = t[0] - M2C_FIELD(o, u16 *, 0x24);
    v[1] = 0;
    v[2] = t[2] - M2C_FIELD(o, u16 *, 0x2C);
    if (v[2] * 2 + v[0] * v[0] < 400) {
        M2C_FIELD(o, u8 *, 0x8E) = 1;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
        M2C_FIELD(o, s32 *, 0x24) = t[0];
        M2C_FIELD(o, s32 *, 0x2C) = t[2];
        M2C_FIELD(o, u8 *, 0x80) = 1;
    } else {
        Object_SetVelocityToward(o, v, 0x14, 0x800);
        Object_ApplyVelocity(o);
    }
}

void Object_PlaceAtPathPoint(void *, s32);
void func_8005866C(void *, s32);

void func_80140214(u8 *o) {
    M2C_FIELD(o, s16 *, 0xA0) = 300;
    M2C_FIELD(o, s16 *, 0xB0) = 0x16;
    M2C_FIELD(o, u8 *, 0xC8) = 0x1B;
    M2C_FIELD(o, s16 *, 0x48) = 0x400;
    M2C_FIELD(o, s16 *, 0x4A) = -0x3EFF;
    M2C_FIELD(o, s16 *, 0x46) = 300;
    M2C_FIELD(o, s16 *, 0x44) = 0x10E;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(o, s16 *, 0xA8) = 0;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x200;
    M2C_FIELD(o, u8 *, 0x8F) = 0;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
    M2C_FIELD(o, u8 *, 0x8E) = 1;
    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        Object_PlaceAtPathPoint(o, 0);
        func_8005866C(o, 1);
    }
    func_8013F904();
    M2C_FIELD(o, u8 *, 0x80) = 1;
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
    func_8013F8A4(o);
}

void func_8013F844();
void func_8013FA90(void *arg0, void *arg1);
void func_8013FD9C(void *arg0, s32 n);
void func_8013FDF0(void *arg0);
void func_8013FE4C(void *arg0);
void func_8013FE94(void *arg0);
void func_8013FF1C(void *);
void func_801400B0(void *arg0);
void func_80140150(u8 *o);
void func_80140214(u8 *o);

void func_801402E8(u8 *o) {
    SVECTOR v;

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_80140214(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013F844(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 2:
        func_801400B0(o);
        break;
    case 3:
        func_8013FF1C(o);
        if (func_8005588C(o, -1) == 0) {
            func_8013FA90(o, &v);
            if (Spike_WithinRadiusXZ(v.vx, v.vz, 0x400)) {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = 2;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
                M2C_FIELD(o, s16 *, 0xB0) = 5;
                M2C_FIELD(o, u32 *, 0xE0) &= ~1;
            }
        }
        break;
    case 4:
        func_8013FF1C(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    case 5:
        func_8013FE94(o);
        func_8013FF1C(o);
        if (func_8005588C(o, -1) == 0 && (M2C_FIELD(o, u32 *, 0xE0) & 1)) {
            func_8013FE4C(o);
        }
        break;
    case 6:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8005588C(o, 0x3C);
        }
        break;
    case 7:
        func_8013FD9C(o, 0);
        func_80140150(o);
    case 1:
        func_8013FDF0(o);
        break;
    }
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

void func_80140504(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x70B4, 0x1000, arg0 + 0x24);
}

void func_80140538(void *arg0) {
    func_80088120(M2C_FIELD(arg0, s8 *, 0x7C));
}

M2C_UNK func_80051E98(s32, M2C_UNK);
M2C_UNK func_800573A0(s32, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8014055C(s32 arg0) {
    func_80140538(arg0);
    func_800573A0(arg0, 0, 0, 0);
    Object_PlaySound(arg0, 0x5F);
    func_80051E98(arg0, 1);
}

M2C_UNK func_800525E0(void *);
M2C_UNK func_80052864(void *);

void func_801405AC(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_80140538(arg0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

s32 rsin_801405F8(s16) asm("rsin");
void Object_StepOrbitAngle(void *, s16);

void func_801405F8(void *arg0, s32 v, s32 lim) {
    Object_StepOrbitAngle(arg0, 0x3C);
    if (__builtin_abs(v) > lim) {
        v = v > 0 ? lim : -lim;
    }
    M2C_FIELD(arg0, s16 *, 0x96) = v + ((rsin_801405F8(M2C_FIELD(arg0, s16 *, 0xAA)) * 0x1E) >> 12);
}

extern s32 D_800EC208;
void Object_ChaseSpike(void *, s16);

void func_80140684(void *arg0)
{
  int new_var;
  int new_var2;
  new_var = 0x28;
  Object_ChaseSpike(arg0, 0x12);
  new_var2 = (*((s32 *) (((s8 *) arg0) + new_var))) + 0x100;
  func_801405F8(arg0, ((s32) (D_800EC208 - new_var2)) >> 3, 0x32);
  Object_ApplyVelocity(arg0);
}

void func_801406D8(void *arg0) {
    Object_TurnToward(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
    Object_SetForwardVelocity(arg0, 0x12);
    func_801405F8(arg0, (s32) (M2C_FIELD(arg0, s16 *, 0x9C) - M2C_FIELD(arg0, s32 *, 0x28)) >> 2, 0x14);
    Object_ApplyVelocity(arg0);
}

M2C_UNK func_80055F1C(void *, M2C_UNK);

void func_80140760(void *arg0)
{
  *((s16 *) (((s8 *) arg0) + 0xB0)) = 0x7D;
  *((s16 *) (((s8 *) arg0) + 0x48)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x4A)) = 0x103;
  *((s8 *) (((s8 *) arg0) + 0xC8)) = 4;
  *((s16 *) (((s8 *) arg0) + 0x44)) = 0x1E;
  *((s16 *) (((s8 *) arg0) + 0xA0)) = 0x32;
  *((s8 *) (((s8 *) arg0) + 0x7D)) = 0xA;
  *((s16 *) (((s8 *) arg0) + 0x46)) = 0x32;
  *((s16 *) (((s8 *) arg0) + 0xAA)) = 0;
  *((s8 *) (((s8 *) arg0) + 0xDC)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) & (~0x1000));
  func_80140504(arg0);
  func_80055F1C(arg0, 0x32);
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 0;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = (u16) (*(*((u16 **) (((s8 *) arg0) + 0x88))));
}

typedef struct { u8 pad[0xB0]; s16 f_B0; } O_801407F8;
s32 Math_Atan2_801407F8(s32, s32) asm("Math_Atan2");
s32 Math_WithinSquare_801407F8(s32, s32, s32) asm("Math_WithinSquare");
void func_8014055C(s32 arg0);
void func_801405AC(void *arg0);
void func_801406D8(void *arg0);

void func_801407F8(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_80140760(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_80055E6C(o, 0x32);
        M2C_FIELD(o, s16 *, 0x96) = 0;
        Object_ApplyVelocity(o);
        if (M2C_FIELD(o, s16 *, 0x9C) < D_800EC208 && D_800EC208 - M2C_FIELD(o, s16 *, 0x9C) < 0x800 && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            ((O_801407F8 *)o)->f_B0 = 0x71;
            func_8005588C(o, (((u32)((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 5) >> 6) + 0x28);
        }
        break;
    case 2:
        func_80140684(o);
        if (Object_DetachLink(o, 0) == 6) {
            func_8014055C((s32)o);
            return;
        }
        M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphereNear(o, 0x32, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C), M2C_FIELD(o, s16 *, 0x48), M2C_FIELD(o, s16 *, 0x4A));
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
        }
        break;
    case 3:
        func_801406D8(o);
        if (Math_WithinSquare_801407F8(M2C_FIELD(o, s16 *, 0x9A) - M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s16 *, 0x9E) - M2C_FIELD(o, s32 *, 0x2C), M2C_FIELD(o, s16 *, 0xA6))) {
            if (ABS(M2C_FIELD(o, s16 *, 0x9C) - M2C_FIELD(o, s32 *, 0x28)) < 0x14) {
                M2C_FIELD(o, s16 *, 0xAA) = (Math_Atan2_801407F8(M2C_FIELD(o, s32 *, 0x24) - M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x2C) - M2C_FIELD(o, s16 *, 0x9E)) + 0x1400) % 4096;
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, s16 *, 0x96) = 0;
                M2C_FIELD(o, s16 *, 0xB0) = 0x7D;
                M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
            }
        }
        break;
    }
    func_801405AC(o);
}

typedef struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[0x32]; s16 f60; u8 pad62[2]; s16 f64; } Obj_80140A70;

void func_80140A70(Obj_80140A70 *a, s32 arg1) {
    SVECTOR v;
    s32 dx;
    s32 dz;

    dx = ((a->f60 * 25) >> 9) / arg1;
    dz = ((a->f64 * 25) >> 9) / arg1;
    v.vx = a->x - dx + ((s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2);
    v.vy = a->y - ((g_RandSeed = g_RandSeed * 5 + 1) >> 8);
    v.vz = a->z - dz + ((s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2);
    Effect_SpawnAt(5, &v);
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80140BC8);

void func_80140E9C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_80140EDC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_80140F20(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

void func_80052038_80140F9C(void *, s32) asm("func_80052038");
void func_80140E9C(void *arg0);
void func_80140EDC(void *arg0);
void func_80140F20(void *arg0);

void func_80140F9C(u8 *o) {
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
            func_80140E9C(o);
            func_80140F20(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80140EDC(o);
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

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_801411B8);

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801412C4 asm("g_Spike");
s32 Vec_Length(s32, s32, s32);

void func_801412C4(u8 *o) {
    s32 dx;
    s32 dz;
    s32 k;

    M2C_FIELD(o, s16 *, 0x96) = -0x62;
    M2C_FIELD(o, u8 *, 0x80) = 3;
    if (Spike_WithinRadiusXZ(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), M2C_FIELD(o, s16 *, 0xA6))) {
        dx = g_Spike_801412C4.x - M2C_FIELD(o, s32 *, 0x24);
        dz = g_Spike_801412C4.z - M2C_FIELD(o, s32 *, 0x2C);
    } else {
        dx = M2C_FIELD(o, s16 *, 0x9A) - M2C_FIELD(o, s32 *, 0x24);
        dz = M2C_FIELD(o, s16 *, 0x9E) - M2C_FIELD(o, s32 *, 0x2C);
    }
    if (ABS(dx) >= 20 || ABS(dz) >= 20) {
        Vec_Length(dx, 0, dz);
    }
    k = 10;
    M2C_FIELD(o, s16 *, 0xAE) = 0;
    M2C_FIELD(o, u8 *, 0x8F) = 0;
    M2C_FIELD(o, s16 *, 0x94) = M2C_FIELD(o, s16 *, 0x60) * k >> 12;
    M2C_FIELD(o, s16 *, 0x98) = M2C_FIELD(o, s16 *, 0x64) * k >> 12;
}

void func_801413AC(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x400) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);
void func_801413AC(void *arg0, M2C_UNK arg1);

void func_801413F8(u8 *a) {
    s32 x1;
    s32 z1;
    s32 x2;
    s32 z2;
    u16 id;

    x1 = (M2C_FIELD(a, s16 *, 0x60) * 125) >> 12;
    z1 = (M2C_FIELD(a, s16 *, 0x64) * 125) >> 12;
    x2 = (-M2C_FIELD(a, s16 *, 0x64) * 25) >> 12;
    z2 = (M2C_FIELD(a, s16 *, 0x60) * 25) >> 12;
    id = *(u16 *)(M2C_FIELD(a, u8 *, 0x7F) * 4 + M2C_FIELD(a, u8 **, 0x88));
    if (M2C_FIELD(a, u16 *, 0x5C) == id + 10 || M2C_FIELD(a, u16 *, 0x5C) == id + 0x11) {
        Object_SpawnEffect(a, 4, x1 + x2, 100, z1 + z2);
        Object_SpawnEffect(a, 4, x1 - x2, 100, z1 - z2);
        func_801413AC(a, 0xBA);
    }
}

void func_80141504(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0) {
        Object_TurnTowardSpike(arg0);
        return;
    }
    Object_TurnToward(arg0, (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
}

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_80141588);

INCLUDE_ASM("asm/ovl/398/nonmatchings/398_thick_jungle", func_8014186C);

typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[4]; s16 f10; } Scr_801423AC;
extern u8 *D_800B4DC4;
extern SVECTOR D_800F4B30[3];
extern struct { s32 f0; u8 pad4[4]; s32 f8; } g_Game_801423AC asm("g_Game");
extern u8 D_800E7D00_801423AC[] asm("D_800E7D00");
s32 Floor_GetHeight_801423AC(s32, s32, s32) asm("Floor_GetHeight");
s32 Water_Query(s32, s32, s32);
s32 rsin_801423AC(s32) asm("rsin");
void func_80014804(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4_801423AC(s32, void *, void *) asm("func_80017CD4");

void func_801423AC(void) {
    u8 *o;
    s32 fl;
    s32 lvl;
    s32 y;

    o = D_800B4DC4;
    fl = Floor_GetHeight_801423AC(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C));
    if (((Water_Query(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C)) & 0xFFFF) >> 12) == 1) {
        lvl = ((Scr_801423AC *)0x1F8003D4)->fA - ((Scr_801423AC *)0x1F8003D4)->f10;
        if (M2C_FIELD(o, s32 *, 0x28) - lvl > 0x20) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s32 *, 0x28) - 12;
        } else {
            M2C_FIELD(o, s32 *, 0x28) = lvl + 0x20;
        }
        M2C_FIELD(o, u16 *, 0x78) = M2C_FIELD(o, u16 *, 0x24);
        M2C_FIELD(o, u16 *, 0x7A) = M2C_FIELD(o, u16 *, 0x28);
        M2C_FIELD(o, u16 *, 0x7C) = M2C_FIELD(o, u16 *, 0x2C);
    } else if (M2C_FIELD(o, s32 *, 0x28) >= fl) {
        M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(o, s16 *, 0x78);
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x7A);
        M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s16 *, 0x7C);
    }
    func_80014804((s16 *)(o + 0x60), M2C_FIELD(o, s16 **, 0x14));
    y = M2C_FIELD(o, s32 *, 0x28);
    M2C_FIELD(o, s32 *, 0x28) += rsin_801423AC(g_Game_801423AC.f0 << 6) >> 9;
    D_800F4B30[0].vx = 0;
    D_800F4B30[0].vy = 0x800;
    D_800F4B30[0].vz = 0;
    D_800F4B30[1].vx = 0x400;
    D_800F4B30[1].vy = 0;
    D_800F4B30[1].vz = -0x480;
    D_800F4B30[2].vx = 0x400;
    D_800F4B30[2].vy = 0;
    D_800F4B30[2].vz = -0x380;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_801423AC(g_Game_801423AC.f8, D_800E7D00_801423AC, o);
    M2C_FIELD(o, s32 *, 0x28) = y;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
