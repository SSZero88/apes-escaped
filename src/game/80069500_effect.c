#include "common.h"
#include "m2c_macros.h"
typedef struct { s16 vx, vy, vz; u8 f_6; u8 pad7; } S_Pos_8006962C;
typedef struct { u8 f_0; u8 f_1; u8 f_2; s8 f_3; u32 f_4; u8 pad8[0xA]; u8 f_12; u8 f_13; S_Pos_8006962C f_14; u8 pad1C[6]; s16 f_22; u8 pad24[6]; s16 f_2A; u8 pad2C[4]; u32 f_30; } S_Particle_8006962C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006AB10;

struct S_D_800B9900_80069548 *func_80069548(void);

M2C_UNK func_8006DAC8();
M2C_UNK func_8006E02C();
M2C_UNK func_8006ED4C();
M2C_UNK func_8006FE54();
M2C_UNK Puff_ClearAll();
M2C_UNK func_800710F8();

void Effect_Spawn(s32 id, s16 *pos, u32 *tbl, s16 **scripts);
extern M2C_UNK D_800B175C;
extern M2C_UNK D_800B1828;

void Fx_ClearAll(void);
M2C_UNK func_8006B7DC();
extern s8 D_800B9900;
extern s8 D_800BAD50;
M2C_UNK Fx_UpdateSpikeEffects();
M2C_UNK Fx_UpdateBlastSequence();
M2C_UNK func_8006D5A8();
M2C_UNK SuperHoop_DrawSparkles();
M2C_UNK func_8006E1C0();
M2C_UNK Fx_UpdateFadeRings();
M2C_UNK Shockwave_UpdateAll();
M2C_UNK func_80070560();
M2C_UNK Puff_UpdateAll();
M2C_UNK Debris_UpdateAll();
struct S_D_800B9900_80069548 { u8 f_0; u8 pad1; u8 f_2; u8 pad3[0x31]; };
extern u16 g_RandSeed;
extern struct S_D_800B1BD4 { u8 pad[0x54]; } D_800B1BD4[];
void func_80070284(s16 *pos, struct S_D_800B1BD4 *d, s32 a, s32 b, s32 c);
void Fx_SpawnFadeRing(s16 *pos, s32 a, s32 b, s32 c);
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; u16 f_60; u16 pad62; u16 f_64; } g_Spike;
void func_800A3740(void *, s32, s32);
void Effect_SpawnAt(s32, void *);
void func_80071120(s16 *, s32);
void Sound_PlayFixed(s32);

void func_80069500(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x63;
    var_v0 = &D_800B9900;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 += 0x34;
    } while (var_v1 >= 0);
    D_800BAD50 = 0;
    Fx_ClearAll();
    func_8006B7DC();
}

struct S_D_800B9900_80069548 *func_80069548(void) {
    s32 i;
    struct S_D_800B9900_80069548 *p;
    for (i = 99; i >= 0; i--) {
        if (++(*(u8 *)&D_800BAD50) >= 100) {
            (*(u8 *)&D_800BAD50) = 0;
        }
        p = &((struct S_D_800B9900_80069548 *)&D_800B9900)[(*(u8 *)&D_800BAD50)];
        if (p->f_0 == 0) {
            return p;
        }
    }
    for (i = 99; i >= 0; i--) {
        if (++(*(u8 *)&D_800BAD50) >= 100) {
            (*(u8 *)&D_800BAD50) = 0;
        }
        p = &((struct S_D_800B9900_80069548 *)&D_800B9900)[(*(u8 *)&D_800BAD50)];
        if (p->f_2 == 0) {
            return p;
        }
    }
    return ((struct S_D_800B9900_80069548 *)&D_800B9900);
}

void Particle_Spawn(s32 type, SVECTOR *pos, u32 *tbl) {
    S_Particle_8006962C *p = func_80069548();
    p->f_0 = type;
    *(SVECTOR *)&p->f_14 = *pos;
    if (type < 200) {
        p->f_4 = tbl[type];
    } else {
        p->f_4 = tbl[type - 200];
    }
    p->f_3 = -1;
    p->f_30 = 0x2C000000;
    p->f_1 = 0;
    p->f_22 = 0;
    p->f_12 = 0;
    p->f_13 = 0;
    p->f_14.f_6 = 0;
    p->f_2 = 0;
    p->f_2A = 0x7C;
}

