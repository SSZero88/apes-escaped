#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define PAD_4B5FC ((struct Pad_8004B5FC *)&g_Pad)
#define G_GAME_8004A978 ((struct g_Game_8004A978 *)&g_Game)
#define SP_4AA58 ((struct Spike_8004AA58 *)&g_Spike)
typedef struct { s16 vx, vy, vz, pad; } SVEC_80049514;
typedef struct { u8 pad0[4]; s16 f_4; u8 pad6[4]; SVECTOR f_A; u8 pad12[0x1E]; u8 f_30; u8 pad31; u8 f_32; u8 f_33; u8 pad34[4]; s32 f_38; u8 pad3C[4]; s32 f_40; u8 pad44[0x6C]; } S_B4D40_80049514;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80048F6C_80048F6C;
typedef struct { u8 pad0[0x18]; u16 f_18; u16 f_1A; u16 f_1C; } SCR_80048F6C_80048F6C;
typedef struct { u8 pad0[0xA]; s16 f_A; s16 f_C; s16 f_E; } S_80048F6C_80048F6C;
typedef struct { u8 pad0[0xA]; s16 f_A; s16 f_C; s16 f_E; u8 pad10[2]; s16 f_12; s16 f_14; s16 f_16; u8 pad18[2]; s16 f_1A; s16 f_1C; s16 f_1E; u8 pad20[0x10]; u8 f_30; u8 f_31; u8 f_32; u8 f_33; u8 f_34; u8 f_35; u8 f_36; u8 f_37; s32 f_38; u8 pad3C[4]; s32 f_40; s32 f_44; u8 pad48[8]; s16 f_50; s16 f_52; s16 f_54; u8 pad56[2]; s16 f_58; s16 f_5A; s16 f_5C; u8 pad5E[0x10]; s16 f_6E; u8 pad70[0x10]; u8 f_80; u8 f_81; } S_800493D4_800493D4;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 f_62; s16 f_64; } S_EC1E0_800493D4_800493D4;
typedef struct { u16 vx, vy, vz, pad; } USVEC_80048DD0_80048DD0;
typedef struct { u8 pad0[0x10]; u16 f_10; u8 pad12[2]; u16 f_14; u8 pad16[4]; u16 f_1A; u8 pad1C[0x24]; USVEC_80048DD0_80048DD0 f_40; } S_Sc_80048DD0_80048DD0;
typedef struct { u8 pad0[0x1A]; s16 f_1A; s16 f_1C; s16 f_1E; u8 pad20[0x10]; u8 f_30; u8 f_31; u8 pad32[0xE]; s32 f_40; u8 pad44[4]; s32 f_48; s32 f_4C; u8 pad50[0x10]; s32 f_60; SVECTOR f_64; } S_C_80048DD0_80048DD0;
typedef struct { u8 pad0[0x38]; s32 dist; u8 pad3C[4]; s32 yaw; } Cam_8004B5FC_8004B5FC;
typedef struct { SVECTOR eye; SVECTOR at; SVECTOR tgt; u8 pad18[0x5C]; s32 stick; } Scr_8004B5FC_8004B5FC;
typedef struct { u8 pad0[0xC]; s16 f_C; u8 padE[4]; s16 f_12; s16 f_14; s16 f_16; u8 pad18[0x20]; s32 dist; } Cam_8004AC84_8004AC84;
typedef struct { s16 vx, vy, vz, pad; } SV_8004AC84_8004AC84;
typedef struct { SV_8004AC84_8004AC84 eye; SV_8004AC84_8004AC84 at; SV_8004AC84_8004AC84 tgt; SV_8004AC84_8004AC84 v18; } Scr_8004AC84_8004AC84;
typedef struct { u8 pad[0xB0]; } A_8004AC84_8004AC84;
typedef struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[0x32]; SV_8004AC84_8004AC84 dir; u8 pad68[8]; s32 f_70; } Sp_8004AC84_8004AC84;
typedef struct { s16 vx, vy, vz, pad; } SV_4906C_8004906C;
typedef struct { u16 x; u16 y; u16 z; } SC_4906C_8004906C;
typedef struct { u8 pad0[0xA]; s16 f_A; s16 f_C; s16 f_E; u8 pad10[0x20]; u8 f_30; u8 pad31[3]; u8 f_34; u8 f_35; u8 f_36; u8 f_37; u8 pad38[8]; s32 f_40; s32 f_44; } Cam_4906C_8004906C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; s32 vx; s32 pad34; s32 vz; } Rc_8004AA58_8004AA58;
typedef struct { u8 pad0[0x80]; u8 zoom; u8 f_81; } Cam_8004AA58_8004AA58;

extern u8 *D_800E68D8;

extern struct S_D_800EC350 { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0x28]; u16 f_8150; } g_Game;

s32 Stage_IsArea53();
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern struct S_D_800E68D0 { u8 pad_0[0x46]; u8 f_46; } g_CameraState;

extern s8 D_800E6912;
extern s32 g_CameraSlots;
extern u8 D_800E68E8;
extern void (*D_80141390[])(s32);
extern void (*D_8014440C[])(s32);
extern struct S_D_800EC1E0 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
void VectorNormalSS(SVEC_80049514 *, SVEC_80049514 *);
s32 Math_Atan2(s32, s32);
struct S_D_800EC350_80049514 { u8 pad0[0x8258]; SVECTOR f_8258; };
s16 Floor_GetHeight(s32, s32, s32);
extern M2C_UNK D_800E54A0;
void func_80047360(S_C_80048DD0_80048DD0 *);

/* Camera: updates its heading from the view vector and counts how long the
 * camera has been still and how long the idle counter has run.
 */
