#include "common.h"
#include "m2c_macros.h"

M2C_UNK Link_Activate(s16, void *);
extern struct S_g_Game { u8 pad_0[0x8160]; u16 f_8160; u8 pad_8162[0xAA]; s32 f_820C; } g_Game;
s32 func_800978E0(s16);

M2C_UNK Model_BindStageMesh(s32, s16);
M2C_UNK Stage_CountCaughtMonkeys(s32 *);
extern s32 g_StageMeshes;
M2C_UNK Collision_Set(M2C_UNK, void *, M2C_UNK *);
extern struct S_D_8013DCE0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x8]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[0x14]; s16 f_60; s16 f_62; s16 f_64; } D_8013DCE0;
s32 SpecterCoin_Count();
s32 func_800964B0(M2C_UNK);

s32 TimeStation_ShowCaughtMonkeys(void *arg0) {
    s32 sp10;
    s32 var_s0;

    if ((M2C_FIELD(arg0, s16 *, 0xC) >= 0) && (M2C_FIELD(arg0, s16 *, 0xE) >= 0)) {
        Stage_CountCaughtMonkeys(&sp10);
        var_s0 = 0;
        if (M2C_FIELD(arg0, s16 *, 8) > 0) {
            do {
                if (var_s0 < sp10) {
                    Model_BindStageMesh(g_StageMeshes + ((M2C_FIELD(arg0, s16 *, 0xC) + var_s0) << 5), M2C_FIELD(arg0, s16 *, 0xE));
                }
                var_s0 += 1;
            } while (var_s0 < M2C_FIELD(arg0, s16 *, 8));
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013D0B4 asm("g_Game");
extern u8 *D_800B4D64_8013D0B4 asm("g_StageMeshes");

s32 LinkHide_Update(s16 *p) {
    u8 *e;
    u8 *t;

    if (p[4] < 0) {
        return 0;
    }
    e = g_Game_8013D0B4.f_820C + p[2] * 0x38;
    t = g_Game_8013D0B4.f_8220 + p[4] * 0x18;
    if (p[1] == 0 && M2C_FIELD(t, s16 *, 2) == 1) {
        p[1] = 1;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013D0B4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013D158 asm("g_Game");
extern u8 *D_800B4D64_8013D158 asm("g_StageMeshes");

s32 LinkMesh_Init(s16 *p) {
    u8 *e = g_Game_8013D158.f_820C + p[2] * 0x38;

    p[1] = 0;
    p[3] = 0;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        if (p[4] == 0) {
            Model_BindStageMesh(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, p[7]);
        } else {
            Model_BindStageMesh(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, p[8]);
        }
        M2C_FIELD(D_800B4D64_8013D158 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    return 0;
}

typedef struct { s16 x, y, z; u8 pad6[8]; s16 f_E; u8 pad10[8]; u16 flags; u8 pad1A[0x1E]; } Ent_8013D208;
typedef struct { u8 pad0[2]; s16 f_2; u8 pad4[0x14]; } Coll_8013D208;
typedef struct { u8 pad0[0x16]; u16 f_16; u8 pad18[8]; } Mesh_8013D208;
extern struct { u32 frame; u8 pad_4[0x8208]; Ent_8013D208 *f_820C; u8 pad_8210[0x10]; Coll_8013D208 *f_8220; } g_Game_8013D208 asm("g_Game");
extern Mesh_8013D208 *D_800B4D64_8013D208 asm("g_StageMeshes");
extern u16 g_RandSeed;
void Camera_StartShake(s32);
s32 Cd_PlayXaTrack(s32);
void Effect_SpawnAt(s32, void *);
void Spike_SetState(s32);
void Pad_Vibrate(s32, s32, s32);
s32 Sound_PlayFixed(s32);

s32 BreakTarget_Update(s16 *a) {
    SVECTOR v;
    Ent_8013D208 *e;
    Coll_8013D208 *c;
    s32 hit;

    if (a[6] < 0) {
        return 0;
    }
    e = &g_Game_8013D208.f_820C[a[2]];
    c = &g_Game_8013D208.f_8220[a[6]];
    switch (a[1]) {
    case 0:
        hit = c->f_2;
        if (hit != 1) {
            break;
        }
        if (e->f_E >= 0) {
            D_800B4D64_8013D208[e->f_E].f_16 = 0xFFFF;
        }
        Camera_StartShake(0);
        Pad_Vibrate(0, 1, 3);
        v.vx = e->x;
        v.vy = e->y - 0x80;
        v.vz = e->z;
        if (a[4] == 0) {
            a[1] = 2;
            a[3] = 0x28;
            e->flags |= 0x8000;
            break;
        }
        a[1] = hit;
        a[3] = 0x14;
        Sound_PlayFixed(0x7A);
        Effect_SpawnAt(0x103, &v);
        break;
    case 1:
        if (--a[3] < 0) {
            a[1] = 3;
            break;
        }
        if ((s16)(a[3] % 5) != 0) {
            break;
        }
        v.vx = e->x - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) - 0x80);
        v.vy = e->y - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) + 0x80);
        v.vz = e->z - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) - 0x80);
        Sound_PlayFixed(0x7A);
        Effect_SpawnAt(0x103, &v);
        break;
    case 2:
        if (--a[3] < 0) {
            a[1] = 3;
            break;
        }
        if ((s16)(a[3] % 5) != 0) {
            break;
        }
        if (a[3] > 20) {
            break;
        }
        if (a[3] == 20) {
            D_800B4D64_8013D208[e->f_E].f_16 = 0;
            Spike_SetState(0x22);
            Cd_PlayXaTrack(g_Game_8013D208.frame & 1 ? 0xD : 0xF);
        }
        v.vx = e->x - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) - 0x80);
        v.vy = e->y - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) + 0x80);
        v.vz = e->z - (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0xFE) - 0x80);
        Effect_SpawnAt(0x102, &v);
        Sound_PlayFixed(0x4D);
        Sound_PlayFixed(0x5F);
        break;
    }
    return 0;
}

