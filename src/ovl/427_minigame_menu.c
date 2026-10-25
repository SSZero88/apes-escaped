#include "common.h"
#include "m2c_macros.h"

extern void *D_8013FD60;
extern struct S_D_8013F3E0 { u8 *f_0; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s32 f_C; s32 f_10; u8 *f_14; u8 pad18[4]; s32 f_1C; u8 pad20[0xC]; s32 f_2C; s32 f_30; } D_8013F3E0;
M2C_UNK Seq_Tick();
M2C_UNK func_80088578();
extern struct S_D_8013FC80 { u16 f_0; u8 pad_2[0x6]; s32 f_8; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; u16 f_16; } D_8013FC80;
extern s32 D_8013FB98;
s32 func_8008C09C(M2C_UNK);
extern M2C_UNK D_8013FCE0;
extern void *D_8013FCE4;
extern s32 D_8013FBF0;
extern struct S_D_8013F418 { s32 f_0; u8 pad_4[0x74]; } D_8013F418[];
extern M2C_UNK D_8013FC08;
extern M2C_UNK D_8013FD70;
extern struct S_D_8013FCF0 { u8 pad_0[0x6]; s16 f_6; u8 pad_8[0x4]; } D_8013FCF0[];
extern s32 D_8013FD2C;
extern struct S_D_8013FE60 { u8 pad_0[0x24]; s32 f_24; s32 f_28; u8 pad_2C[0x6C]; s32 f_98; s32 f_9C; u8 pad_A0[0x6C]; s32 f_10C; s32 f_110; u8 pad_114[0x6C]; s32 f_180; s32 f_184; u8 pad_188[0x6C]; s32 f_1F4; s32 f_1F8; } D_8013FE60;
extern s16 D_8013FD40;
extern M2C_UNK D_8013FD58;
M2C_UNK Msg_PutChar(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8008DDB0(s16, s16);
void func_80138350(s32 arg0);
M2C_UNK func_801384CC(s32, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_8013EF8C;
M2C_UNK func_80138368(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
M2C_UNK func_8013E940(M2C_UNK, M2C_UNK, s32);
extern M2C_UNK D_8013EB60;
extern M2C_UNK D_8013EB6C;
extern M2C_UNK D_8013EFC8;

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80136000);

void func_8013609C(void) {
    D_8013F3E0.f_2C = 0xC350;
    D_8013F3E0.f_30 = 0x4E20;
    M2C_FIELD(D_8013FD60, s32 *, 4) = 0xC350;
    M2C_FIELD(D_8013FD60, s32 *, 8) = 0x4E20;
}

void func_801360C8(void) {
    M2C_FIELD(D_8013FD60, s32 *, 4) = (s32) D_8013F3E0.f_2C;
    M2C_FIELD(D_8013FD60, s32 *, 8) = (s32) D_8013F3E0.f_30;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801360F0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013626C);

typedef struct { u8 pad0[0x1C]; u8 f_1C; u8 pad1D[0x1B]; } Pad_801364CC;
extern Pad_801364CC D_8013FBF8_801364CC[2] asm("D_8013FBF8");
s32 PadGetState(s32);
void func_8013626C(s32, s32, s32);

void func_801364CC(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        switch (PadGetState(i * 16)) {
        case 0:
            func_8013626C(0, i, i * 16);
            break;
        case 1:
            if (!(D_8013FBF8_801364CC[i].f_1C & 1)) {
                func_8013626C(0, i, i * 16);
            }
            break;
        case 6:
            if (D_8013FBF8_801364CC[i].f_1C != 3) {
                func_8013626C(1, i, i * 16);
            }
            break;
        }
    }
}

void func_801365A8(void) {
    Seq_Tick();
    func_80088578();
}

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EA90);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801365D0);

typedef struct { u8 pad0[0x14]; s16 *mat; u8 pad18[0xC]; s32 x; s32 y; s32 z; u8 pad30[0x30]; s16 rot[3]; u8 pad66[0xE]; } Mdl_80136704;
extern Mdl_80136704 D_8013FD70_80136704[] asm("D_8013FD70");
extern struct { s32 frame; u8 *prim; s32 ot; s32 cur; DrawBuf db[2]; } g_Game_80136704 asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; u8 pad10[0xD]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_80136704 asm("D_8013FBF8");
extern struct { u8 pad0[0x22]; s16 f_22; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; } D_8013F3E0_80136704 asm("D_8013F3E0");
extern SVECTOR D_800F4B30_80136704[3] asm("D_800F4B30");
extern s32 D_800E7D00_80136704 asm("D_800E7D00");
extern u8 D_800E78C0_80136704[] asm("D_800E78C0");
extern u8 D_800AF0A0[];
extern s32 D_8013EFE0;
void func_801360F0(void);
void func_801364CC(void);
void func_801365D0(void);
void func_80137934(void);
void Gfx_BeginFrame(void);
void func_8008C390(void);
void func_8004637C(void *);
void *CompMatrix(void *m0, void *m1, void *m2);
void func_80014804(s16 *, s16 *);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4(s32, s32, void *);
void DrawSync(s32);
s32 VSync(s32 mode);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
void Cd_Update(void);

void func_80136704(void) {
    Mdl_80136704 *m;
    s32 i;

    for (;;) {
        func_801360F0();
        func_801364CC();
        g_Game_80136704.frame++;
        Gfx_BeginFrame();
        func_8008C390();
        func_8004637C(D_800E78C0_80136704);
        CompMatrix(D_800AF0A0, D_800E78C0_80136704, D_800E78C0_80136704);
        for (i = 0; i < 2; i++) {
            D_8013FD70_80136704[i].x = i * 0x1F4 - 0xFA;
            D_8013FD70_80136704[i].y = 0xC0;
            D_8013FD70_80136704[i].z = 0x3D8;
            D_8013FD70_80136704[i].rot[0] = 0;
            D_8013FD70_80136704[i].rot[1] = 0;
            D_8013FD70_80136704[i].rot[2] = -0x1000;
            func_80014804(D_8013FD70_80136704[i].rot, D_8013FD70_80136704[i].mat);
            D_800F4B30_80136704[0].vx = 0;
            D_800F4B30_80136704[0].vy = g_Game_80136704.frame * 8;
            D_800F4B30_80136704[0].vz = 0;
            D_800F4B30_80136704[1].vx = 0;
            D_800F4B30_80136704[1].vy = g_Game_80136704.frame * 32;
            D_800F4B30_80136704[1].vz = 0;
            D_800F4B30_80136704[2].vx = 0;
            D_800F4B30_80136704[2].vy = -g_Game_80136704.frame * 64;
            D_800F4B30_80136704[2].vz = 0;
            Model_CalcJointMatrices(&D_8013FD70_80136704[i], 1);
            Model_ProjectBonedVerts(&D_8013FD70_80136704[i]);
            func_80017CD4(g_Game_80136704.ot, (s32)&D_800E7D00_80136704, &D_8013FD70_80136704[i]);
        }
        D_8013EFE0 = 0;
        func_80137934();
        func_801365D0();
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_80136704.db[g_Game_80136704.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136704.db[g_Game_80136704.cur].env);
        DrawOTag(&g_Game_80136704.db[g_Game_80136704.cur].ot[0xFFF]);
        Cd_Update();
        if (D_8013FBF8_80136704.f_0 & D_8013FBF8_80136704.f_4 & 0x860) {
            if (D_8013FBF8_80136704.f_1D == 1) {
                break;
            }
            D_8013FBF8_80136704.f_1D = 1;
        }
        if (D_8013FBF8_80136704.f_8 & D_8013FBF8_80136704.f_C & 0x860) {
            if (D_8013FBF8_80136704.f_55 == 1) {
                break;
            }
            D_8013FBF8_80136704.f_55 = 1;
        }
    }
    D_8013F3E0_80136704.f_24 = 0;
    if (D_8013FBF8_80136704.f_1D != 0) {
        D_8013F3E0_80136704.f_24 = 1;
    }
    if (D_8013FBF8_80136704.f_55 != 0) {
        D_8013F3E0_80136704.f_24 |= 2;
    }
    if (D_8013F3E0_80136704.f_22 == 2) {
        D_8013F3E0_80136704.f_28 = D_8013F3E0_80136704.f_2C;
    } else {
        D_8013F3E0_80136704.f_28 = D_8013F3E0_80136704.f_30;
    }
}

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAAC);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAB0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801369F4);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD0);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD4);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAD8);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAE8);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAEC);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EAF0);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB00);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB08);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB10);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", jtbl_8013EB18);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB60);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB6C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80136F30);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB94);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", D_8013EB9C);

INCLUDE_RODATA("asm/ovl/427/nonmatchings/427_minigame_menu", jtbl_8013EBA8);

typedef struct { s16 x, y, w, h; } Rect_80137654;
extern struct { u8 pad0[0x22]; s16 f_22; u8 pad24[4]; s32 f_28; s32 f_2C; s32 f_30; } D_8013F3E0_80137654 asm("D_8013F3E0");
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; } D_800EBFA0_80137654 asm("D_800EBFA0");
extern struct { s32 frame; u8 pad4[0x811C]; s16 f_8120; } g_Game_80137654 asm("g_Game");
extern u8 D_8013EFE4[];
void VSyncCallback(void *);
void func_801365A8(void);
void Game_VSyncCallback();
s32 Gfx_InitDisplay(void);
void func_8008C01C(void);
void func_80137874(void);
void func_80139444(void);
void func_80139480(void);
void func_801394A4(void);
void func_8013A29C(void);
void func_80069500(void);
void Fx_ClearAll(void);
s32 VSync(s32 mode);
void func_80011194(void *);
s32 func_800116C0();
void Cd_Update(void);
void func_8002FAF0(s32);
void func_801385F4(void);
void Sound_ResumeStreams(void);
s32 func_80136F30(void);
void func_8013DB7C(void);
void func_80136704(void);
void func_80138C30(void);
void DrawSync(s32);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void Sound_UnloadBanks(s32);
void func_80012CA0(s32);
void Boot_LoadingScreen(void);

