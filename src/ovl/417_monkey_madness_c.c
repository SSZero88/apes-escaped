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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D4D8);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D538);

void func_8013D62C(void *arg0) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x74);
    Effect_Spawn(0xCA, temp_s1, &D_801409FC, 0);
    Effect_Spawn(0xCB, temp_s1, &D_801409FC, 0);
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D684);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D738);

void func_8013D8F0(void *arg0, s32 a) {
    M2C_FIELD(arg0, u8 *, 0x71) = a;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x71) * 4 + M2C_FIELD(arg0, u8 **, 0x74));
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013D910);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DAC8);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013DDAC);

void func_8013DDAC(void *, void *);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E098);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E1A4);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E310);

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
void func_8013E310(s32);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E4E0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E650);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E730);

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
M2C_UNK func_8013E730();
extern M2C_UNK D_80140D00;
extern M2C_UNK D_80140D38;

void func_8013E88C(void *arg0) {
    func_80051E98(arg0, 0);
    Collision_Remove(&D_80140D00);
    func_8007CDC4(&D_80140D38);
    func_8013E730();
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013E8CC);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EAD4);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EBC0);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EC24);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EC70);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013ED4C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013EE4C);

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F37C);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_8013F6FC);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140070);

s32 func_80140264(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140278);

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

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_801403DC);

s32 func_80140564(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/417/nonmatchings/417_monkey_madness_c", func_80140574);

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
