#include "common.h"
#include "m2c_macros.h"

extern struct S_D_8013FAD0 { u8 pad_0[0xB]; s8 f_B; } D_8013FAD0[];
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Puff_Spawn(s32, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
extern M2C_UNK D_8013FB90;
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
void func_8013E22C(void *arg0);
void *Collision_GetShape(s32);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_TakeHitDamage(void *, void *);
M2C_UNK Object_HitFeedback(void *);
M2C_UNK Object_Timer(void *, M2C_UNK);
void func_8013E26C(void *arg0);

s32 func_8013D000(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_8013FAD0[i].f_B = 0;
    }
    return 0;
}

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_8013FAD0");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D028(SVECTOR *arg0, s32 arg1) {
    s32 i;
    u16 x = arg0->vx;
    u16 y = arg0->vy;
    u16 z = arg0->vz;
    s16 floor = Floor_GetHeight(arg0->vx, arg0->vy, arg0->vz);

    for (i = 15; i >= 0; i--) {
        if (D_80144590_8013D028[i].life == 0) {
            D_80144590_8013D028[i].life = (RAND() >> 8 & 0x1F) + 0x28;
            D_80144590_8013D028[i].floor = floor;
            D_80144590_8013D028[i].x = x + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].y = y - ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].z = z + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].vx = ((RAND() >> 8) - 0x80) / 8;
            D_80144590_8013D028[i].vy = -(RAND() >> 8 & 0x1F) - 0x18;
            D_80144590_8013D028[i].vz = ((RAND() >> 8) - 0x80) / 8;
            if (--arg1 == 0) {
                break;
            }
        }
    }
}

