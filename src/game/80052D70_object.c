#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "common.h"
#include "common.h"
#include "common.h"
#include "common.h"
#define RAND() (g_RandSeed = g_RandSeed * 5 + 1)
#define E2(o) (*(u16 *)((u8 *)(o) + 0xE2))
#define G_SPIKE_80053CE8 ((struct g_Spike_80053CE8 *)&g_Spike)
#define ABS2(x) ((x) < 0 ? -(x) : (x))
typedef struct { u8 pad0[0xAC]; s16 f_AC; s16 f_AE; u8 padB0[2]; s16 f_B2; } S_8005685C;
typedef struct { u16 unk0; u16 unk2; } S_Frame;
typedef struct { u8 pad0[0x24]; s32 unk24; s32 unk28; s32 unk2C; u8 pad30[0x16]; s16 unk46; s16 unk48; s16 unk4A; u8 pad4C[0x10]; u16 unk5C; u8 pad5E[0x21]; u8 unk7F; u8 unk80; u8 pad81[7]; S_Frame *unk88; u8 pad8C[0x1C]; s16 unkA8; u8 padAA[0xA]; s32 unkB4; u8 padB8[0x28]; u32 unkE0; } S_52DFC;
typedef struct { u16 f_0; u16 f_2; } S_Frame_8005337C;
typedef struct { u8 pad0[0x44]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x20]; u8 f_7E; u8 f_7F; u8 pad80; u8 f_81; u8 pad82[6]; S_Frame_8005337C *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[6]; s16 f_A8; u8 padAA[6]; s16 f_B0; u8 padB2[0x16]; u8 f_C8; u8 padC9[4]; u8 f_CD; u8 padCE[0xE]; u8 f_DC; u8 padDD[3]; u32 f_E0; } S_5337C_8005337C;
typedef struct { u8 pad0[0x5C]; u16 unk5C; u8 pad5E[0x21]; u8 unk7F; u8 unk80; u8 pad81[7]; u16 *unk88; } S_52ED4;
typedef struct { s16 vx, vy, vz, pad; } SVEC_800555D8;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } S_555D8_800555D8;
typedef struct { u8 pad0[0x24]; s16 f_24; s16 pad26; s16 f_28; s16 pad2A; s16 f_2C; } S_573A0_800573A0;
typedef struct { s16 x, y, z; } S16x3;
typedef struct { u8 pad0[0x24]; s16 unk24; s16 pad26; s16 unk28; s16 pad2A; s16 unk2C; } S_55404;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80055674;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x6A]; s16 f_9A; u8 pad9C[2]; s16 f_9E; } S_55674_80055674;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x64]; s16 f_94; s16 pad96; s16 f_98; u8 pad9A[0x46]; u32 f_E0; } S_56344_80056344;
typedef struct { u8 pad0[0x24]; s16 f_24; s16 pad26; s16 f_28; s16 pad2A; s16 f_2C; } S_573A0_80057504;
typedef struct { u8 pad0[0x60]; s16 f_60; s16 pad62; s16 f_64; u8 pad66[0x3C]; s16 f_A2; } S_565C4_800565C4;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x6A]; s16 f_9A; u8 pad9C[2]; s16 f_9E; u8 padA0[4]; s16 f_A4; } S_56674_80056674;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } S_56714_80056714;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } S_56714_800567B8;
typedef struct { u8 pad0[0xAA]; s16 f_AA; u8 padAC[0x34]; u32 f_E0; } S_559E8_800559E8;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x6A]; s16 f_9A; s16 f_9C; s16 f_9E; } S_56CE0_80056CE0;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8005744C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } S_5744C_8005744C;
typedef struct { s32 f_0; s32 f_4; s32 f_8; u8 padC[0xC]; SVECTOR f_18; s16 f_20; s16 f_22; s16 f_24; s16 f_26; u8 pad28[0x10]; } S_BD1A0_8005813C;
typedef struct { u8 pad0[0x60]; SVECTOR f_60; } S_5813C_8005813C;
typedef struct { u8 pad0[0x94]; s16 f_94; s16 pad96; s16 f_98; u8 pad9A[0x16]; s16 f_B0; } S_53304_80053304;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80053B44;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x64]; s16 f_94; s16 pad96; s16 f_98; } S_53B44_80053B44;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80[8]; u16 *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[0xE]; s16 f_B0; u8 padB2[0x2E]; u32 f_E0; } S_55328_80055328;
typedef struct { u16 f_0; u16 f_2; } S_Rec4_80056E50;
typedef struct { u8 pad_0[0x5C]; u16 f_5C; u8 pad_5E[0x21]; u8 f_7F; u8 f_80; u8 pad_81[0x7]; S_Rec4_80056E50 *f_88; u8 pad_8C[0x42]; u8 f_CE; } S_80056E50_80056E50;
typedef struct { s16 x, y, z; } S16x3_800573EC;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80056128;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x64]; s16 f_94; s16 pad96; s16 f_98; s16 f_9A; s16 pad9C; s16 f_9E; u8 padA0[6]; s16 f_A6; } S_56128_80056128;
typedef struct { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1; u32 b4 : 1; u32 b5 : 9; u32 b14 : 1; u32 b15 : 12; u32 b27 : 1; u32 b28 : 4; } EFlags_80056AE4;
typedef struct { u8 pad0[0x1C]; s32 f_1C; u8 pad20[4]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 f_81; u8 pad82[0x18]; s16 f_9A; s16 f_9C; s16 f_9E; u8 padA0[0x2A]; s8 f_CA; u8 padCB[0x15]; EFlags_80056AE4 f_E0; } S_56AE4_80056AE4;
typedef struct { u8 pad0[4]; u16 f_4; } S88_80053154_80053154;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[4]; s32 f_2C; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[0x20]; u8 f_7E; u8 f_7F; u8 f_80; u8 pad81[7]; S88_80053154_80053154 *f_88; u8 pad8C[0xA]; s16 f_96; u8 pad98[0x10]; s16 f_A8; u8 padAA[6]; s16 f_B0; u8 padB2[0x2E]; u32 f_E0; } S_80053154_80053154;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x64]; s16 f_94; s16 pad96; s16 f_98; u8 pad9A[0x14]; s16 f_AE; s16 f_B0; } S_55AA0_80055AA0;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[4]; s32 f_2C; u8 pad30[0x30]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0x44]; s16 f_AA; s16 f_AC; u8 padAE[0x32]; struct { u32 b0 : 19; u32 b19 : 1; u32 b20 : 12; } f_E0; } S_80056238_80056238;
typedef struct { u8 pad0[0x24]; s32 f_24; u8 pad28[4]; s32 f_2C; u8 pad30[0x30]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0x2E]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x12]; s16 f_AC; u8 padAE[0x32]; struct { u32 b0 : 5; u32 b5 : 1; u32 b6 : 4; u32 b10 : 1; u32 b11 : 21; } f_E0; } S_800571C4_800571C4;
typedef struct { u8 pad0[0x8C]; u16 f_8C; u8 f_8E; u8 pad8F[0x51]; struct { u32 b0 : 6; u32 b6 : 1; u32 b7 : 25; } f_E0; } S_800584C8_800584C8;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0x34]; s16 f_9A; s16 pad9C; s16 f_9E; s16 padA0; s16 f_A2; s16 f_A4; } S_558C4_800558C4;
typedef struct { u8 pad0[0xE0]; u32 f_E0; } S_O_80057FD0_80057FD0;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x64]; s16 f_94; s16 f_96; s16 f_98; u8 pad9A[0x16]; s16 f_B0; } S_O_80055718_80055718;
typedef struct { u8 pad0[0xAE]; s16 f_AE; u8 padB0[2]; s16 f_B2; } O_80053A1C_80053A1C;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x18]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[7]; u16 *f_88; u8 pad8C[0x10]; s16 f_9C; u8 pad9E[2]; s16 f_A0; u8 padA2[0xE]; s16 f_B0; u8 padB2[0x1B]; u8 f_CD; u8 padCE[0x12]; u32 f_E0; } O_800542C0_800542C0;
typedef struct { u16 start; u16 end; } Seg_80056010_80056010;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80[8]; Seg_80056010_80056010 *f_88; } O_80056010_80056010;
typedef struct { u16 start; u16 end; } Anim_53E98_80053E98;
typedef struct { u8 pad0[0x28]; s32 y; u8 pad2C[0x18]; s16 f_44; u8 pad46[0x16]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 f_80; u8 pad81[7]; Anim_53E98_80053E98 *f_88; u8 pad8C[3]; u8 f_8F; u8 pad90[0xA]; s16 f_9A; u8 pad9C[2]; s16 f_9E; u8 padA0[8]; s16 f_A8; u8 padAA[8]; s16 f_B2; u8 padB4[0x2C]; u32 f_E0; } Obj_53E98_80053E98;
typedef struct { u16 start; u16 end; } Anim_53550_80053550;
typedef struct { u8 pad0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 x; s32 y; s32 z; u8 pad30[0x14]; s16 f_44; s16 f_46; u8 pad48[0x14]; u16 f_5C; u8 pad5E[2]; s16 f_60; u8 pad62[2]; s16 f_64; u8 pad66[0x18]; u8 kind; u8 f_7F; u8 f_80; u8 pad81[7]; Anim_53550_80053550 *f_88; u8 pad8C[3]; u8 f_8F; u8 pad90[6]; u16 f_96; u8 pad98[4]; s16 f_9C; u8 pad9E[0xA]; s16 f_A8; u8 padAA[6]; s16 f_B0; u8 padB2[2]; s32 f_B4; u8 padB8[0x11]; u8 f_C9; u8 padCA[0x16]; u32 f_E0; u16 f_E2_dummy; } Obj_53550_80053550;
typedef struct { s16 vx, vy, vz, pad; } SV_55174_80055174;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x14]; s16 f_44; s16 f_46; u8 pad48[8]; u32 f_50; u8 pad54[8]; u16 f_5C; u8 pad5E[0x20]; u8 kind; u8 f_7F; u8 pad80[8]; u16 *f_88; u16 f_8C; u8 pad8E[0x12]; s16 f_A0; u8 padA2[0x2B]; u8 f_CD; u8 padCE[0x12]; u32 f_E0; } Obj_55174_80055174;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 pad62; s16 f_64; u8 pad66[0x2E]; s16 f_94; u16 f_96; s16 f_98; u8 pad9A[0x12]; s16 f_AC; u8 padAE[0x32]; u32 f_E0; } S_572CC_800572CC;
typedef struct { s16 vx, vy, vz; } S16x3_80055D28;
typedef struct { u8 pad0[0x94]; s16 f_94; s16 f_96; s16 f_98; } S_55D28_80055D28;
typedef struct { u8 pad0[0x7E]; u8 f_7E; u8 pad7F[0x4B]; s8 f_CA; u8 padCB; u8 f_CC; u8 padCD[0x13]; u32 f_E0; } S_E6960_80054A08;
typedef struct { u16 f_0; u16 f_2; } S_Frame_80053CE8;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[2]; s16 f_60; s16 pad62; s16 f_64; u8 pad66[0x19]; u8 f_7F; u8 f_80; u8 pad81[7]; S_Frame_80053CE8 *f_88; u8 pad8C[0xE]; s16 f_9A; s16 pad9C; s16 f_9E; u8 padA0[6]; s16 f_A6; u8 padA8[4]; s16 f_AC; u8 padAE[0x35]; u8 f_E3; u32 unkE0_; } S_53CE8_80053CE8;
typedef struct { u16 f_0; u16 f_2; } S_Frame_80054220;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x21]; u8 f_7F; u8 pad80[8]; S_Frame_80054220 *f_88; } S_54220_80054220;
typedef struct { u16 f_0; u16 f_2; } S_Frame_80052F28;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x20]; u8 f_7E; u8 f_7F; u8 pad80[8]; S_Frame_80052F28 *f_88; } S_52F28_80052F28;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } O_56EAC_80056EAC;
typedef struct { u8 pad0[0x28]; s16 f_28; u8 pad2A[0x66]; u8 *f_90; } S_58400_80058400;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x6A]; s16 f_96; } S_5648C_8005648C;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } S_56F6C_80056F6C;
typedef struct { u8 pad0[0x2C]; u32 f_2C; } S_Obj_800582EC;
typedef struct { u8 pad0[0xB4]; S_Obj_800582EC *f_B4[4]; } S_582EC_800582EC;
typedef struct { u8 pad0[0x28]; s32 f_28; u8 pad2C[0x6A]; s16 f_96; u8 pad98[4]; s16 f_9C; } O_80055B9C_80055B9C;
typedef struct { u8 pad0[0xA8]; s16 size; u8 padAA[0x36]; u32 flags; } Obj_80056DC4;
typedef struct { u16 f_0; u16 f_2; } S_Frame_80053DFC;
typedef struct { u8 pad0[0x44]; s16 f_44; s16 f_46; s16 f_48; s16 f_4A; u8 pad4C[0x10]; u16 f_5C; u8 pad5E[0x1E]; s8 f_7C; u8 pad7D; u8 f_7E; u8 f_7F; u8 f_80; u8 pad81[7]; S_Frame_80053DFC *f_88; u8 pad8C[0x14]; s16 f_A0; u8 padA2[0xE]; s16 f_B0; u8 padB2[0x1B]; u8 f_CD; u8 padCE[0xE]; u8 f_DC; u8 padDD[3]; u32 f_E0; } S_53DFC_80053DFC;
typedef struct { u8 pad0[0xA6]; s16 f_A6; u8 padA8[2]; s16 f_AA; u8 padAC[0x33]; u8 f_DF; u32 f_E0; } S_55F1C_80055F1C;


