#include "common.h"
#include "m2c_macros.h"

extern s32 D_800B4D64;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xB6]; s32 f_820C; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
M2C_UNK Effect_Spawn(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_800B4D88;
extern M2C_UNK D_80141640;
extern struct S_D_80141880 { u8 pad_0[0x2]; u16 f_2; s16 f_4; u8 pad_6[0x2]; s16 f_8; u8 pad_A[0x6]; s32 f_10; s32 f_14; } D_80141880;
extern struct S_g_Spike { u8 pad_0[0x2C]; s32 f_2C; s32 f_30; u8 pad_34[0x4]; s32 f_38; } g_Spike;

extern struct S_D_80142368 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80142368[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142728;
s32 Sound_Play(M2C_UNK, s32);
M2C_UNK func_8013D440(M2C_UNK, M2C_UNK *, void *);
extern M2C_UNK D_80141D20;
extern M2C_UNK D_801421C0;
extern M2C_UNK D_80142260;
extern M2C_UNK D_801418A0;

s32 func_8013D000(void *arg0) {
    s16 temp_a0;
    void *temp_v1;

    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    temp_a0 = M2C_FIELD(arg0, s16 *, 0xC);
    if (temp_a0 >= 0) {
        M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D06C);

int abs(int);
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D2A0 asm("g_Spike");
extern u8 *D_800B4D64_8013D2A0 asm("D_800B4D64");
void Model_BindStageMesh(void *, s32);

s32 func_8013D2A0(s16 *p) {
    switch (p[1]) {
    case 0:
        if (abs(g_Spike_8013D2A0.x - 0x620) < 0x3A0 && abs(g_Spike_8013D2A0.y + 0xA00) < 0x100 && abs(g_Spike_8013D2A0.z + 0xDC0) < 0x1C0) {
            p[1] = 1;
            Model_BindStageMesh(D_800B4D64_8013D2A0 + p[6] * 32, p[7]);
        }
        break;
    case 1:
        if (!(abs(g_Spike_8013D2A0.x - 0x620) < 0x3A0 && abs(g_Spike_8013D2A0.y + 0xA00) < 0x100 && abs(g_Spike_8013D2A0.z + 0xDC0) < 0x1C0)) {
            p[1] = 0;
            Model_BindStageMesh(D_800B4D64_8013D2A0 + p[6] * 32, p[8]);
        }
        break;
    }
    return 0;
}

__asm__(".section .text\n.balign 16");

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D3F0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013D440);

#include "gte.h"
typedef struct { u8 pad0[0x8]; u16 n; u8 padA[2]; s32 rgb[1]; } MdlHdr_422;
typedef struct { MdlHdr_422 *hdr; s32 *f_4; u8 *prims; } Mdl_422;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_422;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;
void Model_DrawPrims(s32, u8 *, s32);

void func_8013D4E0(s32 ot, s32 arg1, Mdl_422 *m, s32 add) {
    s32 i;
    u8 *c;
    s32 *src;
    Scr_422 *sc = (Scr_422 *)0x1F800000;

    c = m->prims;
    if (add == 0) {
        src = m->hdr->rgb;
        for (i = 0; i < m->hdr->n; i++) {
            gte_ldIR(0x1000, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2_mem(&sc->rgb[i]);
        }
    } else {
        src = m->hdr->rgb;
        for (i = 0; i < m->hdr->n; i++) {
            gte_ldIR(0x800, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2(&sc->rgb[i]);
            sc->rgb[i] += add;
        }
    }
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    sc->f_3F4 = 6;
    sc->f_3C0 = D_800EBFA0.f_24;
    sc->f_3C2 = D_800EBFA0.f_28;
    Model_DrawPrims(ot, c, arg1);
}

extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013D63C asm("g_Game");
extern u8 D_800E78C0[];
extern u8 D_800E7D00[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void Matrix_FromDirection(void *, void *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);

s32 func_8013D63C(u8 *a, void *scale, s32 c) {
    SVECTOR v;
    s32 sxy;
    s16 x;
    s16 y;
    s32 p;
    s32 z;

    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    v.vx = M2C_FIELD(a, s32 *, 0x24);
    v.vy = M2C_FIELD(a, s32 *, 0x28);
    v.vz = M2C_FIELD(a, s32 *, 0x2C);
    z = RotTransPers(&v, &sxy, &p, &p);
    x = sxy;
    y = sxy >> 16;
    if (x < -0x80 || x > 0x200 || y < -0x80 || y > 0x1B8 || z > 0x1000 || z <= 0) {
        return 1;
    }
    Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
    ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
    func_80015780(a, 3);
    Model_ProjectBonedVerts(a);
    func_8013D4E0(g_Game_8013D63C.f_80 + g_Game_8013D63C.f_C * 0x4078, D_800E7D00, a, c);
    return 0;
}

typedef struct { s32 x, y, z; u8 pad_C[0x14]; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013D77C;
typedef struct { Shape_8013D77C *shape; s16 x, y, z; } Coll_8013D77C;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D77C asm("g_Spike");
Shape_8013D77C *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

void func_8013D77C(Coll_8013D77C *c, void *owner, s32 a2, s16 a3, s16 a4) {
    s32 dx = g_Spike_8013D77C.x - c->x;
    s32 dz = g_Spike_8013D77C.z - c->z;

    if (dx * dx + dz * dz > 0x24000) {
        c->shape = NULL;
        return;
    }
    c->shape = CollShape_Alloc();
    if (c->shape != NULL) {
        c->shape->x = c->x;
        c->shape->y = c->y;
        c->shape->z = c->z;
        c->shape->f_20 = a2;
        c->shape->f_24 = a3 | 1;
        c->shape->f_26 = a4;
        Collision_Set(7, c->shape, owner);
    }
}


void func_8013D890(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    func_8013D77C(arg0, arg1, arg2, 0, arg3);
}

void func_8013D8BC(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80142368[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80142368");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D8E4(SVECTOR *arg0) {
    s32 i;
    s16 x = arg0->vx;
    s16 y = arg0->vy;
    s16 z = arg0->vz;

    for (i = 0x4F; i >= 0; i--) {
        D_80143F08_8013D554[i].life = (RAND() >> 8 & 0x1F) + 0x28;
        D_80143F08_8013D554[i].x = x + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].y = y - ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].z = z + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].vx = ((RAND() >> 8) - 0x80) / 2;
        D_80143F08_8013D554[i].vy = -(RAND() >> 8 & 0x3F) - 0x20;
        D_80143F08_8013D554[i].vz = ((RAND() >> 8) - 0x80) / 2;
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013DA4C);

void func_8013DE1C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DE44(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DE6C(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DE94(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

void func_8013DF28(void) {
    D_80142728 = -1;
}

void func_8013DF38(s32 arg0) {
    D_80142728 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013DF60(void *obj) {
    if (D_80142728 != -1) {
        Sound_Stop(obj, D_80142728);
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x14]; s16 f60, f62, f64; u8 pad66[0x16]; s32 f7C; u8 pad80[4]; u8 f84; u8 pad85; u8 f86, f87; u8 pad88[8]; u8 f90; u8 pad91; u8 f92, f93; } Obj_8013DF90;
extern Obj_8013DF90 D_80142260_8013DF90[] asm("D_80142260");
extern struct { u8 f0; u8 pad1[0xF]; s32 f10; u8 pad14[8]; u8 f1C, f1D, pad1E, f1F; } D_80141880_8013DF90 asm("D_80141880");
extern Obj_8013DF90 D_801422F8;
extern u8 D_800AF840;
extern s16 D_800E69BE;
s32 SaveByte_Get(s32);
void func_8013EF0C(void *arg0, s32 anim);
void func_8013EF00(s8 arg0);
void func_8013F544(void);
void func_8013E14C(void);
void func_8013EC5C(void);
void func_8013D8BC(void);
void func_8013DF28(void);

void func_8013DF90(void) {
    Obj_8013DF90 *o;
    s32 i;

    if (SaveByte_Get(8) == 5) {
        D_800AF840 = 1;
        return;
    }
    D_800E69BE = 0;
    i = 0;
    o = D_80142260_8013DF90;
    for (; i < 1; i++, o++) {
        func_8013D440(i, (M2C_UNK *)o, (u8 *)o + 0x74);
        o->f87 = 5;
        o->f86 = 5;
        o->f84 = 1;
        o->x = 0x600;
        o->y = -0xA00;
        o->z = -0x1B40;
        o->f60 = 0;
        o->f62 = 0;
        o->f64 = 0x1000;
        func_8013EF0C(o, 0);
        o->f7C = 0;
        o->f90 = 0;
        o->f93 = 0;
        o->f92 = 0;
        Collision_Set(5, &o->x, o);
        o->f48 = 1;
        o->f4A = -0x3E00;
        o->f44 = 0x1C2;
        o->f46 = 0x168;
    }
    D_80141880_8013DF90.f0 = 1;
    func_8013EF00(0);
    D_80141880_8013DF90.f10 = 0;
    D_80141880_8013DF90.f1C = 0;
    D_80141880_8013DF90.f1D = 0;
    D_80141880_8013DF90.f1F = 0;
    Collision_Set(5, &D_801422F8.x, &D_801422F8);
    D_801422F8.f4A = 0x4000;
    D_801422F8.f44 = 0x50;
    D_801422F8.f48 = 0;
    D_801422F8.f46 = 0x80;
    func_8013F544();
    func_8013E14C();
    func_8013EC5C();
    func_8013D8BC();
    func_8013DF28();
}

void func_8013E14C(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 7;
    var_s1 = &D_80141D20;
    var_s0 = (void *)((u8 *)&D_80141D20 + 0x7C);
    do {
        func_8013D440(2, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 -= 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x94));
        var_s1 = (void *)((u8 *)var_s1 + (0x94));
    } while (var_s2 >= 0);
}

void func_8013E1AC(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_80141D20;
    do {
        M2C_FIELD(var_v0, s8 *, 0x84) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x94));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E1D0);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013E2BC);

void func_8013EC5C(void) {
    func_8013D440(3, &D_801421C0, (void *)((u8 *)&D_801421C0 + 0x70));
    M2C_FIELD(&D_801421C0, s8 *, 0x78) = 0;
}

extern struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x48]; u8 f_78; u8 pad79; s16 f_7A; } D_801421C0_8013EC94 asm("D_801421C0");

void func_8013EC94(s16 x, s16 y, s16 z) {
    D_801421C0_8013EC94.f_78 = 0x14;
    D_801421C0_8013EC94.x = x;
    D_801421C0_8013EC94.y = y;
    D_801421C0_8013EC94.z = z;
    D_801421C0_8013EC94.f_7A = -0x5A;
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013ECD4);

void func_8013EE74(void) {
    func_8013EF00(1);
    func_8013EF0C(&D_80142260, 0);
    D_80141880.f_14 = 0x1E;
    D_80141880.f_10 = 0;
}

M2C_UNK Sound_PlayFixed(M2C_UNK);

void func_8013EEB8(void) {
    M2C_FIELD(&D_80141880, s8 *, 0) = 0;
    func_8013EE74();
    M2C_FIELD(&D_80141880, s32 *, 0x18) = 0;
    M2C_FIELD(&D_80141880, s32 *, 0x14) = 0x5A;
    func_8013DF38(0xB1);
    Sound_PlayFixed(4);
}

extern s8 D_80141881;

void func_8013EF00(s8 arg0) {
    D_80141881 = arg0;
}

void func_8013EF0C(void *arg0, s32 anim) {
    if (M2C_FIELD(arg0, u16 *, 0x78) != anim) {
        M2C_FIELD(arg0, u16 *, 0x78) = anim;
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(anim * 4 + M2C_FIELD(arg0, u8 **, 0x74));
        M2C_FIELD(arg0, u8 *, 0x7A) = 1;
        M2C_FIELD(arg0, u8 *, 0x7B) = 0;
    }
}

void func_8013EF44(void *arg0) {
    u16 temp_a0;
    u16 temp_v1;
    void *temp_a2;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x5C) + 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = temp_v1;
    if ((temp_v1 & 0xFFFF) == M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74)), u16 *, 2)) {
        M2C_FIELD(arg0, s8 *, 0x7A) = 0;
    }
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x5C);
    temp_a2 = (M2C_FIELD(arg0, u16 *, 0x78) * 4) + M2C_FIELD(arg0, s32 *, 0x74);
    if ((u16) M2C_FIELD(temp_a2, u16 *, 2) < temp_a0) {
        if (M2C_FIELD(arg0, u8 *, 0x7B) == 1) {
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (temp_a0 - 1);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(temp_a2, u16 *, 0);
    }
}

