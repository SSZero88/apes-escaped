#include "common.h"
#include "m2c_macros.h"
#include "common.h"
#include "common.h"
#include "common.h"
#include "common.h"
typedef struct { u8 pad0[0x14]; u16 unk14; u16 unk16; } S_F75C0;
typedef struct { u8 pad0[0x180]; s32 f_180; s32 f_184; u8 pad188[4]; s32 f_18C; u8 pad190[0x1A]; s16 f_1AA; s16 f_1AC; } S_800A1718_800A1718;
typedef struct { u8 pad0[0x26]; u8 f_26; u8 f_27; u16 f_28; u16 f_2A; u16 f_2C; u16 f_2E; } S_G_800A0E84_800A0E84;
typedef struct { u8 pad0[0x1E]; u8 f_1E; u8 f_1F; u16 f_20; u16 f_22; u16 f_24; } S_G_8009E940_8009E940;
typedef struct { u8 pad0[4]; void *f_4; u8 pad8[4]; s32 f_C; } Hdr_800A1A5C_800A1A5C;
typedef struct { u8 pad0[0xC]; u8 f_C; u8 padD[3]; } Ev_8009E784_8009E784;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[2]; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[0xFF]; } Ch_9E124_8009E124;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[2]; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[0xF7]; u8 f_118; u8 pad119[7]; } Ch_9F060_8009F060;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[2]; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[6]; u8 f_27; u8 pad28[0xF8]; } Ch_9EC48_8009EC48;
typedef struct { u8 f_0; u8 pad1[0xB]; s32 f_C; u8 pad10[0x17]; u8 f_27; u8 pad28[0xDC]; u16 f_104; u16 f_106; u8 f_108; u8 pad109[3]; s32 f_10C; u32 f_110; s32 f_114; u8 pad118[8]; } Ch_A01BC_800A01BC;
typedef struct { u8 pad0[0x1AA]; u16 f_1AA; } S_A0700_800A0700;
typedef struct { u32 v[3]; } Q_A0700_800A0700;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[2]; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[6]; u8 f_27; u8 pad28[0xF8]; } Ch_9EE28_8009EE28;
typedef struct { u8 pad0[0x10]; u8 *f_10; u8 pad14[0x22]; u8 f_36; u8 pad37; u8 f_38; u8 pad39; u8 m[10][16]; u8 padDA[0x46]; } Ch_A0B64_800A0B64;
typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[8]; s32 f_C; u8 pad10[0x109]; u8 f_119; u8 f_11A; u8 f_11B; u8 pad11C[4]; } S_F5AC0_8009FEB4;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[9]; s32 f_C; u8 *f_10; u8 pad14[0xC]; u8 f_20; u8 pad21[0xFF]; } S_Ch_800A0050_800A0050;
typedef struct { u16 f_0; u16 f_2; u16 f_4; u8 pad6[0xA]; } S_Voice_800A0050_800A0050;
typedef struct { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[0x11C]; } Ch_9E6B4_8009E6B4;
typedef struct { u8 f_0; u8 f_1; u8 pad2[0xA]; s32 f_C; u8 pad10[0x15]; u8 f_25; u8 pad26; u8 f_27; u8 pad28[0xBB]; u8 f_E3; u8 padE4; u8 f_E5; u8 f_E6; u8 padE7[0x19]; u8 f_100; u8 f_101; u8 pad102[0x12]; s32 f_114; u8 pad118[8]; } Ch_9EAAC_8009EAAC;
typedef struct { u8 f_0; u8 pad1[0xB]; s32 f_C; u8 pad10[0x18]; s32 f_28; u8 pad2C[5]; u8 f_31; u8 pad32; u8 f_33; u8 pad34; u8 f_35; u8 pad36[0xAC]; u8 f_E2; u8 padE3[0x3D]; } Ch_9FA28_8009FA28;
typedef struct { u16 f_0, f_2, f_4, f_6, f_8, f_A; u8 padC[4]; } SpuVoice_A13EC_800A13EC;
typedef struct { SpuVoice_A13EC_800A13EC v[24]; u8 pad180[8]; u16 f_188; u16 f_18A; u16 f_18C; u16 f_18E; u8 pad190[0x1A]; u16 f_1AA; u16 f_1AC; } SpuRegs_A13EC_800A13EC;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 f_3; u8 pad4[8]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[6]; u8 f_27; u8 pad28[0xF8]; } Ch_9F218_8009F218;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 f_3; u8 pad4[8]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[6]; u8 f_27; u8 pad28[0xF8]; } Ch_9F568_8009F568;
typedef struct { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[8]; s32 f_C; u8 pad10[0x109]; u8 f_119; u8 pad11A; u8 f_11B; u8 f_11C; u8 pad11D; u16 f_11E; } Ch_9FB08_8009FB08;
typedef struct { u8 pad0[6]; u16 f_6; u16 f_8; } Adsr_9FB08_8009FB08;
typedef struct { u8 pad0[8]; u16 f_8; u16 f_A; u8 padC[4]; } SpuV_9FB08_8009FB08;
typedef struct { u8 pad0[0x26]; u8 f_26; u8 f_27; u8 pad28[0xBB]; u8 f_E3; u8 padE4[6]; u16 f_EA; u16 f_EC; u8 padEE[0x12]; u8 f_100; u8 f_101; u8 pad102[0x12]; s32 f_114; u8 pad118[8]; } Ch_A048C_800A048C;
typedef struct { u8 pad0[0xC]; u16 f_C; u8 padE[2]; } V16_A048C_800A048C;
typedef struct { u8 f_0; u8 f_1; u8 f_2; u8 pad3[9]; s32 f_C; u8 pad10[0x15]; u8 f_25; u8 pad26; u8 f_27; s32 f_28; u8 pad2C[7]; u8 f_33; u8 pad34; u8 f_35; u8 pad36[0xA4]; u16 f_DA; u16 f_DC; u16 f_DE; u16 f_E0; u8 f_E2; u8 padE3[0x21]; u16 f_104; u8 pad106[0xE]; s32 f_114; u8 pad118[8]; } Ch_9BA90_8009BA90;
typedef struct { u8 pad0[0x188]; u16 f_188; u16 f_18A; u16 f_18C; u16 f_18E; u8 pad190[4]; u16 f_194; u16 f_196; u16 f_198; u16 f_19A; } Spu_9BA90_8009BA90;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 pad3[9]; s32 f_C; u8 *f_10; u8 pad14[0xC]; u8 f_20; u8 pad21[0xFF]; } S_Ch_800A0900_800A0900;
typedef struct { u8 pad0[0x20]; s32 f_20; } S_Bank_800A0900_800A0900;
typedef struct { u16 f_0; u16 f_2; u8 pad4[0xC]; } S_Voice_800A0900_800A0900;
typedef struct { u16 w[51]; } Vc_A0900_800A0900;

extern u8 *D_800B4DF0;


extern M2C_UNK g_SeqChannels;
extern void *D_800B4DE0;
extern s32 D_800E1854;
extern u8 *D_800B4DE4;
extern M2C_UNK D_800F75C0;

M2C_UNK DMACallback(M2C_UNK, s32);
extern s32 D_800B4424;
extern s16 D_800F75DC;
struct S_D_800F5AC0_8009FF38 { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[8]; s32 f_C; u8 pad10[0x18]; s32 f_28; u8 pad2C[5]; u8 f_31; u8 pad32; u8 f_33; u8 pad34; u8 f_35; u8 pad36[0xE3]; u8 f_119; u8 f_11A; u8 f_11B; u8 f_11C; u8 pad11D[3]; };
extern S_800A1718_800A1718 *D_800E1874;
extern u16 g_SeqVoices[][51];
extern s32 g_SoundBanks[][3];
void func_8002F210(void);
void func_8002F5D0(s32);
void func_8002F230(void);
struct S_D_800F75C0_800A1718 { u8 pad0[0x18]; s32 f_18; };
void func_8009E4D8(s32 arg0, s32 arg1);
struct S_D_800F5AC0_8009E2DC { u8 f_0; u8 pad1; u8 f_2; u8 pad3[9]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 pad21[0xFF]; };
void Seq_VoiceBindSample(u16 v);
struct S_D_800F5AC0_800A1018 { u8 f_0; u8 pad1; u8 f_2; u8 pad3[9]; s32 f_C; u8 *f_10; u8 pad14[0xC]; u8 f_20; u8 pad21[0xFF]; };
struct S_D_800F5AC0_8009F8A8 { u8 f_0; u8 pad1; u8 f_2; u8 pad3[9]; s32 f_C; u8 *f_10; u8 pad14[0xC]; u8 f_20; u8 pad21[0xFF]; };
extern u8 D_800B4422;
void func_800A23E0(s16, s16);
void *func_8009E82C(u8, u8, u8);
struct S_D_800F5AC0_8009E940 { u8 pad0[0xC]; s32 f_C; void *f_10; u8 pad14[0xC]; u8 f_20; u8 pad21[3]; u8 f_24; u8 f_25; u8 f_26; u8 f_27; u8 pad28[9]; u8 f_31; u8 pad32; u8 f_33; u8 pad34[0xAE]; u8 f_E2; u8 f_E3; u8 padE4; u8 f_E5; u8 f_E6; u8 padE7; u16 f_E8; u16 f_EA; u16 f_EC; u8 padEE[0x26]; s32 f_114; u8 pad118[8]; };
struct S_F75C0_800A1A5C { u8 pad0[0x1C]; u16 busy; u8 pad1E[0x17]; u8 qcount; };
extern union S_D_800E1780 { struct { void *src; void *dst; u32 size; } e; u32 v[3]; } g_SpuUploadQueue[];
s16 Spu_StartTransfer(u8, u32, u32, u32);
struct S_D_800E1180_800A1A5C { s32 used; Hdr_800A1A5C_800A1A5C *h; u32 size; };
extern u8 D_800B3D90[];
extern u8 *D_800B4DE8;
struct S_D_800F75C0_8009F060 { u8 pad0[0x3E]; u16 f_3E; };
struct S_D_800F75C0_800A01BC { u8 pad0[0x3E]; u16 f_3E; };
extern void (*D_800B4DEC)(void);
struct S_D_800F75C0_800A0700 { u8 pad0[0x1C]; u16 busy; u8 pad1E[0x16]; u8 f_34; u8 qcount; };
u8 Sound_LerpU8(u8 a, u8 b, u8 c, u8 d);
void func_800A2428(u8, u8);
void func_800A1018(s16 ch, s16 n, s16 vol);
void func_800A2B6C(u8, s32);
u16 Seq_NotePitch(u8, u8, s8, u8, u8);
struct S_D_800F75C0_800A1830 { u8 pad0[0x1C]; u16 f_1C; u8 pad1E[0x17]; u8 f_35; };
struct S_D_800F75C0_800A192C { u8 pad0[0x1C]; u16 f_1C; u8 pad1E[0x17]; u8 f_35; };
extern u8 *D_800E1860;
extern u8 D_800B4190[];
extern struct S_D_800A6AA0 { u8 b[16]; } D_800A6AA0;
extern u32 *D_800E1840;
extern u32 *D_800E1844;
extern u32 *D_800E1848;
extern u32 *D_800E184C;
extern u32 *D_800E1850;
void Spu_SetDmaCallback(s32 arg0);
void Spu_ProcessUploadQueue(void);
s32 func_8002F5B0(u32, s32, s32, s32);
void func_8002F5C0(s32);
void Sound_BusyWait(s32);
s16 Spu_Upload(u32, u32, u32);
s16 func_800A1A24(void);
struct S_D_800F75C0_800A13EC { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[9]; u8 f_D; u8 padE[0xA]; s32 f_18; u8 pad1C[0x22]; u16 f_3E; };
u8 func_8009E784(u8 cmd, u8 n);
u16 Seq_NoteVolume(u8, u8, u8);
struct S_D_800F75C0_8009F218 { u8 pad0[0x3E]; u16 f_3E; };
struct S_D_800F75C0_8009F568 { u8 pad0[0x3E]; u16 f_3E; };
void func_800A2030(u8);
void func_800A20F4(u8, u8);
void func_800A222C(u8);
void func_800A2184(u8);
struct S_D_800F75C0_800A048C { u8 f_0; u8 pad1[0xC]; u8 f_D; u8 padE[0x10]; u8 f_1E; };
s32 func_800A1378(s32 arg0);
void Seq_ReleaseFinishedVoices(void);
u8 *func_8009D7C8(u8);
s32 SeqDriver_ReadEvent(u8);
u8 func_8009D870(u8);
void Seq_EndOfTrack(u8 ch);
void Seq_SetTempo(u8);
void Seq_ProgramChange(s32 arg0);
void Seq_CmdModulation(u8 ch);
void Seq_CmdModRate(u8 ch);
void Seq_CmdNrpnData(u8);
void Seq_CmdVolume(u8 ch);
void Seq_CmdPan(u8 ch);
void Seq_CmdSustain(u8 ch);
void Seq_CmdPortamento(u8 ch);
void Seq_CmdLoop(u8);
void Seq_ReadDeltaTime(u8);
void Seq_CmdNrpnLsb(u8 i);
void Seq_CmdNrpnMsb(u8 ch);
void Seq_PitchBend(u8 ch);
u8 Seq_NoteOff(u8 ch);
void func_8009BFFC(u8);
void func_8009C77C(u8);
void Seq_UpdateChannelFades(u8);
void func_8009CE18(void);
void Sound_UpdateFade(void);
struct S_D_800F75C0_8009BA90 { u8 pad0; u8 f_1; u8 pad2[2]; u8 f_4; u8 pad5[0xB]; u16 f_10; u16 f_12; u16 f_14; u16 f_16; u8 pad18[0x1A]; u16 f_32; u8 pad34[2]; u16 f_36; u16 f_38; u16 f_3A; u16 f_3C; };
extern S_Bank_800A0900_800A0900 *D_800E1870;
s16 Seq_VoiceVolume(u16, s32);
struct S_D_800F75C0_8009DAB4 { u8 f_0; u8 pad1[0xE]; u8 f_F; };

