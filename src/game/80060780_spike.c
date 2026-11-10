#include "common.h"
#include "m2c_macros.h"
#include "gte.h"
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
void Matrix_SetIdentity(MATRIX_80066C90 *);
void RotMatrixY(s32, MATRIX_80066C90 *);

extern struct S_D_800EC1E0 { u8 pad_0[0x24]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad_3C[0x24]; s16 f_60; s16 f_62; s16 f_64; u8 pad_66[0xA]; s32 f_70; s16 f_74; s16 f_76; s16 f_78; u8 pad_7A[0x12]; s16 f_8C; u8 pad_8E[0x26]; s16 f_B4; s16 f_B6; s16 f_B8; s16 f_BA; s16 f_BC; s16 f_BE; s16 f_C0; s16 f_C2; s16 f_C4; s16 f_C6; s16 f_C8; s16 f_CA; u8 pad_CC[0x12]; u16 f_DE; s32 f_E0; u8 pad_E4[0x4]; s16 f_E8; u8 pad_EA[0x16]; s16 f_100; u8 pad_102[0x2]; s16 f_104; s16 f_106; s32 f_108; u8 pad_10C[0x4]; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad_130[0x6]; s16 f_136; u16 f_138; u8 pad_13A[0x2]; s16 f_13C; } g_Spike;

M2C_UNK Spike_WaterSplashOut();

s32 Floor_GetHeight(s32, s32, s32);
s32 func_800652E4(void);
extern struct S_D_800F5120 { u8 pad0[0x28]; s16 f_28; s16 f_2A; s16 f_2C; } g_GadgetState;
extern struct S_D_800E5320 { u8 pad_0[0xA4]; u16 f_A4[40]; u8 pad_F4[0x7C]; s32 f_170; u8 pad_174[0xE]; u16 f_182; u8 pad_184[0x18]; u16 f_19C; s16 pad19E; u16 f_1A0; } g_Pad;
void Spike_SetMoveDirFromStick(void);
void func_80066028(void);

extern s8 g_CurrentGadget;
M2C_UNK Spike_FxBump();
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

