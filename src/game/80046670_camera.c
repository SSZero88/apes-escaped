#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define HUD_DB ((struct D4DB0_80046BC4 *)&g_HudState)
#define HUD_CAM ((struct Cam_80046BC4 *)&g_CameraState)
#define HUD_GS ((struct GS_80046BC4 *)&g_GadgetState)
#define CS_4875C ((struct CS_8004875C *)&g_CameraState)
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
void Camera_InitFollow(S_47104_80047104 *);
void CamPoint_Init(S_47104_80047104 *);

extern s8 g_CurrentGadget;
s32 Spike_IsUnderwater(void);

void func_8002FAF0(s32);
extern struct S_D_800E68D0 { u8 pad_0[0x8]; S_47690_80047690 *f_8; u8 pad_C[0x4]; u16 f_10; u16 f_12; u16 f_14; u8 pad_16[0x16]; u16 f_2C; u8 pad_2E[0x1]; u8 f_2F; u8 pad_30[0x2]; u8 f_32; u8 pad_33[0x5]; u8 f_38; u8 pad_39[0x1]; u8 f_3A; u8 f_3B; u8 f_3C; u8 pad_3D[0x1]; u8 f_3E; u8 pad_3F[0x2]; u8 f_41; } g_CameraState;

void Screen_DrawFadeTile(s32 c);


s32 Radar_LiveCamAllowed(void);
extern struct S_D_800F5120 { u8 pad_0[0x18]; s32 f_18; s32 f_1C; } g_GadgetState;
void Camera_DenyLook(void);
s32 Stage_GetSpecialKind();
s32 Game_IsPlaying();
M2C_UNK Sound_PlayFixed(M2C_UNK);
extern struct S_D_800E6950 { s16 x, y, z; u8 pad6[2]; u8 timer; u8 level; } g_CameraShake;
s32 Math_Atan2(s32 arg0, s32 arg1);
extern struct S_D_800EC1E0 { u8 pad_0[0x24]; u16 f_24; u8 pad_26[6]; u16 f_2C; u8 pad_2E[0x30]; u16 state; s16 f_60; u8 pad_62[0x2]; s16 f_64; u8 pad_66[0x8C]; s8 gadget; } g_Spike;

M2C_UNK func_80047360();
extern s32 g_RadarLiveTarget;
extern s8 D_800E6908;
extern S_B4D40_80047290 *g_CameraSlots;
struct S_D_800E68D0_80047290 { u8 pad0[2]; u16 f_2; u16 f_4; u8 pad6[6]; u8 f_C; u8 f_D; u8 f_E; u8 padF[0xC]; u8 f_1B; u8 pad1C[0x25]; u8 f_41; u8 pad42[0xA]; S_30_80047290 *f_4C; };
struct S_D_800EC350_80046990 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_80046990 db[2]; };
void Model_GetRootJointPos(void *, SVECTOR *);
struct S_D_800EC1E0_80047DA4 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x24]; SVECTOR f_60; u8 pad68[0xC4]; s32 f_12C; };
struct S_D_800E68D0_80047DA4 { u8 pad0[0x6C]; SVECTOR f_6C; SVECTOR f_74; };
struct S_D_800E68D0_80047EE0 { u8 pad0[0x48]; u8 f_48; u8 pad49[0x23]; SVEC_80047EE0_80047EE0 f_6C; SVEC_80047EE0_80047EE0 f_74; };
struct S_D_800E6950_80048BBC { s16 f_0; s16 f_2; s16 f_4; u8 pad6[2]; u8 f_8; };
struct D4DB0_80046BC4 { u8 pad0[4]; u16 f_4; u8 pad6[0x1A]; s32 f_20; };
struct Cam_80046BC4 { u8 pad0[0x2F]; u8 f_2F; u8 pad30[2]; u8 f_32; u8 pad33[0x13]; u8 f_46; };
struct GS_80046BC4 { u8 pad0[0x18]; s32 f_18; s32 f_1C; };
extern M2C_UNK g_HudState;
void Hud_DrawStatusIcon(s32, s32, s16, s32);
struct Game_800482C0 { u8 pad0[0x8150]; u16 f_8150; };
void Camera_UpdateOrbit(void);
void Camera_CallStageHook(s32, void *);
s32 Camera_RcCarActive(void);
void Camera_FollowRcCar(void *);
s32 Camera_StageHookActive(void);
void func_8013D000(void *);
s32 Camera_UpdateSpecial(void *);
void Camera_UpdateFollow(void *, s32);
struct CS_8004875C { u8 pad0[0x32]; u8 f_32; u8 pad33[5]; u8 f_38; };
struct Pad_8004875C { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; };
extern struct S_D_800E5320 { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; } g_Pad;
s32 Monkey_IsRadarTrackable(void *);
void Camera_ExitRadarLive(void);
void Camera_ExitLook(void);
void Radar_GetLiveTarget(void);
void Camera_ExitAim(void);
void Screen_StartFade(s32 arg0, s32 arg1, s32 arg2);
void Camera_ReadRadarTarget(void);
void Camera_PlaceBehindSpike(void *arg0, void *arg1, s32 arg2);
void Camera_Nop(void);
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
s32 CamFlyby_IsActive(void);
void Camera_EnterAim(void);
void Camera_EnterLook(void);
void Camera_Recenter(void *arg0);
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

