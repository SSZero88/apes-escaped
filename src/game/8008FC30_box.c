#include "game.h"
#include "m2c_macros.h"
#define SPK_90754 ((struct Act_80090754 *)&g_Spike)
#define RC_90754 ((struct Act_80090754 *)&g_RcCar)
#define GM_90754 ((struct Game_80090754 *)&g_Game)
typedef struct { u8 pad[0x20]; } S_4D64;
typedef struct { u8 pad0[6]; s16 f_6; s16 f_8; s16 f_A; s16 f_C; u8 padE[8]; s16 f_16; } S_90D94_80090D94;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } S_820C_800905A4;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; u8 pad6[4]; s16 f_A; s16 f_C; s16 f_E; s16 f_10; } S_905A4_800905A4;
typedef struct { u8 pad0[8]; s16 f_8; u8 padA[0x2E]; } S_820C_800909A8;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; s16 f_6; u8 pad8[0xA]; s16 f_12; s16 f_14; s16 f_16; } S_909A8_800909A8;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[0x28]; } S_820C_80090660;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; u8 pad6[6]; s16 f_C; s16 f_E; s16 f_10; } S_90660_80090660;
typedef struct { s16 x, y, z, rx, h, rz; } Box_80090754_80090754;
typedef struct { s16 x, y, z, rx, f_8, rz; u8 padC[6]; u8 f_12; u8 pad13[0x25]; } Solid_80090754_80090754;
typedef struct { s16 vx, vy, vz, pad; } SV_909FC_800909FC;
typedef struct { u8 pad0[0x1E]; s16 f_1E; u8 pad20[0x18]; } Zone_909FC_800909FC;
typedef struct { u8 pad0[4]; s16 zone; s16 f_6; s16 f_8[5]; u8 pad12[2]; s16 speed; s16 angle; } Mech_909FC_800909FC;
typedef struct { u8 pad0[0x1C]; void *f_1C; } Mdl_909FC_800909FC;
typedef struct { u8 pad[0x16]; u16 f_16; u8 pad18[8]; } S_4D64_80090230_80090230;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } S_820C_80090230_80090230;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; s16 f_10; s16 f_12; u8 pad14[4]; } S_Node_80090230_80090230;
typedef struct { u8 pad[0x20]; } S_4D64_80090370;
typedef struct { u8 pad0[0xE]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } S_820C_80090370_80090370;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; u8 pad6[2]; u16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; s16 f_12; } S_L_80090370_80090370;

extern S_4D64 *D_800B4D64;
void Model_BindStageMesh(S_4D64 *, s16);

M2C_UNK func_8008FC30(s16, void *);
s32 func_80090E54(s16 a, s16 b, s16 c, s16 d);
extern struct S_D_800EC350 { u8 pad_0[0x820C]; s32 f_820C; } g_Game;

s32 func_80090D94();
s32 Stage_CountCaughtMonkeys(s32 *);
s32 func_80097504(void);
struct S_D_800EC350_800905A4 { u8 pad0[0x820C]; S_820C_800905A4 *f_820C; };
struct S_D_800EC350_800909A8 { u8 pad0[0x820C]; S_820C_800909A8 *f_820C; };
/* Returns 1 if anything stands in box `b` (centre x,y,z; half sizes rx, rz; height h below y):
 * Spike, the RC car while it is out (g_RcCar+0x70), any solid object (type 1) in the
 * stage's object list (g_Game+0x820C, count +0x8284) whose footprint overlaps, or, when
 * `monkeys` is set, a monkey in state 4. */
s32 Box_IsOccupied(s32 monkeys, Box_80090754_80090754 *b);
void Sound_PlayAt(s32, S_820C_80090660 *);
struct S_D_800EC350_80090660 { u8 pad0[0x820C]; S_820C_80090660 *f_820C; };
struct Act_80090754 { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x40]; s32 f_70; };
struct Game_80090754 { u8 pad0[0x820C]; Solid_80090754_80090754 *f_820C; u8 pad8210[0x74]; s16 f_8284; };
extern M2C_UNK g_Spike;
extern M2C_UNK g_RcCar;
extern Monkey g_Monkeys[8];
int abs(int);
/* 1 if (x, y, z) is inside box b: x/z within the half sizes b[3]/b[5] of the centre b[0]/b[2],
 * and y between the top b[1] and b[1] - b[4]. */
s32 Box_ContainsPoint(s16 *b, s32 x, s32 y, s32 z);
struct Game_909FC { u8 pad0[0x820C]; Zone_909FC_800909FC *f_820C; };
void RotMatrixZYX(SV_909FC_800909FC *, void *);
struct S_D_800EC350_80090230 { u8 pad0[0x820C]; S_820C_80090230_80090230 *f_820C; u8 pad8210[0x10]; S_Node_80090230_80090230 *f_8220; };
struct S_D_800EC350_80090370 { u8 pad0[0x820C]; S_820C_80090370_80090370 *f_820C; };

INCLUDE_ASM("asm/nonmatchings/game/8008FC30_box", func_8008FC30);

