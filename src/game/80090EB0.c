#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "common.h"
#define SP_931C8 ((struct Spike_800931C8 *)&g_Spike)
#define SP_91D24 ((struct Spike_80091D24 *)&g_Spike)
#define LEN(s) (*(s16 *)((u8 *)(s) + 0x12))
#define GM_91A18 ((struct Game_91A18 *)&g_Game)
#include "common.h"
#define G_GAME_80092E74 ((struct g_Game_80092E74 *)&g_Game)
#define G_GAME_80092FBC ((struct g_Game_80092FBC *)&g_Game)
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } S_820C_80091704;
typedef struct { u8 pad0[0x16]; s16 f_16; u8 pad18[8]; } S_4D64_80091704;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; } S_91704_80091704;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80092A68;
typedef struct { u8 pad0[0x1C]; void *f_1C; } S_4D64_80092A68;
typedef struct { u8 pad0[2]; s16 f_2; u8 pad4[2]; s16 f_6; s16 f_8; u8 padA[2]; s16 f_C; s16 f_E; } S_92A68_80092A68;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[0xE]; u16 f_18; u8 pad1A[0x1E]; } S_820C_80090F80;
typedef struct { u8 pad0[4]; s16 f_4; } S_90F80_80090F80;
typedef struct { s16 f_0; s16 f_2; u8 pad_4[0x14]; } S_Rec18_800930A4;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80091060_80091060;
typedef struct { u16 f_0; u16 f_2; u16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[0xC]; u16 f_18; u8 pad1A[0x1E]; } R38_80091060_80091060;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; u8 padE[2]; s16 f_10; u8 pad12[2]; s16 f_14; } A_80091060_80091060;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; } S_91598a_80091598;
typedef struct { u8 pad0[4]; u16 f_4; u8 pad6[0x10]; s16 f_16; } S_91598b_80091598;
typedef struct { u8 pad0[0x12]; s16 f_12; u8 pad14[0xC]; } S_4D64_80091598;
typedef struct { u8 pad0[0x38]; } R38_800918FC_800918FC;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; u8 padC[2]; s16 f_E; } A_800918FC_800918FC;
typedef struct { s16 vx, vy, vz, pad; } SVEC_800935F0_800935F0;
typedef struct { u8 pad0[8]; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; } S_P_800935F0_800935F0;
typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0xC]; SVEC_800935F0_800935F0 f_18; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; } S_O_800935F0_800935F0;
typedef struct { u8 pad[0x16]; s16 f_16; u8 pad18[8]; } S_4D64_800913EC_800913EC;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[4]; s16 f_1E; u8 pad20[0x18]; } S_820C_800913EC_800913EC;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; u16 f_6; s16 f_8; s16 f_A; s16 f_C; } S_T_800913EC_800913EC;
typedef struct { u8 pad0[8]; s16 arr[8]; } S_TA_800913EC_800913EC;
typedef struct { s16 x, y, z; u8 pad6[0x18]; s16 f_1E; u8 pad20[0x18]; } Solid_80091178_80091178;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; s16 f_10; s16 f_12; s16 f_14; } Trig_80091178_80091178;
typedef struct { u8 pad0[0x10]; s16 x, y, z; u8 pad16[6]; void *mat; } Mdl_800931C8_800931C8;
typedef struct { u8 pad0[6]; s16 angle; u8 pad8[2]; s16 speed; s16 mdl; s16 radius; s16 length; } Spin_800931C8_800931C8;
typedef struct { s32 x, z, d; } Hit_800931C8_800931C8;
typedef struct { s16 x, z; } XZ_800931C8_800931C8;
typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR f_18; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Coll_800931C8_800931C8;
typedef struct { s16 x, y, z, rx, h, rz; } Box_80091D24_80091D24;
typedef struct { s32 x, y, z; } P3_80091D24_80091D24;
typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR f_18; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Coll_80091D24_80091D24;
typedef struct { s16 f_0, f_2, f_4, f_6, f_8; u16 f_A; s16 f_C, f_E, f_10, f_12, f_14, f_16; } T_800920AC_800920AC;
typedef struct { u8 pad0[0x16]; u16 f_16; } Pl_800920AC_800920AC;
typedef struct { u8 pad0[0x10]; s16 f_10; u8 pad12[0xA]; s16 f_1C; u8 pad1E[6]; SVECTOR f_24; u8 pad2C[0xC]; } O_800920AC_800920AC;
typedef struct { s16 vx, vy, vz, pad; } SV_92B0C_80092B0C;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_92B0C_80092B0C;
typedef struct { s16 x, y, z, w, h, d; } Box_92B0C_80092B0C;
typedef struct { u8 pad0[2]; s16 state; u8 pad4[2]; s16 t; s16 axis; s16 period; s16 mdl; u16 amp; s16 size; u8 pad12_dummy[0]; } Sw_92B0C_80092B0C;
typedef struct { u8 pad0[0x10]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[6]; MAT_92B0C_80092B0C *f_1C; } Mdl_92B0C_80092B0C;
typedef struct { u8 pad[0x38]; } S_820C_80091A18;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; u8 padC[2]; s16 f_E; } S_91A18_80091A18;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u16 f_6; u16 f_8; u16 f_A; u8 padC[4]; s16 f_10; u8 pad12[0xA]; s16 f_1C; u8 pad1E[6]; u16 f_24; u16 f_26; u16 f_28; u8 pad2A[8]; u16 f_32; u16 f_34; u16 f_36; } R38_80091FB0;
typedef struct { u8 pad0[6]; s16 f_6; u8 pad8[0x10]; } R18_80091FB0;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; union { u8 b[2]; u16 h; } f_A; u8 padC[2]; s16 f_E; u8 pad10[6]; s16 f_16; } A_80091FB0;
typedef struct { u8 pad0[0x16]; s16 f_16; } S_8220_80092E74;
typedef struct { u8 pad[0x20]; } S_4D64_80092E74;
typedef struct { u8 pad0[8]; s16 f_8; s16 f_A; s16 f_C; s16 f_E; } S_92E74_80092E74;
typedef struct { u32 *f_0; u8 pad4[0x18]; void *f_1C; } S_4D64_80091C04;
typedef struct { u8 pad0[0x16]; s16 f_16; } S_8220_80092FBC;
typedef struct { u8 pad0[2]; s16 f_2; u8 pad4[4]; s16 f_8; s16 f_A; s16 f_C; } S_92FBC_80092FBC;
typedef struct { s16 f_0; s16 f_2; u8 pad4[0x14]; } S_8220_80093110;
typedef struct { u8 pad0[2]; s16 f_2; u8 pad4[4]; s16 f_8; u8 padA[2]; s16 f_C; } S_93110_80093110;

