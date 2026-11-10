#include "common.h"
#include "m2c_macros.h"

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern Rect_80136000 D_80136A80;
extern s32 SoundTest_Stage;
extern s32 SoundTest_Page;
extern s32 SoundTest_MenuRow;
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; s16 f_8120; u8 pad8122[0x198]; u16 f_82BA; } g_Game_80136000 asm("g_Game");
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
s32 ClearImage(void *rect, u8 r, u8 g, u8 b);
void DrawSync(s32);
s32 VSync(s32 mode);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void DebugFont_Init(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 SoundTest_Main(void) {
    Rect_80136000 r;

    r = D_80136A80;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    g_Game_80136000.db[1].env[0x18] = 1;
    g_Game_80136000.db[0].env[0x18] = 1;
    SoundTest_Stage = 0;
    g_Game_80136000.cur = 0;
    SoundTest_Page = 0;
    SoundTest_MenuRow = 0;
    g_Game_80136000.f_82BA |= 2;
    while (func_8001325C(2), Gfx_BeginFrame(), DebugFont_Init(), SoundTest_Update() >= 0) {
        DrawSync(0);
        VSync(0);
        g_Game_80136000.frame++;
        PutDispEnv(&g_Game_80136000.db[g_Game_80136000.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136000.db[g_Game_80136000.cur].env);
        DrawOTag(&g_Game_80136000.db[g_Game_80136000.cur].ot[0xFFF]);
    }
    g_Game_80136000.f_8120 = 3;
    return 0;
}

extern s32 SoundTest_Page;
s32 SoundTest_UpdateMainMenu(void);

s32 SoundTest_Update(void)
{
  int new_var;
  switch (SoundTest_Page)
  {
    case 0:
      new_var = SoundTest_UpdateMainMenu() < 0;
      if (new_var)
    {
      new_var = 1;
      return -new_var;
    }
      return 0;

    case 1:
      SoundTest_UpdateCommonTest();
      return 0;

    case 2:
      SoundTest_UpdateSightTest();
      return 0;

  }

  return 0;
}

typedef struct { unsigned addr : 24; unsigned len : 8; } Tag_80136244;
typedef struct { u8 name[0x10]; u8 s10[8]; u16 f18; } Song_80136244;
typedef struct { u8 tag[3]; u8 len; u8 r0, g0, b0, code; s16 x0, y0; u8 r1, g1, b1, pad1; s16 x1, y1; u8 r2, g2, b2, pad2; s16 x2, y2; u8 r3, g3, b3, pad3; s16 x3, y3; } PolyG4_80136244;
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; u8 pad164[4]; u32 repeat; } g_Pad_80136244 asm("g_Pad");
extern u8 D_80136AA0[];
extern u8 D_80136AB8[];
extern s32 SoundTest_MenuLabels[];
extern Song_80136244 SoundTest_Stages[];
extern s32 SoundTest_SoundId;
extern s32 SoundTest_BgmMuted;
extern u16 SoundTest_BankFile;
void DebugFont_Locate(s32, s32);
void DebugFont_PrintfAlways(u8 *, ...);
s32 Sound_PlayFixed(s32);
void Cd_StartLoadList(void *);
s32 Cd_PollLoadList(void);
void Cd_Update(void);

s32 SoundTest_UpdateMainMenu(void) {
    s32 i;
    s32 y;
    u32 b;

    DebugFont_Locate(0x64, 0x28);
    DebugFont_PrintfAlways(D_80136AA0);
    for (i = 0; i < 3; i++) {
        DebugFont_Locate(0xA0, 0x64 + i * 0x14);
        DebugFont_PrintfAlways(D_80136AB8, SoundTest_MenuLabels[i]);
    }
    DebugFont_Locate(0xBE, 0x96);
    DebugFont_PrintfAlways(D_80136AB8, SoundTest_Stages[SoundTest_Stage].name);
    DebugFont_Locate(0x104, 0x96);
    DebugFont_PrintfAlways(D_80136AB8, SoundTest_Stages[SoundTest_Stage].s10);
    ((PolyG4_80136244 *)g_Game_80136000.prim)->len = 8;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->code = 0x38;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->code |= 2;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->x0 = 0x90;
    y = SoundTest_MenuRow * 0x14;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->y0 = y + 0x66;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->x1 = 0x108;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->y1 = y + 0x66;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->x2 = 0x90;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->y2 = y + 0x6D;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->x3 = 0x108;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->y3 = y + 0x6D;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->r0 = 0xF5;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->g0 = 0xDC;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->b0 = 0xC8;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->r1 = 0xE6;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->g1 = 0x46;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->b1 = 0x28;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->r2 = 0xC4;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->g2 = 0x46;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->b2 = 0x3C;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->r3 = 0x5F;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->g3 = 0x0A;
    ((PolyG4_80136244 *)g_Game_80136000.prim)->b3 = 0x08;
    ((Tag_80136244 *)g_Game_80136000.prim)->addr = ((Tag_80136244 *)g_Game_80136000.db[g_Game_80136000.cur].ot)->addr;
    ((Tag_80136244 *)g_Game_80136000.db[g_Game_80136000.cur].ot)->addr = (u32)g_Game_80136000.prim;
    g_Game_80136000.prim += sizeof(PolyG4_80136244);
    if (g_Pad_80136244.held & g_Pad_80136244.pressed & 0x800) {
        Sound_PlayFixed(2);
        if (SoundTest_MenuRow == 0) {
            return -1;
        }
        if (SoundTest_MenuRow == 1) {
            SoundTest_Page = 1;
            SoundTest_SoundId = 0;
        } else {
            SoundTest_Page = 2;
            SoundTest_SoundId = 0xAC;
            SoundTest_BgmMuted = 0;
            SoundTest_BankFile = SoundTest_Stages[SoundTest_Stage].f18;
            Cd_StartLoadList(&SoundTest_BankFile);
            while (Cd_PollLoadList() >= 0) {
                Cd_Update();
            }
            return 0;
        }
    } else {
        b = g_Pad_80136244.repeat;
        if (b & 0x1000) {
            Sound_PlayFixed(0);
            if (--SoundTest_MenuRow < 0) {
                SoundTest_MenuRow = 2;
            }
        } else if (b & 0x4000) {
            Sound_PlayFixed(0);
            if (++SoundTest_MenuRow >= 3) {
                SoundTest_MenuRow = 0;
            }
        } else if (b & 0x8000) {
            Sound_PlayFixed(0);
            if (--SoundTest_Stage < 0) {
                SoundTest_Stage = 0x2A;
            }
        } else if (b & 0x2000) {
            Sound_PlayFixed(0);
            if (++SoundTest_Stage >= 0x2B) {
                SoundTest_Stage = 0;
            }
        }
    }
    return 0;
}

/* returns s32 0: change the file prototype at the top of 387_sound_test.c to s32 SoundTest_UpdateCommonTest(void); */
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; u8 pad164[4]; u32 repeat; } g_Pad_80136698 asm("g_Pad");
extern u8 D_80136ABC[];
extern u8 D_80136ACC[];
extern u8 D_80136AE4[];
extern u8 D_80136AF8[];
extern s32 SoundTest_SoundId;
extern s32 D_80136FD0;
extern s32 D_80136FD4;
extern s32 SoundTest_CommonVoice;
void DebugFont_SetPos(s32, s32);
void DebugFont_Printf(u8 *, ...);
s32 Sound_PlayFixed(s32);
void func_800A342C(s32);
s32 Sound_GetTableEntry(s32, s32 *, s32 *);

