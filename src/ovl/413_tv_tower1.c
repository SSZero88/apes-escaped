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

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x1C]; u16 f_8120; u8 pad_8122[0x2E]; u16 f_8150; u8 pad_8152[0xCE]; u8 *f_8220; } g_Game_8013D08C asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_8013D08C(s16 *p) {
    u8 *e;

    switch (p[1]) {
    case 0:
        e = g_Game_8013D08C.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(e, s16 *, 0x16) > p[5] && g_Game_8013D08C.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_8013D08C.f_8150 == 0) {
            func_8008FC30(p[7], p);
            func_8008FC30(p[8], p);
            p[1] = 2;
            if (g_Game_8013D08C.f_8120 != 0x13) {
                if (p[6] > 0) {
                    CamFlyby_StartSegment(p[6] - 1);
                    g_Game_8013D08C.f_8100 = 7;
                }
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}

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

extern struct S_g_Game_8013D210 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D210 asm("g_Game");

s32 func_8013D210(s16 *p) {
    s32 pad[2];
    u8 *e = g_Game_8013D210.f_8220 + p[4] * 0x18;

    switch (p[1]) {
    case 0:
        if (M2C_FIELD(e, s16 *, 2) == 1) {
            p[1] = 1;
            p[3] = 0;
            p[5] = M2C_FIELD(D_800B4D64 + p[6] * 32, u16 *, 0x12);
            break;
        }
        return 0;
    case 1:
        p[3] += p[7];
        if (p[8] < p[3]) {
            p[1] = 2;
            if (p[6] >= 0) {
                M2C_FIELD(D_800B4D64 + p[6] * 32, s16 *, 0x16) = 0;
            }
        }
        M2C_FIELD(D_800B4D64 + p[6] * 32, u16 *, 0x12) = p[5] + p[3];
        break;
    case 2:
        return 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D31C asm("g_Game");
extern u8 *D_800B4D64_8013D31C asm("D_800B4D64");
void Model_BindStageMesh(void *, s32);

s32 func_8013D31C(s16 *p) {
    u8 *t;

    p[3] = 0;
    t = g_Game_8013D31C.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(t, s16 *, 2) == 0) {
        p[1] = 0;
    } else {
        p[1] = 1;
        if (p[6] >= 0) {
            if (p[7] >= 0) {
                Model_BindStageMesh(D_800B4D64_8013D31C + p[6] * 32, p[7]);
            } else {
                M2C_FIELD(D_800B4D64_8013D31C + p[6] * 32, s16 *, 0x16) = 0;
            }
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D3C4 asm("g_Game");
extern u8 *D_800B4D64_8013D3C4 asm("D_800B4D64");

s32 func_8013D3C4(s16 *p) {
    u8 *t = g_Game_8013D3C4.f_8220 + p[4] * 0x18;

    if (p[1] == 0 && M2C_FIELD(t, s16 *, 2) == 1) {
        p[1] = 1;
        if (p[6] >= 0) {
            if (p[7] >= 0) {
                Model_BindStageMesh(D_800B4D64_8013D3C4 + p[6] * 32, p[7]);
            } else {
                M2C_FIELD(D_800B4D64_8013D3C4 + p[6] * 32, s16 *, 0x16) = 0;
            }
        }
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013D46C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013D46C *f_8220; } g_Game_8013D46C asm("g_Game");
typedef struct { s16 f_0; s16 state; s16 ent; s16 timer; s16 arg[4]; } Cmd_8013D46C;

s32 func_8013D46C(Cmd_8013D46C *p) {
    u8 *e;
    s32 i;
    s16 idx;

    S18_8013D46C *t;

    e = g_Game_8013D46C.f_820C;
    p->timer = 0;
    t = &g_Game_8013D46C.f_8220[p->arg[0]];
    e += p->ent * 0x38;
    if (t->f_2 == 0) {
        p->state = 0;
    } else {
        p->state = 1;
        M2C_FIELD(e, u16 *, 0x12) = M2C_FIELD(e, u8 *, 0x12);
        for (i = 0; i < 2; i++) {
            idx = p->arg[i + 2];
            if (idx >= 0) {
                t = &g_Game_8013D46C.f_8220[idx];
                e = g_Game_8013D46C.f_820C + t->f_4 * 0x38;
                M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            }
        }
    }
    return 0;
}

typedef struct { s16 f0, st, f4, f6; s16 ids[8]; } P_8013D548;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D548 asm("g_Game");

s32 func_8013D548(P_8013D548 *p) {
    u8 *e = g_Game_8013D548.f_820C + p->f4 * 0x38;
    u8 *t = g_Game_8013D548.f_8220 + p->ids[0] * 0x18;
    s32 i;

    if (p->st == 0 && M2C_FIELD(t, s16 *, 2) == 1) {
        p->st = 1;
        M2C_FIELD(e, u16 *, 0x12) = M2C_FIELD(e, u8 *, 0x12);
        for (i = 0; i < 2; i++) {
            if (p->ids[i + 2] >= 0) {
                t = g_Game_8013D548.f_8220 + p->ids[i + 2] * 0x18;
                e = g_Game_8013D548.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
                M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            }
        }
    }
    return 0;
}

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

typedef struct { u8 pad_0[0x16]; s16 f_16; } S18_8013DD64;
extern struct { u8 pad_0[0x8220]; S18_8013DD64 *f_8220; } g_Game_8013DD64 asm("g_Game");
extern u8 *D_800B4D64_8013DD64 asm("D_800B4D64");

s32 func_8013DD64(s16 *p) {
    s32 i;
    s32 n;
    S18_8013DD64 *t;

    if (p[5] >= 0 && p[6] >= 0 && p[7] >= 0) {
        t = &g_Game_8013DD64.f_8220[p[5]];
        n = t->f_16;
        for (i = 0; i < p[4]; i++) {
            if (i < n - p[8]) {
                Model_BindStageMesh(D_800B4D64_8013DD64 + (p[6] + i) * 32, p[7]);
            }
        }
    }
    return 0;
}

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

extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xCE]; u8 *f_8220; } g_Game_8013DEB4 asm("g_Game");

s32 func_8013DEB4(s16 *p) {
    u8 *t;

    switch (p[1]) {
    case 0:
        t = g_Game_8013DEB4.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 0x16) >= p[5]
            && g_Game_8013DEB4.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_8013DEB4.f_8150 == 0) {
            p[1] = 2;
            func_8004BD0C();
        }
        break;
    case 2:
        break;
    }
    return 0;
}

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

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013E004;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013E004 *f_8220; } g_Game_8013E004 asm("g_Game");
s32 Sound_Play(s32, s32);
void Sound_Stop(s32, s32);

s32 func_8013E004(s16 *p) {
    u8 *e = g_Game_8013E004.f_820C + p[2] * 0x38;
    S18_8013E004 *t;

    switch (p[1]) {
    case 0:
        t = &g_Game_8013E004.f_8220[p[4]];
        if (t->f_2 == 2) {
            p[1] = 1;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            CamFlyby_StartSegment(2);
            p[3] = 0;
            g_Game_8013E004.f_8100 = 7;
            p[11] = Sound_Play(0, 0xB1);
        }
        break;
    case 1:
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6] * 2) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 2;
            Sound_Stop(0xB1, p[11]);
            g_Game_8013E004.f_8100 = 0;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013E120;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013E120 *f_8220; } g_Game_8013E120 asm("g_Game");
extern u8 *D_800B4D64_8013E120 asm("D_800B4D64");

s32 func_8013E120(s16 *p) {
    u8 *e = g_Game_8013E120.f_820C + p[2] * 0x38;
    S18_8013E120 *t = &g_Game_8013E120.f_8220[p[4]];

    if (t->f_2 != 0) {
        p[1] = 1;
        if (M2C_FIELD(e, u16 *, 0x18) & 0x8000) {
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013E120 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
        } else {
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013E120 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
        }
    } else {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013E120 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    p[3] = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E20C);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E2A8);

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013E3A4);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[8]; u8 *f_8218; u8 pad_821C[4]; u8 *f_8220; } g_Game_8013E59C asm("g_Game");