s32 Radar_LiveCamAllowed(void) {
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
        r = Game_IsPlaying() != 0;
    }
    return r;
}

void Camera_Nop(void) {
}

void Screen_StartFade(s32 arg0, s32 arg1, s32 arg2) {
    g_CameraState.f_3A = arg0;
    g_CameraState.f_3B = arg1;
    g_CameraState.f_3C = arg2;
}

void Screen_DrawFadeTile(s32 c)
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

void Screen_UpdateFade(void) {
    if (g_CameraState.f_3A != 0) {
        g_CameraState.f_3A = (u8) (g_CameraState.f_3A - 1);
        Screen_DrawFadeTile(g_CameraState.f_3B);
        g_CameraState.f_3B = (u8) (g_CameraState.f_3B + g_CameraState.f_3C);
    }
}

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_7F0;
typedef struct { P_TAG_7F0 tag; u32 mode; u32 code; u32 xy; u32 uvc; u32 wh; } S_Spr_7F0;
typedef struct { u8 u; u8 v; u8 w; u8 h; u16 clut; u16 tpage; } S_SprDef_7F0;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_func_80046ACC;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_func_80046ACC db[2]; } g_Game_7F0 asm("g_Game");
extern S_SprDef_7F0 D_800AF0E0_7F0[] asm("D_800AF0E0");

/* Hud_DrawStatusIcon: one HUD icon sprite (D_800AF0E0[idx]: u, v, w, h, clut, tpage) at x, y in the
 * HUD OT, semi-transparent when semi; addPrim written out with the 0xFFFFFF masks. */
void Hud_DrawStatusIcon(s32 idx, s32 x, s16 y, s32 semi) {
    s32 m;
    S_Spr_7F0 *p = (S_Spr_7F0 *)g_Game_7F0.prim;
    S_SprDef_7F0 *t = &D_800AF0E0_7F0[idx];
    u32 *ot = &g_Game_7F0.db[g_Game_7F0.cur].term;
    p->tag.len = 5;
    semi = semi != 0;
    m = t->tpage & 0x9FF;
    p->code = (semi << 25) | 0x65000000;
    p->xy = (y << 16) | (u16)x;
    p->mode = m | 0xE1000200;
    p->wh = (t->h << 16) | t->w;
    p->uvc = (t->v << 8) | t->u | (t->clut << 16);
    *(u32 *)&p->tag = (*(u32 *)&p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    g_Game_7F0.prim = (u8 *)(p + 1);
}

/* Places the HUD status icons (via Hud_DrawStatusIcon(icon, x, y, flag)) along the bottom-left,
 * shifted by g_HudState+4 when its flag 8 is set. Icon 1 flashes to 2 every 4 frames while the
 * Monkey Radar (gadget 2) is active; icon 4 and the 0 marker move when camera mode
 * (g_CameraState+0x46 or +0x32) is 1; icon 3 blinks while the g_CameraState+0x2F counter runs down;
 * the last icon is 6 if Radar_LiveCamAllowed() says so, 7 with the Slingback (gadget 3), else 5. */
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
    if (Radar_LiveCamAllowed() != 0) {
        icon = 6;
    } else if (g_CurrentGadget == 3) {
        icon = 7;
    }
    Hud_DrawStatusIcon(icon, 0x2D, y + 0x12, flag ^ 1);
    Hud_DrawStatusIcon(0, x - 2, y + 0xE, 1);
}