#define gte_ldv3c_(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mtx_8013D218;
typedef struct { SVECTOR v[3]; u8 pad[8]; } Tri_8013D218;
typedef struct { Mtx_8013D218 m; Mtx_8013D218 cam; SVECTOR rot; Tri_8013D218 tri[4]; s32 sxy[3]; s32 otz; } Scr_8013D218;
typedef struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } Rock_8013D218;
extern Rock_8013D218 D_8013FAD0_8013D218[] asm("D_8013FAD0");
extern Mtx_8013D218 D_800E78C0_8013D218 asm("g_ViewMatrix");
typedef struct { u32 addr : 24; u32 len : 8; } Tag_8013D218;
typedef struct { u32 tag; u32 rgb0; s32 xy0; u32 rgb1; s32 xy1; u32 rgb2; s32 xy2; } PolyG3_8013D218;
extern struct { u8 pad_0[0x4]; u32 *f_4; u8 pad_8[4]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013D218 asm("g_Game");
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
void Effect_SpawnAt(s32, SVECTOR *);
void Sound_PlayFixed(s32);

s32 func_8013D218(void) {
    Scr_8013D218 *sc = (Scr_8013D218 *)0x1F800000;
    Rock_8013D218 *p;
    PolyG3_8013D218 *g;
    u32 *ot;
    s32 i;

    sc->cam = D_800E78C0_8013D218;
    sc->tri[0].v[0].vx = -0x1C;
    sc->tri[0].v[0].vy = -0x1C;
    sc->tri[0].v[0].vz = 0;
    sc->tri[0].v[1].vx = 0x1C;
    sc->tri[0].v[1].vy = -0x1C;
    sc->tri[0].v[1].vz = 0;
    sc->tri[0].v[2].vx = 0;
    sc->tri[0].v[2].vy = 0x1C;
    sc->tri[0].v[2].vz = 0;
    sc->tri[1].v[0].vx = -0x38;
    sc->tri[1].v[0].vy = -0x38;
    sc->tri[1].v[0].vz = 0;
    sc->tri[1].v[1].vx = 0x38;
    sc->tri[1].v[1].vy = -0x38;
    sc->tri[1].v[1].vz = 0;
    sc->tri[1].v[2].vx = 0;
    sc->tri[1].v[2].vy = 0x38;
    sc->tri[1].v[2].vz = 0;
    sc->tri[2].v[0].vx = -9;
    sc->tri[2].v[0].vy = -0x38;
    sc->tri[2].v[0].vz = 0;
    sc->tri[2].v[1].vx = 9;
    sc->tri[2].v[1].vy = -0x38;
    sc->tri[2].v[1].vz = 0;
    sc->tri[2].v[2].vx = 0;
    sc->tri[2].v[2].vy = 0x54;
    sc->tri[2].v[2].vz = 0;
    sc->tri[3].v[0].vx = -0xE;
    sc->tri[3].v[0].vy = -0xE;
    sc->tri[3].v[0].vz = 0;
    sc->tri[3].v[1].vx = 0xE;
    sc->tri[3].v[1].vy = -0xE;
    sc->tri[3].v[1].vz = 0;
    sc->tri[3].v[2].vx = 0;
    sc->tri[3].v[2].vy = 0xE;
    sc->tri[3].v[2].vz = 0;
    g = (PolyG3_8013D218 *)g_Game_8013D218.f_4;
    ot = (u32 *)(g_Game_8013D218.f_80 + g_Game_8013D218.f_C * 0x4078);
    for (i = 15; i >= 0; i--) {
        p = &D_8013FAD0_8013D218[i];
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
            Effect_SpawnAt(4, (SVECTOR *)p);
            if ((RAND() >> 8 & 3) == 0) {
                Sound_PlayFixed(0x67);
            }
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
        g->rgb0 = 0x323C8028;
        g->rgb1 = 0x1E4014;
        g->rgb2 = 0xA1C00;
        g->xy0 = sc->sxy[0];
        g->xy1 = sc->sxy[1];
        g->xy2 = sc->sxy[2];
        ((Tag_8013D218 *)g)->addr = ((Tag_8013D218 *)&ot[sc->otz])->addr;
        ((Tag_8013D218 *)&ot[sc->otz])->addr = (u32)g;
        g++;
        ((u8 *)g)[3] = 1;
        ((u32 *)g)[1] = 0xE1000220;
        ((Tag_8013D218 *)g)->addr = ((Tag_8013D218 *)&ot[sc->otz])->addr;
        ((Tag_8013D218 *)&ot[sc->otz])->addr = (u32)g;
        g = (PolyG3_8013D218 *)((u8 *)g + 8);
    }
    g_Game_8013D218.f_4 = (u32 *)g;
    return 0;
}

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_8013D6B8(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_8013D028(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

void Effect_SpawnAt(s32, SVECTOR *);
s32 rcos_8013EF18(s32) asm("rcos");
s32 rsin_8013EF18(s32) asm("rsin");
extern u16 g_RandSeed2;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND2() (g_RandSeed2 = g_RandSeed2 * 5 + 1)

void func_8013D73C(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    r = RAND() >> 8;
    a = (M2C_FIELD(arg0, s16 *, 0xAC) + (r << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013EF18(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (RAND2() >> 8) - 300;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013EF18(a) << 8) >> 12);
    Effect_SpawnAt(7, &v);
}

void func_8013D840(s32 arg0) {
    u16 temp_v0;

    Puff_Spawn(arg0 + 0x24, 1, 0, 0x12C);
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

void Dust_SpawnDrift(SVECTOR *);
s32 rcos_8013F084(s32) asm("rcos");
s32 rsin_8013F084(s32) asm("rsin");

void func_8013D8A8(void *arg0) {
    SVECTOR v;
    s32 a;
    s32 r;

    r = RAND() >> 8;
    a = (M2C_FIELD(arg0, s16 *, 0xAC) + (r << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013F084(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - (RAND2() >> 9) - 200;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013F084(a) << 8) >> 12);
    Dust_SpawnDrift(&v);
}

s32 rcos_8013D9A8(s32) asm("rcos");
s32 rsin_8013D9A8(s32) asm("rsin");

void func_8013D9A8(void *arg0) {
    SVECTOR v;
    s32 a;



    a = (M2C_FIELD(arg0, s16 *, 0xAC) + ((RAND() >> 8) << 12) / 510 + 0xC00) % 0x1000;
    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((rcos_8013D9A8(a) << 8) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - ((RAND() >> 9) + 0xFA);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((rsin_8013D9A8(a) << 8) >> 12);
    Effect_SpawnAt(0x102, &v);
    Object_PlaySound(arg0, 0x6C);
    Object_PlaySound(arg0, 0x4D);
}

extern u32 g_Game_8013DAC8 asm("g_Game");

void func_8013DAC8(void *arg0) {
    if (g_Game_8013DAC8 % 5 == 0 || g_Game_8013DAC8 % 17 == 0) {
        func_8013D9A8(arg0);
    }
}

typedef struct { s32 x, y, z; u8 pad_C[0x14]; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_8013DB34;
typedef struct { Shape_8013DB34 *shape; s16 x, y, z; } Coll_8013DB34;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013DB34 asm("g_Spike");
Shape_8013DB34 *CollShape_Alloc_8013DB34(void) asm("CollShape_Alloc");
s32 Collision_Set_8013DB34(s32, void *, void *) asm("Collision_Set");

void func_8013DB34(void *cv, void *owner, s32 a2, s16 a3) {
    Coll_8013DB34 *c = cv;
    s32 dx = g_Spike_8013DB34.x - c->x;
    s32 dz = g_Spike_8013DB34.z - c->z;

    if (dx * dx + dz * dz > 0x24000) {
        c->shape = NULL;
        return;
    }
    c->shape = CollShape_Alloc_8013DB34();
    if (c->shape != NULL) {
        c->shape->x = c->x;
        c->shape->y = c->y;
        c->shape->z = c->z;
        c->shape->f_20 = a2;
        c->shape->f_24 = 1;
        c->shape->f_26 = a3;
        Collision_Set_8013DB34(7, c->shape, owner);
    }
}

void func_8013DC3C(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_8013FB90;
    do {
        M2C_FIELD(var_v0, s8 *, 0x18) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x30));
    } while (var_v1 >= 0);
}

typedef struct { u8 pad0[0x14]; s32 b; u8 f_18; u8 pad19[7]; s32 a; SVECTOR v; s32 c; } Ev_423;
extern Ev_423 D_8013FB90_8013DC60[4] asm("D_8013FB90");

void func_8013DC60(s32 a, SVECTOR *v, s32 b, s32 c) {
    s32 i;
    Ev_423 *e;

    for (i = 3, e = D_8013FB90_8013DC60; i >= 0; i--, e++) {
        if (e->f_18 == 0) {
            e->f_18 = 1;
            e->a = a;
            e->v = *v;
            e->b = b;
            e->c = c;
            return;
        }
    }
}

typedef struct { u32 *shape; SVECTOR head; SVECTOR tail; s32 obj; u8 state; u8 pad19; s8 size; u8 pad1B; u16 timer; u16 age; SVECTOR *src; SVECTOR vel; s32 snd; } Ev_8013DCC8;
extern Ev_8013DCC8 D_8013FB90_8013DCC8[4] asm("D_8013FB90");
extern u8 D_800B1C28[];
extern u8 D_8013F990[];
void Shockwave_Spawn(void *, void *, s32, s32, void *);
s32 Camera_StartShake_8013DCC8(s32) asm("Camera_StartShake");
s32 Object_PlaySound_8013DCC8(s32, s32) asm("Object_PlaySound");
void func_8006F3D0_8013DCC8(SVECTOR *, s32, void *, s32) asm("Fx_DrawRibbon");
void func_8013DB34(void *cv, void *owner, s32 a2, s16 a3);

void func_8013DCC8(void) {
    SVECTOR pts[16];
    Ev_8013DCC8 *e;
    s32 i;
    s32 k;
    s16 h;
    s32 d;

    for (i = 3, e = D_8013FB90_8013DCC8; i >= 0; i--, e++) {
        if (e->state == 0) {
            continue;
        }
        switch (e->state) {
        case 1:
            e->tail = *e->src;
            e->head = e->tail;
            Fx_SpawnFadeRing(&e->tail, 3, 0x300, 0);
            e->state = 2;
            e->age = 0;
            e->size = 0xC;
            Effect_SpawnAt(0x114, &e->tail);
            Shockwave_Spawn(&e->tail, D_800B1C28, 1, 0, &e->vel);
            Camera_StartShake_8013DCC8(0);
            Object_PlaySound_8013DCC8(e->obj, e->snd);
            break;
        case 2:
            e->age++;
            if (e->size < 0x24) {
                e->size += 4;
            }
            e->head.vx += e->vel.vx;
            e->head.vy += e->vel.vy;
            e->head.vz += e->vel.vz;
            h = Floor_GetHeight(e->head.vx, e->head.vy, e->head.vz);
            if (e->age >= 0x10 || e->head.vy > h || (e->shape != NULL && (e->shape[0xB] >> 28) == 6)) {
            d = e->head.vy - h;
            if ((d < 0 ? h - e->head.vy : d) < 0x100) {
                e->head.vy = h - 0x20;
            }
            e->state = 3;
            e->timer = e->age;
            Effect_SpawnAt(0x114, &e->head);
            Shockwave_Spawn(&e->head, D_800B1C28, 1, 0, 0);
            } else {
                func_8013DB34(e, (void *)e->obj, 0x80, 0x200);
            }
            break;
        case 3:
            e->tail.vx += e->vel.vx;
            e->tail.vy += e->vel.vy;
            e->tail.vz += e->vel.vz;
            e->size -= 8;
            if (e->size < 4) {
                e->size = 4;
            }
            if (--e->timer == 0) {
                e->state = 0;
            }
            break;
        }
    }
    for (i = 3, e = D_8013FB90_8013DCC8; i >= 0; i--, e++) {
        if (e->state >= 2) {
            SVECTOR *q = pts;
            *q = e->tail;
            for (k = 16; k > 0; k--) {
                q->vx = (e->tail.vx * k + e->head.vx * (16 - k)) / 16;
                q->vy = (e->tail.vy * k + e->head.vy * (16 - k)) / 16;
                q->vz = (e->tail.vz * k + e->head.vz * (16 - k)) / 16;
                q++;
            }
            func_8006F3D0_8013DCC8(pts, 16, D_8013F990, e->size);
            Effect_SpawnAt(0x2F, &e->head);
        }
    }
}

typedef struct { u8 pad0[8]; s16 f_8, f_A; } Pt_423;
extern Pt_423 D_8013FC50[5];
void Matrix_FromFacingXZ(void *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Object_GetJointPoint(void *, s32, s32, Pt_423 *);

void func_8013E134(void *arg0) {
    s32 i;
    Pt_423 *e;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    Matrix_FromFacingXZ((u8 *)arg0 + 0x60, M2C_FIELD(arg0, void **, 0x14));
    Model_CalcKeyedJointMatrices(arg0, 3);
    for (i = 4; i >= 0; i--) {
        e = &D_8013FC50[i];
        Object_GetJointPoint(arg0, e->f_8, e->f_A, e);
    }
}

typedef struct { u8 pad0[8]; s16 f_8; s16 f_A; } Ent_8013E1C4;
extern Ent_8013E1C4 D_8013FC50_8013E1C4[] asm("D_8013FC50");

void func_8013E1C4(void) {
    Ent_8013E1C4 *p = D_8013FC50_8013E1C4;

    p->f_8 = 0xA;
    p->f_A = 0x121;
    p++;
    p->f_8 = 9;
    p->f_A = 0x102;
    p++;
    p->f_8 = 4;
    p->f_A = 0x89;
    p++;
    p->f_8 = 6;
    p->f_A = 0xBF;
    p++;
    p->f_8 = 6;
    p->f_A = 0xB6;
}

void func_8013E22C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x7065, 0x1000, arg0 + 0x24);
    }
}

void func_8013E26C(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

typedef struct { s16 x, y, z; u8 pad6[6]; } Pt_8013E2B0;
extern Pt_8013E2B0 D_8013FC68[3];
extern u8 D_8013F998[];
void VectorNormalSS(void *, void *);
void Shockwave_Spawn(void *, void *, s32, s32, void *);

void func_8013E2B0(u8 *e, s32 n) {
    SVECTOR v;
    SVECTOR s;
    Pt_8013E2B0 *p1;
    Pt_8013E2B0 *p2;
    u8 *k;
    s32 dz, dx;

    if ((M2C_FIELD(e, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    v.vx = D_8013FC68[2].x - D_8013FC68[1].x;
    p1 = &D_8013FC68[1];
    p2 = &D_8013FC68[2];
    v.vy = p2->y - p1->y;
    v.vz = p2->z - p1->z;
    VectorNormalSS(&v, &v);
    k = D_8013F998 + n * 0x54;
    dz = -((M2C_FIELD(e, s16 *, 0x64) * 75) >> 11);
    dx = (M2C_FIELD(e, s16 *, 0x60) * 75) >> 11;
    s.vx = (D_8013FC68[0].x + p1->x) / 2 + dz;
    s.vy = (D_8013FC68[0].y + p1->y) / 2;
    s.vz = (D_8013FC68[0].z + p1->z) / 2 + dx;
    Shockwave_Spawn(&s, k, 1, 0, &v);
    s.vx = (D_8013FC68[0].x + p1->x) / 2 - dz;
    s.vz = (D_8013FC68[0].z + p1->z) / 2 - dx;
    Shockwave_Spawn(&s, k, 1, 0, &v);
}

extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013E494 asm("g_Spike");
typedef struct { u16 x, y, z, pad; } Pt_8013E494;

/* called without its flag argument (old-style declaration), so defined old-style */
s32 func_8013E494(e, flag)
    u8 *e;
    s32 flag;
{
    SVECTOR a, b, c;
    Pt_8013E494 *pts;
    s32 n;
    Pt_8013E494 *p1, *p0;
    s32 d1, d2;

    if (e[0x8E] == 0) {
        return 1;
    }
    if (e[0x8E] == M2C_FIELD(e, u16 *, 0x8C) - 1) {
        return M2C_FIELD(e, u16 *, 0x8C) - 2;
    }
    n = e[0x8E];
    pts = M2C_FIELD(e, Pt_8013E494 **, 0x90);
    p1 = &pts[n + 1];
    p0 = &pts[n - 1];
    a.vx = g_Spike_8013E494.x - M2C_FIELD(e, u16 *, 0x24);
    a.vy = g_Spike_8013E494.y - M2C_FIELD(e, u16 *, 0x28);
    a.vz = g_Spike_8013E494.z - M2C_FIELD(e, u16 *, 0x2C);
    b.vx = p1->x - M2C_FIELD(e, u16 *, 0x24);
    b.vy = p1->y - M2C_FIELD(e, u16 *, 0x28);
    b.vz = p1->z - M2C_FIELD(e, u16 *, 0x2C);
    c.vx = p0->x - M2C_FIELD(e, u16 *, 0x24);
    c.vy = p0->y - M2C_FIELD(e, u16 *, 0x28);
    c.vz = p0->z - M2C_FIELD(e, u16 *, 0x2C);
    VectorNormalSS(&a, &a);
    VectorNormalSS(&b, &b);
    VectorNormalSS(&c, &c);
    d1 = (a.vx * b.vx + a.vz * b.vz) / 4096;
    d2 = (a.vx * c.vx + a.vz * c.vz) / 4096;
    if (flag != 0) {
        if (d2 < d1) {
            return e[0x8E] - 1;
        }
    } else {
        if (d2 >= d1) {
            return e[0x8E] - 1;
        }
    }
    return e[0x8E] + 1;
}

s32 func_8013E494();
void VectorNormalSS(void *, void *);
void Object_TurnToward(void *, s16, s16, s16, s16);

void func_8013E670(u8 *e, s32 flag) {
    s16 *pt;

    M2C_FIELD(e, u8 *, 0x8E) = func_8013E494(e);
    pt = (s16 *)(M2C_FIELD(e, u8 **, 0x90) + M2C_FIELD(e, u8 *, 0x8E) * 8);
    M2C_FIELD(e, s16 *, 0x94) = pt[0] - M2C_FIELD(e, s16 *, 0x24);
    M2C_FIELD(e, s16 *, 0x96) = pt[1] - M2C_FIELD(e, s16 *, 0x9C);
    M2C_FIELD(e, s16 *, 0x98) = pt[2] - M2C_FIELD(e, s16 *, 0x2C);
    VectorNormalSS(e + 0x94, e + 0x94);
    if (flag) {
        Object_TurnToward(e, -M2C_FIELD(e, s16 *, 0x94), -M2C_FIELD(e, s16 *, 0x98), 0, M2C_FIELD(e, s16 *, 0xB0));
    } else {
        Object_TurnToward(e, M2C_FIELD(e, s16 *, 0x94), M2C_FIELD(e, s16 *, 0x98), 0, M2C_FIELD(e, s16 *, 0xB0));
    }
}

void func_8013E740(void *arg0) {
    s32 temp_v0_2;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0xA8) - 0x46;
    M2C_FIELD(arg0, u16 *, 0xA8) = temp_v0;
    if ((s16) temp_v0 < 0) {
        M2C_FIELD(arg0, u16 *, 0xA8) = 0U;
    }
    temp_v0_2 = (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x94) * temp_v0_2) >> 0xC));
    M2C_FIELD(arg0, u16 *, 0x9C) = (u16) (M2C_FIELD(arg0, u16 *, 0x9C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x96) * temp_v0_2) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x98) * temp_v0_2) >> 0xC));
}

