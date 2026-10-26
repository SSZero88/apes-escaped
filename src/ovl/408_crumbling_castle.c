#include "common.h"
#include "m2c_macros.h"

s32 func_800569C4(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Objects;
M2C_UNK Object_TurnToward(void *, s16, s16, M2C_UNK, s32);
M2C_UNK func_80052864(void *);
s32 Object_SpikeInFront(void *, s32, s32, s16);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
M2C_UNK VectorNormalSS(void *, void *);

M2C_UNK func_80051E98(void *, M2C_UNK);
M2C_UNK func_80088120(s8);
void Object_SpawnEffect(void *, s16, s32, s32, s32);
M2C_UNK Object_CameraShake(void *, M2C_UNK);

s32 SaveByte_Get(M2C_UNK);
M2C_UNK Effect_SpawnAt(M2C_UNK, s32);
M2C_UNK Link_SendEvent(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Object_DisableCollision(void *);
M2C_UNK Object_DropPickups(void *);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK Object_ApplyVelocity(void *);
M2C_UNK Object_HeadTowardSpike(void *, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s32);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
M2C_UNK Object_PlaySound(void *, M2C_UNK);
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_800573A0(void *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801401D4(void *arg0);
extern s32 D_80145D24;
extern M2C_UNK D_80145D30;
s32 Spike_WithinRadiusXZ(s16, s16, s16);
s32 func_8013D118(void);
void func_80140530(void *arg0);
extern s32 D_80145D20;
M2C_UNK Puff_Spawn(void *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_80145D40;
extern struct S_D_800E77A0 { u8 pad_0[0x1]; u8 f_1; } D_800E77A0;
M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16, s32);
s16 Sound_Play(M2C_UNK, M2C_UNK);

void func_8013D000(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = func_800569C4(0x64, 1);
    if (temp_v0 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0 * 0xE4)), 0);
    }
    temp_v0_2 = func_800569C4(0x65, 1);
    if (temp_v0_2 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0_2 * 0xE4)), 0);
    }
    temp_v0_3 = func_800569C4(0x51, 1);
    if (temp_v0_3 != -1) {
        func_80051E98((void *)((u8 *)&g_Objects + (temp_v0_3 * 0xE4)), 0);
    }
}

s32 func_8005BB5C(s32);

s32 func_8013D0C8(void) {
    s32 r;

    r = 0;
    if (SaveByte_Get(1) >= 2 || func_8005BB5C(1) >= 2) {
        r = 1;
    }
    return r;
}

s32 func_8013D118(void) {
    return SaveByte_Get(1) == 5;
}

typedef struct { u8 pad0[0x10]; s8 f; s8 g; s8 h; s8 k; } Slot_8013D13C;
typedef struct { u8 pad[0xE4]; } Obj_8013D13C;
extern Obj_8013D13C g_Objects_8013D13C[] asm("g_Objects");
extern s16 D_800E77E0;
extern s32 D_80144F30;
extern Slot_8013D13C *D_80144F34_8013D13C asm("D_80144F34");
s32 Hook_Add(void *);
void func_8013DAFC(void);

void func_8013D13C(void) {
    s32 i;

    D_80144F34_8013D13C = (Slot_8013D13C *)&g_Objects_8013D13C[D_800E77E0];
    D_80144F30 = (16 - D_800E77E0) * sizeof(Obj_8013D13C) / sizeof(Slot_8013D13C);
    if (D_80144F30 > 32) {
        D_80144F30 = 32;
    }
    for (i = D_80144F30 - 1; i >= 0; i--) {
        D_80144F34_8013D13C[i].f = 0;
        D_80144F34_8013D13C[i].g = 0;
        D_80144F34_8013D13C[i].h = -1;
    }
    Hook_Add(func_8013DAFC);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D230);

typedef struct { u8 pad0[0x10]; s8 f; u8 pad11[3]; } Slot_406;
extern s32 D_80144F30;
extern Slot_406 *D_80144F34;

