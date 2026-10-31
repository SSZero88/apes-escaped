#include "common.h"
#include "m2c_macros.h"

void Object_PlaySound(void *, s32);

M2C_UNK Collision_Remove(M2C_UNK *);
M2C_UNK func_80052038(void *, M2C_UNK);
M2C_UNK func_8007CDC4(M2C_UNK *);
extern M2C_UNK D_80140B80;
extern M2C_UNK D_80140BB8;
extern s32 D_80140BC0;
M2C_UNK Object_StepOnGroundFixed(s32);
M2C_UNK func_800585D0(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK Spike_WithinRadiusXZ(s16, s16, s16);
M2C_UNK func_80056128(s32, M2C_UNK);
M2C_UNK func_800525E0();
M2C_UNK func_80052864(void *);
M2C_UNK Object_SeekHeight(void *, M2C_UNK);
s32 func_80055718(void *, s16, s16, s16, s32);
M2C_UNK func_8005588C(void *, M2C_UNK);
M2C_UNK func_800563E0(void *, M2C_UNK);
s32 rcos(s16);
s32 rsin(s16);
extern M2C_UNK D_80141B38;

typedef struct { s16 m[3][3]; s32 t[3]; } Mat_8013D000;
typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; } Scr_8013D000;
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013D000 asm("g_Spike");
void func_80047464(void *, s32, s32, s32);
void func_80047558(void *, s32, s32, s32);
void func_8004B8F4(void *, s32, void *);
void VectorNormalSS(void *, void *);
void func_8004637C(void *);
void *RotMatrixY(s32 r, void *m);
void *ApplyMatrixSV(void *m, void *v0, void *v1);

void func_8013D000(void *arg0) {
    SVECTOR v;
    SVECTOR d;
    Mat_8013D000 m;

    ((Scr_8013D000 *)0x1F800000)->spike.vx = g_Spike_8013D000.x;
    ((Scr_8013D000 *)0x1F800000)->spike.vy = g_Spike_8013D000.y;
    ((Scr_8013D000 *)0x1F800000)->spike.vz = g_Spike_8013D000.z;
    func_8004B8F4(arg0, 2, &v);
    ((Scr_8013D000 *)0x1F800000)->eye.vx = ((Scr_8013D000 *)0x1F800000)->spike.vx;
    ((Scr_8013D000 *)0x1F800000)->eye.vy = ((Scr_8013D000 *)0x1F800000)->spike.vy - 0x190;
    ((Scr_8013D000 *)0x1F800000)->eye.vz = ((Scr_8013D000 *)0x1F800000)->spike.vz;
    func_80047558(arg0, 0x10, 8, 0x10);
    d.vx = v.vx - ((Scr_8013D000 *)0x1F800000)->spike.vx;
    d.vy = 0;
    d.vz = v.vz - ((Scr_8013D000 *)0x1F800000)->spike.vz;
    VectorNormalSS(&d, &d);
    func_8004637C(&m);
    RotMatrixY(0x111, &m);
    ApplyMatrixSV(&m, &d, &d);
    ((Scr_8013D000 *)0x1F800000)->at.vx = v.vx - ((d.vx * 925) >> 11);
    ((Scr_8013D000 *)0x1F800000)->at.vz = v.vz - ((d.vz * 925) >> 11);
    ((Scr_8013D000 *)0x1F800000)->at.vy = ((Scr_8013D000 *)0x1F800000)->spike.vy - 0x400;
    func_80047464(arg0, 0x10, 0x10, 0x10);
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u8 pad5E[2]; s16 r0, r1, r2, r3; u8 pad68[8]; s16 vx, vy, vz; s16 wx, wy, wz; s16 rx, ry, rz; u8 f82; u8 life; } Piece_8013D16C;
extern Piece_8013D16C D_80140BC8[];
extern struct { s32 x; s32 y; s32 z; } D_80140B80_8013D16C asm("D_80140B80");
extern u16 g_RandSeed;
extern u16 D_800AE8F2;
void func_800520A8(void *, s32);
void Hook_Add(void *);
void func_8013D488();

void func_8013D16C(void *a) {
    s32 i;
    s32 k;
    Piece_8013D16C *p;

    for (i = 0; i < 16; i++) {
        p = &D_80140BC8[i];
        k = (i & 1) + 0xA1;
        func_80052038(p, k);
        func_800520A8(p, k);
        p->r2 = 0x1000;
        p->frame = 0;
        p->r1 = 0;
        p->r0 = 0;
        p->r3 = 3;
        p->x = D_80140B80_8013D16C.x + ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) - 0x80;
        p->y = D_80140B80_8013D16C.y - ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8);
        p->z = D_80140B80_8013D16C.z + ((D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) - 0x80;
        p->vx = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        p->vz = (s32)(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) - 0x80) / 4;
        p->vy = -(s32)((g_RandSeed = g_RandSeed * 5 + 1) >> 8) / 4 - 0x40;
        p->wx = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        p->wy = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        p->wz = (s32)((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) % 20) << 12) / 360;
        p->rz = 0;
        p->ry = 0;
        p->rx = 0;
        p->life = 60;
        p->f82 = M2C_FIELD(a, u8 *, 0xCB);
    }
    Hook_Add(func_8013D488);
}

typedef struct { u8 pad0[0x14]; s32 mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x40]; s16 vx, vy, vz; s16 rvx, rvy, rvz; s16 rx, ry, rz; u8 owner; u8 timer; } Deb_8013D488;
typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x70]; s16 floor; u8 pad9E[0x46]; } Obj_8013D488;
void Model_ProjectBonedVerts(void *);
void RotMatrixYXZ_8013D488(void *, void *) asm("RotMatrixYXZ");
void func_80015780(void *, s32);
void func_80016EBC(void *, void *, void *);
s32 func_80051410(void *, s32, s32);
extern M2C_UNK D_800E7D00;
extern struct { u8 pad0[0xC]; s32 f_C; u8 pad10[0x70]; u8 f_80[1]; } g_Game_8013D488 asm("g_Game");
extern Deb_8013D488 D_80140BC8_8013D488[] asm("D_80140BC8");
extern Obj_8013D488 g_Objects_8013D488[] asm("g_Objects");

void func_8013D488(void) {
    s32 i;
    Deb_8013D488 *m;
    Obj_8013D488 *t;
    SVECTOR sv;

    for (i = 0; i < 16; i++) {
        m = &D_80140BC8_8013D488[i];
        if (m->timer != 0) {
            m->timer--;
            m->x += m->vx;
            m->y += m->vy;
            m->z += m->vz;
            *(volatile s16 *)&m->vy += 7;
            t = &g_Objects_8013D488[m->owner];
            if (t->floor < m->y) {
                { s32 y = t->y; m->vy = -(m->vy / 2); m->y = y; }
                sv.vx = m->x;
                sv.vy = m->y;
                sv.vz = m->z;
            }
            m->rx = (m->rx + m->rvx) % 4096;
            m->ry = (m->ry + m->rvy) % 4096;
            m->rz = (m->rz + m->rvz) % 4096;
            if (func_80051410(&m->x, 0, 0) == 0) {
                RotMatrixYXZ_8013D488(&m->rx, (void *)m->mat);
                func_80015780(m, 3);
                Model_ProjectBonedVerts(m);
                func_80016EBC(g_Game_8013D488.f_80 + g_Game_8013D488.f_C * 0x4078, &D_800E7D00, m);
            }
        }
    }
}

extern u8 D_801409C0[];
extern u8 D_80140A68[];
void func_800702B0(void *, void *);
void Object_CameraShake(void *, s32);

void func_8013D6A4(u8 *o) {
    SVECTOR v;

    v.vx = M2C_FIELD(o, u16 *, 0x24) + (M2C_FIELD(o, s16 *, 0x60) * 25 >> 8);
    v.vy = M2C_FIELD(o, u16 *, 0x28) - 0x40;
    v.vz = M2C_FIELD(o, u16 *, 0x2C) + (M2C_FIELD(o, s16 *, 0x64) * 25 >> 8);
    func_80070284(&v, D_801409C0, 1, 0, 0);
    func_80070284(&v, D_801409C0 + 0x54, 1, 0, 0);
    func_800702B0(&v, D_80140A68);
    Object_CameraShake(o, 2);
    Object_PlaySound(o, 0x79);
}

