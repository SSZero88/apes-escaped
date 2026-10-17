#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#define SP_80066ADC ((struct Spike_80066ADC *)&g_Spike)
#define SP_64208 ((struct Spike_80064208 *)&g_Spike)
#define SP ((Sp_80067CAC_80067CAC *)&g_Spike)
#define G_SPIKE_80065A24 ((struct g_Spike_80065A24 *)&g_Spike)
#define G_SPIKE_800655C4 ((struct g_Spike_800655C4 *)&g_Spike)
#define G_PAD_800655C4 ((struct g_Pad_800655C4 *)&g_Pad)
#define SPIKE_F2 (*(s8 *)((u8 *)&g_Spike + 0xF2))
#define G_SPIKE_80066DAC ((struct g_Spike_80066DAC *)&g_Spike)
#define G_SPIKE_80066358 ((struct g_Spike_80066358 *)&g_Spike)
#define G_PAD_80066358 ((struct g_Pad_80066358 *)&g_Pad)
#define G_SPIKE_80065C20 ((struct g_Spike_80065C20 *)&g_Spike)
#define G_GADGETSTATE_80065C20 ((struct g_GadgetState_80065C20 *)&g_GadgetState)
#include "common.h"
typedef struct { s16 vx, vy, vz, pad; } SVEC_80066C90;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX_80066C90;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u16 f_6; } S_1F800048_80065B6C;
typedef struct { u8 pad0[0x86]; s16 f_86; } S_4D70_80067AF0_80067AF0;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_800689F0;
typedef struct { s32 vx, vy, vz, pad; } VEC_800689F0;
typedef struct { u8 pad0[6]; u16 f_6; } S_Hdr_800689F0;
typedef struct { u8 pad0[0x114]; s32 f_114; u8 pad118[4]; s32 f_11C; s32 f_120; u8 pad124[4]; s32 f_128; } S_EC1E0_8006699C_8006699C;
typedef struct { u16 start; u16 end; u32 flags; } Anim_80064208_80064208;
typedef struct { u8 pad0[0x48]; Anim_80064208_80064208 *tbl; } Scr_80064208_80064208;
typedef struct { s16 vx, vy, vz, pad; } SV_80063EC4_80063EC4;
typedef struct { u8 pad0[0x24]; s32 x, y, z; s32 f_30, f_34, f_38; u8 pad3C[8]; s16 f_44; s16 f_46; u8 pad48[8]; u32 f_50; u8 pad54[0xC]; SV_80063EC4_80063EC4 dir; u8 pad68[8]; s32 f_70; u8 pad74[0x74]; s16 f_E8; u8 padEA[0x1A]; s32 f_104; } Sp_80063EC4_80063EC4;
typedef struct { u16 start; u16 end; u32 flags; } Anim_80064208_80064208_80067CAC;
typedef struct { s16 vx, vy, vz, pad; } SV_80067CAC_80067CAC;
typedef struct { u8 pad0[0x48]; Anim_80064208_80064208_80067CAC *tbl; void *f_4C; void *f_50; s32 f_54; s32 f_58; u8 pad5C[0x24]; s32 f_80; } Scr_80067CAC_80067CAC;
typedef struct { u8 pad0[0x24]; s32 x, y, z, vx, vy, vz; u8 pad3C[0x20]; u16 frame; u16 state; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0xE]; SV_80067CAC_80067CAC f_74; u8 pad7C[0x38]; s16 f_B4; s16 f_B6; s16 f_B8; s16 f_BA; u8 padBC[2]; s16 f_BE; u8 padC0[0x32]; s8 gadget; u8 padF3[0x2D]; s32 f_120; s32 f_124; s32 f_128; } Sp_80067CAC_80067CAC;
typedef struct { void *f_0; Anim_80064208_80064208_80067CAC *f_4; void *f_8; void *f_C; } AS_80067CAC_80067CAC;
typedef struct { u8 pad0[0x100]; u16 f_100; u8 pad102[0x22]; s32 f_124; } Sp_65ED4_80065ED4;
typedef struct { u8 pad0[0x1B4]; u16 f_1B4; u8 pad1B6[6]; s16 f_1BC; } Pad_65ED4_80065ED4;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u16 f_6; } S_1F800048_800655C4;
typedef struct { s16 vx, vy, vz, pad; } SV_657F0_800657F0;
typedef struct { u8 pad0[0x60]; SV_657F0_800657F0 f_60; u8 pad68[8]; u32 f_70; u8 pad74[8]; s32 f_7C; SV_657F0_800657F0 f_80; u8 pad88[0xB0]; u16 f_138; u8 pad13A[0xB8]; s8 f_F2_dummy; } Sp_657F0_800657F0;
typedef struct { u8 pad0[0xA4]; u16 f_A4[40]; u8 padF4[0x7C]; s32 f_170; } S_E5320_80064B24;
typedef struct { u8 pad0[0x34]; s32 f_34; u8 pad38[0x26]; u16 f_5E; u8 pad60[0x80]; u32 f_E0; u8 padE4[0x18]; s16 f_FC; s16 f_FE; } S_EC1E0_80066770_80066770;
typedef struct { s16 vx, vy, vz, pad; } SVEC_800661D4_800661D4;
typedef struct { u8 pad0[0x64]; u16 f_64; } SCR_800661D4_800661D4;

s32 rcos(s32);
void func_8004637C(MATRIX_80066C90 *);
void RotMatrixY(s32, MATRIX_80066C90 *);

extern struct S_D_800EC1E0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x24]; s16 f_60; s16 f_62; s16 f_64; u8 pad_66[0xA]; s32 f_70; s16 f_74; s16 f_76; s16 f_78; u8 pad_7A[0x12]; s16 f_8C; u8 pad_8E[0x26]; s16 f_B4; s16 f_B6; s16 f_B8; s16 f_BA; s16 f_BC; s16 f_BE; s16 f_C0; s16 f_C2; s16 f_C4; s16 f_C6; s16 f_C8; s16 f_CA; u8 pad_CC[0x12]; u16 f_DE; s32 f_E0; u8 pad_E4[0x4]; s16 f_E8; u8 pad_EA[0x16]; s16 f_100; u8 pad_102[0x2]; s16 f_104; s16 f_106; s32 f_108; u8 pad_10C[0x4]; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad_130[0x6]; s16 f_136; u16 f_138; u8 pad_13A[0x2]; s16 f_13C; } g_Spike;

M2C_UNK Spike_WaterSplashOut();

s32 Floor_GetHeight(s32, s32, s32);
s32 func_800652E4(void);
extern struct S_D_800F5120 { u8 pad0[0x28]; s16 f_28; s16 f_2A; s16 f_2C; } g_GadgetState;
extern struct S_D_800E5320 { u8 pad_0[0xA4]; u16 f_A4[40]; u8 pad_F4[0x7C]; s32 f_170; u8 pad_174[0xE]; u16 f_182; u8 pad_184[0x18]; u16 f_19C; s16 pad19E; u16 f_1A0; } g_Pad;
void func_80066198(void);
void func_80066028(void);

extern s8 g_CurrentGadget;
M2C_UNK func_8006C58C();
extern s32 D_800EC214;



extern u32 D_800EC230;

extern s32 (*D_800B02FC)();
extern s32 D_800EC01C;
extern struct S_D_800EC010 { u8 pad_0[0x10]; s32 f_10; u8 pad_14[0x4]; u16 f_18; u8 pad_1A[0x12]; s32 f_2C; s32 f_30; u8 pad_34[0x4]; s32 f_38; s32 f_3C; } D_800EC010;
extern s32 D_800EC024;
M2C_UNK Pad_Vibrate(M2C_UNK, M2C_UNK, M2C_UNK);
void Sound_PlayFixed();
extern s8 D_800EC2CE;
extern struct S_D_800EC350 { u8 pad_0[0x8150]; u16 f_8150; } g_Game;
M2C_UNK func_8006CC28();

s32 func_80065B6C(void);
extern u16 g_RandSeed;

extern u8 D_800EC233;
extern u16 D_800EC318;
extern s16 D_800F5124;
extern s16 D_800F4DCE;
/* Sets Spike's action state (+0x5E) to `st` and starts its animation. States below 0x80 use the
 * base animation set g_SpikeAnimSets[0], others the current gadget's set (g_SpikeAnimSets[gadget +
 * 1]); the table pointer goes to scratchpad +0x48. Some changes blend over 5 frames instead of
 * cutting: to 0 while the current animation has not finished, to 0x24 from anything but 0x24, 0xE
 * or 0x8D, and between 0x46 and 0x47 (probably Water Net swimming). Copies the animation's flags
 * (bits 24..31) into +0x70. */