void Seq_Tick(void) {
    Ch_9BA90_8009BA90 *c = ((Ch_9BA90_8009BA90 *)&g_SeqChannels);
    struct S_D_800F75C0_8009BA90 *s = ((struct S_D_800F75C0_8009BA90 *)&D_800F75C0);

    func_800A1378(1);
    Seq_ReleaseFinishedVoices();
    for (s->f_1 = 0; s->f_1 < 24; s->f_1++, c++) {
        if (c->f_25 == 1 || c->f_27 == 1) {
            func_8009D7C8(s->f_1);
            while (c->f_114 == 0) {
                SeqDriver_ReadEvent(s->f_1);
                if (func_8009D870(s->f_1) == 0) {
                    c->f_C += 3;
                    s->f_4 = 0;
                } else {
                    s->f_4 = 1;
                    switch (c->f_0 & 0xF0) {
                    case 0xF0:
                        switch (c->f_2) {
                        case 0x2F:
                            Seq_EndOfTrack(s->f_1);
                            goto next;
                        case 0x51:
                            Seq_SetTempo(s->f_1);
                            break;
                        }
                        break;
                    case 0xC0:
                        Seq_ProgramChange(s->f_1);
                        break;
                    case 0xB0:
                        switch (c->f_2) {
                        case 1:
                            Seq_CmdModulation(s->f_1);
                            break;
                        case 2:
                            Seq_CmdModRate(s->f_1);
                            break;
                        case 6:
                            Seq_CmdNrpnData(s->f_1);
                            break;
                        case 7:
                            Seq_CmdVolume(s->f_1);
                            break;
                        case 0xA:
                            if (s->f_32 != 0) {
                                if (c->f_25 != 0) {
                                    (*(u8 * *)&D_800B4DE0)[4] = ((u8 *)(c->f_C + D_800E1854))[2];
                                    c->f_C += 3;
                                } else {
                                    c->f_C += 6;
                                }
                            } else {
                                Seq_CmdPan(s->f_1);
                            }
                            break;
                        case 0x40:
                            Seq_CmdSustain(s->f_1);
                            break;
                        case 0x41:
                            Seq_CmdPortamento(s->f_1);
                            break;
                        case 0x60:
                            Seq_CmdLoop(s->f_1);
                            Seq_ReadDeltaTime(s->f_1);
                            goto next;
                        case 0x62:
                            Seq_CmdNrpnLsb(s->f_1);
                            break;
                        case 0x63:
                            Seq_CmdNrpnMsb(s->f_1);
                            break;
                        }
                        break;
                    case 0xE0:
                        Seq_PitchBend(s->f_1);
                        break;
                    case 0x80:
                        Seq_NoteOff(s->f_1);
                        break;
                    case 0xA0:
                        func_8009BFFC(s->f_1);
                        break;
                    case 0x90:
                        func_8009C77C(s->f_1);
                        break;
                    }
                }
                Seq_ReadDeltaTime(s->f_1);
            }
        next:
            if (s->f_4 != 0) {
                s->f_36 |= c->f_DA;
                s->f_38 |= c->f_DC;
                s->f_3A |= c->f_DE;
                s->f_3C |= c->f_E0;
                c->f_DC = 0;
                c->f_DA = 0;
                c->f_E0 = 0;
                c->f_DE = 0;
                s->f_4 = 0;
            }
            if ((c->f_104 != 0 || c->f_27 == 1) && c->f_114 != 0) {
                c->f_114--;
            }
            if (c->f_33 != 0) {
                c->f_0 = c->f_35;
                c->f_33 = 0;
                c->f_1 = c->f_35;
                c->f_C = c->f_28;
                if (c->f_E2 != 0) {
                    c->f_27 = 1;
                    c->f_E2 = 0;
                } else {
                    c->f_25 = 1;
                    c->f_114 = 0;
                }
            }
        }
        Seq_UpdateChannelFades(s->f_1);
    }
    (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_194 = s->f_14;
    (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_196 = s->f_16;
    (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_198 = s->f_10;
    (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_19A = s->f_12;
    if (s->f_3A + s->f_3C != 0) {
        (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_18C = s->f_3A;
        (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_18E = s->f_3C;
        Sound_BusyWait(2);
    }
    if (s->f_36 + s->f_38 != 0) {
        (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_188 = s->f_36;
        (*(Spu_9BA90_8009BA90 * *)&D_800E1874)->f_18A = s->f_38;
    }
    s->f_38 = 0;
    s->f_36 = 0;
    s->f_3C = 0;
    s->f_3A = 0;
    func_8009CE18();
    Sound_UpdateFade();
    func_800A1378(0);
}

INCLUDE_RODATA("asm/nonmatchings/game/8009BA90_seq", jtbl_800A68C0_pad);


typedef struct { u8 f_0; u8 f_1; u8 f_2; u8 f_3; u16 f_4; u16 f_6; u16 f_8; u8 f_A; u8 f_B; u8 f_C; u8 f_D; u8 f_E; u8 f_F; } Note_BFFC;
typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[6]; u8 f_A; u8 padB; u8 f_C; u8 padD; u8 f_E; } Trk_BFFC;
typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 f_3; u8 pad4; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0xD]; u8 f_1D; u8 pad1E; u8 f_1F; u8 f_20; u8 pad21[0xC4]; u8 f_E5; u8 f_E6; u8 padE7; u16 f_E8; u16 f_EA; u16 f_EC; u8 padEE[0x32]; } Ch_BFFC;
typedef struct { u8 f_0; u8 pad1[3]; u8 f_4; u8 pad5[0xB]; u16 f_10; u16 f_12; u16 f_14; u16 f_16; u8 pad18[0x1A]; u16 f_32; } Seq_BFFC;
typedef struct { u16 f_0, f_2, f_4, f_6, f_8, f_A; u8 padC[4]; } SpuV_BFFC;
typedef struct { SpuV_BFFC v[24]; u8 pad180[0x2A]; u16 f_1AA; } Spu_BFFC;
typedef struct { u8 pad0[8]; u16 f_8; u8 padA[2]; } Bank_BFFC;
typedef struct { u16 f_0, f_2, f_4, f_6, f_8, f_A, f_C, f_E, f_10, f_12, f_14, f_16, f_18, f_1A, f_1C, f_1E, f_20, f_22, f_24, f_26, f_28, f_2A, f_2C, f_2E, f_30, f_32, f_34, f_36, f_38, f_3A, f_3C, f_3E, f_40, f_42, f_44, f_46, f_48, f_4A, f_4C, f_4E; u16 pad50[9]; u16 f_62; u16 pad64; } Vo_BFFC;
extern Note_BFFC *D_800B4DF0_BFFC asm("D_800B4DF0");
extern Trk_BFFC *D_800B4DE0_BFFC asm("D_800B4DE0");
extern Ch_BFFC g_SeqChannels_BFFC[] asm("g_SeqChannels");
extern Vo_BFFC g_SeqVoices_BFFC[] asm("g_SeqVoices");
extern Seq_BFFC D_800F75C0_BFFC asm("D_800F75C0");
extern Spu_BFFC *D_800E1874_BFFC asm("D_800E1874");
extern Bank_BFFC g_SoundBanks_BFFC[] asm("g_SoundBanks");
u8 func_8009E124(u8 ch);
u8 func_8009DCA0(u8 ch, u8 prio);
s16 Seq_ScaleParam(u16, s32);
s32 Math_MaxS16(s16, s16);
void func_8009E434(s32, s32);
void func_8009E490(s32 a0, u8 bit);

void func_8009BFFC(u8 ch) {
    Ch_BFFC *c;
    Seq_BFFC *sq = &D_800F75C0_BFFC;
    s16 d;
    s32 k;
    s32 v;
    s32 j;
    Vo_BFFC *vo;
    u16 l, r;
    s16 a, b;
    u8 adsr;

    c = g_SeqChannels_BFFC; c += (u8)ch;
    if (c->f_3 == 0) {
        func_8009E124((u8)ch);
        return;
    }
    d = c->f_2 - D_800B4DE8[6];
    k = d;
    if (k < 0) {
        return;
    }
    D_800B4DF0_BFFC += k;
    D_800B4DE0_BFFC->f_A = 0x40;
    v = func_8009DCA0(D_800B4DF0_BFFC->f_0, D_800B4DF0_BFFC->f_1);
    { s32 i0; __asm__("" : "=r"(i0) : "0"(v));
    if (i0 == 0xFF) {
        c->f_C += 4;
        sq->f_4 = 0;
        return;
    }
    if (D_800B4DF0_BFFC->f_F & 1) {
        g_SeqVoices_BFFC[i0].f_8 = 0;
        g_SeqVoices_BFFC[i0].f_C = 1;
    } else {
        g_SeqVoices_BFFC[i0].f_8 = 1;
        g_SeqVoices_BFFC[i0].f_C = 0;
    } }
    g_SeqVoices_BFFC[v].f_0 = 1;
    g_SeqVoices_BFFC[v].f_2 = c->f_2;
    g_SeqVoices_BFFC[v].f_4 = c->f_0 & 0xF;
    __asm__("" : "=m"(g_SeqVoices_BFFC[v].f_6) : "m"(g_SeqVoices_BFFC[v].f_4));
    g_SeqVoices_BFFC[v].f_6 = (u8)ch;
    g_SeqVoices_BFFC[v].f_A = sq->f_0;
    g_SeqVoices_BFFC[v].f_E = d;
    g_SeqVoices_BFFC[v].f_12 = 0;
    g_SeqVoices_BFFC[v].f_18 = 0;
    g_SeqVoices_BFFC[v].f_1A = 1;
    g_SeqVoices_BFFC[v].f_1C = 4;
    g_SeqVoices_BFFC[v].f_1E = D_800B4DF0_BFFC->f_1;
    g_SeqVoices_BFFC[v].f_20 = D_800B4DF0_BFFC->f_0;
    g_SeqVoices_BFFC[v].f_22 = c->f_20;
    g_SeqVoices_BFFC[v].f_24 = c->f_1D;
    g_SeqVoices_BFFC[v].f_26 = c->f_1F;
    g_SeqVoices_BFFC[v].f_28 = D_800B4DE0_BFFC->f_E;
    g_SeqVoices_BFFC[v].f_2A = D_800B4DE8[1];
    g_SeqVoices_BFFC[v].f_2C = D_800E1860[c->f_3 + 2];
    g_SeqVoices_BFFC[v].f_2E = D_800B4DF0_BFFC->f_B;
    g_SeqVoices_BFFC[v].f_30 = D_800B4190[(func_8009E784(4, 0) >> 1) & 0x7E];
    { u8 *q = &D_800B4190[((func_8009E784(4, 0) >> 1) & 0x7E)]; g_SeqVoices_BFFC[v].f_32 = q[1]; }
    g_SeqVoices_BFFC[v].f_34 = D_800B4DE0_BFFC->f_3;
    g_SeqVoices_BFFC[v].f_36 = D_800B4DF0_BFFC->f_3;
    g_SeqVoices_BFFC[v].f_38 = D_800B4DE0_BFFC->f_A;
    g_SeqVoices_BFFC[v].f_3A = D_800B4DF0_BFFC->f_D;
    g_SeqVoices_BFFC[v].f_3C = D_800B4DE0_BFFC->f_C;
    g_SeqVoices_BFFC[v].f_3E = c->f_5;
    g_SeqVoices_BFFC[v].f_40 = D_800B4DF0_BFFC->f_2;
    g_SeqVoices_BFFC[v].f_44 = 0;
    g_SeqVoices_BFFC[v].f_4A = D_800B4DF0_BFFC->f_A;
    g_SeqVoices_BFFC[v].f_4C = D_800B4DF0_BFFC->f_C;
    g_SeqVoices_BFFC[v].f_4E = 0x78;
    g_SeqVoices_BFFC[v].f_62 = 0;
    sq->f_0 += sq->f_0 < 0x18;
    if (D_800B4DF0_BFFC->f_F & 0x20) {
        if (D_800B4DF0_BFFC->f_F & 0x40) {
            g_SeqVoices_BFFC[v].f_10 = D_800B4DE8[5];
        } else {
            g_SeqVoices_BFFC[v].f_10 = D_800B4DF0_BFFC->f_E;
        }
        g_SeqVoices_BFFC[v].f_14 = 1;
        g_SeqVoices_BFFC[v].f_16 = 0x7F;
    } else {
        g_SeqVoices_BFFC[v].f_14 = 0;
    }
    l = Seq_NoteVolume((u8)ch, func_8009E784(4, 0), 0);
    r = Seq_NoteVolume((u8)ch, func_8009E784(4, 0), 1);
    if (D_800B4DF0_BFFC->f_F & 0x10) {
        adsr = D_800B4DE8[4];
    } else {
        adsr = D_800B4DF0_BFFC->f_D;
    }
    if (c->f_E5 != 0) {
        u16 p = Seq_NotePitch(D_800B4DF0_BFFC->f_2, c->f_2, D_800B4DF0_BFFC->f_3, D_800B4DE0_BFFC->f_A, adsr);
        { s32 ja; __asm__("" : "=r"(ja) : "0"(v));
        D_800E1874_BFFC->v[ja].f_4 = p * c->f_E8 >> 12;
        a = Seq_ScaleParam(l, c->f_EA);
        b = Seq_ScaleParam(r, c->f_EC);
        g_SeqVoices_BFFC[ja].f_42 = 1; }
    } else {
        u16 p = Seq_NotePitch(D_800B4DF0_BFFC->f_2, c->f_2, D_800B4DF0_BFFC->f_3, D_800B4DE0_BFFC->f_A, adsr);
        { s32 jb; Spu_BFFC *sp = D_800E1874_BFFC; __asm__("" : "=r"(jb) : "0"(v), "r"(p));
        sp->v[jb].f_4 = p;
        a = Seq_ScaleParam(l, 0x1000);
        b = Seq_ScaleParam(r, 0x1000);
        g_SeqVoices_BFFC[jb].f_42 = 0; }
    }
    if (sq->f_32 != 0) {
        b = Math_MaxS16(a, b); __asm__("" : "=r"(a) : "0"(b));
    }
    {
        Spu_BFFC *sp = D_800E1874_BFFC; SpuV_BFFC *sv;
        __asm__("" : "=r"(j) : "0"(v), "r"(a));
        sv = &sp->v[j];
        sv->f_0 = a;
        sv->f_2 = b;
        sv->f_6 = D_800B4DF0_BFFC->f_4 + g_SoundBanks_BFFC[c->f_20].f_8;
        sv->f_8 = D_800B4DF0_BFFC->f_6;
        sv->f_A = D_800B4DF0_BFFC->f_8;
    }
    func_8009E434((u8)ch, v);
    if (c->f_E6 != 0) {
        if (j < 0x10) {
            sq->f_10 |= 1 << j;
        } else {
            sq->f_12 |= 1 << (j - 0x10);
        }
    } else if (D_800B4DF0_BFFC->f_F & 0x80) {
        if (j < 0x10) {
            sq->f_10 |= 1 << j;
        } else {
            sq->f_12 |= 1 << (j - 0x10);
        }
    } else if (j < 0x10) {
        sq->f_10 &= ~(1 << j);
    } else {
        sq->f_12 &= ~(1 << (j - 0x10));
    }
    if (D_800B4DF0_BFFC->f_F & 2) {
        func_8009E490((u8)ch, v);
        D_800E1874_BFFC->f_1AA = (D_800E1874_BFFC->f_1AA & 0xC0FF) | (D_800B4DF0_BFFC->f_2 << 8);
    } else {
        s32 j2; __asm__("" : "=r"(j2) : "0"(v));
        if (j2 < 0x10) {
            sq->f_14 &= ~(1 << j2);
        } else {
            sq->f_16 &= ~(1 << (j2 - 0x10));
        }
    }
    D_800B4DF0_BFFC -= d;
    c->f_C += 4;
}

typedef struct { u8 f_0; u8 pad1; u8 f_2; u8 f_3; u8 pad4; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x10]; u8 f_20; u8 f_21; u8 pad22; u8 f_23; u8 pad24[0xFC]; } SeqCh_C77C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; s16 f_16; s16 f_18; s16 f_1A; s16 f_1C; s16 f_1E; s16 f_20; s16 f_22; s16 pad24[2]; s16 f_28; s16 f_2A; s16 f_2C; s16 f_2E; s16 f_30; s16 f_32; s16 f_34; s16 f_36; s16 f_38; s16 f_3A; s16 f_3C; s16 f_3E; s16 f_40; s16 f_42; s16 f_44; s16 pad46[2]; s16 f_4A; s16 f_4C; s16 f_4E; s16 pad50[11]; } SeqVoice_C77C;
typedef struct { s16 volL; s16 volR; s16 pad4; s16 pitch; u16 adsr1; u16 adsr2; u8 padC[4]; } SpuVAttr_C77C;
typedef struct { u8 nvoice; u8 pad1[0xB]; u8 f_C; u8 pad0D[3]; u16 f_10; u16 f_12; u16 f_14; u16 f_16; u8 pad18[0x1A]; u16 f_32; } SeqState_C77C;
extern SeqCh_C77C g_SeqChannels_C77C[] asm("g_SeqChannels");
extern SeqVoice_C77C g_SeqVoices_[] asm("g_SeqVoices");
extern SeqState_C77C D_800F75C0_ asm("D_800F75C0");
extern u8 *D_800B4DE0_C77C asm("D_800B4DE0");
extern u8 *D_800B4DE8_C77C asm("D_800B4DE8");
extern u8 *D_800B4DF0_C77C asm("D_800B4DF0");
extern u8 *D_800E1860_C77C asm("D_800E1860");
extern SpuVAttr_C77C *D_800E1874_ asm("D_800E1874");
extern u8 D_800B4190_C77C[] asm("D_800B4190");
extern s32 g_SoundBanks_C77C[][3] asm("g_SoundBanks");
u8 Seq_NoteOff_C77C(u8 ch) asm("Seq_NoteOff");
s32 Seq_AllocVoice_C77C(void) asm("Seq_AllocVoice");
void func_8009E434_C77C(s32, s32) asm("func_8009E434");
u8 func_8009E534_C77C(u8, u8, u8) asm("func_8009E534");
u16 func_8009E594_C77C(u8, u8, s8, u8, u8) asm("Seq_NotePitch");
u8 func_8009E784_C77C(u8 cmd, u8 n) asm("func_8009E784");
u16 Seq_NoteVolume_C77C(u8, u8, u8) asm("Seq_NoteVolume");
s16 Math_MaxS16_C77C(s16, s16) asm("Math_MaxS16");

void func_8009C77C(u8 ch) {
    SeqCh_C77C *c = (SeqCh_C77C *)g_SeqChannels_C77C;
    SeqState_C77C *st = &D_800F75C0_;
    s16 k;
    s32 v;
    s32 j;
    SeqVoice_C77C *vo;
    SpuVAttr_C77C *a;
    u8 t;
    u8 prio;
    s16 l, r;

    c += ch;
    if (c->f_3 == 0) {
        Seq_NoteOff_C77C(ch);
        return;
    }
    if (D_800B4DE0_C77C[3] != 0) {
        t = D_800B4DE8_C77C[0];
        if (t == 0xFF) {
            c->f_21 = c->f_23 = c->f_2 - D_800B4DE8_C77C[6];
        } else {
            if (t & 0x80) {
                c->f_23 = t + 0x80;
                st->f_C = 0;
            } else {
                c->f_23 = t;
                st->f_C = 1;
            }
            c->f_21 = 0;
        }
        for (k = c->f_21; k < c->f_23 + 1; k++) {
            if (func_8009E534_C77C(D_800B4DE8_C77C[0], k, c->f_2) == 0) {
                continue;
            }
            v = Seq_AllocVoice_C77C() & 0xFF;
            { s32 w; __asm__("" : "=r"(w) : "0"(v));
            if (w == 0xFF) {
                break;
            }
            D_800B4DF0_C77C += k * 16;
            if (D_800B4DF0_C77C[0xF] & 1) {
                g_SeqVoices_[w].f_8 = 0;
                g_SeqVoices_[w].f_C = 1;
            } else {
                g_SeqVoices_[w].f_8 = 1;
                g_SeqVoices_[w].f_C = 0;
            } }
            vo = &g_SeqVoices_[v];
            vo->f_0 = 1;
            vo->f_2 = c->f_2;
            vo->f_4 = c->f_0 & 0xF;
            vo->f_6 = ch;
            vo->f_A = st->nvoice;
            vo->f_E = k;
            vo->f_12 = 0;
            vo->f_1A = 0;
            vo->f_1C = 0;
            vo->f_1E = 0;
            vo->f_20 = 0;
            vo->f_22 = c->f_20;
            vo->f_28 = D_800B4DE0_C77C[0xE];
            vo->f_2A = D_800B4DE8_C77C[1];
            vo->f_2C = D_800E1860_C77C[c->f_3 + 2];
            vo->f_2E = D_800B4DF0_C77C[0xB];
            vo->f_30 = *(((func_8009E784_C77C(0, 0) >> 1) & 0x7E) + D_800B4190_C77C);
            vo->f_32 = ((struct { u8 a; u8 b; } *)(((func_8009E784_C77C(0, 0) >> 1) & 0x7E) + D_800B4190_C77C))->b;
            vo->f_34 = D_800B4DE0_C77C[3];
            vo->f_36 = D_800B4DF0_C77C[3];
            vo->f_38 = D_800B4DE0_C77C[0xA];
            vo->f_3A = D_800B4DF0_C77C[0xD];
            vo->f_3C = D_800B4DE0_C77C[0xC];
            vo->f_3E = c->f_5;
            vo->f_40 = D_800B4DF0_C77C[2];
            vo->f_42 = 0;
            vo->f_44 = 0;
            vo->f_4A = D_800B4DF0_C77C[0xA];
            vo->f_4C = D_800B4DE0_C77C[4];
            vo->f_4E = 0x78;
            if (D_800B4DE0_C77C[0xB] == 0x7F) {
                vo->f_18 = 1;
            }
            t = D_800B4DF0_C77C[0xF];
            if ((t & 0x20) && D_800B4DE0_C77C[9] != 0) {
                if (t & 0x40) {
                    vo->f_10 = D_800B4DE8_C77C[5];
                } else {
                    vo->f_10 = D_800B4DF0_C77C[0xE];
                }
                g_SeqVoices_[v].f_14 = 1;
                g_SeqVoices_[v].f_16 = D_800B4DE0_C77C[9];
            } else {
                g_SeqVoices_[v].f_14 = 0;
                g_SeqVoices_[v].f_16 = 0;
            }
            if (D_800B4DF0_C77C[0xF] & 0x10) {
                prio = D_800B4DE8_C77C[4];
            } else {
                prio = D_800B4DF0_C77C[0xD];
            }
            __asm__("" : "=r"(j) : "0"(v));
            { s16 p = func_8009E594_C77C(D_800B4DF0_C77C[2], c->f_2, D_800B4DF0_C77C[3], D_800B4DE0_C77C[0xA], prio); *(s16 *)((s32)D_800E1874_ + (j << 4) + 4) = p; }
            l = Seq_NoteVolume_C77C(ch, func_8009E784_C77C(0, 0), 0);
            r = Seq_NoteVolume_C77C(ch, func_8009E784_C77C(0, 0), 1);
            if (st->f_32 != 0) {
                r = Math_MaxS16_C77C(l, r);
                l = r;
            }
            a = &D_800E1874_[j];
            a->volL = l;
            a->volR = r;
            a->pitch = *(u16 *)(D_800B4DF0_C77C + 4) + g_SoundBanks_C77C[c->f_20][2];
            a->adsr1 = *(u16 *)(D_800B4DF0_C77C + 6);
            a->adsr2 = *(u16 *)(D_800B4DF0_C77C + 8);
            func_8009E434_C77C(ch, v);
    __asm__("" :: "r"(st),"r"(st),"r"(st),"r"(st),"r"(st),"r"(st),"r"(st),"r"(st));
            if (D_800B4DF0_C77C[0xF] & 0x80) {
                if (j < 0x10) {
                    st->f_10 |= 1 << j;
                } else {
                    st->f_12 |= 1 << (j - 0x10);
                }
            } else if (j < 0x10) {
                st->f_10 &= ~(1 << j);
            } else {
                st->f_12 &= ~(1 << (j - 0x10));
            }
            { s32 x; __asm__("" : "=r"(x) : "0"(v));
            if (x < 0x10) {
                st->f_14 &= ~(1 << x);
            } else {
                st->f_16 &= ~(1 << (x - 0x10));
            } }
            st->nvoice += st->nvoice < 0x18;
            D_800B4DF0_C77C -= k * 16;
            if (st->f_C != 0) {
                st->f_C = 0;
                break;
            }
        }
    }
    c->f_C += 3;
}

typedef struct { u8 pad0[0xE8]; s16 f_E8; u16 f_EA; u16 f_EC; u8 padEE[0x12]; u8 f_100; u8 f_101; u8 pad102[0x16]; u8 f_118; u8 pad119[7]; } Ch_9CE18_CE18;
typedef struct { s16 volL; s16 volR; s16 pitch; u8 pad6[0xA]; } SpuV_9CE18_CE18;
struct Snd_9CE18 { u8 pad0[0x32]; u16 f_32; u8 pad34[0xA]; u16 f_3E; };
extern Ch_9CE18_CE18 g_SeqChannels_CE18[] asm("g_SeqChannels");
extern u16 g_SeqVoices_CE18[][51] asm("g_SeqVoices");
extern SpuV_9CE18_CE18 *D_800E1874_CE18 asm("D_800E1874");
extern u16 *D_800E1864_CE18 asm("D_800E1864");
extern u8 *D_800E1868_CE18 asm("D_800E1868");
extern u8 D_800B4190_CE18[] asm("D_800B4190");
extern struct Snd_9CE18 D_800F75C0_CE18 asm("D_800F75C0");
s16 Math_MaxS16_CE18(s16, s16) asm("Math_MaxS16");
s16 Seq_VoiceVolume_CE18(u16, s32) asm("Seq_VoiceVolume");
u8 Sound_LerpU8_CE18(u8 a, u8 b, u8 c, u8 d) asm("Sound_LerpU8");
u16 func_8009E594_CE18(u8, u8, s8, u8, u8) asm("Seq_NotePitch");
s16 Seq_ScaleParam_CE18(u16 a, s32 b) asm("Seq_ScaleParam");
#define V(k) g_SeqVoices_CE18[i][k]
typedef struct { u8 a, b; } Pair_9CE18_CE18;
extern Pair_9CE18_CE18 D_800B4190P[] asm("D_800B4190");

void func_8009CE18(void) {
    Ch_9CE18_CE18 *c;
    s16 i;
    u8 t2;
    u8 a1;
    u8 a2;
    u8 a3;
    u8 t3;
    u8 depth;
    s32 d;
    s32 n;
    s32 n_s1;
    s32 t1;
    s32 m;
    s16 s;
    s16 l;
    s16 r;
    struct Snd_9CE18 *st;

    c = g_SeqChannels_CE18;
    st = &D_800F75C0_CE18;
    for (i = 0; i < 24; i++) {
        if (V(0) != 1) {
            continue;
        }
        c += V(3);
        if (V(0xA) == 1 || V(0x22) == 1 || c->f_100 == 1) {
            a2 = V(0x1B);
            a1 = V(1);
            t2 = V(0x20);
            a3 = V(0x1C);
            t3 = V(0x1D);
            if (V(0xA) == 1 || V(0x22) == 1) {
                if (t2 <= a1) {
                    t2 = 0x78 - (a1 - t2);
                } else {
                    t2 = t2 - a1 + 0x78;
                }
                if (V(0xA) != 0) {
                    if (st->f_3E == 0x3C && (V(0x1E) & 0xFFF) == 0x78) {
                        if (V(0x1E) & 0xF000) {
                            V(0x1E) = (V(0x1E) & 0xFFF) | ((V(0x1E) & 0xF000) - 0x1000);
                            V(9) += V(0x1E) & 0xFFF;
                        } else {
                            V(0x1E) |= 0x6000;
                        }
                    } else {
                        V(9) += V(0x1E) & 0xFFF;
                    }
                    if (V(9) >= 0xF0) {
                        V(9) = (V(0x1E) & 0xFFF) >> 1;
                    }
                    a1 = V(0x27);
                    depth = D_800E1868_CE18[D_800E1864_CE18[V(8) + 1] + (V(9) >> 2)];
                    if (V(0xE) == 0) {
                        if (V(0x1C) >= 0x40) {
                            { s32 dd = (V(0x1C) - 0x40) * V(0x1D);
                            s32 nn = dd / 64;
                            a1 += nn;
                            a2 += dd / 4 - nn * 16; }
                        } else {
                            d = (0x40 - V(0x1C)) * V(0x1D);
                            n = d / 64;
                            a1 -= n;
                            { s32 q = d / 4; a2 += n * 16 - q; }
                        }
                        t3 = 1;
                    }
                    a3 = depth * V(0xB) / 255 - (((V(0xB) + 1) >> 1) - 0x40);
                }
                if (V(0x22) != 0 && V(0x31) != 0) {
                    V(0x31)--;
                    if (V(0x30) & 0x80) {
                        n_s1 = V(0x32) - V(0x31);
                        t1 = n_s1 * (u8)-V(0x30) * 0xC0 / (V(0x32) * 0x78);
                        a1 = (u8)V(0x27) - n_s1 * (0x100 - V(0x30)) / 10 / V(0x32);
                        a2 -= t1 % 16;
                    } else {
                        m = (V(0x32) - V(0x31)) * V(0x30);
                        t1 = m * 0xC0 / (V(0x32) * 0x78);
                        a1 = (u8)V(0x27) + m / 10 / V(0x32);
                        a2 += t1 % 16;
__asm__("" :: "m"(V(0x30)), "m"(V(0x30)));
                    }
                    if (a1 < 0xD) {
                        a1 = 0xC;
                    }
                    if (a1 >= 0xF3) {
                        a1 = 0xF3;
                    }
                    c->f_118 = a1;
                    if (V(0x31) == 0) {
                        V(0x27) = a1;
                        V(0x22) = 0;
                    }
                }
            }
            if (V(0x21) == 1 || c->f_100 == 1) {
                s = c->f_E8;
            } else {
                s = 0x1000;
            }
            { s32 p = (func_8009E594_CE18(t2, a1, a2, a3, t3) * s) >> 12; SpuV_9CE18_CE18 *b = D_800E1874_CE18; ((SpuV_9CE18_CE18 *)((s32)b + (i << 4)))->pitch = p; }
        }
        if (V(0xD) == 1 && (V(0x23) == 1 || V(0x24) == 1 || c->f_101 == 1)) {
            if (V(0x23) != 0) {
                if (V(0x28) != V(0x29)) {
                    if (V(0x2A) != 0) {
                        V(0x16) = Sound_LerpU8_CE18(V(0x28), V(0x29), V(0x2B), V(0x2A));
                        V(0x2A)--;
                    } else {
                        V(0x16) = V(0x28);
                        V(0x23) = 0;
                    }
                } else {
                    V(0x23) = 0;
                }
            }
            if (V(0x24) != 0) {
                if (V(0x2C) == V(0x2D)) {
                    V(0x24) = 0;
                } else {
                    if (V(0x2E) != 0) {
                        V(0x26) = Sound_LerpU8_CE18(V(0x2C), V(0x2D), V(0x2F), V(0x2E));
                        V(0x2E)--;
                    } else {
                        V(0x26) = V(0x2C);
                        V(0x24) = 0;
                    }
                    V(0x18) = D_800B4190P[V(0x26) >> 2].a;
                    V(0x19) = D_800B4190P[V(0x26) >> 2].b;
                }
            }
            l = Seq_VoiceVolume_CE18(i, 0);
            r = Seq_VoiceVolume_CE18(i, 1);
            if (V(0x21) == 1 || c->f_101 == 1) {
                l = Seq_ScaleParam_CE18(l, c->f_EA);
                r = Seq_ScaleParam_CE18(r, c->f_EC);
            }
            if (st->f_32 != 0) {
                r = Math_MaxS16_CE18(l, r);
                l = r;
            }
            { SpuV_9CE18_CE18 *a = (SpuV_9CE18_CE18 *)((s32)D_800E1874_CE18 + (i << 4)); a->volL = l; a->volR = r; }
        }
        c -= V(3);
    }
}

void Sound_BusyWait(s32 n) {
    s32 i;
    i = n * 0x300;
    while (--i != -1) {
    }
}

typedef struct { u8 pad0[0x10]; s32 unk10; u8 pad14[0xC]; u8 unk20; u8 pad21[6]; u8 unk27; u8 pad28[0xF8]; } SeqCh_9D7C8;
typedef struct { s32 unk0; u8 *unk4; s32 unk8; } Bank_9D7C8;
typedef struct { u8 pad0[8]; u8 *f_8; } Snd_9D7C8;
extern SeqCh_9D7C8 g_SeqChannels_9D7C8[] asm("g_SeqChannels");
extern Bank_9D7C8 g_SoundBanks_9D7C8[] asm("g_SoundBanks");
extern Snd_9D7C8 D_800F75C0_9D7C8 asm("D_800F75C0");
extern u8 *D_800E1870_9D7C8 asm("D_800E1870");
extern u8 *D_800E1864;
extern u8 *D_800E1868;
extern u8 *D_800E1858;
extern u8 *D_800E185C;

/* Loads sound bank `p->unk20` of sequence channel i: sets the bank header pointer and its section
   pointers (offsets at +0x14/+0x18 and the program table entry unk27 at +0x10); returns the bank. */
u8 *func_8009D7C8(u8 i) {
    SeqCh_9D7C8 *p;
    u8 *h;
    u8 *e;
    p = g_SeqChannels_9D7C8;
    p += i;
    h = g_SoundBanks_9D7C8[p->unk20].unk4;
    D_800F75C0_9D7C8.f_8 = h;
    D_800E1870_9D7C8 = h;
    D_800E1854 = p->unk10;
    D_800E1868 = (D_800E1864 = h + *(s32 *)(h + 0x18));
    e = (u8 *)((s32)(p->unk27 * 16) + (s32)h) + 0x10;
    D_800E1860 = h + *(s32 *)(h + 0x14);
    D_800E1858 = h + *(s32 *)e;
    D_800E185C = D_800E1858;
    return h;
}

typedef struct { u8 f_0; u8 pad1[0xB]; s32 f_C; s32 f_10; u8 pad14[0x10]; u32 f_24; u8 pad28[0xF8]; } Ch_9D870;
typedef struct { u8 pad0[0x10]; s32 f_10; u8 pad14[0xC]; s32 f_20; } Bank_9D870;
typedef struct { u8 pad0[8]; s32 f_8; } Snd_9D870;
extern Ch_9D870 g_SeqChannels_9D870[] asm("g_SeqChannels");
extern Snd_9D870 D_800F75C0_9D870 asm("D_800F75C0");
extern Bank_9D870 *D_800E1870_9D870 asm("D_800E1870");
extern u16 *D_800E1858_9D870 asm("D_800E1858");
extern s32 D_800E1854_9D870 asm("D_800E1854");
extern s32 D_800B4DE0_9D870 asm("D_800B4DE0");
extern s32 D_800B4DE4_9D870 asm("D_800B4DE4");
extern s32 D_800B4DE8_9D870 asm("D_800B4DE8");
extern s32 D_800B4DF0_9D870 asm("D_800B4DF0");
#define F20_9D870 (*(s32 *)((u8 *)D_800E1870_9D870 + 0x20))
#define F10_9D870 (*(s32 *)((u8 *)D_800E1870_9D870 + 0x10))

u8 func_8009D870(u8 ch) {
    Ch_9D870 *c = g_SeqChannels_9D870;
    Snd_9D870 *s = &D_800F75C0_9D870;
    u8 ok;
    s32 k;
    c += ch;

    if ((c->f_24 & 0xFF00FF00) == 0x1000000 && (ok = 1, F20_9D870 != -1)) {
        { s32 *pd = &D_800B4DE8_9D870; s32 b = D_800F75C0_9D870.f_8 + F20_9D870; s32 o = D_800E1858_9D870[((u8 *)(c->f_C + D_800E1854_9D870))[3] + 0xC9] + 0x190; s32 *pe = &D_800B4DE0_9D870; *pd = b + o;
        { s32 idx = ((u8 *)(c->f_C + D_800E1854_9D870))[3]; s32 kk;
        D_800B4DE4_9D870 = D_800F75C0_9D870.f_8 + F20_9D870;
        { s32 bb = D_800F75C0_9D870.f_8 + F20_9D870; kk = ch * 16 + 0x10; *pe = bb + kk; }
        D_800B4DF0_9D870 = D_800E1858_9D870[idx + 0xC9] + (D_800F75C0_9D870.f_8 + F20_9D870) + 0x198; }
        }
        goto end;
    }
    if (((u8 *)c)[0x25] == 0 || ((u8 *)c)[0x27] == 1) {
        __asm__("" :: "r"(ok));
        return 0;
    }
    { u8 t; __asm__("" : "=r"(t) : "0"(c->f_0 & 0xF)); k = t; }
    if (c->f_0 < 0xA0) {
        ok = 0;
        if (D_800E1858_9D870[((u8 *)(k * 16 + D_800E1854_9D870))[0x12] + 1] == 0xFFFF) {
            goto end;
        }
        if (*D_800E1858_9D870 < ((u8 *)(k * 16 + D_800E1854_9D870))[0x12]) {
            goto end;
        }
        if (D_800E1870_9D870->f_10 != -1) {
            ok = 1;
        } else {
            ok = 0;
            goto end;
        }
    } else {
        ok = 1;
    }
    { s32 kk; s32 *pd = &D_800B4DE8_9D870; Bank_9D870 *bk = D_800E1870_9D870; kk = k * 16;
    *pd = bk->f_10 + *(s32 *)((u8 *)s + 8) + D_800E1858_9D870[((u8 *)(kk + D_800E1854_9D870))[0x12] + 1];
    { s32 idx = ((u8 *)(kk + D_800E1854_9D870))[0x12];
    kk += 0x10;
    D_800B4DE4_9D870 = *(s32 *)((u8 *)c + 0x10);
    D_800B4DE0_9D870 = *(s32 *)((u8 *)c + 0x10) + kk;
    D_800B4DF0_9D870 = bk->f_10 + *(s32 *)((u8 *)s + 8) + D_800E1858_9D870[idx + 1] + 8; } }
end:
    return ok;
}

/* Seq_AllocVoice: pick a sequencer voice (24 voices, g_SeqVoices). Round-robin from the last one
 * (D_800F75C0+0xF) to the first free voice ([0] == 0); otherwise steal the unlocked ([0xD] == 0)
 * voice in state [4] == 1 with the lowest rank [5], else the first unlocked voice ranked below 24,
 * else none (0xFF). After a steal, ranks above the stolen one move down and the count f_0 drops. */
u8 Seq_AllocVoice(void) {
    u16 best = 24;
    struct S_D_800F75C0_8009DAB4 *s = ((struct S_D_800F75C0_8009DAB4 *)&D_800F75C0);
    s32 next;
    u16 i;
    u8 n;

    for (i = 0; i < 24; i++) {
        next = s->f_F < 23 ? s->f_F + 1 : 0;
        s->f_F = next;
        if (g_SeqVoices[s->f_F][0] == 0) {
            goto end;
        }
    }
    for (i = 0; i < 24; i++) {
        if (g_SeqVoices[i][0xD] == 0 && g_SeqVoices[i][4] == 1 && g_SeqVoices[i][5] < best) {
            best = g_SeqVoices[i][5];
            s->f_F = i;
        }
    }
    if (best == 24) {
        for (i = 0; i < 24; i++) {
            if (g_SeqVoices[i][0xD] == 0 && g_SeqVoices[i][5] < best) {
                best = g_SeqVoices[i][5];
                s->f_F = i;
                goto found;
            }
        }
        s->f_F = 0xFF;
        goto end;
    }
found:
    for (i = 0; i < 24; i++) {
        if (best < g_SeqVoices[i][5]) {
            g_SeqVoices[i][5]--;
        }
    }
    s->f_0--;
end:
    return s->f_F;
}

typedef struct { u8 f_0; u8 pad1[2]; u8 f_3; u8 pad4[9]; u8 f_D; u8 padE; u8 f_F; } Snd_9DCA0;

u8 func_8009DCA0(u8 ch, u8 prio) {
    u16 best = 0;
    Snd_9DCA0 *s = (Snd_9DCA0 *)&D_800F75C0;
    u16 min = 24;
    u16 i;
    u16 j;

    if (ch != 0) {
        for (i = 0; i < 24; i++) {
            if (g_SeqVoices[i][0xD] == 1 && g_SeqVoices[i][0x10] == ch) {
                for (j = 0; j < 24; j++) {
                    if (g_SeqVoices[i][5] < g_SeqVoices[j][5] && g_SeqVoices[i][5] != 0x40) {
                        g_SeqVoices[j][5]--;
                    }
                }
                s->f_0--;
                ch = i;
                goto end;
            }
        }
    }
    if (s->f_D >= s->f_3) {
        for (j = 0; j < 24; j++) {
            for (i = 0; i < 24; i++) {
                if (g_SeqVoices[i][0xD] == 1 && g_SeqVoices[i][5] >= j && g_SeqVoices[i][5] < min) {
                    min = g_SeqVoices[i][5];
                    best = i;
                }
            }
            if (prio >= g_SeqVoices[best][0xF]) {
                for (j = 0; j < 24; j++) {
                    if (min < g_SeqVoices[j][5] && g_SeqVoices[j][5] != 0xFFFF) {
                        g_SeqVoices[j][5]--;
                    }
                }
                s->f_0--;
                ch = best;
                goto end;
            }
            min = 24;
        }
        ch = 0xFF;
        goto end;
    }
    for (i = 0; i < 24; i++) {
        { s32 next = s->f_F < 23 ? s->f_F + 1 : 0;
        s->f_F = next;
        if (g_SeqVoices[s->f_F][0] == 0) {
            s->f_D++;
            ch = s->f_F;
            goto end;
        } }
    }
    for (i = 0; i < 24; i++) {
        if (g_SeqVoices[i][4] == 1 && g_SeqVoices[i][0xD] != 1) {
            for (j = i; j < 24; j++) {
                if (g_SeqVoices[j][4] == 1 && g_SeqVoices[j][0xD] != 1 && g_SeqVoices[j][5] < min) {
                    min = g_SeqVoices[j][5];
                    ch = j;
                }
            }
            goto found;
        }
    }
    for (i = 0; i < 24; i++) {
        if (g_SeqVoices[i][0xD] != 1 && g_SeqVoices[i][5] < min) {
            min = g_SeqVoices[i][5];
            ch = i;
        }
    }
found:
    for (j = 0; j < 24; j++) {
        if (min < g_SeqVoices[j][5] && g_SeqVoices[j][5] != 0xFFFF) {
            g_SeqVoices[j][5]--;
        }
    }
    s->f_D++;
    s->f_0--;
end:
    return ch;
}

u8 func_8009E124(u8 ch) {
    Ch_9E124_8009E124 *c;
    u32 found = 0;
    u32 other = found;
    u16 i;
    u16 *r;

    c = ((Ch_9E124_8009E124 *)&g_SeqChannels);
    c += ch;
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[0] == 1 && r[0xD] == 1 && r[0x11] == c->f_20 && r[0x1F] == c->f_5 && r[1] == c->f_2 && r[6] == 1) {
            if (r[3] == ch) {
                found |= 1 << i;
            } else {
                other |= 1 << i;
            }
        }
    }
    if (found == 0) {
        found = other;
    }
    for (i = 0; i < 24; i++) {
        if (found & (1 << i)) {
            func_8009E4D8(ch, (u8)i);
            g_SeqVoices[i][4] = 1;
        }
    }
    c->f_C += 4;
    return i;
}

