#include "common.h"
#include "m2c_macros.h"
#define TIP_717B4 ((struct Tip_800717B4 *)&g_TipState)
#define CD_717B4 ((struct Cd_800717B4 *)&g_Cd)
typedef struct { s16 f_0; s16 f_2; SVECTOR f_4; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; s16 f_16; } S_BBD34_800716EC;
typedef struct { u8 b[4]; } Loc_800717B4_800717B4;
typedef struct { Loc_800717B4_800717B4 loc; u8 *buf; s32 n; } Req_800717B4_800717B4;
typedef struct { Loc_800717B4_800717B4 pos; u32 size; char name[16]; } File_800717B4_800717B4;
typedef struct { s16 kind; s16 pad2; s16 x; s16 y; s16 z; s16 timer; u8 padC[8]; s16 f_14; u16 used; } Box_800717B4_800717B4;

extern u8 Tip_OpenState;
s32 Msg_IsOpen(void);

M2C_UNK Mem_Free(s32);
extern struct S_D_800F4DB0 { u8 pad_0[0x20]; s32 f_20; } g_HudState;

extern struct S_D_800BBC50 { s32 f_0; u8 pad_4[0x140]; s32 f_144; u8 pad_148[0x1]; s8 f_149; } g_TipState;
M2C_UNK Model_BindBoned(M2C_UNK *, void *);
extern M2C_UNK Tip_MailboxModel;
extern M2C_UNK Tip_DispenserModel;
void bios_exit(s32) __attribute__((noreturn));
s32 rsin(s32);
s32 rcos(s32);
struct S_D_800BBC50_800716EC { s32 f_0; u8 pad4[0xE0]; S_BBD34_800716EC f_E4[4]; };
struct Tip_800717B4 { u8 pad0[0xE4]; Box_800717B4_800717B4 box[4]; u8 *buf; u8 pad148; u8 f_149; u8 f_14A; };
struct Cd_800717B4 { u8 pad0[8]; s32 f_8; u8 padC[4]; s32 f_10; u8 pad14[0x30]; u8 f_44[0x2C]; };
struct D4DB0_800717B4 { u8 pad0[0x20]; s32 f_20; };
extern M2C_UNK g_Cd;
void Msg_Open(void);
u8 *Mem_AllocPages(s32);
void Cd_GetFileEntry(File_800717B4_800717B4 *, s32);
s32 CdPosToInt(Loc_800717B4_800717B4 *);
void CdIntToPos(s32, void *);
s32 Cd_QueueCommand(s32, void *, void *, void *);
void Game_SetMode(s32, s32, s32);
void Spike_SetPlayMode(s32);
void Camera_ExitLook(void);
void Camera_ExitRadarLive(void);
void Pickup_Drop(s32, SVECTOR *, s32, s32);
void Sound_PlayFixed(s32);

void Tip_ClearAll(void) {
    g_TipState.f_0 = 0;
    g_TipState.f_149 = 0;
}

void Tip_Close(void) {
    Mem_Free(g_TipState.f_144);
    g_TipState.f_149 = 0;
    g_HudState.f_20 = (s32) (g_HudState.f_20 | 0x10);
}

s32 Tip_IsFinished(void) {
    if (Tip_OpenState == 2 && Msg_IsOpen() == 0) {
        return 1;
    }
    return 0;
}

void Tip_SetMailboxModel(void *arg0) {
    Model_BindBoned(&Tip_MailboxModel, arg0 + (M2C_FIELD(arg0, u16 *, 4) * 4));
    M2C_FIELD(&Tip_MailboxModel, void **, 0x18) = (void *) (arg0 + (M2C_FIELD(arg0, u16 *, 8) * 4));
}

void Tip_SetDispenserModel(void *arg0) {
    Model_BindBoned(&Tip_DispenserModel, arg0 + (M2C_FIELD(arg0, u16 *, 4) * 4));
    M2C_FIELD(&Tip_DispenserModel, void **, 0x18) = (void *) (arg0 + (M2C_FIELD(arg0, u16 *, 8) * 4));
}

