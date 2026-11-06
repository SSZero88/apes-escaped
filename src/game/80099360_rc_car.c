#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s16 vx, vy, vz, pad; } SVEC_80099360_80099360;
typedef struct { u8 pad[0x4078]; } Db_99C44_80099C44;
typedef struct { u8 pad0[0xC]; s32 cur; u8 pad10[0x70]; Db_99C44_80099C44 db[2]; } Game_99C44_80099C44;
typedef struct { u8 pad[0x20]; } Mat_99C44_80099C44;
typedef struct { u8 pad0[4]; u16 f_4; } Hdr_99C44_80099C44;
typedef struct { u8 pad0[0xF2]; s8 f_F2; } Sp_99C44_80099C44;

M2C_UNK Collision_Remove(void *);
extern struct S_D_800F5A20 { u8 pad_0[0x70]; s32 f_70; } g_RcCar;
extern struct S_D_800EC1E0 { u8 pad0[0x60]; SVEC_80099360_80099360 f_60; SVEC_80099360_80099360 f_68; } g_Spike;
s32 func_8007CA48(s32);
void RcCar_Remove(void);
void Collision_Set(s32, s32 *, struct S_D_800F5A20 *);
struct S_D_800F5A20_80099360 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[8]; s16 f_44; s16 f_46; u8 pad48[8]; s32 f_50; u8 pad54[0xC]; SVEC_80099360_80099360 f_60; SVEC_80099360_80099360 f_68; s32 f_70; u8 pad74[4]; s16 f_78; };
extern Game_99C44_80099C44 g_Game;
extern struct S_D_800EC060 { Hdr_99C44_80099C44 *hdr; u8 pad4[0xC]; } D_800EC060[];
extern Mat_99C44_80099C44 D_800E9C60[];
extern Mat_99C44_80099C44 D_800F4730[];
extern u8 D_800E7D00[];
void Model_ProjectVerts(struct S_D_800EC060 *, Mat_99C44_80099C44 *, u8 *);
void func_8006CFBC(Mat_99C44_80099C44 *);
void func_80017CD4(Db_99C44_80099C44 *, u8 *, struct S_D_800EC060 *);

void RcCar_Place(s32 x, s32 y, s32 z) {
    struct S_D_800F5A20_80099360 *s;

    if (func_8007CA48(7) == 0) {
        return;
    }
    s = ((struct S_D_800F5A20_80099360 *)&g_RcCar);
    if (s->f_70 != 0) {
        if (s->f_78 > 0) {
            return;
        }
        RcCar_Remove();
    }
    s->f_70 = 1;
    s->f_24 = x;
    s->f_2C = z;
    s->f_28 = y;
    s->f_30 = 0;
    s->f_34 = 0;
    s->f_38 = 0;
    s->f_60 = g_Spike.f_60;
    s->f_68 = g_Spike.f_68;
    s->f_44 = 0x40;
    s->f_46 = 0x40;
    s->f_50 = 0;
    Collision_Set(2, &s->f_24, s);
    s->f_78 = 10;
}

void RcCar_Remove(void) {
    if (g_RcCar.f_70 != 0) {
        g_RcCar.f_70 = 0;
        Collision_Remove((void *)((u8 *)&g_RcCar + 0x24));
    }
}

typedef struct { s16 vx, vy, vz, pad; } SV_9A8;
typedef struct { s32 x, y, z; u8 padC[0xC]; SV_9A8 dir; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Col_9A8;
typedef struct { u8 pad0[0x24]; s32 x, y, z, vx, vy, vz; u8 pad3C[0xA]; s16 f_46; u8 pad48[8]; u32 f_50; u8 pad54[0xC]; SV_9A8 f_60; SV_9A8 f_68; s32 f_70; u16 f_74; u16 f_76; s16 f_78; s16 f_7A; } RC_9A8;
typedef struct { u8 pad0[8]; u16 f_8; u8 padA[2]; s16 f_C; s16 f_E; } Sc_9A8;
typedef struct { u8 pad0[0x60]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0x82]; s16 f_E8; u8 padEA[8]; s8 gadget; } Sp_9A8;
typedef struct { u8 pad0[0x182]; u16 f_182; u8 pad184[0x18]; s16 f_19C; } Pad_9A8;
extern RC_9A8 g_RcCar_9A8 asm("g_RcCar");
extern Sp_9A8 g_Spike_9A8 asm("g_Spike");
extern Pad_9A8 g_Pad_9A8 asm("g_Pad");
extern struct { s32 frame; u8 pad4[0x814C]; u16 f_8150; } g_Game_9A8 asm("g_Game");
extern u8 D_800F5A80[];
s32 Floor_GetHeight_9A8(s32, s32, s32) asm("Floor_GetHeight");
void VectorNormalSS_9A8(void *, void *) asm("VectorNormalSS");
void Effect_SpawnAt_9A8(s32, void *) asm("Effect_SpawnAt");
void Sound_PlayFixed_9A8(s32) asm("Sound_PlayFixed");
void func_80066C90_9A8(void *, void *, s32) asm("func_80066C90");
Col_9A8 *CollShape_Alloc_9A8(void) asm("CollShape_Alloc");
s32 Collision_Set_9A8(s32, void *, void *) asm("Collision_Set");
u16 Water_Query_9A8(s32, s32, s32) asm("Water_Query");
void Puff_Spawn_9A8(void *, s32, s32, s32) asm("Puff_Spawn");
s32 Projectile_Spawn_9A8(void *, void *, s32) asm("Projectile_Spawn");
s32 func_800463A4_9A8(s32, s32, s32) asm("func_800463A4");
void memset_9A8(void *, s32, s32) asm("memset");