s32 SpikeCond_AnimEnded(void);
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
void Spike_StartJump(void);
void Spike_TurnAround(void);
extern s16 D_800EC26E;
M2C_UNK ApplyMatrixSV(M2C_UNK *, M2C_UNK *, M2C_UNK *);
extern M2C_UNK D_800AE760;
extern M2C_UNK D_800EC254;
extern M2C_UNK D_800AE740;
M2C_UNK Camera_EnterAim();
M2C_UNK Camera_ExitAim();
extern s16 g_AirTimer;
extern s16 D_800F51E4;
void Spike_PlayVoice(s32 a);
extern s16 D_800F5164;
void Spike_DrawStretched(void);
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
extern u8 g_ProjVerts[];
extern u32 *g_GameOt;
void Anim_SetFrame(void *);
void Matrix_LookAt(SVECTOR *, SVECTOR *, MAT_800689F0 *, s32);
void ScaleMatrixL(MAT_800689F0 *, VEC_800689F0 *);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void Model_CycleVertexColors(u8 *, s32);
void Model_DrawCycledColors(u32 *, u8 *, void *);
struct S_D_800EC1E0_800689F0 { S_Hdr_800689F0 *f_0; u8 pad4[0x10]; MAT_800689F0 *f_14; u8 pad18[0x48]; SVECTOR f_60; SVECTOR f_68; u8 pad70[0x90]; s16 f_100; };
s32 Vec_Length(s32, s32, s32);
struct Spike_80066ADC { u8 pad0[0x114]; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct Spike_80064208 { u8 pad0[0x18]; void *f_18; u8 pad1C[0x40]; u16 frame; u16 state; u8 pad60[0x10]; s32 f_70; u8 pad74[0x18]; s16 f_8C; s16 f_8E; s32 f_90; u8 pad94[0x5E]; s8 gadget; };
extern struct S_D_800F4DE0 { void *f_0; Anim_80064208_80064208 *f_4; void *f_8; void *f_C; } g_SpikeAnimSets[];
s32 Anim_GetFrame(void *, s32);
extern s16 D_800EC240;
extern s16 D_800EC244;
struct Game_80063EC4 { u8 pad0[0x8150]; u16 sub; u8 pad8152[0x144]; s16 f_8296; };
void VectorNormalSS(void *, void *);
s32 Floor_GetHeightAndSlope(s32, s32, s32, void *);
s32 func_80078C9C(s32, void *, void *);
extern s16 D_800AE7A0[];
extern s16 D_800AE780[];
void Spike_CheckTransitions(void *);
void Dir_TurnTowardMax(SVEC_80066C90 *a, SVEC_80066C90 *b, s32 ang);
struct S_D_800EC1E0_80067CAC { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };
struct S_D_800E5320_80067CAC { u8 pad0[0xA2]; s8 sx; s8 sy; };
struct g_Spike_80065A24 { u8 pad0[0x50]; u32 f_50; u8 pad54[0x98]; s16 f_EC; u8 padEE[0x16]; s16 f_104; s16 f_106; u8 pad108[0x30]; u16 f_138; };
extern struct S_D_800AEF60 { u8 pad0[0xC]; s16 f_C; u8 padE[2]; } D_800AEF60[];
s32 SpikeCond_PressedR1R2(void);
struct S_D_800EC010_80065ED4 { u8 pad0[0x18]; s32 f_18; u8 pad1C[0x18]; s32 f_34; u8 pad38[8]; s32 f_40; s32 f_44; };
struct g_Spike_800655C4 { u8 pad0[0x5C]; u16 f_5C; u16 f_5E; };
struct g_Pad_800655C4 { u8 pad0[0xA4]; u16 f_A4[0x66]; s32 f_170; };
extern struct S_D_800F51D0 { u8 pad0[0x10]; s32 f_10; u8 pad14[4]; s16 f_18; s16 f_1A; } D_800F51D0;
extern u8 D_800E6916;
void Gadget_StopSounds(s32);
void Spike_WaterSplashIn(void);
void Radar_ResetScan(void);
struct g_Spike_80066DAC { u8 pad0[0x94]; S16x10 f_94; s32 f_A8; s32 f_AC; s32 f_B0; u8 padB4[0x2C]; s32 f_E0; };
struct g_Spike_80066358 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; SVECTOR f_60; u8 pad68[0xC]; SVECTOR f_74; u8 pad7C[0xA4]; s32 f_120; s32 f_124; s32 f_128; };
struct g_Pad_80066358 { u8 pad0[0x19C]; SVECTOR f_19C; };
void Spike_GroundBlast(void);
void Spike_TakeDamage(s32);
struct g_Spike_80065C20 { u8 pad0[0xF2]; s8 f_F2; u8 padF3[0x21]; s32 f_114; u8 pad118[4]; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct g_GadgetState_80065C20 { u8 pad0[4]; s16 f_4; u8 pad6[2]; s32 f_8; };
void Camera_ExitLook(void);
struct S_D_800EC010_80065C20 { u8 pad0[4]; s32 f_4; s32 f_8; u8 padC[0x1C]; s32 f_28; };
struct S_D_800EC1E0_800661D4 { u8 pad_0[0x60]; SVEC_800661D4_800661D4 f_60; u8 pad_68[0xC]; SVEC_800661D4_800661D4 f_74; u8 pad_7C[0x98]; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; };
struct S_D_800E5320_800661D4 { u8 pad_0[0x178]; u16 f_178; u8 pad_17A[0x1A]; u16 f_194; u8 pad_196[2]; u16 f_198; };
struct S_D_800EC010_800661D4 { u8 pad_0[0x10]; s32 f_10; u8 pad_14[0x10]; s32 f_24; u8 pad_28[0x8]; s32 f_30; };

typedef struct { u8 pad0[0x24]; s32 x, y, z; s32 vx, vy, vz; SVECTOR prevDir; u8 pad44[0xC]; u32 coll; u8 pad54[8]; u16 frame; u16 state; SVECTOR dir; SVECTOR up; s32 animFlags; SVECTOR moveDir; s32 lean; SVECTOR aim; u16 f_88; u16 f_8A; u16 f_8C; u16 f_8E; u8 pad90[0x48]; SVECTOR f_D8; s32 events; s32 prevEvents; s16 health; u8 padEA[2]; s16 floorKind; u8 f_EE; u8 padEF; u8 padF0; u8 f_F1; s8 gadget; u8 padF3[9]; u16 f_FC; s16 f_FE; u8 pad100[2]; s16 f_102; s16 slopeX, slopeZ; s32 f_108, f_10C, f_110; s32 f_114, f_118, f_11C; s32 f_120, f_124, f_128; s32 ground; s16 lastX, lastY, lastZ; s16 f_136; u16 water; u16 prevWater; s16 waterTop; s16 waterY; u8 pad140[8]; u16 idle; u8 idleLoading; u8 idleReady; } Spike_SU;
typedef struct { u8 pad0[0x158]; s32 held; u8 pad15C[4]; s32 pressed; u8 pad164[0x14]; union { u32 both; struct { u16 l, r; } h; } sticks; u16 f_17C, f_17E; u16 magL; u16 magR; u8 pad184[0x10]; SVECTOR dirL; SVECTOR dirR; s32 f_1A4, f_1A8; s16 f_1AC, f_1AE, f_1B0, f_1B2, f_1B4, f_1B6, f_1B8, f_1BA, f_1BC, f_1BE; } Pad_SU;
typedef struct { u16 f_0, f_2; unsigned steer : 4; unsigned tilt : 4; unsigned move : 8; unsigned cb : 8; unsigned flagLo : 4; unsigned flagHi : 4; } AnimEnt_SU;
typedef struct { void *f_0; AnimEnt_SU *anims; void *f_8; void *events; } AnimSet_SU;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MATRIX_SU;
typedef struct { SVECTOR v0; SVECTOR dir; SVECTOR v2; u8 pad18[0x10]; MATRIX_SU m; AnimEnt_SU *anims; void *f_4C; void *events; s32 held, pressed; u16 stickL, stickR, f_60, f_62, magL, magR; s32 f_68, f_6C; s16 f_70, f_72, f_74, f_76, f_78, f_7A, f_7C, f_7E; s32 noControl; } Scr_SU;
typedef struct { u8 pad0[0x32]; u8 look; u8 pad33[5]; u8 firstPerson; u8 pad39[0xD]; u8 aim; } Cam_SU;
typedef struct { u8 pad0[0x18]; s16 air; s16 airLow; u8 pad1C[2]; s16 f_1E; } Air_SU;
typedef struct { s32 f_0, f_4; u8 pad8[2]; s16 f_A; u8 padC[2]; s16 f_E; } Floor_SU;
typedef struct { u8 pad0[0x80]; void *buf; u8 pad84[2]; s16 clip; } IdleClip_SU;
typedef struct { s32 x, y, z; u8 padC[0xC]; SVECTOR dir; s16 f_20; u8 pad22[2]; s16 f_24, f_26; } Shape_SU;
typedef struct { s16 x; u8 pad2[2]; s16 y; u8 pad6[2]; s16 z; } ExitShape_SU;
typedef struct { u8 loc[4]; void *buf; s32 sectors; } CdRead_SU;
struct Game_SU { u32 frame; u8 pad4[0x8122]; u16 stage; u8 pad8128[2]; u16 area; u8 pad812C[0x24]; u16 playMode; u16 f_8152; u8 pad8154[0x17C]; s32 lastIdleClip; };
extern Spike_SU g_Spike_SU asm("g_Spike");
extern Pad_SU g_Pad_SU asm("g_Pad");
extern struct Game_SU g_Game_SU asm("g_Game");
extern Cam_SU D_800E68D0_SU asm("g_CameraState");
extern Air_SU D_800F4DB0_SU asm("g_HudState");
extern AnimSet_SU g_SpikeAnimSets_SU[] asm("g_SpikeAnimSets");
extern AnimEnt_SU *D_800F4DE4_SU asm("D_800F4DE4");
extern void *D_800F4DE8_SU asm("D_800F4DE8");
extern Floor_SU D_800AEF60_SU[] asm("D_800AEF60");
extern void (*D_800B03AC_SU[])(void) asm("Spike_Actions");
extern IdleClip_SU *D_800B4D70_SU asm("D_800B4D70");
extern struct { u8 pad0[0x8E]; s8 f_8E; s8 f_8F; } *D_800B4DC4_SU asm("D_800B4DC4");
extern void (*D_800B4DC0_SU)(void) asm("D_800B4DC0");
extern void (*D_800B4DC8_SU)(void) asm("D_800B4DC8");
extern struct { s32 f_0; u8 pad4[2]; s16 f_6; u8 pad8[0x44]; s32 f_4C, f_50; u8 pad54[0xC]; s16 f_60, f_62, f_64; } g_GadgetState_SU asm("g_GadgetState");
extern struct { s32 f_0; s16 f_4; s16 f_6; s32 f_8, f_C, f_10, f_14; } g_GadgetPos_SU asm("g_GadgetState");
extern struct { u8 pad0[0x2C]; s32 f_2C; } *D_800F516C_SU asm("D_800F516C");
extern struct { u8 pad0[0x2C]; s32 f_2C; } *D_800F5170_SU asm("D_800F5170");
extern struct { u8 pad0[0x14]; s16 f_14; } D_800F51D0_SU asm("D_800F51D0");
extern struct { u8 pad0[8]; s32 f_8; u8 padC[4]; s32 f_10; u8 pad14[0x30]; u8 f_44[1]; } D_800E3890_SU asm("g_Cd");
extern s16 D_800F5144_SU asm("D_800F5144");
extern u8 D_800E38D4_SU[] asm("D_800E38D4");
extern MATRIX_SU D_800AE740_SU asm("D_800AE740");
extern MATRIX_SU D_800AE760_SU asm("D_800AE760");
extern s32 D_800EC014_SU asm("D_800EC014");
extern s32 D_800EC02C_SU asm("D_800EC02C");
extern s32 D_800EC034_SU asm("D_800EC034");
void Spike_SetState_SU(s32) asm("Spike_SetState");
void Spike_AnimEvents_SU(void *, void *) asm("Spike_AnimEvents");
void Spike_HandleHit_SU(void) asm("Spike_HandleHit");
void Spike_StartDamageEffect_SU(s32) asm("Spike_StartDamageEffect");
void Spike_StateClimb_SU(void) asm("Spike_StateClimb");
void Spike_SwapGadgetState_SU(void) asm("Spike_SwapGadgetState");
void Spike_ResetAir_SU(void) asm("Spike_ResetAir");
void Spike_UpdateMode8Scene_SU(void) asm("Spike_UpdateMode8Scene");
s32 Gadget_SelectFromButtons_SU(void) asm("Gadget_SelectFromButtons");
s32 Gadget_Cancel_SU(void) asm("Gadget_Cancel");
s32 Gadget_Select_SU(s32, s32) asm("Gadget_Select");
s32 Game_NotExiting_SU(void) asm("Game_NotExiting");
s32 Game_SetMode_SU(s32, s32, s32) asm("Game_SetMode");
s32 Cd_PlayXaTrack_SU(s32) asm("Cd_PlayXaTrack");
s32 Cd_QueueCommand_SU(s32, void *, void *, s32) asm("Cd_QueueCommand");
s32 rsin_SU(s32) asm("rsin");
void *func_8008C09C_SU(s32) asm("Mem_AllocPages");
void func_8008C064_SU(s32) asm("Mem_Free");
void Spike_Draw_SU(void) asm("Spike_Draw");
void func_80066094_SU(void) asm("Spike_EnterSwimIfInWater");
void func_800668A0_SU(void *) asm("func_800668A0");
s32 func_8006699C_SU(s32) asm("Spike_ClampMoveStepXZ");
void func_800681E4_SU(void) asm("Spike_StateHangBar");
void func_80068634_SU(void) asm("Spike_UpdateOnShape");
void func_800687D8_SU(void) asm("Spike_UpdateRide");
void func_8006896C_SU(s32) asm("Spike_PlayVoice");
void func_80068ADC_SU(void) asm("Spike_DrawWarpA");
void func_80068B1C_SU(void) asm("Spike_DrawWarpB");
void func_8006B70C_SU(void) asm("Spike_FxRunDust");
void func_8006BF10_SU(void) asm("func_8006BF10");
void func_80142808_SU(void *) asm("func_80142808");
void func_80014804_SU(SVECTOR *, MATRIX_SU *) asm("Matrix_FromFacingXZ");
s32 Water_Query_SU(s32, s32, s32) asm("Water_Query");
#define SPK g_Spike_SU
#define PAD g_Pad_SU
#define GAME g_Game_SU
#define SCR scr
s16 Floor_GetHeightSlope_SU(s32, s32, s32, s16 *) asm("Floor_GetHeightAndSlope");
void func_80142808_v(void) asm("func_80142808");
extern u16 D_800E54A0_SU asm("D_800E54A0");
void ApplyMatrixSV_SU(void *, void *, void *) asm("ApplyMatrixSV");
void Camera_ExitAim_SU(void) asm("Camera_ExitAim");
void Camera_ExitLook_SU(void) asm("Camera_ExitLook");
void CdIntToPos_SU(s32, void *) asm("CdIntToPos");
s32 CdPosToInt_SU(void *) asm("CdPosToInt");
void *Cd_GetFileEntry_SU(void *, s32) asm("Cd_GetFileEntry");
void *CollShape_Alloc_SU(void) asm("CollShape_Alloc");
s32 Collision_GetShape_SU(s16) asm("Collision_GetShape");
s32 Collision_Set_SU(s32, void *, void *) asm("Collision_Set");
void Effect_SpawnAt_SU(s32, void *) asm("Effect_SpawnAt");
void Pad_Vibrate_SU(s32, s32, s32) asm("Pad_Vibrate");
s32 Sound_PlayFixed_SU(s32) asm("Sound_PlayFixed");
s32 Spike_ClampMoveStep_SU(s32) asm("Spike_ClampMoveStep");
void Spike_LoadModelData_SU(void *) asm("Spike_LoadModelData");
void Spike_SetPlayMode_SU(s32) asm("Spike_SetPlayMode");
void Spike_TakeDamage_SU(s32) asm("Spike_TakeDamage");
s32 Vec_Length_SU(s32, s32, s32) asm("Vec_Length");
s32 VectorNormalSS_SU(void *, void *) asm("VectorNormalSS");
void func_800649D8_SU(void *) asm("Spike_CheckTransitions");
s32 func_800652E4_SU(void) asm("func_800652E4");
void func_80066C90_SU(void *, void *, s32) asm("Dir_TurnTowardMax");
void func_8006BF84_SU(void) asm("Spike_GroundBlast");
s32 rcos_SU(s32) asm("rcos");

void Spike_Update(void) {
    /* Spike's per-frame update. In order:
     * - Idle animations: after 0x385 frames with no input while standing still, one of 8 idle
     *   animations is read from CD file 0x13 (never the same one twice in a row) and played in
     *   play mode 10; any input frees it again.
     * - Copies the pad into the scratchpad, cleared or masked while the camera is in look / first
     *   person / aim mode, during mode 0xB and when Spike is dead.
     * - Touching a stage exit (collision kind 8) ends the stage (mode 0x10, or 0x21 from stage 0x57).
     * - Event bits from the last frame can switch the play mode (5, 6, 3, 1).
     * - Play modes 1/2/3 run per-area routines in the level overlay, 8/12/13 other routines;
     *   5/6/7/10 run their state routine; the rest (normal play) steers, moves, swims, takes floor
     *   damage and runs the animation callback.
     * - All modes but 1/2/3/8/12/13 then update the body tilt, the Stun Club and Sky Flyer
     *   hitboxes, integrate the velocity, run collision (Spike_Draw) and the animation events. */
    Scr_SU *scr = (Scr_SU *)0x1F800000;
    SVECTOR n;
    SVECTOR fx, fx2; /* unused, but part of the original stack frame */
    AnimEnt_SU *e;
    Shape_SU *c;
    s32 t, lim, ev, steer;
    u32 kind;
    struct { u8 pad0[0x8E]; s8 f_8E; s8 f_8F; } *g;

    /* idle animations */
    if (GAME.playMode == 0) {
        if (GAME.f_8152 != 0xB && PAD.sticks.both == 0 && !(PAD.held & 0xEFF) && SPK.x == SPK.lastX &&
            SPK.y == SPK.lastY && SPK.z == SPK.lastZ && D_800E68D0_SU.firstPerson != 1) {
            if (++SPK.idle >= 0x385 && SPK.state < 2) {
                if (SPK.idleReady != 0) {
                    Spike_SetPlayMode_SU(10);
                } else if (SPK.idleLoading == 0) {
                    void *buf = func_8008C09C_SU(0xA000);
                    CdRead_SU rd;
                    CdRead_SU file;
                    SVECTOR unused; /* unused, but part of the original stack frame */
                    u8 mode;
                    s32 pos;
                    s32 clip;
                    D_800B4D70_SU = func_8008C09C_SU(0x88);
                    D_800B4D70_SU->buf = buf;
                    Cd_GetFileEntry_SU(&file, 0x13);
                    pos = CdPosToInt_SU(&file);
                    __asm__ volatile("");
                    clip = GAME.frame & 7;
                    if (GAME.lastIdleClip == clip) {
                        clip = (clip + 1) % 8;
                    }
                    GAME.lastIdleClip = clip;
                    D_800B4D70_SU->clip = clip;
                    CdIntToPos_SU(pos + clip * 20, rd.loc);
                    mode = 0x80;
                    Cd_QueueCommand_SU(0xE, &mode, D_800E3890_SU.f_44, 0);
                    rd.buf = D_800B4D70_SU->buf;
                    rd.sectors = 0x14;
                    Cd_QueueCommand_SU(2, &rd, D_800E3890_SU.f_44, 0);
                    Cd_QueueCommand_SU(0x20, &rd, D_800E3890_SU.f_44, (s32)&SPK.idleReady);
                    SPK.idleLoading = 1;
                    Game_SetMode_SU(3, 0, 0);
                    D_800E3890_SU.f_8 = 0;
                    D_800E3890_SU.f_10 = -1;
                }
            }
        } else {
            SPK.idle = 0;
            if (SPK.idleReady != 0) {
                func_8008C064_SU((s32)D_800B4D70_SU->buf);
                func_8008C064_SU((s32)D_800B4D70_SU);
                Spike_LoadModelData_SU(0);
            }
        }
    }

    /* controller copy */
    if (D_800E68D0_SU.look == 1 || D_800E68D0_SU.firstPerson == 1 || D_800E68D0_SU.aim == 1 ||
        GAME.f_8152 == 0xB || SPK.health == 0) {
        if (GAME.f_8152 == 0xB || SPK.health == 0) {
            SCR->held = 0;
            SCR->pressed = 0;
        } else {
            if (D_800E68D0_SU.look == 1) {
                SCR->held = PAD.held & 0xFA;
                SCR->pressed = PAD.pressed;
            }
            if (D_800E68D0_SU.firstPerson == 1 || D_800E68D0_SU.aim == 1) {
                SCR->held = PAD.held & 0x2F0;
                SCR->pressed = PAD.pressed;
            }
        }
        SCR->stickL = 0;
        SCR->magL = 0;
        if (D_800E68D0_SU.aim == 1 && GAME.f_8152 != 0xB) {
            SCR->stickR = PAD.sticks.h.r;
            SCR->magR = PAD.magR;
        } else {
            SCR->stickR = 0;
            SCR->magR = 0;
        }
        SCR->f_70 = 0x1000;
        SCR->f_74 = 0x1000;
        SCR->f_60 = 0;
        SCR->f_62 = 0;
        SCR->f_68 = 0;
        SCR->f_6C = 0;
        SCR->f_72 = 0;
        SCR->f_76 = 0;
        SCR->f_78 = 0;
        SCR->f_7A = 0;
        SCR->f_7C = 0;
        SCR->f_7E = 0;
        SCR->noControl = 1;
    } else {
        SCR->held = PAD.held;
        SCR->pressed = PAD.pressed;
        SCR->stickL = PAD.sticks.h.l;
        SCR->stickR = PAD.sticks.h.r;
        SCR->f_60 = PAD.f_17C;
        SCR->f_62 = PAD.f_17E;
        SCR->magL = PAD.magL;
        SCR->magR = PAD.magR;
        SCR->f_68 = PAD.f_1A4;
        SCR->f_6C = PAD.f_1A8;
        SCR->f_72 = PAD.f_1AE;
        SCR->f_70 = PAD.f_1AC;
        SCR->f_76 = PAD.f_1B2;
        SCR->f_74 = PAD.f_1B0;
        SCR->f_78 = PAD.f_1B4;
        SCR->f_7A = PAD.f_1B6;
        SCR->f_7C = PAD.f_1BC;
        SCR->noControl = 0;
        SCR->f_7E = PAD.f_1BE;
    }

    {
        AnimEnt_SU *at;
        if (SPK.state < 0x80) {
            at = D_800F4DE4_SU;
        } else {
            at = g_SpikeAnimSets_SU[SPK.gadget + 1].anims;
        }
        SCR->anims = at;
    }
    SCR->f_4C = g_SpikeAnimSets_SU[SPK.gadget + 1].f_8;
    SCR->events = g_SpikeAnimSets_SU[SPK.gadget + 1].events;
    SPK.ground = Floor_GetHeightSlope_SU(SPK.x, SPK.y, SPK.z, &SPK.slopeX);
    if ((*(u16 *)0x1F8003F8 & 0xF) == 1) {
        SPK.f_136 = 0;
    } else {
        SPK.f_136 = 1;
    }

    if (SPK.coll >> 28 == 8) {
        /* stage exit */
        ExitShape_SU *x = (ExitShape_SU *)Collision_GetShape_SU((s16)SPK.coll);
        SVECTOR ex;
        ex.vx = x->x;
        ex.vy = x->y - 0x80;
        ex.vz = x->z;
        if (Game_NotExiting_SU() != 0) {
            if (GAME.stage == 0x57) {
                Game_SetMode_SU(0x21, GAME.stage, GAME.area);
            } else {
                Game_SetMode_SU(0x10, GAME.stage, GAME.area);
            }
        }
        SPK.coll = 0;
    } else if (GAME.playMode != 0xD && SPK.health > 0) {
        if (SPK.events & 2) {
            if (func_800652E4_SU() == 0 || (PAD.held & 0xA)) {
                Spike_SetPlayMode_SU(5);
            } else {
                SPK.vy = 0;
            }
        }
        if ((SPK.events & 4) && GAME.playMode != 6 && SPK.vy >= 0) {
            Spike_SetPlayMode_SU(6);
        }
        if ((SPK.events & 0x10) && SPK.health > 0) {
            g = D_800B4DC4_SU;
            if (!(SPK.prevEvents & 0x10)) {
            if (g->f_8F >= 2) {
                g->f_8F--;
            } else if (GAME.playMode == 0) {
                if (g_GadgetState_SU.f_0 & 8) {
                    Spike_SetPlayMode_SU(3);
                } else if ((g_GadgetState_SU.f_0 & 4) && D_800B4DC4_SU->f_8E > 0) {
                    Spike_SetPlayMode_SU(1);
                }
            }
            }
        }
    }
    SPK.prevEvents = SPK.events;

    switch (GAME.playMode) {
    case 1:
        D_800B4DC8_SU();
        return;
    case 3:
        D_800B4DC0_SU();
        return;
    case 2:
        func_80142808_v();
        return;
    case 8:
        Spike_UpdateMode8Scene_SU();
        return;
    case 5:
        Gadget_SelectFromButtons_SU();
        Spike_StateClimb_SU();
        break;
    case 6:
        Gadget_SelectFromButtons_SU();
        func_800681E4_SU();
        break;
    case 7:
        Gadget_SelectFromButtons_SU();
        func_80068634_SU();
        break;
    case 10:
        func_800687D8_SU();
        break;
    case 12:
        func_80068ADC_SU();
        return;
    case 13:
        func_80068B1C_SU();
        return;
    ev8:
        SPK.dir = SPK.f_D8;
        SPK.f_114 = SPK.f_D8.vx << 5;
        SPK.f_11C = SPK.f_D8.vz << 5;
        Spike_SetState_SU(6);
        Sound_PlayFixed_SU(0x27);
        goto moved;
    stick:
        SPK.f_114 = (PAD.dirL.vx * PAD.magL) >> 2;
        SPK.f_11C = (PAD.dirL.vz * PAD.magL) >> 2;
        SPK.moveDir = PAD.dirL;
        goto moved;
    default:
        /* normal play */
        SCR->v0.vy = 0;
        SCR->v0.vx = SPK.vx - SPK.f_114;
        SCR->v0.vz = SPK.vz - SPK.f_11C;
        if (VectorNormalSS_SU(&SCR->v0, &SCR->v0) > 0x100) {
            SPK.vx /= 4;
            SPK.vz /= 4;
        }
        if (SPK.f_118 - SPK.vy >= 8 && SPK.vy < 0) {
            SPK.vy = SPK.f_118 - 7;
        }
        do {
        ev = SPK.events;
        if (ev & 8) {
            goto ev8;
        } else if (ev & 0x40) {
            SPK.vy = -0x6E;
            SPK.y--;
            Spike_SetState_SU(0x2C);
            func_8006BF84_SU();
            if (PAD.sticks.h.l != 0) {
                goto stick;
            }
            SPK.moveDir = SPK.dir;
        } else {
            if (ev & 0x20) {
                switch (SPK.state) {
                case 0x0:
                    SPK.vy = -0x3C;
                    SPK.y--;
                    Spike_SetState_SU(8);
                    break;
                case 0x9:
                    if (ABS(SPK.vy) < 0x26) {
                        SPK.vy -= 0x14;
                        SPK.moveDir = SPK.dir;
                        Spike_SetState_SU(0x35);
                    }
                    break;
                case 0x36:
                    Spike_SetPlayMode_SU(0xD);
                    break;
                }
            }
            SPK.f_114 = (SPK.vx << 12) + SPK.f_108;
            SPK.f_11C = (SPK.vz << 12) + SPK.f_110;
        }
        } while (0);

    moved:
        /* water and the air meter */
        SPK.prevWater = SPK.water;
        SPK.water = Water_Query_SU(SPK.x, SPK.y, SPK.z);
        if (SPK.water >> 12 == 1) {
            s16 *wi = (s16 *)0x1F8003D4;
            SPK.waterY = wi[5];
            SPK.waterTop = SPK.waterY - wi[8];
            if (SPK.y - SPK.waterTop < 0x100 && SPK.health > 0) {
                t = D_800F4DB0_SU.air;
                if (t < 600) {
                    t += 15;
                    if (t > 600) {
                        t = 600;
                        Sound_PlayFixed_SU(0x41);
                    }
                    if (t < 450 && D_800F4DB0_SU.airLow != 0) {
                        Sound_PlayFixed_SU(0x40);
                    }
                }
                D_800F4DB0_SU.air = t;
                D_800F4DB0_SU.airLow = 0;
            } else if ((u32)(SPK.state - 0x46) < 2) {
                t = D_800F4DB0_SU.air - 1;
                if (t < 150) {
                    if (GAME.frame % 10 == 0) {
                        Sound_PlayFixed_SU(0x23);
                    }
                } else if (t < 300) {
                    if (GAME.frame % 25 == 0) {
                        Sound_PlayFixed_SU(0x23);
                    }
                }
                D_800F4DB0_SU.air = t;
                D_800F4DB0_SU.airLow = 1;
                if (t <= 0) {
                    Spike_TakeDamage_SU(5);
                }
            }
        }
        switch (SPK.state) {
        case 0x49:
        case 0x4A:
            SPK.vx = 0;
            SPK.vy = 0;
            SPK.vz = 0;
            SPK.f_10C = 0;
            SPK.f_114 = 0;
            SPK.f_11C = 0;
            /* fallthrough */
        case 0x46:
        case 0x47:
        case 0x4C:
            switch (SPK.water & 0xF) {
            case 0:
                if (SPK.state != 0x47) {
                    SPK.f_10C -= 0x800;
                }
                break;
            case 1:
                SPK.vy /= 2;
                if (SPK.y - 0x9C < SPK.waterTop) {
                    SPK.f_10C += 0x2000;
                }
                break;
            case 2:
                SPK.f_10C += 0x5000;
                break;
            }
            {
                Spike_SU *sp = &SPK;
                sp->vy = sp->vy < -0x10 ? -0x10 : sp->vy > 0x10 ? 0x10 : sp->vy;
            }
            break;
        case 0x4D:
            SPK.vx = 0;
            SPK.vy = 0;
            SPK.vz = 0;
            break;
        default:
            SPK.f_10C += D_800EC014_SU << 7;
            break;
        }
        {
        s32 r = (SPK.vy << 12) + SPK.f_10C;
        SPK.f_128 = 0;
        SPK.f_120 = 0;
        SPK.f_110 = 0;
        SPK.f_10C = 0;
        SPK.f_108 = 0;
        SPK.f_124 = SPK.f_118 = r;
        }
        if (Gadget_SelectFromButtons_SU() != 0) {
            AnimEnt_SU *at;
            if (SPK.state < 0x80) {
                at = D_800F4DE4_SU;
            } else {
                at = g_SpikeAnimSets_SU[SPK.gadget + 1].anims;
            }
            SCR->anims = at;
            SCR->f_4C = g_SpikeAnimSets_SU[SPK.gadget + 1].f_8;
            SCR->events = g_SpikeAnimSets_SU[SPK.gadget + 1].events;
            if (SPK.state >= 0x80) {
                Spike_SetState_SU(SPK.ground > SPK.y ? 0x24 : 0);
            }
        }

        /* steering: the wanted direction in SCR->dir */
        steer = SCR->anims[SPK.state & 0x7F].steer;
        SCR->dir = SPK.dir;
        if (D_800E68D0_SU.aim != 1) {
            switch (steer) {
            case 0:
                if (SCR->stickL != 0) {
                    SCR->dir = PAD.dirL;
                    if (SCR->dir.vx == 0 && SCR->dir.vz == 0) {
                        SCR->dir = SPK.dir;
                    }
                }
                break;
            case 1:
                if (SCR->stickL != 0) {
                    SCR->v2 = PAD.dirL;
                    func_80066C90_SU(&SCR->v2, &SCR->dir, 0x71);
                }
                break;
            case 2:
                if (SCR->stickL != 0) {
                    SCR->v2 = PAD.dirL;
                    func_80066C90_SU(&SCR->v2, &SCR->dir, 0x155);
                }
                break;
            case 4: {
                s32 l;
                s32 d;
                if (SCR->stickL != 0) {
                    SCR->v2 = PAD.dirL;
                    func_80066C90_SU(&SCR->v2, &SCR->dir, 0x71);
                }
                l = 0;
                if (PAD.sticks.h.l == 0) {
                    if (PAD.held & 0x200) {
                        l = 0x300;
                    } else if (PAD.held & 0xA) {
                        l = -0x300;
                    }
                } else if (PAD.held & 0x200) {
                    l = 0x300;
                } else {
                    l = PAD.magL * 6 - 0x300;
                }
                d = SPK.lean - l;
                if (d > 0x20) {
                    SPK.lean -= 0x20;
                } else if (d < -0x20) {
                    SPK.lean += 0x20;
                } else {
                    SPK.lean = l;
                }
                SCR->v2.vx = 0;
                SCR->v2.vy = rsin_SU(SPK.lean);
                SCR->v2.vz = -rcos_SU(SPK.lean);
                func_80014804_SU(&SCR->dir, &SCR->m);
                ApplyMatrixSV_SU(&SCR->m, &SCR->v2, &SPK.aim);
                break;
            }
            case 5:
                if (!(PAD.held & 0x200) && PAD.sticks.h.r != 0) {
                    SCR->v2.vy = 0;
                    SCR->v2.vx = -PAD.dirR.vx;
                    SCR->v2.vz = -PAD.dirR.vz;
                    func_80066C90_SU(&SCR->v2, &SCR->dir, 0x38);
                }
                break;
            case 6:
                if (SCR->stickR != 0) {
                    SCR->v2 = PAD.dirR;
                    func_80066C90_SU(&SCR->v2, &SCR->dir, 0x155);
                }
                break;
            case 7:
                func_80066C90_SU(&SPK.moveDir, &SPK.dir, 0x155);
                SCR->dir = SPK.dir;
                break;
            case 8:
                ApplyMatrixSV_SU(&D_800AE740_SU, &SPK.dir, &SCR->dir);
                break;
            case 9:
                ApplyMatrixSV_SU(&D_800AE760_SU, &SPK.dir, &SCR->dir);
                break;
            case 10:
                /* snap to the 8 directions */
                if (SCR->dir.vx >= 0x800) {
                    SCR->dir.vx = 0x1000;
                } else if (SCR->dir.vx < -0x7FF) {
                    SCR->dir.vx = -0x1000;
                } else {
                    SCR->dir.vx = 0;
                }
                if (SCR->dir.vz >= 0x800) {
                    SCR->dir.vz = 0x1000;
                } else if (SCR->dir.vz < -0x7FF) {
                    SCR->dir.vz = -0x1000;
                } else {
                    SCR->dir.vz = 0;
                }
                VectorNormalSS_SU(&SCR->dir, &SCR->dir);
                break;
            }
        }
        VectorNormalSS_SU(&SCR->dir, &SPK.dir);
        Spike_SwapGadgetState_SU();

        /* movement: the wanted velocity in f_120 / f_128 */
        if (D_800E68D0_SU.aim == 1) {
            SPK.f_128 = 0;
            SPK.f_120 = 0;
            SPK.frame++;
        } else {
            switch (SCR->anims[SPK.state & 0x7F].move) {
            case 0:
                SPK.f_128 = 0;
                SPK.f_120 = 0;
                SPK.frame++;
                break;
            case 1:
                SPK.f_120 = SPK.f_114 * 4000 / 4096;
                SPK.f_128 = SPK.f_11C * 4000 / 4096;
                SPK.f_EE = 0;
                SPK.frame++;
                break;
            case 2:
                SPK.frame++;
                SPK.f_120 = ((SPK.dir.vx / 2) * SCR->magL) >> 2;
                SPK.f_128 = ((SPK.dir.vz / 2) * SCR->magL) >> 2;
                break;
            case 3:
                if (PAD.sticks.h.l != 0) {
                    if (PAD.f_1B0 > 0) {
                        SPK.f_120 = SPK.dir.vx * SCR->magL / 8;
                        SPK.f_128 = SPK.dir.vz * SCR->magL / 8;
                    } else {
                        SPK.f_120 = 0;
                        SPK.f_128 = 0;
                    }
                } else {
                    SPK.f_128 = 0;
                    SPK.f_120 = 0;
                }
                SPK.f_8A += D_800E54A0_SU << 5;
                if (SPK.f_8A >= 0x1000) {
                    SPK.f_8A -= 0x1000;
                    SPK.frame++;
                }
                break;
            case 4:
                SPK.frame++;
                SPK.f_120 = (((SPK.dir.vx * SCR->magL) >> 7) * D_800EC034_SU) >> 5;
                SPK.f_128 = (((SPK.dir.vz * SCR->magL) >> 7) * D_800EC034_SU) >> 5;
                break;
            case 5:
                SPK.frame++;
                SPK.f_120 = (SCR->magL * PAD.dirL.vx * D_800EC02C_SU) >> 10;
                SPK.f_128 = (SCR->magL * PAD.dirL.vz * D_800EC02C_SU) >> 10;
                break;
            case 6:
                SPK.f_120 = 0;
                SPK.f_128 = 0;
                SPK.f_EE = 0;
                SPK.f_8A += SPK.f_8E;
                SPK.f_8C = 0xFFFF;
                SPK.frame += SPK.f_8A / 4096;
                SPK.f_8A %= 4096;
                break;
            case 7:
                SPK.frame++;
                SPK.f_120 = (((PAD.dirL.vx * SCR->magL) >> 7) * D_800EC034_SU) >> 5;
                SPK.f_128 = (((PAD.dirL.vz * SCR->magL) >> 7) * D_800EC034_SU) >> 5;
                break;
            case 8:
                SPK.f_120 = 0;
                SPK.f_128 = 0;
                SPK.f_EE = 0;
                SPK.frame++;
                break;
            case 9:
                SPK.f_120 = 0;
                SPK.f_124 = 0;
                SPK.f_128 = 0;
                SPK.frame++;
                break;
            case 10:
                SPK.f_120 = PAD.dirL.vx * 8;
                SPK.f_128 = PAD.dirL.vz * 8;
                SPK.frame++;
                break;
            case 11:
                if (PAD.sticks.h.l != 0) {
                    SPK.f_120 = SPK.dir.vx * SCR->magL / 8;
                    SPK.f_128 = SPK.dir.vz * SCR->magL / 8;
                } else {
                    SPK.f_128 = 0;
                    SPK.f_120 = 0;
                }
                SPK.frame++;
                break;
            case 12:
                if (SPK.state == 0x46) {
                    SPK.f_120 = 0;
                    SPK.f_124 = -0xA000;
                    SPK.f_128 = 0;
                    if ((SCR->pressed & 0xA) && D_800F51D0_SU.f_14 == 0) {
                        D_800F51D0_SU.f_14 = 0x1E;
                    }
                } else if (SCR->held & 0xA) {
                    SPK.f_120 = SPK.aim.vx << 5;
                    SPK.f_124 = SPK.aim.vy << 5;
                    SPK.f_128 = SPK.aim.vz << 5;
                    SPK.frame++;
                    if ((SCR->pressed & 0xA) && D_800F51D0_SU.f_14 == 0) {
                        D_800F51D0_SU.f_14 = 0x1E;
                    } else {
                        Pad_Vibrate_SU(1, 0x4A, 2);
                    }
                } else {
                    SPK.f_120 = SPK.aim.vx * 21;
                    SPK.f_124 = SPK.aim.vy * 21;
                    SPK.f_128 = SPK.aim.vz * 21;
                }
                t = D_800F51D0_SU.f_14;
                if (t > 0) {
                    Pad_Vibrate_SU(1, t * 8, 1);
                    if (t == 0x1C) {
                        Sound_PlayFixed_SU(0x3E);
                    }
                    if (t >= 11) {
                        func_8006BF10_SU();
                    }
                    D_800F51D0_SU.f_14 = t - 1;
                }
                Spike_ClampMoveStep_SU(0x1000);
                SPK.frame++;
                break;
            case 14:
                SPK.f_120 = SPK.f_114 * 0xED8 / 4096;
                SPK.f_128 = SPK.f_11C * 0xED8 / 4096;
                SPK.f_124 = SPK.f_124 * 0xED8 / 4096;
                SPK.frame++;
                break;
            case 15:
                SPK.f_120 = (SPK.dir.vx * D_800EC034_SU) >> 3;
                SPK.f_128 = (SPK.dir.vz * D_800EC034_SU) >> 3;
                func_8006699C_SU(0x6000);
                SPK.frame++;
                break;
            case 16:
                SPK.f_120 = (SPK.dir.vx * D_800EC034_SU) >> 4;
                SPK.f_128 = (SPK.dir.vz * D_800EC034_SU) >> 4;
                if (g_GadgetState_SU.f_6 != 0) {
                    SPK.f_114 = SPK.f_120;
                    SPK.f_11C = SPK.f_128;
                    g_GadgetState_SU.f_6 = 0;
                    Sound_PlayFixed_SU(0x27);
                }
                SPK.frame++;
                break;
            }
        }

        if (SPK.health > 0) {
            /* floor */
            n.vy = 0x200;
            n.vx = -SPK.slopeX;
            n.vz = -SPK.slopeZ;
            VectorNormalSS_SU(&n, &n);
            if (SPK.y >= SPK.ground) {
                volatile u16 *fa = (u16 *)0x1F8003F0;
                kind = (fa[4] >> 1) & 7;
                {
                s32 len = Vec_Length_SU(SPK.slopeX, 0x200, 0);
                if (len != 0) {
                    SPK.f_120 = (SPK.f_120 << 9) / len;
                }
                }
                {
                s32 len = Vec_Length_SU(SPK.slopeZ, 0x200, 0);
                if (len != 0) {
                    SPK.f_128 = (SPK.f_128 << 9) / len;
                }
                }
                if (fa[4] & 1) {
                    if (kind != 0) {
                        /* damaging floor, kinds 1-3 */
                        if (kind < 4 && SPK.state != 0x4D) {
                            Spike_SetState_SU(0x4D);
                            Spike_StartDamageEffect_SU(kind);
                            Pad_Vibrate_SU(1, 0x96, 0xC);
                            SPK.f_F1 = 0xF;
                            Spike_TakeDamage_SU(1);
                            if (D_800E68D0_SU.look == 1) {
                                Camera_ExitLook_SU();
                            }
                            if (D_800E68D0_SU.aim == 1) {
                                Camera_ExitAim_SU();
                            }
                            switch (kind) {
                            case 1:
                                Sound_PlayFixed_SU(0x34);
                                break;
                            case 2:
                                Sound_PlayFixed_SU(0x33);
                                break;
                            case 3:
                                Sound_PlayFixed_SU(0x35);
                                break;
                            }
                        }
                    } else {
                        /* bottomless pit */
                        Spike_TakeDamage_SU(5);
                        Spike_SetState_SU(0x2D);
                        func_8006896C_SU(0xA);
                        if (SPK.gadget == 4) {
                            Gadget_Select_SU(4, 4);
                        }
                        goto common;
                    }
                } else {
                    switch (kind) {
                    case 6:
                    case 7:
                        func_8006699C_SU(0);
                        if ((SPK.animFlags & 0xF0) != 0xA0) {
                            func_800668A0_SU(&n);
                        }
                        if (SPK.vy < 0) {
                            SPK.f_114 = SPK.f_120 >> 1;
                            SPK.f_11C = SPK.f_128 >> 1;
                        }
                        SPK.f_120 += SPK.slopeX * 0x38;
                        SPK.f_128 += SPK.slopeZ * 0x38;
                        func_8006699C_SU(0x4000);
                        break;
                    default: {
                        lim = D_800AEF60_SU[kind].f_E;
                        if (SPK.f_EE == 0 || SPK.slopeX > lim || SPK.slopeX < -lim || SPK.slopeZ > lim || SPK.slopeZ < -lim) {
                            func_8006699C_SU(D_800AEF60_SU[kind].f_4);
                            SPK.f_EE = 0;
                            SPK.f_120 += SPK.slopeX * 0x38;
                            SPK.f_128 += SPK.slopeZ * 0x38;
                        }
                        if ((SPK.events & 0x04000000) || SPK.floorKind == -1) {
                            s32 af = SPK.animFlags & 0xF0;
                            if (af != 0xA0 && af != 0xC0) {
                                lim = D_800AEF60_SU[kind].f_A;
                                if (ABS(SPK.slopeX) > lim || ABS(SPK.slopeZ) > lim) {
                                    func_800668A0_SU(&n);
                                }
                            }
                        }
                        if (SPK.f_EE != 0) {
                            if (func_8006699C_SU(D_800AEF60_SU[kind].f_0) != 0) {
                                SPK.f_EE = 0;
                                if (kind == 5 && (SPK.animFlags & 0xF0) == 0x30 && (GAME.frame & 0x20)) {
                                    Sound_PlayFixed_SU(0x83);
                                }
                            }
                        } else {
                            func_8006B70C_SU();
                            if ((SPK.animFlags & 0xF0) == 0xA0 && SPK.vy < 0) {
                                SPK.f_114 = SPK.f_120 >> 1;
                                SPK.f_11C = SPK.f_128 >> 1;
                            }
                            if (func_8006699C_SU(D_800AEF60_SU[kind].f_4) == 0) {
                                SPK.f_EE = 1;
                            }
                        }
                        break;
                    }
                    }
                }
                /* dust while sliding fast, sparkles in state 0x48 */
                if (SPK.state == 0x2F && (ABS(SPK.vx) + ABS(SPK.vz)) / 2 > 10) {
                    SVECTOR p = { SPK.x, SPK.y, SPK.z };
                    Effect_SpawnAt_SU(4, &p);
                }
                if (SPK.state == 0x48 && SPK.frame % 5 == 0) {
                    SVECTOR p = { SPK.x + rsin_SU(GAME.frame * 360) / 32, SPK.y - rsin_SU(GAME.frame * 360) / 32 - 0x80,
                                  SPK.z + rcos_SU(GAME.frame * 360) / 32 };
                    Effect_SpawnAt_SU(0x103, &p);
                }
                SPK.floorKind = kind;
            } else {
                /* in the air */
                SPK.floorKind = -1;
                func_8006699C_SU(SPK.state == 0x2B ? 0x3000 : 0x1000);
            }
            if (Gadget_Cancel_SU() != 0) {
                Spike_SetState_SU(0x46);
                Spike_ResetAir_SU();
                switch (SPK.gadget) {
                case 4:
                    g_GadgetPos_SU.f_4 = 0;
                    g_GadgetPos_SU.f_8 = 0;
                    g_GadgetPos_SU.f_C = 0;
                    g_GadgetPos_SU.f_10 = 0;
                    g_GadgetPos_SU.f_14 = 0;
                    break;
                case 3:
                    D_800F5144_SU = 0;
                    break;
                }
            }
        } else if ((SPK.animFlags & 0xF0) != 0xE0) {
            /* just died */
            Spike_SetState_SU(0x22);
            func_80066094_SU();
            Cd_PlayXaTrack_SU(GAME.frame & 1 ? 0xD : 0xF);
        }
        func_800649D8_SU(D_800F4DE8_SU);
        if (SPK.gadget != 9) {
            func_800649D8_SU(SCR->f_4C);
        }
        e = (AnimEnt_SU *)((SPK.state & 0x7F) * 8 + (s32)SCR->anims);
        if (e->cb != 0) {
            D_800B03AC_SU[e->cb]();
        }
        break;
    }

common:
    Spike_HandleHit_SU();
    if (GAME.playMode == 0xA) {
        SPK.animFlags = 0x12;
    } else {
        SPK.animFlags = SCR->anims[SPK.state & 0x7F].flagLo | (SCR->anims[SPK.state & 0x7F].flagHi << 4);
    }
    if (SPK.f_102 != 0) {
        SPK.animFlags &= 0xF0;
    }

    /* body tilt toward the floor normal n (n is only set in normal play) */
    {
    s32 tl = SCR->anims[SPK.state & 0x7F].tilt;
    switch (tl) {
    case 0:
        SPK.up.vz = 0;
        SPK.up.vx = 0;
        SPK.up.vy = 0x1000;
        break;
    case 1:
        n.vx /= 4;
        n.vz /= 4;
        n.vx = (n.vx + SPK.up.vx) >> 1;
        n.vz = (n.vz + SPK.up.vz) >> 1;
        VectorNormalSS_SU(&n, &SPK.up);
        break;
    case 2:
        n.vx /= 2;
        n.vz /= 2;
        n.vx = (n.vx + SPK.up.vx) >> 1;
        n.vz = (n.vz + SPK.up.vz) >> 1;
        VectorNormalSS_SU(&n, &SPK.up);
        break;
    case 3:
        n.vx = (n.vx + SPK.up.vx) >> 1;
        n.vz = (n.vz + SPK.up.vz) >> 1;
        VectorNormalSS_SU(&n, &SPK.up);
        break;
    case 4: {
        s32 d;
        n.vy = 0x1000;
        SPK.up.vy = 0x1000;
        if (SPK.state == 0x46) {
            n.vx = 0;
            n.vz = 0;
        } else {
            n.vx = -(PAD.dirR.vx * PAD.magR) >> 8;
            n.vz = -(PAD.dirR.vz * PAD.magR) >> 8;
        }
        {
        d = n.vx - SPK.up.vx;
        if (ABS(d) > 0x80) {
            SPK.up.vx += d > 0 ? 0x80 : -0x80;
        } else {
            SPK.up.vx = n.vx;
        }
        }
        {
        d = n.vz - SPK.up.vz;
        if (ABS(d) > 0x80) {
            SPK.up.vz += d > 0 ? 0x80 : -0x80;
        } else {
            SPK.up.vz = n.vz;
        }
        }
        break;
        }
    }
    }
    SPK.prevDir = SPK.dir;

    /* Stun Club swing hitbox (gadget 1, state 0x81) */
    if (SPK.gadget == 1 && SPK.state == 0x81) {
        SPK.f_8C = 0xFFFE;
        lim = PAD.f_1AE < 0 ? SCR->anims[2].f_0 : SCR->anims[2].f_2;
        if (SPK.f_88 != lim) {
            SPK.f_88 = lim;
            SPK.f_8A = 0;
        }
        {
        s32 cl = ABS(PAD.f_1AE * 4);
        s32 dd;
        cl = cl < 0 ? 0 : cl > 0x1000 ? 0x1000 : cl;
        dd = cl - SPK.f_8A;
        if (dd > 0x80) {
            SPK.f_8A += 0x80;
        } else if (dd < -0x80) {
            SPK.f_8A -= 0x80;
        } else {
            SPK.f_8A = cl;
        }
        }
        if (GAME.f_8152 != 0xB && SPK.health > 0 && (SPK.ground > SPK.y || PAD.f_1BC > 0x28)) {
            c = (Shape_SU *)CollShape_Alloc_SU();
            if (c != NULL) {
                c->dir = SPK.dir;
                c->x = g_GadgetState_SU.f_60;
                c->y = g_GadgetState_SU.f_62;
                c->z = g_GadgetState_SU.f_64;
                c->f_20 = 0x80;
                Collision_Set_SU(8, (void *)c, (void *)&SPK);
                c->f_24 = 0x100;
                c->f_26 = 0;
            }
        }
    }
    if (SPK.gadget == 0) {
        if (D_800F516C_SU != NULL && D_800F516C_SU->f_2C != 0) {
            Pad_Vibrate_SU(0, 1, 1);
        }
        if (D_800F5170_SU != NULL && D_800F5170_SU->f_2C != 0) {
            Pad_Vibrate_SU(0, 1, 1);
        }
        g_GadgetState_SU.f_4C = 0;
        g_GadgetState_SU.f_50 = 0;
    }
    /* falling hitbox under Spike (gadget 6, state 0x84) */
    if (SPK.gadget == 6 && SPK.state == 0x84 && SPK.vy < -7) {
        c = (Shape_SU *)CollShape_Alloc_SU();
        if (c != NULL) {
            c->dir.vx = 0;
            c->dir.vy = -0x1000;
            c->dir.vz = 0;
            c->x = SPK.x;
            c->y = SPK.y - 0x100;
            c->z = SPK.z;
            c->f_20 = 0x80;
            Collision_Set_SU(6, (void *)c, (void *)&SPK);
            c->f_24 = 0x12;
            c->f_26 = 0x201;
        }
    }
    if (SPK.gadget == 7 && GAME.f_8152 != 0xB && (PAD.held & PAD.pressed & 0x400)) {
        Gadget_Select_SU(7, 7);
    }

    /* integrate the velocity */
    SPK.f_120 += SPK.f_108;
    SPK.f_124 += SPK.f_10C;
    SPK.f_128 += SPK.f_110;
    SPK.f_120 = SPK.f_120 < -0x40000 ? -0x40000 : SPK.f_120 > 0x40000 ? 0x40000 : SPK.f_120;
    SPK.f_128 = SPK.f_128 < -0x40000 ? -0x40000 : SPK.f_128 > 0x40000 ? 0x40000 : SPK.f_128;
    SPK.f_124 = SPK.f_124 < -0x80000 ? -0x80000 : SPK.f_124 > 0x80000 ? 0x80000 : SPK.f_124;
    if (SPK.f_124 == 0x80000) {
        SPK.f_FC++;
    } else {
        SPK.f_FC = 0;
    }
    SPK.events = 0;
    Spike_Draw_SU();
    SPK.vx = SPK.f_120 / 4096;
    SPK.vy = SPK.f_124 / 4096;
    SPK.vz = SPK.f_128 / 4096;
    SPK.f_108 = SPK.f_120 - (SPK.vx << 12);
    SPK.f_10C = SPK.f_124 - (SPK.vy << 12);
    SPK.f_110 = SPK.f_128 - (SPK.vz << 12);
    SPK.f_114 = SPK.vx;
    SPK.f_11C = SPK.vz;
    SPK.f_118 = SPK.vy;
    SPK.lastX = SPK.x;
    SPK.lastY = SPK.y;
    SPK.lastZ = SPK.z;
    {
        AnimEnt_SU *at;
        if (SPK.state < 0x80) {
            at = D_800F4DE4_SU;
        } else {
            at = g_SpikeAnimSets_SU[SPK.gadget + 1].anims;
        }
        SCR->anims = at;
    }
    SCR->events = g_SpikeAnimSets_SU[SPK.gadget + 1].events;
    Spike_AnimEvents_SU(SCR->anims, g_SpikeAnimSets_SU[0].events);
    if (SPK.gadget != 9) {
        Spike_AnimEvents_SU(SCR->anims, SCR->events);
    }
    if (SPK.f_8C > 0xFFFD) {
        SPK.f_8C = 0;
    } else if (SPK.f_8C != 0) {
        SPK.f_8C--;
    }
    if (SPK.f_FE > 0) {
        SPK.f_FE--;
    }
    if (D_800F4DB0_SU.f_1E > 0) {
        D_800F4DB0_SU.f_1E--;
    }
    if (GAME.playMode == 0xA) {
        /* idle animation: any input ends it */
        if (PAD.sticks.both != 0 || (PAD.held & 0xFFF) || SPK.idle == 0) {
            Spike_SetPlayMode_SU(0);
            return;
        }
        SPK.idle--;
    }
}
#undef SPK
#undef PAD
#undef GAME
#undef SCR



typedef struct { s16 vx, vy, vz, pad; } SV_63628;
typedef struct { s32 vx, vy, vz, pad; } V_63628;
typedef struct { u8 pad0[4]; u16 f_4; u16 f_6; } Hdr_63628;
struct Spike_63628 { Hdr_63628 *f_0; u8 pad4[0x10]; void *f_14; u8 pad18[4]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x2C]; u16 f_5C; u16 f_5E; u16 f_60; u8 pad62[2]; u16 f_64; u8 pad66[2]; SV_63628 f_68; s32 f_70; u8 pad74[0xC]; SV_63628 f_80; u16 f_88; u16 f_8A; u16 f_8C; u8 pad8E[2]; s32 f_90; s32 f_94[8]; u8 padB4[0x2C]; s32 f_E0; u8 padE4[0x10]; u8 f_F4; u8 f_F5; u8 f_F6; u8 padF7; u8 f_F8; u8 f_F9; u8 f_FA; u8 padFB[3]; s16 f_FE; u8 pad100[2]; s16 f_102; s32 f_104; u8 pad108[0x24]; s32 f_12C; u8 pad130[6]; s16 f_136; u16 f_138; u8 pad13A[2]; u16 f_13C; };
typedef struct { u8 pad0[0x10]; SV_63628 f_10; V_63628 f_18; u8 pad28[0x3CC]; u8 f_3F4; } Scr_63628;
typedef struct { u8 pad0[0x32]; u8 f_32; u8 pad33[0x13]; u8 f_46; } Cam_63628;
typedef struct { u8 pad0[0x18]; s16 f_18; s16 f_1A; } Snd_63628;
typedef struct { u8 pad0[4]; s16 f_4; u8 pad6[2]; s32 f_8; } Gs_63628;
typedef struct { u8 pad0[0x1A]; u16 f_1A; u16 f_1C; } Dbg_63628;
typedef struct { u8 pad0[0xA2]; s8 f_A2; s8 f_A3; u8 padA4[0xB4]; u32 f_158; u8 pad15C[4]; u32 f_160; } Pad_63628;
typedef struct { Hdr_63628 *hdr; u8 pad4[0xC]; } Gm_63628;
extern struct Spike_63628 g_Spike_63628 asm("g_Spike");
extern struct { u8 pad0[0xC]; s32 cur; u8 pad10[0x70]; u8 ot[0x8150 - 0x80]; u16 f_8150; u8 pad8152[0x12A]; u32 f_827C; } g_Game_63628 asm("g_Game");
extern Pad_63628 g_Pad_63628 asm("g_Pad");
extern Cam_63628 D_800E68D0_63628 asm("g_CameraState");
extern u8 D_800E6902_63628 asm("D_800E6902");
extern u8 D_800E78C0_63628[] asm("g_ViewMatrix");
extern u8 D_800E7D00_63628[] asm("g_ProjVerts");
extern u8 D_800E9C60_63628[] asm("g_ModelMatrices");
extern u8 D_800E9E40_63628[] asm("D_800E9E40");
extern Gm_63628 D_800EC060_63628[] asm("g_GadgetModels");
extern u8 D_800EC0E0_63628[] asm("D_800EC0E0");
extern Dbg_63628 D_800F4B30_63628 asm("g_JointAngles");
extern s16 D_800F4DCE_63628 asm("D_800F4DCE");
extern Snd_63628 D_800F51D0_63628 asm("D_800F51D0");
extern s32 D_800F51E0_63628 asm("D_800F51E0");
extern s8 g_CurrentGadget_63628 asm("g_CurrentGadget");
extern Gs_63628 g_GadgetState_63628 asm("g_GadgetState");
extern s16 g_SpikeHealth_63628 asm("g_SpikeHealth");
void Anim_BlendFrameIndex_63628(void *, s32, s32, s32) asm("Anim_BlendFrameIndex");
void Anim_BlendFrames_63628(void *, s32, s32, s32) asm("Anim_BlendFrames");
void Anim_SetFrame_63628(void *) asm("Anim_SetFrame");
s32 func_80015240_63628(void *, s32) asm("Anim_GetFrame");
void Matrix_Copy_63628(void *, void *) asm("Matrix_Copy");
void Matrix_LookAt_63628(SV_63628 *, SV_63628 *, void *, s32) asm("Matrix_LookAt");
void func_800A3740_63628(void *, s32, s32) asm("memset");
s32 rsin_63628(s32) asm("rsin");
void ScaleMatrix_63628(void *, void *) asm("ScaleMatrix");
void func_80015504_63628(void *, s32) asm("Model_CalcJointMatrices");
void Model_ProjectBonedVerts_63628(void *) asm("Model_ProjectBonedVerts");
void SetRotMatrix_63628(void *) asm("SetRotMatrix");
void SetTransMatrix_63628(void *) asm("SetTransMatrix");
void Mesh_WaveVertices_63628(void *, s32, s32) asm("Mesh_WaveVertices");
void Model_CalcEnvMapUVs_63628(void *) asm("Model_CalcEnvMapUVs");
void func_8001CE54_63628(void *, void *, void *) asm("Model_DrawEnvMapped");
void Fx_DrawFadeRing_63628(SV_63628 *, s32, s32, s32) asm("Fx_DrawFadeRing");
void Light_SetColorMode_63628(s32, s32, s32, s32) asm("Light_SetColorMode");
s32 func_800463A4_63628(s32, s32, s32) asm("Math_StepToward");
void func_80017CD4_63628(void *, void *, void *) asm("Model_Draw");
s32 Spike_IsUnderwater_63628(void) asm("Spike_IsUnderwater");
void Model_ProjectVerts_63628(void *, void *, void *) asm("Model_ProjectVerts");
void WaterNet_Shoot_63628(void) asm("WaterNet_Shoot");
void WaterNet_UpdateShot_63628(void) asm("WaterNet_UpdateShot");
void Spike_UpdateGadgetLoopSound_63628(void) asm("Spike_UpdateGadgetLoopSound");
void Sound_Stop_63628(s32, s32) asm("Sound_Stop");
void Hoop_Update_63628(void) asm("Hoop_Update");
void Slingback_Update_63628(void) asm("Slingback_Update");
void TimeNet_Update_63628(void) asm("TimeNet_Update");
void StunClub_Update_63628(void) asm("StunClub_Update");
void func_80099C44_63628(void) asm("RcCar_DrawRemote");
void Club_SwingUpdate_63628(void) asm("Club_SwingUpdate");
void SkyFlyer_Update_63628(void) asm("SkyFlyer_Update");
void func_80099D70_63628(void) asm("Radar_Update");
void func_8005E000_63628(s32, s32) asm("Debug_CpuMark");
void Gadget_StopSounds_63628(s32, void *) asm("Gadget_StopSounds");
void Shadow_Draw_63628(void *, s32, s32, s32) asm("Shadow_Draw");
#define OT_63628 ((u8 *)&g_Game_63628 + g_Game_63628.cur * 0x4078 + 0x80)

