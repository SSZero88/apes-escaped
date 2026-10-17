#include "common.h"
#include "m2c_macros.h"

extern struct S_D_800F51F0 { s32 f_0; } g_GuidedTargets[];


void func_8007CD60(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        g_GuidedTargets[i].f_0 = 0;
    }
}

s32 func_8007CD88(s32 a) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (g_GuidedTargets[i].f_0 == 0) {
            g_GuidedTargets[i].f_0 = a;
            return i;
        }
    }
    return -1;
}

void func_8007CDC4(s32 arg0) {
    s32 *var_v1;
    s32 var_a1;

    var_a1 = 0;
    var_v1 = &g_GuidedTargets[0].f_0;
    do {
        if (*var_v1 == arg0) {
            *var_v1 = 0;
        }
        var_a1 += 1;
        var_v1 = (void *)((u8 *)var_v1 + (4));
    } while (var_a1 < 0x20);
}

/* Returns the nearest of the 32 guided-ammo candidates that lies within `range`
 * of the aim point, or NULL.
 */
typedef struct { s32 vx, vy, vz; } VEC32_7CD60;
extern SVECTOR *g_GuidedTargetsP[] asm("g_GuidedTargets");
s32 VectorNormalSS(SVECTOR *, SVECTOR *);
s32 Vec_Length(s32, s32, s32);

/* Guided (homing) ammo: of the 32 locked-on candidates in g_GuidedTargets, returns the one whose
 * direction from pos (normalized) is within maxDist of dir and that is the nearest, or 0. The
 * goto loop and the do/while (0) are needed to match. */
SVECTOR *GuidedAmmo_FindTarget(VEC32_7CD60 *pos, SVECTOR *dir, s32 maxDist) {
    SVECTOR d;
    SVECTOR **t;
    s32 i;
    s32 len;
    s32 best;
    s32 bi;

    i = 0;
    best = 0x40000000;
    bi = -1;
    t = g_GuidedTargetsP;
loop:
    if (t[i] != 0) {
        d.vx = t[i]->vx - pos->vx;
        d.vy = t[i]->vy - pos->vy;
        d.vz = t[i]->vz - pos->vz;
        len = VectorNormalSS(&d, &d);
        if (Vec_Length(d.vx - dir->vx, (d.vy - dir->vy) >> 1, d.vz - dir->vz) < maxDist && len < best) {
            do {
                best = len;
            } while (0);
            bi = i;
        }
    }
    i++;
    if (i < 32) {
        goto loop;
    }
    if (bi != -1) {
        return g_GuidedTargetsP[bi];
    }
    return 0;
}

extern u8 g_Game[];
extern u8 D_800E78C0[];
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_7CF7C;
typedef struct { P_TAG_7CF7C tag; u8 r0, g0, b0, code; s16 x0, y0, x1, y1, x2, y2; } PolyF3_7CF7C;

/* Marks each of the 32 guided-ammo candidates on screen with a small red triangle (POLY_F3,
   projected with the camera matrix D_800E78C0), linked at OT entry 1 */
void GuidedAmmo_DrawCandidates(void) {
    PolyF3_7CF7C *p = (PolyF3_7CF7C *)G_DRAW.prim;
    s32 i;
    s32 buf[2];
    s32 x, y;

    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    for (i = 0; i < 32; i++) {
        if (g_GuidedTargetsP[i] != NULL) {
            RotTransPers(g_GuidedTargetsP[i], &buf[0], &buf[1], &buf[1]);
            p->tag.len = 4;
            p->code = 0x20;
            p->r0 = 0xFF;
            p->g0 = 0;
            p->b0 = 0;
            x = ((s16 *)buf)[0];
            y = ((s16 *)buf)[1];
            p->x0 = x;
            p->y0 = y;
            p->x1 = x - 8;
            p->y1 = y - 8;
            p->x2 = x + 8;
            p->y2 = y - 8;
            p->tag.addr = ((P_TAG_7CF7C *)&G_DRAW.db[G_DRAW.cur].ot[1])->addr;
            ((P_TAG_7CF7C *)&G_DRAW.db[G_DRAW.cur].ot[1])->addr = (u32)p;
            p++;
        }
    }
    G_DRAW.prim = (u8 *)p;
}
