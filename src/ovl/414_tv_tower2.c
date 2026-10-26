#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

extern struct S_D_80143F08 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80143F08[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801442C8;
s32 Sound_Play(M2C_UNK, s32);
extern s32 D_801442CC;
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80143718;
extern M2C_UNK D_80144570;
extern M2C_UNK D_80144598;
extern M2C_UNK D_80143AF0;
M2C_UNK Camera_StartShake(M2C_UNK);
extern M2C_UNK D_80143D70;
extern s8 D_80143F04;

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D014);

s32 func_8013D174(void) {
    return M2C_FIELD(g_Game.f_8220, s16 *, 0x1A) >= 4;
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D1A0);

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D1F0 asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D1F0;
extern u8 *D_80143D50[];
extern u8 *D_80143D60[];
void func_80015BA0(void *, void *);

M2C_UNK func_8013D1F0(M2C_UNK i, M2C_UNK *obj, void *out) {
    u8 *bank = g_Game_8013D1F0.f_8244;
    AnimEnt_8013D1F0 *ent;
    u8 *s;
    u32 *q;

    D_80143D50[i] = bank + (ent = (AnimEnt_8013D1F0 *)(i * 32 + (u32)(bank + M2C_FIELD(bank, s32 *, 8))))->f18;
    D_80143D60[i] = s = g_Game_8013D1F0.f_8244 + ent->f1C;
    q = (u32 *)s + 1;
    *(u32 **)out = q;
    M2C_FIELD(obj, u32 **, 0x18) = q + *(u16 *)s;
    func_80015BA0(obj, D_80143D50[i]);
}

#include "gte.h"
typedef struct { u8 pad0[0x8]; u16 n; u8 padA[2]; s32 rgb[1]; } MdlHdr_422;
typedef struct { MdlHdr_422 *hdr; s32 *f_4; u8 *prims; } Mdl_422;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_422;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;
void Model_DrawPrims(s32, u8 *, s32);

void func_8013D290(s32 ot, s32 arg1, Mdl_422 *m, s32 add) {
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

void func_8013D3EC(Coll_8013D3EC *c, void *owner, s32 a2, s16 a3, s16 a4) {
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


void func_8013D500(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    func_8013D3EC(arg0, arg1, arg2, 0, arg3);
}

void func_8013D52C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80143F08[i].f_A = 0;
    }
}

#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80143F08");

void func_8013D554(SVECTOR *arg0) {
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

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D6BC);

