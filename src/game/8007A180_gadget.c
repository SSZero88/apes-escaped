#include "common.h"
#include "m2c_macros.h"
#define GS_8007C468 g
#define SPK_7C2A0 ((struct Spike_8007C2A0 *)&g_Spike)
#define GS_7C2A0 ((struct GS_8007C2A0 *)&g_GadgetState)
#define GSL_7B16C ((struct GSl_8007B16C *)&g_GadgetState)
#define GM_7B16C ((struct Game_8007B16C *)&g_Game)
#define GSA_7AA98 ((struct GSA_8007AA98 *)&g_GadgetState)
#define GM_7AA98 ((struct Game_8007AA98 *)&g_Game)
#define SP_7AA98 ((struct Spike_8007AA98 *)&g_Spike)
#define GS_7B374 ((struct GS_8007B374 *)&g_GadgetState)
#define GSND (*(GadgetSnd_8007A180 *)&g_GadgetState)
#define GSND2 (*(GadgetSnd2_8007A180 *)&D_800F51D0)
#include "common.h"
typedef struct { s16 vx, vy, vz, pad; } SVEC_8007A32C_8007A32C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; SVEC_8007A32C_8007A32C f_60; } S_EC1E0_8007A32C_8007A32C;
typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR f_18; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Shape_8007C468_8007C468;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_8007C2A0_8007C2A0;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u8 pad[0x8]; } DrawBuf_8007C2A0_8007C2A0;
typedef struct { s16 vx, vy, vz, pad; } SV_8007C6CC_8007C6CC;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_8007C6CC_8007C6CC;
typedef struct { s32 vx, vy, vz, pad; } VEC_8007C6CC_8007C6CC;
typedef struct { s32 x, y, z; u8 padC[0xC]; SV_8007C6CC_8007C6CC dir; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; } Col_8007C6CC_8007C6CC;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s32 f_8; s32 f_C; s32 f_10; s32 f_14; s32 f_18; u8 pad1C[4]; s16 f_20; s16 f_22; s16 f_24; u8 pad26[0x72]; s16 f_98; s16 f_9A; s16 f_9C; u8 pad9E[2]; u8 ammo; } GS_8007AC64_8007AC64;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; } GS2_8007AC64_8007AC64;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2E]; u16 state; u8 pad60[0x10]; s32 f_70; u8 pad74[0x7E]; s8 gadget; s8 prev; u8 padF4[0x38]; s32 f_12C; } Sp_8007AC64_8007AC64;
typedef struct { s16 vx, vy, vz, pad; } SV_7B374_8007B374;
typedef struct { s16 x, y, z; u8 pad6[0x12]; u16 f_18; } CN_7B374_8007B374;
typedef struct { u8 pad0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 x, y, z; u8 pad30[0x30]; SV_7B374_8007B374 f_60; SV_7B374_8007B374 f_68; CN_7B374_8007B374 *f_70; u8 pad74[0x1A]; s8 f_8E; u8 f_8F; } Veh_7B374_8007B374;
typedef struct { u8 pad0[0x80]; void *f_80; s16 f_84; } Obj_7B374_8007B374;
typedef struct { u8 pad0[0x24]; s32 x, y, z; s32 vx, vy, vz; u8 pad3C[0x20]; s16 f_5C; s16 f_5E; SV_7B374_8007B374 f_60; SV_7B374_8007B374 f_68; u8 pad70[4]; SV_7B374_8007B374 f_74; u8 pad7C[0x10]; s16 f_8C; u8 pad8E[0x26]; s16 f_B4; u8 padB6[2]; s16 f_B8; u8 padBA[6]; s16 f_C0, f_C2, f_C4, f_C6, f_C8, f_CA, f_CC, f_CE; SV_7B374_8007B374 f_D0; u8 padD8[8]; s32 f_E0; u8 padE4[0xE]; s8 f_F2; s8 f_F3; u8 padF4[0xC]; s16 f_100; u8 pad102[0x12]; s32 f_114; s32 f_118; s32 f_11C; u8 pad120[4]; s32 f_124; } Spk_7B374_8007B374;
typedef struct { u8 pad0[0x28]; s16 f_28; s16 f_2A; s16 f_2C; } S_F5120_8007AA1C;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s32 f_8; u8 padC[8]; s16 f_14; s16 f_16; u8 pad18[8]; s16 f_20; s16 f_22; u8 pad24[0x24]; s16 f_48; } GadgetSnd_8007A180;
typedef struct { u8 pad0[0x18]; s16 handle; s16 id; } GadgetSnd2_8007A180;
typedef struct { s32 vx, vy, vz, pad; } VEC_7CAE0_8007CAE0;
typedef struct { s16 vx, vy, vz, pad; } SV_7CAE0_8007CAE0;
typedef struct { u8 pad[0x50]; } Mdl_7CAE0_8007CAE0;
typedef struct { u8 pad0[0xC]; u16 f_C; u16 f_E; u16 f_10; } Gad_7CAE0_8007CAE0;

extern struct S_D_800EC350 { u8 pad_0[0x8124]; u16 f_8124; u8 pad_8126[0x2C]; s16 f_8152; u8 pad_8154[0x50]; void *f_81A4; } g_Game;
extern struct S_D_800F50B0 { u8 pad0[0x18]; u8 *f_18; } D_800F50B0;
extern u8 *D_800B4DA0;
void func_80015AC0(void *, void *);

extern struct S_D_800F5120 { s32 f_0; u8 pad_4[0x20]; s32 f_24; s16 f_28; s16 f_2A; s16 f_2C; u8 pad_2E[0x1A]; s16 f_48; s16 f_4A; s32 f_4C; s32 f_50; u8 pad_54[0x34]; u8 f_88; u8 f_89; u8 f_8A; u8 f_8B; u8 f_8C; u8 f_8D; u8 f_8E; u8 f_8F; s32 f_90; u8 pad_94[0xF]; u8 f_A3; s32 f_A4; } g_GadgetState;
void func_8006CDE0(void);

extern struct S_D_800F5090 { s32 f_0; s16 f_4; s16 pad6; } g_GuidedLocks[];
M2C_UNK Pad_Vibrate(); /* one caller passes a 4th argument */
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern struct S_D_800EC1E0 { u8 pad_0[0x80]; SVECTOR f_80; u8 pad_88[0x60]; s16 f_E8; } g_Spike;
extern struct S_D_800F4730 { u8 pad_0[0x1F4]; s32 f_1F4; s32 f_1F8; s32 f_1FC; u8 pad_200[0x14]; s32 f_214; s32 f_218; s32 f_21C; } D_800F4730;
extern struct S_D_800F51D0 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; SVECTOR f_8; s32 f_10; } D_800F51D0;

