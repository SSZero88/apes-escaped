#include "common.h"
#define GS_9B1C0 ((struct GS_8009B1C0 *)&g_GadgetState)
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u8 pad[0x8]; } DrawBuf_8009B1C0_8009B1C0;
struct GameDb_8009B1C0 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8009B1C0_8009B1C0 db[2]; };
struct GS_8009B1C0 { u8 pad0[4]; s16 windVoice; s16 flyVoice; u32 snd; };
extern u8 g_GadgetState;
extern u8 g_Game;
extern u16 D_800EC23E;
extern u8 D_800EC0C0;
extern u8 D_800EC180;
extern u8 D_800E9E40;
extern u8 D_800E7D00[];
s16 Sound_Play(s32, s32);
void Sound_Stop(s32, s16);
void Model_ProjectVerts(void *, void *, void *);
void func_80017CD4(u32 *, void *, void *);
void func_8006CEF0(void);

typedef struct { u8 pad0[4]; SVECTOR a; SVECTOR b; SVECTOR pouch; u8 pad1C[8]; s16 drawn; u8 pad26[0x7A]; u8 f_A0; u8 padA1; u8 f_A2; } GS_9AD60;
typedef struct { u8 pad0[0xC]; SVECTOR *verts; } Mdl_9AD60;
typedef struct { u8 pad0[0x10]; u8 *bones; u8 pad14[0x4A]; u16 state; } Spike_9AD60;
typedef struct { u32 tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 end; } LineG3_9AD60;
extern GS_9AD60 g_GadgetState_9AD60 asm("g_GadgetState");
extern Spike_9AD60 g_Spike_9AD60 asm("g_Spike");
extern Mdl_9AD60 D_800EC090;
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; } g_Pad_9AD60 asm("g_Pad");
extern struct { u8 pad0[0x8152]; u16 f_8152; } g_Game_9AD60 asm("g_Game");
extern u8 D_800E6916;
extern s16 D_800F5144;
extern u8 D_800E78C0[];
extern u8 D_800F4910[][0x20];
void Gadget_Select(s32, s32);
void GuidedAmmo_UpdateLockOn(GS_9AD60 *);
void GuidedAmmo_ClearLocks(void);
void SetRotMatrix(void *);
void SetTransMatrix(void *);
#define gte_ldv0_(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtv0tr() __asm__ volatile ("nop; nop; mvmva 1, 0, 0, 0, 0")
#define gte_stIR1(r) __asm__ volatile ("mfc2 %0, $9" : "=r"(r))
#define gte_stIR2(r) __asm__ volatile ("mfc2 %0, $10" : "=r"(r))
#define gte_stIR3(r) __asm__ volatile ("mfc2 %0, $11" : "=r"(r))
#define gte_ldv3_(a, b, c) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 0(%1); lwc2 $3, 4(%1); lwc2 $4, 0(%2); lwc2 $5, 4(%2)" : : "r"(a), "r"(b), "r"(c))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_stSZ2(r) __asm__ volatile ("mfc2 %0, $18; nop" : "=r"(r))
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_9AD60;
#define ADDPRIM_BF(ot, p) (((PTag_9AD60 *)(p))->addr = ((PTag_9AD60 *)(ot))->addr, ((PTag_9AD60 *)(ot))->addr = (u32)(p))
#define gte_stsxy3_(a, b, c) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 0(%1); swc2 $14, 0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory")
#define GS g_GadgetState_9AD60

/* Slingback Shooter: Select (with the gadget button) cycles the gadget; while drawn back (state 0x83)
   with a guided shot (ammo kind 3) updates the lock-on, else clears it. Outside first person it
   draws the slingshot model, takes the two prong tips (model vertices 1 and 5) through Spike's hand
   matrix and, for the pouch, either starts it between them, puts it at Spike's other hand (states
   0x81-0x83, 0x85-0x86, bone vertex +0xA28 through the second hand matrix), or eases it back to the
   middle (0x40 lower). The rubber band is a gouraud polyline prong B - pouch - prong A. */
