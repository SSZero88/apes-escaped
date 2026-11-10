#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; s32 f_820C; } g_Game;
M2C_UNK Matrix_FromDirection(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
M2C_UNK Model_CalcKeyedJointMatrices(void *, M2C_UNK);
M2C_UNK Model_DrawAuto(void *, M2C_UNK *, void *);
s32 func_80051410(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK g_ProjVerts;
extern M2C_UNK D_80144690;

M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s16 Floor_GetHeight(s16, s16, s16);
M2C_UNK Hook_Add(M2C_UNK *);
void func_8013FB40(void);
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

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D6D0 asm("g_Game");
extern u8 *D_800B4D64_8013D6D0 asm("D_800B4D64");
extern s16 D_800EC238;
s32 Sound_PlayAt_8013D6D0(s32, void *) asm("Sound_PlayAt");

s32 func_8013D6D0(s16 *p) {
    u8 *e = g_Game_8013D6D0.f_820C + p[2] * 0x38;
    u8 *t;

    switch (p[1]) {
    case 0:
        break;
    case 1:
        if (p[3] == 0 && D_800EC238 == p[2]) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[3] = 1;
            p[1] = 2;
            t = g_Game_8013D6D0.f_8220 + p[7] * 0x18;
            M2C_FIELD(t, s16 *, 2) = 2;
            e = g_Game_8013D6D0.f_820C + M2C_FIELD(t, s16 *, 4) * 0x38;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_8013D6D0 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            Sound_PlayAt_8013D6D0(0x9C, e);
        } else if (D_800EC238 < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 2:
        if (M2C_FIELD(e, s16 *, 0x32) == ((p[6] / 2) * 2 | 1)) {
            Sound_PlayAt_8013D6D0(0x9C, e);
        }
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            t = g_Game_8013D6D0.f_8220 + p[7] * 0x18;
            M2C_FIELD(t, s16 *, 2) = 5;
            p[1] = 1;
            Sound_PlayAt_8013D6D0(0x9C, e);
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}

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

extern struct { u8 pad_0[0x8214]; u8 *f_8214; } g_Game_8013D94C asm("g_Game");
extern u8 *D_800B4D64_8013D94C asm("D_800B4D64");
s16 func_800889EC(u16 *);

M2C_UNK func_8013D94C(void *e) {
    u8 *n;
    u8 *m;
    u8 *tbl;
    s16 d;
    s32 len;
    s32 dx;
    s32 dy;
    s32 dz;
    u16 x;
    u16 y;
    u16 z;

    if (M2C_FIELD(e, s16 *, 0x22) < 0) {
        return 0;
    }
    n = g_Game_8013D94C.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 16;
    d = M2C_FIELD(e, s16 *, 0xC);
    len = M2C_FIELD(n, s16 *, 0xC) * 2;
    dx = (d * (M2C_FIELD(n, s16 *, 0) - M2C_FIELD(e, s16 *, 0x24))) / len;
    dy = (d * (M2C_FIELD(n, s16 *, 2) - M2C_FIELD(e, s16 *, 0x26))) / len;
    dz = (d * (M2C_FIELD(n, s16 *, 4) - M2C_FIELD(e, s16 *, 0x28))) / len;
    x = M2C_FIELD(e, u16 *, 0x24) + dx;
    y = M2C_FIELD(e, u16 *, 0x26) + dy;
    z = M2C_FIELD(e, u16 *, 0x28) + dz;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        tbl = D_800B4D64_8013D94C;
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x10) = x;
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x12) = y;
        M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x14) = z;
    }
    M2C_FIELD(e, u16 *, 4) = z;
    M2C_FIELD(e, u16 *, 0) = x;
    M2C_FIELD(e, u16 *, 2) = y;
    M2C_FIELD(e, s16 *, 0x20) = func_800889EC((u16 *)e);
    M2C_FIELD(e, s16 *, 0xC)++;
    M2C_FIELD(e, s16 *, 0x32)++;
    if (M2C_FIELD(e, s16 *, 0xC) >= M2C_FIELD(n, s16 *, 0xC) * 2) {
        M2C_FIELD(e, s16 *, 0xC) = 0;
        M2C_FIELD(e, u16 *, 0x22) = M2C_FIELD(n, u16 *, 0xE);
        m = (u8 *)(M2C_FIELD(e, s16 *, 0x22) * 16 + (s32)g_Game_8013D94C.f_8214);
        if (M2C_FIELD(m, s16 *, 0xC) <= 0) {
            M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(m, u16 *, 0);
            M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(g_Game_8013D94C.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 16, u16 *, 2);
            M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(g_Game_8013D94C.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 16, u16 *, 4);
            M2C_FIELD(e, u16 *, 0x22) = M2C_FIELD(g_Game_8013D94C.f_8214 + M2C_FIELD(e, s16 *, 0x22) * 16, u16 *, 0xE);
            M2C_FIELD(e, s16 *, 0x32) = 0;
        } else {
            M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(n, u16 *, 0);
            M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(n, u16 *, 2);
            M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(n, u16 *, 4);
        }
    }
    return 0;
}

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

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013DC5C;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; S18_8013DC5C *f_8220; } g_Game_8013DC5C asm("g_Game");
s32 Sound_Play(s32, s32);
void Sound_Stop(s32, s32);

s32 func_8013DC5C(s16 *p) {
    s32 s;
    S18_8013DC5C *t;

    if (p[4] >= 0) {
        switch (p[1]) {
        case 0:
            t = &g_Game_8013DC5C.f_8220[p[4]];
            s = t->f_2;
            if (s == 1) {
                p[9] = Sound_Play(0, 0xB9);
                CamFlyby_StartSegment(p[6] - 1);
                g_Game_8013DC5C.f_8100 = 7;
                D_800EC238 = -1;
                p[1] = s;
                p[3] = 0;
            }
            break;
        case 1:
            if (++p[3] >= 0x3D) {
                Sound_Stop(0xB9, p[9]);
                p[1] = 2;
            }
            break;
        case 2:
            break;
        }
        return 0;
    }
    return 0;
}

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

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013E20C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013E20C *f_8220; } g_Game_8013E20C asm("g_Game");
extern u8 *D_800B4D64_8013E20C asm("D_800B4D64");

s32 func_8013E20C(s16 *p) {
    u8 *e = g_Game_8013E20C.f_820C + p[2] * 0x38;
    s32 n;
    S18_8013E20C *t;

    if (p[1] == 0 && (t = &g_Game_8013E20C.f_8220[p[4]])->f_2 != 0) {
        p[1] = 1;
        n = M2C_FIELD(e, s16 *, 0xE);
        M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
        if (n >= 0) {
            M2C_FIELD(D_800B4D64_8013E20C + n * 32, u16 *, 0x16) = 0xFFFF;
        }
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013E2A8;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013E2A8 *f_8220; } g_Game_8013E2A8 asm("g_Game");

s32 func_8013E2A8(s16 *p) {
    S18_8013E2A8 *t = &g_Game_8013E2A8.f_8220[p[4]];
    u8 *e;

    if (t->f_2 != 0) {
        p[1] = 2;
        e = g_Game_8013E2A8.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x2A) = p[5];
        e = (u8 *)(p[2] * 0x38 + (s32)g_Game_8013E2A8.f_820C);
        M2C_FIELD(e, u16 *, 0x62) = p[5];
    } else {
        p[1] = 0;
        e = g_Game_8013E2A8.f_820C + p[2] * 0x38;
        p[10] = M2C_FIELD(e, u16 *, 0x2A);
        e = (u8 *)(p[2] * 0x38 + (s32)g_Game_8013E2A8.f_820C);
        p[11] = M2C_FIELD(e, u16 *, 0x62);
        p[9] = Sound_Play(0, 0xB4);
    }
    p[3] = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013E3A4 asm("g_Game");
s32 func_80087BA4_8013E3A4(s32, s32, s32, s32) asm("func_80087BA4");
void func_801426B0(void);

s32 func_8013E3A4(s16 *p) {
    u8 *e;
    u8 *t;

    switch (p[1]) {
    case 0:
        t = g_Game_8013E3A4.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) != 0) {
            p[1] = 1;
            p[3] = 0;
        }
        func_801426B0();
        break;
    case 1:
        p[3]++;
        if (p[3] >= 30) {
            p[1] = 2;
            Sound_Stop(0xB4, p[9]);
            e = g_Game_8013E3A4.f_820C + p[2] * 0x38;
            M2C_FIELD(e, s16 *, 0x2A) = p[5];
            e = (u8 *)(p[2] * 0x38 + (s32)g_Game_8013E3A4.f_820C);
            M2C_FIELD(e, s16 *, 0x62) = p[5];
        } else {
            func_80087BA4_8013E3A4(0xB4, p[9], 30 - p[3], 30);
            e = g_Game_8013E3A4.f_820C + p[2] * 0x38;
            M2C_FIELD(e, s16 *, 0x2A) = p[10] + (p[5] - p[10]) * p[3] / 30;
            e = (u8 *)(p[2] * 0x38 + (s32)g_Game_8013E3A4.f_820C);
            M2C_FIELD(e, s16 *, 0x62) = p[11] + (p[5] - p[11]) * p[3] / 30;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

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

extern struct S_g_8013E64C { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[8]; u8 *f_8218; u8 pad_821C[4]; u8 *f_8220; } g_Game_8013E64C asm("g_Game");

s32 func_8013E64C(s16 *p) {
    u8 *t;
    u8 *e;
    s16 *q;
    u8 *g0 = (u8 *)&g_Game_8013E64C;
    s32 k = 0x8000;
    u8 *g = g0 + k;

    if (p[1] == 0) {
        t = *(u8 **)(g + 0x220) + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) != 0) {
            p[1] = 1;
            e = *(u8 **)(g + 0x20C) + p[2] * 0x38;
            if (M2C_FIELD(e, s16 *, 0x30) >= 0) {
                q = (s16 *)(*(u8 **)(g + 0x218) + M2C_FIELD(e, s16 *, 0x30) * 16);
                if (q[0] == 3 && q[1] == 0x5A) {
                    q[2] = p[5];
                }
            }
        }
    }
    return 0;
}

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

typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad[0x12]; } S18_8013E774;
extern struct { u8 pad_0[0x8150]; u16 f_8150; u8 pad_8152[0xBA]; u8 *f_820C; u8 pad_8210[0x10]; S18_8013E774 *f_8220; } g_Game_8013E774 asm("g_Game");
extern struct { u8 pad_0[0x34]; s32 f_34; } g_Spike_8013E774 asm("g_Spike");
s32 func_80094A48(s16);
s32 func_80094B6C(s16, s16 *, s16 *);

s32 func_8013E774(s16 *p) {
    s16 *e;
    S18_8013E774 *t;
    u8 *q;

    if (g_Game_8013E774.f_8150 == 8) {
        return 0;
    }
    t = g_Game_8013E774.f_8220;
    if (t[18].f_2 == 1) {
        return 0;
    }
    e = (s16 *)(g_Game_8013E774.f_820C + p[2] * 0x38);
    q = (u8 *)t + p[11] * 0x18;
    if (M2C_FIELD(q, s16 *, 2) == 1) {
        p[1] = 1;
        if (D_80144630 < 0) {
            D_80144630 = Sound_Play(0, 0xB1);
        }
    } else if (D_800EC238 == p[2] || func_80094A48(p[4]) != 0) {
        p[1] = 2;
        if (D_80144630 < 0) {
            D_80144630 = Sound_Play(0, 0xB1);
        }
    } else if (p[1] != 4) {
        p[1] = 3;
        if (D_80144630 >= 0) {
            Sound_Stop(0xB1, D_80144630);
            D_80144630 = -1;
        }
    }
    switch (p[1]) {
    case 0:
        break;
    case 1:
        p[3] = 30;
        e[1] -= p[6];
        if (e[1] < e[0x13]) {
            e[1] = e[0x13];
            if (D_80144630 >= 0) {
                Sound_Stop(0xB1, D_80144630);
                D_80144630 = -1;
            }
        }
        break;
    case 2:
        p[3] = 30;
        g_Spike_8013E774.f_34 += p[7];
        e[1] += p[7];
        if (e[0x13] + p[5] < e[1]) {
            e[1] = e[0x13] + p[5];
            if (D_80144630 >= 0) {
                Sound_Stop(0xB1, D_80144630);
                D_80144630 = -1;
            }
        }
        break;
    case 3:
        if (--p[3] < 0) {
            p[1] = 4;
        }
        break;
    case 4:
        e[1] -= p[6] / 2;
        if (e[1] < e[0x13]) {
            e[1] = e[0x13];
            if (D_80144630 >= 0) {
                Sound_Stop(0xB1, D_80144630);
                D_80144630 = -1;
            }
        }
        break;
    }
    if (p[1] == 0) {
        return 0;
    }
    if (e[7] >= 0) {
        M2C_FIELD(D_800B4D64 + e[7] * 32, s16 *, 0x12) = e[1];
    }
    if (p[4] >= 0) {
        func_80094B6C(p[4], e, &p[8]);
    }
    return 0;
}

extern struct S_g_Game_8013EA44 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013EA44 asm("g_Game");
void Matrix_SetScale(SVECTOR *, void *);

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
            Matrix_SetScale(&v, M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
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

typedef struct { u16 f[8]; } N16_8013ED24;
extern struct { u8 pad_0[0x8214]; N16_8013ED24 *f_8214; } g_Game_8013ED24 asm("g_Game");

s32 func_8013ED24(s16 *p) {
    s32 i = p[17];
    N16_8013ED24 *t;

    if (i < 0) {
        return 0;
    }
    t = &g_Game_8013ED24.f_8214[i];
    p[3] = t->f[3];
    p[4] = t->f[4];
    p[5] = t->f[5];
    p[17] = ((u16 *)(p[17] * 16 + (s32)g_Game_8013ED24.f_8214))[7];
    p[25]++;
    return 0;
}

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

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x28]; s16 f40; u8 pad42[2]; s16 f44; } Scr_8013F148;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013F148;
void Camera_UpdateOrientation(void *);
void Camera_HandleManualInput(void *);
void Camera_KeepAboveFloor(void *);
void Matrix_LookAt(void *, void *, void *, s32);
void ApplyMatrixSV(void *, void *, void *);
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
s32 rcos_8013F148(s32) asm("rcos");
s32 rsin_8013F148(s32) asm("rsin");
extern s32 D_800E5478;
extern SVECTOR D_800EC240[2];

void func_8013F148(void *c) {
    Scr_8013F148 *scr = (Scr_8013F148 *)0x1F800000;
    SVECTOR v;
    Mat_8013F148 m;
    s32 t;

    Camera_UpdateOrientation(c);
    M2C_FIELD(c, s32 *, 0x38) = (M2C_FIELD(c, s32 *, 0x38) * 3 + 0x400) / 4;
    Camera_HandleManualInput(c);
    if (!(D_800E5478 & 0xA000)) {
        M2C_FIELD(c, s32 *, 0x4C) = M2C_FIELD(c, s32 *, 0x4C) * 3 / 4;
    }
    t = M2C_FIELD(c, s32 *, 0x4C) + 0x1000;
    M2C_FIELD(c, s32 *, 0x40) = (M2C_FIELD(c, s32 *, 0x48) + t) % 0x1000;
    M2C_FIELD(c, u8 *, 0x34) = 0;
    M2C_FIELD(c, u8 *, 0x32) = 0;
    Matrix_LookAt(&D_800EC240[0], &D_800EC240[1], &m, 0);
    v.vx = 0;
    v.vy = 0;
    v.vz = -M2C_FIELD(c, u16 *, 0x38);
    ApplyMatrixSV(&m, &v, &v);
    scr->eye.vx = scr->spike.vx + scr->f40 / 16;
    scr->eye.vy = scr->spike.vy + (s16)(v.vy - 0x3C);
    scr->eye.vz = scr->spike.vz + scr->f44 / 16;
    scr->at.vx = scr->eye.vx + ((rcos_8013F148(M2C_FIELD(c, s32 *, 0x40)) * M2C_FIELD(c, s32 *, 0x38)) >> 12);
    scr->at.vy = scr->spike.vy - (s16)(v.vy + 0x140);
    scr->at.vz = scr->eye.vz + ((rsin_8013F148(M2C_FIELD(c, s32 *, 0x40)) * M2C_FIELD(c, s32 *, 0x38)) >> 12);
    func_80047558(c, 2, 8, 2);
    func_80047464(c, 2, 4, 2);
    M2C_FIELD(c, s16 *, 0xC) += M2C_FIELD(c, s16 *, 0x6C);
    Camera_KeepAboveFloor(c);
    M2C_FIELD(c, s32 *, 0x44) = M2C_FIELD(c, s32 *, 0x40);
}

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
        Model_CalcKeyedJointMatrices(temp_s0, 3);
        Model_ProjectBonedVerts(temp_s0);
        Model_DrawAuto((g_Game.f_C * 0x4078) + ((void *)((u8 *)&g_Game + 0x80)), &g_ProjVerts, temp_s0);
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

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, pad12; } Drip_8013F630;
extern Drip_8013F630 D_80144640_8013F630[4] asm("D_80144640");
extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013F630 asm("g_Spike");
s32 func_8013F5F4(void);
s32 rcos_8013F630(s32) asm("rcos");
s32 rsin_8013F630(s32) asm("rsin");
s32 Vec_Length_8013F630(s32, s32, s32) asm("Vec_Length");
s32 VectorNormalSS_8013F630(void *, void *) asm("VectorNormalSS");
void Object_PlaySound_8013F630(void *, s32) asm("Object_PlaySound");

void func_8013F630(u8 *o, s16 side, s16 drop, s16 fwd, s32 aimed) {
    Drip_8013F630 *p;
    s32 i;
    s32 a;
    s16 c;
    s16 s;
    s32 d;
    s32 n;
    s32 t;
    s32 h;
    SVECTOR v;

    i = func_8013F5F4();
    if (i == -1) {
        return;
    }
    p = &D_80144640_8013F630[i];
    a = (M2C_FIELD(o, s16 *, 0xAC) + 0x1000 + M2C_FIELD(o, s16 *, 0xB2)) % 0x1000;
    c = rcos_8013F630(a);
    s = rsin_8013F630(a);
    { s32 t1 = (c * fwd) >> 12; s32 t2 = (s * side) >> 12; p->x = t2 + (M2C_FIELD(o, u16 *, 0x24) + t1); }
    p->y = M2C_FIELD(o, u16 *, 0x28) - drop;
    { s32 t1 = (s * fwd) >> 12; s32 t2 = (-(c * side)) >> 12; p->z = t2 + (M2C_FIELD(o, u16 *, 0x2C) + t1); }
    p->active++;
    d = Vec_Length_8013F630(g_Spike_8013F630.x - p->x, 0, g_Spike_8013F630.z - p->z);
    if (aimed != 0) {
        if (d > 0x400) {
            v.vx = (u16)g_Spike_8013F630.x - p->x;
            v.vy = 0;
            v.vz = (u16)g_Spike_8013F630.z - p->z;
            VectorNormalSS_8013F630(&v, &v);
            p->vx = v.vx / 72;
            p->vz = v.vz / 72;
            n = d / 56;
            p->grav = 1;
            if (n == 0) {
                p->vy = 0;
            } else {
                p->vy = (g_Spike_8013F630.y - (h = p->y + 0x80)) / n - n / 2;
            }
        } else {
            v.vx = (u16)g_Spike_8013F630.x - p->x;
            v.vy = -(p->y + 0x80) + g_Spike_8013F630.y;
            v.vz = (u16)g_Spike_8013F630.z - p->z;
            VectorNormalSS_8013F630(&v, &v);
            p->vx = v.vx / 72;
            p->vy = v.vy / 72;
            p->vz = v.vz / 72;
            p->grav = 0;
        }
    } else {
        n = d / 85;
        p->grav = 2;
        p->vx = c / 48;
        p->vz = s / 48;
        if (n == 0) {
            p->vy = 0;
        } else {
            h = p->y + 0x80;
            t = g_Spike_8013F630.y - h;
            if (t < -100) {
                t = -100;
            }
            p->vy = t / n - n;
        }
    }
    p->owner = M2C_FIELD(o, s8 *, 0xCB);
    Object_PlaySound_8013F630(o, 0x77);
}

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

