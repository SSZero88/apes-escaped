#include "common.h"
#include "m2c_macros.h"

extern s32 g_StageMeshes;
extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xB6]; s32 f_820C; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;
M2C_UNK Effect_Spawn(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK);
extern M2C_UNK Fx_SpikeChestPos;
extern M2C_UNK D_80141640;
extern struct S_D_80141880 { u8 pad_0[0x2]; u16 f_2; s16 f_4; u8 pad_6[0x2]; s16 f_8; u8 pad_A[0x6]; s32 f_10; s32 f_14; } D_80141880;
extern struct S_g_Spike { u8 pad_0[0x2C]; s32 f_2C; s32 f_30; u8 pad_34[0x4]; s32 f_38; } g_Spike;

extern struct S_D_80142368 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80142368[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80142728;
s32 Sound_Play(M2C_UNK, s32);
extern M2C_UNK D_80141D20;
extern M2C_UNK D_801421C0;
extern M2C_UNK D_80142260;
extern M2C_UNK D_801418A0;

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D440 asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D440;
extern u8 *D_80142240[];
extern u8 *D_80142250[];
void Model_BindBonedAuto(void *, void *);

M2C_UNK func_8013D440(M2C_UNK i, M2C_UNK *obj, void *out) {
    u8 *bank = g_Game_8013D440.f_8244;
    AnimEnt_8013D440 *ent;
    u8 *s;
    u32 *q;

    D_80142240[i] = bank + (ent = (AnimEnt_8013D440 *)(i * 32 + (u32)(bank + M2C_FIELD(bank, s32 *, 8))))->f18;
    D_80142250[i] = s = g_Game_8013D440.f_8244 + ent->f1C;
    q = (u32 *)s + 1;
    *(u32 **)out = q;
    M2C_FIELD(obj, u32 **, 0x18) = q + *(u16 *)s;
    Model_BindBonedAuto(obj, D_80142240[i]);
}

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
extern u8 g_ViewMatrix[];
extern u8 g_ProjVerts[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void Matrix_FromDirection(void *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);

s32 func_8013D63C(u8 *a, void *scale, s32 c) {
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
    if (x < -0x80 || x > 0x200 || y < -0x80 || y > 0x1B8 || z > 0x1000 || z <= 0) {
        return 1;
    }
    Matrix_FromDirection(a + 0x60, M2C_FIELD(a, void **, 0x14));
    ScaleMatrix(M2C_FIELD(a, void **, 0x14), scale);
    Model_CalcKeyedJointMatrices(a, 3);
    Model_ProjectBonedVerts(a);
    func_8013D4E0(g_Game_8013D63C.f_80 + g_Game_8013D63C.f_C * 0x4078, g_ProjVerts, a, c);
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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013DA4C;
typedef struct { Mat_8013DA4C m; Mat_8013DA4C w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013DA4C;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_8013DA4C;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013DA4C;
#define ADDPRIM_BF_8013DA4C(ot, p) (((PTag_8013DA4C *)(p))->addr = ((PTag_8013DA4C *)(ot))->addr, ((PTag_8013DA4C *)(ot))->addr = (u32)(p))
#define gte_ldv3c_8013DA4C(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_8013DA4C() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_8013DA4C(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_8013DA4C(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Part_8013DA4C D_80142368_8013DA4C[] asm("D_80142368");
extern Mat_8013DA4C D_800E78C0_8013DA4C asm("g_ViewMatrix");
extern GameDraw g_Game_8013DA4C asm("g_Game");
void SetRotMatrix_8013DA4C(Mat_8013DA4C *) asm("SetRotMatrix");
void SetTransMatrix_8013DA4C(Mat_8013DA4C *) asm("SetTransMatrix");
void RotMatrixZYX_8013DA4C(SVECTOR *, Mat_8013DA4C *) asm("RotMatrixZYX");
void CompMatrix_8013DA4C(Mat_8013DA4C *, Mat_8013DA4C *, Mat_8013DA4C *) asm("CompMatrix");
#define SCR_8013DA4C ((Scr_8013DA4C *)0x1F800000)

void func_8013DA4C(void) {
    s32 i;
    Part_8013DA4C *e;
    u32 *p;
    u32 *ot;
    Scr_8013DA4C *sc;

    sc = SCR_8013DA4C;
    ot = g_Game_8013DA4C.db[g_Game_8013DA4C.cur].ot;
    p = (u32 *)g_Game_8013DA4C.prim;
    sc->w = D_800E78C0_8013DA4C;
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
        e = &D_80142368_8013DA4C[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            e->vy += 3;
            sc->rot.vx = e->life << 7;
            sc->rot.vy = e->life << 7;
            sc->rot.vz = e->life << 7;
            RotMatrixZYX_8013DA4C(&sc->rot, &sc->m);
            sc->m.t[0] = e->x;
            sc->m.t[1] = e->y;
            sc->m.t[2] = e->z;
            CompMatrix_8013DA4C(&sc->w, &sc->m, &sc->m);
            SetRotMatrix_8013DA4C(&sc->m);
            SetTransMatrix_8013DA4C(&sc->m);
            gte_ldv3c_8013DA4C(sc->v[i & 3]);
            gte_rtpt_8013DA4C();
            gte_stsxy3c_8013DA4C(sc->sxy);
            gte_stszotz_8013DA4C(&sc->z);
            if ((u32)(sc->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 6;
                p[1] = 0x32808080;
                p[3] = 0x404040;
                p[5] = 0;
                p[2] = sc->sxy[0];
                p[4] = sc->sxy[1];
                p[6] = sc->sxy[2];
                ADDPRIM_BF_8013DA4C(ot + sc->z, p);
                p += 7;
            }
        }
    }
    ((u8 *)p)[3] = 1;
    p[1] = 0xE1000200;
    ADDPRIM_BF_8013DA4C(ot, p);
    p += 2;
    g_Game_8013DA4C.prim = (u8 *)p;
}

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

typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x2C]; s16 f_5C; u8 pad_5E[0x12]; s32 f_70; u8 pad_74[6]; u8 f_7A; u8 f_7B; u8 pad_7C[6]; u8 f_82; u8 type; u8 active; u8 f_85; u16 f_86; s16 f_88; s16 f_8A; s16 f_8C; u8 f_8E; u8 f_8F; u8 f_90; u8 pad_91[3]; } O_8013E1D0;
extern O_8013E1D0 D_80141D20_8013E1D0[] asm("D_80141D20");

void func_8013E1D0(s16 *pos, s32 type) {
    s32 i;
    O_8013E1D0 *p;

    for (i = 0, p = D_80141D20_8013E1D0; i < 8; i++, p++) {
        if (p->active == 0) {
            p->active = 1;
            p->f_82 = i << 5;
            p->f_70 = 0;
            p->f_85 = 0;
            p->x = pos[0];
            p->y = pos[1];
            p->z = pos[2];
            p->f_88 = 0;
            p->f_8A = 0;
            p->f_8C = 0;
            p->f_86 = 0xFFFF;
            p->f_7A = 0;
            p->f_7B = 0;
            p->f_90 = 2;
            p->type = type;
            if (type != 2) {
                if (type >= 3) {
                    if (type == 4) {
                        p->f_8E = 0;
                        p->f_8F = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) + 8;
                    }
                }
            }
            p->f_5C = 0;
            return;
        }
    }
}

typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[4]; u32 f_50; u8 pad_54[8]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[8]; u8 f_70[4]; s16 f_74; s16 f_76; s16 f_78; u8 f_7A; u8 f_7B; u16 *f_7C; u8 pad_80[2]; u8 f_82; u8 type; u8 active; u8 f_85; u16 f_86; s16 vx; s16 vy; s16 vz; u8 f_8E; u8 f_8F; u8 f_90; u8 pad_91[3]; } O_8013E2BC;
extern O_8013E2BC D_80141D20_8013E2BC[] asm("D_80141D20");
extern struct { u8 pad_0[0x1C]; u8 f_1C; } D_80141880_8013E2BC asm("D_80141880");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E2BC asm("g_Spike");
extern u8 D_80142260_8013E2BC[] asm("D_80142260");
void Effect_SpawnAt(s32, void *);
s32 Sound_PlayFixed_8013E2BC(s32) asm("Sound_PlayFixed");
s32 VectorNormalSS_8013E2BC(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
void Collision_Set_8013E2BC(s32, void *, void *) asm("Collision_Set");
void Collision_Remove_8013E2BC(void *) asm("Collision_Remove");
void func_8007CD88_8013E2BC(void *) asm("GuidedAmmo_AddTarget");
void func_8007CDC4_8013E2BC(void *) asm("GuidedAmmo_RemoveTarget");
void Puff_Spawn_8013E2BC(void *, s32, s32, s32) asm("Puff_Spawn");
void func_8013D890(void *arg0, s32 arg1, s32 arg2, s16 arg3);
s32 func_8013D63C(u8 *a, void *scale, s32 c);
void func_8013DE94(s32 arg0);
#define RAND_8013E2BC() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013E2BC(void) {
    s32 sc[3];
    SVECTOR pos;
    SVECTOR d;
    O_8013E2BC *p;
    s32 i;
    s32 r;
    s32 c;
    u16 r1;

    for (i = 7, p = D_80141D20_8013E2BC; i >= 0; i--, p++) {
        if (p->active == 0) {
            continue;
        }
        if (p->f_82 != 0) {
            p->f_82--;
            continue;
        }
        pos.vx = p->x;
        pos.vy = p->y;
        pos.vz = p->z;
        sc[0] = 0x1800;
        sc[1] = 0x1800;
        sc[2] = 0x1800;
        if (p->active == 1) {
            Effect_SpawnAt(0x113, &pos);
            Sound_PlayFixed_8013E2BC(0x18);
            p->active = 2;
            Collision_Set_8013E2BC(4, &p->x, D_80142260_8013E2BC);
            p->f_48 = 1;
            p->f_4A = 0x200;
            p->f_44 = 0x60;
            p->f_46 = 0x40;
            func_8007CD88_8013E2BC(&p->f_74);
        } else if (p->active == 3) {
            p->active = 0;
            Collision_Remove_8013E2BC(&p->x);
            func_8007CDC4_8013E2BC(&p->f_74);
        } else {
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (p->f_85 & 1) {
                Effect_SpawnAt(9, &pos);
            }
            if (p->z > -0xC40 || p->f_85 > p->f_86) {
                Effect_SpawnAt(0x102, &pos);
                Sound_PlayFixed_8013E2BC(0x4D);
                p->f_85 = 0;
                p->active = 3;
            } else if (p->active == 2) {
                if ((p->f_50 >> 28) == 0xB) {
                    if (--p->f_90 == 0) {
                        Effect_SpawnAt(0x102, &pos);
                        Sound_PlayFixed_8013E2BC(0x4D);
                        p->f_85 = 0;
                        p->active = 3;
                        if (D_80141880_8013E2BC.f_1C == 0 && !((RAND_8013E2BC() >> 8) & 1)) {
                            func_8013DE94((s32)&pos);
                            D_80141880_8013E2BC.f_1C = 1;
                        }
                    } else {
                        p->active = 4;
                        Effect_SpawnAt(0x113, &pos);
                        p->f_7A = 0x20;
                        p->vx = p->x - g_Spike_8013E2BC.x;
                        p->vy = 0;
                        p->vz = p->z - g_Spike_8013E2BC.z;
                        VectorNormalSS_8013E2BC((SVECTOR *)&p->vx, (SVECTOR *)&p->vx);
                        p->vx >>= 5;
                        p->vz >>= 5;
                        p->type = (RAND_8013E2BC() >> 8) & 1;
                        Sound_PlayFixed_8013E2BC(0x67);
                    }
                }
            }
            if (p->active == 4) {
                p->vx = p->vx * 3 / 4;
                p->vz = p->vz * 3 / 4;
                if (--p->f_7A == 0) {
                    p->active = 2;
                }
                if (!(p->f_85 & 3)) {
                    Puff_Spawn_8013E2BC(&p->f_74, 1, 0, 0x20);
                }
            }
            d.vx = g_Spike_8013E2BC.x - p->x;
            d.vy = -(p->y + 0x80) + g_Spike_8013E2BC.y;
            d.vz = g_Spike_8013E2BC.z - p->z;
            r = VectorNormalSS_8013E2BC(&d, &d);
            if (p->f_7A == 0) {
                switch (p->type) {
                case 0:
                    if (r <= 0x3FFFF && p->f_86 == 0xFFFF) {
                        p->f_86 = 0xF0;
                    }
                    p->vx = ((p->vx * 31) >> 5) + (d.vx >> 10);
                    p->vz = ((p->vz * 31) >> 5) + (d.vz >> 10);
                    p->vx = p->vx < -0x1C ? -0x1C : p->vx > 0x1C ? 0x1C : p->vx;
                    p->vz = p->vz < -0x1C ? -0x1C : p->vz > 0x1C ? 0x1C : p->vz;
                    if (!((RAND_8013E2BC() >> 8) & 0x1F)) {
                        Sound_PlayFixed_8013E2BC(0x97);
                    }
                    break;
                case 1:
                    p->vx = d.vx >> 9;
                    p->vz = d.vz >> 9;
                    if (++p->f_7B > 0x10) {
                        p->f_7B = 0;
                        p->vx = d.vx >> 6;
                        p->vz = d.vz >> 6;
                        p->type = 2;
                        Sound_PlayFixed_8013E2BC(0x97);
                    }
                    break;
                case 2:
                    if (r <= 0x3FFFF && p->f_86 == 0xFFFF) {
                        p->f_86 = 0xF0;
                    }
                    if (++p->f_7B >= 0x1F || r <= 0x9C3F) {
                        p->f_7B = 10;
                        p->type = 3;
                    }
                    break;
                case 3:
                    p->vx = p->vx * 15 / 16;
                    p->vz = p->vz * 15 / 16;
                    if (--p->f_7B == 0) {
                        p->f_7B = 0;
                        p->type = 1;
                    }
                    break;
                case 4:
                    if (p->f_8F != 0 && p->f_8E == 0) {
                        if (--p->f_8F == 0) {
                            r1 = RAND_8013E2BC();
                            p->f_8E = ((RAND_8013E2BC() >> 8) & 0xF) + 0x14;
                            p->vx = ((r1 >> 8) & 2) - 1;
                            p->f_8F = ((RAND_8013E2BC() >> 8) & 0xF) + 8;
                        }
                    }
                    if (p->f_8E < 5) {
                        p->vz += 3;
                        p->vx = p->vx * 3 / 4;
                    }
                    if (p->f_8E != 0) {
                        p->f_8E--;
                        if (p->vx >= 0) {
                            p->vx += 3;
                        } else {
                            p->vx -= 3;
                        }
                        p->vz = p->vz * 3 / 4;
                    }
                    p->vx = p->vx < -0x20 ? -0x20 : p->vx > 0x20 ? 0x20 : p->vx;
                    p->vz = p->vz < -0x40 ? -0x40 : p->vz > 0x40 ? 0x40 : p->vz;
                    if (p->x < -0x180) {
                        p->x = -0x180;
                    }
                    if (p->x > 0xD80) {
                        p->x = 0xD80;
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
            && (g_Spike_8013E2BC.x - p->x < 0 ? p->x - g_Spike_8013E2BC.x : g_Spike_8013E2BC.x - p->x) < 0x200
            && (g_Spike_8013E2BC.z - p->z < 0 ? p->z - g_Spike_8013E2BC.z : g_Spike_8013E2BC.z - p->z) < 0x200) {
            func_8013D890(p->f_70, (s32)D_80142260_8013E2BC, 0x50, 0x200);
        }
        if (++p->f_5C > p->f_7C[1]) {
            p->f_5C = p->f_7C[0];
        }
        c = 0;
        if (p->active == 4) {
            if (p->f_85 & 1) {
                c = 0x141E80;
            }
        } else {
            VectorNormalSS_8013E2BC((SVECTOR *)&p->vx, &p->f_60);
        }
        func_8013D63C((u8 *)p, sc, c);
    }
}

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

extern struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[2]; s16 f_60, f_62, f_64; u8 pad66[0xA]; u16 *f_70; u8 pad74[4]; u8 f_78; u8 pad79; s16 f_7A; } D_801421C0_8013ECD4 asm("D_801421C0");
s32 func_8013D63C(u8 *a, void *scale, s32 c);
void Effect_SpawnAt(s32, void *);
void *memset(void *, s32, s32);

void func_8013ECD4(void) {
    s32 sc[4] = { 0x1000, 0x1000, 0x1000, 0 };
    SVECTOR pos;
    SVECTOR tmp;
    s32 ang;

    if (D_801421C0_8013ECD4.f_78 != 0) {
        if (D_801421C0_8013ECD4.f_70[1] < ++D_801421C0_8013ECD4.f_5C) {
            D_801421C0_8013ECD4.f_5C = D_801421C0_8013ECD4.f_70[0];
        }
        ang = (D_801421C0_8013ECD4.f_78 * 512) % 4096;
        D_801421C0_8013ECD4.f_60 = rcos(ang);
        D_801421C0_8013ECD4.f_62 = 0;
        D_801421C0_8013ECD4.f_64 = rsin(ang);
        func_8013D63C((u8 *)&D_801421C0_8013ECD4, sc, 0);
        memset(&tmp, 0, 8);
        tmp.vx = D_801421C0_8013ECD4.x;
        tmp.vy = D_801421C0_8013ECD4.y - 0x40;
        tmp.vz = D_801421C0_8013ECD4.z;
        pos = tmp;
        Effect_SpawnAt(5, &pos);
        Effect_SpawnAt(5, &pos);
        Effect_SpawnAt(0x28, &pos);
        Effect_SpawnAt(0x30, &pos);
        D_801421C0_8013ECD4.y += D_801421C0_8013ECD4.f_7A;
        D_801421C0_8013ECD4.f_7A += 2;
        D_801421C0_8013ECD4.f_78--;
    }
}

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
        Effect_Spawn(0xCE, &Fx_SpikeChestPos, &D_80141640, 0);
    }
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013F1AC;
typedef struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x54]; u8 f_84; u8 pad_85[3]; s16 f_88; } M_8013F1AC;
extern M_8013F1AC D_80142260_8013F1AC asm("D_80142260");
extern struct { u8 f_0; u8 f_1; u8 pad_2[0xA]; s32 f_C; u8 pad_10[0xF]; u8 f_1F; } D_80141880_8013F1AC asm("D_80141880");
extern struct { u8 pad_0[0x24]; s32 x, y, z; } g_Spike_8013F1AC asm("g_Spike");
extern s32 D_800EC204;
extern s8 g_CurrentGadget;
extern u8 D_800E6916;
void Camera_ResetToStart(void);
s32 Sound_PlayFixed_8013F1AC(s32) asm("Sound_PlayFixed");
void Camera_DrawAimReticle(void *);
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);

