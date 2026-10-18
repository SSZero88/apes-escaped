#include "common.h"
#include "m2c_macros.h"
#include "gte.h"
#include "common.h"
#define GM_520A8 ((struct Game_520A8 *)&g_Game)
#include "common.h"
typedef struct { u32 b0 : 5; u32 b5 : 1; u32 b6 : 4; u32 b10 : 1; u32 b11 : 9; u32 b20 : 1; u32 b21 : 11; } Flags_800522A8;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[4]; s32 f_2C; u8 pad30[0x52]; u8 f_82; u8 pad83; u8 f_84; u8 f_85; u8 pad86[0xE]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x3E]; s16 f_D8; u8 f_DA; u8 padDB[5]; Flags_800522A8 f_E0; } S_O_800522A8;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_800522A8;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80051F1C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0xB3]; u8 f_E3; } S_51F1C_80051F1C;
typedef struct { u16 f_0; u16 f_2; } S_Frame_800529A0;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80[8]; S_Frame_800529A0 *f_88; u8 pad8C[0x41]; u8 f_CD; u8 f_CE; u8 padCF[0x11]; u32 f_E0; } S_529A0_800529A0;
typedef struct { u8 pad0[0x5E]; u16 f_5E; u8 pad60[0x3A]; s16 f_9A; s16 f_9C; s16 f_9E; u8 padA0[0x2F]; u8 f_CF; u8 padD0[0x10]; u32 unkE0; } S_E6960;
typedef struct { u16 f_0; u16 f_2; } S_Frame_800528E0;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80; u8 f_81; u8 f_82; u8 pad83[5]; S_Frame_800528E0 *f_88; u8 pad8C[8]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x34]; u8 f_CE; u8 padCF[0x11]; u32 f_E0; } S_528E0_800528E0;
typedef struct { u8 pad_0[0x60]; s16 f_60; u8 pad_62[0x2]; s16 f_64; u8 pad_66[0x2E]; s16 f_94; u8 pad_96[0x2]; s16 f_98; u8 pad_9A[0x3E]; u16 f_D8; u8 f_DA; } S_80052800_80052800;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x68]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x46]; struct { u32 b0 : 5; u32 b5 : 1; u32 b6 : 4; u32 b10 : 1; u32 b11 : 21; } f_E0; } S_80052688_80052688;
typedef struct { s32 vx, vy, vz, pad; } Vec4_80051410;
typedef struct { s16 pad0; s16 x; s16 pad4; s16 z; u8 pad8[8]; u16 f_10; u16 f_12; u8 pad14[2]; u8 f_16; u8 pad17[9]; } S_Spawn_80050B04_80050B04;
typedef struct { u8 pad0[0x5E]; u16 f_5E; u8 pad60[0x3A]; s16 f_9A; s16 f_9C; s16 f_9E; u8 padA0[0x40]; u32 f_E0; } S_E6960_80050B04;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0xAC]; u8 f_DC; u8 padDD[6]; u8 f_E3; } S_51F1C_80051F1C_8005216C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80051F1C_8005216C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[2]; s16 f_8; u8 padA[0x20]; s16 f_2A; s16 f_2C; s16 f_2E; u8 pad30[8]; } S_820C_80051740_80051740;
typedef struct { u8 pad0[0x70]; u16 f_70; u8 pad72[0x3C]; s16 f_AE; u8 padB0[2]; s16 f_B2; } S_O_80051740_80051740;
typedef struct { s32 vx, vy, vz, pad; } VEC_800518AC_800518AC;
typedef struct { u8 pad0[0x14]; void *f_14; u8 pad18[0x48]; SVECTOR f_60; u8 pad68[0x44]; s16 f_AC; u8 padAE[0x14]; s16 f_C2; s16 f_C4; s16 f_C6; u8 f_C8; u8 padC9[0xB]; u16 f_D4; u16 f_D6; u8 padD8[8]; u32 f_E0; } S_O_800518AC_800518AC;
typedef struct { u8 pad0[0x7D]; s8 f_7D; u8 pad7E[4]; u8 f_82; u8 f_83; u8 pad84[0x57]; u8 f_DB; } S_O_8005240C_8005240C;
typedef struct { u8 pad0[0x18]; SVECTOR f_18; u8 pad20[6]; u16 f_26; } S_H_8005240C_8005240C;
typedef struct { u16 f_0; u8 pad2[0x14]; u8 f_16; u8 pad17[9]; } O_800509CC_800509CC;
typedef struct { u16 start; u16 end; } Anim_800511A4_800511A4;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x30]; u16 f_5C; u8 pad5E[2]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0xA]; u16 f_70; u8 pad72[0xC]; u8 f_7E; u8 f_7F; u8 pad80[2]; u8 f_82; u8 pad83[5]; Anim_800511A4_800511A4 *f_88; u8 pad8C[0x10]; s16 f_9C; u8 pad9E[0xE]; s16 f_AC; s16 f_AE; u8 padB0[2]; s16 f_B2; u8 padB4[0x2C]; u32 f_E0; } Obj_800511A4_800511A4;
typedef struct { u16 f_0; u8 pad2[0x1E]; } S_20_80051FE8;
typedef struct { u8 pad0[0xE3]; u8 f_E3; } S_52864_80052864;
typedef struct { u8 pad0[0x1C]; s32 f_1C; } S_20_800520A8;
typedef struct { u8 pad0[0x18]; u8 *f_18; } S_520A8_800520A8;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[0x1E]; u16 f_46; u8 pad48[0x80]; u8 f_C8; u8 padC9[0x17]; u32 f_E0; } O_51534_80051534;
typedef struct { u8 f_0; u8 pad1; s16 f_2; s16 f_4; s16 f_6; u16 f_8; u16 f_A; u16 f_C; u16 f_E; u8 pad10[6]; u8 f_16; } S_Spawn_800508B8;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x40]; u16 f_70; u8 pad72[0xC]; u8 f_7E; u8 pad7F[0xD]; s16 f_8C; u8 pad8E[0x16]; u16 f_A4; u16 f_A6; u8 padA8[0x23]; s8 f_CB; u8 f_CC; u8 padCD[0x13]; u32 f_E0; } S_508B8_800508B8;
typedef struct { u8 pad0[6]; u16 f_6; } Hdr_51C00_80051C00;
typedef struct { Hdr_51C00_80051C00 *hdr; u8 pad4[0x20]; u8 pos[0xC]; u8 pad30[0x30]; SVECTOR f_60; u16 f_68_; u8 pad6A[6]; u16 f_70; u8 pad72[0x12]; u8 f_84; u8 pad85[0x1B]; s16 f_A0; u8 padA2[0x2E]; s32 f_D0; u8 padD4[0xC]; u32 f_E0; } Obj_51C00_80051C00;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_51C00_80051C00;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; Db_51C00_80051C00 db[2]; } Game_51C00_80051C00;

