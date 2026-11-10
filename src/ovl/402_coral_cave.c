#include "common.h"
#include "m2c_macros.h"

s16 rcos(s16);
s16 rsin(s16);
s32 Object_StepTowardXZ(void *, s16, s16, s16);
s32 CoralCave_Clamp(s32 *arg0, s32 arg1, s32 arg2);
M2C_UNK Object_SetModel(void *, M2C_UNK);
M2C_UNK Object_GetAnimTable(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
s32 Object_DetachLink(void *, M2C_UNK);

typedef struct { s16 f0; s16 x, y, z; s16 f8; u16 fA; u8 padC[4]; } Src_8013E1E0;
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 padF[9]; s16 f18; s16 f1A; u8 pad1C[4]; } Pt_8013E1E0;
extern struct { u8 pad0[0x824C]; u8 *f_824C; } g_Game_8013E1E0 asm("g_Game");
extern u8 CoralCave_DripCount;
extern Pt_8013E1E0 CoralCave_Drips[];
s32 Floor_GetHeight_8013E1E0(s32, s32, s32) asm("Floor_GetHeight");

s32 CoralCave_InitDrips(void) {
    u8 *h;
    Src_8013E1E0 *src;
    s32 i;

    h = g_Game_8013E1E0.f_824C;
    CoralCave_DripCount = 0;
    src = (Src_8013E1E0 *)(h + 8);
    if (*(u16 *)h == 0x452E && h[2] == 0x46) {
    } else {
        return 1;
    }
    CoralCave_DripCount = h[4];
    if (CoralCave_DripCount > 32) {
        CoralCave_DripCount = 32;
    }
    for (i = 0; i < CoralCave_DripCount; i++) {
        CoralCave_Drips[i].fE = 0;
        CoralCave_Drips[i].x8 = CoralCave_Drips[i].x = src[i].x;
        CoralCave_Drips[i].yA = CoralCave_Drips[i].y = src[i].y;
        CoralCave_Drips[i].zC = CoralCave_Drips[i].z = src[i].z;
        CoralCave_Drips[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x200, src[i].z);
        if (CoralCave_Drips[i].floor < src[i].y) {
            CoralCave_Drips[i].floor = Floor_GetHeight_8013E1E0(src[i].x, src[i].y + 0x1000, src[i].z);
        }
        CoralCave_Drips[i].f18 = 1;
        CoralCave_Drips[i].f1A = src[i].fA;
    }
    return 0;
}

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013D15C;
typedef struct { s16 x, y, z, floor; s16 x0, y0, z0; u8 active; u8 state; s16 f10; s16 vy; s16 f14; u8 phase; u8 pad17; s16 delay; u16 delay0; u8 u, v, f1E, f1F; } Drip_8013D15C;
typedef struct { s32 z; s32 sxy; } Scr_8013D15C;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013D15C;
#define ADDPRIM_BF_8013D15C(ot, p) (((PTag_8013D15C *)(p))->addr = ((PTag_8013D15C *)(ot))->addr, ((PTag_8013D15C *)(ot))->addr = (u32)(p))
#define gte_stszotz_8013D15C(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern u8 D_80141750_8013D15C asm("CoralCave_DripCount");
extern Drip_8013D15C D_80141350_8013D15C[] asm("CoralCave_Drips");
extern Mat_8013D15C D_800E78C0_8013D15C asm("g_ViewMatrix");
extern GameDraw g_Game_8013D15C asm("g_Game");
void SetRotMatrix_8013D15C(Mat_8013D15C *) asm("SetRotMatrix");
void SetTransMatrix_8013D15C(Mat_8013D15C *) asm("SetTransMatrix");
#define SCR_8013D15C ((Scr_8013D15C *)0x1F800000)

s32 CoralCave_UpdateDrips(void) {
    Scr_8013D15C *sc;
    Drip_8013D15C *e;
    s32 i;
    u32 *p;
    u32 *ot;
    u16 x;
    s32 y;
    s32 y2;
    s16 w;
    s16 h;
    s16 x0;
    s16 y0;

    sc = SCR_8013D15C;
    if (D_80141750_8013D15C == 0) {
        return 0;
    }
    e = D_80141350_8013D15C;
    for (i = 0; i < D_80141750_8013D15C; i++, e++) {
        if (e->active == 0) {
            if (--e->delay == 0) {
                e->state = 0;
                e->active = 1;
                e->delay = e->delay0;
                e->x = e->x0;
                e->y = e->y0;
                e->z = e->z0;
                e->f14 = 0;
                e->f10 = 0;
                e->vy = 0;
                e->phase = 0;
                *(u32 *)&D_80141350_8013D15C[i].u = 0x170F60C0;
            }
        }
    }
    e = D_80141350_8013D15C;
    for (i = 0; i < D_80141750_8013D15C; i++, e++) {
        if (e->active != 0) {
            switch (e->phase) {
            case 0:
                if (e->state == 10) {
                    e->u += 0x10;
                }
                if (e->state == 0x22) {
                    e->u += 0x10;
                }
                if (e->state >= 0x22) {
                    e->vy += 0xF;
                    if (e->vy > 0x60) {
                        e->vy = 0x60;
                    }
                    e->y += e->vy;
                    if (e->y > e->floor) {
                        e->y = e->floor;
                        e->state = 0;
                        *(u32 *)&e->u = 0x70F20B0;
                        e->phase++;
                    }
                }
                break;
            case 1:
                e->v += 8;
                if (e->state >= 3) {
                    e->active = 0;
                }
                break;
            }
            e->state++;
        }
    }
    SetRotMatrix_8013D15C(&D_800E78C0_8013D15C);
    SetTransMatrix_8013D15C(&D_800E78C0_8013D15C);
    e = D_80141350_8013D15C;
    p = (u32 *)g_Game_8013D15C.prim;
    ot = g_Game_8013D15C.db[g_Game_8013D15C.cur].ot;
    for (i = 0; i < D_80141750_8013D15C; i++, e++) {
        if (e->active == 0) {
            continue;
        }
        gte_ldv0(e);
        gte_rtps();
        gte_stsxy(&sc->sxy);
        gte_stszotz_8013D15C(&sc->z);
        if ((u32)(sc->z - 1) >= 0x7FF) {
            continue;
        }
        x = sc->sxy & 0xFFFF;
        y = sc->sxy >> 16;
        if ((u16)(x + 0x20) >= 0x1C1 || ({ __asm__("" : "=r"(y2) : "0"(y)); y2; }) < -0x20 || y2 >= 0x111) {
            continue;
        }
        w = 0xCD0 / sc->z;
        h = 0xC2C / sc->z;
        x0 = x - w / 2;
        y0 = y - h / 2;
        switch (e->phase) {
        case 0:
            ((u8 *)p)[3] = 9;
            p[1] = 0x2E5A3728;
            p[2] = (y0 << 16) | (x0 & 0xFFFF);
            p[4] = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p[6] = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p[8] = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p[3] = (e->v << 8 | e->u) | 0x7CAC0000;
            p[5] = (e->v << 8 | (e->u + 0xF)) | 0x3C0000;
            ((u16 *)p)[14] = e->u | ((e->v + 0x17) << 8);
            ((u16 *)p)[18] = ((e->v + 0x17) << 8) | (e->u + 0xF);
            ADDPRIM_BF_8013D15C(ot + sc->z, p);
            p += 10;
            break;
        case 1:
            ((u8 *)p)[3] = 9;
            p[1] = 0x2E6E4B3C;
            p[2] = (y0 << 16) | (x0 & 0xFFFF);
            p[4] = (y0 << 16) | ((x0 + w) & 0xFFFF);
            p[6] = ((y0 + h) << 16) | (x0 & 0xFFFF);
            p[8] = ((y0 + h) << 16) | ((x0 + w) & 0xFFFF);
            p[3] = (e->v << 8 | e->u) | 0x7CAC0000;
            p[5] = (e->v << 8 | (e->u + 0xF)) | 0x3C0000;
            ((u16 *)p)[14] = e->u | ((e->v + 7) << 8);
            ((u16 *)p)[18] = ((e->v + 7) << 8) | (e->u + 0xF);
            ADDPRIM_BF_8013D15C(ot + sc->z, p);
            p += 10;
            break;
        default:
            continue;
        }
    }
    g_Game_8013D15C.prim = (u8 *)p;
    return 0;
}

