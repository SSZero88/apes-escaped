#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s16 vx, vy, vz, pad; } SVEC;
typedef struct { u8 pad0[0xA4]; s16 f_A4; s16 f_A6; } S_8004B8F4_8004B8F4;
typedef struct { u16 f_0; u16 flags; u16 x; u16 y; u16 z; u16 w; u16 h; u16 d; u8 pad[0x20]; } Box_8004BD98_8004BD98;
typedef struct { s16 vx, vy, vz, pad; } V_8004BD98_8004BD98;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8004CA70;
typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[6]; SVEC_8004CA70 pos; SVEC_8004CA70 look; u8 pad1A[0x19]; u8 f_33; u8 pad34[4]; s32 f_38; u8 pad3C[4]; s32 f_40; u8 pad44[0x44]; s16 f_88; u8 pad8A[2]; s16 f_8C; u8 pad8E[2]; u8 f_90; u8 f_91; u8 pad92[2]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[2]; s16 f_9C; s16 f_9E; s16 f_A0; u8 padA2[6]; SVEC_8004CA70 f_A8; } Cam_8004CA70_8004CA70;
typedef struct { u16 f_0; u16 f_2; u8 pad4[0x2C]; } S_30_8004BD0C;

extern struct S_D_800EC350 { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[2]; u16 f_812A; } g_Game;
extern s16 Fx_SpikeChestPos[3];
void Game_SetMode(s32, s32, s32);
void Effect_SpawnAt(s32, s16 *);
void Pad_Vibrate(s32, s32, s32);

void Camera_GetEye(u8 *);
s32 CameraSlot_Alloc(s32, u8 *);
void Camera_SetSetting(s32);

extern u16 g_RandSeed;
extern s32 g_RadarLiveTarget;

extern struct S_D_800EC1E0 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; SVEC unk60; } g_Spike;

extern s32 g_CameraSlots;
M2C_UNK Camera_ExitRadarLive();
s32 Camera_StartEventCam(s32 a, s32 b, s32 c);
M2C_UNK Sound_PlayFixed(M2C_UNK);

extern struct S_D_800E68D0 { u16 f_0; u8 pad_2[0x19]; u8 f_1B; u8 pad_1C[0x14]; s16 f_30; u8 pad_32[0x6]; u8 f_38; u8 pad_39[0x5]; s8 f_3E; u8 pad_3F[0x2]; s8 f_41; u8 pad_42[0xA]; s32 f_4C; s32 f_50; s32 f_54; s32 f_58; s32 f_5C; } g_CameraState;
extern s8 g_AfterimageFrames;
extern s8 D_800AF131;
extern SVEC D_800E68C0;
void CamPoint_GetBaseDir(s32 a0, s32 mode, SVEC *out);
struct S_D_800E68D0_8004BD98 { u16 count; u8 pad[0x4A]; Box_8004BD98_8004BD98 *boxes; };
s32 rcos(s32);
s32 rsin(s32);
void VectorNormalSS(void *in, void *out);
void CamPoint_GetLookPoint(S_8004B8F4_8004B8F4 *o, s32 mode, SVEC *out);
void CamPoint_RunScript(Cam_8004CA70_8004CA70 *o, s32 mode);
struct S_D_800EC1E0_8004CA70 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };
struct S_D_800E68D0_8004BD0C { u16 f_0; u8 pad2[0x4A]; S_30_8004BD0C *f_4C; };

void CamPoint_GetBaseDir(s32 a0, s32 mode, SVEC *out) {
    switch (mode) {
    case 0:
        *out = g_Spike.unk60;
        break;
    case 1:
        out->vx = 0;
        out->vy = 0;
        out->vz = 0;
        break;
    case 2:
        out->vx = 0;
        out->vy = 0;
        out->vz = 0;
        break;
    }
}