struct Spike_8004B5FC { u8 pad0[0x24]; s32 x, y, z; };
struct Pad_8004B5FC { u8 pad0[0x158]; u32 held; };
s32 rcos(s32);
s32 rsin(s32);
void Camera_EaseLookAt(Cam_8004B5FC_8004B5FC *, s32, s32, s32);
void Camera_EaseEye(Cam_8004B5FC_8004B5FC *, s32, s32, s32);
extern struct S_D_800E5320 { u8 pad0[0xA2]; s8 sx; s8 sy; u8 padA4[0xB4]; u32 held; } g_Pad;
struct Game_8004AC84 { u8 pad0[0x8150]; u16 f_8150; };
void Camera_PlaceBehindSpike(void *arg0, void *arg1, s32 arg2);
void Matrix_SetIdentity(void *);
void RotMatrixY(s32, void *);
void ApplyMatrixSV(void *, void *, void *);
void Camera_CallStageHook(s32 i, s32 arg);
void Camera_DrawAimReticle(Cam_8004AC84_8004AC84 *);
struct S_D_800E68D0_8004AC84 { u8 pad0[6]; u16 f_6; u8 pad8[0x10]; u8 f_18; u8 pad19[0x19]; u8 f_32; u8 f_33; u8 pad34[0x12]; u8 f_46; };
s32 SquareRoot0(s32);
extern s8 g_CurrentGadget;
extern s32 D_800F5A90;
struct g_Game_8004A978 { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0x28]; u16 f_8150; };
s32 Stage_GetSpecialKind(void);
struct Spike_8004AA58 { u8 pad0[0x24]; s32 x, y, z; };
extern Rc_8004AA58_8004AA58 g_RcCar;
extern M2C_UNK g_ViewMatrix;
extern u16 D_800E54A2;
extern u16 D_800E68D6;
void SetRotMatrix(void *);
void SetTransMatrix(void *);
s32 RotTransPers(SVECTOR *, s32 *, s32 *, s32 *);
void Camera_UpdateFollow();

void Camera_UpdateOrientation(S_C_80048DD0_80048DD0 *o) {
    S_Sc_80048DD0_80048DD0 *sc = (S_Sc_80048DD0_80048DD0 *)0x1F800000;
    s32 d;
    o->f_48 = Math_Atan2(-(s16)sc->f_40.vx, -(s16)sc->f_40.vz);
    o->f_4C = (o->f_40 - o->f_48 + 0x1000) % 4096;
    if (o->f_4C > 0x800) {
        o->f_4C -= 0x1000;
    }
    func_80047360(o);
    if (*(u16 *)&D_800E54A0 > 100) {
        o->f_31 += o->f_31 < 0xFF;
    } else {
        o->f_31 = 0;
    }
    if (*(u32 *)&D_800E54A0 == 0 && o->f_1A == (s16)sc->f_10 && o->f_1C == (s16)sc->f_1A && o->f_1E == (s16)sc->f_14) {
        o->f_30 += o->f_30 < 0xFF;
    } else {
        o->f_30 = 0;
    }
    o->f_60 = ((s16)sc->f_40.vz * o->f_64.vx - (s16)sc->f_40.vx * o->f_64.vz) >> 12;
    *(USVEC_80048DD0_80048DD0 *)&o->f_64 = sc->f_40;
}

void Camera_KeepAboveFloor(S_80048F6C_80048F6C *s) {
    SVEC_80048F6C_80048F6C v;
    s32 r;
    SCR_80048F6C_80048F6C *sc = (SCR_80048F6C_80048F6C *)0x1F800000;

    v.vx = sc->f_18 - s->f_A;
    v.vy = s->f_C;
    v.vz = sc->f_1C - s->f_E;
    VectorNormalSS(&v, &v);
    r = Floor_GetHeight(s->f_A + (v.vx >> 5), s->f_C, s->f_E + (v.vz >> 5));
    if (r - 0x80 < s->f_C && s->f_C < r + 0x110) {
        if ((s16)sc->f_1A < r + 0x100) {
            s->f_C = r - 0x80;
        }
        if (s->f_C < (s16)sc->f_1A - 0x400) {
            s->f_C = sc->f_1A - 0x400;
        }
    }
}

void Camera_ProbeDrop(Cam_4906C_8004906C *c, s32 flag) {
    SC_4906C_8004906C *sc = (SC_4906C_8004906C *)0x1F800000;
    SV_4906C_8004906C d;
    s32 len;
    s32 h1;
    s32 h2;
    s32 lim;

    d.vx = sc->x - c->f_A;
    d.vy = 0;
    d.vz = sc->z - c->f_E;
    len = SquareRoot0(((s32 (*)(void *, void *))VectorNormalSS)(&d, &d));
    if (len > 0x40) {
        len = 0x40;
    }
    h1 = ((s32 (*)(s32, s32, s32))Floor_GetHeight)(c->f_A + (d.vx * len >> 10), c->f_C, c->f_E + (d.vz * len >> 10));
    h2 = ((s32 (*)(s32, s32, s32))Floor_GetHeight)(c->f_A + (d.vx * len >> 11), c->f_C, c->f_E + (d.vz * len >> 11));
    if ((s16)h1 < (s16)sc->y - 0x100 || (s16)h2 < (s16)sc->y - 0x100) {
        if (flag != 0 && c->f_34 == 0) {
            c->f_40 = c->f_44;
        }
        c->f_37 = 0;
        if (c->f_36 < 0xFF) {
            c->f_36++;
        }
        c->f_35 = 6;
    } else {
        if (c->f_35 == 0) {
            c->f_36 = 0;
        }
        if (c->f_30 == 0 && c->f_37 < 0xFF) {
            c->f_37++;
        }
    }
}

typedef struct { u8 pad0[0xC]; s16 f_C; u8 padE[0x22]; u8 f_30; u8 pad31; u8 f_32; u8 pad33; u8 f_34; u8 pad35[2]; u8 f_37; u8 pad38[0x34]; s16 f_6C; s16 f_6E; } Cam_8004923C;
struct Pad_8004923C { u8 pad0[0xA2]; s8 f_A2; s8 f_A3; u8 padA4[0xDC]; u16 f_180; };
extern u8 g_Pad_CHMI[] asm("g_Pad");
extern u8 D_800E6908_CHMI asm("D_800E6908");
extern struct { u32 v; } D_800E5478_s asm("D_800E5478");
s32 Game_IsPlaying(void);
/* Camera_HandleManualInput: manual camera control from the right stick (pad +0xA2/+0xA3, when an
 * analog pad is in mode 1 with +0x180 > 100) or the buttons in D_800E5478: yaw speed f_6E = +-0x22
 * (0x2000 / 0x8000), pitch f_6C = -0x30 / +0x30 (0x1000 / 0x4000) clamped to the limits from
 * scratch +0x1A (-0x404 / +0x100). D_800E5478 is accessed as a struct member (alias rule, README). */