s32 rcos_8013D770(s32) asm("rcos");
s32 rsin_8013D770(s32) asm("rsin");

M2C_UNK Swimmer_SetNextTarget(void *o) {
    u16 *t;
    s32 a;

    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        M2C_FIELD(o, u8 *, 0x8E) ^= 1;
        t = (u16 *)(M2C_FIELD(o, u8 **, 0x90) + M2C_FIELD(o, u8 *, 0x8E) * 8);
        M2C_FIELD(o, u16 *, 0xBC) = t[0];
        M2C_FIELD(o, u16 *, 0xC0) = t[2];
    } else {
        a = (M2C_FIELD(o, s16 *, 0xAC) + 0x100) % 0x1000;
        M2C_FIELD(o, u16 *, 0xBC) = M2C_FIELD(o, u16 *, 0x9A) + (rcos_8013D770(a) * M2C_FIELD(o, s16 *, 0xA6) >> 12);
        M2C_FIELD(o, u16 *, 0xC0) = M2C_FIELD(o, u16 *, 0x9E) + (rsin_8013D770(a) * M2C_FIELD(o, s16 *, 0xA6) >> 12);
    }
}

void Swimmer_TurnAround(void *arg0) {
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0xAC);
    temp_v1 = temp_a0 + 0x800;
    var_v0 = temp_v1;
    if (temp_v1 < 0) {
        var_v0 = temp_a0 + 0x17FF;
    }
    temp_v0 = temp_v1 - ((var_v0 >> 0xC) << 0xC);
    M2C_FIELD(arg0, s16 *, 0xAC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x60) = rcos(temp_v0);
    M2C_FIELD(arg0, s16 *, 0x64) = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
    Swimmer_SetNextTarget(arg0);
}

extern s32 D_800EC208;

s32 Swimmer_SpikeInSight(u8 *a)
{
  if (!Object_SpikeInFront(a, 0x5A, 0xB50, 0x400))
  {
    return 0;
  }
  if (Object_SpikeInFront(a, 0x5A, 0xB50, 0x100))
  {
    return 0;
  }
  if ((((D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))) >= 0) ? (D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))) : (-(D_800EC208 - (*((s32 *) (((s8 *) a) + 0x28)))))) > 0x400)
  {
    return 0;
  }
  if ((*((u16 *) (((s8 *) a) + 0x8C))) != 0)
  {
    return 1;
  }
  if (Object_WouldLeaveHome(a, 0))
  {
    return 0;
  }
  if (D_800EC208)
  {
    return 1;
  }
  else
  {
    return 1;
  }
}

s32 CoralCave_Clamp(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < arg2) {
        *arg0 = arg2;
        return 0;
    }
    if (arg1 < temp_v1) {
        *arg0 = arg1;
        return 0;
    }
    return 1;
}

u16 Water_Query(s32, s32, s32);
s16 Object_FloorAt_8013D9A4(void *, s32, s32, s32) asm("Object_FloorAt");
extern u32 g_Game_8013D9A4 asm("g_Game");
extern s32 D_800B1D24;
void Shockwave_Spawn(void *, s32 *, s32, s32, s32);

void Swimmer_AdjustDepth(u8 *a, s32 dv, s32 off) {
    SVECTOR v;
    s32 y;
    s32 h;

    y = off + dv;
    if (Water_Query(M2C_FIELD(a, s32 *, 0x24), y, M2C_FIELD(a, s32 *, 0x2C)) >> 12 == 1) {
        if (ABS(M2C_FIELD(a, s16 *, 0x96) + dv) < 0x300) {
            h = Object_FloorAt_8013D9A4(a, 0, 0, 0) - 0x96;
            if (h < y + 300) {
                M2C_FIELD(a, s32 *, 0x28) = h;
            } else {
                M2C_FIELD(a, s32 *, 0x28) = y + 300;
                M2C_FIELD(a, s16 *, 0x96) += dv;
            }
        }
    } else {
        if (g_Game_8013D9A4 % 30 == 0 || g_Game_8013D9A4 % 30 == 5) {
            v.vx = M2C_FIELD(a, u16 *, 0x24);
            v.vy = -0x8E4;
            v.vz = M2C_FIELD(a, u16 *, 0x2C);
            Shockwave_Spawn(&v, &D_800B1D24, 1, 0, 0);
        }
    }
}

s32 rsin_8013DAD8(s16) asm("rsin");
extern s32 D_800EC208;
void Object_StepOrbitAngle(void *, s16);

void Swimmer_UpdateDepth(void *arg0) {
    s32 sp10;
    s32 temp_s0;

    sp10 = D_800EC208 - M2C_FIELD(arg0, s32 *, 0x28);
    Object_StepOrbitAngle(arg0, 8);
    temp_s0 = (s32) (rsin_8013DAD8(M2C_FIELD(arg0, s16 *, 0xAA)) * 0xC8) >> 0xC;
    CoralCave_Clamp(&sp10, 5, -5);
    Swimmer_AdjustDepth(arg0, sp10, M2C_FIELD(arg0, s16 *, 0x9C) + M2C_FIELD(arg0, s16 *, 0x96) + temp_s0);
}

void Swimmer_StartTurn(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 2;
    M2C_FIELD(arg0, u8 *, 0x7F) = 3;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0xAE) = 0;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x108;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x10000;
}

s32 Swimmer_ReachedPathPoint(void *arg0, s16 arg1) {
    s32 sp10;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x90) + (M2C_FIELD(arg0, u8 *, 0x8E) * 8);
    sp10 = M2C_FIELD(temp_s0, s16 *, 2) - M2C_FIELD(arg0, s32 *, 0x28);
    CoralCave_Clamp(&sp10, 0xA, -0xA);
    M2C_FIELD(arg0, u16 *, 0x96) = (u16) sp10;
    return Object_StepTowardXZ(arg0, M2C_FIELD(temp_s0, s16 *, 0), M2C_FIELD(temp_s0, s16 *, 4), arg1) != 0;
}

void Object_ApplyVelocity(void *);

s32 Swimmer_Patrol(u8 *o, s32 a) {
    s32 r = 0;

    if (M2C_FIELD(o, u16 *, 0x8C) != 0) {
        if (Swimmer_ReachedPathPoint(o, a)) {
            Swimmer_StartTurn(o);
            r = 1;
        }
        Object_ApplyVelocity(o);
    } else {
        if (Object_StepTowardXZ(o, M2C_FIELD(o, s16 *, 0xBC), M2C_FIELD(o, s16 *, 0xC0), a)) {
            Swimmer_StartTurn(o);
            r = 1;
        }
        Swimmer_UpdateDepth(o);
        M2C_FIELD(o, s32 *, 0x24) += M2C_FIELD(o, s16 *, 0x94);
        M2C_FIELD(o, s32 *, 0x2C) += M2C_FIELD(o, s16 *, 0x98);
    }
    return r;
}

