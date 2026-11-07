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

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D000 asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D000;
extern u8 *D_80144410[];
extern u8 *D_80144438[];
void func_80015BA0(void *, void *);

void func_8013D000(s32 i, void *obj, void *out) {
    u8 *bank = g_Game_8013D000.f_8244;
    AnimEnt_8013D000 *ent;
    u8 *s;
    u32 *q;

    D_80144410[i] = bank + (ent = (AnimEnt_8013D000 *)(i * 32 + (u32)(bank + M2C_FIELD(bank, s32 *, 8))))->f18;
    D_80144438[i] = s = g_Game_8013D000.f_8244 + ent->f1C;
    q = (u32 *)s + 1;
    *(u32 **)out = q;
    M2C_FIELD(obj, u32 **, 0x18) = q + *(u16 *)s;
    func_80015BA0(obj, D_80144410[i]);
}

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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D6BC;
typedef struct { Mat_8013D6BC m; Mat_8013D6BC w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013D6BC;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_8013D6BC;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013D6BC;
extern Part_8013D6BC D_80143F08_8013D6BC[] asm("D_80144C18");
extern Mat_8013D6BC D_800E78C0_8013D6BC asm("D_800E78C0");
extern GameDraw g_Game_8013D6BC asm("g_Game");
void SetRotMatrix_8013D6BC(Mat_8013D6BC *) asm("SetRotMatrix");
void SetTransMatrix_8013D6BC(Mat_8013D6BC *) asm("SetTransMatrix");
void RotMatrixZYX_8013D6BC(SVECTOR *, Mat_8013D6BC *) asm("RotMatrixZYX");
void CompMatrix_8013D6BC(Mat_8013D6BC *, Mat_8013D6BC *, Mat_8013D6BC *) asm("CompMatrix");
#define ADDPRIM_BF_8013D6BC(ot, p) (((PTag_8013D6BC *)(p))->addr = ((PTag_8013D6BC *)(ot))->addr, ((PTag_8013D6BC *)(ot))->addr = (u32)(p))
#define gte_ldv3c_8013D6BC(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_8013D6BC() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_8013D6BC(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_8013D6BC(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
#define SCR_8013D6BC ((Scr_8013D6BC *)0x1F800000)

void func_8013D60C(void) {
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

typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x14]; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0x1E]; u8 f_84[4]; s32 f_88; u8 f_8C; u8 f_8D; u8 f_8E; u8 f_8F; u8 pad90[8]; } Ent_8013DAE8;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[0x1C]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x24]; s16 f_70; s16 f_72; s16 f_74; u8 pad76[2]; } Ent2_8013DAE8;
typedef struct { u16 id; u8 pad2[0x1E]; } Spawn_8013DAE8;
extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013DAE8 asm("g_Game");
extern Ent_8013DAE8 D_80144460_8013DAE8[] asm("D_80144460");
extern Ent2_8013DAE8 D_80144888[];
extern s32 D_801444E4;
extern struct { u8 pad0[8]; s32 f_8; u8 f_C; u8 f_D; u8 f_E; u8 f_F; s16 f_10; u8 pad12[2]; u8 f_14; u8 pad15[7]; u8 f_1C; u8 pad1D; u8 f_1E; u8 f_1F; u8 pad20[4]; s16 f_24; } D_80144BE8_8013DAE8 asm("D_80144BE8");
extern s16 D_800E69BE;
extern u8 D_800AF840;
s32 SaveByte_Get(s32);
void func_801406F8(s32 anim);
void func_8013F86C(void);
void func_8013E4A8(void);
void func_8013D47C(void);
void func_8013E070(void);
void func_8013E7F8(void);
void func_8013F080(void);

void func_8013DAE8(void) {
    u8 *h;
    Spawn_8013DAE8 *sp;
    Ent_8013DAE8 *e;
    Ent2_8013DAE8 *e2;
    s32 i;
    s16 x;

    D_800E69BE = 0;
    h = g_Game_8013DAE8.f_8244;
    if (SaveByte_Get(3) == 5) {
        D_800AF840 = 1;
        return;
    }
    sp = (Spawn_8013DAE8 *)(g_Game_8013DAE8.f_8244 + M2C_FIELD(h, s32 *, 8));
    for (i = 0, e = D_80144460_8013DAE8; i < 7; sp++, i++, e++) {
        func_8013D000(i, e, e->f_84);
        e->f_8C = 1;
        e->f_8F = 6;
        e->f_8E = 6;
        e->f_8D = 0;
        e->f_88 = 0;
        e->x = 0;
        e->y = -0x3000;
        e->z = 0x10B8;
        e->f_60 = 0;
        e->f_62 = 0;
        e->f_64 = -0x1000;
        if (sp->id == 0xD4) {
            Collision_Set(5, &e->x, e);
            e->f_48 = 0;
            e->f_4A = -0x4000;
            e->f_44 = 0x258;
            e->f_46 = 0x384;
        }
    }
    for (i = 0, e2 = D_80144888, e = &D_80144460_8013DAE8[3]; i < 2; i++, e++, e2++) {
        Collision_Set(5, &e2->f_24, e2);
        e2->f_70 = 0x180 - i * 0x300;
        e2->f_4A = -0x4000;
        e2->f_48 = 0;
        e2->f_44 = 0x62;
        e2->f_46 = 0xA0;
        e2->f_72 = -0x3334;
        e2->f_74 = 0x10B8;
        e->f_8F = 2;
        e->f_8E = 2;
    }
    { s32 t = D_801444E4; D_80144BE8_8013DAE8.f_8 = t; }
    func_801406F8(0);
    D_80144BE8_8013DAE8.f_10 = 0x5A;
    D_80144BE8_8013DAE8.f_1E = 3;
    D_80144BE8_8013DAE8.f_14 = 0;
    D_80144BE8_8013DAE8.f_D = 0;
    D_80144BE8_8013DAE8.f_C = 0;
    D_80144BE8_8013DAE8.f_1C = 0;
    D_80144BE8_8013DAE8.f_E = 1;
    D_80144BE8_8013DAE8.f_F = 0;
    D_80144BE8_8013DAE8.f_1F = 0;
    D_80144BE8_8013DAE8.f_24 = 0;
    func_8013F86C();
    func_8013E4A8();
    func_8013D47C();
    func_8013E070();
    func_8013E7F8();
    func_8013F080();
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013DD44;
typedef struct { u8 pad0[0x10]; u8 *verts; u8 pad14[0x14]; s32 y; s32 z; u8 pad30[0x44]; SVECTOR a; SVECTOR b; u8 pad84[0xA]; u8 f_8E; u8 f_8F; u8 pad90[8]; } Part_8013DD44;
extern struct { u8 pad0[0x12]; u16 f_12; s8 f_14; u8 f_15; u8 f_16; u8 pad17[5]; u8 f_1C; u8 f_1D; } D_80144BE8_8013DD44 asm("D_80144BE8");
extern Part_8013DD44 D_801444F8_8013DD44[] asm("D_801444F8");
extern Mat_8013DD44 D_800F4750_8013DD44[] asm("D_800F4750");
extern u8 D_80143D00_8013DD44[] asm("D_80143D00");
s32 func_8013D1FC(u8 *a, void *scale, s32 c);

void func_8013DD44(Part_8013DD44 *e) {
    s32 a;
    s32 c;
    u8 *v;
    Mat_8013DD44 *m;

    if (D_80144BE8_8013DD44.f_14 != 0) {
        if (D_80144BE8_8013DD44.f_16 == 0) {
            e->z -= D_80144BE8_8013DD44.f_14;
        } else {
            e->y -= D_80144BE8_8013DD44.f_14;
        }
        D_80144BE8_8013DD44.f_14 += D_80144BE8_8013DD44.f_15;
        D_80144BE8_8013DD44.f_15 += 8;
        if (D_80144BE8_8013DD44.f_14 > 0) {
            D_80144BE8_8013DD44.f_14 = 0;
        }
    }
    c = 0;
    if (D_80144BE8_8013DD44.f_1C != 0) {
        a = D_80144BE8_8013DD44.f_12 & 0xF;
        if (a >= 8) {
            a = 0xF - a;
        }
        switch (D_80144BE8_8013DD44.f_1D) {
        case 0:
            c = ((a * 12 + 1) << 16) | ((a * 12) << 8) | (a * 16);
            break;
        case 1:
            c = ((a * 16) << 16) | ((a * 12) << 8) | (a * 8 + 1);
            break;
        }
    } else if (e->f_8E == 2 && e->f_8F != 2) {
        a = D_80144BE8_8013DD44.f_12 & 0xF;
        if (a >= 8) {
            a = 0xF - a;
        }
        c = 0x10000 | (a * 16);
    } else if (e->f_8E < 2) {
        a = D_80144BE8_8013DD44.f_12 & 7;
        if (a >= 4) {
            a = 7 - a;
        }
        c = 0x10000 | (a * 32);
    }
    if (func_8013D1FC((u8 *)e, D_80143D00_8013DD44, c) != 0) {
        return;
    }
    if (e == &D_801444F8_8013DD44[0] || e == &D_801444F8_8013DD44[1] || e == &D_801444F8_8013DD44[4] || e == &D_801444F8_8013DD44[5]) {
        ApplyMatrixSV(&D_800F4750_8013DD44[0], e->verts + 0x50, &e->a);
        e->a.vx += D_800F4750_8013DD44[0].t[0];
        e->a.vy += D_800F4750_8013DD44[0].t[1];
        e->a.vz += D_800F4750_8013DD44[0].t[2];
        e->b = e->a;
    } else if (e == &D_801444F8_8013DD44[2] || e == &D_801444F8_8013DD44[3]) {
        v = e->verts;
        m = &D_800F4750_8013DD44[5];
        ApplyMatrixSV(m, v + 0x340, &e->a);
        e->a.vx += m->t[0];
        e->a.vy += m->t[1];
        e->a.vz += m->t[2];
        m += 3;
        ApplyMatrixSV(m, v + 0x480, &e->b);
        e->b.vx += m->t[0];
        e->b.vy += m->t[1];
        e->b.vz += m->t[2];
    }
}

void func_8013E070(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_80144FD8[i].f_6 = 0;
    }
}

typedef struct { s16 x, y, z; u8 f_6; u8 f_7; s16 vx, vy, vz; u8 padE[2]; } Pt_8013E098;
extern Pt_8013E098 D_80144FD8_8013E098[] asm("D_80144FD8");

void func_8013E098(SVECTOR *src) {
    SVECTOR d;
    Pt_8013E098 *p;
    s32 i;

    for (i = 31; i >= 0; i--) {
        p = &D_80144FD8_8013E098[i];
        p->f_6 = 6;
        p->f_7 = RAND() >> 8 & 3;
        p->x = src->vx + ((RAND() >> 8) - 0x80) * 4;
        p->y = src->vy + ((RAND() >> 8) - 0x80) * 4;
        p->z = src->vz + ((RAND() >> 8) - 0x80) * 4;
        d.vx = src->vx - p->x;
        d.vy = src->vy - p->y;
        d.vz = src->vz - p->z;
        p->vx = d.vx / 6;
        p->vy = d.vy / 6;
        p->vz = d.vz / 6;
    }
}

