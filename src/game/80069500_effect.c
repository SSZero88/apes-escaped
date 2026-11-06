#include "common.h"
#include "m2c_macros.h"
typedef struct { s16 vx, vy, vz; u8 f_6; u8 pad7; } S_Pos_8006962C;
typedef struct { u8 f_0; u8 f_1; u8 f_2; s8 f_3; u32 f_4; u8 pad8[0xA]; u8 f_12; u8 f_13; S_Pos_8006962C f_14; u8 pad1C[6]; s16 f_22; u8 pad24[6]; s16 f_2A; u8 pad2C[4]; u32 f_30; } S_Particle_8006962C;
typedef struct { s16 vx, vy, vz, pad; } SVEC_8006AB10;

struct S_D_800B9900_80069548 *func_80069548(void);

M2C_UNK func_8006DAC8();
M2C_UNK func_8006E02C();
M2C_UNK func_8006ED4C();
M2C_UNK func_8006FE54();
M2C_UNK Puff_ClearAll();
M2C_UNK func_800710F8();

void Effect_Spawn(s32 id, s16 *pos, u32 *tbl, s16 **scripts);
extern M2C_UNK D_800B175C;
extern M2C_UNK D_800B1828;

void Fx_ClearAll(void);
M2C_UNK func_8006B7DC();
extern s8 D_800B9900;
extern s8 D_800BAD50;
M2C_UNK Fx_UpdateSpikeEffects();
M2C_UNK Fx_UpdateBlastSequence();
M2C_UNK func_8006D5A8();
M2C_UNK SuperHoop_DrawSparkles();
M2C_UNK func_8006E1C0();
M2C_UNK Fx_UpdateFadeRings();
M2C_UNK Shockwave_UpdateAll();
M2C_UNK func_80070560();
M2C_UNK Puff_UpdateAll();
M2C_UNK Debris_UpdateAll();
struct S_D_800B9900_80069548 { u8 f_0; u8 pad1; u8 f_2; u8 pad3[0x31]; };
extern u16 g_RandSeed;
extern struct S_D_800B1BD4 { u8 pad[0x54]; } D_800B1BD4[];
void func_80070284(s16 *pos, struct S_D_800B1BD4 *d, s32 a, s32 b, s32 c);
void Fx_SpawnFadeRing(s16 *pos, s32 a, s32 b, s32 c);
extern struct { u8 pad0[0x24]; s32 f_24; s32 f_28; s32 f_2C; u8 pad30[0x30]; u16 f_60; u16 pad62; u16 f_64; } g_Spike;
void memset(void *, s32, s32);
void Effect_SpawnAt(s32, void *);
void func_80071120(s16 *, s32);
void Sound_PlayFixed(s32);

void func_80069500(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x63;
    var_v0 = &D_800B9900;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 += 0x34;
    } while (var_v1 >= 0);
    D_800BAD50 = 0;
    Fx_ClearAll();
    func_8006B7DC();
}

struct S_D_800B9900_80069548 *func_80069548(void) {
    s32 i;
    struct S_D_800B9900_80069548 *p;
    for (i = 99; i >= 0; i--) {
        if (++(*(u8 *)&D_800BAD50) >= 100) {
            (*(u8 *)&D_800BAD50) = 0;
        }
        p = &((struct S_D_800B9900_80069548 *)&D_800B9900)[(*(u8 *)&D_800BAD50)];
        if (p->f_0 == 0) {
            return p;
        }
    }
    for (i = 99; i >= 0; i--) {
        if (++(*(u8 *)&D_800BAD50) >= 100) {
            (*(u8 *)&D_800BAD50) = 0;
        }
        p = &((struct S_D_800B9900_80069548 *)&D_800B9900)[(*(u8 *)&D_800BAD50)];
        if (p->f_2 == 0) {
            return p;
        }
    }
    return ((struct S_D_800B9900_80069548 *)&D_800B9900);
}