s32 func_8013D4F8(void) {
    s32 i;

    for (i = 0; i < D_80144F30; i++) {
        if (D_80144F34[i].f == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { u8 b[8]; } B8_8013D54C;
typedef struct { B8_8013D54C a; B8_8013D54C b; s8 f; s8 g; s8 h; s8 k; } Slot_8013D54C;
extern Slot_8013D54C *D_80144F34_8013D54C asm("D_80144F34");
s32 func_8013D4F8(void);

s32 func_8013D54C(s32 kind, s32 h, B8_8013D54C *a, B8_8013D54C *b, s32 g) {
    s32 i = func_8013D4F8();
    Slot_8013D54C *s;

    if (i == -1) {
        return -1;
    }
    s = &D_80144F34_8013D54C[i];
    s->f = 8;
    s->a = *a;
    s->b = *b;
    s->g = g;
    s->h = h;
    s->k = kind;
    if (kind == 2) {
        s->f = 16;
    }
    return i;
}

typedef struct { u8 b[8]; } B8_8013D628;
typedef struct { B8_8013D628 a; B8_8013D628 b; s8 f; s8 g; s8 h; s8 k; } Slot_8013D628;
typedef struct { u8 pad[0x7E]; u8 f7E; u8 pad7F[0x65]; } Obj_8013D628;
extern Obj_8013D628 g_Objects_8013D628[] asm("g_Objects");
extern Slot_8013D628 *D_80144F34_8013D628 asm("D_80144F34");
void func_8013D230(B8_8013D628 *, s32, s32, s32);

void func_8013D628(Slot_8013D628 *s) {
    Slot_8013D628 *t = &D_80144F34_8013D628[s->g];
    B8_8013D628 v[4];
    s32 k;

    if (t->f != 0) {
        k = 4;
        v[0] = s->a;
        v[1] = s->b;
        v[2] = t->a;
        v[3] = t->b;
        if (g_Objects_8013D628[s->h].f7E == 0x3C) {
            k = 8;
        }
        func_8013D230(v, s->f - 1, t->f - 1, k);
    }
}

void func_8013D740(s16 *p) {
    p[0] += p[4];
    p[1] += p[5];
    p[2] += p[6];
    Effect_SpawnAt(0x2B, p);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013D794);

typedef struct { u8 pad0[0x10]; s8 f; s8 g; s8 h; s8 k; } Slot_8013DAFC;
typedef struct { u8 pad[0xE0]; u32 b0 : 2; u32 b2 : 1; u32 rest : 29; } Obj_8013DAFC;
extern Obj_8013DAFC g_Objects_8013DAFC[] asm("g_Objects");
extern Slot_8013DAFC *D_80144F34_8013DAFC asm("D_80144F34");
extern void (*D_80144950[])(Slot_8013DAFC *);

void func_8013DAFC(void) {
    s32 i;
    Slot_8013DAFC *s;

    for (i = 0; i < D_80144F30; i++) {
        s = &D_80144F34_8013DAFC[i];
        if (s->f != 0) {
            if (--s->f != 0) {
                if (!g_Objects_8013DAFC[s->h].b2) {
                    D_80144950[s->k](s);
                }
            }
        }
    }
}

void Effect_Spawn_8013DC04(s32, SVECTOR *, void *, s32) asm("Effect_Spawn");
void Effect_SpawnAt_8013DC04(s32, SVECTOR *) asm("Effect_SpawnAt");
extern u8 D_801449D4[];
extern u16 g_RandSeed;

void func_8013DC04(SVECTOR *p) {
    SVECTOR v;
    s32 i;

    Effect_Spawn_8013DC04(0xC8, p, D_801449D4, 0);
    Effect_SpawnAt_8013DC04(0x2A, p);
    for (i = 0; i < 6; i++) {
        v.vx = p->vx + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        v.vy = p->vy + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        v.vz = p->vz + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        Effect_Spawn_8013DC04(0xC8, &v, D_801449D4, 0);
        Effect_SpawnAt_8013DC04(0x2A, &v);
    }
}

void func_8013DD40(s32 arg0) {
    Effect_SpawnAt(4, arg0);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; s16 f5C; u8 pad5E[2]; SVECTOR rot; u8 pad68[8]; s16 vx, vy, vz, f76; } Chunk_8013DD64;
s32 rcos_8013DD64(s32) asm("rcos");
s32 rsin_8013DD64(s32) asm("rsin");
void func_80052038(void *, s32);
void func_800520A8(void *, s32);
extern s32 D_8014495C_8013DD64[] asm("D_8014495C");
extern Chunk_8013DD64 D_80144F38_8013DD64[] asm("D_80144F38");

M2C_UNK func_8013DD64(void *arg0) {
    s32 i;
    Chunk_8013DD64 *m;
    s32 k;

    for (i = 0; i < 7; i++) {
        m = &D_80144F38_8013DD64[i];
        k = i + 0x79;
        func_80052038(m, k);
        func_800520A8(m, k);
        m->f5C = 0;
        m->rot = ((Chunk_8013DD64 *)arg0)->rot;
        m->x = ((Chunk_8013DD64 *)arg0)->x;
        m->y = ((Chunk_8013DD64 *)arg0)->y;
        m->z = ((Chunk_8013DD64 *)arg0)->z;
        if (k == 0x7B) {
            m->vx = 0;
            m->vz = 0;
        } else {
            m->vx = rcos_8013DD64(D_8014495C_8013DD64[i]) * ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2) >> 12;
            m->vz = rsin_8013DD64(D_8014495C_8013DD64[i]) * ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 2) >> 12;
        }
        m->f76 = 0;
        m->vy = -((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 6 - 0x10;
    }
}

typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[4]; SVECTOR pos; s32 x, y, z; u8 pad30[0x30]; SVECTOR rot; u8 pad68[8]; s16 vx, vy, vz, state; } Chunk_8013DF2C;
extern Chunk_8013DF2C D_80144F38_8013DF2C[] asm("D_80144F38");
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013DF2C asm("g_Game");
extern u8 D_800E7D00_8013DF2C[] asm("D_800E7D00");
void func_80014804_8013DF2C(void *, void *) asm("func_80014804");
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
void func_8013DC04(SVECTOR *p);
void func_8013DD40(s32 arg0);

void func_8013DF2C(u8 *o) {
    s32 i;
    Chunk_8013DF2C *m;
    Chunk_8013DF2C *p;
    SVECTOR v;

    for (i = 0; i < 7; i++) {
        p = &D_80144F38_8013DF2C[i];
        if (p->state != 2) {
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            p->vy += 4;
            m = p;
            if (M2C_FIELD(o, s32 *, 0x28) < p->y) {
                p->y = M2C_FIELD(o, s32 *, 0x28);
                p->state++;
                func_8013DC04(&p->pos);
                if (i % 3 == 0) {
                    Object_PlaySound(o, 0x60);
                }
                p->vx = p->vx / 2;
                p->vy = p->vy / -3;
                p->vz = p->vz / 2;
                v.vx = p->x;
                v.vy = p->y;
                v.vz = p->z;
            }
            if (func_80051410(&m->x, 0, 0) == 0) {
                func_80014804_8013DF2C(&m->rot, m->mat);
                func_80015780(m, 3);
                Model_ProjectBonedVerts(m);
                func_80016EBC(g_Game_8013DF2C.f_80 + g_Game_8013DF2C.f_C * 0x4078, D_800E7D00_8013DF2C, m);
                func_8013DD40((s32)&m->pos);
            }
        }
    }
}

void func_8013E134(void) {
    Link_SendEvent(8, 6, 0);
}

void func_8013E15C(void *arg0) {
    Object_PlaySound(arg0, 0x60);
}

void func_8013E17C(void *arg0) {
    func_8013E15C(arg0);
    M2C_FIELD(arg0, s8 *, 0x80) = 0xD;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0;
    func_8005588C(arg0, 0x5A);
    func_8013DD64(arg0);
    Object_DropPickups(arg0);
    Object_DisableCollision(arg0);
}

void func_8013E1D0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

void func_8013E1F4(void *arg0, s32 arg1) {
    u32 temp_s1;

    temp_s1 = (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C;
    if (temp_s1 == 0xB) {
        if ((Object_SpikeInFront(arg0, 0xB4, 0, 0) != 0) && (arg1 == 0)) {
            M2C_FIELD(arg0, s8 *, 0x80) = (s8) temp_s1;
            M2C_FIELD(arg0, s8 *, 0x7F) = 8;
            M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x20);
            Object_DisableCollision(arg0);
            Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, 0x1000);
            Object_PlaySound(arg0, 0x67);
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
            return;
        }
        func_80052864(arg0);
        M2C_FIELD(arg0, s8 *, 0x80) = 5;
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
        func_8013E1D0(arg0);
    }
}

s32 func_80056010(void *, M2C_UNK, M2C_UNK, M2C_UNK);

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013E308(obj)
    void *obj;
{
    return (s16)func_80056010(obj, 0x19, 4, 0);
}

s32 func_8013E334(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6 || Object_DetachLink(arg0, 1) == 6) {
        return 1;
    }
    return 0;
}

s32 func_8013E334(void *arg0);

void func_8013E384(u8 *o, s16 *a, s16 *b) {
    s32 f = M2C_FIELD(o, u32 *, 0xE0) & 1;
    s32 one = 1;

    if (f == one) {
        return;
    }
    if (func_8013E334(o) != 0) {
        M2C_FIELD(o, u32 *, 0xE0) |= one;
        return;
    }
    M2C_FIELD(o, s32 *, 0xB4) = Object_AddAttackSphereNear(o, 0xC8, a[0], a[1], a[2], one, 0x203);
    M2C_FIELD(o, s32 *, 0xB8) = Object_AddAttackSphereNear(o, 0xC8, (a[0] + b[0] * 2) / 3, (a[1] + b[1] * 2) / 3, (s16)((a[2] + b[2] * 2) / 3), one, 0x203);
}

void func_8013E4C4(void *arg0, s32 n) {
    M2C_FIELD(arg0, u8 *, 0x7F) = n;
    M2C_FIELD(arg0, u8 *, 0x80) = 4;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~1;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

extern struct { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike_8013E500 asm("g_Spike");
void func_8013E384(u8 *o, s16 *a, s16 *b);

s32 func_8013E500(void *o, s32 turn, s32 lo, s32 hi, s32 snd) {
    if (M2C_FIELD(o, u16 *, 0x5C) < *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + turn || turn == 0) {
        Object_TurnToward(o, g_Spike_8013E500.f_24 - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013E500.f_2C - M2C_FIELD(o, u16 *, 0x2C), 0, M2C_FIELD(o, s16 *, 0xB0));
    }
    if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + lo) {
        Object_PlaySound(o, snd);
        return 0;
    }
    if (*(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + lo < M2C_FIELD(o, u16 *, 0x5C)) {
        if (M2C_FIELD(o, u16 *, 0x5C) < *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + hi) {
            func_8013E384(o, M2C_FIELD(o, s16 **, 0x78), M2C_FIELD(o, s16 **, 0x74));
        }
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + hi) {
            if (func_8013E334(o) != 0) {
                M2C_FIELD(o, u32 *, 0xE0) |= 1;
            }
        }
        return 1;
    }
    return 0;
}

void func_8013E654(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1 || d == f2) {
        Object_PlaySound(arg0, 0xB8);
    }
}

typedef struct { u8 b[8]; } B8_8013E6A4;
void func_8013E654(void *arg0, s32 f1, s32 f2);
void func_8013E1F4(void *arg0, s32 arg1);

void func_8013E6A4(u8 *o) {
    s32 r;

    if (M2C_FIELD(o, u8 *, 0x7F) == 11) {
        r = func_8013E500(o, 20, 0x1F, 0x23, 20);
        if (M2C_FIELD(o, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + 0x23 && !(M2C_FIELD(o, u32 *, 0xE0) & 1)) {
            Object_PlaySound(o, 0x67);
        }
        func_8013E654(o, -1, 0x1F);
    } else {
        r = 1;
        func_8013E500(o, 0, 0x24, 0x2B, 0x1A);
        func_8013E654(o, 0x23, -1);
    }
    M2C_FIELD(o, u8 *, 0xDE) = func_8013D54C(0, M2C_FIELD(o, s8 *, 0xCB), M2C_FIELD(o, B8_8013E6A4 **, 0x78), M2C_FIELD(o, B8_8013E6A4 **, 0x74), M2C_FIELD(o, u8 *, 0xDE));
    func_8013E1F4(o, r);
}

void func_8013E7A8(void *arg0) {
    u32 f;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 0xB) {
        f = M2C_FIELD(arg0, u32 *, 0xE0) & 1;
        M2C_FIELD(arg0, u8 *, 0x80) = 0xC;
        if (f == 1) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0xC;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x30);
        } else {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0xD;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0x34);
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x80) = 3;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