s32 func_8013F1AC(void *cam) {
    Scr_8013F1AC *sc = (Scr_8013F1AC *)0x1F800000;
    s32 d;
    M_8013F1AC *m = &D_80142260_8013F1AC;

    if (D_80141880_8013F1AC.f_0 != 0) {
        return 0;
    }
    if (m->f_84 == 0) {
        if (D_80141880_8013F1AC.f_1F != 0) {
            return 0;
        }
        if (D_800EC204 < -0x180) {
            D_80141880_8013F1AC.f_1F = 1;
            Camera_ResetToStart();
            Sound_PlayFixed_8013F1AC(4);
        }
    }
    if (D_80141880_8013F1AC.f_1F != 0) {
        return 0;
    }
    sc->spike.vx = g_Spike_8013F1AC.x;
    sc->spike.vy = g_Spike_8013F1AC.y - 0x80;
    sc->spike.vz = g_Spike_8013F1AC.z;
    if (m->z < g_Spike_8013F1AC.z) {
        sc->spike.vz = m->z;
    }
    sc->eye.vy = -0xA00;
    sc->at.vx = (g_Spike_8013F1AC.x - 0x600) * 3 / 2 + 0x600;
    sc->at.vy = m->y - 0x44C;
    sc->at.vz = sc->spike.vz - 0x640;
    sc->eye.vx = (g_Spike_8013F1AC.x - 0x600) / 2 + 0x600;
    sc->eye.vz = sc->at.vz + 0xBB8;
    if (D_80141880_8013F1AC.f_1 == 0xD) {
        sc->at.vz += 0x320;
    } else if ((D_80141880_8013F1AC.f_1 == 4 || D_80141880_8013F1AC.f_1 == 8) && m->z < g_Spike_8013F1AC.z) {
        sc->at.vz += 0x400;
        sc->eye.vz += 0x400;
        sc->eye.vy += 0x258;
    } else if (D_80141880_8013F1AC.f_1 == 0x14) {
        sc->at.vz -= 0x400;
    } else if (D_80141880_8013F1AC.f_1 == 0x18) {
        d = -0x258;
        if (m->x < D_800EC204) {
            d = 0x258;
        }
        sc->eye.vx += d - m->f_88 * 8 + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) + 0xFF80);
        sc->at.vx += m->f_88 * 8 - d + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) + 0xFF80);
        sc->at.vz += (g_RandSeed = g_RandSeed * 5 + 1) >> 8;
    } else if (D_80141880_8013F1AC.f_1 == 0x19) {
        if (D_80141880_8013F1AC.f_C >= 0x49) {
            sc->at.vz += 0x400;
            sc->eye.vy -= 0x100;
        } else {
            sc->at.vz -= 0x200;
        }
    }
    sc->at.vx = sc->at.vx < 0x80 ? 0x80 : (sc->at.vx > 0xB80 ? 0xB80 : sc->at.vx);
    if (g_CurrentGadget == 3 && D_800E6916 != 1) {
        Camera_DrawAimReticle(cam);
    }
    Camera_EaseLookAt(cam, 8, 0x18, 0x10);
    Camera_EaseEye(cam, 8, 0x18, 8);
    return 1;
}

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

