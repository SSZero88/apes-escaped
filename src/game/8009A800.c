#include "common.h"
#define GS_9AA28 ((struct GS_8009AA28 *)&g_GadgetState)
#define GS_9A800 ((struct GS_8009A800 *)&g_GadgetState)
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_8009ABF4_8009ABF4;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_8009AA28_8009AA28;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_8009A800_8009A800;
extern struct S_D_800EC350_8009ABF4 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8009ABF4_8009ABF4 db[2]; } g_Game;
extern u8 D_800EC060[];
extern u8 D_800E7D00[];
extern struct S_D_800F5124 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800F5124;
void Model_ProjectVerts(void *, struct S_D_800F5124 *, void *);
void func_80017CD4(u32 *, void *, void *);
void CompMatrix(struct S_D_800F5124 *, struct S_D_800F5124 *, struct S_D_800F5124 *);
void Fx_DrawGlowBeam(void *, void *, s32, s32);
struct GS_8009AA28 { u8 pad0[4]; MAT_8009AA28_8009AA28 f_4; u8 pad24[4]; s16 f_28; s16 f_2A; s16 f_2C; u8 pad2E[6]; SVECTOR f_34; SVECTOR f_3C; s16 f_44; };
struct Game_8009AA28 { u8 pad0[0x8100]; s32 f_8100; };
struct D_EC060_8009AA28 { u8 pad0[0x9C]; u8 *f_9C; };
extern u8 g_GadgetState;
extern u8 D_800E9E40;
extern u8 D_800F4910;
extern u16 D_800EC23E;
extern s16 D_800E54D4;
int abs(int);
void MagicPunch_Draw(); /* called before its definition, so no s16 conversion at the call */
void SetRotMatrix(MAT_8009AA28_8009AA28 *);
void SetTransMatrix(MAT_8009AA28_8009AA28 *);
void RotTransSV(SVECTOR *, SVECTOR *, s32 *);
void Weapon_DrawSwingTrail(void);
struct GS_8009A800 { u8 pad0[4]; MAT_8009A800_8009A800 f_4; u8 pad24[4]; s16 f_28; s16 f_2A; s16 f_2C; u8 pad2E[6]; SVECTOR f_34; SVECTOR f_3C; s16 f_44; u8 pad46[2]; s16 f_48; };
struct Game_8009A800 { u8 pad0[0x8100]; s32 f_8100; };
struct D_EC060_8009A800 { u8 pad0[0x9C]; u8 *f_9C; };
void MagicPunch_Draw();
void GadgetTrail_Push(void);
s16 Sound_Play(s32, s32);
void Sound_Stop(s32, s16);

/* Probably the Stun Club (gadget 0): the same stick-pumped stretch as MagicPunch_Update (states
 * 0x8A..0x8B pump g_GadgetState+0x28, no upper limit here, drawn at most at 2x), but while
 * Spike's action state is 0x8A..0x8D it loops sound 0x3D (voice +0x48), the sound
 * Gadget_StopSounds stops for the club, and calls GadgetTrail_Push. */
void StunClub_Update(void) {
    s32 flag;
    s32 t;
    s32 st;
    s32 sc;
    if (((struct Game_8009A800 *)&g_Game)->f_8100 & 1) {
        MagicPunch_Draw(&D_800E9E40, &D_800F4910, GS_9A800->f_28 + 0x800);
        return;
    }
    st = D_800EC23E;
    if (st < 0x8C) {
        if (st >= 0x8A && GS_9A800->f_28 < 0x2000) {
            GS_9A800->f_2C = -0x40;
            GS_9A800->f_2A += abs(D_800E54D4) * 4;
        }
    }
    GS_9A800->f_28 += GS_9A800->f_2A;
    GS_9A800->f_2A += GS_9A800->f_2C;
    if (GS_9A800->f_28 < 0) {
        GS_9A800->f_28 = 0;
        GS_9A800->f_2A = 0;
        GS_9A800->f_2C = 0;
    }
    t = GS_9A800->f_44;
    if (t > 0) {
        if (t >= 6) {
            t = 5;
        }
        GS_9A800->f_44 = t - 1;
    }
    sc = GS_9A800->f_28;
    if (sc > 0x800) {
        sc = 0x800;
    }
    MagicPunch_Draw(&D_800E9E40, &D_800F4910, sc + 0x800);
    SetRotMatrix(&GS_9A800->f_4);
    SetTransMatrix(&GS_9A800->f_4);
    RotTransSV((SVECTOR *)(((struct D_EC060_8009A800 *)&D_800EC060)->f_9C + 0x40), &GS_9A800->f_34, &flag);
    RotTransSV((SVECTOR *)(((struct D_EC060_8009A800 *)&D_800EC060)->f_9C + 0x48), &GS_9A800->f_3C, &flag);
    st = D_800EC23E;
    if (st < 0x8E) {
        if (st >= 0x8A) {
            if (GS_9A800->f_48 == -1) {
                GS_9A800->f_48 = Sound_Play(0, 0x3D);
            }
            GadgetTrail_Push();
            goto done;
        }
    }
    if (GS_9A800->f_48 != -1) {
        Sound_Stop(0x3D, GS_9A800->f_48);
        GS_9A800->f_48 = -1;
    }
done:
    Weapon_DrawSwingTrail();
}

