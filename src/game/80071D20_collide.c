#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define HEAD (*(S_Node_80072018_80072018 **)&g_CollisionHead)
#define TAIL (*(S_Node_80072018_80072018 **)&g_CollisionTail)
#define GM_78A18 ((struct Game_80078A18 *)&g_Game)
#define GS_78A18 ((struct GS_80078A18 *)&g_GadgetState)
#define GM_792C8 ((struct Game_800792C8 *)&g_Game)
typedef struct S_20D8_80078864 { s16 f_0; s16 f_2; u8 pad4[8]; struct S_20D8_80078864 *f_C; } S_20D8_80078864;
typedef struct { u8 pad0[0x4C]; s16 f_4C; } S_78864_80078864;
typedef struct { s16 unk0; s16 unk2; s32 f_4; u8 pad8[0xC]; } S_BBDA0;
typedef struct { u8 pad[0x38]; } S_BD1A0;
typedef struct { u16 f_0; u8 pad2[2]; u16 f_4; u8 pad6[2]; u16 f_8; u8 padA[0x18]; u16 f_22; } S_77C28_80077C28;
typedef struct { u8 pad0[0xC]; s32 f_C; u8 pad10[4]; s32 f_14; } S_80072BE8_80072BE8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[0xA]; u8 f_10; } S_A_8007734C_8007734C;
typedef struct { s32 f_0; s32 f_4; s32 f_8; } S_B_8007734C_8007734C;
typedef struct { s32 f_0; s32 f_4; s32 f_8; } S_P_8007734C_8007734C;
typedef struct S_Node_80072018_80072018 { s16 f_0; s16 f_2; s32 f_4; s32 f_8; struct S_Node_80072018_80072018 *f_C; struct S_Node_80072018_80072018 *f_10; } S_Node_80072018_80072018;
typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0x14]; s16 f_20; u8 pad22[2]; s16 f_24; u8 pad26[6]; s32 f_2C; } S_P_800788B8_800788B8;
typedef struct { u8 pad0[4]; S_P_800788B8_800788B8 *f_4; } S_O_800788B8_800788B8;
typedef struct { u8 pad0[0x20]; s16 f_20; } S_X_800788B8_800788B8;
typedef struct S_Node_800788B8_800788B8 { s16 f_0; s16 f_2; S_X_800788B8_800788B8 *f_4; u8 pad8[4]; struct S_Node_800788B8_800788B8 *f_C; } S_Node_800788B8_800788B8;
typedef struct { s16 vx; u16 vy; u16 vz; } S_Sc_800788B8_800788B8;
typedef struct { u8 pad0[0x26]; u16 f_26; u8 pad28[2]; s16 f_2A; } ObjA_80071E44_80071E44;
typedef struct { u8 pad0[0x4C]; s16 f_4C; } ObjB_80071E44_80071E44;
typedef struct Node_80071E44_80071E44 { s16 f_0; s16 f_2; ObjA_80071E44_80071E44 *f_4; ObjB_80071E44_80071E44 *f_8; struct Node_80071E44_80071E44 *f_C; struct Node_80071E44_80071E44 *f_10; } Node_80071E44_80071E44;
typedef struct { s32 x; s32 y; s32 z; s32 vx; s32 vy; s32 vz; } Roll_80072A14_80072A14;
typedef struct { s16 x; s16 y; s16 z; } O_800774B8_800774B8;
typedef struct { s32 x; s32 y; s32 z; } P_800774B8_800774B8;
typedef struct { s32 x, y, z; } V3_792C8_800792C8;
typedef struct { s32 x, y, z; u8 padC[0x28]; s16 f_34; } P_792C8_800792C8;
typedef struct { s16 x, y, z, f_6, f_8, f_A; u8 padC[4]; u16 f_10; u8 f_12; u8 pad13[5]; u16 f_18; u8 pad1A[0x1E]; } A_792C8_800792C8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[4]; u8 f_10; u8 pad11[0x13]; s16 f_24; s16 f_26; } O_76AC8_80076AC8;
typedef struct { s32 x, y, z; } P_76AC8_80076AC8;
typedef struct { s16 x, y, z, w, h, d; } O_76488_80076488;
typedef struct { s32 x, y, z; } P_76488_80076488;
typedef struct { s32 r, flags, h; } B_76488_80076488;
typedef struct { s16 x, y, z, f_6, f_8, f_A; } O_761AC_800761AC;
typedef struct { s32 r, flags, y; } B_761AC_800761AC;
typedef struct { s32 x, y, z; } P_761AC_800761AC;
typedef struct { s16 x, y, z, w, h, d; } O_73B64_80073B64;
typedef struct { s32 x, y, z; } P_73B64_80073B64;
typedef struct { s16 x, y, z, w, h, d; } O_73BC8_80073BC8;
typedef struct { s32 x, y, z; } P_73BC8_80073BC8;
typedef struct { u16 r; u8 pad2[2]; u8 kind; u8 pad5[3]; s32 h; } B_73BC8_80073BC8;
typedef struct { s32 f_0; s32 f_4; s32 f_8; } S_P_8007734C_8007734C_80075F48;
typedef struct { s16 x; s16 y; s16 z; s16 hx; s16 h; s16 hz; } Box_80075F48_80075F48;
typedef struct { s16 x, y, z, w, h, d; } O_75630_80075630;
typedef struct { s32 x, y, z; } P_75630_80075630;
typedef struct { u16 r; u8 pad2[2]; u8 kind; u8 pad5[3]; s32 h; } B_75630_80075630;
typedef struct { s16 x, y, z, w, h, d; } O_7449C_8007449C;
typedef struct { s32 x, y, z; } P_7449C_8007449C;
typedef struct { s32 r; s32 flags; s32 h; } B_7449C_8007449C;
typedef struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; s32 f_10; s32 f_14; } S_72D28_80072D28;
typedef struct { s32 x, y, z; s32 f_C; u8 pad10[4]; s32 f_14; u8 pad18[0x12]; u16 f_2A; s32 f_2C; u8 pad30[4]; s16 f_34; u8 pad36[2]; } Body_8007247C_8007247C;
typedef struct { s16 kind; u8 pad2[2]; Body_8007247C_8007247C *o; u8 pad8[4]; struct CNode_8007247C_8007247C *next; } CNode_8007247C_8007247C;
typedef struct { u8 pad0[0x1E]; s16 f_1E; u8 pad20[0x18]; } Ent_8007247C_8007247C;

extern struct S_D_800BEEA0 { s16 f_0; s16 f_2; s32 f_4; s16 f_8; s16 padA; } D_800BEEA0[];
extern S_20D8_80078864 *g_CollisionHead;

extern S_BBDA0 g_CollisionEntries[256];
extern S_BD1A0 D_800BD1A0[128];
extern s16 D_800BEDA0[];


M2C_UNK Sound_PauseVolumes(M2C_UNK);
M2C_UNK Sound_Stop(M2C_UNK, s16);
M2C_UNK func_8013FB20(M2C_UNK);
extern struct S_D_800B20D0 { s16 f_0; s16 f_2; } D_800B20D0;
extern struct S_D_800B20D4 { s16 f_0; s16 f_2; } D_800B20D4;
extern struct S_D_800EC350 { u8 pad_0[0x8124]; u16 f_8124; } g_Game;
M2C_UNK bios_printf(M2C_UNK *, s32);
extern M2C_UNK D_800A5E80;

extern s32 D_800B2130;
extern void *Coll_Cells;
extern s32 D_800EC250;
extern s32 g_CollisionTail;
s32 CollShape_Clear(void *arg0);
struct S_D_800BBDA0_80071D3C { s16 f_0; s16 f_2; s32 f_4; s32 f_8; s32 f_C; s32 f_10; };
struct S_D_800BD1A0_80071D3C { u8 pad0[0x38]; };
struct S_D_800EC350_80071D3C { u8 pad_0[0x8290]; s16 f_8290; u8 pad_8292[4]; s16 f_8296; s16 f_8298; };
struct S_D_800EC350_80072BE8 { u8 pad_0[0x8150]; u16 f_8150; };
extern s16 D_800B213C;
extern s16 D_800B213E;
extern u32 D_800E53C0;
s16 Sound_Play(s32, s32);
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
extern S_P_8007734C_8007734C *Coll_Pos;
s32 Coll_RampPieceHeight(S_A_8007734C_8007734C *, S_P_8007734C_8007734C *);
s32 Coll_HeightOverlap(s32, s32, s32, s32);
extern s16 D_800F5A78;
/* Spike picks up an item of `type` (sound 0xE for a Specter coin, 0xD for a life, else 0x7A):
 *   1  cookie: heals Spike by 1 (Spike_Heal(1))
 *   2  extra life: lives (g_Game+0x813C) + 1, at most 100
 *   3  energy chip (+1), 5 big energy chip (+5): chips (g_Game+0x8168) go up, the HUD shows the
 *      amount (g_HudState+2/+3); at 100 chips, 100 are taken for an extra life (sound 0xD).
 *      In game mode 0x13 (probably Time Trial) they stop the clock instead (TimeTrial_AddClockStop).
 *   4  Specter coin: coins (g_Game+0x816A) + 1, at most 60; SpecterCoin_Add(stage)
 *   6  explosive / 7 guided Slingback ammo: + 1 up to the capacity g_Game+0x8154 / +0x8156
 *      (the capacities the cheat codes set to 49 / 99). */
void Pickup_Collect(s16 type);
s32 Collider_GetCentre(s16 k, S_77C28_80077C28 *s, s16 *out);
s32 Vec_Length(s32, s32, s32);
extern char D_800A5D20[];
S_BBDA0 *Collision_AllocEntry(void);
s32 Link_GetKindSound(s16);
extern s32 D_800B2134;
extern s32 D_800B2138;
int abs(int);
void Sound_PlayAt(s32, SVECTOR *);
void Sound_UpdateVoice3D(s32, s16, s32, SVECTOR *);
void Sound_SetVoicePitch(s32, s16, s32);
struct S_D_800B20D0_80072A14 { s16 voice; s16 on; };
struct Game_80078A18 { u8 pad0[0x8120]; u16 mode; u8 pad8122[4]; u16 stage; u8 pad8128[0x14]; u16 lives; u8 pad813E[0x16]; u16 explosiveMax; u16 guidedMax; u8 pad8158[0x10]; s16 chips; s16 coins; };
struct GS_80078A18 { u8 pad0[0xA1]; u8 explosive; u8 guided; };
struct Hud_80078A18 { u8 pad0[2]; u8 f_2; u8 f_3; };
extern M2C_UNK g_GadgetState;
extern M2C_UNK g_HudState;
void Sound_PlayFixed(s32);
void Spike_Heal(s32);
void Hud_ShowLives(s32, s32);
void TimeTrial_AddClockStop(s32);
void Hud_ShowChips(s32);
void SpecterCoin_Add(s32);
s32 SquareRoot0(s32);
struct Game_800792C8 { u8 pad0[0x8150]; u16 f_8150; u8 pad8152[0xBA]; A_792C8_800792C8 *f_820C; u8 pad8210[0x74]; u16 f_8284; };
extern struct { u8 pad0[0x5E]; u16 f_5E; u8 pad60[0x10]; s32 f_70; } g_Spike;
s32 Coll_HalfCylinderHeight(s32, s16 *, V3_792C8_800792C8 *, V3_792C8_800792C8 *);
s32 Surface_CylinderHeight(s32, s16 *, V3_792C8_800792C8 *, V3_792C8_800792C8 *);
s32 Surface_QueryShape(s32, A_792C8_800792C8 *, V3_792C8_800792C8 *, V3_792C8_800792C8 *);
s32 Coll_CurvedCorner(O_76AC8_80076AC8 *, P_76AC8_80076AC8 *, s32 *, s16 *);
void CurvedCorner_GetCentre(O_76AC8_80076AC8 *, s32 *);
extern P_73BC8_80073BC8 *D_800B20B8;
extern struct S_D_800A5D84 { SVECTOR v[4]; } D_800A5D84;
s32 Geo_DiagonalDistance();
s32 Dir_QuadrantIndex(s32 a);
s32 Floor_GetHeight(s32, s32, s32);
extern struct S_D_800F4350 { u8 pad0[0x100]; s32 f_100; u8 pad104[0x4C]; u16 f_150; u8 pad152[0x13E]; s16 f_290; } D_800F4350;
extern s16 D_800B20C4;
extern s16 D_800B20C8;
extern s16 D_800B20CA;
extern s16 D_800B20CC;
extern s16 D_800EBFA0[2];
extern s16 g_SpikeHealth;
s32 CollShape_Free_p(void *) asm("CollShape_Free");
s32 Collision_Remove_p(void *) asm("Collision_Remove");
s32 func_80072DC4_p(void *) asm("Coll_Nop");
s32 Contact_ClearSeen_p(void) asm("Contact_ClearSeen");
s32 Contact_Expire_p(void) asm("Contact_Expire");
s32 func_8007304C_p(s32, void *) asm("Coll_GatherCells");
s32 Coll_ResolveBody(s32, void *);
s32 func_80072DCC_p(void *, s32, s32) asm("Body_FallToFloor");
s32 Collision_UpdateMoveRumble_p(void *) asm("Collision_UpdateMoveRumble");
s32 Coll_ClipColumnHeight_p(void *) asm("Coll_ClipColumnHeight");
s32 Roller_UpdateSound_p(void *) asm("Roller_UpdateSound");
s32 Zone_FindIndexAt_p(void *, s32) asm("Zone_FindIndexAt");
s32 func_80078088_p(s32, void *) asm("func_80078088");
s32 Pickup_CheckTouch_p(s32, void *) asm("Pickup_CheckTouch");
s32 func_80077D18_p(s32, void *) asm("func_80077D18");
s32 func_80077EE8_p(s32, void *) asm("func_80077EE8");
s32 Collider_PushApart_p(void *) asm("Collider_PushApart");
void Spike_TryGrabLedge(void);

s32 Collision_TickCounter(void) {
    D_800B2130 += 1;
    return 0;
}

s32 Collision_Init(void)
{
  s32 i;
  (*(s32 *)&g_CollisionHead) = 0;
  g_CollisionTail = 0;
  for (i = 0; i < 0x100; i++)
  {
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_0 = -1;
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_2 = -1;
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_4 = 0;
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_8 = 0;
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_C = 0;
    ((struct S_D_800BBDA0_80071D3C *)&g_CollisionEntries)[i].f_10 = 0;
  }

  for (i = 0; i < 0x80; i++)
  {
    D_800BEDA0[i] = -1;
    CollShape_Clear(&((struct S_D_800BD1A0_80071D3C *)&D_800BD1A0)[i]);
  }

  for (i = 0; i < 0x10; i++)
  {
    D_800BEEA0[i].f_0 = -1;
    D_800BEEA0[i].f_2 = 0;
    D_800BEEA0[i].f_8 = 0;
    D_800BEEA0[i].f_4 = 0;
  }

  ((struct S_D_800EC350_80071D3C *)&g_Game)->f_8296 = 0;
  ((struct S_D_800EC350_80071D3C *)&g_Game)->f_8298 = 0;
  ((struct S_D_800EC350_80071D3C *)&g_Game)->f_8290 = -1;
  return 0;
}

/* Registers object `a` (with optional owner `b`) as a collision entry of `type`: takes a free
 * entry, sets type-specific flags (type 2 also starts looping sound 0x16) and appends it to the
 * collision list. Prints "Collision_set Error" and returns -1 when all 256 entries are used. */
