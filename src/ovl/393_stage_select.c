#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_393;
void Gfx_InitDisplay(void);
void ResetGraph(s32);
void ClearImage(Rect_393 *, s32, s32, s32);
void DrawSync(s32);
typedef struct { u8 pad0[0x12C]; s16 world[24]; } StageSet_393;
extern StageSet_393 D_80138A20[];

s32 func_80136000(void) {
    Rect_393 r = { 0, 0, 0x180, 0x200 };

    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    return 0;
}

/* Stage-select screen main loop: one world per Era plus single-stage worlds (Stadium Attack,
   Gladiator Attack, Monkey Madness, Peak Point Matrix); per frame it spins the centrepiece, draws a
   marker per stage of the current world and the time panel. On TV Tower (world 7, stage 2) the
   camera eye rises to -0x578 so the view tilts up the skyscraper model; elsewhere it eases back to 0.
   Near-miss C draft (31 diffs): wip/_ovl/drafts/393/StageSelect_Main.c */
INCLUDE_ASM("asm/ovl/393/nonmatchings/393_stage_select", StageSelect_Main);

#include "gte.h"
void Model_DrawPrims(s32, u8 *, s32);
void Model_ProjectVertsAlt(void *, void *, void *);
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_801375C0;
typedef struct { u8 pad0[0xE]; u16 n; } Hdr_801375C0;
typedef struct { Hdr_801375C0 *f_0; s32 *f_4; u8 *f_8; } Mdl_801375C0;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_801375C0;
extern u8 D_800E7D00_801375C0[] asm("D_800E7D00");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_801375C0 asm("g_Game");
extern MAT_801375C0 D_800E78C0_801375C0 asm("D_800E78C0");

void func_801375C0(pos, rot, m, light)
    SVECTOR *pos; SVECTOR *rot; Mdl_801375C0 *m; s32 light;
{
    MAT_801375C0 mat;
    Scr_801375C0 *sc = (Scr_801375C0 *)0x1F800000;
    u8 *c = m->f_8;
    s32 i;
    s32 n;
    s32 *src;

    sc->f_3F4 = 0;
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    func_8004637C(&mat);
    mat.t[2] = pos->vz;
    mat.t[0] = pos->vx;
    mat.t[1] = pos->vy;
    RotMatrix(rot, &mat);
    CompMatrix(&D_800E78C0_801375C0, &mat, &mat);
    Model_ProjectVertsAlt(m, &mat, D_800E7D00_801375C0);
    n = m->f_0->n;
    src = m->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(light, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    Model_DrawPrims((s32)(g_Game_801375C0.cur * 0x4078 + (u8 *)&g_Game_801375C0 + 0x80), c, (s32)D_800E7D00_801375C0);
}

typedef struct { s16 m[3][3]; s32 t[3]; } MAT_80137714;
typedef struct { u8 pad0[0xE]; u16 n; } Hdr_80137714;
typedef struct { Hdr_80137714 *f_0; s32 *f_4; u8 *f_8; } Mdl_80137714;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } Scr_80137714;
extern u8 D_800E7D00_80137714[] asm("D_800E7D00");
extern struct { u8 pad0[0xC]; s32 cur; } g_Game_80137714 asm("g_Game");
extern MAT_80137714 D_800E78C0_80137714 asm("D_800E78C0");

void func_80137714(pos, rot, m, light)
    SVECTOR *pos; SVECTOR *rot; Mdl_80137714 *m; s32 light;
{
    MAT_80137714 mat;
    Scr_80137714 *sc = (Scr_80137714 *)0x1F800000;
    u8 *c = m->f_8;
    s32 i;
    s32 n;
    s32 *src;

    sc->f_3F4 = 1;
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    func_8004637C(&mat);
    mat.t[2] = pos->vz;
    mat.t[0] = pos->vx;
    mat.t[1] = pos->vy;
    RotMatrix(rot, &mat);
    CompMatrix(&D_800E78C0_80137714, &mat, &mat);
    Model_ProjectVertsAlt(m, &mat, D_800E7D00_80137714);
    n = m->f_0->n;
    src = m->f_4;
    for (i = 0; i < n; i++) {
        gte_ldIR(light, 0, 0);
        gte_ldRGB(&src[i]);
        gte_cc();
        gte_stRGB2(&sc->rgb[i]);
    }
    Model_DrawPrims((s32)(g_Game_80137714.cur * 0x4078 + (u8 *)&g_Game_80137714 + 0x80), c, (s32)D_800E7D00_80137714);
}

