#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s32 vx, vy, vz, pad; } VEC_9A574_8009A574;
typedef struct { s16 vx, vy, vz, pad; } SV_9A574_8009A574;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_9A574_8009A574;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; Db_9A574_8009A574 db[2]; } Game_9A574_8009A574;

extern struct S_D_800EC1E0 { u8 pad_0[0x60]; SVECTOR f_60; } g_Spike;
extern struct S_D_800F5120 { u8 pad_0[0x4]; SVECTOR f_4; s32 f_C; s32 f_10; s16 f_14; s16 f_16; s32 f_18; s32 f_1C; } g_GadgetState;

void func_8007CD0C(s32);
void Radar_DrawModel();
extern u16 D_800EC23E;
extern Game_9A574_8009A574 g_Game;
extern struct S_D_800EC080 { u8 pad0[0xC]; u8 *f_C; } D_800EC080[];
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
extern u8 D_800E7D00[];
void Model_ProjectVerts(struct S_D_800EC080 *, struct S_D_800E78C0 *, u8 *);
void func_80017CD4(u32 *, u8 *, struct S_D_800EC080 *);
void SetRotMatrix(struct S_D_800E78C0 *);
void SetTransMatrix(struct S_D_800E78C0 *);
void RotTransSV(SV_9A574_8009A574 *, SV_9A574_8009A574 *, s32 *);
void func_8004637C(struct S_D_800E78C0 *);
void RotMatrixX(s32, struct S_D_800E78C0 *);
void RotMatrixY(s32, struct S_D_800E78C0 *);
void CompMatrix(struct S_D_800E78C0 *, struct S_D_800E78C0 *, struct S_D_800E78C0 *);
void func_80014804(SV_9A574_8009A574 *, struct S_D_800E78C0 *);
void memset(void *, s32, s32);
void ScaleMatrix(struct S_D_800E78C0 *, VEC_9A574_8009A574 *);

void func_80099D20(void) {
    g_GadgetState.f_4 = g_Spike.f_60;
    g_GadgetState.f_C = 0;
    g_GadgetState.f_10 = 0;
    g_GadgetState.f_14 = -1;
    g_GadgetState.f_16 = -1;
    g_GadgetState.f_18 = 0;
    g_GadgetState.f_1C = 0;
}

typedef struct { u32 addr : 24; u32 len : 8; } P_TAG_99D70;
typedef struct { P_TAG_99D70 tag; u32 tpage; u8 r0, g0, b0, code; s16 x0, y0; u32 uvclut; u32 wh; } Spr_99D70;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_99D70;
typedef struct { u32 frame; Spr_99D70 *prim; u8 pad8[4]; s32 cur; Db_99D70 db[2]; u8 padRest[0x8100 - 0x10 - 2 * sizeof(Db_99D70)]; u32 f_8100; } Game_99D70;
typedef struct { u8 pad0[8]; void *f_8; } Mdl_99D70;
typedef struct { u8 pad0[0x140]; u16 x; u16 y; } Scr_99D70;
extern Game_99D70 g_Game_99D70 asm("g_Game");
extern struct { u8 pad0[0x17A]; u16 f_17A; u8 pad17C[0x20]; SVECTOR f_19C; } g_Pad;
extern s16 g_SpikeHealth;
extern u8 D_800E9E40[];
extern u8 D_800F4910[];
extern Mdl_99D70 D_800EC170;
extern SVECTOR D_800EC240;
s32 func_8007CA48(s32);
void func_80066C90(SVECTOR *, SVECTOR *, s32);
s32 Radar_GetSignal(void);
void func_8009A4E8(s32, s32, s32, s32);
void func_80020A20(Mdl_99D70 *, s32, s32, s32, s32);
void Model_DrawPrims(u32 *, void *, u8 *);
void Sound_Stop(s32, s32);
s16 Sound_Play(s32, s32);
void func_80087C28(s32, s32, s32);
void Pad_Vibrate(s32, s32, s32);
s32 func_8009A17C(void *);

