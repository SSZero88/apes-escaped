#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { u8 pad0[0xA]; u16 f_A; } S_Mdl_800845E0;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 padA; u8 f_B; } S_846D8_800845E0;
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u32 term; u8 *prims; } DrawBuf_800845E0;
typedef struct { u8 pad0[0xA]; u16 f_A; } S_Mdl_800846D8;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 padA; u8 f_B; } S_846D8_800846D8;
typedef struct { u16 x, y, z; } Pos_83470_80083470;
typedef struct { u16 kind; u16 x; u16 y; u16 z; u8 pad8[8]; } Rec_83470_80083470;
typedef struct { u16 m0; u16 m1; u16 count; u16 pad6; Rec_83470_80083470 recs[1]; } Hdr_83470_80083470;
typedef struct { u8 pad0[4]; s16 f_4; s16 f_6; s16 f_8; u8 kind; u8 f_B; u8 padC[0xB]; u8 blink; } Pk_8435C_8008435C;
typedef struct { s16 vx, vy, vz, pad; } SV_8435C_8008435C;
typedef struct { u8 pad0[0x24]; s32 x, y, z; } Spk_8435C_8008435C;

extern u16 g_RandSeed;
extern s32 D_800F51C4;

extern struct S_D_800BF2B8 { s32 f_0; } D_800BF2B8[];

M2C_UNK Pickup_UpdateAll();
void Pickup_DrawAll(void);
extern struct S_D_800EC350 { u8 pad_0[0x8100]; s32 f_8100; } g_Game;
extern struct S_D_800BEFA0 { u8 pad0[0xA]; u8 f_A; u8 padB[0xD]; } D_800BEFA0[];
extern u8 D_800BF2D8[32];
extern char D_800A6160[];
s32 World_FirstStage(s32);
void bios_printf(const char *, ...);
struct S_D_800EC350_800847EC { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; };
extern struct S_D_800E78C0 { s16 m[3][3]; s16 pad; s32 t[3]; } D_800E78C0;
extern struct S_D_800F4C30 { S_Mdl_800845E0 *f_0; u8 pad4[0xC]; } D_800F4C30[];
extern u8 D_800E7D00[];
void func_8004637C(struct S_D_800E78C0 *);
void Matrix_RotateY(s32, struct S_D_800E78C0 *);
void CompMatrix(struct S_D_800E78C0 *, struct S_D_800E78C0 *, struct S_D_800E78C0 *);
void Model_ProjectVerts(struct S_D_800F4C30 *, struct S_D_800E78C0 *, u8 *);
void func_80017CD4(u32 *, u8 *, struct S_D_800F4C30 *);
struct S_D_800EC350_800845E0 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_800845E0 db[2]; };
extern u32 *D_800EC358;
void func_80016D60(struct S_D_800F4C30 *);
void func_8001CE54(u32 *, u8 *, struct S_D_800F4C30 *);
struct S_D_800F4C30_800846D8 { S_Mdl_800846D8 *f_0; u8 pad4[0xC]; };
struct Game_83470 { u8 pad0[0x8124]; u16 f_8124; u16 f_8126; u8 pad8128[0x120]; Hdr_83470_80083470 *f_8248; };
extern u8 D_800B2920[];
extern u8 D_800BF2F8;
extern u8 D_800B28B0;
extern u8 D_800B28B1;
extern u8 g_SpecterCoinTimer;
extern u8 D_800BF2B5;
s32 SpecterCoin_IsCollected(s32);
void Pickup_Spawn(s32 kind, Pos_83470_80083470 *pos, s32 mode, s32 slot);

/* Clears the 32 pickup slots, then, if the loaded area data (g_Game+0x8248) starts with the tag
 * 0x492E 0x4D54 (marked as read by overwriting its first byte), spawns its pickups: 16-byte
 * records (kind, x, y, z; kind 0xFF ends the list), skipping those whose bit is set in this
 * area's collected mask D_800BF2B8[area] and the Specter coin (kind 4) when this stage's is already collected (SpecterCoin_IsCollected). Then picks the
 * stage's drop table D_800BF2F8 (D_800B2920[stage], at most 4) and resets the drop counters. */
extern Pk_8435C_8008435C D_800BF2A0;
extern Spk_8435C_8008435C g_Spike;
extern s32 D_800EBFC8;
void SetRotMatrix(void *m);
void SetTransMatrix(void *m);
s32 RotTransPers(void *v0, s32 *sxy, s32 *p, s32 *flag);
void Effect_SpawnAt(s32, void *);
void func_800845E0(s32 i, S_846D8_800845E0 *o);
void func_800846D8(s32 i, S_846D8_800846D8 *o);
extern u16 D_800AE8F2;
typedef struct { u8 pad0[0x813C]; u16 f_813C; } Game_83790;