void func_8013E814(void *arg0) {
    Object_HeadTowardSpike(arg0, func_8013E308());
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), 0x2BC) == 0) {
        func_8013E4C4(arg0, 0xB);
    }
    Object_ApplyVelocity(arg0);
    func_8013E654(arg0, 0, 0x12);
}

extern s32 D_800EC208;

/* called without all its arguments (old-style declaration), so defined old-style */
s32 func_8013E888(arg0)
    void *arg0;
{
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28),
                               M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) == 0 &&
        M2C_FIELD(arg0, s32 *, 0x28) - 0x12C < D_800EC208) {
        return 1;
    }
    return 0;
}

void func_8013E8EC(void *arg0) {
    if (func_8013E888() != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    }
}

s32 func_80057140_8013E930(void *, s32, s32) asm("func_80057140");
void Object_PlaceAtPathPoint(void *, s32);
void func_8005866C(void *, s32);
void func_8013D13C(void);

void func_8013E930(u8 *o) {
    M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(o, u8 *, 0x81) = 16;
    M2C_FIELD(o, s16 *, 0x46) = 0x2BC;
    M2C_FIELD(o, s16 *, 0xA0) = 200;
    M2C_FIELD(o, u8 *, 0xC8) = 11;
    M2C_FIELD(o, s16 *, 0x44) = 200;
    M2C_FIELD(o, u8 *, 0x7D) = 8;
    M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
    M2C_FIELD(o, u8 *, 0xDC) = 6;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x202000;
    M2C_FIELD(o, s32 *, 0x74) = func_80057140_8013E930(o, 0x12, 0xE7);
    M2C_FIELD(o, s32 *, 0x78) = func_80057140_8013E930(o, 0x12, 0xD2);
    M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(o, u8 *, 0x8E) = 1;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x40;
    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        Object_PlaceAtPathPoint(o, 0);
        func_8005866C(o, 1);
    }
    func_8013D13C();
    M2C_FIELD(o, u8 *, 0xDE) = 0;
    M2C_FIELD(o, u8 *, 0x7F) = 3;
    M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013EA4C);

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_408;
s32 Hook_Add(void *);
void func_8013F4B4(void);
void func_80052038(void *, s32);
void func_800520A8(void *, s32);
extern Mdl_408 D_80145280_s[] asm("D_80145280");

void func_8013F124(void) {
    s32 i;
    Mdl_408 *m;
    s32 k;

    if (Hook_Add(func_8013F4B4) == 1) {
        for (i = 0; i < 20; i++) {
            m = &D_80145280_s[i];
            k = (i & 1) + 0xA1;
            func_80052038(m, k);
            func_800520A8(m, k);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f82; u8 life; s16 floor; s16 scale; } Debris_8013F1CC;
extern Debris_8013F1CC D_80145280_8013F1CC[] asm("D_80145280");
extern u16 D_800AE8F2;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 f60; u8 pad62[2]; s16 f64; u8 pad66[0x65]; u8 fCB; } Obj_8013F1CC;

M2C_UNK func_8013F1CC(void *o) {
    s32 i;
    Debris_8013F1CC *d;

    for (i = 0; i < 20; i++) {
        d = &D_80145280_8013F1CC[i];
        d->x = ((Obj_8013F1CC *)o)->x + ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) - 0x80;
        d->y = ((Obj_8013F1CC *)o)->y - ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8);
        d->z = ((Obj_8013F1CC *)o)->z + ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) - 0x80;
        d->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4 + (((Obj_8013F1CC *)o)->f60 * 15 >> 11);
        d->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4 + (((Obj_8013F1CC *)o)->f64 * 15 >> 11);
        d->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x20;
        d->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        d->rz = 0;
        d->ry = 0;
        d->rx = 0;
        d->life = 30;
        d->f82 = ((Obj_8013F1CC *)o)->fCB;
        d->floor = (u16)((Obj_8013F1CC *)o)->y - 50;
        d->scale = (i % 3 + 2) << 12;
    }
}

typedef struct { u8 pad0[0x14]; s32 mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 rvx, rvy, rvz; s16 rx, ry, rz; u8 pad82; u8 timer; u8 pad84[2]; s16 scale; } Deb_8013F4B4;
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void RotMatrixYXZ(void *, void *);
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013F4B4 asm("g_Game");
extern Deb_8013F4B4 D_80145280_8013F4B4[] asm("D_80145280");

void func_8013F4B4(void) {
    s32 i;
    Deb_8013F4B4 *m;
    s32 v[3];

    for (i = 0; i < 20; i++) {
        m = &D_80145280_8013F4B4[i];
        if (m->timer != 0) {
            m->timer--;
            m->x += m->vx;
            m->y += m->vy;
            m->z += m->vz;
            m->vy += 7;
            m->rx = (m->rx + m->rvx) % 4096;
            m->ry = (m->ry + m->rvy) % 4096;
            m->rz = (m->rz + m->rvz) % 4096;
            if (func_80051410(&m->x, 0, 0) == 0) {
                RotMatrixYXZ(&m->rx, (void *)m->mat);
                v[0] = v[1] = v[2] = m->scale;
                ScaleMatrix(m->mat, v);
                func_80015780(m, 3);
                Model_ProjectBonedVerts(m);
                func_80016EBC(g_Game_8013F4B4.f_80 + g_Game_8013F4B4.f_C * 0x4078, &D_800E7D00, m);
            }
        }
    }
}

void func_8013F65C(void *arg0) {
    s8 temp_a0;

    Object_SpawnEffect(arg0, 6, 0, 0x80, 0);
    func_8013F1CC(arg0);
    Object_PlaySound(arg0, 0x4D);
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 - 1);
    func_80051E98(arg0, 0);
    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
}

void func_8013F6DC(void *arg0) {
    s32 var_a0;

    var_a0 = 0;
    if (M2C_FIELD(arg0, u8 *, 0xDD) != 0) {
        var_a0 = 0xA00;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x1C), M2C_FIELD(arg0, s16 *, 0x1E), (s32) M2C_FIELD(arg0, s16 *, 0x20), var_a0 | 1, 0x201);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013F740);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FB20);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8013FF2C);

void func_8014006C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
}

void func_80140088(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x80) = 7;
    if (arg1 != 0) {
        M2C_FIELD(arg0, s8 *, 0x7F) = 6;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x18);
    }
}

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
extern u8 D_801449D8[];
extern u8 D_801449F0[];
void Fx_GroundBlast(s16, s16, s16);
void func_800702B0_801400B4(void *, void *) asm("func_800702B0");
void func_80070284_801400B4(void *, void *, s32, s32, s32) asm("func_80070284");
void Pickup_Drop_801400B4(s32, void *, s32, s32) asm("Pickup_Drop");

void func_801400B4(u8 *o, s32 big) {
    s16 *pos = M2C_FIELD(o, s16 **, 0x74);
    SVECTOR v;

    v.vx = pos[0];
    v.vy = M2C_FIELD(o, u16 *, 0x28) - 0x5A;
    v.vz = pos[2];
    func_800702B0_801400B4(&v, D_801449D8);
    Object_PlaySound(o, 0x79);
    Object_CameraShake(o, 2);
    Fx_GroundBlast(pos[0], pos[1], pos[2]);
    if (big) {
        func_80070284_801400B4(&v, D_801449F0, 1, 0, 0);
        func_80070284_801400B4(&v, D_801449F0 + 0x54, 1, 0, 0);
        func_80070284_801400B4(&v, D_801449F0 + 0xA8, 1, 0, 0);
    }
    if ((RAND() >> 8) & 1) {
        Pickup_Drop_801400B4(1, &v, 3, 0);
    }
}

