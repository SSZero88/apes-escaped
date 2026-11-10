#include "common.h"
#include "m2c_macros.h"

M2C_UNK Cd_PlayXaTrack(s32);
extern s32 D_8013705C;

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 g_ViewMatrix;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);
void CompMatrix(void *, void *, void *);
void Matrix_SetIdentity(void *);
void ScaleMatrixL(void *, void *);

void func_80136000(SVECTOR *eye, SVECTOR *at) {
    VEC_391 d;
    VEC_391 n;
    MAT_391 m;
    VEC_391 s;
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
    Matrix_SetIdentity(&m);
    s.vx = 0x2000;
    s.vy = 0x2000;
    s.vz = 0x2000;
    ScaleMatrixL(&m, &s);
    CompMatrix(&m, &g_ViewMatrix, &g_ViewMatrix);
}

u8 *func_801361D8(u8 *arg0, s32 arg1)
{
  s32 var_v0;
  s32 var_v1;
  u8 *var_a0;
  var_a0 = arg0;
  var_v1 = 0;
  if (arg1 > 0)
  {
    do
    {
      var_v0 = var_v1 < arg1;
      if ((*var_a0) == 0)
      {
        var_v1 += 1;
      }
      var_a0 += 1;
      var_v0 = var_v1 < arg1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

typedef struct { s16 x, y, w, h; } Rect_80136208;
typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x, y, w, h; } Tile_80136208;
extern struct { u8 pad0[0x10]; SVECTOR eye; SVECTOR at; u8 pad20[0x14]; s16 tx, ty, tz, n; u8 pad3C[0x20]; s32 f5C; } D_80137010_80136208 asm("D_80137010");
extern struct { u8 pad0[0x24]; s32 f24; s32 f28; s32 f2C; } D_800EBFA0_80136208 asm("D_800EBFA0");
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 mode; } g_Game_80136208 asm("g_Game");
extern s16 D_80136E30;
extern u8 D_80136E34[];
extern s32 g_Cd;
void Mem_Init(void);
s32 Gfx_InitDisplay(void);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
s32 DrawSync(s32 mode);
s32 VSync(s32 mode);
void *PutDispEnv(void *env);
void *PutDrawEnv(void *env);
void DrawOTag(u32 *p);
void func_80136C94(void);
s32 Cd_StartLoadList(void *);
s32 Cd_PollLoadList(void);
void Cd_Update(void);
void Cd_WaitIdle();
s32 func_80136780(void);
s32 Sound_ResumeStreams(void);
void func_8002FAF0(s32);
void Light_SetColorMode(s32, s32, s32, s32);
void func_80136C04(void);
void func_80136C6C(void);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void DebugFont_Init(void);
void func_801368CC(void);
void func_80136AA0(void);
s32 func_80136724(void);
void func_80136000(SVECTOR *eye, SVECTOR *at);

s32 func_80136208(void) {
    Rect_80136208 r = { 0, 0, 0x180, 0x200 };
    SprtTp *p;
    Tile_80136208 *t;
    s32 n, dx, dy, dz;
    u32 *ot;

    Mem_Init();
    Gfx_InitDisplay();
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136208.cur = 0;
    PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
    PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
    VSync(0);
    D_80136E30 = 0;
    func_80136C94();
    Cd_StartLoadList(D_80136E34);
    while (Cd_PollLoadList() >= 0) {
        VSync(2);
        Cd_Update();
    }
    Cd_WaitIdle(0);
    func_80136780();
    Sound_ResumeStreams();
    func_8002FAF0(0x148);
    Light_SetColorMode(0, 0, 0, 0);
    D_800EBFA0_80136208.f24 = 0;
    D_800EBFA0_80136208.f28 = 0x1000;
    D_800EBFA0_80136208.f2C = 0x1000;
    D_80137010_80136208.eye.vx = 0;
    D_80137010_80136208.eye.vy = -0x100;
    D_80137010_80136208.eye.vz = -0x200;
    D_80137010_80136208.tx = 0;
    D_80137010_80136208.ty = -0x100;
    D_80137010_80136208.tz = -0x200;
    D_80137010_80136208.n = 0x3C;
    D_80137010_80136208.at.vx = 0;
    D_80137010_80136208.at.vy = -0x80;
    D_80137010_80136208.at.vz = 0;
    D_80137010_80136208.f5C = 0;
    func_80136000(&D_80137010_80136208.eye, &D_80137010_80136208.at);
    func_80136C04();
    func_80136C6C();
    for (;;) {
        func_8001325C(0);
        Gfx_BeginFrame();
        DebugFont_Init();
        p = (SprtTp *)g_Game_80136208.prim;
        ot = g_Game_80136208.ot;
        ((u8 *)p)[3] = 5;
        p->code = 0x65;
        p->y0 = 0x20;
        p->w = 0xC0;
        p->h = 0x40;
        p->tpage = 0xE1000206;
        p->x0 = 0x60;
        p->u0 = 0;
        p->v0 = 0;
        p->clut = 0x3C1B;
        ADD_PRIM_R(&ot[0xFFF], p, "$4", "$2");
        p++;
        g_Game_80136208.prim = (u8 *)p;
        func_801368CC();
        func_80136AA0();
        t = (Tile_80136208 *)g_Game_80136208.prim;
        *(u32 *)&t->r0 = 0;
        ((u8 *)t)[3] = 3;
        t->code = 0x60;
        *(u32 *)&t->x = 0;
        *(u32 *)&t->w = 0xF00180;
        ADD_PRIM_R(&g_Game_80136208.db[g_Game_80136208.cur].ot[0xFFF], t, "$5", "$3");
        t++;
        g_Game_80136208.prim = (u8 *)t;
        if (func_80136724() < 0 && g_Cd == 0) {
            break;
        }
        DrawSync(0);
        VSync(0);
        g_Game_80136208.frame++;
        PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
        DrawOTag(&g_Game_80136208.db[g_Game_80136208.cur].ot[0xFFF]);
        Cd_Update();
        n = D_80137010_80136208.n;
        if (n > 0) {
            dx = (D_80137010_80136208.tx - D_80137010_80136208.eye.vx) / n;
            dy = (D_80137010_80136208.ty - D_80137010_80136208.eye.vy) / n;
            dz = (D_80137010_80136208.tz - D_80137010_80136208.eye.vz) / n;
            D_80137010_80136208.n = --n;
            D_80137010_80136208.eye.vx += dx;
            D_80137010_80136208.eye.vy += dy;
            D_80137010_80136208.eye.vz += dz;
        }
        func_80136000(&D_80137010_80136208.eye, &D_80137010_80136208.at);
        D_80137010_80136208.f5C++;
    }
    g_Game_80136208.mode = 0xD;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    Gfx_InitDisplay();
    PutDispEnv(&g_Game_80136208.db[g_Game_80136208.cur].env[0x5C]);
    PutDrawEnv(g_Game_80136208.db[g_Game_80136208.cur].env);
    VSync(0);
    return 0;
}

extern s16 D_80136E30;
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; } g_Pad_80136724 asm("g_Pad");

