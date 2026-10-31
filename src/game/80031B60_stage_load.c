#include "common.h"
#include "m2c_macros.h"
typedef struct { s32 v[9]; } S32x9_80032BBC_80032BBC;
typedef struct { u8 pad0[0x14]; void *f_14; s32 f_18; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 f_24; s32 f_28; s32 f_2C; s32 f_30; s32 f_34; s32 f_38; u8 pad3C[8]; s16 f_44; u8 pad46[2]; s16 f_48; s16 f_4A; u8 pad4C[0xC]; s16 f_58; u8 pad5A[2]; s16 f_5C; s16 f_5E; SVECTOR f_60; s16 f_68; s16 f_6A; s16 f_6C; u8 pad6E[2]; s32 f_70; u8 pad74[0x18]; s16 f_8C; u8 pad8E[0x74]; s16 f_102; u8 pad104[4]; s32 f_108; u8 pad10C[4]; s32 f_110; s32 f_114; u8 pad118[4]; s32 f_11C; u8 pad120[0xC]; s32 f_12C; } S_Spike_80032BBC_80032BBC;
typedef struct { u32 f_0; u16 f_4; u16 p6; u16 f_8; u16 pA; u16 f_C; u16 pE; u16 f_10; u16 p12; u16 f_14; u16 p16; u16 f_18; } Hdr_80032ADC_80032ADC;
typedef struct { u32 *f_0; u32 *f_4; u32 *f_8; u32 *f_C; u8 f_10[0x18]; u32 *f_28; } Obj_80032ADC_80032ADC;
typedef struct { u16 lo; u16 hi; } W_8003272C_8003272C;
typedef struct { u32 *a, *b, *c, *d; } AS_8003272C_8003272C;
typedef struct { u8 pad0[0x18]; u32 *f_18; u8 pad1C[0x14]; s32 f_30, f_34, f_38; u8 pad3C[0xA]; s16 f_46; u8 pad48[8]; s32 f_50; u8 pad54[0x12]; s16 f_66; u8 pad68[8]; s32 f_70; u8 pad74[0x1A]; s16 f_8E; u8 pad90[0x50]; s32 f_E0; u8 padE4[4]; s16 f_E8; u8 padEA[2]; s16 f_EC; u8 padEE[6]; s32 f_F4; s32 f_F8; u8 padFC[2]; s16 f_FE; u8 pad100[0x14]; s32 f_114, f_118, f_11C, f_120, f_124, f_128, f_12C; u8 pad130[8]; s32 f_138; u8 pad13C[0xC]; s16 f_148; } Sp_8003272C_8003272C;
typedef struct { s32 w[9]; } S32x9_80032D38;
typedef struct { s16 vx, vy, vz, pad; } SVEC_80032D38;

M2C_UNK SetFarColor(u8, u8, u8);
extern struct S_D_800EBFA0 { u8 pad_0[0x1C]; u8 f_1C; u8 f_1D; u8 f_1E; u8 pad_1F[0x5]; u16 f_24; u8 pad_26[0x2]; u16 f_28; } D_800EBFA0;
struct S_D_800EC350_80032BBC { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 pad812C[0x74]; s32 f_81A0; u8 pad81A4[0xB4]; SVECTOR f_8258; SVECTOR f_8260; };
extern M2C_UNK g_Game;
extern M2C_UNK g_Spike;
extern M2C_UNK D_800E9C60;
void func_80010C3C(u16, u16, S32x9_80032BBC_80032BBC *);
s16 Floor_GetHeight(s32, s32, s32);
void VectorNormalSS(void *, void *);
void Collision_Set(s32, void *, void *);
void func_80047754(void);
struct Spike_80032ADC { u8 pad0[0x148]; s16 f_148; u8 f_14A; u8 f_14B; };
struct D4DE0_80032ADC { u8 pad0[0xA0]; u32 *f_A0; u32 *f_A4; u32 *f_A8; u32 *f_AC; };
extern Obj_80032ADC_80032ADC *D_800B4D70;
extern M2C_UNK g_SpikeAnimSets;
void func_80015AC0(void *, u32 *);
struct Game_8003272C { u8 pad0[0x819C]; u32 *f_819C; u32 *f_81A0; u8 pad81A4[0x58]; W_8003272C_8003272C *f_81FC; W_8003272C_8003272C *f_8200; W_8003272C_8003272C *f_8204; u8 pad8208[0x34]; u16 f_823C; u16 f_823E; };
extern s32 D_800EC010[];
extern u8 D_800EC060[];
extern u8 D_800F4C30[];
extern u8 D_800F4630[];
extern s16 D_800F4DC4;
void func_80015B30(Sp_8003272C_8003272C *, u32 *);
void func_80015D10(void *, u32 *);
void TimeNet_Init(u32 *);
struct g_Spike_80032D38 { u8 pad0[0x1C]; s16 f_1C; s16 f_1E; s16 f_20; u8 pad22[2]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; s16 f_60; s16 f_62; s16 f_64; u8 pad66[0xC6]; s32 f_12C; };
#define G_SPIKE_80032D38 ((struct g_Spike_80032D38 *)&g_Spike)