typedef struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x54]; u8 active; u8 pad_85[3]; s16 vx, vy, vz; u8 pad_8E[2]; } Rock_8013F5A8;
extern Rock_8013F5A8 D_801418A0_8013F5A8[] asm("D_801418A0");
extern u8 D_80141640_8013F5A8[] asm("D_80141640");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F5A8 asm("g_Spike");
void Effect_Spawn_8013F5A8(s32, void *, void *, s32) asm("Effect_Spawn");
s32 Sound_PlayFixed_8013F5A8(s32) asm("Sound_PlayFixed");

void func_8013F5A8(SVECTOR *pos) {
    Rock_8013F5A8 *o = D_801418A0_8013F5A8;
    s32 i;
    s32 j;
    s32 r;
    s32 d;

    for (i = 0; i < 8; i++, o++) {
        if (o->active == 0) {
            o->active = 1;
            o->x = pos->vx;
            o->y = pos->vy;
            o->z = pos->vz;
            o->vx = (g_Spike_8013F5A8.x - pos->vx) / 24 + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0xF;
            o->vy = -0x10;
            o->vz = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) + 0x1E;
            Effect_Spawn_8013F5A8(0xCA, pos, D_80141640_8013F5A8, 0);
            for (j = 8; j > 0; j--) {
                Effect_Spawn_8013F5A8(0xCB, pos, D_80141640_8013F5A8, 0);
            }
            Sound_PlayFixed_8013F5A8(0x4B);
            return;
        }
    }
}

