#include "common.h"
#include "m2c_macros.h"
#define MDL(i) ((Mdl_8009398C_8009398C *)&D_800B4D64[i])
#define GG ((G_8009398C_8009398C *)&g_Game)
#define SP ((Sp_8009398C_8009398C *)&g_Spike)
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[0x28]; } S_820C_8009391C;
typedef struct { u32 *f_0; u8 pad4[0x1C]; } S_4D64_8009391C;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; u8 pad8[4]; s16 f_C; } S_9391C_8009391C;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } S_820C_80093E74;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; s16 f_8; } S_93E74_80093E74;
typedef struct { u8 pad[0x38]; } S_820C_80093788;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; s16 f_8; } S_93788_80093788;
typedef struct { s16 vx, vy, vz, pad; } SV_80093F04_80093F04;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; } T_80093F04_80093F04;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[0x28]; } O_80093F04_80093F04;
typedef struct { u8 pad0[0x18]; s16 f_18; u8 pad1A[6]; } Mdl_80093F04_80093F04;
typedef struct { u8 pad0[0x24]; s32 pos[3]; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x24]; s16 f_60; u8 pad62[2]; s16 f_64; } Sp_80093F04_80093F04;
typedef struct { s16 vx, vy, vz, pad; } SV_8009398C_8009398C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[4]; s16 f_E; u8 pad10[0x28]; } E_8009398C_8009398C;
typedef struct { u32 *f_0; u8 pad4[0x14]; s16 f_18; u8 pad1A[2]; void *f_1C; } Mdl_8009398C_8009398C;
typedef struct { s16 f_0; s16 state; s16 ent; u8 pad6[2]; s16 amp; s16 phase; s16 f_C; s16 f_E; s16 f_10; s16 f_12; } T_8009398C_8009398C;
typedef struct { u8 pad0[0x24]; s32 x, y, z, vx, vy, vz; u8 pad3C[8]; s16 f_44; u8 pad46[0x12]; s16 f_58; u8 pad5A[6]; s16 f_60; u8 pad62[2]; s16 f_64; } Sp_8009398C_8009398C;
typedef struct { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0xE4]; E_8009398C_8009398C *f_820C; } G_8009398C_8009398C;
typedef struct { u32 *f_0; u8 pad4[0x1C]; } S_4D64_8009391C_8009398C;
typedef struct { s16 x, y, z, w, h, d; } O_80094330_80094330;
typedef struct { s32 x, y, z; } P_80094330_80094330;

extern struct S_D_800EC350 { u8 pad_0[0x820C]; s32 f_820C; } g_Game;
s32 Box_ContainsPoint(void *, s32, s32, s32);
extern struct S_D_800EC1E0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
extern S_4D64_8009391C *D_800B4D64;
s32 Link_TouchesSpike(s16 arg0, void *arg1, void *arg2);
void Spike_StartKnockback(u8 *, s32);
struct S_D_800EC350_80093788 { u8 pad0[0x820C]; S_820C_80093788 *f_820C; };
struct Game_80093F04 { u8 pad0[0x8126]; u16 stage; u8 pad8128[0xE4]; O_80093F04_80093F04 *f_820C; };
s32 func_80094330(O_80094330_80094330 *o, P_80094330_80094330 *p, s16 ex, s16 ez);
s32 Geo_DiagonalDistance(s32, s32 *, O_80093F04_80093F04 *, void *);
void VectorNormalSS(void *, void *);
void Sound_PlayFixed(s32);
void Pad_Vibrate(s32, s32, s32);
void func_80066F34(void);
void func_800147D0(void *, void *);
s32 rsin(s32);

s32 func_80093740(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x18) | 0x8000);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

s32 Link_UpdateKnockbackZone(S_93788_80093788 *s) {
    S_820C_80093788 *r = &((struct S_D_800EC350_80093788 *)&g_Game)->f_820C[s->f_4];
    u8 buf[8];
    switch (s->f_2) {
    case 0:
        if (Link_TouchesSpike(s->f_8, r, buf) != 0) {
            s->f_2 = 1;
            s->f_6 = 30;
            Spike_StartKnockback(buf, 30);
        }
        break;
    case 1:
        if (--s->f_6 < 0) {
            s->f_2 = 0;
        }
        break;
    }
    return 0;
}