void Spike_SetState(s32 st);
M2C_UNK Slingback_Fire();
void func_80065C20(void);
void func_80066140(void);
extern s16 D_800EC26E;
M2C_UNK ApplyMatrixSV(M2C_UNK *, M2C_UNK *, M2C_UNK *);
extern M2C_UNK D_800AE760;
extern M2C_UNK D_800EC254;
extern M2C_UNK D_800AE740;
M2C_UNK Camera_EnterAim();
M2C_UNK Camera_ExitAim();
extern s16 g_AirTimer;
extern s16 D_800F51E4;
void func_8006896C(s32 a);
extern s16 D_800F5164;
void func_800689F0(void);
M2C_UNK func_8006C92C();
extern s16 D_800EC2E0;
extern u16 D_800EC23E;
struct S_D_800E5320_80064BBC { u8 pad0[0xA4]; u16 f_A4[0x66]; s32 f_170; };
struct S_D_800EC1E0_800653C0 { u8 pad0[0x50]; u32 f_50; u8 pad54[0xC]; s16 f_60; s16 pad62; s16 f_64; };
struct S_D_800EC1E0_80065B6C { u8 pad0[0x5C]; u16 f_5C; u16 f_5E; u8 pad60[0x2A]; u16 f_8A; };
void Spike_SetPlayMode(s32);
struct S_D_800EC1E0_80066434 { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x34]; SVECTOR f_60; u8 pad68[0xC]; SVECTOR f_74; u8 pad7C[0x9C]; s32 f_118; u8 pad11C[4]; s32 f_120; s32 f_124; s32 f_128; };
struct S_D_800E5320_80066434 { u8 pad0[0x19C]; SVECTOR f_19C; };
extern s16 g_SpikeHealth;
extern S_4D70_80067AF0_80067AF0 *D_800B4D70;
s32 Overlay_GetState(void);
void Spike_SetBlinkFrame(s32);
struct S_D_800EC350_80067AF0 { u32 f_0; u8 pad_4[0x814C]; u16 f_8150; };
extern u8 D_800E7D00[];
extern u32 *D_800EC358;
void Anim_SetFrame(void *);
void Matrix_LookAt(SVECTOR *, SVECTOR *, MAT_800689F0 *, s32);
void ScaleMatrixL(MAT_800689F0 *, VEC_800689F0 *);
void func_80015504(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_8001D4A8(u8 *, s32);
void func_8001D530(u32 *, u8 *, void *);
struct S_D_800EC1E0_800689F0 { S_Hdr_800689F0 *f_0; u8 pad4[0x10]; MAT_800689F0 *f_14; u8 pad18[0x48]; SVECTOR f_60; SVECTOR f_68; u8 pad70[0x90]; s16 f_100; };
s32 Vec_Length(s32, s32, s32);
struct Spike_80066ADC { u8 pad0[0x114]; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct Spike_80064208 { u8 pad0[0x18]; void *f_18; u8 pad1C[0x40]; u16 frame; u16 state; u8 pad60[0x10]; s32 f_70; u8 pad74[0x18]; s16 f_8C; s16 f_8E; s32 f_90; u8 pad94[0x5E]; s8 gadget; };
extern struct S_D_800F4DE0 { void *f_0; Anim_80064208_80064208 *f_4; void *f_8; void *f_C; } g_SpikeAnimSets[];
s32 func_80015240(void *, s32);
extern s16 D_800EC240;
extern s16 D_800EC244;
struct Game_80063EC4 { u8 pad0[0x8150]; u16 sub; u8 pad8152[0x144]; s16 f_8296; };
void VectorNormalSS(void *, void *);
s32 func_800433B0(s32, s32, s32, void *);
s32 func_80078C9C(s32, void *, void *);
extern s16 D_800AE7A0[];
extern s16 D_800AE780[];
void func_800649D8(void *);
void func_80066C90(SVEC_80066C90 *a, SVEC_80066C90 *b, s32 ang);
struct S_D_800EC1E0_80067CAC { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };
struct S_D_800E5320_80067CAC { u8 pad0[0xA2]; s8 sx; s8 sy; };
struct g_Spike_80065A24 { u8 pad0[0x50]; u32 f_50; u8 pad54[0x98]; s16 f_EC; u8 padEE[0x16]; s16 f_104; s16 f_106; u8 pad108[0x30]; u16 f_138; };
extern struct S_D_800AEF60 { u8 pad0[0xC]; s16 f_C; u8 padE[2]; } D_800AEF60[];
s32 func_80064B08(void);
struct S_D_800EC010_80065ED4 { u8 pad0[0x18]; s32 f_18; u8 pad1C[0x18]; s32 f_34; u8 pad38[8]; s32 f_40; s32 f_44; };
struct g_Spike_800655C4 { u8 pad0[0x5C]; u16 f_5C; u16 f_5E; };
struct g_Pad_800655C4 { u8 pad0[0xA4]; u16 f_A4[0x66]; s32 f_170; };
extern struct S_D_800F51D0 { u8 pad0[0x10]; s32 f_10; u8 pad14[4]; s16 f_18; s16 f_1A; } D_800F51D0;
extern u8 D_800E6916;
void Gadget_StopSounds(s32);
void Spike_WaterSplashIn(void);
void func_80099D20(void);
struct g_Spike_80066DAC { u8 pad0[0x94]; S16x10 f_94; s32 f_A8; s32 f_AC; s32 f_B0; u8 padB4[0x2C]; s32 f_E0; };
struct g_Spike_80066358 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; SVECTOR f_60; u8 pad68[0xC]; SVECTOR f_74; u8 pad7C[0xA4]; s32 f_120; s32 f_124; s32 f_128; };
struct g_Pad_80066358 { u8 pad0[0x19C]; SVECTOR f_19C; };
void func_8006BF84(void);
void Spike_TakeDamage(s32);
struct g_Spike_80065C20 { u8 pad0[0xF2]; s8 f_F2; u8 padF3[0x21]; s32 f_114; u8 pad118[4]; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct g_GadgetState_80065C20 { u8 pad0[4]; s16 f_4; u8 pad6[2]; s32 f_8; };
void Camera_ExitLook(void);
struct S_D_800EC010_80065C20 { u8 pad0[4]; s32 f_4; s32 f_8; u8 padC[0x1C]; s32 f_28; };
struct S_D_800EC1E0_800661D4 { u8 pad_0[0x60]; SVEC_800661D4_800661D4 f_60; u8 pad_68[0xC]; SVEC_800661D4_800661D4 f_74; u8 pad_7C[0x98]; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct S_D_800E5320_800661D4 { u8 pad_0[0x178]; u16 f_178; u8 pad_17A[0x1A]; u16 f_194; u8 pad_196[2]; u16 f_198; };
struct S_D_800EC010_800661D4 { u8 pad_0[0x10]; s32 f_10; u8 pad_14[0x10]; s32 f_24; u8 pad_28[0x8]; s32 f_30; };

INCLUDE_ASM("asm/nonmatchings/game/80060780", Spike_Update);

INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5A40);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5A40_pad);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5A78);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5A98);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5A98_pad);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5AC8);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5AC8_pad);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B10);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B10_pad);


INCLUDE_ASM("asm/nonmatchings/game/80060780", func_80063628);

INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B28);


/* Ledge grab: while Spike has health (+0xE8 > 0) and is falling (+0x34 > 0) above the floor,
 * checks one step ahead in his facing direction (snapped to 8 directions). If the floor there
 * (func_800433B0) is 0x81..0xFF above him, is not a blocked surface (scratchpad 0x1F8003F0
 * flags/kinds 0x24, 0x25, 0x53, 0x54, 10) and nothing is in the way (func_80078C9C), he is put
 * on it, stopped, and set to state 0xE (climbing up). Not in sub-modes 1, 3, 5, 6. */
void Spike_TryGrabLedge(void) {
    SV_80063EC4_80063EC4 dir;
    struct { s32 x, y, z, a, b; } p;
    u8 out[8];
    s16 *scr = (s16 *)0x1F8003F0;
    s32 h;
    s32 k;
    if ((*(Sp_80063EC4_80063EC4 *)&g_Spike).f_E8 <= 0) {
        return;
    }
    if (((*(Sp_80063EC4_80063EC4 *)&g_Spike).f_50 >> 28) == 8) {
        return;
    }
    switch ((*(struct Game_80063EC4 *)&g_Game).sub) {
    case 1:
    case 3:
    case 5:
    case 6:
        return;
    }
    dir.vy = 0;
    if (D_800EC240 > 0x800) {
        dir.vx = 1;
    } else if (D_800EC240 < -0x800) {
        dir.vx = -1;
    } else {
        dir.vx = 0;
    }
    if (D_800EC244 > 0x800) {
        dir.vz = 1;
    } else if (D_800EC244 < -0x800) {
        dir.vz = -1;
    } else {
        dir.vz = 0;
    }
    VectorNormalSS(&dir, &dir);
    if ((*(Sp_80063EC4_80063EC4 *)&g_Spike).f_34 <= 0) {
        return;
    }
    if ((*(Sp_80063EC4_80063EC4 *)&g_Spike).y >= (s16)Floor_GetHeight((*(Sp_80063EC4_80063EC4 *)&g_Spike).x, (*(Sp_80063EC4_80063EC4 *)&g_Spike).y, (*(Sp_80063EC4_80063EC4 *)&g_Spike).z)) {
        return;
    }
    if (((*(Sp_80063EC4_80063EC4 *)&g_Spike).f_70 & 0xF0) == 0xC0) {
        return;
    }
    (*(struct Game_80063EC4 *)&g_Game).f_8296 = 1;
    h = (s16)func_800433B0((*(Sp_80063EC4_80063EC4 *)&g_Spike).x + dir.vx / 32, (*(Sp_80063EC4_80063EC4 *)&g_Spike).y - 0x100, (*(Sp_80063EC4_80063EC4 *)&g_Spike).z + dir.vz / 32, &(*(Sp_80063EC4_80063EC4 *)&g_Spike).f_104);
    p.x = (*(Sp_80063EC4_80063EC4 *)&g_Spike).x + dir.vx / 32;
    p.y = (*(Sp_80063EC4_80063EC4 *)&g_Spike).y - 0x100;
    p.z = (*(Sp_80063EC4_80063EC4 *)&g_Spike).z + dir.vz / 32;
    p.a = (*(Sp_80063EC4_80063EC4 *)&g_Spike).f_44;
    p.b = (*(Sp_80063EC4_80063EC4 *)&g_Spike).f_46;
    if ((u32)((*(Sp_80063EC4_80063EC4 *)&g_Spike).y - h - 0x81) >= 0x7F) {
        return;
    }
    if ((*(Sp_80063EC4_80063EC4 *)&g_Spike).f_104 != 0) {
        return;
    }
    if (scr[0] < 0) {
        return;
    }
    if (((u16 *)scr)[4] & 0x4000) {
        return;
    }
    k = ((u16 *)scr)[2] & 0xFF;
    if (k == 0x24) {
        return;
    }
    if (k == 0x25) {
        return;
    }
    if (k == 0x53) {
        return;
    }
    if (k == 0x54) {
        return;
    }
    if ((((u16 *)scr)[3] & 0xFF) == 10) {
        return;
    }
    if (func_80078C9C(0, &p, out) >= 0) {
        return;
    }
    (*(Sp_80063EC4_80063EC4 *)&g_Spike).x += dir.vx / 32; (*(Sp_80063EC4_80063EC4 *)&g_Spike).z += dir.vz / 32; (*(Sp_80063EC4_80063EC4 *)&g_Spike).y = h; (*(Sp_80063EC4_80063EC4 *)&g_Spike).f_30 = 0; (*(Sp_80063EC4_80063EC4 *)&g_Spike).f_34 = 0; (*(Sp_80063EC4_80063EC4 *)&g_Spike).f_38 = 0;
    Spike_SetState(0xE);
    (*(Sp_80063EC4_80063EC4 *)&g_Spike).dir = dir;
}

