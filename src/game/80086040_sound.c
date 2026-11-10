#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s16 x; s16 y; } S16x2;
typedef struct { s16 x; s16 y; } S16x2_80087A20;
typedef struct { s16 x; s16 y; } S16x2_80087BA4;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } S_Snd_800877F8;
typedef struct { s16 f_0; s16 f_2; u8 pad4[0x12]; s16 f_16; u8 pad18[4]; } S_BF370_80086788;
typedef struct { u16 f_0; u8 pad2[2]; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; } S_Src_80087EE0_80087EE0;

s32 Sound_CalcVolume3D(s32, s16, S16x2 *);
void func_800A3570(s32, s32, s32);

s32 Sound_ForgetVoice(s16 a, s16 b);
extern struct S_D_800BF610 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } Sound_FrameQueue[];

s32 Sound_SetVolumes(s32 a, s32 b);

extern struct S_D_800BF670 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; s16 f_16; } g_SoundState;

M2C_UNK func_800A2640(s16, s16);
M2C_UNK func_800A35FC(s16, s16);
M2C_UNK func_800A329C(s16);
extern struct S_D_800BF370 { s16 f_0; s16 f_2; u8 pad4[0xC]; s16 f_10; s16 f_12; s16 f_14; s16 f_16; s32 f_18; } g_SoundSlots[];
extern M2C_UNK g_SoundTable;

s32 Sound_ResetVolumes(s32 arg0);
s32 Sound_ClearFrameQueue(void);
s16 Spu_Upload(s32 arg0, u32 arg1, u32 arg2);
s16 Spu_TransferBusy(void);
M2C_UNK func_800A1F8C(M2C_UNK);
M2C_UNK func_800A2030(M2C_UNK);
M2C_UNK func_800A20F4(M2C_UNK, M2C_UNK);
M2C_UNK func_800A23E0(s16, s16);
M2C_UNK func_800A28FC(M2C_UNK, M2C_UNK);
M2C_UNK func_800A2A14(M2C_UNK, M2C_UNK);
M2C_UNK func_800A2A70(M2C_UNK, M2C_UNK);
extern s16 D_800BF67A;
s16 func_800A1DB0(s16, s32);
extern struct S_D_800EC350 { u8 pad_0[0x8120]; u16 f_8120; u8 pad_8122[0x10E]; s32 f_8230; } g_Game;
M2C_UNK func_800A2F54(s16, M2C_UNK, M2C_UNK);

s32 Sound_Play(s32 arg0, s32 arg1);
struct S_D_800BF370 *Sound_AllocSlot(void);
M2C_UNK bios_printf(char *, ...);
extern M2C_UNK D_800A627C;

void func_800A2428(s16, s16);
extern s16 D_800BF67E;

s32 Sound_ResumeStreams(void);
s32 Sound_ClearSlots(void);
extern s16 D_800BF676;
extern s16 D_800BF686;
M2C_UNK func_800A2294(s16);
void func_800A342C(s32);
void VSync(s32);
struct S_D_800BF670_80086170 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; u16 f_10; };
struct S_D_800EC350_80086170 { u8 pad0[0x8120]; u16 f_8120; };
struct S_D_800BF670_800862E4 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; s16 f_C; s16 f_E; s16 f_10; };
extern char D_800A622C[];
s32 Sound_IsQueuedThisFrame(s16 a);
s32 Sound_QueueThisFrame(s16 a, s16 b, s16 *c);
s16 func_800A31B8(s32, s32, s32, s32, s32, s32);
struct S_D_800B2D08_80087A20 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; };
extern u32 D_800EC250;
s32 func_800A30D8(s32, s32, s32);
void func_800A25CC(s32, s32, s32, s32);
struct S_D_800BF610_80088578 { s16 f_0; s16 f_2; s32 f_4; };
void func_800A2B6C(s32, s32);
s16 func_800A1F3C(s32);
s16 func_800A1CCC(s32);
void SeqDriver_Quit(void);
extern s32 D_800E38B4;
s16 Sound_LoadBank(void *src, void *h, u32 size);
s16 SsGetNck(void);
s32 Music_OpenSeq(void);
s32 Music_Play(void);
struct S_D_800EC350_80086CAC { u8 pad_0[0x822C]; s32 *f_822C; s32 f_8230; };
s16 func_800A3158(s16, s16, s16);
extern struct S_D_800BF688 { s16 f_0; s16 f_2; s16 f_4; } g_SoundListenerPos;
s32 SquareRoot0(s32);

s32 Sound_InitState(void) {
    s32 *var_v1;
    s32 var_v0;

    func_800A23E0(0, 0);
    g_SoundState.f_A = 0x7F;
    g_SoundState.f_C = 0x7F;
    g_SoundState.f_8 = 0;
    g_SoundState.f_0 = -1;
    g_SoundState.f_2 = -1;
    g_SoundState.f_4 = -1;
    g_SoundState.f_6 = -1;
    g_SoundState.f_16 = -1;
    Sound_ResetVolumes(0);
    Sound_ClearFrameQueue();
    var_v1 = (s32 *)0x80154000;
    var_v0 = 0x3FFF;
    do {
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 = (void *)((u8 *)var_v1 + (4));
    } while (var_v0 >= 0);
    Spu_Upload(0x80154000, 0x6FFFFU, 0x10000U);
    do {

    } while ((Spu_TransferBusy() << 0x10) != 0);
    func_800A1F8C(0xC);
    func_800A2030(4);
    func_800A20F4(0xA, 0xA);
    func_800A28FC(1, 1);
    func_800A28FC(0, 0);
    func_800A2A14(0x7F, 0x7F);
    func_800A2A70(0, 0);
    func_800A23E0(D_800BF67A, D_800BF67A);
    return 0;
}

s32 Sound_ResetSlotsAndResume(void) {
    Sound_ClearSlots();
    Sound_ResumeStreams();
    return 0;
}