void Pickup_SpawnArea(void) {
    Pos_83470_80083470 pos;
    Hdr_83470_80083470 *hdr;
    s32 i;
    s32 a;
    u32 mask;
    Rec_83470_80083470 *r;

    hdr = (*(struct Game_83470 *)&g_Game).f_8248;
    r = hdr->recs;
    for (i = 31; i >= 0; i--) {
        D_800BEFA0[i].f_A = 0;
        D_800BF2D8[i] = 0;
    }
    if ((u32)(*(struct Game_83470 *)&g_Game).f_8248 == 0x80154000) {
        return;
    }
    if (hdr->m0 != 0x492E) {
        return;
    }
    if (hdr->m1 != 0x4D54) {
        return;
    }
    *(u8 *)hdr = 0x78;
    a = (*(struct Game_83470 *)&g_Game).f_8126 - World_FirstStage((*(struct Game_83470 *)&g_Game).f_8124);
    if (a >= 8) {
        bios_printf(D_800A6160);
        a = 0;
    }
    i = 0;
    mask = ((u32 *)&D_800BF2B8)[a];
    D_800B28B1 = 1;
    for (; i < hdr->count; i++, r++) {
        if (r->kind == 0xFF) {
            break;
        }
        pos.x = r->x;
        pos.y = r->y;
        pos.z = r->z;
        if (!(mask & 1)) {
            if (r->kind == 4) {
                if (SpecterCoin_IsCollected((*(struct Game_83470 *)&g_Game).f_8126) == 0) {
                    Pickup_Spawn(4, &pos, 0, i);
                    D_800BF2D8[i] = 1;
                }
            } else {
                Pickup_Spawn(r->kind, &pos, 0, i);
                D_800BF2D8[i] = 1;
            }
        }
        mask >>= 1;
    }
    D_800BF2F8 = D_800B2920[(*(struct Game_83470 *)&g_Game).f_8124];
    if (D_800BF2F8 >= 5) {
        D_800BF2F8 = 4;
    }
    D_800B28B0 = 3;
    g_SpecterCoinTimer = 0;
    D_800BF2B5 = 0;
    D_800B28B1 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80083470", D_800A6160);


void func_800836E0(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 6);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 8);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x24) = (s16) M2C_FIELD(arg0, u8 *, 0xA);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x26) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s16 *, 0x20) = 0x80;
}

s32 func_8008373C(void) {
    s32 ret = 7;
    u16 r = g_RandSeed * 5 + 1;
    u8 bit;
    g_RandSeed = r;
    bit = (r >> 8) & 1;
    if (!(D_800F51C4 & 8)) {
        return 3;
    }
    if (bit) {
        ret = 6;
    }
    return ret;
}

/* func_80083790: pick the item for a kind-2 drop (Pickup_Drop): roll 1..25 and return 5 when the
 * roll is below (n - 1) * 10, n = g_Game+0x813C (the lives counter? 5 at a new game) clamped to
 * 1..10, else 2. While the cooldown D_800B28B0 runs it returns 5; otherwise it restarts it at 9. */