s32 func_8013E59C(s16 *p) {
    u8 *t = g_Game_8013E59C.f_8220 + p[4] * 0x18;
    u8 *e;
    s16 *q;

    if (M2C_FIELD(t, s16 *, 2) != 0) {
        p[1] = 1;
        e = g_Game_8013E59C.f_820C + p[2] * 0x38;
        if (M2C_FIELD(e, s16 *, 0x30) >= 0) {
            q = (s16 *)(g_Game_8013E59C.f_8218 + M2C_FIELD(e, s16 *, 0x30) * 16);
            if (q[0] == 3 && q[1] == 0x5A) {
                q[2] = p[5];
            }
        }
    } else {
        p[1] = 0;
    }
    p[3] = 0;
    return 0;
}

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

extern struct S_g_Game_8013EA44 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013EA44 asm("g_Game");
void func_8013ED24(void *);
void func_800147D0(SVECTOR *, void *);

s32 func_8013EA44(s16 *p) {
    SVECTOR v;
    u8 *s;
    u8 *e = g_Game_8013EA44.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    p[3] = 0;
    if (p[5] >= 0 && M2C_FIELD(s = g_Game_8013EA44.f_8220 + p[5] * 0x18, s16 *, 2) == 1) {
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
        }
        p[1] = 3;
    loop:
        if (M2C_FIELD(e, s16 *, 0x32) < p[6]) {
            func_8013ED24(e);
            goto loop;
        }
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            v.vx = 0x1000;
            v.vy = 0x1000;
            v.vz = 0x1000;
            func_800147D0(&v, M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
        }
        return 0;
    }
    p[1] = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013EB94 asm("g_Game");