s32 Collision_Set(s32 type, ObjA_80071E44_80071E44 *a, ObjB_80071E44_80071E44 *b) {
    Node_80071E44_80071E44 *n = Collision_AllocEntry();
    Node_80071E44_80071E44 *p;
    if (n == 0) {
        bios_printf(D_800A5D20, type);
        return -1;
    }
    n->f_0 = type;
    n->f_8 = b;
    n->f_4 = a;
    if ((n->f_0 == 1 || n->f_0 == 3 || n->f_0 == 4 || n->f_0 == 5) && b != 0) {
        n->f_8->f_4C = n->f_2;
    }
    if (n->f_0 == 3) {
        n->f_4->f_26 |= 0x8000;
    }
    if (n->f_0 == 2) {
        if (b != 0) {
            n->f_8->f_4C = n->f_2;
        }
        D_800B20D0.f_0 = Sound_Play(1, 0x16);
        D_800B20D0.f_2 = 1;
    }
    n->f_4->f_2A = 0;
    if ((u16)n->f_0 - 6 < 3U || (u16)n->f_0 - 12 < 6U) {
        n->f_4->f_2A = 1;
    }
    if ((*(Node_80071E44_80071E44 * *)&g_CollisionHead) == 0) {
        (*(Node_80071E44_80071E44 * *)&g_CollisionHead) = n;
        (*(Node_80071E44_80071E44 * *)&g_CollisionTail) = n;
        n->f_C = 0;
        n->f_10 = 0;
    } else {
        p = (*(Node_80071E44_80071E44 * *)&g_CollisionTail);
        (*(Node_80071E44_80071E44 * *)&g_CollisionTail) = n;
        p->f_C = n;
        n->f_C = 0;
        n->f_10 = p;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80071D20_collide", D_800A5D20);


/* Returns the first free collision entry (type < 0), storing its index in it, or NULL. */
S_BBDA0 *Collision_AllocEntry(void) {
    s32 i;
    for (i = 0; i < 256; i++) {
        if (g_CollisionEntries[i].unk0 < 0) {
            g_CollisionEntries[i].unk2 = i;
            return &g_CollisionEntries[i];
        }
    }
    return 0;
}

/* Removes the collision entry whose object is `key` from the list and frees it. */
s32 Collision_Remove(s32 key) {
    S_Node_80072018_80072018 *e = 0;
    S_Node_80072018_80072018 *p;
    s32 i;
    for (i = 0; i < 256; i++) {
        p = &((S_Node_80072018_80072018 *)&g_CollisionEntries)[i];
        if (p->f_4 == key) {
            e = p;
            break;
        }
    }
    if (e == 0) {
        return -1;
    }
    if (e->f_0 == 2) {
        D_800F5A78 = -1;
        if (D_800B20D0.f_2 != 0) {
            Sound_Stop(0x16, D_800B20D0.f_0);
            D_800B20D0.f_2 = 0;
        }
    }
    e->f_0 = -1;
    e->f_2 = -1;
    e->f_8 = 0;
    e->f_4 = 0;
    if (HEAD == e) {
        if (e->f_C == 0) {
            HEAD = 0;
            TAIL = 0;
        } else {
            HEAD = e->f_C;
            e->f_C->f_10 = 0;
        }
    } else {
        if (TAIL == e) {
            TAIL = e->f_10;
        }
        if (e->f_C == 0) {
            e->f_10->f_C = 0;
        } else {
            e->f_10->f_C = e->f_C;
            e->f_C->f_10 = e->f_10;
        }
    }
    e->f_C = 0;
    e->f_10 = 0;
    return 0;
}

s32 Collision_GetShape(s16 a) {
    if ((u16)a > 0x100) {
        return 0;
    }
    return g_CollisionEntries[a].f_4;
}

typedef struct { u8 pad0[0x4C]; s16 link; } CollOwner_721B4;
typedef struct { s16 id; s16 unk2; s32 unk4; CollOwner_721B4 *owner; u8 padC[8]; } CollEnt_721B4;
extern CollEnt_721B4 g_CollEnt_721B4[] asm("g_CollisionEntries");
extern CollEnt_721B4 g_CollEnt2_721B4[] asm("g_CollisionEntries");

/* Collision entry id: follows the entry's owner link (owner+0x4C) when it has one; -2 for an
   out-of-range index. (The second table alias keeps the base address from being CSE'd.) */
s32 Collision_GetId(s32 a) {
    s32 i;
    if (g_CollEnt_721B4[(s16)a].owner != 0) {
        i = g_CollEnt_721B4[(s16)a].owner->link;
    } else i = (s16)a;
    if ((u32)i > 0x100) {
        return -2;
    }
    return g_CollEnt2_721B4[i].id;
}

S_BD1A0 *CollShape_Alloc(void) {
    s32 i;
    for (i = 0; i < 128; i++) {
        if (D_800BEDA0[i] < 0) {
            D_800BEDA0[i] = 1;
            CollShape_Clear(&D_800BD1A0[i]);
            return &D_800BD1A0[i];
        }
    }
    return 0;
}

s32 CollShape_Clear(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x20) = 0;
    M2C_FIELD(arg0, s16 *, 0x22) = 0;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x26) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
    return 0;
}

s32 CollShape_Free(S_BD1A0 *p)
{
  s32 i;
  int new_var;
  for (i = 0; i < 128; i++)
  {
    if ((&D_800BD1A0[i]) == p)
    {
      new_var = -1;
      D_800BEDA0[i] = new_var;
      CollShape_Clear(&D_800BD1A0[i]);
      return 0;
    }
  }

  return -1;
}

/* Contact list D_800BEEA0 (16 entries: kind, frames held, thing, seen this frame) used to fire
   touch events once: adds (kind, thing) as a new contact. */
s32 Contact_Add(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_800BEEA0[i].f_0 < 0) {
            D_800BEEA0[i].f_0 = a;
            D_800BEEA0[i].f_2 = 0;
            D_800BEEA0[i].f_8 = 1;
            D_800BEEA0[i].f_4 = b;
            return 0;
        }
    }
    return -1;
}

/* Returns 1 if (kind, thing) is not in the contact list yet; otherwise marks it seen again and returns 0. */
s32 Contact_IsNew(s16 a, s32 b) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_800BEEA0[i].f_0 >= 0 && a == D_800BEEA0[i].f_0 && b == D_800BEEA0[i].f_4) {
            D_800BEEA0[i].f_8++;
            return 0;
        }
    }
    return 1;
}

/* Drops contacts not seen this frame and counts up the frames held for the rest. */
s32 Contact_Expire(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_800BEEA0[i].f_0 >= 0) {
            if (D_800BEEA0[i].f_8 == 0) {
                D_800BEEA0[i].f_0 = -1;
                D_800BEEA0[i].f_2 = 0;
                D_800BEEA0[i].f_8 = 0;
                D_800BEEA0[i].f_4 = 0;
            } else {
                D_800BEEA0[i].f_2++;
            }
        }
    }
    return 0;
}

/* Clears the seen-this-frame mark of every contact. */
s32 Contact_ClearSeen(void) {
    s32 i;

    for (i = 15; i >= 0; i--) {
        D_800BEEA0[i].f_8 = 0;
    }
    return -1;
}

extern struct S_Sp_8007247C { u8 pad0[0x24]; s32 x, y, z, vx, vy, vz; u8 pad3C[0x22]; u16 f_5E; } g_Spike_7247C asm("g_Spike");
extern struct { u8 pad0[0x820C]; Ent_8007247C_8007247C *f_820C; u8 pad8210[0x74]; s16 f_8284; u8 pad8286[0xA]; s16 f_8290; } g_Game_7247C asm("g_Game");
/* Per-frame collision pass over the collider list g_CollisionHead. While Spike is in state 0x2D
 * he just moves by his velocity. Otherwise: resets the stage objects' contact slots, frees expired
 * temporary shapes (kinds 6-8 and 0xC-0x11 whose +0x2A timer ran out), then runs each collider's
 * handler by kind (1: Spike, with move rumble, column clip, ground, ledge grab and zone lookup; 2: a
 * roller; 3-5: Collider_PushApart; 6-8, 0xC-0xF: hit shapes; 9: pickup touch; 0x10, 0x11) and keeps
 * every collider inside the stage bounds D_800EBFA0. */
s32 Collision_UpdateAll(void) {
    CNode_8007247C_8007247C *c;
    CNode_8007247C_8007247C *next;
    Body_8007247C_8007247C *o;
    s32 i;
    s32 k;
    s32 lim;
    s32 lim2;
    s32 x;
    s32 t;

    if (g_Spike_7247C.f_5E == 0x2D) {
        g_Spike_7247C.x += g_Spike_7247C.vx;
        g_Spike_7247C.y += g_Spike_7247C.vy;
        g_Spike_7247C.z += g_Spike_7247C.vz;
        return 0;
    }
    c = (*(CNode_8007247C_8007247C * *)&g_CollisionHead);
    D_800B20C4 = 0;
    g_Game_7247C.f_8290 = -1;
    for (i = g_Game_7247C.f_8284 - 1; i >= 0; i--) {
        g_Game_7247C.f_820C[i].f_1E = -1;
    }
    Contact_ClearSeen_p();
    for (; c != 0; c = next) {
        o = c->o;
        k = c->kind;
        next = c->next;
        if (k >= 6) {
            if (k < 9) {
                if (o->f_2A == 0) {
                    CollShape_Free_p(o);
                    Collision_Remove_p(o);
                }
            } else if (k < 0x12) {
                if (k >= 0xC) {
                    if (o->f_2A == 0) {
                        CollShape_Free_p(o);
                        Collision_Remove_p(o);
                    }
                }
            }
        }
        o->f_2C = 0;
    }
    for (c = (*(CNode_8007247C_8007247C * *)&g_CollisionHead); c != 0; c = next) {
        o = c->o;
        next = c->next;
        D_800B20CC = c->kind;
        switch (c->kind) {
        case 1:
            *(*(Body_8007247C_8007247C * *)&D_800B20B8) = *o;
            D_800B20C8 = D_800B20CA = -1;
            if (D_800F4350.f_150 == 2) {
                func_8007304C_p(1, o);
                break;
            }
            if (D_800F4350.f_150 == 6) {
                D_800B20C8 = o->f_34;
            } else if (D_800F4350.f_150 == 5) {
                D_800B20CA = o->f_34;
                o->f_14 = 0;
                o->f_C = 0;
            }
            o->f_34 = -1;
            Collision_UpdateMoveRumble_p(o);
            Coll_ClipColumnHeight_p(o);
            func_80072DC4_p(o);
            func_8007304C_p(1, o);
            func_80072DCC_p(o, c->kind, Coll_ResolveBody(c->kind, o));
            Spike_TryGrabLedge();
            Zone_FindIndexAt_p(o, 1);
            break;
        case 2:
            *(*(Body_8007247C_8007247C * *)&D_800B20B8) = *o;
            o->f_34 = -1;
            Roller_UpdateSound_p(o);
            Coll_ClipColumnHeight_p(o);
            func_80072DC4_p(o);
            func_8007304C_p(2, o);
            func_80072DCC_p(o, c->kind, Coll_ResolveBody(c->kind, o));
            Zone_FindIndexAt_p(o, 2);
            break;
        case 3:
        case 4:
        case 5:
            Collider_PushApart_p(c);
            break;
        case 6:
        case 7:
        case 12:
        case 13:
            func_8007304C_p(c->kind, o);
        case 8:
        case 14:
        case 15:
            func_80078088_p(c->kind, c);
            o->f_2A--;
            break;
        case 9:
            if (D_800F4350.f_100 == 0 && g_SpikeHealth > 0) {
                Pickup_CheckTouch_p(c->kind, c);
            }
            break;
        case 16:
            func_80077D18_p(c->kind, c);
            o->f_2A--;
            break;
        case 17:
            func_80077EE8_p(c->kind, c);
            o->f_2A--;
            break;
        }
        t = o->x;
        lim2 = (D_800EBFA0[0] - 1) << 8;
        x = -lim2;
        if (t >= x) {
            x = lim2;
            if (t <= lim2) {
                x = t;
            }
        }
        o->x = x;
        t = o->z;
        lim = (D_800EBFA0[1] - 1) << 8;
        x = -lim;
        if (t >= x) {
            x = lim;
            if (t <= lim) {
                x = t;
            }
        }
        o->z = x;
    }
    Contact_Expire_p();
    D_800B2130 = 0;
    return 0;
}



s32 Pause_MuteSounds(void) {
    if (D_800B20D0.f_2 != 0) {
        Sound_Stop(0x16, D_800B20D0.f_0);
        D_800B20D0.f_2 = 0;
    }
    if (D_800B20D4.f_2 != 0) {
        Sound_Stop(0xAD, D_800B20D4.f_0);
        D_800B20D4.f_2 = 0;
    }
    if (g_Game.f_8124 == 0x1B) {
        func_8013FB20(0);
    }
    Sound_PauseVolumes(0);
    return 0;
}

s32 Pause_RestoreSounds(void) {
    if (g_Game.f_8124 == 0x1B) {
        func_8013FB20(1);
    }
    Sound_PauseVolumes(1);
    return 0;
}

/* Sound for a rolling object (the type-2 collision entry, whose Collision_Set starts the same loop):
 * while |vx| + |vz| >= 3 keeps looping sound 0x16 at its position and raises or lowers its
 * pitch (D_800B2134, kept within 0..0x1FFF) by the change in vx^2 + vz^2; when it nearly stops,
 * ends the loop and plays 0x17 there, resetting the pitch to 0xD00. */