/* Clears object link i (+0xB4) and returns the linked object's kind (its +0x2C >> 28), 0 if none. */
u32 Object_DetachLink(S_582EC_800582EC *s, s32 i);
s32 func_8005588C(void *arg0, s32 arg1);
s32 Object_AddAttackSphereNear(void *, s32, s32, s32, s16, s32, s32);

extern u16 D_800AE8F2;

extern s8 D_800E77ED;

void func_800A3740(void *, s32, s32);
extern struct S_D_800E6960 { u8 pad_0[0x7E]; u8 f_7E; u8 pad_7F[0x2]; u8 f_81; u8 pad_82[0x18]; u16 f_9A; s16 f_9C; u16 f_9E; u8 pad_A0[4]; s16 f_A4; s16 f_A6; u8 pad_A8[0x38]; u32 f_E0; } g_Objects[];
s32 func_800569C4(s16 kind, s16 flag);
void func_80056AE4(S_56AE4_80056AE4 *s, s32 *pos, s32 k);
void func_80051E98(struct S_D_800E6960 *, s32);

s16 Floor_GetHeight(s32, s32, s32);

s32 Object_SpikeOutOfYRange(void *, s32);
s32 Spike_WithinRadiusXZ(s32 x, s32 z, s32 r);
void func_8006B3CC(s16 *);
extern struct S_D_800E77D0 { u8 pad_0[0x10]; s16 f_10; u8 pad_12[0x8]; u8 f_1A; u8 pad_1B[0x1]; u8 f_1C; u8 pad_1D[0x6]; u8 f_23; } D_800E77D0;

void Sound_PlayAt(s32, S16x3 *);

M2C_UNK func_8013E02C();
M2C_UNK func_8013E074();
M2C_UNK func_8013E150();
M2C_UNK func_8013F408();
M2C_UNK func_801405CC();
M2C_UNK func_80140984();
M2C_UNK func_80141760();
extern struct S_D_800EC350 { u8 pad_0[0x8124]; u16 f_8124; u16 f_8126; u8 pad_8128[0x11C]; s32 f_8244; } g_Game;
M2C_UNK func_8013D714();
M2C_UNK func_8013DB38();
M2C_UNK func_8013EA6C();
M2C_UNK func_801403E0();
M2C_UNK func_80141FDC();
M2C_UNK func_8013DAEC();
M2C_UNK func_8013EA38();
M2C_UNK func_8013FC98();
M2C_UNK func_8013DE74();
M2C_UNK func_8013E774();
M2C_UNK func_8013EB9C();
M2C_UNK func_8013ED60();
M2C_UNK func_8013FA2C();
M2C_UNK func_80140F9C();

extern s8 D_800E77A5;
extern struct S_D_800B8D20 { s32 f_0; } g_Hooks[];

s16 func_80058400(S_58400_80058400 *a, u8 i, s8 mode, s16 d);
void func_800584C8(S_800584C8_800584C8 *m, s8 bounce);

M2C_UNK func_8013D2BC();
M2C_UNK func_8013D630();
M2C_UNK func_8013D7AC();
M2C_UNK func_801424D4();

extern M2C_UNK D_800E7800;

void func_80052F28(S_52F28_80052F28 *s);
void Object_ChaseSpike(void *arg0, s16 arg1);
s32 Object_StepGrowShrink(Obj_80056DC4 *, s16, s16, s16);
void Object_HeadTowardSpike(S_555D8_800555D8 *s, s32 b);
extern s8 D_800E77EB;
s32 Object_SpikeInFront(S_56714_800567B8 *s, s32 a, s32 b, s16 r);

void func_80055328();
M2C_UNK func_8013F2E0();
M2C_UNK func_8013F460();
M2C_UNK func_80140348();
M2C_UNK func_8013EF54();
M2C_UNK func_8013F08C();
M2C_UNK func_8013F7E0();
M2C_UNK func_8013E778();
M2C_UNK func_8013FAEC();
M2C_UNK func_8013DF54();
M2C_UNK func_8013F504();
M2C_UNK func_80140880();
M2C_UNK func_8014116C();
M2C_UNK func_8013FCE0();
M2C_UNK func_80141CFC();
M2C_UNK func_8013D810();
M2C_UNK func_8013FB20();
M2C_UNK func_8013D1BC();
M2C_UNK func_8013EED0();
M2C_UNK func_8013FF9C();
M2C_UNK func_80140264();
M2C_UNK func_8013D67C();
M2C_UNK func_8013E8B4();
M2C_UNK func_8013D484();
M2C_UNK func_8013FE8C();
M2C_UNK func_8013D770();
M2C_UNK func_8013E340();
M2C_UNK func_8013EFBC();
M2C_UNK func_8013F4F4();
M2C_UNK func_80140800();
M2C_UNK func_8013EA4C();
M2C_UNK func_8013DA5C();
M2C_UNK func_801407F8();
M2C_UNK func_8013E38C();
M2C_UNK func_8013EF7C();
M2C_UNK func_8013D51C();
M2C_UNK func_8013EA18();
M2C_UNK func_8013ECD4();
M2C_UNK func_8013F71C();
M2C_UNK func_801402E8();
M2C_UNK func_8013E200();
M2C_UNK func_8013F740();
M2C_UNK func_8013EAF8();
M2C_UNK func_8013FF2C();
M2C_UNK func_801411B8();
M2C_UNK func_8013E6BC();
M2C_UNK func_8013EEB4();
M2C_UNK func_801407DC();
M2C_UNK func_801412FC();
struct g_Spike_80053CE8 { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; };
s32 Object_SpikeOutOfRange(void *s, s32 x, s32 px, s32 z, s16 r);
s32 Object_SpikeWithin(O_56EAC_80056EAC *o, s32 d);
/* 1 if Spike is less than r away from object s on both x and z (a square, not a circle). */
s32 Object_SpikeWithinXZ(S_56F6C_80056F6C *s, s32 r);
extern s32 D_800E77D8;

s32 Object_StepOnGround(S_56344_80056344 *s, s16 h);
void Object_HeadHome(S_55674_80055674 *s, s32 a, s32 b);
s16 Object_FloorAt(void *arg0, s16 arg1, s16 arg2, s16 arg3);
S_BD1A0_8005813C *Object_AddAttackSphere(S_5813C_8005813C *s, s16 a, s16 x, s16 y, s16 z, s16 e, s16 g);


void func_80052ED4(S_52ED4 *a);

void VectorNormalSS();
void Object_TurnToward(S_8005685C *m, s16 dx, s16 dz, s16 off, s16 max);
void Object_StepOrbitAngle(S_559E8_800559E8 *s, s16 a);
s32 func_80055AA0(S_55AA0_80055AA0 *s, s32 tx, s32 tz, s32 r);
s32 rcos(s16);
s32 rsin(s16);

void Object_PlaySound(S_55404 *a, s32 b);
void func_800571C4();
void Object_SpawnEffect(S_573A0_80057504 *a, s16 id, s32 dx, s32 dy, s32 dz);
M2C_UNK func_800525E0(void *);
M2C_UNK func_80052864(void *);
void func_8005744C(S_5744C_8005744C *s, s32 dx, s32 dy, s32 dz);
void *Collision_GetShape(s32);
M2C_UNK Camera_StartShake(M2C_UNK);
void Object_SetVelocityToward(void *arg0, void *arg1, s32 arg2, s16 arg3);
extern u16 g_RandSeed;
s32 Object_WouldLeaveHome(void *arg0, s16 arg1);
void func_80055D28(S_55D28_80055D28 *s, s16 a, s16 b);
void Effect_SpawnAt(s32, s16 *);
s32 Object_IsFacingDir(S_565C4_800565C4 *s, s32 ang, s32 lim, s16 dx, s16 dz);
extern struct S_D_800E77A0 { u8 pad0; u8 f_1; u8 f_2; u8 pad_3[0x2]; u8 f_5; u16 f_6; } D_800E77A0;
void func_800573EC(s16 *p);
S_BD1A0_8005813C *CollShape_Alloc(void);
void Collision_Set(s32, S_BD1A0_8005813C *, S_5813C_8005813C *);
s32 func_80055DC0(void *s, s16 a, s16 b);
s32 Math_Atan2(s32, s32);
extern s32 D_800AF520;
void func_80070284(s16 *, void *, s32, s32, S16x3_800573EC *);
struct S_D_800EC1E0_800573EC { u8 pad0[0x24]; s16 f_24; s16 pad26; s16 f_28; s16 pad2A; s16 f_2C; };
s32 Vec_Length(s32, M2C_UNK, s32, s16);
struct S_D_800E6960 *func_80056BC4(s16 id, s32 b, s16 c);
struct S_D_800E77A0_80057A28 { u8 pad_0[0x1]; u8 f_1; u8 f_2; u8 pad_3[0x3]; u16 f_6; };
struct S_D_800EC1E0_80057A28 { u8 pad_0[0x24]; s32 f_24; u8 pad_28[0x4]; s32 f_2C; };
struct S_D_800EC350_80057A28 { u8 pad_0[0x8126]; u16 f_8126; };
void func_8007CD88(s32 *);
extern s8 D_800E77F1;
s32 Object_FallToFloor(S_5648C_8005648C *s);
void Object_SetForwardVelocity(void *arg0, s16 arg1);
struct S_D_800E77D0_800569C4 { u8 pad0[0x10]; s16 f_10; };
struct S_D_800E6960_800569C4 { u8 pad0[0x7E]; u8 f_7E; u8 pad7F[0x61]; struct { u32 b0 : 4; u32 b4 : 1; u32 b5 : 27; } f_E0; };
struct S_D_800EC350_80057FD0 { u8 pad_0[0x8126]; u16 f_8126; };
struct S_D_800E77A0_80057FD0 { u8 f_0; u8 f_1; u8 f_2; u8 pad_3[0x2]; u8 f_5; u16 f_6; };
extern struct S_D_800AF590 { u8 pad[0x24]; } D_800AF590[];
extern struct S_D_800AF590 *D_800B00A4;
extern u8 D_800E77E4[];
void func_8007D23C(struct S_D_800AF590 *, u8 *, s32);
void DebugItem_Init(struct S_D_800AF590 *, u8 *, s32);
void func_8007D29C(struct S_D_800AF590 *, void (*)());
s32 func_8005879C(s32 a);
struct S_D_800E77A0_8005760C { u8 pad0[5]; u8 count; };
void func_80055F1C(S_55F1C_80055F1C *s, s32 a);
void func_80058134(); /* empty stub; callers pass (obj, value) */
void func_80055E6C(void *arg0, s16 arg1);
/* Steer Y (f_28) toward the target height f_9C: sets Y velocity f_96 to +-speed,
   or snaps to the target, zeroes the velocity and returns 1 once within speed. */
