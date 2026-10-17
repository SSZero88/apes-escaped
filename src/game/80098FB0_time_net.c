#include "common.h"
#include "m2c_macros.h"

M2C_UNK func_80015AC0(M2C_UNK *, s32);
typedef struct { s16 m[3][3]; s32 t[3]; } Mat_98FEC;
typedef struct { u8 pad0[0x20]; Mat_98FEC base; Mat_98FEC handle; Mat_98FEC net; } NetObj_98FEC;
extern struct { u8 pad0[0x14]; NetObj_98FEC *obj; } g_TimeNetModel;
extern Mat_98FEC D_800E9C60[];

void TimeNet_Init(s32 arg0) {
    func_80015AC0(&g_TimeNetModel, arg0);
    g_TimeNetModel.obj = (NetObj_98FEC *)D_800E9C60;
}

extern struct { u8 pad0[0x60]; s16 x; s16 y; s16 z; u8 pad66[2]; s16 swingX; s16 swingY; s16 swingZ; } g_GadgetState_98FEC asm("g_GadgetState");
extern s16 D_800F5180;
extern SVECTOR D_800A6830;
extern SVECTOR D_800A6838;
extern Mat_98FEC D_800F4910;
extern Mat_98FEC D_800E78C0_98FEC asm("D_800E78C0");
extern u8 D_800E7D00[];
extern u32 *D_800EC358;
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
void RotTransSV(SVECTOR *a, SVECTOR *b, s32 *flag);
void RotMatrixZYX(SVECTOR *r, Mat_98FEC *m);
void CompMatrix(Mat_98FEC *a, Mat_98FEC *b, Mat_98FEC *c);
void MatrixNormal(Mat_98FEC *a, Mat_98FEC *b);
void func_8004637C(Mat_98FEC *m);
void Model_ProjectBonedVerts(void *m);
void func_80017CD4(u32 *ot, void *buf, void *m);

/* Time Net (gadget 1): projects the net's grip point D_800A6830 through the hand matrix
   D_800F4910 and turns how far it moved since last frame (x64, clamped to +-0x1000) into a swing,
   added to the handle matrix and, halved, to the net's; then draws the model g_TimeNetModel. */
void TimeNet_Update(void) {
    SVECTOR v;
    s32 flag;
    SVECTOR r;
    s32 d;
    s32 e;

    v = D_800A6830;
    SetRotMatrix(&D_800F4910);
    SetTransMatrix(&D_800F4910);
    RotTransSV(&v, &v, &flag);
    d = (D_800F5180 - v.vx) << 6;
    if (d < -0x1000) {
        d = -0x1000;
    } else if (d > 0x1000) {
        d = 0x1000;
    }
    g_GadgetState_98FEC.swingX = d;
    d = (g_GadgetState_98FEC.y - v.vy) << 6;
    d += 0x400;
    if (d < -0x1000) {
        d = -0x1000;
    } else if (d > 0x1000) {
        d = 0x1000;
    }
    g_GadgetState_98FEC.swingY = d;
    e = (g_GadgetState_98FEC.z - v.vz) << 6;
    if (e < -0x1000) {
        e = -0x1000;
    } else if (e > 0x1000) {
        e = 0x1000;
    }
    g_GadgetState_98FEC.swingZ = e;
    g_GadgetState_98FEC.x = v.vx;
    g_GadgetState_98FEC.y = v.vy;
    g_GadgetState_98FEC.z = v.vz;
    g_TimeNetModel.obj->base = D_800E9C60[15];
    r = D_800A6838;
    RotMatrixZYX(&r, &g_TimeNetModel.obj->handle);
    g_TimeNetModel.obj->handle.t[0] = 0x18;
    g_TimeNetModel.obj->handle.t[1] = 0xB8;
    g_TimeNetModel.obj->handle.t[2] = 0;
    CompMatrix(&D_800F4910, &g_TimeNetModel.obj->handle, &g_TimeNetModel.obj->handle);
    g_TimeNetModel.obj->handle.m[0][0] += g_GadgetState_98FEC.swingX;
    g_TimeNetModel.obj->handle.m[1][0] += g_GadgetState_98FEC.swingY;
    g_TimeNetModel.obj->handle.m[2][0] += g_GadgetState_98FEC.swingZ;
    MatrixNormal(&g_TimeNetModel.obj->handle, &g_TimeNetModel.obj->handle);
    func_8004637C(&g_TimeNetModel.obj->net);
    g_TimeNetModel.obj->net.t[0] = 0x60;
    g_TimeNetModel.obj->net.t[1] = 0;
    g_TimeNetModel.obj->net.t[2] = 0;
    CompMatrix(&g_TimeNetModel.obj->handle, &g_TimeNetModel.obj->net, &g_TimeNetModel.obj->net);
    g_TimeNetModel.obj->net.m[0][0] += g_GadgetState_98FEC.swingX >> 1;
    g_TimeNetModel.obj->net.m[1][0] += g_GadgetState_98FEC.swingY >> 1;
    g_TimeNetModel.obj->net.m[2][0] += g_GadgetState_98FEC.swingZ >> 1;
    MatrixNormal(&g_TimeNetModel.obj->net, &g_TimeNetModel.obj->net);
    CompMatrix(&D_800E78C0_98FEC, &g_TimeNetModel.obj->handle, &g_TimeNetModel.obj->handle);
    CompMatrix(&D_800E78C0_98FEC, &g_TimeNetModel.obj->net, &g_TimeNetModel.obj->net);
    Model_ProjectBonedVerts(&g_TimeNetModel);
    func_80017CD4(D_800EC358, D_800E7D00, &g_TimeNetModel);
}

INCLUDE_RODATA("asm/nonmatchings/game/80098FB0_time_net", D_800A6830);
INCLUDE_RODATA("asm/nonmatchings/game/80098FB0_time_net", D_800A6838);