u8 Seq_NoteOff(u8 ch) {
    struct S_D_800F5AC0_8009E2DC *c = ((struct S_D_800F5AC0_8009E2DC *)&g_SeqChannels);
    u16 i;
    u16 *r;
    c += ch;
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[0] == 1 && r[0xD] == 0 && r[3] == ch && r[0x11] == c->f_20 && r[2] == (c->f_0 & 0xF) && r[1] == c->f_2) {
            if (r[6] != 0) {
                if (r[0xC] == 0) {
                    r[4] = 1;
                } else {
                    r[0xC] = 0;
                }
            } else {
                r[4] = 1;
                r[0xC] = 0;
            }
            func_8009E4D8(ch, (u8)i);
        }
    }
    c->f_C += 3;
    return ch;
}

void func_8009E434(s32 arg0, s32 arg1)
{
  u32 temp_a1;
  void *temp_a2;
  temp_a2 = &g_SeqChannels;
  temp_a2 = ((arg0 & 0xFF) * 0x120) + temp_a2;
  temp_a1 = arg1 & 0xFF;
  if (temp_a1 < 0x10U)
  {
    *((u16 *) (((s8 *) temp_a2) + 0xDA)) = (u16) ((*((u16 *) (((s8 *) temp_a2) + 0xDA))) | (1 << temp_a1));
    return;
  }
  *((u16 *) (((s8 *) temp_a2) + 0xDC)) = (u16) ((*((u16 *) (((s8 *) temp_a2) + 0xDC))) | (1 << (temp_a1 - 0x10)));
}