/* Spike_Draw: per-frame Spike model update and draw. Steps the animation (blend modes by +0x8C),
 * builds the body matrix (look-at, or copied when +0xE0 bit 0), squashes it while +0xFE > 0, projects
 * the bones (wave-deformed at the water line), then draws Spike: env-mapped with a fade ring when
 * +0x102, otherwise lit with his colour easing towards the target (blinking while D_800F4DCE is
 * * odd). Underwater he holds the water net (R3 shoots); otherwise the held gadget is updated by
 * g_CurrentGadget (default: just draw its model). Ends with the CPU meter and his shadow. */
void Spike_Draw(void) {
    Scr_63628 *sc = (Scr_63628 *)0x1F800000;
    s32 sy;

    if (g_Game_63628.f_8150 == 0xC) {
        return;
    }
    if ((g_Spike_63628.f_70 & 0xF0) == 0x20 || g_Spike_63628.f_8C == 0xFFFF) {
        g_Spike_63628.f_88 = g_Spike_63628.f_5C + 1;
        Anim_BlendFrameIndex_63628(&g_Spike_63628, g_Spike_63628.f_5C, g_Spike_63628.f_88, g_Spike_63628.f_8A);
    } else if (g_Spike_63628.f_8C == 0xFFFE) {
        Anim_BlendFrameIndex_63628(&g_Spike_63628, g_Spike_63628.f_5C, g_Spike_63628.f_88, g_Spike_63628.f_8A);
    } else if (g_Spike_63628.f_8C != 0) {
        Anim_BlendFrames_63628(&g_Spike_63628, func_80015240_63628(&g_Spike_63628, g_Spike_63628.f_5C), g_Spike_63628.f_90, g_Spike_63628.f_8C * 0x333);
    } else {
        Anim_SetFrame_63628(&g_Spike_63628);
    }
    if (g_Spike_63628.f_E0 & 1) {
        Matrix_Copy_63628(g_Spike_63628.f_14, g_Spike_63628.f_94);
    } else {
        switch (g_Spike_63628.f_5E) {
        case 0x46:
        case 0x47:
        case 0x4C:
            Matrix_LookAt_63628(&g_Spike_63628.f_80, &g_Spike_63628.f_68, g_Spike_63628.f_14, 1);
            break;
        default:
            Matrix_LookAt_63628((SV_63628 *)&g_Spike_63628.f_60, &g_Spike_63628.f_68, g_Spike_63628.f_14, 0);
            break;
        }
    }
    if (g_Spike_63628.f_FE > 0) {
        V_63628 s = { 0x1000, 0x1000 - (g_Spike_63628.f_FE << 12) / 80 - rsin_63628(g_Spike_63628.f_FE * 300) * g_Spike_63628.f_FE / 240, 0x1000 };
        ScaleMatrix_63628(g_Spike_63628.f_14, &s);
    }
    if (D_800E6902_63628 == 1) {
        D_800F4B30_63628.f_1A -= g_Pad_63628.f_A2 * 4;
        D_800F4B30_63628.f_1C -= g_Pad_63628.f_A3 * 4;
    }
    func_80015504_63628(&g_Spike_63628, (g_Game_63628.f_8150 == 6) ? 7 : 3);
    Model_ProjectBonedVerts_63628(&g_Spike_63628);
    if ((g_Spike_63628.f_138 >> 12) == 1 && (g_Game_63628.f_827C >> 12) != 1) {
        sc->f_10.vx = g_Spike_63628.f_24;
        sc->f_10.vy = g_Spike_63628.f_13C;
        sc->f_10.vz = g_Spike_63628.f_2C;
        SetRotMatrix_63628(D_800E78C0_63628);
        SetTransMatrix_63628(D_800E78C0_63628);
        gte_ldv0(&sc->f_10);
        gte_rtps();
        __asm__ volatile ("mfc2 %0, $14" : "=r"(sy));
        Mesh_WaveVertices_63628(D_800E7D00_63628, g_Spike_63628.f_0->f_6, sy >> 16);
    }
    if (g_Spike_63628.f_102 != 0) {
        Model_CalcEnvMapUVs_63628(&g_Spike_63628);
        sc->f_3F4 = 2;
        func_8001CE54_63628(OT_63628, D_800E7D00_63628, &g_Spike_63628);
        {
            SV_63628 p = { g_Spike_63628.f_24, g_Spike_63628.f_28 - 0xC0, g_Spike_63628.f_2C };
            Fx_DrawFadeRing_63628(&p, 0x180, 1, 0x404040);
        }
    } else if (D_800E68D0_63628.f_32 != 1 && D_800E68D0_63628.f_46 != 1) {
        if (D_800F4DCE_63628 <= 0 || !(D_800F4DCE_63628 & 1)) {
            Light_SetColorMode_63628(2, g_Spike_63628.f_F4 * 16, g_Spike_63628.f_F5 * 16, g_Spike_63628.f_F6 * 16);
            if (*(s32 *)&g_Spike_63628.f_F4 != *(s32 *)&g_Spike_63628.f_F8) {
                g_Spike_63628.f_F4 = func_800463A4_63628(g_Spike_63628.f_F4, g_Spike_63628.f_F8, 4);
                g_Spike_63628.f_F5 = func_800463A4_63628(g_Spike_63628.f_F5, g_Spike_63628.f_F9, 4);
                g_Spike_63628.f_F6 = func_800463A4_63628(g_Spike_63628.f_F6, g_Spike_63628.f_FA, 4);
            }
            func_80017CD4_63628(OT_63628, D_800E7D00_63628, &g_Spike_63628);
            Light_SetColorMode_63628(3, 0, 0, 0);
        }
    }
    if (D_800E68D0_63628.f_32 == 1) {
        if (g_CurrentGadget_63628 == 4 && g_GadgetState_63628.f_4 == 1) {
            g_GadgetState_63628.f_4 = 0;
            g_GadgetState_63628.f_8 = 0;
            Gadget_StopSounds_63628(4, &g_GadgetState_63628);
        }
    } else if (Spike_IsUnderwater_63628() != 0) {
        Model_ProjectVerts_63628(D_800EC0E0_63628, D_800E9E40_63628, D_800E7D00_63628);
        func_80017CD4_63628(OT_63628, D_800E7D00_63628, D_800EC0E0_63628);
        if (D_800E68D0_63628.f_32 != 1 && (g_Pad_63628.f_158 & g_Pad_63628.f_160 & PAD_R3) && g_SpikeHealth_63628 > 0 && D_800F51E0_63628 == 0) {
            WaterNet_Shoot_63628();
        }
        if (D_800F51E0_63628 > 0) {
            WaterNet_UpdateShot_63628();
        }
        Spike_UpdateGadgetLoopSound_63628();
    } else {
        if (D_800F51D0_63628.f_18 != -1) {
            Sound_Stop_63628(D_800F51D0_63628.f_1A, D_800F51D0_63628.f_18);
            D_800F51D0_63628.f_18 = -1;
            D_800F51D0_63628.f_1A = -1;
        }
        switch (g_CurrentGadget_63628) {
        case 8:
        default: {
            Gm_63628 *g = &D_800EC060_63628[g_CurrentGadget_63628];
            Model_ProjectVerts_63628(g, D_800E9C60_63628 + (g->hdr->f_4 << 5), D_800E7D00_63628);
            func_80017CD4_63628(OT_63628, D_800E7D00_63628, g);
            break;
        }
        case 4:
            Hoop_Update_63628();
            break;
        case 3:
            Slingback_Update_63628();
            break;
        case 1:
            TimeNet_Update_63628();
            break;
        case 0:
            StunClub_Update_63628();
            break;
        case 7:
            func_80099C44_63628();
            break;
        case 5:
            Club_SwingUpdate_63628();
            break;
        case 6:
            SkyFlyer_Update_63628();
            break;
        case 2:
            func_80099D70_63628();
            break;
        case 9:
            break;
        }
    }
    func_8005E000_63628(1, 0xFFFFFF);
    sc->f_18.vx = g_Spike_63628.f_1C;
    sc->f_18.vy = g_Spike_63628.f_1E;
    sc->f_18.vz = g_Spike_63628.f_20;
    if ((u16)(g_Spike_63628.f_5E - 0xE) < 2) {
        sc->f_18.vx -= (s16)g_Spike_63628.f_60 >> 8;
        sc->f_18.vz -= (s16)g_Spike_63628.f_64 >> 8;
    }
    if (D_800E68D0_63628.f_32 != 1 && D_800E68D0_63628.f_46 != 1 && g_Spike_63628.f_136 != 0) {
        Shadow_Draw_63628(&sc->f_18, g_Spike_63628.f_12C, 0x54, g_Spike_63628.f_104);
    }
}