void Camera_SetProjection(u16 arg0)
{
  u16 new_var2;
  u16 new_var;
  struct S_D_800E68D0 *p = &g_CameraState;
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
/* Makes camera setting idx (entry of g_CameraSlots) current: index +4, type +6 (entry +0), pointer +8. */
void Camera_SetSetting(s32 idx) {
    ((struct Cam_SetSetting *)&g_CameraState)->f_4 = idx;
    ((struct Cam_SetSetting *)&g_CameraState)->f_6 = ((Set_SetSetting *)g_CameraSlots)[idx].f_0;
    ((struct Cam_SetSetting *)&g_CameraState)->f_8 = &((Set_SetSetting *)g_CameraSlots)[idx];
}

/* Chooses which camera setting (entry of the 0xB0-byte table g_CameraSlots) to use. Candidates in
 * g_CameraState: +0x18 normal (mode 1), +0x1B zone (mode 4, or 5 when the entry's +0x8E is 1),
 * +0x1A when +0x38 is set (mode 3), +0x19 when +0x32/+0x46 is set (mode 2, unless
 * Camera_StageHookActive), +0x1B forced by +0x41. On a change it picks the transition kind +0x2E
 * (2 to/from +0x19, 3 for mode 3 or a +0x33 entry, 1 leaving mode 4/5; a mode-5 zone is only
 * entered when Spike is on the side its +0x94/+0x98 direction faces), saves the current view
 * (g_Game+0x8258) at +0x1C and sets the new setting. */
void Camera_SelectSetting(void) {
    struct { s16 x, y, z; } v;
    s32 idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_18;
    s32 mode = 1;
    s32 kind;
    A_80046DE8_80046DE8 *cur;
    A_80046DE8_80046DE8 *nw;
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_1B != 0xFF) {
        mode = 4;
        idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_1B;
        if ((*(A_80046DE8_80046DE8 * *)&g_CameraSlots)[idx].f_8E == 1) {
            mode = 5;
        }
    }
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_42 != 0) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_18;
        mode = 1;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_38 == 1) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_1A;
        mode = 3;
    }
    if ((((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_32 == 1 || ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_46 == 1) && !Camera_StageHookActive()) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_19;
        mode = 2;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_41 != 0) {
        idx = ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_1B;
        mode = 4;
    }
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->cur == idx) {
        return;
    }
    kind = 0;
    if (((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->cur == ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_19 || idx == ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_19) {
        kind = 2;
    } else if (mode == 3 || ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->mode == 3) {
        kind = 3;
    } else if (mode == 5) {
        cur = &(*(A_80046DE8_80046DE8 * *)&g_CameraSlots)[((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->cur];
        nw = &(*(A_80046DE8_80046DE8 * *)&g_CameraSlots)[idx];
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
    } else if (mode == 1 && (u8)(((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->mode - 4) < 2) {
        kind = 1;
        Camera_ResetToStart();
    }
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_30 = 0x80;
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->kind = kind;
    if (mode == 4 && ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_41 != 0) {
        ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_30 = 0;
    }
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_1C = ((struct Game_80046DE8 *)&g_Game)->f_8258;
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->f_24 = ((struct Game_80046DE8 *)&g_Game)->f_8260;
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->cur = idx;
    ((struct S_D_800E68D0_80046DE8 *)&g_CameraState)->mode = mode;
    Camera_SetSetting(idx);
}

void Camera_GetEye(void *arg0) {
    M2C_FIELD(arg0, SVECTOR *, 0) = g_Game.f_8258;
}

void CameraSlot_Init(S_47104_80047104 *p, s32 type) {
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
        Camera_InitFollow(p);
        break;
    case 4:
    case 5:
        CamPoint_Init(p);
        break;
    }
}

typedef struct { u8 unk0; u8 pad1; u8 unk2; u8 pad3[7]; SVECTOR unkA; u8 pad12[0x81]; u8 unk93; u8 pad94[0x1C]; } S_B4D40_800471E4;
typedef struct { u8 pad0[2]; u16 unk2; } C_800471E4;
extern C_800471E4 D_800E68D0_471E4 asm("g_CameraState");
extern S_B4D40_800471E4 *D_800B4D40_471E4 asm("g_CameraSlots");
void func_80047104_471E4(S_B4D40_800471E4 *, s32) asm("CameraSlot_Init");

/* Claim the first free one of the 12 camera slots for camera `type` looking from `pos`; returns its index (0 if none). */
s32 CameraSlot_Alloc(s32 type, SVECTOR *pos) {
    C_800471E4 *cnt;
    S_B4D40_800471E4 *p;
    s32 i;
    i = 0;
    cnt = &D_800E68D0_471E4;
    p = D_800B4D40_471E4;
    for (; i < 12; i++) {
        if (p->unk0 == 0) {
            __asm__("" : "=r"(p) : "0"(p));
            p->unk0 = type;
            p->unkA = *pos;
            p->unk2 = i;
            p->unk93 = 0xFF;
            func_80047104_471E4(p, type);
            cnt->unk2++;
            return i;
        }
        p++;
    }
    return 0;
}

void CameraSlot_Free(s32 i) {
    S_B4D40_80047290 *p = &g_CameraSlots[i];
    if (((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_41 != 0) {
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_41 = 0;
    }
    if (p->f_93 != 0xFF) {
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_4C[p->f_93].f_2 &= 0xFFF0;
    }
    ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_2--;
    if (p->f_0 >= 4 && p->f_0 < 6 && ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_1B == i) {
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_1B = 0xFF;
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_C = 0;
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_D = 0xFF;
    }
    if (((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_4 == i) {
        ((struct S_D_800E68D0_80047290 *)&g_CameraState)->f_E = i;
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


void Camera_EaseEye(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *scratch = (u8 *)0x1F800000;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xA) * (arg1 - 1)) + *(s16 *)(scratch + 0x0000)) / arg1);
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xC) * (arg2 - 1)) + (s16) *(s16 *)(scratch + 0x0002)) / arg2);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0xE) * (arg3 - 1)) + (s16) *(s16 *)(scratch + 0x0004)) / arg3);
}

