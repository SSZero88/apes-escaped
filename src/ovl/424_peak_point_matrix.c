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
void func_8013FFFC(void);
extern s8 D_80142322;
extern M2C_UNK D_80142338;
M2C_UNK Puff_Spawn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8013DFB0(s32 arg0);

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D000 asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D000;
extern u8 *D_80142330[];
extern u8 *D_80142334[];
void Model_BindBonedAuto(void *, void *);

M2C_UNK func_8013D000(M2C_UNK i, M2C_UNK *obj, void *out) {
    u8 *bank = g_Game_8013D000.f_8244;
    AnimEnt_8013D000 *ent;
    u8 *s;
    u32 *q;

    D_80142330[i] = bank + (ent = (AnimEnt_8013D000 *)(i * 32 + (u32)(bank + M2C_FIELD(bank, s32 *, 8))))->f18;
    D_80142334[i] = s = g_Game_8013D000.f_8244 + ent->f1C;
    q = (u32 *)s + 1;
    *(u32 **)out = q;
    M2C_FIELD(obj, u32 **, 0x18) = q + *(u16 *)s;
    Model_BindBonedAuto(obj, D_80142330[i]);
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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D6BC;
typedef struct { Mat_8013D6BC m; Mat_8013D6BC w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013D6BC;
typedef struct { s16 x, y, z, vy; s8 vx, vz; u8 life; u8 pad; } Part_8013D6BC;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013D6BC;
extern Part_8013D6BC D_80143F08_8013D6BC[] asm("D_801423D8");
extern Mat_8013D6BC D_800E78C0_8013D6BC asm("g_ViewMatrix");
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

void func_8013D4CC(void) {
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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013DB94;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013DB94;
typedef struct { u8 pad0[0x14]; void *f_14; u8 pad18[0xC]; s32 x; s32 y; s32 z; u8 pad30[0x30]; SVECTOR f_60; } Mdl_8013DB94;
extern struct { u8 f_0; u8 f_1; u8 pad2[6]; u8 f_8; u8 f_9; u8 padA[2]; u16 f_C; } D_80142320_8013DB94 asm("D_80142320");
extern struct { u8 pad0[6]; u16 f_6; } *g_Spike_8013DB94 asm("g_Spike");
extern u8 g_ViewMatrix[];
extern u8 g_ProjVerts[];
extern s32 D_800EC358;
void SetRotMatrix(void *);
void SetTransMatrix(void *);
s32 RotTransPers(SVECTOR *, s32 *, s32 *, s32 *);
void Matrix_FromDirection(SVECTOR *, void *);
void *ScaleMatrix(void *, void *);
void Matrix_SetIdentity(void *);
void *RotMatrixY(s32, void *);
void *ApplyMatrixSV(void *, SVECTOR *, SVECTOR *);
void *memset(void *, s32, s32);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void Model_CycleVertexColors(void *, s32);
void Model_DrawCycledColors(s32, void *, void *);
void func_8013D0A0_8013DB94(s32, s32, void *, s32) asm("func_8013D0A0");

s32 func_8013DB94(Mdl_8013DB94 *m, void *scale, s32 flags) {
    SVECTOR pos;
    Mat_8013DB94 rm;
    Vec_8013DB94 v;
    s32 sv[2];
    s32 z;
    s16 sy;
    u32 n;

    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    pos.vx = m->x;
    pos.vy = m->y;
    pos.vz = m->z;
    z = RotTransPers(&pos, &sv[0], &sv[1], &sv[1]);
    { s32 t = ((s16 *)sv)[1]; sy = t; }
    if ((u16)(((s16 *)sv)[0] + 0x80) > 0x280 || sy < -0x80 || sy >= 0x1B9 || z > 0x1000 || z <= 0) {
        return 1;
    }
    Matrix_FromDirection(&m->f_60, m->f_14);
    ScaleMatrix(m->f_14, scale);
    if (D_80142320_8013DB94.f_8) {
        Matrix_SetIdentity(&rm);
        RotMatrixY(0x71, &rm);
        ApplyMatrixSV(&rm, &m->f_60, &m->f_60);
        if (!D_80142320_8013DB94.f_9) {
            n = D_80142320_8013DB94.f_C;
            memset(&v, 0, 0x10);
            v.vx = 0x1000 - (n << 7);
            v.vy = (n << 10) + 0x1000;
            v.vz = 0x1000 - (n << 7);
            ScaleMatrix(m->f_14, &v);
            ApplyMatrixSV(&rm, &m->f_60, &m->f_60);
        }
    }
    Model_CalcKeyedJointMatrices(m, 3);
    Model_ProjectBonedVerts(m);
    if ((u32)(D_80142320_8013DB94.f_1 - 2) < 3 || D_80142320_8013DB94.f_8) {
        Model_CycleVertexColors(g_ProjVerts, g_Spike_8013DB94->f_6);
        Model_DrawCycledColors(D_800EC358, g_ProjVerts, m);
    } else {
        func_8013D0A0_8013DB94(D_800EC358, (s32)g_ProjVerts, m, flags);
    }
    return 0;
}

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x52]; u8 f_7E; u8 pad7F[7]; s16 f_86; } Mdl_8013DDC4;
extern struct { u8 f_0; u8 f_1; u8 pad2[2]; s32 f_4; } D_80142320_8013DDC4 asm("D_80142320");
extern s32 D_80141D00;
s32 rsin(s32);

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

typedef struct { SVECTOR at; SVECTOR eye; } Scr_8013E4B4;
typedef struct { u8 f_0; u8 f_1; u8 pad2[0xC]; u16 f_E; } St_8013E4B4;
extern St_8013E4B4 D_80142320_8013E4B4 asm("D_80142320");
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } Ent_8013E4B4;
extern Ent_8013E4B4 D_80142338_8013E4B4 asm("D_80142338");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E4B4 asm("g_Spike");
extern s8 g_CurrentGadget;
extern u8 D_800E6916;
s32 rcos(s32);
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004CEA8(s8);
void func_8004AF78(void *);

s32 func_8013E4B4(void *cam) {
    SVECTOR v;
    s32 t;
    s32 ang;
    s32 r;
    s32 r2;
    Scr_8013E4B4 *s = (Scr_8013E4B4 *)0x1F800000;
    Ent_8013E4B4 *b = &D_80142338_8013E4B4;
    St_8013E4B4 *st = &D_80142320_8013E4B4;

    if (st->f_1 >= 0x14) {
        return func_8013E8A8(cam);
    }
    if (D_80142320_8013E4B4.f_0 != 0 && g_Spike_8013E4B4.y < -0xA20) {
        r2 = st->f_E;
        ang = (r2 * 48 + 0x400) % 0x1000;
        t = r2 * 32;
        s->eye.vx = g_Spike_8013E4B4.x;
        s->eye.vy = g_Spike_8013E4B4.y - 0x40;
        s->eye.vz = g_Spike_8013E4B4.x;
        r = t + 0x320;
        s->at.vx = s->eye.vx + ((rcos(ang) * r) >> 12);
        t += 0x1F4;
        s->at.vy = s->eye.vy - t;
        s->at.vz = s->eye.vz + ((rsin(ang) * r) >> 12);
        func_80047558(cam, 2, 2, 2);
        func_80047464(cam, 2, 2, 2);
        if (st->f_E != 0) {
            st->f_E--;
        }
        if (st->f_E < 0x33) {
            func_8004CEA8(4);
        }
        return 1;
    }
    v.vx = b->x - g_Spike_8013E4B4.x;
    v.vy = b->y - g_Spike_8013E4B4.y;
    v.vz = b->z - g_Spike_8013E4B4.z;
    VectorNormalSS(&v, &v);
    s->at.vx = g_Spike_8013E4B4.x - ((v.vx * 45) >> 8);
    s->at.vy = g_Spike_8013E4B4.y - 0x104;
    s->at.vz = g_Spike_8013E4B4.z - ((v.vz * 45) >> 8);
    s->eye.vx = b->x;
    s->eye.vy = b->y;
    s->eye.vz = b->z;
    if ((u8)(D_80142320_8013E4B4.f_1 - 0xC) < 2) {
        s->at.vx = g_Spike_8013E4B4.x - v.vx / 4;
        s->at.vz = g_Spike_8013E4B4.z - v.vz / 4;
        if (D_80142320_8013E4B4.f_1 == 0xC) {
            s->at.vx = b->x - ((v.vx * 225) >> 10);
            s->at.vy = b->y - 0x5F4;
            s->at.vz = b->z - ((v.vz * 225) >> 10);
            s->eye.vx = b->x;
            s->eye.vy = b->y - 0x12C;
            s->eye.vz = b->z;
        } else {
            s->at.vy -= 0x978;
            s->eye.vx = (b->x + g_Spike_8013E4B4.x * 3) / 4;
            s->eye.vy += 0x960;
            s->eye.vz = (b->z + g_Spike_8013E4B4.z * 3) / 4;
        }
    }
    if (g_CurrentGadget == 3 && D_800E6916 != 1) {
        func_8004AF78(cam);
    }
    func_80047558(cam, 8, 0x10, 8);
    func_80047464(cam, 8, 0x10, 8);
    return 1;
}

