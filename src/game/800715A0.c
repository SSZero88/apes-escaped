#include "common.h"
#include "m2c_macros.h"
#define TIP_717B4 ((struct Tip_800717B4 *)&g_TipState)
#define CD_717B4 ((struct Cd_800717B4 *)&D_800E3890)
typedef struct { s16 f_0; s16 f_2; SVECTOR f_4; s16 f_C; s16 f_E; s16 f_10; s16 f_12; s16 f_14; s16 f_16; } S_BBD34_800716EC;
typedef struct { u8 b[4]; } Loc_800717B4_800717B4;
typedef struct { Loc_800717B4_800717B4 loc; u8 *buf; s32 n; } Req_800717B4_800717B4;
typedef struct { Loc_800717B4_800717B4 pos; u32 size; char name[16]; } File_800717B4_800717B4;
typedef struct { s16 kind; s16 pad2; s16 x; s16 y; s16 z; s16 timer; u8 padC[8]; s16 f_14; u16 used; } Box_800717B4_800717B4;

extern u8 D_800BBD99;
s32 func_8008DF3C(void);

M2C_UNK func_8008C064(s32);
extern struct S_D_800F4DB0 { u8 pad_0[0x20]; s32 f_20; } D_800F4DB0;

extern struct S_D_800BBC50 { s32 f_0; u8 pad_4[0x140]; s32 f_144; u8 pad_148[0x1]; s8 f_149; } g_TipState;
M2C_UNK func_80015AC0(M2C_UNK *, void *);
extern M2C_UNK D_800BBC54;
extern M2C_UNK D_800BBCC4;
void bios_exit(s32) __attribute__((noreturn));
s32 rsin(s32);
s32 rcos(s32);
struct S_D_800BBC50_800716EC { s32 f_0; u8 pad4[0xE0]; S_BBD34_800716EC f_E4[4]; };
struct Tip_800717B4 { u8 pad0[0xE4]; Box_800717B4_800717B4 box[4]; u8 *buf; u8 pad148; u8 f_149; u8 f_14A; };
struct Cd_800717B4 { u8 pad0[8]; s32 f_8; u8 padC[4]; s32 f_10; u8 pad14[0x30]; u8 f_44[0x2C]; };
struct D4DB0_800717B4 { u8 pad0[0x20]; s32 f_20; };
extern M2C_UNK D_800E3890;
void func_8008DEEC(void);
u8 *func_8008C09C(s32);
void Cd_GetFileEntry(File_800717B4_800717B4 *, s32);
s32 CdPosToInt(Loc_800717B4_800717B4 *);
void CdIntToPos(s32, void *);
s32 Cd_QueueCommand(s32, void *, void *, void *);
void Game_SetMode(s32, s32, s32);
void Spike_SetPlayMode(s32);
void Camera_ExitLook(void);
void func_80048748(void);
void Pickup_Drop(s32, SVECTOR *, s32, s32);
void Sound_PlayFixed(s32);

void func_800715A0(void) {
    g_TipState.f_0 = 0;
    g_TipState.f_149 = 0;
}

void func_800715B4(void) {
    func_8008C064(g_TipState.f_144);
    g_TipState.f_149 = 0;
    D_800F4DB0.f_20 = (s32) (D_800F4DB0.f_20 | 0x10);
}

s32 func_800715FC(void) {
    if (D_800BBD99 == 2 && func_8008DF3C() == 0) {
        return 1;
    }
    return 0;
}

void func_8007163C(void *arg0) {
    func_80015AC0(&D_800BBC54, arg0 + (M2C_FIELD(arg0, u16 *, 4) * 4));
    M2C_FIELD(&D_800BBC54, void **, 0x18) = (void *) (arg0 + (M2C_FIELD(arg0, u16 *, 8) * 4));
}

void func_80071694(void *arg0) {
    func_80015AC0(&D_800BBCC4, arg0 + (M2C_FIELD(arg0, u16 *, 4) * 4));
    M2C_FIELD(&D_800BBCC4, void **, 0x18) = (void *) (arg0 + (M2C_FIELD(arg0, u16 *, 8) * 4));
}

s32 func_800716EC(s32 a, SVECTOR *pos, s32 ang) {
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
 * func_8008DF3C says no, allocates a 2 KB buffer, reads one sector of CD file 0x14 (the tips
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
        if (func_8008DF3C() != 0) {
            return;
        }
        func_8008DEEC();
        b->used = 1;
        b->f_14 = 0x1D;
        TIP_717B4->buf = func_8008C09C(0x800);
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
        ((struct D4DB0_800717B4 *)&D_800F4DB0)->f_20 &= ~0x10;
        Camera_ExitLook();
        func_80048748();
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

INCLUDE_ASM("asm/nonmatchings/game/800715A0", Tip_DrawAll);
