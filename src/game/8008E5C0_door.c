#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "game.h"
typedef struct { u8 pad[0x10]; s16 f_10; s16 f_12; s16 f_14; u8 pad16[0xA]; } S_4D64_8008FAD0_8008FAD0;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; } S_O_8008FAD0_8008FAD0;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[2]; s16 f_E; u8 pad10[0x14]; s16 f_24; s16 f_26; s16 f_28; u8 pad2A[0xE]; } S_820C_8008EF60_8008EF60;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s16 f_C; s16 f_E; s16 f_10; } S_P_8008EF60_8008EF60;
typedef struct { u8 pad[0x12]; s16 f_12; u8 pad14[2]; s16 f_16; u8 pad18[8]; } S_4D64_8008EF60_8008EF60;
typedef struct { u32 *f_0; u8 pad4[0x18]; void *f_1C; } S_4D64_8008F308_8008F308;
typedef struct { s16 f_0; u8 pad2[4]; s16 f_6; s16 f_8; } S_O_8008F308_8008F308;
typedef struct { s16 f_0, f_2, f_4, f_6, f_8; u8 padA[0x1A]; s16 f_24, f_26, f_28; u8 pad2A[0xE]; } Solid_8008F468_8008F468;
typedef struct { u8 pad0[6]; s16 f_6; u8 pad8[0x10]; } Sw_8008F468_8008F468;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[4]; s16 f_C; s16 f_E; s16 f_10; s16 f_12; } T_8008F468_8008F468;
typedef struct { s16 f_0, f_2, f_4, f_6, f_8; u8 padA[4]; s16 f_E; u8 pad10[6]; u16 f_16; u8 pad18[0xC]; SVECTOR f_24; u8 pad2C[0xC]; } Solid_8008F53C_8008F53C;
typedef struct { u8 pad0[0x16]; s16 f_16; } Sw_8008F53C_8008F53C;
typedef struct { u8 pad0[0x12]; s16 f_12; u8 pad14[2]; u16 f_16; u8 pad18[8]; } Mdl_8008F53C_8008F53C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; s16 f_10; s16 f_12; } T_8008F53C_8008F53C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s16 f_C; s16 f_E; s16 f_10; s16 f_12; } T_8008F720_8008F720;
typedef struct { u16 f_0; u16 f_2; u16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; u8 padC[2]; s16 f_E; u8 pad10[0x14]; u16 f_24; u16 f_26; u16 f_28; u8 pad2A[0xE]; } O_8008F720_8008F720;
typedef struct { u8 pad0[0x16]; s16 f_16; u8 pad18[8]; } Mdl_8008F720_8008F720;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s16 f_C; s16 f_E; s16 f_10; s16 f_12; } T_8008F8D4_8008F8D4;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[0x28]; } O_8008F8D4_8008F8D4;
typedef struct { u8 pad0[0x16]; u16 f_16; u8 pad18[8]; } Mdl_8008F8D4_8008F8D4;
typedef struct { s16 x; s16 y; s16 z; s16 w; s16 f_8; s16 d; u8 padC[0xC]; u16 f_18; } O_8008ECFC_8008ECFC;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[4]; s16 f_E; } T_8008E90C_8008E90C;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } O_8008E90C_8008E90C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[4]; s16 f_E; } T_8008F0BC_8008F0BC;
typedef struct { s16 x; u16 y; s16 z; u8 pad6[2]; s16 f_8; u8 padA[4]; s16 f_E; u8 pad10[0x28]; } O_8008F0BC_8008F0BC;
typedef struct { u8 pad0[0x12]; u16 f_12; u8 pad14[2]; u16 f_16; u8 pad18[8]; } Mdl_8008F0BC_8008F0BC;
typedef struct { s32 x, y, z; } P_8008EC70_8008EC70;
typedef struct { u8 pad0[8]; s16 f_8; u8 padA[0x1A]; s16 f_24; s16 f_26; s16 f_28; } O_8008EC70_8008EC70;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[2]; s16 f_C; s16 f_E; s16 f_10; } T_8008E5C0_8008E5C0;
typedef struct { u16 x; u16 y; u16 z; s16 w; u8 pad8[2]; s16 d; u8 padC[2]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0xA]; u16 f_24; u16 f_26; u16 f_28; u8 pad2A[0xE]; } O_8008E5C0_8008E5C0;