extern struct { u8 pad0[0x24]; s32 x, y, z; } g_Spike_8013D780 asm("g_Spike");
s32 Math_WithinSquare(s32, s32, s32);
void Object_CameraShake(void *, s32);

/* called without all its arguments (old-style declaration), so defined old-style */
void func_8013D780(arg0)
    void *arg0;
{
    s32 f = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4);

    if (Math_WithinSquare(M2C_FIELD(arg0, s32 *, 0x24) - g_Spike_8013D780.x,
                          M2C_FIELD(arg0, s32 *, 0x2C) - g_Spike_8013D780.z, 0xFA0)) {
        if (f == 0xF || f == 0x31) {
            Object_CameraShake(arg0, 1);
            Object_PlaySound(arg0, 0xAC);
        }
    }
}

void func_8013D81C(void *arg0) {
    Collision_Remove(&D_80140B80);
    func_8007CDC4(&D_80140BB8);
    func_80052038(arg0, 0x80);
    M2C_FIELD(arg0, s16 *, 0x5E) = 1;
    D_80140BC0 = 0;
}

extern u8 D_80140B80_8013D870[] asm("D_80140B80");
s32 Collision_GetShape(s32);
s32 func_800525A0(void *, s32);

void func_8013D870(u8 *a) {
    u8 *c;

    if (a[0x81] != 0) {
        c = D_80140B80_8013D870;
        if ((M2C_FIELD(c, u32 *, 0x2C) >> 28) == 0xB) {
            if (func_800525A0(a, Collision_GetShape(M2C_FIELD(c, u16 *, 0x2C) & 0xFFF))) {
                func_8013D16C(a);
                Object_PlaySound(a, 0x4D);
                func_8013D81C(a);
            } else {
                a[0x80] = 4;
                func_8005588C(a, 0x1E);
                Object_PlaySound(a, 0x6A);
            }
        }
    }
}

extern struct { s32 x; s32 y; s32 z; u8 pad_C[0x14]; s16 w; s16 h; } D_80140B80_8013D918 asm("D_80140B80");
extern struct { s16 x; s16 y; s16 z; } D_80140BB8_8013D918 asm("D_80140BB8");
extern u8 D_800E77E5;
void Debug_DrawWorldQuad(void *, s32, s32);

void func_8013D918(u8 *a) {
    u32 fl;
    s16 *p;
    s16 *q;

    fl = M2C_FIELD(a, u32 *, 0xE0);
    p = M2C_FIELD(a, s16 **, 0x74);
    q = M2C_FIELD(a, s16 **, 0x78);
    if ((fl >> 2) & 1) {
        M2C_FIELD(a, u32 *, 0xE0) = fl & ~0x2000;
        p[0] = M2C_FIELD(a, u16 *, 0x24);
        p[2] = M2C_FIELD(a, u16 *, 0x2C);
        q[0] = M2C_FIELD(a, u16 *, 0x24);
        q[2] = M2C_FIELD(a, u16 *, 0x2C);
    } else {
        M2C_FIELD(a, u32 *, 0xE0) = fl | 0x2000;
    }
    D_80140B80_8013D918.x = D_80140BB8_8013D918.x = (p[0] + q[0]) / 2;
    D_80140B80_8013D918.y = D_80140BB8_8013D918.y = (p[1] + q[1]) / 2;
    D_80140B80_8013D918.z = D_80140BB8_8013D918.z = (p[2] + q[2]) / 2;
    D_80140B80_8013D918.w = 150;
    D_80140B80_8013D918.h = 300;
    if (D_800E77E5 >= 2) {
        Debug_DrawWorldQuad(&D_80140B80_8013D918, 150, 300);
    }
}

extern struct { s32 x; s32 y; s32 z; u8 pad_C[0x14]; s16 w; s16 h; s16 f24; s16 f26; } D_80140B80_8013DA40 asm("D_80140B80");
extern struct { s16 x; s16 y; s16 z; } D_80140BB8_8013DA40 asm("D_80140BB8");
void Object_PlaceAtPathPoint(void *, s32);
void func_8005866C(void *, s32);
void *func_80057140(void *, s16, s16);
s32 Collision_Set(s32, void *, void *);
s32 func_8007CD88_8013DA40(void *) asm("func_8007CD88");
void *func_80056BC4(s16, s32, s16);

void func_8013DA40(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xA0) = 600;
    M2C_FIELD(arg0, s16 *, 0x44) = 500;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x44C;
    M2C_FIELD(arg0, s16 *, 0xB0) = 11;
    M2C_FIELD(arg0, u8 *, 0x81) = 10;
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) & ~0x1000) | 0x200;
    Object_PlaceAtPathPoint(arg0, 0);
    func_8005866C(arg0, 1);
    M2C_FIELD(arg0, u8 *, 0x80) = 1;
    M2C_FIELD(arg0, u8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x2000;
    M2C_FIELD(arg0, void **, 0x74) = func_80057140(arg0, 3, 0x2A);
    M2C_FIELD(arg0, void **, 0x78) = func_80057140(arg0, 3, 0x2D);
    M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFF3FFFFF) | 0x400000;
    M2C_FIELD(arg0, u16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28);
    D_80140B80_8013DA40.w = 150;
    D_80140B80_8013DA40.h = 300;
    D_80140B80_8013DA40.f24 = 0;
    D_80140B80_8013DA40.f26 = -0x7EFD;
    D_80140B80_8013DA40.x = D_80140BB8_8013DA40.x = M2C_FIELD(arg0, u16 *, 0x24);
    D_80140B80_8013DA40.y = D_80140BB8_8013DA40.y = M2C_FIELD(arg0, u16 *, 0x28) - 0x4B0;
    D_80140B80_8013DA40.z = D_80140BB8_8013DA40.z = M2C_FIELD(arg0, u16 *, 0x2C);
    Collision_Set(4, &D_80140B80_8013DA40, arg0);
    func_8007CD88_8013DA40(&D_80140BB8_8013DA40);
    func_80056BC4(0x1B, 0, M2C_FIELD(arg0, s8 *, 0xCB));
    D_80140BC0 = 1;
}

void func_8013DBC4(void *arg0) {
    s32 d = M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0xBE);

    if ((u8)(M2C_FIELD(arg0, u8 *, 0x8E) - 5) < 2) {
        d = 0;
    }
    if (d == 0) {
        if (M2C_FIELD(arg0, s16 *, 0xD4) > 0) {
            M2C_FIELD(arg0, s16 *, 0xD4) -= 10;
        } else if (M2C_FIELD(arg0, s16 *, 0xD4) < 0) {
            M2C_FIELD(arg0, s16 *, 0xD4) += 10;
        }
    } else if (__builtin_abs(M2C_FIELD(arg0, s16 *, 0xD4)) <= 0x70) {
        if (d > 0) {
            M2C_FIELD(arg0, s16 *, 0xD4) += 10;
        } else {
            M2C_FIELD(arg0, s16 *, 0xD4) -= 10;
        }
    }
    M2C_FIELD(arg0, s16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28);
}

void func_8013DC58(s32 arg0) {
    func_8013D780();
    func_800585D0(arg0, 0xA, 0, 0);
    Object_StepOnGroundFixed(arg0);
    func_8013DBC4(arg0);
}

void func_80058134_8013DCA0(void *, s32) asm("func_80058134");
void func_8013D6A4(u8 *o);
void func_8013D81C(void *arg0);
void func_8013D870(u8 *a);
void func_8013D918(u8 *a);
void func_8013DA40(void *arg0);
void func_8013DC58(s32 arg0);