#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
typedef struct { s16 x, y, z; u8 f_6; u8 f_7; s16 vx, vy, vz; u8 padE[2]; } Pt_8013E22C;
extern Pt_8013E22C D_80144FD8_8013E22C[] asm("D_80144FD8");
typedef struct { u32 addr : 24; u32 len : 8; } Tag_8013E22C;
typedef struct { u32 tag; u32 mode; u32 rgb0; s32 xy0; u32 rgb1; s32 xy1; } Line_8013E22C;
extern struct { u8 pad_0[0x4]; Line_8013E22C *f_4; u8 pad_8[4]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013E22C asm("g_Game");

void func_8013E22C(void) {
    SVECTOR v;
    s32 sxy0[1];
    s32 z;
    s32 sxy1[1];
    Pt_8013E22C *p;
    Line_8013E22C *l;
    u32 *ot;
    s32 i;
    u32 c;
    u32 md;
    s32 t;

    for (i = 31; i >= 0; i--) {
        p = &D_80144FD8_8013E22C[i];
        if (p->f_6 != 0) {
            if (p->f_7 != 0) {
                p->f_7--;
            } else {
                p->f_6--;
                p->x += p->vx;
                p->y += p->vy;
                p->z += p->vz;
            }
        }
    }
    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    l = g_Game_8013E22C.f_4;
    ot = (u32 *)(g_Game_8013E22C.f_80 + g_Game_8013E22C.f_C * 0x4078);
    for (i = 31; i >= 0; i--) {
        p = &D_80144FD8_8013E22C[i];
        if (p->f_6 == 0 || p->f_7 != 0) {
            continue;
        }
        gte_ldv0(p);
        gte_rtps();
        gte_stsxy(sxy0);
        gte_stszotz(&z);
        if ((u32)(z - 1) >= 0xFFF) {
            break;
        }
        v.vx = p->x - p->vx * 2;
        v.vy = p->y - p->vy * 2;
        v.vz = p->z - p->vz * 2;
        gte_ldv0(&v);
        gte_rtps();
        gte_stsxy(sxy1);
        c = (u8)(-0x80 - p->f_6 * 8);
        ((u8 *)l)[3] = 5;
        md = 0xE100023C;
        l->rgb0 = (c << 16) | (c << 7) | c | 0x52000000;
        l->xy0 = sxy0[0];
        l->rgb1 = 0;
        t = sxy1[0];
        l->mode = md;
        l->xy1 = t;
        ((Tag_8013E22C *)l)->addr = ((Tag_8013E22C *)&ot[z])->addr;
        ((Tag_8013E22C *)&ot[z])->addr = (u32)l;
        l++;
    }
    g_Game_8013E22C.f_4 = l;
}

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

typedef struct { SVECTOR start; SVECTOR *end; u8 n; u8 pad; u16 seed; } Bolt_8013E564;
extern Bolt_8013E564 D_801451D8_8013E564[] asm("D_801451D8");
extern u8 D_800B1B90[];
void func_8006F3D0(SVECTOR *, s32, void *, s32);

void func_8013E564(void) {
    SVECTOR pts[9];
    SVECTOR b;
    SVECTOR a;
    Bolt_8013E564 *e;
    SVECTOR *p;
    s32 i;
    s32 k;
    s32 t;
    u16 seed;

    for (i = 15, e = D_801451D8_8013E564; i >= 0; i--, e++) {
        if (e->n == 0) {
            continue;
        }
        seed = e->seed;
        a = *e->end;
        b = e->start;
        p = pts;
        for (k = e->n; k > 0; p++, k--) {
            t = k - 1;
            p->vx = (b.vx * t + a.vx * (7 - t)) / 7;
            p->vy = (b.vy * t + a.vy * (7 - t)) / 7;
            p->vz = (b.vz * t + a.vz * (7 - t)) / 7;
            if (k >= 2 && k < e->n) {
                p->vx += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
                p->vy += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
                p->vz += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
            }
        }
        func_8006F3D0(pts, e->n, D_800B1B90, 10);
        e->n--;
    }
}

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

typedef struct { u32 *coll; SVECTOR head; SVECTOR tail; u8 state; u8 kind; s8 size; u8 pad17; u16 timer; u16 age; SVECTOR *tgt; SVECTOR *src; SVECTOR vel; } Rock_8013E8D4;
extern Rock_8013E8D4 D_801452E0_8013E8D4[4] asm("D_801452E0");
extern struct { u8 pad0[0xF]; u8 f_F; u8 pad10[4]; s8 f_14; s8 f_15; u8 f_16; u8 pad17[5]; u8 f_1C; u8 f_1D; u8 f_1E; u8 f_1F; } D_80144BE8_8013E8D4 asm("D_80144BE8");
extern u8 D_80143F6C_8013E8D4[] asm("D_80143F6C");
extern u8 D_80143F00_8013E8D4[] asm("D_80143F00");
typedef struct { u8 b[8]; } Gfx_8013E8D4;
extern Gfx_8013E8D4 D_8014435C_8013E8D4[] asm("D_8014435C");
extern u8 D_80144460_8013E8D4[] asm("D_80144460");
void Fx_DrawFadeRing_8013E8D4(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
s32 VectorNormalSS_8013E8D4(void *, void *) asm("VectorNormalSS");
void Effect_SpawnAt_8013E8D4(s32, void *) asm("Effect_SpawnAt");
void Effect_Spawn_8013E8D4(s32, void *, void *, s32) asm("Effect_Spawn");
void func_80070284_8013E8D4(void *, void *, s32, s32, void *) asm("func_80070284");
s32 Camera_StartShake_8013E8D4(s32) asm("Camera_StartShake");
s32 Sound_PlayFixed_8013E8D4(s32) asm("Sound_PlayFixed");
void func_8006F3D0_8013E8D4(SVECTOR *, s32, void *, s32) asm("func_8006F3D0");
void func_8013D450(void *arg0, s32 arg1, s32 arg2, s16 arg3);
void func_8013DA54(s32 arg0);
void func_80142528(s16 *arg0);
#define RAND_8013E8D4() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013E8D4(void) {
    SVECTOR pts[16];
    Rock_8013E8D4 *e;
    s32 i;
    s32 k;
    s32 j;
    u8 c;

    for (i = 3, e = D_801452E0_8013E8D4; i >= 0; i--, e++) {
        if (e->state == 0) {
            continue;
        }
        switch (e->state) {
        case 1:
            e->tail = *e->src;
            e->head = e->tail;
            e->size = 0x50;
            c = 0x40 - e->timer;
            Fx_DrawFadeRing_8013E8D4(&e->tail, e->timer * 0x18, e->kind + 3, (c << 16) | (c << 8) | c);
            e->timer = e->timer * 3 / 4;
            if (e->timer != 0) {
                break;
            }
            e->vel.vx = e->tail.vx - e->tgt->vx;
            e->vel.vy = e->tail.vy - e->tgt->vy;
            e->vel.vz = e->tail.vz - e->tgt->vz;
            VectorNormalSS_8013E8D4(&e->vel, &e->vel);
            e->state = 2;
            e->age = 0;
            e->size = 0x16;
            e->vel.vx = e->vel.vx / 24;
            e->vel.vy = e->vel.vy / 24;
            e->vel.vz = e->vel.vz / 24;
            if (e->kind == 0) {
                D_80144BE8_8013E8D4.f_15 = -0x20;
                D_80144BE8_8013E8D4.f_14 = -0x20;
                D_80144BE8_8013E8D4.f_16 = 0;
            }
            Effect_SpawnAt_8013E8D4(0x114 - e->kind, &e->tail);
            func_80070284_8013E8D4(&e->tail, D_80143F6C_8013E8D4 + e->kind * 0x54, 1, 0, &e->vel);
            Camera_StartShake_8013E8D4(0);
            if (e->kind == 0) {
                D_80144BE8_8013E8D4.f_1D = 0;
                D_80144BE8_8013E8D4.f_1C = ((RAND_8013E8D4() >> 8) & 7) + 9;
                Sound_PlayFixed_8013E8D4(0x8F);
                Sound_PlayFixed_8013E8D4(0x77);
                Sound_PlayFixed_8013E8D4(0x93);
            } else {
                Sound_PlayFixed_8013E8D4(0xA0);
            }
            break;
        case 2:
            e->age++;
            if (e->kind == 0) {
                if (D_80144BE8_8013E8D4.f_F == 1) {
                    if (e->size < 0x5C) {
                        e->size += 8;
                    }
                    Effect_SpawnAt_8013E8D4(0x2F, &e->head);
                    Fx_DrawFadeRing_8013E8D4(&e->head, ((RAND_8013E8D4() >> 8) & 0x7F) + 0x50, 3, 0x606060);
                } else if (e->size < 0x2C) {
                    e->size += 4;
                }
            } else if (e->size < 0x22) {
                e->size += 3;
            }
            e->head.vx += e->vel.vx;
            e->head.vy += e->vel.vy;
            e->head.vz += e->vel.vz;
            Effect_Spawn_8013E8D4(e->kind + 0xC8, &e->head, D_80143F00_8013E8D4, 0);
            if (e->head.vy >= -0x3000 || e->age >= 0x20 || (e->coll != NULL && (e->coll[0xB] >> 28) == 6)) {
                if (((e->head.vy + 0x3020) < 0 ? -0x3020 - e->head.vy : (e->head.vy + 0x3020)) < 0x100) {
                    e->head.vy = -0x3020;
                }
                e->state = 3;
                e->timer = e->age;
                Effect_SpawnAt_8013E8D4(0x114 - e->kind, &e->head);
                func_80070284_8013E8D4(&e->head, D_80143F6C_8013E8D4 + e->kind * 0x54, 1, 0, 0);
                if (e->kind == 1) {
                    if (((RAND_8013E8D4() >> 8) & 3) < 3) {
                        D_80144BE8_8013E8D4.f_1F = 1;
                        func_8013DA54((s32)&e->head);
                    }
                    if ((RAND_8013E8D4() >> 8) & 1) {
                        D_80144BE8_8013E8D4.f_1F = 1;
                        func_8013DA54((s32)&e->head);
                    }
                }
                if (D_80144BE8_8013E8D4.f_F == 1 && e->kind == 0) {
                    func_80142528(&e->head.vx);
                }
            } else {
                func_8013D450(e, (s32)D_80144460_8013E8D4, 0x50, 0x200);
            }
            break;
        case 3:
            e->tail.vx += e->vel.vx;
            e->tail.vy += e->vel.vy;
            e->tail.vz += e->vel.vz;
            e->size -= 10;
            if (e->size < 8) {
                e->size = 8;
            }
            if (--e->timer == 0) {
                e->state = 0;
            }
            break;
        }
    }
    for (i = 3, e = D_801452E0_8013E8D4; i >= 0; i--, e++) {
        if (e->state != 0) {
            SVECTOR *q = pts;
            *q = e->tail;
            for (k = 16; k > 0; k--) {
                q->vx = (e->tail.vx * k + e->head.vx * (16 - k)) / 16;
                q->vy = (e->tail.vy * k + e->head.vy * (16 - k)) / 16;
                q->vz = (e->tail.vz * k + e->head.vz * (16 - k)) / 16;
                q++;
            }
            func_8006F3D0_8013E8D4(pts, 16, &D_8014435C_8013E8D4[e->kind], e->size);
        }
    }
}

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

/* 3 diffs (hand) */
typedef struct { u8 pad0[4]; s16 x, y, z; u8 f_A; u8 pad_B; s16 f_C, f_E, f_10; u8 pad12[2]; } Bit_8013F0A4;
extern Bit_8013F0A4 D_80145390_8013F0A4[8] asm("D_80145390");
extern u16 g_RandSeed_8013F0A4 asm("g_RandSeed");
void Effect_SpawnAt(s32, void *);
#define RAND_8013F0A4() (g_RandSeed_8013F0A4 = g_RandSeed_8013F0A4 * 5 + 1)
typedef struct { u8 pad[0x7C]; s16 x, y, z; } Src_8013F0A4;

void func_8013F0A4(Src_8013F0A4 *a0) {
    s32 i;
    Bit_8013F0A4 *e;

    i = 7;
    e = D_80145390_8013F0A4;
    do {
        if (e->f_A == 0) {
            e->f_A = 1;
            M2C_FIELD(e, s16 *, 4) = a0->x + ((RAND_8013F0A4() >> 8) - 0x80);
            e->y = a0->y;
            e->z = a0->z + ((RAND_8013F0A4() >> 8) - 0x80);
            e->f_C = 0;
            e->f_10 = 0;
            e->f_E = -0x60 - ((RAND_8013F0A4() >> 8) & 0x3F);
            Effect_SpawnAt(0x112, &e->x);
            return;
        }
        i--;
        e++;
    } while (i >= 0);
}

typedef struct { u8 pad0[4]; s16 x, y, z; u8 state; u8 pad_B; s16 vx, vy, vz; u16 timer; } Rock_8013F198;
extern Rock_8013F198 D_80145390_8013F198[8] asm("D_80145390");
extern u16 g_RandSeed_8013F198 asm("g_RandSeed");
extern struct { u8 pad0[0x1F]; u8 f_1F; } D_80144BE8_8013F198 asm("D_80144BE8");
extern u8 D_80143F00_8013F198[] asm("D_80143F00");
extern u8 D_80144260_8013F198[] asm("D_80144260");
extern u8 D_80144460_8013F198[] asm("D_80144460");
void Effect_SpawnAt_8013F198(s32, void *) asm("Effect_SpawnAt");
void Effect_Spawn_8013F198(s32, void *, void *, s32) asm("Effect_Spawn");
void Fx_DrawFadeRing_8013F198(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
s32 Camera_StartShake_8013F198(s32) asm("Camera_StartShake");
s32 Sound_PlayFixed_8013F198(s32) asm("Sound_PlayFixed");
s32 func_80070284_8013F198(void *, void *, s32, s32, s32) asm("func_80070284");
void *memset_8013F198(void *, s32, s32) asm("memset");
#define RAND_8013F198() (g_RandSeed_8013F198 = g_RandSeed_8013F198 * 5 + 1)

void func_8013F198(void) {
    s32 i;
    Rock_8013F198 *e;
    SVECTOR b;
    SVECTOR a;
    s16 vy;

    for (i = 7, e = D_80145390_8013F198; i >= 0; i--, e++) {
        if (e->state == 0) {
            continue;
        }
        switch (e->state) {
        case 1:
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            if (e->y < -0x4200) {
                e->state = 2;
                e->vy = 0;
                e->x = ((RAND_8013F198() >> 8) - 0x80) * 12;
                e->z = (RAND_8013F198() >> 8) * 4 + 0x6CD;
                memset_8013F198(&a, 0, 8);
                a.vx = e->x;
                a.vy = -0x3020;
                a.vz = e->z;
                b = a;
                func_80070284_8013F198(&b, D_80144260_8013F198, 2, 0x14, 0);
            }
            break;
        case 2:
            e->x += e->vx;
            e->y += e->vy;
            vy = e->vy + 7;
            e->vy = vy;
            e->z += e->vz;
            if (vy >= 0x80) {
                e->vy = 0x80;
            }
            if (e->y >= -0x3000) {
                e->y = -0x3020;
                e->state = 3;
                e->timer = 0x28;
                Effect_SpawnAt_8013F198(0x112, &e->x);
                Camera_StartShake_8013F198(0);
                Sound_PlayFixed_8013F198(0x4D);
            }
            func_8013D450(e, (s32)D_80144460_8013F198, 0x80, 0x200);
            break;
        case 3:
            if (--e->timer == 0) {
                e->state = 0;
                if ((RAND_8013F198() >> 8) & 1) {
                    if (D_80144BE8_8013F198.f_1F == 0) {
                        D_80144BE8_8013F198.f_1F = 1;
                        func_8013DA54((s32)&e->x);
                    }
                }
            }
            Effect_Spawn_8013F198(0xCB, &e->x, D_80143F00_8013F198, 0);
            Effect_Spawn_8013F198(0xCC, &e->x, D_80143F00_8013F198, 0);
            func_8013D450(e, (s32)D_80144460_8013F198, 0x80, 0x200);
            break;
        }
        if (e->state != 3) {
            Fx_DrawFadeRing_8013F198(&e->x, ((RAND_8013F198() >> 8) & 0x7F) + 0x40, 5, 0x404040);
            Fx_DrawFadeRing_8013F198(&e->x, ((RAND_8013F198() >> 8) & 0x3F) + 0x30, 1, 0x404040);
            if (e->y >= -0x39FF) {
                e->y += 0x60;
                Effect_Spawn_8013F198(0xCB, &e->x, D_80143F00_8013F198, 0);
                Effect_Spawn_8013F198(0xCC, &e->x, D_80143F00_8013F198, 0);
                Effect_Spawn_8013F198(0xCC, &e->x, D_80143F00_8013F198, 0);
                e->y -= 0x60;
            }
        }
    }
}

extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F598 asm("g_Spike");
extern struct { u8 pad0[0xF]; u8 f_F; u8 pad10[0x16]; u16 f_26; s16 f_28; s16 f_2A; s16 f_2C; } D_80144BE8_8013F598 asm("D_80144BE8");
extern s32 D_8014420C;
extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[6]; u16 z; } g_Spike_8013F598h asm("g_Spike");
extern u8 D_800B4D88[];
s32 VectorNormalSS_8013F598(void *, void *) asm("VectorNormalSS");
void Effect_SpawnAt(s32, void *);

void func_8013F598(u8 *obj) {
    SVECTOR v;
    SVECTOR s;
    s32 vx, vz;
    s32 f;
    s32 t;

    if (D_80144BE8_8013F598.f_26 != 0) {
        vx = D_80144BE8_8013F598.f_28;
        vz = D_80144BE8_8013F598.f_2C;
        D_80144BE8_8013F598.f_26--;
        g_Spike_8013F598.x += vx;
        g_Spike_8013F598.z += vz;
        D_80144BE8_8013F598.f_28 = vx * 7 / 8;
        D_80144BE8_8013F598.f_2C = vz * 7 / 8;
        if (g_Spike_8013F598.z < 0x73A) {
            g_Spike_8013F598.z = 0x73A;
        }
    }
    v.vx = g_Spike_8013F598h.x - M2C_FIELD(obj, u16 *, 0x24);
    v.vy = 0;
    v.vz = g_Spike_8013F598h.z - M2C_FIELD(obj, u16 *, 0x2C);
    if (D_80144BE8_8013F598.f_26 != 0) {
        return;
    }
    if (VectorNormalSS_8013F598(&v, &v) > 0x70E3F) {
        return;
    }
    f = D_80144BE8_8013F598.f_F;
    if (f == 1) {
        t = 4;
    } else {
        t = 0x14;
    }
    D_80144BE8_8013F598.f_26 = t;
    D_80144BE8_8013F598.f_2A = 0;
    D_80144BE8_8013F598.f_28 = v.vx / 20;
    D_80144BE8_8013F598.f_2C = v.vz / 20;
    if (f == 0) {
        s.vx = 0;
        s.vy = -0x3000;
        s.vz = 0x10B8;
        func_80070284(&s.vx, &D_8014420C, 1, 0, 0);
        Effect_SpawnAt(0x112, D_800B4D88);
        Sound_PlayFixed(0x82);
        Sound_PlayFixed(0x4B);
    }
}

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

typedef struct { u8 pad0[0x92]; u8 f92, f93; u8 pad94[8]; s16 f9C; u8 pad9E[2]; } Ent_8013F964;
extern Ent_8013F964 D_80144AA8_8013F964[2] asm("D_80144AA8");
extern u8 D_80144BF7;
extern s32 D_800EC204;

void func_8013F964(void) {
    s32 i;
    Ent_8013F964 *e;

    if (D_80144BF7 == 1) {
        e = D_80144AA8_8013F964;
        if (D_800EC204 > 0) {
            e++;
        }
        if (e->f92 == 3) {
            e->f92 = 4;
            e->f9C = 0;
            e->f93 = 1;
        }
        return;
    }
    for (i = 0, e = D_80144AA8_8013F964; i < 2; i++, e++) {
        if (e->f92 == 3) {
            e->f92 = 4;
            e->f9C = 0;
            e->f93 = 1;
        }
    }
}

typedef struct { u8 pad0[0x74]; SVECTOR pos; u8 pad7C[0x24]; } Ent_8013F9FC;
extern Ent_8013F9FC D_80144AA8_8013F9FC[2] asm("D_80144AA8");
extern u8 D_80143F00[];

void func_8013F9FC(void) {
    s32 i;
    s32 j;
    Ent_8013F9FC *e;

    for (i = 0, e = D_80144AA8_8013F9FC; i < 2; i++, e++) {
        Effect_SpawnAt(0x102, &e->pos);
        Fx_SpawnFadeRing(&e->pos, 0, 0x200, 0);
        for (j = 0; j < 12; j++) {
            Effect_Spawn(0xCD, &e->pos, D_80143F00, 0);
        }
    }
    Sound_PlayFixed(0xBA);
}

typedef struct { s32 vx, vy, vz, pad; } Vec_8013FAA4;
typedef struct { u16 lo, hi; } Rng_8013FAA4;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x2C]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[0xC]; s16 f_74; s16 f_76; s16 f_78; u8 pad_7A[2]; s16 f_7C; s16 f_7E; s16 f_80; u8 pad_82[2]; s16 f_84; s16 f_86; s16 f_88; u8 pad_8A[2]; Rng_8013FAA4 *f_8C; u16 f_90; u8 state; u8 f_93; s16 vx; s16 vy; s16 vz; s16 f_9A; u16 f_9C; u8 pad_9E[2]; } Boss_8013FAA4;
extern Boss_8013FAA4 D_80144AA8_8013FAA4[2] asm("D_80144AA8");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013FAA4 asm("g_Spike");
extern u8 D_80144014_8013FAA4[] asm("D_80144014");
extern u8 D_80144384_8013FAA4[] asm("D_80144384");
extern u16 D_800AE8F2;
const Vec_8013FAA4 D_80143C50 = { 0x1000, 0x1000, 0x1000, 0 };
void Effect_SpawnAt_8013FAA4(s32, void *) asm("Effect_SpawnAt");
s32 Sound_PlayFixed_8013FAA4(s32) asm("Sound_PlayFixed");
s32 VectorNormalSS_8013FAA4(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
void Shadow_Draw_8013FAA4(void *, s32, s32, s32) asm("Shadow_Draw");
void func_80070284_8013FAA4(void *, void *, s32, s32, void *) asm("func_80070284");
void func_8013E4D0(SVECTOR *pos, s32 b);
void func_8013E81C(u8 *a0, s32 a1);
void func_8013F75C(void *arg0, s32 anim);
#define RAND_8013FAA4() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2_8013FAA4() (D_800AE8F2 = D_800AE8F2 * 5 + 1)

void func_8013FAA4(void) {
    SVECTOR v;
    Vec_8013FAA4 sc;
    Boss_8013FAA4 *p;
    s32 i;
    s32 j;
    Rng_8013FAA4 *a;

    for (i = 0, p = D_80144AA8_8013FAA4; i < 2; i++, p++) {
        p->f_84 = p->x;
        p->f_86 = p->y;
        p->f_88 = p->z;
        if (++p->f_5C > p->f_8C[p->f_90].hi) {
            p->f_5C = p->f_8C[p->f_90].lo;
        }
        switch (p->state) {
        case 0:
            break;
        case 1:
            if (!(p->f_9C & 3)) {
                v.vx = p->f_84 + ((RAND_8013FAA4() >> 8) - 0x80) * 8;
                v.vy = p->f_86 - (RAND_8013FAA4() >> 8) * 8;
                v.vz = (RAND_8013FAA4() >> 8) * 8 + 0x7D2;
                func_8013E4D0(&v, (s32)&p->f_84);
            }
            if (!(p->f_9C & 7)) {
                Effect_SpawnAt_8013FAA4(0x112, &p->f_84);
            }
            if (p->f_9C >= 9) {
                for (j = 20; j > 0; j--) {
                    Effect_SpawnAt_8013FAA4(6, &p->f_84);
                }
                Effect_SpawnAt_8013FAA4(0x112, &p->f_84);
                func_80070284_8013FAA4(&p->f_84, D_80144014_8013FAA4, 1, 0, &p->f_60);
                p->state = 2;
                p->f_9C = 0;
                Sound_PlayFixed_8013FAA4(0x74);
            }
            break;
        case 2:
            if (!(p->f_9C & 3)) {
                Sound_PlayFixed_8013FAA4(0x5B);
            }
            if (p->f_9C >= 0x1F) {
                p->state = 3;
                p->f_9A = i * 0xC58 - 0x62C;
                Sound_PlayFixed_8013FAA4(0x2E);
            }
            if (p->f_9C < 0x14 && !(p->f_9C & 3)) {
                v.vx = p->f_84 + ((RAND_8013FAA4() >> 8) - 0x80) * 2;
                v.vy = p->f_86 - ((RAND_8013FAA4() >> 8) - 0x80) * 2;
                v.vz = (RAND_8013FAA4() >> 8) * 2 + 0xAD2;
                func_8013E4D0(&v, (s32)&p->f_84);
            }
            break;
        default:
        case 3:
            if (((RAND2_8013FAA4() >> 8) & 0x3F) < 3) {
                p->vx = ((RAND_8013FAA4() >> 8) - 0x80) / 2;
                p->vy = ((RAND_8013FAA4() >> 8) - 0x80) / 2;
                p->vz = ((RAND_8013FAA4() >> 8) - 0x80) / 2;
            }
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            v.vx = p->f_9A - p->x;
            v.vy = -0x3300 - p->y;
            v.vz = 0xBD2 - p->z;
            if (VectorNormalSS_8013FAA4(&v, &v) > 0x4000) {
                p->x += v.vx / 128;
                p->y += v.vy / 128;
                p->z += v.vz / 128;
            }
            p->vx = p->vx * 63 / 64;
            p->vy = p->vy * 63 / 64;
            p->vz = p->vz * 63 / 64;
            break;
        case 4:
            if (p->f_93 == 0) {
                p->state = 5;
                func_8013F75C(p, 1);
                p->f_9C = 0;
            }
            break;
        case 5:
            if (p->f_9C < 0x46 && !((RAND_8013FAA4() >> 8) & 3)) {
                Sound_PlayFixed_8013FAA4(0x5B);
            }
            if (p->f_9C < 0x50 && !(p->f_9C & 3)) {
                v.vx = p->f_84 + ((RAND_8013FAA4() >> 8) - 0x80) * 2;
                v.vy = p->f_86 - ((RAND_8013FAA4() >> 8) - 0x80) * 2;
                v.vz = (RAND_8013FAA4() >> 8) * 2 + 0xAD2;
                func_8013E4D0(&v, (s32)&p->f_84);
            }
            if (p->f_9C == 0x50) {
                func_8013E81C((u8 *)p, 1);
                p->state = 6;
                p->f_9C = 0;
            }
            break;
        case 6:
            if (p->f_9C >= 0x3C) {
                p->state = 3;
                func_8013F75C(p, 0);
            }
            break;
        }
        if (p->state - 4 < 2u) {
            v.vx = g_Spike_8013FAA4.x - p->x;
            v.vy = -0x3320 - p->y;
            v.vz = g_Spike_8013FAA4.z - p->z;
            VectorNormalSS_8013FAA4(&v, &v);
            p->x += v.vx / 256;
            p->y += v.vy / 256;
            p->z += v.vz / 256;
        }
        v.vx = p->x - p->f_9A;
        v.vy = p->y + 0x3300;
        v.vz = p->z - 0xBD2;
        if (VectorNormalSS_8013FAA4(&v, &v) > 0x15F900) {
            p->x = p->f_9A + ((v.vx * 75) >> 8);
            p->y = ((v.vy * 75) >> 8) - 0x3300;
            p->z = ((v.vz * 75) >> 8) + 0xBD2;
        }
        if (p->y > -0x3080) {
            p->y = -0x3080;
        }
        if (p->state != 6) {
            p->f_60.vx = g_Spike_8013FAA4.x - p->x;
            p->f_60.vy = g_Spike_8013FAA4.y - p->y;
            p->f_60.vz = g_Spike_8013FAA4.z - p->z;
            VectorNormalSS_8013FAA4(&p->f_60, &p->f_60);
            p->f_74 = p->x;
            p->f_76 = p->y;
            p->f_78 = p->z;
            p->f_7C = p->x + p->f_60.vx / 64;
            p->f_7E = p->y + p->f_60.vy / 64;
            p->f_80 = p->z + p->f_60.vz / 64;
        }
        switch (p->state) {
        case 0:
        case 1:
            break;
        default:
            p->f_93 = func_8013D1FC((u8 *)p, D_80144384_8013FAA4, 0);
            Shadow_Draw_8013FAA4(&p->x, -0x3010, 0x80, 0);
            break;
        case 2:
            {
            u8 c2 = (p->f_9C & 1) * 255;
            sc = D_80143C50;
            if (p->f_9C < 8) {
                sc.vx = p->f_9C << 4;
                sc.vy = ((8 - p->f_9C) << 12) + 0x1000;
                sc.vz = 0x1000;
            }
            func_8013D1FC((u8 *)p, &sc, ((u8)~c2 << 16) | (u8)c2);
            }
            break;
        }
        p->f_9C++;
    }
}

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

extern struct { u32 f_0; } g_Game_8014063C asm("g_Game");
extern struct { u8 pad_0[0x24]; u16 f_24; } D_80144BE8_8014063C asm("D_80144BE8");

void func_8014063C(void) {
    s32 n;

    if (D_80144BE8_8014063C.f_24 == 0) {
        n = (g_Game_8014063C.f_0 / 6) % 10;
    } else {
        D_80144BE8_8014063C.f_24--;
        n = D_80144BE8_8014063C.f_24 % 10;
    }
    if (n >= 5) {
        n = 9 - n;
    }
    func_80140564(n);
}

extern struct { u16 cur; u8 pad2[2]; u16 f_4; u8 f_6; u8 f_7; u8 *tbl; } D_80144BE8_801406F8 asm("D_80144BE8");

void func_801406F8(s32 anim) {
    if (D_80144BE8_801406F8.cur != anim) {
        D_80144BE8_801406F8.cur = anim;
        D_80144BE8_801406F8.f_4 = *(u16 *)(anim * 4 + D_80144BE8_801406F8.tbl);
        D_80144BE8_801406F8.f_6 = 1;
        D_80144BE8_801406F8.f_7 = 0;
    }
}

typedef struct { u16 start; u16 end; } Rng_80140738;
extern struct { u16 anim; u16 pad2; u16 frame; u8 f_6; u8 f_7; Rng_80140738 *tbl; } D_80144BE8_80140738 asm("D_80144BE8");
#define A_80140738 D_80144BE8_80140738

void func_80140738(void) {
    u16 old = A_80140738.frame;
    u16 n;
    Rng_80140738 *r;

    n = old + 1;
    A_80140738.frame = n;
    r = (Rng_80140738 *)(A_80140738.anim * 4 + (s32)A_80140738.tbl);
    if (n == r->end) {
        A_80140738.f_6 = 0;
    }
    if (r->end < n) {
        if (A_80140738.f_7 == 1) {
            A_80140738.frame = old;
            return;
        }
        A_80140738.frame = r->start;
    }
}

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

extern struct { u8 pad_0[0xC]; s8 f_C; u8 pad_D[3]; s16 f_10; u8 pad_12[5]; u8 f_17; s32 f_18; } D_80144BE8_801409AC asm("D_80144BE8");

void func_801409AC(void) {
    D_80144BE8_801409AC.f_C = 0xA;
    D_80144BE8_801409AC.f_10 = 0x5A;
    func_801406F8(D_80144BE8_801409AC.f_17 + 9);
    func_80070284((s16 *)(D_80144BE8_801409AC.f_18 + 0x7C), (M2C_UNK *)D_80143F18, 1, 0, D_80144BE8_801409AC.f_18 + 0x60);
    Sound_PlayFixed(0x27);
    Sound_PlayFixed(0x28);
}

extern struct { u8 pad0[0xC]; u8 f_C; u8 padD; u8 f_E; u8 padF; s16 f_10; } D_80144BE8_80140A20 asm("D_80144BE8");

void func_80140A20(void) {
    func_8014092C();
    D_80144BE8_80140A20.f_C = 1;
    D_80144BE8_80140A20.f_10 = 0;
    D_80144BE8_80140A20.f_E = 0;
    func_80140630(0x32);
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80140A60;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x20]; u32 f_50; u8 pad_54[8]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[0xC]; SVECTOR f_74; SVECTOR f_7C; u16 *f_84; u8 pad_88[4]; u8 f_8C; u8 pad_8D; u8 f_8E; u8 pad_8F; s16 f_90; s16 f_92; s16 f_94; u16 f_96; } Part_80140A60;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x20]; u32 f_50; u8 pad_54[0x1C]; SVECTOR f_70; } Coll_80140A60;
typedef struct { u16 anim; u8 pad_2[2]; u16 f_4; u8 f_6; u8 f_7; u16 *f_8; u8 f_C; u8 f_D; u8 f_E; u8 f_F; s16 f_10; u16 f_12; s8 f_14; s8 f_15; u8 f_16; u8 f_17; Part_80140A60 *f_18; u8 f_1C; u8 f_1D; u8 f_1E; u8 f_1F; } St_80140A60;
typedef struct { u8 pad_0[0x24]; s16 f_24; } Shape_80140A60;
extern St_80140A60 D_80144BE8_80140A60 asm("D_80144BE8");
extern Part_80140A60 D_80144460_80140A60[] asm("D_80144460");
extern Coll_80140A60 D_80144888_80140A60[] asm("D_80144888");
extern u8 D_80144BEE_80140A60 asm("D_80144BEE");
extern s16 D_80144BF8_80140A60 asm("D_80144BF8");
extern s16 D_801444A4_80140A60 asm("D_801444A4");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80140A60 asm("g_Spike");
extern u8 D_80143F00_80140A60[] asm("D_80143F00");
extern u8 D_80144014_80140A60[] asm("D_80144014");
extern u8 D_801440BC_80140A60[] asm("D_801440BC");
extern u8 D_80144164_80140A60[] asm("D_80144164");
extern u8 D_8014436C_80140A60[] asm("D_8014436C");
extern u8 D_80144378_80140A60[] asm("D_80144378");
s32 Sound_PlayFixed_80140A60(s32) asm("Sound_PlayFixed");
void Camera_StartShake_80140A60(s32) asm("Camera_StartShake");
void Effect_Spawn_80140A60(s32, void *, void *, s32) asm("Effect_Spawn");
void Fx_SpawnFadeRing_80140A60(void *, s32, s32, s32) asm("Fx_SpawnFadeRing");
void Fx_DrawFadeRing_80140A60(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
void func_80070284_80140A60(void *, void *, s32, s32, void *) asm("func_80070284");
void func_80070130_80140A60(void *, void *, s32, s32, s32, s32) asm("func_80070130");
void func_800702B0_80140A60(void *, void *) asm("func_800702B0");
void Pickup_Drop_80140A60(s32, void *, s32, s32) asm("Pickup_Drop");
Shape_80140A60 *Collision_GetShape_80140A60(s32) asm("Collision_GetShape");
s32 Collision_GetId_80140A60(s32) asm("Collision_GetId");
void Collision_Remove_80140A60(void *) asm("Collision_Remove");
void RotMatrix_80140A60(void *, void *) asm("RotMatrix");
void *ApplyMatrixSV_80140A60(void *, void *, void *) asm("ApplyMatrixSV");
s32 VectorNormalSS_80140A60(void *, void *) asm("VectorNormalSS");
void *memset_80140A60(void *, s32, s32) asm("memset");
void func_8013D000(s32 i, void *obj, void *out);
void func_8013D4A4(SVECTOR *arg0);
void func_8013D60C_80140A60(void) asm("func_8013D60C");
void func_8013D9DC(void);
void func_8013DA04(void);
void func_8013DD44_80140A60(void *) asm("func_8013DD44");
void func_8013E22C_80140A60(void) asm("func_8013E22C");
void func_8013E4D0_80140A60(void *, void *) asm("func_8013E4D0");
void func_8013E564(void);
void func_8013E8D4(void);
void func_8013F0A4_80140A60(void *) asm("func_8013F0A4");
void func_8013F198(void);
void func_8013F598(u8 *obj);
void func_8013F78C(u8 *e, s16 a1, s16 a2, s16 a3);
void func_8013F930(void);
void func_8013F964(void);
void func_8013FAA4_80140A60(void) asm("func_8013FAA4");
void func_80140630(s16 arg0);
void func_8014063C(void);
void func_80140738(void);
void func_801407B4(s32 n);
void func_8014081C(void);
void func_801408AC(s32 arg0, s32 arg1);
void func_8014092C(void);
void func_801409AC(void);
void func_80141F70(void);
void func_80142C40_80140A60(void) asm("func_80142C40");
#define RAND_80140A60() (g_RandSeed = g_RandSeed * 5 + 1)
#define ST_80140A60 D_80144BE8_80140A60
#define PT_80140A60 D_80144460_80140A60

void func_80140A60(void) {
    SVECTOR v18;
    SVECTOR v20;
    SVECTOR v28;
    SVECTOR v30;
    SVECTOR v38;
    SVECTOR *sc = (SVECTOR *)0x1F800000;
    s32 i;
    Part_80140A60 *q;
    Part_80140A60 *p;

    if (ST_80140A60.f_F == 1) {
        if (ST_80140A60.f_E == 0) {
            func_80142C40_80140A60();
        }
        return;
    }
    switch (ST_80140A60.f_C) {
    case 1:
        ST_80140A60.f_10++;
        if (ST_80140A60.f_10 < 0x30 && !(*(volatile s16 *)&ST_80140A60.f_10 & 7)) {
            Sound_PlayFixed_80140A60(0x6A);
        }
        if (ST_80140A60.f_6 == 0) {
            func_801408AC(0x1E, 0xA);
        }
        if (ST_80140A60.f_10 == 0x32) {
            func_8013F930();
            Camera_StartShake_80140A60(1);
            Sound_PlayFixed_80140A60(0xC);
            Sound_PlayFixed_80140A60(0x80);
        }
        break;
    case 0:
        func_801406F8(0);
        if (ST_80140A60.f_E == 0 && --ST_80140A60.f_10 == 0) {
            s32 n = 0x40;
            u8 r;

            do {
                r = (RAND_80140A60() >> 8) & 3;
            } while (ST_80140A60.f_1E == r && --n > 0);
            func_801407B4(ST_80140A60.f_17 ^ 1);
            if ((PT_80140A60[3].f_8C != 1 || PT_80140A60[4].f_8C != 1) && r == 2) {
                r = 0;
            }
            ST_80140A60.f_1E = r;
            ST_80140A60.f_1F = 0;
            func_80140630(0x1E);
            switch (r) {
            case 0:
                func_801406F8(ST_80140A60.f_17 + 3);
                ST_80140A60.f_C = 4;
                Sound_PlayFixed_80140A60(0x74);
                Sound_PlayFixed_80140A60(0x8E);
                break;
            case 1:
                func_801406F8(ST_80140A60.f_17 + 5);
                ST_80140A60.f_7 = 1;
                ST_80140A60.f_C = 6;
                ST_80140A60.f_10 = 0;
                Sound_PlayFixed_80140A60(0x74);
                Sound_PlayFixed_80140A60(0x8E);
                break;
            case 2:
                func_801406F8(2);
                ST_80140A60.f_C = 3;
                Sound_PlayFixed_80140A60(0x82);
                break;
            case 3:
                func_8014092C();
                ST_80140A60.f_10 = 0;
                break;
            }
            if ((RAND_80140A60() >> 8) & 1) {
                func_8014081C();
            }
            func_80140498(2);
        }
        break;
    case 2:
        ST_80140A60.f_10++;
        if (ST_80140A60.f_6 == 0) {
            func_801408AC(0x46, 0x1E);
        }
        if (ST_80140A60.f_10 < 0x30 && !(*(volatile s16 *)&ST_80140A60.f_10 & 7)) {
            Sound_PlayFixed_80140A60(0x6A);
        }
        if (D_80144BF8_80140A60 == 0x1E) {
            func_8013F964();
        }
        break;
    case 3:
        if (++ST_80140A60.f_10 < 0x2D) {
            for (i = 0; i < 2; i++) {
                *sc = PT_80140A60[i + 3].f_7C;
                Effect_SpawnAt(6, sc);
                if (!((RAND_80140A60() >> 8) & 3)) {
                    func_800702B0_80140A60(sc, D_80144378_80140A60);
                }
            }
        } else if (ST_80140A60.f_10 == 0x2D) {
            s32 i;

            for (i = 0; i < 2; i++) {
                *sc = PT_80140A60[i + 3].f_7C;
                sc->vy = -0x3010;
                func_80070130_80140A60(sc, D_80144164_80140A60, 2, 1, 2, 0);
                sc->vy += 0x80;
                func_800702B0_80140A60(sc, D_8014436C_80140A60);
            }
            for (i = 0; i < 0x30; i++) {
                sc->vx = ((RAND_80140A60() >> 8) - 0x7F) * 0x10;
                sc->vy = -0x3000;
                sc->vz = 0xEB8 - ((RAND_80140A60() >> 5) & 0x7F8);
                Effect_SpawnAt(6, sc);
            }
            sc->vy = -0x3000;
            sc->vx = 0;
            sc->vz = 0xADC;
            func_8013D4A4(sc);
            Camera_StartShake_80140A60(2);
            Sound_PlayFixed_80140A60(0x80);
            Sound_PlayFixed_80140A60(0x79);
            Sound_PlayFixed_80140A60(0x60);
            func_8013D9DC();
        }
        if (ST_80140A60.f_10 >= 0x35) {
            func_8013DA04();
        }
        if (ST_80140A60.f_6 == 0) {
            func_801408AC(0x28, 0x14);
        }
        break;
    case 4:
        ST_80140A60.f_7 = 1;
        if ((u16)RAND_80140A60() >> 8 < 0x20) {
            func_8013E81C((u8 *)ST_80140A60.f_18, 0);
        }
        if (ST_80140A60.f_6 == 0) {
            func_801409AC();
        }
        break;
    case 6: {
        Part_80140A60 *m = ST_80140A60.f_18;
        SVECTOR *p = &m->f_7C;

        ST_80140A60.f_10++;
        if (ST_80140A60.f_10 & 1) {
            u8 c = ST_80140A60.f_10 * 2 + 0x20;

            Fx_DrawFadeRing_80140A60(p, ST_80140A60.f_10 * 24, 5, (c << 16) | (c << 8) | c);
        }
        if (!(ST_80140A60.f_10 & 1)) {
            sc->vx = p->vx + ((RAND_80140A60() >> 8) - 0x80) * 16;
            sc->vy = p->vy + ((RAND_80140A60() >> 8) - 0x80) * 16;
            sc->vz = p->vz + ((RAND_80140A60() >> 8) - 0x80) * 16;
            func_8013E4D0_80140A60(sc, p);
            ST_80140A60.f_1D = 1;
            ST_80140A60.f_1C = ((RAND_80140A60() >> 8) & 7) + 9;
            if (!(ST_80140A60.f_10 & 1)) {
                Sound_PlayFixed_80140A60(0x58);
            }
        }
        if (ST_80140A60.f_6 == 0) {
            ST_80140A60.f_C = 7;
            ST_80140A60.f_10 = (((RAND_80140A60() >> 8) & 3) + 4) * 4;
        }
        break;
    }
    case 7: {
        Part_80140A60 *m = ST_80140A60.f_18;
        SVECTOR *p = &m->f_7C;

        if (!(--ST_80140A60.f_10 & 3)) {
            func_8013F0A4_80140A60(m);
            ST_80140A60.f_14 = ST_80140A60.f_15 = -0x18;
            ST_80140A60.f_16 = 1;
            sc->vx = p->vx + ((RAND_80140A60() >> 8) - 0x80) * 4;
            sc->vy = p->vy + ((RAND_80140A60() >> 8) - 0x80) * 4;
            sc->vz = p->vz + ((RAND_80140A60() >> 8) - 0x80) * 4;
            func_8013E4D0_80140A60(sc, p);
            Sound_PlayFixed_80140A60(0x77);
        }
        if (ST_80140A60.f_10 == 0) {
            ST_80140A60.f_C = 8;
            func_801406F8(ST_80140A60.f_17 + 7);
            ST_80140A60.f_7 = 1;
        }
        break;
    }
    case 8:
        if (D_80144BEE_80140A60 == 0) {
            func_801408AC(0x1E, 0x3C);
        }
        break;
    case 10:
        if (--ST_80140A60.f_10 == 0x43) {
            func_80140498(0);
        }
        if (ST_80140A60.f_10 == 0x14) {
            func_8014081C();
        }
        if (ST_80140A60.f_10 == 0) {
            func_801406F8(ST_80140A60.f_17 + 0xD);
            ST_80140A60.f_C = 0xB;
            func_80140498(1);
        }
        break;
    case 11:
        if (D_80144BEE_80140A60 == 0) {
            func_801408AC(0x1E, 0x3C);
        }
        break;
    case 12:
        if (ST_80140A60.f_6 == 0 && ST_80140A60.f_D == 0) {
            func_801408AC(0x3C, 0x3C);
        }
        break;
    case 13:
        if (--ST_80140A60.f_10 == 0) {
            v18.vy = -0x3300;
            v18.vx = 0;
            v18.vz = 0xEB8;
            Effect_SpawnAt(0x105, &v18);
            Fx_SpawnFadeRing_80140A60(&v18, 0, 0x3E8, 0);
            func_8013D4A4(&v18);
            Camera_StartShake_80140A60(1);
            memset_80140A60(&v28, 0, 8);
            v28.vx = g_Spike_80140A60.x - v18.vx;
            v28.vy = g_Spike_80140A60.y - v18.vy;
            v28.vz = g_Spike_80140A60.z - v18.vz;
            v20 = v28;
            func_80070284_80140A60(&v18, D_80144014_80140A60, 1, 0, &v20);
            Sound_PlayFixed_80140A60(0x82);
            Sound_PlayFixed_80140A60(0xBA);
            func_8013F78C((u8 *)&PT_80140A60[1], 0x1E, -0x94, -0x1E);
            func_8013F78C((u8 *)&PT_80140A60[2], -0x19, -0x41, -0x28);
            func_8013F78C((u8 *)&PT_80140A60[5], 0x1C, -0x6E, -0x3C);
            func_8013F78C((u8 *)&PT_80140A60[6], -0x24, -0x50, -0xC);
            Sound_PlayFixed_80140A60(0x79);
            ST_80140A60.f_10 = 0x3C;
            ST_80140A60.f_C = 0xE;
            func_8013D000(7, &PT_80140A60[0], &PT_80140A60[0].f_84);
            ST_80140A60.f_8 = PT_80140A60[0].f_84;
            ST_80140A60.f_4 = *ST_80140A60.f_8;
            ST_80140A60.f_7 = 0;
            func_8013D9DC();
        }
        break;
    case 14:
        if (--ST_80140A60.f_10 == 0) {
            v28.vy = -0x3370;
            v28.vx = 0;
            v28.vz = 0xEB8;
            Effect_SpawnAt(0x105, &v28);
            Fx_SpawnFadeRing_80140A60(&v28, 0, 0x640, 0);
            func_8013D4A4(&v28);
            Effect_SpawnAt(0x109, &v28);
            Camera_StartShake_80140A60(2);
            func_8013D9DC();
            memset_80140A60(&v38, 0, 8);
            v38.vx = g_Spike_80140A60.x - v28.vx;
            v38.vy = g_Spike_80140A60.y - v28.vy;
            v38.vz = g_Spike_80140A60.z - v28.vz;
            v30 = v38;
            func_80070284_80140A60(&v28, D_80144014_80140A60, 1, 0, &v30);
            Sound_PlayFixed_80140A60(0x82);
            Sound_PlayFixed_80140A60(0xBA);
            D_801444A4_80140A60 = 0xC8;
            func_80141F70();
        }
        break;
    }
    func_80140738();
    {

        for (i = 0, p = PT_80140A60; i < 7; i++, p++) {
            p->f_5C = ST_80140A60.f_4;
            if (i == 0) {
                func_8013DD44_80140A60(p);
                p->y = -0x3000;
                p->x = 0;
                p->z = 0x10B8;
                continue;
            }
            if (p->f_8C == 2) {
                p->f_5C = 2;
                p->x += p->f_90;
                p->y += p->f_92;
                p->z += p->f_94;
                p->f_92 += 0xB;
                Effect_SpawnAt(6, &p->f_74);
                if (ST_80140A60.f_12 & 1) {
                    Effect_Spawn_80140A60(0xCD, &p->f_74, D_80143F00_80140A60, 0);
                }
                if (p->f_92 > 0 && p->y >= -0x2DFF) {
                    s32 j;

                    p->f_8C = 0;
                    *sc = p->f_7C;
                    sc->vy = -0x3010;
                    if ((u32)(i - 3) < 2) {
                        for (j = 0; j < 3; j++) {
                            Pickup_Drop_80140A60(1, sc, 3, 0);
                        }
                        for (j = 0; j < 2; j++) {
                            Pickup_Drop_80140A60(3, sc, 3, 0);
                        }
                        Pickup_Drop_80140A60(5, sc, 3, 0);
                    }
                    func_8013D4A4(sc);
                    sc->vy -= ((u16)RAND_80140A60() >> 9) + 0x60;
                    func_80070284_80140A60(sc, D_801440BC_80140A60, 1, (RAND_80140A60() >> 8) & 7, NULL);
                    sc->vy -= 0x60;
                    func_80070284_80140A60(sc, D_801440BC_80140A60 - 0x54, 2, (RAND_80140A60() >> 8) & 3, NULL);
                    Fx_SpawnFadeRing_80140A60(sc, 0, 0x578, 0);
                    Effect_SpawnAt(0x109, &p->f_74);
                    for (j = 0; j < 0xF; j++) {
                        Effect_Spawn_80140A60(0xCD, sc, D_80143F00_80140A60, 0);
                    }
                    Camera_StartShake_80140A60(2);
                    Sound_PlayFixed_80140A60(0xBA);
                    func_8013D9DC();
                    if ((u32)(ST_80140A60.f_C - 0xD) >= 2 && PT_80140A60[3].f_8C == 0 && PT_80140A60[4].f_8C == 0) {
                        ST_80140A60.f_C = 0xD;
                        ST_80140A60.f_10 = 0x1E;
                    }
                }
                sc->vx = 0xB;
                sc->vy = 0;
                sc->vz = 0;
                RotMatrix_80140A60(sc, (Mat_80140A60 *)(sc + 1));
                ApplyMatrixSV_80140A60((Mat_80140A60 *)(sc + 1), &p->f_60, &p->f_60);
                VectorNormalSS_80140A60(&p->f_60, &p->f_60);
                p->f_96++;
            }
            if (p->f_8C == 1) {
                p->y = -0x3000;
                p->x = 0;
                p->z = 0x10B8;
            }
            if (p->f_8C != 0) {
                func_8013DD44_80140A60(p);
            }
        }
    }
    {
        Coll_80140A60 *c;


        for (i = 0, p = &PT_80140A60[3], c = D_80144888_80140A60; i < 2; i++, p++, c++) {
            if (p->f_8C != 1) {
                v18.vx = c->f_70.vx + ((RAND_80140A60() >> 8) + 0xFF80);
                v18.vy = c->f_70.vy + ((RAND_80140A60() >> 8) + 0xFF80);
                v18.vz = c->f_70.vz + ((RAND_80140A60() >> 8) + 0xFF80);
                if (!((RAND_80140A60() >> 8) & 7)) {
                    func_8013E4D0_80140A60(&v18, &c->f_70);
                }
                if (!((RAND_80140A60() >> 8) & 1)) {
                    Effect_SpawnAt(7, &v18);
                    Effect_SpawnAt(0x31, &v18);
                }
                if (ST_80140A60.f_12 & 1) {
                    Fx_DrawFadeRing_80140A60(&c->f_70, ((u16)RAND_80140A60() >> 9) | 0x80, 0, 0x303030);
                }
            }
            if (p->f_8E != 0 && ST_80140A60.f_D == 0) {
                c->x = p->f_7C.vx;
                c->y = p->f_7C.vy + 0x50;
                c->z = p->f_7C.vz;
                if ((c->f_50 >> 28) == 0xB) {
                    Shape_80140A60 *sh = Collision_GetShape_80140A60(M2C_FIELD(c, u16 *, 0x50) & 0xFFF);
                    s32 id = Collision_GetId_80140A60(M2C_FIELD(p, u16 *, 0x50) & 0xFFF);
                    s32 t;

                    if (p != ST_80140A60.f_18 || (t = sh->f_24 & 0xFF00) == 0xD00 || t == 0xF00
                        || (u32)(ST_80140A60.f_C - 0xA) >= 2 || id != 1) {
                        ST_80140A60.f_D = 0xC;
                        Effect_SpawnAt(0x109, &p->f_7C);
                        Camera_StartShake_80140A60(0);
                        Sound_PlayFixed_80140A60(0x60);
                        func_8013D9DC();
                    } else {
                        memset_80140A60(&v28, 0, 8);
                        v28.vx = p->f_7C.vx;
                        v28.vy = p->f_7C.vy;
                        v28.vz = p->f_7C.vz;
                        v20 = v28;
                        func_801406F8(i + 0xB);
                        ST_80140A60.f_D = 0x1E;
                        ST_80140A60.f_C = 0xC;
                        Effect_SpawnAt(0x105, &v20);
                        Fx_SpawnFadeRing_80140A60(&v20, 0, 0x300, 0);
                        func_8013D4A4(&v20);
                        Camera_StartShake_80140A60(1);
                        memset_80140A60(&v30, 0, 8);
                        v30.vx = g_Spike_80140A60.x - v20.vx;
                        v30.vy = g_Spike_80140A60.y - v20.vy;
                        v30.vz = g_Spike_80140A60.z - v20.vz;
                        v28 = v30;
                        func_80070284_80140A60(&v20, D_80144014_80140A60, 1, 0, &v28);
                        Sound_PlayFixed_80140A60(0x4D);
                        Sound_PlayFixed_80140A60(0x82);
                        func_80140630(0x32);
                        func_8013D9DC();
                        if (--p->f_8E == 0) {
                            Collision_Remove_80140A60(&c->x);
                            func_8013F78C((u8 *)p, i * -0x28 + 0x14, -0x50, -8);
                            Sound_PlayFixed_80140A60(0x79);
                        }
                    }
                }
            }
        }
    }
    q = &PT_80140A60[3]; /* the original passes &PT[3] - 3 to func_8013F598 */
    if (ST_80140A60.f_D != 0) {
        ST_80140A60.f_D--;
    }
    if (ST_80140A60.f_1C != 0) {
        ST_80140A60.f_1C--;
    }
    ST_80140A60.f_12++;
    func_8013FAA4_80140A60();
    func_8013E8D4();
    func_8013F198();
    func_8013D60C_80140A60();
    func_8013E22C_80140A60();
    func_8013E564();
    func_8014063C();
    func_8013F598((u8 *)(q - 3));
}

extern u8 D_80144A10[];
extern u8 D_80144978[];
extern u8 D_80144BE8_80141F70[] asm("D_80144BE8");
void func_801423E8(void);
void func_801428A4(void);

void func_80141F70(void) {
    u8 *a = D_80144A10;
    u8 *c;

    M2C_FIELD(a, s32 *, 0x88) = 0;
    M2C_FIELD(a, s32 *, 0x24) = 0;
    M2C_FIELD(a, s32 *, 0x28) = -0x3200;
    M2C_FIELD(a, s32 *, 0x2C) = 0xF28;
    M2C_FIELD(a, s16 *, 0x60) = 0;
    M2C_FIELD(a, s16 *, 0x62) = 0;
    M2C_FIELD(a, s16 *, 0x64) = -0x1000;
    Collision_Set(5, a + 0x24, a);
    M2C_FIELD(a, s16 *, 0x4A) = -0x4000;
    M2C_FIELD(a, s16 *, 0x44) = 0x100;
    M2C_FIELD(a, s16 *, 0x46) = 0x100;
    M2C_FIELD(a, s16 *, 0x48) = 0;
    a = D_80144978;
    func_8013D000(7, a, a + 0x84);
    M2C_FIELD(a, u8 *, 0x8F) = 3;
    M2C_FIELD(a, u8 *, 0x8E) = 3;
    M2C_FIELD(a, u8 *, 0x8C) = 1;
    M2C_FIELD(a, u8 *, 0x8D) = 0;
    M2C_FIELD(a, s32 *, 0x28) = -0x3000;
    M2C_FIELD(a, s32 *, 0x2C) = 0x10B8;
    M2C_FIELD(a, s16 *, 0x44) = 0x200;
    M2C_FIELD(a, s16 *, 0x64) = -0x1000;
    M2C_FIELD(a, s32 *, 0x88) = 0;
    M2C_FIELD(a, s32 *, 0x24) = 0;
    M2C_FIELD(a, s16 *, 0x60) = 0;
    M2C_FIELD(a, s16 *, 0x62) = 0;
    M2C_FIELD(a, s16 *, 0x74) = 0;
    M2C_FIELD(a, s16 *, 0x76) = -0x3200;
    M2C_FIELD(a, s16 *, 0x78) = 0xEB8;
    M2C_FIELD(a, s16 *, 0x7C) = 0;
    M2C_FIELD(a, s16 *, 0x7E) = -0x3100;
    M2C_FIELD(a, s16 *, 0x80) = 0xEB8;
    c = D_80144BE8_80141F70;
    M2C_FIELD(c, u8 *, 0xF) = 1;
    M2C_FIELD(c, s32 *, 0x8) = M2C_FIELD(a, s32 *, 0x84);
    M2C_FIELD(c, u8 *, 0xC) = 0;
    func_801406F8(0);
    M2C_FIELD(c, u8 *, 0x14) = 0;
    M2C_FIELD(c, u8 *, 0xD) = 0;
    M2C_FIELD(c, s16 *, 0x10) = 0x5A;
    M2C_FIELD(c, u8 *, 0x1C) = 0;
    M2C_FIELD(c, s16 *, 0x12) = 0;
    M2C_FIELD(c, u8 *, 0x1F) = 0;
    M2C_FIELD(c, u8 *, 0x20) = 0;
    func_801423E8();
    func_801428A4();
}

typedef struct { u8 pad0[0x10]; u8 *f_10; u8 pad14[0x14]; s32 y; s32 z; u8 pad30[0x44]; SVECTOR f_74; SVECTOR f_7C; u8 pad84[0xA]; u8 f_8E; } Boss_801420BC;
extern struct { u8 pad0[0x12]; u16 f_12; s8 f_14; u8 f_15; u8 f_16; u8 pad17[5]; u8 f_1C; u8 f_1D; u8 pad1E[2]; u8 f_20; } D_80144BE8_801420BC asm("D_80144BE8");
extern struct { s16 m[3][3]; s16 pad; s32 t[3]; } D_800F47F0;
extern u8 D_80144394[];
s32 func_8013D1FC(u8 *a, void *scale, s32 c);
void *ApplyMatrixSV(void *, void *, void *);

void func_801420BC(Boss_801420BC *m) {
    s32 v;
    s32 t;
    s32 flags;

    if (D_80144BE8_801420BC.f_20 != 0) {
        return;
    }
    if ((v = D_80144BE8_801420BC.f_14) != 0) {
        if (D_80144BE8_801420BC.f_16 == 0) {
            m->z -= v;
        } else {
            m->y -= v;
        }
        D_80144BE8_801420BC.f_14 += D_80144BE8_801420BC.f_15;
        D_80144BE8_801420BC.f_15 += 8;
        if (D_80144BE8_801420BC.f_14 > 0) {
            D_80144BE8_801420BC.f_14 = 0;
        }
    }
    flags = 0;
    if (D_80144BE8_801420BC.f_1C != 0) {
        t = D_80144BE8_801420BC.f_12 & 0xF;
        if (t >= 8) {
            t = 15 - t;
        }
        switch (D_80144BE8_801420BC.f_1D) {
        case 0:
            flags = 0x808000 | ((t << 3) + 0x80);
            break;
        case 1:
            flags = (((t << 3) + 0x80) << 16) | ((t + 0x80) << 8) | 0x80;
            break;
        }
    } else if (m->f_8E == 2) {
        t = D_80144BE8_801420BC.f_12 & 0xF;
        if (t >= 8) {
            t = 15 - t;
        }
        flags = (t << 4) | 0x10000;
    } else if (m->f_8E < 2) {
        t = D_80144BE8_801420BC.f_12 & 7;
        if (t >= 4) {
            t = 7 - t;
        }
        flags = (t << 5) | 0x10000;
    }
    if (func_8013D1FC((u8 *)m, D_80144394, flags) == 0) {
        ApplyMatrixSV(&D_800F47F0, m->f_10 + 0x800, &m->f_74);
        m->f_74.vx += D_800F47F0.t[0];
        m->f_74.vy += D_800F47F0.t[1];
        m->f_74.vz += D_800F47F0.t[2];
        ApplyMatrixSV(&D_800F47F0, m->f_10 + 0x750, &m->f_7C);
        m->f_7C.vx += D_800F47F0.t[0];
        m->f_7C.vy += D_800F47F0.t[1];
        m->f_7C.vz += D_800F47F0.t[2];
    }
}

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

typedef struct { s16 x, y, z; u8 pad6[2]; u8 f_8; u8 pad9[3]; } Pt_801423E8;
extern Pt_801423E8 D_80145430_801423E8[3] asm("D_80145430");

void func_801423E8(void) {
    s32 i;
    u8 *q;

    for (i = 0; i < 3; i++) {
        D_80145430_801423E8[i].f_8 = 1;
        Link_SendEvent(9, i + 1, 0);
    }
    M2C_FIELD(D_80145430_801423E8, s16 *, 0) = 0;
    M2C_FIELD(D_80145430_801423E8, s16 *, 2) = -0x3000;
    M2C_FIELD(D_80145430_801423E8, s16 *, 4) = 0x8FC;
    M2C_FIELD(D_80145430_801423E8, s16 *, 0xC) = -0x708;
    q = (u8 *)D_80145430_801423E8 + 0xC;
    M2C_FIELD(q, s16 *, 2) = -0x3000;
    M2C_FIELD(q, s16 *, 4) = 0xCD0;
    M2C_FIELD(D_80145430_801423E8, s16 *, 0x18) = 0x708;
    q = (u8 *)D_80145430_801423E8 + 0x18;
    M2C_FIELD(q, s16 *, 2) = -0x3000;
    M2C_FIELD(q, s16 *, 4) = 0xCD0;
}

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

typedef struct { s16 x, y, z; u8 pad6[2]; u8 state; u8 count; u8 timer; u8 padB; } Gate_801425EC;
extern Gate_801425EC D_80145430_801425EC[] asm("D_80145430");
s32 Link_SendEvent(s32, s32, s32);
void func_80142924(s32 i);

void func_801425EC(void) {
    SVECTOR pos;
    Gate_801425EC *e;
    s32 i;
    s32 j;

    for (i = 0, e = D_80145430_801425EC; i < 3; i++, e++) {
        switch (e->state) {
        case 0:
            if (--e->timer == 0) {
                e->state = 3;
                e->count = 0x1E;
            }
            break;
        case 1:
            break;
        case 2:
            if (--e->count == 0) {
                Link_SendEvent(9, i + 1, 3);
                e->state = 0;
                e->timer = 0xB4;
                switch (i) {
                case 0:
                    for (j = 6; j < 12; j++) {
                        func_80142924(j);
                    }
                    break;
                case 1:
                    for (j = 0; j < 3; j++) {
                        func_80142924(j);
                    }
                    break;
                case 2:
                    for (j = 3; j < 6; j++) {
                        func_80142924(j);
                    }
                    break;
                }
                Sound_PlayFixed(0x6C);
            } else {
                Link_SendEvent(9, i + 1, e->count & 1);
                for (j = 0; j < 4; j++) {
                    pos.vx = e->x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 12;
                    pos.vy = e->y;
                    pos.vz = e->z + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 12;
                    Effect_SpawnAt(6, &pos);
                }
            }
            break;
        case 3:
            if (--e->count == 0) {
                Link_SendEvent(9, i + 1, 0);
                e->state = 1;
            } else {
                Link_SendEvent(9, i + 1, (e->count & 1) | 2);
            }
            break;
        }
    }
}

typedef struct { u8 *mdl; u8 pad4[6]; u8 f_A; u8 padB[0x19]; SVECTOR pos; } Piece_801428A4;
extern Piece_801428A4 D_80145458_801428A4[12] asm("D_80145458");
extern u8 D_801443A4[];
extern SVECTOR D_801443B0[];
extern u8 *D_800B4D64;

void func_801428A4(void) {
    s32 i;
    Piece_801428A4 *e;

    for (i = 0, e = D_80145458_801428A4; i < 12; i++, e++) {
        e->f_A = 0;
        e->mdl = D_800B4D64 + D_801443A4[i] * 32;
        e->pos = D_801443B0[i];
    }
}

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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80142A48;
typedef struct { void *model; s16 x, y, z; u8 active; u8 padB; s16 vx, vy, vz; u8 pad12[2]; SVECTOR rot; s16 rvx, rvy, rvz; u8 pad22[0xA]; } Rock_80142A48;
extern Rock_80142A48 D_80145458_80142A48[] asm("D_80145458");
extern void *D_800EC358;
void func_8013D9DC(void);
void func_8004637C(void *);
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void Model_ProjectVertsAlt(void *, void *, void *);
void func_80017E5C(void *, void *, void *);

void func_80142A48(void) {
    Mat_80142A48 m;
    Rock_80142A48 *e;
    s32 i, j;

    for (i = 0, e = D_80145458_80142A48; i < 12; i++, e++) {
        if (e->active == 0) {
            continue;
        }
        e->x += e->vx;
        e->y += e->vy;
        e->z += e->vz;
        e->vy += 8;
        if ((RAND() >> 8 & 0x1F) == 0) {
            Sound_PlayFixed(0x60);
        }
        if (e->y >= -0x2DFF) {
            for (j = 0; j < 16; j++) {
                Effect_Spawn(0xCD, (SVECTOR *)&e->x, D_80143F00, 0);
            }
            func_80070284(&e->x, (M2C_UNK *)D_80144068, 1, 0, 0);
            Sound_PlayFixed(0xBA);
            func_8013D9DC();
            e->active = 0;
            continue;
        }
        e->rot.vx += e->rvx;
        e->rot.vy += e->rvy;
        e->rot.vz += e->rvz;
        func_8004637C(&m);
        RotMatrixZYX(&e->rot, &m);
        m.t[0] = e->x;
        m.t[1] = e->y;
        m.t[2] = e->z;
        CompMatrix(D_800E78C0, &m, &m);
        Model_ProjectVertsAlt(e->model, &m, D_800E7D00);
        func_80017E5C(D_800EC358, D_800E7D00, e->model);
    }
}

typedef struct { u8 pad_0[4]; u16 f_4; u8 f_6; u8 pad_7[5]; u8 f_C; u8 f_D; u8 pad_E[2]; s16 f_10; u16 f_12; u8 pad_14[8]; u8 f_1C; u8 pad_1D[3]; u8 f_20; u8 f_21; u16 f_22; } St_80142C40;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x2C]; u16 f_5C; u8 pad_5E[2]; SVECTOR f_60; u8 pad_68[0x14]; SVECTOR f_7C; u8 pad_84[0xA]; u8 f_8E; } Boss_80142C40;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x20]; u32 f_50; } Obj_80142C40;
typedef struct { u8 pad_0[8]; u8 f_8; u8 pad_9[3]; } Zone_80142C40;
extern St_80142C40 D_80144BE8_80142C40 asm("D_80144BE8");
extern Boss_80142C40 D_80144978_80142C40 asm("D_80144978");
extern Obj_80142C40 D_80144A10_80142C40 asm("D_80144A10");
extern Zone_80142C40 D_80145430_80142C40[] asm("D_80145430");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80142C40 asm("g_Spike");
extern u8 D_80143F00_80142C40[] asm("D_80143F00");
extern u8 D_80143F18_80142C40[] asm("D_80143F18");
extern u8 D_80144014_80142C40[] asm("D_80144014");
extern u8 D_80144308_80142C40[] asm("D_80144308");
extern u8 D_80144BF4_80142C40 asm("D_80144BF4");
void Camera_ExitAim_80142C40(void) asm("Camera_ExitAim");
void Camera_StartShake_80142C40(s32) asm("Camera_StartShake");
void Effect_SpawnAt_80142C40(s32, void *) asm("Effect_SpawnAt");
void Effect_Spawn_80142C40(s32, void *, void *, s32) asm("Effect_Spawn");
void Sound_PlayFixed_80142C40(s32) asm("Sound_PlayFixed");
void func_80070284_80142C40(void *, void *, s32, s32, void *) asm("func_80070284");
void Fx_SpawnFadeRing_80142C40(void *, s32, s32, s32) asm("Fx_SpawnFadeRing");
void Fx_DrawFadeRing_80142C40(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
void Fx_DebrisExplosion_80142C40(s32, s32, s32) asm("Fx_DebrisExplosion");
void func_8006D548_80142C40(void *) asm("func_8006D548");
u8 *Collision_GetShape_80142C40(s32) asm("Collision_GetShape");
void Spike_SetPlayMode_80142C40(s32) asm("Spike_SetPlayMode");
void *memset_80142C40(void *, s32, s32) asm("memset");
void func_80140630_80142C40(s32) asm("func_80140630");
void func_8014081C(void);
void func_8013E098(SVECTOR *src);
s32 func_801424A0_80142C40(s32, s32) asm("func_801424A0");
void func_8013F964(void);
void func_8013F9FC(void);
void func_80142310_80142C40(s32) asm("func_80142310");
void func_8013D4A4(SVECTOR *arg0);
void func_8013DA2C(void);
void func_8013DA04(void);
void func_801420BC_80142C40(void *) asm("func_801420BC");
void func_80140738(void);
void func_8013FAA4_80142C40(void) asm("func_8013FAA4");
void func_8013E8D4(void);
void func_8013F198(void);
void func_8013D60C_80142C40(void) asm("func_8013D60C");
void func_8013E22C_80142C40(void) asm("func_8013E22C");
void func_8013E564(void);
void func_801425EC(void);
void func_80142A48(void);
void func_8014063C(void);
void func_8013F598(u8 *obj);
#define RAND_80142C40() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80142C40(void) {
    SVECTOR v;
    s32 i;
    s32 r;
    s32 c;
    u8 *sh;
    Boss_80142C40 *bs = &D_80144978_80142C40;

    if (bs->f_8E == 0) {
        Camera_ExitAim_80142C40();
    }
    switch (D_80144BE8_80142C40.f_C) {
    case 0:
        func_801406F8(0);
        if (D_80144BE8_80142C40.f_10 == 0 || --D_80144BE8_80142C40.f_10 == 0) {
            D_80144BE8_80142C40.f_C = 1;
            func_801406F8(1);
            D_80144BE8_80142C40.f_10 = 0x40;
            D_80144BE8_80142C40.f_21 = bs->f_8E < 2 ? 2 : 1;
            func_80140630_80142C40(0x32);
            func_8014081C();
            Sound_PlayFixed_80142C40(0x92);
        }
        break;
    case 1:
        if (D_80144BE8_80142C40.f_10 != 0) {
            c = (u8)(0x40 - (u8)D_80144BE8_80142C40.f_10);
            Fx_DrawFadeRing_80142C40(&bs->f_7C, D_80144BE8_80142C40.f_10 * 24, 3, (c << 16) | (c << 8) | c);
            if (!(D_80144BE8_80142C40.f_10 & 7)) {
                func_8013E098(&bs->f_7C);
            }
            D_80144BE8_80142C40.f_10--;
        }
        {
        St_80142C40 *p = &D_80144BE8_80142C40;
        if (p->f_6 == 0) {
            r = func_801424A0_80142C40((s16)g_Spike_80142C40.x, (s16)g_Spike_80142C40.z);
            if (D_80145430_80142C40[r].f_8 == 1) {
                s32 an;
                if (r != 1) {
                    if (r != 2) {
                        func_801406F8(2);
                        p->f_10 = 10;
                        goto set;
                    }
                    an = 3;
                    goto call;
                }
                an = 4;
            call:
                func_801406F8(an);
                p->f_10 = 0x10;
            set:
                D_80144BF4_80142C40 = 2;
                Sound_PlayFixed_80142C40(0x81);
                Sound_PlayFixed_80142C40(0x82);
            } else {
                p->f_C = 0;
                p->f_10 = 0x5A;
            }
        }
        }
        break;
    case 2:
        if (D_80144BE8_80142C40.f_10 != 0 && --D_80144BE8_80142C40.f_10 == 0) {
            func_8013E81C((u8 *)bs, 0);
        }
        if (D_80144BE8_80142C40.f_6 == 0) {
            if (--D_80144BE8_80142C40.f_21 != 0) {
                D_80144BE8_80142C40.f_C = 1;
                func_801406F8(1);
                D_80144BE8_80142C40.f_10 = 0x40;
                func_8014081C();
            } else {
                D_80144BE8_80142C40.f_10 = 0x1E;
                D_80144BE8_80142C40.f_C = 3;
                func_801406F8(0);
            }
        }
        break;
    case 3:
        if (--D_80144BE8_80142C40.f_10 == 0) {
            D_80144BE8_80142C40.f_C = 4;
            func_801406F8(7);
        }
        break;
    case 4:
        if (D_80144BE8_80142C40.f_6 == 0) {
            v.vy = -0x3300;
            v.vz = 0xEB8;
            v.vx = 0;
            func_80070284_80142C40(&v, D_80143F18_80142C40, 1, 0, &bs->f_60);
            D_80144BE8_80142C40.f_C = 5;
            func_801406F8(5);
            func_8014081C();
            D_80144BE8_80142C40.f_10 = 0;
        }
        break;
    case 5:
        if (++D_80144BE8_80142C40.f_10 == 0x96) {
            D_80144BE8_80142C40.f_C = 6;
            func_801406F8(6);
        }
        if (D_80144BE8_80142C40.f_10 > 0x3C && !((RAND_80142C40() >> 8) & 3)) {
            func_8013F964();
        }
        break;
    case 6:
        if (D_80144BE8_80142C40.f_6 == 0) {
            D_80144BE8_80142C40.f_C = 0;
            func_801406F8(0);
            D_80144BE8_80142C40.f_10 = 0x78;
        }
        break;
    case 7:
        if (D_80144BE8_80142C40.f_6 == 0) {
            D_80144BE8_80142C40.f_C = 6;
            func_801406F8(6);
        }
        break;
    case 8:
    case 9:
        {
        SVECTOR u;
        if (g_Spike_80142C40.y >= -0x2FFF) {
            g_Spike_80142C40.y = -0x3000;
        }
        if ((D_80144BE8_80142C40.f_10 = D_80144BE8_80142C40.f_10 - 1) << 16 == 0) {
            D_800E69BE = 1;
            D_80144BE8_80142C40.f_C = 10;
            __asm__ volatile("" ::: "memory");
        }
        if (D_80144BE8_80142C40.f_10 == 0xB2) {
            Sound_PlayFixed_80142C40(0x94);
            Sound_PlayFixed_80142C40(0x95);
        }
        if (D_80144BE8_80142C40.f_10 >= 0x83) {
            u.vx = bs->x + (((u16)RAND_80142C40() >> 8) - 0x80) * 4;
            u.vy = -0x3000 - ((u16)RAND_80142C40() >> 8) * 3;
            u.vz = bs->z - ((u16)RAND_80142C40() >> 8);
            func_8006D548_80142C40(&u);
            Effect_SpawnAt_80142C40(7, &u);
            if (!(D_80144BE8_80142C40.f_10 & 7)) {
                Effect_SpawnAt_80142C40(0x109, &u);
            }
        }
        if (D_80144BE8_80142C40.f_10 == 0xAA) {
            Sound_PlayFixed_80142C40(0xBA);
            Fx_DebrisExplosion_80142C40((s16)bs->x, -0x3100, (s16)bs->z);
        }
        if (D_80144BE8_80142C40.f_10 == 0xA4) {
            Sound_PlayFixed_80142C40(0xBA);
            func_8013F9FC();
        }
        if (D_80144BE8_80142C40.f_10 == 0xA0) {
            Sound_PlayFixed_80142C40(0xBA);
            Fx_DebrisExplosion_80142C40((s16)bs->x, -0x3400, (s16)bs->z);
        }
        if (D_80144BE8_80142C40.f_10 == 0x8C) {
            SVECTOR b = { bs->x, -0x3000, bs->z };
            for (i = 0; i < 0x20; i++) {
                Effect_Spawn_80142C40(0xCD, &b, D_80143F00_80142C40, 0);
            }
            Sound_PlayFixed_80142C40(0xBA);
        }
        if ((u32)((u16)D_80144BE8_80142C40.f_10 - 0x7D) < 6) {
            func_80142310_80142C40(0xE6F0FF);
            D_80144BE8_80142C40.f_20 = 1;
            D_80144BE8_80142C40.f_22 = 0xDC;
            D_80144BE8_80142C40.f_C = 9;
        }
        if (D_80144BE8_80142C40.f_22 != 0) {
            u32 cc = (u8)D_80144BE8_80142C40.f_22;
            func_80142310_80142C40(((cc >> 2) << 16) | ((cc >> 1) << 8) | cc);
            D_80144BE8_80142C40.f_22 -= 4;
        }
        if (D_80144BE8_80142C40.f_10 == 0x7C) {
            SVECTOR b = { bs->x, -0x3000, bs->z };
            for (i = 0; i < 0x1E; i++) {
                Effect_Spawn_80142C40(0xCD, &b, D_80143F00_80142C40, 0);
            }
            func_8013D4A4(&b);
            Fx_SpawnFadeRing_80142C40(&b, 0, 0x800, 5);
            Fx_SpawnFadeRing_80142C40(&b, 0, 0x400, 0xC);
            func_80070284_80142C40(&b, D_80144308_80142C40, 3, 0, 0);
            b.vy = -0x3040;
            func_80070284_80142C40(&b, D_80144308_80142C40 - 0x54, 1, 6, 0);
            b.vy = -0x31A4;
            func_80070284_80142C40(&b, D_80144308_80142C40 - 0x54, 1, 0xD, 0);
            b.vy = -0x3320;
            func_80070284_80142C40(&b, D_80144308_80142C40 - 0x54, 1, 0x16, 0);
            Sound_PlayFixed_80142C40(0x6C);
            Sound_PlayFixed_80142C40(0x82);
            Sound_PlayFixed_80142C40(0xBA);
        }
        if ((u32)((u16)D_80144BE8_80142C40.f_10 - 0x61) < 0x15) {
            if (!(D_80144BE8_80142C40.f_10 & 7)) {
                Sound_PlayFixed_80142C40(0x6C);
            }
            if ((D_80144BE8_80142C40.f_10 & 7) == 3) {
                Sound_PlayFixed_80142C40(0xBA);
            }
        }
        if (D_80144BE8_80142C40.f_10 > 0x1E) {
            Camera_StartShake_80142C40(2);
            func_8013DA2C();
        } else {
            Camera_StartShake_80142C40(0);
            func_8013DA04();
        }
        }
        break;
    case 10:
        return;
    }
    bs->f_5C = D_80144BE8_80142C40.f_4;
    func_801420BC_80142C40(bs);
    bs->y = -0x3000;
    bs->x = 0;
    bs->z = 0x10B8;
    func_80140738();
    if (D_80144BE8_80142C40.f_D != 0) {
        D_80144BE8_80142C40.f_D--;
    }
    if (D_80144BE8_80142C40.f_1C != 0) {
        D_80144BE8_80142C40.f_1C--;
    }
    D_80144BE8_80142C40.f_12++;
    if (M2C_FIELD(&D_80144BE8_80142C40, u16 *, 0xC) == 5 && (D_80144A10_80142C40.f_50 >> 28) == 0xB) {
        sh = Collision_GetShape_80142C40(M2C_FIELD(&D_80144A10_80142C40, u16 *, 0x50) & 0xFFF);
        {
            SVECTOR p = { D_80144A10_80142C40.x, D_80144A10_80142C40.y - 0x80, D_80144A10_80142C40.z };
            if ((M2C_FIELD(sh, s16 *, 0x24) & 0xFF00) == 0xD00 || (M2C_FIELD(sh, s16 *, 0x24) & 0xFF00) == 0xF00) {
                D_80144BE8_80142C40.f_D = 0x1E;
                Effect_SpawnAt_80142C40(0x109, &p);
                Camera_StartShake_80142C40(0);
                Sound_PlayFixed_80142C40(0x60);
                func_8013D9DC();
            } else {
                D_80144BE8_80142C40.f_D = 0x3C;
                D_80144BE8_80142C40.f_C = 7;
                func_801406F8(8);
                Effect_SpawnAt_80142C40(0x105, &p);
                Fx_SpawnFadeRing_80142C40(&p, 0, 0x300, 0);
                func_8013D4A4(&p);
                Camera_StartShake_80142C40(1);
                {
                    SVECTOR q = { g_Spike_80142C40.x - p.vx, g_Spike_80142C40.y - p.vy, g_Spike_80142C40.z - p.vz };
                    func_80070284_80142C40(&p, D_80144014_80142C40, 1, 0, &q);
                }
                Sound_PlayFixed_80142C40(0x6C);
                Sound_PlayFixed_80142C40(0x82);
                func_80140630_80142C40(0x32);
                func_8013D9DC();
                if (--bs->f_8E == 0) {
                    func_801423E8();
                    D_80144BE8_80142C40.f_C = 8;
                    D_80144BE8_80142C40.f_10 = 0xBE;
                    Spike_SetPlayMode_80142C40(0xE);
                }
            }
        }
    }
    if (D_80144BE8_80142C40.f_C < 8) {
        func_8013FAA4_80142C40();
        func_8013E8D4();
        func_8013F198();
        func_8013D60C_80142C40();
        func_8013E22C_80142C40();
        func_8013E564();
        func_801425EC();
        func_80142A48();
        func_8014063C();
        func_8013F598((u8 *)bs);
    }
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_80143854;
typedef struct { u8 pad_0[0x38]; s32 f_38; } Cam_80143854;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80143854 asm("g_Spike");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x224]; u8 f_254; u8 pad_255[0x97]; u8 f_2EC; } D_80144460_80143854 asm("D_80144460");
extern struct { u8 pad_0[0xC]; u8 f_C; u8 f_D; u8 f_E; u8 f_F; } D_80144BE8_80143854 asm("D_80144BE8");
extern s8 g_CurrentGadget;
extern u8 D_800E6916;
s32 VectorNormalSS_80143854(void *, void *) asm("VectorNormalSS");
s32 SquareRoot0(s32);
void func_8004AF78(void *);
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);