s32 func_8005BB98(u16);
M2C_UNK Sound_PlayFixed(s32);
M2C_UNK Sound_PlayAt(s32, void *);
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; } g_Game;
extern S_4D64_8008FAD0_8008FAD0 *D_800B4D64;
struct S_D_800EC350_8008EF60 { u8 pad0[0x820C]; S_820C_8008EF60_8008EF60 *f_820C; };
void RotMatrixZYX(SVECTOR *, void *);
extern s32 D_800EC204[];
extern struct S_D_800F5A20 { u8 pad0[0x24]; s32 f_24[3]; u8 pad30[0x40]; s32 f_70; } g_RcCar;
extern Monkey g_Monkeys[];
s32 Door_PointInBox(P_8008EC70_8008EC70 *p, O_8008EC70_8008EC70 *o, s16 r, s16 *box);
struct Game_8008F468 { u8 pad0[0x820C]; Solid_8008F468_8008F468 *f_820C; u8 pad8210[0x10]; Sw_8008F468_8008F468 *f_8220; };
struct Game_8008F53C { u8 pad0[0x820C]; Solid_8008F53C_8008F53C *f_820C; u8 pad8210[0x10]; Sw_8008F53C_8008F53C *f_8220; };
s16 Sound_Play(s32, s32);
void Sound_Stop(s32, s16);
void Sound_UpdateVoice3D(s32, s16, s32, SVECTOR *);
struct Game_8008F720 { u8 pad0[0x820C]; O_8008F720_8008F720 *f_820C; };
s32 func_8008FAD0(S_O_8008FAD0_8008FAD0 *o, s16 dir, s32 amt);
struct Game_8008F8D4 { u8 pad0[0x820C]; O_8008F8D4_8008F8D4 *f_820C; };
s32 Door_IsTriggered(s32 a, short r, s32 c);
s32 Door_PlaySound(void *arg0);
struct Game_8008E90C { u8 pad0[0x820C]; O_8008E90C_8008E90C *f_820C; };
s32 SwingDoor_SetModelRot(S_O_8008F308_8008F308 *o, s32 idx);
s32 Box_SwingAroundCorner(void *o, s16 dir, s16 m);
struct Game_8008F0BC { u8 pad0[0x820C]; O_8008F0BC_8008F0BC *f_820C; };
int abs(int);
struct Game_8008E5C0 { u8 pad0[0x820C]; O_8008E5C0_8008E5C0 *f_820C; };

/* Sets up a swinging door (see SwingDoor_Update): halves the object's box half sizes, moves
 * the box next to the hinge t->f_8 (0..7) and remembers the pivot (+0x24..+0x28), sizes the
 * trigger box t->f_E/+0x10. Auto doors (t->f_0 == 1) start closed (3) or, with t->f_C, open (0);
 * others closed for good (4) or open (1, box already swung). */
s32 SwingDoor_Init(T_8008E5C0_8008E5C0 *t) {
    O_8008E5C0_8008E5C0 *o = &(*(struct Game_8008E5C0 *)&g_Game).f_820C[t->f_4];
    o->w = o->w / 2;
    o->d = o->d / 2;
    switch (t->f_8) {
    case 0:
        o->x -= o->w;
        o->z += o->d;
        o->f_24 = o->x - o->w;
        o->f_28 = o->z;
        t->f_E = o->w * 4;
        t->f_10 = o->d + 0x600;
        break;
    case 7:
        o->x -= o->w;
        o->z += o->d;
        o->f_24 = o->x;
        o->f_28 = o->z + o->d;
        t->f_E = o->w + 0x600;
        t->f_10 = o->d * 4;
        break;
    case 1:
        o->x += o->w;
        o->z += o->d;
        o->f_24 = o->x + o->w;
        o->f_28 = o->z;
        t->f_E = o->w * 4;
        t->f_10 = o->d + 0x600;
        break;
    case 2:
        o->x += o->w;
        o->z += o->d;
        o->f_24 = o->x;
        o->f_28 = o->z + o->d;
        t->f_E = o->w + 0x600;
        t->f_10 = o->d * 4;
        break;
    case 4:
        o->x += o->w;
        o->z -= o->d;
        o->f_24 = o->x + o->w;
        o->f_28 = o->z;
        t->f_E = o->w * 4;
        t->f_10 = o->d + 0x600;
        break;
    case 3:
        o->x += o->w;
        o->z -= o->d;
        o->f_24 = o->x;
        o->f_28 = o->z - o->d;
        t->f_E = o->w + 0x600;
        t->f_10 = o->d * 4;
        break;
    case 5:
        o->x -= o->w;
        o->z -= o->d;
        o->f_24 = o->x - o->w;
        o->f_28 = o->z;
        t->f_E = o->w * 4;
        t->f_10 = o->d + 0x600;
        break;
    case 6:
        o->x -= o->w;
        o->z -= o->d;
        o->f_24 = o->x;
        o->f_28 = o->z - o->d;
        t->f_E = o->w + 0x600;
        t->f_10 = o->d * 4;
        break;
    }
    o->f_26 = o->y;
    if (t->f_0 == 1) {
        if (t->f_C == 0) {
            t->f_2 = 3;
            t->f_6 = 0;
        } else {
            o->f_18 |= 0x8000;
            t->f_2 = 0;
            t->f_6 = 0x400;
            SwingDoor_SetModelRot(t, o->f_E);
        }
    } else if (t->f_C == 0) {
        t->f_2 = 4;
        t->f_6 = 0;
    } else {
        Box_SwingAroundCorner(o, t->f_8, 2);
        t->f_2 = 1;
        t->f_6 = 0x400;
        SwingDoor_SetModelRot(t, o->f_E);
    }
    return 0;
}