void func_8009E490(s32 a0, u8 bit) {
    S_F75C0 *p = &D_800F75C0;
    if (bit < 16) {
        p->unk14 |= 1 << bit;
    } else {
        p->unk16 |= 1 << (bit - 16);
    }
}

void func_8009E4D8(s32 arg0, s32 arg1)
{
  u32 temp_a1;
  void *temp_a2;
  temp_a2 = &g_SeqChannels;
  temp_a2 = ((arg0 & 0xFF) * 0x120) + temp_a2;
  temp_a1 = arg1 & 0xFF;
  if (temp_a1 < 0x10U)
  {
    *((u16 *) (((s8 *) temp_a2) + 0xDE)) = (u16) ((*((u16 *) (((s8 *) temp_a2) + 0xDE))) | (1 << temp_a1));
    return;
  }
  *((u16 *) (((s8 *) temp_a2) + 0xE0)) = (u16) ((*((u16 *) (((s8 *) temp_a2) + 0xE0))) | (1 << (temp_a1 - 0x10)));
}

u8 func_8009E534(u8 a, u8 b, u8 c)
{
  if (a == 0xFF)
  {
    a = 1;
  }
  else
  {
    D_800B4DF0 += b * 16;
    a = 0;
    if (c >= D_800B4DF0[0])
    {
      a = D_800B4DF0[1] >= c;
    }
    D_800B4DF0 -= b * 16;
  }
  return a;
}

