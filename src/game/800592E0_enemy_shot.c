#include "common.h"
#include "m2c_macros.h"
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
typedef struct { s16 vx, vy, vz, pad; } SV_59FA4_80059FA4;
typedef struct { u8 pad0[0x2C]; u32 f_2C; } Col_59FA4_80059FA4;
typedef struct { u8 pad0[0x24]; s32 x, y, z; s32 vx, vy, vz; } Spk_59FA4_80059FA4;

M2C_UNK EnemyShot_DrawAll();
void EnemyShot_UpdateAll(void);
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; } g_Game;

extern M2C_UNK D_800B8D30;

M2C_UNK Collision_Set(M2C_UNK, s32 *, s32);
s32 *CollShape_Alloc();
struct Game_59FA4 { u8 pad0[0x8296]; s16 f_8296; };
extern Spk_59FA4_80059FA4 g_Spike;
extern u16 g_RandSeed;
void Effect_SpawnAt(s32, void *);
void EnemyShot_SetHitbox(void *arg0, s16 arg1, s16 arg2, s16 arg3);
s16 Floor_GetHeight(s32, s32, s32);
void Sound_PlayFixed(s32);
void Camera_StartShake(s32);
void memset(void *, s32, s32);
void VectorNormalSS(void *, void *);
s32 SquareRoot0(s32);
struct S_D_800B8D30_80059FA4 { Col_59FA4_80059FA4 *col; s32 f_4; u8 *obj; u8 state; u8 f_D; u8 delay; u8 f_F; u8 f_10; u8 f_11; u8 f_12; u8 hidden; u8 f_14; u8 f_15; u8 pad16[6]; SV_59FA4_80059FA4 pos; s16 vx; s16 vy; s16 vz; s16 ground; u8 pad2C[2]; u16 timer; };

void EnemyShot_InitAll(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0xF;
    var_v0 = &D_800B8D30;
    do {
        M2C_FIELD(var_v0, s8 *, 0xC) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x30));
    } while (var_v1 >= 0);
}

typedef struct { s16 vx, vy, vz, pad; } SV_59304;
typedef struct { s16 x, y, z; } P3_59304;
typedef struct { u8 pad0[8]; s32 f_8; u8 padC[0x16]; u8 f_22; u8 pad23[7]; s16 f_2A; } Proj_59304;
typedef struct { SV_59304 v; u8 f_8; u8 f_9; u8 padA[2]; } Aim_59304;
typedef struct { void *col; s32 f_4; Proj_59304 *obj; u8 state; u8 f_D; u8 delay; u8 f_F; u8 f_10; u8 f_11; u8 f_12; u8 hidden; u8 f_14; u8 f_15; u8 f_16; u8 f_17; u16 f_18; u16 f_1A; SV_59304 pos; s16 vx; s16 vy; s16 vz; s16 ground; u8 pad2C[2]; u16 timer; } Shot_59304;
extern Shot_59304 D_800B8D30_59304[] asm("D_800B8D30");
extern Aim_59304 D_800AF800[];
void func_80014804(void *, void *);
void ApplyMatrixSV(void *, void *, void *);
Proj_59304 *Projectile_Alloc(void);
void func_80084BB8(Proj_59304 *, s32);
void func_80084B48(Proj_59304 *, SV_59304 *, SV_59304 *, s32);
void func_80084B74(Proj_59304 *, s32);
void func_80084C78(Proj_59304 *, s32, s32, s32);

