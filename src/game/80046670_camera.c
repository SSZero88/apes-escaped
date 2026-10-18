#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define HUD_DB ((struct D4DB0_80046BC4 *)&D_800F4DB0)
#define HUD_CAM ((struct Cam_80046BC4 *)&D_800E68D0)
#define HUD_GS ((struct GS_80046BC4 *)&g_GadgetState)
#define CS_4875C ((struct CS_8004875C *)&D_800E68D0)
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; SVECTOR f_A; SVECTOR f_12; u8 pad1A[0x12]; s32 f_2C; u8 pad30[8]; s32 f_38; u8 pad3C[0x30]; s16 f_6C; } S_47104_80047104;
typedef struct { u8 pad0[0xA]; s16 f_A; s16 f_C; s16 f_E; u8 pad10[2]; s16 f_12; s16 f_14; s16 f_16; } S_47690_80047690;
typedef struct { u8 f_0; u8 pad1[0x92]; u8 f_93; u8 pad94[0x1C]; } S_B4D40_80047290;
typedef struct { u16 f_0; u16 f_2; u8 pad4[0x2C]; } S_30_80047290;
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_80046990;
typedef struct { P_TAG_80046990 tag; u32 rgbc; u32 xy; u32 wh; } TILE_80046990;
typedef struct { P_TAG_80046990 tag; u32 code; } DR_MODE_80046990;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_80046990;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80047EE0_80047EE0;
typedef struct { u8 pad0[0x10]; SVEC_80047EE0_80047EE0 f_10; SVEC_80047EE0_80047EE0 f_18; u8 pad20[0x20]; SVEC_80047EE0_80047EE0 f_40; u8 pad48[0x20]; s32 f_68; s32 f_6C; s32 f_70; } SCR_80047EE0_80047EE0;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0xA]; s16 f_46; u8 pad48[0x18]; s16 f_60; s16 f_62; s16 f_64; } S_80047EE0_80047EE0;
typedef struct { u8 pad0[4]; s16 f_4; u8 pad6[0x2C]; u8 f_32; u8 f_33; u8 pad34[4]; s32 f_38; u8 pad3C[4]; s32 f_40; } Cam_8004875C_8004875C;
typedef struct { s16 v[4]; } B16_80046DE8_80046DE8;
typedef struct { u8 pad0[0xA]; s16 f_A; u8 padC[2]; s16 f_E; u8 pad10[0x23]; u8 f_33; u8 pad34[0x5A]; u8 f_8E; u8 pad8F[5]; s16 f_94; u8 pad96[2]; s16 f_98; u8 pad9A[0x16]; } A_80046DE8_80046DE8;
typedef struct { u8 pad0[4]; s16 f_4; u8 pad6[0x32]; s32 f_38; } Cam_80048454_80048454;
typedef struct { u8 pad0[0x32]; u8 f_32; u8 pad33[0x4E]; u8 f_81; u8 pad82[0x2E]; } A_80048454_80048454;
typedef struct { s16 vx, vy, vz, pad; } SV_47FF0_80047FF0;
typedef struct { u8 pad0[0xA]; SV_47FF0_80047FF0 eye; SV_47FF0_80047FF0 look; } Set_47FF0_80047FF0;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80046670_80046670;
typedef struct { s16 vx, vy, vz, pad; } SV_80046670_80046670;
typedef struct { s32 vx, vy, vz, pad; } V_80046670_80046670;

extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x22]; u16 f_8126; u8 pad_8128[0x2A]; u16 f_8152; u8 pad_8154[0x104]; SVECTOR f_8258; SVECTOR f_8260; } g_Game;
void func_800493D4(S_47104_80047104 *);
void func_8004C2E4(S_47104_80047104 *);

extern s8 g_CurrentGadget;
s32 Spike_IsUnderwater(void);

void func_8002FAF0(s32);
extern struct S_D_800E68D0 { u8 pad_0[0x8]; S_47690_80047690 *f_8; u8 pad_C[0x4]; u16 f_10; u16 f_12; u16 f_14; u8 pad_16[0x16]; u16 f_2C; u8 pad_2E[0x1]; u8 f_2F; u8 pad_30[0x2]; u8 f_32; u8 pad_33[0x5]; u8 f_38; u8 pad_39[0x1]; u8 f_3A; u8 f_3B; u8 f_3C; u8 pad_3D[0x1]; u8 f_3E; u8 pad_3F[0x2]; u8 f_41; } D_800E68D0;

void func_80046990(s32 c);


s32 func_800468EC(void);
extern struct S_D_800F5120 { u8 pad_0[0x18]; s32 f_18; s32 f_1C; } g_GadgetState;
void Camera_DenyLook(void);
s32 Stage_GetSpecialKind();
s32 func_8005DC78();
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern struct S_D_800E6950 { s16 x, y, z; u8 pad6[2]; u8 timer; u8 level; } g_CameraShake;
s32 Math_Atan2(s32 arg0, s32 arg1);
extern struct S_D_800EC1E0 { u8 pad_0[0x24]; u16 f_24; u8 pad_26[6]; u16 f_2C; u8 pad_2E[0x30]; u16 state; s16 f_60; u8 pad_62[0x2]; s16 f_64; u8 pad_66[0x8C]; s8 gadget; } g_Spike;