void func_80099D70(void) {
    s32 sig;
    u32 *ot;
    u32 c;
    Spr_99D70 *p;
    u32 t;

    if (g_Game_99D70.f_8100 & 1) {
        func_8009A4E8((s32)D_800E9E40, (s32)D_800F4910, (s32)&g_GadgetState.f_4, g_Game_99D70.frame << 7);
        return;
    }
    if (func_8007CA48(2) && g_Pad.f_17A != 0 && g_SpikeHealth > 0) {
        func_80066C90(&g_Pad.f_19C, &g_GadgetState.f_4, 0x155);
        sig = Radar_GetSignal();
        func_8009A4E8((s32)D_800E9E40, (s32)D_800F4910, (s32)&g_GadgetState.f_4, g_Game_99D70.frame << 7);
        if (sig > 0) {
            Scr_99D70 *scr;
            ot = &g_Game_99D70.db[g_Game_99D70.cur].ot[1];
            if (sig < 21) {
                c = sig * 8 + 0x20;
            } else {
                c = 0xFF;
            }
            c |= (c >> 1) << 16 | (c >> 1) << 8;
            func_80020A20(&D_800EC170, (g_Game_99D70.frame & 0x1F) << 8, 0, 6, c);
            Model_DrawPrims(g_Game_99D70.db[g_Game_99D70.cur].ot, D_800EC170.f_8, (u8 *)(scr = (Scr_99D70 *)D_800E7D00));
            __asm__("" : : "r"(scr));
            p = g_Game_99D70.prim;
            if (g_Game_99D70.frame % (40 - sig) < 10) {
                p->tag.len = 5;
                p->tpage = 0xE100023D;
                p->code = 0x67;
                p->x0 = scr->x - 0xF;
                p->y0 = scr->y - 0x22;
                p->uvclut = 0x713740A0;
                p->wh = 0x200020;
                {
                    u32 t1, t2;
                    __asm__ volatile("lwl %0, %2
	sll %1, %4, 8
	swl %1, %2
	swl %0, %3"
                                     : "=&r"(t1), "=&r"(t2)
                                     : "m"(*((u8 *)ot + 2)), "m"(*((u8 *)p + 2)), "r"(p));
                }
                p++;
            }
            g_Game_99D70.prim = p;
            if (g_GadgetState.f_14 != -1) {
                Sound_Stop(0x25, g_GadgetState.f_14);
                g_GadgetState.f_14 = -1;
            }
            if (g_GadgetState.f_16 == -1) {
                g_GadgetState.f_16 = Sound_Play(0, 0x26);
            } else {
                func_80087C28(0x26, g_GadgetState.f_16, sig * 80 + 0x1000);
                Pad_Vibrate(1, sig * 4 + 0x28, 2);
            }
        } else {
            func_80020A20(&D_800EC170, ((g_Game_99D70.frame & 0x1F) << 8) | 0x20, 0, 6, 0x202020);
            Model_DrawPrims(g_Game_99D70.db[g_Game_99D70.cur].ot, D_800EC170.f_8, D_800E7D00);
            if (g_GadgetState.f_16 != -1) {
                Sound_Stop(0x26, g_GadgetState.f_16);
                g_GadgetState.f_16 = -1;
            }
            if (g_GadgetState.f_14 == -1) {
                g_GadgetState.f_14 = Sound_Play(0, 0x25);
            }
        }
    } else {
        func_80066C90(&D_800EC240, &g_GadgetState.f_4, 0x155);
        func_8009A4E8((s32)D_800E9E40, (s32)D_800F4910, (s32)&g_GadgetState.f_4, 0);
        if (g_GadgetState.f_14 != -1) {
            Sound_Stop(0x25, g_GadgetState.f_14);
            g_GadgetState.f_14 = -1;
        }
        if (g_GadgetState.f_16 != -1) {
            Sound_Stop(0x26, g_GadgetState.f_16);
            g_GadgetState.f_16 = -1;
        }
    }
    if (g_GadgetState.f_1C != 0 && !func_8009A17C((void *)g_GadgetState.f_18)) {
        g_GadgetState.f_1C = 0;
    }
}

