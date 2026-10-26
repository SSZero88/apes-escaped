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
extern M2C_UNK D_8013EF8C;
extern M2C_UNK D_8013EB60;
extern M2C_UNK D_8013EB6C;
extern M2C_UNK D_8013EFC8;

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x44]; } Obj_80136000;
typedef struct { s32 active; Obj_80136000 o; } Pop_80136000;
extern Pop_80136000 D_8013F418_80136000[16] asm("D_8013F418");
void Effect_SpawnAt(s32, void *);

void func_80136000(void) {
    SVECTOR v;
    s32 i;
    Pop_80136000 *e;
    Obj_80136000 *o;

    for (i = 0; i < 16; i++) {
        if (D_8013F418_80136000[i].active != 0) {
            o = &D_8013F418_80136000[i].o;
            v.vx = o->x >> 1;
            v.vy = o->y >> 1;
            v.vz = o->z >> 1;
            Effect_SpawnAt(0x105, &v);
            D_8013F418_80136000[i].active = 0;
        }
    }
}

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

typedef struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; u8 *pad; u8 pad14[0x24]; } Ctl_801360F0;
extern Ctl_801360F0 D_8013FBF8_801360F0[2] asm("D_8013FBF8");
extern u8 D_800E52D0[];
extern u8 *D_8013FC08_801360F0 asm("D_8013FC08");
void func_8013E8D0(void);

void func_801360F0(void) {
    s32 i;
    u8 *p;
    u8 *p2;
    u8 *q;
    u32 b;
    u32 old;
    s32 a;
    Ctl_801360F0 *c;

    for (i = 1; i >= 0; i--) {
        D_8013FBF8_801360F0[i].pad = D_800E52D0 + i * 0x22;
    }

    p = D_8013FC08_801360F0;
    b = ~((p[2] << 8) | p[3]);
    if (p[0] != 0xFF) {
        a = p[6] - 0x80;
        if (a > 0x78) {
            b |= 0x2000;
        } else if (a < -0x78) {
            b |= 0x8000;
        }
        a = p[7] - 0x80;
        if (a > 0x78) {
            b |= 0x4000;
        } else if (a < -0x78) {
            b |= 0x1000;
        }
    }
    old = D_8013FBF8_801360F0[0].f_0;
    D_8013FBF8_801360F0[0].f_0 = b;
    D_8013FBF8_801360F0[0].f_4 = old ^ b;

    p2 = D_8013FBF8_801360F0[1].pad;
    b = ~((p2[2] << 8) | p2[3]);
    if (p2[0] != 0xFF) {
        a = p2[6] - 0x80;
        if (a > 0x78) {
            b |= 0x2000;
        } else if (a < -0x78) {
            b |= 0x8000;
        }
        a = p2[7] - 0x80;
        if (a > 0x78) {
            b |= 0x4000;
        } else if (a < -0x78) {
            b |= 0x1000;
        }
    }
    D_8013FBF8_801360F0[0].f_C = D_8013FBF8_801360F0[0].f_8 ^ b;
    D_8013FBF8_801360F0[0].f_8 = b;
    func_8013E8D0();
}

/* NOTE returns s32: src prototype void func_8013626C(s32, s32, s32); (line after the INCLUDE_ASM) must become s32 */
typedef struct { u8 pad0[0x14]; u8 f_14[6]; u8 f_1A[2]; u8 f_1C; u8 pad1D[0x1B]; } Pad_8013626C;
extern Pad_8013626C D_8013FBF8_8013626C[2] asm("D_8013FBF8");
void PadSetAct(s32, u8 *, s32);
s32 PadInfoMode(s32, s32, s32);
s32 PadSetMainMode(s32, s32, s32);
s32 PadInfoAct(s32, s32, s32);
s32 PadSetActAlign(s32, u8 *);

s32 func_8013626C(s32 mode, s32 i, s32 port_) {
    register s32 port asm("$20") = port_;
    Pad_8013626C *p;
    Pad_8013626C *q;
    s32 j;
    s32 n;
    s32 k;
    s32 r;

    if (mode == 0) {
        PadSetAct(port, D_8013FBF8_8013626C[i].f_1A, 2);
        for (j = 0; j < 6; j++) {
            D_8013FBF8_8013626C[i].f_14[j] = 0xFF;
        }
        D_8013FBF8_8013626C[i].f_1C = 0;
        return 0;
    }
    {
        Pad_8013626C *b = D_8013FBF8_8013626C;
        p = b + i;
    }
    if (!(p->f_1C & 1)) {
        if (PadInfoMode(port, 1, 0) != 7) {
            n = PadInfoMode(port, 4, -1);
            for (j = 0; j < n; j++) {
                if (PadInfoMode(port, 4, j) == 7) {
                    if (PadSetMainMode(port, j, 3)) {
                        p->f_1C = 1;
                    }
                    return 0;
                }
            }
            return -1;
        }
        if (PadSetMainMode(port, PadInfoMode(port, 3, 0), 3)) {
            p->f_1C = 1;
        }
        return 0;
    }
    n = PadInfoAct(port, -1, 0);
    j = 0;
    if (j < n) {
        s32 one = 1;
        s32 two = 2;
        q = p;
        do {
        k = PadInfoAct(port, j, 1);
        if (k == one) {
            r = PadInfoAct(port, j, 2);
            if (r != k) {
                if (r == two) {
                    q->f_14[0] = j;
                }
            } else {
                q->f_14[1] = j;
            }
        }
        } while (++j < n);
    }
    if (PadSetActAlign(port, D_8013FBF8_8013626C[i].f_14)) {
        D_8013FBF8_8013626C[i].f_1C |= 2;
    }
    return 0;
}

typedef struct { u8 pad0[0x1C]; u8 f_1C; u8 pad1D[0x1B]; } Pad_801364CC;
extern Pad_801364CC D_8013FBF8_801364CC[2] asm("D_8013FBF8");
s32 PadGetState(s32);

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

extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; u8 pad10[0xD]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_801365D0 asm("D_8013FBF8");
extern u8 D_8013EA90_801365D0[] asm("D_8013EA90");
extern u8 D_8013EAAC_801365D0[] asm("D_8013EAAC");
extern u8 D_8013EAB0_801365D0[] asm("D_8013EAB0");
extern u32 g_Game_801365D0 asm("g_Game");

void func_801365D0(void) {
    func_80138350(0);
    func_80138368(0x60, 0x3C, (M2C_UNK *)D_8013EA90_801365D0, 0x808080);
    if (D_8013FBF8_801365D0.f_1D == 0) {
        func_80138368(0x50, 0x7E, (M2C_UNK *)"PRESS", 0x808080);
        func_80138368(0x26, 0x8A, (M2C_UNK *)"START BUTTON", 0x808080);
    }
    func_80138350(1);
    func_80138368(0x108, 0x3C, (M2C_UNK *)D_8013EAAC_801365D0, 0x808080);
    if (D_8013FBF8_801365D0.f_55 == 0) {
        func_80138368(0xFC, 0x7E, (M2C_UNK *)"PRESS", 0x808080);
        func_80138368(0xD2, 0x8A, (M2C_UNK *)"START BUTTON", 0x808080);
    }
    if (g_Game_801365D0 & 0x20) {
        func_80138350(2);
        func_801384CC(0x78, 0xC8, (M2C_UNK *)D_8013EAB0_801365D0, 0x808080);
    }
}

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