s32 Object_SeekHeight(O_80055B9C_80055B9C *o, s16 speed);
s32 func_800563E0(void *arg0, s32 arg1);
void func_80054220(S_54220_80054220 *s);
s32 Math_WithinSquare(s32 arg0, s32 arg1, s32 arg2);
void func_80053DFC(S_53DFC_80053DFC *s);
void func_80058134();
s32 func_80053C14(void *arg0);
s32 func_80055718(S_O_80055718_80055718 *o, s32 x, s32 y, s32 z, s32 r);
void Object_StepOnGroundFixed(void *arg0);
s32 func_80053CE8(S_53CE8_80053CE8 *s, s32 flag);
void func_80053CB4(u8 *arg0);
void func_80053A6C(void *arg0);
void Object_MoveTowardSpike(S_53B44_80053B44 *s, s32 speed);
void func_80053A1C(O_80053A1C_80053A1C *o, s32 on);
void func_800539B4(u8* arg0);
void Object_ClampAnimFrame(void *arg0, s32 arg1);
void func_80053DE4(void *arg0);
void func_80053AC0(s32 arg0);
void func_80053BD8(void *arg0);
extern s8 D_800E77EC;
void func_8005337C(S_5337C_8005337C *s);
void func_800534E8(u8* arg0);
void func_80053440(void *arg0);
void func_80053304(S_53304_80053304 *s);
void func_80053154(S_80053154_80053154 *m);
void func_80052FE8(void *arg0);
void func_80052DFC(S_52DFC *s);
void func_80052D70(void *arg0);
void func_80053264(void *arg0);
void func_80056128(S_56128_80056128 *s, s16 b);
void Object_TurnTowardSpike(void *arg0);
void Object_SetVelY(void *arg0, s16 arg1);
void func_800530D0(void *arg0);
void Object_DisableCollision(Obj_53550_80053550 *);
s32 func_800572CC(S_572CC_800572CC *s);
void Object_EnableCollision(Obj_53550_80053550 *);
void Object_Destroy(Obj_53550_80053550 *);
struct Game_55174 { u8 pad0[0x8126]; u16 f_8126; };
extern void D_8013D6B8(s32, s32, s32);
extern void D_80141418(s32, s32, s32);
extern void D_8013D6B8_52(s32, s32, s32);
void Object_PlaceAtPathPoint(void *arg0, s32 arg1);
void func_8005866C(void *arg0, s32 arg1);
void Pickup_Drop(s32, SV_55174_80055174 *, s32, s32);
s32 func_8005278C(S_572CC_800572CC *);
s32 func_80052688(S_572CC_800572CC *, s16);
extern s16 D_800E77E0;
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
extern s32 D_800EC204;
extern s32 D_800EC208;
extern s32 D_800EC20C;
/* The duplicated if/else (both arms equal, no branch in the output) is a permuter find; a single
 * copy schedules the f_E0 load differently. */

void func_80052D70(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    func_80055AA0(arg0, (s32) M2C_FIELD(arg0, s16 *, 0x9A), (s32) M2C_FIELD(arg0, s16 *, 0x9E), 8);
    Object_StepOnGround(arg0, 0x40);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x9A) - M2C_FIELD(arg0, s32 *, 0x24);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9E) - M2C_FIELD(arg0, s32 *, 0x2C);
    if (((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < 0x400) {
        M2C_FIELD(arg0, s8 *, 0x80) = 1;
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s16 *, 0x96) = 0;
        M2C_FIELD(arg0, s16 *, 0x94) = 0;
    }
}

void func_80052DFC(S_52DFC *s)
{
  u16 new_var;
  if (Object_DetachLink(s, 0) == 6)
  {
    s->unk80 = 6;
    s->unk7F = 0;
    new_var = s->unk88->unk0;
    s->unkE0 &= ~0x10000;
    s->unkA8 = 0x140;
    s->unk5C = new_var;
    Object_PlaySound(s, 0x5F);
    func_8005588C(s, (D_800E77ED != 0) ? (D_800E77ED) : (0x32));
  }
  s->unkB4 = Object_AddAttackSphereNear(s, 0x78, (s16) s->unk24, (s16) (s->unk28 - (((s16) s->unk46) >> 1)), s->unk2C, s->unk48, s->unk4A);
}

void func_80052ED4(S_52ED4 *a)
{
  u16 *q = a->unk88;
  s32 v;
 do { a->unk80 = 5; a->unk7F = 0; a->unk5C = *q; v = 0x32; } while (0);
  if (D_800E77ED != 0)
  {
    v = D_800E77ED;
  }
  func_8005588C(a, v);
}

void func_80052F28(S_52F28_80052F28 *s) {
    s32 d = s->f_5C - s->f_88[s->f_7F].f_0;
    s16 m;
    s32 r;
    if (s->f_7E == 3) {
        m = 4;
        r = 0;
    } else {
        m = 8;
        r = 3;
    }
    if (d < 13 && d % m == r) {
        Object_PlaySound(s, 0x45);
        Object_SpawnEffect(s, 4, 0, 0, 0);
    }
}

void func_80052FE8(void *arg0) {
    s32 var_s1;

    var_s1 = 0x28;
    Object_ChaseSpike(arg0, (s16) ((s32) (M2C_FIELD(arg0, u16 *, 0xA8) << 0x10) >> 0x13));
    Object_StepOnGround(arg0, 0x40);
    func_80052F28(arg0);
    if (Object_WouldLeaveHome(arg0, 0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x80) = 4;
    }
    if (M2C_FIELD(arg0, u8 *, 0x7E) == 0x49) {
        var_s1 = 0x14;
        if (M2C_FIELD(arg0, u16 *, 0xE2) & 1) {
            goto block_5;
        }
    } else {
block_5:
        if (Object_StepGrowShrink(arg0, var_s1, (s32) (s16) ((s8) D_800E77D0.f_1A + 0xA), (s32) (s16) (-0x15 - (s8) D_800E77D0.f_1C)) != 0) {
            func_80052ED4(arg0);
        }
    }
}

void func_800530D0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 0xB;
    M2C_FIELD(arg0, s8 *, 0x7F) = 4;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x88), u16 *, 0x10);
    func_800571C4();
    Object_PlaySound(arg0, 0x68);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~1);
    Object_SpawnEffect(arg0, 4, 0, 0, 0);
    M2C_FIELD(arg0, s16 *, 0x44) = 0x2D;
    M2C_FIELD(arg0, s16 *, 0x46) = 0x72;
}

void func_80053154(S_80053154_80053154 *m) {
    Object_TurnToward(m, g_Spike.f_24 - m->f_24, g_Spike.f_2C - m->f_2C, 0, 0xB6);
    if (Object_FallToFloor(m)) {
        m->f_E0 |= 0x10000;
        m->f_A8 = 0;
        if (m->f_7E == 0x49) {
            m->f_B0 = ((D_800E77F1 + 9) << 12) / 360;
        } else {
            m->f_B0 = ((D_800E77F1 + 3) << 12) / 360;
        }
        m->f_80 = 3;
        m->f_7F = 1;
        m->f_5C = m->f_88->f_4;
    }
    m->f_96 += 10;
}

void Object_SetVelY(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x96) = arg1;
}

void func_80053264(void *arg0) {
    if ((Spike_WithinRadiusXZ(M2C_FIELD(arg0, s16 *, 0x9A), M2C_FIELD(arg0, s16 *, 0x9E), M2C_FIELD(arg0, s16 *, 0xA6)) != 0) && (Object_SpikeOutOfRange(arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), (D_800E77EB * 0x19) + 0x271) == 0)) {
        M2C_FIELD(arg0, s8 *, 0x80) = 2;
        Object_HeadTowardSpike(arg0, 1);
        Object_PlaySound(arg0, 0x61);
        Object_SetVelY(arg0, -0x2A);
    }
}

void func_80053304(S_53304_80053304 *s)
{
  S_53304_80053304 *new_var;
  int new_var4;
  int new_var2;
  int new_var3;
  func_80055DC0(s, 8, 0);
  if (((s16) Object_StepOnGround(s, 0x40)) == 0)
  {
    new_var2 = -s->f_98;
    new_var = s;
    new_var4 = -s->f_94;
    new_var->f_94 = new_var4;
    new_var3 = new_var2;
    (*s).f_98 = new_var3;
    Object_TurnToward(s, s->f_94, s->f_98, 0, s->f_B0);
  }
}

void func_8005337C(S_5337C_8005337C *s) {
    s->f_A0 = 0x32;
    s->f_A8 = 8;
    s->f_B0 = 0x5B;
    s->f_48 = 1;
    s->f_4A = 0xC103;
    s->f_44 = 0x5A;
    s->f_46 = 0xE4;
    s->f_E0 |= 0x10000;
    s->f_CD = 2;
    switch (s->f_7E) {
    case 0xE:
        s->f_48 = 0;
        s->f_4A = 0xC101;
        break;
    case 0x49:
        s->f_C8 = 5;
        s->f_81 = 5;
        s->f_DC = 2;
        break;
    case 3:
        s->f_DC = 0;
        break;
    }
    s->f_7F = 0;
    s->f_5C = s->f_88[0].f_0;
}

void func_80053440(void *arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0xE0);
    if ((temp_v1 >> 0x14) & 1) {
        M2C_FIELD(arg0, u32 *, 0xE0) = (u32) (temp_v1 & 0xFFEFFFFF);
        M2C_FIELD(arg0, s16 *, 0x44) = 0x5A;
        M2C_FIELD(arg0, s16 *, 0x46) = 0xE4;
        if ((Object_SpikeInFront(arg0, 0x5A, 0xB50, 0x600) != 0) && (M2C_FIELD(arg0, u8 *, 0x7E) == 0x49)) {
            M2C_FIELD(arg0, s8 *, 0x80) = 0xA;
            M2C_FIELD(arg0, s8 *, 0x8F) = 0;
            Object_SetVelY(arg0, -0x2A);
            return;
        }
        func_80052ED4(arg0);
        M2C_FIELD(arg0, s16 *, 0xB0) = 0x5B;
    }
}

void func_800534E8(u8* arg0) {
    u8 state;

    if (Object_WouldLeaveHome(arg0, 0) != 0) {
        state = arg0[0x80];
        if (state != 5 && state != 10 && state != 11 && state != 12) {
            func_80052ED4(arg0);
            *(s16*)(arg0 + 0xB0) = 0x5B;
        }
    }
}

void func_80053550(Obj_53550_80053550 *o) {
    s32 a;
    if (!((o->f_E0 >> 3) & 1)) {
        func_8005337C(o);
        o->f_E0 |= 8;
    }
    func_80058134(o, o->f_44);
    func_800534E8(o);
    func_80053440(o);
    switch (o->f_80) {
    case 1:
        func_80053304(o);
        func_80053264(o);
        break;
    case 2:
        func_80053154(o);
        break;
    case 3:
        func_80052FE8(o);
        func_80052DFC(o);
        break;
    case 4:
        func_80052ED4(o);
        o->f_B0 = 0x5B;
        break;
    case 5:
        func_80052D70(o);
        if (!func_8005588C(o, -1)) {
            func_80053264(o);
        }
        break;
    case 6:
        a = D_800E77EC;
        if (a != 0) {
            a = -a;
        } else {
            a = -0x1E;
        }
        Object_StepGrowShrink(o, 0, 0, a);
        if (!(E2(o) & 1)) {
            o->x -= o->f_60 * (o->f_A8 >> 3) >> 12;
            o->z -= o->f_64 * (o->f_A8 >> 3) >> 12;
            o->y = Object_FloorAt(o, 0, 0, 0);
        } else {
            o->f_80 = 7;
        }
        if (o->f_C9 != 0) {
            o->f_C9--;
        }
        break;
    case 7:
        func_80056128(o, 8);
        Object_StepOnGround(o, 0x40);
        if (!func_8005588C(o, -1)) {
            o->f_B0 = 0x5B;
            o->f_80 = 1;
        }
        break;
    case 10:
        Object_TurnTowardSpike(o);
        if (Object_FallToFloor(o)) {
            o->f_8F++;
            Object_PlaySound(o, 0x45);
            if (o->f_8F < 2) {
                Object_SetVelY(o, -0x34);
            } else {
                func_800530D0(o);
            }
        }
        o->f_96 += 10;
        break;
    case 11:
        Object_ClampAnimFrame(o, o->f_88[o->f_7F].end);
        if (Object_DetachLink(o, 0) == 6) {
            o->f_E0 |= 1;
            Object_DisableCollision(o);
        }
        if (!(o->f_E0 & 1)) {
            o->f_B4 = Object_AddAttackSphereNear(o, 0x5F, o->f_1C, o->f_1E, o->f_20, 1, 0x202);
        }
        if (func_800572CC(o)) {
            o->f_80 = 0xC;
            o->f_7F = 3;
            o->f_5C = o->f_88[3].start;
            o->f_B0 = 0x5B;
            o->f_E0 &= ~1;
            o->f_A8 = 0x50;
            o->f_E0 &= ~0x10000;
            Object_EnableCollision(o);
            Object_PlaySound(o, 0x45);
            Object_SpawnEffect(o, 4, 0, 0, 0);
            o->f_44 = 0x5A;
            o->f_46 = 0xE4;
        }
        break;
    case 12:
        if (!(E2(o) & 1)) {
            Object_StepGrowShrink(o, 0, 0, 2);
            Object_SetForwardVelocity(o, o->f_A8 >> 3);
            Object_StepOnGroundFixed(o);
        }
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            func_80052ED4(o);
        }
        break;
    }
    if (o->kind == 0x49 && o->f_80 != 0xB && o->f_9C + 0x266 < o->y) {
        Object_Destroy(o);
    }
}



