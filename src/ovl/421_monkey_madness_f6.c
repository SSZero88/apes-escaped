#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013D028(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013D050(void) {
    Pad_Vibrate(1, 0x78, 2);
}

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

void func_8013D078(s32 arg0) {
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

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D10C asm("g_Game");
typedef struct { u8 pad0[0x18]; s32 f18, f1C; } AnimEnt_8013D10C;
extern u8 *D_80140870[];
extern u8 *D_80140898[];
void func_80015BA0(void *, void *);

void func_8013D10C(s32 i, void *obj, void *out) {
    u8 *bank = g_Game_8013D10C.f_8244;
    AnimEnt_8013D10C *ent;
    u8 *s;
    u32 *q;

    D_80140870[i] = bank + (ent = (AnimEnt_8013D10C *)(i * 32 + (u32)(bank + M2C_FIELD(bank, s32 *, 8))))->f18;
    D_80140898[i] = s = g_Game_8013D10C.f_8244 + ent->f1C;
    q = (u32 *)s + 1;
    *(u32 **)out = q;
    M2C_FIELD(obj, u32 **, 0x18) = q + *(u16 *)s;
    func_80015BA0(obj, D_80140870[i]);
}

extern struct { u8 pad_0[0x8244]; u8 *f_8244; } g_Game_8013D1AC asm("g_Game");
extern s16 D_800E69BE;
extern u8 D_80140470[];
extern struct { s32 f_0; s32 f_4; u8 f_8; u8 pad9[3]; s32 f_C; s32 f_10; u8 pad14[4]; s16 f_18; s16 f_1A; u8 pad1C[0x1E]; u8 f_3A; u8 f_3B; u8 f_3C; } D_801408C0_8013D1AC asm("D_801408C0");
s32 Collision_Set(s32, void *, void *);
void func_8013F4F0(void);
void func_8013E8C0(void);
void func_8013DE14(void);
void func_8013E4D8(void);
void func_8013D804(void);

void func_8013D1AC(void) {
    s32 i;
    u8 *e;
    u8 *m;
    u8 *h;

    h = g_Game_8013D1AC.f_8244;
    D_800E69BE = 0;
    m = h + M2C_FIELD(h, s32 *, 8);
    for (i = 0, e = D_80140470; i < 8; i++, e += 0x80) {
        func_8013D10C(i, e, e + 0x70);
        M2C_FIELD(e, s32 *, 0x28) = -0x3600;
        M2C_FIELD(e, s32 *, 0x74) = 0;
        M2C_FIELD(e, s32 *, 0x24) = 0;
        M2C_FIELD(e, s32 *, 0x2C) = 0x12B8;
        M2C_FIELD(e, s16 *, 0x60) = 0;
        M2C_FIELD(e, s16 *, 0x62) = 0;
        M2C_FIELD(e, s16 *, 0x64) = -0x1000;
        if (*(u16 *)m == 0xD4) {
            Collision_Set(5, e + 0x24, e);
            M2C_FIELD(e, s16 *, 0x48) = 0;
            M2C_FIELD(e, s16 *, 0x4A) = -0x4000;
            M2C_FIELD(e, s16 *, 0x44) = 0x230;
            M2C_FIELD(e, s16 *, 0x46) = 0x384;
        }
        m += 0x20;
    }
    D_801408C0_8013D1AC.f_8 = 1;
    D_801408C0_8013D1AC.f_0 = 0;
    D_801408C0_8013D1AC.f_4 = 0;
    D_801408C0_8013D1AC.f_C = 0;
    D_801408C0_8013D1AC.f_10 = 0;
    D_801408C0_8013D1AC.f_18 = 0;
    D_801408C0_8013D1AC.f_1A = 0;
    D_801408C0_8013D1AC.f_3A = 1;
    D_801408C0_8013D1AC.f_3B = 6;
    D_801408C0_8013D1AC.f_3C = 0;
    func_8013F4F0();
    func_8013E8C0();
    func_8013DE14();
    func_8013E4D8();
    func_8013D804();
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013D324);

extern struct { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_8013D43C asm("g_Game");
extern u8 D_800E78C0[];
extern u8 D_800E7D00[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void *ScaleMatrix(void *m, void *v);
void Matrix_FromDirection(void *, void *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_8013D324(void *, void *, void *, s32);

s32 func_8013D43C(u8 *a, void *scale, s32 c) {
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
    func_8013D324(g_Game_8013D43C.f_80 + g_Game_8013D43C.f_C * 0x4078, D_800E7D00, a, c);
    return 0;
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013D57C;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D57C asm("g_Spike");
extern struct { u8 pad0[0x10]; s32 f_10; u8 pad14[0x24]; s16 f_38; u8 f_3A; } D_801408C0_8013D57C_t asm("D_801408C0");
s32 SquareRoot0(s32);
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);

s32 func_8013D57C(u8 *cam) {
    Scr_8013D57C *sc = (Scr_8013D57C *)0x1F800000;
    u8 *e = D_80140470;
    SVECTOR v;
    s32 r;
    s32 h;

    if (D_801408C0_8013D57C_t.f_3A != 0) {
        return 0;
    }
    M2C_FIELD(cam, s32 *, 0x2C) = (D_801408C0_8013D57C_t.f_10 << 12) / 360;
    v.vy = 0;
    sc->spike.vx = g_Spike_8013D57C.x;
    sc->spike.vy = g_Spike_8013D57C.y - 0x80;
    sc->spike.vz = g_Spike_8013D57C.z;
    sc->eye.vx = g_Spike_8013D57C.x;
    sc->eye.vy = g_Spike_8013D57C.y - 0x80;
    sc->eye.vz = g_Spike_8013D57C.z;
    v.vx = g_Spike_8013D57C.x - M2C_FIELD(e, s32 *, 0x24);
    v.vz = g_Spike_8013D57C.z - M2C_FIELD(e, s32 *, 0x2C);
    r = SquareRoot0(v.vx * v.vx + v.vz * v.vz);
    sc->at.vx = M2C_FIELD(e, s32 *, 0x24);
    h = r / 8 + 0x280;
    sc->at.vy = M2C_FIELD(e, u16 *, 0x28) - h;
    if (sc->at.vy > M2C_FIELD(e, s32 *, 0x28) - 0x280) {
        sc->at.vy = M2C_FIELD(e, u16 *, 0x28) - 0x280;
    }
    sc->at.vz = M2C_FIELD(e, s32 *, 0x2C);
    func_80047558(cam, 0x10, 0x10, 0x10);
    func_80047464(cam, 8, 0x10, 8);
    D_801408C0_8013D57C_t.f_38 = M2C_FIELD(cam, u16 *, 0xC) + 0x3690;
    return 1;
}

extern struct { u8 pad_0[0x24]; s32 x; u8 pad_28[4]; s32 z; } g_Spike_8013D708 asm("g_Spike");
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; } Shape_8013D708;
typedef struct { Shape_8013D708 *shape; s16 x, y, z; } Coll_8013D708;

void func_8013D708(Coll_8013D708 *c, void *owner, s32 arg2) {
    s32 dx = g_Spike_8013D708.x - c->x;
    s32 dz = g_Spike_8013D708.z - c->z;
    Shape_8013D708 *s;

    if (dx * dx + dz * dz > 0x24000) {
        c->shape = 0;
        return;
    }
    s = CollShape_Alloc();
    c->shape = s;
    if (s != 0) {
        c->shape->x = c->x;
        c->shape->y = c->y;
        c->shape->z = c->z;
        c->shape->f_20 = arg2;
        c->shape->f_24 = 1;
        c->shape->f_26 = 0x200;
        Collision_Set(7, c->shape, owner);
    }
}

extern u8 D_80140944;

void func_8013D804(void) {
    D_80140944 = 0;
}

extern struct { SVECTOR v; u8 pad8[0x3C]; u8 f_44; u8 pad45; s16 f_46; } D_80140900;

void func_8013D810(SVECTOR *v) {
    if (D_80140900.f_44 == 0) {
        D_80140900.f_44 = 1;
        D_80140900.f_46 = 0x32;
        D_80140900.v = *v;
    }
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D860;
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; s16 f_22; u16 f_24; u16 f_26; u8 pad28[4]; u32 f_2C; } Coll_8013D860;
typedef struct { s16 x, y, z, pad6; s16 f_8, f_A, f_C; u8 f_E; u8 padF; s16 f_10, f_12, f_14, f_16; u32 f_18; u32 f_1C; Mat_8013D860 mat; Coll_8013D860 *coll; u8 state; u8 armed; s16 timer; } Wave_8013D860;
extern Wave_8013D860 D_80140900_8013D860 asm("D_80140900");
extern Mat_8013D860 D_800B1BB0_8013D860 asm("D_800B1BB0");
extern s32 D_801408C4;
extern u8 D_80140394[];
s32 Sound_PlayFixed_8013D860(s32) asm("Sound_PlayFixed");
s32 Camera_StartShake_8013D860(s32) asm("Camera_StartShake");
void Effect_Spawn_8013D860(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
Coll_8013D860 *CollShape_Alloc_8013D860(void) asm("CollShape_Alloc");
void Shockwave_Draw_8013D860(void *) asm("Shockwave_Draw");
s32 rcos(s32);
int abs(int);
s32 rsin(s32);
#define RAND_8013D860() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013D860(void) {
    Wave_8013D860 *s = &D_80140900_8013D860;
    Wave_8013D860 *w;
    SVECTOR v;
    s32 i;
    s32 ang;
    s32 d;
    s16 dd;
    s32 r10;
    s32 r12;
    u32 c;

    if (s->state == 1) {
        if (--s->timer == 0) {
            s->state = 2;
            Sound_PlayFixed_8013D860(0x8E);
            Sound_PlayFixed_8013D860(0x92);
            Sound_PlayFixed_8013D860(0x95);
        }
    }
    if (s->state == 2) {
        if (++s->timer >= 0x1F) {
            s->state = 3;
            s->armed = 1;
            s->f_E = 0x20;
            s->f_14 = 0x38E;
            s->f_16 = 0x7C2C;
            s->timer = 0;
            s->f_C = 0;
            s->f_A = 0;
            s->f_18 = 0x3F2F0008;
            s->f_1C = 0x909090;
            s->mat = D_800B1BB0_8013D860;
            Camera_StartShake_8013D860(1);
            func_8013E8C0();
            D_801408C4 = 0x3C;
            Sound_PlayFixed_8013D860(0x94);
            Sound_PlayFixed_8013D860(0x95);
        } else {
            s32 i;
            for (i = 0; i < 4; i++) {
                v.vx = ((RAND_8013D860() >> 8) - 0x80) * 4;
                v.vy = -0x3800;
                v.vz = 0x10B8;
                Effect_Spawn_8013D860(i / 2 + 0xC9, &v, D_80140394, 0);
            }
            Camera_StartShake_8013D860(0);
        }
    }
    if (s->state == 3) {
        s->f_8 = -0x200;
        s->f_10 = s->timer * 0x60 + (s16)(((RAND_8013D860() >> 8) - 0x80) / 2 + 0x100);
        s->f_12 = s->timer * 0x60 + ((RAND_8013D860() >> 8) - 0x80) / 2;
        s->mat = D_800B1BB0_8013D860;
        s->f_1C += 0xFFFDFDFE;
        w = s;
        if (s->coll != NULL && (s->coll->f_2C >> 28) == 6) {
            s->armed = 0;
        } else if (s->armed != 0 && (s->coll = CollShape_Alloc_8013D860()) != NULL) {
            dd = w->f_10 - w->f_12;
            s->coll->x = w->x;
            s->coll->y = w->y - 0x80;
            s->coll->z = w->z;
            s->coll->f_20 = w->f_10;
            s->coll->f_22 = abs(dd);
            s->coll->f_24 = 0x201;
            s->coll->f_26 = 0x200;
            Collision_Set(0x10, s->coll, 0);
        }
        Shockwave_Draw_8013D860(w);
        r10 = w->f_10;
        c = w->f_1C;
        r12 = w->f_12;
        w->f_10 = (s16)(w->f_10 - 0x100) + ((RAND_8013D860() >> 8) - 0x80) / 2;
        w->f_1C = (w->f_1C & 0xFEFEFE) >> 1;
        w->f_12 = (s16)(w->f_12 - 0x100) + ((RAND_8013D860() >> 8) - 0x80) / 2;
        Shockwave_Draw_8013D860(w);
        w->f_10 = r10;
        w->f_12 = r12;
        w->f_1C = c;
        ang = (RAND_8013D860() >> 8) * 8 + 0x800;
        for (i = 0; i < 8; i++) {
            v.vx = (rcos(ang) * w->f_10) >> 12;
            v.vy = -0x3680;
            v.vz = ((rsin(ang) * w->f_10) >> 12) + 0x12B8;
            Effect_Spawn_8013D860(i / 4 + 0xC9, &v, D_80140394, 0);
        }
        if (((RAND_8013D860() >> 8) & 0x1F) == 0) {
            Sound_PlayFixed_8013D860(0x95);
            Camera_StartShake_8013D860(0);
        }
        if (++s->timer >= 0x29) {
            s->state = 0;
        }
    }
}

typedef struct { u8 pad0[0x54]; u8 f_54; u8 pad55[7]; } Slot_421;
extern Slot_421 D_80140948[4];

void func_8013DE14(void) {
    s32 i;
    Slot_421 *p;

    for (i = 3, p = D_80140948; i >= 0; i--, p++) {
        p->f_54 = 0;
    }
}

typedef struct { s32 f_0; SVECTOR v[8]; SVECTOR pos; u8 pad4C[8]; u8 f_54; u8 pad55[3]; s16 f_58; u8 pad5A[2]; } Slot_8013DE38;
extern Slot_8013DE38 D_80140948_8013DE38[4] asm("D_80140948");
extern struct { u8 pad0[0x24]; SVECTOR v; } D_801408C0_8013DE38 asm("D_801408C0");

void func_8013DE38(s32 unused, SVECTOR *pos) {
    s32 i;
    Slot_8013DE38 *p;

    for (i = 3, p = D_80140948_8013DE38; i >= 0; i--, p++) {
        if (p->f_54 == 0) {
            p->f_54 = 1;
            p->f_58 = 1;
            p->pos = *pos;
            p->pos.vy += 0xC0;
            for (i = 0; i < 8; i++) {
                p->v[i] = D_801408C0_8013DE38.v;
            }
            return;
        }
    }
}

typedef struct { s32 x, y, z; } V3_8013DEEC;
typedef struct { u32 *coll; SVECTOR v[8]; SVECTOR pos; SVECTOR vel; u8 state; u8 pad55; s8 size; u8 pad57; u16 timer; u16 age; } Rock_8013DEEC;
extern Rock_8013DEEC D_80140948_8013DEEC[4] asm("D_80140948");
extern u8 D_801403A0[];
extern u8 D_80140448[];
extern u8 D_80140394[];
void Fx_DrawFadeRing_8013DEEC(void *, s32, s32, s32) asm("Fx_DrawFadeRing");
void func_80070284_8013DEEC(void *, void *, s32, s32, void *) asm("func_80070284");
s32 Camera_StartShake_8013DEEC(s32) asm("Camera_StartShake");
void Effect_SpawnAt_8013DEEC(s32, void *) asm("Effect_SpawnAt");
void Effect_Spawn_8013DEEC(s32, void *, void *, s32) asm("Effect_Spawn");
s32 Sound_PlayFixed_8013DEEC(s32) asm("Sound_PlayFixed");
s32 VectorNormalSS_8013DEEC(void *, void *) asm("VectorNormalSS");
void Shadow_Draw_8013DEEC(void *, s32, s32, s32) asm("Shadow_Draw");
void func_8006F3D0_8013DEEC(void *, s32, void *, s32) asm("func_8006F3D0");
void func_8013D078(s32 arg0);
#define RAND_8013DEEC() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013DEEC(void) {
    Rock_8013DEEC *p;
    s32 i;
    s32 k;
    s32 j;
    u8 c;
    SVECTOR d;
    V3_8013DEEC u;
    V3_8013DEEC t;

    for (i = 3, p = D_80140948_8013DEEC; i >= 0; i--, p++) {
        if (p->state == 0) {
            continue;
        }
        for (j = 6; j >= 0; j--) {
            p->v[j + 1] = p->v[j];
        }
        switch (p->state) {
        case 1:
            p->size = 1;
            c = 0x40 - p->timer;
            Fx_DrawFadeRing_8013DEEC(&p->v[0], p->timer * 0x18, 4, (c << 16) | (c << 8) | c);
            p->timer = p->timer * 3 / 4;
            if (p->timer == 0) {
                p->vel.vx = ((RAND_8013DEEC() >> 8) - 0x80) / 3;
                p->vel.vy = -(RAND_8013DEEC() >> 11) - 0x18;
                p->vel.vz = -(RAND_8013DEEC() >> 8) / 4;
                p->state = 2;
                p->age = 0;
                func_80070284_8013DEEC(&p->v[0], D_801403A0, 1, 0, &p->vel);
                Camera_StartShake_8013DEEC(0);
                Effect_SpawnAt_8013DEEC(4, &p->v[0]);
                for (k = 0; k < 5; k++) {
                    Effect_Spawn_8013DEEC(0xC8, &p->v[0], D_80140394, 0);
                }
                Sound_PlayFixed_8013DEEC(0x8F);
                Sound_PlayFixed_8013DEEC(0x77);
            }
            break;
        case 2:
            p->age++;
            if (p->size < 0x14) {
                p->size += 2;
            }
            d.vx = p->pos.vx - p->v[0].vx;
            d.vy = p->pos.vy - p->v[0].vy;
            d.vz = p->pos.vz - p->v[0].vz;
            if (VectorNormalSS_8013DEEC(&d, &d) <= 0x960F || p->age >= 0x40 || (p->coll != NULL && (p->coll[0xB] >> 28) == 6)) {
                p->v[0].vy = -0x3620;
                p->state = 3;
                p->timer = p->age;
                Effect_SpawnAt_8013DEEC(0x113, &p->v[0]);
                func_80070284_8013DEEC(&p->v[0], D_801403A0, 1, 0, 0);
            } else {
                func_8013D708(p, D_80140470, 0x80);
            }
            p->vel.vx = (p->vel.vx * 0x39D) >> 10;
            p->vel.vy = (p->vel.vy * 0x39D) >> 10;
            p->vel.vz = (p->vel.vz * 0x39D) >> 10;
            p->vel.vx += d.vx >> 8;
            p->vel.vy += (d.vy >> 8) + 4;
            p->vel.vz += d.vz >> 8;
            p->v[0].vx += p->vel.vx;
            p->v[0].vy += p->vel.vy;
            p->v[0].vz += p->vel.vz;
            p->vel.vx = p->vel.vx < -0xC4 ? -0xC4 : (p->vel.vx > 0xC4 ? 0xC4 : p->vel.vx);
            p->vel.vy = p->vel.vy < -0xC4 ? -0xC4 : (p->vel.vy > 0xC4 ? 0xC4 : p->vel.vy);
            p->vel.vz = p->vel.vz < -0xC4 ? -0xC4 : (p->vel.vz > 0xC4 ? 0xC4 : p->vel.vz);
            if (p->v[0].vy >= -0x3640) {
                p->v[0].vy = -0x3640;
            }
            t.x = p->v[0].vx;
            t.y = p->v[0].vy;
            t.z = p->v[0].vz;
            u = t;
            Shadow_Draw_8013DEEC(&u, -0x3610, 0x40, 0);
            break;
        case 3:
            if (--p->timer == 0) {
                p->state = 0;
                if (((RAND_8013DEEC() >> 8) & 0xF) == 0) {
                    func_8013D078((s32)&p->v[0]);
                }
            }
            break;
        }
    }
    for (i = 3, p = D_80140948_8013DEEC; i >= 0; i--, p++) {
        if (p->state != 0) {
            func_8006F3D0_8013DEEC(&p->v[0], 7, D_80140448, p->size);
        }
    }
}

typedef struct { u8 pad0[0x1C]; u8 f_1C; u8 pad1D[7]; } Slot_421b;
extern Slot_421b D_80140AB8[16];
extern u8 D_80140CF8;

void func_8013E4D8(void) {
    s32 i;
    Slot_421b *p;

    for (i = 15, p = D_80140AB8; i >= 0; i--, p++) {
        p->f_1C = 0;
    }
    D_80140CF8 = 0;
}

typedef struct {
    SVECTOR pos;
    s32 f_8;
    SVECTOR vel;
    SVECTOR vel0;
    u8 f_1C;
    u8 f_1D;
    s16 f_1E;
    u8 f_20;
    u8 f_21;
    u8 pad_22[2];
} Spark_8013E500;
extern Spark_8013E500 D_80140AB8_E500[] asm("D_80140AB8");

void func_8013E500(SVECTOR *pos, s32 a1, s32 rnd, u8 a3, u8 a4) {
    Spark_8013E500 *e = &D_80140AB8_E500[D_80140CF8];

    e->f_1C = 8;
    e->f_1D = 1;
    e->pos = *pos;
    e->f_8 = a1;
    e->f_1E = ((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0;
    e->f_20 = a3;
    e->f_21 = a4;
    if (rnd == 0) {
        e->vel.vx = 0;
        e->vel.vy = 0;
        e->vel.vz = 0;
    } else {
        e->vel.vx = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0x10;
        e->vel.vy = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) - 7;
        e->vel.vz = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0x10;
    }
    e->vel0 = e->vel;
    D_80140CF8 = (D_80140CF8 + 1) % 16;
}

typedef struct { SVECTOR start; SVECTOR *end; u8 padC[0x10]; u8 n; u8 pad1D; u16 seed; u8 pad20[4]; } Bolt_8013E650;
extern Bolt_8013E650 D_80140AB8_8013E650[] asm("D_80140AB8");
extern u8 D_800B1B90[];
void func_8006F3D0(SVECTOR *, s32, void *, s32);

void func_8013E650(void) {
    SVECTOR pts[9];
    SVECTOR b;
    SVECTOR a;
    Bolt_8013E650 *e;
    SVECTOR *p;
    s32 i;
    s32 k;
    s32 t;
    u16 seed;

    for (i = 15, e = D_80140AB8_8013E650; i >= 0; i--, e++) {
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
            p->vx += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
            p->vy += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
            p->vz += (((s16)(seed = seed * 5 + 1) >> 8) - 0x80) / 2;
        }
        func_8006F3D0(pts, e->n, D_800B1B90, 8);
        e->n--;
    }
}

typedef struct { u8 pad0[6]; u8 f_6; u8 pad7[5]; } Slot_421c;
extern Slot_421c D_80140D00[4];

void func_8013E8C0(void) {
    s32 i;
    Slot_421c *p;

    for (i = 3, p = D_80140D00; i >= 0; i--, p++) {
        p->f_6 = 0;
    }
}

typedef struct { s16 x, y, z; u8 f6, f7, f8; u8 pad9[3]; } Puff_421;
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
void Sound_PlayFixed(s32);

void func_8013E8E4(void) {
    s32 i;
    Puff_421 *e;

    for (i = 3, e = D_80140D00; i >= 0; i--, e++) {
        if (e->f6 == 0) {
            e->f6 = 1;
            e->f7 = 0x1B;
            e->x = g_Spike.f_24;
            e->y = g_Spike.f_28 - 0x40;
            e->z = g_Spike.f_2C;
            e->f8 = 0x40;
            Sound_PlayFixed(0x18);
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013E97C);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013EE04);

extern struct { s32 f_0; s32 f_4; u8 pad8[0x12]; u8 f_1A[18]; } D_80140D30;

void func_8013F4F0(void) {
    s32 i;

    for (i = 0; i < 18; i++) {
        D_80140D30.f_1A[i] = 0;
        D_80140D30.f_0 = 0;
        D_80140D30.f_4 = 0;
    }
}

extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; u8 pad_2E[2]; s32 f_30; u8 pad_34[4]; s32 f_38; } g_Spike_8013F520 asm("g_Spike");
typedef struct { u8 pad0[0x1A]; s16 f_1A; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[0xA]; SVECTOR v; } St_8013F520;
extern SVECTOR D_801408EC;
void func_8013E500(SVECTOR *pos, s32 a1, s32 rnd, u8 a3, u8 a4);

void func_8013F520(void) {
    SVECTOR sv;
    u16 x, y, z;
    u16 t;
    s32 a;
    SVECTOR *v = &D_801408EC;
    St_8013F520 *d = (St_8013F520 *)((u8 *)v - 0x2C);

    v->vx = x = g_Spike_8013F520.x;
    y = g_Spike_8013F520.y;
    z = g_Spike_8013F520.z;
    v->vy = y - 0x80;
    v->vz = z;
    if (d->f_1A != 0) {
        t = --d->f_1A;
        g_Spike_8013F520.f_30 = d->f_1C / 2;
        g_Spike_8013F520.f_38 = a = d->f_20;
        d->f_1C = d->f_1C * 7 / 8;
        d->f_1E = d->f_1E * 7 / 8;
        d->f_20 = a * 7 / 8;
        if ((t & 3) == 0) {
            sv.vx = x + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2);
            sv.vy = y - ((g_RandSeed = g_RandSeed * 5 + 1) >> 8);
            sv.vz = z + ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) * 2);
            func_8013E500(&sv, (s32)v, 1, 8, 0x20);
        }
    }
}