void func_801401D4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xCE) = (u8) M2C_FIELD(arg0, u8 *, 0x7F);
    func_800525E0();
}

unsigned long func_801401F8(void *arg0)
{
  if (((*((u32 *) (((s8 *) arg0) + 0x50))) >> 28) == 6)
  {
    *((u8 *) (((s8 *) arg0) + 0x80)) = 8;
    *((u8 *) (((s8 *) arg0) + 0x7F)) = 0xA;
    *((u16 *) (((s8 *) arg0) + 0x5C)) = *((u16 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x88)))) + 0x28));
    Object_PlaySound(arg0, 0xB5);
  }
}

s32 func_80140244(void *arg0) {
    if ((D_80145D24 != 0) || (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) != 0xB)) {
        return 0;
    }
    func_800573A0(arg0, 0, 0, 0);
    Sound_PlayFixed(0x60);
    Sound_PlayFixed(0x15);
    Object_PlaySound(arg0, 0xB4);
    M2C_FIELD(arg0, s8 *, 0x7F) = 5;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
    func_801401D4(arg0);
    return 1;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801402D8);

s16 func_80140358(void *obj) {
    if (D_80145D24 != 0) {
        return func_80056010(obj, 0x28, 4, 0);
    }
    return func_80056010(obj, 0x14, 4, 0);
}

void func_80140398(s32 arg0, s32 arg1) {
    Puff_Spawn(arg0, 0, 0, arg1 + 0xFA);
}

void func_801403C0(void *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x78);
    func_80140398(M2C_FIELD(arg0, s32 *, 0x74), 0);
    func_80140398(temp_s0, 0);
}

extern s32 D_80145D38;
void func_80140398(s32 arg0, s32 arg1);
void func_801400B4(u8 *o, s32 big);
s32 func_8013D54C_801403FC(s32, s32, void *, void *, s32) asm("func_8013D54C");
s32 Object_AddAttackSphereNear_801403FC(void *, s32, s32, s32, s32, s32, s32) asm("Object_AddAttackSphereNear");

void func_801403FC(u8 *o) {
    s32 t = M2C_FIELD(o, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
    s16 *a = M2C_FIELD(o, s16 **, 0x74);
    s16 *b = M2C_FIELD(o, s16 **, 0x78);

    if (D_80145D38 != 0) {
        func_80140398((s32)a, 0);
        func_80140398((s32)b, 0);
    }
    if (t >= 0x30 && t < 0x4D) {
        Object_AddAttackSphereNear_801403FC(o, 0xFA, (a[0] + b[0]) >> 1, (a[1] + b[1]) >> 1, (a[2] + b[2]) >> 1, 1, 0x203);
        if (t == 0x37) {
            Object_PlaySound(o, 0x1A);
        }
        if (t == 0x41) {
            func_801400B4(o, D_80145D38);
        }
        M2C_FIELD(o, u8 *, 0xDE) = func_8013D54C_801403FC(0, M2C_FIELD(o, s8 *, 0xCB), a, b, M2C_FIELD(o, u8 *, 0xDE));
    }
}

void func_80140530(void *arg0) {
    M2C_FIELD(&D_80145D30, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(&D_80145D30, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    M2C_FIELD(&D_80145D30, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

extern u32 g_Game_80140554 asm("g_Game");

void func_80140554(void *arg0) {
    switch (g_Game_80140554 & 3) {
    case 0:
        func_80052038(arg0, 0x1E);
        break;
    case 1:
        func_80052038(arg0, 0x89);
        break;
    case 2:
        func_80052038(arg0, 0x8B);
        break;
    case 3:
        func_80052038(arg0, 0x8C);
        break;
    }
}

extern u16 g_RandSeed;
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_801405BC(void *arg0, u8 mask) {
    if (!((RAND() >> 8) & mask)) {
        Object_PlaySound(arg0, 0x5B);
    }
}

extern s16 D_80145D30_80140610[3] asm("D_80145D30");

M2C_UNK func_80140610(void *o, s32 blend) {
    s16 *s;
    s32 k;

    if (blend != 0) {
        k = D_80145D24;
        s = M2C_FIELD(o, s16 **, 0x74);
        D_80145D30_80140610[0] = (M2C_FIELD(o, s32 *, 0x24) * k + s[0] * (30 - k)) / 30;
        D_80145D30_80140610[1] = ((M2C_FIELD(o, s32 *, 0x28) - 0x15E) * k + s[1] * (30 - k)) / 30;
        D_80145D30_80140610[2] = (M2C_FIELD(o, s32 *, 0x2C) * k + s[2] * (30 - k)) / 30;
    } else {
        D_80145D30_80140610[0] = M2C_FIELD(o, s32 *, 0x24);
        D_80145D30_80140610[1] = M2C_FIELD(o, s32 *, 0x28) - 0x15E;
        D_80145D30_80140610[2] = M2C_FIELD(o, s32 *, 0x2C);
    }
    func_80140398((s32)D_80145D30_80140610, 0);
    func_80140398((s32)D_80145D30_80140610, 0x1E);
    func_80140398((s32)D_80145D30_80140610, 0x32);
}


void func_80140778(void *arg0) {
    u8 temp_v1;
    u8 *a;

    if (D_80145D24 != 0) {
        func_801405BC(arg0, 0xF);
        func_80140610(arg0, D_80145D24 < 0x1E);
        D_80145D24 -= 1;
        if (M2C_FIELD(arg0, u8 *, 0x80) != 8) {
            if (Object_DetachLink(arg0, 0) == 6) {
                if (M2C_FIELD(arg0, u8 *, 0x80) != 3) {
                    a = M2C_FIELD(arg0, u8 **, 0x88);
                    D_80145D24 = 0x1F;
                    M2C_FIELD(arg0, u8 *, 0x80) = 8U;
                    M2C_FIELD(arg0, s8 *, 0x7F) = 0xA;
                    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(a, u16 *, 0x28);
                    Object_PlaySound(arg0, 0xB5);
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xFA, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0x15E), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x203);
            }
        }
        if (D_80145D24 != 0) {
            temp_v1 = M2C_FIELD(arg0, u8 *, 0x80);
            if ((temp_v1 == 3) || (temp_v1 == 8)) {
                func_80140554(arg0);
                return;
            }
            goto block_12;
        }
block_12:
        func_80052038(arg0, 0x1E);
        func_8005588C(arg0, 0x78);
    }
}

void func_801408C8(void *arg0, s32 arg1) {
    Object_SpawnEffect(arg0, 5, (s16) (-((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x41) >> 0xB) * arg1), 0, (s32) (s16) (((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x41) >> 0xB) * arg1));
    Object_PlaySound(arg0, 0xB7);
    Object_CameraShake(arg0, 0);
}

void func_8014095C(void *arg0, s32 f1, s32 f2) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == f1) {
        func_801408C8(arg0, 1);
    } else if (d == f2) {
        func_801408C8(arg0, -1);
    }
}

M2C_UNK Object_StepOnGroundFixed(s32);
s32 Object_WouldLeaveHome(void *, s16);

void func_801409AC(s32 arg0, s32 arg1) {
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_StepOnGroundFixed(arg0);
        return;
    }
    if ((arg1 != 0) && (D_80145D24 >= 0x1E)) {
        D_80145D24 = 0x1D;
    }
}

s32 func_80057140_80140A18(void *, s32, s32) asm("func_80057140");
extern s32 D_80145D28;

void func_80140A18(u8 *o) {
    M2C_FIELD(o, s16 *, 0xA0) = 0xFA;
    M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(o, u8 *, 0x81) = 20;
    M2C_FIELD(o, s16 *, 0x44) = 200;
    M2C_FIELD(o, s16 *, 0x46) = 0x2BC;
    M2C_FIELD(o, u8 *, 0x7D) = 8;
    M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFCFFFFFF) | 0x1000000;
    M2C_FIELD(o, u8 *, 0xC8) = 0;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x200000;
    M2C_FIELD(o, s16 *, 0x4A) = -0x4000;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
    M2C_FIELD(o, s8 *, 0x7C) = -1;
    M2C_FIELD(o, s32 *, 0x74) = func_80057140_80140A18(o, 0x12, 0x135);
    M2C_FIELD(o, s32 *, 0x78) = func_80057140_80140A18(o, 0x12, 0x12E);
    D_80145D20 = 0;
    D_80145D24 = 0;
    D_80145D38 = 0;
    D_80145D28 = 1;
    Object_DisableCollision(o);
    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        Object_PlaceAtPathPoint(o, 0);
        func_8005866C(o, 1);
    }
    M2C_FIELD(o, u8 *, 0x7F) = 0;
    M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
    func_8013D13C();
    M2C_FIELD(o, u8 *, 0xDE) = 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140B40);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140C54);