extern struct S_D_800EC350 { u8 pad_0[0x8124]; u16 f_8124; u16 f_8126; u8 pad_8128[0xE4]; s32 f_820C; u8 pad_8210[0x10]; s32 f_8220; } g_Game;

M2C_UNK func_8009B578(s16, s16, s16, void *);
extern s32 D_800B4D64;
M2C_UNK Sound_PlayAt(M2C_UNK, void *);
M2C_UNK func_80091AF0();

/* A box-shaped hazard: while Spike is inside box b (centre, half sizes rx/rz, height h below y)
 * adds a type-6 collision entry with flags 0x202 (damage type 0x200, probably a shock; 2 damage)
 * that knocks him out along +x / -x / +z / -z (directions 0..3), away from the centre (4), or for
 * modes 5 / 6 out of the nearer x / z side. */
s32 ShockBox_Update(s32 mode, Box_80091D24_80091D24 *b, s32 radius);
void RotMatrixZYX(SVEC_80092A68 *, void *);
extern struct S_D_800EC1E0 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
void func_8009B3B0(s32);
struct S_D_800EC350_80090F80 { u8 pad0[0x820C]; S_820C_80090F80 *f_820C; };
struct S_D_800EC350_800930A4 { u8 pad_0[0x8220]; S_Rec18_800930A4 *f_8220; };
s32 Game_IsTimed(void);
s16 func_800716EC(s32, SVEC_80091060_80091060 *, s32);
struct S_D_800EC350_80091060 { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0xE4]; R38_80091060_80091060 *f_820C; };
s32 Floor_GetHeight(s32, s32, s32);
struct S_D_800EC350_80091598 { u8 pad0[0x8290]; u16 f_8290; };
struct S_D_800EC350_800918FC { u8 pad_0[0x820C]; R38_800918FC_800918FC *f_820C; };
s32 Vec_Length(s32, s32, s32);
void VectorNormalSS(void *, void *);
S_O_800935F0_800935F0 *CollShape_Alloc(void);
void Collision_Set(s32, S_O_800935F0_800935F0 *, s32);
struct S_D_800EC350_800913EC { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0xE4]; S_820C_800913EC_800913EC *f_820C; };
s32 func_80091598(S_91598a_80091598 *a, S_91598b_80091598 *b);
void Fx_Explosion(S_820C_800913EC_800913EC *, s16, s32);
void Model_BindStageMesh(S_4D64_800913EC_800913EC *, s16);
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Camera_StartShake(M2C_UNK);
struct Game_80091178 { u8 pad0[0x8126]; u16 stage; u8 pad8128[4]; u8 mode; u8 pad812D[0xDF]; Solid_80091178_80091178 *f_820C; };
struct Spike_80091178 { u8 pad0[0x24]; s32 x, y, z; };
void Mailbox_OpenTip(s16, s16);
void Effect_SpawnXYZ(s32, s16, s16, s16);
struct Spike_800931C8 { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x16]; s16 height; };
s32 Geo_ProjectOnLine(s16 *c, s16 *p, s16 ang, s32 *out);
struct Spike_80091D24 { u8 pad0[0x24]; s32 x, y, z; };
struct Game_800920AC { u8 pad0[0x820C]; O_800920AC_800920AC *f_820C; u8 pad8210[0x10]; Pl_800920AC_800920AC *f_8220; };
s16 func_80092324(T_800920AC_800920AC *, O_800920AC_800920AC *);
/* For a type-3 model idx (D_800B4D64, low nibble of its first word) builds its rotation matrix
 * from one angle about the axis picked by direction code axis: 4/7 +x, 5/6 -x, 0/3 +z, 1/2 -z,
 * 8 +y. */