s32 SoundTest_UpdateCommonTest(void) {
    u32 b;

    DebugFont_SetPos(0x82, 0x46);
    DebugFont_Printf(D_80136ABC);
    DebugFont_SetPos(0x82, 0xC4);
    DebugFont_Printf(D_80136ACC);
    DebugFont_SetPos(0x82, 0xD2);
    DebugFont_Printf(D_80136AE4);
    if (g_Pad_80136698.held & g_Pad_80136698.pressed & PAD_START) {
        Sound_PlayFixed(2);
        SoundTest_Page = 0;
        return 0;
    }
    b = g_Pad_80136698.repeat;
    if (b & PAD_UP) {
        Sound_PlayFixed(0);
        if (--SoundTest_SoundId < 0) {
            SoundTest_SoundId = 0xAB;
        }
    } else if (b & PAD_DOWN) {
        Sound_PlayFixed(0);
        if (++SoundTest_SoundId >= 0xAC) {
            SoundTest_SoundId = 0;
        }
    } else if (b & PAD_SQUARE) {
        SoundTest_CommonVoice = Sound_PlayFixed(SoundTest_SoundId);
    } else if (b & PAD_CIRCLE) {
        SoundTest_CommonVoice = Sound_PlayFixed(SoundTest_SoundId);
    } else if (b & PAD_SELECT) {
        func_800A342C(0);
    }
    Sound_GetTableEntry(SoundTest_SoundId, &D_80136FD0, &D_80136FD4);
    DebugFont_SetPos(0x82, 0x82);
    DebugFont_Printf(D_80136AF8, SoundTest_SoundId, D_80136FD0, D_80136FD4, SoundTest_CommonVoice);
    return 0;
}