void Camera_HandleManualInput(Cam_8004923C *c) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 rx = 0;
    s32 ry = 0;
    s16 lim;
    if (Game_IsPlaying() == 0) {
        return;
    }
    if (D_800E6908_CHMI == 1 && ((struct Pad_8004923C *)&g_Pad_CHMI)->f_180 > 100) {
        rx = ((struct Pad_8004923C *)&g_Pad_CHMI)->f_A2;
        ry = ((struct Pad_8004923C *)&g_Pad_CHMI)->f_A3;
    }
    c->f_6E = 0;
    if (rx != 0 || (c->f_34 == 0 && c->f_32 == 0)) {
        if ((D_800E5478_s.v & 0x2000) || rx > 0) {
            c->f_6E = 0x22;
            c->f_30 = 0;
            c->f_37 = 0;
        } else if ((D_800E5478_s.v & 0x8000) || rx < 0) {
            c->f_6E = -0x22;
            c->f_30 = 0;
            c->f_37 = 0;
        }
    }
    c->f_6C = 0;
    if ((D_800E5478_s.v & 0x1000) || ry > 0) {
        c->f_6C = -0x30;
        lim = *(u16 *)(scratch + 0x1A);
        lim -= 0x404;
        if (c->f_C - 0x30 < lim) {
            c->f_6C = lim - c->f_C;
        }
    }
    if ((D_800E5478_s.v & 0x4000) || ry < 0) {
        lim = *(u16 *)(scratch + 0x1A);
        lim += 0x100;
        c->f_6C = 0x30;
        if (c->f_C + 0x30 > lim) {
            c->f_6C = lim - c->f_C;
        }
    }
}


void Camera_InitFollow(S_800493D4_800493D4 *o) {
    S_EC1E0_800493D4_800493D4 *s = (S_EC1E0_800493D4_800493D4 *)&g_Spike;
    o->f_40 = Math_Atan2(-s->f_60, -s->f_64);
    o->f_38 = 0x460;
    o->f_6E = 0;
    o->f_30 = 0;
    o->f_31 = 0;
    o->f_32 = 0;
    o->f_34 = 0;
    o->f_37 = 0;
    o->f_36 = 0;
    o->f_35 = 0;
    o->f_80 = 0;
    o->f_81 = 1;
    o->f_44 = o->f_40;
    o->f_1A = s->f_24;
    o->f_1C = s->f_28;
    o->f_1E = s->f_2C;
    o->f_50 = 0;
    o->f_52 = 0;
    o->f_54 = 0;
    o->f_58 = 0;
    o->f_5A = 0;
    o->f_5C = 0;
    o->f_A = s->f_24 - (s->f_60 >> 1);
    o->f_C = s->f_28 - 0x172;
    o->f_E = s->f_2C - (s->f_64 >> 1);
    o->f_12 = s->f_24 + (s->f_60 >> 2);
    o->f_14 = s->f_28 - 0x6E;
    o->f_16 = s->f_2C + (s->f_64 >> 2);
    o->f_33 = 1;
}

void Camera_ResetToStart(void)
{
  S_B4D40_80049514 *p = &(*(S_B4D40_80049514 * *)&g_CameraSlots)[D_800E68E8];
  SVEC_80049514 v;
  p->f_33 = 1;
  p->f_32 = 0;
  p->f_A = ((struct S_D_800EC350_80049514 *)&g_Game)->f_8258;
  p->f_30 = 0;
  p->f_38 = 0x460;
  p->f_4 = 0x460;
  v.vx = g_Spike.f_24 - p->f_A.vx;
  v.vy = 0;
  v.vz = g_Spike.f_2C - p->f_A.vz;
  VectorNormalSS(&v, &v);
  p->f_40 = Math_Atan2(-v.vx, -v.vz);
}

/* scratch pad while the camera updates */
typedef struct { SVECTOR eye;                /* 0x00 wanted eye */ SVECTOR at;                 /* 0x08 wanted look-at point */ u16 x; u16 pad12; u16 z; u8 pad16[4]; u16 y; /* 0x10 Spike (x, z, y at 0x1A) */ u8 pad1C[0x10]; s32 f_2C; u8 pad30[0x10]; u16 dx; u16 pad42; u16 dz;  /* 0x40 Spike's facing */ u8 pad46[0x1A]; s32 sx, sy;                 /* 0x60 Spike on screen */ s32 vx, vy, vz;             /* 0x68 Spike's velocity */ s32 pad74; s32 dot;                    /* 0x78 */ } CamScr_495F4;
typedef struct { u8 pad0[4]; s16 dist;                   /* 0x04 */ s16 height;                 /* 0x06 */ s16 atHeight;               /* 0x08 */ SVECTOR eye;                /* 0x0A x, y, z (unaligned) */ SVECTOR at;                 /* 0x12 */ s16 lastX, lastY, lastZ;    /* 0x1A */ u8 pad20[0x10]; u8 still;                   /* 0x30 */ u8 moving;                  /* 0x31 */ u8 turn;                    /* 0x32 */ u8 snap;                    /* 0x33 */ u8 slow;                    /* 0x34 */ u8 probe;                   /* 0x35 */ u8 f_36; u8 f_37; s32 range;                  /* 0x38 */ u8 pad3C[4]; s32 yaw;                    /* 0x40 */ s32 lastYaw;                /* 0x44 */ s32 f_48; s32 spin;                   /* 0x4C */ u8 pad50[2]; s16 bobY;                   /* 0x52 */ u8 pad54[6]; s16 bobAt;                  /* 0x5A */ u8 pad5C[4]; s32 f_60; u8 pad64[8]; s16 f_6C; s16 f_6E; s32 f_70; s32 f_74; u8 pad78[8]; u8 rcZoom;                  /* 0x80 */ } Cam_495F4;
extern struct { u8 pad0[0x34]; s16 f_34; s16 f_36; u8 pad38[7]; u8 f_3F; u8 f_40; u8 pad41[6]; u8 busy; u8 f_48; } D_800E68D0_495F4 asm("g_CameraState");
extern struct { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x22]; u16 f_8126; u8 pad8128[0x28]; u16 f_8150; } g_Game_495F4 asm("g_Game");
extern struct { u8 pad0[0xA2]; s8 sx; } g_Pad_495F4 asm("g_Pad");
extern struct { u8 pad0[0x5E]; u16 state; u8 pad60[0x10]; s32 animFlags; } g_Spike_495F4 asm("g_Spike");
extern u8 D_800E78C0_495F4[] asm("g_ViewMatrix");
extern u16 D_800EC23E_495F4 asm("D_800EC23E");
extern u8 D_800E6916_495F4 asm("D_800E6916");
extern s8 g_CurrentGadget_495F4 asm("g_CurrentGadget");
void SetRotMatrix_495F4(void *) asm("SetRotMatrix");
void SetTransMatrix_495F4(void *) asm("SetTransMatrix");
s32 RotTransPers_495F4(SVECTOR *, s32 *, s32 *, s32 *) asm("RotTransPers");
void Camera_UpdateOrientation_495F4(Cam_495F4 *) asm("Camera_UpdateOrientation");
void Camera_HandleManualInput_495F4(Cam_495F4 *) asm("Camera_HandleManualInput");
s32 Camera_RcCarActive_495F4(void) asm("Camera_RcCarActive");
void Camera_ProbeDrop_495F4(Cam_495F4 *, s32) asm("Camera_ProbeDrop");
void Camera_KeepAboveFloor_495F4(Cam_495F4 *) asm("Camera_KeepAboveFloor");
s32 func_8006B9F8_495F4(void) asm("Spike_IsDeepInWater");
void VectorNormalSS_495F4(SVECTOR *, SVECTOR *) asm("VectorNormalSS");
s16 Floor_GetHeight_495F4(s32, s32, s32) asm("Floor_GetHeight");
void memset_495F4(void *, s32, s32) asm("memset");
s32 SquareRoot0_495F4(s32) asm("SquareRoot0");
s32 rcos_495F4(s32) asm("rcos");
s32 rsin_495F4(s32) asm("rsin");
void func_8004AF78_495F4(Cam_495F4 *) asm("Camera_DrawAimReticle");
s32 Math_Atan2_495F4(s32, s32) asm("Math_Atan2");