s32 Model_SetTurnAngle(s16 axis, s16 idx, s32 ang);
void Sound_UpdateVoice3D(s32, s16, s32, SVECTOR *);
s32 Sound_Play(s32, s32);
void Sound_Stop(s32, s32);
s32 rsin(s32);
s32 rcos(s32);
struct Game_92B0C { u8 pad0[0x8126]; u16 f_8126; };
extern s32 D_800EC208;
void ApplyMatrixSV(MAT_92B0C_80092B0C *, SV_92B0C_80092B0C *, SV_92B0C_80092B0C *);
struct Game_91A18 { u8 pad0[0x820C]; S_820C_80091A18 *f_820C; };
struct S_D_800EC350_80091FB0 { u8 pad_0[0x820C]; R38_80091FB0 *f_820C; u8 pad_8210[0x10]; R18_80091FB0 *f_8220; };
struct g_Game_80092E74 { u8 pad0[0x8220]; S_8220_80092E74 *f_8220; };
struct g_Game_80092FBC { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x4C]; u16 f_8150; u8 pad8152[0xCE]; S_8220_80092FBC *f_8220; };
void CamFlyby_StartSegment(s32);
struct g_Game_80093110 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x11C]; S_8220_80093110 *f_8220; };
#define G_GAME_80093110 ((struct g_Game_80093110 *)&g_Game)
extern s16 D_800EC238;

s32 func_80090EB0(void) {
    return 0;
}

s32 func_80090EB8(void) {
    return 0;
}

s32 func_80090EC0(void *arg0) {
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

s32 func_80090F0C(void *arg0) {
    void *temp_a0;

    temp_a0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a0, s16 *, 0x20) = 0x1111;
    M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a0, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    func_8009B578(M2C_FIELD(arg0, s16 *, 8), M2C_FIELD(arg0, s16 *, 4), M2C_FIELD(arg0, s16 *, 0xA), arg0);
    return 0;
}

s32 func_80090F80(S_90F80_80090F80 *s) {
    S_820C_80090F80 *r = &((struct S_D_800EC350_80090F80 *)&g_Game)->f_820C[s->f_4];
    s32 dx;
    s32 dz;
    if (r->f_18 & 0x8000) {
        return 0;
    }
    dx = r->f_0 - g_Spike.f_24;
    dz = r->f_4 - g_Spike.f_2C;
    if (dx * dx + dz * dz >= r->f_6 * r->f_6) {
        return 0;
    }
    if (g_Spike.f_28 < r->f_2 - r->f_8) {
        return 0;
    }
    if (r->f_2 < g_Spike.f_28) {
        return 0;
    }
    func_8009B3B0(0);
    return 0;
}

s32 func_80091060(A_80091060_80091060 *a) {
    R38_80091060_80091060 *r = &((struct S_D_800EC350_80091060 *)&g_Game)->f_820C[a->f_4];
    SVEC_80091060_80091060 v;

    r->f_18 = (r->f_18 & 0xFFF0) | 1;
    if (Game_IsTimed() != 0) {
        a->f_2 = 2;
        r->f_18 |= 0x8000;
    } else {
        r->f_A = 0x50;
        r->f_6 = 0x50;
        r->f_8 = 0x100;
        v.vx = r->f_0;
        v.vy = r->f_2;
        v.vz = r->f_4;
        a->f_14 = func_800716EC(a->f_A, &v, a->f_C);
        a->f_6 = 0;
        if ((u16)(((struct S_D_800EC350_80091060 *)&g_Game)->f_8126 - 0x5C) < 7 || a->f_8 == 0) {
            a->f_2 = 0;
        } else {
            a->f_2 = 1;
        }
        a->f_10 = 0;
    }
    return 0;
}

/* Hint mailbox: how the Professor gives Spike tips (user). Spike can read it, and it shows an
 * indicator when he is close. Its object is g_Game+0x820C[t->f_4]; inactive in game modes 7, 0x15 and 0x17.
 * State t->f_2: 0 waits until Spike is within t->f_E, then calls Mailbox_OpenTip(t->f_14, t->f_12)
 * (probably sets up the Professor's tip) and goes to 3 in the tutorial stages (0x5C..0x62), else 1;
 * 1 repeats that call and spawns effect 0x112 (the indicator) just above the box while Spike is
 * in range, the object's +0x1E >= 0 and t->f_10 is 0; 3 does the same while in range and rearms
 * (0) when Spike leaves. */
