#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { u8 pad0[0xA]; u16 f_A; } S_Mdl_800845E0;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 padA; u8 f_B; } S_846D8_800845E0;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_800845E0;
typedef struct { u8 pad0[0xA]; u16 f_A; } S_Mdl_800846D8;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 padA; u8 f_B; } S_846D8_800846D8;
typedef struct { u16 x, y, z; } Pos_83470_80083470;
typedef struct { u16 kind; u16 x; u16 y; u16 z; u8 pad8[8]; } Rec_83470_80083470;
typedef struct { u16 m0; u16 m1; u16 count; u16 pad6; Rec_83470_80083470 recs[1]; } Hdr_83470_80083470;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 kind; u8 f_B; u8 padC[0xB]; u8 blink; } Pk_8435C_8008435C;
typedef struct { s16 vx, vy, vz, pad; } SV_8435C_8008435C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Spk_8435C_8008435C;

extern u16 g_RandSeed;
extern s32 D_800F51C4;

extern struct S_D_800BF2B8 { s32 f_0; } Pickup_AreaMasks[];

void Pickup_UpdateAll(void);
void Pickup_DrawAll(void);
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; } g_Game;
extern struct S_D_800BEFA0 { u8 pad0[0xA]; u8 f_A; u8 padB[0xD]; } D_800BEFA0[];
extern u8 D_800BF2D8[32];
extern char D_800A6160[];
s32 World_FirstStage(s32);
void bios_printf(const char *, ...);
struct S_D_800EC350_800847EC { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; };
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } g_ViewMatrix;
extern struct S_D_800F4C30 { S_Mdl_800845E0 *f_0; u8 pad4[0xC]; } D_800F4C30[];
extern u8 g_ProjVerts[];
void Matrix_SetIdentity(struct S_D_800E78C0 *);
void Matrix_RotateY(s32, struct S_D_800E78C0 *);
void CompMatrix(struct S_D_800E78C0 *, struct S_D_800E78C0 *, struct S_D_800E78C0 *);
void Model_ProjectVerts(struct S_D_800F4C30 *, struct S_D_800E78C0 *, u8 *);
void Model_Draw(u32 *, u8 *, struct S_D_800F4C30 *);
struct S_D_800EC350_800845E0 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_800845E0 db[2]; };
extern u32 *g_GameOt;
void Model_CalcEnvMapUVs64(struct S_D_800F4C30 *);
void Model_DrawEnvMapped(u32 *, u8 *, struct S_D_800F4C30 *);
struct S_D_800F4C30_800846D8 { S_Mdl_800846D8 *f_0; u8 pad4[0xC]; };
struct Game_83470 { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; u8 pad8128[0x120]; Hdr_83470_80083470 *f_8248; };
extern u8 D_800B2920[];
extern u8 D_800BF2F8;
extern u8 Pickup_Kind2Cooldown;
extern u8 D_800B28B1;
extern u8 g_SpecterCoinTimer;
extern u8 D_800BF2B5;
s32 SpecterCoin_IsCollected(s32);
void Pickup_Spawn(s32 kind, Pos_83470_80083470 *pos, s32 mode, s32 slot);

/* Clears the 32 pickup slots, then, if the loaded area data (g_Game+0x8248) starts with the tag
 * 0x492E 0x4D54 (marked as read by overwriting its first byte), spawns its pickups: 16-byte
 * records (kind, x, y, z; kind 0xFF ends the list), skipping those whose bit is set in this
 * area's collected mask Pickup_AreaMasks[area] and the Specter coin (kind 4) when this stage's is already collected (SpecterCoin_IsCollected). Then picks the
 * stage's drop table D_800BF2F8 (D_800B2920[stage], at most 4) and resets the drop counters. */
extern Pk_8435C_8008435C D_800BF2A0;
extern Spk_8435C_8008435C g_Spike;
extern s32 D_800EBFC8;
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void Effect_SpawnAt(s32, void *);
void Pickup_DrawModel(s32 i, S_846D8_800845E0 *o);
void Pickup_DrawModelEnvMap(s32 i, S_846D8_800846D8 *o);
extern u16 g_RandSeed2;
typedef struct { u8 pad0[0x813C]; u16 f_813C; } Game_83790;