void Spike_SetState(s32 st) {
    Scr_80064208_80064208 *scr = (Scr_80064208_80064208 *)0x1F800000;
    u32 f;
    Anim_80064208_80064208 *t;
    SP_64208->f_8E = 0x1000;
    *(s16 *)((u8 *)&(*(M2C_UNK *)&g_Spike) + 0x8A) = 0;
    if (SP_64208->state < 0x80) {
        t = g_SpikeAnimSets[0].f_4;
    } else {
        t = g_SpikeAnimSets[SP_64208->gadget + 1].f_4;
    }
    scr->tbl = t;
    if (st == 0) {
        if (SP_64208->state != 0 && SP_64208->frame != t[SP_64208->state & 0x7F].end + 1) {
            goto blend;
        }
    }
    if (st == 0x24) {
        if (SP_64208->state == 0x24 || SP_64208->state == 0xE || SP_64208->state == 0x8D) {
            goto check;
        }
        goto blend;
    }
check:
    if ((SP_64208->state == 0x46 && st == 0x47) || (SP_64208->state == 0x47 && st == 0x46)) {
    blend:
        SP_64208->f_8C = 5;
        SP_64208->f_90 = func_80015240(&(*(M2C_UNK *)&g_Spike), SP_64208->frame);
    } else if (st != 0x24 || SP_64208->state != st) {
        SP_64208->f_8C = 0;
    }
    if (st < 0x80) {
        scr->tbl = g_SpikeAnimSets[0].f_4;
    } else {
        scr->tbl = g_SpikeAnimSets[SP_64208->gadget + 1].f_4;
    }
    SP_64208->state = st;
    SP_64208->frame = scr->tbl[st % 128].start;
    if (st < 0x80) {
        SP_64208->f_18 = g_SpikeAnimSets[0].f_0;
    } else {
        SP_64208->f_18 = g_SpikeAnimSets[SP_64208->gadget + 1].f_0;
    }
    f = scr->tbl[SP_64208->state & 0x7F].flags;
    SP_64208->f_70 = ((f >> 24) & 0xF) | ((f >> 28) << 4);
}

INCLUDE_ASM("asm/nonmatchings/game/80060780", Spike_AnimEvents);

INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B50);


INCLUDE_ASM("asm/nonmatchings/game/80060780", func_800649D8);

s32 func_80064AF0(void) {
    return 0;
}

s32 func_80064AF8(void) {
    return *(s32 *)0x1F800054 & 0xA;
}

s32 func_80064B08(void) {
    s32 *sp = (s32 *)0x1F800000;

    return sp[0x16] & sp[0x15] & 0xA;
}

/* 1 if R2 (2) is among the last 10 entries of the button-press history (g_Pad+0xA4, 40 entries,
 * write index +0x170), unless input is blocked (*0x1F800080). */
s32 Pad_RecentR2(void) {
    s32 i;
    s32 idx;
    if (*(s32 *)0x1F800080 != 0) {
        return 0;
    }
    idx = (*(S_E5320_80064B24 *)&g_Pad).f_170;
    for (i = 0; i < 10; i++) {
        if ((*(S_E5320_80064B24 *)&g_Pad).f_A4[(idx + 40 - i) % 40] == 2) {
            return 1;
        }
    }
    return 0;
}

/* 1 if Cross (0x40) is among the last 10 button-press history entries (no input-block check;
 * the original falls off the end without returning 0). */
s32 Pad_RecentCross(void)
{
  s32 new_var;
  s32 i;
  new_var = ((struct S_D_800E5320_80064BBC *)&g_Pad)->f_170;
  for (i = 0; i < 10; i++)
  {
    if (((struct S_D_800E5320_80064BBC *)&g_Pad)->f_A4[((new_var + 40) - i) % 40] == 0x40)
    {
      return 1;
    }
  }

}

s32 func_80064C3C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if ((s16) *(u16 *)(scratch + 0x0070) < -0xB50) {
        var_v1 = (u16) *(u16 *)(scratch + 0x0066) >= 0x6FU;
    }
    return var_v1;
}

s32 func_80064C74(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if ((D_800F5164 != 0) || (*(u16 *)(scratch + 0x005E) & 0x30) || ((s16) *(u16 *)(scratch + 0x0070) < 0xB50)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_80064CC8(void) {
    return ((s32) ((g_Spike.f_60 * g_Spike.f_74) + (g_Spike.f_64 * g_Spike.f_78)) / 4096) >= 0xDDC;
}

s32 func_80064D18(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if (*(u16 *)(scratch + 0x0066) != 0) {
        var_a0 = (s16) *(u16 *)(scratch + 0x0072) < -0xDDB;
    }
    return var_a0;
}

s32 func_80064D4C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if (*(u16 *)(scratch + 0x0066) != 0) {
        var_a0 = (s16) *(u16 *)(scratch + 0x0072) > 0xDDB;
    }
    return var_a0;
}

s32 func_80064D7C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if (*(u16 *)(scratch + 0x0066) != 0) {
        var_a0 = (s16) *(u16 *)(scratch + 0x0070) > 0xDDB;
    }
    return var_a0;
}

s32 func_80064DAC(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if (*(u16 *)(scratch + 0x0066) != 0) {
        var_a0 = (s16) *(u16 *)(scratch + 0x0070) < -0xDDB;
    }
    return var_a0;
}

s32 func_80064DE0(void) {
    u16 temp_v0;

    temp_v0 = g_Spike.f_DE - 1;
    g_Spike.f_DE = temp_v0;
    return (temp_v0 << 0x10) == 0;
}

s32 func_80064E04(void) {
    s16 h = Floor_GetHeight(g_Spike.f_24 - ((s16)g_Spike.f_60 >> 5), g_Spike.f_28, g_Spike.f_2C - ((s16)g_Spike.f_64 >> 5));
    return h < g_Spike.f_28 + 0x100;
}

s32 func_80064E6C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if ((*(u16 *)(scratch + 0x005E) & 0x30) || ((s16) *(u16 *)(scratch + 0x007C) >= 0x321)) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_80064EAC(void) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    var_a1 = 0;
    if ((temp_v0 >> 8) & 1) {
        var_a1 = func_80065B6C() != 0;
    }
    return var_a1;
}

s32 func_80064EF8(void)
{
  int new_var;
  u8 *scratch = (u8 *) 0x1F800000;
  s32 var_a0;
  var_a0 = 0;
  if ((*((u16 *) (scratch + 0x005C))) == 0)
  {
    new_var = ((*((s32 *) (scratch + 0x0054))) & 0x20A) == 0;
    var_a0 = new_var;
  }
  return var_a0;
}

s32 func_80064F28(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if ((s16) *(u16 *)(scratch + 0x0074) >= 0xB51) {
        var_v1 = *(u16 *)(scratch + 0x005C) != 0;
    }
    return var_v1;
}

s32 func_80064F5C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if ((s16) *(u16 *)(scratch + 0x0074) < -0xB50) {
        var_v1 = *(u16 *)(scratch + 0x005C) != 0;
    }
    return var_v1;
}

/* 1 if L1 (4) is among the last 10 entries of the button-press history (g_Pad+0xA4, 40 entries,
 * write index +0x170), unless input is blocked (*0x1F800080). */
s32 Pad_RecentL1(void) {
    s32 i;
    if (*(s32 *)0x1F800080 != 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + 40 - i) % 40] == 4) {
            return 1;
        }
    }
    return 0;
}

/* 1 if R1 (8) is among the last 10 entries of the button-press history (g_Pad+0xA4, 40 entries,
 * write index +0x170), unless input is blocked (*0x1F800080). */
s32 Pad_RecentR1(void) {
    s32 i;
    if (*(s32 *)0x1F800080 != 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + 40 - i) % 40] == 8) {
            return 1;
        }
    }
    return 0;
}

s32 func_800650A8(void)
{
  u8 *scratch = (u8 *) 0x1F800000;
  s32 var_a0;
  var_a0 = 0;
  if ((*((u16 *) (scratch + 0x005E))) == 0)
  {
    var_a0 = 0U;
    var_a0 = ((u32) ((*((s32 *) (scratch + 0x0054))) & 0x400)) > var_a0;
  }
  return var_a0;
}

s32 func_800650D8(void) {
    return *(u16 *)0x1F80005E & 0x30;
}

s32 func_800650E8(void)
{
  u8 *scratch = (u8 *) 0x1F800000;
  int var_v0;
  s32 var_v1;
  var_v1 = 0;
  if ((*((u16 *) (scratch + 0x005E))) & 0x30)
  {
    var_v0 = (s16) (*((u16 *) (scratch + 0x0078)));
    if (var_v0 < 0)
    {
      var_v0 = -var_v0;
    }
    var_v1 = var_v0 >= 0x15;
  }
  return var_v1;
}

s32 func_8006512C(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if (((s16) *(u16 *)(scratch + 0x0070) >= 0xB51) && (*(u16 *)(scratch + 0x005E) & 0xC)) {
        var_v1 = g_CurrentGadget == 1;
    }
    return var_v1;
}

s32 func_80065178(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v1;

    var_v1 = 0;
    if (((s16) *(u16 *)(scratch + 0x0070) < -0xB50) && ((u16) *(u16 *)(scratch + 0x0066) >= 0x6FU)) {
        var_v1 = g_CurrentGadget == 3;
    }
    return var_v1;
}

s32 func_800651C4(void) {
    return *(u16 *)0x1F80005E & 0x10;
}

