#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8013D730();
M2C_UNK func_8013E994();
extern s32 D_80141158;
s32 Collision_GetShape(s32);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8005240C(void *, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
s32 func_8013D000();
M2C_UNK func_8013F368(void *);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D000);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D040);

void func_8013D1B0(void) {
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D1B8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D208);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D260);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D468);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D5A4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D648);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D6C4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D730);

void func_8013D7B4(void) {
    func_8013D730();
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D7D4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D80C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D8AC);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013D95C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013DA44);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013DDF8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013DE98);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013DF3C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013DFC4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E010);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E174);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E1C4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E214);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E284);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E2D8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E320);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E40C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E7D8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E82C);

void func_8013E934(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) - ((s32) -(M2C_FIELD(arg1, s16 *, 0x64) * 0x28) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_a2, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + ((s32) -(M2C_FIELD(arg1, s16 *, 0x60) * 0x28) >> 0xC));
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013E994);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013EA8C);

void func_8013EB8C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_8005240C(arg0, Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF));
        Sound_PlayFixed(0x5F);
        Sound_PlayFixed(0x15);
    }
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013EBE8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013EC54);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013EE34);

void func_8013EE80(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013EED0);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F100);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F144);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F26C);

void func_8013F300(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x74);
    M2C_FIELD(arg1, s16 *, 0) = (s16) ((M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(temp_a2, s16 *, 0) * 2)) / 3);
    M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1A4);
    M2C_FIELD(arg1, s16 *, 4) = (s16) ((M2C_FIELD(arg0, s32 *, 0x2C) + (M2C_FIELD(temp_a2, s16 *, 4) * 2)) / 3);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F368);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F3A4);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F484);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013F694);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013FA24);

void func_8013FC44(void *arg0, M2C_UNK arg1) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0xA00) != 0) {
        Object_PlaySound(arg0, arg1);
    }
}

void func_8013FC90(void) {
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8013FC98);

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

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140024);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_801400EC);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140140);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8014017C);

s32 func_801402B4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_801402F8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140338);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_801403C0);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8014059C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_801405C8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140658);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_801406E8);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_8014074C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140824);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140880);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140B0C);

INCLUDE_ASM("asm/ovl/397/nonmatchings/397", func_80140E40);
