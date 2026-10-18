#include "game.h"
#include "m2c_macros.h"
#include "common.h"
#include "m2c_macros.h"
#include "game.h"
#include "common.h"
#include "game.h"
#include "common.h"
#include "game.h"
#include "common.h"
#include "game.h"
#define M ((S_M_80035474_80035474 *)g_CurMonkey)
#define M_3516C ((MR_8003516C_8003516C *)g_CurMonkey)
#define MR_3710C ((MR_8003710C_8003710C *)g_CurMonkey)
#define MD_42E18 ((MD_80042E18_80042E18 *)g_CurMonkey)
#define GM_42E18 ((struct Game_80042E18 *)&g_Game)
#define MV_405C4 ((MV_800405C4_800405C4 *)g_CurMonkey)
#define MD ((M_8003D9D4_8003D9D4 *)g_CurMonkey)
#define MS ((M_80037550_80037550 *)g_CurMonkey)
#define MSF ((M_80036CD0_80036CD0 *)g_CurMonkey)
#define MX ((M_80037908_80037908 *)g_CurMonkey)
#define KX ((K_80037908_80037908 *)g_MonkeyKinds)
#define LOST (((u8 *)&g_CurMonkey->f_248)[1])
#include "common.h"
#include "m2c_macros.h"
#include "game.h"
#define ABS(x) ((x) < 0 ? -(x) : (x))
#include "common.h"
#include "game.h"
#define G_GAME_80035918 ((struct g_Game_80035918 *)&g_Game)
#define M_3B674 ((MT_8003B674_8003B674 *)g_CurMonkey)
#define NODE_34EF8 (((S_Grp_80034EF8_80034EF8 *)D_800B4D00)[k])
#include "game.h"
#define MJ_3FD7C ((MJ_8003FD7C_8003FD7C *)g_CurMonkey)
#include "game.h"
#define CM ((M_39ED4_80039ED4 *)g_CurMonkey)
#define GDB ((Game_39ED4_80039ED4 *)&g_Game)
#define KIND(m) ((K_39ED4_80039ED4 *)&g_MonkeyKinds[(m)->f_7C])
#include "common.h"
#include "game.h"
#define M_39C38 ((ML_80039C38_80039C38 *)g_CurMonkey)
#include "common.h"
typedef struct { u8 pad0[0xF0]; s16 unkF0; u8 padF2[0x156]; u32 unk248; } S_4D08;
typedef struct { s32 vx, vy, vz, pad; } VEC_8003473C;
typedef struct { s32 vx, vy, vz, pad; } VEC_80034940;
typedef struct { s16 vx, vy, vz, pad; } SVEC;
typedef struct { s32 vx, vy, vz; } VEC3_8003455C;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC;
typedef struct { s32 vx, vy, vz, pad; } VEC_800345D4;
typedef struct { s32 vx, vy, vz, pad; } VEC_80034684;
typedef struct { s16 vx, vy, vz, pad; } SVEC_800347D8;
typedef struct { s32 vx, vy, vz, pad; } VEC_800344C8;
typedef struct { s32 f_0; u8 pad_4[0x14]; } S_Rec18b_800349F4;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8003B534;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_8003B534;
typedef struct { s16 f_0; s16 f_2; s32 f_4; s32 f_8; } S_Pair_8003B880_8003B880;
typedef struct { s32 vx, vy, vz, pad; } VEC_80034684_8004002C;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_8004002C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8003AC54;
typedef struct { u8 pad0[0x176]; s16 f_176[8]; } S_176_8003AC54_8003AC54;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_8003AC54;
typedef struct { u8 pad0[0x20C]; s32 f_20C; u8 pad210[0x1C]; u16 f_22C; } S_M_80034A2C_80034A2C;
typedef struct { u8 pad0[0xC]; s16 f_C[7]; s16 f_1A; } S_Kind_800361B4_800361B4;
typedef struct { u8 pad0[0x70]; u32 f_70; } S_70_800361B4_800361B4;
typedef struct { u8 pad0[0x80]; s16 f_80; s16 f_82; } S_80_800393E4_800393E4;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80035BD0;
typedef struct { u8 pad0[0x50]; s32 f_50; u8 pad54[0x68]; s32 f_BC; s32 f_C0; s32 f_C4; } S_BC_80035BD0_80035BD0;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_80035474;
typedef struct { s32 vx, vy, vz, pad; } VEC_80034684_80035474;
typedef struct { u8 pad0[0xBC]; VEC_80040CFC_80035474 f_BC; u8 padCC[0x148]; s32 f_214; s32 f_218; u8 pad21C[0xC]; u32 f_228; u8 pad22C[2]; u8 f_22E; u8 pad22F[0x1C]; u8 f_24B; } S_M_80035474_80035474;
typedef struct { u8 pad0[0x98]; s16 f_98; } S_M98_8003F18C_8003F18C;
typedef struct { u8 pad0[0x98]; s16 f_98; } S_M98_8003F308_8003F308;
typedef struct { s32 x, y, z, pad; } V4_80037E8C_80037E8C;
typedef struct { s32 x, y, z, pad; } V_800424D4_800424D4;
typedef struct { u8 pad0[0x78]; u8 state; u8 pad79[0x79]; u16 spot; u8 padF4[0x120]; s32 f_214; s32 f_218; u8 pad21C[4]; s16 range; u8 pad222[6]; u32 f_228; } MR_8003516C_8003516C;
typedef struct { u8 pad0[0x1E]; u16 chance; u16 pad20; s16 min; s16 max; } React_8003710C_8003710C;
typedef struct { u8 pad0[0x88]; } Kind_8003710C_8003710C;
typedef struct { u8 pad0[0x5C]; u16 f_5C; u8 pad5E[0x1A]; u8 state; u8 pad79[3]; u8 kind; u8 pad7D; u16 f_7E; u8 pad80[0x16]; s16 f_96; u8 pad98[0x90]; s16 f_128; u8 pad12A[0x42]; u16 f_16C_lo; u16 f_16E; u16 f_170; u16 f_172; u16 f_174; u8 pad176[0x96]; s32 dist; u8 pad210[0x12]; u8 f_222; } MR_8003710C_8003710C;
typedef struct { u32 lo : 21; u32 b21 : 1; u32 hi : 10; } MB_80042E18_80042E18;
typedef struct { u8 pad0[0x7A]; u8 f_7A; u8 pad7B[0xD9]; s32 f_154; s16 f_158; u8 pad15A[0xEE]; MB_80042E18_80042E18 f_248; u8 pad24C[4]; } MD_80042E18_80042E18;
typedef struct { u32 lo : 28; u32 seen : 1; u32 near : 1; u32 hi : 2; } MBits_800405C4_800405C4;
typedef struct { u8 pad0[0x78]; u8 state; u8 pad79[3]; u8 kind; u8 pad7D[0x18F]; s32 dist; u8 pad210[0xC]; u32 angle; u8 pad220[0x28]; MBits_800405C4_800405C4 bits; } MV_800405C4_800405C4;
typedef struct { u8 pad0[0xC]; s16 range[7]; s16 f_1A; u8 pad1C[0x6C]; } Kind_800405C4_800405C4;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_8003D9D4;
typedef struct { u8 pad0[0x60]; SVECTOR f_60; u8 pad68[0x2C]; s16 f_94; u8 pad96[6]; u8 f_9C[0x20]; s32 f_BC; s32 f_C0; s32 f_C4; u8 padC8[0x58]; s16 f_120; } M_8003D9D4_8003D9D4;
typedef struct { u8 pad0[0x78]; u8 state; u8 f_79; u8 pad7A[0x1A]; s16 f_94; u8 pad96[0x56]; s16 f_EC; u8 padEE[0x11E]; s32 f_20C; u8 pad210[0x12]; s8 f_222; u8 pad223[5]; u32 f_228; u8 pad22C[0x1C]; u32 f_248; } M_80037550_80037550;
typedef struct { u8 pad0[0x78]; u8 state; u8 pad79[0x1B]; s16 f_94; u8 pad96[0x56]; s16 f_EC; u8 padEE[4]; u16 f_F2; u16 f_F4; u8 padF6[0x122]; s32 f_218; u8 pad21C[0xC]; u32 f_228; u8 pad22C[0x1C]; u32 f_248; } M_80036CD0_80036CD0;
typedef struct { u8 pad0[0x78]; u8 state; u8 f_79; u8 pad7A[2]; u8 kind; u8 pad7D[0x17]; s16 f_94; u8 pad96[0x56]; s16 f_EC; u8 padEE[0x11E]; s32 f_20C; u8 pad210[0x12]; s8 f_222; u8 pad223[5]; u32 f_228; u8 pad22C[0x1C]; u32 f_248; } M_80037908_80037908;
typedef struct { u8 pad0[2]; s16 f_2; s16 f_4; u8 pad6[2]; s16 f_8; u8 padA[4]; s16 f_E; u8 pad10[2]; s16 f_12; u8 pad14[0x74]; } K_80037908_80037908;
typedef struct { s32 vx, vy, vz, pad; } VEC_80035370_80035370;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_80040BDC;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_8003CC3C;
typedef struct { u8 pad0[0xF2]; u16 f_F2; u16 f_F4; u16 f_F6; u16 f_F8; u16 f_FA; u16 f_FC; } M_35604_80035604;
typedef struct { u8 pad0[0x78]; u8 f_78; u8 pad79[0xAB]; s16 f_124; s16 f_126; u8 pad128[0x100]; s32 f_228; } M_392F0_800392F0;
typedef struct { u8 pad[0x4078]; } Db_39E50_80039E50;
typedef struct { u8 pad0[0xC]; s32 cur; u8 pad10[0x70]; Db_39E50_80039E50 db[2]; } Game_39E50_80039E50;
typedef struct { u8 pad0[4]; u16 f_4; } Hdr_39E50_80039E50;
typedef struct { Hdr_39E50_80039E50 *hdr; } Model_39E50_80039E50;
typedef struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x48]; u8 f_78; u8 f_79; u8 f_7A; u8 f_7B; u8 f_7C; u8 pad7D[3]; s16 f_80; s16 f_82; u8 pad84[0x6C]; s16 f_F0; u8 padF2[0x36]; u16 f_128; u8 pad12A[0x36]; s32 f_160; u8 pad164[4]; u16 f_168; u8 pad16A[0xBE]; u32 f_228; u8 pad22C[0x1C]; u32 f_248; } M42B68_80042B68;
typedef struct { s16 a; s16 b; u32 flags; u8 pad8[4]; } Pair_8003B674_8003B674;
typedef struct { u8 pad0[0x4A]; s16 f_4A; u8 pad4C[0xA0]; s16 f_EC; u8 padEE[0x136]; s16 f_224; s16 f_226; u32 f_228; u8 pad22C[0x1C]; u32 f_248; } MT_8003B674_8003B674;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_80034EF8;
typedef struct { u32 f_0; s16 f_4; s16 f_6; s16 f_8; u8 padA[6]; s16 f_10; u8 pad12[6]; } S_Grp_80034EF8_80034EF8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; u8 padA[0x2E]; } S_820C_80034EF8_80034EF8;
typedef struct { u16 start; u16 end; u8 pad[4]; } AE_8003FD7C_8003FD7C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u8 pad5E[0x1A]; u8 state; u8 pad79[0x1D]; s16 t; u8 pad98[0x90]; u16 dur; u8 pad12A[6]; s32 y0; u8 pad134[0xC]; s32 vy; u8 pad144[0x28]; AE_8003FD7C_8003FD7C *anims; u16 f_170; u16 f_172; } MJ_8003FD7C_8003FD7C;
typedef struct { s32 x, y, z, pad; } V4_800386C8_800386C8;
typedef struct { u8 draw[0x5C]; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } Db_39ED4_80039ED4;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; Db_39ED4_80039ED4 db[2]; } Game_39ED4_80039ED4;
typedef struct { u8 pad0[0x8126]; u16 f_8126; } GameS_39ED4_80039ED4;
typedef struct { u8 pad[0x10]; } Model_39ED4_80039ED4;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0x48]; SVECTOR rot; u8 pad68[0x10]; u8 f_78; u8 f_79; u8 f_7A; u8 f_7B; u8 f_7C; u8 pad7D[0x13]; u16 f_90; u8 pad92[0x43]; u8 f_D5; u8 padD6[0x1A]; s16 f_F0; u8 padF2[0x5A]; s32 f_14C; u8 pad150[0x10]; s32 f_160; u8 pad164[0xE6]; u16 f_24A; } M_39ED4_80039ED4;
typedef struct { u16 f_0; u8 pad2[0x1A]; struct { u16 f_0; u16 f_2; u8 pad4[4]; } parts[8]; } K_39ED4_80039ED4;
typedef struct { s16 f_0; s16 f_2; u8 pad4[4]; } R_39ED4_80039ED4;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x48]; u8 state; u8 pad79[0x5C]; u8 lod; u8 padD6[0x76]; s32 alert; s16 flash; } ML_80039C38_80039C38;
typedef struct { s32 x, y, z, pad; } V4_3DC7C_8003DC7C;
typedef struct { s16 vx, vy, vz, pad; } SV_3DC7C_8003DC7C;
typedef struct { u16 f_0; u16 f_2; u8 pad4[4]; } An_3DC7C_8003DC7C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; u8 pad30[0x2C]; u16 f_5C; u8 pad5E[2]; SV_3DC7C_8003DC7C f_60; u8 pad68[0x10]; u8 state; u8 f_79; u8 pad7A[2]; u8 f_7C; u8 pad7D[7]; s16 f_84, f_86, f_88; u8 pad8A[0xC]; s16 f_96; u8 pad98[2]; s16 f_9A; u8 pad9C[0x20]; V4_3DC7C_8003DC7C goal; u8 padCC[0x17]; u8 f_E3; s16 f_E4; u8 padE6[0xC]; u16 f_F2; u16 f_F4; u8 padF6[0x76]; An_3DC7C_8003DC7C *f_16C; u8 pad170[0x9C]; s32 f_20C; u8 pad210[0xC]; u32 f_21C; u8 pad220[2]; s8 f_222; u8 pad223[5]; u32 f_228; u16 f_22C; u8 pad22E[0x1A]; union { u32 w; u8 b[4]; } f_248; } M_3DC7C_8003DC7C;
typedef struct { u16 on; u16 pad; s16 min, max; } Atk_3DC7C_8003DC7C;
typedef struct { u8 pad0[0x1E]; Atk_3DC7C_8003DC7C atk[8]; u8 pad5E[0x2A]; } K_3DC7C_8003DC7C;
typedef struct { u32 f_0; u8 pad4[0xC]; s16 f_10; u8 pad12[6]; } Nd_3DC7C_8003DC7C;
typedef struct { s16 x, y, z; u8 pad[0x32]; } Pt_3DC7C_8003DC7C;
typedef struct { s32 x, y, z; } V_3581C_8003581C;
typedef struct { u8 pad0[0x4A]; s16 f_4A; u8 pad4C[0x2C]; u8 f_78; u8 pad79[3]; u8 f_7C; u8 pad7D[0x11]; s16 f_8E; u8 pad90[0x62]; s16 f_F2; s16 f_F4; u8 padF6[0x66]; s32 f_15C; u8 pad160[0xD0]; s32 f_230; s32 f_234; s32 f_238; s32 f_23C; s16 f_240; u8 pad242[6]; u32 f_248; } M_3581C_8003581C;
typedef struct { s32 vx, vy, vz, pad; } VEC_80040CFC_800364BC;

s32 Monkey_EnableCollision(void);

void memset(void *, s32, s32);
void Square0(VEC_8003473C *, VEC_8003473C *);
s32 SquareRoot0(s32);
extern s16 D_800EC2CA;
extern struct S_D_800AEBB4 { s32 f_0; u32 f_4; } D_800AEBB4[];
/* Tries reaction `kind` for the current monkey: its kind's entry gives a chance and a distance
 * band; if the target is inside the band and a roll out of 100 succeeds, the monkey switches to
 * the reaction's state (D_800AEBB4[kind]). Reaction 1 then has a 90-frame cooldown (+0x174);
 * 0 and 5 adjust the animation start; 7 also calls Monkey_QueueSound. Returns 1 if it reacted. */
s32 Monkey_TryReaction(s16 kind);

M2C_UNK ApplyMatrixSV(void *, s32, void *);
M2C_UNK func_80014804(void *, s32);
M2C_UNK func_80015780(void *, M2C_UNK);
extern M2C_UNK g_Objects;
extern M2C_UNK D_800F4750;

extern struct S_D_800E6780 { s32 f_0; s16 f_4; s16 pad6; s32 f_8; s32 f_C; s32 f_10; } D_800E6780[];
void VectorNormal(VEC_80034940 *, VEC_80034940 *);

void VectorNormalSS(SVEC *, SVEC *);
void func_80033E4C(s16);

extern s16 D_800AEB5A;

M2C_UNK Collision_Remove(void *);
M2C_UNK func_8007CDC4(void *);
s32 ratan2();

extern struct S_D_800EC350 { u8 pad_0[0x8122]; u16 f_8122; u8 pad_8124[0x2]; u16 f_8126; u8 pad_8128[0x118]; s32 f_8240; } g_Game;
extern void *D_800B4D14;
extern struct S_D_800E5500 { u8 pad_0[0x16C]; void * f_16C; } g_Monkeys;

void func_80039248();
/* For the current monkey: if its state (f_78) is flagged as animation-timed in D_800AE940,
 * returns 1 while the frame counter f_5C has not passed the animation entry's length;
 * otherwise returns 1 once the timer f_128 has reached f_96. */
s32 Monkey_CheckStateTimer(void);
void func_80036300(void);
void Monkey_RestartAnim();
void func_800355DC(void);
void func_80036B24(void);
s32 func_8003B880(s16 a, s16 b, s32 *out);

s32 Monkey_DisableCollision(void);
void func_8003929C(void);
void func_80036174(void);

s32 func_800356C0();
void func_80038F00(void);

extern s32 g_ActiveMonkeys[];

extern u32 D_800B4D10;
void Monkey_QueueSound(s32 a, s32 b);
void Monkey_FireShot(s32 k);
void func_80035370(void);
void func_80035474(void);
void Monkey_SetState(int arg0);
s32 func_800339EC(void);
void Monkey_SetFacingDir(s16 dir);
void func_80036B78(void);
M2C_UNK Fx_DebrisExplosion(s16, s16, s16);
/* Picks the current monkey's next action (called from many state handlers). Skipped while flag
 * bit 20 of +0x248 is set. If func_800339EC (target noticed) and game +0x812C is not 3 it goes
 * to / stays in state 0xB. Otherwise it marks +0x79, may leave with Monkey_RestartAnim (state 0xB with
 * the target 300..1500 away, or states flagged 8 in D_800AE940 with +0x222 > 0), lets
 * Monkey_TrySpecialAction take over, and else picks state 3, or 8 with 30% chance (never right after 8,
 * 0x23, 0x39 or while turning, +0x94). Walking monkeys (0xC, 0x24) then call func_80039248. */
void Monkey_PickNextAction(void);
/* Next action for a monkey that has not noticed its target (otherwise Monkey_PickNextAction).
 * Clears +0x79, then: states flagged 8 in D_800AE940 with +0x222 > 0 -> Monkey_RestartAnim; a special
 * trait action (Monkey_TrySpecialAction); kinds with no move speeds (g_MonkeyKinds +2/+4 == 0)
 * either func_80036300 (target within +0x12 or kind's +8 percent chance) or state 0; otherwise
 * state 2 while turning, 0x18 after 0x19, func_80036300 by chance, rarely 0x27/0x28 from state 2,
 * 0x18/0x19 by distance (+0xE) if it had just been alerted, 9% func_8003641C, else state 2.
 * Walking monkeys (0xC, 0x24) then call func_80039248. */
void Monkey_PickIdleAction(void);
void *Collision_GetShape(s32);
extern struct S_D_800AE940 { s32 f_0; u32 f_4; } D_800AE940[];
s32 Monkey_CurAnimIndex(void);
s32 Vec_AngleBetweenXZ(VEC_800344C8 *a, VEC_800344C8 *b);
void Sound_PlayAt(s32, s16 *);
void Effect_SpawnAt(s32, s16 *);
s32 func_80033B10(void);
s32 Vec_Dist(VEC_80034684 *a, VEC_80034684 *b);
s32 func_8003455C(void);
void Node_GetPosition(u16 k, VEC_80040CFC_80034EF8 *out);
s32 func_80040BDC(VEC_80040CFC_80040BDC *a, VEC_80040CFC_80040BDC *b);
void Monkey_AimAtGoal(void);
s32 func_80033C34(void);
s32 func_80033BE0(void);
u32 Monkey_Rand(void);
void func_80059304(s16 *, Monkey *, s32, s16 *);
extern struct S_D_800F4730 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800F4730[];
extern u32 D_800AEB60;
s32 func_80033C00(void);
s32 Monkey_AnimJustStarted(void);
u8 Monkey_ChooseRoute(s16, s16);
extern s32 g_CameraTarget;
extern u8 D_800E6908;
s32 Vec_DistXZ_SV(VEC_800345D4 *a, SVECTOR *b);
void func_80015AC0(void *, void *);
struct S_D_800EC350_8003A33C { u8 pad0[0x81A4]; void *f_81A4[4]; };
struct S_D_800EC350_8003317C { u8 pad_0[0x816C]; s8 f_816C[8]; };
struct S_D_800EC350_80033220 { u8 pad_0[0x81B4]; s32 f_81B4; s32 f_81B8; u8 pad_81BC[0x84]; s32 f_8240; };
s32 Node_LinkFlag(s16 n, s16 v);
void Monkey_SwapPathNodes(void);
s32 func_8003B534(s16 *a, s16 *b);
s32 rcos(s32);
extern u16 D_800AEB6C[];
s16 SVec_DotXZ(SVEC *a, SVEC *b);
extern S_Pair_8003B880_8003B880 *D_800B4D1C;
extern s16 D_800B4D20;
void Monkey_GoToNode(s16);
s32 Node_GetLink(s16, s16);
void Monkey_StartLink(s16, s16);
s32 Monkey_NodeEvents(s16);
s32 func_80052C4C(s16);
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void func_8006B3CC(SVEC_80035BD0 *);
s32 Vec_DistXZ(VEC_8003473C *a, VEC_8003473C *b);
/* Whether the current monkey sees its target: within the kind's sight distance for what the target
 * is doing (+0xC range[mode], or +0x1A), always in states 3 and 8 or when the target's mode is 7,
 * else inside the angle window for `dir` and with line of sight (func_800401F4). Writes the
 * result into flag bits 28 and 29 of +0x248. */
s32 Monkey_CanSeeTarget(u32 dir);
s32 func_8003398C(void);
void func_800357E0(void);
struct S_D_800AE940_8003F18C { u32 f_0; u32 f_4; };
/* Runs the current monkey's special behaviour, chosen by its trait flags (+0x228) in priority
 * order: 0x100 func_800359F0, 0x800 on a spot flagged 0x200 func_8003581C, 0x20 func_80035FBC,
 * 0x20000 func_80035F8C, 8 state 0xA, 4 func_8003601C, 0x10 func_80035F1C/F54, 1 func_80035A7C,
 * 0x10000 func_80036964, 0x800000 func_800360D8, 0x1000000 in state 0x3D func_8003612C; an idle
 * (state 3) monkey that has not noticed the target also gets func_80035A7C 10% of the time
 * between unflagged spots when +0x218 is 300..800. Returns 1 if something ran (0 while flag
 * bit 22 of +0x248 is set). */
s32 Monkey_TrySpecialAction(void);
s32 Floor_GetHeight(s32, s32, s32);
void func_80035DD8(void);
struct Game_800332F8 { u8 pad0[0x816C]; u8 f_816C[8]; };
void Object_SetFlagCF(s16, s32);
void func_80052D04(s16, s32 *);
s32 func_800335D0(s32 idx);
/* 1 if the current monkey's target is within its detection range. The range (+0x220) is doubled
 * in states 0xC and 0x24, x1.5 in state 9, and halved on stage 0x4D or 0x1A while the monkey's
 * spot (+0xF2) is one of a fixed list. Compares against distance +0x218 when flag 2 of +0x228
 * is set, else +0x214. */