void func_80014804(s32, MAT_800522A8 *);
M2C_UNK Object_TurnToward(void *, s16, s16, s16, s32);

void memset(void *, s32, s32);
void func_80051E98(void *arg0, s32 arg1);
void Effect_SpawnAt(s32, SVEC_80051F1C *);
void Object_PlaySound(S_51F1C_80051F1C *, s32);
void Object_DropPickups(S_51F1C_80051F1C_8005216C *s);

void func_80052864(S_52864_80052864 *s);

extern s16 D_800E77E0;
extern S_E6960 g_Objects[];
extern s8 D_800E77E8;

extern u32 D_800B8D00[];

M2C_UNK ApplyMatrixSV(void *, s32, void *);
extern M2C_UNK D_800F4730;

M2C_UNK func_80015780(void *, M2C_UNK);
void func_80051740(S_O_80051740_80051740 *o);
void func_800518AC(S_O_800518AC_800518AC *o);
void func_8005240C(S_O_8005240C_8005240C *o, S_H_8005240C_8005240C *h);
s32 func_800525A0(u8 *a0, u8 *a1);
s32 Collision_GetShape(s32);

void Object_SpawnNearby(void);
void Object_UpdateAll(void);
void Object_DrawAll(void);
M2C_UNK EnemyShot_Frame();
M2C_UNK func_8005E000(M2C_UNK, s32);
extern u8 D_800E77E4;
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; u8 pad_8104[0x140]; s32 f_8244; u8 pad_8248[0x50]; s16 f_8298; } g_Game;
M2C_UNK func_80015BA0(s32, s32);
s32 func_80051FE8(s32 a);
extern s32 D_800E77D4;
s16 Object_FloorAt(void *arg0, s16 arg1, s16 arg2, s16 arg3);

void func_80051620(void *arg0, s32 arg1, s32 arg2, void *arg3);
M2C_UNK Collision_Set(M2C_UNK, void *, void *);
M2C_UNK func_8007CD88(void *);
M2C_UNK Collision_Remove(void *);
M2C_UNK func_8007CDC4(void *);
u8 *func_800520A8(S_520A8_800520A8 *s, s32 key);
extern s8 D_800E77E2;
extern s8 D_800E77E3;
extern s8 D_800E77B0[];
void Object_EnableCollision(void *arg0);
void Object_Destroy(S_51F1C_80051F1C *s);
void Object_DisableCollision(void *arg0);
struct S_D_800EC350_80051E98 { u8 pad_0[0x8160]; u16 f_8160; };
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
extern s16 D_800B4D50;
extern s16 D_800B4D52;
void SetTransMatrix(void *m);
extern struct S_D_800E77D0 { s32 pad0; S_Spawn_80050B04_80050B04 *f_4; s32 pad8; s16 f_C; } D_800E77D0;
extern struct S_D_800EC1E0 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
S_E6960 *func_80050CB0(void);
/* Sets up object s from placement record r (kind, position, two angles, +0xC, optional
 * +0xE setting), resets it for its kind, records it as the object of placement id k
 * (D_800E77B0[k] = its slot) and marks the record as spawned (+0x16). */