extern u16 D_800B38D0[];

u16 Seq_NotePitch(u8 center, u8 note, s8 fine, u8 bend, u8 range) {
    if (note >= center) {
        s32 d, oct, b;
        d = note - center;
        oct = d / 12;
        d = d % 12;
        b = ((range * (bend - 64)) >> 2) + 0xD0;
        __asm__("" : "=r"(oct) : "0"(oct), "r"(oct));
        return D_800B38D0[d * 16 + b + fine] << oct;
    } else {
        s32 d, b;
        d = center - note;
        return D_800B38D0[(12 - d % 12) * 16 + (b = ((range * (bend - 64)) >> 2) + 0xD0) + fine] >> (d / 12 + 1);
    }
}

u16 Seq_NoteVolume(u8 ch, u8 b, u8 c) {
    Ch_9E6B4_8009E6B4 *p;
    s16 t;

    p = ((Ch_9E6B4_8009E6B4 *)&g_SeqChannels);
    p += ch;
    t = ((*(u8 * *)&D_800B4DE0)[0xE] * D_800B4DE8[1] * D_800E1860[p->f_3 + 2] * D_800B4DF0[0xB] >> 14) * D_800B4190[c + ((b >> 1) & 0x7E)] >> 7;
    if (D_800B4DF0[0xA] != 0) {
        t = ((s16)t >> 7) | (D_800B4DF0[0xA] << 8);
    }
    return t;
}

u8 func_8009E784(u8 cmd, u8 n)
{
  (*(Ev_8009E784_8009E784 * *)&D_800B4DF0) += n;
  if (cmd == 4)
  {
    cmd = (*(Ev_8009E784_8009E784 * *)&D_800B4DF0)->f_C;
  }
  else
  {
    cmd = D_800B3D90[((*(Ev_8009E784_8009E784 * *)&D_800B4DF0)->f_C >> 2) + ((D_800B4DE8[2] >> 2) * 32)];
    cmd = D_800B3D90[(cmd >> 2) + (((*(u8 * *)&D_800B4DE0)[4] >> 2) * 32)];
  }
  (*(Ev_8009E784_8009E784 * *)&D_800B4DF0) -= n;
  return cmd;
}

typedef struct { u8 pad0[0x14]; s32 f_14; u8 pad18[4]; s32 f_1C; s32 f_20; } Bank_8009E82C;
typedef struct { s32 f_0; Bank_8009E82C *f_4; s32 f_8; } Ent_8009E82C;
typedef struct { u8 pad0[3]; u8 f_3; u8 pad4[4]; Bank_8009E82C *f_8; } S_F75C0_8009E82C;
extern S_F75C0_8009E82C D_800F75C0_9E82C asm("D_800F75C0");
extern Ent_8009E82C g_SoundBanks_9E82C[] asm("g_SoundBanks");
extern Bank_8009E82C *D_800E1870_9E82C asm("D_800E1870");
extern u16 *D_800E186C_9E82C asm("D_800E186C");
extern u8 *D_800E1858_9E82C asm("D_800E1858");
extern u8 *D_800E1860_9E82C asm("D_800E1860");

void *func_8009E82C(u8 idx, u8 prog, u8 tone) {
    S_F75C0_8009E82C *s = &D_800F75C0_9E82C;
    Ent_8009E82C *e;
    Bank_8009E82C *b;
    u16 *t;
    register u16 *p asm("$5");

    { Ent_8009E82C *tb = g_SoundBanks_9E82C; e = &tb[(u8)idx]; }
    b = e->f_4;
    s->f_8 = b;
    D_800E1870_9E82C = b;
    D_800E186C_9E82C = t = (u16 *)((u8 *)b + b->f_1C);
    if (b->f_20 != -1 && !(idx & 0x80) && s->f_3 != 0 && e->f_0 == 1 && t[0] >= (u8)prog) {
        { register s32 o asm("$2") = (u8)prog * 2; p = (u16 *)(o + (s32)t); }
        if ((u16)p[1] != 0xFFFF && t[p[1] / 2] >= (u8)tone) {
            D_800E1858_9E82C = (u8 *)b + b->f_20;
            { register u8 *w asm("$2") = (u8 *)b + b->f_14; D_800E1860_9E82C = w; }
            { register u8 *r asm("$3"); register s32 h asm("$3") = p[1] / 2; register s32 k asm("$2") = (u8)tone; u16 x = t[k + h + 1]; r = (u8 *)b + b->f_1C; return r + x; }
        }
    }
    return NULL;
}

/* Sequencer: claims a free channel (of 24) for a new sequence and initialises it;
 * returns its index or -1.
 */
s16 SeqDriver_AllocChannel(u8 a, u8 b, u8 c)
{
  s16 r = -1;
  struct S_D_800F5AC0_8009E940 *base = ((struct S_D_800F5AC0_8009E940 *)&g_SeqChannels);
  S_G_8009E940_8009E940 *g = (S_G_8009E940_8009E940 *) (&D_800F75C0);
  struct S_D_800F5AC0_8009E940 *ch;
  void *p;
  s16 i;
  p = func_8009E82C(a, b, c);
  if (p != 0)
  {
    ch = base;
    for (i = 0; i < 24; i++, ch++)
    {
      if (((*((u32 *) (&ch->f_24))) & 0xFF00FF) == 0)
      {
        ch->f_26 = 1;
        ch->f_27 = 1;
        ch->f_25 = 0;
        ch->f_114 = 0;
        ch->f_E3 = 0;
        ch->f_10 = p;
        ch->f_C = 0;
        ch->f_20 = a;
        ((u8 *) ch)[0x1D] = b;
        ((u8 *) ch)[0x1F] = c;
        r = g->f_1F;
        if (r != 0)
        {
          if (g->f_22)
          {
            ch->f_E6 = 1;
            g->f_1F = 0;
          }
          else
          {
            ch->f_E6 = 1;
            g->f_1F = 0;
          }
        }
        ch->f_E2 = 0;
        ch->f_31 = 0;
        ch->f_33 = 0;
        ch->f_EC = 0;
        ch->f_EA = 0;
        ch->f_E5 = 0;
        r = i;
        if (g->f_1E != 0)
        {
          ch->f_E5 = 1;
          ch->f_EA = g->f_22;
          ch->f_EC = g->f_24;
          ch->f_E8 = g->f_20;
          g->f_20 = 0;
          g->f_24 = 0;
          g->f_22 = 0;
          g->f_1E = 0;
        }
        break;
      }
    }

  }
  return r;
}

void Seq_EndOfTrack(u8 ch) {
    Ch_9EAAC_8009EAAC *c;
    s16 i;

    c = ((Ch_9EAAC_8009EAAC *)&g_SeqChannels);
    c += ch;
    if (c->f_27 != 0) {
        c->f_E3 = 1;
        c->f_114 = 0;
        c->f_27 = 0;
        c->f_100 = 0;
        c->f_101 = 0;
        c->f_E5 = 0;
        c->f_E6 = 0;
    } else {
        c->f_C = 0x110;
        c->f_25 = 0;
    }
    for (i = 0; i < 24; i++) {
        if (g_SeqVoices[i][3] == ch && g_SeqVoices[i][0xD] == 0) {
            g_SeqVoices[i][0xA] = 0;
            g_SeqVoices[i][0x1C] = 0x40;
        }
    }
    c->f_1 = c->f_0;
}

typedef struct { u8 pad0[0xC]; s32 f_C; u8 *f_10; u8 pad14[0xF0]; u16 f_104; u8 pad106[0x1A]; } SeqCh_SetTempo;

