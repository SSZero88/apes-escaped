#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
extern s32 g_StageMeshes;
extern struct S_g_Game { u8 pad_0[0x820C]; s32 f_820C; } g_Game;
s32 SaveByte_Get(M2C_UNK);

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

extern struct S_D_80144590 { u8 pad_0[0xB]; s8 f_B; } D_80144590[];
M2C_UNK Object_PlaySound(s32, M2C_UNK);
M2C_UNK Puff_Spawn(s32, M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_RandSeed;
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK Sound_FreeSlot(s8);
M2C_UNK Hook_Add(M2C_UNK *);
void func_8013F0CC(void);
extern struct S_D_80144A28 { u8 pad_0[0x10]; s8 f_10; u8 pad_11[0x3]; } D_80144A28[];
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_Despawn(s32, M2C_UNK);
extern s32 D_80144650;
M2C_UNK Fx_DebrisExplosion(s16, s16, s16);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_DropPickups(void *);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);
void func_80140310(void);
extern struct S_D_80144AD0 { u8 pad_0[0x10]; s32 f_10; } D_80144AD0[];
void *Collision_GetShape(s32);
M2C_UNK Object_ApplyHit(void *);
M2C_UNK Object_HitFeedback(void *);
M2C_UNK Object_SpawnImpactFx(void *, s16, s16, s16);
M2C_UNK Link_Activate(s16, void *);

s32 func_8013D000(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_80144590[i].f_B = 0;
    }
    return 0;
}

s16 Floor_GetHeight(s16, s16, s16);
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80144590");

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

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D218;
typedef struct { Mat_8013D218 m; Mat_8013D218 w; SVECTOR rot; SVECTOR v[4][4]; s32 sxy[3]; s32 z; } Scr_8013D218;
typedef struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } Part_8013D218;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013D218;
#define ADDPRIM_BF_8013D218(ot, p) (((PTag_8013D218 *)(p))->addr = ((PTag_8013D218 *)(ot))->addr, ((PTag_8013D218 *)(ot))->addr = (u32)(p))
#define gte_ldv3c_8013D218(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_8013D218() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_8013D218(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz_8013D218(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Part_8013D218 D_80144590_8013D218[] asm("D_80144590");
extern Mat_8013D218 D_800E78C0_8013D218 asm("g_ViewMatrix");
extern u16 g_RandSeed_8013D218 asm("g_RandSeed");
void Effect_SpawnAt_8013D218(s32, void *) asm("Effect_SpawnAt");
void Sound_PlayFixed_8013D218(s32) asm("Sound_PlayFixed");
extern GameDraw g_Game_8013D218 asm("g_Game");
void SetRotMatrix_8013D218(Mat_8013D218 *) asm("SetRotMatrix");
void SetTransMatrix_8013D218(Mat_8013D218 *) asm("SetTransMatrix");
void RotMatrixZYX_8013D218(SVECTOR *, Mat_8013D218 *) asm("RotMatrixZYX");
void CompMatrix_8013D218(Mat_8013D218 *, Mat_8013D218 *, Mat_8013D218 *) asm("CompMatrix");
#define SCR_8013D218 ((Scr_8013D218 *)0x1F800000)

s32 func_8013D218(void) {
    s32 i;
    Part_8013D218 *e;
    u32 *p;
    u32 *ot;
    Scr_8013D218 *sc;

    sc = SCR_8013D218;
    sc->w = D_800E78C0_8013D218;
    sc->v[0][0].vx = -0x1C;
    sc->v[0][0].vy = -0x1C;
    sc->v[0][0].vz = 0;
    sc->v[0][1].vx = 0x1C;
    sc->v[0][1].vy = -0x1C;
    sc->v[0][1].vz = 0;
    sc->v[0][2].vx = 0;
    sc->v[0][2].vy = 0x1C;
    sc->v[0][2].vz = 0;
    sc->v[1][0].vx = -0x38;
    sc->v[1][0].vy = -0x38;
    sc->v[1][0].vz = 0;
    sc->v[1][1].vx = 0x38;
    sc->v[1][1].vy = -0x38;
    sc->v[1][1].vz = 0;
    sc->v[1][2].vx = 0;
    sc->v[1][2].vy = 0x38;
    sc->v[1][2].vz = 0;
    sc->v[2][0].vx = -9;
    sc->v[2][0].vy = -0x38;
    sc->v[2][0].vz = 0;
    sc->v[2][1].vx = 9;
    sc->v[2][1].vy = -0x38;
    sc->v[2][1].vz = 0;
    sc->v[2][2].vx = 0;
    sc->v[2][2].vy = 0x54;
    sc->v[2][2].vz = 0;
    sc->v[3][0].vx = -0xE;
    sc->v[3][0].vy = -0xE;
    sc->v[3][0].vz = 0;
    sc->v[3][1].vx = 0xE;
    sc->v[3][1].vy = -0xE;
    sc->v[3][1].vz = 0;
    sc->v[3][2].vx = 0;
    sc->v[3][2].vy = 0xE;
    sc->v[3][2].vz = 0;
    p = (u32 *)g_Game_8013D218.prim;
    ot = g_Game_8013D218.db[g_Game_8013D218.cur].ot;
    for (i = 15; i >= 0; i--) {
        e = &D_80144590_8013D218[i];
        if (e->life != 0) {
            e->life--;
            e->x += e->vx;
            e->y += e->vy;
            e->z += e->vz;
            e->vy += 4;
            if (e->y > e->floor) {
                e->y = e->floor;
                e->vy = -e->vy / 3;
                Effect_SpawnAt_8013D218(4, e);
                if (((g_RandSeed_8013D218 = g_RandSeed_8013D218 * 5 + 1) >> 8 & 3) == 0) {
                    Sound_PlayFixed_8013D218(0x67);
                }
                if (e->vy >= -11) {
                    e->life = 0;
                    continue;
                }
            }
            sc->rot.vx = (e->life << 7) & 0xFFF;
            sc->rot.vy = (e->life << 7) & 0xFFF;
            sc->rot.vz = (e->life << 7) & 0xFFF;
            RotMatrixZYX_8013D218(&sc->rot, &sc->m);
            sc->m.t[0] = e->x;
            sc->m.t[1] = e->y;
            sc->m.t[2] = e->z;
            CompMatrix_8013D218(&sc->w, &sc->m, &sc->m);
            SetRotMatrix_8013D218(&sc->m);
            SetTransMatrix_8013D218(&sc->m);
            gte_ldv3c_8013D218(sc->v[i & 3]);
            gte_rtpt_8013D218();
            gte_stsxy3c_8013D218(sc->sxy);
            gte_stszotz_8013D218(&sc->z);
            if ((u32)(sc->z - 1) < 0xFFF) {
                ((u8 *)p)[3] = 6;
                p[1] = 0x323C8028;
                p[3] = 0x1E4014;
                p[5] = 0xA1C00;
                p[2] = sc->sxy[0];
                p[4] = sc->sxy[1];
                p[6] = sc->sxy[2];
                ADDPRIM_BF_8013D218(ot + sc->z, p);
                p += 7;
                ((u8 *)p)[3] = 1;
                p[1] = 0xE1000220;
                ADDPRIM_BF_8013D218(ot + sc->z, p);
                p += 2;
            }
        }
    }
    g_Game_8013D218.prim = (u8 *)p;
    return 0;
}

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);

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

extern u8 D_801440C4[];
void Shockwave_Spawn(void *, void *, s32, s32, void *);

void func_8013DB34(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    Shockwave_Spawn(m, D_801440C4, 1, 0, (u8 *)arg0 + 0x60);
}

extern u32 g_Game_80140110 asm("g_Game");
extern u8 D_80144070[];

void func_8013DB70(void *arg0) {
    void *m = M2C_FIELD(arg0, void **, 0x78);

    if (g_Game_80140110 & 1) {
        Shockwave_Spawn(m, D_80144070, 1, 0, (u8 *)arg0 + 0x60);
    }
}

void func_8013DBBC(void *arg0) {
    u16 temp_v0;

    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn(arg0 + 0x24, 1, 0, 0x64);
    }
    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    if (!((temp_v0 >> 8) & 0xF)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_8013DC3C(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
}

s32 Math_Atan2(s32, s32);

void func_8013DC88(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013DD14(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    Object_PlaySound(arg0, 0x6F);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    Object_Timer(arg0, 0xA);
}

s32 Object_FlyAboveFloor(void *, s32);

void func_8013DD60(void *arg0) {
    Object_FlyAboveFloor(arg0, 0x14);
}

void func_8013DD80(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_8013DD60(arg0);
}

M2C_UNK Object_ApplyVelocity(void *);
s16 Object_FloorAt(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepGrowShrink(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK VectorNormalSS(void *, void *);

void func_8013DE44(void *arg0) {
    void *temp_a0;

    if (Object_DetachLink(arg0, 0) == 6) {
        Object_PlaySound(arg0, 0x5F);
        goto block_8;
    }
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x53, 0x37, 0);
    }
    if (Object_StepToward3D(arg0, M2C_FIELD(arg0, s16 *, 0xBC), M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s16 *, 0xC0), (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13) != 0) {
        func_8013DC88(arg0);
    } else {
        M2C_FIELD(arg0, u16 *, 0x60) = (u16) M2C_FIELD(arg0, u16 *, 0x94);
        temp_a0 = arg0 + 0x60;
        M2C_FIELD(temp_a0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(temp_a0, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x98);
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) ((M2C_FIELD(arg0, s32 *, 0xE0) & 0xFF3FFFFF) | 0x800000);
        VectorNormalSS(temp_a0, temp_a0);
        Object_ApplyVelocity(arg0);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, (s16) (M2C_FIELD(arg0, u16 *, 0x44) + 0x32), M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x103);
    }
    if (Object_FloorAt(arg0, 0, 0, 0) < M2C_FIELD(arg0, s32 *, 0x28)) {
block_8:
        func_8013DC88(arg0);
    }
}

s32 func_8013DFA8(void *arg0) {
    u8 old;

    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB) {
        M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
        old = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0xCE) = old;
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
        return 1;
    }
    return 0;
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 20; u32 mode : 2; u32 b26 : 6; } Flags_801405CC;
typedef struct { u16 start; u16 end; } Rng_801405CC;
void Object_TurnToward(void *, s16, s16, s16, s16);
void Object_InitOrbit(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
void Object_OrbitHome(void *, s16);
extern struct { u8 pad_0[0x24]; u16 x; u16 p26; u16 y; u16 p2A; u16 z; } g_Spike_801405CC asm("g_Spike");
void Object_ClampAnimFrame_801405CC(void *, s32) asm("Object_ClampAnimFrame");
void Object_PlaySound_801405CC(void *, s32) asm("Object_PlaySound");
void func_80058134_801405CC(void *, s32) asm("Object_DebugStub");
s32 func_80057140_801405CC(void *, s32, s32) asm("Object_AddAttachPoint");
void func_8013DB34(void *arg0);
void func_8013DB70(void *arg0);
void func_8013DBBC(void *arg0);
void func_8013DC3C(void *arg0);
void func_8013DD14(void *arg0);
void func_8013DD60(void *arg0);
void func_8013DD80(void *arg0);
void func_8013DE44(void *arg0);
s32 func_8013DFA8(void *arg0);

void func_8013E02C(u8 *o) {
    if (!M2C_FIELD(o, Flags_801405CC *, 0xE0).init) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x64;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x46) = 0x64;
        M2C_FIELD(o, s16 *, 0x44) = 0x3C;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0xDC) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, s16 *, 0x9C) -= 0xC8;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, Flags_801405CC *, 0xE0).mode = 2;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, Rng_801405CC **, 0x88)[0].start;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, s32 *, 0x74) = func_80057140_801405CC(o, 0xA, 0x9C);
        M2C_FIELD(o, s32 *, 0x78) = func_80057140_801405CC(o, 6, 0x70);
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, Flags_801405CC *, 0xE0).init = 1;
    }
    func_80058134_801405CC(o, M2C_FIELD(o, s16 *, 0x44));
    if (func_8013DFA8(o) == 0) {
        switch (M2C_FIELD(o, u8 *, 0x80)) {
        case 1:
            Object_OrbitHome(o, 8);
            Object_SeekHeight(o, 8);
            func_8013DD60(o);
            if (Object_Timer(o, -1) == 0 && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
                func_8013DD14(o);
            }
            break;
        case 2:
            Object_ClampAnimFrame_801405CC(o, M2C_FIELD(o, Rng_801405CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            Object_TurnToward(o, g_Spike_801405CC.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_801405CC.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
            func_8013DC3C(o);
            func_8013DBBC(o);
            if (Object_Timer(o, -1) == 0) {
                M2C_FIELD(o, u8 *, 0x80) = 3;
                M2C_FIELD(o, s16 *, 0xA8) = 0;
                M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
                M2C_FIELD(o, u16 *, 0xBC) = g_Spike_801405CC.x;
                M2C_FIELD(o, u16 *, 0xC0) = g_Spike_801405CC.z;
                M2C_FIELD(o, u16 *, 0xBE) = g_Spike_801405CC.y - 0xC8;
                M2C_FIELD(o, u8 *, 0x8F) = 0;
                func_8013DB34(o);
            }
            break;
        case 3:
            Object_ClampAnimFrame_801405CC(o, M2C_FIELD(o, Rng_801405CC **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].end);
            if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
                if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                    Object_PlaySound_801405CC(o, 0xA6);
                }
            }
            func_8013DE44(o);
            func_8013DC3C(o);
            func_8013DBBC(o);
            func_8013DB70(o);
            break;
        case 4:
            func_8013DD80(o);
            break;
        }
    }
}