s32 Swimmer_CheckTurn(u8 *a, s32 r) {
    s32 ret = 0;
    s32 c;
    s32 dx;
    s32 dz;

    if (M2C_FIELD(a, u16 *, 0x8C) != 0) {
        dx = M2C_FIELD(a, s16 *, 0xBC) - M2C_FIELD(a, s32 *, 0x24);
        dz = M2C_FIELD(a, s16 *, 0xC0) - M2C_FIELD(a, s32 *, 0x2C);
        c = dx * dx + dz * dz < r * r;
    } else {
        Swimmer_UpdateDepth(a);
        c = Object_WouldLeaveHome(a, 0);
    }
    if (c) {
        Swimmer_StartTurn(a);
        ret = 1;
    }
    return ret;
}

void Object_SetForwardVelocity(void *, s16);

void Swimmer_MoveForward(void *arg0, s16 speed) {
    Object_SetForwardVelocity(arg0, speed);
    M2C_FIELD(arg0, s32 *, 0x24) += M2C_FIELD(arg0, s16 *, 0x94);
    M2C_FIELD(arg0, s32 *, 0x2C) += M2C_FIELD(arg0, s16 *, 0x98);
    Swimmer_CheckTurn(arg0, speed);
}

void Swimmer_AddBiteSphere(void *arg0, s32 k, s16 r) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24) + ((M2C_FIELD(arg0, s16 *, 0x60) * k) >> 12);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28);
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C) + ((M2C_FIELD(arg0, s16 *, 0x64) * k) >> 12);
    Object_AddAttackSphereNear(arg0, r, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
}

void Swimmer_BiteSounds(void *arg0) {
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    if (d == 0x14) {
        Object_PlaySound(arg0, 0xB4);
    } else if (d == 0x19) {
        Object_PlaySound(arg0, 0x69);
    }
}

void Effect_SpawnAt(s32, SVECTOR *);

void Swimmer_SurfaceSplash(void *arg0)
{
  SVECTOR v;
  v.vx = (*((u16 *) (((s8 *) arg0) + 0x24))) + (((*((s16 *) (((s8 *) arg0) + 0x60))) * 25) >> 9);
  v.vy = -0x8E4;
  v.vz = (*((u16 *) (((s8 *) arg0) + 0x2C))) + (((*((s16 *) (((s8 *) arg0) + 0x64))) * 25) >> 9);
  Effect_SpawnAt(0x100, &v);
  Object_PlaySound(arg0, 0xA3);
}

s32 Object_StepGrowShrink(void *, s16, s16, s16);

void Swimmer_TurnDrift(void *arg0) {
    s32 temp_v0;

    Object_StepGrowShrink(arg0, 0, 0, -4);
    temp_v0 = (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

void Swimmer_TurnDriftBack(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) - 0x14);
    }
    temp_v0 = ((s32) ((u16) M2C_FIELD(arg0, s16 *, 0xA8) << 0x10) >> 0x13) + 0x21;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * temp_v0) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) - ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * temp_v0) >> 0xC));
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013E068 asm("g_Spike");
void Object_PlaceAtPathPoint(void *, s32);
void Object_FacePathPoint(void *, s32);
void Object_TurnToward(void *, s16, s16, s32, s32);
void Swimmer_TurnAround(void *arg0);
s32 Swimmer_Patrol(u8 *o, s32 a);
s32 func_8013DDA8_8013E068(void *, s16) asm("Swimmer_MoveForward");
void Swimmer_AddBiteSphere(void *arg0, s32 k, s16 r);
void Swimmer_BiteSounds(void *arg0);
void Swimmer_TurnDrift(void *arg0);
void Swimmer_TurnDriftBack(void *arg0);

void Swimmer_Update(u8 *o) {
    s32 end;
    s32 f;
    s32 k;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        M2C_FIELD(o, s16 *, 0xA0) = 0x64;
        M2C_FIELD(o, s16 *, 0x44) = 0xC8;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFF;
        M2C_FIELD(o, s16 *, 0x46) = 0;
        M2C_FIELD(o, s16 *, 0xAC) = 0;
        M2C_FIELD(o, s16 *, 0xA8) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x200;
        M2C_FIELD(o, s16 *, 0xA4) = M2C_FIELD(o, s16 *, 0xA6);
        M2C_FIELD(o, s16 *, 0xA6) -= 0x190;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x80000;
        if (M2C_FIELD(o, u16 *, 0x8C)) {
            Object_PlaceAtPathPoint(o, 0);
            Object_FacePathPoint(o, 1);
            M2C_FIELD(o, u8 *, 0x8E) = 0;
            M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        }
        Swimmer_TurnAround(o);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(o, s16 *, 0xA8) != 0) {
            M2C_FIELD(o, s16 *, 0xA8) -= 0x14;
        }
        if (!Swimmer_Patrol(o, (M2C_FIELD(o, s16 *, 0xA8) >> 3) + 0x21) && Swimmer_SpikeInSight(o)) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[4];
        }
        break;
    case 3:
        end = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2);
        f = M2C_FIELD(o, u16 *, 0x5C);
        if (f < end - 0x19) {
            if (!M2C_FIELD(o, u16 *, 0x8C)) {
                Object_TurnToward(o, g_Spike_8013E068.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013E068.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x5B);
            }
        } else {
            if (f < end - 0xF) {
                k = (end - f) * 3 + 0x21;
            } else {
                k = 0x21;
            }
            if (func_8013DDA8_8013E068(o, k)) {
                break;
            }
            Swimmer_AddBiteSphere(o, 0x190, 0xC8);
        }
        Swimmer_BiteSounds(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    case 4:
        func_8013DDA8_8013E068(o, 0x21);
        break;
    case 2:
        Swimmer_TurnDrift(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) + 0x23) {
            Swimmer_SurfaceSplash(o);
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, s16 *, 0xA8) = 0x280;
        }
        break;
    case 5:
        Swimmer_TurnDriftBack(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            Swimmer_TurnAround(o);
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        }
        break;
    }
}

void Crab_StartHide(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 10;
}

M2C_UNK Object_PlaySound(void *, M2C_UNK);
void Crab_StartHide(void *arg0);
void Object_SpawnImpactFx(void *, s32, s32, s32);
void Object_ApplyHit(void *);
void Object_HitFeedback(void *);

void Crab_HandleHits(u8 *a) {

    if (M2C_FIELD(a, u8 *, 0x80) == 6) {
        return;
    }
    if (Object_DetachLink(a, 0) == 6) {
        Crab_StartHide(a);
    }
    switch (M2C_FIELD(a, u8 *, 0x80)) {
    case 1:
    case 2:
        M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear(a, 100, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, s16 *, 0x28), M2C_FIELD(a, s16 *, 0x2C), M2C_FIELD(a, s16 *, 0x48), M2C_FIELD(a, s16 *, 0x4A));
    default:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB) {
            Object_PlaySound(a, 0x67);
            Object_SpawnImpactFx(a, 0, 0, 0);
            Crab_StartHide(a);
        }
        break;
    case 3:
    case 4:
    case 5:
        if ((M2C_FIELD(a, u32 *, 0x50) >> 28) == 0xB && !(M2C_FIELD(a, u8 *, 0xE0) >> 7)) {
            Object_ApplyHit(a);
            Object_HitFeedback(a);
        }
        break;
    }
}