s16 Object_PathPointNear(void *, void *, s32, s32);

s32 func_8013E7CC(u8 *e, s32 spd) {
    s32 s;

    if (Object_PathPointNear(e, e + 0x24, spd * 2, M2C_FIELD(e, u8 *, 0x8E)) != 0) {
        return 1;
    }
    if ((M2C_FIELD(e, s16 *, 0xA8) >> 3) < spd) {
        M2C_FIELD(e, s16 *, 0xA8) += 0x32;
    }
    s = M2C_FIELD(e, s16 *, 0xA8) >> 3;
    M2C_FIELD(e, s32 *, 0x24) += (M2C_FIELD(e, s16 *, 0x94) * s) >> 12;
    M2C_FIELD(e, s16 *, 0x9C) += (M2C_FIELD(e, s16 *, 0x96) * s) >> 12;
    M2C_FIELD(e, s32 *, 0x2C) += (M2C_FIELD(e, s16 *, 0x98) * s) >> 12;
    return 0;
}

void func_8013E8A0(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x800) != 0) {
        func_8013E670(arg0, 1);
        M2C_FIELD(arg0, s8 *, 0x7F) = 7;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x40);
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x1C);
    } else {
        func_8013E670(arg0, 0);
        M2C_FIELD(arg0, s8 *, 0x7F) = 4;
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~0x40);
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x10);
    }
    M2C_FIELD(arg0, s8 *, 0x80) = 6;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    func_8013E22C(arg0);
}