/* The normal follow camera (mode 0, or 1 = behind Spike). Works out how far behind and above
   Spike to sit (the defaults in the camera, overridden by g_CameraState settings, when Spike is in a
   tight spot (state group 0x80), in mode 0xA and when Spike_IsDeepInWater says so), runs the
   orientation and manual-control steps, damps the spin and eases the range, checks the ground
   between Spike and the camera when the stick turns it, pulls in when something blocks the view,
   bobs with Spike's jumps, then moves the eye and look-at points towards their goals. */
void Camera_UpdateFollow(Cam_495F4 *cam, s32 mode) {
    CamScr_495F4 *scr = (CamScr_495F4 *)0x1F800000;
    SVECTOR v;
    SVECTOR d;
    SVECTOR side;
    SVECTOR t;
    s32 sxy, dummy;
    s16 h, atH;
    s16 dist;
    s32 blocked;
    s32 i, k, a, b, ox, oz; s32 k1; s32 a6;
    s16 px, py, pz;
    s16 stepX, stepY, stepZ;

    if (D_800E68D0_495F4.busy != 0) {
        return;
    }
    D_800E68D0_495F4.busy = 1;
    v.vx = scr->x;
    v.vy = scr->y - 0x80;
    v.vz = scr->z;
    SetRotMatrix_495F4(D_800E78C0_495F4);
    SetTransMatrix_495F4(D_800E78C0_495F4);
    RotTransPers_495F4(&v, &sxy, &dummy, &dummy);
    scr->sx = sxy & 0xFFFF;
    scr->sy = sxy >> 16;
    atH = cam->atHeight;
    h = cam->height;
    dist = cam->dist;
    if (mode == 0) {
        if (D_800E68D0_495F4.f_3F != 0) {
            h = D_800E68D0_495F4.f_34;
        }
        if (D_800E68D0_495F4.f_40 != 0) {
            dist = D_800E68D0_495F4.f_36;
        }
        if ((g_Spike_495F4.animFlags & 0xF0) == 0x80) {
            h = -0xDC;
            dist = 0x26C;
        }
        if (g_Game_495F4.f_8150 == 0xA) {
            dist = 0x2F8;
            atH = -0x32;
            h = -0x64;
        } else if (func_8006B9F8_495F4() != 0) {
            k1 = scr->vy;
            dist = 0x294;
            atH = k1 << 5;
            h = -(k1 * 8);
        }
    } else if (D_800E68D0_495F4.f_48 == 1) {
        h = 0;
        atH = -0x8C;
    }
    Camera_UpdateOrientation_495F4(cam);
    if (mode == 1) {
        if (scr->vx | scr->vy | scr->vz) {
            cam->still = 0;
            cam->moving += cam->moving < 0xFF;
        } else {
            cam->moving = 0;
            cam->still += cam->still < 0xFF;
        }
    }
    Camera_HandleManualInput_495F4(cam);
    if ((u32)(scr->dot + 0xF9F) < 0x1EDB) {
        if (ABS(cam->f_60) < 0x640 && cam->moving != 0 && cam->turn == 0) {
            cam->spin = cam->spin * 0x3F / 64;
        }
    }
    if (cam->rcZoom != 0 && Camera_RcCarActive_495F4() != 0) {
        a = cam->rcZoom;
        if (a > 0) {
            k = 0x30;
            if (a < 0x31) {
                k = a;
            }
        } else {
            k = 1;
        }
        a = 0x40 - k;
        cam->spin = cam->spin * a / (a + 1);
    } else if (cam->still >= 0x12 && scr->dot < 0xF3C && g_Game_495F4.f_8150 != 0xA) {
        a = cam->still - 0x12;
        if (a > 0) {
            k = 0x30;
            if (a < 0x31) {
                k = a;
            }
        } else {
            k = 1;
        }
        a = 0x40 - k;
        cam->spin = cam->spin * a / (a + 1);
    }
    if (cam->slow != 0) {
        cam->slow--;
        cam->spin = cam->spin * 0xF / 16;
        if (ABS(cam->spin) < 0xB) {
            cam->slow = 0;
        }
    }
    if (cam->turn != 0 && (g_Spike_495F4.animFlags & 0xF0) != 0x80) {
        cam->range = (cam->range + (dist - 0x80)) / 2;
    } else if (g_Game_495F4.f_8150 == 0xA) {
        cam->range = (cam->range * 7 + dist) / 8;
    } else {
        if (cam->range > dist + 0x100) {
            cam->range = (cam->range * 3 + (dist + 0x100)) / 4;
        }
        if (cam->range < dist - 0x100) {
            cam->range = (cam->range * 3 + (dist - 0x100)) / 4;
        }
    }
    { s32 s = cam->spin + 0x1000; cam->yaw = (cam->f_48 + s + cam->f_6E) % 4096; }
    if (cam->turn != 0) {
        cam->turn--;
        a = cam->f_70 - cam->f_74;
        a = (a + 0x1000) % 4096;
        if (a > 0x800) {
            a -= 0x1000;
        }
        a = (a * 8 - a) / 8;
        if (ABS(a) < 0xB) {
            cam->turn = 0;
        }
        { s32 c = a + 0x1000; cam->f_70 = (cam->f_74 + c) % 4096; }
        cam->yaw = cam->f_70;
    }
    /* turning the camera with the stick: is the ground between Spike and the camera clear? */
    blocked = 0;
    if (scr->dot < 0x3E8) {
        s32 dy = scr->f_2C - cam->eye.vy;
        if ((dy >= 0 ? dy : cam->eye.vy - scr->f_2C) < 0x800) {
            if (ABS(g_Pad_495F4.sx) >= 0x33) {
                d.vx = cam->eye.vx - scr->x;
                d.vy = 0;
                d.vz = cam->eye.vz - scr->z;
                VectorNormalSS_495F4(&d, &d);
                if (g_Pad_495F4.sx > 0) {
                    side.vx = -d.vz;
                    side.vz = d.vx;
                } else {
                    side.vx = d.vz;
                    side.vz = -d.vx;
                }
                px = scr->x + side.vx / 12;
                py = scr->y - 0x80;
                pz = scr->z + side.vz / 12;
                stepX = (cam->eye.vx - (s16)scr->x) / 4;
                stepY = (cam->eye.vy - py) / 4;
                stepZ = (cam->eye.vz - (s16)scr->z) / 4;
                for (i = 0; i < 3; i++) {
                    if (Floor_GetHeight_495F4(px, py, pz) < py - 0xC0) {
                        blocked = 1;
                        break;
                    }
                    py += stepY;
                    px += stepX;
                    pz += stepZ;
                }
            }
        }
    }
    if (scr->dot >= 0x7D1 && cam->moving != 0) {
        memset_495F4(&t, 0, 8);
        t.vx = scr->x - cam->eye.vx;
        t.vz = scr->z - cam->eye.vz;
        side = t;
        VectorNormalSS_495F4(&side, &side);
        if (Floor_GetHeight_495F4(cam->eye.vx - side.vx / 32, cam->eye.vy, cam->eye.vz - side.vz / 32) < cam->eye.vy) {
            cam->slow = 5;
            cam->f_36 = 0;
            cam->probe = 0;
            cam->f_37 = 0xFF;
        }
    }
    if (blocked != 0) {
        if (scr->dot < 0xDAC) {
            cam->slow = 8;
            cam->f_36 = 0;
            cam->probe = 0;
            cam->range -= 0x258;
            if (cam->range < 0) {
                cam->range = 0;
            }
            cam->range = cam->range * 7 / 8 + 0x258;
        }
    }
    if (blocked == 0) {
        s16 dy2 = scr->y - cam->lastY;
        if (dy2 != 0 && ABS(dy2) < 0x60) {
            b = g_Spike_495F4.animFlags & 0xF0;
            if (b == 0x20 || b == 0x30 || b == 0xA0 || g_Spike_495F4.state == 6) {
                if (scr->dot > 0 && dy2 < 0) {
                    dy2 = -dy2 * 4;
                }
                cam->bobY = -dy2 / 2;
                cam->bobAt = dy2 / 3;
            }
        }
    }
    scr->at.vy = (s16)scr->y + (s16)(atH - 0x80);
    {
    s32 k_;
    s16 a_;
    register s16 ox_ asm("$7");
    s16 b_;
    register s16 oz_ asm("$5");
    k_ = SquareRoot0_495F4(scr->vx * scr->vx + scr->vz * scr->vz);
    if (k_ > 0x20) {
        k_ = 0x20;
    }
    a_ = ((s16)scr->dx / 16) * k_ / 32;
    __asm__ volatile("");
    ox_ = a_;
    b_ = ((s16)scr->dz / 16) * k_ / 32;
    oz_ = b_;
    if (mode == 1) {
        ox_ = -a_;
        oz_ = -b_;
    }
    scr->at.vx = scr->x + ox_ + scr->vx * k_;
    scr->at.vz = scr->z + oz_ + scr->vz * k_;
    }
    if ((g_Spike_495F4.animFlags & 0xF0) == 0x50) {
        s32 vy = scr->vy;
        if (vy > 0) {
            scr->at.vy += vy << 6;
        }
    }
    if (scr->sy > 0xD0 && scr->vy > 0x20 && (g_Spike_495F4.animFlags & 0xF0) != 0x40 && scr->dot < 0) {
        cam->range = cam->range * 7 / 8;
        if (cam->range < 0x200) {
            cam->range = 0x200;
        }
    }
    if (scr->at.vy > 0 && g_Game_495F4.f_8126 != 7) {
        scr->at.vy = 0;
    }
    scr->eye.vx = cam->at.vx + (rcos_495F4(cam->yaw) * cam->range >> 12);
    scr->eye.vz = cam->at.vz + (rsin_495F4(cam->yaw) * cam->range >> 12);
    scr->eye.vy = (s16)scr->y + (s16)(h - 0x80);
    if (g_CurrentGadget_495F4 == 3 && D_800E6916_495F4 != 1) {
        func_8004AF78_495F4(cam);
    }
    if (cam->probe != 0) {
        cam->probe--;
    }
    Camera_ProbeDrop_495F4(cam, 0);
    if (cam->probe != 0) {
        if (cam->f_36 >= 5) {
            cam->range -= 0x30;
            if (cam->range < 0x180) {
                cam->range = 0x180;
                if (cam->eye.vy < (s16)scr->y - 0x60) {
                    cam->bobY = 8;
                }
            }
            cam->dist = cam->range;
        }
        scr->eye.vx = cam->at.vx + (rcos_495F4(cam->yaw) * cam->range >> 12);
        scr->eye.vz = cam->at.vz + (rsin_495F4(cam->yaw) * cam->range >> 12);
        Camera_ProbeDrop_495F4(cam, 1);
    }
    if (cam->slow == 0 && cam->dist < 0x460 && cam->f_37 >= 0xD) {
        cam->dist = (cam->dist * 3 + 0x460) / 4;
    }
    if (!(g_Game_495F4.f_8100 & 1) && cam->slow == 0) {
        scr->eye.vx += scr->vx * 3 / 2;
        scr->eye.vz += scr->vz * 3 / 2;
    }
    if ((g_Spike_495F4.animFlags & 0xF0) == 0x50) {
        s32 vy = scr->vy;
        if (vy > 0) {
            scr->eye.vy -= vy << 6;
        }
    }
    if (scr->eye.vy > 0) {
        scr->eye.vy = 0;
    }
    if (D_800EC23E_495F4 == 0x2D) {
        scr->eye.vx = scr->x - (s16)scr->dx / 64;
        scr->eye.vz = scr->z - (s16)scr->dz / 64;
    }
    if (cam->snap != 0) {
        cam->at.vx = scr->x + (s16)scr->dx / 16;
        cam->at.vy = (s16)scr->y + (s16)(atH - 0x80);
        cam->at.vz = scr->z + (s16)scr->dz / 16;
    }
    cam->at.vx = (scr->at.vx + cam->at.vx * 0x1F) / 32;
    cam->at.vz = (scr->at.vz + cam->at.vz * 0x1F) / 32;
    if ((g_Spike_495F4.animFlags & 0xF0) == 0x40) {
        cam->at.vy = (scr->at.vy + cam->at.vy * 0x1F) / 32;
    } else {
        cam->at.vy = (scr->at.vy + cam->at.vy * 0xF) / 16;
    }
    a = scr->sy;
    if ((g_Spike_495F4.animFlags & 0xF0) == 0x50 ? a < 0x30 : a < 0x20) {
        if (scr->vy < 0) {
            cam->bobAt = scr->vy - 8;
        }
    }
    if (scr->sy > 0xD0 && scr->vy > 0) {
        cam->bobAt += scr->vy / 2;
        if (cam->bobAt > 0x60) {
            cam->bobAt = 0x60;
        }
    }
    cam->at.vy += cam->bobAt;
    cam->bobAt = cam->bobAt * 7 / 8;
    if (cam->snap != 0) {
        cam->eye = scr->eye;
        d.vx = cam->at.vx - cam->eye.vx;
        d.vy = 0;
        d.vz = cam->at.vz - cam->eye.vz;
        VectorNormalSS_495F4(&d, &d);
        cam->yaw = Math_Atan2_495F4(-d.vx, -d.vz);
    } else {
        cam->eye.vx = (scr->eye.vx + cam->eye.vx) / 2;
        cam->eye.vz = (scr->eye.vz + cam->eye.vz) / 2;
        if ((g_Spike_495F4.animFlags & 0xF0) == 0x40) {
            cam->eye.vy = (scr->eye.vy + cam->eye.vy * 0x3F) / 64;
        } else {
            cam->eye.vy = (scr->eye.vy + cam->eye.vy * 0x1F) / 32;
        }
        cam->eye.vy += cam->f_6C;
        cam->eye.vy += cam->bobY;
        cam->bobY = cam->bobY * 7 / 8;
    }
    if (D_800EC23E_495F4 != 0x2D) {
        Camera_KeepAboveFloor_495F4(cam);
    }
    a = (cam->at.vx - cam->eye.vx) * (cam->at.vx - cam->eye.vx);
    b = (cam->at.vz - cam->eye.vz) * (cam->at.vz - cam->eye.vz);
    cam->lastX = scr->x;
    cam->lastY = scr->y;
    cam->lastZ = scr->z;
    cam->range = SquareRoot0_495F4(a + b);
    cam->snap = 0;
    cam->lastYaw = cam->yaw;
}