void Pickup_SpawnArea(void) {
    Pos_83470_80083470 pos;
    Hdr_83470_80083470 *hdr;
    s32 i;
    s32 a;
    u32 mask;
    Rec_83470_80083470 *r;

    hdr = (*(struct Game_83470 *)&g_Game).f_8248;
    r = hdr->recs;
    for (i = 31; i >= 0; i--) {
        D_800BEFA0[i].f_A = 0;
        D_800BF2D8[i] = 0;
    }
    if ((u32)(*(struct Game_83470 *)&g_Game).f_8248 == 0x80154000) {
        return;
    }
    if (hdr->m0 != 0x492E) {
        return;
    }
    if (hdr->m1 != 0x4D54) {
        return;
    }
    *(u8 *)hdr = 0x78;
    a = (*(struct Game_83470 *)&g_Game).f_8126 - World_FirstStage((*(struct Game_83470 *)&g_Game).f_8124);
    if (a >= 8) {
        bios_printf(D_800A6160);
        a = 0;
    }
    i = 0;
    mask = ((u32 *)&Pickup_AreaMasks)[a];
    D_800B28B1 = 1;
    for (; i < hdr->count; i++, r++) {
        if (r->kind == 0xFF) {
            break;
        }
        pos.x = r->x;
        pos.y = r->y;
        pos.z = r->z;
        if (!(mask & 1)) {
            if (r->kind == 4) {
                if (SpecterCoin_IsCollected((*(struct Game_83470 *)&g_Game).f_8126) == 0) {
                    Pickup_Spawn(4, &pos, 0, i);
                    D_800BF2D8[i] = 1;
                }
            } else {
                Pickup_Spawn(r->kind, &pos, 0, i);
                D_800BF2D8[i] = 1;
            }
        }
        mask >>= 1;
    }
    D_800BF2F8 = D_800B2920[(*(struct Game_83470 *)&g_Game).f_8124];
    if (D_800BF2F8 >= 5) {
        D_800BF2F8 = 4;
    }
    Pickup_Kind2Cooldown = 3;
    g_SpecterCoinTimer = 0;
    D_800BF2B5 = 0;
    D_800B28B1 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80083470_pickup", D_800A6160);


void Pickup_SetCollShape(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 6);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 8);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x24) = (s16) M2C_FIELD(arg0, u8 *, 0xA);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x26) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x20) = 0x80;
}

s32 Pickup_RollAmmoDrop(void) {
    s32 ret = 7;
    u16 r = g_RandSeed * 5 + 1;
    u8 bit;
    g_RandSeed = r;
    bit = (r >> 8) & 1;
    if (!(D_800F51C4 & 8)) {
        return 3;
    }
    if (bit) {
        ret = 6;
    }
    return ret;
}

/* Pickup_RollKind2Drop: pick the item for a kind-2 drop (Pickup_Drop): roll 1..25 and return 5 when the
 * roll is below (n - 1) * 10, n = g_Game+0x813C (the lives counter? 5 at a new game) clamped to
 * 1..10, else 2. While the cooldown Pickup_Kind2Cooldown runs it returns 5; otherwise it restarts it at 9. */
s32 Pickup_RollKind2Drop(void) {
    s32 ret = 2;
    u16 r = g_RandSeed2 * 5 + 1;
    u8 p = ((u32)((r >> 8) * 25) >> 6) + 1;
    s32 n;
    s32 c;
    g_RandSeed2 = r;
    n = ((Game_83790 *)&g_Game)->f_813C;
    if (Pickup_Kind2Cooldown != 0) {
        return 5;
    }
    Pickup_Kind2Cooldown = 9;
    c = (n <= 0) ? 1 : (n >= 11) ? 10 : n;
    if (p < (c - 1) * 10) {
        ret = 5;
    }
    return ret;
}

typedef struct { s32 f_0; s16 x, y, z; u8 kind; u8 f_B; s16 vx, vy, vz; u8 pad12[2]; u8 f_14; u8 f_15; u8 pad16; u8 f_17; } Pk_80083844;
extern Pk_80083844 D_800BEFA0_83844[] asm("D_800BEFA0");