s32 rsin(s16);
void Object_StepOrbitAngle(void *, s16);

void func_8013E948(void *arg0)
{
  int new_var;
  new_var = 0xC8;
  Object_StepOrbitAngle(arg0, 0x10);
  *((s32 *) (((s8 *) arg0) + 0x28)) = (s32) ((*((s16 *) (((s8 *) arg0) + 0x9C))) - ((((s32) (rsin(*((s16 *) (((s8 *) arg0) + 0xAA))) << 7)) >> 0xC) + new_var));
}

typedef struct { s16 x, y, z; u8 pad6[6]; } Pt_8013E994;
extern Pt_8013E994 D_8013FC50_8013E994[2] asm("D_8013FC50");
void func_8013DC60(s32 a, SVECTOR *v, s32 b, s32 c);

void func_8013E994(u8 *e) {
    SVECTOR v;
    s32 dx;
    s32 dz;
    Pt_8013E994 *p;

    if (M2C_FIELD(e, u16 *, 0x5C) != *(u16 *)(M2C_FIELD(e, u8 **, 0x88) + M2C_FIELD(e, u8 *, 0x7F) * 4) + 0xD) {
        return;
    }
    if ((M2C_FIELD(e, u32 *, 0xE0) >> 2) & 1) {
        return;
    }
    dx = (M2C_FIELD(e, s16 *, 0x64) * 55) >> 11;
    M2C_FIELD(e, s16 *, 0xBC) = D_8013FC50_8013E994[0].x + dx;
    M2C_FIELD(e, s16 *, 0xBE) = D_8013FC50_8013E994[0].y;
    dz = -((M2C_FIELD(e, s16 *, 0x60) * 55) >> 11);
    M2C_FIELD(e, s16 *, 0xC0) = D_8013FC50_8013E994[0].z + dz;
    p = &D_8013FC50_8013E994[1];
    M2C_FIELD(e, s16 *, 0xC2) = p->x - dx;
    M2C_FIELD(e, s16 *, 0xC4) = p->y;
    M2C_FIELD(e, s16 *, 0xC6) = p->z - dz;
    v.vx = M2C_FIELD(e, s16 *, 0x60);
    v.vy = 0x578;
    v.vz = M2C_FIELD(e, s16 *, 0x64);
    VectorNormalSS(&v, &v);
    v.vx /= 16;
    v.vy /= 16;
    v.vz /= 16;
    func_8013DC60((s32)(e + 0xBC), &v, (s32)e, 0x8F);
    func_8013DC60((s32)(e + 0xC2), &v, (s32)e, 0x8F);
}