typedef struct { u8 b[4]; } C4_31B60;
typedef struct { s16 x, y, w, h; } C8_31B60;
typedef struct { u32 frame; u8 pad4[0x80FC]; s32 f_8100; u8 pad8104[0x1E]; s16 f_8122; s16 f_8124; u16 f_8126; u8 pad8128[2]; u16 f_812A; u8 f_812C; u8 pad812D; u16 f_812E; u8 pad8130[8]; u8 f_8138; u8 pad8139[0x17]; s16 f_8150; s16 f_8152; u8 pad8154[0x40]; u32 *f_8194; u32 *f_8198; u8 pad819C[0x6C]; void *f_8208; void *f_820C; void *f_8210; void *f_8214; void *f_8218; void *f_821C; void *f_8220; u32 *f_8224; u32 *f_8228; u8 pad822C[4]; u32 *f_8230; void *f_8234; void *f_8238; u8 pad823C[4]; void *f_8240; void *f_8244; void *f_8248; void *f_824C; void *f_8250; void *f_8254; u8 pad8258[0x10]; s16 f_8268; u8 pad826A[0x16]; s32 f_8280; u16 f_8284; u8 pad8286[2]; s32 f_8288; s32 f_828C; u8 pad8290[0x10]; s32 f_82A0; s32 f_82A4; s32 f_82A8; s32 f_82AC; u8 pad82B0[8]; s16 f_82B8; s16 f_82BA; u8 pad82BC[4]; C4_31B60 f_82C0; } Game_31B60;
typedef struct { u32 f_0, f_4, f_8, f_C, f_10; u8 pad14[0xC]; C4_31B60 f_20; C4_31B60 f_24; u16 f_28, f_2A, f_2C, f_2E; u8 pad30[4]; u32 f_34[8]; } Sd_31B60;
typedef struct { u8 pad0[0x18]; u8 *f_18; C4_31B60 f_1C; u8 pad20[4]; s32 f_24; s32 f_28; s32 f_2C; } Ter_31B60;
extern Game_31B60 g_Game_31B60 asm("g_Game");
extern Ter_31B60 D_800EBFA0_31B60 asm("D_800EBFA0");
extern s32 D_800A8A54;
extern s32 D_800A8A58;
extern u16 g_RandSeed;
extern u16 D_800AE8F2;
extern s32 D_800E38E4;
extern struct { s32 v; } D_800F4DD0_s asm("D_800F4DD0");
extern u8 D_800E9C60_31B60[][0x20] asm("D_800E9C60");
extern u8 D_800F4730[][0x20];
extern u8 D_800E78C0[];
extern u8 D_800EC330[];
extern C4_31B60 D_800AE914[];
extern struct { u32 f_0; } g_GadgetState;
void func_8008C01C(void);
void func_8008C058(s32);
s16 func_80010CA4(s32);
s16 Stage_GetWorld(s32);
void func_8004637C(void *);
void func_8007AFB8(void);
void func_800690E8(void *);
void Zone_SetTable(void *);
void func_800715A0(void);
void func_8009B7C8(void *);
void func_8009B7E4(void *);
void func_8009B7F0(void *);
void Spike_CreateModel(void *, s32);
void func_8007163C(void *);
void func_80071694(void *);
s32 func_80086F00(s32, s32);
s32 func_80087388(void);
void func_8008745C(void);
void Stage_ApplyFog(void);
void Light_SetColorMode(s32, s32, s32, s32);
void func_80086540(void);
s32 func_8003244C(void);
u8 *Grid_BuildHalfResMap(void);
void func_8007D0F0(void);
void func_8005CB1C(void);
void func_8005CC58(void);
void func_8005CCDC(void);
void func_8008DEE0(void);
void Collision_Init(void);
s32 Spike_SpawnAtStageStart(void);
void func_8007CD60(void);
void func_800505C8(void);
void Monkey_InitAll(void);
void func_8007BCB4(void);
void Projectile_InitAll(void);
void EnemyShot_InitAll(void);
void func_80069500(void);
void func_80088670(void);
void Link_InitArea(void);
void func_8005AB90(void);
void Pickup_SpawnArea(void);
void Gadget_SetupForMode(void);
void Tex_MakeFogLevels_31B60(C8_31B60 *, s32, C4_31B60) asm("Tex_MakeFogLevels");
void RcCar_Remove(void);