s32 Roller_UpdateSound(Roll_80072A14_80072A14 *o) {
    SVECTOR pos;
    s32 e;
    s16 p;
    if ((s16)(abs(o->vx) + abs(o->vz)) < 3) {
        if (((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->on != 0) {
            Sound_Stop(0x16, ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->voice);
            pos.vx = o->x;
            pos.vy = o->y;
            pos.vz = o->z;
            Sound_PlayAt(0x17, &pos);
            D_800B2134 = 0xD00;
            ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->on = 0;
            D_800B2138 = 0;
        }
        return 0;
    }
    if (((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->on == 0) {
        ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->voice = Sound_Play(1, 0x16);
        ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->on = 1;
    }
    pos.vx = o->x;
    pos.vy = o->y;
    pos.vz = o->z;
    Sound_UpdateVoice3D(0x16, ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->voice, 0x1000, &pos);
    e = o->vx * o->vx + o->vz * o->vz;
    p = D_800B2134 + (e - D_800B2138);
    if (p >= 0x2000) {
        p = 0x1FFF;
    }
    if (p < 0) {
        p = 0;
    }
    if (D_800B2134 != p) {
        Sound_SetVoicePitch(0x16, ((struct S_D_800B20D0_80072A14 *)&D_800B20D0)->voice, p);
    }
    D_800B2134 = p;
    D_800B2138 = (s16)e;
    return 0;
}

s32 Collision_UpdateMoveRumble(S_80072BE8_80072BE8 *a) {
    if (((struct S_D_800EC350_80072BE8 *)&g_Game)->f_8150 == 1) {
        if (D_800B213E == 0) {
            D_800B213C = 0x6E;
            D_800B213E = 2;
        } else {
            D_800B213C = 0;
            D_800B213E = D_800B213E - 1;
        }
        if (a->f_C != 0 || a->f_14 != 0 || (D_800E53C0 & 0xFF00FF00)) {
            goto play;
        }
    }
    if (D_800B20D4.f_2 != 0) {
        Sound_Stop(0xAD, D_800B20D4.f_0);
        D_800B20D4.f_2 = 0;
    }
    D_800B213E = 0;
    D_800B213C = 0;
    return 0;
play:
    if (D_800B20D4.f_2 == 0) {
        D_800B20D4.f_0 = Sound_Play(0, 0xAD);
        D_800B20D4.f_2 = 1;
    }
    if (D_800B213C > 0) {
        Pad_Vibrate(1, D_800B213C, D_800B213E);
    }
    return 0;
}

/* Steps along a column s (base x/y/z +0/+4/+8, offset +0xC/+0x14, length +0x10) by 0x20 in y and
 * cuts its length at the first step d where Floor_GetHeight (floor height) is below y + d. */
s32 Coll_ClipColumnHeight(S_72D28_80072D28 *s) {
    s32 d;
    if (s->f_10 < 0x20) {
        return 0;
    }
    d = 0x20;
loop:
    if (s->f_10 - d < 0) {
        return 0;
    }
    if (Floor_GetHeight(s->f_0 + s->f_C, s->f_4 + d, s->f_8 + s->f_14) < s->f_4 + d) {
        s->f_10 = d;
        return 0;
    }
    d += 0x20;
    goto loop;
}

s32 Coll_Nop(void) {
    return 0;
}

typedef struct { s32 x, y, z, f_C, vy, f_14; u8 pad18[0xA]; s16 h; u8 pad24[8]; s32 f_2C; } Act_80072DCC;
typedef struct { u8 pad0[0xC]; s32 ground; } ScrA_80072DCC;
typedef struct { s16 f_0; u16 pad2; u16 f_4; } ScrB_80072DCC;
struct Game_80072DCC { s32 frame; u8 pad4[0x8120]; u16 f_8124; u16 stage; u8 pad8128[0x170]; s16 f_8298; };
struct Spike_80072DCC { u8 pad0[0x5E]; u16 state; u8 pad60[0x10]; s32 f_70; };
struct Rc_80072DCC { u8 pad0[0x24]; s32 x, y, z; };
extern M2C_UNK g_RcCar;
void Spike_TakeDamage(s32);
void Spike_SetState(s32);
void Cd_PlayXaTrack(s32);
void RcCar_Remove(void);
void Effect_SpawnAt(s32, SVECTOR *);
#define GM_72DCC ((struct Game_80072DCC *)&g_Game)

s32 Body_FallToFloor(Act_80072DCC *o, s32 who, s32 g) {
    ScrB_80072DCC *sb = (ScrB_80072DCC *)0x1F8003F0;
    ScrA_80072DCC *sa = (ScrA_80072DCC *)0x1F8000F0;
    Act_80072DCC *r;
    s32 ground;
    s32 k;
    SVECTOR p;
    GM_72DCC->f_8298 = 1;
    ground = Floor_GetHeight(o->x, o->y + o->vy - o->h / 2, o->z);
    sa->ground = ground;
    if (ground < o->y + o->vy) {
        o->vy = ground - o->y;
        o->y = sa->ground;
    } else {
        o->y = o->y + (o->vy + g);
    }
    r = (Act_80072DCC *)D_800B20B8;
    if (o->y - r->y < -0xFF) {
        o->x = r->x;
        o->y = r->y;
        o->z = r->z;
        o->f_14 = 0;
        o->f_C = 0;
        o->vy = r->vy;
        if (who == 1) {
            k = 0;
            if (sb->f_0 == who) {
                k = sb->f_4 & 0xFF;
            }
            if (o->f_2C != 0 && (((struct Spike_80072DCC *)&g_Spike)->f_70 & 0xF0) != 0xE0 &&
                ((struct Spike_80072DCC *)&g_Spike)->state != 0x23 && ((struct Spike_80072DCC *)&g_Spike)->state != 0x4A &&
                ((struct Spike_80072DCC *)&g_Spike)->state != 0x2D && (u16)k != 0x24) {
                if ((u16)k != 0x25 && GM_72DCC->stage != 0x44) {
                    if (GM_72DCC->f_8124 != 0x20) {
                        Spike_TakeDamage(5);
                    } else {
                        Spike_SetState(0x22);
                        if (GM_72DCC->frame & 1) {
                            Cd_PlayXaTrack(0xD);
                        } else {
                            Cd_PlayXaTrack(0xF);
                        }
                    }
                }
            }
        } else if (who == 2) {
            RcCar_Remove();
            Sound_PlayFixed(0x79);
            p.vx = ((struct Rc_80072DCC *)&g_RcCar)->x;
            p.vy = ((struct Rc_80072DCC *)&g_RcCar)->y;
            p.vz = ((struct Rc_80072DCC *)&g_RcCar)->z;
            Effect_SpawnAt(0x102, &p);
        }
    }
    return 0;
}

typedef struct { s16 x, y, z, f_6, f_8, f_A; s16 *f_C; } Probe_7304C;
typedef struct { s32 vx, vy, vz, pad, f_10; } Pos_7304C;
typedef struct { u8 pad0[0x12]; u16 f_12; u8 pad14[4]; u16 f_18; u8 pad1A[0x18]; s16 f_32; u8 pad34[4]; } Obj_7304C;
typedef struct { u8 pad0[0x820C]; Obj_7304C *f_820C; u8 pad8210[0x74]; u16 f_8284; u8 pad8286[0x22]; s32 f_82A8; s32 f_82AC; } Game_7304C;
typedef struct { u8 pad0[0x2A8]; u16 f_2A8; u8 pad2AA[2]; u16 f_2AC; } G8_7304C;
extern Game_7304C g_Game_7304C asm("g_Game");
extern G8_7304C D_800F4350_7304C asm("D_800F4350");
extern Probe_7304C *D_800B20B0_7304C asm("Coll_Cells");
extern u8 *Coll_NearObjects;
s16 *Coll_FindCell(Probe_7304C *);

s32 Coll_GatherCells(s32 mode, Pos_7304C *pos) {
    Probe_7304C *t;
    s16 *r;
    s16 i;
    s32 x;
    s32 q;
    u16 y;

    D_800B20B0_7304C->x = pos->vx;
    { u16 y0 = pos->vy;
    D_800B20B0_7304C->y = y0;
    i = 1;
    if (pos->f_10 > 0) {
        D_800B20B0_7304C->y = y0 + pos->f_10;
    }}
    D_800B20B0_7304C->z = pos->vz;
    t = D_800B20B0_7304C;
    for (; i < 8; i++) {
        Probe_7304C *e;
        e = (Probe_7304C *)((i << 4) + (s32)t);
        e->x = t->x;
        y = t->y;
        e->y = y;
        if (i >= 4) {
            e->y = y - 0x200;
        }
        e->z = t->z;
    }
    x = ((((pos->vx + g_Game_7304C.f_82A8) % 0x200 - 0x100) >> 31) & 2);
    q = (pos->vz + g_Game_7304C.f_82AC) % 0x200 - 0x100;
    q = (u32)q >> 31;
    q |= x;
    switch (q) {
    case 0:
        Probe_ShiftCorners(0x200, 0x200);
        break;
    case 1:
        Probe_ShiftCorners(0x200, -0x200);
        break;
    case 2:
        Probe_ShiftCorners(-0x200, 0x200);
        break;
    case 3:
        Probe_ShiftCorners(-0x200, -0x200);
        break;
    }
    for (i = 7; i >= 0; i--) {
        r = Coll_FindCell(&D_800B20B0_7304C[i]);
        {
        Probe_7304C *e;
        e = (Probe_7304C *)((i << 4) + (s32)D_800B20B0_7304C);
        e->f_C = r;
        if (r != 0) {
            e->f_6 = r[3];
            e->f_8 = r[4];
            e->f_A = r[5];
            { s32 a = r[0]; a = (a << 9) - D_800F4350_7304C.f_2A8 + 0x100; e->x = a; }
            { s32 a = r[1]; a = -(a << 9); e->y = a; }
            { s32 a = r[2]; a = (a << 9) - D_800F4350_7304C.f_2AC + 0x100; e->z = a; }
        }
        }
    }
    for (i = g_Game_7304C.f_8284 - 1; i >= 0; i--) {
        Obj_7304C *o;
        Coll_NearObjects[i] = 0;
        o = (Obj_7304C *)(i * 56 + (s32)g_Game_7304C.f_820C);
        if (o->f_18 & 0x8000) {
            Coll_NearObjects[i] = 1;
            continue;
        }
        { u16 k = o->f_12;
        if (k == 0xE) {
            continue;
        }
        if ((s16)mode == 1 && k == (s16)mode) {
            o->f_32 = -1;
        }
        if (Box_NearPoint((s16 *)&g_Game_7304C.f_820C[i], (s32 *)pos) != 0) {
            Coll_NearObjects[i] = 1;
        }}
    }
    return 0;
}

s32 Probe_ShiftCorners(s32 arg0, s32 arg1) {
    M2C_FIELD(Coll_Cells, u16 *, 0x14) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x14) + arg1);
    M2C_FIELD(Coll_Cells, u16 *, 0x24) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x24) + arg1);
    M2C_FIELD(Coll_Cells, u16 *, 0x20) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x20) + arg0);
    M2C_FIELD(Coll_Cells, u16 *, 0x30) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x30) + arg0);
    M2C_FIELD(Coll_Cells, u16 *, 0x44) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x44) + arg1);
    M2C_FIELD(Coll_Cells, u16 *, 0x54) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x54) + arg1);
    M2C_FIELD(Coll_Cells, u16 *, 0x50) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x50) + arg0);
    M2C_FIELD(Coll_Cells, u16 *, 0x60) = (u16) (M2C_FIELD(Coll_Cells, u16 *, 0x60) + arg0);
    return 0;
}

typedef struct { s32 x, y, z, vx, vy, vz; u8 pad18[8]; s16 f_20; s16 f_22; u8 pad24[4]; u16 f_28; u8 pad2A[2]; s32 f_2C; } Act_73450;
typedef struct { s16 x, y, z, w, h, d; u8 padC[2]; s16 f_E; u16 f_10; u16 f_12; u8 pad14[2]; u16 f_16; u8 pad18[0x1A]; u16 f_32; u8 pad34[4]; } Obj_73450;
typedef struct { u8 pad0[0x12]; u16 f_12; } Cell_73450;
typedef struct { u8 pad0[0xC]; Cell_73450 *f_C; } Hit_73450;
typedef struct { s32 x, y, z; } P_73450;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } Rc_73450;
typedef struct { u8 pad0[0x820C]; Obj_73450 *f_820C; u8 pad8210[0x74]; u16 f_8284; } Game_73450;
extern Game_73450 g_Game_73450 asm("g_Game");
extern Rc_73450 g_RcCar_73450 asm("g_RcCar");
extern Hit_73450 *D_800B20B0_73450 asm("Coll_Cells");
extern P_73450 *D_800B20B4_73450 asm("Coll_Pos");
extern s16 D_800B20C6;
extern s32 (*D_800B20E0[])(void *, s32 *, s32 *);
extern s32 (*D_800B2108[])(void *, s32 *, s32 *);
s32 Coll_HeightRangeHit(s16, s16, s16, s16);
void Effect_SpawnAt_73450(s32, s16 *) asm("Effect_SpawnAt");

s32 Coll_ResolveBody(s32 mode, void *a) {
    s32 *box = (s32 *)0x1F8000F0;
    s32 *res = (s32 *)0x1F800100;
    s32 *acc;
    s32 flags;
    s16 i;
    s32 best = 0;
    Obj_73450 *o;
    s16 sv[3];
    s32 k;
    s32 z = 0;
    __asm__("" : "=r"(res) : "0"(res));
    acc = (s32 *)0x1F800118;
    flags = 0;
    i = 0;

    acc[0] = 0;
    ((Act_73450 *)a)->x += ((Act_73450 *)a)->vx;
    ((Act_73450 *)a)->z += ((Act_73450 *)a)->vz;
    acc[2] = 0;
    acc[1] = 0;
    D_800B20C6 = -999;
    box[0] = ((Act_73450 *)a)->f_20;
    box[2] = ((Act_73450 *)a)->f_22;
    for (; i < 8; i++) {
        if (D_800B20B0_73450[i].f_C == 0) {
            continue;
        }
        *(s32 *)D_800B20B4_73450 = ((Act_73450 *)a)->x + acc[0];
        D_800B20B4_73450->y = ((Act_73450 *)a)->y + ((Act_73450 *)a)->vy + acc[1];
        D_800B20B4_73450->z = ((Act_73450 *)a)->z + acc[2];
        box[1] = (s16)D_800B20B0_73450[i].f_C->f_12;
        k = D_800B20B0_73450[i].f_C->f_12 & 0xF000;
        res[0] = 0;
        res[5] = 0;
        res[4] = 0;
        res[3] = 0;
        res[2] = 0;
        res[1] = 0;
        if (D_800B20E0[k >> 12](&D_800B20B0_73450[i], box, res) == 0) {
            continue;
        }
        if (i != 7 || (((Act_73450 *)a)->vy += res[3], res[3] == 0)) {
            acc[2] += res[2];
            acc[0] += res[0];
            flags = ((Obj_73450 *)D_800B20B0_73450[i].f_C)->f_E | 0xA0000000;
        } else if (best < res[3]) {
            best = res[3];
        }
    }
    for (i = g_Game_73450.f_8284 - 1; i >= 0; i--) {
        D_800B20C6 = i;
        if (Coll_NearObjects[i] != 0) {
            continue;
        }
        D_800B20C4++;
        *(s32 *)D_800B20B4_73450 = ((Act_73450 *)a)->x + acc[0];
        D_800B20B4_73450->y = ((Act_73450 *)a)->y + ((Act_73450 *)a)->vy + acc[1];
        D_800B20B4_73450->z = ((Act_73450 *)a)->z + acc[2];
        box[1] = g_Game_73450.f_820C[i].f_10;
        k = g_Game_73450.f_820C[i].f_10 & 0xF000;
        res[0] = 0;
        res[5] = 0;
        res[4] = 0;
        res[3] = 0;
        res[2] = 0;
        res[1] = 0;
        if (D_800B2108[k >> 12](&g_Game_73450.f_820C[i], box, res) == 0) {
            continue;
        }
        if (res[3] > z && Coll_HeightRangeHit(*(s16 *)&D_800B20B4_73450->y, ((Act_73450 *)a)->f_22, g_Game_73450.f_820C[i].y + res[4], g_Game_73450.f_820C[i].h + res[5])) {
            ((Act_73450 *)a)->vy += res[3];
        } else {
            acc[0] += res[0];
            acc[2] += res[2];
        }
        o = (Obj_73450 *)(i * sizeof(Obj_73450) + (s32)g_Game_73450.f_820C);
        flags = o->f_16 | 0xA0000000;
        if ((o->f_12 & 0xFF) == 1) {
            flags |= 0x8000000;
        }
        if (o->f_12 == 1) {
            o->f_32 = ((Act_73450 *)a)->f_28;
            ((Act_73450 *)a)->f_2C = flags | 0xA0000000;
        }
    }
    ((Act_73450 *)a)->x += acc[0];
    ((Act_73450 *)a)->z += acc[2];
    if (acc[0] != 0 || acc[2] != 0 || flags != 0) {
        if (mode == 2 && (abs(acc[0]) > 0x60 || abs(acc[2]) > 0x60)) {
            acc[2] = 0;
            acc[0] = 0;
            RcCar_Remove();
            Sound_PlayFixed(0x79);
            sv[0] = g_RcCar_73450.x;
            sv[1] = g_RcCar_73450.y;
            sv[2] = g_RcCar_73450.z;
            Effect_SpawnAt_73450(0x102, sv);
        }
        ((Act_73450 *)a)->f_2C = flags;
        if (acc[0] != 0) {
            ((Act_73450 *)a)->vx += acc[0];
        }
        if (acc[2] != 0) {
            ((Act_73450 *)a)->vz += acc[2];
        }
    }
    if (best < z) {
        return z;
    }
    return best;
}

/* Vertical overlap test of a body (top a, height b) against a solid (top c, height d). */
s32 Coll_HeightRangeHit(s16 a, s16 b, s16 c, s16 d) {
    if (a - b < c && c - d < a - b) {
        if (c - d < a) {
            return 1;
        }
        goto miss;
    }
    if (a - b < c - d && c < a) {
        return 1;
    }
    miss:
    return 0;
}

s32 Box_NearPoint(s16 *arg0, s32 *arg1) {
    if (ABS(arg0[0] - arg1[0]) < arg0[3] + 0x200) {
        if (ABS(arg0[1] - arg1[1]) < arg0[4] + 0x200) {
            if (ABS(arg0[2] - arg1[2]) < arg0[5] + 0x200) {
                return 0;
            }
        }
    }
    return -1;
}

/* 1 if point p lies inside box o's x/z footprint (centre +0/+4, half sizes +6/+0xA). */
s32 Box_ContainsXZ(P_73B64_80073B64 *p, O_73B64_80073B64 *o) {
    if (o->x + o->w < p->x) {
        goto miss;
    }
    if (p->x < o->x - o->w) {
        goto miss;
    }
    if (o->z + o->d < p->z) {
        goto miss;
    }
    if (p->z < o->z - o->d) {
        goto miss;
    }
    return 1;
miss:
    return 0;
}

/* Push Spike (Coll_Pos) out of a solid box o (x/z half sizes +6/+0xA, height +8 below its top
 * +2) using box b (radius b+0, height b+8); kinds 0x3C..0x3F (b+4) first shift the box by one
 * half size towards -z/-x/+z/+x. The face is chosen by the quadrant (diagonals) he is in, or by
 * corner region outside both extents; out[0] or out[2] gets the correction, and out[3] the
 * step up onto its top when he is above it within both boxes (Box_ContainsXZ). */
