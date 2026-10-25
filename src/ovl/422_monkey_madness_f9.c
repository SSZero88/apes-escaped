#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern s16 g_SpikeHealth;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; } g_Game;

extern struct S_D_80144C18 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80144C18[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct S_D_80144FD8 { u8 pad_0[0x6]; s8 f_6; u8 pad_7[0x9]; } D_80144FD8[];
extern M2C_UNK D_801451D8;
extern s8 D_801452D8;
extern M2C_UNK D_801452E0;
extern M2C_UNK D_80145390;
extern s16 D_80144C0C;
extern u16 g_RandSeed;
extern struct S_D_80144BE8 { u8 pad_0[0xC]; s8 f_C; u8 pad_D[0x3]; s16 f_10; } D_80144BE8;
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_80070284(s16 *, M2C_UNK *, M2C_UNK, M2C_UNK, s32);
extern M2C_UNK D_801441B8;
extern struct S_D_80145430 { u8 pad_0[0x9]; s8 f_9; u8 pad_A[0x2]; } D_80145430[];

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D000);

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

s32 func_8013D1FC(u8 *a, void *scale, s32 c) {
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
    func_8013D0A0(g_Game_8013D63C.f_80 + g_Game_8013D63C.f_C * 0x4078, D_800E7D00, a, c);
    return 0;
}

typedef struct { s32 x, y, z; u8 pad_C[0x14]; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013D3EC;
typedef struct { Shape_8013D3EC *shape; s16 x, y, z; } Coll_8013D3EC;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D3EC asm("g_Spike");
Shape_8013D3EC *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

void func_8013D33C(Coll_8013D3EC *c, void *owner, s32 a2, s16 a3, s16 a4) {
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


void func_8013D450(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    func_8013D33C(arg0, arg1, arg2, 0, arg3);
}

void func_8013D47C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80144C18[i].f_A = 0;
    }
}

extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80144C18");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D4A4(SVECTOR *arg0) {
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

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013D60C);

void func_8013D9DC(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DA04(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DA2C(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DA54(s32 arg0) {
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

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013DAE8);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013DD44);

void func_8013E070(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_80144FD8[i].f_6 = 0;
    }
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E098);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E22C);

void func_8013E4A8(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0xF;
    var_v0 = &D_801451D8;
    do {
        M2C_FIELD(var_v0, s8 *, 0xC) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x10));
    } while (var_v1 >= 0);
    D_801452D8 = 0;
}

typedef struct { SVECTOR pos; s32 f_8; u8 f_C, f_D; s16 f_E; } Chip_422;
extern Chip_422 D_801451D8_8013E4D0[16] asm("D_801451D8");
extern u8 D_801452D8_8013E4D0 asm("D_801452D8");

void func_8013E4D0(SVECTOR *pos, s32 b) {
    Chip_422 *e = &D_801451D8_8013E4D0[D_801452D8_8013E4D0];

    e->f_C = 7;
    e->f_D = 1;
    e->pos = *pos;
    e->f_8 = b;
    e->f_E = (RAND() >> 4) & 0xFF0;
    D_801452D8_8013E4D0 = (D_801452D8_8013E4D0 + 1) % 16;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E564);

void func_8013E7F8(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_801452E0;
    do {
        M2C_FIELD(var_v0, s8 *, 0x14) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x2C));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad_0[0x14]; u8 f_14; u8 f_15; u8 pad_16[2]; s16 f_18; u8 pad_1A[2]; u8 *f_1C; u8 *f_20; u8 pad_24[8]; } Ent_8013E81C;
extern Ent_8013E81C D_801452E0_8013E81C[4] asm("D_801452E0");
extern struct { u8 pad_0[0xF]; u8 f_F; } D_80144BE8_8013E81C asm("D_80144BE8");
void func_8013E098(u8 *);

void func_8013E81C(u8 *a0, s32 a1) {
    s32 i;
    Ent_8013E81C *e;

    i = 3;
    e = D_801452E0_8013E81C;
    do {
        if (e->f_14 == 0) {
            e->f_14 = 1;
            e->f_15 = a1;
            e->f_18 = 0x40;
            e->f_1C = a0 + 0x74;
            e->f_20 = a0 + 0x7C;
            func_8013E098(a0 + 0x7C);
            if (D_80144BE8_8013E81C.f_F != 1 || e->f_15 != 0) {
                Sound_PlayFixed(0x92);
            }
            return;
        }
        i--;
        e++;
    } while (i >= 0);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013E8D4);

void func_8013F080(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 7;
    var_v0 = &D_80145390;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x14));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F0A4);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F198);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F598);

void func_8013F75C(void *arg0, s32 anim) {
    if (M2C_FIELD(arg0, u16 *, 0x90) != anim) {
        M2C_FIELD(arg0, u16 *, 0x90) = anim;
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(anim * 4 + M2C_FIELD(arg0, u8 **, 0x8C));
    }
}

extern u16 g_RandSeed_8013F78C asm("g_RandSeed");
extern u8 D_80144068[];
void Fx_SpawnFadeRing(void *, s16, s32, u8);
void Effect_SpawnAt(s32, void *);
#define RAND_8013F78C() (g_RandSeed_8013F78C = g_RandSeed_8013F78C * 5 + 1)