s32 func_800651D4(void) {
    return *(u16 *)0x1F80005E & 0x20;
}

s32 func_800651E4(void) {
    return *(u16 *)0x1F80005E == 0;
}

s32 func_800651F4(void) {
    return *(u16 *)0x1F800062 & 4;
}

s32 func_80065204(void) {
    return *(u16 *)0x1F800062 & 8;
}

s32 func_80065214(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_a0;

    var_a0 = 0;
    if (*(u16 *)(scratch + 0x005C) == 0) {
        var_a0 = var_a0 < (*(u32 *)(scratch + 0x0054) & 0x200);
    }
    return var_a0;
}

s32 func_80065244(void) {
    return *(u16 *)0x1F80005C == 0;
}

s32 func_80065254(void) {
    return *(u16 *)0x1F80005C & 2;
}

s32 func_80065264(void) {
    return *(u16 *)0x1F80005C & 4;
}

s32 func_80065274(void) {
    return *(u16 *)0x1F80005C & 8;
}

s32 func_80065284(void) {
    return (u16) *(u16 *)0x1F800064 >= 0x7DU;
}

s32 func_8006529C(void) {
    return (u16) *(u16 *)0x1F800066 >= 0x7DU;
}

s32 func_800652B4(void) {
    return (u32) (*(u16 *)0x1F800064 - 1) < 0x7BU;
}

s32 func_800652CC(void) {
    return (u32) (*(u16 *)0x1F800066 - 1) < 0x7BU;
}

s32 func_800652E4(void)
{
  s32 var_a0;
  s8 *new_var;
  new_var = (s8 *) (&g_Spike);
 do { var_a0 = 0; } while (0);
  if ((*((s32 *) (new_var + 0x12C))) <= (*((s32 *) (new_var + 0x28))))
  {
    var_a0 = 0U;
    var_a0 = ((u32) (*((s16 *) (new_var + 0x136)))) > var_a0;
  }
  return var_a0;
}

s32 func_80065318(void) {
    s32 r = 0;
    if (g_Spike.f_136 != 0) {
        s16 h = Floor_GetHeight(g_Spike.f_24, g_Spike.f_28 + g_Spike.f_124 / 4096, g_Spike.f_2C);
        if (h < g_Spike.f_28 + g_Spike.f_124 / 4096 * 3) {
            r = 1;
        }
    }
    return r;
}

s32 func_800653C0(void)
{
  int new_var;
  s32 r = 0;
  u32 fl = ((struct S_D_800EC1E0_800653C0 *)&g_Spike)->f_50;
  u8 *scratch = (u8 *) 0x1F800000;
  if ((((fl >> 28) == 0xA) && ((fl & 0xF000) != 0x3000)) && ((fl & 0xF000) != 0x9000))
  {
    new_var = (((*((s16 *) (scratch + 0))) * ((struct S_D_800EC1E0_800653C0 *)&g_Spike)->f_60) + (((s16) (*((u16 *) (scratch + 4)))) * ((struct S_D_800EC1E0_800653C0 *)&g_Spike)->f_64)) < (-0xDDB000);
    r = new_var;
  }
  return r;
}

s32 func_8006543C(void) {
    return (D_800EC233 & 0xF) == 8;
}

s32 func_80065458(void) {
    return (D_800EC233 & 0xF) != 8;
}

s32 func_80065474(void) {
    s32 var_a1;

    var_a1 = 0;
    if ((g_Spike.f_28 + 0x40) < g_Spike.f_12C) {
        var_a1 = g_Spike.f_34 >= 0x11;
    }
    return var_a1;
}

/* 1 if Triangle (0x10) is among the last 10 entries of the button-press history (g_Pad+0xA4, 40 entries,
 * write index +0x170), unless input is blocked (*0x1F800080). */
s32 Pad_RecentTriangle(void) {
    s32 i;
    if (*(s32 *)0x1F800080 != 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + 40 - i) % 40] == 0x10) {
            return 1;
        }
    }
    return 0;
}

/* 1 if Circle (0x20) is among the last 10 entries of the button-press history (g_Pad+0xA4, 40 entries,
 * write index +0x170), unless input is blocked (*0x1F800080). */
s32 Pad_RecentCircle(void) {
    s32 i;
    if (*(s32 *)0x1F800080 != 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + 40 - i) % 40] == 0x20) {
            return 1;
        }
    }
    return 0;
}

/* 1 when Spike's animation frame (+0x5C) is one past the last frame of his current animation
 * (+0x5E & 0x7F in the table at *0x1F800048) and the latest entry of the button-press history
 * (g_Pad+0xA4, index +0x170) is Triangle (0x10). */
s32 Spike_AnimEndOnTriangle(void) {
    if (G_SPIKE_800655C4->f_5C == (*(S_1F800048_800655C4 **)0x1F800048)[G_SPIKE_800655C4->f_5E & 0x7F].f_0 + 1 && G_PAD_800655C4->f_A4[G_PAD_800655C4->f_170] == 0x10) {
        return 1;
    }
    return 0;
}

/* 1 when Spike's animation frame (+0x5C) is one past the last frame of his current animation
 * (+0x5E & 0x7F in the table at *0x1F800048) and the latest entry of the button-press history
 * (g_Pad+0xA4, index +0x170) is Circle (0x20). */
s32 Spike_AnimEndOnCircle(void) {
    if (G_SPIKE_800655C4->f_5C == (*(S_1F800048_800655C4 **)0x1F800048)[G_SPIKE_800655C4->f_5E & 0x7F].f_0 + 1 && G_PAD_800655C4->f_A4[G_PAD_800655C4->f_170] == 0x20) {
        return 1;
    }
    return 0;
}

s32 func_80065694(void) {
    switch (g_CurrentGadget) {
    case 2:
    case 5:
    case 7:
        return 1;
    }
    return 0;
}