void func_8013EB00(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_Timer(arg0, 0x3C);
}

void func_8013EB3C(void *arg0) {
    u32 temp_s1;
    u8 temp_v0;
    void *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (temp_v0 - 1);
        return;
    }
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 9) && (temp_s1 = (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C, (temp_s1 == 0xB)) && (temp_v0_2 = Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), ((M2C_FIELD(temp_v0_2, s16 *, 0x24) & 0xFF00) != 0xD00))) {
        Object_TakeHitDamage(arg0, temp_v0_2);
        M2C_FIELD(arg0, s8 *, 0x84) = 0x14;
        func_8013E26C(arg0);
        Object_HitFeedback(arg0);
        if (M2C_FIELD(arg0, u8 *, 0x81) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 9U;
            M2C_FIELD(arg0, s8 *, 0x7F) = (s8) temp_s1;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x2C);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x80) = 0xAU;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_DisableCollision(arg0);
        Object_Timer(arg0, 0x3C);
    }
}

extern u32 g_Game_8013EC44 asm("g_Game");

void func_8013EC44(u8 *a) {
    if (g_Game_8013EC44 & 1) {
        if (a[0x81] < 5) {
            func_8013D73C(a);
            func_8013D73C(a);
            func_8013D8A8(a);
            func_8013D8A8(a);
            func_8013D840((s32)a);
        } else if (a[0x81] < 10) {
            func_8013D73C(a);
            func_8013D73C(a);
            func_8013D840((s32)a);
        } else if (a[0x81] < 15) {
            func_8013D73C(a);
        }
    }
}