void Particle_Spawn(s32 type, SVECTOR *pos, u32 *tbl) {
    S_Particle_8006962C *p = func_80069548();
    p->f_0 = type;
    *(SVECTOR *)&p->f_14 = *pos;
    if (type < 200) {
        p->f_4 = tbl[type];
    } else {
        p->f_4 = tbl[type - 200];
    }
    p->f_3 = -1;
    p->f_30 = 0x2C000000;
    p->f_1 = 0;
    p->f_22 = 0;
    p->f_12 = 0;
    p->f_13 = 0;
    p->f_14.f_6 = 0;
    p->f_2 = 0;
    p->f_2A = 0x7C;
}

/* Spawn effect `id` at pos. Ids below 0x100 are a single particle (Particle_Spawn); higher ids run
 * a script (scripts[id - 0x100], or scripts[id - 0x1C8] from 0x1C8 up) of 0-terminated commands,
 * each {type, y offset, ...}: 0x32 -> func_80070284(entry D_800B1BD4[a], b, c), 0x33 ->
 * Fx_SpawnFadeRing(a, b, c), any other type -> n + rand * m / 256 particles of that type. */
void Effect_Spawn(s32 id, s16 *pos, u32 *tbl, s16 **scripts) {
    s16 *s;
    u16 cmd;
    s32 n;
    s16 v[4];
    s32 a, b, c;

    if (id < 0x100) {
        Particle_Spawn(id, (SVECTOR *)pos, tbl);
        return;
    }
    if (id < 0x1C8) {
        s = scripts[id - 0x100];
    } else {
        s = scripts[id - 0x1C8];
    }
    cmd = *s++;
    while (cmd != 0) {
        v[0] = pos[0];
        v[1] = pos[1] + *s++;
        v[2] = pos[2];
        switch (cmd) {
        default:
            n = *s++;
            n += (((g_RandSeed = g_RandSeed * 5 + 1) >> 8) * *s++) >> 8;
            while (n > 0) {
                Particle_Spawn(cmd, (SVECTOR *)v, tbl);
                n--;
            }
            break;
        case 0x32:
            a = *s++;
            b = *s++;
            c = *s++;
            func_80070284(v, &D_800B1BD4[a], b, c, 0);
            break;
        case 0x33:
            {
            s32 x, y, z;
            x = *s++;
            y = *s++;
            z = *s++;
            Fx_SpawnFadeRing(v, x, y, z);
            }
            break;
        }
        cmd = *s++;
    }
}

void Effect_SpawnAt(s32 arg0, void *arg1) {
    Effect_Spawn(arg0, arg1, (u32 *)&D_800B175C, (s16 **)&D_800B1828);
}

void Effect_SpawnXYZ(s32 a0, s16 a1, s16 a2, s16 a3) {
    s16 v[3];
    v[0] = a1;
    v[1] = a2;
    v[2] = a3;
    Effect_Spawn(a0, v, (u32 *)&D_800B175C, (s16 **)&D_800B1828);
}

typedef struct { u8 active; u8 pad1[0x11]; u8 sx; u8 sy; SVECTOR pos; u8 pad1C[8]; u32 uv0; u32 uv1; u16 uv2; u16 uv3; u32 code; } Spr_69920;
typedef struct { u16 x; s16 y; u32 z; } Scr_69920;
typedef struct { u32 tag; u32 code; u32 xy0; u32 uv0; u32 xy1; u32 uv1; u32 xy2; u16 uv2; u16 pad1E; u32 xy3; u16 uv3; u16 pad26; } FT4_69920;
typedef struct { unsigned addr : 24; unsigned len : 8; } PTag_69920;
#define ADDPRIM_BF_69920(ot, p) (((PTag_69920 *)(p))->addr = ((PTag_69920 *)(ot))->addr, ((PTag_69920 *)(ot))->addr = (u32)(p))
extern Spr_69920 D_800B9900_69920[] asm("D_800B9900");
extern u8 g_Game;
extern u8 *D_800EC354;
extern u8 D_800E78C0[];
#define gte_ldv0_69920(v) __asm__ volatile ("lwc2 $0, 0(%0); lwc2 $1, 4(%0)" : : "r"(v))
#define gte_rtps_69920() __asm__ volatile ("nop; nop; rtps")
#define gte_stsxy_69920(p) __asm__ volatile ("swc2 $14, 0(%0)" : : "r"(p) : "memory")
#define gte_stszotz_69920(p) __asm__ volatile ("mfc2 $12, $19; nop; sra $12, $12, 2; sw $12, 0(%0)" : : "r"(p) : "$12", "memory")