void func_80137654(void) {
    s32 v;

    VSyncCallback(func_801365A8);
    Gfx_InitDisplay();
    func_8008C01C();
    func_80137874();
    func_80139444();
    func_80139480();
    func_801394A4();
    func_8013A29C();
    func_80069500();
    Fx_ClearAll();
    func_8013626C(0, 0, 0);
    func_8013626C(0, 1, 0x10);
    D_800EBFA0_80137654.f_24 = 0;
    D_800EBFA0_80137654.f_28 = 0x1000;
    VSync(0);
    func_80011194(D_8013EFE4);
    while (func_800116C0() >= 0) {
        Cd_Update();
        VSync(2);
    }
    func_8002FAF0(0x148);
    func_801385F4();
    g_Game_80137654.frame = 0;
    Sound_ResumeStreams();
    while ((v = func_80136F30()) >= 0) {
        if (v == 1) {
            func_8013DB7C();
            continue;
        }
        func_80136704();
        func_80138C30();
        switch (D_8013F3E0_80137654.f_22) {
        case 2:
            D_8013F3E0_80137654.f_2C = D_8013F3E0_80137654.f_28;
            break;
        case 3:
            D_8013F3E0_80137654.f_30 = D_8013F3E0_80137654.f_28;
            break;
        }
    }
    DrawSync(0);
    {
        Rect_80137654 r = { 0, 0, 0x280, 0x1E0 };

        VSync(0);
        ClearImage(&r, 0, 0, 0);
    }
    DrawSync(0);
    Sound_UnloadBanks(0);
    VSyncCallback(Game_VSyncCallback);
    func_80012CA0(0);
    g_Game_80137654.f_8120 = 0xD;
    Boot_LoadingScreen();
}

typedef struct { s16 x, y, z; s16 pad; u32 col; } Star_80137874;
extern Star_80137874 *D_8013FC78_80137874 asm("D_8013FC78");
extern u16 D_800AE8F2_80137874 asm("D_800AE8F2");
extern u16 g_RandSeed_80137874 asm("g_RandSeed");

void func_80137874(void) {
    s32 i;
    Star_80137874 *s;

    D_8013FC78_80137874 = func_8008C09C(0x300);
    for (i = 0; i < 0x40; i++) {
        D_8013FC78_80137874[i].x = (D_800AE8F2_80137874 = D_800AE8F2_80137874 * 5 + 1) & 0x1FF;
        D_8013FC78_80137874[i].z = ((g_RandSeed_80137874 = g_RandSeed_80137874 * 5 + 1) >> 8 & 3) + 1;
        D_8013FC78_80137874[i].y = (D_800AE8F2_80137874 = D_800AE8F2_80137874 * 5 + 1) >> 8;
        M2C_FIELD(&D_8013FC78_80137874[i], u32 *, 8) = 0xFFFFFF;
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137934);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80137F50);

void func_801380B4(void) {
    s32 var_v1;
    void *var_v0;

    D_8013FC80.f_14 = 0;
    var_v1 = 5;
    var_v0 = (void *)((u8 *)&D_8013FC80.f_0 + 0x3C);
    do {
        M2C_FIELD(var_v0, s16 *, 0x20) = 0;
        var_v1 -= 1;
        var_v0 -= 0xC;
    } while (var_v1 >= 0);
}

void func_801380E0(s16 arg0, s16 arg1, s32 arg2, s16 arg3) {
    D_8013FC80.f_C = arg0;
    D_8013FC80.f_E = arg1;
    D_8013FC80.f_8 = arg2;
    D_8013FC80.f_10 = arg3;
    D_8013FC80.f_14 = 1;
    D_8013FC80.f_12 = 0;
    D_8013FC80.f_16 = (u16) D_8013FC80.f_0;
}

extern u32 g_Game_80138110 asm("g_Game");

void func_80138110(void) {
    s32 more;
    u8 *dst = (u8 *)0x1F800000;
    u8 *src;
    s32 n;
    s32 i;
    u8 c;

    if (D_8013FC80.f_14 == 0) {
        return;
    }
    more = 1;
    src = (u8 *)D_8013FC80.f_8;
    D_8013FC80.f_0 = D_8013FC80.f_16;
    n = D_8013FC80.f_12 >> 3;
    for (i = 0; i < n; i++) {
        c = *src++;
        if (c == 0) {
            more = 0;
            break;
        }
        *dst++ = c;
    }
    if (g_Game_80138110 & 4) {
        *dst++ = 0x63;
    }
    *dst = 0;
    if (D_8013FC80.f_12 & 7) {
        more = 0;
    }
    if (more) {
        Sound_PlayFixed(0xA4);
    }
    func_80138368(D_8013FC80.f_C, D_8013FC80.f_E, (M2C_UNK *)0x1F800000, 0x808080);
    if (D_8013FC80.f_14 > 0) {
        if (D_8013FC80.f_10 < ++D_8013FC80.f_12) {
            D_8013FC80.f_14 = -1;
        }
    } else if (D_8013FC80.f_12 <= 0) {
        D_8013FC80.f_14 = 0;
    } else {
        D_8013FC80.f_12 -= 4;
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013825C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801382C0);

void func_80138350(s32 arg0) {
    D_8013FC80.f_0 = ((arg0 + 0xF0) << 6) | 0x37;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138368);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801384CC);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801385B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801385F4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138860);

void func_80138934(void) {
    s32 *var_v0;
    s32 var_v1;

    var_v0 = &D_8013FB98;
    var_v1 = 0xF;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (4));
    } while (var_v1 >= 0);
}

extern u8 D_8013FB98_80138958[] asm("D_8013FB98");

s32 func_80138958(s32 x, s32 z) {
    u32 cx = (x + 0x600) / 328;
    u32 cz = (z + 0x3C0) / 328;

    if (cx >= 8 || cz >= 8) {
        return -1;
    }
    if (D_8013FB98_80138958[cz + cx * 8] != 0) {
        return 0;
    }
    D_8013FB98_80138958[cz + cx * 8] = 1;
    return 1;
}

typedef struct { u8 *pad; u8 pad4[0xC]; s8 f_10; s8 f_11; s8 f_12; s8 f_13; SVECTOR f_14; SVECTOR f_1C; s16 f_24; s16 f_26; u8 pad28[0x10]; } Stick_801389E4;
extern Stick_801389E4 D_8013FC08_801389E4[] asm("D_8013FC08");
M2C_UNK VectorNormalSS(void *, void *);

void func_801389E4(void) {
    SVECTOR v;
    Stick_801389E4 *s;
    s32 i;
    s32 n;
    s32 m;
    u8 *pad;

    for (i = 0; i < 2; i++) {
        s = &D_8013FC08_801389E4[i];
        pad = s->pad;
        if (pad[0] != 0xFF) {
            s->f_10 = pad[4] + 0x80;
            s->f_11 = pad[5] + 0x80;
            s->f_12 = pad[6] + 0x80;
            s->f_13 = pad[7] + 0x80;
        } else {
            pad[4] = 0x80;
            pad[5] = 0x80;
            pad[6] = 0x80;
            pad[7] = 0x80;
            *(s32 *)&s->f_10 = 0;
        }
        v.vx = s->f_12;
        v.vz = 0;
        v.vy = s->f_13;
        n = VectorNormalSS(&v, &s->f_14) / 128;
        n = (n < 21) ? 0 : n - 21;
        n = n * 127 / 106;
        if (n < 0x80) {
            m = n;
        } else {
            m = 0x7F;
        }
        n = m;
        s->f_24 = n;
        s->f_12 = s->f_14.vx * n / 4096;
        s->f_13 = s->f_14.vy * n / 4096;
        v.vx = s->f_10;
        v.vz = 0;
        v.vy = s->f_11;
        n = VectorNormalSS(&v, &s->f_1C) / 128;
        n = (n < 21) ? 0 : n - 21;
        n = n * 127 / 106;
        if (n < 0x80) {
            m = n;
        } else {
            m = 0x7F;
        }
        n = m;
        s->f_26 = n;
        s->f_10 = s->f_1C.vx * n / 4096;
        s->f_11 = s->f_1C.vy * n / 4096;
    }
}

extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x158]; SVECTOR f_8258; SVECTOR f_8260; } g_Game_80138C30 asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; u8 pad10[0xD]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_80138C30 asm("D_8013FBF8");
extern struct { u8 pad0[0x1C]; s32 f_1C; s16 f_20; } D_8013F3E0_80138C30 asm("D_8013F3E0");
extern u8 g_CameraTarget[];
extern u8 D_800F45B0[];
extern u8 D_800E78C0[];
extern u8 D_800EC330[];
void Camera_LookAt(void *, void *, void *, void *, s32);
void Fx_UpdateAll(void);
void func_80069BEC(void);
M2C_UNK Sound_PlayFixed(M2C_UNK);
void func_801380B4(void);
void func_80138110(void);
void func_801382C0();
void func_80138860();
void func_801389E4(void);
void func_80139888();
void func_80139BF8();
void func_8013B4B4(void);
void func_8013B890(void);
void func_8013B92C();
void func_80138934(void);
void func_8013A6CC();
void func_8013A548();
void func_80139A74();
void func_8013B14C();
void func_801380E0(s16 arg0, s16 arg1, s32 arg2, s16 arg3);