s32 func_80031B60(s32 stage, s32 mode)
{
  u16 prev;
  u32 *dir;
  u32 *dsz;
  Sd_31B60 *sd;
  u8 type;
  u8 *e;
  s32 i;
  u32 *dst;
  u32 *src;
  u8 *sub;
  u32 o0;
  u32 o2;
  u32 o3;
  u32 o4;
  s32 w;
  s32 h;
  u8 *m1;
  u8 *m2;
  D_800A8A54 = 0;
  if (stage < 0x68)
  {
    if (stage >= 0x63)
    {
      D_800A8A58 = 1;
      g_Game_31B60.frame = 0;
      g_RandSeed = 12345;
      D_800AE8F2 = 0xD432;
      g_Game_31B60.f_8138 = 0;
    }
    else
    {
      D_800A8A58 = 0;
    }
  }
  else
  {
    D_800A8A58 = 0;
  }
  if (g_Game_31B60.f_812E == 2)
  {
    g_RandSeed = 12345;
    g_Game_31B60.frame = 0;
    D_800AE8F2 = 0xD432;
  }
  if (g_Game_31B60.f_812C == 1)
  {
    g_Game_31B60.f_8100 = 1;
  }
  else
  {
    g_Game_31B60.f_8100 = 0;
  }
  func_8008C01C();
  dir = (u32 *) 0x801544C4;
  dsz = (u32 *) 0x80154504;
  func_8008C058(D_800E38E4);
  i = 0;
  prev = g_Game_31B60.f_8126;
  g_Game_31B60.f_8194 = (u32 *) (dir[3] + 0x80154000);
  sd = (Sd_31B60 *) g_Game_31B60.f_8194;
  g_Game_31B60.f_8122 = func_80010CA4(stage);
  g_Game_31B60.f_8124 = Stage_GetWorld(stage);
  g_Game_31B60.f_8126 = stage;
  g_Game_31B60.f_812A = mode;
  g_Game_31B60.f_8150 = 0;
  g_Game_31B60.f_8152 = 0;
  g_Game_31B60.f_82B8 = 0;
  g_Game_31B60.f_82BA = 0;
  g_Game_31B60.f_8268 = 0;
  D_800F4DD0_s.v = 50;
  for (; i < 32; i++)
  {
    func_8004637C(D_800E9C60_31B60[i]);
    func_8004637C(D_800F4730[i]);
  }

  func_8004637C(D_800E78C0);
  func_8004637C(D_800EC330);
  func_8007AFB8();
  func_800690E8(0);
  Zone_SetTable(0);
  func_800715A0();
  func_8009B7C8(0);
  for (i = 0; i < 8; i++)
  {
    type = *((u8 *) (&sd->f_34[i]));
    if (type != 0)
    {
      { u8 *sb = ((u8 *) sd) + ((sd->f_34[i] >> 8) * 4);
      switch (type)
      {
        case 0x40:
          Spike_CreateModel(sb, 1);
          g_GadgetState.f_0 |= 1;
          break;

        case 0x41:
          Spike_CreateModel(sb, 2);
          g_GadgetState.f_0 |= 2;
          break;

        case 0x20:
          func_800690E8(sb);
          break;

        case 0x10:
          func_8007163C(sb);
          break;

        case 0x11:
          func_80071694(sb);
          break;

        case 0x8:
          Zone_SetTable(sb);
          break;

        case 0x30:
          func_8009B7C8(sb);
          break;

        case 0x31:
          func_8009B7E4(sb);
          break;

        case 0x32:
          func_8009B7F0(sb);
          break;

      } }

    }
  }

  g_Game_31B60.f_8244 = (void *) (dir[7] + 0x80154000);
  g_Game_31B60.f_8248 = (void *) (dir[6] + 0x80154000);
  g_Game_31B60.f_8250 = (void *) (dir[5] + 0x80154000);
  g_Game_31B60.f_824C = (void *) (dir[9] + 0x80154000);
  g_Game_31B60.f_8240 = (void *) (dir[8] + 0x80154000);
  g_Game_31B60.f_8254 = (void *) 0x80102800;
  if (func_80086F00(stage, (s16) prev))
  {
    dst = g_Game_31B60.f_8230;
    src = (u32 *) (dir[0] + 0x80154000);
    for (i = 0; i < (((*dsz) + 3) >> 2); i++)
    {
      *(dst++) = *(src++);
    }

    if (g_Game_31B60.f_812C == 2)
    {
      if (((((((((((stage == 0x4B) || (stage == 4)) || (stage == 3)) || (stage == 0x21)) || (stage == 0x22)) || (stage == 0x1E)) || (stage == 0x20)) || (stage == 6)) || (stage == 8)) || (stage == 9)) || (stage == 0xA))
      {
        func_80087388();
        func_8008745C();
      }
      else
        if (stage == 0x48)
      {
        func_80087388();
      }
    }
  }
  g_Game_31B60.f_8234 = (void *) 0x80154000;
  g_Game_31B60.f_828C = *(s32 *)0x80154240;
  if (*(s32 *)0x80154240 == 0)
  {
    g_Game_31B60.f_8238 = 0;
  }
  else
  {
    g_Game_31B60.f_8238 = (void *) 0x80154244;
  }
  g_Game_31B60.f_8198 = ((u32 *) ((u8 *) sd)) + ((u32 *) ((u8 *) sd))[1];
  sub = (u8 *) (sd->f_10 * 4 + (u32) sd);
  o0 = ((u32 *) sub)[0];
  o2 = ((u32 *) sub)[2];
  o3 = ((u32 *) sub)[3];
  o4 = ((u32 *) sub)[4];
  g_Game_31B60.f_8208 = (sub + ((u32 *) sub)[1]) + 2;
  g_Game_31B60.f_8210 = ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o0) + 4;
  w = *((s16 *) ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o0));
  g_Game_31B60.f_82A0 = w;
  h = *((s16 *) (((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o0) + 2));
  g_Game_31B60.f_82A8 = w << 8;
  g_Game_31B60.f_82A4 = h;
  g_Game_31B60.f_82AC = h << 8;
  g_Game_31B60.f_820C = ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o2) + 2;
  g_Game_31B60.f_8284 = *((u16 *) ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o2));
  g_Game_31B60.f_8214 = ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o3) + 2;
  g_Game_31B60.f_8218 = ((((u8 *) sd) + (((u32 *) ((u8 *) sd))[4] * 4)) + o4) + 2;
  g_Game_31B60.f_8224 = ((u32 *) ((u8 *) sd)) + ((u32 *) ((u8 *) sd))[2];
  g_Game_31B60.f_8228 = (((u32 *) ((u8 *) sd)) + ((u32 *) ((u8 *) sd))[3]) + 1;
  g_Game_31B60.f_8280 = *(((u32 *) ((u8 *) sd)) + ((u32 *) ((u8 *) sd))[3]);
  g_Game_31B60.f_821C = (void *) (dir[4] + 0x80154004);
  g_Game_31B60.f_8288 = *((s32 *) (dir[4] + 0x80154000));
  g_Game_31B60.f_8220 = (void *) (dir[4] + 0x80154004 + g_Game_31B60.f_8288 * 8);
  g_Game_31B60.f_82C0 = D_800AE914[stage % 9];
  D_800EBFA0_31B60.f_1C = *((C4_31B60 *) (((u8 *) sd) + 0x20));
  if ((*((u16 *) (((u8 *) sd) + 0x28))) != 0)
  {
    i = (*((u16 *) (((u8 *) sd) + 0x2E))) - (*((u16 *) (((u8 *) sd) + 0x2C)));
    if (i <= 0)
    {
      i = 1;
    }
    D_800EBFA0_31B60.f_24 = 0x1000000 / i;
    D_800EBFA0_31B60.f_28 = *((u16 *) (((u8 *) sd) + 0x2C));
  }
  else
  {
    D_800EBFA0_31B60.f_28 = 0x4B0;
    D_800EBFA0_31B60.f_24 = 0;
  }
  D_800EBFA0_31B60.f_24 = 0xF000;
  D_800EBFA0_31B60.f_2C = (D_800EBFA0_31B60.f_28 * 4) + 0x400;
  Stage_ApplyFog();
  Light_SetColorMode(0, 0, 0, 0);
  func_80086540();
  func_8003244C();
  D_800EBFA0_31B60.f_18 = Grid_BuildHalfResMap();
  func_8007D0F0();
  func_8005CB1C();
  func_8005CC58();
  func_8005CCDC();
  func_8008DEE0();
  Collision_Init();
  Spike_SpawnAtStageStart();
  func_8007CD60();
  func_800505C8();
  Monkey_InitAll();
  func_8007BCB4();
  Projectile_InitAll();
  EnemyShot_InitAll();
  func_80069500();
  func_80088670();
  Link_InitArea();
  func_8005AB90();
  Pickup_SpawnArea();
  Gadget_SetupForMode();
  if ((*((u16 *) (((u8 *) sd) + 0x2A))) != 0)
  {
    C8_31B60 tmp = {0x370, 0x80, 0x10, 0x80}; Tex_MakeFogLevels_31B60(&tmp, 0, sd->f_24);
  }
  RcCar_Remove();
  return 0;
}