extern s8 g_CurrentGadget;
struct S_D_800EC1E0_8007CA48 { u8 pad0[0x5E]; u16 f_5E; u8 pad60[0x88]; s16 f_E8; };
struct S_D_800EC350_8007CA48 { u8 pad0[0x8150]; u16 f_8150; u16 f_8152; };
extern M2C_UNK D_800EC204;
extern u8 D_800E6916;
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
void func_8004B54C(SVEC_8007A32C_8007A32C *);
s32 VectorNormalSS(void *, void *);
void *GuidedAmmo_FindTarget(void *, SVEC_8007A32C_8007A32C *, s32);
void func_8007A48C(s32 x);
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void GuidedAmmo_DrawReticle(s32, s32, s32);
struct S_D_800F5090_8007A32C { SVEC_8007A32C_8007A32C *f_0; s16 f_4; };

/* Stops the looping sounds belonging to gadget `g` (called when pausing), then
 * the shared gadget loop.
 */
struct Game_8007AFC4 { u8 pad0[0x8126]; u16 stage; };
void Gadget_SaveSlots(void);
struct GSt_8007C468 { u8 pad0[0x34]; s16 f_34; s16 f_36; s16 f_38; s16 pad3A; s16 f_3C; s16 f_3E; s16 f_40; s16 pad42; u8 pad44[8]; Shape_8007C468_8007C468 *f_4C; Shape_8007C468_8007C468 *f_50; };
struct Spike_8007C468 { u8 pad0[0x60]; SVECTOR f_60; };
Shape_8007C468_8007C468 *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);
struct GameDb_8007C2A0 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8007C2A0_8007C2A0 db[2]; };
struct Game_8007C2A0 { u8 pad0[0x8100]; s32 f_8100; };
struct Spike_8007C2A0 { u8 pad0[0x14]; MAT_8007C2A0_8007C2A0 *f_14; u8 pad18[0x48]; SVECTOR f_60; SVECTOR f_68; };
struct GS_8007C2A0 { u8 pad0[0x54]; s16 f_54; };
extern u8 D_800E7D00[];
extern M2C_UNK D_800F50D4;
void Matrix_LookAt(SVECTOR *, SVECTOR *, MAT_8007C2A0_8007C2A0 *, s32);
void Anim_SetFrame(void *);
void func_80015504(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4(u32 *, void *, void *);
void func_8007BD38(void);
void func_8006896C(s32);
void func_8004BC9C(void);
void func_8006C6A4(void *);
void Spike_SetPlayMode(s32 req);
struct GSl_8007B16C { u8 pad0[0x88]; s8 slot[4]; u8 pad8C[0x17]; u8 f_A3; s32 f_A4; };
struct Game_8007B16C { u8 pad0[0x8122]; u16 f_8122; u8 pad8124[2]; u16 stage; u8 pad8128[2]; u16 f_812A; u8 f_812C; };
struct D51D0_8007B16C { u8 pad0[0x18]; s16 f_18; s16 f_1A; };
void Gadget_RestoreSlots(void);
s32 Gadget_SetupStageLoadout(s32);
/* Selects gadget g (previous prev, -1 when restoring). Stops the sounds of the Stun Club,
 * Monkey Radar, Super Hoop or Sky Flyer being put away. Per gadget: Stun Club re-inits its swing,
 * Monkey Radar starts its scan (func_80099D20), Slingback re-selected cycles the ammo type
 * (+0xA0: regular/explosive/guided, sound 3) or else resets it (and re-enters aiming if in look
 * mode), Super Hoop and Magic Punch reset their state, Sky Flyer clears D_800F5128, RC Car
 * re-selected while not in the 0xC0 state calls RcCar_Place at Spike (sound 0x2E).
 * Stores g / prev at g_Spike+0xF2 / +0xF3. If it changed: switch sound 0x24, Spike back to an
 * idle state (0, or 0x24 when below +0x12C), swaps gadget state; returns 1 (0 if unchanged). */
s32 Gadget_Select(s32 g, s32 prev);
void Gadget_UpdateHudCursor(void);
struct GSA_8007AA98 { u8 pad0[0xA0]; u8 type; u8 explosive; u8 guided; };
struct Game_8007AA98 { u8 pad0[0x8120]; u16 f_8120; u8 pad8122[2]; u16 f_8124; u8 pad8126[0x132]; SVECTOR f_8258; s16 f_8260; s16 f_8262; s16 f_8264; };
struct Spike_8007AA98 { u8 pad0[0x1C]; SVECTOR f_1C; s32 x; s32 y; s32 z; u8 pad30[0x30]; SVECTOR f_60; };
void Projectile_Spawn(SVECTOR *, SVECTOR *, s32);
extern s32 D_800F51E0;
extern u8 D_800EC130[];
extern void *D_800EC358;
struct Game_8007C6CC { u8 pad0[0x8152]; u16 f_8152; };
void func_8004637C(void *);
void RotMatrixX(s32, void *);
void Matrix_FromDirection(void *, void *);
void ScaleMatrix(void *, void *);
void MulMatrix0(void *, void *, void *);
void CompMatrix(void *, void *, void *);
void Model_ProjectVerts(void *, void *, void *);
void Light_SetColorMode(s32, s32, s32, s32);
s32 Water_Query(s32, s32, s32);
s32 Floor_GetHeight(s32, s32, s32);
void Effect_SpawnAt(s32, void *);
struct S_D_800F51D0_8007C6CC { s16 x, y, z, rot; SV_8007C6CC_8007C6CC vel; s32 timer; };
extern u8 D_800E6902;
extern s32 D_800F5128;
void Gadget_StopSounds(s32);
void func_8007AA64(void);
void func_8001F884(void);
void GuidedAmmo_ClearLocks(void);
void Camera_EnterAim(void);
void Camera_ExitAim(void);
void RcCar_Place(s32, s32, s32);
void func_8004AA24(void);
void func_8006DAC8(void);
void func_80099D20(void);
void Spike_SetState(s32);
void Spike_SwapGadgetState(void);
s32 func_8007F5D4(void);
void func_8006CFA4(void);
struct Game_7B374 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x20]; u16 f_8124; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 pad812C[0x24]; u16 f_8150; s16 f_8152; };
struct GS_8007B374 { u8 pad0[4]; s16 f_4; u8 pad6[2]; s32 f_8; };
extern struct S_D_800F4DB0 { u8 pad0[0x20]; u32 f_20; } D_800F4DB0;
extern Veh_7B374_8007B374 *D_800B4DC4;
extern Obj_7B374_8007B374 *D_800B4D70;
extern struct S_D_800E68D0 { u8 pad0[0x32]; u8 f_32; u8 pad33[0x13]; u8 f_46; } D_800E68D0;
extern s16 D_800F5174;
extern s32 D_800F4DD0;
extern s16 D_800EC2E0;
extern s16 D_800EC26C;
extern void (*D_800B4DD0)(s32);
void func_8004B590(s32, s32);
void func_8006BF84(void);
s32 Vec_Length(s32, s32, s32);
s32 Math_ISqrt(s32);
void Camera_ExitLook(void);
void Spike_LoadModelData(void *);
void Fx_DebrisExplosion(s32, s32, s32);
void Game_SetMode(s32, s32, s32);
s32 Stage_IsCleared(void);
void func_80095244(s32);
void func_8008C064(void *);
extern u16 D_800E549E;