extern u16 g_RandSeed;
s16 func_80055DC0_8013E518(void *, s16, s16) asm("Object_Wander");
void Object_StepOnGroundFixed(void *);

void Crab_Wander(void *arg0) {
    if (func_80055DC0_8013E518(arg0, M2C_FIELD(arg0, s16 *, 0xA8), 0x400)) {
        M2C_FIELD(arg0, u8 *, 0x80) = 2;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        M2C_FIELD(arg0, s16 *, 0x94) = M2C_FIELD(arg0, s16 *, 0x94) * -1;
        M2C_FIELD(arg0, s16 *, 0x98) = M2C_FIELD(arg0, s16 *, 0x98) * -1;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x96) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
    }
    if (!(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F)) {
        if (M2C_FIELD(arg0, s16 *, 0xA8) == 20) {
            M2C_FIELD(arg0, s16 *, 0xA8) = 35;
            M2C_FIELD(arg0, u16 *, 0x94) *= 2;
            M2C_FIELD(arg0, u16 *, 0x98) *= 2;
        } else {
            M2C_FIELD(arg0, s16 *, 0xA8) = 20;
            if (M2C_FIELD(arg0, s16 *, 0x94) * M2C_FIELD(arg0, s16 *, 0x94) + M2C_FIELD(arg0, s16 *, 0x98) * M2C_FIELD(arg0, s16 *, 0x98) >= 26) {
                M2C_FIELD(arg0, s16 *, 0x94) >>= 1;
                M2C_FIELD(arg0, s16 *, 0x98) >>= 1;
            }
        }
    }
    Object_StepOnGroundFixed(arg0);
}

s32 Object_SpikeWithin(void *, s32);

void Crab_UpdateShell(void *arg0)
{
  int new_var;
  s32 new_var2;
  new_var2 = Object_SpikeWithin(arg0, 0x96);
  new_var = 0x46;
  *((s16 *) (((s8 *) arg0) + new_var)) = (new_var2) ? (-0x3C) : (0x3C);
  if (Object_SpikeWithin(arg0, 0x64))
  {
    *((u32 *) (((s8 *) arg0) + 0xE0)) |= 0x80;
  }
  else
  {
    *((u32 *) (((s8 *) arg0) + 0xE0)) &= ~0x80;
  }
}

s32 Object_WouldLeaveHome(void *, s16);
s16 Object_FloorAt(void *, s32, s32, s32);

void Crab_Sidestep(void *arg0) {
    SVECTOR v;
    s16 sp;
    s32 f;

    f = M2C_FIELD(arg0, s16 *, 0xAE);
    if (f != 0) {
        if (f >= 11) {
            sp = M2C_FIELD(arg0, s16 *, 0xA8) * 2;
        } else {
            sp = M2C_FIELD(arg0, s16 *, 0xA8) * f / 10 * 2;
        }
        if (M2C_FIELD(arg0, s16 *, 0xB2) > 0) {
            v.vx = (M2C_FIELD(arg0, s16 *, 0x64) * sp) >> 12;
            v.vz = -(M2C_FIELD(arg0, s16 *, 0x60) * sp) >> 12;
        } else {
            v.vx = -(M2C_FIELD(arg0, s16 *, 0x64) * sp) >> 12;
            v.vz = (M2C_FIELD(arg0, s16 *, 0x60) * sp) >> 12;
        }
        if (Object_WouldLeaveHome(arg0, 0) == 0) {
            M2C_FIELD(arg0, s32 *, 0x24) += v.vx;
            M2C_FIELD(arg0, s32 *, 0x2C) += v.vz;
            M2C_FIELD(arg0, s32 *, 0x28) = Object_FloorAt(arg0, 0, 0, 0);
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
    }
}

typedef struct { u8 p0[0x44]; s16 f44; s16 f46; s16 f48; s16 f4A; u8 p4C[0x10]; u16 f5C; u8 p5E[0x21]; u8 f7F; u8 p80[8]; u16 *f88; u8 p8C[0x14]; s16 fA0; u8 pA2[6]; s16 fA8; u8 pAA[6]; s16 fB0; u8 pB2[0x1B]; u8 fCD; u8 pCE[0xE]; u8 fDC; u8 pDD[3]; u32 fE0; } Obj_8013E834;

void Crab_Init(void *arg0) {
    ((Obj_8013E834 *)arg0)->fA0 = 0x32;
    ((Obj_8013E834 *)arg0)->fB0 = 0x5B;
    ((Obj_8013E834 *)arg0)->f44 = 0x32;
    ((Obj_8013E834 *)arg0)->f4A = -0x7DFC;
    ((Obj_8013E834 *)arg0)->f48 = 0x600;
    ((Obj_8013E834 *)arg0)->f46 = 0x3C;
    ((Obj_8013E834 *)arg0)->fCD = 2;
    ((Obj_8013E834 *)arg0)->fDC = 0;
    ((Obj_8013E834 *)arg0)->f7F = 0;
    ((Obj_8013E834 *)arg0)->fE0 &= ~0x10000;
    ((Obj_8013E834 *)arg0)->fE0 &= ~0x1000;
    *(volatile u32 *)&((Obj_8013E834 *)arg0)->fE0 |= 0x200000;
    ((Obj_8013E834 *)arg0)->f5C = *((Obj_8013E834 *)arg0)->f88;
    ((Obj_8013E834 *)arg0)->fA8 = 0x23;
}

void func_80058134_8013E8B4(void *, s32) asm("Object_DebugStub");
void Object_PlaySound_8013E8B4(void *, s32) asm("Object_PlaySound");
void Object_Destroy_8013E8B4(void *) asm("Object_Destroy");
s32 Object_SpikeNear_8013E8B4(void *, s32) asm("Object_SpikeNear");
void Object_HeadHome_8013E8B4(void *, s32, s32) asm("Object_HeadHome");
void Crab_HandleHits(u8 *a);
void Crab_Wander(void *arg0);
void Crab_Sidestep(void *arg0);

void Crab_Update(u8 *o) {
    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        Crab_Init(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013E8B4(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        if (((M2C_FIELD(o, u32 *, 0xE0) >> 10) & 1) == 0) {
            M2C_FIELD(o, u32 *, 0xE0) = (M2C_FIELD(o, u32 *, 0xE0) & 0xFF3FFFFF) | 0x400000;
            M2C_FIELD(o, s16 *, 0xD4) = (M2C_FIELD(o, s16 *, 0xD4) + 0x1B8) % 4096;
        } else {
            M2C_FIELD(o, u32 *, 0xE0) &= 0xFF3FFFFF;
        }
        return;
    }
    if ((M2C_FIELD(o, u32 *, 0xE0) >> 20) & 1) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x100000;
        Object_PlaySound_8013E8B4(o, 0x15);
        Object_Destroy_8013E8B4(o);
    }
    Crab_HandleHits(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Crab_Wander(o);
        break;
    case 2:
        Crab_Sidestep(o);
        break;
    case 3:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    case 4:
        Crab_UpdateShell(o);
        if (Object_SpikeNear_8013E8B4(o, 0x200) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 5;
            M2C_FIELD(o, u8 *, 0x7F) = 3;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            M2C_FIELD(o, u32 *, 0xE0) &= ~0x80;
            M2C_FIELD(o, s16 *, 0x46) = 0x3C;
        }
        break;
    case 5:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_HeadHome_8013E8B4(o, M2C_FIELD(o, s16 *, 0xA8), 0x400);
        }
        break;
    }
}