void Slingback_Update(void) {
    SVECTOR *v, *bv;
    s32 ax, ay, bx, by;
    s32 x, y, z, st;
    LineG3_9AD60 *p;

    if (g_Game_9AD60.f_8152 != 0xB && (g_Pad_9AD60.held & g_Pad_9AD60.pressed & PAD_R3)) {
        Gadget_Select(3, 3);
    }
    if (D_800EC23E == 0x83) {
        if (GS.f_A0 + 1 == 3 && GS.f_A2 != 0) {
            GuidedAmmo_UpdateLockOn(&GS);
        }
    } else {
        GuidedAmmo_ClearLocks();
    }
    if (D_800E6916 == 1) {
        return;
    }
    Model_ProjectVerts(&D_800EC090, &D_800E9E40, D_800E7D00);
    func_80017CD4(G_DRAW.db[G_DRAW.cur].ot, D_800E7D00, &D_800EC090);
    SetRotMatrix(D_800F4910[0]);
    SetTransMatrix(D_800F4910[0]);
    v = D_800EC090.verts;
    gte_ldv0_(&v[1]);
    gte_rtv0tr();
    gte_stIR1(ax);
    gte_stIR2(ay);
    GS.a.vx = ax;
    gte_stIR3(ax);
    GS.a.vy = ay;
    GS.a.vz = ax;
    gte_ldv0_(&v[5]);
    gte_rtv0tr();
    gte_stIR1(bx);
    gte_stIR2(by);
    GS.b.vx = bx;
    gte_stIR3(bx);
    GS.b.vy = by;
    GS.b.vz = bx;
    if (GS.drawn == 0) {
        GS.pouch.vy = (GS.b.vy + GS.a.vy) >> 1;
        GS.pouch.vz = (GS.b.vz + GS.a.vz) >> 1;
        GS.drawn = 1;
        GS.pouch.vx = (GS.b.vx + GS.a.vx) >> 1;
    } else {
        st = g_Spike_9AD60.state;
        switch (st) {
        case 0x81:
        case 0x82:
        case 0x83:
        case 0x85:
        case 0x86:
            SetRotMatrix(D_800F4910[1]);
            SetTransMatrix(D_800F4910[1]);
            bv = (SVECTOR *)(g_Spike_9AD60.bones + 0xA28);
            gte_ldv0_(bv);
            gte_rtv0tr();
            gte_stIR1(x);
            gte_stIR2(y);
            GS.pouch.vx = x;
            gte_stIR3(x);
            GS.pouch.vy = y;
            GS.pouch.vz = x;
            break;
        default:
            GS.pouch.vx = (GS.pouch.vx + ((GS.b.vx + GS.a.vx) >> 1)) >> 1;
            GS.pouch.vy = (GS.pouch.vy + ((GS.b.vy + 0x40 + GS.a.vy) >> 1)) >> 1;
            GS.pouch.vz = (GS.pouch.vz + ((GS.b.vz + GS.a.vz) >> 1)) >> 1;
            break;
        }
        D_800F5144 = 1;
    }
    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    p = (LineG3_9AD60 *)G_DRAW.prim;
    gte_ldv3_(&GS.b, &GS.pouch, &GS.a);
    gte_rtpt_n();
    p->c0 = 0x667788;
    p->c1 = 0xCCBBBB;
    ((u8 *)p)[3] = 7;
    p->c2 = 0x667788;
    p->end = 0x55555555;
    ((u8 *)p)[0x17] = 0;
    ((u8 *)p)[7] = 0x58;
    gte_stSZ2(z);
    if (z < 0xA40) {
        gte_stsxy3_(&p->xy0, &p->xy1, &p->xy2);
        ADDPRIM_BF(G_DRAW.db[G_DRAW.cur].ot + (z >> 2), p);
        p++;
        G_DRAW.prim = (u8 *)p;
    }
}

/* Sky Flyer: while Spike's action state is 0x80..0x82 (winding it up) keeps the wind-up sound
 * 0x1D going, and in 0x83..0x84 (flying) the flying sound 0x1E; g_GadgetState+8 tracks which one
 * plays (voices at +4 / +6). Draws the flying model (D_800EC180) or the idle one (D_800EC0C0),
 * and while flying calls func_8006CEF0. */
void SkyFlyer_Update(void) {
    s32 st;
    void *m;
    switch (GS_9B1C0->snd) {
    case 0:
        st = D_800EC23E;
        if (st >= 0x80) {
            if (st < 0x83) {
                GS_9B1C0->windVoice = Sound_Play(0, 0x1D);
                if (GS_9B1C0->windVoice != -1) {
                    GS_9B1C0->snd = 1;
                }
            } else if (st < 0x85) {
                GS_9B1C0->flyVoice = Sound_Play(0, 0x1E);
                if (GS_9B1C0->flyVoice != -1) {
                    GS_9B1C0->snd = 2;
                }
            }
        }
        break;
    case 1:
        st = D_800EC23E;
        if (st < 0x83) {
            if (st >= 0x80) {
                break;
            }
        }
        if (GS_9B1C0->windVoice != -1) {
            Sound_Stop(0x1D, GS_9B1C0->windVoice);
        }
        GS_9B1C0->snd = 0;
        break;
    case 2:
        st = D_800EC23E;
        if (st < 0x85) {
            if (st >= 0x83) {
                break;
            }
        }
        if (GS_9B1C0->flyVoice != -1) {
            Sound_Stop(0x1E, GS_9B1C0->flyVoice);
        }
        GS_9B1C0->snd = 0;
        break;
    }
    st = D_800EC23E;
    if (st < 0x85) {
        if (st < 0x83) {
            m = &D_800EC0C0;
        } else {
            m = &D_800EC180;
        }
    } else {
        m = &D_800EC0C0;
    }
    Model_ProjectVerts(m, &D_800E9E40, D_800E7D00);
    func_80017CD4(((struct GameDb_8009B1C0 *)&g_Game)->db[((struct GameDb_8009B1C0 *)&g_Game)->cur].ot, D_800E7D00, m);
    if (D_800EC23E >= 0x83 && D_800EC23E <= 0x84) {
        func_8006CEF0();
    }
}