extern struct { s32 frame; SprtTp *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_801369F4 asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; u8 pad10[0x32]; s16 f_42; u8 pad44[0x36]; s16 f_7A; } D_8013FBF8_801369F4 asm("D_8013FBF8");
/* these strings are shared with func_80136F30 */
const char D_8013EAC4[] = "SCORE RESET";
const char D_8013EAD0[] = "YES";
const char D_8013EAD4[] = "NO";
extern struct { u8 pad0[0x13A]; u16 f_13A; } D_800F4350_801369F4 asm("D_800F4350");
void func_8013609C(void);
M2C_UNK Sound_PlayFixed(M2C_UNK);
s32 Sound_SetStereo(s32);

void func_801369F4(void) {
    s32 sel;
    u32 pad;
    s32 c;
    register char *str asm("$6");
    s32 x, y, k;
    SprtTp *p;

    sel = 0;
    for (;;) {
        Gfx_BeginFrame();
        func_801360F0();
        func_801364CC();
        pad = (D_8013FBF8_801369F4.f_0 & D_8013FBF8_801369F4.f_4) | (D_8013FBF8_801369F4.f_8 & D_8013FBF8_801369F4.f_C);
        func_8008C390();
        p = g_Game_801369F4.prim;
        ((u8 *)p)[3] = 5;
        p->code = 0x65;
        p->x0 = 0x40;
        p->y0 = 0x18;
        p->w = 0x100;
        p->h = 0x6E;
        p->tpage = 0xE1000239;
        *(u16 *)&p->u0 = 0;
        p->clut = 0x3A37;
        { register u32 *ot asm("$4") = g_Game_801369F4.ot; ADD_PRIM_R(ot, p, "$5", "$2"); }
        g_Game_801369F4.prim = p + 1;
        func_80137934();
        if (pad & PAD_DOWN) {
            sel++;
            Sound_PlayFixed(0);
        }
        if (pad & PAD_UP) {
            sel--;
            Sound_PlayFixed(0);
        }
        if (sel >= 6) {
            sel = sel % 2 | 0x10;
            func_80138350(1);
            func_80138368(0x7E, 0x9E, (M2C_UNK *)D_8013EAC4, 0x808080);
            func_80138350(0);
            func_80138368(0xAE, 0xAC, (M2C_UNK *)D_8013EAD0, sel == 0x10 ? 0x808080 : 0x202020);
            k = 0x202020;
            if (sel == 0x11) {
                k = 0x808080;
            }
            x = 0xB4;
            str = D_8013EAD4;
            y = 0xBA;
        } else {
            sel = (sel + 5) % 5;
            func_80138350(0);
            c = sel == 0 ? 0x808080 : 0x202020;
            func_80138368(0x66, 0x94, (M2C_UNK *)"1P VIBRATION", c);
            func_80138368(0x10E, 0x94, (M2C_UNK *)(D_8013FBF8_801369F4.f_42 ? "ON" : "OFF"), c);
            c = sel == 1 ? 0x808080 : 0x202020;
            func_80138368(0x66, 0xA2, (M2C_UNK *)"2P VIBRATION", c);
            func_80138368(0x10E, 0xA2, (M2C_UNK *)(D_8013FBF8_801369F4.f_7A ? "ON" : "OFF"), c);
            c = sel == 2 ? 0x808080 : 0x202020;
            func_80138368(0x9C, 0xB0, (M2C_UNK *)(D_800F4350_801369F4.f_13A ? "STEREO" : " MONO "), c);
            func_80138368(0x7E, 0xBE, (M2C_UNK *)D_8013EAC4, sel == 3 ? 0x808080 : 0x202020);
            k = 0x202020;
            if (sel == 4) {
                k = 0x808080;
            }
            x = 0x9C;
            y = 0xCC;
            str = "RETURN";
        }
        func_80138368(x, y, (M2C_UNK *)str, k);
        DrawSync(0);
        VSync(0);
        PutDispEnv(&g_Game_801369F4.db[g_Game_801369F4.cur].env[0x5C]);
        PutDrawEnv(g_Game_801369F4.db[g_Game_801369F4.cur].env);
        DrawOTag(&g_Game_801369F4.db[g_Game_801369F4.cur].ot[0xFFF]);
        Cd_Update();
        switch (sel) {
        case 0:
            if (pad & 0xA060) {
                Sound_PlayFixed(0);
                D_8013FBF8_801369F4.f_42 ^= 1;
            }
            break;
        case 1:
            if (pad & 0xA060) {
                Sound_PlayFixed(0);
                D_8013FBF8_801369F4.f_7A ^= 1;
            }
            break;
        case 2:
            if (pad & 0xA860) {
                D_800F4350_801369F4.f_13A ^= 1;
                Sound_SetStereo(D_800F4350_801369F4.f_13A);
                Sound_PlayFixed(0);
            }
            break;
        case 3:
            if (pad & 0x860) {
                sel = 0x10;
                Sound_PlayFixed(0);
            }
            break;
        case 4:
            if (pad & 0x860) {
                Sound_PlayFixed(0xA5);
                return;
            }
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        case 0x10:
            if (pad & 0x860) {
                sel = 3;
                func_8013609C();
                Sound_PlayFixed(0x6C);
            }
            break;
        case 0x11:
            if (pad & 0x860) {
                Sound_PlayFixed(0xA5);
                sel = 3;
            }
            break;
        }
    }
}

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