typedef struct { u8 pad0[4]; s16 f_4; u8 pad6[2]; s16 f_8; u8 padA[0xE]; } Trig_8013D5C0;
typedef struct { s16 x, y, z; u8 pad6[0x32]; } Ent_8013D5C0;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_8013D5C0;
extern struct { u8 pad_0[0x820C]; Ent_8013D5C0 *f_820C; u8 pad_8210[0x10]; Trig_8013D5C0 *f_8220; } g_Game_8013D5C0 asm("g_Game");
extern Monkey_8013D5C0 g_Monkeys_8013D5C0[] asm("g_Monkeys");
extern u16 g_RandSeed_8013D5C0 asm("g_RandSeed");

s32 Training_PlaceMonkey(s16 *p) {
    s32 i;
    s32 r;
    s32 n;
    Trig_8013D5C0 *t;
    Ent_8013D5C0 *e;

    for (i = 7; i >= 0; i--) {
        g_Monkeys_8013D5C0[i].f_7A = 0;
    }
    r = (g_RandSeed_8013D5C0 = g_RandSeed_8013D5C0 * 5 + 1) >> 8 & 7;

    if (!(r & 1)) {
        t = &g_Game_8013D5C0.f_8220[p[6]];
    } else {
        t = &g_Game_8013D5C0.f_8220[p[9]];
    }
    n = t->f_4;
    t->f_8 = 1;
    g_Monkeys_8013D5C0[0].f_7A = 4;
    e = &g_Game_8013D5C0.f_820C[n];
    g_Monkeys_8013D5C0[0].x = e->x;
    g_Monkeys_8013D5C0[0].y = e->y;
    g_Monkeys_8013D5C0[0].z = e->z;

    if (!(r & 2)) {
        t = &g_Game_8013D5C0.f_8220[p[7]];
    } else {
        t = &g_Game_8013D5C0.f_8220[p[10]];
    }
    n = t->f_4;
    t->f_8 = 2;
    g_Monkeys_8013D5C0[1].f_7A = 4;
    e = &g_Game_8013D5C0.f_820C[n];
    g_Monkeys_8013D5C0[1].x = e->x;
    g_Monkeys_8013D5C0[1].y = e->y;
    g_Monkeys_8013D5C0[1].z = e->z;

    if (!(r & 4)) {
        t = &g_Game_8013D5C0.f_8220[p[8]];
    } else {
        t = &g_Game_8013D5C0.f_8220[p[11]];
    }
    n = t->f_4;
    t->f_8 = 3;
    g_Monkeys_8013D5C0[2].f_7A = 4;
    e = &g_Game_8013D5C0.f_820C[n];
    g_Monkeys_8013D5C0[2].x = e->x;
    g_Monkeys_8013D5C0[2].y = e->y;
    g_Monkeys_8013D5C0[2].z = e->z;
    return 0;
}

extern struct { u8 pad_0[0x220]; u8 *f_220; } D_800F4350_8013D7E8 asm("D_800F4350");
typedef struct { u8 pad_0[0x7A]; u8 f_7A; u8 pad_7B[0x250 - 0x7B]; } Monkey_8013D7E8;
extern Monkey_8013D7E8 g_Monkeys_8013D7E8[] asm("g_Monkeys");

s32 Training_CountSwitches(s16 *p) {
    s32 n = 0;
    s32 i;
    s16 *t;

    for (i = 2; i < 8; i++) {
        t = (s16 *)(D_800F4350_8013D7E8.f_220 + p[i + 4] * 0x18);
        if (t[1] != 0) {
            if (t[4] != 0) {
                g_Monkeys_8013D7E8[t[4] - 1].f_7A = 2;
            }
            n++;
        }
    }
    if (n == 3) {
        Link_Activate(p[5], p);
    }
    return 0;
}

