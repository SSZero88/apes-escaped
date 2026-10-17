#include "common.h"
#include "m2c_macros.h"
#define V_11F6C ((struct S_D_800E3890_80011F6C *)&D_800E3890)
#define G (*(G_80011754_80011754 *)&g_Game)
#define CD ((Cd_800125B8_800125B8 *)&D_800E3890)
typedef struct { s32 w[9]; } S32x9;
typedef struct { u8 b[4]; } LOC_80011208;
typedef struct { LOC_80011208 loc; u32 sector; u8 pad8[0x10]; } S_Pos_80011208;
typedef struct { LOC_80011208 loc; s32 f_4; u32 f_8; } S_Args_80011208;
typedef struct { u16 f_0; u8 pad2[2]; s32 f_4; } S_File_80011208;
typedef struct { u8 b[4]; } LOC_800112E4;
typedef struct { LOC_800112E4 loc; u32 sector; u8 pad8[0x10]; } S_Pos_800112E4;
typedef struct { LOC_800112E4 loc; s32 f_4; u32 f_8; } S_Args_800112E4;
typedef struct { s32 w[15]; } S32x15_80011C1C;
typedef struct { u8 pad0[8]; void *f_8; u32 f_C; u8 pad10[0x2C]; } S_Out_80011C1C;
typedef struct { u8 b[4]; } LOC_800113CC;
typedef struct { LOC_800113CC loc; s32 size; } CdFileInfo;
typedef struct { LOC_800113CC loc; u32 sector; u8 pad8[0x10]; } S_Pos_800113CC;
typedef struct { LOC_800113CC loc; s32 f_4; u32 f_8; } S_Args_800113CC;
typedef struct { u8 b[4]; } LOC_800114D8;
typedef struct { LOC_800114D8 loc; u32 sector; u8 pad8[0x10]; } S_Pos_800114D8;
typedef struct { u16 f_0; u8 pad2[6]; u16 f_8; } S_File_800114D8_800114D8;
typedef struct { u8 pad0[0x1C]; void *f_1C; } StageInfo_80010B50_80010B50;
typedef struct { u8 com; u8 pad1[7]; s32 f_8; s32 f_C; u8 *result; u8 *done; u8 *param; } CdReq_80012A0C_80012A0C;
typedef struct { s16 x, y, w, h; } RECT_80011754_80011754;
typedef struct { u8 pad0_0[0x18]; u8 isbg; u8 pad19[0x5C - 0x19]; } DE_80011754_80011754;
typedef struct { DE_80011754_80011754 draw; u8 disp[0x14]; u32 ot[0x1000]; u8 pad[8]; } DB_80011754_80011754;
typedef struct { u32 frame; u8 pad4[8]; s32 cur; DB_80011754_80011754 db[2]; } G_80011754_80011754;
typedef struct { u8 pos[4]; u32 size; char name[16]; } CdlFILE_80011CF8_80011CF8;
typedef struct { u32 sector : 20; u32 size : 12; } CdEnt_80011CF8_80011CF8;
typedef struct { u8 com; u8 pad1[3]; s32 prm[3]; u8 *result; u8 *done; s32 *param; } CdReq_80012360_800125B8;
typedef struct { u32 f_0; u8 pad4[0x28]; s32 f_2C; u8 pad30[0xC]; s32 f_3C; u8 pad40[4]; u8 f_44[8]; s32 f_4C; s32 f_50; u8 pad54[8]; s32 f_5C; s32 f_60; u8 pad64[4]; s32 f_68; s32 f_6C; u8 f_70[4]; s16 f_74; s16 f_76; CdReq_80012360_800125B8 q[16]; } Cd_800125B8_800125B8;
typedef struct { s32 w[15]; } Exe_11A2C_80011A2C;

void func_80068D10(s32);
void DrawSync(s32);
void Sound_LoadBanks(s32);


extern s32 D_800A7BF8;
extern s32 D_800A7C20;
extern s32 *D_800A83E0;

extern struct S_D_800A81B0 { u16 *f_0; s16 f_4; s16 f_6; } D_800A81B0[];

M2C_UNK VSync(M2C_UNK);
void Cd_Update(void);

