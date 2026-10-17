#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 b[4]; } Loc_9B7FC_8009B7FC;
typedef struct { Loc_9B7FC_8009B7FC loc; u8 *buf; s32 n; } Req_9B7FC_8009B7FC;
typedef struct { Loc_9B7FC_8009B7FC pos; u32 size; char name[16]; } File_9B7FC_8009B7FC;

extern u8 D_800F5AA0;
extern s32 D_800F5AAC;
extern s32 D_800F5AB0;
extern s32 D_800F4DD0;
extern struct S_D_800E3890 { s32 f_0; u8 pad4[0x40]; u8 f_44[0x2C]; u8 f_70[4]; } D_800E3890;
void Spike_SetPlayMode(s32);
void Cd_GetFileEntry(File_9B7FC_8009B7FC *, s32);
s32 Cd_QueueCommand(s32, void *, void *, void *);
void Screen_DrawLetterbox(s32, s32, s32);
void func_80137248(s32);
struct S_D_800F5AA0_8009B7FC { u8 state; u8 loaded; u8 ready; u8 arg; s16 fade; };

u8 Overlay_GetState(void) {
    return D_800F5AA0;
}

void Overlay_Request(s8 arg0) {
    M2C_FIELD(&D_800F5AA0, s8 *, 0) = 1;
    M2C_FIELD(&D_800F5AA0, s8 *, 3) = arg0;
}

void func_8009B7C8(s32 arg0) {
    M2C_FIELD(&D_800F5AA0, s32 *, 0) = 0;
    M2C_FIELD(&D_800F5AA0, s32 *, 8) = arg0;
    M2C_FIELD(&D_800F5AA0, s32 *, 0xC) = 0;
    M2C_FIELD(&D_800F5AA0, s32 *, 0x10) = 0;
}

void func_8009B7E4(s32 arg0) {
    D_800F5AAC = arg0;
}

void func_8009B7F0(s32 arg0) {
    D_800F5AB0 = arg0;
}

void Overlay_Update(void) {
    struct S_D_800F5AA0_8009B7FC *s = ((struct S_D_800F5AA0_8009B7FC *)&D_800F5AA0);
    s32 st = ((struct S_D_800F5AA0_8009B7FC *)&D_800F5AA0)->state;
    s32 t;
    Req_9B7FC_8009B7FC req;
    File_9B7FC_8009B7FC f;

    switch (st) {
    case 1:
        D_800F4DD0 = 0;
        if (s->loaded == 0) {
            Spike_SetPlayMode(0xB);
            if (D_800E3890.f_0 != 0) {
                break;
            }
            Cd_GetFileEntry(&f, 0x180);
            req.loc = f.pos;
            req.buf = (u8 *)0x80136000;
            req.n = f.size >> 11;
            Cd_QueueCommand(0xE, D_800E3890.f_70, D_800E3890.f_44, 0);
            Cd_QueueCommand(2, &req, D_800E3890.f_44, 0);
            Cd_QueueCommand(0x20, &req, D_800E3890.f_44, &s->ready);
            s->loaded = st;
            s->fade = 0;
            break;
        }
        {
            s32 u = s->fade;
            if (u < 0xF0) {
                u += 0x10;
                s->fade = u;
            }
        }
        Screen_DrawLetterbox(0x1E, 0x1E, s->fade);
        if (s->ready != 0) {
            func_80137248(s->arg);
            ((struct S_D_800F5AA0_8009B7FC *)&D_800F5AA0)->state = 2;
            s->fade = 0xF0;
            Screen_DrawLetterbox(0x1E, 0x1E, 0xF0);
        }
        break;
    case 0:
        break;
    case 2:
        t = s->fade;
        if (t > 0) {
            s->fade = t - 0x10;
            Screen_DrawLetterbox(0x1E, 0x1E, s->fade);
            break;
        }
        *(s32 *)((struct S_D_800F5AA0_8009B7FC *)&D_800F5AA0) = 0;
        D_800F4DD0 = 0x32;
        Spike_SetPlayMode(0);
        break;
    }
}

extern u8 g_Game[];
typedef struct { u32 tag; u32 rgbc; u32 xy; u32 wh; } Tile_9B9C8;
typedef struct { u32 tag; u32 code; } DrTpage_9B9C8;

/* Cinematic letterbox: black semi-transparent TILEs over the top `top` rows and the bottom `bottom`
   rows (shade c), then a texpage reset. addPrim with hard a0/v0 temps; the second needs the
   do { } while (0). */
void Screen_DrawLetterbox(s32 top, s32 bottom, s32 c) {
    Tile_9B9C8 *p = (Tile_9B9C8 *)G_DRAW.prim;
    u32 *ot = G_DRAW.ot;
    u32 rgb = (c << 16) | (c << 8) | c;

    p->rgbc = rgb;
    ((u8 *)p)[3] = 3;
    ((u8 *)p)[7] = 0x62;
    p->xy = 0;
    p->wh = (top << 16) | 0x180;
    ADD_PRIM_R(ot, p, "$4", "$2");
    p++;
    p->rgbc = rgb;
    ((u8 *)p)[3] = 3;
    ((u8 *)p)[7] = 0x62;
    p->xy = (0xF0 - bottom) << 16;
    p->wh = (bottom << 16) | 0x180;
    do { ADD_PRIM_R(ot, p, "$4", "$2"); } while (0);
    p++;
    ((u8 *)p)[3] = 1;
    ((DrTpage_9B9C8 *)p)->code = 0xE1000240;
    ADD_PRIM_R(ot, p, "$4", "$2");
    p = (Tile_9B9C8 *)((u8 *)p + 8);
    G_DRAW.prim = (u8 *)p;
}
