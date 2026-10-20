#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Pad { u8 pad_0[0x1BC]; s16 f_1BC; s16 f_1BE; } g_Pad;
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x6]; u16 f_2C; } g_Spike;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

void * Object_AddAttackSphere(void *, s16, s16, s16, s16, s16, s16);
M2C_UNK Object_OrbitAround(void *, s16, s16, s32, s32);
extern s32 D_8014115C;
s16 func_80056010(void *, s16, s16, s32);

M2C_UNK func_8013D730();
M2C_UNK func_8013E994();
extern s32 D_80141158;
s32 Collision_GetShape(s32);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8005240C(void *, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 func_8013D000(void);
M2C_UNK func_8013F368(void *);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);

s32 func_8013D000(void) {
    if ((g_Pad.f_1BC >= 0x321) || (g_Pad.f_1BE >= 0x321)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D040);

void func_8013D1B0(void) {
}

void func_8013D1B8(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphere(arg0, 0x12C, M2C_FIELD(temp_v0, s16 *, 0), M2C_FIELD(temp_v0, s16 *, 2), (s32) M2C_FIELD(temp_v0, s16 *, 4), 1, 0x202);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D208);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D260);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D468);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D5A4);

s32 Object_SpikeBehind(s32, M2C_UNK, M2C_UNK, s16);
s32 Object_SpikeInFront(void *, s32, s32, s16);

s32 func_8013D648(s32 arg0, s16 arg1, s32 arg2) {
    s32 var_s1;

    var_s1 = Object_SpikeInFront(arg0, 0x5A, 0xB50, arg1);
    if (arg2 != 0) {
        var_s1 |= Object_SpikeBehind(arg0, 0x5A, 0xB50, arg1) * 2;
    }
    return var_s1;
}

M2C_UNK Object_ApplyVelocity(void *);
s16 Object_PathPointNear(void *, void *, s16, u8);
s32 func_800585D0(void *, s16, s8, s8);

s16 func_8013D6C4(void *arg0, s16 arg1, s16 arg2, s8 arg3) {
    func_800585D0(arg0, arg1, 0, arg3);
    Object_ApplyVelocity(arg0);
    return Object_PathPointNear(arg0, arg0 + 0x24, arg2, M2C_FIELD(arg0, u8 *, 0x8E));
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D730);

void func_8013D7B4(void) {
    func_8013D730();
}

void func_8013D7D4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0xAE);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D80C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D8AC);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013D95C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DA44);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DDF8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DE98);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DF3C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013DFC4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E010);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E174);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E1C4);

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
extern M2C_UNK D_80141168;
u32 Object_DetachLink(void *, s32);

void func_8013E214(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0xC9) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x12C, M2C_FIELD(&D_80141168, s16 *, 0), M2C_FIELD(&D_80141168, s16 *, 4), (s32) M2C_FIELD(&D_80141168, s16 *, 8), 1, 0x203);
}

void func_8013E284(void *arg0) {
    Object_OrbitAround(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), D_8014115C, (s32) func_80056010(arg0, 5, 2, 6));
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E2D8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E320);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E40C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E7D8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E82C);

void func_8013E934(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) - ((s32) -(M2C_FIELD(arg1, s16 *, 0x64) * 0x28) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_a2, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + ((s32) -(M2C_FIELD(arg1, s16 *, 0x60) * 0x28) >> 0xC));
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013E994);

void func_8013EA38(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 5) {
        D_80141158 = 1;
        func_8013E994();
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x80) == 1) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2U;
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EA8C);

void func_8013EB8C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_8005240C(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        Sound_PlayFixed(0x5F);
        Sound_PlayFixed(0x15);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EBE8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EC54);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EE34);

void func_8013EE80(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013EED0);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F100);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F144);

void func_8013F26C(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x80) - 2) >= 2U) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0)) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2U;
        M2C_FIELD(arg0, s8 *, 0x7F) = 2;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
        Object_PlaySound(arg0, 0xB3);
        M2C_FIELD(arg0, u16 *, 0xC2) = (u16) g_Spike.f_24;
        M2C_FIELD(arg0, u16 *, 0xC6) = (u16) g_Spike.f_2C;
    }
}

void func_8013F300(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x74);
    M2C_FIELD(arg1, s16 *, 0) = (s16) ((M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(temp_a2, s16 *, 0) * 2)) / 3);
    M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1A4);
    M2C_FIELD(arg1, s16 *, 4) = (s16) ((M2C_FIELD(arg0, s32 *, 0x2C) + (M2C_FIELD(temp_a2, s16 *, 4) * 2)) / 3);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F368);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F3A4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F484);

void func_8013F5FC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) & 1) {
        if ((M2C_FIELD(arg0, u8 *, 0x80) == 7) && ((func_8013D000() << 0x10) != 0)) {
            M2C_FIELD(arg0, u8 *, 0x80) = 1U;
            M2C_FIELD(arg0, s8 *, 0x7F) = 0;
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
            func_8005588C(arg0, 0x3C);
            return;
        }
        func_8013F368(arg0);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013F694);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013FA24);

void func_8013FC44(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void func_8013FC90(void) {
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8013FC98);

void func_8013FF84(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80141240[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80140024 asm("g_Game");

void func_80140024(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80141240 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game_80140024.f_80 + g_Game_80140024.f_C * 0x4078, &D_800E7D00, m);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_801400EC);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140140);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8014017C);

s32 func_801402B4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_801402F8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140338);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_801403C0);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8014059C);

void func_800525E0(void *);
void func_80052864(void *);
void func_800573A0(void *, s32, s32, s32);

void func_801405C8(void *arg0) {
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
void func_8014059C(void *);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_80140658 asm("g_Spike");

void func_80140658(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8014059C(arg0);
    Object_TurnToward(arg0, g_Spike_80140658.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike_80140658.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_801406E8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_8014074C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140824);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140880);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397_molten_lava", func_80140B0C);

s32 func_80140E40(void *arg0) {
    s16 temp_a0;
    void *temp_a1;

    temp_a1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    temp_a0 = M2C_FIELD(temp_a1, s16 *, 0x32);
    if ((temp_a0 == 1) || (temp_a0 == 0x3D) || (temp_a0 == 0xA1) || (temp_a0 == 0xDD)) {
        Sound_PlayAt(0x9C, temp_a1);
    }
    return 0;
}
