#include "common.h"
#include "m2c_macros.h"

M2C_UNK Object_PlaySound(void *, M2C_UNK);
s32 Spike_WithinRadiusXZ(s32, s32, M2C_UNK);

s32 LevelObj_ResetState(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 0x16) = 0;
    return 0;
}

typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_8013D010;
extern Monkey_8013D010 g_Monkeys_8013D010[] asm("g_Monkeys");
extern struct { u8 pad_0[0x8126]; u16 f_8126; u8 pad_8128[2]; u16 f_812A; } g_Game_8013D010 asm("g_Game");
extern s32 D_800EC204;
extern s32 D_800EC20C;
s32 RaceGoal_AddMonkeyShapes(s32 type, s32 idx);
void Game_SetMode(s32, s32, s32);

s32 RaceGoal_Update(s16 *p) {
    s32 i;
    Monkey_8013D010 *m;

    switch (p[1]) {
    case 0:
        if (ABS(D_800EC20C - p[6]) < p[8] && ABS(D_800EC204 - p[4]) < p[7]) {
            p[1] = 1;
            g_Game_8013D010.f_812A = 2;
            Game_SetMode(0x12, g_Game_8013D010.f_8126, 2);
            RaceGoal_AddMonkeyShapes(0xF, -1);
            break;
        }
        i = 0;
        m = g_Monkeys_8013D010;
    loop:
        if (m->f_7A == 4 && ABS(m->z - p[6]) < p[8] && ABS(m->x - p[4]) < p[7]) {
            p[1] = 2;
            p[10] = i;
            RaceGoal_AddMonkeyShapes(0xE, (s16)i);
            break;
        }
        m++;
        i++;
        if (i < 8) {
            goto loop;
        }
        break;
    case 1:
        RaceGoal_AddMonkeyShapes(0xF, -1);
        break;
    case 2:
        if (ABS(D_800EC20C - p[6]) < p[8] && ABS(D_800EC204 - p[4]) < p[7]) {
            p[1] = 3;
            Game_SetMode(0x1A, g_Game_8013D010.f_8126, g_Game_8013D010.f_812A);
        }
    case 3:
        RaceGoal_AddMonkeyShapes(0xE, p[10]);
        break;
    }
    return 0;
}

typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR rot; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Shape_8013D290;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x4A]; u8 f_7A; u8 pad7B[0x1D5]; } Monkey_8013D290;
extern Monkey_8013D290 g_Monkeys_8013D290[] asm("g_Monkeys");
extern u8 g_Spike_8013D290[] asm("g_Spike");
void *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);

s32 RaceGoal_AddMonkeyShapes(s32 type, s32 idx) {
    SVECTOR v;
    s32 i;
    Monkey_8013D290 *m;
    Shape_8013D290 *s;

    v.vx = 0x1000;
    v.vz = 0;
    v.vy = 0;
    if (idx < 0) {
        for (i = 0; i < 8; i++) {
            m = &g_Monkeys_8013D290[i];
            if (m->f_7A == 4) {
                s = CollShape_Alloc();
                if (s != NULL) {
                    s->rot = v;
                    s->x = m->x;
                    s->y = m->y;
                    s->z = m->z;
                    s->f_20 = 0x200;
                    s->f_24 = 0;
                    s->f_26 = 0;
                    Collision_Set(type, s, g_Spike_8013D290);
                }
            }
        }
    } else {
        s = CollShape_Alloc();
        if (s != NULL) {
            s->rot = v;
            s->x = g_Monkeys_8013D290[idx].x;
            s->y = g_Monkeys_8013D290[idx].y;
            s->z = g_Monkeys_8013D290[idx].z;
            s->f_20 = 0x200;
            s->f_24 = 0;
            s->f_26 = 0;
            Collision_Set(type, s, g_Spike_8013D290);
        }
    }
    return 0;
}

extern GameDraw g_Game_8013D424 asm("g_Game");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Spike_8013D424 asm("g_Spike");
extern struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; } g_Monkeys_8013D424 asm("g_Monkeys");
extern SprtTp *D_800EC354_8013D424 asm("g_GamePrim");

