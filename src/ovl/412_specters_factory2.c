#include "common.h"
#include "m2c_macros.h"

M2C_UNK Matrix_FromDirection(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
M2C_UNK func_80015780(void *, M2C_UNK);
M2C_UNK func_80016EBC(void *, M2C_UNK *, void *);
s32 func_80051410(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800E7D00;
extern M2C_UNK D_80141E40;
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; s32 f_820C; u8 pad_8210[0x10]; s32 f_8220; } g_Game;
M2C_UNK func_80141090(void *);
M2C_UNK func_80141134(void *);
extern s32 D_800B4D64;

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013D974;
extern struct S_D_80141DF0 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80141DF0[];
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
s32 Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
extern s32 D_80142000;
M2C_UNK Fx_DrawFadeRing(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_AddAttackSphereAt(void *, s32, M2C_UNK);
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s32);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
extern struct { u8 pad0[0xA]; s16 f_A; } D_800E68C0;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike;

void func_8013D000(void *arg0) {
    SVECTOR v;

    ((Scr_401 *)0x1F800000)->spike.vx = g_Spike.x;
    ((Scr_401 *)0x1F800000)->spike.vy = g_Spike.y;
    ((Scr_401 *)0x1F800000)->spike.vz = g_Spike.z;
    func_8004B8F4(arg0, 2, &v);
    v.vy += D_800E68C0.f_A;
    ((Scr_401 *)0x1F800000)->eye.vx = ((Scr_401 *)0x1F800000)->spike.vx;
    ((Scr_401 *)0x1F800000)->eye.vy = g_Spike.y - 0x100;
    ((Scr_401 *)0x1F800000)->eye.vz = ((Scr_401 *)0x1F800000)->spike.vz;
    func_80047558(arg0, 6, 6, 6);
    ((Scr_401 *)0x1F800000)->at.vx = (v.vx * 7 + ((Scr_401 *)0x1F800000)->spike.vx) / 8;
    ((Scr_401 *)0x1F800000)->at.vy = v.vy - D_800E68C0.f_A * 2;
    ((Scr_401 *)0x1F800000)->dir.vx = ((Scr_401 *)0x1F800000)->spike.vx - M2C_FIELD(arg0, s16 *, 0xA);
    ((Scr_401 *)0x1F800000)->dir.vy = 0;
    ((Scr_401 *)0x1F800000)->dir.vz = ((Scr_401 *)0x1F800000)->spike.vz - M2C_FIELD(arg0, s16 *, 0xE);
    VectorNormalSS(&((Scr_401 *)0x1F800000)->dir, &((Scr_401 *)0x1F800000)->dir);
    ((Scr_401 *)0x1F800000)->at.vz = ((Scr_401 *)0x1F800000)->spike.vz - ((Scr_401 *)0x1F800000)->dir.vz / 3;
    func_80047464(arg0, 6, 6, 6);
}

void func_8013D168(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void func_8013D208(s32 arg0) {
    void *temp_s0;

    temp_s0 = (void *)((u8 *)&D_80141E40 + (arg0 * 0x70));
    if (func_80051410(temp_s0 + 0x24, 0, 0) == 0) {
        Matrix_FromDirection(temp_s0 + 0x60, M2C_FIELD(temp_s0, s32 *, 0x14));
        func_80015780(temp_s0, 3);
        Model_ProjectBonedVerts(temp_s0);
        func_80016EBC((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, temp_s0);
    }
}

typedef struct { u8 pad0[0xC]; s16 f; u8 pad[0x6]; } Slot_411;
extern Slot_411 D_80141738_s[4] asm("D_80141DF0");

s32 func_8013D2AC(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_80141738_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013D2E8);

s32 func_8013D7CC(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013D810(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013D850(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013D890);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013D974);

void func_8013DB38(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80141DF0[i].f_C = 0;
    }
    Hook_Add(&func_8013D974);
}

extern u8 D_80141AA4[];
void func_80070284(void *, void *, s32, s32, void *);

void func_8013DB7C(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    func_80070284(m, D_80141AA4, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_80140110 asm("g_Game");
extern u8 D_80141A50[];

void func_8013DBB8(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_80140110 & 1) {
        func_80070284(m, D_80141A50, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8013DC04(void *arg0) {
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

void func_8013DC84(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
}

s32 Math_Atan2(s32, s32);

void func_8013DCD0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013DD5C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    Object_PlaySound(arg0, 0x6F);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    func_8005588C(arg0, 0xA);
}

s32 func_800563E0(void *, s32);

void func_8013DDA8(void *arg0) {
    func_800563E0(arg0, 0x14);
}

void func_8013DDC8(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013DDA8(arg0);
}

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);
M2C_UNK Object_ApplyVelocity(void *);
s16 Object_FloorAt(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepGrowShrink(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK VectorNormalSS(void *, void *);

void func_8013DE8C(void *arg0) {
    void *temp_a0;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        goto block_8;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13) != 0) {
        func_8013DCD0(arg0);
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
        func_8013DCD0(arg0);
    }
}

void func_800525E0(void *);
void func_80052864(void *);

s32 func_8013DFF0(void *arg0) {
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

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013E074);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013E388);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013E674);

void func_8013E884(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, arg0 + 0x24);
    }
}

void func_8013E8C4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

extern u8 D_80141B10[];

void func_8013E908(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x40;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    func_80070284(&v, D_80141B10, 1, 0, 0);
    func_80070284(&v, D_80141B10 + 0x54, 1, 0, 0);
}

extern u8 D_80141BB8[];

void func_8013E97C(void *pos) {
    SVECTOR d = { 0, -0x1000, 0 };

    func_80070284(pos, D_80141BB8, 1, 0, &d);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013E9D8);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013EADC);

void func_8013EB94(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x88);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, s8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_v1, u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) ((s32) -(arg1 * (s16) (((M2C_FIELD(temp_v1, u16 *, 0x12) + 5) - M2C_FIELD(temp_v1, u16 *, 0x10)) - 1)) / 2);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013EBF4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013EC78);