/* Draws the 100 billboard sprites in D_800B9900 (0x34 each): every active, sized one is projected
   and, when its centre is on screen (with a 0x20 margin), drawn as an FT4 sx x sy units across at
   the projected size (sy corrected by 19/24), with its own colour/code and texture words. */
void func_80069920(void) {
    void SetRotMatrix(void *m); void SetTransMatrix(void *m);
    Scr_69920 *scr = (Scr_69920 *)0x1F800000;
    Spr_69920 *e;
    FT4_69920 *p;
    u32 *ot;
    s32 i, h; s16 y;
    u32 x, w;
    s16 x0, y0;
    u32 xa, xb, ya, yb;

    SetRotMatrix(D_800E78C0);
    SetTransMatrix(D_800E78C0);
    ot = G_DRAW.db[G_DRAW.cur].ot;
    p = (FT4_69920 *)G_DRAW.prim;
    for (i = 99, e = D_800B9900_69920; i >= 0; i--, e++) {
        if (e->active == 0 || e->sx == 0) {
            continue;
        }
        gte_ldv0_69920(&e->pos);
        gte_rtps_69920();
        gte_stsxy_69920(scr);
        x = scr->x;
        y = *(s32 *)scr >> 16;
        if ((u16)(x + 0x20) >= 0x1C1 || y < -0x20 || y >= 0x111) {
            continue;
        }
        gte_stszotz_69920(&scr->z);
        if (scr->z - 1 >= 0xFFF) {
            continue;
        }
        w = e->sx * 0x148 / scr->z;
        h = (u32)(e->sy * 0x148 * 0x11D00) / 0x16800 / scr->z;
        { s32 n; __asm__ volatile("" : "=r"(n) : "0"(9)); ((u8 *)p)[3] = n; }
        p->code = e->code;
        x0 = x - (w >> 1);
        xa = x0 & 0xFFFF;
        xb = (x0 + w) & 0xFFFF;
        y0 = y - h / 2;
        ya = y0 << 16;
        yb = (y0 + h) << 16;
        p->xy0 = ya | xa;
        p->xy1 = ya | xb;
        p->xy2 = yb | xa;
        p->xy3 = yb | xb;
        p->uv0 = e->uv0;
        p->uv1 = e->uv1;
        p->uv2 = e->uv2;
        p->uv3 = e->uv3;
        ADDPRIM_BF_69920(ot + scr->z, p);
        p++;
    }
    D_800EC354 = (u8 *)p;
}

typedef struct { s16 vx, vy, vz, pad; } SV_69BEC;
typedef struct { u16 vx, vy, vz, pad; } USV_69BEC;
typedef struct { u8 id; u8 still; u8 blend; s8 depth; s16 *pc; s16 *ret[2]; u8 count[2]; u8 sx; u8 sy; s16 x, y, z; s8 fade; u8 pad1B; s16 vx, vy, vz; s16 wait; u8 u0, v0; u16 clut; u8 u1, v1; u16 tpage; u8 u2, v2; u8 u3, v3; union { u32 w; struct { u8 r, g, b, code; } c; } col; } Fx_69BEC;
typedef struct { u8 pad0[0x24]; u16 x; u8 pad26[2]; u16 y; u8 pad2A[2]; u16 z; u8 pad2E[0xFE]; s32 f_12C; } Spk_69BEC;
extern Fx_69BEC D_800B9900_69BEC[] asm("D_800B9900");
extern Spk_69BEC g_Spike_69BEC asm("g_Spike");
extern u16 D_800AE8F2;
extern SV_69BEC D_800B4D80;
extern SV_69BEC D_800B4D88;
#define VS_69BEC(x) (*(volatile s16 *)&(x))
extern s16 D_800B4D90;
extern u8 D_800B1E20[];
extern u8 D_800B1B78[][8];
void func_80069920_69BEC(s32, s32, s32) asm("func_80069920");
void bios_printf(const char *, ...);
void func_80070284_69BEC(SV_69BEC *, u8 *, s32, s32, s32) asm("func_80070284");
void func_8006F3D0(SV_69BEC *, s32, u8 *, s32);
#define RNG_69BEC(n) ((((u16)(seed = seed * 5 + 1) >> 8) * (n)) >> 8)