M2C_UNK func_80047360();
extern s32 g_RadarLiveTarget;
extern s8 D_800E6908;
extern S_B4D40_80047290 *D_800B4D40;
struct S_D_800E68D0_80047290 { u8 pad0[2]; u16 f_2; u16 f_4; u8 pad6[6]; u8 f_C; u8 f_D; u8 f_E; u8 padF[0xC]; u8 f_1B; u8 pad1C[0x25]; u8 f_41; u8 pad42[0xA]; S_30_80047290 *f_4C; };
struct S_D_800EC350_80046990 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_80046990 db[2]; };
void func_800154DC(void *, SVECTOR *);
struct S_D_800EC1E0_80047DA4 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x24]; SVECTOR f_60; u8 pad68[0xC4]; s32 f_12C; };
struct S_D_800E68D0_80047DA4 { u8 pad0[0x6C]; SVECTOR f_6C; SVECTOR f_74; };
struct S_D_800E68D0_80047EE0 { u8 pad0[0x48]; u8 f_48; u8 pad49[0x23]; SVEC_80047EE0_80047EE0 f_6C; SVEC_80047EE0_80047EE0 f_74; };
struct S_D_800E6950_80048BBC { s16 f_0; s16 f_2; s16 f_4; u8 pad6[2]; u8 f_8; };
struct D4DB0_80046BC4 { u8 pad0[4]; u16 f_4; u8 pad6[0x1A]; s32 f_20; };
struct Cam_80046BC4 { u8 pad0[0x2F]; u8 f_2F; u8 pad30[2]; u8 f_32; u8 pad33[0x13]; u8 f_46; };
struct GS_80046BC4 { u8 pad0[0x18]; s32 f_18; s32 f_1C; };
extern M2C_UNK D_800F4DB0;
void Hud_DrawStatusIcon(s32, s32, s16, s32);
struct Game_800482C0 { u8 pad0[0x8150]; u16 f_8150; };
void Camera_UpdateOrbit(void);
void func_8004B590(s32, void *);
s32 Camera_RcCarActive(void);
void Camera_FollowRcCar(void *);
s32 func_8004A940(void);
void func_8013D000(void *);
s32 Camera_UpdateSpecial(void *);
void func_800495F4(void *, s32);
struct CS_8004875C { u8 pad0[0x32]; u8 f_32; u8 pad33[5]; u8 f_38; };
struct Pad_8004875C { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; };
extern struct S_D_800E5320 { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; } g_Pad;
s32 func_8009A17C(void *);
void func_80048748(void);
void Camera_ExitLook(void);
void Radar_GetLiveTarget(void);
void Camera_ExitAim(void);
void func_80046978(s32 arg0, s32 arg1, s32 arg2);
void func_80047EE0(void);
void func_80048D10(void *arg0, void *arg1, s32 arg2);
void func_80046970(void);
s32 Floor_GetHeight(s32, s32, s32);
void Radar_DrawMonkeyCard(void *);
struct Game_80046DE8 { u8 pad0[0x8258]; B16_80046DE8_80046DE8 f_8258; B16_80046DE8_80046DE8 f_8260; };
void Camera_ResetToStart(void);
void Camera_SetSetting(s32);
void VectorNormalSS(void *, void *);
struct S_D_800E68D0_80046DE8 { u8 pad0[0xE]; u8 cur; u8 mode; u8 pad10[8]; u8 f_18, f_19, f_1A, f_1B; B16_80046DE8_80046DE8 f_1C; B16_80046DE8_80046DE8 f_24; u8 pad2C[2]; u8 kind; u8 pad2F; s16 f_30; u8 f_32; u8 pad33[5]; u8 f_38; u8 pad39[8]; u8 f_41; u8 f_42; u8 pad43[3]; u8 f_46; };
extern u8 D_800E6902;
extern u8 D_800E6916;
struct Game_80048454 { u8 pad0[0x8126]; u16 mode; u8 pad8128[0x28]; u16 sub; };
s32 func_8004D104(void);
void Camera_EnterAim(void);
void Camera_EnterLook(void);
void func_80047654(void *arg0);
void Camera_UpdateLook(Cam_80048454_80048454 *);
struct S_D_800E68D0_80048454 { u8 pad0[0x18]; u8 f_18; u8 pad19[0x19]; u8 f_32; u8 pad33[0xB]; u8 f_3E; u8 pad3F[2]; u8 f_41; u8 pad42[4]; u8 f_46; };
extern u16 g_RandSeed;
struct Game_47FF0 { u8 pad0[0x8258]; SV_47FF0_80047FF0 eye; SV_47FF0_80047FF0 look; };
struct S_D_800E68D0_80047FF0 { u8 pad0[8]; Set_47FF0_80047FF0 *set; u8 padC[0x10]; SV_47FF0_80047FF0 eye; SV_47FF0_80047FF0 look; u8 pad2C[2]; u8 kind; u8 pad2F; u16 t; };
extern MAT_80046670_80046670 D_800AF0A0;
extern MAT_80046670_80046670 D_800EBFD0;
s32 SquareRoot0(s32 a);
void *MulMatrix0(void *m0, void *m1, void *m2);
void *CompMatrix(void *m0, void *m1, void *m2);
void *ApplyMatrixLV(void *m, void *v0, void *v1);
void VectorNormal(void *v0, void *v1);
s32 rcos(s32);
s32 rsin(s32);
void memset(void *p, s32 c, s32 n);
s32 Water_Query(s32 x, s32 y, s32 z);
struct S_D_800EC350_80046670 { u8 pad_0[0x827C]; s32 f_827C; };