s32 func_80083790(void) {
    s32 ret = 2;
    u16 r = D_800AE8F2 * 5 + 1;
    u8 p = ((u32)((r >> 8) * 25) >> 6) + 1;
    s32 n;
    s32 c;
    D_800AE8F2 = r;
    n = ((Game_83790 *)&g_Game)->f_813C;
    if (D_800B28B0 != 0) {
        return 5;
    }
    D_800B28B0 = 9;
    c = (n <= 0) ? 1 : (n >= 11) ? 10 : n;
    if (p < (c - 1) * 10) {
        ret = 5;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/game/80083470", Pickup_Spawn);

INCLUDE_ASM("asm/nonmatchings/game/80083470", Pickup_Drop);

INCLUDE_ASM("asm/nonmatchings/game/80083470", Pickup_UpdateAll);

INCLUDE_RODATA("asm/nonmatchings/game/80083470", jtbl_800A6180);


/* Draws every live pickup: those blinking out (timer +0x17 in 1..45) skip odd frames; culled by
 * RotTransPers depth (<= min(D_800EBFC8, 0x800)) and screen bounds, then the kind (1-7) picks the
 * model (0xD-0x13) and drawer (func_800845E0 or func_800846D8). While g_SpecterCoinTimer counts down it
 * also draws model 0xD spinning down onto Spike, with effect 0x104 every 8th frame. */
void Pickup_DrawAll(void) {
    SV_8435C_8008435C pos;
    s32 sxy;
    s32 flag;
    s32 z;
    s32 maxz;
    s32 i;
    Pk_8435C_8008435C *p;
    Pk_8435C_8008435C *q;
    s32 y;

    maxz = 0x800;
    if (D_800EBFC8 < 0x800) {
        maxz = D_800EBFC8;
    }
    for (i = 31, p = ((Pk_8435C_8008435C *)&D_800BEFA0); i >= 0; i--, p++) {
        if (p->kind == 0) {
            continue;
        }
        if (p->blink - 1U < 45 && !(p->blink & 1)) {
            continue;
        }
        SetRotMatrix(((u8 *)&D_800E78C0));
        SetTransMatrix(((u8 *)&D_800E78C0));
        z = RotTransPers(&p->f_4, &sxy, &flag, &flag);
        if (z > maxz || z <= 0) {
            continue;
        }
        y = sxy;
        if ((u32)((s16)sxy + 0x20) >= 0x1C1) {
            continue;
        }
        y >>= 16;
        if (y < -0x20) {
            continue;
        }
        if (y >= 0x111) {
            continue;
        }
        switch (p->kind) {
        case 4:
            func_800846D8(0xD, p);
            break;
        case 1:
            func_800845E0(0xE, p);
            break;
        case 3:
            func_800846D8(0xF, p);
            break;
        case 6:
            func_800845E0(0x12, p);
            break;
        case 7:
            func_800845E0(0x13, p);
            break;
        case 2:
            func_800845E0(0x11, p);
            break;
        case 5:
            func_800846D8(0x10, p);
            break;
        }
    }
    if (g_SpecterCoinTimer != 0) {
        q = &D_800BF2A0;
        q->f_B = g_SpecterCoinTimer * 4;
        pos.vx = g_Spike.x;
        pos.vy = g_Spike.y - 0x200 + g_SpecterCoinTimer * 8;
        pos.vz = g_Spike.z;
        if (!(g_SpecterCoinTimer & 7)) {
            Effect_SpawnAt(0x104, &pos);
        }
        q->f_4 = pos.vx;
        q->f_6 = pos.vy;
        q->f_8 = pos.vz;
        func_800846D8(0xD, q);
        g_SpecterCoinTimer--;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80083470", jtbl_800A61B8_pad);


void Pickup_Frame(void) {
    if (g_Game.f_8100 == 0) {
        Pickup_UpdateAll();
    }
    Pickup_DrawAll();
}

void func_800845E0(s32 i, S_846D8_800845E0 *o) {
    struct S_D_800E78C0 m;
    struct S_D_800F4C30 *s;
    u8 *buf;
    func_8004637C(&m);
    m.t[0] = o->f_4;
    m.t[1] = o->f_6;
    m.t[2] = o->f_8;
    Matrix_RotateY(o->f_B << 6, &m);
    CompMatrix(&D_800E78C0, &m, &m);
    s = &D_800F4C30[i];
    if (s->f_0->f_A != 0) {
        buf = (u8 *)0x1F800080;
    } else {
        buf = D_800E7D00;
    }
    Model_ProjectVerts(s, &m, buf);
    func_80017CD4(((struct S_D_800EC350_800845E0 *)&g_Game)->db[((struct S_D_800EC350_800845E0 *)&g_Game)->cur].ot, buf, s);
}

void func_800846D8(s32 i, S_846D8_800846D8 *o) {
    struct S_D_800E78C0 m;
    struct S_D_800F4C30_800846D8 *s;
    u8 *buf;
    func_8004637C(&m);
    m.t[0] = o->f_4;
    m.t[1] = o->f_6;
    m.t[2] = o->f_8;
    Matrix_RotateY(o->f_B << 6, &m);
    CompMatrix(&D_800E78C0, &m, &m);
    s = &((struct S_D_800F4C30_800846D8 *)&D_800F4C30)[i];
    if (s->f_0->f_A != 0) {
        buf = (u8 *)0x1F800080;
    } else {
        buf = D_800E7D00;
    }
    Model_ProjectVerts(s, &m, buf);
    func_80016D60(s);
    *(u8 *)0x1F8003F4 = 2;
    func_8001CE54(D_800EC358, buf, s);
}

void func_800847C4(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        D_800BF2B8[i].f_0 = 0;
    }
}

void Pickup_SaveAreaMask(void) {
    s32 k = ((struct S_D_800EC350_800847EC *)&g_Game)->f_8126 - World_FirstStage(((struct S_D_800EC350_800847EC *)&g_Game)->f_8124);
    u32 bits;
    s32 i;
    if (k >= 8) {
        bios_printf(D_800A6160);
        k = 0;
    }
    bits = 0;
    for (i = 31; i >= 0; i--) {
        bits <<= 1;
        if (D_800BEFA0[i].f_A == 0 || D_800BF2D8[i] == 0) {
            bits |= 1;
        }
    }
    ((u32 *)&D_800BF2B8)[k] = bits;
}

void func_800848B0(void) {

}
