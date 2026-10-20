#include "common.h"
#include "m2c_macros.h"

s32 SaveByte_Get(M2C_UNK);
M2C_UNK Effect_SpawnAt(M2C_UNK, s32);
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_DropPickups(void *);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_8013DD64(void *);
M2C_UNK func_800525E0();
M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_HeadTowardSpike(void *, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s32);
s32 func_8013E308();
M2C_UNK func_8013E4C4(void *, M2C_UNK);
M2C_UNK func_8013E654(void *, M2C_UNK, M2C_UNK);
s32 func_8013E888();
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_800573A0(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801401D4(void *arg0);
extern s32 D_80145D24;
extern M2C_UNK D_80145D30;
s32 Spike_WithinRadiusXZ(s16, s16, s16);
s32 func_8013D0C8();
s32 func_8013D118(void);
void func_80140530(void *arg0);
extern s32 D_80145D20;
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_80145D40;
extern struct S_D_800E77A0 { u8 pad_0[0x1]; u8 f_1; } D_800E77A0;
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s32 func_801423E4();
s16 Sound_Play(M2C_UNK, M2C_UNK);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D000);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D0C8);

s32 func_8013D118(void) {
    return SaveByte_Get(1) == 5;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D13C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D230);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D4F8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D54C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D628);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D794);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DAFC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DC04);

void func_8013DD40(s32 arg0) {
    Effect_SpawnAt(4, arg0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DD64);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013DF2C);

void func_8013E134(void) {
    Link_SendEvent(8, 6, 0);
}

void func_8013E15C(void *arg0) {
    Object_PlaySound(arg0, 0x60);
}

void func_8013E17C(void *arg0) {
    func_8013E15C(arg0);
    M2C_FIELD(arg0, s8 *, 0x80) = 0xD;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    func_8005588C(arg0, 0x5A);
    func_8013DD64(arg0);
    Object_DropPickups(arg0);
    Object_DisableCollision(arg0);
}

void func_8013E1D0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E1F4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E308);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E334);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E384);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E4C4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E500);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E654);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E6A4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E7A8);

void func_8013E814(void *arg0) {
    Object_HeadTowardSpike(arg0, func_8013E308());
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), 0x2BC) == 0) {
        func_8013E4C4(arg0, 0xB);
    }
    Object_ApplyVelocity(arg0);
    func_8013E654(arg0, 0, 0x12);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E888);

void func_8013E8EC(void *arg0) {
    if (func_8013E888() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013E930);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013EA4C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F124);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F1CC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F4B4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F65C);

void func_8013F6DC(void *arg0) {
    s32 var_a0;

    var_a0 = 0;
    if (M2C_FIELD(arg0, u8 *, 0xDD) != 0) {
        var_a0 = 0xA00;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x20), var_a0 | 1, 0x201);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FB20);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FF2C);

void func_8014006C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
}

void func_80140088(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x80) = 7;
    if (arg1 != 0) {
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801400B4);

void func_801401D4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801401F8);

s32 func_80140244(void *arg0) {
    if ((D_80145D24 != 0) || (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) != 0xB)) {
        return 0;
    }
    func_800573A0(arg0, 0, 0, 0);
    Sound_PlayFixed(0x60);
    Sound_PlayFixed(0x15);
    Object_PlaySound(arg0, 0xB4);
    M2C_FIELD(arg0, s8 *, 0x7F) = 5;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
    func_801401D4(arg0);
    return 1;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801402D8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140358);

void func_80140398(s32 arg0, s32 arg1) {
    Puff_Spawn(arg0, 0, 0, arg1 + 0xFA);
}

void func_801403C0(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x78);
    func_80140398(M2C_FIELD(arg0, s32 *, 0x74), 0);
    func_80140398(temp_s0, 0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801403FC);

void func_80140530(void *arg0) {
    M2C_FIELD(&D_80145D30, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(&D_80145D30, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    M2C_FIELD(&D_80145D30, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140554);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801405BC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140610);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140778);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801408C8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014095C);

M2C_UNK Object_StepOnGroundFixed(s32);
s32 Object_WouldLeaveHome(void *, s16);

void func_801409AC(s32 arg0, s32 arg1) {
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_StepOnGroundFixed(arg0);
        return;
    }
    if ((arg1 != 0) && (D_80145D24 >= 0x1E)) {
        D_80145D24 = 0x1D;
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140A18);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140B40);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140C54);

void func_80140EE0(void *arg0) {
    if ((func_8013D0C8() != 0) && (func_8013D118() == 0) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) != 0)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        func_8005588C(arg0, 0x3C);
        func_80140530(arg0);
        D_80145D20 = 2;
    }
}

void func_80140F5C(void) {
    Link_SendEvent(5, 1, 0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140F84);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014183C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014194C);

void func_8014198C(void *arg0) {
    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn((void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10)), 0, 0, 0x64);
    }
}

void func_801419DC(void *arg0) {
    void *temp_v1;

    M2C_FIELD(arg0, u8 *, 0x8F) = (u8) D_800E77A0.f_1;
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 + 1);
    temp_v1 = (void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10));
    M2C_FIELD(temp_v1, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(temp_v1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) + 0x12C);
    M2C_FIELD(temp_v1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141A38);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141AE0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141C90);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141D64);

void func_80141DDC(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141EB8);

u32 Object_DetachLink(void *, s32);

void func_80141F38(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141FDC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142218);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801422E8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801423E4);

void func_80142418(void *arg0) {
    if (func_801423E4() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014246C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801424D4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801426B4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142840);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014296C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142CCC);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142DB0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80142FD8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143068);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014318C);

s32 func_80143240(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143248);

s32 func_801432E8(void) {
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801432F0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143344);

s32 func_80143524(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143534);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801436A8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801437E8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801439C8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143A64);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143B14);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143B8C);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143BF8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143CC0);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143E94);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143FA8);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144240);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144280);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144438);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801444E4);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801446D4);

s32 func_8014483C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 8) = Sound_Play(1, 0xB1);
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144870);