s32 Camera_StageHookActive(void)
{
  s32 var_a0;
  int new_var;
  var_a0 = 0;
  if (g_Game.f_8150 == 2)
  {
    new_var = g_Game.f_8126 - 0x48;
    var_a0 = ((u32) new_var) < 5U;
  }
  return var_a0;
}

s32 Camera_RcCarActive(void) {
    s32 r;
    u32 m;
    if (Stage_GetSpecialKind() != 0) {
        return 0;
    }
    r = 0;
    if (g_CurrentGadget == 7 && D_800F5A90 != 0) {
        if (G_GAME_8004A978->f_8150 != 0) {
            goto end;
        }
        m = G_GAME_8004A978->f_8126;
        if (m != 0x3A && m != 0x35 && m != 0x36 && m != 0x50 && m != 0x52 && m != 0x54) {
            r = r < (m ^ 0x61);
        }
    }
end:
    return r;
}

void Camera_ForceFloorCheck(void)
{
  s8 *new_var;
  new_var = (s8 *) (((s8 *) (g_CameraSlots + (D_800E68E8 * 0xB0))) + 0x81);
  *new_var = 1;
}


/* Camera while driving the RC car: zoom (cam->zoom, 16..40) from the car's screen depth 0x2900/z
   (z from RotTransPers of the car 4 frames ahead), set only when the car is over 0x180 from Spike
   and D_800E54A2 is set; past 0x14 of it +0x81 latches, and in camera mode 1 the car-to-Spike
   direction goes to scratch +0x40. The x^2 term and the clamps reuse a and d to match. */