INCLUDE_RODATA("asm/nonmatchings/game/8008FC30_box", jtbl_800A6570);


s32 Link_ResetTree(S_Node_80090230_80090230 *n) {
    struct S_D_800EC350_80090230 *d;
    S_820C_80090230_80090230 *e;
    s16 idx = n->f_4;
    if (idx < 0) {
        return 0;
    }
    d = (struct S_D_800EC350_80090230 *)&g_Game;
    e = &d->f_820C[idx];
    n->f_2 = 1;
    if (e->f_E >= 0) {
        (*(S_4D64_80090230_80090230 **)&D_800B4D64)[e->f_E].f_16 = 0xFFFF;
    }
    e->f_18 = (e->f_18 & 0xFFF0) | 2;
    if (n->f_E >= 0) {
        Link_ResetTree(&d->f_8220[n->f_E]);
    }
    if (n->f_10 >= 0) {
        Link_ResetTree(&d->f_8220[n->f_10]);
    }
    if (n->f_12 >= 0) {
        Link_ResetTree(&d->f_8220[n->f_12]);
    }
    n->f_E = e->f_0;
    n->f_10 = e->f_2;
    n->f_12 = e->f_4;
    return 0;
}

s32 Link_ToggleSwitch(S_L_80090370_80090370 *l) {
    S_820C_80090370_80090370 *e = &((struct S_D_800EC350_80090370 *)&g_Game)->f_820C[l->f_4];
    s32 m;
    s32 k;
    if ((u16)(l->f_8 - 0x2A) < 4) {
        if (l->f_A == 0) {
            m = l->f_E;
            l->f_2 = 0;
        } else {
            m = l->f_10;
            func_8008FC30(l->f_C, l);
            l->f_2 = 1;
            e->f_18 |= 0x8000;
        }
        func_80090E54(e->f_E, m, l->f_E, l->f_10);
    } else if ((u16)(l->f_8 - 0x2E) < 4) {
        k = l->f_A;
        if (k == 0) {
            m = l->f_E;
            l->f_2 = 0;
        } else if (k == 1) {
            m = l->f_10;
            func_8008FC30(l->f_C, l);
            l->f_2 = k;
            e->f_18 |= 0x8000;
        } else {
            m = l->f_12;
            l->f_2 = 2;
        }
        if (l->f_E >= 0 && l->f_10 >= 0 && l->f_12 >= 0 && e->f_E >= 0) {
            Model_BindStageMesh(&(*(S_4D64_80090370 * *)&D_800B4D64)[e->f_E], m);
        }
    }
    return 0;
}

s32 func_80090500(void *arg0) {
    s16 temp_a1;
    void *temp_s0;

    temp_s0 = g_Game.f_820C + (M2C_FIELD(arg0, s16 *, 4) * 0x38);
    if ((M2C_FIELD(arg0, s16 *, 2) == 0) && (M2C_FIELD(temp_s0, s16 *, 0x1E) >= 0)) {
        func_8008FC30(M2C_FIELD(arg0, s16 *, 0xC), arg0);
        M2C_FIELD(arg0, s16 *, 2) = 1;
        M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_s0, u16 *, 0x18) | 0x8000);
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x10);
        func_80090E54(M2C_FIELD(temp_s0, s16 *, 0xE), temp_a1, temp_a1, 0);
    }
    return 0;
}

s32 func_800905A4(S_905A4_800905A4 *a) {
    S_820C_800905A4 *r = &((struct S_D_800EC350_800905A4 *)&g_Game)->f_820C[a->f_4];
    if (a->f_A == 0) {
        a->f_2 = 0;
        r->f_18 |= 0x8000;
        func_80090E54(r->f_E, a->f_E, a->f_E, a->f_10);
    } else {
        func_8008FC30(a->f_C, a);
        a->f_2 = 1;
        r->f_18 |= 0x8000;
        func_80090E54(r->f_E, a->f_10, a->f_E, a->f_10);
    }
    return 0;
}

s32 Link_UpdatePressurePlate(S_90660_80090660 *s) {
    S_820C_80090660 *r = &((struct S_D_800EC350_80090660 *)&g_Game)->f_820C[s->f_4];
    switch (s->f_2) {
    case 0:
        if (Box_IsOccupied(1, r) == 0) {
            break;
        }
        func_8008FC30(s->f_C, s);
        s->f_2 = 1;
        Sound_PlayAt(0x75, r);
        func_80090E54(r->f_E, s->f_10, s->f_E, s->f_10);
        break;
    case 1:
        if (Box_IsOccupied(1, r) != 0) {
            break;
        }
        func_8008FC30(s->f_C, s);
        s->f_2 = 0;
        func_80090E54(r->f_E, s->f_E, s->f_E, s->f_10);
        break;
    }
    return 0;
}

