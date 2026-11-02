#include "common.h"
#include "m2c_macros.h"

M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);

extern u16 g_RandSeed;

INCLUDE_ASM("asm/ovl/421/nonmatchings/421_monkey_madness_f6_obj", func_80140D60);

s16 Floor_GetHeight(s16, s16, s16);
extern struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } D_80144590_8013D028[] asm("D_80141880");
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)

void func_80140D88(SVECTOR *arg0, s32 arg1) {
    s32 i;
    u16 x = arg0->vx;
    u16 y = arg0->vy;
    u16 z = arg0->vz;
    s16 floor = Floor_GetHeight(arg0->vx, arg0->vy, arg0->vz);

    for (i = 15; i >= 0; i--) {
        if (D_80144590_8013D028[i].life == 0) {
            D_80144590_8013D028[i].life = (RAND() >> 8 & 0x1F) + 0x28;
            D_80144590_8013D028[i].floor = floor;
            D_80144590_8013D028[i].x = x + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].y = y - ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].z = z + ((RAND() >> 8) - 0x80) / 4;
            D_80144590_8013D028[i].vx = ((RAND() >> 8) - 0x80) / 8;
            D_80144590_8013D028[i].vy = -(RAND() >> 8 & 0x1F) - 0x18;
            D_80144590_8013D028[i].vz = ((RAND() >> 8) - 0x80) / 8;
            if (--arg1 == 0) {
                break;
            }
        }
    }
}

#define gte_ldv3c_(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0); lwc2 $2, 8(%0); lwc2 $3, 12(%0); lwc2 $4, 16(%0); lwc2 $5, 20(%0)" : : "r"(v))
#define gte_rtpt_n() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3c_(p) __asm__ volatile ("swc2 $12, 0(%0); swc2 $13, 4(%0); swc2 $14, 8(%0)" : : "r"(p) : "memory")
#define gte_stszotz(r0) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(r0) : "$12", "memory")
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mtx_80140F78;
typedef struct { SVECTOR v[3]; u8 pad[8]; } Tri_80140F78;
typedef struct { Mtx_80140F78 m; Mtx_80140F78 cam; SVECTOR rot; Tri_80140F78 tri[4]; s32 sxy[3]; s32 otz; } Scr_80140F78;
typedef struct { s16 x, y, z, floor; s8 vx, vy, vz; u8 life; } Rock_80140F78;
extern Rock_80140F78 D_80141880_80140F78[] asm("D_80141880");
extern Mtx_80140F78 D_800E78C0_80140F78 asm("D_800E78C0");
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80140F78;
typedef struct { u32 tag; u32 rgb0; s32 xy0; u32 rgb1; s32 xy1; u32 rgb2; s32 xy2; } PolyG3_80140F78;
extern struct { u8 pad_0[0x4]; u32 *f_4; u8 pad_8[4]; s32 f_C; u8 pad_10[0x70]; u8 f_80[1]; } g_Game_80140F78 asm("g_Game");
void *RotMatrixZYX(void *r, void *m);
void *CompMatrix(void *m0, void *m1, void *m2);