void func_8013F78C(u8 *e, s16 a1, s16 a2, s16 a3) {
    SVECTOR v;

    M2C_FIELD(e, s16 *, 0x90) = a1;
    M2C_FIELD(e, s16 *, 0x92) = a2;
    M2C_FIELD(e, s16 *, 0x94) = a3;
    M2C_FIELD(e, u8 *, 0x8C) = 2;
    M2C_FIELD(e, s16 *, 0x96) = 0;
    Fx_SpawnFadeRing(e + 0x74, 0, 0x300, 0);
    v.vx = (RAND_8013F78C() >> 4) & 0xFF0;
    v.vy = (RAND_8013F78C() >> 4) & 0xFF0;
    v.vz = (RAND_8013F78C() >> 4) & 0xFF0;
    func_80070284(e + 0x74, D_80144068, 1, 0, &v);
    Effect_SpawnAt(0x109, e + 0x74);
}

typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x5C]; u8 f_8C[4]; u8 pad90[2]; u8 f_92; u8 pad93[7]; s16 f_9A; s16 f_9C; u8 pad9E[2]; } Ent_8013F86C;
extern Ent_8013F86C D_80144AA8_8013F86C[2] asm("D_80144AA8");
void func_8013D000(s32, void *, void *);

void func_8013F86C(void) {
    s32 i;
    Ent_8013F86C *e;
    s16 x;

    for (i = 0, e = D_80144AA8_8013F86C; i < 2; i++, e++) {
        func_8013D000(8, e, e->f_8C);
        func_8013F75C(e, 0);
        x = i * 0x41C - 0x20E;
        e->f_9A = x;
        e->f_92 = 0;
        e->f_24 = x;
        e->f_28 = -0x3200;
        e->f_2C = 0xBD2;
        e->f_9C = 0;
    }
}

typedef struct { u8 pad0[0x92]; u8 f_92; u8 pad93[9]; s16 f_9C; u8 pad9E[2]; } Ent_422b;
extern Ent_422b D_80144AA8[2];

void func_8013F930(void) {
    s32 i;
    Ent_422b *p;

    for (i = 0, p = D_80144AA8; i < 2; i++, p++) {
        p->f_92 = 1;
        p->f_9C = 0;
    }
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F964);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013F9FC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8013FAA4);

typedef struct { s16 x, y, w, h; } RECT16_80140498;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80140498;
void SetDrawMove(void *, RECT16_80140498 *, s32, s32);

void func_80140498(long row)
{
  u32 *ot;
  RECT16_80140498 r;
  u8 *p;
 do { } while (0);
  p = (*((GameDraw *) (&g_Game))).prim;
  r.x = 0x200;
  if ((!row) && (!row))
  {
  }
  r.y = row + 0xBE;
  r.w = 0x10;
  r.h = 1;
  ot = &(*((GameDraw *) (&g_Game))).db[(*((GameDraw *) (&g_Game))).cur].ot[0xFFF];
  SetDrawMove(p, &r, 0x200, 0xBD);
  ((Tag_80140498 *) p)->addr = ((Tag_80140498 *) ot)->addr;
  ((Tag_80140498 *) ot)->addr = (u32) p;
  p += 0x18;
  (*((GameDraw *) (&g_Game))).prim = p;
}

typedef struct { s16 x, y, w, h; } RECT16_80140564;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80140564;

void func_80140564(s32 row)
{
  u32 *ot;
  RECT16_80140564 r;
  u8 *p;
 do { p = (*((GameDraw *) (&g_Game))).prim; r.x = 0x200; r.y = row + 0xC2; r.w = 0x10; r.h = 1; ot = &(*((GameDraw *) (&g_Game))).db[(*((GameDraw *) (&g_Game))).cur].ot[0xFFF]; SetDrawMove(p, &r, 0x200, 0xC1); ((Tag_80140564 *) p)->addr = ((Tag_80140564 *) ot)->addr; ((Tag_80140564 *) ot)->addr = (u32) p; p += 0x18; (*((GameDraw *) (&g_Game))).prim = p; } while (0);
}

void func_80140630(s16 arg0) {
    D_80144C0C = arg0;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_8014063C);

extern struct { u16 cur; u8 pad2[2]; u16 f_4; u8 f_6; u8 f_7; u8 *tbl; } D_80144BE8_801406F8 asm("D_80144BE8");

void func_801406F8(s32 anim) {
    if (D_80144BE8_801406F8.cur != anim) {
        D_80144BE8_801406F8.cur = anim;
        D_80144BE8_801406F8.f_4 = *(u16 *)(anim * 4 + D_80144BE8_801406F8.tbl);
        D_80144BE8_801406F8.f_6 = 1;
        D_80144BE8_801406F8.f_7 = 0;
    }
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140738);

typedef struct { u8 pad0[0x8C]; u8 f_8C; u8 pad8D[0xB]; } Ent_422c;
extern Ent_422c D_80144460[];
extern struct { u8 pad0[0x17]; u8 f_17; Ent_422c *f_18; } D_80144BE8_801407B4 asm("D_80144BE8");

