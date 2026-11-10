#include "common.h"
#include "m2c_macros.h"
#include "common.h"
typedef struct { s32 w[4]; } S16B_80010A10;
typedef struct { s32 w[8]; } S32B_80010A10;
typedef struct { s32 w[32]; } S128B_80010A10;
typedef struct { s32 pad0[6]; u8 f_18[16]; u8 pad28[0x778]; } Save7A0_8001078C;
typedef struct { u8 pad0[0x180]; s16 f_180; s16 f_182; u8 pad184[0x14]; u8 f_198[16]; u8 pad1A8[0x5F8]; } S_10720_80010720;

s32 MemCard_Request(s32 cmd, s32 unused);
extern struct S_D_800E3880 { s16 f_0; u8 pad_2[0x2]; s16 f_4; u8 pad_6[0x2]; u16 f_8; } g_MemCard;

M2C_UNK MemCardInit(M2C_UNK);
M2C_UNK MemCardStart();
extern s16 D_800E3888;
M2C_UNK MemCardEnd();
M2C_UNK MemCardStop();
extern struct S_D_800E1880 { u8 magic[2]; u8 type; u8 blocks; S16B_80010A10 title; u8 pad14[0x4C]; S32B_80010A10 clut; S128B_80010A10 icon; } g_MemCardImage;
extern S16B_80010A10 MemCard_PocketTitle;
extern S32B_80010A10 MemCard_IconClut;
extern S128B_80010A10 MemCard_IconImage;
extern u8 MemCard_SlotNameTemplate[16];
extern u8 g_MemCardSlot;
Save7A0_8001078C *func_8009628C(void);
s32 MemCardClose(void);
s32 MemCard_Retry(void);
extern char MemCard_SaveFileName[];
extern char MemCard_PocketFileName[];
/* Resets the 4 save slots (0x7A0 bytes each): +0x180 = -1, +0x182 = 0, and the 16-byte slot
 * name from template MemCard_SlotNameTemplate (game font codes) with its 5th character set to the slot digit. */
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

INCLUDE_RODATA("asm/nonmatchings/game/80010000_memcard", MemCard_SaveFileName);
INCLUDE_RODATA("asm/nonmatchings/game/80010000_memcard", MemCard_PocketFileName);

