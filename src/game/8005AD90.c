#include "common.h"
#include "m2c_macros.h"
#define G_8005BC10 ((struct Game_8005BC10 *)&g_Game)
#define S_8005BC10 ((struct Spike_8005BC10 *)&g_Spike)
#define D_8005B318 (*(struct S_D_800EC350_8005B318 *)&g_Game)
typedef struct { s16 unk0; s16 unk2; s16 unk4; u8 pad6[0x18]; } S_B9030;
typedef struct { s16 f_0; s16 f_2; u8 pad4[0x14]; } S_8220_8005BB5C;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u16 f_8; u8 padA[0xE]; } S_8220_8005ADF8_8005ADF8;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } S_821C_8005ADF8_8005ADF8;
typedef struct { s16 f_0; s16 f_2; s32 f_4; } S_821C_8005B7BC;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[0x12]; } S_8220_8005B7BC;
typedef struct { s32 x, y, z, pad; } V4_8005BC10_8005BC10;
typedef struct { s16 f_0; s16 f_2; } P_8005BC10_8005BC10;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[2]; s16 f_A; s16 f_C; s16 f_E; s16 f_10; u8 pad12[6]; } L_8005B880_8005B880;
typedef struct { s16 f_0; s16 f_2; s16 f_4; u8 pad6[8]; s16 f_E; u8 pad10[8]; u16 f_18; u8 pad1A[0x1E]; } O_8005B880_8005B880;
typedef struct { u8 pad[0x20]; } Mdl_8005B880_8005B880;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; s16 f_8; s16 f_A; u8 padC[6]; s16 f_12; u8 pad14[4]; } S_8220_8005B318_8005B318;
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } S_821C_8005B318_8005B318;
typedef struct { void *fn; s32 pad4; void *f_8; } S_Entry_8005B318_8005B318;

extern S_B9030 D_800B9030[64];
extern s16 D_800AFA20;
extern s16 D_800AFA22;
extern s16 D_800AFA24;
extern struct S_D_800EC350 { u8 pad0[0x812C]; u8 unk812C; u8 pad812D[0xF3]; S_8220_8005BB5C *f_8220; } g_Game;
struct S_D_800EC350_8005ADF8 { u8 pad0[0x8124]; u16 f_8124; u8 pad8126[0xF6]; S_821C_8005ADF8_8005ADF8 *f_821C; S_8220_8005ADF8_8005ADF8 *f_8220; u8 pad8224[0x64]; s32 f_8288; };
s32 Link_SaveState(s32, S_8220_8005ADF8_8005ADF8 *);
struct S_D_800EC350_8005B7BC { u8 pad0[0x821C]; S_821C_8005B7BC *f_821C; S_8220_8005B7BC *f_8220; u8 pad8224[0x64]; s32 f_8288; };
struct Game_8005BC10 { u8 pad0[0x8126]; u16 stage; u8 pad8128[0xF8]; P_8005BC10_8005BC10 *f_8220; };
struct Spike_8005BC10 { u8 pad0[0x24]; V4_8005BC10_8005BC10 pos; };
extern M2C_UNK g_Spike;
void Spike_PlaceAtSpawn(s32, s32, s32);
void Camera_Translate(s32, s32, s32);
void func_8013D000(void);
void func_8013FE04(void);
extern Mdl_8005B880_8005B880 *D_800B4D64;
struct Game_8005B880 { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x22]; u16 stage; u8 pad8128[0xE4]; O_8005B880_8005B880 *f_820C; u8 pad8210[0x10]; L_8005B880_8005B880 *f_8220; };
void Sound_PlayAt(s32, O_8005B880_8005B880 *);
void func_8008FC30(s32, L_8005B880_8005B880 *);
void Model_BindStageMesh(Mdl_8005B880_8005B880 *, s16);
void func_8013D358(s32, s32, s32);
void Camera_StartShake(s32);
void func_80052CEC(s32);
void CamFlyby_StartSegment(s32);
void SaveFlag_Set(s32);
void SaveByte_Set(s32, s32);
struct S_D_800B9030_8005B480 { s16 f_0; s16 f_2; s16 f_4; s16 f_6; u8 pad8[6]; s16 f_E; s16 f_10; u8 pad12[6]; s16 f_18; u8 pad1A[4]; };
struct S_D_800EC350_8005B318 { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; u8 pad8128[0xF4]; S_821C_8005B318_8005B318 *f_821C; S_8220_8005B318_8005B318 *f_8220; };
extern S_Entry_8005B318_8005B318 *D_800AF868[];
s32 SaveFlag_Test(s16);
s16 SaveByte_Get(s16);