void func_8013DA8C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DAB4(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DADC(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DB04(s32 arg0) {
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

void func_8013DB98(void) {
    D_801442C8 = -1;
}

void func_8013DBA8(s32 arg0) {
    D_801442C8 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013DBD0(void *obj) {
    if (D_801442C8 != -1) {
        Sound_Stop(obj, D_801442C8);
    }
}

void func_8013DC00(void) {
    D_801442CC = -1;
}

void func_8013DC10(s32 arg0) {
    D_801442CC = Sound_Play(0, arg0);
}

void func_8013DC38(void *obj) {
    if (D_801442CC != -1) {
        Sound_Stop(obj, D_801442CC);
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x14]; s16 f44, f46, f48, f4A; u8 pad4C[0x14]; s16 f60, f62, f64; u8 pad66[0xB]; u8 f71; u8 pad72[6]; s16 f78; u8 pad7A; u8 f7B; u8 pad7C[0x24]; s32 fA0; s32 fA4; u8 padA8[5]; u8 fAD, fAE, fAF; u8 padB0[2]; s16 fB2; u8 padB4[6]; u8 fBA; u8 padBB; s32 fBC; u8 padC0[4]; } Obj_8013DC68;
extern Obj_8013DC68 D_80143D70_8013DC68[] asm("D_80143D70");
extern struct { u8 pad0[2]; u8 f2, f3; u8 pad4[4]; s16 f8; u8 padA[2]; u8 fC, fD; } D_80143EF8_8013DC68 asm("D_80143EF8");
extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013DC68 asm("g_Game");
extern u8 D_800AF840;
extern s16 D_800E69BE;
s32 SaveByte_Get(s32);
void func_80140948(void *arg0, s32 anim);
void func_8013F68C(void);
void func_8013F130(void);
void func_8013ECF4(void);
void func_8013D52C(void);
void func_8013DB98(void);
void func_8013DC00(void);

void func_8013DC68(void) {
    u8 *hdr;
    s16 *p;
    s16 *tbl;
    Obj_8013DC68 *o;
    s32 i;

    D_80143EF8_8013DC68.fC = 1;
    hdr = g_Game_8013DC68.f_8244;
    if (SaveByte_Get(0) == 5) {
        D_800AF840 = 1;
        return;
    }
    i = 0;
    D_800E69BE = 0;
    D_80143EF8_8013DC68.f3 = 0;
    D_80143EF8_8013DC68.f2 = 0;
    D_80143EF8_8013DC68.f8 = 0;
    D_80143EF8_8013DC68.fD = 0;
    tbl = (s16 *)(g_Game_8013DC68.f_8244 + M2C_FIELD(hdr, s32 *, 8));
    o = D_80143D70_8013DC68;
    for (; i < 2; i++, o++) {
        p = tbl + i * 16;
        func_8013D1F0(i, (M2C_UNK *)o, (u8 *)o + 0x74);
        o->x = p[1];
        o->y = p[2];
        o->z = p[3];
        o->f78 = 0;
        o->fA0 = 0;
        o->fA4 = 0;
        o->fB2 = 0x3C;
        o->fAF = 6;
        o->fBC = 0;
        o->f7B = 0;
        o->fBA = 0;
        o->f60 = 0x1000;
        o->f62 = 0;
        o->f64 = 0;
        if ((u16)p[0] == 0xC8) {
            o->f71 = 0;
            func_80140948(o, 2);
            o->fAD = 0;
            o->fAE = 0;
            Collision_Set(5, &o->x, o);
            o->f48 = 1;
            o->f4A = -0x7EFE;
            o->f44 = 0x4E2;
            o->f46 = 0x300;
        }
    }
    func_8013F68C();
    func_8013F130();
    func_8013ECF4();
    func_8013D52C();
    func_8013DB98();
    func_8013DC00();
}

void func_8013DE24(s32 arg0) {
    s32 var_s0;

    var_s0 = 8;
    do {
        Effect_Spawn(0xCE, arg0, &D_80143718, 0);
        var_s0 -= 1;
    } while (var_s0 > 0);
}

typedef struct { s32 f_0; s16 x; s16 y; s16 z; u8 active; u8 f_B; s16 f_C; s16 f_E; s16 f_10; u8 f_12; u8 pad13; } P_8013DE7C;
extern P_8013DE7C D_801442D0_8013DE7C[] asm("D_801442D0");

void func_8013DE7C(SVECTOR *pos) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_801442D0_8013DE7C[i].active == 0) {
            *(SVECTOR *)&D_801442D0_8013DE7C[i].x = *pos;
            D_801442D0_8013DE7C[i].active = 1;
            D_801442D0_8013DE7C[i].f_B = 0x10;
            D_801442D0_8013DE7C[i].f_12 = 0;
            D_801442D0_8013DE7C[i].f_0 = 0;
            D_801442D0_8013DE7C[i].f_C = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2;
            D_801442D0_8013DE7C[i].f_10 = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2;
            D_801442D0_8013DE7C[i].f_E = ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 0x60;
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013DF68);

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_414;
typedef struct { P_TAG_414 tag; u32 rgbc; u32 xy; u32 wh; } TILE_414;
typedef struct { P_TAG_414 tag; u32 code; } DR_MODE_414;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_414;
struct Game_414 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_414 db[2]; };

void func_8013E464(s32 c)
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

typedef struct { s16 x, y, z; u8 f6, f7; s16 vx, vy, vz; u8 fE, fF; } Bit_8013E53C;
extern Bit_8013E53C D_80144370[32];

void func_8013E53C(SVECTOR *pos, s32 c) {
    s32 i;
    Bit_8013E53C *b;
    s16 d[3];

    i = 31;
    b = D_80144370;
    for (; i >= 0; i--, b++) {
        b->f6 = 0x10;
        b->fF = (u8)c;
        b->fE = (RAND() >> 8) & 1;
        b->f7 = (RAND() >> 8) & 0xF;
        b->x = pos->vx + ((((u16)RAND() >> 8) - 0x80) << 3);
        b->y = pos->vy + ((((u16)RAND() >> 8) - 0x80) << 3);
        b->z = pos->vz - (((u16)RAND() >> 8) << 2);
        d[0] = pos->vx - b->x;
        d[1] = pos->vy - b->y;
        d[2] = pos->vz - b->z;
        b->vx = d[0] / 16;
        b->vy = d[1] / 16;
        b->vz = d[2] / 16;
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013E6E4);

extern struct { s32 frame; u8 pad_4[0x8]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013E9C8 asm("g_Game");
extern u8 D_80143D70_8013E9C8[] asm("D_80143D70");
extern u8 D_800E78C0[];
extern u8 D_800E7D00[];
extern u8 D_800E9EC0[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void *RotMatrixZ(s32 r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Matrix_FromDirection(void *, void *);
void Matrix_RotateY(s32, void *);
void func_8004637C(void *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_8013D290_8013E9C8(s32, s32, void *, s32) asm("func_8013D290");

s32 func_8013E9C8(u8 *a, void *scale, s32 c, s32 spin) {
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
    if (x < -0x80 || x > 0x200 || y < -0x80 || y > 0x170 || z > 0x1000 || z <= 0) {
        return 0;
    }
    if (spin == 0) {
        Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
        ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
        func_80015780(a, 3);
    } else {
        u8 *o = D_80143D70_8013E9C8;

        func_8004637C((void *)0x1F800018);
        RotMatrixZ(M2C_FIELD(o, s32 *, 0xA4), (void *)0x1F800018);
        Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
        CompMatrix(M2C_FIELD(a, void **, 0x14), (void *)0x1F800018, M2C_FIELD(a, void **, 0x14));
        ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
        func_80015780(o, 3);
        Matrix_RotateY(g_Game_8013E9C8.frame * 773, D_800E9EC0);
        Matrix_RotateY(g_Game_8013E9C8.frame * 773, D_800E9EC0 + 0x20);
    }
    Model_ProjectBonedVerts(a);
    func_8013D290_8013E9C8((s32)(g_Game_8013E9C8.f_80 + g_Game_8013E9C8.f_C * 0x4078), (s32)D_800E7D00, a, c);
    return 0;
}

typedef struct { s16 x, y, z, w; } SV_8013EBC8;
typedef struct {
    u8 pad_0[0x24];
    s32 x, y, z;
    u8 pad_30[0x30];
    SV_8013EBC8 rot;
    u8 pad_68[0x47];
    u8 f_AF;
    u8 pad_B0[0xA];
    u8 f_BA;
    u8 pad_BB;
    s32 f_BC;
    u8 pad_C0[4];
} Obj_8013EBC8;
extern Obj_8013EBC8 D_80143D70_EBC8[] asm("D_80143D70");

void func_8013EBC8(void) {
    Obj_8013EBC8 *o = D_80143D70_EBC8;
    Obj_8013EBC8 *b = o + 1;
    s32 v[3];
    s32 c;
    s32 t;

    if (o->f_BA == 0) {
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        c = 0;
        if (o->f_AF == 2) {
            t = o->f_BC & 0xF;
            if (t >= 8) {
                t = 0xF - t;
            }
            c = (t << 4) | 0x10000;
        } else if (o->f_AF < 2) {
            t = o->f_BC & 7;
            if (t >= 4) {
                t = 7 - t;
            }
            c = (t << 5) | 0x10000;
        }
        func_8013E9C8(o, v, c, 1);
        b->y = -0x1080;
        b->x = o->x;
        b->z = o->z;
        b->rot = o->rot;
        v[1] = 0x1000;
        b->rot.y = 0;
        v[2] = v[0] = o->y + 0x1E00;
        func_8013E9C8(b, v, 0, 0);
    }
}

void func_8013ECF4(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 1;
    var_v0 = &D_80144570;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x14));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad_0[4]; s16 x, y, z; u8 active; u8 f_B; s16 vx, vy, vz; u8 pad_12[2]; } Deb_8013ED18;
typedef struct { s16 x, y, z, w; } Vel_8013ED18;
extern Deb_8013ED18 D_80144570_8013ED18[] asm("D_80144570");
extern Vel_8013ED18 D_80143AA4[];
extern struct { u8 pad_0[3]; u8 f_3; s16 f_4; } D_80143EF8;
void Camera_StartShake_8013ED18(s32) asm("Camera_StartShake");
s32 Sound_PlayFixed_8013ED18(s32) asm("Sound_PlayFixed");

void func_8013ED18(s16 *pos) {
    Deb_8013ED18 *d = D_80144570_8013ED18;
    Vel_8013ED18 *v;
    s32 i;

    if (d->active == 0) {
        v = &D_80143AA4[(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 3) >> 8];
        for (i = 1; i >= 0; i--) {
            d->active = 1;
            d->x = pos[0];
            d->y = pos[1];
            d->z = pos[2];
            d->vx = v->x;
            d->vy = v->y;
            d->vz = v->z;
            d->f_B = 0;
            d++;
            v++;
        }
        Camera_StartShake_8013ED18(1);
        Sound_PlayFixed_8013ED18(0x8F);
        Sound_PlayFixed_8013ED18(0x95);
        D_80143EF8.f_4 = -0xBE;
        D_80143EF8.f_3 = 0xF;
    }
}

typedef struct { u8 pad_0[4]; s16 x, y, z; u8 active; u8 f_B; s16 vx, vy, vz; u8 pad_12[2]; } Deb_8013EE1C;
extern Deb_8013EE1C D_80144570_8013EE1C[] asm("D_80144570");
void Sound_PlayFixed_8013EE1C(s32) asm("Sound_PlayFixed");
void func_8006D548(void *);

void func_8013EE1C(void *o) {
    Deb_8013EE1C *d;
    s32 i;
    s32 n;
    s32 played;
    SVECTOR v;

    played = 0;
    for (i = 1, d = D_80144570_8013EE1C; i >= 0; i--, d++) {
        if (d->active == 0) {
            continue;
        }
        d->x += d->vx;
        d->y += d->vy;
        d->z += d->vz;
        switch (d->active) {
        case 1:
            d->vx = d->vx * 31 / 32;
            d->vy += 5;
            if (d->y >= -0x1020) {
                d->y = -0x1020;
                d->vx = 0;
                d->vy = 0;
                d->vz = -0x30 - (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F);
                d->active = 2;
                Sound_PlayFixed_8013EE1C(0x94);
            }
            Effect_Spawn(0xCF, (s32)&d->x, &D_80143718, 0);
            func_8006D548(&d->x);
            break;
        case 2:
            Camera_StartShake(0);
            if (d->z < -0x200) {
                d->active = 0;
            }
            for (n = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) + 1; n >= 0; n--) {
                v.vx = d->x + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) << 2);
                v.vy = d->y;
                v.vz = d->z;
                Effect_Spawn((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) + 0xCF, (s32)&v, &D_80143718, 0);
            }
            if ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) == 0 && played == 0) {
                played = 1;
                Sound_PlayFixed_8013EE1C(0x95);
            }
            d->x -= 0x280;
            func_8013D3EC((void *)d, o, 0x100, 0x200, 0x200);
            d->x += 0x280;
            func_8013D3EC((void *)d, o, 0x100, 0x200, 0x200);
            d->x += 0x280;
            func_8013D3EC((void *)d, o, 0x100, 0x200, 0x200);
            d->x -= 0x280;
            break;
        }
    }
}

