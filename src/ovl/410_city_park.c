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
M2C_UNK func_8013E3B4(void *);
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
M2C_UNK func_8013FA08(void *);
s32 func_8013FBD4();
M2C_UNK func_8013FDE0(void *);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
s32 rcos(s16);
s32 rsin(s16);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013D000);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013DCD4);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013DD24);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E010);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E3B4);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E6F4);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013E848);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013EA38);

s32 func_8013EABC(void *arg0) {
    return Math_WithinSquare(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0x9E), 0x32);
}

M2C_UNK func_80055AA0(void *, s16, s16, s16);
M2C_UNK func_8013EA38(void *);
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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013EC88);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013EE4C);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013F184);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013FA08);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013FB38);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013FBD4);

void func_8013FC08(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x96) = -0x2D;
    M2C_FIELD(arg0, s16 *, 0x94) = arg1;
    M2C_FIELD(arg0, s16 *, 0x98) = arg2;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & ~0x20) | 0x400);
}

M2C_UNK func_80056AE4(void *, void *, s8);
void *func_8013FB38(void *, s32, s32);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_8013FDE0);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_801400D4);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140110);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_801401DC);

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

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_801408E0);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_801409F8);

s32 func_80140B78(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140B84);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140E68);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140ED4);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80140FF4);

INCLUDE_ASM("asm/ovl/410/nonmatchings/410_city_park", func_80141084);
