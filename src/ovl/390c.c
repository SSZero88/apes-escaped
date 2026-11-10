#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_8013C5E0;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013C5E0;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013C5E0 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 held; } g_Pad_8013C5E0 asm("g_Pad");
void Gfx_InitDisplay(void);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void DebugFont_Init(void);
void DebugFont_Locate(s32, s32);
void DebugFont_PrintfAlways(u8 *);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
s32 Sound_PlayFixed(s32);

extern struct { u8 pad0[0x8120]; s16 f_8120; } g_Game_8013C7F0 asm("g_Game");
extern s16 D_8013AF56;
extern s32 D_8013F280;
extern s16 D_8013F284;
extern s32 D_8013F288;
void Gfx_InitDisplay(void);
s32 ResetGraph(s32);
s32 func_8013C8E8(void);
s32 func_8013F630(void);
s32 func_8013C954(void);
s32 func_8013CB30(void);

s32 func_8013C7F0(void) {
    Gfx_InitDisplay();
    ResetGraph(1);
    D_8013AF56 = 0xE;
    D_8013F280 = 0;
    D_8013F284 = 1;
    D_8013F288 = 0;
    func_8013C8E8();
    while (1) {
        switch (D_8013F280) {
        case 0:
            if (func_8013F630() < 0) {
                goto end;
            }
            break;
        case 1:
            func_8013C954();
            break;
        case 2:
            func_8013CB30();
            break;
        }
    }
end:
    g_Game_8013C7F0.f_8120 = 0x15;
    return 0;
}

extern struct S_g_Game { u8 pad_0[0x813C]; u16 f_813C; u8 pad_813E[0x16]; u16 f_8154; u16 f_8156; } g_Game;
extern struct { u8 pad0[0xA1]; u8 f_A1; u8 f_A2; } g_GadgetState;
extern struct { s16 f_0, f_2, f_4, f_6, f_8, f_A; } D_8013F5E4;
s32 Save_SumStageMonkeys(s32);

s32 func_8013C8E8(void) {
    D_8013F5E4.f_0 = Save_SumStageMonkeys(0);
    D_8013F5E4.f_2 = g_Game.f_813C;
    D_8013F5E4.f_4 = g_Game.f_8154;
    D_8013F5E4.f_6 = g_Game.f_8156;
    D_8013F5E4.f_8 = g_GadgetState.f_A1;
    D_8013F5E4.f_A = g_GadgetState.f_A2;
    return 0;
}

/* D_8013AF66 and D_8013F280 come from the externs at the top of src/ovl/390c.c */
extern s16 D_8013AF66;
typedef struct { s16 x, y, w, h; } Rect_8013C954;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013C954;
extern Rect_8013C954 D_8013EEE0;
extern u8 D_8013D688[];
extern s16 D_8013AF68;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013C954 asm("g_Game");
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 func_8013A634(void);
s32 func_8013D19C(void);
s32 func_8013D1F8(void);
void func_80141A10(u8 *);
void func_80141B00(void);
void func_80141AB4(void);
void MemCard_Request(s32, s32);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_8013C954(void) {
    Rect_8013C954 r;

    r = D_8013EEE0;
    g_Game_8013C954.db[1].env[0x18] = 1;
    g_Game_8013C954.db[0].env[0x18] = 1;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[0])->r0 = 0;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[0])->g0 = 0;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[0])->b0 = 0;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[1])->r0 = 0;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[1])->g0 = 0;
    ((DrawEnv_8013C954 *)&g_Game_8013C954.db[1])->b0 = 0;
    g_Game_8013C954.cur = 0;
    func_8013D19C();
    func_80141A10(D_8013D688);
    D_8013AF66 = 0;
    D_8013AF68 = 0x1E;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        if (func_8013D1F8() != 0) {
            D_8013AF66 = 2;
        }
        func_80141B00();
        DrawSync(0);
        VSync(0);
        g_Game_8013C954.frame++;
        PutDispEnv(&g_Game_8013C954.db[g_Game_8013C954.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013C954.db[g_Game_8013C954.cur].env);
        DrawOTag(&g_Game_8013C954.db[g_Game_8013C954.cur].ot[0xFFF]);
    }
    func_80141AB4();
    MemCard_Request(9, 0);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    D_8013F280 = 0;
    return 0;
}

/* D_8013AF66, D_8013F280 and D_8013F288 come from the externs at the top of src/ovl/390c.c */
typedef struct { s16 x, y, w, h; } Rect_8013CB30;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013CB30;
extern Rect_8013CB30 D_8013EEE0_8013CB30 asm("D_8013EEE0");
extern u8 D_8013D764[];
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_8013CB30 asm("g_Game");
s32 func_8013D218(void);
void func_80095D44(void);