/* Ledge grab: while Spike has health (+0xE8 > 0) and is falling (+0x34 > 0) above the floor,
 * checks one step ahead in his facing direction (snapped to 8 directions). If the floor there
 * (Floor_GetHeightAndSlope) is 0x81..0xFF above him, is not a blocked surface (scratchpad 0x1F8003F0
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
    h = (s16)Floor_GetHeightAndSlope((*(Sp_80063EC4_80063EC4 *)&g_Spike).x + dir.vx / 32, (*(Sp_80063EC4_80063EC4 *)&g_Spike).y - 0x100, (*(Sp_80063EC4_80063EC4 *)&g_Spike).z + dir.vz / 32, &(*(Sp_80063EC4_80063EC4 *)&g_Spike).f_104);
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
        SP_64208->f_90 = Anim_GetFrame(&(*(M2C_UNK *)&g_Spike), SP_64208->frame);
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

typedef struct { s16 vx, vy, vz, pad; } SV_80064454;
typedef struct { s32 x, y, z; u8 padC[0xC]; SV_80064454 dir; s16 f_20; s16 pad22; s16 f_24; s16 f_26; } Col_80064454;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u16 state; SV_80064454 f_60; u8 pad68[0x22]; u16 f_8A; u8 pad8C[0x5C]; s16 f_E8; } Sp_80064454;
typedef struct { u8 pad0[0x60]; s16 f_60; s16 f_62; s16 f_64; } GS_80064454;
typedef struct { s8 dx, dy, dz, r; u8 yaw; u8 pitch; u8 pad6[2]; u16 f_8; u16 f_A; } Arg_80064454;
extern struct S_AE_64454 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike_64454 asm("g_Spike");
extern struct { u8 pad0[0x152]; u16 f_152; } D_800F4350_64454 asm("D_800F4350");
extern u8 g_GadgetState_64454[] asm("g_GadgetState");
extern u8 g_JointWorldMatrices[];
extern void (*Spike_AnimFxCallbacks[])(void);
extern void (*Spike_Actions[])(void);
void Sound_PlayFixed_AE(s32) asm("Sound_PlayFixed");
Col_80064454 *CollShape_Alloc(void);
s32 Collision_Set(s32, void *, void *);
void ApplyMatrixSV_64454(void *, void *, void *) asm("ApplyMatrixSV");
s32 rsin(s32);
void MagicPunch_AddHitSpheres(SV_80064454 *, s32, s32, s32);
typedef struct { u8 st; u8 fr; u8 type; u8 arg; } Ev_80064454;

void Spike_AnimEvents(Anim_80064208_80064208 *tbl, u8 *script)
{
  SV_80064454 v;
  s32 i;
  Ev_80064454 *r;
  Arg_80064454 *a;
  Ev_80064454 **new_var;
  Col_80064454 *c;
  Col_80064454 *d;
  s32 s;
  s32 st;
  Sp_80064454 *sp;
  struct { u8 pad0[0x152]; u16 f_152; } *dd;
  GS_80064454 *gs;
  sp = (Sp_80064454 *)&g_Spike_64454;
  dd = (void *)&D_800F4350_64454;
  gs = (GS_80064454 *)g_GadgetState_64454;
  r = (Ev_80064454 *) script;
  i = 4;
  __asm__ ("" :: "r"(sp), "r"(dd), "r"(gs));
  __asm__ ("" :: "r"(i), "r"(i), "r"(i), "r"(i), "r"(i), "r"(i), "r"(i), "r"(i), "r"(i));
  __asm__ ("" :: "r"(i), "r"(i), "r"(i), "r"(i), "r"(i), "r"(i));
  __asm__ ("" :: "r"(script), "r"(script), "r"(script), "r"(script), "r"(script), "r"(script));
  while (1)
  {
    __asm__ ("" :: "r"(r));
    __asm__ ("" :: "r"(r));
    __asm__ ("" :: "r"(r));
    __asm__ ("" :: "r"(r));
    sp = (Sp_80064454 *)&g_Spike_64454; dd = (void *)&D_800F4350_64454; gs = (GS_80064454 *)g_GadgetState_64454;
    st = r->st;
    if (st == 0xFF)
    {
      break;
    }
    if (((st == sp->state) && ((r->fr + tbl[st % 128].start) == sp->frame)) && (sp->f_8A == 0))
    {
      switch (r->type)
      {
        case 1:
          Sound_PlayFixed_AE(r->arg);
          break;

        case 8:
          Spike_PlayVoice(r->arg);
          break;

        case 2:
          c = CollShape_Alloc();
          if (c != 0)
        {
          a = (Arg_80064454 *) (script + i);
          v.vx = a->dx * 8;
          v.vy = a->dy * 8;
          v.vz = a->dz * 8;
          ApplyMatrixSV_64454(g_JointWorldMatrices, &v, &v);
          c->x = sp->x + v.vx;
          c->y = sp->y + v.vy;
          c->z = sp->z + v.vz;
          c->f_20 = a->r * 8;
          s = rsin(a->yaw << 4);
          v.vx = (s * rcos(a->pitch << 4)) / 4096;
          v.vy = rsin(a->pitch << 4);
          s = rcos(a->yaw << 4);
          { s32 cp = rcos(a->pitch << 4); __asm__ volatile(""); s = -s; v.vz = (s * cp) / 4096; }
          ApplyMatrixSV_64454(g_JointWorldMatrices, &v, &c->dir);
          c->f_24 = a->f_8;
          c->f_26 = a->f_A;
          Collision_Set(6, c, sp);
        }
          break;

        case 3: {
          if ((dd->f_152 != 0xB) && (sp->f_E8 > 0))
        {
          Col_80064454 *c;
          Arg_80064454 *a;
          c = CollShape_Alloc();
          if (c != 0)
          {
            a = (Arg_80064454 *) (script + i);
            c->dir = sp->f_60;
            v.vx = a->dx * 8;
            v.vy = a->dy * 8;
            v.vz = a->dz * 8;
            ApplyMatrixSV_64454(g_JointWorldMatrices, &v, &v);
            c->x = sp->x + v.vx;
            c->y = sp->y + v.vy;
            c->z = sp->z + v.vz;
            c->f_20 = a->r * 8;
            Collision_Set(8, c, sp);
            c->f_24 = 0x100;
            c->f_26 = 0;
          }
        }
          break;

        } case 7:
          if ((dd->f_152 != 0xB) && (sp->f_E8 > 0))
        {
          d = CollShape_Alloc();
          if (d != 0)
          {
            d->dir = sp->f_60;
            d->x = gs->f_60;
            d->y = gs->f_62;
            d->z = gs->f_64;
            d->f_20 = ((Arg_80064454 *) (script + i))->r * 8;
            Collision_Set(8, d, sp);
            d->f_24 = 0x100;
            d->f_26 = 0;
          }
        }
          break;

        case 4:
          Spike_AnimFxCallbacks[r->arg]();
          break;

        case 5:
          Spike_Actions[r->arg]();
          break;

        case 6:
          a = (Arg_80064454 *) (script + i);
          s = rsin(a->yaw << 4);
          v.vx = (s * rcos(a->pitch << 4)) / 4096;
          v.vy = rsin(a->pitch << 4);
          s = rcos(a->yaw << 4);
          { s32 cp = rcos(a->pitch << 4); __asm__ volatile(""); s = -s; v.vz = (s * cp) / 4096; }
          MagicPunch_AddHitSpheres(&v, a->r * 8, a->f_8, a->f_A);
          break;

      }

    }
    switch ((*(new_var = &r))->type)
    {
      case 2:

      case 6:
        r += 4;
        i += 0x10;
        break;

      case 3:

      case 7:
        r += 2;
        i += 8;
        break;

      default:
        r += 1;
        i += 4;
        break;

    }

  }

}



typedef struct { u8 f_0; s8 f_1; u8 f_2; u8 f_3; } E_800649D8;
extern s32 (*Spike_Conditions[])(void);
extern void (*Spike_Actions[])(void);
void Spike_SetState(s32);

void Spike_CheckTransitions(void *arg) {
    register E_800649D8 *tbl asm("$21") = arg;
    s32 i = 0;
    s32 k = D_800EC23E;
    E_800649D8 *e;
    while (1) {
        e = (E_800649D8 *)((i << 2) + (s32)tbl);
        if (e->f_0 > k) {
            return;
        }
        if (e->f_0 == k) goto match;
next:
        i++;
        continue;
match:
        if (e->f_1 > 0) {
            if (Spike_Conditions[e->f_1]() == 0) goto next;
        } else if (Spike_Conditions[-e->f_1]() != 0) {
            goto next;
        }
        Spike_SetState(e->f_2);
        if (e->f_3 != 0) {
            Spike_Actions[e->f_3]();
        }
        return;
    }
}

s32 SpikeCond_Never(void) {
    return 0;
}

s32 SpikeCond_HeldR1R2(void) {
    return *(s32 *)0x1F800054 & 0xA;
}

s32 SpikeCond_PressedR1R2(void) {
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
        if ((*(S_E5320_80064B24 *)&g_Pad).f_A4[(idx + PAD_HISTORY_LEN - i) % PAD_HISTORY_LEN] == PAD_R2) {
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
    if (((struct S_D_800E5320_80064BBC *)&g_Pad)->f_A4[((new_var + PAD_HISTORY_LEN) - i) % PAD_HISTORY_LEN] == PAD_CROSS)
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

s32 SpikeCond_MovingForward(void) {
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

s32 SpikeCond_KnockbackDone(void) {
    u16 temp_v0;

    temp_v0 = g_Spike.f_DE - 1;
    g_Spike.f_DE = temp_v0;
    return (temp_v0 << 0x10) == 0;
}

s32 SpikeCond_FloorAhead(void) {
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

s32 SpikeCond_RandomAnimEnd(void) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = (g_RandSeed * 5) + 1;
    g_RandSeed = temp_v0;
    var_a1 = 0;
    if ((temp_v0 >> 8) & 1) {
        var_a1 = SpikeCond_AnimEnded() != 0;
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
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + PAD_HISTORY_LEN - i) % PAD_HISTORY_LEN] == PAD_L1) {
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
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + PAD_HISTORY_LEN - i) % PAD_HISTORY_LEN] == PAD_R1) {
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

s32 SpikeCond_NoStickR(void) {
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

s32 SpikeCond_NoStickL(void) {
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
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + PAD_HISTORY_LEN - i) % PAD_HISTORY_LEN] == PAD_TRIANGLE) {
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
        if (g_Pad.f_A4[(u32)(g_Pad.f_170 + PAD_HISTORY_LEN - i) % PAD_HISTORY_LEN] == PAD_CIRCLE) {
            return 1;
        }
    }
    return 0;
}

/* 1 when Spike's animation frame (+0x5C) is one past the last frame of his current animation
 * (+0x5E & 0x7F in the table at *0x1F800048) and the latest entry of the button-press history
 * (g_Pad+0xA4, index +0x170) is Triangle (0x10). */