extern u8 g_Game[];
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013786C;
extern Mat_8013786C D_800E78C0_8013786C asm("D_800E78C0");
extern u8 D_800E7D00_8013786C[] asm("D_800E7D00");
void func_8004637C(Mat_8013786C *);
void RotMatrix(void *, Mat_8013786C *);
void CompMatrix(Mat_8013786C *, Mat_8013786C *, Mat_8013786C *);
void Model_ProjectVerts(void *, Mat_8013786C *, void *);
void Model_CalcEnvMapUVs64(void *);
void func_8001CE54(void *, void *, void *);

void func_8013786C(s16 *pos, void *rot, void *mdl) {
    Mat_8013786C m;
    u8 *sc = (u8 *)0x1F800000;

    sc[0x3F4] = 1;
    *(s16 *)(sc + 0x3C6) = 0;
    *(s16 *)(sc + 0x3C4) = 0;
    func_8004637C(&m);
    m.t[2] = pos[2];
    m.t[0] = pos[0];
    m.t[1] = pos[1];
    RotMatrix(rot, &m);
    CompMatrix(&D_800E78C0_8013786C, &m, &m);
    Model_ProjectVerts(mdl, &m, D_800E7D00_8013786C);
    Model_CalcEnvMapUVs64(mdl);
    func_8001CE54(g_Game + 0x80 + G_DRAW.cur * 0x4078, D_800E7D00_8013786C, mdl);
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, p1; s16 x1, y1; u8 r2, g2, b2, p2; s16 x2, y2; u8 r3, g3, b3, p3; s16 x3, y3; } PolyG4_80137950;
extern struct { s32 frame; PolyG4_80137950 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x26]; u16 f_8126; u8 pad8128[0x1A4]; u8 f_82CC; u8 f_82CD; } g_Game_80137950 asm("g_Game");
extern struct { u8 pad0[0x158]; u32 f_158; u8 pad15C[4]; u32 f_160; u8 pad164[4]; s32 f_168; } g_Pad_80137950 asm("g_Pad");
typedef struct { s16 x, y; u16 clut; u16 tpage; u32 *ot; } Pen_80137950;
extern Pen_80137950 D_80139CF0_80137950 asm("D_80139CF0");
typedef struct { char name[0x12C]; s16 world[24]; } StageSet_80137950;
extern StageSet_80137950 D_80138A20_80137950[] asm("D_80138A20");
extern s32 D_80139BDC;
extern s32 D_80139BC4;
extern s32 D_80139BC8;
extern s32 D_80139BCC;
extern s32 D_80139BD4;
extern s32 D_80139BD8;
extern s32 D_80139BE0;
extern u8 D_80139BE4;
extern s32 D_80139BE8;
extern u32 D_800E5488;
extern s8 D_80139978[][4];
extern u8 D_80139914[];
extern u8 D_80139B20[];
extern char D_80138A08[];
extern char D_80138A18[];
s32 Sound_UnloadBanks(s32);
s32 Sound_PlayFixed(s32);
void func_8008C3C0(s32, s32);
void DebugFont_Printf(char *, ...);
s32 func_800116C0(void);
s32 func_800976B8(s32, s32);
#define PAD_80137950 (g_Pad_80137950.f_160 & g_Pad_80137950.f_158)