s32 func_8013CB30(void) {
    Rect_8013CB30 r;

    r = D_8013EEE0_8013CB30;
    g_Game_8013CB30.db[1].env[0x18] = 1;
    g_Game_8013CB30.db[0].env[0x18] = 1;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[0])->r0 = 0;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[0])->g0 = 0;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[0])->b0 = 0;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[1])->r0 = 0;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[1])->g0 = 0;
    ((DrawEnv_8013CB30 *)&g_Game_8013CB30.db[1])->b0 = 0;
    g_Game_8013CB30.cur = 0;
    func_8013D19C();
    func_80141A10(D_8013D764);
    D_8013AF68 = 0x1E;
    D_8013AF66 = 0;
    D_8013F288 = 0;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8013A634() >= 0) {
        if (func_8013D218() != 0) {
            D_8013AF66 = 2;
        }
        func_80141B00();
        DrawSync(0);
        VSync(0);
        g_Game_8013CB30.frame++;
        PutDispEnv(&g_Game_8013CB30.db[g_Game_8013CB30.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013CB30.db[g_Game_8013CB30.cur].env);
        DrawOTag(&g_Game_8013CB30.db[g_Game_8013CB30.cur].ot[0xFFF]);
    }
    func_80141AB4();
    MemCard_Request(9, 0);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    func_80095D44();
    D_8013F280 = 0;
    return 0;
}

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390c", D_8013EEE0);

extern s16 D_8013F5E4_8013CD1C[] asm("D_8013F5E4");
extern s16 D_8013F5FC[];
extern s16 D_8013F614[];
extern s32 D_800E1990[];
extern u8 *D_800E388C;
extern s16 D_8013AF5A;
extern s16 D_8013F28C;
extern s32 D_8013F290;
extern s32 D_8013F294;
extern s32 D_8013F298;
extern s16 D_800E3884;

s32 func_8013CD1C(s32 msg, s32 arg) {
    s32 i;
    s32 *dst;
    s32 *src;
    s32 *t;

    D_8013AF56 = msg;
    switch (msg) {
    case 21:
        D_8013F298 = VSync(-1);
        break;
    case 32:
        src = D_800E1990;
        { register u8 *p asm("$3") = D_800E388C; t = (s32 *)(p + 0x110); }
        if (D_8013F288 == 0) {
            D_8013F5E4_8013CD1C[6] = 0;
            for (i = 0; i < 6; i++) {
                t[i] = src[i];
            }
            t[6] = D_8013F5E4_8013CD1C[0];
            break;
        }
        for (i = 0; i < 12; i++) {
            D_8013F614[i] = D_8013F5E4_8013CD1C[i];
        }
        if (D_8013F5E4_8013CD1C[1] + D_8013F5E4_8013CD1C[7] > 100) {
            D_8013F5FC[1] = 100 - D_8013F5E4_8013CD1C[1];
        } else {
            D_8013F5FC[1] = D_8013F5E4_8013CD1C[7];
        }
        D_8013F5FC[7] = D_8013F5FC[1];
        for (i = 2; i < 4; i++) {
            if (D_8013F5E4_8013CD1C[i] + D_8013F5E4_8013CD1C[i + 6] >= 100) {
                D_8013F5FC[i] = 99 - D_8013F5E4_8013CD1C[i];
                if (i != 1) {
                    D_8013F5FC[i + 6] = D_8013F614[i + 6];
                } else {
                    D_8013F5FC[7] = D_8013F5FC[1];
                }
            } else {
                D_8013F5FC[i + 6] = D_8013F5FC[i] = D_8013F5E4_8013CD1C[i + 6];
            }
        }
        for (i = 4; i < 6; i++) {
            if (D_8013F5E4_8013CD1C[i] + D_8013F5E4_8013CD1C[i + 6] > D_8013F5E4_8013CD1C[i - 2] + D_8013F5FC[i - 2]) {
                D_8013F5FC[i] = D_8013F5E4_8013CD1C[i - 2] + D_8013F5FC[i - 2] - D_8013F5E4_8013CD1C[i];
            } else if (D_8013F5E4_8013CD1C[i] + D_8013F5E4_8013CD1C[i + 6] >= 100) {
                D_8013F5FC[i] = 99 - D_8013F5E4_8013CD1C[i];
            } else {
                D_8013F5FC[i] = D_8013F5E4_8013CD1C[i + 6];
            }
            D_8013F5FC[i + 6] = D_8013F5FC[i];
        }
        t[0] = D_8013F614[7] - D_8013F5FC[7];
        t[1] = D_8013F614[11] - D_8013F5FC[11];
        t[2] = D_8013F614[10] - D_8013F5FC[10];
        t[3] = D_8013F614[9] - D_8013F5FC[9];
        t[4] = D_8013F614[8] - D_8013F5FC[8];
        t[5] = src[5];
        t[6] = src[6];
        break;
    case 29:
        if (arg == 0) {
            src = D_800E1990;
            D_8013F5E4_8013CD1C[6] = src[6];
            D_8013F5E4_8013CD1C[7] = src[0];
            D_8013F5E4_8013CD1C[8] = src[4];
            D_8013F5E4_8013CD1C[9] = src[3];
            D_8013F5E4_8013CD1C[10] = src[2];
            D_8013F5E4_8013CD1C[11] = src[1];
            D_8013F288 = 0;
        }
        break;
    case 34:
        D_8013F294 = 0;
        if (D_8013F288 != 0) {
            g_Game.f_813C += D_8013F5FC[1];
            g_Game.f_8154 += D_8013F5FC[2];
            g_Game.f_8156 += D_8013F5FC[3];
            g_GadgetState.f_A1 += D_8013F5FC[4];
            g_GadgetState.f_A2 += D_8013F5FC[5];
        }
        { register u8 *p asm("$3") = D_800E388C; dst = (s32 *)(p + 0x110); }
        for (i = 0; i < 7; i++) {
            D_800E1990[i] = dst[i];
        }
        break;
    case 24:
    case 31:
    case 40:
        D_8013AF5A = 1;
        break;
    case 26:
    case 37:
    case 39:
        D_8013F290 = 0;
        D_8013AF5A = 1;
        break;
    case 25:
        D_8013F28C = 0;
        break;
    case 18:
    case 30:
    case 36:
    case 38:
        D_800E3884 = 0xB;
        break;
    case 14: case 15: case 16: case 17: case 19: case 20: case 22: case 23: case 27: case 28: case 33: case 35:
    case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49:
        break;
    }
    return 0;
}