s32 func_80140F78(void) {
    Scr_80140F78 *sc = (Scr_80140F78 *)0x1F800000;
    Rock_80140F78 *p;
    PolyG3_80140F78 *g;
    u32 *ot;
    s32 i;

    sc->cam = D_800E78C0_80140F78;
    sc->tri[0].v[0].vx = -0x1C;
    sc->tri[0].v[0].vy = -0x1C;
    sc->tri[0].v[0].vz = 0;
    sc->tri[0].v[1].vx = 0x1C;
    sc->tri[0].v[1].vy = -0x1C;
    sc->tri[0].v[1].vz = 0;
    sc->tri[0].v[2].vx = 0;
    sc->tri[0].v[2].vy = 0x1C;
    sc->tri[0].v[2].vz = 0;
    sc->tri[1].v[0].vx = -0x38;
    sc->tri[1].v[0].vy = -0x38;
    sc->tri[1].v[0].vz = 0;
    sc->tri[1].v[1].vx = 0x38;
    sc->tri[1].v[1].vy = -0x38;
    sc->tri[1].v[1].vz = 0;
    sc->tri[1].v[2].vx = 0;
    sc->tri[1].v[2].vy = 0x38;
    sc->tri[1].v[2].vz = 0;
    sc->tri[2].v[0].vx = -9;
    sc->tri[2].v[0].vy = -0x38;
    sc->tri[2].v[0].vz = 0;
    sc->tri[2].v[1].vx = 9;
    sc->tri[2].v[1].vy = -0x38;
    sc->tri[2].v[1].vz = 0;
    sc->tri[2].v[2].vx = 0;
    sc->tri[2].v[2].vy = 0x54;
    sc->tri[2].v[2].vz = 0;
    sc->tri[3].v[0].vx = -0xE;
    sc->tri[3].v[0].vy = -0xE;
    sc->tri[3].v[0].vz = 0;
    sc->tri[3].v[1].vx = 0xE;
    sc->tri[3].v[1].vy = -0xE;
    sc->tri[3].v[1].vz = 0;
    sc->tri[3].v[2].vx = 0;
    sc->tri[3].v[2].vy = 0xE;
    sc->tri[3].v[2].vz = 0;
    g = (PolyG3_80140F78 *)g_Game_80140F78.f_4;
    ot = (u32 *)(g_Game_80140F78.f_80 + g_Game_80140F78.f_C * 0x4078);
    for (i = 15; i >= 0; i--) {
        p = &D_80141880_80140F78[i];
        if (p->life == 0) {
            continue;
        }
        p->life--;
        p->x += p->vx;
        p->y += p->vy;
        p->z += p->vz;
        p->vy += 4;
        if (p->y > p->floor) {
            p->y = p->floor;
            p->vy = -p->vy / 3;
            Effect_SpawnAt(4, (SVECTOR *)p);
            if ((RAND() >> 8 & 3) == 0) {
                Sound_PlayFixed(0x67);
            }
            if (p->vy >= -0xB) {
                p->life = 0;
                continue;
            }
        }
        sc->rot.vx = (p->life << 7) & 0xFFF;
        sc->rot.vy = (p->life << 7) & 0xFFF;
        sc->rot.vz = (p->life << 7) & 0xFFF;
        RotMatrixZYX(&sc->rot, &sc->m);
        sc->m.t[0] = p->x;
        sc->m.t[1] = p->y;
        sc->m.t[2] = p->z;
        CompMatrix(&sc->cam, &sc->m, &sc->m);
        SetRotMatrix(&sc->m);
        SetTransMatrix(&sc->m);
        gte_ldv3c_(&sc->tri[i & 3]);
        gte_rtpt_n();
        gte_stsxy3c_(sc->sxy);
        gte_stszotz(&sc->otz);
        if ((u32)(sc->otz - 1) >= 0xFFF) {
            continue;
        }
        ((u8 *)g)[3] = 6;
        g->rgb0 = 0x323C8028;
        g->rgb1 = 0x1E4014;
        g->rgb2 = 0xA1C00;
        g->xy0 = sc->sxy[0];
        g->xy1 = sc->sxy[1];
        g->xy2 = sc->sxy[2];
        ((Tag_80140F78 *)g)->addr = ((Tag_80140F78 *)&ot[sc->otz])->addr;
        ((Tag_80140F78 *)&ot[sc->otz])->addr = (u32)g;
        g++;
        ((u8 *)g)[3] = 1;
        ((u32 *)g)[1] = 0xE1000220;
        ((Tag_80140F78 *)g)->addr = ((Tag_80140F78 *)&ot[sc->otz])->addr;
        ((Tag_80140F78 *)&ot[sc->otz])->addr = (u32)g;
        g = (PolyG3_80140F78 *)((u8 *)g + 8);
    }
    g_Game_80140F78.f_4 = (u32 *)g;
    return 0;
}

void Effect_SpawnAt(s32, SVECTOR *);
void Fx_SpawnFadeRing(SVECTOR *, s32, s32, s32);
void Effect_SpawnAt(s32, SVECTOR *);
void *memset(void *, s32, s32);

