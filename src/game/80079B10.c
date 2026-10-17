#include "common.h"
#include "m2c_macros.h"

void func_80046990(s32 arg0);
extern struct S_D_800EC350 { u8 pad_0[0x8132]; s16 f_8132; } g_Game;
void Gfx_BeginFrame(void);
s32 ScreenWipe_DrawSpiral(void);
struct S_D_800A5ED0 { s16 x, y, w, h; };
extern struct S_D_800E3890 { s32 f_0; } D_800E3890;
struct Game_80079B10 { s32 frame; u8 pad4[0x8120]; u16 f_8124; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 f_812C; u8 pad812D[3]; u16 f_8130; s16 f_8132; };
void func_80079E78(void);
s32 Game_IsTimed(void);
void Game_SetMode(s32, s32, s32);
void func_80095600(s32, s32);
void func_80095244(s32);
void func_8005E42C(s32);
void ClearImage(void *, s32, s32, s32);
void DrawSync(s32);
void Sound_UnloadBanks(s32);
void Cd_Update(void);
void VSync(s32);
void Cd_ReadCurrentFile(void);
s32 func_800116C0(void);

/* Screen transition, state g_Game+0x8130 with timer +0x8132. 1: fade (func_80079E78) for the
 * timer, then per stage state +0x812C: 1 -> stage state 0x18 (0x19 in races / stage 0x21),
 * 0xD -> 3 and resets (func_80095600/func_80095244/func_8005E42C), else 3. 4: ring wipe
 * (ScreenWipe_DrawSpiral), then state 3. 2: fade out over 48 frames, clear VRAM, return -1. 3: fade out,
 * clear VRAM, wait for streaming and loads to finish (Cd_Update), then stage state 0xD. */
s32 ScreenWipe_Update(void) {
    struct S_D_800A5ED0 r = { 0, 0, 0x180, 0x200 };
    u8 st;
    switch ((*(struct Game_80079B10 *)&g_Game).f_8130) {
    case 1:
        st = (*(struct Game_80079B10 *)&g_Game).f_812C;
        if (st != 1 && st != 0xD && st != 2) {
            (*(struct Game_80079B10 *)&g_Game).f_8130 = 0;
            break;
        }
        func_80079E78();
        if (--(*(struct Game_80079B10 *)&g_Game).f_8132 > 0) {
            return 0;
        }
        (*(struct Game_80079B10 *)&g_Game).f_8132 = 0;
        (*(struct Game_80079B10 *)&g_Game).f_8130 = 0;
        switch ((*(struct Game_80079B10 *)&g_Game).f_812C) {
        case 1:
            if (!Game_IsTimed() && (*(struct Game_80079B10 *)&g_Game).f_8124 != 0x21) {
                Game_SetMode(0x18, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
            } else {
                Game_SetMode(0x19, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
            }
            break;
        case 0xD:
            Game_SetMode(3, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
            func_80095600(0, 0);
            func_80095244(0);
            func_8005E42C(0);
            return 0;
        default:
            Game_SetMode(3, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
            break;
        }
        break;
    case 4:
        ScreenWipe_DrawSpiral();
        if (--(*(struct Game_80079B10 *)&g_Game).f_8132 > 0) {
            return 0;
        }
        (*(struct Game_80079B10 *)&g_Game).f_8132 = 0;
        (*(struct Game_80079B10 *)&g_Game).f_8130 = 0;
        Game_SetMode(3, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
        break;
    case 2:
        func_80079E78();
        if (++(*(struct Game_80079B10 *)&g_Game).f_8132 < 0x30) {
            return 0;
        }
        (*(struct Game_80079B10 *)&g_Game).f_8130 = 0;
        (*(struct Game_80079B10 *)&g_Game).f_8132 = 0;
        ClearImage(&r, 0, 0, 0);
        DrawSync(0);
        return -1;
    case 3:
        func_80079E78();
        if (++(*(struct Game_80079B10 *)&g_Game).f_8132 < 0x30) {
            return 0;
        }
        (*(struct Game_80079B10 *)&g_Game).f_8130 = 0;
        (*(struct Game_80079B10 *)&g_Game).f_8132 = 0;
        Sound_UnloadBanks(2);
        ClearImage(&r, 0, 0, 0);
        DrawSync(0);
        while (D_800E3890.f_0 != 0) {
            (*(struct Game_80079B10 *)&g_Game).frame++;
            Cd_Update();
            VSync(2);
        }
        Cd_ReadCurrentFile();
        while (func_800116C0() >= 0) {
            Cd_Update();
            VSync(2);
        }
        Game_SetMode(0xD, (*(struct Game_80079B10 *)&g_Game).f_8126, (*(struct Game_80079B10 *)&g_Game).f_812A);
        break;
    case 0:
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80079B10", jtbl_800A5ED8_pad);


void func_80079E78(void) {
    func_80046990((g_Game.f_8132 * 0xFF) / 48);
}

typedef struct { u32 tag; u32 c0; s16 x0, y0, x1, y1, x2, y2, x3, y3; } PolyF4_79ECC;
s32 rsin(s32);
extern DrawBuf D_800F03D0_db[2] asm("D_800F03D0"); /* g_Game.db[].hud seen from the HUD OT symbol */
s32 rcos(s32);
extern u8 *D_800EC354;

/* Ring wipe (g_Game+0x8130 state 4): black POLY_F4 quads between a spiral and the screen edge,
   closing as the timer +0x8132 runs to 24. Returns 0. */
s32 ScreenWipe_DrawSpiral(void) {
    PolyF4_79ECC *p = (PolyF4_79ECC *)G_DRAW.prim;
    s32 a, b, k;
    s32 s0, c0, r0;
    s32 s1, c1, r1;

    if (g_Game.f_8132 >= 25) {
        g_Game.f_8132 = 24;
    }
    a = 0x2000 - (g_Game.f_8132 << 13) / 24;
    s0 = rsin(a);
    c0 = rcos(a) * 320 / 384;
    r0 = a * 384 / 0x2000;
    for (k = 0x80; k <= 0x1000; k += 0x80) {
        b = a - k;
        s1 = rsin(b);
        c1 = rcos(b) * 320 / 384;
        if (b < 0) {
            r1 = 0;
        } else {
            r1 = b * 384 / 0x2000;
            if (r1 > 0x100) {
                r1 = 0x100;
            }
        }
        ((u8 *)p)[3] = 5;
        p->c0 = 0;
        ((u8 *)p)[7] = 0x28;
        p->x0 = (s0 >> 4) + 0xC0;
        p->y0 = (c0 >> 4) + 0x78;
        p->x1 = (s1 >> 4) + 0xC0;
        p->y1 = (c1 >> 4) + 0x78;
        p->x2 = ((s0 * r0) >> 12) + 0xC0;
        p->y2 = ((c0 * r0) >> 12) + 0x78;
        p->x3 = ((s1 * r1) >> 12) + 0xC0;
        p->y3 = ((c1 * r1) >> 12) + 0x78;
        ADD_PRIM_R((u32 *)&D_800F03D0_db[G_DRAW.cur], p, "$4", "$3");
        p++;
        s0 = s1;
        c0 = c1;
        r0 = r1;
    }
    D_800EC354 = (u8 *)p;
    return 0;
}

void func_8007A14C(void) {
    s32 unused[2];
    Gfx_BeginFrame();
    ScreenWipe_DrawSpiral();
}