void CamPoint_GetLookPoint(S_8004B8F4_8004B8F4 *o, s32 mode, SVEC *out) {
    SVEC d;

    switch (mode) {
    case 0:
        out->vx = g_Spike.f_24;
        out->vy = g_Spike.f_28 - 0x80;
        out->vz = g_Spike.f_2C;
        CamPoint_GetBaseDir((s32)o, 0, &d);
        out->vx += (d.vx * o->f_A4) >> 12;
        out->vz += (d.vz * o->f_A4) >> 12;
        out->vy += o->f_A6;
        break;
    case 1:
        break;
    case 2:
        *out = D_800E68C0;
        break;
    }
}

void CamScript_Event(s32 a) {
    switch (a) {
    case 1:
        break;
    case 2:
        Game_SetMode(0x13, g_Game.f_8126, g_Game.f_812A);
        Camera_StartEventCam(1, 0, 0);
        g_CameraState.f_41 = 1;
        g_CameraState.f_30 = 0;
        break;
    case 3:
        Effect_SpawnAt(0x119, Fx_SpikeChestPos);
        Pad_Vibrate(1, 0xB4, 9);
        break;
    case 4:
        D_800AF131 = 1;
        break;
    case 5:
        D_800AF131 = 0;
        break;
    }
}



void CamPoint_SetScript(s32 arg0, s32 arg1, s8 arg2, s32 arg3) {
    s32 var_v0;
    void *temp_t0;

    temp_t0 = g_CameraSlots + (arg0 * 0xB0);
    M2C_FIELD(temp_t0, s8 *, 0x8E) = arg2;
    M2C_FIELD(temp_t0, s16 *, 0x8A) = 0;
    M2C_FIELD(temp_t0, s16 *, 0x88) = 0;
    if (arg3 == 0) {
        var_v0 = g_CameraState.f_50 + M2C_FIELD(((arg1 * 0x28) + g_CameraState.f_58), u16 *, 2);
    } else {
        var_v0 = g_CameraState.f_54 + M2C_FIELD(((arg1 * 0x28) + g_CameraState.f_5C), u16 *, 2);
    }
    M2C_FIELD(temp_t0, s32 *, 0x84) = var_v0;
}

s32 Camera_StartEventCam(s32 a, s32 b, s32 c) {
    u8 buf[8];
    s32 r;
    Camera_GetEye(buf);
    r = CameraSlot_Alloc(4, buf);
    CamPoint_SetScript(r, a, 0, c);
    if (b == 0) {
        Camera_SetSetting(r);
        g_CameraState.f_1B = r;
    }
    return r;
}

void Camera_StartEventCam4(void) {
    Camera_StartEventCam(4, 0, 0);
    g_CameraState.f_41 = 1;
    g_CameraState.f_30 = 0;
    Camera_ExitRadarLive();
    g_CameraState.f_3E = 1;
    g_AfterimageFrames = 0x18;
    Sound_PlayFixed(9);
    Sound_PlayFixed(0xA);
}

void Camera_StartEventCam1(void) {
    Camera_StartEventCam(1, 0, 0);
    g_CameraState.f_41 = 1;
    g_CameraState.f_30 = 0;
    Camera_ExitRadarLive();
}

void Camera_StartRandomEventCam(void) {
    u16 r;
    Sound_PlayFixed(0x52);
    r = g_RandSeed * 5 + 1;
    g_RandSeed = r;
    Camera_StartEventCam(((r >> 8) & 1) | 2, 0, 0);
    g_CameraState.f_41 = 1;
    g_CameraState.f_30 = 0;
    g_CameraState.f_38 = 0;
    g_RadarLiveTarget = 0;
}

void Camera_DisableAllZoneBoxes(void) {
    s32 i;
    S_30_8004BD0C *p = ((struct S_D_800E68D0_8004BD0C *)&g_CameraState)->f_4C;
    for (i = 0; i < ((struct S_D_800E68D0_8004BD0C *)&g_CameraState)->f_0; i++, p++) {
        p->f_2 |= 0x6000;
    }
}

