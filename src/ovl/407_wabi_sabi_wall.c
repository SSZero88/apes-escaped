#include "common.h"
#include "m2c_macros.h"

M2C_UNK VectorNormalSS(void *, void *);
extern struct S_g_Spike { u8 pad_0[0x24]; u16 f_24; u8 pad_26[0x2]; u16 f_28; u8 pad_2A[0x2]; u16 f_2C; } g_Spike;
s32 Object_IsFacingDir(void *, M2C_UNK, M2C_UNK, s16, s32);

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);
extern s32 g_Game;
s8 Sound_ReserveSlot(M2C_UNK, M2C_UNK, void *);
M2C_UNK func_80088120(s8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D000);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D20C);

extern u8 D_80141B54[];
void func_80070284(SVECTOR *, void *, s32, s32, SVECTOR *);
void Effect_SpawnAt(s32, SVECTOR *);

void func_8013D358(s16 x, s16 y, s16 z) {
    SVECTOR v;
    SVECTOR d;

    v.vx = x;
    v.vy = y - 0x80;
    v.vz = z;
    d.vz = -0x1000;
    d.vx = 0;
    d.vy = 0;
    func_80070284(&v, D_80141B54, 1, 4, &d);
    Effect_SpawnAt(0x112, &v);
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D3BC);

void func_8006D568(void *);
s32 Object_AddAttackSphereNear(void *, M2C_UNK, s16, s16, s32, s32, s32);

void func_8013D4F0(void *arg0) {
    SVECTOR v;

    if (M2C_FIELD(arg0, u8 *, 0x8F) != 0) {
        M2C_FIELD(arg0, u8 *, 0x8F)++;
        M2C_FIELD(arg0, u16 *, 0xBC) += M2C_FIELD(arg0, u16 *, 0x94);
        M2C_FIELD(arg0, u16 *, 0xBE) += M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0xC0) += M2C_FIELD(arg0, u16 *, 0x98);
        v.vx = M2C_FIELD(arg0, u16 *, 0xBC);
        v.vy = M2C_FIELD(arg0, u16 *, 0xBE);
        v.vz = M2C_FIELD(arg0, u16 *, 0xC0);
        func_8006D568(&v);
        M2C_FIELD(arg0, s32 *, 0xB4) = Object_AddAttackSphereNear(arg0, 0x50, v.vx, v.vy, v.vz, M2C_FIELD(arg0, s16 *, 0x48), M2C_FIELD(arg0, s16 *, 0x4A));
        if (M2C_FIELD(arg0, u8 *, 0x8F) >= 0x33) {
            M2C_FIELD(arg0, u8 *, 0x8F) = 0;
        }
    }
}

void func_8013D5C0(void *arg0) {
    u8 st;

    if (!((M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        st = M2C_FIELD(arg0, u8 *, 0x7F);
        if (st == 2 && M2C_FIELD(arg0, u16 *, 0x5C) == *(u16 *)(M2C_FIELD(arg0, u8 **, 0x88) + M2C_FIELD(arg0, u8 *, 0x7F) * 4) + 7) {
            M2C_FIELD(arg0, s16 *, 0x94) = (M2C_FIELD(arg0, s16 *, 0x60) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x96) = (M2C_FIELD(arg0, s16 *, 0x62) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0x98) = (M2C_FIELD(arg0, s16 *, 0x64) * 0xF) >> 11;
            M2C_FIELD(arg0, s16 *, 0xBC) = M2C_FIELD(arg0, u16 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94) * 2;
            M2C_FIELD(arg0, s16 *, 0xBE) = M2C_FIELD(arg0, u16 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96) * 2;
            M2C_FIELD(arg0, s16 *, 0xC0) = M2C_FIELD(arg0, u16 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98) * 2;
            Object_PlaySound(arg0, 0x4D);
            M2C_FIELD(arg0, s8 *, 0x8F) = 1;
            M2C_FIELD(arg0, u32 *, 0xE0) |= 1;
        }
    }
}

s32 Object_SpikeOutOfRange(void *, s32, s32, s32, s16);

s32 func_8013D6BC(void *arg0) {
    return Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s16 *, 0x9E), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0;
}

void func_8013D6F0(void *arg0) {
    if (func_8013D6BC(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        M2C_FIELD(arg0, s8 *, 0x7F) = 1;
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 4);
        Object_PlaySound(arg0, 0x62);
        M2C_FIELD(arg0, s8 *, 0x8F) = 0;
    }
}

void func_8013D744(void *arg0) {
    void *temp_a0;

    M2C_FIELD(arg0, s16 *, 0x60) = (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24));
    M2C_FIELD(arg0, s16 *, 0x62) = (s16) (g_Spike.f_28 - M2C_FIELD(arg0, u16 *, 0x28));
    M2C_FIELD(arg0, s16 *, 0x64) = (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C));
    temp_a0 = arg0 + 0x60;
    VectorNormalSS(temp_a0, temp_a0);
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D7AC);