void Object_DebugStub(void *, s32);
s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
s32 rcos_8013E340(s32) asm("rcos");
s32 rsin_8013E340(s32) asm("rsin");
s16 Floor_GetHeight_8013E340(s32, s32, s32) asm("Floor_GetHeight");
void Shadow_Draw(void *, s32, s32, s32);

void func_8013E340(u8 *e) {
    s32 t;
    s32 u;
    s32 w;
    s32 dx;
    s32 dz;
    s32 v[3];

    if (((M2C_FIELD(e, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x3C;
        M2C_FIELD(e, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(e, s16 *, 0x44) = 0x64;
        M2C_FIELD(e, s16 *, 0x4A) = -0x3EFF;
        M2C_FIELD(e, s16 *, 0x48) = 0;
        e[0x7F] = 0;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C) - 0xD7;
        *(volatile u32 *)(e + 0xE0) |= 0x200;
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
        if ((u8)(e[0x7E] - 0x59) < 3) {
            M2C_FIELD(e, u32 *, 0xE0) |= 0x80000;
            M2C_FIELD(e, u16 *, 0x5C) = (*(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88)) + *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88) + 2)) >> 1;
        } else {
            M2C_FIELD(e, u32 *, 0xE0) &= ~0x80000;
        }
        Object_Timer(e, 0);
        M2C_FIELD(e, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(e, M2C_FIELD(e, s16 *, 0x44));
    if (e[0xC9] != 0) {
        e[0xC9]--;
    } else {
        Object_Timer(e, 0x16);
        if (Spike_WithinRadiusXZ(M2C_FIELD(e, s16 *, 0x9A), M2C_FIELD(e, s16 *, 0x9E), 0x800) != 0) {
            Object_PlaySound((s32)e, 0x81);
        }
    }
    if ((M2C_FIELD(e, u32 *, 0xE0) >> 19) & 1) {
        u = M2C_FIELD(e, u16 *, 0x5C) - 2;
        if (u < *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88))) {
            w = *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88) + 2) + 1;
            u = w - (*(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88)) - u);
        }
        M2C_FIELD(e, u16 *, 0x5C) = u;
    }
    if (((M2C_FIELD(e, u32 *, 0xE0) >> 2) & 1) == 0) {
        t = ((M2C_FIELD(e, u16 *, 0x5C) - *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88))) << 12) / (*(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88) + 2) - *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88)) + 1);
        t = (t + 0x5FA) % 4096;
        dx = rcos_8013E340(t) * 797 >> 12;
        dz = rsin_8013E340(t) * 797 >> 12;
        Object_AddAttackSphereNear(e, 0x78, M2C_FIELD(e, u16 *, 0x24) + dx, M2C_FIELD(e, s16 *, 0x28), (s16)(M2C_FIELD(e, u16 *, 0x2C) + dz), 1, 0x203);
        v[0] = M2C_FIELD(e, s32 *, 0x24) + dx;
        v[1] = M2C_FIELD(e, s32 *, 0x28);
        v[2] = M2C_FIELD(e, s32 *, 0x2C) + dz;
        Shadow_Draw(v, Floor_GetHeight_8013E340(v[0], v[1], v[2]), 100, *(s32 *)0x1F8003FC);
    }
}

void func_8013E674(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013E6B4(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013E6F8(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

void Object_DebugStub(void *, s32);
void Object_EnableCollision(void *);
void func_80052038_80140F9C(void *, s32) asm("Object_SetModel");
void func_8013E674(void *arg0);
void func_8013E6B4(void *arg0);
void func_8013E6F8(void *arg0);

void func_8013E774(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x44) = 0xFA;
        M2C_FIELD(o, s16 *, 0x46) = 0x200;
        M2C_FIELD(o, s8 *, 0x7C) = -1;
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_DisableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        M2C_FIELD(o, s16 *, 0xC2) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(o, u8 *, 0xCF) == 1) {
        M2C_FIELD(o, u8 *, 0x80) = 2;
        M2C_FIELD(o, u8 *, 0x7F) = 1;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        Object_EnableCollision(o);
        func_80052038_80140F9C(o, 0x84);
        Object_PlaySound(o, 0x5C);
    }
    M2C_FIELD(o, u8 *, 0xCF) = 0;
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, s16 *, 0xC2) = 0x12C;
            func_8013E674(o);
            func_8013E6F8(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, s16 *, 0xC2) != 0) {
            M2C_FIELD(o, s16 *, 0xC2)--;
        } else {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8013E6B4(o);
            Object_PlaySound(o, 0x5E);
        }
        break;
    case 4:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_80052038_80140F9C(o, 0x19);
            Object_DisableCollision(o);
        }
        break;
    }
}

extern u8 D_80144118[];

void func_8013E990(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x1E;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Shockwave_Spawn(&v, D_80144118, 1, 0, 0);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[8]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; s16 life; } Debris_8013E9E0;
extern Debris_8013E9E0 D_80144688_8013E9E0[] asm("D_80144688");
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Obj_8013E9E0;

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013E9E0(o)
    void *o;
{
    s32 i;
    Debris_8013E9E0 *d;
    s32 k;

    for (i = 0; i < 7; i++) {
        d = &D_80144688_8013E9E0[i];
        k = i + 0x96;
        Object_SetModel(d, k);
        Object_GetAnimTable(d, k);
        d->f5C = 0;
        d->f62 = 0;
        d->f60 = 0;
        d->f64 = 0x1000;
        d->f66 = 3;
        d->x = ((Obj_8013E9E0 *)o)->x + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->y = ((Obj_8013E9E0 *)o)->y - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8);
        d->z = ((Obj_8013E9E0 *)o)->z + ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x40;
        d->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 6) << 12) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 1;
    }
}

typedef struct { s16 x, y, z; } Rot_8013ECCC;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_8013ECCC r; s16 life; } Debris_8013ECCC;
extern Debris_8013ECCC D_80144688[7];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013ECCC asm("g_Game");
extern u8 g_ProjVerts[];
s32 Object_IsOffScreen(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
M2C_UNK Model_ProjectBonedVerts(void *);
void Model_DrawAuto(void *, void *, void *);

void func_8013ECCC(u8 *arg0) {
    s32 i;
    Debris_8013ECCC *d;
    SVECTOR v;

    for (i = 0; i < 7; i++) {
        d = &D_80144688[i];
        if (d->life != 0) {
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            v.vx = d->x;
            v.vy = d->y;
            v.vz = d->z;
            if (M2C_FIELD(arg0, s16 *, 0x9C) < d->y) {
                d->life = 0;
                v.vy = M2C_FIELD(arg0, s16 *, 0x9C) - 0x32;
                Effect_SpawnAt(0x102, &v);
                Object_PlaySound((s32)arg0, 0x6E);
                continue;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (Object_IsOffScreen(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                Model_CalcKeyedJointMatrices(d, 3);
                Model_ProjectBonedVerts(d);
                Model_DrawAuto(g_Game_8013ECCC.f_80 + g_Game_8013ECCC.f_C * 0x4078, g_ProjVerts, d);
                Effect_SpawnAt(7, &v);
                Dust_SpawnDrift(&v);
            }
        }
    }
}

void func_8013EEDC(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_80144A28[i].f_10 = 0;
    }
    Hook_Add(&func_8013F0CC);
}

typedef struct { u8 pad0[0x10]; s8 f; u8 pad[0x3]; } Slot_8013EF20;
extern Slot_8013EF20 D_80144A28_s[8] asm("D_80144A28");

s32 func_8013EF20(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_80144A28_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { SVECTOR a; SVECTOR b; u8 f_10; u8 f_11; u8 f_12; u8 f_13; } Spark_8013EF5C;
extern Spark_8013EF5C D_80144A28_8013EF5C[8] asm("D_80144A28");
s32 func_8013EF20(void);

void func_8013EF5C(SVECTOR *a, SVECTOR *b, s32 c, s32 d) {
    s32 i = func_8013EF20();
    Spark_8013EF5C *p;

    if (i != -1) {
        p = &D_80144A28_8013EF5C[i];
        p->a.vx = a->vx;
        p->a.vy = a->vy;
        p->a.vz = a->vz;
        p->b.vx = b->vx;
        p->b.vy = b->vy;
        p->b.vz = b->vz;
        p->f_10 = 8;
        p->f_12 = c;
        p->f_13 = d;
    }
}

M2C_UNK Object_AddAttackSphere(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s16, s16, M2C_UNK);
extern s32 D_800EC208;
extern M2C_UNK g_Objects;

void func_8013F018(void *arg0) {
    s16 temp_a3;
    s32 var_v0;
    void *temp_s1;

    temp_s1 = (u8 *)&g_Objects + (M2C_FIELD(arg0, s8 *, 0x12) * 0xE4);
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 4), 0xC8) != 0) {
        temp_a3 = M2C_FIELD(arg0, s16 *, 2);
        var_v0 = (temp_a3 - D_800EC208) + 0x7D;
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 < 0xC9) {
            Object_AddAttackSphere(temp_s1, 0x64, M2C_FIELD(arg0, s16 *, 0), temp_a3, (s32) M2C_FIELD(arg0, s16 *, 4), 0x201, 0x202);
        }
    }
}

typedef struct { s16 x, y, z, pad6; s16 vx, vy, vz, padE; s8 t; u8 pad11[2]; s8 f13; } Spark_8013F0CC;
extern Spark_8013F0CC D_80144A28_8013F0CC[8] asm("D_80144A28");
void Dust_SpawnStill(void *);

void func_8013F0CC(void) {
    Spark_8013F0CC *p;
    s32 i;

    for (i = 7; i >= 0; i--) {
        p = &D_80144A28_8013F0CC[i];
        if (p->t != 0) {
            p->t--;
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            Dust_SpawnStill(p);
            if (p->f13 != 0) {
                func_8013F018(p);
            }
        }
    }
}