s32 Sound_PlayFixed(s32);

s32 func_8013EB94(s16 *p) {
    u8 *s;
    u8 *e = g_Game_8013EB94.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (p[5] >= 0) {
            s = g_Game_8013EB94.f_8220 + p[5] * 0x18;
            if (M2C_FIELD(s, s16 *, 2) == 1) {
                p[1] = 1;
                p[3] = 0;
            }
        }
        break;
    case 1:
        if (++p[3] > 10) {
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = 2;
            if (p[7] > 0) {
                p[10] = Sound_Play(0, 0xB1);
                Sound_PlayFixed(0x9B);
            }
        }
        break;
    case 2:
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6]) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 3;
            if (p[7] > 0) {
                Sound_Stop(0xB1, p[10]);
                Sound_PlayFixed(0x9B);
            }
        }
        break;
    }
    return 0;
}

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

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x4C]; u16 f_8150; u8 pad_8152[0xCE]; struct S18_80142C9C { s16 f[12]; } *f_8220; } g_Game_80142C9C asm("g_Game");
void CamFlyby_StartSegment(s32);
void CamFlyby_StartSegment(s32);
void CamFlyby_StartSegment(s32);

s32 func_8013EE2C(s16 *p) {
    struct S18_80142C9C *t;

    switch (p[1]) {
    case 0:
        t = g_Game_80142C9C.f_8220 + p[4];
        if (t->f[11] > p[5]) {
            if (g_Game_80142C9C.f_8150 == 8) {
                p[1] = 1;
            }
        }
        break;
    case 1:
        if (g_Game_80142C9C.f_8150 == 0) {
            func_8008FC30(p[7], p);
            func_8008FC30(p[8], p);
            if (p[6] > 0) {
                CamFlyby_StartSegment(p[6] - 1);
                g_Game_80142C9C.f_8100 = 7;
            }
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

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

typedef struct { u32 tag; u32 tpage; u32 rgbc; u32 xy; u32 uvclut; u32 wh; } Spr_8013F058;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013F058 asm("g_Game");

void func_8013F058(void) {
    Spr_8013F058 *p;
    u32 *ot;
    s32 t;
    s32 b;

    t = g_Game_8013F058.frame & 0x1F;
    b = g_Game_8013F058.frame & 8;
    if (t >= 16) {
        t = 31 - t;
    }
    t = t * 8 + 0x60;
    p = (Spr_8013F058 *)g_Game_8013F058.prim;
    ot = &g_Game_8013F058.db[g_Game_8013F058.cur].ot[1];
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100021B;
    p->rgbc = (t << 16) | (t << 8) | t | 0x66000000;
    p->xy = 0x6800A4;
    p->wh = 0x200038;
    p->uvclut = (b << 10) | 0x7CED00A0;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    g_Game_8013F058.prim = (u8 *)(p + 1);
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_8013F148);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013F37C;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike_8013F37C asm("g_Spike");
extern s16 D_800E68CA;
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);

void func_8013F37C(void *arg0) {
    SVECTOR v;

    ((Scr_8013F37C *)0x1F800000)->spike.vx = g_Spike_8013F37C.x;
    ((Scr_8013F37C *)0x1F800000)->spike.vy = g_Spike_8013F37C.y;
    ((Scr_8013F37C *)0x1F800000)->spike.vz = g_Spike_8013F37C.z;
    func_8004B8F4(arg0, 2, &v);
    v.vy += D_800E68CA;
    ((Scr_8013F37C *)0x1F800000)->eye.vx = (v.vx + ((Scr_8013F37C *)0x1F800000)->spike.vx) / 2;
    ((Scr_8013F37C *)0x1F800000)->eye.vy = g_Spike_8013F37C.y - 400;
    ((Scr_8013F37C *)0x1F800000)->eye.vz = (v.vz + ((Scr_8013F37C *)0x1F800000)->spike.vz) / 2;
    func_80047558(arg0, 6, 6, 6);
    ((Scr_8013F37C *)0x1F800000)->at.vx = ((Scr_8013F37C *)0x1F800000)->spike.vx + 0x800;
    ((Scr_8013F37C *)0x1F800000)->at.vz = (v.vz * 3 + ((Scr_8013F37C *)0x1F800000)->spike.vz) / 4;
    ((Scr_8013F37C *)0x1F800000)->at.vy = ((Scr_8013F37C *)0x1F800000)->eye.vy - 400;
    func_80047464(arg0, 6, 2, 6);
}

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

typedef struct { u8 pad0[0x5C]; u16 frame; } Anim_8013FEE8;
extern Anim_8013FEE8 D_80144690_8013FEE8 asm("D_80144690");
M2C_UNK func_8005588C(void *, M2C_UNK);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
void Object_EnableCollision(void *);
void func_8013FE00(void *arg0, s32 n);

s32 func_8013FEE8(u8 *o) {
    Anim_8013FEE8 *a = &D_80144690_8013FEE8;

    switch (o[0x8F]) {
    case 0:
        if (++a->frame == 1) {
            o[0x7C] = Sound_ReserveSlot(0x70AE, 0x1000, o + 0x24);
        } else if (a->frame == 0x18) {
            func_80088120(o[0x7C]);
            Object_PlaySound(o, 0x5C);
        }
        if (a->frame < 0x14) {
            func_8013FE00(o, 0);
        } else {
            func_8013FE00(o, 1);
        }
        if (a->frame >= 0x27) {
            o[0xC8] = 10;
            o[0x8F] = 1;
            o[0x7C] = Sound_ReserveSlot(0x70AE, 0x1000, o + 0x24);
            Object_EnableCollision(o);
            func_8005588C(o, 0xD);
        }
        return 0;
    case 1:
        func_8013FE00(o, 1);
        M2C_FIELD(o, s32 *, 0x28) -= 8;
        if (func_8005588C(o, -1) == 0) {
            func_80088120(o[0x7C]);
            o[0x8F] = 2;
        }
        return 0;
    case 2:
        if (a->frame >= 0x37) {
            return 1;
        }
        if (++a->frame == 0x18) {
            Object_PlaySound(o, 0x5E);
        }
        return 0;
    }
    return 0;
}

typedef struct { s16 a[4]; } Q_801400A4;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x2C]; u16 f_5C; u16 f_5E; Q_801400A4 rot; u8 pad_68[0x18]; u8 f_80; u8 pad_81[0x47]; u8 f_C8; u8 pad_C9[0x17]; s32 f_E0; } O_801400A4;
extern O_801400A4 D_80144770_801400A4 asm("D_80144770");
void func_8013F550(s32 arg0);