s32 func_80136724(void) {
    if (g_Pad_80136724.f_158 & g_Pad_80136724.f_160 & 0x800) {
        return -1;
    }
    if (++D_80136E30 >= 0x259) {
        return -1;
    }
    return 0;
}

extern struct { u8 pad0[0x8280]; s32 f_8280; } g_Game_80136780 asm("g_Game");
extern s32 g_StageMeshes;
typedef struct { u8 pad0[0x18]; u8 *f_18; u8 pad1C[0x40]; s16 f_5C, f_5E, f_60, f_62, f_64; u8 pad66[0xA]; s16 f_70, f_72; u8 *f_74; u8 pad78[0x10]; } Obj_80136780;
extern Obj_80136780 D_80136F00[];
u8 *Mem_AllocPages(s32);
void Model_BindMesh(void *, u32 *);
void Model_BindBoned(void *, u8 *);

s32 func_80136780(void) {
    u8 *h;
    s32 i;
    Obj_80136780 *e;
    u8 *q;

    h = (u8 *)0x80154000;
    g_Game_80136780.f_8280 = 2;
    g_StageMeshes = (s32)Mem_AllocPages(0x40);
    for (i = 0; i < g_Game_80136780.f_8280; i++) {
        Model_BindMesh((void *)(g_StageMeshes + i * 0x20), (u32 *)(h + *(u16 *)(h + i * 4 + 0x14) * 4));
    }
    for (i = 0; i < 2; i++) {
        Model_BindBoned(&D_80136F00[i], h + *(u16 *)(h + i * 4 + 4) * 4);
        q = (u8 *)(*(u16 *)(h + i * 4 + 0xC) * 4 + (s32)h);
        D_80136F00[i].f_18 = q + *(s32 *)q * 4 + 4;
        D_80136F00[i].f_74 = h + *(u16 *)(h + i * 4 + 0xC) * 4 + 4;
        D_80136F00[i].f_5C = 0;
        D_80136F00[i].f_5E = 0;
        D_80136F00[i].f_70 = 0;
        D_80136F00[i].f_72 = 0;
        D_80136F00[i].f_60 = 0;
        D_80136F00[i].f_62 = 0;
        D_80136F00[i].f_64 = -0x1000;
    }
    return 0;
}