void func_8013DCA0(u8 *o) {
    u16 s;

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        func_8013DA40(o);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013DCA0(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0xCF) == 4) {
        func_8013D81C(o);
        M2C_FIELD(o, u8 *, 0xCF) = 0;
        return;
    }
    if (D_80140BC0 == 0) {
        M2C_FIELD(o, s16 *, 0x5E) = 1;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_8013D870(o);
        func_8013DC58((s32)o);
        if ((M2C_FIELD(o, u32 *, 0x50) >> 28) == 11) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x7F) == 0) {
            M2C_FIELD(o, u16 *, 0x5C)++;
            func_8013DC58((s32)o);
        } else {
            s = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            if (M2C_FIELD(o, u16 *, 0x5C) == s + 0x20) {
                Object_PlaySound(o, 0xAE);
            } else if (M2C_FIELD(o, u16 *, 0x5C) == s + 0x41) {
                func_8013D6A4(o);
            }
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88) + 2)) {
            if (M2C_FIELD(o, u8 *, 0x7F) == 0) {
                M2C_FIELD(o, u8 *, 0x7F) = 2;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, u8 *, 0x7F) = 0;
                M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            }
        }
        break;
    case 4:
        if (M2C_FIELD(o, u8 *, 0xC9) & 1) {
            func_80052038(o, 7);
        } else {
            func_80052038(o, 0x81);
        }
        func_8013DC58((s32)o);
        if (func_8005588C(o, -1) == 0) {
            func_80052038(o, 7);
            M2C_FIELD(o, u8 *, 0x80) = 1;
        }
        break;
    }
    func_8013D918(o);
}

void func_8013DED0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(&D_80140B80, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(&D_80140B80, s32 *, 4) - 0x32);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(&D_80140B80, s32 *, 8);
}

void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);

void func_8013DEFC(void *arg0, s32 on) {
    u16 *p = M2C_FIELD(arg0, u16 **, 0x74);
    SVECTOR v;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x2000;
        p[0] = M2C_FIELD(arg0, u16 *, 0x24);
        p[2] = M2C_FIELD(arg0, u16 *, 0x2C);
    } else {
        M2C_FIELD(arg0, u32 *, 0xE0) |= 0x2000;
    }
    v.vx = p[0];
    v.vy = p[1] + 0xDC;
    v.vz = p[2];
    Monkey_DrawHelmetLight(&v, 2, on != 0);
}

extern struct { u32 f_0; } g_Game_8013DF80 asm("g_Game");
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013DF80 asm("g_Spike");
s32 rcos_8013DF80(s32) asm("rcos");
s32 rsin_8013DF80(s32) asm("rsin");
void func_80059304(SVECTOR *, void *, s32, SVECTOR *);

void func_8013DF80(u8 *o) {
    SVECTOR w;
    SVECTOR v;
    u8 r = M2C_FIELD(o, u8 *, 0xC9) % 5;

    if (r == 0) {
        v.vx = g_Spike_8013DF80.x + rcos_8013DF80((g_Game_8013DF80.f_0 << 12) / 100) * 400 / 4096 - M2C_FIELD(o, u16 *, 0x24);
        v.vz = g_Spike_8013DF80.z + rsin_8013DF80((g_Game_8013DF80.f_0 << 12) / 100) * 400 / 4096 - M2C_FIELD(o, u16 *, 0x2C);
        v.vy = g_Spike_8013DF80.y - (M2C_FIELD(o, u16 *, 0x28) + 0x7D);
        VectorNormalSS(&v, &v);
        v.vx /= 32;
        v.vy /= 32;
        v.vz /= 32;
        w.vx = M2C_FIELD(o, u16 *, 0x24) + v.vx * 3;
        w.vy = M2C_FIELD(o, u16 *, 0x28) + v.vy * 2 - 0x64;
        w.vz = M2C_FIELD(o, u16 *, 0x2C) + v.vz * 3;
        Object_PlaySound(o, 0x58);
        func_80059304(&w, o, 1, &v);
    } else if (r == 2) {
        Object_PlaySound(o, 0x58);
    }
}

typedef struct { u8 pad[0xE4]; } Obj_8013E174;
extern Obj_8013E174 g_Objects_8013E174[] asm("g_Objects");
void func_80051E98(void *, s32);
void Object_TurnTowardSpike_8013E174(void *) asm("Object_TurnTowardSpike");
void Object_TurnToward_8013E174(void *, s16, s16, s32, s32) asm("Object_TurnToward");
void func_8013DED0(void *arg0);
void func_8013DEFC(void *arg0, s32 on);
void func_8013DF80(u8 *o);

void func_8013E174(u8 *o) {
    u8 *t = (u8 *)&g_Objects_8013E174[M2C_FIELD(o, s8 *, 0xCA)];

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, s16 *, 0xB0) = 0x1000;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x2000;
        M2C_FIELD(o, void **, 0x74) = func_80057140(o, 6, 0x47);
        M2C_FIELD(o, u8 *, 0x80) = 1;
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    if (M2C_FIELD(t, u16 *, 0x5E) == 1) {
        func_80051E98(o, 0);
        return;
    }
    func_8013DED0(o);
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        Object_TurnToward_8013E174(o, M2C_FIELD(t, s16 *, 0x60), M2C_FIELD(t, s16 *, 0x64), 0, M2C_FIELD(o, s16 *, 0xB0));
        func_8013DEFC(o, 0);
        if (M2C_FIELD(t, u8 *, 0x80) == 4) {
            M2C_FIELD(o, u8 *, 0x80) = 2;
            M2C_FIELD(o, u8 *, 0x7F) = 1;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            Object_TurnTowardSpike_8013E174(o);
            Object_PlaySound(o, 0x54);
        }
        break;
    case 2:
        func_8013DEFC(o, 1);
        if (M2C_FIELD(t, u8 *, 0x80) != 4) {
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x7F) = 2;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
            func_8005588C(o, 0x1E);
        }
        break;
    case 3:
        Object_TurnTowardSpike_8013E174(o);
        func_8013DF80(o);
        func_8013DEFC(o, 1);
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0x80) = 1;
            M2C_FIELD(o, u8 *, 0x7F) = 0;
            M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        }
        break;
    }
}

void Object_SetAnim(void *, s32, s32);
void func_80058134_8013E38C(void *, s32) asm("func_80058134");
void func_8005866C_8013E38C(void *, s32) asm("func_8005866C");

void func_8013E38C(void *arg0) {
    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(arg0, s16 *, 0x44) = 0x118;
        M2C_FIELD(arg0, s16 *, 0x4A) = -0x4000;
        M2C_FIELD(arg0, s16 *, 0xA0) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(arg0, u32 *, 0xE0) = (M2C_FIELD(arg0, u32 *, 0xE0) & ~0x03000000) | 0x01000000;
        M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        if (M2C_FIELD(arg0, u16 *, 0x8C) != 0) {
            func_8005866C_8013E38C(arg0, 1);
        }
        M2C_FIELD(arg0, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013E38C(arg0, M2C_FIELD(arg0, s16 *, 0x44));
    if (M2C_FIELD(arg0, u8 *, 0xCF) == 1) {
        Object_SetAnim(arg0, 2, 1);
        M2C_FIELD(arg0, u8 *, 0xC9) = 50;
    }
    if (M2C_FIELD(arg0, u8 *, 0xC9) != 0) {
        if (--M2C_FIELD(arg0, u8 *, 0xC9) == 0) {
            Object_SetAnim(arg0, 2, 3);
        }
    }
    M2C_FIELD(arg0, u8 *, 0xCF) = 0;
    if (M2C_FIELD(arg0, u8 *, 0x80) == 2 && M2C_FIELD(arg0, u16 *, 0x5C) >= M2C_FIELD(arg0, u16 **, 0x88)[M2C_FIELD(arg0, u8 *, 0x7F) * 2 + 1]) {
        M2C_FIELD(arg0, u8 *, 0x80) = 1;
        if (M2C_FIELD(arg0, u8 *, 0x7F) == 3) {
            M2C_FIELD(arg0, u8 *, 0x7F) = 0;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[0];
        } else {
            M2C_FIELD(arg0, u8 *, 0x7F) = 2;
            M2C_FIELD(arg0, u16 *, 0x5C) = M2C_FIELD(arg0, u16 **, 0x88)[4];
        }
    }
}

extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013E4FC asm("g_Spike");
s32 Vec_Length(s32, s32, s32);
void Object_PlaySound_8013E4FC(void *, s32) asm("Object_PlaySound");

void func_8013E4FC(void *arg0) {
    u8 *o = arg0;
    s32 v;

    M2C_FIELD(o, s16 *, 0x96) = -(M2C_FIELD(o, s16 *, 0xA8) + 7) * 11;
    if (M2C_FIELD(o, s16 *, 0xA8) != 0) {
        v = Vec_Length(g_Spike_8013E4FC.x - M2C_FIELD(o, s32 *, 0x24), 0, g_Spike_8013E4FC.z - M2C_FIELD(o, s32 *, 0x2C)) / 22;
    } else {
        v = 17;
    }
    M2C_FIELD(o, s16 *, 0xAE) = 0;
    M2C_FIELD(o, u8 *, 0xDD) = 0;
    M2C_FIELD(o, u32 *, 0xE0) |= 0x400;
    M2C_FIELD(o, u32 *, 0xE0) &= ~0x20;
    M2C_FIELD(o, s16 *, 0x94) = (M2C_FIELD(o, s16 *, 0x60) * v) >> 12;
    M2C_FIELD(o, s16 *, 0x98) = (M2C_FIELD(o, s16 *, 0x64) * v) >> 12;
    Object_PlaySound_8013E4FC(o, 0x68);
}

s32 Object_AddAttackSphereNear(void *, s16, s16, s16, s32, s32, s32);

void func_8013E5E8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0xAA, M2C_FIELD(arg0, s16 *, 0x24),
                                                               M2C_FIELD(arg0, u16 *, 0x1E) - 0x78,
                                                               M2C_FIELD(arg0, s16 *, 0x2C), 1, 0x202);
}