void func_80140EE0(void *arg0) {
    if ((func_8013D0C8() != 0) && (func_8013D118() == 0) && (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA4)) != 0)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
        func_8005588C(arg0, 0x3C);
        func_80140530(arg0);
        D_80145D20 = 2;
    }
}

void func_80140F5C(void) {
    Link_SendEvent(5, 1, 0);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80140F84);

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014183C);

M2C_UNK func_8006F274(void *, void *, u16);
extern M2C_UNK D_80145D48;
extern u16 g_Game;

void func_8014194C(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x8F) * 0x10;
    func_8006F274((u8 *)&D_80145D48 + temp_v0, (u8 *)&D_80145D48 - 8 + temp_v0, g_Game);
}

void func_8014198C(void *arg0) {
    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Puff_Spawn((void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10)), 0, 0, 0x64);
    }
}

void func_801419DC(void *arg0) {
    void *temp_v1;

    M2C_FIELD(arg0, u8 *, 0x8F) = (u8) D_800E77A0.f_1;
    D_800E77A0.f_1 = (u8) (D_800E77A0.f_1 + 1);
    temp_v1 = (void *)((u8 *)&D_80145D40 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0x10));
    M2C_FIELD(temp_v1, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(temp_v1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x28) + 0x12C);
    M2C_FIELD(temp_v1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141A38);

void func_8014183C(void *);
void func_8014194C(void *arg0);
void func_8014198C(void *arg0);
void func_801419DC(void *arg0);
void func_80141A38(void *);

void func_80141AE0(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u8 *, 0xC8) = 5;
        func_801419DC(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (D_80145D20 != 0) {
            func_80141A38(o);
        }
        break;
    case 2:
        if ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 5) == 0) {
            func_8014198C(o);
        }
        if (D_80145D20 == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
        }
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            func_8005588C(o, 4);
            Object_PlaySound(o, 0x78);
            func_8014183C(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0xC9) != 0) {
            func_8014194C(o);
            if (--M2C_FIELD(o, u8 *, 0xC9) == 0) {
                func_80141A38(o);
            }
        }
        if (D_80145D20 == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
        }
        break;
    }
}

s32 func_8013D0C8(void);
void func_80058134_80141C90(void *, s32) asm("func_80058134");

void func_80141C90(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & ~0x1000) | 0x200;
        if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
            Object_PlaceAtPathPoint(o, 0);
            func_8005866C(o, 1);
        }
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (func_8013D0C8()) {
        func_80051E98(o, 0);
    } else {
        func_80058134_80141C90(o, M2C_FIELD(o, s16 *, 0x44));
        if (M2C_FIELD(o, u16 *, 0x8C) == 0) {
            Object_TurnTowardSpike(o);
        }
    }
}

s16 Object_FloorAt(void *, s32, s32, s32);

s32 func_80141D64(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

void func_80141DDC(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAA);
    temp_v1 = temp_a0 + 0x22;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x1021;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0;
    temp_a1 = (s32) (rcos(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

void func_80141EB8(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

u32 Object_DetachLink(void *, s32);

void func_80141F38(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80141FDC);

void func_8006D568(void *);

void func_80142218(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x8F) != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        M2C_FIELD(arg0, u16 *, 0xBC) += M2C_FIELD(arg0, u16 *, 0x94);
        M2C_FIELD(arg0, u16 *, 0xBE) += M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0xC0) += M2C_FIELD(arg0, u16 *, 0x98);
        v.vx = M2C_FIELD(arg0, u16 *, 0xBC);
        v.vy = M2C_FIELD(arg0, u16 *, 0xBE);
        v.vz = M2C_FIELD(arg0, u16 *, 0xC0);
        func_8006D568(&v);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x50, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        if (M2C_FIELD(arg0, u8 *, 0x8F) >= 0x33) {
            M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        }
    }
}

void func_801422E8(void *arg0) {
    u8 st;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        st = M2C_FIELD(arg0, u8 *, 0x7F);
        if (st == 2 && M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4) + 7) {
            M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x96) = (M2C_FIELD(arg0, s16 *, 0x62) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0xBC) = M2C_FIELD(arg0, u16 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94) * 2;
            M2C_FIELD(arg0, s16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96) * 2;
            M2C_FIELD(arg0, s16 *, 0xC0) = M2C_FIELD(arg0, u16 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98) * 2;
            Object_PlaySound(arg0, 0x4D);
            M2C_FIELD(arg0, s8 *, 0x8F) = 1;
            M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        }
    }
}