s32 Sound_ResumeStreams(void) {
    s32 v;
    u16 m;
    func_800A342C(1);
    VSync(0);
    m = ((struct S_D_800EC350_80086170 *)&g_Game)->f_8120;
    if ((m >= 0xA && m < 0xE) || (m >= 0x11 && m < 0x15) || (m >= 0x17 && m < 0x1A) || m == 9) {
        v = ((struct S_D_800BF670_80086170 *)&g_SoundState)->f_10;
    } else {
        v = 0x7F;
    }
    if (((struct S_D_800BF670_80086170 *)&g_SoundState)->f_0 >= 0) {
        func_800A2640(((struct S_D_800BF670_80086170 *)&g_SoundState)->f_0, v);
    }
    if (((struct S_D_800BF670_80086170 *)&g_SoundState)->f_4 >= 0) {
        func_800A2640(((struct S_D_800BF670_80086170 *)&g_SoundState)->f_4, v);
    }
    return 0;
}

extern s16 D_800BF680;

s32 Sound_SetXaVolume(s32 mode) {
    switch (mode) {
    case 0:
        { s32 t = D_800BF67E; mode = t * 127 / 75; __asm__("" : : "r"(t)); mode <<= 16; mode >>= 16; }
        break;
    case 1:
        mode = D_800BF680;
        break;
    case 2:
        mode = 0;
        break;
    default:
        mode = 0x7F;
        break;
    }
    func_800A2A14(mode, mode);
    return 0;
}

/* Sets the two master volumes (clamped to 0..127) on the sound channels.
 */
