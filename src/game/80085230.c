#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define CLAMP96(v) ((v) < -0x60 ? -0x60 : ((v) > 0x60 ? 0x60 : (v)))
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_80085630;
typedef struct { s16 vx, vy, vz, pad; } SV_856FC_800856FC;
typedef struct { s16 x, y, z; } P3_856FC_800856FC;
typedef struct { u8 f_0; u8 pad1[0x1B]; s16 f_1C; s16 f_1E; s16 f_20; } Proj_856FC_800856FC;
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; u8 pad22[2]; s16 f_24; s16 f_26; } Coll_856FC_800856FC;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_856FC_800856FC;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; Db_856FC_800856FC db[2]; u8 pad[0x8126 - 0x10 - 2 * sizeof(Db_856FC_800856FC)]; u16 f_8126; } Game_856FC_800856FC;
typedef struct { u8 pad0[0x24]; s16 x; u8 pad26[6]; s16 z; } Spike_856FC_800856FC;

extern struct S_D_800F5090 { s32 f_0; s32 f_4; } g_GuidedLocks[];
extern s32 D_800B2960[3];
s32 func_80085254(void *, SVECTOR *, s32, s32);
void func_8004637C(MAT_80085630 *);
void RotMatrixY(s32, MAT_80085630 *);
void ApplyMatrixSV(MAT_80085630 *, SVECTOR *, SVECTOR *);

extern M2C_UNK D_800BF300;
extern Game_856FC_800856FC g_Game;
extern Spike_856FC_800856FC g_Spike;
extern u8 D_800B296C[];
extern struct S_D_800F4C30 { void *f_0; u8 pad4[0xC]; } D_800F4C30[];
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
extern u8 D_800E7D00[];
extern u16 g_RandSeed;
void RotMatrixZ(s32, struct S_D_800E78C0 *);
void Effect_SpawnAt(s32, P3_856FC_800856FC *);
void func_8014263C(P3_856FC_800856FC *, SV_856FC_800856FC *);
void func_8014022C(P3_856FC_800856FC *, SV_856FC_800856FC *);
s32 Projectile_Spawn(void *, SVECTOR *, s32);
s32 Floor_GetHeight();
void VectorNormalSS(SV_856FC_800856FC *, SV_856FC_800856FC *);
Coll_856FC_800856FC *CollShape_Alloc(void);
void Collision_Set(s32, void *, void *);
void Matrix_FromDirection(s16 *, struct S_D_800E78C0 *);
void CompMatrix(struct S_D_800E78C0 *, struct S_D_800E78C0 *, struct S_D_800E78C0 *);
void Model_ProjectVerts(struct S_D_800F4C30 *, struct S_D_800E78C0 *, u8 *);
void func_80017CD4(u32 *, u8 *, struct S_D_800F4C30 *);
struct S_D_800BF300_800856FC { Coll_856FC_800856FC *f_0; Proj_856FC_800856FC *f_4; P3_856FC_800856FC *f_8; P3_856FC_800856FC pos; u8 f_12; u8 f_13; P3_856FC_800856FC vel; u8 pad1A[2]; };

void func_80085230(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = &D_800BF300;
    do {
        M2C_FIELD(var_v0, s8 *, 0x12) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x1C));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/game/80085230", func_80085254);

INCLUDE_RODATA("asm/nonmatchings/game/80085230", jtbl_800A61E0);
INCLUDE_RODATA("asm/nonmatchings/game/80085230", jtbl_800A61E0_pad);


s32 Projectile_Spawn(void *a, SVECTOR *v, s32 mode) {
    MAT_80085630 m;
    SVECTOR out;
    s32 i;
    if (mode != 3) {
        return func_80085254(a, v, mode, 0);
    }
    for (i = 0; i < 3; i++) {
        func_8004637C(&m);
        RotMatrixY(D_800B2960[i], &m);
        ApplyMatrixSV(&m, v, &out);
        func_80085254(a, &out, 3, g_GuidedLocks[i].f_0);
    }
    return 0;
}