void RcCar_Update(void) {
    SV_9A8 p;
    SV_9A8 q;
    SV_9A8 z;
    s32 ground;
    s32 tx;
    s32 tz;

    if (g_RcCar_9A8.f_70 == 0) {
        return;
    }
    if (g_RcCar_9A8.vy < -14) {
        g_RcCar_9A8.vy = -14;
    }
    g_RcCar_9A8.vy += 7;
    if (g_RcCar_9A8.f_78 > 0) {
        Sp_9A8 *sp = &g_Spike_9A8;
        s32 a = sp->f_60;
        s32 b;
        g_RcCar_9A8.f_78--;
        b = sp->f_64;
        g_RcCar_9A8.vx = a >> 8;
        g_RcCar_9A8.vz = b >> 8;
        return;
    }
    ground = Floor_GetHeight_9A8(g_RcCar_9A8.x, g_RcCar_9A8.y, g_RcCar_9A8.z);
    if (g_RcCar_9A8.y >= ground) {
        Sc_9A8 *sc = (Sc_9A8 *)0x1F8003F0;
        s32 k;
        s16 nx, nz;
        g_RcCar_9A8.f_68.vy = 0x200;
        nx = sc->f_C;
        nz = sc->f_E;
        g_RcCar_9A8.f_68.vx = -nx;
        g_RcCar_9A8.f_68.vz = -nz;
        VectorNormalSS_9A8(&g_RcCar_9A8.f_68, &g_RcCar_9A8.f_68);
        if (sc->f_8 & 1) {
            k = (sc->f_8 >> 1) & 7;
            if (k < 4) { if (k >= 0) {
                { s16 px = g_RcCar_9A8.x, py = g_RcCar_9A8.y, pz = g_RcCar_9A8.z;
                p.vx = px;
                p.vy = py;
                p.vz = pz; }
                Effect_SpawnAt_9A8(0x102, &p);
                RcCar_Remove();
                Sound_PlayFixed_9A8(0x79);
            } }
        }
    }
    if (func_8007CA48(7) && g_Spike_9A8.gadget == 7 && g_Spike_9A8.f_E8 > 0) {
        if (g_RcCar_9A8.y >= ground) {
            s32 m = g_Game_9A8.f_8150;
            if (m < 4) { if (m != 0) {
                tx = 0;
                tz = tx;
                goto have;
            } }
            {
                Pad_9A8 *pad = &g_Pad_9A8;
                if (pad->f_182 != 0) {
                    func_80066C90_9A8(&pad->f_19C, D_800F5A80, 0x155);
                }
                {
                tx = g_RcCar_9A8.f_60.vx * pad->f_182 / 0x3000;
                tz = g_RcCar_9A8.f_60.vz * pad->f_182 / 0x3000; }
                // * pad->f_182 / 0x3000;
                tz = g_RcCar_9A8.f_60.vz * pad->f_182 / 0x3000;
            }
            have: {
                Sc_9A8 *sc = (Sc_9A8 *)0x1F8003F0;
                s32 nx = sc->f_C;
                s32 nz = sc->f_E;
                if ((u32)(nx + 0x200) > 0x400) {
                    tx = g_RcCar_9A8.vx + 0xE00 / nx;
                }
                if ((u32)(nz + 0x200) > 0x400) {
                    tz = g_RcCar_9A8.vz + 0xE00 / nz;
                }
            }
        } else {
            tx = g_RcCar_9A8.vx;
            tz = g_RcCar_9A8.vz;
        }
        {
        if (g_RcCar_9A8.vx * g_RcCar_9A8.vx + g_RcCar_9A8.vz * g_RcCar_9A8.vz >= 0x385) {
            Col_9A8 *col = CollShape_Alloc_9A8();
            if (col != 0) {
                col->x = g_RcCar_9A8.x;
                col->y = g_RcCar_9A8.y - g_RcCar_9A8.f_46 / 2;
                col->z = g_RcCar_9A8.z;
                col->f_20 = 0x50;
                col->dir = g_RcCar_9A8.f_60;
                col->f_24 = 0x22;
                col->f_26 = 0x201;
                Collision_Set_9A8(6, col, &g_RcCar_9A8);
            }
        } }
    } else {
        tx = 0;
        tz = tx;
    }
    {
    g_RcCar_9A8.f_74 = g_RcCar_9A8.f_76;
    {
        u16 w = Water_Query_9A8(g_RcCar_9A8.x, g_RcCar_9A8.y, g_RcCar_9A8.z);
        g_RcCar_9A8.f_76 = w;
        if ((w >> 12) == 1) {
            p.vx = g_RcCar_9A8.x;
            p.vy = g_RcCar_9A8.y;
            p.vz = g_RcCar_9A8.z;
            if ((g_RcCar_9A8.f_74 >> 12) != 1) {
                Effect_SpawnAt_9A8(0x100, &p);
                Sound_PlayFixed_9A8(0x72);
                g_RcCar_9A8.f_7A = 0;
            }
            if (++g_RcCar_9A8.f_7A >= 0x1F) {
                Effect_SpawnAt_9A8(0x102, &p);
                Sound_PlayFixed_9A8(0x79);
                RcCar_Remove();
            } else if (!(g_Game_9A8.frame & 7)) {
                Puff_Spawn_9A8(&g_RcCar_9A8.x, 1, 0, 0x60);
            }
        }
    }
    }
    if ((g_RcCar_9A8.f_50 >> 28) == 0xB) {
        Sound_PlayFixed_9A8(0x79);
        q.vx = g_RcCar_9A8.x;
        q.vy = g_RcCar_9A8.y;
        q.vz = g_RcCar_9A8.z;
        Effect_SpawnAt_9A8(0x102, &q);
        z.vx = 0;
        z.vy = 0;
        z.vz = 0;
        Projectile_Spawn_9A8(&q, &z, 6);
        RcCar_Remove();
    }
    if (g_RcCar_9A8.vy < -7) {
        g_RcCar_9A8.vx = (g_RcCar_9A8.vx + tx) >> 2;
        g_RcCar_9A8.vz = (g_RcCar_9A8.vz + tz) >> 2;
        return;
    }
    {
        s32 nvx = func_800463A4_9A8(g_RcCar_9A8.vx, tx, 4);
        s32 nvz = func_800463A4_9A8(g_RcCar_9A8.vz, tz, 4);
        g_RcCar_9A8.vx = nvx;
        g_RcCar_9A8.vz = nvz;
        if (((nvx != tx) | (nvz != tz)) && !(g_Game_9A8.frame & 1)) {
            memset_9A8(&z, 0, 8);
            z.vx = g_RcCar_9A8.x;
            z.vy = g_RcCar_9A8.y;
            z.vz = g_RcCar_9A8.z;
            q = z;
            Effect_SpawnAt_9A8(4, &q);
        }
    }
}

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_80099AE0;
extern struct S_D_800F5A20_80099360 g_RcCar_80099AE0 asm("g_RcCar");
extern MAT_80099AE0 D_800E78C0;
extern struct S_D_800EC060 D_800EC110;
extern s8 g_CurrentGadget;
void Matrix_LookAt(SVEC_80099360_80099360 *, SVEC_80099360_80099360 *, MAT_80099AE0 *, s32);
void CompMatrix(MAT_80099AE0 *, MAT_80099AE0 *, MAT_80099AE0 *);
void Model_CycleVertexColors(u8 *, u16);
void Model_DrawCycledColors(Db_99C44_80099C44 *, u8 *, struct S_D_800EC060 *);
void func_8006D044(void);