void func_80069BEC(void) {
    s32 i;
    Fx_69BEC *fx;
    s16 *pc;
    s32 run;
    s32 j;
    s16 *p;
    u16 seed;
    s32 sx0, sy0, sz0;
    s32 r, g, b;
    SV_69BEC t18;
    SV_69BEC t20;
    SV_69BEC t28;
    SV_69BEC seg[2];

    i = 99;
    seed = g_RandSeed;
    VS_69BEC(D_800B4D80.vx) = sx0 = g_Spike_69BEC.x;
    __asm__ volatile("");
    sy0 = g_Spike_69BEC.y;
    sz0 = g_Spike_69BEC.z;
    __asm__ volatile("");
    VS_69BEC(D_800B4D80.vy) = sy0;
    VS_69BEC(D_800B4D80.vz) = sz0;
    VS_69BEC(D_800B4D88.vx) = sx0;
    __asm__ volatile("");
    VS_69BEC(D_800B4D88.vy) = sy0 -= 0x80;
    D_800B4D88.vz = sz0;
    func_80069920_69BEC(sy0, sx0, sz0);
    for (fx = D_800B9900_69BEC; i >= 0; i--, fx++) {
        if (fx->id == 0) {
            continue;
        }
        run = 1;
        pc = fx->pc;
        for (;;) {
            if (fx->wait > 0) {
                fx->wait--;
                break;
            }
            switch ((s16)*pc++) {
            default:
                bios_printf("Type[%d] Illegal command...: ", fx->id);
                for (j = -1; j < 5; j++) {
                    bios_printf("%d ", pc[j]);
                }
                bios_printf("\n");
                run = 0;
                break;
            case 12:
                run = 0;
                fx->still = 0;
                fx->wait = 0;
                break;
            case 13:
                fx->still = 0;
                goto wait_n;
            case 14:
                fx->still = 0;
                goto wait_rnd;
            case 10:
                fx->still = 1;
            wait_n:
                fx->wait = *pc++ - 1;
                run = 0;
                break;
            case 11:
                fx->still = 1;
            wait_rnd:
                fx->wait = *pc++;
                { s32 t = RNG_69BEC(*pc++) + 0xFFFF; fx->wait += t; }
                run = 0;
                break;
            case 1:
                if (++fx->depth >= 2) {
                    bios_printf("*** type[%d] LoopDepth error!! (cmd: %d)\n", fx->id, pc[-1]);
                }
                fx->ret[fx->depth] = pc + 1;
                fx->count[fx->depth] = *pc++;
                break;
            case 2:
                if (++fx->depth >= 2) {
                    bios_printf("*** type[%d] LoopDepth error!! (cmd: %d)\n", fx->id, pc[-1]);
                }
                fx->ret[fx->depth] = pc + 2;
                fx->count[fx->depth] = *pc++;
                fx->count[fx->depth] += RNG_69BEC(*pc++);
                break;
            case 3:
                if (fx->count[fx->depth] == 0 || (fx->count[fx->depth]--, fx->count[fx->depth] == 0)) {
                    fx->depth--;
                } else {
                    pc = fx->ret[fx->depth];
                }
                break;
            case 8:
                fx->x += *pc++;
                fx->y += *pc++;
                fx->z += *pc++;
                break;
            case 9:
                fx->x += RNG_69BEC(*pc++);
                fx->x -= *pc++;
                fx->y += RNG_69BEC(*pc++);
                fx->y -= *pc++;
                fx->z += RNG_69BEC(*pc++);
                fx->z -= *pc++;
                break;
            case 16:
                fx->vx = *pc++;
                break;
            case 17:
                fx->vy = *pc++;
                break;
            case 15:
                fx->vx = *pc++;
                fx->vy = *pc++;
            case 18:
                fx->vz = *pc++;
                break;
            case 20:
                fx->vx = RNG_69BEC(*pc++);
                fx->vx -= *pc++;
                break;
            case 21:
                fx->vy = RNG_69BEC(*pc++);
                fx->vy -= *pc++;
                break;
            case 19:
                fx->vx = RNG_69BEC(*pc++);
                fx->vx -= *pc++;
                fx->vy = RNG_69BEC(*pc++);
                fx->vy -= *pc++;
            case 22:
                fx->vz = RNG_69BEC(*pc++);
                fx->vz -= *pc++;
                break;
            case 23:
                fx->vx += *pc++;
                fx->vy += *pc++;
                fx->vz += *pc++;
                break;
            case 24:
                fx->vx = fx->vx * *pc++ >> 12;
                fx->vy = fx->vy * *pc++ >> 12;
                fx->vz = fx->vz * *pc++ >> 12;
                break;
            case 25:
                fx->blend = 0;
                break;
            case 26:
                fx->blend = 1;
                break;
            case 27:
                fx->blend = 2;
                break;
            case 33:
                fx->sx = *pc++;
                fx->sy = *pc++;
                break;
            case 34:
                fx->sx = *pc++;
                fx->sx += RNG_69BEC(*pc++);
                fx->sy = *pc++;
                fx->sy += RNG_69BEC(*pc++);
                break;
            case 35:
                fx->sx = *pc++;
                fx->sy = fx->sx += RNG_69BEC(*pc++);
                break;
            case 36:
                fx->sx = fx->sx * *pc++ >> 12;
                fx->sy = fx->sy * *pc++ >> 12;
                break;
            case 30: {
                s16 a = *pc++;
                u16 d = *pc++;
                *(u16 *)&fx->u1 = a + (d & 0xFF00);
                *(u16 *)&fx->u0 = a;
                *(u16 *)&fx->u2 = a + (d & 0xFF);
                *(u16 *)&fx->u3 = a + d;
                break;
            }
            case 31: {
                u8 a = *pc++;
                fx->u0 += a;
                fx->u1 += a;
                fx->u2 += a;
                fx->u3 += a;
                break;
            }
            case 32: {
                u8 a = *pc++;
                fx->v0 += a;
                fx->v1 += a;
                fx->v2 += a;
                fx->v3 += a;
                break;
            }
            case 37:
                fx->col.w &= 0xFF000000;
                fx->col.w |= *pc++;
                fx->col.w |= *pc++ << 8;
                fx->col.w |= *pc++ << 16;
                break;
            case 38: {
                s32 a;
                fx->col.w &= 0xFFFF00FF;
                a = *pc++;
                fx->col.w |= (a + (u16)RNG_69BEC(*pc++)) << 8;
                break;
            }
            case 39:
                fx->fade = *pc++;
                break;
            case 40: {
                u8 a = *pc++;
                fx->fade = a;
                fx->fade = a + RNG_69BEC(*pc++);
                break;
            }
            case 41:
                fx->col.c.code &= 0xFD;
                break;
            case 42:
                fx->tpage = 0x1C;
                fx->col.c.code |= 2;
                break;
            case 43:
                fx->tpage = 0x3C;
                fx->col.c.code |= 2;
                break;
            case 44:
                fx->tpage = 0x5C;
                fx->col.c.code |= 2;
                break;
            case 45:
                fx->tpage = 0x7C;
                fx->col.c.code |= 2;
                break;
            case 46:
                fx->col.c.code &= 0xFE;
                break;
            case 47:
                fx->col.c.code |= 1;
                break;
            case 48:
                fx->clut = ((*pc++ + 0x1F0) << 6) | 0x2C;
                break;
            case 49: {
                s32 a = *pc++;
                s32 t = (u16)RNG_69BEC(*pc++);
                fx->clut = ((a + t + 0x1F0) << 6) | 0x2C;
                break;
            }
            case 51: {
                Spk_69BEC *sp = &g_Spike_69BEC;
                if (sp->f_12C < fx->y) {
                    memset(&t20, 0, 8);
                    t20.vx = fx->x;
                    t20.vy = sp->f_12C;
                    t20.vz = fx->z;
                    t18 = t20;
                    Effect_SpawnAt(0x107, &t18);
                    run = 0;
                    fx->id = 0;
                } else if (D_800B4D90 < fx->y) {
                    D_800AE8F2 = D_800AE8F2 * 5 + 1;
                    memset(&t28, 0, 8);
                    run = 0;
                    t28.vx = fx->x;
                    t28.vy = D_800B4D90;
                    t28.vz = fx->z;
                    t20 = t28;
                    func_80070284_69BEC(&t20, D_800B1E20, 1, 0, 0);
                    fx->id = 0;
                }
                break;
            }
            case 52:
                seg[0] = *(SV_69BEC *)&fx->x;
                seg[1].vx = fx->x + fx->vx * 3;
                seg[1].vy = fx->y + fx->vy * 3;
                seg[1].vz = fx->z + fx->vz * 3;
                func_8006F3D0(seg, 2, D_800B1B78[*pc++], fx->sx);
                break;
            case 4:
                fx->id = 0;
                run = 0;
                break;
            }
            
            if (run == 0) {
                break;
            }
        }
        fx->pc = pc;
        if (fx->id == 0) {
            continue;
        }
        if (fx->still == 0) {
            fx->x += fx->vx;
            fx->y += fx->vy;
            fx->z += fx->vz;
        }
        if (fx->fade > 0) {
            r = fx->col.c.r;
            g = fx->col.c.g;
            b = fx->col.c.b;
            r -= fx->fade;
            r = r < 0 ? 0 : (r >= 0x100 ? 0xFF : r);
            g -= fx->fade;
            g = g < 0 ? 0 : (g >= 0x100 ? 0xFF : g);
            b -= fx->fade;
            b = b < 0 ? 0 : (b >= 0x100 ? 0xFF : b);
            fx->col.w = (fx->col.w & 0xFF000000) | (r | (g << 8) | (b << 16));
            fx->col.c.r = r;
            fx->col.c.g = g;
            fx->col.c.b = b;
        }
    }
    g_RandSeed = seed;
}