typedef struct { SVECTOR at; SVECTOR eye; } Scr_8013E8A8;
typedef struct { u8 f_0; u8 f_1; u8 pad2[6]; u8 f_8; } St_8013E8A8;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } Ent_8013E8A8;
extern St_8013E8A8 D_80142320_8013E8A8 asm("D_80142320");
extern Ent_8013E8A8 D_80142338_8013E8A8 asm("D_80142338");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E8A8 asm("g_Spike");

s32 func_8013E8A8(void *cam) {
    SVECTOR v;
    s32 dx, dz;
    Scr_8013E8A8 *s = (Scr_8013E8A8 *)0x1F800000;
    Ent_8013E8A8 *b = &D_80142338_8013E8A8;
    St_8013E8A8 *st = &D_80142320_8013E8A8;

    if (st->f_8 != 0) {
        func_8013EA9C(cam);
        return 1;
    }
    v.vx = b->x - g_Spike_8013E8A8.x;
    v.vy = b->y - g_Spike_8013E8A8.y;
    v.vz = b->z - g_Spike_8013E8A8.z;
    VectorNormalSS(&v, &v);
    dx = v.vx;
    dz = v.vz;
    s->at.vx = g_Spike_8013E8A8.x - ((dx * 381) >> 10);
    s->at.vy = g_Spike_8013E8A8.y - 0x52C;
    s->at.vz = g_Spike_8013E8A8.z - ((dz * 381) >> 10);
    s->eye.vx = b->x;
    s->eye.vy = b->y;
    s->eye.vz = b->z;
    if ((u8)(st->f_1 - 0x16) < 5) {
        s->at.vx = g_Spike_8013E8A8.x - ((dx * 32) >> 8);
        s->at.vy = g_Spike_8013E8A8.y - 0x12C;
        s->at.vz = g_Spike_8013E8A8.z - ((dz * 32) >> 8);
    }
    func_80047558(cam, 0xC, 0x10, 0xC);
    func_80047464(cam, 0xC, 0x10, 0xC);
    return 1;
}

extern struct { u8 pad0[8]; u8 f_8; s8 f_9; s16 f_A; } D_80142320_8013EA24 asm("D_80142320");
M2C_UNK Collision_Remove(void *);

void func_8013EA24(void) {
    u8 *e = (u8 *)&D_80142338;

    if (D_80142320_8013EA24.f_8 == 0) {
        Collision_Remove(e + 0x24);
        D_80142320_8013EA24.f_8 = 1;
        D_80142320_8013EA24.f_9 = 2;
        D_80142320_8013EA24.f_A = 0x10;
        Pad_Vibrate(1, 0xC8, 3);
        Sound_PlayFixed(0x37);
        Sound_PlayFixed(0x38);
    }
}

typedef struct { u8 pad0[0xA]; s16 ax, ay, az; u8 pad10[2]; s16 bx, by, bz; } Cam_8013EA9C;
typedef struct { s16 x, y, z, pad; } Ofs_8013EA9C;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013EA9C;
typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[5]; u8 f_9; u16 f_A; u16 f_C; } Ctl_8013EA9C;
extern Ctl_8013EA9C D_80142320_8013EA9C asm("D_80142320");
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Bo_8013EA9C;
extern Bo_8013EA9C D_80142338_8013EA9C asm("D_80142338");
extern struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 f_60; u8 pad62[2]; s16 f_64; } g_Spike_8013EA9C asm("g_Spike");
extern struct { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[2]; u16 f_812A; } g_Game_8013EA9C asm("g_Game");
extern Ofs_8013EA9C D_801422F8_8013EA9C[] asm("D_801422F8");
extern u8 D_80142250_8013EA9C[] asm("D_80142250");
void Effect_SpawnAt_8013EA9C(s32, void *) asm("Effect_SpawnAt");
s32 func_80070284_8013EA9C(void *, void *, s32, s32, s32) asm("func_80070284");
s32 Camera_StartShake_8013EA9C(s32) asm("Camera_StartShake");
s32 Sound_PlayFixed_8013EA9C(s32) asm("Sound_PlayFixed");
s32 Pad_Vibrate_8013EA9C(s32, s32, s32) asm("Pad_Vibrate");
void *memset_8013EA9C(void *, s32, s32) asm("memset");
s32 Game_SetMode(s32, s32, s32);
void func_8004BC9C(void);
void func_8006C6A4_8013EA9C(void *) asm("func_8006C6A4");