s32 func_80143854(Cam_80143854 *cam) {
    Scr_80143854 *sc = (Scr_80143854 *)0x1F800000;
    u8 *m = (u8 *)&D_80144460_80143854;
    SVECTOR v;
    s32 d;
    s32 h;
    s32 ay;

    if (D_80144BE8_80143854.f_E != 0) {
        return 0;
    }
    v.vy = 0;
    sc->spike.vx = g_Spike_80143854.x;
    sc->spike.vy = g_Spike_80143854.y - 0x80;
    sc->spike.vz = g_Spike_80143854.z;
    sc->eye.vx = *(s32*)(m+0x24);
    sc->eye.vz = *(s32*)(m+0x2C);
    v.vx = *(s32*)(m+0x24) - g_Spike_80143854.x;
    v.vz = *(s32*)(m+0x2C) - g_Spike_80143854.z;
    d = SquareRoot0(VectorNormalSS_80143854(&v, &v));
    if (d < 0x600) {
        d = 0x600;
    }
    if (d > 0xA00) {
        d = 0xA00;
    }
    h = d / 2;
    sc->eye.vy = h - 0x3600;
    ay = -0x2F40 - d / 3;
    sc->at.vx = sc->spike.vx - ((v.vx * cam->f_38) >> 12);
    sc->at.vy = ay;
    sc->at.vz = sc->spike.vz - ((v.vz * cam->f_38) >> 12);
    if (sc->at.vz > 0x9C4) {
        sc->at.vz = 0x9C4;
    }
    if (D_80144BE8_80143854.f_F == 0) {
        u8 c = D_80144BE8_80143854.f_C;
        if (c == 6) {
            sc->eye.vy = h - 0x3800;
        } else if ((u8)(c - 7) < 2) {
            d = 0x9C4;
            sc->eye.vy = h - 0x3400;
            sc->at.vy = ay - 0x4B0;
        } else if (c == 4) {
            d = 0x898;
            sc->eye.vy = h - 0x3470;
            sc->at.vy = ay - 0x200;
        } else if ((u8)(c - 1) < 2) {
            sc->eye.vy = h - 0x3680;
            d = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x7F) * 3 + 0x6A4;
            sc->at.vy = ay + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x3F) + 0xFFE0);
        } else if ((u8)(c - 0xD) < 2 || m[0x254] == 2 || m[0x2EC] == 2) {
            d = 0xAF0;
            sc->eye.vy += 0x200;
            sc->at.vy -= 0x5DC;
        } else if (c == 0xC) {
            d = 0x834;
            sc->at.vx /= 4;
            sc->at.vy = -0x30C0;
        }
    } else if (D_80144BE8_80143854.f_F == 1) {
        u8 c;
        if (D_80144BE8_80143854.f_C == 7) {
            d = 0x834;
            sc->at.vx /= 4;
            sc->at.vy = -0x30C0;
        }
        c = D_80144BF4;
        if (c == 8) {
            d = 0x3E8;
            sc->eye.vy -= 0x80;
            sc->at.vy += 0x80;
        } else if (c == 9) {
            sc->at.vy -= 0x230;
            d = 0xAF0;
        } else if ((u8)(c - 1) < 4) {
            d = 0xAF0;
            sc->eye.vy += 0x200;
            sc->at.vy -= 0x5DC;
        }
    }
    if (g_CurrentGadget == 3 && D_800E6916 != 1) {
        func_8004AF78(cam);
    }
    cam->f_38 -= 0x12C; cam->f_38 = (cam->f_38 + d) / 2;
    func_80047558(cam, 0x10, 0x18, 0x10);
    func_80047464(cam, 8, 0x18, 8);
    return 1;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