typedef struct { s16 x, y, z, vx, vy, vz, active, owner, grav, pad12; } Drip_8013DA0C;
typedef struct { s16 x, y, z; } V3_8013DA0C;
typedef struct { u8 pad[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 vx, vy, vz; } M_8013DA0C;
typedef struct { u8 pad[0x28]; s32 y; u8 pad2C[0xB4 - 0x2C]; s32 f_B4; u8 padB8[0xE4 - 0xB8]; } Obj_8013DA0C;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
extern Drip_8013DA0C D_80141738_8013DA0C[4] asm("D_80144640");
extern M_8013DA0C D_801418D8_8013DA0C asm("D_801447E0");
extern Obj_8013DA0C g_Objects_8013DA0C[] asm("g_Objects");
s32 VectorNormalSS_8013DA0C(void *, void *) asm("VectorNormalSS");
s32 Object_AddAttackSphere_8013DA0C(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");
void func_8013F550(s32 arg0);
s32 func_8013FA7C(void *arg0);
void func_8013FAC0(SVECTOR *arg0);
void func_8013FB00(SVECTOR *arg0);
void func_8013F550(s32 arg0);

void func_8013FB40(void) {
    Drip_8013DA0C *p;
    M_8013DA0C *m;
    Obj_8013DA0C *o;
    s32 i;
    s32 r;
    V3_8013DA0C s;
    V3_8013DA0C v;

    m = &D_801418D8_8013DA0C;
    for (i = 3; i >= 0; i--) {
        p = &D_80141738_8013DA0C[i];
        if (p->active != 0) {
            p->active++;
            p->vy += p->grav;
            o = &g_Objects_8013DA0C[p->owner];
            func_8013FAC0((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            r = Object_DetachLink(o, 0);
            if (func_8013FA7C(p) || o->y + 0x600 < p->y || r == 6) {
                v.x = p->x;
                v.y = p->y;
                v.z = p->z;
                s = v;
                Sound_PlayAt(0x4D, &s);
                p->active = 0;
                func_8013FB00((SVECTOR *)p);
                continue;
            }
            m->x = p->x;
            m->y = p->y;
            m->z = p->z;
            m->vx = p->vx;
            m->vy = p->vy;
            m->vz = p->vz;
            VectorNormalSS_8013DA0C(&m->vx, &m->vx);
            func_8013F550(3);
            o->f_B4 = Object_AddAttackSphere_8013DA0C(o, 100, p->x, p->y, p->z, 0x201, 0x203);
        }
    }
}

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

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_80140298 asm("g_Spike");
void Object_SpawnEffect(void *, s16, s32, s32, s32);
void Object_TurnToward(void *, s16, s16, s16, s16);
s32 func_8014018C_80140298() asm("func_8014018C");

s32 func_80140298(u8 *e) {
    SVECTOR v;
    SVECTOR t;

    if (e[0x80] != 5 && e[0x80] != 2 && func_8014018C_80140298()) {
        memset(&t, 0, 8);
        t.vx = M2C_FIELD(e, u16 *, 0x24);
        t.vy = M2C_FIELD(e, u16 *, 0x28);
        t.vz = M2C_FIELD(e, u16 *, 0x2C);
        v = t;
        Effect_SpawnAt(5, &v);
        Effect_SpawnAt(0x108, &v);
        M2C_FIELD(e, s16 *, 0x5E) = 0;
        if (e[0x81] != 0) {
            if (--e[0x81] != 0 && (M2C_FIELD(e, u32 *, 0xE0) & 1)) {
                e[0x80] = 5;
                e[0x7F] = 4;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[8];
                Object_PlaySound(e, 0x78);
            } else {
                e[0x81] = 0;
                Object_SpawnEffect(e, 0x102, 0, 300, 0);
                Object_PlaySound(e, 0x79);
                M2C_FIELD(e, s16 *, 0x5E) = 2;
                M2C_FIELD(e, s16 *, 0x96) = -0x5A;
                e[0x80] = 6;
                M2C_FIELD(e, s16 *, 0xD4) = M2C_FIELD(e, s16 *, 0xD6) = 0;
                M2C_FIELD(e, u32 *, 0xE0) &= ~1;
                e[0x7F] = 1;
                M2C_FIELD(e, u32 *, 0xE0) = (M2C_FIELD(e, u32 *, 0xE0) & 0xFF3FFFFF) | 0x400000;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[2];
                func_80052038(e, 0x8D);
            }
            Object_TurnToward(e, g_Spike_80140298.x - M2C_FIELD(e, u16 *, 0x24), g_Spike_80140298.z - M2C_FIELD(e, u16 *, 0x2C), 0, 0x1000);
            return 1;
        }
        Object_PlaySound(e, 0x60);
        return 1;
    }
    return 0;
}

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

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_801407DC asm("g_Spike");
extern u32 g_Game_801407DC asm("g_Game");
extern u16 D_800AE8F2;
M2C_UNK func_80058134(void *, s16);
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void *func_80057140_801407DC(void *, s32, s32) asm("func_80057140");
void Fx_DebrisExplosion_801407DC(s32, s32, s32) asm("Fx_DebrisExplosion");
void Object_DisableCollision(void *);
void func_8005866C(void *, s32);
void Object_ClampAnimFrame(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s16);
void func_8013F630(u8 *o, s16 side, s16 drop, s16 fwd, s32 aimed);
void func_8013FD8C(void *arg0);
s32 func_8013FEE8(u8 *o);
void func_8014020C(void *arg0);
s32 func_80140298(u8 *e);
void func_801404A4(void *arg0, s32 on);
s32 func_801404EC(void *arg0);
void func_80140578(void *arg0);
void func_80140670(void *arg0);
#define ANIM_801407DC(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))
#define RAND_801407DC() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2_801407DC() (D_800AE8F2 = D_800AE8F2 * 5 + 1)

void func_801407DC(u8 *e) {
    SVECTOR v;

    if (!((M2C_FIELD(e, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(e, s16 *, 0x4A) = -0x3EFF;
        e[0x81] = 5;
        M2C_FIELD(e, s16 *, 0x48) = 0;
        e[0xC8] = 0;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(e, u32 *, 0xE0) = (M2C_FIELD(e, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x8000;
        M2C_FIELD(e, u32 *, 0xE0) &= ~1;
        M2C_FIELD(e, s16 *, 0x44) = 0xFA;
        M2C_FIELD(e, u32 *, 0xE0) &= ~1;
        M2C_FIELD(e, s16 *, 0x46) = 0x1EA;
        { register u32 t asm("$3") = M2C_FIELD(e, u32 *, 0xE0); M2C_FIELD(e, u32 *, 0xE0) = t | 0x2000; }
        M2C_FIELD(e, void **, 0x74) = func_80057140_801407DC(e, 7, 0xD9);
        Object_DisableCollision(e);
        e[0xDE] = 0;
        if (M2C_FIELD(e, u16 *, 0x8C) != 0) {
            func_8005866C(e, 1);
        }
        e[0x7F] = 2;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C);
        M2C_FIELD(e, u16 *, 0x9C) -= 0x68;
        M2C_FIELD(e, u16 *, 0x5C) = ANIM_801407DC(e, 2)[0];
        func_8013FD8C(e);
        M2C_FIELD(e, u32 *, 0xE0) |= 8;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    if (func_80140298(e) == 0) {
        func_8014020C(e);
        e[0xCF] = 0;
        switch (e[0x80]) {
        case 5:
            if (M2C_FIELD(e, u16 *, 0x5C) >= ANIM_801407DC(e, e[0x7F])[1]) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_801407DC(e, 0)[0];
                func_8005588C(e, 0);
            }
            break;
        case 6:
            M2C_FIELD(e, s16 *, 0x5E) = 2;
            M2C_FIELD(e, u16 *, 0x96) += 7;
            M2C_FIELD(e, s32 *, 0x28) += M2C_FIELD(e, s16 *, 0x96);
            M2C_FIELD(e, u16 *, 0xD4) += 5;
            M2C_FIELD(e, u16 *, 0xD6) += 5;
            func_80140670(e);
            Object_ClampAnimFrame(e, ANIM_801407DC(e, e[0x7F])[1]);
            if (M2C_FIELD(e, s16 *, 0x9C) + 100 < M2C_FIELD(e, s32 *, 0x28)) {
                M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 100;
                e[0x80] = 7;
                Object_PlaySound(e, 0x4D);
                Fx_DebrisExplosion_801407DC(M2C_FIELD(e, s16 *, 0x24), M2C_FIELD(e, s16 *, 0x28), M2C_FIELD(e, s16 *, 0x2C));
            }
            break;
        case 7:
            M2C_FIELD(e, s16 *, 0x5E) = 2;
            Object_ClampAnimFrame(e, ANIM_801407DC(e, e[0x7F])[1]);
            if (g_Game_801407DC % 20 < 5) {
                v.vx = M2C_FIELD(e, u16 *, 0x24) + ((RAND2_801407DC() >> 8) - 0x80) * 2;
                v.vy = M2C_FIELD(e, u16 *, 0x28) - (RAND2_801407DC() >> 8) - 0x12C;
                v.vz = M2C_FIELD(e, u16 *, 0x2C) + ((RAND2_801407DC() >> 8) - 0x80) * 2;
                Effect_SpawnAt(7, &v);
                Puff_Spawn(e + 0x24, 1, 0, 0x100);
                if (((RAND_801407DC() >> 8) & 0xF) == 0) {
                    Object_PlaySound(e, 0x5B);
                }
            }
            break;
        case 2:
            if (!(M2C_FIELD(e, u32 *, 0xE0) & 1)) {
                e[0xC8] = 0;
                M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) + 0x68;
                Object_DisableCollision(e);
                e[0xDE] = 0;
                func_8013FD8C(e);
                if (M2C_FIELD(e, s8 *, 0x7C) != -1) {
                    func_80088120(M2C_FIELD(e, s8 *, 0x7C));
                }
                M2C_FIELD(e, s8 *, 0x7C) = -1;
            } else if (func_8013FEE8(e)) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_801407DC(e, 0)[0];
                func_8005588C(e, 15);
            }
            break;
        case 3:
            Object_TurnToward(e, (s16)(g_Spike_801407DC.x - M2C_FIELD(e, u16 *, 0x24)), (s16)(g_Spike_801407DC.z - M2C_FIELD(e, u16 *, 0x2C)), 0, M2C_FIELD(e, s16 *, 0xB0));
            func_801404A4(e, 0);
            if (func_8005588C(e, -1) == 0 && Object_SpikeInFront(e, 0x5A, 0xB50, 0x1200)) {
                e[0x80] = 4;
                e[0x7F] = 3;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_801407DC(e, 3)[0];
            }
            break;
        case 4:
            Object_TurnToward(e, (s16)(g_Spike_801407DC.x - M2C_FIELD(e, u16 *, 0x24)), (s16)(g_Spike_801407DC.z - M2C_FIELD(e, u16 *, 0x2C)), 0, M2C_FIELD(e, s16 *, 0xB0));
            if (M2C_FIELD(e, u16 *, 0x5C) == ANIM_801407DC(e, e[0x7F])[0] + 15) {
                func_8013F630(e, 0, 0xC8, 0x1C2, 0);
            }
            func_801404A4(e, 1);
            if (M2C_FIELD(e, u16 *, 0x5C) >= ANIM_801407DC(e, e[0x7F])[1]) {
                e[0x80] = 3;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = ANIM_801407DC(e, 0)[0];
                func_8005588C(e, func_801404EC(e));
            }
            break;
        }
        func_80140578(e);
    }
    func_8013F550(0);
    func_8013F550(1);
    func_801400A4(e);
}

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

M2C_UNK Object_ApplyVelocity(void *);
s16 func_80056010(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80058134(void *, s16);
M2C_UNK func_800585D0(void *, s16, M2C_UNK, M2C_UNK);

void func_80140E94(void *arg0) {
    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0xDC;
        M2C_FIELD(arg0, s16 *, 0x44) = 0xDC;
        M2C_FIELD(arg0, s16 *, 0x46) = 0x1AE;
        M2C_FIELD(arg0, s8 *, 0xC8) = 0xD;
        M2C_FIELD(arg0, s8 *, 0x81) = 0x1E;
        M2C_FIELD(arg0, s8 *, 0xCD) = 1;
        M2C_FIELD(arg0, s8 *, 0xDC) = 1;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFF;
        M2C_FIELD(arg0, s8 *, 0x7D) = 0xA;
        M2C_FIELD(arg0, s16 *, 0x48) = 0;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (M2C_FIELD(arg0, u8 *, 0x80) == 1) {
        func_800585D0(arg0, func_80056010(arg0, 0x12, 2, 0), 0, 0);
        if (M2C_FIELD(arg0, s16 *, 0xAE) == 0) {
            Object_ApplyVelocity(arg0);
        }
    }
    func_80140DAC(arg0);
}

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_80140FA0(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

s32 func_80140FA0(void *arg0);

s32 func_80140FD4(void *arg0) {
    if (func_80140FA0(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
        func_8005588C(arg0, 0x1E);
        Object_PlaySound(arg0, 0x9E);
        return 1;
    }
    return 0;
}

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

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 8; u32 f12 : 1; u32 b13 : 11; u32 f24 : 2; u32 b26 : 6; } Flags_801412FC;
typedef struct { u16 start; u16 end; } Rng_801412FC;
typedef struct { s16 x; s16 y; s16 z; s16 w; } Pt_801412FC;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_801412FC asm("g_Spike");
s32 rsin_801412FC(s32) asm("rsin");
s32 func_80140FD4(void *arg0);
void func_8014102C(void *arg0, s32 a);
void func_80141214(s32 arg0);
void func_8014124C(void *arg0);
void func_80141290(void *arg0);
s32 func_801412BC(void *arg0);
void Object_PlaceAtPathPoint(void *, s32);

void func_801412FC(u8 *e) {
    s16 d;
    Pt_801412FC *pt;

    if (!M2C_FIELD(e, Flags_801412FC *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 100;
        M2C_FIELD(e, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(e, s16 *, 0x44) = 0x96;
        e[0xC8] = 10;
        e[0x7D] = 10;
        M2C_FIELD(e, s16 *, 0x48) = 0x201;
        M2C_FIELD(e, s16 *, 0x4A) = 0x8203;
        e[0xDC] = 3;
        M2C_FIELD(e, s8 *, 0x7C) = -1;
        M2C_FIELD(e, s16 *, 0x46) = 0;
        M2C_FIELD(e, s16 *, 0xA8) = 0;
        e[0x8E] = 0;
        M2C_FIELD(e, Flags_801412FC *, 0xE0).f12 = 0;
        M2C_FIELD(e, Flags_801412FC *, 0xE0).f24 = 2;
        Object_PlaceAtPathPoint(e, 0);
        e[0x7F] = 0;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) - 0x1A4;
        M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, Rng_801412FC **, 0x88)[0].start;
        M2C_FIELD(e, Flags_801412FC *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    switch (e[0x80]) {
    case 1:
        if (e[0xC9] != 0) {
            e[0xC9]--;
        }
        if (func_800585D0(e, 0x28, 1, 0) != 0 && e[0xC9] == 0) {
            e[0x80] = 2;
            func_8005588C(e, 0x28);
            M2C_FIELD(e, s16 *, 0xAE) = 0;
            break;
        }
        if (M2C_FIELD(e, s16 *, 0xAE) == 0) {
            Object_ApplyVelocity(e);
        }
        break;
    case 2:
        if (func_80140FD4(e) != 0) {
            break;
        }
        if (func_8005588C(e, -1) != 0) {
            break;
        }
        e[0x80] = 4;
        Object_TurnToward(e, g_Spike_801412FC.x - M2C_FIELD(e, u16 *, 0x24), g_Spike_801412FC.z - M2C_FIELD(e, u16 *, 0x2C), 0, M2C_FIELD(e, s16 *, 0xB0));
        break;
    case 4:
        if (M2C_FIELD(e, s16 *, 0xAE) == 0) {
            e[0x80] = 5;
            M2C_FIELD(e, s16 *, 0xAA) = 0;
            M2C_FIELD(e, s16 *, 0xB2) = M2C_FIELD(e, s16 *, 0xAC);
        }
        func_80140FD4(e);
        break;
    case 5:
        M2C_FIELD(e, s16 *, 0xAA) += 0x5B;
        if (M2C_FIELD(e, s16 *, 0xAA) > 0x1000) {
            M2C_FIELD(e, s16 *, 0xAA) %= 0x1000;
            e[0x80] = 6;
            pt = &M2C_FIELD(e, Pt_801412FC **, 0x90)[e[0x8E]];
            Object_TurnToward(e, pt->x - M2C_FIELD(e, u16 *, 0x24), pt->z - M2C_FIELD(e, u16 *, 0x2C), 0, M2C_FIELD(e, s16 *, 0xB0));
            break;
        }
        d = ((((rsin_801412FC(M2C_FIELD(e, s16 *, 0xAA)) << 10) >> 12) + 0x1000) % 0x1000);
        M2C_FIELD(e, s16 *, 0xAC) = (M2C_FIELD(e, s16 *, 0xB2) + d + 0x1000) % 0x1000;
        M2C_FIELD(e, s16 *, 0x60) = rcos(M2C_FIELD(e, s16 *, 0xAC));
        M2C_FIELD(e, s16 *, 0x64) = rsin(M2C_FIELD(e, s16 *, 0xAC));
        func_80140FD4(e);
        break;
    case 6:
        if (M2C_FIELD(e, s16 *, 0xAE) == 0) {
            e[0x80] = 1;
        }
        func_80140FD4(e);
        break;
    case 3:
        e[0x8F] ^= 1;
        func_8014102C(e, e[0x8F]);
        Object_TurnToward(e, g_Spike_801412FC.x - M2C_FIELD(e, u16 *, 0x24), g_Spike_801412FC.z - M2C_FIELD(e, u16 *, 0x2C), 0, 0xB6);
        if (func_801412BC(e) != 0) {
            break;
        }
        if (func_8005588C(e, -1) != 0) {
            break;
        }
        e[0x80] = 7;
        func_80141214((s32)e);
        func_80141290(e);
        break;
    case 7:
        if ((M2C_FIELD(e, u32 *, 0x50) >> 28) == 6) {
            e[0x80] = 1;
            func_8005588C(e, 0x2D);
            break;
        }
        if (func_800585D0(e, 0x28, 1, 0) != 0) {
            e[0x80] = 2;
            func_8005588C(e, 0x28);
            M2C_FIELD(e, s16 *, 0xAE) = 0;
            break;
        }
        Object_ApplyVelocity(e);
        break;
    }
    func_8014124C(e);
}

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

extern s32 D_800EC208;
extern s32 D_80144850;
s32 Object_HomeSeesSpike(void *, s32, s32);

s32 func_80141840(void *arg0, s32 mode) {
    s32 ok = D_800EC208 >= D_80144850;
    u32 r;

    if (mode) {
        r = 0;
        if (Object_HomeSeesSpike(arg0, 0x5A, 0xB50)) {
            r = r < ok;
        }
    } else {
        r = 0;
        if (!Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6))) {
            r = r < ok;
        }
    }
    return r;
}

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

typedef struct { u16 start; u16 end; } Rng_80141998;
typedef struct { u8 pad_0[0x5C]; u16 frame; u8 pad_5E[0x2A]; Rng_80141998 *anim; } Obj_80141998;

void func_80141998(void *arg0) {
    s32 r;

    M2C_FIELD(arg0, u8 *, 0x80) = 1;
    M2C_FIELD(arg0, u8 *, 0x7F) = 0;
    r = (RAND() >> 9) + 0x40;
    ((Obj_80141998 *)arg0)->frame = ((Obj_80141998 *)arg0)->anim[0].start;
    func_8005588C(arg0, r);
}

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

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_80141CFC;
typedef struct { u16 start; u16 end; } Rng_80141CFC;
typedef struct { u8 pad_0[0x5C]; u16 frame; u8 pad_5E[0x2A]; Rng_80141CFC *anim; } Obj_80141CFC;
extern u32 g_Game_80141CFC asm("g_Game");
void func_8014173C(u8 *arg0, s32 arg1);
s32 func_80141840(void *arg0, s32 mode);
s32 func_801418D8(u8 *o, s32 r);
void func_80141998(void *arg0);
void func_80141A98(void *arg0);
void func_80141AF8_80141CFC(void *, s32, s32, s32) asm("func_80141AF8");
void func_80141C1C(void *arg0);
void func_80141C74(void *arg0);

void func_80141CFC(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        D_80144850 = -0x365;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, s16 *, 0xA8) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, Flags_80141CFC *, 0xE0).mode = 1;
        ((Obj_80141CFC *)o)->frame = ((Obj_80141CFC *)o)->anim[0].start;
        M2C_FIELD(o, u16 *, 0x5C) = ((Obj_80141CFC *)o)->anim[M2C_FIELD(o, u8 *, 0x7F)].end * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 255;
        func_80052038(o, 0xA9);
        func_8005588C(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 0x40);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (func_80141840(o, 1)) {
            func_801419F0(o);
        } else {
            func_80141C1C(o);
        }
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            func_8005588C(o, 0xF);
        }
        break;
    case 2:
        if (func_80141840(o, 1)) {
            func_801419F0(o);
            func_8014173C(o, 2);
        } else {
            func_8014173C(o, g_Game_80141CFC & 1);
            func_80141C1C(o);
        }
        if (func_8005588C(o, -1) == 0) {
            func_80141998(o);
            func_8014173C(o, 2);
        }
        break;
    case 3:
        if (func_80141840(o, 0) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            func_8005588C(o, 10);
        } else {
            func_80141AF8_80141CFC(o, g_Spike_801404EC.x, g_Spike_801404EC.y, g_Spike_801404EC.z);
            if (func_801418D8(o, 0x96)) {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = 1;
                M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
                M2C_FIELD(o, u32 *, 0xE0) &= ~1;
                func_8005588C(o, 0x1E);
                M2C_FIELD(o, s16 *, 0xA8) = 0;
            }
        }
        break;
    case 4:
        func_8014173C(o, g_Game_80141CFC & 1);
        func_80141C74(o);
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            ((Obj_80141CFC *)o)->frame = ((Obj_80141CFC *)o)->anim[0].start;
            func_8014173C(o, 2);
            func_8005588C(o, 0x3C);
        }
        break;
    case 5:
        if (func_8005588C(o, -1) == 0) {
            func_80141998(o);
        }
        break;
    }
    func_80141A98(o);
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

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

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80142200;
typedef struct { Mat_80142200 m; Mat_80142200 w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_80142200;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_80142200;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_80142200;
#define ADDPRIM_BF_80142200(ot, p) (((PTag_80142200 *)(p))->addr = ((PTag_80142200 *)(ot))->addr, ((PTag_80142200 *)(ot))->addr = (u32)(p))
#define gte_ldv3c_80142200(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_80142200() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_80142200(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_80142200(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Part_80142200 D_80144858_80142200[] asm("D_80144858");
extern Mat_80142200 D_800E78C0_80142200 asm("g_ViewMatrix");
extern u16 g_RandSeed_80142200 asm("g_RandSeed");
extern GameDraw g_Game_80142200 asm("g_Game");
void SetRotMatrix_80142200(Mat_80142200 *) asm("SetRotMatrix");
void SetTransMatrix_80142200(Mat_80142200 *) asm("SetTransMatrix");
void RotMatrixZYX_80142200(SVECTOR *, Mat_80142200 *) asm("RotMatrixZYX");
void CompMatrix_80142200(Mat_80142200 *, Mat_80142200 *, Mat_80142200 *) asm("CompMatrix");
#define SCR_80142200 ((Scr_80142200 *)0x1F800000)

s32 func_80142200(void) {
    s32 i;
    s32 r;
    Part_80142200 *e;
    u32 *p;
    u32 *ot;
    Scr_80142200 *sc;

    sc = SCR_80142200;
    sc->w = D_800E78C0_80142200;
    r = ((u16)(g_RandSeed_80142200 = g_RandSeed_80142200 * 5 + 1) >> 8 & 0xF) + 8;
    sc->v[0][0].vx = -r;
    sc->v[0][0].vy = -r;
    sc->v[0][0].vz = 0;
    sc->v[0][1].vx = r;
    sc->v[0][1].vy = -r;
    sc->v[0][1].vz = 0;
    sc->v[0][2].vx = 0;
    sc->v[0][2].vy = r;
    sc->v[0][2].vz = 0;
    sc->v[1][0].vx = -r * 2;
    sc->v[1][0].vy = -r * 2;
    sc->v[1][0].vz = 0;
    sc->v[1][1].vx = r * 2;
    sc->v[1][1].vy = -r * 2;
    sc->v[1][1].vz = 0;
    sc->v[1][2].vx = 0;
    sc->v[1][2].vy = r * 2;
    sc->v[1][2].vz = 0;
    sc->v[2][0].vx = -r / 3;
    sc->v[2][0].vy = -r * 2;
    sc->v[2][0].vz = 0;
    sc->v[2][1].vx = r / 3;
    sc->v[2][1].vy = -r * 2;
    sc->v[2][1].vz = 0;
    sc->v[2][2].vx = 0;
    sc->v[2][2].vy = r * 3;
    sc->v[2][2].vz = 0;
    sc->v[3][0].vx = -r / 2;
    sc->v[3][0].vy = -r / 2;
    sc->v[3][0].vz = 0;
    sc->v[3][1].vx = r / 2;
    sc->v[3][1].vy = -r / 2;
    sc->v[3][1].vz = 0;
    sc->v[3][2].vx = 0;
    sc->v[3][2].vy = r / 2;
    sc->v[3][2].vz = 0;
    p = (u32 *)g_Game_80142200.prim;
    ot = g_Game_80142200.db[g_Game_80142200.cur].ot;
    for (i = 63; i >= 0; i--) {
        e = &D_80144858_80142200[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            e->vy += 3;
            sc->rot.vx = (e->life << 7) & 0xFFF;
            sc->rot.vy = (e->life << 7) & 0xFFF;
            sc->rot.vz = (e->life << 7) & 0xFFF;
            RotMatrixZYX_80142200(&sc->rot, &sc->m);
            sc->m.t[0] = e->x;
            sc->m.t[1] = e->y;
            sc->m.t[2] = e->z;
            CompMatrix_80142200(&sc->w, &sc->m, &sc->m);
            SetRotMatrix_80142200(&sc->m);
            SetTransMatrix_80142200(&sc->m);
            gte_ldv3c_80142200(sc->v[i & 3]);
            gte_rtpt_80142200();
            gte_stsxy3c_80142200(sc->sxy);
            gte_stszotz_80142200(&sc->z);
            if ((u32)(sc->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 6;
                p[1] = 0x32648080;
                p[3] = 0x405050;
                p[5] = 0x182020;
                p[2] = sc->sxy[0];
                p[4] = sc->sxy[1];
                p[6] = sc->sxy[2];
                ADDPRIM_BF_80142200(ot + sc->z, p);
                p += 7;
                ((u8 *)p)[3] = 1;
                p[1] = 0xE1000220;
                ADDPRIM_BF_80142200(ot + sc->z, p);
                p += 2;
            }
        }
    }
    g_Game_80142200.prim = (u8 *)p;
    return 0;
}

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

typedef struct { u16 b0 : 1; u16 b1 : 3; } BF_801428E4;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_801428E4;
typedef struct { u8 pad_0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad_22[2]; s32 x; s32 y; s32 z; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x14]; u32 f_50; u8 pad_54[0xC]; SVECTOR f_60; SVECTOR f_68; s32 f_70; u8 pad_74[0x90]; s16 f_104; s16 f_106; s32 f_108; s32 f_10C; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad_130[8]; s16 f_138; s16 f_13A; } Spike_801428E4;
typedef struct { u8 pad_0[0x14]; void *f_14; u8 pad_18[4]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad_22[2]; s32 x; s32 y; s32 z; u8 pad_30[0x5C]; u8 f_8C; u8 f_8D; s8 f_8E; u8 pad_8F; u8 f_90[4]; } Veh_801428E4;
extern Spike_801428E4 g_Spike_801428E4 asm("g_Spike");
extern Veh_801428E4 *D_800B4DC4_801428E4 asm("D_800B4DC4");
extern struct { u8 pad_0[0x8]; u8 *f_8; u8 pad_C[0x8146]; u16 f_8152; u8 pad_8154[0x104]; s16 f_8258; s16 f_825A; s16 f_825C; u8 pad_825E[2]; s16 f_8260; s16 f_8262; s16 f_8264; } g_Game_801428E4 asm("g_Game");
extern struct { u8 pad_0[0xA1]; s8 f_A1; u8 pad_A2; s8 f_A3; u8 pad_A4[0xB4]; u32 f_158; u8 pad_15C[4]; u32 f_160; } g_Pad_801428E4 asm("g_Pad");
extern struct { u8 pad_0[0x46]; u8 f_46; } D_800E68D0_801428E4 asm("D_800E68D0");
extern u8 D_800E6916_801428E4 asm("D_800E6916");
extern SVECTOR D_800F4B30_801428E4[2] asm("g_JointAngles");
extern u32 D_800E5478_801428E4 asm("D_800E5478");
extern u8 D_800F4730_801428E4[] asm("g_JointWorldMatrices");
extern u8 D_80144610_801428E4[] asm("D_80144610");
extern u8 D_80144618_801428E4[] asm("D_80144618");
extern u8 D_80144620_801428E4[] asm("D_80144620");
extern u8 D_800E9C60_801428E4[] asm("g_ModelMatrices");
extern u8 D_800E7D00_801428E4[] asm("g_ProjVerts");
s16 func_800433B0_801428E4(s32, s32, s32, s16 *) asm("Floor_GetHeightAndSlope");
s16 Water_Query_801428E4(s32, s32, s32) asm("Water_Query");
s32 rsin_801428E4(s32) asm("rsin");
s32 rcos_801428E4(s32) asm("rcos");
void *ApplyMatrixSV_801428E4(void *, void *, void *) asm("ApplyMatrixSV");
void func_80014804_801428E4(void *, void *) asm("Matrix_FromFacingXZ");
s32 VectorNormalSS_801428E4(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
s32 func_800463A4_801428E4(s32, s32, s32) asm("Math_StepToward");
void Matrix_LookAt_801428E4(void *, void *, void *, s32) asm("Matrix_LookAt");
void Model_CalcJointMatrices_801428E4(void *, s32) asm("Model_CalcJointMatrices");
void Model_ProjectBonedVerts_801428E4(void *) asm("Model_ProjectBonedVerts");
void func_80017CD4_801428E4(void *, void *, void *) asm("Model_Draw");
void func_8004637C_801428E4(void *) asm("Matrix_SetIdentity");
void *CompMatrix_801428E4(void *, void *, void *) asm("CompMatrix");
void Model_ProjectVerts_801428E4(void *, void *, void *) asm("Model_ProjectVerts");
void Effect_SpawnAt_801428E4(s32, void *) asm("Effect_SpawnAt");
void func_8006D548_801428E4(void *) asm("func_8006D548");
void SetRotMatrix_801428E4(void *) asm("SetRotMatrix");
void SetTransMatrix_801428E4(void *) asm("SetTransMatrix");
void RotTransSV_801428E4(void *, void *, s32 *) asm("RotTransSV");
s32 Projectile_Spawn_801428E4(void *, void *, s32) asm("Projectile_Spawn");
u8 *Collision_GetShape_801428E4(s32) asm("Collision_GetShape");
s32 Sound_PlayFixed_801428E4(s32) asm("Sound_PlayFixed");
void Spike_SetPlayMode_801428E4(s32) asm("Spike_SetPlayMode");
void func_8004B83C_801428E4(void) asm("func_8004B83C");
void Camera_EnterAim_801428E4(void) asm("Camera_EnterAim");
void func_80048748_801428E4(void) asm("func_80048748");
void Camera_ExitAim_801428E4(void) asm("Camera_ExitAim");
#define RAND_801428E4() (g_RandSeed = g_RandSeed * 5 + 1)

void func_801428E4(void) {
    SVECTOR v;
    SVECTOR b;
    Mat_801428E4 m;
    SVECTOR u;
    SVECTOR w;
    s32 flag;
    Veh_801428E4 *veh;
    s32 a;
    s32 t0, t1, t2, x, y, z;
    u32 k;

    veh = D_800B4DC4_801428E4;
    g_Spike_801428E4.f_12C = func_800433B0_801428E4(g_Spike_801428E4.x, g_Spike_801428E4.y, g_Spike_801428E4.z, &g_Spike_801428E4.f_104);
    g_Spike_801428E4.f_114 = (g_Spike_801428E4.f_30 << 12) + g_Spike_801428E4.f_108;
    g_Spike_801428E4.f_11C = (g_Spike_801428E4.f_38 << 12) + g_Spike_801428E4.f_110;
    g_Spike_801428E4.f_13A = g_Spike_801428E4.f_138;
    g_Spike_801428E4.f_138 = Water_Query_801428E4(g_Spike_801428E4.x, g_Spike_801428E4.y, g_Spike_801428E4.z);
    g_Spike_801428E4.f_70 = 2;
    g_Spike_801428E4.f_128 = 0;
    g_Spike_801428E4.f_120 = 0;
    g_Spike_801428E4.f_110 = 0;
    g_Spike_801428E4.f_108 = 0;
    g_Spike_801428E4.f_10C += 0x7000;
    g_Spike_801428E4.f_124 = g_Spike_801428E4.f_118 = (g_Spike_801428E4.f_34 << 12) + g_Spike_801428E4.f_10C;
    *(volatile s32 *)&g_Spike_801428E4.f_10C = 0;
    if (D_800E6916_801428E4 != 1 && g_Spike_801428E4.f_12C <= g_Spike_801428E4.y) {
        a = (-g_Pad_801428E4.f_A3 + g_Pad_801428E4.f_A1) / 4;
        m.m[0][0] = rcos_801428E4(a);
        m.m[0][1] = 0;
        m.m[0][2] = -rsin_801428E4(a);
        m.m[1][0] = 0;
        m.m[1][1] = 0x1000;
        m.m[1][2] = 0;
        m.m[2][0] = rsin_801428E4(a);
        m.m[2][1] = 0;
        m.m[2][2] = rcos_801428E4(a);
        if (g_Game_801428E4.f_8152 != 0xB) {
            ApplyMatrixSV_801428E4(&m, &g_Spike_801428E4.f_60, &g_Spike_801428E4.f_60);
        }
        func_80014804_801428E4(&g_Spike_801428E4.f_60, &m);
        v.vy = 0;
        v.vx = 0;
        v.vz = -(g_Pad_801428E4.f_A3 + g_Pad_801428E4.f_A1) / 2;
        ApplyMatrixSV_801428E4(&m, &v, &v);
        if (g_Game_801428E4.f_8152 != 0xB) {
            g_Spike_801428E4.f_108 += v.vx << 10;
            g_Spike_801428E4.f_110 += v.vz << 10;
        }
    }
    v.vy = 0x200;
    v.vx = -g_Spike_801428E4.f_104;
    v.vz = -g_Spike_801428E4.f_106;
    VectorNormalSS_801428E4(&v, &v);
    v.vx = func_800463A4_801428E4(g_Spike_801428E4.f_68.vx, v.vx, 0x40);
    v.vy = func_800463A4_801428E4(g_Spike_801428E4.f_68.vy, v.vy, 0x40);
    v.vz = func_800463A4_801428E4(g_Spike_801428E4.f_68.vz, v.vz, 0x40);
    t0 = g_Spike_801428E4.f_120 + g_Spike_801428E4.f_108;
    g_Spike_801428E4.f_120 = t0;
    t1 = g_Spike_801428E4.f_124 + g_Spike_801428E4.f_10C;
    t2 = g_Spike_801428E4.f_128 + g_Spike_801428E4.f_110;
    g_Spike_801428E4.f_124 = t1;
    g_Spike_801428E4.f_128 = t2;
    x = t0 / 4096;
    g_Spike_801428E4.f_30 = x;
    y = t1 / 4096;
    g_Spike_801428E4.f_34 = y;
    z = t2 / 4096;
    g_Spike_801428E4.f_38 = z;
    g_Spike_801428E4.f_108 = t0 - (x << 12);
    g_Spike_801428E4.f_10C = t1 - (y << 12);
    g_Spike_801428E4.f_110 = t2 - (z << 12);
    g_Spike_801428E4.f_114 = x;
    g_Spike_801428E4.f_11C = z;
    g_Spike_801428E4.f_118 = y;
    VectorNormalSS_801428E4(&v, &g_Spike_801428E4.f_68);
    if (D_800E68D0_801428E4.f_46 != 1) {
        Matrix_LookAt_801428E4(&g_Spike_801428E4.f_60, &g_Spike_801428E4.f_68, veh->f_14, 0);
        veh->x = g_Spike_801428E4.x;
        veh->y = g_Spike_801428E4.y;
        veh->z = g_Spike_801428E4.z;
        g_Spike_801428E4.f_1C = veh->f_1C = g_Spike_801428E4.x;
        g_Spike_801428E4.f_1E = veh->f_1E = g_Spike_801428E4.y - 0x80;
        g_Spike_801428E4.f_20 = veh->f_20 = g_Spike_801428E4.z;
        D_800F4B30_801428E4[0].vx = 0;
        D_800F4B30_801428E4[0].vy = 0;
        D_800F4B30_801428E4[0].vz = 0;
        D_800F4B30_801428E4[1].vx = 0;
        D_800F4B30_801428E4[1].vy = 0;
        D_800F4B30_801428E4[1].vz = 0;
        Model_CalcJointMatrices_801428E4(veh, 3);
        Model_ProjectBonedVerts_801428E4(veh);
        func_80017CD4_801428E4(g_Game_801428E4.f_8 + 0x80, D_800E7D00_801428E4, veh);
        func_8004637C_801428E4(&m);
        m.t[2] = 0x20;
        m.t[1] = -0xC8;
        CompMatrix_801428E4(D_800E9C60_801428E4, &m, &m);
        Model_ProjectVerts_801428E4(veh->f_90, &m, D_800E7D00_801428E4);
        func_80017CD4_801428E4(g_Game_801428E4.f_8, D_800E7D00_801428E4, veh->f_90);
    }
    if (veh->f_8E < 5 && D_800E68D0_801428E4.f_46 != 1) {
        u.vx = veh->f_1C + (((u16)RAND_801428E4() >> 8) - 0x80);
        u.vy = veh->f_1E - ((u16)RAND_801428E4() >> 9);
        u.vz = veh->f_20 + (((u16)RAND_801428E4() >> 8) - 0x80);
        Effect_SpawnAt_801428E4(7, &u);
        if (veh->f_8E < 3) {
            func_8006D548_801428E4(&u);
        }
    }
    if (g_Game_801428E4.f_8152 != 0xB) {
        if (D_800E6916_801428E4 != 1) {
            if ((D_800E5478_801428E4 & 0x400) && veh->f_8C >= 0x1F) {
                SetRotMatrix_801428E4(D_800F4730_801428E4);
                SetTransMatrix_801428E4(D_800F4730_801428E4);
                RotTransSV_801428E4(D_80144610_801428E4, &v, &flag);
                ApplyMatrixSV_801428E4(D_800F4730_801428E4, D_80144620_801428E4, &b);
                Projectile_Spawn_801428E4(&v, &b, 5);
                veh->f_8C = 0;
            } else {
                veh->f_8C++;
            }
            if ((D_800E5478_801428E4 & 0x200) && veh->f_8D >= 6) {
                SetRotMatrix_801428E4(D_800F4730_801428E4);
                SetTransMatrix_801428E4(D_800F4730_801428E4);
                RotTransSV_801428E4(D_80144618_801428E4, &v, &flag);
                ApplyMatrixSV_801428E4(D_800F4730_801428E4, D_80144620_801428E4, &b);
                Projectile_Spawn_801428E4(&v, &b, 4);
                veh->f_8D = 0;
            } else {
                veh->f_8D++;
            }
        } else {
            w.vx = g_Game_801428E4.f_8260 - g_Game_801428E4.f_8258;
            w.vy = g_Game_801428E4.f_8262 - g_Game_801428E4.f_825A;
            w.vz = g_Game_801428E4.f_8264 - g_Game_801428E4.f_825C;
            VectorNormalSS_801428E4(&w, &w);
            if ((D_800E5478_801428E4 & 0x400) && veh->f_8C >= 0x1F) {
                Projectile_Spawn_801428E4(&veh->f_1C, &w, 5);
                veh->f_8C = 0;
            } else {
                veh->f_8C++;
            }
            if ((D_800E5478_801428E4 & 0x200) && veh->f_8D >= 6) {
                Projectile_Spawn_801428E4(&veh->f_1C, &w, 4);
                veh->f_8D = 0;
            } else {
                veh->f_8D++;
            }
        }
    }
    if (g_Spike_801428E4.y >= g_Spike_801428E4.f_12C) {
        s32 bb;
        u32 kk = *(u16 *)0x1F8003F8;
        bb = (kk >> 1) & 7;
        if ((kk & 1) && !bb) {
            veh->f_8E = 0;
        }
    }
    if ((g_Spike_801428E4.f_50 >> 28) == 0xB) {
        s32 dmg = M2C_FIELD(Collision_GetShape_801428E4(M2C_FIELD(&g_Spike_801428E4, u16 *, 0x50) & 0xFFF), u16 *, 0x24) & 0xF;
        veh->f_8E -= dmg;
        Sound_PlayFixed_801428E4(0x78);
    }
    if (veh->f_8E <= 0) {
        Spike_SetPlayMode_801428E4(0);
        return;
    }
    if (D_800E6916_801428E4 != 1 && g_Game_801428E4.f_8152 != 0xB) {
        k = g_Pad_801428E4.f_158 & g_Pad_801428E4.f_160;
        if (k & 0xA) {
            Spike_SetPlayMode_801428E4(0);
            func_8004B83C_801428E4();
        } else if (k & 1) {
            Camera_EnterAim_801428E4();
            func_80048748_801428E4();
        }
    } else if ((g_Pad_801428E4.f_158 & g_Pad_801428E4.f_160) & 1) {
        Camera_ExitAim_801428E4();
    }
}

extern struct { u8 pad_0[0x8290]; u16 f_8290; } g_Game_801431B0 asm("g_Game");
extern SVECTOR D_800F4B30_801431B0[3] asm("g_JointAngles");
extern s32 D_800EC358;
s16 Floor_GetHeight_801431B0(s32, s32, s32) asm("Floor_GetHeight");
void Matrix_LookAt(void *, void *, void *, s32);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_801431B0(s32, void *, void *) asm("Model_Draw");
void Fx_DebrisExplosion_801431B0(s32, s32, s32) asm("Fx_DebrisExplosion");
void func_8006D548_801431B0(void *) asm("func_8006D548");
void func_8014283C(void);
typedef struct { u16 a : 1; u16 b : 3; u16 c : 12; } Pad_801431B0;

void func_801431B0(s32 arg0) {
    u8 *o = D_800B4DC4;
    s32 fl;
    s32 y;
    SVECTOR v;
    u16 pad;
    u16 t;

    if (arg0 == 1) {
        func_8014283C();
        return;
    }
    g_Game_801431B0.f_8290 = M2C_FIELD(o, u16 *, 0x74);
    fl = Floor_GetHeight_801431B0(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C));
    y = M2C_FIELD(o, s32 *, 0x28);
    if (y < fl) {
        if (fl - y > 0x20) {
            M2C_FIELD(o, s32 *, 0x28) = y + 0x20;
        } else {
            M2C_FIELD(o, s32 *, 0x28) = fl;
        }
        M2C_FIELD(M2C_FIELD(o, u8 **, 0x70), s16 *, 2) = M2C_FIELD(o, s32 *, 0x28);
    } else {
        pad = *(u16 *)0x1F8003F8;
        t = (pad >> 1) & 7;
        if ((pad & 1) && t == 0) {
            o[0x8E] = 0;
        }
        M2C_FIELD(o, s32 *, 0x28) = fl;
        M2C_FIELD(M2C_FIELD(o, u8 **, 0x70), s16 *, 2) = M2C_FIELD(o, s32 *, 0x28);
    }
    M2C_FIELD(o, s16 *, 0x1C) = M2C_FIELD(o, s32 *, 0x24);
    M2C_FIELD(o, s16 *, 0x1E) = M2C_FIELD(o, s32 *, 0x28) - 0x80;
    M2C_FIELD(o, s16 *, 0x20) = M2C_FIELD(o, s32 *, 0x2C);
    Matrix_LookAt(o + 0x60, o + 0x68, M2C_FIELD(o, void **, 0x14), 0);
    D_800F4B30_801431B0[0].vx = 0;
    D_800F4B30_801431B0[0].vy = 0;
    D_800F4B30_801431B0[0].vz = 0;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_801431B0(D_800EC358, &g_ProjVerts, o);
    if (M2C_FIELD(o, s8 *, 0x8E) <= 0) {
        Sound_PlayFixed(0x79);
        Fx_DebrisExplosion_801431B0(M2C_FIELD(o, s16 *, 0x1C), M2C_FIELD(o, s16 *, 0x1E), M2C_FIELD(o, s16 *, 0x20));
        func_8014283C();
        return;
    }
    if (M2C_FIELD(o, s8 *, 0x8E) < 5) {
        v.vx = M2C_FIELD(o, u16 *, 0x1C) + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        v.vy = M2C_FIELD(o, u16 *, 0x1E) - ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        v.vz = M2C_FIELD(o, u16 *, 0x20) + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80);
        Effect_SpawnAt(7, &v);
        if (M2C_FIELD(o, s8 *, 0x8E) < 3) {
            func_8006D548_801431B0(&v);
        }
    }
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_801433F0;
typedef struct { s8 a[4]; } Stk_801433F0;
typedef struct { u8 pad_0[0x14]; void *f_14; s32 f_18; u8 pad_1C[8]; s32 x; s32 y; s32 z; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x20]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[8]; s32 f_70; u8 pad_74[0x90]; s16 f_104; s16 f_106; s32 f_108; s32 f_10C; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad_130[8]; u16 f_138; u16 f_13A; s16 f_13C; s16 f_13E; } Spike_801433F0;
typedef struct { u8 pad_0[0x14]; void *f_14; s32 f_18; u8 pad_1C[8]; s32 x; s32 y; s32 z; u8 pad_30[0x48]; s16 f_78; s16 f_7A; s16 f_7C; u8 pad_7E[0xE]; u8 f_8C; u8 f_8D; u8 pad_8E[0x12]; Stk_801433F0 st; s16 f_A4; s16 f_A6; s16 f_A8; s16 f_AA; } Veh_801433F0;
extern Spike_801433F0 g_Spike_801433F0 asm("g_Spike");
extern Veh_801433F0 *D_800B4DC4_801433F0 asm("D_800B4DC4");
extern Stk_801433F0 D_800E53C0_801433F0 asm("D_800E53C0");
extern struct { s32 f_0; u8 pad_4[8]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_801433F0 asm("g_Game");
extern struct { u8 pad_0[0x158]; u32 f_158; u8 pad_15C[4]; u32 f_160; } g_Pad_801433F0 asm("g_Pad");
extern u8 D_800E6902_801433F0 asm("D_800E6902");
extern s32 D_800EC014_801433F0 asm("D_800EC014");
extern s32 D_800E54C4_801433F0 asm("D_800E54C4");
extern s32 D_800E54C8_801433F0 asm("D_800E54C8");
extern s16 D_800F4B30_801433F0[] asm("g_JointAngles");
extern u8 D_800E7D00_801433F0[] asm("g_ProjVerts");
s16 func_800433B0_801433F0(s32, s32, s32, s16 *) asm("Floor_GetHeightAndSlope");
u16 Water_Query_801433F0(s32, s32, s32) asm("Water_Query");
s32 rsin_801433F0(s32) asm("rsin");
s32 rcos_801433F0(s32) asm("rcos");
s32 Sound_PlayFixed_801433F0(s32) asm("Sound_PlayFixed");
void func_8004637C_801433F0(void *) asm("Matrix_SetIdentity");
void *RotMatrixY_801433F0(s32, void *) asm("RotMatrixY");
void *ApplyMatrixSV_801433F0(void *, void *, void *) asm("ApplyMatrixSV");
void func_8006699C_801433F0(s32) asm("func_8006699C");
void func_80014804_801433F0(void *, void *) asm("Matrix_FromFacingXZ");
void Model_CalcJointMatrices_801433F0(void *, s32) asm("Model_CalcJointMatrices");
void Model_ProjectBonedVerts_801433F0(void *) asm("Model_ProjectBonedVerts");
void func_80017CD4_801433F0(void *, void *, void *) asm("Model_Draw");
void Anim_SetFrame_801433F0(void *) asm("Anim_SetFrame");
void Spike_SetPlayMode_801433F0(s32) asm("Spike_SetPlayMode");
void func_8004B83C_801433F0(void) asm("func_8004B83C");
void Spike_UpdateFootEffects_801433F0(void) asm("Spike_UpdateFootEffects");
#define CLAMP_801433F0(v, lo, hi) ((v) < (lo) ? (lo) : (v) > (hi) ? (hi) : (v))

void func_801433F0(void) {
    Mat_801433F0 m;
    Spike_801433F0 *sp = &g_Spike_801433F0;
    Veh_801433F0 *veh;
    s32 rot;
    s32 spd;
    s32 a;
    s32 r;
    s32 t0, t1, t2, x, y, z;
    s32 save;
    s32 c;
    Stk_801433F0 *pad;

    veh = D_800B4DC4_801433F0;
    sp->f_12C = func_800433B0_801433F0(sp->x, sp->y, sp->z, &sp->f_104);
    pad = &D_800E53C0_801433F0;
    veh->st = *pad;
    sp->f_13A = sp->f_138;
    sp->f_138 = Water_Query_801433F0(sp->x, sp->y, sp->z);
    sp->f_128 = 0;
    sp->f_120 = 0;
    sp->f_70 = 1;
    if ((sp->f_138 >> 12) == 1) {
        u16 *q = (u16 *)0x1F8003D4;
        sp->f_13E = q[5];
        sp->f_13C = q[5] - q[8];
        if (sp->y - sp->f_13C > 0x20) {
            sp->f_10C -= 0x3000;
        } else if (sp->f_34 < 0) {
            sp->f_34 = 0;
            sp->f_10C = 0;
        }
        veh->f_78 = g_Spike_801433F0.x;
        veh->f_7A = g_Spike_801433F0.y;
        veh->f_7C = g_Spike_801433F0.z;
    } else {
        if (sp->f_12C <= sp->y) {
            sp->x = veh->f_78;
            sp->y = veh->f_7A;
            sp->z = veh->f_7C;
            sp->f_30 = -sp->f_114;
            sp->f_38 = -sp->f_11C;
            sp->f_34 = 0;
        }
        sp->f_10C += D_800EC014_801433F0 << 7;
    }
    g_Spike_801433F0.f_30 = CLAMP_801433F0(g_Spike_801433F0.f_30, -0x20, 0x20);
    g_Spike_801433F0.f_38 = CLAMP_801433F0(g_Spike_801433F0.f_38, -0x20, 0x20);
    g_Spike_801433F0.f_114 = (g_Spike_801433F0.f_30 << 12) + g_Spike_801433F0.f_108;
    g_Spike_801433F0.f_11C = (g_Spike_801433F0.f_38 << 12) + g_Spike_801433F0.f_110;
    g_Spike_801433F0.f_124 = g_Spike_801433F0.f_118 = (g_Spike_801433F0.f_34 << 12) + g_Spike_801433F0.f_10C;
    g_Spike_801433F0.f_110 = 0;
    g_Spike_801433F0.f_10C = 0;
    g_Spike_801433F0.f_108 = 0;
    g_Spike_801433F0.f_124 = CLAMP_801433F0(g_Spike_801433F0.f_124, -0x1E000, 0x1E000);
    rot = 0;
    if (D_800E6902_801433F0 != 1) {
        spd = 0;
        if (pad->a[1] > 100) {
            veh->f_A4++;
        } else if (pad->a[1] < -100) {
            veh->f_A4--;
        } else {
            veh->f_A4 = 0;
            veh->f_A8 = 0;
        }
        if (pad->a[3] > 100) {
            veh->f_A6++;
        } else if (pad->a[3] < -100) {
            veh->f_A6--;
        } else {
            veh->f_A6 = 0;
        }
        if ((veh->f_A4 >= 0x10 && veh->f_A6 >= 0x10) || (veh->f_A4 < -0xF && veh->f_A6 < -0xF)) {
            veh->f_AA = veh->f_A8;
        }
        if (veh->f_A4 >= 0xF) {
            veh->f_A4 = 0xF;
            a = veh->f_A8 + 0x100;
            r = -rsin_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[1] = c;
            r = rcos_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[0] = c;
            veh->f_A8 = a & 0xFFF;
        } else if (veh->f_A4 < -0xE) {
            veh->f_A4 = -0xF;
            a = veh->f_A8 + 0xF00;
            r = -rsin_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[1] = c;
            r = rcos_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[0] = c;
            veh->f_A8 = a & 0xFFF;
        }
        if (veh->st.a[0] > 0x50) {
            if (veh->f_A4 >= 0xF) {
                rot -= 0x20;
                spd += 0x100;
            } else if (veh->f_A4 < -0xE) {
                rot += 0x20;
                spd -= 0x100;
            } else {
                rot -= D_800E54C4_801433F0 >> 6;
                spd += D_800E54C4_801433F0 >> 4;
            }
            if (!(veh->f_8C & 1)) {
                veh->f_8C = 0x11;
                Sound_PlayFixed_801433F0(0xB0);
            } else {
                veh->f_8C = 1;
            }
        } else if (veh->f_8C & 1) {
            veh->f_8C = 0x10;
        } else {
            veh->f_8C = 0;
        }
        if (veh->f_A6 >= 0xF) {
            veh->f_A6 = 0xF;
            a = veh->f_AA + 0x100;
            r = -rsin_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[3] = c;
            r = -rcos_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[2] = c;
            veh->f_AA = a & 0xFFF;
        } else if (veh->f_A6 < -0xE) {
            veh->f_A6 = -0xF;
            a = veh->f_AA + 0xF00;
            r = -rsin_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[3] = c;
            r = -rcos_801433F0(a) >> 5;
            c = CLAMP_801433F0(r, -0x7F, 0x7F);
            veh->st.a[2] = c;
            veh->f_AA = a & 0xFFF;
        }
        if (veh->st.a[2] < -0x50) {
            if (veh->f_A6 >= 0xF) {
                rot += 0x20;
                spd += 0x100;
            } else if (veh->f_A6 < -0xE) {
                rot -= 0x20;
                spd -= 0x100;
            } else {
                rot -= D_800E54C8_801433F0 >> 6;
                spd -= D_800E54C8_801433F0 >> 4;
            }
            if (!(veh->f_8D & 1)) {
                veh->f_8D = 0x11;
                Sound_PlayFixed_801433F0(0xB0);
            } else {
                veh->f_8D = 1;
            }
        } else if (veh->f_8D & 1) {
            veh->f_8D = 0x10;
        } else {
            veh->f_8D = 0;
        }
        func_8004637C_801433F0(&m);
        RotMatrixY_801433F0(rot, &m);
        ApplyMatrixSV_801433F0(&m, &g_Spike_801433F0.f_60, &g_Spike_801433F0.f_60);
        g_Spike_801433F0.f_108 += (g_Spike_801433F0.f_60.vx * spd) >> 2;
        g_Spike_801433F0.f_110 += (g_Spike_801433F0.f_60.vz * spd) >> 2;
    }
    g_Spike_801433F0.f_120 += g_Spike_801433F0.f_108;
    g_Spike_801433F0.f_124 += g_Spike_801433F0.f_10C;
    g_Spike_801433F0.f_128 += g_Spike_801433F0.f_110;
    g_Spike_801433F0.f_120 = CLAMP_801433F0(g_Spike_801433F0.f_120, -0x14000, 0x14000);
    g_Spike_801433F0.f_128 = CLAMP_801433F0(g_Spike_801433F0.f_128, -0x14000, 0x14000);
    func_8006699C_801433F0(spd == 0 ? 0x2AA : 0x3000);
    t0 = g_Spike_801433F0.f_120;
    x = t0 / 4096;
    g_Spike_801433F0.f_30 = x;
    t1 = g_Spike_801433F0.f_124;
    y = t1 / 4096;
    g_Spike_801433F0.f_34 = y;
    t2 = g_Spike_801433F0.f_128;
    z = t2 / 4096;
    g_Spike_801433F0.f_38 = z;
    g_Spike_801433F0.f_108 = t0 - (x << 12);
    g_Spike_801433F0.f_10C = t1 - (y << 12);
    g_Spike_801433F0.f_110 = t2 - (z << 12);
    g_Spike_801433F0.f_114 = x;
    g_Spike_801433F0.f_11C = z;
    g_Spike_801433F0.f_118 = y;
    func_80014804_801433F0(&g_Spike_801433F0.f_60, veh->f_14);
    veh->x = g_Spike_801433F0.x;
    veh->y = g_Spike_801433F0.y + (rsin_801433F0(g_Game_801433F0.f_0 << 6) >> 9);
    veh->z = g_Spike_801433F0.z;
    D_800F4B30_801433F0[0] = 0;
    D_800F4B30_801433F0[1] = 0x800;
    D_800F4B30_801433F0[2] = 0;
    D_800F4B30_801433F0[4] = 0x400 - (veh->st.a[3] << 2);
    D_800F4B30_801433F0[5] = 0;
    D_800F4B30_801433F0[6] = (veh->st.a[2] << 2) - 0x480;
    D_800F4B30_801433F0[8] = (veh->st.a[1] << 2) + 0x400;
    D_800F4B30_801433F0[9] = 0;
    D_800F4B30_801433F0[10] = (veh->st.a[0] << 2) - 0x380;
    Model_CalcJointMatrices_801433F0(veh, 3);
    Model_ProjectBonedVerts_801433F0(veh);
    func_80017CD4_801433F0(g_Game_801433F0.f_80 + g_Game_801433F0.f_C * 0x4078, D_800E7D00_801433F0, veh);
    if (++g_Spike_801433F0.f_5C >= 0x1E) {
        g_Spike_801433F0.f_5C = 0;
    }
    func_80014804_801433F0(&g_Spike_801433F0.f_60, g_Spike_801433F0.f_14);
    RotMatrixY_801433F0(0x800, g_Spike_801433F0.f_14);
    save = g_Spike_801433F0.f_18;
    g_Spike_801433F0.f_18 = veh->f_18;
    Anim_SetFrame_801433F0(&g_Spike_801433F0);
    g_Spike_801433F0.f_18 = save;
    D_800F4B30_801433F0[0x12] -= veh->st.a[2] << 2;
    D_800F4B30_801433F0[0x16] += veh->st.a[0] << 2;
    D_800F4B30_801433F0[0x22] -= veh->st.a[2] << 1;
    D_800F4B30_801433F0[0x26] += veh->st.a[0] << 1;
    D_800F4B30_801433F0[0x21] += veh->st.a[3] << 2;
    D_800F4B30_801433F0[0x25] -= veh->st.a[1] << 2;
    Model_CalcJointMatrices_801433F0(&g_Spike_801433F0, 1);
    Model_ProjectBonedVerts_801433F0(&g_Spike_801433F0);
    func_80017CD4_801433F0(g_Game_801433F0.f_80 + g_Game_801433F0.f_C * 0x4078, D_800E7D00_801433F0, &g_Spike_801433F0);
    if ((g_Pad_801433F0.f_158 & g_Pad_801433F0.f_160) & 0xA) {
        Spike_SetPlayMode_801433F0(0);
        func_8004B83C_801433F0();
    }
    Spike_UpdateFootEffects_801433F0();
}

typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[4]; s16 f10; } Scr_80143F38;
extern SVECTOR g_JointAngles[3];
extern struct { s32 f0; u8 pad4[4]; s32 f8; } g_Game_80143F38 asm("g_Game");
s16 Floor_GetHeight_80143F38(s32, s32, s32) asm("Floor_GetHeight");
s32 Water_Query(s32, s32, s32);
s32 rsin_80143F38(s32) asm("rsin");
void Matrix_FromFacingXZ(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_80143F38(s32, void *, void *) asm("Model_Draw");

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
    Matrix_FromFacingXZ((s16 *)(o + 0x60), M2C_FIELD(o, s16 **, 0x14));
    y = M2C_FIELD(o, s32 *, 0x28);
    M2C_FIELD(o, s32 *, 0x28) += rsin_80143F38(g_Game_80143F38.f0 << 6) >> 9;
    g_JointAngles[0].vx = 0;
    g_JointAngles[0].vy = 0x800;
    g_JointAngles[0].vz = 0;
    g_JointAngles[1].vx = 0x400;
    g_JointAngles[1].vy = 0;
    g_JointAngles[1].vz = -0x480;
    g_JointAngles[2].vx = 0x400;
    g_JointAngles[2].vy = 0;
    g_JointAngles[2].vz = -0x380;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_80143F38(g_Game_80143F38.f8, (u8 *)&g_ProjVerts, o);
    M2C_FIELD(o, s32 *, 0x28) = y;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