void Object_SpawnFromRecord(S_508B8_800508B8 *s, S_Spawn_800508B8 *r, s32 k);
extern s8 D_800AF300[][4];
void Pickup_Drop(s32, SVEC_80051F1C_8005216C *, s32, s32);
struct S_D_800EC350_80051740 { u8 pad0[0x820C]; S_820C_80051740_80051740 *f_820C; };
extern struct S_D_800E77A080051740 { u8 pad0[8]; u16 f_8; u16 f_A; u16 f_C; } D_800E77A0;
s32 Math_Atan2(s32, s32);
s32 rsin(s32);
s32 rcos(s32);
struct S_D_800EC1E0_80051740 { u8 pad0[0x60]; s16 f_60; s16 f_62; s16 f_64; };
extern s8 D_800E77EE;
void Matrix_FromDirection(SVECTOR *, void *);
void RotMatrixYXZ(SVECTOR *, void *);
void ScaleMatrix(void *, VEC_800518AC_800518AC *);
struct S_D_800E77D0_8005240C { u8 pad0[0x19]; s8 f_19; s8 f_1A; u8 pad1B; s8 f_1C; };
extern s8 D_800AF330[][4];
extern s8 D_800E77EF;
void func_800522A8(S_O_800522A8 *o, s32 rot, s32 spd, short ang);
struct Game_800509CC { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; u8 pad8128[0x38]; s16 f_8160; };
extern char D_800A4F60[];
void bios_printf(const char *, ...);
s32 World_FirstStage(s32);
s32 func_80050580(s32 arg0);
void func_80054A08(u32 *);
struct S_D_800E77D0_800509CC { u8 pad0[4]; O_800509CC_800509CC *f_4; u8 pad8[4]; s16 f_C; };
extern struct S_D_800F4350 { u8 pad0[0x290]; u16 f_290; } D_800F4350;
extern void (*D_800AF574[])(void);
extern void (*D_800AF350[])(Obj_800511A4_800511A4 *);
void func_80052BC8(void *arg0);
s32 Object_UpdateAction();
void Object_FinishAction(S_528E0_800528E0 *s);
void func_8013F660(Obj_800511A4_800511A4 *);
void Hook_RunAll(void);
void func_80058954(void);
struct S_D_800E77D0_800511A4_800511A4 { u8 pad0[0x10]; s16 f_10; };
struct S_D_800E77A0_800511A4 { u8 f_0; };
struct S_D_800E77D0_80051FE8 { u8 pad0[4]; S_20_80051FE8 *f_4; u8 pad8[4]; s16 f_C; };
void func_800573A0(S_52864_80052864 *, s32, s32, s32);
struct Game_520A8 { u8 pad0[0x8244]; u8 *f_8244; };
struct S_D_800E77D0_800520A8 { u8 pad0[4]; S_20_800520A8 *f_4; };
s32 func_80051410(Vec4_80051410 *pos, s32 dy, s32 far);
/* Draws one stage object (called from Object_DrawAll): normalizes its facing (+0x60), drops a
 * shadow of size +0xA0 at the floor below it, builds the model matrix, applies the optional
 * extras (flag bit 13 of +0xE0, a joint-override when +0x70 != 0xFFFF) and adds it to the OT.
 * Flag bit 26 sends it through the alternate Model_CycleVertexColors/Model_DrawCycledColors path (header +6 is
 * passed); otherwise it is drawn with a flash brightness while the hit timer +0x84 counts down. */
void Object_Draw(Obj_51C00_80051C00 *o);
void func_80051A28(void *arg0);
struct S_D_800E77D0_80051534 { u8 pad0[0x10]; s16 f_10; };
void Object_SetPath(S_508B8_800508B8 *, u16);
void Object_Reset(S_508B8_800508B8 *, u8);
void func_80057FD0(S_508B8_800508B8 *, u8, s8);
extern u8 D_800E7D00[];
void VectorNormalSS(void *, void *);
void Shadow_Draw(void *, s32, s32, s32);
void func_800516D8(void *arg0);
void Model_ProjectBonedVerts(Obj_51C00_80051C00 *);
void Model_CycleVertexColors(u8 *, u16);
void Model_DrawCycledColors(u32 *, u8 *, Obj_51C00_80051C00 *);
typedef struct { u8 pad0[0x8]; u16 f_8; u8 padA[2]; s32 rgb[1]; } S_Hdr_51AA4;
typedef struct { S_Hdr_51AA4 *f_0; s32 f_4; s32 f_8; } S_Model_51AA4;
typedef struct { s32 rgb[0xF0]; s16 f_3C0; s16 f_3C2; s16 f_3C4; s16 f_3C6; u8 pad3C8[0x2C]; u8 f_3F4; } S_Scr_51AA4;
extern struct { u8 pad0[0x24]; u16 f_24; u8 pad26[2]; u16 f_28; } D_800EBFA0;

void func_80051AA4(u32 *, u8 *, S_Model_51AA4 *, s32);
void Model_DrawPrims(u32 *, s32, u8 *);