s32 func_8009A17C(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, u8 *, 0x7A) == 4) {
        var_a1 = ((u32) M2C_FIELD(arg0, u32 *, 0x248) >> 0x12) & 1;
    }
    return var_a1;
}

typedef struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; u8 pad2E[0x4C]; u8 f_7A; u8 pad7B[0x1D5]; } Mky_9A1A4;
typedef struct { s32 type; s32 x, y, z; u8 pad10[0x10]; s32 dest; s32 sub; } Zone_9A1A4;
typedef struct { s16 vx, vy, vz, pad; } SV_9A1A4;
extern Mky_9A1A4 g_Monkeys_9A1A4[8] asm("g_Monkeys");
extern struct { u8 pad0[0x24]; u16 x; u8 pad26[6]; u16 z; u8 pad2E[0x32]; s16 dx; u8 pad62[2]; s16 dz; } g_Spike_9A1A4 asm("g_Spike");
extern struct { u8 pad0[4]; s16 dx; u8 pad6[2]; s16 dz; u8 padA[0xE]; Mky_9A1A4 *target; s32 f_1C; } g_GadgetState_9A1A4 asm("g_GadgetState");
extern struct { u8 pad0[0x8238]; Zone_9A1A4 *zones; u8 pad823C[0x50]; s32 nzones; } g_Game_9A1A4 asm("g_Game");
s32 VectorNormalSS_9A1A4(SV_9A1A4 *, SV_9A1A4 *) asm("VectorNormalSS");
s32 Math_ISqrt(s32);
u8 *func_80097E88_9A1A4(s32, s32 *) asm("func_80097E88");

/* Monkey Radar signal strength (0..0x20): for each active monkey (state not 0/2/3), the cosine
   between the radar heading and the direction to it, scaled by distance; strongest one becomes the
   radar target. With no monkeys around, 1 if some zone (g_Game+0x8238) points
   at a stage whose monkey list still has uncaught monkeys and lies in the radar heading. */
s32 Radar_GetSignal(void) {
    SV_9A1A4 v;
    s32 n;
    s32 sum = 0;
    s32 count = 0;
    s32 best = 0;
    s32 i;
    s32 j;
    s32 k;
    s32 c;
    s32 d;
    s32 s;
    Mky_9A1A4 *m;
    Zone_9A1A4 *z;
    Zone_9A1A4 *zs;
    u8 *list;

    for (i = 0; i < 8; i++) {
        m = &g_Monkeys_9A1A4[i];
        if ((u8)(m->f_7A - 2) < 2) {
            continue;
        }
        if (m->f_7A == 0) {
            continue;
        }
        v.vx = m->x - g_Spike_9A1A4.x + (g_Spike_9A1A4.dx >> 5);
        v.vy = 0;
        v.vz = m->z - g_Spike_9A1A4.z + (g_Spike_9A1A4.dz >> 5);
        k = Math_ISqrt(VectorNormalSS_9A1A4(&v, &v));
        c = v.vx * g_GadgetState_9A1A4.dx + v.vz * g_GadgetState_9A1A4.dz;
        c >>= 12;
        d = k;
        count++;
        if (c < 0xDDC) {
            continue;
        }
        if (d > 0x200) {
            c -= 0xDDB;
            s = (c << 12) / (d * 549 / 4 + 1) + 2;
        } else {
            s = 0x1000 / (d / 4 + 1) + 2;
        }
        sum += s;
        if (best < s) {
            best = s;
            g_GadgetState_9A1A4.f_1C = 1;
            g_GadgetState_9A1A4.target = m;
        }
    }
    if (count == 0) {
        zs = g_Game_9A1A4.zones;
        for (i = 0; i < g_Game_9A1A4.nzones; i++) {
            z = &zs[i];
            list = func_80097E88_9A1A4(z->dest, &n);
            if (list == 0) {
                break;
            }
            k = 0;
            for (j = 0; j < 8; j++) {
                if ((u8)(list[j] - 2) < 2) {
                    k++;
                }
            }
            if (k < n) {
                v.vx = z->x - g_Spike_9A1A4.x;
                v.vy = 0;
                v.vz = z->z - g_Spike_9A1A4.z;
                Math_ISqrt(VectorNormalSS_9A1A4(&v, &v));
                c = (v.vx * g_GadgetState_9A1A4.dx + v.vz * g_GadgetState_9A1A4.dz) >> 12;
                if (c >= 0xDDC) {
                    sum = 1;
                }
            }
        }
    }
    if (sum > 0x20) {
        sum = 0x20;
    }
    return sum;
}