/* Swinging door (sibling of SlideDoor_Update). State t->f_2: 3 closed, opens (5) when
 * Door_IsTriggered finds something in its box (object flag 0x8000 set while moving); 5 turns it
 * 0x20 per frame (SwingDoor_SetModelRot updates the model, Door_PlaySound sound at 0xC0) until 0x400,
 * then its collision box is swung around the hinge (Box_SwingAroundCorner) and it is open (0, or
 * 1 for good); 0 closes (2) once the box is empty; 2 turns back to 0 (sound at 0x340), swings
 * the box back and goes to 3 (auto) or 4. Returns 0. */
s32 SwingDoor_Update(T_8008E90C_8008E90C *t) {
    O_8008E90C_8008E90C *o = &(*(struct Game_8008E90C *)&g_Game).f_820C[t->f_4];
    switch (t->f_2) {
    case 3:
        if (Door_IsTriggered(o, 0, &t->f_E)) {
            o->f_18 |= 0x8000;
            t->f_2 = 5;
        }
        break;
    case 5:
        SwingDoor_SetModelRot(t, o->f_E);
        t->f_6 += 0x20;
        if (t->f_6 == 0xC0) {
            Door_PlaySound(o);
        }
        if (t->f_6 > 0x400) {
            Box_SwingAroundCorner(o, t->f_8, 2);
            if (t->f_0 == 1) {
                t->f_2 = 0;
            } else {
                t->f_2 = 1;
            }
        }
        break;
    case 0:
        if (!Door_IsTriggered(o, 0, &t->f_E)) {
            o->f_18 |= 0x8000;
            t->f_2 = 2;
        }
        break;
    case 2:
        SwingDoor_SetModelRot(t, o->f_E);
        t->f_6 -= 0x20;
        if (t->f_6 == 0x340) {
            Door_PlaySound(o);
        }
        if (t->f_6 < 0) {
            Box_SwingAroundCorner(o, t->f_8, 5);
            if (t->f_0 == 1) {
                t->f_2 = 3;
            } else {
                t->f_2 = 4;
            }
            t->f_6 = 0;
            o->f_18 &= 0x7FFF;
        }
        break;
    case 1:
    case 4:
        break;
    }
    return 0;
}



s32 Door_PlaySound(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_8005BB98(M2C_FIELD(arg0, u16 *, 0x16));
    if (temp_v0 >= 0) {
        if (g_Game.f_8100 & 1) {
            Sound_PlayFixed(temp_v0);
        } else {
            Sound_PlayAt(temp_v0, arg0);
        }
    }
    return 0;
}

/* True when Spike, the RC Car (while out) or a monkey in state 4 is inside the trigger box of
 * a door (Door_PointInBox with the door object, kind r and box c). */