s32 Cd_ReadFile(s32 file, s32 dest);
void Cd_WaitQueue(s32 a);
extern struct S_D_800E3890 { s32 f_0; u8 pad4[0x70]; s16 f_74; s16 f_76; } D_800E3890;
s32 Cd_ProcessLoaded(s32 a, s32 b);
extern struct S_D_800EC350 { u8 pad0[0x8126]; s16 f_8126; u8 pad8128[0x10C]; S32x9 *unk8234; } g_Game;
s32 Stage_PairInSharedSet(s16 a, s16 b);
CdFileInfo *Cd_GetFileEntry();
s32 CdPosToInt(u8 *);
s32 Cd_QueueCommand(s32, void *, void *, s32);
struct S_D_800E3890_80011208 { u8 pad0[0x1C]; S_File_80011208 *f_1C; s32 f_20; u8 pad24[0x20]; u8 f_44[0x2C]; u8 f_70[4]; };
s32 func_8001231C(void);
struct S_D_800E3890_800112E4 { s32 f_0; u8 pad4[0x40]; u8 f_44[0x2C]; u8 f_70[4]; };
extern char D_800A41D0[];
void CdGetSector(void *, s32);
void CdReadyCallback(void *);
void bios_printf(const char *, ...);
struct S_D_800E3890_800128C8 { s32 f_0; u8 pad4[0x48]; u8 *f_4C; u8 pad50[8]; u8 *f_58; u8 pad5C[4]; s32 f_60; };
extern struct S_D_800B7650 { u8 pad0[0x10]; S32x15_80011C1C f_10; } D_800B7650;
s32 Cd_ReadFilePart(s32 file, s32 off, u32 size, s32 dest);
void Cd_WaitIdle();
LOC_800113CC *CdIntToPos(s32, LOC_800113CC *);
struct S_D_800E3890_800113CC { s32 f_0; u8 pad4[0x40]; u8 f_44[0x2C]; u8 f_70[4]; };
struct S_D_800E3890_800114D8 { s32 f_0; u8 pad4[0x14]; s32 f_18; S_File_800114D8_800114D8 *f_1C; s32 f_20; s32 f_24; u8 pad28[0x1C]; u8 f_44[0x2C]; u8 f_70[4]; };
struct S_D_800EC350_800114D8 { u8 pad_0[0x8126]; s16 f_8126; };
struct S_D_800A81B0_800114D8 { S_File_800114D8_800114D8 *f_0; s32 f_4; };
extern struct S_D_800A8530 { s32 f_0; s32 f_4; u8 f_8; u8 f_9; u8 f_A; u8 f_B; } D_800A8530[];
struct S_D_800E3890_80011F6C { u8 pad0[0x30]; s32 f_30; u8 pad34[0xC]; s16 f_40; u8 pad42[2]; u8 f_44[0x2C]; };
void func_80086248(s32);
u8 *func_8009628C(void);
extern void *D_800A8A50;
extern u8 g_Objects[][0xE4];
extern M2C_UNK D_800E68D0;
extern M2C_UNK D_800E68C0;
extern M2C_UNK g_GadgetState;
extern M2C_UNK g_Spike;
extern u8 g_Monkeys[8][0x250];
void *func_8008C000(s32);
void Mem_ZeroWords(void *, s32);
struct S_D_800A81B0_80010B50 { StageInfo_80010B50_80010B50 *f_0; s32 f_4; };

/* Stage load: allocates the 0x7800-byte stage work buffer (kept in D_800A8A50 and the stage's
 * info record), then zeroes the 8 monkeys, Spike, the 16 g_Objects, the camera (D_800E68D0),
 * D_800E68C0 and g_GadgetState. */
extern s32 D_800E38C4;
s32 CdControl(u8 com, u8 *param, u8 *result);
void Cd_ReadReady(u8 status);
struct S_D_800E3890_80012A0C_80012A0C { s32 f_0; u8 pad4[0x28]; s32 f_2C; u8 pad30[4]; s32 f_34; s32 f_38; s32 f_3C; u8 pad40[0xC]; s32 f_4C; s32 f_50; u8 pad54[4]; u8 *f_58; s32 f_5C; s32 f_60; s32 f_64; s32 f_68; s32 f_6C; u8 pad70[4]; s16 f_74; };
extern char D_800A40E0[];
extern char D_800A40F8[];
extern char D_800A4110[];
extern char D_800A4124[];
s32 CdSync(s32 mode, u8 *result);
s32 Cd_PlayXaTrack(s32 n);
struct S_D_800E3890_80012110_80012110 { s32 f_0; u8 pad4[0x28]; s32 f_2C; s32 f_30; s32 f_34; u8 pad38[8]; u16 f_40; };
extern s16 D_800A8528[];
extern char D_800A850C[];
s32 ClearImage(void* rect, u8 r, u8 g, u8 b);
s32 ResetGraph(s32 mode);
void DrawOTag(u32* p);
void* PutDrawEnv(void* env);
void* PutDispEnv(void* env);
void Gfx_InitDisplay(void);
s32 Cd_StartFileLoad(s32, s32);
s32 func_800116C0(void);
void Gfx_BeginFrame(void);
void func_8008DDB0(s32, s32);
void func_8008DDC8(char *);
struct S_D_800EC350_80011754 { u8 pad0[0x8126]; s16 f_8126; };
extern CdEnt_80011CF8_80011CF8 g_CdFileTable[];
extern char D_800A40D0[];
void *CdSearchFile(void *fp, char *name);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 CdControlB(u8 com, u8 *param, u8 *result);
extern char D_800A415C[];
extern char D_800A417C[];
extern char D_800A4194[];
extern char D_800A41B0[];
s32 Cd_PollStatus(void);
s32 CdLastCom(void);
s32 Cd_IssueRequest(CdReq_80012A0C_80012A0C *r);
struct Game_11A2C { u8 pad0[0x8120]; u16 f_8120; u8 pad8122[0x16]; u8 f_8138; u8 pad8139; u16 f_813A; };
extern s8 D_800A8508[];
u8 *Minigame_GetSaveData(s32 n);
s32 Exe_Load();
void func_800864DC(void);
void Sound_RestoreVolumes(void);
void System_Shutdown(void);
void func_8002F210(void);
void func_8002F900(Exe_11A2C_80011A2C *, s32, s32);
void SetGraphDebug(s32);
void System_Init(void);
s32 Boot_LoadingScreen(void);
struct g_Game_800115F4 { u8 pad0[0x812C]; u8 f_812C; };
#define G_GAME_800115F4 ((struct g_Game_800115F4 *)&g_Game)
extern u8 D_800A851C[];