s32 func_80059304(P3_59304 *p, s32 owner, s32 type, s32 arg) {
    Shot_59304 *s;
    s32 i;
    s32 n;
    s16 h;
    SV_59304 v6;
    u8 mat[0x20];
    SV_59304 d;
    SV_59304 tmp;
    Aim_59304 *t;
    s32 a;
    s16 a16;
    s32 q;
    s32 k;
    s32 k2;
    s32 fx;

    if (type == 6) {
        n = 0;
        for (i = 15, s = D_800B8D30_59304; i >= 0; i--, s++) {
            if (s->state == 6) {
                n++;
            }
        }
        if (n >= 4) {
            return 1;
        }
    }
    h = Floor_GetHeight(p->x, p->y, p->z);
    for (i = 15, s = D_800B8D30_59304; i >= 0; i--, s++) {
        if (s->state != 0) {
            continue;
        }
        s->timer = 0;
        s->col = 0;
        s->f_4 = owner;
        s->pos.vx = p->x;
        s->pos.vy = p->y;
        s->pos.vz = p->z;
        s->f_12 = 1;
        s->f_D = 0;
        s->ground = h;
        s->f_11 = 0;
        s->hidden = 0;
        s->pos.pad = 0;
        s->delay = 0;
        s->f_F = 0;
        switch (type) {
        case 6:
            k = arg;
            if ((u8)k >= 5) {
                k = 0;
            }
            v6.vx = g_Spike.x - p->x;
            v6.vy = 0;
            v6.vz = g_Spike.z - p->z;
            t = &D_800AF800[(u8)k];
            VectorNormalSS(&v6, &v6);
            func_80014804(&v6, mat);
            ApplyMatrixSV(mat, t, &v6);
            s->vx = v6.vx;
            s->vy = v6.vy;
            s->vz = v6.vz;
            s->delay = t->f_8;
            s->f_D = t->f_9;
            s->f_10 = 1;
            Sound_PlayFixed(0x4C);
            s->state = type;
            goto done;
        case 7:
            s->f_10 = 3;
            q = (g_Spike.y - p->y) / 3;
            if ((s16)q < -0x400) {
                a16 = -0x400;
            } else if ((s16)q > 0x400) {
                a16 = 0x400;
            } else {
                a16 = q;
            }
            d.vx = g_Spike.x + g_Spike.vx * 16 - p->x;
            d.vy = 0;
            d.vz = g_Spike.z + g_Spike.vz * 16 - p->z;
            d.vx = d.vx * (0x400 - a16) >> 10;
            d.vz = d.vz * (0x400 - a16) >> 10;
            s->vx = d.vx / 24;
            s->vz = d.vz / 24;
            s->vy = -0x30;
            break;
        case 8:
            s->f_10 = 4;
            memset(&tmp, 0, 8);
            tmp.vx = g_Spike.x - p->x;
            tmp.vz = g_Spike.z - p->z;
            d = tmp;
            s->vx = d.vx / 128;
            s->vz = d.vz / 128;
            s->vy = -6;
            break;
        case 9:
            s->f_10 = 4;
            memset(&tmp, 0, 8);
            tmp.vx = g_Spike.x - p->x;
            tmp.vz = g_Spike.z - p->z;
            d = tmp;
            s->vx = d.vx / 32;
            s->vz = d.vz / 32;
            s->vy = -15;
            break;
        case 5:
            s->vy = -0x14;
            s->f_1A = 0x5B;
            s->f_18 = 0x7CAD;
            s->f_12 = 3;
            s->vx = 0;
            s->vz = 0;
            s->f_16 = 0x1F;
            s->f_17 = 0x1F;
            break;
        case 1:
            d.vx = ((SV_59304 *)arg)->vx;
            d.vy = ((SV_59304 *)arg)->vy;
            d.vz = ((SV_59304 *)arg)->vz;
            if ((s->obj = Projectile_Alloc()) == 0) {
                return 1;
            }
            func_80084BB8(s->obj, 0x38);
            func_80084B48(s->obj, &s->pos, &d, 0);
            func_80084B74(s->obj, 1);
            func_80084C78(s->obj, 0x10A, 0x6B, 0x59);
            fx = 0x10B;
            goto spawn;
        case 10:
            s->f_10 = 12;
            memset(&tmp, 0, 8);
            tmp.vx = g_Spike.x - s->pos.vx;
            tmp.vz = g_Spike.z - s->pos.vz;
            d = tmp;
            VectorNormalSS(&d, &d);
            switch (arg) {
            case 0:
            default:
                d.vx /= 128;
                { s32 t = d.vz; if (t < 0) t += 127; k2 = 0x21; d.vz = t >> 7; }
                break;
            case 1:
                d.vx /= 128;
                { s32 t = d.vz; if (t < 0) t += 127; k2 = 0x41; d.vz = t >> 7; }
                break;
            }
            d.vy = 0x2E;
            __asm__ volatile("");
            s->vx = d.vx;
            s->vy = d.vy;
            s->vz = d.vz;
            if ((s->obj = Projectile_Alloc()) == 0) {
                return 1;
            }
            func_80084B48(s->obj, &s->pos, &d, k2);
            s->obj->f_8 = s->f_4;
            s->obj->f_22 = 8;
            s->obj->f_2A = 0xC01;
            break;
        case 2:
            tmp.vx = ((SV_59304 *)arg)->vx;
            tmp.vy = ((SV_59304 *)arg)->vy;
            tmp.vz = ((SV_59304 *)arg)->vz;
            if ((s->obj = Projectile_Alloc()) == 0) {
                return 1;
            }
            func_80084B48(s->obj, &s->pos, &tmp, 0);
            func_80084B74(s->obj, 2);
            func_80084C78(s->obj, 0x112, 0x5A, 0xFF);
            fx = 0x118;
        spawn:
            s->obj->f_8 = s->f_4;
            Effect_SpawnAt(fx, &s->pos);
            s->state = type;
            goto done;
        case 3:
        case 4:
            s->vx = 0;
            s->vy = 0;
            s->vz = 0;
            break;
        }
        s->state = type;
    done:
        return 0;
    }
    return 1;
}