/* Spawn effect `id` at pos. Ids below 0x100 are a single particle (Particle_Spawn); higher ids run
 * a script (scripts[id - 0x100], or scripts[id - 0x1C8] from 0x1C8 up) of 0-terminated commands,
 * each {type, y offset, ...}: 0x32 -> func_80070284(entry D_800B1BD4[a], b, c), 0x33 ->
 * Fx_SpawnFadeRing(a, b, c), any other type -> n + rand * m / 256 particles of that type. */
void Effect_Spawn(s32 id, s16 *pos, u32 *tbl, s16 **scripts) {
    s16 *s;
    u16 cmd;
    s32 n;
    s16 v[4];
    s32 a, b, c;

    if (id < 0x100) {
        Particle_Spawn(id, (SVECTOR *)pos, tbl);
        return;
    }
    if (id < 0x1C8) {
        s = scripts[id - 0x100];
    } else {
        s = scripts[id - 0x1C8];
    }
    cmd = *s++;
    while (cmd != 0) {
        v[0] = pos[0];
        v[1] = pos[1] + *s++;
        v[2] = pos[2];
        switch (cmd) {
        default:
            n = *s++;
            n += (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * *s++) >> 8;
            while (n > 0) {
                Particle_Spawn(cmd, (SVECTOR *)v, tbl);
                n--;
            }
            break;
        case 0x32:
            a = *s++;
            b = *s++;
            c = *s++;
            func_80070284(v, &D_800B1BD4[a], b, c, 0);
            break;
        case 0x33:
            {
            s32 x, y, z;
            x = *s++;
            y = *s++;
            z = *s++;
            Fx_SpawnFadeRing(v, x, y, z);
            }
            break;
        }
        cmd = *s++;
    }
}

void Effect_SpawnAt(s32 arg0, void *arg1) {
    Effect_Spawn(arg0, arg1, (u32 *)&D_800B175C, (s16 **)&D_800B1828);
}

void Effect_SpawnXYZ(s32 a0, s16 a1, s16 a2, s16 a3) {
    s16 v[3];
    v[0] = a1;
    v[1] = a2;
    v[2] = a3;
    Effect_Spawn(a0, v, (u32 *)&D_800B175C, (s16 **)&D_800B1828);
}

INCLUDE_ASM("asm/nonmatchings/game/80069500_effect", func_80069920);

INCLUDE_ASM("asm/nonmatchings/game/80069500_effect", func_80069BEC);

INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", D_800A5BF0);
INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", D_800A5C10);
INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", D_800A5C14);
INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", D_800A5C18);
INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", jtbl_800A5C48);
INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", jtbl_800A5C48_pad);


void Fx_ClearAll(void) {
    func_800710F8();
    func_8006FE54();
    Puff_ClearAll();
    func_8006DAC8();
    func_8006ED4C();
    func_8006E02C();
}

void Fx_UpdateAll(void) {
    Debris_UpdateAll();
    Shockwave_UpdateAll();
    Puff_UpdateAll();
    SuperHoop_DrawSparkles();
    Fx_UpdateFadeRings();
    func_8006E1C0();
    func_80070560();
    Fx_UpdateBlastSequence();
    func_8006D5A8();
    Fx_UpdateSpikeEffects();
}

void Fx_Explosion(s16 *pos, s32 b, s32 kind) {
    s32 snd;
    Effect_SpawnAt(0x109, pos);
    func_80071120(pos, b);
    switch (kind) {
    case 0:
    default:
        Effect_SpawnAt(0x105, pos);
        Effect_SpawnAt(0x103, pos);
        Sound_PlayFixed(0x4B);
        Sound_PlayFixed(0x5F);
        break;
    case 1:
        Sound_PlayFixed(0x4D);
        Sound_PlayFixed(0x5F);
        break;
    case 2:
        Sound_PlayFixed(0xB9);
        break;
    }
}

/* Spawn effects 0x105 and 0x108 just ahead of Spike: his position plus 1/12 of +0x60/+0x64,
   0x80 up. Only reached through a function pointer. */
void func_8006AB10(void) {
    SVEC_8006AB10 tmp;
    SVEC_8006AB10 v;
    func_800A3740(&v, 0, 8);
    v.vy = g_Spike.f_28 - 0x80;
    v.vx = g_Spike.f_24 + (s16)g_Spike.f_60 / 12;
    v.vz = g_Spike.f_2C + (s16)g_Spike.f_64 / 12;
    tmp = v;
    Effect_SpawnAt(0x105, &tmp);
    Effect_SpawnAt(0x108, &tmp);
}