s32 func_80050580(s32 arg0) {
    if ((arg0 == 0x61) || (arg0 == 0x63) || (arg0 == 0x6D) || (arg0 == 0x6E) || (arg0 == 0x84) || ((u32) (arg0 - 0x72) < 0x44U)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80050580_object_draw", func_800505C8);

INCLUDE_RODATA("asm/nonmatchings/game/80050580_object_draw", D_800A4F60);


void Object_SpawnFromRecord(S_508B8_800508B8 *s, S_Spawn_800508B8 *r, s32 k) {
    s->f_7E = r->f_0;
    s->f_24 = r->f_2;
    s->f_28 = r->f_4;
    s->f_2C = r->f_6;
    s->f_A4 = r->f_8;
    s->f_A6 = r->f_A;
    s->f_70 = r->f_C;
    s->f_8C = 0;
    s->f_E0 &= ~8;
    if (r->f_E != 0xFFFF) {
        Object_SetPath(s, r->f_E);
    }
    Object_Reset(s, s->f_7E);
    D_800E77B0[k] = s->f_CB;
    func_80057FD0(s, s->f_7E, s->f_CB);
    r->f_16 = 1;
    s->f_CC = k;
}

void func_800509A4(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_800B8D00[i] = 0;
    }
}

/* Remembers which of the current area's spawn records (D_800E77D0+4, count +0xC; 0x20 bytes
 * each) are still there: one bit per record that func_80050580 does not exclude, set when its
 * +0x16 is 0, newest record in bit 0. Stored (after func_80054A08) in D_800B8D00 indexed by the
 * area within the stage (g_Game+0x8126 minus the stage's first area, World_FirstStage; must be
 * < 8). Not for stage 0x20, which instead clears g_Game+0x8160. */
void Area_SaveObjectMask(void) {
    u32 mask;
    s32 area;
    s32 i;
    O_800509CC_800509CC *objs = ((struct S_D_800E77D0_800509CC *)&D_800E77D0)->f_4;
    O_800509CC_800509CC *o;
    if ((*(struct Game_800509CC *)&g_Game).f_8124 == 0x20) {
        (*(struct Game_800509CC *)&g_Game).f_8160 = 0;
        return;
    }
    if (((struct S_D_800E77D0_800509CC *)&D_800E77D0)->f_C == 0) {
        return;
    }
    area = (*(struct Game_800509CC *)&g_Game).f_8126 - World_FirstStage((*(struct Game_800509CC *)&g_Game).f_8124);
    if (area >= 8) {
        bios_printf(D_800A4F60);
        area = 0;
    }
    mask = 0;
    if (((struct S_D_800E77D0_800509CC *)&D_800E77D0)->f_C > 0) {
        for (i = ((struct S_D_800E77D0_800509CC *)&D_800E77D0)->f_C - 1; i >= 0; i--) {
            o = &objs[i];
            if (!func_80050580(o->f_0)) {
                mask <<= 1;
                if (o->f_16 == 0) {
                    mask |= 1;
                }
            }
        }
    }
    func_80054A08(&mask);
    D_800B8D00[area] = mask;
}

void func_80050AFC(void) {
}

void Object_SpawnNearby(void) {
    S_Spawn_80050B04_80050B04 *list = D_800E77D0.f_4;
    S_Spawn_80050B04_80050B04 *s;
    s16 px = g_Spike.f_24;
    s16 pz = g_Spike.f_2C;
    s32 i;
    S_E6960_80050B04 *o;
    s32 dx, dz;
    for (i = 0; i < D_800E77D0.f_C; i++) {
        s = &list[i];
        if (s->f_16 == 0 && s->f_10 != 0) {
            dx = s->x - px;
            dz = s->z - pz;
            if (s->f_12 * s->f_12 < dx * dx + dz * dz) {
                o = func_80050CB0();
                if (o != 0) {
                    s->f_16 = 1;
                    s->f_10--;
                    Object_SpawnFromRecord(o, s, i);
                }
            }
        }
    }
}

void Object_Frame(void) {
    EnemyShot_Frame();
    if (D_800E77E4 == 0) {
        if (!(g_Game.f_8100 & 4)) {
            Object_UpdateAll();
        }
        func_8005E000(1, 0x10A0F0);
        Object_DrawAll();
        Object_SpawnNearby();
    }
}

S_E6960 *func_80050CB0(void) {
    s32 i;
    for (i = 0; i < D_800E77E0; i++) {
        if (!((g_Objects[i].unkE0 >> 4) & 1)) {
            return &g_Objects[i];
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80050580_object_draw", Object_Reset);

/* Per-frame update of all stage objects (0xE4-byte slots in g_Objects, count D_800E77D0+0x10).
 * First runs the mode hook D_800AF574[D_800E77A0.f_0]. For each live object (flag 0x10): records
 * its link id (+0x70) in D_800F4350+0x290, clears flag 0x100, steps the animation frame (+0x5C,
 * wrapping per the anim table +0x88), turns it by +0xB2 while the timer +0xAE runs, then
 * func_80052BC8 / Object_UpdateAction (2 -> Object_FinishAction). An object 0x800 below its floor (+0x9C,
 * unless flag 0x40000) is destroyed; otherwise its type handler D_800AF350[type] runs when +0x82
 * is 0 or flag 0x200000 is set. Ends with Hook_RunAll and func_80058954. */
void Object_UpdateAll(void) {
    s32 i;
    Obj_800511A4_800511A4 *o;

    i = 0;
    D_800AF574[((struct S_D_800E77A0_800511A4 *)&D_800E77A0)->f_0]();
    for (; i < ((struct S_D_800E77D0_800511A4_800511A4 *)&D_800E77D0)->f_10; i++) {
        o = &((Obj_800511A4_800511A4 *)&g_Objects)[i];
        if (!((o->f_E0 >> 4) & 1)) {
            continue;
        }
        if (o->f_70 != 0xFFFF) {
            D_800F4350.f_290 = o->f_70;
        }
        o->f_E0 &= ~0x100;
        o->f_5C++;
        if (o->f_88[o->f_7F].end < o->f_5C) {
            o->f_5C = o->f_88[o->f_7F].start;
        }
        if (o->f_AE != 0) {
            o->f_AE--;
            {
                s32 t = o->f_B2 + 0x1000;
                o->f_AC = (o->f_AC + t) % 0x1000;
            }
            o->f_60 = rcos(o->f_AC);
            o->f_64 = rsin(o->f_AC);
        }
        func_80052BC8(o);
        if ((s16)Object_UpdateAction(o) == 2) {
            Object_FinishAction(o);
            continue;
        }
        if (!((o->f_E0 >> 18) & 1) && o->f_28 > o->f_9C + 0x800) {
            if (o->f_7E == 0x3F) {
                func_8013F660(o);
            } else {
                Object_Destroy(o);
            }
            continue;
        }
        if (o->f_82 == 0 || ((o->f_E0 >> 21) & 1)) {
            D_800AF350[o->f_7E](o);
        }
    }
    Hook_RunAll();
    func_80058954();
}

s32 func_80051410(Vec4_80051410 *pos, s32 dy, s32 far) {
    SVECTOR v;
    s32 sxy;
    s32 p;
    s32 z;
    s16 margin;
    s16 lim;
    s16 x, y;
    SetRotMatrix(&D_800E78C0);
    SetTransMatrix(&D_800E78C0);
    v.vx = pos->vx;
    v.vy = pos->vy - dy;
    v.vz = pos->vz;
    z = RotTransPers(&v, &sxy, &p, &p);
    x = sxy;
    y = sxy >> 16;
    if (far) {
        lim = D_800B4D52;
        margin = 500;
    } else {
        margin = 0;
        lim = D_800B4D50;
    }
    if (x < -100 - margin || x > margin + 484 || y < -100 - margin || y > margin + 340 || lim < z || z <= 0) {
        return 1;
    }
    return 0;
}

void Object_DrawAll(void) {
    s32 i;
    O_51534_80051534 *o;

    for (i = 0; i < ((struct S_D_800E77D0_80051534 *)&D_800E77D0)->f_10; i++) {
        o = &((O_51534_80051534 *)&g_Objects)[i];
        o->f_E0 |= 4;
        if ((o->f_E0 >> 4) & 1) {
            if (func_80051410(&o->f_24, (s16)o->f_46 / 2, (o->f_E0 >> 9) & 1) == 0) {
                o->f_E0 &= ~4;
                if (o->f_C8 != 0) {
                    Object_Draw(o);
                    continue;
                }
            }
            func_80051A28(o);
        }
    }
}

void func_80051620(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    void *temp_s0;

    temp_s0 = (void *)((u8 *)&D_800F4730 + (arg1 << 5));
    if (arg2 == -1) {
        M2C_FIELD(arg3, u16 *, 0) = (u16) M2C_FIELD(temp_s0, u16 *, 0x14);
        M2C_FIELD(arg3, u16 *, 2) = (u16) M2C_FIELD(temp_s0, u16 *, 0x18);
        M2C_FIELD(arg3, u16 *, 4) = (u16) M2C_FIELD(temp_s0, u16 *, 0x1C);
        return;
    }
    ApplyMatrixSV(temp_s0, M2C_FIELD(arg0, s32 *, 0x10) + (arg2 * 8), arg3);
    M2C_FIELD(arg3, u16 *, 0) = (u16) (M2C_FIELD(arg3, u16 *, 0) + M2C_FIELD(temp_s0, u16 *, 0x14));
    M2C_FIELD(arg3, u16 *, 2) = (u16) (M2C_FIELD(arg3, u16 *, 2) + M2C_FIELD(temp_s0, u16 *, 0x18));
    M2C_FIELD(arg3, u16 *, 4) = (u16) (M2C_FIELD(arg3, u16 *, 4) + M2C_FIELD(temp_s0, u16 *, 0x1C));
}

void func_800516D8(void *arg0) {
    s32 var_s1;
    void *temp_a3;
    void *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
loop_1:
    temp_a3 = M2C_FIELD(var_s0, void **, 0x74);
    var_s0 += 4;
    if (temp_a3 != NULL) {
        var_s1 += 1;
        func_80051620(arg0, M2C_FIELD(temp_a3, s16 *, 8), M2C_FIELD(temp_a3, s16 *, 0xA), temp_a3);
        if (var_s1 < 2) {
            goto loop_1;
        }
    }
}

void func_80051740(S_O_80051740_80051740 *o) {
    s32 a = Math_Atan2(((struct S_D_800EC1E0_80051740 *)&g_Spike)->f_60, ((struct S_D_800EC1E0_80051740 *)&g_Spike)->f_64);
    if (o->f_AE != 0) {
        a = (a + o->f_B2 + 0x1000) % 4096;
    }

    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_2A = rcos(a);
    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_2C = 0;
    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_2E = rsin(a);
    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_0 = D_800E77A0.f_8;
    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_2 = D_800E77A0.f_A + ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_8;
    ((struct S_D_800EC350_80051740 *)&g_Game)->f_820C[o->f_70].f_4 = D_800E77A0.f_C;
}

void func_800518AC(S_O_800518AC_800518AC *o) {
    SVECTOR r;
    VEC_800518AC_800518AC s;
    VEC_800518AC_800518AC t;
    s32 k;
    u32 mode;
    mode = (o->f_E0 >> 22) & 3;
    if (mode == 0) {
        func_80014804(&o->f_60, o->f_14);
    } else if (mode == 1) {
        r.vx = o->f_D4;
        r.vy = (0x1C00 - o->f_AC) % 4096;
        r.vz = o->f_D6;
        RotMatrixYXZ(&r, o->f_14);
    } else {
        Matrix_FromDirection(&o->f_60, o->f_14);
    }
    if (o->f_C8 != 10 || D_800E77EE != 0) {
        if (o->f_C8 == 0xFF) {
            s.vx = o->f_C2;
            s.vy = o->f_C4;
            s.vz = o->f_C6;
        } else {
            k = D_800E77EE;
            if (k == 0) {
                k = o->f_C8;
            }
            s.vx = s.vy = s.vz = (k << 12) / 10;
        }
        ScaleMatrix(o->f_14, &s);
    }
    if (*(u8 *)&o->f_E0 >> 7) {
        t.vx = t.vz = 0x14CC;
        t.vy = 0x600;
        ScaleMatrix(o->f_14, &t);
    }
}

void func_80051A28(void *arg0) {
    if ((((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 0xD) & 1) && (M2C_FIELD(arg0, u8 *, 0xC8) != 0)) {
        func_800518AC(arg0);
        func_80015780(arg0, 3);
        func_800516D8(arg0);
    }
    if (M2C_FIELD(arg0, u16 *, 0x70) != 0xFFFF) {
        func_80051740(arg0);
    }
}

/* Lights the model's vertex colours (stored after its header) with the GTE into the
 * scratchpad, ORing bits into each one when non-zero, then sets scratch draw mode 2
 * and draws via Model_DrawPrims. Called from Object_Draw.
 */
void func_80051AA4(u32 *ot, u8 *buf, S_Model_51AA4 *o, s32 bits) {
    s32 i;
    s32 *src;
    s32 c = o->f_8;
    S_Scr_51AA4 *sc = (S_Scr_51AA4 *)0x1F800000;

    if (bits == 0) {
        src = o->f_0->rgb;
        for (i = 0; i < o->f_0->f_8; i++) {
            gte_ldIR(0x1000, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2_mem(&sc->rgb[i]);
        }
    } else {
        src = o->f_0->rgb;
        for (i = 0; i < o->f_0->f_8; i++) {
            gte_ldIR(0x1000, 0, 0);
            gte_ldRGB(&src[i]);
            gte_cc();
            gte_stRGB2_mem(&sc->rgb[i]);
            sc->rgb[i] |= bits;
        }
    }
    sc->f_3C6 = 0;
    sc->f_3C4 = 0;
    sc->f_3F4 = 2;
    sc->f_3C0 = D_800EBFA0.f_24;
    sc->f_3C2 = D_800EBFA0.f_28;
    Model_DrawPrims(ot, c, buf);
}

void Object_Draw(Obj_51C00_80051C00 *o) {
    s32 k;
    s32 c;

    VectorNormalSS(&o->f_60, &o->f_60);
    if (o->f_A0 > 0) {
        Shadow_Draw(o->pos, Object_FloorAt(o, 0, 0, 0), o->f_A0, o->f_D0);
    }
    func_800518AC(o);
    func_80015780(o, 3);
    if ((o->f_E0 >> 13) & 1) {
        func_800516D8(o);
    }
    if (o->f_70 != 0xFFFF) {
        func_80051740(o);
    }
    Model_ProjectBonedVerts(o);
    if ((o->f_E0 >> 26) & 1) {
        Model_CycleVertexColors(D_800E7D00, o->hdr->f_6);
        Model_DrawCycledColors((*(Game_51C00_80051C00 *)&g_Game).db[(*(Game_51C00_80051C00 *)&g_Game).cur].ot, D_800E7D00, o);
        return;
    }
    if (o->f_84 != 0) {
        k = (*(Game_51C00_80051C00 *)&g_Game).frame % 5;
        if (k >= 3) {
            k = 5 - k;
        }
        c = k * 255 / 2;
        o->f_84--;
    } else {
        c = 0;
    }
    func_80051AA4((*(Game_51C00_80051C00 *)&g_Game).db[(*(Game_51C00_80051C00 *)&g_Game).cur].ot, D_800E7D00, (S_Model_51AA4 *)o, c);
}

void Object_EnableCollision(void *arg0) {
    u32 temp_v0;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) & 0x4002) == 0x4002) {
        Collision_Set(4, arg0 + 0x24, arg0);
        temp_v0 = M2C_FIELD(arg0, u32 *, 0xE0) & ~2;
        M2C_FIELD(arg0, u32 *, 0xE0) = temp_v0;
        if ((temp_v0 >> 0x1B) & 1) {
            func_8007CD88(arg0 + 0x1C);
        }
    }
}

void Object_DisableCollision(void *arg0) {
    u32 temp_v0;

    if ((M2C_FIELD(arg0, u32 *, 0xE0) & 0x4002) == 0x4000) {
        Collision_Remove(arg0 + 0x24);
        temp_v0 = M2C_FIELD(arg0, u32 *, 0xE0) | 2;
        M2C_FIELD(arg0, u32 *, 0xE0) = temp_v0;
        if ((temp_v0 >> 0x1B) & 1) {
            func_8007CDC4(arg0 + 0x1C);
        }
    }
}

void func_80051E98(void *arg0, s32 arg1)
{
  u8 temp_v1;
  if (arg1 != 0)
  {
    ((struct S_D_800EC350_80051E98 *)&g_Game)->f_8160 = (u16) (((struct S_D_800EC350_80051E98 *)&g_Game)->f_8160 + 1);
  }
  *((s16 *) (((s8 *) arg0) + 0x5E)) = 1;
  *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xE0))) & (~0x10));
  Object_DisableCollision(arg0);
  ;
  if ((*((u8 *) (((s8 *) arg0) + 0xCC))) != 0xFF)
  {
    *((s8 *) (((s8 *) (((*((u8 *) (((s8 *) arg0) + 0xCC))) << 5) + D_800E77D4)) + 0x16)) = 0;
  }
}