/* func_800856FC: update and draw the 4 boss/enemy shots at D_800BF300 (state f_12). For owners of
 * kind 1-2, state 5 explodes the shot (effect 0x10D, then a stage-specific spawn toward Spike in
 * stages 0x42/0x38) and state 2 turns it into a projectile (effects 0x102/0x113); other states move
 * it, ground it on the floor (effect 4) and keep its collision shape (type 0x11) up to date; the
 * model is drawn with a spin from the frame counter. */
void func_800856FC(void) {
    struct S_D_800E78C0 m;
    struct S_D_800E78C0 rot;
    SV_856FC_800856FC d;
    struct S_D_800BF300_800856FC *s;
    s32 i;
    s16 h;
    func_8004637C(&rot);
    RotMatrixZ((g_Game.frame & 0xF) << 8, &rot);
    s = ((struct S_D_800BF300_800856FC *)&D_800BF300);
    for (i = 3; i >= 0; i--, s++) {
        if (s->f_12 == 0) {
            continue;
        }
        if ((u8)(s->f_4->f_0 - 1) < 2) {
            switch (s->f_12) {
            case 5:
                s->f_12 = 0;
                Effect_SpawnAt(0x10D, &s->pos);
                d.vx = g_Spike.x - s->pos.x;
                d.vy = 0;
                d.vz = g_Spike.z - s->pos.z;
                if (g_Game.f_8126 == 0x42) {
                    func_8014263C(&s->pos, &d);
                } else if (g_Game.f_8126 == 0x38) {
                    func_8014022C(&s->pos, &d);
                }
                break;
            case 2:
                Effect_SpawnAt(0x102, &s->pos);
                s->vel.z = 0;
                s->vel.y = 0;
                s->vel.x = 0;
                Projectile_Spawn(&s->pos, &s->vel, 6);
                Effect_SpawnAt(0x113, &s->pos);
                s->f_12 = 0;
                break;
            case 1:
                if (s->f_4->f_0 == 2) {
                    s->f_12 = 0;
                    break;
                }
                s->f_12 = 7;
                s->f_13 = 0;
                s->vel.x = (-s->f_4->f_1C) / 8;
                s->vel.z = (-s->f_4->f_20) / 8;
                g_RandSeed = (g_RandSeed * 5) + 1;
                s->vel.y = -((g_RandSeed >> 8) & 0x3F);
                break;
            default:
                s->f_12 = 0;
                break;
            }
            continue;
        }
        switch (s->f_12) {
        case 7:
            s->pos.x += s->vel.x;
            s->pos.y += s->vel.y;
            s->pos.z += s->vel.z;
            s->f_13++;
            s->vel.y += 12;
            h = Floor_GetHeight(s->pos.x, s->pos.y, s->pos.z) - 0x20;
            if (s->pos.y >= h) {
                s->pos.y = h;
                s->vel.x = s->vel.x / 2;
                s->vel.z = s->vel.z / 2;
                s->vel.y = (-s->vel.y) / 3;
                if (s->vel.y >= (-0x13)) {
                    s->f_12 = 0;
                } else {
                    Effect_SpawnAt(4, &s->pos);
                }
            }
            if (s->f_13 >= 0x3C) {
                s->f_12 = 0;
            }
            break;
        case 5:
            Effect_SpawnAt(4, &s->pos);
            s->f_4->f_1E += 4;
            break;
        case 3:
            if (s->f_8 != 0) {
                s->f_4->f_1C = (s->f_4->f_1C * 925) >> 10;
                s->f_4->f_1E = (s->f_4->f_1E * 925) >> 10;
                s->f_4->f_20 = (s->f_4->f_20 * 925) >> 10;
                d.vx = s->f_8->x - s->pos.x;
                d.vy = s->f_8->y - ((s16) (s->pos.y + 0x40));
                d.vz = s->f_8->z - s->pos.z;
                VectorNormalSS(&d, &d);
                s->f_4->f_1C += d.vx >> 8;
                s->f_4->f_1E += d.vy >> 8;
                s->f_4->f_20 += d.vz >> 8;
                s->f_4->f_1C = (s->f_4->f_1C < (-0x60)) ? (-0x60) : ((s->f_4->f_1C > 0x60) ? (0x60) : (s->f_4->f_1C));
                s->f_4->f_1E = (s->f_4->f_1E < (-0x60)) ? (-0x60) : ((s->f_4->f_1E > 0x60) ? (0x60) : (s->f_4->f_1E));
                s->f_4->f_20 = (s->f_4->f_20 < (-0x60)) ? (-0x60) : ((s->f_4->f_20 > 0x60) ? (0x60) : (s->f_4->f_20));
            }
            break;
        case 6:
            if (!((++s->f_13) < 10)) {
                s->f_12 = 0;
            } else if ((s->f_0 = CollShape_Alloc()) != 0) {
                s->f_0->x = s->pos.x;
                s->f_0->y = s->pos.y;
                s->f_0->z = s->pos.z;
                s->f_0->f_20 = s->f_13 * 48;
                s->f_0->f_24 = 0xE36;
                s->f_0->f_26 = 0x203;
                Collision_Set(0x11, s->f_0, &g_Spike);
            }
            break;
        }
        if (s->f_12 != 6) {
            Matrix_FromDirection(&s->f_4->f_1C, &m);
            m.t[0] = s->pos.x;
            m.t[1] = s->pos.y;
            m.t[2] = s->pos.z;
            CompMatrix(&m, &rot, &m);
            CompMatrix(&D_800E78C0, &m, &m);
            Model_ProjectVerts(&D_800F4C30[D_800B296C[s->f_12]], &m, D_800E7D00);
            func_80017CD4(g_Game.db[g_Game.cur].ot, D_800E7D00, &D_800F4C30[D_800B296C[s->f_12]]);
        }
    }
}