/* Camera_LookAt: build the GTE view matrix from eye to at: yaw from the xz direction, pitch from
 * the normalised 3D direction, an optional roll (MulMatrix0 with a z rotation), translation -eye,
 * then CompMatrix with D_800AF0A0; rot gets the yaw-only matrix and D_800EBFD0 = view * rot. Also
 * records whether the eye is under water (g_Game+0x827C = Water_Query(eye)). The two do/while(0)
 * around the roll matrix stores are needed for the match. */
void Camera_LookAt(SV_80046670_80046670 *eye, SV_80046670_80046670 *at, MAT_80046670_80046670 *view, MAT_80046670_80046670 *rot, s16 roll) {
    V_80046670_80046670 d;
    V_80046670_80046670 n;
    MAT_80046670_80046670 r;
    s32 nx;
    s32 nz;
    s32 ny;
    s32 h;
    s32 c;
    s32 sn;

    view->t[0] = -eye->vx;
    view->t[1] = -eye->vy;
    view->t[2] = -eye->vz;
    d.vx = at->vx - eye->vx;
    d.vy = 0;
    d.vz = at->vz - eye->vz;
    if (d.vx == 0 && d.vz == 0) {
        d.vz = 0x1000;
    }
    VectorNormal(&d, &n);
    nx = n.vx;
    nz = n.vz;
    d.vy = at->vy - eye->vy;
    VectorNormal(&d, &n);
    ny = n.vy;
    h = SquareRoot0(n.vz * n.vz + n.vx * n.vx);
    view->m[0][0] = nz;
    view->m[0][1] = 0;
    view->m[0][2] = -nx;
    view->m[1][0] = (-nx * ny) >> 12;
    view->m[1][1] = h;
    view->m[1][2] = -(ny * nz) >> 12;
    view->m[2][0] = -(h * -nx) >> 12;
    view->m[2][1] = ny;
    view->m[2][2] = (h * nz) >> 12;
    rot->m[2][2] = nz;
    rot->m[0][0] = nz;
    rot->m[2][1] = 0;
    rot->m[1][2] = 0;
    rot->m[1][0] = 0;
    rot->m[0][1] = 0;
    rot->m[0][2] = nx;
    rot->m[2][0] = -nx;
    rot->m[1][1] = 0x1000;
    if (roll != 0) {
        c = rcos(roll);
        sn = rsin(roll);
        r.m[0][0] = c;
        r.m[0][1] = sn;
        r.m[0][2] = 0;
        do { r.m[1][0] = -sn; } while (0);
        do { r.m[1][1] = c; } while (0);
        r.m[1][2] = 0;
        r.m[2][0] = 0;
        r.m[2][1] = 0;
        r.m[2][2] = 0x1000;
        memset(r.t, 0, 12);
        MulMatrix0(&r, view, view);
    }
    ApplyMatrixLV(view, view->t, view->t);
    CompMatrix(&D_800AF0A0, view, view);
    MulMatrix0(view, rot, &D_800EBFD0);
    ((struct S_D_800EC350_80046670 *)&g_Game)->f_827C = Water_Query(eye->vx, eye->vy, eye->vz);
}

s32 func_800468EC(void) {
    s32 r;
    if (g_Game.f_8126 >= 0x58 && g_Game.f_8126 < 0x63) {
        return 0;
    }
    if (g_Game.f_8152 == 11) {
        return 0;
    }
    if (Spike_IsUnderwater() != 0) {
        return 0;
    }
    r = 0;
    if (g_CurrentGadget == 2) {
        r = func_8005DC78() != 0;
    }
    return r;
}

void func_80046970(void) {
}

void func_80046978(s32 arg0, s32 arg1, s32 arg2) {
    D_800E68D0.f_3A = arg0;
    D_800E68D0.f_3B = arg1;
    D_800E68D0.f_3C = arg2;
}

void func_80046990(s32 c)
{
  TILE_80046990 *p = (TILE_80046990 *) ((struct S_D_800EC350_80046990 *)&g_Game)->prim;
  u32 *ot = ((struct S_D_800EC350_80046990 *)&g_Game)->db[((struct S_D_800EC350_80046990 *)&g_Game)->cur].ot;
  DR_MODE_80046990 *m;
  p->tag.len = 3;
  p->rgbc = (((c << 16) | (c << 8)) | c) | 0x62000000;
  p->xy = 0;
  p->wh = 0xF00180;
  p->tag.addr = ((P_TAG_80046990 *) ot)->addr;
  ((P_TAG_80046990 *) ot)->addr = (u32) p;
  p = (DR_MODE_80046990 *) (p - -1);
  m = p;
  m->tag.len = 1;
  m->code = 0xE1000240;
  m->tag.addr = ((P_TAG_80046990 *) ot)->addr;
  ((P_TAG_80046990 *) ot)->addr = (u32) m;
  ((struct S_D_800EC350_80046990 *)&g_Game)->prim = (u8 *) (m + 1);
}