extern u8 g_Game[];
typedef struct { s16 x; s16 y; s16 dy; s16 pad6; u32 col; } Star_80137934;
extern Star_80137934 *D_8013FC78;
extern u16 D_800AE8F2;
extern u16 g_RandSeed;
extern u8 *D_800EC354;
extern struct { u8 pad0[0x1D]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_80137934 asm("D_8013FBF8");
s32 func_800463A4(s32, s32, s32);
#define SPRT_80137934(tp, x, y, uv, clut, wh, A)                          \
    p[3] = 5;                                                          \
    M2C_FIELD(p, u32 *, 4) = tp;                                       \
    p[0xB] = 0x65;                                                     \
    M2C_FIELD(p, s16 *, 0xC) = x;                                      \
    M2C_FIELD(p, s16 *, 0xE) = y;                                      \
    M2C_FIELD(p, u32 *, 0x14) = wh;                                    \
    M2C_FIELD(p, u16 *, 0x10) = uv;                                    \
    M2C_FIELD(p, u16 *, 0x12) = clut;                                  \
    ADD_PRIM_R(&ot[0xFFF], p, A, "$2");              \
    p += 0x18;
#define ADD_PRIM_R2_80137934(ot, p, A, B) __asm__ volatile("lwl " A ", 2(%0)\n\tsll " B ", %2, 8\n\tswl " B ", 2(%3)\n\tswl " A ", %1" : : "r"(ot), "m"(*((u8 *)(p) + 2)), "r"(p), "r"(ot) : A, B)

void func_80137934(void) {
    u8 *p;
    Star_80137934 *st;
    s32 s;
    s32 t, y;
    s32 u, v;
    s32 i;
    u32 *ot;

    p = G_DRAW.prim;
    ot = G_DRAW.db[G_DRAW.cur].ot;
    st = D_8013FC78;
    s = D_8013EFE0;
    t = s >> 4;
    if (t > -0x100 && t < 0x100) {
        y = t + 0x80;
        SPRT_80137934(0xE10002AB, 0, y, 0, 0x3FA0, 0x800100, "$3");
        SPRT_80137934(0xE10002AD, 0x100, y, 0, 0x3FA0, 0x800080, "$3");
    }
    y = t - 0x280;
    if (t - 0x200 > 0) {
        if (y > 0) {
            y = 0;
        }
        SPRT_80137934(0xE10002A8, 0, y, 0, 0x3FE0, 0x800100, "$3");
        SPRT_80137934(0xE10002AA, 0x100, y, 0, 0x3FE0, 0x800080, "$3");
    }
    u = s >> 3;
    { s32 v1 = u - 0x40;
    if (u > 0 && u < 0x180) {
        SPRT_80137934(0xE1000229, 0x100, v1, 0x8040, 0x36B7, 0x400040, "$4");
    }
    }
    { s32 v2 = u - 0x130;
    if (u > 0xF0 && u < 0x270) {
        SPRT_80137934(0xE1000229, 0x20, v2, 0x8000, 0x3677, 0x400040, "$4");
    }
    }
    { s32 v3 = u - 0x220;
    if (u > 0x1D0 && u < 0x370) {
        SPRT_80137934(0xE100022A, 0x100, v3, 0x8000, 0x3737, 0x500050, "$4");
    }
    }
    { s32 v4 = u - 0x2C0;
    if (u > 0x280 && u < 0x400) {
        SPRT_80137934(0xE1000228, 0xC4, v4, 0x8060, 0x3777, 0x400040, "$4");
    }
    }
    { s32 v5 = u - 0x360;
    if (u > 0x320 && u < 0x4A0) {
        SPRT_80137934(0xE1000228, 0x20, v5, 0x80A0, 0x37B7, 0x400050, "$4");
    }
    }
    { s32 v6 = u - 0x420;
    if (u > 0x3C0 && u < 0x580) {
        SPRT_80137934(0xE1000228, 0x100, v6, 0x8000, 0x37F7, 0x600060, "$4");
    }
    }
    {
    for (i = 0; i < 0x40; i++, st++) {
        M2C_FIELD(p, u32 *, 4) = ((D_800AE8F2 = D_800AE8F2 * 5 + 1) << 8) | ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) | 0x808080;
        p[3] = 2;
        p[7] = 0x68;
        M2C_FIELD(p, u32 *, 8) = *(u32 *)st;
        ADD_PRIM_R2_80137934(&ot[0xFFF], p, "$3", "$2");
        p += 0xC;
        if ((st->y += st->dy) > 0xF0) {
            st->x = (D_800AE8F2 = D_800AE8F2 * 5 + 1) & 0x1FF;
            st->y = 0;
            st->dy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 3) + 1;
            st->col = ((g_RandSeed = g_RandSeed * 5 + 1) & 0xFF00) | 0xFF00FF;
        }
    }
    }
    p[3] = 3;
    M2C_FIELD(p, u32 *, 4) = 0;
    p[7] = 0x60;
    M2C_FIELD(p, s16 *, 0xC) = 0x180;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0xE) = 0xF0;
    ADD_PRIM_R(&ot[0xFFF], p, "$4", "$2");
    p += 0x10;
    D_800EC354 = p;
    if (D_8013FBF8_80137934.f_1D + D_8013FBF8_80137934.f_55 > 0) {
        s++;
    } else {
        s = func_800463A4(s, 0, 8);
    }
    if (s > 0x3840) {
        s = 0x3840;
    }
    D_8013EFE0 = s;
}

extern GameDraw g_Game_80137F50 asm("g_Game");
extern SprtTp *D_800EC354_80137F50 asm("D_800EC354");
extern u16 D_800AE8F2_80137F50 asm("D_800AE8F2");
extern u8 D_8013F048[];

void func_80137F50(s32 x, s32 y, u8 *s, s32 pal) {
    SprtTp *p;
    u32 *ot;
    u32 c;
    p = (SprtTp *)g_Game_80137F50.prim;
    c = *s;
    ot = g_Game_80137F50.ot;

    for (; c != 0; c = *s) {
        ((u8 *)&p->tag)[3] = 5;
        p->tpage = 0xE1000226;
        p->code = 0x67;
        D_800AE8F2_80137F50 = D_800AE8F2_80137F50 * 5 + 1;
        p->x0 = x;
        p->clut = (pal << 6) | 0x1B;
        p[1].clut = 0xDB;
        p->w = 16; p[1].w = 16;
        p->h = 16; p[1].h = 16;
        p->y0 = y - ((D_800AE8F2_80137F50 >> 8) & 1);
        p[1].u0 = p->u0 = (c & 0xF) << 4;
        p[1].v0 = p->v0 = c & 0xF0;
        ADD_PRIM_ASM_DW(ot, p);
        p++;
        ((u8 *)&p->tag)[3] = 5;
        p->code = 0x67;
        p->tpage = 0xE1000246;
        p->x0 = x + 2;
        D_800AE8F2_80137F50 = D_800AE8F2_80137F50 * 5 + 1;
        p->y0 = y - (((D_800AE8F2_80137F50 >> 8) & 1) - 2);
        ADD_PRIM_ASM(ot, p);
        p++;
        s++;
        x += D_8013F048[c];
    }
    D_800EC354_80137F50 = p;
}

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

typedef struct { s32 f_0; s16 f_4, f_6, f_8, f_A; } Pop_8013825C;
extern Pop_8013825C D_8013FC98_8013825C[6] asm("D_8013FC98");

void func_8013825C(s16 x, s16 y, s32 v, s32 c) {
    s32 i;
    Pop_8013825C *e;

    for (e = D_8013FC98_8013825C, i = 0; i < 6; i++, e++) {
        if (e->f_8 <= 0) {
            e->f_0 = v;
            e->f_4 = x;
            e->f_6 = y;
            e->f_8 = 0x3C;
            e->f_A = ((0xF1 - c) << 6) | 0x37;
            return;
        }
    }
}

extern struct { u16 f_0; } D_8013FC80_801382C0 asm("D_8013FC80");
typedef struct { s32 f_0; s16 f_4, f_6, f_8, f_A; } Pop_801382C0;
extern Pop_801382C0 D_8013FC98_801382C0[6] asm("D_8013FC98");