s32 Door_IsTriggered(s32 a, short r, s32 c)
{
  s32 i;
  if (Door_PointInBox(D_800EC204, a, r, c))
  {
    return 1;
  }
  if ((g_RcCar.f_70 != 0) && Door_PointInBox(g_RcCar.f_24, a, r, c))
  {
    return 1;
  }
  for (i = 0; i < 8; i++)
  {
    if ((g_Monkeys[i].f_7A == 4) && Door_PointInBox(&g_Monkeys[i].f_24, a, r, c))
    {
      return 1;
    }
  }

  return 0;
}

s32 Door_PointInBox(P_8008EC70_8008EC70 *p, O_8008EC70_8008EC70 *o, s16 r, s16 *box) {
    if (abs(p->z - o->f_28) < box[1] && abs(p->x - o->f_24) < box[0]) {
        if (p->y < o->f_26 + o->f_8 && o->f_26 - o->f_8 < p->y) {
            return 1;
        }
    }
    return 0;
}

/* Turns a stage box (centre +0/+4, half sizes +6/+0xA) by 90 degrees around the hinge corner
 * selected by dir (0..7), the other way when m == 2: moves the centre accordingly and swaps the
 * half sizes. Clears flag 0x8000 of +0x18. Used by swinging doors/gates. Returns 0. */
s32 Box_SwingAroundCorner(void *ov, s16 dir, s16 m) {
    O_8008ECFC_8008ECFC *o = ov;
    s32 x = o->x;
    s32 z = o->z;
    s32 w = o->w;
    s32 d = o->d;
    o->f_18 &= 0x7FFF;
    switch (dir) {
    case 0:
        if (m == 2) {
            o->x = x + w - d;
            o->z = z - w - d;
        } else {
            o->x = x - d + w;
            o->z = z + d + w;
        }
        break;
    case 7:
        if (m == 2) {
            o->x = x + d + w;
            o->z = z - d + w;
        } else {
            o->x = x - w - d;
            o->z = z + w - d;
        }
        break;
    case 1:
        if (m == 2) {
            o->x = x - w + d;
            o->z = z - w - d;
        } else {
            o->x = x + d - w;
            o->z = z + d + w;
        }
        break;
    case 2:
        if (m == 2) {
            o->x = x - d - w;
            o->z = z - d + w;
        } else {
            o->x = x + w + d;
            o->z = z + w - d;
        }
        break;
    case 4:
        if (m == 2) {
            o->x = x - w + d;
            o->z = z + w + d;
        } else {
            o->x = x + d - w;
            o->z = z - d - w;
        }
        break;
    case 3:
        if (m == 2) {
            o->x = x - d - w;
            o->z = z + d - w;
        } else {
            o->x = x + w + d;
            o->z = z - w + d;
        }
        break;
    case 5:
        if (m == 2) {
            o->x = x + w - d;
            o->z = z + w + d;
        } else {
            o->x = x - d + w;
            o->z = z - d - w;
        }
        break;
    case 6:
        if (m == 2) {
            o->x = x + d + w;
            o->z = z + d - w;
        } else {
            o->x = x - w - d;
            o->z = z - w + d;
        }
        break;
    }
    o->w = d;
    o->d = w;
    return 0;
}



s32 func_8008EF60(S_P_8008EF60_8008EF60 *p) {
    S_820C_8008EF60_8008EF60 *e = &((struct S_D_800EC350_8008EF60 *)&g_Game)->f_820C[p->f_4];
    e->f_24 = e->f_0;
    e->f_26 = e->f_2;
    e->f_28 = e->f_4;
    if (p->f_0 == 1) {
        if (p->f_8 == 10 || p->f_8 == 12) {
            p->f_E = e->f_6 * 2;
            p->f_10 = e->f_A + 0x400;
        } else {
            p->f_E = e->f_6 + 0x400;
            p->f_10 = e->f_A * 2;
        }
        if (p->f_C != 0) {
            p->f_2 = 0;
            p->f_6 = e->f_8;
        } else {
            p->f_2 = 3;
            p->f_6 = 0;
        }
    } else if (p->f_C == 0) {
        p->f_2 = 4;
        p->f_6 = 0;
    } else {
        p->f_2 = 1;
        p->f_6 = e->f_8;
        if (e->f_E >= 0) {
            (*(S_4D64_8008EF60_8008EF60 * *)&D_800B4D64)[e->f_E].f_12 -= e->f_8;
        }
        e->f_2 -= e->f_8;
        if (e->f_E >= 0) {
            (*(S_4D64_8008EF60_8008EF60 * *)&D_800B4D64)[e->f_E].f_16 = 0;
        }
    }
    return 0;
}