void func_801407B4(s32 n) {
    if (D_80144460[n + 3].f_8C != 1) {
        n ^= 1;
    }
    D_80144BE8_801407B4.f_17 = n;
    D_80144BE8_801407B4.f_18 = &D_80144460[n + 3];
}

extern u8 D_80143F00[];
void Effect_Spawn(s32, SVECTOR *, void *, s32);

void func_8014081C(void) {
    SVECTOR v = { 0x80, -0x3300, 0xFB8 };
    s32 i;

    for (i = 0; i < 20; i++) {
        Effect_Spawn(0xCA, &v, D_80143F00, 0);
    }
    Camera_StartShake(1);
    Sound_PlayFixed(0x28);
    Sound_PlayFixed(0x80);
}

void func_801408AC(s32 arg0, s32 arg1) {
    u16 temp_v1;

    D_80144BE8.f_C = 0;
    func_801406F8(0);
    temp_v1 = (g_RandSeed * 5) + 1;
    D_80144BE8.f_10 = (s16) (arg0 + ((s32) (((u32) (temp_v1 & 0xFFFF) >> 8) * arg1) >> 8));
    g_RandSeed = temp_v1;
}

extern u8 D_80144BF4;
extern u8 D_80143F18[];

void func_8014092C(void) {
    SVECTOR v;
    u8 *m = D_80144460;

    D_80144BF4 = 2;
    func_801406F8(1);
    func_8014081C();
    v.vy = -0x3300;
    v.vx = 0;
    v.vz = 0xEB8;
    func_80070284(&v, D_80143F18, 1, 0, m + 0x60);
    Sound_PlayFixed(0x81);
    Sound_PlayFixed(0x82);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801409AC);

extern struct { u8 pad0[0xC]; u8 f_C; u8 padD; u8 f_E; u8 padF; s16 f_10; } D_80144BE8_80140A20 asm("D_80144BE8");

void func_80140A20(void) {
    func_8014092C();
    D_80144BE8_80140A20.f_C = 1;
    D_80144BE8_80140A20.f_10 = 0;
    D_80144BE8_80140A20.f_E = 0;
    func_80140630(0x32);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80140A60);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80141F70);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801420BC);

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_414;
typedef struct { P_TAG_414 tag; u32 rgbc; u32 xy; u32 wh; } TILE_414;
typedef struct { P_TAG_414 tag; u32 code; } DR_MODE_414;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_414;
struct Game_414 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_414 db[2]; };

void func_80142310(s32 c)
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

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801423E8);

s32 func_801424A0(s16 x, s32 a)
{
  s16 y = a - 0x1000;
  if ((x > 0) && (y > (-x)))
  {
    return 2;
  }
  if ((x < 0) && (x < y))
  {
    return 1;
  }
  return 0;
}

typedef struct { u8 pad0[8]; u8 f_8; u8 pad9[3]; } Ent_422;

void func_80142508(s32 i, u8 v) {
    Ent_422 *e = &D_80145430[i];

    e->f_8 = v;
}

void func_80142528(s16 *arg0) {
    s16 temp_v1;
    s32 var_s0;

    temp_v1 = *arg0;
    var_s0 = 0;
    if (temp_v1 < -0x3E8) {
        var_s0 = 1;
    } else if (temp_v1 >= 0x3E9) {
        var_s0 = 2;
    }
    func_80142508(var_s0, 2);
    D_80145430[var_s0].f_9 = 0x32;
    func_80070284(arg0, &D_801441B8, 1, 0, 0);
    func_8013D4A4(arg0);
    Camera_StartShake(2);
    Sound_PlayFixed(0x80);
    Sound_PlayFixed(0x6C);
    Sound_PlayFixed(0x60);
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801425EC);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_801428A4);

typedef struct { u8 pad0[4]; s16 x, y, z; u8 f_A; u8 padB; s16 vx, vy, vz; s16 f_12; s16 f_14, f_16, f_18; s16 f_1A; s16 f_1C, f_1E, f_20; u8 pad22[2]; s16 f_24, f_26, f_28; u8 pad2A[2]; } Deb_80142924;
extern Deb_80142924 D_80145458[];

void func_80142924(s32 i) {
    Deb_80142924 *e = &D_80145458[i];

    e->f_A = 1;
    e->f_14 = 0;
    e->f_16 = 0;
    e->f_18 = 0;
    e->vx = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x3F) - 0x20;
    e->vy = -((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x3F) - 0x1A;
    e->vz = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x3F) - 0x20;
    e->x = e->f_24;
    e->y = e->f_26;
    e->z = e->f_28;
    e->f_1C = (g_RandSeed = g_RandSeed * 5 + 1) >> 9;
    e->f_1E = (g_RandSeed = g_RandSeed * 5 + 1) >> 9;
    e->f_20 = (g_RandSeed = g_RandSeed * 5 + 1) >> 9;
}

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142A48);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80142C40);

INCLUDE_ASM("asm/ovl/422/nonmatchings/422_monkey_madness_f9", func_80143854);