void EnemyShot_SetHitbox(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 *temp_v0;

    temp_v0 = CollShape_Alloc();
    M2C_FIELD(arg0, s32 **, 0) = temp_v0;
    if (temp_v0 != NULL) {
        *temp_v0 = (s32) M2C_FIELD(arg0, s16 *, 0x1C);
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s32 *, 4) = (s32) (M2C_FIELD(arg0, s16 *, 0x1E) - 0x40);
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x20);
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x20) = arg1;
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x24) = arg2;
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x26) = arg3;
        Collision_Set(6, M2C_FIELD(arg0, s32 **, 0), M2C_FIELD(arg0, s32 *, 4));
    }
}

void EnemyShot_Frame(void) {
    if (!(g_Game.f_8100 & 6)) {
        EnemyShot_UpdateAll();
    }
    EnemyShot_DrawAll();
}

INCLUDE_ASM("asm/nonmatchings/game/800592E0_enemy_shot", EnemyShot_DrawAll);

/* Updates the 16 enemy projectiles (D_800B8D30). By state: 1/2 wait while the owner object
 * exists, 10 explodes when it is destroyed; 3/4 are one-frame blasts; 5 hops toward Spike
 * when he is near and blinks out; 6 is a homing missile that steers at Spike's predicted
 * position and explodes on the ground, on contact or after 90 frames; 7 a bouncing bomb and
 * 8/9 thrown rocks that bounce and settle. A start delay (+0xE) keeps a shot hidden. */