s32 Hook_Add(s32);
void func_8013DC3C(void);
void Object_PlaceAtPathPoint(void *, s32);

void func_8013ECE8(u8 *o) {
    M2C_FIELD(o, s16 *, 0xA0) = 0xC8;
    M2C_FIELD(o, s16 *, 0xB0) = 0x88;
    M2C_FIELD(o, s16 *, 0x46) = 0x280;
    M2C_FIELD(o, s16 *, 0x44) = 0x12C;
    M2C_FIELD(o, u8 *, 0x81) = 0x14;
    M2C_FIELD(o, u8 *, 0xDC) = 9;
    M2C_FIELD(o, u8 *, 0xC8) = 0;
    M2C_FIELD(o, u8 *, 0x8F) = 0;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(o, s8 *, 0x7C) = -1;
    M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
    Object_PlaceAtPathPoint(o, 0);
    M2C_FIELD(o, s32 *, 0x28) += 0x2B8;
    func_8013E1C4();
    M2C_FIELD(o, u8 *, 0x80) = 1;
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
    func_8013DC3C();
    Hook_Add((s32)func_8013DCC8);
    Object_DisableCollision(o);
}

typedef struct { u16 start; u16 end; } Rng_8013EDBC;
typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 2; u32 alt : 1; u32 b7 : 15; u32 b22 : 2; u32 b24 : 8; } Bits_8013EDBC;
extern s32 D_800EC208;
void func_8013ECE8(u8 *o);
void Object_DebugStub(void *, s32);
void func_8013E134(void *arg0);
void func_8013EB3C(void *arg0);
void Object_ClampAnimFrame(void *, s32);
void Object_TurnTowardSpike(void *);
void Object_EnableCollision(void *);
void Object_DropPickups(void *);
void func_8013E2B0(u8 *e, s32 n);
void func_8013EB00(void *arg0);
void func_8013E994(u8 *e);
void func_8013E8A0(void *arg0);
s32 func_8013E7CC(u8 *e, s32 spd);
void func_8013E740(void *arg0);
void func_8013DAC8(void *arg0);
void Object_Despawn(void *, s32);
void func_8013EC44(u8 *a);
#define TBL_8013EDBC (M2C_FIELD(o, Rng_8013EDBC **, 0x88))
#define FRAME_8013EDBC (M2C_FIELD(o, u16 *, 0x5C))
#define BITS_8013EDBC (M2C_FIELD(o, Bits_8013EDBC *, 0xE0))

