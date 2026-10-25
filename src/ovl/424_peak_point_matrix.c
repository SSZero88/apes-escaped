#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; } g_Game;

extern struct S_D_801423D8 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_801423D8[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142798;
s32 Sound_Play(M2C_UNK, s32);
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80141F88;
extern M2C_UNK D_801427A0;
extern M2C_UNK D_801427C0;
extern s8 D_80142320;
extern M2C_UNK D_80142940;
extern struct S_D_801429C0 { u8 pad_0[0xB]; s8 f_B; } D_801429C0[];
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Effect_SpawnAt(M2C_UNK, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8013D000(M2C_UNK, M2C_UNK *, void *);
void func_8013FFFC(void);
extern s8 D_80142322;
extern M2C_UNK D_80142338;
M2C_UNK Puff_Spawn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8013DFB0(s32 arg0);
M2C_UNK func_8013EEC0(void *, M2C_UNK);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D000);

#include "gte.h"
typedef struct { u8 pad0[0x8]; u16 n; u8 padA[2]; s32 rgb[1]; } MdlHdr_422;
typedef struct { MdlHdr_422 *hdr; s32 *f_4; u8 *prims; } Mdl_422;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_422;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;
void Model_DrawPrims(s32, u8 *, s32);

void func_8013D0A0(s32 ot, s32 arg1, Mdl_422 *m, s32 add) {
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

typedef struct { s32 x, y, z; u8 pad_C[0x14]; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013D3EC;
typedef struct { Shape_8013D3EC *shape; s16 x, y, z; } Coll_8013D3EC;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D3EC asm("g_Spike");
Shape_8013D3EC *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

void func_8013D1FC(Coll_8013D3EC *c, void *owner, s32 a2, s16 a3, s16 a4) {
    s32 dx = g_Spike_8013D3EC.x - c->x;
    s32 dz = g_Spike_8013D3EC.z - c->z;

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


void func_8013D310(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    func_8013D1FC(arg0, arg1, arg2, 0, arg3);
}

void func_8013D33C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_801423D8[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_801423D8");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D364(SVECTOR *arg0) {
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

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013D4CC);

void func_8013D89C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D8C4(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D8EC(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013D914(s32 arg0) {
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

void func_8013D9A8(void) {
    D_80142798 = -1;
}

void func_8013D9B8(s32 arg0) {
    D_80142798 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013D9E0(void *obj) {
    if (D_80142798 != -1) {
        Sound_Stop(obj, D_80142798);
    }
}

extern s16 D_800E69BE;
extern u8 D_800AF840;
extern struct { u8 pad0[8]; s16 x; s16 y; s16 z; } D_80141CC0_8013DA10 asm("D_80141CC0");
extern struct { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[4]; u8 f_8; u8 pad9[5]; s16 f_E; } D_80142320_8013DA10 asm("D_80142320");
s32 SaveByte_Get(s32);
void func_8013F3A4(void *arg0, s32 anim);
void func_8013F398(s8 arg0);
void func_8013E020(void);
void func_8013D33C(void);
void func_801407BC(void);
void func_8013D9A8(void);
void func_8013EE9C(void);

void func_8013DA10(void) {
    s32 i;
    u8 *e;

    D_800E69BE = 0;
    if (SaveByte_Get(0xC) == 5) {
        D_800AF840 = 1;
        return;
    }
    for (i = 0, e = (u8 *)&D_80142338; i < 1; i++, e += 0xA0) {
        func_8013D000(i, (M2C_UNK *)e, e + 0x74);
        M2C_FIELD(e, s32 *, 0x24) = D_80141CC0_8013DA10.x;
        M2C_FIELD(e, s32 *, 0x28) = D_80141CC0_8013DA10.y;
        M2C_FIELD(e, s32 *, 0x2C) = D_80141CC0_8013DA10.z;
        M2C_FIELD(e, u8 *, 0x88) = 1;
        M2C_FIELD(e, s16 *, 0x86) = 0;
        M2C_FIELD(e, u8 *, 0x7E) = 4;
        M2C_FIELD(e, u8 *, 0x7C) = 1;
        M2C_FIELD(e, u8 *, 0x89) = 2;
        M2C_FIELD(e, s16 *, 0x8A) = 0x5A;
        M2C_FIELD(e, s16 *, 0x60) = 0;
        M2C_FIELD(e, s16 *, 0x62) = 0;
        M2C_FIELD(e, s16 *, 0x64) = 0x1000;
        func_8013F3A4(e, 0);
        Collision_Set(5, e + 0x24, e);
        M2C_FIELD(e, s16 *, 0x48) = 1;
        M2C_FIELD(e, s16 *, 0x4A) = -0x3E00;
        M2C_FIELD(e, s16 *, 0x44) = 0xB4;
        M2C_FIELD(e, s16 *, 0x46) = 0x320;
    }
    func_8013F398(1);
    func_8013E020();
    func_8013D33C();
    func_801407BC();
    func_8013D9A8();
    func_8013EE9C();
    D_80142320_8013DA10.f_0 = 1;
    D_80142320_8013DA10.f_8 = 0;
    D_80142320_8013DA10.f_3 = 1;
    D_80142320_8013DA10.f_E = 0x64;
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013DB94);

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x52]; u8 f_7E; u8 pad7F[7]; s16 f_86; } Mdl_8013DDC4;
extern struct { u8 f_0; u8 f_1; u8 pad2[2]; s32 f_4; } D_80142320_8013DDC4 asm("D_80142320");
extern s32 D_80141D00;
s32 rsin(s32);
void func_8013DB94();

void func_8013DDC4(Mdl_8013DDC4 *m) {
    s32 sc[3];
    s32 y;
    u32 st;
    s32 t;
    s32 flags;
    s32 v;

    st = D_80142320_8013DDC4.f_1;
    y = m->y;
    if (st < 0x14) {
        sc[0] = 0x1CCC;
        sc[1] = 0x1CCC;
        sc[2] = 0x1CCC;
        if (st == 0x13) {
            sc[0] = 0x1800;
            sc[1] = 0x1800;
            sc[2] = 0x1800;
        } else if (st == 2) {
            sc[0] = 0x2000 - (D_80142320_8013DDC4.f_4 << 8);
            sc[1] = (D_80142320_8013DDC4.f_4 << 8) + 0x2000;
            sc[2] = 0x2000 - (D_80142320_8013DDC4.f_4 << 8);
        } else if (st == 4) {
            sc[0] = (D_80142320_8013DDC4.f_4 << 8) + 0x400;
            sc[1] = 0x8000 - (D_80142320_8013DDC4.f_4 << 10);
            sc[2] = (D_80142320_8013DDC4.f_4 << 8) + 0x400;
        } else if (st == 3) {
            t = D_80142320_8013DDC4.f_4;
            if (t >= 8) {
                return;
            }
            sc[0] = 0x2000 - (t << 10);
            sc[2] = 0x2000 - (t << 10);
            sc[1] = (t << 12) + 0x2000;
        }
        m->f_86 = (m->f_86 + 0x44) % 0x1000;
        m->y += rsin(m->f_86) >> 6;
    } else {
        sc[0] = 0x1000;
        sc[1] = 0x1000;
        sc[2] = 0x1000;
    }
    flags = 0;
    if (m->f_7E == 2) {
        v = D_80141D00 & 0xF;
        if (v >= 8) {
            v = 15 - v;
        }
        flags = (v << 4) | 0x10000;
    } else if (m->f_7E < 2) {
        v = D_80141D00 & 7;
        if (v >= 4) {
            v = 7 - v;
        }
        flags = (v << 5) | 0x10000;
    }
    func_8013DB94(m, sc, flags);
    m->y = y;
    D_80141D00 = (D_80141D00 + 1) & 0xFF;
}

void func_8013DFB0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0x10;
    do {
        Effect_Spawn(0xC9, arg0, &D_80141F88, 0);
        Effect_Spawn(0xCA, arg0, &D_80141F88, 0);
        var_s0 -= 1;
    } while (var_s0 > 0);
}

void func_8013E020(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0;
    var_v0 = &D_801427A0;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x1C));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad0[4]; s16 x, y, z; u8 f_A; u8 f_B; SVECTOR f_C; s16 dx, dy, dz; u8 f_1A; u8 pad1B; } Ent_8013E044;
extern Ent_8013E044 D_801427A0_8013E044[1] asm("D_801427A0");
void VectorNormalSS(void *, void *);

void func_8013E044(SVECTOR *pos) {
    s32 i;
    Ent_8013E044 *e;

    i = 0;
    e = D_801427A0_8013E044;
    do {
        if (e->f_A == 0) {
            e->f_A = 1;
            e->f_B = 0;
            e->f_1A = 0;
            e->x = pos->vx;
            e->y = pos->vy;
            e->z = pos->vz;
            e->f_C = *pos;
            e->dx = -0x100 - pos->vx;
            e->dy = -0xA00 - pos->vy;
            e->dz = -0x100 - pos->vz;
            VectorNormalSS(&e->dx, &e->dx);
            return;
        }
        i--;
        e++;
    } while (i >= 0);
}

extern u8 D_80141FB0_8013E120[] asm("D_80141FB0");
extern u8 D_80142004_8013E120[] asm("D_80142004");
extern u8 D_80142338_8013E120[] asm("D_80142338");
extern u32 D_80141F88_8013E120[] asm("D_80141F88");
void func_80070284(void *, s32 *, s32, s32, s32);
void Fx_SpawnFadeRing(void *, s32, s32, s32);
void Fx_DrawFadeRing(void *, s32, s32, s32);

void func_8013E120(void) {
    SVECTOR v;
    Ent_8013E044 *e;
    s32 i;
    s32 j;
    s32 r;

    for (i = 0, e = D_801427A0_8013E044; i >= 0; i--, e++) {
        if (e->f_A == 0) {
            continue;
        }
        switch (e->f_A) {
        case 1:
            e->x += e->dx / 32;
            e->y += e->dy / 32;
            e->z += e->dz / 32;
            v.vx = e->x + e->dx / 16;
            v.vy = e->y + e->dy / 16;
            v.vz = e->z + e->dz / 16;
            for (j = 3; j >= 0; j--) {
                Effect_Spawn(0xC8, (s32)&v, (M2C_UNK *)D_80141F88_8013E120, 0);
            }
            e->f_B++;
            if (e->y >= -0xA00) {
                e->y = -0xA80;
                e->f_A = 2;
                e->f_B = 0x41;
                Fx_SpawnFadeRing(&e->x, 1, 0x400, 0);
                Camera_StartShake(2);
                func_80070284(&e->x, (s32 *)D_80141FB0_8013E120, 1, 0, 0);
                func_8013D364((SVECTOR *)&e->x);
                func_8013DFB0((s32)&e->x);
                Sound_PlayFixed(0xB1);
                func_8013D89C();
            }
            break;
        case 2:
            r = 400;
            if (e->f_B < 20) {
                r = e->f_B * 20;
            }
            Fx_DrawFadeRing(&e->x, r + 0x70, 5, 0x808080);
            Fx_DrawFadeRing(&e->x, r + ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 9), 1, 0x808080);
            func_8013D1FC((Coll_8013D3EC *)e, D_80142338_8013E120, r, 0x400, 0x200);
            if (--e->f_B == 0) {
                e->f_A = 0;
                Effect_SpawnAt(0x112, (s32)&e->x);
            } else if (e->f_B % 16 == 0) {
                for (j = 16; j > 0; j--) {
                    Effect_Spawn(0xCA, (s32)&e->x, (M2C_UNK *)D_80141F88_8013E120, 0);
                }
                func_80070284(&e->x, (s32 *)(D_80142004_8013E120 + e->f_1A * 0x54), 1, 0, 0);
                e->f_1A = 1;
                Sound_PlayFixed(0xB1);
            }
            if ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) == 0) {
                Puff_Spawn(&e->x, 0, 0x101, 0x1000);
            }
            func_8013D8C4();
            break;
        }
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E4B4);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013E8A8);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EA24);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EA9C);

