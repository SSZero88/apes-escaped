#include "common.h"
#include "m2c_macros.h"

M2C_UNK Seq_Tick();
M2C_UNK func_8001300C();
M2C_UNK Sound_ClearFrameQueue();
M2C_UNK func_80141B34();
M2C_UNK Sound_PlayFixed(M2C_UNK);
M2C_UNK func_8013FB30(s16);
extern s32 D_800E5488;
extern s16 D_8013AF52;
extern s16 SaveMenu_FadeState;
extern s16 D_8013AF6C;
M2C_UNK MemCard_Request(M2C_UNK, M2C_UNK);
extern s16 SaveMenu_Screen;
extern struct S_D_800E3880 { s16 f_0; u8 pad_2[0x4]; s16 f_6; s16 f_8; } g_MemCard;

extern u8 g_Game[];
extern u8 SaveMenu_GlyphWidths[];

void SaveMenu_DrawText(u8 *s, s32 x, s32 y, s32 c) {
    SprtTp *p;
    u32 *ot;
    u32 ch;

    p = (SprtTp *)G_DRAW.prim;
    ot = G_DRAW.ot;
    if (x < 0) {
        x = 0xC0 - SaveMenu_GetTextWidth(s) / 2;
    }
    while ((ch = *s) != 0) {
        ((u8 *)p)[3] = 5;
        p->tpage = 0xE1000226;
        p->code = 0x67;
        p->x0 = x;
        p->y0 = y;
        p->u0 = (ch & 0xF) << 4;
        p->v0 = ch & 0xF0;
        p->clut = ((c + 0xF8) << 6) | 0x1C;
        p->w = 0x10;
        p->h = 0x10;
        ADD_PRIM_R(ot, p, "$3", "$2");
        p++;
        s++;
        x += SaveMenu_GlyphWidths[ch];
    }
    G_DRAW.prim = (u8 *)p;
}

s32 SaveMenu_GetTextWidth(u8 *s) {
    s32 w;

    w = 0;
    for (; *s != 0; s++) {
        w += SaveMenu_GlyphWidths[*s];
    }
    return w;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; u8 r1, g1, b1, p1; s16 x1, y1; u8 u1, v1; u16 tpage; u8 r2, g2, b2, p2; s16 x2, y2; u8 u2, v2; u16 pad2; u8 r3, g3, b3, p3; s16 x3, y3; u8 u3, v3; u16 pad3; } PolyGT4_80136160;
extern struct { u32 frame; PolyGT4_80136160 *prim; u32 *ot; } g_Game_80136160 asm("g_Game");
extern PolyGT4_80136160 *D_800EC354_80136160 asm("g_GamePrim");

s32 SaveMenu_DrawFrame(s32 x, s32 y, s32 w, s32 h) {
    PolyGT4_80136160 *p;
    u32 *ot;
    s32 i;

    p = g_Game_80136160.prim;
    ot = g_Game_80136160.ot;
    for (i = 0; i < 6; i++) {
        ((u8 *)p)[3] = 0xC;
        p->code = 0x3E;
        if (i < 3) {
            s32 c;
            c = 0x640 / (h + 8);
            p->b0 = 0xC8;
            p->b1 = 0xC8;
            p->r0 = 0;
            p->g0 = 0;
            p->r1 = 0;
            p->g1 = 0;
            p->r2 = 0;
            p->g2 = 0;
            p->r3 = 0;
            p->g3 = 0;
            p->b2 = 0xC8 - c;
            p->b3 = 0xC8 - c;
        } else {
            s32 c, c2;
            c = 0xC8 / (h + 8);
            c2 = (h - 0x10) * 0xC8 / (h + 8);
            p->r0 = 0;
            p->g0 = 0;
            p->r1 = 0;
            p->g1 = 0;
            p->r2 = 0;
            p->g2 = 0;
            p->r3 = 0;
            p->g3 = 0;
            p->b0 = 0xC8 - c;
            p->b1 = 0xC8 - c;
            p->b2 = 0xC8 - c2;
            p->b3 = 0xC8 - c2;
        }
        switch (i) {
        case 0:
            p->x0 = x;
            p->y0 = y;
            p->x1 = x + 8;
            p->y1 = y;
            p->x2 = x;
            p->y2 = y + 8;
            p->x3 = x + 8;
            p->y3 = y + 8;
            p->u0 = 0x80;
            p->v0 = 0xA0;
            p->u1 = 0x88;
            p->v1 = 0xA0;
            p->u2 = 0x80;
            p->v2 = 0xA8;
            p->u3 = 0x88;
            p->v3 = 0xA8;
            break;
        case 1:
            p->x0 = x + w - 8;
            p->y0 = y;
            p->x1 = x + w;
            p->y1 = y;
            p->x2 = x + w - 8;
            p->y2 = y + 8;
            p->x3 = x + w;
            p->y3 = y + 8;
            p->u0 = 0x90;
            p->v0 = 0xA0;
            p->u1 = 0x98;
            p->v1 = 0xA0;
            p->u2 = 0x90;
            p->v2 = 0xA8;
            p->u3 = 0x98;
            p->v3 = 0xA8;
            break;
        case 2:
            p->x0 = x + 8;
            p->y0 = y;
            p->x1 = x + (s16)(w - 8);
            p->y1 = y;
            p->x2 = x + 8;
            p->y2 = y + 8;
            p->x3 = x + (s16)(w - 8);
            p->y3 = y + 8;
            p->u0 = 0x88;
            p->v0 = 0xA0;
            p->u1 = 0x90;
            p->v1 = 0xA0;
            p->u2 = 0x88;
            p->v2 = 0xA8;
            p->u3 = 0x90;
            p->v3 = 0xA8;
            break;
        case 3:
            p->x0 = x;
            p->y0 = y + 8;
            p->x1 = x + 8;
            p->y1 = y + 8;
            p->x2 = x;
            p->y2 = y + (s16)(h - 8);
            p->x3 = x + 8;
            p->y3 = y + (s16)(h - 8);
            p->u0 = 0x80;
            p->v0 = 0xA8;
            p->u1 = 0x88;
            p->v1 = 0xA8;
            p->u2 = 0x80;
            p->v2 = 0xB0;
            p->u3 = 0x88;
            p->v3 = 0xB0;
            break;
        case 4:
            p->x0 = x + w - 8;
            p->y0 = y + 8;
            p->x1 = x + w;
            p->y1 = y + 8;
            p->x2 = x + w - 8;
            p->y2 = y + (s16)(h - 8);
            p->x3 = x + w;
            p->y3 = y + (s16)(h - 8);
            p->u0 = 0x90;
            p->v0 = 0xA8;
            p->u1 = 0x98;
            p->v1 = 0xA8;
            p->u2 = 0x90;
            p->v2 = 0xB0;
            p->u3 = 0x98;
            p->v3 = 0xB0;
            break;
        case 5:
            p->x0 = x + 8;
            p->y0 = y + 8;
            p->x1 = x + (s16)(w - 8);
            p->y1 = y + 8;
            p->x2 = x + 8;
            p->y2 = y + (s16)(h - 8);
            p->x3 = x + (s16)(w - 8);
            p->y3 = y + (s16)(h - 8);
            p->u0 = 0x88;
            p->v0 = 0xA8;
            p->u1 = 0x90;
            p->v1 = 0xA8;
            p->u2 = 0x88;
            p->v2 = 0xB0;
            p->u3 = 0x90;
            p->v3 = 0xB0;
            break;
        }
        p->clut = 0x77AB;
        p->tpage = 0x3A;
        { u32 _t1; __asm__ volatile("lwl %0, %1\n\tsll $2, %3, 8\n\tswl $2, %1\n\tswl %0, %2" : "=&r"(_t1) : "m"(*((u8 *)(ot) + 2)), "m"(*((u8 *)(p) + 2)), "r"(p), "m"(*((u8 *)(ot) + 2)) : "$2"); }
        p++;
    }
    D_800EC354_80136160 = p;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad2; s16 x3, y3; u8 u3, v3; u16 pad3; } PolyFT4_80136554;
extern struct { u32 frame; PolyFT4_80136554 *prim; u32 *ot; } g_Game_80136554 asm("g_Game");
extern PolyFT4_80136554 *D_800EC354_80136554 asm("g_GamePrim");