void func_80138C30(void) {
    func_80138860();
    func_8013B890();
    func_801380B4();
    g_Game_80138C30.f_8258.vx = 0;
    g_Game_80138C30.f_8258.vy = 0;
    g_Game_80138C30.f_8258.vz = 0;
    g_Game_80138C30.f_8260.vx = 0;
    g_Game_80138C30.f_8260.vy = 0;
    g_Game_80138C30.f_8260.vz = 0x1000;
    Camera_LookAt(g_CameraTarget, D_800F45B0, D_800E78C0, D_800EC330, 0);
    func_8013B4B4();
    for (;;) {
        func_801360F0();
        func_801364CC();
        func_801389E4();
        func_80138934();
        func_8013A6CC();
        g_Game_80138C30.frame++;
        Gfx_BeginFrame();
        func_8008C390();
        func_80069BEC();
        Fx_UpdateAll();
        func_80139BF8();
        func_8013A548();
        func_80139888();
        func_80139A74();
        func_8013B92C();
        if (((D_8013FBF8_80138C30.f_0 & D_8013FBF8_80138C30.f_4 & 0x800) || (D_8013FBF8_80138C30.f_8 & D_8013FBF8_80138C30.f_C & 0x800))
            && D_8013FBF8_80138C30.f_1D + D_8013FBF8_80138C30.f_55 > 0) {
            D_8013F3E0_80138C30.f_20 = 1;
        }
        func_8013B530();
        func_80137934();
        func_8013B14C();
        func_8013C810();
        func_80138350(2);
        if (D_8013F3E0_80138C30.f_1C == 0xF0) {
            func_801380E0(0x9C, 0x70, (s32)"READY", 0x64);
        }
        if (D_8013F3E0_80138C30.f_1C == 0x78) {
            func_801380E0(0xA8, 0x70, (s32)"GO!", 0x64);
        }
        func_80138110();
        func_801382C0();
        func_8013CBF0();
        if (D_8013FBF8_80138C30.f_1D + D_8013FBF8_80138C30.f_55 == 0) {
            if (func_8013E71C() != 0) {
                break;
            }
        } else {
            func_8013E700();
        }
        if (D_8013F3E0_80138C30.f_20 != 0) {
            Sound_PlayFixed(3);
            if (func_80139098() != 0) {
                break;
            }
        }
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_80138C30.db[g_Game_80138C30.cur].env[0x5C]);
        PutDrawEnv(g_Game_80138C30.db[g_Game_80138C30.cur].env);
        DrawOTag(&g_Game_80138C30.db[g_Game_80138C30.cur].ot[0xFFF]);
        Cd_Update();
    }
    DrawSync(0);
    VSync(0);
    PutDispEnv(&g_Game_80138C30.db[g_Game_80138C30.cur].env[0x5C]);
    PutDrawEnv(g_Game_80138C30.db[g_Game_80138C30.cur].env);
    DrawOTag(&g_Game_80138C30.db[g_Game_80138C30.cur].ot[0xFFF]);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80138FD4);

extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80139098 asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; } D_8013FBF8_80139098 asm("D_8013FBF8");
extern struct { u8 pad0[0x20]; s16 f_20; s16 f_22; } D_8013F3E0_80139098 asm("D_8013F3E0");
extern char D_8013EB94[];
typedef struct { s16 x, y, w, h; } Rect_80139098;
void SetDrawMove(void *p, void *rect, s32 x, s32 y);
void func_80138FD4();

s32 func_80139098(void) {
    Rect_80139098 r;
    u8 *p;
    s32 cur;
    s32 sel;
    u32 pad;

    DrawSync(0);
    VSync(0);
    PutDispEnv(&g_Game_80139098.db[g_Game_80139098.cur].env[0x5C]);
    PutDrawEnv(g_Game_80139098.db[g_Game_80139098.cur].env);
    DrawOTag(&g_Game_80139098.db[g_Game_80139098.cur].ot[0xFFF]);
    sel = 0;
    Gfx_BeginFrame();
    p = g_Game_80139098.prim;
    r.x = 0;
    r.w = 0x180;
    cur = g_Game_80139098.cur;
    r.h = 0x100;
    if (cur != 0) {
        r.y = 0x100;
        SetDrawMove(p, &r, 0, 0);
    } else {
        r.y = 0;
        SetDrawMove(p, &r, 0, 0x100);
    }
    {
        register u32 *ot asm("$3") = g_Game_80139098.ot;
        ADD_PRIM_R(ot, p, "$4", "$2");
    }
    p += 0x18;
    g_Game_80139098.prim = p;
    DrawSync(0);
    VSync(1);
    PutDispEnv(&g_Game_80139098.db[g_Game_80139098.cur].env[0x5C]);
    PutDrawEnv(g_Game_80139098.db[g_Game_80139098.cur].env);
    DrawOTag(&g_Game_80139098.db[g_Game_80139098.cur].ot[0xFFF]);
    Cd_Update();
    for (;;) {
        func_801360F0();
        func_801364CC();
        Gfx_BeginFrame();
        pad = (D_8013FBF8_80139098.f_0 & D_8013FBF8_80139098.f_4) | (D_8013FBF8_80139098.f_8 & D_8013FBF8_80139098.f_C);
        if (pad & 0x860) {
            Sound_PlayFixed(3);
            break;
        }
        if (pad & 0x5000) {
            Sound_PlayFixed(0);
            sel ^= 1;
        }
        func_80138350(3);
        func_80138368(0xA2, 0x64, (M2C_UNK *)"PAUSE", 0x808080);
        func_80138350(2);
        func_80138368(0x90, 0x74, (M2C_UNK *)"CONTINUE", sel == 0 ? 0x808080 : 0x202020);
        func_80138368(0xA8, 0x84, (M2C_UNK *)D_8013EB94, sel == 1 ? 0x808080 : 0x202020);
        func_80138FD4(0x82, 0x5A, 0x7C, 0x3C);
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_80139098.db[cur].env[0x5C]);
        PutDrawEnv(g_Game_80139098.db[cur ^ 1].env);
        DrawOTag(&g_Game_80139098.db[g_Game_80139098.cur].ot[0xFFF]);
        Cd_Update();
    }
    D_8013F3E0_80139098.f_20 = 0;
    if (sel == 1) {
        D_8013F3E0_80139098.f_22 = 4;
    }
    return sel;
}
__asm__(".section .rodata\n\t.align 2\n\t.asciz \"100\"\n\t.align 2\n\t.asciz \"5024\"\n\t.align 2\n\t.asciz \"800\"\n\t.align 2\n\t.asciz \"400\"\n\t.align 2\n\t.asciz \"200\"\n\t.section .text");

void func_80139444(void) {
    M2C_FIELD(&D_8013FCE0, s32 *, 0) = func_8008C09C(0x120);
    M2C_FIELD(&D_8013FCE0, s32 *, 4) = func_8008C09C(0x180);
}

void func_80139480(void) {
    s32 var_v0;
    void *var_v1;

    var_v1 = D_8013FCE0;
    var_v0 = 0x17;
    do {
        M2C_FIELD(var_v1, s8 *, 7) = 0;
        var_v0 -= 1;
        var_v1 += 0xC;
    } while (var_v0 >= 0);
}

void func_801394A4(void) {
    s32 var_v0;
    void *var_v1;

    var_v1 = D_8013FCE4;
    var_v0 = 0x1F;
    do {
        M2C_FIELD(var_v1, s8 *, 7) = 0;
        var_v0 -= 1;
        var_v1 += 0xC;
    } while (var_v0 >= 0);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801394C8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801395B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013966C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801396F4);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013978C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139840);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139888);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139A74);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139BF8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_80139F80);

void func_8013A29C(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_8013F418[i].f_0 = 0;
    }
    D_8013FBF0 = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A2C8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A548);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A6CC);

void func_8013A760(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 *var_a0;
    s32 *var_a1;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_a2 = (s32) (arg2 + 3) >> 2;
    var_v1 = 0;
    if (temp_a2 > 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 = (void *)((u8 *)var_a1 + (4));
            var_v1 += 1;
            *var_a0 = temp_v0;
            var_a0 = (void *)((u8 *)var_a0 + (4));
        } while (var_v1 < temp_a2);
    }
}

typedef struct { s32 f_0; u8 pad4[0x24]; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[0x16]; s16 f_52; u8 pad54[0x10]; s32 f_64; u8 pad68[0x10]; } Pop_8013A794;
extern Pop_8013A794 D_8013F418_8013A794[] asm("D_8013F418");
extern u8 D_8013FE60_8013A794[] asm("D_8013FE60");
extern s32 D_8013F3F0;
extern s32 D_8013F3E4;
void func_8013A760(s32 *arg0, s32 *arg1, s32 arg2);

