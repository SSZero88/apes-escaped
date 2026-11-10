#include "common.h"
#include "m2c_macros.h"

extern M2C_UNK D_80138338;

typedef struct { s16 x, y, w, h; } Rect_80136000;
extern Rect_80136000 D_80137830;
extern u8 D_80137840[];
extern u8 D_80137860[];
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 f_8120; u8 pad8122[0x38]; s16 f_815A; u8 pad815C[0x15E]; u16 f_82BA; } g_Game_80136000 asm("g_Game");
void Cd_StartLoadList(void *);
s32 Cd_PollLoadList();
void Cd_Update(void);
s32 Gfx_InitDisplay(void);
s32 ResetGraph(s32 mode);
void DrawSync(s32);
s32 VSync(s32 mode);
void Sound_ResumeStreams(void);
void Sound_UnloadBanks(s32);
void func_8001325C(s32);
void Gfx_BeginFrame(void);
void func_8008C390(void);
void func_80136590(void);
void func_80136E58(void);
void *PutDrawEnv(void *env);
void *PutDispEnv(void *env);
void DrawOTag(u32 *p);

s32 func_80136000(void) {
    Rect_80136000 r;

    r = D_80137830;
    Gfx_InitDisplay();
    ResetGraph(1);
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    if (g_Game_80136000.f_8120 == 0x1D) {
        Cd_StartLoadList(D_80137840);
    } else {
        Cd_StartLoadList(D_80137860);
    }
    while (Cd_PollLoadList() == 0) {
        Cd_Update();
        VSync(2);
    }
    Sound_ResumeStreams();
    g_Game_80136000.db[1].env[0x18] = 1;
    g_Game_80136000.db[0].env[0x18] = 1;
    { u8 *e = g_Game_80136000.db[0].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    { u8 *e = g_Game_80136000.db[1].env; e[0x19] = 0; e[0x1A] = 0; e[0x1B] = 0; }
    g_Game_80136000.cur = 0;
    g_Game_80136000.f_82BA |= 2;
    func_80136590();
    func_80136E58();
    func_80137374();
    while (func_8001325C(0), Gfx_BeginFrame(), func_8008C390(), func_80136730() == 0) {
        DrawSync(0);
        VSync(2);
        g_Game_80136000.frame++;
        PutDispEnv(&g_Game_80136000.db[g_Game_80136000.cur].env[0x5C]);
        PutDrawEnv(g_Game_80136000.db[g_Game_80136000.cur].env);
        DrawOTag(&g_Game_80136000.db[g_Game_80136000.cur].ot[0xFFF]);
    }
    Sound_UnloadBanks(1);
    if (g_Game_80136000.f_8120 == 0x1D) {
        g_Game_80136000.f_8120 = 0x1A;
        g_Game_80136000.f_815A = 5;
    } else {
        g_Game_80136000.f_8120 = 0x1A;
        g_Game_80136000.f_815A = 6;
    }
    return 0;
}

typedef struct { u32 addr : 24; u32 len : 8; } Tag_8013626C;
typedef struct { u32 tag; u32 tpage; u32 code; u32 xy; u32 uvclut; u32 wh; } Sprt_8013626C;
extern GameDraw g_Game_8013626C asm("g_Game");
extern Sprt_8013626C *D_800EC354_8013626C asm("D_800EC354");
extern u16 D_80137980[];
extern u8 D_80137880[];

u8 *func_8013626C(u8 *s, s32 x, s16 y, s32 flags) {
    Sprt_8013626C *p;
    u32 *ot;
    u32 semi;
    s32 opaque;
    s32 a;

    semi = 0;
    opaque = 1;
    if (flags & 8) {
        semi = 0x2000000;
        opaque = 0;
    }
    flags &= 3;
    p = (Sprt_8013626C *)g_Game_8013626C.prim;
    {
        s32 b = (s32)g_Game_8013626C.db[g_Game_8013626C.cur].ot;
        ot = (u32 *)(opaque * 4 + b);
    }
    for (;;) {
        u32 c = *s;

        if (c == 0) {
            break;
        }
        if (c == 0xD) {
            s++;
            break;
        }
        if ((u16)(y + 0x20) < 0x131) {
            a = 0x80;
            if (y < 0x10) {
                a = y * 4;
                semi = 0x2000000;
            }
            if (y >= 0xD0) {
                a = (0xF0 - y) * 4;
            }
            if (!opaque) {
                a = 0x10;
            }
            a = a < 0 ? 0 : (a >= 0x100 ? 0xFF : a);
            {
                register u32 tp asm("$2") = 0xE1000226;
                register u32 wh asm("$4") = 0x100010;
                u32 m;

                p->tpage = tp;
                m = (a << 16) | (a << 8) | a;
                {
                    register u32 r asm("$3") = 0x64000000;
                    p->code = semi | (m | r);
                }
                ((u8 *)p)[3] = 5;
                p->xy = (y << 16) | (u16)x;
                p->wh = wh;
            }
            p->uvclut = ((c >> 4) << 12) | ((c & 0xF) << 4) | (D_80137980[flags] << 16);
            ((Tag_8013626C *)p)->addr = ((Tag_8013626C *)ot)->addr;
            ((Tag_8013626C *)ot)->addr = (u32)p;
            p++;
            x += D_80137880[c];
        }
        s++;
    }
    D_800EC354_8013626C = p;
    return s;
}

typedef struct { s16 x, y, w, h; } RECT_80136494;
void LoadImage(RECT_80136494 *, u32 *);

void func_80136494(s32 n, s32 row) {
    u32 *p = (u32 *)0x80155000;
    RECT_80136494 r;

    for (; n != 0; n--) {
        p += 2;
        p += *p >> 2;
        p += *p >> 2;
    }
    p += 2;
    r = *(RECT_80136494 *)(p + 1);
    r.x = 0x1C0;
    r.y = row + 0xFE;
    LoadImage(&r, p + 3);
    p += *p >> 2;
    r = *(RECT_80136494 *)(p + 1);
    r.x = row * 128 + 0x1C0;
    r.y = 0;
    LoadImage(&r, p + 3);
}

typedef struct { s16 x, y, w, h; } Rect_430;
extern Rect_430 D_80137838;
extern struct { u8 f_0; u8 pad1; s16 f_2; s32 f_4, f_8, f_C, f_10, f_14, f_18, f_1C, f_20; } D_80138310;
void ClearImage(Rect_430 *, s32, s32, s32);
void DrawSync(s32);

void func_80136590(void) {
    Rect_430 r;

    D_80138310.f_0 = 2;
    D_80138310.f_4 = 0;
    D_80138310.f_8 = 0x3C;
    D_80138310.f_C = 0;
    D_80138310.f_2 = 0;
    D_80138310.f_10 = 0;
    D_80138310.f_14 = 0;
    D_80138310.f_18 = 0;
    D_80138310.f_1C = 0;
    D_80138310.f_20 = 0;
    r = D_80137838;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
}

extern GameDraw g_Game;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_80136624;
typedef struct { u32 tag; u32 tpage; u32 code; u32 xy; u32 uvclut; u32 wh; } Sprt_80136624;

void func_80136624(s32 y) {
    Sprt_80136624 *p = (Sprt_80136624 *)G_DRAW.prim;
    u32 *ot = &G_DRAW.db[G_DRAW.cur].ot[2];

    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000207;
    p->code = 0x65000000;
    p->xy = (y << 16) | 0x20;
    p->wh = 0x180100;
    p->uvclut = 0x3E9CC800;
    ((Tag_80136624 *)p)->addr = ((Tag_80136624 *)ot)->addr;
    ((Tag_80136624 *)ot)->addr = (u32)p;
    p++;
    ((u8 *)p)[3] = 5;
    p->tpage = 0xE1000208;
    p->code = 0x65000000;
    p->xy = (y << 16) | 0x120;
    p->wh = 0x180040;
    p->uvclut = 0x3E9CC800;
    ((Tag_80136624 *)p)->addr = ((Tag_80136624 *)ot)->addr;
    ((Tag_80136624 *)ot)->addr = (u32)p;
    p++;
    G_DRAW.prim = (u8 *)p;
}

typedef struct { u32 addr : 24; u32 len : 8; } Tag_80136730;
typedef struct { u32 tag; u32 tpage; u32 code; u32 xy; u32 uvclut; u32 wh; } Sprt_80136730;
extern GameDraw g_Game_80136730 asm("g_Game");
extern struct { u8 f_0; u8 pad1; s16 f_2; s32 f_4, f_8, f_C, f_10, f_14, f_18, f_1C, f_20; } D_80138310_80136730 asm("D_80138310");
u8 *func_8013626C(u8 *s, s32 x, s16 y, s32 flags);
void func_80136494(s32 n, s32 row);
void func_80136624(s32 y);
void func_80136E7C(void);
void func_801376EC(void);
s32 func_8008760C(void);
typedef struct { u32 tag; u32 code; u32 xy; u32 wh; } Tile_80136730;
typedef struct { u32 tag; u32 code; } Mode_80136730;
extern u16 D_80137988[];
extern u16 D_8013798C[];
extern u8 D_80137990[];
extern u16 g_RandSeed;

s32 func_80136730(void) {
    u8 *s;
    u8 *start;
    s16 y;
    s32 c;
    s32 font;
    s32 n;
    s32 x;
    Sprt_80136730 *p;
    u32 *ot;
    s32 f18;
    s32 f10;

    func_80136E7C();
    func_801376EC();
    s = D_80137990;
    y = 0xF0 - D_80138310_80136730.f_2;
    for (;;) {
        c = *s;
        if (c == 0) {
            if (y < 0x91) {
                D_80138310_80136730.f_0 = 1;
            }
            break;
        }
        if (c == 0xD) {
            y += 4;
            s++;
            continue;
        }
        font = 0;
        if (c == 1) {
            y += 0x10;
            font = 1;
            s++;
        }
        c = *s;
        if (c == 2) {
            y += 8;
            font = 2;
            s++;
            c = *s;
        }
        if (c == 3) {
            func_80136624(y);
            s++;
            continue;
        }
        start = s;
        s = func_8013626C(start, 0x10, y, font);
        x = 0x10;
        if (font != 0) {
            n = 6;
            if (font == 1) {
                n = 8;
            }
            for (; n > 0; n--) {
                func_8013626C(start, x + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 5 >> 8) - 2,
                              y + (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * 5 >> 8) - 2, font | 8);
            }
        }
        y += 0x18;
        if (y >= 0x111) {
            break;
        }
    }
    if (--D_80138310_80136730.f_8 == 0) {
        D_80138310_80136730.f_8 = 0x338;
        if (D_80138310_80136730.f_14 == 6) {
            D_80138310_80136730.f_10 = 0x10;
            D_80138310_80136730.f_8 = 0x249F00;
            D_80138310_80136730.f_14 = 7;
        } else if (D_80138310_80136730.f_14 < 6) {
            func_80136494(D_80138310_80136730.f_14, D_80138310_80136730.f_18 ^= 1);
            D_80138310_80136730.f_10 = 0x10;
            D_80138310_80136730.f_14++;
        }
    }
    if (D_80138310_80136730.f_10 != 0) {
        D_80138310_80136730.f_10--;
    }
    p = (Sprt_80136730 *)g_Game_80136730.prim;
    ot = g_Game_80136730.db[g_Game_80136730.cur].ot;
    f18 = D_80138310_80136730.f_18;
    f10 = D_80138310_80136730.f_10;
    if (f10 != 0 && D_80138310_80136730.f_14 == 7) {
        {
            s32 c4 = f10 * 4;
            s32 tp;

            ((u8 *)p)[3] = 5;
            tp = (D_80137988[f18] & 0x9FF) | 0xE1000200;
            p->code = (c4 << 16) | (c4 << 8) | c4 | 0x66000000;
            p->xy = 0x6000B0;
            p->wh = 0x8000C0;
            p->tpage = tp;
            p->uvclut = D_8013798C[f18] << 16;
            ((Tag_80136730 *)p)->addr = ((Tag_80136730 *)&ot[2])->addr;
            ((Tag_80136730 *)&ot[2])->addr = (u32)p;
            p++;
        }
    } else if (f10 == 0) {
        if ((u32)(D_80138310_80136730.f_14 - 1) < 6) {
            s32 tp;

            ((u8 *)p)[3] = 5;
            tp = (D_80137988[f18] & 0x9FF) | 0xE1000200;
            p->code = 0x65000000;
            p->xy = 0x6000B0;
            p->wh = 0x8000C0;
            p->tpage = tp;
            p->uvclut = D_8013798C[f18] << 16;
            ((Tag_80136730 *)p)->addr = ((Tag_80136730 *)&ot[2])->addr;
            ((Tag_80136730 *)&ot[2])->addr = (u32)p;
            p++;
        }
    } else {
        {
            s32 a = (f10 * 8) ^ 0x7F;
            s32 k;

            k = 2;
            if (D_80138310_80136730.f_14 == 1) {
                k = 1;
            }
            for (; k > 0; k--) {
                ((u8 *)p)[3] = 5;
                p->tpage = (D_80137988[f18] & 0x9FF) | 0xE1000200;
                p->code = (a << 16) | (a << 8) | a | 0x66000000;
                p->xy = 0x6000B0;
                p->wh = 0x8000C0;
                p->uvclut = D_8013798C[f18] << 16;
                f18 ^= 1;
                a ^= 0x7F;
                ((Tag_80136730 *)p)->addr = ((Tag_80136730 *)&ot[2])->addr;
                ((Tag_80136730 *)&ot[2])->addr = (u32)p;
                p++;
            }
            {
                Tile_80136730 *t = (Tile_80136730 *)p;

                ((u8 *)t)[3] = 3;
                t->xy = 0x6000B0;
                t->wh = 0x8000C0;
                t->code = 0x61000000;
                ((Tag_80136730 *)t)->addr = ((Tag_80136730 *)&ot[2])->addr;
                ((Tag_80136730 *)&ot[2])->addr = (u32)t;
                p = (Sprt_80136730 *)(t + 1);
            }
        }
    }
    g_Game_80136730.prim = (u8 *)p;
    if (D_80138310_80136730.f_0 == 1) {
        if (++D_80138310_80136730.f_1C >= 0x30D) {
            return 1;
        }
        if (D_80138310_80136730.f_1C == 0x258) {
            func_8008760C();
        }
        if (D_80138310_80136730.f_1C == 0x21C) {
            D_80138310_80136730.f_20 = 0x3C;
        }
        if (D_80138310_80136730.f_20 != 0) {
            Tile_80136730 *t;
            s32 v;
            u32 *ot1;

            if (D_80138310_80136730.f_20 >= 2) {
                D_80138310_80136730.f_20--;
            }
            t = (Tile_80136730 *)g_Game_80136730.prim;
            v = 0xFF - D_80138310_80136730.f_20 * 4;
            ot1 = g_Game_80136730.db[g_Game_80136730.cur].ot;
            ((u8 *)t)[3] = 3;
            t->code = (v << 16) | (v << 8) | v | 0x62000000;
            t->xy = 0;
            t->wh = 0xF00180;
            ((Tag_80136730 *)t)->addr = ((Tag_80136730 *)&ot1[1])->addr;
            ((Tag_80136730 *)&ot1[1])->addr = (u32)t;
            t = (Tile_80136730 *)((u8 *)t + 0x10);
            ((u8 *)t)[3] = 1;
            t->code = 0xE1000240;
            ((Tag_80136730 *)t)->addr = ((Tag_80136730 *)&ot1[1])->addr;
            ((Tag_80136730 *)&ot1[1])->addr = (u32)t;
            g_Game_80136730.prim = (u8 *)t + 8;
        }
        return 0;
    }
    D_80138310_80136730.f_4++;
    D_80138310_80136730.f_2++;
    return 0;
}