extern struct { s32 f_0; } g_Game_8013EFCC asm("g_Game");
extern u32 D_80141870;
extern u8 D_80141860[];

void func_8013EFCC(u8 *a) {
    s32 c;
    s32 t;

    if (M2C_FIELD(a, s8 *, 0x90) != 0) {
        M2C_FIELD(a, s32 *, 0x2C) -= M2C_FIELD(a, s8 *, 0x90);
        a[0x90] += a[0x91];
        a[0x91] += 8;
        if (M2C_FIELD(a, s8 *, 0x90) > 0) {
            a[0x90] = 0;
        }
    }
    c = 0;
    if (a[0x86] == 0) {
        t = (g_Game_8013EFCC.f_0 & 1) * 0xF0;
        c = t | 0x10000;
    } else if (a[0x86] == 2) {
        t = D_80141870 & 0xF;
        if (t >= 8) {
            t = 0xF - t;
        }
        c = (t << 4) | 0x10000;
    } else if (a[0x86] < 2) {
        t = D_80141870 & 7;
        if (t >= 4) {
            t = 7 - t;
        }
        c = (t << 5) | 0x10000;
    }
    func_8013D63C(a, D_80141860, c);
    D_80141870 = (D_80141870 + 1) & 0xFF;
}

void func_8013F0E0(void) {
    if (D_80141880.f_2 != 0) {
        D_80141880.f_2 = (u16) (D_80141880.f_2 - 1);
        g_Spike.f_30 = (s32) D_80141880.f_4;
        g_Spike.f_38 = (s32) D_80141880.f_8;
        if (g_Spike.f_2C >= -0xC3F) {
            g_Spike.f_2C = -0xC40;
        }
        if (g_Spike.f_2C < -0x1FA4) {
            g_Spike.f_2C = -0x1FB8;
        }
        D_80141880.f_4 = (s16) ((s32) (D_80141880.f_4 * 7) / 8);
        D_80141880.f_8 = (s16) ((s32) (D_80141880.f_8 * 7) / 8);
        Effect_Spawn(0xCE, &D_800B4D88, &D_80141640, 0);
    }
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F1AC);

