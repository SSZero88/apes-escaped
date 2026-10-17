#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s32 w[4]; } S16B_80010A10;
typedef struct { s32 w[8]; } S32B_80010A10;
typedef struct { s32 w[32]; } S128B_80010A10;
typedef struct { s32 pad0[6]; u8 f_18[16]; u8 pad28[0x778]; } Save7A0_8001078C;
typedef struct { u8 pad0[0x180]; s16 f_180; s16 f_182; u8 pad184[0x14]; u8 f_198[16]; u8 pad1A8[0x5F8]; } S_10720_80010720;

s32 MemCard_Request(s32 cmd, s32 unused);
extern struct S_D_800E3880 { s16 f_0; u8 pad_2[0x2]; s16 f_4; u8 pad_6[0x2]; u16 f_8; } D_800E3880;

M2C_UNK MemCardInit(M2C_UNK);
M2C_UNK MemCardStart();
extern s16 D_800E3888;
M2C_UNK MemCardEnd();
M2C_UNK MemCardStop();
extern struct S_D_800E1880 { u8 magic[2]; u8 type; u8 blocks; S16B_80010A10 title; u8 pad14[0x4C]; S32B_80010A10 clut; S128B_80010A10 icon; } D_800E1880;
extern S16B_80010A10 D_800A3910;
extern S32B_80010A10 D_800A6AB0;
extern S128B_80010A10 D_800A6AD0;
extern u8 D_800A6BD0[16];
extern u8 D_800E3886;
Save7A0_8001078C *func_8009628C(void);
s32 MemCardClose(void);
s32 MemCard_Retry(void);
extern char D_800A37F0[];
extern char D_800A3800[];
/* Resets the 4 save slots (0x7A0 bytes each): +0x180 = -1, +0x182 = 0, and the 16-byte slot
 * name from template D_800A6BD0 (game font codes) with its 5th character set to the slot digit. */
s32 Save_InitSlots(S_10720_80010720 *a);
s32 MemCardSync(s32, s32 *, s32 *);
s32 MemCardAccept(s32);
s32 MemCardExist(s32);
s32 MemCardReadFile(s32, char *, void *, s32, s32);
s32 MemCardWriteFile(s32, char *, void *, s32, s32);
s32 MemCardCreateFile(s32, char *, s32);
s32 MemCardFormat(s32);
s32 MemCardCallback(void *);
s32 MemCard_BuildHeader(void);
void MemCard_Callback(s32, s32);
struct S_D_800E3880_80010000 { s16 status; u8 pad2[2]; s16 cmd; u8 pad6[6]; u8 *buf; };

INCLUDE_RODATA("asm/nonmatchings/game/80010000", D_800A37F0);
INCLUDE_RODATA("asm/nonmatchings/game/80010000", D_800A3800);

