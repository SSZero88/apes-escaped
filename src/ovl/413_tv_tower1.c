#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_8013D94C(void *);
extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; s32 f_820C; } g_Game;
M2C_UNK Matrix_FromDirection(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
M2C_UNK func_80015780(void *, M2C_UNK);
M2C_UNK func_80016EBC(void *, M2C_UNK *, void *);
s32 func_80051410(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800E7D00;
extern M2C_UNK D_80144690;

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
extern M2C_UNK func_8013FB40;
extern struct S_D_80144640 { u8 pad_0[0xC]; s16 f_C; u8 pad_E[0x6]; } D_80144640[];
void *Collision_GetShape(s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
s16 rcos(s16);
s16 rsin(s16);
extern struct S_D_80144858 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80144858[];

extern struct S_g_Game_8013D000 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D000 asm("g_Game");
void func_8008FC30(s32, s16 *);

s32 func_8013D000(s16 *p) {
    u8 *e = g_Game_8013D000.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D08C);

extern struct S_g_Game_8013D19C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D19C asm("g_Game");
extern u8 *D_800B4D64;

s32 func_8013D19C(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game_8013D19C.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 0) {
        p[1] = 0;
    } else {
        p[1] = 2;
        if (p[6] >= 0) {
            M2C_FIELD(D_800B4D64 + p[6] * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D210);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D31C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D3C4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D46C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D548);

s32 func_8013D620(void *arg0) {
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_s0, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (M2C_FIELD(temp_s0, s16 *, 0x32) < ((M2C_FIELD(arg0, s16 *, 0xA) * 2) + 1)) {
        do {
            func_8013D94C(temp_s0);
        } while (M2C_FIELD(temp_s0, s16 *, 0x32) < ((M2C_FIELD(arg0, s16 *, 0xA) * 2) + 1));
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D6D0);

extern struct S_g_Game_8013D8D8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D8D8 asm("g_Game");

s32 func_8013D8D8(s16 *p) {
    u8 *e = g_Game_8013D8D8.f_820C + p[2] * 0x38;
    u8 *f;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    f = g_Game_8013D8D8.f_8220 + p[7] * 0x18;
    M2C_FIELD(f, s16 *, 2) = 5;
    p[1] = 1;
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013D94C);

extern struct S_g_Game_8013DBF0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013DBF0 asm("g_Game");

s32 func_8013DBF0(s16 *p) {
    u8 *e;

    p[3] = 0;
    if (p[10] == 0) {
        e = g_Game_8013DBF0.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(e, s16 *, 2) == 1) {
            p[1] = 1;
        } else {
            p[1] = 0;
        }
    } else {
        p[1] = 2;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DC5C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DD64);

extern struct S_g_Game_8013DE4C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013DE4C asm("g_Game");
void func_8004BD0C(void);

s32 func_8013DE4C(s16 *p) {
    u8 *e = g_Game_8013DE4C.f_8220 + p[4] * 0x18;
    s32 lo = M2C_FIELD(e, s16 *, 0x16) < p[5];

    p[1] = 0;
    if (!lo) {
        p[1] = 2;
        func_8004BD0C();
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013DEB4);

extern struct S_g_Game_8013DF6C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013DF6C asm("g_Game");

s32 func_8013DF6C(s16 *p) {
    u8 *e = g_Game_8013DF6C.f_820C + p[2] * 0x38;
    u8 *f = g_Game_8013DF6C.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(f, s16 *, 2) == 2) {
        p[1] = 1;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    } else {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    }
    p[11] = -1;
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E004);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E120);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E20C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E2A8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E3A4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E59C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E64C);

extern s32 D_80144630;

s32 func_8013E704(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    p[1] = 0;
    p[3] = 0;
    p[8] = e[0];
    p[9] = e[1];
    p[10] = e[2];
    D_80144630 = -1;
    e[0x13] = e[1];
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E774);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EA44);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EB94);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013ED24);

extern struct S_g_Game_8013EDA0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013EDA0 asm("g_Game");

s32 func_8013EDA0(s16 *p) {
    u8 *e = g_Game_8013EDA0.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013EE2C);

extern struct S_g_Game_8013EF2C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013EF2C asm("g_Game");

s32 func_8013EF2C(s16 *p) {
    u8 *e;

    e = g_Game_8013EF2C.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 1;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct S_g_Game_8013EF7C { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_8013EF7C asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_8013EF7C(s16 *p) {
    u8 *e;
    s32 v;

    if (p[1] == 0) {
        e = g_Game_8013EF7C.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            p[1] = v;
            CamFlyby_StartSegment(3);
            p[3] = 0;
            g_Game_8013EF7C.f_8100 = 7;
        }
    }
    return 0;
}

extern SVECTOR D_80144638;
extern struct { u8 pad0[0x60]; SVECTOR f_60; } g_Spike_8013D000 asm("g_Spike");
void Camera_ExitLook(void);
void func_80048748(void);

void func_8013F000(void) {
    D_80144638 = g_Spike_8013D000.f_60;
    Camera_ExitLook();
    func_80048748();
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F058);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F148);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F37C);