void func_80141418(s16 x, s16 y, s16 z) {
    SVECTOR v;

    memset(&v, 0, 8);
    v.vx = x;
    v.vy = y - 0x60;
    v.vz = z;
    func_80140D88(&v, 0x10);
    Effect_SpawnAt(0x112, &v);
    Fx_SpawnFadeRing(&v, 5, 0x80, 0);
}

s32 SaveByte_Get(s32);

s32 func_8014149C(s16 *p)
{
  s32 v;
  p[1] = p[4];
  p[3] = 0;
  v = p[1];
  if ((v == 5) && (SaveByte_Get(3) != v))
  {
    p[1] = 2;
  }
  return 0;
}

typedef struct { s32 type; s32 x; s32 y; s32 z; s32 f_10; s32 f_14; s32 f_18; s32 f_1C; s32 f_20; s32 f_24; } Obj_801414F8;
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; u8 pad_812C[0x10C]; Obj_801414F8 *f_8238; u8 pad_823C[0x50]; s32 f_828C; } g_Game_801414F8 asm("g_Game");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; } g_Spike_801414F8 asm("g_Spike");
extern s16 D_800EC238;
extern u16 D_800E69BE_801414F8 asm("D_800E69BE");
void func_800863B0(s32, s32);
void Overlay_Request(s32);
s32 Overlay_GetState(void);
void func_8013FC74(void);
void Spike_SetPlayMode(s32);
void Game_SetMode(s32, s32, s32);

s32 func_801414F8(s16 *p) {
    s32 i;
    Obj_801414F8 *o;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            p[1] = 1;
            func_800863B0(2, 0x28);
            Overlay_Request(9);
        }
        break;
    case 1:
        if (Overlay_GetState() == 0) {
            func_800863B0(0, 0);
            p[1] = 3;
            func_8013FC74();
        }
        break;
    case 2:
        if (D_800EC238 == p[2]) {
            p[1] = 3;
            func_8013FC74();
        }
        break;
    case 3:
        if (D_800E69BE_801414F8 == 1) {
            p[1] = 5;
            Spike_SetPlayMode(0xB);
            Game_SetMode(0x1F, g_Game_801414F8.f_8126, g_Game_801414F8.f_812A);
        }
        break;
    case 4:
        if (Overlay_GetState() == 0) {
            p[1] = 5;
            func_800863B0(0, 0);
            Spike_SetPlayMode(0xB);
            o = g_Game_801414F8.f_8238;
            for (i = 0; i < g_Game_801414F8.f_828C; i++) {
                if (o[i].type == 3) {
                    o = &o[i];
                    o->type = 0;
                    o->x = g_Spike_801414F8.x;
                    o->y = g_Spike_801414F8.y;
                    o->z = g_Spike_801414F8.z;
                    o->f_10 = 0x800;
                    o->f_14 = 0x200;
                    o->f_18 = 0x200;
                    o->f_1C = 0x200;
                    o->f_20 = 0x56;
                    o->f_24 = 0;
                    break;
                }
            }
        }
        break;
    case 5:
        break;
    }
    return 0;
}

/* the original pads the read-only data after this jump table to 16 bytes (D_80141850 is 16-aligned) */
__asm__(".section .rodata\n\t.align 4\n\t.section .text");

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_801416D8 asm("g_Game");
extern s16 D_800EC238;

s32 func_801416D8(s16 *p) {
    u8 *e = g_Game_801416D8.f_820C + p[2] * 0x38;

    switch (p[1]) {
    case 0:
        if (D_800EC238 == p[2]) {
            if (p[3] == 0) {
                M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
                p[3] = 1;
                p[1] = 3;
                Sound_PlayAt(0x9C, (s32)e);
            }
        } else {
            p[3] = 0;
        }
        break;
    case 3:
        if (M2C_FIELD(e, s16 *, 0x32) == p[8] * 2 + 1 || M2C_FIELD(e, s16 *, 0x32) == p[9] * 2 + 1) {
            Sound_PlayAt(0x9C, (s32)e);
        }
        if (M2C_FIELD(e, s16 *, 0x32) >= p[7] * 2 + 1) {
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            p[1] = 0;
            Sound_PlayAt(0x9C, (s32)e);
            p[3] = D_800EC238 == p[2];
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/ovl/421/nonmatchings/421_monkey_madness_f6_obj", D_80141850);