extern s16 D_8013AF56;
extern struct { s16 f_0; u8 pad2[6]; s16 f_8; u8 padA[2]; void *f_C; } g_MemCard;
void MemCard_Request(s32, s32);

s32 func_8013D19C(void) {
    D_8013AF56 = 0x13;
    MemCard_Request(8, 0);
    g_MemCard.f_C = (void *)0x80158000;
    g_MemCard.f_0 = 1;
    g_MemCard.f_8 = 0;
    MemCard_Request(10, 0);
    return 0;
}

s32 func_8013D238(void);

s32 func_8013D1F8(void) {
    return func_8013D238() != 0;
}

s32 func_8013D218(void) {
    return func_8013D238() != 0;
}

extern struct { s16 f_0; s16 f_2; s16 f_4; } D_800E3880_8013D238 asm("g_MemCard");
s32 func_8013CD1C(s32 msg, s32 arg);
void func_80139A3C(s32);
void func_80139A68(void);
void func_8013FEFC(s32);
s32 func_8014016C(void);
s32 func_80139F08(void);
s32 func_80136554(s32 x, s32 y, s32 w, s32 h);
s32 func_8013E290(void);
s32 func_8013E30C(void);
s32 func_8013A400(void);
s32 func_8013ED0C(void);
s32 func_8013D834(void);
s32 func_8013D92C(void);
s32 func_8013DA00(void);
s32 func_8013DA7C(void);
s32 func_8013DB48(void);
s32 func_8013DBF0(void);
s32 func_8013DC78(void);
s32 func_8013DDF0(void);
s32 func_8013DEB4(void);
s32 func_8013DF40(void);

s32 func_8013D238(void) {
    s32 r;
    s32 i;
    s32 n;

    switch (D_8013AF56) {
    case 19:
    case 28:
        func_8013FEFC(0);
        goto show;
    case 14:
        func_80139A3C(4);
        func_80139A68();
        return 1;
    case 29:
        func_8013E290();
        if (func_8013E30C() == 0) {
            break;
        }
        return 1;
    case 31:
    case 40:
        func_8014016C();
        r = func_80139F08();
        func_80136554(0x60, 0x50, 0xC0, 0x84);
        func_8013E290();
        if (r == 0) {
            break;
        }
        if (r == 2) {
            goto back;
        }
        func_8013CD1C(0x20, 0);
        return 0;
    case 49:
        func_8014016C();
        func_80136554(0x60, 0x50, 0xC0, 0x84);
        func_8013E290();
        if (func_8013A400() == 0) {
            return 0;
        }
        Sound_PlayFixed(3);
    back:
        func_8013CD1C(0x1D, 1);
        return 0;
    case 34:
        if (++D_8013F294 >= 0x5B) {
            func_8013CD1C(0x1D, 1);
        } else if (D_8013F288 == 0) {
            D_8013F5E4_8013CD1C[6] = D_8013F5E4_8013CD1C[0] * D_8013F294 / 90;
        } else {
            for (i = 1; i < 6; i++) {
                D_8013F5E4_8013CD1C[i] = D_8013F614[i] + D_8013F5FC[i] * D_8013F294 / 90;
            }
            for (i = 7; i < 12; i++) {
                D_8013F5E4_8013CD1C[i] = D_8013F614[i] - D_8013F5FC[i] * D_8013F294 / 90;
            }
        }
    case 32:
    case 33:
        func_8014016C();
        func_80136554(0x60, 0x50, 0xC0, 0x84);
        func_8013E290();
        return 0;
    case 18:
    case 30:
        if (D_800E3884 != 0xB) {
            func_8013FEFC(0);
        } else {
            func_8014016C();
        }
        func_80139A3C(4);
        func_80139A68();
        if (D_800E3884 == 0xB) {
            if (func_8013A400() == 0) {
                return 0;
            }
            Sound_PlayFixed(3);
            return 1;
        }
        return 0;
    case 21:
    case 48:
        func_8014016C();
        func_8013ED0C();
        goto show;
    case 20:
    case 23:
    case 36:
    case 38:
    case 41:
    case 42:
    case 46:
    case 47:
        func_8014016C();
        func_80139A3C(4);
        func_80139A68();
        if (func_8013A400() == 0) {
            return 0;
        }
        Sound_PlayFixed(3);
        return 1;
    case 24:
        func_8014016C();
        r = func_80139F08();
        func_80139A3C(4);
        func_80139A68();
        if (r == 0) {
            break;
        }
        if (r == 2) {
            return 1;
        }
        func_8013CD1C(0x19, 0);
        return 0;
    case 26:
    case 37:
    case 39:
        func_8014016C();
        r = func_80139F08();
        func_80139A3C(4);
        func_80139A68();
        if (r == 0) {
            break;
        }
        if (D_8013F290 != 0) {
            return 0;
        }
        if (r == 2) {
            return 1;
        }
        D_8013F290 = 1;
        break;
    case 25:
        func_8014016C();
    show:
        func_80139A3C(4);
        func_80139A68();
        break;
    }
    return 0;
}