void func_8013F170(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(arg1 | 0x7000, 0x1000, arg0 + 0x24);
    }
}

void func_8013F1B0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        Sound_FreeSlot(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void func_8013F1F4(u8 *a, s32 n) {
    u8 *l;
    u8 *r;

    a[0x7F] = n;
    M2C_FIELD(a, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(a, u8 **, 0x88) + a[0x7F] * 4);
    l = M2C_FIELD(a, u8 **, 0x74);
    r = M2C_FIELD(a, u8 **, 0x78);
    switch (n) {
    case 9:
        M2C_FIELD(r, s16 *, 8) = 7;
        M2C_FIELD(l, s16 *, 8) = 7;
        M2C_FIELD(l, s16 *, 0xA) = 0x5D;
        M2C_FIELD(r, s16 *, 0xA) = 0x5E;
        break;
    case 8:
        M2C_FIELD(r, s16 *, 8) = 0x11;
        M2C_FIELD(l, s16 *, 8) = 0x11;
        M2C_FIELD(l, s16 *, 0xA) = 0xE5;
        M2C_FIELD(r, s16 *, 0xA) = -1;
        break;
    case 5:
        M2C_FIELD(r, s16 *, 8) = 0x10;
        M2C_FIELD(l, s16 *, 8) = 0x10;
        M2C_FIELD(l, s16 *, 0xA) = 0xCB;
        M2C_FIELD(r, s16 *, 0xA) = 0xC5;
        break;
    }
}

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013F2A4 asm("g_Spike");
s32 Object_SpikeOutOfYRange(void *, s32);
s32 Vec_Length(s32, s32, s32);

s32 func_8013F2A4(void *arg0) {
    s32 d;

    if (Object_SpikeOutOfYRange(arg0, M2C_FIELD(arg0, s32 *, 0x28)) != 0) {
        return -1;
    }
    d = Vec_Length(g_Spike_8013F2A4.x - M2C_FIELD(arg0, s32 *, 0x24), 0, g_Spike_8013F2A4.z - M2C_FIELD(arg0, s32 *, 0x2C));
    if (d > 0x1400) {
        return -1;
    }
    return d;
}

void func_8013F1F4(u8 *a, s32 n);

s32 func_8013F318(void *arg0) {
    if (func_8013F2A4(arg0) == -1) {
        return 0;
    }
    if (M2C_FIELD(arg0, u8 *, 0x8F) != 0) {
        M2C_FIELD(arg0, u8 *, 0x80) = 6;
        func_8013F1F4(arg0, 9);
    } else {
        M2C_FIELD(arg0, u8 *, 0x80) = 9;
        func_8013F1F4(arg0, 8);
    }
    M2C_FIELD(arg0, u8 *, 0x8F) ^= 1;
    return 1;
}

void func_8013F390(u8 *a, s32 n, s32 k)
{
  s16 *l;
  s16 *r;
  s32 w;
  s32 h;
  SVECTOR v;
  if ((*((u16 *) (((s8 *) a) + 0x5C))) == ((*((u16 *) ((*((u8 **) (((s8 *) a) + 0x88))) + (a[0x7F] * 4)))) + (++k)))
  {
    l = *((s16 **) (((s8 *) a) + 0x74));
    r = *((s16 **) (((s8 *) a) + 0x78));
    w = (-(n << 1)) + 12;
    h = ((n & 1) * 14) + 10;
    v.vx = ((l[0] * w) + (r[0] * (16 - w))) / 16;
    v.vy = l[1] + h;
    v.vz = ((l[2] * w) + (r[2] * (16 - w))) / 16;
    EnemyShot_Spawn(&v, a, 6, ((g_RandSeed = (g_RandSeed * 5) + 1) >> 8) % 5);
  }
}

typedef struct { u16 f_0; s16 f_2; } Fr_8013F4C8;
void EnemyShot_Spawn(void *, void *, s32, SVECTOR *);

void func_8013F4C8(u8 *o) {
    SVECTOR v;
    SVECTOR *a;
    SVECTOR *b;
    s32 k;
    s32 r;

    r = M2C_FIELD(o, u16 *, 0x5C) - M2C_FIELD(o, Fr_8013F4C8 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F)].f_0;
    k = r - 5;
    if (k >= 0 && k < 26) {
        r = k % 5;
        if (r == 0) {
            a = M2C_FIELD(o, SVECTOR **, 0x74);
            b = M2C_FIELD(o, SVECTOR **, 0x78);
            v.vx = a->vx - b->vx;
            v.vy = 0;
            v.vz = a->vz - b->vz;
            VectorNormalSS(&v, &v);
            v.vx /= 48;
            v.vy /= 48;
            v.vz /= 48;
            Object_PlaySound((s32)o, 0x58);
            EnemyShot_Spawn(a, o, 1, &v);
        } else if (r == 2) {
            Object_PlaySound((s32)o, 0x58);
        }
    }
}


void func_8013F630(u8 *o) {
    SVECTOR v;
    SVECTOR *a = M2C_FIELD(o, SVECTOR **, 0x74);
    SVECTOR *b = M2C_FIELD(o, SVECTOR **, 0x78);

    v.vx = a->vx - b->vx;
    v.vy = a->vy - b->vy;
    v.vz = a->vz - b->vz;
    VectorNormalSS(&v, &v);
    v.vx /= 64;
    v.vy /= 64;
    v.vz /= 64;
    if (M2C_FIELD(o, u8 *, 0x7F) == 5) {
        func_8013EF5C(a, &v, M2C_FIELD(o, s8 *, 0xCB), 0);
    } else {
        func_8013EF5C(a, &v, M2C_FIELD(o, s8 *, 0xCB), 1);
    }
}

extern u32 g_Game_8013F718 asm("g_Game");
void func_8013D73C(void *arg0);
void func_8013D840(s32 arg0);
void func_8013D8A8(void *arg0);

void func_8013F718(u8 *o) {
    u8 v;

    if (M2C_FIELD(o, u8 *, 0x80) != 0xD && (g_Game_8013F718 & 1)) {
        v = M2C_FIELD(o, u8 *, 0x81);
        if (v < 5) {
            func_8013D73C(o);
            func_8013D73C(o);
            func_8013D73C(o);
            func_8013D8A8(o);
            func_8013D8A8(o);
            func_8013D840((s32)o);
            func_8013D840((s32)o);
        } else if (v < 10) {
            func_8013D73C(o);
            func_8013D73C(o);
            func_8013D8A8(o);
            func_8013D840((s32)o);
        } else if (v < 15) {
            func_8013D73C(o);
            func_8013D840((s32)o);
        } else if (v < 20) {
            func_8013D73C(o);
        }
    }
}

void func_8013F800(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80144650 - 1;
    D_80144650 = temp_v0;
    if (temp_v0 == 0) {
        Link_SendEvent(0xF, 0x1E, 0);
    }
    Object_Despawn(arg0, 1);
}

void func_8013F850(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 0xD;
    func_8013E9E0();
    Object_Timer(arg0, 0x3C);
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    Object_DisableCollision(arg0);
    Object_DropPickups(arg0);
    Object_PlaySound(arg0, 0x4D);
    Fx_DebrisExplosion(M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s16 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C));
}

s32 Spike_WithinRadiusXZ_8013F8BC(s32, s32, s32) asm("Spike_WithinRadiusXZ");
s32 Collision_GetId(s32);
void func_8013F170(void *arg0, s32 arg1);
void func_8013F1B0(void *arg0);
void func_8013F800(s32 arg0);

s32 func_8013F8BC(u8 *e) {
    u8 *s;
    s32 id;

    if (e[0x82] != 0) {
        func_8013F1B0(e);
        if (e[0x81] != 0) {
            if (Spike_WithinRadiusXZ_8013F8BC(M2C_FIELD(e, s32 *, 0x24), M2C_FIELD(e, s32 *, 0x2C), 1000)) {
                u8 *l = M2C_FIELD(e, u8 **, 0x74);
                u8 *r = M2C_FIELD(e, u8 **, 0x78);

                M2C_FIELD(r, s16 *, 8) = 0x10;
                M2C_FIELD(l, s16 *, 8) = 0x10;
                M2C_FIELD(l, s16 *, 0xA) = 0xCB;
                M2C_FIELD(r, s16 *, 0xA) = 0xC5;
                e[0xCE] = 5;
            } else {
                e[0xCE] = 8;
            }
        } else {
            e[0xCE] = 9;
        }
        if (M2C_FIELD(e, s16 *, 0x9C) + 0x600 < M2C_FIELD(e, s32 *, 0x28)) {
            func_8013F800((s32)e);
        }
        return 1;
    }
    if ((M2C_FIELD(e, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(e, u32 *, 0xE0) &= ~0x100000;
        if (e[0x81] != 0) {
            if (Spike_WithinRadiusXZ_8013F8BC(M2C_FIELD(e, s32 *, 0x24), M2C_FIELD(e, s32 *, 0x2C), 1000)) {
                e[0x80] = 10;
                func_8013F1F4(e, 5);
                func_8013F170(e, 0x65);
                return 0;
            }
            { register u8 *a asm("$4") = e; register s32 n asm("$5") = 8; __asm__ volatile("" : : "r"(a), "r"(n)); e[0x80] = 9; func_8013F1F4(a, n); }
        } else {
            e[0x80] = 12;
            e[0x7F] = 9;
            M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[0x12];
            Object_Timer(e, 30);
        }
        e[0xDD] = 0;
        return 0;
    }
    if (e[0xDD] != 0 && (M2C_FIELD(e, u32 *, 0x50) >> 28) == 0xB) {
        s = Collision_GetShape(M2C_FIELD(e, u16 *, 0x50) & 0xFFF);
        id = Collision_GetId(M2C_FIELD(e, u16 *, 0x50) & 0xFFF);
        if ((M2C_FIELD(s, s16 *, 0x24) & 0xFF00) != 0xD00 && id != 2) {
            e[0xCE] = e[0x7F];
            e[0x7F] = e[0xCD];
            M2C_FIELD(e, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(e, u8 **, 0x88) + e[0x7F] * 4);
            Object_ApplyHit(e);
            Object_HitFeedback(e);
            return 1;
        }
    }
    return 0;
}

s32 func_8013FAD4(u8 *e) {
    if (func_8013F2A4(e) < 0x4E3) {
        e[0x80] = 0xB;
        e[0x7F] = 0xB;
        M2C_FIELD(e, u16 *, 0x5C) = *(u16 *)(e[0x7F] * 4 + M2C_FIELD(e, u8 **, 0x88));
        return 1;
    }
    return 0;
}

void func_8013FB24(void *arg0) {
    u8 temp_v0;
    u8 temp_v1;

    if ((M2C_FIELD(arg0, u8 *, 0xC8) != 0) && (temp_v1 = M2C_FIELD(arg0, u8 *, 0x80), (temp_v1 != 0xC)) && (temp_v1 != 0xD)) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x118, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xC8), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0, 0x100);
    }
}

extern struct { u8 f_0; u8 f_1; } D_800E77A0;
typedef struct { u8 pad0[8]; s16 f_8; s16 f_A; } Pt_8013FBDC;
typedef struct { u32 b0 : 12; u32 b12 : 1; u32 b13 : 1; u32 b14 : 7; u32 b21 : 1; u32 b22 : 2; u32 b24 : 2; u32 b26 : 6; } Bits_8013FBDC;
extern u8 D_80144658[];
void func_8013EEDC(void);

