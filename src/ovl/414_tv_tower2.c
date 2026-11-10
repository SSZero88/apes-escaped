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

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D1F0 asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D1F0;
extern u8 *D_80143D50[];
extern u8 *D_80143D60[];
void Model_BindBonedAuto(void *, void *);

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
    Model_BindBonedAuto(obj, D_80143D50[i]);
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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D6BC;
typedef struct { Mat_8013D6BC m; Mat_8013D6BC w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013D6BC;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_8013D6BC;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013D6BC;
#define ADDPRIM_BF_8013D6BC(ot, p) (((PTag_8013D6BC *)(p))->addr = ((PTag_8013D6BC *)(ot))->addr, ((PTag_8013D6BC *)(ot))->addr = (u32)(p))
#define gte_ldv3c_8013D6BC(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_8013D6BC() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_8013D6BC(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_8013D6BC(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Part_8013D6BC D_80143F08_8013D6BC[] asm("D_80143F08");
extern Mat_8013D6BC D_800E78C0_8013D6BC asm("g_ViewMatrix");
extern GameDraw g_Game_8013D6BC asm("g_Game");
void SetRotMatrix_8013D6BC(Mat_8013D6BC *) asm("SetRotMatrix");
void SetTransMatrix_8013D6BC(Mat_8013D6BC *) asm("SetTransMatrix");
void RotMatrixZYX_8013D6BC(SVECTOR *, Mat_8013D6BC *) asm("RotMatrixZYX");
void CompMatrix_8013D6BC(Mat_8013D6BC *, Mat_8013D6BC *, Mat_8013D6BC *) asm("CompMatrix");
#define SCR_8013D6BC ((Scr_8013D6BC *)0x1F800000)

void func_8013D6BC(void) {
    s32 i;
    Part_8013D6BC *e;
    u32 *p;
    u32 *ot;
    Scr_8013D6BC *sc;

    sc = SCR_8013D6BC;
    ot = g_Game_8013D6BC.db[g_Game_8013D6BC.cur].ot;
    p = (u32 *)g_Game_8013D6BC.prim;
    sc->w = D_800E78C0_8013D6BC;
    sc->v[0][0].vx = -0x18;
    sc->v[0][0].vy = -0x18;
    sc->v[0][0].vz = 0;
    sc->v[0][1].vx = 0x18;
    sc->v[0][1].vy = -0x18;
    sc->v[0][1].vz = 0;
    sc->v[0][2].vx = 0;
    sc->v[0][2].vy = 0x18;
    sc->v[0][2].vz = 0;
    sc->v[1][0].vx = -0x30;
    sc->v[1][0].vy = -0x30;
    sc->v[1][0].vz = 0;
    sc->v[1][1].vx = 0x30;
    sc->v[1][1].vy = -0x30;
    sc->v[1][1].vz = 0;
    sc->v[1][2].vx = 0;
    sc->v[1][2].vy = 0x30;
    sc->v[1][2].vz = 0;
    sc->v[2][0].vx = -8;
    sc->v[2][0].vy = -0x30;
    sc->v[2][0].vz = 0;
    sc->v[2][1].vx = 8;
    sc->v[2][1].vy = -0x30;
    sc->v[2][1].vz = 0;
    sc->v[2][2].vx = 0;
    sc->v[2][2].vy = 0x48;
    sc->v[2][2].vz = 0;
    sc->v[3][0].vx = -0xC;
    sc->v[3][0].vy = -0xC;
    sc->v[3][0].vz = 0;
    sc->v[3][1].vx = 0xC;
    sc->v[3][1].vy = -0xC;
    sc->v[3][1].vz = 0;
    sc->v[3][2].vx = 0;
    sc->v[3][2].vy = 0xC;
    sc->v[3][2].vz = 0;
    for (i = 79; i >= 0; i--) {
        e = &D_80143F08_8013D6BC[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            e->vy += 3;
            sc->rot.vx = e->life << 7;
            sc->rot.vy = e->life << 7;
            sc->rot.vz = e->life << 7;
            RotMatrixZYX_8013D6BC(&sc->rot, &sc->m);
            sc->m.t[0] = e->x;
            sc->m.t[1] = e->y;
            sc->m.t[2] = e->z;
            CompMatrix_8013D6BC(&sc->w, &sc->m, &sc->m);
            SetRotMatrix_8013D6BC(&sc->m);
            SetTransMatrix_8013D6BC(&sc->m);
            gte_ldv3c_8013D6BC(sc->v[i & 3]);
            gte_rtpt_8013D6BC();
            gte_stsxy3c_8013D6BC(sc->sxy);
            gte_stszotz_8013D6BC(&sc->z);
            if ((u32)(sc->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 6;
                p[1] = 0x32808080;
                p[3] = 0x404040;
                p[5] = 0;
                p[2] = sc->sxy[0];
                p[4] = sc->sxy[1];
                p[6] = sc->sxy[2];
                ADDPRIM_BF_8013D6BC(ot + sc->z, p);
                p += 7;
            }
        }
    }
    ((u8 *)p)[3] = 1;
    p[1] = 0xE1000200;
    ADDPRIM_BF_8013D6BC(ot, p);
    p += 2;
    g_Game_8013D6BC.prim = (u8 *)p;
}

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

typedef struct { s32 vx, vy, vz, pad; } Vec_8013DF68;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013DF68;
typedef struct { u8 *obj; s16 x, y, z; u8 active; u8 t; s16 vx, vy, vz; u8 state; u8 pad13; } Bomb_8013DF68;
extern Bomb_8013DF68 D_801442D0_8013DF68[] asm("D_801442D0");
extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013DF68 asm("g_Spike");
extern struct { u8 pad0[0xD]; u8 fD; } D_80143EF8_8013DF68 asm("D_80143EF8");
extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013DF68 asm("g_Game");
const Vec_8013DF68 D_80143250 = { 0x2800, 0x2800, 0x2800, 0 };
extern u8 g_ViewMatrix[];
extern u8 g_ProjVerts[];
extern u8 D_800F4C40[];
void func_8013D500(void *arg0, s32 arg1, s32 arg2, s16 arg3);
void func_8013DB04(s32 arg0);
void VectorNormalSS_8013DF68(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
void Effect_SpawnAt(s32, SVECTOR *);
s32 Sound_PlayFixed_8013DF68(s32) asm("Sound_PlayFixed");
void *memset_8013DF68(void *, s32, s32) asm("memset");
void Shadow_Draw_8013DF68(void *, s32, s32, s32) asm("Shadow_Draw");
void Matrix_FromDirection_8013DF68(void *, void *) asm("Matrix_FromDirection");
void *ScaleMatrix_8013DF68(void *m, void *v) asm("ScaleMatrix");
void *CompMatrix_8013DF68(void *m0, void *m1, void *m2) asm("CompMatrix");
void Model_ProjectVerts_8013DF68(void *, void *, void *) asm("Model_ProjectVerts");
void func_80017CD4_8013DF68(void *, void *, void *) asm("Model_Draw");

void func_8013DF68(s32 arg0) {
    Mat_8013DF68 m;
    SVECTOR d;
    Vec_8013DF68 b;
    Vec_8013DF68 a;
    Bomb_8013DF68 *p;
    s32 i;
    s32 ty;

    for (i = 7; i >= 0; i--) {
        p = &D_801442D0_8013DF68[i];
        if (p->active == 0) {
            continue;
        }
        p->t--;
        switch (p->state) {
        case 0:
            p->vx = p->vx * 7 / 8;
            p->vy = p->vy * 3 / 4;
            p->vz = p->vz * 7 / 8;
            if (p->t == 0) {
                p->state = 1;
                p->t = 0x12;
            }
            break;
        case 1:
            d.vx = g_Spike_8013DF68.x - p->x;
            d.vy = g_Spike_8013DF68.y - p->y;
            d.vz = g_Spike_8013DF68.z - p->z;
            VectorNormalSS_8013DF68(&d, &d);
            if (p->t == 0) {
                p->state = 2;
                p->t = 0xB4;
                p->vx = d.vx / 128;
                p->vy = d.vy / 128;
                p->vz = d.vz / 128;
                Effect_SpawnAt(0x27, (SVECTOR *)&D_801442D0_8013DF68[i].x);
            } else {
                p->vx = d.vx / 256;
                p->vy = d.vy / 256;
                p->vz = d.vz / 256;
            }
            break;
        case 2:
            if (p->t != 0 && p->y < -0x1020) {
                if (p->obj == NULL) {
                    break;
                }
                ty = M2C_FIELD(p->obj, u32 *, 0x2C) >> 28;
                if (ty != 6 && ty != 10 && ty != 11) {
                    break;
                }
            }
            p->active = 0;
            p->y = -0x1020;
            Effect_SpawnAt(0x102, (SVECTOR *)&D_801442D0_8013DF68[i].x);
            Camera_StartShake(0);
            Sound_PlayFixed_8013DF68(0x4D);
            if (D_80143EF8_8013DF68.fD == 0 && !(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1)) {
                func_8013DB04((s32)&D_801442D0_8013DF68[i].x);
                D_80143EF8_8013DF68.fD = 1;
            }
            break;
        }
        if (p->active != 0) {
            func_8013D500(p, arg0, 0x50, 0x200);
            if (p->t & 1) {
                Effect_SpawnAt(5, (SVECTOR *)&D_801442D0_8013DF68[i].x);
            }
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
        }
    }
    for (i = 7; i >= 0; i--) {
        p = &D_801442D0_8013DF68[i];
        if (p->active != 0) {
            memset_8013DF68(&a, 0, 0x10);
            a.vx = p->x;
            a.vy = p->y;
            a.vz = p->z;
            b = a;
            Shadow_Draw_8013DF68(&b, -0x1010, 0x80, 0);
            Matrix_FromDirection_8013DF68(&D_801442D0_8013DF68[i].vx, &m);
            a = D_80143250;
            ScaleMatrix_8013DF68(&m, &a);
            m.t[0] = p->x;
            m.t[1] = p->y;
            m.t[2] = p->z;
            CompMatrix_8013DF68(g_ViewMatrix, &m, &m);
            Model_ProjectVerts_8013DF68(D_800F4C40, &m, g_ProjVerts);
            func_80017CD4_8013DF68(g_Game_8013DF68.f_80 + g_Game_8013DF68.f_C * 0x4078, g_ProjVerts, D_800F4C40);
        }
    }
}

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

typedef struct { s16 x, y, z; u8 f6, f7; s16 vx, vy, vz; u8 fE, fF; } Bit_8013E6E4;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013E6E4;
#define ADDPRIM_BF_8013E6E4(ot, p) (((PTag_8013E6E4 *)(p))->addr = ((PTag_8013E6E4 *)(ot))->addr, ((PTag_8013E6E4 *)(ot))->addr = (u32)(p))
#define gte_stszotz_8013E6E4(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Bit_8013E6E4 D_80144370_8013E6E4[32] asm("D_80144370");
extern u32 D_80143A9C[];
extern u8 D_80143718_8013E6E4[] asm("D_80143718");
extern GameDraw g_Game_8013E6E4 asm("g_Game");
extern u8 D_800E78C0_8013E6E4[] asm("g_ViewMatrix");
void SetRotMatrix_8013E6E4(void *) asm("SetRotMatrix");
void SetTransMatrix_8013E6E4(void *) asm("SetTransMatrix");
void Effect_Spawn_8013E6E4(s32, void *, void *, s32) asm("Effect_Spawn");

void func_8013E6E4(void) {
    SVECTOR v;
    s32 sxy0[1];
    s32 z;
    s32 sxy1[1];
    s32 i;
    Bit_8013E6E4 *b;
    u32 *p;
    u32 *ot;

    i = 31;
    b = D_80144370_8013E6E4;
    for (; i >= 0; i--, b++) {
        if (b->f6 != 0) {
            if (b->f7 != 0) {
                b->f7--;
            } else {
                b->f6--;
                b->x += b->vx;
                b->y += b->vy;
                b->z += b->vz;
            }
        }
    }
    SetRotMatrix_8013E6E4(D_800E78C0_8013E6E4);
    SetTransMatrix_8013E6E4(D_800E78C0_8013E6E4);
    p = (u32 *)g_Game_8013E6E4.prim;
    ot = g_Game_8013E6E4.db[g_Game_8013E6E4.cur].ot;
    i = 31;
    b = D_80144370_8013E6E4;
    for (; i >= 0; i--, b++) {
        if (b->f6 != 0 && b->f7 == 0) {
            gte_ldv0(b);
            gte_rtps();
            gte_stsxy(sxy0);
            gte_stszotz_8013E6E4(&z);
            if ((u32)(z - 1) >= 0xFFF) {
                break;
            }
            if (b->fE == 0) {
                v.vx = b->x - b->vx * 8;
                v.vy = b->y - b->vy * 8;
                v.vz = b->z - b->vz * 8;
                gte_ldv0(&v);
                gte_rtps();
                gte_stsxy(sxy1);
                ((u8 *)p)[3] = 5;
                p[1] = 0xE100023C;
                p[2] = D_80143A9C[b->fF] | 0x52000000;
                p[3] = sxy0[0];
                p[4] = 0;
                p[5] = sxy1[0];
                ADDPRIM_BF_8013E6E4(ot + z, p);
                p += 6;
            } else {
                Effect_Spawn_8013E6E4(b->fF + 0xD1, b, D_80143718_8013E6E4, 0);
            }
        }
    }
    g_Game_8013E6E4.prim = (u8 *)p;
}

extern struct { s32 frame; u8 pad_4[0x8]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013E9C8 asm("g_Game");
extern u8 D_80143D70_8013E9C8[] asm("D_80143D70");
extern u8 g_ViewMatrix[];
extern u8 g_ProjVerts[];
extern u8 D_800E9EC0[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void *RotMatrixZ(s32 r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Matrix_FromDirection(void *, void *);
void Matrix_RotateY(s32, void *);
void Matrix_SetIdentity(void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_8013D290_8013E9C8(s32, s32, void *, s32) asm("func_8013D290");

s32 func_8013E9C8(u8 *a, void *scale, s32 c, s32 spin) {
    SVECTOR v;
    s32 sxy;
    s16 x;
    s16 y;
    s32 p;
    s32 z;

    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
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
        Model_CalcKeyedJointMatrices(a, 3);
    } else {
        u8 *o = D_80143D70_8013E9C8;

        Matrix_SetIdentity((void *)0x1F800018);
        RotMatrixZ(M2C_FIELD(o, s32 *, 0xA4), (void *)0x1F800018);
        Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
        CompMatrix(M2C_FIELD(a, void **, 0x14), (void *)0x1F800018, M2C_FIELD(a, void **, 0x14));
        ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
        Model_CalcKeyedJointMatrices(o, 3);
        Matrix_RotateY(g_Game_8013E9C8.frame * 773, D_800E9EC0);
        Matrix_RotateY(g_Game_8013E9C8.frame * 773, D_800E9EC0 + 0x20);
    }
    Model_ProjectBonedVerts(a);
    func_8013D290_8013E9C8((s32)(g_Game_8013E9C8.f_80 + g_Game_8013E9C8.f_C * 0x4078), (s32)g_ProjVerts, a, c);
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

typedef struct { s32 vx, vy, vz, pad; } Vec_8013F240;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; s16 f_5C; u8 pad5E[2]; s16 f_60, f_62, f_64; u8 pad66[0x14]; s16 f_7A, f_7C, f_7E; u8 f_80, f_81; u8 pad82[2]; } Blast_8013F240;
extern Blast_8013F240 D_80144598_8013F240[1] asm("D_80144598");
extern u8 D_800B1BD4[];
extern u8 D_801439F4_8013F240[] asm("D_801439F4");
const Vec_8013F240 D_80143260 = { 0x2000, 0x2000, 0x2000, 0 };
s32 Sound_PlayFixed_8013F240(s32) asm("Sound_PlayFixed");
void Shadow_Draw_8013F240(void *, s32, s32, s32) asm("Shadow_Draw");
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
s32 func_8013E9C8(u8 *a, void *scale, s32 c, s32 spin);

void func_8013F240(void) {
    SVECTOR v;
    Vec_8013F240 a;
    Blast_8013F240 *b;
    s32 i;
    s32 j;
    s32 c;

    for (i = 0, b = D_80144598_8013F240; i < 1; i++, b++) {
        if (b->f_80 == 0) {
            continue;
        }
        switch (b->f_80) {
        case 1:
            b->x += b->f_7A;
            b->y += b->f_7C;
            b->z += b->f_7E;
            b->f_7C += 3;
            v.vx = b->x;
            v.vy = b->y;
            v.vz = b->z;
            Effect_SpawnAt(5, &v);
            if (b->y >= -0x107F) {
                b->f_7C = -0x19;
                b->y = -0x1080;
                b->f_80 = 2;
                v.vy = -0x1000;
                for (j = 0; j < 30; j++) {
                    Effect_Spawn(0xD6, (s32)&v, &D_80143718, 0);
                }
                func_80070284(&v, D_800B1BD4, 1, 4, 0);
                Camera_StartShake(1);
                Sound_PlayFixed_8013F240(0x9C);
            }
            break;
        case 2:
            b->x += b->f_7A;
            b->y += b->f_7C;
            b->z += b->f_7E;
            b->f_7C += 5;
            v.vx = b->x;
            v.vy = b->y;
            v.vz = b->z;
            if (b->y >= -0x107F) {
                b->y = -0x1080;
                v.vy = -0x1000;
                for (j = 0; j < 16; j++) {
                    Effect_Spawn(0xD6, (s32)&v, &D_80143718, 0);
                }
                b->f_7C = -b->f_7C / 3;
                if (b->f_7C >= -0x13) {
                    b->f_80 = 3;
                    b->f_81 = 0;
                }
            }
            break;
        case 3:
            v.vx = b->x;
            v.vy = -0x1080;
            v.vz = b->z;
            if (b->f_81 >= 0x2E) {
                for (j = 0; j < 60; j++) {
                    Effect_Spawn(0xD5, (s32)&v, &D_80143718, 0);
                }
                Fx_SpawnFadeRing(&v, 0, 0x578, 0);
                Fx_SpawnFadeRing(&v, 0, 0x384, 4);
                func_80070284(&v, D_801439F4_8013F240, 1, 6, 0);
                func_80070284(&v, D_801439F4_8013F240 + 0x54, 1, 0, 0);
                Effect_SpawnAt(0x109, &v);
                Sound_PlayFixed_8013F240(0x80);
                Sound_PlayFixed_8013F240(0x6C);
                Sound_PlayFixed_8013F240(0x95);
                Camera_StartShake(2);
                b->f_80 = 4;
                b->f_81 = 0;
            }
            break;
        case 4:
            if (b->f_81 >= 0x29) {
                b->f_80 = 0;
            }
            break;
        }
        b->f_81++;
        if ((u32)(b->f_80 - 1) < 3) {
            b->f_5C = 0;
            a = D_80143260;
            c = 0;
            if (b->f_80 == 3 && (b->f_81 & 1)) {
                c = 0x141E80;
            }
            b->f_60 = 0;
            b->f_62 = 0;
            b->f_64 = 0x1000;
            func_8013E9C8((u8 *)b, &a, c, 0);
            Shadow_Draw_8013F240(&b->x, -0x1010, 0x100, 0);
        }
    }
}

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

typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[4]; u32 f_50; u8 pad_54[8]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[8]; u8 *f_70; s16 f_74; s16 f_76; s16 f_78; u8 pad_7A[2]; u16 *f_7C; u8 pad_80[2]; u8 f_82; u8 mode; u8 active; u8 f_85; u8 f_86; u8 f_87; s16 vx; s16 vy; s16 vz; s16 f_8E; s16 f_90; s16 f_92; u8 f_94; u8 pad_95[3]; } Mine_8013F8B8;
extern Mine_8013F8B8 D_80143AF0_8013F8B8[] asm("D_80143AF0");
extern struct { u8 pad_0[0xD]; u8 fD; } D_80143EF8_8013F8B8 asm("D_80143EF8");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F8B8 asm("g_Spike");
extern u8 D_80143718_8013F8B8[] asm("D_80143718");
void Effect_Spawn_8013F8B8(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
s32 Sound_PlayFixed_8013F8B8(s32) asm("Sound_PlayFixed");
s32 VectorNormalSS_8013F8B8(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
void Collision_Set_8013F8B8(s32, void *, void *) asm("Collision_Set");
void Collision_Remove_8013F8B8(void *) asm("Collision_Remove");
void func_8007CD88_8013F8B8(void *) asm("func_8007CD88");
void func_8007CDC4_8013F8B8(void *) asm("func_8007CDC4");
void *memset_8013F8B8(void *, s32, s32) asm("memset");
void Shadow_Draw_8013F8B8(void *, s32, s32, s32) asm("Shadow_Draw");
s32 rsin_8013F8B8(s32) asm("rsin");
s32 rcos_8013F8B8(s32) asm("rcos");
s32 func_8013E9C8(u8 *a, void *scale, s32 c, s32 spin);
void func_8013F838(SVECTOR *v);
#define RAND_8013F8B8() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013F8B8(void) {
    s32 sc[3];
    SVECTOR pos;
    SVECTOR d;
    SVECTOR t;
    SVECTOR u;
    Mine_8013F8B8 *p;
    s32 i;
    s32 r;
    s32 c;

    for (i = 3, p = D_80143AF0_8013F8B8; i >= 0; i--, p++) {
        if (p->active == 0) {
            continue;
        }
        if (p->f_87 != 0) {
            p->f_87--;
            continue;
        }
        pos.vx = p->x;
        pos.vy = p->y;
        pos.vz = p->z;
        sc[0] = 0x1000;
        sc[1] = 0x1000;
        sc[2] = 0x1000;
        if (p->active == 1) {
            func_8013F838(&pos);
            Camera_StartShake(1);
            Sound_PlayFixed_8013F8B8(0x8F);
            p->active = 2;
            Collision_Set_8013F8B8(5, &p->x, p);
            p->f_4A = 0x200;
            p->f_48 = 1;
            p->f_44 = 0x80;
            p->f_46 = 0x80;
            func_8007CD88_8013F8B8(&p->f_74);
        } else if (p->active == 3) {
            sc[0] = 0x1000 - (p->f_85 << 9);
            sc[1] = (p->f_85 << 11) + 0x1000;
            sc[2] = 0x1000 - (p->f_85 << 9);
            p->y += 0x40;
            if (p->f_85 >= 8) {
                p->active = 0;
                Collision_Remove_8013F8B8(&p->x);
                func_8007CDC4_8013F8B8(&p->f_74);
            }
        } else {
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (p->f_85 > p->f_86 || (p->f_70 != NULL && (M2C_FIELD(p->f_70, u32 *, 0x2C) >> 28) == 6)) {
                func_8013F838(&pos);
                p->f_85 = 0;
                p->active = 3;
                Sound_PlayFixed_8013F8B8(0x90);
            } else if (p->active == 2) {
                if ((p->f_50 >> 28) == 0xB) {
                    Effect_SpawnAt(0x113, &pos);
                    if (--p->f_94 == 0) {
                        func_8013F838(&pos);
                        p->f_85 = 0;
                        p->active = 3;
                        Sound_PlayFixed_8013F8B8(0x90);
                        Sound_PlayFixed_8013F8B8(0x6E);
                        if (D_80143EF8_8013F8B8.fD == 0 && !((RAND_8013F8B8() >> 8) & 1)) {
                            func_8013DB04((s32)&pos);
                            D_80143EF8_8013F8B8.fD = 1;
                        }
                    } else {
                        p->active = 4;
                        Effect_SpawnAt(0x113, &pos);
                        p->f_8E = 0x14;
                        p->vx = p->x - g_Spike_8013F8B8.x;
                        p->vy = 0;
                        p->vz = p->z - g_Spike_8013F8B8.z;
                        VectorNormalSS_8013F8B8((SVECTOR *)&p->vx, (SVECTOR *)&p->vx);
                        p->vy = -0x20;
                        p->vx >>= 5;
                        p->vz >>= 5;
                        Sound_PlayFixed_8013F8B8(0x60);
                    }
                }
            }
            Effect_Spawn_8013F8B8(0xD3, &pos, D_80143718_8013F8B8, 0);
            if (p->active == 4) {
                p->vx = p->vx * 7 / 8;
                p->vy = p->vy * 7 / 8;
                p->vz = p->vz * 7 / 8;
                if (--p->f_8E == 0) {
                    p->active = 2;
                }
            } else {
                p->y += rsin_8013F8B8(p->f_92) >> 8;
                p->f_92 = (p->f_92 + 0xE3) % 4096;
            }
            if (p->f_8E < 2) {
                switch (p->mode) {
                case 0:
                    d.vx = g_Spike_8013F8B8.x - p->x;
                    d.vy = g_Spike_8013F8B8.y - p->y;
                    d.vz = g_Spike_8013F8B8.z - p->z;
                    r = VectorNormalSS_8013F8B8(&d, &d);
                    if (r > 0x100000 && p->f_86 == 0xFF) {
                        p->f_86 = 0xF0;
                    }
                    p->vx = ((p->vx * 31) >> 5) + (d.vx >> 10);
                    p->vy = ((p->vy * 31) >> 5) + (d.vy >> 10);
                    p->vz = ((p->vz * 31) >> 5) + (d.vz >> 10);
                    p->vx = p->vx < -0x1C ? -0x1C : p->vx > 0x1C ? 0x1C : p->vx;
                    p->vy = p->vy < -0x10 ? -0x10 : p->vy > 0x10 ? 0x10 : p->vy;
                    p->vz = p->vz < -0x1C ? -0x1C : p->vz > 0x1C ? 0x1C : p->vz;
                    if (!(p->f_85 & 0x1F) && ((RAND_8013F8B8() >> 8) & 1)) {
                        Sound_PlayFixed_8013F8B8(0x96);
                    }
                    break;
                case 1:
                    p->x += rcos_8013F8B8(p->f_90) >> 8;
                    p->y += p->vy;
                    p->z += rsin_8013F8B8(p->f_90) >> 8;
                    p->f_90 = (p->f_90 + 0x71) % 4096;
                    if (p->f_8E == 1 || (p->z < 0xA8C && p->f_82 == 0)) {
                        p->f_82 = 1;
                        p->vy = 0;
                        p->vx = ((RAND_8013F8B8() >> 8) & 0x7F) - 0x40;
                        p->vz = -((RAND_8013F8B8() >> 8) & 0x3F) - 8;
                        Sound_PlayFixed_8013F8B8(0x96);
                    }
                    if (p->f_82 != 0) {
                        if (p->x < -0x600) {
                            p->x = -0x600;
                            p->vx = -p->vx;
                        }
                        if (p->x > 0x600) {
                            p->x = 0x600;
                            p->vx = -p->vx;
                        }
                        if (p->z < -0x200) {
                            p->z = -0x200;
                            p->vz = -p->vz;
                        }
                        if (p->z > 0xA00) {
                            p->z = 0xA00;
                            p->vz = -p->vz;
                        }
                    }
                    break;
                }
            }
        }
        p->f_85++;
        p->f_74 = p->x;
        p->f_76 = p->y;
        p->f_78 = p->z;
        if (p->active == 2
            && (g_Spike_8013F8B8.x - p->x < 0 ? p->x - g_Spike_8013F8B8.x : g_Spike_8013F8B8.x - p->x) < 0x200
            && (g_Spike_8013F8B8.z - p->z < 0 ? p->z - g_Spike_8013F8B8.z : g_Spike_8013F8B8.z - p->z) < 0x200) {
            func_8013D500(&p->f_70, (s32)p, 0x50, 0x200);
        }
        if (p->f_94 == 1 && !(p->f_85 & 3)) {
            memset_8013F8B8(&u, 0, 8);
            u.vx = p->x + (((u16)RAND_8013F8B8() >> 8) - 0x80);
            u.vy = p->y - ((u16)RAND_8013F8B8() >> 8);
            u.vz = p->z + (((u16)RAND_8013F8B8() >> 8) - 0x80);
            t = u;
            Effect_SpawnAt(7, &t);
            func_8006D548(&t);
        }
        if (++p->f_5C > p->f_7C[1]) {
            p->f_5C = p->f_7C[0];
        }
        c = 0;
        if (p->f_94 == 1) {
            if (p->f_85 & 1) {
                c = 0x141E80;
            }
        } else if (p->vx | p->vy | p->vz) {
            VectorNormalSS_8013F8B8((SVECTOR *)&p->vx, &p->f_60);
        }
        func_8013E9C8((u8 *)p, sc, c, 0);
        Shadow_Draw_8013F8B8(&p->x, -0x1010, 0x80, 0);
    }
}

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

typedef struct { u16 start; u16 end; } Anim_80140D60;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x20]; u32 f50; u8 pad_54[8]; u16 f5C; u8 pad_5E[2]; SVECTOR dir; u8 pad_68[8]; u8 f70; u8 state; u8 f72; u8 f73; Anim_80140D60 *anims; u16 anim; u8 pad_7A; u8 f7B; s32 ang; s32 f80; s32 rad; SVECTOR tgt; SVECTOR f90; SVECTOR f98; s32 fA0; s32 fA4; s32 fA8; u8 pad_AC; u8 fAD; u8 fAE; u8 fAF; u16 fB0; u16 fB2; s16 fB4; s16 fB6; s16 fB8; u8 fBA; u8 fBB; u32 fBC; s32 fC0; } Boss_80140D60;
typedef struct { s16 x, y, z, pad; } Pt_80140D60;
typedef struct { u8 b[0x54]; } Burst_80140D60;
typedef struct { u8 pad_0[0x24]; s16 f24; } Shape_80140D60;
extern Boss_80140D60 D_80143D70_80140D60[] asm("D_80143D70");
extern struct { u8 pad_0[6]; u8 f6; u8 f7; s16 f8; s16 fA; u8 fC; u8 fD; } D_80143EF8_80140D60 asm("D_80143EF8");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x30]; SVECTOR f60; } g_Spike_80140D60 asm("g_Spike");
extern Pt_80140D60 D_80143AC4[];
extern Burst_80140D60 D_80143754;
extern Burst_80140D60 D_801437A8[];
extern Burst_80140D60 D_801438F8;
extern Burst_80140D60 D_8014394C[];
extern u8 D_80143850_80140D60[] asm("D_80143850");
void Camera_StartShake_80140D60(s32) asm("Camera_StartShake");
void Camera_ExitAim(void);
void Spike_SetPlayMode(s32);
void VectorNormalSS_80140D60(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
Shape_80140D60 *Collision_GetShape_80140D60(s32) asm("Collision_GetShape");
void Collision_Remove_80140D60(void *) asm("Collision_Remove");
void Fx_DebrisExplosion(s32, s32, s32);
void Effect_Spawn_80140D60(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
void *memset_80140D60(void *, s32, s32) asm("memset");
u32 SquareRoot0_80140D60(s32) asm("SquareRoot0");
s32 rsin_80140D60(s32) asm("rsin");
s32 rcos_80140D60(s32) asm("rcos");
void RotMatrixY_80140D60(s32, void *) asm("RotMatrixY");
void ApplyMatrixSV_80140D60(void *, void *, void *) asm("ApplyMatrixSV");
void func_8013D554(SVECTOR *arg0);
void func_8013DA8C(void);
void func_8013DAB4(void);
void func_8013DADC(void);
void func_8013DBA8(s32 arg0);
void func_8013DBD0(void *obj);
void func_8013DC38(void *obj);
void func_8013DE7C(SVECTOR *pos);
void func_8013DF68(s32 arg0);
void func_8013D6BC(void);
void func_8013E53C(SVECTOR *pos, s32 c);
void func_8013E6E4(void);
void func_8013EBC8(void);
void func_8013ED18(s16 *pos);
void func_8013EE1C(void *o);
void func_8013F190(void);
void func_8013F1B4(s16 *p);
void func_8013F240(void);
void func_8013F6EC(s16 *pos);
void func_8013F8B8(void);
s32 func_80140794(void *arg0, s32 arg1);
void func_801407FC(u8 *a, s32 sx, s32 sy, s32 sz);
void func_8014097C(u8 *a);
void func_80140A18(void *arg0);
void func_80140A90(u8 *arg0);
void func_80140BF0(u8 *arg0, s32 n, s32 burst);
#define RAND_80140D60() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D60(void) {
    SVECTOR *sp = (SVECTOR *)0x1F800000;
    Boss_80140D60 *o = D_80143D70_80140D60;

    if (o->fAD != 1) {
        if (o->anims[o->anim].end < ++o->f5C) {
            o->f5C--;
            o->fBB = 0;
        }
        sp[0].vy = 0;
        sp[0].vx = g_Spike_80140D60.x - o->x;
        sp[0].vz = g_Spike_80140D60.z - o->z;
        VectorNormalSS_80140D60(&sp[0], &sp[0]);
        sp[1].vy = 0;
        sp[1].vx = o->tgt.vx - o->x;
        sp[1].vz = o->tgt.vz - o->z;
        VectorNormalSS_80140D60(&sp[1], &sp[1]);
        sp[2].vx = 0;
        sp[2].vz = 0;
        sp[2].vy = o->tgt.vy - o->y;
        VectorNormalSS_80140D60(&sp[2], &sp[2]);
        if (o->fAF != 0 && (o->f50 >> 28) == 0xB && o->state < 0x14 && o->fAE == 0) {
            Shape_80140D60 *sh = Collision_GetShape_80140D60(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
            SVECTOR pos;

            pos.vx = o->x + o->dir.vx / 4;
            pos.vy = 0;
            pos.vz = o->z + o->dir.vz / 4;
            if ((o->anim == 1 || o->anim == 8 || o->anim == 3 || o->anim == 6)
                && (sh->f24 & 0xFF00) != 0xD00 && (sh->f24 & 0xFF00) != 0xF00) {
                if (o->y >= -0x11FF) {
                    pos.vy = o->y - 0x200;
                } else {
                    pos.vy = o->y;
                }
                Fx_DebrisExplosion(pos.vx, pos.vy, pos.vz);
                func_8013D554(&pos);
                Camera_StartShake_80140D60(1);
                {
                    SVECTOR dir = { g_Spike_80140D60.f60.vx, 0, g_Spike_80140D60.f60.vz };

                    func_80070284(&pos, D_80143850_80140D60, 1, 0, (s32)&dir);
                }
                pos.vy = 0;
                pos.vx = g_Spike_80140D60.x - o->x;
                pos.vz = g_Spike_80140D60.z - o->z;
                VectorNormalSS_80140D60(&pos, &pos);
                o->fB4 = -pos.vx / 16;
                o->fB6 = 0;
                o->fB8 = -pos.vz / 16;
                o->state = 0x14;
                o->fAE = 0x18;
                o->fB2 = 0x18;
                o->f7B = 0;
                o->fAF--;
                func_8013DA8C();
                Sound_PlayFixed(0x95);
                Sound_PlayFixed(0x4D);
                Sound_PlayFixed(0x78);
            } else {
                o->fAE = 0xC;
                pos.vy = o->y - 0x100;
                func_8013DE24((s32)&pos);
                func_8013DE24((s32)&pos);
                Camera_StartShake_80140D60(0);
                Sound_PlayFixed(0x22);
                Sound_PlayFixed(0x60);
                func_8013DA8C();
            }
        }
        switch (o->state) {
        case 20:
            o->x += o->fB4;
            o->y -= 8;
            o->z += o->fB8;
            o->fB4 = o->fB4 * 3 / 4;
            o->fB8 = o->fB8 * 3 / 4;
            o->fB0 = 30000;
            o->fA4 = (o->fA4 + 0x1022) % 0x1000;
            o->fA0 = (o->fA0 + 0xFF5) % 0x1000;
            {
                SVECTOR v = { o->x + o->dir.vx / 4, o->y - 0x80, o->z + o->dir.vz / 4 };

                Effect_SpawnAt(7, &v);
                Effect_SpawnAt(5, &v);
            }
            if (--o->fB2 == 0) {
                func_8013DC38((void *)0xBB);
                func_8014097C((u8 *)o);
                Sound_PlayFixed(0xBA);
                if (o->fAF == 0) {
                    o->state = 0x15;
                    o->tgt.vy = -0x1680;
                    o->tgt.vx = 0;
                    o->tgt.vz = 0x400;
                    o->f90 = o->tgt;
                    func_8013F190();
                    Spike_SetPlayMode(0xE);
                }
            }
            break;
        case 21:
            Camera_ExitAim();
            func_801407FC((u8 *)o, 0x18, 0x18, 0x18);
            {
                s32 t;

                t = ((RAND_80140D60() >> 8) & 7) + 0x1000;
                o->fA0 = (o->fA0 + t - 3) % 0x1000;
                t = ((RAND_80140D60() >> 8) & 7) + 0x1000;
                o->fA4 = (o->fA4 + t - 3) % 0x1000;
            }
            if (func_80140794(o, 0x40)) {
                o->state = 0x16;
                o->f90.vy = -0x1000;
                o->fB6 = -0xA;
                o->fB2 = 2;
                o->fC0 = 0x38;
            }
            if (((RAND_80140D60() >> 8) & 7) == 0) {
                o->fB0 = 4;
            }
            if (((RAND_80140D60() >> 8) & 0xF) == 0) {
                Sound_PlayFixed(0x4B);
            }
            if (((RAND_80140D60() >> 8) & 7) == 0) {
                Sound_PlayFixed(0x4D);
            }
            break;
        case 22:
            Camera_ExitAim();
            {
                s32 t;

                t = o->fC0 + 0x1000;
                o->fA0 = (o->fA0 + t) % 0x1000;
                t = o->fC0 + 0x1000;
                o->fA4 = (o->fA4 + t) % 0x1000;
            }
            o->y += o->fB6;
            o->fB6 += 0x28;
            if (o->y >= -0xFFF) {
                o->y = -0x1000;
                o->fB6 = -o->fB6 / 3;
                o->fC0 = -o->fC0;
                if (--o->fB2 == 0) {
                    o->state = 0x17;
                    o->fB2 = 0xB4;
                    Sound_PlayFixed(0x78);
                } else {
                    {
                        SVECTOR v = { o->x, -0x1010, o->z };

                        func_80070284(&v, &D_80143754, 1, 0, 0);
                    }
                    Sound_PlayFixed(0x4D);
                }
                Camera_StartShake_80140D60(1);
            }
            break;
        case 23:
            Camera_ExitAim();
            if (--o->fB2 == 0) {
                o->fAD = 1;
                break;
            }
            if (o->fB2 >= 0xAF && o->fB2 <= 0xB2) {
                func_8013E464(0xE6F0FF);
                o->fC0 = 0xA0;
                o->fBA = 1;
                Sound_PlayFixed(0xBD);
                Sound_PlayFixed(0x79);
            }
            if (o->fB2 < 0xAE && o->fC0 != 0) {
                u8 c = o->fC0;

                func_8013E464((c >> 2 << 16) | (c >> 1 << 8) | c);
                o->fC0--;
            }
            if (o->fB2 == 0xAF) {
                SVECTOR v = { o->x, -0xF00, o->z };
                s32 i;

                func_8013D554(&v);
                Fx_SpawnFadeRing(&v, 0, 0xBB8, 5);
                func_80070284(&v, &D_801437A8[0], 3, 0, 0);
                v.vy = -0x1040;
                func_80070284(&v, &D_801437A8[1], 1, 6, 0);
                v.vy = -0x129E;
                func_80070284(&v, &D_801437A8[1], 1, 0xD, 0);
                v.vy = -0x13E8;
                func_80070284(&v, &D_801437A8[1], 1, 0x16, 0);
                for (i = 0x14; i >= 0; i--) {
                    v.vx = o->x + ((RAND_80140D60() >> 8) - 0x80) * 4;
                    v.vy = -0x1000 - ((s16)RAND_80140D60() >> 6 & 0x3FC);
                    v.vz = o->z + ((RAND_80140D60() >> 8) - 0x80) * 4;
                    Effect_SpawnAt(6, &v);
                }
                func_8013DBA8(0xBC);
                Sound_PlayFixed(0x79);
                Collision_Remove_80140D60(&o->x);
            }
            if (o->fB2 == 0x8C) {
                func_8013DBD0((void *)0xBC);
            }
            if (o->fB2 > 0x68) {
                if ((o->fB2 & 7) == 0) {
                    Sound_PlayFixed(0x79);
                }
                if ((o->fB2 & 0xF) == 0) {
                    Sound_PlayFixed(0x80);
                }
            }
            if (o->fB2 < 0x50) {
                Camera_StartShake_80140D60(0);
            } else if (o->fB2 < 0x78) {
                Camera_StartShake_80140D60(1);
                func_8013DAB4();
            } else {
                Camera_StartShake_80140D60(2);
                func_8013DADC();
            }
            if (o->fB2 > 0x50) {
                SVECTOR v = { o->x + ((RAND_80140D60() >> 8) - 0x80) * 8, -0x1000 - (RAND_80140D60() >> 8) * 3, o->z + ((RAND_80140D60() >> 8) - 0x80) * 8 };

                Effect_SpawnAt(7, &v);
            }
            if (o->fB2 > 0x78) {
                SVECTOR v = { o->x + ((RAND_80140D60() >> 8) - 0x80) * 4, -0x1000 - ((s16)RAND_80140D60() >> 7 & 0x1FE), o->z + ((RAND_80140D60() >> 8) - 0x80) * 4 };

                Effect_SpawnAt(7, &v);
            }
            if (o->fB2 == 0x96) {
                SVECTOR v;
                s32 i;

                for (i = 0x14; i >= 0; i--) {
                    v.vx = o->x;
                    v.vy = -0x1000 - ((s16)RAND_80140D60() >> 6 & 0x3FC);
                    v.vz = o->z;
                    Effect_SpawnAt(5, &v);
                }
            }
            if (o->fB2 == 0x1E) {
                D_800E69BE = 1;
            }
            break;
        case 0:
            o->x = 0;
            o->y = -0x1000;
            o->z = 0x1400;
            o->tgt.vx = 0;
            o->tgt.vy = -0x1000;
            o->tgt.vz = 0x400;
            o->f90 = o->tgt;
            o->fA8 = 0x22;
            if (D_80143EF8_80140D60.fC == 0) {
                if (o->fBB == 0 && o->anim != 2) {
                    func_80140948(o, 2);
                    Sound_PlayFixed(0x4D);
                    Sound_PlayFixed(0x60);
                    Camera_StartShake_80140D60(1);
                }
                if (--o->fB2 == 0) {
                    o->state = 2;
                    D_80143EF8_80140D60.f8 = 0x14;
                    D_80143EF8_80140D60.f7 = 2;
                }
                func_80140BF0((u8 *)o, 3, 1);
            }
            break;
        case 2:
            if (D_80143EF8_80140D60.f7 == 0 && D_80143EF8_80140D60.f8 == 0) {
                o->state = 3;
                o->fB2 = o->fAF * 30 + 0x48;
                func_80140948(o, 6);
                func_80140A90((u8 *)o);
                D_80143EF8_80140D60.f8 = 0x3F;
                func_8013DBD0((void *)0xBE);
            }
            if (D_80143EF8_80140D60.f8 != 0) {
                D_80143EF8_80140D60.f8--;
            }
            if (D_80143EF8_80140D60.f7 != 0 && D_80143EF8_80140D60.f8 == 0) {
                SVECTOR v;

                u16 sd;
                v.vx = o->x + o->dir.vx / 3;
                D_80143EF8_80140D60.f7--;
                sd = g_RandSeed * 5 + 1;
                D_80143EF8_80140D60.fA = 0x1E;
                D_80143EF8_80140D60.f8 = 0x12C;
                D_80143EF8_80140D60.fD = 0;
                v.vy = o->y - 0x380;
                D_80143EF8_80140D60.f6 = ((g_RandSeed = sd) >> 8) & 1;
                v.vz = o->z + o->dir.vz / 3;
                func_8013E53C(&v, D_80143EF8_80140D60.f6);
                Sound_PlayFixed(0x8E);
                Sound_PlayFixed(0x80);
                func_80070284(&v, &D_8014394C[D_80143EF8_80140D60.f6], 3, 6, (s32)&o->dir);
            }
            if (D_80143EF8_80140D60.fA != 0) {
                D_80143EF8_80140D60.fA--;
                D_80143EF8_80140D60.f8++;
                if (D_80143EF8_80140D60.fA == 0) {
                    SVECTOR v;

                    v.vy = o->y - 0x380;
                    v.vx = o->x + o->dir.vx / 3;
                    v.vz = o->z + o->dir.vz / 3;
                    if (D_80143EF8_80140D60.f6 == 0) {
                        D_80143EF8_80140D60.f8 = 0x12C;
                        func_8013F6EC((s16 *)&v);
                    } else {
                        D_80143EF8_80140D60.f8 = 0x78;
                        func_8013ED18((s16 *)&v);
                        func_80070284(&v, &D_801438F8, 2, 3, (s32)&o->dir);
                        Effect_SpawnAt(0x113, &v);
                    }
                }
            }
            func_80140BF0((u8 *)o, 3, 1);
            break;
        case 3:
            if (--o->fB2 == 0) {
                o->state = 4;
                func_80140948(o, 7);
                Sound_PlayFixed(0x27);
                Sound_PlayFixed(0x28);
            }
            if (D_80143EF8_80140D60.f8 != 0) {
                D_80143EF8_80140D60.f8--;
                func_80140BF0((u8 *)o, D_80143EF8_80140D60.f8 >> 4, 1);
            }
            break;
        case 4:
            if (o->fBB == 0) {
                func_8014097C((u8 *)o);
            }
            break;
        case 8:
            Camera_StartShake_80140D60(0);
            if (o->fB2 != 0) {
                if (--o->fB2 == 0) {
                    o->fB0 = 30000;
                    o->fBC = 0;
                    func_8013DBA8(0xBE);
                    Sound_PlayFixed(0x4D);
                }
            }
            if (o->fBB != 0) {
                break;
            }
            o->f90.vy = o->tgt.vy;
            if (o->fBC < 0x2A) {
                func_801407FC((u8 *)o, 5, 5, 5);
                o->y += o->fB6;
                o->fB6++;
                if (o->fB6 < 0) {
                    o->fB6 = 0;
                }
            } else {
                func_801407FC((u8 *)o, 0x30, 0x40, 0x30);
            }
            if (o->fBC == 0x2F) {
                SVECTOR v = { o->x, o->y + 0x100, o->z };

                func_80070284(&v, &D_80143754, 1, 0, 0);
                Camera_StartShake_80140D60(1);
                Sound_PlayFixed(0x80);
                Sound_PlayFixed(0x79);
            }
            if (func_80140794(o, 0x40)) {
                o->state = 9;
                o->fA8 = 0x38;
                o->f80 = 0x16;
                if ((RAND_80140D60() >> 8) & 1) {
                    o->f80 = -0x16;
                }
                o->f73 = 1;
                o->fB0 = 0;
                o->fBC = 0;
                o->f90.vx = o->x - o->f80;
                o->f90.vz = o->z;
                o->fB2 = (RAND_80140D60() >> 9) + 0x12C;
                func_8013DBD0((void *)0xBE);
                Sound_PlayFixed(0xBA);
            }
            break;
        case 9:
            func_80140948(o, 0);
            if (o->f73 == 0) {
                if (o->ang == 0x400) {
                    o->fB0 = 8;
                }
                if (o->f80 > 0) {
                    o->dir.vx = -rsin_80140D60(o->ang);
                    o->dir.vz = rcos_80140D60(o->ang);
                } else {
                    o->dir.vx = rsin_80140D60(o->ang);
                    o->dir.vz = -rcos_80140D60(o->ang);
                }
                o->dir.vy = 0;
                o->x = rcos_80140D60(o->ang) * o->rad >> 12;
                o->z = (rsin_80140D60(o->ang) * o->rad >> 12) + 0x400;
                o->y = -0x1480;
                o->ang = (o->ang + o->f80 + 0x1000) % 0x1000;
                o->rad = (u32)(o->rad * 31 + 0x578) >> 5;
                if (--o->fB2 == 0) {
                    func_80140A18(o);
                } else if (o->fBC >= 0x47 && o->fB2 >= 0x47 && o->fB2 % 63 == 0) {
                    u8 idx;

                    if (o->fAF >= 5) {
                        goto block_f7b;
                    }
                    idx = 2;
                    if (o->fAF >= 3 && ((RAND_80140D60() >> 8) & 7) >= 5) {
                    block_f7b:
                        o->f7B = 3;
                        Sound_PlayFixed(0xA8);
                        Sound_PlayFixed(0x80);
                    } else {
                        u32 best = 0x4000;
                        s32 k;

                        for (k = 4; k >= 0; k--) {
                            s32 dx = o->x - D_80143AC4[k].x;
                            s32 dz = o->z - D_80143AC4[k].z;
                            u32 d = SquareRoot0_80140D60(dx * dx + dz * dz);

                            if (d < best) {
                                best = d;
                                idx = k;
                            }
                        }
                        o->state = 0xA;
                        o->f73 = 1;
                        o->fB2 = 0xA;
                        o->fB6 = 0x32;
                        o->f72 = idx;
                        o->fA8 = 0x22;
                        o->tgt.vx = D_80143AC4[o->f72].x;
                        o->tgt.vy = D_80143AC4[o->f72].y;
                        o->tgt.vz = D_80143AC4[o->f72].z;
                        o->f90 = o->tgt;
                        Sound_PlayFixed(0xBA);
                        Sound_PlayFixed(0xAC);
                    }
                }
            }
            break;
        case 10:
            if (o->f73 != 0) {
                o->y += 6;
                break;
            }
            o->fA8 = 0x44;
            if (o->fB0 == 0) {
                o->fB0 = 30000;
                func_8013DBA8(0xBC);
            }
            if (o->fB2 != 0) {
                o->y += o->fB6;
                o->fB6 -= 0xA;
                if (--o->fB2 == 0) {
                    SVECTOR v = { o->x, o->y, o->z };

                    func_80070284(&v, &D_80143754, 1, 0, 0);
                    Fx_DebrisExplosion(v.vx, v.vy, v.vz);
                    Camera_StartShake_80140D60(2);
                    o->fB6 = -0xF0;
                    func_8013DBD0((void *)0xBC);
                    Sound_PlayFixed(0x80);
                    Sound_PlayFixed(0x79);
                }
            } else {
                func_801407FC((u8 *)o, 0x40, 0x20, 0x40);
                o->y += o->fB6;
                o->fB6 += 0x14;
                if (o->fB6 > 0) {
                    o->fB6 = 0;
                }
                if (func_80140794(o, 0x5F4)) {
                    o->f90.vx = g_Spike_80140D60.x;
                    o->f90.vy = g_Spike_80140D60.y;
                    o->f90.vz = g_Spike_80140D60.z;
                }
                if (func_80140794(o, 0x60)) {
                    o->state = 0xB;
                    o->f73 = 1;
                    o->fB0 = 8;
                    o->tgt.vx = g_Spike_80140D60.x;
                    o->tgt.vy = g_Spike_80140D60.y;
                    o->tgt.vz = g_Spike_80140D60.z;
                }
            }
            break;
        case 11:
            o->y -= 0xE;
            if (o->f73 == 0) {
                o->state = 0xC;
                o->fB2 = 0x4E;
                Sound_PlayFixed(0x81);
                Sound_PlayFixed(0x80);
            }
            break;
        case 12:
            o->fA8 = 4;
            o->tgt.vx = g_Spike_80140D60.x;
            o->tgt.vy = g_Spike_80140D60.y - 0x100;
            o->tgt.vz = g_Spike_80140D60.z;
            o->f90 = o->tgt;
            o->y += 8;
            if (--o->fB2 == 0x2E) {
                func_80140948(o, 8);
                func_80140A90((u8 *)o);
            }
            if (o->fB2 == 0) {
                func_80140948(o, 1);
                o->state = 0xD;
                o->fB6 = -0x32;
                o->fA8 = 0xB;
                o->tgt.vy = -0x1258;
                o->tgt.vx = g_Spike_80140D60.x;
                o->tgt.vz = g_Spike_80140D60.z;
                o->f90 = o->tgt;
                Sound_PlayFixed(0x8C);
            }
            break;
        case 13:
            func_801407FC((u8 *)o, 0x50, 0, 0x50);
            o->fA8 = 0xB;
            o->y += o->fB6;
            o->fB6 += 4;
            if (o->y >= -0x1257) {
                o->fB6 = 0x14;
                o->state = 0xE;
                o->y = -0x1258;
                o->fB0 = 30000;
                o->tgt.vy = -0x1258;
                o->tgt.vx = o->x + sp[1].vx;
                o->tgt.vz = o->z + sp[1].vz;
                {
                    SVECTOR v = { o->x, o->y, o->z };

                    func_8013F1B4((s16 *)&v);
                    Sound_PlayFixed(0x80);
                    Sound_PlayFixed(0xBA);
                }
            }
            Camera_StartShake_80140D60(1);
            break;
        case 14:
            func_801407FC((u8 *)o, 0x50, 0, 0x50);
            o->y += o->fB6;
            o->fB6 -= 4;
            if (o->fB6 < 0) {
                o->tgt.vy = -0x1680;
            }
            o->f90 = o->tgt;
            if (o->y >= -0x1257) {
                o->y = -0x1258;
            }
            if (o->y < -0x1680) {
                o->y = -0x1680;
            }
            if (func_80140794(o, 0x80)) {
                func_80140A18(o);
            }
            break;
        case 15:
            func_801407FC((u8 *)o, 0x40, 0x40, 0x40);
            if (o->fBB == 0) {
                func_80140948(o, 0);
            }
            if (func_80140794(o, 0x60)) {
                o->z = 0x1400;
                o->state = 0x10;
                o->tgt.vy = -0x1240;
                o->tgt.vz = 0x400;
                o->x = 0;
                o->tgt.vx = 0;
                o->f90 = o->tgt;
                o->fA8 = 0x22;
                o->f73 = 1;
                o->fB6 = -0x1E;
                o->fB0 = 6;
                Sound_PlayFixed(0x81);
                Sound_PlayFixed(0x80);
            }
            break;
        case 16:
            if (o->f73 != 0) {
                o->y += o->fB6;
                o->fB6 += 2;
                if (o->fB6 > 0x36) {
                    o->fB6 = 0x36;
                }
            } else {
                s32 d;

                if (o->fB0 == 0) {
                    o->fB0 = 30000;
                    func_8013DBA8(0xBC);
                }
                o->fB6 -= 6;
                if (o->fB6 < 0x10) {
                    o->fB6 = 0x10;
                }
                o->y += o->fB6;
                d = -0x1000 - o->y;
                if (d >= 0x200) {
                    d = 0x1FF;
                }
                func_80140BF0((u8 *)o, d >> 7, 0);
            }
            if (o->y >= -0xFFF) {
                o->y = -0x1000;
                Camera_StartShake_80140D60(1);
                {
                    SVECTOR v = { o->x, -0x1020, o->z };

                    func_80070284(&v, &D_80143754, 2, 0, 0);
                }
                o->fB2 = 0x50;
                o->state = 0;
                func_80140948(o, 4);
                func_8013DC38((void *)0xBB);
                func_8013DBD0((void *)0xBC);
                func_8013DBA8(0xBE);
                Sound_PlayFixed(0x81);
                Sound_PlayFixed(0x79);
            }
            break;
        }
        if ((M2C_FIELD(o, u32 *, 0x70) & 0xFF00FF00) != 0x900) {
            SVECTOR v = { o->f90.vx - o->x, 0, o->f90.vz - o->z };
            s32 dot;

            o->dir.vy = 0;
            VectorNormalSS_80140D60(&v, &v);
            dot = (o->dir.vx * v.vx + o->dir.vz * v.vz) >> 12;
            if (rcos_80140D60(o->fA8 * 2) < dot) {
                o->f73 = 0;
            }
            if (dot < rcos_80140D60(o->fA8)) {
                s32 cross = (o->dir.vz * v.vx - o->dir.vx * v.vz) >> 12;
                s32 a = o->fA8;

                Matrix_SetIdentity((void *)(sp + 3));
                if (cross < 0) {
                    a = -a;
                }
                RotMatrixY_80140D60(a, (void *)(sp + 3));
                ApplyMatrixSV_80140D60((void *)(sp + 3), &o->dir, &o->dir);
                VectorNormalSS_80140D60(&o->dir, &o->dir);
            }
        }
        if (o->state != 0x14) {
            if (o->f90.vy < o->y) {
                o->fA0 = (o->fA0 + 0xFF5) % 0x1000;
                if (o->fA0 > 0x800 && o->fA0 < 0xEAA) { o->fA0 = 0xEAA; }
            } else if (o->y < o->f90.vy) {
                o->fA0 = (o->fA0 + 0x100B) % 0x1000;
                if (o->fA0 > 0x155 && o->fA0 < 0x800) { o->fA0 = 0x155; }
            } else if (o->fA0 != 0) { if (o->fA0 > 0x800) {
                    o->fA0 = (o->fA0 + 0x100B) % 0x1000;
                } else {
                    o->fA0 = (o->fA0 + 0xFF5) % 0x1000;
                }
                if (o->fA0 < 0x16 || o->fA0 >= 0xFEA) {
                    o->fA0 = 0;
                }
            }
        }
        o->dir.vy = rsin_80140D60(o->fA0);
        {
            s32 cross = (o->dir.vz * o->f98.vx - o->dir.vx * o->f98.vz) >> 12;

            if (o->dir.vx != o->f98.vx || o->dir.vz != o->f98.vz) {
                s32 t = (cross < 0 ? -0xB : 0xB);
                s32 u = t + 0x1000;

                o->fA4 = (o->fA4 + u) % 0x1000;
                if (o->fA4 < 0x800) {
                    if (o->fA4 > 0xE3) {
                        o->fA4 = 0xE3;
                    }
                } else if (o->fA4 < 0xF1C) {
                    o->fA4 = 0xF1C;
                }
            } else if (o->fA4 != 0) {
                if (o->fA4 < 0x800) {
                    o->fA4 = (o->fA4 + 0xFF5) % 0x1000;
                    if (o->fA4 > 0x800) {
                        o->fA4 = 0;
                    }
                } else {
                    o->fA4 = (o->fA4 + 0x100B) % 0x1000;
                    if (o->fA4 < 0x800) {
                        o->fA4 = 0;
                    }
                }
            }
        }
        func_8013EBC8();
        o->fBC++;
        if (o->fAE != 0) {
            o->fAE--;
        }
        if (D_80143EF8_80140D60.fC == 0) {
            if (o->f7B != 0) {
                if ((o->fBC & 3) == 0) {
                    SVECTOR v = { o->x, o->y - 0x100, o->z };

                    func_8013DE7C(&v);
                    o->f7B--;
                }
            }
            if (o->state != 0x17 && (o->fAF < 5 || o->state == 0x14)) {
                SVECTOR v = { o->x + ((RAND_80140D60() >> 8) - 0x80) * 8, o->y - (((RAND_80140D60() >> 6) & 0x3FC) + 0x100), o->z + ((RAND_80140D60() >> 8) - 0x80) * 8 };

                Effect_SpawnAt(7, &v);
                if (o->state > 0x14) {
                    Effect_SpawnAt(((RAND_80140D60() >> 8) & 3) ? 0x27 : 0x102, &v);
                }
                func_8006D548(&v);
            }
            if (o->fB0 != 0) {
                SVECTOR v;

                o->fB0--;
                v.vx = o->x + o->dir.vz / 4;
                v.vy = o->y - 0x1A4;
                v.vz = o->z - o->dir.vx / 4;
                Effect_Spawn_80140D60(0xC8, &v, &D_80143718, 0);
                v.vx = o->x - o->dir.vz / 4;
                v.vz = o->z + o->dir.vx / 4;
                Effect_Spawn_80140D60(0xC8, &v, &D_80143718, 0);
            }
        }
        o->f98 = o->dir;
        func_8013DF68((s32)o);
        func_8013D6BC();
        func_8013E6E4();
        func_8013F8B8();
        func_8013F240();
        func_8013EE1C(o);
    }
}