s32 func_800656DC(void) {
    u8 *scratch = (u8 *)0x1F800000;
    s32 var_v0;

    if (*(s32 *)(scratch + 0x0054) & *(s32 *)(scratch + 0x0058) & 0xA) {
        var_v0 = D_800EC214;
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 < 0x26) {
            func_8006C58C();
            return 1;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

s32 func_80065748(void) {
    return *(s16 *)0x1F800076 >= 0xB51;
}

s32 func_80065760(void) {
    return *(s16 *)0x1F800076 < -0xB50;
}

s32 func_80065770(void) {
    return (u32) ((*(u16 *)0x1F800076 + 0xB50) & 0xFFFF) >= 0x16A1U;
}

s32 func_80065790(void)
{
  s32 var_v1;
  int new_var;
  var_v1 = 0;
  if ((*((u16 *) 0x1F80005C)) == 0)
  {
    new_var = (g_Spike.f_30 * g_Spike.f_30) + (g_Spike.f_38 * g_Spike.f_38);
    var_v1 = new_var >= 0x401;
  }
  return var_v1;
}

s32 func_800657E0(void) {
    return *(u16 *)0x1F800062 & 0xC;
}

/* Puts the gadget away when Spike is not in state group 0xC0/0xE0 and his gadget state +0x138 is
 * 0x1000 exactly: stops its sounds, clears the aim values, copies +0x60 to +0x80, leaves the aim
 * camera if it is on (D_800E6916 == 1) and, for gadget slot +0xF2 == 2, calls func_80099D20.
 * Returns 1 when it did. */
s32 Gadget_Cancel(void) {
    Sp_657F0_800657F0 *p = &(*(Sp_657F0_800657F0 *)&g_Spike);
    s32 hi;
    u16 st;

    if ((p->f_70 & 0xF0) == 0xC0 || (p->f_70 & 0xF0) == 0xE0) {
        return 0;
    }
    st = p->f_138;
    hi = st >> 12;
    if (hi == 1 && (st & 0xF) == 0) {
    Gadget_StopSounds(*(s8 *)((u8 *)p + 0xF2));
    D_800F51D0.f_10 = 0;
    p->f_7C = 0;
    p->f_80 = p->f_60;
    Spike_WaterSplashIn();
    D_800F51D0.f_18 = -1;
    D_800F51D0.f_1A = -1;
    if (D_800E6916 == hi) {
        Camera_ExitAim();
    }
    if (*(s8 *)((u8 *)p + 0xF2) == 2) {
        func_80099D20();
    }
    return 1;
    }
    return 0;
}

s32 func_800658E8(void) {
    return ((u16) D_800EC318 >> 0xC) == 1;
}

s32 func_80065904(void) {
    s32 r = 0;
    u16 v = g_Spike.f_138;
    if ((v >> 12) == 1 && (v & 0xF) != 0 && ABS(g_Spike.f_104) + ABS(g_Spike.f_106) < 0x200) {
        r = func_800652E4() != 0;
    }
    return r;
}

s32 func_80065980(void)
{
  s32 var_a0;
  var_a0 = 0;
  if ((((u32) D_800EC230) >> 0x1C) == 0xA)
  {
    var_a0 = 0x3B;
    var_a0 = (D_800EC230 & 0xFF) == var_a0;
  }
  return var_a0;
}

s32 func_800659AC(void)
{
  u8 *scratch = (u8 *) 0x1F800000;
  s32 temp_v1;
  ;
  if (((*((s32 *) (scratch + 0x0058))) & (*((s32 *) (scratch + 0x0054)))) & 0xA)
  {
    if ((!((*((s32 *) (scratch + 0x0054))) & 0x200)) && ((g_Spike.f_28 - g_Spike.f_13C) < 0xC8))
    {
      Spike_WaterSplashOut();
      return 1;
    }
    return 0;
  }
  return 0;
}

s32 func_80065A24(void) {
    s32 r;
    s32 lim;
    if (func_80064B08() == 0) {
        return 0;
    }
    if ((G_SPIKE_80065A24->f_138 >> 12) == 1 && (G_SPIKE_80065A24->f_50 >> 28) == 0xA) {
        return 1;
    }
    if (G_SPIKE_80065A24->f_EC < 0) {
        goto miss;
    }
    lim = D_800AEF60[G_SPIKE_80065A24->f_EC].f_C;
    r = 0;
    if (!(lim < ABS(G_SPIKE_80065A24->f_106))) {
        r = !(lim < ABS(G_SPIKE_80065A24->f_104));
    }
    return r;
miss:
    return 0;
}

s32 func_80065AE8(void)
{
  u8 *scratch = (u8 *) 0x1F800000;
  s32 var_a0;
  var_a0 = 0;
  if ((*((u16 *) (scratch + 0x005C))) == 0)
  {
    var_a0 = 0U;
    var_a0 = ((u32) (((*((s32 *) (scratch + 0x0054))) & (*((s32 *) (scratch + 0x0058)))) & 0x200)) > var_a0;
  }
  return var_a0;
}

s32 func_80065B20(void)
{
  int new_var;
  s32 var_v1;
  var_v1 = 0;
  if (g_Spike.f_E8 <= 0)
  {
    new_var = (g_Spike.f_70 & 0xF0) ^ 0xE0;
    var_v1 = ((u32) new_var) > 0U;
  }
  return var_v1;
}

s32 func_80065B54(void) {
    return D_800F5124 == 1;
}

s32 func_80065B6C(void)
{
  int new_var;
  new_var = ((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_8A != 0;
  return (*((S_1F800048_80065B6C **) 0x1F800048))[((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_5E & 0x7F].f_2 < (((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_5C + new_var);
}

s32 func_80065BA8(void) {
    return 0;
}

s32 func_80065BB0(void)
{
  s32 var_a0;
  M2C_UNK *new_var;
  new_var = &g_Spike;
  var_a0 = 0;
  if (((((u32) ((*((s32 *) (((s8 *) new_var) + 0x30))) + 4)) < 9U) && (((u32) ((*((s32 *) (((s8 *) (&g_Spike)) + 0x38))) + 4)) < 9U)) && (((u32) (((*((u16 *) (((s8 *) (&g_Spike)) + 0x106))) + 0xFF) & 0xFFFF)) < 0x1FFU))
  {
    var_a0 = 0x1FFU;
    var_a0 = ((u32) (((*((u16 *) (((s8 *) (&g_Spike)) + 0x104))) + 0xFF) & 0xFFFF)) < var_a0;
  }
  return var_a0;
}

void func_80065C20(void)
{
  s32 x;
  s32 height;
  s32 z;
  if (G_SPIKE_80065C20->f_F2 == 4)
  {
    if (G_GADGETSTATE_80065C20->f_4 == 1)
    {
      G_SPIKE_80065C20->f_114 >>= 1;
      G_SPIKE_80065C20->f_11C = G_SPIKE_80065C20->f_11C >> 1;
    }
    G_GADGETSTATE_80065C20->f_4 = 0;
    G_GADGETSTATE_80065C20->f_8 = 0;
  }
  Camera_ExitLook();
  x = (G_SPIKE_80065C20->f_114 * ((struct S_D_800EC010_80065C20 *)(void *)&D_800EC010)->f_28) / 100;
  height = ((struct S_D_800EC010_80065C20 *)(void *)&D_800EC010)->f_8;
  z = (G_SPIKE_80065C20->f_11C * ((struct S_D_800EC010_80065C20 *)(void *)&D_800EC010)->f_28) / 100;
  G_SPIKE_80065C20->f_124 = (((struct S_D_800EC010_80065C20 *)(void *)&D_800EC010)->f_4 + height) << 7;
  G_SPIKE_80065C20->f_114 = x;
  G_SPIKE_80065C20->f_120 = x;
  G_SPIKE_80065C20->f_11C = z;
  G_SPIKE_80065C20->f_128 = z;
}

void func_80065D1C(void) {
    if (D_800B02FC() != 0) {
        g_Spike.f_124 = (s32) (g_Spike.f_124 + (D_800EC01C << 7));
    }
}

void func_80065D68(void) {
    g_Spike.f_124 = (s32) (D_800EC010.f_10 << 7);
    g_Spike.f_114 = (s32) ((g_Spike.f_114 * D_800EC010.f_30) / 100);
    g_Spike.f_11C = (s32) ((g_Spike.f_11C * D_800EC010.f_30) / 100);
}

void func_80065DEC(void) {
    g_Spike.f_120 = 0;
    g_Spike.f_114 = 0;
    g_Spike.f_128 = 0;
    g_Spike.f_11C = 0;
    g_Spike.f_124 = (s32) (D_800EC024 << 7);
}

void func_80065E18(void) {
    g_Spike.f_124 = (s32) (D_800EC010.f_10 << 7);
    g_Spike.f_114 = (s32) ((g_Spike.f_114 * D_800EC010.f_2C) / 100);
    g_Spike.f_11C = (s32) ((g_Spike.f_11C * D_800EC010.f_2C) / 100);
}

void func_80065E9C(void) {
    g_Spike.f_100 = 0;
    g_Spike.f_124 = 0;
    Pad_Vibrate(1, 0xFF, 0x14);
}

void func_80065ED4(void) {
    Sp_65ED4_80065ED4 *s = &(*(Sp_65ED4_80065ED4 *)&g_Spike);
    s32 lim;
    s16 n;

    n = s->f_100;
    s->f_100 = n + 1;
    if (n < ((struct S_D_800EC010_80065ED4 *)&D_800EC010)->f_18) {
        s->f_124 += ((struct S_D_800EC010_80065ED4 *)&D_800EC010)->f_34 << 7;
        Pad_Vibrate(1, 0x8C, 5);
    } else {
        lim = 0;
        s->f_124 += ((struct S_D_800EC010_80065ED4 *)&D_800EC010)->f_40 << 7;
        if ((u16)((*(Pad_65ED4_80065ED4 *)&g_Pad).f_1B4 + 7) >= 0xF || (*(Pad_65ED4_80065ED4 *)&g_Pad).f_1BC > 800) {
            lim = ((struct S_D_800EC010_80065ED4 *)&D_800EC010)->f_44 << 5;
        }
        if (lim < (*(Sp_65ED4_80065ED4 *)&g_Spike).f_124) {
            (*(Sp_65ED4_80065ED4 *)&g_Spike).f_124 = lim;
        }
        Pad_Vibrate(1, 0x50, 5);
    }
}

void func_80065FC8(void) {
    g_Spike.f_100 = (u16) D_800EC010.f_18;
    g_Spike.f_124 = (s32) (D_800EC010.f_38 << 5);
}

void func_80065FF0(void) {
    g_Spike.f_100 = (u16) D_800EC010.f_18;
    g_Spike.f_124 = (s32) (D_800EC010.f_3C << 5);
}

void func_80066018(void) {
    D_800F4DCE = 0xF;
}

void func_80066028(void) {
    u16 v;
    if (func_800650D8() != 0 && g_GadgetState.f_28 < 0x2000) {
        v = *(u16 *)0x1F800078;
        g_GadgetState.f_2C = -0x40;
        g_GadgetState.f_2A += ABS((s16)v);
    }
}

void func_80066094(void) {
    if (((u16) D_800EC318 >> 0xC) == 1) {
        Spike_SetState(0x49);
    }
}

void func_800660C8(void) {
    Slingback_Fire();
}

void func_800660E8(void) {
    g_Spike.f_108 = (s32) (g_Spike.f_108 + (g_Spike.f_60 << 5));
    g_Spike.f_110 = (s32) (g_Spike.f_110 + (g_Spike.f_64 << 5));
}

void func_8006611C(void) {
    s16 *sp = (s16 *)0x1F800000;

    sp[5] = 0;
    sp[4] = -sp[0];
    sp[6] = -sp[2];
}

void func_80066140(void) {
    g_Spike.f_8C = 0;
    g_Spike.f_60 = -g_Spike.f_60;
    g_Spike.f_64 = -g_Spike.f_64;
}

void func_80066168(void) {
    func_80066140();
    func_80065C20();
}

void func_80066190(void) {
}

void func_80066198(void) {
    if (g_Pad.f_182 > 0x40) {
        g_Spike.f_76 = 0;
        g_Spike.f_74 = g_Pad.f_19C;
        g_Spike.f_78 = g_Pad.f_1A0;
    }
}

/* Analog stick movement: while the stick is in use (g_Pad+0x178) Spike's move direction (+0x74)
 * comes from the stick (+0x194, +0x198) and his speed (+0x114, +0x11C) from it scaled by the
 * scratchpad factor +0x64 and the move parameters D_800EC010 (+0x24, +0x30); otherwise the
 * direction is his facing (+0x60). Then copies the speeds into +0x120..+0x128 (+0x124 = f_10 << 7). */
void Spike_ApplyAnalogMove(void) {
    s32 t;
    s32 k;
    SCR_800661D4_800661D4 *sc = (SCR_800661D4_800661D4 *)0x1F800000;

    if (((struct S_D_800E5320_800661D4 *)&g_Pad)->f_178 != 0) {
        s32 x;
        s32 z;
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74.vx = ((struct S_D_800E5320_800661D4 *)&g_Pad)->f_194;
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74.vz = ((struct S_D_800E5320_800661D4 *)&g_Pad)->f_198;
        t = ((((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74.vx * sc->f_64) >> 7) * ((struct S_D_800EC010_800661D4 *)&D_800EC010)->f_24;
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74.vy = 0;
        x = t;
        z = (k = ((((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74.vz * sc->f_64) >> 7) * ((struct S_D_800EC010_800661D4 *)&D_800EC010)->f_24);
        k = ((struct S_D_800EC010_800661D4 *)&D_800EC010)->f_30;
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_114 = (x * k) >> 12;
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_11C = (z * k) >> 12;
    } else {
        ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_74 = ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_60;
    }
    ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_124 = ((struct S_D_800EC010_800661D4 *)&D_800EC010)->f_10 << 7;
    ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_120 = ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_114;
    ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_128 = ((struct S_D_800EC1E0_800661D4 *)&g_Spike)->f_11C;
}

void func_800662DC(void) {
    g_Spike.f_24 -= g_Spike.f_60 / 32;
    g_Spike.f_2C -= g_Spike.f_64 / 32;
    g_Spike.f_120 = 0;
    g_Spike.f_128 = 0;
    g_Spike.f_124 = 0;
    g_Spike.f_28 += 0x100;
    func_80066198();
}

/* Knock Spike back off what he ran into: step back by 1/32 of his velocity (+0x60), launch him
   backwards (-16x velocity) and upward (-0x1E000), copy the pad direction (g_Pad+0x19C) into
   +0x74/+0x60, and return to the normal play mode. */
void Spike_BounceBack(void) {
    s32 z;
    s32 x = G_SPIKE_80066358->f_60.vx;
    s32 dz;
    G_SPIKE_80066358->f_24 -= x / 32;
    z = G_SPIKE_80066358->f_60.vz;
    dz = z / 32;
    G_SPIKE_80066358->f_120 = -x << 4;
    G_SPIKE_80066358->f_124 = -0x1E000;
    G_SPIKE_80066358->f_128 = -z << 4;
    G_SPIKE_80066358->f_2C -= dz;
    G_SPIKE_80066358->f_74 = G_PAD_80066358->f_19C;
    G_SPIKE_80066358->f_60 = G_SPIKE_80066358->f_74;
    Spike_SetPlayMode(0);
}

void func_80066434(void)
{
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_124 = 0;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_118 = 0;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_28 += 0x10;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_120 = ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_60.vx << 4;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_128 = ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_60.vz << 4;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_74 = ((struct S_D_800E5320_80066434 *)&g_Pad)->f_19C;
  ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_60 = ((struct S_D_800EC1E0_80066434 *)&g_Spike)->f_74;
  Spike_SetPlayMode(0);
}

void func_800664D0(void) {
    D_800EC26E = 0x1000;
}

void func_800664E0(void) {
    D_800EC26E = 0x800;
}

void func_800664F0(void) {
    func_80066198();
    if (*(u16 *)0x1F800062 & 4) {
        D_800EC26E = 0x800;
    }
}

void func_80066530(void) {
    func_80066198();
    ApplyMatrixSV(&D_800AE760, &D_800EC254, &D_800EC254);
}

void func_80066568(void) {
    func_80066198();
    ApplyMatrixSV(&D_800AE740, &D_800EC254, &D_800EC254);
}

void func_800665A0(void) {
    Camera_EnterAim();
}

void func_800665C0(void) {
    Camera_ExitAim();
}

void Spike_ResetAir(void) {
    g_AirTimer = 0x258;
    D_800F51E4 = 0;
}

void func_800665F8(void) {
    g_Spike.f_76 = 0;
    g_Spike.f_74 = -g_Pad.f_1A0;
    g_Spike.f_78 = g_Pad.f_19C;
    func_80066028();
}

void func_8006663C(void) {
    g_Spike.f_76 = 0;
    g_Spike.f_74 = g_Pad.f_1A0;
    g_Spike.f_78 = -g_Pad.f_19C;
    func_80066028();
}

void func_80066680(void)
{
  long new_var;
  int new_var3;
  s16 new_var2;
  s16 temp_a0;
  temp_a0 = g_Spike.f_60;
  new_var2 = temp_a0;
  new_var3 = -g_Spike.f_64;
  new_var = new_var2;
  g_Spike.f_62 = 0;
  g_Spike.f_60 = (s16) new_var3;
  g_Spike.f_64 = new_var;
}

void func_800666A4(void)
{
  s16 new_var2;
  unsigned long new_var;
  s16 temp_v1;
  unsigned int new_var3;
  new_var = (s16) g_Spike.f_64;
  g_Spike.f_62 = 0;
  new_var3 = g_Spike.f_60;
  temp_v1 = -new_var3;
  g_Spike.f_60 = new_var;
  new_var2 = temp_v1;
  g_Spike.f_64 = new_var2;
}

void func_800666C8(void)
{
  u8 *new_var;
  u16 temp_v1;
  new_var = ((u8 *) (&g_Pad)) + (g_Pad.f_170 * 2);
  temp_v1 = *((u16 *) (((s8 *) ((void *) new_var)) + 0xA4));
  if ((temp_v1 == 0x10) || (temp_v1 == 0x20))
  {
    g_Spike.f_76 = 0;
    g_Spike.f_74 = (u16) g_Pad.f_19C;
    g_Spike.f_78 = (u16) g_Pad.f_1A0;
  }
}

void func_8006671C(void) {
    g_Spike.f_124 = (s32) ((s32) -g_Spike.f_118 / 2);
}

void func_80066744(void) {
    D_800F5164 = 5;
    func_8006896C(2);
}

/* Probably Spike's landing handler (only reached through a pointer). With a fall counter +0xFC
   of 6 or more he takes 1 damage, the pad rumbles, he goes to state 0x18 (from state 0x45) or 0x4B
   with +0xFE = 60, and sound 0x43 plays; otherwise a light rumble and sound 0x42 (state 0x45) or
   0x13/0x12 depending on the vertical speed +0x34. Always sets flag 0x4000000 in +0xE0. */
void Spike_Land(void) {
    S_EC1E0_80066770_80066770 *s = (S_EC1E0_80066770_80066770 *)&(*(M2C_UNK *)&g_Spike);
    if (s->f_5E == 0x45) {
        func_8006BF84();
        if (s->f_FC >= 6) {
            Spike_TakeDamage(1);
            Pad_Vibrate(1, 0xF0, 8);
            Spike_SetState(0x18);
            func_8006896C(9);
            Sound_PlayFixed(0x43);
        } else {
            Pad_Vibrate(0, 1, 2);
            Sound_PlayFixed(0x42);
        }
    } else if (s->f_FC >= 6) {
        Spike_TakeDamage(1);
        Pad_Vibrate(1, 0xF0, 8);
        s->f_FE = 0x3C;
        func_8006BF84();
        Spike_SetState(0x4B);
        func_8006896C(9);
        Sound_PlayFixed(0x43);
    } else if (s->f_34 > 0x20) {
        Pad_Vibrate(0, 1, 1);
        Sound_PlayFixed(0x13);
    } else {
        Sound_PlayFixed(0x12);
    }
    ((S_EC1E0_80066770_80066770 *)&g_Spike)->f_E0 |= 0x4000000;
}

void func_800668A0(void *arg0) {
    s32 temp_lo;
    s32 temp_s1;
    s32 var_v0;
    s32 var_v1;

    if (g_Spike.f_E8 > 0) {
        temp_lo = g_Spike.f_60 * M2C_FIELD(arg0, s16 *, 0);
        temp_s1 = temp_lo + (g_Spike.f_64 * M2C_FIELD(arg0, s16 *, 4));
        if (g_Spike.f_124 < 0) {
            g_Spike.f_124 = 0;
        }
        Sound_PlayFixed(0x2B, temp_lo);
        if (temp_s1 > 0) {
            Spike_SetState(0x2F);
            var_v0 = g_Spike.f_120;
            if (var_v0 < 0) {
                var_v0 += 3;
            }
            var_v1 = g_Spike.f_128;
            g_Spike.f_120 = (s32) (var_v0 >> 2);
            if (var_v1 < 0) {
                var_v1 += 3;
            }
            g_Spike.f_128 = (s32) (var_v1 >> 2);
        } else {
            Spike_SetState(0x42);
            g_Spike.f_120 = (s32) ((s32) (g_Spike.f_120 + ((u32) g_Spike.f_120 >> 0x1F)) >> 1);
            g_Spike.f_128 = (s32) ((s32) g_Spike.f_128 / 2);
        }
        D_800EC2CE = 0;
    }
}

s32 func_8006699C(s32 n) {
    S_EC1E0_8006699C_8006699C *s = (S_EC1E0_8006699C_8006699C *)&(*(M2C_UNK *)&g_Spike);
    s32 dx = (s->f_120 - s->f_114) / 64;
    s32 dz = (s->f_128 - s->f_11C) / 64;
    s32 len = Vec_Length(dx, 0, dz) << 6;
    s32 d;
    s32 t;
    if (n < len) {
        t = dx * n;
        d = len / 64;
        s->f_120 = s->f_114 + t / d;
        s->f_128 = s->f_11C + dz * n / d;
        return len;
    }
    return 0;
}

/* If Spike's move this frame (new position +0x120 minus old +0x114, in 1/64 units) is longer
 * than `max`, scales it down to `max` and returns the original length; else returns 0. */
s32 Spike_ClampMoveStep(s32 max)
{
  s32 dx = (((struct Spike_80066ADC *) (&g_Spike))->f_120 - ((struct Spike_80066ADC *) (&g_Spike))->f_114) / 64;
  M2C_UNK *spike;
  s32 dy = (((struct Spike_80066ADC *) (&g_Spike))->f_124 - ((struct Spike_80066ADC *) (&g_Spike))->f_118) / 64;
  s32 dz = (((struct Spike_80066ADC *) (&g_Spike))->f_128 - ((struct Spike_80066ADC *) (&g_Spike))->f_11C) / 64;
  s32 len = Vec_Length(dx, dy, dz) << 6;
  if (max < len)
  {
    ((struct Spike_80066ADC *) (&g_Spike))->f_120 = ((struct Spike_80066ADC *) (&g_Spike))->f_114 + ((dx * max) / (len / 64));
    ((struct Spike_80066ADC *) (&g_Spike))->f_124 = ((struct Spike_80066ADC *) (&g_Spike))->f_118 + ((dy * max) / (len / 64));
    spike = &(*(M2C_UNK *)&g_Spike);
    ((struct Spike_80066ADC *) spike)->f_128 = ((struct Spike_80066ADC *) spike)->f_11C + ((dz * max) / (len / 64));
    return len;
  }
  return 0;
}

void func_80066C90(SVEC_80066C90 *a, SVEC_80066C90 *b, s32 ang)
{
  s32 r;
  if ((((a->vx * b->vx) + (a->vz * b->vz)) >> 12) < rcos(ang))
  {
    func_8004637C((MATRIX_80066C90 *) 0x1F800028);
    if ((((a->vx * b->vz) - (a->vz * b->vx)) / 4096) > 0)
    {
      r = ang;
    }
    else
      if (a)
    {
      r = -ang;
    }
    else
    {
      r = -ang;
    }
    RotMatrixY(r, (MATRIX_80066C90 *) 0x1F800028);
    ApplyMatrixSV((MATRIX_80066C90 *) 0x1F800028, b, b);
  }
  else
  {
    *b = *a;
  }
}

void func_80066DAC(S16x10 *a, s32 b, s32 c, s32 d) {
    S16x10 *dst = &G_SPIKE_80066DAC->f_94;
    *dst = *a;
    G_SPIKE_80066DAC->f_A8 = b;
    G_SPIKE_80066DAC->f_AC = c;
    G_SPIKE_80066DAC->f_B0 = d;
    G_SPIKE_80066DAC->f_E0 |= 1;
}

void func_80066E28(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    g_Spike.f_B4 = arg0;
    g_Spike.f_B6 = arg1;
    g_Spike.f_B8 = arg2;
    g_Spike.f_BC = arg3;
    g_Spike.f_BE = (s16) (arg4 - 0x100);
    g_Spike.f_BA = (s16) arg5;
    if (g_Game.f_8150 != 5) {
        g_Spike.f_E0 = (s32) (g_Spike.f_E0 | 2);
    }
}

void func_80066E8C(s16 *a, s16 *b) {
    g_Spike.f_C0 = a[0];
    g_Spike.f_C2 = a[1] + 0x100;
    g_Spike.f_C4 = a[2];
    g_Spike.f_C6 = b[0];
    g_Spike.f_C8 = b[1] + 0x100;
    g_Spike.f_CA = b[2];
    g_Spike.f_E0 |= 4;
}

typedef struct { u8 pad0[0xD8]; s32 f_D8; u16 f_DC; s16 f_DE; u32 f_E0; } Sp_StartKnockback;
#define SP_KB ((Sp_StartKnockback *)&g_Spike)
void func_8006CE9C(void);
/* Spike_StartKnockback: store the 6-byte knockback vector p and duration a, set the knockback flag
 * (f_E0 bit 3) and spawn the hit effect 0x116 (func_8006CE9C). */
void Spike_StartKnockback(s32 *p, s16 a) {
    s32 *d = &SP_KB->f_D8;
    s32 x = p[0];
    u16 y = *(u16 *)&p[1];
    d[0] = x;
    SP_KB->f_DE = a;
    *(u16 *)&(&SP_KB->f_D8)[1] = y;
    SP_KB->f_E0 |= 8;
    func_8006CE9C();
}

void func_80066F34(void) {
    g_Spike.f_E0 = (s32) (g_Spike.f_E0 | 0x40);
}

s32 func_80066F50(void) {
    switch (g_Game.f_8150) {
    case 1:
    case 2:
    case 3:
    case 9:
    case 11:
        return 0;
    }
    return Spike_IsUnderwater() == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80060780", Spike_HandleHit);

/* Gadget selection: maps newly pressed face buttons (Triangle, Square, Circle,
 * Cross) to the four gadget slots and switches to that slot's gadget.
 */
typedef struct { u8 pad0[0x88]; s8 slots[4]; } GadgetSlots_800679A0;
s32 Gadget_Select(s32 g, s32 prev);

/* The first exit is a bare `return;` in the original, leaving v0 as func_80066F50's 0. */
s32 Gadget_SelectFromButtons(void) {
    u8 *spad = (u8 *)0x1F800000;
    s32 b;
    s32 slot;
    s32 cur;
    if (func_80066F50() == 0) {
        return;
    }
    b = *(s32 *)(spad + 0x58) & *(s32 *)(spad + 0x54);
    cur = g_CurrentGadget;
    slot = -1;
    if (b & 0x10) slot = 0; /* Triangle */
    if (b & 0x80) slot = 1; /* Square */
    if (b & 0x20) slot = 2; /* Circle */
    if (b & 0x40) slot = 3; /* Cross */
    if (slot < 0) return 0;
    if (((GadgetSlots_800679A0 *)&g_GadgetState)->slots[slot] < 0) return 0;
    return Gadget_Select(((GadgetSlots_800679A0 *)&g_GadgetState)->slots[slot], cur);
}

/* Switches Spike's action state between its plain and gadget-holding variants
 * (0<->1, 3<->4, 5<->7, 0x13<->0x14) depending on the gadget in hand.
 */
void Spike_SwapGadgetState(void) {
    s32 n;
    if (func_80065694() != 0) {
        switch (D_800EC23E) {
        case 3:
            n = 4;
            break;
        case 5:
            n = 7;
            break;
        case 0:
            n = 1;
            break;
        case 0x13:
            n = 0x14;
            break;
        default:
            return;
        }
    } else {
        switch (D_800EC23E) {
        case 4:
            n = 3;
            break;
        case 7:
            n = 5;
            break;
        case 1:
            n = 0;
            break;
        case 0x14:
            n = 0x13;
            break;
        default:
            return;
        }
    }
    Spike_SetState(n);
}

void Spike_UpdateBlink(void) {
    s32 r = -1;

    if (Overlay_GetState() == 1) {
        r = 0;
    } else if (g_SpikeHealth <= 0) { /* dead: eyes stay half-closed (user) */
        r = 1;
    } else if (((struct S_D_800EC350_80067AF0 *)&g_Game)->f_8150 == 10 && D_800B4D70->f_86 == 7) {
        r = 2;
    }
    if (r < 0) {
        switch (((struct S_D_800EC350_80067AF0 *)&g_Game)->f_0 % 120) {
        case 0:
            r = 0;
            break;
        case 0x72:
        case 0x76:
            r = 1;
            break;
        case 0x74:
            r = 2;
            break;
        }
        if (r < 0) {
            return;
        }
    }
    Spike_SetBlinkFrame(r);
}

typedef struct { s16 x, y, w, h; } RECT16;
void SetDrawMove(void *, RECT16 *, s32, s32);

/* Blink frame: copies the 16x64 VRAM strip of frame i (x 0x3D0 + 16i) over the live one at
   x 0x3C0 with a DR_MOVE at the end of the world OT (Spike_UpdateBlink picks i: his blink, per the user). */
void Spike_SetBlinkFrame(s32 i) {
    u32 *ot;
    RECT16 r;
    u8 *p;
    p = G_DRAW.prim;
    r.x = i * 16 + 0x3D0;
    r.y = 0;
    r.w = 16;
    r.h = 64;
    ot = &G_DRAW.db[G_DRAW.cur].ot[0xFFF];
    SetDrawMove(p, &r, 0x3C0, 0);
    ADD_PRIM_R(ot, p, "$3", "$2");
    p += 0x18;
    G_DRAW.prim = p;
}

/* Spike's climbing states (0x38 hold, 0x39 idle, 0x3A climb up, 0x3B/0x3C climb down) on a tree (user:
 * level 1 has climbable trees) or similar ladder,
 * pole or vine whose axis is at +0xB4/+0xB8 (top +0xB6, length +0xBE, +0xBA = can climb off the
 * top). Keeps him centred on it, moves him with the stick's Y (down at double speed), turns him
 * with the stick's X, and switches between the climb states on the animation's step frames. At
 * the top he climbs off (state 0xE) or stops; below the bottom he lets go (state 0, pushed back);
 * getting hit knocks him off (state 8). Velocity is zeroed while climbing. */
void Spike_StateClimb(void) {
    Scr_80067CAC_80067CAC *sc = (Scr_80067CAC_80067CAC *)0x1F800000;
    Anim_80064208_80064208_80067CAC *t;
    s32 v;
    s32 lo;
    s32 k;

    if (SP->state < 0x80) {
        t = g_SpikeAnimSets[0].f_4;
    } else {
        t = g_SpikeAnimSets[SP->gadget + 1].f_4;
    }
    sc->tbl = t;
    sc->f_4C = g_SpikeAnimSets[SP->gadget + 1].f_8;
    sc->f_50 = g_SpikeAnimSets[SP->gadget + 1].f_C;
    {
        s32 t = SP->f_B4 - SP->f_74.vx / 128;
        if (SP->x != t) {
            SP->x = (SP->x + t) / 2;
        }
    }
    {
        s32 t = SP->f_B8 - SP->f_74.vz / 128;
        if (SP->z != t) {
            SP->z = (SP->z + t) / 2;
        }
    }
    SP->frame++;
    if (sc->f_80 == 0) {
        v = -((struct S_D_800E5320_80067CAC *)&g_Pad)->sy / 8;
    } else {
        v = 0;
    }
    if (v > 0) {
        v *= 2;
    }
    SP->y += v;
    switch (SP->state) {
    case 0x3B:
    case 0x3C:
        if (SP->f_B6 < SP->y) {
            Spike_SetPlayMode(0);
            SP->x -= SP->f_60 / 32;
            SP->z -= SP->f_64 / 32;
            SP->f_120 = -SP->f_60 << 4;
            SP->f_128 = -SP->f_64 << 4;
            Spike_SetState(0);
        } else if (v <= 0) {
            Spike_SetState(0x39);
        }
        break;
    case 0x39:
        if (v > 0) {
            Spike_SetState(0x3B);
        } else if (v < 0) {
            Spike_SetState(0x3A);
        }
        break;
    case 0x3A:
        if (v > 0) {
            Spike_SetState(0x3B);
            break;
        }
        lo = SP->f_B6 - SP->f_BE;
        if (SP->y < lo) {
            if (SP->f_BA == 1) {
                Spike_SetPlayMode(0);
                SP->f_120 = 0;
                SP->f_124 = 0;
                SP->f_128 = 0;
                SP->y = SP->f_B6 - SP->f_BE - 0x100;
                Spike_SetState(0xE);
                return;
            }
            SP->y = lo;
        }
        if (v == 0) {
            k = SP->frame - sc->tbl[SP->state].start;
            if (k == 5 || k == 0xF) {
                Spike_SetState(0x39);
            }
        }
        break;
    default:
        Spike_SetState(0x38);
    case 0x38:
        break;
    }
    func_800649D8(g_SpikeAnimSets[0].f_8);
    func_800649D8(sc->f_4C);
    if (sc->f_80 == 0) {
        if (((struct S_D_800E5320_80067CAC *)&g_Pad)->sx >= 0x79) {
            ApplyMatrixSV(D_800AE7A0, &SP->f_74, &SP->f_74);
        }
        if (((struct S_D_800E5320_80067CAC *)&g_Pad)->sx < -0x78) {
            ApplyMatrixSV(D_800AE780, &SP->f_74, &SP->f_74);
        }
    }
    func_80066C90(&SP->f_74, &SP->f_60, 0x155);
    if (SP->frame < sc->tbl[SP->state].start) {
        SP->frame = sc->tbl[SP->state].end;
    }
    if (SP->frame > sc->tbl[SP->state].end) {
        SP->frame = sc->tbl[SP->state].start;
    }
    if (SP->y < SP->f_B6 - SP->f_BE) {
        SP->y = SP->f_B6 - SP->f_BE;
    }
    if (SP->f_B6 < SP->y) {
        SP->y = SP->f_B6;
    }
    if ((sc->f_54 & sc->f_58 & 0xA) && SP->state != 0x38) {
        Spike_SetState(8);
        SP->x -= SP->f_60 / 32;
        SP->z -= SP->f_64 / 32;
        SP->f_120 = -SP->f_60 << 4;
        SP->f_128 = -SP->f_64 << 4;
        SP->f_124 = -0x1E000;
        Spike_SetPlayMode(0);
        return;
    }
    SP->vx = 0;
    SP->vy = 0;
    SP->vz = 0;
    SP->f_120 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B70_pad);


INCLUDE_ASM("asm/nonmatchings/game/80060780", func_800681E4);

INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B88);
INCLUDE_RODATA("asm/nonmatchings/game/80060780", jtbl_800A5B88_pad);


typedef struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; } Rec_80068634;
typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0xC]; SVECTOR f_18; u8 pad20[4]; u16 f_24; } Obj_80068634;
struct Spike_80068634 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x20]; u32 f_50; u8 pad54[8]; u16 f_5C; u16 f_5E; SVECTOR f_60; u8 pad68[0x8A]; s8 f_F2; u8 padF3[0x2D]; s32 f_120; s32 f_124; s32 f_128; };
struct Pad_80068634 { u8 pad0[0x1BC]; s16 f_1BC; s16 f_1BE; };
typedef struct { u8 pad0[0x48]; s32 f_48; s32 f_4C; s32 f_50; } Scr_80068634;
extern Rec_80068634 g_SpikeAnimSets_68634[] asm("g_SpikeAnimSets");
Obj_80068634 *Collision_GetShape_68634(s32) asm("Collision_GetShape");
void func_800649D8_68634(s32) asm("func_800649D8");
#define SP_80068634 ((struct Spike_80068634 *)&g_Spike)
/* func_80068634: start a Spike action attached to a collision object: set the animation tables
 * (scratch +0x48/+0x4C/+0x50) from the base or current gadget set, clear +0x120..+0x128, step the
 * frame by 1 or 2 by the analog stick (pad +0x1BC + +0x1BE >= 0x65). If Spike's contact +0x50 is a
 * collision shape (top nibble 0xB) of type 0xB00, snap to it (position and direction) and run the
 * action tables (func_800649D8); otherwise go back to play mode 0, state 0. */
void func_80068634(void) {
    Scr_80068634 *scratch = (Scr_80068634 *)0x1F800000;
    Obj_80068634 *o;
    scratch->f_48 = SP_80068634->f_5E < 0x80 ? g_SpikeAnimSets_68634[0].f_4 : g_SpikeAnimSets_68634[SP_80068634->f_F2 + 1].f_4;
    scratch->f_4C = g_SpikeAnimSets_68634[SP_80068634->f_F2 + 1].f_8;
    scratch->f_50 = g_SpikeAnimSets_68634[SP_80068634->f_F2 + 1].f_C;
    SP_80068634->f_128 = 0;
    SP_80068634->f_120 = 0;
    SP_80068634->f_124 = 0;
    SP_80068634->f_5C += ((struct Pad_80068634 *)&g_Pad)->f_1BC + ((struct Pad_80068634 *)&g_Pad)->f_1BE < 0x65 ? 1 : 2;
    if ((SP_80068634->f_50 >> 28) == 0xB) {
        o = Collision_GetShape_68634((u16)SP_80068634->f_50 & 0xFFF);
        if ((o->f_24 & 0xFF00) == 0xB00) {
            SP_80068634->f_24 = o->f_0;
            SP_80068634->f_28 = o->f_4;
            SP_80068634->f_2C = o->f_8;
            SP_80068634->f_60 = o->f_18;
            func_800649D8_68634(g_SpikeAnimSets_68634[0].f_8);
            func_800649D8_68634(scratch->f_4C);
            return;
        }
    }
    Spike_SetPlayMode(0);
    Spike_SetState(0);
}


INCLUDE_ASM("asm/nonmatchings/game/80060780", func_800687D8);

void func_8006896C(s32 a) {
    s32 id;
    switch (a) {
    case 0:
    case 4:
        id = 0x86;
        break;
    case 3:
        id = 0x85;
        break;
    case 2:
    case 5:
        id = 0x84;
        break;
    case 6:
        return;
    case 7:
        id = 0x87;
        break;
    case 8:
        id = 0x88;
        break;
    case 9:
        id = 0x89;
        break;
    case 10:
        id = 0x8A;
        break;
    case 11:
        id = 0x8B;
        break;
    }
    Sound_PlayFixed(id);
}



void func_800689F0(void) {
    s16 k = ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_100;
    VEC_800689F0 sc;
    if (k >= 8) {
        return;
    }
    Anim_SetFrame(((struct S_D_800EC1E0_800689F0 *)&g_Spike));
    Matrix_LookAt(&((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_60, &((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_68, ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_14, 0);
    sc.vx = 0x1000 - (k << 9);
    sc.vy = (k << 11) + 0x1000;
    sc.vz = 0x1000 - (k << 9);
    ScaleMatrixL(((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_14, &sc);
    ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_14->t[0] = 0;
    ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_14->t[1] = k << 5;
    ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_14->t[2] = 0;
    func_80015504(((struct S_D_800EC1E0_800689F0 *)&g_Spike), 7);
    Model_ProjectBonedVerts(((struct S_D_800EC1E0_800689F0 *)&g_Spike));
    func_8001D4A8(D_800E7D00, ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_0->f_6);
    func_8001D530(D_800EC358, D_800E7D00, ((struct S_D_800EC1E0_800689F0 *)&g_Spike));
}

void func_80068ADC(void) {
    func_800689F0();
    if (D_800EC2E0 < 0x1E) {
        func_8006C92C();
    }
}

void func_80068B1C(void) {
    g_Spike.f_38 = 0;
    g_Spike.f_34 = 0;
    g_Spike.f_30 = 0;
    func_800689F0();
    if (g_Spike.f_100 < 0x10) {
        func_8006CC28();
    }
    g_Spike.f_100 = (s16) ((u16) g_Spike.f_100 + 1);
}

/* 1 while Spike is underwater: his state D_800EC23E is 0x46/0x47/0x49/0x4A/0x4C. The HUD then
   swaps the gadget icons for the air meter (Hud_DrawAirMeter, confirmed by the user). */
s32 Spike_IsUnderwater(void) {
    if (((u32) (D_800EC23E - 0x46) < 2U) || (D_800EC23E == 0x49) || (D_800EC23E == 0x4A) || (D_800EC23E == 0x4C)) {
        return 1;
    }
    return 0;
}

/* Keeps one looping sound going for what Spike is doing: in action state 0x47
 * (probably swimming with the Water Net) sound 0x73, or 0x3F while R1/R2 is held; otherwise
 * 0x73 while he moves fast. Stops the loop when none applies.
 */
typedef struct { u8 pad0[0x30]; s32 vx, vy, vz; u8 pad3C[0x22]; u16 state; } SpikeSnd_68BF0;
typedef struct { u8 pad0[0x8152]; u16 f_8152; } GameSnd_68BF0;
#define SP_SND ((SpikeSnd_68BF0 *)&g_Spike)
#define GM_SND ((GameSnd_68BF0 *)&g_Game)
extern s32 D_800E5478;
void Sound_Stop(s32, s32);
s32 Sound_Play(s32, s32);
/* Spike_UpdateGadgetLoopSound (80068BC0): keep the looping gadget sound in D_800F51D0 (+0x18 voice, +0x1A
 * sound id) in step with Spike: in state 0x47 sound 0x3F while pad bits 0xA are held (0x73
 * otherwise; none in stage mode 0xB), else 0x73 while |vx| + |vy| + |vz| >= 9. Stops the old
 * sound when it changes or stops. */
void Spike_UpdateGadgetLoopSound(void) {
    s32 snd = 0;

    if (SP_SND->state == 0x47) {
        if (GM_SND->f_8152 != 0xB) {
            if (D_800E5478 & 0xA) {
                snd = 0x3F;
            } else {
                snd = 0x73;
            }
        }
    } else if (abs(SP_SND->vx) + abs(SP_SND->vy) + abs(SP_SND->vz) >= 9) {
        snd = 0x73;
    }
    if (snd == 0) {
        if (D_800F51D0.f_18 != -1) {
            Sound_Stop(D_800F51D0.f_1A, D_800F51D0.f_18);
            D_800F51D0.f_18 = -1;
            D_800F51D0.f_1A = -1;
        }
    } else if (D_800F51D0.f_1A != snd) {
        if (D_800F51D0.f_18 != -1) {
            Sound_Stop(D_800F51D0.f_1A, D_800F51D0.f_18);
        }
        D_800F51D0.f_18 = Sound_Play(0, snd);
        if (D_800F51D0.f_18 != -1) {
            D_800F51D0.f_1A = snd;
        }
    }
}
