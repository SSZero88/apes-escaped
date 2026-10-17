#include "common.h"
#include "m2c_macros.h"
typedef struct { s32 v[9]; } S32x9_80032BBC_80032BBC;
typedef struct { u8 pad0[0x14]; void *f_14; s32 f_18; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[8]; s16 f_44; u8 pad46[2]; s16 f_48; s16 f_4A; u8 pad4C[0xC]; s16 f_58; u8 pad5A[2]; s16 f_5C; s16 f_5E; SVECTOR f_60; s16 f_68; s16 f_6A; s16 f_6C; u8 pad6E[2]; s32 f_70; u8 pad74[0x18]; s16 f_8C; u8 pad8E[0x74]; s16 f_102; u8 pad104[4]; s32 f_108; u8 pad10C[4]; s32 f_110; s32 f_114; u8 pad118[4]; s32 f_11C; u8 pad120[0xC]; s32 f_12C; } S_Spike_80032BBC_80032BBC;
typedef struct { u32 f_0; u16 f_4; u16 p6; u16 f_8; u16 pA; u16 f_C; u16 pE; u16 f_10; u16 p12; u16 f_14; u16 p16; u16 f_18; } Hdr_80032ADC_80032ADC;
typedef struct { u32 *f_0; u32 *f_4; u32 *f_8; u32 *f_C; u8 f_10[0x18]; u32 *f_28; } Obj_80032ADC_80032ADC;
typedef struct { u16 lo; u16 hi; } W_8003272C_8003272C;
typedef struct { u32 *a, *b, *c, *d; } AS_8003272C_8003272C;
typedef struct { u8 pad0[0x18]; u32 *f_18; u8 pad1C[0x14]; s32 f_30, f_34, f_38; u8 pad3C[0xA]; s16 f_46; u8 pad48[8]; s32 f_50; u8 pad54[0x12]; s16 f_66; u8 pad68[8]; s32 f_70; u8 pad74[0x1A]; s16 f_8E; u8 pad90[0x50]; s32 f_E0; u8 padE4[4]; s16 f_E8; u8 padEA[2]; s16 f_EC; u8 padEE[6]; s32 f_F4; s32 f_F8; u8 padFC[2]; s16 f_FE; u8 pad100[0x14]; s32 f_114, f_118, f_11C, f_120, f_124, f_128, f_12C; u8 pad130[8]; s32 f_138; u8 pad13C[0xC]; s16 f_148; } Sp_8003272C_8003272C;
typedef struct { s32 w[9]; } S32x9_80032D38;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80032D38;

M2C_UNK SetFarColor(u8, u8, u8);
extern struct S_D_800EBFA0 { u8 pad_0[0x1C]; u8 f_1C; u8 f_1D; u8 f_1E; u8 pad_1F[0x5]; u16 f_24; u8 pad_26[0x2]; u16 f_28; } D_800EBFA0;
struct S_D_800EC350_80032BBC { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 pad812C[0x74]; s32 f_81A0; u8 pad81A4[0xB4]; SVECTOR f_8258; SVECTOR f_8260; };
extern M2C_UNK g_Game;
extern M2C_UNK g_Spike;
extern M2C_UNK D_800E9C60;
void func_80010C3C(u16, u16, S32x9_80032BBC_80032BBC *);
s16 Floor_GetHeight(s32, s32, s32);
void VectorNormalSS(void *, void *);
void Collision_Set(s32, void *, void *);
void func_80047754(void);
struct Spike_80032ADC { u8 pad0[0x148]; s16 f_148; u8 f_14A; u8 f_14B; };
struct D4DE0_80032ADC { u8 pad0[0xA0]; u32 *f_A0; u32 *f_A4; u32 *f_A8; u32 *f_AC; };
extern Obj_80032ADC_80032ADC *D_800B4D70;
extern M2C_UNK g_SpikeAnimSets;
void func_80015AC0(void *, u32 *);
struct Game_8003272C { u8 pad0[0x819C]; u32 *f_819C; u32 *f_81A0; u8 pad81A4[0x58]; W_8003272C_8003272C *f_81FC; W_8003272C_8003272C *f_8200; W_8003272C_8003272C *f_8204; u8 pad8208[0x34]; u16 f_823C; u16 f_823E; };
extern s32 D_800EC010[];
extern u8 D_800EC060[];
extern u8 D_800F4C30[];
extern u8 D_800F4630[];
extern s16 D_800F4DC4;
void func_80015B30(Sp_8003272C_8003272C *, u32 *);
void func_80015D10(void *, u32 *);
void TimeNet_Init(u32 *);
struct g_Spike_80032D38 { u8 pad0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0xC6]; s32 f_12C; };
#define G_SPIKE_80032D38 ((struct g_Spike_80032D38 *)&g_Spike)

INCLUDE_ASM("asm/nonmatchings/game/80031B60_stage_load", func_80031B60);

INCLUDE_RODATA("asm/nonmatchings/game/80031B60_stage_load", D_800A47F0);
INCLUDE_RODATA("asm/nonmatchings/game/80031B60_stage_load", jtbl_800A47F8);