s16 Object_FloorAt(void *, s16, s16, s16);
void func_80070284(SVECTOR *, void *, s32, s32, s32);
extern u8 D_80140A74[];

void func_8013E640(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x7F) == 3 &&
        M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 0x1F) {
        v.vx = M2C_FIELD(arg0, u16 *, 0x24);
        v.vy = Object_FloorAt(arg0, 0, 0, 0);
        v.vz = M2C_FIELD(arg0, u16 *, 0x2C);
        func_80070284(&v, D_80140A74, 1, 0, 0);
        Object_PlaySound(arg0, 0x4B);
    }
}

/* called without arguments (old-style declaration), so defined old-style */
s32 func_8013E6DC(arg0)
    void *arg0;
{
    s32 d = M2C_FIELD(arg0, u16 *, 0x5C) - *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88));

    return d < 9 || d > 0x1F;
}

s32 func_8013E70C(void *arg0) {
    return Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6));
}

s32 func_8013E73C(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x121;
}

void func_8013E778(void *arg0) {
    if ((func_8013E70C(arg0) == 0) && (func_8013E73C(arg0) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s16 *, 0x9A);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s16 *, 0x9E);
    }
}

s32 func_8013E70C(void *arg0);
s32 func_8013E73C(void *arg0);
void func_8013E778(void *arg0);
void func_8013E5E8(void *arg0);
void Object_TurnTowardSpike_8013E7CC(void *) asm("Object_TurnTowardSpike");
void Object_TurnToward_8013E7CC(void *, s16, s16, s32, s32) asm("Object_TurnToward");
s32 func_800572CC_8013E7CC(void *) asm("func_800572CC");
s32 Object_DetachLink_8013E7CC(void *, s32) asm("Object_DetachLink");

void func_8013E7CC(void *arg0) {
    if (func_8013E6DC(arg0)) {
        if (func_8013E70C(arg0)) {
            Object_TurnTowardSpike_8013E7CC(arg0);
            M2C_FIELD(arg0, s16 *, 0xA8) = 1;
        } else {
            Object_TurnToward_8013E7CC(arg0, M2C_FIELD(arg0, u16 *, 0x9A) - M2C_FIELD(arg0, u16 *, 0x24),
                                       M2C_FIELD(arg0, u16 *, 0x9E) - M2C_FIELD(arg0, u16 *, 0x2C), 0,
                                       M2C_FIELD(arg0, s16 *, 0xB0));
            M2C_FIELD(arg0, s16 *, 0xA8) = 0;
            if (func_8013E73C(arg0)) {
                M2C_FIELD(arg0, u8 *, 0x80) = 5;
                M2C_FIELD(arg0, u8 *, 0x7F) = 4;
                M2C_FIELD(arg0, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + 0x10);
            }
        }
        if (M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 *, 0x7F) * 4 + M2C_FIELD(arg0, u8 **, 0x88)) + 8) {
            func_8013E4FC(arg0);
        }
    } else {
        M2C_FIELD(arg0, u16 *, 0x96) += M2C_FIELD(arg0, u16 *, 0xA8);
        func_8013E778(arg0);
        if (M2C_FIELD(arg0, u8 *, 0xDD) == 0 && func_800572CC_8013E7CC(arg0)) {
            M2C_FIELD(arg0, u8 *, 0xDD) = 1;
        }
    }
    if (Object_DetachLink_8013E7CC(arg0, 0) == 6) {
        M2C_FIELD(arg0, u8 *, 0x80) = 4;
        func_8005588C(arg0, 0x1E);
    } else {
        func_8013E5E8(arg0);
    }
}

void func_8013E92C(s32 arg0) {
    if (func_8013E6DC() != 0) {
        func_80056128(arg0, 0x11);
        return;
    }
    Object_StepOnGroundFixed(arg0);
}

void func_8013E970(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1) {
        M2C_FIELD(arg0, s16 *, 0x46) = 0xF0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (((M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s16 *, 0x1E)) + 0x78) * 2);
}

void func_8013E9B0(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x80) != 1) && (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB)) {
        M2C_FIELD(arg0, s8 *, 0xCE) = 3;
        M2C_FIELD(arg0, s8 *, 0x7F) = 5;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x14);
        func_800525E0();
        func_80052864(arg0);
    }
}

typedef struct { u16 f0; u16 f2; } Anim_8013EA18;
typedef struct { u8 pad0[0x44]; s16 f_44; u8 pad46[0x4]; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1F]; u8 f_7D; u8 pad7E[0x1]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[0x6]; Anim_8013EA18 *anim; u8 pad8C[0xE]; s16 f_9A; u8 pad9C[0x2]; s16 f_9E; s16 f_A0; u8 padA2[0x2]; s16 f_A4; u8 padA6[0x2]; s16 f_A8; u8 padAA[0x6]; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 padC9[0x13]; u8 f_DC; u8 f_DD; u8 padDE[0x2]; u32 f_E0; } Obj_8013EA18;
void func_80058134_8013EA18(void *, s32) asm("func_80058134");
void func_8013E640(void *arg0);
void func_8013E7CC(void *arg0);
void func_8013E92C(s32 arg0);
void func_8013E970(void *arg0);
void func_8013E9B0(void *arg0);

void func_8013EA18(Obj_8013EA18 *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        o->f_B0 = 0x5B;
        o->f_A0 = 100;
        o->f_44 = 100;
        o->f_4A = -0x4000;
        o->f_81 = 12;
        o->f_C8 = 6;
        o->f_DC = 1;
        o->f_7D = 7;
        o->f_DD = 1;
        o->f_7F = 0;
        o->f_A8 = 0;
        o->f_E0 &= ~0x1000;
        o->f_5C = o->anim[0].f0;
        func_8005588C(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        o->f_E0 |= 8;
    }
    func_8013E970(o);
    func_80058134_8013EA18(o, o->f_44);
    if ((o->f_E0 >> 20) & 1) {
        o->f_E0 &= ~0x100000;
        o->f_80 = 3;
    }
    switch (o->f_80) {
    case 1:
        if (Spike_WithinRadiusXZ(o->f_9A, o->f_9E, o->f_A4)) {
            o->f_80 = 2;
            o->f_7F = 2;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        if (func_8005588C(o, -1) == 0 && o->f_5C >= o->anim[o->f_7F].f2) {
            if (o->f_7F == 0) {
                o->f_7F = 1;
                o->f_5C = o->anim[o->f_7F].f0;
            } else {
                o->f_7F = 0;
                o->f_5C = o->anim[o->f_7F].f0;
                func_8005588C(o, ((g_RandSeed = g_RandSeed * 5 + 1) >> 9) + 10);
            }
        }
        break;
    case 2:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 3;
            o->f_7F = 3;
            o->f_5C = o->anim[o->f_7F].f0;
        }
        break;
    case 3:
        func_8013E7CC(o);
        break;
    case 4:
        func_8013E92C((s32)o);
        if (func_8005588C(o, -1) == 0) {
            o->f_80 = 3;
        }
        break;
    case 5:
        if (o->f_5C >= o->anim[o->f_7F].f2) {
            o->f_80 = 1;
            o->f_7F = 0;
            o->f_5C = o->anim[o->f_7F].f0;
            func_8005588C(o, (g_RandSeed = g_RandSeed * 5 + 1) >> 9);
        }
        break;
    }
    func_8013E640(o);
    func_8013E9B0(o);
}