s32 Spike_AnimEndOnTriangle(void) {
    if (G_SPIKE_800655C4->f_5C == (*(S_1F800048_800655C4 **)0x1F800048)[G_SPIKE_800655C4->f_5E & 0x7F].f_0 + 1 && G_PAD_800655C4->f_A4[G_PAD_800655C4->f_170] == PAD_TRIANGLE) {
        return 1;
    }
    return 0;
}

/* 1 when Spike's animation frame (+0x5C) is one past the last frame of his current animation
 * (+0x5E & 0x7F in the table at *0x1F800048) and the latest entry of the button-press history
 * (g_Pad+0xA4, index +0x170) is Circle (0x20). */
s32 Spike_AnimEndOnCircle(void) {
    if (G_SPIKE_800655C4->f_5C == (*(S_1F800048_800655C4 **)0x1F800048)[G_SPIKE_800655C4->f_5E & 0x7F].f_0 + 1 && G_PAD_800655C4->f_A4[G_PAD_800655C4->f_170] == PAD_CIRCLE) {
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
            Spike_FxBump();
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
 * camera if it is on (D_800E6916 == 1) and, for gadget slot +0xF2 == 2, calls Radar_ResetScan.
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
        Radar_ResetScan();
    }
    return 1;
    }
    return 0;
}