void func_80046A78(void) {
    if (D_800E68D0.f_3A != 0) {
        D_800E68D0.f_3A = (u8) (D_800E68D0.f_3A - 1);
        func_80046990(D_800E68D0.f_3B);
        D_800E68D0.f_3B = (u8) (D_800E68D0.f_3B + D_800E68D0.f_3C);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80046670_camera", Hud_DrawStatusIcon);

/* Places the HUD status icons (via Hud_DrawStatusIcon(icon, x, y, flag)) along the bottom-left,
 * shifted by D_800F4DB0+4 when its flag 8 is set. Icon 1 flashes to 2 every 4 frames while the
 * Monkey Radar (gadget 2) is active; icon 4 and the 0 marker move when camera mode
 * (D_800E68D0+0x46 or +0x32) is 1; icon 3 blinks while the D_800E68D0+0x2F counter runs down;
 * the last icon is 6 if func_800468EC() says so, 7 with the Slingback (gadget 3), else 5. */
void Hud_UpdateStatusIcons(void) {
    s32 y = 0;
    s32 x;
    s32 flag;
    s32 icon;
    s32 a;
    u8 t;
    if (HUD_DB->f_20 & 8) {
        y = HUD_DB->f_4;
    }
    y += 0xB8;
    a = 1;
    if (((*(s32 *)&g_Game) & 4) && g_CurrentGadget == 2 && HUD_GS->f_1C == 1 && HUD_GS->f_18 != 0) {
        a = 2;
    }
    Hud_DrawStatusIcon(a, 0x18, y, 0);
    x = 0x18;
    flag = 0;
    if (HUD_CAM->f_46 == 1 || HUD_CAM->f_32 == 1) {
        x = 0x2D;
        flag = 1;
    }
    Hud_DrawStatusIcon(4, 0x19, y + 0x10, flag);
    t = HUD_CAM->f_2F;
    if (t != 0) {
        HUD_CAM->f_2F = t + 0xFF;
        if (t & 1) {
            Hud_DrawStatusIcon(3, 0x2D, y + 0x12, 0);
        }
    }
    icon = 5;
    if (func_800468EC() != 0) {
        icon = 6;
    } else if (g_CurrentGadget == 3) {
        icon = 7;
    }
    Hud_DrawStatusIcon(icon, 0x2D, y + 0x12, flag ^ 1);
    Hud_DrawStatusIcon(0, x - 2, y + 0xE, 1);
}

void func_80046D80(u16 arg0)
{
  u16 new_var2;
  u16 new_var;
  struct S_D_800E68D0 *p = &D_800E68D0;
  if (1)
  {
    p->f_2C = (new_var = (new_var2 = arg0));
  }
  if (p)
  {
    func_8002FAF0(new_var);
  }
  else
  {
    func_8002FAF0(new_var);
  }
}

struct Cam_SetSetting { u8 pad0[4]; u16 f_4; u16 f_6; void *f_8; };
typedef struct { u8 f_0; u8 pad1[0xAF]; } Set_SetSetting;
/* Makes camera setting idx (entry of D_800B4D40) current: index +4, type +6 (entry +0), pointer +8. */
void Camera_SetSetting(s32 idx) {
    ((struct Cam_SetSetting *)&D_800E68D0)->f_4 = idx;
    ((struct Cam_SetSetting *)&D_800E68D0)->f_6 = ((Set_SetSetting *)D_800B4D40)[idx].f_0;
    ((struct Cam_SetSetting *)&D_800E68D0)->f_8 = &((Set_SetSetting *)D_800B4D40)[idx];
}

/* Chooses which camera setting (entry of the 0xB0-byte table D_800B4D40) to use. Candidates in
 * D_800E68D0: +0x18 normal (mode 1), +0x1B zone (mode 4, or 5 when the entry's +0x8E is 1),
 * +0x1A when +0x38 is set (mode 3), +0x19 when +0x32/+0x46 is set (mode 2, unless
 * func_8004A940), +0x1B forced by +0x41. On a change it picks the transition kind +0x2E
 * (2 to/from +0x19, 3 for mode 3 or a +0x33 entry, 1 leaving mode 4/5; a mode-5 zone is only
 * entered when Spike is on the side its +0x94/+0x98 direction faces), saves the current view
 * (g_Game+0x8258) at +0x1C and sets the new setting. */
void Camera_SelectSetting(void) {
    struct { s16 x, y, z; } v;
    s32 idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_18;
    s32 mode = 1;
    s32 kind;
    A_80046DE8_80046DE8 *cur;
    A_80046DE8_80046DE8 *nw;
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_1B != 0xFF) {
        mode = 4;
        idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_1B;
        if ((*(A_80046DE8_80046DE8 * *)&D_800B4D40)[idx].f_8E == 1) {
            mode = 5;
        }
    }
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_42 != 0) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_18;
        mode = 1;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_38 == 1) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_1A;
        mode = 3;
    }
    if ((((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_32 == 1 || ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_46 == 1) && !func_8004A940()) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_19;
        mode = 2;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_41 != 0) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_1B;
        mode = 4;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->cur == idx) {
        return;
    }
    kind = 0;
    if (((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->cur == ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_19 || idx == ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_19) {
        kind = 2;
    } else if (mode == 3 || ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->mode == 3) {
        kind = 3;
    } else if (mode == 5) {
        cur = &(*(A_80046DE8_80046DE8 * *)&D_800B4D40)[((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->cur];
        nw = &(*(A_80046DE8_80046DE8 * *)&D_800B4D40)[idx];
        if (nw->f_33 != 0) {
            kind = 3;
        } else {
            v.x = g_Spike.f_24 - cur->f_A;
            v.y = 0;
            v.z = g_Spike.f_2C - cur->f_E;
            VectorNormalSS(&v, &v);
            if (nw->f_94 * v.x + nw->f_98 * v.z < 0) {
                return;
            }
        }
    } else if (mode == 1 && (u8)(((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->mode - 4) < 2) {
        kind = 1;
        Camera_ResetToStart();
    }
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_30 = 0x80;
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->kind = kind;
    if (mode == 4 && ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_41 != 0) {
        ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_30 = 0;
    }
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_1C = ((struct Game_80046DE8 *)&g_Game)->f_8258;
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->f_24 = ((struct Game_80046DE8 *)&g_Game)->f_8260;
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->cur = idx;
    ((struct S_D_800E68D0_80046DE8 *)&D_800E68D0)->mode = mode;
    Camera_SetSetting(idx);
}

void func_800470CC(void *arg0) {
    M2C_FIELD(arg0, SVECTOR *, 0) = g_Game.f_8258;
}

void func_80047104(S_47104_80047104 *p, s32 type) {
    p->f_6 = -0x172;
    p->f_8 = -0x6E;
    p->f_4 = 0x460;
    p->f_A = g_Game.f_8258;
    p->f_12 = g_Game.f_8260;
    p->f_38 = 0x460;
    p->f_2C = 0;
    p->f_6C = 0;
    switch (type) {
    case 1:
    case 3:
        func_800493D4(p);
        break;
    case 4:
    case 5:
        func_8004C2E4(p);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80046670_camera", func_800471E4);

void func_80047290(s32 i) {
    S_B4D40_80047290 *p = &D_800B4D40[i];
    if (((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_41 != 0) {
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_41 = 0;
    }
    if (p->f_93 != 0xFF) {
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_4C[p->f_93].f_2 &= 0xFFF0;
    }
    ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_2--;
    if (p->f_0 >= 4 && p->f_0 < 6 && ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_1B == i) {
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_1B = 0xFF;
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_C = 0;
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_D = 0xFF;
    }
    if (((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_4 == i) {
        ((struct S_D_800E68D0_80047290 *)&D_800E68D0)->f_E = i;
    }
    p->f_0 = 0;
}

typedef struct { s16 vx, vy, vz, pad; } SVEC_80047360;
typedef struct { u8 pad0[0x10]; u16 f_10; u8 pad12[2]; u16 f_14; u8 pad16[0x2A]; u16 f_40; u8 pad42[2]; u16 f_44; u8 pad46[0x2E]; s32 f_74; s32 f_78; } SCR_80047360;
typedef struct { u8 pad0[0xA]; s16 f_A; s16 f_C; s16 f_E; } S_80047360;
void *Bios_Memset_47360(void *, s32, s32) asm("memset");
void func_80047360_(S_80047360 *s) asm("func_80047360");
/* func_80047360: camera side vector: from the camera (scratch +0x10/+0x14) to the target s (f_A,
 * f_E) in xz, normalised; scratch +0x78/+0x74 = its dot and cross products with the scratch
 * direction (+0x40/+0x44). memset (BIOS memset) must be declared returning a pointer. */
void func_80047360_(S_80047360 *s) {
    SVEC_80047360 n;
    SVEC_80047360 v;
    SCR_80047360 *sc = (SCR_80047360 *)0x1F800000;

    Bios_Memset_47360(&v, 0, 8);
    v.vx = sc->f_10 - s->f_A;
    v.vz = sc->f_14 - s->f_E;
    n = v;
    VectorNormalSS(&n, &n);
    sc->f_78 = -((s16)sc->f_40 * n.vx + (s16)sc->f_44 * n.vz) / 4096;
    sc->f_74 = ((s16)sc->f_40 * n.vz - (s16)sc->f_44 * n.vx) / 4096;
}


void func_80047464(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *scratch = (u8 *)0x1F800000;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xA) * (arg1 - 1)) + *(s16 *)(scratch + 0x0000)) / arg1);
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xC) * (arg2 - 1)) + (s16) *(s16 *)(scratch + 0x0002)) / arg2);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xE) * (arg3 - 1)) + (s16) *(s16 *)(scratch + 0x0004)) / arg3);
}

