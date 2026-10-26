#include "common.h"
#include "m2c_macros.h"

INCLUDE_RODATA("asm/ovl/386/nonmatchings/386_title_menu", D_801376F0);

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern struct { u32 frame; SprtTp *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x32]; u16 f_815A; u16 f_815C; } g_Game_80136000 asm("g_Game");
extern struct { u8 pad0[0x1C]; s32 f1C; u8 pad20[4]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_80136000 asm("D_800EBFA0");
extern u8 D_80137828[];
extern s32 D_80137810;
extern s16 D_80137818;
extern s16 D_8013781A;
extern s16 D_8013781C;
extern s32 D_800A8A58;
s32 Gfx_InitDisplay(void);
void Game_NewGameReset(void);
void func_8002FAF0(s32);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_80011194(void *);
s32 func_800116C0(void);
void Cd_Update(void);
void func_80136AC0(u8 *b);
void func_80069500(void);
void Stage_ApplyFog(void);
void Light_SetColorMode(s32, s32, s32, s32);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void func_8008C390(void);
s32 func_801374E4(void);
s32 func_80136C5C(void);
void func_8008760C(void);
void func_8013674C(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);
void Sound_UnloadBanks(s32);
void Stage_ResetActors(s32);
s32 Cd_StartFileLoad(s32, s32);

s32 func_80136000(void) {
    Rect_80136000 r;
    SprtTp *p;
    u32 *ot;
    s32 res;
    s32 v;
    u8 c;
    s32 n;

    r.x = 0;
    r.y = 0;
    r.w = 0x180;
    r.h = 0x200;
    Gfx_InitDisplay();
    Game_NewGameReset();
    func_8002FAF0(0x148);
    ClearImage(&r, 0xFF, 0xFF, 0xFF);
    DrawSync(0);
    g_Game_80136000.db[1].env[0x18] = 1;
    g_Game_80136000.db[0].env[0x18] = 1;
    g_Game_80136000.cur = 0;
    func_80011194(D_80137828);
    while (func_800116C0() >= 0) {
        Cd_Update();
        VSync(2);
    }
    func_80136AC0((u8 *)0x80154000);
    func_80069500();
    D_800EBFA0_80136000.f24 = 0xF000;
    D_800EBFA0_80136000.f28 = 0x600;
    D_800EBFA0_80136000.f2C = 0x4000;
    D_800EBFA0_80136000.f1C = 0;
    Stage_ApplyFog();
    Light_SetColorMode(0, 0, 0, 0);
    D_80137810 = 0;
    D_8013781A = 0x1E;
    D_8013781C = 0;
    D_80137818 = 0;
    D_800A8A58 = 0;
    while (func_8001325C(2), Gfx_BeginFrame(), func_8008C390(), func_801374E4() >= 0) {
        v = func_80136C5C();
        if (v < 0 && D_80137818 == 1) {
            res = v;
            if (res == -3) {
                D_80137818 = 3;
            } else {
                D_80137818 = 2;
            }
        }
        D_8013781C++;
        if (D_80137818 == 1 && D_8013781C >= 0x709) {
            res = -9;
            D_80137818 = 2;
            func_8008760C();
        }
        p = g_Game_80136000.prim;
        ot = g_Game_80136000.db[g_Game_80136000.cur].ot;
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE1000229;
        p->code = 0x65;
        *(u32 *)&p->x0 = 0xC80040;
        *(u32 *)&p->w = 0x100100;
        *(u16 *)&p->u0 = 0x8000;
        p->clut = 0x3CB7;
        ADD_PRIM_R(ot, p, "$5", "$2");
        p++;
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE10002A9;
        p->code = 0x65;
        *(u32 *)&p->x0 = 0x180040;
        *(u32 *)&p->w = 0x800100;
        *(u16 *)&p->u0 = 0;
        p->clut = 0x3F98;
        ADD_PRIM_R(ot, p, "$5", "$2");
        p++;
        g_Game_80136000.prim = p;
        func_8013674C();
        DrawSync(0);
        VSync(2);
        g_Game_80136000.frame++;
        PutDispEnv(&g_Game_80136000.db[g_Game_80136000.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136000.db[g_Game_80136000.cur].env);
        DrawOTag(&g_Game_80136000.db[g_Game_80136000.cur].ot[0xFFF]);
    }
    DrawSync(0);
    VSync(0);
    Sound_UnloadBanks(1);
    if (res == -3) {
        ClearImage(&r, 0xFF, 0xFF, 0xFF);
    } else {
        ClearImage(&r, 0, 0, 0);
    }
    DrawSync(0);
    switch (res) {
    case -1:
        g_Game_80136000.mode = 0xD;
        break;
    case -2:
        g_Game_80136000.mode = 0xB;
        break;
    case -3:
        g_Game_80136000.mode = 0x1A;
        g_Game_80136000.f_815A = 0;
        break;
    case -4:
        g_Game_80136000.mode = 6;
        break;
    case -5:
        g_Game_80136000.mode = 5;
        break;
    case -6:
        g_Game_80136000.mode = 0xE;
        break;
    case -8:
        g_Game_80136000.mode = 0x1B;
        break;
    case -9:
        n = g_Game_80136000.f_815C + 1;
        n %= 5;
        g_Game_80136000.stage = n + 0x63;
        g_Game_80136000.mode = 0x24;
        g_Game_80136000.f_815C = n;
        Stage_ResetActors(g_Game_80136000.stage);
        Cd_StartFileLoad(1, g_Game_80136000.stage);
        while (func_800116C0() == 0) {
            Cd_Update();
            VSync(2);
        }
        break;
    case -10:
        g_Game_80136000.mode = 0x22;
        break;
    case -7:
        break;
    }
    return 0;
}

typedef struct { s16 vx, vy, vz, pad; } SVec_8013654C;
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013654C;
extern Mat_8013654C D_800E78C0_8013654C asm("D_800E78C0");
extern u32 D_80137848;
extern u8 D_80137960_8013654C[] asm("D_80137960");
extern u8 D_800E7D00_8013654C[] asm("D_800E7D00");
extern u8 *D_800EC354;
extern struct { u8 frame; } g_Game_8013654C asm("g_Game");
#define GD_8013654C (*(GameDraw *)&g_Game_8013654C)
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
void func_80016294(void *, void *);
void func_80017EFC(void *, void *, void *, s32);

void func_8013654C(void) {
    SVec_8013654C *pos = (SVec_8013654C *)0x1F8003C8;
    s32 i, j;
    s32 z;
    s16 y;
    u8 *p;
    s32 f;

    SetRotMatrix(&D_800E78C0_8013654C);
    SetTransMatrix(&D_800E78C0_8013654C);
    D_80137848 += 0x40;
    if (D_80137848 > 0x400) {
        D_80137848 -= 0x400;
    }
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            pos->vx = i * 0x400 - 0x2000;
            pos->vy = 0;
            pos->vz = D_80137848 + (j * 0x400 + 0xE000);
            func_80016294(D_80137960_8013654C, D_800E7D00_8013654C);
            func_80017EFC(GD_8013654C.ot + 0x40, D_800E7D00_8013654C, D_80137960_8013654C, 0);
        }
    }
    p = D_800EC354;
    z = 8 - (s16)(D_800E78C0_8013654C.m[2][1] / 18);
    if (z < -0x80) {
        y = -0x80;
    } else if (z > 0) {
        y = 0;
    } else {
        y = z;
    }
    f = g_Game_8013654C.frame;
    p[3] = 5;
    p[0xB] = 0x65;
    *(u32 *)(p + 4) = 0xE10002AC;
    *(u16 *)(p + 0x12) = 0x3F58;
    *(u32 *)(p + 0xC) = y << 16;
    *(u32 *)(p + 0x14) = 0x800180;
    *(u16 *)(p + 0x10) = (0xFF - f) | 0x4000;
    ADD_PRIM_R(GD_8013654C.ot + 0xFFF, p, "$4", "$3");
    p += 0x18;
    GD_8013654C.prim = p;
}

extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x158]; SVECTOR eye; SVECTOR at; } g_Game_8013674C asm("g_Game");
extern u8 D_80137850_8013674C[] asm("D_80137850");
typedef struct { u8 *mesh; u8 pad4[0xC]; } Part_8013674C;
extern Part_8013674C D_801379A0_8013674C[] asm("D_801379A0");
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_8013674C;
extern MAT_8013674C D_800E9C60_8013674C[] asm("D_800E9C60");
extern struct { u8 pad0[0xC0]; MAT_8013674C mat; } D_800F4730_8013674C asm("D_800F4730");
extern u8 g_CameraTarget[];
extern u8 D_800F45B0[];
extern u8 D_800E78C0[];
extern u8 D_800EC330[];
extern u8 D_800E7D00_8013674C[] asm("D_800E7D00");
s32 rsin(s32);
s32 rcos(s32);
void Camera_LookAt(void *, void *, void *, void *, s32);
void func_80014804(s16 *, s16 *);
void func_80015780(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4_8013674C(void *, void *, void *) asm("func_80017CD4");
void func_80017D94_8013674C(void *, void *, void *, s32) asm("func_80017D94");
void Shadow_Draw(void *, s32, s32, s32);
void *RotMatrixZYX(void *r, void *m);
void CompMatrix(void *, void *, void *);
void Model_ProjectVerts(void *, void *, void *);
void *ApplyMatrixSV(void *m, void *v0, void *v1);
void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);
void func_8013654C(void);