void EnemyShot_UpdateAll(void) {
    struct S_D_800B8D30_80059FA4 *p;
    s32 i;
    s32 d;
    s16 g;
    struct S_D_800B8D30_80059FA4 *k0;
    s32 k1;
    s32 k2;
    SV_59FA4_80059FA4 b;
    SV_59FA4_80059FA4 a;

    for (i = 15, p = ((struct S_D_800B8D30_80059FA4 *)&D_800B8D30); i >= 0; i--, p++) {
        if (p->state == 0) {
            continue;
        }
        if (p->delay != 0) {
            p->delay--;
            p->hidden = 1;
            continue;
        }
        p->hidden = 0;
        switch (p->state) {
        case 5:
            p->f_12--;
            if (p->ground > p->pos.vy) {
                p->pos.vx += p->vx;
                p->pos.vy += p->vy;
                p->pos.vz += p->vz;
                p->vy += 6;
                if (p->f_12 == 0) {
                    p->f_12 = 2;
                    if (p->f_11 < 4) {
                        p->f_11++;
                    }
                }
                if (p->pos.vy >= p->ground) {
                    p->pos.vy = p->ground;
                    Effect_SpawnAt(4, &p->pos);
                }
            } else {
                if (p->f_12 == 0) {
                    p->f_12 = 2;
                    if (p->f_11 < 7) {
                        p->f_11++;
                    }
                }
                if (++p->timer >= 0x5A) {
                    p->state = 0;
                }
                if (p->timer >= 0x3C) {
                    if (p->timer & 1) {
                        p->hidden = 1;
                    }
                } else if ((p->pos.vx - g_Spike.x) * (p->pos.vx - g_Spike.x) + (p->pos.vy - g_Spike.y) * (p->pos.vy - g_Spike.y)
                           + (p->pos.vz - g_Spike.z) * (p->pos.vz - g_Spike.z) < 0x1900) {
                    p->f_11 = 0;
                    p->vy = -0x20;
                    p->timer = 0x3C;
                    p->vx = (RAND() >> 8 & 0x1F) - 0x10;
                    p->pos.vy += p->vy;
                    p->vz = (RAND() >> 8 & 0x1F) - 0x10;
                    p->f_12 = 4;
                    EnemyShot_SetHitbox(p, 0x80, 0x600, 0);
                }
            }
            p->f_15 = 0x40;
            p->f_14 = (p->f_11 & 7) << 5;
            continue;
        case 6:
            p->timer++;
            (*(struct Game_59FA4 *)&g_Game).f_8296 = 2;
            if (p->timer & 1) {
                p->ground = Floor_GetHeight(p->pos.vx, p->pos.vy, p->pos.vz);
            }
            if (p->ground - 0x40 < p->pos.vy || p->timer >= 0x5B || (p->col != 0 && (p->col->f_2C >> 28) == 6)) {
                p->state = 0;
                if (ABS(p->pos.vy - p->ground) < 0x154) {
                    p->pos.vy = p->ground;
                }
                Effect_SpawnAt(0x102, &p->pos);
                Sound_PlayFixed(0x4D);
                Camera_StartShake(1);
                continue;
            }
            p->pos.vx += p->vx;
            p->pos.vy += p->vy;
            p->pos.vz += p->vz;
            Effect_SpawnAt(0x1A, &p->pos);
            if (!(p->timer & 3)) {
                Effect_SpawnAt(4, &p->pos);
            }
            if (p->f_D != 0 && --p->f_D == 0) {
                Effect_SpawnAt(0x10B, &p->pos);
            }
            if (p->f_F == 0) {
                if (p->f_D == 0) {
                memset(&a, 0, 8);
                a.vx = g_Spike.vx * 4 + g_Spike.x - p->pos.vx;
                a.vy = (g_Spike.vy * 2 - 0x80) + g_Spike.y - p->pos.vy;
                a.vz = g_Spike.z + g_Spike.vz * 4 - p->pos.vz;
                b = a;
                VectorNormalSS(&b, &b);
                p->vx = p->vx * 475 >> 9;
                p->vy = p->vy * 475 >> 9;
                p->vz = p->vz * 475 >> 9;
                p->vx += b.vx >> 8;
                p->vy += b.vy >> 8;
                p->vz += b.vz >> 8;
                p->vx = p->vx < -0x1C ? -0x1C : p->vx > 0x1C ? 0x1C : p->vx;
                p->vy = p->vy < -0x1A ? -0x1A : p->vy > 0x1A ? 0x1A : p->vy;
                p->vz = p->vz < -0x1C ? -0x1C : p->vz > 0x1C ? 0x1C : p->vz;
                }
            } else {
                p->vy += 2;
            }
            d = (p->pos.vx - g_Spike.x) * (p->pos.vx - g_Spike.x) + (p->pos.vy - (g_Spike.y - 0x80)) * (p->pos.vy - (g_Spike.y - 0x80))
                + (p->pos.vz - g_Spike.z) * (p->pos.vz - g_Spike.z);
            if (d < 0x9610) {
                p->f_F = 1;
            }
            if (d < 0x4000) {
                EnemyShot_SetHitbox(p, 0x28, 1, 0x200);
            }
            continue;
        case 7:
            p->pos.vx += p->vx;
            p->pos.vy += p->vy;
            p->pos.vz += p->vz;
            if (p->timer < 0x400) {
                p->vy += 4;
                if (p->vy >= 0x180) {
                    p->vy = 0x180;
                }
                if (p->vy > 0) {
                    g = Floor_GetHeight(p->pos.vx, p->pos.vy, p->pos.vz);
                    p->ground = g;
                    if (p->pos.vy >= g) {
                        p->pos.vy = g;
                        p->vy = -0x14;
                        p->vx /= 4;
                        p->vz /= 4;
                        p->timer = 0x400;
                        Effect_SpawnAt(4, &p->pos);
                    }
                }
                if (p->col != 0 && (p->col->f_2C >> 28) == 6) {
                    p->vx = -p->vx / 4;
                    p->vz = -p->vz / 4;
                    p->vy = -0x16;
                    p->timer = 0x400;
                    Effect_SpawnAt(4, &p->pos);
                    p->ground = Floor_GetHeight(p->pos.vx, p->pos.vy, p->pos.vz);
                }
                if (SquareRoot0((p->pos.vx - g_Spike.x) * (p->pos.vx - g_Spike.x) + (p->pos.vz - g_Spike.z) * (p->pos.vz - g_Spike.z)) < 0x80) {
                    k0 = p;
                    k1 = 0x20;
                    k2 = 1;
                spawn:
                    EnemyShot_SetHitbox(k0, k1, k2, 0);
                }
                break;
            }
            p->vy += 8;
            if (p->pos.vy < p->ground) {
                break;
            }
            p->vy = -p->vy / 2;
            if (p->vy >= -7) {
                p->state = 0;
            } else if (p->vy < -10) {
                Effect_SpawnAt(4, &p->pos);
            }
            break;
        case 8:
        case 9:
            p->pos.vx += p->vx;
            p->pos.vy += p->vy;
            p->pos.vz += p->vz;
            p->vy += 4;
            if (p->timer < 0x400) {
                if (p->vy > 0) {
                    g = Floor_GetHeight(p->pos.vx, p->pos.vy, p->pos.vz);
                    p->ground = g;
                    if (p->pos.vy >= g) {
                        p->vy = -0x14;
                        p->pos.vy = g;
                        if (p->state == 8) {
                            p->vx *= 4;
                            p->vz *= 4;
                        }
                        p->timer = 0x400;
                        Effect_SpawnAt(5, &p->pos);
                    }
                    if (SquareRoot0((p->pos.vx - g_Spike.x) * (p->pos.vx - g_Spike.x) + (p->pos.vz - g_Spike.z) * (p->pos.vz - g_Spike.z)) < 0x80) {
                        k0 = p;
                        k1 = 0x50;
                        k2 = 0;
                        goto spawn;
                    }
                }
                break;
            }
            if (p->pos.vy < p->ground) {
                break;
            }
            p->vy = -p->vy / 2;
            if (p->vy >= -7) {
                p->state = 0;
            } else if (p->vy < -10) {
                Effect_SpawnAt(4, &p->pos);
            }
            break;
        case 10:
            if ((u8)(*p->obj - 1) < 2) {
                p->state = 0;
                Effect_SpawnAt(0x102, &p->pos);
                Camera_StartShake(0);
                Sound_PlayFixed(0x4D);
            }
            continue;
        case 1:
        case 2:
            if ((u8)(*p->obj - 1) < 2) {
                p->state = 0;
            }
            continue;
        case 3:
            if (p->timer == 0) {
                EnemyShot_SetHitbox(p, 0xC8, 0, 0x102);
            }
            if (p->timer == 1) {
                p->state = 0;
            }
            break;
        case 4:
            if (p->timer == 0) {
                EnemyShot_SetHitbox(p, 0xC8, 1, 0x201);
            }
            if (p->timer == 1) {
                p->state = 0;
            }
            break;
        default:
            continue;
        }
        p->timer++;
    }
}


