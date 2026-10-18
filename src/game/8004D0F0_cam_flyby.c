#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 pad[0x20]; } S_20_8004D39C;
typedef struct { s16 vx, vy, vz, pad; } SV_8004D40C_8004D40C;
typedef struct { u8 pad[0xB0]; } A_8004D40C_8004D40C;

extern struct S_D_800E68D0 { u8 pad0[0x46]; u8 f_46; u8 pad47[0x19]; S_20_8004D39C *f_60; u8 pad64[4]; u16 f_68; u16 f_6A; } D_800E68D0;
extern struct S_D_800B8CC0 { u8 pad_0[0x20]; s16 f_20; u8 pad_22[0x2]; s8 f_24; u8 f_25; s8 f_26; u8 pad_27[0x2]; u8 f_29; } D_800B8CC0;
extern char D_800A4DB0[];
void bios_printf(const char *, ...);
void CamFlyby_SetupSegment(S_20_8004D39C *);
void func_8005DD28(void);

M2C_UNK Game_SetMode(M2C_UNK, u16, u16);
extern struct S_D_800EC350 { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[0x2]; u16 f_812A; } g_Game;

extern s16 D_800B8CE0;
void CamFlyby_End(void);
extern u8 *D_800E6934;
extern struct S_D_800E5320 { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad;
struct S_D_800B8CC0_8004D7A0 { u8 pad0[0x20]; s16 f_20; s16 f_22; s8 f_24; s8 f_25; u8 f_26; u8 pad27; u8 f_28; };
extern u8 D_800E68E8;
extern A_8004D40C_8004D40C *D_800B4D40;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; u8 pad2A[2]; u16 f_2C; } g_Spike;
struct Game_8004D40C { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x154]; SV_8004D40C_8004D40C f_8258; SV_8004D40C_8004D40C f_8260; };
void memset(void *, s32, s32);
void CamFlyby_StartSegment(s32 i);
void func_80048D10(void *arg0, void *arg1, s32 arg2);
void func_8005DD18(void);
void func_80046990(s32);
struct S_D_800B8CC0_8004D40C { SV_8004D40C_8004D40C pos; SV_8004D40C_8004D40C vel; SV_8004D40C_8004D40C at; SV_8004D40C_8004D40C atvel; s16 timer; s16 fade; s8 f_24; u8 pad25[3]; u8 next; u8 f_29; };

void func_8004D0F0(void) {
    D_800B8CC0.f_20 = 0;
    D_800B8CC0.f_24 = 0;
}

s32 func_8004D104(void) {
    return D_800B8CE0 != 0;
}

void func_8004D114(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) D_800B8CC0.f_20;
    M2C_FIELD(arg0, s32 *, 4) = (s32) D_800B8CC0.f_26;
}

INCLUDE_ASM("asm/nonmatchings/game/8004D0F0_cam_flyby", CamFlyby_SetupSegment);

void CamFlyby_StartSegment(s32 i) {
    if (i >= D_800E68D0.f_68) {
        bios_printf(D_800A4DB0);
        return;
    }
    D_800E68D0.f_46 = 0;
    CamFlyby_SetupSegment(&D_800E68D0.f_60[i]);
    D_800B8CC0.f_29 = 0;
    D_800B8CC0.f_26 = i;
    func_8005DD28();
}

INCLUDE_RODATA("asm/nonmatchings/game/8004D0F0_cam_flyby", D_800A4DB0);


/* Scripted camera path (state D_800B8CC0: eye +0, eye step +8, target offset +0x10, its step
 * +0x18, frames left +0x20, fade +0x22). Each frame writes eye and eye+offset to the game camera
 * (g_Game+0x8258/+0x8260) and steps both. When the segment ends it chains to segment +0x28-1,
 * or hands back to the normal camera (setting D_800E68D0+0x18, func_80048D10 around Spike).
 * In the last 4 frames, or while +0x22 counts down, it fades via func_80046990. */
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
    if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->timer == 0) {
        return;
    }
    if (--((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->timer == 0) {
        if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->f_29 == 0) {
            if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->next != 0) {
                CamFlyby_StartSegment(((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->next - 1);
                ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->fade = 0;
            } else {
                (*(struct Game_8004D40C *)&g_Game).f_8100 = 0;
                func_80048D10(&D_800B4D40[D_800E68E8], &w, 0x333);
                func_8005DD18();
                return;
            }
        } else if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->f_24 == 0) {
            (*(struct Game_8004D40C *)&g_Game).f_8100 = 0;
            func_80048D10(&D_800B4D40[D_800E68E8], &w, 0x333);
            return;
        }
    }
    if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->next == 0) {
        if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->timer < 5 || ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->fade != 0) {
            if (((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->fade != 0) {
                a = ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->fade * 31;
                ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->fade--;
            } else {
                a = (4 - ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->timer) * 31;
            }
            func_80046990(a);
        }
    }
    at.vx = ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vx + ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->at.vx;
    at.vy = ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vy + ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->at.vy;
    at.vz = ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vz + ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->at.vz;
    (*(struct Game_8004D40C *)&g_Game).f_8258 = ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos;
    (*(struct Game_8004D40C *)&g_Game).f_8260 = at;
    {
        SV_8004D40C_8004D40C *d = &((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->vel;
        SV_8004D40C_8004D40C *a = &((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->at;
        SV_8004D40C_8004D40C *e = &((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->atvel;
        ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vx += d->vx;
        ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vy += d->vy;
        ((struct S_D_800B8CC0_8004D40C *)&D_800B8CC0)->pos.vz += d->vz;
        a->vx += e->vx;
        a->vy += e->vy;
        a->vz += e->vz;
    }
}

void CamFlyby_End(void) {
    D_800B8CC0.f_24 = 0;
    D_800B8CC0.f_20 = 0;
    Game_SetMode(0x19, g_Game.f_8126, g_Game.f_812A);
}

void func_8004D73C(void) {
    if (D_800E68D0.f_6A == 0) {
        CamFlyby_End();
        return;
    }
    D_800B8CC0.f_25 = 0;
    D_800B8CC0.f_26 = 0;
    D_800B8CC0.f_20 = 0;
    D_800B8CC0.f_29 = 1;
    D_800B8CC0.f_24 = D_800E68D0.f_6A + 1;
}

void CamFlyby_StepSegments(void) {
    struct S_D_800B8CC0_8004D7A0 *p = &D_800B8CC0;
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