void func_801382C0(void) {
    s32 i;
    Pop_801382C0 *e;

    for (e = D_8013FC98_801382C0, i = 0; i < 6; i++, e++) {
        if (e->f_8 != 0) {
            e->f_8--;
            D_8013FC80_801382C0.f_0 = e->f_A;
            func_801384CC(e->f_4, e->f_6, (M2C_UNK *)e->f_0, 0x808080);
        }
    }
}

void func_80138350(s32 arg0) {
    D_8013FC80.f_0 = ((arg0 + 0xF0) << 6) | 0x37;
}

extern GameDraw g_Game_80138368 asm("g_Game");
typedef struct { u32 tag; u32 tpage; u32 col; s16 x, y; u8 u, v; u16 clut; s16 w, h; } Sprt_80138368;
extern Sprt_80138368 *D_800EC354_80138368 asm("D_800EC354");
extern struct { u16 f_0; } D_8013FC80_80138368 asm("D_8013FC80");

M2C_UNK func_80138368(M2C_UNK x, M2C_UNK y, M2C_UNK *str, M2C_UNK color) {
    Sprt_80138368 *p = (Sprt_80138368 *)g_Game_80138368.prim;
    u32 *ot = g_Game_80138368.ot;
    u32 c;

    for (; (c = *(u8 *)str) != 0; str = (M2C_UNK *)((u8 *)str + 1)) {
        switch (c) {
        case ' ':
            x += 12; continue;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            c -= 0x30;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
        case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
        case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
        case 'V': case 'W': case 'X': case 'Y': case 'Z':
            c -= 0x37;
            break;
        case 'a': case 'b': case 'c': case 'd':
            c -= 0x39;
            break;
        case '.':
            c = 0x24;
            break;
        case '?':
            c = 0x26;
            break;
        case '!':
            c = 0x27;
            break;
        }
        p->col = color;
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE1000239;
        ((u8 *)p)[0xB] = 0x64;
        p->x = x;
        p->y = y;
        p->u = (c % 10) * 12;
        p->v = (c / 10) * 12 + 0x88;
        p->w = 12;
        p->h = 12;
        p->clut = D_8013FC80_80138368.f_0;
        ADD_PRIM_ASM(ot, p);
        p++;
        x += 12;
    }
    D_800EC354_80138368 = p;
}

extern u8 *D_800EC354_801384CC asm("D_800EC354");
extern u16 D_8013FC80_801384CC asm("D_8013FC80");

void func_801384CC(s32 x, s32 y, u8 *str, u32 color) {
    u8 *p = G_DRAW.prim;
    u32 *ot = G_DRAW.ot;
    register u32 c asm("$8");

    for (; (c = *str) != 0; str++, x += 8) {
        switch (c) {
        case ' ':
            continue;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            c -= 0x30;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
        case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
        case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
        case 'V': case 'W': case 'X': case 'Y': case 'Z':
            c -= 0x36;
            break;
        case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28:
        case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F:
        case 0x3A: case 0x3B: case 0x3C: case 0x3D: case 0x3E: case 0x3F: case 0x40:
            break;
        }
        M2C_FIELD(p, u32 *, 8) = color;
        p[3] = 5;
        M2C_FIELD(p, u32 *, 4) = 0xE1000239;
        p[0xB] = 0x64;
        M2C_FIELD(p, s16 *, 0xC) = x;
        { register u32 lo asm("$2") = (c & 0xF) << 3; p[0x10] = lo; }
        M2C_FIELD(p, s16 *, 0xE) = y;
        { register u32 h asm("$2") = (c >> 4) * 8 + 0x70; p[0x11] = h; }
        M2C_FIELD(p, s16 *, 0x14) = 8;
        M2C_FIELD(p, s16 *, 0x16) = 8;
        M2C_FIELD(p, u16 *, 0x12) = D_8013FC80_801384CC;
        ADD_PRIM_ASM(ot, p);
        p += 0x18;
    }
    D_800EC354_801384CC = p;
}

typedef struct { u8 *a; u8 *b; u8 *c; u8 *d; } O_801385B8;

void func_801385B8(O_801385B8 *out, u8 *b) {
    out->a = b;
    out->b = b + 0x18;
    out->d = out->a + M2C_FIELD(out->a, u16 *, 0x10) * 4;
    out->c = out->a + M2C_FIELD(out->a, u16 *, 0x14) * 4;
}

typedef struct { u16 off; u16 hi; } Ofs_801385F4;
typedef struct { u8 pad0[0x18]; s32 *f_18; u8 pad1C[0x28]; s16 f_44; u8 pad46[2]; s16 f_48; u8 pad4A[6]; s32 f_50; u8 pad54[8]; s16 f_5C; s16 f_5E; u8 pad60[0x10]; s32 *f_70; } Mdl_801385F4;
typedef struct { u16 a; u16 b; } Pos_801385F4;
extern Mdl_801385F4 D_8013FD70_801385F4[] asm("D_8013FD70");
extern Mdl_801385F4 D_8013FE60_801385F4[] asm("D_8013FE60");
extern u8 D_80140200[][0x20];
extern Pos_801385F4 D_8013F148[];
typedef struct { s32 f_0; s32 f_4; s32 f_8; } Save_801385F4;
extern Save_801385F4 *D_8013FD60_801385F4 asm("D_8013FD60");
extern struct { u8 pad0[0x2C]; s32 f_2C; s32 f_30; } D_8013F3E0_801385F4 asm("D_8013F3E0");
extern struct { u8 pad0[0x8138]; u8 f_8138; } g_Game_801385F4 asm("g_Game");
extern struct { u8 pad0[0x42]; s16 f_42; u8 pad44[0x36]; s16 f_7A; } D_8013FBF8_801385F4 asm("D_8013FBF8");
void func_80015AC0(void *, void *);
void func_801385B8();
void Model_BindMesh(void *, void *);
Save_801385F4 *Minigame_GetSaveData(s32);
void bios_printf(u8 *, ...);