void func_8013EA9C(Cam_8013EA9C *cam) {
    SVECTOR sv;
    Vec_8013EA9C copy;
    Vec_8013EA9C pos;
    s32 dx, dz, y;
    Bo_8013EA9C *bo = &D_80142338_8013EA9C;
    Ctl_8013EA9C *ctl = &D_80142320_8013EA9C;

    if (ctl->f_A == 0x10) {
        dx = g_Spike_8013EA9C.f_60 >> 4;
        y = g_Spike_8013EA9C.y;
        dz = g_Spike_8013EA9C.f_64 >> 4;
        bo->x = g_Spike_8013EA9C.x + dx;
        bo->y = y;
        bo->z = g_Spike_8013EA9C.z + dz;
        sv.vx = bo->x;
        sv.vy = bo->y;
        sv.vz = bo->z;
        Effect_SpawnAt_8013EA9C(0x113, &sv);
        func_80070284_8013EA9C(&sv, D_80142250_8013EA9C, 1, 0, 0);
        func_80070284_8013EA9C(&sv, D_80142250_8013EA9C + 0x54, 2, 3, 0);
        Camera_StartShake_8013EA9C(0);
        Sound_PlayFixed_8013EA9C(0x36);
        Sound_PlayFixed_8013EA9C(0x39);
        Sound_PlayFixed_8013EA9C(0x3B);
        Sound_PlayFixed_8013EA9C(0x6C);
        cam->ax = bo->x + D_801422F8_8013EA9C[ctl->f_9].x;
        cam->ay = bo->y + D_801422F8_8013EA9C[ctl->f_9].y;
        cam->az = bo->z + D_801422F8_8013EA9C[ctl->f_9].z;
        cam->bx = bo->x;
        cam->by = bo->y - 0x80;
        cam->bz = bo->z;
    }
    if (ctl->f_9 != 0) {
        cam->ax = (cam->ax * 7 + cam->bx) / 8;
        cam->ay = (cam->ay * 7 + cam->by) / 8;
        cam->az = (cam->az * 7 + cam->bz) / 8;
    }
    if (D_80142320_8013EA9C.f_C < 0x32 && D_80142320_8013EA9C.f_A % 5 == 4) {
        Pad_Vibrate_8013EA9C(1, 0xC8, 3);
    }
    if (--D_80142320_8013EA9C.f_A == 0) {
        D_80142320_8013EA9C.f_A = 0x10;
        if (--D_80142320_8013EA9C.f_9 == 0) {
            memset_8013EA9C(&pos, 0, 0x10);
            pos.vx = g_Spike_8013EA9C.x + g_Spike_8013EA9C.f_60 / 16;
            pos.vy = g_Spike_8013EA9C.y;
            pos.vz = g_Spike_8013EA9C.z + g_Spike_8013EA9C.f_64 / 16;
            copy = pos;
            func_8004BC9C();
            func_8006C6A4_8013EA9C(&copy);
            Sound_PlayFixed_8013EA9C(0x6C);
            Camera_StartShake_8013EA9C(1);
            D_80142320_8013EA9C.f_A = 0xFFFF;
            D_80142320_8013EA9C.f_C = 0;
        }
    }
    if (D_80142320_8013EA9C.f_9 == 0) {
        D_80142320_8013EA9C.f_C++;
        if (D_80142320_8013EA9C.f_A == 0xFFD3) {
            Game_SetMode(0x1D, g_Game_8013EA9C.f_8126, g_Game_8013EA9C.f_812A);
        } else if (D_80142320_8013EA9C.f_A == 0xFFD5) {
            D_800E69BE = 1;
        } else if (D_80142320_8013EA9C.f_A == 0xFFDF) {
            D_80142320_8013EA9C.f_3 = 0;
        }
    }
}

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

typedef struct { s16 x; s16 y; s16 z; u8 f_6; u8 f_7; u8 f_8; u8 pad9; s16 f_A; } Pt_8013EEC0;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } Ent_8013EEC0;
extern Pt_8013EEC0 D_801427C0_8013EEC0[] asm("D_801427C0");