s32 Link_TouchesSpike(s16 arg0, void *arg1, void *arg2) {
    s16 var_a0;
    s16 var_a0_2;

    if (Box_ContainsPoint(arg1, g_Spike.f_24, g_Spike.f_28, g_Spike.f_2C) == 0) {
        return 0;
    }
    if (arg0 == 1) {
        M2C_FIELD(arg2, s16 *, 2) = 0;
        M2C_FIELD(arg2, s16 *, 0) = 0;
        var_a0 = 0x1000;
        if (M2C_FIELD(arg1, s16 *, 4) < g_Spike.f_2C) {
            var_a0 = -0x1000;
        }
        M2C_FIELD(arg2, s16 *, 4) = var_a0;
    } else {
        M2C_FIELD(arg2, s16 *, 2) = 0;
        M2C_FIELD(arg2, s16 *, 4) = 0;
        var_a0_2 = 0x1000;
        if (M2C_FIELD(arg1, s16 *, 0) < g_Spike.f_24) {
            var_a0_2 = -0x1000;
        }
        M2C_FIELD(arg2, s16 *, 0) = var_a0_2;
    }
    return 1;
}

s32 func_8009391C(S_9391C_8009391C *a) {
    S_820C_8009391C *r = &((S_820C_8009391C *)g_Game.f_820C)[a->f_4];
    a->f_2 = 0;
    a->f_6 = 0;
    if (a->f_C > 0) {
        *D_800B4D64[r->f_E].f_0 |= 0x2000;
    }
    return 0;
}

/* A bouncy stage object. Idle (state 0): when Spike lands on it (his floor entity +0x58 is ours) it
 * squashes (state 1, or turns with state 3 when +0xC is set), rumbles the pad, plays the stage's
 * bounce sound (0xB5 stage 7, 0xB3 stages 0x51/0x52/0x54, 0xB6 0x32, 0xAE 0x47) and bounces him
 * (func_80066F34). Running into its side (within radius +6 plus his own, inside its height)
 * knocks him back along the average of his heading and the push-out direction and makes it
 * wobble sideways (state 2; sound 0xBB in stage 0x19). The wobble (amplitude +8, phase +0xA)
 * halves every cycle and scales the model through func_800147D0. Returns 0. */