s32 MemCard_Request(s32 cmd, s32 unused) {
    s32 c;
    s32 r;

    switch (cmd) {
    case 7:
        Save_InitSlots(((u8 *)&g_MemCardImage));
        break;
    case 0:
    case 10:
    case 17:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCardAccept(0);
        break;
    case 4:
    case 11:
    case 16:
        if (MemCardSync(1, &c, &r) < 0) {
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
            MemCardExist(0);
        }
        break;
    case 1:
        Save_InitSlots(((u8 *)&g_MemCardImage));
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCardReadFile(0, MemCard_SaveFileName, ((u8 *)&g_MemCardImage), 0, 0x2000);
        break;
    case 12:
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCardReadFile(0, MemCard_PocketFileName, ((u8 *)&g_MemCardImage), 0, 0x180);
        break;
    case 5:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        switch (MemCardCreateFile(0, MemCard_SaveFileName, 1)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 4:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -8;
            break;
        case 6:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -6;
            break;
        case 7:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -4;
            break;
        }
        if (((struct S_D_800E3880_80010000 *)&g_MemCard)->status != 0) {
            return -1;
        }
        MemCard_BuildHeader();
        MemCardWriteFile(0, MemCard_SaveFileName, ((u8 *)&g_MemCardImage), 0, 0x100);
        break;
    case 2:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCard_BuildHeader();
        MemCardWriteFile(0, MemCard_SaveFileName, ((u8 *)&g_MemCardImage), 0, 0x2000);
        break;
    case 13:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        switch (MemCardCreateFile(0, MemCard_PocketFileName, 0xC)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 4:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -8;
            break;
        case 6:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -6;
            break;
        case 7:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -4;
            break;
        }
        if (((struct S_D_800E3880_80010000 *)&g_MemCard)->status != 0) {
            return -1;
        }
        MemCardWriteFile(0, MemCard_PocketFileName, ((struct S_D_800E3880_80010000 *)&g_MemCard)->buf, 0, 0x18000);
        break;
    case 14:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCardWriteFile(0, MemCard_PocketFileName, ((struct S_D_800E3880_80010000 *)&g_MemCard)->buf, 0, 0x18000);
        break;
    case 15:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        MemCardWriteFile(0, MemCard_PocketFileName, ((struct S_D_800E3880_80010000 *)&g_MemCard)->buf, 0, 0x180);
        break;
    case 3:
        MemCardSync(0, &c, &r);
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->cmd = cmd;
        ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 1;
        switch (MemCardFormat(0)) {
        case 0:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = 0;
            break;
        case 1:
            ((struct S_D_800E3880_80010000 *)&g_MemCard)->status = -7;
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
 * Sets the card status g_MemCard.f_0 (0 ok, -5 no file, -7 no card, -8 unformatted), retries
 * invalid accesses (MemCard_Retry), and on a new card restarts the pending operation (f_4). */
void MemCard_Callback(s32 ev, s32 res) {
    switch (ev) {
    case 1:
        switch ((u32)res) {
        case 0:
            g_MemCard.f_0 = 0;
            break;
        case 1:
            g_MemCard.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (g_MemCard.f_4 == 4) {
                MemCard_Request(0, 0);
            } else if (g_MemCard.f_4 == 0xB) {
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
            g_MemCard.f_0 = 0;
            break;
        case 1:
            g_MemCard.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (g_MemCard.f_4 == 0) {
                MemCard_Request(1, 0);
            } else if (g_MemCard.f_4 == 0xA) {
                MemCard_Request(0xC, 0);
            } else {
                g_MemCard.f_0 = 0;
            }
            break;
        case 4:
            g_MemCard.f_0 = -8;
            break;
        }
        break;
    case 3:
    case 5:
        switch (res) {
        case 0:
            g_MemCard.f_0 = 0;
            MemCardClose();
            break;
        case 1:
            g_MemCard.f_0 = -7;
            break;
        case 2:
            MemCard_Retry();
            break;
        case 3:
            if (g_MemCard.f_4 == 1) {
                MemCard_Request(1, 0);
            } else {
                MemCard_Request(0xC, 0);
            }
            break;
        case 4:
            break;
        case 5:
            g_MemCard.f_0 = -5;
            break;
        }
        break;
    case 4:
    case 6:
        switch (res) {
        case 0:
            g_MemCard.f_0 = 0;
            MemCardClose();
            break;
        case 1:
            g_MemCard.f_0 = -7;
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
            g_MemCard.f_0 = -5;
            break;
        }
        break;
    }
}



s32 MemCard_Retry(void) {
    u16 temp_v0;

    temp_v0 = g_MemCard.f_8 + 1;
    g_MemCard.f_8 = temp_v0;
    if ((s16) temp_v0 >= 6) {
        g_MemCard.f_0 = -1;
        g_MemCard.f_8 = 0U;
    } else {
        MemCard_Request(g_MemCard.f_4, 0);
    }
    return 0;
}

s32 Save_InitSlots(S_10720_80010720 *a) {
    s32 j;
    s32 k;
    for (j = 0; j < 4; j++) {
        a[j].f_180 = -1;
        a[j].f_182 = 0;
        MemCard_SlotNameTemplate[4] = j + 0x6B;
        for (k = 0; k < 16; k++) {
            a->f_198[k + j * sizeof(S_10720_80010720)] = MemCard_SlotNameTemplate[k];
        }
    }
    return 0;
}

s32 Save_CopyToSlot(Save7A0_8001078C *s) {
    u8 buf[16];
    s32 i;

    if (s->f_18[0] == 0) {
        MemCard_SlotNameTemplate[4] = g_MemCardSlot + 0x6B;
        for (i = 0; i < 16; i++) {
            buf[i] = MemCard_SlotNameTemplate[i];
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
extern Hdr_8001088C D_800E1880_h asm("g_MemCardImage");
extern Icon_8001088C D_800E1980_h asm("D_800E1980");
extern s32 D_800A38F8_h[] asm("MemCard_SaveTitle");
extern Pal_8001088C D_800A6AB0_h asm("MemCard_IconClut");
extern Icon_8001088C D_800A6AD0_h asm("MemCard_IconImage");
extern Icon_8001088C D_800A6B50_h asm("D_800A6B50");
void *memcpy(void *, const void *, unsigned int);
/* Fills the memory card save header in g_MemCardImage: "SC" magic, icon type 0x11 (one-frame
 * icon), 1 block, the title from MemCard_SaveTitle, reserved bytes cleared, tag "CRD0" at +0x52, the
 * icon palette (MemCard_IconClut) and image (MemCard_IconImage), then copies D_800A6B50 to header + 0x100. */
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


INCLUDE_RODATA("asm/nonmatchings/game/80010000_memcard", MemCard_SaveTitle);


/* Builds the memory-card save header: "SC" magic, icon, block count, title,
 * palette and icon bitmap.
 */
s32 MemCard_BuildSaveHeader(void) {
    g_MemCardImage.magic[0] = 'S';
    g_MemCardImage.magic[1] = 'C';
    g_MemCardImage.type = 0x11;
    g_MemCardImage.title = MemCard_PocketTitle;
    g_MemCardImage.blocks = 3;
    g_MemCardImage.clut = MemCard_IconClut;
    g_MemCardImage.icon = MemCard_IconImage;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80010000_memcard", MemCard_PocketTitle);


void MemCard_Start(void) {
    MemCardInit(0);
    MemCardStart();
    D_800E3888 = 0;
}

void MemCard_Stop(void) {
    MemCardStop();
    MemCardEnd();
}