s32 func_8013A794(s32 kind, s16 *pos) {
    s32 n;
    s32 i;
    Pop_8013A794 *e = D_8013F418_8013A794;

    n = D_8013F3F0 / 10 + 2;
    if (n > 16) {
        n = 16;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->f_0 == 0) {
            func_8013A760((s32 *)&e->pad4, (s32 *)(D_8013FE60_8013A794 + kind * 0x74), 0x74);
            e->f_28 = pos[0];
            e->f_2C = pos[1];
            e->f_30 = 0xA40;
            e->f_34 = 0;
            e->f_38 = 0;
            e->f_64 = D_8013F3E4;
            e->f_0 = kind + 1;
            e->f_52 = i & 1;
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013A8C0);

typedef struct { u8 pad0[0xD]; u8 f_D; u8 padE[0x1A]; s32 f_28; u8 pad2C[4]; s16 f_30; u8 pad32[6]; } A_427;
typedef struct { u8 pad0[0x54]; s32 f_54; u8 pad58[0x1C]; } B_427;
extern A_427 D_8013FC08_8013AE1C[] asm("D_8013FC08");
extern B_427 D_8013FD70_8013AE1C[] asm("D_8013FD70");

void func_8013AE1C(s32 i) {
    A_427 *a = &D_8013FC08_8013AE1C[i];
    B_427 *b = &D_8013FD70_8013AE1C[i];

    a->f_D = 0;
    b->f_54 = 0;
    a->f_30 = 3;
    a->f_28 = 0;
}

void func_8013AE64(s32 arg0) {
    s32 var_v0;
    void *temp_a0;
    void *temp_v1;

    temp_v1 = (void *)((u8 *)&D_8013FD70 + (arg0 * 0x74));
    temp_a0 = (void *)((u8 *)&D_8013FC08 + (arg0 * 0x38));
    if (M2C_FIELD(temp_a0, s16 *, 0x30) <= 0) {
        M2C_FIELD(temp_a0, s8 *, 0xD) = 0;
        return;
    }
    M2C_FIELD(temp_a0, s16 *, 0x30) = (s16) ((u16) M2C_FIELD(temp_a0, s16 *, 0x30) - 1);
    M2C_FIELD(temp_v1, s32 *, 0x54) = 0;
    if (arg0 == 0) {
        M2C_FIELD(temp_v1, s32 *, 0x24) = 0x1F4;
        var_v0 = 0x12C;
    } else {
        M2C_FIELD(temp_v1, s32 *, 0x24) = -0x1F4;
        var_v0 = -0x3C;
    }
    M2C_FIELD(temp_v1, s32 *, 0x28) = var_v0;
    M2C_FIELD(temp_v1, s32 *, 0x2C) = 0x3D8;
    M2C_FIELD(temp_v1, s16 *, 0x6A) = 0x1000;
    M2C_FIELD(temp_v1, s16 *, 0x64) = -0x1000;
    M2C_FIELD(temp_v1, s16 *, 0x68) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x6C) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x60) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x62) = 0;
    M2C_FIELD(temp_a0, s8 *, 0xD) = 2;
    M2C_FIELD(temp_a0, s8 *, 0xE) = 0;
}

extern struct { s32 f_0; s32 f_4; s32 f_8; } g_Game_8013AF14 asm("g_Game");
extern SVECTOR D_800F4B30[3];
extern s32 D_800E7D00;
void Matrix_LookAt(void *, void *, void *, s32);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4(s32, s32, void *);

void func_8013AF14(u8 *m) {
    Matrix_LookAt(m + 0x60, m + 0x68, M2C_FIELD(m, void **, 0x14), 0);
    D_800F4B30[0].vx = 0;
    D_800F4B30[0].vy = g_Game_8013AF14.f_0 * 8;
    D_800F4B30[0].vz = 0;
    D_800F4B30[1].vx = 0;
    D_800F4B30[1].vy = g_Game_8013AF14.f_0 * 32;
    D_800F4B30[1].vz = 0;
    D_800F4B30[2].vx = 0;
    D_800F4B30[2].vy = -g_Game_8013AF14.f_0 * 64;
    D_800F4B30[2].vz = 0;
    Model_CalcJointMatrices(m, 1);
    Model_ProjectBonedVerts(m);
    func_80017CD4(g_Game_8013AF14.f_8, (s32)&D_800E7D00, m);
}

typedef struct { u8 pad0[0xD]; u8 f_D; u8 f_E; u8 padF[0x29]; } Slot_8013AFC0;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x1C]; s16 f_4C; u8 pad4E[0x12]; s16 r[3]; s16 pad66; s16 t[3]; u8 pad6E[6]; } Mdl_8013AFC0;
extern Slot_8013AFC0 D_8013FC08_8013AFC0[] asm("D_8013FC08");
extern Mdl_8013AFC0 D_8013FD70_8013AFC0[] asm("D_8013FD70");
s32 func_800463A4(s32, s32, s32);
void func_8013AF14(u8 *m);

void func_8013AFC0(s32 i) {
    Slot_8013AFC0 *s = &D_8013FC08_8013AFC0[i];
    Mdl_8013AFC0 *m = &D_8013FD70_8013AFC0[i];
    s32 old;
    s32 v;

    switch (s->f_E) {
    case 0:
        old = m->x;
        v = func_800463A4(old, 0, 0x10);
        if (old == v) {
            s->f_E = 1;
        }
        m->x = v;
        break;
    case 1:
        m->x = func_800463A4(m->x, i == 0 ? -0x200 : 0x200, 0x10);
        m->y = func_800463A4(m->y, 0x3D8, 0x10);
        m->z = func_800463A4(m->z, 0xA40, 0x10);
        m->r[0] = func_800463A4(m->r[0], 0, 0x3F);
        m->r[1] = func_800463A4(m->r[1], -0x1000, 0x3F);
        m->r[2] = func_800463A4(m->r[2], 0, 0x3F);
        m->t[0] = func_800463A4(m->t[0], 0, 0x3F);
        m->t[1] = func_800463A4(m->t[1], 0, 0x3F);
        m->t[2] = func_800463A4(m->t[2], 0x1000, 0x3F);
        if (m->z == 0xA40) {
            s->f_D = 3;
            m->f_4C = 0xB4;
        }
        break;
    default:
        return;
    }
    func_8013AF14((u8 *)m);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B14C);

extern u8 g_Game[];

void func_8013B444(s16 x, s16 y) {
    SprtTp *p;
    register u32 *ot asm("$4");

    p = (SprtTp *)G_DRAW.prim;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    M2C_FIELD(p, u16 *, 0x10) = 0x40A0;
    p->tpage = 0xE100020F;
    p->clut = 0x3A7F;
    p->x0 = x;
    p->y0 = y;
    M2C_FIELD(p, u32 *, 0x14) = 0x200020;
    ot = G_DRAW.ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    G_DRAW.prim = (u8 *)(p + 1);
}

extern u8 D_8013F184[];

void func_8013B4B4(void) {
    D_8013F3E0.f_0 = D_8013F184;
    D_8013F3E0.f_6 = 0x1000;
    D_8013F3E0.f_14 = "LEVEL 000";
    D_8013F3E0.f_C = 0;
    D_8013F3E0.f_4 = 0;
    D_8013F3E0.f_8 = 0;
    D_8013F3E0.f_10 = 0;
    D_8013F3E0.f_1C = 0x12C;
}

s32 func_8013B4F8(void) {
    s32 *var_a0;
    s32 var_a1;
    s32 var_v1;

    var_a0 = &D_8013F418;
    var_a1 = 0;
    var_v1 = 0xF;
    do {
        if (*var_a0 != 0) {
            var_a1 += 1;
        }
        var_v1 -= 1;
        var_a0 = (void *)((u8 *)var_a0 + (0x78));
    } while (var_v1 >= 0);
    return var_a1;
}

typedef struct { u8 op; u8 a; s8 b; s8 c; } Cmd_8013B530;
extern struct { u8 pad0[0x1D]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_8013B530 asm("D_8013FBF8");
extern u8 D_8013F180[];
void func_8013C7FC_8013B530() asm("func_8013C7FC");

void func_8013B530(void) {
    Cmd_8013B530 *c = (Cmd_8013B530 *)D_8013F3E0.f_0;
    s16 *scr = (s16 *)0x1F800000;
    s32 n;
    u8 *buf;

    if (D_8013FBF8_8013B530.f_1D + D_8013FBF8_8013B530.f_55 == 0) {
        return;
    }
    if (D_8013F3E0.f_1C > 0) {
        D_8013F3E0.f_1C--;
        return;
    }
    if (D_8013F3E0.f_C > 0) {
        D_8013F3E0.f_C--;
        return;
    }
    switch (c->op) {
    case 0:
        break;
    case 1:
        scr[0] = c->b * 19;
        scr[1] = c->c * 12;
        if (func_8013A794(c->a, scr) == 0) {
            if (c->b == 0x7F) {
                n = 3;
            } else if (c->b == -0x7F) {
                n = 2;
            } else if (c->c == 0x7F) {
                n = 1;
            } else if (c->c == -0x7F) {
                n = 0;
            } else {
                break;
            }
            func_8013C7FC_8013B530(n, 0x1E);
        }
        break;
    case 2:
        if (func_8013B4F8() != 0) {
            c--;
        }
        break;
    case 0xFF:
        c = (Cmd_8013B530 *)D_8013F180;
        break;
    case 4:
        D_8013F3E0.f_C = c->b * c->c;
        break;
    case 3:
        D_8013F3E0.f_4 = (s8)((u8 *)c)[2] << 6;
        D_8013F3E0.f_6 = (s8)((u8 *)c)[3] << 6;
        break;
    case 5:
        func_8013C7FC_8013B530(c->a, c->b);
        break;
    case 6:
        if (++D_8013F3E0.f_10 > 100) {
            D_8013F3E0.f_10 = 101;
        }
        break;
    case 7:
        if (D_8013F3E0.f_10 != 101) {
            func_80138350(2);
            buf = D_8013F3E0.f_14;
            if (D_8013F3E0.f_10 >= 100) {
                buf[6] = 'M';
                buf[7] = 'A';
                buf[8] = 'X';
            } else {
                buf[6] = D_8013F3E0.f_10 / 100 % 10 + '0';
                buf[7] = D_8013F3E0.f_10 / 10 % 10 + '0';
                buf[8] = D_8013F3E0.f_10 % 10 + '0';
            }
            func_801380E0(0x88, 0x70, (s32)buf, 0x8C);
        }
        break;
    }
    D_8013F3E0.f_0 = (u8 *)(c + 1);
}

void func_8013B890(void) {
    s32 i;

    for (i = 4; i >= 0; i--) {
        D_8013FCF0[i].f_6 = 0;
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B8B8);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013B92C);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013BAC0);