void func_8013674C(void) {
    MAT_8013674C mat;
    SVECTOR r;
    SVECTOR v;
    u8 *m;

    m = D_80137850_8013674C;
    g_Game_8013674C.at.vx = 0;
    g_Game_8013674C.at.vy = -0xFA;
    g_Game_8013674C.at.vz = 0;
    g_Game_8013674C.eye.vx = rsin(g_Game_8013674C.frame * 8) / 5;
    g_Game_8013674C.eye.vy = (rsin(g_Game_8013674C.frame * 4) >> 2) - 0x500;
    g_Game_8013674C.eye.vz = rcos(g_Game_8013674C.frame * 8) / 5;
    Camera_LookAt(g_CameraTarget, D_800F45B0, D_800E78C0, D_800EC330, 0);

    M2C_FIELD(m, s32 *, 0x24) = 0;
    M2C_FIELD(m, s32 *, 0x28) = 0;
    M2C_FIELD(m, s32 *, 0x2C) = 0x200;
    func_80014804((s16 *)(m + 0x60), M2C_FIELD(m, s16 **, 0x14));
    M2C_FIELD(m, u16 *, 0x5C)++;
    if (*(s16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, u16 *, 0x5E) * 4 + 2) < M2C_FIELD(m, u16 *, 0x5C)) {
        M2C_FIELD(m, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, s16 *, 0x70) * 4);
        M2C_FIELD(m, u16 *, 0x5E) = M2C_FIELD(m, u16 *, 0x70);
    }
    func_80015780(m, 1);
    Model_ProjectBonedVerts(m);
    func_80017CD4_8013674C(g_Game_8013674C.ot, D_800E7D00_8013674C, m);
    Shadow_Draw(m + 0x24, M2C_FIELD(m, s32 *, 0x28), 0x60, 0);
    m += 0x88;

    r.vx = 0x400;
    r.vy = 0x400;
    r.vz = 0;
    RotMatrixZYX(&r, &mat);
    mat.t[0] = 0;
    mat.t[1] = 0;
    mat.t[2] = 0;
    CompMatrix(&D_800E9C60_8013674C[*(u16 *)(D_801379A0_8013674C[0].mesh + 4)], &mat, &mat);
    Model_ProjectVerts(&D_801379A0_8013674C[0], &mat, D_800E7D00_8013674C);
    func_80017CD4_8013674C(g_Game_8013674C.ot, D_800E7D00_8013674C, &D_801379A0_8013674C[0]);

    M2C_FIELD(m, s32 *, 0x24) = 0;
    M2C_FIELD(m, s32 *, 0x28) = 0;
    M2C_FIELD(m, s32 *, 0x2C) = -0x200;
    func_80014804((s16 *)(m + 0x60), M2C_FIELD(m, s16 **, 0x14));
    M2C_FIELD(m, u16 *, 0x5C)++;
    if (*(s16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, u16 *, 0x5E) * 4 + 2) < M2C_FIELD(m, u16 *, 0x5C)) {
        M2C_FIELD(m, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, s16 *, 0x70) * 4);
        M2C_FIELD(m, u16 *, 0x5E) = M2C_FIELD(m, u16 *, 0x70);
    }
    func_80015780(m, 3);
    Model_ProjectBonedVerts(m);
    func_80017D94_8013674C(g_Game_8013674C.ot, D_800E7D00_8013674C, m, 0x400);
    Model_ProjectVerts(&D_801379A0_8013674C[1], &D_800E9C60_8013674C[*(u16 *)(D_801379A0_8013674C[1].mesh + 4)], D_800E7D00_8013674C);
    func_80017CD4_8013674C(g_Game_8013674C.ot, D_800E7D00_8013674C, &D_801379A0_8013674C[1]);
    Shadow_Draw(m + 0x24, M2C_FIELD(m, s32 *, 0x28), 0x40, 0);

    v.vx = 0;
    v.vy = 100;
    v.vz = 0;
    ApplyMatrixSV(&D_800F4730_8013674C.mat, &v, &v);
    v.vx += D_800F4730_8013674C.mat.t[0];
    v.vy += D_800F4730_8013674C.mat.t[1] + 0xDC;
    v.vz += D_800F4730_8013674C.mat.t[2];
    Monkey_DrawHelmetLight(&v, 2, 1);
    func_8013654C();
}