s32 Mailbox_Update(Trig_80091178_80091178 *t) {
    struct Game_80091178 *g;
    Solid_80091178_80091178 *o;
    s32 d;
    g = (struct Game_80091178 *)&(*(M2C_UNK *)&g_Game);
    if (g->mode == 0x17 || g->mode == 7) {
        return 0;
    }
    if (g->mode == 0x15) {
        return 0;
    }
    o = &g->f_820C[t->f_4];
    d = Vec_Length(((struct Spike_80091178 *)&g_Spike)->x - o->x, ((struct Spike_80091178 *)&g_Spike)->y - o->y,
                      ((struct Spike_80091178 *)&g_Spike)->z - o->z);
    switch (t->f_2) {
    case 0:
        if (d < t->f_E) {
            Mailbox_OpenTip(t->f_14, t->f_12);
            if (g->stage >= 0x5C && g->stage <= 0x62) {
                t->f_2 = 3;
            } else {
                t->f_2 = 1;
            }
        }
        break;
    case 1:
        if (d < t->f_E && o->f_1E >= 0 && t->f_10 == 0) {
            Mailbox_OpenTip(t->f_14, t->f_12);
            Effect_SpawnXYZ(0x112, o->x, o->y - 0xBE, o->z);
        }
        break;
    case 2:
        break;
    case 3:
        if (t->f_E < d) {
            t->f_2 = 0;
            break;
        }
        if (o->f_1E >= 0) {
            Mailbox_OpenTip(t->f_14, t->f_12);
            Effect_SpawnXYZ(0x112, o->x, o->y - 0xBE, o->z);
        }
        break;
    }
    return 0;
}

s32 func_80091358(void *arg0) {
    s16 temp_a0;
    void *temp_a2;

    temp_a2 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if (M2C_FIELD(arg0, s16 *, 0xA) == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 0;
        M2C_FIELD(arg0, s16 *, 6) = 3;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
        M2C_FIELD(arg0, s16 *, 0x16) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 2) = 1;
        temp_a0 = M2C_FIELD(temp_a2, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
        M2C_FIELD(temp_a2, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a2, u16 *, 0x18) | 0x8000);
    }
    return 0;
}

s32 func_800913EC(S_T_800913EC_800913EC *t) {
    S_820C_800913EC_800913EC *e = &((struct S_D_800EC350_800913EC *)&g_Game)->f_820C[t->f_4];
    s16 v;
    s32 i;
    if (t->f_2 != 0) {
        return 0;
    }
    if (e->f_1E >= 0) {
        if (t->f_8 == 1 && (e->f_1E & 0xFF00) != 0x800) {
            return 0;
        }
        Camera_StartShake(0);
        t->f_A++;
        if (t->f_A >= t->f_C) {
            t->f_A = 0;
            i = (u8)t->f_6;
            if (i >= 8 || (v = ((S_TA_800913EC_800913EC *)t)->arr[i]) < 0) {
                t->f_2 = 1;
                e->f_18 |= 0x8000;
                Pad_Vibrate(0, 1, 3);
                if (e->f_E >= 0) {
                    (*(S_4D64_800913EC_800913EC * *)&D_800B4D64)[e->f_E].f_16 = 0;
                    if (((struct S_D_800EC350_800913EC *)&g_Game)->f_8126 == 0x1D) {
                        Fx_Explosion(e, e->f_E, 2);
                        return 0;
                    }
                    Fx_Explosion(e, e->f_E, 1);
                    return 0;
                }
                return 0;
            }
                if (e->f_E >= 0) {
                    Model_BindStageMesh(&(*(S_4D64_800913EC_800913EC * *)&D_800B4D64)[e->f_E], v);
                }
                t->f_6++;
        }
    }
    func_80091598(e, t);
    return 0;
}

s32 func_80091598(S_91598a_80091598 *a, S_91598b_80091598 *b) {
    s32 h;
    ((struct S_D_800EC350_80091598 *)&g_Game)->f_8290 = b->f_4;
    h = Floor_GetHeight(a->f_0, a->f_2 + b->f_16 + 8, a->f_4);
    if (h < a->f_2 + b->f_16 + 8) {
        b->f_16 = 0;
        a->f_2 = h;
        if (a->f_E >= 0) {
            (*(S_4D64_80091598 * *)&D_800B4D64)[a->f_E].f_12 = h;
        }
    } else {
        b->f_16 += 8;
        a->f_2 += b->f_16;
        if (a->f_E >= 0) {
            (*(S_4D64_80091598 * *)&D_800B4D64)[a->f_E].f_12 += b->f_16;
        }
    }
    return 0;
}

s32 func_80091688(void *arg0) {
    s16 temp_a0;
    void *temp_v1;

    temp_v1 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_v1, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_v1, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (M2C_FIELD(arg0, s16 *, 8) == 0) {
        temp_a0 = M2C_FIELD(temp_v1, s16 *, 0xE);
        if (temp_a0 >= 0) {
            M2C_FIELD(((temp_a0 << 5) + D_800B4D64), s16 *, 0x16) = 0;
        }
    }
    return 0;
}

s32 func_800916FC(void) {
    return 0;
}

s32 func_80091704(S_91704_80091704 *a) {
    S_820C_80091704 *r = &((S_820C_80091704 *)g_Game.f_820C)[a->f_4];
    r->f_18 = (r->f_18 & 0xFFF0) | 1;
    if (r->f_E >= 0) {
        ((S_4D64_80091704 *)D_800B4D64)[r->f_E].f_16 = 0;
    }
    a->f_2 = 0;
    a->f_6 = 0;
    return 0;
}