void func_8013D98C(void *arg0) {
    Object_AddAttackSphereNear(arg0, 0x12C, M2C_FIELD(arg0, s16 *, 0x24), M2C_FIELD(arg0, u16 *, 0x28) - 0x12C,
                               M2C_FIELD(arg0, s16 *, 0x2C), 0xA01, 0x200);
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013D9D8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DC64);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DE8C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013DF50);

s32 func_8013E044(void *arg0) {
    s32 var_s0;

    var_s0 = 0;
    if (Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x1200) != 0) {
        var_s0 = Object_IsFacingDir(arg0, 0x5A, 0xB50, (s16) (g_Spike.f_24 - (u16) M2C_FIELD(arg0, s32 *, 0x24)), (s32) (s16) (g_Spike.f_2C - (u16) M2C_FIELD(arg0, s32 *, 0x2C))) != 0;
    }
    return var_s0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E0D0);

void func_8013E358(void *arg0) {
    if ((Spike_WithinRadiusXZ(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), 0x800) != 0) && !(g_Game & 3)) {
        Object_PlaySound(arg0, 0x12);
    }
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E3AC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E43C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E46C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E51C);

s32 func_8005588C(void *, s32);

void func_8013E5C4(void *arg0)
{
  u16 new_var3;
  int new_var;
  s8 *new_var2;
  *((s8 *) (((s8 *) arg0) + 0x80)) = 1;
  new_var = 0x3C;
  *((s8 *) (((s8 *) arg0) + 0x7F)) = 0;
  new_var3 = (u16) (*(*((u16 **) (((s8 *) arg0) + 0x88))));
  new_var2 = ((s8 *) arg0) + 0xB0;
  *((s16 *) new_var2) = 0x5B;
  *((u16 *) (((s8 *) arg0) + 0x5C)) = new_var3;
  func_8005588C(arg0, new_var);
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E604);

void func_8013E6A8(s16 *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;

    if (arg2 != 0) {
        if (*arg0 < (arg1 * 8)) {
            *arg0 = (u16) *arg0 + 0xA;
        }
    } else {
        temp_v0 = (u16) *arg0 - 5;
        *arg0 = temp_v0;
        if ((s16) temp_v0 < 0) {
            *arg0 = 0;
        }
    }
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E6F8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013E7E8);

void func_8013EA9C(void *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x7C) == -1) {
        M2C_FIELD(arg0, s8 *, 0x7C) = Sound_ReserveSlot(0x705D, 0x1000, arg0 + 0x24);
    }
}

void func_8013EADC(void *arg0) {
    s8 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 *, 0x7C);
    if (temp_a0 != -1) {
        func_80088120(temp_a0);
    }
    M2C_FIELD(arg0, s8 *, 0x7C) = -1;
}

void Fx_BigExplosion(SVECTOR *);
void *memset(void *, s32, s32);

void func_8013EB20(void *arg0) {
    SVECTOR q;
    SVECTOR p;

    memset(&p, 0, 8);
    p.vx = M2C_FIELD(arg0, u16 *, 0x24);
    p.vy = M2C_FIELD(arg0, u16 *, 0x28);
    p.vz = M2C_FIELD(arg0, u16 *, 0x2C);
    q = p;
    Fx_BigExplosion(&q);
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EB9C);

s32 func_8013EDB8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x16) = -1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EDD0);

s32 func_8013EFA0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013EFB0);

extern struct S_g_Game_8013F1C0 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_8013F1C0 asm("g_Game");
s16 Sound_Play(s32, s32);

s32 func_8013F1C0(s16 *p) {
    u8 *t = g_Game_8013F1C0.f_820C;
    u16 *e = (u16 *)(t + p[5] * 0x38);

    p[1] = 0;
    p[3] = 0;
    p[6] = e[0];
    p[7] = e[1];
    p[8] = e[2];
    p[10] = Sound_Play(1, 0xB2);
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F240);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F3F8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F584);