void Camera_FollowRcCar(Cam_8004AA58_8004AA58 *cam) {
    SVECTOR v;
    s32 sxy;
    s32 p;
    u16 x, y, z;
    s32 d;
    s32 k;
    s32 t;
    s32 a;
    u8 *scratch = (u8 *)0x1F800000;
    x = g_RcCar.x;
    y = g_RcCar.y;
    v.vx = x + g_RcCar.vx * 4;
    v.vy = y;
    z = g_RcCar.z;
    v.vz = z + g_RcCar.vz * 4;
    SetRotMatrix(&g_ViewMatrix);
    SetTransMatrix(&g_ViewMatrix);
    t = RotTransPers(&v, &sxy, &p, &p);
    if (t <= 0) {
        t = 1;
    }
    a = ((s16)x - SP_4AA58->x) * ((s16)x - SP_4AA58->x);
    k = 0x2900 / t;
    d = SquareRoot0(a + ((s16)z - SP_4AA58->z) * ((s16)z - SP_4AA58->z));
    cam->zoom = 0;
    if (d > 0x180 && D_800E54A2 != 0) {
        d = k + 0x10;
        if (d > 0) {
            if (d < 0x29) {
                a = d;
            } else {
                a = 0x28;
            }
        } else {
            a = 1;
        }
        d = a * 40 / 32;
        if (d < 0x10) {
            a = 0x10;
        } else if (d < 0x29) {
            a = d;
        } else {
            a = 0x28;
        }
        cam->zoom = a;
    }
    if (D_800E54A2 > 0x14) {
        cam->f_81 = 1;
    }
    if (D_800E68D6 == 1 && cam->f_81 != 0) {
        ((SVECTOR *)(scratch + 0x40))->vx = x - SP_4AA58->x;
        ((SVECTOR *)(scratch + 0x40))->vy = y - SP_4AA58->y;
        ((SVECTOR *)(scratch + 0x40))->vz = z - SP_4AA58->z;
        VectorNormalSS((SVEC_80049514 *)(scratch + 0x40), (SVEC_80049514 *)(scratch + 0x40));
    }
    Camera_UpdateFollow(cam, 0);
}

/* Look / aim camera (run by Camera_HandleViewButtons). Unless the current setting type
 * (g_CameraState+6) is 2 it only eases towards the normal camera. Otherwise the eye is at Spike's
 * head (0x50 higher when his flags +0x70 say 0x80), the right stick X / D-pad Left-Right turn
 * Spike's facing (+0x60), and stick Y / D-pad Up-Down tilt the look point, clamped between
 * +0x400 (aiming) or +0x734 above and 0xABC below the base +0xC. In sub-mode 1 it hands over
 * to Camera_CallStageHook(2); while aiming (+0x46) it calls Camera_DrawAimReticle. */