void func_8013F544(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    var_s1 = &D_801418A0;
    var_s0 = (void *)((u8 *)&D_801418A0 + 0x7C);
    do {
        func_8013D440(1, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x90));
        var_s1 = (void *)((u8 *)var_s1 + (0x90));
    } while (var_s2 < 8);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F5A8);

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013F6F8);

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_414;
typedef struct { P_TAG_414 tag; u32 rgbc; u32 xy; u32 wh; } TILE_414;
typedef struct { P_TAG_414 tag; u32 code; } DR_MODE_414;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_414;
struct Game_414 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_414 db[2]; };

void func_8013F954(s32 c)
{
  TILE_414 *p = (TILE_414 *) ((struct Game_414 *)&g_Game)->prim;
  u32 *ot = ((struct Game_414 *)&g_Game)->db[((struct Game_414 *)&g_Game)->cur].ot;
  DR_MODE_414 *m;
  p->tag.len = 3;
  p->rgbc = c | 0x62000000;
  p->xy = 0;
  p->wh = 0xF00180;
  p->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) p;
  p = (TILE_414 *) (p - -1);
  m = (DR_MODE_414 *) p;
  m->tag.len = 1;
  m->code = 0xE1000220;
  m->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) m;
  ((struct Game_414 *)&g_Game)->prim = (u8 *) (m + 1);
}

INCLUDE_ASM("asm/ovl/416/nonmatchings/416_monkey_madness_b", func_8013FA2C);