void Camera_DisableZoneBox(s32 arg0) {
    void *temp_v0;

    if ((s32) g_CameraState.f_0 >= arg0) {
        temp_v0 = (arg0 * 0x30) + g_CameraState.f_4C;
        M2C_FIELD(temp_v0, u16 *, 2) = (u16) (M2C_FIELD(temp_v0, u16 *, 2) | 0x6000);
    }
}

/* Returns the index of the first box in g_CameraState's list (0x30-byte records: centre at +4,
 * size at +0xA) that contains point `p`, skipping boxes disabled by their flags; -1 if none. */
s32 Zone_FindBoxContaining(V_8004BD98_8004BD98 *p)
{
  V_8004BD98_8004BD98 c[4];
  Box_8004BD98_8004BD98 *b = ((struct S_D_800E68D0_8004BD98 *)&g_CameraState)->boxes;
  s32 i;
  if (((struct S_D_800E68D0_8004BD98 *)&g_CameraState)->count == 0)
  {
    return -1;
  }
  for (i = 0; i < ((struct S_D_800E68D0_8004BD98 *)&g_CameraState)->count; i++)
  {
    u16 f = b[i].flags;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    s16 z0;
    s16 z1;
    s16 hw;
    s16 hh;
    s16 hd;
    s16 x;
    s16 y;
    s16 z;
    if ((f & 0x6000) == 0x6000)
    {
      continue;
    }
    if ((f & 0x8300) == 0x8100)
    {
      continue;
    }
    x = b[i].x;
    y = b[i].y;
    z = b[i].z;
    hw = ((s16) b[i].w) / 2;
    hh = ((s16) b[i].h) / 2;
    hd = ((s16) b[i].d) / 2;
    x0 = x - hw;
    x1 = x + hw;
    y0 = y - hh;
    y1 = y + hh;
    z0 = z - hd;
    z1 = z + hd;
    c[0].vx = x0;
    c[2].vx = x0;
    c[3].vx = x0;
    c[0].vy = y0;
    c[0].vz = z0;
    c[1].vy = y0;
    c[1].vz = z0;
    c[2].vy = y0;
    c[1].vx = x1;
    c[2].vz = z1;
    c[3].vy = y1;
    c[3].vz = z0;
    if ((((((c[0].vx < p->vx) && (p->vx < c[1].vx)) && (c[0].vz < p->vz)) && (p->vz < c[2].vz)) && (c[0].vy < p->vy)) && (p->vy < c[3].vy))
    {
      return i;
    }
  }

  return -1;
}

typedef struct { s16 vx, vy, vz, pad; } SV_8004BF20;
typedef struct { s16 f_0; u16 f_2; s16 f_4, f_6, f_8, f_A, f_C, f_E; u8 pad10[0x20]; } Box_8004BF20;
typedef struct { u8 pad0[0xC]; u8 f_C; u8 f_D; u8 padE[0xD]; u8 f_1B; u8 pad1C[0x23]; u8 f_3F; u8 f_40; u8 pad41; u8 f_42; u8 pad43[9]; Box_8004BF20 *f_4C; } C_8004BF20;
typedef struct { s16 x, y, z, pad; s16 f_8, f_A, f_C; } P_8004BF20;
typedef struct { u8 pad0[0xA]; SV_8004BF20 f_A; SV_8004BF20 f_12; u8 pad1A[0x6E]; u16 f_88; u16 f_8A; u8 pad8C[7]; u8 f_93; u8 pad94[0x1C]; } Set_8004BF20;
typedef struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } Spk_8004BF20;
typedef struct { u8 pad0[0x8258]; SV_8004BF20 f_8258; SV_8004BF20 f_8260; } Game_8004BF20;
extern C_8004BF20 D_800E68D0_BF20 asm("g_CameraState");
extern u8 D_800E68DD;
extern P_8004BF20 D_800E68C0_BF20 asm("D_800E68C0");
extern Set_8004BF20 *D_800B4D40_BF20 asm("g_CameraSlots");
extern Spk_8004BF20 g_Spike_BF20 asm("g_Spike");
extern Game_8004BF20 g_Game_BF20 asm("g_Game");
void memset(void *, s32, s32);
s32 Zone_FindBoxContaining_BF20(SV_8004BF20 *) asm("Zone_FindBoxContaining");
void CameraSlot_Free(s32);
void Camera_SelectSetting(void);

