#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
extern s32 D_800B4D64;
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;
s32 SaveByte_Get(M2C_UNK);

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

extern struct S_D_80144590 { u8 pad_0[0xB]; s8 f_B; } D_80144590[];
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Puff_Spawn(s32, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013F0CC;
extern struct S_D_80144A28 { u8 pad_0[0x10]; s8 f_10; u8 pad_11[0x3]; } D_80144A28[];
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80051E98(s32, M2C_UNK);
extern s32 D_80144650;
M2C_UNK Fx_DebrisExplosion(s16, s16, s16);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_DropPickups(void *);
M2C_UNK func_8013E9E0();
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
extern M2C_UNK func_80140310;
extern struct S_D_80144AD0 { u8 pad_0[0x10]; s32 f_10; } D_80144AD0[];
void *Collision_GetShape(s32);
M2C_UNK func_800525E0(void *);
M2C_UNK func_80052864(void *);
M2C_UNK func_8005744C(void *, s16, s16, s16);
M2C_UNK func_8008FC30(s16, void *);
s32 func_80140B7C(void *);

s32 func_8013D000(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_80144590[i].f_B = 0;
    }
    return 0;
}

s16 Floor_GetHeight(s16, s16, s16);
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80144590");

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D218);

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);

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

extern u8 D_801440C4[];
void func_80070284(void *, void *, s32, s32, void *);

void func_8013DB34(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    func_80070284(m, D_801440C4, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_80140110 asm("g_Game");
extern u8 D_80144070[];

void func_8013DB70(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_80140110 & 1) {
        func_80070284(m, D_80144070, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8013DBBC(void *arg0) {
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

void func_8013DC3C(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
}

s32 Math_Atan2(s32, s32);

void func_8013DC88(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013DD14(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    Object_PlaySound(arg0, 0x6F);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    func_8005588C(arg0, 0xA);
}

s32 func_800563E0(void *, s32);

void func_8013DD60(void *arg0) {
    func_800563E0(arg0, 0x14);
}

void func_8013DD80(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013DD60(arg0);
}

M2C_UNK Object_ApplyVelocity(void *);
s16 Object_FloorAt(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepGrowShrink(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK VectorNormalSS(void *, void *);

void func_8013DE44(void *arg0) {
    void *temp_a0;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        goto block_8;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13) != 0) {
        func_8013DC88(arg0);
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
        func_8013DC88(arg0);
    }
}

s32 func_8013DFA8(void *arg0) {
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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E02C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E340);

void func_8013E674(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013E6B4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013E6F8(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E774);

extern u8 D_80144118[];

void func_8013E990(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x1E;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    func_80070284(&v, D_80144118, 1, 0, 0);
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E9E0);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013ECCC);

void func_8013EEDC(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_80144A28[i].f_10 = 0;
    }
    Hook_Add(&func_8013F0CC);
}

typedef struct { u8 pad0[0x10]; s8 f; u8 pad[0x3]; } Slot_8013EF20;
extern Slot_8013EF20 D_80144A28_s[8] asm("D_80144A28");

s32 func_8013EF20(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_80144A28_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013EF5C);

M2C_UNK Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
extern s32 D_800EC208;
extern M2C_UNK g_Objects;

void func_8013F018(void *arg0) {
    s16 temp_a3;
    s32 var_v0;
    void *temp_s1;

    temp_s1 = (u8 *)&g_Objects + (M2C_FIELD(arg0, s8 *, 0x12) * 0xE4);
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 4), 0xC8) != 0) {
        temp_a3 = M2C_FIELD(arg0, s16 *, 2);
        var_v0 = (temp_a3 - D_800EC208) + 0x7D;
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 < 0xC9) {
            Object_AddAttackSphere(temp_s1, 0x64, M2C_FIELD(arg0, s16 *, 0), temp_a3, (s32) M2C_FIELD(arg0, s16 *, 4), 0x201, 0x202);
        }
    }
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F0CC);

void func_8013F170(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(arg1 | 0x7000, 0x1000, arg0 + 0x24);
    }
}

void func_8013F1B0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F1F4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F2A4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F318);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F390);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F4C8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F630);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F718);

void func_8013F800(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80144650 - 1;
    D_80144650 = temp_v0;
    if (temp_v0 == 0) {
        Link_SendEvent(0xF, 0x1E, 0);
    }
    func_80051E98(arg0, 1);
}