s32 func_80137950(void) {
    s32 i;
    s32 d;
    s32 stg;
    s32 r;
    u8 *s;
    u32 *ot;

    switch (D_80139BDC) {
    case 0:
        if ((PAD_80137950 & 3) == 3) {
            Sound_UnloadBanks(0);
            return -1;
        }
        if (PAD_80137950 & 0x800) {
            Sound_PlayFixed(2);
            if (D_80139BC4 < 11) {
                D_80139BDC = 3;
                D_80139BC8 = 0;
                D_80139BE8 = 0;
                while (1) {
                    if (D_80138A20_80137950[D_80139BC4].world[D_80139BE8] == -2) {
                        D_80139BE8--;
                        break;
                    }
                    D_80139BE8++;
                }
            }
        } else if (PAD_80137950 & 0x4000) {
            Sound_PlayFixed(0);
            D_80139BE4 = 8;
            D_80139BC4 += 3;
            if (D_80139BC4 >= 11) {
                D_80139BC4 %= 3;
            }
        } else if (PAD_80137950 & 0x1000) {
            Sound_PlayFixed(0);
            D_80139BE4 = 8;
            D_80139BC4 -= 3;
            if (D_80139BC4 < 0) {
                D_80139BC4 = (D_80139BC4 + 3) % 3 + 9;
                if (D_80139BC4 >= 11) {
                    D_80139BC4 -= 3;
                }
            }
        } else if (PAD_80137950 & 0x8004) {
            Sound_PlayFixed(0);
            D_80139BE4 = 8;
            D_80139BC4 = D_80139BC4 / 3 * 3 + (D_80139BC4 + 2) % 3;
            if (D_80139BC4 >= 11) {
                D_80139BC4 = 10;
            }
        } else if (PAD_80137950 & 0x2008) {
            Sound_PlayFixed(0);
            D_80139BE4 = 8;
            D_80139BC4 = D_80139BC4 / 3 * 3 + (D_80139BC4 + 4) % 3;
            if (D_80139BC4 >= 11) {
                D_80139BC4 = 10;
            }
        }
        func_8008C3C0(0x82, 10);
        DebugFont_Printf(D_80138A08);
        for (i = 0; i < 11; i++) {
            if (i == D_80139BC4) {
                d = 5 - D_80139BE4;
            } else {
                d = 0;
            }
            func_8008C3C0((i % 3) * 80 + 0x82 + d / 2, (i / 3) * 15 + 0x1C);
            DebugFont_Printf(D_80138A18, D_80138A20_80137950[i].name);
        }
        {
        register typeof(g_Game_80137950) *gd asm("$4") = &g_Game_80137950;
        ((u8 *)gd->prim)[3] = 8;
        gd->prim->code = 0x38;
        gd->prim->code |= 2;
        gd->prim->x0 = (D_80139BC4 % 3) * 80 + 0x7C;
        gd->prim->y0 = (D_80139BC4 / 3) * 15 + 0x1E;
        gd->prim->x1 = (D_80139BC4 % 3) * 80 + 0xBA;
        gd->prim->y1 = (D_80139BC4 / 3) * 15 + 0x1E;
        gd->prim->x2 = (D_80139BC4 % 3) * 80 + 0x7C;
        gd->prim->y2 = (D_80139BC4 / 3) * 15 + 0x25;
        gd->prim->x3 = (D_80139BC4 % 3) * 80 + 0xBA;
        gd->prim->y3 = (D_80139BC4 / 3) * 15 + 0x25;
        gd->prim->r0 = 0xF5;
        gd->prim->g0 = 0xDC;
        gd->prim->b0 = 0xC8;
        gd->prim->r1 = 0xE6;
        gd->prim->g1 = 0x46;
        gd->prim->b1 = 0x28;
        gd->prim->r2 = 0xC4;
        gd->prim->g2 = 0x46;
        gd->prim->b2 = 0x3C;
        gd->prim->r3 = 0x5F;
        gd->prim->g3 = 0xA;
        gd->prim->b3 = 8;
        ot = g_Game_80137950.db[g_Game_80137950.cur].ot;
        __asm__ volatile("lwl $5, 2(%0)\n\tlw $2, %1\n\tsll $2, $2, 8\n\tswl $2, 2(%0)\n\tlw $2, %1\n\tswl $5, 2($2)" : : "r"(ot), "m"(gd->prim) : "$2", "$5", "memory");
        gd->prim++;
        }
        D_80139BE4 >>= 1;
        break;
    case 1:
        if (func_800116C0() < 0) {
            return -2;
        }
        break;
    case 3:
        if (D_80139BC4 < 10) {
            s = func_801387FC(D_80139B20, D_80139BC4);
            D_80139CF0_80137950.x = 0xC0 - func_8013882C(s) / 2;
            D_80139CF0_80137950.y = 0x2B;
            D_80139CF0_80137950.clut = 0x3FA3;
            D_80139CF0_80137950.ot = g_Game_80137950.db[g_Game_80137950.cur].ot;
            func_80138700(s);
        }
        if (D_80139BD8 != 0) {
            break;
        }
        switch (D_800E5488) {
        case 0x10:
        case 0x80:
            Sound_UnloadBanks(1);
            Sound_PlayFixed(1);
            return -7;
        case 0x20:
        case 0x40:
        case 0x800:
            if (D_80139978[D_80139BC4][D_80139BCC] == -1) {
                break;
            }
            stg = D_80139914[D_80139BCC * 2 + D_80139BC4 * 9 + 1];
            D_80139BC8 = stg;
            g_Game_80137950.f_8126 = D_80138A20_80137950[D_80139BC4].world[stg];
            r = func_800976B8(D_80138A20_80137950[D_80139BC4].world[stg], g_Pad_80137950.f_168);
            if (g_Pad_80137950.f_168 == 0x800 && (r != 3 || g_Game_80137950.f_8126 == 0x57)) {
                break;
            }
            Sound_UnloadBanks(1);
            Sound_PlayFixed(3);
            g_Game_80137950.f_82CC = D_80139BC4;
            g_Game_80137950.f_82CD = D_80139BCC;
            if (r == 0) {
                return -3;
            }
            if (r == 2) {
                return -6;
            }
            if (r == 3) {
                return -8;
            }
            return -4;
        case 0x100:
        case 0x1000:
        case 0x4000:
            break;
        case 0x2000:
            if (D_80139914[D_80139BC4 * 9] > D_80139BCC + 1) {
                if (func_801382D8(D_80139BC4, D_80139BCC + 1)) {
                    D_80139BE0 = 0;
                    D_80139BCC++;
                    Sound_PlayFixed(0);
                    break;
                }
            }
            if (D_80139BC4 < 9) {
                if (func_801382D8(D_80139BC4 + 1, 0)) {
                    D_80139BD8 = -1;
                    D_80139BD4 = 0;
                    D_80139BE0 = 0;
                    Sound_PlayFixed(0xB);
                }
            }
            break;
        case 0x8000:
            if (D_80139BCC > 0) {
                D_80139BCC--;
                D_80139BE0 = 0;
                Sound_PlayFixed(0);
                break;
            }
            if (D_80139BC4 != 0) {
                D_80139BD4 = 0;
                D_80139BD8 = 1;
                D_80139BE0 = 0;
                Sound_PlayFixed(0xB);
            }
            break;
        case 4:
            if (D_80139BC4 != 0) {
                D_80139BD4 = 0;
                D_80139BD8 = 1;
                D_80139BE0 = 0;
                Sound_PlayFixed(0xB);
            }
            break;
        case 8:
            if (D_80139BC4 < 9) {
                if (func_801382D8(D_80139BC4 + 1, 0)) {
                    D_80139BD8 = -1;
                    D_80139BD4 = 0;
                    D_80139BE0 = 0;
                    Sound_PlayFixed(0xB);
                }
            }
            break;
        }
        break;
    default:
        return 0;
    }
    return 0;
}