void func_80047558(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *scratch = (u8 *)0x1F800000;
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x12) * (arg1 - 1)) + (s16) *(u16 *)(scratch + 0x0008)) / arg1);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x14) * (arg2 - 1)) + (s16) *(u16 *)(scratch + 0x000A)) / arg2);
    M2C_FIELD(arg0, s16 *, 0x16) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x16) * (arg3 - 1)) + (s16) *(u16 *)(scratch + 0x000C)) / arg3);
}

void func_80047654(void *arg0) {
    func_80047360();
    M2C_FIELD(arg0, s8 *, 0x32) = 0x18;
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
}

/* Moves the camera position and its target by (dx, dy, dz), unless the camera is locked. */
void Camera_Translate(s32 dx, s32 dy, s32 dz) {
    S_47690_80047690 *p = D_800E68D0.f_8;
    if (D_800E68D0.f_38 == 1) {
        return;
    }
    if (g_Game.f_8100 & 1) {
        return;
    }
    p->f_A += dx;
    p->f_C += dy;
    p->f_E += dz;
    p->f_12 += dx;
    p->f_14 += dy;
    p->f_16 += dz;
}

void func_80047720(s32 arg0, s32 arg1, s32 arg2) {
    D_800E68D0.f_10 = (u16) (D_800E68D0.f_10 + arg0);
    D_800E68D0.f_12 = (u16) (D_800E68D0.f_12 + arg1);
    D_800E68D0.f_14 = (u16) (D_800E68D0.f_14 + arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/80046670_camera", func_80047754);

INCLUDE_RODATA("asm/nonmatchings/game/80046670_camera", D_800A4CC0);


INCLUDE_ASM("asm/nonmatchings/game/80046670_camera", func_80047BD0);

INCLUDE_RODATA("asm/nonmatchings/game/80046670_camera", jtbl_800A4CD8);
INCLUDE_RODATA("asm/nonmatchings/game/80046670_camera", jtbl_800A4CD8_pad);


void func_80047DA4(void)
{
  u8 *sc = (u8 *) 0x1F800000;
  func_800154DC(((struct S_D_800EC1E0_80047DA4 *)&g_Spike), (SVECTOR *) 0x1F800010);
  *((SVECTOR *) 0x1F800040) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_60;
  *((s16 *) (sc + 0x18)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_24;
  *((s16 *) (sc + 0x1A)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_28;
  *((s16 *) (sc + 0x1C)) = (((struct S_D_800EC1E0_80047DA4 *)&g_Spike))->f_2C;
  *((s32 *) (sc + 0x68)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_30;
  *((s32 *) (sc + 0x6C)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_34;
  *((s32 *) (sc + 0x70)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_38;
  *((s32 *) (sc + 0x2C)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_12C;
 do { } while (0);
  ((struct S_D_800E68D0_80047DA4 *)&D_800E68D0)->f_6C = *((SVECTOR *) 0x1F800010);
  ((struct S_D_800E68D0_80047DA4 *)&D_800E68D0)->f_74 = *((SVECTOR *) 0x1F800040);
}

void Radar_GetLiveTarget(void) {
    if ((func_800468EC() == 0) || (g_GadgetState.f_1C == 0)) {
        g_RadarLiveTarget = 0;
        return;
    }
    g_RadarLiveTarget = g_GadgetState.f_18;
}

void func_80047EE0(void) {
    S_80047EE0_80047EE0 *m = (*(S_80047EE0_80047EE0 * *)&g_RadarLiveTarget);
    SCR_80047EE0_80047EE0 *sc = (SCR_80047EE0_80047EE0 *)0x1F800000;

    if (m != NULL) {
        ((struct S_D_800E68D0_80047EE0 *)&D_800E68D0)->f_48 = 0;
        sc->f_40.vx = -m->f_60;
        sc->f_40.vy = m->f_62;
        sc->f_40.vz = -m->f_64;
        sc->f_18.vx = m->f_24;
        sc->f_18.vy = m->f_28;
        if (m->f_46 < 0) {
            sc->f_18.vy += 0x180;
            ((struct S_D_800E68D0_80047EE0 *)&D_800E68D0)->f_48 = 1;
        }
        sc->f_18.vz = m->f_2C;
        sc->f_10.vx = sc->f_18.vx;
        sc->f_10.vy = sc->f_18.vy - 0x80;
        sc->f_10.vz = sc->f_18.vz;
        sc->f_68 = m->f_30;
        sc->f_6C = m->f_34;
        sc->f_70 = m->f_38;
    }
    ((struct S_D_800E68D0_80047EE0 *)&D_800E68D0)->f_6C = sc->f_10;
    ((struct S_D_800E68D0_80047EE0 *)&D_800E68D0)->f_74 = sc->f_40;
}

void Camera_BlendToSetting(void) {
    struct S_D_800E68D0_80047FF0 *c = ((struct S_D_800E68D0_80047FF0 *)&D_800E68D0);
    u16 t = c->t;
    Set_47FF0_80047FF0 *s = c->set;
    s32 w;
    struct S_D_800E68D0_80047FF0 *c2;
    s32 iw;
    SV_47FF0_80047FF0 e;
    SV_47FF0_80047FF0 l;

    if (t == 0) {
        (*(struct Game_47FF0 *)&g_Game).eye = s->eye;
        (*(struct Game_47FF0 *)&g_Game).look = s->look;
        return;
    }
    switch (c->kind) {
    default:
    case 0:
        if (t < 0x20) {
            c->t = t - 1;
        } else {
            c->t = t - 3;
        }
        break;
    case 1:
        if (t < 0x30) {
            c->t = c->t * 7 / 8;
        } else {
            c->t = t - 8;
        }
        break;
    case 2:
        c->t = c->t * 3 / 4;
        break;
    case 3:
        c->t = 0;
        break;
    }
    c2 = ((struct S_D_800E68D0_80047FF0 *)&D_800E68D0);
    w = c2->t;
    e = s->eye;
    l = s->look;
    iw = 0x80 - w;
    (*(struct Game_47FF0 *)&g_Game).eye.vx = (c2->eye.vx * w + e.vx * iw) / 128;
    (*(struct Game_47FF0 *)&g_Game).eye.vy = (c2->eye.vy * w + e.vy * iw) / 128;
    (*(struct Game_47FF0 *)&g_Game).eye.vz = (c2->eye.vz * w + e.vz * iw) / 128;
    (*(struct Game_47FF0 *)&g_Game).look.vx = (c2->look.vx * w + l.vx * iw) / 128;
    (*(struct Game_47FF0 *)&g_Game).look.vy = (c2->look.vy * w + l.vy * iw) / 128;
    (*(struct Game_47FF0 *)&g_Game).look.vz = (c2->look.vz * w + l.vz * iw) / 128;
}

/* Camera update for game sub-mode g_Game+0x8150: 3 -> Camera_UpdateOrbit, 1 -> func_8004B590(1, cam);
 * otherwise the first that applies of Camera_FollowRcCar (when Camera_RcCarActive says so), the stage
 * overlay hook func_8013D000 (when func_8004A940 says so), or, unless Camera_UpdateSpecial handled it
 * or D_800E6908 is 1, the normal camera func_800495F4(cam, 0). */
void Camera_UpdateMode(void *cam) {
    u16 m = ((struct Game_800482C0 *)&g_Game)->f_8150;
    if (m == 3) {
        Camera_UpdateOrbit();
    } else if (m == 1) {
        func_8004B590(1, cam);
    } else if (Camera_RcCarActive() != 0) {
        Camera_FollowRcCar(cam);
    } else if (func_8004A940() != 0) {
        func_8013D000(cam);
    } else if (Camera_UpdateSpecial(cam) == 0 && (*(u8 *)&D_800E6908) != 1) {
        func_800495F4(cam, 0);
    }
}

void Camera_EnterLook(void) {
    if ((D_800E68D0.f_32 != 1) && (func_8005DC78() != 0) && (D_800E68D0.f_3E == 0) && (D_800E68D0.f_41 == 0)) {
        if (Stage_GetSpecialKind() != 0) {
            Camera_DenyLook();
            return;
        }
        D_800E68D0.f_32 = 1U;
        Sound_PlayFixed(4);
    }
}

void Camera_ExitLook(void) {
    if (D_800E68D0.f_32 == 1) {
        D_800E68D0.f_32 = 0U;
    }
}

/* View buttons. In look mode (D_800E68D0+0x32), L1 or L2 leaves it (sound 5). Otherwise, unless
 * a camera flyby runs: L2 in game modes 0x13/0x24 or sub-modes 2-3 is refused (Camera_DenyLook);
 * with the Slingback (gadget 3) it toggles aiming (+0x46) from standing/walking states
 * (0, 3, 5, 8-10, 0x10, 0x11, 0x13, 0x80-0x87); with other gadgets except the Monkey Radar it enters
 * look mode from states 0, 1 and 0x46. L1 leaves aiming, or recentres the camera on the current
 * setting (func_80047654, sound 4) when allowed. Then runs Camera_UpdateLook. */
void Camera_HandleViewButtons(Cam_80048454_80048454 *cam) {
    A_80048454_80048454 *p;
    s32 g;
    if (D_800E6902 == 1) {
        if (g_Pad.held & g_Pad.pressed & 5) {
            Camera_ExitLook();
            cam->f_38 = cam->f_4;
            func_80048748();
            Sound_PlayFixed(5);
        }
    } else if (!func_8004D104()) {
        if (g_Pad.held & g_Pad.pressed & 1) {
            if ((*(struct Game_80048454 *)&g_Game).mode == 0x13 || (*(struct Game_80048454 *)&g_Game).mode == 0x24) {
                Camera_DenyLook();
            } else {
                switch ((*(struct Game_80048454 *)&g_Game).sub) {
                case 1:
                    break;
                case 2:
                case 3:
                    Camera_DenyLook();
                    break;
                default:
                    switch (g_Spike.gadget) {
                    case 2:
                        break;
                    case 3:
                        if (D_800E6916 == 1) {
                            Camera_ExitAim();
                            break;
                        }
                        switch (g_Spike.state) {
                        case 0:
                        case 3:
                        case 5:
                        case 8:
                        case 9:
                        case 10:
                        case 0x10:
                        case 0x11:
                        case 0x13:
                        case 0x80:
                        case 0x81:
                        case 0x82:
                        case 0x83:
                        case 0x84:
                        case 0x85:
                        case 0x86:
                        case 0x87:
                            Camera_EnterAim();
                            break;
                        }
                        break;
                    default:
                        switch (g_Spike.state) {
                        default:
                            Camera_DenyLook();
                            break;
                        case 0:
                        case 1:
                        case 0x46:
                            Camera_EnterLook();
                            break;
                        }
                        break;
                    }
                    break;
                }
            }
        }
        if (g_Pad.held & g_Pad.pressed & 4) {
            if (((struct S_D_800E68D0_80048454 *)&D_800E68D0)->f_46 == 1) {
                Camera_ExitAim();
            } else if (((struct S_D_800E68D0_80048454 *)&D_800E68D0)->f_32 != 1 && ((struct S_D_800E68D0_80048454 *)&D_800E68D0)->f_3E == 0 && ((struct S_D_800E68D0_80048454 *)&D_800E68D0)->f_41 == 0 && (*(struct Game_80048454 *)&g_Game).sub != 1 && func_8005DC78()) {
                p = &(*(A_80048454_80048454 * *)&D_800B4D40)[((struct S_D_800E68D0_80048454 *)&D_800E68D0)->f_18];
                if (p->f_32 < 0xF) {
                    func_80047654(p);
                    p->f_81 = 0;
                    Sound_PlayFixed(4);
                }
            }
        }
    }
    Camera_UpdateLook(cam);
}

void func_80048748(void) {
    g_RadarLiveTarget = 0;
    D_800E6908 = 0;
}

/* Monkey Radar LIVE camera (user: a live camera following the monkey, with its info card; separate
 * from the normal first-person look). Camera type 3. Camera mode D_800E68D0+0x38 (D_800E6908): 0 normal, 1 live
 * 2 other. Newly pressing L2 (pad bit 1, confirmed by the user) while func_800468EC allows it toggles: from 0,
 * when a target g_RadarLiveTarget exists, enters the live view (sound 4) and points the camera; from 1
 * leaves it (sound 5); 2 calls func_80046970. In the live view it updates the aim each frame and
 * drops out (func_80048748) when it is no longer allowed. */
void Camera_UpdateRadarLive(Cam_8004875C_8004875C *cam) {
    u8 *scratch = (u8 *)0x1F800000;
    if ((*(u8 *)&D_800E6908) == 1) {
        if (func_800468EC() == 0 || func_8009A17C((*(void * *)&g_RadarLiveTarget)) == 0) {
            func_80048748();
            return;
        }
    }
    if ((((struct Pad_8004875C *)&g_Pad)->pressed & ((struct Pad_8004875C *)&g_Pad)->held & 1) && func_800468EC() != 0) {
        Camera_ExitLook();
        switch (CS_4875C->f_38) {
        case 0:
            Radar_GetLiveTarget();
            if ((*(void * *)&g_RadarLiveTarget) != 0) {
                CS_4875C->f_38 = 1;
                Camera_ExitAim();
                CS_4875C->f_32 = 0;
                func_80046978(3, 200, -60);
                Sound_PlayFixed(4);
                func_80047EE0();
                func_80048D10(cam, scratch + 0x10, 0x333);
                cam->f_40 = Math_Atan2(-*(s16 *)(scratch + 0x40), -*(s16 *)(scratch + 0x44));
                cam->f_33 = 1;
                cam->f_38 = 0x460;
                cam->f_4 = 0x460;
                cam->f_32 = 0;
            }
            break;
        case 1:
            func_80048748();
            func_80046978(3, 200, -60);
            Sound_PlayFixed(5);
            break;
        case 2:
            func_80046970();
            break;
        }
    }
    if ((*(u8 *)&D_800E6908) == 1) {
        func_80047EE0();
        *(s32 *)(scratch + 0x2C) = (s16)Floor_GetHeight(*(s16 *)(scratch + 0x10), *(s16 *)(scratch + 0x12), *(s16 *)(scratch + 0x14));
        func_800495F4(cam, 1);
        Radar_DrawMonkeyCard((*(void * *)&g_RadarLiveTarget));
    }
}

void Camera_DenyLook(void) {
    if ((D_800E68D0.f_2F == 0) && (D_800E68D0.f_41 == 0) && (func_8005DC78() != 0)) {
        D_800E68D0.f_2F = 0xCU;
        Sound_PlayFixed(0x30);
    }
}

void Camera_StopShake(void) {
    g_CameraShake.timer = 0;
    g_CameraShake.level = 0;
}

/* Starts a camera shake of the given level (0, 1, 2: 10, 11, 12 frames; random x/z offset up to
 * +-2, +-4, +-8 and y +-4, +-8, +-16), unless a stronger shake is still running. Read by
 * Camera_UpdateShake. */
void Camera_StartShake(s32 level) {
    if (g_CameraShake.timer != 0 && level < g_CameraShake.level) {
        return;
    }
    g_CameraShake.level = level;
    switch (level) {
    case 0:
    default:
        g_CameraShake.timer = 10;
        g_CameraShake.x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) - 2;
        g_CameraShake.y = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 8) - 4;
        g_CameraShake.z = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) - 2;
        break;
    case 1:
        g_CameraShake.timer = 11;
        g_CameraShake.x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7) - 4;
        g_CameraShake.y = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x10) - 8;
        g_CameraShake.z = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 7) - 4;
        break;
    case 2:
        g_CameraShake.timer = 12;
        g_CameraShake.x = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) - 8;
        g_CameraShake.y = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x20) - 0x10;
        g_CameraShake.z = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF) - 8;
        break;
    }
}