s32 func_801423E4(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_80142418(void *arg0) {
    if (func_801423E4(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8014246C(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

typedef struct { u32 b0 : 3; u32 init : 1; u32 b4 : 18; u32 mode : 2; u32 b24 : 8; } Flags_8013D630;
void func_80058134();
void func_80054220(void *);
void func_80142218(void *arg0);
void func_801422E8(void *arg0);
void func_80142418(void *arg0);
void func_8014246C(void *arg0);

void func_801424D4(u8 *e) {
    u8 state;

    if (!M2C_FIELD(e, Flags_8013D630 *, 0xE0).init) {
        M2C_FIELD(e, s16 *, 0xA0) = 0x32;
        M2C_FIELD(e, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(e, s16 *, 0x44) = 0x3C;
        M2C_FIELD(e, s16 *, 0x48) = 0x201;
        M2C_FIELD(e, s16 *, 0x4A) = 0x8202;
        M2C_FIELD(e, s16 *, 0x46) = 0x64;
        e[0xCD] = 3;
        e[0xDC] = 5;
        e[0xC9] = 0;
        e[0x7F] = 0;
        M2C_FIELD(e, s16 *, 0x9C) -= 200;
        M2C_FIELD(e, s32 *, 0x28) = M2C_FIELD(e, s16 *, 0x9C);
        M2C_FIELD(e, Flags_8013D630 *, 0xE0).mode = 2;
        M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
        M2C_FIELD(e, Flags_8013D630 *, 0xE0).init = 1;
    }
    func_80058134(e, M2C_FIELD(e, s16 *, 0x44));
    func_8014246C(e);
    switch (e[0x80]) {
    case 1:
        if (e[0xC9] == 0) {
            func_80142418(e);
        }
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            if (e[0xC9] != 0) {
                e[0xC9]--;
            }
        }
        break;
    case 2:
        func_801422E8(e);
        if (M2C_FIELD(e, u16 *, 0x5C) >= M2C_FIELD(e, u16 **, 0x88)[e[0x7F] * 2 + 1]) {
            if (e[0x7F] == 2) {
                e[0x80] = 1;
                e[0x7F] = 0;
                M2C_FIELD(e, u16 *, 0x5C) = *M2C_FIELD(e, u16 **, 0x88);
                e[0xC9] = 5;
            } else {
                e[0x7F] = 2;
                M2C_FIELD(e, u16 *, 0x5C) = M2C_FIELD(e, u16 **, 0x88)[4];
            }
        }
        break;
    }
    func_80142218(e);
    func_80054220(e);
}

extern struct S_g_Game_801426B4 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801426B4 asm("g_Game");
void func_8008FC30(s32, s16 *);

s32 func_801426B4(s16 *p) {
    u8 *e = g_Game_801426B4.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(e, s16 *, 0x16) > p[5]) {
        func_8008FC30(p[7], p);
        func_8008FC30(p[8], p);
        p[1] = 2;
    } else {
        p[1] = 0;
    }
    return 0;
}

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x4C]; u16 f_8150; u8 pad_8152[0xCE]; u8 *f_8220; } g_Game_80142740 asm("g_Game");
void CamFlyby_StartSegment(s32);
void func_8008FC30_80142740(s32, void *) asm("func_8008FC30");

s32 func_80142740(s16 *p) {
    u8 *t;

    switch (p[1]) {
    case 0:
        t = g_Game_80142740.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 0x16) > p[5] && g_Game_80142740.f_8150 == 8) {
            p[1] = 1;
        }
        break;
    case 1:
        if (g_Game_80142740.f_8150 == 0) {
            func_8008FC30_80142740(p[7], p);
            func_8008FC30_80142740(p[8], p);
            if (p[6] > 0) {
                CamFlyby_StartSegment(p[6] - 1);
            }
            g_Game_80142740.f_8100 = 7;
            p[1] = 2;
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80142840 asm("g_Game");
extern u8 *D_800B4D64_80142840 asm("D_800B4D64");

s32 func_80142840(s16 *p) {
    u16 *e = (u16 *)(g_Game_80142840.f_820C + p[2] * 0x38);
    u8 *f = g_Game_80142840.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(f, s16 *, 2) == 1) {
        p[1] = 3;
        e[2] += p[6];
        e[0x17] = p[7];
        e[0x14] = e[2];
        e = (u16 *)(g_Game_80142840.f_820C + (p[2] * 0x38 + 0x38));
        e[2] += p[6];
        e[0x17] = p[7];
        e[0x14] = e[2];
        if ((s16)e[7] >= 0) {
            M2C_FIELD(D_800B4D64_80142840 + (s16)e[7] * 32, u16 *, 0x14) = e[2];
        }
    } else {
        p[1] = 0;
        p[3] = 0;
        e[0x14] = e[2];
        e = (u16 *)(g_Game_80142840.f_820C + (p[2] * 0x38 + 0x38));
        e[0x14] = e[2];
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_8014296C);

typedef struct { s16 f0; s16 f2; u8 pad4[0x14]; } Sw_80142CCC;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; Sw_80142CCC *f_8220; } g_Game_80142CCC asm("g_Game");

s32 func_80142CCC(s16 *p) {
    u8 *e = g_Game_80142CCC.f_820C + p[2] * 0x38;
    s32 t;

    u8 *s = (u8 *)g_Game_80142CCC.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(s, s16 *, 2) == 3) {
        p[1] = 2;
        if (p[5] == 1) {
            M2C_FIELD(e, u16 *, 0x2E) = p[6];
        } else if (p[5] == 2) {
            M2C_FIELD(e, u16 *, 0x2C) = p[6];
            M2C_FIELD(e, s16 *, 0x1C) = 2;
            M2C_FIELD(e, s16 *, 0x36) = 0;
            M2C_FIELD(e, u16 *, 0x12) |= 0x103;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
            t = M2C_FIELD(e, s16 *, 0xC) * 2;
            M2C_FIELD(e, s16 *, 0xC) = t / 360;
        }
    } else {
        p[1] = 0;
        p[3] = 0;
    }
    return 0;
}

typedef struct { s16 f0; s16 f2; u8 pad4[0x14]; } Sw_80142DB0;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; Sw_80142DB0 *f_8220; } g_Game_80142DB0 asm("g_Game");
int abs(int);

