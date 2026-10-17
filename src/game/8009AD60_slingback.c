#include "common.h"
#define GS_9B1C0 ((struct GS_8009B1C0 *)&g_GadgetState)
typedef struct { u8 pad0[0x70]; u32 ot[0x1000]; u8 pad[0x8]; } DrawBuf_8009B1C0_8009B1C0;
struct GameDb_8009B1C0 { s32 frame; u8 *prim; u32 *ot; s32 cur; DrawBuf_8009B1C0_8009B1C0 db[2]; };
struct GS_8009B1C0 { u8 pad0[4]; s16 windVoice; s16 flyVoice; u32 snd; };
extern u8 g_GadgetState;
extern u8 g_Game;
extern u16 D_800EC23E;
extern u8 D_800EC0C0;
extern u8 D_800EC180;
extern u8 D_800E9E40;
extern u8 D_800E7D00[];
s16 Sound_Play(s32, s32);
void Sound_Stop(s32, s16);
void Model_ProjectVerts(void *, void *, void *);
void func_80017CD4(u32 *, void *, void *);
void func_8006CEF0(void);

INCLUDE_ASM("asm/nonmatchings/game/8009AD60_slingback", Slingback_Update);

/* Sky Flyer: while Spike's action state is 0x80..0x82 (winding it up) keeps the wind-up sound
 * 0x1D going, and in 0x83..0x84 (flying) the flying sound 0x1E; g_GadgetState+8 tracks which one
 * plays (voices at +4 / +6). Draws the flying model (D_800EC180) or the idle one (D_800EC0C0),
 * and while flying calls func_8006CEF0. */
void SkyFlyer_Update(void) {
    s32 st;
    void *m;
    switch (GS_9B1C0->snd) {
    case 0:
        st = D_800EC23E;
        if (st >= 0x80) {
            if (st < 0x83) {
                GS_9B1C0->windVoice = Sound_Play(0, 0x1D);
                if (GS_9B1C0->windVoice != -1) {
                    GS_9B1C0->snd = 1;
                }
            } else if (st < 0x85) {
                GS_9B1C0->flyVoice = Sound_Play(0, 0x1E);
                if (GS_9B1C0->flyVoice != -1) {
                    GS_9B1C0->snd = 2;
                }
            }
        }
        break;
    case 1:
        st = D_800EC23E;
        if (st < 0x83) {
            if (st >= 0x80) {
                break;
            }
        }
        if (GS_9B1C0->windVoice != -1) {
            Sound_Stop(0x1D, GS_9B1C0->windVoice);
        }
        GS_9B1C0->snd = 0;
        break;
    case 2:
        st = D_800EC23E;
        if (st < 0x85) {
            if (st >= 0x83) {
                break;
            }
        }
        if (GS_9B1C0->flyVoice != -1) {
            Sound_Stop(0x1E, GS_9B1C0->flyVoice);
        }
        GS_9B1C0->snd = 0;
        break;
    }
    st = D_800EC23E;
    if (st < 0x85) {
        if (st < 0x83) {
            m = &D_800EC0C0;
        } else {
            m = &D_800EC180;
        }
    } else {
        m = &D_800EC0C0;
    }
    Model_ProjectVerts(m, &D_800E9E40, D_800E7D00);
    func_80017CD4(((struct GameDb_8009B1C0 *)&g_Game)->db[((struct GameDb_8009B1C0 *)&g_Game)->cur].ot, D_800E7D00, m);
    if (D_800EC23E >= 0x83 && D_800EC23E <= 0x84) {
        func_8006CEF0();
    }
}