extern struct { u8 pad_0[0x24]; u16 x; u8 pad_26[2]; u16 y; u8 pad_2A[2]; u16 z; } g_Spike_8013F694 asm("g_Spike");
extern struct { u8 pad0[0x1A]; s16 f_1A; s16 f_1C; s16 f_1E; s16 f_20; } D_801408C0_8013F694 asm("D_801408C0");
extern s32 D_801403F4;
void VectorNormalSS(void *, void *);
void Effect_SpawnAt(s32, SVECTOR *);
void func_80070284(void *, s32 *, s32, s32, s32);
void Camera_StartShake(s32);
void func_8013D000(void);

void func_8013F694(u8 *obj, s32 div) {
    SVECTOR v;
    s32 a, b, c;

    if (D_801408C0_8013F694.f_1A != 0) {
        return;
    }
    v.vx = g_Spike_8013F694.x - M2C_FIELD(obj, u16 *, 0x24);
    v.vy = 0;
    v.vz = g_Spike_8013F694.z - M2C_FIELD(obj, u16 *, 0x2C);
    VectorNormalSS(&v, &v);
    a = v.vx / div;
    b = v.vy / div;
    c = v.vz / div;
    D_801408C0_8013F694.f_1A = 0x14;
    v.vx = g_Spike_8013F694.x;
    v.vy = g_Spike_8013F694.y - 0x80;
    v.vz = g_Spike_8013F694.z;
    D_801408C0_8013F694.f_1C = a;
    D_801408C0_8013F694.f_1E = b;
    D_801408C0_8013F694.f_20 = c;
    Effect_SpawnAt(0x112, &v);
    v.vx = M2C_FIELD(obj, u16 *, 0x24);
    v.vy = g_Spike_8013F694.y;
    v.vz = M2C_FIELD(obj, u16 *, 0x2C);
    func_80070284(&v, &D_801403F4, 1, 0, 0);
    Camera_StartShake(0);
    Sound_PlayFixed(0x82);
    Sound_PlayFixed(0x4B);
    func_8013D000();
}