s32 Tip_AddBox(s32 a, SVECTOR *pos, s32 ang) {
    s32 n = ((struct S_D_800BBC50_800716EC *)&g_TipState)->f_0;
    S_BBD34_800716EC *r;
    if (n == 4) {
        bios_exit(1);
    }
    r = &((struct S_D_800BBC50_800716EC *)&g_TipState)->f_E4[n];
    r->f_0 = a;
    r->f_2 = ang;
    r->f_4 = *pos;
    r->f_14 = 0;
    r->f_16 = 0;
    r->f_C = rsin(ang);
    r->f_E = 0;
    r->f_10 = rcos(ang);
    r->f_4.pad = 0;
    ((struct S_D_800BBC50_800716EC *)&g_TipState)->f_0 = n + 1;
    return n;
}

/* Uses interactable `slot` (one of 4 in g_TipState+0xE4: mailboxes and dispensers). Kinds 0 and 1: unless already open or
 * Msg_IsOpen says no, allocates a 2 KB buffer, reads one sector of CD file 0x14 (the tips
 * file) at `sector` into it, switches to game mode 3 (the tip screen) and pauses the camera.
 * Kind 2 is a cookie dispenser (user: you hit them and they spawn cookies): unless used or
 * its timer (+0xA) is running, spawns three pickups (Pickup_Drop(1, pos, 3, 0); type 1 is the cookie,
 * type 3 the energy chip) just above it and sets the timer to 90 frames. Both then play sound 0xF. */
void Mailbox_OpenTip(s32 slot, s32 sector) {
    Box_800717B4_800717B4 *b = &TIP_717B4->box[slot];
    Loc_800717B4_800717B4 mode;
    Req_800717B4_800717B4 req;
    File_800717B4_800717B4 pos;
    SVECTOR v;
    switch (b->kind) {
    case 0:
    case 1:
        if (b->used == 1) {
            return;
        }
        if (Msg_IsOpen() != 0) {
            return;
        }
        Msg_Open();
        b->used = 1;
        b->f_14 = 0x1D;
        TIP_717B4->buf = Mem_AllocPages(0x800);
        TIP_717B4->f_14A = 0;
        Cd_GetFileEntry(&pos, 0x14);
        CdIntToPos(CdPosToInt(&pos.pos) + sector, &req.loc);
        mode.b[0] = 0x80;
        Cd_QueueCommand(0xE, &mode, CD_717B4->f_44, 0);
        req.buf = TIP_717B4->buf;
        req.n = 1;
        Cd_QueueCommand(2, &req.loc, CD_717B4->f_44, 0);
        Cd_QueueCommand(0x20, &req.loc, CD_717B4->f_44, &TIP_717B4->f_14A);
        TIP_717B4->f_149 = 1;
        Game_SetMode(3, 0, 0);
        CD_717B4->f_8 = 0;
        CD_717B4->f_10 = -1;
        Spike_SetPlayMode(0xB);
        ((struct D4DB0_800717B4 *)&g_HudState)->f_20 &= ~0x10;
        Camera_ExitLook();
        Camera_ExitRadarLive();
        break;
    case 2:
        if (b->used != 0) {
            return;
        }
        if (b->timer > 0) {
            return;
        }
        b->used = 1;
        b->f_14 = 0x3A;
        b->timer = 0x5A;
        v.vx = b->x;
        v.vy = b->y - 0x140;
        v.vz = b->z;
        Pickup_Drop(1, &v, 3, 0);
        Pickup_Drop(1, &v, 3, 0);
        Pickup_Drop(1, &v, 3, 0);
        break;
    default:
        return;
    }
    Sound_PlayFixed(0xF);
}

typedef struct { s16 kind; s16 pad2; SVECTOR pos; SVECTOR rot; u16 frame; u16 state; } TipBox_71A28;
typedef struct { u8 pad0[0x14]; void *mat; u8 pad18[0xC]; s32 x, y, z; u8 pad30[0x2C]; u16 frame; u8 pad5E[0x12]; } TipMdl_71A28;
typedef struct { s32 n; TipMdl_71A28 mdlA; TipMdl_71A28 mdlB; u8 pad[0xE4 - 4 - 0xE0]; TipBox_71A28 box[4]; u8 *buf; u32 f_148; } TipState_71A28;
extern TipState_71A28 g_TipState_71A28 asm("g_TipState");
extern struct { u8 pad0[8]; void *ot; u8 padC[0x80F4]; s32 f_8100; } g_Game_71A28 asm("g_Game");
extern u8 g_ViewMatrix[];
extern TipMdl_71A28 D_800BBC54_71A28 asm("Tip_MailboxModel");
extern TipMdl_71A28 D_800BBCC4_71A28 asm("Tip_DispenserModel");
extern u8 g_ProjVerts[];
void SetRotMatrix(void *);
void SetTransMatrix(void *);
void Matrix_FromFacingXZ(SVECTOR *, void *);
void Model_CalcKeyedJointMatrices(void *, s32);
void Model_ProjectBonedVerts(void *);
void Model_DrawNoFog(void *, void *, void *, s32);
void Shadow_Draw(void *, s32, s32, s32);
s32 Tip_IsFinished(void);
void Spike_ClearPlayMode(void);
void Tip_Close(void);
void Msg_SetText(s32);

