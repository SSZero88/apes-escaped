#include "common.h"
#include "m2c_macros.h"

extern struct S_g_Game { u8 pad_0[0x8154]; u16 f_8154; u8 pad_8156[0xCA]; void * f_8220; } g_Game;
M2C_UNK Pickup_Drop(M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern u8 D_800F51C1;
extern u16 g_RandSeed;
extern s16 g_SpikeHealth;

extern struct S_D_80143F08 { u8 pad_0[0xA]; s8 f_A; u8 pad_B[0x1]; } D_80143F08[];
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801442C8;
s32 Sound_Play(M2C_UNK, s32);
extern s32 D_801442CC;
M2C_UNK Effect_Spawn(M2C_UNK, s32, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80143718;
extern M2C_UNK D_80144570;
M2C_UNK func_8013D1F0(M2C_UNK, M2C_UNK *, void *);
extern M2C_UNK D_80144598;
extern M2C_UNK D_80143AF0;
M2C_UNK Camera_StartShake(M2C_UNK);
M2C_UNK func_8014097C(M2C_UNK *);
extern M2C_UNK D_80143D70;
extern s8 D_80143F04;

s32 func_8013D000(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 8);
    return 0;
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D014);

s32 func_8013D174(void) {
    return M2C_FIELD(g_Game.f_8220, s16 *, 0x1A) >= 4;
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D1A0);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D1F0);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D290);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D3EC);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D500);

void func_8013D52C(void) {
    s32 i;

    for (i = 79; i >= 0; i--) {
        D_80143F08[i].f_A = 0;
    }
}

#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
extern struct { s16 x, y, z, vy; s8 vx, vz, life; u8 pad; } D_80143F08_8013D554[] asm("D_80143F08");

void func_8013D554(SVECTOR *arg0) {
    s32 i;
    s16 x = arg0->vx;
    s16 y = arg0->vy;
    s16 z = arg0->vz;

    for (i = 0x4F; i >= 0; i--) {
        D_80143F08_8013D554[i].life = (RAND() >> 8 & 0x1F) + 0x28;
        D_80143F08_8013D554[i].x = x + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].y = y - ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].z = z + ((RAND() >> 8) - 0x80) * 2;
        D_80143F08_8013D554[i].vx = ((RAND() >> 8) - 0x80) / 2;
        D_80143F08_8013D554[i].vy = -(RAND() >> 8 & 0x3F) - 0x20;
        D_80143F08_8013D554[i].vz = ((RAND() >> 8) - 0x80) / 2;
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013D6BC);

void func_8013DA8C(void) {
    Pad_Vibrate(1, 0xC8, 0xA);
}

void func_8013DAB4(void) {
    Pad_Vibrate(1, 0x3C, 2);
}

void func_8013DADC(void) {
    Pad_Vibrate(1, 0x78, 2);
}

void func_8013DB04(s32 arg0) {
    M2C_UNK var_a2;
    u16 temp_v0;

    var_a2 = 1;
    if (g_SpikeHealth >= 3) {
        temp_v0 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0;
        if ((temp_v0 >> 8) & 1) {
            var_a2 = 6;
            if (g_Game.f_8154 == D_800F51C1) {
                var_a2 = 3;
            }
        }
    }
    Pickup_Drop(var_a2, arg0, 3, 0);
}

void func_8013DB98(void) {
    D_801442C8 = -1;
}

void func_8013DBA8(s32 arg0) {
    D_801442C8 = Sound_Play(0, arg0);
}

M2C_UNK Sound_Stop(void *, s32);

void func_8013DBD0(void *obj) {
    if (D_801442C8 != -1) {
        Sound_Stop(obj, D_801442C8);
    }
}

void func_8013DC00(void) {
    D_801442CC = -1;
}

void func_8013DC10(s32 arg0) {
    D_801442CC = Sound_Play(0, arg0);
}

void func_8013DC38(void *obj) {
    if (D_801442CC != -1) {
        Sound_Stop(obj, D_801442CC);
    }
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013DC68);

void func_8013DE24(s32 arg0) {
    s32 var_s0;

    var_s0 = 8;
    do {
        Effect_Spawn(0xCE, arg0, &D_80143718, 0);
        var_s0 -= 1;
    } while (var_s0 > 0);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013DE7C);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013DF68);

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_414;
typedef struct { P_TAG_414 tag; u32 rgbc; u32 xy; u32 wh; } TILE_414;
typedef struct { P_TAG_414 tag; u32 code; } DR_MODE_414;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_414;
struct Game_414 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_414 db[2]; };

void func_8013E464(s32 c)
{
  TILE_414 *p = (TILE_414 *) ((struct Game_414 *)&g_Game)->prim;
  u32 *ot = ((struct Game_414 *)&g_Game)->db[((struct Game_414 *)&g_Game)->cur].ot;
  DR_MODE_414 *m;
  p->tag.len = 3;
  p->rgbc = c | 0x62000000;
  p->xy = 0;
  p->wh = 0xF00180;
  p->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) p;
  p = (TILE_414 *) (p - -1);
  m = (DR_MODE_414 *) p;
  m->tag.len = 1;
  m->code = 0xE1000220;
  m->tag.addr = ((P_TAG_414 *) ot)->addr;
  ((P_TAG_414 *) ot)->addr = (u32) m;
  ((struct Game_414 *)&g_Game)->prim = (u8 *) (m + 1);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013E53C);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013E6E4);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013E9C8);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013EBC8);

void func_8013ECF4(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 1;
    var_v0 = &D_80144570;
    do {
        M2C_FIELD(var_v0, s8 *, 0xA) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x14));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013ED18);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013EE1C);

void func_8013F130(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    var_s1 = &D_80144598;
    var_s0 = (void *)((u8 *)&D_80144598 + 0x74);
    do {
        func_8013D1F0(3, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 0xC) = 0;
        var_s2 += 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x84));
        var_s1 = (void *)((u8 *)var_s1 + (0x84));
    } while (var_s2 <= 0);
}

void func_8013F190(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v0 = &D_80144598;
    var_v1 = 0;
    do {
        M2C_FIELD(var_v0, s8 *, 0x80) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0x84));
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F1B4);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F240);

void func_8013F68C(void) {
    M2C_UNK *var_s1;
    s32 var_s2;
    void *var_s0;

    var_s2 = 3;
    var_s1 = &D_80143AF0;
    var_s0 = (void *)((u8 *)&D_80143AF0 + 0x7C);
    do {
        func_8013D1F0(2, var_s1, var_s0);
        M2C_FIELD(var_s0, s8 *, 8) = 0;
        var_s2 -= 1;
        var_s0 = (void *)((u8 *)var_s0 + (0x98));
        var_s1 = (void *)((u8 *)var_s1 + (0x98));
    } while (var_s2 >= 0);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F6EC);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F838);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8013F8B8);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_801402D8);

void func_80140760(void) {
    D_80143F04 = 0;
    func_8014097C(&D_80143D70);
    Camera_StartShake(1);
}

s32 func_80140794(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x88) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x8A) - M2C_FIELD(arg0, s32 *, 0x28);
    temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x8C) - M2C_FIELD(arg0, s32 *, 0x2C);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3)) < (arg1 * arg1);
}

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_801407FC);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140948);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_8014097C);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140A18);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140A90);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140BF0);

INCLUDE_ASM("asm/ovl/414/nonmatchings/414_tv_tower2", func_80140D60);