void func_8013F850(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 0xD;
    func_8013E9E0();
    func_8005588C(arg0, 0x3C);
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    Object_DisableCollision(arg0);
    Object_DropPickups(arg0);
    Object_PlaySound(arg0, 0x4D);
    Fx_DebrisExplosion(M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C));
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F8BC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013FAD4);

void func_8013FB24(void *arg0) {
    u8 temp_v0;
    u8 temp_v1;

    if ((M2C_FIELD(arg0, u8 *, 0xC8) != 0) && (temp_v1 = M2C_FIELD(arg0, u8 *, 0x80), (temp_v1 != 0xC)) && (temp_v1 != 0xD)) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x118, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xC8), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0, 0x100);
    }
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013FBDC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013FD38);

void func_801401F4(void) {
    s32 i;

    for (i = 5; i >= 0; i--) {
        D_80144AD0[i].f_10 = 0;
    }
    Hook_Add(&func_80140310);
}

typedef struct { u8 pad0[0x10]; s32 f; } Slot_80140238;
extern Slot_80140238 D_80144AD0_s[6] asm("D_80144AD0");

s32 func_80140238(void) {
    s32 i;

    for (i = 5; i >= 0; i--) {
        if (D_80144AD0_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

void func_80140274(void *arg0, void *arg1) {
    s32 temp_v0;
    void *temp_v1;

    temp_v0 = func_80140238();
    if (temp_v0 != -1) {
        temp_v1 = (void *)((u8 *)&D_80144AD0 + (temp_v0 * 0x14));
        M2C_FIELD(temp_v1, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
        M2C_FIELD(temp_v1, SVECTOR *, 8) = M2C_FIELD(arg1, SVECTOR *, 0);
        M2C_FIELD(temp_v1, s32 *, 0x10) = 3;
    }
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140310);

void func_80140380(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * arg2) >> 0xC));
    M2C_FIELD(arg1, s16 *, 2) = (s16) ((M2C_FIELD(arg0, u16 *, 0x28) + ((s32) (M2C_FIELD(arg0, s16 *, 0x62) * arg2) >> 0xC)) - 0x4C);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * arg2) >> 0xC));
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801403E8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140598);

void func_80140694(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

s32 func_801406FC(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), 0x800) == 0;
}

s32 func_80140730(void *arg0) {
    void *temp_a3;

    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        temp_a3 = Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF);
        if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) || ((M2C_FIELD(temp_a3, s16 *, 0x24) & 0xFF00) == 0x800)) {
            func_800525E0(arg0);
            func_80052864(arg0);
            return 1;
        }
        func_8005744C(arg0, (s16) (M2C_FIELD(temp_a3, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - M2C_FIELD(temp_a3, u16 *, 4)), (s16) (M2C_FIELD(temp_a3, u16 *, 8) - M2C_FIELD(arg0, u16 *, 0x2C)));
        Object_PlaySound(arg0, 0x67);
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140800);

s32 func_80140AA0(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xA) == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    } else {
        func_8008FC30(M2C_FIELD(arg0, s16 *, 0xC), arg0);
        M2C_FIELD(arg0, s16 *, 2) = 1;
    }
    return 0;
}

s32 func_80140AF0(void *arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 2);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (func_80140B7C(arg0) != 0) {
            func_8008FC30(M2C_FIELD(arg0, s16 *, 0xC), arg0);
            M2C_FIELD(arg0, s16 *, 2) = 1;
        }
        break;
    case 1:
        if (func_80140B7C(arg0) == 0) {
            func_8008FC30(M2C_FIELD(arg0, s16 *, 0xC), arg0);
            M2C_FIELD(arg0, s16 *, 2) = 0;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140B7C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140C00);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140CB4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140E1C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140F24);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014143C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014153C);

extern struct { u8 pad0[0x20C]; u8 *f_20C; } D_800F4350;

s32 func_80141790(u8 *a) {
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

s32 func_801418DC(u8 *a) {
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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141A6C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141B4C);

s32 func_80141C3C(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 0x8);
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    p[7] = -1;
    p[1] = 0;
    p[3] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141CB4);