/* MIDI meta event 0x51: read the 16-bit little-endian tempo at stream+2 and skip the 4-byte event. */
void Seq_SetTempo(u8 ch) {
    SeqCh_SetTempo *c = (SeqCh_SetTempo *)&g_SeqChannels;
    u8 *p;
    c += ch;
    p = c->f_10 + c->f_C;
    c->f_104 = (p[3] << 8) | p[2];
    c->f_C += 4;
}

void Seq_ProgramChange(s32 arg0)
{
  void *temp_a1;
  temp_a1 = &g_SeqChannels;
  temp_a1 = ((arg0 & 0xFF) * 0x120) + temp_a1;
  if ((*((u8 *) (((s8 *) temp_a1) + 0x27))) == 0)
  {
    *((u8 *) (((s8 *) D_800B4DE0) + 2)) = (u8) (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) temp_a1) + 0xC))) + D_800E1854)) + 1)));
    *((s8 *) (((s8 *) D_800B4DE0) + 0xA)) = 0x40;
    *((s8 *) (((s8 *) D_800B4DE0) + 0xB)) = 0x40;
  }
  *((s32 *) (((s8 *) temp_a1) + 0xC)) = (s32) ((*((s32 *) (((s8 *) temp_a1) + 0xC))) + 2);
}

void Seq_CmdModulation(u8 ch) {
    Ch_9EC48_8009EC48 *c;
    u16 i;
    u16 *r;
    u16 *q;
    u8 *p;
    u16 t;

    c = ((Ch_9EC48_8009EC48 *)&g_SeqChannels);
    c += ch;
    if (c->f_27 != 0) {
        for (i = 0; i < 24; i++) {
            r = g_SeqVoices[i];
            if (r[0xD] == 1 && r[0x1F] == (p = (u8 *)(c->f_C + D_800E1854))[3] && r[1] == p[4] && r[0x11] == c->f_20 && r[3] == ch && r[0] == 1) {
                t = p[2];
                r[0xA] = 1;
                r[0xB] = t;
            }
        }
        c->f_C += 5;
        return;
    }
    (*(u8 * *)&D_800B4DE0)[9] = ((u8 *)(c->f_C + D_800E1854))[2];
    for (i = 0; i < 24; i++) {
        q = g_SeqVoices[i];
        if (q[2] == (c->f_0 & 0xF) && q[0x11] == c->f_20 && q[3] == ch && q[0] == 1) {
            t = ((u8 *)(c->f_C + D_800E1854))[2];
            q[0xA] = 1;
            q[0xB] = t;
        }
    }
    c->f_C += 3;
}

void Seq_CmdModRate(u8 ch) {
    Ch_9EE28_8009EE28 *c;
    u16 i;
    u16 *r;
    u16 *q;
    u16 t;

    c = ((Ch_9EE28_8009EE28 *)&g_SeqChannels);
    c += ch;
    t = 240 / (60 - ((u8 *)(c->f_C + D_800E1854))[2] * 58 / 127);
    if (c->f_27 != 0) {
        for (i = 0; i < 24; i++) {
            r = g_SeqVoices[i];
            if (r[2] == (c->f_0 & 0xF) && r[0x1F] == ((u8 *)(c->f_C + D_800E1854))[3] && r[1] == ((u8 *)(c->f_C + D_800E1854))[4] && r[0x11] == c->f_20 && r[3] == ch && r[0] == 1) {
                r[0x1E] = t;
            }
        }
        c->f_C += 5;
        return;
    }
    (*(u8 * *)&D_800B4DE0)[0xC] = t;
    for (i = 0; i < 24; i++) {
        q = g_SeqVoices[i];
        if (q[2] == (c->f_0 & 0xF) && q[0x11] == c->f_20 && q[3] == ch && q[0] == 1) {
            q[0x1E] = t;
        }
    }
    c->f_C += 3;
}

void Seq_CmdPortamento(u8 ch) {
    Ch_9F060_8009F060 *c;
    u16 i;
    u16 *r;
    struct S_D_800F75C0_8009F060 *s;

    c = ((Ch_9F060_8009F060 *)&g_SeqChannels);
    s = ((struct S_D_800F75C0_8009F060 *)&D_800F75C0);
    c += ch;
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[0] == 1 && r[0xD] == 1 && r[0x11] == c->f_20 && r[0x1F] == ((u8 *)(c->f_C + D_800E1854))[4] && r[1] == ((u8 *)(c->f_C + D_800E1854))[5] && r[3] == ch) {
            if (r[0x31] != 0) {
                r[0x27] = c->f_118;
            }
            r[0x22] = 1;
            r[0x30] = ((u8 *)(c->f_C + D_800E1854))[3];
            r[0x31] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
            r[0x32] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
        }
    }
    c->f_C += 6;
}

void Seq_CmdVolume(u8 ch) {
    Ch_9F218_8009F218 *c;
    struct S_D_800F75C0_8009F218 *s;
    u16 i;
    u16 *r;
    u16 *q;

    c = ((Ch_9F218_8009F218 *)&g_SeqChannels);
    c += ch;
    s = ((struct S_D_800F75C0_8009F218 *)&D_800F75C0);
    if (c->f_27 != 0) {
        for (i = 0; i < 24; i++) {
            r = g_SeqVoices[i];
            if (r[0] == 1 && r[0xD] == 1 && r[0x11] == c->f_20 && r[0x1F] == ((u8 *)(c->f_C + D_800E1854))[4] && r[1] == ((u8 *)(c->f_C + D_800E1854))[5] && r[3] == ch) {
                r[0x23] = 1;
                r[0x28] = ((u8 *)(c->f_C + D_800E1854))[3];
                r[0x29] = r[0x16];
                r[0x2A] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
                r[0x2B] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
            }
        }
        c->f_C += 6;
    } else {
        (*(u8 * *)&D_800B4DE0)[3] = ((u8 *)(c->f_C + D_800E1854))[2];
        (*(u8 * *)&D_800B4DE0)[0xE] = D_800B4DE4[0] * (*(u8 * *)&D_800B4DE0)[3] >> 7;
        for (i = 0; i < 24; i++) {
            q = g_SeqVoices[i];
            if (q[0] == 1 && q[2] == (c->f_0 & 0xF) && q[0x11] == c->f_20 && q[4] != 1 && q[3] == ch) {
                c->f_3 = ((u8 *)q)[0x2C];
                *(u16 *)((*(u8 * *)&D_800E1874) + (i << 4)) = Seq_NoteVolume(ch, func_8009E784(0, ((u8 *)q)[0xE]), 0);
                *(u16 *)((*(u8 * *)&D_800E1874) + (i << 4) + 2) = Seq_NoteVolume(ch, func_8009E784(0, ((u8 *)q)[0xE]), 1);
            }
        }
        c->f_C += 3;
    }
}

void Seq_CmdPan(u8 ch) {
    Ch_9F568_8009F568 *c;
    struct S_D_800F75C0_8009F568 *s;
    u16 i;
    u16 *r;
    u16 *q;

    c = ((Ch_9F568_8009F568 *)&g_SeqChannels);
    c += ch;
    s = ((struct S_D_800F75C0_8009F568 *)&D_800F75C0);
    if (c->f_27 != 0) {
        for (i = 0; i < 24; i++) {
            r = g_SeqVoices[i];
            if (r[0] == 1 && r[0xD] == 1 && r[0x11] == c->f_20 && r[0x1F] == ((u8 *)(c->f_C + D_800E1854))[4] && r[1] == ((u8 *)(c->f_C + D_800E1854))[5] && r[3] == ch) {
                r[0x24] = 1;
                r[0x2C] = ((u8 *)(c->f_C + D_800E1854))[3];
                r[0x2D] = r[0x26];
                r[0x2E] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
                r[0x2F] = (((u8 *)(c->f_C + D_800E1854))[2] << 2) * s->f_3E / 60;
            }
        }
        c->f_C += 6;
    } else {
        (*(u8 * *)&D_800B4DE0)[4] = ((u8 *)(c->f_C + D_800E1854))[2];
        for (i = 0; i < 24; i++) {
            q = g_SeqVoices[i];
            if (q[2] == (c->f_0 & 0xF) && q[0x11] == c->f_20 && q[3] == ch && q[4] != 1 && q[0] == 1) {
                q[0x26] = ((u8 *)(c->f_C + D_800E1854))[2];
                c->f_3 = ((u8 *)q)[0x2C];
                *(u16 *)((*(u8 * *)&D_800E1874) + (i << 4)) = Seq_NoteVolume(ch, func_8009E784(0, ((u8 *)q)[0xE]), 0);
                *(u16 *)((*(u8 * *)&D_800E1874) + (i << 4) + 2) = Seq_NoteVolume(ch, func_8009E784(0, ((u8 *)q)[0xE]), 1);
            }
        }
        c->f_C += 3;
    }
}

void Seq_CmdSustain(u8 ch) {
    struct S_D_800F5AC0_8009F8A8 *c = ((struct S_D_800F5AC0_8009F8A8 *)&g_SeqChannels);
    u16 i;
    u16 *r;
    c += ch;
    ((u8 *)D_800B4DE0)[0xB] = ((u8 *)(c->f_C + D_800E1854))[2];
    if (((u8 *)(c->f_C + D_800E1854))[2] == 0) {
        for (i = 0; i < 24; i++) {
            r = g_SeqVoices[i];
            if (r[2] == (c->f_0 & 0xF) && r[0x11] == c->f_20 && r[3] == ch && r[6] != 0) {
                if (((u8 *)D_800B4DE0)[0xB] == 0) {
                    func_8009E4D8(ch, (u8)i);
                    r[4] = 1;
                } else {
                    r[0xC] = 1;
                }
            }
        }
    }
    c->f_C += 3;
}

void Seq_CmdLoop(u8 ch) {
    Ch_9FA28_8009FA28 *c;
    u8 *p;

    c = ((Ch_9FA28_8009FA28 *)&g_SeqChannels);
    c += ch;
    c->f_33 = 1;
    c->f_E2 = 1;
    p = (u8 *)(c->f_C + D_800E1854);
    if (p[4] != 0) {
        if (c->f_31 == p[4]) {
            c->f_33 = 0;
            c->f_31 = 0;
            c->f_E2 = 0;
        } else {
            c->f_28 = (p[3] << 8) + p[2];
            c->f_35 = *(u8 *)(D_800E1854 + c->f_28);
            c->f_31++;
        }
    } else {
        c->f_28 = p[3] << 8;
        c->f_28 |= ((u8 *)(c->f_C + D_800E1854))[2];
        c->f_35 = *(u8 *)(D_800E1854 + c->f_28);
    }
    c->f_C += 5;
}