s32 MemCard_Request(s32 cmd, s32 unused) {
    s32 c;
    s32 r;

    switch (cmd) {
    case 7:
        Save_InitSlots(((u8 *)&D_800E1880));
        break;
    case 0:
    case 10:
    case 17:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCardAccept(0);
        break;
    case 4:
    case 11:
    case 16:
        if (MemCardSync(1, &c, &r) < 0) {
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
            MemCardExist(0);
        }
        break;
    case 1:
        Save_InitSlots(((u8 *)&D_800E1880));
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCardReadFile(0, D_800A37F0, ((u8 *)&D_800E1880), 0, 0x2000);
        break;
    case 12:
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCardReadFile(0, D_800A3800, ((u8 *)&D_800E1880), 0, 0x180);
        break;
    case 5:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        switch (MemCardCreateFile(0, D_800A37F0, 1)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 4:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -8;
            break;
        case 6:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -6;
            break;
        case 7:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -4;
            break;
        }
        if (((struct S_D_800E3880_80010000 *)&D_800E3880)->status != 0) {
            return -1;
        }
        MemCard_BuildHeader();
        MemCardWriteFile(0, D_800A37F0, ((u8 *)&D_800E1880), 0, 0x100);
        break;
    case 2:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCard_BuildHeader();
        MemCardWriteFile(0, D_800A37F0, ((u8 *)&D_800E1880), 0, 0x2000);
        break;
    case 13:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        switch (MemCardCreateFile(0, D_800A3800, 0xC)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 4:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -8;
            break;
        case 6:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -6;
            break;
        case 7:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -4;
            break;
        }
        if (((struct S_D_800E3880_80010000 *)&D_800E3880)->status != 0) {
            return -1;
        }
        MemCardWriteFile(0, D_800A3800, ((struct S_D_800E3880_80010000 *)&D_800E3880)->buf, 0, 0x18000);
        break;
    case 14:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCardWriteFile(0, D_800A3800, ((struct S_D_800E3880_80010000 *)&D_800E3880)->buf, 0, 0x18000);
        break;
    case 15:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        MemCardWriteFile(0, D_800A3800, ((struct S_D_800E3880_80010000 *)&D_800E3880)->buf, 0, 0x180);
        break;
    case 3:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 1;
        switch (MemCardFormat(0)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&D_800E3880)->status = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        default:
            break;
        }
        break;
    case 8:
        MemCardSync(0, &c, &r);
        MemCardCallback(MemCard_Callback);
        break;
    case 9:
        MemCardSync(0, &c, &r);
        MemCardCallback(0);
        break;
    }
    return 0;
}



/* MemCardCallback handler. ev is the libmcrd function that finished (1 Exist, 2 Accept, 3/5 read,
 * 4/6 write), res its result (0 none, 1 no card, 2 invalid, 3 new card, 4 unformatted, 5 no file).
 * Sets the card status D_800E3880.f_0 (0 ok, -5 no file, -7 no card, -8 unformatted), retries
 * invalid accesses (MemCard_Retry), and on a new card restarts the pending operation (f_4). */
void MemCard_Callback(s32 ev, s32 res) {
    switch (ev) {
    case 1:
        switch ((u32)res) {
        case 0:
            D_800E3880.f_0 = 0;
            break;
        case 1:
            D_800E3880.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (D_800E3880.f_4 == 4) {
                MemCard_Request(0, 0);
            } else if (D_800E3880.f_4 == 0xB) {
                MemCard_Request(0xA, 0);
            } else {
                MemCard_Request(0x11, 0);
            }
            break;
        }
        break;
    case 2:
        switch (res) {
        case 0:
            D_800E3880.f_0 = 0;
            break;
        case 1:
            D_800E3880.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (D_800E3880.f_4 == 0) {
                MemCard_Request(1, 0);
            } else if (D_800E3880.f_4 == 0xA) {
                MemCard_Request(0xC, 0);
            } else {
                D_800E3880.f_0 = 0;
            }
            break;
        case 4:
            D_800E3880.f_0 = -8;
            break;
        }
        break;
    case 3:
    case 5:
        switch (res) {
        case 0:
            D_800E3880.f_0 = 0;
            MemCardClose();
            break;
        case 1:
            D_800E3880.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (D_800E3880.f_4 == 1) {
                MemCard_Request(1, 0);
            } else {
                MemCard_Request(0xC, 0);
            }
            break;
        case 4:
            break;
        case 5:
            D_800E3880.f_0 = -5;
            break;
        }
        break;
    case 4:
    case 6:
        switch (res) {
        case 0:
            D_800E3880.f_0 = 0;
            MemCardClose();
            break;
        case 1:
            D_800E3880.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            MemCard_Request(1, 0);
            break;
        case 4:
            break;
        case 5:
            D_800E3880.f_0 = -5;
            break;
        }
        break;
    }
}



s32 MemCard_Retry(void) {
    u16 temp_v0;

    temp_v0 = D_800E3880.f_8 + 1;
    D_800E3880.f_8 = temp_v0;
    if ((s16) temp_v0 >= 6) {
        D_800E3880.f_0 = -1;
        D_800E3880.f_8 = 0U;
    } else {
        MemCard_Request(D_800E3880.f_4, 0);
    }
    return 0;
}