void func_8013EDBC(u8 *o) {
    SVECTOR v;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013ECE8(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013E134(o);
    func_8013EB3C(o);
    switch (o[0x80]) {
    case 1:
        if (Spike_WithinRadiusXZ(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x800) && D_800EC208 < M2C_FIELD(o, s32 *, 0x28)) {
            o[0x80] = 2;
            FRAME_8013EDBC = TBL_8013EDBC[o[0x7F]].start;
            o[0xC8] = 0xF;
            M2C_FIELD(o, s16 *, 0x96) = -0x70;
            M2C_FIELD(o, s16 *, 0xAA) = 0;
            func_8013E22C(o);
        }
        break;
    case 2:
        Object_ClampAnimFrame(o, TBL_8013EDBC[o[0x7F]].end);
        Object_TurnTowardSpike(o);
        func_8013E2B0(o, 0);
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        M2C_FIELD(o, s16 *, 0x96) += 7;
        if (M2C_FIELD(o, s16 *, 0x96) >= 0) {
            o[0x80] = 3;
            o[0x7F] = 1;
            FRAME_8013EDBC = TBL_8013EDBC[1].start;
            func_8013E26C(o);
            Object_PlaySound((s32)o, 0x9F);
        }
        break;
    case 3:
        func_8013E948(o);
        func_8013E2B0(o, 1);
        Object_TurnTowardSpike(o);
        if (FRAME_8013EDBC >= TBL_8013EDBC[o[0x7F]].end) {
            func_8013EB00(o);
            Object_EnableCollision(o);
        }
        break;
    case 4:
        func_8013E948(o);
        func_8013E2B0(o, 1);
        Object_TurnTowardSpike(o);
        func_8013E994(o);
        if (Object_Timer(o, -1) == 0 && FRAME_8013EDBC >= TBL_8013EDBC[o[0x7F]].end) {
            o[0x80] = 5;
            o[0x7F] = 3;
            FRAME_8013EDBC = TBL_8013EDBC[3].start;
        }
        break;
    case 5:
        func_8013E948(o);
        func_8013E2B0(o, 1);
        Object_TurnTowardSpike(o);
        func_8013E8A0(o);
        break;
    case 6:
        func_8013E948(o);
        func_8013E2B0(o, 0);
        func_8013E7CC(o, 0x5A);
        if (FRAME_8013EDBC >= TBL_8013EDBC[o[0x7F]].end) {
            o[0x80] = 7;
            if (BITS_8013EDBC.alt) {
                o[0x7F] = 8;
                FRAME_8013EDBC = TBL_8013EDBC[8].start;
            } else {
                o[0x7F] = 5;
                FRAME_8013EDBC = TBL_8013EDBC[5].start;
            }
        }
        break;
    case 7:
        func_8013E948(o);
        func_8013E2B0(o, 0);
        if (func_8013E7CC(o, 0x5A)) {
            o[0x80] = 8;
            if (BITS_8013EDBC.alt) {
                o[0x7F] = 9;
                FRAME_8013EDBC = TBL_8013EDBC[9].start;
            } else {
                o[0x7F] = 6;
                FRAME_8013EDBC = TBL_8013EDBC[6].start;
            }
            func_8013E26C(o);
            Object_PlaySound((s32)o, 0x9F);
        }
        break;
    case 8:
        func_8013E948(o);
        func_8013E740(o);
        func_8013E2B0(o, 0);
        if (FRAME_8013EDBC >= TBL_8013EDBC[o[0x7F]].end) {
            func_8013EB00(o);
        }
        break;
    case 9:
        func_8013E2B0(o, 1);
        if (FRAME_8013EDBC >= TBL_8013EDBC[o[0x7F]].end) {
            func_8013E8A0(o);
            o[0x8F] = 0x3C;
        }
        break;
    case 10:
        BITS_8013EDBC.b22 = 1;
        M2C_FIELD(o, s16 *, 0xD4) = (M2C_FIELD(o, s16 *, 0xD4) + 3) % 0x1000;
        M2C_FIELD(o, s16 *, 0xD6) = (M2C_FIELD(o, s16 *, 0xD6) + 5) % 0x1000;
        if (TBL_8013EDBC[o[0x7F]].start + 3 < FRAME_8013EDBC) {
            FRAME_8013EDBC = TBL_8013EDBC[o[0x7F]].start;
        }
        if ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) == 0) {
            func_8013E2B0(o, 0);
        }
        func_8013DAC8(o);
        if (Object_Timer(o, -1) == 0) {
            Object_Despawn(o, 1);
            Object_DropPickups(o);
            Object_PlaySound((s32)o, 0x6E);
            v.vx = M2C_FIELD(o, s32 *, 0x24);
            v.vy = M2C_FIELD(o, s32 *, 0x28) - 0xC8;
            v.vz = M2C_FIELD(o, s32 *, 0x2C);
            Fx_SpawnFadeRing(&v, 0, 0x320, 8);
            v.vy -= 0x80;
            Shockwave_Spawn(&v, D_800B1C28, 1, 8, 0);
        }
        break;
    }
    func_8013EC44(o);
}

s32 func_8013F360(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    return 0;
}