s32 Coll_PushBox(O_73BC8_80073BC8 *o, B_73BC8_80073BC8 *b, s32 *out) {
    s16 ex;
    s16 ez;
    s32 dx;
    s32 dz;
    s16 side;
    s32 t;

    switch (b->kind) {
    case 0x3C:
        o->z -= o->d;
        break;
    case 0x3D:
        o->x -= o->w;
        break;
    case 0x3E:
        o->z += o->d;
        break;
    case 0x3F:
        o->x += o->w;
        break;
    }
    if (o->w == 0) {
        o->w = 1;
    }
    ex = o->w + b->r;
    ez = o->d + b->r;
    if (o->x + ex < (*(P_73BC8_80073BC8 * *)&Coll_Pos)->x) {
        goto miss;
    }
    if ((*(P_73BC8_80073BC8 * *)&Coll_Pos)->x < o->x - ex) {
        return 0;
    }
    if (o->z + ez < (*(P_73BC8_80073BC8 * *)&Coll_Pos)->z) {
        return 0;
    }
    if ((*(P_73BC8_80073BC8 * *)&Coll_Pos)->z < o->z - ez) {
        return 0;
    }
    if (Coll_HeightOverlap((*(P_73BC8_80073BC8 * *)&Coll_Pos)->y, b->h, o->y, o->h) == 0) {
        return 0;
    }
    dx = (*(P_73BC8_80073BC8 * *)&Coll_Pos)->x - o->x;
    dz = (*(P_73BC8_80073BC8 * *)&Coll_Pos)->z - o->z;
    if (o->w < ABS(dx) && o->d < ABS(dz)) {
        dx = o->w < dx ? dx - o->w : dx + o->w;
        dz = o->d < dz ? dz - o->d : dz + o->d;
        side = (dx < dz) << 1;
        side |= -dx < dz;
    } else {
        side = ((dx * o->d / o->w < dz) << 1) | (dx * -o->d / o->w < dz);
    }
    if (side == 0 || side == 3) {
        t = o->z - (*(P_73BC8_80073BC8 * *)&Coll_Pos)->z;
        out[2] = t;
        out[2] = (*(P_73BC8_80073BC8 * *)&Coll_Pos)->z < o->z ? t - ez : t + ez;
    } else if (side == 1 || side == 2) {
        t = o->x - (*(P_73BC8_80073BC8 * *)&Coll_Pos)->x;
        out[0] = t;
        out[0] = (*(P_73BC8_80073BC8 * *)&Coll_Pos)->x < o->x ? t - ex : t + ex;
    }
    if ((*(P_73BC8_80073BC8 * *)&Coll_Pos)->y - b->h < o->y && o->y - o->h < (*(P_73BC8_80073BC8 * *)&Coll_Pos)->y) {
        if (Box_ContainsXZ((P_73B64_80073B64 *)Coll_Pos, (O_73B64_80073B64 *)o) && Box_ContainsXZ((P_73B64_80073B64 *)D_800B20B8, (O_73B64_80073B64 *)o)) {
            out[3] = o->y - ((*(P_73BC8_80073BC8 * *)&Coll_Pos)->y - b->h);
        }
    }
    return 1;
miss:
    return 0;
}

typedef struct { s16 x, y, z, w, h, d; } O_73FD4;
typedef struct { s32 x, y, z; } P_73FD4;
typedef struct { u16 r; u8 pad2[2]; s32 flags; s32 h; } B_73FD4;
extern P_73FD4 *D_800B20B4_73FD4 asm("Coll_Pos");
extern P_73FD4 *D_800B20B8_73FD4 asm("D_800B20B8");
s32 func_8004F884_73FD4(s32, O_73FD4 *, P_73FD4 *, s32 *) asm("Surface_QueryShape");
s32 Box_ContainsXZ_73FD4(P_73FD4 *, O_73FD4 *) asm("Box_ContainsXZ");

s32 func_80073FD4(O_73FD4 *o, B_73FD4 *b, s32 *out) {
    s32 *top = (s32 *)0x1F800124;
    P_73FD4 *q = (P_73FD4 *)0x1F800134;
    s32 fl;
    s16 ex = o->w + b->r;
    s16 ez = o->d + b->r;
    s16 i;
    s32 dx;
    s32 dz;
    s16 side;
    s32 t;
    s32 y;
    P_73FD4 *p;
    s32 hit;
    s32 *zp;

    fl = b->flags;
    zp = &D_800B20B4_73FD4->z;
    if (o->x + ex < D_800B20B4_73FD4->x) {
        goto miss;
    }
    if (D_800B20B4_73FD4->x < o->x - ex) {
        return 0;
    }
    if (o->z + ez < D_800B20B4_73FD4->z) {
        return 0;
    }
    if (*zp < o->z - ez) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        ((s32 *)q)[i] = ((s32 *)D_800B20B4_73FD4)[i];
    }
    if (D_800B20B4_73FD4->x >= o->x + o->w) {
        q->x = o->x + o->w - 1;
    } else if (!(o->x - o->w < D_800B20B4_73FD4->x)) {
        q->x = o->x - o->w + 1;
    }
    if (D_800B20B4_73FD4->z >= o->z + o->d) {
        q->z = o->z + o->d - 1;
    } else if (!(o->z - o->d < D_800B20B4_73FD4->z)) {
        q->z = o->z - o->d + 1;
    }
    if (func_8004F884_73FD4(fl & 0xFF, o, q, top) == 0) {
        goto miss;
    }
    if (Coll_HeightOverlap(D_800B20B4_73FD4->y, b->h, top[0], top[1]) == 0) {
        return 0;
    }
__asm__("" : : "r"(b));    dx = D_800B20B4_73FD4->x - o->x;
    dz = D_800B20B4_73FD4->z - o->z;
    side = ((dx * o->d / o->w < dz) << 1) | (dx * -o->d / o->w < dz);
    if (side == 0 || side == 3) {
        t = o->z - D_800B20B4_73FD4->z;
        out[2] = t;
        out[2] = D_800B20B4_73FD4->z < o->z ? t - ez : t + ez;
    } else if (side == 1 || side == 2) {
        out[0] = o->x - D_800B20B4_73FD4->x;
        out[0] = D_800B20B4_73FD4->x < o->x ? out[0] - ex : out[0] + ex;
    }
    if ((u32)((fl & 0xFF) - 0x40) < 4) {
        p = D_800B20B4_73FD4;
        if (p->y - b->h < top[0] && top[0] - top[1] < p->y) {
            if (Box_ContainsXZ_73FD4(p, o) && Box_ContainsXZ_73FD4(D_800B20B8_73FD4, o)) {
                out[3] = top[0] - (D_800B20B4_73FD4->y - b->h);
            }
        }
    } else {
        p = D_800B20B4_73FD4;
        if (p->y - b->h < top[0] && top[0] - top[1] < p->y - b->h && top[0] < p->y) {
            if (Box_ContainsXZ_73FD4(p, o) && Box_ContainsXZ_73FD4(D_800B20B8_73FD4, o)) {
                out[3] = top[0] - (D_800B20B4_73FD4->y - b->h);
            }
        }
    }
skip:

    if ((u32)((fl & 0xFF) - 7) < 4) {
        y = top[0];
    } else {
        y = top[0] - top[1];
    }
    if (D_800B20B4_73FD4->y - 0x60 < y) {
        if ((u32)((fl & 0xFF) - 0x40) < 4) {
            return 0;
        }
        if ((fl & 0xF00) == 0x800) {
            if (side == 3) {
                return 0;
            }
        } else if ((fl & 0xF00) == 0xC00) {
            if (side == 2) {
                return 0;
            }
        } else if ((fl & 0xF00) == 0x400) {
            if (side == 1) {
                return 0;
            }
        } else if (side == 0) {
            return 0;
        }
    }
    return 1;
miss:
    return 0;
}

/* Push Spike (Coll_Pos) out of a wedge: box o (x/z half sizes +6/+0xA, height +8 below +2) cut
 * along a 45-degree diagonal (b[1] & 0xF00, see Geo_DiagonalDistance). On the square faces he is
 * pushed out along x or z like Coll_PushBox; on the diagonal face he is pushed back along the
 * perpendicular (signs from D_800A5D84), and out[3] gets the step up onto it from below. */