extern u8 D_80139914[];
s32 Stage_GetWorld(s32);
s32 func_80096580_801382D8(s32) asm("func_80096580");
extern s8 D_801399A8[][4];
extern s8 D_801399D4[];

s32 func_801382D8(s32 world, s32 stage) {
    s32 i;
    s32 r;

    if (Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]) == 1) {
        return 1;
    }
    if (world < 9) {
        return func_80096580_801382D8(D_801399A8[world][stage]) > 0;
    }
    r = 1;
    for (i = 0; D_801399D4[i] > 0; i++) {
        if (func_80096580_801382D8(D_801399D4[i]) < 2) {
            r = 0;
            break;
        }
    }
    return r;
}

extern u8 D_80139914[];
s32 Stage_GetWorld(s32);
void func_80096580(s32);

void func_801383EC(s32 world, s32 stage) {
    func_80096580(Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]));
}

typedef struct { u8 pad0[0xE]; u16 f_E; } Info_80138468;

s32 func_80138468(s32 world, s32 stage) {
    s32 w;

    w = Stage_GetWorld(D_80138A20[world].world[D_80139914[stage * 2 + world * 9 + 1]]);
    Stage_GetInfo(w, (void *)0x1F800000);
    switch (w) {
    case 14:
        return func_800964B0(0x24) & 0x10;
    case 7:
        return func_800964B0(0x13) & 0x10;
    case 30:
        return 0;
    default:
        return func_80097FB0(w) == (s16)((volatile Info_80138468 *)0x1F800000)->f_E;
    }
}