s32 func_80142DB0(s16 *p) {
    u8 *e = g_Game_80142DB0.f_820C + p[2] * 0x38;
    s32 t;
    Sw_80142DB0 *w;

    switch (p[1]) {
    case 0:
        w = &g_Game_80142DB0.f_8220[p[4]];
        if (w->f2 == 2) {
            p[1] = 1;
            p[3] = 0;
            if (p[5] == 2) {
                M2C_FIELD(e, s16 *, 0x1C) = 2;
                M2C_FIELD(e, s16 *, 0x36) = 0;
                M2C_FIELD(e, u16 *, 0x12) |= 0x103;
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
                t = M2C_FIELD(e, s16 *, 0xC) * 2;
                M2C_FIELD(e, s16 *, 0xC) = t / 360;
            }
        }
        break;
    case 1:
        p[3]++;
        if (p[7] < p[3]) {
            p[1] = 2;
            p[3] = p[7];
        }
        if (p[5] == 1) {
            M2C_FIELD(e, s16 *, 0x2E) = 360 - p[3] * (360 - abs(p[6])) / p[7];
            if (p[6] < 0) {
                M2C_FIELD(e, s16 *, 0x2E) *= -1;
            }
        } else if (p[5] == 2) {
            M2C_FIELD(e, s16 *, 0x2C) = 360 - p[3] * (360 - abs(p[6])) / p[7];
            if (p[6] < 0) {
                M2C_FIELD(e, s16 *, 0x2C) *= -1;
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}

extern struct S_g_Game_80142FD8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80142FD8 asm("g_Game");

s32 func_80142FD8(s16 *p) {
    u16 *e = (u16 *)(g_Game_80142FD8.f_820C + p[2] * 0x38);
    u8 *f = g_Game_80142FD8.f_8220 + p[4] * 0x18;

    if (M2C_FIELD(f, s16 *, 2) == 1) {
        p[1] = 2;
        e[2] += p[6];
    } else {
        p[1] = 0;
        p[3] = 0;
        e[0x14] = e[2];
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143068 asm("g_Game");
extern s16 D_800AFA20;

s32 func_80143068(s16 *p) {
    u16 *e = (u16 *)(g_Game_80143068.f_820C + p[2] * 0x38);
    u8 *f;

    switch (p[1]) {
    case 2:
        break;
    case 0:
        f = g_Game_80143068.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(f, s16 *, 2) == 1) {
            p[1] = 1;
            p[3] = 0;
            D_800AFA20 = 1;
        }
        break;
    case 1:
        p[3]++;
        if (p[5] < p[3]) {
            p[1] = 2;
            p[3] = 0;
            e[2] = e[0x14] + p[6];
        } else {
            e[2] = e[0x14] + p[3] * p[6] / p[5];
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x812A]; u16 f_812A; u8 pad_812C[0x10C]; s32 *f_8238; u8 pad_823C[0x50]; s32 f_828C; } g_Game_8014318C asm("g_Game");
extern s16 D_800AFA20;
extern u8 *D_800B4D64_8014318C asm("D_800B4D64");

s32 func_8014318C(s16 *p) {
    s32 i;
    s32 *q;

    if (g_Game_8014318C.f_812A == 0) {
        D_800AFA20 = 0;
    } else if (D_800AFA20 != 0) {
        if (p[6] >= 0) {
            M2C_FIELD(D_800B4D64_8014318C + p[6] * 32, s16 *, 0x16) = 0;
        }
        q = g_Game_8014318C.f_8238;
        if (q == 0) {
            return 0;
        }
        for (i = 0; i < g_Game_8014318C.f_828C; i++) {
            if (q[i * 10] == 3) {
                q[i * 10] = 0;
            }
        }
    }
    return 0;
}

s32 func_80143240(void) {
    return 0;
}

extern struct S_g_Game_80143248 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143248 asm("g_Game");
extern s16 D_800AFA20;

s32 func_80143248(s16 *p)
{
  u8 *e = g_Game_80143248.f_820C + (p[2] * 0x38);
  s16 new_var2;
  int new_var;
  if (D_800AFA20 != 0)
  {
    new_var2 = p[4];
    *((s16 *) (((s8 *) e) + 0x1C)) = 2;
    *((s16 *) (((s8 *) e) + 0x36)) = 0;
    *((u16 *) (((s8 *) e) + 0x2C)) = new_var2;
    *((u16 *) (((s8 *) e) + 0x12)) |= 0x103;
    *((u16 *) (((s8 *) e) + 0x18)) = (new_var = ((*((u16 *) (((s8 *) e) + 0x18))) & 0xFFF0) | 2);
    *((s16 *) (((s8 *) e) + 0xC)) = ((*((s16 *) (((s8 *) e) + 0xC))) << 1) / 360;
  }
  return 0;
}

s32 func_801432E8(void) {
    return 0;
}

extern struct S_g_Game_801432F0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801432F0 asm("g_Game");

s32 func_801432F0(s16 *p) {
    u8 *e;

    p[3] = 0;
    e = g_Game_801432F0.f_8220 + p[4] * 0x18;
    if (M2C_FIELD(e, s16 *, 2) == 1) {
        p[1] = 3;
    } else {
        p[1] = 0;
    }
    return 0;
}

typedef struct { s16 f0; s16 f2; u8 pad4[0x14]; } Sw_80143344;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x11C]; Sw_80143344 *f_8220; } g_Game_80143344 asm("g_Game");
extern s16 D_800EC238;

s32 func_80143344(s16 *p) {
    Sw_80143344 *t;

    if (p[4] < 0) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        t = &g_Game_80143344.f_8220[p[4]];
        if (t->f2 == 1) {
            CamFlyby_StartSegment(0);
            g_Game_80143344.f_8100 = 7;
            D_800EC238 = -1;
            p[1] = 1;
            p[3] = 0;
        }
        break;
    case 1:
        if (++p[3] >= p[5]) {
            CamFlyby_StartSegment(1);
            g_Game_80143344.f_8100 = 7;
            p[1] = 2;
            p[3] = 0;
            t = &g_Game_80143344.f_8220[p[7]];
            t->f2 = 1;
            t = &g_Game_80143344.f_8220[p[8]];
            t->f2 = 1;
        }
        break;
    case 2:
        if (++p[3] >= p[6]) {
            CamFlyby_StartSegment(2);
            g_Game_80143344.f_8100 = 7;
            p[1] = 3;
            p[3] = 0;
            t = &g_Game_80143344.f_8220[p[9]];
            t->f2 = 5;
            Sound_PlayFixed(0xB3);
        }
        break;
    }
    return 0;
}

s32 func_80143524(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80143534 asm("g_Game");

s32 func_80143534(s16 *p) {
    u8 *e = g_Game_80143534.f_820C + p[2] * 0x38;
    s16 v;

    switch (p[1]) {
    case 0:
        break;
    case 1:
        p[1] = 2;
        p[3] = 0;
        M2C_FIELD(e, s16 *, 0x1C) = 2;
        M2C_FIELD(e, s16 *, 0xC) = (M2C_FIELD(e, s16 *, 0xC) << 1) / 360;
        M2C_FIELD(e, s16 *, 0x36) = 0;
        M2C_FIELD(e, u16 *, 0x12) |= 0x103;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        break;
    case 2:
        p[3]++;
        if (p[3] > p[5]) {
            p[1] = 3;
            p[3] = p[5];
        }
        v = 360 - p[3] * (360 - ABS(p[4])) / p[5];
        M2C_FIELD(e, s16 *, 0x2C) = v;
        if (p[4] < 0) {
            M2C_FIELD(e, s16 *, 0x2C) = v * -1;
        }
        break;
    }
    return 0;
}

extern struct { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0xEA]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801436A8 asm("g_Game");
extern u8 *D_800B4D64_801436A8 asm("D_800B4D64");

s32 func_801436A8(s16 *p) {
    s16 *f;
    u16 *e;

    if (g_Game_801436A8.f_8120 == 0x13) {
        f = (s16 *)(g_Game_801436A8.f_8220 + p[6] * 0x18);
        if (f[1] == 4) {
            f[1] = 5;
        }
        e = (u16 *)(g_Game_801436A8.f_820C + f[2] * 0x38);
        e[0xC] |= 0x8000;
        if ((s16)e[7] >= 0) {
            M2C_FIELD(D_800B4D64_801436A8 + (s16)e[7] * 32, s16 *, 0x16) = 0;
        }
        p[1] = 5;
        return 0;
    }
    p[3] = 0;
    p[1] = p[4];
    if (p[1] == 5) {
        f = (s16 *)(g_Game_801436A8.f_8220 + p[6] * 0x18);
        if (f[1] == 4) {
            f[1] = 5;
        }
        e = (u16 *)(g_Game_801436A8.f_820C + f[2] * 0x38);
        e[0xC] |= 0x8000;
        if ((s16)e[7] >= 0) {
            M2C_FIELD(D_800B4D64_801436A8 + (s16)e[7] * 32, s16 *, 0x16) = 0;
        }
    }
    return 0;
}

typedef struct { s16 f0; s16 f2; u8 pad4[0x14]; } Sw_801437E8;
extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x1C]; u16 f_8120; u8 pad_8122[4]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; u8 pad_812C[0xF4]; Sw_801437E8 *f_8220; } g_Game_801437E8 asm("g_Game");
extern struct { u8 pad_0[0x2C]; s32 z; u8 pad_30[8]; s32 f_38; } g_Spike_801437E8 asm("g_Spike");
extern s32 D_800EC20C;
s32 Game_SetMode(s32, s32, s32);
s32 Overlay_GetState_801437E8(void) asm("Overlay_GetState");
void Overlay_Request(s8);
s32 Sound_UnloadBanks(s32);
void func_8008745C(void);

s32 func_801437E8(s16 *p) {
    Sw_801437E8 *t;

    if (g_Game_801437E8.f_8120 == 0x13) {
        return 0;
    }
    switch (p[1]) {
    case 0:
        if (D_800EC20C > 0x40) {
            p[1] = 1;
            Sound_UnloadBanks(2);
            Overlay_Request(0xC);
        }
        break;
    case 1:
        if (Overlay_GetState_801437E8() == 0) {
            p[1] = 3;
            p[8] = 0;
            func_8008745C();
        }
        break;
    case 2:
        if (D_800EC20C > 0x40) {
            p[1] = 3;
        }
        break;
    case 3:
        if (p[8] != 0) {
            p[1] = 4;
            t = &g_Game_801437E8.f_8220[p[6]];
            if (t->f2 == 4) {
                t->f2 = 5;
                Sound_PlayFixed(0xB3);
            }
            CamFlyby_StartSegment(0);
            p[3] = 0;
            g_Game_801437E8.f_8100 = 7;
        } else if (g_Spike_801437E8.z < 0) {
            g_Spike_801437E8.z = 0;
            g_Spike_801437E8.f_38 = 0;
        }
        break;
    case 4:
        p[3]++;
        g_Game_801437E8.f_8100 = 7;
        if (p[3] > p[7]) {
            p[1] = 5;
            Game_SetMode(0x12, g_Game_801437E8.f_8126, g_Game_801437E8.f_812A);
        }
        break;
    case 5:
        break;
    }
    return 0;
}

s32 func_801439C8(s16 *p) {
    u8 *e;
    u8 *g0 = (u8 *)&g_Game_801426B4;
    s32 k = 0x8000;
    u8 *g = g0 + k;

    p[3] = 0;
    if (p[10] == 0) {
        p[1] = 0;
    } else {
        e = *(u8 **)(g + 0x220) + p[4] * 0x18;
        if (M2C_FIELD(e, s16 *, 2) == 4) {
            M2C_FIELD(e, s16 *, 2) = 5;
        }
        e = *(u8 **)(g + 0x220) + p[5] * 0x18;
        if (M2C_FIELD(e, s16 *, 2) == 4) {
            M2C_FIELD(e, s16 *, 2) = 5;
        }
        p[1] = 2;
    }
    return 0;
}

s32 func_80143A64(s16 *p) {
    u8 *t;
    u8 *g0 = (u8 *)&g_Game_801426B4;
    s32 k = 0x8000;
    u8 *g = g0 + k;

    if (p[1] == 1) {
        p[1] = 2;
        t = *(u8 **)(g + 0x220) + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 4) {
            M2C_FIELD(t, s16 *, 2) = 5;
        }
        t = *(u8 **)(g + 0x220) + p[5] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 4) {
            M2C_FIELD(t, s16 *, 2) = 5;
        }
        CamFlyby_StartSegment(0);
        *(s32 *)(g + 0x100) = 7;
    }
    return 0;
}

extern struct S_g_Game_80143B14 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143B14 asm("g_Game");