void func_80136E58(void) {
    M2C_UNK *var_v0;
    s32 var_v1;

    var_v1 = 0x5F;
    var_v0 = &D_80138338;
    do {
        M2C_FIELD(var_v0, s8 *, 4) = 0;
        var_v1 -= 1;
        var_v0 = (void *)((u8 *)var_v0 + (0xC));
    } while (var_v1 >= 0);
}

typedef struct { u32 addr : 24; u32 len : 8; } Tag_80136E7C;
typedef struct { s16 x; s16 y; u8 active; u8 size; s8 dx; s8 dy; u8 bright; u8 pad9[3]; } Spark_80136E7C;
extern Spark_80136E7C D_80138338_80136E7C[] asm("D_80138338");
extern u16 D_801382F8[];
extern struct { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf db[2]; u8 pad8100[0x20]; u16 f_8120; } g_Game_80136E7C asm("g_Game");

void func_80136E7C(void) {
    Spark_80136E7C *q;
    s32 i;
    u8 *p;
    s16 w;
    s16 t;
    s16 sz;
    u32 *ot;
    u32 *otb;

    for (i = 0x5F, q = D_80138338_80136E7C; i >= 0; i--, q++) {
        if (q->active == 0) {
            if (((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 3) != 0) {
                continue;
            }
            q->active = (g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 7;
            q->x = ((g_RandSeed = g_RandSeed * 5 + 1) >> 7 & 0x1FE) + 0x40;
            q->y = -0x40;
            q->dx = 0xFF - ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 7);
            q->dy = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0xF) + 2;
            q->size = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x3F) + 4;
            q->bright = ((g_RandSeed = g_RandSeed * 5 + 1) >> 8 & 0x1F) + 8;
        }
        q->x += q->dx;
        q->y += q->dy;
        if (q->x < -0x20 - q->size || q->y > 0x110) {
            q->active = 0;
        }
    }
    p = g_Game_80136E7C.prim;
    otb = g_Game_80136E7C.db[g_Game_80136E7C.cur].ot;
    for (i = 0x5F, q = D_80138338_80136E7C; i >= 0; i--, q++) {
        if (q->active != 0) {
            sz = q->size;
            w = (u32)(q->size * 0x11D00) / 0x16800;
            p[3] = 9;
            M2C_FIELD(p, u32 *, 4) = (q->bright << 16) | (q->bright << 8) | q->bright | 0x2E000000;
            M2C_FIELD(p, u32 *, 8) = (q->y << 16) | (u16)q->x;
            M2C_FIELD(p, u32 *, 0x10) = (q->y << 16) | ((q->x + sz) & 0xFFFF);
            M2C_FIELD(p, u32 *, 0x18) = ((q->y + w) << 16) | (u16)q->x;
            M2C_FIELD(p, u32 *, 0x20) = ((q->y + w) << 16) | ((q->x + sz) & 0xFFFF);
            M2C_FIELD(p, u32 *, 0xC) = D_801382F8[q->active] << 16;
            { register s32 k asm("$2") = 0x3F00; M2C_FIELD(p, u16 *, 0x1C) = k; }
            M2C_FIELD(p, u32 *, 0x14) = 0x3B003F;
            { register s32 k asm("$2") = 0x3F3F; M2C_FIELD(p, u16 *, 0x24) = k; }
            ((Tag_80136E7C *)p)->addr = ((Tag_80136E7C *)&otb[0xFF0])->addr;
            ((Tag_80136E7C *)&otb[0xFF0])->addr = (u32)p;
            p += 0x28;
        }
    }
    g_Game_80136E7C.prim = p;
    if (g_Game_80136E7C.f_8120 == 0x1E) {
        s32 tt = g_Game_80136E7C.frame & 0x1F;
        u32 m;
        if (tt >= 16) {
            tt = 31 - tt;
        }
        tt = tt / 2 + 0x40;
        {
            u32 c1;
            u32 c2;
            w = (u32)(tt * 0x11D00) / 0x16800;
            c1 = 0x7E2D80C0;
            c2 = 0x7B80FF;
            m = 0xFFFFFF;
            __asm__ volatile("");
            ot = &g_Game_80136E7C.db[g_Game_80136E7C.cur].ot[0xFF0];
            p[3] = 9;
            M2C_FIELD(p, u32 *, 4) = 0x2F000000;
            M2C_FIELD(p, u16 *, 0x1C) = 0xBFC0;
            M2C_FIELD(p, u32 *, 0xC) = c1;
            M2C_FIELD(p, u32 *, 0x14) = c2;
            M2C_FIELD(p, u16 *, 0x24) = 0xBFFF;
        }
        {
            register s32 k120 asm("$5") = 0x78;
            s32 k96 = 0x60;
            register s32 ws asm("$6") = w;
            M2C_FIELD(p, u32 *, 8) = ((k120 - ws) << 16) | ((k96 - (s16)tt) & 0xFFFF);
            M2C_FIELD(p, u32 *, 0x10) = ((k120 - ws) << 16) | (((s16)tt + 0x60) & 0xFFFF);
            M2C_FIELD(p, u32 *, 0x18) = ((ws + 0x78) << 16) | ((k96 - (s16)tt) & 0xFFFF);
            M2C_FIELD(p, u32 *, 0x20) = ((ws + 0x78) << 16) | (((s16)tt + 0x60) & 0xFFFF);
        }
        *(u32 *)p = (*(u32 *)p & 0xFF000000) | (*ot & m);
        *ot = (*ot & 0xFF000000) | ((u32)p & m);
        g_Game_80136E7C.prim = p + 0x28;
    }
}