void func_800539B4(u8* arg0) {
    if (*(s16*)(arg0 + 0xA8) > 0) {
        if (*(s16*)(arg0 + 0xAA) == 0) {
            Object_PlaySound(arg0, 0xA1);
            *(s16*)(arg0 + 0xAA) = 1;
        }
    } else if (*(s16*)(arg0 + 0xAA) != 0) {
        *(s16*)(arg0 + 0xAA) = 0;
    }
}

void func_80053A1C(O_80053A1C_80053A1C *o, s32 on) {
    o->f_AE = 1;
    if (on) {
        if (o->f_B2 < 0x2AA) {
            o->f_B2 += 0x22;
        }
    } else {
        o->f_B2 -= 0x16;
        if (o->f_B2 < 0) {
            o->f_B2 = 0;
        }
    }
}

void func_80053A6C(void *arg0) {
    u16 temp_a1;

    temp_a1 = M2C_FIELD(arg0, u16 *, 0xA8) + 0xA;
    M2C_FIELD(arg0, u16 *, 0xA8) = temp_a1;
    if ((temp_a1 << 0x10) > 0) {
        M2C_FIELD(arg0, u16 *, 0xA8) = (u16) (temp_a1 + (M2C_FIELD(arg0, u8 *, 0x8F) * 0xA));
    }
    if ((s16) M2C_FIELD(arg0, u16 *, 0xA8) >= 0x191) {
        M2C_FIELD(arg0, u16 *, 0xA8) = 0x190U;
    }
}

void func_80053AC0(s32 arg0)
{
  s16 temp_v0;
  int new_var;
  if (Object_DetachLink(arg0, 0) == 6)
  {
    temp_v0 = *((s16 *) (((s8 *) arg0) + 0xA8));
    if (temp_v0 > 0)
    {
      new_var = -temp_v0;
      *((s16 *) (((s8 *) arg0) + 0xA8)) = (s16) new_var;
    }
  }
  else
  {
    *((s32 *) (((s8 *) arg0) + 0xB4)) = Object_AddAttackSphereNear(arg0, 0xA0, *((s16 *) (((s8 *) arg0) + 0x24)), (s16) ((*((u16 *) (((s8 *) arg0) + 0x28))) - 0x72), (s16) ((s32) (*((s16 *) (((s8 *) arg0) + 0x2C)))), (s32) (*((s16 *) (((s8 *) arg0) + 0x48))), (s32) (*((s16 *) (((s8 *) arg0) + 0x4A))));
  }
}

void Object_MoveTowardSpike(S_53B44_80053B44 *s, s32 speed)
{
  unsigned short new_var;
  SVEC_80053B44 v;
  new_var = g_Spike.f_24 - s->f_24;
  v.vy = 0;
  v.vx = new_var;
  v.vz = g_Spike.f_2C - s->f_2C;
  VectorNormalSS(&v, &v);
  s->f_94 = (v.vx * speed) >> 12;
  s->f_98 = (v.vz * speed) >> 12;
}

void func_80053BD8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 1;
    M2C_FIELD(arg0, s8 *, 0x7F) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) *M2C_FIELD(arg0, u16 **, 0x88);
    Object_HeadHome(arg0, 8, 0);
}

s32 func_80053C14(void *arg0) {
    if (((u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C) == 0xB) {
        if ((M2C_FIELD(Collision_GetShape((u16) M2C_FIELD(arg0, u32 *, 0x50) & 0xFFF), s16 *, 0x24) & 0xFF00) == 0x800) {
            func_800525E0(arg0);
            func_80052864(arg0);
            return 1;
        }
        func_8005744C(arg0, 0, 0x72, 0);
        Object_PlaySound(arg0, 0x67);
        M2C_FIELD(arg0, s16 *, 0xA8) = -0x140;
        M2C_FIELD(arg0, u8 *, 0x8F) = (u8) (M2C_FIELD(arg0, u8 *, 0x8F) + 1);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

void func_80053CB4(u8 *arg0)
{
  int new_var3;
  u8 *new_var;
  u16 *new_var2;
  arg0[0x80] = 3;
  new_var2 = (u16 *) ((*((u8 **) (arg0 + 0x88))) + 0xA);
  arg0[0x7F] = 2;
  new_var3 = (*new_var2) - 1;
  *((s16 *) (arg0 + 0xB2)) = 0;
  *((s16 *) (arg0 + 0xA8)) = 0;
  arg0[0x8F] = 0;
  new_var = arg0 + 0xAA;
  *((s16 *) new_var) = 0;
  *((s16 *) (arg0 + 0x5C)) = new_var3;
}

s32 func_80053CE8(S_53CE8_80053CE8 *s, s32 flag) {
    s32 id;
    if (Object_SpikeOutOfRange(s, s->f_9A, s->f_28, s->f_9E, s->f_A6) != 0) {
        return 0;
    }
    if (flag != 0) {
        s->f_80 = 2;
        s->f_7F = 5;
        s->f_5C = s->f_88[5].f_0;
    } else {
        func_80053CB4(s);
        s->f_AC = Math_Atan2(g_Spike.f_24 - s->f_24, g_Spike.f_2C - s->f_2C);
        s->f_60 = rcos(s->f_AC);
        s->f_64 = rsin(s->f_AC);
    }
    if ((s->f_E3 & 3) == 2) {
        Object_PlaySound(s, 0x6F);
    } else {
        Object_PlaySound(s, 0x63);
    }
    *(u32 *)((u8 *)s + 0xE0) &= ~0x1000;
    return 1;
}

void func_80053DE4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x80) = 8;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x1000);
}

/* func_80053DFC: default parameters of an object on its first update (func_80053E98): sizes, flags
 * and (kind 0x31) mode 2 in f_E0 bits 24-25. */
void func_80053DFC(S_53DFC_80053DFC *s) {
    s->f_A0 = 0x32;
    s->f_B0 = 0xB6;
    s->f_4A = 0x8202;
    s->f_44 = 0x64;
    s->f_46 = 0xE4;
    s->f_48 = 1;
    s->f_7C = -1;
    s->f_DC = 2;
    s->f_E0 &= ~0x1000;
    s->f_CD = 1;
    if (s->f_7E == 0x31) {
        s->f_E0 = (s->f_E0 & ~0x3000000) | 0x2000000;
    }
    s->f_80 = 9;
    s->f_7F = 4;
    s->f_5C = s->f_88[4].f_0;
}

void func_80053E98(Obj_53E98_80053E98 *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        func_80053DFC(o);
        o->f_E0 |= 8;
    }
    func_80058134(o, o->f_44);
    if (func_80053C14(o)) {
        return;
    }
    switch (o->f_80) {
    case 1:
        if (func_80055718(o, o->f_9A, (s16)o->y, o->f_9E, 8)) {
            o->f_80 = 9;
            o->f_7F = 3;
            o->f_5C = o->f_88[3].start;
            o->f_E0 &= ~0x1000;
        }
        Object_StepOnGroundFixed(o);
        break;
    case 9:
        if (o->f_7F == 3) {
            if (o->f_5C < o->f_88[o->f_7F].end) {
                break;
            }
            o->f_7F = 4;
            o->f_5C = o->f_88[4].start;
            o->f_8F = 0;
            func_8005588C(o, RAND() >> 8);
            break;
        }
        if (func_80053CE8(o, 1)) {
            break;
        }
        if (o->f_8F == 0) {
            o->f_5C = o->f_88[o->f_7F].start;
        } else if (o->f_5C == o->f_88[o->f_7F].end) {
            o->f_8F = 0;
            func_8005588C(o, RAND() >> 8);
        }
        if (!func_8005588C(o, -1)) {
            o->f_8F = 1;
        }
        break;
    case 2:
        if (o->f_5C >= o->f_88[o->f_7F].end) {
            func_80053CB4(o);
        }
        break;
    case 3:
        Object_SpawnEffect(o, 4, 0, 0, 0);
        func_80053A6C(o);
        Object_MoveTowardSpike(o, o->f_A8 >> 3);
        func_80053A1C(o, 1);
        func_800539B4(o);
        Object_ClampAnimFrame(o, o->f_88[o->f_7F].end);
        if (Object_WouldLeaveHome(o, 0x32)) {
            func_80053DE4(o);
        } else if ((s16)Object_StepOnGround(o, 0x40) == 0) {
            s32 sp = o->f_A8;
            o->f_A8 = -sp;
        }
        func_80053AC0(o);
        break;
    case 8:
        func_80053A1C(o, 0);
        if (o->f_B2 == 0) {
            o->f_80 = 6;
            o->f_7F = 2;
            o->f_5C = o->f_88[2].end - 2;
        }
        break;
    case 6:
        o->f_5C -= 2;
        if (o->f_88[o->f_7F].start >= o->f_5C) {
            func_80053BD8(o);
        }
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", jtbl_800A4FB0_pad);


void func_80054220(S_54220_80054220 *s) {
    u16 r;
    if (s->f_7F != 0) {
        return;
    }
    if (Object_SpikeWithin(s, 0x600) == 0) {
        return;
    }
    if (s->f_5C != s->f_88[s->f_7F].f_0 + 8) {
        return;
    }
    r = g_RandSeed * 5 + 1;
    g_RandSeed = r;
    if ((r >> 8) & 1) {
        Object_PlaySound(s, 0x70);
    } else {
        Object_PlaySound(s, 0x71);
    }
}

void func_800542C0(O_800542C0_800542C0 *o) {
    if (!((o->f_E0 >> 3) & 1)) {
        o->f_A0 = 0x32;
        o->f_B0 = 0x5B;
        o->f_44 = 0x5A;
        o->f_48 = 0x201;
        o->f_4A = -0x7EFD;
        o->f_46 = 0x1C;
        o->f_CD = 3;
        o->f_7F = 0;
        o->f_9C -= 200;
        o->f_28 = o->f_9C;
        o->f_5C = *o->f_88;
        func_80055F1C(o, 8);
        o->f_E0 |= 8;
    }
    func_80058134(o, o->f_44);
    if (o->f_80 == 1) {
        func_80055E6C(o, 8);
        Object_SeekHeight(o, 8);
        func_800563E0(o, 0x14);
    }
    func_80054220(o);
}

void func_800543B0(void) {
    switch (g_Game.f_8124) {
    case 6:
    case 33:
        func_8013D2BC();
        return;
    case 27:
        func_8013D630();
        return;
    case 17:
        func_801424D4();
        return;
    case 16:
        func_8013D7AC();
        return;
    default:
    func_80055328();
        return;
    }
}



void func_80054454(void) {
    switch (g_Game.f_8124) {
    case 5:
        func_8013F408();
        return;
    case 9:
        func_80140984();
        return;
    case 10:
        func_80141760();
        return;
    case 20:
        func_801405CC();
        return;
    case 21:
        if ((u16) g_Game.f_8126 < 0x3BU) {
            func_8013E150();
            return;
        }
        func_8013E074();
        return;
    case 29:
        func_8013E02C();
        return;
    default:
    func_80055328();
        return;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", jtbl_800A5048_pad);


void func_8005454C(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 11:
        func_8013F2E0();
        return;
    case 12:
        func_8013F460();
        return;
    case 13:
        func_80140348();
        return;
    default:
    func_80055328();
        return;
    }
}

void func_800545E8(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 21:
        func_8013F7E0();
        return;
    case 5:
        func_8013EF54();
        return;
    case 15:
        func_8013F08C();
        return;
    default:
    func_80055328();
        return;
    }
}

void func_8005467C(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 12:
        func_8013E778();
        return;
    case 13:
        func_8013FAEC();
        return;
    }
}