s32 Training_CheckScore(void *arg0) {
    if ((s32) g_Game.f_8160 >= M2C_FIELD(arg0, s16 *, 0xA)) {
        Link_Activate(M2C_FIELD(arg0, s16 *, 8), arg0);
    }
    return 0;
}

s32 SlingTarget_Init(void *arg0) {
    D_8013DCE0.f_44 = 0x40;
    D_8013DCE0.f_46 = 0x100;
    D_8013DCE0.f_30 = 0;
    D_8013DCE0.f_34 = 0;
    D_8013DCE0.f_38 = 0;
    D_8013DCE0.f_48 = 0;
    D_8013DCE0.f_4A = 0;
    D_8013DCE0.f_60 = 0x1000;
    D_8013DCE0.f_62 = 0;
    D_8013DCE0.f_64 = 0;
    D_8013DCE0.f_24 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + g_StageMeshes), s16 *, 0x10);
    D_8013DCE0.f_28 = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + g_StageMeshes), s16 *, 0x12);
    D_8013DCE0.f_2C = (s32) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0xC) << 5) + g_StageMeshes), s16 *, 0x14);
    Collision_Set(3, (void *)((u8 *)&D_8013DCE0 + 0x24), &D_8013DCE0);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) D_8013DCE0.f_28;
    return 0;
}

extern struct { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad_30[0x20]; u32 f_50; } D_8013DCE0_8013D9D4 asm("D_8013DCE0");
extern struct { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } Gadget_HeldModel;
extern u8 *D_800B4D64_8013D9D4 asm("g_StageMeshes");

s32 SlingTarget_Update(s16 *p) {
    Gadget_HeldModel.f_24 = D_8013DCE0_8013D9D4.f_24;
    Gadget_HeldModel.f_28 = D_8013DCE0_8013D9D4.f_28;
    Gadget_HeldModel.f_2C = D_8013DCE0_8013D9D4.f_2C;
    if (p[1] == 0) {
        if ((D_8013DCE0_8013D9D4.f_50 >> 28) == 8) {
            Link_Activate(p[4], p);
            Collision_Remove((s32)&D_8013DCE0_8013D9D4.f_24);
            M2C_FIELD(D_800B4D64_8013D9D4 + p[6] * 32, s16 *, 0x16) = 0;
            p[1] = 1;
        } else {
            if (p[5] == 0) {
                p[3] += 4;
                if (p[3] > 0x100) {
                    p[3] = 0x100;
                    p[5] = 1;
                }
            } else {
                p[3] -= 4;
                if (p[3] < -0x100) {
                    p[3] = -0x100;
                    p[5] = 0;
                }
            }
            D_8013DCE0_8013D9D4.f_28 = p[7] + p[3];
            M2C_FIELD(D_800B4D64_8013D9D4 + p[6] * 32, u16 *, 0x12) = M2C_FIELD(&D_8013DCE0_8013D9D4, u16 *, 0x28);
        }
    }
    return 0;
}

__asm__(".section .text\n.balign 16");

/* object type tables for the Time Station areas: {init, update, ?} triples, zero-terminated */
s32 LiftDoor_Init();
s32 LiftDoor_Update();
s32 PressurePlate_Init();
s32 Link_UpdatePressurePlate();
s32 Switch_Init();
s32 Mailbox_Init();
s32 Mailbox_Update();
s32 Link_ToggleSwitch();
s32 HitSwitch_Update();
s32 CounterLink_Init();
s32 CounterLink_Update();
s32 HitCounter_Init();
s32 HitCounter_Update();
void *D_8013DB30[24] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    Training_PlaceMonkey, Training_CountSwitches, 0,
    PressurePlate_Init, Link_UpdatePressurePlate, 0,
    Switch_Init, LinkHide_Update, 0,
    LinkMesh_Init, BreakTarget_Update, 0,
    TimeStation_ShowCaughtMonkeys, TimeStation_ShowCaughtMonkeys, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
void *D_8013DB90[15] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    Link_ToggleSwitch, HitSwitch_Update, 0,
    Mailbox_Init, Mailbox_Update, 0,
    Switch_Init, Training_CheckScore, 0,
    0, 0, 0,
};
void *D_8013DBCC[15] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    PressurePlate_Init, Link_UpdatePressurePlate, 0,
    Switch_Init, Training_CheckScore, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
void *D_8013DC08[18] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    CounterLink_Init, CounterLink_Update, 0,
    Link_ToggleSwitch, HitSwitch_Update, 0,
    HitCounter_Init, HitCounter_Update, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
void *D_8013DC50[9] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
void *D_8013DC74[12] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    PressurePlate_Init, Link_UpdatePressurePlate, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
void *D_8013DCA4[12] = {
    LiftDoor_Init, LiftDoor_Update, 0,
    SlingTarget_Init, SlingTarget_Update, 0,
    Mailbox_Init, Mailbox_Update, 0,
    0, 0, 0,
};
__asm__("\t.balign 16");  /* GCC is still emitting .data here */
struct S_D_8013DCE0 D_8013DCE0 = { 0 };