s32 func_80136554(s32 x, s32 y, s32 w, s32 h) {
    PolyFT4_80136554 *p = g_Game_80136554.prim;
    u32 *ot = g_Game_80136554.ot;
    s32 i;
    s32 yy = y;

    for (i = 0; i < 9; i++) {
        ((u8 *)p)[3] = 9;
        p->code = 0x2E;
        p->r0 = 0x40;
        p->g0 = 0x40;
        p->b0 = 0x40;
        switch (i) {
        case 0:
            p->x0 = x; p->y0 = yy; p->x1 = x + 8; p->y1 = yy;
            p->x2 = x; p->y2 = yy + 8; p->x3 = x + 8; p->y3 = yy + 8;
            p->u0 = 0x80; p->v0 = 0xA0; p->u1 = 0x88; p->v1 = 0xA0;
            p->u2 = 0x80; p->v2 = 0xA8; p->u3 = 0x88; p->v3 = 0xA8;
            break;
        case 1:
            p->x0 = x + 8; p->y0 = yy; p->x1 = x + (s16)(w - 8); p->y1 = yy;
            p->x2 = x + 8; p->y2 = yy + 8; p->x3 = x + (s16)(w - 8); p->y3 = yy + 8;
            p->u0 = 0x88; p->v0 = 0xA0; p->u1 = 0x90; p->v1 = 0xA0;
            p->u2 = 0x88; p->v2 = 0xA8; p->u3 = 0x90; p->v3 = 0xA8;
            break;
        case 2:
            p->x0 = x + w - 8; p->y0 = yy; p->x1 = x + w; p->y1 = yy;
            p->x2 = x + w - 8; p->y2 = yy + 8; p->x3 = x + w; p->y3 = yy + 8;
            p->u0 = 0x90; p->v0 = 0xA0; p->u1 = 0x98; p->v1 = 0xA0;
            p->u2 = 0x90; p->v2 = 0xA8; p->u3 = 0x98; p->v3 = 0xA8;
            break;
        case 3:
            p->x0 = x; p->y0 = yy + 8; p->x1 = x + 8; p->y1 = yy + 8;
            p->x2 = x; p->y2 = yy + (s16)(h - 8); p->x3 = x + 8; p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x80; p->v0 = 0xA8; p->u1 = 0x88; p->v1 = 0xA8;
            p->u2 = 0x80; p->v2 = 0xB0; p->u3 = 0x88; p->v3 = 0xB0;
            break;
        case 4:
            p->x0 = x + 8; p->y0 = yy + 8; p->x1 = x + (s16)(w - 8); p->y1 = yy + 8;
            p->x2 = x + 8; p->y2 = yy + (s16)(h - 8); p->x3 = x + (s16)(w - 8); p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x88; p->v0 = 0xA8; p->u1 = 0x90; p->v1 = 0xA8;
            p->u2 = 0x88; p->v2 = 0xB0; p->u3 = 0x90; p->v3 = 0xB0;
            break;
        case 5:
            p->x0 = x + w - 8; p->y0 = yy + 8; p->x1 = x + w; p->y1 = yy + 8;
            p->x2 = x + w - 8; p->y2 = yy + (s16)(h - 8); p->x3 = x + w; p->y3 = yy + (s16)(h - 8);
            p->u0 = 0x90; p->v0 = 0xA8; p->u1 = 0x98; p->v1 = 0xA8;
            p->u2 = 0x90; p->v2 = 0xB0; p->u3 = 0x98; p->v3 = 0xB0;
            break;
        case 6:
            p->x0 = x; p->y0 = yy + h - 8; p->x1 = x + 8; p->y1 = yy + h - 8;
            p->x2 = x; p->y2 = yy + h; p->x3 = x + 8; p->y3 = yy + h;
            p->u0 = 0x80; p->v0 = 0xB0; p->u1 = 0x88; p->v1 = 0xB0;
            p->u2 = 0x80; p->v2 = 0xB8; p->u3 = 0x88; p->v3 = 0xB8;
            break;
        case 7:
            p->x0 = x + 8; p->y0 = yy + h - 8; p->x1 = x + (s16)(w - 8); p->y1 = yy + h - 8;
            p->x2 = x + 8; p->y2 = yy + h; p->x3 = x + (s16)(w - 8); p->y3 = yy + h;
            p->u0 = 0x88; p->v0 = 0xB0; p->u1 = 0x90; p->v1 = 0xB0;
            p->u2 = 0x88; p->v2 = 0xB8; p->u3 = 0x90; p->v3 = 0xB8;
            break;
        case 8:
            p->x0 = x + w - 8; p->y0 = yy + h - 8; p->x1 = x + w; p->y1 = yy + h - 8;
            p->x2 = x + w - 8; p->y2 = yy + h; p->x3 = x + w; p->y3 = yy + h;
            p->u0 = 0x90; p->v0 = 0xB0; p->u1 = 0x98; p->v1 = 0xB0;
            p->u2 = 0x90; p->v2 = 0xB8; p->u3 = 0x98; p->v3 = 0xB8;
            break;
        }
        p->clut = 0x77AB;
        p->tpage = 0x5A;
        ADD_PRIM_ASM(ot, p);
        p++;
        __asm__ volatile("" : : "r"(x), "r"(x));
    }
    D_800EC354_80136554 = p;
    return 0;
}

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 g_ViewMatrix;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);

void func_801368E8(SVECTOR *eye, SVECTOR *at) {
    VEC_391 d;
    VEC_391 n;
    s32 nx;
    s32 nz;
    s32 ny;
    s32 h;

    g_ViewMatrix.t[0] = -eye->vx;
    g_ViewMatrix.t[1] = -eye->vy;
    g_ViewMatrix.t[2] = -eye->vz;
    d.vx = at->vx - eye->vx;
    d.vy = 0;
    d.vz = at->vz - eye->vz;
    if (d.vx == 0 && d.vz == 0) {
        d.vz = 0x1000;
    }
    VectorNormal(&d, &n);
    nx = -n.vx;
    nz = n.vz;
    d.vy = at->vy - eye->vy;
    VectorNormal(&d, &n);
    ny = n.vy;
    h = SquareRoot0(n.vz * n.vz + n.vx * n.vx);
    g_ViewMatrix.m[0][0] = nz;
    g_ViewMatrix.m[0][1] = 0;
    g_ViewMatrix.m[0][2] = nx;
    g_ViewMatrix.m[1][0] = (nx * ny) >> 12;
    g_ViewMatrix.m[1][1] = h;
    g_ViewMatrix.m[1][2] = -(ny * nz) >> 12;
    g_ViewMatrix.m[2][0] = -(h * nx) >> 12;
    g_ViewMatrix.m[2][1] = ny;
    g_ViewMatrix.m[2][2] = (h * nz) >> 12;
    ApplyMatrixLV(&g_ViewMatrix, g_ViewMatrix.t, g_ViewMatrix.t);
    CompMatrix(&D_800AF0A0, &g_ViewMatrix, &g_ViewMatrix);
}