typedef struct { s16 x, y; s32 z; } Pt_391;
void *func_8008C09C(s32);
s32 rcos(s32);
s32 rsin(s32);
extern Pt_391 *D_80139E28_80138B0C asm("D_801387B8");

void func_80137374(void)
{
  Pt_391 *p;
  s32 r;
  s32 k;
  s32 a;
  s32 a0;
  s32 rad;
  p = (D_80139E28_80138B0C = func_8008C09C(0x600));
  for (a0 = 0, r = 0; r < 12; r++, a0 += 0x80)
  {
    rad = ((r * r) * 300) / 144;
    for (k = 0, a = a0; k < 16; k++)
    {
      p->x = ((rcos(a) * rad) >> 12) + 0xC0;
      p->y = ((rsin(a) * rad) >> 12) + 0x78;
      p->z = 0;
      a += 0x100;
      p++;
    }

  }

}

typedef struct { s16 x, y; union { u8 c[4]; s32 col; } u; } Pt_8013748C;
extern Pt_8013748C *D_801387B8_8013748C asm("D_801387B8");
extern struct { s32 frame; u8 pad4[0x811C]; u16 f_8120; } g_Game_8013748C asm("g_Game");

void func_8013748C(void) {
    s32 a;
    s32 b;
    s32 c;
    Pt_8013748C *p;
    Pt_8013748C *l;
    Pt_8013748C *r;
    s32 i;
    s32 k;
    s32 mode;
    register Pt_8013748C *q asm("$16");

    p = D_801387B8_8013748C + 0xB0;
    mode = g_Game_8013748C.f_8120 == 0x1E;
    for (i = 12; i >= 2; i--) {
        for (k = 0; k < 16; p++, k++) {
            r = p + 1;
            if (k == 15) {
                r = p - 15;
            }
            l = p - 1;
            if (k == 0) {
                l = p + 15;
            }
            if (!mode) {
                p->u.c[0] = (r[-16].u.c[0] + l[-16].u.c[0] + p[-16].u.c[0] * 2) >> 2;
                p->u.c[1] = (r[-16].u.c[1] + l[-16].u.c[1] + p[-16].u.c[1] * 2) >> 2;
                p->u.c[2] = (r[-16].u.c[2] + l[-16].u.c[2] + p[-16].u.c[2] * 2) >> 2;
            } else {
                p->u.c[0] = (r[-16].u.c[0] + l[-16].u.c[0] + p[-16].u.c[0] * 2) >> 4;
                p->u.c[1] = (r[-16].u.c[1] + l[-16].u.c[1] + p[-16].u.c[1] * 2) >> 3;
                p->u.c[2] = (r[-16].u.c[2] + l[-16].u.c[2] + p[-16].u.c[2] * 2) >> 2;
            }
        }
        p -= 32;
    }
    p = D_801387B8_8013748C;
    for (i = 15; i >= 0; i--) {
        p[i].u.col = 0;
    }
    if (g_Game_8013748C.frame & 0xFF) {
        for (i = 0, q = p, a = g_Game_8013748C.frame << 5; i < 16; a += 0x100, i++, q++) {
            q->u.col += ((rsin(a) + 0x1000) * 4) & 0xFF00;
        }
        for (i = 0, q = p, b = (g_Game_8013748C.frame << 5) + 0x555; i < 16; b += 0x100, i++, q++) {
            q->u.col += ((rsin(b) + 0x1000) >> 6) & 0xFF;
        }
        for (i = 0, q = p, c = (g_Game_8013748C.frame << 5) + 0xAAA; i < 16; c += 0x100, i++, q++) {
            q->u.col += (((rsin(c) + 0x1000) >> 6) & 0xFF) << 16;
        }
    }
}