extern struct { u8 pad0[0x1A]; s8 f_1A; u8 pad1B; s8 f_1C; } D_800E77D0_8013EAF8 asm("D_800E77D0");
void Object_OrbitAround(void *, s16, s16, s16, s16);

void Orbiter_Update(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013E8B4(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    Object_OrbitAround(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6), (M2C_FIELD(arg0, s16 *, 0xA8) >> 3) + 4);
    switch (M2C_FIELD(arg0, u8 *, 0x80)) {
    case 1:
        if (Object_SpikeNear_8013E8B4(arg0, 0x15E) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 2;
        }
        break;
    case 2:
        if (Object_StepGrowShrink(arg0, 0x14, D_800E77D0_8013EAF8.f_1A + 0x50, -6 - D_800E77D0_8013EAF8.f_1C) != 0) {
            M2C_FIELD(arg0, s16 *, 0xA8) = 0;
            M2C_FIELD(arg0, u8 *, 0x80) = 1;
        }
        break;
    }
}

void Spitter_InitShotModel(void *arg0, void *arg1, M2C_UNK arg2) {
    Object_SetModel(arg1, arg2);
    Object_GetAnimTable(arg1, arg2);
    M2C_FIELD(arg1, s16 *, 0x5C) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 3;
    M2C_FIELD(arg1, SVECTOR *, 0x60) = M2C_FIELD(arg0, SVECTOR *, 0x60);
    M2C_FIELD(arg1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg1, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}

void Matrix_FromDirection(void *, s32);
void Model_ProjectBonedVerts(void *);
void ScaleMatrix(s32, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_DrawAuto(void *, void *, void *);
s32 Object_IsOffScreen(void *, s32, s32);
extern M2C_UNK g_ProjVerts;
extern u8 Spitter_ShotModel[];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;

void Spitter_DrawShot(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = Spitter_ShotModel + arg0 * 0x70;
    if (Object_IsOffScreen(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        Model_CalcKeyedJointMatrices(m, 3);
        Model_ProjectBonedVerts(m);
        Model_DrawAuto(g_Game.f_80 + g_Game.f_C * 0x4078, &g_ProjVerts, m);
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("Spitter_Shots");
void Spitter_UpdateShots(void);
void Hook_Add(void *);

void Spitter_InitShots(void *arg0) {
    s32 i;

    Spitter_InitShotModel(arg0, Spitter_ShotModel, 0x83);
    for (i = 7; i >= 0; i--) {
        D_8013F2A0_s[i].active = 0;
    }
    Hook_Add(Spitter_UpdateShots);
}

s32 Spitter_FindFreeShot(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

s16 rsin_8013D858(s16) asm("rsin");
extern u8 Spitter_Shots[];

void Spitter_FireShot(void *arg0, s32 arg1, s16 arg2)
{
  s32 i;
  u8 *p;
  s16 c;
  s16 s;
  i = Spitter_FindFreeShot();
  if (i != (-1))
  {
    p = Spitter_Shots + (i * 0x14);
    c = rcos(*((s16 *) (((s8 *) arg0) + 0xAC)));
    s = rsin_8013D858(*((s16 *) (((s8 *) arg0) + 0xAC)));
    *((s16 *) (((s8 *) p) + 0)) = (*((u16 *) (((s8 *) arg0) + 0x24))) + ((c * arg2) >> 12);
    *((s16 *) (((s8 *) p) + 2)) = (*((u16 *) (((s8 *) arg0) + 0x28))) - arg1;
    *((s16 *) (((s8 *) p) + 4)) = (*((u16 *) (((s8 *) arg0) + 0x2C))) + ((s * arg2) >> 12);
    *((s16 *) (((s8 *) p) + 6)) = c / 48;
    *((s16 *) (((s8 *) p) + 0xA)) = s / 48;
    *((s16 *) (((s8 *) p) + 8)) = -0x28;
    *((u16 *) (((s8 *) p) + 0xC)) += 1;
    *((s16 *) (((s8 *) p) + 0xE)) = *((s8 *) (((s8 *) arg0) + 0xCB));
  }
}

s32 Spitter_ShotHitFloor(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void Spitter_ShotTrail(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void Spitter_ShotBurst(SVECTOR *p) {
    s32 i;
    SVECTOR v;

    for (i = 0; i < 32; i++) {
        v.vx = p->vx;
        v.vy = p->vy;
        v.vz = p->vz;
        Effect_SpawnAt(10, &v);
    }
}

typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x88]; s32 fB4; u8 padB8[0x2C]; } Obj_8013F044;
extern Obj_8013F044 g_Objects_8013F044[] asm("g_Objects");
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; SVECTOR dir; } Mdl_8013F044;
extern Mdl_8013F044 D_801417F8_8013F044 asm("Spitter_ShotModel");
void VectorNormalSS(void *, void *);
void Object_PlaySound_8013F044(void *, s32) asm("Object_PlaySound");
s32 Object_AddAttackSphere_8013F044(void *, s32, s16, s16, s32, s32, s32) asm("Object_AddAttackSphere");

void Spitter_UpdateShots(void) {
    Drip_396 *p;
    Obj_8013F044 *o;
    s32 i;
    Mdl_8013F044 *m;

    m = &D_801417F8_8013F044;
    for (i = 7; i >= 0; i--) {
        p = &D_8013F2A0_s[i];
        if (p->active != 0) {
            p->active++;
            p->vy += 4;
            o = &g_Objects_8013F044[p->unkE];
            Spitter_ShotTrail((SVECTOR *)p);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            if (Object_DetachLink(o, 0) == 6) {
                p->active = 0;
                Spitter_ShotBurst((SVECTOR *)p);
                Object_PlaySound_8013F044(o, 0x6B);
            } else if (Spitter_ShotHitFloor(p) != 0 || o->y + 0x600 < p->y) {
                p->active = 0;
                Spitter_ShotBurst((SVECTOR *)p);
            } else {
                m->x = p->x;
                m->y = p->y;
                m->z = p->z;
                m->dir.vx = p->vx;
                m->dir.vy = p->vy;
                m->dir.vz = p->vz;
                VectorNormalSS(&m->dir, &m->dir);
                Spitter_DrawShot(0, 3);
                o->fB4 = Object_AddAttackSphere_8013F044(o, 0x1E, p->x, p->y, p->z, 1, 0x203);
            }
        }
    }
}

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void Spitter_Splash(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void Object_ApplyHit(void *);
void Object_HitFeedback(void *);
void Object_SpawnHitSpark(void *, s32, s32, s32);

void Spitter_CheckStunned(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        Object_SpawnHitSpark(arg0, 0, 0, 0);
        Object_ApplyHit(arg0);
        Object_HitFeedback(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void Spitter_Emerge(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    Spitter_Splash(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}

void Spitter_Spit(void *arg0) {
    if (++M2C_FIELD(arg0, u8 *, 0x8F) < 2) {
        Spitter_FireShot(arg0, 0x46, 0xA0);
        Object_PlaySound(arg0, 0x4B);
    } else {
        Object_PlaySound(arg0, 0x48);
    }
}

void Spitter_Init(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
    M2C_FIELD(arg0, s8 *, 0xCD) = 5;
    M2C_FIELD(arg0, s8 *, 0x7D) = 8;
    M2C_FIELD(arg0, s8 *, 0xC8) = 0xE;
    M2C_FIELD(arg0, s8 *, 0xDC) = 1;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, s16 *, 0xA0) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    Object_Timer(arg0, M2C_FIELD(arg0, s16 *, 0x9A) % 60 + 60);
    Object_DisableCollision(arg0);
}

void Object_TurnTowardSpike(void *);

s32 Spitter_CheckHit(void *arg0) {
    u32 s;

    Object_TurnTowardSpike(arg0);
    s = M2C_FIELD(arg0, u32 *, 0x50) >> 28;
    if (s == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = s;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        Spitter_Splash(arg0);
        return 1;
    }
    return 0;
}

void Spitter_Init(void *arg0);
void Spitter_InitShots(void *arg0);
void Spitter_Splash(void *arg0);
void Spitter_CheckStunned(void *arg0);
void Spitter_Emerge(void *arg0);
void Spitter_Spit(void *arg0);
s32 Spitter_CheckHit(void *arg0);
M2C_UNK Object_DisableCollision(void *);
void Object_EnableCollision(void *);
M2C_UNK Object_Timer(void *, M2C_UNK);
void Object_DebugStub(void *, s32);
void Shadow_Draw(void *, s32, s32, s32);
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);
#define ANIM_8013F504(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void Spitter_Update(u8 *o) {
    s32 st;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        Spitter_Init(o);
        M2C_FIELD(o, s16 *, 0xA0) = 100;
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, u8 *, 0xC9) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~1;
        Spitter_InitShots(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    switch (st = M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        Shadow_Draw(o + 0x24, Object_FloorAt(o, 0, 0, 0), M2C_FIELD(o, s16 *, 0xA0), M2C_FIELD(o, s32 *, 0xD0));
        if (Object_Timer(o, -1) == 0
            && Object_SpikeOutOfRange(o, M2C_FIELD(o, s16 *, 0x9A), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s16 *, 0x9E), 1500) == 0) {
            Spitter_Emerge(o);
            M2C_FIELD(o, u8 *, 0xC8) = 14;
            Object_EnableCollision(o);
        }
        break;
    case 3:
        Object_TurnTowardSpike(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F504(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            if (M2C_FIELD(o, u8 *, 0x7F) == 1) {
                M2C_FIELD(o, u8 *, 0x7F) = 4;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F504(o, 4)[0];
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 4;
                M2C_FIELD(o, u8 *, 0x7F) = st;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F504(o, 3)[0];
                M2C_FIELD(o, u8 *, 0x8F) = 0;
            }
        }
        break;
    case 4:
        if (Spitter_CheckHit(o) == 0) {
            if (M2C_FIELD(o, u16 *, 0x5C) == ANIM_8013F504(o, M2C_FIELD(o, u8 *, 0x7F))[0] + 20) {
                Spitter_Spit(o);
            }
            if (M2C_FIELD(o, u8 *, 0x8F) >= 3) {
                M2C_FIELD(o, u8 *, 0x80) = 6;
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F504(o, 0)[0];
                Spitter_Splash(o);
            }
        }
        break;
    case 6:
        Object_DisableCollision(o);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F504(o, M2C_FIELD(o, u8 *, 0x7F))[1]) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F504(o, 1)[0];
            Spitter_Splash(o);
            Object_Timer(o, 60);
        }
        break;
    }
    Spitter_CheckStunned(o);
}

void Cannon_AddAttackSphere(void *arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x80) != 3) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xDE) = (u8) (temp_v0 - 1);
            return;
        }
        if (Object_DetachLink(arg0, 1) == 6) {
            M2C_FIELD(arg0, u8 *, 0xDE) = 0xAU;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB8) = Object_AddAttackSphereNear(arg0, 0x96, (s16) (M2C_FIELD(arg0, u16 *, 0x24) + ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * 0x19) >> 9)), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xBE), (s32) (s16) (M2C_FIELD(arg0, u16 *, 0x2C) + ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * 0x19) >> 9)), 0, 0x100);
    }
}