void func_8013EC78(void *, s16, s16, s32, s32);

void func_8013ED10(void *arg0, s16 n) {
    func_8013EC78(arg0, n * 50 + 0x104, 500 - n * 10, -0x14, 5);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013ED7C);

void func_8013D2E8(void *, s32, s32, s32, s32, s32);

void func_8013EE38(void *arg0, s16 n) {
    func_8013D2E8(arg0, 0xC8, n, 0xC8, 1, 1);
    func_8013D2E8(arg0, -0xC8, n, 0xC8, 1, 0);
}

s32 func_8005836C(void *, SVECTOR *, s32, s32);

void func_8013EEA8(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u32 *, 0xE0) & 1) {
        return;
    }
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        return;
    }
    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x190;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0xB4) = func_8005836C(arg0, &v, 0x104, 0x201);
}

void func_8013EF34(void *arg0) {
    s32 var_t0;
    s32 var_v1;

    if (D_80142000 != 0) {
        D_80142000 -= 1;
        return;
    }
    if (Object_DetachLink(arg0, 1) == 6) {
        if (M2C_FIELD(arg0, u8 *, 0x80) != 0x11) {
            D_80142000 = 0xA;
        }
    } else if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        var_t0 = 0x101;
        if (M2C_FIELD(arg0, u8 *, 0x80) == 0x11) {
            var_t0 = 0x203;
            var_v1 = 0x801;
        } else {
            var_v1 = 0x800;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphere(arg0, 0x104, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x190), (s32) M2C_FIELD(arg0, s16 *, 0x2C), var_v1, var_t0);
    }
}

void func_8013F010(void *arg0) {
    s32 a;

    if (M2C_FIELD(arg0, u8 *, 0x8F) <= 0x3C) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        if (M2C_FIELD(arg0, u8 *, 0x8F) & 1) {
            a = 0x3F;
        } else {
            a = 0x8E;
        }
    } else {
        a = 0x3F;
    }
    func_80052038(arg0, a);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F058);

