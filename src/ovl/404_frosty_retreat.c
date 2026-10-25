#include "common.h"
#include "m2c_macros.h"

void Object_PlaySound(void *, s32);

M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_80056128(s32, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_800520A8(void *, M2C_UNK);
s32 Floor_GetHeight(s16, s16, s16);
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D000);

s32 Object_AddAttackSphereNear_8013D0EC(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");

void func_8013D0EC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear_8013D0EC(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern u8 D_80141850[];

void func_8013D144(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        func_80070284(&v, D_80141850, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013D1E0(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 func_8013D210(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013D240(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013D27C(void *arg0) {
    if ((func_8013D210(arg0) == 0) && (func_8013D240(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 func_8013D210(void *arg0);
s32 func_8013D240(void *arg0);
void func_8013D27C(void *arg0);
void func_8013D000(void *);
void func_8013D0EC(void *arg0);
void Object_TurnTowardSpike_8013D2D0(void *) asm("Object_TurnTowardSpike");
void Object_TurnToward_8013D2D0(void *, s16, s16, s32, s32) asm("Object_TurnToward");
s32 func_800572CC_8013D2D0(void *) asm("func_800572CC");
s32 Object_DetachLink_8013D2D0(void *, s32) asm("Object_DetachLink");

void func_8013D2D0(void *arg0) {
    if (func_8013D1E0(arg0)) {
        if (func_8013D210(arg0)) {
            Object_TurnTowardSpike_8013D2D0(arg0);
            M2C_FIELD(arg0, s16 *, 0xA8) = 1;
        } else {
            Object_TurnToward_8013D2D0(arg0, M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24),
                                       M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C), 0,
                                       M2C_FIELD(arg0, s16 *, 0xB0));
            M2C_FIELD(arg0, s16 *, 0xA8) = 0;
            if (func_8013D240(arg0)) {
                M2C_FIELD(arg0, u8 *, 0x80) = 5;
                M2C_FIELD(arg0, u8 *, 0x7F) = 4;
                M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + 0x10);
            }
        }
        if (M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 8) {
            func_8013D000(arg0);
        }
    } else {
        M2C_FIELD(arg0, u16 *, 0x96) += M2C_FIELD(arg0, u16 *, 0xA8);
        func_8013D27C(arg0);
        if (M2C_FIELD(arg0, u8 *, 0xDD) == 0 && func_800572CC_8013D2D0(arg0)) {
            M2C_FIELD(arg0, u8 *, 0xDD) = 1;
        }
    }
    if (Object_DetachLink_8013D2D0(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        func_8005588C(arg0, 0x1E);
    } else {
        func_8013D0EC(arg0);
    }
}

void func_8013D430(s32 arg0) {
    if (func_8013D1E0() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013D474(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013D4B4(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D51C);

typedef struct { u8 pad0[0x5C]; s16 f5C; u8 pad5E[2]; s16 f60, f62, f64, f66; u8 pad68[0x20]; } Mdl_404;
s32 Hook_Add(void *);
void func_8013DB40(void);
extern Mdl_404 D_80141950_s[] asm("D_80141950");

void func_8013D804(void) {
    s32 i;
    Mdl_404 *m;

    if (Hook_Add(func_8013DB40) == 1) {
        for (i = 0; i < 16; i++) {
            m = &D_80141950_s[i];
            func_80052038(m, 0x40);
            func_800520A8(m, 0x40);
            m->f5C = 0;
            m->f62 = 0;
            m->f60 = 0;
            m->f64 = 0x1000;
            m->f66 = 3;
        }
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013D89C);

typedef struct { s16 x, y, z; } Rot_404;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 wx, wy, wz; Rot_404 r; u8 pad82; u8 life; s16 scale; s16 floor; } Debris_404;
extern Debris_404 D_80141950[16];
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game;
extern u8 D_800E7D00_8013DB40[] asm("D_800E7D00");
s32 func_80051410(void *, s32, s32);
void RotMatrixYXZ(void *, void *);
void ScaleMatrix_8013DB40(void *, void *) asm("ScaleMatrix");
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80016EBC(void *, void *, void *);

void func_8013DB40(void) {
    s32 i;
    Debris_404 *d;
    s32 s[3];
    SVECTOR v;

    for (i = 0; i < 16; i++) {
        d = &D_80141950[i];
        if (d->life != 0) {
            d->life--;
            d->x += d->vx;
            d->y += d->vy;
            d->z += d->vz;
            d->vy += 7;
            if (d->floor < d->y) {
                d->y = d->floor;
                d->vy = -(d->vy / 2);
                v.vx = d->x;
                v.vy = d->y;
                v.vz = d->z;
            }
            d->r.x = (d->r.x + d->wx) % 4096;
            d->r.y = (d->r.y + d->wy) % 4096;
            d->r.z = (d->r.z + d->wz) % 4096;
            if (func_80051410(&d->x, 0, 0) == 0) {
                RotMatrixYXZ(&d->r, d->mat);
                s[0] = s[1] = s[2] = d->scale;
                ScaleMatrix_8013DB40(d->mat, s);
                func_80015780(d, 3);
                Model_ProjectBonedVerts(d);
                func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, D_800E7D00_8013DB40, d);
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013DD40);

void func_8013DF78(void *arg0, void *arg1, M2C_UNK arg2) {
    func_80052038(arg1, arg2);
    func_800520A8(arg1, arg2);
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
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern u8 D_80142270[];

void func_8013E018(s32 arg0, s32 arg1) {
    s32 v[3];
    u8 *m;

    m = D_80142270 + arg0 * 0x70;
    if (func_80051410(m + 0x24, 0, 0) == 0) {
        v[0] = v[1] = v[2] = arg1 << 8;
        Matrix_FromDirection(m + 0x60, M2C_FIELD(m, s32 *, 0x14));
        ScaleMatrix(M2C_FIELD(m, s32 *, 0x14), v);
        func_80015780(m, 3);
        Model_ProjectBonedVerts(m);
        func_80016EBC(g_Game.f_80 + g_Game.f_C * 0x4078, &D_800E7D00, m);
    }
}

typedef struct { u8 pad0[0xC]; s16 active; u8 padE[6]; } Drip_404;
extern Drip_404 D_801421D0_s[8] asm("D_801421D0");

void func_8013E0E0(void *arg0) {
    s32 i;

    func_8013DF78(arg0, D_80142270, 0x83);
    for (i = 7; i >= 0; i--) {
        D_801421D0_s[i].active = 0;
    }
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_396;
extern Drip_396 D_8013F2A0_s[8] asm("D_801421D0");

s32 func_8013E128(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (D_8013F2A0_s[i].active == 0) {
            return i;
        }
    }
    return -1;
}

typedef struct { s16 x, y, z, vx, vy, vz, active, unkE; s32 unk10; } Drip_8013E164;
extern Drip_8013E164 D_801421D0_8013E164[8] asm("D_801421D0");
s32 func_8013E128(void);

M2C_UNK func_8013E164(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 i;
    Drip_8013E164 *p;
    s16 c;
    s16 s;

    i = func_8013E128();
    if (i != -1) {
        p = &D_801421D0_8013E164[i];
        c = rcos(M2C_FIELD(arg0, s16 *, 0xAC));
        s = rsin(M2C_FIELD(arg0, s16 *, 0xAC));
        p->x = M2C_FIELD(arg0, s16 *, 0x24) + ((c * (s16)arg2) >> 12);
        p->y = M2C_FIELD(arg0, s16 *, 0x28) - arg1;
        p->z = M2C_FIELD(arg0, s16 *, 0x2C) + ((s * (s16)arg2) >> 12);
        p->vx = c / 48;
        p->vz = s / 48;
        p->vy = -40;
        p->active++;
        p->unkE = M2C_FIELD(arg0, s8 *, 0xCB);
        Object_PlaySound(arg0, 0x77);
    }
}

s32 func_8013E2A4(void *arg0) {
    return Floor_GetHeight(M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4)) < M2C_FIELD(arg0, s16 *, 2);
}

void Effect_SpawnAt(s32, SVECTOR *);

void func_8013E2E0(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(4, &v);
}

void func_8013E320(SVECTOR *arg0) {
    SVECTOR v;

    v.vx = arg0->vx;
    v.vy = arg0->vy;
    v.vz = arg0->vz;
    Effect_SpawnAt(0x102, &v);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E360);

void Object_SpawnEffect(void *, s32, s32, s32, s32);

void func_8013E528(void *arg0) {
    Object_SpawnEffect(arg0, 0x106, 0, 0, 0);
}

void func_800573A0(void *, s32, s32, s32);

void func_8013E554(void *arg0) {
    if ((M2C_FIELD(arg0, u32 *, 0x50) >> 28) == 0xB && !((M2C_FIELD(arg0, u32 *, 0xE0) >> 1) & 1)) {
        M2C_FIELD(arg0, u8 *, 0xCE) = M2C_FIELD(arg0, u8 *, 0x7F);
        M2C_FIELD(arg0, u8 *, 0x7F) = M2C_FIELD(arg0, u8 *, 0xCD);
        M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));
        func_800573A0(arg0, 0, 0, 0);
        func_800525E0(arg0);
        func_80052864(arg0);
    }
}

void Object_TurnToward(void *, s16, s16, s32, s32);
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike;

void func_8013E5E4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, s16 *, 0x94) = 0;
    func_8013E528(arg0);
    Object_TurnToward(arg0, g_Spike.x - M2C_FIELD(arg0, u16 *, 0x24), g_Spike.z - M2C_FIELD(arg0, u16 *, 0x2C), 0, 0x1000);
}


void func_8013E674(void *obj) {
    func_8013E164(obj, 0x46, 0xA0);
}

void Object_DisableCollision(void *);

void func_8013E698(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    M2C_FIELD(arg0, s16 *, 0x4A) = -0x7EFD;
    M2C_FIELD(arg0, u8 *, 0x7D) = 8;
    M2C_FIELD(arg0, u8 *, 0xC8) = 0xE;
    M2C_FIELD(arg0, u8 *, 0xCD) = 5;
    M2C_FIELD(arg0, u8 *, 0x7F) = 1;
    M2C_FIELD(arg0, u8 *, 0xDC) = 5;
    M2C_FIELD(arg0, s16 *, 0xA0) = 0;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
    M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x88), u16 *, 4);
    func_8005588C(arg0, (s16)(M2C_FIELD(arg0, s16 *, 0x9A) % 60) + 0x3C);
    func_8013E0E0(arg0);
    Object_DisableCollision(arg0);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013E778);

void func_8013EC60(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013ECA0(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013ECE4(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013ED60);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013EF7C);

s32 Math_Atan2(s32, s32);

void func_8013F0EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013F178(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_8013F1B0(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

s32 Object_AddAttackSphereNear_8013F278(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
s32 Object_DetachLink_8013F278(void *, s32) asm("Object_DetachLink");
void Object_PlaySound_8013F278(void *, s32) asm("Object_PlaySound");
void Object_ApplyVelocity_8013F278(void *) asm("Object_ApplyVelocity");
s32 func_80055718_8013F278(void *, s16, s16, s16, s32) asm("func_80055718");
s32 Object_StepGrowShrink_8013F278(void *, s16, s16, s16) asm("Object_StepGrowShrink");
void func_8013F0EC(void *arg0);

void func_8013F278(u8 *a) {
    s16 *v;

    if (Object_DetachLink_8013F278(a, 0) == 6) {
        Object_PlaySound_8013F278(a, 0x5F);
        func_8013F0EC(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink_8013F278(a, 0x53, 0x37, 0);
    }
    if (func_80055718_8013F278(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        func_8013F0EC(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity_8013F278(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear_8013F278(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F39C asm("g_Spike");

void func_8013F39C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F39C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F39C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F39C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void func_8013F3EC(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x200000;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x96) >= 0x39) {
        M2C_FIELD(arg0, u8 *, 0x82) = 0;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x100000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013F460);

extern struct { u32 f_0; } g_Game_8013F7F8 asm("g_Game");
extern u16 g_RandSeed;
void func_80052038_8013F7F8(void *, s32) asm("func_80052038");
void Puff_Spawn(void *, s32, s32, s32);
s32 Spike_WithinRadiusXZ_8013F7F8(s32, s32, s32) asm("Spike_WithinRadiusXZ");

void func_8013F7F8(u8 *o, s32 a) {
    if (a) {
        func_80052038_8013F7F8(o, 0x12);
    } else {
        func_80052038_8013F7F8(o, 0xA7);
    }
    Puff_Spawn(o + 0x24, 1, 0, 200);
    if (Spike_WithinRadiusXZ_8013F7F8(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x2C), 0x600)) {
        if (g_Game_8013F7F8.f_0 % 5 == 0 || (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) == 0) {
            Object_PlaySound(o, 0x5B);
        }
    }
}

extern s32 D_800EC208;
extern s32 D_801422E0;
s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013F8BC(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA6)) == 0) {
        var_v0 = D_800EC208 >= D_801422E0;
    }
    return var_v0;
}

extern s32 D_800EC204;
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013F91C asm("g_Spike");

s32 func_8013F91C(u8 *o, s32 r) {
    s32 ret = 0;

    if (ABS(D_800EC204 - M2C_FIELD(o, s32 *, 0x24)) < r
        && ABS(g_Spike_8013F91C.y - M2C_FIELD(o, s32 *, 0x28) + 0xD7) < r
        && ABS(g_Spike_8013F91C.z - M2C_FIELD(o, s32 *, 0x2C)) < r) {
        ret = 1;
    }
    return ret;
}

extern u16 g_RandSeed;

void func_8013F9D4(void *arg0) {
    u16 temp_a1;

    M2C_FIELD(arg0, s8 *, 0x80) = 1;
    temp_a1 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_a1;
    func_8005588C(arg0, ((u32) (temp_a1 & 0xFFFF) >> 9) + 0x40);
}

void func_8013FA20(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x10000);
}

s32 func_8013FA40(s32 x) {
    if (x == 0) {
        return 0;
    }
    if (x > 0) {
        return 1;
    }
    return -1;
}

void func_8013FA60(s16 *p, s32 lim) {
    if (*p > 0) {
        *p -= 5;
        if (*p > lim) {
            *p = lim;
        }
    } else if (*p < 0) {
        *p += 5;
        if (*p < -lim) {
            *p = -lim;
        }
    }
}

void func_8013FAB8(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xD4) = (u16) (M2C_FIELD(arg0, u16 *, 0xD4) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s16 *, 0xBC)) * 0xA));
    M2C_FIELD(arg0, u16 *, 0xD6) = (u16) (M2C_FIELD(arg0, u16 *, 0xD6) + (func_8013FA40(M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s16 *, 0xC0)) * 0xA));
    func_8013FA60(arg0 + 0xD4, 0x17C);
    func_8013FA60(arg0 + 0xD6, 0x17C);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (u16) M2C_FIELD(arg0, s32 *, 0x2C);
}

M2C_UNK Object_ApplyVelocity(void *);
s32 Object_WouldLeaveHome(void *, M2C_UNK);
s32 Object_StepGrowShrink(void *, s16, s16, s16);

void func_8013FB54(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink(arg0, 0x1E, 0x14, 0);
    }
    func_80055718(arg0, arg1, arg2, arg3, (s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13);
    if (Object_WouldLeaveHome(arg0, 0) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

void func_8013FC04(void *arg0) {
    if (func_80055718(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9C), M2C_FIELD(arg0, s16 *, 0x9E), 0xA) == 0) {
        Object_ApplyVelocity(arg0);
    }
}

s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);
u32 Object_DetachLink(void *, s32);

void func_8013FC4C(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 0xE0) & 1)) {
        if (Object_DetachLink(arg0, 0) == 6) {
            M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xC8, M2C_FIELD(arg0, s16 *, 0x24), (s16) (M2C_FIELD(arg0, u16 *, 0x28) - 0xD7), (s32) M2C_FIELD(arg0, s16 *, 0x2C), 0x401, 0x202);
    }
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8013FCE0);

typedef struct { s16 f0; s16 x, y, z; s16 f8; u16 fA; u8 padC[4]; } Src_8013FFC8;
typedef struct { s16 x, y, z, floor; s16 x8, yA, zC; u8 fE; u8 padF[9]; s16 f18; s16 f1A; u8 pad1C[4]; } Pt_8013FFC8;
extern struct { u8 pad0[0x824C]; u8 *f_824C; } g_Game_8013FFC8 asm("g_Game");
extern u8 D_801426E8;
extern Pt_8013FFC8 D_801422E8[];
s32 Floor_GetHeight_8013FFC8(s32, s32, s32) asm("Floor_GetHeight");

s32 func_8013FFC8(void) {
    u8 *h;
    Src_8013FFC8 *src;
    s32 i;

    h = g_Game_8013FFC8.f_824C;
    D_801426E8 = 0;
    src = (Src_8013FFC8 *)(h + 8);
    if (*(u16 *)h == 0x452E && h[2] == 0x46) {
    } else {
        return 1;
    }
    D_801426E8 = h[4];
    if (D_801426E8 > 32) {
        D_801426E8 = 32;
    }
    for (i = 0; i < D_801426E8; i++) {
        D_801422E8[i].fE = 0;
        D_801422E8[i].x8 = D_801422E8[i].x = src[i].x;
        D_801422E8[i].yA = D_801422E8[i].y = src[i].y;
        D_801422E8[i].zC = D_801422E8[i].z = src[i].z;
        D_801422E8[i].floor = Floor_GetHeight_8013FFC8(src[i].x, src[i].y + 0x200, src[i].z);
        if (D_801422E8[i].floor < src[i].y) {
            D_801422E8[i].floor = Floor_GetHeight_8013FFC8(src[i].x, src[i].y + 0x1000, src[i].z);
        }
        D_801422E8[i].f18 = 1;
        D_801422E8[i].f1A = src[i].fA;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140124);

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140738 asm("g_Game");
void Sound_PlayAt_80140738(s32, void *) asm("Sound_PlayAt");
s32 ShockBox_Update(s32, void *, s32);

s32 func_80140738(s16 *p) {
    s16 *e = (s16 *)(g_Game_80140738.f_820C + p[2] * 0x38);
    s16 b[6];

    e[0xC] |= 0x8000;
    if (e[0x11] == 100) {
        Sound_PlayAt_80140738(0xB7, e);
    }
    if (p[4] >= 0) {
        if (p[4] < 2) {
            if (e[3] < 0x40) {
                return 0;
            }
        } else if (p[4] < 4) {
            if (e[5] < 0x40) {
                return 0;
            }
        }
    }
    b[0] = e[0];
    b[1] = e[1] + 0x20;
    b[2] = e[2];
    b[3] = e[3] + 0x60;
    b[4] = e[4] + 0x40;
    b[5] = e[5] + 0x60;
    ShockBox_Update(p[4], b, 0x80);
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140864 asm("g_Game");
extern u8 *D_800B4D64_80140864 asm("D_800B4D64");

s32 func_80140864(s16 *p) {
    u8 *e = g_Game_80140864.f_820C + p[2] * 0x38;

    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        **(u32 **)(D_800B4D64_80140864 + M2C_FIELD(e, s16 *, 0xE) * 32) |= 0x2000;
    }
    M2C_FIELD(e, u16 *, 0x32) = M2C_FIELD(e, u16 *, 6);
    M2C_FIELD(e, u16 *, 0x34) = M2C_FIELD(e, u16 *, 8);
    M2C_FIELD(e, u16 *, 0x36) = M2C_FIELD(e, u16 *, 0xA);
    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 2;
        p[3] = 0x1000;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_8014090C);

INCLUDE_ASM("asm/ovl/404/nonmatchings/404_frosty_retreat", func_80140AFC);

typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[4]; s16 f10; } Scr_8014163C;
extern u8 *D_800B4DC4;
extern SVECTOR D_800F4B30[3];
extern struct { s32 f0; u8 pad4[4]; s32 f8; } g_Game_8014163C asm("g_Game");
extern u8 D_800E7D00_8014163C[] asm("D_800E7D00");
s32 Floor_GetHeight_8014163C(s32, s32, s32) asm("Floor_GetHeight");
s32 Water_Query(s32, s32, s32);
s32 rsin_8014163C(s32) asm("rsin");
void func_80014804(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void func_80017CD4_8014163C(s32, void *, void *) asm("func_80017CD4");

void func_8014163C(void) {
    u8 *o;
    s32 fl;
    s32 lvl;
    s32 y;

    o = D_800B4DC4;
    fl = Floor_GetHeight_8014163C(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C));
    if (((Water_Query(M2C_FIELD(o, s32 *, 0x24), M2C_FIELD(o, s32 *, 0x28), M2C_FIELD(o, s32 *, 0x2C)) & 0xFFFF) >> 12) == 1) {
        lvl = ((Scr_8014163C *)0x1F8003D4)->fA - ((Scr_8014163C *)0x1F8003D4)->f10;
        if (M2C_FIELD(o, s32 *, 0x28) - lvl > 0x20) {
            M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s32 *, 0x28) - 12;
        } else {
            M2C_FIELD(o, s32 *, 0x28) = lvl + 0x20;
        }
        M2C_FIELD(o, u16 *, 0x78) = M2C_FIELD(o, u16 *, 0x24);
        M2C_FIELD(o, u16 *, 0x7A) = M2C_FIELD(o, u16 *, 0x28);
        M2C_FIELD(o, u16 *, 0x7C) = M2C_FIELD(o, u16 *, 0x2C);
    } else if (M2C_FIELD(o, s32 *, 0x28) >= fl) {
        M2C_FIELD(o, s32 *, 0x24) = M2C_FIELD(o, s16 *, 0x78);
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x7A);
        M2C_FIELD(o, s32 *, 0x2C) = M2C_FIELD(o, s16 *, 0x7C);
    }
    func_80014804((s16 *)(o + 0x60), M2C_FIELD(o, s16 **, 0x14));
    y = M2C_FIELD(o, s32 *, 0x28);
    M2C_FIELD(o, s32 *, 0x28) += rsin_8014163C(g_Game_8014163C.f0 << 6) >> 9;
    D_800F4B30[0].vx = 0;
    D_800F4B30[0].vy = 0x800;
    D_800F4B30[0].vz = 0;
    D_800F4B30[1].vx = 0x400;
    D_800F4B30[1].vy = 0;
    D_800F4B30[1].vz = -0x480;
    D_800F4B30[2].vx = 0x400;
    D_800F4B30[2].vy = 0;
    D_800F4B30[2].vz = -0x380;
    Model_CalcJointMatrices(o, 1);
    Model_ProjectBonedVerts(o);
    func_80017CD4_8014163C(g_Game_8014163C.f8, D_800E7D00_8014163C, o);
    M2C_FIELD(o, s32 *, 0x28) = y;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop\n\tnop");