s32 func_8005AD90(void) {
    s32 i;
    for (i = 0; i < 64; i++) {
        D_800B9030[i].unk0 = -1;
        D_800B9030[i].unk2 = -1;
        D_800B9030[i].unk4 = -1;
    }
    if (g_Game.unk812C != 2) {
        D_800AFA20 = 0;
        D_800AFA22 = 0;
        D_800AFA24 = 0;
    }
    return 0;
}

s32 func_8005ADF8(void) {
    struct S_D_800EC350_8005ADF8 *d = (struct S_D_800EC350_8005ADF8 *)&(*(M2C_UNK *)&g_Game);
    S_821C_8005ADF8_8005ADF8 *g;
    s32 i, j, k;
    if (d->f_8124 == 0x20) {
        return 0;
    }
    for (i = 0; i < d->f_8288; i++) {
        g = &d->f_821C[i];
        for (j = 0; j < g->f_0; j++) {
            k = g->f_4 + j;
            switch (d->f_8220[k].f_0) {
            case 2:
                if ((u16)(d->f_8220[k].f_8 - 0x37) < 4) {
                    break;
                }
            case 3: case 4: case 5: case 6: case 7:
            case 9: case 10:
            case 12: case 13: case 14:
            case 23: case 24:
            case 32: case 33: case 34: case 35:
            case 37:
            case 39:
            case 41: case 42:
            case 45: case 46: case 47: case 48:
            case 50:
                Link_SaveState(k, &d->f_8220[k]);
                break;
            }
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005AD90", jtbl_800A53B0_pad);


typedef struct { s16 f_0; s16 f_2; s16 f_4; u16 f_6; u8 pad8[6]; u16 f_E; u16 f_10; u16 f_12; u16 f_14; u16 f_16; u16 f_18; u16 f_1A; u8 pad1C[2]; } Rec_8005AF4C;
typedef struct { u8 pad0[8]; u16 f_8; u16 f_A; u16 f_C; u16 f_E; u16 f_10; u16 f_12; u16 f_14; u8 pad16[2]; } L_8005AF4C;
extern struct S_D_800F4350_8005AF4C { u8 pad0[0x126]; u16 f_126; u8 pad128[0xF8]; L_8005AF4C *f_220; } D_800F4350;
#define REC_AF4C ((Rec_8005AF4C *)D_800B9030)

/* Puts the saved link values (D_800B9030, 64 records {area +0, link +2, index +4, kind +6, ...})
 * of the current area (D_800F4350+0x126) back into the area's link table (D_800F4350+0x220) and
 * frees the records. The value fields used depend on the link kind. Written as the permuter found
 * it: the `REC_AF4C + k` re-evaluations reproduce the original addressing. Returns 0. */
s32 Link_RestoreSaved(void) {
    Rec_8005AF4C *r;
    s32 i;
    s32 k;
    for (k = 0; k < 64; k++) {
        r = REC_AF4C + k;
        if ((REC_AF4C + k)->f_0 < 0) {
            continue;
        }
        if ((REC_AF4C + k)->f_2 != D_800F4350.f_126) {
            continue;
        }
        i = r->f_4;
        switch ((s16)(REC_AF4C + k)->f_6) {
        case 2: case 3: case 9: case 12: case 13: case 23:
            D_800F4350.f_220[i].f_A = (REC_AF4C + k)->f_10;
            break;
        case 24:
            D_800F4350.f_220[i].f_8 = (REC_AF4C + k)->f_10;
            break;
        case 5: case 7: case 32: case 33: case 34: case 35:
            D_800F4350.f_220[i].f_8 = (REC_AF4C + k)->f_10;
            break;
        case 6:
            D_800F4350.f_220[i].f_14 = (REC_AF4C + k)->f_10;
            break;
        case 10: case 39: case 41: case 42: case 45: case 46: case 47: case 48:
            D_800F4350.f_220[i].f_14 = (REC_AF4C + k)->f_1A;
            break;
        case 4:
            D_800F4350.f_220[i].f_C = (REC_AF4C + k)->f_12;
            break;
        case 14:
            D_800F4350.f_220[i].f_8 = (REC_AF4C + k)->f_E;
            D_800F4350.f_220[i].f_E = (REC_AF4C + k)->f_14;
            D_800F4350.f_220[i].f_10 = (REC_AF4C + k)->f_16;
            D_800F4350.f_220[i].f_12 = (REC_AF4C + k)->f_18;
            break;
        case 37:
            D_800F4350.f_220[i].f_8 = r->f_E;
            D_800F4350.f_220[i].f_C = r->f_12;
            break;
        case 50:
            D_800F4350.f_220[i].f_8 = r->f_E;
            break;
        }
        r->f_0 = -1;
        r->f_2 = -1;
        r->f_4 = -1;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005AD90", jtbl_800A5478_pad);


/* a saved link record: in-use flag, area, link index, then the link itself (kind at +6) */
typedef struct { s16 f_0; s16 f_2; s16 f_4; S_8220_8005ADF8_8005ADF8 l; } LinkSave_5B130;
#define LS_5B130 ((LinkSave_5B130 *)D_800B9030)
typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 kind; s16 f_8; u8 padA[4]; u16 f_E; u16 f_10; u8 pad12[8]; u16 f_1A; u8 pad1C[2]; } LinkSaveF_5B130;

/* Saves link l (index idx of the current area) into a free D_800B9030 record and derives the values
   Link_RestoreSaved puts back, by link kind. Returns 0, or -1 when all 64 records are in use. */
s32 Link_SaveState(s32 idx, S_8220_8005ADF8_8005ADF8 *l) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (LS_5B130[i].f_0 >= 0) {
            continue;
        }
        LS_5B130[i].f_0 = 1;
        LS_5B130[i].f_2 = D_800F4350.f_126;
        LS_5B130[i].f_4 = idx;
        LS_5B130[i].l = *l;
        switch (((LinkSaveF_5B130 *)D_800B9030)[i].kind) {
        case 2: case 3: case 5: case 7: case 9: case 12: case 13: case 23:
        case 32: case 33: case 34: case 35:
            ((LinkSaveF_5B130 *)D_800B9030)[i].f_10 = ((LinkSaveF_5B130 *)D_800B9030)[i].f_8;
            break;
        case 24:
            ((LinkSaveF_5B130 *)D_800B9030)[i].f_10 = ((LinkSaveF_5B130 *)D_800B9030)[i].f_E | (((LinkSaveF_5B130 *)D_800B9030)[i].f_8 << 8);
            break;
        case 6:
            if (((LinkSaveF_5B130 *)D_800B9030)[i].f_8 == 3) {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_10 = 1;
            } else {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_10 = 0;
            }
            break;
        case 10: case 41: case 46: case 48:
            if (((LinkSaveF_5B130 *)D_800B9030)[i].f_8 != 0) {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 1;
            } else {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 0;
            }
            break;
        case 42: case 45: case 47:
            if (((LinkSaveF_5B130 *)D_800B9030)[i].f_8 != 0) {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 2;
            } else {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 0;
            }
            break;
        case 39:
            if (((LinkSaveF_5B130 *)D_800B9030)[i].f_8 != 4) {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 1;
            } else {
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_1A = 4;
            }
            break;
        case 50:
            switch (((LinkSaveF_5B130 *)D_800B9030)[i].f_8) {
            case 0:
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_E = 0;
                break;
            case 1: case 2: case 3:
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_E = 2;
                break;
            case 4: case 5:
                ((LinkSaveF_5B130 *)D_800B9030)[i].f_E = 5;
                break;
            }
            break;
        case 37:
            ((LinkSaveF_5B130 *)D_800B9030)[i].f_E = ((LinkSaveF_5B130 *)D_800B9030)[i].f_8;
            break;
        }
        return 0;
    }
    return -1;
}



s32 Link_ApplySaveFlags(void) {
    S_Entry_8005B318_8005B318 *tbl;
    S_821C_8005B318_8005B318 *g;
    S_8220_8005B318_8005B318 *o;
    s32 i, j;
    if (D_8005B318.f_8124 == 0x20) {
        return 0;
    }
    tbl = D_800AF868[D_8005B318.f_8126];
    if (tbl == 0) {
        return 0;
    }
    for (i = 0; tbl[i].fn != 0; i++) {
        g = &D_8005B318.f_821C[i];
        for (j = 0; j < g->f_0; j++) {
            o = &D_8005B318.f_8220[g->f_4 + j];
            switch (o->f_0) {
            case 0x22:
                if (SaveFlag_Test(o->f_12) != 0) {
                    o->f_8 = 1;
                }
                break;
            case 0x32:
                o->f_8 = SaveByte_Get(o->f_A);
                break;
            }
        }
    }
    return 0;
}

s32 Link_SaveStates(void) {
    s32 i;
    for (i = 0; i < 64; i++) {
        if (((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_0 < 0) {
            continue;
        }
        if (((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_6 == 0x22 && ((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_10 != 0) {
            SaveFlag_Set(((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_18);
        }
        if (((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_6 == 0x32) {
            SaveByte_Set(((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_10, ((struct S_D_800B9030_8005B480 *)&D_800B9030)[i].f_E);
        }
    }
    return 0;
}

typedef struct { s16 f_0; s16 f_2; s16 f_4; s16 f_6; } S_821C_8005B538;
typedef struct { void (*fn)(void *); s32 pad4; S_821C_8005B538 *f_8; } S_Entry_8005B538;
struct S_D_800EC350_8005B538 { u8 pad0[0x8126]; u16 f_8126; u8 pad8128[0xF4]; S_821C_8005B538 *f_821C; S_8220_8005BB5C *f_8220; u8 pad8224[0x64]; s32 f_8288; };
#define D_8005B538 (*(struct S_D_800EC350_8005B538 *)&g_Game)
extern S_Entry_8005B538 *D_800AF868_li[] asm("D_800AF868");
/* Link_InitArea: run the stage's link-init table D_800AF868[stage] after restoring the saved link
 * state. Entries below g_Game+0x8288 get their group record g_Game+0x821C[i] (count reset) and their
 * function is called once per link record of the group; the rest are called with 0. */
s32 Link_InitArea(void) {
    S_821C_8005B538 *g;
    S_Entry_8005B538 *tbl;
    s32 i;
    S_8220_8005BB5C *arg;
    s32 j;

    tbl = D_800AF868_li[D_8005B538.f_8126];
    if (tbl == 0) {
        D_8005B538.f_8288 = 0;
        return 0;
    }
    Link_RestoreSaved();
    Link_ApplySaveFlags();
    for (i = 0; tbl[i].fn != 0; i++) {
        if (i < D_8005B538.f_8288) {
            tbl[i].f_8 = &D_8005B538.f_821C[i];
            tbl[i].f_8->f_2 = 0;
            g = tbl[i].f_8;
            for (j = 0; j < g->f_0; j++) {
                arg = &D_8005B538.f_8220[g->f_4 + j];
                do { } while (0);
                tbl[i].fn(arg);
            }
        } else {
            tbl[i].fn(0);
        }
    }
    return 0;
}

typedef struct { s16 f_0; s16 pad2; s16 f_4; } S_Range_8005B68C;
typedef struct { s32 pad0; void (*fn)(void *); S_Range_8005B68C *f_8; } S_Entry_8005B68C;
extern struct { u8 pad0[0x8100]; s32 f_8100; u8 pad8104[0x22]; u16 f_8126; u8 pad8128[0xF8]; S_8220_8005BB5C *f_8220; u8 pad8224[0x6C]; s16 f_8290; } G_5B68C asm("g_Game");
extern S_Entry_8005B68C *LinkTbl_5B68C[] asm("D_800AF868");

/* Per-frame partner of Link_InitArea: runs the stage link table D_800AF868[stage] again, each
   function once per link record of its group (skipped while g_Game+0x8100 bit 3 is set) or with 0
   for entries without a group. Needs the early return. */
s32 Link_UpdateArea(void) {
    S_Entry_8005B68C *e;
    s32 j;
    S_8220_8005BB5C *p;
    S_Range_8005B68C *r;
    s32 i;
    e = LinkTbl_5B68C[G_5B68C.f_8126];
    if (e == 0) {
        return 0;
    }
    G_5B68C.f_8290 = -1;
    for (j = 0; e[j].fn != 0; j++) {
        if (e[j].f_8 == 0) {
            e[j].fn(0);
        } else if (!(G_5B68C.f_8100 & 8)) {
            r = e[j].f_8;
            for (i = 0; i < r->f_0; i++) {
                p = G_5B68C.f_8220;
                p += r->f_4 + i;
                e[j].fn(p);
            }
        }
    }
    return 0;
}

s32 func_8005B7BC(s16 i, s16 *out) {
    s32 total = 0;
    s32 k;
    for (k = 0; k < ((struct S_D_800EC350_8005B7BC *)&g_Game)->f_8288; k++) {
        total += ((struct S_D_800EC350_8005B7BC *)&g_Game)->f_821C[k].f_0;
    }
    if (i >= total) {
        return -1;
    }
    out[0] = ((struct S_D_800EC350_8005B7BC *)&g_Game)->f_8220[i].f_0;
    out[1] = ((struct S_D_800EC350_8005B7BC *)&g_Game)->f_8220[i].f_2;
    out[2] = ((struct S_D_800EC350_8005B7BC *)&g_Game)->f_8220[i].f_4;
    return 0;
}

/* Sends event cmd to stage link record g_Game+0x8220[idx] (0x18 bytes; its object is
 * g_Game+0x820C[+4]); used by the monkey AI. 1: activates it (sound 0x75, func_8008FC30, sets
 * object flag 0x8000, optional model anim +0x10) - kind 0x2B instead goes 4 -> 5 (sound 0xB0);
 * 2: starts it with a camera shake (sound 0xAF, or 0xAC + func_8013D358 in stage 0x29);
 * 3/4: 4 -> 5 or 1 -> 2; 5/6: set +0x10/+0xE; 7: camera flyby segment 0, g_Game+0x8100 = 7;
 * 8, 11: state 1; 9: state arg+1 (0..3); 12/13/15: 4 -> 5; 14: state 1, timer 0.
 * Returns 0 (-1 for idx < 0). */
s32 Link_SendEvent(s32 cmd, s32 idx, s32 arg) {
    L_8005B880_8005B880 *l;
    O_8005B880_8005B880 *o;
    if (idx < 0) {
        return -1;
    }
    l = &(*(struct Game_8005B880 *)&g_Game).f_8220[idx];
    o = &(*(struct Game_8005B880 *)&g_Game).f_820C[l->f_4];
    switch (cmd) {
    case 1:
        if (l->f_0 == 0x2B) {
            if (l->f_2 == 4) {
                l->f_2 = 5;
                Sound_PlayAt(0xB0, o);
            }
            return 0;
        }
        if (l->f_2 != 0) {
            return 0;
        }
        func_8008FC30(l->f_C, l);
        l->f_2 = 1;
        o->f_18 |= 0x8000;
        Sound_PlayAt(0x75, o);
        if (l->f_10 < 0) {
            return 0;
        }
        if (o->f_E >= 0) {
            Model_BindStageMesh(&D_800B4D64[o->f_E], l->f_10);
            return 0;
        }
        break;
    case 2:
        if (l->f_2 != 0) {
            return 0;
        }
        l->f_2 = 1;
        l->f_6 = l->f_A;
        if ((*(struct Game_8005B880 *)&g_Game).stage == 0x29) {
            Sound_PlayAt(0xAC, o);
            func_8013D358(o->f_0, o->f_2, o->f_4);
        } else {
            Sound_PlayAt(0xAF, o);
        }
        Camera_StartShake(0);
        func_80052CEC(1);
        return 0;
    case 3:
    case 4:
        if (l->f_2 == 4) {
            l->f_2 = 5;
            break;
        }
        if (l->f_2 != 1) {
            return 0;
        }
        l->f_2 = 2;
        break;
    case 7:
        l->f_2 = 1;
        CamFlyby_StartSegment(0);
        (*(struct Game_8005B880 *)&g_Game).f_8100 = 7;
        break;
    case 5:
        l->f_10 = 1;
        break;
    case 6:
        l->f_E = 1;
        break;
    case 11:
        if (l->f_2 != 0) {
            return 0;
        }
        l->f_2 = 1;
        break;
    case 8:
        l->f_2 = 1;
        break;
    case 9:
        if (arg == 0) {
            l->f_2 = 1;
        } else if (arg == 1) {
            l->f_2 = 2;
        } else if (arg == 2) {
            l->f_2 = 3;
        } else if (arg == 3) {
            l->f_2 = 4;
        } else {
            return 0;
        }
        break;
    case 12:
    case 13:
    case 15:
        if (l->f_2 != 4) {
            return 0;
        }
        l->f_2 = 5;
        break;
    case 14:
        if (l->f_2 != 0) {
            return 0;
        }
        l->f_2 = 1;
        l->f_6 = 0;
        break;
    case 0:
    case 10:
        break;
    }
    return 0;
}



s32 func_8005BB5C(s32 a) {
    if (a < 0) {
        return -1;
    }
    return g_Game.f_8220[a].f_2;
}

s32 func_8005BB98(s32 arg0) {
    s16 temp_a0;

    temp_a0 = (arg0 & 0x1F) - 2;
    switch (temp_a0) {
    case 8:
        return 0x75;
    case 13:
        return 0x7E;
    case 7:
        return 0x2A;
    case 4:
    case 5:
        return 0x80;
    case 0:
    case 1:
        return 0x82;
    case 2:
    case 3:
        return 0x81;
    case 15:
        return 0xB1;
    default:
        return -1;
    }
}



/* Extra setup for a few stages (0x30, 0x45, 0x47, 0x4B, 0x56): calls Spike_PlaceAtSpawn for the stage
 * (which can move Spike), runs that stage's overlay hook (0x30, 0x47), and moves the camera by
 * however far Spike moved. */
s32 Stage_SpecialSetup(void) {
    V4_8005BC10_8005BC10 old;
    old = *(V4_8005BC10_8005BC10 *)((u8 *)&g_Spike + 0x24);
    switch (G_8005BC10->stage) {
    case 0x47:
        if (G_8005BC10->f_8220->f_2 == 1) {
            Spike_PlaceAtSpawn(1, G_8005BC10->stage, 2);
        } else {
            Spike_PlaceAtSpawn(-1, G_8005BC10->stage, 2);
            func_8013FE04();
        }
        Camera_Translate(S_8005BC10->pos.x - old.x, S_8005BC10->pos.y - old.y, S_8005BC10->pos.z - old.z);
        break;
    case 0x4B:
        Spike_PlaceAtSpawn(1, G_8005BC10->stage, 2);
        Camera_Translate(S_8005BC10->pos.x - old.x, S_8005BC10->pos.y - old.y, S_8005BC10->pos.z - old.z);
        break;
    case 0x56:
        Spike_PlaceAtSpawn(1, G_8005BC10->stage, 1);
    case 0x45:
        Camera_Translate(S_8005BC10->pos.x - old.x, S_8005BC10->pos.y - old.y, S_8005BC10->pos.z - old.z);
        break;
    case 0x30:
        Spike_PlaceAtSpawn(1, G_8005BC10->stage, 2);
        Camera_Translate(S_8005BC10->pos.x - old.x, S_8005BC10->pos.y - old.y, S_8005BC10->pos.z - old.z);
        func_8013D000();
        break;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/8005AD90", jtbl_800A56A0_pad);