s32 rsin(s32);
s32 rcos(s32);
typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_85E08;
typedef struct { P_TAG_85E08 tag; u32 rgbc; u32 xy0; u32 uv0clut; u32 xy1; u32 uv1tp; u32 xy2; u16 uv2, pad2; u32 xy3; u16 uv3, pad3; } PolyFT4_85E08;

/* Guided ammo lock-on reticle at screen (x, y): rotating textured quads shrinking towards the
   target, the innermost (k == n) brighter, linked at OT entry 1 */
void GuidedAmmo_DrawReticle(s16 x, s16 y, s32 n) {
    PolyFT4_85E08 *p = (PolyFT4_85E08 *)G_DRAW.prim;
    u32 *ot = G_DRAW.db[G_DRAW.cur].ot;
    s32 k = n;
    s32 a, r, c, s;

    if (n > 0) {
        k = n + 4;
    }
    for (; k >= n; k -= 2) {
        r = k * 3 + 20;
        a = (k << 15) / 360;
        c = (rcos(a) * r) >> 12;
        s = (rsin(a) * r) >> 12;
        p->tag.len = 9;
        if (k == n) {
            p->rgbc = 0x2E808080;
        } else {
            p->rgbc = 0x2E404040;
        }
        p->xy0 = ((y + s) << 16) | ((x + c) & 0xFFFF);
        p->xy1 = ((y - c) << 16) | ((x + s) & 0xFFFF);
        p->xy2 = ((y + c) << 16) | ((x - s) & 0xFFFF);
        p->xy3 = ((y - s) << 16) | ((x - c) & 0xFFFF);
        p->uv0clut = 0x7D6D00D8;
        p->uv1tp = (k == n) ? 0x1B00F6 : 0x7B00F6;
        p->uv2 = 0x1ED8;
        p->uv3 = 0x1EF6;
        p->tag.addr = ((P_TAG_85E08 *)&ot[1])->addr;
        ((P_TAG_85E08 *)&ot[1])->addr = (u32)p;
        p++;
    }
    G_DRAW.prim = (u8 *)p;
}