typedef struct { s32 vx, vy, vz, pad; } VEC_391;
typedef struct { s16 m[3][3]; s32 t[3]; } MAT_391;
extern MAT_391 D_800E78C0;
extern MAT_391 D_800AF0A0;
void VectorNormal(void *, void *);
s32 SquareRoot0(s32);
void ApplyMatrixLV(void *, void *, void *);

void StageSelect_SetCamera(SVECTOR *eye, SVECTOR *at) {
    VEC_391 d;
    VEC_391 n;
    s32 nx;
    s32 nz;
    s32 ny;
    s32 h;

    D_800E78C0.t[0] = -eye->vx;
    D_800E78C0.t[1] = -eye->vy;
    D_800E78C0.t[2] = -eye->vz;
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
    D_800E78C0.m[0][0] = nz;
    D_800E78C0.m[0][1] = 0;
    D_800E78C0.m[0][2] = nx;
    D_800E78C0.m[1][0] = (nx * ny) >> 12;
    D_800E78C0.m[1][1] = h;
    D_800E78C0.m[1][2] = -(ny * nz) >> 12;
    D_800E78C0.m[2][0] = -(h * nx) >> 12;
    D_800E78C0.m[2][1] = ny;
    D_800E78C0.m[2][2] = (h * nz) >> 12;
    ApplyMatrixLV(&D_800E78C0, D_800E78C0.t, D_800E78C0.t);
    CompMatrix(&D_800AF0A0, &D_800E78C0, &D_800E78C0);
}

extern u16 D_800AE8F2;
extern u8 *D_800EC354;
extern u8 D_80139BF0[];
typedef struct { s16 x, y; u16 clut; u16 tpage; u32 *ot; } Pen_80138700;
extern Pen_80138700 D_80139CF0;

void func_80138700(u8 *s) {
    SprtTp *p;
    u32 c;
    u32 r;

    p = (SprtTp *)D_800EC354;
    while ((c = *s) != 0) {
        ((u8 *)p)[3] = 5;
        p->tpage = (D_80139CF0.tpage & 0x9FF) | 0xE1000200;
        p->code = 0x67;
        r = ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) & 1;
        p->x0 = D_80139CF0.x;
        p->y0 = D_80139CF0.y - r;
        p->u0 = (c & 0xF) << 4;
        p->v0 = c & 0xF0;
        p->clut = D_80139CF0.clut;
        p->w = 0x10;
        p->h = 0x10;
        { register u32 *ot asm("$3") = D_80139CF0.ot; ADD_PRIM_R(ot, p, "$4", "$2"); }
        p++;
        D_80139CF0.x += D_80139BF0[c];
        s++;
    }
    D_800EC354 = (u8 *)p;
}

u8 *func_801387FC(u8 *arg0, s32 arg1)
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
      var_v0 = var_v1 < arg1;
      var_a0 += 1;
    }
    while (var_v0 != 0);
  }
  return var_a0;
}

extern u8 D_80139BF0[];

s32 func_8013882C(u8 *s) {
    s32 w;

    w = 0;
    for (; *s != 0; s++) {
        w += D_80139BF0[*s];
    }
    return w;
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; } Tile1_8013886C;

void func_8013886C(void) {
    s32 seed = 0;
    s32 i;
    s32 x;
    Tile1_8013886C *p;
    u32 *ot;

    p = (Tile1_8013886C *)G_DRAW.prim;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    for (i = 0; i < 300; i++) {
        x = seed = (seed * 87 + 1) & 0x1FF;
        seed = (seed * 87 + 1) & 0x1FF;
        *(u32 *)&p->r0 = 0xFFFFFF;
        ((u8 *)p)[3] = 2;
        p->code = 0x68;
        p->x0 = x;
        p->y0 = seed;
        ADD_PRIM_ASM(ot, p);
        p++;
    }
    G_DRAW.prim = (u8 *)p;
}

typedef struct { s16 x, y; } Pt_8013893C;
s32 VectorNormalSS(SVECTOR *, SVECTOR *);
s32 rsin(s32);
s32 rcos(s32);

s32 func_8013893C(s32 x, s32 y) {
    SVECTOR d;
    Pt_8013893C p;
    s32 r;

    d.vx = 0xC0 - x;
    d.vy = 0x78 - y;
    d.vz = 0;
    r = SquareRoot0(VectorNormalSS(&d, &d)) << 5;
    p.x = x + (rsin(r) >> 16);
    p.y = y + (rcos(r) >> 16);
    return *(s32 *)&p;
}