void func_800546DC(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 2:
        func_8013DF54();
        return;
    case 3:
        func_80140880();
        return;
    case 10:
        func_8014116C();
        return;
    case 9:
        func_8013F504();
        return;
    }
}

void func_80054780(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 12:
        func_8013FCE0();
        return;
    case 22:
        func_80141CFC();
        return;
    default:
    func_80055328();
        return;
    }
}

void func_800547F0(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 17:
        func_8013FB20();
        return;
    case 27:
        func_8013D810();
        return;
    }
}

void func_80054850(void) {
    switch (g_Game.f_8124) {
    case 8:
        func_8013DB38();
        return;
    case 9:
        func_801403E0();
        return;
    case 6:
    case 33:
        func_8013D714();
        return;
    case 17:
        func_80141FDC();
        return;
    case 27:
        func_8013EA6C();
        /* fallthrough */
    default:
        return;
    }
}



void func_800548F4(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 10:
        func_80140264();
        return;
    case 3:
        func_8013EED0();
        return;
    case 9:
        func_8013FF9C();
        return;
    case 15:
        func_8013D1BC();
        return;
    }
}

void func_80054998(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 33:
    case 8:
        func_8013D67C();
        return;
    case 9:
        func_8013E8B4();
        return;
    }
}

void func_80054A08(u32 *mask) {
    s32 i;
    for (i = D_800E77E0 - 1; i >= 0; i--) {
        if (((((S_E6960_80054A08 *)&g_Objects)[i].f_E0 >> 4) & 1) && (((S_E6960_80054A08 *)&g_Objects)[i].f_7E == 0x68 || ((S_E6960_80054A08 *)&g_Objects)[i].f_7E == 0x69)) {
            *mask &= ~(1 << ((S_E6960_80054A08 *)&g_Objects)[((S_E6960_80054A08 *)&g_Objects)[i].f_CA].f_CC);
        }
    }
}

void func_80054ABC(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 5:
        func_8013D484();
        return;
    case 20:
    case 33:
        func_8013FE8C();
        return;
    }
}

void func_80054B38(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 13:
        func_8013EFBC();
        return;
    case 29:
        func_8013E340();
        return;
    case 14:
    case 7:
        func_8013D770();
        return;
    }
}

void func_80054BCC(void) {
    if (g_Game.f_8124 == 0x14) {
        func_8013F4F4();
        return;
    }
    func_80055328();
}

void func_80054C1C(void) {
    if (g_Game.f_8124 == 0x1D) {
        func_80140800();
    }
}

void func_80054C5C(void) {
    switch (g_Game.f_8124) {
    case 3:
    case 33:
        func_8013FC98();
        return;
    case 15:
        func_8013EA38();
        return;
    case 7:
    case 14:
        func_8013DAEC();
        /* fallthrough */
    default:
        return;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", jtbl_800A5120_pad);


void func_80054CE0(void) {
    switch (g_Game.f_8124) {
    case 4:
        func_80140F9C();
        return;
    case 8:
        func_8013DE74();
        return;
    case 12:
        func_8013ED60();
        return;
    case 16:
        func_8013EB9C();
        return;
    case 29:
        func_8013E774();
        return;
    case 21:
        func_8013FA2C();
        /* fallthrough */
    default:
        return;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", jtbl_800A51A0_pad);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5210);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5220);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5230);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5240);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5250);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5260);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5270);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5280);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5290);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52A0);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52B0);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52C0);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52D0);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52D8);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52E8);


void func_80054D94(void) {
    if (g_Game.f_8124 == 0x11) {
        func_8013EA4C();
    }
}

void func_80054DD4(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 4:
        func_801407F8();
        return;
    case 20:
        func_8013DA5C();
        return;
    }
}

void func_80054E34(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 11:
        func_8013E38C();
        return;
    case 12:
        func_8013EF7C();
        return;
    }
}

void func_80054E94(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 11:
        func_8013EA18();
        return;
    case 12:
        func_8013D51C();
        return;
    case 13:
        func_8013ECD4();
        return;
    }
}

void func_80054F20(void) {
    if (g_Game.f_8124 == 4) {
        func_8013F71C();
    }
}

void func_80054F60(void) {
    if ((g_Game.f_8124 == 4) || (g_Game.f_8124 == 0x21)) {
        func_801402E8();
    }
}

void func_80054FA8(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 17:
        func_8013F740();
        return;
    case 10:
        func_8013E200();
        return;
    }
}

void func_80055000(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 33:
    case 4:
        func_801411B8();
        return;
    case 9:
        func_8013EAF8();
        return;
    case 17:
        func_8013FF2C();
        return;
    }
}

void func_8005508C(void) {
    if (g_Game.f_8124 == 0xA) {
        func_8013E6BC();
    }
}

void func_800550CC(void) {
    switch (g_Game.f_8124) { /* irregular */
    case 22:
        func_801407DC();
        return;
    case 21:
        func_8013EEB4();
        return;
    }
}

void func_80055124(void) {
    if (g_Game.f_8124 == 0x16) {
        func_801412FC();
        return;
    }
    func_80055328();
}

/* Defeated-object state: first frame sets it up (kind 0x43 gets a short bounce timer, others stop
 * colliding); once flagged (+0x50 top nibble 0xB) it calls the stage overlay's effect at its
 * position (0x8013D6B8 in stages 0x51/0x52, else 0x80141418), is destroyed, drops a pickup of
 * kind 2 and plays sounds 0x69/0x7A. */
void Object_DefeatedUpdate(Obj_55174_80055174 *o) {
    void (*fn)(s32, s32, s32);
    SV_55174_80055174 t;
    u32 e;
    u16 q;
    SV_55174_80055174 v;

    if (!((o->f_E0 >> 3) & 1)) {
        if (o->kind == 0x43) {
            o->f_CD = 1;
            o->f_A0 = 0x64;
            o->f_46 = 0x104;
            o->f_44 = 0x64;
            o->f_E0 &= ~0x1000;
        } else {
            o->f_A0 = 0;
            o->f_E0 = (o->f_E0 & ~0x1000) | 0x200;
        }
        if (o->f_8C != 0) {
            Object_PlaceAtPathPoint(o, 0);
            func_8005866C(o, 1);
        }
        o->f_7F = 0;
        q = *o->f_88;
        o->f_E0 |= 8;
        o->f_5C = q;
    }
    if ((o->f_50 >> 28) == 0xB) {
        if ((*(struct Game_55174 *)&g_Game).f_8126 == 0x51) {
            fn = D_8013D6B8;
        } else if ((*(struct Game_55174 *)&g_Game).f_8126 == 0x52) {
            fn = D_8013D6B8_52;
        } else {
            fn = D_80141418;
        }
        fn((s16)o->x, (s16)o->y, (s16)o->z);
        Object_Destroy(o);
        func_800A3740(&v, 0, 8);
        v.vx = o->x;
        v.vy = o->y - 0x40;
        v.vz = o->z;
        t = v;
        Pickup_Drop(2, &t, 2, 0);
        Object_PlaySound(o, 0x69);
        Object_PlaySound(o, 0x7A);
    }
}

void func_80055328(a)
S_55328_80055328 *a;
{
  u16 new_var;
  if (!((a->f_E0 >> 3) & 1))
  {
    u16 *q = a->f_88;
    a->f_A0 = 0x32;
    a->f_B0 = 0x5B;
    a->f_7F = 0;
    new_var = *q;
    a->f_E0 |= 8;
    a->f_5C = new_var;
  }
}

s32 Object_WouldLeaveHome(void *arg0, s16 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x9A) - (M2C_FIELD(arg0, s32 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94));
    temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x9E) - (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98));
    temp_v0 = M2C_FIELD(arg0, s16 *, 0xA6) + arg1;
    return (temp_v0 * temp_v0) < ((temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3));
}

void Object_CameraShake(void *arg0, M2C_UNK arg1) {
    if (!(((u32) M2C_FIELD(arg0, u32 *, 0xE0) >> 2) & 1)) {
        Camera_StartShake(arg1);
    }
}

void Object_PlaySound(S_55404 *a, s32 b) {
    S16x3 u;
    S16x3 t;
    t.x = a->unk24;
    t.y = a->unk28;
    t.z = a->unk2C;
    u = t;
    Sound_PlayAt(b, &u);
}

void Object_StepOnGroundFixed(void *arg0) {
    s16 temp_v0;

    temp_v0 = Object_FloorAt(arg0, M2C_FIELD(arg0, s16 *, 0x94), 0, M2C_FIELD(arg0, s16 *, 0x98));
    if (temp_v0 >= (M2C_FIELD(arg0, s32 *, 0x28) - 0x40)) {
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94));
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98));
    } else {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) & ~0x100);
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) temp_v0;
}

void Object_ApplyVelocity(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + M2C_FIELD(arg0, s16 *, 0x94));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x96));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s16 *, 0x98));
}

void Object_SetVelocityToward(void *arg0, void *arg1, s32 arg2, s16 arg3) {
    VectorNormalSS(arg1);
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 0) * arg2) >> 0xC);
    M2C_FIELD(arg0, s16 *, 0x96) = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 2) * arg2) >> 0xC);
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((s32) (M2C_FIELD(arg1, s16 *, 4) * arg2) >> 0xC);
    Object_TurnToward(arg0, M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 4), arg3, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
}

void Object_HeadTowardSpike(S_555D8_800555D8 *s, s32 b) {
    SVEC_800555D8 tmp;
    SVEC_800555D8 v;
    func_800A3740(&v, 0, 8);
    v.vx = g_Spike.f_24 - s->f_24;
    v.vz = g_Spike.f_2C - s->f_2C;
    tmp = v;
    Object_SetVelocityToward(s, &tmp, b, 0);
}

void Object_HeadHome(S_55674_80055674 *s, s32 a, s32 b) {
    SVEC_80055674 tmp;
    SVEC_80055674 v;
    func_800A3740(&v, 0, 8);
    v.vx = s->f_9A - s->f_24;
    v.vz = s->f_9E - s->f_2C;
    tmp = v;
    Object_SetVelocityToward(s, &tmp, a, b);
}

s32 func_80055718(S_O_80055718_80055718 *o, s32 x, s32 y, s32 z, s32 r) {
    SVECTOR w;
    SVECTOR v;
    func_800A3740(&v, 0, 8);
    v.vx = x - o->f_24;
    v.vy = y - o->f_28;
    v.vz = z - o->f_2C;
    w = v;
    if (w.vx * w.vx + w.vy * w.vy + w.vz * w.vz < r * r) {
        o->f_94 = w.vx;
        o->f_96 = w.vy;
        o->f_98 = w.vz;
        if (w.vx != 0 || w.vz != 0) {
            Object_TurnToward(o, w.vx, w.vz, 0, o->f_B0);
        }
        return 1;
    }
    Object_SetVelocityToward(o, &w, r, 0);
    return 0;
}

s32 func_8005588C(void *arg0, s32 arg1) {
    u8 temp_v0;

    if (arg1 < 0) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xC9);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8 *, 0xC9) = (u8) (temp_v0 - 1);
            return 1;
        }
        return 0;
    }
    M2C_FIELD(arg0, u8 *, 0xC9) = (u8) arg1;
    return 0;
}

s32 Object_SpikeInView3D(S_558C4_800558C4 *s, s32 ang, s32 lim) {
    SVECTOR v;
    if (Object_SpikeOutOfRange(s, s->f_9A, s->f_28, s->f_9E, s->f_A4) != 0) {
        return 0;
    }
    s->f_A2 = (ang << 12) / 360;
    v.vx = g_Spike.f_24 - s->f_24;
    v.vy = g_Spike.f_28 - s->f_28;
    v.vz = g_Spike.f_2C - s->f_2C;
    VectorNormalSS(&v, &v);
    return lim < (v.vx * s->f_60 + v.vy * s->f_62 + v.vz * s->f_64) / 4096;
}

