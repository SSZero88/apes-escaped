#include "common.h"
#include "m2c_macros.h"

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 4;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x4E3;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_8013D020 asm("g_Game");
s32 Sound_PlayAt(s32, s32);
s32 func_8013D1C4(s16 *p);

s32 func_8013D020(s16 *p) {
    u8 *e = g_Game_8013D020.f_820C + p[2] * 0x38;
    s16 t;

    switch (p[1]) {
    case 5:
        if (p[8] > 0x200 && p[3] == 0) {
            Sound_PlayAt(0x77, (s32)e);
        }
        p[3] += p[4];
        if (p[8] < p[3]) {
            p[3] = p[8];
            if (p[8] < 0x200) {
                p[1] = 2;
            } else {
                p[10] = 0;
                p[1] = 6;
            }
        }
        func_8013D1C4(p);
        break;
    case 2:
        p[3] -= p[7];
        if (p[3] < 0) {
            p[3] = 0;
            t = p[8];
            if (t < 0x200) {
                p[1] = 4;
                p[8] = 0x4E3;
            } else {
                p[1] = 5;
                p[8] = t / 3;
            }
        }
        func_8013D1C4(p);
        break;
    case 6:
        if (p[9] < ++p[10]) {
            p[1] = 2;
        }
        func_8013D1C4(p);
        break;
    case 1:
    case 3:
    case 4:
        break;
    }
    return 0;
}

typedef struct { u32 *mdl; u8 pad4[0xC]; s16 x, y, z; u8 pad16[6]; void *mat; } Mesh_8013D1C4;
typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR dir; s16 f20; u8 pad22[2]; s16 f24; s16 f26; } Shape_8013D1C4;
extern Mesh_8013D1C4 *D_800B4D64_8013D1C4 asm("g_StageMeshes");
void RotMatrixZYX(SVECTOR *, void *);
void *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 func_8013D1C4(s16 *p) {
    SVECTOR v;
    s32 t;
    Shape_8013D1C4 *c;
    s32 a;

    t = *D_800B4D64_8013D1C4[p[5]].mdl & 0xF;
    if (t != 3) {
        return 0;
    }
    v.vz = 0;
    v.vx = 0;
    v.vy = p[3];
    RotMatrixZYX(&v, D_800B4D64_8013D1C4[p[5]].mat);
    if ((*D_800B4D64_8013D1C4[p[6]].mdl & 0xF) != t) {
        return 0;
    }
    v.vz = 0;
    v.vx = 0;
    v.vy = p[3] * -1;
    RotMatrixZYX(&v, D_800B4D64_8013D1C4[p[6]].mat);
    if (p[1] != 6) {
        v.vy = 0;
        v.vx = 0;
        v.vz = -0x1000;
        c = CollShape_Alloc();
        if (c == NULL) {
            return 0;
        }
        c->dir = v;
        a = D_800B4D64_8013D1C4[p[5]].x;
        c->x = a + (D_800B4D64_8013D1C4[p[6]].x - a) / 2;
        c->y = D_800B4D64_8013D1C4[p[5]].y;
        c->z = D_800B4D64_8013D1C4[p[5]].z;
        c->f20 = 0x100;
        c->f24 = 1;
        c->f26 = 0x203;
        Collision_Set(6, c, 0);
    }
    return 0;
}

/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop");