s32 Bouncy_Update(T_8009398C_8009398C *t) {
    E_8009398C_8009398C *e = &GG->f_820C[t->ent];
    SV_8009398C_8009398C s;
    SV_8009398C_8009398C w;
    s32 dx;
    s32 dz;
    s32 r;

    switch (t->state) {
    case 0:
        if (SP->f_58 == t->ent) {
            if (t->f_C > 0) {
                t->state = 3;
            } else {
                t->state = 1;
            }
            t->amp = 0x300;
            t->phase = 0;
            Pad_Vibrate(0, 1, 5);
            if (GG->f_8126 == 7) {
                Sound_PlayFixed(0xB5);
            } else if ((u16)(GG->f_8126 - 0x51) < 2 || GG->f_8126 == 0x54) {
                Sound_PlayFixed(0xB3);
            } else if (GG->f_8126 == 0x32) {
                Sound_PlayFixed(0xB6);
            } else if (GG->f_8126 == 0x47) {
                Sound_PlayFixed(0xAE);
            }
            func_80066F34();
            break;
        }
        if (t->f_12 > 0) {
            break;
        }
        dx = e->f_0 - SP->x;
        dz = e->f_4 - SP->z;
        r = e->f_6 + SP->f_44 + 0x20;
        if (r * r < dx * dx + dz * dz) {
            break;
        }
        if (e->f_2 < SP->y) {
            break;
        }
        if (SP->y < e->f_2 - e->f_8) {
            break;
        }
        if (t->f_C > 0) {
            t->state = 3;
        } else {
            t->state = 2;
        }
        if (GG->f_8126 == 0x19) {
            Sound_PlayFixed(0xBB);
        }
        t->amp = 0x300;
        t->phase = 0;
        Pad_Vibrate(0, 1, 5);
        s.vx = SP->x + SP->vx - e->f_0;
        s.vy = 0;
        s.vz = SP->z + SP->vz - e->f_4;
        VectorNormalSS(&s, &s);
        w.vy = 0;
        w.vx = SP->vx;
        w.vz = SP->vz;
        VectorNormalSS(&w, &w);
        w.vy = 0;
        w.vx += s.vx;
        w.vz += s.vz;
        VectorNormalSS(&w, &w);
        SP->f_60 = w.vx;
        SP->f_64 = w.vz;
        Spike_StartKnockback(&w, 30);
        break;
    case 1:
        s.vx = 0x1000;
        s.vy = 0x1000;
        s.vz = 0x1000;
        if (t->amp < 0x80) {
            t->state = 0;
            goto apply;
        }
        s.vy = 0x1000 - t->amp * rsin(t->phase) / 4096;
        goto step;
    case 2:
        s.vx = 0x1000;
        s.vy = 0x1000;
        s.vz = 0x1000;
        if (t->amp < 0x80) {
            t->state = 0;
            goto apply;
        }
        s.vx = 0x1000 - t->amp * rsin(t->phase) / 4096;
        s.vz = 0x1000 - t->amp * rsin(t->phase) / 4096;
    step:
        t->phase += 0x100;
        if (t->phase > 0x1000) {
            t->phase = 0;
            t->amp /= 2;
        }
    apply:
        if ((*MDL(e->f_E)->f_0 & 0xF) == 3) {
            func_800147D0(&s, MDL(e->f_E)->f_1C);
        }
        break;
    case 3:
        t->phase += t->f_E;
        if (t->phase >= t->f_10 << 12) {
            t->phase = 0;
            t->state = 0;
        }
        MDL(e->f_E)->f_18 = t->phase;
        break;
    }
    return 0;
}

s32 func_80093E74(S_93E74_80093E74 *a) {
    S_820C_80093E74 *r = &((S_820C_80093E74 *)g_Game.f_820C)[a->f_4];
    if (a->f_8 >= 4) {
        r->f_18 |= 0x8000;
    }
    if (r->f_E >= 0) {
        *D_800B4D64[r->f_E].f_0 |= 0x2000;
    }
    a->f_2 = 0;
    a->f_6 = 0;
    return 0;
}

/* Bumper: when Spike touches it (func_80094330 with size t->f_C / t->f_E; directions 4-7 also
 * check the side with Geo_DiagonalDistance) it reflects his horizontal velocity according to its facing
 * t->f_8 (a zero component becomes 1), boosts it 5x, turns him to face the new direction and
 * starts a knockback of t->f_A frames (Spike_StartKnockback). Sound 0xB3 in stage 0x15, 0xB4 in
 * stage 0x54. Then plays its squash animation (states 1/2, model frame from t->f_6). */