typedef struct { s16 next; s16 last; } Anim_8013BC28;
typedef struct { u8 pad0[0x14]; void *f_14; u8 pad18[0xC]; s32 x; s32 y; s32 z; s32 vx; s32 vy; u8 pad38[0xC]; s16 f_44; s16 f_46; s16 f_48; u8 pad4A[4]; u16 f_4E; u8 pad50[0xC]; u16 f_5C; u16 f_5E; SVECTOR f_60; SVECTOR f_68; Anim_8013BC28 *f_70; } Mdl_8013BC28;
extern s16 D_8013F402;
extern s32 *D_8013FBD8_8013BC28[] asm("D_8013FBD8");
s32 func_80138958(s32 x, s32 z);
void *ScaleMatrixL(void *m, void *v);
void func_80015780(void *, s32);

void func_8013BC28(Mdl_8013BC28 *m) {
    s32 sc[3];
    u32 s;
    s32 *t;
    s32 v;
    s32 vy;
    u16 n;

    n = ++m->f_5C;
    if (m->f_70[m->f_5E].last < n) {
        m->f_5C = m->f_70[m->f_5E].next;
    }
    m->f_60.vz = -0x1000;
    m->f_68.vy = 0x1000;
    M2C_FIELD(m, s16 *, 0x60) = 0;
    M2C_FIELD(m, s16 *, 0x62) = 0;
    M2C_FIELD(m, s16 *, 0x68) = 0;
    M2C_FIELD(m, s16 *, 0x6C) = 0;
    if (D_8013F402 != 1) {
        if (func_80138958(m->x + m->vx, m->y + m->vy)) {
            t = D_8013FBD8_8013BC28[m->f_4E];
            m->x += m->vx;
            m->y += m->vy;
            v = m->vx;
            m->vx = (m->x < t[0]) ? v + 1 : v - 1;
            vy = m->vy;
            m->vy = (m->y < t[1]) ? vy + 1 : vy - 1;
            m->vx = (m->vx < -0x10) ? -0x10 : (m->vx > 0x10) ? 0x10 : m->vx;
            m->vy = (m->vy < -0x10) ? -0x10 : (m->vy > 0x10) ? 0x10 : m->vy;
        } else {
            m->vx = 0;
            m->vy = 0;
        }
    }
    m->z = 0xA40;
    Matrix_LookAt(&m->f_60, &m->f_68, m->f_14, 0);
    if (D_8013F402 != 1) {
        s = ((0x10 - m->f_48) << 12) / 3 + 0x1000;
    } else {
        s = 0x1800;
    }
    sc[0] = s;
    sc[1] = s;
    sc[2] = s;
    ScaleMatrixL(m->f_14, sc);
    m->f_44 = (s * 3) >> 7;
    func_80015780(m, 1);
    Model_ProjectBonedVerts(m);
}

typedef struct { s16 next; s16 last; } Anim_8013BE5C;
typedef struct { u8 pad0[0x14]; void *f_14; u8 pad18[0xC]; s32 x; s32 y; s32 z; s32 vx; s32 vy; u8 pad38[0xC]; s16 f_44; s16 f_46; s16 f_48; u8 pad4A[4]; u16 f_4E; u8 pad50[0xC]; u16 f_5C; u16 f_5E; SVECTOR f_60; SVECTOR f_68; Anim_8013BE5C *f_70; } Mdl_8013BE5C;
extern u16 g_RandSeed_8013BE5C asm("g_RandSeed");
void func_801394C8();
extern s32 *D_8013FBD8_8013BE5C[] asm("D_8013FBD8");

void func_8013BE5C(Mdl_8013BE5C *m) {
    SVECTOR d;
    s32 sc[3];
    u32 s;
    s32 *t;
    s32 *g;
    s32 v;
    s32 vy;
    u16 n;

    n = ++m->f_5C;
    if (m->f_70[m->f_5E].last < n) {
        m->f_5C = m->f_70[m->f_5E].next;
    }
    m->f_60.vy = 0x1000;
    m->f_68.vz = -0x1000;
    M2C_FIELD(m, s16 *, 0x60) = 0;
    M2C_FIELD(m, s16 *, 0x64) = 0;
    M2C_FIELD(m, s16 *, 0x68) = 0;
    M2C_FIELD(m, s16 *, 0x6A) = 0;
    if (D_8013F402 != 1) {
        if ((u16)(g_RandSeed_8013BE5C = g_RandSeed_8013BE5C * 5 + 1) >> 8 < 8) {
            g = D_8013FBD8_8013BE5C[m->f_4E];
            d.vx = g[0] - m->x;
            d.vy = g[1] - m->y;
            d.vz = 0;
            VectorNormalSS(&d, &d);
            func_801394C8(&m->x, &d, 1);
        }
        if (func_80138958(m->x + m->vx, m->y + m->vy)) {
            t = D_8013FBD8_8013BE5C[m->f_4E];
            m->x += m->vx;
            m->y += m->vy;
            v = m->vx;
            m->vx = (m->x < t[0]) ? v + 1 : v - 1;
            vy = m->vy;
            m->vy = (m->y < t[1]) ? vy + 1 : vy - 1;
            m->vx = (m->vx < -0x10) ? -0x10 : (m->vx > 0x10) ? 0x10 : m->vx;
            m->vy = (m->vy < -0x10) ? -0x10 : (m->vy > 0x10) ? 0x10 : m->vy;
        } else {
            m->vx = 0;
            m->vy = 0;
        }
    }
    m->z = 0xA40;
    Matrix_LookAt(&m->f_60, &m->f_68, m->f_14, 0);
    s = 0x1000;
    if (D_8013F402 != 1) {
        s = 0x2000;
    }
    sc[0] = s;
    sc[1] = s;
    sc[2] = s;
    ScaleMatrixL(m->f_14, sc);
    m->f_44 = (s * 3) >> 7;
    func_80015780(m, 1);
    Model_ProjectBonedVerts(m);
}

typedef struct { s16 next; s16 last; } Anim_8013C0E4;
typedef struct { u8 pad0[0x14]; void *f_14; u8 pad18[0xC]; s32 x; s32 y; s32 z; s32 vx; s32 vy; u8 pad38[0xC]; s16 f_44; s16 f_46; s16 f_48; u8 pad4A[4]; u16 f_4E; u8 pad50[0xC]; u16 f_5C; u16 f_5E; SVECTOR f_60; SVECTOR f_68; Anim_8013C0E4 *f_70; } Mdl_8013C0E4;
extern u16 g_RandSeed_8013C0E4 asm("g_RandSeed");
extern s32 *D_8013FBD8_8013C0E4[] asm("D_8013FBD8");

void func_8013C0E4(Mdl_8013C0E4 *m) {
    SVECTOR d;
    s32 sc[3];
    u32 s;
    s32 *t;
    s32 *g;
    s32 v;
    s32 vy;
    u16 n;

    n = ++m->f_5C;
    if (m->f_70[m->f_5E].last < n) {
        m->f_5C = m->f_70[m->f_5E].next;
    }
    m->f_60.vy = 0x1000;
    m->f_68.vz = 0x1000;
    M2C_FIELD(m, s16 *, 0x60) = 0;
    M2C_FIELD(m, s16 *, 0x64) = 0;
    M2C_FIELD(m, s16 *, 0x68) = 0;
    M2C_FIELD(m, s16 *, 0x6A) = 0;
    if (D_8013F402 != 1) {
        if ((u16)(g_RandSeed_8013C0E4 = g_RandSeed_8013C0E4 * 5 + 1) >> 8 < 8) {
            g = D_8013FBD8_8013C0E4[m->f_4E];
            d.vx = g[0] - m->x;
            d.vy = g[1] - m->y;
            d.vz = 0;
            VectorNormalSS(&d, &d);
            func_801394C8(&m->x, &d, 1);
        }
        if (func_80138958(m->x + m->vx, m->y + m->vy)) {
            t = D_8013FBD8_8013C0E4[m->f_4E];
            m->x += m->vx;
            m->y += m->vy;
            v = m->vx;
            m->vx = (m->x < t[0]) ? v + 1 : v - 1;
            vy = m->vy;
            m->vy = (m->y < t[1]) ? vy + 1 : vy - 1;
            m->vx = (m->vx < -0x10) ? -0x10 : (m->vx > 0x10) ? 0x10 : m->vx;
            m->vy = (m->vy < -0x10) ? -0x10 : (m->vy > 0x10) ? 0x10 : m->vy;
        } else {
            m->vx = 0;
            m->vy = 0;
        }
    }
    m->z = 0xA40;
    Matrix_LookAt(&m->f_60, &m->f_68, m->f_14, 0);
    s = 0x1800;
    if (D_8013F402 != 1) {
        s = 0x3000;
    }
    sc[0] = s;
    sc[1] = s;
    sc[2] = s;
    ScaleMatrixL(m->f_14, sc);
    m->f_44 = (s * 3) >> 7;
    func_80015780(m, 1);
    Model_ProjectBonedVerts(m);
}

typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x30]; s16 f_60; s16 f_62; } Mdl_8013C368;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013C368;
typedef struct { Mat_8013C368 rot; SVECTOR dir; SVECTOR up; u8 pad30[0x10]; s32 scale[3]; } Scr_8013C368;
extern s32 g_Game_8013C368 asm("g_Game");
extern Mat_8013C368 D_800E9C60_8013C368 asm("D_800E9C60");
extern u8 D_800E78C0[];
void func_8004637C(void *);
void *RotMatrixX(s32 r, void *m);
void *MulMatrix(void *m0, void *m1);
void *CompMatrix(void *m0, void *m1, void *m2);
void Model_ProjectVertsAlt(void *, void *, void *);

void func_8013C368(Mdl_8013C368 *m) {
    Scr_8013C368 *s = (Scr_8013C368 *)0x1F800000;
    Mat_8013C368 *mat;

    m->z = 0xA40;
    if (D_8013F402 != 1) {
        m->x += m->f_60 >> 8;
        m->y += m->f_62 >> 8;
        s->dir.vx = m->f_60;
        s->dir.vy = m->f_62;
        s->dir.vz = 0;
    } else {
        s->dir.vx = -0x1000;
        s->dir.vy = 0;
        s->dir.vz = 0;
    }
    mat = &D_800E9C60_8013C368;
    s->up.vx = 0;
    s->up.vy = 0;
    s->up.vz = 0x1000;
    Matrix_LookAt(&s->dir, &s->up, mat, 0);
    func_8004637C(s);
    RotMatrixX(g_Game_8013C368 * 32, s);
    MulMatrix(mat, s);
    mat->t[0] = m->x;
    mat->t[1] = m->y;
    mat->t[2] = 0xA40;
    if (D_8013F402 == 1) {
        s->scale[0] = 0x800;
        s->scale[1] = 0x800;
        s->scale[2] = 0x800;
        ScaleMatrixL(mat, s->scale);
    }
    CompMatrix(D_800E78C0, mat, mat);
    Model_ProjectVertsAlt(m, mat, &D_800E7D00);
}

s32 rcos(s32);
void func_8004637C(void *);
void RotMatrixZ(s32, void *);
void ApplyMatrixSV(void *, SVECTOR *, SVECTOR *);
M2C_UNK VectorNormalSS(void *, void *);

void func_8013C4D4(SVECTOR *a, SVECTOR *b, s32 ang) {
    s32 c;

    if ((a->vx * b->vx + a->vy * b->vy) >> 12 < rcos(ang)) {
        func_8004637C((void *)0x1F800000);
        c = (a->vx * b->vy - a->vy * b->vx) / 4096;
        if (c > 0) {
            RotMatrixZ(-ang, (void *)0x1F800000);
        } else {
            RotMatrixZ(ang, (void *)0x1F800000);
        }
        ApplyMatrixSV((void *)0x1F800000, b, b);
    } else {
        *b = *a;
    }
    VectorNormalSS(b, b);
}

typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; s32 f_30; s32 f_34; u8 pad38[0x16]; u16 f_4E; u8 pad50[0x10]; s16 f_60; s16 f_62; } Mdl_8013C5F0;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013C5F0;
typedef struct { Mat_8013C5F0 rot; SVECTOR dir; SVECTOR up; SVECTOR tgt; } Scr_8013C5F0;
extern u16 g_RandSeed_8013C5F0 asm("g_RandSeed");
extern s16 *D_8013FBD8[];
extern Mat_8013C5F0 D_800E9C60_8013C5F0 asm("D_800E9C60");
void func_801395B8();
void func_8013C4D4(SVECTOR *a, SVECTOR *b, s32 ang);

void func_8013C5F0(Mdl_8013C5F0 *m) {
    Scr_8013C5F0 *s = (Scr_8013C5F0 *)0x1F800000;
    Mat_8013C5F0 *mat;

    m->z = 0xA40;
    if (D_8013F402 != 1) {
        if ((u16)(g_RandSeed_8013C5F0 = g_RandSeed_8013C5F0 * 5 + 1) >> 8 < 2) {
            func_801395B8(&m->x, &m->f_60, 1);
        }
        if (func_80138958(m->x + m->f_30, m->y + m->f_34)) {
            m->x += m->f_60 >> 8;
            m->y += m->f_62 >> 8;
        }
        s->dir.vx = m->f_60;
        s->dir.vy = m->f_62;
        s->dir.vz = 0;
        s->up.vx = 0;
        s->up.vy = 0;
        s->up.vz = 0x1000;
        s->tgt.vx = D_8013FBD8[m->f_4E][0] - m->x;
        s->tgt.vy = D_8013FBD8[m->f_4E][2] - m->y;
        s->tgt.vz = 0;
        VectorNormalSS(&s->tgt, &s->tgt);
        func_8013C4D4(&s->tgt, &s->dir, 0xB);
        m->f_60 = s->dir.vx;
        m->f_62 = s->dir.vy;
    } else {
        s->dir.vx = -0x1000;
        s->dir.vy = 0;
        s->dir.vz = 0;
        s->up.vx = 0;
        s->up.vy = 0;
        s->up.vz = 0x1000;
    }
    mat = &D_800E9C60_8013C5F0;
    Matrix_LookAt(&s->dir, &s->up, mat, 0);
    mat->t[0] = m->x;
    mat->t[1] = m->y;
    mat->t[2] = 0xA40;
    CompMatrix(D_800E78C0, mat, mat);
    Model_ProjectVertsAlt(m, mat, &D_800E7D00);
}

void func_8013C7F0(void) {
    D_8013FD2C = 0;
}

extern u8 D_8013FD2C_8013C7FC[] asm("D_8013FD2C");

void func_8013C7FC(s32 i, u8 v) {
    D_8013FD2C_8013C7FC[i] = v;
}

extern struct { s32 frame; u8 *prim; u32 *ot; } g_Game_8013C810 asm("g_Game");
extern u8 *D_800EC354_8013C810 asm("D_800EC354");