typedef struct { u8 pad0[0x18]; u8 *f_18; u8 pad1C[0x40]; s16 f_5C; s16 f_5E; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0xA]; s16 f_70; s16 f_72; u8 *f_74; u8 pad78[0x10]; } Obj_80136AC0;
typedef struct { u8 pad0[0x10]; } Spr_80136AC0;
typedef struct { u8 pad0[0x1C]; s32 f_1C; } Mesh_80136AC0;
extern Obj_80136AC0 D_80137850[];
extern Spr_80136AC0 D_80137960[];
extern Mesh_80136AC0 D_801378A0[];
void func_8008C01C(void);
void func_80015AC0(void *, u8 *);
void func_80015B30(void *, u8 *);
void func_80015D10(void *, void *);
void Model_BindMesh(void *, u32 *);

void func_80136AC0(u8 *b) {
    u8 *buf = b;
    Obj_80136AC0 *o;
    s32 *t;
    u8 *m;
    s32 i;
    s32 j;

    func_8008C01C();
    for (i = 0; i < 4; i += 2) {
        o = &D_80137850[i >> 1];
        if (i == 0) {
            func_80015B30(o, buf + ((u16 *)buf)[2] * 4);
        } else {
            func_80015AC0(o, buf + ((u16 *)buf)[i * 2 + 2] * 4);
        }
        t = (s32 *)(((u16 *)buf)[i * 2 + 4] * 4 + (s32)buf);
        o->f_18 = (u8 *)(t + *t + 1);
        m = buf + ((u16 *)buf)[i * 2 + 4] * 4 + 4;
        o->f_5C = 0;
        o->f_5E = 0;
        o->f_70 = 0;
        o->f_72 = 0;
        o->f_60 = 0;
        o->f_62 = 0;
        o->f_64 = -0x1000;
        o->f_74 = m;
    }
    for (i = 4; i < 6; i++) {
        func_80015D10(&D_80137960[i], buf + ((u16 *)buf)[i * 2 + 2] * 4);
    }
    for (i = 6, j = 0; i < 7; i++, j += 0x20) {
        Model_BindMesh(&D_801378A0[i], (u32 *)(buf + ((u16 *)buf)[i * 2 + 2] * 4));
        ((Mesh_80136AC0 *)((u8 *)&D_801378A0[6] + j))->f_1C = 0;
    }
}

extern s32 D_80137810;
s32 func_80136D00(void);

s32 func_80136C5C(void) {
    switch (D_80137810) {
    case 0:
        if (func_80136D00() >= 0) {
            break;
        }
        return -1;
    case 1:
        return -3;
    case 2:
        return -6;
    case 3:
        break;
    case 4:
        func_80136F54();
        return 0;
    case 5:
        return -4;
    case 6:
        return -5;
    case 7:
        break;
    case 8:
        return -8;
    case 9:
        return -10;
    }
    return 0;
}

extern struct { u32 frame; SprtTp *prim; u32 *ot; } g_Game_80136D00 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136D00 asm("g_Pad");
extern s32 D_8013784C;
extern s16 D_80137818;
extern s16 D_8013781C;
s32 Sound_PlayFixed(s32);