void MemCard_SaveThread_8013D688(void) asm("D_8013D688");
void MemCard_SaveThread_8013D688(void) {
    while (1) {
        switch (D_8013AF56) {
        case 19:
            func_8013D834();
            if (D_800E3880_8013D238.f_4 == 0xD) {
                break;
            }
            MemCard_Request(0xB, 0);
            break;
        case 14:
        case 20:
        case 23:
        case 24:
        case 36:
            func_8013DA00();
            MemCard_Request(0xB, 0);
            break;
        case 26:
        case 37:
        case 39:
        case 48:
            func_8013DC78();
            MemCard_Request(0xB, 0);
            break;
        case 18:
            func_8013DA7C();
            if (D_800E3880_8013D238.f_4 == 0xD) {
                break;
            }
            MemCard_Request(0xB, 0);
            break;
        case 21:
            func_8013DBF0();
            break;
        case 25:
            func_8013DF40();
            break;
        }
    }
}

void MemCard_LoadThread_8013D764(void) asm("D_8013D764");
void MemCard_LoadThread_8013D764(void) {
    while (1) {
        switch (D_8013AF56) {
        case 19:
            func_8013D92C();
            if (D_800E3880_8013D238.f_4 == 0xD) {
                break;
            }
            MemCard_Request(0xB, 0);
            break;
        case 32:
            func_8013DDF0();
            break;
        case 33:
            func_8013DEB4();
            break;
        case 18:
            func_8013DB48();
            MemCard_Request(0xB, 0);
            break;
        case 29:
        case 30:
        case 31:
        case 34:
        case 36:
        case 40:
        case 49:
            func_8013DA00();
            MemCard_Request(0xB, 0);
            break;
        }
    }
}

extern s16 D_800E3880_8013D834 asm("g_MemCard");
extern s16 D_800E3884;