extern struct { u8 pad0; u8 f_1; } D_800E77A0_8013ED00 asm("D_800E77A0");
extern u8 D_80140AC8[];
s32 Object_SpikeNear_8013ED00(void *, s32) asm("Object_SpikeNear");
void func_80051E98_8013ED00(void *, s32) asm("func_80051E98");
void *memset_8013ED00(void *, s32, s32) asm("memset");

void func_8013ED00(u8 *o) {
    SVECTOR b;
    SVECTOR a;
    s16 f;

    if (((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1) == 0) {
        M2C_FIELD(o, s16 *, 0x96) = 0x96;
        M2C_FIELD(o, s16 *, 0x44) = 1;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7DFD;
        M2C_FIELD(o, s16 *, 0x48) = 1;
        M2C_FIELD(o, s16 *, 0xA0) = 0;
        M2C_FIELD(o, s16 *, 0x98) = 0;
        M2C_FIELD(o, s16 *, 0x94) = 0;
        M2C_FIELD(o, u8 *, 0x8F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) &= ~0x1000;
        M2C_FIELD(o, s16 *, 0x9C) = M2C_FIELD(o, u16 *, 0x28);
        func_8005588C(o, 0x32);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u16 *, 0x5C) = *(u16 *)(M2C_FIELD(o, u8 *, 0x7F) * 4 + M2C_FIELD(o, u8 **, 0x88));
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        M2C_FIELD(o, u8 *, 0xC8) = 0;
        M2C_FIELD(o, s16 *, 0xA0) += 6;
        if (func_8005588C(o, -1) == 0) {
            M2C_FIELD(o, u8 *, 0xC8) = 10;
            M2C_FIELD(o, u8 *, 0x80) = 2;
        }
        break;
    case 2:
        M2C_FIELD(o, s16 *, 0x96) += 6;
        M2C_FIELD(o, s32 *, 0x28) += M2C_FIELD(o, s16 *, 0x96);
        f = Object_FloorAt(o, 0, 0, 0);
        if (f < M2C_FIELD(o, s32 *, 0x28)) {
            M2C_FIELD(o, s32 *, 0x28) = f;
            M2C_FIELD(o, u8 *, 0x80) = 3;
            M2C_FIELD(o, u8 *, 0x8F)++;
        }
        if (Object_SpikeNear_8013ED00(o, 0x1F4)) {
            Object_AddAttackSphereNear(o, 0x190, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, u16 *, 0x28) + 0x64, M2C_FIELD(o, s16 *, 0x2C), 0xA01, 0x203);
        } else if (M2C_FIELD(o, s32 *, 0x28) < f - 0x2BC) {
            Object_AddAttackSphereNear(o, 0x190, M2C_FIELD(o, s16 *, 0x24), M2C_FIELD(o, s16 *, 0x28), M2C_FIELD(o, s16 *, 0x2C), 1, 0x101);
        }
        break;
    case 3:
        memset_8013ED00(&a, 0, 8);
        a.vx = M2C_FIELD(o, u16 *, 0x24);
        a.vy = M2C_FIELD(o, u16 *, 0x28);
        a.vz = M2C_FIELD(o, u16 *, 0x2C);
        b = a;
        func_800702B0(&b, D_80140AC8);
        func_80051E98_8013ED00(o, 0);
        D_800E77A0_8013ED00.f_1--;
        break;
    }
}

s32 Math_Atan2(s32, s32);

void func_8013EF6C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 4;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
    M2C_FIELD(arg0, s32 *, 0xE0) &= 0xFF3FFFFF;
    M2C_FIELD(arg0, s16 *, 0xAA) = (Math_Atan2(M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C)) + 0x1000) % 0x1000;
}

void func_8013EFF8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 2;
    M2C_FIELD(arg0, s8 *, 0x7F) = 2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 8);
    Object_PlaySound(arg0, 0x62);
}

void func_8013F030(void *arg0) {
    s16 temp_s0;

    temp_s0 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    if (func_80055718(arg0, temp_s0, M2C_FIELD(arg0, s16 *, 0x28), (s16) (M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC)), 0x14) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        func_8005588C(arg0, 0x1E);
    }
    Object_SeekHeight(arg0, 8);
    func_800563E0(arg0, 0x14);
}

s32 Object_AddAttackSphereNear_8013F0F8(void *, s16, s16, s16, s32, s32, s32) asm("Object_AddAttackSphereNear");
s32 Object_DetachLink_8013F0F8(void *, s32) asm("Object_DetachLink");
void Object_PlaySound_8013F0F8(void *, s32) asm("Object_PlaySound");
void Object_ApplyVelocity_8013F0F8(void *) asm("Object_ApplyVelocity");
s32 func_80055718_8013F0F8(void *, s16, s16, s16, s32) asm("func_80055718");
s32 Object_StepGrowShrink_8013F0F8(void *, s16, s16, s16) asm("Object_StepGrowShrink");
void func_8013EF6C(void *arg0);

void func_8013F0F8(u8 *a) {
    s16 *v;

    if (Object_DetachLink_8013F0F8(a, 0) == 6) {
        Object_PlaySound_8013F0F8(a, 0x5F);
        func_8013EF6C(a);
        return;
    }
    if (M2C_FIELD(a, u16 *, 0xE2) & 1) {
        Object_StepGrowShrink_8013F0F8(a, 0x53, 0x37, 0);
    }
    if (func_80055718_8013F0F8(a, M2C_FIELD(a, s16 *, 0xBC), M2C_FIELD(a, s16 *, 0xBE), M2C_FIELD(a, s16 *, 0xC0), M2C_FIELD(a, s16 *, 0xA8) >> 3)) {
        func_8013EF6C(a);
        return;
    }
    v = (s16 *)(a + 0x60);
    v[0] = M2C_FIELD(a, u16 *, 0x94);
    v[1] = M2C_FIELD(a, u16 *, 0x96);
    v[2] = M2C_FIELD(a, u16 *, 0x98);
    M2C_FIELD(a, u32 *, 0xE0) = (M2C_FIELD(a, u32 *, 0xE0) & 0xFF3FFFFF) | 0x800000;
    Object_ApplyVelocity_8013F0F8(a);
    M2C_FIELD(a, s32 *, 0xB4) = Object_AddAttackSphereNear_8013F0F8(a, M2C_FIELD(a, u16 *, 0x44) + 50, M2C_FIELD(a, s16 *, 0x24), M2C_FIELD(a, u16 *, 0x28) - 30, M2C_FIELD(a, s16 *, 0x2C), 1, 0x103);
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; } g_Spike_8013F21C asm("g_Spike");

void func_8013F21C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x80) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) |= 0x10000;
    M2C_FIELD(arg0, u16 *, 0xBC) = g_Spike_8013F21C.x;
    M2C_FIELD(arg0, u16 *, 0xC0) = g_Spike_8013F21C.z;
    M2C_FIELD(arg0, u16 *, 0xBE) = g_Spike_8013F21C.y - 0xC8;
    M2C_FIELD(arg0, u8 *, 0x8F) = 0;
}