INCLUDE_RODATA("asm/nonmatchings/game/80069500_effect", jtbl_800A5C48_pad);


void Fx_ClearAll(void) {
    func_800710F8();
    func_8006FE54();
    Puff_ClearAll();
    func_8006DAC8();
    func_8006ED4C();
    func_8006E02C();
}

void Fx_UpdateAll(void) {
    Debris_UpdateAll();
    Shockwave_UpdateAll();
    Puff_UpdateAll();
    SuperHoop_DrawSparkles();
    Fx_UpdateFadeRings();
    func_8006E1C0();
    func_80070560();
    Fx_UpdateBlastSequence();
    func_8006D5A8();
    Fx_UpdateSpikeEffects();
}

void Fx_Explosion(s16 *pos, s32 b, s32 kind) {
    s32 snd;
    Effect_SpawnAt(0x109, pos);
    func_80071120(pos, b);
    switch (kind) {
    case 0:
    default:
        Effect_SpawnAt(0x105, pos);
        Effect_SpawnAt(0x103, pos);
        Sound_PlayFixed(0x4B);
        Sound_PlayFixed(0x5F);
        break;
    case 1:
        Sound_PlayFixed(0x4D);
        Sound_PlayFixed(0x5F);
        break;
    case 2:
        Sound_PlayFixed(0xB9);
        break;
    }
}

/* Spawn effects 0x105 and 0x108 just ahead of Spike: his position plus 1/12 of +0x60/+0x64,
   0x80 up. Only reached through a function pointer. */
void func_8006AB10(void) {
    SVEC_8006AB10 tmp;
    SVEC_8006AB10 v;
    memset(&v, 0, 8);
    v.vy = g_Spike.f_28 - 0x80;
    v.vx = g_Spike.f_24 + (s16)g_Spike.f_60 / 12;
    v.vz = g_Spike.f_2C + (s16)g_Spike.f_64 / 12;
    tmp = v;
    Effect_SpawnAt(0x105, &tmp);
    Effect_SpawnAt(0x108, &tmp);
}