typedef struct { u32 xy; u32 col; } Vtx_801376EC;
typedef struct { u32 addr : 24; u32 len : 8; } Tag_801376EC;
typedef struct { Tag_801376EC tag; u32 c0; u32 xy0; u32 c1; u32 xy1; u32 c2; u32 xy2; u32 c3; u32 xy3; } PolyG4_801376EC;
extern struct { u32 frame; PolyG4_801376EC *prim; u32 *ot; } g_Game_801376EC asm("g_Game");
extern PolyG4_801376EC *D_800EC354_801376EC asm("D_800EC354");
extern Vtx_801376EC *D_801387B8_801376EC asm("D_801387B8");

void func_801376EC(void) {
    PolyG4_801376EC *p = g_Game_801376EC.prim;
    Vtx_801376EC *v = D_801387B8_801376EC;
    Tag_801376EC *ot = (Tag_801376EC *)(g_Game_801376EC.ot + 0xFFF);
    Vtx_801376EC *n;
    s32 i, j;

    func_8013748C();
    for (j = 0; j < 11; j++) {
        for (i = 0; i < 16; i++) {
            n = v + 1;
            if (i == 15) {
                n = v - 15;
            }
            p->c0 = v->col;
            p->c1 = n->col;
            p->c2 = v[16].col;
            p->c3 = n[16].col;
            ((u8 *)p)[3] = 8;
            ((u8 *)p)[7] = 0x38;
            p->xy0 = v->xy;
            p->xy1 = n->xy;
            p->xy2 = v[16].xy;
            p->xy3 = n[16].xy;
            p->tag.addr = ot->addr;
            ot->addr = (u32)p;
            p++;
            v++;
        }
    }
    D_800EC354_801376EC = p;
}