extern struct { s32 f_0; u8 pad4[4]; void *f_8; } g_Game_801368CC asm("g_Game");
extern u8 D_80136F00_801368CC[] asm("D_80136F00");
extern u8 D_800E7D00_801368CC[] asm("g_ProjVerts");
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_801368CC;
typedef struct { s32 vx, vy, vz, pad; } VEC_801368CC;
void* RotMatrixZYX(void* r, void* m);
void* ScaleMatrix(void* m, void* v);
s32 rsin(s32 a);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4_801368CC(void *, void *, void *) asm("Model_Draw");
void Model_ProjectVertsAlt(void *, void *, void *);
void Model_DrawColorAnim(void *, void *, void *, s32);

void func_801368CC(void) {
    MAT_801368CC mat;
    SVECTOR r;
    VEC_801368CC s;
    u8 *m = D_80136F00_801368CC;
    s32 v;

    r.vx = 0;
    r.vz = 0;
    r.vy = g_Game_801368CC.f_0 * 12;
    RotMatrixZYX(&r, M2C_FIELD(m, void **, 0x14));
    M2C_FIELD(m, s32 *, 0x24) = 0;
    M2C_FIELD(m, s32 *, 0x28) = 0;
    M2C_FIELD(m, s32 *, 0x2C) = 0;
    M2C_FIELD(m, u16 *, 0x5C)++;
    if (*(s16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, u16 *, 0x5E) * 4 + 2) < M2C_FIELD(m, u16 *, 0x5C)) {
        M2C_FIELD(m, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(m, u8 **, 0x74) + M2C_FIELD(m, s16 *, 0x70) * 4);
        M2C_FIELD(m, u16 *, 0x5E) = M2C_FIELD(m, u16 *, 0x70);
    }
    Model_CalcKeyedJointMatrices(m, 1);
    Model_ProjectBonedVerts(m);
    func_80017CD4_801368CC(g_Game_801368CC.f_8, D_800E7D00_801368CC, m);
    Model_ProjectVertsAlt((void *)g_StageMeshes, M2C_FIELD(m, void **, 0x14), D_800E7D00_801368CC);
    Model_DrawColorAnim(g_Game_801368CC.f_8, D_800E7D00_801368CC, (void *)g_StageMeshes, 0);
    r.vx = 0;
    r.vz = 0;
    r.vy = g_Game_801368CC.f_0 * -64;
    RotMatrixZYX(&r, &mat);
    v = rsin(g_Game_801368CC.f_0 << 7) >> 3;
    s.vx = 0x1000 - v;
    s.vz = 0x1000 - v;
    s.vy = v + 0x1000;
    ScaleMatrix(&mat, &s);
    mat.t[0] = 0;
    mat.t[1] = -0x80;
    mat.t[2] = 0x60;
    CompMatrix(M2C_FIELD(m, void **, 0x14), &mat, &mat);
    Model_ProjectVertsAlt((void *)(g_StageMeshes + 0x20), &mat, D_800E7D00_801368CC);
    Model_DrawColorAnim(g_Game_801368CC.f_8, D_800E7D00_801368CC, (void *)(g_StageMeshes + 0x20), 0);
}

typedef struct { u8 pad0[0x14]; s16 *f_14; u8 pad18[0xC]; s32 f_24, f_28, f_2C; u8 pad30[0x2C]; u16 f_5C; u16 f_5E; SVECTOR f_60; u8 pad68[8]; s16 f_70, f_72; s16 *f_74; } Obj_80136AA0;
extern Obj_80136AA0 D_80136F88;
extern struct { u8 pad0[0x54]; u32 f_54; u8 pad58[4]; u32 f_5C; } D_80137010_80136AA0 asm("D_80137010");
extern s32 D_80137060;
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_80136AA0 asm("g_Game");
extern u8 D_800E7D00_80136AA0[] asm("g_ProjVerts");
void VectorNormalSS(void *, void *);
void Matrix_FromFacingXZ(s16 *, s16 *);
s32 Math_StepToward(s32, s32, s32);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017CD4_80136AA0(void *, void *, void *) asm("Model_Draw");