void Stage_ApplyFog(void) {
    u8 *scratch = (u8 *)0x1F800000;
    SetFarColor(D_800EBFA0.f_1C, D_800EBFA0.f_1D, D_800EBFA0.f_1E);
    *(u16 *)(scratch + 0x03C6) = 0;
    *(u16 *)(scratch + 0x03C4) = 0;
    *(u16 *)(scratch + 0x03C0) = D_800EBFA0.f_24;
    *(u16 *)(scratch + 0x03C2) = D_800EBFA0.f_28;
}

typedef struct { u16 f_0; u16 f_2; s32 f_4; u8 *f_8; u8 *f_C; u8 *f_10; u8 *f_14; } Grid_8003244C;
typedef struct { u16 model; u16 rot; u16 x; u16 y; u16 z; u16 pad; } Place_8003244C;
typedef struct { u32 *f_0; u8 pad4[0xC]; s16 x; s16 y; s16 z; u16 zone; u8 pad18[4]; s32 f_1C; } Mdl_8003244C;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_8003244C;
struct Game_8003244C { u8 pad0[0x8194]; u32 *f_8194; u16 *f_8198; u8 pad819C[0x88]; u8 *f_8224; Place_8003244C *f_8228; u8 pad822C[0x54]; s32 f_8280; };
extern struct Game_8003244C g_Game_3244C asm("g_Game");
extern Grid_8003244C D_800EBFA0_3244C asm("D_800EBFA0");
extern Mdl_8003244C *D_800B4D64;
extern MAT_8003244C D_800E7900[];
extern char D_800A48E0[];
void *Mem_Alloc(s32);
void Model_BindMesh_3244C(Mdl_8003244C *, u8 *) asm("Model_BindMesh");
s16 Zone_FindAt(s32, s32, s32, s32);
void func_8004637C(void *);
void bios_printf(char *, ...);
void bios_exit(s32);