void func_8009A4E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v = D_800EC23E;

    if (v < 0x3D) {
        if (v >= 0x38) {
            func_8007CD0C(0);
            return;
        }
    }
    func_8007CD0C(1);
    Radar_DrawModel(arg0, arg1, arg2, arg3);
}

/* Draws the Monkey Radar model: the body (model 0) on base, model 14 twice (mirrored about y,
 * tilted by angle; probably the two halves of the lid or antenna), then models 13 and 15 at
 * body vertex 0x140 transformed by rt, oriented along dir and scaled by dir->vy when positive. */
void Radar_DrawModel(struct S_D_800E78C0 *base, struct S_D_800E78C0 *rt, SV_9A574_8009A574 *dir, s32 angle) {
    SV_9A574_8009A574 sv;
    struct S_D_800E78C0 m;
    VEC_9A574_8009A574 sc;
    VEC_9A574_8009A574 tmp;
    s32 flag;
    u32 *ot;
    s32 x, y, z;

    ot = g_Game.db[g_Game.cur].ot;
    Model_ProjectVerts(&D_800EC080[0], base, D_800E7D00);
    func_80017CD4(ot, D_800E7D00, &D_800EC080[0]);
    SetRotMatrix(rt);
    SetTransMatrix(rt);
    RotTransSV((SV_9A574_8009A574 *)(D_800EC080[0].f_C + 0x140), &sv, &flag);
    func_8004637C(&m);
    m.t[0] = 4;
    m.t[1] = 0x80;
    m.t[2] = 4;
    RotMatrixX(angle, &m);
    RotMatrixY(0x400, &m);
    CompMatrix(base, &m, &m);
    Model_ProjectVerts(&D_800EC080[14], &m, D_800E7D00);
    func_80017CD4(ot, D_800E7D00, &D_800EC080[14]);
    func_8004637C(&m);
    m.t[0] = 4;
    m.t[1] = 0x80;
    m.t[2] = -0x40;
    RotMatrixX(angle, &m);
    RotMatrixY(-0x400, &m);
    CompMatrix(base, &m, &m);
    Model_ProjectVerts(&D_800EC080[14], &m, D_800E7D00);
    func_80017CD4(ot, D_800E7D00, &D_800EC080[14]);
    x = sv.vx;
    y = sv.vy;
    z = sv.vz;
    func_80014804(dir, &m);
    if (dir->vy > 0) {
        memset(&tmp, 0, 16);
        tmp.vx = dir->vy;
        tmp.vy = dir->vy;
        tmp.vz = dir->vy;
        sc = tmp;
        ScaleMatrix(&m, &sc);
    }
    m.t[0] = x;
    m.t[1] = y;
    m.t[2] = z;
    CompMatrix(&D_800E78C0, &m, &m);
    Model_ProjectVerts(&D_800EC080[13], &m, D_800E7D00);
    func_80017CD4(ot, D_800E7D00, &D_800EC080[13]);
    Model_ProjectVerts(&D_800EC080[15], &m, D_800E7D00);
}