void Camera_UpdateZoneBox(void) {
    SV_8004BF20 q;
    SV_8004BF20 p;
    s32 b;
    s32 k;
    s32 i;
    s32 c;
    u16 f;
    C_8004BF20 *d;
    Box_8004BF20 *boxes;
    Box_8004BF20 *bx;
    Set_8004BF20 *s;
    memset(&p, 0, 8);
    p.vx = g_Spike_BF20.x;
    p.vy = g_Spike_BF20.y - 0x80;
    p.vz = g_Spike_BF20.z;
    d = &D_800E68D0_BF20;
    q = p;
    boxes = d->f_4C;
    if (d->f_C != 0) {
        d->f_C--;
    }
    b = Zone_FindBoxContaining_BF20(&q);
    if (b == -1) {
        b = 0xFF;
    }
    if (b == d->f_D) {
        return;
    }
    if (d->f_C == 0) {
        d->f_C = 1;
    }
    if (d->f_C != 1) {
        return;
    }
    d->f_C = 0;
    if (b == 0xFF) {
        if (d->f_D != 0xFF) {
            i = d->f_D;
            bx = &boxes[i];
            f = bx->f_2;
            c = f & 0xF;
            if (c && ((f & 0x6000) == 0 || (f & 0x6000) == 0x6000)) {
                CameraSlot_Free(c);
            }
            D_800E68D0_BF20.f_1B = 0xFF;
            D_800E68D0_BF20.f_3F = 0;
            D_800E68D0_BF20.f_40 = 0;
            D_800E68D0_BF20.f_42 = 0;
            Camera_SelectSetting();
        }
    } else {
        if (d->f_D != 0xFF) {
            i = d->f_D;
            bx = &boxes[i];
            f = bx->f_2;
            c = f & 0xF;
            if (c && !(f & 0x6000)) {
                CameraSlot_Free(c);
            }
        }
        D_800E68D0_BF20.f_3F = 0;
        D_800E68D0_BF20.f_40 = 0;
        D_800E68D0_BF20.f_42 = 0;
        D_800E68D0_BF20.f_1B = 0xFF;
        if (b >= 0) {
            D_800E68C0_BF20.x = boxes[b].f_4;
            D_800E68C0_BF20.y = boxes[b].f_6;
            D_800E68C0_BF20.z = boxes[b].f_8;
            D_800E68C0_BF20.f_8 = boxes[b].f_A / 2;
            D_800E68C0_BF20.f_A = boxes[b].f_C / 2;
            D_800E68C0_BF20.f_C = boxes[b].f_E / 2;
        }
        if (!(boxes[b].f_2 & 0x8000)) {
            boxes[b].f_2 |= 0x8000;
        }
        k = boxes[b].f_2 & 0xF;
        if (k != 0) {
            D_800E68D0_BF20.f_1B = k;
            s = &D_800B4D40_BF20[D_800E68D0_BF20.f_1B];
            s->f_88 = s->f_8A;
            if (!(boxes[b].f_2 & 0x6000)) {
                s->f_A = g_Game_BF20.f_8258;
                s->f_12 = g_Game_BF20.f_8260;
            }
        } else {
            s32 r;
            if ((boxes[b].f_2 & 0x6000) == 0x4000) {
                r = Camera_StartEventCam(boxes[b].f_0, 1, 1);
            } else {
                r = Camera_StartEventCam(boxes[b].f_0, 0, 1);
            }
            boxes[b].f_2 = (boxes[b].f_2 & 0xFFF0) | (r & 0xF);
            D_800B4D40_BF20[r].f_93 = b;
        }
    }
    D_800E68DD = b;
}

