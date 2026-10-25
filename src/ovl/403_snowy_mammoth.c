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

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013D16C);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013D488);

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
void func_8013D16C(void *);

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

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013E38C);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013E4FC);

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
void func_8013E4FC(void *);
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

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013EA18);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013ED00);

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

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013F2E0);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013F678);

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

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8013FD2C);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_80140048);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_801400C4);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_8014039C);

INCLUDE_ASM("asm/ovl/403/nonmatchings/403_snowy_mammoth", func_80140484);

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