/* Stop the looping sounds gadget g owns and clear their handles, then the shared one
   at D_800F51D0: Stun Club 0x3D, Monkey Radar 0x25/0x26, Super Hoop 0x2C twice, and the
   Sky Flyer's 0x1D/0x1E (flag word: bit 0 = 0x1D playing, bit 1 = 0x1E playing). */
extern Gad_7CAE0_8007CAE0 g_Gad7CAE0 asm("g_GadgetState");
extern Mdl_7CAE0_8007CAE0 D_800EC0B0;
extern Mdl_7CAE0_8007CAE0 D_800EC100;
void RotTrans(SV_7CAE0_8007CAE0 *, s32 *, s32 *);

void Gadget_StopSounds(s32 g) {
    switch (g) {
    case 6:
        if (GSND.f_8 != 0) {
            if (GSND.f_8 & 1) {
                Sound_Stop(0x1D, GSND.f_4);
            }
            if (GSND.f_8 & 2) {
                Sound_Stop(0x1E, GSND.f_6);
            }
            GSND.f_8 = 0;
        }
        break;
    case 0:
        if (GSND.f_48 != -1) {
            Sound_Stop(0x3D, GSND.f_48);
            GSND.f_48 = -1;
        }
        break;
    case 2:
        if (GSND.f_14 != -1) {
            Sound_Stop(0x25, GSND.f_14);
            GSND.f_14 = -1;
        }
        if (GSND.f_16 != -1) {
            Sound_Stop(0x26, GSND.f_16);
            GSND.f_16 = -1;
        }
        break;
    case 4:
        if (GSND.f_20 != -1) {
            Sound_Stop(0x2C, GSND.f_20);
            GSND.f_20 = -1;
        }
        if (GSND.f_22 != -1) {
            Sound_Stop(0x2C, GSND.f_22);
            GSND.f_22 = -1;
        }
        break;
    }
    if (GSND2.handle != -1) {
        Sound_Stop(GSND2.id, GSND2.handle);
        GSND2.handle = -1;
        GSND2.id = -1;
    }
}

void GuidedAmmo_ClearLocks(void) {
    s32 i;

    for (i = 2; i >= 0; i--) {
        g_GuidedLocks[i].f_0 = 0;
    }
}

/* Guided ammo lock-on: aims along the first-person view (or Spike's facing),
 * locks the nearest target within 400 and draws markers on up to 3 locked targets.
 */
void GuidedAmmo_UpdateLockOn(void) {
    SVEC_8007A32C_8007A32C d;
    s32 sxy;
    s32 p;
    void *t;
    s32 i;
    struct S_D_800F5090_8007A32C *e;
    if (D_800E6916 == 1) {
        func_8004B54C(&d);
        d.vx -= ((S_EC1E0_8007A32C_8007A32C *)&g_Spike)->f_24;
        d.vy -= ((S_EC1E0_8007A32C_8007A32C *)&g_Spike)->f_28;
        d.vz -= ((S_EC1E0_8007A32C_8007A32C *)&g_Spike)->f_2C;
        VectorNormalSS(&d, &d);
    } else {
        d = ((S_EC1E0_8007A32C_8007A32C *)&g_Spike)->f_60;
    }
    t = GuidedAmmo_FindTarget(&D_800EC204, &d, 400);
    if (t != 0) {
        func_8007A48C(t);
    }
    SetRotMatrix(&D_800E78C0);
    SetTransMatrix(&D_800E78C0);
    for (i = 0; i < 3; i++) {
        e = &((struct S_D_800F5090_8007A32C *)&g_GuidedLocks)[i];
        if (e->f_0 != 0) {
            if (e->f_4 > 0) {
                e->f_4--;
            }
            RotTransPers(e->f_0, &sxy, &p, &p);
            GuidedAmmo_DrawReticle(sxy & 0xFFFF, sxy >> 16, e->f_4);
        }
    }
}