void Object_Destroy(S_51F1C_80051F1C *s) {
    SVEC_80051F1C tmp;
    SVEC_80051F1C v;
    memset(&v, 0, 8);
    v.vx = s->f_24;
    v.vy = s->f_28;
    v.vz = s->f_2C;
    tmp = v;
    func_80051E98(s, 1);
    if ((s->f_E3 & 3) == 2) {
        Effect_SpawnAt(0x102, &tmp);
        Object_PlaySound(s, 0x6E);
    } else {
        Effect_SpawnAt(0x106, &tmp);
    }
    Object_DropPickups(s);
}

s32 func_80051FE8(s32 a) {
    s32 i;
    S_20_80051FE8 *p = ((struct S_D_800E77D0_80051FE8 *)&D_800E77D0)->f_4;
    for (i = 0; i < ((struct S_D_800E77D0_80051FE8 *)&D_800E77D0)->f_C; i++) {
        if (p[i].f_0 == a) {
            return i;
        }
    }
    return -1;
}

void func_80052038(s32 arg0, M2C_UNK arg1) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = D_800E77D4;
    temp_v0 = func_80051FE8(arg1);
    if (temp_v0 != -1) {
        func_80015BA0(arg0, g_Game.f_8244 + M2C_FIELD(((temp_v0 << 5) + temp_s0), s32 *, 0x18));
    }
}