s32 func_8013F8D4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xE) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x14) = 1;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013F8FC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FC68);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FDC8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FEA4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8013FF40);

s32 func_801400A4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 4;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801400B8);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014019C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140224);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801402C0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801404B0);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801405C4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014066C);

extern u8 *D_800B4D64;
extern struct { u8 pad0[0x20C]; u8 *f_20C; } D_800F4350;

s32 func_8014087C(u8 *a) {
    s16 ids[8];
    s16 i;
    s16 n;
    s16 id;
    u8 *e;
    u8 *tbl;

    ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
    ids[1] = M2C_FIELD(a, u8 *, 0xC);
    ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
    ids[3] = M2C_FIELD(a, u8 *, 0xE);
    ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
    ids[5] = M2C_FIELD(a, u8 *, 0x10);
    ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
    ids[7] = M2C_FIELD(a, u8 *, 0x12);
    tbl = D_800B4D64;
    n = i = 0;
    for (; i < 8; i++) {
        id = ids[i];
        if (id >= 0 && id != 0xFF) {
            e = D_800F4350.f_20C + id * 0x38;
            n++;
            M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 1;
            M2C_FIELD(e, s16 *, 0xE) += i;
            M2C_FIELD(tbl + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
    }
    M2C_FIELD(a, s16 *, 0x14) = M2C_FIELD(a, s16 *, 0xA) / n;
    M2C_FIELD(a, s16 *, 0x2) = 0;
    M2C_FIELD(a, s16 *, 0x6) = 0;
    return 0;
}

extern struct S_g_Game_801409C8 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; } g_Game_801409C8 asm("g_Game");

s32 func_801409C8(u8 *a) {
    s16 ids[8];
    s16 t;
    s32 r;
    s32 d;
    u8 *e;

    t = ++M2C_FIELD(a, s16 *, 0x6);
    if (t < M2C_FIELD(a, s16 *, 0xA) * 2) {
        if (t < (M2C_FIELD(a, s16 *, 0x14) / 2) * 2) {
            return 0;
        }
        ids[0] = M2C_FIELD(a, u16 *, 0xC) >> 8;
        ids[1] = M2C_FIELD(a, u8 *, 0xC);
        ids[2] = M2C_FIELD(a, u16 *, 0xE) >> 8;
        ids[3] = M2C_FIELD(a, u8 *, 0xE);
        ids[4] = M2C_FIELD(a, u16 *, 0x10) >> 8;
        ids[5] = M2C_FIELD(a, u8 *, 0x10);
        ids[6] = M2C_FIELD(a, u16 *, 0x12) >> 8;
        ids[7] = M2C_FIELD(a, u8 *, 0x12);
        r = M2C_FIELD(a, s16 *, 0x6) - (M2C_FIELD(a, s16 *, 0x14) / 2) * 2;
        d = M2C_FIELD(a, s16 *, 0x14) * 2;
        if (r % d != 0) {
            return 0;
        }
        e = g_Game_801409C8.f_820C + ids[r / d] * 0x38;
        M2C_FIELD(e, u16 *, 0x18) = (M2C_FIELD(e, u16 *, 0x18) & 0xFFF0) | 2;
        M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, u16 *, 0x16) = 0xFFFF;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140B58);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80140EB0);

extern struct S_g_Game_80141240 { u8 pad_0[0xC]; s32 f_C; u8 pad_10[0x81FC]; u8 *f_820C; u8 pad_8210[0x10]; u8 *f_8220; } g_Game_80141240 asm("g_Game");

s32 func_80141240(s16 *p) {
    u8 *e = g_Game_80141240.f_820C + p[2] * 0x38;

    if (p[5] == 0) {
        p[1] = 0;
    } else {
        p[1] = 1;
        if (M2C_FIELD(e, s16 *, 0xE) >= 0) {
            M2C_FIELD(D_800B4D64 + M2C_FIELD(e, s16 *, 0xE) * 32, s16 *, 0x16) = 0;
        }
        M2C_FIELD(e, u16 *, 0x18) |= 0x8000;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801412C4);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_801413AC);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014146C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80141538);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_8014164C);

INCLUDE_ASM("asm/ovl/407/nonmatchings/407_wabi_sabi_wall", func_80141874);