void func_801400A4(O_801400A4 *arg0) {
    O_801400A4 *d = &D_80144770_801400A4;
    u16 t;

    if (arg0->f_C8 == 0) {
        return;
    }
    if (!(arg0->f_E0 & 1)) {
        return;
    }
    if (arg0->f_5E == 1) {
        return;
    }
    d->x = arg0->x;
    d->y = arg0->y;
    d->z = arg0->z;
    d->rot = arg0->rot;
    t = d->f_5C;
    d->f_5C = t + 1;
    if (arg0->f_80 == 5) {
        if ((u16)(t - 2) >= 0x10) {
            d->f_5C = 4;
        }
    } else if ((u16)(t + 1) >= 4) {
        d->f_5C = 0;
    }
    func_8013F550(2);
}

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

void func_8005744C(void *, s32, s32, s32);

void func_80140DAC(u8 *arg0) {
    u8 *s;

    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) != 0xB) {
        return;
    }
    s = Collision_GetShape(M2C_FIELD(arg0, u16 *, 0x50) & 0xFFF);
    if ((M2C_FIELD(s, s16 *, 0x24) & 0xFF00) == 0x800) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800525E0(arg0);
        func_80052864(arg0);
    } else {
        Object_PlaySound(arg0, 0x67);
        func_8005744C(arg0, (s16)(M2C_FIELD(s, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0x24)),
                      (s16)(M2C_FIELD(arg0, u16 *, 0x28) - M2C_FIELD(s, u16 *, 4)),
                      (s16)(M2C_FIELD(s, u16 *, 8) - M2C_FIELD(arg0, u16 *, 0x2C)));
    }
}

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

extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike_8014105C asm("g_Spike");
extern s8 D_800E77EC;
void VectorNormalSS(void *, void *);
void func_80059304(SVECTOR *, void *, s32, SVECTOR *);

M2C_UNK func_8014105C(void *o, M2C_UNK dy, M2C_UNK sp) {
    s32 n;
    s32 a, b;
    SVECTOR p;
    SVECTOR v;

    n = 0x20;
    if (D_800E77EC != 0) {
        n = D_800E77EC;
    }
    v.vx = g_Spike_8014105C.x - M2C_FIELD(o, u16 *, 0x24);
    v.vy = dy + (g_Spike_8014105C.y - (M2C_FIELD(o, u16 *, 0x28) + 0x80));
    v.vz = g_Spike_8014105C.z - M2C_FIELD(o, u16 *, 0x2C);
    VectorNormalSS(&v, &v);
    v.vx /= n;
    v.vy /= n;
    v.vz /= n;
    a = M2C_FIELD(o, s16 *, 0x60) * (s16)sp;
    b = M2C_FIELD(o, s16 *, 0x64) * (s16)sp;
    p.vx = M2C_FIELD(o, u16 *, 0x24) + (a >> 12);
    p.vy = M2C_FIELD(o, u16 *, 0x28) - dy;
    p.vz = M2C_FIELD(o, u16 *, 0x2C) + (b >> 12);
    func_80059304(&p, o, 2, &v);
}


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

extern u32 g_Game_8014173C asm("g_Game");
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);

void func_8014173C(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        func_80052038(arg0, 0xA8);
        break;
    case 1:
        func_80052038(arg0, 0x17);
        break;
    case 2:
        func_80052038(arg0, 0xA9);
        break;
    }
    Puff_Spawn(arg0 + 0x24, 1, 0, 200);
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x600)) {
        if (g_Game_8014173C % 5 == 0 || ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 3) == 0) {
            Object_PlaySound(arg0, 0x5B);
        }
    }
}