s32 Monkey_IsTargetInRange(void);
s32 Monkey_PickGoalLink(s16 force);
s32 Monkey_CheckRouteAway(void);
struct Game_800424D4 { u8 pad0[0x8184]; s16 f_8184; };
struct Spike_800424D4 { u8 pad0[0xF2]; s8 f_F2; };
extern M2C_UNK g_Spike;
extern u8 g_MonkeyTargetIsRC;
extern s16 D_800AEB66;
extern M2C_UNK g_RcCar;
void func_8003AD9C(void);
void func_8004086C(void);
void func_80039B30(void);
void Monkey_Update(void);
struct Game_8003516C { u8 pad0[0x8126]; u16 stage; };
s32 Monkey_AttackChance(s16);
s32 func_800339CC(void);
struct S_D_800AEBB4_8003710C { u8 mult; u8 state; u8 pad2[6]; };
struct Game_80042E18 { s32 frame; u8 pad4[0x80FC]; s32 f_8100; u8 pad8104[0x80]; s16 f_8184; };
extern u32 D_800AEB5C;
extern s16 D_800AEC10;
extern s16 D_800AEC12;
extern u8 D_800B4CF4;
s32 func_80033C80(void);
s32 Monkey_UpdateAll(void);
void Monkey_UpdateActive(void);
s32 func_8003A334(void);
void Monkey_UpdateQueuedSounds(void);
void Monkey_SelectActive(void);
struct Tgt_800405C4 { u8 pad0[0x70]; s32 f_70; };
s32 func_800401F4(s32);
void func_8003C204(void);
void func_8003C568(void);
struct Game_80037550 { u8 pad0[0x812C]; u8 f_812C; };
s32 func_8003738C(void);
s32 func_800359F0(void);
s32 func_8003581C(void);
void func_80035FBC(void);
void func_80035F8C(void);
void func_8003601C(void);
void func_80035F1C(void);
void func_80035F54(void);
s32 func_80035A7C(void);
s32 func_80036964(void);
void func_800360D8(void);
void func_8003612C(void);
s32 func_80033B9C(void);
void func_8003641C(void);
s32 Monkey_AvoidConeAngleAlt(void);
void func_80038054(s16 i);
void Monkey_ScoreLinks(s16 k);
void func_80038914(void);
s32 func_80038A1C(s16 a, s16 b);
s32 Monkey_PickNextNode(s16 any, s16 force);
s32 Monkey_IsPathLooping(void);
void func_800363E4(void);
void bios_printf(const char *, ...);
extern char D_800A499C[];
s32 func_80033000(void);
s32 func_80037420(void);
void func_8003429C(s16 k);
s32 func_80032F24(void);
s32 Monkey_AvoidConeAngle(void);
void func_800378C0(void);
extern char D_800A4900[];
s32 Math_Atan2Pos(s32 arg0, s32 arg1);
void RotMatrixYXZ(SVECTOR *, MAT_8003CC3C *);
extern Monkey *g_CurMonkey;
void Collision_Set(s32, void *, void *);
void func_8007CD88(void *);
u32 func_800392E4(void *arg0);
extern struct S_D_800E9C60 { u8 pad[0x20]; } D_800E9C60[];
extern u8 D_800E7D00[];
void Model_ProjectVerts(Model_39E50_80039E50 *, struct S_D_800E9C60 *, u8 *);
void func_80017CD4(Db_39E50_80039E50 *, u8 *, Model_39E50_80039E50 *);
struct g_Game_80035918 { u8 pad0[0x81B8]; s32 f_81B8; u8 pad81BC[0x84]; u8 *f_8240; };
struct D4D14_35918 { u8 pad0[0x1C]; s32 f_1C; };
void func_80034C08(s16 i, s16 *a, s16 *b, s16 *c, s16 *d);
extern struct S_D_800F4350 { u8 pad[0x126]; u16 f_126; } D_800F4350;
extern s16 D_800F4B30[];
extern u8 D_800AEB58;
extern u8 D_800A4BBC[];
extern s32 D_1F8003FC;
s32 Monkey_IsOffScreen(void);
void Monkey_UpdateLod(void);
void func_800880D0(s32, s32);
void func_8008C3C0(s32, s32);
void func_8008CBFC(void *, s32);
void Anim_BlendCurrentEntry(void);
void Shadow_Draw(void *, s32, s32, s32);
void Monkey_Draw(void);
void Monkey_StartNodeJump(void);
struct S_D_800EC350_80034EF8 { u8 pad0[0x820C]; S_820C_80034EF8_80034EF8 *f_820C; };
void Node_GetJointRef(s16 i, s16 *a, s16 *b, s16 *c);
extern R_39ED4_80039ED4 D_800AEBB4_[] asm("D_800AEBB4");
extern u8 D_800AEBF8[];
extern Model_39ED4_80039ED4 D_800F4630[];
extern Model_39ED4_80039ED4 D_800F46B0;
extern Model_39ED4_80039ED4 D_800EC0C0;
extern Model_39ED4_80039ED4 D_800EC180;
void Matrix_FromDirection(SVECTOR *, void *);
void ScaleMatrix(void *, s32 *);
void Model_CalcJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void func_80017D94(void *, u8 *, void *, s32);
void Monkey_UpdateHelmetLight(void);
void func_80039E50(Model_39E50_80039E50 *m);
s32 func_800882C4(s32, s32, s32);
s32 rsin(s32);
extern u8 D_800AEBF4;
s32 Monkey_GetAlertLevel(void);
void Monkey_DrawHelmetLight(SVECTOR *, s32, s32);
struct Game_3DC7C { u8 pad0[0x812C]; u8 f_812C; u8 pad812D[0xDF]; Pt_3DC7C_8003DC7C *f_820C; };
s32 func_80035750();
void func_80036460(void);
void func_80033DF0(void);
void func_800343B0(void);
void func_8003440C(void);
s32 func_800349F4(s16 arg0);
void func_8003CC3C(s32 lim);
struct S_D_800AE940_8003DC7C { u32 f_0; u32 flags; };
s32 func_8005B7BC(s32, s16 *);

u32 Monkey_Rand(void) {
    u32 temp_v0;

    temp_v0 = ((D_800B4D10 * 5) + 1) & 0xFFFF;
    D_800B4D10 = temp_v0;
    return temp_v0 >> 8;
}

u16 func_80032E58(void) {
    return g_MonkeyKinds[D_800AEB5A].f_0;
}

s32 Monkey_CurAnimIndex(void) {
    Monkey *m = g_CurMonkey;
    if ((m->f_78 == 3 || m->f_78 == 8) && g_MonkeyKinds[m->f_7C].f_4 == 0) {
        return 0;
    }
    m = g_CurMonkey;
    if (m->f_78 >= 0x32 && m->f_78 < 0x35) {
        return m->f_242;
    }
    return D_800AE940[m->f_78].f_0;
}

s32 func_80032F24(void) {
    Monkey *m;
    if (g_CurMonkey->f_D4 > 0) {
        g_CurMonkey->f_D4--;
    }
    m = g_CurMonkey;
    if (D_800B4D00[m->f_F2].f_0 & 0x100000) {
        return 1;
    }
    if (m->f_D4 > 0) {
        return 1;
    }
    if ((u16)((u16)Monkey_Rand() % 100) < 3) {
        g_CurMonkey->f_D4 = 4;
        return 1;
    }
    return 0;
}

s32 func_80033000(void) {
    return 2;
}

s32 Monkey_EnableCollision(void) {
    Monkey *p = g_CurMonkey;
    if (!((p->f_24C >> 1) & 1)) {
        p->f_24C |= 2;
        Collision_Set(3, &p->f_24, p);
        func_8007CD88(&p->f_1C);
        return 1;
    }
    return 0;
}

s32 Monkey_DisableCollision(void)
{
  u32 temp_v1;
  void *temp_s0;
  temp_s0 = g_CurMonkey;
  temp_v1 = *((u32 *) (((s8 *) temp_s0) + 0x24C));
  if (!((temp_v1 >> 1) & 1))
  {
    if (temp_s0 || temp_v1)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  *((u32 *) (((s8 *) temp_s0) + 0x24C)) = (u32) (temp_v1 & (~2));
  Collision_Remove(temp_s0 + 0x24);
  func_8007CDC4(temp_s0 + 0x1C);
  return 1;
}

void Monkey_StepAnimFrame(void)
{
  Monkey *m = g_CurMonkey;
  g_CurMonkey->f_5C++;
  g_CurMonkey->f_5C = (m->f_5C < (g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_2 + 1)) ? (g_CurMonkey->f_5C) : (g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_2 + 1);
}

int func_8003317C(void)
{
  s32 i = 0;
  do
  {
    ((struct S_D_800EC350_8003317C *)&g_Game)->f_816C[i] = 0;
    i++;
  }
  while (i < 8);
}

void Monkey_RestartAnim() {
    s32 i = Monkey_CurAnimIndex();
    Monkey *p = g_CurMonkey;
    p->f_5C = p->f_16C[i].f_0;
    if (!((D_800AE940[p->f_78].f_4 >> 2) & 1)) {
        p->f_96 = 0;
    }
}

void Monkey_SetState(int arg0)
{
  if ((*((u8 *) (((s8 *) g_CurMonkey) + 0x78))) != arg0)
  {
    *((u8 *) (((s8 *) g_CurMonkey) + 0x78)) = arg0;
    if (((u32) ((*((u8 *) (((s8 *) g_CurMonkey) + 0x78))) - 0x32)) < 3U)
    {
      *((s32 *) (((s8 *) g_CurMonkey) + 0x18)) = (s32) ((struct S_D_800EC350_80033220 *)&g_Game)->f_81B8;
      *((s32 *) (((s8 *) g_CurMonkey) + 0x16C)) = (s32) (((struct S_D_800EC350_80033220 *)&g_Game)->f_8240 + (*((s32 *) (((s8 *) D_800B4D14) + 0x1C))));
    }
    else
      if ((*((s32 *) (((s8 *) g_CurMonkey) + 0x18))) != ((struct S_D_800EC350_80033220 *)&g_Game)->f_81B4)
    {
      *((s32 *) (((s8 *) g_CurMonkey) + 0x18)) = (s32) ((struct S_D_800EC350_80033220 *)&g_Game)->f_81B4;
      *((s32 *) (((s8 *) g_CurMonkey) + 0x16C)) = (s32) (((struct S_D_800EC350_80033220 *)&g_Game)->f_8240 + (*((s32 *) (((s8 *) D_800B4D14) + 0x18))));
      Monkey_RestartAnim();
    }
    Monkey_RestartAnim();
  }
  if (1)
  {
  }
}

/* For each of the 8 monkeys: sets its state byte f_7A from the stage's saved list at
 * g_Game+0x816C (4 becomes 0). For monkey kinds flagged 0x400 in D_800B4D00, state 2 calls
 * Object_SetFlagCF(kind->f_10 / 100, 4); state 5 does the same, resets the state to 0, calls
 * func_80052D04 with the monkey's position, and Monkey_SetState(0x2B). */
void Monkey_RestoreStates(void) {
    s32 i;
    u8 st;
    for (i = 0; i < 8; i++) {
        g_CurMonkey = &((Monkey *)&g_Monkeys)[i];
        st = ((struct Game_800332F8 *)&g_Game)->f_816C[i];
        if (st == 4) {
            g_CurMonkey->f_7A = 0;
        } else {
            g_CurMonkey->f_7A = st;
        }
        if (D_800B4D00[g_CurMonkey->f_F4].f_0 & 0x400) {
            if (g_CurMonkey->f_7A == 2) {
                Object_SetFlagCF((s16)D_800B4D00[g_CurMonkey->f_F4].f_10 / 100, 4);
            } else if (g_CurMonkey->f_7A == 5) {
                Object_SetFlagCF((s16)D_800B4D00[g_CurMonkey->f_F4].f_10 / 100, 4);
                g_CurMonkey->f_7A = 0;
                func_80052D04((s16)D_800B4D00[g_CurMonkey->f_F4].f_10 / 100, &g_CurMonkey->f_24);
                Monkey_SetState(0x2B);
            }
        }
    }
}

extern struct { u8 pad_0[0x816C]; s8 f_816C[8]; } G_334C8 asm("g_Game");
extern Monkey MK_334C8[] asm("g_Monkeys");
extern s16 g_MonkeyCount;

/* Per-monkey status bytes g_Game+0x816C[8], one per active monkey slot (setting g_CurMonkey to each):
   0 when g_MonkeyCount is 0 or D_800B4CF4 is set, 5 for a monkey in mode 4 at a node flagged 0x400 in
   action 0x2B, 0 in mode 1, 2 in mode 3, else its mode (+0x7A). */
void Monkey_UpdateSlotStatus(void) {
    s32 i;
    Monkey *m;
    for (i = 0; i < 8; i++) {
        m = &MK_334C8[i];
        g_CurMonkey = m;
        if (g_MonkeyCount == 0 || D_800B4CF4 != 0) {
            G_334C8.f_816C[i] = 0;
        } else if (MK_334C8[i].f_7A == 4 && (D_800B4D00[m->f_F4].f_0 & 0x400) && m->f_78 == 0x2B) {
            G_334C8.f_816C[i] = 5;
        } else if (g_CurMonkey->f_7A == 1) {
            G_334C8.f_816C[i] = 0;
        } else if (g_CurMonkey->f_7A == 3) {
            G_334C8.f_816C[i] = 2;
        } else {
            G_334C8.f_816C[i] = MK_334C8[i].f_7A;
        }
    }
}

/* func_800335D0: is link record idx in its "done" state? Reads its kind r[0] and state r[1]
 * (func_8005B7BC): kind 1: state 0 or 5; 0x65: state < 2 or == 5; 6: 3; 9/0x11/0x18: > 0;
 * 0x31: 0; others: 2. Used by Monkey_CanDoAction for actions flagged 0x40/0x80. */
s32 func_800335D0(s32 idx) {
    s16 r[4];
    s32 st;
    u16 ok;
    s32 want;

    if (func_8005B7BC(idx, r) == -1) {
        goto miss;
    }
    ok = 1;
    switch (r[0]) {
    case 1:
        st = r[1];
        want = 5;
        if (st == 0) {
            goto one;
        }
        goto cmp;
    case 0x65:
        if ((u16)r[1] < 2) {
            return 1;
        }
        want = r[1];
        st = 5;
        goto cmp;
    case 6:
        st = r[1];
        want = 3;
        goto cmp;
    case 0:
    case 10:
    default:
        st = r[1];
        want = 2;
    cmp:
        if (st != want) {
            return 0;
        }
    one:
        return ok;
    case 9:
    case 0x11:
    case 0x18:
        if (r[1] <= 0) {
            goto miss;
        }
        return 1;
    case 0x31:
        if (r[1] == 0) {
            return 1;
        }
    miss:
        return 0;
    }
}

void Monkey_ClearQueuedSounds(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_800E6780[i].f_0 = -1;
        D_800E6780[i].f_4 = -1;
        D_800E6780[i].f_10 = 0;
        D_800E6780[i].f_C = 0;
        D_800E6780[i].f_8 = 0;
    }
}

void Monkey_QueueSound(s32 a, s32 b) {
    s32 i = 0;
    Monkey *m = g_CurMonkey;
    for (; i < 16; i++) {
        if (D_800E6780[i].f_4 < 0) {
            D_800E6780[i].f_0 = a;
            D_800E6780[i].f_4 = b;
            D_800E6780[i].f_8 = m->f_24;
            D_800E6780[i].f_C = m->f_28;
            D_800E6780[i].f_10 = m->f_2C;
            return;
        }
    }
    bios_printf(D_800A4900);
}

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4900);


/* Count down the 16 queued monkey sounds (Monkey_QueueSound) and play each one at its
   stored position when its delay reaches 0. */
void Monkey_UpdateQueuedSounds(void) {
    s16 v[3];
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_800E6780[i].f_4 == 0 && D_800E6780[i].f_0 > 0) {
            v[0] = D_800E6780[i].f_8;
            v[1] = D_800E6780[i].f_C;
            v[2] = D_800E6780[i].f_10;
            Sound_PlayAt(D_800E6780[i].f_0, v);
        }
        if (D_800E6780[i].f_4 >= 0) {
            D_800E6780[i].f_4--;
        }
    }
}

/* The k-th link (counting only entries with bit 0x4000) of path node n, without its
   flag bits; -1 if k is negative or the node has fewer such links. */
s32 Node_GetLink(s16 n, s16 k) {
    s32 c;
    s32 j;
    if (k < 0) {
fail:
        return -1;
    }
    c = -1;
    for (j = 0; j < D_800B4D00[n].f_A; j++) {
        if (D_800B4D00[n].f_C[j] & 0x4000) {
            c++;
        }
        if (c == k) {
            break;
        }
    }
    if (c != k) {
        goto fail;
    }
    return D_800B4D00[n].f_C[j] & 0x3FFF;
}

s32 func_80033940(s16 arg0) {
    s32 temp_v0;
    s32 var_a1;

    var_a1 = 0;
    if (arg0 < 4) {
        temp_v0 = g_ActiveMonkeys[arg0];
        if (temp_v0 != 0) {
            var_a1 = M2C_FIELD(temp_v0, u8 *, 0x7A) == 4;
        }
    }
    return var_a1;
}

