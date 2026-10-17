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

INCLUDE_ASM("asm/nonmatchings/game/80099360", RcCar_Update);

INCLUDE_ASM("asm/nonmatchings/game/80099360", func_80099AE0);

void func_80099C44(void) {
    Model_ProjectVerts(&D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2], &D_800E9C60[D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2].hdr->f_4], D_800E7D00);
    func_8006CFBC(&D_800F4730[D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2].hdr->f_4]);
    func_80017CD4(&g_Game.db[g_Game.cur], D_800E7D00, &D_800EC060[(*(Sp_99C44_80099C44 *)&g_Spike).f_F2]);
}
