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
void func_800A3740(void *, s32, s32);
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

INCLUDE_ASM("asm/nonmatchings/game/80099D20_radar", func_80099D70);

s32 func_8009A17C(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, u8 *, 0x7A) == 4) {
        var_a1 = ((u32) M2C_FIELD(arg0, u32 *, 0x248) >> 0x12) & 1;
    }
    return var_a1;
}

INCLUDE_ASM("asm/nonmatchings/game/80099D20_radar", Radar_GetSignal);

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
        func_800A3740(&tmp, 0, 16);
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