void func_801385F4(void) {
    Ofs_801385F4 *f = (Ofs_801385F4 *)0x80154000;
    s32 i;
    s32 *b;

    for (i = 0; i < 2; i++) {
        func_80015AC0(&D_8013FD70_801385F4[i], (u32 *)f + f[1 + i].off);
        D_8013FD70_801385F4[i].f_5C = 0;
        D_8013FD70_801385F4[i].f_5E = 0;
    }
    for (i = 0; i < 3; i++) {
        func_80015AC0(&D_8013FE60_801385F4[i], (u32 *)f + f[3 + i * 2].off);
        b = (s32 *)((u32)(f[4 + i * 2].off * 4) + (u32)f);
        D_8013FE60_801385F4[i].f_18 = b + *b + 1;
        D_8013FE60_801385F4[i].f_70 = (s32 *)f + f[4 + i * 2].off + 1;
        D_8013FE60_801385F4[i].f_5C = 0;
        D_8013FE60_801385F4[i].f_5E = 0;
        D_8013FE60_801385F4[i].f_48 = D_8013F148[i].a;
        D_8013FE60_801385F4[i].f_44 = D_8013F148[i].b;
        D_8013FE60_801385F4[i].f_50 = 0;
    }
    for (; i < 5; i++) {
        func_801385B8(&D_8013FE60_801385F4[i], (u32 *)f + f[6 + i].off);
        D_8013FE60_801385F4[i].f_48 = D_8013F148[i].a;
        D_8013FE60_801385F4[i].f_44 = D_8013F148[i].b;
        D_8013FE60_801385F4[i].f_50 = 1;
    }
    for (i = 0; i < 2; i++) {
        Model_BindMesh(D_80140200[i], (u32 *)f + f[0xB + i].off);
    }
    D_8013FD60_801385F4 = Minigame_GetSaveData(2);
    if (D_8013FD60_801385F4->f_0 == 0) {
        bios_printf("Garaxy Data Init.\n");
        D_8013FD60_801385F4->f_0 = 1;
        func_8013609C();
    }
    if (g_Game_801385F4.f_8138) {
        D_8013FBF8_801385F4.f_42 = 1;
        D_8013FBF8_801385F4.f_7A = 1;
    }
    D_8013F3E0_801385F4.f_2C = D_8013FD60_801385F4->f_4;
    D_8013F3E0_801385F4.f_30 = D_8013FD60_801385F4->f_8;
}

extern struct { void *p[2]; s32 f_8; s32 f_C; s32 f_10; } D_8013FBD8_80138860 asm("D_8013FBD8");
extern u8 D_8013FD70_80138860[] asm("D_8013FD70");
void func_8013C7F0(void);

void func_80138860(void) {
    s32 i;

    {
        s32 *q;
        D_8013FBD8_80138860.f_8 = 0;
        D_8013FBD8_80138860.f_C = 0;
        D_8013FBD8_80138860.f_10 = 0xA40;
        q = &D_8013FBD8_80138860.f_8;
        for (i = 1; i >= 0; i--) {
            D_8013FBD8_80138860.p[i] = q;
        }
    }
    func_8013A29C();
    func_80139480();
    func_801394A4();
    func_80069500();
    Fx_ClearAll();
    func_8013C7F0();
    i = 0;
    do {
        register u8 *e asm("$2") = D_8013FD70_80138860;
        i++;
        M2C_FIELD(e, s32 *, 0x24) = 0;
        M2C_FIELD(e, s32 *, 0x28) = 0;
        M2C_FIELD(e, s32 *, 0x2C) = 0xA40;
        M2C_FIELD(e, s16 *, 0x5C) = 0;
        M2C_FIELD(e, s16 *, 0x5E) = 0;
        M2C_FIELD(e, s16 *, 0x60) = 0;
        M2C_FIELD(e, s16 *, 0x62) = -0x1000;
        M2C_FIELD(e, s16 *, 0x64) = 0;
        M2C_FIELD(e, s16 *, 0x68) = 0;
        M2C_FIELD(e, s16 *, 0x6A) = 0;
        M2C_FIELD(e, s16 *, 0x6C) = 0x1000;
    } while (i < 2);
}

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
void func_801389E4(void);
void func_80139888();
void func_80139BF8();
void func_8013B4B4(void);
void func_8013B890(void);
void func_8013B92C();
void func_80138934(void);
void func_8013A548();
void func_80139A74();
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

extern GameDraw g_Game_80138FD4 asm("g_Game");

void func_80138FD4(s16 x, s16 y, s16 w, s16 h) {
    u8 *p = g_Game_80138FD4.prim;

    M2C_FIELD(p, u32 *, 4) = 0x8000;
    p[3] = 7;
    p[7] = 0x4C;
    M2C_FIELD(p, s16 *, 0xC) = x + w;
    M2C_FIELD(p, s16 *, 0x10) = x + w;
    M2C_FIELD(p, u32 *, 0x1C) = 0x55555555;
    M2C_FIELD(p, s16 *, 0x8) = x;
    M2C_FIELD(p, s16 *, 0xA) = y;
    M2C_FIELD(p, s16 *, 0x18) = x;
    M2C_FIELD(p, s16 *, 0x1A) = y;
    M2C_FIELD(p, s16 *, 0xE) = y;
    M2C_FIELD(p, s16 *, 0x12) = y + h;
    M2C_FIELD(p, s16 *, 0x14) = x;
    M2C_FIELD(p, s16 *, 0x16) = y + h;
    {
        register u32 *o asm("$8") = g_Game_80138FD4.ot;
        ADD_PRIM_R(o, p, "$9", "$3");
    }
    p += 0x20;
    p[3] = 3;
    M2C_FIELD(p, u32 *, 4) = 0;
    p[7] = 0x60;
    M2C_FIELD(p, s16 *, 0x8) = x;
    M2C_FIELD(p, s16 *, 0xA) = y;
    M2C_FIELD(p, s16 *, 0xC) = w;
    M2C_FIELD(p, s16 *, 0xE) = h;
    {
        register u32 *o asm("$4") = g_Game_80138FD4.ot;
        ADD_PRIM_R(o, p, "$5", "$3");
    }
    p += 0x10;
    g_Game_80138FD4.prim = p;
}

extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80139098 asm("g_Game");
extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; } D_8013FBF8_80139098 asm("D_8013FBF8");
extern struct { u8 pad0[0x20]; s16 f_20; s16 f_22; } D_8013F3E0_80139098 asm("D_8013F3E0");
extern char D_8013EB94[];
typedef struct { s16 x, y, w, h; } Rect_80139098;
void SetDrawMove(void *p, void *rect, s32 x, s32 y);

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

typedef struct { s16 x, z, f_4; u8 f_6, f_7; s16 dx, dz; } Spark_801394C8;
extern Spark_801394C8 *D_8013FCE4_801394C8 asm("D_8013FCE4");
extern s32 D_8013F3F0;

void func_801394C8(s16 *pos, s16 *vel, s32 kind) {
    s32 i;
    s32 n;
    Spark_801394C8 *e;

    e = D_8013FCE4_801394C8;
    n = (D_8013F3F0 << 5) / 100;
    if (n > 32) {
        n = 32;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->f_7 == 0) {
            *(s32 *)&e->dx = *(s32 *)vel;
            e->f_7 = 1;
            e->f_6 = kind;
            e->x = pos[0];
            e->z = pos[2];
            e->f_4 = 0xA40;
            e->dx = vel[0];
            e->dz = vel[1];
            if (vel[0] == 0 && vel[1] == 0) {
                e->dz = 0x1000;
            }
            return;
        }
    }
}

INCLUDE_ASM("asm/ovl/427/nonmatchings/427_minigame_menu", func_801395B8);

typedef struct { s16 x, z, f_4; u8 f_6, f_7; s32 vel; } Spark_8013966C;
extern Spark_8013966C *D_8013FCE0_8013966C asm("D_8013FCE0");