void func_8013F130(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    var_s1 = &D_80144598;
    var_s0 = (void *)((u8 *)&D_80144598 + 0x74);
    do {
        func_8013D1F0(3, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 0xC) = 0;
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x84));
        var_s1 = (void *)((u8 *)var_s1 + (0x84));
    } while (var_s2 <= 0);
}

void func_8013F190(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v0 = &D_80144598;
    var_v1 = 0;
    do {
        M2C_FIELD(var_v0, s8 *, 0x80) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x84));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x4A]; s16 f_7A, f_7C, f_7E; u8 f_80, f_81; u8 pad82[2]; } Blast_8013F1B4;
extern Blast_8013F1B4 D_80144598_8013F1B4[1] asm("D_80144598");
void Effect_SpawnAt(s32, SVECTOR *);

void func_8013F1B4(s16 *p) {
    s32 i;
    Blast_8013F1B4 *b;

    for (i = 0, b = D_80144598_8013F1B4; i < 1; i++, b++) {
        if (b->f_80 == 0) {
            b->f_80 = 1;
            b->x = p[0];
            b->y = p[1];
            b->z = p[2];
            b->f_7A = 0;
            b->f_7C = 0;
            b->f_7E = 0;
            b->f_81 = 0;
            Effect_SpawnAt(0x113, (SVECTOR *)p);
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F240);

void func_8013F68C(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 3;
    var_s1 = &D_80143AF0;
    var_s0 = (void *)((u8 *)&D_80143AF0 + 0x7C);
    do {
        func_8013D1F0(2, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 -= 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x98));
        var_s1 = (void *)((u8 *)var_s1 + (0x98));
    } while (var_s2 >= 0);
}

typedef struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x2C]; s16 f_5C; u8 pad_5E[0x12]; s32 f_70; u8 pad_74[0xE]; u8 f_82; u8 f_83; u8 f_84; u8 f_85; u8 f_86; u8 f_87; s16 f_88; s16 f_8A; s16 f_8C; s16 f_8E; s16 f_90; s16 f_92; u8 f_94; u8 pad_95[3]; } Part_8013F6EC;
extern Part_8013F6EC D_80143AF0_F6EC[] asm("D_80143AF0");