void func_8013F4B0(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void func_8013F550(s32 arg0) {
    void *temp_s0;

    temp_s0 = (void *)((u8 *)&D_80144690 + (arg0 * 0x70));
    if (func_80051410(temp_s0 + 0x24, 0, 0) == 0) {
        Matrix_FromDirection(temp_s0 + 0x60, M2C_FIELD(temp_s0, s32 *, 0x14));
        func_80015780(temp_s0, 3);
        Model_ProjectBonedVerts(temp_s0);
        func_80016EBC((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &D_800E7D00, temp_s0);
    }
}

typedef struct { u8 pad0[0xC]; s16 f; u8 pad[0x6]; } Slot_411;
extern Slot_411 D_80141738_s[4] asm("D_80144640");

s32 func_8013F5F4(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_80141738_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F630);

s32 func_8013FA7C(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void func_8013FAC0(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013FB00(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FB40);

void func_8013FD48(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        D_80144640[i].f_C = 0;
    }
    Hook_Add(&func_8013FB40);
}

extern u8 D_80141788_8013E464[] asm("D_80144690");

void func_8013FD8C(void *arg0) {
    func_8013F4B0(arg0, D_80141788_8013E464, 0x85);
    func_8013F4B0(arg0, D_80141788_8013E464 + 0x70, 0x86);
    func_8013F4B0(arg0, D_80141788_8013E464 + 0xE0, 0xB4);
    func_8013F4B0(arg0, D_80141788_8013E464 + 0x150, 0x87);
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
    func_8013FD48();
}

typedef struct { u8 b[0x54]; } FxDef_411;
extern u32 g_Game_8013E4D8 asm("g_Game");
extern FxDef_411 D_80144418[][2];
void *memset(void *, s32, s32);
void *memset(void *, s32, s32);
M2C_UNK func_80070284(s32, M2C_UNK *, M2C_UNK, M2C_UNK, s32);

void func_8013FE00(void *arg0, s32 n) {
    SVECTOR w;
    SVECTOR v;

    if ((g_Game_8013E4D8 & 3) == 0) {
        memset(&v, 0, 8);
        v.vx = M2C_FIELD(arg0, u16 *, 0x9A);
        v.vy = M2C_FIELD(arg0, u16 *, 0x9C);
        v.vz = M2C_FIELD(arg0, u16 *, 0x9E);
        w = v;
        func_80070284(&w, &D_80144418[n][0], 1, 0, 0);
        func_80070284(&w, &D_80144418[n][1], 1, 0, 0);
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013FEE8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801400A4);

s32 func_8014018C(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x1200) != 0)) {
        if ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) == 0x800) {
            return 1;
        }
        Object_PlaySound(arg0, 0x67);
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

void func_8014020C(void *arg0) {
    s32 temp_v1;
    u8 temp_a1;

    if (M2C_FIELD(arg0, u8 *, 0x81) != 0) {
        temp_a1 = M2C_FIELD(arg0, u8 *, 0xCF);
        if (temp_a1 == 1) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0xE0);
            if (!(temp_v1 & 1)) {
                M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 | 1);
                M2C_FIELD(arg0, s8 *, 0x80) = 2;
                M2C_FIELD(arg0, u8 *, 0x7F) = 0U;
                M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0);
                return;
            }
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v1 & ~1);
            M2C_FIELD(arg0, s8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = temp_a1;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x5E) = 2;
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140298);

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_801404A4(void *arg0, s32 on) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = p[1] + 0xF0;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Monkey_DrawHelmetLight(&v, 2, on != 0);
}

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_801404EC asm("g_Spike");
s32 Vec_Length(s32, s32, s32);

s32 func_801404EC(void *arg0) {
    s32 d = Vec_Length(g_Spike_801404EC.x - M2C_FIELD(arg0, s32 *, 0x24), 0, g_Spike_801404EC.z - M2C_FIELD(arg0, s32 *, 0x2C));

    if (d < 0x400) {
        return 0x1E;
    }
    return d * 50 / 3584;
}

void func_80140578(void *arg0) {
    u8 temp_v0;

    if ((M2C_FIELD(arg0, u8 *, 0xC8) != 0) && (M2C_FIELD(arg0, u8 *, 0x80) != 7)) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x7D) >> 0xB)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xC8), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x7D) >> 0xB)), 0, 0x100);
    }
}

extern u16 g_RandSeed;
void Effect_SpawnAt(s32, SVECTOR *);
void Object_PlaySound_8013F264(void *, s32) asm("Object_PlaySound");
s32 rcos_8013F264(s32) asm("rcos");
s32 rsin_8013F264(s32) asm("rsin");
extern u32 g_Game_8013F264 asm("g_Game");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140670(void *arg0) {
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

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801407DC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140DAC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140E94);

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_80140FA0(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80140FD4);

void func_8014102C(void *arg0, s32 a) {
    if (a != 0) {
        a = 0xC;
    } else {
        a = 6;
    }
    func_80052038(arg0, a);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014105C);

M2C_UNK func_8014105C(void *, M2C_UNK, M2C_UNK);

void func_80141214(s32 arg0) {
    func_8014105C(arg0, 0, 0);
    Object_PlaySound(arg0, 0xA0);
}