s32 Stage_ResetActors(s32 stage) {
    void *p = func_8008C000(0x7800);
    s32 i;
    D_800A8A50 = p;
    ((struct S_D_800A81B0_80010B50 *)&D_800A81B0)[stage].f_0->f_1C = p;
    for (i = 0; i < 8; i++) {
        Mem_ZeroWords(g_Monkeys[i], 0x94);
    }
    Mem_ZeroWords(&g_Spike, 0x53);
    for (i = 0; i < 16; i++) {
        Mem_ZeroWords(g_Objects[i], 0x39);
    }
    Mem_ZeroWords(&D_800E68D0, 0x1F);
    Mem_ZeroWords(&D_800E68C0, 4);
    Mem_ZeroWords(&g_GadgetState, 0x2A);
    return 0;
}

s32 func_80010C3C(s32 a0, s32 i, S32x9 *out) {
    *out = g_Game.unk8234[i];
    return 0;
}

s16 func_80010CA4(s32 arg0) {
    return D_800A81B0[arg0].f_6;
}

s16 Stage_GetWorld(s32 arg0) {
    return D_800A81B0[arg0].f_4;
}

s32 func_80010CDC(s32 arg0) {
    if (arg0 == 0) {
        D_800A83E0 = &D_800A7BF8;
    } else {
        D_800A83E0 = &D_800A7C20;
    }
    return 0;
}

s32 Cd_GetAreaFileSector(s32 i) {
    u16 *p = D_800A81B0[i].f_0;
    u8 loc[0x18];
    s32 sec;
    if (Stage_PairInSharedSet(g_Game.f_8126, i) != 0) {
        sec = p[0];
    } else {
        sec = p[4];
    }
    Cd_GetFileEntry(loc, sec);
    return CdPosToInt(loc);
}

INCLUDE_ASM("asm/nonmatchings/game/80010B50_cd", Zone_CheckSpike);

s32 func_800110B0(void) {
    M2C_FIELD(&D_800E3890, s32 *, 0) = 0x50000;
    M2C_FIELD(&D_800E3890, s32 *, 4) = -1;
    M2C_FIELD(&D_800E3890, s32 *, 0x10) = -1;
    M2C_FIELD(&D_800E3890, s32 *, 0x14) = -1;
    M2C_FIELD(&D_800E3890, s32 *, 0x24) = -1;
    M2C_FIELD(&D_800E3890, s32 *, 8) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0xC) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0x1C) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0x20) = 0;
    M2C_FIELD(&D_800E3890, s16 *, 0x74) = 0;
    M2C_FIELD(&D_800E3890, s16 *, 0x76) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0x2C) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0x34) = 0;
    M2C_FIELD(&D_800E3890, u8 *, 0x70) = 0x80;
    return 0;
}

typedef struct { u16 file; u8 pad2[2]; s32 dest; } LoadRec_80011104;
typedef struct { u8 pad_0[0x1C]; LoadRec_80011104 *table; s32 index; s32 stage; } CdLoadState_80011104;
extern LoadRec_80011104 D_800A7120[]; /* general file loads: (disc file, destination) */
extern s32 D_800E38B8;
#define CDLOAD (*(CdLoadState_80011104 *)&D_800E3890)

/* Start an asynchronous file load. kind 0: entry n of the general load table D_800A7120;
   otherwise the load list of stage n (D_800A81B0[n].f_0). Remembers which list and entry
   are in progress in D_800E3890. */
s32 Cd_StartFileLoad(s32 kind, s32 n) {
    u16 file;
    LoadRec_80011104 *r;
    s32 dest;
    if (kind == 0) {
        r = D_800A7120;
        file = D_800A7120[n].file;
        dest = D_800A7120[n].dest;
        CDLOAD.table = r;
        CDLOAD.index = n;
        CDLOAD.stage = -1;
    } else {
        r = (LoadRec_80011104 *)D_800A81B0[n].f_0;
        file = r->file;
        dest = r->dest;
        CDLOAD.table = r;
        CDLOAD.index = 0;
        CDLOAD.stage = n;
    }
    D_800E38B8 = 0;
    Cd_ReadFile(file, dest);
    return 0;
}

s32 func_80011194(void *arg0) {
    if (M2C_FIELD(&D_800E3890, s32 *, 0) & 0x10000) {
        M2C_FIELD(&D_800E3890, s32 *, 0) = 0x50000;
        Cd_WaitQueue(0);
    }
    M2C_FIELD(&D_800E3890, void **, 0x1C) = arg0;
    M2C_FIELD(&D_800E3890, s32 *, 0x20) = 0;
    M2C_FIELD(&D_800E3890, s32 *, 0x24) = -1;
    Cd_ReadFile(M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, s32 *, 4));
    return 0;
}