s32 func_80143B14(s16 *p) {
    u8 *e = g_Game_80143B14.f_820C + p[2] * 0x38;
    s32 v = p[10];

    if (v == 1) {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        p[1] = v;
    } else {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        p[1] = 0;
    }
    return 0;
}

extern struct S_g_Game_80143B8C { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143B8C asm("g_Game");
extern s16 D_800EC238;

s32 func_80143B8C(s16 *p) {
    u8 *e = g_Game_80143B8C.f_820C + p[2] * 0x38;

    if (p[1] == 0 && D_800EC238 == p[2]) {
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        p[1] = 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143BF8);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80143CC0 asm("g_Game");
s32 Sound_Stop_80143CC0(s32, s32) asm("Sound_Stop");
void Sound_UpdateVoice3D(s32, s32, s32, void *);
s32 func_80143E94(u8 *e, s16 *p);

s32 func_80143CC0(s16 *p) {
    u8 *e = g_Game_80143CC0.f_820C + p[2] * 0x38;
    u8 *t;
    s32 v;

    if (p[5] >= 0) {
        t = g_Game_80143CC0.f_8220 + p[5] * 0x18;
        v = M2C_FIELD(t, s16 *, 0x16);
    }
    switch (p[1]) {
    case 0:
        if (v < p[3]) {
            p[1] = 2;
        } else {
            p[3] = v;
            if (v >= 0x1000) {
                p[3] = 0x1000;
                p[1] = 1;
                p[9] = p[6];
            }
        }
        break;
    case 1:
        if (--p[9] < 0) {
            p[1] = 2;
        }
        break;
    case 2:
        p[3] -= p[7];
        if (p[3] < v) {
            p[3] = v;
            p[1] = 0;
        } else if (p[3] < p[8]) {
            p[3] = p[8];
            p[1] = 0;
        }
        break;
    }
    if (p[3] != p[8]) {
        if (p[10] < 0) {
            p[10] = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, p[10], 0x1800, e);
        }
    } else if (p[10] >= 0) {
        Sound_Stop_80143CC0(0x7F, p[10]);
        p[10] = -1;
    }
    func_80143E94(e, p);
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80143E94);

typedef struct { s32 m[8]; } Mtx_80143FA8;
void RotMatrixZYX(void *, void *);
void Camera_StartShake(s32);
void func_80052CEC(s32);
s32 Sound_PlayAt(s32, s32);

s32 func_80143FA8(s16 *p) {
    Mtx_80143FA8 m;
    SVECTOR r;
    s32 a = 0;
    u8 *e = g_Game_80143068.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (M2C_FIELD(e, s16 *, 0x1E) >= 0) {
            p[1] = 1;
            p[3] = p[5];
            Camera_StartShake(0);
            func_80052CEC(1);
            Sound_PlayAt(0xAF, (s32)e);
        }
        break;
    case 1:
        p[3]--;
        if (p[3] < 0) {
            p[1] = 0;
            p[3] = 0;
        }
        if (p[3] * 2 == p[5]) {
            Sound_PlayAt(0xAF, (s32)e);
        }
        a = (-(p[3] << 9) / p[5]) * rsin_8013DD64((p[3] << 13) / p[5]) / 4096;
        break;
    }
    if (p[5] >= 0) {
        r.vy = 0;
        r.vz = 0;
        r.vx = a;
        RotMatrixZYX(&r, &m);
        *M2C_FIELD(D_800B4D64_80142840 + p[5] * 32, Mtx_80143FA8 **, 0x1C) = m;
    }
    if (p[6] >= 0) {
        r.vy = 0;
        r.vz = 0;
        r.vx = -a;
        RotMatrixZYX(&r, &m);
        *M2C_FIELD(D_800B4D64_80142840 + p[6] * 32, Mtx_80143FA8 **, 0x1C) = m;
    }
    return 0;
}

extern struct S_g_Game_80144240 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game_80144240 asm("g_Game");

s32 func_80144240(s16 *p) {
    u8 *e = g_Game_80144240.f_820C + p[2] * 0x38;

    M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    return 0;
}

typedef struct { s32 x, y, z; u8 pad_C[0xC]; SVECTOR rot; s16 f_20; s16 pad_22; s16 f_24; s16 f_26; } Shape_80144280;
typedef struct { SVECTOR rot; s32 x, y, z, pad; } Loc_80144280;
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x16]; s16 h; } g_Spike_80144280 asm("g_Spike");
typedef struct { s16 x, y, z, w, h, d; } Ent_80144280;
extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80144280 asm("g_Game");
Shape_80144280 *CollShape_Alloc_80144280(void) asm("CollShape_Alloc");
s32 Collision_Set(s32, void *, void *);

s32 func_80144280(s16 *p) {
    Ent_80144280 *e = (Ent_80144280 *)(g_Game_80144280.f_820C + p[2] * 0x38);
    s32 a;
    s32 b;
    s32 hs;
    s32 he;
    s32 unused[4];
    Loc_80144280 l;
    Shape_80144280 *s;

    if (!(e->w < abs(g_Spike_80144280.x - e->x))) {
        if (!(e->d < abs(g_Spike_80144280.z - e->z))) {
            hs = g_Spike_80144280.h / 2;
            a = g_Spike_80144280.y - hs;
            he = e->h / 2;
            b = e->y - he;
            if (!(abs(a - b) > he + hs)) {
                l.rot.vy = 0;
                l.rot.vz = 0;
                if (g_Spike_80144280.x < e->x) {
                    l.rot.vx = -0x1000;
                    l.x = g_Spike_80144280.x + 0x40;
                } else {
                    l.rot.vx = 0x1000;
                    l.x = g_Spike_80144280.x - 0x40;
                }
                l.y = g_Spike_80144280.y;
                l.z = g_Spike_80144280.z;
                s = CollShape_Alloc_80144280();
                if (s != NULL) {
                    s->rot = l.rot;
                    s->x = l.x;
                    s->y = l.y;
                    s->z = l.z;
                    s->f_20 = 0x80;
                    s->f_24 = 1;
                    s->f_26 = 0x202;
                    Collision_Set(6, s, 0);
                }
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_80144438);

extern struct { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801444E4 asm("g_Game");
extern u8 *D_800B4D64_801444E4 asm("D_800B4D64");
void func_800147D0(void *, s32);

s32 func_801444E4(s16 *p) {
    u8 *e = g_Game_801444E4.f_820C + p[2] * 0x38;
    u8 *t;
    SVECTOR v;

    switch (p[1]) {
    case 0:
        t = g_Game_801444E4.f_8220 + p[4] * 0x18;
        if (M2C_FIELD(t, s16 *, 2) == 1) {
            p[1] = 1;
            p[3] = 0;
            if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                M2C_FIELD(D_800B4D64_801444E4 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
            }
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            Sound_PlayFixed(0x9C);
            CamFlyby_StartSegment(1);
            g_Game_801444E4.f_8100 = 7;
        }
        break;
    case 1:
        p[3]++;
        if (p[3] > p[5]) {
            p[1] = 2;
            Sound_PlayFixed(0x9C);
            M2C_FIELD(e, s16 *, 0xA) = M2C_FIELD(e, s16 *, 0x36);
        } else {
            M2C_FIELD(e, s16 *, 0xA) = M2C_FIELD(e, s16 *, 0x36) * p[3] / p[5];
        }
        v.vy = 0x1000;
        v.vx = 0x1000;
        v.vz = (p[3] << 12) / p[5];
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            func_800147D0(&v, M2C_FIELD(D_800B4D64_801444E4 + M2C_FIELD(e, s16 *, 0xE) * 32, s32 *, 0x1C));
        }
        break;
    case 2:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/408/nonmatchings/408_crumbling_castle", func_801446D4);

s32 func_8014483C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 8) = Sound_Play(1, 0xB1);
    return 0;
}

extern struct S_g_Game_80144870 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80144870 asm("g_Game");
void Sound_UpdateVoice3D(s32, s32, s32, void *);

s32 func_80144870(s16 *p) {
    Sound_UpdateVoice3D(0xB1, p[4], 0x1000, g_Game_80144870.f_820C + p[2] * 0x38);
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