/* Door that rises out of the way (third door type, see SlideDoor_Update): 3 closed until
 * Door_IsTriggered (kind 1); 5 rises 0x20 per frame (Door_PlaySound at 0x80) up to its height
 * +8, then 0 (auto) or 1; 0 starts lowering (2) once nobody is there; 2 lowers back to 3 or 4. */
s32 LiftDoor_Update(T_8008F0BC_8008F0BC *t) {
    O_8008F0BC_8008F0BC *o = &(*(struct Game_8008F0BC *)&g_Game).f_820C[t->f_4];
    switch (t->f_2) {
    case 3:
        if (Door_IsTriggered(o, 1, &t->f_E)) {
            t->f_2 = 5;
        }
        break;
    case 5:
        t->f_6 += 0x20;
        if (t->f_6 == 0x80) {
            Door_PlaySound(o);
        }
        if (t->f_6 > o->f_8) {
            t->f_6 = o->f_8;
            if (t->f_0 == 1) {
                t->f_2 = 0;
            } else {
                t->f_2 = 1;
            }
            if (o->f_E >= 0) {
                (*(Mdl_8008F0BC_8008F0BC * *)&D_800B4D64)[o->f_E].f_16 = 0;
            }
        } else {
            o->y -= 0x20;
            if (o->f_E >= 0) {
                (*(Mdl_8008F0BC_8008F0BC * *)&D_800B4D64)[o->f_E].f_12 -= 0x20;
            }
        }
        break;
    case 0:
        if (!Door_IsTriggered(o, 1, &t->f_E)) {
            t->f_2 = 2;
            if (o->f_E >= 0) {
                (*(Mdl_8008F0BC_8008F0BC * *)&D_800B4D64)[o->f_E].f_16 = 0xFFFF;
            }
        }
        break;
    case 2:
        t->f_6 -= 0x20;
        if (t->f_6 == (o->f_8 / 32 - 4) * 32) {
            Door_PlaySound(o);
        }
        if (t->f_6 < 0) {
            t->f_6 = 0;
            if (t->f_0 == 1) {
                t->f_2 = 3;
            } else {
                t->f_2 = 4;
            }
        } else {
            o->y += 0x20;
            if (o->f_E >= 0) {
                (*(Mdl_8008F0BC_8008F0BC * *)&D_800B4D64)[o->f_E].f_12 += 0x20;
            }
        }
        break;
    case 1:
    case 4:
        break;
    }
    return 0;
}



s32 SwingDoor_SetModelRot(S_O_8008F308_8008F308 *o, s32 idx) {
    SVECTOR r;
    if ((*(*(S_4D64_8008F308_8008F308 * *)&D_800B4D64)[idx].f_0 & 0xF) != 3) {
        return 0;
    }
    switch (o->f_0) {
    case 1:
    case 101:
        r.vz = 0;
        r.vx = 0;
        if (o->f_8 & 1) {
            r.vy = o->f_6;
        } else {
            r.vy = o->f_6 * -1;
        }
        break;
    case 3:
    case 20:
        if (!((o->f_8 - 60) & 1)) {
            r.vz = 0;
            r.vy = 0;
            if (o->f_8 == 60) {
                r.vx = o->f_6;
            } else {
                r.vx = o->f_6 * -1;
            }
        } else {
            r.vx = 0;
            r.vy = 0;
            if (o->f_8 == 61) {
                r.vz = o->f_6 * -1;
            } else {
                r.vz = o->f_6;
            }
        }
        break;
    default:
        return 0;
    }
    RotMatrixZYX(&r, (*(S_4D64_8008F308_8008F308 * *)&D_800B4D64)[idx].f_1C);
    return 0;
}

/* Puts pressure-plate gate t (stage object g_Game+0x820C[t->f_4]) back at its start position,
 * resets its one or two plates (g_Game+0x8220[t->f_E / t->f_10]) and its state. */