typedef struct { u32 addr : 24; u32 len : 8; } Tag_8013F848;
typedef struct { s32 cur; s32 wait; u8 seed[0x12]; u8 len[0x12]; } Bars_8013F848;
extern Bars_8013F848 D_80140D30_8013F848 asm("D_80140D30");
extern s32 D_801408C0_8013F848 asm("D_801408C0");
extern u8 *D_800EC354;
#define RAND_8013F848() (g_RandSeed = g_RandSeed * 5 + 1)

void func_8013F848(void) {
    u32 *ot;
    u32 *p;
    s32 i;
    s32 j;
    s32 n;
    u16 seed;
    s32 c;
    s32 r;
    u8 *q;

    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (u32 *)G_DRAW.prim;
    if ((D_801408C0_8013F848 & 7) < 4) {
        ((u8 *)p)[3] = 3;
        p[1] = 0x420C280A;
        p[2] = ((D_80140D30_8013F848.cur * 6 + 0x5C) << 16) | (D_80140D30_8013F848.len[D_80140D30_8013F848.cur] * 3 + 0xFC);
        p[3] = ((D_80140D30_8013F848.cur * 6 + 0x5C) << 16) | (D_80140D30_8013F848.len[D_80140D30_8013F848.cur] * 3 + 0xFF);
        ((Tag_8013F848 *)p)->addr = ((Tag_8013F848 *)&ot[1])->addr;
        ((Tag_8013F848 *)&ot[1])->addr = (u32)p;
        p += 4;
    }
    for (i = 0; i < 0x12; i++) {
        seed = D_80140D30_8013F848.seed[i];
        for (j = 0; j < D_80140D30_8013F848.len[i]; j++) {
            seed = seed * 5 + 1;
            ((u8 *)p)[3] = 5;
            p[1] = 0xE1000228;
            p[2] = 0x660C280A;
            p[3] = ((i * 6 + 0x58) << 16) | (u16)(j * 3 + 0xFC);
            p[5] = 0x50002;
            p[4] = ((seed & 7) << 2) | 0x3877B800;
            ((Tag_8013F848 *)p)->addr = ((Tag_8013F848 *)&ot[1])->addr;
            ((Tag_8013F848 *)&ot[1])->addr = (u32)p;
            p += 6;
        }
    }
    n = 0;
    if (D_80140D30_8013F848.wait != 0) {
        if (--D_80140D30_8013F848.wait == 0) {
            n = ((RAND_8013F848() >> 8) & 1) + 1;
        }
    } else {
        D_80140D30_8013F848.len[D_80140D30_8013F848.cur]++;
        if (D_80140D30_8013F848.len[D_80140D30_8013F848.cur] >= 6 && ((RAND_8013F848() >> 8) & 0xF) == 0) {
            D_80140D30_8013F848.wait = (RAND_8013F848() >> 8) & 0x3F;
        }
        if (D_80140D30_8013F848.len[D_80140D30_8013F848.cur] >= 0x1E) {
            n = 1;
        }
    }
    while (n != 0) {
        r = g_RandSeed;
        c = D_80140D30_8013F848.cur++;
        if ((((g_RandSeed = r * 5 + 1) >> 8) & 0x1F) == 0) {
            D_80140D30_8013F848.cur = 0;
            for (i = 0x11, q = (u8 *)&D_80140D30_8013F848 + i; i >= 0; i--, q--) {
                q[0x1A] = 0;
            }
        } else if (c + 1 >= 0x12) {
            D_80140D30_8013F848.cur = c;
            for (i = 0; i < 0x11; i++) {
                D_80140D30_8013F848.seed[i] = D_80140D30_8013F848.seed[i + 1];
                D_80140D30_8013F848.len[i] = D_80140D30_8013F848.len[i + 1];
            }
        }
        D_80140D30_8013F848.len[D_80140D30_8013F848.cur] = 0;
        n--;
        D_80140D30_8013F848.seed[D_80140D30_8013F848.cur] = RAND_8013F848() >> 8;
    }
    D_800EC354 = (u8 *)p;
}