void CamPoint_Init(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x90) = 0;
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    M2C_FIELD(arg0, s8 *, 0x92) = 0;
    M2C_FIELD(arg0, s8 *, 3) = 0;
    M2C_FIELD(arg0, s8 *, 0x33) = 0;
    g_AfterimageFrames = 0;
    M2C_FIELD(arg0, s16 *, 0x8A) = 0;
    M2C_FIELD(arg0, s16 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    D_800AF131 = 0;
}

typedef struct { u8 pad0[2]; u8 f_2; u8 f_3; u8 pad4[6]; s16 x; s16 y; s16 z; u8 pad10[2]; SVEC tgt; u8 pad1A[0x1E]; s32 f_38; u8 pad3C[4]; s32 f_40; u8 pad44[0x40]; u16 *script; s16 f_88; s16 f_8A; s16 f_8C; u8 pad8E[2]; u8 f_90; u8 f_91; u8 f_92; u8 pad93; SVEC f_94; s16 f_9C; s16 f_9E; s16 f_A0; u8 padA2[2]; s16 f_A4; s16 f_A6; SVEC f_A8; } Cam_4C318;
typedef struct { u8 pad0[0x34]; s16 f_34; s16 f_36; u8 pad38[7]; u8 f_3F; u8 f_40; } S_E68D0_4C318;
typedef struct { u8 pad0[0x258]; s16 f_258; u8 pad25A[2]; s16 f_25C; } S_F4350_4C318;
extern S_E68D0_4C318 D_800E68D0_4C318 asm("g_CameraState");
extern S_F4350_4C318 D_800F4350_4C318 asm("D_800F4350");
extern SVEC g_CameraTarget_4C318 asm("g_CameraTarget");
void func_8004B880_4C318(Cam_4C318 *a0, s32 mode, SVEC *out) asm("CamPoint_GetBaseDir");
void func_8004B8F4_4C318(Cam_4C318 *o, s32 mode, SVEC *out) asm("CamPoint_GetLookPoint");
s32 Math_Atan2(s32, s32);
void Camera_ResetToStart(void);
void bios_printf(char *, ...);