void func_8014124C(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        func_800525E0();
        func_80052864(arg0);
    }
}

void func_80141290(void *arg0) {
    func_80052038(arg0, 6);
    M2C_FIELD(arg0, s8 *, 0x8F) = 0;
}

s32 func_801412BC(void *arg0) {
    if (func_80140FA0(arg0) == 0) {
        func_80141290(arg0);
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801412FC);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8014173C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141840);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801418D8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141998);

void func_801419F0(void *arg0)
{
  u16 new_var;
  *((u8 *) (((s8 *) arg0) + 0x80)) = 3;
  *((u8 *) (((s8 *) arg0) + 0x7F)) = 0;
  new_var = *(*((u16 **) (((s8 *) arg0) + 0x88)));
  *((s16 *) (((s8 *) arg0) + 0xA8)) = 0;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var;
  *((u32 *) (((s8 *) arg0) + 0xE0)) |= 0x10000;
}

s32 func_80141A20(s32 x) {
    if (x == 0) {
        return 0;
    }
    if (x > 0) {
        return 1;
    }
    return -1;
}

void func_80141A40(s16 *p, s32 lim) {
    if (*p > 0) {
        *p -= 5;
        if (*p > lim) {
            *p = lim;
        }
    } else if (*p < 0) {
        *p += 5;
        if (*p < -lim) {
            *p = -lim;
        }
    }
}

void func_80141A98(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_80141A20(M2C_FIELD(arg0, s16 *, 0xA8) - M2C_FIELD(arg0, s16 *, 0xC2)) * 0x14));
    func_80141A40(arg0 + 0xD4, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xC2) = (s16) (u16) M2C_FIELD(arg0, s16 *, 0xA8);
}

M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_TurnTowardSpike(void *);
s32 Object_WouldLeaveHome(void *, M2C_UNK);
M2C_UNK func_80055718(void *, s16, s16, s16, s32);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_80141AF8(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x1E, 0x14, 0);
    }
    func_80055718(arg0, arg1, arg2, arg3, (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13);
    Object_TurnTowardSpike(arg0);
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

void func_80141BB0(void *arg0) {
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0xAC) + M2C_FIELD(arg0, s16 *, 0xB0);
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_v1 + 0xFFF;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0);
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
}

void func_80141C1C(void *arg0) {
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9C), M2C_FIELD(arg0, s16 *, 0x9E), 0xA) == 0) {
        Object_ApplyVelocity(arg0);
        return;
    }
    func_80141BB0(arg0);
}

void func_80141C74(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        if (Object_DetachLink(arg0, 0) == 6) {
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x202);
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141CFC);

s32 func_80142058(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_80144858[i].f_A = 0;
    }
    return 0;
}

typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Spark_411;

void func_80142080(SVECTOR *pos, s32 n) {
    s32 i;
    Spark_411 *p;
    s16 x;
    s16 y;
    s16 z;

    x = pos->vx;
    y = pos->vy;
    z = pos->vz;
    for (i = 63; i >= 0; i--) {
        p = &D_80144858[i];
        if (p->life == 0) {
            p->life = ((RAND() >> 8) & 0x1F) + 0x28;
            p->x = x + ((RAND() >> 8) - 0x80);
            p->y = y - ((RAND() >> 8) - 0x80);
            p->z = z + ((RAND() >> 8) - 0x80);
            p->vx = ((RAND() >> 8) - 0x80) / 4;
            p->vy = -((RAND() >> 8) & 0x3F) - 8;
            p->vz = ((RAND() >> 8) - 0x80) / 4;
            if (--n == 0) {
                return;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80142200);

M2C_UNK func_80070284(s32, M2C_UNK *, M2C_UNK, M2C_UNK, s32);
extern M2C_UNK D_800B1C7C;

void func_8014263C(s32 arg0, s32 arg1) {
    func_80142080(arg0, 0x20);
    func_80070284(arg0, &D_800B1C7C, 1, 0, arg1);
    func_80070284(arg0, (u8 *)&D_800B1C7C + 0x2A0, 1, 0, arg1);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801426B0);

extern u8 *D_800B4DC4;

void func_8014283C(void) {
    u8 *o;

    o = D_800B4DC4;
    M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 0) = M2C_FIELD(o, s16 *, 0x78);
    M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 2) = M2C_FIELD(o, s16 *, 0x7A);
    M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(M2C_FIELD(o, s16 **, 0x70), s16 *, 4) = M2C_FIELD(o, s16 *, 0x7C);
    M2C_FIELD(M2C_FIELD(o, u8 **, 0x70), u16 *, 0x18) &= 0x7FFF;
    M2C_FIELD(o, SVECTOR *, 0x60) = M2C_FIELD(o, SVECTOR *, 0x80);
    M2C_FIELD(o, s16 *, 0x6A) = 0x1000;
    M2C_FIELD(o, s16 *, 0x68) = 0;
    M2C_FIELD(o, s16 *, 0x6C) = 0;
    M2C_FIELD(o, u8 *, 0x8E) = 6;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801428E4);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801431B0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_801433F0);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80143F38);