s32 Save_InitSlots(S_10720_80010720 *a) {
    s32 j;
    s32 k;
    for (j = 0; j < 4; j++) {
        a[j].f_180 = -1;
        a[j].f_182 = 0;
        D_800A6BD0[4] = j + 0x6B;
        for (k = 0; k < 16; k++) {
            a->f_198[k + j * sizeof(S_10720_80010720)] = D_800A6BD0[k];
        }
    }
    return 0;
}

s32 func_8001078C(Save7A0_8001078C *s) {
    u8 buf[16];
    s32 i;

    if (s->f_18[0] == 0) {
        D_800A6BD0[4] = D_800E3886 + 0x6B;
        for (i = 0; i < 16; i++) {
            buf[i] = D_800A6BD0[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            buf[i] = s->f_18[i];
        }
    }
    *s = *func_8009628C();
    for (i = 0; i < 16; i++) {
        s->f_18[i] = buf[i];
    }
    return 0;
}

typedef struct { s32 w[8]; } Pal_8001088C;
typedef struct { s32 w[0x20]; } Icon_8001088C;
typedef struct { u8 magic[2]; u8 type; u8 blocks; s32 title[0x10]; u8 rsv[0xC]; u16 f_50; u8 tag[4]; u8 f_56; u8 f_57; s32 f_58; s32 f_5C; Pal_8001088C pal; Icon_8001088C icon; } Hdr_8001088C;
extern Hdr_8001088C D_800E1880_h asm("D_800E1880");
extern Icon_8001088C D_800E1980_h asm("D_800E1980");
extern s32 D_800A38F8_h[] asm("D_800A38F8");
extern Pal_8001088C D_800A6AB0_h asm("D_800A6AB0");
extern Icon_8001088C D_800A6AD0_h asm("D_800A6AD0");
extern Icon_8001088C D_800A6B50_h asm("D_800A6B50");
void *memcpy(void *, const void *, unsigned int);
/* Fills the memory card save header in D_800E1880: "SC" magic, icon type 0x11 (one-frame
 * icon), 1 block, the title from D_800A38F8, reserved bytes cleared, tag "CRD0" at +0x52, the
 * icon palette (D_800A6AB0) and image (D_800A6AD0), then copies D_800A6B50 to header + 0x100. */
s32 MemCard_BuildHeader(void) {
    u8 *p;
    s32 i;
    D_800E1880_h.magic[0] = 'S';
    D_800E1880_h.magic[1] = 'C';
    D_800E1880_h.type = 0x11;
    D_800E1880_h.blocks = 1;
    memcpy(D_800E1880_h.title, D_800A38F8_h, 21);
    for (i = 11, p = (u8 *)&D_800E1880_h + i; i >= 0; i--, p--) { p[0x44] = 0; }
    D_800E1880_h.f_50 = 1;
    D_800E1880_h.tag[0] = 'C';
    D_800E1880_h.tag[1] = 'R';
    D_800E1880_h.tag[2] = 'D';
    D_800E1880_h.tag[3] = '0';
    D_800E1880_h.f_56 = 0;
    D_800E1880_h.f_57 = 0;
    D_800E1880_h.f_58 = 0;
    D_800E1880_h.f_5C = 0;
    D_800E1880_h.pal = D_800A6AB0_h;
    D_800E1880_h.icon = D_800A6AD0_h;
    D_800E1980_h = D_800A6B50_h;
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/game/80010000", D_800A38F8);


/* Builds the memory-card save header: "SC" magic, icon, block count, title,
 * palette and icon bitmap.
 */
s32 MemCard_BuildSaveHeader(void) {
    D_800E1880.magic[0] = 'S';
    D_800E1880.magic[1] = 'C';
    D_800E1880.type = 0x11;
    D_800E1880.title = D_800A3910;
    D_800E1880.blocks = 3;
    D_800E1880.clut = D_800A6AB0;
    D_800E1880.icon = D_800A6AD0;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80010000", D_800A3910);


void MemCard_Start(void) {
    MemCardInit(0);
    MemCardStart();
    D_800E3888 = 0;
}

void MemCard_Stop(void) {
    MemCardStop();
    MemCardEnd();
}