M2C_UNK func_8013EEC0(void *arg0, M2C_UNK arg1) {
    Pt_8013EEC0 *p;
    s32 i;

    for (i = 0x1F, p = D_801427C0_8013EEC0; i >= 0; i--, p++) {
        p->f_6 = 0x20;
        p->f_7 = (g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 1;
        p->f_8 = (g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0xF;
        if (arg1 != 0) {
            p->x = ((Ent_8013EEC0 *)arg0)->x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 16;
            p->y = ((Ent_8013EEC0 *)arg0)->y + (s16)(((g_RandSeed = g_RandSeed * 5 + 1) >> 4 & 0xFF0) - 0xA4E);
            p->z = ((Ent_8013EEC0 *)arg0)->z + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 16;
            p->f_A = -0x24E;
        } else {
            p->x = ((Ent_8013EEC0 *)arg0)->x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 8;
            p->y = ((Ent_8013EEC0 *)arg0)->y - ((g_RandSeed = g_RandSeed * 5 + 1) >> 6 & 0x3FC);
            p->z = ((Ent_8013EEC0 *)arg0)->z + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 8;
            { register s32 k asm("$2") = -0x40; p->f_A = k; }
        }
    }
}

#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
typedef struct { u32 addr : 24; u32 len : 8; } Tag_8013F06C;
typedef struct { u32 tag; u32 mode; u32 rgb0; s32 xy0; u32 rgb1; s32 xy1; } Line_8013F06C;
extern struct { u8 pad_0[0x4]; Line_8013F06C *f_4; u8 pad_8[4]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013F06C asm("g_Game");

void func_8013F06C(Ent_8013EEC0 *o) {
    SVECTOR v;
    s32 sxy0[1];
    s32 z;
    s32 sxy1[1];
    s32 t;
    Pt_8013EEC0 *p;
    Line_8013F06C *l;
    u32 *ot;
    s32 i;

    for (i = 0x1F, p = D_801427C0_8013EEC0; i >= 0; i--, p++) {
        if (p->f_6 != 0) {
            if (p->f_8 != 0) {
                p->f_8--;
            } else {
                p->f_6--;
                p->x = (o->x + p->x * 7) / 8;
                p->y = (o->y + p->f_A + p->y * 7) / 8;
                p->z = (o->z + p->z * 7) / 8;
            }
        }
    }
    SetRotMatrix(g_ViewMatrix);
    SetTransMatrix(g_ViewMatrix);
    l = g_Game_8013F06C.f_4;
    ot = (u32 *)(g_Game_8013F06C.f_80 + g_Game_8013F06C.f_C * 0x4078);
    for (i = 0x1F, p = D_801427C0_8013EEC0; i >= 0; i--, p++) {
        if (p->f_6 == 0 || p->f_8 != 0) {
            continue;
        }
        gte_ldv0(p);
        gte_rtps();
        gte_stsxy(sxy0);
        gte_stszotz(&z);
        if ((u32)(z - 1) >= 0xFFF) {
            break;
        }
        if (p->f_7 == 0) {
            v.vx = o->x;
            v.vy = o->y + p->f_A;
            v.vz = o->z;
            gte_ldv0(&v);
            gte_rtps();
            gte_stsxy(sxy1);
            {
            __asm__ volatile("lui $5,0xE100");
            ((u8 *)l)[3] = 5;
            l->rgb0 = 0x52A05A28;
            l->xy0 = sxy0[0];
            l->rgb1 = 0x1E140A;
            t = sxy1[0];
            __asm__ volatile("ori $5,$5,0x220; sw $5,%0" : "=m"(l->mode));
            }
            l->xy1 = t;
            ((Tag_8013F06C *)l)->addr = ((Tag_8013F06C *)&ot[z])->addr;
            ((Tag_8013F06C *)&ot[z])->addr = (u32)l;
            l++;
        } else {
            Effect_Spawn(0xCF, (s32)p, (M2C_UNK *)D_80141F88_8013E120, 0);
        }
    }
    g_Game_8013F06C.f_4 = l;
}

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

typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x14]; s16 f_44; s16 f_46; u8 pad_48[8]; u32 f_50; u8 pad_54[0xC]; SVECTOR f_60; u8 pad_68[0x12]; u8 f_7A; u8 f_7B; u8 pad_7C[2]; u8 f_7E; u8 pad_7F; s16 f_80; s16 f_82; s16 f_84; s16 f_86; u8 f_88; u8 f_89; s16 f_8A; u8 pad_8C[4]; u16 f_90; } Boss_8013F464;
typedef struct { u8 f_0; u8 f_1; u8 pad_2[2]; s32 f_4; } St_8013F464;
typedef struct { s16 x, y, z, pad; } Pt_8013F464;
extern Boss_8013F464 D_80142338_8013F464 asm("D_80142338");
extern St_8013F464 D_80142320_8013F464 asm("D_80142320");
extern SVECTOR D_80142310_8013F464 asm("D_80142310");
extern Pt_8013F464 D_80141CC0_8013F464[] asm("D_80141CC0");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F464 asm("g_Spike");
extern u8 D_801420AC_8013F464[] asm("D_801420AC");
extern u8 D_80142100_8013F464[] asm("D_80142100");
extern u8 D_80142154_8013F464[] asm("D_80142154");
extern u8 D_801421A8_8013F464[] asm("D_801421A8");
void Camera_StartShake_8013F464(s32) asm("Camera_StartShake");
void Effect_SpawnAt_8013F464(s32, void *) asm("Effect_SpawnAt");
void Sound_PlayFixed_8013F464(s32) asm("Sound_PlayFixed");
void Puff_Spawn_8013F464(void *, s32, s32, s32) asm("Puff_Spawn");
void VectorNormalSS_8013F464(void *, void *) asm("VectorNormalSS");
void func_80070284_8013F464(void *, void *, s32, s32, void *) asm("func_80070284");
void Fx_SpawnFadeRing_8013F464(void *, s32, s32, s32) asm("Fx_SpawnFadeRing");
void Fx_DebrisExplosion_8013F464(s32, s32, s32) asm("Fx_DebrisExplosion");
void func_8006D548_8013F464(void *) asm("func_8006D548");
void func_8013DFB0_8013F464(void *) asm("func_8013DFB0");
void func_8013EEC0_8013F464(void *, s32) asm("func_8013EEC0");
void func_8013D364_8013F464(void *) asm("func_8013D364");
void func_8013D9E0_8013F464(s32) asm("func_8013D9E0");
void func_8013E044_8013F464(void *) asm("func_8013E044");
void func_8013DDC4_8013F464(void *) asm("func_8013DDC4");
void func_8013D89C(void);
void func_8013D9B8(s32 arg0);
void func_8013E120(void);
void func_80140E70(void);
void func_8013F3DC(void *arg0);
void func_8013D4CC_8013F464(void) asm("func_8013D4CC");
void func_801409D4_8013F464(void) asm("func_801409D4");
void func_8013F06C_8013F464(void *) asm("func_8013F06C");
void func_80140FFC_8013F464(void) asm("func_80140FFC");
#define RAND_8013F464() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013F464(void) {
    SVECTOR v;
    SVECTOR w;
    SVECTOR u;
    Boss_8013F464 *b = &D_80142338_8013F464;
    s32 i;
    s32 r;
    s32 old;
    u8 ph;

    if (D_80142320_8013F464.f_0 != 0) {
        return;
    }
    if (D_80142320_8013F464.f_1 >= 0x14) {
        func_80140FFC_8013F464();
        return;
    }
    D_80142310_8013F464.vx = b->x;
    D_80142310_8013F464.vy = b->y - 0x24E;
    D_80142310_8013F464.vz = b->z;
    if (D_80142320_8013F464.f_1 != 0x13) {
        v.vy = 0;
        v.vx = g_Spike_8013F464.x - D_80142310_8013F464.vx;
        v.vz = g_Spike_8013F464.z - D_80142310_8013F464.vz;
        VectorNormalSS_8013F464(&v, &b->f_60);
    }
    switch (D_80142320_8013F464.f_1) {
    case 1:
        func_8013F3A4(b, 0);
        if (b->f_89 == 0) {
            if (!((RAND_8013F464() >> 8) & 0x3F)) {
                func_8013F398(10);
                func_8013F3A4(b, 2);
                func_8013D9B8(0xAE);
            }
        } else if (b->f_8A != 0 && --b->f_8A == 0) {
            b->f_89--;
            func_8013F398(2);
            func_8013F3A4(b, 7);
            b->f_7B = 1;
            D_80142320_8013F464.f_4 = 0;
            Fx_SpawnFadeRing_8013F464(&D_80142310_8013F464, 1, -0x44C, 8);
            Fx_SpawnFadeRing_8013F464(&D_80142310_8013F464, 1, -0x1C2, 0);
            for (i = 3; i > 0; i--) {
                w.vx = (RAND_8013F464() >> 8) << 4;
                w.vy = (RAND_8013F464() >> 8) << 4;
                w.vz = (RAND_8013F464() >> 8) << 4;
                func_80070284_8013F464(&D_80142310_8013F464, D_80142100_8013F464, 1, i << 1, &w);
            }
            Sound_PlayFixed_8013F464(0xAD);
            b->f_90 = 0;
        }
        break;
    case 2:
        if (++D_80142320_8013F464.f_4 >= 0xC) {
            func_8013DFB0_8013F464(&D_80142310_8013F464);
            func_8013F398(3);
            Effect_SpawnAt_8013F464(0x112, &D_80142310_8013F464);
            D_80142320_8013F464.f_4 = 0;
            func_80070284_8013F464(&D_80142310_8013F464, D_801420AC_8013F464, 2, 6, 0);
        }
        break;
    case 3:
        if (++D_80142320_8013F464.f_4 >= 0x1E) {
            do {
                r = (RAND_8013F464() >> 8) & 7;
            } while (b->f_88 == r);
            b->f_88 = r;
            b->x = D_80141CC0_8013F464[r].x;
            b->y = D_80141CC0_8013F464[r].y;
            b->z = D_80141CC0_8013F464[r].z;
            D_80142320_8013F464.f_4 = 0;
            func_8013F398(4);
            func_8013F3A4(b, 8);
            b->f_7B = 1;
            Sound_PlayFixed_8013F464(0xAC);
        }
        break;
    case 4:
        if (++D_80142320_8013F464.f_4 == 1) {
            Fx_SpawnFadeRing_8013F464(&D_80142310_8013F464, 1, 0x400, 8);
            Fx_SpawnFadeRing_8013F464(&D_80142310_8013F464, 1, 0x258, 0);
            func_80070284_8013F464(&D_80142310_8013F464, D_80142154_8013F464, 2, 6, 0);
        }
        if (D_80142320_8013F464.f_4 >= 0x10) {
            func_8013DFB0_8013F464(&D_80142310_8013F464);
            func_8013F398(1);
            b->f_89 = 0;
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 10:
        if (b->f_7A == 0) {
            func_8013F398(0xB);
            func_8013F3A4(b, 3);
            D_80142320_8013F464.f_4 = 0x28;
            func_8013EEC0_8013F464(b, 1);
        }
        break;
    case 11:
        if (--D_80142320_8013F464.f_4 == 0) {
            func_8013F398(0xC);
            func_8013F3A4(b, 4);
            D_80142320_8013F464.f_4 = 0;
            func_8013D9E0_8013F464(0xAE);
            func_8013D9B8(0xAF);
            Sound_PlayFixed_8013F464(0xB2);
        }
        break;
    case 12:
        D_80142320_8013F464.f_4++;
        if (b->f_7A == 0) {
            func_8013F398(0xD);
            func_8013F3A4(b, 5);
            D_80142320_8013F464.f_4 = 0x78;
            Fx_SpawnFadeRing_8013F464(&D_80142310_8013F464, 1, 0x136, 0);
            func_8013E044_8013F464(&D_80142310_8013F464);
            Effect_SpawnAt_8013F464(0x112, &D_80142310_8013F464);
            func_80070284_8013F464(&D_80142310_8013F464, D_801420AC_8013F464, 1, 0, &b->f_60);
            func_8013D9E0_8013F464(0xAF);
            func_8013D9B8(0xB0);
        }
        break;
    case 13:
        if (--D_80142320_8013F464.f_4 == 0) {
            func_8013F398(0xE);
            func_8013F3A4(b, 6);
            func_8013D9E0_8013F464(0xB0);
        }
        break;
    case 14:
        if (b->f_7A == 0) {
            func_8013F398(1);
            func_8013F3A4(b, 0);
            b->f_89 = 1;
            b->f_8A = ((RAND_8013F464() >> 8) & 0x1F) + 0x3C;
        }
        break;
    case 15:
    case 16:
    case 17:
        break;
    case 18:
        if (b->f_7A == 0) {
            func_8013F398(1);
            func_8013F3A4(b, 0);
        }
        break;
    case 19:
        b->f_44 = 1;
        b->f_46 = 1;
        w.vx = D_80142310_8013F464.vx + (((u16)RAND_8013F464() >> 8) - 0x80);
        w.vy = D_80142310_8013F464.vy + (((u16)RAND_8013F464() >> 8) - 0x80) * 2;
        w.vz = D_80142310_8013F464.vz + (((u16)RAND_8013F464() >> 8) - 0x80);
        func_8006D548_8013F464(&w);
        Effect_SpawnAt_8013F464(7, &w);
        if (!((RAND_8013F464() >> 8) & 7)) {
            Effect_SpawnAt_8013F464(0x102, &w);
            Sound_PlayFixed_8013F464(0x6C);
        }
        w.vy = 0;
        w.vx = -0x100 - b->x;
        w.vz = -0x100 - b->z;
        VectorNormalSS_8013F464(&w, &w);
        b->y += b->f_82;
        b->x += (s16)(w.vx / 96);
        b->z += (s16)(w.vz / 96);
        if (b->f_82 < 0x20) {
            b->f_82 += 2;
        }
        b->f_86 = 0;
        if (b->y >= -0x980) {
            u.vx = b->x;
            u.vy = -0xA40;
            u.vz = b->z;
            Fx_DebrisExplosion_8013F464(u.vx, u.vy, u.vz);
            func_8013D364_8013F464(&u);
            Camera_StartShake_8013F464(2);
            Sound_PlayFixed_8013F464(0x6C);
            func_8013D89C();
            func_80140E70();
            func_8013F398(0x14);
            b->f_80 = w.vx / 128;
            b->f_82 = -0x30;
            b->f_84 = w.vz / 128;
            b->f_90 = 0;
        }
        break;
    }
    if ((u8)(D_80142320_8013F464.f_1 - 0xB) < 2) {
        if (D_80142320_8013F464.f_1 == 0xB) {
            if (D_80142320_8013F464.f_4 & 1) {
                w.vx = (RAND_8013F464() >> 8) << 4;
                w.vy = (RAND_8013F464() >> 8) << 4;
                w.vz = (RAND_8013F464() >> 8) << 4;
                func_80070284_8013F464(&D_80142310_8013F464, D_801421A8_8013F464, 1, 0, &w);
            }
            if (!(D_80142320_8013F464.f_4 & 3)) {
                w.vx = (RAND_8013F464() >> 8) << 4;
                w.vy = (RAND_8013F464() >> 8) << 4;
                w.vz = (RAND_8013F464() >> 8) << 4;
                func_80070284_8013F464(&D_80142310_8013F464, D_80142154_8013F464, 1, 0, &w);
            }
        }
        Puff_Spawn_8013F464(&D_80142310_8013F464, 0, 0x101, 0xBB8);
    }
    if (b->f_90 != 0) {
        b->f_90--;
    }
    if ((b->f_50 >> 28) == 0xB) {
        ph = D_80142320_8013F464.f_1;
        if (ph == 1 && b->f_90 == 0) {
            func_8013D364_8013F464(&D_80142310_8013F464);
            Camera_StartShake_8013F464(1);
            if (--b->f_7E == 0) {
                Sound_PlayFixed_8013F464(0xB3);
                Sound_PlayFixed_8013F464(0x6C);
                func_8013F398(0x13);
                b->f_82 = -0x1E;
            } else {
                Fx_DebrisExplosion_8013F464(D_80142310_8013F464.vx, D_80142310_8013F464.vy, D_80142310_8013F464.vz);
                func_8013F398(0x12);
                func_8013F3A4(b, 1);
                b->f_7B = ph;
                Sound_PlayFixed_8013F464(0x6C);
                Sound_PlayFixed_8013F464(0xB3);
            }
            b->f_90 = 0xFFFF;
            func_8013D89C();
        } else {
            Effect_SpawnAt_8013F464(0x117, &D_80142310_8013F464);
            Camera_StartShake_8013F464(0);
            Sound_PlayFixed_8013F464(0x60);
            func_8013D89C();
            if (b->f_90 < 0x10) {
                b->f_90 = 0x10;
            }
        }
    }
    func_8013F3DC(b);
    func_8013DDC4_8013F464(b);
    func_8013E120();
    func_8013D4CC_8013F464();
    func_801409D4_8013F464();
    func_8013F06C_8013F464(b);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

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

typedef struct { s32 x, y, z, pad; } V4_801400F4;
typedef struct { s16 vx, vy, vz; } P3_801400F4;
typedef struct { u32 *coll; P3_801400F4 pos; u8 age; u8 state; s16 vx, vy, vz; s16 radius; s32 ang2; s32 ang1; s16 spd; u8 bright; u8 pad1F; } Orb_801400F4;
extern Orb_801400F4 D_80142940_801400F4[4] asm("D_80142940");
typedef struct { u8 pad_0[0x24]; s32 x, y, z; } Boss_801400F4;
extern Boss_801400F4 D_80142338_801400F4 asm("D_80142338");
extern struct { u8 pad_0[0x24]; s32 x, y, z; } g_Spike_801400F4 asm("g_Spike");
extern struct { u8 pad_0[2]; u8 f_2; } D_80142320_801400F4 asm("D_80142320");
extern u8 D_801421FC[];
void Effect_Spawn_801400F4(s32, void *, void *, s32) asm("Effect_Spawn");
s32 Sound_PlayFixed_801400F4(s32) asm("Sound_PlayFixed");
s32 VectorNormalSS_801400F4(void *, void *) asm("VectorNormalSS");
s32 Camera_StartShake_801400F4(s32) asm("Camera_StartShake");
void Effect_SpawnAt_801400F4(s32, void *) asm("Effect_SpawnAt");
void func_80070284_801400F4(void *, void *, s32, s32, void *) asm("func_80070284");
void func_8013D914(s32 arg0);
void func_8013D310(void *arg0, s32 arg1, s32 arg2, s16 arg3);
void *memset_801400F4(void *, s32, s32) asm("memset");
void Shadow_Draw_801400F4(void *, s32, s32, s32) asm("Shadow_Draw");

void func_801400F4(void) {
    Boss_801400F4 *bp = &D_80142338_801400F4;
    Orb_801400F4 *e;
    s32 i;
    s32 r;
    s32 r2;
    s32 col;
    s32 n;
    SVECTOR d;
    V4_801400F4 b;
    V4_801400F4 a;

    for (i = 3, e = D_80142940_801400F4; i >= 0; i--, e++) {
        if (e->state == 0) {
            continue;
        }
        switch (e->state) {
        case 1:
            e->ang1 = (e->ang1 + e->spd) % 0x1000;
            e->ang2 = (e->ang2 + 0xAA) % 0x1000;
            r = e->age & 0x1F;
            if (r >= 0x10) {
                r = 0x1F - r;
            }
            r = r * 8 + 0x100;
            e->pos.vx = bp->x + ((rcos(e->ang1) * r) >> 12);
            r2 = ((rsin(e->ang2) * r) >> 13) + 0x100;
            e->pos.vy = bp->y - r2;
            e->pos.vz = bp->z + ((rsin(e->ang1) * r) >> 12);
            Effect_Spawn_801400F4(0xCB, &e->pos, &D_80141F88, 0);
            if (e->age > 0x80) {
                e->state = 2;
                e->vx = (e->pos.vx - bp->x) / 8;
                e->vy = (e->pos.vy - bp->y) / 8 - 0x30;
                e->vz = (e->pos.vz - bp->z) / 8;
                Sound_PlayFixed_801400F4(0x8F);
                if (D_80142320_801400F4.f_2 != 0) {
                    Sound_PlayFixed_801400F4(0xB2);
                    D_80142320_801400F4.f_2 = 0;
                }
            }
            e->bright = e->age + 0x18;
            if (e->bright > 0x60) {
                e->bright = 0x60;
            }
            if (e->age < 0x10) {
                e->radius = (0x10 - e->age) * 8 + 0x10;
            } else {
                e->radius = e->age + 0x10;
                if (e->radius > 0x60) {
                    e->radius = 0x60;
                }
            }
            break;
        case 2:
            e->pos.vx += e->vx;
            e->pos.vy += e->vy;
            e->pos.vz += e->vz;
            e->vx = e->vx * 7 / 8;
            e->vy = e->vy * 7 / 8;
            e->vz = e->vz * 7 / 8;
            d.vx = g_Spike_801400F4.x - e->pos.vx;
            d.vy = g_Spike_801400F4.y - (s16)(e->pos.vy + 0x10);
            d.vz = g_Spike_801400F4.z - e->pos.vz;
            VectorNormalSS_801400F4(&d, &d);
            e->vx += d.vx / 256;
            e->vz += d.vz / 256;
            if ((e->pos.vx - g_Spike_801400F4.x) * (e->pos.vx - g_Spike_801400F4.x) + (e->pos.vz - g_Spike_801400F4.z) * (e->pos.vz - g_Spike_801400F4.z) <= 0xFFFF || e->age >= 0xB5) {
                e->vy += 8;
            } else {
                e->vy += d.vy / 256;
            }
            e->vx = e->vx < -0x30 ? -0x30 : (e->vx > 0x30 ? 0x30 : e->vx);
            e->vz = e->vz < -0x30 ? -0x30 : (e->vz > 0x30 ? 0x30 : e->vz);
            Effect_Spawn_801400F4(0xCC, &e->pos, &D_80141F88, 0);
            if (e->pos.vy >= -0xA20 || (e->coll != NULL && (e->coll[0xB] >> 28) == 6)) {
                e->state = 0;
                e->pos.vy = -0xA20;
                Camera_StartShake_801400F4(0);
                Effect_SpawnAt_801400F4(0x112, &e->pos);
                Fx_SpawnFadeRing(&e->pos, 5, 0x12C, 0);
                func_80070284_801400F4(&e->pos, D_801421FC, 1, 0, 0);
                Sound_PlayFixed_801400F4(0x93);
                if ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7) == 0) {
                    func_8013D914((s32)&e->pos);
                }
                continue;
            }
            func_8013D310(e, (s32)&D_80142338_801400F4, 0x50, 0x200);
            break;
        }
        if (e->age < 0xFF) {
            e->age++;
        }
        n = 3;
        col = (e->bright << 16) | (e->bright << 8) | e->bright;
        if (e->state == 2) {
            n = 5;
        }
        Fx_DrawFadeRing(&e->pos, e->radius, n, col);
        Fx_DrawFadeRing(&e->pos, e->radius / 2, 1, col);
        memset_801400F4(&a, 0, 0x10);
        a.x = e->pos.vx;
        a.y = e->pos.vy;
        a.z = e->pos.vz;
        b = a;
        Shadow_Draw_801400F4(&b, -0xA10, 0x40, 0);
    }
}

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