s32 func_80136D00(void) {
    SprtTp *p;
    u32 *ot;
    u32 btn;
    u32 bob;

    p = g_Game_80136D00.prim;
    bob = g_Game_80136D00.frame / 4 % 3;
    ot = g_Game_80136D00.ot;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE100023A;
    p->code = 0x65;
    p->y0 = D_8013784C * 24 + (bob + 0x80);
    p->x0 = 0x7C;
    *(u32 *)&p->u0 = 0x7DEBA0A0;
    p->w = 0x20;
    p->h = 0x20;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    p->tpage = 0xE100022B;
    p->x0 = 0x90;
    p->w = 0x60;
    *(u16 *)&p->u0 = 0x20A0;
    p->h = 0x20;
    p->y0 = 0x98;
    p->clut = D_8013784C == 0 ? 0x3E2F : 0x3E6F;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    ((u8 *)p)[3] = 5;
    p->code = 0x65;
    *(u16 *)&p->u0 = 0xA0;
    p->tpage = 0xE100022B;
    p->x0 = 0x90;
    p->y0 = 0xA8;
    p->w = 0x60;
    p->h = 0x20;
    p->clut = D_8013784C == 0 ? 0x3E6F : 0x3E2F;
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    g_Game_80136D00.prim = p;
    if (D_80137818 == 1) {
        btn = g_Pad_80136D00.f_160 & g_Pad_80136D00.f_158;
        if (btn & 0x860) {
            Sound_PlayFixed(2);
            if (D_8013784C == 0) {
                D_80137810 = 2;
            } else {
                if (D_8013784C != 1) {
                    return 0;
                }
                D_80137810 = 1;
            }
        } else if (btn & 0x1000) {
            Sound_PlayFixed(0);
            if (--D_8013784C < 0) {
                D_8013784C = 1;
            }
            D_8013781C = 0;
        } else {
            if (!(btn & 0x4000)) {
                return 0;
            }
            Sound_PlayFixed(0);
            if (++D_8013784C >= 2) {
                D_8013784C = 0;
            }
            D_8013781C = 0;
        }
    }
    return 0;
}

typedef struct { s8 f0, f1, f2, f3; } PadPort_80136F54;
extern struct { PadPort_80136F54 ports[0x56]; u32 f_158; u8 pad15C[4]; u32 f_160; u8 pad164[0xC]; s32 port; u8 pad174[0x4C]; s32 stick_mode; } g_Pad_80136F54 asm("g_Pad");
extern struct { u8 pad0[0x8138]; u8 vibration; u8 remote_vib; u16 stereo; } g_Game_80136F54 asm("g_Game");
extern s32 D_80137814;
extern s32 D_800E54E0;
s32 Sound_SetStereo(s32);
void Pad_Vibrate(s32, s32, s32);
void func_8008CBFC(s32, ...);
void func_8008CC60(s32, s32);
void Debug_DrawSticks(void);
void Debug_DrawPadGraph(void);