s32 func_8003244C(void) {
    u16 *h;
    s32 n;
    s32 i;
    Mdl_8003244C *m;
    u32 k;
    s32 x, y, z;

    h = g_Game_3244C.f_8198;
    D_800EBFA0_3244C.f_0 = h[0];
    D_800EBFA0_3244C.f_2 = h[1];
    if (!(*g_Game_3244C.f_8194 & 2)) {
        D_800EBFA0_3244C.f_4 = ((s32 *)h)[1];
        D_800EBFA0_3244C.f_8 = (u8 *)h + 8;
        D_800EBFA0_3244C.f_C = (u8 *)h + (D_800EBFA0_3244C.f_0 * D_800EBFA0_3244C.f_2 * 4 + 8);
        D_800EBFA0_3244C.f_10 = (u8 *)h + (D_800EBFA0_3244C.f_0 * D_800EBFA0_3244C.f_2 * 4 + 8) + D_800EBFA0_3244C.f_4 * 4;
        D_800EBFA0_3244C.f_14 = D_800EBFA0_3244C.f_10 + D_800EBFA0_3244C.f_0 * D_800EBFA0_3244C.f_2 * 8;
    }
    n = 0;
    D_800B4D64 = Mem_Alloc(g_Game_3244C.f_8280 << 5);
    for (i = 0; i < g_Game_3244C.f_8280; i++) {
        Model_BindMesh_3244C(&D_800B4D64[i], g_Game_3244C.f_8224 + *(u16 *)(g_Game_3244C.f_8224 + g_Game_3244C.f_8228[i].model * 4 + 4) * 4);
        D_800B4D64[i].x = g_Game_3244C.f_8228[i].x;
        x = D_800B4D64[i].x;
        D_800B4D64[i].y = g_Game_3244C.f_8228[i].y;
        y = D_800B4D64[i].y;
        D_800B4D64[i].z = g_Game_3244C.f_8228[i].z;
        z = D_800B4D64[i].z;
        k = *(u8 *)D_800B4D64[i].f_0;
        if (k < 6) {
            if (k >= 4) {
                D_800B4D64[i].zone = 0xFFFF;
                goto next;
            }
        }
        D_800B4D64[i].zone = Zone_FindAt(x, y, z, 0);
    next:
        if ((*D_800B4D64[i].f_0 & 0xF) != 3) {
            D_800B4D64[i].f_1C = g_Game_3244C.f_8228[i].rot;
        } else {
            D_800B4D64[i].f_1C = (s32)&D_800E7900[n];
            func_8004637C(&D_800E7900[n]);
            RotMatrixY(g_Game_3244C.f_8228[i].rot, &D_800E7900[n]);
            n++;
            if (n > 0x20) {
                bios_printf(D_800A48E0);
                bios_exit(1);
            }
        }
        *D_800B4D64[i].f_0 &= 0xFFFF1FFF;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80031B60_stage_load", D_800A48E0);


void Mem_ZeroWords(s32* dst, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dst++ = 0;
    }
}

/* Sets Spike up from his data block loaded at 0x80103000 (header of word offsets): model and
 * skeleton (g_Game+0x819C/+0x81A0), the 10 gadget animation sets g_SpikeAnimSets, and three
 * tables of effect models (g_Game+0x81FC -> D_800EC060, +0x8200 -> D_800F4C30,
 * +0x8204 -> D_800F4630). Resets his state: health (+0xE8) 5, velocities, timers, flags, and
 * the movement constants D_800EC010[0..17]. Returns 0. */
s32 Spike_Init(void) {
    W_8003272C_8003272C *h = (W_8003272C_8003272C *)0x80103000;
    W_8003272C_8003272C *p;
    s32 i;
    s32 n;
    p = (W_8003272C_8003272C *)0x80103000;
    (*(struct Game_8003272C *)&g_Game).f_819C = (u32 *)h + h[1].lo;
    (*(struct Game_8003272C *)&g_Game).f_81FC = (W_8003272C_8003272C *)((u32 *)h + h[2].lo);
    (*(struct Game_8003272C *)&g_Game).f_8200 = (W_8003272C_8003272C *)((u32 *)h + h[3].lo);
    (*(struct Game_8003272C *)&g_Game).f_8204 = (W_8003272C_8003272C *)((u32 *)h + h[4].lo);
    (*(struct Game_8003272C *)&g_Game).f_81A0 = (u32 *)h + h[5].lo;
    for (i = 0; i < 10; i++) {
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].a = (u32 *)h + p[i * 4 + 5].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].b = (u32 *)h + p[i * 4 + 6].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].c = (u32 *)h + p[i * 4 + 7].lo;
        ((AS_8003272C_8003272C *)&g_SpikeAnimSets)[i].d = (u32 *)h + p[i * 4 + 8].lo;
    }
    Spike_LoadModelData(0);
    (*(struct Game_8003272C *)&g_Game).f_823E = 6;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_18 = (*(struct Game_8003272C *)&g_Game).f_81A0;
    func_80015B30(&(*(Sp_8003272C_8003272C *)&g_Spike), (*(struct Game_8003272C *)&g_Game).f_819C);
    (*(Sp_8003272C_8003272C *)&g_Spike).f_66 = 1;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_46 = 0x100;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_E8 = 5;
    D_800F4DC4 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_8E = 0x1000;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_30 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_34 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_38 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_120 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_124 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_128 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_114 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_118 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_11C = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_50 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_E0 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_EC = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_148 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_FE = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_12C = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_138 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_70 = 0;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_F4 = 0xFFFFFF;
    (*(Sp_8003272C_8003272C *)&g_Spike).f_F8 = 0xFFFFFF;
    D_800EC010[0] = 0;
    D_800EC010[1] = 0xAD;
    D_800EC010[2] = -0x672;
    D_800EC010[3] = -0x29E;
    D_800EC010[4] = -0x690;
    D_800EC010[5] = 0x500;
    D_800EC010[6] = 1;
    D_800EC010[7] = 0xC8;
    D_800EC010[8] = 0x780;
    D_800EC010[9] = 0x3F2;
    D_800EC010[10] = 0x64;
    D_800EC010[11] = 0x50;
    D_800EC010[12] = 0x3C;
    D_800EC010[13] = -0x76C;
    D_800EC010[14] = -0x15AE;
    D_800EC010[15] = -0x1158;
    D_800EC010[16] = -0x78;
    D_800EC010[17] = 0xA5A;
    (*(struct Game_8003272C *)&g_Game).f_823C = (*(struct Game_8003272C *)&g_Game).f_81FC[0].lo - 1;
    for (i = 0; i < (*(struct Game_8003272C *)&g_Game).f_823C; i++) {
        func_80015D10(&D_800EC060[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_81FC + (*(struct Game_8003272C *)&g_Game).f_81FC[i + 1].lo);
    }
    TimeNet_Init((u32 *)(*(struct Game_8003272C *)&g_Game).f_81FC + (*(struct Game_8003272C *)&g_Game).f_81FC[i + 1].lo);
    n = *(s32 *)(*(struct Game_8003272C *)&g_Game).f_8200;
    for (i = 0; i < n; i++) {
        func_80015D10(&D_800F4C30[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_8200 + (*(struct Game_8003272C *)&g_Game).f_8200[i + 1].lo);
    }
    n = *(s32 *)(*(struct Game_8003272C *)&g_Game).f_8204;
    for (i = 0; i < n; i++) {
        func_80015D10(&D_800F4630[i * 0x10], (u32 *)(*(struct Game_8003272C *)&g_Game).f_8204 + (*(struct Game_8003272C *)&g_Game).f_8204[i + 1].lo);
    }
    return 0;
}

/* Points D_800B4D70's data (and g_SpikeAnimSets+0xA0..0xAC) at the sections of block `h`, whose
 * header holds word offsets. NULL clears it and resets Spike's idle timer (+0x148) and flags. */
void Spike_LoadModelData(Hdr_80032ADC_80032ADC *h) {
    u32 *v;
    if (h == 0) {
        D_800B4D70 = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_14A = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_14B = 0;
        ((struct Spike_80032ADC *)&g_Spike)->f_148 = 0;
        return;
    }
    v = (u32 *)h + h->f_4;
    D_800B4D70->f_0 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A0 = v;
    v = (u32 *)h + h->f_8;
    D_800B4D70->f_4 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A4 = v;
    v = (u32 *)h + h->f_C;
    D_800B4D70->f_8 = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_A8 = v;
    v = (u32 *)h + h->f_10;
    D_800B4D70->f_C = v;
    ((struct D4DE0_80032ADC *)&g_SpikeAnimSets)->f_AC = v;
    func_80015AC0(D_800B4D70->f_10, (u32 *)h + h->f_14);
    D_800B4D70->f_28 = (u32 *)h + h->f_18;
}

/* Stage start: reads the stage's spawn record, places Spike on the ground there
 * facing the given direction, resets his velocities and timers, and sets the camera position.
 */
s32 Spike_SpawnAtStageStart(void) {
    struct S_D_800EC350_80032BBC *d = (struct S_D_800EC350_80032BBC *)&g_Game;
    S_Spike_80032BBC_80032BBC *s;
    S32x9_80032BBC_80032BBC b;
    SVECTOR v;
    s32 x, z;
    func_80010C3C(d->f_8126, d->f_812A, &b);
    s = (S_Spike_80032BBC_80032BBC *)&g_Spike;
    d->f_8258.vx = b.v[3];
    d->f_8258.vy = b.v[4];
    d->f_8258.vz = b.v[5];
    d->f_8260.vx = b.v[0];
    d->f_8260.vy = b.v[1];
    d->f_8260.vz = b.v[2];
    x = b.v[0];
    z = b.v[2];
    s->f_24 = x;
    s->f_1C = x;
    s->f_2C = z;
    s->f_20 = z;
    s->f_1E = Floor_GetHeight(x, b.v[1], z);
    s->f_12C = s->f_1E;
    s->f_28 = s->f_1E;
    s->f_44 = 0x40;
    s->f_48 = 1;
    s->f_5C = 0;
    s->f_5E = 0;
    s->f_8C = 0;
    s->f_70 = 0;
    s->f_30 = 0;
    s->f_34 = 0;
    s->f_38 = 0;
    s->f_114 = 0;
    s->f_11C = 0;
    s->f_108 = 0;
    s->f_110 = 0;
    s->f_4A = 0x200;
    s->f_58 = -1;
    s->f_102 = 0;
    s->f_18 = d->f_81A0;
    v.vx = b.v[6];
    v.vy = b.v[7];
    v.vz = b.v[8];
    VectorNormalSS(&v, &v);
    s->f_6A = 0x1000;
    s->f_68 = 0;
    s->f_6C = 0;
    s->f_14 = &D_800E9C60;
    s->f_60.vx = v.vx;
    s->f_60.vy = v.vy;
    s->f_60.vz = v.vz;
    Collision_Set(1, &s->f_24, s);
    func_80047754();
    return 0;
}

/* Puts Spike on spawn point b of area id (func_80010C3C; area 0x3D always uses point 0): x/z from
 * the point, y from the floor height there (Floor_GetHeight), facing the point's direction
 * scaled by a and normalised. */
s32 Spike_PlaceAtSpawn(s32 a, s16 id, s32 b) {
    S32x9_80032D38 rec;
    SVEC_80032D38 dir;
    s16 h;
    s32 x;
    s32 y;
    s32 z;
    if (id == 0x3D) {
        b = 0;
    }
    ((s32 (*)(s32, s32, void *))func_80010C3C)(id, (s16)b, &rec);
    x = rec.w[0];
    z = rec.w[2];
    G_SPIKE_80032D38->f_24 = x;
    G_SPIKE_80032D38->f_1C = x;
    G_SPIKE_80032D38->f_2C = z;
    G_SPIKE_80032D38->f_20 = z;
    G_SPIKE_80032D38->f_12C = G_SPIKE_80032D38->f_1E = G_SPIKE_80032D38->f_28 = (s16)((s32 (*)(s32, s32, s32))Floor_GetHeight)(x, rec.w[1], z);
    dir.vx = (s16)a * rec.w[6];
    dir.vy = (s16)a * rec.w[7];
    dir.vz = (s16)a * rec.w[8];
    VectorNormalSS(&dir, &dir);
    G_SPIKE_80032D38->f_60 = dir.vx;
    G_SPIKE_80032D38->f_62 = dir.vy;
    G_SPIKE_80032D38->f_64 = dir.vz;
    return 0;
}