/* Draws the tip boxes (g_TipState: count, then up to 4 boxes at +0xE4). Each box is projected through
   the GTE (depth cue registers DQA 0x40 / DQB 0 give its screen radius in MAC0) and steps its
   animation: kinds 0/1 drive model A's frame (+0x60; state 0 loops 0x1D frames, state 1 plays 0x59
   frames once then returns to state 0), kind 2 model B's (+0xD0; 0x3A / 0x58) and counts down its timer
   +0xA. On screen, it draws model A (kind 1 shaded 0x40) or B at the box, with a shadow. Afterwards
   finishes an opening tip (f_149 == 2) and shows a pending message once its file has loaded. */
void Tip_DrawAll(void) {
    s32 n = g_TipState_71A28.n;
    TipBox_71A28 *b;
    TipMdl_71A28 *m;
    s32 i;
    s32 f;
    register s32 r asm("$3"); s32 sz, sxy, x, y;
    s32 shade;

    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        b = &g_TipState_71A28.box[i];
        SetRotMatrix(g_ViewMatrix);
        SetTransMatrix(g_ViewMatrix);
        __asm__ volatile("lwc2 $0, 4(%0); lwc2 $1, 8(%0)" : : "r"(b));
        __asm__ volatile("li $8, 0x40; ctc2 $8, $27; addu $8, $0, $0; ctc2 $8, $28; nop; nop; rtps" : : : "$8");
        f = b->frame + 1;
        switch (b->kind) {
        case 0:
        case 1:
            switch (b->state) {
            case 0:
                if (f >= 0x1D) {
                    f = 0;
                }
                break;
            case 1:
                if (f >= 0x59) {
                    f = 0;
                    b->state = 0;
                }
                break;
            }
            g_TipState_71A28.mdlA.frame = f;
            break;
        case 2:
            switch (b->state) {
            case 0:
                if (f >= 0x3A) {
                    f = 0;
                }
                break;
            case 1:
                if (f >= 0x58) {
                    f = 0;
                    b->state = 0;
                }
                break;
            }
            g_TipState_71A28.mdlB.frame = f;
            if (b->pos.pad > 0) {
                b->pos.pad--;
            }
            break;
        }
        b->frame = f;
        __asm__ volatile("mfc2 %0, $24" : "=r"(r));
        __asm__ volatile("mfc2 %0, $19" : "=r"(sz));
        __asm__ volatile("mfc2 %0, $14" : "=r"(sxy));
        r >>= 16;
        if ((u32)(sz - 1) >= 0xF60) {
            continue;
        }
        x = (s16)sxy;
        y = sxy >> 16;
        if (x + r < 0 || x - r >= 0x181 || y + r < 0 || y - r >= 0xF1) {
            continue;
        }
        __asm__("" : : "r"(r));
        shade = 0;
        switch (b->kind) {
        case 1:
            shade = 0x40;
        case 0:
            m = &D_800BBC54_71A28;
            break;
        default:
            m = &D_800BBCC4_71A28;
            break;
        }
        m->x = b->pos.vx;
        m->y = b->pos.vy;
        m->z = b->pos.vz;
        Matrix_FromFacingXZ(&b->rot, m->mat);
        Model_CalcKeyedJointMatrices(m, 1);
        Model_ProjectBonedVerts(m);
        Model_DrawNoFog(g_Game_71A28.ot, g_ProjVerts, m, shade);
        Shadow_Draw(&m->x, b->pos.vy, 0x40, 0);
    }
    if (Tip_OpenState == 2 && Tip_IsFinished() == 1) {
        Spike_ClearPlayMode();
        Tip_Close();
        g_Game_71A28.f_8100 = 0;
    }
    if ((g_TipState_71A28.f_148 & 0xFFFF00) == 0x10100) {
        Msg_SetText((s32)g_TipState_71A28.buf);
        ((u8 *)&g_TipState_71A28.f_148)[1] = 2;
    }
}