void func_8013F26C(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x200000;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x96) >= 0x39) {
        M2C_FIELD(arg0, u8 *, 0x82) = 0;
        M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0;
        M2C_FIELD(arg0, u32 *, 0xE0) &= ~0x100000;
        M2C_FIELD(arg0, u16 *, 0x5C) = *M2C_FIELD(arg0, u16 **, 0x88);
        M2C_FIELD(arg0, u8 *, 0x80) = 5;
    }
}

extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; } g_Spike_8013F2E0 asm("g_Spike");
void func_80055F1C(void *, s32);
void func_80058134_8013F2E0(void *, s32) asm("func_80058134");
void func_8013F26C(void *arg0);
void func_80055E6C(void *, s32);
s32 Object_SpikeInFront(void *, s32, s32, s32);
void Object_TurnToward_8013F2E0(void *, s16, s16, s32, s32) asm("Object_TurnToward");
void func_8013F21C(void *arg0);
void func_8013F0F8(u8 *a);
void func_8013F030(void *arg0);
void func_8013EFF8(void *arg0);
void func_80054220(void *);
#define ANIM_8013F2E0(o, i) ((u16 *)(M2C_FIELD(o, u8 **, 0x88) + (i) * 4))

void func_8013F2E0(u8 *o) {
    if (!((M2C_FIELD(o, u32 *, 0xE0) >> 3) & 1)) {
        M2C_FIELD(o, s16 *, 0xA0) = 50;
        M2C_FIELD(o, s16 *, 0xB0) = 0x5B;
        M2C_FIELD(o, s16 *, 0x44) = 60;
        M2C_FIELD(o, s16 *, 0x48) = 0x201;
        M2C_FIELD(o, s16 *, 0x4A) = -0x7EFD;
        M2C_FIELD(o, s16 *, 0x46) = 100;
        M2C_FIELD(o, u8 *, 0xCD) = 1;
        M2C_FIELD(o, u8 *, 0x81) = 6;
        M2C_FIELD(o, u8 *, 0xDC) = 8;
        M2C_FIELD(o, s16 *, 0x9C) -= 200;
        M2C_FIELD(o, s32 *, 0x28) = M2C_FIELD(o, s16 *, 0x9C);
        M2C_FIELD(o, u8 *, 0x7F) = 0;
        M2C_FIELD(o, u32 *, 0xE0) |= 0x200000;
        M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F2E0(o, 0)[0];
        func_80055F1C(o, 8);
        M2C_FIELD(o, u32 *, 0xE0) |= 8;
    }
    func_80058134_8013F2E0(o, M2C_FIELD(o, s16 *, 0x44));
    if (M2C_FIELD(o, u8 *, 0x82) != 0) {
        M2C_FIELD(o, u32 *, 0xE0) &= ~0xC00000;
        func_8013F26C(o);
        return;
    }
    switch (M2C_FIELD(o, u8 *, 0x80)) {
    case 1:
        func_80055E6C(o, 8);
        Object_SeekHeight(o, 8);
        func_800563E0(o, 20);
        if (func_8005588C(o, -1) == 0 && Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
            func_8013EFF8(o);
        }
        break;
    case 2:
        Object_TurnToward_8013F2E0(o, g_Spike_8013F2E0.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013F2E0.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F2E0(o, M2C_FIELD(o, u8 *, 0x7F))[1] - 10) {
            func_8013F21C(o);
        }
        break;
    case 3:
        if (M2C_FIELD(o, u8 *, 0x8F) < 3) {
            if (++M2C_FIELD(o, u8 *, 0x8F) == 3) {
                Object_PlaySound(o, 0xA6);
            }
        }
        func_8013F0F8(o);
        if (Object_FloorAt(o, 0, 0, 0) < M2C_FIELD(o, s32 *, 0x28)) {
            func_8013EF6C(o);
            break;
        }
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F2E0(o, M2C_FIELD(o, u8 *, 0x7F))[1] && M2C_FIELD(o, u8 *, 0x7F) != 4) {
            M2C_FIELD(o, u8 *, 0x7F) = 4;
            M2C_FIELD(o, u16 *, 0x5C) = ANIM_8013F2E0(o, 4)[0];
        }
        break;
    case 4:
        func_8013F030(o);
        break;
    case 5:
        Object_TurnToward_8013F2E0(o, g_Spike_8013F2E0.x - M2C_FIELD(o, u16 *, 0x24), g_Spike_8013F2E0.z - M2C_FIELD(o, u16 *, 0x2C), 0, 0x1000);
        if (M2C_FIELD(o, u16 *, 0x5C) >= ANIM_8013F2E0(o, M2C_FIELD(o, u8 *, 0x7F))[1] && ++M2C_FIELD(o, u8 *, 0x8F) == 3) {
            if (Object_SpikeInFront(o, 360, -0x1000, 0x400)) {
                func_8013EFF8(o);
            } else {
                M2C_FIELD(o, u8 *, 0x80) = 1;
                M2C_FIELD(o, u8 *, 0xC9) = 0;
            }
        }
        break;
    }
    func_80054220(o);
}
__asm__(".section .rodata\n\t.align 3\n\t.section .text");

#include "gte.h"
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } Mat_8013F678;
typedef struct { u8 pad0[8]; s32 sx; s32 sy; s32 z; s32 sxy; u8 pad18[4]; u16 seed0; u16 seed1; SVECTOR v; SVECTOR cam; } Scr_8013F678;
typedef struct { s16 x, y, z; s8 active; u8 speed; } Flake_8013F678;
typedef struct { s16 dx, dz; } Wind_8013F678;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_8013F678;
#define ADDPRIM_BF_8013F678(ot, p) (((PTag_8013F678 *)(p))->addr = ((PTag_8013F678 *)(ot))->addr, ((PTag_8013F678 *)(ot))->addr = (u32)(p))
#define gte_stszotz_8013F678(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")
extern Wind_8013F678 D_80141B38_8013F678 asm("D_80141B38");
extern Flake_8013F678 D_80141408_8013F678[] asm("D_80141408");
extern Mat_8013F678 D_800E78C0_8013F678 asm("D_800E78C0");
extern GameDraw g_Game_8013F678 asm("g_Game");
extern struct { u8 pad0[0x8258]; SVECTOR camA; SVECTOR camB; } g_GameCam_8013F678 asm("g_Game");
void SetRotMatrix_8013F678(Mat_8013F678 *) asm("SetRotMatrix");
void SetTransMatrix_8013F678(Mat_8013F678 *) asm("SetTransMatrix");
s32 SquareRoot0_8013F678(s32) asm("SquareRoot0");
#define SCR_8013F678 ((Scr_8013F678 *)0x1F800000)