void func_8013F1C0(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x1C, 0, 0, 0x12C);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F240);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F3A4);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F4B4);

M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);

void func_8013F660(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x80) != 0xF) {
        M2C_FIELD(arg0, u8 *, 0x80) = 0xFU;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x96) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        func_80052038(arg0, 0x3F);
        M2C_FIELD(arg0, s8 *, 0x82) = 0;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s16 *, 0x9C) + 0x538);
        func_8013EB94(arg0, 5);
        Object_TurnToward(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
        func_8005588C(arg0, 0x14);
    }
}

void func_8013F724(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (arg1 * 8);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & 0xFFFEFFFF);
    Object_PlaySound(arg0, 0xA8);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F760);

void func_8013F80C(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x74);
    Fx_DrawFadeRing(temp_s0, 0xC8, 4, 0x645050);
    Object_AddAttackSphereAt(arg0, temp_s0, 0xC8);
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013F860);

void func_8013F9C0(void *arg0, s32 arg1) {
    Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6) + arg1);
}

extern M2C_UNK D_80141F90;

void func_8013F9F4(void *obj) {
    func_8013D168(obj, &D_80141F90, 0xA0);
    func_8013DB38();
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013FA24);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_8013FB34);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_80140BD0);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_80140CDC);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_80140D60);

s32 func_80140F9C(void *arg0) {
    s32 var_s0;
    u16 temp_v0;
    void *temp_s1;

    temp_s1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_s1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_s1, u16 *, 0x18) & 0xFFF0) | 1);
    temp_v0 = M2C_FIELD(arg0, u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(temp_s1, u16 *, 0xE) = temp_v0;
    if ((s16) temp_v0 >= 0) {
        M2C_FIELD((((s16) temp_v0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, s16 *, 0xA) > 0) {
        do {
            func_80141090(arg0);
            if ((M2C_FIELD(temp_s1, u16 *, 0x18) & 0xF) != 1) {
                func_80141134(temp_s1);
            }
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s16 *, 0xA));
    }
    return 0;
}

s32 func_80141090(void *arg0) {
    s16 temp_a0;
    u16 temp_v0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 2) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 6) + 1;
        M2C_FIELD(arg0, u16 *, 6) = temp_v0;
        if (M2C_FIELD(arg0, s16 *, 8) < (s16) temp_v0) {
            M2C_FIELD(arg0, s16 *, 2) = 1;
            temp_a0 = M2C_FIELD(temp_a1, s16 *, 0xE);
            if (temp_a0 >= 0) {
                M2C_FIELD(((temp_a0 << 5) + D_800B4D64), u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(temp_a1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a1, u16 *, 0x18) & 0xFFF0) | 2);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_80141134);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_801413D8);

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_80141494);

s32 func_8014173C(s16 arg0, s16 arg1) {
    void *temp_a0;
    void *temp_v1;

    temp_a0 = g_Game.f_8220 + (arg0 * 0x18);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(temp_a0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 2);
    M2C_FIELD(temp_a0, s16 *, 2) = arg1;
    M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 0);
    M2C_FIELD(temp_a0, u16 *, 0x14) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
    M2C_FIELD(temp_a0, u16 *, 0x16) = (u16) M2C_FIELD(temp_v1, u16 *, 4);
    return 0;
}

s32 func_801417C8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 0x14) = -1;
    return 0;
}

INCLUDE_ASM("asm/ovl/412/nonmatchings/412_specters_factory2", func_801417DC);

extern u32 g_Game_80141960 asm("g_Game");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
void Sound_PlayAt(s32, void *);

s32 func_80141960(u8 *arg0) {
    if (g_Game_80141960 % 10 == 0) {
        Sound_PlayAt(((RAND() >> 8) & 3) + 0xB6, arg0 + 8);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