void func_8013EE9C(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0x1F;
    var_v0 = &D_801427C0;
    do {
        M2C_FIELD(var_v0, s8 *, 6) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0xC));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013EEC0);

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013F06C);

void func_8013F370(void) {
    D_80142320 = 0;
    func_8013F398(1);
}

extern s8 D_80142321;

void func_8013F398(s8 arg0) {
    D_80142321 = arg0;
}

void func_8013F3A4(void *arg0, s32 anim) {
    if (M2C_FIELD(arg0, u16 *, 0x78) != anim) {
        M2C_FIELD(arg0, u16 *, 0x78) = anim;
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(anim * 4 + M2C_FIELD(arg0, u8 **, 0x74));
        M2C_FIELD(arg0, u8 *, 0x7A) = 1;
        M2C_FIELD(arg0, u8 *, 0x7B) = 0;
    }
}

void func_8013F3DC(void *arg0) {
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

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_8013F464);

void func_8013FFFC(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_80142940;
    do {
        M2C_FIELD(var_v0, s8 *, 0xB) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x20));
    } while (var_v1 >= 0);
}

typedef struct { s32 f_0; u8 pad4[6]; u8 f_A; u8 f_B; u8 padC[8]; s32 f_14; s32 f_18; s16 f_1C; u8 pad1E[2]; } Rock_80140020;
extern Rock_80140020 D_80142940_80140020[4] asm("D_80142940");
extern u16 g_RandSeed_80140020 asm("g_RandSeed");
#define RAND_80140020() (g_RandSeed_80140020 = g_RandSeed_80140020 * 5 + 1)