void Pickup_Spawn(s32 kind, Pos_83470_80083470 *pos, s32 mode, s32 slot) {
    Pk_80083844 *p;
    s32 i;
    i = 0x1F;
    p = D_800BEFA0_83844;
    for (; i >= 0; i--, p++) {
        if (slot >= 0) {
            p = &D_800BEFA0_83844[slot];
        } else if (p->kind != 0) {
            continue;
        }
        p->kind = kind;
        p->f_15 = 0;
        p->f_0 = 0;
        p->f_B = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F;
        p->f_14 = 0;
        p->f_17 = 0;
        switch (mode) {
        case 0:
        default:
            p->x = pos->x;
            p->y = pos->y;
            p->z = pos->z;
            p->vz = 0;
            p->vy = 0;
            p->vx = 0;
            p->f_14 = 1;
            return;
        case 1:
            p->x = pos->x + rcos(((g_RandSeed = g_RandSeed * 5 + 1) >> 4) & 0xFF0) / 16;
            p->y = pos->y;
            p->z = pos->z + rsin(((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 4) & 0xFF0) / 16;
            p->vy = 0xC;
            p->vz = 0;
            p->vx = 0;
            return;
        case 2:
            p->x = pos->x;
            p->y = pos->y;
            p->z = pos->z;
            p->vz = 0;
            p->vx = 0;
            p->vy = -0x3E;
            return;
        case 3:
            p->x = pos->x;
            p->y = pos->y;
            p->z = pos->z;
            p->vx = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F) - 0x10;
            p->vz = (((g_RandSeed2 = g_RandSeed2 * 5 + 1) >> 8) & 0x1F) - 0x10;
            p->vy = 0xFFE1 - (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0x1F);
            return;
        }
    }
}

extern u8 D_800B28A2_83AA8[][25] asm("D_800B28A2");
extern u8 D_800B28B4[];
extern s16 g_SpikeHealth;
s32 Game_IsTimed(void);

void Pickup_Drop(s32 type, Pos_83470_80083470 *pos, s32 mode, s32 table) {
    s32 kind;
    u8 cum[5];
    s32 n = 1;
    s32 i;
    u8 sum;
    u8 *t;
    u8 *c;
    u16 r;
    if (table == 0) {
        kind = type;
        if (D_800B28B1 == 0 && Game_IsTimed()) {
            kind = 3;
        }
    } else {
        sum = 0;
        if (table == 1) {
            table = D_800BF2F8;
        }
        i = 0;
        c = cum;
        {
            u8 *row = D_800B28A2_83AA8[table];
            t = &row[g_SpikeHealth];
        }
        for (; i < 5; i++) {
            sum += *t;
            c[i] = sum;
            t += 5;
        }
        kind = 1;
        r = g_RandSeed2 * 5 + 1;
        sum = ((u32)((r >> 8) * 25) >> 6) + 1;
        g_RandSeed2 = r;
        for (i = 0; i < 5; i++) {
            if (sum < cum[i]) {
                kind = D_800B28B4[i];
                break;
            }
        }
        if (kind == 7) {
            kind = Pickup_RollAmmoDrop();
        } else if (kind == 2) {
            kind = Pickup_RollKind2Drop();
        } else if (kind == 3) {
            n = (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) + 2;
        }
        if (Pickup_Kind2Cooldown != 0) {
            Pickup_Kind2Cooldown--;
        }
        if (Game_IsTimed()) {
            kind = 3;
            n = 2;
        }
    }
    for (; n > 0; n--) {
        Pickup_Spawn(kind, pos, mode, -1);
    }
}

s32 Floor_GetHeight_PU() asm("Floor_GetHeight");
typedef struct { s16 vx, vy, vz, pad; } SV_80083CB8;
typedef struct { s32 x, y, z; u8 padC[0x20]; u32 f_2C; } Col_80083CB8;
typedef struct { Col_80083CB8 *col; s16 x; s16 y; s16 z; u8 kind; u8 spin; s16 vx; s16 vy; s16 vz; s16 gy; u8 state; u8 age; u8 timer; u8 fade; } Item_80083CB8;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s32 f_70; } Body_80083CB8;
extern u8 D_800BEFA0_83CB8[] asm("D_800BEFA0");
extern u8 g_Spike_83CB8[] asm("g_Spike");
extern u8 g_RcCar_83CB8[] asm("g_RcCar");
Col_80083CB8 *CollShape_Alloc(void);
void Pickup_SetCollShape(void *arg0);
s32 Collision_Set(s32, void *, void *);
s32 CollShape_Free(void *);
s32 Collision_Remove(void *);
void Fx_SpawnFadeRing(void *, s32, s32, s32);
void CenterSign_ShowSpecterCoin(void);
s32 Floor_GetHeight(s32, s32, s32);