void func_8013FBDC(u8 *o) {
    M2C_FIELD(o, s16 *, 0xA0) = 0x12C;
    M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(o, s16 *, 0x44) = 0xE6;
    M2C_FIELD(o, s16 *, 0x46) = 0x190;
    o[0xCD] = 4;
    o[0x7D] = 7;
    o[0xDC] = 6;
    M2C_FIELD(o, s8 *, 0x7C) = -1;
    o[0xC8] = 0;
    M2C_FIELD(o, Bits_8013FBDC *, 0xE0).b24 = 1;
    M2C_FIELD(o, Bits_8013FBDC *, 0xE0).b21 = 1;
    o[0xDD] = 1;
    M2C_FIELD(o, Bits_8013FBDC *, 0xE0).b12 = 0;
    o[0x81] = 0x14;
    M2C_FIELD(o, Bits_8013FBDC *, 0xE0).b13 = 1;
    M2C_FIELD(o, Pt_8013FBDC **, 0x74) = (Pt_8013FBDC *)(D_80144658 + D_800E77A0.f_1 * 0x18);
    M2C_FIELD(o, Pt_8013FBDC **, 0x74)->f_8 = 7;
    M2C_FIELD(o, Pt_8013FBDC **, 0x74)->f_A = 0x5D;
    M2C_FIELD(o, Pt_8013FBDC **, 0x78) = (Pt_8013FBDC *)(D_80144658 + 0xC + D_800E77A0.f_1 * 0x18);
    M2C_FIELD(o, Pt_8013FBDC **, 0x78)->f_8 = 7;
    M2C_FIELD(o, Pt_8013FBDC **, 0x78)->f_A = 0x5E;
    func_8013EEDC();
    o[0x80] = 1;
    o[0xDE] = 0;
    o[0x8F] = 0;
    M2C_FIELD(o, s32 *, 0x28) -= 0xBB8;
    Object_DisableCollision(o);
    D_80144650 = 0;
    D_800E77A0.f_1++;
}

typedef struct { u16 start; u16 end; } Rng_8013FD38;
extern u8 D_800E77A1;
void func_8013FBDC(u8 *o);
void func_8013F718(u8 *o);
s32 func_8013F8BC(u8 *e);
void Object_TurnTowardSpike(void *);
void Object_ClampAnimFrame(void *, s32);
s32 Object_FallToFloor(void *);
void func_8013DAC8(void *arg0);
void func_8013F850(void *arg0);
void func_8013ECCC(u8 *arg0);
void func_8013F800(s32 arg0);
void func_8013E990(void *arg0);
s32 func_8013F318(void *arg0);
s32 func_8013FAD4(u8 *e);
void func_8013F4C8(u8 *o);
void func_8013F630(u8 *o);
void func_8013F1B0(void *arg0);
void func_8013FB24(void *arg0);
#define TBL_8013FD38 (M2C_FIELD(o, Rng_8013FD38 **, 0x88))
#define FRAME_8013FD38 (M2C_FIELD(o, u16 *, 0x5C))

void func_8013FD38(u8 *o) {
    s32 v;
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        func_8013FBDC(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    func_8013F718(o);
    if (func_8013F8BC(o) != 0) {
        return;
    }
    Object_TurnTowardSpike(o);
    switch (o[0x80]) {
    case 12:
        if (TBL_8013FD38[o[0x7F]].start + 3 < FRAME_8013FD38) {
            FRAME_8013FD38 = TBL_8013FD38[o[0x7F]].start;
        }
        func_8013DAC8(o);
        if (Object_Timer(o, -1) == 0) {
            func_8013F850(o);
        }
        break;
    case 13:
        func_8013ECCC(o);
        if (Object_Timer(o, -1) == 0) {
            func_8013F800((s32)o);
        }
        break;
    case 1:
        if (Spike_WithinRadiusXZ(M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s16 *, 0x9E), 0x800)) {
            if (((M2C_FIELD(o, s16 *, 0x9C) - D_800EC208) < 0 ? -(M2C_FIELD(o, s16 *, 0x9C) - D_800EC208) : (M2C_FIELD(o, s16 *, 0x9C) - D_800EC208)) < 0xC8) {
                D_80144650++;
                o[0x80] = 2;
            }
        }
        break;
    case 2:
        if (D_80144650 == D_800E77A1) {
            o[0x80] = 3;
            o[0x7F] = 0xC;
            FRAME_8013FD38 = TBL_8013FD38[o[0x7F]].start;
            o[0xC8] = 0xC;
            M2C_FIELD(o, s16 *, 0x96) = 0;
            Object_EnableCollision(o);
        }
        break;
    case 3:
        Object_TurnTowardSpike(o);
        M2C_FIELD(o, s16 *, 0x96) += 7;
        Object_ClampAnimFrame(o, TBL_8013FD38[o[0x7F]].start + 0x28);
        if (Object_FallToFloor(o)) {
            o[0x80] = 5;
            Object_PlaySound((s32)o, 0x4B);
            Object_PlaySound((s32)o, 0x8D);
            func_8013E990(o);
        }
        break;
    case 5:
        Object_TurnTowardSpike(o);
        if (FRAME_8013FD38 < TBL_8013FD38[o[0x7F]].end) {
            break;
        }
        {
            o[0x80] = 4;
            o[0x7F] = 0;
            FRAME_8013FD38 = TBL_8013FD38[0].start;
        }
        break;
    case 4:
        func_8013F318(o);
        break;
    case 11:
        if (FRAME_8013FD38 >= TBL_8013FD38[o[0x7F]].end && func_8013F318(o) == 0) {
            o[0x80] = 4;
            o[0x7F] = 0;
            FRAME_8013FD38 = TBL_8013FD38[0].start;
        }
        break;
    case 6:
        if (FRAME_8013FD38 >= TBL_8013FD38[o[0x7F]].end) {
            o[0x80] = 7;
            o[0x7F] = 0xA;
            FRAME_8013FD38 = TBL_8013FD38[0xA].start;
        }
        break;
    case 7:
        func_8013F390(o, 0, 0);
        func_8013F390(o, 4, 0);
        if (FRAME_8013FD38 >= TBL_8013FD38[o[0x7F]].end && func_8013FAD4(o) == 0) {
            o[0x80] = 8;
            Object_Timer(o, 0x14);
        }
        break;
    case 8:
        Object_ClampAnimFrame(o, TBL_8013FD38[o[0x7F]].start);
        if (func_8013FAD4(o) == 0 && Object_Timer(o, -1) == 0) {
            o[0x80] = 0xB;
            o[0x7F] = 0xB;
            FRAME_8013FD38 = TBL_8013FD38[0xB].start;
        }
        break;
    case 9:
        func_8013F4C8(o);
        if (FRAME_8013FD38 >= TBL_8013FD38[o[0x7F]].end - 1) {
            o[0xDD] = 1;
            o[0x80] = 0xB;
            o[0x7F] = 0;
            FRAME_8013FD38 = TBL_8013FD38[0].start;
        }
        break;
    case 10:
        func_8013F630(o);
        if (FRAME_8013FD38 >= TBL_8013FD38[o[0x7F]].end) {
            if (o[0x7F] == 5) {
                o[0x7F] = 6;
                FRAME_8013FD38 = TBL_8013FD38[6].start;
            } else {
                o[0x80] = 0xB;
                o[0x7F] = 7;
                FRAME_8013FD38 = TBL_8013FD38[7].start;
                func_8013F1B0(o);
            }
        }
        break;
    }
    func_8013FB24(o);
}

void func_801401F4(void) {
    s32 i;

    for (i = 5; i >= 0; i--) {
        D_80144AD0[i].f_10 = 0;
    }
    Hook_Add(&func_80140310);
}

typedef struct { u8 pad0[0x10]; s32 f; } Slot_80140238;
extern Slot_80140238 D_80144AD0_s[6] asm("D_80144AD0");

s32 func_80140238(void) {
    s32 i;

    for (i = 5; i >= 0; i--) {
        if (D_80144AD0_s[i].f == 0) {
            return i;
        }
    }
    return -1;
}

void func_80140274(void *arg0, void *arg1) {
    s32 temp_v0;
    void *temp_v1;

    temp_v0 = func_80140238();
    if (temp_v0 != -1) {
        temp_v1 = (void *)((u8 *)&D_80144AD0 + (temp_v0 * 0x14));
        M2C_FIELD(temp_v1, SVECTOR *, 0) = M2C_FIELD(arg0, SVECTOR *, 0);
        M2C_FIELD(temp_v1, SVECTOR *, 8) = M2C_FIELD(arg1, SVECTOR *, 0);
        M2C_FIELD(temp_v1, s32 *, 0x10) = 3;
    }
}

typedef struct { SVECTOR a; SVECTOR b; s32 n; } Spark_80140310;
extern Spark_80140310 D_80144AD0_80140310[6] asm("D_80144AD0");
extern struct { u16 f_0; } g_Game_80140310 asm("g_Game");
void Fx_DrawLightning(SVECTOR *, SVECTOR *, u16);

void func_80140310(void) {
    s32 i;
    Spark_80140310 *p;

    for (i = 5; i >= 0; i--) {
        p = &D_80144AD0_80140310[i];
        if (p->n) {
            p->n--;
            Fx_DrawLightning(&p->a, &p->b, g_Game_80140310.f_0);
        }
    }
}

void func_80140380(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * arg2) >> 0xC));
    M2C_FIELD(arg1, s16 *, 2) = (s16) ((M2C_FIELD(arg0, u16 *, 0x28) + ((s32) (M2C_FIELD(arg0, s16 *, 0x62) * arg2) >> 0xC)) - 0x4C);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * arg2) >> 0xC));
}

void func_80140274(void *arg0, void *arg1);
void func_80140380(void *arg0, void *arg1, s32 arg2);
void Fx_DrawFadeRing(void *, s32, s32, s32);
#define RAND_801403E8() (g_RandSeed = g_RandSeed * 5 + 1)

void func_801403E8(u8 *e) {
    SVECTOR v;
    SVECTOR s;
    u8 c = e[0xC9];
    u8 f;

    if (c > 0x40) {
        if ((c & 3) == 0) {
            v.vx = M2C_FIELD(e, u16 *, 0x94) + ((RAND_801403E8() >> 8) - 0x80) * 2;
            v.vy = M2C_FIELD(e, u16 *, 0x96) - ((RAND_801403E8() >> 8) - 0x80) * 2;
            v.vz = M2C_FIELD(e, u16 *, 0x98) + ((RAND_801403E8() >> 8) - 0x80) * 2;
            func_80140380(e, &s, 0x72);
            func_80140274(&s, &v);
        }
        if (e[0xC9] >= 0x4B && ((RAND_801403E8() >> 8) & 3) == 0) {
            Object_PlaySound((s32)e, 0x5B);
        }
    } else {
        f = 0x40 - c;
        if (c == 0x40) {
            Object_PlaySound((s32)e, 0x8E);
        }
        Fx_DrawFadeRing(e + 0x94, e[0xC9] * 24, 4, ((f & 0xFF) << 16) | ((f & 0xFF) << 8) | (f & 0xFF));
        e[0xC9] = e[0xC9] * 3 / 4;
    }
}

extern u8 D_8014416C[];
void EnemyShot_Spawn(void *, void *, s32, SVECTOR *);

void func_80140598(u8 *o)
{
  u16 new_var;
  SVECTOR v;
  v.vx = g_Spike.f_24 - (*((u16 *) (((s8 *) o) + 0x24)));
  new_var = *((u16 *) (((s8 *) o) + 0x28));
  v.vy = (g_Spike.f_28 - new_var) - 0x34;
  v.vz = g_Spike.f_2C - (*((u16 *) (((s8 *) o) + 0x2C)));
  VectorNormalSS(&v, &v);
  v.vx /= 16;
  v.vy /= 16;
  v.vz /= 16;
  EnemyShot_Spawn(o + 0x94, o, 2, &v);
  Shockwave_Spawn(o + 0x94, D_8014416C, 1, 0, o + 0x60);
  Object_PlaySound((s32) o, 0xA0);
}

void func_80140694(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

s32 func_801406FC(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), 0x800) == 0;
}

