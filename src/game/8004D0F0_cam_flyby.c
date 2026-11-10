#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 pad[0x20]; } S_20_8004D39C;
typedef struct { s16 vx, vy, vz, pad; } SV_8004D40C_8004D40C;
typedef struct { u8 pad[0xB0]; } A_8004D40C_8004D40C;

extern struct S_D_800E68D0 { u8 pad0[0x46]; u8 f_46; u8 pad47[0x19]; S_20_8004D39C *f_60; u8 pad64[4]; u16 f_68; u16 f_6A; } g_CameraState;
extern struct S_D_800B8CC0 { u8 pad_0[0x20]; s16 f_20; u8 pad_22[0x2]; s8 f_24; u8 f_25; s8 f_26; u8 pad_27[0x2]; u8 f_29; } CamFlyby_State;
extern char D_800A4DB0[];
void bios_printf(const char *, ...);
void CamFlyby_SetupSegment();
void Timer_Stop(void);

M2C_UNK Game_SetMode(M2C_UNK, u16, u16);
extern struct S_D_800EC350 { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0x2]; u16 f_812A; } g_Game;

extern s16 D_800B8CE0;
void CamFlyby_End(void);
extern u8 *D_800E6934;
extern struct S_D_800E5320 { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad;
struct S_D_800B8CC0_8004D7A0 { u8 pad0[0x20]; s16 f_20; s16 f_22; s8 f_24; s8 f_25; u8 f_26; u8 pad27; u8 f_28; };
extern u8 D_800E68E8;
extern A_8004D40C_8004D40C *g_CameraSlots;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; u8 pad2A[2]; u16 f_2C; } g_Spike;
struct Game_8004D40C { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x154]; SV_8004D40C_8004D40C f_8258; SV_8004D40C_8004D40C f_8260; };
void memset(void *, s32, s32);
void CamFlyby_StartSegment(s32 i);
void Camera_PlaceBehindSpike(void *arg0, void *arg1, s32 arg2);
void Timer_Start(void);
void Screen_DrawFadeTile(s32);
struct S_D_800B8CC0_8004D40C { SV_8004D40C_8004D40C pos; SV_8004D40C_8004D40C vel; SV_8004D40C_8004D40C at; SV_8004D40C_8004D40C atvel; s16 timer; s16 fade; s8 f_24; u8 pad25[3]; u8 next; u8 f_29; };

void CamFlyby_Reset(void) {
    CamFlyby_State.f_20 = 0;
    CamFlyby_State.f_24 = 0;
}

s32 CamFlyby_IsActive(void) {
    return D_800B8CE0 != 0;
}

void CamFlyby_GetState(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) CamFlyby_State.f_20;
    M2C_FIELD(arg0, s32 *, 4) = (s32) CamFlyby_State.f_26;
}

typedef struct { s16 vx, vy, vz, pad; } SV_8004D134;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } M_8004D134;
typedef struct { SV_8004D134 p0; s16 x1, y1, z1, frames; s16 r0x, r0y, r0z; u8 next; u8 pad17; SV_8004D134 r1; } Key_8004D134;
typedef struct { SV_8004D134 pos; SV_8004D134 vel; SV_8004D134 at; SV_8004D134 atvel; s16 timer; s16 fade; u8 pad24[4]; u8 next; } Fly_8004D134;
extern Fly_8004D134 D_800B8CC0_4D134 asm("CamFlyby_State");
void RotMatrixZYX_4D134(SV_8004D134 *, M_8004D134 *) asm("RotMatrixZYX");
#define setVector_4D134(v, _x, _y, _z) (v)->vx = _x, (v)->vy = _y, (v)->vz = _z

/* Start flyby segment k: eye moves from p0 to (x1,y1,z1) over `frames`, the look direction turns
 * from rotation r0 to r1 (z axis of each rotation matrix); `next` chains the following segment. */
void CamFlyby_SetupSegment(Key_8004D134 *k) {
    SV_8004D134 v;
    M_8004D134 m;
    s32 n;
    n = k->frames;
    if (n == 0) {
        n = 1;
    }
    D_800B8CC0_4D134.timer = n + 1;
    D_800B8CC0_4D134.pos = k->p0;
    setVector_4D134(&D_800B8CC0_4D134.vel, (k->x1 - D_800B8CC0_4D134.pos.vx) / n, (k->y1 - D_800B8CC0_4D134.pos.vy) / n, (k->z1 - D_800B8CC0_4D134.pos.vz) / n);
    RotMatrixZYX_4D134((SV_8004D134 *)&k->r0x, &m);
    setVector_4D134(&D_800B8CC0_4D134.at, m.m[0][2], m.m[1][2], m.m[2][2]);
    RotMatrixZYX_4D134(&k->r1, &m);
    v.vx = m.m[0][2];
    v.vy = m.m[1][2];
    v.vz = m.m[2][2];
    setVector_4D134(&D_800B8CC0_4D134.atvel, (v.vx - D_800B8CC0_4D134.at.vx) / n, (v.vy - D_800B8CC0_4D134.at.vy) / n, (v.vz - D_800B8CC0_4D134.at.vz) / n);
    D_800B8CC0_4D134.next = k->next;
    D_800B8CC0_4D134.fade = 4;
}

