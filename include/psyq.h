#ifndef PSYQ_H
#define PSYQ_H

/*
 * Prototypes for the PsyQ 4.x library functions linked into the game
 * (identified by tools/match_psyq.py). Pointer-to-struct parameters are
 * void* for now; codegen is identical. Swap in real libgpu/libgte structs
 * as they become useful.
 */

#include "common.h"

/* libapi */
s32 SetRCnt(s32 spec, u16 target, s32 mode);
s32 GetRCnt(s32 spec);
s32 StartRCnt(s32 spec);
s32 StopRCnt(s32 spec);
s32 ResetRCnt(s32 spec);
void InitPAD(void* bufA, s32 lenA, void* bufB, s32 lenB);
s32 StartPAD(void);
void StopPAD(void);
void EnablePAD(void);
void DisablePAD(void);
s32 puts(const char* s);

/* libetc */
s32 VSync(s32 mode);
void* VSyncCallback(void (*func)(void));
s32 VSyncCallbacks(s32 ch, void (*func)(void));
s32 ResetCallback(void);
void* InterruptCallback(s32 irq, void (*func)(void));
void* DMACallback(s32 dma, void (*func)(void));
s32 StopCallback(void);
s32 RestartCallback(void);
s32 CheckCallback(void);
s32 GetIntrMask(void);
s32 SetIntrMask(s32 mask);
s32 SetVideoMode(s32 mode);
s32 GetVideoMode(void);

/* libpad */
void PadInitDirect(u8* pad1, u8* pad2);
s32 PadStartCom(void);
void PadStopCom(void);
s32 PadChkVsync(void);
s32 PadGetState(s32 port);
s32 PadInfoMode(s32 port, s32 term, s32 offs);
s32 PadInfoAct(s32 port, s32 actno, s32 term);
s32 PadInfoComb(s32 port, s32 listno, s32 offs);
s32 PadSetActAlign(s32 port, u8* data);
s32 PadSetMainMode(s32 port, s32 offs, s32 lock);
void PadSetAct(s32 port, u8* data, s32 len);
void PadEnableCom(s32 mode);
s32 PadChkMtap(s32 port);

/* libgpu */
s32 ResetGraph(s32 mode);
s32 SetGraphDebug(s32 level);
s32 SetGraphQueue(s32 mode);
s32 GetGraphDebug(void);
void* DrawSyncCallback(void (*func)(void));
void SetDispMask(s32 mask);
s32 DrawSync(s32 mode);
s32 ClearImage(void* rect, u8 r, u8 g, u8 b);
s32 ClearImage2(void* rect, u8 r, u8 g, u8 b);
s32 LoadImage(void* rect, u32* p);
s32 StoreImage(void* rect, u32* p);
s32 MoveImage(void* rect, s32 x, s32 y);
s32 LoadImage2(void* rect, u32* p);
s32 StoreImage2(void* rect, u32* p);
s32 MoveImage2(void* rect, s32 x, s32 y);
u32* ClearOTag(u32* ot, s32 n);
u32* ClearOTagR(u32* ot, s32 n);
void DrawPrim(void* p);
void DrawOTag(u32* p);
void DrawOTag2(u32* p);
void* PutDrawEnv(void* env);
void DrawOTagEnv(u32* p, void* env);
void* GetDrawEnv(void* env);
void* PutDispEnv(void* env);
void* GetDispEnv(void* env);
s32 GetODE(void);
void SetDrawArea(void* p, void* r);
void SetDrawOffset(void* p, u16* ofs);
void SetDrawEnv(void* dr_env, void* env);
void* SetDefDrawEnv(void* env, s32 x, s32 y, s32 w, s32 h);
void* SetDefDispEnv(void* env, s32 x, s32 y, s32 w, s32 h);
void SetDrawMove(void* p, void* rect, s32 x, s32 y);
void SetDrawStp(void* p, s32 pbw);
void SetDrawTPage(void* p, s32 dfe, s32 dtd, s32 tpage);
u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);