s32 func_8009176C(void *arg0) {
    s16 temp_v1;
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    temp_v1 = M2C_FIELD(arg0, s16 *, 2);
    if (temp_v1 == 1) {
        if (M2C_FIELD(temp_s0, s16 *, 0x32) == temp_v1) {
            if ((g_Game.f_8124 != 6) && (g_Game.f_8126 != 0x65)) {
                Sound_PlayAt(0x9B, temp_s0);
            }
        }
        if (M2C_FIELD(temp_s0, s16 *, 0x32) >= M2C_FIELD(arg0, s16 *, 0xC)) {
            M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_s0, u16 *, 0x18) & 0xFFF0) | 1);
            M2C_FIELD(arg0, s16 *, 2) = 2;
            if ((g_Game.f_8124 != 6) && (g_Game.f_8126 != 0x65)) {
                Sound_PlayAt(0x9B, temp_s0);
            }
        }
    }
    return 0;
}

s32 func_80091870(void *arg0) {
    void *temp_a2;

    temp_a2 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    M2C_FIELD(temp_a2, u16 *, 0x18) = (u16) ((M2C_FIELD(temp_a2, u16 *, 0x18) & 0xFFF0) | 1);
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(temp_a2, u16 *, 0x32) = (u16) M2C_FIELD(temp_a2, u16 *, 6);
    M2C_FIELD(temp_a2, u16 *, 0x34) = (u16) M2C_FIELD(temp_a2, u16 *, 8);
    M2C_FIELD(temp_a2, u16 *, 0x36) = (u16) M2C_FIELD(temp_a2, u16 *, 0xA);
    if (M2C_FIELD(temp_a2, s16 *, 0xE) >= 0) {
        func_80091AF0(temp_a2, arg0, temp_a2, arg0);
    }
    return 0;
}

s32 Link_UpdateGrowBox(A_800918FC_800918FC *a) {
    R38_800918FC_800918FC *r = &((struct S_D_800EC350_800918FC *)&g_Game)->f_820C[a->f_4];

    switch (a->f_2) {
    case 0:
        break;
    case 1:
        if (a->f_6 == 0) {
            Sound_PlayAt(0x9B, r);
        }
        a->f_6 += a->f_A;
        if (a->f_6 > 0x1000) {
            a->f_6 = 0x1000;
            a->f_2 = 2;
            Sound_PlayAt(0x9B, r);
        }
        break;
    case 2:
        a->f_6 -= a->f_E;
        if (a->f_6 < 0) {
            a->f_6 = 0;
            a->f_2 = 0;
        }
        break;
    }
    if (a->f_2 != 0) {
        func_80091AF0(r, a);
    }
    return 0;
}