void Seq_CmdNrpnData(u8 ch) {
    Ch_9FB08_8009FB08 *c;
    u16 i;
    u16 *r;

    c = ((Ch_9FB08_8009FB08 *)&g_SeqChannels);
    c += ch;
    switch (c->f_11B) {
    case 0:
        c->f_11B = 0;
        c->f_119 = c->f_3;
        goto end;
    case 4:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 &= 0xFF;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 |= (0x7F - c->f_3) << 8;
        break;
    case 5:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 &= 0xFF;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 = (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 | ((0x7F - c->f_3) << 8) | 0x8000;
        break;
    case 6:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 &= 0xFF0F;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 |= ((0x7F - c->f_3) >> 3) << 4;
        break;
    case 7:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 &= 0xFFF0;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6 |= c->f_3 >> 3;
        break;
    case 8:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 &= 0x3F;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 |= (0x7F - c->f_3) << 6;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 |= 0x4000 - c->f_11E;
        break;
    case 9:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 &= 0x3F;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 = (u16)((*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 | ((0x7F - c->f_3) << 6)) | 0x8000;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 |= 0x4000 - c->f_11E;
        break;
    case 10:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 &= 0xFFC0;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 |= (0x7F - c->f_3) >> 2;
        break;
    case 11:
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 &= 0xFFC0;
        (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 = (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8 | ((0x7F - c->f_3) >> 2) | 0x20;
        break;
    case 12:
        if (c->f_3 >= 0x41) {
            c->f_11E = 0x4000;
        } else {
            c->f_11E = 0;
        }
        break;
    case 15:
        func_800A2030(c->f_3);
        goto end;
    case 16:
        func_800A20F4(c->f_3, c->f_3);
        goto end;
    case 17:
        func_800A222C(c->f_3);
        goto end;
    case 18:
    case 19:
        func_800A2184(c->f_3);
        goto end;
    case 1:
    case 2:
    case 3:
    case 13:
    case 14:
        break;
    }
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[1] == 1 && r[2] == (c->f_0 & 0xF) && r[0xD] == 0 && r[3] == ch && (c->f_11C == 0xFF || r[7] == c->f_11C)) {
            ((SpuV_9FB08_8009FB08 *)((u8 *)(*(SpuV_9FB08_8009FB08 * *)&D_800E1874) + (i << 4)))->f_8 = (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_6;
            ((SpuV_9FB08_8009FB08 *)((u8 *)(*(SpuV_9FB08_8009FB08 * *)&D_800E1874) + (i << 4)))->f_A = (*(Adsr_9FB08_8009FB08 * *)&D_800B4DF0)->f_8;
        }
    }
end:
    c->f_C += 3;
}



void Seq_CmdNrpnLsb(u8 i) {
    S_F5AC0_8009FEB4 *p = ((S_F5AC0_8009FEB4 *)&g_SeqChannels);
    p += i;
    switch (p->f_11A) {
    case 0:
        p->f_11B = 0;
        p->f_119 = p->f_3;
        break;
    case 1:
        p->f_11B = p->f_3;
        break;
    case 2:
        p->f_11B = p->f_3;
        break;
    }
    p->f_C += 3;
}

void Seq_CmdNrpnMsb(u8 ch) {
    struct S_D_800F5AC0_8009FF38 *c = ((struct S_D_800F5AC0_8009FF38 *)&g_SeqChannels);

    c += ch;
    switch (c->f_3) {
    case 0x14:
        c->f_11A = 0;
        c->f_11B = 0;
        c->f_35 = c->f_0;
        c->f_28 = c->f_C;
        break;
    case 0x1E:
        if (c->f_119 == 0x7F) {
            c->f_33 = 1;
        } else if (c->f_31 >= c->f_119) {
            c->f_28 = 0;
            c->f_33 = 0;
            c->f_31 = 0;
        } else {
            c->f_31++;
            c->f_33 = 1;
        }
        c->f_11A = 0;
        break;
    case 0x10:
        c->f_11A = 1;
        break;
    case 0x7F:
        c->f_11A = 2;
        c->f_11C = 0xFF;
        break;
    case 0 ... 15:
        c->f_11A = 2;
        c->f_11C = c->f_3;
        break;
    }
    c->f_C += 3;
}

void Seq_PitchBend(u8 ch) {
    S_Ch_800A0050_800A0050 *c = ((S_Ch_800A0050_800A0050 *)&g_SeqChannels);
    u16 i;
    u16 *r;
    c += ch;
    ((u8 *)D_800B4DE0)[0xA] = ((u8 *)(c->f_C + D_800E1854))[1];
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[2] == (c->f_0 & 0xF) && r[0x11] == c->f_20 && r[3] == ch && r[0] == 1) {
            *(u16 *)((u8 *)D_800E1874 + (i << 4) + 4) = Seq_NotePitch(((u8 *)r)[0x40], ((u8 *)r)[2], ((s8 *)r)[0x36], ((u8 *)D_800B4DE0)[0xA], ((u8 *)r)[0x3A]);
            r[0x1C] = ((u8 *)(c->f_C + D_800E1854))[1];
        }
    }
    c->f_C += 2;
}

/* Reads a MIDI variable-length delta time for channel ch (up to 4 bytes from the sequence data
 * at D_800E1854 + c->pos) into +0x114, then converts it to the playback rate: ticks * 10 scaled
 * by the channel tempo (+0x104 * +0x106, 60/480 when +0x27) over D_800F75C0+0x3E * 60, carrying the
 * rounding remainder in +0x10C/+0x108. */
void Seq_ReadDeltaTime(u8 ch) {
    Ch_A01BC_800A01BC *c;
    struct S_D_800F75C0_800A01BC *s;
    u16 i = 0;
    s32 b;
    s32 t;
    s32 q;
    s32 v;
    s32 r;

    c = ((Ch_A01BC_800A01BC *)&g_SeqChannels);
    s = ((struct S_D_800F75C0_800A01BC *)&D_800F75C0);
    c += ch;
    for (; i < 4; i++) {
        b = *(u8 *)(D_800E1854 + c->f_C++);
        c->f_114 <<= 7;
        if (!(b & 0x80)) {
            c->f_114 = b | c->f_114;
            break;
        }
        c->f_114 |= b & 0x7F;
    }
    if (c->f_27 != 0) {
        c->f_104 = 60;
        c->f_106 = 480;
    }
    if (c->f_104 == 0) {
        return;
    }
    t = c->f_114 * 10;
    c->f_110 = t;
    q = c->f_104 * c->f_106 * 10 / (s->f_3E * 60);
    if (c->f_108 != 0) {
        c->f_108 = 0;
        v = t - (q - c->f_10C);
    } else {
        v = t + c->f_10C;
    }
    r = v % q;
    if (q < r * 2) {
        c->f_110 = v + (q - r);
        c->f_108 = 1;
    } else {
        c->f_110 = v - r;
    }
    c->f_10C = v % q;
    c->f_114 = c->f_110 / q;
}

/* Sequencer: reads the next event with MIDI-style running status.
 */
typedef struct { u8 f_0; u8 f_1; u8 f_2; u8 f_3; u8 pad4; u8 f_5; u8 pad6[6]; s32 f_C; u8 pad10[0x110]; } Ch_A03D4;
/* Reads the status byte of the next event of channel ch (MIDI running status: a data byte
 * reuses the previous status +1 and steps the position back) and its three data bytes into
 * +2/+3/+5. */
s32 SeqDriver_ReadEvent(u8 ch) {
    Ch_A03D4 *c;
    u8 b;

    c = (Ch_A03D4 *)&g_SeqChannels;
    c += ch;
    b = *(u8 *)(D_800E1854 + c->f_C);
    if (b & 0x80) {
        c->f_1 = b;
        c->f_0 = *(u8 *)(D_800E1854 + c->f_C);
    } else {
        c->f_C--;
        c->f_0 = c->f_1;
    }
    c->f_2 = *(u8 *)(c->f_C + D_800E1854 + 1);
    c->f_3 = *(u8 *)(c->f_C + D_800E1854 + 2);
    c->f_5 = *(u8 *)(c->f_C + D_800E1854 + 3);
    return 0;
}

void Seq_ReleaseFinishedVoices(void) {
    struct S_D_800F75C0_800A048C *s;
    Ch_A048C_800A048C *c;
    u16 i;
    u16 j;
    u16 *r;

    s = ((struct S_D_800F75C0_800A048C *)&D_800F75C0);
    c = ((Ch_A048C_800A048C *)&g_SeqChannels);
    for (i = 0; i < 24; i++, c++) {
        if (c->f_E3 == 1 && c->f_26 == 1) {
            for (j = 0; j < 24; j++) {
                if (g_SeqVoices[j][3] == i) {
                    goto next;
                }
            }
            c->f_114 = 0;
            c->f_26 = 0;
            c->f_27 = 0;
            c->f_E3 = 0;
            c->f_EC = 0;
            c->f_EA = 0;
            c->f_100 = 0;
            c->f_101 = 0;
            c->f_26 = 0;
            s->f_1E = 0;
        }
    next:;
    }
    for (i = 0; i < 24; i++) {
        if ((*(u16 *)((u8 *)(*(V16_A048C_800A048C * *)&D_800E1874) + (i << 4) + 0xC) & 0x7FFF) < 0x10 && (r = g_SeqVoices[i])[4] == 1) {
            if (r[0xD] != 0) {
                s->f_D -= s->f_D != 0;
            }
            for (j = 0; j < 24; j++) {
                if (g_SeqVoices[i][5] < g_SeqVoices[j][5] && g_SeqVoices[j][5] != 0xFFFF) {
                    g_SeqVoices[j][5]--;
                }
            }
            for (j = 0; j < 51; j++) {
                g_SeqVoices[i][j] = 0;
            }
            g_SeqVoices[i][3] = 0xFFFF;
            g_SeqVoices[i][0x13] = 0xFFFF;
            g_SeqVoices[i][0x12] = 0xFFFF;
            g_SeqVoices[i][0x11] = 0xFFFF;
            g_SeqVoices[i][5] = 0xFFFF;
            g_SeqVoices[i][0x27] = 0x78;
            s->f_0 -= s->f_0 != 0;
        }
    }
}

void Spu_SetDmaCallback(s32 arg0) {
    DMACallback(4, arg0);
}

/* Called when an SPU transfer finished: starts the next queued upload (g_SpuUploadQueue, count
 * D_800F75C0+0x35; bit 31 of the destination selects transfer mode 1), dropping empty entries;
 * when the queue is empty runs the completion callback D_800B4DEC if one is armed. */
void Spu_ProcessUploadQueue(void) {
    struct S_D_800F75C0_800A0700 *s;
    u16 i;
    u16 j;
    u32 d;

    (*(S_A0700_800A0700 * *)&D_800E1874)->f_1AA &= 0xFFCF;
    s = ((struct S_D_800F75C0_800A0700 *)&D_800F75C0);
    s->busy = 0;
loop:
    if (s->qcount != 0) {
        d = g_SpuUploadQueue[0].v[1];
        if ((d & 0x7FFFFFFF) == 0) {
            for (i = 0; i < s->qcount - 1; i++) {
                for (j = 0; j < 3; j++) {
                    g_SpuUploadQueue[i].v[j] = g_SpuUploadQueue[i + 1].v[j];
                }
            }
            s->qcount--;
            goto loop;
        } else {
            if ((s32)d < 0) {
                Spu_StartTransfer(1, g_SpuUploadQueue[0].v[0], d & 0x7FFFFFFF, g_SpuUploadQueue[0].v[2]);
            } else {
                Spu_StartTransfer(0, g_SpuUploadQueue[0].v[0], d, g_SpuUploadQueue[0].v[2]);
            }
            for (i = 0; i < s->qcount - 1; i++) {
                for (j = 0; j < 3; j++) {
                    g_SpuUploadQueue[i].v[j] = g_SpuUploadQueue[i + 1].v[j];
                }
            }
            s->qcount--;
            return;
        }
    }
    if (s->f_34 != 0) {
        D_800B4DEC();
    }
}

// Points voice v at its 16-byte sample header (sound bank or channel data) and
// writes its left/right volumes to the SPU shadow table.
void Seq_VoiceBindSample(u16 v)
{
  Vc_A0900_800A0900 **new_var;
  Vc_A0900_800A0900 *rv;
  S_Ch_800A0900_800A0900 *c;
  c = ((S_Ch_800A0900_800A0900 *)&g_SeqChannels);
  rv = ((Vc_A0900_800A0900 *)&g_SeqVoices);
  rv += (u16) v;
  c += rv->w[3];
  if (rv->w[0xD] != 0)
  {
    D_800E1870 = (S_Bank_800A0900_800A0900 *) g_SoundBanks[c->f_20][1];
    D_800B4DE0 = (((u8 *) g_SoundBanks[c->f_20][1]) + D_800E1870->f_20) + ((rv->w[2] * 16) + 16);
  }
  else
  {
    D_800B4DE0 = c->f_10 + (((*(new_var = &rv))->w[2] * 16) + 16);
  }
  ((Vc_A0900_800A0900 *)&g_SeqVoices)[(u16) v].w[0x14] = ((u8 *) D_800B4DE0)[0xE];
  *((u16 *) ((*(u8 * *)&D_800E1874) + (((u16) v) << 4))) = Seq_VoiceVolume((u16) v, 0);
  *((u16 *) (((*(u8 * *)&D_800E1874) + (((u16) v) << 4)) + 2)) = Seq_VoiceVolume((u16) v, 1);
}

s16 Seq_VoiceVolume(u16 i, s32 ch) {
    s16 t;
    t = (g_SeqVoices[i][0x14] * g_SeqVoices[i][0x15] * g_SeqVoices[i][0x16] * g_SeqVoices[i][0x17] >> 14) * g_SeqVoices[i][(u16)ch + 0x18] >> 7;
    if (g_SeqVoices[i][0x25] != 0) {
        t = ((s16)t >> 7) | (g_SeqVoices[i][0x25] << 8);
    }
    return t;
}

u8 Sound_LerpU8(u8 a, u8 b, u8 c, u8 d) {
    return a + ((b - a) * d) / c;
}

void Seq_UpdateChannelFades(u8 ch) {
    Ch_A0B64_800A0B64 *c;
    s16 n;
    u8 i;
    u8 j;

    c = ((Ch_A0B64_800A0B64 *)&g_SeqChannels);
    c += ch;
    n = 0;
    if (c->f_38 == 0) {
        return;
    }
    if (c->m[5][0] != 0) {
        D_800B4DE4 = c->f_10;
        if (D_800B4DE4[0] != c->m[6][0]) {
            if (c->m[7][0] != 0) {
                D_800B4DE4[0] = Sound_LerpU8(c->m[6][0], c->m[9][0], c->m[8][0], c->m[7][0]);
                c->m[7][0]--;
            } else {
                D_800B4DE4[0] = c->m[6][0];
            }
            func_800A2428(ch, D_800B4DE4[0]);
            n++;
        }
    }
    (*(u8 * *)&D_800B4DE0) = c->f_10 + 0x10;
    for (i = 0; i < 16; i++) {
        if ((*(u8 * *)&D_800B4DE0)[3] != c->m[1][i] && c->m[0][i] == 1) {
            if (c->m[2][i] != 0) {
                (*(u8 * *)&D_800B4DE0)[3] = Sound_LerpU8(c->m[1][i], c->m[4][i], c->m[3][i], c->m[2][i]);
                c->m[2][i]--;
            } else {
                (*(u8 * *)&D_800B4DE0)[3] = c->m[1][i];
            }
            func_800A1018(ch, i, (*(u8 * *)&D_800B4DE0)[3]);
            n++;
        }
        (*(u8 * *)&D_800B4DE0) += 0x10;
    }
    if (n == 0) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 16; j++) {
                c->m[i][j] = 0;
            }
        }
        if (c->f_36 != 0) {
            c->f_36 = 0;
            func_800A2B6C(ch, 1);
        }
        c->f_38 = 0;
    }
}

u8 func_800A0DB0(s16 arg0, s8 arg1, s32 arg2, s8 arg3)
{
  s32 temp_a2;
  u8 var_v1;
  void *temp_t0;
  void *temp_v1;
  temp_t0 = &g_SeqChannels;
  temp_t0 = (arg0 * 0x120) + temp_t0;
  temp_a2 = arg2 & 0xFFFF;
  if (temp_a2 == 0xFFFF)
  {
    D_800B4DE4 = *((u8 **) (((s8 *) temp_t0) + 0x10));
    *((s8 *) (((s8 *) temp_t0) + 0x8A)) = 1;
    *((s8 *) (((s8 *) temp_t0) + 0x9A)) = arg3;
    *((s8 *) (((s8 *) temp_t0) + 0xAA)) = arg1;
    *((s8 *) (((s8 *) temp_t0) + 0xBA)) = arg1;
    *((u8 *) (((s8 *) temp_t0) + 0xCA)) = (u8) (*D_800B4DE4);
    var_v1 = *D_800B4DE4;
  }
  else
  {
    D_800B4DE0 = (*((u8 **) (((s8 *) temp_t0) + 0x10))) + ((temp_a2 * 0x10) + 0x10);
    temp_v1 = temp_t0 + temp_a2;
    *((s8 *) (((s8 *) temp_v1) + 0x3A)) = 1;
    *((s8 *) (((s8 *) temp_v1) + 0x4A)) = arg3;
    *((s8 *) (((s8 *) temp_v1) + 0x5A)) = arg1;
    *((s8 *) (((s8 *) temp_v1) + 0x6A)) = arg1;
    *((u8 *) (((s8 *) temp_v1) + 0x7A)) = (u8) (*((u8 *) (((s8 *) D_800B4DE0) + 3)));
    var_v1 = *((u8 *) (((s8 *) D_800B4DE0) + 3));
  }
  *((s8 *) (((s8 *) temp_t0) + 0x38)) = 1;
  return var_v1;
}