s32 func_8013F678(void) {
    Scr_8013F678 *sc;
    s16 dx;
    s16 dz;
    s32 fall;
    s32 dx8;
    s32 dz8;
    s32 i;
    Flake_8013F678 *f;
    u32 *p;
    u32 *ot;
    s32 w;
    s32 xy;
    s32 t3;
    s16 lim;
    s32 x2;
    s16 t;
    s16 c;
    s32 h;

    sc = SCR_8013F678;
    dx = D_80141B38_8013F678.dx;
    dz = D_80141B38_8013F678.dz;
    sc->cam = g_GameCam_8013F678.camA;
    if (dx != -3 && dz != -3) {
        fall = SquareRoot0_8013F678(dx * dx + dz * dz) * 2;
        if (fall < 12) {
            fall = 12;
        }
        t = dx * 4;
        c = t < -0x40 ? -0x40 : (t > 0x40 ? 0x40 : t);
        dx = c;
        t = dz * 4;
        c = t < -0x40 ? -0x40 : (t > 0x40 ? 0x40 : t);
        dz = c;
        sc->cam = g_GameCam_8013F678.camB;
    } else {
        fall = 12;
    }
    D_80141B38_8013F678.dz = -3;
    D_80141B38_8013F678.dx = -3;
    sc->seed0 = g_RandSeed;
    sc->seed1 = D_800AE8F2;
    SetRotMatrix_8013F678(&D_800E78C0_8013F678);
    SetTransMatrix_8013F678(&D_800E78C0_8013F678);
    p = (u32 *)g_Game_8013F678.prim;
    ot = g_Game_8013F678.db[g_Game_8013F678.cur].ot;
    i = 229;
    f = D_80141408_8013F678;
    dx8 = dx * 8;
    dz8 = dz * 8;
    for (; i >= 0; i--, f++) {
        if (f->active == 0) {
            f->active = 1;
            f->x = ((((u16)(sc->seed0 = sc->seed0 * 5 + 1) >> 8) - 0x80) << 4) + (((u16)(sc->seed1 = sc->seed1 * 5 + 1) >> 8) << 2) - dx8;
            f->z = ((((u16)(sc->seed1 = sc->seed1 * 5 + 1) >> 8) - 0x80) << 4) + (((u16)(sc->seed0 = sc->seed0 * 5 + 1) >> 8) << 2) - dz8;
            f->y = -0x464;
            f->speed = ((u16)(sc->seed1 = sc->seed1 * 5 + 1) >> 8) & 0xF;
        }
        f->x += dx;
        f->y += f->speed + fall;
        f->z += dz;
        lim = sc->cam.vy + 0x200;
        if (sc->cam.vy + f->y > lim) {
            f->active = 0;
        } else {
            sc->v.vx = sc->cam.vx + f->x;
            sc->v.vy = sc->cam.vy + f->y;
            sc->v.vz = sc->cam.vz + f->z;
            gte_ldv0(&sc->v);
            gte_rtps();
            gte_stsxy(&sc->sxy);
            gte_stszotz_8013F678(&sc->z);
            xy = sc->sxy;
            x2 = xy;
            xy = xy >> 16;
            __asm__("" : "=r"(xy) : "0"(xy));
            sc->sx = x2 & 0xFFFF;
            sc->sy = xy;
            if ((u32)(sc->sx + 0x20) < 0x1C1 && sc->sy >= -0x20 && sc->sy < 0x111) {
                if ((u32)(sc->z - 1) >= 0xFFF) {
                    f->active = 0;
                } else {
                    w = 0x11F0 / sc->z;
                    h = 0xF60 / sc->z;
                    ((u8 *)p)[3] = 9;
                    p[1] = 0x2F000000;
                    p[2] = sc->sxy;
                    p[4] = (sc->sy << 16) | ((sc->sx + w) & 0xFFFF);
                    p[6] = ((sc->sy + h) << 16) | (sc->sx & 0xFFFF);
                    p[8] = ((sc->sy + h) << 16) | ((sc->sx + w) & 0xFFFF);
                    p[3] = 0x7CAC00C0;
                    p[5] = 0x7C00EF;
                    ((u16 *)p)[14] = 0x2FC0;
                    ((u16 *)p)[18] = 0x2FEF;
                    ADDPRIM_BF_8013F678(ot + 2, p);
                    p += 10;
                }
            }
        }
    }
    g_Game_8013F678.prim = (u8 *)p;
    g_RandSeed = sc->seed0;
    D_800AE8F2 = sc->seed1;
    return 0;
}

