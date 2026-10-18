#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 pad0[0x10]; s32 f_10; u8 pad14[0x12]; u8 f_26; u8 f_27; u8 pad28[0xA]; s16 f_32; } S_84C04_80084C04;
typedef struct { u8 pad0[0x10]; void *f_10; u8 pad14[0x12]; u8 f_26; u8 f_27; u8 pad28[0xA]; s16 f_32; } E_80084C04_80084C04;
typedef struct { s16 vx, vy, vz, pad; } SV_84C94_80084C94;
typedef struct { s32 x, y, z; u8 padC[0xC]; SV_84C94_80084C94 n; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; u8 pad28[4]; u32 f_2C; } Col_84C94_80084C94;
typedef struct { u8 pad0[0xA]; u16 f_A; u8 padC[4]; u16 f_10; } SCR_84C94_80084C94;

extern struct S_D_800F5380 { u8 f_0; u8 f_1; u8 f_2; u8 f_3; s32 f_4; s32 f_8; s32 f_C; u8 pad10[0x16]; u8 f_26; u8 f_27; u8 pad28[2]; s16 f_2A; s16 f_2C; u8 pad2E[2]; s16 f_30; u8 pad32[2]; } D_800F5380[];

extern M2C_UNK D_800B2950;

void Projectile_UpdateAll(void);
M2C_UNK func_800856FC();
void Effect_HitCallback(E_80084C04_80084C04 *e, s32 kind);
void Effect_SpawnAt(s32, s32);
void Sound_PlayAt(s32, s32);
void func_80085230(void);
struct S_D_800F5380_80084A60 { u8 f_0; u8 pad[0x33]; };
extern u8 D_800B1B78[][8];
void Projectile_End(void *arg0, s32 kind);
void Sound_PlayFixed(s32);
s32 Water_Query(s32, s32, s32);
void memset(void *, s32, s32);
Col_84C94_80084C94 *CollShape_Alloc(void);
void Collision_Set(s32, void *, s32);
void func_8006F3D0(SV_84C94_80084C94 *, s32, void *, s32);
struct S_D_800F5380_80084C94 { u8 state; u8 f_1; u8 life; u8 f_3; void *cb; s32 f_8; Col_84C94_80084C94 *col; SV_84C94_80084C94 *pos; SV_84C94_80084C94 dir; s16 vx; s16 vy; s16 vz; s8 grav; u8 f_23; u8 f_24; u8 f_25; u8 f_26; u8 f_27; u16 water; s16 f_2A; s16 f_2C; u8 pad2E[2]; s16 f_30; s16 f_32; };

void Projectile_InitAll(void) {
    s32 i;
    for (i = 31; i >= 0; i--) {
        ((struct S_D_800F5380_80084A60 *)&D_800F5380)[i].f_0 = 0;
    }
    func_80085230();
}

void Projectile_Frame(void) {
    Projectile_UpdateAll();
    func_800856FC();
}

struct S_D_800F5380 *Projectile_Alloc(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_800F5380[i].f_0 == 0) {
            struct S_D_800F5380 *p = &D_800F5380[i];
            p->f_4 = 0;
            p->f_1 = 0;
            p->f_2 = 0x80;
            p->f_3 = 0;
            p->f_0 = 3;
            p->f_8 = 0;
            p->f_C = 0;
            p->f_2A = 1;
            p->f_2C = 0x200;
            p->f_30 = 0x40;
            p->f_27 = 0xFF;
            p->f_26 = 0xFF;
            return p;
        }
    }
    return 0;
}

void func_80084B48(void *arg0, s32 arg1, void *arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 1) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, u16 *, 0x1C) = (u16) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0x20) = (u16) M2C_FIELD(arg2, u16 *, 4);
}

void func_80084B74(void *arg0, s32 arg1)
{
  u8 *new_var;
  void *temp_v0;
  *((u8 *) (((s8 *) arg0) + 1)) = (u8) ((*((u8 *) (((s8 *) arg0) + 1))) | 0x10);
  new_var = (u8 *) (&D_800B2950);
  temp_v0 = (void *) (new_var + (arg1 * 3));
  *((u8 *) (((s8 *) arg0) + 0x23)) = (u8) (*((u8 *) (((s8 *) temp_v0) + 0)));
  *((u8 *) (((s8 *) arg0) + 0x24)) = (u8) (*((u8 *) (((s8 *) temp_v0) + 1)));
  *((u8 *) (((s8 *) arg0) + 0x25)) = (u8) (*((u8 *) (((s8 *) temp_v0) + 2)));
}

void func_80084BB8(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 2) = arg1;
}