void Pickup_UpdateAll(void)
{
  Item_80083CB8 *it;
  s32 i;
  s32 j;
  register s32 d asm("$3");
  s32 t;
  s32 k80;
  i = 31;
  it = (Item_80083CB8 *) D_800BEFA0_83CB8;
  for (; i >= 0; i--, it++)
  {
    if (it->kind == 0)
    {
      continue;
    }
    if (it->state < 2)
    {
      t = 0;
      if ((((((((Body_80083CB8 *) (g_Spike_83CB8))->x - it->x) >= 0) ? (((Body_80083CB8 *) (g_Spike_83CB8))->x - it->x) : (-(((Body_80083CB8 *) (g_Spike_83CB8))->x - it->x))) < 0x200) && ((((((Body_80083CB8 *) (g_Spike_83CB8))->z - it->z) >= 0) ? (((Body_80083CB8 *) (g_Spike_83CB8))->z - it->z) : (-(((Body_80083CB8 *) (g_Spike_83CB8))->z - it->z))) < 0x200)) && (({ register s32 _t asm("$2") = it->y; d = _t + 0x80; }), ((((((Body_80083CB8 *) (g_Spike_83CB8))->y - d) >= 0) ? (((Body_80083CB8 *) (g_Spike_83CB8))->y - d) : ({ s32 _r = -(((Body_80083CB8 *) (g_Spike_83CB8))->y - d); __asm__("" : : "r"(d)); _r; })) < 0x200)))
      {
        t = 1;
      }
      if ((((Body_80083CB8 *) (g_RcCar_83CB8))->f_70 != 0) && (!t))
      {
        if ((((((((Body_80083CB8 *) (g_RcCar_83CB8))->x - it->x) >= 0) ? (((Body_80083CB8 *) (g_RcCar_83CB8))->x - it->x) : (-(((Body_80083CB8 *) (g_RcCar_83CB8))->x - it->x))) < 0x200) && ((((((Body_80083CB8 *) (g_RcCar_83CB8))->z - it->z) >= 0) ? (((Body_80083CB8 *) (g_RcCar_83CB8))->z - it->z) : (-(((Body_80083CB8 *) (g_RcCar_83CB8))->z - it->z))) < 0x200)) && (({ register s32 _t asm("$2") = it->y; d = _t + 0x80; }), ((((((Body_80083CB8 *) (g_RcCar_83CB8))->y - d) >= 0) ? (((Body_80083CB8 *) (g_RcCar_83CB8))->y - d) : ({ s32 _r = -(((Body_80083CB8 *) (g_RcCar_83CB8))->y - d); __asm__("" : : "r"(d)); _r; })) < 0x200)))
        {
          t = 1;
        }
      }
      if (it->col == 0)
      {
        if (t)
        {
          Col_80083CB8 *c = CollShape_Alloc();
          it->col = c;
          if (c != 0)
          {
            Pickup_SetCollShape(it);
            if (Collision_Set(9, it->col, 0) < 0)
            {
              CollShape_Free(it->col);
              it->col = 0;
            }
          }
        }
      }
      else
        if (!t)
      {
        CollShape_Free(it->col);
        Collision_Remove(it->col);
        it->col = 0;
      }
    }
    if (it->col != 0)
    {
      switch (it->col->f_2C >> 28)
      {
        case 0:
          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 8:

        case 11:

        case 12:

        case 13:
          CollShape_Free(it->col);
          Collision_Remove(it->col);
          it->col = 0;
          it->state = 2;
          it->vy = -0x50;
          it->timer = 10;
          it->fade = 0;
          if ((it->kind == 2) || (it->kind == 4))
        {
          Fx_SpawnFadeRing(&it->x, 4, 0x200, 0);
          Effect_SpawnAt(0x113, &it->x);
          Effect_SpawnAt(0x109, &it->x);
          for (j = 0; j < 20; j++)
          {
            Effect_SpawnAt(0x25, &it->x);
          }

          if (it->kind == 4)
          {
            g_SpecterCoinTimer = 0x20;
            it->kind = 0;
            CenterSign_ShowSpecterCoin();
          }
        }
        else
        {
          Effect_SpawnAt(0x103, &it->x);
        }
          break;

      }

    }
    if (it->kind == 0)
    {
      continue;
    }
    switch (it->state)
    {
      case 0:
        it->x += it->vx;
        it->y += it->vy;
        it->z += it->vz;
        it->vy += 7;
        it->gy = Floor_GetHeight_PU(it->x, it->y, it->z) - 0x40;
        if (it->y >= it->gy)
      {
        if (((it->y - it->gy) > 0x80) && (it->vx | it->vz))
        {
          it->x -= it->vx;
          it->z -= it->vz;
          it->vx = (-it->vx) / 2;
          it->vz = (-it->vz) / 2;
        }
        else
        {
          it->y = it->gy;
          it->vy = (-it->vy) / 3;
          if (it->vy >= (-14))
          {
            it->state = 1;
            it->fade = 0xF0;
          }
        }
        Effect_SpawnAt(4, &it->x);
      }
        if (it->age >= 0x5A)
      {
        it->state = 1;
        it->fade = 0xF0;
      }
        break;

      case 1:
        if (it->fade != 0)
      {
        if ((--it->fade) == 0)
        {
          it->kind = 0;
          if (it->col != 0)
          {
            CollShape_Free(it->col);
            Collision_Remove(it->col);
            it->col = 0;
          }
        }
      }
        break;

      case 2:
        it->y += it->vy;
        it->vy += 0xC;
        if ((--it->timer) == 0)
      {
        it->state = 3;
        it->timer = 8;
      }
        break;

      case 3:
        it->spin += it->timer;
        if ((--it->timer) == 0)
      {
        it->kind = 0;
        Effect_SpawnAt(0x104, &it->x);
      }
        break;

    }

    if (it->kind != 0)
    {
      if ((it->state < 2) && (it->col != 0))
      {
        it->col->x = it->x;
        it->col->y = it->y;
        it->col->z = it->z;
      }
      it->age++;
      it->spin++;
    }
  }

}