void func_8013F6EC(s16 *pos) {
    Part_8013F6EC *o = D_80143AF0_F6EC;
    s32 type = 0;
    s32 i;

    for (i = 0; i < 4; i++, o++) {
        o->f_84 = 1;
        o->f_87 = i * 30;
        o->f_70 = 0;
        o->x = pos[0];
        o->y = pos[1];
        o->z = pos[2];
        o->f_92 = 0;
        o->f_90 = 0;
        o->f_85 = 0;
        o->f_8E = 0;
        o->f_83 = type;
        o->f_94 = 2;
        switch (type) {
        case 0:
            o->f_88 = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) - 0x20;
            o->f_8A = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) - 0x20;
            o->f_8C = -12 - (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF);
            o->f_88 = 0;
            o->f_8A = 0;
            o->f_86 = 0xFF;
            break;
        case 1:
            o->f_86 = 0xF0;
            o->f_82 = 0;
            o->f_88 = 0;
            o->f_8A = 7;
            o->f_8C = -0x18;
            break;
        }
        o->f_5C = 0;
        type = 1;
    }
}

extern u8 D_80143718_8013F838[] asm("D_80143718");
extern u8 D_801438A4[];
void Effect_SpawnAt(s32, SVECTOR *);
void Effect_Spawn_8013F838(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void func_80070284(SVECTOR *, void *, s32, s32, s32);

void func_8013F838(SVECTOR *v) {
    func_8013DE24(v);
    func_8013DE24(v);
    Effect_SpawnAt(0x112, v);
    Effect_Spawn_8013F838(0xD4, v, D_80143718_8013F838, 0);
    Fx_SpawnFadeRing(v, 1, 0x200, 0);
    func_80070284(v, D_801438A4, 1, 0, 0);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F8B8);

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR tgt; } Scr_801402D8;
extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_801402D8 asm("g_Spike");
extern u8 D_80143D70_801402D8[] asm("D_80143D70");
extern u8 D_80144598_801402D8[] asm("D_80144598");
extern struct { u8 pad_0[3]; u8 f_3; s16 f_4; } D_80143EF8_801402D8 asm("D_80143EF8");
extern s8 g_CurrentGadget;
extern u8 D_800E6916;
void func_800495F4(void *, s32);
void func_8004AF78(void *);
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_80047720(s32, s32, s32);
s32 VectorNormalSS_801402D8(SVECTOR *, SVECTOR *) asm("VectorNormalSS");