s32 func_80091A18(S_91A18_80091A18 *s) {
    S_820C_80091A18 *r = &GM_91A18->f_820C[s->f_4];
    switch (s->f_2) {
    case 0:
        break;
    case 1:
        s->f_6 += s->f_A;
        if (s->f_6 > 0x1000) {
            s->f_6 = 0x1000;
        }
        break;
    case 2:
        s->f_6 -= s->f_E;
        if (s->f_6 < 0) {
            s->f_6 = 0;
        }
        break;
    }
    if (s->f_2 != 0) {
        func_80091AF0(r, s);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80090EB0", func_80091AF0);

s32 Model_SetTurnAngle(s16 axis, s16 idx, s32 ang) {
    SVECTOR r;
    s32 t;
    if (idx < 0) {
        return 0;
    }
    if ((*((S_4D64_80091C04 *)D_800B4D64)[idx].f_0 & 0xF) != 3) {
        return 0;
    }
    r.vz = 0;
    r.vy = 0;
    r.vx = 0;
    switch (axis) {
    case 5:
    case 6:
        t = -(s16)ang;
        r.vx = t;
        break;
    case 4:
    case 7:
        r.vx = ang;
        break;
    case 1:
    case 2:
        t = -(s16)ang;
        r.vz = t;
        break;
    case 0:
    case 3:
        r.vz = ang;
        break;
    case 8:
        r.vy = ang;
        break;
    }
    RotMatrixZYX(&r, ((S_4D64_80091C04 *)D_800B4D64)[idx].f_1C);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80090EB0", jtbl_800A6700_pad);


s32 func_80091CF8(void *arg0) {
    ShockBox_Update(M2C_FIELD(arg0, s16 *, 8), arg0 + 0xA, 0x80);
    return 0;
}

s32 ShockBox_Update(s32 mode, Box_80091D24_80091D24 *b, s32 radius) {
    SVECTOR dir;
    P3_80091D24_80091D24 pos;
    s16 d = mode;
    s32 r;
    Coll_80091D24_80091D24 *o;
    if (b->x - b->rx < SP_91D24->x && SP_91D24->x < b->x + b->rx && SP_91D24->y < b->y && b->y - b->h < SP_91D24->y &&
        b->z - b->rz < SP_91D24->z && SP_91D24->z < b->z + b->rz) {
        if ((s16)mode == 5) {
            d = SP_91D24->x < b->x;
        } else if ((s16)mode == 6) {
            d = 2;
            if (SP_91D24->z < b->z) {
                d = 3;
            }
        }
        pos.x = SP_91D24->x;
        pos.y = SP_91D24->y;
        pos.z = SP_91D24->z;
        r = (s16)radius;
        dir.vz = 0;
        dir.vy = 0;
        dir.vx = 0;
        switch (d) {
        case 0:
            dir.vx = 0x1000;
            pos.x -= 0x40;
            break;
        case 1:
            dir.vx = -0x1000;
            pos.x += 0x40;
            break;
        case 2:
            dir.vz = 0x1000;
            pos.z -= 0x40;
            break;
        case 3:
            dir.vz = -0x1000;
            pos.z += 0x40;
            break;
        case 4:
            dir.vx = SP_91D24->x - b->x;
            dir.vy = SP_91D24->y - b->y;
            dir.vz = SP_91D24->z - b->z;
            VectorNormalSS(&dir, &dir);
            pos.x = b->x;
            pos.y = b->y;
            pos.z = b->z;
            r = b->rx;
            break;
        }
        o = CollShape_Alloc();
        if (o != 0) {
            o->f_18 = dir;
            o->x = pos.x;
            o->y = pos.y;
            o->z = pos.z;
            o->f_24 = 1;
            o->f_20 = r;
            o->f_26 = 0x202;
            Collision_Set(6, o, 0);
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80090EB0", jtbl_800A6728_pad);


s32 func_80091FB0(A_80091FB0 *a) {
    R38_80091FB0 *r = &((struct S_D_800EC350_80091FB0 *)&g_Game)->f_820C[a->f_4];
    u32 i;
    R18_80091FB0 *q;

    r->f_1C = -1;
    r->f_24 = r->f_0;
    r->f_26 = r->f_2;
    r->f_28 = r->f_4;
    r->f_32 = r->f_6;
    r->f_34 = r->f_8;
    r->f_36 = r->f_A;
    a->f_2 = 0;
    a->f_6 = 0;
    a->f_16 = 0;
    i = a->f_A.b[0];
    if (i != 0xFF) {
        q = ((struct S_D_800EC350_80091FB0 *)&g_Game)->f_8220;
        q += i;
        q->f_6 = a->f_E * 2;
    }
    i = a->f_A.h >> 8;
    if (i != 0xFF) {
        q = ((struct S_D_800EC350_80091FB0 *)&g_Game)->f_8220;
        q += i;
        q->f_6 = a->f_E * 2;
    }
    r->f_10 = func_80092324(a, r);
    return 0;
}

/* Object raised by up to two pressure plates (t->f_A: two u8 indices into g_Game+0x8220, 0xFF =
 * none); target height is half of each plate's press. State t->f_2: 0 follows the plates up to
 * the cap t->f_E, 1 holds at the cap for t->f_14 frames, 2 sinks by t->f_12 per frame.
 * Loops sound 0x7F at its stage object (g_Game+0x820C[t->f_4]) while raised. */
s32 PlateLift_Update(T_800920AC_800920AC *t) {
    struct Game_800920AC *g = (struct Game_800920AC *)&(*(M2C_UNK *)&g_Game);
    s32 s = 0;
    s32 i;
    u16 c; s32 opened;
    O_800920AC_800920AC *o = &g->f_820C[t->f_4];
    i = t->f_A & 0xFF;
    if (i != 0xFF) {
        Pl_800920AC_800920AC *w = g->f_8220 + i;
        s = (s16)w->f_16 / 2;
    }
    i = t->f_A >> 8;
    if (i != 0xFF) {
        Pl_800920AC_800920AC *w = g->f_8220 + i;
        s += (s16)w->f_16 / 2;
    }
    opened = 1;
    switch (t->f_2) {
    case 0:
        c = t->f_16;
        if (s < t->f_16) {
            t->f_2 = 2;
            t->f_16 = c - t->f_12;
        } else {
            t->f_16 = s;
            if (t->f_16 >= t->f_E) {
                t->f_16 = t->f_E;
                goto open;
            }
        }
        break;
    case 1:
        t->f_6++;
        if (t->f_6 > t->f_14) {
            t->f_2 = 2;
        }
        break;
    case 2:
        t->f_16 -= t->f_12;
        if (t->f_16 < s) {
            t->f_16 = s;
            if (t->f_16 > t->f_E) {
                t->f_16 = t->f_E;
            open:
                t->f_6 = 0;
                t->f_2 = opened;
                break;
            }
        } else {
            if (t->f_16 >= 0) {
                break;
            }
            t->f_16 = 0;
        }
        t->f_2 = 0;
        break;
    }
    if (t->f_16 > 0) {
        if (o->f_1C < 0) {
            o->f_1C = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, o->f_1C, 0x2000, &o->f_24);
        }
    } else if (o->f_1C >= 0) {
        Sound_Stop(0x7F, o->f_1C);
        o->f_1C = -1;
    }
    o->f_10 = func_80092324(t, o);
    Model_SetTurnAngle(t->f_8, t->f_C, t->f_16);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80090EB0", func_80092324);

INCLUDE_RODATA("asm/nonmatchings/game/80090EB0", jtbl_800A6740);


s32 func_80092A68(S_92A68_80092A68 *s) {
    SVEC_80092A68 r;
    s->f_2 = 0;
    s->f_6 = 0;
    if (s->f_C >= 0) {
        r.vz = 0;
        r.vy = 0;
        r.vx = 0;
        if (s->f_8 == 0) {
            r.vx = -s->f_E / 2;
        } else {
            r.vz = s->f_E / 2;
        }
        RotMatrixZYX(&r, ((S_4D64_80092A68 *)D_800B4D64)[s->f_C].f_1C);
    }
    return 0;
}

s32 Pendulum_Update(Sw_92B0C_80092B0C *s) {
    SV_92B0C_80092B0C r;
    SV_92B0C_80092B0C p;
    MAT_92B0C_80092B0C m;
    Box_92B0C_80092B0C b;
    s32 a;

    r.vz = 0;
    r.vy = 0;
    r.vx = 0;
    switch (s->state) {
    case 0:
        if (++s->t > s->period) {
            s->state = 1;
            s->t = 0;
            a = (s16)s->amp / 2;
            break;
        }
        a = -(s16)s->amp / 2 * rcos((s->t << 11) / s->period) / 4096;
        break;
    case 1:
        if (++s->t > s->period) {
            s->state = 0;
            s->t = 0;
            a = -(s16)s->amp / 2;
            break;
        }
        a = (s16)s->amp / 2 * rcos((s->t << 11) / s->period) / 4096;
        break;
    }
    if (s->mdl < 0) {
        goto end;
    }
    if (s->axis == 0) {
        r.vx = a;
    } else {
        r.vz = a;
    }
    RotMatrixZYX(&r, &m);
    r.vx = 0;
    r.vy = LEN(s);
    r.vz = 0;
    ApplyMatrixSV(&m, &r, &p);
    b.x = (*(Mdl_92B0C_80092B0C * *)&D_800B4D64)[s->mdl].f_10 + p.vx;
    b.y = (*(Mdl_92B0C_80092B0C * *)&D_800B4D64)[s->mdl].f_12 + p.vy;
    b.z = (*(Mdl_92B0C_80092B0C * *)&D_800B4D64)[s->mdl].f_14 + p.vz;
    b.w = s->size;
    b.h = s->size;
    b.d = s->size;
    ShockBox_Update(4, &b, s->size);
    *(*(Mdl_92B0C_80092B0C * *)&D_800B4D64)[s->mdl].f_1C = m;
    if (s->t == (s16)s->period / 2) {
        if ((*(struct Game_92B0C *)&g_Game).f_8126 == 0x3C) {
            if (D_800EC208 < -0xB00) {
                Sound_PlayAt(0xB4, &b);
            }
        } else if ((*(struct Game_92B0C *)&g_Game).f_8126 == 0x17) {
            Sound_PlayAt(0xB2, &b);
        }
    }
end:
    return 0;
}

s32 func_80092E74(S_92E74_80092E74 *s) {
    s32 i;
    s32 n;
    S_8220_80092E74 *p;
    if (s->f_A >= 0 && s->f_C >= 0 && s->f_E >= 0) {
    p = &G_GAME_80092E74->f_8220[s->f_A];
    n = p->f_16;
    for (i = 0; i < s->f_8; i++) {
        if (i < n) {
            Model_BindStageMesh(&(*(S_4D64_80092E74 * *)&D_800B4D64)[s->f_C + i], s->f_E);
        }
    }
    }
    return 0;
}

s32 func_80092F50(void *arg0)
{
  void *new_var;
  s8 *new_var5;
  int new_var4;
  s16 *new_var3;
  s8 *new_var2;
  *((s16 *) (((s8 *) arg0) + 6)) = 0;
  if ((*((s16 *) (((s8 *) arg0) + 0x14))) == 0)
  {
    new_var = arg0;
    new_var2 = (s8 *) new_var;
    new_var3 = &(*((s16 *) (new_var2 + 0xA)));
    new_var5 = (s8 *) (g_Game.f_8220 + (new_var4 = (*((s16 *) (((s8 *) arg0) + 8))) * 0x18));
    if ((*((s16 *) (new_var5 + 0x16))) < (*new_var3))
    {
      *((s16 *) (((s8 *) new_var) + 2)) = 0;
    }
    else
    {
      goto block_4;
    }
  }
  else
  {
    block_4:
    *((s16 *) (((s8 *) arg0) + 2)) = 2;

  }
  return 0;
}

s32 Link_UpdateFlybyTrigger(S_92FBC_80092FBC *s) {
    S_8220_80092FBC *l;
    if (s->f_8 < 0) {
        return 0;
    }
    switch (s->f_2) {
    case 0:
        l = &G_GAME_80092FBC->f_8220[s->f_8];
        if (l->f_16 < s->f_A) {
            return 0;
        }
        if (G_GAME_80092FBC->f_8150 != 8) {
            return 0;
        }
        s->f_2 = 1;
        return 0;
    case 1:
        if (G_GAME_80092FBC->f_8150 != 0) {
            return 0;
        }
        CamFlyby_StartSegment(s->f_C - 1);
        G_GAME_80092FBC->f_8100 = 7;
        s->f_2 = 2;
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_800930A4(s16 *arg0)
{
  s32 temp;
  S_Rec18_800930A4 *new_var;
  arg0[3] = 0;
  if (arg0[10] == 0)
  {
    new_var = &((struct S_D_800EC350_800930A4 *)&g_Game)->f_8220[arg0[4]];
    temp = (*new_var).f_2;
    if (temp == 1)
    {
      arg0[1] = temp;
    }
    else
      if (arg0)
    {
      arg0[1] = 0;
    }
    else
    {
      arg0[1] = 0;
    }
  }
  else
  {
    arg0[1] = 1;
  }
  return 0;
}

s32 Link_UpdateFlybyOnSwitch(S_93110_80093110 *s) {
    s32 v;
    S_8220_80093110 *e;
    if (s->f_8 < 0) {
        return 0;
    }
    switch (s->f_2) {
    case 0:
        e = &G_GAME_80093110->f_8220[s->f_8];
        v = e->f_2;
        if (v != 1) {
            return 0;
        }
        CamFlyby_StartSegment(s->f_C - 1);
        G_GAME_80093110->f_8100 = 7;
        D_800EC238 = -1;
        s->f_2 = v;
        break;
    }
    return 0;
}

s32 func_800931BC(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

/* A spinning stage object: turns model D_800B4D64[t->mdl] by t->speed per frame (angle wraps at
 * 0x1000). When Spike is within its height band and within t->length of its centre along the arm
 * (Geo_ProjectOnLine) and closer than t->radius to the arm, adds a type-6 collision entry (flags 0x203,
 * probably a knockback hit) at the nearest point, pushing Spike away from the arm. */
s32 SpinHazard_Update(Spin_800931C8_800931C8 *t) {
    SVECTOR rot;
    Hit_800931C8_800931C8 hit;
    XZ_800931C8_800931C8 c;
    XZ_800931C8_800931C8 p;
    Coll_800931C8_800931C8 *o;
    u32 r;
    if (t->mdl < 0) {
        return 0;
    }
    t->angle += t->speed;
    if (t->angle > 0x1000) {
        t->angle -= 0x1000;
    } else if (t->angle < 0) {
        t->angle += 0x1000;
    }
    rot.vz = 0;
    rot.vx = 0;
    rot.vy = t->angle;
    RotMatrixZYX(&rot, (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].mat);
    if ((*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].y < SP_931C8->y - SP_931C8->height) {
        return 0;
    }
    if (SP_931C8->y < (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].y) {
        return 0;
    }
    c.x = (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].x;
    c.z = (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].z;
    p.x = SP_931C8->x;
    p.z = SP_931C8->z;
    r = Geo_ProjectOnLine(&c, &p, -t->angle, &hit);
    if ((u32)t->length < r) {
        return 0;
    }
    if (hit.d < t->radius) {
        rot.vx = SP_931C8->x - hit.x;
        rot.vy = SP_931C8->y - (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].y;
        rot.vz = SP_931C8->z - hit.z;
        VectorNormalSS(&rot, &rot);
        o = CollShape_Alloc();
        if (o != 0) {
            o->f_18 = rot;
            o->x = hit.x;
            o->y = (*(Mdl_800931C8_800931C8 * *)&D_800B4D64)[t->mdl].y;
            o->z = hit.z;
            o->f_20 = t->radius;
            o->f_24 = 1;
            o->f_26 = 0x203;
            Collision_Set(6, o, 0);
        }
    }
    return 0;
}

/* Project the XZ point p onto the line through c with direction ang (using sin^2, cos^2 and
 * sin*cos). Writes the foot point to out[0] (x) / out[1] (z) and the distance from p to it to
 * out[2]; returns the distance from c to the foot point. */
s32 Geo_ProjectOnLine(s16 *c, s16 *p, s16 ang, s32 *out) {
    s32 ss = rsin(ang) * rsin(ang) / 4096;
    s32 cc = rcos(ang) * rcos(ang) / 4096;
    s32 cs = rcos(ang) * rsin(ang) / 4096;
    s32 d;
    out[1] = cs * (c[0] - p[0]) / 4096 + cc * p[1] / 4096 + ss * c[1] / 4096;
    out[0] = cs * (c[1] - p[1]) / 4096 + ss * p[0] / 4096 + cc * c[0] / 4096;
    d = Vec_Length(out[0] - c[0], out[1] - c[1], 0);
    out[2] = Vec_Length(out[0] - p[0], out[1] - p[1], 0);
    return d;
}

s32 func_800935F0(S_P_800935F0_800935F0 *p) {
    SVEC_800935F0_800935F0 d;
    S_O_800935F0_800935F0 *o;
    s32 k;
    if (Vec_Length(g_Spike.f_24 - p->f_8, g_Spike.f_28 - p->f_A, g_Spike.f_2C - p->f_C) > p->f_E) {
        return 0;
    }
    d.vx = g_Spike.f_24 - p->f_8;
    d.vy = g_Spike.f_28 - p->f_A;
    d.vz = g_Spike.f_2C - p->f_C;
    VectorNormalSS(&d, &d);
    switch (p->f_10) {
    case 1:
        k = 0x301;
        break;
    case 2:
        k = 0x401;
        break;
    default:
        k = 0x201;
        break;
    }
    o = CollShape_Alloc();
    if (o != 0) {
        o->f_18 = d;
        o->f_0 = p->f_8;
        o->f_4 = p->f_A;
        o->f_8 = p->f_C;
        o->f_20 = p->f_E;
        o->f_24 = k;
        o->f_26 = 0x202;
        Collision_Set(6, o, 0);
    }
    return 0;
}