s32 PlateGate_Reset(T_8008F468_8008F468 *t) {
    struct Game_8008F468 *g = (struct Game_8008F468 *)&(*(M2C_UNK *)&g_Game);
    Solid_8008F468_8008F468 *o = &g->f_820C[t->f_4];
    o->f_24 = o->f_0;
    o->f_26 = o->f_2;
    o->f_28 = o->f_4;
    if (t->f_E >= 0) {
        { Sw_8008F468_8008F468 *w = g->f_8220 + t->f_E; w->f_6 = o->f_8; }
    }
    if (t->f_10 >= 0) {
        { Sw_8008F468_8008F468 *w = g->f_8220 + t->f_10; w->f_6 = o->f_8; }
    }
    if (t->f_C == 0) {
        t->f_2 = 3;
        t->f_6 = 0;
    } else {
        t->f_2 = 0;
        t->f_6 = o->f_8;
    }
    t->f_12 = -1;
    return 0;
}

/* Pressure-plate gate (user: you stand on the plate, then use the Super Hoop to reach the gate
 * before it closes). Its opening is the sum of its one or two plates' +0x16 values
 * (g_Game+0x8220[t->f_E / t->f_10], how far each is pressed), capped by the gate's +0x8.
 * While it moves, loops the grinding sound 0x7F at it; when it comes to rest after moving it
 * plays its own sound (func_8005BB98(+0x16)). State t->f_2: 0 at the limit, 3 at rest, 5 moving.
 * Its height is +0x26 minus the offset, mirrored into its model's +0x12. */
s32 PlateGate_Update(T_8008F53C_8008F53C *t) {
    struct Game_8008F53C *g = (struct Game_8008F53C *)&(*(M2C_UNK *)&g_Game);
    s32 s = 0;
    Solid_8008F53C_8008F53C *o = &g->f_820C[t->f_4];
    s32 snd;
    if (t->f_E >= 0) {
        Sw_8008F53C_8008F53C *w = g->f_8220 + t->f_E;
        s = w->f_16;
    }
    if (t->f_10 >= 0) {
        Sw_8008F53C_8008F53C *w = g->f_8220 + t->f_10;
        s += w->f_16;
    }
    if (o->f_8 < s) {
        if (o->f_E >= 0) {
            (*(Mdl_8008F53C_8008F53C * *)&D_800B4D64)[o->f_E].f_16 = 0;
        }
        t->f_2 = 0;
    } else if (s <= 0) {
        if (t->f_2 == 5) {
            snd = func_8005BB98(o->f_16);
            if (snd >= 0) {
                Sound_PlayAt(snd, o);
            }
        }
        t->f_2 = 3;
    } else {
        if (o->f_E >= 0) {
            (*(Mdl_8008F53C_8008F53C * *)&D_800B4D64)[o->f_E].f_16 = 0xFFFF;
        }
        t->f_2 = 5;
    }
    if (s > 0) {
        if (t->f_12 < 0) {
            t->f_12 = Sound_Play(1, 0x7F);
        } else {
            Sound_UpdateVoice3D(0x7F, t->f_12, 0x1800, &o->f_24);
        }
    } else if (t->f_12 >= 0) {
        Sound_Stop(0x7F, t->f_12);
        t->f_12 = -1;
    }
    o->f_2 = *(u16 *)((u8 *)o + 0x26) - s;
    if (o->f_E >= 0) {
        (*(Mdl_8008F53C_8008F53C * *)&D_800B4D64)[o->f_E].f_12 = *(u16 *)((u8 *)o + 0x26) - s;
    }
    return 0;
}

/* Sets up a sliding door: remembers the stage object's position (+0x24..+0x28), offsets it by
 * its half size along x (directions 0/5 minus, 1/4 plus) or z (2/7 plus, 3/6 minus), sizes the
 * trigger box t->f_E/+0x10 and the slide length t->f_12. With t->f_0 == 1 it starts closed and
 * waiting (state 3), with t->f_C == 0 closed for good (4); otherwise open (1). */