void Object_StepOrbitAngle(S_559E8_800559E8 *s, s16 a) {
    if ((s->f_E0 >> 19) & 1) {
        s->f_AA = (s->f_AA - (a << 12) / 1440 + 0x1000) % 4096;
    } else {
        s->f_AA = (s->f_AA + (a << 12) / 1440) % 4096;
    }
}

s32 func_80055AA0(S_55AA0_80055AA0 *s, s32 tx, s32 tz, s32 r) {
    s32 rx = tx - (u16)s->f_24;
    s32 rz = tz - (u16)s->f_2C;
    s16 dx = rx;
    s16 dz = rz;
    Object_TurnToward(s, dx, dz, 0, s->f_B0);
    if (dx * dx + dz * dz < r * r) {
        s->f_94 = rx;
        s->f_98 = rz;
        if (dx == 0 && dz == 0) {
            return 1;
        }
        if (s->f_AE < 3) {
            s->f_AE = 0;
        }
        return 1;
    }
    Object_SetForwardVelocity(s, r);
    return 0;
}

s32 Object_SeekHeight(O_80055B9C_80055B9C *o, s16 speed)
{
  s16 d = o->f_28 - o->f_9C;
  if (((d >= 0) ? (d) : (-d)) <= speed)
  {
    o->f_96 = 0;
    o->f_28 = o->f_9C;
    return 1;
  }
  if (d > 0)
  {
    o->f_96 = -speed;
  }
  else
  {
    o->f_96 = speed;
  }
  return 0;
}

void Object_ChaseSpike(void *arg0, s16 arg1) {
    Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
    Object_SetForwardVelocity(arg0, arg1);
}

s32 func_80055C7C(void *arg0, s16 arg1)
{
  s8 *new_var;
  new_var = (s8 *) arg0;
  Object_TurnToward(arg0, (s16) ((*((u16 *) (((s8 *) arg0) + 0x24))) - (&g_Spike)->f_24), (s16) ((*((u16 *) (new_var + 0x2C))) - g_Spike.f_2C), 0, (s32) (*((s16 *) (new_var + 0xB0))));
  Object_SetForwardVelocity(arg0, arg1);
  if (Object_WouldLeaveHome(arg0, 0) == 0)
  {
    if (new_var || arg1)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  Object_HeadHome(arg0, (s32) arg1, (float) 0);
  return 0;
}

void func_80055D28(S_55D28_80055D28 *s, s16 a, s16 b) {
    s->f_96 = 0;
    s->f_94 = (((u16)(D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 3u >> 5) - 12;
    s->f_98 = (((u16)(D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) * 3u >> 5) - 12;
    Object_SetVelocityToward(s, &s->f_94, a, b);
}

s32 func_80055DC0(void *s, s16 a, s16 b) {
    u16 r;
    if (Object_WouldLeaveHome(s, 0) != 0) {
        Object_HeadHome(s, a, b);
        return 1;
    }
    r = g_RandSeed * 5 + 1;
    g_RandSeed = r;
    if (((r >> 8) & 0x1F) != 0) {
        return 0;
    }
    func_80055D28(s, a, b);
    return 1;
}

void func_80055E6C(void *arg0, s16 arg1) {
    s16 temp_s1;
    s16 temp_s2;

    temp_s2 = M2C_FIELD(arg0, u16 *, 0x9A) + ((s32) (rcos(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    temp_s1 = M2C_FIELD(arg0, u16 *, 0x9E) + ((s32) (rsin(M2C_FIELD(arg0, s16 *, 0xAA)) * M2C_FIELD(arg0, s16 *, 0xA6)) >> 0xC);
    Object_StepOrbitAngle(arg0, M2C_FIELD(arg0, u8 *, 0xDF));
    func_80055AA0(arg0, temp_s2, temp_s1, arg1);
}

/* func_80055F1C: random start angle (f_AA, 0..4095) and random flag 0x80000 for an object, and
 * f_DF = a * 396 / f_A6. */
void func_80055F1C(S_55F1C_80055F1C *s, s32 a) {
    int flags;
    if (s) {
        s->f_AA = ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8 << 12) / 255 % 4096;
        flags = (s->f_E0 & ~0x80000) | ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) << 19);
        s->f_DF = a * 3960 / (s->f_A6 * 10);
        s->f_E0 = flags;
    } else {
        s->f_AA = ((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8 << 12) / 255 % 4096;
        flags = (s->f_E0 & ~0x80000) | ((((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 1) << 19);
        s->f_DF = a * 3960 / (s->f_A6 * 10);
        s->f_E0 = flags;
    }
}

s16 func_80056010(O_80056010_80056010 *o, s16 a, s16 b, s32 off) {
    Seg_80056010_80056010 *e = (Seg_80056010_80056010 *)(o->f_7F * 4 + (s32)o->f_88);
    s32 len = e->end - e->start;
    s32 t = (((o->f_5C - e->start + off) % len) << 13) / len;
    s32 s = rsin((s16)((t + 0xC00) % 0x1000));
    return (s * (a - b) >> 13) + (a + b) / 2;
}

void func_80056128(S_56128_80056128 *s, s16 b)
{
  SVEC_80056128 d;
  d.vx = s->f_24 - s->f_9A;
  d.vy = 0;
  d.vz = s->f_2C - s->f_9E;
  if (((d.vx * d.vx) + (d.vz * d.vz)) < (s->f_A6 * s->f_A6))
  {
    d.vx = s->f_24 - g_Spike.f_24;
    d.vy = 0;
    d.vz = s->f_2C - g_Spike.f_2C;
    Object_SetVelocityToward(s, &d, b, 0);
  }
  else
  {
    s->f_94 = 0;
    s->f_98 = 0;
  }
}

void Object_SetForwardVelocity(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x94) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x60) * arg1) >> 0xC);
    M2C_FIELD(arg0, s16 *, 0x98) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x64) * arg1) >> 0xC);
}

void Object_OrbitAround(S_80056238_80056238 *m, s16 x, s16 z, s16 r, s16 a) {
    Object_StepOrbitAngle(m, a);
    m->f_24 = x + ((rcos(m->f_AA) * r) >> 12);
    m->f_2C = z + ((rsin(m->f_AA) * r) >> 12);
    if (m->f_E0.b19) {
        m->f_AC = (m->f_AA + 0xC00) % 0x1000;
    } else {
        m->f_AC = (m->f_AA + 0x400) % 0x1000;
    }
    m->f_60 = rcos(m->f_AC);
    m->f_64 = rsin(m->f_AC);
}

s32 Object_StepOnGround(S_56344_80056344 *s, s16 h) {
    s16 g = Object_FloorAt(s, s->f_94, 0, s->f_98);
    if (g >= s->f_28 - h) {
        s->f_28 = g;
        s->f_24 += s->f_94;
        s->f_2C += s->f_98;
        return 1;
    }
    s->f_E0 &= ~0x100;
    return 0;
}

s32 func_800563E0(void *arg0, s32 arg1)
{
  s8 *new_var;
  s16 temp_v0;
  new_var = (s8 *) arg0;
  *((s32 *) (new_var + 0x24)) = (s32) ((*((s32 *) (new_var + 0x24))) + (*((s16 *) (((s8 *) arg0) + 0x94))));
  *((s32 *) (new_var + 0x2C)) = (s32) ((*((s32 *) (new_var + 0x2C))) + (*((s16 *) (new_var + 0x98))));
  *((s32 *) (((s8 *) arg0) + 0x28)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x28))) + (*((s16 *) (new_var + 0x96))));
  temp_v0 = Object_FloorAt(arg0, 0, 0, 0);
  temp_v0 = temp_v0 - arg1;
  if ((*((s32 *) (((s8 *) arg0) + 0x28))) < temp_v0)
  {
    if (arg0 || new_var)
    {
      *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (new_var + 0xE0))) & (~0x100));
      return 1;
    }
    else
    {
      *((s32 *) (((s8 *) arg0) + 0xE0)) = (s32) ((*((s32 *) (new_var + 0xE0))) & (~0x100));
      return 1;
    }
  }
  *((s32 *) (((s8 *) arg0) + 0x28)) = (s32) temp_v0;
  return 0;
}

s32 Object_FallToFloor(S_5648C_8005648C *s) {
    s32 lim = (s16)Object_FloorAt(s, 0, 0, 0);
    s32 v = s->f_28 + s->f_96;
    if (v < lim) {
        s->f_28 = v;
        return 0;
    }
    s->f_28 = lim;
    return 1;
}

#define ABSDIFF_564EC(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))
typedef struct { u8 pad0[0xE0]; u32 flags; } Obj_800564EC;
extern s32 D_800EC208; /* g_Spike.y */

/* 1 if Spike is more than 0x600 above or below height y, or always with object flag bit 2. */
s32 Object_SpikeOutOfYRange(void *o, s32 y) {
    s32 r = 0;
    if ((((Obj_800564EC *)o)->flags >> 2) & 1 || ABSDIFF_564EC(D_800EC208, y) >= 0x601) {
        r = 1;
    }
    return r;
}

s32 Object_SpikeOutOfRange(void *s, s32 x, s32 px, s32 z, s16 r) {
    s32 ret = 0;
    if (Object_SpikeOutOfYRange(s, px) != 0 || (r != 0 && Spike_WithinRadiusXZ(x, z, r) == 0)) {
        ret = 1;
    }
    return ret;
}

s32 Object_IsFacingDir(S_565C4_800565C4 *s, s32 ang, s32 lim, s16 dx, s16 dz) {
    SVECTOR v;
    s->f_A2 = (ang << 12) / 360;
    v.vx = dx;
    v.vy = 0;
    v.vz = dz;
    VectorNormalSS(&v, &v);
    return lim < (v.vx * s->f_60 + v.vz * s->f_64) / 4096;
}

s32 Object_HomeSeesSpike(S_56674_80056674 *s, s32 a, s32 b) {
    if (Object_SpikeOutOfRange(s, s->f_9A, s->f_28, s->f_9E, s->f_A4) != 0) {
        return 0;
    }
    return Object_IsFacingDir(s, a, b, g_Spike.f_24 - s->f_24, g_Spike.f_2C - s->f_2C);
}

s32 Object_SpikeBehind(S_56714_80056714 *s, s32 a, s32 b, s16 r) {
    if (Object_SpikeOutOfRange(s, s->f_24, s->f_28, s->f_2C, r) != 0) {
        return 0;
    }
    return Object_IsFacingDir(s, a, b, s->f_24 - g_Spike.f_24, s->f_2C - g_Spike.f_2C);
}

s32 Object_SpikeInFront(S_56714_800567B8 *s, s32 a, s32 b, s16 r) {
    if (Object_SpikeOutOfRange(s, s->f_24, s->f_28, s->f_2C, r) != 0) {
        return 0;
    }
    return Object_IsFacingDir(s, a, b, g_Spike.f_24 - s->f_24, g_Spike.f_2C - s->f_2C);
}

void Object_TurnToward(S_8005685C *m, s16 dx, s16 dz, s16 off, s16 max)
{
  s32 d;
  s16 new_var;
  s32 sign;
  s32 step;
  s32 ad;
  d = (((Math_Atan2(dx, dz) + off) + 0x2000) % 0x1000) - m->f_AC;
  if (d != 0)
  {
    sign = (d > 0) ? (1) : (-1);
    step = d < 0;
    new_var = max;
    ad = d;
    if (step)
    {
      ad = -ad;
    }
    if (ad > 0x800)
    {
      ad = 0x1000 - ad;
      sign = -sign;
    }
    step = ad;
    if (ad >= new_var)
    {
      step = max;
    }
    m->f_B2 = sign * step;
    m->f_AE = ad / step;
  }
}

void Object_TurnTowardSpike(void *arg0) {
    Object_TurnToward(arg0, (s16) (g_Spike.f_24 - M2C_FIELD(arg0, u16 *, 0x24)), (s16) (g_Spike.f_2C - M2C_FIELD(arg0, u16 *, 0x2C)), 0, (s32) M2C_FIELD(arg0, s16 *, 0xB0));
}

