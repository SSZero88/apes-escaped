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
extern s16 D_800B4D88[3];
void Game_SetMode(s32, s32, s32);
void Effect_SpawnAt(s32, s16 *);
void Pad_Vibrate(s32, s32, s32);

void func_800470CC(u8 *);
s32 func_800471E4(s32, u8 *);
void Camera_SetSetting(s32);

extern u16 g_RandSeed;
extern s32 g_RadarLiveTarget;

extern struct S_D_800EC1E0 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; SVEC unk60; } g_Spike;

extern s32 D_800B4D40;
M2C_UNK func_80048748();
s32 Camera_StartEventCam(s32 a, s32 b, s32 c);
M2C_UNK Sound_PlayFixed(M2C_UNK);

extern struct S_D_800E68D0 { u16 f_0; u8 pad_2[0x19]; u8 f_1B; u8 pad_1C[0x14]; s16 f_30; u8 pad_32[0x6]; u8 f_38; u8 pad_39[0x5]; s8 f_3E; u8 pad_3F[0x2]; s8 f_41; u8 pad_42[0xA]; s32 f_4C; s32 f_50; s32 f_54; s32 f_58; s32 f_5C; } D_800E68D0;
extern s8 g_AfterimageFrames;
extern s8 D_800AF131;
extern SVEC D_800E68C0;
void func_8004B880(s32 a0, s32 mode, SVEC *out);
struct S_D_800E68D0_8004BD98 { u16 count; u8 pad[0x4A]; Box_8004BD98_8004BD98 *boxes; };
s32 rcos(s32);
s32 rsin(s32);
void VectorNormalSS(void *in, void *out);
void func_8004B8F4(S_8004B8F4_8004B8F4 *o, s32 mode, SVEC *out);
void CamPoint_RunScript(Cam_8004CA70_8004CA70 *o, s32 mode);
struct S_D_800EC1E0_8004CA70 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };
struct S_D_800E68D0_8004BD0C { u16 f_0; u8 pad2[0x4A]; S_30_8004BD0C *f_4C; };

void func_8004B880(s32 a0, s32 mode, SVEC *out) {
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

void func_8004B8F4(S_8004B8F4_8004B8F4 *o, s32 mode, SVEC *out) {
    SVEC d;

    switch (mode) {
    case 0:
        out->vx = g_Spike.f_24;
        out->vy = g_Spike.f_28 - 0x80;
        out->vz = g_Spike.f_2C;
        func_8004B880((s32)o, 0, &d);
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
        D_800E68D0.f_41 = 1;
        D_800E68D0.f_30 = 0;
        break;
    case 3:
        Effect_SpawnAt(0x119, D_800B4D88);
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



void func_8004BAD8(s32 arg0, s32 arg1, s8 arg2, s32 arg3) {
    s32 var_v0;
    void *temp_t0;

    temp_t0 = D_800B4D40 + (arg0 * 0xB0);
    M2C_FIELD(temp_t0, s8 *, 0x8E) = arg2;
    M2C_FIELD(temp_t0, s16 *, 0x8A) = 0;
    M2C_FIELD(temp_t0, s16 *, 0x88) = 0;
    if (arg3 == 0) {
        var_v0 = D_800E68D0.f_50 + M2C_FIELD(((arg1 * 0x28) + D_800E68D0.f_58), u16 *, 2);
    } else {
        var_v0 = D_800E68D0.f_54 + M2C_FIELD(((arg1 * 0x28) + D_800E68D0.f_5C), u16 *, 2);
    }
    M2C_FIELD(temp_t0, s32 *, 0x84) = var_v0;
}

s32 Camera_StartEventCam(s32 a, s32 b, s32 c) {
    u8 buf[8];
    s32 r;
    func_800470CC(buf);
    r = func_800471E4(4, buf);
    func_8004BAD8(r, a, 0, c);
    if (b == 0) {
        Camera_SetSetting(r);
        D_800E68D0.f_1B = r;
    }
    return r;
}

void func_8004BBF0(void) {
    Camera_StartEventCam(4, 0, 0);
    D_800E68D0.f_41 = 1;
    D_800E68D0.f_30 = 0;
    func_80048748();
    D_800E68D0.f_3E = 1;
    g_AfterimageFrames = 0x18;
    Sound_PlayFixed(9);
    Sound_PlayFixed(0xA);
}

void func_8004BC5C(void) {
    Camera_StartEventCam(1, 0, 0);
    D_800E68D0.f_41 = 1;
    D_800E68D0.f_30 = 0;
    func_80048748();
}

void func_8004BC9C(void) {
    u16 r;
    Sound_PlayFixed(0x52);
    r = g_RandSeed * 5 + 1;
    g_RandSeed = r;
    Camera_StartEventCam(((r >> 8) & 1) | 2, 0, 0);
    D_800E68D0.f_41 = 1;
    D_800E68D0.f_30 = 0;
    D_800E68D0.f_38 = 0;
    g_RadarLiveTarget = 0;
}

void func_8004BD0C(void) {
    s32 i;
    S_30_8004BD0C *p = ((struct S_D_800E68D0_8004BD0C *)&D_800E68D0)->f_4C;
    for (i = 0; i < ((struct S_D_800E68D0_8004BD0C *)&D_800E68D0)->f_0; i++, p++) {
        p->f_2 |= 0x6000;
    }
}

void func_8004BD54(s32 arg0) {
    void *temp_v0;

    if ((s32) D_800E68D0.f_0 >= arg0) {
        temp_v0 = (arg0 * 0x30) + D_800E68D0.f_4C;
        M2C_FIELD(temp_v0, u16 *, 2) = (u16) (M2C_FIELD(temp_v0, u16 *, 2) | 0x6000);
    }
}

/* Returns the index of the first box in D_800E68D0's list (0x30-byte records: centre at +4,
 * size at +0xA) that contains point `p`, skipping boxes disabled by their flags; -1 if none. */
s32 Zone_FindBoxContaining(V_8004BD98_8004BD98 *p)
{
  V_8004BD98_8004BD98 c[4];
  Box_8004BD98_8004BD98 *b = ((struct S_D_800E68D0_8004BD98 *)&D_800E68D0)->boxes;
  s32 i;
  if (((struct S_D_800E68D0_8004BD98 *)&D_800E68D0)->count == 0)
  {
    return -1;
  }
  for (i = 0; i < ((struct S_D_800E68D0_8004BD98 *)&D_800E68D0)->count; i++)
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

INCLUDE_ASM("asm/nonmatchings/game/8004B880", Camera_UpdateZoneBox);

void func_8004C2E4(void *arg0) {
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

INCLUDE_ASM("asm/nonmatchings/game/8004B880", func_8004C318);

INCLUDE_RODATA("asm/nonmatchings/game/8004B880", D_800A4D04);
INCLUDE_RODATA("asm/nonmatchings/game/8004B880", jtbl_800A4D28);


/* Camera point object update (pos +0xA, look +0x12). Runs while the timer +0x88 is non-zero
 * (counting down if positive); a script (+3) is handed to CamPoint_RunScript. Otherwise look comes
 * from func_8004B8F4(+0x91) and the type +0x90 moves pos: 2 also from func_8004B8F4, 5 orbits the
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
    func_8004B8F4(o, o->f_91, &look);
    pos = o->pos;
    switch (o->f_90) {
    case 2:
        func_8004B8F4(o, o->f_91, &pos);
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



void func_8004CEA8(s8 arg0) {
    g_AfterimageFrames = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/8004B880", Screen_DrawAfterimage);