s32 func_80140730(void *arg0) {
    void *temp_a3;

    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        temp_a3 = Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF);
        if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) || ((M2C_FIELD(temp_a3, s16 *, 0x24) & 0xFF00) == 0x800)) {
            Object_ApplyHit(arg0);
            Object_HitFeedback(arg0);
            return 1;
        }
        Object_SpawnImpactFx(arg0, (s16) (M2C_FIELD(temp_a3, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - M2C_FIELD(temp_a3, u16 *, 4)), (s16) (M2C_FIELD(temp_a3, u16 *, 8) - M2C_FIELD(arg0, u16 *, 0x2C)));
        Object_PlaySound(arg0, 0x67);
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

void func_801401F4(void);
void func_801403E8(u8 *e);
void func_80140694(void *arg0);
s32 func_801406FC(void *arg0);
s32 func_80140730(void *arg0);

void func_80140800(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 200;
        M2C_FIELD(o, s16 *, 0x46) = 200;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
        M2C_FIELD(o, u8 *, 0xDC) = 4;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u8 *, 0xC8) = 6;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFCFFFFFF) | 0x2000000;
        func_801401F4();
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (func_80140730(o) != 0) {
        return;
    }
    func_80140694(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (func_801406FC(o) != 0) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_PlaySound((s32)o, 0x5C);
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_Timer(o, 0x90);
        }
        break;
    case 3:
        func_80140380(o, o + 0x94, 0xA2);
        func_801403E8(o);
        if (Object_Timer(o, -1) == 0) {
            func_80140598(o);
            M2C_FIELD(o, u8 *, 0x80) = 4;
            Object_Timer(o, 0x1E);
        }
        break;
    case 4:
        if (Object_Timer(o, -1) == 0) {
            if (func_801406FC(o) != 0) {
                M2C_FIELD(o, u8 *, 0x80) = 3;
                Object_Timer(o, 0x90);
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 5;
                M2C_FIELD(o, u8 *, 0x7F) = 3;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
                Object_PlaySound((s32)o, 0x5C);
            }
        }
        break;
    case 5:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    }
}

s32 func_80140AA0(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xA) == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    } else {
        Link_Activate(M2C_FIELD(arg0, s16 *, 0xC), arg0);
        M2C_FIELD(arg0, s16 *, 2) = 1;
    }
    return 0;
}

s32 func_80140AF0(void *arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 2);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (func_80140B7C(arg0) != 0) {
            Link_Activate(M2C_FIELD(arg0, s16 *, 0xC), arg0);
            M2C_FIELD(arg0, s16 *, 2) = 1;
        }
        break;
    case 1:
        if (func_80140B7C(arg0) == 0) {
            Link_Activate(M2C_FIELD(arg0, s16 *, 0xC), arg0);
            M2C_FIELD(arg0, s16 *, 2) = 0;
        }
        break;
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; u8 pad_4[0x14]; } T_80140B7C;
extern T_80140B7C *D_800F4570_80140B7C asm("D_800F4570");

s32 func_80140B7C(void *arg0) {
    s16 *p = arg0;
    s16 n = p[7];
    s16 i;
    s32 k;

    if (n <= 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        k = p[8 + i] * 0x18;
        if (M2C_FIELD((u8 *)D_800F4570_80140B7C + k, s16 *, 2) != 1) {
            return 0;
        }
    }
    return 1;
}

typedef struct { s16 f[12]; } S18_80140C00;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80140C00 *f_8220; } g_Game_80140C00 asm("g_Game");

s32 func_80140C00(s16 *p) {
    u8 *e = g_Game_80140C00.f_820C + p[2] * 0x38;
    S18_80140C00 *t;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 4);
    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    p[1] = 0;
    p[3] = 0;
    p[11] = -1;
    if (p[4] >= 0) {
        t = g_Game_80140C00.f_8220 + p[4];
        t->f[3] = p[6];
    }
    if (p[5] >= 0) {
        t = g_Game_80140C00.f_8220 + p[5];
        t->f[3] = p[6];
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80140CB4;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80140CB4 *f_8220; } g_Game_80140CB4 asm("g_Game");
extern u8 *D_800B4D64_80140CB4 asm("g_StageMeshes");
s16 Sound_Play(s32, s32);

s32 func_80140CB4(s16 *p) {
    s32 d = 0;
    u8 *e = g_Game_80140CB4.f_820C + p[2] * 0x38;
    S18_80140CB4 *t;
    s32 lim;

    if (p[4] >= 0) {
        t = g_Game_80140CB4.f_8220 + p[4];
        d = t->f[11];
    }
    if (p[5] >= 0) {
        t = g_Game_80140CB4.f_8220 + p[5];
        d -= t->f[11];
    }
    lim = p[6];
    if (lim < d || d < (lim = -lim)) {
        d = lim;
    }
    if (d != 0) {
        if (p[11] < 0) {
            p[11] = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, p[11], 0x1000, (s32)e);
        }
    } else if (p[11] >= 0) {
        Sound_Stop(0x7F, p[11]);
        p[11] = -1;
    }
    M2C_FIELD(e, u16 *, 4) = M2C_FIELD(e, u16 *, 0x28) - d;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_80140CB4 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x14) = M2C_FIELD(e, u16 *, 0x28) - d;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80140E1C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80140E1C *f_8220; } g_Game_80140E1C asm("g_Game");

s32 func_80140E1C(s16 *p) {
    u8 *e = g_Game_80140E1C.f_820C + p[2] * 0x38;
    S18_80140E1C *t;
    s32 x;

    M2C_FIELD(e, s16 *, 0x24) = M2C_FIELD(e, s16 *, 0);
    M2C_FIELD(e, s16 *, 0x26) = M2C_FIELD(e, s16 *, 2);
    M2C_FIELD(e, s16 *, 0x28) = M2C_FIELD(e, s16 *, 4);
    p[1] = 0;
    p[3] = 0;
    if (p[4] >= 0) {
        t = g_Game_80140E1C.f_8220 + p[4];
        e = g_Game_80140E1C.f_820C + t->f[2] * 0x38;
        p[8] = M2C_FIELD(e, s16 *, 0x24);
        p[9] = M2C_FIELD(e, s16 *, 0x26);
        x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 0x740) / 256;
        p[10] = x - 0x3A0;
        if (p[10] < 0) {
            p[10] = x - 0x520;
        } else {
            p[10] = x - 0x220;
        }
        p[10] += 0x80;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80140F24;
typedef struct { s16 x, y, z, w, f_8, f_A, f_C, f_E; u8 pad10[0x14]; s16 hx, hy, hz; } Plat_80140F24;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80140F24 *f_8220; } g_Game_80140F24 asm("g_Game");
extern u8 *D_800B4D64_80140F24 asm("g_StageMeshes");
extern struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x28]; s16 f_58; } g_Spike_80140F24 asm("g_Spike");
extern struct { u8 pad_0[0x24]; s32 x, y, z; u8 pad_30[0x28]; s16 f_58; } g_RcCar_80140F24 asm("g_RcCar");
void Sound_PlayAt_80140F24(s32, void *) asm("Sound_PlayAt");

s32 func_80140F24(s16 *p) {
    Plat_80140F24 *e = (Plat_80140F24 *)(g_Game_80140F24.f_820C + p[2] * 0x38);
    Plat_80140F24 *t;
    S18_80140F24 *s;
    s32 ox;
    s32 oz;
    s32 x;
    s32 h;

    switch (p[1]) {
    case 0:
        p[3] += p[6];
        e->x = e->hx - p[3];
        e->z = e->hz - (p[3] * p[10]) / (e->hx - p[8]);
        if (e->f_E >= 0) {
            M2C_FIELD(D_800B4D64_80140F24 + e->f_E * 32, s16 *, 0x10) = e->x;
            M2C_FIELD(D_800B4D64_80140F24 + e->f_E * 32, s16 *, 0x14) = e->z;
        }
        if (p[4] >= 0) {
            s = g_Game_80140F24.f_8220 + p[4];
            t = (Plat_80140F24 *)(g_Game_80140F24.f_820C + s->f[2] * 0x38);
            if (e->z + e->f_A > t->z - t->f_A && e->z - e->f_A < t->z + t->f_A && e->x - t->x < e->w + t->w) {
                h = t->f_A / 2;
                if (((e->z - t->z) < 0 ? -(e->z - t->z) : (e->z - t->z)) < h) {
                    p[10] = (e->hz - e->z) / ((e->hx - t->x) / p[7]);
                    p[11] = p[7];
                    p[1] = 1;
                } else {
                    p[11] = p[6];
                    if (e->z < t->z) {
                        p[10] = -p[6];
                    } else {
                        p[10] = p[6];
                    }
                    p[1] = 2;
                }
                Sound_PlayAt_80140F24(0xB6, e);
                p[3] = 0;
                break;
            }
        }
        if (e->x < p[8]) {
            p[3] = 0;
            x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 0x740) / 256;
            p[10] = x - 0x3A0;
            if (p[10] < 0) {
                p[10] = x - 0x520;
            } else {
                p[10] = x - 0x220;
            }
            p[10] += 0x80;
            Sound_PlayAt_80140F24(0xB5, &e->hx);
        }
        break;
    case 1:
        if (++p[3] >= 0x1F) {
            p[1] = 2;
            p[3] = 0;
        }
        break;
    case 2:
        ox = e->x;
        oz = e->z;
        e->x += p[11];
        e->z += p[10];
        if (e->f_E >= 0) {
            M2C_FIELD(D_800B4D64_80140F24 + e->f_E * 32, s16 *, 0x10) = e->x;
            M2C_FIELD(D_800B4D64_80140F24 + e->f_E * 32, s16 *, 0x14) = e->z;
        }
        if (g_Spike_80140F24.f_58 == p[2]) {
            g_Spike_80140F24.x += e->x - ox;
            g_Spike_80140F24.z += e->z - oz;
        }
        if (g_RcCar_80140F24.f_58 == p[2]) {
            g_RcCar_80140F24.x += e->x - ox;
            g_RcCar_80140F24.z += e->z - oz;
        }
        if (e->x > e->hx) {
            p[3] = 0;
            x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 0x740) / 256;
            p[10] = x - 0x3A0;
            if (p[10] < 0) {
                p[10] = x - 0x520;
            } else {
                p[10] = x - 0x220;
            }
            p[1] = 0;
            p[10] += 0x80;
            Sound_PlayAt_80140F24(0xB5, &e->hx);
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; struct S18_8014143C { s16 f[12]; } *f_8220; } g_Game_8014143C asm("g_Game");
extern u8 *D_800B4D64_8014143C asm("g_StageMeshes");
void Matrix_SetScale(s16 *, void *);