void func_801402D8(void *o) {
    Scr_801402D8 *sc = (Scr_801402D8 *)0x1F800000;
    u8 *d = D_80143D70_801402D8;
    u8 *p;
    SVECTOR v;
    u8 m;

    if (g_Spike_801402D8.z < -0xA5A) {
        func_800495F4(o, 0);
        return;
    }
    sc->tgt.vx = g_Spike_801402D8.x;
    sc->tgt.vy = g_Spike_801402D8.y - 0x80;
    sc->tgt.vz = g_Spike_801402D8.z;
    sc->eye.vx = (M2C_FIELD(d, s32 *, 0x24) + sc->tgt.vx * 3) / 4;
    sc->eye.vy = -0x1200;
    sc->eye.vz = (M2C_FIELD(d, s32 *, 0x2C) + sc->tgt.vz * 3) / 4;
    v.vx = sc->eye.vx - sc->tgt.vx;
    v.vy = 0;
    v.vz = sc->eye.vz - sc->tgt.vz;
    VectorNormalSS_801402D8(&v, &v);
    sc->at.vx = sc->tgt.vx - v.vx / 4 * 3;
    sc->at.vy = M2C_FIELD(d, u16 *, 0x28) - 0x3E8;
    sc->at.vz = sc->tgt.vz - v.vz / 4 * 3;
    m = d[0x71];
    if (m < 4) {
        sc->at.vx = sc->tgt.vx - v.vx / 2;
        sc->at.vy = M2C_FIELD(d, u16 *, 0x28) - 0x76C;
        sc->at.vz = -(v.vz / 2 + 0x200) + sc->tgt.vz;
    } else if (m == 13 || m == 14) {
        v.vx = -sc->tgt.vx;
        v.vy = 0;
        v.vz = 0x400 - sc->tgt.vz;
        VectorNormalSS_801402D8(&v, &v);
        sc->eye.vx = sc->tgt.vx + (v.vx >> 1);
        sc->eye.vy = sc->tgt.vy - 0xC8;
        sc->eye.vz = sc->tgt.vz + (v.vz >> 1);
        sc->at.vx = sc->tgt.vx - (v.vx >> 1);
        sc->at.vy = sc->tgt.vy - 0x118;
        sc->at.vz = sc->tgt.vz - (v.vz >> 1);
    } else if (m == 10 || m == 11 || m == 12 || m == 15 || m == 16 || m == 21) {
        sc->eye.vy = M2C_FIELD(d, u16 *, 0x28) + 0x640;
        sc->at.vy = sc->tgt.vy;
        sc->at.vx = sc->tgt.vx - v.vx / 3;
        sc->at.vz = sc->tgt.vz - v.vz / 3;
    } else if (m == 20 || m == 22) {
        sc->at.vx = sc->tgt.vx + v.vz / 2;
        sc->at.vz = sc->tgt.vz - v.vx / 2;
        sc->eye.vy = M2C_FIELD(d, u16 *, 0x28);
        sc->at.vy = sc->tgt.vy - 0x17C;
    }
    p = D_80144598_801402D8;
    if (p[0x80] != 0) {
        v.vx = M2C_FIELD(p, u16 *, 0x24) - sc->tgt.vx;
        v.vy = 0;
        v.vz = M2C_FIELD(p, u16 *, 0x2C) - sc->tgt.vz;
        VectorNormalSS_801402D8(&v, &v);
        sc->eye.vx = M2C_FIELD(p, u16 *, 0x24);
        sc->eye.vy = sc->tgt.vy - 0xC8;
        sc->eye.vz = M2C_FIELD(p, u16 *, 0x2C);
        sc->at.vx = sc->tgt.vx - (v.vx >> 1);
        sc->at.vy = sc->tgt.vy - 0x400;
        sc->at.vz = sc->tgt.vz - (v.vz >> 1);
    }
    if (sc->eye.vy > -0x1200) {
        sc->eye.vy = -0x1200;
    }
    if (g_CurrentGadget == 3 && D_800E6916 != 1) {
        func_8004AF78(o);
    }
    func_80047558(o, 0x20, 0x18, 0x20);
    func_80047464(o, 0x18, 0x18, 0x18);
    if (D_80143EF8_801402D8.f_3 != 0) {
        func_80047720(0, 0, D_80143EF8_801402D8.f_4);
        D_80143EF8_801402D8.f_4 += 0x18;
        if (--D_80143EF8_801402D8.f_3 == 0) {
            D_80143EF8_801402D8.f_4 = 0;
        }
    }
}