/* libgte */
void InitGeom(void);
void SetGeomOffset(s32 ofx, s32 ofy);
void SetRotMatrix(void* m);
void SetTransMatrix(void* m);
void SetBackColor(s32 rbk, s32 gbk, s32 bbk);
void SetColorMatrix(void* m);
void SetFarColor(s32 rfc, s32 gfc, s32 bfc);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 sin_1(s32 a);
s32 ratan2(s32 y, s32 x);
s32 SquareRoot0(s32 a);
s32 InvSquareRoot(s32 a, s32* b, s32* c);
void* RotMatrix(void* r, void* m);
void* RotMatrixX(s32 r, void* m);
void* RotMatrixY(s32 r, void* m);
void* RotMatrixZ(s32 r, void* m);
void* RotMatrixYXZ(void* r, void* m);
void* RotMatrixZYX(void* r, void* m);
void* MulMatrix(void* m0, void* m1);
void* MulMatrix0(void* m0, void* m1, void* m2);
void* MulMatrix2(void* m0, void* m1);
void* CompMatrix(void* m0, void* m1, void* m2);
void* ScaleMatrix(void* m, void* v);
void* ScaleMatrixL(void* m, void* v);
void* MatrixNormal(void* m, void* n);
void* ApplyMatrix(void* m, void* v0, void* v1);
void* ApplyMatrixSV(void* m, void* v0, void* v1);
void* ApplyMatrixLV(void* m, void* v0, void* v1);
void VectorNormal(void* v0, void* v1);
void VectorNormalS(void* v0, void* v1);
void VectorNormalSS(void* v0, void* v1);
void OuterProduct0(void* v0, void* v1, void* v2);
void OuterProduct12(void* v0, void* v1, void* v2);
void Square0(void* v0, void* v1);
void Square12(void* v0, void* v1);
void SquareSS0(void* v0, void* v1);
void SquareSS12(void* v0, void* v1);
void SquareSL0(void* v0, void* v1);
void SquareSL12(void* v0, void* v1);
s32 RotTransPers(void* v0, s32* sxy, s32* p, s32* flag);
void RotTrans(void* v0, void* v1, s32* flag);
void RotTransSV(void* v0, void* v1, s32* flag);
void LocalLight(void* v0, void* v1);
void LightColor(void* v0, void* v1);
void DpqColorLight(void* v0, void* v1, s32 p, void* v2);
void DpqColor(void* v0, s32 p, void* v1);
void DpqColor3(void* v0, void* v1, void* v2, s32 p, void* v3, void* v4, void* v5);
void Intpl(void* v0, s32 p, void* v1);
void NormalColor(void* v0, void* v1);
void NormalColor3(void* v0, void* v1, void* v2, void* v3, void* v4, void* v5);
void NormalColorDpq(void* v0, void* v1, s32 p, void* v2);
void NormalColorDpq3(void* v0, void* v1, void* v2, void* v3, s32 p, void* v4, void* v5, void* v6);
void NormalColorCol(void* v0, void* v1, void* v2);
void NormalColorCol3(void* v0, void* v1, void* v2, void* v3, void* v4, void* v5, void* v6);
void ColorDpq(void* v0, void* v1, s32 p, void* v2);
void ColorCol(void* v0, void* v1, void* v2);
s32 AverageZ3(s32 sz0, s32 sz1, s32 sz2);
s32 AverageZ4(s32 sz0, s32 sz1, s32 sz2, s32 sz3);
s32 AverageSZ3(s32 sz0, s32 sz1, s32 sz2);
s32 AverageSZ4(s32 sz0, s32 sz1, s32 sz2, s32 sz3);
s32 Lzc(s32 data);

/* libcd */
s32 CdInit(void);
s32 CdStatus(void);
s32 CdMode(void);
s32 CdLastCom(void);
void* CdLastPos(void);
s32 CdReset(s32 mode);
void CdFlush(void);
s32 CdSetDebug(s32 level);
char* CdComstr(u8 com);
char* CdIntstr(u8 intr);
s32 CdSync(s32 mode, u8* result);
s32 CdReady(s32 mode, u8* result);
void* CdSyncCallback(void (*func)(u8, u8*));
void* CdReadyCallback(void (*func)(u8, u8*));
s32 CdControl(u8 com, u8* param, u8* result);
s32 CdControlF(u8 com, u8* param);
s32 CdControlB(u8 com, u8* param, u8* result);
s32 CdMix(void* vol);
s32 CdGetSector(void* madr, s32 size);
s32 CdGetSector2(void* madr, s32 size);
void* CdDataCallback(void (*func)(void));
s32 CdDataSync(s32 mode);
void* CdIntToPos(s32 i, void* p);
s32 CdPosToInt(void* p);
void* CdSearchFile(void* fp, char* name);
s32 CdRead(s32 sectors, u32* buf, s32 mode);
s32 CdReadSync(s32 mode, u8* result);
void* CdReadCallback(void (*func)(u8, u8*));
s32 CdReadMode(s32 mode);
s32 CdReadBreak(void);
s32 CdRead2(s32 mode);
void StSetRing(u32* ring_addr, u32 ring_size);
void StSetStream(u32 mode, u32 start_frame, u32 end_frame, void (*func1)(void), void (*func2)(void));
void StClearRing(void);
void StUnSetRing(void);
u32 StFreeRing(u32* base);
u32 StGetNext(u32** addr, u32** header);

/* libmcrd */
void MemCardInit(s32 val);
void MemCardEnd(void);
void MemCardStart(void);
void MemCardStop(void);
s32 MemCardExist(s32 chan);
s32 MemCardAccept(s32 chan);
s32 MemCardOpen(s32 chan, char* file, s32 flag);
void MemCardClose(void);
s32 MemCardReadData(u32* adrs, s32 ofs, s32 bytes);
s32 MemCardReadFile(s32 chan, char* file, u32* adrs, s32 ofs, s32 bytes);
s32 MemCardWriteData(u32* adrs, s32 ofs, s32 bytes);
s32 MemCardWriteFile(s32 chan, char* file, u32* adrs, s32 ofs, s32 bytes);
s32 MemCardCreateFile(s32 chan, char* file, s32 blocks);
s32 MemCardDeleteFile(s32 chan, char* file);
s32 MemCardFormat(s32 chan);
s32 MemCardUnformat(s32 chan);
s32 MemCardSync(s32 mode, s32* cmds, s32* rslt);
void* MemCardCallback(void (*func)(void));
s32 MemCardGetDirentry(s32 chan, char* name, void* dir, s32* files, s32 ofs, s32 max);

/* libsnd */
s16 SsGetNck(void);

#endif