extern struct S_g_Game_80141FCC { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141FCC asm("g_Game");

s32 func_80141FCC(s16 *p) {
    u8 *e = g_Game_80141FCC.f_820C + p[2] * 0x38;
    u8 *f = g_Game_80141FCC.f_8220 + p[4] * 0x18;
    s32 v = M2C_FIELD(f, s16 *, 2);

    if (v == 1) {
        p[1] = v;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    } else {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    }
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014205C);

s32 func_80142154(void *arg0) {
    s16 temp_a1;
    void *temp_a0;

    temp_a0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a0, u16 *, 0x34) = (u16) M2C_FIELD(temp_a0, u16 *, 8);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (M2C_FIELD(arg0, s16 *, 0x14) != 0) {
        temp_a1 = M2C_FIELD(temp_a0, s16 *, 0xE);
        if (temp_a1 >= 0) {
            M2C_FIELD(((temp_a1 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
        M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x18) | 0x8000);
        M2C_FIELD(arg0, s16 *, 2) = 2;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801421E4);

extern struct S_g_Game_801423C8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801423C8 asm("g_Game");
extern s16 D_800AFA22;

s32 func_801423C8(s16 *p) {
    u8 *e = g_Game_801423C8.f_8220 + p[4] * 0x18;
    s32 v = M2C_FIELD(e, s16 *, 2);

    if (v == 1) {
        p[1] = v;
        D_800AFA22 = v;
    } else {
        p[1] = 0;
        D_800AFA22 = 0;
    }
    p[3] = 0;
    return 0;
}

extern struct S_g_Game_80142424 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80142424 asm("g_Game");

s32 func_80142424(s16 *p) {
    u8 *e;
    s32 v;

    if (p[1] == 0) {
        e = g_Game_80142424.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            p[1] = v;
            D_800AFA22 = v;
        }
    }
    return 0;
}

s16 Sound_Play(s32, s32);

s32 func_8014247C(s16 *p) {
    s32 v = D_800AFA22;
    u8 *e;

    if (v == 1) {
        p[1] = v;
        e = g_Game.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    } else {
        p[1] = 0;
        p[11] = Sound_Play(1, 0x66);
    }
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142508);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014281C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142908);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142ACC);

extern struct S_g_Game_801426B4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801426B4 asm("g_Game");

s32 func_80142C10(s16 *p) {
    u8 *e = g_Game_801426B4.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142C9C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142D9C);

extern struct S_g_Game_80142EA0 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_80142EA0 asm("g_Game");
extern s32 D_800EC204;
void CamFlyby_StartSegment(s32);

s32 func_80142EA0(s16 *p) {
    u8 *e;

    if (p[1] == 0 && D_800EC204 > 0) {
        p[1] = 2;
        p[3] = 0;
        if (p[5] > 0) {
            CamFlyby_StartSegment(p[5] - 1);
            g_Game_80142EA0.f_8100 = 5;
        }
        e = g_Game_80142EA0.f_8220 + p[6] * 0x18;
        M2C_FIELD(e, s16 *, 2) = 0;
    }
    return 0;
}

s32 func_80142F40(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    if (SaveByte_Get(0xD) == 5) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 3;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142FB8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801430B0);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143158);

extern struct S_g_Game_80143600 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143600 asm("g_Game");
extern u8 *D_800B4D64_80143600 asm("D_800B4D64");
s32 SaveByte_Get_80143600(s32) asm("SaveByte_Get");
void Model_BindStageMesh(void *, s32);

s32 func_80143600(s16 *p) {
    u8 *e = g_Game_80143600.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 2) == 1 || SaveByte_Get_80143600(0xD) == 5) {
        p[1] = 2;
        Model_BindStageMesh(D_800B4D64_80143600 + p[6] * 32, p[7]);
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014369C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801437B4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801438E8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143A1C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143AEC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143BE4);

extern struct S_g_Game_80143CB8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143CB8 asm("g_Game");

s32 func_80143CB8(s16 *p) {
    u8 *e;

    e = g_Game_80143CB8.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 1;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct S_g_Game_80143D08 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_80143D08 asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_80143D08(s16 *p) {
    u8 *e;
    s32 v;

    if (p[1] == 0) {
        e = g_Game_80143D08.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            p[1] = v;
            CamFlyby_StartSegment(0);
            g_Game_80143D08.f_8100 = 7;
        }
    }
    return 0;
}

s32 func_80143D80(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

extern struct S_g_Game_80143D94 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143D94 asm("g_Game");

s32 func_80143D94(s16 *p) {
    u8 *e;

    if (p[1] == 0) {
        e = g_Game_80143D94.f_8220 + p[6] * 0x18;
        if (M2C_FIELD(e, s16 *, 2) == 1) {
            p[1] = 5;
        }
    }
    return 0;
}

s32 func_80143DE8(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    p[1] = 0;
    p[3] = 0;
    p[8] = e[0];
    p[9] = e[1];
    p[10] = e[2];
    p[11] = -1;
    e[0x13] = e[1];
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143E54);