typedef struct { s16 x, y, z; u8 pad6[0x12]; u16 flags; u8 pad1A[0x1E]; } Ent_8013F370;
extern struct { u8 frame; u8 pad1[0x812B]; u8 f_812C; u8 pad812D[0xDF]; Ent_8013F370 *f_820C; u8 pad8210[0x48]; SVECTOR f_8258; } g_Game_8013F370 asm("g_Game");
extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013F370 asm("g_Spike");
extern u8 D_800E6908;
void Fx_DrawLightning(void *, void *, s32);
s32 Vec_Length(s32, s32, s32);
s16 Sound_Play(s32, s32);
s32 Sound_Stop(s32, s32);
s32 Sound_UpdateVoice3D(s32, s32, s16, s32);

s32 func_8013F370(s16 *a) {
    s16 box[6];
    SVECTOR p0;
    SVECTOR p1;
    Ent_8013F370 *e;
    s16 i;

    e = &g_Game_8013F370.f_820C[a[2]];
    e->flags |= 0x8000;
    box[0] = e->x;
    box[1] = e->y + 0x100;
    box[2] = e->z;
    box[3] = a[5];
    box[4] = a[6];
    box[5] = a[7];
    func_8013F6BC(a[4], box, 0x80);
    for (i = 0; i < 6; i++) {
        p0.vx = e->x - a[5];
        p0.vy = e->y - (a[6] - 0x100) * i / 6;
        p0.vz = e->z;
        p1.vx = e->x + a[5];
        p1.vy = e->y - (a[6] - 0x100) * i / 6;
        p1.vz = e->z;
        Fx_DrawLightning(&p0, &p1, g_Game_8013F370.frame * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        Fx_DrawLightning(&p0, &p1, g_Game_8013F370.frame * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
    }
    if (g_Game_8013F370.f_812C == 0x18 || D_800E6908 == 1) {
        p0 = g_Game_8013F370.f_8258;
    } else {
        p0.vx = g_Spike_8013F370.x;
        p0.vy = g_Spike_8013F370.y;
        p0.vz = g_Spike_8013F370.z;
    }
    box[1] = e->y - a[6] / 2;
    if (Vec_Length(p0.vx - box[0], p0.vy - box[1], p0.vz - box[2]) < 0x1000) {
        if (a[0xB] < 0) {
            a[0xB] = Sound_Play(1, 0x66);
        } else {
            Sound_UpdateVoice3D(0x66, a[0xB], 0x1000, (s32)box);
        }
    } else if (a[0xB] >= 0) {
        Sound_Stop(0x66, a[0xB]);
        a[0xB] = -1;
    }
    return 0;
}

typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR n; s16 r; u8 pad22[2]; s16 f_24; s16 f_26; } Coll_8013F6BC;
typedef struct { s32 x, y, z; } Vec_8013F6BC;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F6BC asm("g_Spike");
Coll_8013F6BC *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 func_8013F6BC(s32 mode, s16 *b, s32 r) {
    SVECTOR n;
    Vec_8013F6BC pos;
    Coll_8013F6BC *c;
    s16 dir;
    s32 rad;

    dir = mode;
    if (b[0] - b[3] < g_Spike_8013F6BC.x && g_Spike_8013F6BC.x < b[0] + b[3]
        && g_Spike_8013F6BC.y < b[1] && b[1] - b[4] < g_Spike_8013F6BC.y
        && b[2] - b[5] < g_Spike_8013F6BC.z && g_Spike_8013F6BC.z < b[2] + b[5]) {
        if ((s16)mode == 5) {
            dir = g_Spike_8013F6BC.x < b[0];
        } else if ((s16)mode == 6) {
            dir = 2;
            if (g_Spike_8013F6BC.z < b[2]) {
                dir = 3;
            }
        }
        n.vz = 0;
        n.vy = 0;
        n.vx = 0;
        pos.x = g_Spike_8013F6BC.x;
        pos.y = g_Spike_8013F6BC.y;
        pos.z = g_Spike_8013F6BC.z;
        rad = (s16)r;
        switch (dir) {
        case 0:
            n.vx = 0x1000;
            pos.x -= 0x40;
            break;
        case 1:
            n.vx = -0x1000;
            pos.x += 0x40;
            break;
        case 2:
            n.vz = 0x1000;
            pos.z -= 0x40;
            break;
        case 3:
            n.vz = -0x1000;
            pos.z += 0x40;
            break;
        case 4:
            n.vx = g_Spike_8013F6BC.x - b[0];
            n.vy = g_Spike_8013F6BC.y - b[1];
            n.vz = g_Spike_8013F6BC.z - b[2];
            VectorNormalSS(&n, &n);
            pos.x = b[0];
            pos.y = b[1];
            pos.z = b[2];
            rad = b[3];
            break;
        }
        c = CollShape_Alloc();
        if (c != NULL) {
            c->n = n;
            c->x = pos.x;
            c->y = pos.y;
            c->z = pos.z;
            c->f_24 = 0x401;
            c->r = rad;
            c->f_26 = 0x202;
            Collision_Set(6, c, 0);
        }
    }
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