s32 Sound_SetVolumes(s32 a, s32 b) {
    if (a >= 0x80) {
        a = 0x7F;
    }
    if (a != ((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_10) {
        ((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_10 = a;
        if (((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_0 >= 0) {
            func_800A2640(((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_0, a);
        }
        if (((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_4 >= 0) {
            func_800A2640(((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_4, ((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_10);
        }
    }
    if (b >= 0x80) {
        b = 0x7F;
    }
    if (b == ((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_E) {
        return 0;
    }
    ((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_E = b;
    if (((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_6 < 0) {
        return 0;
    }
    func_800A2428(((struct S_D_800BF670_800862E4 *)&g_SoundState)->f_6, b);
    return 0;
}

s32 Music_SetVolume(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 2) {
            arg1 = 0x4B;
        }
    } else {
        arg1 = D_800BF67E;
    }
    if (D_800BF676 >= 0) {
        func_800A2428(D_800BF676, arg1);
    }
    return 0;
}

s16 Music_GetSeq(void) {
    return D_800BF676;
}

s16 Music_GetPlayingSeq(void) {
    return D_800BF686;
}

s32 Sound_ResetVolumes(s32 arg0)
{
  g_SoundState.f_E = 0x4B;
  g_SoundState.f_10 = 0x7F;
  if (arg0 != 0)
  {
    if (g_SoundState.f_0 >= 0)
    {
      func_800A2640(g_SoundState.f_0, 0x7F);
    }
    if (g_SoundState.f_4 >= 0)
    {
      func_800A2640(g_SoundState.f_4, g_SoundState.f_10);
    }
    if (g_SoundState.f_6 >= 0)
    {
      func_800A2428(g_SoundState.f_6, g_SoundState.f_E);
    }
  }
 do { return 0; } while (0);
}

s32 Sound_GetVolumes(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) g_SoundState.f_10;
    M2C_FIELD(arg0, s32 *, 4) = (s32) g_SoundState.f_E;
    return 0;
}

s32 Sound_SaveVolumes(void) {
    g_SoundState.f_14 = g_SoundState.f_10;
    g_SoundState.f_12 = g_SoundState.f_E;
    return 0;
}

s32 Sound_RestoreVolumes(void) {
    g_SoundState.f_10 = (u16) g_SoundState.f_14;
    g_SoundState.f_E = (u16) g_SoundState.f_12;
    Sound_SetVolumes((s16) g_SoundState.f_14, (s16) g_SoundState.f_12);
    return 0;
}

typedef struct { u16 id; s16 voice; u16 f_4, f_6, f_8, f_A, f_C, f_E, f_10; s16 f_12; s16 f_14; s16 f_16; s32 f_18; } Slot_80086540;
typedef struct { u16 id; u16 f_2; u16 f_4, f_6, f_8, f_A, f_C, f_E; } Amb_80086540;
struct Game_80086540 { u8 pad0[0x8126]; u16 stage; };
extern Slot_80086540 g_SoundSlots_80086540[24] asm("g_SoundSlots");
extern struct { Amb_80086540 *list; s32 f_4; } Sound_StageAmbience[];
extern char D_800A6200[];

s32 Sound_StartAmbience(void) {
    s16 i;
    Slot_80086540 *s;
    Amb_80086540 *list;
    Amb_80086540 *a;
    for (i = 0; i < 24; i++) {
        s = &g_SoundSlots_80086540[i];
        if ((s16)((s16)s->id & -0x1000) == 0x5000 || (s16)s->id < 0) {
            continue;
        }
        if (s->voice >= 0) {
            func_800A329C(s->voice);
        }
        if ((s16)((s16)s->id & -0x1000) == 0x7000) {
            *(s16 *)&s->id = -1;
            s->voice = -1;
            s->f_12 = 0;
            s->f_14 = -1;
            s->f_16 = 0;
        } else {
            Sound_ForgetVoice(s->id, s->voice);
        }
    }
    list = Sound_StageAmbience[((struct Game_80086540 *)&g_Game)->stage].list;
    if (list == 0) {
        return 0;
    }
    for (i = 0; (s16)list[i].id >= 0; i++) {
        list[i].id |= list[i].f_2;
        s = (Slot_80086540 *)Sound_AllocSlot();
        if (s == 0) {
            bios_printf(D_800A6200, (s16)list[i].id);
            continue;
        }
        s->voice = Sound_Play(1, (s16)list[i].id);
        s->id = list[i].id;
        s->f_4 = list[i].f_4;
        s->f_6 = list[i].f_6;
        s->f_8 = list[i].f_8;
        s->f_A = list[i].f_A;
        s->f_C = list[i].f_C;
        s->f_E = list[i].f_E;
        s->f_10 = list[i].f_A;
        s->f_18 = 0;
        if (s->voice >= 0) {
            s->f_12 = 1;
        } else {
            s->f_12 = 0;
        }
    }
    Sound_ClearFrameQueue();
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80086040_sound", D_800A6200);


s32 Sound_PauseVolumes(s32 mode) {
    S_BF370_80086788 *p;
    s32 i;
    s16 type;
    s16 vol[2];
    for (i = 0; i < 24; i++) {
        p = &((S_BF370_80086788 *)&g_SoundSlots)[i];
        if (p->f_0 < 0) {
            continue;
        }
        if (p->f_2 < 0) {
            continue;
        }
        type = p->f_0 & 0xF000;
        if (mode == 0) {
            if (type < 0x6000 && type != 0) {
                continue;
            }
            vol[0] = vol[1] = 0;
            func_800A3570(p->f_2, vol[0], vol[1]);
        } else {
            if (type != 0) {
                continue;
            }
            if (p->f_16 == 1) {
                continue;
            }
            func_800A3570(p->f_2, 0x1000, 0x1000);
        }
    }
    return 0;
}

typedef struct { s16 vx, vy, vz, pad; } SV_8008686C;
typedef struct { s16 id; s16 voice; SV_8008686C pos; u8 padC[4]; s16 f_10; s16 playing; s16 f_14; s16 f_16; s32 *f_18; } Slot_8008686C;
typedef struct { u8 pad0[0x24]; s32 x; s32 y; s32 z; u8 pad30[0x220]; } Mky_8008686C;
typedef struct { u8 pad0[0x812C]; u8 f_812C; u8 pad_812D[0x12B]; SV_8008686C f_8258; } Game_8008686C;
extern Slot_8008686C g_SoundSlots_8008686C[] asm("g_SoundSlots");
extern Mky_8008686C g_Monkeys[];
extern struct { u8 pad0[0x100]; s32 f_100; u8 pad104[0x2C]; u16 f_130; s16 f_132; } D_800F4350;
extern u8 D_800E6908;
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; } g_Spike;
extern SV_8008686C D_800BF688_8008686C asm("g_SoundListenerPos");
s32 Sound_CalcVolumePlanar(S_Src_80087EE0_80087EE0 *s, s16 *out);
s32 Sound_Stop(s32 a, s32 b);
s32 Music_DuckForPause(void);
#define STOP_8008686C { if (s->playing != 0) { Sound_Stop(s->id, s->voice); s->playing = 0; s->voice = -1; } continue; }
#define PLAY_8008686C { s->voice = Sound_Play(1, s->id); if (s->voice >= 0) { s->playing = 1; } else { s->playing = 0; } continue; }

s32 Sound_UpdatePositional(void) {
    S16x2 vol;
    SV_8008686C p;
    s16 i;
    s16 kind;
    Slot_8008686C *s;

    if (((Game_8008686C *)&g_Game)->f_812C == 0x18 || D_800E6908 == 1) {
        D_800BF688_8008686C = ((Game_8008686C *)&g_Game)->f_8258;
    } else {
        D_800BF688_8008686C.vx = g_Spike.f_24;
        D_800BF688_8008686C.vy = g_Spike.f_28;
        D_800BF688_8008686C.vz = g_Spike.f_2C;
    }
    for (i = 0; i < 0x18; i++) {
        s = &g_SoundSlots_8008686C[i];
        if (s->id < 0) {
            continue;
        }
        kind = s->id & 0xF000;
        if (kind == 0x2000) {
            if (Sound_CalcVolume3D((s32)&g_SoundSlots_8008686C[i].pos, s->f_10, &vol) == 0) STOP_8008686C
            if (s->playing == 0) PLAY_8008686C
        } else if (kind == 0x3000 || kind == 0x4000) {
            if (Sound_CalcVolumePlanar((S_Src_80087EE0_80087EE0 *)s, (s16 *)&vol) == 0) STOP_8008686C
            if (s->playing == 0) PLAY_8008686C
        } else if (kind == 0x5000) {
            continue;
        } else if (kind == 0x6000) {
            if (D_800F4350.f_100 & 2) {
                vol.y = 0;
                vol.x = 0;
            } else {
                p.vx = g_Monkeys[s->f_10].x;
                p.vy = g_Monkeys[s->f_10].y;
                p.vz = g_Monkeys[s->f_10].z;
                Sound_CalcVolume3D((s32)&p, 0x2000, &vol);
            }
        } else if (kind == 0x7000) {
            if (D_800F4350.f_100 & 4) {
                vol.y = 0;
                vol.x = 0;
            } else {
                p.vx = s->f_18[0];
                p.vy = s->f_18[1];
                p.vz = s->f_18[2];
                if (Sound_CalcVolume3D((s32)&p, s->f_10, &vol) == 0) STOP_8008686C
                if (s->playing == 0) PLAY_8008686C
            }
        } else if (kind == 0x1000) {
            if (D_800F4350.f_130 == 0) {
                continue;
            }
            vol.x = 0x1000;
            vol.y = 0x1000;
        } else {
            continue;
        }
        if ((u16)(D_800F4350.f_130 - 1) < 4) {
            s32 x = (0x30 - D_800F4350.f_132) * vol.x;
            s32 y = (0x30 - D_800F4350.f_132) * vol.y;
            vol.x = x / 48;
            vol.y = y / 48;
        }
        func_800A3570(g_SoundSlots_8008686C[i].voice, vol.x, vol.y);
    }
    Music_DuckForPause();
    return 0;
}

s32 Sound_Nop(void) {
    return 0;
}

/* Load sound banks. 1: the common bank (header 0x80100000, data 0x80154000) -> g_SoundState.f_0.
 * 3: the bank at 0x80146000 with reverb (type 4, depth 10) -> f_4. 2: a stage sound pack at
 * 0x80146000: its offsets (+0x14..+0x24) are made absolute and kept in g_Game+0x822C/+0x8230, bank 1
 * -> f_2, optional bank 2 (if word 1 is set) -> f_4; then Music_OpenSeq and, except when
 * D_800E38B4 is 0x35, 0x18, 0x48, 0x57 or 0x4E, Music_Play. Each load waits for SsGetNck. */
s32 Sound_LoadBanks(s32 mode) {
    s16 id;
    s32 *h;
    s32 *h2;

    if (mode == 1) {
        id = Sound_LoadBank((void *)0x80154000, (void *)0x80100000, 0x1010);
        while (SsGetNck() != 0) {
        }
        g_SoundState.f_0 = id;
        if (id >= 0) {
            func_800A2640(id, g_SoundState.f_10);
        }
        return 0;
    } else if (mode == 3) {
        id = Sound_LoadBank((void *)0x80154000, (void *)0x80146000, 0x41810);
        while (SsGetNck() != 0) {
        }
        func_800A2030(4);
        func_800A20F4(10, 10);
        g_SoundState.f_4 = id;
        if (id >= 0) {
            func_800A2640(id, g_SoundState.f_10);
        }
        return 0;
    } else if (mode == 2) {
        func_800A342C(1);
        VSync(0);
        h = (s32 *)0x80146000;
        g_SoundState.f_2 = -1;
        g_SoundState.f_4 = -1;
        g_SoundState.f_6 = -1;
        g_SoundState.f_16 = -1;
        ((struct S_D_800EC350_80086CAC *)&g_Game)->f_822C = h;
        h[5] += (s32)h;
        h[6] += (s32)h;
        h[7] += (s32)h;
        h[8] += (s32)h;
        h[9] += (s32)h;
        ((struct S_D_800EC350_80086CAC *)&g_Game)->f_8230 = h[7];
        id = Sound_LoadBank((void *)h[8], (void *)h[5], 0x41810);
        while (SsGetNck() != 0) {
        }
        g_SoundState.f_2 = id;
        h2 = ((struct S_D_800EC350_80086CAC *)&g_Game)->f_822C;
        if (h2[1] != 0) {
            id = Sound_LoadBank((void *)h2[9], (void *)h2[6], 0x69010);
            while (SsGetNck() != 0) {
            }
            g_SoundState.f_4 = id;
        }
        if (g_SoundState.f_4 >= 0) {
            func_800A2640(g_SoundState.f_4, g_SoundState.f_10);
        }
        Music_OpenSeq();
        if (D_800E38B4 != 0x35 && D_800E38B4 != 0x18 && D_800E38B4 != 0x48 && D_800E38B4 != 0x57 && D_800E38B4 != 0x4E) {
            Music_Play();
        }
        return 0;
    }
    return 0;
}

s32 Music_ChangesOnAreaSwitch(s32 a, s32 b) {
    if (a == 0x4B || (a == 0x48 && b == 0x4C) || a == 4 || (a == 3 && b == 4) || a == 0x22 || (a == 0x21 && b == 0x22)
        || (a == 0x20 && b == 0x1E) || (a == 0x1E && b == 0x20) || (a == 8 && b == 6) || (a == 6 && b == 8)
        || (a == 9 && b == 0xA) || (a == 0xA && b == 9)) {
        return 1;
    }
    return 0;
}

/* Counterpart of Sound_LoadBanks. Stops the current sequence (g_SoundState.f_6) and, by mode,
 * frees it (3), also the stage banks f_4 / f_2 (1), or everything including the common bank f_0
 * (0); 2 only stops. Each close is retried until the library accepts it. Returns 0. */
s32 Sound_UnloadBanks(s32 mode) {
    if (g_SoundState.f_6 >= 0) {
        func_800A2428(g_SoundState.f_6, 0);
        func_800A2B6C(g_SoundState.f_6, 1);
    }
    switch (mode) {
    case 1:
        if (g_SoundState.f_6 >= 0) {
            while (func_800A1F3C(g_SoundState.f_6) < 0) {
            }
            g_SoundState.f_6 = -1;
            g_SoundState.f_16 = -1;
        }
        Sound_ClearSlots();
        func_800A342C(1);
        VSync(0);
        if (g_SoundState.f_4 >= 0) {
            while (func_800A1CCC(g_SoundState.f_4) < 0) {
            }
        }
        if (g_SoundState.f_2 >= 0) {
            while (func_800A1CCC(g_SoundState.f_2) < 0) {
            }
        }
        g_SoundState.f_4 = -1;
        g_SoundState.f_2 = -1;
        break;
    case 0:
        if (g_SoundState.f_6 >= 0) {
            while (func_800A1F3C(g_SoundState.f_6) < 0) {
            }
            g_SoundState.f_6 = -1;
            g_SoundState.f_16 = -1;
        }
        Sound_ClearSlots();
        func_800A342C(1);
        VSync(0);
        if (g_SoundState.f_4 >= 0) {
            while (func_800A1CCC(g_SoundState.f_4) < 0) {
            }
        }
        if (g_SoundState.f_2 >= 0) {
            while (func_800A1CCC(g_SoundState.f_2) < 0) {
            }
        }
        if (g_SoundState.f_0 >= 0) {
            while (func_800A1CCC(g_SoundState.f_0) < 0) {
            }
        }
        g_SoundState.f_4 = -1;
        g_SoundState.f_2 = -1;
        g_SoundState.f_0 = -1;
        break;
    case 2:
        break;
    case 3:
        if (g_SoundState.f_6 >= 0) {
            while (func_800A1F3C(g_SoundState.f_6) < 0) {
            }
            g_SoundState.f_6 = -1;
            g_SoundState.f_16 = -1;
        }
        break;
    }
    return 0;
}

/* Stops the music/stream voice (g_SoundState+6, also clears +0x16), then waits for the three
 * sound-bank slots (+4, +2, +0) to finish (func_800A1CCC < 0 while busy) and shuts the sound
 * library down (func_800A2030(4), func_800A20F4(0, 0), SeqDriver_Quit). Returns 0. */
s32 Sound_Shutdown(void) {
    if (g_SoundState.f_6 >= 0) {
        func_800A2428(g_SoundState.f_6, 0);
        func_800A2B6C(g_SoundState.f_6, 0);
        while (func_800A1F3C(g_SoundState.f_6) < 0) {
        }
        g_SoundState.f_6 = -1;
        g_SoundState.f_16 = -1;
    }
    func_800A342C(1);
    VSync(0);
    if (g_SoundState.f_4 >= 0) {
        while (func_800A1CCC(g_SoundState.f_4) < 0) {
        }
    }
    if (g_SoundState.f_2 >= 0) {
        while (func_800A1CCC(g_SoundState.f_2) < 0) {
        }
    }
    if (g_SoundState.f_0 >= 0) {
        while (func_800A1CCC(g_SoundState.f_0) < 0) {
        }
    }
    func_800A2030(4);
    func_800A20F4(0, 0);
    SeqDriver_Quit();
    return 0;
}

s32 Music_OpenSeq(void) {
    s16 temp_v0;

    if ((g_Game.f_8230 == 0) || (g_SoundState.f_2 < 0)) {
        return -1;
    }
    temp_v0 = func_800A1DB0(g_SoundState.f_2, g_Game.f_8230);
    g_SoundState.f_6 = temp_v0;
    if (temp_v0 >= 0) {
        g_SoundState.f_8 = 0;
        func_800A2428(temp_v0, 0);
    }
    return 0;
}

s32 Music_ModeUsesUserVolume(void) {
    if ((g_Game.f_8120 == 0xD) || (g_Game.f_8120 == 0xB) || (g_Game.f_8120 == 0x11) || (g_Game.f_8120 == 0x13) || (g_Game.f_8120 == 0x18)) {
        return 1;
    }
    return 0;
}

s32 SaveByte_Get(s32);
void func_800A2E3C(s32, s32, s32);
void func_800A2ACC(s32);

/* Starts the stage music voice (g_SoundState.f_6) with the volume for the current level: special-cased
   when Music_ModeUsesUserVolume() is set (level 0x46 with save byte 8 == 5 plays at a third), otherwise by
   g_Game.f_8120. Remembers the voice in f_16. Returns 0. */
s32 Music_Play(void) {
    struct S_D_800BF670 *ss = &g_SoundState;
    u16 m;
    if (ss->f_6 < 0) {
        return 0;
    }
    if (Music_ModeUsesUserVolume() != 0) {
        if (D_800E38B4 == 0x46 && SaveByte_Get(8) == 5) {
            func_800A2E3C(g_SoundState.f_6, 0x5A, (s16)(g_SoundState.f_E / 3));
        } else {
            func_800A2E3C(g_SoundState.f_6, 0x5A, g_SoundState.f_E);
        }
    } else {
        m = g_Game.f_8120;
        if (m == 3) {
            func_800A2E3C(g_SoundState.f_6, 0x5A, 0x6E);
        } else if (m == 8 || m == 0x10 || (m == 0x1D || m == 0x1E)) {
            func_800A2ACC(ss->f_6);
            func_800A2428(ss->f_6, 0x4B);
        } else if (m == 9 || m == 10 || m == 0x12 || m == 0x17 || m == 0xC || m == 0x14 || m == 0x19) {
            func_800A2ACC(g_SoundState.f_6);
            func_800A2428(g_SoundState.f_6, g_SoundState.f_E);
        } else {
            func_800A2E3C(g_SoundState.f_6, 0x5A, 0x4B);
        }
    }
    g_SoundState.f_16 = g_SoundState.f_6;
    return 0;
}

s32 Music_FadeOut(void) {
    if (g_SoundState.f_6 >= 0) {
        func_800A2F54(g_SoundState.f_6, 0x5A, 0);
        g_SoundState.f_16 = -1;
    }
    return 0;
}

/* On pause, switches the music's 16 channels to a quieter setting; on unpause,
 * switches them back.
 */
s32 Music_DuckForPause(void) {

    s16 i;
    s32 v;
    if (g_SoundState.f_6 < 0) {
        return 0;
    }
    if (g_SoundState.f_8 == 0) {
        if ((D_800EC250 & 0xF0) != 0x80) {
            return 0;
        }
        g_SoundState.f_8 = 1;
        for (i = 0; i < 16; i++) {
            v = func_800A30D8(g_SoundState.f_6, i, 0);
            if ((u16)(v - 20) < 20) {
                func_800A25CC(g_SoundState.f_6, i, 0, 15);
            } else if ((u16)(v - 40) < 20) {
                func_800A25CC(g_SoundState.f_6, i, g_SoundState.f_C, 15);
            }
        }
        return 0;
    }
    if ((D_800EC250 & 0xF0) != 0x80) {
        g_SoundState.f_8 = 0;
        for (i = 0; i < 16; i++) {
            v = func_800A30D8(g_SoundState.f_6, i, 0);
            if ((u16)(v - 20) < 20) {
                func_800A25CC(g_SoundState.f_6, i, g_SoundState.f_C, 10);
            } else if ((u16)(v - 40) < 20) {
                func_800A25CC(g_SoundState.f_6, i, 0, 10);
            }
        }
    }
    return 0;
}

/* g_SoundState viewed as an s16 array (linker alias, see undefined_syms_auto.txt) */
extern s16 g_SoundStateArr[];
s32 Sound_PlayFixed(s32 id) {
    if (g_SoundStateArr[((S_Snd_800877F8 *)&g_SoundTable)[id].f_0] < 0) {
        return -1;
    }
    if (Sound_IsQueuedThisFrame(id) != 0) {
        return 0;
    }
    if (Sound_QueueThisFrame(0, id, 0) == 0) {
        return 0;
    }
    ((S_Snd_800877F8 *)&g_SoundTable)[id].f_6 = func_800A3158(g_SoundStateArr[((S_Snd_800877F8 *)&g_SoundTable)[id].f_0], ((S_Snd_800877F8 *)&g_SoundTable)[id].f_2, ((S_Snd_800877F8 *)&g_SoundTable)[id].f_4);
    if (((S_Snd_800877F8 *)&g_SoundTable)[id].f_6 < 0) {
        bios_printf(D_800A622C, id, ((S_Snd_800877F8 *)&g_SoundTable)[id].f_2, ((S_Snd_800877F8 *)&g_SoundTable)[id].f_4);
    }
    return ((S_Snd_800877F8 *)&g_SoundTable)[id].f_6;
}

INCLUDE_RODATA("asm/nonmatchings/game/80086040_sound", D_800A622C);


/* Plays sound effect `id & 0xFFF` from the sound table; unless `id` has flag bits
 * set, records the voice in a slot so it can be stopped. Returns the voice or -1.
 */
extern char D_800A6240[];
extern char D_800A625C[];
s16 func_800A3158_878E0(s32, s32, s32) asm("func_800A3158");
typedef struct { s16 bank; s16 a; s16 b; s16 pad; } SndEnt_878E0;
extern SndEnt_878E0 g_SoundTable_878E0[] asm("g_SoundTable");
extern s16 g_SoundState_878E0[] asm("g_SoundState");

s32 Sound_Play(s32 mode, s32 id) {
    s16 i = id & 0xFFF;
    s32 bank = g_SoundState_878E0[g_SoundTable_878E0[i].bank];
    SndEnt_878E0 *e = &g_SoundTable_878E0[i];
    s32 h;
    struct S_D_800BF370 *s;
    if (bank < 0) {
        return -1;
    }
    if (mode == 0) {
        h = func_800A3158_878E0(bank, e->a, e->b);
    } else {
        h = func_800A31B8(bank, e->a, e->b, 1, 1, 0x1000);
    }
    if (h < 0) {
        bios_printf(D_800A6240, i, g_SoundTable_878E0[i].a, g_SoundTable_878E0[i].b);
        return -1;
    }
    if (!(id & ~0xFFF)) {
        s = Sound_AllocSlot();
        if (s != 0) {
            s->f_0 = id;
            s->f_2 = h;
            s->f_12 = 1;
            s->f_16 = mode;
        } else {
            bios_printf(D_800A625C);
            return -1;
        }
    }
    return h;
}

INCLUDE_RODATA("asm/nonmatchings/game/80086040_sound", D_800A6240);
INCLUDE_RODATA("asm/nonmatchings/game/80086040_sound", D_800A625C);


s32 Sound_PlayAt(s32 idx, s32 a1)
{
  s16 *tbl = ((s16 *)&g_SoundState);
  struct S_D_800B2D08_80087A20 *e;
  S16x2_80087A20 v;
  if (tbl[(&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_0] < 0)
  {
    return -1;
  }
  if (Sound_CalcVolume3D(a1, 0x2000, &v) == 0)
  {
    return 0;
  }
  if (Sound_IsQueuedThisFrame(idx) != 0)
  {
    return 0;
  }
  if (Sound_QueueThisFrame(1, idx, &v) == 0)
  {
    return 0;
  }
  (&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_6 = func_800A31B8(tbl[(&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_0], (&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_2, (&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_4, v.x, v.y, 0x1000);
  if ((&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_6 < 0)
  {
    bios_printf(D_800A622C, idx, (&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_2, (&((struct S_D_800B2D08_80087A20 *)&g_SoundTable)[idx])->f_4);
  }
  return 0;
}

s32 Sound_UpdateVoice3D(s32 a0, s32 arg1, s16 b, s32 c)
{
  s16 a = arg1;
  S16x2 v;
  s32 x;
  unsigned int new_var2;
  s32 y;
  s32 new_var3;
  int new_var;
  if (a < 0)
  {
    return -1;
  }
  new_var3 = Sound_CalcVolume3D(c, b, &v);
  new_var2 = a;
  new_var = (x = new_var3) != 0;
  if (new_var)
  {
    x = v.x;
    y = v.y;
  }
  else
  {
    x = 0;
    y = 0;
  }
  func_800A3570(new_var2, x, y);
  return 0;
}

s32 Sound_SetVoiceVolumeRatio(s32 a0, s16 id, s16 n, s16 d) {
    S16x2_80087BA4 v;
    if (id < 0) {
        return -1;
    }
    v.y = v.x = (n << 12) / d;
    func_800A3570(id, v.x, v.x);
    return 0;
}

s32 Sound_SetVoicePitch(s32 arg0, s16 arg1, s16 arg2)
{
  s16 new_var;
  int new_var2;
  if (arg1 >= 0)
  {
    new_var = arg1;
    func_800A35FC(new_var, arg2);
    return 0;
  }
  if (arg1 || arg2)
  {
    new_var2 = -1;
    return new_var2;
  }
  else
  {
    new_var2 = -1;
    return new_var2;
  }
}

s32 Sound_SetStereo(s32 arg0) {
    func_800A2294((s16) (arg0 ^ 1));
    return 0;
}

typedef struct { s16 vx, vy, vz, pad; } SV_87C8C;
struct Game_87C8C { u8 pad0[0x813A]; u16 f_813A; u8 pad813C[0x11C]; SV_87C8C f_8258; SV_87C8C f_8260; };
extern struct Game_87C8C g_Game_87C8C asm("g_Game");
extern SV_87C8C D_800BF688_87C8C asm("g_SoundListenerPos");
void VectorNormalSS(void *, void *);

s32 Sound_CalcVolume3D(s32 pv, s16 range, S16x2 *out)
{
  SV_87C8C *p = (SV_87C8C *)pv;
  SV_87C8C v;
  SV_87C8C n1;
  SV_87C8C cam;
  SV_87C8C n2;
  s32 d;
  s32 e;
  s32 l;
  s32 r;
  int new_var;
  out->y = 0;
  out->x = 0;
  new_var = ((D_800BF688_87C8C.vx - p->vx) * (D_800BF688_87C8C.vx - p->vx)) + ((D_800BF688_87C8C.vy - p->vy) * (D_800BF688_87C8C.vy - p->vy));
  d = SquareRoot0(new_var + ((D_800BF688_87C8C.vz - p->vz) * (D_800BF688_87C8C.vz - p->vz)));
  {
  s32 rg = (s16)range; __asm__("" :: "r"(rg), "r"(rg), "r"(rg), "r"(rg));
  if (d > rg)
  {
    return 0;
  }
  l = 0x1000;
  if (d > 0x800)
  {
    l = ((rg - d) << 12) / (rg - 0x800);
  }
  }
  if (n2.vz)
  {
    r = l;
  }
  else
  {
    r = l;
  }
  if (g_Game_87C8C.f_813A != 0)
  {
    __asm__("" :: "m"(g_Game_87C8C.f_813A), "m"(g_Game_87C8C.f_813A), "m"(g_Game_87C8C.f_813A));
    cam = g_Game_87C8C.f_8258;
    v.vx = p->vx - cam.vx;
    v.vy = 0;
    v.vz = p->vz - cam.vz;
    VectorNormalSS(&v, &n1);
    v.vy = 0;
    v.vx = g_Game_87C8C.f_8260.vx - cam.vx;
    v.vz = g_Game_87C8C.f_8260.vz - cam.vz;
    VectorNormalSS(&v, &n2);
    e = ((-n2.vz) * n1.vx) + (n2.vx * n1.vz);
    if (e > 0)
    {
      e >>= 12; r = (r * (0x1000 - e)) / 4096;
    }
    else
    {
      e = -e;
      l = (l * (0x1000 - (e / 4096))) / 4096;
    }
  }
  out->y = r;
  out->x = l;
  e = 0;
  if (r < 8 && l < 8) return e;
  return 1;
}

/* Sound_CalcVolumePlanar: volume of a positional sound source s for the listener g_SoundListenerPos (used by
 * Sound_UpdatePositional). Distance in the y/z plane (type 0x3000) or y/x plane, against radius f_E or
 * f_A: full volume 0x1000 within 0x800, falling linearly to 0 at the radius. Writes the same value
 * to out[0] and out[1] (left/right?); returns 0 when out of range, muted (D_800EC250 mode 0xC*) or
 * below 8. */
s32 Sound_CalcVolumePlanar(S_Src_80087EE0_80087EE0 *s, s16 *out) {
    s32 type;
    s32 y;
    s32 d;
    s32 r;
    s32 vl, vr;
    out[1] = 0;
    out[0] = 0;
    type = (s16)(s->f_0 & 0xF000);
    y = s->f_6 - s->f_C;
    if ((D_800EC250 & 0xF0) == 0xC0) {
        return 0;
    }
    if (type == 0x3000) {
        d = SquareRoot0((g_SoundListenerPos.f_2 - y) * (g_SoundListenerPos.f_2 - y) + (g_SoundListenerPos.f_4 - s->f_8) * (g_SoundListenerPos.f_4 - s->f_8));
        r = s->f_E;
        if (r < d) {
            return 0;
        }
        if (d >= 0x801) {
            vl = ((r - d) << 12) / (r - 0x800);
            vr = vl;
        } else {
            vl = 0x1000;
            vr = vl;
        }
    } else {
        d = SquareRoot0((g_SoundListenerPos.f_2 - y) * (g_SoundListenerPos.f_2 - y) + (g_SoundListenerPos.f_0 - s->f_4) * (g_SoundListenerPos.f_0 - s->f_4));
        r = s->f_A;
        if (r < d) {
            return 0;
        }
        if (d < 0x801) {
            vl = 0x1000;
            vr = vl;
        } else {
            vl = ((r - d) << 12) / (r - 0x800);
            vr = vl;
        }
    }
    out[1] = vr;
    out[0] = vl;
    if (vr < 8 && vl < 8) {
        return 0;
    }
    return 1;
}

/* Stops the voice playing sound `id`.
 */
s32 Sound_Stop(s32 a, s32 b) {
    if (b < 0) {
        return 0;
    }
    func_800A329C(b);
    if (a & ~0xFFF) {
        return 0;
    }
    Sound_ForgetVoice(a, b);
    return 0;
}

s32 Sound_StopAndForget(s32 a, s32 b) {
    if (b < 0) {
        return 0;
    }
    func_800A329C(b);
    Sound_ForgetVoice(a, b);
    return 0;
}

s32 Sound_FreeSlot(s32 arg0)
{
  void *new_var;
  s16 temp_a0;
  void *temp_s0;
  if (arg0 < 0)
  {
    return 0;
  }
  temp_s0 = &g_SoundSlots;
  temp_s0 = (arg0 * 0x1C) + temp_s0;
  new_var = temp_s0;
  temp_a0 = *((s16 *) (((s8 *) new_var) + 2));
  if (temp_a0 >= 0)
  {
    func_800A329C(temp_a0);
  }
  *((s16 *) (((s8 *) new_var) + 0)) = -1;
  *((s16 *) (((s8 *) new_var) + 2)) = -1;
  *((s16 *) (((s8 *) new_var) + 0x12)) = 0;
  *((s16 *) (((s8 *) temp_s0) + 0x14)) = -1;
  *((s16 *) (((s8 *) new_var) + 0x16)) = 0;
  return 0;
}

s32 Sound_ClearSlots(void) {
    s32 i;
    for (i = 0; i < 24; i++) {
        g_SoundSlots[i].f_0 = -1;
        g_SoundSlots[i].f_2 = -1;
        g_SoundSlots[i].f_12 = 0;
        g_SoundSlots[i].f_14 = -1;
        g_SoundSlots[i].f_16 = 0;
    }
    return 0;
}

/* Returns a free playing-sound slot, or NULL.
 */
struct S_D_800BF370 *Sound_AllocSlot(void) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (g_SoundSlots[i].f_0 < 0) {
            g_SoundSlots[i].f_14 = i;
            return &g_SoundSlots[i];
        }
    }
    return 0;
}

s32 Sound_ForgetVoice(s16 a, s16 b) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (g_SoundSlots[i].f_2 == b && g_SoundSlots[i].f_0 == a) {
            g_SoundSlots[i].f_0 = -1;
            g_SoundSlots[i].f_2 = -1;
            g_SoundSlots[i].f_12 = 0;
            g_SoundSlots[i].f_14 = -1;
            g_SoundSlots[i].f_16 = 0;
            return 0;
        }
    }
    return -1;
}

s32 Sound_FindVoice(s16 a) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (g_SoundSlots[i].f_0 == a) {
            return g_SoundSlots[i].f_2;
        }
    }
    return -1;
}

typedef struct { s16 bank; s16 a; s16 b; s16 pad; } SndEnt_882C4;
extern SndEnt_882C4 g_SoundTable_882C4[] asm("g_SoundTable");
extern s16 g_SoundState_882C4[] asm("g_SoundState");
s16 func_800A3158_882C4(s32, s32, s32) asm("func_800A3158");

s32 Sound_PlayTagged(s32 mode, s32 id, s32 tag) {
    s16 i = id & 0xFFF;
    SndEnt_882C4 *e;
    struct S_D_800BF370 *p;
    s32 h;
    if (g_SoundState_882C4[g_SoundTable_882C4[i].bank] >= 0) {
        e = &g_SoundTable_882C4[i];
        p = Sound_AllocSlot();
        if (p == 0) {
            bios_printf((char *)&D_800A627C, i);
            return -1;
        }
        if (mode == 0) {
            h = func_800A3158_882C4(g_SoundState_882C4[e->bank], e->a, e->b);
        } else {
            h = func_800A31B8(g_SoundState_882C4[e->bank], e->a, e->b, 1, 1, 0x1000);
        }
        if (h >= 0) {
            p->f_0 = id;
            p->f_10 = tag;
            p->f_2 = h;
            p->f_12 = 1;
            return h;
        }
        bios_printf(D_800A6240, i, g_SoundTable_882C4[i].a, g_SoundTable_882C4[i].b);
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/game/80086040_sound", D_800A627C);


s32 Sound_ReserveSlot(s32 a, s32 b, s32 c) {
    s32 id = a & 0xFFF;
    struct S_D_800BF370 *p = Sound_AllocSlot();
    s32 r;
    if (p == 0) {
        bios_printf(&D_800A627C, id);
        return -1;
    }
    r = p->f_14;
    p->f_2 = -1;
    p->f_12 = 0;
    p->f_0 = a;
    p->f_10 = b;
    p->f_18 = c;
    return r;
}

s32 Sound_PlayTracked(s16 arg0, s16 arg1) {
    s32 *temp_v0_2;
    s32 temp_v0;

    temp_v0 = Sound_Play(arg0, arg1);
    if (temp_v0 >= 0) {
        temp_v0_2 = Sound_AllocSlot();
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s16 *, 0) = arg1;
            M2C_FIELD(temp_v0_2, s16 *, 2) = (s16) temp_v0;
            M2C_FIELD(temp_v0_2, s16 *, 0x12) = 1;
            return temp_v0;
        }
        bios_printf(&D_800A627C, arg1);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}

s32 Sound_GetTableEntry(s32 arg0, s32 *arg1, s32 *arg2)
{
  void *temp_a0;
  M2C_UNK *new_var2;
  s32 new_var;
  new_var2 = &g_SoundTable;
  temp_a0 = new_var2;
  temp_a0 = (arg0 * 8) + temp_a0;
  new_var = (s32) (*((s16 *) (((s8 *) temp_a0) + 2)));
  *arg1 = new_var;
  *arg2 = (s32) (*((s16 *) (((s8 *) temp_a0) + 4)));
  return 0;
}

s32 Sound_ClearFrameQueue(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        ((struct S_D_800BF610_80088578 *)&Sound_FrameQueue)[i].f_0 = -1;
        ((struct S_D_800BF610_80088578 *)&Sound_FrameQueue)[i].f_2 = 0;
    }
    return 0;
}

s32 Sound_IsQueuedThisFrame(s16 a) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (Sound_FrameQueue[i].f_0 >= 0 && Sound_FrameQueue[i].f_2 == a) {
            return 1;
        }
    }
    return 0;
}

s32 Sound_QueueThisFrame(s16 a, s16 b, s16 *c) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (Sound_FrameQueue[i].f_0 < 0) {
            Sound_FrameQueue[i].f_0 = a;
            Sound_FrameQueue[i].f_2 = b;
            if (a == 1) {
                Sound_FrameQueue[i].f_4 = c[0];
                Sound_FrameQueue[i].f_6 = c[1];
            }
            return 1;
        }
    }
    return 0;
}
