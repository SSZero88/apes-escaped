#include "common.h"
#include "m2c_macros.h"

s32 Stage_GetSpecialKind(void);
M2C_UNK func_8013D1AC();
M2C_UNK func_8013DA10();
M2C_UNK func_8013DAE8();
M2C_UNK func_8013DC68();
M2C_UNK func_8013DF90();
extern u8 D_800AF840;

extern struct S_D_800EC350 { u8 pad_0[0x8126]; u16 f_8126; } g_Game;
void func_80140D60(void);
void func_8013FD74(void);
void func_80140A60(void);
void func_8013FA2C(void);
void func_8013F464(void);
void func_801402D8(void *);
s32 func_8013D57C(void *);
s32 func_80143854(void *);
s32 func_8013F1AC(void *);
s32 func_8013E4B4(void *);

s32 Stage_GetSpecialKind(void) {
    u16 m = g_Game.f_8126;
    if (m == 0x44) {
        return 1;
    }
    if (m == 0x53) {
        return 2;
    }
    if (m == 0x56) {
        return 3;
    }
    if (m == 0x46) {
        return 4;
    }
    if (m == 0x57) {
        return 5;
    }
    return 0;
}

s32 func_8005AB6C(void) {
    return g_Game.f_8126 == 0x53;
}

void func_8005AB90(void) {
    s32 temp_v0;

    D_800AF840 = 0;
    temp_v0 = Stage_GetSpecialKind();
    switch (temp_v0) {
    case 1:
        func_8013DC68();
        return;
    case 2:
        func_8013D1AC();
        return;
    case 3:
        func_8013DAE8();
        return;
    case 4:
        func_8013DF90();
        return;
    case 5:
        func_8013DA10();
        /* fallthrough */
    default:
        return;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8005AB00_stage_special", jtbl_800A5360_pad);


/* Camera hook for the special areas (Stage_GetSpecialKind 1..5, unless D_800AF840 is set):
 * runs that area's overlay camera function (0x801402D8, 0x8013D57C, 0x80143854, 0x8013F1AC,
 * 0x8013E4B4). Returns 1 when it took over the camera (kind 1 always), else 0. */
s32 Camera_UpdateSpecial(void *a) {
    if (D_800AF840 == 0) {
        switch (Stage_GetSpecialKind()) {
        case 1:
            func_801402D8(a);
            return 1;
        case 2:
            if (func_8013D57C(a)) {
                return 1;
            }
            break;
        case 3:
            if (func_80143854(a)) {
                return 1;
            }
            break;
        case 4:
            if (func_8013F1AC(a)) {
                return 1;
            }
            break;
        case 5:
            if (func_8013E4B4(a)) {
                return 1;
            }
            break;
        case 0:
            break;
        }
    }
    return 0;
}



void func_8005ACE8(void) {
    if (D_800AF840 == 0) {
        switch (Stage_GetSpecialKind()) {
        case 1:
            func_80140D60();
            break;
        case 2:
            func_8013FD74();
            break;
        case 3:
            func_80140A60();
            break;
        case 4:
            func_8013FA2C();
            break;
        case 5:
            func_8013F464();
            break;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8005AB00_stage_special", jtbl_800A5390_pad);