s32 func_8003398C(void) {
    s32 var_a0;

    var_a0 = 0;
    if ((g_Game.f_8126 == 0x29) || (g_Game.f_8126 == 0x43) || (g_Game.f_8126 == 0x35)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_800339CC(void) {
    return (u32)(g_CurMonkey->f_78 - 30) < 3;
}

s32 func_800339EC(void) {
    s32 var_a0;

    var_a0 = 0;
    if ((g_Game.f_8122 == 3) || (g_Game.f_8122 == 6) || (g_Game.f_8122 == 8) || (g_Game.f_8126 == 0x46)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 Monkey_CheckStateTimer(void) {
    Monkey *m = g_CurMonkey;
    s32 i;
    if ((D_800AE940[m->f_78].f_4 >> 2) & 1) {
        i = Monkey_CurAnimIndex();
        m = g_CurMonkey;
        return !(m->f_5C > m->f_16C[i].f_2);
    }
    return !(m->f_96 > (u16)m->f_128);
}

s32 Monkey_AnimJustStarted(void) {
    s32 i = Monkey_CurAnimIndex();
    return g_CurMonkey->f_5C == g_CurMonkey->f_16C[i].f_0 + 1;
}

s32 func_80033B10(void) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(g_CurMonkey, u8 *, 0x78);
    var_a0 = 0;
    if ((temp_v1 == 1) || (temp_v1 == 0xD) || (temp_v1 == 0x10) || (temp_v1 == 0x13) || (temp_v1 == 0x3A) || (temp_v1 == 0xE) || (temp_v1 == 0x11) || (temp_v1 == 0x14) || (temp_v1 == 0x3B) || (temp_v1 == 0xF) || (temp_v1 == 0x12) || (temp_v1 == 0x15) || (temp_v1 == 0x3C)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_80033B9C(void) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(g_CurMonkey, u8 *, 0x78);
    var_a0 = 0;
    if ((temp_v1 == 0xF) || (temp_v1 == 0x12) || (temp_v1 == 0x15) || (temp_v1 == 0x3C)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_80033BE0(void) {
    return (u32)(g_CurMonkey->f_78 - 50) < 3;
}

s32 func_80033C00(void) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(g_CurMonkey, u8 *, 0x78);
    var_a0 = 0;
    if ((temp_v1 == 0xC) || (temp_v1 == 0x24)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_80033C34(void) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(g_CurMonkey, u8 *, 0x78);
    var_a0 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 0x2C) || (temp_v1 == 0x2D) || (temp_v1 == 0x2E) || (temp_v1 == 0x31)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_80033C80(void) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(g_CurMonkey, u8 *, 0x78);
    var_a0 = 0;
    if ((temp_v1 == 0x40) || (temp_v1 == 5) || (temp_v1 == 0x41) || (temp_v1 == 0x25) || (temp_v1 == 6)) {
        var_a0 = 1;
    }
    return var_a0;
}

/* Fires an enemy shot of type k (func_80059304) from g_CurMonkey: from its position, raised by
 * 200 except for types 3 and 4, aimed at g_MonkeyTarget. Type 6 cycles through the five aim
 * patterns (D_800AEBF4 % 5) instead of passing the direction. */
void Monkey_FireShot(s32 k) {
    s16 v[4];
    s16 d[4];
    Monkey *m;
    Monkey *s;

    if ((u32)(k - 3) < 2) {
        m = g_CurMonkey;
        v[0] = m->f_24;
        v[1] = m->f_28;
        v[2] = m->f_2C;
    } else {
        m = g_CurMonkey;
        v[0] = m->f_24;
        v[1] = m->f_28 - 200;
        v[2] = m->f_2C;
    }
    s = g_MonkeyTarget;
    d[0] = s->f_24 - g_CurMonkey->f_24;
    d[1] = s->f_28 - g_CurMonkey->f_28;
    d[2] = s->f_2C - g_CurMonkey->f_2C;
    if (k == 6) {
        func_80059304(v, g_CurMonkey, 6, (u8)(D_800AEBF4++ % 5));
    } else {
        func_80059304(v, g_CurMonkey, k, (s32)d);
    }
}

void func_80033DF0(void) {
    M2C_FIELD(g_CurMonkey, u16 *, 0x96) = (u16) (M2C_FIELD(g_CurMonkey, u16 *, 0x96) + 1);
    Monkey_FireShot(6);
    Monkey_QueueSound(0x4B, 5);
    M2C_FIELD(g_CurMonkey, u8 *, 0x222) = (u8) (M2C_FIELD(g_CurMonkey, u8 *, 0x222) - 1);
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_80033E4C);

void func_8003429C(s16 k) {
    s16 v[4];
    s16 d[4];

    g_CurMonkey->f_96++;
    v[0] = g_CurMonkey->f_24;
    v[1] = g_CurMonkey->f_28 - 200;
    v[2] = g_CurMonkey->f_2C;
    if (k == 6) {
        func_80059304(v, g_CurMonkey, 10, (s16 *)(u16)((u16)Monkey_Rand() % 3));
    } else {
        /* the original writes all three deltas to d[0] */
        d[0] = g_MonkeyTarget->f_24 - g_CurMonkey->f_24;
        d[0] = g_MonkeyTarget->f_28 - g_CurMonkey->f_28;
        d[0] = g_MonkeyTarget->f_2C - g_CurMonkey->f_2C;
        func_80059304(v, g_CurMonkey, 5, d);
    }
    Monkey_QueueSound(0x49, 0);
    M2C_FIELD(g_CurMonkey, s16 *, 0x150) = 10;
    g_CurMonkey->f_222--;
}

void func_800343B0(void) {
    M2C_FIELD(g_CurMonkey, u16 *, 0x96) = (u16) (M2C_FIELD(g_CurMonkey, u16 *, 0x96) + 1);
    Monkey_FireShot(7);
    Monkey_QueueSound(0x48, 2);
    M2C_FIELD(g_CurMonkey, u8 *, 0x222) = (u8) (M2C_FIELD(g_CurMonkey, u8 *, 0x222) - 1);
}

void func_8003440C(void) {
    Monkey *m = g_CurMonkey;
    s16 p[3];
    s16 d[3];
    m->f_96++;
    p[0] = m->f_24;
    p[1] = m->f_28 + 200;
    p[2] = m->f_2C;
    d[0] = g_MonkeyTarget->f_24 - m->f_24;
    d[0] = g_MonkeyTarget->f_28 - m->f_28;
    d[0] = g_MonkeyTarget->f_2C - m->f_2C;
    func_80059304(p, m, 8, d);
    Monkey_QueueSound(0x49, 0);
    g_CurMonkey->f_222--;
}

s32 Vec_AngleBetweenXZ(VEC_800344C8 *a, VEC_800344C8 *b)
{
  VEC_800344C8 na;
  int new_var;
  VEC_800344C8 nb;
  VectorNormal(a, &na);
  VectorNormal(b, &nb);
  new_var = ((na.vx * nb.vx) + (na.vz * nb.vz)) >> 12;
  return ratan2(((na.vx * nb.vz) - (na.vz * nb.vx)) / 4096, new_var);
}

s32 func_8003455C(void) {
    Monkey *m = g_CurMonkey;
    VEC3_8003455C a;
    VEC3_8003455C b;
    s32 r;
    a.vx = m->f_60;
    a.vy = 0;
    a.vz = m->f_64;
    b.vx = g_MonkeyTarget->f_24 - m->f_24;
    b.vy = 0;
    b.vz = g_MonkeyTarget->f_2C - m->f_2C;
    r = Vec_AngleBetweenXZ(&a, &b);
    if (r <= 0) {
        r += 0x1000;
    }
    return r;
}

s32 Vec_DistXZ_SV(VEC_800345D4 *a, SVECTOR *b) {
    VEC_800345D4 sq;
    VEC_800345D4 d;
    memset(&d, 0, 0x10);
    d.vx = a->vx - b->vx;
    d.vy = a->vy - b->vy;
    d.vz = a->vz - b->vz;
    sq = d;
    Square0(&sq, &sq);
    return SquareRoot0(sq.vx + sq.vz);
}

s32 Vec_Dist(VEC_80034684 *a, VEC_80034684 *b) {
    VEC_80034684 sq;
    VEC_80034684 d;
    memset(&d, 0, 0x10);
    d.vx = a->vx - b->vx;
    d.vy = a->vy - b->vy;
    d.vz = a->vz - b->vz;
    sq = d;
    Square0(&sq, &sq);
    return SquareRoot0(sq.vx + sq.vy + sq.vz);
}

s32 Vec_DistXZ(VEC_8003473C *a, VEC_8003473C *b) {
    VEC_8003473C sq;
    VEC_8003473C d;
    memset(&d, 0, 0x10);
    d.vx = a->vx - b->vx;
    d.vz = a->vz - b->vz;
    sq = d;
    Square0(&sq, &sq);
    return SquareRoot0(sq.vx + sq.vz);
}

void Monkey_AimAtGoal(void) {
    Monkey *p = g_CurMonkey;
    p->f_68.vx = p->f_BC - p->f_24;
    p->f_68.vy = p->f_C0 - p->f_28;
    p->f_68.vz = p->f_C4 - p->f_2C;
    VectorNormalSS(&p->f_68, &p->f_68);
}

void Monkey_TurnToGoal(void) {
    Monkey *m;
    Monkey_AimAtGoal();
    if (func_80033C34() != 0) {
        return;
    }
    if (g_CurMonkey->f_78 == 9) {
        return;
    }
    if (func_80033BE0() != 0) {
        return;
    }
    m = g_CurMonkey;
    if (m->f_78 == 0x29 || m->f_78 == 0x2B) {
        return;
    }
    m->f_62 = 0;
    m->f_60 = m->f_68.vx;
    m->f_64 = m->f_68.vz;
    VectorNormalSS((SVECTOR *)&m->f_60, (SVECTOR *)&m->f_60);
}

s16 SVec_DotXZ(SVEC *a, SVEC *b) {
    SVEC na;
    SVEC nb;
    VectorNormalSS(a, &na);
    VectorNormalSS(b, &nb);
    return (na.vx * nb.vx + na.vz * nb.vz) / 4096;
}

s16 Vec_DotXZ(VEC_80034940 *a, VEC_80034940 *b) {
    VEC_80034940 na;
    VEC_80034940 nb;
    VectorNormal(a, &na);
    VectorNormal(b, &nb);
    return (na.vx * nb.vx + na.vz * nb.vz) / 4096;
}

s32 Math_Atan2Pos(s32 arg0, s32 arg1)
{
  s32 var_v0;
  if (arg1 == 0)
  {
    var_v0 = 0x400;
    if (arg0 <= 0)
    {
      if (var_v0)
      {
        return 0xC00;
      }
      else
      {
        return 0xC00;
      }
    }
    return var_v0;
  }
  var_v0 = ratan2();
  if (var_v0 < 0)
  {
    var_v0 += 0x1000;
  }
  return var_v0;
}

s32 func_800349F4(s16 arg0) {
    return (D_800B4D00[arg0].f_0 & 0x1800C) != 0;
}

s32 func_80034A2C(s16 k) {
    s32 r = 0;
    u32 f = D_800B4D00[k].f_0;
    if ((f & 4) && ((S_M_80034A2C_80034A2C *)g_CurMonkey)->f_22C == 0) {
        goto yes;
    }
    if ((f & 8) && func_800339EC() == 0 && ((S_M_80034A2C_80034A2C *)g_CurMonkey)->f_20C < (s16)D_800B4D00[k].f_10) {
        goto yes;
    }
    f = D_800B4D00[k].f_0;
    if ((f & 0x8000) && ((S_M_80034A2C_80034A2C *)g_CurMonkey)->f_20C >= 0x5DD) {
        goto yes;
    }
    if (!(f & 0x10000) || func_80052C4C(D_800B4D00[k].f_10) != 2) {
        goto end;
    }
yes:
    r = 1;
end:
    return r;
}

void Node_GetJointRef(s16 i, s16 *a, s16 *b, s16 *c) {
    *a = (s16)D_800B4D00[i].f_10 / 100;
    *b = D_800B4D00[i].f_10 - *a * 100;
    *c = D_800B4D00[i].f_12;
}

void func_80034C08(s16 i, s16 *a, s16 *b, s16 *c, s16 *d) {
    *a = D_800AEB6C[(s16)((s16)D_800B4D00[i].f_10 / 100)];
    *b = D_800B4D00[i].f_10 - (s16)((s16)D_800B4D00[i].f_10 / 100) * 100;
    *c = (s16)D_800B4D00[i].f_12 / 100;
    *d = D_800B4D00[i].f_12 - *c * 100;
}

s32 Object_GetJointPos(s16 arg0, s32 arg1, unsigned short arg2, void *arg3)
{
  void *temp_s0;
  void *temp_s1;
  temp_s0 = (void *) (((u8 *) (&g_Objects)) + (arg0 * 0xE4));
  temp_s1 = (void *) (((u8 *) (&D_800F4750)) + ((arg1 & 0xFFFF) << 5));
  if ((temp_s0 == ((void *) 0)) || (!((((u32) (*((u32 *) (((s8 *) temp_s0) + 0xE0)))) >> 4) & 1)))
  {
    return 0;
  }
  func_80014804(temp_s0 + 0x60, *((s32 *) (((s8 *) temp_s0) + 0x14)));
  func_80015780(temp_s0, 3);
  ApplyMatrixSV(temp_s1, (*((s32 *) (((s8 *) temp_s0) + 0x10))) + ((arg2 & 0xFFFF) * 8), arg3);
  *((u16 *) (((s8 *) arg3) + 0)) = (u16) ((*((u16 *) (((s8 *) arg3) + 0))) + (*((u16 *) (((s8 *) temp_s1) + 0x14))));
  *((u16 *) (((s8 *) arg3) + 2)) = (u16) ((*((u16 *) (((s8 *) arg3) + 2))) + (*((u16 *) (((s8 *) temp_s1) + 0x18))));
  *((u16 *) (((s8 *) arg3) + 4)) = (u16) ((*((u16 *) (((s8 *) arg3) + 4))) + (*((u16 *) (((s8 *) temp_s1) + 0x1C))));
  return 1;
}

s32 Monkey_GetJointPos(u16 i, u16 j, SVECTOR *out) {
    struct S_D_800F4730 *t = &D_800F4730[i];
    Monkey *m = g_CurMonkey;
    if (m == 0 || m->f_7A == 0) {
        return 0;
    }
    ApplyMatrixSV(t, &m->f_10[j], out);
    out->vx += t->t[0];
    out->vy += t->t[1];
    out->vz += t->t[2];
    out->vy += 0xDC;
    return 1;
}

void Node_GetPosition(u16 k, VEC_80040CFC_80034EF8 *out) {
    SVECTOR v;
    s16 a, b, c;
    if (NODE_34EF8.f_0 & 0x400) {
        Node_GetJointRef(k, &a, &b, &c);
        if (((s32 (*)(s16, u16, u16, SVECTOR *))Object_GetJointPos)(a, b, c, &v) != 0) {
            out->vx = v.vx;
            out->vy = v.vy;
            out->vz = v.vz;
        } else {
            out->vx = 0;
            out->vy = 0;
            out->vz = 0;
        }
    } else if (NODE_34EF8.f_0 & 1) {
        out->vx = NODE_34EF8.f_4 + ((struct S_D_800EC350_80034EF8 *)&g_Game)->f_820C[NODE_34EF8.f_10].f_0;
        out->vy = NODE_34EF8.f_6 + ((struct S_D_800EC350_80034EF8 *)&g_Game)->f_820C[NODE_34EF8.f_10].f_2 - ((struct S_D_800EC350_80034EF8 *)&g_Game)->f_820C[NODE_34EF8.f_10].f_8;
        out->vz = NODE_34EF8.f_8 + ((struct S_D_800EC350_80034EF8 *)&g_Game)->f_820C[NODE_34EF8.f_10].f_4;
    } else {
        out->vx = NODE_34EF8.f_4;
        out->vy = NODE_34EF8.f_6;
        out->vz = NODE_34EF8.f_8;
    }
}

typedef struct { u8 pad[0xF2]; u16 hist[6]; } MonkeyPath_80035080;

/* Push `node` onto the monkey's six-entry path history (f_F2.., newest first). If the monkey
   should turn back (func_80033C34 with f_228 bit 0, state 9/0x1A/0x35, f_228 bit 9, or
   func_800339EC), its goal f_EC becomes the previous node. */
void Monkey_GoToNode(s16 node) {
    s32 i;
    Monkey *m = g_CurMonkey;
    i = 5;
    while (i > 0) {
        ((MonkeyPath_80035080 *)m)->hist[i] = ((MonkeyPath_80035080 *)m)->hist[i - 1];
        i--;
    }
    g_CurMonkey->f_F2 = node;
    func_800355DC();
    if ((func_80033C34() != 0 && (g_CurMonkey->f_228 & 1)) ||
        g_CurMonkey->f_78 == 9 || g_CurMonkey->f_78 == 0x1A || g_CurMonkey->f_78 == 0x35 ||
        (g_CurMonkey->f_228 & 0x200) || func_800339EC() != 0) {
        g_CurMonkey->f_EC = g_CurMonkey->f_F4;
    }
}

s32 Monkey_IsTargetInRange(void) {
    s16 r;
    s32 res;
    if (M_3516C->state == 0xC || M_3516C->state == 0x24) {
        r = M_3516C->range * 2;
    } else if (M_3516C->state == 9) {
        r = M_3516C->range * 15 / 10;
    } else if (((struct Game_8003516C *)&g_Game)->stage == 0x4D &&
               ((M_3516C->spot >= 5 && M_3516C->spot <= 6) || M_3516C->spot == 0x13 || M_3516C->spot == 0x14 ||
                M_3516C->spot == 0xB4 || M_3516C->spot == 0xB5 || M_3516C->spot == 0x9E || M_3516C->spot == 0x9F ||
                M_3516C->spot == 0xA4)) {
        r = M_3516C->range / 2;
    } else if (((struct Game_8003516C *)&g_Game)->stage == 0x1A &&
               ((M_3516C->spot >= 0x97 && M_3516C->spot <= 0x99) || M_3516C->spot == 0x9C || M_3516C->spot == 0x9D ||
                M_3516C->spot == 0x9E || M_3516C->spot == 0x9F || M_3516C->spot == 0xA0 || M_3516C->spot == 0xA9 ||
                M_3516C->spot == 0xAA || M_3516C->spot == 0xAB || M_3516C->spot == 0xAD)) {
        r = M_3516C->range / 2;
    } else {
        r = M_3516C->range;
    }
    res = 0;
    if (M_3516C->f_228 & 2) {
        if (M_3516C->f_218 < r) {
            goto yes;
        }
    } else if (M_3516C->f_214 < r) {
    yes:
        res = 1;
    }
    return res;
}

void func_80035370(void) {
    VEC_80035370_80035370 a;
    VEC_80035370_80035370 b;
    s32 d;
    s32 v;

    Node_GetPosition(g_CurMonkey->f_F2, &a);
    Node_GetPosition(g_CurMonkey->f_F4, &b);
    d = Vec_Dist(&a, &b);
    v = Vec_DistXZ(&a, &b);
    if (d == 0 || ABS(v * 100 / d) > 10) {
        M2C_FIELD(g_CurMonkey, u8 *, 0x22E) = 0;
    } else if (b.vy > a.vy) {
        M2C_FIELD(g_CurMonkey, u8 *, 0x22E) = 1;
    } else {
        M2C_FIELD(g_CurMonkey, u8 *, 0x22E) = 2;
    }
}

void func_80035474(void) {
    VEC_80040CFC_80035474 t;
    VEC_80034684_80035474 p;
    if (g_CurMonkey->f_78 != 0x1E || (M->f_24B & 1)) {
        if (D_800B4D00[g_CurMonkey->f_F2].f_0 & 0x40) {
            M->f_BC.vx = g_MonkeyTarget->f_24;
            M->f_BC.vy = 0;
            M->f_BC.vz = g_MonkeyTarget->f_2C;
        } else {
            Node_GetPosition(g_CurMonkey->f_F2, &t);
            M->f_BC = t;
            p.vx = g_CurMonkey->f_24;
            p.vy = g_CurMonkey->f_28;
            p.vz = g_CurMonkey->f_2C;
            if ((M->f_228 & 2) && g_CurMonkey->f_78 == 9 && M->f_22E == 1) {
                p.vy -= 200;
            }
        }
    }
    M->f_214 = Vec_DistXZ(&p, (VEC_80034684_80035474 *)&M->f_BC);
    M->f_218 = Vec_Dist(&p, (VEC_80034684_80035474 *)&M->f_BC);
}

void func_800355DC(void) {
    func_80035370();
    func_80035474();
}

s32 Monkey_IsPathLooping(void) {
    M_35604_80035604 *m = (*(M_35604_80035604 * *)&g_CurMonkey);
    M_35604_80035604 *n;


    if (m->f_F2 == m->f_F4) {
        if (m->f_F2 == m->f_F6) {
            return 1;
        }
    } else if (m->f_F2 == m->f_F6 && *(s32 *)&m->f_F4 == *(s32 *)&m->f_F8 && m->f_F8 == m->f_FC) {
        return 1;
    }
    n = (*(M_35604_80035604 * *)&g_CurMonkey);
    if (n->f_F2 == n->f_F8 && n->f_F4 == n->f_FA && n->f_F6 == n->f_FC) {
        return 1;
    }
    return 0;
}

/* func_800356C0: per-type sound id of the current monkey: 0x52 for yellow / dark blue, 0x54 for type 5 /
 * red, 0x53 for the others. All seven types are listed (with the default in the middle) for the
 * compiler to build the original decision tree. */
s32 func_800356C0(void) {
    switch (g_MonkeyKinds[g_CurMonkey->f_7C].f_0) {
    case MONKEY_YELLOW:
    case MONKEY_DARK_BLUE:
        return 0x52;
    case MONKEY_LIGHT_BLUE:
    case MONKEY_GREEN:
    case MONKEY_WHITE:
    default:
        return 0x53;
    case MONKEY_TYPE5:
    case MONKEY_RED:
        return 0x54;
    }
}

/* func_80035750: per-type sound id of the current monkey: 0x55 for yellow / dark blue, 0x57 for type 5 /
 * red, 0x56 for the others. All seven types are listed (with the default in the middle) for the
 * compiler to build the original decision tree. */
s32 func_80035750(void) {
    switch (g_MonkeyKinds[g_CurMonkey->f_7C].f_0) {
    case MONKEY_YELLOW:
    case MONKEY_DARK_BLUE:
        return 0x55;
    case MONKEY_LIGHT_BLUE:
    case MONKEY_GREEN:
    case MONKEY_WHITE:
    default:
        return 0x56;
    case MONKEY_TYPE5:
    case MONKEY_RED:
        return 0x57;
    }
}

void func_800357E0(void) {
    Monkey_QueueSound(func_800356C0(), 0);
    Monkey_SetState(7);
    func_80038F00();
}

/* func_8003581C: enter monkey state 0x1E at the current node f_F2 (from Monkey_TrySpecialAction when f_228 has
 * 0x800 and the node has flag 0x200): stores the node position (+0x234..) and the direction from
 * func_8003B880 (+0x240), sets flag 0x80000000 and clears 0x1000000, and starts sound 0x6050 unless
 * the previous state was 0x1E or 0x20. */
s32 func_8003581C(void) {
    s32 prev = (*(M_3581C_8003581C * *)&g_CurMonkey)->f_78;
    V_3581C_8003581C v;
    s16 d[1];
    V_3581C_8003581C *pv;

    Monkey_SetState(0x1E);
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_230 = 0;
    pv = &v;
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_8E = 1000;
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_248 |= 0x80000000;
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_4A = -0x4000;
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_248 &= ~0x1000000;
    func_8003B880((*(M_3581C_8003581C * *)&g_CurMonkey)->f_F4, (*(M_3581C_8003581C * *)&g_CurMonkey)->f_F2, d);
    Node_GetPosition((*(M_3581C_8003581C * *)&g_CurMonkey)->f_F2, pv);
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_234 = v.x;
    (*(M_3581C_8003581C * *)&g_CurMonkey)->f_238 = v.y;
    { s32 z = v.z; (*(M_3581C_8003581C * *)&g_CurMonkey)->f_240 = d[0]; (*(M_3581C_8003581C * *)&g_CurMonkey)->f_23C = z; }
    func_80038F00();
    if (prev != 0x1E && prev != 0x20) {
        (*(M_3581C_8003581C * *)&g_CurMonkey)->f_15C = func_800882C4(1, 0x6050, (*(M_3581C_8003581C * *)&g_CurMonkey)->f_7C);
    }
    do { return 1; } while (0);
}

void func_80035918(s16 a) {
    Monkey *m;
    s16 v;
    Monkey *n;
    MonkeyAnimEntry *t;
    g_CurMonkey->f_78 = 0x32;
    m = g_CurMonkey;
    func_80034C08(a, &m->f_242, &v, &m->f_244, &m->f_246);
    n = g_CurMonkey;
    m = n;
    m->f_18 = G_GAME_80035918->f_81B8;
    t = (MonkeyAnimEntry *)(G_GAME_80035918->f_8240 + ((struct D4D14_35918 *)D_800B4D14)->f_1C);
    *(u8 *)&m->f_248 = 0;
    m->f_16C = t;
    Monkey_SetFacingDir(v);
    Monkey_RestartAnim();
}

void func_800359B4(void) {
    Monkey_SetState(0x34);
    M2C_FIELD(g_CurMonkey, u16 *, 0x242) = (u16) (M2C_FIELD(g_CurMonkey, u16 *, 0x242) + 1);
}

s32 func_800359F0(void) {
    u16 sp10;

    if (M2C_FIELD(g_CurMonkey, u8 *, 0x78) != 0x1D) {
        func_80036B24();
    }
    M2C_FIELD(g_CurMonkey, u8 *, 0x78) = 0x1DU;
    Monkey_RestartAnim();
    func_8003B880(M2C_FIELD(g_CurMonkey, s16 *, 0xF4), M2C_FIELD(g_CurMonkey, s16 *, 0xF2), &sp10);
    func_800355DC();
    M2C_FIELD(g_CurMonkey, u16 *, 0x128) = sp10;
    M2C_FIELD(g_CurMonkey, s16 *, 0x96) = 0;
    M2C_FIELD(g_CurMonkey, u16 *, 0xEC) = (u16) M2C_FIELD(g_CurMonkey, s16 *, 0xF4);
    return 1;
}

s32 func_80035A7C(void) {
    Monkey *m = g_CurMonkey;
    m->f_78 = 4;
    m->f_EC = m->f_F4;
    Monkey_RestartAnim();
    g_CurMonkey->f_172 = 5;
    g_CurMonkey->f_170 = g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_2 - g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0 + 1;
    func_800355DC();
    Monkey_StartNodeJump();
    func_80038F00();
    if (func_800339EC() != 0) {
        Monkey_QueueSound(0xB1, 0);
        Monkey_QueueSound(0x11, 0);
        Monkey_QueueSound(0x13, g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_2 - g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0 - 1);
    } else {
        Monkey_QueueSound(0x44, 3);
        Monkey_QueueSound(0x45, g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_2 - g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0 + 1);
    }
    return 1;
}

void func_80035BD0(s16 st) {
    SVEC_80035BD0 a;
    SVEC_80035BD0 b;
    if (func_80033C34() == 0) {
        ((S_BC_80035BD0_80035BD0 *)g_CurMonkey)->f_BC = g_MonkeyTarget->f_24;
        ((S_BC_80035BD0_80035BD0 *)g_CurMonkey)->f_C0 = g_MonkeyTarget->f_28;
        ((S_BC_80035BD0_80035BD0 *)g_CurMonkey)->f_C4 = g_MonkeyTarget->f_2C;
    }
    Monkey_SetState(st);
    if (st == 0x30) {
        g_CurMonkey->f_E2 = 0x5A;
    } else {
        g_CurMonkey->f_E2 = 0x1E;
    }
    g_CurMonkey->f_124 = 0x78;
    ((S_BC_80035BD0_80035BD0 *)g_CurMonkey)->f_50 = 0;
    Monkey_QueueSound(0x47, 3);
    if (!((g_CurMonkey->f_248 >> 21) & 1)) {
        a.vx = g_CurMonkey->f_24;
        a.vy = g_CurMonkey->f_28;
        a.vz = g_CurMonkey->f_2C;
        Sound_PlayAt(0x4E, &a.vx);
        g_CurMonkey->f_158 = 0x32;
        g_CurMonkey->f_248 |= 0x200000;
    }
    b.vx = g_CurMonkey->f_24;
    b.vy = g_CurMonkey->f_28 - 0x80;
    b.vz = g_CurMonkey->f_2C;
    func_8006B3CC(&b);
}

void func_80035D18(void) {
    Monkey *m = g_CurMonkey;
    s16 v[3];
    Monkey_SetState(0x2F);
    m->f_E2 = 0x1E;
    m->f_92 = 0;
    m->f_124 = 0x78;
    m->f_E4 = m->f_28 + 0x80;
    Monkey_QueueSound(0x47, 3);
    if (!((m->f_248 >> 21) & 1)) {
        v[0] = g_CurMonkey->f_24;
        v[1] = g_CurMonkey->f_28;
        v[2] = g_CurMonkey->f_2C;
        Sound_PlayAt(0x4E, v);
        m->f_158 = 0x32;
        m->f_248 |= 0x200000;
    }
}

void func_80035DD8(void) {
    Monkey *m = g_CurMonkey;
    s16 v[3];
    Monkey_SetState(0x30);
    if (!((m->f_248 >> 21) & 1)) {
        v[0] = g_CurMonkey->f_24;
        v[1] = g_CurMonkey->f_28;
        v[2] = g_CurMonkey->f_2C;
        Sound_PlayAt(0x4E, v);
        m->f_158 = 0x32;
        m->f_248 |= 0x200000;
    }
}

void func_80035E6C(void) {
    Monkey_SetState(0x36);
    M2C_FIELD(g_CurMonkey, s32 *, 0x50) = 0;
    Monkey_QueueSound(0x47, 3);
}

void func_80035EA4(void) {
    Monkey *m = g_CurMonkey;
    s16 v[3];
    v[0] = m->f_24;
    v[1] = m->f_28;
    v[2] = m->f_2C;
    Monkey_SetState(0x20);
    Effect_SpawnAt(5, v);
    Effect_SpawnAt(5, v);
    Monkey_QueueSound(0x78, 0);
    Monkey_QueueSound(0x78, 2);
}

void func_80035F1C(void) {
    if (func_80033C00() == 0) {
        func_80039248();
    }
    Monkey_SetState(0x24);
}

void func_80035F54(void) {
    if (func_80033C00() == 0) {
        func_80039248();
    }
    Monkey_SetState(0xC);
}

void func_80035F8C(void) {
    M2C_FIELD(g_CurMonkey, u16 *, 0xEC) = (u16) M2C_FIELD(g_CurMonkey, u16 *, 0xF4);
    Monkey_SetState(0x35);
}

void func_80035FBC(void) {
    M2C_FIELD(g_CurMonkey, u16 *, 0xEC) = (u16) M2C_FIELD(g_CurMonkey, u16 *, 0xF4);
    if (func_800339EC() != 0) {
        M2C_FIELD(g_CurMonkey, s32 *, 0x12C) = (s32) M2C_FIELD(g_CurMonkey, s32 *, 0x24);
        M2C_FIELD(g_CurMonkey, s32 *, 0x130) = (s32) M2C_FIELD(g_CurMonkey, s32 *, 0x28);
        M2C_FIELD(g_CurMonkey, s32 *, 0x134) = (s32) M2C_FIELD(g_CurMonkey, s32 *, 0x2C);
    }
    Monkey_SetState(0x1A);
}

void func_8003601C(void) {
    s16 sp10;

    M2C_FIELD(g_CurMonkey, s16 *, 0x94) = 0;
    M2C_FIELD(g_CurMonkey, u16 *, 0xEC) = (u16) M2C_FIELD(g_CurMonkey, s16 *, 0xF4);
    func_8003B880(M2C_FIELD(g_CurMonkey, s16 *, 0xF4), M2C_FIELD(g_CurMonkey, s16 *, 0xF2), &sp10);
    if ((((M2C_FIELD(g_CurMonkey, u8 *, 0x78) == 0x1A) && (func_800339EC() == 0)) || (M2C_FIELD(g_CurMonkey, u8 *, 0x78) == 0x35)) && (M2C_FIELD(g_CurMonkey, u8 *, 0x22E) == 2)) {
        M2C_FIELD(g_CurMonkey, s32 *, 0x28) = (s32) (M2C_FIELD(g_CurMonkey, s32 *, 0x28) + 0xC8);
    }
    Monkey_SetState(9);
    Monkey_SetFacingDir(sp10);
}

void func_800360D8(void) {
    M2C_FIELD(g_CurMonkey, u16 *, 0xEC) = (u16) M2C_FIELD(g_CurMonkey, u16 *, 0xF4);
    if (M2C_FIELD(g_CurMonkey, u8 *, 0x78) != 0x3D) {
        M2C_FIELD(g_CurMonkey, s16 *, 0x96) = 0;
        M2C_FIELD(g_CurMonkey, u8 *, 0x78) = 0x3DU;
        Monkey_RestartAnim();
        Monkey_QueueSound(0x2B, 0);
    }
}

void func_8003612C(void) {
    Monkey *p = g_CurMonkey;
    if (p->f_78 != 0x3E) {
        p->f_96 = 0;
        p->f_128 = 0x32;
        p->f_78 = 0x3E;
        p->f_EC = p->f_F4;
        Monkey_RestartAnim();
    }
}

void func_80036174(void) {
    Monkey *p = g_CurMonkey;
    if (p->f_78 != 0x3F) {
        p->f_78 = 0x3F;
        p->f_EC = p->f_F4;
        Monkey_RestartAnim();
    }
}

s32 func_800361B4(void) {
    s32 k;
    if (func_800339EC() != 0) {
        return 0;
    }
    if (func_80033B10() != 0 && ((g_CurMonkey->f_248 >> 19) & 1)) {
        return 0;
    }
    k = (((S_70_800361B4_800361B4 *)g_MonkeyTarget)->f_70 & 0xF) < 2;
    if (k && g_CurMonkey->f_20C < ((S_Kind_800361B4_800361B4 *)&g_MonkeyKinds[g_CurMonkey->f_7C])->f_C[k]) {
        return 1;
    }
    if (g_CurMonkey->f_78 == 0x33 && g_CurMonkey->f_20C < ((S_Kind_800361B4_800361B4 *)&g_MonkeyKinds[g_CurMonkey->f_7C])->f_1A * 3) {
        return 1;
    }
    return g_CurMonkey->f_20C < ((S_Kind_800361B4_800361B4 *)&g_MonkeyKinds[g_CurMonkey->f_7C])->f_1A;
}

void func_80036300(void) {
    u16 r;
    Monkey *m;
    s32 k;
    Monkey_SetState(1);
    r = Monkey_Rand();
    m = g_CurMonkey;
    k = g_MonkeyKinds[m->f_7C].f_A;
    m->f_248 &= ~0x80000;
    m->f_9A = k * 2 - (r * 2) % k;
}

void func_800363A4(void) {
    void *temp_s0;

    temp_s0 = g_CurMonkey;
    Monkey_SetState(1);
    M2C_FIELD(temp_s0, s16 *, 0x9A) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x248) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x248) | 0x80000);
}

void func_800363E4(void) {
    Monkey_SetState((Monkey_Rand() & 1) == 0 ? 0x16 : 0x26);
}

void func_8003641C(void) {
    if (M2C_FIELD(g_CurMonkey, u8 *, 0x78) != 0x17) {
        M2C_FIELD(g_CurMonkey, u8 *, 0x78) = 0x17U;
        Monkey_RestartAnim(0x17);
    }
    Monkey_QueueSound(0x46, 0x1E);
}

void func_80036460(void) {
    if (M2C_FIELD(g_CurMonkey, u8 *, 0x78) != 0x2A) {
        M2C_FIELD(g_CurMonkey, u8 *, 0x78) = 0x2AU;
        Monkey_RestartAnim(0x2A);
        M2C_FIELD(g_CurMonkey, s8 *, 0xE3) = 0;
        M2C_FIELD(g_CurMonkey, u16 *, 0xE4) = (u16) M2C_FIELD(g_CurMonkey, u16 *, 0x28);
        func_80036B78();
    }
}

/* Monkey_StartNodeJump: sets up g_CurMonkey's ballistic jump from its position (+0x24) to path node +0xF2: horizontal direction +0x68, launch angle
   from the height difference (Math_Atan2Pos, clamped), velocity +0x13C/+0x140/+0x144 and duration +0x128 for Monkey_UpdateJump
   (timer +0x96 reset); very steep jumps (angle >= 1002) use a fixed 30-frame drop. */
void Monkey_StartNodeJump(void)
{
  VEC_80040CFC_800364BC p;
  s32 dy;
  s32 dist;
  s32 ang;
  s32 s;
  s32 c;
  s32 den;
  s32 d100;
  s32 t;
  s32 sp;
  s32 a;
  s32 b;
  Node_GetPosition(g_CurMonkey->f_F4, &p);
  g_CurMonkey->f_60 = g_CurMonkey->f_BC - p.vx;
  g_CurMonkey->f_62 = 0;
  g_CurMonkey->f_64 = g_CurMonkey->f_C4 - p.vz;
  g_CurMonkey->f_96 = 0;
  Monkey_RestartAnim();
  g_CurMonkey->f_12C = g_CurMonkey->f_24;
  g_CurMonkey->f_130 = g_CurMonkey->f_28;
  g_CurMonkey->f_134 = g_CurMonkey->f_2C;
  Node_GetPosition(g_CurMonkey->f_F2, &p);
  dy = g_CurMonkey->f_28 - p.vy;
  g_CurMonkey->f_68.vx = p.vx - g_CurMonkey->f_24;
  g_CurMonkey->f_68.vy = 0;
  g_CurMonkey->f_68.vz = p.vz - g_CurMonkey->f_2C;
  dist = (u16) Vec_DistXZ(&p, &g_CurMonkey->f_24);
  if ((dy >= 0) || (((dy >= 0) ? (dy) : (-dy)) < 100))
  {
    ang = 0x400;
    if (dist != 0)
    {
      if (((dy >= 0) ? (dy) : (-dy)) < 100)
      {
        dy = 0;
      }
      ang = (Math_Atan2Pos(dy, dist) + 0x400) / 2;
    }
  }
  else
    if (dist == 0)
  {
    ang = 0x400;
  }
  else
  {
    ang = Math_Atan2Pos(-dy, dist);
    ang = (ang * 70) / 100;
    if (ang < 341)
    {
      ang = 341;
    }
  }
  if (ang >= 1002)
  {
    g_CurMonkey->f_128 = 30;
    g_CurMonkey->f_144 = 0;
    g_CurMonkey->f_13C = 0;
    g_CurMonkey->f_140 = (-((dy + 2700) << 12)) / 30;
  }
  else
  {
    s = rsin(ang);
    c = rcos(ang);
    t = (c * dy) - (s * dist);
    den = (t >= 0) ? (t) : (-t);
    if (den == 0)
    {
      g_CurMonkey->f_144 = 0;
      g_CurMonkey->f_140 = 0;
      g_CurMonkey->f_13C = 0;
    }
    else
      if (den)
    {
      t = c * 1080000;
      d100 = den * 100;
      sp = (SquareRoot0(((u32) t) / d100) * dist) / 60;
      sp = (sp * 120) / 100;
      g_CurMonkey->f_140 = 0;
      g_CurMonkey->f_13C = g_CurMonkey->f_68.vx;
      g_CurMonkey->f_144 = g_CurMonkey->f_68.vz;
      VectorNormal(&g_CurMonkey->f_13C, &g_CurMonkey->f_13C);
      a = (s * s) / (c * 100);
      b = ((dist * 300) * dist) / den;
      g_CurMonkey->f_13C *= sp;
      g_CurMonkey->f_144 *= sp;
      g_CurMonkey->f_140 = -(SquareRoot0(a * b) << 12);
      g_CurMonkey->f_128 = (SquareRoot0(d100 / (c * 300)) * 110) / 100;
    }
    else
    {
      t = c * 1080000;
      d100 = den * 100;
      sp = (SquareRoot0(((u32) t) / d100) * dist) / 60;
      sp = (sp * 120) / 100;
      g_CurMonkey->f_140 = 0;
      g_CurMonkey->f_13C = g_CurMonkey->f_68.vx;
      g_CurMonkey->f_144 = g_CurMonkey->f_68.vz;
      VectorNormal(&g_CurMonkey->f_13C, &g_CurMonkey->f_13C);
      a = (s * s) / (c * 100);
      b = ((dist * 300) * dist) / den;
      g_CurMonkey->f_13C *= sp;
      g_CurMonkey->f_144 *= sp;
      g_CurMonkey->f_140 = -(SquareRoot0(a * b) << 12);
      g_CurMonkey->f_128 = (SquareRoot0(d100 / (c * 300)) * 110) / 100;
    }
  }
  func_80038F00();
}

s32 func_80036964(void) {
    Monkey *m = g_CurMonkey;
    s32 a;
    Monkey *n;
    s32 b;
    m->f_172 = 3;
    m->f_78 = 0x2C;
    m->f_EC = m->f_F4;
    Monkey_RestartAnim();
    n = g_CurMonkey;
    n->f_170 = n->f_16C[34].f_2 - n->f_16C[34].f_0 + 1;
    func_800355DC();
    Monkey_StartNodeJump();
    func_80038F00();
    Monkey_QueueSound(0x44, 3);
    a = Monkey_CurAnimIndex();
    b = Monkey_CurAnimIndex();
    Monkey_QueueSound(0x45, g_CurMonkey->f_16C[a].f_2 - g_CurMonkey->f_16C[b].f_0);
    return 1;
}

void Monkey_QueueSound(s32, s32);

void func_80036A34(void)
{
  int new_var;
  Monkey *m;
  s32 a;
  s32 b;
  s32 x;
  g_CurMonkey->f_78 = 0x31;
  Monkey_RestartAnim();
  m = g_CurMonkey;
  m->f_96 = 0;
  m->f_172 = 7;
  m->f_12C = m->f_24;
  m->f_130 = m->f_28;
  m->f_134 = m->f_2C;
  a = Monkey_CurAnimIndex();
  b = Monkey_CurAnimIndex();
  g_CurMonkey->f_170 = (g_CurMonkey->f_16C[a].f_2 - g_CurMonkey->f_16C[b].f_0) + 1;

  x = SquareRoot0(40000) / 10;
  ;
  g_CurMonkey->f_144 = 0;
  g_CurMonkey->f_13C = 0;
  g_CurMonkey->f_128 = x;
  g_CurMonkey->f_140 = ((u16) g_CurMonkey->f_128) << 2;
  Monkey_QueueSound(0x47, 3);
  func_80038F00();
}

void func_80036B24(void) {
    M2C_FIELD(g_CurMonkey, s16 *, 0xF0) = 0;
    M2C_FIELD(g_CurMonkey, s32 *, 0x248) = (s32) (((M2C_FIELD(g_CurMonkey, s32 *, 0x248) | 0x40000000) & 0xFFFCFFFF) | 0x20000);
    Monkey_DisableCollision();
    func_8003929C();
}

void func_80036B78(void)
{
  S_4D08 *p = g_CurMonkey;
  int new_var2;
  S_4D08 *new_var;
  new_var = p;
  new_var->unkF0 = 0;
  new_var2 = 0xBFFFFFFF;
  p->unk248 = ((p->unk248 & new_var2) & 0xFFFCFFFF) | 0x10000;
  Monkey_EnableCollision();
  func_8003929C();
}

/* Sets the current monkey's facing vector (+0x60/+0x64, 4096 = 1.0) to one of 8 compass
 * directions, 45 degrees apart. Out-of-range values act like 0. The original split this
 * function's switch cases into separate "functions" (func_80036C20 / func_80036C70).
 */
void Monkey_SetFacingDir(s16 dir) {
    Monkey *m = g_CurMonkey;
    m->f_60 = 0;
    m->f_62 = 0;
    m->f_64 = 0;
    switch (dir) {
    default:
    case 0:
        m->f_64 = -0x1000;
        return;
    case 1:
        m->f_60 = -0xB50;
        m->f_64 = -0xB50;
        return;
    case 2:
        m->f_60 = -0x1000;
        return;
    case 3:
        m->f_60 = -0xB50;
        m->f_64 = 0xB50;
        return;
    case 4:
        m->f_64 = 0x1000;
        return;
    case 5:
        m->f_60 = 0xB50;
        m->f_64 = 0xB50;
        return;
    case 6:
        m->f_60 = 0x1000;
        return;
    case 7:
        m->f_60 = 0xB50;
        m->f_64 = -0xB50;
        return;
    }
}

void func_80036C84(void) {
    Fx_DebrisExplosion(M2C_FIELD(g_CurMonkey, s16 *, 0x24), M2C_FIELD(g_CurMonkey, s16 *, 0x28), M2C_FIELD(g_CurMonkey, s16 *, 0x2C));
    Monkey_QueueSound(0x79, 0);
    Monkey_QueueSound(0x79, 2);
}

s32 Monkey_TrySpecialAction(void) {
    u8 r = 1;
    M_80036CD0_80036CD0 *m = MSF;
    u32 f;
    s32 st;
    if ((m->f_248 >> 22) & 1) {
        return 0;
    }
    f = m->f_228;
    if (f & 0x100) {
        func_800359F0();
    } else if ((f & 0x800) && (D_800B4D00[m->f_F4].f_0 & 0x200)) {
        func_8003581C();
    } else {
        m = MSF;
        f = m->f_228;
        if (f & 0x20) {
            func_80035FBC();
        } else if (f & 0x20000) {
            func_80035F8C();
        } else if (f & 8) {
            Monkey_SetState(0xA);
        } else if (f & 4) {
            func_8003601C();
        } else if (f & 0x10) {
            if (m->f_94 <= 0 && (u16)Monkey_Rand() % 100 < 100) {
                func_80035F1C();
            } else {
                func_80035F54();
            }
        } else if (f & 1) {
            func_80035A7C();
        } else if (f & 0x10000) {
            func_80036964();
        } else if (f & 0x800000) {
            func_800360D8();
        } else if ((f & 0x1000000) && m->state == 0x3D) {
            func_8003612C();
        } else if (MSF->state == 3 && !func_800339EC() && (u16)Monkey_Rand() % 100 < 10
                   && (!(D_800B4D00[MSF->f_F2].f_0 & 1) || !(D_800B4D00[MSF->f_F4].f_0 & 1))
                   && (u32)(MSF->f_218 - 300) < 0x1F5) {
            func_80035A7C();
        } else {
            r = 0;
        }
    }
    if (r && !func_80033C34()) {
        st = MSF->state;
        if (st != 9 && st != 0x1A) {
            if (st != 0x35 && !(MSF->f_228 & 0x200) && !func_800339EC()) {
                MSF->f_EC = -1;
            }
        }
    }
    return r;
}

typedef struct { s16 on; s16 chance; s16 min; s16 max; } Win_37068;
typedef struct { u8 pad0[0x1E]; Win_37068 win[8]; u8 pad5E[0x2A]; } Kind_37068;
/* Monkey_AttackChance: chance in percent that the current monkey uses attack window i (kind +0x1E: 8 x
 * {on, chance, min, max distance}); the caller rolls 0..99 against it once Spike is in range.
 * While +0xD4 > 0 only window 7 counts, at 100x its chance (always). */
s32 Monkey_AttackChance(s16 i) {
    Monkey *m = g_CurMonkey;
    if (m->f_D4 <= 0) {
        return (u16)((Kind_37068 *)g_MonkeyKinds)[m->f_7C].win[i].chance;
    }
    if (i == 7) {
        return (u16)((Kind_37068 *)g_MonkeyKinds)[m->f_7C].win[7].chance * 100;
    }
}

s32 Monkey_TryReaction(s16 kind)
{
  int off;
  React_8003710C_8003710C *r;
  struct S_D_800AEBB4_8003710C *t;
  u16 roll;
  if ((kind == 1) && (((MR_8003710C_8003710C *) g_CurMonkey)->f_174 != 0))
  {
    return 0;
  }
  r = (React_8003710C_8003710C *) (((((MR_8003710C_8003710C *) g_CurMonkey)->kind * 0x88) + ((s32) g_MonkeyKinds)) + (kind * 8));
  if (r->chance == 0)
  {
    return 0;
  }
  off = kind * 8;
  if (((MR_8003710C_8003710C *) g_CurMonkey)->dist < r->min)
  {
    return 0;
  }
  if (r->max < ((MR_8003710C_8003710C *) g_CurMonkey)->dist)
  {
    return 0;
  }
  roll = ((u16) Monkey_Rand()) % 100;
  if (roll < Monkey_AttackChance(kind))
  {
    t = (struct S_D_800AEBB4_8003710C *) (off + ((s32) ((struct S_D_800AEBB4_8003710C *)&D_800AEBB4)));
    ((MR_8003710C_8003710C *) g_CurMonkey)->f_222 = t->mult * ((React_8003710C_8003710C *) (((((MR_8003710C_8003710C *) g_CurMonkey)->kind * 0x88) + ((s32) g_MonkeyKinds)) + off))->chance;
    if (kind == 1)
    {
      ((MR_8003710C_8003710C *) g_CurMonkey)->f_174 = 0x5A;
    }
    if (func_800339CC() != 0)
    {
      return 1;
    }
    ((MR_8003710C_8003710C *) g_CurMonkey)->state = t->state;
    if (!((D_800AE940[((MR_8003710C_8003710C *) g_CurMonkey)->state].f_4 >> 2) & 1))
    {
      ((MR_8003710C_8003710C *) g_CurMonkey)->f_96 = 0;
      ((MR_8003710C_8003710C *) g_CurMonkey)->f_128 = 0xC;
    }
    Monkey_RestartAnim();
    if ((kind == 0) || (kind == 5))
    {
      ((MR_8003710C_8003710C *) g_CurMonkey)->f_5C = g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0 + 4;
      ((MR_8003710C_8003710C *) g_CurMonkey)->f_7E = g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0;
    }
    if (kind == 7)
    {
      Monkey_QueueSound(func_800356C0(), 0);
    }
    return 1;
  }
  return 0;
}

s32 func_8003738C(void) {
    s32 i;
    s32 k;
    if (D_800EC2CA != 0) {
        return 100;
    }
    for (i = 0; i < 12; i++) {
        k = Monkey_Rand() & 7;
        if ((D_800AEBB4[k].f_4 & 1) && Monkey_TryReaction(k) != 0) {
            return k;
        }
    }
    return 100;
}

s32 func_80037420(void) {
    s32 i;
    s32 k;
    if (D_800EC2CA != 0) {
        return 100;
    }
    for (i = 0; i < 12; i++) {
        k = Monkey_Rand() & 7;
        if (((D_800AEBB4[k].f_4 >> 1) & 1) && Monkey_TryReaction(k) != 0) {
            return k;
        }
    }
    return 100;
}

s32 func_800374B8(void) {
    s32 i;
    s32 k;
    if (D_800EC2CA != 0) {
        return 100;
    }
    for (i = 0; i < 12; i++) {
        k = Monkey_Rand() & 7;
        if (((D_800AEBB4[k].f_4 >> 2) & 1) && Monkey_TryReaction(k) != 0) {
            return k;
        }
    }
    return 100;
}

void Monkey_PickNextAction(void) {
    u8 walk = 0;
    u8 near;
    s32 st;
    if (MS->state == 0xC || MS->state == 0x24) {
        walk = 1;
    }
    if ((MS->f_248 >> 20) & 1) {
        return;
    }
    if (MS->f_79 == 0) {
        ((u8 *)&MS->f_248)[1] = 0;
    }
    if (func_800339EC() && (*(struct Game_80037550 *)&g_Game).f_812C != 3) {
        if (MS->state == 0xB) {
            Monkey_RestartAnim();
        } else {
            Monkey_SetState(0xB);
        }
        return;
    }
    MS->f_79 = 1;
    near = (u32)(MS->f_20C - 300) < 0x4B1;
    if (!func_800339EC() && MS->state == 0xB && near) {
        goto leave;
    }
    if (((MS->f_248 >> 26) & 1) && near) {
        Monkey_SetState(0xB);
        goto after;
    }
    if (((D_800AE940[MS->state].f_4 >> 3) & 1) && MS->f_222 > 0) {
    leave:
        Monkey_RestartAnim();
        goto after;
    }
    if (Monkey_TrySpecialAction()) {
        goto done;
    }
    if (Monkey_CheckStateTimer() && (MS->state == 3 || MS->state == 8)) {
        return;
    }
    if (((MS->f_248 >> 23) & 1) && MS->state == 3) {
        if (func_8003738C() != 100) {
            return;
        }
    }
    if (MS->state != 8 && MS->state != 0x23 && MS->state != 0x39 && MS->f_94 <= 0 && (u16)Monkey_Rand() % 100 < 30) {
        Monkey_SetState(8);
    } else {
        Monkey_SetState(3);
    }
after:
    if (!func_80033C34()) {
        st = MS->state;
        if (st != 9 && st != 0x1A) {
            if (st != 0x35 && !(MS->f_228 & 0x200) && !func_800339EC()) {
                MS->f_EC = -1;
            }
        }
    }
done:
    if (walk && !func_80033C00()) {
        func_80039248();
    }
}

void func_800378C0(void) {
    if (M2C_FIELD(g_CurMonkey, u8 *, 0x79) == 1) {
        Monkey_PickNextAction();
        return;
    }
    Monkey_PickIdleAction();
}

void Monkey_PickIdleAction(void) {
    u8 was = MX->f_79 == 1;
    u8 walk = 0;
    s32 st;
    if (MX->state == 0xC || MX->state == 0x24) {
        walk = 1;
    }
    if ((MX->f_248 >> 20) & 1) {
        return;
    }
    if (func_800339EC()) {
        Monkey_PickNextAction();
        return;
    }
    MX->f_79 = 0;
    if (((D_800AE940[MX->state].f_4 >> 3) & 1) && MX->f_222 > 0) {
        Monkey_RestartAnim();
    } else if (!Monkey_TrySpecialAction()) {
        if (KX[MX->kind].f_2 == 0 && KX[MX->kind].f_4 == 0) {
            if (KX[MX->kind].f_12 >= MX->f_20C || (u16)Monkey_Rand() % 100 < KX[MX->kind].f_8) {
                func_80036300();
            } else {
                Monkey_SetState(0);
            }
        } else if (MX->f_94 > 0) {
            Monkey_SetState(2);
        } else if (MX->state == 0x19) {
            Monkey_SetState(0x18);
        } else if ((MX->state == 2 || func_80033B9C()) && (u16)Monkey_Rand() % 100 < KX[MX->kind].f_8) {
            func_80036300();
        } else if (MX->state == 2 && (u16)Monkey_Rand() % 100 < 10) {
            if (!(Monkey_Rand() & 1)) {
                Monkey_SetState(0x27);
            } else {
                Monkey_SetState(0x28);
            }
        } else if (was) {
            if (KX[MX->kind].f_E < MX->f_20C) {
                Monkey_SetState(0x18);
            } else {
                Monkey_SetState(0x19);
            }
        } else if ((u16)Monkey_Rand() % 100 < 9) {
            func_8003641C();
        } else {
            Monkey_SetState(2);
        }
    }
    if (!func_80033C34()) {
        st = MX->state;
        if (st != 9 && st != 0x1A) {
            if (st != 0x35 && !(MX->f_228 & 0x200) && !func_800339EC()) {
                MX->f_EC = -1;
            }
        }
    }
    if (walk && !func_80033C00()) {
        func_80039248();
    }
}

s32 Monkey_AvoidConeAngleAlt(void) {
    s32 d = g_CurMonkey->f_20C;
    if (d < 800) {
        return 50;
    }
    if (d > 2000) {
        return 0;
    }
    return ((2000 - d) / 24 << 12) / 360;
}

/* Half-angle (4096 = 360 degrees) of the cone a monkey avoids when picking its next path
   link: 60 degrees while f_20C (distance) is under 260, shrinking linearly to 0 at 3000. */
s32 Monkey_AvoidConeAngle(void) {
    s32 d = g_CurMonkey->f_20C;
    s32 lo = 0x104;
    s32 hi = 3000;
    if (d < lo) {
        return 0x2AA;
    }
    if (d > hi) {
        return 0;
    }
    return ((hi - d) * 60 / (hi - lo) << 12) / 360;
}

/* Returns 1 if the current monkey may do action `act` (of kind `a`): func_8003B880 gives the
 * action's requirement flags and a parameter, then each flag is checked: 0x40/0x80 a condition
 * (func_800335D0) that must hold / must not hold, 0x400 the target within `param` distance,
 * 0x1000 sub-state f_7C == param, 0x200000 / 0x400000 f_79 must / must not be 1, 0x40000
 * func_80052C4C(param) != 1, and actions flagged 0x100 only for the monkey's own action f_E6. */
s32 Monkey_CanDoAction(s32 a, s32 act)
{
  V4_80037E8C_80037E8C tgt;
  V4_80037E8C_80037E8C pos;
  s32 param;
  u32 f = func_8003B880(a, act, &param);
  if ((f & 0x40) && (func_800335D0(param) == 0))
  {
    return 0;
  }
  if (f & 0x80)
  {
    if (func_800335D0(param) != 0)
    {
      if (param || g_CurMonkey) /* both arms return 0; only reproduces the original layout */
      {
        return 0;
      }
      else
      {
        return 0;
      }
    }
  }
  if (f & 0x400)
  {
    pos.x = g_CurMonkey->f_24;
    pos.y = g_CurMonkey->f_28;
    pos.z = g_CurMonkey->f_2C;
    Node_GetPosition(act, &tgt);
    if (param < Vec_Dist(&pos, &tgt))
    {
      return 0;
    }
  }
  if ((f & 0x1000) && (g_CurMonkey->f_7C != param))
  {
    return 0;
  }
  if ((f & 0x200000) && (g_CurMonkey->f_79 != 1))
  {
    return 0;
  }
  if ((f & 0x400000) && (g_CurMonkey->f_79 == 1))
  {
    return 0;
  }
  if ((f & 0x40000) && (func_80052C4C(param) == 1))
  {
    return 0;
  }
  if ((D_800B4D00[act].f_0 & 0x100) && (act != g_CurMonkey->f_E6))
  {
    return 0;
  }
  return 1;
}

void func_80038054(s16 i) {
    Monkey *m = g_CurMonkey;
    s32 k;
    s32 n;
    u8 *p;
    for (k = 0x31, p = (u8 *)m + 0x31; k >= 0; k--, p--) {
        p[0x1DA] = 0;
    }
    n = D_800B4D00[i].f_B;
    for (k = 0; k < n; k++) {
        if (Monkey_CanDoAction(i, Node_GetLink(i, k)) == 0) {
            m->f_1DA[k] = 1;
        }
    }
}

/* Chooses the next node for the current monkey. A monkey that noticed its target takes a random
 * link. Otherwise each usable link (not the previous node f_EC, not blocked in f_1DA) is scored
 * by the node's priority for this monkey's route group (D_800B4D00[n].f_14[f_7B]); the best one
 * is taken if it beats the current node (or `force`) and, for an alerted monkey (f_79), its link
 * score f_176 is under a cosine threshold. Returns the node, or -1 to stay. */
s32 Monkey_PickGoalLink(s16 force)
{
  s16 links[50];
  SVECTOR d;
  s32 thr;
  s32 a;
  s32 i;
  s16 n;
  s16 best;
  s16 bi;
  s16 bj;
  s16 j;
  s16 cp;
  s32 p;
  if (func_800339EC())
  {
    return Node_GetLink(g_CurMonkey->f_F2, ((u16) Monkey_Rand()) % D_800B4D00[g_CurMonkey->f_F2].f_B);
  }
  if (func_80032F24() != 0)
  {
    thr = rcos(0);
  }
  else
    if (func_8003398C())
  {
    thr = rcos(Monkey_AvoidConeAngleAlt());
  }
  else
    if ((g_CurMonkey->f_248 >> 26) & 1)
  {
    thr = rcos(0x38);
  }
  else
  {
    thr = rcos(Monkey_AvoidConeAngle());
  }
  if (func_80033C00())
  {
    thr *= 2;
  }
  d.vx = g_MonkeyTarget->f_24 - g_CurMonkey->f_24;
  d.vy = g_MonkeyTarget->f_28 - g_CurMonkey->f_28;
  d.vz = g_MonkeyTarget->f_2C - g_CurMonkey->f_2C;
  best = -10000;
  bi = -1;
  func_80038054(g_CurMonkey->f_F2);
  n = 0;
  for (i = 0; i < D_800B4D00[g_CurMonkey->f_F2].f_B; i++)
  {
    j = Node_GetLink(g_CurMonkey->f_F2, i);
    if ((j == ((s16) g_CurMonkey->f_EC)) || (g_CurMonkey->f_1DA[i] != 0))
    {
      continue;
    }
    links[n++] = j;
    if (D_800B4D00[j].f_14[g_CurMonkey->f_7B] > best)
    {
      best = D_800B4D00[j].f_14[g_CurMonkey->f_7B];
      bi = i;
      bj = j;
    }
  }

  cp = D_800B4D00[g_CurMonkey->f_F2].f_14[g_CurMonkey->f_7B];
  if ((best == 0) && (cp == 0))
  {
    if ((g_CurMonkey->f_248 >> 27) & 1)
    {
      g_CurMonkey->f_248 &= ~0x8000000;
    }
    return -1;
  }
  if ((cp >= best) && (force == 0))
  {
    return -1;
  }
  if (bi >= 0)
  {
    if ((((g_CurMonkey->f_79 == 0) || func_800339EC()) || (g_CurMonkey->f_78 == 0x3D)) || (g_CurMonkey->f_176[bi] < thr))
    {
      return bj;
    }
  }
  for (i = 0; i < D_800B4D00[g_CurMonkey->f_F2].f_B; i++)
  {
    j = Node_GetLink(g_CurMonkey->f_F2, i);
    if ((j == ((s16) g_CurMonkey->f_EC)) || (g_CurMonkey->f_1DA[i] != 0))
    {
      continue;
    }
    p = D_800B4D00[j].f_14[g_CurMonkey->f_7B];
    if ((cp < p) || (((best == 0) && (cp == 0)) && (p == 0)))
    {
      if ((g_CurMonkey->f_79 == 0) || (g_CurMonkey->f_176[i] < thr))
      {
        return j;
      }
    }
  }

  return -1;
}

s32 Node_LinkFlag(s16 n, s16 v)
{
  s32 j;
  s32 c = D_800B4D00[n].f_A;
  for (j = 0; j < c; j++)
  {
    if (v < (D_800B4D00[n].f_C[j] & 0x3FFF))
    {
      return 0;
    }
    if ((D_800B4D00[n].f_C[j] & 0x3FFF) == v)
    {
      return (s16)(D_800B4D00[n].f_C[j] & 0x4000);
    }
  }

  return 0;
}

void Monkey_SwapPathNodes(void) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(g_CurMonkey, u16 *, 0xF2);
    M2C_FIELD(g_CurMonkey, u16 *, 0xF2) = (u16) M2C_FIELD(g_CurMonkey, u16 *, 0xF4);
    M2C_FIELD(g_CurMonkey, u16 *, 0xF4) = temp_a0;
    func_800355DC();
}

s32 Monkey_CheckRouteAway(void) {
    SVECTOR toT;
    SVECTOR toP;
    V4_800386C8_800386C8 pt;
    s32 ang;
    s16 d;
    if (func_800339EC() != 0) {
        return 1;
    }
    if (g_CurMonkey->f_F2 == (s16)g_CurMonkey->f_EC) {
        goto turn;
    }
    if (g_CurMonkey->f_F4 == (s16)g_CurMonkey->f_EC) {
        return 1;
    }
    if (Node_LinkFlag(g_CurMonkey->f_F2, g_CurMonkey->f_F4) == 0) {
        return 1;
    }
    if (Node_LinkFlag(g_CurMonkey->f_F4, g_CurMonkey->f_F2) == 0) {
        return ((s32 (*)(void))Monkey_SwapPathNodes)();
    }
    if (func_8003398C() != 0) {
        ang = Monkey_AvoidConeAngleAlt();
    } else {
        ang = Monkey_AvoidConeAngle();
    }
    toT.vx = g_MonkeyTarget->f_24 - g_CurMonkey->f_24;
    toT.vy = 0;
    toT.vz = g_MonkeyTarget->f_2C - g_CurMonkey->f_2C;
    if (D_800B4D00[g_CurMonkey->f_F2].f_14[g_CurMonkey->f_7B] < D_800B4D00[g_CurMonkey->f_F4].f_14[g_CurMonkey->f_7B]) {
        Node_GetPosition(g_CurMonkey->f_F4, &pt);
        toP.vx = pt.x - g_CurMonkey->f_24;
        toP.vy = 0;
        toP.vz = pt.z - g_CurMonkey->f_2C;
        if (func_80032F24() == 0) {
            d = (s16)SVec_DotXZ(&toT, &toP);
            if (d >= rcos(ang)) {
                return 0;
            }
        }
    turn:
        Monkey_SwapPathNodes();
        return 1;
    }
    Node_GetPosition(g_CurMonkey->f_F2, &pt);
    toP.vx = pt.x - g_CurMonkey->f_24;
    toP.vy = 0;
    toP.vz = pt.z - g_CurMonkey->f_2C;
    if (func_80032F24() != 0 || (s16)SVec_DotXZ(&toT, &toP) < rcos(ang)) {
        return 1;
    }
    return 0;
}

void func_80038914(void) {
    s16 a;
    s16 b;

    if (g_CurMonkey->f_F2 != (s16)g_CurMonkey->f_EC) {
        if (g_CurMonkey->f_F4 == (s16)g_CurMonkey->f_EC) {
            return;
        }
        if (Node_LinkFlag(g_CurMonkey->f_F2, g_CurMonkey->f_F4) == 0) {
            return;
        }
        if (Node_LinkFlag(g_CurMonkey->f_F4, g_CurMonkey->f_F2) != 0) {
            if ((u16)Monkey_Rand() % 10 < 7) {
                return;
            }
            if (func_8003B534(&a, &b) == 0) {
                return;
            }
            if (a <= rcos(0x2AA)) {
                return;
            }
            if (a <= b) {
                return;
            }
        }
    }
    Monkey_SwapPathNodes();
}

s32 func_80038A1C(s16 a, s16 b) {
    func_80035474();
    if (a != 0 || Monkey_IsTargetInRange() != 0) {
        s16 r = Monkey_PickGoalLink(b);
        if (r == -1) {
            return 0;
        }
        Monkey_GoToNode(r);
        return 1;
    }
    return Monkey_CheckRouteAway();
}

/* Picks the next path node for g_CurMonkey from its node f_F2. A calm monkey (f_79 == 0) takes the
 * first link that does not lead back (f_EC) and is not blocked (f_1DA[i] == 1). An alert one scores
 * the links against its target (Monkey_ScoreLinks -> f_176[]) and takes the lowest score, with a 5%
 * chance per link of taking one already under the threshold cos(60 deg) (or cos of the
 * Monkey_AvoidConeAngleAlt angle when func_8003398C); if nothing beats the threshold it gives up unless
 * force, and when no link was scored at all it falls back to the first free link. With any == 0
 * and the target out of range it does func_80038914 instead. Returns 1 when it set off. */
s32 Monkey_PickNextNode(s16 any, s16 force) {
    s32 thr;
    s16 i;
    s16 next;
    s16 j;
    s16 d;
    s16 best;
    s16 bestj;

    thr = rcos(0x2AA);
    func_80038054(g_CurMonkey->f_F2);
    if (g_CurMonkey->f_79 == 0) {
        for (i = 0; i < D_800B4D00[g_CurMonkey->f_F2].f_B; i++) {
            j = Node_GetLink(g_CurMonkey->f_F2, i);
            if (j != (s16)g_CurMonkey->f_EC && g_CurMonkey->f_1DA[i] != 1) {
                goto found1;
            }
        }
        goto fail;
    }
    if (func_8003398C()) {
        thr = rcos((Monkey_AvoidConeAngleAlt() << 12) / 360);
    }
    func_80035474();
    if (any == 0 && !Monkey_IsTargetInRange()) {
        goto notarget;
    }
    Monkey_ScoreLinks(g_CurMonkey->f_F2);
    best = 0x2000;
    bestj = -1;
    for (i = 0; i < D_800B4D00[g_CurMonkey->f_F2].f_B; i++) {
        next = Node_GetLink(g_CurMonkey->f_F2, i);
        if (next == (s16)g_CurMonkey->f_EC || g_CurMonkey->f_1DA[i] == 1) {
            continue;
        }
        d = g_CurMonkey->f_176[i];
        if (d < thr && (u16)Monkey_Rand() % 100 < 5) {
            best = d;
            bestj = next;
            break;
        }
        if (d < best) {
            best = d;
            bestj = next;
        }
    }
    if (force == 0 && best >= thr) {
        goto fail;
    }
    if (bestj >= 0) {
        Monkey_GoToNode(bestj);
        return 1;
    }
    if (D_800B4D00[g_CurMonkey->f_F2].f_B == 0) {
        return 0;
    }
    for (i = 0; i < D_800B4D00[g_CurMonkey->f_F2].f_B; i++) {
        j = Node_GetLink(g_CurMonkey->f_F2, i);
        if (j != (s16)g_CurMonkey->f_EC && g_CurMonkey->f_1DA[i] != 1) {
            goto found3;
        }
    }
fail:
    func_800355DC();
    return 0;
found1:
    Monkey_GoToNode(j);
    return 1;
found3:
    Monkey_GoToNode(j);
    return 1;
notarget:
    func_80038914();
    return 1;
}

void func_80038F00(void) {
    s16 v[3];
    Monkey *m;
    if (D_800AEB60 % 3 != 0) {
        return;
    }
    m = g_CurMonkey;
    if (g_MonkeyKinds[m->f_7C].f_4 == 0) {
        return;
    }
    if (m->f_78 == 0x1A || m->f_78 == 0x35) {
        return;
    }
    if (func_80033C00() != 0) {
        return;
    }
    v[0] = g_CurMonkey->f_24;
    v[1] = g_CurMonkey->f_28 - 0x20;
    v[2] = g_CurMonkey->f_2C;
    Effect_SpawnAt(9, v);
}

void func_80038FD8(void) {
    s16 p[4];
    s16 v[4];
    s32 i;

    p[0] = g_CurMonkey->f_24;
    p[1] = g_CurMonkey->f_28;
    p[2] = g_CurMonkey->f_2C;
    for (i = 0; i < 6; i++) {
        v[0] = p[0] - ((u16)Monkey_Rand() % 200 - 100);
        v[1] = p[1] - ((u16)Monkey_Rand() % 200 - 50);
        v[2] = p[2] - ((u16)Monkey_Rand() % 200 - 100);
        Effect_SpawnAt(7, v);
    }
}

void func_800390F8(void) {
    s16 p[4];
    s16 v[4];

    p[0] = g_CurMonkey->f_24;
    p[1] = g_CurMonkey->f_28;
    p[2] = g_CurMonkey->f_2C;
    v[0] = p[0] - ((u16)Monkey_Rand() % 200 - 100);
    v[1] = p[1] - ((u16)Monkey_Rand() % 200 - 50);
    v[2] = p[2] - ((u16)Monkey_Rand() % 200 - 100);
    Effect_SpawnAt(7, v);
}

void func_80039200(void) {
    Monkey *p = g_CurMonkey;
    s16 v[3];
    v[0] = p->f_24;
    v[1] = p->f_28;
    v[2] = p->f_2C;
    Effect_SpawnAt(0x14, v);
}

void func_80039248() {
    Monkey *p = g_CurMonkey;
    s16 v[3];
    v[0] = p->f_24;
    v[1] = p->f_28;
    v[2] = p->f_2C;
    Effect_SpawnAt(0x100, v);
    Monkey_QueueSound(0x72, 1);
}

void func_8003929C(void) {
    Monkey *p = g_CurMonkey;
    s16 v[3];
    v[0] = p->f_24;
    v[1] = p->f_28;
    v[2] = p->f_2C;
    Effect_SpawnAt(5, v);
}

u32 func_800392E4(void *arg0) {
    return (u32) M2C_FIELD(arg0, u32 *, 0x50) >> 0x1C;
}

s32 func_800392F0(void) {
    s32 r = func_800392E4((*(M_392F0_800392F0 * *)&g_CurMonkey));

    if (((*(M_392F0_800392F0 * *)&g_CurMonkey)->f_78 == 0x1E || (*(M_392F0_800392F0 * *)&g_CurMonkey)->f_78 == 0x20) && r == 8) {
        (*(M_392F0_800392F0 * *)&g_CurMonkey)->f_126 = 0;
        goto miss;
    }
    (*(M_392F0_800392F0 * *)&g_CurMonkey)->f_126 = r;
    if (r == 8 || r == 1 || r == 11 || r == 10) {
        return 1;
    }
    if (r != 3) {
        return 0;
    }
    if ((*(M_392F0_800392F0 * *)&g_CurMonkey)->f_78 != 2 && func_80033B10() == 0 && !((*(M_392F0_800392F0 * *)&g_CurMonkey)->f_228 & 0x8000)) {
        goto miss;
    }
    if ((*(M_392F0_800392F0 * *)&g_CurMonkey)->f_124 <= 0) {
        return 1;
    }
miss:
    return 0;
}

/* Returns 1 if the current monkey is off-screen or far from the camera (more than
 * 6000 away, or projected outside x -50..434 / y -25..265, or behind the camera). Also
 * stores its screen position.
 */
s32 Monkey_IsOffScreen(void) {
    SVECTOR v;
    s32 sxy;
    s32 p;
    s32 flag;
    u16 x;
    s16 y;
    s32 z;
    if (g_CurMonkey->f_7A == 0 || g_CurMonkey->f_7A == 2) {
        return 1;
    }
    if (Vec_DistXZ_SV(&g_CurMonkey->f_24, &g_CameraTarget) > 6000) {
        return 1;
    }
    SetRotMatrix(&D_800E78C0);
    SetTransMatrix(&D_800E78C0);
    v.vx = g_CurMonkey->f_24;
    v.vy = g_CurMonkey->f_28;
    v.vz = g_CurMonkey->f_2C;
    z = RotTransPers(&v, &sxy, &p, &flag);
    x = sxy;
    y = sxy >> 16;
    ((S_80_800393E4_800393E4 *)g_CurMonkey)->f_80 = x;
    v.vx = g_CurMonkey->f_24;
    v.vy = g_CurMonkey->f_28 - 400;
    v.vz = g_CurMonkey->f_2C;
    RotTransPers(&v, &sxy, &p, &flag);
    ((S_80_800393E4_800393E4 *)g_CurMonkey)->f_82 = sxy >> 16;
    if ((u16)(x + 50) < 0x1E5) {
        if (y >= -25) {
            if (y < 0x10A) {
                if (z > 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void func_80039530(s32 *arg0, u16 *arg1, u16 *arg2) {
    *arg1 = M2C_FIELD(g_Monkeys.f_16C, u16 *, 0xC8);
    *arg2 = M2C_FIELD(g_Monkeys.f_16C, u16 *, 0xCA);
    *arg0 = g_Game.f_8240 + M2C_FIELD(D_800B4D14, s32 *, 0x20);
}

/* Sets up the monkey records for the area (max 4; prints an error if it asks
 * for more).
 */
INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", Monkey_InitAll);

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4930);


void func_80039B30(void) {
    if (func_80033B10() == 0) {
        func_80035474();
    }
    g_CurMonkey->f_20C = Vec_Dist(&g_CurMonkey->f_24, &g_MonkeyTarget->f_24);
    g_CurMonkey->f_21C = func_8003455C();
}

/* Helmet-light alert level of the current monkey (user: blue calm, yellow after losing sight of Spike
   before going calm, red alerted): 0x1C0 (yellow) when it is alerted and its
   lost-sight counter (f_248 byte 1) is within 2 of func_80033000(), or f_248 bit 19 is set; else 0 when calm
   (f_79 == 0) and 0x380 when alerted. The || chain keeps g_CurMonkey's %hi in s0. */
s32 Monkey_GetAlertLevel(void) {
    s32 one = 1;
    if ((g_CurMonkey->f_79 == one && func_80033000() - ((u8 *)&g_CurMonkey->f_248)[1] < 2) || ((g_CurMonkey->f_248 >> 19) & 1)) {
        return 0x1C0;
    }
    if (g_CurMonkey->f_79 == 0) {
        return 0;
    }
    if (g_CurMonkey->f_79 == one) {
        return 0x380;
    }
}

/* The light on the current monkey's helmet: its level comes from Monkey_GetAlertLevel (0, 0x1C0 or
 * 0x380 -> light kind 0, 1, 2) and flashes for 10 frames when it changes. It is shown while
 * flashing, in states flagged 8 in D_800AE940, or when func_80033C80/func_80033B10 say so; it
 * sits 100 above the head joint (D_800F4730[6]) at LOD 0-2, else at the monkey's position.
 * The do/while (0) around vis = 1 is needed to match. */
void Monkey_UpdateHelmetLight(void) {
    SVECTOR v;
    s32 kind;
    s32 vis;
    s32 a = Monkey_GetAlertLevel();

    if (M_39C38->alert != a) {
        M_39C38->flash = 10;
    }
    M_39C38->alert = a;
    switch (a) {
    case 0:
        kind = 0;
        break;
    case 0x1C0:
        kind = 1;
        break;
    case 0x380:
        kind = 2;
        break;
    default:
        kind = 0;
        break;
    }
    if (M_39C38->flash > 0 || (D_800AE940[M_39C38->state].f_4 >> 3 & 1) || func_80033C80() != 0 ||
        func_80033B10() != 0) {
        do {
            vis = 1;
        } while (0);
    } else {
        vis = 0;
    }
    switch (M_39C38->lod) {
    case 0:
    case 1:
    case 2:
        v.vx = 0;
        v.vy = 100;
        v.vz = 0;
        ApplyMatrixSV(&D_800F4730[6], &v, &v);
        v.vx += D_800F4730[6].t[0];
        v.vy += D_800F4730[6].t[1] + 0xDC;
        v.vz += D_800F4730[6].t[2];
        break;
    case 3:
        v.vx = M_39C38->x;
        v.vy = M_39C38->y + 10;
        v.vz = M_39C38->z;
        break;
    default:
        v.vx = M_39C38->x;
        v.vy = M_39C38->y;
        v.vz = M_39C38->z;
        break;
    }
    Monkey_DrawHelmetLight(&v, kind, vis);
    M_39C38->flash--;
}

void func_80039E50(Model_39E50_80039E50 *m) {
    Model_ProjectVerts(m, &D_800E9C60[m->hdr->f_4], D_800E7D00);
    func_80017CD4(&(*(Game_39E50_80039E50 *)&g_Game).db[(*(Game_39E50_80039E50 *)&g_Game).cur], D_800E7D00, m);
}

/* Draws g_CurMonkey: only on frames where f_7A == 4, or f_7A == 3 and f_90 % 3 == 0.
 * Builds the body matrix (scaled by rcos/rsin of f_F0 while spawning in, per f_24A & 3),
 * draws it (plain when func_800339EC, else at detail level f_D5), adds stage extras
 * (stage 0x46 model; stage 0x24 model plus loop sound 0x602D while in state 0x1A),
 * the per-kind attachment models, and one more model picked by D_800AEBF8[kind f_0 >> 6]
 * (probably the helmet light). */
void Monkey_Draw(void) {
    s32 scale[3];
    s16 i;
    s16 k;
    Model_39ED4_80039ED4 *mdl;

    if (CM->f_7A == 4 || (CM->f_7A == 3 && CM->f_90 % 3 == 0)) {
        if (func_80033C00()) {
            Matrix_FromDirection(&CM->rot, CM->mat);
        } else {
            func_80014804(&CM->rot, CM->mat);
        }
        if (CM->f_F0 <= 0) {
            if ((CM->f_24A & 3) == 2) {
                scale[0] = scale[1] = scale[2] = rcos(CM->f_F0 << 10);
            } else if ((CM->f_24A & 3) == 1) {
                scale[0] = scale[1] = scale[2] = rsin(CM->f_F0 << 10);
            }
            if ((u32)((CM->f_24A & 3) - 1) < 2) {
                ScaleMatrix(CM->mat, scale);
            }
        }
        Model_CalcJointMatrices(CM, 3);
        Model_ProjectBonedVerts(CM);
        if (func_800339EC()) {
            func_80017CD4((Db_39E50_80039E50 *)GDB->db[GDB->cur].ot, D_800E7D00, (Model_39E50_80039E50 *)CM);
        } else if (CM->f_D5 == 3) {
            func_80017D94(GDB->db[GDB->cur].ot, D_800E7D00, CM, 0);
        } else {
            Monkey_UpdateHelmetLight();
            func_80017D94(&GDB->db[GDB->cur].ot[4], D_800E7D00, CM, CM->f_14C + KIND(CM)->f_0);
        }
        if (((GameS_39ED4_80039ED4 *)((u8 *)&g_Game))->f_8126 == 0x46) {
            func_80039E50(&D_800F46B0);
        }
        if (((GameS_39ED4_80039ED4 *)((u8 *)&g_Game))->f_8126 == 0x24) {
            if (CM->f_78 == 0x1A) {
                mdl = &D_800EC180;
                if (CM->f_160 == -1) {
                    CM->f_160 = func_800882C4(1, 0x602D, CM->f_7C);
                }
            } else {
                mdl = &D_800EC0C0;
                if (CM->f_160 != -1) {
                    func_800880D0(0x602D, CM->f_160);
                    CM->f_160 = -1;
                }
            }
            func_80039E50(mdl);
        }
        if (CM->f_78 != 0x1E && CM->f_78 != 0x20) {
            for (i = 0; i < 8; i++) {
                if (KIND(CM)->parts[i].f_2 != 0) {
                    k = D_800AEBB4_[i].f_2;
                    if (k != -1) {
                        func_80039E50(&D_800F4630[k]);
                    }
                }
            }
        }
        if (!func_800339EC() && CM->f_D5 != 3) {
            func_80039E50(&D_800F4630[D_800AEBF8[KIND(CM)->f_0 >> 6]]);
        }
    }
}

s32 func_8003A334(void) {
    return 0;
}

/* Picks the monkey model's level of detail from its distance to the camera
 * (< 1000, < 2000, further).
 */
void Monkey_UpdateLod(void) {
    Monkey *m = g_CurMonkey;
    s32 lod;
    u8 cur = m->f_D5;
    if (m->f_78 == 0x1E || m->f_78 == 0x20) {
        lod = 3;
        m->f_46 = 0x100;
    } else {
        s32 d = Vec_DistXZ_SV(&m->f_24, &g_CameraTarget);
        if (D_800E6908 == 1 || d < 1000) {
            lod = 0;
        } else if (d < 2000) {
            lod = 1;
        } else {
            lod = 2;
        }
    }
    if (cur != lod) {
        func_80015AC0(g_CurMonkey, ((struct S_D_800EC350_8003A33C *)&g_Game)->f_81A4[lod]);
        g_CurMonkey->f_D5 = lod;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", Monkey_Spawn);

void Monkey_ScoreLinks(s16 k) {
    VEC_80040CFC_8003AC54 t;
    SVEC_8003AC54 d;
    SVEC_8003AC54 r;
    s32 i;
    d.vx = g_MonkeyTarget->f_24 - g_CurMonkey->f_24;
    d.vy = g_MonkeyTarget->f_28 - g_CurMonkey->f_28;
    d.vz = g_MonkeyTarget->f_2C - g_CurMonkey->f_2C;
    for (i = 0; i < D_800B4D00[k].f_B; i++) {
        Node_GetPosition(Node_GetLink(k, i), &t);
        r.vx = t.vx - g_CurMonkey->f_24;
        r.vy = t.vy - g_CurMonkey->f_28;
        r.vz = t.vz - g_CurMonkey->f_2C;
        ((S_176_8003AC54_8003AC54 *)g_CurMonkey)->f_176[i] = SVec_DotXZ(&d, &r);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8003AD9C);

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4964);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4988);


/* Route decision when g_CurMonkey reaches a path node (f_F2). A calm monkey (f_79 == 0) tries
 * func_80038A1C and else Monkey_PickNextNode. An alert one does the same (forced while
 * func_800339EC), state 0x3D jumps straight along link 0, and failing that it stays. Unless the
 * chosen node is flagged 0x10000 (or force is 1) it then looks one node further: the lowest scored
 * link that does not lead back, else a random one of up to 10 candidates; with none it restores its
 * path history (f_F2[6]) and calls func_800363E4. Arriving at a new node fires Monkey_NodeEvents;
 * Monkey_StartLink starts the move. Returns 1 when it moves. */
u8 Monkey_ChooseRoute(s16 any, s16 force) {
    u16 hist[6];
    s32 cand[10];
    u16 start;
    u8 moved;
    s32 i;
    s32 n;
    s32 best;
    s32 bi;
    Monkey *m;

    moved = 1;
    start = g_CurMonkey->f_F2;
    for (i = 0; i < 6; i++) {
        hist[i] = (&g_CurMonkey->f_F2)[i];
    }
    if (((g_CurMonkey->f_248 >> 27) & 1) && g_CurMonkey->f_F2 == g_CurMonkey->f_E6) {
        func_8003398C();
        func_8003AD9C();
    }
    func_80038054(g_CurMonkey->f_F2);
    Monkey_ScoreLinks(g_CurMonkey->f_F2);
    if (g_CurMonkey->f_79 == 0) {
        if (func_80038A1C(any, 1) == 0) {
            Monkey_PickNextNode(any, 1);
        }
        goto end;
    }
    if (func_800339EC()) {
        force = 1;
    }
    if (func_80038A1C(any, force) == 0) {
        if (func_800339EC()) {
            goto stay;
        }
        if (g_CurMonkey->f_78 == 0x3D) {
            goto jump;
        }
        if (Monkey_PickNextNode(any, 1) == 0) {
            goto stay;
        }
    }
    if (D_800B4D00[g_CurMonkey->f_F4].f_0 & 0x10000) {
        goto end;
    }
    if (force == 1) {
        goto end;
    }
    if (Monkey_IsPathLooping() == 0) {
        goto end;
    }
    Monkey_ScoreLinks(g_CurMonkey->f_F4);
    func_80038054(g_CurMonkey->f_F4);
    best = 0x40000000;
    bi = -1;
    n = 0;
    for (i = 0; i < D_800B4D00[g_CurMonkey->f_F4].f_B; i++) {
        if (Node_GetLink(g_CurMonkey->f_F4, i) == g_CurMonkey->f_F2) {
            continue;
        }
        if (Node_GetLink(g_CurMonkey->f_F4, i) == (s16)g_CurMonkey->f_EC) {
            continue;
        }
        if (g_CurMonkey->f_1DA[i] != 0) {
            continue;
        }
        if (g_CurMonkey->f_176[i] < best) {
            best = g_CurMonkey->f_176[i];
            bi = i;
        } else if (n < 10) {
            cand[n++] = i;
        }
    }
    if (bi != -1) {
        g_CurMonkey->f_F2 = Node_GetLink(g_CurMonkey->f_F4, bi);
        func_800355DC();
        goto end;
    }
    if (n > 0) {
        g_CurMonkey->f_F2 = Node_GetLink(g_CurMonkey->f_F4, cand[(u16)Monkey_Rand() % n]);
        func_800355DC();
        goto end;
    }
    m = g_CurMonkey;
    for (i = 0; i < 6; i++) {
        (&m->f_F2)[i] = hist[i];
    }
    func_800363E4();
    moved = 0;
    goto end;
stay:
    if (g_CurMonkey->f_78 == 0x3D) {
    jump:
        Monkey_GoToNode(Node_GetLink(g_CurMonkey->f_F2, 0));
        moved = 1;
    } else {
        moved = 0;
    }
end:
    if ((s16)start != g_CurMonkey->f_F2) {
        Monkey_NodeEvents(g_CurMonkey->f_F4);
    }
    if (moved) {
        Monkey_StartLink(g_CurMonkey->f_F4, g_CurMonkey->f_F2);
    }
    if (force && !moved) {
        bios_printf(D_800A499C, (s16)start);
    }
    return moved;
}

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A499C);


s32 func_8003B534(s16 *a, s16 *b) {
    SVEC_8003B534 r;
    SVEC_8003B534 d;
    VEC_80040CFC_8003B534 t;
    d.vx = g_MonkeyTarget->f_24 - g_CurMonkey->f_24;
    d.vy = g_MonkeyTarget->f_28 - g_CurMonkey->f_28;
    d.vz = g_MonkeyTarget->f_2C - g_CurMonkey->f_2C;
    Node_GetPosition(g_CurMonkey->f_F2, &t);
    r.vx = t.vx - g_CurMonkey->f_24;
    r.vy = t.vy - g_CurMonkey->f_28;
    r.vz = t.vz - g_CurMonkey->f_2C;
    *a = SVec_DotXZ(&d, &r);
    Node_GetPosition(g_CurMonkey->f_F4, &t);
    r.vx = t.vx - g_CurMonkey->f_24;
    r.vy = t.vy - g_CurMonkey->f_28;
    r.vz = t.vz - g_CurMonkey->f_2C;
    *b = SVec_DotXZ(&d, &r);
}

/* Put the monkey on the path link from -> to (if the nodes are linked): look the pair up in the
   sorted link-flag table D_800B4D1C (count D_800B4D20) into f_228, then derive move settings:
   f_4A -0x4000 (special modes or flag 0x2000000) else -0x8000; flag 0x200 makes `from` the goal;
   flags 0x2000 / 0x4000000 clear bits 0x800000 / 0x40000 of f_248 (else set them). */
void Monkey_StartLink(from, to)
    s16 from, to;
{
    s32 lo, hi;
    s32 i;
    if (Node_LinkFlag(from, to) == 0) {
        return;
    }
    if (from < to) {
        lo = from;
        hi = to;
    } else {
        hi = from;
        lo = to;
    }
    if (M_3B674->f_224 == from && M_3B674->f_226 == to) {
        return;
    }
    M_3B674->f_228 = 0;
    M_3B674->f_224 = from;
    M_3B674->f_226 = to;
    for (i = 0; i < D_800B4D20; i++) {
        if (lo < (*(Pair_8003B674_8003B674 * *)&D_800B4D1C)[i].a) {
            break;
        }
        if ((*(Pair_8003B674_8003B674 * *)&D_800B4D1C)[i].a == lo) {
            if (hi < (*(Pair_8003B674_8003B674 * *)&D_800B4D1C)[i].b) {
                break;
            }
            if ((*(Pair_8003B674_8003B674 * *)&D_800B4D1C)[i].b == hi) {
                M_3B674->f_228 = (*(Pair_8003B674_8003B674 * *)&D_800B4D1C)[i].flags;
                break;
            }
        }
    }
    if (func_800339EC() != 0 || (M_3B674->f_228 & 0x2000000)) {
        M_3B674->f_4A = -0x4000;
    } else {
        M_3B674->f_4A = -0x8000;
    }
    if (M_3B674->f_228 & 0x200) {
        M_3B674->f_EC = from;
    }
    if (M_3B674->f_228 & 0x2000) {
        M_3B674->f_248 &= ~0x800000;
    } else {
        M_3B674->f_248 |= 0x800000;
    }
    if (M_3B674->f_228 & 0x4000000) {
        M_3B674->f_248 &= ~0x40000;
    } else {
        M_3B674->f_248 |= 0x40000;
    }
}

s32 func_8003B880(s16 a, s16 b, s32 *out) {
    s16 lo = a;
    s16 hi = b;
    s32 i;
    if (Node_LinkFlag(a, b) == 0) {
        return 0;
    }
    if (b < a) {
        hi = a;
        lo = b;
    }
    for (i = 0; i < D_800B4D20; i++) {
        if (lo < D_800B4D1C[i].f_0) {
            return 0;
        }
        if (D_800B4D1C[i].f_0 == lo) {
            if (hi < D_800B4D1C[i].f_2) {
                return 0;
            }
            if (D_800B4D1C[i].f_2 == hi) {
                *out = D_800B4D1C[i].f_8;
                return D_800B4D1C[i].f_4;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", Monkey_UpdateSpeed);

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8003C204);

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", jtbl_800A49B8);


typedef struct { u8 pad0[0x60]; SVECTOR f_60; u8 pad68[0x98]; s32 f_100; s32 f_104; s32 f_108; u8 pad10C[4]; s32 f_110; s32 f_114; s32 f_118; u8 pad11C[4]; s16 f_120; s16 f_122; } S_M_8003C568;
s32 VectorNormalSS_3C568(void *, void *) asm("VectorNormalSS");
/* func_8003C568: one step of a monkey turn (set up by func_8003C204): direction f_60 = the start
 * direction +0x100 blended toward the goal +0x110 by (f_122 - f_120) / f_122, normalised; f_120
 * counts the steps down. VectorNormalSS must be declared returning long (as in libgte). */
void func_8003C568(void) {
    S_M_8003C568 *m = (S_M_8003C568 *)g_CurMonkey;
    m->f_60.vx = m->f_100 + ((m->f_110 - m->f_100) * (m->f_122 - m->f_120)) / m->f_122;
    m->f_60.vy = m->f_104 + ((m->f_114 - m->f_104) * (m->f_122 - m->f_120)) / m->f_122;
    m->f_60.vz = m->f_108 + ((m->f_118 - m->f_108) * (m->f_122 - m->f_120)) / m->f_122;
    VectorNormalSS_3C568(&m->f_60, &m->f_60);
    ((S_M_8003C568 *)g_CurMonkey)->f_120--;
}

/* Moving state of g_CurMonkey (walk 3, run 8, 0x24, 0x1A, 0x35 ...). Every few frames it checks
 * whether it still sees its target (byte +0x249 counts the checks without sight). With the target
 * in range it re-plans its route (Monkey_ChooseRoute) and may switch action, or gives up (state 0)
 * when calm, far (>= 200) and nothing else applies. While the state timer runs it moves by its
 * velocity (+0x70/+0x72/+0x74) and turns by the matrix +0x9C for +0x94 frames; when it runs out it
 * re-plans if it sees the target, else picks an idle action once it has lost sight long enough. */
void Monkey_StateMove(void) {
    s32 st;
    s16 k;

    if (g_CurMonkey->f_78 == 3 || g_CurMonkey->f_78 == 8) {
        func_80038F00();
    }
    if (((g_CurMonkey->f_78 == 0x24 || g_CurMonkey->f_78 == 8) && g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0 == g_CurMonkey->f_5C - 10)
        || ((g_CurMonkey->f_78 == 0x1A || g_CurMonkey->f_78 == 0x35) && D_800AEB60 % 300 != 0)) {
        if ((s16)Monkey_CanSeeTarget(0)) {
            LOST = 0;
        } else {
            LOST++;
        }
    }
    if (Monkey_IsTargetInRange()) {
        if (Monkey_ChooseRoute(1, 1)) {
            st = g_CurMonkey->f_78;
            Monkey_PickNextAction();
            if (g_CurMonkey->f_78 != 9 && !func_80033BE0()) {
                func_8003C204();
            }
            if (g_CurMonkey->f_78 != st) {
                return;
            }
        } else {
            if (!func_800339EC() && g_CurMonkey->f_78 != 9 && !func_80033BE0() && g_CurMonkey->f_78 != 0x3D && g_CurMonkey->f_78 != 0x1A
                && g_CurMonkey->f_78 != 0x35 && !func_80033C00() && g_CurMonkey->f_20C >= 200) {
                Monkey_SetState(0);
                return;
            }
            Monkey_ChooseRoute(0, 0);
            Monkey_TrySpecialAction();
            if (g_CurMonkey->f_78 != 9 && !func_80033BE0()) {
                func_8003C204();
            }
        }
    }
    if (Monkey_CheckStateTimer()) {
        if (D_800AEB60 % 5 == 0 && Monkey_CanSeeTarget(1)) {
            Monkey_ChooseRoute(0, 0);
            goto check;
        }
        if ((g_CurMonkey->f_5C - g_CurMonkey->f_16C[Monkey_CurAnimIndex()].f_0) % 5 == 0 && ((g_CurMonkey->f_248 >> 23) & 1) && g_CurMonkey->f_78 == 8
            && (k = func_80037420()) != 100) {
            func_8003429C(k);
        }
        if (func_80033C00()) {
            if (g_CurMonkey->f_120 > 0) {
                func_8003C568();
            }
        } else if (g_CurMonkey->f_94 > 0 && g_MonkeyKinds[g_CurMonkey->f_7C].f_4 != 0) {
            ApplyMatrixSV(g_CurMonkey->f_9C, &g_CurMonkey->f_60, &g_CurMonkey->f_60);
            g_CurMonkey->f_94--;
        }
        if (g_CurMonkey->f_228 & 2) {
            g_CurMonkey->f_28 += g_CurMonkey->f_72;
        }
        g_CurMonkey->f_24 += g_CurMonkey->f_70;
        g_CurMonkey->f_2C += g_CurMonkey->f_74;
        return;
    }
    if (Monkey_CanSeeTarget(0)) {
        Monkey_ChooseRoute(0, 0);
        Monkey_PickNextAction();
    check:
        if (g_CurMonkey->f_78 != 9 && !func_80033BE0()) {
            func_8003C204();
        }
        return;
    }
    if ((!func_8003398C() && LOST >= func_80033000()) || (func_8003398C() && LOST != 0)) {
        LOST = 0;
        Monkey_PickIdleAction();
    } else {
        Monkey_PickNextAction();
    }
}

void func_8003CC3C(s32 lim) {
    Monkey *m = g_CurMonkey;
    s32 a;
    s32 b;
    s32 d;
    SVECTOR r;
    MAT_8003CC3C mt;
    m->f_248 |= 0x2000000;
    a = -Math_Atan2Pos(g_MonkeyTarget->f_2C - m->f_2C, g_MonkeyTarget->f_24 - m->f_24);
    b = -Math_Atan2Pos(g_CurMonkey->f_64, g_CurMonkey->f_60);
    d = b - a;
    if (ABS(d) < lim + 0x2D) {
        return;
    }
    if (d < 0) {
        r.vx = 0;
        r.vy = lim;
        r.vz = 0;
    } else {
        r.vx = 0;
        r.vy = -lim;
        r.vz = 0;
    }
    RotMatrixYXZ(&r, &mt);
    ApplyMatrixSV(&mt, (SVECTOR *)&g_CurMonkey->f_60, (SVECTOR *)&g_CurMonkey->f_60);
}

void func_8003CD24(s32 a) {
    switch (a) {
    case 0:
    case 5:
        func_80033E4C(a);
        break;
    case 1:
        func_80033DF0();
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8003CD84);

/* Monkey state handler (from the per-state dispatch in Monkey_Update) for unalerted movement.
 * Every third frame (staggered by kind f_7C) it looks for Spike; if seen it either reacts
 * (func_800356C0 -> Monkey_QueueSound) or, for states flagged 0x40 in D_800AE940, sets f_79 and
 * calls func_800357E0. If the target is in range (states 0x1A/0x35 first re-aim at their path
 * points f_F2/f_F4) it picks a new action. Otherwise, while the state timer runs, it turns the
 * velocity f_60 by the matrix at +0x9C for f_94 frames and moves the position by f_70..f_74. */
void Monkey_StateRoam(void) {
    VEC_80040CFC_8003D9D4 a;
    VEC_80040CFC_8003D9D4 b;
    s16 state;
    if ((D_800AEB60 + g_CurMonkey->f_7C) % 3 == 0 && Monkey_CanSeeTarget(1)) {
        if (func_8003398C() || !((D_800AE940[g_CurMonkey->f_78].f_4 >> 6) & 1)) {
            Monkey_QueueSound(func_800356C0(), 0);
            Monkey_PickNextAction();
        } else {
            g_CurMonkey->f_79 = 1;
            func_800357E0();
        }
        return;
    }
    if (Monkey_IsTargetInRange()) {
        state = g_CurMonkey->f_78;
        if (MD->f_94 > 0) {
            switch (state) {
            case 0x1A:
            case 0x35:
            Node_GetPosition(g_CurMonkey->f_F2, &a);
            Node_GetPosition(g_CurMonkey->f_F4, &b);
            MD->f_BC = a.vx - b.vx;
            MD->f_C4 = a.vz - b.vz;
            }
        }
        Monkey_ChooseRoute(1, 0);
        Monkey_PickIdleAction();
        if (g_CurMonkey->f_78 != 9) {
            func_8003C204();
        }
        if (g_CurMonkey->f_78 != state) {
            return;
        }
    }
    if (Monkey_CheckStateTimer()) {
        if (func_80033C00()) {
            if (MD->f_120 > 0) {
                func_8003C568();
            }
        } else if (MD->f_94 > 0) {
            ApplyMatrixSV(&MD->f_9C, (s32)&MD->f_60, &MD->f_60);
            MD->f_94--;
        }
        if (g_CurMonkey->f_228 & 2) {
            g_CurMonkey->f_28 += g_CurMonkey->f_72;
        }
        g_CurMonkey->f_24 += g_CurMonkey->f_70;
        g_CurMonkey->f_2C += g_CurMonkey->f_74;
    } else {
        Monkey_PickIdleAction();
    }
}

#undef CM
#undef KIND
#define CM ((M_3DC7C_8003DC7C *)g_CurMonkey)
#define NODE(i) ((Nd_3DC7C_8003DC7C *)D_800B4D00)[i]
#define STF(s) (((struct S_D_800AE940_8003DC7C *)&D_800AE940)[s].flags >> 3 & 1)
#define KIND ((K_3DC7C_8003DC7C *)g_MonkeyKinds + CM->f_7C)
void func_800355DC_t(u16) asm("func_800355DC");
/* Monkey_Update's handler for the states a monkey plays out in place (0, 1, 0xB, 0x16-0x18, 0x1B,
 * 0x1C, 0x21, 0x22, 0x26-0x2B, 0x37, 0x38, 0x42).
 * - On a node flagged 0x400 (states 0x29-0x2B move between two linked nodes): tracks whether it
 *   still sees its target (+0x79, +0x249 give-up counter), re-places itself on the link or swaps
 *   +0xF2/+0xF4 when func_80052C4C says so, and state 0x2A drops along an arc onto the floor
 *   (then 0x2B). On a node flagged 0x40 it snaps to its stage object.
 * - State 1 (idle) counts down +0x9A, then picks 0xD/0x10/0x13/0x3A, by the direction to Spike
 *   (+0x21C) when alerted (bit 19 of +0x248, or randomly when close), else at random.
 * - While the state's animation runs: kinds' attack windows (kind+0x1E: 8 x {on, ?, min, max}
 *   distance, indexed by the state) fire shots (func_80033DF0, func_80033E4C, func_800343B0,
 *   func_8003440C, Monkey_FireShot at given animation frames); +0x222 counts the attack down.
 * - When it ends: idle-type states pick a new idle action; others decide (distance, node flags,
 *   sight checks every 150 frames) between func_800378C0 and Monkey_PickNextAction.
 * Finally states 0x1C/0x21/0x38/0xB/0x37 call func_8003CC3C with a range. The do/while (0) around
 * one Monkey_RestartAnim() is needed to match. */
void Monkey_StateInPlace(void) {
    V4_3DC7C_8003DC7C b, a;
    u32 st;
    u32 ang;
    s32 h;
    s32 d;
    s32 t;
    u32 f;
    u32 f2;
    u32 st2;
    u32 st3;
    M_3DC7C_8003DC7C *mm;

    if (NODE(CM->f_F4).f_0 & 0x400) {
        if (CM->f_79 == 0) {
            if (Monkey_CanSeeTarget(1)) {
                Monkey_QueueSound(func_800356C0(), 0);
                CM->f_79 = 1;
                CM->f_248.b[1] = 0;
            }
        } else if (CM->f_248.b[1] >= func_80033000()) {
            CM->f_79 = 0;
            CM->f_248.b[1] = 0;
        } else if (D_800AEB60 % 300 == 0 && !Monkey_CanSeeTarget(1)) {
            CM->f_248.b[1]++;
        }
        if (STF(CM->state) && !Monkey_CheckStateTimer()) {
            if (CM->f_222 > 0) {
                Monkey_RestartAnim();
            } else {
                Monkey_SetState(0x29);
            }
        }
        if (CM->state == 0x29 || STF(CM->state)) {
            if (func_80052C4C((s16)NODE(CM->f_F2).f_10 / 100) == 1) {
                func_80036460();
                t = CM->f_F2;
                CM->f_F2 = CM->f_F4;
                CM->f_F4 = t;
                func_800355DC_t(t);
            } else {
                Node_GetPosition(CM->f_F4, &a);
                Node_GetPosition(CM->f_F2, &b);
                CM->goal.x = b.x;
                CM->goal.y = b.y;
                CM->goal.z = b.z;
                CM->f_60.vx = b.x - a.x;
                CM->f_60.vy = 0;
                CM->f_60.vz = b.z - a.z;
                VectorNormalSS(&CM->f_60, &CM->f_60);
                CM->x = a.x;
                CM->y = a.y + 0x32;
                CM->z = a.z;
                if (!(CM->f_228 & 2) && !(NODE(CM->f_F2).f_0 & 0x400)) {
                    CM->y = Floor_GetHeight(CM->y, CM->y - 0x32, CM->z);
                }
            }
            if (!Monkey_CheckStateTimer()) {
                if ((CM->f_248.w >> 23 & 1) && func_8003738C() != 100) {
                    return;
                }
                Monkey_RestartAnim();
            }
        } else if (CM->state == 0x2A) {
            CM->y = CM->f_E4 - CM->f_E3 * 100 + CM->f_E3 * 4 * CM->f_E3;
            CM->f_E3++;
            {
                M_3DC7C_8003DC7C *m = CM;
                h = (s16)Floor_GetHeight(m->x, m->y, m->z);
                if (h < m->y) {
                    Monkey_SetState(0x2B);
                    CM->f_60.vx = 0x1000;
                    CM->f_60.vy = 0;
                    CM->f_60.vz = 0;
                    CM->f_84 = 0;
                    CM->f_86 = 0;
                    CM->f_88 = 0;
                    CM->y = h;
                }
            }
            if (!Monkey_CheckStateTimer()) {
                Monkey_RestartAnim();
            }
        } else if (CM->state == 0x2B) {
            if (!Monkey_CheckStateTimer()) {
                goto restart_ret;
            }
        }
        if (!STF(CM->state)) {
            return;
        }
    } else if (NODE(CM->f_F2).f_0 & 0x40) {
        d = NODE(CM->f_F2).f_10;
        CM->x = (*(struct Game_3DC7C *)&g_Game).f_820C[d].x;
        CM->y = (*(struct Game_3DC7C *)&g_Game).f_820C[d].y;
        CM->z = (*(struct Game_3DC7C *)&g_Game).f_820C[d].z;
        CM->y = Floor_GetHeight(CM->x, CM->y - 0x40, CM->z);
    }

    if (CM->state == 1 && CM->f_9A-- <= 0) {
        if ((CM->f_248.w >> 19 & 1) ||
            (CM->f_20C < 2000 && 2000 - CM->f_20C > (u16)Monkey_Rand() % 2000 && (u16)Monkey_Rand() % 10 < 3)) {
            ang = CM->f_21C;
            if (CM->f_248.w >> 19 & 1) {
                Monkey_QueueSound(func_80035750(), 0);
            }
            if (ang - 0x156 < 0x555) {
                CM->state = 0xD;
            } else if (ang - 0x556 < 0x555) {
                CM->state = 0x13;
            } else if (ang - 0x956 < 0x555) {
                CM->state = 0x10;
            } else if (ang < 0x2E4 || ang - 0xD1D < 0x2E4) {
                CM->state = 0x3A;
            }
        } else {
            switch ((s32)(Monkey_Rand() & 3)) {
            case 0:
                CM->state = 0xD;
                break;
            case 1:
                CM->state = 0x10;
                break;
            case 2:
                CM->state = 0x13;
                break;
            case 3:
                CM->state = 0x3A;
                break;
            }
        }
        Monkey_RestartAnim();
        return;
    }

    if (Monkey_CheckStateTimer()) {
        if (func_800339EC() && CM->state == 0xB && (*(struct Game_3DC7C *)&g_Game).f_812C == 3) {
            Monkey_PickNextAction();
            D_800AEB5C = 0;
        }
        st = CM->state;
        if (st == 1 && (D_800AEB60 + CM->f_7C) % 3 == 0 && Monkey_CanSeeTarget(1)) {
            if (func_8003398C() || !(((struct S_D_800AE940_8003DC7C *)&D_800AE940)[CM->state].flags >> 6 & 1)) {
                Monkey_QueueSound(func_800356C0(), 0);
                Monkey_PickNextAction();
                return;
            }
            CM->f_79 = 1;
            func_800357E0();
            return;
        }
        f2 = NODE(CM->f_F4).f_0;
        if (f2 & 0x10000) {
            if (func_80052C4C(NODE(CM->f_F4).f_10) == 2 || func_80052C4C(NODE(CM->f_F4).f_10) == 1) {
                goto pick;
            }
            if ((NODE(CM->f_F4).f_0 & 0x10000) && (u16)Monkey_Rand() % 20 == 0) {
                Object_SetFlagCF(NODE(CM->f_F4).f_10, 3);
            }
        } else {
            if (!(f2 & 0x400)) {
                if (!STF(CM->state)) {
                    goto tail;
                }
                if (CM->f_222 <= 0) {
                pick:
                    Monkey_PickNextAction();
                    goto tail;
                }
            }
            if (STF(CM->state) && CM->f_222 > 0) {
                if (CM->state == 0x22 && KIND->atk[1].on && CM->f_20C >= KIND->atk[1].min && CM->f_20C <= KIND->atk[1].max) {
                    if (D_800AEB60 % 5 == 0) {
                        func_80033DF0();
                    }
                } else if (CM->state == 0x21 && KIND->atk[0].on && CM->f_20C >= KIND->atk[0].min && CM->f_20C <= KIND->atk[0].max) {
                    func_80033E4C(0);
                } else if (CM->state == 0x38 && KIND->atk[5].on && CM->f_20C >= KIND->atk[5].min && CM->f_20C <= KIND->atk[5].max) {
                    func_80033E4C(5);
                } else if (CM->state == 0x1C && KIND->atk[4].on && CM->f_20C >= KIND->atk[4].min && CM->f_20C <= KIND->atk[4].max) {
                    if (CM->f_16C[Monkey_CurAnimIndex()].f_0 == CM->f_5C - 10) {
                        func_800343B0();
                    }
                } else if (CM->state == 0x1B && KIND->atk[3].on && CM->f_20C >= KIND->atk[3].min && CM->f_20C <= KIND->atk[3].max) {
                    if (CM->f_16C[Monkey_CurAnimIndex()].f_0 == CM->f_5C - 25) {
                        func_8003440C();
                    }
                } else if (CM->state == 0x37 && KIND->atk[7].on && CM->f_20C >= KIND->atk[7].min && CM->f_20C <= KIND->atk[7].max) {
                    if ((CM->f_5C - CM->f_16C[Monkey_CurAnimIndex()].f_0) % 10 == 3 ||
                        (CM->f_5C - CM->f_16C[Monkey_CurAnimIndex()].f_0) % 10 == 7) {
                        Monkey_FireShot(3);
                        Monkey_QueueSound(0x48, 0);
                    }
                } else {
                    CM->f_222--;
                }
            }
        }
        goto tail;
    }

    if (func_800339EC() && (*(struct Game_3DC7C *)&g_Game).f_812C != 3) {
        Monkey_RestartAnim();
    } else if (CM->state == 0x37) {
        M_3DC7C_8003DC7C *m = CM;
        m->f_222--;
        m->f_96++;
        if (CM->f_222 <= 0) {
            Monkey_FireShot(4);
        }
    } else if (!(NODE(CM->f_F4).f_0 & 0x400) && STF(CM->state) && CM->f_222 <= 0) {
        Monkey_PickNextAction();
    } else if (!(NODE(CM->f_F4).f_0 & 0x400) && STF(CM->state) && CM->f_222 > 0) {
        Monkey_RestartAnim();
    } else {
        mm = CM;
        if ((f = NODE(mm->f_F4).f_0) & 0x10000) {
            if (func_80052C4C(NODE(mm->f_F4).f_10) == 2) {
                Monkey_PickNextAction();
            }
        } else {
            st2 = CM->state;
            if (st2 - 0x27 < 2 || (st2 & 0xFF) == 0x17 || (st2 & 0xFF) == 0x18 || (st2 & 0xFF) == 0x29) {
                Monkey_PickIdleAction();
                return;
            }
            if (NODE(CM->f_F2).f_0 & 0x40) {
            restart_ret:
                Monkey_RestartAnim();
                return;
            }
            if ((st2 & 0xFF) == 1) {
                do {
                    Monkey_RestartAnim();
                    return;
                } while (0);
            }
            if (STF(mm->state) ||
                (mm->state == 0x1C && mm->f_222 <= 0) ||
                (mm->state == 0x37 && mm->f_222 <= 0) ||
                (mm->state == 0x21 && mm->f_222 <= 0) ||
                (mm->state == 0x38 && mm->f_222 <= 0) ||
                (mm->state == 0x1B && mm->f_222 <= 0) ||
                ((f & 4) && mm->f_22C == 0) ||
                ((NODE(CM->f_F4).f_0 & 8) && !func_800339EC() && CM->f_20C < NODE(CM->f_F4).f_10) ||
                ((NODE(CM->f_F4).f_0 & 0x8000) && CM->f_20C >= 0x5DD) ||
                ((NODE(CM->f_F4).f_0 & 0x10000) && func_80052C4C(NODE(CM->f_F4).f_10) == 2) ||
                (CM->f_79 == 1 && !STF(CM->state) && !func_800349F4(CM->f_F4)) ||
                (CM->state != 0x37 && !(NODE(CM->f_F4).f_0 & 0x10000) && !func_800349F4(CM->f_F4) &&
                 (D_800AEB60 + CM->f_7C + 3) % 150 == 0 && !Monkey_CanSeeTarget(1)) ||
                (CM->state != 0x37 && !func_800349F4(CM->f_F4) && CM->f_20C < 200)) {
                if (CM->state == 0xB && CM->f_20C - 300 >= 0x4B1U) {
                    Monkey_PickNextAction();
                } else {
                    func_800378C0();
                }
            }
        }
    }
    Monkey_RestartAnim();
tail:
    st3 = CM->state;
    if (st3 == 0x1C || st3 == 0x21 || st3 == 0x38) {
        func_8003CC3C(0xAA);
    } else if (st3 == 0xB && !func_800339EC()) {
        func_8003CC3C(0x11C);
    } else if (CM->state == 0x37) {
        func_8003CC3C(0x1FE);
    }
}
#undef CM
#undef NODE
#undef STF
#undef KIND
#define CM ((M_39ED4_80039ED4 *)g_CurMonkey)
#define KIND(m) ((K_39ED4_80039ED4 *)&g_MonkeyKinds[(m)->f_7C])

void func_8003F18C(void) {
    if (Monkey_CheckStateTimer() != 0) {
        if ((D_800AEB60 + g_CurMonkey->f_7C) % 3 == 0 && Monkey_CanSeeTarget(1) != 0) {
            if (func_8003398C() != 0 || !((((struct S_D_800AE940_8003F18C *)&D_800AE940)[g_CurMonkey->f_78].f_4 >> 6) & 1)) {
                Monkey_QueueSound(func_800356C0(), 0);
                Monkey_PickNextAction();
            } else {
                g_CurMonkey->f_79 = 1;
                func_800357E0();
            }
        }
        return;
    }
    ((S_M98_8003F18C_8003F18C *)g_CurMonkey)->f_98 = (u16)Monkey_Rand() % 20 + 10;
    switch (g_CurMonkey->f_78) {
    case 0x10:
        g_CurMonkey->f_78 = 0x11;
        break;
    case 0x13:
        g_CurMonkey->f_78 = 0x14;
        break;
    case 0xD:
        g_CurMonkey->f_78 = 0xE;
        break;
    case 0x3A:
        g_CurMonkey->f_78 = 0x3B;
        break;
    }
}

void func_8003F308(void) {
    Monkey *m = g_CurMonkey;
    s32 t;
    s32 k;
    ((S_M98_8003F308_8003F308 *)m)->f_98--;
    t = (u16)((S_M98_8003F308_8003F308 *)m)->f_98;
    if ((t & 7) == 0) {
        switch (m->f_78) {
        case 0xE:
            k = 2;
            break;
        case 0x11:
            k = 4;
            break;
        case 0x14:
            k = 3;
            break;
        case 0x3B:
            k = 1;
            break;
        default:
            k = 0;
            break;
        }
        if (Monkey_CanSeeTarget(k) != 0) {
            g_CurMonkey->f_79 = 1;
            if (func_8003398C() != 0) {
                Monkey_QueueSound(func_800356C0(), 0);
                Monkey_PickNextAction();
            } else {
                g_CurMonkey->f_79 = 1;
                func_800357E0();
            }
        }
        return;
    }
    if ((s16)t < 0) {
        switch (m->f_78) {
        case 0xE:
            m->f_78 = 0xF;
            break;
        case 0x11:
            m->f_78 = 0x12;
            break;
        case 0x14:
            m->f_78 = 0x15;
            break;
        default:
            g_CurMonkey->f_78 = 0x3C;
            break;
        }
    } else if (Monkey_CheckStateTimer() != 0) {
        Monkey_TrySpecialAction();
        return;
    }
    Monkey_RestartAnim();
}

void func_8003F4B4(void) {
    if (Monkey_CheckStateTimer() == 0) {
        if (!(((Monkey_Rand() & 0xFFFF) % 6) & 0xFFFF)) {
            func_80036300();
            return;
        }
        Monkey_PickIdleAction();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8003F530);

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8003F86C);

s32 func_8003FB44(void) {
    if (Monkey_IsTargetInRange() != 0) {
        Monkey_ChooseRoute(1, 1);
        func_800378C0();
    } else {
        if (g_CurMonkey->f_228 & 2) {
            g_CurMonkey->f_28 += g_CurMonkey->f_72;
        }
        g_CurMonkey->f_24 += g_CurMonkey->f_70;
        g_CurMonkey->f_2C += g_CurMonkey->f_74;
    }
    if (g_CurMonkey->f_96 < 30) {
        g_CurMonkey->f_96++;
    }
}

void func_8003FC08(void) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(g_CurMonkey, u16 *, 0x96) + 1;
    M2C_FIELD(g_CurMonkey, u16 *, 0x96) = temp_v0;
    if ((s16) temp_v0 < (s32) M2C_FIELD(g_CurMonkey, u16 *, 0x128)) {
        if (M2C_FIELD(g_CurMonkey, s32 *, 0x228) & 2) {
            M2C_FIELD(g_CurMonkey, s32 *, 0x28) = (s32) (M2C_FIELD(g_CurMonkey, s32 *, 0x28) + M2C_FIELD(g_CurMonkey, s16 *, 0x72));
        }
        M2C_FIELD(g_CurMonkey, s32 *, 0x24) = (s32) (M2C_FIELD(g_CurMonkey, s32 *, 0x24) + M2C_FIELD(g_CurMonkey, s16 *, 0x70));
        M2C_FIELD(g_CurMonkey, s32 *, 0x2C) = (s32) (M2C_FIELD(g_CurMonkey, s32 *, 0x2C) + M2C_FIELD(g_CurMonkey, s16 *, 0x74));
        return;
    }
    func_80036174();
}

void func_8003FCA8(void) {
    if (Monkey_CheckStateTimer() == 0) {
        func_800378C0();
    }
}

/* Falling/jump arc for the current monkey: height f_28 = f_E4 + 6 * t * t with t = f_92
 * (counting up each call). When that goes below the ground under it, lands (func_80035DD8)
 * and snaps to the ground height. */
void Monkey_UpdateFall(void) {
    Monkey *m = g_CurMonkey;
    s32 y;
    m->f_28 = m->f_E4 + (m->f_92 * 6) * m->f_92;
    y = Floor_GetHeight(m->f_24, m->f_28 + 0x32, m->f_2C);
    if (y < m->f_28) {
        func_80035DD8();
        g_CurMonkey->f_28 = y;
    }
    g_CurMonkey->f_92++;
}

void Monkey_UpdateJump(void) {
    MJ_8003FD7C_8003FD7C *m;
    MJ_8003FD7C_8003FD7C *m2;
    s32 t;
    u16 tt = MJ_3FD7C->t;
    s32 ny;
    s32 h;
    s32 r;
    s32 y;
    u16 f;
    if (MJ_3FD7C->t < MJ_3FD7C->dur) {
        if (MJ_3FD7C->state != 0x1D) {
            if (MJ_3FD7C->t < (MJ_3FD7C->dur >> 1)) {
                f = MJ_3FD7C->frame;
                if (f < MJ_3FD7C->anims[Monkey_CurAnimIndex()].start + MJ_3FD7C->f_172) {
                    MJ_3FD7C->frame++;
                }
            } else if (MJ_3FD7C->t >= MJ_3FD7C->dur - (MJ_3FD7C->f_170 >> 1) && Monkey_CheckStateTimer() != 0) {
                MJ_3FD7C->frame++;
            }
            m2 = MJ_3FD7C;
            if (m2->frame < MJ_3FD7C->anims[Monkey_CurAnimIndex()].end) {
                f = MJ_3FD7C->frame;
            } else {
                f = MJ_3FD7C->anims[Monkey_CurAnimIndex()].end;
            }
            m2->frame = f;
            m = MJ_3FD7C;
            y = Floor_GetHeight(m->x, m->y, m->z);
            t = (s16)tt;
            ny = t * 400;
            h = MJ_3FD7C->y0 - MJ_3FD7C->vy * t + t * ny / 100; if (y < h) { r = Floor_GetHeight(MJ_3FD7C->x, MJ_3FD7C->y, MJ_3FD7C->z); } else { r = h; } m->y = r;
        }
        MJ_3FD7C->t++;
        return;
    }
    if (((s32 (*)(s32, s32))Monkey_ChooseRoute)(1, 0) != 0) {
        func_800378C0();
        return;
    }
    if (func_800339EC() != 0) {
        return;
    }
    if (MJ_3FD7C->state == 9 || MJ_3FD7C->state == 0x3D || MJ_3FD7C->state == 0x1A || MJ_3FD7C->state == 0x35) {
        return;
    }
    if (func_80033C00() == 0) {
        Monkey_SetState(0);
    }
}

void func_8004002C(void) {
    VEC_80040CFC_8004002C t;
    u16 i;
    u16 best = 60000;
    u16 d;
    s16 bi;
    s16 v;
    if (Monkey_CheckStateTimer() != 0) {
        return;
    }
    for (i = 0; i < D_800B4D18; i++) {
        if (D_800B4D00[i].f_0 & 0x2000) {
            Node_GetPosition(i, &t);
            d = Vec_Dist((VEC_80034684_8004002C *)&g_CurMonkey->f_24, (VEC_80034684_8004002C *)&t);
            if (best > d) {
                bi = i;
                best = d;
            }
        }
    }
    Monkey_GoToNode(bi);
    v = Node_GetLink(bi, 0);
    g_CurMonkey->f_F4 = v;
    Monkey_StartLink(v, g_CurMonkey->f_F2);
    if (Monkey_NodeEvents(bi) == 0) {
        Monkey_PickNextAction();
    }
}

void func_80040170(void)
{
  s16 new_var;
  void *temp_a0;
  if (Monkey_AnimJustStarted() != 0)
  {
    temp_a0 = (s8 *) g_CurMonkey + 0x60;
    new_var = (s16) ((*((u16 *) (((s8 *) g_MonkeyTarget) + 0x24))) - (*((u16 *) (((s8 *) g_CurMonkey) + 0x24))));
    *((s16 *) (((s8 *) g_CurMonkey) + 0x62)) = 0;
    *((s16 *) (((s8 *) g_CurMonkey) + 0x60)) = new_var;
    *((s16 *) (((s8 *) g_CurMonkey) + 0x64)) = (s16) ((*((u16 *) (((s8 *) g_MonkeyTarget) + 0x2C))) - (*((u16 *) (((s8 *) g_CurMonkey) + 0x2C))));
    VectorNormalSS(temp_a0, temp_a0);
  }
  if (Monkey_CheckStateTimer() == 0)
  {
    Monkey_ChooseRoute(0, 0);
    Monkey_PickNextAction();
  }
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_800401F4);

s32 Monkey_CanSeeTarget(u32 dir)
{
  s32 mode;
  s32 arg;
  s32 ok;
  u32 a;
  s32 r;
  if (func_800339EC() != 0)
  {
    ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = 1;
    return 1;
  }
  mode = 1;
  if (!g_MonkeyTargetIsRC)
  {
    mode = ((struct Tgt_800405C4 *) g_MonkeyTarget)->f_70 & 0xF;
  }
  if ((((MV_800405C4_800405C4 *) g_CurMonkey)->dist < (&((Kind_800405C4_800405C4 *) g_MonkeyKinds)[((MV_800405C4_800405C4 *) g_CurMonkey)->kind])->range[mode]) || (((MV_800405C4_800405C4 *) g_CurMonkey)->dist < (&((Kind_800405C4_800405C4 *) g_MonkeyKinds)[((MV_800405C4_800405C4 *) g_CurMonkey)->kind])->f_1A))
  {
    if ((((MV_800405C4_800405C4 *) g_CurMonkey)->state == 3) || (((MV_800405C4_800405C4 *) g_CurMonkey)->state == 8))
    {
      ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.near = 1;
      ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = 1;
      return 1;
    }
    if (mode == 7)
    {
      ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = 1;
      return 1;
    }
    a = ((MV_800405C4_800405C4 *) g_CurMonkey)->angle;
    arg = 0;
    switch (dir)
    {
      default:

      case 0:
        arg = 1;
        ok = 1;
        break;

      case 1:
        arg = 1;
        ok = (a < 0x239) || ((a - 0xDC8) < 0x239);
        break;

      case 2:
        ok = (a - 0x1C8) < 0x471;
        break;

      case 3:
        ok = (a - 0x5C8) < 0x471;
        break;

      case 4:
        ok = (a - 0x9C8) < 0x471;
        break;

    }

    if (ok)
    {
      r = func_800401F4(arg) & 1;
      ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.near = r;
      ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = r;
      return r;
    }
    ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.near = 0;
    ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = 0;
    return 0;
  }
  ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.near = 0;
  ((MV_800405C4_800405C4 *) g_CurMonkey)->bits.seen = 0;
  return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", jtbl_800A4A98_pad);


void func_800407F0(void) {
    s32 i;
    Monkey *m;
    for (i = 0; i < D_800B4D18; i++) {
        D_800B4D00[i].f_14[g_CurMonkey->f_7B] = 0;
    }
    m = g_CurMonkey;
    m->f_EA = 0;
    m->f_E6 = -1;
    m->f_248 &= ~0x08000000;
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", func_8004086C);

s32 func_80040BDC(VEC_80040CFC_80040BDC *a, VEC_80040CFC_80040BDC *b) {
    s32 ax = a->vx;
    s32 bx = b->vx;
    s32 az = a->vz;
    s32 bz = b->vz;
    s32 ay = a->vy;
    s32 by = b->vy;
    s32 dx = ax - bx;
    s32 dz = az - bz;
    s32 adx, adz;
    Monkey *m;

    if ((dx == 0 && dz == 0) || (m = g_CurMonkey)->f_78 == 9) {
        return g_CurMonkey->f_28;
    }
    adx = (dx >= 0) ? dx : -dx;
    adz = (dz >= 0) ? dz : -dz;
    if (adx < adz) {
        return by + (ay - by) * (m->f_2C - bz) / dz;
    }
    return by + (ay - by) * (m->f_24 - bx) / dx;
}

void func_80040CFC(s16 flag) {
    VEC_80040CFC a;
    VEC_80040CFC b;
    Node_GetPosition(g_CurMonkey->f_F2, &a);
    if (flag) {
        Monkey *m = g_CurMonkey;
        b.vx = m->f_12C;
        b.vy = m->f_130;
        b.vz = m->f_134;
    } else {
        Node_GetPosition(g_CurMonkey->f_F4, &b);
    }
    func_80040BDC(&a, &b);
}

INCLUDE_ASM("asm/nonmatchings/game/80032E30_monkey", Monkey_NodeEvents);

s32 func_80041280(void) {
    return M2C_FIELD(Collision_GetShape(M2C_FIELD(g_CurMonkey, s32 *, 0x50) & 0xFFF), u16 *, 0x24) & 0xF0;
}

typedef struct { s32 x, y, z, pad; } V4_412B0;
typedef struct { s16 vx, vy, vz, pad; } SV_412B0;
typedef struct { u8 b[8]; } B8_412B0;
typedef struct {
    u8 pad0[0x18]; s32 f_18; u8 pad1C[8]; s32 x, y, z; s32 f_30; u8 pad34[4]; s32 f_38; B8_412B0 f_3C;
    u8 pad44[2]; s16 f_46; u8 pad48[0x16]; u16 f_5E; B8_412B0 f_60; u8 pad68[8]; s16 vx, vy, vz; u8 pad76[2];
    u8 state; u8 f_79; u8 f_7A; u8 f_7B; u8 f_7C; u8 pad7D[7]; SV_412B0 f_84; u8 pad8C[2]; s16 f_8E; u16 f_90;
    s16 f_92; s16 f_94; u8 pad96[0x26]; V4_412B0 goal; u8 padCC[0x16]; u8 f_E2; u8 padE3[0xD]; s16 f_F0;
    u16 f_F2; u16 f_F4; u8 padF6[0x2E]; s16 f_124; u16 f_126; u8 pad128[0x3E]; s16 f_166; u8 pad168[4];
    void *f_16C; u8 pad170[4]; u16 f_174; u8 pad176[0x96]; s32 f_20C; u8 pad210[0x18]; u32 f_228; u16 f_22C;
    u8 pad22E[2]; s32 f_230; u8 pad234[0xE]; s16 f_242; s16 f_244; s16 f_246; u32 f_248; u32 f_24C;
} M_412B0;
typedef struct { u32 f_0; u32 flags; } St_412B0;
typedef struct { u8 pad0[0x1A]; s16 f_1A; } K_412B0;
typedef struct { u32 f_0; u8 pad4[0xC]; s16 f_10; u8 pad12[6]; } Nd_412B0;
typedef struct { u8 pad0[0x18]; s32 f_18; s32 f_1C; } Set_412B0;
struct Game_412B0 { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0x8C]; s32 f_81B4; s32 f_81B8; u8 pad81BC[0x84]; s32 f_8240; };

extern struct Game_412B0 g_Game412B0 asm("g_Game");
extern St_412B0 D_800AE940_U[] asm("D_800AE940");
extern Set_412B0 *D_800B4D14_U asm("D_800B4D14");
s32 func_80040CFC_r(s32) asm("func_80040CFC");
s16 func_80041280_s(void) asm("func_80041280");
void func_80035BD0_i(s32) asm("func_80035BD0");
u16 Monkey_CurAnimIndex_u(void) asm("Monkey_CurAnimIndex");
void func_8003F530(void);
void func_8003F86C(void);
void func_8003CD84(void);
void RotMatrix(SV_412B0 *, void *);
#undef CM
#undef NODE
#undef STF
#define CM ((M_412B0 *)g_CurMonkey)
#define NODE(i) ((Nd_412B0 *)D_800B4D00)[i]
#define STF(s) (D_800AE940_U[s].flags)
/* Per-frame update of the current monkey: timers, turning towards its goal, animation stepping,
 * the state machine (Monkey_StateMove/Roam/InPlace and the other state handlers), speed, falling,
 * floor height and collision, node events and the helmet light. */
void Monkey_Update(void) {
    s32 phase;
    V4_412B0 pos;
    u8 mat[0x20];
    SV_412B0 v;
    SV_412B0 tmp;
    s32 vulnerable;
    s32 k;
    s32 t;
    s32 c;
    s32 q;
    if (CM->f_174 != 0) {
        CM->f_174--;
    }
    vulnerable = D_800AE940_U[CM->state].flags >> 5;
    vulnerable &= 1;
    CM->f_248 &= 0xFFEFFFFF;
    if ((CM->f_7A == 0) || (CM->f_7A == 2)) {
        return;
    }
    if ((((((((CM->state != 2) && (!func_80033B10())) && (CM->state != 3)) && (CM->state != 8)) && (CM->state != 0xA)) && (!func_80033C00())) && (CM->state != 0x1A)) && (CM->state != 0x35)) {
        CM->f_94 = 0;
    }
    if (func_80033C00()) {
        Monkey_AimAtGoal();
    } else if (((((CM->f_94 <= 0) && (CM->state != 0)) && (CM->state != 0x42)) && (!((CM->f_248 >> 25) & 1))) && (CM->state != 7)) {
        Monkey_TurnToGoal();
    }
    CM->f_248 &= 0xFDFFFFFF;
    if (CM->f_7A == 3) {
        CM->f_90--;
    } else {
        if ((D_800AE940_U[CM->state].flags >> 2) & 1) {
            Monkey_StepAnimFrame();
        }
        switch (CM->state) {
        case 0x2:
        case 0x3:
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xC:
        case 0x19:
        case 0x1A:
        case 0x23:
        case 0x24:
        case 0x35:
        case 0x39:
            if (CM->f_79 == 1) {
                Monkey_StateMove();
            } else {
                Monkey_StateRoam();
            }
            break;
        case 0x0:
        case 0x1:
        case 0xB:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x1B:
        case 0x1C:
        case 0x21:
        case 0x22:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x37:
        case 0x38:
        case 0x42:
            Monkey_StateInPlace();
            break;
        case 0xD:
        case 0x10:
        case 0x13:
        case 0x3A:
            func_8003F18C();
            break;
        case 0xE:
        case 0x11:
        case 0x14:
        case 0x3B:
            func_8003F308();
            break;
        case 0xF:
        case 0x12:
        case 0x15:
        case 0x3C:
            func_8003F4B4();
            break;
        case 0x4:
        case 0x1D:
            func_8003F530();
            break;
        case 0x2C:
        case 0x2D:
        case 0x2E:
            func_8003F86C();
            break;
        case 0x31:
            Monkey_UpdateJump();
            break;
        case 0x1E:
        case 0x20:
            func_8003CD84();
            break;
        case 0x36:
            if (!Monkey_CheckStateTimer()) {
                Monkey_PickIdleAction();
            }
            break;
        case 0x7:
            func_80040170();
            break;
        case 0x32:
            if (!Monkey_CheckStateTimer()) {
                CM->state = 0x33;
                CM->f_242++;
            restart:
                Monkey_RestartAnim();
            }
            break;
        case 0x33:
            if ((CM->f_242 == 7) && (!(((u16) Monkey_Rand()) % 10))) {
                memset(&tmp, 0, 8);
                tmp.vx = CM->x;
                tmp.vy = CM->y - 0x20;
                tmp.vz = CM->z;
                v = tmp;
                Effect_SpawnAt(0x110, &v);
            }
            if (CM->f_20C < (((K_412B0 *) (&g_MonkeyKinds[CM->f_7C]))->f_1A * 3)) {
                func_800359B4();
                break;
            }
            if (Monkey_CheckStateTimer()) {
                break;
            }
            ((u8 *) (&CM->f_248))[0]++;
            if ((((u8 *) (&CM->f_248))[0] < CM->f_246) || (CM->f_244 >= CM->f_246)) {
                goto restart;
            }
            func_800359B4();
            break;
        case 0x34:
            if (!Monkey_CheckStateTimer()) {
                func_800378C0();
                Monkey_TurnToGoal();
            }
            break;
        case 0x3D:
            func_8003FB44();
            break;
        case 0x3E:
            func_8003FC08();
            break;
        case 0x3F:
            if (Monkey_CheckStateTimer()) {
                break;
            }
            goto pick;
        case 0x5:
        case 0x41:
            if (Monkey_CheckStateTimer()) {
                CM->f_92++;
                CM->vx = (CM->vx * CM->f_166) / 32768;
                CM->vy = (CM->vy * CM->f_166) / 32768;
                CM->vz = (CM->vz * CM->f_166) / 32768;
                q = (0x190 - (CM->f_92 * CM->f_92)) / 250;
                c = 0;
                if (q >= 0) {
                    c = q;
                }
                CM->f_30 = (-CM->vx) * ((s16) c);
                CM->f_38 = (-CM->vz) * ((s16) c);
            } else {
                k = CM->state;
                if (k == 5) {
                    CM->f_92 = k;
                } else {
                    CM->f_92 = 0x28;
                }
                Monkey_SetState(0x25);
            }
            break;
        case 0x25:
            if (((s16) (CM->f_92--)) <= 0) {
                if (!(CM->f_228 & 0x8000)) {
                    Node_GetPosition(CM->f_F2, &pos);
                    CM->state = 6;
                    CM->goal = pos;
                    goto restart;
                }
                goto run;
            }
            break;
        case 0x40:
            if (Monkey_CheckStateTimer()) {
                break;
            }
            if (CM->f_228 & 0x8000) {
            run:
                func_80035D18();
                break;
            }
            if (CM->f_79 == 0) {
                goto idle;
            }
            goto pick;
        case 0x2F:
            Monkey_UpdateFall();
            break;
        case 0x30:
            func_8004002C();
            break;
        case 0x6:
            if (Monkey_CheckStateTimer()) {
                break;
            }
            if (CM->f_79 != 0) {
                goto pick;
            }
        idle:
            func_800363A4();
            break;
        pick:
            func_800378C0();
            break;
        }
    }
    if (((u32) (CM->state - 0x32)) < 3) {
        CM->f_18 = g_Game412B0.f_81B8;
        CM->f_16C = (void *) (g_Game412B0.f_8240 + D_800B4D14_U->f_1C);
    } else if (CM->f_18 != g_Game412B0.f_81B4) {
        CM->f_18 = g_Game412B0.f_81B4;
        CM->f_16C = (void *) (g_Game412B0.f_8240 + D_800B4D14_U->f_18);
        Monkey_RestartAnim();
    }
    if ((CM->f_79 == 1) && (g_MonkeyKinds[CM->f_7C].f_4 == 0)) {
        func_8003CC3C(0x22);
    }
    if (((CM->f_228 & 0x4000) || (((Nd_412B0 *)D_800B4D00)[CM->f_F4].f_0 & 0x10)) || (CM->state == 0x1D)) {
        if (!((CM->f_248 >> 30) & 1)) {
            func_80036B24();
        }
    } else if ((CM->f_248 >> 30) & 1) {
        func_80036B78();
    }
    if (CM->f_124 > 0) {
        CM->f_124--;
    }
    if (!Monkey_CheckStateTimer()) {
        Monkey_RestartAnim();
    }
    if ((!func_80033C34()) && (!(((Nd_412B0 *)D_800B4D00)[CM->f_F4].f_0 & 0x400))) {
        u32 fl = ((Nd_412B0 *)D_800B4D00)[CM->f_F2].f_0;
        s32 st;
        if ((((!(fl & 0x40)) && (((u8) (st = CM->state)) != 0x1E)) && (((u8) st) != 0x20)) && (((u32) (st - 0x2F)) >= 2)) {
            if (CM->f_228 & 2) {
                if (func_800339EC() && (CM->state == 0x1A)) {
                    CM->y = func_80040CFC_r(1);
                } else if ((CM->f_228 & 0x20020) && func_80033C80()) {
                    CM->y = func_80040CFC_r(0) + 0x100;
                } else {
                    CM->y = func_80040CFC_r(0);
                }
            } else if (!(fl & 0x400)) {
                CM->y = Floor_GetHeight(CM->x, CM->y, CM->z);
            }
        }
    }
    if (func_80033C00() && ((phase = (s32) (D_800AEB60 % 50)) < 10)) {
        func_80039200();
    }
    Monkey_UpdateSpeed();
    if (CM->f_22C != 0) {
        CM->f_22C--;
    }
    if ((((!vulnerable) && ((D_800AE940_U[CM->state].flags >> 5) & 1)) && (!((CM->f_24C >> 1) & 1))) && (!((CM->f_248 >> 30) & 1))) {
        Monkey_EnableCollision();
    } else if (vulnerable && (!((D_800AE940_U[CM->state].flags >> 5) & 1))) {
        Monkey_DisableCollision();
    }
    if (CM->f_E2 != 0) {
        CM->f_E2--;
    }
    if (((((CM->f_7A == 4) && (!func_800339EC())) && (!((CM->f_248 >> 30) & 1))) && func_800392F0()) && (CM->state != 0x20)) {
        if ((CM->state == 0x1E) && (CM->f_230 > 0xF0)) {
            if (CM->f_126 == 0xB) {
                func_80035EA4();
                CM->f_8E -= 0xC8;
            }
        } else if ((CM->f_126 == 8) && Game_NotExiting()) {
            CM->f_7A = 3;
            Monkey_DisableCollision();
            D_800AEB5A = CM->f_7C;
        } else if (((CM->f_126 == 0xB) && (CM->f_E2 == 0)) && (!(CM->f_228 & 0x80000))) {
            if (!(CM->f_228 & 0x8000)) {
                if (((Nd_412B0 *)D_800B4D00)[CM->f_F2].f_0 & 0x400) {
                    goto done_hit;
                }
                if (((CM->state == 0x1A) || (CM->state == 0x35)) || (CM->state == 9)) {
                    goto done_hit;
                }
                if (func_80033C00()) {
                    goto done_hit;
                }
            }
            t = D_800AE940_U[CM->state].flags & 3;
            if (t == 1) {
                Monkey_SetState(0x40);
            } else if (t >= 2) {
                switch (func_80041280_s()) {
                default:
                case 0x10:
                    k = 0x40;
                    CM->f_8E -= 0x12C;
                    break;
                case 0x20:
                    k = 5;
                    CM->f_8E -= 0x190;
                    break;
                case 0x30:
                    k = 0x41;
                    CM->f_8E -= 0x1F4;
                    break;
                }
                func_80035BD0_i(k);
            }
        }
    }
done_hit:
    if ((g_Game412B0.f_8126 == 0x46) && (CM->f_8E < 0)) {
        Link_SendEvent(0xA, 0, 0);
        CM->f_7A = 2;
        Monkey_SelectActive();
        return;
    }
    if (CM->f_90 == 0) {
        CM->f_7A = 2;
        Monkey_SelectActive();
    }
    if ((((CM->state != 9) && (!func_80033BE0())) && (CM->state != 0x29)) && (CM->state != 0x2B)) {
        RotMatrix(&CM->f_84, mat);
        ApplyMatrixSV(mat, &CM->f_60, &CM->f_60);
        VectorNormalSS(&CM->f_60, &CM->f_60);
    }
    CM->f_3C = CM->f_60;
    if ((((u32) ((((u16 *) (&CM->f_248))[1] & 3) - 1)) < 2) && (CM->f_F0 <= 0)) {
        CM->f_F0++;
    } else if (((CM->f_79 == 0) && ((D_800AE940_U[CM->state].flags >> 6) & 1)) && func_800361B4()) {
        if (func_800349F4(CM->f_F4)) {
            u32 nf = ((Nd_412B0 *)D_800B4D00)[CM->f_F4].f_0;
            if ((nf & 4) && (CM->f_22C == 0)) {
                goto react;
            }
            if (((!(nf & 8)) || func_800339EC()) || (CM->f_20C >= ((Nd_412B0 *)D_800B4D00)[CM->f_F4].f_10)) {
                goto skip_react;
            }
        }
    react:
        if (CM->state == 0x33) {
            func_800359B4();
        } else if (CM->state != 0x34) {
            func_800363A4();
        }
    }
skip_react:
    if (((CM->f_248 >> 19) & 1) && (!func_80033B10())) {
        CM->f_248 &= 0xFFF7FFFF;
    }
    CM->f_5E = Monkey_CurAnimIndex_u();
    if (((D_800AE940_U[CM->state].flags >> 4) & 1) && (!func_800339EC())) {
        CM->f_46 = -0x100;
    } else {
        CM->f_46 = 0x100;
    }
    if ((CM->state == 0x1E) || (CM->state == 0x20)) {
        CM->f_46 = 0x100;
    }
}
#undef CM
#undef NODE
#undef STF
#define CM ((M_39ED4_80039ED4 *)g_CurMonkey)




/* Per frame, for each of the 4 active monkeys (if g_Game+0x8184 > 0): picks what it reacts to.
 * That is the RC car (g_RcCar, setting g_MonkeyTargetIsRC) when Spike's +0xF2 is 7 (the RC Car)
 * and the car is closer to the monkey than Spike, else Spike (g_MonkeyTarget). Then, unless the
 * monkey is caught (state 2), runs its AI: func_8003AD9C when its +0xEA timer passes 0xA8D, else
 * every D_800AEB66-th frame in its own slot (by +0x7B) func_8004086C unless func_800339EC; then
 * func_80039B30 and Monkey_Update. Declared s32 with no return value: the original keeps v0
 * live at the exit. */
s32 Monkey_UpdateAll(void) {
    s16 i;
    s32 d;
    if (((struct Game_800424D4 *)&g_Game)->f_8184 <= 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        g_CurMonkey = (Monkey *)g_ActiveMonkeys[i];
        if (((struct Spike_800424D4 *)&g_Spike)->f_F2 == 7 &&
            (d = Vec_Dist(&g_CurMonkey->f_24, (u8 *)&g_Spike + 0x24),
             Vec_Dist(&g_CurMonkey->f_24, (u8 *)&g_RcCar + 0x24) < d)) {
            g_MonkeyTargetIsRC = 1;
            g_MonkeyTarget = (Monkey *)&g_RcCar;
        } else {
            g_MonkeyTargetIsRC = 0;
            g_MonkeyTarget = (Monkey *)&g_Spike;
        }
        if (g_CurMonkey != 0 && g_CurMonkey->f_7A != 2) {
        if ((u16)g_CurMonkey->f_EA >= 0xA8D) {
            func_8003AD9C();
        } else if (D_800AEB60 % D_800AEB66 == g_CurMonkey->f_7B % D_800AEB66) {
            if (func_800339EC() == 0) {
                func_8004086C();
            }
        }
        func_80039B30();
        Monkey_Update();
        }
    }
}

extern Monkey g_MonkeysSA[] asm("g_Monkeys");
extern VEC_80034684 D_800EC204;
void Monkey_Spawn(s32, s32, s32);
void func_800407F0(void);
#define AM ((Monkey **)g_ActiveMonkeys)
/* Picks which monkeys in the area get one of the D_800AEB66 active slots (g_ActiveMonkeys):
 * refreshes every monkey's distance to D_800EC204 (+0x210), then gives free slots in order and
 * otherwise replaces the farthest holder when a closer monkey is found (the bumped one goes back
 * to +0x7A = 1). Newly active monkeys are respawned into their slot (Monkey_Spawn(kind, 4, slot));
 * a slot whose kind changed is re-placed at its old node (+0xE6) or sent off by func_8003AD9C. */
void Monkey_SelectActive(void) {
    Monkey *saved = g_CurMonkey;
    s16 kinds[4];
    s16 i;
    s16 j;
    s16 worst;
    s32 far;
    s32 found;
    Monkey *m;
    s32 n;
    u8 b;
    s32 st;

    if (g_MonkeyCount == 0 || D_800AEB66 == 0) {
        return;
    }
    for (j = 0; j < 4; j++) {
        kinds[j] = AM[j]->f_7C;
    }
    for (i = 0; i < g_MonkeyCount; i++) {
        Monkey *p = &g_MonkeysSA[i];
        if ((u8)(p->f_7A - 2) < 2) {
            continue;
        }
        g_CurMonkey = p;
        g_CurMonkey->f_210 = Vec_Dist((VEC_80034684 *)&p->f_24, &D_800EC204);
        if (g_CurMonkey->f_7A == 4) {
            g_CurMonkey->f_7A = 1;
            Monkey_DisableCollision();
        }
    }
    for (j = 0; j < 4; j++) {
        AM[j] = 0;
    }
    for (i = 0; i < g_MonkeyCount; i++) {
        far = -1000;
        worst = -1;
        found = 0;
        g_CurMonkey = &g_MonkeysSA[i];
        if ((u8)(g_MonkeysSA[i].f_7A - 2) < 2) {
            continue;
        }
        for (j = 0; j < D_800AEB66; j++) {
            if (AM[j] == 0) {
                AM[j] = &g_MonkeysSA[i];
                found = 1;
                break;
            }
            if (far < AM[j]->f_210) {
                far = AM[j]->f_210;
                worst = j;
            }
        }
        if (!found && g_CurMonkey->f_210 < far) {
            if (AM[worst]->f_7A != 0) {
                AM[worst]->f_7A = 1;
            }
            AM[worst] = g_CurMonkey;
        }
    }
    for (j = 0; j < D_800AEB66; j++) {
        g_CurMonkey = AM[j];
        if (g_CurMonkey != 0) {
            st = g_CurMonkey->f_7A;
            Monkey_Spawn(g_CurMonkey->f_7C, 4, j);
            if (st == 0) {
                func_8003AD9C();
            }
        }
    }
    for (j = 0; j < D_800AEB66; j++) {
        m = AM[j];
        if (m == 0 || kinds[j] == m->f_7C) {
            continue;
        }
        n = m->f_E6;
        g_CurMonkey = m;
        b = m->f_D8;
        if (n == -1) {
            func_8003AD9C();
        } else {
            func_800407F0();
            g_CurMonkey->f_E6 = n;
            g_CurMonkey->f_D8 = b;
        }
        D_800B4D00[g_CurMonkey->f_E6].f_14[g_CurMonkey->f_7B] = 1;
        g_CurMonkey->f_EE = 1;
    }
    g_CurMonkey = saved;
}
#undef AM


/* Runs the per-frame update for each of the 4 active monkeys. Monkeys that are
   gone, caught or off-screen are skipped (in area 0x24 their sound 0x602D is stopped). */
void Monkey_UpdateActive(void) {
    s16 i;
    M42B68_80042B68 *m;
    u32 fl;

    for (i = 0; i < 4; i++) {
        (*(M42B68_80042B68 * *)&g_CurMonkey) = m = ((M42B68_80042B68 * *)&g_ActiveMonkeys)[i];
        fl = m->f_248;
        if (((fl & 0x40030000) == 0x40020000 && (m->f_F0 > 0 || m->f_F0 >= m->f_128))
            || (s32)fl < 0 || (m->f_228 & 0x4000) || m == 0 || m->f_7A == 2
            || Monkey_IsOffScreen() != 0) {
            if (D_800F4350.f_126 == 0x24 && (*(M42B68_80042B68 * *)&g_CurMonkey)->f_160 != -1) {
                func_800880D0(0x602D, (*(M42B68_80042B68 * *)&g_CurMonkey)->f_160);
                (*(M42B68_80042B68 * *)&g_CurMonkey)->f_160 = -1;
            }
            continue;
        }
        if (D_800AEB58 == 2) {
            func_8008C3C0((*(M42B68_80042B68 * *)&g_CurMonkey)->f_80, (*(M42B68_80042B68 * *)&g_CurMonkey)->f_82);
            func_8008CBFC(D_800A4BBC, (*(M42B68_80042B68 * *)&g_CurMonkey)->f_7C);
        }
        if ((D_800AEB60 + (*(M42B68_80042B68 * *)&g_CurMonkey)->f_7B) % 3 == 0) {
            Monkey_UpdateLod();
        }
        m = (*(M42B68_80042B68 * *)&g_CurMonkey);
        if (m->f_78 == 0x1E || m->f_78 == 0x20) {
            D_800F4B30[0] = 0;
            D_800F4B30[1] = 0;
            D_800F4B30[2] = 0;
            D_800F4B30[4] = 0;
            D_800F4B30[6] = 0;
            D_800F4B30[8] = 0;
            D_800F4B30[10] = 0;
            D_800F4B30[5] = -D_800AEB60 * 80;
            D_800F4B30[9] = D_800AEB60 * 400;
        } else {
            Anim_BlendCurrentEntry();
        }
        if ((*(M42B68_80042B68 * *)&g_CurMonkey)->f_168 != 0) {
            Shadow_Draw(&(*(M42B68_80042B68 * *)&g_CurMonkey)->f_24,
                          Floor_GetHeight((*(M42B68_80042B68 * *)&g_CurMonkey)->f_24, (*(M42B68_80042B68 * *)&g_CurMonkey)->f_28, (*(M42B68_80042B68 * *)&g_CurMonkey)->f_2C),
                          (*(M42B68_80042B68 * *)&g_CurMonkey)->f_168, *(s32 *)0x1F8003FC);
        }
        Monkey_Draw();
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BBC);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BC0);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BD0);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BE0);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BEC);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4BF8);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C04);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C10);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C1C);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C28);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C34);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C40);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C4C);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C58);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C64);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C70);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C7C);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C88);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4C94);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4CA0);
INCLUDE_RODATA("asm/nonmatchings/game/80032E30_monkey", D_800A4CAC);