/* One step of a volume fade-in or fade-out.
 */
void Sound_UpdateFade(void) {
    S_G_800A0E84_800A0E84 *g = (S_G_800A0E84_800A0E84 *)&D_800F75C0;
    s16 v;
    s32 n;
    s16 l, r;
    if (g->f_26 != 0) {
        if (D_800B4422 == g->f_28) {
            D_800B4422 = 0;
            g->f_26 = 0;
        } else {
            v = g->f_2A * D_800B4422 / g->f_28;
            D_800B4422++;
            func_800A23E0(v, v);
        }
    }
    if (g->f_27 != 0) {
        if (D_800B4422 == g->f_28) {
            D_800B4422 = 0;
            g->f_27 = 0;
        } else {
            n = g->f_28 - D_800B4422;
            l = g->f_2C * n / g->f_28;
            r = g->f_2E * n / g->f_28;
            D_800B4422++;
            func_800A23E0(l, r);
        }
    }
}

void func_800A1018(s16 ch, s16 n, s16 vol) {
    struct S_D_800F5AC0_800A1018 *c = ((struct S_D_800F5AC0_800A1018 *)&g_SeqChannels);
    u16 i;
    u16 *r;
    c += ch;
    D_800B4DE4 = c->f_10;
    D_800B4DE0 = c->f_10 + (n * 16 + 16);
    ((u8 *)D_800B4DE0)[3] = vol;
    ((u8 *)D_800B4DE0)[0xE] = (vol * D_800B4DE4[0]) >> 7;
    for (i = 0; i < 24; i++) {
        r = g_SeqVoices[i];
        if (r[0] == 1 && r[0xD] == 0 && r[0x11] == c->f_20 && r[3] == ch && r[2] == n) {
            Seq_VoiceBindSample(i);
        }
    }
}

s32 Math_MaxS16(s16 a, s16 b) {
    if (b < a) {
        return a;
    }
    return b;
}

s16 func_800A119C(s16 a, s16 b)
{
  s16 r = b;
  if (b & 0x8000)
  {
    r = -b;
    if (r > a)
    {
      r = a;
    }
    r |= 0x8000;
  }
  else
    if (a < b)
  {
    r = a;
  }
  return r;
}

/* Sequencer parameter scaling (note-on, envelope values): a is either a 7-bit value in bits 0-6
   with flag 0x8000 (taken as value << 7, times b & 0x7FFF) or a plain 16-bit value (times b's
   7FFF part); >> 12, then inverted (0x7FFF - x) when b has bit 0x8000. Needs the copy-then-mask of
   a inside the else branch (found by the permuter). */
s16 Seq_ScaleParam(u16 a, s32 b) {
    s32 x;
    s32 y;
    s16 r;

    if (a & 0x8000) {
        y = (a & 0x7F) << 7;
        x = b & 0x7FFF;
    } else {
        x = a;
        x = (u16)x;
        y = b & 0x7FFF;
    }
    x = (x * y) >> 12;
    r = x;
    if (b & 0x8000) {
        r = 0x7FFF - x;
    }
    return r;
}

/* Starts a DMA transfer of `size` bytes between main RAM and SPU RAM.
 */
typedef struct { u8 pad0[0x1A6]; u16 f_1A6; u8 pad1A8[2]; u16 f_1AA; } SpuReg_A124C;
typedef struct { u8 pad0[0x1C]; u16 f_1C; } Snd_A124C;
extern SpuReg_A124C *D_800E1874_ST asm("D_800E1874");
extern Snd_A124C D_800F75C0_ST asm("D_800F75C0");
/* Starts a DMA transfer between main RAM (src) and SPU RAM (addr): mode 0 writes to the SPU,
 * otherwise reads. Sets the SPU transfer address and mode bits in SPUCNT, enables the SPU DMA
 * channel in DPCR, then programs the channel (size in 64-byte blocks, rounded up) and starts it.
 * Returns the block count. */
s16 Spu_StartTransfer(u8 mode, u32 src, u32 size, u32 addr) {
    Snd_A124C *s = &D_800F75C0_ST;
    u32 t;
    s32 bits;
    s32 dpcr;
    s32 dir;
    s16 n;
    int rem;

    dir = 0;
    t = 0;
    if (mode != dir) {
        bits = 0x70;
        dpcr = 0x22000000;
        dir = t;
    } else {
        bits = 0x60;
        dpcr = 0x20000000;
        dir = 1;
    }
    t = D_800E1874_ST->f_1AA;
    D_800E1874_ST->f_1A6 = addr >> 3;
    s->f_1C = 1;
    t &= 0xFFCF;
    bits |= t;
    t = bits;
    Sound_BusyWait(1);
    D_800E1874_ST->f_1AA = t;
    Sound_BusyWait(1);
    *D_800E1850 = (*D_800E1850 & 0xF0FFFFFF) | dpcr;
    Sound_BusyWait(1);
    *D_800E1840 = src;
    rem = size & 0x3F;
    n = (size >> 6) + (rem != 0);
    *D_800E1844 = (n << 16) | 0x10;
    t = dir | 0x01000200;
    *D_800E1848 = t;
    return n;
}

s32 func_800A1378(s32 arg0) {
    if (arg0 < 2) {
        D_800B4424 = arg0;
    }
    return D_800B4424;
}

s32 func_800A1398(void) {
    u32 i = 0;
    while (func_800A1378(2) != 0) {
        if (i > 0x89CFF) {
            return 1;
        }
        i++;
    }
    return 0;
}

void Sound_Init(void) {
    struct S_D_800F75C0_800A13EC *s = ((struct S_D_800F75C0_800A13EC *)&D_800F75C0);
    u16 *spu = (u16 *)0x1F801C00;
    u16 i;
    u16 j;
    struct S_D_800A6AA0 buf = D_800A6AA0;

    for (i = 0; i < 256; i++) {
        spu[i] = 0;
    }
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874) = (SpuRegs_A13EC_800A13EC *)0x1F801C00;
    D_800E1840 = (u32 *)0x1F8010C0;
    D_800E1844 = (u32 *)0x1F8010C4;
    D_800E1848 = (u32 *)0x1F8010C8;
    D_800E184C = (u32 *)0x1F8010F0;
    D_800E1850 = (u32 *)0x1F801014;
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_1AC = 4;
    func_8002F210();
    Spu_SetDmaCallback(Spu_ProcessUploadQueue);
    s->f_18 = func_8002F5B0(0xF0000009, 0x20, 0x2000, 0);
    func_8002F5C0(s->f_18);
    func_8002F230();
    *D_800E184C |= 0xB0000;
    s->f_3 = 8;
    s->f_0 = 0;
    s->f_D = 0;
    s->f_3E = 60;
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_1AA = 0xC000;
    Sound_BusyWait(2);
    Spu_Upload((u32)&buf, 0x1010, 0x10);
    while (func_800A1A24() != 0) {
    }
    for (i = 0; i < 24; i++) {
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_0 = 0;
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_2 = 0;
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_4 = 0x1000;
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_6 = 0x1010;
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_8 = 0;
        (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->v[i].f_A = 0;
    }
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_188 = 0xFFFF;
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_18A = 0xFF;
    Sound_BusyWait(4);
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_18C = 0xFFFF;
    (*(SpuRegs_A13EC_800A13EC * *)&D_800E1874)->f_18E = 0xFF;
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 50; j++) {
            g_SeqVoices[i][j] = 0;
        }
    }
    for (i = 0; i < 127; i++) {
        for (j = 0; j < 3; j++) {
            g_SoundBanks[i][j] = 0;
        }
    }
    for (i = 0; i < 24; i++) {
        g_SeqVoices[i][0x27] = 0x78;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8009BA90_seq", D_800A6AA0);


void func_800A1718(void) {
    struct S_D_800F75C0_800A1718 *s = ((struct S_D_800F75C0_800A1718 *)&D_800F75C0);
    u16 i;
    u16 j;

    D_800E1874->f_18C = 0;
    D_800E1874->f_184 = 0;
    D_800E1874->f_180 = 0;
    D_800E1874->f_1AA = 0;
    D_800E1874->f_1AC = 0;
    func_8002F210();
    func_8002F5D0(s->f_18);
    func_8002F230();
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 50; j++) {
            g_SeqVoices[i][j] = 0;
        }
    }
    for (i = 0; i < 127; i++) {
        for (j = 0; j < 3; j++) {
            g_SoundBanks[i][j] = 0;
        }
    }
}

s16 Spu_Upload(u32 a0, u32 a1, u32 a2) {
    struct S_D_800F75C0_800A1830 *p = ((struct S_D_800F75C0_800A1830 *)&D_800F75C0);
    s16 ret;
    u8 old;

    if (a1 > 0x80000 || a2 > 0x80000 || (a0 & 3)) {
        goto fail;
    }
    if (p->f_1C != 0) {
        old = p->f_35;
        p->f_35 = old + 1;
        if (p->f_35 < 0x21) {
            g_SpuUploadQueue[p->f_35 - 1].v[0] = a0;
            g_SpuUploadQueue[p->f_35 - 1].v[1] = a2;
            g_SpuUploadQueue[p->f_35 - 1].v[2] = a1;
            ret = 0;
            goto end;
        }
        p->f_35 = old;
        goto fail;
    }
    Spu_StartTransfer(0, (void *)a0, (void *)a2, a1);
    ret = 1;
    goto end;
fail:
    ret = -1;
end:
    return ret;
}

s16 Spu_Download(u32 a, u32 b, u32 c) {
    struct S_D_800F75C0_800A192C *p = ((struct S_D_800F75C0_800A192C *)&D_800F75C0);
    s16 ret;
    u8 old;

    if (a > 0x80000 || c > 0x80000) {
        goto fail;
    }
    if (p->f_1C != 0) {
        old = p->f_35;
        p->f_35 = old + 1;
        if (p->f_35 < 0x21) {
            g_SpuUploadQueue[p->f_35 - 1].v[0] = b;
            g_SpuUploadQueue[p->f_35 - 1].v[1] = c | 0x80000000;
            g_SpuUploadQueue[p->f_35 - 1].v[2] = a;
            ret = 0;
            goto end;
        }
        p->f_35 = old;
        goto fail;
    }
    Spu_StartTransfer(1, (void *)b, (void *)c, a);
    ret = 1;
    goto end;
fail:
    ret = -1;
end:
    return ret;
}

s16 func_800A1A24(void) {
    return D_800F75DC;
}

void func_800A1A34(s32 arg0)
{
  M2C_UNK *new_var;
  new_var = &D_800F75C0;
  if (arg0 == 0)
  {
    *((s8 *) (((s8 *) new_var) + 0x34)) = 0;
    return;
  }
  D_800B4DEC = (void (*)(void))arg0;
  *((s8 *) (((s8 *) (&D_800F75C0)) + 0x34)) = 1;
}

/* Loads a sound bank: checks alignment, size (<= 512 KB, multiple of 16) and the "SShd" magic
 * at +0xC, then uploads `size` bytes from `src` to SPU RAM address h->f_4 (or queues the upload
 * in g_SpuUploadQueue while a transfer is running). Returns the g_SoundBanks slot it took, or -1. */
s16 Sound_LoadBank(void *src, Hdr_800A1A5C_800A1A5C *h, u32 size) {
    struct S_F75C0_800A1A5C *s = (struct S_F75C0_800A1A5C *)&D_800F75C0;
    void *dst;
    s32 i;
    s32 r;
    if ((s32)src & 3) {
        goto fail;
    }
    if ((s32)h & 3) {
        goto fail;
    }
    if (size > 0x80000) {
        goto fail;
    }
    if (size & 0xF) {
        goto fail;
    }
    dst = h->f_4;
    if (h->f_C != 0x64685353) {
        goto fail;
    }
    if (s->busy != 0) {
        if (++s->qcount <= 32) {
            g_SpuUploadQueue[s->qcount - 1].e.src = src;
            g_SpuUploadQueue[s->qcount - 1].e.dst = dst;
            g_SpuUploadQueue[s->qcount - 1].e.size = size;
        } else {
            s->qcount--;
            goto fail;
        }
    } else if (dst != 0) {
        Spu_StartTransfer(0, src, dst, size);
    } else {
        s->busy = 0;
    }
    for (i = 0; (u16)i < 127; i++) {
        if (((struct S_D_800E1180_800A1A5C *)&g_SoundBanks)[(u16)i].used == 0) {
            ((struct S_D_800E1180_800A1A5C *)&g_SoundBanks)[(u16)i].used = 1;
            ((struct S_D_800E1180_800A1A5C *)&g_SoundBanks)[(u16)i].h = h;
            ((struct S_D_800E1180_800A1A5C *)&g_SoundBanks)[(u16)i].size = size >> 3;
            break;
        }
    }
    r = i;
    goto end;
fail:
    r = -1;
end:
    return r;
}