s32 func_800569C4(s16 kind, s16 flag) {
    struct S_D_800E77D0_800569C4 *p = ((struct S_D_800E77D0_800569C4 *)&D_800E77D0);
    s32 n;
    s32 i;

    if (p->f_10 == 0) {
        return -1;
    }
    n = p->f_10;
    i = ((u16)(D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) % n;
    for (; n > 0; n--) {
        if (((struct S_D_800E6960_800569C4 *)&g_Objects)[i].f_7E == kind && ((struct S_D_800E6960_800569C4 *)&g_Objects)[i].f_E0.b4 == flag) {
            return i;
        }
        i = (i + 1) % ((struct S_D_800E77D0_800569C4 *)&D_800E77D0)->f_10;
    }
    return -1;
}

void func_80056AE4(S_56AE4_80056AE4 *s, s32 *pos, s32 k)
{
  s->f_E0.b4 = 1;
  if (pos != 0)
  {
    s->f_24 = pos[0];
    s->f_28 = pos[1];
    s->f_2C = pos[2];
  }
  else
  {
    s->f_24 = s->f_9A;
    s->f_28 = s->f_9C;
    s->f_2C = s->f_9E;
  }
  s->f_80 = 1;
  s->f_81 = 1;
  s->f_CA = k;
  s->f_E0.b3 = (s->f_5C = 0);
  s->f_7F = 0;
  s->f_E0.b1 = 0;
  if (s->f_E0.b14)
  {
    Collision_Set(4, &s->f_24, s);
    if (s->f_E0.b27)
    {
      func_8007CD88(&s->f_1C);
    }
  }
}

struct S_D_800E6960 *func_80056BC4(s16 id, s32 b, s16 c) {
    s16 k = func_800569C4(id, 0);
    if (k == -1) {
        return 0;
    }
    func_80056AE4(&g_Objects[k], b, c);
    return &g_Objects[k];
}

s16 Object_FloorAt(void *arg0, s16 arg1, s16 arg2, s16 arg3)
{
  s16 new_var;
  if (1)
  {
    if (!((((u32) (*((u32 *) (((s8 *) arg0) + 0xE0)))) >> 8) & 1))
    {
      new_var = Floor_GetHeight((*((s32 *) (((s8 *) arg0) + 0x24))) + arg1, (*((s32 *) (((s8 *) arg0) + 0x28))) + arg2, (*((s32 *) (((s8 *) arg0) + 0x2C))) + arg3);
      *((s32 *) (((s8 *) arg0) + 0xD0)) = (s32) (*((s32 *) 0x1F8003FC));
      *((s16 *) (((s8 *) arg0) + 0x86)) = new_var;
      *((u32 *) (((s8 *) arg0) + 0xE0)) = (u32) ((*((u32 *) (((s8 *) arg0) + 0xE0))) | 0x100);
    }
  }
  return *((s16 *) (((s8 *) arg0) + ((unsigned char) 0x86)));
}

void Object_PlaceRandomAroundHome(S_56CE0_80056CE0 *s, s16 r) {
    s32 c;
    s32 ang = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) << 12) / 255 % 4096;
    s->f_24 = s->f_9A + ((((s32 (*)(s32))rsin)(ang) * r) >> 12);
    c = ((s32 (*)(s32))rcos)(ang);
    s->f_28 = s->f_9C;
    s->f_2C = s->f_9E + ((c * r) >> 12);
}

/* Ramp o->size (+0xA8, in 1/8 units) between 0 and max*8. While flag 0x10000 (bit 0 of
   +0xE2) is set it grows by `up`; at the top the flag is cleared and it shrinks by `down`
   (negative). Reaching 0 sets the flag again and returns 1 (one full cycle). */
s32 Object_StepGrowShrink(Obj_80056DC4 *o, s16 max, s16 up, s16 down) {
    if (!(*(u16 *)((u8 *)o + 0xE2) & 1)) {
        o->size += down;
        if (o->size <= 0) {
            o->flags |= 0x10000;
            return 1;
        }
    } else {
        o->size += up;
        if (o->size > max * 8) {
            o->flags &= ~0x10000;
            o->size = max << 3;
        }
    }
    return 0;
}

void Object_SetAnim(S_80056E50_80056E50 *arg0, u8 arg1, u8 arg2)
{
  u8 prev = arg0->f_7F;
  S_Rec4_80056E50 *tbl = arg0->f_88;
  arg0->f_80 = arg1;
  arg0->f_7F = arg2;
  arg0->f_CE = prev;
  arg0->f_5C = tbl[arg2].f_0;
  arg0->f_7F = arg2;
}

s32 Math_WithinSquare(s32 arg0, s32 arg1, s32 arg2) {
    return ABS(arg0) < arg2 && ABS(arg1) < arg2;
}

s32 Object_SpikeWithin(O_56EAC_80056EAC *o, s32 d) {
    s32 r = 0;

    if (ABS2(D_800EC204 - o->f_24) < d && ABS2(D_800EC208 - o->f_28) < d && ABS2(D_800EC20C - o->f_2C) < d) {
        r = 1;
    }
    return r;
}

s32 Object_SpikeWithinXZ(S_56F6C_80056F6C *s, s32 r) {
    s32 ret = 0;
    if (ABS(g_Spike.f_24 - s->f_24) < r && ABS(g_Spike.f_2C - s->f_2C) < r) {
        ret = 1;
    }
    return ret;
}

s32 Object_SpikeNear(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (Object_SpikeOutOfRange((s32) arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0) {
        var_v0 = Object_SpikeWithin(arg0, arg1) != 0;
    }
    return var_v0;
}

s32 Object_SpikeNearXZ(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (Object_SpikeOutOfRange((s32) arg0, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0xA4)) == 0) {
        var_v0 = Object_SpikeWithinXZ(arg0, arg1) != 0;
    }
    return var_v0;
}

void Object_ClampAnimFrame(void *arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, u16 *, 0x5C) >= arg1) {
        M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (arg1 - 1);
    }
}

s32 Spike_WithinRadiusXZ(s32 x, s32 z, s32 r) {
    s32 dx = g_Spike.f_24 - x;
    s32 dz = g_Spike.f_2C - z;
    return dx * dx + dz * dz < r * r;
}