typedef struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x2C]; s16 f_5C; u8 pad_5E[2]; SVECTOR dir; u8 pad_68[8]; u8 f_70[4]; s16 f_74, f_76, f_78; u8 pad_7A[0xA]; u8 active; u8 pad_85[3]; s16 vx, vy, vz; u8 pad_8E[2]; } Rock_8013F6F8;
extern Rock_8013F6F8 D_801418A0_8013F6F8[8] asm("D_801418A0");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F6F8 asm("g_Spike");
#define RAND_8013F6F8() (g_RandSeed = g_RandSeed * 5 + 1)
void Camera_StartShake(s32);
void VectorNormalSS(void *, void *);
void func_8013D890(void *arg0, s32 arg1, s32 arg2, s16 arg3);

void func_8013F6F8(void) {
    s32 sc[4] = { 0x2000, 0x2000, 0x2000, 0 };
    SVECTOR v;
    SVECTOR w;
    Rock_8013F6F8 *b;
    s32 i;

    for (i = 0, b = D_801418A0_8013F6F8; i < 8; i++, b++) {
        if (b->active != 0) {
            if (b->z >= -0x1917 || g_Spike_8013F6F8.z - 0x400 < b->z) {
                b->vy += ((RAND_8013F6F8() >> 8) & 3) + 5;
                b->vz += ((RAND_8013F6F8() >> 8) & 1) + 1;
            }
            b->x += b->vx + (g_Spike_8013F6F8.x - b->x) / 64;
            b->y += b->vy;
            b->z += b->vz;
            b->vy++;
            b->vz += 3;
            if (b->y >= -0xA20) {
                v.vx = b->x;
                v.vy = -0xA40;
                v.vz = b->z;
                Effect_SpawnAt(0x102, &v);
                Sound_PlayFixed(0x4D);
                Camera_StartShake(0);
                b->active = 0;
            }
            w.vx = b->x;
            w.vy = b->y;
            w.vz = b->z + 0x20;
            Effect_Spawn(0xCC, (M2C_UNK *)&w, &D_80141640, 0);
            b->f_74 = b->x;
            b->f_76 = b->y;
            b->f_78 = b->z;
            func_8013D890(b->f_70, (s32)&D_80142260, 0x50, 0x200);
            VectorNormalSS(&b->vx, &b->dir);
            b->f_5C = 0;
            func_8013D63C((u8 *)b, sc, 0);
        }
    }
}

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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013FA2C;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x20]; u32 f_50; u8 pad_54[0xC]; s16 f_60; s16 f_62; s16 f_64; u8 pad_66[0x12]; u16 f_78; u8 f_7A; u8 f_7B; s32 f_7C; s32 f_80; u8 f_84; u8 pad_85; u8 f_86; u8 pad_87; s16 f_88; s16 f_8A; s16 f_8C; s16 f_8E; u8 f_90; u8 f_91; u8 f_92; u8 f_93; } Boss_8013FA2C;
typedef struct { u8 f_0; u8 f_1; u16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 pad_A[2]; s32 f_C; s32 f_10; s32 f_14; s32 f_18; u8 f_1C; u8 f_1D; u8 f_1E; u8 pad_1F; } St_8013FA2C;
typedef struct { u8 pad_0[0x24]; s16 f_24; } Shape_8013FA2C;
typedef struct { void *shape; s16 x, y, z; } Coll_8013FA2C;
extern Boss_8013FA2C D_80142260_8013FA2C asm("D_80142260");
extern Boss_8013FA2C D_801422F8_8013FA2C asm("D_801422F8");
extern St_8013FA2C D_80141880_8013FA2C asm("D_80141880");
extern Coll_8013FA2C D_80142730_8013FA2C asm("D_80142730");
extern u8 D_80141881_8013FA2C asm("D_80141881");
extern s32 D_8014188C;
extern s32 D_80141890;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013FA2C asm("g_Spike");
extern u8 D_80141640_8013FA2C[] asm("D_80141640");
extern u8 D_800B4D88_8013FA2C[] asm("Fx_SpikeChestPos");
extern u8 D_80141660[];
extern u8 D_801416B4[];
extern u8 D_80141708[];
extern u8 D_8014175C[];
extern u8 D_80141804[];
extern u8 D_80141858[];
extern struct { s32 x, y, z; } D_800EC204_8013FA2C asm("D_800EC204");
void Effect_Spawn_8013FA2C(s32, void *, void *, s32) asm("Effect_Spawn");
s32 Sound_PlayFixed_8013FA2C(s32) asm("Sound_PlayFixed");
void Fx_SpawnFadeRing_8013FA2C(void *, s32, s32, s32) asm("Fx_SpawnFadeRing");
void func_80070284_8013FA2C(void *, void *, s32, s32, void *) asm("Shockwave_Spawn");
void func_8006F3D0_8013FA2C(void *, s32, void *, s32) asm("Fx_DrawRibbon");
void Fx_DebrisExplosion_8013FA2C(s32, s32, s32) asm("Fx_DebrisExplosion");
void Fx_GroundBlast_8013FA2C(s16, s16, s16) asm("Fx_GroundBlast");
Shape_8013FA2C *Collision_GetShape_8013FA2C(s32) asm("Collision_GetShape");
s32 Collision_GetId_8013FA2C(s32) asm("Collision_GetId");
void Collision_Remove_8013FA2C(void *) asm("Collision_Remove");
void Spike_SetPlayMode_8013FA2C(s32) asm("Spike_SetPlayMode");
void func_8006D548_8013FA2C(void *) asm("Dust_SpawnDrift");
void func_8004637C_8013FA2C(void *) asm("Matrix_SetIdentity");
void *RotMatrixY_8013FA2C(s32, void *) asm("RotMatrixY");
void *ApplyMatrixSV_8013FA2C(void *, void *, void *) asm("ApplyMatrixSV");
void func_8013DF60_8013FA2C(s32) asm("func_8013DF60");
void func_8013E1D0_8013FA2C(void *, s32, s32) asm("func_8013E1D0");
void func_8013D8E4(SVECTOR *arg0);
void func_8013DA4C_8013FA2C(void) asm("func_8013DA4C");
void func_8013DE1C(void);
void func_8013DE44(void);
void func_8013DE6C(void);
void func_8013DF38(s32 arg0);
void func_8013E1AC(void);
void func_8013E2BC(void);
void func_8013EC94(s16 x, s16 y, s16 z);
void func_8013ECD4(void);
void func_8013EE74(void);
void func_8013EF44(void *arg0);
void func_8013EFCC(u8 *a);
void func_8013F0E0(void);
void func_8013F5A8_8013FA2C(SVECTOR *) asm("func_8013F5A8");
void func_8013F6F8(void);
#define RAND_8013FA2C() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013FA2C(void) {
    SVECTOR s18;
    SVECTOR s20;
    SVECTOR s28;
    SVECTOR s30;
    SVECTOR s38;
    SVECTOR s40;
    SVECTOR s48;
    SVECTOR s50;
    SVECTOR s58;
    SVECTOR s60;
    SVECTOR s68;
    SVECTOR s70;
    SVECTOR s78;
    SVECTOR s80;
    SVECTOR s88;
    SVECTOR s90;
    SVECTOR s98;
    Mat_8013FA2C m;
    Boss_8013FA2C *b = &D_80142260_8013FA2C;
    s32 t;
    s32 dx;

    if (b->f_84 == 0) {
        return;
    }
    if (D_80141880_8013FA2C.f_0 == 0 && g_Spike_8013FA2C.z >= -0x11F7 && g_Spike_8013FA2C.x >= -0x180
        && (D_80141880_8013FA2C.f_1 == 1 || D_80141880_8013FA2C.f_1 == 0xC)) {
        D_80141880_8013FA2C.f_10++;
    } else {
        D_80141890 = 0;
    }
    switch (D_80141881_8013FA2C) {
    case 0:
        break;
    case 1:
        b->f_64 = 0x1000;
        b->f_7C = 0;
        b->f_60 = 0;
        b->f_62 = 0;
        b->z = -0x1B40;
        if (D_80141880_8013FA2C.f_10 >= 0x32 && D_80141880_8013FA2C.f_18 > 0) {
            func_8013EF00(0xC);
            D_80141880_8013FA2C.f_C = 0x3C;
            func_8013EF0C(b, 1);
            b->f_7B = 1;
            s18.vx = b->x;
            s18.vy = b->y - 0xC4;
            s18.vz = b->z - 0x1CC;
            func_80070284_8013FA2C(&s18, D_80141708, 1, 0, &b->f_60);
            Sound_PlayFixed_8013FA2C(0xAC);
        }
        if (D_80141880_8013FA2C.f_14 == 0 || --D_80141880_8013FA2C.f_14 == 0) {
            if (D_80141880_8013FA2C.f_18 == 0) {
                goto s7;
            }
            if (D_80141880_8013FA2C.f_10 < 0x19) {
                if (!((RAND_8013FA2C() >> 8) & 3)) {
                s7:
                    func_8013EF00(7);
                    func_8013EF0C(b, 0x11);
                    Sound_PlayFixed_8013FA2C(0xB3);
                } else {
                    func_8013EF00(2);
                    func_8013EF0C(b, 0xB);
                    Sound_PlayFixed_8013FA2C(0xB4);
                }
                D_80141880_8013FA2C.f_14 = 0x1E;
                D_80141880_8013FA2C.f_1C = 0;
                D_80141880_8013FA2C.f_18++;
            }
        }
        break;
    case 2:
        if (b->f_7A == 0) {
            func_8013EF00(3);
            func_8013EF0C(b, 0xE);
        }
        break;
    case 3:
        if (b->f_7A == 0) {
            func_8013EF0C(b, 0xF);
            b->f_7B = 1;
            func_8013EF00(4);
            D_8014188C = 0x5A;
        }
        break;
    case 4:
        D_80141880_8013FA2C.f_C--;
        b->z = -0x1B40;
        if (D_80141880_8013FA2C.f_C % 10 == 0) {
            s16 x = b->x;
            s20.vx = x - 0xDC;
            s20.vy = b->y - 0x240;
            s20.vz = b->z - 0x40;
            if (D_80141880_8013FA2C.f_C & 8) {
                s20.vx = x + 0xDC;
            }
            func_8013F5A8_8013FA2C(&s20);
            b->f_90 = b->f_91 = 0x20;
        }
        if (D_8014188C == 0) {
            func_8013EF00(5);
            func_8013EF0C(b, 0x10);
        }
        break;
    case 5:
        b->z = -0x1B40;
        if (b->f_7A == 0) {
            func_8013EF00(6);
            func_8013EF0C(b, 0xD);
            Sound_PlayFixed_8013FA2C(0xB4);
        }
        break;
    case 7:
        if (b->f_7A == 0) {
            func_8013EF0C(b, 0x12);
            func_8013EF00(8);
            D_8014188C = 0xF0;
        }
        break;
    case 8:
        D_80141880_8013FA2C.f_C--;
        b->z = -0x1B40;
        if (D_80141880_8013FA2C.f_C == 0xE4) {
            s28.vy = -0xA00;
            s28.vx = b->x;
            s28.vz = b->z + 0x320;
            func_8013E1D0_8013FA2C(&s28, 1, 0);
            func_8013E1D0_8013FA2C(&s28, 0, 0x20);
            func_8013E1D0_8013FA2C(&s28, 4, 0x40);
            func_8013E1D0_8013FA2C(&s28, 4, 0x60);
        }
        if (D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(9);
            func_8013EF0C(b, 0x13);
            Sound_PlayFixed_8013FA2C(0xB3);
        }
        break;
    case 6:
    case 9:
        if (b->f_7A == 0) {
            func_8013EE74();
        }
        break;
    case 12:
        if (D_80141880_8013FA2C.f_10 == 0) {
            func_8013EF00(1);
            func_8013EF0C(b, 3);
            b->f_7B = 1;
            break;
        }
        if (--D_80141880_8013FA2C.f_C == 0) {
            s30.vx = b->x - 0x80;
            s30.vy = b->y - 0xA4;
            s30.vz = b->z - 0x200;
            {
                s32 i;
                for (i = 0; i < 2; i++) {
                    Fx_SpawnFadeRing_8013FA2C(&s30, 1, 0x400, 0);
                    Effect_SpawnAt(0x112, &s30);
                    s30.vx += 0x100;
                }
            }
            func_8013EF00(0xD);
            b->f_88 = 0;
            b->f_8C = 0x20;
            Camera_StartShake(1);
            D_8014188C = 0;
            func_8013EF0C(b, 4);
            func_8013DF60_8013FA2C(0xB1);
            func_8013DF38(0xB2);
            Sound_PlayFixed_8013FA2C(0xAD);
        }
        s38.vx = b->x - 0x80;
        s38.vy = b->y - 0x40;
        s38.vz = b->z - 0x200;
        {
            s32 i;
            for (i = 0; i < 2; i++) {
                Effect_Spawn_8013FA2C(0xC8, &s38, D_80141640_8013FA2C, 0);
                Effect_Spawn_8013FA2C(0xC9, &s38, D_80141640_8013FA2C, 0);
                s38.vx += 0x100;
            }
        }
        Camera_StartShake(0);
        break;
    case 13:
        D_80141880_8013FA2C.f_C++;
        VectorNormalSS(&b->f_88, &b->f_60);
        s58.vx = 0;
        s58.vy = 0;
        s58.vz = -0x1000;
        s40.vx = b->x - 0x80;
        s40.vy = b->y - 0xA4;
        s40.vz = b->z - 0x200;
        s48.vx = b->x - 0x80;
        s48.vy = b->y - 0xA4;
        s48.vz = b->z - 0x5E8;
        s50.vx = b->x - 0x100;
        s50.vy = b->y - 0x40;
        s50.vz = b->z - 0x5E8;
        s48.vx -= b->f_88;
        {
            s32 i;
            for (i = 0; i < 2; i++) {
                SVECTOR *p = &s40;
                Effect_SpawnAt(4, &s50);
                Effect_SpawnAt(5, &s50);
                if ((D_80141880_8013FA2C.f_C & 3) == 1) {
                    func_80070284_8013FA2C(p, D_80141660, 1, 0, &s58);
                }
                func_8006F3D0_8013FA2C(p, 2, D_80141858, 0x20 - D_80141880_8013FA2C.f_C);
                s40.vx += 0x100;
                s48.vx += 0x100;
                s50.vx += 0x200;
            }
        }
        b->x += b->f_88;
        b->z += b->f_8C - (5 - b->f_86) * 2;
        dx = (D_800EC204_8013FA2C.x - b->x) / 256;
        if ((s16)dx >= -3) {
            if ((s16)dx >= 4) {
                dx = 3;
            }
        } else {
            dx = -3;
        }
        { s16 t = dx; b->f_88 = t + b->f_88; }
        if (b->z >= -0x127F) {
            b->f_8C -= 2;
        } else {
            b->f_8C += 4;
        }
        if (b->z >= -0xE7F) {
            b->z = -0xE80;
            Camera_StartShake(1);
            func_8013EF00(0xE);
            D_8014188C = 0x28;
            s60.vx = b->x;
            s60.vy = b->y - 0x80;
            s60.vz = b->z + 0x200;
            func_8013D8E4(&s60);
            func_80070284_8013FA2C(&s60, D_801416B4, 1, 0, &b->f_60);
            {
                s32 i;
                for (i = 0x10; i > 0; i--) {
                    Effect_Spawn_8013FA2C(0xCD, &s60, D_80141640_8013FA2C, 0);
                }
            }
            func_8013EF0C(b, 2);
            b->f_60 = 0;
            b->f_62 = 0;
            b->f_64 = 0x1000;
            func_8013DF60_8013FA2C(0xB2);
            func_8013DF38(0xB1);
            Sound_PlayFixed_8013FA2C(0xAE);
            Sound_PlayFixed_8013FA2C(0x4D);
        }
        D_80142730_8013FA2C.x = b->x;
        D_80142730_8013FA2C.y = b->y + 0x100;
        D_80142730_8013FA2C.z = b->z + 0x200;
        func_8013D890(&D_80142730_8013FA2C, (s32)b, 0x200, 0x200);
        break;
    case 14:
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(0x10);
            func_8013EF0C(b, 3);
            b->f_7B = 1;
            D_80141880_8013FA2C.f_C = 0x1E;
        }
        break;
    case 16:
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013DF60_8013FA2C(0xB1);
            func_8013DF38(0xB2);
            func_8013EF00(0x11);
            if (b->x > 0x600) {
                b->f_7C = 0x2D;
                func_8013EF0C(b, 6);
            } else {
                b->f_7C = -0x2D;
                func_8013EF0C(b, 5);
            }
            b->f_7B = 1;
            D_8014188C = 0x16;
            b->f_8E = 0x10;
            b->f_80 = b->f_7C;
            Sound_PlayFixed_8013FA2C(0xAF);
        }
        break;
    case 17:
        if (b->f_7A == 0) {
            func_8013EF0C(b, b->f_78 + 2);
        }
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(0x12);
            func_8013EF0C(b, b->f_78 + 2);
            b->f_7B = 1;
            D_80141880_8013FA2C.f_C = 0xF;
            func_8013DF60_8013FA2C(0xB2);
            func_8013DF38(0xB1);
        }
        b->x -= (b->f_60 * b->f_8E) >> 12;
        b->z -= (b->f_64 * b->f_8E) >> 12;
        if (b->f_8E < 0x40) {
            b->f_8E += 4;
        }
        s68.vx = b->x + b->f_60 / 8 + ((RAND_8013FA2C() >> 8) - 0x80) * 2;
        s68.vy = b->y - 0x20;
        s68.vz = b->z + b->f_64 / 8 + ((RAND_8013FA2C() >> 8) - 0x80) * 2;
        Effect_SpawnAt(6, &s68);
        break;
    case 18:
        b->f_7C = 0;
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(0x13);
            D_80141880_8013FA2C.f_C = 0x16;
            b->f_8E = 0x10;
            if (b->x < 0x600) {
                func_8013EF0C(b, 5);
            } else {
                func_8013EF0C(b, 6);
            }
            b->f_7B = 1;
            b->f_7C = b->f_80;
            func_8013DF60_8013FA2C(0xB1);
            func_8013DF38(0xB2);
        }
        break;
    case 19:
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(0x14);
            func_8013EF0C(b, 4);
            b->f_88 = (0x600 - b->x) / 32;
            b->f_8C = -0x20;
            b->f_7C = 0;
        }
        b->x += (b->f_60 * b->f_8E) >> 12;
        b->z += (b->f_64 * b->f_8E) >> 12;
        if (b->f_8E < 0x40) {
            b->f_8E += 4;
        }
        break;
    case 20:
        b->x += b->f_88;
        b->z += b->f_8C;
        if (b->z < -0x15D8) {
            {
                s32 i;
                for (i = 0; i < 4; i++) {
                    s70.vx = b->x + ((RAND_8013FA2C() >> 8) - 0x80) * 4;
                    s70.vy = b->y - 0x80;
                    s70.vz = b->z;
                    Effect_SpawnAt(6, &s70);
                }
            }
            b->f_7C = 0x44;
            b->f_8C += 3;
            Camera_StartShake(0);
            if (b->f_78 != 0) {
                Sound_PlayFixed_8013FA2C(0xAF);
            }
            func_8013EF0C(b, 0);
        } else {
            b->f_8C -= 0xA;
        }
        if (b->z < -0x1CB0) {
            b->f_8C = 0;
            b->f_88 = 0;
            func_8013EF00(0x15);
            b->f_7C = 0;
            s78.vx = b->x;
            s78.vy = b->y - 0x60;
            s78.vz = b->z;
            func_80070284_8013FA2C(&s78, D_801416B4, 1, 0, NULL);
            Sound_PlayFixed_8013FA2C(0xAF);
        }
        break;
    case 21:
        b->x += b->f_88;
        b->z += b->f_8C;
        b->f_8C++;
        if (b->z >= -0x1B3F) {
            D_80141880_8013FA2C.f_C = 0x3C;
            b->z = -0x1B40;
            b->f_7C = 0;
            func_8013EE74();
            D_80141880_8013FA2C.f_18 = 0;
            func_8013DF60_8013FA2C(0xB2);
            func_8013DF38(0xB1);
        }
        b->x += b->f_60 >> 8;
        b->z += b->f_64 >> 8;
        break;
    case 24:
        b->x += b->f_88;
        b->f_88 = b->f_88 * 3 / 4;
        if (b->f_88 != 0) {
            Camera_StartShake(1);
        }
        if (--D_80141880_8013FA2C.f_C == 0) {
            func_8013EF00(0x10);
            D_80141880_8013FA2C.f_C = 0x14;
            func_8013DF60_8013FA2C(0xB1);
        }
        break;
    case 25:
        if (--D_80141880_8013FA2C.f_C == 0) {
            D_800E69BE = 1;
            b->f_84 = 0;
        }
        if (D_80141880_8013FA2C.f_C == 0x76) {
            Fx_DebrisExplosion_8013FA2C((s16)b->x, (s16)b->y, (s16)b->z);
            Sound_PlayFixed_8013FA2C(0xB0);
        }
        if (D_80141880_8013FA2C.f_C == 0x5A) {
            memset(&s88, 0, 8);
            s88.vx = b->x;
            s88.vy = b->y - 0x100;
            s88.vz = b->z;
            s80 = s88;
            Effect_SpawnAt(0x112, &s80);
            func_8013EC94(b->x, b->y - 0x100, b->z);
            Fx_GroundBlast_8013FA2C(b->x, b->y - 0x100, b->z);
            Sound_PlayFixed_8013FA2C(0xA8);
            Sound_PlayFixed_8013FA2C(0x6E);
        }
        if (D_80141880_8013FA2C.f_C == 0x62) {
            Sound_PlayFixed_8013FA2C(0x94);
            Sound_PlayFixed_8013FA2C(0x95);
        }
        if ((u32)(D_80141880_8013FA2C.f_C - 0x44) < 5) {
            func_8013F954(0xE6F0FF);
            D_80141880_8013FA2C.f_1D = 1;
            D_80141880_8013FA2C.f_1E = 0xDC;
        }
        if (D_80141880_8013FA2C.f_C == 0x50) {
            memset(&s90, 0, 8);
            s90.vy = -0xA00;
            s90.vx = b->x;
            s90.vz = b->z;
            s88 = s90;
            {
                s32 i;
                for (i = 0; i < 0x18; i++) {
                    Effect_Spawn_8013FA2C(0xCF, &s88, D_80141640_8013FA2C, 0);
                }
            }
            func_8013DF60_8013FA2C(0xB1);
            Sound_PlayFixed_8013FA2C(0xB0);
        }
        if (D_80141880_8013FA2C.f_C < 0x48) {
            u32 cc = D_80141880_8013FA2C.f_1E;
            if (cc != 0) {
                func_8013F954(((cc >> 2) << 16) | ((cc >> 1) << 8) | cc);
                D_80141880_8013FA2C.f_1E -= 4;
            }
        }
        if (D_8014188C == 0x48) {
            memset(&s98, 0, 8);
            s98.vy = -0xA00;
            s98.vx = b->x;
            s98.vz = b->z;
            s90 = s98;
            {
                s32 i;
                for (i = 0; i < 0x1E; i++) {
                    Effect_Spawn_8013FA2C(0xCF, &s90, D_80141640_8013FA2C, 0);
                }
            }
            func_8013D8E4(&s90);
            Fx_SpawnFadeRing_8013FA2C(&s90, 0, 0x800, 5);
            Fx_SpawnFadeRing_8013FA2C(&s90, 0, 0x52C, 8);
            func_80070284_8013FA2C(&s90, D_80141804, 3, 0, NULL);
            s90.vy = -0xA40;
            func_80070284_8013FA2C(&s90, D_80141804 - 0x54, 1, 6, NULL);
            s90.vy = -0xBA4;
            func_80070284_8013FA2C(&s90, D_80141804 - 0x54, 1, 0xD, NULL);
            s90.vy = -0xD20;
            func_80070284_8013FA2C(&s90, D_80141804 - 0x54, 1, 0x16, NULL);
            Sound_PlayFixed_8013FA2C(0x6C);
            Sound_PlayFixed_8013FA2C(0x82);
            Collision_Remove_8013FA2C(&b->x);
            Collision_Remove_8013FA2C(&D_801422F8_8013FA2C.x);
        }
        if ((u32)(D_80141880_8013FA2C.f_C - 0x2F) < 0x15) {
            if (!(D_80141880_8013FA2C.f_C & 7)) {
                Sound_PlayFixed_8013FA2C(0x6C);
            }
            if ((D_80141880_8013FA2C.f_C & 7) == 3) {
                Sound_PlayFixed_8013FA2C(0x95);
            }
        }
        if (D_8014188C >= 0x1F) {
            Camera_StartShake(2);
            func_8013DE6C();
        } else {
            Camera_StartShake(0);
            func_8013DE44();
        }
        break;
    }
    b->x = b->x < 0x80 ? 0x80 : b->x > 0xB80 ? 0xB80 : b->x;
    if ((u32)(D_80141881_8013FA2C - 0xE) < 3 || (u32)(b->f_86 - 1) < 3) {
        {
            s32 i;
            for (i = 2; i >= 0; i--) {
                s80.vx = b->x + ((RAND_8013FA2C() >> 8) - 0x80) * 2;
                s80.vy = b->y - (((RAND_8013FA2C() >> 8) & 0x7F) + 0x80);
                s80.vz = b->z + ((RAND_8013FA2C() >> 8) - 0x80) * 2;
                if (i == 0 && b->f_86 < 3) {
                    func_8006D548_8013FA2C(&s80);
                } else {
                    Effect_SpawnAt(7, &s80);
                }
            }
        }
    }
    if (D_80141880_8013FA2C.f_1 == 0x19) {
        if (D_80141880_8013FA2C.f_1D == 0) {
            func_8013EFCC((u8 *)b);
        }
    } else {
        func_8013EF44(b);
        func_8004637C_8013FA2C(&m);
        RotMatrixY_8013FA2C(b->f_7C, &m);
        ApplyMatrixSV_8013FA2C(&m, &b->f_60, &b->f_60);
        VectorNormalSS(&b->f_60, &b->f_60);
        func_8013EFCC((u8 *)b);
        D_801422F8_8013FA2C.x = b->x;
        D_801422F8_8013FA2C.y = b->y - 0x80;
        D_801422F8_8013FA2C.z = b->z - 0x200;
        if (b->f_93 != 0) {
            b->f_93--;
        }
        if (b->f_92 != 0) {
            b->f_92--;
        }
    }
    if (D_80141880_8013FA2C.f_1 != 0x19 && (D_801422F8_8013FA2C.f_50 >> 28) == 0xB && b->f_93 == 0) {
        Shape_8013FA2C *sh = Collision_GetShape_8013FA2C(M2C_FIELD(b, u16 *, 0x50) & 0xFFF);
        s88.vx = D_801422F8_8013FA2C.x;
        s88.vy = D_801422F8_8013FA2C.y - 0x80;
        s88.vz = D_801422F8_8013FA2C.z - 0x80;
        if ((D_80141880_8013FA2C.f_1 == 0xE || D_80141880_8013FA2C.f_1 == 0x10)
            && (sh->f_24 & 0xFF00) != 0xD00 && (sh->f_24 & 0xFF00) != 0xF00) {
            func_8013D8E4(&s88);
            Camera_StartShake(0);
            Effect_SpawnAt(0x102, &s88);
            Fx_SpawnFadeRing_8013FA2C(&s88, 0, 0x300, 0);
            func_8013EF00(0x18);
            func_8013EF0C(b, 3);
            b->f_7B = 1;
            D_80141880_8013FA2C.f_C = 0x14;
            if (b->x > D_800EC204_8013FA2C.x) {
                b->f_88 = 0x80;
            } else {
                b->f_88 = -0x80;
            }
            Sound_PlayFixed_8013FA2C(0x4D);
            Sound_PlayFixed_8013FA2C(0x82);
            if (--b->f_86 == 0) {
                func_8013E1AC();
                func_8013EF00(0x19);
                D_8014188C = 0x82;
                Spike_SetPlayMode_8013FA2C(0xE);
            }
        } else {
            Effect_SpawnAt(0x117, &s88);
            Camera_StartShake(0);
            Sound_PlayFixed_8013FA2C(0x60);
        }
        func_8013DE1C();
        b->f_93 = 0x10;
    }
    if (D_80141880_8013FA2C.f_1 != 0x19 && (b->f_50 >> 28) == 0xB && !(M2C_FIELD(b, u32 *, 0x90) & 0xFFFF0000)
        && D_80141880_8013FA2C.f_1 != 0xE && D_80141880_8013FA2C.f_1 != 0x18) {
        Shape_8013FA2C *sh = Collision_GetShape_8013FA2C(M2C_FIELD(b, u16 *, 0x50) & 0xFFF);
        s32 id = Collision_GetId_8013FA2C(M2C_FIELD(b, u16 *, 0x50) & 0xFFF);
        s32 c;
        s90.vy = -0xA00;
        s90.vx = b->x;
        s90.vz = b->z;
        func_80070284_8013FA2C(&s90, D_8014175C, 1, 0, NULL);
        c = sh->f_24 & 0xFF00;
        if (c != 0xD00 && c != 0xE00 && c != 0xF00 && id != 2) {
            s98.vy = 0;
            s98.vx = g_Spike_8013FA2C.x - b->x;
            s98.vz = g_Spike_8013FA2C.z - b->z;
            VectorNormalSS(&s98, &s98);
            D_80141880_8013FA2C.f_2 = 0x14;
            D_80141880_8013FA2C.f_4 = s98.vx / 32;
            D_80141880_8013FA2C.f_6 = 0;
            D_80141880_8013FA2C.f_8 = s98.vz / 32;
            Effect_SpawnAt(0x112, D_800B4D88_8013FA2C);
        }
        Camera_StartShake(0);
        Sound_PlayFixed_8013FA2C(0x82);
        Sound_PlayFixed_8013FA2C(0x4B);
        func_8013DE1C();
        b->f_92 = 0x10;
    }
    func_8013DA4C_8013FA2C();
    func_8013ECD4();
    if (D_80141881_8013FA2C != 0x19) {
        func_8013F6F8();
        func_8013E2BC();
        func_8013F0E0();
    }
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