s32 func_8014143C(s16 *p) {
    u8 *e = g_Game_8014143C.f_820C + p[2] * 0x38;
    s16 v[3];
    struct S18_8014143C *t;

    p[1] = 0;
    p[3] = 0;
    p[9] = p[6];
    p[10] = M2C_FIELD(e, s16 *, 0xA);
    p[11] = -1;
    if (p[4] >= 0) {
        t = g_Game_8014143C.f_8220 + p[4];
        t->f[3] = p[5];
    }
    if (M2C_FIELD(e, s16 *, 0xE) > 0) {
        v[1] = 0x1000;
        v[0] = 0x1000;
        v[2] = p[9];
        Matrix_SetScale(v, M2C_FIELD(D_800B4D64_8014143C + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
        M2C_FIELD(e, s16 *, 0xA) = (p[10] * p[9]) / 4096;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; struct S18_8014153C { s16 f[12]; } *f_8220; } g_Game_8014153C asm("g_Game");
extern u8 *D_800B4D64_8014153C asm("g_StageMeshes");
s32 Sound_Stop(s32, s32);
s32 Sound_UpdateVoice3D();

s32 func_8014153C(s16 *p) {
    u8 *e = g_Game_8014153C.f_820C + p[2] * 0x38;
    s16 v[3];
    s32 lvl = 0;
    struct S18_8014153C *t;

    if (p[4] >= 0) {
        t = g_Game_8014153C.f_8220 + p[4];
        lvl = t->f[11];
    }
    switch (p[1]) {
    case 0:
        if (lvl < p[9]) {
            p[1] = 2;
        } else {
            p[9] = lvl;
            if (lvl >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[8];
            }
        }
        break;
    case 1:
        if (--p[3] < 0) {
            p[1] = 2;
        }
        break;
    case 2:
        p[9] -= p[7];
        if (p[9] < lvl) {
            p[9] = lvl;
            if (lvl >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            } else {
                p[1] = 0;
            }
        } else if (p[9] < p[6]) {
            p[9] = p[6];
            p[1] = 0;
        }
        break;
    }
    if (p[9] > p[6]) {
        if (p[11] < 0) {
            p[11] = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, p[11], 0x1800, (s32)e);
        }
    } else if (p[11] >= 0) {
        Sound_Stop(0x7F, p[11]);
        p[11] = -1;
    }
    if (M2C_FIELD(e, s16 *, 0xE) > 0) {
        v[1] = 0x1000;
        v[0] = 0x1000;
        v[2] = p[9];
        Matrix_SetScale(v, M2C_FIELD(D_800B4D64_8014153C + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
        M2C_FIELD(e, s16 *, 0xA) = (p[10] * p[9]) / 4096;
    }
    return 0;
}

extern struct { u8 pad0[0x20C]; u8 *f_20C; } D_800F4350;

s32 func_80141790(u8 *a) {
    s16 ids[8];
    s16 i;
    s16 n;
    s16 id;
    u8 *e;
    u8 *tbl;

    ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
    ids[1] = M2C_FIELD(a, u8 *, 0xC);
    ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
    ids[3] = M2C_FIELD(a, u8 *, 0xE);
    ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
    ids[5] = M2C_FIELD(a, u8 *, 0x10);
    ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
    ids[7] = M2C_FIELD(a, u8 *, 0x12);
    tbl = g_StageMeshes;
    n = i = 0;
    for (; i < 8; i++) {
        id = ids[i];
        if (id >= 0 && id != 0xFF) {
            e = D_800F4350.f_20C + id * 0x38;
            n++;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            M2C_FIELD(e, s16 *, 0xE) += i;
            M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    M2C_FIELD(a, s16 *, 0x14) = M2C_FIELD(a, s16 *, 0xA) / n;
    M2C_FIELD(a, s16 *, 0x2) = 0;
    M2C_FIELD(a, s16 *, 0x6) = 0;
    return 0;
}

extern struct S_g_Game_801409C8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game_801409C8 asm("g_Game");

s32 func_801418DC(u8 *a) {
    s16 ids[8];
    s16 t;
    s32 r;
    s32 d;
    u8 *e;

    t = ++M2C_FIELD(a, s16 *, 0x6);
    if (t < M2C_FIELD(a, s16 *, 0xA) * 2) {
        if (t < (M2C_FIELD(a, s16 *, 0x14) / 2) * 2) {
            return 0;
        }
        ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
        ids[1] = M2C_FIELD(a, u8 *, 0xC);
        ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
        ids[3] = M2C_FIELD(a, u8 *, 0xE);
        ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
        ids[5] = M2C_FIELD(a, u8 *, 0x10);
        ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
        ids[7] = M2C_FIELD(a, u8 *, 0x12);
        r = M2C_FIELD(a, s16 *, 0x6) - (M2C_FIELD(a, s16 *, 0x14) / 2) * 2;
        d = M2C_FIELD(a, s16 *, 0x14) * 2;
        if (r % d != 0) {
            return 0;
        }
        e = g_Game_801409C8.f_820C + ids[r / d] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        M2C_FIELD(g_StageMeshes + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80141A6C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80141A6C *f_8220; } g_Game_80141A6C asm("g_Game");
extern u8 *D_800B4D64_80141A6C asm("g_StageMeshes");

s32 func_80141A6C(s16 *p) {
    u8 *e = g_Game_80141A6C.f_820C + p[2] * 0x38;
    s32 v;
    S18_80141A6C *t;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_80141A6C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    p[3] = 0;
    if (p[5] >= 0) {
        t = g_Game_80141A6C.f_8220 + p[5];
        v = t->f[1];
        if (v == 1) {
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_80141A6C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            p[1] = v;
            return 0;
        }
    }
    p[1] = 0;
    p[11] = -1;
    return 0;
}

typedef struct { s16 f[12]; } S18_80141B4C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80141B4C *f_8220; } g_Game_80141B4C asm("g_Game");
extern u8 *D_800B4D64_80141B4C asm("g_StageMeshes");
s32 Sound_PlayAt_80141B4C(s32, void *) asm("Sound_PlayAt");

s32 func_80141B4C(s16 *p) {
    u8 *e = g_Game_80141B4C.f_820C + p[2] * 0x38;
    S18_80141B4C *t;
    s32 v;

    switch (p[1]) {
    case 0:
        if (p[5] >= 0) {
            t = g_Game_80141B4C.f_8220 + p[5];
            v = t->f[1];
            if (v == 1) {
                if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                    M2C_FIELD(D_800B4D64_80141B4C + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
                }
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
                p[1] = v;
            }
        }
        break;
    case 1:
        if (M2C_FIELD(e, s16 *, 0x32) == p[7]) {
            Sound_PlayAt_80141B4C(0x9B, e);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_80141C3C(s16 *p) {
    u8 *e = g_Game.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 0x8);
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(g_StageMeshes + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
    }
    p[7] = -1;
    p[1] = 0;
    p[3] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80141CB4 asm("g_Game");
extern struct { u8 pad_0[0x28]; s32 y; u8 pad_2C[0x2C]; s16 f_58; } g_Spike_80141CB4 asm("g_Spike");
extern u8 *D_800B4D64_80141CB4 asm("g_StageMeshes");
extern s16 g_SpikeStandObj;
s32 Sound_PlayFixed(s32);
void Camera_Translate(s32, s32, s32);

s32 func_80141CB4(s16 *p) {
    u8 *e = g_Game_80141CB4.f_820C + p[2] * 0x38;
    s16 v[3];

    switch (p[1]) {
    case 0:
        if (g_SpikeStandObj == p[2] && p[3] == 0) {
            p[1] = 1;
            p[3] = 0;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_80141CB4 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            p[7] = Sound_Play(0, 0xB1);
        } else if (g_SpikeStandObj < 0 && p[3] != 0) {
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[9] > p[4]) {
            p[1] = 2;
            p[11] = 0;
            p[9] = p[4];
        }
        break;
    case 2:
        if (++p[11] > p[6]) {
            p[1] = 3;
            p[11] = 0;
            Sound_PlayFixed(0xB2);
        }
        break;
    case 3:
        if (--p[9] < 0) {
            p[1] = 0;
            p[9] = 0;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_80141CB4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
            p[3] = g_SpikeStandObj == p[2];
        }
        break;
    }
    M2C_FIELD(e, s16 *, 0x8) = M2C_FIELD(e, u16 *, 0x26) + p[5] * p[9] / p[4];
    if (g_Spike_80141CB4.f_58 == p[2]) {
        g_Spike_80141CB4.y += p[10] - M2C_FIELD(e, s16 *, 0x8);
        Camera_Translate(0, (s16)(p[10] - M2C_FIELD(e, u16 *, 0x8)), 0);
    }
    p[10] = M2C_FIELD(e, s16 *, 0x8);
    v[2] = 0x1000;
    v[0] = 0x1000;
    v[1] = (p[9] << 12) / p[4];
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        Matrix_SetScale(v, M2C_FIELD(D_800B4D64_80141CB4 + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
    }
    return 0;
}

extern struct S_g_Game_80141FCC { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141FCC asm("g_Game");

s32 func_80141FCC(s16 *p) {
    u8 *e = g_Game_80141FCC.f_820C + p[2] * 0x38;
    u8 *f = g_Game_80141FCC.f_8220 + p[4] * 0x18;
    s32 v = M2C_FIELD(f, s16 *, 2);

    if (v == 1) {
        p[1] = v;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
    } else {
        p[1] = 0;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    }
    p[3] = 0;
    return 0;
}

typedef struct { s16 f[12]; } S18_8014205C;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_8014205C *f_8220; } g_Game_8014205C asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_8014205C(s16 *p) {
    u8 *e = g_Game_8014205C.f_820C + p[2] * 0x38;
    S18_8014205C *t;
    s32 v;

    switch (p[1]) {
    case 0:
        t = g_Game_8014205C.f_8220 + p[4];
        v = t->f[1];
        if (v == 1) {
            p[1] = v;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            CamFlyby_StartSegment(0);
            g_Game_8014205C.f_8100 = 7;
        }
        break;
    case 1:
        if (M2C_FIELD(e, s16 *, 0x32) >= p[6] * 2) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_80142154(void *arg0) {
    s16 temp_a1;
    void *temp_a0;

    temp_a0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a0, u16 *, 0x34) = (u16) M2C_FIELD(temp_a0, u16 *, 8);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (M2C_FIELD(arg0, s16 *, 0x14) != 0) {
        temp_a1 = M2C_FIELD(temp_a0, s16 *, 0xE);
        if (temp_a1 >= 0) {
            M2C_FIELD(((temp_a1 << 5) + g_StageMeshes), s16 *, 0x16) = 0;
        }
        M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x18) | 0x8000);
        M2C_FIELD(arg0, s16 *, 2) = 2;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_801421E4;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_801421E4 *f_8220; } g_Game_801421E4 asm("g_Game");
extern u8 *D_800B4D64_801421E4 asm("g_StageMeshes");
s32 Sound_PlayFixed(s32);

s32 func_801421E4(s16 *p) {
    u8 *e = g_Game_801421E4.f_820C + p[2] * 0x38;
    S18_801421E4 *t;
    SVECTOR sv;

    switch (p[1]) {
    case 0:
        if (p[4] >= 0) {
            t = g_Game_801421E4.f_8220 + p[4];
            if (t->f[1] == 1) {
                p[1] = 1;
                p[3] = 0;
                Sound_PlayFixed(0xAA);
                CamFlyby_StartSegment(0);
                g_Game_801421E4.f_8100 = 7;
            }
        }
        break;
    case 1:
        if (++p[3] >= p[6]) {
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_801421E4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
            }
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            p[1] = 2;
        } else {
            sv.vz = 0x1000;
            sv.vx = 0x1000;
            sv.vy = ((p[6] - p[3]) << 12) / p[6];
            M2C_FIELD(e, s16 *, 8) = (M2C_FIELD(e, s16 *, 0x34) * (p[6] - p[3])) / p[6];
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                Matrix_SetScale(&sv.vx, M2C_FIELD(D_800B4D64_801421E4 + M2C_FIELD(e, s16 *, 0xE) * 32, void **, 0x1C));
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_801423C8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801423C8 asm("g_Game");
extern s16 D_800AFA22;

s32 func_801423C8(s16 *p) {
    u8 *e = g_Game_801423C8.f_8220 + p[4] * 0x18;
    s32 v = M2C_FIELD(e, s16 *, 2);

    if (v == 1) {
        p[1] = v;
        D_800AFA22 = v;
    } else {
        p[1] = 0;
        D_800AFA22 = 0;
    }
    p[3] = 0;
    return 0;
}

extern struct S_g_Game_80142424 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80142424 asm("g_Game");

s32 func_80142424(s16 *p) {
    u8 *e;
    s32 v;

    if (p[1] == 0) {
        e = g_Game_80142424.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            p[1] = v;
            D_800AFA22 = v;
        }
    }
    return 0;
}

s16 Sound_Play(s32, s32);

s32 func_8014247C(s16 *p) {
    s32 v = D_800AFA22;
    u8 *e;

    if (v == 1) {
        p[1] = v;
        e = g_Game.f_820C + p[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    } else {
        p[1] = 0;
        p[11] = Sound_Play(1, 0x66);
    }
    p[3] = 0;
    return 0;
}

typedef struct { s32 x, y, z; u8 pad_C[0xC]; SVECTOR r; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_80142508;
extern struct { u8 f_0; u8 pad_1[0x820B]; u8 *f_820C; } g_Game_80142508 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_80142508 asm("g_Spike");
extern s32 D_800EC204;
extern s32 D_800EC20C;
Shape_80142508 *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 func_80142508(s16 *p) {
    SVECTOR a;
    SVECTOR b;
    SVECTOR c;
    s32 pos[3];
    Shape_80142508 *s;
    s32 i;
    s32 v;
    s32 m;
    s32 h;

    if (p[1] == 0) {
        m = D_800AFA22;
        if (m == 1) {
            u8 *e;
            p[1] = m;
            e = g_Game_80142508.f_820C + p[2] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            Sound_Stop(0x66, p[11]);
        } else {
            for (i = 0; i < 8; i++) {
                b.vx = -0x1400;
                a.vx = -0x1400;
                v = ((i + 1) << 10) / 9;
                h = p[1];
                h = -0x1A00;
                a.vz = h;
                b.vz = -0x1E00;
                b.vy = -0x1800 - v;
                a.vy = -0x1800 - v;
                Fx_DrawLightning(&a, &b, g_Game_80142508.f_0 * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8));
                Fx_DrawLightning(&a, &b, g_Game_80142508.f_0 * ((g_RandSeed = g_RandSeed * 5 + 1) >> 8));
            }
            c.vx = -0x1400;
            c.vy = h;
            c.vz = -0x1C00;
            Sound_UpdateVoice3D(0x66, p[11], 0x1800, &c);
            if ((D_800EC204 + 0x1400 >= 0 ? D_800EC204 + 0x1400 <= 0x80 : -0x1400 - D_800EC204 <= 0x80) && (D_800EC20C + 0x1C00 >= 0 ? D_800EC20C + 0x1C00 <= 0x200 : -0x1C00 - D_800EC20C <= 0x200) && (D_800EC208 + 0x1840 >= 0 ? D_800EC208 + 0x1840 <= 0x400 : -0x1840 - D_800EC208 <= 0x400)) {
                c.vx = -0x1000;
                c.vy = 0;
                c.vz = 0;
                pos[0] = g_Spike_80142508.x + 0x40;
                pos[1] = g_Spike_80142508.y;
                pos[2] = g_Spike_80142508.z;
                s = CollShape_Alloc();
                if (s != NULL) {
                    s->r = c;
                    s->x = pos[0];
                    s->y = pos[1];
                    s->z = pos[2];
                    s->f_20 = 0x80;
                    s->f_24 = 0x401;
                    s->f_26 = 0x202;
                    Collision_Set(6, s, NULL);
                }
            }
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_8014281C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_8014281C *f_8220; } g_Game_8014281C asm("g_Game");
extern u8 *D_800B4D64_8014281C asm("g_StageMeshes");
extern s16 D_800AFA24;

s32 func_8014281C(s16 *p) {
    u8 *e = g_Game_8014281C.f_820C + p[2] * 0x38;
    S18_8014281C *t;
    s32 v;

    M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
    t = g_Game_8014281C.f_8220 + p[4];
    v = t->f[1];
    if (v == 1) {
        p[1] = 3;
        t = g_Game_8014281C.f_8220 + p[8];
        D_800AFA24 = v;
        e = g_Game_8014281C.f_820C + t->f[2] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8014281C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    } else {
        p[1] = 0;
        D_800AFA24 = 0;
    }
    p[3] = 0;
    return 0;
}

typedef struct { s16 f[12]; } S18_80142908;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; S18_80142908 *f_8220; } g_Game_80142908 asm("g_Game");
extern s16 g_SpikeStandObj;
s32 Sound_Stop(s32, s32);
void Spike_SetPlayMode(s32);

s32 func_80142908(s16 *p) {
    u8 *e = g_Game_80142908.f_820C + p[2] * 0x38;
    S18_80142908 *t;

    switch (p[1]) {
    case 0:
        t = g_Game_80142908.f_8220 + p[4];
        if (t->f[1] == 1) {
            p[1] = 1;
            p[3] = 0;
            D_800AFA24 = 1;
            CamFlyby_StartSegment(0);
            Link_Activate(p[6], p);
            p[11] = Sound_Play(0, 0xC0);
            g_Game_80142908.f_8100 = 7;
        }
        break;
    case 1:
        if (p[5] < ++p[3]) {
            p[1] = 3;
            p[3] = 0;
            Sound_Stop(0xC0, p[11]);
        }
        break;
    case 3:
        if (g_SpikeStandObj == p[2]) {
            p[1] = 4;
            p[3] = 0;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            Sound_PlayFixed(0x9C);
            Spike_SetPlayMode(0xB);
            g_Game_80142908.f_8100 = 0;
        }
        break;
    case 2:
    case 4:
        if (++p[3] >= p[7]) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 8 bytes */
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xE4]; u8 *f_820C; } g_Game_80142ACC asm("g_Game");
extern u8 *D_800B4D64_80142ACC asm("g_StageMeshes");
extern s16 D_800AFA24;

s32 func_80142ACC(s16 *p) {
    s16 flag;
    u8 *e;

    if (g_Game_80142ACC.f_8126 == 0x50) {
        flag = D_800AFA24;
    } else {
        flag = SaveByte_Get(0xD) == 5;
    }
    e = g_Game_80142ACC.f_820C + p[2] * 0x38;
    if (p[4] == 0) {
        if (flag == 1) {
            return 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80142ACC + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    } else if (p[4] == 1) {
        if (flag == 0) {
            return 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80142ACC + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    } else {
        if (flag != 1) {
            return 0;
        }
        if (p[5] == 0) {
            return 0;
        }
        M2C_FIELD(e, s16 *, 0) += p[5];
        M2C_FIELD(D_800B4D64_80142ACC + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x10) += p[5];
    }
    return 0;
}

extern struct S_g_Game_801426B4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801426B4 asm("g_Game");

s32 func_80142C10(s16 *p) {
    u8 *e = g_Game_801426B4.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        Link_Activate(p[7], p);
        Link_Activate(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x4C]; u16 f_8150; u8 pad_8152[0xCE]; struct S18_80142C9C { s16 f[12]; } *f_8220; } g_Game_80142C9C asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_80142C9C(s16 *p) {
    struct S18_80142C9C *t;

    switch (p[1]) {
    case 0:
        t = g_Game_80142C9C.f_8220 + p[4];
        if (t->f[11] > p[5]) {
            if (g_Game_80142C9C.f_8150 == 8) {
                p[1] = 1;
            }
        }
        break;
    case 1:
        if (g_Game_80142C9C.f_8150 == 0) {
            Link_Activate(p[7], p);
            Link_Activate(p[8], p);
            if (p[6] > 0) {
                CamFlyby_StartSegment(p[6] - 1);
                g_Game_80142C9C.f_8100 = 7;
            }
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80142D9C;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_80142D9C *f_8220; } g_Game_80142D9C asm("g_Game");

s32 func_80142D9C(s16 *p) {
    S18_80142D9C *t = g_Game_80142D9C.f_8220 + p[4];
    u8 *e;

    if (t->f[1] == 1 || SaveByte_Get(0xD) == 5) {
        p[1] = 2;
        t = g_Game_80142D9C.f_8220 + p[6];
        t->f[1] = 0;
    } else {
        p[1] = 0;
        t = g_Game_80142D9C.f_8220 + p[6];
        t->f[1] = 3;
    }
    e = g_Game_80142D9C.f_820C + t->f[2] * 0x38;
    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    p[3] = -1;
    return 0;
}

extern struct S_g_Game_80142EA0 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_80142EA0 asm("g_Game");
extern s32 D_800EC204;
void CamFlyby_StartSegment(s32);

s32 func_80142EA0(s16 *p) {
    u8 *e;

    if (p[1] == 0 && D_800EC204 > 0) {
        p[1] = 2;
        p[3] = 0;
        if (p[5] > 0) {
            CamFlyby_StartSegment(p[5] - 1);
            g_Game_80142EA0.f_8100 = 5;
        }
        e = g_Game_80142EA0.f_8220 + p[6] * 0x18;
        M2C_FIELD(e, s16 *, 2) = 0;
    }
    return 0;
}

s32 func_80142F40(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    if (SaveByte_Get(0xD) == 5) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 3;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; } g_Game_80142FB8 asm("g_Game");
extern s16 g_SpikeStandObj;

s32 func_80142FB8(s16 *p) {
    u8 *e;

    if (SaveByte_Get(3) == 5) {
        return 0;
    }
    e = g_Game_80142FB8.f_820C + p[2] * 0x38;
    switch (p[1]) {
    case 0:
        if (g_SpikeStandObj == p[2]) {
            p[1] = 1;
            p[3] = 0;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            Spike_SetPlayMode(0xB);
            g_Game_80142FB8.f_8100 = 0;
        }
        break;
    case 1:
        if (++p[3] >= p[4]) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801430B0 asm("g_Game");
extern u8 *D_800B4D64_801430B0 asm("g_StageMeshes");

s32 func_801430B0(s16 *p) {
    u8 *e = g_Game_801430B0.f_820C + p[2] * 0x38;
    u8 *t;

    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    t = g_Game_801430B0.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(t, s16 *, 2) == 1) {
        p[1] = 2;
    } else {
        p[1] = 0;
        p[11] = Sound_Play(1, 0x66);
    }
    p[3] = 0;
    return 0;
}

typedef struct { s16 x, y, z, w, h, d; } Box_80143158;
typedef struct { s16 f[12]; } S18_80143158;
typedef struct { SVECTOR rot; s32 x, y, z; } Coll_80143158;
extern struct { u8 f_0; u8 pad_1[0x80FF]; s32 f_8100; u8 pad_8104[0x108]; Box_80143158 *f_820C; u8 pad_8210[0x10]; S18_80143158 *f_8220; } g_Game_80143158 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x, y, z; } g_Spike_80143158 asm("g_Spike");
extern s32 D_800EC20C;
void *CollShape_Alloc_80143158(void) asm("CollShape_Alloc");
s32 Collision_Set_80143158(s32, void *, void *) asm("Collision_Set");

s32 func_80143158(s16 *p) {
    SVECTOR a;
    SVECTOR b;
    Coll_80143158 c;
    Box_80143158 *e;
    u8 *s;
    s32 i;
    S18_80143158 *t;

    e = (Box_80143158 *)((u8 *)g_Game_80143158.f_820C + p[2] * 0x38);
    switch (p[1]) {
    case 0:
        t = g_Game_80143158.f_8220 + p[4];
        if (t->f[1] == 1) {
            p[1] = 1;
            p[3] = 0;
            CamFlyby_StartSegment(0);
            g_Game_80143158.f_8100 = 7;
            Sound_Stop(0x66, p[11]);
        }
        a.vz = b.vz = e->z;
        a.vy = b.vy = e->y - e->h + 0x80;
        a.vx = (s16)(e->x - 0xC0) + e->w;
        b.vx = (s16)(e->x + 0xC0) - e->w;
        Fx_DrawLightning(&a, &b, g_Game_80143158.f_0 * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        Fx_DrawLightning(&a, &b, g_Game_80143158.f_0 * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        c.rot.vx = e->x;
        c.rot.vy = e->y - e->h + 0x80;
        c.rot.vz = e->z;
        Sound_UpdateVoice3D(0x66, p[11], 0x1800, &c);
        if (((D_800EC204 - e->x) < 0 ? -(D_800EC204 - e->x) : (D_800EC204 - e->x)) <= e->w) {
            if (((D_800EC20C - e->z) < 0 ? -(D_800EC20C - e->z) : (D_800EC20C - e->z)) <= e->d) {
                c.rot.vy = 0;
                c.rot.vx = 0;
                c.rot.vz = -0x1000;
                c.x = g_Spike_80143158.x;
                c.y = g_Spike_80143158.y;
                c.z = g_Spike_80143158.z + 0x40;
                s = CollShape_Alloc_80143158();
                if (s != NULL) {
                    *(SVECTOR *)(s + 0x18) = c.rot;
                    *(s32 *)(s + 0) = c.x;
                    *(s32 *)(s + 4) = c.y;
                    *(s32 *)(s + 8) = c.z;
                    *(s16 *)(s + 0x20) = 0x80;
                    *(s16 *)(s + 0x24) = 0x401;
                    *(s16 *)(s + 0x26) = 0x202;
                    Collision_Set_80143158(6, s, 0);
                }
            }
        }
        break;
    case 1:
        if (++p[3] >= 0x49) {
            p[3] = 0;
            p[1] = 2;
            break;
        }
        if ((s16)(p[3] % 9) == 0) {
            Sound_PlayFixed(0x75);
        }
        for (i = 0; i < 8 - (s16)(p[3] / 9); i++) {
            a.vx = b.vx = 0x800;
            a.vz = -0x600;
            b.vz = -0xA00;
            a.vy = b.vy = -0x5A00 - ((i + 1) * 0x400) / 9;
            Fx_DrawLightning(&a, &b, g_Game_80143158.f_0 * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
            Fx_DrawLightning(&a, &b, g_Game_80143158.f_0 * ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8));
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_80143600 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143600 asm("g_Game");
extern u8 *D_800B4D64_80143600 asm("g_StageMeshes");
s32 SaveByte_Get_80143600(s32) asm("SaveByte_Get");
void Model_BindStageMesh(void *, s32);

s32 func_80143600(s16 *p) {
    u8 *e = g_Game_80143600.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 2) == 1 || SaveByte_Get_80143600(0xD) == 5) {
        p[1] = 2;
        Model_BindStageMesh(D_800B4D64_80143600 + p[6] * 32, p[7]);
    } else {
        p[1] = 0;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_8014369C;
extern struct { u8 pad_0[0x8220]; S18_8014369C *f_8220; } g_Game_8014369C asm("g_Game");
extern u8 *D_800B4D64_8014369C asm("g_StageMeshes");
void Music_Play(void);
s32 Sound_SetVoiceVolumeRatio(s32, s16, s16, s16);

s32 func_8014369C(s16 *p) {
    S18_8014369C *t;
    s32 v;
    s32 w;

    switch (p[1]) {
    case 0:
        t = g_Game_8014369C.f_8220 + p[4];
        v = t->f[1];
        if (v == 1) {
            p[1] = v;
            p[3] = 0x12C;
            Model_BindStageMesh(D_800B4D64_8014369C + p[6] * 32, p[7]);
            p[10] = Sound_Play(0, 0xB9);
        }
        break;
    case 1:
        p[3]--;
        w = p[3];
        if (w < 0) {
            Sound_Stop(0xB9, p[10]);
            p[1] = 2;
        } else if (w == 0x5A) {
            Music_Play();
        } else if (w < 0x5A) {
            Sound_SetVoiceVolumeRatio(0xB9, p[10], w, 0x5A);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_801437B4;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_801437B4 *f_8220; } g_Game_801437B4 asm("g_Game");
extern u8 *D_800B4D64_801437B4 asm("g_StageMeshes");
extern s16 D_800AFA24;

s32 func_801437B4(s16 *p) {
    u8 *e;
    S18_801437B4 *t;

    if (p[2] >= 0) {
        e = g_Game_801437B4.f_820C + p[2] * 0x38;
    }
    t = g_Game_801437B4.f_8220 + p[4];
    if (t->f[1] == 1 || D_800AFA24 == 1) {
        p[1] = 1;
        if (p[5] == 0) {
            M2C_FIELD(D_800B4D64_801437B4 + p[6] * 32, s16 *, 0x16) = 0;
            if (p[2] >= 0) {
                M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            }
        } else if (p[5] == 2) {
            Model_BindStageMesh(D_800B4D64_801437B4 + p[6] * 32, p[7]);
        }
    } else {
        p[1] = 0;
        if (p[5] == 1) {
            M2C_FIELD(D_800B4D64_801437B4 + p[6] * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_801438E8;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; S18_801438E8 *f_8220; } g_Game_801438E8 asm("g_Game");
extern u8 *D_800B4D64_801438E8 asm("g_StageMeshes");

s32 func_801438E8(s16 *p) {
    u8 *e;
    S18_801438E8 *t;

    if (p[2] >= 0) {
        e = g_Game_801438E8.f_820C + p[2] * 0x38;
    }
    if (p[1] == 0) {
        t = g_Game_801438E8.f_8220 + p[4];
        if (t->f[1] == 1 || D_800AFA24 == 1) {
            p[1] = 1;
            if (p[5] == 0) {
                M2C_FIELD(D_800B4D64_801438E8 + p[6] * 32, s16 *, 0x16) = 0;
                if (p[2] >= 0) {
                    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
                }
            } else if (p[5] == 2) {
                Model_BindStageMesh(D_800B4D64_801438E8 + p[6] * 32, p[7]);
            } else {
                M2C_FIELD(D_800B4D64_801438E8 + p[6] * 32, u16 *, 0x16) = 0xFFFF;
            }
        }
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80143A1C;
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xF8]; S18_80143A1C *f_8220; } g_Game_80143A1C asm("g_Game");
s32 func_80086418_80143A1C() asm("Music_GetPlayingSeq");
void Music_Play(void);

s32 func_80143A1C(s16 *p) {
    S18_80143A1C *t;

    if (g_Game_80143A1C.f_8126 != 0x4E) {
        goto play;
    }
    p[4] = -1;
    t = g_Game_80143A1C.f_8220 + p[7];
    if (t->f[1] != 0) {
play:
        p[4] = Sound_Play(1, 0x91);
    }
    if (SaveByte_Get(0xD) == 5) {
        if (func_80086418_80143A1C() < 0) {
            Music_Play();
        }
    } else {
        p[5] = Sound_Play(1, 0xB7);
        p[6] = Sound_Play(1, 0xB8);
    }
    return 0;
}

typedef struct { s16 f[12]; } S18_80143AEC;
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xF8]; S18_80143AEC *f_8220; } g_Game_80143AEC asm("g_Game");
void func_800A3570(s32, s32, s32);

s32 func_80143AEC(s16 *p) {
    SVECTOR v;
    S18_80143AEC *t;

    if (g_Game_80143AEC.f_8126 == 0x4E) {
        t = g_Game_80143AEC.f_8220 + p[7];
        if (t->f[1] != 0) {
            if (p[4] < 0) {
                p[4] = Sound_Play(1, 0x91);
            } else {
                v.vy = -0x140;
                v.vx = 0;
                v.vz = 0xE00;
                Sound_UpdateVoice3D(0x91, p[4], 0x1800, (s32)&v);
            }
        }
    } else {
        v.vy = -0x2048;
        v.vx = 0;
        v.vz = -0x2600;
        Sound_UpdateVoice3D(0x91, p[4], 0x1800, (s32)&v);
    }
    if (SaveByte_Get(0xD) != 5) {
        func_800A3570(p[5], 0x1000, 0x1000);
        func_800A3570(p[6], 0x1000, 0x1000);
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80143BE4 asm("g_Game");
extern u8 *D_800B4D64_80143BE4 asm("g_StageMeshes");

s32 func_80143BE4(s16 *p) {
    u8 *e = g_Game_80143BE4.f_820C + p[2] * 0x38;
    s32 v;

    M2C_FIELD(e, u16 *, 0x24) = M2C_FIELD(e, u16 *, 0);
    M2C_FIELD(e, u16 *, 0x26) = M2C_FIELD(e, u16 *, 2);
    M2C_FIELD(e, u16 *, 0x28) = M2C_FIELD(e, u16 *, 4);
    v = p[5];
    if (v == 4) {
        p[1] = v;
        p[3] = 0;
    } else {
        p[1] = 1;
        p[3] = M2C_FIELD(e, u16 *, 8);
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80143BE4 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x12) -= M2C_FIELD(e, u16 *, 8);
        }
        M2C_FIELD(e, u16 *, 2) -= M2C_FIELD(e, u16 *, 8);
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_80143BE4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

extern struct S_g_Game_80143CB8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143CB8 asm("g_Game");

s32 func_80143CB8(s16 *p) {
    u8 *e;

    e = g_Game_80143CB8.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 1;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct S_g_Game_80143D08 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; u8 *f_8220; } g_Game_80143D08 asm("g_Game");
void CamFlyby_StartSegment(s32);

s32 func_80143D08(s16 *p) {
    u8 *e;
    s32 v;

    if (p[1] == 0) {
        e = g_Game_80143D08.f_8220 + p[4] * 0x18;
        v = M2C_FIELD(e, s16 *, 2);
        if (v == 1) {
            p[1] = v;
            CamFlyby_StartSegment(0);
            g_Game_80143D08.f_8100 = 7;
        }
    }
    return 0;
}

s32 func_80143D80(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

extern struct S_g_Game_80143D94 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143D94 asm("g_Game");

s32 func_80143D94(s16 *p) {
    u8 *e;

    if (p[1] == 0) {
        e = g_Game_80143D94.f_8220 + p[6] * 0x18;
        if (M2C_FIELD(e, s16 *, 2) == 1) {
            p[1] = 5;
        }
    }
    return 0;
}

s32 func_80143DE8(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    p[1] = 0;
    p[3] = 0;
    p[8] = e[0];
    p[9] = e[1];
    p[10] = e[2];
    p[11] = -1;
    e[0x13] = e[1];
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80143E54 asm("g_Game");
extern u8 *D_800B4D64_80143E54 asm("g_StageMeshes");
s32 Sound_Stop(s32, s32);
s32 Sound_PlayAt(s32, s32);
s32 Link_MoveChainWith(s16, s16 *, s16 *);

s32 func_80143E54(s16 *p) {
    s16 *e = (s16 *)(g_Game_80143E54.f_820C + p[2] * 0x38);

    switch (p[1]) {
    case 0:
        break;
    case 1:
        e[1] -= p[6];
        if (e[1] < e[0x13] + p[5]) {
            e[1] = e[0x13] + p[5];
            if (p[11] >= 0) {
                Sound_PlayAt(0xC1, (s32)e);
                Sound_Stop(0xBF, p[11]);
                p[11] = -1;
            }
        } else if (p[11] < 0) {
            p[11] = Sound_Play(0, 0xC1);
        }
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_80143E54 + e[7] * 32, s16 *, 0x12) = e[1];
        }
        if (p[4] >= 0) {
            Link_MoveChainWith(p[4], e, p + 8);
        }
        break;
    case 2:
        e[1] += p[7];
        if (e[0x13] < e[1]) {
            e[1] = e[0x13];
            if (p[11] >= 0) {
                Sound_PlayAt(0xC1, (s32)e);
                Sound_Stop(0xBF, p[11]);
                p[11] = -1;
            }
        } else if (p[11] < 0) {
            p[11] = Sound_Play(0, 0xC1);
        }
        if (e[7] >= 0) {
            M2C_FIELD(D_800B4D64_80143E54 + e[7] * 32, s16 *, 0x12) = e[1];
        }
        if (p[4] >= 0) {
            Link_MoveChainWith(p[4], e, p + 8);
        }
        break;
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