/* Per-frame monkey driver: advances the AI frame counter, clears the expired +0x248 bit 21 flags
 * and ticks the +0x158 timers of the 8 monkeys, then (unless g_Game+0x8100 bit 2 freezes them)
 * runs Monkey_UpdateAll and the follow-up passes, and refreshes Monkey_SelectActive when the monkey
 * count or AI stagger changes or every 30 frames. Declared s32 with no return value: the
 * original keeps v0 live at the exit. */
s32 Monkey_UpdateFrame(void)
{
  s16 i;
  D_800AEB5C++;
  if (func_800339EC() != 0)
  {
    D_800AEB60 = D_800AEB5C;
  }
  else
  {
    D_800AEB60 = ((struct Game_80042E18 *) (&g_Game))->frame;
  }
  for (i = 0; i < 8; i++)
  {
    g_CurMonkey = (Monkey *) (&((MD_80042E18_80042E18 *)&g_Monkeys)[i]);
    if (((MD_80042E18_80042E18 *) g_CurMonkey)->f_248.b21 == 1)
    {
      if ((((MD_80042E18_80042E18 *) g_CurMonkey)->f_7A != 4) || (func_80033C80() == 0))
      {
        ((MD_80042E18_80042E18 *) g_CurMonkey)->f_154 = -1;
        ((MD_80042E18_80042E18 *) g_CurMonkey)->f_248.b21 = 0;
      }
    }
    if (((MD_80042E18_80042E18 *) g_CurMonkey)->f_158 > 0)
    {
      ((MD_80042E18_80042E18 *) g_CurMonkey)->f_158--;
    }
  }

  if ((D_800B4CF4 == 0) && (((struct Game_80042E18 *) (&g_Game))->f_8184 > 0))
  {
    if (!(((struct Game_80042E18 *) (&g_Game))->f_8100 & 2))
    {
      Monkey_UpdateAll();
    }
    Monkey_UpdateActive();
    func_8003A334();
    Monkey_UpdateQueuedSounds();
    if (((D_800AEC10 != ((struct Game_80042E18 *) (&g_Game))->f_8184) || (D_800AEC12 != D_800AEB66)) || ((D_800AEB60 % 30) == 0))
    {
      Monkey_SelectActive();
    }
    D_800AEC10 = ((struct Game_80042E18 *) (&g_Game))->f_8184;
    D_800AEC12 = D_800AEB66;
  }
}