s32 Bumper_Update(T_80093F04_80093F04 *t) {
    SV_80093F04_80093F04 d;
    u8 tmp[0x10];
    O_80093F04_80093F04 *o = &(*(struct Game_80093F04 *)&g_Game).f_820C[t->f_4];
    s32 r;
    switch (t->f_2) {
    case 0:
        if (!func_80094330(o, (*(Sp_80093F04_80093F04 *)&g_Spike).pos, t->f_C, t->f_E)) {
            return 0;
        }
        switch (t->f_8) {
        case 0:
        case 2:
            {
                Sp_80093F04_80093F04 *s = &(*(Sp_80093F04_80093F04 *)&g_Spike);
                if (s->f_30 == 0 || s->f_38 == 0) {
                    s->f_38 = 1;
                    s->f_30 = 1;
                }
            }
            d.vy = 0;
            d.vx = -(*(Sp_80093F04_80093F04 *)&g_Spike).f_30;
            d.vz = (*(Sp_80093F04_80093F04 *)&g_Spike).f_38;
            break;
        case 1:
        case 3:
            {
                Sp_80093F04_80093F04 *s = &(*(Sp_80093F04_80093F04 *)&g_Spike);
                if (s->f_30 == 0 || s->f_38 == 0) {
                    s->f_38 = 1;
                    s->f_30 = 1;
                }
            }
            d.vx = (*(Sp_80093F04_80093F04 *)&g_Spike).f_30;
            d.vy = 0;
            d.vz = -(*(Sp_80093F04_80093F04 *)&g_Spike).f_38;
            break;
        case 4:
        case 6:
            r = Geo_DiagonalDistance(0, (*(Sp_80093F04_80093F04 *)&g_Spike).pos, o, tmp);
            if ((*(struct Game_80093F04 *)&g_Game).stage == 0x54 && t->f_C < r) {
                return 0;
            }
            if (t->f_C < ABS(r)) {
                return 0;
            }
            {
                Sp_80093F04_80093F04 *s = &(*(Sp_80093F04_80093F04 *)&g_Spike);
                if (s->f_30 == 0 || s->f_38 == 0) {
                    s->f_38 = 1;
                    s->f_30 = 1;
                }
            }
            d.vy = 0;
            d.vx = -(*(Sp_80093F04_80093F04 *)&g_Spike).f_38;
            d.vz = -(*(Sp_80093F04_80093F04 *)&g_Spike).f_30;
            break;
        case 5:
        case 7:
            r = Geo_DiagonalDistance(0xC00, (*(Sp_80093F04_80093F04 *)&g_Spike).pos, o, tmp);
            if (t->f_C < ABS(r)) {
                return 0;
            }
            {
                Sp_80093F04_80093F04 *s = &(*(Sp_80093F04_80093F04 *)&g_Spike);
                if (s->f_30 == 0 || s->f_38 == 0) {
                    s->f_38 = 1;
                    s->f_30 = 1;
                }
            }
            d.vx = (*(Sp_80093F04_80093F04 *)&g_Spike).f_38;
            d.vz = (*(Sp_80093F04_80093F04 *)&g_Spike).f_30;
            d.vy = 0;
            break;
        }
        (*(Sp_80093F04_80093F04 *)&g_Spike).f_30 = d.vx * 5;
        (*(Sp_80093F04_80093F04 *)&g_Spike).f_38 = d.vz * 5;
        VectorNormalSS(&d, &d);
        (*(Sp_80093F04_80093F04 *)&g_Spike).f_60 = d.vx;
        (*(Sp_80093F04_80093F04 *)&g_Spike).f_64 = d.vz;
        t->f_2 = 1;
        if ((*(struct Game_80093F04 *)&g_Game).stage == 0x15) {
            Sound_PlayFixed(0xB3);
        } else if ((*(struct Game_80093F04 *)&g_Game).stage == 0x54) {
            Sound_PlayFixed(0xB4);
        }
        Spike_StartKnockback(&d, t->f_A);
        return 0;
    case 1:
        t->f_6 += 2;
        if (t->f_6 >= t->f_A) {
            t->f_2 = 2;
            t->f_6 = t->f_A - 1;
        }
        break;
    case 2:
        t->f_6 -= 2;
        if (t->f_6 < 0) {
            t->f_2 = 0;
            t->f_6 = 0;
        }
        break;
    default:
        return 0;
    }
    if (o->f_E >= 0) {
        (*(Mdl_80093F04_80093F04 * *)&D_800B4D64)[o->f_E].f_18 = t->f_6 * ((t->f_10 + 1) << 12) / t->f_A;
    }
    return 0;
}



s32 func_80094330(O_80094330_80094330 *o, P_80094330_80094330 *p, s16 ex, s16 ez) {
    if (o->x + o->w + ex < p->x || p->x < o->x - o->w - ex) {
        goto miss;
    }
    if (o->z + o->d + ez < p->z || p->z < o->z - o->d - ez) {
        goto miss;
    }
    if (p->y < o->y - o->h) {
        goto miss;
    }
    if (o->y < p->y) {
        goto miss;
    }
    return 1;
miss:
    return 0;
}