u8 *func_800520A8(S_520A8_800520A8 *s, s32 key) {
    S_20_800520A8 *tbl = ((struct S_D_800E77D0_800520A8 *)&D_800E77D0)->f_4;
    s32 i = func_80051FE8(key);
    u8 *h;
    u8 *p;
    if (i == -1) {
        return 0;
    }
    h = GM_520A8->f_8244 + tbl[i].f_1C;
    p = h + 4;
    s->f_18 = p + *(u16 *)h * 4;
    return p;
}

void func_80052134(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((s32 (*)())func_800520A8)();
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x88) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0x5C) = 0;
        M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    }
}

void Object_DropPickups(S_51F1C_80051F1C_8005216C *s) {
    SVEC_80051F1C_8005216C w;
    SVEC_80051F1C_8005216C v;
    s32 i;
    s32 k;
    memset(&v, 0, 8);
    v.vx = s->f_24;
    v.vy = s->f_28 - 50;
    v.vz = s->f_2C;
    w = v;
    if (s->f_DC == 0x63) {
        return;
    }
    for (i = 0; i < 4; i++) {
        k = D_800AF300[s->f_DC][i];
        if (k == -1) {
            return;
        }
        if (k != 0) {
            Pickup_Drop(k, &w, 3, 0);
            if (k == 3) {
                Pickup_Drop(3, &w, 3, 0);
            }
        } else {
            Pickup_Drop(3, &w, 3, 1);
        }
    }
}