void func_80140760(void) {
    D_80143F04 = 0;
    func_8014097C(&D_80143D70);
    Camera_StartShake(1);
}

s32 func_80140794(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x88) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x8A) - M2C_FIELD(arg0, s32 *, 0x28);
    temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x8C) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3)) < (arg1 * arg1);
}

void func_801407FC(u8 *a, s32 sx, s32 sy, s32 sz) {
    u8 *m = (u8 *)0x1F800000;

    if (ABS(M2C_FIELD(a, s16 *, 0x88) - M2C_FIELD(a, s32 *, 0x24)) < sx) {
        M2C_FIELD(a, s32 *, 0x24) = M2C_FIELD(a, s16 *, 0x88);
    } else {
        M2C_FIELD(a, s32 *, 0x24) += (M2C_FIELD(m, s16 *, 0x08) * sx) >> 12;
    }
    if (ABS(M2C_FIELD(a, s16 *, 0x8A) - M2C_FIELD(a, s32 *, 0x28)) < sy) {
        M2C_FIELD(a, s32 *, 0x28) = M2C_FIELD(a, s16 *, 0x8A);
    } else {
        M2C_FIELD(a, s32 *, 0x28) += (M2C_FIELD(m, s16 *, 0x12) * sy) >> 12;
    }
    if (ABS(M2C_FIELD(a, s16 *, 0x8C) - M2C_FIELD(a, s32 *, 0x2C)) < sz) {
        M2C_FIELD(a, s32 *, 0x2C) = M2C_FIELD(a, s16 *, 0x8C);
    } else {
        M2C_FIELD(a, s32 *, 0x2C) += (M2C_FIELD(m, s16 *, 0x0C) * sz) >> 12;
    }
}