void EnemyShot_Spawn(SVECTOR *, void *, s32, SVECTOR *);

void Cannon_Fire(u8 *a, s32 mode) {
    SVECTOR p;
    SVECTOR d;

    if (mode == 0) {
        d.vx = M2C_FIELD(a, s16 *, 0x60) / 32;
        d.vy = M2C_FIELD(a, s16 *, 0x62) / 32;
        d.vz = M2C_FIELD(a, s16 *, 0x64) / 32;
        p.vx = M2C_FIELD(a, u16 *, 0x24) + ((M2C_FIELD(a, s16 *, 0x60) * 45) >> 9);
        p.vy = M2C_FIELD(a, u16 *, 0x28) - 0xBE;
        p.vz = M2C_FIELD(a, u16 *, 0x2C) + ((M2C_FIELD(a, s16 *, 0x64) * 45) >> 9);
        Object_PlaySound(a, 0x58);
        EnemyShot_Spawn(&p, a, 1, &d);
    } else if (mode == 2) {
        Object_PlaySound(a, 0x58);
    }
}

M2C_UNK Object_DisableCollision(void *);

void Cannon_Break(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    Object_SetModel(arg0, 0x9F);
    M2C_FIELD(arg0, s16 *, 0x5E) = 1;
    Object_DisableCollision(arg0);
}

extern u8 D_80141200[];
void Rock_SpawnBurst(SVECTOR *, void *);
void Object_CameraShake(void *, s32);

void Cannon_Explode(void *arg0) {
    SVECTOR v;

    v.vx = M2C_FIELD(arg0, u16 *, 0x24);
    v.vy = M2C_FIELD(arg0, u16 *, 0x28) - 0x64;
    v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    Rock_SpawnBurst(&v, D_80141200);
    Rock_SpawnBurst(&v, D_80141200 + 0xC);
    Object_CameraShake(arg0, 0);
    Object_PlaySound(arg0, 0x79);
}

u16 *Collision_GetShape(s16);
s32 Object_TakeHitDamage(u8 *, u16 *);
void func_800573A0_8013FA50(void *, s16, s16, s16) asm("Object_SpawnHitSpark");
void Object_PlaySound_8013FA50(void *, s32) asm("Object_PlaySound");

s32 Cannon_HandleKnock(u8 *o) {
    u16 *s;

    if ((M2C_FIELD(o, u32 *, 0x50) >> 28) != 11) {
        return 0;
    }
    s = Collision_GetShape(M2C_FIELD(o, u16 *, 0x50) & 0xFFF);
    Object_TakeHitDamage(o, s);
    func_800573A0_8013FA50(o, s[0] - M2C_FIELD(o, u16 *, 0x24), M2C_FIELD(o, u16 *, 0x28) - s[2], s[4] - M2C_FIELD(o, u16 *, 0x2C));
    Object_PlaySound_8013FA50(o, 0x60);
    if (M2C_FIELD(o, u8 *, 0x81) != 0) {
        M2C_FIELD(o, u8 *, 0x84) = 20;
        M2C_FIELD(o, u8 *, 0x80) = 5;
        M2C_FIELD(o, u8 *, 0x7F) = 2;
        M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(o, u8 **, 0x88), u16 *, 0x8);
    } else {
        Cannon_Break(o);
        Cannon_Explode(o);
    }
    return 1;
}

void Cannon_CheckBreakEvent(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 4) {
        Cannon_Break(arg0);
        M2C_FIELD(arg0, u8 *, 0xCF) = 0U;
    }
}