void func_800522A8(S_O_800522A8 *o, s32 rot, s32 spd, short ang)
{
  MAT_800522A8 m;
  switch (o->f_82)
  {
    case 4:
      o->f_94 = 0;
      o->f_96 = -(((rsin((s16) ang) * ((s16) spd)) * 2) >> 12);
      o->f_98 = -(((rcos((s16) ang) * ((s16) spd)) * 2) >> 12);
      break;

    case 5:
      o->f_98 = -spd;
      o->f_96 = 0;
      o->f_94 = 0;
      o->f_DA = ang;
      o->f_D8 = spd * 8;
      break;

  }

  func_80014804(rot, &m);
  ApplyMatrixSV(&m, &o->f_94, &o->f_94);
  Object_TurnToward(o, g_Spike.f_24 - o->f_24, g_Spike.f_2C - o->f_2C, 0, 0x1000);
  o->f_84 = 0x14;
  o->f_85 = 0;
  o->f_E0.b10 = 0;
  o->f_E0.b5 = 0;
  o->f_E0.b20 = 0;
}

void func_8005240C(S_O_8005240C_8005240C *o, S_H_8005240C_8005240C *h) {
    struct S_D_800E77D0_8005240C *g = (struct S_D_800E77D0_8005240C *)&D_800E77D0;
    s16 spd;
    s16 ang;
    s32 v;
    switch (g->f_19) {
    case 1:
        ang = (g->f_1C << 12) / 360;
        spd = g->f_1A;
        o->f_82 = 4;
        break;
    case 2:
        spd = g->f_1A;
        ang = g->f_1C;
        o->f_82 = 5;
        break;
    default:
        if (o->f_DB == 0) {
            o->f_83 = h->f_26;
            if ((h->f_26 & 0x3F00) == 0x200) {
                o->f_82 = 4;
            } else {
                o->f_82 = 5;
            }
        } else {
            o->f_82 = o->f_DB;
        }
        if (o->f_82 == 4) {
            spd = D_800AF330[o->f_83][0];
            ang = (D_800AF330[o->f_83][1] << 12) / 360;
        } else {
            spd = 0x23;
            ang = 0x14;
        }
        break;
    }
    if (o->f_7D == 10) {
        spd = 0;
    } else {
        spd = spd * (10 - D_800E77EF - o->f_7D) / 10;
    }
    func_800522A8(o, (s32)&h->f_18, spd, ang);
}

s32 func_800525A0(u8 *a0, u8 *a1) {
    if (D_800E77E8 != 0) {
        s32 v = a0[0x81] - (*(u16 *)(a1 + 0x24) & 0xF);
        if (v <= 0) {
            a0[0x81] = 0;
            return 1;
        }
        a0[0x81] = v;
    }
    return 0;
}

void func_800525E0(void *arg0) {
    s32 temp_v0;

    temp_v0 = Collision_GetShape(M2C_FIELD(arg0, u16 *, 0x50) & 0xFFF);
    func_8005240C(arg0, temp_v0);
    if (func_800525A0(arg0, temp_v0) != 0) {
        Object_DisableCollision(arg0);
    }
}

s32 func_80052640(void *arg0) {
    return ((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB;
}

void func_80052658(void *arg0) {
    u16 temp_v1;

    temp_v1 = M2C_FIELD(((M2C_FIELD(arg0, u8 *, 0x7F) * 4) + M2C_FIELD(arg0, s32 *, 0x88)), u16 *, 2);
    if (M2C_FIELD(arg0, u16 *, 0x5C) == temp_v1) {
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (temp_v1 - 1);
    }
}

s32 func_80052688(S_80052688_80052688 *m, s16 y) {
    s16 t = m->f_96;

    if (m->f_96 < 0x40) {
        t = 0x40;
    }
    if (y + t < m->f_28 && !m->f_E0.b5) {
        m->f_94 *= -1;
        m->f_98 *= -1;
        m->f_E0.b5 = 1;
    } else if (m->f_28 >= y) {
        m->f_28 = y;
        if (m->f_E0.b10) {
            return 1;
        }
        m->f_96 = -m->f_96 / 2;
        m->f_94 >>= 1;
        m->f_98 >>= 1;
        m->f_E0.b10 = 1;
    }
    return 0;
}

s16 func_8005278C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96));
    g_Game.f_8298 = 1;
    return Object_FloorAt(arg0, 0, 0, 0);
}