void func_8013FC18(s16 arg0, s16 arg1) {
    M2C_FIELD(&D_80141B38, s16 *, 0) = arg0;
    M2C_FIELD(&D_80141B38, s16 *, 2) = arg1;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FC2C asm("g_Game");
extern u8 *D_800B4D64_8013FC2C asm("D_800B4D64");

s32 func_8013FC2C(s16 *p) {
    u8 *e = g_Game_8013FC2C.f_820C + p[2] * 0x38;
    u8 *e2;
    s32 i;

    if (p[4] == 0) {
        p[1] = 0;
        p[3] = 0;
    } else {
        p[1] = 2;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64_8013FC2C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        for (i = 1; i < 4; i++) {
            if (p[i + 4] >= 0) {
                e2 = g_Game_8013FC2C.f_820C + p[i + 4] * 0x38;
                M2C_FIELD(e2, u16 *, 0x18) = (M2C_FIELD(e2, u16 *, 0x18) & 0xFFF0) | 1;
            }
        }
        if (p[10] >= 0) {
            e2 = g_Game_8013FC2C.f_8220 + p[10] * 0x18;
            M2C_FIELD(e2, s16 *, 0xA) = 0;
        }
    }
    return 0;
}

extern struct { u32 f_0; u8 pad_4[0x80FC]; s32 f_8100; u8 pad_8104[0x108]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013FD2C asm("g_Game");
extern u8 *D_800B4D64_8013FD2C asm("D_800B4D64");
extern s16 D_800EC238;
extern u16 g_RandSeed;
void Camera_StartShake(s32);
void Pad_Vibrate(s32, s32, s32);
void CamFlyby_StartSegment(s32);
void Fx_Explosion(void *, s32, s32);
void Sound_PlayAt(s32, void *);

s32 func_8013FD2C(s16 *p) {
    u8 *e = g_Game_8013FD2C.f_820C + p[2] * 0x38;
    u8 *e2;
    s32 i;

    switch (p[1]) {
    case 0:
        if (M2C_FIELD(e, s16 *, 0x1E) >= 0) {
            Camera_StartShake(0);
            if (++p[3] > p[0xB]) {
                M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
                p[1] = 1;
                p[3] = 0;
                Pad_Vibrate(0, 1, 3);
                CamFlyby_StartSegment(0);
                g_Game_8013FD2C.f_8100 = 7;
                D_800EC238 = -1;
                if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
                    M2C_FIELD(D_800B4D64_8013FD2C + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
                    Fx_Explosion(e, M2C_FIELD(e, s16 *, 0xE), 1);
                }
            }
        } else if (g_Game_8013FD2C.f_0 % 10 == 0) {
            Sound_PlayAt((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 3) + 0xB5, e);
        }
        break;
    case 1:
        if (++p[3] >= 0x5B) {
            p[1] = 2;
            for (i = 1; i < 4; i++) {
                if (p[i + 4] >= 0) {
                    e2 = g_Game_8013FD2C.f_820C + p[i + 4] * 0x38;
                    M2C_FIELD(e2, u16 *, 0x18) = (M2C_FIELD(e2, u16 *, 0x18) & 0xFFF0) | 1;
                }
            }
            if (p[10] >= 0) {
                e2 = g_Game_8013FD2C.f_8220 + p[10] * 0x18;
                M2C_FIELD(e2, s16 *, 0xA) = 0;
            }
        } else {
            for (i = 1; i < 4; i++) {
                if (p[i + 4] >= 0) {
                    e2 = g_Game_8013FD2C.f_820C + p[i + 4] * 0x38;
                    if (M2C_FIELD(e2, s16 *, 0x2C) > 0) {
                        M2C_FIELD(e2, s16 *, 0x2C)++;
                    } else {
                        M2C_FIELD(e2, s16 *, 0x2C)--;
                    }
                    if (i >= 3) {
                        M2C_FIELD(e2, s16 *, 0x1C)++;
                    }
                }
            }
            if (p[10] >= 0) {
                e2 = g_Game_8013FD2C.f_8220 + p[10] * 0x18;
                M2C_FIELD(e2, s16 *, 0xA) = p[10] - p[10] * p[3] / 90;
            }
        }
        break;
    case 2:
        break;
    }
    return 0;
}

typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; s16 f10; s16 f12; s16 f14; } Ctl_80140048;
typedef struct { s16 f0; s16 f2; s16 pad4[4]; s16 fC; } Ent_80140048;
typedef struct { s16 pad0[3]; s16 f6; s16 pad8[8]; } Ent2_80140048;
extern struct { u8 pad_0[0x820C]; Ent_80140048 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80140048 asm("g_Game");
extern s16 D_80141B3C;

s32 func_80140048(Ctl_80140048 *p) {
    Ent_80140048 *e = (Ent_80140048 *)((u8 *)g_Game_80140048.f_820C + p->f4 * 0x38);

    e->fC = 0;
    p->f2 = 0;
    p->f6 = 0;
    p->f12 = 0;
    D_80141B3C = -1;
    p->f14 = e->f2;
    if (p->f8 >= 0) {
        u8 *t = g_Game_80140048.f_8220 + p->f8 * 0x18;
        M2C_FIELD(t, s16 *, 6) = p->fA;
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_801400C4 asm("g_Game");
extern s16 D_80141B3C;
extern u8 *D_800B4D64_801400C4 asm("D_800B4D64");
s32 Sound_Play(s32, s32);
void Sound_UpdateVoice3D(s32, s32, s32, void *);
void Sound_Stop(s32, s32);

s32 func_801400C4(s16 *p) {
    u8 *e = g_Game_801400C4.f_820C + p[2] * 0x38;
    s32 lvl = 0;
    u8 *t;
    s16 cur;

    if (p[4] >= 0) {
        t = g_Game_801400C4.f_8220 + p[4] * 0x18;
        lvl = M2C_FIELD(t, s16 *, 0x16);
    }
    switch (p[1]) {
    case 0:
        cur = p[9];
        if (lvl < cur) {
            p[1] = 2;
            p[9] = cur - p[7];
        } else {
            p[9] = lvl;
            if (lvl >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            }
        }
        break;
    case 1:
        if (--p[3] < 0) {
            p[1] = 2;
        }
        break;
    case 2:
        p[9] -= p[7];
        if (p[9] < lvl) {
            p[9] = lvl;
            if (lvl >= p[5]) {
                p[9] = p[5];
                p[1] = 1;
                p[3] = p[6];
            } else {
                p[1] = 0;
            }
        } else if (p[9] < 0) {
            p[9] = 0;
            p[1] = 0;
        }
        break;
    }
    if (p[9] > 0) {
        if (D_80141B3C < 0) {
            D_80141B3C = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, D_80141B3C, 0x2000, e);
        }
    } else if (D_80141B3C >= 0) {
        Sound_Stop(0x7F, D_80141B3C);
        D_80141B3C = -1;
    }
    M2C_FIELD(e, s16 *, 2) = p[0xA] + p[8] * p[9];
    M2C_FIELD(e, s16 *, 0x26) = p[0xA] + p[8] * p[9];
    M2C_FIELD(e, s16 *, 0xC) = 0;
    if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
        M2C_FIELD(D_800B4D64_801400C4 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x12) = p[0xA] + p[8] * p[9];
    }
    if (p[0xB] >= 0) {
        t = g_Game_801400C4.f_8220 + p[0xB] * 0x18;
        if (M2C_FIELD(t, s16 *, 0xC) >= 0) {
            M2C_FIELD(D_800B4D64_801400C4 + M2C_FIELD(t, s16 *, 0xC) * 32, s16 *, 0x12) = M2C_FIELD(t, s16 *, 8) + p[8] * p[9];
        }
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8014039C asm("g_Game");
extern u8 *D_800B4D64_8014039C asm("D_800B4D64");
void func_8004BD0C_8014039C(void *, s32) asm("func_8004BD0C");

s32 func_8014039C(s16 *p) {
    u8 *e = g_Game_8014039C.f_820C + p[2] * 0x38;
    s32 i = p[6];

    p[1] = 0;
    p[3] = 0;
    if (i >= 0) {
        p[4] = M2C_FIELD(D_800B4D64_8014039C + i * 32, s16 *, 0x12);
    }
    p[10] = p[5];
    if (p[5] == 0) {
        p[1] = 1;
        M2C_FIELD(D_800B4D64_8014039C + p[6] * 32, s16 *, 0x16) = 0;
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        func_8004BD0C_8014039C(e, i);
    } else {
        p[10] = Sound_Play(1, 0xB1);
        p[11] = Sound_Play(1, 0xB2);
    }
    return 0;
}

extern struct { u8 pad_0[0x820C]; u8 *f_820C; } g_Game_80140484 asm("g_Game");
extern u8 *D_800B4D64_80140484 asm("D_800B4D64");
extern struct { u8 pad_0[0x24]; s32 x; s32 y; s32 z; u8 pad_30[0x16]; s16 h; } g_Spike_80140484 asm("g_Spike");
s32 Sound_PlayFixed(s32);
void func_8004BD0C(void);
void RotMatrixZYX(SVECTOR *, void *);
void *CollShape_Alloc(void);
u32 Geo_ProjectOnLine_80140484(s16 *, s16 *, s16, s32 *) asm("Geo_ProjectOnLine");

s32 func_80140484(s16 *p) {
    SVECTOR v;
    s32 out[3];
    s16 a[4];
    s16 b[4];
    u8 *e;
    u8 *d;
    u8 *c;
    s32 dx;
    s32 dz;

    if (p[6] < 0) {
        return 0;
    }
    if (p[1] != 0) {
        return 0;
    }
    e = g_Game_80140484.f_820C + p[2] * 0x38;
    if (p[5] == 0) {
        Sound_Stop(0xB1, p[10]);
        Sound_Stop(0xB2, p[11]);
        Sound_PlayFixed(0xB3);
        Sound_PlayFixed(0xB4);
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
        p[1] = 1;
        M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, s16 *, 0x16) = 0;
        dx = p[8] / 2 * rsin(p[3]) / 4096;
        dz = p[8] / 2 * rcos(p[3]) / 4096;
        v.vx = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x10) + dx;
        v.vz = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x14) + dz;
        v.vy = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x12);
        Fx_Explosion(&v, p[6], 1);
        v.vx = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x10) - dx;
        v.vz = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x14) - dz;
        Fx_Explosion(&v, p[6], 1);
        func_8004BD0C();
        return 0;
    }
    Sound_UpdateVoice3D(0xB1, p[10], 0x1800, e);
    Sound_UpdateVoice3D(0xB2, p[11], 0x1800, e);
    if (p[5] > 0) {
        M2C_FIELD(e, s16 *, 0x2C) = -0x1000 / p[5];
    } else {
        M2C_FIELD(e, s16 *, 0x2C) = 0;
    }
    p[3] += p[5];
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
    } else if (p[3] < 0) {
        p[3] += 0x1000;
    }
    v.vz = 0;
    v.vx = 0;
    v.vy = p[3];
    RotMatrixZYX(&v, M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, void **, 0x1C));
    d = (u8 *)((s32)p[6] * 32 + (s32)D_800B4D64_80140484);
    if (M2C_FIELD(d, s16 *, 0x12) < g_Spike_80140484.y - g_Spike_80140484.h) {
        return 0;
    }
    if (g_Spike_80140484.y < M2C_FIELD(d, s16 *, 0x12)) {
        return 0;
    }
    a[0] = M2C_FIELD(d, u16 *, 0x10);
    a[1] = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, u16 *, 0x14);
    b[0] = g_Spike_80140484.x;
    b[1] = g_Spike_80140484.z;
    if (Geo_ProjectOnLine_80140484(a, b, -p[3], out) > p[8]) {
        return 0;
    }
    if (out[2] < p[7]) {
        v.vy = 0;
        v.vx = g_Spike_80140484.x - out[0];
        v.vz = g_Spike_80140484.z - out[1];
        VectorNormalSS(&v, &v);
        c = CollShape_Alloc();
        if (c != NULL) {
            *(SVECTOR *)(c + 0x18) = v;
            M2C_FIELD(c, s32 *, 0) = out[0];
            M2C_FIELD(c, s32 *, 4) = M2C_FIELD(D_800B4D64_80140484 + p[6] * 32, s16 *, 0x12);
            M2C_FIELD(c, s32 *, 8) = out[1];
            M2C_FIELD(c, s16 *, 0x20) = p[7];
            M2C_FIELD(c, s16 *, 0x24) = 1;
            M2C_FIELD(c, s16 *, 0x26) = 0x202;
            Collision_Set(6, c, 0);
        }
    }
    return 0;
}

extern struct S_g_Game { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game;

s32 func_801408E4(s16 *p) {
    u16 *e = (u16 *)(g_Game.f_820C + p[2] * 0x38);

    p[7] = e[0];
    p[8] = e[1];
    p[9] = e[2];
    return 0;
}

void func_80094B6C(s32, void *, void *);

s32 func_80140938(s16 *p) {
    func_80094B6C(p[4], g_Game.f_820C + p[2] * 0x38, p + 7);
    return 0;
}


/* the original text ends with padding words after the last function */
__asm__(".section .text\n\tnop\n\tnop");