void func_8007A48C(s32 x) {
    s32 i;
    for (i = 2; i >= 0; i--) {
        if (g_GuidedLocks[i].f_0 == x) {
            return;
        }
    }
    for (i = 0; i < 3; i++) {
        if (g_GuidedLocks[i].f_0 == 0) {
            g_GuidedLocks[i].f_0 = x;
            g_GuidedLocks[i].f_4 = 8;
            Sound_PlayFixed(0x18);
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8007A180_gadget", Club_SwingUpdate);

INCLUDE_RODATA("asm/nonmatchings/game/8007A180_gadget", D_800A5EF0);
INCLUDE_RODATA("asm/nonmatchings/game/8007A180_gadget", jtbl_800A5EF8);


void func_8007AA1C(void) {
    if (D_800E549E & 8) {
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_2A = 0x190;
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_28 = 0;
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_2C = -0x40;
    } else {
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_2A = 0x320;
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_28 = 0;
        (*(S_F5120_8007AA1C *)&g_GadgetState).f_2C = -0x80;
    }
}

void func_8007AA64(void) {
    g_GadgetState.f_48 = -1;
    g_GadgetState.f_24 = 0;
    g_GadgetState.f_28 = 0;
    g_GadgetState.f_2A = 0;
    g_GadgetState.f_2C = 0;
    g_GadgetState.f_4A = 0x1000;
    g_GadgetState.f_4C = 0;
    g_GadgetState.f_50 = 0;
}

/* Fires the Slingback. g_GadgetState+0xA0 is the selected ammo: 0 regular (unlimited, per the
 * user), 1 explosive (count +0xA1), 2 guided (count +0xA2). If the selected special ammo has rounds
 * left the shot is type 2 / 3 and one round is used up, except when g_Game+0x8124 is 0x20 or
 * +0x8120 is 0x13 (special ammo not consumed there); otherwise a regular shot (type 1). Aims along
 * the first-person view (D_800E6916 == 1), else at the nearest target GuidedAmmo_FindTarget finds
 * within 400, else straight along Spike's facing; then Projectile_Spawn(from, dir, type). */
void Slingback_Fire(void) {
    SVECTOR d1;
    SVECTOR d2;
    SVECTOR *t;
    s32 type = 1;
    switch (GSA_7AA98->type) {
    case 1:
        if (GSA_7AA98->explosive != 0) {
            type = 2;
            if (GM_7AA98->f_8124 != 0x20 && GM_7AA98->f_8120 != 0x13) {
                GSA_7AA98->explosive--;
            }
        }
        break;
    case 2:
        if (GSA_7AA98->guided != 0) {
            type = 3;
            if (GM_7AA98->f_8124 != 0x20 && GM_7AA98->f_8120 != 0x13) {
                GSA_7AA98->guided--;
            }
        }
        break;
    }
    if (D_800E6916 == 1) {
        d2.vx = GM_7AA98->f_8260 - GM_7AA98->f_8258.vx;
        d2.vy = GM_7AA98->f_8262 - GM_7AA98->f_8258.vy;
        d2.vz = GM_7AA98->f_8264 - GM_7AA98->f_8258.vz;
        VectorNormalSS(&d2, &d2);
        Projectile_Spawn(&SP_7AA98->f_1C, &d2, type);
    } else {
        t = GuidedAmmo_FindTarget(&SP_7AA98->x, &SP_7AA98->f_60, 400);
        if (t != 0) {
            d1.vx = t->vx - SP_7AA98->x;
            d1.vy = t->vy - SP_7AA98->y;
            d1.vz = t->vz - SP_7AA98->z;
            VectorNormalSS(&d1, &d1);
            Projectile_Spawn(&SP_7AA98->f_1C, &d1, type);
        } else {
            Projectile_Spawn(&SP_7AA98->f_1C, &SP_7AA98->f_60, type);
        }
    }
}

s32 Gadget_Select(s32 g, s32 prev) {
    switch (prev) {
    case 6:
        if (g != prev) {
            Gadget_StopSounds(6);
        }
        break;
    case 0:
        if (g != 0) {
            Gadget_StopSounds(0);
        }
        break;
    case 2:
        if (g != prev) {
            Gadget_StopSounds(2);
        }
        break;
    case 4:
        Gadget_StopSounds(4);
        break;
    }
    switch (g) {
    case 0:
        if (prev != 0) {
            func_8007AA64();
            func_8001F884();
        }
        break;
    case 6:
        if (prev != 6) {
            D_800F5128 = 0;
        }
        break;
    case 3:
        if (g_CurrentGadget == g) {
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_9A = 0x1C;
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).ammo = ((*(GS_8007AC64_8007AC64 *)&g_GadgetState).ammo + 1) % 3;
            Sound_PlayFixed(3);
            GuidedAmmo_ClearLocks();
        } else {
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_9C = 1;
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_98 = 0x190;
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).ammo = 0;
            (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_24 = 0;
        }
        if (D_800E6902 == 1) {
            Camera_EnterAim();
        }
        break;
    case 7:
        if (((*(Sp_8007AC64_8007AC64 *)&g_Spike).f_70 & 0xF0) != 0xC0 && prev == g) {
            RcCar_Place((*(Sp_8007AC64_8007AC64 *)&g_Spike).x, (*(Sp_8007AC64_8007AC64 *)&g_Spike).y, (*(Sp_8007AC64_8007AC64 *)&g_Spike).z);
            func_8004AA24();
            Sound_PlayFixed(0x2E);
        }
        if (D_800E6916 == 1) {
            Camera_ExitAim();
        }
        break;
    case 4:
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_4 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_8 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_C = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_10 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_14 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_20 = -1;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_22 = -1;
        func_8006DAC8();
        break;
    case 2:
        if (prev != 2) {
            func_80099D20();
        }
        break;
    case 5:
        ((GS2_8007AC64_8007AC64 *)&g_GadgetState)->f_4 = 0x400;
        ((GS2_8007AC64_8007AC64 *)&g_GadgetState)->f_8 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_14 = 0;
        (*(GS_8007AC64_8007AC64 *)&g_GadgetState).f_18 = 0;
        ((GS2_8007AC64_8007AC64 *)&g_GadgetState)->f_6 = 0x400;
        break;
    }
    (*(Sp_8007AC64_8007AC64 *)&g_Spike).gadget = g;
    (*(Sp_8007AC64_8007AC64 *)&g_Spike).prev = prev;
    if (g != 3 && D_800E6916 == 1) {
        Camera_ExitAim();
    }
    if (prev != g) {
        if (prev != -1 && g != 9) {
            Sound_PlayFixed(0x24);
        }
        if ((*(Sp_8007AC64_8007AC64 *)&g_Spike).state >= 0x80) {
            Spike_SetState((*(Sp_8007AC64_8007AC64 *)&g_Spike).f_12C > (*(Sp_8007AC64_8007AC64 *)&g_Spike).y ? 0x24 : 0);
        }
        Spike_SwapGadgetState();
        if (!func_8007F5D4()) {
            func_8006CDE0();
        }
        if (g == 7) {
            func_8006CFA4();
        }
        return 1;
    }
    return 0;
}



void func_8007AFB8(void) {
    g_GadgetState.f_0 = 0;
}

/* Stage start: clears the four gadget slots (g_GadgetState+0x88..0x8B), then for special stages
 * fills them. Tutorial stages 0x5C..0x61 put gadget 2..7 in the 4th slot (0x62 puts gadget 0)
 * and return it as the gadget in hand; stages 0x63..0x67 get the Stun Club (0) and Net (1)
 * plus fixed extras. Other stages return `g` unchanged. */
struct GadgetSlots_8007AFC4 { u8 pad0[0x88]; s8 slot[4]; u8 pad8C[0x15]; u8 f_A1; u8 f_A2; };
s32 Gadget_SetupStageLoadout(s32 g) {
    Gadget_SaveSlots();
    ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[0] = -1;
    ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[1] = -1;
    ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[2] = -1;
    ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = -1;
    switch (((struct Game_8007AFC4 *)&g_Game)->stage) {
    case 0x5C:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 2;
        g = 2;
        break;
    case 0x5D:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 3;
        g = 3;
        break;
    case 0x5E:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 4;
        g = 4;
        break;
    case 0x5F:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 5;
        g = 5;
        break;
    case 0x60:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 6;
        g = 6;
        break;
    case 0x61:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 7;
        g = 7;
        break;
    case 0x62:
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 0;
        g = 0;
        break;
    case 0x63:
    case 0x64:
        g = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[0] = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 1;
        break;
    case 0x65:
        g = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[1] = 3;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[2] = 7;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 1;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->f_A1 = 9;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[0] = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->f_A2 = 5;
        break;
    case 0x66:
        g = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[1] = 2;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[2] = 4;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[0] = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 1;
        break;
    case 0x67:
        g = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[1] = 6;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[2] = 7;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[0] = 0;
        ((struct GadgetSlots_8007AFC4 *)&g_GadgetState)->slot[3] = 1;
        break;
    }
    return g;
}



/* Picks the starting gadget and slots for the game mode g_Game+0x812C: modes 0, 7 and 8 give
 * the Stun Club (slot 1) and Net (slot 4); mode 1 sub-mode 3 (the races with Jake, per the user) gives only the Sky Flyer (6); stage 0x13, the first race, gets nothing;
 * sub-modes 14/15 use Gadget_SetupStageLoadout; mode 2 does stage 0x5A specially and the
 * tutorial stages via Gadget_SetupStageLoadout. Then switches to that gadget and updates the HUD
 * cursor. */
void Gadget_SetupForMode(void) {
    s32 g = g_CurrentGadget;
    switch (GM_7B16C->f_812C) {
    case 0:
    case 7:
    case 8:
        g = 0;
        GSL_7B16C->slot[1] = -1;
        GSL_7B16C->slot[2] = -1;
        GSL_7B16C->slot[3] = 1;
        GSL_7B16C->slot[0] = 0;
        GSL_7B16C->f_A4 = 3;
        Gadget_SaveSlots();
        break;
    case 1:
        switch (GM_7B16C->f_8122) {
        case 15:
            g = Gadget_SetupStageLoadout(g);
            break;
        case 14:
            g = Gadget_SetupStageLoadout(g);
            break;
        case 3:
            Gadget_SaveSlots();
            GSL_7B16C->slot[0] = -1;
            GSL_7B16C->slot[1] = -1;
            GSL_7B16C->slot[2] = -1;
            if (GM_7B16C->stage == 0x13) {
                GSL_7B16C->slot[3] = -1;
                g = 9;
            } else {
                GSL_7B16C->slot[3] = 6;
                g = 6;
            }
            break;
        }
        break;
    case 2:
        if (GM_7B16C->stage == 0x5A && GM_7B16C->f_812A != 0) {
            Gadget_RestoreSlots();
            g = g_CurrentGadget;
        } else if (GM_7B16C->stage >= 0x5C && GM_7B16C->stage <= 0x62) {
            g = Gadget_SetupStageLoadout(g);
        }
        break;
    }
    g_CurrentGadget = 9;
    ((struct D51D0_8007B16C *)&D_800F51D0)->f_18 = -1;
    ((struct D51D0_8007B16C *)&D_800F51D0)->f_1A = -1;
    GSL_7B16C->f_A3 = 1;
    Gadget_Select(g, -1);
    Gadget_UpdateHudCursor();
}

INCLUDE_RODATA("asm/nonmatchings/game/8007A180_gadget", jtbl_800A6018_pad);


void Gadget_Unlock(s32 arg0) {
    g_GadgetState.f_A4 = (s32) (g_GadgetState.f_A4 | arg0);
}

/* Changes Spike's play mode (g_Game+0x8150) on request `req`, running the exit/enter actions.
 * 0xB/0xE end play (mode +0x8152 = 0xB, stop Spike). From the normal modes 0/5/6: 1 and 3 move
 * Spike onto the vehicle D_800B4DC4, 5/6 start a guided move between two points, 9 stops,
 * 10 swaps Spike's model for object D_800B4D70, 12 drops him; from modes 1/3 he gets off the
 * vehicle again (or it is destroyed when its health +0x8E ran out); mode 8 leaves the stage
 * through Game_SetMode; mode 10 restores Spike's own model and gadget. */
void Spike_SetPlayMode(s32 req) {
    Veh_7B374_8007B374 *o;
    Veh_7B374_8007B374 *v;
    Veh_7B374_8007B374 *u;
    Veh_7B374_8007B374 *w;
    s32 d1;
    s32 d2;
    SV_7B374_8007B374 t;

    if (req == 0xB || req == 0xE) {
        (*(struct Game_7B374 *)&g_Game).f_8152 = 0xB;
        D_800F4DB0.f_20 &= ~0x10;
        if (req == 0xB) {
            (*(struct Game_7B374 *)&g_Game).f_8100 = 0xE;
        }
        (*(Spk_7B374_8007B374 *)&g_Spike).vx = 0;
        (*(Spk_7B374_8007B374 *)&g_Spike).vy = 0;
        (*(Spk_7B374_8007B374 *)&g_Spike).vz = 0;
        if ((*(Spk_7B374_8007B374 *)&g_Spike).f_F2 == 4 && GS_7B374->f_4 != 0) {
            GS_7B374->f_4 = 0;
            GS_7B374->f_8 = 0;
        }
        return;
    }
    switch ((*(struct Game_7B374 *)&g_Game).f_8150) {
    case 0:
    case 5:
    case 6:
        switch (req) {
        case 1:
            v = D_800B4DC4;
            (*(Spk_7B374_8007B374 *)&g_Spike).x = v->x;
            (*(Spk_7B374_8007B374 *)&g_Spike).y = v->y;
            (*(Spk_7B374_8007B374 *)&g_Spike).z = v->z;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_60 = v->f_60;
            v->f_70->f_18 |= 0x8000;
            (*(Spk_7B374_8007B374 *)&g_Spike).vx = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vy = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vz = 0;
            (*(struct Game_7B374 *)&g_Game).f_8150 = 1;
            func_8004B590(0, 0);
            if ((*(struct Game_7B374 *)&g_Game).f_8126 != 0x52) {
                Sound_PlayFixed(0xAC);
            }
            Gadget_Select(9, (*(Spk_7B374_8007B374 *)&g_Spike).f_F2);
            func_8006BF84();
            return;
        case 3:
            u = D_800B4DC4;
            (*(Spk_7B374_8007B374 *)&g_Spike).x = u->x;
            (*(Spk_7B374_8007B374 *)&g_Spike).y = u->y;
            (*(Spk_7B374_8007B374 *)&g_Spike).z = u->z;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_60 = u->f_60;
            u->f_70->f_18 |= 0x8000;
            (*(Spk_7B374_8007B374 *)&g_Spike).vx = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vy = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vz = 0;
            (*(struct Game_7B374 *)&g_Game).f_8150 = 3;
            Sound_PlayFixed(0xAF);
            Gadget_Select(9, (*(Spk_7B374_8007B374 *)&g_Spike).f_F2);
            return;
        case 8:
            (*(struct Game_7B374 *)&g_Game).f_8150 = 8;
            D_800F5174 = 0x26;
            return;
        case 5:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            Spike_SetState(0x38);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_74.vx = (*(Spk_7B374_8007B374 *)&g_Spike).f_B4 - (*(Spk_7B374_8007B374 *)&g_Spike).x;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_74.vy = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_74.vz = (*(Spk_7B374_8007B374 *)&g_Spike).f_B8 - (*(Spk_7B374_8007B374 *)&g_Spike).z;
            VectorNormalSS(&(*(Spk_7B374_8007B374 *)&g_Spike).f_74, &(*(Spk_7B374_8007B374 *)&g_Spike).f_74);
            return;
        case 6:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            Spike_SetState(0x3D);
            d1 = Vec_Length((*(Spk_7B374_8007B374 *)&g_Spike).x - (*(Spk_7B374_8007B374 *)&g_Spike).f_C0, 0, (*(Spk_7B374_8007B374 *)&g_Spike).z - (*(Spk_7B374_8007B374 *)&g_Spike).f_C4);
            d2 = Vec_Length((*(Spk_7B374_8007B374 *)&g_Spike).x - (*(Spk_7B374_8007B374 *)&g_Spike).f_C6, 0, (*(Spk_7B374_8007B374 *)&g_Spike).z - (*(Spk_7B374_8007B374 *)&g_Spike).f_CA);
            t.vx = (*(Spk_7B374_8007B374 *)&g_Spike).f_C6 - (*(Spk_7B374_8007B374 *)&g_Spike).f_C0;
            t.vy = (*(Spk_7B374_8007B374 *)&g_Spike).f_C8 - (*(Spk_7B374_8007B374 *)&g_Spike).f_C2;
            t.vz = (*(Spk_7B374_8007B374 *)&g_Spike).f_CA - (*(Spk_7B374_8007B374 *)&g_Spike).f_C4;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_CC = (d2 << 12) / (d1 + d2);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_CE = Math_ISqrt(VectorNormalSS(&t, &(*(Spk_7B374_8007B374 *)&g_Spike).f_D0));
            return;
        case 10:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            D_800B4D70->f_84 = (*(Spk_7B374_8007B374 *)&g_Spike).f_F2;
            Gadget_Select(9, (*(Spk_7B374_8007B374 *)&g_Spike).f_F2);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_5E = 0x80;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_5C = 0;
            if (D_800E68D0.f_46 == 1) {
                Camera_ExitAim();
            }
            if (D_800E68D0.f_32 == 1) {
                D_800E68D0.f_32 = 0;
            }
            Spike_LoadModelData(D_800B4D70->f_80);
            return;
        case 9:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            Spike_SetState(0x48);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_11C = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_114 = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vz = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vx = 0;
            D_800F4DD0 = 0;
            Camera_ExitAim();
            Camera_ExitLook();
            return;
        case 12:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_100 = 0x1E;
            (*(Spk_7B374_8007B374 *)&g_Spike).y -= 0x200;
            Spike_SetState(0x24);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_8C = 0;
            return;
        case 7:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            Spike_SetState(0x2E);
            return;
        case 0:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            (*(struct Game_7B374 *)&g_Game).f_8152 = 0;
            (*(struct Game_7B374 *)&g_Game).f_8100 = 0;
            return;
        case 13:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            D_800EC2E0 = 0;
            return;
        default:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            return;
        }
    case 1:
        (*(struct Game_7B374 *)&g_Game).f_8150 = req;
        o = D_800B4DC4;
        if (o->f_8E <= 0) {
            Sound_PlayFixed(0x79);
            Fx_DebrisExplosion(o->f_1C, o->f_1E, o->f_20);
            D_800B4DD0(1);
        } else {
            o->f_70->f_18 &= 0x7FFF;
            o->f_70->x = (*(Spk_7B374_8007B374 *)&g_Spike).x;
            o->f_70->y = (*(Spk_7B374_8007B374 *)&g_Spike).y;
            o->f_70->z = (*(Spk_7B374_8007B374 *)&g_Spike).z;
            o->f_60 = (*(Spk_7B374_8007B374 *)&g_Spike).f_60;
            o->f_68 = (*(Spk_7B374_8007B374 *)&g_Spike).f_68;
        }
        o->f_8F = 10;
        Spike_SetState(8);
        (*(Spk_7B374_8007B374 *)&g_Spike).vy = -0x1E;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_124 = 0xFFFE2000;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_118 = 0xFFFE2000;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_E0 = 0;
        (*(Spk_7B374_8007B374 *)&g_Spike).y -= 0xA2;
        if (D_800E6916 == 1) {
            Camera_ExitAim();
        }
        Gadget_Select((*(Spk_7B374_8007B374 *)&g_Spike).f_F3, (*(Spk_7B374_8007B374 *)&g_Spike).f_F2);
        return;
    case 3:
        (*(struct Game_7B374 *)&g_Game).f_8150 = req;
        Spike_SetState(8);
        w = D_800B4DC4;
        w->f_70->x = (*(Spk_7B374_8007B374 *)&g_Spike).x;
        w->f_70->y = (*(Spk_7B374_8007B374 *)&g_Spike).y + 0x80;
        w->f_70->z = (*(Spk_7B374_8007B374 *)&g_Spike).z;
        w->f_60 = (*(Spk_7B374_8007B374 *)&g_Spike).f_60;
        w->f_70->f_18 &= 0x7FFF;
        w->f_8F = 10;
        (*(Spk_7B374_8007B374 *)&g_Spike).vy = -0x1E;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_124 = 0xFFFE2000;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_118 = 0xFFFE2000;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_E0 = 0;
        (*(Spk_7B374_8007B374 *)&g_Spike).y -= 2;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_60.vx = -(*(Spk_7B374_8007B374 *)&g_Spike).f_60.vx;
        (*(Spk_7B374_8007B374 *)&g_Spike).f_60.vz = -(*(Spk_7B374_8007B374 *)&g_Spike).f_60.vz;
        Gadget_Select((*(Spk_7B374_8007B374 *)&g_Spike).f_F3, (*(Spk_7B374_8007B374 *)&g_Spike).f_F2);
        return;
    case 8:
        switch (req) {
        case 0:
        default:
            (*(struct Game_7B374 *)&g_Game).f_8100 = 0;
            if ((*(struct Game_7B374 *)&g_Game).f_8124 == 0x20) {
                Game_SetMode(3, (*(struct Game_7B374 *)&g_Game).f_8126, (*(struct Game_7B374 *)&g_Game).f_812A);
                (*(struct Game_7B374 *)&g_Game).f_8150 = req;
                return;
            }
            if (Stage_IsCleared()) {
                Game_SetMode(0x12, (*(struct Game_7B374 *)&g_Game).f_8126, (*(struct Game_7B374 *)&g_Game).f_812A);
                return;
            }
            Game_SetMode(3, (*(struct Game_7B374 *)&g_Game).f_8126, (*(struct Game_7B374 *)&g_Game).f_812A);
            func_80095244(0);
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            return;
        case 9:
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            Spike_SetState(0x48);
            (*(Spk_7B374_8007B374 *)&g_Spike).f_11C = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).f_114 = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vz = 0;
            (*(Spk_7B374_8007B374 *)&g_Spike).vx = 0;
            D_800F4DD0 = 0;
            return;
        }
    case 10:
        (*(struct Game_7B374 *)&g_Game).f_8150 = req;
        Gadget_Select(D_800B4D70->f_84, -1);
        func_8008C064(D_800B4D70->f_80);
        func_8008C064(D_800B4D70);
        Spike_LoadModelData(0);
        Spike_SetState(0);
        D_800EC26C = 0;
        return;
    default:
        if (req == 0xD) {
            (*(struct Game_7B374 *)&g_Game).f_8150 = req;
            D_800EC2E0 = 0;
            return;
        }
        (*(struct Game_7B374 *)&g_Game).f_8150 = req;
        return;
    }
}



void func_8007BC9C(void) {
    g_Game.f_8152 = 0;
}

void func_8007BCB4(void) {
    u8 *base = (u8 *)0x80103000;
    if (g_Game.f_8124 != 0x20) {
        func_80015AC0(&D_800F50B0, g_Game.f_81A4);
        D_800F50B0.f_18 = base + *(u16 *)(base + 0xB8) * 4;
        D_800B4DA0 = base + *(u16 *)(base + 0xB4) * 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8007A180_gadget", func_8007BD38);

/* Spike_Update's handler for game sub-mode 8 (g_Game+0x8150). Draws Spike, then counts
 * g_GadgetState+0x54 down to 0: strong rumble pulses every 5 frames while >= 13, a light one
 * from 12 to 4; at 38 calls func_8006896C(5) and func_8004BC9C, at 37 sets g_Game+0x8100 bits
 * 0xE, at 9 calls func_8006896C(6); at 0 Spike_SetPlayMode(0) ends it. Which scene this is is not
 * known yet. */
void Spike_UpdateMode8Scene(void) {
    s16 t;
    Matrix_LookAt(&SPK_7C2A0->f_60, &SPK_7C2A0->f_68, SPK_7C2A0->f_14, 0);
    Anim_SetFrame(SPK_7C2A0);
    func_80015504(SPK_7C2A0, 3);
    Model_ProjectBonedVerts(SPK_7C2A0);
    func_80017CD4(((struct GameDb_8007C2A0 *)&g_Game)->db[((struct GameDb_8007C2A0 *)&g_Game)->cur].ot, D_800E7D00, SPK_7C2A0);
    func_8007BD38();
    t = GS_7C2A0->f_54;
    if (t >= 13) {
        if (t % 5 == 0) {
            Pad_Vibrate(1, 200, 3);
        }
    } else if (t >= 4) {
        Pad_Vibrate(0, 1, 1);
    }
    switch (GS_7C2A0->f_54) {
    case 0x26:
        func_8006896C(5);
        func_8004BC9C();
        func_8006C6A4(&D_800F50D4);
        break;
    case 0x25:
        ((struct Game_8007C2A0 *)&g_Game)->f_8100 |= 0xE;
        break;
    case 9:
        func_8006896C(6);
        break;
    }
    if (--GS_7C2A0->f_54 == 0) {
        Spike_SetPlayMode(0);
    }
}

/* Adds two type-6 collision entries owned by Spike on the line between the gadget points
 * g_GadgetState+0x34 and +0x3C: one 7/8 of the way along with radius r+0x20, one 3/8 along with
 * radius r: the Magic Punch's hit area (the tip sphere is the larger). Stored at g_GadgetState+0x4C/+0x50. */
void MagicPunch_AddHitSpheres(s32 unused, s32 r, s32 a, s32 b)
{
  Shape_8007C468_8007C468 *p;
  struct GSt_8007C468 *g;
  if ((p = CollShape_Alloc()) != 0)
  {
    p->x = (((struct GSt_8007C468 *) (&g_GadgetState))->f_34 + (((struct GSt_8007C468 *) (&g_GadgetState))->f_3C * 7)) >> 3;
    p->y = (((struct GSt_8007C468 *) (&g_GadgetState))->f_36 + (((struct GSt_8007C468 *) (&g_GadgetState))->f_3E * 7)) >> 3;
    p->z = (((struct GSt_8007C468 *) (&g_GadgetState))->f_38 + (((struct GSt_8007C468 *) (&g_GadgetState))->f_40 * 7)) >> 3;
    p->f_20 = r + 0x20;
    p->f_18 = ((struct Spike_8007C468 *) (&g_Spike))->f_60;
    p->f_24 = a;
    p->f_26 = b;
    ((struct GSt_8007C468 *) (&g_GadgetState))->f_4C = p;
    Collision_Set(6, p, &g_Spike);
  }
  if ((p = CollShape_Alloc()) != 0)
  {
    g = (struct GSt_8007C468 *) (&g_GadgetState);
    p->x = ((g->f_34 * 5) + (g->f_3C * 3)) >> 3;
    p->y = ((g->f_36 * 5) + (g->f_3E * 3)) >> 3;
    p->z = ((g->f_38 * 5) + (g->f_40 * 3)) >> 3;
    p->f_20 = r;
    p->f_18 = ((struct Spike_8007C468 *) (&g_Spike))->f_60;
    p->f_24 = a;
    p->f_26 = b;
    g->f_50 = p;
    Collision_Set(6, p, &g_Spike);
  }
}

void WaterNet_Shoot(void) {
    D_800F51D0.f_8 = g_Spike.f_80;
    D_800F51D0.f_10 = 1;
    D_800F51D0.f_6 = 0x200;
    D_800F51D0.f_0 = (s16) ((s32) (D_800F4730.f_1F4 + D_800F4730.f_214) >> 1);
    D_800F51D0.f_2 = (s16) ((s32) (D_800F4730.f_1F8 + D_800F4730.f_218) >> 1);
    D_800F51D0.f_4 = (s16) ((s32) (D_800F4730.f_1FC + D_800F4730.f_21C) >> 1);
    Pad_Vibrate(1, 0xFF, 6, &D_800F51D0);
    Sound_PlayFixed(0x28);
}

/* Water Net shot (user: R3 shoots the net). State D_800F51D0: position, growing scale +6,
 * direction +8, frame +0x10 (0 = none). Draws the net scaled by +6 and spinning, fading from
 * frame 10 (blinking from 0x10). Before frame 0x10 it moves by direction/64 and leaves particles;
 * it stops at a wall/out of water (Water_Query kind != 1) or the ground; otherwise it adds a
 * catch sphere (collision kind 8, radius frame*16) unless game sub-state +0x8152 is 0xB.
 * Finishes after frame 0x15. */
void WaterNet_UpdateShot(void) {
    MAT_8007C6CC_8007C6CC m;
    MAT_8007C6CC_8007C6CC rx;
    VEC_8007C6CC_8007C6CC sc;
    s32 t = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->timer;
    s32 a;
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    Col_8007C6CC_8007C6CC *c;
    r = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->rot + 0x400; sc.vx = r; sc.vy = r; sc.vz = r; ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->rot = r;
    func_8004637C(&rx);
    RotMatrixX(0x400, &rx);
    Matrix_FromDirection(&((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->vel, &m);
    ScaleMatrix(&m, &sc);
    MulMatrix0(&m, &rx, &m);
    m.t[0] = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->x;
    m.t[1] = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->y;
    m.t[2] = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->z;
    CompMatrix(((u8 *)&D_800E78C0), &m, &m);
    Model_ProjectVerts(D_800EC130, &m, D_800E7D00);
    a = 0xFF;
    if (t - 10 > 0) {
        a = 0xFF - (t - 10) * 51;
        if (a < 0) {
            a = 0;
        }
    }
    a <<= 4;
    Light_SetColorMode(2, a, a, a);
    if (t < 0x10 || (t & 1)) {
        func_80017CD4(D_800EC358, D_800E7D00, D_800EC130);
    }
    Light_SetColorMode(3, 0, 0, 0);
    if (t < 0x10) {
        ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->x = x = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->x + (((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->vel.vx >> 6);
        ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->y = y = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->y + (((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->vel.vy >> 6);
        ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->z = z = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->z + (((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->vel.vz >> 6);
        if (((Water_Query(x, y + 0x20, z) & 0xFFFF) >> 12) != 1 || Floor_GetHeight(x, y, z) < y) {
            t = 0x10;
        } else if ((*(struct Game_8007C6CC *)&g_Game).f_8152 != 0xB && g_Spike.f_E8 > 0) {
            c = CollShape_Alloc();
            if (c != 0) {
                c->dir = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->vel;
                c->x = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->x;
                c->y = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->y;
                c->z = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->z;
                c->f_20 = ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0)->timer << 4;
                Collision_Set(8, c, &g_Spike);
                c->f_24 = 0x100;
                c->f_26 = 0;
            }
        }
    }
    if (t++ >= 0x15) {
        D_800F51E0 = 0;
    } else {
        D_800F51E0 = t;
    }
    if (t < 0x10) {
        Effect_SpawnAt(0x14, ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0));
        Effect_SpawnAt(0x12, ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0));
        Effect_SpawnAt(0x15, ((struct S_D_800F51D0_8007C6CC *)&D_800F51D0));
    }
}

void Gadget_SaveSlots(void) {
    g_GadgetState.f_8C = (u8) g_GadgetState.f_88;
    g_GadgetState.f_8D = (u8) g_GadgetState.f_89;
    g_GadgetState.f_8E = (u8) g_GadgetState.f_8A;
    g_GadgetState.f_8F = (u8) g_GadgetState.f_8B;
    g_GadgetState.f_90 = (s32) g_CurrentGadget;
}

void Gadget_RestoreSlots(void) {
    g_GadgetState.f_88 = (u8) g_GadgetState.f_8C;
    g_GadgetState.f_89 = (u8) g_GadgetState.f_8D;
    g_GadgetState.f_8A = (u8) g_GadgetState.f_8E;
    g_GadgetState.f_8B = (u8) g_GadgetState.f_8F;
    g_CurrentGadget = g_GadgetState.f_90;
}

s32 func_8007CA48(void)
{
  struct 
  {
    u8 pad0[0x8150];
    u16 f_8150;
    u16 f_8152;
  } *new_var;
  u16 v;
  if (((struct S_D_800EC1E0_8007CA48 *)&g_Spike)->f_E8 <= 0)
  {
    return 0;
  }
  new_var = &g_Game;
  if (((*new_var).f_8150 == 5) || (((struct S_D_800EC350_8007CA48 *)&g_Game)->f_8150 == 6))
  {
    return 0;
  }
  if (((struct S_D_800EC350_8007CA48 *)&g_Game)->f_8152 == 11)
  {
    return 0;
  }
  v = ((struct S_D_800EC1E0_8007CA48 *)&g_Spike)->f_5E;
  if ((v >= 0xE) && (v < 0x10))
  {
    return 0;
  }
  if ((v >= 0x2F) && (v < 0x31))
  {
    return 0;
  }
  if ((v >= 0x42) && (v < 0x44))
  {
    return 0;
  }
  return !((0x1B <= v) && (v < 0x22));
}

/* Draws the Stun Club on its parent matrix: the shaft model D_800EC0B0 squashed by
 * 0x1000000 / len along x (len along z), and the head model D_800EC100 scaled by len * 3
 * (clamped to 1.0..2.0). With save set, the head position (0, 0, -0x1AE in shaft space) is
 * stored in g_GadgetState + 0xC for hit checks. */
void Club_Draw(struct S_D_800E78C0 *parent, s32 len, s32 save) {
    VEC_7CAE0_8007CAE0 sc;
    SV_7CAE0_8007CAE0 tip;
    struct S_D_800E78C0 m;
    struct S_D_800E78C0 m2;
    s32 flag;
    s32 k;
    s32 s;

    func_8004637C(&m);
    m.t[1] = -0x10;
    m.t[2] = -0x40;
    CompMatrix(parent, &m, &m);
    k = 0x1000000 / len;
    m2 = m;
    sc.vx = 0x1000;
    sc.vz = len;
    if (k > 0x1000) {
        k = 0x1000;
    }
    sc.vx = k;
    ScaleMatrix(&m, &sc);
    tip.vx = 0;
    tip.vy = 0;
    tip.vz = -0x1AE;
    SetRotMatrix(&m);
    SetTransMatrix(&m);
    RotTrans(&tip, m2.t, &flag);
    if (save) {
        g_Gad7CAE0.f_C = m2.t[0];
        g_Gad7CAE0.f_E = m2.t[1];
        g_Gad7CAE0.f_10 = m2.t[2];
    }
    CompMatrix(&D_800E78C0, &m, &m);
    Model_ProjectVerts(&D_800EC0B0, &m, D_800E7D00);
    func_80017CD4((*(u32 * *)&D_800EC358), D_800E7D00, &D_800EC0B0);
    s = len * 3;
    s = s < 0x1000 ? 0x1000 : (s > 0x2000 ? 0x2000 : s);
    sc.vx = s;
    sc.vy = s;
    sc.vz = s;
    CompMatrix(&D_800E78C0, &m2, &m2);
    ScaleMatrix(&m2, &sc);
    Model_ProjectVerts(&D_800EC100, &m2, D_800E7D00);
    func_80017CD4((*(u32 * *)&D_800EC358), D_800E7D00, &D_800EC100);
}

void func_8007CD0C(s32 a) {
    if (g_GadgetState.f_A3 != a) {
        func_8006CDE0();
        g_GadgetState.f_A3 = a;
    }
}
