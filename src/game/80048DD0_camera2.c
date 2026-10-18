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

s32 func_8005AB6C();
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern struct S_D_800E68D0 { u8 pad_0[0x46]; u8 f_46; } D_800E68D0;

extern s8 D_800E6912;
extern s32 D_800B4D40;
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
void func_80047558(Cam_8004B5FC_8004B5FC *, s32, s32, s32);
void func_80047464(Cam_8004B5FC_8004B5FC *, s32, s32, s32);
extern struct S_D_800E5320 { u8 pad0[0xA2]; s8 sx; s8 sy; u8 padA4[0xB4]; u32 held; } g_Pad;
struct Game_8004AC84 { u8 pad0[0x8150]; u16 f_8150; };
void func_80048D10(void *arg0, void *arg1, s32 arg2);
void func_8004637C(void *);
void RotMatrixY(s32, void *);
void ApplyMatrixSV(void *, void *, void *);
void func_8004B590(s32 i, s32 arg);
void func_8004AF78(Cam_8004AC84_8004AC84 *);
struct S_D_800E68D0_8004AC84 { u8 pad0[6]; u16 f_6; u8 pad8[0x10]; u8 f_18; u8 pad19[0x19]; u8 f_32; u8 f_33; u8 pad34[0x12]; u8 f_46; };
s32 SquareRoot0(s32);
extern s8 g_CurrentGadget;
extern s32 D_800F5A90;
struct g_Game_8004A978 { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0x28]; u16 f_8150; };
s32 Stage_GetSpecialKind(void);
struct Spike_8004AA58 { u8 pad0[0x24]; s32 x, y, z; };
extern Rc_8004AA58_8004AA58 g_RcCar;
extern M2C_UNK D_800E78C0;
extern u16 D_800E54A2;
extern u16 D_800E68D6;
void SetRotMatrix(void *);
void SetTransMatrix(void *);
s32 RotTransPers(SVECTOR *, s32 *, s32 *, s32 *);
void func_800495F4(Cam_8004AA58_8004AA58 *, s32);

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
s32 func_8005DC78(void);
/* Camera_HandleManualInput: manual camera control from the right stick (pad +0xA2/+0xA3, when an
 * analog pad is in mode 1 with +0x180 > 100) or the buttons in D_800E5478: yaw speed f_6E = +-0x22
 * (0x2000 / 0x8000), pitch f_6C = -0x30 / +0x30 (0x1000 / 0x4000) clamped to the limits from
 * scratch +0x1A (-0x404 / +0x100). D_800E5478 is accessed as a struct member (alias rule, README). */
void Camera_HandleManualInput(Cam_8004923C *c) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 rx = 0;
    s32 ry = 0;
    s16 lim;
    if (func_8005DC78() == 0) {
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


void func_800493D4(S_800493D4_800493D4 *o) {
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
  S_B4D40_80049514 *p = &(*(S_B4D40_80049514 * *)&D_800B4D40)[D_800E68E8];
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

INCLUDE_ASM("asm/nonmatchings/game/80048DD0_camera2", func_800495F4);

s32 func_8004A940(void)
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

void func_8004AA24(void)
{
  s8 *new_var;
  new_var = (s8 *) (((s8 *) (D_800B4D40 + (D_800E68E8 * 0xB0))) + 0x81);
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
    SetRotMatrix(&D_800E78C0);
    SetTransMatrix(&D_800E78C0);
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
    func_800495F4(cam, 0);
}

/* Look / aim camera (run by Camera_HandleViewButtons). Unless the current setting type
 * (D_800E68D0+6) is 2 it only eases towards the normal camera. Otherwise the eye is at Spike's
 * head (0x50 higher when his flags +0x70 say 0x80), the right stick X / D-pad Left-Right turn
 * Spike's facing (+0x60), and stick Y / D-pad Up-Down tilt the look point, clamped between
 * +0x400 (aiming) or +0x734 above and 0xABC below the base +0xC. In sub-mode 1 it hands over
 * to func_8004B590(2); while aiming (+0x46) it calls func_8004AF78. */
void Camera_UpdateLook(Cam_8004AC84_8004AC84 *cam) {
    Scr_8004AC84_8004AC84 *scr = (Scr_8004AC84_8004AC84 *)0x1F800000;
    struct S_D_800E68D0_8004AC84 *d = ((struct S_D_800E68D0_8004AC84 *)&D_800E68D0);
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
        func_80048D10(cam, &scr->tgt, cam->dist);
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
    func_8004637C(m);
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
    func_80047558(cam, 4, 3, 4);
    func_80047464(cam, 4, 3, 4);
    d->f_33 = 0;
    func_80048D10(&(*(A_8004AC84_8004AC84 * *)&D_800B4D40)[d->f_18], &scr->tgt, 0x333);
    if ((*(struct Game_8004AC84 *)&g_Game).f_8150 == one) {
        func_8004B590(2, (s32)cam);
    } else if (d->f_46 == one) {
        func_8004AF78(cam);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80048DD0_camera2", func_8004AF78);

void Camera_EnterAim(void) {
    if ((D_800E68D0.f_46 != 1) && (func_8005AB6C() == 0)) {
        D_800E68D0.f_46 = 1U;
        Sound_PlayFixed(4);
    }
}

void Camera_ExitAim(void) {
    if (D_800E68D0.f_46 != 0) {
        D_800E68D0.f_46 = 0U;
        Sound_PlayFixed(5);
    }
}

void func_8004B54C(SVECTOR *arg0) {
    *arg0 = *(SVECTOR *)(D_800E68D8 + 0x12);
}

void func_8004B580(void) {
    D_800E6912 = 1;
}

void func_8004B590(s32 i, s32 arg) {
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
    func_80047558(cam, 8, 8, 8);
    func_80047464(cam, 5, 8, 5);
}

void func_8004B83C(void) {
    void *temp_v1;

    temp_v1 = D_800B4D40 + (D_800E68E8 * 0xB0);
    M2C_FIELD(temp_v1, s8 *, 0x34) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x36) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x35) = 0;
    M2C_FIELD(temp_v1, s8 *, 0x37) = 0;
}
