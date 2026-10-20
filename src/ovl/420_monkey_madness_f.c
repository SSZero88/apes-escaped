#include "common.h"
#include "m2c_macros.h"

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
s32 func_80140238();
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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D028);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D218);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D6B8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D73C);

void func_8013D840(s32 arg0) {
    u16 temp_v0;

    Puff_Spawn(arg0 + 0x24, 1, 0, 0x12C);
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D8A8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013D9A8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DAC8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DB34);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DB70);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DC3C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DC88);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DE44);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013DFA8);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E6F8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E774);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E990);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013E9E0);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013ECCC);

void func_8013EEDC(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_80144A28[i].f_10 = 0;
    }
    Hook_Add(&func_8013F0CC);
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013EF20);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013EF5C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8013F018);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140238);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80140694);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801406FC);

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

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141790);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801418DC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141A6C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141B4C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141C3C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141CB4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80141FCC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014205C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142154);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801421E4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801423C8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142424);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014247C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142508);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014281C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142908);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142ACC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142C10);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142C9C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142D9C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142EA0);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142F40);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80142FB8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801430B0);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143158);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143600);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_8014369C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801437B4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_801438E8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143A1C);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143AEC);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143BE4);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143CB8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143D08);

s32 func_80143D80(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143D94);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143DE8);

INCLUDE_ASM("asm/ovl/420/nonmatchings/420_monkey_madness_f", func_80143E54);