extern s32 Cannon_Loaded;
extern u16 g_RandSeed2;
s32 Object_AddAttachPoint(void *, s32, s32);
void Object_SpawnPooled(s32, s32, s32);
void Cannon_AddAttackSphere(void *arg0);
void Cannon_Fire(u8 *a, s32 mode);
s32 Cannon_HandleKnock(u8 *o);
void Cannon_CheckBreakEvent(void *arg0);

void Cannon_Update(u8 *o) {
    SVECTOR v;

    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x16;
        M2C_FIELD(o, s16 *, 0x44) = 0xC8;
        M2C_FIELD(o, s16 *, 0x46) = 0x190;
        M2C_FIELD(o, u8 *, 0x7D) = 0xA;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u8 *, 0x81) = 0x14;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, s32 *, 0x74) = Object_AddAttachPoint(o, 1, 1);
        Object_SpawnPooled(0x3B, 0, M2C_FIELD(o, s8 *, 0xCB));
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        M2C_FIELD(o, u8 *, 0xDE) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    Cannon_CheckBreakEvent(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_TurnTowardSpike(o);
        if (!Cannon_HandleKnock(o) && !Object_Timer(o, -1) &&
            !Object_SpikeOutOfRange(o, M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C), 0xC00)) {
            M2C_FIELD(o, u8 *, 0x80) = 4;
            Cannon_Loaded = 0;
        }
        break;
    case 4:
        Object_TurnTowardSpike(o);
        if (!Cannon_HandleKnock(o) && Cannon_Loaded) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[2];
            M2C_FIELD(o, u8 *, 0x8F) = 0;
        }
        break;
    case 2:
        Object_TurnTowardSpike(o);
        Cannon_Fire(o, M2C_FIELD(o, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88)) - 1);
        if (!Cannon_HandleKnock(o) && M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)
            && ++M2C_FIELD(o, u8 *, 0x8F) >= 3) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
            Object_Timer(o, 0x5A);
        }
        break;
    case 3:
        M2C_FIELD(o, s16 *, 0x5E) = 1;
        if (g_Game_8013D9A4 % 40 < 5) {
            v.vx = M2C_FIELD(o, u16 *, 0x24) + (((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80) * 2;
            v.vy = M2C_FIELD(o, u16 *, 0x28) - ((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x64;
            v.vz = M2C_FIELD(o, u16 *, 0x2C) + (((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) - 0x80) * 2;
            Effect_SpawnAt(7, &v);
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
    Cannon_AddAttackSphere(o);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void CannonMonkey_DrawHelmetLight(void *arg0) {
    SVECTOR v;
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);

    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, 0);
}

void CannonMonkey_FollowCannon(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x74);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v1, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
    M2C_FIELD(arg0, SVECTOR *, 0x60) = M2C_FIELD(arg1, SVECTOR *, 0x60);
    M2C_FIELD(arg0, u16 *, 0xAC) = (u16) M2C_FIELD(arg1, u16 *, 0xAC);
}

typedef struct { u8 pad[0xE4]; } Obj_8013FF9C;
extern Obj_8013FF9C g_Objects_8013FF9C[] asm("g_Objects");
extern s32 Cannon_Loaded;
typedef struct { u8 pad[0x88]; u16 *f_88; } Anim_8013FF9C;
s32 Object_AddAttachPoint(void *, s32, s32);
void Object_Despawn(void *, s32);
void CannonMonkey_DrawHelmetLight(void *arg0);
void CannonMonkey_FollowCannon(void *arg0, void *arg1);

void CannonMonkey_Update(u8 *o) {
    u8 *t = (u8 *)&g_Objects_8013FF9C[M2C_FIELD(o, s8 *, 0xCA)];

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xB0) = 0x44;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x42000;
        M2C_FIELD(o, s32 *, 0x74) = Object_AddAttachPoint(o, 6, 0x45);
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(t, u8 *, 0x80) == 3) {
        Object_Despawn(o, 0);
    }
    CannonMonkey_FollowCannon(o, t);
    CannonMonkey_DrawHelmetLight(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        if (M2C_FIELD(t, u8 *, 0x80) == 4) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_PlaySound(o, 0x52);
        }
        break;
    case 2:
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            Cannon_Loaded = 1;
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = ((Anim_8013FF9C *)o)->f_88[M2C_FIELD(o, u8 *, 0x7F) * 2];
        }
        break;
    case 3:
        if (M2C_FIELD(t, u8 *, 0x80) != 2) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    }
}

s16 Object_FloorAt(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);
s32 Spike_WithinRadiusXZ(s32, s32, s32);

s32 Burrower_SpikeAbove(void *arg0)
{
  s16 new_var;
  new_var = Object_FloorAt(arg0, 0, 0, 0);
  return ((D_800EC208 <= new_var) && ((*((s32 *) (((s8 *) arg0) + 0x28))) < D_800EC208)) && Spike_WithinRadiusXZ(*((s16 *) (((s8 *) arg0) + 0x9A)), *((s16 *) (((s8 *) arg0) + 0x9E)), 0x600);
}

M2C_UNK Object_SetVelocityToward(void *, void *, M2C_UNK, M2C_UNK);
M2C_UNK Object_StepOnGround(void *, M2C_UNK);
s32 rcos_801401E0(s16) asm("rcos");
s32 rsin_801401E0(s16, s32) asm("rsin");

void Burrower_Circle(void *arg0) {
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
    temp_a1 = (s32) (rcos_801401E0(temp_v0) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC;
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9A) + temp_a1) - M2C_FIELD(arg0, u16 *, 0x24));
    temp_lo = rsin_801401E0(M2C_FIELD(arg0, s16 *, 0xAA), temp_a1) * M2C_FIELD(arg0, s16 *, 0xA6);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) (M2C_FIELD(arg0, u16 *, 0x9C) - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((M2C_FIELD(arg0, u16 *, 0x9E) + (temp_lo >> 0xC)) - M2C_FIELD(arg0, u16 *, 0x2C));
    Object_SetVelocityToward(arg0, arg0 + 0x94, 0x3C, 0);
    Object_StepOnGround(arg0, 0x40);
}

s32 Spike_WithinRadiusXZ(s32, s32, s32);

void Burrower_CheckSpikeGone(void *arg0) {
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), 0xA00) == 0 && ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

M2C_UNK Object_PlaySound(void *, M2C_UNK);

void Burrower_Attack(void *arg0) {
    if (Object_DetachLink(arg0, 0) == 6) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
        M2C_FIELD(arg0, s8 *, 0x7F) = 3;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0xC);
        Object_PlaySound(arg0, 0x51);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x96, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - ((s32) (M2C_FIELD(arg0, u16 *, 0x46) << 0x10) >> 0x11)), (s32) M2C_FIELD(arg0, s16 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
}

void Object_PlaySound_801403E0(void *, s32) asm("Object_PlaySound");
s32 Object_FlyAboveFloor(void *, s32);
void func_80058134_801403E0(void *, s32) asm("Object_DebugStub");
void Burrower_Circle(void *arg0);
void Burrower_CheckSpikeGone(void *arg0);
void Burrower_Attack(void *arg0);