void Camera_UpdateLook(Cam_8004AC84_8004AC84 *cam) {
    Scr_8004AC84_8004AC84 *scr = (Scr_8004AC84_8004AC84 *)0x1F800000;
    struct S_D_800E68D0_8004AC84 *d = ((struct S_D_800E68D0_8004AC84 *)&g_CameraState);
    Sp_8004AC84_8004AC84 *sp;
    u16 c;
    u8 m[0x20];
    s32 lift;
    s32 rot;
    s32 y;
    s32 lim;
    s32 one;
    s32 dy;
    s32 r;
    if (d->f_46 == 1) {
        d->f_32 = 0;
    }
    if (d->f_6 != 2) {
        Camera_PlaceBehindSpike(cam, &scr->tgt, cam->dist);
        cam->f_14 = scr->v18.vy - 300;
        cam->f_C = scr->v18.vy - 300;
        cam->dist = (cam->dist + 0xE00) / 8;
        return;
    }
    sp = &(*(Sp_8004AC84_8004AC84 *)&g_Spike);
    lift = 0;
    if ((sp->f_70 & 0xF0) == 0x80) {
        lift = 0x50;
    }
    r = g_Pad.sx / 4;
    if (g_Pad.held & PAD_LEFT) {
        r -= 0x18;
    }
    rot = r;
    if (g_Pad.held & PAD_RIGHT) {
        rot += 0x18;
    }
    Matrix_SetIdentity(m);
    RotMatrixY(rot, m);
    ApplyMatrixSV(m, &sp->dir, &sp->dir);
    VectorNormalSS(&sp->dir, &sp->dir);
    scr->at.vx = cam->f_12 = sp->x + sp->dir.vx / 2;
    scr->at.vz = cam->f_16 = sp->z + sp->dir.vz / 2;
    y = cam->f_14 + g_Pad.sy * 2;
    if (g_Pad.held & PAD_UP) {
        y += 0x100;
    }
    one = 1;
    if (g_Pad.held & PAD_DOWN) {
        y -= 0x100;
    }
    scr->at.vy = y;
    c = cam->f_C;
    lim = c + 0x400;
    if (d->f_46 != one) {
        lim = c + 0x734;
    }
    if ((s16)lim < (s16)y) {
        scr->at.vy = lim;
    }
    if (scr->at.vy < cam->f_C - 0xABC) {
        scr->at.vy = cam->f_C - 0xABC;
    }
    dy = lift - 200;
    scr->eye.vx = sp->x;
    scr->eye.vy = sp->y + dy;
    scr->eye.vz = sp->z;
    Camera_EaseLookAt(cam, 4, 3, 4);
    Camera_EaseEye(cam, 4, 3, 4);
    d->f_33 = 0;
    Camera_PlaceBehindSpike(&(*(A_8004AC84_8004AC84 * *)&g_CameraSlots)[d->f_18], &scr->tgt, 0x333);
    if ((*(struct Game_8004AC84 *)&g_Game).f_8150 == one) {
        Camera_CallStageHook(2, (s32)cam);
    } else if (d->f_46 == one) {
        Camera_DrawAimReticle(cam);
    }
}

typedef struct { u8 pad0[0x30]; u8 f_30; u8 pad31[7]; u16 step; u8 pad3A[6]; s32 yaw; } CamAim_4AF78;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x30]; s16 dirX; s16 dirY; s16 dirZ; } Spike_4AF78;
typedef struct { u8 pad0[0xA2]; s8 sx; s8 sy; u8 padA4[0xDC]; u16 magL; } Pad_4AF78;
typedef struct { u32 tag; u32 code; u32 xy0; u32 xy1; } LineF2_4AF78;
typedef struct { u32 addr : 24; u32 len : 8; } PT_4AF78;
#define AP_4AF78(ot, p) (((PT_4AF78 *)(p))->addr = ((PT_4AF78 *)(ot))->addr, ((PT_4AF78 *)(ot))->addr = (u32)(p))
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad1E; u32 xy3; u16 uv3; u16 pad26; } FT4_4AF78;
extern Spike_4AF78 g_Spike_4AF78 asm("g_Spike");
extern Pad_4AF78 g_Pad_4AF78 asm("g_Pad");
extern u8 D_800E6916;
extern u16 D_800EC23E;
extern s8 D_800E53C3;
extern u8 D_800B8CB0;
s32 CamFlyby_IsActive(void);
s32 Floor_GetHeight_4AF78(s32, s32, s32) asm("Floor_GetHeight");
s32 RotTransPers_4AF78(SVECTOR *, s32 *, s32 *, s32 *) asm("RotTransPers");