#define gte_ldv3c_(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mtx_801409D4;
typedef struct { SVECTOR v[3]; u8 pad[8]; } Tri_801409D4;
typedef struct { Mtx_801409D4 m; Mtx_801409D4 cam; SVECTOR rot; Tri_801409D4 tri[4]; s32 sxy[3]; s32 otz; } Scr_801409D4;
typedef struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } Rock_801409D4;
extern Rock_801409D4 D_801429C0_801409D4[] asm("D_801429C0");
extern Mtx_801409D4 D_800E78C0_801409D4 asm("g_ViewMatrix");
typedef struct { u32 addr : 24; u32 len : 8; } Tag_801409D4;
typedef struct { u32 tag; u32 rgb0; s32 xy0; u32 rgb1; s32 xy1; u32 rgb2; s32 xy2; } PolyG3_801409D4;
extern struct { u8 pad_0[0x4]; u32 *f_4; u8 pad_8[4]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_801409D4 asm("g_Game");
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);

void func_801409D4(void) {
    Scr_801409D4 *sc = (Scr_801409D4 *)0x1F800000;
    Rock_801409D4 *p;
    PolyG3_801409D4 *g;
    u32 *ot;
    s32 i;
    s32 r;
    s32 n;

    sc->cam = D_800E78C0_801409D4;
    r = (RAND() >> 8 & 0x1F) + 0xB;
    n = -r;
    sc->tri[0].v[0].vx = n;
    sc->tri[0].v[0].vy = n;
    sc->tri[0].v[0].vz = 0;
    sc->tri[0].v[1].vx = r;
    sc->tri[0].v[1].vy = n;
    sc->tri[0].v[1].vz = 0;
    sc->tri[0].v[2].vx = 0;
    sc->tri[0].v[2].vy = r;
    sc->tri[0].v[2].vz = 0;
    sc->tri[1].v[0].vx = n * 2;
    sc->tri[1].v[0].vy = n * 2;
    sc->tri[1].v[0].vz = 0;
    sc->tri[1].v[1].vx = r * 2;
    sc->tri[1].v[1].vy = n * 2;
    sc->tri[1].v[1].vz = 0;
    sc->tri[1].v[2].vx = 0;
    sc->tri[1].v[2].vy = r * 2;
    sc->tri[1].v[2].vz = 0;
    sc->tri[2].v[0].vx = n / 3;
    sc->tri[2].v[0].vy = n * 2;
    sc->tri[2].v[0].vz = 0;
    sc->tri[2].v[1].vx = r / 3;
    sc->tri[2].v[1].vy = n * 2;
    sc->tri[2].v[1].vz = 0;
    sc->tri[2].v[2].vx = 0;
    sc->tri[2].v[2].vy = r * 3;
    sc->tri[2].v[2].vz = 0;
    sc->tri[3].v[0].vx = n / 2;
    sc->tri[3].v[0].vy = n / 2;
    sc->tri[3].v[0].vz = 0;
    sc->tri[3].v[1].vx = r / 2;
    sc->tri[3].v[1].vy = n / 2;
    sc->tri[3].v[1].vz = 0;
    sc->tri[3].v[2].vx = 0;
    sc->tri[3].v[2].vy = r / 2;
    sc->tri[3].v[2].vz = 0;
    g = (PolyG3_801409D4 *)g_Game_801409D4.f_4;
    ot = (u32 *)(g_Game_801409D4.f_80 + g_Game_801409D4.f_C * 0x4078);
    for (i = 31; i >= 0; i--) {
        p = &D_801429C0_801409D4[i];
        if (p->life == 0) {
            continue;
        }
        p->life--;
        p->x += p->vx;
        p->y += p->vy;
        p->z += p->vz;
        p->vy += 4;
        if (p->y > p->floor) {
            p->y = p->floor;
            p->vy = -p->vy / 3;
            if (p->vy >= -0xB) {
                p->life = 0;
                continue;
            }
        }
        sc->rot.vx = (p->life << 7) & 0xFFF;
        sc->rot.vy = (p->life << 7) & 0xFFF;
        sc->rot.vz = (p->life << 7) & 0xFFF;
        RotMatrixZYX(&sc->rot, &sc->m);
        sc->m.t[0] = p->x;
        sc->m.t[1] = p->y;
        sc->m.t[2] = p->z;
        CompMatrix(&sc->cam, &sc->m, &sc->m);
        SetRotMatrix(&sc->m);
        SetTransMatrix(&sc->m);
        gte_ldv3c_(&sc->tri[i & 3]);
        gte_rtpt_n();
        gte_stsxy3c_(sc->sxy);
        gte_stszotz(&sc->otz);
        if ((u32)(sc->otz - 1) >= 0xFFF) {
            continue;
        }
        ((u8 *)g)[3] = 6;
        g->rgb0 = 0x32EE9628;
        g->rgb1 = 0xB86E14;
        g->rgb2 = 0x3A1E00;
        g->xy0 = sc->sxy[0];
        g->xy1 = sc->sxy[1];
        g->xy2 = sc->sxy[2];
        ((Tag_801409D4 *)g)->addr = ((Tag_801409D4 *)&ot[sc->otz])->addr;
        ((Tag_801409D4 *)&ot[sc->otz])->addr = (u32)g;
        g++;
        ((u8 *)g)[3] = 1;
        ((u32 *)g)[1] = 0xE1000220;
        ((Tag_801409D4 *)g)->addr = ((Tag_801409D4 *)&ot[sc->otz])->addr;
        ((Tag_801409D4 *)&ot[sc->otz])->addr = (u32)g;
        g = (PolyG3_801409D4 *)((u8 *)g + 8);
    }
    g_Game_801409D4.f_4 = (u32 *)g;
}

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

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_80140FFC;
typedef struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x14]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad_4C[4]; u32 f_50; u8 pad_54[0xC]; SVECTOR f_60; u8 pad_68[0x10]; u16 f_78; u8 f_7A; u8 f_7B; u8 f_7C; u8 pad_7D; u8 f_7E; u8 pad_7F; s16 f_80; s16 f_82; s16 f_84; u8 pad_86[6]; u8 f_8C; u8 pad_8D; s16 f_8E; u16 f_90; s16 f_92; s16 f_94; s16 f_96; s16 f_98; u8 pad_9A[2]; s16 f_9C; s16 f_9E; } Boss_80140FFC;
typedef struct { u8 f_0; u8 f_1; u8 f_2; u8 f_3; s32 f_4; u8 f_8; } St_80140FFC;
extern Boss_80140FFC D_80142338_80140FFC asm("D_80142338");
extern St_80140FFC D_80142320_80140FFC asm("D_80142320");
extern SVECTOR D_80142318_80140FFC asm("D_80142318");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80140FFC asm("g_Spike");
extern struct { s32 f_0; } g_Game_80140FFC asm("g_Game");
extern u8 D_80141F88_80140FFC[] asm("D_80141F88");
void Camera_StartShake_80140FFC(s32) asm("Camera_StartShake");
void Effect_SpawnAt_80140FFC(s32, void *) asm("Effect_SpawnAt");
void Effect_Spawn_80140FFC(s32, void *, void *, s32) asm("Effect_Spawn");
void Sound_PlayFixed_80140FFC(s32) asm("Sound_PlayFixed");
void Puff_Spawn_80140FFC(void *, s32, s32, s32) asm("Puff_Spawn");
s32 VectorNormalSS_80140FFC(void *, void *) asm("VectorNormalSS");
s32 SquareRoot0_80140FFC(s32) asm("SquareRoot0");
void Fx_SpawnFadeRing_80140FFC(void *, s32, s32, s32) asm("Fx_SpawnFadeRing");
void Fx_DrawFadeRing_80140FFC(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
void Fx_DebrisExplosion_80140FFC(s32, s32, s32) asm("Fx_DebrisExplosion");
void Shadow_Draw_80140FFC(void *, s32, s32, s32) asm("Shadow_Draw");
void *Collision_GetShape_80140FFC(s32) asm("Collision_GetShape");
s32 Collision_GetId_80140FFC(s32) asm("Collision_GetId");
void Collision_Set_80140FFC(s32, void *, void *) asm("Collision_Set");
void Collision_Remove_80140FFC(void *) asm("Collision_Remove");
void func_8004637C_80140FFC(void *) asm("Matrix_SetIdentity");
void *RotMatrixY_80140FFC(s32, void *) asm("RotMatrixY");
void *ApplyMatrixSV_80140FFC(void *, void *, void *) asm("ApplyMatrixSV");
void func_8013D364_80140FFC(void *) asm("func_8013D364");
void func_8013DDC4_80140FFC(void *) asm("func_8013DDC4");
void func_8013D4CC_80140FFC(void) asm("func_8013D4CC");
void func_801409D4_80140FFC(void) asm("func_801409D4");
void func_8013F06C_80140FFC(void *) asm("func_8013F06C");
s32 func_80140020(void);
void func_801400F4(void);
void func_80140794(void);
void func_801407E4_80140FFC(void *, s32) asm("func_801407E4");
void func_80140F08_80140FFC(void *, void *) asm("func_80140F08");
void func_80140F68_80140FFC(void *, void *) asm("func_80140F68");
#define RAND_80140FFC() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140FFC(void) {
    SVECTOR v;
    SVECTOR w;
    SVECTOR t;
    SVECTOR q;
    Mat_80140FFC m;
    SVECTOR pad;
    Boss_80140FFC *b = &D_80142338_80140FFC;
    s32 dist;
    s32 d;
    s32 k;
    s32 r;
    s32 j;
    s32 ang;

    v.vy = 0;
    D_80142318_80140FFC.vx = b->x;
    D_80142318_80140FFC.vy = b->y - 0x80;
    D_80142318_80140FFC.vz = b->z;
    v.vx = g_Spike_80140FFC.x - D_80142318_80140FFC.vx;
    v.vz = g_Spike_80140FFC.z - D_80142318_80140FFC.vz;
    dist = SquareRoot0_80140FFC(VectorNormalSS_80140FFC(&v, &v));
    if ((u8)(D_80142320_80140FFC.f_1 - 0x16) < 3 || (b->f_7C == 0 && D_80142320_80140FFC.f_8 == 0)) {
        s32 k0 = g_Game_80140FFC.f_0 & 3;
        if (k0 == 0) {
            Effect_Spawn_80140FFC(0xD0, &D_80142318_80140FFC, D_80141F88_80140FFC, 0);
        } else if (k0 == 2) {
            Effect_Spawn_80140FFC(0xD1, &D_80142318_80140FFC, D_80141F88_80140FFC, 0);
        }
    }
    if (b->f_7C == 0) {
        if (D_80142320_80140FFC.f_3 != 0) {
            if ((M2C_FIELD(b, u32 *, 0x78) & 0xFFFFFF) == 5) {
                func_8013F3A4(b, 6);
            }
            func_8013F3DC(b);
            func_8013DDC4_80140FFC(b);
            Shadow_Draw_80140FFC(&b->x, -0xA00, 0x40, 0);
        }
        return;
    }
    switch (D_80142320_80140FFC.f_1) {
    case 0x16:
        if (b->f_7A == 0) {
            func_8013F398(0x17);
            func_8013F3A4(b, 2);
            b->f_7B = 1;
        }
        break;
    case 0x17:
        if (b->f_7A == 0) {
            func_8013F398(0x18);
            func_8013F3A4(b, 3);
            b->f_7B = 1;
        }
        break;
    case 0x18:
        if (b->f_7A == 0) {
            func_8013F398(0x19);
            func_8013F3A4(b, 4);
            b->f_7B = 1;
        }
        break;
    case 0x19:
        if (b->f_7A == 0) {
            func_8013F398(0x15);
            func_8013F3A4(b, 0);
            func_80140F68_80140FFC(b, &D_80142318_80140FFC);
        }
        break;
    case 0x14:
        func_8013F3A4(b, 0);
        b->x += b->f_80;
        b->y += b->f_82;
        b->z += b->f_84;
        b->f_82 += 6;
        if (b->y >= -0xA00) {
            b->y = -0xA00;
            func_8013F398(0x15);
            func_8013F3A4(b, 0);
            b->f_8E = 0x78;
        }
        break;
    case 0x15:
        func_8013F3A4(b, 0);
        b->x += b->f_9C;
        b->z += b->f_9E;
        b->f_9C = b->f_9C * 7 / 8;
        b->f_9E = b->f_9E * 7 / 8;
        if (!((RAND_80140FFC() >> 8) & 0x3F)
            || (b->f_94 - b->x) * (b->f_94 - b->x) + (b->f_98 - b->z) * (b->f_98 - b->z) < 0x2400) {
            b->f_96 = 0;
            b->f_94 = (((((u16)RAND_80140FFC() >> 8) - 0x80) * 19) >> 1) - 0x100;
            b->f_98 = (((((u16)RAND_80140FFC() >> 8) - 0x80) * 19) >> 1) - 0x100;
        }
        if (dist < 0x320) {
            { s32 h = b->f_7E * 20; s32 g = b->f_92 * 8 + 0x226; d = h + g; }
            if (d < 0x190) {
                d = 0x190;
            }
            b->f_80 -= v.vx / d;
            b->f_84 -= v.vz / d;
        } else {
            w.vy = 0;
            w.vx = b->f_94 - b->x;
            w.vz = b->f_98 - b->z;
            VectorNormalSS_80140FFC(&w, &w);
            b->f_80 += w.vx / 800;
            b->f_84 += w.vz / 800;
        }
        b->f_80 = b->f_80 < -0x50 ? -0x50 : b->f_80 > 0x50 ? 0x50 : b->f_80;
        b->f_84 = b->f_84 < -0x50 ? -0x50 : b->f_84 > 0x50 ? 0x50 : b->f_84;
        b->x += b->f_80;
        b->z += b->f_84;
        b->f_80 = b->f_80 * 7 / 8;
        b->f_84 = b->f_84 * 7 / 8;
        t.vy = 0;
        t.vx = b->x + 0x100;
        t.vz = b->z + 0x100;
        if (VectorNormalSS_80140FFC(&t, &t) > 0x240000) {
            b->x = ((t.vx * 3) >> 3) - 0x100;
            b->z = ((t.vz * 3) >> 3) - 0x100;
        }
        b->f_8C++;
        if (b->f_92 != 0) {
            k = b->f_8C & 0x1F;
            if (k >= 0x10) {
                k = 0x1F - k;
            }
            r = b->f_92 * 10 + 0x32;
            if (!(b->f_90 & 1)) {
                s32 k4 = k * 4;
                s32 k2;
                s32 c2;
                Fx_DrawFadeRing_80140FFC(&D_80142318_80140FFC, r + k4, 1, ((k4 + 0x18) << 16) | ((c2 = (k2 = k * 2) + 0x18) << 8) | 0x18);
                Fx_DrawFadeRing_80140FFC(&D_80142318_80140FFC, r + c2, 5, ((k2 + 0x30) << 16) | ((k4 + 0x30) << 8) | 0x30);
            }
            if (!(b->f_8C & 2)) {
                Puff_Spawn_80140FFC(&D_80142318_80140FFC, 0, 0, (r >> 1) + k * 4);
            }
            Effect_Spawn_80140FFC(0xCE, &D_80142318_80140FFC, D_80141F88_80140FFC, 0);
            b->f_44 = r;
        }
        break;
    }
    if (b->f_8E != 0 && D_80142320_80140FFC.f_1 == 0x15 && --b->f_8E == 0 && b->f_92 == 0) {
        func_80140F68_80140FFC(b, &D_80142318_80140FFC);
    }
    if (dist < 0x600 && b->f_8E == 0) {
        b->f_8E = 0x14;
        if (func_80140020()) {
            b->f_8E = 0x12C;
            D_80142320_80140FFC.f_2 = 1;
        } else {
            for (j = 16; j > 0; j--) {
                Effect_Spawn_80140FFC(0xCD, &D_80142318_80140FFC, D_80141F88_80140FFC, 0);
                Effect_SpawnAt_80140FFC(0x2E, &D_80142318_80140FFC);
            }
        }
        if (--b->f_92 == 0) {
            func_80140F08_80140FFC(b, &D_80142318_80140FFC);
            b->f_8E = (b->f_7E << 4) + 0x96;
        }
    }
    t = b->f_60;
    q.vy = 0;
    q.vx = b->f_80;
    q.vz = b->f_84;
    VectorNormalSS_80140FFC(&q, &q);
    if ((t.vx * q.vx + t.vz * q.vz) >> 12 < 0xFC2) {
        ang = (t.vz * q.vx - t.vx * q.vz) < 0 ? -0x71 : 0x71;
        func_8004637C_80140FFC(&m);
        RotMatrixY_80140FFC(ang, &m);
        ApplyMatrixSV_80140FFC(&m, &t, &b->f_60);
        VectorNormalSS_80140FFC(&b->f_60, &b->f_60);
    }
    if (b->f_90 != 0) {
        b->f_90--;
    }
    if ((b->f_50 >> 28) == 0xB && b->f_90 == 0) {
        Collision_GetShape_80140FFC(M2C_FIELD(b, u16 *, 0x50) & 0xFFF);
        Collision_GetId_80140FFC(M2C_FIELD(b, u16 *, 0x50) & 0xFFF);
        if (b->f_92 == 0) {
            func_8013D364_80140FFC(&D_80142318_80140FFC);
            Camera_StartShake_80140FFC(0);
            Fx_DebrisExplosion_80140FFC(D_80142318_80140FFC.vx, D_80142318_80140FFC.vy, D_80142318_80140FFC.vz);
            func_8013F398(0x16);
            func_8013F3A4(b, 1);
            b->f_7B = 1;
            D_80142320_80140FFC.f_4 = 0x1E;
            b->f_90 = 0x78;
            b->f_9C = -v.vx / 48;
            b->f_9E = -v.vz / 48;
            Sound_PlayFixed_80140FFC(0xB3);
            Sound_PlayFixed_80140FFC(0x6C);
            if (--b->f_7E == 0) {
                b->f_7C = 0;
                Collision_Remove_80140FFC(&b->x);
                func_8013F3A4(b, 5);
                func_8013F398(0x1A);
                Collision_Set_80140FFC(3, &b->x, b);
                b->f_4A = -0x8000;
                b->f_44 = 0x80;
                b->f_48 = 0;
                b->f_46 = 0x100;
            }
            func_8013D89C();
        } else {
            Effect_SpawnAt_80140FFC(0x112, &D_80142318_80140FFC);
            Effect_SpawnAt_80140FFC(0x109, &D_80142318_80140FFC);
            Fx_SpawnFadeRing_80140FFC(&D_80142318_80140FFC, 1, 0x200, 0);
            b->f_90 = 0x18;
            b->f_9C = -v.vx / 32;
            b->f_9E = -v.vz / 32;
            Sound_PlayFixed_80140FFC(0x60);
            Sound_PlayFixed_80140FFC(0x69);
            func_801407E4_80140FFC(&D_80142318_80140FFC, 0x20);
            if (b->f_92 != 0 && (b->f_92 -= 2) <= 0) {
                func_80140F08_80140FFC(b, &D_80142318_80140FFC);
            }
            func_80140794();
        }
    }
    if (b->f_7E < 4) {
        Effect_SpawnAt_80140FFC(7, &D_80142318_80140FFC);
    }
    func_8013F3DC(b);
    func_8013DDC4_80140FFC(b);
    Shadow_Draw_80140FFC(&b->x, -0xA00, 0x40, 0);
    func_8013D4CC_80140FFC();
    func_801409D4_80140FFC();
    func_8013F06C_80140FFC(b);
    func_801400F4();
}