s32 SlideDoor_Init(T_8008F720_8008F720 *t) {
    O_8008F720_8008F720 *o = &(*(struct Game_8008F720 *)&g_Game).f_820C[t->f_4];
    o->f_24 = o->f_0;
    o->f_26 = o->f_2;
    o->f_28 = o->f_4;
    switch (t->f_8) {
    case 0:
    case 5:
        o->f_24 -= o->f_6;
        t->f_E = o->f_6 * 2;
        t->f_10 = o->f_A + 0x400;
        t->f_12 = o->f_6 * 2;
        break;
    case 1:
    case 4:
        o->f_24 += o->f_6;
        t->f_E = o->f_6 * 2;
        t->f_10 = o->f_A + 0x400;
        t->f_12 = o->f_6 * 2;
        break;
    case 2:
    case 7:
        o->f_28 += o->f_A;
        t->f_E = o->f_6 + 0x400;
        t->f_10 = o->f_A * 2;
        t->f_12 = o->f_A * 2;
        break;
    case 3:
    case 6:
        o->f_28 -= o->f_A;
        t->f_E = o->f_6 + 0x400;
        t->f_10 = o->f_A * 2;
        t->f_12 = o->f_A * 2;
        break;
    }
    if (t->f_0 == 1) {
        t->f_2 = 3;
        t->f_6 = 0;
    } else if (t->f_C == 0) {
        t->f_2 = 4;
        t->f_6 = 0;
    } else {
        t->f_2 = 1;
        if (o->f_E >= 0) {
            (*(Mdl_8008F720_8008F720 * *)&D_800B4D64)[o->f_E].f_16 = 0;
        }
        t->f_6 = t->f_12;
        func_8008FAD0(o, t->f_8, t->f_12);
    }
    return 0;
}



/* Sliding door. State t->f_2: 3 closed, opens (5) when Door_IsTriggered finds something in its
 * trigger box t->f_E; 5 slides 32 per frame (Door_PlaySound at 64) until t->f_12, then 0 (auto
 * door, t->f_0 == 1) or 1 (stays open); 0 starts closing (2) once the box is empty; 2 slides
 * back (Door_PlaySound near the end) to 3 (auto) or 4 (stays closed). Returns 0. */
s32 SlideDoor_Update(T_8008F8D4_8008F8D4 *t) {
    O_8008F8D4_8008F8D4 *o = &(*(struct Game_8008F8D4 *)&g_Game).f_820C[t->f_4];
    switch (t->f_2) {
    case 3:
        if (Door_IsTriggered(o, 2, &t->f_E)) {
            t->f_2 = 5;
        }
        break;
    case 5:
        t->f_6 += 0x20;
        if (t->f_6 == 0x40) {
            Door_PlaySound(o);
        }
        if (t->f_6 > t->f_12) {
            t->f_6 = t->f_12;
            if (t->f_0 == 1) {
                t->f_2 = 0;
            } else {
                t->f_2 = 1;
            }
            if (o->f_E >= 0) {
                (*(Mdl_8008F8D4_8008F8D4 * *)&D_800B4D64)[o->f_E].f_16 = 0;
            }
        } else {
            func_8008FAD0(o, t->f_8, 0x20);
        }
        break;
    case 0:
        if (!Door_IsTriggered(o, 2, &t->f_E)) {
            t->f_2 = 2;
            if (o->f_E >= 0) {
                (*(Mdl_8008F8D4_8008F8D4 * *)&D_800B4D64)[o->f_E].f_16 = 0xFFFF;
            }
        }
        break;
    case 2:
        t->f_6 -= 0x20;
        if (t->f_6 == (t->f_12 / 32 - 2) * 32) {
            Door_PlaySound(o);
        }
        if (t->f_6 < 0) {
            t->f_6 = 0;
            if (t->f_0 == 1) {
                t->f_2 = 3;
            } else {
                t->f_2 = 4;
            }
        } else {
            func_8008FAD0(o, t->f_8, -0x20);
        }
        break;
    case 1:
    case 4:
        break;
    }
    return 0;
}



s32 func_8008FAD0(S_O_8008FAD0_8008FAD0 *o, s16 dir, s32 amt) {
    s16 a = amt;
    if (o->f_E < 0) {
        return 0;
    }
    if ((u16)(dir - 8) < 8) {
        o->f_2 += amt;
        D_800B4D64[o->f_E].f_12 += amt;
    }
    switch (dir) {
    case 0: case 5: case 8: case 13:
        o->f_0 += a;
        D_800B4D64[o->f_E].f_10 += a;
        break;
    case 1: case 4: case 9: case 12:
        o->f_0 -= a;
        D_800B4D64[o->f_E].f_10 -= a;
        break;
    case 2: case 7: case 10: case 15:
        o->f_4 -= a;
        D_800B4D64[o->f_E].f_14 -= a;
        break;
    case 3: case 6: case 11: case 14:
        o->f_4 += a;
        D_800B4D64[o->f_E].f_14 += a;
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8008E5C0_door", jtbl_800A6528_pad);