void func_80140948(void *arg0, s32 anim) {
    if (M2C_FIELD(arg0, u16 *, 0x78) != anim) {
        M2C_FIELD(arg0, u16 *, 0x78) = anim;
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(anim * 4 + M2C_FIELD(arg0, u8 **, 0x74));
        M2C_FIELD(arg0, u8 *, 0xBB) = 1;
    }
}

extern u8 D_80143F05;
void Sound_PlayFixed(s32);

void func_8014097C(u8 *a) {
    a[0x71] = 8;
    M2C_FIELD(a, s16 *, 0x8A) = -0x1480;
    M2C_FIELD(a, s16 *, 0x8C) = 0x978;
    M2C_FIELD(a, s16 *, 0x88) = 0;
    *(SVECTOR *)(a + 0x90) = *(SVECTOR *)(a + 0x88);
    M2C_FIELD(a, s32 *, 0x7C) = 0x400;
    M2C_FIELD(a, s32 *, 0x84) = 0x578;
    M2C_FIELD(a, s16 *, 0xB2) = 0x28;
    M2C_FIELD(a, s32 *, 0xBC) = 0;
    M2C_FIELD(a, s16 *, 0xB6) = -0x3C;
    M2C_FIELD(a, u16 *, 0x92) = M2C_FIELD(a, u16 *, 0x28);
    func_80140948(a, 5);
    Sound_PlayFixed(0x8C);
    func_8013DC10(0xBB);
    D_80143F05 = 0;
}