s32 func_80140020(void) {
    s32 i;
    Rock_80140020 *e;

    for (i = 3, e = D_80142940_80140020; i >= 0; i--, e++) {
        if (e->f_B == 0) {
            e->f_B = 1;
            e->f_A = 0;
            e->f_18 = (RAND_80140020() >> 4) & 0xFF0;
            e->f_1C = ((RAND_80140020() >> 2) & 0xC0) - 0x60;
            e->f_14 = (RAND_80140020() >> 4) & 0xFF0;
            e->f_0 = 0;
            Sound_PlayFixed(0x8E);
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_801400F4);

void func_80140794(void) {
    Pad_Vibrate(1, 0xAA, 6);
}

void func_801407BC(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_801429C0[i].f_B = 0;
    }
}

typedef struct { s16 x, y, z, h; s8 vx, vy, vz; u8 life; } Pt_801407E4;
extern Pt_801407E4 D_801429C0_801407E4[] asm("D_801429C0");
#define RAND_801407E4() (g_RandSeed = g_RandSeed * 5 + 1)
s32 Floor_GetHeight(s32, s32, s32);

M2C_UNK func_801407E4(SVECTOR *v, s32 n) {
    s32 i;
    s16 x = v->vx;
    s16 y = v->vy;
    s16 z = v->vz;
    s16 h = Floor_GetHeight(v->vx, v->vy, v->vz);

    for (i = 31; i >= 0; i--) {
        if (D_801429C0_801407E4[i].life == 0) {
            D_801429C0_801407E4[i].life = (RAND_801407E4() >> 8 & 0x1F) + 0x28;
            D_801429C0_801407E4[i].h = h;
            D_801429C0_801407E4[i].x = x + ((RAND_801407E4() >> 8) - 0x80) / 2;
            D_801429C0_801407E4[i].y = y - ((RAND_801407E4() >> 8) - 0x80) / 2;
            D_801429C0_801407E4[i].z = z + ((RAND_801407E4() >> 8) - 0x80) / 2;
            D_801429C0_801407E4[i].vx = ((RAND_801407E4() >> 8) - 0x80) / 4;
            D_801429C0_801407E4[i].vy = -(RAND_801407E4() >> 8 & 0x1F) - 0x18;
            D_801429C0_801407E4[i].vz = ((RAND_801407E4() >> 8) - 0x80) / 4;
            if (--n == 0) {
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_801409D4);

void func_80140E70(void) {
    func_8013D000(1, &D_80142338, (void *)((u8 *)&D_80142338 + 0x74));
    M2C_FIELD(&D_80142338, s32 *, 0x28) = -0xA00;
    M2C_FIELD(&D_80142338, s8 *, 0x7E) = 5;
    M2C_FIELD(&D_80142338, s8 *, 0x7C) = 1;
    M2C_FIELD(&D_80142338, s16 *, 0x92) = 0xF;
    M2C_FIELD(&D_80142338, s16 *, 0x8E) = 0x78;
    M2C_FIELD(&D_80142338, s16 *, 0x94) = -0x100;
    M2C_FIELD(&D_80142338, s16 *, 0x98) = -0x100;
    M2C_FIELD(&D_80142338, s16 *, 0x44) = 0x80;
    M2C_FIELD(&D_80142338, s16 *, 0x86) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x90) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x9E) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x9C) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x96) = 0;
    M2C_FIELD(&D_80142338, s16 *, 0x46) = 0x100;
    func_8013FFFC();
    D_80142322 = 0;
}

void func_80140F08(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x8E) = 0x168;
    M2C_FIELD(arg0, s16 *, 0x92) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0x80;
    func_801407E4(arg1, 0x20);
    Effect_SpawnAt(0x112, arg1);
    Sound_PlayFixed(0x92);
    Camera_StartShake(1);
}

void func_80140F68(void *arg0, M2C_UNK arg1) {
    s32 var_s0;

    var_s0 = 3;
    do {
        Puff_Spawn(arg1, 0, 0x101, 0x800);
        var_s0 -= 1;
    } while (var_s0 > 0);
    func_8013DFB0(arg1);
    M2C_FIELD(arg0, s16 *, 0x92) = 0xF;
    M2C_FIELD(arg0, s16 *, 0x8E) = 0x1E;
    func_8013EEC0(arg0, 0);
    Camera_StartShake(1);
    Sound_PlayFixed(0x27);
    Sound_PlayFixed(0x92);
}

INCLUDE_ASM("asm/ovl/424/nonmatchings/424_peak_point_matrix", func_80140FFC);