void CamFlyby_StartSegment(s32 i) {
    if (i >= g_CameraState.f_68) {
        bios_printf(D_800A4DB0);
        return;
    }
    g_CameraState.f_46 = 0;
    CamFlyby_SetupSegment(&g_CameraState.f_60[i]);
    CamFlyby_State.f_29 = 0;
    CamFlyby_State.f_26 = i;
    Timer_Stop();
}

INCLUDE_RODATA("asm/nonmatchings/game/8004D0F0_cam_flyby", D_800A4DB0);


/* Scripted camera path (state CamFlyby_State: eye +0, eye step +8, target offset +0x10, its step
 * +0x18, frames left +0x20, fade +0x22). Each frame writes eye and eye+offset to the game camera
 * (g_Game+0x8258/+0x8260) and steps both. When the segment ends it chains to segment +0x28-1,
 * or hands back to the normal camera (setting g_CameraState+0x18, Camera_PlaceBehindSpike around Spike).
 * In the last 4 frames, or while +0x22 counts down, it fades via Screen_DrawFadeTile. */
void CamFlyby_Update(void) {
    SV_8004D40C_8004D40C at;
    SV_8004D40C_8004D40C w;
    SV_8004D40C_8004D40C v;
    s32 a;
    memset(&v, 0, 8);
    v.vx = g_Spike.f_24;
    v.vy = g_Spike.f_28;
    v.vz = g_Spike.f_2C;
    w = v;
    if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->timer == 0) {
        return;
    }
    if (--((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->timer == 0) {
        if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->f_29 == 0) {
            if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->next != 0) {
                CamFlyby_StartSegment(((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->next - 1);
                ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->fade = 0;
            } else {
                (*(struct Game_8004D40C *)&g_Game).f_8100 = 0;
                Camera_PlaceBehindSpike(&g_CameraSlots[D_800E68E8], &w, 0x333);
                Timer_Start();
                return;
            }
        } else if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->f_24 == 0) {
            (*(struct Game_8004D40C *)&g_Game).f_8100 = 0;
            Camera_PlaceBehindSpike(&g_CameraSlots[D_800E68E8], &w, 0x333);
            return;
        }
    }
    if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->next == 0) {
        if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->timer < 5 || ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->fade != 0) {
            if (((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->fade != 0) {
                a = ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->fade * 31;
                ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->fade--;
            } else {
                a = (4 - ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->timer) * 31;
            }
            Screen_DrawFadeTile(a);
        }
    }
    at.vx = ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vx + ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->at.vx;
    at.vy = ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vy + ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->at.vy;
    at.vz = ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vz + ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->at.vz;
    (*(struct Game_8004D40C *)&g_Game).f_8258 = ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos;
    (*(struct Game_8004D40C *)&g_Game).f_8260 = at;
    {
        SV_8004D40C_8004D40C *d = &((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->vel;
        SV_8004D40C_8004D40C *a = &((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->at;
        SV_8004D40C_8004D40C *e = &((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->atvel;
        ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vx += d->vx;
        ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vy += d->vy;
        ((struct S_D_800B8CC0_8004D40C *)&CamFlyby_State)->pos.vz += d->vz;
        a->vx += e->vx;
        a->vy += e->vy;
        a->vz += e->vz;
    }
}

void CamFlyby_End(void) {
    CamFlyby_State.f_24 = 0;
    CamFlyby_State.f_20 = 0;
    Game_SetMode(0x19, g_Game.f_8126, g_Game.f_812A);
}

void CamFlyby_Start(void) {
    if (g_CameraState.f_6A == 0) {
        CamFlyby_End();
        return;
    }
    CamFlyby_State.f_25 = 0;
    CamFlyby_State.f_26 = 0;
    CamFlyby_State.f_20 = 0;
    CamFlyby_State.f_29 = 1;
    CamFlyby_State.f_24 = g_CameraState.f_6A + 1;
}

void CamFlyby_StepSegments(void) {
    struct S_D_800B8CC0_8004D7A0 *p = &CamFlyby_State;
    if (p->f_24 == 0) {
        return;
    }
    if (p->f_20 == 0) {
        if (--p->f_24 == 0) {
            CamFlyby_End();
        } else {
            CamFlyby_SetupSegment(D_800E6934 + p->f_25 * 32);
            if (p->f_28 != 0) {
                p->f_22 = 0;
                p->f_28 = 0;
            }
            p->f_26 = ++p->f_25;
        }
    }
    if (g_Pad.f_158 & g_Pad.f_160 & (PAD_START | PAD_SQUARE | PAD_CROSS | PAD_CIRCLE)) {
        CamFlyby_End();
    }
}