void Projectile_End(void *arg0, s32 kind) {
    M2C_UNK (*temp_v0)();

    temp_v0 = M2C_FIELD(arg0, M2C_UNK (**)(), 4);
    if (temp_v0 != NULL) {
        temp_v0();
    }
    M2C_FIELD(arg0, s8 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

/* Hit callback (installed at +4 by the effect's init): unless kind is 2, spawns effect +0x32 at
 * the position +0x10 and plays sound +0x26 (kind 0) or +0x27 (0xFF = none). The duplicated call
 * in the if/else is a permuter find that reproduces the original register use. */
void Effect_HitCallback(E_80084C04_80084C04 *e, s32 kind) {
    s32 snd;
    if (kind == 2) {
        return;
    }
    if (e || snd) {
        Effect_SpawnAt(e->f_32, e->f_10);
    } else {
        Effect_SpawnAt(e->f_32, e->f_10);
    }
    if (kind == 0) {
        snd = (*e).f_26;
    } else {
        snd = e->f_27;
    }
    if (snd != 0xFF) {
        Sound_PlayAt(snd, e->f_10);
    }
}

void func_80084C78(void *arg0, s16 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, M2C_UNK **, 4) = &Effect_HitCallback;
    M2C_FIELD(arg0, s16 *, 0x32) = arg1;
    M2C_FIELD(arg0, s8 *, 0x26) = arg2;
    M2C_FIELD(arg0, s8 *, 0x27) = arg3;
}

/* Updates the 32 projectiles at D_800F5380. Each has a lifetime (+2), a collision box (+0xC)
 * whose last hit kind ends it (6/0xB) or bounces it (10: flags +1 & 0x60 pick the bounce),
 * a splash and halved speed on entering water, movement by +0x1C with gravity +0x22 when
 * (+1 & 0xF) == 1, and an optional trail effect (+1 & 0x10). */
void Projectile_UpdateAll(void) {
    SCR_84C94_80084C94 *sc;
    s32 i;
    struct S_D_800F5380_80084C94 *p;
    SV_84C94_80084C94 *pos;
    s32 w;
    u32 k;
    SV_84C94_80084C94 b;
    SV_84C94_80084C94 a;
    SV_84C94_80084C94 t;
    SV_84C94_80084C94 q;

    for (i = 0, sc = (SCR_84C94_80084C94 *)0x1F8003D4; i < 32; i++) {
        p = &((struct S_D_800F5380_80084C94 *)&D_800F5380)[i];
        if (p->state == 0) {
            continue;
        }
        if ((u8)(p->state - 1) < 2) {
            p->state = 0;
            continue;
        }
        if (--p->life == 0) {
            Projectile_End(p, 2);
            p->state = 2;
            continue;
        }
        if (p->col != 0) {
            k = p->col->f_2C >> 28;
            if (k == 6 || k == 0xB) {
                Projectile_End(p, 0);
                continue;
            }
            if (k == 10) {
                if (!(p->f_1 & 0x60)) {
                    p->pos->vx -= p->vx;
                    p->pos->vy -= p->vy;
                    p->pos->vz -= p->vz;
                    Projectile_End(p, 1);
                    continue;
                }
                if (p->vy > 0) {
                    if ((p->f_1 & 0x60) == 0x20) {
                        p->vy = (p->vy - p->vy * 8) / 8;
                    } else {
                        p->vy = -p->vy / 2;
                        p->vx = p->vx / 2;
                        p->vz = p->vz / 2;
                    }
                }
                if (-p->grav < p->vy) {
                    Projectile_End(p, 1);
                    continue;
                }
                if (p->vy < -0x14) {
                    Sound_PlayFixed(0x51);
                    Effect_SpawnAt(4, p->pos);
                }
            }
        }
        pos = p->pos;
        w = Water_Query(pos->vx, pos->vy, pos->vz);
        if (((u16)w >> 12) == 1 && (p->water >> 12) != 1) {
            memset(&a, 0, 8);
            a.vx = pos->vx;
            a.vy = sc->f_A - sc->f_10;
            a.vz = pos->vz;
            b = a;
            Effect_SpawnAt(0x100, &b);
            p->vx = p->vx / 2;
            p->vy = p->vy / 2;
            p->vz = p->vz / 2;
            Sound_PlayFixed(0x72);
        }
        p->water = w;
        switch (p->f_1 & 0xF) {
        case 0:
        default:
            pos->vx += p->vx;
            pos->vy += p->vy;
            pos->vz += p->vz;
            break;
        case 1:
            pos->vx += p->vx;
            pos->vy += p->vy;
            pos->vz += p->vz;
            p->vy += p->grav;
            break;
        }
        p->dir.vx = p->vx;
        p->dir.vy = p->vy;
        p->dir.vz = p->vz;
        VectorNormalSS(&p->dir, &p->dir);
        if ((p->col = CollShape_Alloc()) != 0) {
            p->col->n = p->dir;
            p->col->x = pos->vx;
            p->col->y = pos->vy;
            p->col->z = pos->vz;
            p->col->f_20 = p->f_30;
            p->col->f_24 = p->f_2A;
            p->col->f_26 = p->f_2C;
            Collision_Set(7, p->col, p->f_8);
        }
        if (p->f_1 & 0x10) {
            q = *pos;
            VectorNormalSS(&p->vx, &t);
            t.vx = pos->vx + (-t.vx * p->f_25 >> 8);
            t.vy = pos->vy + (-t.vy * p->f_25 >> 8);
            t.vz = pos->vz + (-t.vz * p->f_25 >> 8);
            func_8006F3D0(&t, 2, D_800B1B78[p->f_23], p->f_24);
        }
    }
}