s32 func_8013D834(void) {
    switch (D_800E3880_8013D834) {
    case -5:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x25 : 0x24, 0);
        break;
    case 0:
        if (D_800E3884 == 10) {
            MemCard_Request(0xC, 0);
        } else {
            func_8013E098();
            func_8013CD1C(D_8013F284 == 0 ? 0x27 : 0x24, 0);
        }
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -8:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x18 : 0x24, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013D92C asm("g_MemCard");
extern s16 D_800E3884;
extern s16 D_8013F284;

s32 func_8013D92C(void) {
    switch (D_800E3880_8013D92C) {
    case 0:
        if (D_800E3884 == 10) {
            MemCard_Request(0xC, 0);
        } else {
            func_8013E098();
            func_8013CD1C(D_8013F284 == 0 ? 0x1D : 0x24, 0);
        }
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -8:
    case -5:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x1E : 0x24, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DA00 asm("g_MemCard");

s32 func_8013DA00(void) {
    switch (D_800E3880_8013DA00) {
    case -7:
        if (D_8013AF56 != 0x26) {
            func_8013CD1C(0x12, 0);
        }
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DA7C asm("g_MemCard");

s32 func_8013DA7C(void) {
    switch (D_800E3880_8013DA7C) {
    case -5:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x25 : 0x24, 0);
        break;
    case 0:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x27 : 0x24, 0);
        break;
    case -8:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x18 : 0x24, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DB48 asm("g_MemCard");
extern s16 D_8013F284;

s32 func_8013DB48(void) {
    switch (D_800E3880_8013DB48) {
    case 0:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x1D : 0x24, 0);
        break;
    case -8:
    case -5:
        func_8013E098();
        func_8013CD1C(D_8013F284 == 0 ? 0x1E : 0x24, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DBF0 asm("g_MemCard");

s32 func_8013DBF0(void) {
    switch (D_800E3880_8013DBF0) {
    case 0:
        func_8013E22C(0);
        func_8013CD1C(0x26, 0);
        break;
    case -4:
        func_8013E22C(-4);
        func_8013CD1C(0x17, 0);
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x2E, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DC78 asm("g_MemCard");
extern s32 D_8013F290;
s32 func_8013E098(void);
s32 func_8013E114(void);
s32 func_8013E188(s32 clear);

s32 func_8013DC78(void) {
    switch (D_800E3880_8013DC78) {
    case 0:
        if (D_8013F290 == 0) {
            break;
        }
        if (D_8013AF56 == 0x27) {
            func_8013CD1C(0x1A, 0);
        } else {
            func_8013E098();
            if (D_8013F284 != 0) {
                func_8013CD1C(0x24, 0);
            } else if (func_8013E114() != 0) {
                func_8013CD1C(0x14, 0);
            } else {
                func_8013E188(1);
                if (D_8013AF56 == 0x25) {
                    func_8013CD1C(0x30, 0);
                    MemCard_Request(0xD, 0);
                    if (D_800E3880_8013DC78 == 0) {
                        D_800E3880_8013DC78 = 1;
                    } else {
                        if (D_800E3880_8013DC78 == -4) {
                            func_8013E22C(-4);
                            func_8013CD1C(0x17, 0);
                        } else if (D_800E3880_8013DC78 == -7) {
                            func_8013E22C(-7);
                            func_8013CD1C(0x12, 0);
                        } else if (D_800E3880_8013DC78 == -2 || D_800E3880_8013DC78 == -1) {
                            func_8013E22C(-1);
                            func_8013CD1C(0x2E, 0);
                        } else {
                            func_8013CD1C(0x15, 0);
                        }
                        break;
                    }
                } else {
                    MemCard_Request(0xE, 0);
                }
                func_8013CD1C(0x15, 0);
            }
        }
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x2E, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DDF0 asm("g_MemCard");
extern s32 D_8013F288;
s32 func_8013E114(void);

s32 func_8013DDF0(void) {
    s32 a;

    switch (D_800E3880_8013DDF0) {
    case 0:
        func_8013E098();
        if (D_8013F284 != 0) {
            a = 0x24;
        } else if (func_8013E114() != 0) {
            a = 0x14;
        } else {
            if (D_8013F288 == 0) {
                func_8013E188(0);
            }
            MemCard_Request(0xF, 0);
            a = 0x21;
        }
        func_8013CD1C(a, 0);
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x2F, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DEB4 asm("g_MemCard");
extern s32 D_8013F288;

s32 func_8013DEB4(void) {
    switch (D_800E3880_8013DEB4) {
    case 0:
        if (D_8013F288 == 0) {
            func_8013E22C(0);
        }
        func_8013CD1C(0x22, 0);
        break;
    case -7:
        func_8013CD1C(0x12, 0);
        break;
    case -2:
    case -1:
        func_8013CD1C(0x2F, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_8013DF40 asm("g_MemCard");
extern s16 D_8013F28C;
void func_8013784C(s32, s32);

s32 func_8013DF40(void) {
    if (++D_8013F28C < 3) {
        return 0;
    }
    MemCard_Request(3, 0);
    if (D_800E3880_8013DF40 == -2 || D_800E3880_8013DF40 == -1) {
        func_8013784C(0x2A, 0);
        return 0;
    }
    if (D_800E3880_8013DF40 != 0) {
        func_8013CD1C(0x12, 0);
    } else {
        func_8013E098();
        if (D_8013F284 != 0) {
            func_8013CD1C(0x24, 0);
        } else if (func_8013E114() != 0) {
            func_8013CD1C(0x14, 0);
        } else {
            func_8013E188(1);
            func_8013CD1C(0x30, 0);
            MemCard_Request(0xD, 0);
            if (D_800E3880_8013DF40 == 0) {
                D_800E3880_8013DF40 = 1;
                func_8013CD1C(0x15, 0);
            } else if (D_800E3880_8013DF40 == -4) {
                func_8013E22C(-4);
                func_8013CD1C(0x17, 0);
            } else if (D_800E3880_8013DF40 == -7) {
                func_8013E22C(-7);
                func_8013CD1C(0x12, 0);
            } else if (D_800E3880_8013DF40 == -2 || D_800E3880_8013DF40 == -1) {
                func_8013E22C(-1);
                func_8013CD1C(0x2E, 0);
            } else {
                func_8013CD1C(0x15, 0);
            }
        }
    }
    return 0;
}

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_801444D4(s32);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E098(void) {
    s32 cmd;
    s32 res;

    MemCardSync(0, &cmd, &res);
    func_801444D4(0);
    func_8014236C(0, &cmd, &res);
    if (res == 0) {
        D_8013F284 = 0;
    } else {
        D_8013F284 = 1;
    }
    return 0;
}

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_8014464C(s32, s16 *);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E114(void) {
    s16 info[16];
    s32 cmd;
    s32 res;

    if (D_8013F284 != 0) {
        return 0;
    }
    MemCardSync(0, &cmd, &res);
    func_8014464C(0, info);
    func_8014236C(0, &cmd, &res);
    return info[0];
}

extern u8 *D_800E388C;
extern s16 D_8013F5E4_8013E188 asm("D_8013F5E4");
void func_80143F54(s32, s32, s32);

s32 func_8013E188(s32 clear) {
    s32 cmd;
    s32 result;
    s32 i;
    s32 *q;

    if (clear) {
        M2C_FIELD(D_800E388C, s32 *, 0x128) = D_8013F5E4_8013E188;
        for (i = 4, q = (s32 *)(D_800E388C + 0x120); i >= 0; i--) {
            *q-- = 0;
        }
    }
    if (D_8013F284 != 0) {
        return 0;
    }
    MemCardSync(0, &cmd, &result);
    func_80143F54(0, 1, 0x3C);
    func_8014236C(0, &cmd, &result);
    return 0;
}

extern s16 D_8013F284;
void MemCardSync(s32, s32 *, s32 *);
void func_80144084(s32);
void func_8014236C(s32, s32 *, s32 *);

s32 func_8013E22C(void) {
    s32 cmd;
    s32 res;

    if (D_8013F284 != 0) {
        return 0;
    }
    MemCardSync(0, &cmd, &res);
    func_80144084(0);
    func_8014236C(0, &cmd, &res);
    return 0;
}

s32 func_8013E438(void);
s32 func_8013E604(void);
s32 func_8013FEA0(void);
void func_80136160(s32, s32, s32, s32);
void func_80139A68(void);

s32 func_8013E290(void) {
    func_8013E438();
    func_8013E604();
    if (D_8013AF56 == 0x1D) {
        func_8013EBD0();
        func_8013FEA0();
    }
    func_80136160(0xC, 0x14, 0x160, 0x5E);
    func_80136160(0xC, 0x6E, 0x160, 0x6A);
    func_80139A68();
    return 0;
}

extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013E30C asm("g_Pad");
extern struct { s16 f_0, f_2, f_4, f_6, f_8, f_A, f_C; } D_8013F5E4_8013E30C asm("D_8013F5E4");
extern s32 D_800E5488;
extern s16 D_8013AF66;
s32 Sound_PlayFixed(s32);

s32 func_8013E30C(void) {
    u32 b;

    if (D_8013AF66 == 1) {
        if (D_800E5488 == 0x1000) {
            Sound_PlayFixed(0);
            if (--D_8013F288 < 0) {
                D_8013F288 = 1;
            }
        }
        if (D_800E5488 == 0x4000) {
            Sound_PlayFixed(0);
            if (++D_8013F288 >= 2) {
                D_8013F288 = 0;
            }
        }
        b = g_Pad_8013E30C.f_160 & g_Pad_8013E30C.f_158;
        if (b & 0x800) {
            Sound_PlayFixed(1);
            return 1;
        }
        if (b & 0x20) {
            Sound_PlayFixed(3);
            if (D_8013F288 == 0) {
                if (D_8013F5E4_8013E30C.f_0 > D_8013F5E4_8013E30C.f_C) {
                    func_8013CD1C(0x1F, 0);
                } else {
                    func_8013CD1C(0x31, 0);
                }
            } else {
                func_8013CD1C(0x28, 0);
            }
        }
    }
    return 0;
}

typedef struct { s16 id; s16 tpx, tpy; u16 cx, cy; s16 x, y, w, h; u8 u, pad13, v, pad15; } Elem_8013E438;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013E438;
extern Elem_8013E438 D_8013F29C_8013E438[] asm("D_8013F29C");
extern GameDraw g_Game_8013E438 asm("g_Game");
extern u8 *g_GamePrim;

s32 func_8013E438(void) {
    u8 *p;
    u32 *ot;
    s32 i;

    p = g_Game_8013E438.prim;
    for (i = 0; i < 20; i++) {
        if (D_8013F29C_8013E438[i].id == D_8013F288 && D_8013AF56 == 0x1D) {
            p[3] = 4;
            ((Sprt_8013E438 *)p)->code = 0x65;
        } else {
            p[3] = 4;
            ((Sprt_8013E438 *)p)->code = 0x64;
            ((Sprt_8013E438 *)p)->r0 = 0x30;
            ((Sprt_8013E438 *)p)->g0 = 0x30;
            ((Sprt_8013E438 *)p)->b0 = 0x30;
        }
        ((Sprt_8013E438 *)p)->clut = (D_8013F29C_8013E438[i].cy << 6) | ((D_8013F29C_8013E438[i].cx >> 4) & 0x3F);
        ((Sprt_8013E438 *)p)->x0 = D_8013F29C_8013E438[i].x;
        ((Sprt_8013E438 *)p)->y0 = D_8013F29C_8013E438[i].y;
        ((Sprt_8013E438 *)p)->w = D_8013F29C_8013E438[i].w;
        ((Sprt_8013E438 *)p)->h = D_8013F29C_8013E438[i].h;
        ((Sprt_8013E438 *)p)->u0 = D_8013F29C_8013E438[i].u;
        ((Sprt_8013E438 *)p)->v0 = D_8013F29C_8013E438[i].v;
        ot = &g_Game_8013E438.db[g_Game_8013E438.cur].ot[0];
        ADD_PRIM_R(ot, p, "$4", "$3");
        __asm__ volatile("");
        __asm__ volatile("");
        __asm__ volatile("");
        __asm__ volatile("");
        __asm__ volatile("");
        p += 0x14;
        p[3] = 1;
        ((u32 *)p)[1] = (((D_8013F29C_8013E438[i].tpy & 0x100) >> 4) | ((D_8013F29C_8013E438[i].tpx & 0x3FF) >> 6) | ((D_8013F29C_8013E438[i].tpy & 0x200) << 2)) | 0xE1000200;
        ot = &g_Game_8013E438.db[g_Game_8013E438.cur].ot[0];
        ADD_PRIM_R(ot, p, "$4", "$3");
        p += 8;
    }
    g_GamePrim = p;
    func_8013EB14(1);
    return 0;
}

typedef struct { s16 id; u16 tpx, tpy, cx, cy; s16 x, y, w, h; u8 u, pad13, v, pad15; } Elem_8013E604;
typedef struct { u8 u, pad1, v, pad3; s16 w; } Glyph_8013E604;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013E604;
extern Elem_8013E604 D_8013F454_8013E604[] asm("D_8013F454");
extern Glyph_8013E604 D_8013F594_8013E604[] asm("D_8013F594");
extern s16 D_8013F5E4_8013E604[] asm("D_8013F5E4");
extern GameDraw g_Game_8013E604 asm("g_Game");

s32 func_8013E604(void) {
    u8 *p;
    u32 *ot;
    Elem_8013E604 *e;
    s32 i, j, k, x;
    s32 d[3];
    s16 n;

    p = g_Game_8013E604.prim;
    for (i = 0; i < 12; i++) {
        e = &D_8013F454_8013E604[i];
        if (e->id == D_8013F288 && D_8013AF56 == 0x1D) {
            p[3] = 4;
            ((Sprt_8013E604 *)p)->code = 0x65;
        } else {
            p[3] = 4;
            ((Sprt_8013E604 *)p)->code = 0x64;
            ((Sprt_8013E604 *)p)->r0 = 0x30;
            ((Sprt_8013E604 *)p)->g0 = 0x30;
            ((Sprt_8013E604 *)p)->b0 = 0x30;
        }
        ((Sprt_8013E604 *)p)->clut = (e->cy << 6) | ((e->cx >> 4) & 0x3F);
        ((Sprt_8013E604 *)p)->x0 = e->x;
        if (e->id == 0) {
            ((Sprt_8013E604 *)p)->y0 = e->y + 3;
            ((Sprt_8013E604 *)p)->w = D_8013F594_8013E604[12].w;
            ((Sprt_8013E604 *)p)->h = 9;
            ((Sprt_8013E604 *)p)->u0 = e->u + D_8013F594_8013E604[12].u;
            ((Sprt_8013E604 *)p)->v0 = e->v + D_8013F594_8013E604[12].v;
        } else {
            ((Sprt_8013E604 *)p)->y0 = e->y;
            ((Sprt_8013E604 *)p)->w = D_8013F594_8013E604[10].w;
            ((Sprt_8013E604 *)p)->h = 0xF;
            ((Sprt_8013E604 *)p)->u0 = e->u + D_8013F594_8013E604[10].u;
            ((Sprt_8013E604 *)p)->v0 = e->v + D_8013F594_8013E604[10].v;
        }
        { register s32 c asm("$3"); c = g_Game_8013E604.cur; ot = g_Game_8013E604.db[c].ot; }
        ADD_PRIM_R(ot, p, "$4", "$3");
        p += 0x14;
        n = D_8013F5E4_8013E604[i];
        if (i == 1) {
            n--;
        }
        d[0] = (s16)(n % 10);
        if (d[0] == 0) {
            d[0] = 10;
        }
        d[0]--;
        d[1] = (s16)((s16)(n % 100) / 10);
        if (d[1] == 0) {
            d[1] = 10;
        }
        d[1]--;
        d[2] = (s16)(n / 100);
        if (d[2] == 0) {
            d[2] = 10;
        }
        d[2]--;
        if (i == 0 || i == 6) {
            k = 3;
            x = e->x + 0x34;
        } else {
            k = 2;
            x = e->x + 0x26;
        }
        for (j = 0; j < k; j++) {
            if (D_8013F454_8013E604[i].id == D_8013F288 && D_8013AF56 == 0x1D) {
                p[3] = 4;
                ((Sprt_8013E604 *)p)->code = 0x65;
            } else {
                p[3] = 4;
                ((Sprt_8013E604 *)p)->code = 0x64;
                ((Sprt_8013E604 *)p)->r0 = 0x30;
                ((Sprt_8013E604 *)p)->g0 = 0x30;
                ((Sprt_8013E604 *)p)->b0 = 0x30;
            }
            ((Sprt_8013E604 *)p)->clut = (D_8013F454_8013E604[i].cy << 6) | ((D_8013F454_8013E604[i].cx >> 4) & 0x3F);
            ((Sprt_8013E604 *)p)->x0 = x - D_8013F594_8013E604[d[j]].w;
            ((Sprt_8013E604 *)p)->y0 = D_8013F454_8013E604[i].y;
            ((Sprt_8013E604 *)p)->w = D_8013F594_8013E604[d[j]].w;
            ((Sprt_8013E604 *)p)->h = 0xF;
            ((Sprt_8013E604 *)p)->u0 = D_8013F454_8013E604[i].u + D_8013F594_8013E604[d[j]].u;
            ((Sprt_8013E604 *)p)->v0 = D_8013F454_8013E604[i].v + D_8013F594_8013E604[d[j]].v;
            ot = &g_Game_8013E604.db[g_Game_8013E604.cur].ot[0];
            ADD_PRIM_R(ot, p, "$4", "$3");
            p += 0x14;
            { s32 t = x - 2; x = t - D_8013F594_8013E604[d[j]].w; }
        }
    }
    p[3] = 1;
    ((u32 *)p)[1] = 0xE1000209;
    ot = &g_Game_8013E604.db[g_Game_8013E604.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$3");
    p += 8;
    g_Game_8013E604.prim = p;
    return 0;
}

typedef struct { s16 f0; u16 f2; s16 f4; s16 f6; s16 f8; s16 fA; u16 fC; } Anim_8013EB14;
typedef struct { u8 pad[0x14]; u16 f14; } Elem_8013EB14;
extern Anim_8013EB14 D_8013F55C[];
extern Elem_8013EB14 D_8013F29C[];

s32 func_8013EB14(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (++D_8013F55C[i].f8 > D_8013F55C[i].fA) {
            D_8013F55C[i].f8 = 0;
            if (++D_8013F55C[i].f4 >= D_8013F55C[i].f6) {
                D_8013F55C[i].f4 = 0;
            }
            D_8013F29C[D_8013F55C[i].f0].f14 = D_8013F55C[i].fC + D_8013F55C[i].f2 * (u16)D_8013F55C[i].f4;
        }
    }
    return 0;
}

extern u8 g_Game_8013EBD0[] asm("g_Game");
#define GD_8013EBD0 (*(GameDraw *)g_Game_8013EBD0)
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013EBD0;

s32 func_8013EBD0(void) {
    u8 *p;
    u32 *ot;

    p = GD_8013EBD0.prim;
    p[3] = 4;
    ((Sprt_8013EBD0 *)p)->code = 0x65;
    ((Sprt_8013EBD0 *)p)->clut = 0x7C5D;
    ((Sprt_8013EBD0 *)p)->x0 = 0x64;
    ((Sprt_8013EBD0 *)p)->y0 = 0xD8;
    ((Sprt_8013EBD0 *)p)->w = 0x13;
    ((Sprt_8013EBD0 *)p)->h = 0x11;
    ((Sprt_8013EBD0 *)p)->u0 = 0;
    ((Sprt_8013EBD0 *)p)->v0 = 0x98;
    ot = &GD_8013EBD0.db[GD_8013EBD0.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$4");
    p += 0x14;
    p[3] = 4;
    ((Sprt_8013EBD0 *)p)->code = 0x65;
    ((Sprt_8013EBD0 *)p)->clut = 0x7C1D;
    ((Sprt_8013EBD0 *)p)->x0 = 0xDC;
    ((Sprt_8013EBD0 *)p)->y0 = 0xD8;
    ((Sprt_8013EBD0 *)p)->w = 0x13;
    ((Sprt_8013EBD0 *)p)->h = 0x11;
    ((Sprt_8013EBD0 *)p)->u0 = 0;
    ((Sprt_8013EBD0 *)p)->v0 = 0x80;
    ot = &GD_8013EBD0.db[GD_8013EBD0.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$4");
    p += 0x14;
    p[3] = 1;
    ((u32 *)p)[1] = 0xE1000217;
    ot = &GD_8013EBD0.db[GD_8013EBD0.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$4");
    p += 8;
    GD_8013EBD0.prim = p;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013ED0C;
extern GameDraw g_Game_8013ED0C asm("g_Game");

s32 func_8013ED0C(void) {
    u8 *p;
    u32 *ot;
    s32 i;
    s32 now;
    s32 v;

    p = g_Game_8013ED0C.prim;
    now = VSync(-1);
    for (i = 0; i < 10; i++) {
        v = 0;
        if (now - D_8013F298 > (i + 1) * 0x96 && D_8013AF56 == 0x15) {
            p[3] = 4;
            ((Sprt_8013ED0C *)p)->code = 0x65;
            v = (now % 40 >= 0x15) ? 0x20 : 0;
        } else {
            p[3] = 4;
            ((Sprt_8013ED0C *)p)->code = 0x64;
            ((Sprt_8013ED0C *)p)->r0 = 0x30;
            ((Sprt_8013ED0C *)p)->g0 = 0x30;
            ((Sprt_8013ED0C *)p)->b0 = 0x30;
        }
        ((Sprt_8013ED0C *)p)->clut = 0x3E27;
        ((Sprt_8013ED0C *)p)->y0 = 0xBE;
        ((Sprt_8013ED0C *)p)->x0 = i * 0x1E + 0x2A;
        ((Sprt_8013ED0C *)p)->w = 0x20;
        ((Sprt_8013ED0C *)p)->h = 0x20;
        ((Sprt_8013ED0C *)p)->u0 = 0x78;
        ((Sprt_8013ED0C *)p)->v0 = v;
        ot = &g_Game_8013ED0C.db[g_Game_8013ED0C.cur].ot[0];
        ADD_PRIM_R(ot, p, "$4", "$3");
        p += 0x14;
        p[3] = 1;
        ((u32 *)p)[1] = 0xE1000209;
        ot = &g_Game_8013ED0C.db[g_Game_8013ED0C.cur].ot[0];
        ADD_PRIM_R(ot, p, "$4", "$3");
        p += 8;
    }
    g_GamePrim = p;
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