/* Magic Punch (identified by the user). The punch arm is the second part of the gadget model and
 * is stretched lengthwise by g_GadgetState+0x28 (scale 0x800 + value, so from half length up to
 * about 1.1x). While Spike's action state is 0x8A or 0x8B and the value is below 0x2000, its
 * speed (+0x2A) is pumped by |D_800E54D4| * 4 (an analog controller value) against a pull of
 * -0x40 (+0x2C); the value stays within 0..0x960 and resets when it falls back to 0. Then builds
 * the matrix (MagicPunch_Draw, which also draws the arm and a pulsing pink-red additive beam along it;
 * the user sees no glow, so it is faint or hidden) and
 * transforms the arm's two points into +0x34 / +0x3C for MagicPunch_AddHitSpheres. */
void MagicPunch_Update(void) {
    s32 flag;
    s32 t;
    s32 st;
    if (((struct Game_8009AA28 *)&g_Game)->f_8100 & 1) {
        MagicPunch_Draw(&D_800E9E40, &D_800F4910, GS_9AA28->f_28 + 0x800);
        return;
    }
    st = D_800EC23E;
    if (st < 0x8C) {
        if (st >= 0x8A && GS_9AA28->f_28 < 0x2000) {
            GS_9AA28->f_2C = -0x40;
            GS_9AA28->f_2A += abs(D_800E54D4) * 4;
        }
    }
    GS_9AA28->f_28 += GS_9AA28->f_2A;
    GS_9AA28->f_2A += GS_9AA28->f_2C;
    if (GS_9AA28->f_28 < 0) {
        GS_9AA28->f_28 = 0;
        GS_9AA28->f_2A = 0;
        GS_9AA28->f_2C = 0;
    } else if (GS_9AA28->f_28 > 0x960) {
        GS_9AA28->f_28 = 0x960;
        GS_9AA28->f_2A = 0;
    }
    t = GS_9AA28->f_44;
    if (t > 0) {
        if (t >= 6) {
            t = 5;
        }
        GS_9AA28->f_44 = t - 1;
    }
    MagicPunch_Draw(&D_800E9E40, &D_800F4910, GS_9AA28->f_28 + 0x800);
    SetRotMatrix(&GS_9AA28->f_4);
    SetTransMatrix(&GS_9AA28->f_4);
    RotTransSV((SVECTOR *)(((struct D_EC060_8009AA28 *)&D_800EC060)->f_9C + 0x40), &GS_9AA28->f_34, &flag);
    RotTransSV((SVECTOR *)(((struct D_EC060_8009AA28 *)&D_800EC060)->f_9C + 0x48), &GS_9AA28->f_3C, &flag);
    Weapon_DrawSwingTrail();
}

void MagicPunch_Draw(m, m2, sc)
    struct S_D_800F5124 *m;
    struct S_D_800F5124 *m2;
    s16 sc;
{
    struct S_D_800F5124 t;
    u8 *obj = D_800EC060;
    u8 *buf = D_800E7D00;
    u32 *ot;
    u32 k;
    t.m[0][0] = 0x1000;
    t.m[0][1] = 0;
    t.m[0][2] = 0;
    t.m[1][0] = 0;
    t.m[1][1] = sc;
    t.m[1][2] = 0;
    t.m[2][0] = 0;
    t.m[2][1] = 0;
    t.m[2][2] = 0x1000;
    t.t[0] = 0x10;
    t.t[1] = 0x4A;
    t.t[2] = -8;
    ot = g_Game.db[g_Game.cur].ot;
    Model_ProjectVerts(obj, m, buf);
    func_80017CD4(ot, buf, obj);
    if (m2 != 0) {
        CompMatrix(m2, &t, &D_800F5124);
    }
    CompMatrix(m, &t, &t);
    obj += 0x90;
    Model_ProjectVerts(obj, &t, buf);
    func_80017CD4(ot, buf, obj);
    k = g_Game.frame & 0x1F;
    if (k > 16) {
        k = 32 - k;
    }
    Fx_DrawGlowBeam(buf + 0x40, buf + 0x48, k + 0x18, 0xFF8080);
}