void func_8013C810(void) {
    u8 *p = g_Game_8013C810.prim;
    u32 *ot = g_Game_8013C810.ot;
    s32 i;

    if (g_Game_8013C810.frame & 1) {
        return;
    }
    i = D_8013FD2C_8013C7FC[0];
    if (i > 0) {
        D_8013FD2C_8013C7FC[0] = i - 1;
        for (i = 0; i < 0x180; i += 0x20) {
            M2C_FIELD(p, s32 *, 8) = 0x606060;
            p[3] = 5;
            M2C_FIELD(p, s32 *, 4) = 0xE1000238;
            p[0xB] = 0x66;
            M2C_FIELD(p, s32 *, 0xC) = i | 0x80000;
            M2C_FIELD(p, s16 *, 0x10) = 0x2000;
            M2C_FIELD(p, s32 *, 0x14) = 0x200020;
            M2C_FIELD(p, s16 *, 0x12) = 0x3A9F;
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    i = D_8013FD2C_8013C7FC[1];
    if (i > 0) {
        D_8013FD2C_8013C7FC[1] = i - 1;
        for (i = 0; i < 0x180; i += 0x20) {
            M2C_FIELD(p, s32 *, 8) = 0x606060;
            p[3] = 5;
            M2C_FIELD(p, s32 *, 4) = 0xE1000238;
            p[0xB] = 0x66;
            M2C_FIELD(p, s32 *, 0xC) = i | 0xE00000;
            M2C_FIELD(p, s16 *, 0x10) = 0x2000;
            M2C_FIELD(p, s32 *, 0x14) = 0x200020;
            M2C_FIELD(p, s16 *, 0x12) = 0x3A9F;
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    i = D_8013FD2C_8013C7FC[2];
    if (i > 0) {
        D_8013FD2C_8013C7FC[2] = i - 1;
        for (i = 8; i < 0xD0; i += 0x20) {
            M2C_FIELD(p, s32 *, 8) = 0x606060;
            p[3] = 5;
            M2C_FIELD(p, s32 *, 4) = 0xE1000238;
            p[0xB] = 0x66;
            M2C_FIELD(p, s32 *, 0xC) = i << 16;
            M2C_FIELD(p, s16 *, 0x10) = 0x2000;
            M2C_FIELD(p, s32 *, 0x14) = 0x200020;
            M2C_FIELD(p, s16 *, 0x12) = 0x3A9F;
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    i = D_8013FD2C_8013C7FC[3];
    if (i > 0) {
        D_8013FD2C_8013C7FC[3] = i - 1;
        for (i = 8; i < 0xD0; i += 0x20) {
            M2C_FIELD(p, s32 *, 8) = 0x606060;
            p[3] = 5;
            M2C_FIELD(p, s32 *, 4) = 0xE1000238;
            p[0xB] = 0x66;
            M2C_FIELD(p, s32 *, 0xC) = (i << 16) | 0x160;
            M2C_FIELD(p, s16 *, 0x10) = 0x2000;
            M2C_FIELD(p, s32 *, 0x14) = 0x200020;
            M2C_FIELD(p, s16 *, 0x12) = 0x3A9F;
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    D_800EC354_8013C810 = p;
}

extern GameDraw g_Game_8013CA94 asm("g_Game");
extern u8 *D_800EC354_8013CA94 asm("D_800EC354");
extern u32 D_8013F37C[];
typedef struct { u8 v[8]; } Seg_8013CA94;
extern Seg_8013CA94 D_8013F32C[];

void func_8013CA94(s32 digit, s32 x, s32 y, s32 sh) {
    s32 i;
    u8 *p = g_Game_8013CA94.prim;
    u32 *ot = g_Game_8013CA94.ot;

    for (i = 0; i < 10; i++) {
        if (D_8013F37C[digit] & (1 << i)) {
            M2C_FIELD(p, u32 *, 4) = 0xFF00;
            p[3] = 5;
            p[7] = 0x28;
            M2C_FIELD(p, s16 *, 0x8) = x + (D_8013F32C[i].v[0] >> sh);
            M2C_FIELD(p, s16 *, 0xA) = y + (D_8013F32C[i].v[1] >> sh);
            M2C_FIELD(p, s16 *, 0xC) = x + (D_8013F32C[i].v[2] >> sh);
            M2C_FIELD(p, s16 *, 0xE) = y + (D_8013F32C[i].v[3] >> sh);
            M2C_FIELD(p, s16 *, 0x10) = x + (D_8013F32C[i].v[4] >> sh);
            M2C_FIELD(p, s16 *, 0x12) = y + (D_8013F32C[i].v[5] >> sh);
            M2C_FIELD(p, s16 *, 0x14) = x + (D_8013F32C[i].v[6] >> sh);
            M2C_FIELD(p, s16 *, 0x16) = y + (D_8013F32C[i].v[7] >> sh);
            ADD_PRIM_ASM(ot, p);
            p += 0x18;
        }
    }
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000220;
    ADD_PRIM_ASM(ot, p);
    p += 8;
    D_800EC354_8013CA94 = p;
}

extern struct { u8 pad0[0x18]; s32 f_18; s32 f_1C; } D_8013F3E0_8013CBF0 asm("D_8013F3E0");
extern u8 D_8013FBF8_8013CBF0[] asm("D_8013FBF8");

void func_8013CBF0(void) {
    s32 t = D_8013F3E0_8013CBF0.f_18;
    s32 m;
    u8 *p;

    if (t < 0 || D_8013F3E0_8013CBF0.f_1C > 0) {
        return;
    }
    m = t / 3600;
    func_8013CA94(m / 10, 0xF8, 0xB4, 2);
    func_8013CA94(m % 10, 0x10A, 0xB4, 2);
    func_8013CA94(10, 0x11C, 0xB4, 2);
    m = t / 60 - m * 60;
    func_8013CA94(m / 10, 0x12E, 0xB4, 2);
    func_8013CA94(m % 10, 0x140, 0xB4, 2);
    if (t > 0) {
        D_8013F3E0_8013CBF0.f_18 = t - 1;
        return;
    }
    p = D_8013FBF8_8013CBF0;
    D_8013F3E0_8013CBF0.f_18 = -1;
    if (p[0x1D] != 0) {
        M2C_FIELD(p, u16 *, 0x40)++;
    }
    if (p[0x55] != 0) {
        M2C_FIELD(p, u16 *, 0x78)++;
    }
    p[0x1D] = 0;
    p[0x55] = 0;
}

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013CDB0;
typedef struct { s32 vx, vy, vz, pad; } Vec_8013CDB0;
extern struct { u32 frame; s32 prim; s32 ot; } g_Game_8013CDB0 asm("g_Game");
extern u8 D_80140220_8013CDB0[] asm("D_80140220");
void *ScaleMatrix(void *m, void *v);
void *RotMatrixZYX(void *r, void *m);
void func_80017EFC(s32, s32, void *, s32);

void func_8013CDB0(void) {
    Mat_8013CDB0 m;
    Mat_8013CDB0 r;
    Vec_8013CDB0 sc;
    SVECTOR rot;

    if (g_Game_8013CDB0.frame > 0x780) {
        return;
    }
    func_8004637C(&m);
    m.t[0] = -0x30;
    if (g_Game_8013CDB0.frame < 0x680) {
        m.t[1] = 0x50;
    } else {
        m.t[1] = g_Game_8013CDB0.frame - 0x630;
    }
    m.t[2] = 0x180;
    sc.vx = 0x400;
    sc.vy = 0x400;
    sc.vz = 0x400;
    ScaleMatrix(&m, &sc);
    CompMatrix(&m, D_800E78C0, &m);
    Model_ProjectVertsAlt(D_80140220_8013CDB0, &m, &D_800E7D00);
    func_80017EFC(g_Game_8013CDB0.ot + 0x100, (s32)&D_800E7D00, D_80140220_8013CDB0, 0);
    func_8004637C(&r);
    rot.vz = 0;
    rot.vx = (s8)D_8013FBF8_8013CBF0[0x23] * 4;
    rot.vy = -((s8)D_8013FBF8_8013CBF0[0x22] * 4);
    m.t[2] -= 0x10;
    RotMatrixZYX(&rot, &r);
    CompMatrix(&m, &r, &r);
    Model_ProjectVertsAlt(D_80140220_8013CDB0 - 0x20, &r, &D_800E7D00);
    func_80017EFC(g_Game_8013CDB0.ot, (s32)&D_800E7D00, D_80140220_8013CDB0 - 0x20, 0);

    func_8004637C(&m);
    m.t[0] = 0x30;
    if (g_Game_8013CDB0.frame < 0x680) {
        m.t[1] = 0x50;
    } else {
        m.t[1] = g_Game_8013CDB0.frame - 0x630;
    }
    m.t[2] = 0x180;
    sc.vx = 0x400;
    sc.vy = 0x400;
    sc.vz = 0x400;
    ScaleMatrix(&m, &sc);
    CompMatrix(&m, D_800E78C0, &m);
    Model_ProjectVertsAlt(D_80140220_8013CDB0, &m, &D_800E7D00);
    func_80017EFC(g_Game_8013CDB0.ot + 0x100, (s32)&D_800E7D00, D_80140220_8013CDB0, 0);
    func_8004637C(&r);
    rot.vz = 0;
    rot.vx = (s8)D_8013FBF8_8013CBF0[0x21] * 4;
    rot.vy = -((s8)D_8013FBF8_8013CBF0[0x20] * 4);
    m.t[2] -= 0x10;
    RotMatrixZYX(&rot, &r);
    CompMatrix(&m, &r, &r);
    Model_ProjectVertsAlt(D_80140220_8013CDB0 - 0x20, &r, &D_800E7D00);
    func_80017EFC(g_Game_8013CDB0.ot, (s32)&D_800E7D00, D_80140220_8013CDB0 - 0x20, 0);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D044);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D1F0);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D528);

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013D578);

void func_8013D8B8(void) {
    D_8013FE60.f_24 = 0x600;
    D_8013FE60.f_28 = -0x300;
    D_8013FE60.f_98 = 0x780;
    D_8013FE60.f_9C = -0x180;
    D_8013FE60.f_10C = 0x900;
    D_8013FE60.f_180 = 0xA80;
    D_8013FE60.f_184 = 0x180;
    D_8013FE60.f_1F4 = 0xC00;
    D_8013FE60.f_110 = 0;
    D_8013FE60.f_1F8 = 0x300;
}

typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[0x28]; s32 f_50; u8 pad54[0x20]; } Mdl_8013D910;
extern Mdl_8013D910 D_8013FE60_8013D910[] asm("D_8013FE60");
extern struct { u32 f_0; s32 f_4; s32 f_8; } g_Game_8013D910 asm("g_Game");
void func_8013BC28();
void func_8013BE5C();
void func_8013C0E4();
void func_8013C368();
void func_8013C5F0();
void func_80017EFC(s32, s32, void *, s32);

void func_8013D910(void) {
    s32 i;
    Mdl_8013D910 *m;
    s32 v;
    s32 w;

    for (i = 0; i < 5; i++) {
        m = &D_8013FE60_8013D910[i];
        v = m->f_24 -= 0x20;
        if (g_Game_8013D910.f_0 < 0x980) {
            w = (v < -0x300) ? -0x300 : (v > 0x1000) ? 0x1000 : v;
        } else {
            w = (v < -0x1000) ? -0x1000 : (v > 0x1000) ? 0x1000 : v;
        }
        m->f_24 = w;
        switch (i) {
        case 0:
            func_8013BC28((u8 *)m);
            func_80138350(0);
            func_80138368((m->f_24 >> 3) + 0xF0, 0x34, (M2C_UNK *)"... 200 POINTS", 0x808080);
            break;
        case 1:
            func_8013BE5C((u8 *)m);
            func_80138350(1);
            func_80138368((m->f_24 >> 3) + 0xF0, 0x56, (M2C_UNK *)"... 400 POINTS", 0x808080);
            break;
        case 2:
            func_8013C0E4((u8 *)m);
            func_80138350(0);
            func_80138368((m->f_24 >> 3) + 0xF0, 0x78, (M2C_UNK *)"... 800 POINTS", 0x808080);
            break;
        case 3:
            func_8013C368((u8 *)m);
            func_80138350(1);
            func_80138368((m->f_24 >> 3) + 0xF0, 0x9A, (M2C_UNK *)"... ??? POINTS", 0x808080);
            break;
        case 4:
            func_8013C5F0((u8 *)m);
            func_80138350(0);
            func_80138368((m->f_24 >> 3) + 0xF0, 0xBC, (M2C_UNK *)"... 100 POINTS", 0x808080);
            break;
        }
        switch (m->f_50) {
        case 0:
            func_80017CD4(g_Game_8013D910.f_8, (s32)&D_800E7D00, m);
            break;
        case 1:
            func_80017EFC(g_Game_8013D910.f_8, (s32)&D_800E7D00, m, 6);
            break;
        }
    }
}

void func_8013DAF0(s32 arg0, s32 arg1) {
    func_80138350(2);
    func_801384CC(arg0 - 8, arg1, &D_8013EF8C, 0x808080);
    func_8008DDB0((s16) (arg0 + 0x28), (s16) (arg1 - 4));
    Msg_PutChar(0x101, 0x1F0, 0);
    Msg_PutChar(0x104, 0x1F0, 0);
}

extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x158]; SVECTOR f_8258; SVECTOR f_8260; } g_Game_8013DB7C asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; } D_8013FBF8_8013DB7C asm("D_8013FBF8");
extern struct { u8 pad0[0x28]; s32 y; } D_8013FD70_8013DB7C asm("D_8013FD70");
void func_8013D044();
void func_8013D1F0();
void func_8013D528();
void func_8013D578();
void func_8013D8B8(void);
void func_8013D910(void);
void func_8013DAF0(s32 arg0, s32 arg1);
void func_8013E9E0(void);

void func_8013DB7C(void) {
    u32 pad;

    func_80138860();
    func_8013B890();
    func_8013D528();
    func_8013D044(0);
    func_8013D8B8();
    func_801380B4();
    g_Game_8013DB7C.f_8258.vx = 0;
    g_Game_8013DB7C.f_8258.vy = 0;
    g_Game_8013DB7C.f_8258.vz = 0;
    g_Game_8013DB7C.f_8260.vx = 0;
    g_Game_8013DB7C.f_8260.vy = 0;
    g_Game_8013DB7C.f_8260.vz = 0x1000;
    Camera_LookAt(g_CameraTarget, D_800F45B0, D_800E78C0, D_800EC330, 0);
    func_8013B4B4();
    g_Game_8013DB7C.frame = 0;
    for (;;) {
        func_801360F0();
        func_801364CC();
        func_801389E4();
        func_8013D578();
        g_Game_8013DB7C.frame++;
        pad = (D_8013FBF8_8013DB7C.f_0 & D_8013FBF8_8013DB7C.f_4) | (D_8013FBF8_8013DB7C.f_8 & D_8013FBF8_8013DB7C.f_C);
        Gfx_BeginFrame();
        func_8008C390();
        func_80069BEC();
        Fx_UpdateAll();
        if (g_Game_8013DB7C.frame < 0x700) {
            if (g_Game_8013DB7C.frame > 0x680) {
                D_8013FD70_8013DB7C.y -= 0x20;
            }
            func_80139BF8();
        } else if (g_Game_8013DB7C.frame < 0xA40) {
            func_8013D910();
        } else {
            func_8013E9E0();
        }
        func_80139888();
        func_8013CDB0();
        func_8013D1F0();
        func_8013B92C();
        if (g_Game_8013DB7C.frame & 0x20) {
            func_8013DAF0(0xC8, 0x1A);
        }
        if (pad & 0x60) {
            Sound_PlayFixed(0);
            if (g_Game_8013DB7C.frame < 0x700) {
                g_Game_8013DB7C.frame = 0x700;
                func_8013B890();
            } else if (g_Game_8013DB7C.frame < 0xA40) {
                g_Game_8013DB7C.frame = 0xA40;
            } else {
                break;
            }
        }
        if (g_Game_8013DB7C.frame > 0xB80) {
            Sound_PlayFixed(0);
            break;
        }
        func_80137934();
        func_80138110();
        func_801382C0();
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_8013DB7C.db[g_Game_8013DB7C.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013DB7C.db[g_Game_8013DB7C.cur].env);
        DrawOTag(&g_Game_8013DB7C.db[g_Game_8013DB7C.cur].ot[0xFFF]);
        Cd_Update();
    }
    DrawSync(0);
    VSync(0);
    PutDispEnv(&g_Game_8013DB7C.db[g_Game_8013DB7C.cur].env[0x5C]);
    PutDrawEnv(g_Game_8013DB7C.db[g_Game_8013DB7C.cur].env);
    DrawOTag(&g_Game_8013DB7C.db[g_Game_8013DB7C.cur].ot[0xFFF]);
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013DEFC);

void func_8013DF7C(void) {
    D_8013FD40 = 0;
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013DF88);

void func_8013E700(void) {
    M2C_FIELD(&D_8013FD58, s16 *, 0) = 0;
    M2C_FIELD(&D_8013FD58, s32 *, 4) = -1;
    M2C_FIELD(&D_8013FD58, s16 *, 2) = 0;
}

extern struct { s16 f_0; s16 f_2; s32 f_4; } D_8013FD58_8013E71C asm("D_8013FD58");
extern struct { u8 pad0[0x18]; s32 f_18; } D_8013F3E0_8013E71C asm("D_8013F3E0");
extern struct { s32 f_0; s32 f_4; } D_8013FBF8_8013E71C asm("D_8013FBF8");
extern s16 D_8013F402;
extern u8 D_8013EFBC[];
s32 Sound_Play_8013E71C(s32, s32) asm("Sound_Play");
void func_80136000(void);
void func_8013DF7C(void);
s32 func_8013DF88(void);

s32 func_8013E71C(void) {
    s32 t = D_8013FD58_8013E71C.f_0;
    s32 x;

    if (D_8013F3E0_8013E71C.f_18 > 0) {
        D_8013F3E0_8013E71C.f_18 = 0;
    }
    if (t == 0) {
        D_8013FD58_8013E71C.f_4 = Sound_Play_8013E71C(0, 0x50);
        func_80136000();
    }
    t++;
    if (t < 0x1A4) {
        func_80138350(3);
        x = t - 6;
        if (x > 0x72) {
            x = 0x72;
        }
        func_80138368(0x8A, x, (M2C_UNK *)D_8013EFBC, 0x808080);
        if (t == 0x77) {
            if (D_8013FD58_8013E71C.f_4 != -1) {
                Sound_Stop(0x50, D_8013FD58_8013E71C.f_4);
            }
            Sound_PlayFixed(0x6C);
        }
    }
    if (D_8013F402 == 3) {
        if (t < 0x1E0) {
            func_8013DF7C();
        } else {
            if (func_8013DF88() != 0) {
                return 1;
            }
            t--;
        }
    } else if (t >= 0x97) {
        if (t >= 0x1A5) {
            return 1;
        }
        if (D_8013FBF8_8013E71C.f_0 & D_8013FBF8_8013E71C.f_4 & 0x860) {
            return 1;
        }
    }
    D_8013FD58_8013E71C.f_0 = t;
    return 0;
}

void func_8013E874(s32 arg0, s32 arg1, s8 arg2, s16 arg3) {
    void *temp_v1;

    temp_v1 = (void *)((u8 *)&D_8013FC08 + (arg0 * 0x38));
    if (M2C_FIELD(temp_v1, s16 *, 0x32) != 0) {
        switch (arg1) {                             /* irregular */
        case 0:
            M2C_FIELD(temp_v1, s8 *, 0xA) = arg2;
            M2C_FIELD(temp_v1, s16 *, 0x34) = arg3;
            return;
        case 1:
            M2C_FIELD(temp_v1, s8 *, 0xB) = arg2;
            M2C_FIELD(temp_v1, s16 *, 0x36) = arg3;
            break;
        }
    }
}

typedef struct { u8 pad0[0xA]; u8 f_A; u8 f_B; u8 padC[0x26]; s16 f_32; s16 f_34; s16 f_36; } Tm_427;
extern Tm_427 D_8013FC08_8013E8D0[2] asm("D_8013FC08");

void func_8013E8D0(void) {
    s32 i;
    Tm_427 *e;

    for (i = 0; i < 2; i++) {
        e = &D_8013FC08_8013E8D0[i];
        if (e->f_32 != 0) {
            if (e->f_34 > 0) {
                e->f_34--;
            } else {
                e->f_A = 0;
            }
            if (e->f_36 > 0) {
                e->f_36--;
                continue;
            }
        } else {
            e->f_A = 0;
        }
        e->f_B = 0;
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_8013E940);

void func_8013E9E0(void) {
    func_80138350(2);
    func_80138368(0x7E, 0x34, &D_8013EFC8, 0x808080);
    func_80138350(0);
    func_80138368(0x7E, 0x4A, &D_8013EB60, 0x808080);
    func_8013E940(0x66, 0x62, D_8013F3E0.f_2C);
    func_80138350(0);
    func_80138368(0x48, 0x8C, &D_8013EB6C, 0x808080);
    func_8013E940(0x66, 0xA4, D_8013F3E0.f_30);
}