s32 Cd_ReadCurrentFile(void) {
    S_Pos_80011208 pos;
    S_Args_80011208 args;
    Cd_GetFileEntry(&pos, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_1C[((struct S_D_800E3890_80011208 *)&D_800E3890)->f_20].f_0);
    args.loc = pos.loc;
    args.f_4 = ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_1C[((struct S_D_800E3890_80011208 *)&D_800E3890)->f_20].f_4;
    args.f_8 = pos.sector >> 11;
    Cd_QueueCommand(0xE, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_70, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(2, &args, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(1, 0, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(0x20, &args, ((struct S_D_800E3890_80011208 *)&D_800E3890)->f_44, 0);
    return 0;
}

s32 Cd_ReadFile(s32 file, s32 dest) {
    S_Pos_800112E4 pos;
    S_Args_800112E4 args;
    if (((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_0 & 0x10000) {
        func_8001231C();
        Cd_WaitQueue(0);
    }
    Cd_GetFileEntry(&pos, file);
    args.loc = pos.loc;
    args.f_4 = dest;
    args.f_8 = pos.sector >> 11;
    Cd_QueueCommand(0xE, ((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_70, ((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(2, &args, ((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(1, 0, ((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(0x20, &args, ((struct S_D_800E3890_800112E4 *)&D_800E3890)->f_44, 0);
    return 0;
}

s32 Cd_ReadFilePart(s32 file, s32 off, u32 size, s32 dest) {
    S_Pos_800113CC pos;
    S_Args_800113CC args;
    if (((struct S_D_800E3890_800113CC *)&D_800E3890)->f_0 & 0x10000) {
        func_8001231C();
        Cd_WaitQueue(0);
    }
    Cd_GetFileEntry(&pos, file);
    CdIntToPos(CdPosToInt(&pos.loc) + off, &pos.loc);
    args.loc = pos.loc;
    args.f_4 = dest;
    args.f_8 = size;
    Cd_QueueCommand(0xE, ((struct S_D_800E3890_800113CC *)&D_800E3890)->f_70, ((struct S_D_800E3890_800113CC *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(2, &args, ((struct S_D_800E3890_800113CC *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(1, 0, ((struct S_D_800E3890_800113CC *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(0x20, &args, ((struct S_D_800E3890_800113CC *)&D_800E3890)->f_44, 0);
    return 0;
}

s32 Cd_SeekAreaFile(s32 file) {
    struct S_D_800E3890_800114D8 *d = ((struct S_D_800E3890_800114D8 *)&D_800E3890);
    S_Pos_800114D8 pos;
    u8 mode[8];
    S_File_800114D8_800114D8 *f = ((struct S_D_800A81B0_800114D8 *)&D_800A81B0)[file].f_0;
    s32 sec;

    d->f_24 = file;
    d->f_1C = f;
    if (Stage_PairInSharedSet(((struct S_D_800EC350_800114D8 *)&g_Game)->f_8126, file)) {
        d->f_20 = 0;
        sec = f->f_0;
    } else {
        d->f_20 = 1;
        sec = f->f_8;
    }
    Cd_GetFileEntry(&pos, sec);
    mode[0] = 0x80;
    ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_18 = CdPosToInt(&pos.loc);
    Cd_QueueCommand(0xE, mode, ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(2, &pos, ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(1, 0, ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(0x15, 0, ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_44, 0);
    Cd_QueueCommand(1, 0, ((struct S_D_800E3890_800114D8 *)&D_800E3890)->f_44, 0);
    return 0;
}

s32 Stage_PairInSharedSet(s16 a, s16 b) {
    s32 i;
    s32 found;
    if (G_GAME_800115F4->f_812C == 11) {
        return 0;
    }
    found = 0;
    for (i = 0; D_800A851C[i] != 0xFF; i++) {
        if (D_800A851C[i] == a) {
            found++;
            break;
        }
    }
    if (found == 0) {
        return 0;
    }
    for (i = 0; D_800A851C[i] != 0xFF; i++) {
        if (D_800A851C[i] == b) {
            return 1;
        }
    }
    return 0;
}

s32 func_800116C0(void) {
    s32 temp_v0_2;
    void *temp_v0;
    void *temp_v1;

    if (M2C_FIELD(&D_800E3890, s32 *, 0) == 0) {
        temp_v0 = (M2C_FIELD(&D_800E3890, s32 *, 0x20) * 8) + M2C_FIELD(&D_800E3890, s32 *, 0x1C);
        Cd_ProcessLoaded(M2C_FIELD(temp_v0, s16 *, 2), M2C_FIELD(temp_v0, s32 *, 4));
        temp_v0_2 = M2C_FIELD(&D_800E3890, s32 *, 0x20) + 1;
        M2C_FIELD(&D_800E3890, s32 *, 0x20) = temp_v0_2;
        temp_v1 = (temp_v0_2 * 8) + M2C_FIELD(&D_800E3890, s32 *, 0x1C);
        if (M2C_FIELD(temp_v1, s16 *, 2) < 0) {
            M2C_FIELD(&D_800E3890, s32 *, 0x54) = (s32) M2C_FIELD(&D_800E3890, s32 *, 0x4C);
            return -1;
        }
        Cd_ReadFile(M2C_FIELD(temp_v1, u16 *, 0), M2C_FIELD(temp_v1, s32 *, 4));
        goto block_4;
    }
block_4:
    return 0;
}

/* Startup loading screen: clears both display buffers, loads file 6 to 0x80154000 and hands it
 * to func_80068D10 (font/graphics), then streams the files listed in D_800A8528 ({1, 7, 12}, -1
 * terminated) one by one while "Now Loading..." (D_800A850C in the game's font codes) blinks at
 * 110,180 (shown when frame % 40 >= 21). Returns 0 when the list is done. */
s32 Boot_LoadingScreen(void) {
    RECT_80011754_80011754 r;
    s32 i;

    r.x = 0;
    r.y = 0;
    r.w = 0x180;
    r.h = 0x100;
    ClearImage(&r, 0, 0, 0);
    r.x = 0;
    r.y = 0x100;
    r.w = 0x180;
    r.h = 0x100;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    Cd_ReadFile(6, 0x80154000);
    Cd_WaitIdle(0);
    func_80068D10(0x80154000);
    DrawSync(0);
    Gfx_InitDisplay();
    ResetGraph(1);
    G.db[1].draw.isbg = 1;
    G.db[0].draw.isbg = 1;
    G.cur = 0;
    i = 0;
    Cd_StartFileLoad(0, D_800A8528[i]);
    while (1) {
        Gfx_BeginFrame();
        if (func_800116C0() < 0) {
            i++;
            if (D_800A8528[i] < 0) {
                return 0;
            }
            Cd_StartFileLoad(0, D_800A8528[i]);
        }
        if (G.frame % 40 >= 21) {
            func_8008DDB0(0x6E, 0xB4);
            func_8008DDC8(D_800A850C);
        }
        Cd_Update();
        DrawSync(0);
        VSync(0);
        G.frame++;
        PutDispEnv(G.db[G.cur].disp);
        PutDrawEnv(&G.db[G.cur].draw);
        DrawOTag(&G.db[G.cur].ot[0xFFF]);
    }
}

s32 Cd_ProcessLoaded(s32 a, s32 b) {
    switch (a) {
    case 1:
        func_80068D10(b);
        DrawSync(0);
        break;
    case 2:
        Sound_LoadBanks(2);
        break;
    case 3:
        Sound_LoadBanks(1);
        break;
    case 4:
        Sound_LoadBanks(3);
        break;
    }
    return 0;
}

u8 *Minigame_GetSaveData(s32 n) {
    return func_8009628C() + (n * 0x84 + 0x168);
}

s32 Minigame_Run(s32 n) {
    u16 *sc = (u16 *)0x1F800000;
    u16 *p;
    s16 i;
    Exe_11A2C_80011A2C exe;

    p = (u16 *)Minigame_GetSaveData(n);
    sc[0] = 0;
    if ((*(struct Game_11A2C *)&g_Game).f_813A != 0) {
        sc[0] = 1;
    }
    if ((*(struct Game_11A2C *)&g_Game).f_8138 != 0) {
        sc[0] |= 2;
    }
    for (i = 0; i < 0x40; i++) {
        sc[i + 1] = p[i];
    }
    func_800864DC();
    Exe_Load(D_800A8508[n], &exe);
    System_Shutdown();
    exe.w[8] = 0x801EFFF0;
    exe.w[9] = 0;
    func_8002F210();
    func_8002F900(&exe, 1, 0);
    ResetGraph(0);
    SetGraphDebug(0);
    System_Init();
    if (sc[0] & 1) {
        (*(struct Game_11A2C *)&g_Game).f_813A = 1;
    } else {
        (*(struct Game_11A2C *)&g_Game).f_813A = 0;
    }
    if (sc[0] & 2) {
        (*(struct Game_11A2C *)&g_Game).f_8138 = 1;
    } else {
        (*(struct Game_11A2C *)&g_Game).f_8138 = 0;
    }
    p = (u16 *)Minigame_GetSaveData(n);
    for (i = 0; i < 0x40; i++) {
        p[i] = sc[i + 1];
    }
    Sound_RestoreVolumes();
    Boot_LoadingScreen();
    (*(struct Game_11A2C *)&g_Game).f_8120 = 3;
    return 0;
}

s32 Exe_Load(a, out)
unsigned short a;
S32x15_80011C1C *out;
{
  Cd_ReadFilePart((s8)a, 0, 1, (s32)&D_800B7650);
  Cd_WaitIdle(0);
  *out = D_800B7650.f_10;
  Cd_ReadFilePart((s8)a, 1, (((S_Out_80011C1C *) out)->f_C + 0x7FF) >> 11, (s32)((S_Out_80011C1C *) out)->f_8);
  Cd_WaitIdle(0);
  return 0;
}

/* CD setup at boot: locates the data archive (D_800A40D0, "\KKIIDDZZ.HED;1"), reads its first sector - a table of
 * 0x1C0 entries {sector:20, size:12} relative to the archive - into g_CdFileTable and makes the
 * sectors absolute. The XA music tracks (D_800A8530 entries 4..0x39) get their start sectors from
 * the XA files 0x1C5, 0x1C4, 0x1C1, 0x1C0, 0x1C2, 0x1C3. Then sets mode 0xC8 and demutes. */
s32 Cd_InitFileTable(void) {
    CdlFILE_80011CF8_80011CF8 fp;
    u8 mode[8];
    u8 res[8];
    s32 base;
    s32 i;

    while (CdSearchFile(&fp, D_800A40D0) == 0) {
    }
    base = CdPosToInt(&fp);
    while (CdControl(2, (u8 *)&fp, 0) == 0) {
    }
    while (CdRead(1, (u32 *)g_CdFileTable, 0x80) == 0) {
    }
    CdReadSync(0, res);
    for (i = 0; i < 0x1C0; i++) {
        g_CdFileTable[i].sector += 1 + base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C5);
    base = CdPosToInt(&fp);
    for (i = 4; i < 0x10; i++) {
        D_800A8530[i].f_0 = base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C4);
    base = CdPosToInt(&fp);
    for (i = 0x10; i < 0x18; i++) {
        D_800A8530[i].f_0 = base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C1);
    base = CdPosToInt(&fp);
    for (i = 0x18; i < 0x1F; i++) {
        D_800A8530[i].f_0 = base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C0);
    base = CdPosToInt(&fp);
    for (i = 0x1F; i < 0x2B; i++) {
        D_800A8530[i].f_0 = base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C2);
    base = CdPosToInt(&fp);
    for (i = 0x2B; i < 0x33; i++) {
        D_800A8530[i].f_0 = base;
    }
    Cd_GetFileEntry((u8 *)&fp, 0x1C3);
    base = CdPosToInt(&fp);
    for (i = 0x33; i < 0x3A; i++) {
        D_800A8530[i].f_0 = base;
    }
    mode[0] = 0xC8;
    while (CdControlB(0xE, mode, 0) == 0) {
    }
    while (CdControlB(0xC, 0, 0) == 0) {
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A40D0);


/* Starts XA (streamed) music track `n`: sets the volume mode, the XA file/channel
 * filter and read mode, seeks to the track and starts reading.
 */
s32 Cd_PlayXaTrack(s32 n) {
    u8 filt[2];
    u8 pos[4];
    u8 mode[1];
    s32 v;
    switch (D_800A8530[n].f_A & 0xC) {
    case 4:
        v = 0;
        break;
    case 8:
        v = 1;
        break;
    default:
        v = -1;
        break;
    }
    func_80086248(v);
    Cd_QueueCommand(0xB, 0, V_11F6C->f_44, 0);
    filt[0] = D_800A8530[n].f_8;
    filt[1] = D_800A8530[n].f_9;
    Cd_QueueCommand(0xD, filt, V_11F6C->f_44, 0);
    mode[0] = 0x48;
    if (D_800A8530[n].f_A & 1) {
        mode[0] = 0xC8;
    }
    Cd_QueueCommand(0xE, mode, V_11F6C->f_44, 0);
    CdIntToPos(D_800A8530[n].f_0, pos);
    Cd_QueueCommand(0xC, 0, V_11F6C->f_44, 0);
    Cd_QueueCommand(1, 0, V_11F6C->f_44, 0);
    Cd_QueueCommand(0x1B, pos, V_11F6C->f_44, 0);
    Cd_QueueCommand(0xB, 0, V_11F6C->f_44, 0);
    Cd_QueueCommand(9, 0, V_11F6C->f_44, 0);
    V_11F6C->f_40 = n;
    V_11F6C->f_30 = D_800A8530[n].f_0;
    return 0;
}

/* Polled once per frame (Cd_Update). After a completed command, unless a delay (f_34) is
 * counting down, it either checks the drive status (every 10th tick of f_2C) or reads the play
 * position (CdlGetlocP) into f_30; once the current XA track D_800A8530[f_40] has played past its
 * length it is restarted if it loops (flag 2) and the state becomes 0x50000. On a disk error the
 * looping track is restarted too (state 0xF0000). Returns 0. */
s32 Cd_PollStatus(void) {
    u8 res[8];
    struct S_D_800E3890_80012110_80012110 *d;
    s32 pos;
    s32 st;

    switch (st = CdSync(1, 0)) {
    case 2:
        d = ((struct S_D_800E3890_80012110_80012110 *)&D_800E3890);
        if (d->f_34 == 0) {
        if (d->f_2C % 10 != 0) {
            if (CdControl(0x11, 0, res) != 0) {
                pos = CdPosToInt(&res[5]);
                d->f_30 = pos;
                if (D_800A8530[d->f_40].f_4 < pos - D_800A8530[d->f_40].f_0) {
                    if (D_800A8530[d->f_40].f_A & 2) {
                        Cd_PlayXaTrack(d->f_40);
                    }
                    ((struct S_D_800E3890_80012110_80012110 *)&D_800E3890)->f_0 = 0x50000;
                }
            } else {
                bios_printf(D_800A40E0);
            }
        } else {
            CdControl(1, 0, res);
            if (res[0] & 5) {
                bios_printf(D_800A40F8, res[0]);
            }
        }
        } else {
            d->f_34--;
        }
        break;
    case 0:
        bios_printf(D_800A4110);
        break;
    case 5:
        CdControl(1, 0, res);
        bios_printf(D_800A4124, res[0]);
        if (((struct S_D_800E3890_80012110_80012110 *)&D_800E3890)->f_0 & 0x10000) {
            ((struct S_D_800E3890_80012110_80012110 *)&D_800E3890)->f_0 = 0xF0000;
            if (D_800A8530[((struct S_D_800E3890_80012110_80012110 *)&D_800E3890)->f_40].f_A & 2) {
                Cd_PlayXaTrack(((struct S_D_800E3890_80012110_80012110 *)&D_800E3890)->f_40);
            }
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A40E0);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A40F8);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A4110);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A4124);


s32 func_8001231C(void) {
    if (D_800E3890.f_0 & 0x10000) {
        D_800E3890.f_0 = 0x50000;
        Cd_WaitQueue(0);
    }
    return 0;
}

s32 func_80012358(void) {
    return 0;
}

typedef struct { u8 cmd; u8 pad1[3]; u32 param[3]; s32 f_10; u8 *result; u32 *pparam; } CdCmd;
typedef struct { s32 f_0; u8 pad4[0x70]; s16 tail; s16 head; CdCmd q[16]; } CdState;
#define CQ ((CdState *)&D_800E3890)
s32 Cd_QueueCommand_(u8 cmd, u32 *params, s32 buf, u8 *result) asm("Cd_QueueCommand");
extern char D_800A4140[];
/* Cd_QueueCommand: append a CD command to the 16-entry ring at D_800E3890+0x78: cmd, its params
 * (3 words for cmd 0x20, else 1; none if params is 0), a response buffer and a done-flag pointer.
 * When the ring is full it prints a warning and issues the oldest request until that succeeds.
 * Clears *result and arms the CD timer (f_0 = 0x50000) if it is idle. */
s32 Cd_QueueCommand_(u8 cmd, u32 *params, s32 buf, u8 *result) {
    if ((CQ->head + 1) % 16 == CQ->tail) {
        CdCmd *c = &CQ->q[(CQ->head + 1) % 16];
        bios_printf(D_800A4140);
        while (Cd_IssueRequest((void *)c) == 0) {
        }
    }
    CQ->q[CQ->head].cmd = cmd;
    if (params == 0) {
        CQ->q[CQ->head].pparam = 0;
    } else {
        CQ->q[CQ->head].pparam = CQ->q[CQ->head].param;
        *CQ->q[CQ->head].param = params[0];
        if (cmd == 0x20) {
            *(CQ->q[CQ->head].param + 1) = params[1];
            *(CQ->q[CQ->head].param + 2) = params[2];
        }
    }
    CQ->q[CQ->head].f_10 = buf;
    CQ->q[CQ->head].result = result;
    CQ->head = (CQ->head + 1) % 16;
    if (result != 0) {
        *result = 0;
    }
    if (CQ->f_0 == 0) {
        CQ->f_0 = 0x50000;
    }
    return 1;
}


INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A4140);


void Cd_WaitIdle()
{
    if (D_800E3890.f_0 != 0) {
        do {
            Cd_Update();
            VSync(2);
        } while (D_800E3890.f_0 != 0);
    }
}

/* Per-frame CD driver, a state machine in D_800E3890.f_0: 0x10000 = XA music playing (poll the
 * position every 5th frame), 0x40000 = data read in progress (restart it after 600 frames without
 * an answer), 0xE0000 = restart the current read, 0xF0000 = recover from an error (status, standby,
 * mode), anything else = wait for the last command and then issue the next queued request
 * (ring f_74..f_76) or go idle; a disk error moves to 0xE0000 / 0xF0000. */
void Cd_Update(void) {
    Cd_800125B8_800125B8 *d = CD;
    CdReq_80012360_800125B8 *r;
    s32 res;

    d->f_2C++;
    switch (CD->f_0) {
    case 0x10000:
        if (d->f_2C % 5 == 0) {
            Cd_PollStatus();
        }
        break;
    case 0x40000:
        if (VSync(-1) - d->f_3C >= 601) {
            CD->f_0 = 0xE0000;
            bios_printf(D_800A415C);
            CdReadyCallback(0);
        }
        break;
    case 0xE0000:
        while (CdControlB(0xE, CD->f_70, CD->f_44) == 0) {
        }
        CD->f_4C = CD->f_50;
        r = &CD->q[CD->f_74];
        CD->f_60 = CD->f_5C;
        if (CdControlB(6, (u8 *)r->param, r->result) == 1) {
            CD->f_3C = VSync(-1);
            CD->f_0 = 0x40000;
            CdReadyCallback(Cd_ReadReady);
            bios_printf(D_800A417C);
        }
        break;
    case 0xF0000:
        if (CdSync(1, 0) == 2 && CdLastCom() == 1) {
            if (d->f_44[0] & 0x10) {
                CdControl(1, 0, CD->f_44);
            } else if (d->f_44[0] & 2) {
                CD->f_0 = 0x50000;
            } else {
                while (CdControlB(7, 0, CD->f_44) == 0) {
                }
                while (CdControlB(0xE, CD->f_70, CD->f_44) == 0) {
                }
            }
        } else {
            CdControl(1, 0, CD->f_44);
        }
        break;
    default:
        switch (CdSync(1, 0)) {
        case 2:
            if (CD->f_74 != CD->f_76) {
                Cd_IssueRequest((CdReq_80012A0C_80012A0C *)&CD->q[CD->f_74]);
            } else {
                if (CD->f_0 == 0x20000) {
                    CD->f_68 = CD->f_6C;
                }
                CD->f_0 = 0;
            }
            break;
        case 5:
            bios_printf(D_800A4194);
            if (CD->f_0 == 0x40000) {
                CD->f_0 = 0xE0000;
                bios_printf(D_800A41B0);
            } else {
                CD->f_0 = 0xF0000;
                CdControl(1, 0, CD->f_44);
            }
            break;
        }
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A415C);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A417C);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A4194);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A41B0);


void Cd_ReadReady(u8 status)
{
  int new_var;
  if (status == 1)
  {
    CdGetSector(((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_4C, 0x200);
    ((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_4C += 0x800;
    ((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_60--;
    if (((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_60 <= 0)
    {
      CdReadyCallback(0);
      new_var = ((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_58 != 0;
      if (new_var)
      {
        new_var = status;
        *((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_58 = new_var;
      }
      ((struct S_D_800E3890_800128C8 *)&D_800E3890)->f_0 = 0x50000;
    }
  }
  else
  {
    bios_printf(D_800A41D0);
  }
}

INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A41D0);


void Cd_WaitQueue(s32 a) {
    if (D_800E3890.f_74 == D_800E3890.f_76) {
        return;
    }
    if (a == -1) {
        D_800E3890.f_74 = D_800E3890.f_76;
        return;
    }
    if (D_800E3890.f_0 == 0) {
        return;
    }
    do {
        Cd_Update();
        if (D_800E3890.f_0 & 0x10000) {
            D_800E3890.f_0 = 0x50000;
        }
        VSync(2);
    } while (D_800E3890.f_0 != 0);
}

/* Issue one queued CD request. Command 0x20 is the game's data read: it records the buffer and
 * length in the CD state block (D_800E3890), starts CdlReadN with Cd_ReadReady as the ready
 * callback and turns the request into CdlPause (9). Other commands go straight to CdControl and set
 * the expected state (seek, read, pause, ...). Marks *done, advances the ring index f_74 (mod 16),
 * stamps the VSync count. Returns 1 if CdControl accepted the command, else 0. */
s32 Cd_IssueRequest(CdReq_80012A0C_80012A0C *r) {
    struct S_D_800E3890_80012A0C_80012A0C *d;
    if (r->com == 0x20) {
        d = ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890);
        d->f_50 = d->f_4C = r->f_8;
        d->f_5C = d->f_60 = r->f_C;
        d->f_58 = r->done;
        if (CdControl(6, r->param, r->result) == 1) {
            CdReadyCallback(Cd_ReadReady);
            ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_0 = 0x40000;
            r->com = 9;
            d->f_3C = VSync(-1);
            return 1;
        }
    } else {
        D_800E38C4 = 0;
        if (CdControl(r->com, r->param, r->result) == 1) {
            switch (r->com) {
            case 2:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_68 = -1;
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_6C = CdPosToInt(r->param);
                break;
            case 6:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_0 = 0x40000;
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_34 = 2;
                break;
            case 27:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_0 = 0x10000;
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_34 = 0x14;
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_2C = 0;
                break;
            case 9:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_0 = 0x50000;
                break;
            case 21:
            case 22:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_0 = 0x20000;
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_34 = 2;
                break;
            case 14:
                ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_38 = ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890)->f_74;
                break;
            }
            d = ((struct S_D_800E3890_80012A0C_80012A0C *)&D_800E3890);
            d->f_64 = r->com;
            if (r->done != 0) {
                *r->done = 1;
            }
            d->f_74 = (d->f_74 + 1) % 16;
            d->f_3C = VSync(-1);
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", jtbl_800A41F0_pad);
INCLUDE_RODATA("asm/nonmatchings/game/80010B50_cd", D_800A4260);


/* Fill out the CdlLOC and byte size of disc file `file`: each table entry packs
   the start sector in the low 20 bits and the length in 2048-byte sectors above. */
CdFileInfo *Cd_GetFileEntry(CdFileInfo *out, s32 file) {
    CdIntToPos(((u32 *)g_CdFileTable)[file] & 0xFFFFF, &out->loc);
    out->size = (((u32 *)g_CdFileTable)[file] >> 20) << 11;
    return out;
}