s32 func_80052800(S_80052800_80052800 *arg0)
{
  short s;
  u16 t;
  s = ((s16) arg0->f_D8) >> 3;
  arg0->f_94 = ((-arg0->f_60) * s) >> 12;
  t = arg0->f_D8 - arg0->f_DA;
  arg0->f_D8 = t;
  arg0->f_98 = ((-arg0->f_64) * s) >> 12;
  return ((s16) t) < 11;
}

void func_80052864(S_52864_80052864 *s) {
    s32 v;
    s32 id;
    func_800573A0(s, 0, 0, 0);
    v = s->f_E3 & 3;
    switch (v) {
    case 1:
        Object_PlaySound(s, 0x60);
        break;
    case 2:
        Object_PlaySound(s, 0x6A);
        break;
    default:
        Object_PlaySound(s, 0x5F);
        break;
    }
    Object_PlaySound(s, 0x15);
}

void Object_FinishAction(S_528E0_800528E0 *s) {
    s->f_82 = 0;
    s->f_98 = 0;
    s->f_96 = 0;
    s->f_94 = 0;
    if (s->f_81 == 0) {
        if ((s->f_E0 >> 21) & 1) {
            Object_EnableCollision(s);
        } else {
            Object_PlaySound(s, 0x15);
            if (D_800E77E8 != 0) {
                Object_Destroy(s);
            }
        }
    } else if (s->f_CE != s->f_7F) {
        s->f_7F = s->f_CE;
        s->f_5C = s->f_88[s->f_7F].f_0;
    }
}

void func_800529A0(S_529A0_800529A0 *s) {
    if ((s->f_E0 >> 12) & 1) {
        if (func_80052640(s) == 1) {
            s->f_CE = s->f_7F;
            s->f_7F = s->f_CD;
            s->f_5C = s->f_88[s->f_7F].f_0;
            func_800525E0(s);
            func_80052864(s);
        }
    }
}

typedef struct { u16 f_0; u16 f_2; } S_Fr_80052A24;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x30]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80[2]; u8 f_82; u8 f_83; u8 pad84; u8 f_85; u8 pad86[2]; S_Fr_80052A24 *f_88; u8 pad8C[0xA]; s16 f_96; u8 pad98[0x48]; u32 f_E0; } S_O_80052A24;
struct S_E77D0_80052A24 { u8 pad0[0x19]; s8 f_19; u8 pad1A[3]; s8 f_1D; };
#define ABS_52A24(x) ((x) < 0 ? -(x) : (x))
s32 Object_UpdateAction(S_O_80052A24 *o) {
    s32 y;
    if (o->f_82 == 0) {
        func_800529A0((void *)o);
        return 0;
    }
    o->f_85++;
    if (!((o->f_E0 >> 20) & 1)) {
        y = ((s32 (*)(void *))func_8005278C)(o);
        func_80052658(o);
        switch (o->f_82) {
        case 4:
            if (func_80052688((void *)o, y) != 0) {
                o->f_E0 |= 0x100000;
            }
            o->f_96 = o->f_96 + (((struct S_E77D0_80052A24 *)&D_800E77D0)->f_19 == 1 ? ((struct S_E77D0_80052A24 *)&D_800E77D0)->f_1D : D_800AF330[o->f_83][2]);
            break;
        case 5:
            if (func_80052800((void *)o) != 0 || ABS_52A24(o->f_28 - (s16)y) > 0x80) {
                o->f_E0 |= 0x100000;
            }
            o->f_28 = (s16)y;
            break;
        }
        return 1;
    } else {
        if (o->f_5C == o->f_88[o->f_7F].f_2) {
            return 2;
        }
    }
}

void func_80052BC8(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        if ((M2C_FIELD(arg0, u32 *, 0xE0) & 0x28000) == 0x8000) {
            M2C_FIELD(arg0, s16 *, 0x5E) = 2;
        } else {
            M2C_FIELD(arg0, s16 *, 0x5E) = 0;
        }
        if (((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 0x11) & 1) {
            M2C_FIELD(arg0, u32 *, 0x50) = 0U;
        }
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) | 0x20000);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x5E) = 0;
    M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (M2C_FIELD(arg0, u32 *, 0xE0) & 0xFFFDFFFF);
}

u16 func_80052C4C(s16 i) {
    s32 k = D_800E77B0[i];
    if (k == -1) {
        return 0;
    }
    return g_Objects[k].f_5E;
}

/* Looks up the object for `id` in D_800E77B0 (-1 = none) and sets its byte +0xCF to `v`. */
void Object_SetFlagCF(s16 id, u8 v) {
    s32 i = D_800E77B0[id];
    if (i != -1) {
        g_Objects[i].f_CF = v;
    }
}

void func_80052CEC(s8 arg0) {
    D_800E77E2 = arg0;
}

void func_80052CF8(s8 arg0) {
    D_800E77E3 = arg0;
}

s32 func_80052D04(s32 i, s32 *out) {
    s32 k = D_800E77B0[i];
    if (k == -1) {
        return 0;
    }
    out[0] = g_Objects[k].f_9A;
    out[1] = g_Objects[k].f_9C;
    out[2] = g_Objects[k].f_9E;
    return 1;
}