void Race_DrawMinimap(s32 flag) {
    SprtTp *p = (SprtTp *)g_Game_8013D424.prim;
    u32 *ot = g_Game_8013D424.db[g_Game_8013D424.cur].hud;
    s32 x0, y0, bx, by;

    if (flag == 0) {
        x0 = 0x124;
        y0 = 0x64;
        bx = 0x140;
        by = 0xA4;
    } else {
        x0 = 0x104;
        y0 = 0x64;
        bx = 0x128;
        by = 0x88;
    }
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000226;
    p->code = 0x65;
    *(u32 *)&p->w = 0x80008;
    *(u16 *)&p->u0 = 0xF860;
    p->clut = 0x3F9B;
    p->x0 = bx + (g_Spike_8013D424.x >> 8);
    p->y0 = by - (g_Spike_8013D424.z >> 8);
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000226;
    p->code = 0x65;
    *(u32 *)&p->w = 0x80008;
    *(u16 *)&p->u0 = 0xF868;
    p->clut = 0x3F9B;
    p->x0 = bx + (g_Monkeys_8013D424.x >> 8);
    p->y0 = by - (g_Monkeys_8013D424.z >> 8);
    ADD_PRIM_R(ot, p, "$3", "$2");
    p++;
    *(u32 *)&p->x0 = (y0 << 16) | x0;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000226;
    p->code = 0x65;
    p->clut = 0x3FDB;
    if (flag == 0) {
        *(u32 *)&p->w = 0x800040;
        *(u16 *)&p->u0 = 0x8000;
    } else {
        *(u32 *)&p->w = 0x600060;
        *(u16 *)&p->u0 = 0xA000;
    }
    ADD_PRIM_R(ot, p, "$2", "$3");
    p++;
    D_800EC354_8013D424 = p;
}

typedef struct { SVECTOR at; SVECTOR eye; SVECTOR spike; u8 pad18[0x30]; SVECTOR dir; } Scr_401;
void Camera_EaseEye(void *, s32, s32, s32);
void Camera_EaseLookAt(void *, s32, s32, s32);
void CamPoint_GetLookPoint(void *, s32, void *);
void VectorNormalSS(void *, void *);
extern struct { u8 pad0[0xA]; s16 f_A; } D_800E68C0;
extern struct { u8 pad0[0x24]; s16 x; u8 pad26[2]; s16 y; u8 pad2A[2]; s16 z; } g_Spike;

void CamScript_ChaseBehind(void *arg0) {
    SVECTOR v;

    ((Scr_401 *)0x1F800000)->spike.vx = g_Spike.x;
    ((Scr_401 *)0x1F800000)->spike.vy = g_Spike.y;
    ((Scr_401 *)0x1F800000)->spike.vz = g_Spike.z;
    CamPoint_GetLookPoint(arg0, 2, &v);
    v.vy += D_800E68C0.f_A;
    ((Scr_401 *)0x1F800000)->eye.vx = ((Scr_401 *)0x1F800000)->spike.vx;
    ((Scr_401 *)0x1F800000)->eye.vy = g_Spike.y - 0x100;
    ((Scr_401 *)0x1F800000)->eye.vz = ((Scr_401 *)0x1F800000)->spike.vz;
    Camera_EaseLookAt(arg0, 6, 6, 6);
    ((Scr_401 *)0x1F800000)->at.vx = (v.vx * 7 + ((Scr_401 *)0x1F800000)->spike.vx) / 8;
    ((Scr_401 *)0x1F800000)->at.vy = v.vy - D_800E68C0.f_A * 2;
    ((Scr_401 *)0x1F800000)->dir.vx = ((Scr_401 *)0x1F800000)->spike.vx - M2C_FIELD(arg0, s16 *, 0xA);
    ((Scr_401 *)0x1F800000)->dir.vy = 0;
    ((Scr_401 *)0x1F800000)->dir.vz = ((Scr_401 *)0x1F800000)->spike.vz - M2C_FIELD(arg0, s16 *, 0xE);
    VectorNormalSS(&((Scr_401 *)0x1F800000)->dir, &((Scr_401 *)0x1F800000)->dir);
    ((Scr_401 *)0x1F800000)->at.vz = ((Scr_401 *)0x1F800000)->spike.vz - ((Scr_401 *)0x1F800000)->dir.vz / 3;
    Camera_EaseEye(arg0, 6, 6, 6);
}


__asm__(".section .text\n.balign 16");

/* object type tables for this course: {init, update, ?}, zero-terminated */
s32 KnockbackZone_Init();
s32 Link_UpdateKnockbackZone();
void *D_8013D730[9] = {
    KnockbackZone_Init, Link_UpdateKnockbackZone, 0,
    LevelObj_ResetState, RaceGoal_Update, 0,
    0, 0, 0,
};
void *D_8013D754[6] = {
    LevelObj_ResetState, RaceGoal_Update, 0,
    0, 0, 0,
};