void func_80136AA0(void) {
    SVECTOR v;
    Obj_80136AA0 *o;
    s32 stop;
    u16 t;

    stop = 0;
    o = &D_80136F88;
    if (D_80137010_80136AA0.f_5C >= D_80137010_80136AA0.f_54) {
        o->f_5C++;
        if (o->f_74[o->f_5E * 2 + 1] < o->f_5C) {
            if (o->f_70 < 0) {
                o->f_5C--;
                stop = 1;
            } else {
                t = o->f_74[o->f_70 * 2];
                o->f_5E = o->f_70;
                o->f_5C = t;
            }
        }
        VectorNormalSS(&o->f_60, &v);
        Matrix_FromFacingXZ((s16 *)&v, o->f_14);
        if (stop) {
            o->f_24 = Math_StepToward(o->f_24, 0x13C, 0x10);
            o->f_2C = -300;
        } else {
            o->f_24 = 0x40;
            o->f_2C = -300;
            o->f_28 = (o->f_28 + D_80137060 + 0x30) >> 1;
        }
        Model_CalcKeyedJointMatrices(o, 1);
        Model_ProjectBonedVerts(o);
        func_80017CD4_80136AA0(g_Game_80136AA0.f_80 + g_Game_80136AA0.f_C * 0x4078, D_800E7D00_80136AA0, o);
    }
}

typedef struct { u8 f_0; u8 f_1; u8 pad2[10]; } Ent_394;
extern Ent_394 D_80136E4C[];
extern s32 D_80137058;
extern struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x30]; u16 f_5C; u16 f_5E; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0xA]; s16 f_70; u8 pad72[2]; u8 *f_74; } D_80136F88_80136C04 asm("D_80136F88");

void func_80136C04(void) {
    s32 i = D_80137058;
    s32 n = D_80136E4C[i].f_1;
    u16 fr = *(u16 *)(n * 4 + D_80136F88_80136C04.f_74);

    D_80136F88_80136C04.f_60 = -0x400;
    D_80136F88_80136C04.f_64 = -0x1000;
    D_80136F88_80136C04.f_70 = -1;
    D_80136F88_80136C04.f_5E = n;
    D_80136F88_80136C04.f_28 = 0x200;
    D_80136F88_80136C04.f_5C = fr;
}

void func_80136C6C(void) {
    Cd_PlayXaTrack(D_8013705C);
}

typedef struct { s16 f0; u16 f2; s16 f4; s16 f6; u16 f8; s16 fA; } Ent_80136C94;
extern struct { u32 f0; } g_Game_80136C94 asm("g_Game");
extern Ent_80136C94 D_80136E4C_80136C94[] asm("D_80136E4C");
extern struct { u8 pad0[0x48]; s32 f48, f4C, f50, f54; } D_80137010_80136C94 asm("D_80137010");
extern u16 D_80136E3C_80136C94 asm("D_80136E3C");
s32 SaveByte_Get(s32);
s32 World_GetProgress(s32);

void func_80136C94(void) {
    u32 i;

    i = g_Game_80136C94.f0 % 14;
    switch (i) {
    case 0:
    case 1:
    case 2:
        if (World_GetProgress(0x11) > 0 && SaveByte_Get(4) != 5) {
            i += 6;
        }
        break;
    case 3:
    case 4:
    case 5:
        if (World_GetProgress(0x11) > 0 && SaveByte_Get(5) != 5) {
            i += 3;
        }
        break;
    case 9:
    case 10:
        if (SaveByte_Get(8) == 5) {
            i -= 2;
        }
        break;
    case 11:
    case 12:
    case 13:
        if (SaveByte_Get(0xC) == 5) {
            i -= 5;
        }
        break;
    }
    D_80137010_80136C94.f48 = i;
    D_80137010_80136C94.f4C = D_80136E4C_80136C94[i].f2;
    D_80137010_80136C94.f50 = D_80136E4C_80136C94[i].f6;
    D_80137010_80136C94.f54 = D_80136E4C_80136C94[i].f4;
    D_80136E3C_80136C94 = D_80136E4C_80136C94[i].f8;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