void *func_80057140(void *arg0, s16 arg1, s16 arg2) {
    void *temp_v0;

    if ((u8) D_800E77D0.f_23 < 0xAU) {
        temp_v0 = (void *)((u8 *)&D_800E7800 + (D_800E77D0.f_23 * 0xC));
        M2C_FIELD(temp_v0, s16 *, 8) = arg1;
        M2C_FIELD(temp_v0, s16 *, 0xA) = arg2;
        M2C_FIELD(temp_v0, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
        M2C_FIELD(temp_v0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
        M2C_FIELD(temp_v0, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
        D_800E77D0.f_23 = (u8) (D_800E77D0.f_23 + 1);
        return temp_v0;
    }
    return NULL;
}

void func_800571C4(m)
S_800571C4_800571C4 *m;
{
    s32 h;
    s32 spd;

    m->f_AC = (Math_Atan2(g_Spike.f_24 - m->f_24, g_Spike.f_2C - m->f_2C) + 0x1000) % 0x1000;
    m->f_60 = rcos(m->f_AC);
    m->f_64 = rsin(m->f_AC);
    spd = 50;
    m->f_96 = -((rsin(0x238) * spd << 1) >> 12);
    h = (rcos(0x238) * spd << 1) >> 12;
    m->f_E0.b5 = 0;
    m->f_E0.b10 = 1;
    m->f_94 = (m->f_60 * h) >> 12;
    m->f_98 = (m->f_64 * h) >> 12;
}

s32 func_800572CC(S_572CC_800572CC *s) {
    s32 r;
    s->f_96 += 7;
    r = func_80052688(s, func_8005278C(s));
    if ((s->f_E0 >> 5) & 1) {
        s->f_24 += s->f_94;
        s->f_2C += s->f_98;
        s->f_AC = (s->f_AC + 0x800) % 4096;
        s->f_60 = rcos(s->f_AC);
        s->f_64 = rsin(s->f_AC);
        s->f_E0 &= ~0x20;
        r = 0;
    }
    return r;
}

void func_800573A0(S_573A0_800573A0 *a, s32 dx, s32 dy, s32 dz) {
    s16 v[3];
    v[0] = a->f_24 + dx;
    dy += 0x80;
    v[1] = a->f_28 - dy;
    v[2] = a->f_2C + dz;
    func_8006B3CC(v);
}

void func_800573EC(s16 *p)
{
  S16x3_800573EC v;
  v.x = p[0] - ((struct S_D_800EC1E0_800573EC *)&g_Spike)->f_24;
  v.y = 0;
  v.z = p[2] - ((struct S_D_800EC1E0_800573EC *)&g_Spike)->f_2C;
  func_80070284(p, &D_800AF520, 1, 0, &v);
}

void func_8005744C(S_5744C_8005744C *s, s32 dx, s32 dy, s32 dz) {
    SVEC_8005744C tmp;
    SVEC_8005744C v;
    func_800A3740(&v, 0, 8);
    v.vx = s->f_24 + dx;
    v.vy = s->f_28 - dy;
    v.vz = s->f_2C + dz;
    tmp = v;
    func_800573EC(&tmp);
    Effect_SpawnAt(0x117, &tmp);
}

void Object_SpawnEffect(S_573A0_80057504 *a, s16 id, s32 dx, s32 dy, s32 dz) {
    s16 v[3];
    v[0] = a->f_24 + dx;
    v[1] = a->f_28 - dy;
    v[2] = a->f_2C + dz;
    Effect_SpawnAt(id, v);
}

/* A list of up to 2 functions (g_Hooks, count at D_800E77A0+5) run each frame by Hook_RunAll. */
void Hook_ClearAll(void) {
    s32 i;

    D_800E77A5 = 0;
    for (i = 1; i >= 0; i--) {
        g_Hooks[i].f_0 = 0;
    }
}

/* Adds `fn` to the hook list: 0 if full, 2 if already there, 1 when added. */
s32 Hook_Add(s32 x) {
    s32 i;
    if (D_800E77A0.f_5 >= 2) {
        return 0;
    }
    for (i = 1; i >= 0; i--) {
        if (g_Hooks[i].f_0 == x) {
            return 2;
        }
    }
    g_Hooks[D_800E77A0.f_5].f_0 = x;
    D_800E77A0.f_5++;
    return 1;
}

void Hook_RunAll(void) {
    s32 i;
    for (i = 0; i < ((struct S_D_800E77A0_8005760C *)&D_800E77A0)->count; i++) {
        ((void (*)(void))g_Hooks[i].f_0)();
    }
}

void func_80057680(void) {
}

/* Spawns object id from the spawner g_Objects[D_800E77A0.f_2] 4000 units above Spike's height:
 * if Spike is within the spawner's radius (+0xA4) of (x, z), at a random direction 400..655
 * from Spike; otherwise at a random point on the radius around (x, z). Counts successes in
 * D_800E77A0.f_1. */
void func_80057688(s32 id, s16 x, s16 z) {
    struct { s32 vx, vy, vz, pad; } pos;
    s16 ang;
    s32 r;
    s32 c;
    if (Math_WithinSquare(g_Spike.f_24 - x, g_Spike.f_2C - z, g_Objects[D_800E77A0.f_2].f_A4)) {
        ang = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) << 12) / 255 % 4096;
        r = ((u16)(D_800AE8F2 = D_800AE8F2 * 5 + 1) >> 8) + 400;
        pos.vx = g_Spike.f_24 + ((rsin(ang) * r) >> 12);
        c = rcos(ang);
        pos.vy = g_Spike.f_28 - 4000;
        pos.vz = g_Spike.f_2C + ((c * r) >> 12);
    } else {
        ang = (((u16)(g_RandSeed = g_RandSeed * 5 + 1) >> 8) << 12) / 255 % 4096;
        pos.vx = x + ((rsin(ang) * g_Objects[D_800E77A0.f_2].f_A4) >> 12);
        pos.vz = z + ((rcos(ang) * g_Objects[D_800E77A0.f_2].f_A4) >> 12);
        pos.vy = g_Spike.f_28 - 4000;
    }
    if (func_80056BC4(id, (s32)&pos, D_800E77A0.f_2)) {
        D_800E77A0.f_1++;
    }
}

/* While fewer than 3 have been spawned, a 1-in-16 chance per frame: if Spike is within the
 * spawner's +0xA6 range of its centre (+0x9A, +0x9E), drops object 0x23 near him
 * (func_80057688). The spawner is g_Objects[D_800E77A0.f_2], the count D_800E77A0.f_1. */
void func_8005793C(void) {
    u16 x = g_Objects[D_800E77A0.f_2].f_9A;
    u16 z = g_Objects[D_800E77A0.f_2].f_9E;
    if (D_800E77A0.f_1 < 3 && !(((g_RandSeed = g_RandSeed * 5 + 1) >> 8) & 0xF)) {
        if (Math_WithinSquare(g_Spike.f_24 - (s16)x, g_Spike.f_2C - (s16)z, g_Objects[D_800E77A0.f_2].f_A6)) {
            func_80057688(0x23, x, z);
        }
    }
}

void func_80057A28(void)
{
  s16 temp_a3;
  s32 temp_s2;
  u16 temp_v0;
  u16 temp_v0_2;
  u8 temp_v1;
  void *temp_s0;
  if (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 != 0)
  {
    ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 = (u16) (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 - 1);
  }
  if ((((u8) ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_1) < 3U) && (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 == 0))
  {
    temp_s0 = (void *) (((u8 *) (&g_Objects)) + (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_2 * 0xE4));
    temp_a3 = *((s16 *) (((s8 *) temp_s0) + 0x9A));
    temp_s2 = Vec_Length(((struct S_D_800EC1E0_80057A28 *)&g_Spike)->f_24 - temp_a3, 0, ((struct S_D_800EC1E0_80057A28 *)&g_Spike)->f_2C - (*((s16 *) (((s8 *) temp_s0) + 0x9E))), temp_a3);
    temp_v1 = *((u8 *) (((s8 *) temp_s0) + 0x7E));
    if (((*((u8 *) (((s8 *) temp_s0) + 0x7E))) == 0x2E) && (func_80056BC4(*((u8 *) (((s8 *) temp_s0) + 0x7E)), 0, ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_2) != 0))
    {
      temp_v0 = (D_800AE8F2 * 5) + 1;
      D_800AE8F2 = temp_v0;
      ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 = (u16) ((((s32) ((((u32) (temp_v0 & 0xFFFF)) >> 8) * 0xF)) >> 7) + 0x1E);
      ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_1 = (u8) (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_1 + 1);
      return;
    }
    if (((temp_s2 < (*((s16 *) (((s8 *) temp_s0) + 0xA4)))) && ((*((s16 *) (((s8 *) temp_s0) + 0xA6))) < temp_s2)) && (func_80056BC4(*((u8 *) (((s8 *) temp_s0) + 0x7E)), 0, ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_2) != 0))
    {
      if (((struct S_D_800EC350_80057A28 *)&g_Game)->f_8126 == 0x2C)
      {
        temp_v0_2 = (g_RandSeed * 5) + 1;
        g_RandSeed = temp_v0_2;
        ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 = (u16) ((((u32) (temp_v0_2 & 0xFFFF)) >> 8) + 0xF0);
      }
      else
      {
        ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_6 = 0U;
      }
      ((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_1 = (u8) (((struct S_D_800E77A0_80057A28 *)&D_800E77A0)->f_1 + 1);
    }
  }
}

void func_80057BF4(void) {
    struct S_D_800E77A0 *p = &D_800E77A0;
    if (p->f_6 != 0) {
        if (--p->f_6 != 0) {
            return;
        }
    }
    if (func_80056BC4(g_Objects[p->f_2].f_7E, 0, p->f_2) == 0) {
        return;
    }
    p->f_1++;
    p->f_6 = ((((u16)(D_800AE8F2 = D_800AE8F2 * 5 + 1)) >> 8) * 5U >> 5) + 40;
}

INCLUDE_ASM("asm/nonmatchings/game/80052D70_object", func_80057CB0);

void func_80057FD0(S_O_80057FD0_80057FD0 *o, s32 k, s32 v) {
    o->f_E0 |= 0x40000;
    switch (k) {
    case 0x6F:
        if (((struct S_D_800EC350_80057FD0 *)&g_Game)->f_8126 == 0x4C) {
            func_80051E98(o, 0);
        }
        break;
    case 0x23:
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_2 = v;
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_0 = 1;
        break;
    case 0x57:
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_2 = v;
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_0 = 4;
        break;
    case 0x2E:
    case 0x40:
    case 0x45:
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_2 = v;
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_0 = 2;
        break;
    case 0x3D:
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_2 = v;
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_0 = 3;
        break;
    case 0x1A:
        ((struct S_D_800E77A0_80057FD0 *)&D_800E77A0)->f_1++;
        break;
    default:
        o->f_E0 &= ~0x40000;
        break;
    }
}

void func_80058134() {
}

S_BD1A0_8005813C *Object_AddAttackSphere(S_5813C_8005813C *s, s16 a, s16 x, s16 y, s16 z, s16 e, s16 g) {
    S_BD1A0_8005813C *o = CollShape_Alloc();
    if (o != 0) {
        o->f_18 = s->f_60;
        o->f_0 = x;
        o->f_4 = y;
        o->f_8 = z;
        o->f_20 = a;
        o->f_22 = 0;
        o->f_24 = e;
        o->f_26 = g;
        Collision_Set(6, o, s);
    }
    return o;
}

s32 Object_AddAttackSphereNear(s, a, b, c, d, e, g)
    void *s;
    s16 a, b, c, d, e, g;
{
    if (Object_SpikeOutOfRange(s, b, c, d, a + 0x200) != 0) {
        return 0;
    }
    return Object_AddAttackSphere(s, a, b, c, d, e, g);
}

u32 Object_DetachLink(S_582EC_800582EC *s, s32 i) {
    u32 r;
    if (s->f_B4[i] == 0) {
        r = 0;
    } else {
        r = s->f_B4[i]->f_2C >> 28;
    }
    s->f_B4[i] = 0;
    return r;
}

void Object_AddAttackSphereAt(void *arg0, void *arg1, s16 arg2) {
    Object_AddAttackSphere(arg0, arg2, M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 2), (s32) M2C_FIELD(arg1, s16 *, 4), 0xB00, 0x200);
}

void func_8005836C(void *arg0, void *arg1, s16 arg2, s16 arg3) {
    Object_AddAttackSphere(arg0, arg2, M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 2), (s32) M2C_FIELD(arg1, s16 *, 4), 0x800, (s32) arg3);
}

void Object_SetPath(void *arg0, s32 arg1) {
    void *temp_a2;

    temp_a2 = D_800E77D8 + ((arg1 & 0xFFFF) * 8);
    M2C_FIELD(arg0, u16 *, 0x8C) = (u16) M2C_FIELD(temp_a2, u16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x90) = (s32) (g_Game.f_8244 + M2C_FIELD(temp_a2, s32 *, 4));
}

s16 func_80058400(S_58400_80058400 *a, u8 i, s8 mode, s16 d) {
    s16 *v = (s16 *)(a->f_90 + i * 8);
    if (mode == 1) {
        return func_80055718(a, v[0], v[1], v[2], d);
    }
    return func_80055718(a, v[0], a->f_28, v[2], d);
}

s32 Object_PathPointNear(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v0_2;
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x90) + ((arg3 & 0xFF) * 8);
    temp_v0 = M2C_FIELD(temp_a0, s16 *, 0) - M2C_FIELD(arg1, s32 *, 0);
    temp_v0_2 = M2C_FIELD(temp_a0, s16 *, 4) - M2C_FIELD(arg1, s32 *, 8);
    return ((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)) < (arg2 * arg2);
}

void func_800584C8(S_800584C8_800584C8 *m, s8 bounce) {
    if (!bounce) {
        if (m->f_E0.b6) {
            m->f_8E = (m->f_8E + m->f_8C - 1) % m->f_8C;
        } else {
            m->f_8E = (m->f_8E + 1) % m->f_8C;
        }
    } else if (m->f_E0.b6) {
        if (m->f_8E == 0) {
            m->f_E0.b6 = 0;
            m->f_8E = 1;
        } else {
            m->f_8E--;
        }
    } else {
        m->f_8E++;
        if (m->f_8E == m->f_8C) {
            m->f_E0.b6 = 1;
            m->f_8E = m->f_8C - 2;
        }
    }
}

s32 func_800585D0(void *arg0, s16 arg1, s8 arg2, s8 arg3)
{
  if ((func_80058400(arg0, (s32) (*((u8 *) (((s8 *) arg0) + 0x8E))), arg3, arg1) << 0x10) == 0)
  {
    if (arg0 || arg2)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  func_800584C8(arg0, (s32) arg2);
  return 1;
}

void Object_PlaceAtPathPoint(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x90) + ((s32) (arg1 << 0x10) >> 0xD);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v1, s16 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v1, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s16 *, 4);
}

void func_8005866C(void *arg0, s32 arg1)
{
  u16 new_var;
  s32 temp_v0;
  s32 temp_v1_2;
  s32 var_v0;
  void *temp_a0;
  void *temp_v1;
  temp_v1 = (*((s32 *) (((s8 *) arg0) + 0x90))) + (((s32) (arg1 << 0x10)) >> 0xD);
  temp_a0 = arg0 + 0x60;
  new_var = *((u16 *) (((s8 *) temp_v1) + 0));
  *((s16 *) (((s8 *) arg0) + 0x62)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x60)) = (s16) (new_var - (*((u16 *) (((s8 *) arg0) + 0x24))));
  *((s16 *) (((s8 *) arg0) + 0x64)) = (s16) ((*((u16 *) (((s8 *) temp_v1) + 4))) - (*((u16 *) (((s8 *) arg0) + 0x2C))));
  VectorNormalSS(temp_a0, temp_a0);
  temp_v0 = Math_Atan2(*((s16 *) (((s8 *) arg0) + 0x60)), *((s16 *) (((s8 *) arg0) + 0x64)));
  temp_v1_2 = temp_v0 + 0x1000;
  var_v0 = temp_v1_2;
  if (temp_v1_2 < 0)
  {
    var_v0 = temp_v0 + 0x1FFF;
  }
  *((s16 *) (((s8 *) arg0) + 0xAC)) = (s16) (temp_v1_2 - ((var_v0 >> 0xC) << 0xC));
}

s32 func_80058700(s32 a) {
    s32 i;
    if (a == 0) {
        return 0;
    }
    for (i = 0; i < D_800E77D0.f_10; i++) {
        if (((g_Objects[i].f_E0 >> 4) & 1) && ((g_Objects[i].f_E0 >> 14) & 1)) {
            func_80051E98(&g_Objects[i], 0);
        }
    }
    return 0;
}

s32 func_8005879C(s32 a) {
    s32 i;
    if (a == 0) {
        return 0;
    }
    for (i = 0; i < D_800E77D0.f_10; i++) {
        g_Objects[i].f_81 = a;
    }
    return 0;
}

void func_800587EC(void) {
    struct S_D_800AF590 *p = D_800AF590;
    D_800B00A4 = p;
    func_8007D23C(p++, &D_800E77E4[0], 0);
    DebugItem_Init(p++, &D_800E77E4[1], 0);
    p++;
    DebugItem_Init(p++, &D_800E77E4[2], 0);
    DebugItem_Init(p++, &D_800E77E4[3], 0);
    DebugItem_Init(p++, &D_800E77E4[7], 0);
    DebugItem_Init(p++, &D_800E77E4[0xD], 0);
    DebugItem_Init(p, &D_800E77E4[4], 0);
    func_8007D29C(p++, func_8005879C);
    DebugItem_Init(p++, &D_800E77E4[0xA], 0);
    DebugItem_Init(p++, &D_800E77E4[0xC], 3);
    DebugItem_Init(p++, &D_800E77E4[0xB], 0);
    p++;
    DebugItem_Init(p++, &D_800E77E4[5], 0);
    DebugItem_Init(p++, &D_800E77E4[6], 0);
    DebugItem_Init(p++, &D_800E77E4[8], 0);
    DebugItem_Init(p, &D_800E77E4[9], 0);
}

INCLUDE_ASM("asm/nonmatchings/game/80052D70_object", func_80058954);

INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A52F8);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5300);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5304);
INCLUDE_RODATA("asm/nonmatchings/game/80052D70_object", D_800A5308);


INCLUDE_ASM("asm/nonmatchings/game/80052D70_object", Debug_DrawWorldQuad);