void CamScript_Step(Cam_4C318 *c) {
    SVEC a;
    SVEC d;
    SVEC b;
    SVEC e;
    SVEC f;
    SVEC g;
    u16 *p;
    s32 done;
    u16 op;
    s32 t;
    s32 k;
    s32 t2;
    SVEC *sp;
    u16 n;
    s32 r;
    s32 r2;
    s32 ang;
    u16 v;

    done = 0;
    sp = (SVEC *)0x1F800000;
    if (c->script == 0 || c->f_88 != 0) {
        return;
    }
    p = c->script;
    do {
        op = *p++;
        k = (s16)op;
        switch (k) {
        default:
            bios_printf("camera script error!! ..(%d)\n", k);
            done = 1;
            break;
        case 1:
            done = 1;
            p = (u16 *)((u8 *)p + *(s16 *)p);
            break;
        case 10:
            c->f_91 = 0;
            goto clear;
        case 11:
            c->f_91 = 1;
            goto clear;
        case 12:
            c->f_91 = 2;
        clear:
            c->f_A6 = 0;
            c->f_A4 = 0;
            break;
        case 13:
            c->f_A4 = *p++;
            c->f_A6 = *p++;
            break;
        case 14:
            c->f_92 = 0;
            break;
        case 15:
            c->f_92 = 1;
            break;
        case 22:
            ang = *(s16 *)p;
            p++;
            c->script = p;
            CamScript_Event(ang);
            p = c->script;
            break;
        case 3:
            t2 = *p++;
            D_800E68D0_4C318.f_3F = 1;
            D_800E68D0_4C318.f_34 = t2;
            break;
        case 4:
            t2 = *p++;
            D_800E68D0_4C318.f_40 = 1;
            D_800E68D0_4C318.f_36 = t2;
            break;
        case 21:
            sp->vx += *p++;
            sp->vy += *p++;
            sp->vz += *p++;
            break;
        case 26:
            ang = *(s16 *)p;
            func_8004B8F4_4C318(c, c->f_91, &a);
            d.vy = 0;
            d.vx = D_800F4350_4C318.f_258 - a.vx;
            d.vz = D_800F4350_4C318.f_25C - a.vz;
            VectorNormalSS(&d, &d);
            p++;
            t2 = Math_Atan2(d.vx, d.vz);
            if (c->f_91 == 0) {
                c->f_40 = t2;
                c->f_38 = ang;
            }
            c->x = a.vx + ((d.vx * ang) >> 12);
            c->y = a.vy + *p;
            c->z = a.vz + ((d.vz * ang) >> 12);
            c->tgt = a;
            p++;
            break;
        case 16:
            ang = (*(s16 *)p << 12) / 360;
            p++;
            { register s32 k asm("$5") = c->f_91;
            r = *(s16 *)p;
            func_8004B8F4_4C318(c, k, &b); }
            func_8004B880_4C318(c, c->f_91, &e);
            p++;
            r2 = ang + 0x1000;
            ang = (Math_Atan2(e.vx, e.vz) + r2) % 4096;
            if (c->f_91 == 0) {
                c->f_40 = ang;
                c->f_38 = r;
            }
            c->x = b.vx + ((rcos(ang) * r) >> 12);
            c->y = b.vy + *p;
            c->z = b.vz + ((rsin(ang) * r) >> 12);
            c->tgt = b;
            p++;
            break;
        case 17:
            ang = (*(s16 *)p << 12) / 360;
            p++;
            { register s32 k asm("$5") = c->f_91;
            r = *(s16 *)p;
            func_8004B8F4_4C318(c, k, &f); }
            p++;
            if (c->f_91 == 0) {
                c->f_38 = r;
            }
            c->f_40 = ang;
            c->x = f.vx + ((rcos(ang) * r) >> 12);
            c->y = f.vy + *p;
            p++;
            c->z = f.vz + ((rsin(ang) * r) >> 12);
            func_8004B8F4_4C318(c, c->f_91, &c->tgt);
            break;
        case 5:
            func_8004B8F4_4C318(c, c->f_91, sp);
            break;
        case 2:
            done = 1;
            CameraSlot_Free(c->f_2);
            break;
        case 19:
            v = *p++;
            c->f_90 = 5;
            c->f_8A = v;
            c->f_88 = v;
            done = 1;
            c->f_8C = (*(s16 *)p << 12) / 360;
            p++;
            c->f_9C = *p++;
            c->f_9E = *p++;
            break;
        case 18:
            { register s32 k asm("$5") = c->f_91;
            v = *p;
            c->f_90 = 7;
            c->f_8A = v;
            c->f_88 = v;
            func_8004B8F4_4C318(c, k, &g); }
            p++;
            g.vx -= c->x;
            g.vy -= c->y;
            g.vz -= c->z;
            VectorNormalSS(&g, &g);
            c->f_94 = g;
            ang = *(s16 *)p;
            c->f_9C = (g.vx * ang) >> 12;
            c->f_9E = (g.vy * ang) >> 12;
            c->f_A0 = (g.vz * ang) >> 12;
            done = 1;
            p++;
            break;
        case 23:
            n = *p++;
            done = 1;
            c->f_8A = n;
            c->f_88 = n;
            c->f_3 = *(u8 *)p;
            p++;
            break;
        case 6:
            c->f_90 = 2;
            n = *p++;
            done = 1;
            c->f_8A = n;
            c->f_88 = n;
            break;
        case 7:
        case 8:
            t = *p++;
            done = 1;
            c->f_90 = 3;
            c->f_8A = t;
            c->f_88 = t;
            break;
        case 9:
            n = *p++;
            c->f_90 = 1;
            done = 1;
            c->f_8A = n;
            c->f_88 = n;
            break;
        case 20:
        case 25:
            v = *p;
            c->f_90 = 8;
            c->f_8A = v;
            c->f_88 = v;
            p++;
            if ((s16)op != 20) {
                c->f_90 = 9;
            }
            c->x = *p++;
            done = 1;
            c->y = *p++;
            c->z = *p++;
            c->f_94.vx = *p++;
            c->f_94.vy = *p++;
            c->f_94.vz = *p;
            c->f_A8 = *(SVEC *)&c->x;
            p++;
            break;
        case 24:
            g_CameraTarget_4C318.vx = *p++;
            g_CameraTarget_4C318.vy = *p++;
            g_CameraTarget_4C318.vz = *p++;
            Camera_ResetToStart();
            break;
        }
    } while (!done);
    c->script = p;
}