void Stage_ApplyFog(void) {
    u8 *scratch = (u8 *)0x1F800000;
    SetFarColor(D_800EBFA0.f_1C, D_800EBFA0.f_1D, D_800EBFA0.f_1E);
    *(u16 *)(scratch + 0x03C6) = 0;
    *(u16 *)(scratch + 0x03C4) = 0;
    *(u16 *)(scratch + 0x03C0) = D_800EBFA0.f_24;
    *(u16 *)(scratch + 0x03C2) = D_800EBFA0.f_28;
}

INCLUDE_ASM("asm/nonmatchings/game/80031B60_stage_load", func_8003244C);

INCLUDE_RODATA("asm/nonmatchings/game/80031B60_stage_load", D_800A48E0);


void Mem_ZeroWords(s32* dst, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dst++ = 0;
    }
}

/* Sets Spike up from his data block loaded at 0x80103000 (header of word offsets): model and
 * skeleton (g_Game+0x819C/+0x81A0), the 10 gadget animation sets g_SpikeAnimSets, and three
 * tables of effect models (g_Game+0x81FC -> D_800EC060, +0x8200 -> D_800F4C30,
 * +0x8204 -> D_800F4630). Resets his state: health (+0xE8) 5, velocities, timers, flags, and
 * the movement constants D_800EC010[0..17]. Returns 0. */