s32 func_80136F54(void) {
    u32 btn;
    s32 pow;

    btn = g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158;
    if (btn & 0x900) {
        Sound_PlayFixed(2);
        D_80137810 = 0;
        return 0;
    }
    if (btn & 0x1000) {
        Sound_PlayFixed(0);
        D_80137814--;
    }
    if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0x4000) {
        Sound_PlayFixed(0);
        D_80137814++;
    }
    D_80137814 = (D_80137814 + 5) % 5;
    switch (D_80137814) {
    case 0:
        if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0xA000) {
            Sound_PlayFixed(1);
            if (g_Pad_80136F54.stick_mode == 0) {
                g_Pad_80136F54.stick_mode = 1;
            } else {
                g_Pad_80136F54.stick_mode = 0;
            }
        }
        break;
    case 1:
        if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0xA000) {
            Sound_PlayFixed(1);
            g_Game_80136F54.stereo ^= 1;
            Sound_SetStereo(g_Game_80136F54.stereo);
        }
        break;
    case 2:
        if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0x8000) {
            Sound_PlayFixed(1);
            g_Game_80136F54.vibration = !g_Game_80136F54.vibration;
        }
        if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0x2000) {
            Sound_PlayFixed(1);
            g_Game_80136F54.vibration = !g_Game_80136F54.vibration;
        }
        break;
    case 3:
        if (g_Pad_80136F54.ports[g_Pad_80136F54.port].f3 > 0x28) {
            Pad_Vibrate(0, 1, 2);
        }
        if (g_Game_80136F54.vibration) {
            pow = g_Pad_80136F54.ports[g_Pad_80136F54.port].f1;
            if (pow > 10) {
                pow *= 2;
                Pad_Vibrate(1, pow, 2);
                func_8008CC60(0xC8, 0xC8);
                func_8008CBFC((s32)"VibPow = %d\n", pow);
            }
        }
        break;
    case 4:
        if ((g_Pad_80136F54.f_160 & g_Pad_80136F54.f_158) & 0xA000) {
            Sound_PlayFixed(1);
            g_Game_80136F54.remote_vib ^= 1;
        }
        break;
    }
    func_8008CC60(0x64, 0x3C);
    func_8008CBFC((s32)"--- OPTION MENU ---\n");
    func_8008CC60(0x64, 0x5A);
    func_8008CBFC((s32)"%c Action Stick", D_80137814 == 0 ? '>' : ' ');
    func_8008CC60(0xFA, 0x5A);
    func_8008CBFC((s32)"%s", D_800E54E0 ? "Subjective" : "Objective");
    func_8008CC60(0x64, 0x69);
    func_8008CBFC((s32)"%c Stereo Type", D_80137814 == 1 ? '>' : ' ');
    func_8008CC60(0xFA, 0x69);
    if (g_Game_80136F54.stereo == 0) {
        func_8008CBFC((s32)"OFF");
    } else {
        func_8008CBFC((s32)"ON");
    }
    func_8008CC60(0x64, 0x78);
    func_8008CBFC((s32)"%c VIBRATION", D_80137814 == 2 ? '>' : ' ');
    func_8008CC60(0xFA, 0x78);
    if (g_Game_80136F54.vibration) {
        func_8008CBFC((s32)"ON");
    } else {
        func_8008CBFC((s32)"OFF");
    }
    func_8008CC60(0x64, 0x87);
    func_8008CBFC((s32)"%c Vibration TEST", D_80137814 == 3 ? '>' : ' ');
    func_8008CC60(0xFA, 0x87);
    func_8008CC60(0x64, 0x96);
    func_8008CBFC((s32)"%c Remote VIB", D_80137814 == 4 ? '>' : ' ');
    func_8008CC60(0xFA, 0x96);
    if (g_Game_80136F54.remote_vib) {
        func_8008CBFC((s32)"ON");
    } else {
        func_8008CBFC((s32)"OFF");
    }
    Debug_DrawSticks();
    Debug_DrawPadGraph();
    return 0;
}
__asm__(".section .rodata\n\t.align 3\n.section .text");

extern s16 D_80137818;
extern s16 D_8013781A;

s32 func_801374E4(void) {
    switch (D_80137818) {
    case 1:
        return 0;
    case 0:
        func_801375C4();
        if (--D_8013781A < 0) {
            D_80137818 = 1;
            D_8013781A = 0;
        }
        return 0;
    case 2:
    case 3:
        func_801375C4();
        if (++D_8013781A >= 0x1F) {
            D_80137818 = 1;
            D_8013781A = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

extern u8 g_Game[];
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; s16 w, h; } Tile_801375C4;

s32 func_801375C4(void) {
    u8 *p;
    u32 *ot;
    s32 c;

    p = G_DRAW.prim;
    c = (D_8013781A * 255) / 30;
    p[3] = 3;
    ((Tile_801375C4 *)p)->code = 0x62;
    ((Tile_801375C4 *)p)->w = 0x180;
    ((Tile_801375C4 *)p)->x0 = 0;
    ((Tile_801375C4 *)p)->y0 = 0;
    ((Tile_801375C4 *)p)->h = 0xF0;
    ((Tile_801375C4 *)p)->b0 = c;
    ((Tile_801375C4 *)p)->g0 = c;
    ((Tile_801375C4 *)p)->r0 = c;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$4", "$3");
    p += 0x10;
    if (D_80137818 == 0 || D_80137818 == 3) {
        p[3] = 1;
        ((u32 *)p)[1] = 0xE1000220;
    } else {
        p[3] = 1;
        ((u32 *)p)[1] = 0xE1000240;
    }
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    ADD_PRIM_R(ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}