void Camera_DrawAimReticle(Cam_8004AC84_8004AC84 *cam) {
    CamAim_4AF78 *c = (CamAim_4AF78 *)cam;
    SVECTOR v;
    s32 sxy;
    s32 dummy;
    s16 sy;
    s16 sx;
    s32 mode;
    s32 half;
    s32 n, t;
    s16 w, h;
    LineF2_4AF78 *l;
    u32 *ot;
    s16 *scr;
    s32 st;

    mode = 1;
    half = 0;
    __asm__("" : "=r"(scr) : "0"(0x1F800000));
    if (CamFlyby_IsActive() != 0) {
        return;
    }
    if (D_800E6916 != 0) {
        sx = 0xC0;
        sy = 0x78;
        st = D_800EC23E;
        if (st >= 0x82 && (st < 0x85 || st == 0x86)) {
            mode = 2;
        }
    } else {
        half = 1;
        st = D_800EC23E;
        if (st < 0x82 || (st >= 0x85 && st != 0x86)) {
            mode = 0;
        } else {
            mode = 2;
            if (g_Pad_4AF78.magL >= 0x33 && Stage_GetSpecialKind() == 0) {
                if (g_Pad_4AF78.sx > 0) {
                    c->yaw = (c->yaw + 0xFEA) % 4096;
                } else {
                    c->yaw = (c->yaw + 0x1016) % 4096;
                }
                c->f_30 = 0;
                __asm__ volatile("");
                if (D_800E53C3 < -0x50) {
                    scr[1] += c->step;
                    if (scr[1] > g_Spike_4AF78.y - 0x40) {
                        scr[1] = g_Spike_4AF78.y - 0x40;
                    }
                } else if (D_800E53C3 > 0x50) {
                    scr[1] -= c->step;
                }
            }
            SetRotMatrix(&g_ViewMatrix);
            SetTransMatrix(&g_ViewMatrix);
            v.vy = g_Spike_4AF78.y - 0x80;
            v.vx = g_Spike_4AF78.x + g_Spike_4AF78.dirX / 3;
            v.vz = g_Spike_4AF78.z + g_Spike_4AF78.dirZ / 3;
            RotTransPers_4AF78(&v, &sxy, &dummy, &dummy);
            sx = sxy;
            sy = sxy >> 16;
            v.vy = Floor_GetHeight_4AF78(v.vx, v.vy, v.vz);
            RotTransPers_4AF78(&v, &sxy, &dummy, &dummy);
            l = (LineF2_4AF78 *)G_DRAW.prim;
            {
            s16 x2 = sxy; s16 y2 = sxy >> 16; s32 cur = G_DRAW.cur; u32 *o2;
            ((u8 *)l)[3] = 3;
            l->xy0 = (y2 << 16) | ((x2 - 7) & 0xFFFF);
            l->xy1 = (y2 << 16) | ((x2 + 7) & 0xFFFF);
            l->code = 0x43010101;
            o2 = G_DRAW.db[cur].ot;
            AP_4AF78(&o2[2], l);
            l = (LineF2_4AF78 *)((u8 *)l + 0x10);
            ((u8 *)l)[3] = 1;
            ((u32 *)l)[1] = 0xE1000200;
            AP_4AF78(&o2[2], l);
            }
            G_DRAW.prim = (u8 *)l + 8;
        }
    }
    if (mode != 0) {
        for (n = 2; n > 0; n--) {
            FT4_4AF78 *p;
            s32 y0, y1, x0, x1;
            if (mode == 2) {
                t = D_800B8CB0 & 0x1F;
                if (t >= 0x10) {
                    t = 0x1F - t;
                }
                h = w = t + 0xC;
            } else {
                D_800B8CB0 = 0x13;
                h = w = 0x18;
            }
            ot = G_DRAW.db[G_DRAW.cur].ot;
            p = (FT4_4AF78 *)G_DRAW.prim;
            if (half) {
                w >>= 1;
                h >>= 1;
            }
            ((u8 *)p)[3] = 9;
            p->code = 0x2F000000;
            y0 = (sy - h) << 16;
            x0 = (sx - w) & 0xFFFF;
            x1 = (sx + w) & 0xFFFF;
            y1 = (sy + h) << 16;
            p->xy0 = y0 | x0;
            p->uv2 = 0x3040;
            p->xy1 = y0 | x1;
            p->xy2 = y1 | x0;
            p->xy3 = y1 | x1;
            p->uv0 = 0x7D2D0040;
            p->uv1 = 0x1B006F;
            p->uv3 = 0x306F;
            AP_4AF78(&ot[1], p);
            p++; G_DRAW.prim = (u8 *)p;
        }
        D_800B8CB0++;
    }
}

void Camera_EnterAim(void) {
    if ((g_CameraState.f_46 != 1) && (Stage_IsArea53() == 0)) {
        g_CameraState.f_46 = 1U;
        Sound_PlayFixed(4);
    }
}

void Camera_ExitAim(void) {
    if (g_CameraState.f_46 != 0) {
        g_CameraState.f_46 = 0U;
        Sound_PlayFixed(5);
    }
}

void Camera_GetLookAt(SVECTOR *arg0) {
    *arg0 = *(SVECTOR *)(D_800E68D8 + 0x12);
}

void func_8004B580(void) {
    D_800E6912 = 1;
}

void Camera_CallStageHook(s32 i, s32 arg) {
    void (**tbl)(s32);
    if (g_Game.f_8126 == 0x38) {
        tbl = D_80141390;
    } else if (g_Game.f_8126 == 0x42) {
        tbl = D_8014440C;
    }
    tbl[i](arg);
}

/* Camera for game sub-mode 3 (the Jake race, via Camera_UpdateMode): orbits Spike at a distance
 * easing towards 0x464. Left/Right on the D-pad turn it by 0x38, or the stick (scratchpad +0x74)
 * beyond +-0xB6 by 0x16; Down raises the eye by 0x180, Up lowers it by 0x200 and lifts the look-at
 * point by 0x100. Eye / look-at / target are scratchpad SVECTORs at 0x0 / 0x8 / 0x10. */
void Camera_UpdateOrbit(Cam_8004B5FC_8004B5FC *cam) {
    Scr_8004B5FC_8004B5FC *scr = (Scr_8004B5FC_8004B5FC *)0x1F800000;
    s32 sx;
    scr->tgt.vx = ((struct Spike_8004B5FC *)&g_Spike)->x;
    scr->tgt.vy = ((struct Spike_8004B5FC *)&g_Spike)->y - 0x80;
    scr->tgt.vz = ((struct Spike_8004B5FC *)&g_Spike)->z;
    cam->dist = (cam->dist + 0x464) / 2;
    func_80047360((S_C_80048DD0_80048DD0 *)cam);
    if (!(PAD_4B5FC->held & 0xA000)) {
        sx = scr->stick;
        if (sx < -0xB6) {
            cam->yaw = (cam->yaw + 0x1016) % 0x1000;
        } else if (sx >= 0xB7) {
            cam->yaw = (cam->yaw + 0xFEA) % 0x1000;
        }
    } else {
        if (PAD_4B5FC->held & 0x8000) {
            cam->yaw = (cam->yaw + 0xFC8) % 0x1000;
        }
        if (PAD_4B5FC->held & 0x2000) {
            cam->yaw = (cam->yaw + 0x1038) % 0x1000;
        }
    }
    scr->at.vx = scr->tgt.vx;
    scr->at.vy = scr->tgt.vy;
    scr->at.vz = scr->tgt.vz;
    scr->eye.vx = scr->tgt.vx + (rcos(cam->yaw) * cam->dist >> 12);
    scr->eye.vy = scr->tgt.vy - 0x1E0;
    scr->eye.vz = scr->tgt.vz + (rsin(cam->yaw) * cam->dist >> 12);
    if (PAD_4B5FC->held & 0x4000) {
        scr->eye.vy += 0x180;
    }
    if (PAD_4B5FC->held & 0x1000) {
        scr->eye.vy -= 0x200;
        scr->at.vy += 0x100;
    }
    Camera_EaseLookAt(cam, 8, 8, 8);
    Camera_EaseEye(cam, 5, 8, 5);
}

void func_8004B83C(void) {
    void *temp_v1;

    temp_v1 = g_CameraSlots + (D_800E68E8 * 0xB0);
    M2C_FIELD(temp_v1, s8 *, 0x34) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x36) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x35) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x37) = 0;
}