void Sound_PlayFixed(s32);

void func_80140A18(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x71) = 0xF;
    M2C_FIELD(arg0, s16 *, 0x8A) = -0x1800;
    M2C_FIELD(arg0, s16 *, 0x8C) = 0x1400;
    M2C_FIELD(arg0, s16 *, 0x88) = 0;
    M2C_FIELD(arg0, SVECTOR *, 0x90) = M2C_FIELD(arg0, SVECTOR *, 0x88);
    M2C_FIELD(arg0, u8 *, 0x73) = 1;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0;
    func_80140948(arg0, 9);
    Sound_PlayFixed(0x8C);
    Sound_PlayFixed(0x4D);
}

extern u8 D_80143850[];
void func_8013DE24(s32 arg0);

void func_80140A90(u8 *arg0) {
    SVECTOR dir = { M2C_FIELD(arg0, s16 *, 0x60), 0, M2C_FIELD(arg0, s16 *, 0x64) };
    SVECTOR pos = { M2C_FIELD(arg0, s16 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x60) / 4, M2C_FIELD(arg0, s16 *, 0x28) - 0xA0, M2C_FIELD(arg0, s16 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x64) / 4 };

    if (M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
        pos.vy += M2C_FIELD(arg0, s32 *, 0xA0);
    }
    func_80070284(&pos, D_80143850, 1, 0, (s32)&dir);
    func_8013DE24((s32)&pos);
    func_8013DE24((s32)&pos);
    Sound_PlayFixed(0x27);
    Sound_PlayFixed(0x28);
}

extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[8]; s32 f_38; } g_Spike_80140BF0 asm("g_Spike");
extern struct { s16 f_0; u8 f_2; } D_80143EF8_80140BF0 asm("D_80143EF8");
void Effect_Spawn_80140BF0(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");

void func_80140BF0(u8 *arg0, s32 n, s32 burst) {
    SVECTOR v;
    s32 off;
    u16 r;
    s32 dy;

    if (n >= 4) {
        n = 3;
    }
    if (burst != 0) {
        for (off = -0x400; off <= 0x400; off += 0x800) {
            v.vx = M2C_FIELD(arg0, u16 *, 0x24) + off + (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 3;
            r = g_RandSeed * 5 + 1;
            dy = (r >> 8) * 2 + 0x100;
            v.vy = M2C_FIELD(arg0, u16 *, 0x28) - dy;
            v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
            g_RandSeed = r;
            Effect_Spawn_80140BF0(n + 0xCA, &v, &D_80143718, 0);
        }
    }
    if (0xA8C - n * 512 < g_Spike_80140BF0.z) {
        D_80143EF8_80140BF0.f_0 = n * 16 + 0x50;
        D_80143EF8_80140BF0.f_2 = 10;
    }
    if (D_80143EF8_80140BF0.f_2 != 0) {
        D_80143EF8_80140BF0.f_2--;
        g_Spike_80140BF0.f_38 = -D_80143EF8_80140BF0.f_0;
        D_80143EF8_80140BF0.f_0 = D_80143EF8_80140BF0.f_0 * 3 / 4;
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140D60);