void func_8013966C(s16 *base, s16 *vel, s32 kind) {
    s32 i;
    Spark_8013966C *e;

    for (e = D_8013FCE0_8013966C, i = 0; i < 24; i++, e++) {
        if (e->f_7 == 0) {
            e->vel = *(s32 *)vel;
            e->f_7 = 1;
            e->f_6 = kind;
            e->x = base[0] + (vel[0] >> 5);
            e->z = base[2] + (vel[1] >> 5);
            e->f_4 = 0xA40;
            return;
        }
    }
}

void func_8013966C(s16 *base, s16 *vel, s32 kind);

void func_801396F4(s32 *p, s16 *s, s32 c) {
    s32 *w = (s32 *)0x1F800000;
    s32 x0 = p[0];
    s32 h0 = s[1] >> 6;
    s32 x1, h1;

    w[0x10] = x0 - h0;
    w[0x14] = x0 + h0;
    x1 = p[1];
    h1 = s[0] >> 6;
    w[0x11] = x1 + h1;
    w[0x15] = x1 - h1;
    func_8013966C((s16 *)0x1F800040, s, c);
    func_8013966C((s16 *)0x1F800050, s, c);
}

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

extern s32 *D_8013FBD8_8013A6CC[] asm("D_8013FBD8");
extern s32 D_8013FBE0_8013A6CC[] asm("D_8013FBE0");
extern s32 D_8013FD94_8013A6CC[] asm("D_8013FD94");
extern s32 D_8013FE08_8013A6CC[] asm("D_8013FE08");
extern struct { u8 pad0[0x1D]; u8 f_1D; u8 pad1E[0x37]; u8 f_55; } D_8013FBF8_8013A6CC asm("D_8013FBF8");

void func_8013A6CC(void) {
    s32 i = 0;
    s32 *t = D_8013FBE0_8013A6CC;

    if (D_8013FBF8_8013A6CC.f_1D != 0) {
        t = D_8013FD94_8013A6CC;
        D_8013FBD8_8013A6CC[0] = t;
        i = 1;
    }
    if (D_8013FBF8_8013A6CC.f_55 != 0) {
        t = D_8013FE08_8013A6CC;
        D_8013FBD8_8013A6CC[i] = t;
        i++;
    }
    for (; i < 2; i++) {
        D_8013FBD8_8013A6CC[i] = t;
    }
}

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

extern struct { u8 pad0[0x1D]; u8 f_1D; u8 pad1E[0x1A]; u32 f_38; u8 pad3C[4]; s16 f_40; u8 pad42[0x13]; u8 f_55; u8 pad56[0x1A]; u32 f_70; u8 pad74[4]; s16 f_78; } D_8013FBF8_8013B14C asm("D_8013FBF8");
extern struct { u8 pad0[0x28]; s32 f_28; } D_8013F3E0_8013B14C asm("D_8013F3E0");
void func_8013B444_8013B14C() asm("func_8013B444");

void func_8013B14C(void) {
    u8 *buf = (u8 *)0x1F800000;
    u32 q;
    s32 sq;
    u32 v;
    s32 hi;
    s32 i;

    if (D_8013FBF8_8013B14C.f_38 > 99999999) {
        D_8013FBF8_8013B14C.f_38 = 99999999;
    }
    if (D_8013FBF8_8013B14C.f_70 > 99999999) {
        D_8013FBF8_8013B14C.f_70 = 99999999;
    }
    func_80138350(0);
    v = D_8013FBF8_8013B14C.f_38;
    buf[8] = 0;
    if (D_8013F3E0_8013B14C.f_28 < v) {
        D_8013F3E0_8013B14C.f_28 = v;
    }
    for (i = 7; i >= 0; i--) {
        q = v % 10;
        buf[i] = q + '0';
        v /= 10;
    }
    func_80138368(0x10, 0x1A, (M2C_UNK *)buf, 0x808080);
    func_80138350(1);
    func_801384CC(0x22, 0x12, (M2C_UNK *)"PLAYER 1", 0x808080);
    func_80138350(1);
    v = D_8013FBF8_8013B14C.f_70;
    buf[8] = 0;
    if (D_8013F3E0_8013B14C.f_28 < v) {
        D_8013F3E0_8013B14C.f_28 = v;
    }
    for (i = 7; i >= 0; i--) {
        q = v % 10;
        buf[i] = q + '0';
        v /= 10;
    }
    func_80138368(0x106, 0x1A, (M2C_UNK *)buf, 0x808080);
    func_80138350(0);
    func_801384CC(0x118, 0x12, (M2C_UNK *)"PLAYER 2", 0x808080);
    func_80138350(2);
    hi = D_8013F3E0_8013B14C.f_28;
    for (i = 7; i >= 0; i--) {
        sq = hi % 10;
        buf[i] = sq + '0';
        hi /= 10;
    }
    func_80138368(0x90, 0x1A, (M2C_UNK *)buf, 0x808080);
    func_801384CC(0x98, 0x12, (M2C_UNK *)"HIGH SCORE", 0x808080);
    if (D_8013FBF8_8013B14C.f_1D != 0) {
        for (i = 0; i < D_8013FBF8_8013B14C.f_40; i++) {
            func_8013B444_8013B14C(0x10 + i * 0x18, 0x24);
        }
    }
    if (D_8013FBF8_8013B14C.f_55 != 0) {
        for (i = 0; i < D_8013FBF8_8013B14C.f_78; i++) {
            func_8013B444_8013B14C(0x150 - i * 0x18, 0x24);
        }
    }
}

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

typedef struct { s16 x, z, y, kind, dx, dz; } Shot_8013B8B8;
extern Shot_8013B8B8 D_8013FCF0_8013B8B8[] asm("D_8013FCF0");

void func_8013B8B8(s32 kind, s16 *pos, s16 *dir) {
    s32 i;
    Shot_8013B8B8 *e;

    for (i = 0; i < 5; i++) {
        e = &D_8013FCF0_8013B8B8[i];
        if (e->kind == 0) {
            e->kind = kind;
            e->x = pos[0];
            e->z = pos[2];
            e->y = 0xA40;
            e->dx = -dir[0];
            e->dz = -dir[1];
            return;
        }
    }
}

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

extern struct { u32 frame; u8 *prim; u32 *ot; } g_Game_8013D1F0 asm("g_Game");
extern struct { s16 x, y; s32 state; s16 x2, y2; } D_8013FD30_8013D1F0 asm("D_8013FD30");
extern struct { u8 pad_0[0x6]; s16 f_6; u8 pad_8[0x4]; } D_8013FCF0_8013D1F0[] asm("D_8013FCF0");
s32 rsin(s32 a);