s32 Box_IsOccupied(s32 monkeys, Box_80090754_80090754 *b) {
    s32 i;
    s32 d;
    Solid_80090754_80090754 *o;
    if (Box_ContainsPoint(b, SPK_90754->x, SPK_90754->y, SPK_90754->z) != 0) {
        return 1;
    }
    if (RC_90754->f_70 != 0 && Box_ContainsPoint(b, RC_90754->x, RC_90754->y, RC_90754->z) != 0) {
        return 1;
    }
    for (i = GM_90754->f_8284 - 1; i >= 0; i--) {
        o = &GM_90754->f_820C[i];
        if (o->f_12 == 1 && abs(o->x - b->x) < o->rx + b->rx && abs(o->z - b->z) < o->rz + b->rz &&
            o->y >= b->y - b->h && o->y <= b->y) {
            return 1;
        }
    }
    if (monkeys == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (g_Monkeys[i].f_7A == 4 && Box_ContainsPoint(b, g_Monkeys[i].f_24, g_Monkeys[i].f_28, g_Monkeys[i].f_2C) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 Box_ContainsPoint(s16 *b, s32 x, s32 y, s32 z) {
    if (b[0] + b[3] >= x && x >= b[0] - b[3] && b[2] + b[5] >= z && z >= b[2] - b[5] && y >= b[1] - b[4] && b[1] >= y) {
        return 1;
    }
    return 0;
}

s32 func_800909A8(S_909A8_800909A8 *a)
{
  S_820C_800909A8 *new_var;
  new_var = &((struct S_D_800EC350_800909A8 *)&g_Game)->f_820C[a->f_4];
  a->f_12 = -1;
  a->f_14 = 0;
  a->f_16 = 0;
  a->f_2 = 0;
  a->f_6 = (*new_var).f_8 * 2;
  return 0;
}

/* Four-armed rotating stage object (kinds 0x37/0x38 turn about x, 0x39/0x3A about z, +8): spins up
 * (+0x60 per frame, max 0xB4) while its zone (+4, g_Game+0x820C) is active, otherwise slows down
 * and swings back to angle 0; the angle (+0x16, capped at +6) plus 0x100 per arm is applied to
 * the four arm models (+0xA..+0x10). */
s32 Rotor_Update(Mech_909FC_800909FC *m)
{
  s16 i;
  s32 a;
  Zone_909FC_800909FC *z;
  s32 e;
  SV_909FC_800909FC r;
  z = &(*(struct Game_909FC *)&g_Game).f_820C[m->zone];
  if (z->f_1E >= 0)
  {
    m->speed += 0x60;
    if (m->speed > 0xB4)
    {
      m->speed = 0xB4;
    }
  }
  else
    if (m->speed > 0)
  {
    e = (((s16) (m->speed / 100)) * 8) + 8;
    m->speed -= e;
  }
  else
    if (m->angle > 0)
  {
    m->speed = -0x10;
  }
  else
  {
    m->speed = 0;
    m->angle = 0;
  }
  m->angle += m->speed;
  if (m->f_6 < m->angle)
  {
    m->angle = m->f_6;
  }
  for (i = 0; i < 4; i++)
  {
    if (m->f_8[i + 1] < 0)
    {
      continue;
    }
    a = (i * 256) + 0x80;
    r.vz = 0;
    r.vy = 0;
    r.vx = 0;
    switch (m->f_8[0])
    {
      case 0x38:
        r.vx = (-a) - m->angle;
        while (r.vx < (-0x400))
      {
        r.vx += 0x400;
      }

        while (r.vx > 0)
      {
        r.vx -= 0x400;
      }

        break;

      case 0x37:
        r.vx = m->angle + a;
        while (r.vx > 0x400)
      {
        r.vx -= 0x400;
      }

        while (r.vx < 0)
      {
        r.vx += 0x400;
      }

        break;

      case 0x39:
        r.vz = (-a) - m->angle;
        while (r.vz < (-0x400))
      {
        r.vz += 0x400;
      }

        while (r.vz > 0)
      {
        r.vz -= 0x400;
      }

        break;

      case 0x3A:
        r.vz = m->angle + a;
        while (r.vz > 0x400)
      {
        r.vz -= 0x400;
      }

        while (r.vz < 0)
      {
        r.vz += 0x400;
      }

        break;

    }

    RotMatrixZYX(&r, ((Mdl_909FC_800909FC *)D_800B4D64)[m->f_8[i + 1]].f_1C);
  }

  return 0;
}

s32 func_80090D6C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = 0;
    func_80090D94();
    return 0;
}

s32 func_80090D94(s)
S_90D94_80090D94 *s;
{
    s32 n;
    if (s->f_6 != 0) {
        return 0;
    }
    if (s->f_8 == 0) {
        s32 r = Stage_CountCaughtMonkeys(&n);
        if ((s->f_A < 0 && r != 0) || (n >= s->f_A && s->f_A >= 0)) {
            goto trigger;
        }
    } else {
        n = func_80097504();
        if (n >= s->f_A) {
            goto trigger;
        }
    }
    goto done;
trigger:
    func_8008FC30(s->f_C, s);
    s->f_6 = 1;
done:
    s->f_16 = n;
    return 0;
}

s32 func_80090E54(s16 a, s16 b, s16 c, s16 d) {
    if (c >= 0 && d >= 0 && a >= 0) {
        Model_BindStageMesh(&D_800B4D64[a], b);
    }
    return 0;
}