/* Draws every live pickup: those blinking out (timer +0x17 in 1..45) skip odd frames; culled by
 * RotTransPers depth (<= min(D_800EBFC8, 0x800)) and screen bounds, then the kind (1-7) picks the
 * model (0xD-0x13) and drawer (Pickup_DrawModel or Pickup_DrawModelEnvMap). While g_SpecterCoinTimer counts down it
 * also draws model 0xD spinning down onto Spike, with effect 0x104 every 8th frame. */
void Pickup_DrawAll(void) {
    SV_8435C_8008435C pos;
    s32 sxy;
    s32 flag;
    s32 z;
    s32 maxz;
    s32 i;
    Pk_8435C_8008435C *p;
    Pk_8435C_8008435C *q;
    s32 y;

    maxz = 0x800;
    if (D_800EBFC8 < 0x800) {
        maxz = D_800EBFC8;
    }
    for (i = 31, p = ((Pk_8435C_8008435C *)&D_800BEFA0); i >= 0; i--, p++) {
        if (p->kind == 0) {
            continue;
        }
        if (p->blink - 1U < 45 && !(p->blink & 1)) {
            continue;
        }
        SetRotMatrix(((u8 *)&g_ViewMatrix));
        SetTransMatrix(((u8 *)&g_ViewMatrix));
        z = RotTransPers(&p->f_4, &sxy, &flag, &flag);
        if (z > maxz || z <= 0) {
            continue;
        }
        y = sxy;
        if ((u32)((s16)sxy + 0x20) >= 0x1C1) {
            continue;
        }
        y >>= 16;
        if (y < -0x20) {
            continue;
        }
        if (y >= 0x111) {
            continue;
        }
        switch (p->kind) {
        case 4:
            Pickup_DrawModelEnvMap(0xD, p);
            break;
        case 1:
            Pickup_DrawModel(0xE, p);
            break;
        case 3:
            Pickup_DrawModelEnvMap(0xF, p);
            break;
        case 6:
            Pickup_DrawModel(0x12, p);
            break;
        case 7:
            Pickup_DrawModel(0x13, p);
            break;
        case 2:
            Pickup_DrawModel(0x11, p);
            break;
        case 5:
            Pickup_DrawModelEnvMap(0x10, p);
            break;
        }
    }
    if (g_SpecterCoinTimer != 0) {
        q = &D_800BF2A0;
        q->f_B = g_SpecterCoinTimer * 4;
        pos.vx = g_Spike.x;
        pos.vy = g_Spike.y - 0x200 + g_SpecterCoinTimer * 8;
        pos.vz = g_Spike.z;
        if (!(g_SpecterCoinTimer & 7)) {
            Effect_SpawnAt(0x104, &pos);
        }
        q->f_4 = pos.vx;
        q->f_6 = pos.vy;
        q->f_8 = pos.vz;
        Pickup_DrawModelEnvMap(0xD, q);
        g_SpecterCoinTimer--;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80083470_pickup", jtbl_800A61B8_pad);


void Pickup_Frame(void) {
    if (g_Game.f_8100 == 0) {
        Pickup_UpdateAll();
    }
    Pickup_DrawAll();
}

void Pickup_DrawModel(s32 i, S_846D8_800845E0 *o) {
    struct S_D_800E78C0 m;
    struct S_D_800F4C30 *s;
    u8 *buf;
    Matrix_SetIdentity(&m);
    m.t[0] = o->f_4;
    m.t[1] = o->f_6;
    m.t[2] = o->f_8;
    Matrix_RotateY(o->f_B << 6, &m);
    CompMatrix(&g_ViewMatrix, &m, &m);
    s = &D_800F4C30[i];
    if (s->f_0->f_A != 0) {
        buf = (u8 *)0x1F800080;
    } else {
        buf = g_ProjVerts;
    }
    Model_ProjectVerts(s, &m, buf);
    Model_Draw(((struct S_D_800EC350_800845E0 *)&g_Game)->db[((struct S_D_800EC350_800845E0 *)&g_Game)->cur].ot, buf, s);
}

void Pickup_DrawModelEnvMap(s32 i, S_846D8_800846D8 *o) {
    struct S_D_800E78C0 m;
    struct S_D_800F4C30_800846D8 *s;
    u8 *buf;
    Matrix_SetIdentity(&m);
    m.t[0] = o->f_4;
    m.t[1] = o->f_6;
    m.t[2] = o->f_8;
    Matrix_RotateY(o->f_B << 6, &m);
    CompMatrix(&g_ViewMatrix, &m, &m);
    s = &((struct S_D_800F4C30_800846D8 *)&D_800F4C30)[i];
    if (s->f_0->f_A != 0) {
        buf = (u8 *)0x1F800080;
    } else {
        buf = g_ProjVerts;
    }
    Model_ProjectVerts(s, &m, buf);
    Model_CalcEnvMapUVs64(s);
    *(u8 *)0x1F8003F4 = 2;
    Model_DrawEnvMapped(g_GameOt, buf, s);
}

void Pickup_ClearAreaMasks(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        Pickup_AreaMasks[i].f_0 = 0;
    }
}

void Pickup_SaveAreaMask(void) {
    s32 k = ((struct S_D_800EC350_800847EC *)&g_Game)->f_8126 - World_FirstStage(((struct S_D_800EC350_800847EC *)&g_Game)->f_8124);
    u32 bits;
    s32 i;
    if (k >= 8) {
        bios_printf(D_800A6160);
        k = 0;
    }
    bits = 0;
    for (i = 31; i >= 0; i--) {
        bits <<= 1;
        if (D_800BEFA0[i].f_A == 0 || D_800BF2D8[i] == 0) {
            bits |= 1;
        }
    }
    ((u32 *)&Pickup_AreaMasks)[k] = bits;
}

void Pickup_Nop(void) {

}