void Camera_EaseLookAt(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *scratch = (u8 *)0x1F800000;
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x12) * (arg1 - 1)) + (s16) *(u16 *)(scratch + 0x0008)) / arg1);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x14) * (arg2 - 1)) + (s16) *(u16 *)(scratch + 0x000A)) / arg2);
    M2C_FIELD(arg0, s16 *, 0x16) = (s16) ((s32) ((M2C_FIELD(arg0, s16 *, 0x16) * (arg3 - 1)) + (s16) *(u16 *)(scratch + 0x000C)) / arg3);
}

void Camera_Recenter(void *arg0) {
    func_80047360();
    M2C_FIELD(arg0, s8 *, 0x32) = 0x18;
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
}

/* Moves the camera position and its target by (dx, dy, dz), unless the camera is locked. */
void Camera_Translate(s32 dx, s32 dy, s32 dz) {
    S_47690_80047690 *p = g_CameraState.f_8;
    if (g_CameraState.f_38 == 1) {
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

void Camera_AddOffset(s32 arg0, s32 arg1, s32 arg2) {
    g_CameraState.f_10 = (u16) (g_CameraState.f_10 + arg0);
    g_CameraState.f_12 = (u16) (g_CameraState.f_12 + arg1);
    g_CameraState.f_14 = (u16) (g_CameraState.f_14 + arg2);
}

/* Level camera init: clears the camera state, binds the level's "CAM" camera file (falls back to a built-in default), matches each camera area's 32-byte name to the name table ("CameraName Error" if missing), allocates the 12 camera slots and picks the start settings around Spike. */
typedef struct { s16 f_0; u16 f_2; SVECTOR f_4; u8 padC[4]; u32 key[8]; } Area_47754;
typedef struct { u16 id; u8 pad2[6]; u32 name[8]; } Name_47754;
typedef struct { u16 magic; u8 m; u8 pad3; u16 f_4; u16 f_6; u16 f_8; u16 f_A; u16 f_C; u16 f_E; } Hdr_47754;
typedef struct { s16 vx, vy, vz; } V3_47754;
typedef struct { u16 f_0; u16 f_2; u8 pad4[8]; u8 f_C; u8 f_D; u8 f_E; u8 padF; V3_47754 f_10; u8 pad16[2]; u8 f_18; u8 f_19; u8 f_1A; u8 f_1B; u8 pad1C[0x10]; u16 f_2C; u8 f_2E; u8 f_2F; u16 f_30; u8 f_32; u8 f_33; u8 pad34[4]; u8 f_38; u8 pad39[5]; u8 f_3E; u8 f_3F; u8 f_40; u8 f_41; u8 f_42; u8 f_43; u8 f_44; u8 pad45[7]; Area_47754 *f_4C; u8 *f_50; u16 *f_54; u8 *f_58; Name_47754 *f_5C; u8 *f_60; u8 *f_64; u16 f_68; u16 f_6A; u8 pad6C[0x10]; } Cam_47754;
extern struct { u8 pad0[0x8250]; u8 *f_8250; u8 *f_8254; SVECTOR f_8258; } g_Game_47754 asm("g_Game");
extern Cam_47754 D_800E68D0_47754 asm("g_CameraState");
extern Hdr_47754 D_800AF120;
extern char D_800A4CC0[];
extern u8 g_CameraTarget[];
extern MAT_80046670_80046670 D_800E78C0_47754 asm("g_ViewMatrix");
extern MAT_80046670_80046670 D_800EC330_47754 asm("D_800EC330");
void *Mem_Alloc(s32);
void bios_printf(const char *, ...);
void CamPoint_SetScript(s32, s32, s8, s32);
void Camera_StopShake(void);
void CamFlyby_Reset(void);

void Camera_InitStage(void) {
    s32 i;
    u8 *p;
    Hdr_47754 *hdr;
    u8 *base;
    u16 *names;
    Name_47754 *nm0;
    s32 j;
    Area_47754 *a;
    Area_47754 *a2;
    Name_47754 *nm;
    Cam_47754 *c;
    SVECTOR tmp;
    s32 r;

    for (p = (u8 *)&D_800E68D0_47754, i = 0; i < sizeof(Cam_47754); i++) {
        *p++ = 0;
    }
    {
        V3_47754 *v = &D_800E68D0_47754.f_10;
        v->vx = 0;
        v->vy = 0;
        v->vz = 0;
    }
    D_800E68D0_47754.f_0 = 0;
    D_800E68D0_47754.f_1B = 0xFF;
    D_800E68D0_47754.f_D = 0xFF;
    D_800E68D0_47754.f_43 = 0;
    D_800E68D0_47754.f_44 = 0;
    D_800E68D0_47754.f_32 = 0;
    D_800E68D0_47754.f_33 = 0;
    D_800E68D0_47754.f_3E = 0;
    D_800E68D0_47754.f_41 = 0;
    D_800E68D0_47754.f_42 = 0;
    D_800E68D0_47754.f_3F = 0;
    D_800E68D0_47754.f_40 = 0;
    D_800E68D0_47754.f_2F = 0;
    D_800E68D0_47754.f_38 = 0;
    D_800E68D0_47754.f_C = 0;
    D_800E68D0_47754.f_2C = 0x148;
    Camera_SetProjection(0x148);
    D_800E68D0_47754.f_30 = 0;
    D_800E68D0_47754.f_2E = 0;
    Camera_ExitAim();
    hdr = (Hdr_47754 *)g_Game_47754.f_8250;
    D_800E68D0_47754.f_50 = g_Game_47754.f_8254;
    D_800E68D0_47754.f_58 = g_Game_47754.f_8254 + 8;
    base = (u8 *)hdr;
    if (hdr != (Hdr_47754 *)0x80154000 && hdr->magic == 0x4143 && hdr->m == 'M') {
        *(u8 *)hdr = 'x';
    } else {
        hdr = &D_800AF120;
    }
    c = &D_800E68D0_47754;
    {
        u16 n = hdr->f_4;
        c->f_4C = (Area_47754 *)(base + 0x10);
        D_800E68D0_47754.f_0 = n;
    }
    c->f_54 = (u16 *)(base + hdr->f_E);
    c->f_5C = (Name_47754 *)(c->f_54 + 4);
    c->f_68 = hdr->f_8;
    c->f_60 = g_Game_47754.f_8250 + hdr->f_C;
    c->f_6A = hdr->f_6;
    c->f_64 = g_Game_47754.f_8250 + hdr->f_A;
    names = c->f_54;
    nm0 = c->f_5C;
    a = c->f_4C;
    for (i = 0; i < D_800E68D0_47754.f_0; i++) {
        u32 *ka = a[i].key;
        for (j = 0; j < *names; j++) {
            u32 *kb;
            nm = &nm0[j];
            kb = nm->name;
            if (ka[0] != kb[0] || ka[1] != kb[1] || ka[2] != kb[2] || ka[3] != kb[3]
                || ka[4] != kb[4] || ka[5] != kb[5] || ka[6] != kb[6] || ka[7] != kb[7]) {
                if (j == *names - 1) {
                    bios_printf(D_800A4CC0, ka);
                }
            } else {
                a[i].f_0 = j;
                a[i].f_2 = nm->id;
                break;
            }
        }
    }
    D_800E68D0_47754.f_2 = 0;
    g_CameraSlots = Mem_Alloc(0x840);
    for (i = 0; i < 12; i++) {
        g_CameraSlots[i].f_0 = 0;
    }
    tmp = g_Game_47754.f_8258;
    a2 = D_800E68D0_47754.f_4C;
    D_800E68D0_47754.f_18 = CameraSlot_Alloc(1, &tmp);
    D_800E68D0_47754.f_19 = CameraSlot_Alloc(2, &tmp);
    D_800E68D0_47754.f_1A = CameraSlot_Alloc(3, &tmp);
    for (i = 0; i < D_800E68D0_47754.f_0; i++) {
        u16 fl = a2[i].f_2;
        a2[i].f_2 = fl & 0xFFF0;
        if ((fl & 0x6000) == 0x2000) {
            r = CameraSlot_Alloc(5, &a2[i].f_4);
            { s32 lo = r & 0xF; a2[i].f_2 = (a2[i].f_2 & 0xFFF0) | lo; }
            CamPoint_SetScript(r, a2[i].f_0, (a2[i].f_2 >> 13) & 3, 1);
        }
    }
    D_800E68D0_47754.f_E = D_800E68D0_47754.f_18;
    Camera_SetSetting(D_800E68D0_47754.f_18);
    Camera_LookAt((void *)g_CameraTarget, (void *)(g_CameraTarget + 8), &D_800E78C0_47754, &D_800EC330_47754, 0);
    g_RadarLiveTarget = 0;
    Camera_StopShake();
    CamFlyby_Reset();
}

INCLUDE_RODATA("asm/nonmatchings/game/80046670_camera", D_800A4CC0);


typedef struct { s16 x, y, z, pad; s16 x2, y2, z2; } Tgt_80047BD0;
extern Tgt_80047BD0 g_CameraTarget_47BD0 asm("g_CameraTarget");
extern MAT_80046670_80046670 D_800E78C0_47BD0 asm("g_ViewMatrix");
extern MAT_80046670_80046670 D_800EC330_47BD0 asm("D_800EC330");
void Camera_ReadSpike(void);
void Camera_UpdateZoneBox(void);
void CamScript_Step(void *);
void CamPoint_Update(void *);
void Camera_UpdateMode(void *cam);
void Camera_HandleViewButtons(Cam_80048454_80048454 *cam);
void Camera_UpdateRadarLive(Cam_8004875C_8004875C *cam);
void Camera_BlendToSetting(void);
void Camera_UpdateShake(void);
void CamFlyby_StepSegments(void);
void CamFlyby_Update(void);
void Screen_DrawAfterimage(void);

void Camera_UpdateAll(void) {
    S_B4D40_80047290 *p;
    s32 i;
    s16 ox, oy, oz;
    s16 *o;

    Camera_ReadSpike();
    if (g_CameraState.f_3E == 0) {
        Camera_UpdateZoneBox();
    }
    Camera_SelectSetting();
    p = g_CameraSlots;
    ((u8 *)&g_CameraState)[0x47] = 0;
    for (i = 11; i >= 0; i--, p++) {
        if (p->f_0 == 4 || p->f_0 == 5) {
            CamScript_Step(p);
            CamPoint_Update(p);
        }
    }
    i = 11;
    p = g_CameraSlots;
    for (; i >= 0; i--, p++) {
        if (p->f_0 != 0) {
            switch (p->f_0) {
            default:
            case 1:
                Camera_UpdateMode(p);
                break;
            case 2:
                Camera_HandleViewButtons((Cam_80048454_80048454 *)p);
                break;
            case 3:
                Camera_UpdateRadarLive((Cam_8004875C_8004875C *)p);
                break;
            case 4:
            case 5:
                break;
            }
        }
    }
    Camera_BlendToSetting();
    Camera_UpdateShake();
    CamFlyby_StepSegments();
    CamFlyby_Update();
    Screen_DrawAfterimage();
    {
        Tgt_80047BD0 *t = &g_CameraTarget_47BD0;
        s16 *t2 = &g_CameraTarget_47BD0.x2;
        s16 tx;
        o = (s16 *)&g_CameraState.f_10;
        tx = t->x;
        ox = o[0];
        oy = o[1];
        oz = o[2];
        o[0] = 0;
        o[1] = 0;
        o[2] = 0;
        t->x = tx + ox;
        t->y += oy;
        t->z += oz;
        t->x2 += ox;
        t2[1] += oy;
        t2[2] += oz;
        Camera_LookAt((SV_80046670_80046670 *)t, (SV_80046670_80046670 *)t2, &D_800E78C0_47BD0, &D_800EC330_47BD0, *(s16 *)((u8 *)g_CameraState.f_8 + 0x2C));
    }
    Screen_UpdateFade();
}

INCLUDE_RODATA("asm/nonmatchings/game/80046670_camera", jtbl_800A4CD8_pad);


void Camera_ReadSpike(void)
{
  u8 *sc = (u8 *) 0x1F800000;
  Model_GetRootJointPos(((struct S_D_800EC1E0_80047DA4 *)&g_Spike), (SVECTOR *) 0x1F800010);
  *((SVECTOR *) 0x1F800040) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_60;
  *((s16 *) (sc + 0x18)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_24;
  *((s16 *) (sc + 0x1A)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_28;
  *((s16 *) (sc + 0x1C)) = (((struct S_D_800EC1E0_80047DA4 *)&g_Spike))->f_2C;
  *((s32 *) (sc + 0x68)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_30;
  *((s32 *) (sc + 0x6C)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_34;
  *((s32 *) (sc + 0x70)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_38;
  *((s32 *) (sc + 0x2C)) = ((struct S_D_800EC1E0_80047DA4 *)&g_Spike)->f_12C;
 do { } while (0);
  ((struct S_D_800E68D0_80047DA4 *)&g_CameraState)->f_6C = *((SVECTOR *) 0x1F800010);
  ((struct S_D_800E68D0_80047DA4 *)&g_CameraState)->f_74 = *((SVECTOR *) 0x1F800040);
}

void Radar_GetLiveTarget(void) {
    if ((Radar_LiveCamAllowed() == 0) || (g_GadgetState.f_1C == 0)) {
        g_RadarLiveTarget = 0;
        return;
    }
    g_RadarLiveTarget = g_GadgetState.f_18;
}

void Camera_ReadRadarTarget(void) {
    S_80047EE0_80047EE0 *m = (*(S_80047EE0_80047EE0 * *)&g_RadarLiveTarget);
    SCR_80047EE0_80047EE0 *sc = (SCR_80047EE0_80047EE0 *)0x1F800000;

    if (m != NULL) {
        ((struct S_D_800E68D0_80047EE0 *)&g_CameraState)->f_48 = 0;
        sc->f_40.vx = -m->f_60;
        sc->f_40.vy = m->f_62;
        sc->f_40.vz = -m->f_64;
        sc->f_18.vx = m->f_24;
        sc->f_18.vy = m->f_28;
        if (m->f_46 < 0) {
            sc->f_18.vy += 0x180;
            ((struct S_D_800E68D0_80047EE0 *)&g_CameraState)->f_48 = 1;
        }
        sc->f_18.vz = m->f_2C;
        sc->f_10.vx = sc->f_18.vx;
        sc->f_10.vy = sc->f_18.vy - 0x80;
        sc->f_10.vz = sc->f_18.vz;
        sc->f_68 = m->f_30;
        sc->f_6C = m->f_34;
        sc->f_70 = m->f_38;
    }
    ((struct S_D_800E68D0_80047EE0 *)&g_CameraState)->f_6C = sc->f_10;
    ((struct S_D_800E68D0_80047EE0 *)&g_CameraState)->f_74 = sc->f_40;
}

void Camera_BlendToSetting(void) {
    struct S_D_800E68D0_80047FF0 *c = ((struct S_D_800E68D0_80047FF0 *)&g_CameraState);
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
    c2 = ((struct S_D_800E68D0_80047FF0 *)&g_CameraState);
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

/* Camera update for game sub-mode g_Game+0x8150: 3 -> Camera_UpdateOrbit, 1 -> Camera_CallStageHook(1, cam);
 * otherwise the first that applies of Camera_FollowRcCar (when Camera_RcCarActive says so), the stage
 * overlay hook func_8013D000 (when Camera_StageHookActive says so), or, unless Camera_UpdateSpecial handled it
 * or D_800E6908 is 1, the normal camera Camera_UpdateFollow(cam, 0). */
void Camera_UpdateMode(void *cam) {
    u16 m = ((struct Game_800482C0 *)&g_Game)->f_8150;
    if (m == 3) {
        Camera_UpdateOrbit();
    } else if (m == 1) {
        Camera_CallStageHook(1, cam);
    } else if (Camera_RcCarActive() != 0) {
        Camera_FollowRcCar(cam);
    } else if (Camera_StageHookActive() != 0) {
        func_8013D000(cam);
    } else if (Camera_UpdateSpecial(cam) == 0 && (*(u8 *)&D_800E6908) != 1) {
        Camera_UpdateFollow(cam, 0);
    }
}

void Camera_EnterLook(void) {
    if ((g_CameraState.f_32 != 1) && (Game_IsPlaying() != 0) && (g_CameraState.f_3E == 0) && (g_CameraState.f_41 == 0)) {
        if (Stage_GetSpecialKind() != 0) {
            Camera_DenyLook();
            return;
        }
        g_CameraState.f_32 = 1U;
        Sound_PlayFixed(4);
    }
}

void Camera_ExitLook(void) {
    if (g_CameraState.f_32 == 1) {
        g_CameraState.f_32 = 0U;
    }
}

/* View buttons. In look mode (g_CameraState+0x32), L1 or L2 leaves it (sound 5). Otherwise, unless
 * a camera flyby runs: L2 in game modes 0x13/0x24 or sub-modes 2-3 is refused (Camera_DenyLook);
 * with the Slingback (gadget 3) it toggles aiming (+0x46) from standing/walking states
 * (0, 3, 5, 8-10, 0x10, 0x11, 0x13, 0x80-0x87); with other gadgets except the Monkey Radar it enters
 * look mode from states 0, 1 and 0x46. L1 leaves aiming, or recentres the camera on the current
 * setting (Camera_Recenter, sound 4) when allowed. Then runs Camera_UpdateLook. */
void Camera_HandleViewButtons(Cam_80048454_80048454 *cam) {
    A_80048454_80048454 *p;
    s32 g;
    if (D_800E6902 == 1) {
        if (g_Pad.held & g_Pad.pressed & 5) {
            Camera_ExitLook();
            cam->f_38 = cam->f_4;
            Camera_ExitRadarLive();
            Sound_PlayFixed(5);
        }
    } else if (!CamFlyby_IsActive()) {
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
            if (((struct S_D_800E68D0_80048454 *)&g_CameraState)->f_46 == 1) {
                Camera_ExitAim();
            } else if (((struct S_D_800E68D0_80048454 *)&g_CameraState)->f_32 != 1 && ((struct S_D_800E68D0_80048454 *)&g_CameraState)->f_3E == 0 && ((struct S_D_800E68D0_80048454 *)&g_CameraState)->f_41 == 0 && (*(struct Game_80048454 *)&g_Game).sub != 1 && Game_IsPlaying()) {
                p = &(*(A_80048454_80048454 * *)&g_CameraSlots)[((struct S_D_800E68D0_80048454 *)&g_CameraState)->f_18];
                if (p->f_32 < 0xF) {
                    Camera_Recenter(p);
                    p->f_81 = 0;
                    Sound_PlayFixed(4);
                }
            }
        }
    }
    Camera_UpdateLook(cam);
}

void Camera_ExitRadarLive(void) {
    g_RadarLiveTarget = 0;
    D_800E6908 = 0;
}

/* Monkey Radar LIVE camera (user: a live camera following the monkey, with its info card; separate
 * from the normal first-person look). Camera type 3. Camera mode g_CameraState+0x38 (D_800E6908): 0 normal, 1 live
 * 2 other. Newly pressing L2 (pad bit 1, confirmed by the user) while Radar_LiveCamAllowed allows it toggles: from 0,
 * when a target g_RadarLiveTarget exists, enters the live view (sound 4) and points the camera; from 1
 * leaves it (sound 5); 2 calls Camera_Nop. In the live view it updates the aim each frame and
 * drops out (Camera_ExitRadarLive) when it is no longer allowed. */
void Camera_UpdateRadarLive(Cam_8004875C_8004875C *cam) {
    u8 *scratch = (u8 *)0x1F800000;
    if ((*(u8 *)&D_800E6908) == 1) {
        if (Radar_LiveCamAllowed() == 0 || Monkey_IsRadarTrackable((*(void * *)&g_RadarLiveTarget)) == 0) {
            Camera_ExitRadarLive();
            return;
        }
    }
    if ((((struct Pad_8004875C *)&g_Pad)->pressed & ((struct Pad_8004875C *)&g_Pad)->held & 1) && Radar_LiveCamAllowed() != 0) {
        Camera_ExitLook();
        switch (CS_4875C->f_38) {
        case 0:
            Radar_GetLiveTarget();
            if ((*(void * *)&g_RadarLiveTarget) != 0) {
                CS_4875C->f_38 = 1;
                Camera_ExitAim();
                CS_4875C->f_32 = 0;
                Screen_StartFade(3, 200, -60);
                Sound_PlayFixed(4);
                Camera_ReadRadarTarget();
                Camera_PlaceBehindSpike(cam, scratch + 0x10, 0x333);
                cam->f_40 = Math_Atan2(-*(s16 *)(scratch + 0x40), -*(s16 *)(scratch + 0x44));
                cam->f_33 = 1;
                cam->f_38 = 0x460;
                cam->f_4 = 0x460;
                cam->f_32 = 0;
            }
            break;
        case 1:
            Camera_ExitRadarLive();
            Screen_StartFade(3, 200, -60);
            Sound_PlayFixed(5);
            break;
        case 2:
            Camera_Nop();
            break;
        }
    }
    if ((*(u8 *)&D_800E6908) == 1) {
        Camera_ReadRadarTarget();
        *(s32 *)(scratch + 0x2C) = (s16)Floor_GetHeight(*(s16 *)(scratch + 0x10), *(s16 *)(scratch + 0x12), *(s16 *)(scratch + 0x14));
        Camera_UpdateFollow(cam, 1);
        Radar_DrawMonkeyCard((*(void * *)&g_RadarLiveTarget));
    }
}

void Camera_DenyLook(void) {
    if ((g_CameraState.f_2F == 0) && (g_CameraState.f_41 == 0) && (Game_IsPlaying() != 0)) {
        g_CameraState.f_2F = 0xCU;
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

void Camera_PlaceBehindSpike(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) (M2C_FIELD(arg1, u16 *, 2) + M2C_FIELD(arg0, u16 *, 8));
    M2C_FIELD(arg0, u16 *, 0x16) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg1, u16 *, 0) - ((s32) (g_Spike.f_60 * arg2) >> 0xC));
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (M2C_FIELD(arg1, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6));
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) (M2C_FIELD(arg1, u16 *, 4) - ((s32) (g_Spike.f_64 * arg2) >> 0xC));
    M2C_FIELD(arg0, s32 *, 0x40) = Math_Atan2((s32) -g_Spike.f_60, (s32) -g_Spike.f_64);
}
