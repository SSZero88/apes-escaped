#include "common.h"
#include "m2c_macros.h"

void Object_PlaySound(void *, s32);

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
s32 func_8013D1E0();
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s32 func_8013FA40(s32);
M2C_UNK func_8013FA60(void *, M2C_UNK);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D000);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D0EC);

s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern u8 D_80141850[];

void func_8013D144(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        func_80070284(&v, D_80141850, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D1E0);

s32 func_8013D210(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013D240(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013D27C(void *arg0) {
    if ((func_8013D210(arg0) == 0) && (func_8013D240(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D2D0);

void func_8013D430(s32 arg0) {
    if (func_8013D1E0() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013D474(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013D4B4(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D51C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D804);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D89C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013DB40);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013DD40);

void func_8013DF78(void *arg0, void *arg1, M2C_UNK arg2) {
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
extern u8 D_80142270[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void func_8013E018(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80142270 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, &D_800E7D00, m);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E0E0);

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801421D0");

s32 func_8013E128(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E164);

s32 func_8013E2A4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013E2E0(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013E320(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E360);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E528);

void func_800573A0(void *, s32, s32, s32);

void func_8013E554(void *arg0) {
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
void func_8013E528(void *);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013E5E4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013E528(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

M2C_UNK func_8013E164(void *, M2C_UNK, M2C_UNK);

void func_8013E674(void *obj) {
    func_8013E164(obj, 0x46, 0xA0);
}

void func_8013E0E0(void *);
void Object_DisableCollision(void *);

void func_8013E698(void *arg0) {
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
    func_8013E0E0(arg0);
    Object_DisableCollision(arg0);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E778);

void func_8013EC60(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013ECA0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013ECE4(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013ED60);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013EF7C);

s32 Math_Atan2(s32, s32);

void func_8013F0EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013F178(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_8013F1B0(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F278);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F39C);

void func_8013F3EC(void *arg0) {
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

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F460);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F7F8);

extern s32 D_800EC208;
extern s32 D_801422E0;
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013F8BC(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA6)) == 0) {
        var_v0 = D_800EC208 >= D_801422E0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F91C);

extern u16 g_RandSeed;

void func_8013F9D4(void *arg0) {
    u16 temp_a1;

    M2C_FIELD(arg0, s8 *, 0x80) = 1;
    temp_a1 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_a1;
    func_8005588C(arg0, ((u32) (temp_a1 & 0xFFFF) >> 9) + 0x40);
}

void func_8013FA20(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x10000);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FA40);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FA60);

void func_8013FAB8(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0xBC)) * 0xA));
    M2C_FIELD(arg0, u16 *, 0xD6) = (u16) (M2C_FIELD(arg0, u16 *, 0xD6) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0xC0)) * 0xA));
    func_8013FA60(arg0 + 0xD4, 0x17C);
    func_8013FA60(arg0 + 0xD6, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x2C);
}

M2C_UNK Object_ApplyVelocity(void *);
s32 Object_WouldLeaveHome(void *, M2C_UNK);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013FB54(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x1E, 0x14, 0);
    }
    func_80055718(arg0, arg1, arg2, arg3, (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13);
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

void func_8013FC04(void *arg0) {
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9C), M2C_FIELD(arg0, s16 *, 0x9E), 0xA) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
u32 Object_DetachLink(void *, s32);

void func_8013FC4C(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        if (Object_DetachLink(arg0, 0) == 6) {
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xD7), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x202);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FCE0);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FFC8);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140124);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140738);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140864);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8014090C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140AFC);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8014163C);