void func_8013D1F0(void) {
    u8 *p = g_Game_8013D1F0.prim;
    s32 i;
    s32 j;
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    register s32 k asm("$4");

    if (D_8013FD30_8013D1F0.state != 0) {
        x = D_8013FD30_8013D1F0.x;
        y = D_8013FD30_8013D1F0.y;
        for (j = 0; j < 3; j++) {
            s = rsin((g_Game_8013D1F0.frame + j * 2) << 5) >> 7;
            c = rcos((g_Game_8013D1F0.frame + j * 2) << 5) >> 7;
            k = 0x55555555;
            {
                register s32 r asm("$3") = 7;
                p[3] = r;
            }
            M2C_FIELD(p, s32 *, 4) = 0x4000 + j * 0x2000;
            {
                register s32 r asm("$3") = 0x4C;
                p[7] = r;
            }
            M2C_FIELD(p, s16 *, 0x8) = x + c;
            M2C_FIELD(p, s16 *, 0x18) = x + c;
            M2C_FIELD(p, s16 *, 0xA) = y + s;
            M2C_FIELD(p, s16 *, 0x1A) = y + s;
            M2C_FIELD(p, s16 *, 0xC) = x - s;
            M2C_FIELD(p, s16 *, 0xE) = y + c;
            M2C_FIELD(p, s16 *, 0x10) = x - c;
            M2C_FIELD(p, s16 *, 0x12) = y - s;
            M2C_FIELD(p, s32 *, 0x1C) = k;
            M2C_FIELD(p, s16 *, 0x14) = x + s;
            M2C_FIELD(p, s16 *, 0x16) = y - c;
            p[7] |= 2;
            {
                register u32 *o asm("$3") = g_Game_8013D1F0.ot;
                ADD_PRIM_R(o, p, "$4", "$2");
            }
            p += 0x20;
        }
    }
    g_Game_8013D1F0.prim = p;
    if (g_Game_8013D1F0.frame > 0x680) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            if (D_8013FCF0_8013D1F0[0].f_6 == 0) {
                continue;
            }
            x = D_8013FD30_8013D1F0.x2;
            y = D_8013FD30_8013D1F0.y2;
        } else {
            y = 0xBE;
            x = 0xEC;
            if (i == 0) {
                x = 0x94;
            }
        }
        M2C_FIELD(p, s32 *, 4) = 0xA000;
        p[3] = 3;
        p[7] = 0x42;
        if (i == 1) {
            M2C_FIELD(p, s16 *, 0x8) = x + 0x20;
        } else {
            M2C_FIELD(p, s16 *, 0x8) = x - 0x20;
        }
        M2C_FIELD(p, s16 *, 0xA) = y - 0x20;
        M2C_FIELD(p, s16 *, 0xC) = x;
        M2C_FIELD(p, s16 *, 0xE) = y;
        {
            register u32 *o asm("$3") = g_Game_8013D1F0.ot;
            ADD_PRIM_R(o, p, "$4", "$2");
        }
        p += 0x10;
    }
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000220;
    {
        register u32 *o asm("$4") = g_Game_8013D1F0.ot;
        ADD_PRIM_R(o, p, "$5", "$2");
    }
    p += 8;
    g_Game_8013D1F0.prim = p;
    func_80138350(2);
    func_80138368(0x40, 0x94, (M2C_UNK *)"MOVE", 0x808080);
    func_80138368(0x1C, 0x88, (M2C_UNK *)"LEFT STICK", 0x808080);
    func_80138368(0x10E, 0x94, (M2C_UNK *)"SHOOT", 0x808080);
    func_80138368(0xEA, 0x88, (M2C_UNK *)"RIGHT STICK", 0x808080);
    if (D_8013FD30_8013D1F0.state == 3 && D_8013FCF0_8013D1F0[0].f_6 != 0) {
        func_80138368(x - 0x40, y - 0x2C, (M2C_UNK *)"POWER UP", 0x808080);
    }
}

typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x30]; s16 r[3]; u8 pad66[2]; s16 s[3]; u8 pad6E[0x6]; } Mdl_8013D528;
extern Mdl_8013D528 D_8013FD70_8013D528[] asm("D_8013FD70");
extern s8 D_8013FC15;

void func_8013D528(void) {
    D_8013FC15 = 3;
    D_8013FD70_8013D528[0].z = 0xA40;
    D_8013FD70_8013D528[0].r[1] = 0x1000;
    D_8013FD70_8013D528[0].s[2] = 0x1000;
    D_8013FD70_8013D528[0].x = 0;
    D_8013FD70_8013D528[0].y = 0;
    D_8013FD70_8013D528[0].r[0] = 0;
    D_8013FD70_8013D528[0].r[2] = 0;
    D_8013FD70_8013D528[0].s[0] = 0;
    D_8013FD70_8013D528[0].s[1] = 0;
    D_8013F402 = 1;
}

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

void func_8013DEFC(s32 n, s8 *buf) {
    s32 i;
    s32 d;

    buf[8] = 0;
    for (i = 7; i >= 0; i--) {
        d = n % 10;
        n /= 10;
        if (d == 0 && n == 0 && i != 7) {
            buf[i] = ' ';
        } else {
            buf[i] = d + '0';
        }
    }
}

void func_8013DF7C(void) {
    D_8013FD40 = 0;
}

extern struct { u32 f_0; u32 f_4; u32 f_8; u32 f_C; u8 pad10[0x28]; s32 f_38; s32 f_3C; s16 f_40; u8 pad42[0x2E]; s32 f_70; s32 f_74; s16 f_78; } D_8013FBF8_8013DF88 asm("D_8013FBF8");
extern struct { s16 f_0; s16 pad2; s32 f_4; s32 f_8; s32 f_C; s32 f_10; } D_8013FD40_8013DF88 asm("D_8013FD40");
extern struct { u8 pad0[0x24]; s32 f_24; } D_8013F3E0_8013DF88 asm("D_8013F3E0");
extern s32 g_Game_8013DF88 asm("g_Game");
extern s32 D_8013FC6C;
extern s32 D_8013F404;
extern u8 D_8013EFA0[];
extern u8 D_8013EFA8[];
extern u8 D_8013EFAC[];
extern u8 D_8013EFB4[];
extern u8 D_8013EA90_8013DF88[] asm("D_8013EA90");
extern u8 D_8013EAAC_8013DF88[] asm("D_8013EAAC");
void func_8013B444(s16 x, s16 y);
void func_8013DEFC(s32 n, s8 *buf);
M2C_UNK func_8013E940(s32 x, s32 y, s32 n);
#define P_8013DF88 D_8013FBF8_8013DF88
#define T_8013DF88 D_8013FD40_8013DF88