s32 SpikeCond_InWater(void) {
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

s32 SpikeCond_JumpOutOfWater(void)
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
    if (SpikeCond_PressedR1R2() == 0) {
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

s32 SpikeCond_OutOfHealth(void)
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

s32 SpikeCond_AnimEnded(void)
{
  int new_var;
  new_var = ((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_8A != 0;
  return (*((S_1F800048_80065B6C **) 0x1F800048))[((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_5E & 0x7F].f_2 < (((struct S_D_800EC1E0_80065B6C *)&g_Spike)->f_5C + new_var);
}

s32 SpikeCond_Never2(void) {
    return 0;
}

s32 SpikeCond_Still(void)
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

void Spike_StartJump(void)
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

void Spike_JumpHoldLift(void) {
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

void SkyFlyer_StartLift(void) {
    g_Spike.f_100 = 0;
    g_Spike.f_124 = 0;
    Pad_Vibrate(1, 0xFF, 0x14);
}

void SkyFlyer_UpdateLift(void) {
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

void Spike_EnterSwimIfInWater(void) {
    if (((u16) D_800EC318 >> 0xC) == 1) {
        Spike_SetState(0x49);
    }
}

void Spike_FireSlingback(void) {
    Slingback_Fire();
}

void Spike_PushForward(void) {
    g_Spike.f_108 = (s32) (g_Spike.f_108 + (g_Spike.f_60 << 5));
    g_Spike.f_110 = (s32) (g_Spike.f_110 + (g_Spike.f_64 << 5));
}

void func_8006611C(void) {
    s16 *sp = (s16 *)0x1F800000;

    sp[5] = 0;
    sp[4] = -sp[0];
    sp[6] = -sp[2];
}

void Spike_TurnAround(void) {
    g_Spike.f_8C = 0;
    g_Spike.f_60 = -g_Spike.f_60;
    g_Spike.f_64 = -g_Spike.f_64;
}

void Spike_TurnAroundAndJump(void) {
    Spike_TurnAround();
    Spike_StartJump();
}

void Spike_ActionNop(void) {
}

void Spike_SetMoveDirFromStick(void) {
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
    Spike_SetMoveDirFromStick();
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
    Spike_SetMoveDirFromStick();
    if (*(u16 *)0x1F800062 & 4) {
        D_800EC26E = 0x800;
    }
}

void func_80066530(void) {
    Spike_SetMoveDirFromStick();
    ApplyMatrixSV(&D_800AE760, &D_800EC254, &D_800EC254);
}

void func_80066568(void) {
    Spike_SetMoveDirFromStick();
    ApplyMatrixSV(&D_800AE740, &D_800EC254, &D_800EC254);
}

void Spike_EnterAim(void) {
    Camera_EnterAim();
}

void Spike_ExitAim(void) {
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

void Spike_BounceUp(void) {
    g_Spike.f_124 = (s32) ((s32) -g_Spike.f_118 / 2);
}

void func_80066744(void) {
    D_800F5164 = 5;
    Spike_PlayVoice(2);
}

/* Probably Spike's landing handler (only reached through a pointer). With a fall counter +0xFC
   of 6 or more he takes 1 damage, the pad rumbles, he goes to state 0x18 (from state 0x45) or 0x4B
   with +0xFE = 60, and sound 0x43 plays; otherwise a light rumble and sound 0x42 (state 0x45) or
   0x13/0x12 depending on the vertical speed +0x34. Always sets flag 0x4000000 in +0xE0. */
void Spike_Land(void) {
    S_EC1E0_80066770_80066770 *s = (S_EC1E0_80066770_80066770 *)&(*(M2C_UNK *)&g_Spike);
    if (s->f_5E == 0x45) {
        Spike_GroundBlast();
        if (s->f_FC >= 6) {
            Spike_TakeDamage(1);
            Pad_Vibrate(1, 0xF0, 8);
            Spike_SetState(0x18);
            Spike_PlayVoice(9);
            Sound_PlayFixed(0x43);
        } else {
            Pad_Vibrate(0, 1, 2);
            Sound_PlayFixed(0x42);
        }
    } else if (s->f_FC >= 6) {
        Spike_TakeDamage(1);
        Pad_Vibrate(1, 0xF0, 8);
        s->f_FE = 0x3C;
        Spike_GroundBlast();
        Spike_SetState(0x4B);
        Spike_PlayVoice(9);
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

s32 Spike_ClampMoveStepXZ(s32 n) {
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

void Dir_TurnTowardMax(SVEC_80066C90 *a, SVEC_80066C90 *b, s32 ang)
{
  s32 r;
  if ((((a->vx * b->vx) + (a->vz * b->vz)) >> 12) < rcos(ang))
  {
    Matrix_SetIdentity((MATRIX_80066C90 *) 0x1F800028);
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

void Spike_SetClimbPole(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
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

void Spike_SetHangBar(s16 *a, s16 *b) {
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
void Spike_FxKnockback(void);
/* Spike_StartKnockback: store the 6-byte knockback vector p and duration a, set the knockback flag
 * (f_E0 bit 3) and spawn the hit effect 0x116 (Spike_FxKnockback). */
void Spike_StartKnockback(s32 *p, s16 a) {
    s32 *d = &SP_KB->f_D8;
    s32 x = p[0];
    u16 y = *(u16 *)&p[1];
    d[0] = x;
    SP_KB->f_DE = a;
    *(u16 *)&(&SP_KB->f_D8)[1] = y;
    SP_KB->f_E0 |= 8;
    Spike_FxKnockback();
}

void func_80066F34(void) {
    g_Spike.f_E0 = (s32) (g_Spike.f_E0 | 0x40);
}

s32 Spike_CanUseRadarView(void) {
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

typedef struct { s16 vx, vy, vz, pad; } SV_67000;
typedef struct { s32 vx, vy, vz, pad; } V_67000;
typedef struct { u8 pad0[8]; SV_67000 n1; SV_67000 n; V_67000 d; } Scr_67000;
typedef struct { s32 x, y, z; u8 padC[0x18]; u16 f_24; u16 f_26; } Col_67000;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x20]; u32 f_50; u8 pad54[0xA]; u16 state; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0xA]; s32 f_70; u8 pad74[0x74]; s16 f_E8; s16 f_EA; u8 padEC[3]; u8 f_EF; u8 f_F0; u8 f_F1; u8 padF2[0xC]; s16 f_FE; u8 pad100[8]; s32 f_108; s32 f_10C; s32 f_110; s32 f_114; s32 f_118; s32 f_11C; s32 f_120; s32 f_124; s32 f_128; s32 f_12C; u8 pad130[8]; u16 f_138; } Sp_67000;
typedef struct { u8 pad0[0x32]; u8 f_32; u8 pad33[5]; u8 f_38; u8 pad39[0xD]; u8 f_46; } Cam_67000;
typedef struct { u16 spd; u16 ang; } KB_67000;
extern u8 g_CameraState[];
extern u8 D_800EC2CF;
extern s32 D_800B0264[];
extern KB_67000 D_800B0250[];
#define SP_67000 ((Sp_67000 *)&g_Spike)
Col_67000 *Collision_GetShape(s32);
void VectorNormalS(void *, void *);
void Camera_ExitRadarLive(void);
void Spike_FxHit(void);
void Spike_StartDamageEffect(s32);
void Spike_FxDripBurst(void);
s32 rsin(s32);
void Camera_StartShake(s32);

s32 Spike_HandleHit(void) {
    Col_67000 *c;
    Cam_67000 *cam;
    u32 k;
    s32 t;
    u16 kind;
    u16 dmg;
    s32 sp;
    s32 a;
    s32 st;
    u32 idx;
    s32 m;
    s32 e;
    Scr_67000 *SC = (Scr_67000 *)0x1F800000;

    t = SP_67000->f_EA - 1;
    if (t >= 0) {
        e = 0x96;
        if (t < 0x97) {
            e = t;
        }
    } else {
        e = 0;
    }
    SP_67000->f_EA = e;
    if (SP_67000->state == 0x4D) {
        if (--SP_67000->f_F1 == 0) {
            SP_67000->f_124 = 0xFFF80000;
            Spike_SetState(0x2B);
            Spike_PlayVoice(0xB);
            Spike_GroundBlast();
        }
        return 0;
    }
    if ((SP_67000->f_70 & 0xF0) == 0xD0 || SP_67000->state == 0x4C || SP_67000->state == 0x22 || D_800F4DCE > 0) {
        SP_67000->f_F0 = 0;
        return 0;
    }
    if (g_Game.f_8150 == 10) {
        k = SP_67000->f_50 >> 28;
        if (k >= 4 && (k < 6 || k == 0xB)) {
            Spike_SetPlayMode(0);
        }
    }
    if (SP_67000->f_E8 <= 0) {
        return 0;
    }
    switch (SP_67000->f_50 >> 28) {
    default:
        SP_67000->f_F0 = 0;
        return 0;
    case 4:
    case 5:
        if ((SP_67000->f_138 >> 12) == 1) {
            return 0;
        }
        if (SP_67000->f_12C < SP_67000->y + 0x20) {
            return 0;
        }
        c = Collision_GetShape(*(u16 *)&SP_67000->f_50 & 0xFFF);
        SC->d.vx = c->x - SP_67000->x;
        SC->d.vy = 0;
        SC->d.vz = c->z - SP_67000->z;
        VectorNormalS(&SC->d, &SC->n1);
        SP_67000->f_10C = 0;
        SP_67000->f_108 = -(SC->n1.vx * 8);
        SP_67000->f_110 = -(SC->n1.vz * 8);
        if (SP_67000->state == 0x24) {
            break;
        }
        SP_67000->f_124 = 0;
        Spike_SetState(0x24);
        return 0;
    case 0xB:
        c = Collision_GetShape(*(u16 *)&SP_67000->f_50 & 0xFFF);
        cam = (Cam_67000 *)g_CameraState;
        kind = c->f_26;
        dmg = c->f_24;
        if (cam->f_38 == 1) {
            Camera_ExitRadarLive();
        }
        if (cam->f_46 == 1) {
            Camera_ExitAim();
        }
        if (cam->f_32 == 1) {
            Camera_ExitLook();
        }
        switch (dmg & 0xFF00) {
        case 0x600:
            Spike_SetState(0x2F);
            Sound_PlayFixed(0x4A);
            Pad_Vibrate(0, 1, 5);
            goto ret1;
        case 0xA00:
            if ((SP_67000->f_70 & 0xF0) == 0xD0 || SP_67000->state == 0x4C) {
                goto ret1;
            }
            SP_67000->f_FE = 60;
            Spike_TakeDamage(1);
            Pad_Vibrate(1, 0xF0, 5);
            switch (g_Game.f_8150) {
            case 6:
                if (SP_67000->f_E8 <= 0) {
                    func_80066434();
                }
                goto common;
            case 5:
                if (SP_67000->f_E8 <= 0) {
                    Spike_BounceBack();
                }
            common:
                func_80066018();
                Spike_PlayVoice(8);
                goto ret1;
            }
            Spike_GroundBlast();
            Spike_SetState(0x4B);
            Sound_PlayFixed(0x42);
            Spike_PlayVoice(9);
            __asm__ volatile("");
            goto ret1;
        case 0xB00:
            Spike_SetPlayMode(7);
            goto ret1;
        }
        if ((kind & 0x3FFF) != 0x100) {
            Spike_FxHit();
        }
        if (SP_67000->f_F0 == 0) {
            Spike_TakeDamage(dmg & 0xF);
        }
        st = SP_67000->state;
        if (st < 0x1D) {
            if (st >= 0x1B) {
                if (SP_67000->f_EF++ >= 6) {
                    kind = 0x202;
                }
            } else {
                D_800EC2CF = 0;
            }
        } else {
            D_800EC2CF = 0;
        }
        switch (dmg & 0xFF00) {
        case 0x300:
            Spike_StartDamageEffect(1);
            Spike_PlayVoice(0xB);
            Sound_PlayFixed(0x34);
            break;
        case 0x200:
            Spike_StartDamageEffect(2);
            Spike_PlayVoice(0xB);
            Sound_PlayFixed(0x33);
            break;
        case 0x400:
            Spike_StartDamageEffect(3);
            Sound_PlayFixed(0x35);
            break;
        }
        SC->d.vx = c->x - SP_67000->x;
        SC->d.vy = 0;
        SC->d.vz = c->z - SP_67000->z;
        if (SC->d.vx != 0 || SC->d.vz != 0) {
            VectorNormalS(&SC->d, &SC->n);
        }
        switch (g_Game.f_8150) {
        case 6:
            if (SP_67000->f_E8 <= 0) {
                func_80066434();
            }
            func_80066018();
            Spike_PlayVoice(8);
            Pad_Vibrate(1, 0xF0, 5);
            Camera_StartShake(0);
            goto ret1;
        case 5:
            if (SP_67000->f_E8 <= 0) {
                Spike_BounceBack();
            }
            func_80066018();
            Spike_PlayVoice(8);
            Pad_Vibrate(1, 0xF0, 5);
            Camera_StartShake(0);
            goto ret1;
        }
        switch (kind & 0x3F00) {
        case 0x100:
            m = D_800B0264[idx = kind & 0xFF];
            if ((SP_67000->f_70 & 0xF0) == 0xC0) {
                Spike_SetState(0x4C);
                Spike_FxDripBurst();
                SP_67000->f_120 = SP_67000->f_114 = -(SC->n.vx * 16);
                SP_67000->f_128 = SP_67000->f_11C = -(SC->n.vz * 16);
                func_80066018();
                if (dmg & 0xF) {
                    Spike_PlayVoice(8);
                }
            } else {
                if (idx < 2) {
                    Spike_SetState(0x1C);
                } else {
                    Spike_SetState(0x1B);
                    Spike_PlayVoice(8);
                }
                SP_67000->f_120 = SP_67000->f_114 = -SC->n.vx * m;
                SP_67000->f_128 = SP_67000->f_11C = -SC->n.vz * m;
            }
            SP_67000->f_60 = SC->n.vx;
            SP_67000->f_64 = SC->n.vz;
            if (m == 0) {
                Sound_PlayFixed(0x5B);
            }
            break;
        case 0x400:
            sp = D_800B0250[kind & 0xFF].spd;
            a = D_800B0250[kind & 0xFF].ang;
            SP_67000->f_114 = -(SC->n.vx * rcos(a) / 4096) * sp;
            SP_67000->f_11C = -(SC->n.vz * rcos(a) / 4096) * sp;
            SP_67000->f_124 = SP_67000->f_118 = -sp * rsin(a);
            SP_67000->f_120 = SP_67000->f_114;
            SP_67000->f_128 = SP_67000->f_11C;
            SP_67000->f_60 = -SC->n.vx;
            SP_67000->f_64 = -SC->n.vz;
            Spike_SetState(0x2B);
            Sound_PlayFixed(0x5F);
            break;
        default:
            if ((SP_67000->f_70 & 0xF0) == 0xC0) {
                Spike_SetState(0x4C);
                Spike_FxDripBurst();
                SP_67000->f_120 = SP_67000->f_114 = -(SC->n.vx * 16);
                SP_67000->f_128 = SP_67000->f_11C = -(SC->n.vz * 16);
                func_80066018();
            } else {
                sp = D_800B0250[kind & 0xFF].spd;
                a = D_800B0250[kind & 0xFF].ang;
                SP_67000->f_114 = -(SC->n.vx * rcos(a) / 4096) * sp;
                SP_67000->f_11C = -(SC->n.vz * rcos(a) / 4096) * sp;
                SP_67000->f_124 = SP_67000->f_118 = -sp * rsin(a);
                SP_67000->f_120 = SP_67000->f_114;
                SP_67000->f_128 = SP_67000->f_11C;
                SP_67000->f_60 = SC->n.vx;
                SP_67000->f_64 = SC->n.vz;
                Spike_SetState(0x1D);
                Sound_PlayFixed(0x5F);
            }
            Spike_PlayVoice(9);
            break;
        }
        Pad_Vibrate(1, 0xF0, 5);
        Camera_StartShake(0);
    ret1:
        return 1;
    }
    return 0;
}

/* Gadget selection: maps newly pressed face buttons (Triangle, Square, Circle,
 * Cross) to the four gadget slots and switches to that slot's gadget.
 */
typedef struct { u8 pad0[0x88]; s8 slots[4]; } GadgetSlots_800679A0;
s32 Gadget_Select(s32 g, s32 prev);

/* The first exit is a bare `return;` in the original, leaving v0 as Spike_CanUseRadarView's 0. */
s32 Gadget_SelectFromButtons(void) {
    u8 *spad = (u8 *)0x1F800000;
    s32 b;
    s32 slot;
    s32 cur;
    if (Spike_CanUseRadarView() == 0) {
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
    Spike_CheckTransitions(g_SpikeAnimSets[0].f_8);
    Spike_CheckTransitions(sc->f_4C);
    if (sc->f_80 == 0) {
        if (((struct S_D_800E5320_80067CAC *)&g_Pad)->sx >= 0x79) {
            ApplyMatrixSV(D_800AE7A0, &SP->f_74, &SP->f_74);
        }
        if (((struct S_D_800E5320_80067CAC *)&g_Pad)->sx < -0x78) {
            ApplyMatrixSV(D_800AE780, &SP->f_74, &SP->f_74);
        }
    }
    Dir_TurnTowardMax(&SP->f_74, &SP->f_60, 0x155);
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

INCLUDE_RODATA("asm/nonmatchings/game/80060780_spike", jtbl_800A5B70_pad);


typedef struct { s16 vx, vy, vz, pad; } SV_681E4;
typedef struct { s32 a, b; } W2_681E4;
typedef struct { u8 pad0[0x14]; s32 f_14; s32 f_18; s32 f_1C; } Body_681E4;
typedef struct {
    u8 pad0[0x14]; Body_681E4 *f_14; u8 pad18[0xC]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x2C];
    u16 f_5C; u16 f_5E; SV_681E4 f_60; u8 pad68[0xC]; SV_681E4 f_74; u8 pad7C[0x44];
    s16 f_C0; s16 f_C2; s16 f_C4; s16 f_C6; s16 f_C8; s16 f_CA; s16 f_CC; s16 f_CE; s16 f_D0; s16 f_D2; s16 f_D4;
    u8 padD6[0xA]; u32 f_E0; u8 padE4[0xE]; s8 f_F2; u8 padF3[0x25]; s32 f_118; u8 pad11C[4]; s32 f_120; s32 f_124; s32 f_128;
} Sp_681E4;
typedef struct { void *f_0; void *f_4; void *f_8; void *f_C; } AnimSet_681E4;
typedef struct { u8 pad0[0x48]; void *f_48; void *f_4C; void *f_50; u32 f_54; u32 f_58; u8 pad5C[8]; u16 f_64; u8 pad66[0x1A]; s32 f_80; } Spad_681E4;
typedef struct { u8 pad0[0x180]; u16 f_180; u8 pad182[0x12]; SV_681E4 f_194; } Pad_681E4;
extern Sp_681E4 g_Spike_681E4 asm("g_Spike");
extern AnimSet_681E4 g_SpikeAnimSets_681E4[] asm("g_SpikeAnimSets");
extern Pad_681E4 g_Pad_681E4 asm("g_Pad");
extern u16 D_800E5498;
void func_80066C90_681E4(SV_681E4 *a, SV_681E4 *b, s32 ang) asm("Dir_TurnTowardMax");

void Spike_StateHangBar(void) {
    Spad_681E4 *sp = (Spad_681E4 *)0x1F800000;
    void *anim;
    s32 w;
    s32 iw;
    s32 v;
    s32 d;
    s16 t;
    Sp_681E4 *p;

    if (g_Spike_681E4.f_5E < 0x80) {
        anim = g_SpikeAnimSets_681E4[0].f_4;
    } else {
        anim = g_SpikeAnimSets_681E4[g_Spike_681E4.f_F2 + 1].f_4;
    }
    sp->f_48 = anim;
    sp->f_4C = g_SpikeAnimSets_681E4[g_Spike_681E4.f_F2 + 1].f_8;
    sp->f_50 = g_SpikeAnimSets_681E4[g_Spike_681E4.f_F2 + 1].f_C;
    g_Spike_681E4.f_128 = 0;
    g_Spike_681E4.f_120 = 0;
    g_Spike_681E4.f_124 = 0;
    v = (g_Spike_681E4.f_C0 * g_Spike_681E4.f_CC + g_Spike_681E4.f_C6 * (0x1000 - g_Spike_681E4.f_CC)) / 4096;
    if (g_Spike_681E4.f_24 != v) {
        g_Spike_681E4.f_24 = (g_Spike_681E4.f_24 + v) / 2;
    }
    v = (g_Spike_681E4.f_C2 * g_Spike_681E4.f_CC + g_Spike_681E4.f_C8 * (0x1000 - g_Spike_681E4.f_CC)) / 4096;
    if (g_Spike_681E4.f_28 != v) {
        g_Spike_681E4.f_28 = (g_Spike_681E4.f_28 + v) / 2;
    }
    v = (g_Spike_681E4.f_C4 * g_Spike_681E4.f_CC + g_Spike_681E4.f_CA * (0x1000 - g_Spike_681E4.f_CC)) / 4096;
    if (g_Spike_681E4.f_2C != v) {
        g_Spike_681E4.f_2C = (g_Spike_681E4.f_2C + v) / 2;
    }
    g_Spike_681E4.f_5C++;
    if (D_800E6916 == 1) {
        Camera_ExitAim();
    }
    if (sp->f_80 == 0 && g_Pad_681E4.f_180 != 0) {
        func_80066C90_681E4(&g_Pad_681E4.f_194, &g_Spike_681E4.f_60, 0x155);
    }
    d = 0;
    switch (g_Spike_681E4.f_5E) {
    case 0x40:
    case 0x41:
        d = g_Spike_681E4.f_60.vx * g_Spike_681E4.f_D0 + g_Spike_681E4.f_60.vz * g_Spike_681E4.f_D4;
        d /= g_Spike_681E4.f_CE;
        d = (d * sp->f_64) >> 15;
        break;
    case 0x3F:
        if (sp->f_64 != 0) {
            Spike_SetState(0x41);
        }
        break;
    case 0x3E:
        if (sp->f_64 != 0) {
            Spike_SetState(0x40);
        }
        break;
    case 0x3D:
        break;
    default:
        Spike_SetState(0x3D);
        break;
    }
    {
    s32 c;
    c = (u16)g_Spike_681E4.f_CC - d;
    g_Spike_681E4.f_CC = c;
    p = &g_Spike_681E4;
    if ((s16)c >= 0) {
        if ((s16)c > 0x1000) {
            c = 0x1000;
        }
    } else {
        c = 0;
    }
    p->f_CC = c;
    }
    Spike_CheckTransitions(g_SpikeAnimSets_681E4[0].f_8);
    Spike_CheckTransitions(sp->f_4C);
    if ((sp->f_54 & sp->f_58 & 0xA) && g_Spike_681E4.f_5E != 0x3D) {
        Spike_SetState(0x35);
        if (D_800E5498 == 0) {
            g_Spike_681E4.f_120 = 0;
            g_Spike_681E4.f_128 = 0;
        } else {
            g_Spike_681E4.f_120 = g_Spike_681E4.f_60.vx << 4;
            g_Spike_681E4.f_128 = g_Spike_681E4.f_60.vz << 4;
        }
        g_Spike_681E4.f_124 = 0xFFFC0000;
        g_Spike_681E4.f_118 = 0xFFFC0000;
        ((s32 *)&g_Spike_681E4.f_74)[0] = ((s32 *)&g_Spike_681E4.f_60)[0];
        ((s32 *)&g_Spike_681E4.f_74)[1] = ((s32 *)&g_Spike_681E4.f_60)[1];
        Spike_SetPlayMode(0);
    } else {
        if (!(g_Spike_681E4.f_E0 & 4)) {
            Spike_SetPlayMode(0);
            Spike_SetState(0x24);
        }
        g_Spike_681E4.f_14->f_18 = -0x100;
        g_Spike_681E4.f_14->f_14 = 0;
        g_Spike_681E4.f_14->f_1C = 0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80060780_spike", jtbl_800A5B88_pad);


typedef struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; } Rec_80068634;
typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0xC]; SVECTOR f_18; u8 pad20[4]; u16 f_24; } Obj_80068634;
struct Spike_80068634 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x20]; u32 f_50; u8 pad54[8]; u16 f_5C; u16 f_5E; SVECTOR f_60; u8 pad68[0x8A]; s8 f_F2; u8 padF3[0x2D]; s32 f_120; s32 f_124; s32 f_128; };
struct Pad_80068634 { u8 pad0[0x1BC]; s16 f_1BC; s16 f_1BE; };
typedef struct { u8 pad0[0x48]; s32 f_48; s32 f_4C; s32 f_50; } Scr_80068634;
extern Rec_80068634 g_SpikeAnimSets_68634[] asm("g_SpikeAnimSets");
Obj_80068634 *Collision_GetShape_68634(s32) asm("Collision_GetShape");
void func_800649D8_68634(s32) asm("Spike_CheckTransitions");
#define SP_80068634 ((struct Spike_80068634 *)&g_Spike)
/* Spike_UpdateOnShape: start a Spike action attached to a collision object: set the animation tables
 * (scratch +0x48/+0x4C/+0x50) from the base or current gadget set, clear +0x120..+0x128, step the
 * frame by 1 or 2 by the analog stick (pad +0x1BC + +0x1BE >= 0x65). If Spike's contact +0x50 is a
 * collision shape (top nibble 0xB) of type 0xB00, snap to it (position and direction) and run the
 * action tables (Spike_CheckTransitions); otherwise go back to play mode 0, state 0. */
void Spike_UpdateOnShape(void) {
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


typedef struct { s16 m[3][3]; s32 t[3]; } MAT_800687D8;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u8 pad[0x8]; } DrawBuf_800687D8;
struct GameDb_800687D8 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_800687D8 db[2]; };
typedef struct { s32 x, y, z; } V3_800687D8;
typedef struct { u8 pad0[0x48]; V3_800687D8 v; } Scr_800687D8;
typedef struct { s32 f_0; V3_800687D8 f_4; u8 f_10[0x14]; MAT_800687D8 *f_24; u8 pad28[0xC]; s32 f_34; s32 f_38; s32 f_3C; u8 pad40[0x2C]; s16 f_6C; u8 pad6E[0x18]; s16 f_86; } Obj_800687D8;
struct Spike_800687D8 { u8 pad0[0x18]; s32 f_18; u8 pad1C[8]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[2]; SVECTOR f_60; SVECTOR f_68; u8 pad70[0xB0]; s32 f_120; s32 f_124; s32 f_128; };
extern Obj_800687D8 *D_800B4D70_687 asm("D_800B4D70");
void func_800649D8_687(void) asm("Spike_CheckTransitions");
void Matrix_LookAt_687(SVECTOR *, SVECTOR *, MAT_800687D8 *, s32) asm("Matrix_LookAt");
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_Draw(u32 *, void *, void *);
void Fx_DrawGlowBeam(void *, void *, s32, s32);

/* Spike_UpdateRide: update and draw Spike while he is riding/attached to the object at D_800B4D70:
 * Spike takes the object's frame, steps his animation, the object copies his position back and
 * is drawn; in state 5 a pulsing glow beam is added. y is pinned to a0 to match the allocation. */
void Spike_UpdateRide(void) {
    Scr_800687D8 *scratch = (Scr_800687D8 *) 0x1F800000;
    u32 a;
    register u32 y asm("$4");
    scratch->v.x = D_800B4D70_687->f_4.x;
    y = D_800B4D70_687->f_4.y;
    scratch->v.y = y;
    scratch->v.z = D_800B4D70_687->f_4.z;
    ((struct Spike_800687D8 *) (&g_Spike))->f_18 = D_800B4D70_687->f_0;
    ((struct Spike_800687D8 *) (&g_Spike))->f_5C++;
    ((struct Spike_800687D8 *) (&g_Spike))->f_120 = 0;
    ((struct Spike_800687D8 *) (&g_Spike))->f_124 = 0;
    ((struct Spike_800687D8 *) (&g_Spike))->f_128 = 0;
    func_800649D8_687();
    D_800B4D70_687->f_34 = ((struct Spike_800687D8 *) (&g_Spike))->f_24;
    D_800B4D70_687->f_38 = ((struct Spike_800687D8 *) (&g_Spike))->f_28;
    D_800B4D70_687->f_3C = ((struct Spike_800687D8 *) (&g_Spike))->f_2C;
    D_800B4D70_687->f_6C = ((struct Spike_800687D8 *) (&g_Spike))->f_5C;
    Matrix_LookAt_687(&((struct Spike_800687D8 *) (&g_Spike))->f_60, &((struct Spike_800687D8 *) (&g_Spike))->f_68, D_800B4D70_687->f_24, 1);
    Model_CalcKeyedJointMatrices(D_800B4D70_687->f_10, 1);
    Model_ProjectBonedVerts(D_800B4D70_687->f_10);
    Model_Draw(((struct GameDb_800687D8 *) (&g_Game))->db[((struct GameDb_800687D8 *) (&g_Game))->cur].ot, g_ProjVerts, D_800B4D70_687->f_10);
    if (D_800B4D70_687->f_86 == 5) {
        a = ((struct GameDb_800687D8 *) (&g_Game))->frame & 0x1F;
        if (a > 0x10) {
            a = 0x20 - a;
        }
        Fx_DrawGlowBeam(g_ProjVerts + 0x268, g_ProjVerts + 0x270, a + 0x18, 0xFF8080);
    }
    scratch->v.x = D_800B4D70_687->f_4.x;
    scratch->v.y = D_800B4D70_687->f_4.y;
    scratch->v.z = D_800B4D70_687->f_4.z;
}

void Spike_PlayVoice(s32 a) {
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



void Spike_DrawStretched(void) {
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
    Model_CalcJointMatrices(((struct S_D_800EC1E0_800689F0 *)&g_Spike), 7);
    Model_ProjectBonedVerts(((struct S_D_800EC1E0_800689F0 *)&g_Spike));
    Model_CycleVertexColors(g_ProjVerts, ((struct S_D_800EC1E0_800689F0 *)&g_Spike)->f_0->f_6);
    Model_DrawCycledColors(g_GameOt, g_ProjVerts, ((struct S_D_800EC1E0_800689F0 *)&g_Spike));
}

void Spike_DrawWarpA(void) {
    Spike_DrawStretched();
    if (D_800EC2E0 < 0x1E) {
        func_8006C92C();
    }
}

void Spike_DrawWarpB(void) {
    g_Spike.f_38 = 0;
    g_Spike.f_34 = 0;
    g_Spike.f_30 = 0;
    Spike_DrawStretched();
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