extern struct { u8 pad0[4]; s32 f_4; u8 pad8[0x32]; u8 f_3A; } D_801408C0;

void func_8013FC74(void) {
    D_801408C0.f_3A = 0;
    D_801408C0.f_4 = 0x1E;
}

typedef struct { u8 pad0[0x24]; u16 f_24; u8 pad26[6]; u16 f_2C; u8 pad2E[0x2E]; s16 f_5C; u8 pad5E[0x22]; } Obj_8013FC8C;
extern Obj_8013FC8C D_801407F0[];
extern u8 D_80140458[];
s32 func_8013D43C(u8 *a, void *scale, s32 c);
void func_8013F520(void);
void func_8013E650(void);

void func_8013FC8C(void) {
    SVECTOR v;
    s32 i;
    Obj_8013FC8C *o;
    s16 dx;
    s16 dz;

    for (i = 0; i < 1; i++) {
        D_801407F0[i].f_5C = 0;
        func_8013D43C((u8 *)&D_801407F0[i], D_80140458, 0);
    }
    o = D_801407F0;
    dx = g_Spike.f_24 - o->f_24;
    dz = g_Spike.f_2C - o->f_2C;
    v.vy = 0;
    v.vx = dx;
    v.vz = dz;
    if (dx * dx + dz * dz <= 0x19C98F) {
        func_8013F694(o, 0x14);
    }
    func_8013F520();
    func_8013E650();
}

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_8013FD74);

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140280);

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80141880");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D88(SVECTOR *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6", func_80140F78);

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_80141418(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_80140D88(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

s32 SaveByte_Get(s32);

s32 func_8014149C(s16 *p)
{
  s32 v;
  p[1] = p[4];
  p[3] = 0;
  v = p[1];
  if ((v == 5) && (SaveByte_Get(3) != v))
  {
    p[1] = 2;
  }
  return 0;
}

typedef struct { s32 type; s32 x; s32 y; s32 z; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; s32 f_20; s32 f_24; } Obj_801414F8;
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; u8 pad_812C[0x10C]; Obj_801414F8 *f_8238; u8 pad_823C[0x50]; s32 f_828C; } g_Game_801414F8 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801414F8 asm("g_Spike");
extern s16 D_800EC238;
extern u16 D_800E69BE_801414F8 asm("D_800E69BE");
void func_800863B0(s32, s32);
void Overlay_Request(s32);
s32 Overlay_GetState(void);
void func_8013FC74(void);
void Spike_SetPlayMode(s32);
void Game_SetMode(s32, s32, s32);

s32 func_801414F8(s16 *p) {
    s32 i;
    Obj_801414F8 *o;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            p[1] = 1;
            func_800863B0(2, 0x28);
            Overlay_Request(9);
        }
        break;
    case 1:
        if (Overlay_GetState() == 0) {
            func_800863B0(0, 0);
            p[1] = 3;
            func_8013FC74();
        }
        break;
    case 2:
        if (D_800EC238 == p[2]) {
            p[1] = 3;
            func_8013FC74();
        }
        break;
    case 3:
        if (D_800E69BE_801414F8 == 1) {
            p[1] = 5;
            Spike_SetPlayMode(0xB);
            Game_SetMode(0x1F, g_Game_801414F8.f_8126, g_Game_801414F8.f_812A);
        }
        break;
    case 4:
        if (Overlay_GetState() == 0) {
            p[1] = 5;
            func_800863B0(0, 0);
            Spike_SetPlayMode(0xB);
            o = g_Game_801414F8.f_8238;
            for (i = 0; i < g_Game_801414F8.f_828C; i++) {
                if (o[i].type == 3) {
                    o = &o[i];
                    o->type = 0;
                    o->x = g_Spike_801414F8.x;
                    o->y = g_Spike_801414F8.y;
                    o->z = g_Spike_801414F8.z;
                    o->f_10 = 0x800;
                    o->f_14 = 0x200;
                    o->f_18 = 0x200;
                    o->f_1C = 0x200;
                    o->f_20 = 0x56;
                    o->f_24 = 0;
                    break;
                }
            }
        }
        break;
    case 5:
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 16 bytes (D_80141850 is 16-aligned) */
__asm__(".section .rodata\n\t.align 4\n\t.section .text");

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801416D8 asm("g_Game");
extern s16 D_800EC238;

s32 func_801416D8(s16 *p) {
    u8 *e = g_Game_801416D8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            if (p[3] == 0) {
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
                p[3] = 1;
                p[1] = 3;
                Sound_PlayAt(0x9C, (s32)e);
            }
        } else {
            p[3] = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(e, s16 *, 0x32) == p[8] * 2 + 1 || M2C_FIELD(e, s16 *, 0x32) == p[9] * 2 + 1) {
            Sound_PlayAt(0x9C, (s32)e);
        }
        if (M2C_FIELD(e, s16 *, 0x32) >= p[7] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 0;
            Sound_PlayAt(0x9C, (s32)e);
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6", D_80141850);