s32 func_8013DF88(void) {
    u32 pad;
    s32 snd;
    s32 done;
    s32 n;
    u8 *buf;
    u8 *q1;
    u8 *q2;

    done = 1;
    buf = (u8 *)SCRATCH;
    pad = (P_8013DF88.f_0 & P_8013DF88.f_4) | (P_8013DF88.f_8 & P_8013DF88.f_C);
    if (T_8013DF88.f_0 == 0) {
        T_8013DF88.f_4 = P_8013DF88.f_40 * 10000;
        T_8013DF88.f_C = P_8013DF88.f_78 * 10000;
        T_8013DF88.f_8 = P_8013DF88.f_3C * 1000;
        T_8013DF88.f_10 = P_8013DF88.f_74 * 1000;
    }
    if (g_Game_8013DF88 & 0x20) {
        func_8013DAF0(0xC8, 0xCA);
    }
    if (T_8013DF88.f_0 < 0x7BC) {
        func_80138350(2);
        func_80138368(0xA2, 0x34, (M2C_UNK *)D_8013EFA0, 0x808080);
        n = P_8013DF88.f_3C;
        if (n < 10) {
            buf[0] = n + '0';
            buf[1] = 0;
        } else {
            buf[2] = 0;
            buf[0] = n / 10 + '0';
            buf[1] = n % 10 + '0';
        }
        n = D_8013FC6C;
        if (n < 10) {
            buf[5] = n + '0';
            buf[6] = 0;
        } else {
            buf[7] = 0;
            buf[5] = n / 10 + '0';
            buf[6] = n % 10 + '0';
        }
        buf[0xB] = 0;
        buf[0x15] = 0;
        buf[0xA] = (u8)P_8013DF88.f_40 + '0';
        buf[0x14] = (u8)P_8013DF88.f_78 + '0';
        q1 = buf + 0x1E;
        func_8013DEFC(T_8013DF88.f_4, (s8 *)q1);
        func_8013DEFC(T_8013DF88.f_C, (s8 *)(buf + 0x28));
        q2 = buf + 0x32;
        func_8013DEFC(T_8013DF88.f_8, (s8 *)q2);
        func_8013DEFC(T_8013DF88.f_10, (s8 *)(buf + 0x3C));
        snd = 0;
        if (D_8013F404 & 1) {
            func_80138350(0);
            func_80138368(0xB4, 0x4A, (M2C_UNK *)D_8013EA90_8013DF88, 0x808080);
            func_80138350(2);
            func_8013B444(0x50, 0x54);
            func_801384CC(0x70, 0x64, (M2C_UNK *)D_8013EFA8, 0x808080);
            func_80138368(0x50, 0x76, (M2C_UNK *)D_8013EFAC, 0x808080);
            func_80138368(0x80, 0x60, (M2C_UNK *)(buf + 0xA), 0x808080);
            func_80138368(0x98, 0x76, (M2C_UNK *)buf, 0x808080);
            func_80138368(0xDC, 0x60, (M2C_UNK *)q1, 0x808080);
            func_80138368(0xDC, 0x76, (M2C_UNK *)q2, 0x808080);
            if (T_8013DF88.f_0 > 0xB4) {
                if (pad & 0x860) {
                    P_8013DF88.f_38 += T_8013DF88.f_4 + T_8013DF88.f_8;
                    T_8013DF88.f_4 = 0;
                    T_8013DF88.f_8 = 0;
                }
                if (T_8013DF88.f_4 > 0) {
                    snd = 1;
                    done = 0;
                    T_8013DF88.f_4 -= 100;
                    P_8013DF88.f_38 += 100;
                }
                if (T_8013DF88.f_8 > 0) {
                    snd = 1;
                    done = 0;
                    T_8013DF88.f_8 -= 100;
                    P_8013DF88.f_38 += 100;
                }
            } else {
                done = 0;
            }
        }
        if (D_8013F404 & 2) {
            func_80138350(1);
            func_80138368(0xB4, 0x8C, (M2C_UNK *)D_8013EAAC_8013DF88, 0x808080);
            func_80138350(2);
            func_8013B444(0x50, 0x96);
            func_801384CC(0x70, 0xA6, (M2C_UNK *)D_8013EFA8, 0x808080);
            func_80138368(0x50, 0xB8, (M2C_UNK *)D_8013EFAC, 0x808080);
            func_80138368(0x80, 0xA2, (M2C_UNK *)(buf + 0x14), 0x808080);
            func_80138368(0x98, 0xB8, (M2C_UNK *)(buf + 5), 0x808080);
            func_80138368(0xDC, 0xA2, (M2C_UNK *)(buf + 0x28), 0x808080);
            func_80138368(0xDC, 0xB8, (M2C_UNK *)(buf + 0x3C), 0x808080);
            if (T_8013DF88.f_0 > 0xB4) {
                if (pad & 0x60) {
                    P_8013DF88.f_70 += T_8013DF88.f_C + T_8013DF88.f_10;
                    T_8013DF88.f_C = 0;
                    T_8013DF88.f_10 = 0;
                }
                if (T_8013DF88.f_C > 0) {
                    snd = 1;
                    done = 0;
                    T_8013DF88.f_C -= 100;
                    P_8013DF88.f_70 += 100;
                }
                if (T_8013DF88.f_10 > 0) {
                    snd = 1;
                    done = 0;
                    T_8013DF88.f_10 -= 100;
                    P_8013DF88.f_70 += 100;
                }
            } else {
                done = 0;
            }
        }
        if (snd && (T_8013DF88.f_0 & 1)) {
            Sound_PlayFixed(1);
        }
        if (done && T_8013DF88.f_0 < 0x708) {
            T_8013DF88.f_0 = 0x708;
        }
        if (T_8013DF88.f_0++ > 0x708) {
            if (D_8013F3E0_8013DF88.f_24 & 1) {
                P_8013DF88.f_38 += T_8013DF88.f_4 + T_8013DF88.f_8;
                T_8013DF88.f_4 = 0;
                T_8013DF88.f_8 = 0;
            }
            if (D_8013F3E0_8013DF88.f_24 & 2) {
                P_8013DF88.f_70 += T_8013DF88.f_C + T_8013DF88.f_10;
                T_8013DF88.f_C = 0;
                T_8013DF88.f_10 = 0;
            }
            if (pad & 0x60) {
                T_8013DF88.f_0 = 0x7BC;
            }
        }
    } else {
        func_80138350(2);
        func_80138368(0xA2, 0x34, (M2C_UNK *)D_8013EFB4, 0x808080);
        if (D_8013F3E0_8013DF88.f_24 & 1) {
            func_80138350(0);
            func_80138368(0xB4, 0x4A, (M2C_UNK *)D_8013EA90_8013DF88, 0x808080);
            func_8013E940(0x66, 0x62, P_8013DF88.f_38);
        }
        if (D_8013F3E0_8013DF88.f_24 & 2) {
            func_80138350(1);
            func_80138368(0xB4, 0x8C, (M2C_UNK *)D_8013EAAC_8013DF88, 0x808080);
            func_8013E940(0x66, 0xA4, P_8013DF88.f_70);
        }
        if (pad & 0x60) {
            return 1;
        }
    }
    return 0;
}

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

void func_8013CA94(s32 digit, s32 x, s32 y, s32 sh);

M2C_UNK func_8013E940(s32 x, s32 y, s32 n) {
    s32 i;
    s32 d;

    x += 0x90;
    for (i = 7; i >= 0; i--) {
        d = n % 10;
        n /= 10;
        func_8013CA94(d, x, y, 2);
        x -= 0x12;
    }
}

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