s32 Spike_Init(void) {
    W_8003272C_8003272C *h = (W_8003272C_8003272C *)0x80103000;
    W_8003272C_8003272C *p;
    s32 i;
    s32 n;
    p = (W_8003272C_8003272C *)0x80103000;
    (*(struct Game_8003272C *)&g_Game).f_819C = (u32 *)h + h[1].lo;
    (*(struct Game_8003272C *)&g_Game).f_81FC = (W_8003272C_8003272C *)((u32 *)h + h[2].lo);
    (*(struct Game_8003272C *)&g_Game).f_8200 = (W_8003272C_8003272C *)((u32 *)h + h[3].lo);
    (*(struct Game_8003272C *)&g_Game).f_8204 = (W_8003272C_8003272C *)((u32 *)h + h[4].lo);
    (*(struct Game_8003272C *)&g_Game).f_81A0 = (u32 *)h + h[5].lo;
    for (i = 0; i < 10; i++) {
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].a = (u32 *)h + p[i * 4 + 5].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].b = (u32 *)h + p[i * 4 + 6].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].c = (u32 *)h + p[i * 4 + 7].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].d = (u32 *)h + p[i * 4 + 8].lo;
    }
    Spike_LoadModelData(0);
    (*(struct Game_8003272C *)&g_Game).f_823E = 6;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_18 = (*(struct Game_8003272C *)&g_Game).f_81A0;
    func_80015B30(&(*(Sp_8003272C_8003272C *)&g_Spike), (*(struct Game_8003272C *)&g_Game).f_819C);
    (*(Sp_8003272C_8003272C *)&g_Spike).f_66 = 1;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_46 = 0x100;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_E8 = 5;
    D_800F4DC4 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_8E = 0x1000;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_30 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_34 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_38 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_120 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_124 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_128 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_114 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_118 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_11C = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_50 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_E0 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_EC = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_148 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_FE = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_12C = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_138 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_70 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_F4 = 0xFFFFFF;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_F8 = 0xFFFFFF;
    D_800EC010[0] = 0;
    D_800EC010[1] = 0xAD;
    D_800EC010[2] = -0x672;
    D_800EC010[3] = -0x29E;
    D_800EC010[4] = -0x690;
    D_800EC010[5] = 0x500;
    D_800EC010[6] = 1;
    D_800EC010[7] = 0xC8;
    D_800EC010[8] = 0x780;
    D_800EC010[9] = 0x3F2;
    D_800EC010[10] = 0x64;
    D_800EC010[11] = 0x50;
    D_800EC010[12] = 0x3C;
    D_800EC010[13] = -0x76C;
    D_800EC010[14] = -0x15AE;
    D_800EC010[15] = -0x1158;
    D_800EC010[16] = -0x78;
    D_800EC010[17] = 0xA5A;
    (*(struct Game_8003272C *)&g_Game).f_823C = (*(struct Game_8003272C *)&g_Game).f_81FC[0].lo - 1;
    for (i = 0; i < (*(struct Game_8003272C *)&g_Game).f_823C; i++) {
        func_80015D10(&D_800EC060[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_81FC + (*(struct Game_8003272C *)&g_Game).f_81FC[i + 1].lo);
    }
    TimeNet_Init((u32 *)(*(struct Game_8003272C *)&g_Game).f_81FC + (*(struct Game_8003272C *)&g_Game).f_81FC[i + 1].lo);
    n = *(s32 *)(*(struct Game_8003272C *)&g_Game).f_8200;
    for (i = 0; i < n; i++) {
        func_80015D10(&D_800F4C30[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_8200 + (*(struct Game_8003272C *)&g_Game).f_8200[i + 1].lo);
    }
    n = *(s32 *)(*(struct Game_8003272C *)&g_Game).f_8204;
    for (i = 0; i < n; i++) {
        func_80015D10(&D_800F4630[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_8204 + (*(struct Game_8003272C *)&g_Game).f_8204[i + 1].lo);
    }
    return 0;
}

/* Points D_800B4D70's data (and g_SpikeAnimSets+0xA0..0xAC) at the sections of block `h`, whose
 * header holds word offsets. NULL clears it and resets Spike's idle timer (+0x148) and flags. */
void Spike_LoadModelData(Hdr_80032ADC_80032ADC *h) {
    u32 *v;
    if (h == 0) {
        D_800B4D70 = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_14A = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_14B = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_148 = 0;
        return;
    }
    v = (u32 *)h + h->f_4;
    D_800B4D70->f_0 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A0 = v;
    v = (u32 *)h + h->f_8;
    D_800B4D70->f_4 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A4 = v;
    v = (u32 *)h + h->f_C;
    D_800B4D70->f_8 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A8 = v;
    v = (u32 *)h + h->f_10;
    D_800B4D70->f_C = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_AC = v;
    func_80015AC0(D_800B4D70->f_10, (u32 *)h + h->f_14);
    D_800B4D70->f_28 = (u32 *)h + h->f_18;
}

/* Stage start: reads the stage's spawn record, places Spike on the ground there
 * facing the given direction, resets his velocities and timers, and sets the camera position.
 */
s32 Spike_SpawnAtStageStart(void) {
    struct S_D_800EC350_80032BBC *d = (struct S_D_800EC350_80032BBC *)&g_Game;
    S_Spike_80032BBC_80032BBC *s;
    S32x9_80032BBC_80032BBC b;
    SVECTOR v;
    s32 x, z;
    func_80010C3C(d->f_8126, d->f_812A, &b);
    s = (S_Spike_80032BBC_80032BBC *)&g_Spike;
    d->f_8258.vx = b.v[3];
    d->f_8258.vy = b.v[4];
    d->f_8258.vz = b.v[5];
    d->f_8260.vx = b.v[0];
    d->f_8260.vy = b.v[1];
    d->f_8260.vz = b.v[2];
    x = b.v[0];
    z = b.v[2];
    s->f_24 = x;
    s->f_1C = x;
    s->f_2C = z;
    s->f_20 = z;
    s->f_1E = Floor_GetHeight(x, b.v[1], z);
    s->f_12C = s->f_1E;
    s->f_28 = s->f_1E;
    s->f_44 = 0x40;
    s->f_48 = 1;
    s->f_5C = 0;
    s->f_5E = 0;
    s->f_8C = 0;
    s->f_70 = 0;
    s->f_30 = 0;
    s->f_34 = 0;
    s->f_38 = 0;
    s->f_114 = 0;
    s->f_11C = 0;
    s->f_108 = 0;
    s->f_110 = 0;
    s->f_4A = 0x200;
    s->f_58 = -1;
    s->f_102 = 0;
    s->f_18 = d->f_81A0;
    v.vx = b.v[6];
    v.vy = b.v[7];
    v.vz = b.v[8];
    VectorNormalSS(&v, &v);
    s->f_6A = 0x1000;
    s->f_68 = 0;
    s->f_6C = 0;
    s->f_14 = &D_800E9C60;
    s->f_60.vx = v.vx;
    s->f_60.vy = v.vy;
    s->f_60.vz = v.vz;
    Collision_Set(1, &s->f_24, s);
    func_80047754();
    return 0;
}

/* Puts Spike on spawn point b of area id (func_80010C3C; area 0x3D always uses point 0): x/z from
 * the point, y from the floor height there (Floor_GetHeight), facing the point's direction
 * scaled by a and normalised. */
s32 Spike_PlaceAtSpawn(s32 a, s16 id, s32 b) {
    S32x9_80032D38 rec;
    SVEC_80032D38 dir;
    s16 h;
    s32 x;
    s32 y;
    s32 z;
    if (id == 0x3D) {
        b = 0;
    }
    ((s32 (*)(s32, s32, void *))func_80010C3C)(id, (s16)b, &rec);
    x = rec.w[0];
    z = rec.w[2];
    G_SPIKE_80032D38->f_24 = x;
    G_SPIKE_80032D38->f_1C = x;
    G_SPIKE_80032D38->f_2C = z;
    G_SPIKE_80032D38->f_20 = z;
    G_SPIKE_80032D38->f_12C = G_SPIKE_80032D38->f_1E = G_SPIKE_80032D38->f_28 = (s16)((s32 (*)(s32, s32, s32))Floor_GetHeight)(x, rec.w[1], z);
    dir.vx = (s16)a * rec.w[6];
    dir.vy = (s16)a * rec.w[7];
    dir.vz = (s16)a * rec.w[8];
    VectorNormalSS(&dir, &dir);
    G_SPIKE_80032D38->f_60 = dir.vx;
    G_SPIKE_80032D38->f_62 = dir.vy;
    G_SPIKE_80032D38->f_64 = dir.vz;
    return 0;
}