INCLUDE_ASM("asm/ovl/413/nonmatchings/413_tv_tower1", func_80141840);

extern s32 D_800EC204;
extern s32 D_800EC208;
extern s32 D_800EC20C;

s32 func_801418D8(u8 *o, s32 r) {
    s32 res = 0;

    if (ABS(D_800EC204 - M2C_FIELD(o, s32 *, 0x24)) < r
        && ABS(D_800EC208 - M2C_FIELD(o, s32 *, 0x28)) < r
        && ABS(D_800EC20C - M2C_FIELD(o, s32 *, 0x2C)) < r) {
        res = 1;
    }
    return res;
}

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

extern u32 D_80144608[];
void Effect_Spawn_801426B0(s32, s16 *, u32 *, s16 **) asm("Effect_Spawn");

void func_801426B0(void) {
    s16 v[3];
    s32 i;

    if (D_800EC208 < -0x794) {
        for (i = 0; i < 3; i++) {
            v[0] = -0x1000;
            v[1] = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 6 - 0xD5B;
            v[2] = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 6 + 0x12C;
            Effect_Spawn_801426B0(0xC8, v, D_80144608, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            v[0] = -0x1000;
            v[1] = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 6 - 0x17F;
            v[2] = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 6 + 0x12C;
            Effect_Spawn_801426B0(0xC8, v, D_80144608, 0);
        }
    }
}

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

typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[4]; s16 f10; } Scr_80143F38;
extern SVECTOR D_800F4B30[3];
extern struct { s32 f0; u8 pad4[4]; s32 f8; } g_Game_80143F38 asm("g_Game");
s16 Floor_GetHeight_80143F38(s32, s32, s32) asm("Floor_GetHeight");
s32 Water_Query(s32, s32, s32);
s32 rsin_80143F38(s32) asm("rsin");
void func_80014804(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_80143F38(s32, void *, void *) asm("func_80017CD4");

void func_80143F38(void) {
    u8 *o;
    s32 fl;
    s32 lvl;
    s32 y;

    o = D_800B4DC4;
    fl = Floor_GetHeight_80143F38(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C));
    if (((Water_Query(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C)) & 0xFFFF) >> 12) == 1) {
        lvl = ((Scr_80143F38 *)0x1F8003D4)->fA - ((Scr_80143F38 *)0x1F8003D4)->f10;
        if (M2C_FIELD(o, s32 *, 0x28) - lvl > 0x20) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s32 *, 0x28) - 12;
        } else {
            M2C_FIELD(o, s32 *, 0x28) = lvl + 0x20;
        }
        M2C_FIELD(o, u16 *, 0x78) = M2C_FIELD(o, u16 *, 0x24);
        M2C_FIELD(o, u16 *, 0x7A) = M2C_FIELD(o, u16 *, 0x28);
        M2C_FIELD(o, u16 *, 0x7C) = M2C_FIELD(o, u16 *, 0x2C);
    } else if (M2C_FIELD(o, s32 *, 0x28) >= fl) {
        M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(o, s16 *, 0x78);
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x7A);
        M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s16 *, 0x7C);
    }
    func_80014804((s16 *)(o + 0x60), M2C_FIELD(o, s16 **, 0x14));
    y = M2C_FIELD(o, s32 *, 0x28);
    M2C_FIELD(o, s32 *, 0x28) += rsin_80143F38(g_Game_80143F38.f0 << 6) >> 9;
    D_800F4B30[0].vx = 0;
    D_800F4B30[0].vy = 0x800;
    D_800F4B30[0].vz = 0;
    D_800F4B30[1].vx = 0x400;
    D_800F4B30[1].vy = 0;
    D_800F4B30[1].vz = -0x480;
    D_800F4B30[2].vx = 0x400;
    D_800F4B30[2].vy = 0;
    D_800F4B30[2].vz = -0x380;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_80143F38(g_Game_80143F38.f8, (u8 *)&D_800E7D00, o);
    M2C_FIELD(o, s32 *, 0x28) = y;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