/* Camera shake: alternates the offset's sign each frame, halves it for the last
 * 4 frames, and adds it to the camera position and target.
 */
void Camera_UpdateShake(void) {
    struct S_D_800E6950_80048BBC *s = ((struct S_D_800E6950_80048BBC *)&g_CameraShake);
    if (s->f_8 == 0) {
        return;
    }
    s->f_8--;
    s->f_0 = -s->f_0;
    s->f_2 = -s->f_2;
    s->f_4 = -s->f_4;
    if (s->f_8 < 4) {
        s->f_0 /= 2;
        s->f_2 /= 2;
        s->f_4 /= 2;
    }
    g_Game.f_8258.vx += s->f_0;
    g_Game.f_8258.vy += s->f_2;
    g_Game.f_8258.vz += s->f_4;
    g_Game.f_8260.vx += s->f_0 * 3 / 2;
    g_Game.f_8260.vy += s->f_2 * 3 / 2;
    g_Game.f_8260.vz += s->f_4 * 3 / 2;
}

void func_80048D10(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) (M2C_FIELD(arg1, u16 *, 2) + M2C_FIELD(arg0, u16 *, 8));
    M2C_FIELD(arg0, u16 *, 0x16) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg1, u16 *, 0) - ((s32) (g_Spike.f_60 * arg2) >> 0xC));
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (M2C_FIELD(arg1, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6));
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) (M2C_FIELD(arg1, u16 *, 4) - ((s32) (g_Spike.f_64 * arg2) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x40) = Math_Atan2((s32) -g_Spike.f_60, (s32) -g_Spike.f_64);
}