void Burrower_Update(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0xA0) = 0x32;
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(arg0, s16 *, 0x48) = 1;
        M2C_FIELD(arg0, s16 *, 0x44) = 0x58;
        M2C_FIELD(arg0, s16 *, 0x46) = 0x114;
        M2C_FIELD(arg0, u8 *, 0xCD) = 4;
        M2C_FIELD(arg0, u8 *, 0xDC) = 0;
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x9C) + 0x100;
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134_801403E0(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    switch (M2C_FIELD(arg0, u8 *, 0x80)) {
    case 1:
        if (Burrower_SpikeAbove(arg0) != 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 2;
            M2C_FIELD(arg0, u8 *, 0x7F) = 1;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[2];
            M2C_FIELD(arg0, s16 *, 0x96) = 4;
            M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 1, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x2C), M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        }
        break;
    case 2:
        if ((s16)Object_FlyAboveFloor(arg0, 0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
            Object_PlaySound_801403E0(arg0, 0xA2);
        }
        M2C_FIELD(arg0, s16 *, 0x96) += 6;
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 1 && M2C_FIELD(arg0, u16 *, 0x5C) == M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    case 3:
        Burrower_Attack(arg0);
        Burrower_Circle(arg0);
        Burrower_CheckSpikeGone(arg0);
        break;
    case 4:
        if (M2C_FIELD(arg0, u16 *, 0x5C) >= M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
            M2C_FIELD(arg0, u8 *, 0x80) = 3;
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
        break;
    }
}

s32 Math_Atan2(s32, s32);

void Darter_StartReturn(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void Darter_StartLunge(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
}

s32 Object_FlyAboveFloor(void *, s32);

void Darter_Hover(void *arg0) {
    Object_FlyAboveFloor(arg0, 0x14);
}

M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 Object_StepToward3D(void *, s16, s16, s16, s32);
M2C_UNK Object_Timer(void *, M2C_UNK);
s32 rcos_80140718(s16) asm("rcos");
s32 rsin_80140718(s16) asm("rsin");

void Darter_Return(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (Object_StepToward3D(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin_80140718(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        Object_Timer(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    Darter_Hover(arg0);
}

s32 Object_AddAttackSphereNear_801407DC(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
void Object_PlaySound_801407DC(void *, s32) asm("Object_PlaySound");
void Darter_StartReturn(void *arg0);

void Darter_Lunge(u8 *a) {
    s16 *v;

    if (Object_DetachLink(a, 0) == 6) {
        Object_PlaySound_801407DC(a, 0x5F);
        Darter_StartReturn(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(a, 0x53, 0x37, 0);
    }
    if (Object_StepToward3D(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        Darter_StartReturn(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear_801407DC(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

s32 Darter_CheckNetted(void *arg0) {
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

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_80140984 asm("g_Spike");
void Object_OrbitHome(void *, s16);
void Object_InitOrbit(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
void ObjKind4D_IdleSounds(void *);
void Darter_StartLunge(void *arg0);
void Darter_Hover(void *arg0);
void Darter_Return(void *arg0);
void Darter_Lunge(u8 *a);
s32 Darter_CheckNetted(void *arg0);

void Darter_Update(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 0x32;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 0x3C;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 0x64;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0xDC) = 1;
        M2C_FIELD(o, s16 *, 0x9C) -= 200;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, u16 *, 0x5C) = *M2C_FIELD(o, u16 **, 0x88);
        Object_InitOrbit(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    Object_DebugStub(o, M2C_FIELD(o, s16 *, 0x44));
    if (Darter_CheckNetted(o)) {
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_OrbitHome(o, 8);
        Object_SeekHeight(o, 8);
        Darter_Hover(o);
        if (!Object_Timer(o, -1) && Object_SpikeInFront(o, 0x168, -0x1000, 0x400)) {
            Darter_StartLunge(o);
        }
        break;
    case 2:
        Object_TurnToward(o, g_Spike_80140984.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_80140984.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1] - 10) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, s16 *, 0xA8) = 0;
            M2C_FIELD(o, u32 *, 0xE0) |= 0x10000;
            M2C_FIELD(o, u16 *, 0xBC) = g_Spike_80140984.x;
            M2C_FIELD(o, u16 *, 0xC0) = g_Spike_80140984.z;
            M2C_FIELD(o, u16 *, 0xBE) = g_Spike_80140984.y - 200;
            M2C_FIELD(o, u8 *, 0x8F) = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3 && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            Object_PlaySound_801407DC(o, 0xA6);
        }
        Darter_Lunge(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            Darter_StartReturn(o);
        } else if (M2C_FIELD(o, u16 *, 0x5C) >= M2C_FIELD(o, u16 **, 0x88)[M2C_FIELD(o, u8 *, 0x7F) * 2 + 1] && M2C_FIELD(o, u8 *, 0x7F) == 2) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = M2C_FIELD(o, u16 **, 0x88)[8];
        }
        break;
    case 4:
        Darter_Return(o);
        break;
    }
    ObjKind4D_IdleSounds(o);
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140C78 asm("g_Game");
s32 Model_SetTurnAngle_80140C78(s16, s16, s32) asm("Model_SetTurnAngle");

s32 CoralCave_InitTurnGate(s16 *p) {
    u8 *e;

    if (p[5] == 0) {
        p[1] = 0;
        if (p[6] >= 0) {
            e = g_Game_80140C78.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[7] >= 0) {
            e = g_Game_80140C78.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[8] >= 0) {
            e = g_Game_80140C78.f_820C + p[8] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[9] >= 0) {
            e = g_Game_80140C78.f_820C + p[9] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        p[3] = 0;
    } else {
        p[1] = 2;
        if (p[6] >= 0) {
            e = g_Game_80140C78.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[7] >= 0) {
            e = g_Game_80140C78.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        if (p[8] >= 0) {
            e = g_Game_80140C78.f_820C + p[8] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        }
        if (p[9] >= 0) {
            e = g_Game_80140C78.f_820C + p[9] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
        }
        p[3] = 0x400;
        Model_SetTurnAngle_80140C78(p[4], p[10], p[3]);
        Model_SetTurnAngle_80140C78(p[4], p[11], p[3]);
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140EF8 asm("g_Game");
M2C_UNK Sound_PlayFixed(M2C_UNK);

s32 CoralCave_UpdateTurnGate(s16 *p) {
    u8 *e;

    switch (p[1]) {
    case 0:
        e = g_Game_80140EF8.f_820C + p[8] * 0x38;
        if (M2C_FIELD(e, s16 *, 0x1E) >= 0) {
            p[1] = 1;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            e = g_Game_80140EF8.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            p[3] = 0;
            Sound_PlayFixed(0x80);
        }
        break;
    case 1:
        Model_SetTurnAngle_80140C78(p[4], p[10], p[3]);
        Model_SetTurnAngle_80140C78(p[4], p[11], p[3]);
        p[3] += 0x20;
        if (p[3] > 0x400) {
            p[1] = 2;
            e = g_Game_80140EF8.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            e = g_Game_80140EF8.f_820C + p[9] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
        }
        break;
    case 2:
        e = g_Game_80140EF8.f_820C + p[9] * 0x38;
        if (M2C_FIELD(e, s16 *, 0x1E) >= 0) {
            p[1] = 3;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            e = g_Game_80140EF8.f_820C + p[7] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
            p[3] = 0x400;
            Sound_PlayFixed(0x80);
        }
        break;
    case 3:
        Model_SetTurnAngle_80140C78(p[4], p[10], p[3]);
        Model_SetTurnAngle_80140C78(p[4], p[11], p[3]);
        p[3] -= 0x20;
        if (p[3] < 0) {
            p[1] = 0;
            e = g_Game_80140EF8.f_820C + p[6] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
            e = g_Game_80140EF8.f_820C + p[8] * 0x38;
            M2C_FIELD(e, u16 *, 0x18) &= 0x7FFF;
        }
        break;
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