u8 *func_80136A88(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 new_var;
  int new_var2;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  new_var2 = arg1 > 0;
  var_v1 = 0;
  if (new_var2)
  {
    do
    {
      new_var = var_v1;
      var_v0 = new_var < arg1;
      if ((*var_a0) == 0)
      {
        var_v1 += 1;
      }
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

INCLUDE_RODATA("asm/ovl/390/nonmatchings/390", D_8013A9CC);

typedef struct { s16 x, y, w, h; } Rect_80136AB8;
extern Rect_80136AB8 D_8013A9CC_80136AB8 asm("D_8013A9CC");
extern struct { u8 pad[0x8120]; u16 f_8120; } g_Game_80136AB8 asm("g_Game");
extern struct { u8 pad[0x120]; u16 f_120; } D_800F4350;
extern u8 D_800E52D0[];
extern s32 D_800E54E0;
extern u8 D_8013AF7C[];
extern u8 D_8013AF84[];
extern void *SaveMenu_OldVSyncCallback;
extern s16 SaveMenu_FromMode;
void PadStopCom(void);
void PadStartCom(void);
void PadInitDirect(u8 *, u8 *);
void func_80141B90(void);
void func_80141C00(void);
void func_8002F1F0(s32);
void func_80012CA0(s32);
s32 Music_GetSeq(void);
s32 Cd_StartLoadList(void *);
s32 Cd_PollLoadList(void);
void Cd_Update(void);
s32 VSync(s32 mode);
void func_80141AF0(void);
void *VSyncCallback(void (*func)(void));
void SaveMenu_VSyncCallback(void);
s32 ResetGraph(s32);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 Sound_ResumeStreams(void);
s32 Sound_UnloadBanks(s32);
s32 SaveMenu_LoadModels(void);
s32 SaveMenu_RunMode15Menu(void);
s32 SaveMenu_RunEndingPrompt(void);
s32 PocketMenu_Main(void);

s32 SaveMenu_Main(void) {
    Rect_80136AB8 r;

    r = D_8013A9CC_80136AB8;
    PadStopCom();
    func_80141B90();
    PadInitDirect(D_800E52D0, D_800E52D0 + 0x22);
    PadStartCom();
    func_8002F1F0(0);
    func_80012CA0(0);
    D_800E54E0 = 0;
    if (Music_GetSeq() < 0) {
        Cd_StartLoadList(D_8013AF7C);
    } else {
        Cd_StartLoadList(D_8013AF84);
    }
    while (Cd_PollLoadList() >= 0) {
        Cd_Update();
        VSync(2);
    }
    func_80141AF0();
    SaveMenu_OldVSyncCallback = VSyncCallback(SaveMenu_VSyncCallback);
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    Sound_ResumeStreams();
    SaveMenu_LoadModels();
    if (g_Game_80136AB8.f_8120 == 0x15) {
        SaveMenu_FromMode = 0x15;
        SaveMenu_RunMode15Menu();
    } else if (g_Game_80136AB8.f_8120 == 0x23) {
        SaveMenu_FromMode = 0x23;
        SaveMenu_RunEndingPrompt();
    }
    while (1) {
        switch (D_800F4350.f_120) {
        case 0:
        case 3:
        case 13:
        case 28:
            goto end;
        case 14:
            SaveMenu_RunCardScreen(SaveMenu_FromMode);
            break;
        case 22:
            PocketMenu_Main();
            break;
        case 21:
            SaveMenu_RunMode15Menu();
            break;
        case 35:
            SaveMenu_RunEndingPrompt();
            break;
        }
    }
end:
    PadStopCom();
    func_80141C00();
    PadInitDirect(D_800E52D0, D_800E52D0 + 0x22);
    PadStartCom();
    func_8002F1F0(0);
    func_80012CA0(0);
    D_800E54E0 = 0;
    if (g_Game_80136AB8.f_8120 != 0x1C) {
        if (g_Game_80136AB8.f_8120 == 0) {
            Sound_UnloadBanks(0);
        } else {
            Sound_UnloadBanks(1);
        }
    }
    VSyncCallback(SaveMenu_OldVSyncCallback);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

void SaveMenu_VSyncCallback(void) {
    func_8001300C();
    Seq_Tick();
    Sound_ClearFrameQueue();
    func_80141B34();
}

extern u8 D_800E78C0_80136D90[] asm("g_ViewMatrix");
extern struct { u8 pad0[0x1C]; s32 f_1C; u8 pad20[4]; s32 f_24; s32 f_28; s32 f_2C; } D_800EBFA0_80136D90 asm("D_800EBFA0");
extern s32 D_8013B214;
extern s32 D_8013AF70;
extern s32 D_8013AF74;
extern s16 SaveMenu_FromMode;
extern s16 SaveMenu_FadeTimer;
void Mem_Init(void);
u8 *Mem_AllocPages(s32);
void Model_BindMesh(void *, u32 *);
s32 func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
void Stage_ApplyFog(void);
void Matrix_SetIdentity(void *);

s32 SaveMenu_LoadModels(void) {
    u8 *h;
    u8 n;
    s32 i;
    u8 *e;
    s32 off;

    h = (u8 *)0x80154000;
    Mem_Init();
    n = h[0];
    i = 1;
    D_8013B214 = (s32)Mem_AllocPages(n << 5);
    for (; i <= n; i++) {
        if (h[i * 4 + 2] == 2) {
            Model_BindMesh((void *)(D_8013B214 + (i - 1) * 0x20), (u32 *)(h + *(u16 *)(h + i * 4) * 4));
        }
    }
    func_8002FAF0(0xA4);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_80136D90.f_24 = 0;
    D_800EBFA0_80136D90.f_28 = 0x1000;
    D_800EBFA0_80136D90.f_2C = 0x1000;
    D_800EBFA0_80136D90.f_1C = 0;
    Stage_ApplyFog();
    Matrix_SetIdentity(D_800E78C0_80136D90);
    D_8013AF70 = 0;
    D_8013AF74 = 0x10;
    SaveMenu_FromMode = -1;
    SaveMenu_FadeState = 0;
    SaveMenu_FadeTimer = 0x1E;
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_80136ED8;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_80136ED8;
extern Rect_80136ED8 D_8013A9CC;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_80136ED8 asm("g_Game");
void Gfx_InitDisplay(void);
s32 ResetGraph(s32);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
s32 SaveMenu_UpdateFade(void);
s32 SaveMenu_InitMode15Menu(void);
s32 func_80137454_80136ED8(void) asm("func_80137454");
void func_80141B00(void);
void func_80141AB4(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 SaveMenu_RunMode15Menu(void) {
    Rect_80136ED8 r;
    s32 res;
    s32 v;

    r = D_8013A9CC;
    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_80136ED8.db[1].env[0x18] = 1;
    g_Game_80136ED8.db[0].env[0x18] = 1;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->r0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->g0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[0])->b0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->r0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->g0 = 0;
    ((DrawEnv_80136ED8 *)&g_Game_80136ED8.db[1])->b0 = 0;
    g_Game_80136ED8.cur = 0;
    SaveMenu_InitMode15Menu();
    while (func_8001325C(2), Gfx_BeginFrame(), SaveMenu_UpdateFade() >= 0) {
        v = func_80137454_80136ED8();
        if (v >= 0) {
            switch (v) {
            case 0:
                res = 0x16;
                break;
            case 1:
                res = 0xE;
                break;
            case 2:
                res = 0x1C;
                break;
            case 3:
                res = 0xD;
                break;
            }
            SaveMenu_FadeState = 2;
        }
        DrawSync(0);
        VSync(2);
        func_80141B00();
        g_Game_80136ED8.frame++;
        PutDispEnv(&g_Game_80136ED8.db[g_Game_80136ED8.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136ED8.db[g_Game_80136ED8.cur].env);
        DrawOTag(&g_Game_80136ED8.db[g_Game_80136ED8.cur].ot[0xFFF]);
    }
    g_Game_80136ED8.f_8120 = res;
    func_80141AB4();
    MemCard_Request(9, 0);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

typedef struct { s16 x, y, w, h; } Rect_80137104;
typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_80137104;
extern Rect_80137104 D_8013A9CC_80137104 asm("D_8013A9CC");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_80137104 asm("g_Game");
s32 func_8014016C(void);
s32 SaveMenu_UpdateYesNo(void);
s32 func_80139A68_80137104() asm("SaveMenu_DrawModel");

s32 SaveMenu_RunEndingPrompt(void) {
    Rect_80137104 r;
    s32 res;
    s32 v;

    r = D_8013A9CC_80137104;
    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_80137104.db[1].env[0x18] = 1;
    g_Game_80137104.db[0].env[0x18] = 1;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->r0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->g0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[0])->b0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->r0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->g0 = 0;
    ((DrawEnv_80137104 *)&g_Game_80137104.db[1])->b0 = 0;
    SaveMenu_FadeState = 0;
    SaveMenu_FadeTimer = 0x1E;
    g_Game_80137104.cur = 0;
    SaveMenu_Screen = 0x23;
    while (func_8001325C(2), Gfx_BeginFrame(), SaveMenu_UpdateFade() >= 0) {
        func_8014016C();
        v = SaveMenu_UpdateYesNo();
        SaveMenu_DrawMainFrame(4);
        func_80139A68_80137104();
        if (v != 0) {
            if (v == 2) {
                res = 0;
            } else {
                res = 0xE;
            }
            SaveMenu_FadeState = 2;
        }
        DrawSync(0);
        VSync(2);
        g_Game_80137104.frame++;
        PutDispEnv(&g_Game_80137104.db[g_Game_80137104.cur].env[0x5C]);
        PutDrawEnv(g_Game_80137104.db[g_Game_80137104.cur].env);
        DrawOTag(&g_Game_80137104.db[g_Game_80137104.cur].ot[0xFFF]);
    }
    g_Game_80137104.f_8120 = res;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

extern s16 SaveMenu_FadeTimer;
extern s32 D_8013AF78;
extern u8 D_80138370[] asm("func_80138370");
s32 World_GetProgress(s32);
s32 func_80137424(void);
s32 Save_SumStageMonkeys(s32);
u8 *func_8013FC20(void);
void func_80141A10(void *);

s32 SaveMenu_InitMode15Menu(void) {
    u8 a[8];
    u8 b[8];
    s32 has;
    s32 n;
    u8 *p;

    has = World_GetProgress(0x18) > 0;
    n = func_80137424();
    SaveMenu_NumberToDigits((s16)Save_SumStageMonkeys(0), a);
    if (has) {
        SaveMenu_NumberToDigits((s16)n, b);
    } else {
        b[0] = 0x7F;
        b[1] = 0x7F;
        b[2] = 0;
    }
    p = func_8013FC20();
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[4] = b[0];
    p[5] = b[1];
    p[6] = b[2];
    p[7] = 0;
    D_8013AF52 = 1;
    D_8013AF78 = -0x200;
    SaveMenu_FadeState = 0;
    SaveMenu_FadeTimer = 0x1E;
    D_8013AF6C = 0;
    SaveMenu_StartCardCheck(1);
    func_80141A10(D_80138370);
    return 0;
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[14]; } Ent_390;

s32 func_80137424(void) {
    s32 i;
    s32 s;

    for (i = s = 0; i < 30; i++) {
        s += ((Ent_390 *)0x80102400)[i].f_1;
    }
    return s;
}

s16 func_80137454(void) {
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v0_2;

    func_8013FB30(D_8013AF52);
    func_80139CF0();
    SaveMenu_DrawModel();
    if (SaveMenu_FadeState == 1) {
        if (SaveMenu_CancelPressed() != 0) {
            Sound_PlayFixed(1);
            return 3;
        }
        if (SaveMenu_ConfirmPressed() != 0) {
            Sound_PlayFixed(3);
            return D_8013AF52;
        }
        temp_a0 = D_8013AF6C == 0;
        if (D_800E5488 == 0x8000) {
            temp_v0 = (u16) D_8013AF52 - 1;
            D_8013AF52 = temp_v0;
            if (temp_v0 < temp_a0) {
                D_8013AF52 = temp_a0;
            } else {
                Sound_PlayFixed(0);
            }
        }
        if (D_800E5488 == 0x2000) {
            temp_v0_2 = (u16) D_8013AF52 + 1;
            D_8013AF52 = temp_v0_2;
            if (temp_v0_2 >= 3) {
                D_8013AF52 = 2;
            } else {
                Sound_PlayFixed(0);
            }
        }
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}

typedef struct { u8 pad0[0x19]; u8 r0, g0, b0; } DrawEnv_8013758C;
extern s16 D_8013AF50;
extern s16 D_8013AF54;
extern s16 D_8013AF60;
extern s16 D_8013AF62;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; s16 f_8120; } g_Game_8013758C asm("g_Game");
void func_8013829C(void);
s32 SaveMenu_UpdateCard(void);

s32 SaveMenu_RunCardScreen(s32 from) {
    s32 res;
    s32 v;

    Gfx_InitDisplay();
    ResetGraph(1);
    g_Game_8013758C.db[1].env[0x18] = 1;
    g_Game_8013758C.db[0].env[0x18] = 1;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->r0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->g0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[0])->b0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->r0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->g0 = 0;
    ((DrawEnv_8013758C *)&g_Game_8013758C.db[1])->b0 = 0;
    D_8013AF52 = 0;
    D_8013AF50 = 5;
    D_8013AF54 = 0;
    D_8013AF60 = 0;
    g_Game_8013758C.cur = 0;
    D_8013AF62 = 0;
    SaveMenu_StartCardCheck(0);
    func_80141A10(func_8013829C);
    SaveMenu_FadeState = 0;
    SaveMenu_FadeTimer = 0x1E;
    while (func_8001325C(2), Gfx_BeginFrame(), SaveMenu_UpdateFade() >= 0) {
        v = SaveMenu_UpdateCard();
        if (v < 0) {
            switch (v) {
            case -4:
                if (from < 0) {
                    res = 3;
                } else if (from == 0x23) {
                    res = 0x23;
                } else {
                    res = 0x15;
                }
                break;
            case -1:
                if (from < 0) {
                    res = 0xD;
                } else if (from == 0x23) {
                    res = 0;
                } else {
                    res = 0x15;
                }
                break;
            case -2:
                res = 3;
                break;
            case -5:
                res = 0;
                break;
            }
            SaveMenu_FadeState = 2;
        }
        DrawSync(0);
        VSync(0);
        func_80141B00();
        g_Game_8013758C.frame++;
        PutDispEnv(&g_Game_8013758C.db[g_Game_8013758C.cur].env[0x5C]);
        PutDrawEnv(g_Game_8013758C.db[g_Game_8013758C.cur].env);
        DrawOTag(&g_Game_8013758C.db[g_Game_8013758C.cur].ot[0xFFF]);
    }
    g_Game_8013758C.f_8120 = res;
    func_80141AB4();
    MemCard_Request(9, 0);
    return 0;
}

s32 SaveMenu_CountCoins(u8 *p, s32 flags) {
    s32 n;
    s32 i;

    for (i = n = 0; i < 0x80; i++, p += 2) {
        if (*p == 0xFF) {
            break;
        }
        n++;
    }
    if (flags & 0x10) {
        n += 5;
    }
    if (flags & 0x1000) {
        n += 5;
    }
    return n;
}

typedef struct { s16 total; s16 f2; s16 f4; s16 f6; s16 pct; s16 fA; s32 fC; u8 s10[0x10]; u8 s20[0x10]; u8 s30[0x10]; u8 s40[0x10]; u8 s50[8]; u8 s58[8]; u8 s60[8]; u8 s68[8]; u8 s70[8]; } Slot_8013784C;
typedef struct { s16 f180; u16 f182; s32 f184; u8 pad188[0x38]; u8 f1C0; u8 pad1C1[7]; u8 f1C8[0x20]; u8 f1E8[0x600]; s32 f7E8; u8 pad7EC[0x7A0 - 0x66C]; } Save_8013784C;
extern Slot_8013784C D_8013B218_784C[] asm("SaveMenu_SlotInfo");
extern struct { u8 pad0[0x180]; Save_8013784C r[4]; } D_800E1880_784C asm("g_MemCardImage");
extern s16 D_8013AFE8_784C[] asm("D_8013AFE8");
extern s16 SaveMenu_YesNo;
extern s16 D_8013AF5C;
s32 SaveMenu_GetSlotLastStage(s32 n);
void func_8013A478_784C(s16, s16) asm("SaveMenu_LoadSlotPicture");
s32 SaveMenu_CountCoins(u8 *p, s32 flags);
s32 Save_GetCompletion(void *);
s32 SaveMenu_NumberToDigits(s32, u8 *);
void func_8013B550(void);

s32 SaveMenu_SetScreen(s32 msg, s32 arg) {
    s32 i;
    s32 j;

    SaveMenu_Screen = msg;
    switch (msg) {
    case 1:
        D_8013AF50 = arg;
        D_8013AF54 = 0;
        j = 1;
        for (i = 4; i >= 0; i--) {
            D_8013AFE8_784C[i] = j;
        }
        if (SaveMenu_FromMode < 0) {
            D_8013AFE8_784C[4] = -1;
            D_8013AFE8_784C[3] = -1;
            D_8013AFE8_784C[1] = -1;
        } else if (SaveMenu_FromMode == 0x23 || arg == 2) {
            D_8013AFE8_784C[4] = -1;
            D_8013AFE8_784C[3] = -1;
            D_8013AFE8_784C[2] = -1;
        }
    case 11:
        SaveMenu_YesNo = 0;
        for (i = 0; i < 4; i++) {
            D_8013B218_784C[i].f4 = 0xCC;
            D_8013B218_784C[i].f6 = 0x3C;
            D_8013B218_784C[i].total = 0;
            D_8013B218_784C[i].fA = -1;
            if (D_800E1880_784C.r[i].f180 >= 0) {
                D_8013B218_784C[i].fA = SaveMenu_GetSlotLastStage(i);
                func_8013A478_784C(i, D_800E1880_784C.r[i].f180);
            }
            for (j = 0; j < 0x19; j++) {
                D_8013B218_784C[i].total += D_800E1880_784C.r[i].f1C8[j];
            }
            D_8013B218_784C[i].f2 = SaveMenu_CountCoins(D_800E1880_784C.r[i].f1E8, D_800E1880_784C.r[i].f7E8);
            D_8013B218_784C[i].pct = Save_GetCompletion(&D_800E1880_784C.r[i].f180);
            if (D_8013B218_784C[i].pct == 1000) {
                D_8013B218_784C[i].s70[0] = 0x6B;
                D_8013B218_784C[i].s70[1] = 0x6A;
                D_8013B218_784C[i].s70[2] = 0x6A;
                D_8013B218_784C[i].s70[3] = 0xBC;
                D_8013B218_784C[i].s70[4] = 0;
            } else {
                SaveMenu_NumberToDigits(D_8013B218_784C[i].pct, D_8013B218_784C[i].s70);
                D_8013B218_784C[i].s70[3] = D_8013B218_784C[i].s70[2];
                D_8013B218_784C[i].s70[2] = 0xAC;
                D_8013B218_784C[i].s70[4] = 0xBC;
                D_8013B218_784C[i].s70[5] = 0;
            }
            SaveMenu_NumberToDigits(D_8013B218_784C[i].total, D_8013B218_784C[i].s50);
            SaveMenu_NumberToDigits(D_8013B218_784C[i].f4, D_8013B218_784C[i].s60);
            SaveMenu_NumberToDigits(D_8013B218_784C[i].f2, D_8013B218_784C[i].s58);
            SaveMenu_NumberToDigits(D_8013B218_784C[i].f6, D_8013B218_784C[i].s68);
            SaveMenu_NumberToDigits(D_8013B218_784C[i].total, D_8013B218_784C[i].s10);
            D_8013B218_784C[i].s10[3] = 0x8D;
            if (D_800E1880_784C.r[i].f1C0 != 0) {
                D_8013B218_784C[i].s10[4] = D_8013B218_784C[i].s60[0];
                D_8013B218_784C[i].s10[5] = D_8013B218_784C[i].s60[1];
                D_8013B218_784C[i].s10[6] = D_8013B218_784C[i].s60[2];
            } else {
                D_8013B218_784C[i].s10[4] = 0x7F;
                D_8013B218_784C[i].s10[5] = 0x7F;
                D_8013B218_784C[i].s10[6] = 0x7F;
            }
            D_8013B218_784C[i].s10[7] = 0;
            SaveMenu_NumberToDigits(D_8013B218_784C[i].f2, D_8013B218_784C[i].s20);
            D_8013B218_784C[i].s20[3] = 0x8D;
            if (D_800E1880_784C.r[i].f1C0 != 0) {
                D_8013B218_784C[i].s20[4] = D_8013B218_784C[i].s68[0];
                D_8013B218_784C[i].s20[5] = D_8013B218_784C[i].s68[1];
                D_8013B218_784C[i].s20[6] = D_8013B218_784C[i].s68[2];
            } else {
                D_8013B218_784C[i].s20[4] = 0x7F;
                D_8013B218_784C[i].s20[5] = 0x7F;
                D_8013B218_784C[i].s20[6] = 0x7F;
            }
            D_8013B218_784C[i].s20[7] = 0;
            D_8013B218_784C[i].s30[0] = 0x8C;
            SaveMenu_NumberToDigits(D_800E1880_784C.r[i].f182 >> 8, &D_8013B218_784C[i].s30[1]);
            D_8013B218_784C[i].s30[1] = D_8013B218_784C[i].s30[2];
            D_8013B218_784C[i].s30[2] = D_8013B218_784C[i].s30[3];
            D_8013B218_784C[i].s30[3] = 0;
            D_8013B218_784C[i].s40[0] = 0x8C;
            SaveMenu_NumberToDigits((D_800E1880_784C.r[i].f182 - 1) & 0xFF, &D_8013B218_784C[i].s40[1]);
            D_8013B218_784C[i].s40[1] = D_8013B218_784C[i].s40[2];
            D_8013B218_784C[i].s40[2] = D_8013B218_784C[i].s40[3];
            D_8013B218_784C[i].s40[3] = 0;
            D_8013B218_784C[i].fC = D_800E1880_784C.r[i].f184;
        }
        D_8013AF52 = 0;
        break;
    case 4:
    case 5:
    case 7:
    case 13:
        SaveMenu_YesNo = 1;
        break;
    case 16:
        SaveMenu_YesNo = 0;
        break;
    case 10:
        D_8013AF5C = 0;
        break;
    case 15:
        func_8013B550();
        break;
    case 0:
    case 45:
        break;
    }
    return 0;
}

extern u8 SaveMenu_DigitGlyphs[];

s32 SaveMenu_NumberToDigits(s32 n, u8 *out) {
    s32 k;
    s32 m;
    s32 h;
    u8 *tb = SaveMenu_DigitGlyphs;

    m = (s16)n;
    h = m / 100;
    out[0] = tb[(s16)h];
    k = n;
    if (out[0] == 0x6A) {
        out[0] = 0xEF;
    }
    out[1] = tb[(s16)((s16)(m - h * 100) / 10)];
    if (out[0] == 0xEF && out[1] == 0x6A) {
        out[1] = out[0];
    }
    out[2] = SaveMenu_DigitGlyphs[(s16)((s16)k % 10)];
    out[3] = 0;
    return 0;
}

s32 SaveMenu_StartCardCheck(s32 arg0) {
    M2C_UNK var_a0;

    MemCard_Request(8, 0);
    MemCard_Request(7, 0);
    g_MemCard.f_6 = 0;
    g_MemCard.f_8 = 0;
    g_MemCard.f_0 = 1;
    if (arg0 == 0) {
        SaveMenu_Screen = 0;
        var_a0 = 0;
    } else {
        var_a0 = 0x11;
    }
    MemCard_Request(var_a0, 0);
    return 0;
}

s32 SaveMenu_UpdateCardScreen(void);

s32 SaveMenu_UpdateCard(void) {
    s32 r = SaveMenu_UpdateCardScreen();

    if (r != 0) {
        return r;
    }
    return 0;
}

extern struct { s16 f0; s16 pad2; s16 f4; s16 f6; } D_800E3880_7E4C asm("g_MemCard");
typedef struct { u8 pad0[0x180]; s16 f180; u8 pad182[0x16]; u8 f198; u8 pad199[0x7A0 - 0x199]; } Save_80137E4C;
extern Save_80137E4C D_800E1880_7E4C[] asm("g_MemCardImage");
extern u8 D_800E1A00[];
extern s16 D_800E3884;
extern s16 g_MemCardSlot;
extern s16 D_8013AF58;
void func_8013FEFC(s32);
s32 func_80139FC8(void);
s32 SaveMenu_SetScreen(s32, s32);
void Save_Load(void);
void Save_CopyToSlot(void *);
void func_8013BC64(void);
s32 func_8013B6C4(void);
void func_8013B47C(void);

s32 SaveMenu_UpdateCardScreen(void) {
    s32 v;

    switch (SaveMenu_Screen) {
    case 0:
        if (D_800E3884 == 1) {
            func_8013FEFC(1);
        }
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        break;
    case 1: {
        s32 r;
        func_8013888C();
        r = func_80139FC8();
        if (r < 0) {
            return r;
        }
        break;
    }
    case 2:
        if (D_800E3884 != 4) {
            func_8013FEFC(1);
        } else {
            func_8014016C();
        }
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (D_800E3884 != 4) {
            return 0;
        }
        if (SaveMenu_ConfirmPressed() == 0) {
            return 0;
        }
        Sound_PlayFixed(3);
        return -4;
    case 4:
        if (D_800E3880_7E4C.f4 != 4 && D_800E3880_7E4C.f0 != 1) {
            func_8013FEFC(1);
            v = 0;
        } else {
            func_8014016C();
            v = SaveMenu_UpdateYesNo();
        }
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            break;
        }
        if (v == 2) {
            SaveMenu_SetScreen(1, 2);
            MemCard_Request(7, 0);
            return 0;
        }
        SaveMenu_SetScreen(10, 0);
        return 0;
    case 9:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        if (D_800E3880_7E4C.f4 != 4 && D_800E3880_7E4C.f0 != 1) {
            func_8013FEFC(1);
            v = 0;
        } else {
            func_8014016C();
            v = SaveMenu_ConfirmPressed();
        }
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            return 0;
        }
        Sound_PlayFixed(3);
        if (SaveMenu_Screen != 0x29) {
            SaveMenu_SetScreen(1, 2);
            MemCard_Request(7, 0);
            return 0;
        }
        Sound_PlayFixed(3);
        return -4;
    case 5:
        func_8014016C();
        v = SaveMenu_UpdateYesNo();
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            break;
        }
        if (v == 1) {
            Save_Load();
            return -1;
        }
        SaveMenu_SetScreen(1, 5);
        return 0;
    case 11:
        if (SaveMenu_FromMode == 0x23) {
            SaveMenu_DrawMainFrame(4);
            SaveMenu_DrawModel();
            return -5;
        }
        func_8014016C();
        func_801391B0();
        v = SaveMenu_UpdateYesNo();
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            break;
        }
        if (v == 1) {
            return -1;
        }
        return -2;
    case 7:
        func_8014016C();
        v = SaveMenu_UpdateYesNo();
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            break;
        }
        if (v != 1) {
            SaveMenu_SetScreen(1, 5);
            return 0;
        }
        D_800E1880_7E4C[D_800E3880_7E4C.f6].f180 = -1;
        D_800E1880_7E4C[D_800E3880_7E4C.f6].f198 = 0;
        MemCard_Request(2, 0);
        SaveMenu_SetScreen(12, 0);
        return 0;
    case 6:
    case 8:
    case 10:
    case 12:
    case 17:
        func_8014016C();
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        break;
    case 13:
        func_8014016C();
        v = SaveMenu_UpdateYesNo();
        SaveMenu_DrawMainFrame(4);
        SaveMenu_DrawModel();
        if (v == 0) {
            break;
        }
        if (v != 1) {
            SaveMenu_SetScreen(1, 5);
            return 0;
        }
        SaveMenu_SetScreen(8, 0);
        Save_CopyToSlot(&D_800E1A00[g_MemCardSlot * 0x7A0]);
        MemCard_Request(2, 0);
        return 0;
    case 15:
        func_8013BC64();
        if (func_8013B6C4() == 0) {
            break;
        }
        SaveMenu_SetScreen(0x10, D_8013AF58);
        return 0;
    case 16:
        func_8013B47C();
        break;
    case 3:
    case 14:
        break;
    }
    return 0;
}

/* NOTE: func_8013829C.s also holds a second, never-returning function at 0x80138370 (named func_80138370 here); both verified with wip/_ovl/ag/A/pair.py (each 0 diffs, total 0x144) */
s32 func_801383E0(void);
s32 func_801384BC(void);
s32 func_80138524(void);
s32 func_801385EC(void);
s32 func_801386CC(void);
s32 func_80138744(void);
s32 func_801387FC(void);
s32 func_8013B400(void);

void func_8013829C(void) {
    while (1) {
        switch (SaveMenu_Screen) {
        case 0:
            func_801383E0();
            MemCard_Request(4, 0);
            break;
        case 2:
            func_80138744();
            MemCard_Request(4, 0);
            break;
        case 6:
            func_80138524();
            break;
        case 8:
            func_801385EC();
            break;
        case 17:
            func_8013B400();
            break;
        case 10:
            func_801387FC();
            break;
        case 12:
            func_801386CC();
            break;
        case 1:
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
        case 13:
        case 15:
        case 16:
            func_801384BC();
            MemCard_Request(4, 0);
            break;
        case 3:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
            break;
        }
    }
}

extern s16 D_800E3880_80138370 asm("g_MemCard");
extern s16 D_8013AF6C;

void func_80138370(void) {
    while (1) {
        switch (D_800E3880_80138370) {
        case -8:
        case -7:
        case -5:
        case -4:
        case -2:
        case -1:
        case 0:
            D_8013AF6C = 0;
        case -6:
        case -3:
        case 1:
            break;
        }
        MemCard_Request(0x10, 0);
    }
}

extern s16 D_800E3880_801383E0 asm("g_MemCard");
extern s16 D_800E3884;
extern s16 D_8013AF64;
s32 SaveMenu_SetScreen(s32, s32);

s32 func_801383E0(void) {
    switch (D_800E3880_801383E0) {
    case 0:
        D_8013AF64 = 0;
        if (D_800E3884 == 0) {
            MemCard_Request(1, 0);
        } else {
            SaveMenu_SetScreen(1, 5);
        }
        break;
    case -5:
    case -4:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(1, 2);
        break;
    case -8:
        D_8013AF64 = 1;
        SaveMenu_SetScreen(1, 2);
        break;
    case -7:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(2, 0);
        break;
    case -2:
    case -1:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_801384BC asm("g_MemCard");
s32 SaveMenu_SetScreen(s32, s32);

s32 func_801384BC(void) {
    switch (D_800E3880_801384BC) {
    case -8:
        break;
    case -7:
        SaveMenu_SetScreen(2, 0);
        break;
    case -2:
    case -1:
        SaveMenu_SetScreen(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_80138524 asm("g_MemCard");
extern s16 g_MemCardSlot;
extern u8 D_800E1A00[];
void Save_CopyToSlot(void *);

s32 func_80138524(void) {
    switch (D_800E3880_80138524) {
    case 0:
        SaveMenu_SetScreen(8, 0);
        Save_CopyToSlot(D_800E1A00 + g_MemCardSlot * 0x7A0);
        MemCard_Request(2, 0);
        break;
    case -7:
        SaveMenu_SetScreen(2, 0);
        break;
    case -8:
        SaveMenu_SetScreen(4, 0);
        break;
    case -4:
        SaveMenu_SetScreen(9, 0);
        break;
    case -2:
    case -1:
        SaveMenu_SetScreen(0x2B, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern struct { s16 f_0; s16 pad_2; s16 f_4; s16 f_6; } D_800E3880_801385EC asm("g_MemCard");

s32 func_801385EC(void) {
    switch (D_800E3880_801385EC.f_0) {
    case -5:
        MemCard_Request(5, 0);
        break;
    case 0:
        if (D_800E3880_801385EC.f_4 == 5) {
            Save_CopyToSlot(D_800E1A00 + D_800E3880_801385EC.f_6 * 0x7A0);
            MemCard_Request(2, 0);
        } else {
            SaveMenu_SetScreen(0xB, 0);
        }
        break;
    case -7:
        SaveMenu_SetScreen(2, 0);
        break;
    case -8:
        SaveMenu_SetScreen(4, 0);
        break;
    case -4:
        SaveMenu_SetScreen(9, 0);
        break;
    case -2:
    case -1:
        SaveMenu_SetScreen(0x2B, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_801386CC asm("g_MemCard");

s32 func_801386CC(void) {
    switch (D_800E3880_801386CC) {
    case 0:
        SaveMenu_SetScreen(1, 5);
        break;
    case -7:
        SaveMenu_SetScreen(2, 0);
        break;
    case -2:
    case -1:
        SaveMenu_SetScreen(0x2D, 0);
        break;
    case -8:
        break;
    case 1:
        break;
    }
    return 0;
}

extern s16 D_800E3880_80138744 asm("g_MemCard");

s32 func_80138744(void) {
    switch (D_800E3880_80138744) {
    case 0:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(1, 5);
        break;
    case -5:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(1, 2);
        MemCard_Request(7, 0);
        break;
    case -8:
        D_8013AF64 = 1;
        SaveMenu_SetScreen(1, 2);
        MemCard_Request(7, 0);
        break;
    case -2:
    case -1:
        D_8013AF64 = 0;
        SaveMenu_SetScreen(0x29, 0);
        break;
    case 1:
        break;
    }
    return 0;
}

extern u16 D_800E3880_801387FC asm("g_MemCard");

s32 func_801387FC(void) {
    s32 a;
    s32 s;
    D_8013AF5C++;
    if (D_8013AF5C < 3) {
        return 0;
    }
    MemCard_Request(3, 0);
    s = D_800E3880_801387FC;
    __asm__("" : "=r"(s) : "0"(s));
    if ((u16)(s + 2) < 2) {
        a = 0x2A;
    } else if ((s16)s != 0) {
        a = 2;
    } else {
        MemCard_Request(4, 0);
        a = 6;
    }
    SaveMenu_SetScreen(a, 0);
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_8013888C;
typedef struct { u16 clut; u8 u, v; } Tex_8013888C;
typedef struct { u8 pad0[0xA]; s16 fA; u8 padC[0x6C]; } Slot_8013888C;
typedef struct { s16 f180; u8 pad2[0x7A0 - 2]; } Save_8013888C;
extern s16 D_8013AFE8_888C[] asm("D_8013AFE8");
extern Tex_8013888C D_8013AFAC_888C[] asm("D_8013AFAC");
extern Slot_8013888C D_8013B218_888C[] asm("SaveMenu_SlotInfo");
extern struct { u8 pad0[0x180]; Save_8013888C r[4]; } D_800E1880_888C asm("g_MemCardImage");
void func_8013FC2C(s32, s16 *);
void func_801400F4(s32);
s32 func_80138DC0(s32 mode, s32 slot);
void func_80140074(s32);
s32 SaveMenu_DrawIcon(s32 i, s32 x, s32 y);
s32 func_80139570(s32 x, s32 y);
#define P_8013888C ((PolyFT4_8013888C *)G_DRAW.prim)
#define ADDPRIM_8013888C(OT) __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(OT), "m"(G_DRAW.prim) : "$2", "$4", "memory")

s32 func_8013888C(void) {
    s32 i;

    func_8013FC2C(D_8013AF52, D_8013AFE8_888C);
    for (i = 0; i < 4; i++) {
        if (D_800E1880_888C.r[i].f180 < 0) {
            func_801400F4(i);
        } else {
            func_80138DC0(0, i);
        }
    }
    func_80140074(D_8013AF54);
    SaveMenu_DrawIcon(0, 0x19, 0x7C);
    SaveMenu_DrawIcon(1, 0x2D, 0x7C);
    if (D_8013AF54 == 1) {
        SaveMenu_DrawIcon(2, 0x19, 0xAA);
        SaveMenu_DrawIcon(3, 0x2D, 0xAA);
    } else {
        SaveMenu_DrawIcon(4, 0x19, 0xAA);
        SaveMenu_DrawIcon(5, 0x32, 0xAA);
    }
    G_DRAW.prim[3] = 1;
    *(u32 *)(G_DRAW.prim + 4) = 0xE1000217;
    ADDPRIM_8013888C(&G_DRAW.db[G_DRAW.cur].ot[0]);
    G_DRAW.prim += 8;
    if (D_8013AF54 == 1) {
        func_80139570(0x60, g_MemCardSlot * 0x30 + 0x18);
    }
    for (i = 0; i < 4; i++) {
        if (D_8013B218_888C[i].fA >= 0 && D_800E1880_888C.r[i].f180 >= 0) {
            ((u8 *)P_8013888C)[3] = 9;
            P_8013888C->code = 0x2D;
            P_8013888C->clut = D_8013AFAC_888C[i + 11].clut;
            P_8013888C->tpage = 0x87;
            P_8013888C->x0 = 0x120;
            P_8013888C->y0 = i * 0x30 + 0x20;
            P_8013888C->x1 = 0x160;
            P_8013888C->y1 = i * 0x30 + 0x20;
            P_8013888C->x2 = 0x120;
            P_8013888C->y2 = i * 0x30 + 0x40;
            P_8013888C->x3 = 0x160;
            P_8013888C->y3 = i * 0x30 + 0x40;
            P_8013888C->u0 = D_8013AFAC_888C[i + 11].u;
            P_8013888C->v0 = D_8013AFAC_888C[i + 11].v;
            P_8013888C->u1 = D_8013AFAC_888C[i + 11].u + 0x3F;
            P_8013888C->v1 = D_8013AFAC_888C[i + 11].v;
            P_8013888C->u2 = D_8013AFAC_888C[i + 11].u;
            P_8013888C->v2 = D_8013AFAC_888C[i + 11].v + 0x1F;
            P_8013888C->u3 = D_8013AFAC_888C[i + 11].u + 0x3F;
            P_8013888C->v3 = D_8013AFAC_888C[i + 11].v + 0x1F;
            ADDPRIM_8013888C(&G_DRAW.db[G_DRAW.cur].ot[0]);
            G_DRAW.prim += 0x28;
        }
    }
    for (i = 0; i < 15; i++) {
        ((u8 *)P_8013888C)[3] = 9;
        P_8013888C->code = 0x2D;
        P_8013888C->clut = D_8013AFAC_888C[2].clut;
        P_8013888C->tpage = 8;
        P_8013888C->x0 = 0x118;
        P_8013888C->y0 = i * 16;
        P_8013888C->x1 = 0x168;
        P_8013888C->y1 = i * 16;
        P_8013888C->x2 = 0x118;
        P_8013888C->y2 = i * 16 + 16;
        P_8013888C->x3 = 0x168;
        P_8013888C->y3 = i * 16 + 16;
        P_8013888C->u0 = D_8013AFAC_888C[2].u;
        P_8013888C->v0 = D_8013AFAC_888C[2].v;
        P_8013888C->u1 = D_8013AFAC_888C[2].u + 0x4F;
        P_8013888C->v1 = D_8013AFAC_888C[2].v;
        P_8013888C->u2 = D_8013AFAC_888C[2].u;
        P_8013888C->v2 = D_8013AFAC_888C[2].v + 0xF;
        P_8013888C->u3 = D_8013AFAC_888C[2].u + 0x4F;
        P_8013888C->v3 = D_8013AFAC_888C[2].v + 0xF;
        ADDPRIM_8013888C(&G_DRAW.db[G_DRAW.cur].ot[0]);
        G_DRAW.prim += 0x28;
    }
    SaveMenu_DrawMainFrame(0);
    SaveMenu_DrawModel();
    return 0;
}

typedef struct { u8 pad0[0xC]; u32 flags; u8 t1[0x10]; u8 t2[0x10]; u8 t3[0x10]; u8 t4[0x10]; u8 pad50[0x28]; } Slot_80138DC0;
typedef struct { u8 t1[0x10]; u8 t2[0x10]; u8 pad20[0x58]; } SlotB_80138DC0;
extern Slot_80138DC0 SaveMenu_SlotInfo[];
extern SlotB_80138DC0 D_8013B228[];
extern u8 D_8013B288[];
extern s8 D_8013AF28[];
extern u8 D_8013ADF0[];
extern u8 D_800E1A18[];
extern s16 D_8013AF5E;
s32 SaveMenu_DrawIcon(s32 i, s32 x, s32 y);
void SaveMenu_DrawText(u8 *s, s32 x, s32 y, s32 c);
s32 SaveMenu_GetTextWidth(u8 *s);
s32 SaveMenu_GetSlotLastStage(s32 n);

s32 func_80138DC0(s32 mode, s32 slot) {
    s32 x;
    s32 y;
    u8 *p;
    s32 w;
    u8 *q;

    if (mode == 0) {
        x = 0x96;
        y = slot * 48 + 0x20;
    } else {
        x = 0x6E;
        y = 0x50;
    }
    if (D_8013AF5E == 1) {
        SaveMenu_DrawIcon(0x11, x - 0x24, y);
        SaveMenu_DrawIcon(0x10, x - 0x24, y + 0x10);
        ((u8 *)G_DRAW.prim)[3] = 1;
        ((u32 *)G_DRAW.prim)[1] = 0xE1000208;
        __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
        G_DRAW.prim += 8;
        SaveMenu_DrawText(D_8013B228[slot].t1, x + 0x1E, y, 1);
        SaveMenu_DrawText(D_8013B228[slot].t2, x + 0x1E, y + 0x10, 1);
    } else if (D_8013AF5E == 2) {
        SaveMenu_DrawIcon(0xF, x - 0x24, y + 0x10);
        SaveMenu_DrawIcon(0x12, x + 0x34, y + 0x10);
        if (SaveMenu_SlotInfo[slot].flags & 1) {
            SaveMenu_DrawIcon(8, x - 0x24, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 2) {
            SaveMenu_DrawIcon(7, x - 0x12, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 4) {
            SaveMenu_DrawIcon(0xC, x, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 8) {
            SaveMenu_DrawIcon(0xB, x + 0x12, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 0x10) {
            SaveMenu_DrawIcon(9, x + 0x24, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 0x40) {
            SaveMenu_DrawIcon(0xE, x + 0x36, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 0x80) {
            SaveMenu_DrawIcon(0xD, x + 0x48, y);
        }
        if (SaveMenu_SlotInfo[slot].flags & 0x20) {
            SaveMenu_DrawIcon(0xA, x + 0x5A, y);
        }
        ((u8 *)G_DRAW.prim)[3] = 1;
        ((u32 *)G_DRAW.prim)[1] = 0xE1000208;
        __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
        G_DRAW.prim += 8;
        SaveMenu_DrawText(SaveMenu_SlotInfo[slot].t3, x + 0x48, y + 0x10, 1);
        SaveMenu_DrawText(SaveMenu_SlotInfo[slot].t4, x - 0x10, y + 0x10, 1);
    } else {
        p = func_80136A88(D_8013ADF0, D_8013AF28[SaveMenu_GetSlotLastStage(slot)]);
        SaveMenu_DrawText(D_800E1A18 + slot * 0x7A0, x - 0x2E, y, 1);
        SaveMenu_DrawText(p, x - 0x1E, y + 0x10, 0);
        q = D_8013B288 + slot * 0x78;
        w = SaveMenu_GetTextWidth(q) - 0x7E;
        SaveMenu_DrawText(q, x - w, y, 0);
    }
    return 0;
}

/* uses the file's existing 'extern struct S_D_800E3880 {...} g_MemCard;' (checked with it prepended) */
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_801391B0;
typedef struct { u16 clut; u8 u, v; } Tex_801391B0;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_801391B0 asm("g_Pad");
extern Tex_801391B0 D_8013AFAC[];
#define P_801391B0 ((PolyFT4_801391B0 *)G_DRAW.prim)

s32 func_801391B0(void) {
    u32 *ot;

    D_8013AF5E = 0;
    if (g_Pad_801391B0.f_158 & 4) {
        D_8013AF5E = 1;
        if (g_Pad_801391B0.f_160 & g_Pad_801391B0.f_158 & 4) {
            Sound_PlayFixed(4);
        }
    } else if (g_Pad_801391B0.f_158 & 8) {
        D_8013AF5E = 2;
        if (g_Pad_801391B0.f_160 & g_Pad_801391B0.f_158 & 8) {
            Sound_PlayFixed(4);
        }
    }
    func_80138DC0(1, g_MemCard.f_6);
    func_80139570(0x38, 0x48);
    ((u8 *)P_801391B0)[3] = 9;
    P_801391B0->code = 0x2D;
    P_801391B0->clut = D_8013AFAC[g_MemCard.f_6 + 11].clut;
    P_801391B0->tpage = 0x87;
    P_801391B0->x0 = 0xF8;
    P_801391B0->y0 = 0x50;
    P_801391B0->x1 = 0x138;
    P_801391B0->y1 = 0x50;
    P_801391B0->x2 = 0xF8;
    P_801391B0->y2 = 0x70;
    P_801391B0->x3 = 0x138;
    P_801391B0->y3 = 0x70;
    P_801391B0->u0 = D_8013AFAC[g_MemCard.f_6 + 11].u;
    P_801391B0->v0 = D_8013AFAC[g_MemCard.f_6 + 11].v;
    P_801391B0->u1 = D_8013AFAC[g_MemCard.f_6 + 11].u + 0x3F;
    P_801391B0->v1 = D_8013AFAC[g_MemCard.f_6 + 11].v;
    P_801391B0->u2 = D_8013AFAC[g_MemCard.f_6 + 11].u;
    P_801391B0->v2 = D_8013AFAC[g_MemCard.f_6 + 11].v + 0x1F;
    P_801391B0->u3 = D_8013AFAC[g_MemCard.f_6 + 11].u + 0x3F;
    P_801391B0->v3 = D_8013AFAC[g_MemCard.f_6 + 11].v + 0x1F;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)" : : "r"(ot), "m"(G_DRAW.prim) : "$2", "$5", "memory");
    G_DRAW.prim += 0x28;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 w, h; } Sprt_8013946C;
typedef struct { u16 x, y, w, h; u8 u, pad9, v, padB; } Img_8013946C;
extern Img_8013946C SaveMenu_Icons[];
#define P_8013946C ((Sprt_8013946C *)G_DRAW.prim)

s32 SaveMenu_DrawIcon(s32 i, s32 x, s32 y) {
    u32 *ot;

    ((u8 *)P_8013946C)[3] = 4;
    P_8013946C->code = 0x65;
    P_8013946C->x0 = x;
    P_8013946C->y0 = y;
    P_8013946C->clut = (SaveMenu_Icons[i].y << 6) | ((SaveMenu_Icons[i].x >> 4) & 0x3F);
    P_8013946C->w = SaveMenu_Icons[i].w;
    P_8013946C->h = SaveMenu_Icons[i].h;
    P_8013946C->u0 = SaveMenu_Icons[i].u;
    P_8013946C->v0 = SaveMenu_Icons[i].v;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0];
    __asm__ volatile("lwl $4, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $4, 2($2)\n\tlw $2, %1\n\tnop\n\taddiu $2, $2, 0x14\n\tsw $2, %1" : : "r"(ot), "m"(G_DRAW.prim) : "$2", "$4", "memory");
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139570;
typedef struct { u16 clut; u8 u, v; } Tex_80139570;
#define P_80139570 ((PolyFT4_80139570 *)G_DRAW.prim)
#define ADDPRIM_80139570(R) __asm__ volatile("lwl " R ", 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl " R ", 2($2)" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", R, "memory")

s32 func_80139570(s32 x, s32 y) {
    s32 i;

    ((u8 *)P_80139570)[3] = 9;
    P_80139570->code = 0x2D;
    P_80139570->clut = D_8013AFAC[0].clut;
    P_80139570->tpage = 8;
    P_80139570->x0 = x;
    P_80139570->y0 = y;
    P_80139570->x1 = x + 8;
    P_80139570->y1 = y;
    P_80139570->x2 = x;
    P_80139570->y2 = y + 0x30;
    P_80139570->x3 = x + 8;
    P_80139570->y3 = y + 0x30;
    P_80139570->u0 = D_8013AFAC[0].u;
    P_80139570->v0 = D_8013AFAC[0].v;
    P_80139570->u1 = D_8013AFAC[0].u + 7;
    P_80139570->v1 = D_8013AFAC[0].v;
    P_80139570->u2 = D_8013AFAC[0].u;
    P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
    P_80139570->u3 = D_8013AFAC[0].u + 7;
    P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
    ADDPRIM_80139570("$6");
    G_DRAW.prim += 0x28;
    for (i = 0; i < 16; i++) {
        ((u8 *)P_80139570)[3] = 9;
        P_80139570->code = 0x2D;
        P_80139570->clut = D_8013AFAC[0].clut;
        P_80139570->tpage = 8;
        P_80139570->x0 = x + 8 + i * 16;
        P_80139570->y0 = y;
        P_80139570->x1 = x + 8 + i * 16 + 16;
        P_80139570->y1 = y;
        P_80139570->x2 = x + 8 + i * 16;
        P_80139570->y2 = y + 0x30;
        P_80139570->x3 = x + 8 + i * 16 + 16;
        P_80139570->y3 = y + 0x30;
        P_80139570->u0 = D_8013AFAC[0].u + 8;
        P_80139570->v0 = D_8013AFAC[0].v;
        P_80139570->u1 = D_8013AFAC[0].u + 0x17;
        P_80139570->v1 = D_8013AFAC[0].v;
        P_80139570->u2 = D_8013AFAC[0].u + 8;
        P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
        P_80139570->u3 = D_8013AFAC[0].u + 0x17;
        P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
        ADDPRIM_80139570("$4");
        G_DRAW.prim += 0x28;
    }
    ((u8 *)P_80139570)[3] = 9;
    P_80139570->code = 0x2D;
    P_80139570->clut = D_8013AFAC[0].clut;
    P_80139570->tpage = 8;
    P_80139570->x0 = x + 0x108;
    P_80139570->y0 = y;
    P_80139570->x1 = x + 0x110;
    P_80139570->y1 = y;
    P_80139570->x2 = x + 0x108;
    P_80139570->y2 = y + 0x30;
    P_80139570->x3 = x + 0x110;
    P_80139570->y3 = y + 0x30;
    P_80139570->u0 = D_8013AFAC[0].u + 0x18;
    P_80139570->v0 = D_8013AFAC[0].v;
    P_80139570->u1 = D_8013AFAC[0].u + 0x1F;
    P_80139570->v1 = D_8013AFAC[0].v;
    P_80139570->u2 = D_8013AFAC[0].u + 0x18;
    P_80139570->v2 = D_8013AFAC[0].v + 0x2F;
    P_80139570->u3 = D_8013AFAC[0].u + 0x1F;
    P_80139570->v3 = D_8013AFAC[0].v + 0x2F;
    __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)\n\tlw $2, %1\n\tnop\n\taddiu $2, $2, 0x28\n\tsw $2, %1" : : "r"(G_DRAW.db[G_DRAW.cur].ot), "m"(G_DRAW.prim) : "$2", "$5", "memory");
    return 0;
}

extern u8 g_MemCardImage[];

s32 SaveMenu_GetSlotLastStage(s32 n) {
    s32 last;
    s32 i;

    last = 1;
    for (i = 0; i < 25; i++) {
        if (g_MemCardImage[i + n * 0x7A0 + 0x1A8] != 0) {
            last = i;
        }
    }
    return last;
}

s32 SaveMenu_DrawMainFrame(void) {
    SaveMenu_DrawFrame(0xC, 0x14, 0x160, 0xC4);
    return 0;
}

typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80139A68;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad[0x8120 - 0x10 - 2 * sizeof(DrawBuf)]; u16 f_8120; } g_Game_80139A68 asm("g_Game");
extern u8 g_ProjVerts[];
void func_801368E8(SVECTOR *eye, SVECTOR *at);
void *RotMatrixX(s32 r, void *m);
void *RotMatrixY(s32 r, void *m);
void *RotMatrixZ(s32 r, void *m);
void Model_ProjectVertsAlt(void *, void *, void *);
void Model_DrawLit();
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 Math_StepToward(s32, s32, s32);

s32 SaveMenu_DrawModel(void) {
    MAT_80139A68 m;
    SVECTOR eye;
    SVECTOR at;
    SVECTOR pos;
    SVECTOR rot;
    s32 target;
    s32 i;

    at.vy = 0;
    at.vx = 0;
    at.vz = 0xA40;
    eye.vy = 0;
    eye.vz = 0;
    eye.vx = 0;
    func_801368E8(&eye, &at);
    func_8002FAF0(0xA4);
    Matrix_SetIdentity(&m);
    RotMatrixZ(D_8013AF70 / 8, &m);
    RotMatrixY(D_8013AF70 / 8, &m);
    RotMatrixX(D_8013AF70 / 8, &m);
    Model_ProjectVertsAlt((void *)D_8013B214, &m, g_ProjVerts);
    Model_DrawLit(&g_Game_80139A68.db[g_Game_80139A68.cur].ot[0xFFF], g_ProjVerts, D_8013B214);
    if (g_Game_80139A68.f_8120 == 0x15) {
        target = -D_8013AF52 << 9;
        if (D_8013AF78 < target - 0x80) {
            D_8013AF78 += 0x80;
        } else if (target + 0x80 < D_8013AF78) {
            D_8013AF78 -= 0x80;
        } else {
            D_8013AF78 = target;
        }
        for (i = 0; i < 3; i++) {
            pos.vx = rsin(D_8013AF78 + i * 0x200) >> 1;
            pos.vy = (rcos(D_8013AF78 + i * 0x200) >> 2) - 0xC8;
            pos.vz = 0xED8 - (rcos(D_8013AF78 + i * 0x200) >> 1);
            rot.vx = 0x80;
            rot.vy = -(u16)g_Game_80139A68.frame * 8;
            rot.vz = 0;
            if (i != 0 || D_8013AF6C != 0) {
                func_8013A804(&pos, &rot, D_8013B214 + (i + 1) * 0x20, 0x1000);
            }
        }
    }
    D_8013AF74 = Math_StepToward(D_8013AF74, 0x10, 0x20);
    D_8013AF70 += D_8013AF74;
    return 0;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PolyFT4_80139CF0;
extern struct { u32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; } g_Game_80139CF0 asm("g_Game");

s32 func_80139CF0(void) {
    PolyFT4_80139CF0 *p;
    u32 *ot;

    p = (PolyFT4_80139CF0 *)g_Game_80139CF0.prim;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->clut = 0x3EE0;
    p->tpage = 8;
    p->x0 = 0x10A;
    p->y0 = 0xA4;
    p->x1 = 0x13A;
    p->y1 = 0xA4;
    p->x2 = 0x10A;
    p->y2 = 0xE4;
    p->x3 = 0x13A;
    p->y3 = 0xE4;
    p->u0 = 0xD0;
    p->v0 = g_Game_80139CF0.frame / 4 % 3 * 64;
    p->u1 = 0xFF;
    p->v1 = g_Game_80139CF0.frame / 4 % 3 * 64;
    p->u2 = 0xD0;
    p->v2 = g_Game_80139CF0.frame / 4 % 3 * 64 + 0x3F;
    p->u3 = 0xFF;
    p->v3 = g_Game_80139CF0.frame / 4 % 3 * 64 + 0x3F;
    ot = g_Game_80139CF0.db[g_Game_80139CF0.cur].ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    p->clut = 0x3EDF;
    ((u8 *)p)[3] = 9;
    p->code = 0x2D;
    p->tpage = 8;
    p->x0 = 0x10A;
    p->y0 = 0xA4;
    p->x1 = 0x15A;
    p->y1 = 0xA4;
    p->x2 = 0x10A;
    p->y2 = 0xE4;
    p->x3 = 0x15A;
    p->y3 = 0xE4;
    p->u0 = 0;
    p->v0 = 0x80;
    p->u1 = 0x50;
    p->v1 = 0x80;
    p->u2 = 0;
    p->v2 = 0xBF;
    p->u3 = 0x50;
    p->v3 = 0xBF;
    ot = g_Game_80139CF0.db[g_Game_80139CF0.cur].ot;
    ADD_PRIM_R(ot, p, "$5", "$3");
    p++;
    g_Game_80139CF0.prim = (u8 *)p;
    return 0;
}

extern struct { u8 pad_0[0x168]; s32 f_168; } g_Pad_80139F08 asm("g_Pad");
extern s16 SaveMenu_YesNo;
void func_8013FFEC(s32);
s32 SaveMenu_ConfirmPressed(void);

s32 SaveMenu_UpdateYesNo(void) {
    func_8013FFEC(SaveMenu_YesNo);
    if (SaveMenu_FadeState != 1) {
        return 0;
    }
    if (g_Pad_80139F08.f_168 == 0x1000) {
        Sound_PlayFixed(0);
        SaveMenu_YesNo = SaveMenu_YesNo == 0;
    }
    if (g_Pad_80139F08.f_168 == 0x4000) {
        Sound_PlayFixed(0);
        SaveMenu_YesNo = SaveMenu_YesNo == 0;
    }
    if (SaveMenu_ConfirmPressed() != 0) {
        Sound_PlayFixed(3);
        return SaveMenu_YesNo + 1;
    }
    return 0;
}

typedef struct { u8 pad0[0x180]; s16 f_180; u8 pad182[0x7A0 - 0x182]; } Slot_80139FC8;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80139FC8 asm("g_Pad");
extern struct { s16 f_0; u8 pad_2[0x4]; s16 f_6; } D_800E3880_80139FC8 asm("g_MemCard");
extern s16 D_8013AFE8[];
extern Slot_80139FC8 D_800E1880_80139FC8[] asm("g_MemCardImage");
s32 SaveMenu_ConfirmPressed(void);
s32 SaveMenu_CancelPressed(void);

s32 func_80139FC8(void) {
    s32 a;

    if (SaveMenu_FadeState != 1) {
        return 0;
    }
    D_8013AF5E = 0;
    if (g_Pad_80139FC8.f_158 & 4) {
        D_8013AF5E = 1;
        if (g_Pad_80139FC8.f_160 & g_Pad_80139FC8.f_158 & 4) {
            Sound_PlayFixed(0xB);
        }
    } else if (g_Pad_80139FC8.f_158 & 8) {
        D_8013AF5E = 2;
        if (g_Pad_80139FC8.f_160 & g_Pad_80139FC8.f_158 & 8) {
            Sound_PlayFixed(0xB);
        }
    }
    if (D_8013AF54 == 0) {
        if (D_800E5488 == 0x1000) {
            Sound_PlayFixed(0);
            do {
                if (--D_8013AF52 < 0) {
                    D_8013AF52 = 4;
                }
            } while (D_8013AFE8[D_8013AF52] != 1);
        } else if (D_800E5488 == 0x4000) {
            Sound_PlayFixed(0);
            do {
                if (++D_8013AF52 >= 5) {
                    D_8013AF52 = 0;
                }
            } while (D_8013AFE8[D_8013AF52] != 1);
        }
        if (D_8013AF52 == 0) {
            if (SaveMenu_ConfirmPressed()) {
                Sound_PlayFixed(3);
                return -4;
            }
            return 0;
        }
        if (D_8013AF52 < 0) {
            return 0;
        }
        if (D_8013AF52 >= 5) {
            return 0;
        }
        if (SaveMenu_ConfirmPressed()) {
            D_8013AF54 = 1;
            g_MemCardSlot = 0;
            Sound_PlayFixed(3);
        }
        return 0;
    }
    if (SaveMenu_CancelPressed()) {
        D_8013AF54 = 0;
        Sound_PlayFixed(1);
        return 0;
    }
    if (SaveMenu_ConfirmPressed()) {
        if (D_8013AF52 == 1) {
            Sound_PlayFixed(3);
            if (D_800E1880_80139FC8[g_MemCardSlot].f_180 >= 0) {
                a = 0xD;
            } else if (D_8013AF64 != 0) {
                a = 4;
            } else {
                MemCard_Request(0, 0);
                a = 6;
            }
        } else if (D_8013AF52 == 2) {
            if (D_800E1880_80139FC8[g_MemCardSlot].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 5;
        } else if (D_8013AF52 == 3) {
            if (D_800E1880_80139FC8[g_MemCardSlot].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 0xF;
        } else if (D_8013AF52 == 4) {
            if (D_800E1880_80139FC8[g_MemCardSlot].f_180 < 0) {
                goto bad;
            }
            Sound_PlayFixed(3);
            a = 7;
        } else {
            return 0;
        }
        SaveMenu_SetScreen(a, 0);
        return 0;
bad:
        Sound_PlayFixed(0x30);
        return 0;
    }
    if (D_800E5488 == 0x1000) {
        Sound_PlayFixed(0);
        if (--D_800E3880_80139FC8.f_6 < 0) {
            D_800E3880_80139FC8.f_6 = 3;
        }
    } else if (D_800E5488 == 0x4000) {
        Sound_PlayFixed(0);
        if (++D_800E3880_80139FC8.f_6 >= 4) {
            D_800E3880_80139FC8.f_6 = 0;
        }
    }
    return 0;
}

extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013A400 asm("g_Pad");

s32 SaveMenu_ConfirmPressed(void) {
    if (SaveMenu_FadeState != 1) {
        return 0;
    }
    return (g_Pad_8013A400.f_160 & g_Pad_8013A400.f_158 & 0x60) != 0;
}

extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_8013A43C asm("g_Pad");

s32 SaveMenu_CancelPressed(void) {
    if (SaveMenu_FadeState != 1) {
        return 0;
    }
    return (g_Pad_8013A43C.f_160 & g_Pad_8013A43C.f_158 & 0x90) != 0;
}

typedef struct { s16 x, y, w, h; } Rect_8013A478;
typedef struct { Rect_8013A478 r[4]; } Rects_8013A478;
typedef struct { u32 id; u32 flag; u8 pad8[0xA18]; } Tim_8013A478;
extern Rects_8013A478 D_8013ADA8;
extern u8 D_8013AFF4[];
extern u8 D_8013ADC8[];
s32 SaveMenu_GetSlotLastStage(s32 n);
void LoadImage2(void *rect, void *p);
void bios_printf(u8 *, ...);

s32 SaveMenu_LoadSlotPicture(s16 n) {
    Rects_8013A478 rects;
    Rect_8013A478 clut;
    u32 *p;

    rects = D_8013ADA8;
    p = (u32 *)&((Tim_8013A478 *)0x80170000)[D_8013AFF4[SaveMenu_GetSlotLastStage(n)]];
    clut.x = 0x1C0;
    clut.y = n + 0xFC;
    clut.w = 0x100;
    clut.h = 1;
    if (*p == 0x10) {
        p++;
        switch (*p & 0xF) {
        case 2:
            LoadImage2(&rects.r[n], (u8 *)p + 0x10);
            break;
        case 8:
        case 9:
            p++;
            LoadImage2(&clut, (u8 *)p + 0xC);
            p = (u32 *)((u8 *)p + ((*p >> 2) << 2));
            LoadImage2(&rects.r[n], (u8 *)p + 0xC);
            break;
        default:
            bios_printf(D_8013ADC8, *p);
            break;
        }
    }
    return 0;
}

extern s16 SaveMenu_FadeTimer;

s32 SaveMenu_UpdateFade(void) {
    switch (SaveMenu_FadeState) {
    case 1:
        return 0;
    case 0:
        SaveMenu_DrawFade();
        if (--SaveMenu_FadeTimer < 0) {
            SaveMenu_FadeState = 1;
            SaveMenu_FadeTimer = 0;
        }
        return 0;
    case 2:
        SaveMenu_DrawFade();
        if (++SaveMenu_FadeTimer >= 0x1F) {
            SaveMenu_FadeState = 1;
            SaveMenu_FadeTimer = 0;
            return -1;
        }
        return 0;
    }
    return 0;
}

s32 SaveMenu_DrawFade(void) {
    u8 *p = G_DRAW.prim;
    s32 v = SaveMenu_FadeTimer * 255 / 30;

    p[3] = 3;
    p[7] = 0x62;
    M2C_FIELD(p, s16 *, 0xC) = 0x180;
    M2C_FIELD(p, s16 *, 0x8) = 0;
    M2C_FIELD(p, s16 *, 0xA) = 0;
    M2C_FIELD(p, s16 *, 0xE) = 0xF0;
    p[4] = p[5] = p[6] = v;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 0x10;
    p[3] = 1;
    M2C_FIELD(p, u32 *, 4) = 0xE1000240;
    ADD_PRIM_R(G_DRAW.db[G_DRAW.cur].ot, p, "$5", "$3");
    p += 8;
    G_DRAW.prim = p;
    return 0;
}

#include "gte.h"
void Model_DrawPrims(s32, u8 *, s32);
void *RotMatrix(void *r, void *m);
void *ScaleMatrix(void *m, void *v);
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_8013A804;
typedef struct { s32 vx, vy, vz, pad; } VEC_8013A804;
typedef struct { u8 pad0[0xE]; u16 n; } Hdr_8013A804;
typedef struct { Hdr_8013A804 *f_0; s32 *f_4; u8 *f_8; } Mdl_8013A804;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_8013A804;
extern VEC_8013A804 D_8013ADD8_8013A804 asm("D_8013ADD8");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_8013A804 asm("g_Game");
extern MAT_8013A804 D_800E78C0_8013A804 asm("g_ViewMatrix");

void func_8013A804(pos, rot, m, light)
    SVECTOR *pos; SVECTOR *rot; Mdl_8013A804 *m; s32 light;
{
    MAT_8013A804 mat;
    VEC_8013A804 scale;
    Scr_8013A804 *sc = (Scr_8013A804 *)0x1F800000;
    u8 *c = m->f_8;
    s32 i;
    s32 n;
    s32 *src;

    sc->f_3F4 = 0;
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    Matrix_SetIdentity(&mat);
    RotMatrix(rot, &mat);
    scale = D_8013ADD8_8013A804;
    ScaleMatrix(&mat, &scale);
    mat.t[2] = pos->vz;
    mat.t[0] = pos->vx;
    mat.t[1] = pos->vy;
    CompMatrix(&D_800E78C0_8013A804, &mat, &mat);
    Model_ProjectVertsAlt(m, &mat, g_ProjVerts);
    n = m->f_0->n;
    src = m->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(light, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    Model_DrawPrims((s32)(g_Game_8013A804.cur * 0x4078 + (u8 *)&g_Game_8013A804 + 0x80), c, (s32)g_ProjVerts);
}
__asm__(".section .text\n.balign 16");