/* returns s32 0: change the file prototype at the top of 387_sound_test.c to s32 SoundTest_UpdateSightTest(void); needs SoundTest_UpdateCommonTest's draft (decls of DebugFont_SetPos, DebugFont_Printf, Sound_PlayFixed, func_800A342C, Sound_GetTableEntry) merged above */
extern struct { u8 pad0[0x158]; u32 held; u8 pad15C[4]; u32 pressed; u8 pad164[4]; u32 repeat; } g_Pad_8013684C asm("g_Pad");
extern u8 D_80136B18[];
extern u8 D_80136B28[];
extern s32 SoundTest_BgmMuted;
void Sound_SetVolumes(s32, s32);
void Sound_UnloadBanks(s32);
extern u8 D_80136ACC_684C[] asm("D_80136ACC");
extern u8 D_80136AE4_684C[] asm("D_80136AE4");
extern u8 D_80136AF8_684C[] asm("D_80136AF8");
extern s32 D_80136B44_684C asm("SoundTest_SoundId");
extern s32 D_80136FDC;
extern s32 D_80136FE0;
extern s32 SoundTest_SightVoice;

s32 SoundTest_UpdateSightTest(void) {
    u32 b;

    DebugFont_SetPos(0x82, 0x46);
    DebugFont_Printf(D_80136B18);
    DebugFont_SetPos(0x82, 0xB4);
    DebugFont_Printf(D_80136B28);
    DebugFont_SetPos(0x82, 0xC4);
    DebugFont_Printf(D_80136ACC_684C);
    DebugFont_SetPos(0x82, 0xD2);
    DebugFont_Printf(D_80136AE4_684C);
    if (g_Pad_8013684C.held & g_Pad_8013684C.pressed & PAD_START) {
        Sound_PlayFixed(2);
        SoundTest_Page = 0;
        Sound_UnloadBanks(1);
        return 0;
    }
    b = g_Pad_8013684C.repeat;
    if (b & PAD_UP) {
        Sound_PlayFixed(0);
        if (--D_80136B44_684C < 0xAC) {
            D_80136B44_684C = 0xC4;
        }
    } else if (b & PAD_DOWN) {
        Sound_PlayFixed(0);
        if (++D_80136B44_684C >= 0xC5) {
            D_80136B44_684C = 0xAC;
        }
    } else if (b & PAD_R1) {
        if (SoundTest_BgmMuted) {
            Sound_SetVolumes(0x7F, 0x30);
        } else {
            Sound_SetVolumes(0x7F, 0);
        }
        SoundTest_BgmMuted = !SoundTest_BgmMuted;
    } else if (b & PAD_SQUARE) {
        SoundTest_SightVoice = Sound_PlayFixed(D_80136B44_684C);
    } else if (b & PAD_CIRCLE) {
        SoundTest_SightVoice = Sound_PlayFixed(D_80136B44_684C);
    } else if (b & PAD_SELECT) {
        func_800A342C(0);
    }
    Sound_GetTableEntry(D_80136B44_684C, &D_80136FDC, &D_80136FE0);
    DebugFont_SetPos(0x82, 0x82);
    DebugFont_Printf(D_80136AF8_684C, D_80136B44_684C, D_80136FDC, D_80136FE0, SoundTest_SightVoice);
    return 0;
}