s32 Coll_PushWedge(O_7449C_8007449C *o, B_7449C_8007449C *b, s32 *out) {
    struct S_D_800A5D84 tbl = D_800A5D84;
    P_7449C_8007449C *q = (P_7449C_8007449C *)0x1F800124;
    s16 ex;
    s16 ez;
    s32 d;
    s32 ax;
    s32 az;
    s16 k;
    s16 side;
    s32 dx;
    s32 dz;
    s32 sx;
    s32 sz;
    s32 t;

    ex = o->w + b->r;
    ez = o->d + b->r;
    if (o->x + ex < (*(P_7449C_8007449C * *)&Coll_Pos)->x) {
        goto miss;
    }
    if ((*(P_7449C_8007449C * *)&Coll_Pos)->x < o->x - ex) {
        return 0;
    }
    if (o->z + ez < (*(P_7449C_8007449C * *)&Coll_Pos)->z) {
        return 0;
    }
    if ((*(P_7449C_8007449C * *)&Coll_Pos)->z < o->z - ez) {
        return 0;
    }
    if (Coll_HeightOverlap((*(P_7449C_8007449C * *)&Coll_Pos)->y, b->h, o->y, o->h) == 0) {
        goto miss;
    }
    d = Geo_DiagonalDistance(b->flags, (*(P_7449C_8007449C * *)&Coll_Pos), o, q);
    if (b->r + 0x20 < d) {
        return 0;
    }
    if (o->w + o->d < ABS(q->x - o->x) + ABS(q->z - o->z)) {
        return 0;
    }
    k = Dir_QuadrantIndex(b->flags);
    dx = (*(P_7449C_8007449C * *)&Coll_Pos)->x - o->x;
    dz = (*(P_7449C_8007449C * *)&Coll_Pos)->z - o->z;
    side = ((dx * o->d / o->w < dz) << 1) | (dx * -o->d / o->w < dz);
    switch (k) {
    case 0:
        if (side == 0 || side == 2) {
            side = 4;
        }
        break;
    case 1:
        if (side == 2 || side == 3) {
            side = 4;
        }
        break;
    case 2:
        if (side == 1 || side == 3) {
            side = 4;
        }
        break;
    case 3:
        if (side == 0 || side == 1) {
            side = 4;
        }
        break;
    }
    if (d == 0) {
        side = 4;
    }
    if (side == 0 || side == 3) {
        t = o->z - (*(P_7449C_8007449C * *)&Coll_Pos)->z;
        out[2] = t;
        out[2] = (*(P_7449C_8007449C * *)&Coll_Pos)->z < o->z ? t - ez : t + ez;
    } else if (side == 1 || side == 2) {
        t = o->x - (*(P_7449C_8007449C * *)&Coll_Pos)->x;
        out[0] = t;
        out[0] = (*(P_7449C_8007449C * *)&Coll_Pos)->x < o->x ? t - ex : t + ex;
    } else {
        sx = tbl.v[k].vx / 2048;
        sz = tbl.v[k].vz / 2048;
        ax = ABS(q->x - (*(P_7449C_8007449C * *)&Coll_Pos)->x);
        az = ABS(q->z - (*(P_7449C_8007449C * *)&Coll_Pos)->z);
        if (d > 0) {
            out[0] = sx * (ax * (b->r + 0x20) / d - ax);
            out[2] = sz * (az * (b->r + 0x20) / d - az);
        } else if (d == 0) {
            out[0] = sx * b->r * 71 / 100;
            out[2] = sz * b->h * 71 / 100;
        } else {
            out[0] = sx * (ax * (b->r + 0x20) / d + ax);
            out[2] = sz * (az * (b->r + 0x20) / d + az);
        }
    }
    if ((*(P_7449C_8007449C * *)&Coll_Pos)->y - b->h < o->y && o->y - o->h < (*(P_7449C_8007449C * *)&Coll_Pos)->y) {
        if (Box_ContainsXZ((void *)Coll_Pos, (void *)o) && Box_ContainsXZ((void *)D_800B20B8, (void *)o) && d < 0) {
            out[3] = o->y - ((*(P_7449C_8007449C * *)&Coll_Pos)->y - b->h);
        }
    }
    return 1;
miss:
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80071D20_collide", D_800A5D84);


typedef struct { s16 x, y, z, r, h, rz; } Shape_74BBC;
typedef struct { s32 radius; u8 kind; u8 pad5[3]; s32 height; } Col_74BBC;
typedef struct { s32 x, y, z; } Pos_74BBC;
extern struct { u8 pad0[0x8150]; u16 f_8150; } g_Game_74BBC asm("g_Game");
extern Pos_74BBC *D_800B20B4_74BBC asm("Coll_Pos");
extern s32 D_800B20B8_74BBC asm("D_800B20B8");
extern s16 D_800B20C6_74BBC asm("D_800B20C6");
extern s16 D_800B20CA_74BBC asm("D_800B20CA");
extern s16 D_800B20CC_74BBC asm("D_800B20CC");
extern u16 D_800EC238_74BBC asm("g_SpikeStandObj");
s32 SquareRoot0_74BBC(s32) asm("SquareRoot0");
s32 Coll_PastEdge_74BBC(Shape_74BBC *, Pos_74BBC *) asm("Coll_PastEdge");
s32 Coll_HeightOverlap_74BBC(s32, s32, s32, s32) asm("Coll_HeightOverlap");
s32 Box_ContainsXZ_74BBC(s32, Shape_74BBC *) asm("Box_ContainsXZ");
void func_80066E28_74BBC(s32, s32, s32, s32, s32, s32) asm("Spike_SetClimbPole");
s32 Coll_PushCurvedCorner_74BBC(Shape_74BBC *, Col_74BBC *, s32 *) asm("Coll_PushCurvedCorner");
s32 Coll_PushHalfCylinder_74BBC(Shape_74BBC *, Col_74BBC *, s32 *) asm("Coll_PushHalfCylinder");
s32 func_80075A40_74BBC(Shape_74BBC *, Col_74BBC *, s32 *) asm("Coll_PushLyingCylinder");
s32 func_80076E80_74BBC(Shape_74BBC *, Col_74BBC *, s32 *) asm("func_80076E80");

s32 Coll_PushObjectShape(Shape_74BBC *s, Col_74BBC *c, s32 *out) {
    s32 rad = c->radius;
    s32 d;
    s32 k;
    s32 dx;
    s32 dz;
    s16 ex;
    s16 ez;

    switch (c->kind) {
    case 0x36:
    case 0x44:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x51:
        d = SquareRoot0_74BBC((s->x - D_800B20B4_74BBC->x) * (s->x - D_800B20B4_74BBC->x) + (s->z - D_800B20B4_74BBC->z) * (s->z - D_800B20B4_74BBC->z));
        if (d == 0) {
            d = 1;
        }
        if (D_800B20B4_74BBC->y < s->y - s->h + 0x40) {
            return 0;
        }
        if (s->y < D_800B20B4_74BBC->y - c->height) {
            return 0;
        }
        rad = s->r * 75 / 1000;
        if (rad < 0x40) {
            rad = 0x40;
        }
        if (rad < (s->r - d >= 0 ? s->r - d : d - s->r)) {
            return 0;
        }
        if ((u32)(c->kind - 0x4E) < 4 && !Coll_PastEdge_74BBC(s, D_800B20B4_74BBC)) {
            return 0;
        }
        if (d < s->r) {
            s32 k = s->r - rad;
            s32 tx = k * (D_800B20B4_74BBC->x - s->x) * 100 / d;
            s32 tz = k * (D_800B20B4_74BBC->z - s->z) * 100 / d;
            dx = tx / 100;
            dz = tz / 100;
        } else {
            s32 k = s->r + rad;
            s32 tx = k * (D_800B20B4_74BBC->x - s->x) * 100 / d;
            s32 tz = k * (D_800B20B4_74BBC->z - s->z) * 100 / d;
            dx = tx / 100;
            dz = tz / 100;
        }
        out[0] = s->x + dx - D_800B20B4_74BBC->x;
        out[2] = s->z + dz - D_800B20B4_74BBC->z;
        return 1;
    case 0x3B:
    case 0x59:
        if (g_Game_74BBC.f_8150 == 5) {
            if (D_800B20CA_74BBC != D_800B20C6_74BBC) {
                return 0;
            }
            if (D_800B20CC_74BBC != 1) {
                return 0;
            }
            D_800EC238_74BBC = D_800B20C6_74BBC;
            break;
        }
        d = SquareRoot0_74BBC((s->x - D_800B20B4_74BBC->x) * (s->x - D_800B20B4_74BBC->x) + (s->z - D_800B20B4_74BBC->z) * (s->z - D_800B20B4_74BBC->z));
        if (d == 0) {
            d = 1;
        }
        if (d >= rad + s->r) {
            return 0;
        }
        if (!Coll_HeightOverlap_74BBC(D_800B20B4_74BBC->y, c->height, s->y, s->h)) {
            break;
        }
        if (D_800B20CC_74BBC == 1) {
            if (c->kind == 0x3B) {
                func_80066E28_74BBC(s->x, s->y, s->z, s->r, s->h, 1);
            } else {
                func_80066E28_74BBC(s->x, s->y, s->z, s->r, s->h, 0);
            }
            D_800EC238_74BBC = D_800B20C6_74BBC;
        }
        {
            s32 tx = (rad + s->r) * (D_800B20B4_74BBC->x - s->x) * 100 / d;
            s32 tz = (rad + s->r) * (D_800B20B4_74BBC->z - s->z) * 100 / d;
            dx = tx / 100;
            dz = tz / 100;
        }
        out[0] = s->x + dx - D_800B20B4_74BBC->x;
        out[2] = s->z + dz - D_800B20B4_74BBC->z;
        if (D_800B20B4_74BBC->y - c->height < s->y && s->y - s->h < D_800B20B4_74BBC->y) {
            if (Box_ContainsXZ_74BBC(D_800B20B8_74BBC, s)) {
                if (d < s->r) {
                    out[3] = s->y - (D_800B20B4_74BBC->y - c->height);
                }
            }
        }
        return 2;
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
        return Coll_PushCurvedCorner_74BBC(s, c, out);
    case 0x24:
    case 0x25:
        ex = (u16)s->r + (u16)c->radius;
        ez = (u16)s->rz + (u16)c->radius;
        if (D_800B20B4_74BBC->x > s->x + ex || s->x - ex > D_800B20B4_74BBC->x) {
            return 0;
        }
        if (s->z + ez < D_800B20B4_74BBC->z || D_800B20B4_74BBC->z < s->z - ez) {
            return 0;
        }
        return Coll_PushHalfCylinder_74BBC(s, c, out);
    case 0x53:
        ex = (u16)s->r + (u16)c->radius;
        ez = (u16)s->rz + ((u16)c->radius + 0x100);
        if (D_800B20B4_74BBC->x > s->x + ex || s->x - ex > D_800B20B4_74BBC->x) {
            return 0;
        }
        if (s->z + ez < D_800B20B4_74BBC->z || D_800B20B4_74BBC->z < s->z - ez) {
            return 0;
        }
        return func_80075A40_74BBC(s, c, out);
    case 0x54:
        ex = (u16)s->r + ((u16)c->radius + 0x100);
        ez = (u16)s->rz + (u16)c->radius;
        if (D_800B20B4_74BBC->x > s->x + ex || s->x - ex > D_800B20B4_74BBC->x) {
            return 0;
        }
        if (s->z + ez < D_800B20B4_74BBC->z || D_800B20B4_74BBC->z < s->z - ez) {
            return 0;
        }
        return func_80075A40_74BBC(s, c, out);
    case 0x52:
        return func_80076E80_74BBC(s, c, out);
    default:
        d = SquareRoot0_74BBC((s->x - D_800B20B4_74BBC->x) * (s->x - D_800B20B4_74BBC->x) + (s->z - D_800B20B4_74BBC->z) * (s->z - D_800B20B4_74BBC->z));
        if (d == 0) {
            d = 1;
        }
        if (d >= rad + s->r) {
            return 0;
        }
        if (!Coll_HeightOverlap_74BBC(D_800B20B4_74BBC->y, c->height, s->y, s->h)) {
            return 0;
        }
        k = rad + s->r;
        if (k > 0x1000) {
            dx = k * (D_800B20B4_74BBC->x - s->x) / d;
            dz = k * (D_800B20B4_74BBC->z - s->z) / d;
        } else {
            s32 tx = k * (D_800B20B4_74BBC->x - s->x) * 100 / d;
            s32 tz = k * (D_800B20B4_74BBC->z - s->z) * 100 / d;
            dx = tx / 100;
            dz = tz / 100;
        }
        out[0] = s->x + dx - D_800B20B4_74BBC->x;
        out[2] = s->z + dz - D_800B20B4_74BBC->z;
        if (D_800B20B4_74BBC->y - c->height < s->y && s->y - s->h < D_800B20B4_74BBC->y) {
            if (Box_ContainsXZ_74BBC(D_800B20B8_74BBC, s)) {
                if (d < s->r) {
                    out[3] = s->y - (D_800B20B4_74BBC->y - c->height);
                }
            }
        }
        return 1;
    }
    return 0;
}



/* Like Coll_PushBox for a half-cylinder (log/barrel) lying along x (kinds 0x24/0x53, radius +0xA)
 * or z (0x25/others, radius +6): its height at Spike's position comes from the circle
 * (SquareRoot0), out[4]/out[5] get that height when he steps onto it. */
s32 Coll_PushHalfCylinder(O_75630_80075630 *o, B_75630_80075630 *b, s32 *out) {
    s16 ex;
    s16 ez;
    s32 dx;
    s32 dz;
    s16 side;
    s32 t;
    s32 r;
    s32 s;

    ex = o->w + b->r;
    ez = o->d + b->r;
    if (b->kind == 0x24) {
        if (o->d < ABS(o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z)) {
            return 0;
        }
        r = SquareRoot0(o->d * o->d - (o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z) * (o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z));
    } else if (b->kind == 0x53) {
        r = SquareRoot0(o->d * o->d - (o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z) * (o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z));
    } else if (b->kind == 0x25) {
        if (o->w < ABS(o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x)) {
            return 0;
        }
        r = SquareRoot0(o->w * o->w - (o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x) * (o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x));
    } else {
        r = SquareRoot0(o->w * o->w - (o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x) * (o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x));
    }
    if (Coll_HeightOverlap((*(P_75630_80075630 * *)&Coll_Pos)->y, b->h, o->y + r, r * 2) == 0) {
        return 0;
    }
    dx = (*(P_75630_80075630 * *)&Coll_Pos)->x - o->x;
    dz = (*(P_75630_80075630 * *)&Coll_Pos)->z - o->z;
    if (o->w < ABS(dx) && o->d < ABS(dz)) {
        dx = o->w < dx ? dx - o->w : dx + o->w;
        dz = o->d < dz ? dz - o->d : dz + o->d;
        side = (dx < dz) << 1;
        side |= -dx < dz;
    } else {
        side = ((dx * o->d / o->w < dz) << 1) | (dx * -o->d / o->w < dz);
    }
    if (side == 0 || side == 3) {
        t = o->z - (*(P_75630_80075630 * *)&Coll_Pos)->z;
        out[2] = t;
        out[2] = (*(P_75630_80075630 * *)&Coll_Pos)->z < o->z ? t - ez : t + ez;
    } else if (side == 1 || side == 2) {
        t = o->x - (*(P_75630_80075630 * *)&Coll_Pos)->x;
        out[0] = t;
        out[0] = (*(P_75630_80075630 * *)&Coll_Pos)->x < o->x ? t - ex : t + ex;
    }
    if ((*(P_75630_80075630 * *)&Coll_Pos)->y - b->h < o->y + r && o->y - r < (*(P_75630_80075630 * *)&Coll_Pos)->y) {
        if (Box_ContainsXZ((P_73B64_80073B64 *)Coll_Pos, (O_73B64_80073B64 *)o) && Box_ContainsXZ((P_73B64_80073B64 *)D_800B20B8, (O_73B64_80073B64 *)o)) {
            out[3] = o->y + r - ((*(P_75630_80075630 * *)&Coll_Pos)->y - b->h);
            out[5] = r;
            out[4] = r;
        }
    }
    return 1;
}

typedef struct { s32 x, y, z; } P_75A40;
extern P_75A40 *D_800B20B4_75A40 asm("Coll_Pos");
s32 Surface_CylinderHeight_75A40(s16, s16 *, V3_792C8_800792C8 *, V3_792C8_800792C8 *) asm("Surface_CylinderHeight");
s32 Coll_PushHalfCylinder(O_75630_80075630 *o, B_75630_80075630 *b, s32 *out);

s32 Coll_PushLyingCylinder(O_75630_80075630 *o, B_75630_80075630 *b, s32 *out) {
    P_75A40 *p = (P_75A40 *)0x1F800124;
    s32 *h1 = (s32 *)0x1F800130;
    s32 *h2 = (s32 *)0x1F800138;
    s32 kind = b->kind;
    s32 d1;
    s32 d2;
    s32 w;
    s16 cc[6];
    s16 i;

    { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - b->h - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
    Surface_CylinderHeight_75A40(kind, &o->w, (V3_792C8_800792C8 *)p, (V3_792C8_800792C8 *)h2);
    { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
    Surface_CylinderHeight_75A40(kind, &o->w, (V3_792C8_800792C8 *)p, (V3_792C8_800792C8 *)h1);
    __asm__("" :: "r"(h1), "r"(h1), "r"(h1), "r"(h1));
    __asm__("" :: "r"(out));
    if (kind == 0x53) {
        { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - b->h - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
        d1 = SquareRoot0(p->y * p->y + p->z * p->z);
        { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
        d2 = SquareRoot0(p->y * p->y + p->z * p->z);
        if (o->d - 0xC0 < d1) {
            goto cyl;
        }
        if (o->d - 0xC0 < d2) {
            goto cyl;
        }
        w = SquareRoot0((o->d - 0x100) * (o->d - 0x100) - b->h * b->h) - 0x40;
        if (*h1 == *h2 && o->z - w < D_800B20B4_75A40->z && D_800B20B4_75A40->z < o->z + w) {
            return 0;
        }
        if (D_800B20B4_75A40->z < o->z - w) {
            out[2] = o->z - w - D_800B20B4_75A40->z;
        } else if (o->z + w < D_800B20B4_75A40->z) {
            out[2] = o->z + w - D_800B20B4_75A40->z;
        }
    } else if (kind == 0x54) {
        { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - b->h - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
        d1 = SquareRoot0(p->y * p->y + p->x * p->x);
        { s32 tx = D_800B20B4_75A40->x - o->x; p->y = D_800B20B4_75A40->y - o->y; p->z = D_800B20B4_75A40->z - o->z; p->x = tx; }
        d2 = SquareRoot0(p->y * p->y + p->x * p->x);
        if (o->w - 0xC0 < d1) {
            goto cyl;
        }
        if (o->w - 0xC0 < d2) {
            goto cyl;
        }
        w = SquareRoot0((o->w - 0x100) * (o->w - 0x100) - b->h * b->h) - 0x40;
        if (*h1 == *h2 && o->x - w < D_800B20B4_75A40->x && D_800B20B4_75A40->x < o->x + w) {
            return 0;
        }
        if (D_800B20B4_75A40->x < o->x - w) {
            out[0] = o->x - w - D_800B20B4_75A40->x;
        } else if (o->x + w < D_800B20B4_75A40->x) {
            out[0] = o->x + w - D_800B20B4_75A40->x;
        }
    } else {
        goto cyl;
    }
    {
        s32 hv = *h1;
        if (hv < 0 && *h2 > 0) {
            s32 c = hv; s32 a; s32 oy; s32 bh; s32 dy; __asm__("" : "=r"(c) : "0"(c));
            dy = D_800B20B4_75A40->y; oy = o->y; bh = b->h; 
            __asm__ volatile("");
            a = c; __asm__("" : "=r"(a) : "0"(a)); a = abs(a);
            out[4] = c; out[5] = a;
            out[3] = oy + hv - (dy - bh);
        }
    }
    return 1;
cyl:
    for (i = 0; i < 6; i++) {
        cc[i] = ((s16 *)o)[i];
    }
    if (kind == 0x53) {
        cc[5] += 0x100;
    } else if (kind == 0x54) {
        cc[3] += 0x100;
    }
    return Coll_PushHalfCylinder((O_75630_80075630 *)cc, b, out);
}

/* Push Spike out of a wall edge piece: type 0x1000 has one fixed face from the orientation,
 * others pick the face by quadrant (like Coll_PushWallSegment); returns the axis corrected. */
s32 Coll_PushWallEdge(Box_80075F48_80075F48 *a, S_P_8007734C_8007734C_80075F48 *b, S_P_8007734C_8007734C_80075F48 *out) {
    s32 r = b->f_0;
    s32 ang = b->f_4;
    s32 dx;
    s32 dz;
    s32 side;
    s32 t;
    s32 u;

    if (Coll_HeightOverlap((*(S_P_8007734C_8007734C_80075F48 * *)&Coll_Pos)->f_4, b->f_8, a->y, a->h) == 0) {
    miss:
        return 0;
    }
    dz = (*(S_P_8007734C_8007734C_80075F48 * *)&Coll_Pos)->f_8 - a->z;
    dx = (*(S_P_8007734C_8007734C_80075F48 * *)&Coll_Pos)->f_0 - a->x;
    if ((ang & 0xF000) == 0x1000) {
        side = 2;
        if (ang & 0xC00) {
            side = 1;
        }
    } else {
        switch (ang & 0xF00) {
        case 0:
            side = 2;
            if (dx < dz) {
                side = 1;
            }
            break;
        case 0x400:
            side = 1;
            if (-dx < dz) {
                side = 2;
            }
            break;
        case 0x800:
            side = 1;
            if (dx < dz) {
                side = 2;
            }
            break;
        case 0xC00:
            side = 2;
            if (-dx < dz) {
                side = 1;
            }
            break;
        }
    }
    if (side == 1) {
        t = r + 12;
        if (dx > t) {
            goto miss;
        }
        t = -t;
        if (dx < t) {
            goto miss;
        }
        if (dz > a->hz || dz < -a->hz) {
            goto miss;
        }
        if (dx > 0) {
            u = dx - 12;
            out->f_0 = r - u;
        } else {
            out->f_0 = t - dx;
        }
    } else if (side == 2) {
        t = r + 12;
        if (dz > t) {
            goto miss;
        }
        t = -t;
        if (dz < t) {
            goto miss;
        }
        if (dx > a->hx || dx < -a->hx) {
            goto miss;
        }
        if (dz > 0) {
            u = dz - 12;
            out->f_8 = r - u;
        } else {
            out->f_8 = t - dz;
        }
    } else if (side == 3) {
        if (dx > 0) {
            u = dx - 12;
            out->f_0 = r - u;
        } else {
            out->f_0 = -(r + 12) - dx;
        }
        if (dz > 0) {
            u = dz - 12;
            out->f_8 = r - u;
        } else {
            out->f_8 = -(r + 12) - dz;
        }
    }
    return side;
}

/* Push Spike (Coll_Pos) out of a wall piece o whose face sits 0x100 off its centre
 * (orientation b[1] & 0xF00; type 0x6000 = one fixed face, else the face is picked from the
 * quadrant he is in) using radius b[0] + 12: returns 1 and corrects out[0] (x face) or 2 and
 * out[2] (z face); 0 if not touching (height test Coll_HeightOverlap first). */
s32 Coll_PushWallSegment(O_761AC_800761AC *o, B_761AC_800761AC *b, P_761AC_800761AC *out) {
    s32 r = b->r + 12;
    s32 fl = b->flags;
    s32 dx;
    s32 dz;
    s32 side;
    s32 ex;
    s32 ez;
    s32 h;

    if (Coll_HeightOverlap((*(P_761AC_800761AC * *)&Coll_Pos)->y, b->y, o->y, o->f_8) == 0) {
        miss:
        return 0;
    }
    dz = (*(P_761AC_800761AC * *)&Coll_Pos)->z - o->z;
    dx = (*(P_761AC_800761AC * *)&Coll_Pos)->x - o->x;
    if ((fl & 0xF000) == 0x6000) {
        switch (fl & 0xF00) {
        case 0:
            ez = -0x100;
            side = 2;
            break;
        case 0x400:
            ex = -0x100;
            side = 1;
            break;
        case 0x800:
            ez = 0x100;
            side = 2;
            break;
        case 0xC00:
            ex = 0x100;
            side = 1;
            break;
        }
    } else {
        switch (fl & 0xF00) {
        case 0:
            ex = -0x100;
            ez = ex;
            side = 2;
            if (dx < dz) {
                side = 1;
            }
            break;
        case 0x400:
            ex = -0x100;
            ez = 0x100;
            side = 1;
            if (-dx < dz) {
                side = 2;
            }
            break;
        case 0x800:
            ex = 0x100;
            ez = ex;
            side = 1;
            if (dx < dz) {
                side = 2;
            }
            break;
        case 0xC00:
            ex = 0x100;
            ez = -0x100;
            side = 2;
            if (-dx < dz) {
                side = 1;
            }
            break;
        }
    }
    if (side == 1) {
        h = o->f_A + r;
        if (h < dz) {
            goto miss;
        }
        if (dz < -h) {
            goto miss;
        }
        if (ex + r < dx) {
            goto miss;
        }
        if (dx < ex - r) {
            goto miss;
        }
        if (dx <= ex) {
            out->x = ex - r - dx;
        } else {
            out->x = ex + r - dx;
        }
    } else if (side == 2) {
        h = o->f_6 + r;
        if (h < dx) {
            goto miss;
        }
        if (dx < -h) {
            goto miss;
        }
        if (ez + r < dz) {
            goto miss;
        }
        if (dz < ez - r) {
            goto miss;
        }
        if (ez < dz) {
            out->z = ez + r - dz;
        } else {
            out->z = ez - r - dz;
        }
    } else if (side == 3) {
        out->x = (ex < dx ? ex + r : ex - r) - dx;
        out->z = (ez < dz ? ez + r : ez - r) - dz;
    }
    return side;
}

/* Push Spike (Coll_Pos) out of a 45-degree wall piece o (orientation b[1] & 0xF00, see
 * Geo_DiagonalDistance) using box b (radius b[0], height b[2]): when within radius + 12 of the
 * diagonal, out[0]/out[2] move him back onto the side he is on along the perpendicular. */
s32 Coll_PushDiagonalWall(O_76488_80076488 *o, B_76488_80076488 *b, s32 *out) {
    P_76488_80076488 *q = (P_76488_80076488 *)0x1F800124;
    s32 r = b->r + 12;
    s32 dz = (*(P_76488_80076488 * *)&Coll_Pos)->z - o->z;
    s32 dx = (*(P_76488_80076488 * *)&Coll_Pos)->x - o->x;
    s32 d;
    s32 ax;
    s32 az;

    if (o->w + b->r < dx) {
        goto miss;
    }
    if (dx < -(o->w + b->r)) {
        goto miss;
    }
    if (o->d + b->r < dz) {
        goto miss;
    }
    if (dz < -(o->d + b->r)) {
        goto miss;
    }
    if (Coll_HeightOverlap((*(P_76488_80076488 * *)&Coll_Pos)->y, b->h, o->y, o->h) == 0) {
        goto miss;
    }
    d = Geo_DiagonalDistance(b->flags, (void *)Coll_Pos, (void *)o, (void *)q);
    if (r < ABS(d)) {
miss:
        return 0;
    }
    if (d == 0) {
        d = 1;
    }
    ax = ABS(q->x - (*(P_76488_80076488 * *)&Coll_Pos)->x);
    az = ABS(q->z - (*(P_76488_80076488 * *)&Coll_Pos)->z);
    switch (b->flags & 0xF00) {
    case 0:
        if (d > 0) {
            out[0] = ax - ax * r / d;
            out[2] = az - az * r / d;
        } else {
            out[0] = -(ax * r / d + ax);
            out[2] = -(az * r / d + az);
        }
        break;
    case 0x400:
        if (d > 0) {
            out[0] = ax - ax * r / d;
            out[2] = az * r / d - az;
        } else {
            out[0] = -(ax * r / d + ax);
            out[2] = az * r / d + az;
        }
        break;
    case 0x800:
        if (d > 0) {
            out[0] = ax * r / d - ax;
            out[2] = az * r / d - az;
        } else {
            out[0] = ax * r / d + ax;
            out[2] = az * r / d + az;
        }
        break;
    case 0xC00:
        if (d > 0) {
            out[0] = ax * r / d - ax;
            out[2] = az - az * r / d;
        } else {
            out[0] = ax * r / d + ax;
            out[2] = -(az * r / d + az);
        }
        break;
    }
    return 1;
}

/* Push Spike (Coll_Pos) out of a quarter-round corner wall piece o (see Coll_CurvedCorner) using
 * box b (radius b[0], height b[2]): on top of the ring (within its width) only out[3] gets the
 * step up to its top; otherwise his x/z (out[0]/out[2]) are moved radially to radius
 * outer -/+ width -/+ b[0] (inside/outside the ring). Returns 1 on contact. */
s32 Coll_PushCurvedCorner(O_76AC8_80076AC8 *o, s32 *b, s32 *out) {
    s32 c[2];
    s16 sl[2];
    s32 h;
    s32 d;
    s32 inner;
    s32 outer;
    s32 lo;
    s32 k;
    s32 dx;
    s32 dz;
    s32 nx;

    h = Coll_CurvedCorner(o, (*(P_76AC8_80076AC8 * *)&Coll_Pos), b, sl);
    if (h < 0) {
        return 0;
    }
    h = o->f_2 - h;
    if ((*(P_76AC8_80076AC8 * *)&Coll_Pos)->y < h + 0x40) {
        return 0;
    }
    CurvedCorner_GetCentre(o, c);
    inner = o->f_6 - o->f_24;
    outer = o->f_24 + o->f_6;
    d = SquareRoot0((c[0] - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x) * (c[0] - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x) + (c[1] - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->z) * (c[1] - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->z));
    if (d == 0) {
        d = 1;
    }
    if (inner >= ABS(outer - d)) {
        if (o->f_26 < o->f_8) {
            lo = o->f_26;
        } else {
            lo = o->f_8;
        }
        if ((*(P_76AC8_80076AC8 * *)&Coll_Pos)->y - b[2] < o->f_2 && o->f_2 - lo < (*(P_76AC8_80076AC8 * *)&Coll_Pos)->y) {
            out[3] = o->f_2 - ((*(P_76AC8_80076AC8 * *)&Coll_Pos)->y - b[2]);
            return 1;
        }
        return 0;
    }
    if (d < outer) {
        k = outer - inner - b[0];
        dx = (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x - c[0];
        nx = k * dx / d;
        dz = (*(P_76AC8_80076AC8 * *)&Coll_Pos)->z - c[1];
        d = k * dz / d;
        if (nx == dx && d == dz) {
            if (c[0] < (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x) {
                nx--;
            } else {
                nx++;
            }
            if ((*(P_76AC8_80076AC8 * *)&Coll_Pos)->z > c[1]) {
                d--;
            } else {
                d++;
            }
        }
    } else {
        k = outer + inner + b[0];
        dx = (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x - c[0];
        nx = k * dx / d;
        dz = (*(P_76AC8_80076AC8 * *)&Coll_Pos)->z - c[1];
        d = k * dz / d;
        if (nx == dx && d == dz) {
            if (c[0] < (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x) {
                nx++;
            } else {
                nx--;
            }
            if ((*(P_76AC8_80076AC8 * *)&Coll_Pos)->z > c[1]) {
                d++;
            } else {
                d--;
            }
        }
    }
    out[0] = c[0] + nx - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->x;
    out[2] = c[1] + d - (*(P_76AC8_80076AC8 * *)&Coll_Pos)->z;
    return 1;
}

typedef struct { s16 x, y, z; u8 pad6[0x1E]; s16 f_24, f_26, f_28; } O_76E80;
typedef struct { s32 x, y, z; } P_76E80;
struct Game_76E80 { u8 pad0[0x8150]; u16 f_8150; };
extern struct Game_76E80 g_Game_76E80 asm("g_Game");
extern P_76E80 *D_800B20B4_76E80 asm("Coll_Pos");
extern s16 D_800EC238_76E80 asm("g_SpikeStandObj");
void func_80066E8C_76E80(s16 *, s16 *) asm("Spike_SetHangBar");

s32 func_80076E80(O_76E80 *o, s32 *b) {
    s32 *q = (s32 *)0x1F800124;
    s32 *r = (s32 *)0x1F80012C;
    s16 hx;
    s16 hz;
    s16 cx;
    s16 cy;
    s16 cz;
    s16 ax;
    s16 az;
    s16 sg[2];
    s32 t;
    s32 k;
    s32 d;

    if (D_800B20CC != 1) {
        goto miss;
    }
    hz = 0x40;
    if (g_Game_76E80.f_8150 == 6 && D_800B20C8 == D_800B20C6) {
        D_800EC238_76E80 = D_800B20C6;
        func_80066E8C_76E80(&o->x, &o->f_24);
    miss:
        return 0;
    }
    hx = hz;
    cx = o->f_24 + (o->x - o->f_24) / 2;
    cy = o->f_26 + (o->y - o->f_26) / 2;
    cz = o->f_28 + (o->z - o->f_28) / 2;
    t = D_800B20B4_76E80->y - b[2] + 0x40;
    if (t < cy - 0x40) {
        goto miss;
    }
    if (cy + 0x40 < t) {
        goto miss;
    }
    if (o->x == o->f_24) {
        hz = ABS(o->f_28 - o->z) / 2;
        ax = ABS(D_800B20B4_76E80->x - cx);
        az = ABS(D_800B20B4_76E80->z - cz);
        if (ax > hx) {
            goto miss;
        }
        if (az > hz) {
            s32 z;
            __asm__("" : "=r"(z) : "0"(0));
            return z;
        }
    } else if (o->z == o->f_28) {
        hx = ABS(o->f_24 - o->x) / 2;
        ax = ABS(D_800B20B4_76E80->x - cx);
        az = ABS(D_800B20B4_76E80->z - cz);
        if (ax > hx) {
            goto miss;
        }
        if (az > hz) {
            s32 z;
            __asm__("" : "=r"(z) : "0"(0), "i"(1));
            return z;
        }
    } else {
        sg[0] = o->x - o->f_24 > 0 ? 1 : -1;
        sg[1] = o->z - o->f_28 > 0 ? 1 : -1;
        if (sg[0] * sg[1] > 0) {
            *(volatile s32 *)&q[0] = (D_800B20B4_76E80->z + D_800B20B4_76E80->x - (cz - cx)) / 2;
            q[1] = (((volatile P_76E80 *)D_800B20B4_76E80)->z + ((volatile P_76E80 *)D_800B20B4_76E80)->x + (cz - cx)) / 2;
        } else {
            *(volatile s32 *)&q[0] = (cz + cx - (D_800B20B4_76E80->z - D_800B20B4_76E80->x)) / 2;
            q[1] = (cz + cx + (((volatile P_76E80 *)D_800B20B4_76E80)->z - ((volatile P_76E80 *)D_800B20B4_76E80)->x)) / 2;
        }
        r[0] = SquareRoot0((D_800B20B4_76E80->z - q[1]) * (D_800B20B4_76E80->z - q[1]) + (D_800B20B4_76E80->x - q[0]) * (D_800B20B4_76E80->x - q[0]));
        r[1] = SquareRoot0((cz - q[1]) * (cz - q[1]) + (cx - q[0]) * (cx - q[0]));
        if (r[0] > 0x40) {
            goto miss;
        }
        d = o->f_24 - cx; if (d < 0) d = cx - o->f_24;
        if (d < r[1]) {
            goto miss;
        }
    }
    func_80066E8C_76E80(&o->x, &o->f_24);
    D_800EC238_76E80 = D_800B20C6;
    return 0;
}

s32 Coll_PushFlatWall(S_A_8007734C_8007734C *a, S_B_8007734C_8007734C *b, S_B_8007734C_8007734C *out) {
    s32 r = b->f_0 + 12;
    s32 dx = Coll_Pos->f_0 - a->f_0;
    s32 dz = Coll_Pos->f_8 - a->f_4;
    s32 t;
    s32 ret;
    if (a->f_10 == 0x4A || a->f_10 == 0x4C) {
        t = Coll_RampPieceHeight(a, Coll_Pos);
        if (t == 0) {
            return 0;
        }
        ret = 2;
        if (Coll_HeightOverlap(Coll_Pos->f_4, b->f_8, a->f_2, t) == 0) {
            return 0;
        }
        if (dz > 0) {
            out->f_8 = r - dz;
        } else {
            out->f_8 = -r - dz;
        }
    } else {
        t = Coll_RampPieceHeight(a, Coll_Pos);
        if (t == 0) {
            return 0;
        }
        ret = 1;
        if (Coll_HeightOverlap(Coll_Pos->f_4, b->f_8, a->f_2, t) == 0) {
            return 0;
        }
        if (dx > 0) {
            out->f_0 = r - dx;
        } else {
            out->f_0 = -r - dx;
        }
    }
    return ret;
}

s32 Coll_UnknownShape(s32 arg0, void *arg1) {
    bios_printf(&D_800A5E80, M2C_FIELD(arg1, s32 *, 4));
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80071D20_collide", D_800A5E80);


/* Signed distance in the x/z plane from point p to the 45-degree line through object o
 * (orientation dir & 0xF00: 0/0x800 the x+z line, 0x400/0xC00 the x-z line); q gets the foot of
 * the perpendicular. Positive on the side the orientation faces. */
s32 Geo_DiagonalDistance(s32 dir, P_800774B8_800774B8 *p, O_800774B8_800774B8 *o, P_800774B8_800774B8 *q) {
    s32 sign = -1;
    s32 dx;
    s32 dz;
    switch (dir & 0xF00) {
    case 0:
        q->x = (o->x + o->z - (p->z - p->x)) / 2;
        q->z = (o->x + o->z + (p->z - p->x)) / 2;
        if (p->z < -p->x + o->x + o->z) {
            sign = 1;
        }
        break;
    case 0x400:
        q->x = (p->x + p->z - (o->z - o->x)) / 2;
        q->z = (p->x + p->z + (o->z - o->x)) / 2;
        if (p->x + o->z - o->x < p->z) {
            sign = 1;
        }
        break;
    case 0x800:
        q->x = (o->x + o->z - (p->z - p->x)) / 2;
        q->z = (o->x + o->z + (p->z - p->x)) / 2;
        if (-p->x + o->x + o->z < p->z) {
            sign = 1;
        }
        break;
    case 0xC00:
        q->x = (p->x + p->z - (o->z - o->x)) / 2;
        q->z = (p->x + p->z + (o->z - o->x)) / 2;
        if (p->z < p->x + o->z - o->x) {
            sign = 1;
        }
        break;
    }
    dx = p->x - q->x;
    dz = p->z - q->z;
    return sign * SquareRoot0(dx * dx + dz * dz);
}

s32 Dir_QuadrantIndex(s32 a) {
    switch (a & 0xF00) {
    case 0:
        return 0;
    case 0x400:
        return 1;
    case 0x800:
        return 2;
    case 0xC00:
        return 3;
    }
    return 0;
}

typedef struct { s16 vx, vy, vz, pad; } SV_777AC;
typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; s16 f_22; u8 pad24[2]; s16 f_26; u8 pad28[4]; s32 f_2C; } D_777AC;
typedef struct N_777AC { s16 kind; s16 id; D_777AC *d; u8 pad8[4]; struct N_777AC *next; } N_777AC;
extern N_777AC *g_CollisionHead_777AC asm("g_CollisionHead");
s32 Collider_GetCentre_777AC(s16, D_777AC *, SV_777AC *) asm("Collider_GetCentre");
void VectorNormalS(void *, void *);
void Camera_Translate(s32, s32, s32);

s32 Collider_PushApart(N_777AC *self)
{
  s32 *d = (s32 *) 0x1F8000F0;
  SV_777AC *n = (SV_777AC *) 0x1F800100;
  SV_777AC *b = (SV_777AC *) 0x1F800108;
  SV_777AC *o = (SV_777AC *) 0x1F800110;
  register N_777AC *c asm("$17");
  D_777AC *od;
  s16 px;
  s16 pz;
  s32 h;
  s32 dx;
  s32 dz;
  if (self->d->f_2C != 0)
  {
    return 0;
  }
  for (c = g_CollisionHead_777AC; c != 0; c = c->next)
  {
    if ((((self == c) || (c->kind <= 0)) || (c->kind >= 6)) || (c->d->f_2C != 0))
    {
      continue;
    }
    if ((((self->kind == 3) && (c->kind != 1)) && (c->kind != 3)) && (c->kind != 2))
    {
      continue;
    }
    if (self->kind == 4)
    {
      if (c->kind == 3)
      {
        continue;
      }
      if (c->kind == 4)
      {
        continue;
      }
    }
    if (self->kind == 5)
    {
      if (c->kind == 5)
      {
        continue;
      }
      if (c->kind == 3)
      {
        continue;
      }
    }
    od = c->d;
    Collider_GetCentre_777AC(c->kind, od, o);
    for (;;)
    {
      Collider_GetCentre_777AC(self->kind, self->d, b);
      d[0] = o->vx - b->vx;
      d[1] = o->vy - b->vy;
      d[2] = o->vz - b->vz;
      if (Vec_Length(d[0], 0, d[2]) >= (od->f_20 + self->d->f_20))
      {
        break;
      }
      h = (((self->d->f_22 / 2) >= 0) ? (self->d->f_22 / 2) : (-(self->d->f_22 / 2))) + (((od->f_22 / 2) >= 0) ? (od->f_22 / 2) : (-(od->f_22 / 2)));
      if ((o->vy - b->vy) >= 0)
      {
        if (!((o->vy - b->vy) < h))
        {
          break;
        }
        __asm__ volatile("");
        goto body;
      }
      if (!((b->vy - o->vy) < h))
      {
        break;
      }
body:
      if ((((c->kind == 5) && (self->kind == 4)) || ((c->kind == 4) && (self->kind == 5))) || (c->kind == 1))
      {
        c->d->f_2C = (self->kind << 28) | self->id;
      }
      self->d->f_2C = (c->kind << 28) | c->id;
      if ((self->kind == 3) && (c->kind == 3))
      {
        break;
      }
      VectorNormalS(d, n);
      px = n->vx >> 10;
      pz = n->vz >> 10;
      if ((((u16) (px + 3)) < 7) && (((u16) (pz + 3)) < 7))
      {
        px = (px < 0) ? (-4) : (4);
        pz = (pz < 0) ? (-4) : (4);
      }
      if (((self->d->f_26 & 0x8000) && (((u16) (c->kind - 1)) < 2)) || ((self->kind == 5) && (c->kind == 4)))
      {
        c->d->x += px;
        c->d->z += pz;
        Collider_GetCentre_777AC(c->kind, c->d, o);
        if (c->kind == 1)
        {
          Camera_Translate(px, 0, pz);
        }
        continue;
      }
      self->d->x -= px;
      self->d->z -= pz;
    }

  }

  return 0;
}

s32 Collider_GetCentre(s16 k, S_77C28_80077C28 *s, s16 *out) {
    if ((k >= 6 && k < 10) || k == 0xC || k == 0xD || k == 0x10 || k == 0x11) {
        out[0] = s->f_0;
        out[1] = s->f_4;
        out[2] = s->f_8;
    } else {
        out[0] = s->f_0;
        out[1] = s->f_4 - (s16)s->f_22 / 2;
        out[2] = s->f_8;
        if (k == 1 && (D_800EC250 & 0xF0) == 0x60) {
            out[1] = s->f_4 + (s16)s->f_22 / 2;
        }
    }
    return 0;
}

typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; s16 f_22; s16 f_24; u8 pad26[6]; u32 f_2C; u8 pad30[0x20]; u32 f_50; } CObj_80077D18;
typedef struct CNode_80077D18 { s16 f_0; u16 f_2; CObj_80077D18 *f_4; CObj_80077D18 *f_8; struct CNode_80077D18 *f_C; } CNode_80077D18;
typedef struct { s16 x; u16 y; u16 z; } SPt_77D18;
extern CNode_80077D18 *g_CollisionHead_7D18 asm("g_CollisionHead");
s32 Collider_GetCentre_7D18(s16 k, CObj_80077D18 *o, SPt_77D18 *out) asm("Collider_GetCentre");
s32 func_80098320(void);

s32 func_80077D18(s32 unused, CNode_80077D18 *self) {
    SPt_77D18 *scr = (SPt_77D18 *)0x1F8000F0;
    CNode_80077D18 *n;
    CObj_80077D18 *o;
    s32 d;
    s32 k; s32 e; s32 w; u32 hi; u32 t;

    for (n = g_CollisionHead_7D18; n != 0; n = n->f_C) {
        if (n->f_0 != 1) {
            continue;
        }
        if (n->f_4->f_2C != 0 && (n->f_4->f_2C >> 28) != 10) {
            continue;
        }
        __asm__ volatile("" ::: "memory");
        o = n->f_4;
        Collider_GetCentre_7D18(n->f_0, o, scr);
        d = Vec_Length(scr->x - self->f_4->x, 0, (s16)scr->z - self->f_4->z);
        w = self->f_4->f_22;
        e = d - self->f_4->f_20;
        if (e >= 0) {
            if (!(e < w)) continue;
            __asm__ volatile("");
            goto body;
        }
        if (!(self->f_4->f_20 - d < w)) continue;
body:
        { register CObj_80077D18 *sp asm("$3") = self->f_4;
        if (o->y - o->f_22 - 0x40 >= sp->y) {
            continue;
        }
        if (sp->y >= o->y + 0x40) {
            continue;
        }
        k = sp->f_24; }
        k <<= 12;
        if (func_80098320() == 0) {
            { register CObj_80077D18 *dst asm("$4"); hi = k & 0xFFFF000; t = (self->f_2 & 0xFFF) | 0xB0000000; dst = n->f_4; hi |= t; dst->f_2C = hi; }
            self->f_4->f_2C = 0x60000000;
            if (self->f_8 != 0) {
                self->f_8->f_50 = 0x60000000;
            }
        } else {
            { register CObj_80077D18 *dst asm("$4"); hi = k & 0xFFFF000; t = (n->f_2 & 0xFFF) | 0xB0000000; dst = self->f_4; hi |= t; dst->f_2C = hi; }
        }
    }
    return 0;
}

typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0x14]; s16 f_20; u16 f_22; s16 f_24; u8 pad26[6]; u32 f_2C; } S_P_80077EE8;
typedef struct { u8 pad0[2]; u16 f_2; S_P_80077EE8 *f_4; } S_O_80077EE8;
typedef struct S_Node_80077EE8 { s16 f_0; s16 f_2; S_P_80077EE8 *f_4; u8 pad8[4]; struct S_Node_80077EE8 *f_C; } S_Node_80077EE8;
typedef struct { s16 vx; u16 vy; u16 vz; } S_Sc_80077EE8;
extern S_Node_80077EE8 *g_CollisionHead_7EE8 asm("g_CollisionHead");
void Collider_GetCentre_7EE8(s16, S_P_80077EE8 *, S_Sc_80077EE8 *) asm("Collider_GetCentre");

s32 func_80077EE8(s32 unused, S_O_80077EE8 *o) {
    S_Sc_80077EE8 *sc = (S_Sc_80077EE8 *)0x1F8000F0;
    register S_Node_80077EE8 *n asm("$16");
    S_P_80077EE8 *x;
    s32 r; register S_P_80077EE8 *op asm("$6");
    s32 h;
    for (n = g_CollisionHead_7EE8; n != 0; n = n->f_C) {
        if ((u16)(n->f_0 - 3) >= 3) continue;
        if (n->f_4->f_2C != 0 && (n->f_4->f_2C >> 28) != 10) continue;
        __asm__ volatile("" ::: "memory");
        x = n->f_4;
        Collider_GetCentre_7EE8(n->f_0, x, sc);
        if (Vec_Length(sc->vx - o->f_4->f_0, 0, (s16)sc->vz - o->f_4->f_8) >= x->f_20 + (op = o->f_4)->f_20) continue;
        h = (s16)x->f_22 / 2;
        { s32 rr = op->f_20 + abs(h); s32 sy = (s16)sc->vy;
        if (((sy - op->f_4) < 0 ? -(sy - op->f_4) : (sy - op->f_4)) < rr) {
            { u32 t = (o->f_2 & 0xFFF) | 0xB0000000; u32 hi = (o->f_4->f_24 << 12) & 0xFFFF000; hi |= t; n->f_4->f_2C = hi; }
            o->f_4->f_2C = 0x60000000;
            
        }}
    }
    return 0;
}

typedef struct { s32 x, y, z; u8 padC[0x14]; s16 f_20; u16 f_22; s16 f_24; u16 f_26; u8 pad28[4]; u32 f_2C; } Shape_78088;
typedef struct { u8 pad0[0x4C]; s16 f_4C; u8 pad4E[2]; u32 f_50; } Own_78088;
typedef struct Node_78088 { s16 kind; s16 id; Shape_78088 *shape; Own_78088 *owner; struct Node_78088 *next; } Node_78088;
typedef struct { s16 x; u16 y; u16 z; } SPt_78088;
typedef struct { u8 pad0[0x8296]; s16 f_8296; } Game_78088;
typedef struct { u8 pad0[0x70]; u32 f_70; } Sp_78088;
extern Game_78088 g_Game_78088 asm("g_Game");
extern Node_78088 *g_CollisionHead_78088 asm("g_CollisionHead");
extern Sp_78088 g_Spike_78088 asm("g_Spike");
extern u8 g_RcCar_78088[] asm("g_RcCar");
s32 Collision_KindOfOwner_78088(Own_78088 *) asm("Collision_KindOfOwner");
s32 Collider_GetCentre_78088(s16 k, Shape_78088 *s, SPt_78088 *out) asm("Collider_GetCentre");
s32 Collider_HitSound(s16, s16);
s32 func_80078C9C_78088(s32, s32 *, s16 *) asm("func_80078C9C");

s32 func_80078088(s32 kind_, Node_78088 *self_) {
    register s32 kind asm("$21") = kind_;
    s32 dmy_ = ({ __asm__("" : "=r"(kind) : "0"(kind)); 0; });
    register Node_78088 *self asm("$19") = self_;
    s32 dmy2_ = ({ __asm__("" : "=r"(self) : "0"(self)); 0; });
    SVECTOR sv;
    s16 flag;
    s32 *d = (s32 *)0x1F8000F0;
    SPt_78088 *pt = (SPt_78088 *)0x1F800100;
    s32 *q = (s32 *)0x1F800108;
    Own_78088 *owner;
    Node_78088 *n;
    s32 sk;
    s32 h;
    s32 dist;
    u16 hh;
    s32 lim;
    s32 ang;
    s32 mode;
    s32 r;
    u16 nk;
    s16 ok;
    u16 px;
    Shape_78088 *ns;

    if (self->shape->f_2C != 0) {
        return 0;
    }
    __asm__("" : "=r"(d) : "0"(d));
    owner = self->owner;
    sk = Collision_KindOfOwner_78088(owner);
    for (n = g_CollisionHead_78088; n != 0; n = n->next) {
        if (self == n) {
            continue;
        }
        if (n->kind <= 0) {
            continue;
        }
        if (n->kind >= 6) {
            continue;
        }
        h = n->shape->f_2C;
        if (h != 0 && (u32)h >> 28 >= 6 && (u32)h >> 28 != 10) {
            continue;
        }
        if (n->kind == 1 && owner != 0 && (owner->f_50 >> 28) == 8) {
            continue;
        }
        if ((void *)n->owner == &g_Spike_78088 && (void *)owner == g_RcCar_78088) {
            continue;
        }
        if (n->kind == 3 && (void *)owner != &g_Spike_78088 && (void *)owner != g_RcCar_78088) {
            continue;
        }
        if (n->kind == 4 && sk != 5 && (void *)owner != &g_Spike_78088 && (void *)owner != g_RcCar_78088) {
            continue;
        }
        ok = 0;
        if (owner == 0) {
            goto yes;
        }
        if (owner->f_4C != n->id && n->owner == 0) {
            goto yes;
        }
        if (owner == n->owner) {
            goto no;
        }
        if (n->owner == 0) {
            goto no;
        }
    yes:
        ok = 1;
    no:
        if (ok == 0) {
            continue;
        }
        ns = n->shape;
        Collider_GetCentre_78088(n->kind, ns, pt); __asm__("" :: "r"(n), "r"(n), "r"(n), "r"(n));
        d[0] = pt->x - self->shape->x;
        d[1] = (s16)pt->y - self->shape->y;
        d[2] = (s16)pt->z - self->shape->z;
        nk = n->kind;
        if ((u16)(nk - 6) < 2 || (s16)nk == 0xC || (s16)nk == 0xD) {
            if (Vec_Length(d[0], d[1], d[2]) < ns->f_20 + self->shape->f_20) {
                n->shape->f_2C = 0xB0000000;
                self->shape->f_2C = 0xB0000000;
            }
            continue;
        }
        dist = Vec_Length(d[0], 0, d[2]);
        hh = ns->f_22;
        if (n->kind == 1 && (g_Spike_78088.f_70 & 0xF0) == 0x80) {
            hh = (s16)hh / 3;
        }
        __asm__("" :: "r"(dist), "r"(dist));
        if (dist >= ns->f_20 + self->shape->f_20) {
            continue;
        }
        lim = self->shape->f_20 + ABS((s16)hh / 2);
        {
            s32 sy = (s16)pt->y;
            if ((sy - self->shape->y) >= 0) { if ((sy - self->shape->y) < lim) goto ok_78088; continue; } if ((self->shape->y - sy) >= lim) continue;
        ok_78088:;
        }
        if ((u32)(kind - 6) < 2 || kind == 0xC || kind == 0xD) {
            self->shape->f_2C = 0x60000000;
            ang = self->shape->f_24; ang <<= 12;
            if (n->kind == 1 && func_80098320() != 0) {
                { u32 t = (n->id & 0xFFF) | 0xB0000000; self->shape->f_2C = (ang & 0xFFFF000) | t; }
                if (self->owner != 0) {
                    self->owner->f_50 = self->shape->f_2C;
                }
            } else {
                { u32 t = (self->id & 0xFFF) | 0xB0000000; n->shape->f_2C = (ang & 0xFFFF000) | t; }
                if (self->owner != 0) {
                    self->owner->f_50 = 0x60000000;
                }
            }
        } else if (kind == 0xE) {
            n->shape->f_2C = 0xE0000000;
        } else if (kind == 0xF) {
            n->shape->f_2C = 0xF0000000;
        } else if (kind == 8) {
            if (n->kind == 3 && (n->shape->f_26 & 0x4000)) {
                continue;
            }
            if (self->owner != 0 && (self->owner->f_50 >> 28) == 8) {
                continue;
            }
            __asm__("" ::: "memory");
            if (n->kind == 3) {
                u32 hb = 0x80000000;
                n->shape->f_2C = (self->id & 0xFFF) | hb;
                self->shape->f_2C = (n->id & 0xFFF) | hb;
                if (self->owner != 0) {
                    self->owner->f_50 = n->id | hb;
                }
            }
        }
    }
    if (!(sk == 5 && kind == 6) && self->shape->f_2C != 0) {
        return 0;
    }
    mode = 0;
    if ((sk == 1 || sk == 5) && ((u32)(kind - 6) < 2 || kind == 0xC || kind == 0xD)) {
        mode = 1;
    } else if (sk == 3 && kind == 7) {
        mode = 2;
    } else if (sk == 4 && (self->shape->f_24 & 0xC00)) {
        mode = 3;
    }
    if (mode == 0) {
        goto out;
    }
    if (kind == 7) g_Game_78088.f_8296 = 2; else g_Game_78088.f_8296 = 1;
    px = self->shape->x;
    sv.vx = px;
    q[1] = sv.vy = self->shape->y + self->shape->f_20;
    q[2] = sv.vz = self->shape->z;
    q[3] = self->shape->f_20;
    q[4] = self->shape->f_20 * 2;
    D_800B20CC = 6;
    q[0] = (s16)px;
    { s32 m4 = mode << 16; r = func_80078C9C_78088(m4 | self->shape->f_24, q, &flag); }
    if (r >= 0) {
        register Shape_78088 *ssh asm("$5") = self->shape;
        if (ssh->f_2C == 0) {
            ssh->f_2C = 0xA0000000;
        }
        if (flag != 0) {
            s32 snd = Collider_HitSound(sk, r);
            if (snd != 0x29) {
                Sound_PlayAt(snd, &sv);
            }
        }
    }
    g_Game_78088.f_8296 = 0;
out:
    return 0;
}

s32 Collider_HitSound(s16 a, s16 b) {
    s32 v;
    if (a == 3) {
        return 0x29;
    }
    v = Link_GetKindSound(b);
    if (v < 0 || v == 0x80 || v == 0x82 || v == 0x81) {
        return 0x29;
    }
    return v;
}

s32 Collision_KindOfOwner(S_78864_80078864 *a) {
    S_20D8_80078864 *p;
    S_20D8_80078864 *next;
    if (a == 0) {
        return -1;
    }
    for (p = g_CollisionHead; p != 0; p = next) {
        next = p->f_C;
        if (a->f_4C == p->f_2) {
            return p->f_0;
        }
    }
    return -1;
}

s32 Pickup_CheckTouch(s32 unused, S_O_800788B8_800788B8 *o) {
    S_Sc_800788B8_800788B8 *sc = (S_Sc_800788B8_800788B8 *)0x1F8000F0;
    S_Node_800788B8_800788B8 *n;
    S_X_800788B8_800788B8 *x;
    if (o->f_4->f_2C != 0) {
        return 0;
    }
    for (n = (*(S_Node_800788B8_800788B8 * *)&g_CollisionHead); n != 0; n = n->f_C) {
        if ((u16)(n->f_0 - 1) < 2 || n->f_0 == 8 || n->f_0 == 13) {
            x = n->f_4;
            Collider_GetCentre(n->f_0, x, sc);
            if (Vec_Length(sc->vx - o->f_4->f_0, (s16)sc->vy - o->f_4->f_4, (s16)sc->vz - o->f_4->f_8) < x->f_20 + o->f_4->f_20) {
                Pickup_Collect(o->f_4->f_24);
                o->f_4->f_2C = (n->f_0 << 28) | (n->f_2 & 0xFFF);
                return 0;
            }
        }
    }
    return 0;
}

void Pickup_Collect(s16 type) {
    s32 n;
    s32 chips;
    s32 a;
    if (type == 4) { Sound_PlayFixed(0xE); } else if (type == 2) { Sound_PlayFixed(0xD); } else { Sound_PlayFixed(0x7A); }
    switch (type) {
    case 1:
        Spike_Heal(1);
        break;
    case 2:
        if (++GM_78A18->lives > 100) {
            GM_78A18->lives = 100;
        }
        Hud_ShowLives(0, 1);
        break;
    case 3:
    case 5:
        if (GM_78A18->mode == 0x13) {
            TimeTrial_AddClockStop(type == 3 ? 1 : 5);
            break;
        }
        chips = GM_78A18->chips;
        n = type == 5 ? 5 : 1;
        chips += n;
        ((struct Hud_80078A18 *)&g_HudState)->f_2 = n;
        ((struct Hud_80078A18 *)&g_HudState)->f_3 = 3;
        if (chips >= 100) {
            chips -= 100;
            if (++GM_78A18->lives > 100) {
                GM_78A18->lives = 100;
            }
            Sound_PlayFixed(0xD);
            Hud_ShowLives(0, 1);
        }
        GM_78A18->chips = chips;
        Hud_ShowChips(0);
        break;
    case 4:
        if (++GM_78A18->coins > 60) {
            GM_78A18->coins = 60;
        }
        SpecterCoin_Add(GM_78A18->stage);
        break;
    case 6:
        a = GS_78A18->explosive;
        if (a < GM_78A18->explosiveMax) {
            a++;
        }
        GS_78A18->explosive = a;
        break;
    case 7:
        a = GS_78A18->guided;
        if (a < GM_78A18->guidedMax) {
            a++;
        }
        GS_78A18->guided = a;
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80071D20_collide", jtbl_800A5EA8_pad);


typedef struct { u8 pad0[0xC]; u16 f_C; s16 f_E; u8 pad10[2]; s16 f_12; } Tile_78C9C;
typedef struct { u8 pad0[0xC]; Tile_78C9C *f_C; } Probe_78C9C;
typedef struct { u8 pad0[0x10]; u16 f_10; u8 pad12[2]; u16 f_14; u16 f_16; u8 pad18[6]; s16 f_1E; u8 pad20[0x18]; } Obj_78C9C;
typedef struct { s32 x, y, z, f_C, f_10; } Q_78C9C;
typedef struct { u8 pad0[0x820C]; Obj_78C9C *f_820C; u8 pad8210[0x74]; u16 f_8284; } Game_78C9C;
extern Game_78C9C g_Game_78C9C asm("g_Game");
extern Probe_78C9C *D_800B20B0_78C9C asm("Coll_Cells");
extern s32 *D_800B20B4_78C9C asm("Coll_Pos");
extern Obj_78C9C *D_800B20BC;
s32 func_80079A28(s16 type, s16 flag);
s32 Contact_Add(s32 a, s32 b);
s32 Contact_IsNew(s16 a, s32 b);

s32 func_80078C9C(s32 arg, Q_78C9C *q, s16 *out) {
    s16 *hit = (s16 *)0x1F8003F0;
    s32 *pt = (s32 *)0x1F800114;
    s32 *res = (s32 *)0x1F800124;
    u32 mode;
    s16 i;
    s32 r;
    Probe_78C9C *p;
    Obj_78C9C *o;

    mode = (u32)arg >> 16;
    r = -1;
    D_800B20B4_78C9C[0] = q->x;
    D_800B20B4_78C9C[1] = q->y;
    D_800B20B4_78C9C[2] = q->z;
    *out = 0;
    pt[0] = q->f_C;
    pt[2] = q->f_10;
    for (i = 7; i >= 0; i--) {
        p = (Probe_78C9C *)((i << 4) + (s32)D_800B20B0_78C9C);
        if (p->f_C == 0) {
            continue;
        }
        pt[1] = p->f_C->f_12;
        { s32 k = (u16)p->f_C->f_12 >> 12;
        res[0] = 0;
        res[5] = 0;
        res[4] = 0;
        res[3] = 0;
        res[2] = 0;
        res[1] = 0;
        if (D_800B20E0[k](&D_800B20B0_78C9C[i], pt, res) == 0) {
            continue;
        } }
        if (mode == 2 && (D_800B20B0_78C9C[i].f_C->f_C & 0x2000)) {
            continue;
        }
        if (func_80079A28(D_800B20B0_78C9C[i].f_C->f_12, D_800B20B0_78C9C[i].f_C->f_C & 0x8000) == 0) {
            continue;
        }
        r = D_800B20B0_78C9C[i].f_C->f_E;
        if (mode != 0 && Contact_IsNew(1, (s32)D_800B20B0_78C9C[i].f_C) == 0) {
            continue;
        }
        *out = 1;
        if (mode != 0) {
            Contact_Add(1, (s32)D_800B20B0_78C9C[i].f_C);
        }
    }
    for (i = g_Game_78C9C.f_8284 - 1; i >= 0; i--) {
        if (Coll_NearObjects[i] != 0) {
            continue;
        }
        *D_800B20BC = *(Obj_78C9C *)(i * 56 + (s32)g_Game_78C9C.f_820C);
        { Obj_78C9C *e = D_800B20BC;
        pt[1] = e->f_10;
        {
        s32 k = (e->f_10 & 0xF000) >> 10;
        res[5] = 0;
        res[4] = 0;
        res[3] = 0;
        res[2] = 0;
        res[1] = 0;
        { s32 (*fn)(Obj_78C9C *, s32 *, s32 *) = *(s32 (**)(Obj_78C9C *, s32 *, s32 *))((u8 *)D_800B2108 + k);
        res[0] = 0;
        if (fn(D_800B20BC, pt, res) == 0) {
            continue;
        } }
        }
        if (0) {
            continue;
        }}
        if (func_80079A28(D_800B20BC->f_10, D_800B20BC->f_14 & 0x8000) == 0) {
            continue;
        }
        if (mode == 2 && (D_800B20BC->f_14 & 0x2000)) {
            continue;
        }
        r = D_800B20BC->f_16;
        if (mode == 1) {
            if (Contact_IsNew(2, (s32)&g_Game_78C9C.f_820C[i]) != 0) {
                *out = mode;
                Contact_Add(2, (s32)&g_Game_78C9C.f_820C[i]);
                D_800B20BC->f_1E = arg;
                g_Game_78C9C.f_820C[i] = *D_800B20BC;
            }
            if (r == 10) {
                return r;
            }
            continue;
        }
        if (mode - 2 < 2) {
            if (Contact_IsNew(2, (s32)&g_Game_78C9C.f_820C[i]) != 0) {
                *out = 1;
                Contact_Add(2, (s32)&g_Game_78C9C.f_820C[i]);
            }
        }
        return r;
    }
    if (r >= 0) {
        return r;
    }
    if (Floor_GetHeight(q->x, q->y - q->f_C, q->z) < q->y - q->f_C && hit[0] < 0) {
        r = (s16)hit[5];
        if (mode != 0 && Contact_IsNew(0, 0) == 0) {
            return r;
        }
        *out = 1;
        if (mode != 0) {
            Contact_Add(0, 0);
        }
    }
    return r;
}

/* Finds the stage zone containing point p: walks the zone list (g_Game+0x820C, count +0x8284)
 * backwards and writes each containing zone's index to p->f_34, so the lowest index wins. Zone
 * shape comes from +0x10 & 0xF000 (0 box, 0x2000 shaped box, 0x3000 cylinder or special shapes,
 * 0x4000 diagonal box). For mode 1 (Spike) nothing is found in some Spike states. Returns 0. */
s32 Zone_FindIndexAt(P_792C8_800792C8 *p, s16 mode) {
    void *f = (void *)0x1F8000F0;
    s32 *d = (s32 *)0x1F8000FC;
    V3_792C8_800792C8 *e = (V3_792C8_800792C8 *)0x1F800108;
    A_792C8_800792C8 *a;
    s16 i;
    u32 k;
    s32 t;

    if (mode == 1) {
        if ((g_Spike.f_70 & 0xF0) == 0xE0) {
            return 0;
        }
        if (g_Spike.f_5E == 0x23 || g_Spike.f_5E == 0x4A || g_Spike.f_5E == 0x2D) {
            return 0;
        }
    }
    if (GM_792C8->f_8150 == 6 && mode == 1) {
        return 0;
    }
    for (i = GM_792C8->f_8284 - 1; i >= 0; i--) {
        a = &GM_792C8->f_820C[i];
        if ((a->f_18 & 0xF) == 3 || (a->f_18 & 0x8000) || a->f_12 == 9) {
            continue;
        }
        k = a->f_10 & 0xF000;
        if (k == 0x3000) {
            t = a->f_10 & 0xFF;
            if ((u32)(t - 0x46) < 4) {
                continue;
            }
            if ((u32)(t - 0x24) < 2) {
                d[0] = p->x - a->x;
                d[1] = p->y - a->y;
                d[2] = p->z - a->z;
                if (Coll_HalfCylinderHeight(t, &a->f_6, (V3_792C8_800792C8 *)d, e) == 0) {
                    continue;
                }
                if (p->y < a->y - e->x || a->y + e->x < p->y) {
                    continue;
                }
                p->f_34 = i;
                continue;
            }
            if ((u32)(t - 0x53) < 2) {
                d[0] = p->x - a->x;
                d[1] = p->y - a->y;
                d[2] = p->z - a->z;
                if (Surface_CylinderHeight(t, &a->f_6, (V3_792C8_800792C8 *)d, e) == 0) {
                    continue;
                }
                if (p->y < a->y - e->x || a->y - e->x + 0x40 < p->y) {
                    continue;
                }
                p->f_34 = i;
                continue;
            }
            if ((a->x - p->x) * (a->x - p->x) + (a->z - p->z) * (a->z - p->z) >= a->f_6 * a->f_6) {
                continue;
            }
            if (p->y < a->y - a->f_8 || a->y < p->y) {
                continue;
            }
            p->f_34 = i;
        } else if (k == 0x4000) {
            if (p->x < a->x - a->f_6 || a->x + a->f_6 < p->x || p->z < a->z - a->f_A || a->z + a->f_A < p->z
                || p->y < a->y - a->f_8 || a->y < p->y) {
                continue;
            }
            *(s32 *)(*(V3_792C8_800792C8 * *)&Coll_Pos) = p->x;
            (*(V3_792C8_800792C8 * *)&Coll_Pos)->y = p->y;
            (*(V3_792C8_800792C8 * *)&Coll_Pos)->z = p->z;
            if (Geo_DiagonalDistance(a->f_10, (*(V3_792C8_800792C8 * *)&Coll_Pos), a, f) <= 0) {
                p->f_34 = i;
            }
        } else if (k == 0x2000) {
            if (p->x < a->x - a->f_6 || a->x + a->f_6 < p->x || p->z < a->z - a->f_A || a->z + a->f_A < p->z
                || p->y < a->y - a->f_8 || a->y < p->y) {
                continue;
            }
            *(s32 *)(*(V3_792C8_800792C8 * *)&Coll_Pos) = p->x;
            (*(V3_792C8_800792C8 * *)&Coll_Pos)->y = p->y;
            (*(V3_792C8_800792C8 * *)&Coll_Pos)->z = p->z;
            if (Surface_QueryShape((u8)a->f_10, a, (*(V3_792C8_800792C8 * *)&Coll_Pos), e) == 0) {
                continue;
            }
            if (p->y < a->y - e->y || a->y < p->y) {
                continue;
            }
            p->f_34 = i;
        } else if (k == 0) {
            if (p->x < a->x - a->f_6 || a->x + a->f_6 < p->x || p->z < a->z - a->f_A || a->z + a->f_A < p->z
                || p->y < a->y - a->f_8 || a->y < p->y) {
                continue;
            }
            p->f_34 = i;
        }
    }
    return 0;
}

typedef struct { s16 x, y, z, f_6, f_8, f_A; u8 padC[6]; u16 f_12; u16 f_14; u16 f_16; u16 f_18; u8 pad1A[2]; u16 f_1C; u8 pad1E[0xC]; s16 f_2A; s16 f_2C; s16 f_2E; u8 pad30[8]; } A_79828;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u16 f_6; s16 x; s16 y; s16 z; s16 f_E; s16 f_10; s16 f_12; s16 f_14; s16 f_16; s16 f_18; } W_79828;
extern struct { u8 pad0[0x820C]; A_79828 *f_820C; u8 pad8210[0x74]; u16 f_8284; u8 pad8286[0xE]; s16 f_8294; } g_Game_79828 asm("g_Game");

s32 Water_Query(s32 x, s32 y, s32 z)
{
    W_79828 *w = (W_79828 *)0x1F8003D4;
    A_79828 *a;
    s16 i;
    s16 s;
    s16 mode;
    u32 t2e;
    u16 fl;
    u16 k;
    u16 ret = 0;
    w->f_0 = 0;
    w->f_2 = 0;
    w->f_4 = 0;
    w->f_6 = 0;
    w->x = 0;
    w->y = 0;
    w->z = 0;
    w->f_E = 0;
    w->f_10 = 0;
    w->f_12 = 0;
    w->f_14 = 0;
    w->f_16 = 0;
    w->f_18 = 0;
    g_Game_79828.f_8294 = -1;
    for (i = g_Game_79828.f_8284 - 1; i >= 0; i--) {
        a = &g_Game_79828.f_820C[i];
        fl = a->f_12;
        if ((u8)fl != 9) continue;
        if (x < a->x - a->f_6 || a->x + a->f_6 < x || z < a->z - a->f_A || a->z + a->f_A < z) continue;
        if (y < a->y - a->f_8 || a->y < y) continue;
        k = (fl & 0xF00) << 4;
        s = a->y - a->f_8;
        w->f_10 = a->f_8;
        if (y >= s && y - 0x40 < s) {
            mode = 2;
        } else if (y - 0x40 >= s && y - 0xC0 < s) {
            mode = 1;
        } else {
            mode = 0;
        }
        w->f_0 = k | mode;
        w->f_2 = a->f_1C;
        w->f_4 = a->f_14;
        w->f_6 = a->f_16;
        w->x = a->x;
        w->y = a->y;
        w->z = a->z;
        w->f_E = a->f_6;
        w->f_12 = a->f_A;
        w->f_14 = a->f_2A * 4096;
        ret = w->f_0;
        w->f_16 = a->f_2C * 4096;
        t2e = a->f_2E;
        g_Game_79828.f_8294 = i;
        w->f_18 = t2e * 4096;
        break;
    }
    return ret;
}

struct Game_79A28 { u8 pad0[0x8296]; s16 f_8296; };
#define GM_79A28 ((struct Game_79A28 *)&g_Game)
s32 func_80079A28(s16 type, s16 flag) {
    u16 special;
    u16 kind;
    s32 t;

    if (GM_79A28->f_8296 == 1) {
        return 1;
    }
    special = 0;
    kind = type & 0xFF;
    t = type & 0xF000;
    if (t == 0x1000 || t == 0x5000 || t == 0x6000 || t == 0x7000 || t == 0x8000 ||
        (t == 0x3000 && ((u32)((type & 0xFF) - 0x4E) < 4 || kind == 0x36))) {
        special = 1;
    }
    if (GM_79A28->f_8296 == 0) {
        if (special == 0) goto one;
        if (flag != 0) goto one;
    zero:
        return 0;
    }
    if (special != 0) {
        if (flag == 0) goto zero;
    } else {
        if (flag != 0) goto zero;
    }
one:
    return 1;
}