/* Camera point object update (pos +0xA, look +0x12). Runs while the timer +0x88 is non-zero
 * (counting down if positive); a script (+3) is handed to CamPoint_RunScript. Otherwise look comes
 * from CamPoint_GetLookPoint(+0x91) and the type +0x90 moves pos: 2 also from CamPoint_GetLookPoint, 5 orbits the
 * look point (radius +0x38 growing by +0x9C, angle +0x40 turning by +0x8C, height by +0x9E), 7
 * drifts by +0x9C/+0x9E/+0xA0, 8 follows Spike a quarter of the way from the base +0xA8 and 9
 * stays at +0xA8 (setting +0x33), both looking half-way towards Spike plus +0x94..+0x98.
 * D_800AF131 nudges pos down and look up. */
void CamPoint_Update(Cam_8004CA70_8004CA70 *o) {
    SVEC_8004CA70 look;
    SVEC_8004CA70 pos;
    s32 t;
    s16 ty;

    o->f_33 = 0;
    if (o->f_88 == 0) {
        return;
    }
    if (o->f_88 > 0) {
        o->f_88--;
    }
    if (o->f_3 != 0) {
        CamPoint_RunScript(o, o->f_3);
        return;
    }
    CamPoint_GetLookPoint(o, o->f_91, &look);
    pos = o->pos;
    switch (o->f_90) {
    case 2:
        CamPoint_GetLookPoint(o, o->f_91, &pos);
        break;
    case 7:
        pos.vx += o->f_9C;
        pos.vy += o->f_9E;
        pos.vz += o->f_A0;
        break;
    case 5:
        pos.vx = look.vx + ((rcos(o->f_40) * o->f_38) >> 12);
        pos.vz = look.vz + ((rsin(o->f_40) * o->f_38) >> 12);
        t = o->f_8C + 0x1000;
        o->f_40 = (o->f_40 + t) % 0x1000;
        pos.vy += o->f_9E;
        o->f_38 += o->f_9C;
        break;
    case 8:
        ty = pos.vy + 0x80;
        look.vx = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_24 - pos.vx;
        look.vy = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_28 - ty;
        look.vz = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_2C - pos.vz;
        VectorNormalSS(&look, &look);
        pos.vx = o->f_A8.vx + (((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_24 - o->f_A8.vx) / 4;
        pos.vz = o->f_A8.vz + (((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_2C - o->f_A8.vz) / 4;
        look.vx = pos.vx + (look.vx + o->f_94) / 2;
        look.vy = pos.vy + (look.vy + o->f_96) / 2;
        look.vz = pos.vz + (look.vz + o->f_98) / 2;
        break;
    case 9:
        ty = pos.vy + 0x80;
        look.vx = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_24 - pos.vx;
        look.vy = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_28 - ty;
        look.vz = ((struct S_D_800EC1E0_8004CA70 *)&g_Spike)->f_2C - pos.vz;
        VectorNormalSS(&look, &look);
        pos = o->f_A8;
        look.vx = pos.vx + (look.vx + o->f_94) / 2;
        look.vy = pos.vy + (look.vy + o->f_96) / 2;
        look.vz = pos.vz + (look.vz + o->f_98) / 2;
        o->f_33 = 1;
        break;
    }
    if ((*(u8 *)&D_800AF131) != 0) {
        look.vy += 3;
        pos.vy -= 6;
    }
    o->look = look;
    o->pos = pos;
}



void Screen_SetAfterimage(s8 arg0) {
    g_AfterimageFrames = arg0;
}

extern u8 g_AfterimageFrames_u asm("g_AfterimageFrames");
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_4CEB4;
typedef struct { P_TAG_4CEB4 tag; u32 code; u32 pad; } DrStp_4CEB4;
typedef struct { P_TAG_4CEB4 tag; u32 rgbc; u32 xy0; u32 uv0clut; u32 xy1; u32 uv1tp; u32 xy2; u16 uv2, pad2; u32 xy3; u16 uv3, pad3; } PolyFT4_4CEB4;

void Screen_DrawAfterimage(void) {
    u8 n;
    u8 *p;
    P_TAG_4CEB4 *ot;
    u32 y;
    u32 tp;
    u32 yb;

    n = g_AfterimageFrames_u;
    if (n == 0) {
        return;
    }
    {
    register u32 two asm("$16");
    __asm__("" : "=r"(two) : "0"(2));
    g_AfterimageFrames_u = n - 1;
    p = G_DRAW.prim;
    { s32 off = G_DRAW.cur * sizeof(DrawBuf); u8 *g = (u8 *)&G_DRAW; y = *(u16 *)(off + g + 0x12); ot = (P_TAG_4CEB4 *)(off + (u8 *)&G_DRAW + 0x80); }
    ((DrStp_4CEB4 *)p)->code = 0xE6000000;
    ((DrStp_4CEB4 *)p)->tag.len = two;
    ((DrStp_4CEB4 *)p)->pad = 0;
    ((DrStp_4CEB4 *)p)->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p += sizeof(DrStp_4CEB4);
    y ^= 0x100;
    tp = (y & 0x100) >> 4;
    ((PolyFT4_4CEB4 *)p)->tag.len = 9;
    ((PolyFT4_4CEB4 *)p)->rgbc = 0x2F000000;
    ((PolyFT4_4CEB4 *)p)->xy0 = 0xFFE0FFE0;
    ((PolyFT4_4CEB4 *)p)->xy1 = 0xFFE000C0;
    ((PolyFT4_4CEB4 *)p)->xy2 = 0x110FFE0;
    ((PolyFT4_4CEB4 *)p)->xy3 = 0x11000C0;
    ((PolyFT4_4CEB4 *)p)->uv0clut = 0;
    ((PolyFT4_4CEB4 *)p)->uv1tp = ((u16)(tp | 0x100) | ((y & 0x200) * 4)) << 16 | 0xBF;
    ((PolyFT4_4CEB4 *)p)->uv2 = 0xEF00;
    ((PolyFT4_4CEB4 *)p)->uv3 = 0xEFBF;
    ((PolyFT4_4CEB4 *)p)->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p += sizeof(PolyFT4_4CEB4);
    ((PolyFT4_4CEB4 *)p)->tag.len = 9;
    ((PolyFT4_4CEB4 *)p)->rgbc = 0x2F000000;
    ((PolyFT4_4CEB4 *)p)->xy0 = 0xFFE000C0;
    ((PolyFT4_4CEB4 *)p)->xy1 = 0xFFE001A0;
    ((PolyFT4_4CEB4 *)p)->xy2 = 0x11000C0;
    ((PolyFT4_4CEB4 *)p)->xy3 = 0x11001A0;
    ((PolyFT4_4CEB4 *)p)->uv0clut = 0;
    ((PolyFT4_4CEB4 *)p)->uv1tp = ((u16)(tp | 0x103) | ((y & 0x200) * 4)) << 16 | 0xBF;
    ((PolyFT4_4CEB4 *)p)->uv2 = 0xEF00;
    ((PolyFT4_4CEB4 *)p)->uv3 = 0xEFBF;
    ((PolyFT4_4CEB4 *)p)->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p += sizeof(PolyFT4_4CEB4);
    ((DrStp_4CEB4 *)p)->tag.len = two;
    ((DrStp_4CEB4 *)p)->code = 0xE6000001;
    ((DrStp_4CEB4 *)p)->pad = 0;
    ((DrStp_4CEB4 *)p)->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p += sizeof(DrStp_4CEB4);
    G_DRAW.prim = p;
    }
}