void func_80099AE0(void) {
    struct S_D_800F5A20_80099360 *o = &g_RcCar_80099AE0;
    MAT_80099AE0 m;
    struct S_D_800EC060 *obj;
    u8 *buf;
    if (o->f_70 == 0) {
        return;
    }
    Matrix_LookAt(&o->f_60, &o->f_68, &m, 0);
    m.t[0] = o->f_24;
    m.t[1] = o->f_28;
    m.t[2] = o->f_2C;
    CompMatrix(&D_800E78C0, &m, &m);
    obj = &D_800EC110;
    buf = D_800E7D00;
    Model_ProjectVerts(obj, (Mat_99C44_80099C44 *)&m, buf);
    __asm__("" :: "r"(buf), "r"(buf), "r"(buf), "r"(o), "r"(o), "r"(o));
    if (o->f_78 > 0) {
        __asm__("" : "=r"(obj) : "0"(obj));
        Model_CycleVertexColors(buf, ((u16 *)obj->hdr)[3]);
        Model_DrawCycledColors(&g_Game.db[g_Game.cur], buf, obj);
    } else {
        func_80017CD4(&g_Game.db[g_Game.cur], buf, obj);
    }
    if (g_CurrentGadget != 7) {
        g_RcCar_80099AE0.f_30 = 0;
        g_RcCar_80099AE0.f_38 = 0;
        g_RcCar_80099AE0.f_34 += 7;
    }
    func_8006D044();
}

void func_80099C44(void) {
    Model_ProjectVerts(&D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2], &D_800E9C60[D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2].hdr->f_4], D_800E7D00);
    func_8006CFBC(&D_800F4730[D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2].hdr->f_4]);
    func_80017CD4(&g_Game.db[g_Game.cur], D_800E7D00, &D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2]);
}
