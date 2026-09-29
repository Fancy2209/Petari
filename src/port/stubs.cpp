#include "SDL3/SDL_init.h"
#include "revolution/os.h"
#include <RVLFaceLib.h>
#include <SDL3/SDL_mutex.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_thread.h>
#include <SDL3/SDL_time.h>
#include <SDL3/SDL_timer.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <revolution.h>
#include <revolution/dsp.h>
#include <revolution/nwc24.h>
#include <revolution/rso.h>
#include <revolution/tpl.h>
#include <revolution/mem.h>
#include <unordered_map>
#include <SDL3/SDL.h>
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#define UNIMPLEMENTED_FUNCTION fprintf(stderr, "UNIMPLEMENTED FUNCTION %s CALLED!\n", __PRETTY_FUNCTION__);
#define UNIMPLEMENTED_FUNCTION_RET(x) UNIMPLEMENTED_FUNCTION return x;

static SDL_Mutex* gOSThreadsMutex = NULL;
static SDL_Mutex* gOSMutexesMutex = NULL;
static SDL_Mutex* gOSQueueCondsMutex = NULL;
struct { OSThread* key; SDL_Thread* value; } *gOSThreads = NULL;
struct { OSMutex* key; SDL_Mutex* value; } *gOSMutexes = NULL;
struct { OSThreadQueue* key; SDL_Condition* value; } *gOSQueueConds = NULL;
struct { OSThreadQueue* key; SDL_Mutex* value; } *gOSQueueMutexes = NULL;


    #include <stdint.h>
    struct Arena {
        uintptr_t low;
        uintptr_t high;
    };

    static Arena MEM1Arena;
    static Arena MEM2Arena;

    void* MEM1Start;
    void* MEM2Start;
    void* MEM1End;
    void* MEM2End;
    #define MEM1_DEFAULT_SIZE (24 * 1024 * 1024)
    #define MEM2_DEFAULT_SIZE (64 * 1024 * 1024)

extern "C" {
    DSPTaskInfo* __DSP_curr_task;
    DSPTaskInfo* __DSP_first_task;
    GDLObj* __GDCurrentDL = NULL;
    u32 __OSBusClock;
    u32 __MEM2End;
    u32 __OSFpscrEnableBits;
    // From libogc
    GXRenderModeObj GXNtsc480Int =
    {
        VI_TVMODE_NTSC_INT,     // viDisplayMode
        640,             // fbWidth
        480,             // efbHeight
        480,             // xfbHeight
        (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
        (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
        640,             // viWidth
        480,             // viHeight
        VI_XFBMODE_DF,   // xFBmode
        GX_FALSE,        // field_rendering
        GX_FALSE,        // aa

        // sample points arranged in increasing Y order
        {
            {6,6},{6,6},{6,6},  // pix 0, 3 sample points, 1/12 units, 4 bits each
            {6,6},{6,6},{6,6},  // pix 1
            {6,6},{6,6},{6,6},  // pix 2
            {6,6},{6,6},{6,6}   // pix 3
        },

        // vertical filter[7], 1/64 units, 6 bits each
        {
            0,         // line n-1
            0,         // line n-1
            21,         // line n
            22,         // line n
            21,         // line n
            0,         // line n+1
            0          // line n+1
        }
    };

    void AIInit(u8*) {UNIMPLEMENTED_FUNCTION}
    void AIInitDMA(u32, u32) {UNIMPLEMENTED_FUNCTION} 
    AIDCallback AIRegisterDMACallback(AIDCallback callback) {UNIMPLEMENTED_FUNCTION_RET(callback)}
    void AISetDSPSampleRate(u32) {UNIMPLEMENTED_FUNCTION}
    void AIStartDMA(void) {UNIMPLEMENTED_FUNCTION}
    void AIStopDMA(void) {UNIMPLEMENTED_FUNCTION}

    static u32 AR_StackPointer;
    void ARStartDMA(u32, u32, u32, u32) {UNIMPLEMENTED_FUNCTION} 
    u32 ARAlloc(u32 len) {AR_StackPointer+= len; UNIMPLEMENTED_FUNCTION_RET(AR_StackPointer)} 
    u32 ARInit(u32*, u32) {AR_StackPointer = 0x4000; UNIMPLEMENTED_FUNCTION_RET(0x4000)} 
    u32 ARGetBaseAddress(void) {UNIMPLEMENTED_FUNCTION_RET(0x4000)} 
    u32 ARGetSize(void) {UNIMPLEMENTED_FUNCTION_RET(MEM2_DEFAULT_SIZE)}
    void ARQInit(void) {UNIMPLEMENTED_FUNCTION}

    BOOL ARCInitHandle(void*, ARCHandle*) {UNIMPLEMENTED_FUNCTION_RET(false)}
    BOOL ARCFastOpen(ARCHandle*, s32, ARCFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    s32 ARCConvertPathToEntrynum(ARCHandle*, const char*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void* ARCGetStartAddrInMem(ARCFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(NULL)} 
    u32 ARCGetLength(ARCFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    BOOL ARCClose(ARCFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL ARCChangeDir(ARCHandle*, const char*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL ARCGetCurrentDir(ARCHandle*, char*, u32) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL ARCOpenDir(ARCHandle*, const char*, ARCDir*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL ARCReadDir(ARCDir*, ARCDirEntry*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL ARCCloseDir(ARCDir*) {UNIMPLEMENTED_FUNCTION_RET(false)}

    void DCFlushRange(void*, u32) {UNIMPLEMENTED_FUNCTION}
    void DCInvalidateRange(void*, u32) {UNIMPLEMENTED_FUNCTION}
    void DCStoreRange(void*, u32) {UNIMPLEMENTED_FUNCTION}
    void DCStoreRangeNoSync(void*, u32) {UNIMPLEMENTED_FUNCTION}
    void DCZeroRange(void*, u32) {UNIMPLEMENTED_FUNCTION}

    void DSPAssertInt(void) {UNIMPLEMENTED_FUNCTION} 
    u32 DSPCheckMailToDSP(void) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    u32 DSPCheckMailFromDSP(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void DSPInit(void) {UNIMPLEMENTED_FUNCTION} 
    u32 DSPReadMailFromDSP(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void DSPSendMailToDSP(u32) {UNIMPLEMENTED_FUNCTION}

    s32 DVDCancel(DVDCommandBlock*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    BOOL DVDCheckDiskAsync(DVDCommandBlock*, DVDCBCallback) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL DVDClose(DVDFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL DVDCloseDir(DVDDir*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    s32 DVDConvertPathToEntrynum(const char*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    BOOL DVDFastOpen(s32, DVDFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    s32 DVDGetCommandBlockStatus(const DVDCommandBlock*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    s32 DVDGetDriveStatus(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void DVDInit(void) {UNIMPLEMENTED_FUNCTION} 
    BOOL DVDOpen(const char*, DVDFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL DVDOpenDir(const char*, DVDDir*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL DVDReadAsyncPrio(DVDFileInfo*, void*, s32, s32, DVDCallback, s32) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    BOOL DVDReadDir(DVDDir*, DVDDirEntry*) {UNIMPLEMENTED_FUNCTION_RET(false)} 
    s32 DVDReadPrio(DVDFileInfo*, void*, s32, s32, s32) {UNIMPLEMENTED_FUNCTION_RET(0)}

    void GDFlushCurrToMem() {UNIMPLEMENTED_FUNCTION}
    void GDInitGDLObj(GDLObj*, void*, u32) {UNIMPLEMENTED_FUNCTION}
    void GDOverflowed() {UNIMPLEMENTED_FUNCTION}
    void GDPadCurr32() {UNIMPLEMENTED_FUNCTION}
    void GDSetAlphaCompare(GXCompare, u8, GXAlphaOp, GXCompare, u8) {UNIMPLEMENTED_FUNCTION}
    void GDSetArray(GXAttr attr, const void* base_ptr, u8 stride) {UNIMPLEMENTED_FUNCTION}
    void GDSetArrayRaw(GXAttr attr, u32 base_ptr_raw, u8 stride) {UNIMPLEMENTED_FUNCTION}
    void GDSetBlendMode(GXBlendMode, GXBlendFactor, GXBlendFactor, GXLogicOp) {UNIMPLEMENTED_FUNCTION}
    void GDSetBlendModeEtc(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp logic_op, GXBool color_update_enable,
                       GXBool alpha_update_enable, GXBool dither_enable) {UNIMPLEMENTED_FUNCTION}
    void GDSetChanAmbColor(GXChannelID chan, GXColor color) {UNIMPLEMENTED_FUNCTION}
    void GDSetChanCtrl(GXChannelID, GXBool, GXColorSrc, GXColorSrc, u32, GXDiffuseFn, GXAttnFn) {UNIMPLEMENTED_FUNCTION}
    void GDSetChanMatColor(GXChannelID chan, GXColor color) {UNIMPLEMENTED_FUNCTION}
    void GDSetCullMode(GXCullMode mode) {UNIMPLEMENTED_FUNCTION}
    void GDSetCurrentMtx(u32 pn, u32 t0, u32 t1, u32 t2, u32 t3, u32 t4, u32 t5, u32 t6, u32 t7) {UNIMPLEMENTED_FUNCTION}
    void GDSetDstAlpha(GXBool enable, u8 alpha) {UNIMPLEMENTED_FUNCTION} 
    void GDSetFog(GXFogType, f32, f32, f32, f32, GXColor) {UNIMPLEMENTED_FUNCTION}
    void GDSetGenMode(u8, u8, u8) {UNIMPLEMENTED_FUNCTION}
    void GDSetGenMode2(u8 nTexGens, u8 nChans, u8 nTevs, u8 nInds, GXCullMode cm) {UNIMPLEMENTED_FUNCTION}
    void GDSetTevAlphaCalcAndSwap(GXTevStageID, GXTevAlphaArg, GXTevAlphaArg, GXTevAlphaArg, GXTevAlphaArg, GXTevOp, GXTevBias, GXTevScale, GXBool,
                              GXTevRegID, GXTevSwapSel, GXTevSwapSel) {UNIMPLEMENTED_FUNCTION}
    void GDSetTevColor(GXTevRegID, GXColor) {UNIMPLEMENTED_FUNCTION}
    void GDSetTevColorCalc(GXTevStageID stage, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d, GXTevOp op, GXTevBias bias,
                       GXTevScale scale, GXBool clamp, GXTevRegID out_reg) {UNIMPLEMENTED_FUNCTION}
    void GDSetTevDirect(GXTevStageID) {UNIMPLEMENTED_FUNCTION}
    void GDSetTevOrder(GXTevStageID evenStage, GXTexCoordID coord0, GXTexMapID map0, GXChannelID color0, GXTexCoordID coord1, GXTexMapID map1,
                   GXChannelID color1) {UNIMPLEMENTED_FUNCTION}
    void GDSetTexCoordGen(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, GXBool normalize, u32 postmtx) {UNIMPLEMENTED_FUNCTION}
    void GDSetTexImgAttr(GXTexMapID id, u16 width, u16 height, GXTexFmt format) {UNIMPLEMENTED_FUNCTION}
    void GDSetTexImgPtr(GXTexMapID id, void* image_ptr) {UNIMPLEMENTED_FUNCTION}
    void GDSetTexLookupMode(GXTexMapID id, GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, GXTexFilter min_filt, GXTexFilter mag_filt, f32 min_lod,
                        f32 max_lod, f32 lod_bias, GXBool bias_clamp, GXBool do_edge_lod, GXAnisotropy max_aniso) {UNIMPLEMENTED_FUNCTION}
    void GDSetVtxDescv(const GXVtxDescList* attrPtr) {UNIMPLEMENTED_FUNCTION}
    void GDSetZMode(GXBool, GXCompare, GXBool) {UNIMPLEMENTED_FUNCTION}

    void GXAbortFrame(void) {UNIMPLEMENTED_FUNCTION}
    void GXBegin(GXPrimitive, GXVtxFmt, u16) {UNIMPLEMENTED_FUNCTION}
    void GXCallDisplayList(const void *, u32) {UNIMPLEMENTED_FUNCTION}
    void GXClearVtxDesc(void) {UNIMPLEMENTED_FUNCTION}
    void GXCopyDisp(void*, GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXCopyTex(void*, GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXDisableBreakPt(void) {UNIMPLEMENTED_FUNCTION}
    void GXDrawDone(void) {UNIMPLEMENTED_FUNCTION}
    void GXEnableBreakPt(void* pBreakPoint) {UNIMPLEMENTED_FUNCTION}
    void GXEnableTexOffsets(GXTexCoordID, GXBool, GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXFlush(void) {UNIMPLEMENTED_FUNCTION}
    GXBool GXGetCPUFifo(GXFifoObj*){UNIMPLEMENTED_FUNCTION_RET(false)}
    void GXGetFifoPtrs(const GXFifoObj*, void**, void**) {UNIMPLEMENTED_FUNCTION}
    void GXGetGPStatus(GXBool*, GXBool*, GXBool*, GXBool*, GXBool*) {UNIMPLEMENTED_FUNCTION}
    u16 GXGetNumXfbLines(u16, f32) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void GXGetProjectionv(f32* ptr) {UNIMPLEMENTED_FUNCTION}
    u32 GXGetTexBufferSize(u16, u16, u32, GXBool, u8) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void GXGetTexObjAll(const GXTexObj *, void **, u16 *, u16 *, GXTexFmt *, GXTexWrapMode *, GXTexWrapMode *, GXBool *) {UNIMPLEMENTED_FUNCTION}
    void GXGetTexObjLODAll(const GXTexObj *, GXTexFilter *, GXTexFilter *, f32 *, f32 *, f32 *, GXBool *, GXBool *, GXAnisotropy *) {UNIMPLEMENTED_FUNCTION}
    u32 GXGetTexObjTlut(const GXTexObj *) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void GXGetViewportv(f32 *) {UNIMPLEMENTED_FUNCTION}
    f32 GXGetYScaleFactor(u16, u16){UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    GXFifoObj* GXInit(void*, u32){UNIMPLEMENTED_FUNCTION_RET(NULL)}
    void GXInitLightAttn(GXLightObj*, f32, f32, f32, f32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void GXInitLightColor(GXLightObj*, GXColor) {UNIMPLEMENTED_FUNCTION}
    void GXInitLightDir(GXLightObj*, f32, f32, f32)  {UNIMPLEMENTED_FUNCTION}
    void GXInitLightDistAttn(GXLightObj*, f32, f32, GXDistAttnFn)  {UNIMPLEMENTED_FUNCTION}
    void GXInitLightPos(GXLightObj*, f32, f32, f32)  {UNIMPLEMENTED_FUNCTION}
    void GXInitLightSpot(GXLightObj*, f32, GXSpotFn)  {UNIMPLEMENTED_FUNCTION}
    void GXInitSpecularDir(GXLightObj*, f32, f32, f32)  {UNIMPLEMENTED_FUNCTION}
    void GXInitSpecularDirHA(GXLightObj*, f32, f32, f32, f32, f32, f32)  {UNIMPLEMENTED_FUNCTION}
    void GXInitTexCacheRegion(GXTexRegion *, GXBool, u32, GXTexCacheSize, u32, GXTexCacheSize) {UNIMPLEMENTED_FUNCTION}
    void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXInitTexObjLOD(GXTexObj *, GXTexFilter, GXTexFilter, f32, f32, f32, GXBool, GXBool, GXAnisotropy) {UNIMPLEMENTED_FUNCTION}
    void GXInitTexObjCI(GXTexObj *, void *, u16, u16, GXCITexFmt, GXTexWrapMode, GXTexWrapMode, GXBool, u32) {UNIMPLEMENTED_FUNCTION}
    void GXInitTexObjTlut(GXTexObj *, u32) {UNIMPLEMENTED_FUNCTION}
    void GXInitTlutObj(GXTlutObj *, void *, GXTlutFmt, u16) {UNIMPLEMENTED_FUNCTION}
    void GXInvalidateTexAll(void) {UNIMPLEMENTED_FUNCTION}
    void GXInvalidateVtxCache(void) {UNIMPLEMENTED_FUNCTION}
    void GXLoadLightObjImm(const GXLightObj*, GXLightID) {UNIMPLEMENTED_FUNCTION}
    void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {UNIMPLEMENTED_FUNCTION}
    void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {UNIMPLEMENTED_FUNCTION}
    void GXLoadTexMtxImm(const f32 mtx[][4], u32 id, GXTexMtxType type) {UNIMPLEMENTED_FUNCTION}
    void GXLoadTexMtxIndx(u16 mtx_indx, u32 id, GXTexMtxType type) {UNIMPLEMENTED_FUNCTION}
    void GXLoadTexObj(const GXTexObj *, GXTexMapID) {UNIMPLEMENTED_FUNCTION}
    void GXLoadTlut(const GXTlutObj *, u32) {UNIMPLEMENTED_FUNCTION}
    void GXPeekARGB(u16 x, u16 y, u32* color) {UNIMPLEMENTED_FUNCTION}
    void GXPeekZ(u16 x, u16 y, u32* z) {UNIMPLEMENTED_FUNCTION}
    void GXPixModeSync(void) {UNIMPLEMENTED_FUNCTION}
    void GXPokeAlphaRead(GXAlphaReadMode) {UNIMPLEMENTED_FUNCTION}
    void GXProject(f32 x, f32 y, f32 z, const f32 pMtx[3][4], const f32* pProjection, const f32* pViewport, f32* pScreenX, f32* pScreenY, f32* pScreenZ) {UNIMPLEMENTED_FUNCTION}
    void GXReadXfRasMetric(u32*, u32*, u32*, u32*) {UNIMPLEMENTED_FUNCTION}
    void GXSetAlphaCompare(GXCompare, u8, GXAlphaOp, GXCompare, u8) {UNIMPLEMENTED_FUNCTION}
    void GXSetAlphaUpdate(GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXSetArray(GXAttr, const void *, u8) {UNIMPLEMENTED_FUNCTION}
    void GXSetBlendMode(GXBlendMode, GXBlendFactor, GXBlendFactor, GXLogicOp) {UNIMPLEMENTED_FUNCTION}
    void GXSetChanAmbColor(GXChannelID, GXColor) {UNIMPLEMENTED_FUNCTION}
    void GXSetChanCtrl(GXChannelID, GXBool, GXColorSrc, GXColorSrc, u32, GXDiffuseFn, GXAttnFn) {UNIMPLEMENTED_FUNCTION}
    void GXSetChanMatColor(GXChannelID, GXColor) {UNIMPLEMENTED_FUNCTION}
    void GXSetClipMode(GXClipMode) {UNIMPLEMENTED_FUNCTION}
    void GXSetCoPlanar(GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXSetColorUpdate(GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXSetCopyClamp(GXFBClamp) {UNIMPLEMENTED_FUNCTION}
    void GXSetCopyClear(GXColor, u32) {UNIMPLEMENTED_FUNCTION}
    void GXSetCopyFilter(GXBool, const u8[12][2], GXBool, const u8[7]) {UNIMPLEMENTED_FUNCTION}
    void GXSetCullMode(GXCullMode) {UNIMPLEMENTED_FUNCTION}
    void GXSetCurrentMtx(u32 id) {UNIMPLEMENTED_FUNCTION}
    void GXSetDispCopyDst(u16, u16) {UNIMPLEMENTED_FUNCTION}
    void GXSetDispCopyGamma(GXGamma) {UNIMPLEMENTED_FUNCTION}
    void GXSetDispCopySrc(u16, u16, u16, u16) {UNIMPLEMENTED_FUNCTION}
    u32 GXSetDispCopyYScale(f32){UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    void GXSetDither(GXBool) {UNIMPLEMENTED_FUNCTION}
    void GXSetDrawDone(void) {UNIMPLEMENTED_FUNCTION}
    void GXSetDrawSync(u16 token) {UNIMPLEMENTED_FUNCTION}
    GXDrawDoneCallback GXSetDrawDoneCallback(GXDrawDoneCallback cb){UNIMPLEMENTED_FUNCTION_RET(cb)}
    GXDrawSyncCallback GXSetDrawSyncCallback(GXDrawSyncCallback cb) {UNIMPLEMENTED_FUNCTION_RET(cb)}
    void GXSetDstAlpha(GXBool, u8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetFog(GXFogType, f32, f32, f32, f32, GXColor)  {UNIMPLEMENTED_FUNCTION}
    void GXSetFogRangeAdj(GXBool, u16, const GXFogAdjTable *)  {UNIMPLEMENTED_FUNCTION}
    void GXSetIndTexCoordScale(GXIndTexStageID, GXIndTexScale, GXIndTexScale)  {UNIMPLEMENTED_FUNCTION}
    void GXSetIndTexMtx(GXIndTexMtxID, const f32[2][3], s8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetIndTexOrder(GXIndTexStageID, GXTexCoordID, GXTexMapID)  {UNIMPLEMENTED_FUNCTION}
    void GXSetLineWidth(u8, GXTexOffset)  {UNIMPLEMENTED_FUNCTION}
    void GXSetMisc(GXMiscToken, u32)  {UNIMPLEMENTED_FUNCTION}
    void GXSetNumChans(u8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetNumIndStages(u8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetNumTevStages(u8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetNumTexGens(u8)  {UNIMPLEMENTED_FUNCTION}
    void GXSetPixelFmt(GXPixelFmt, GXZFmt16)  {UNIMPLEMENTED_FUNCTION}
    void GXSetPointSize(u8, GXTexOffset)  {UNIMPLEMENTED_FUNCTION}
    void GXSetProjection(const f32 mtx[4][4], GXProjectionType type)  {UNIMPLEMENTED_FUNCTION}
    void GXSetScissor(u32, u32, u32, u32)  {UNIMPLEMENTED_FUNCTION}
    void GXSetScissorBoxOffset(s32, s32)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevOp(GXTevStageID, GXTevMode)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevColorIn(GXTevStageID, GXTevColorArg, GXTevColorArg, GXTevColorArg, GXTevColorArg)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevAlphaIn(GXTevStageID, GXTevAlphaArg, GXTevAlphaArg, GXTevAlphaArg, GXTevAlphaArg)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevColorOp(GXTevStageID, GXTevOp, GXTevBias, GXTevScale, GXBool, GXTevRegID)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevAlphaOp(GXTevStageID, GXTevOp, GXTevBias, GXTevScale, GXBool, GXTevRegID)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevColor(GXTevRegID, GXColor)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevColorS10(GXTevRegID, GXColorS10)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevDirect(GXTevStageID) {UNIMPLEMENTED_FUNCTION}
    void GXSetTevIndirect(GXTevStageID, GXIndTexStageID, GXIndTexFormat, GXIndTexBiasSel, GXIndTexMtxID, GXIndTexWrap, GXIndTexWrap, GXBool,
                             GXBool, GXIndTexAlphaSel) {UNIMPLEMENTED_FUNCTION}
    void GXSetTevIndWarp(GXTevStageID, GXIndTexStageID, GXBool, GXBool, GXIndTexMtxID) {UNIMPLEMENTED_FUNCTION}

    void GXSetTevOrder(GXTevStageID, GXTexCoordID, GXTexMapID, GXChannelID)  {UNIMPLEMENTED_FUNCTION}
    void GXSetZTexture(GXZTexOp, GXTexFmt, u32)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevKColor(GXTevKColorID, GXColor)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevKColorSel(GXTevStageID, GXTevKColorSel)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevKAlphaSel(GXTevStageID, GXTevKAlphaSel)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevSwapModeTable(GXTevSwapSel, GXTevColorChan, GXTevColorChan, GXTevColorChan, GXTevColorChan)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTevSwapMode(GXTevStageID, GXTevSwapSel, GXTevSwapSel)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTexCoordGen2(GXTexCoordID, GXTexGenType, GXTexGenSrc, u32, GXBool, u32)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTexCoordScaleManually(GXTexCoordID coord, GXBool enable, u16 ss, u16 ts)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTexCopyDst(u16, u16, GXTexFmt, GXBool)  {UNIMPLEMENTED_FUNCTION}
    void GXSetTexCopySrc(u16, u16, u16, u16)  {UNIMPLEMENTED_FUNCTION}
    void GXSetViewport(f32, f32, f32, f32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void GXSetVtxAttrFmt(GXVtxFmt, GXAttr, GXCompCnt, GXCompType, u8) {UNIMPLEMENTED_FUNCTION}
    void GXSetVtxDesc(GXAttr, GXAttrType) {UNIMPLEMENTED_FUNCTION}
    void GXSetZCompLoc(GXBool){UNIMPLEMENTED_FUNCTION}
    void GXSetZMode(GXBool, GXCompare, GXBool){UNIMPLEMENTED_FUNCTION}
    void GXSetZScaleOffset(f32, f32){UNIMPLEMENTED_FUNCTION}
    void GXTexCoord2f32(const f32 x, const f32 y)  {UNIMPLEMENTED_FUNCTION}
    void GXTexCoord2s16(const s16 x, const s16 y)  {UNIMPLEMENTED_FUNCTION}
    void GXTexCoord2u16(const u16 x, const u16 y)  {UNIMPLEMENTED_FUNCTION}
    void GXTexCoord2u8 (const u8 x,  const u8 y)  {UNIMPLEMENTED_FUNCTION}
    void GXCmd1f32(const f32 x)  {UNIMPLEMENTED_FUNCTION}
    void GXCmd1u16(const u16 x)  {UNIMPLEMENTED_FUNCTION}
    void GXCmd1u32(const u32 x)  {UNIMPLEMENTED_FUNCTION}
    void GXCmd1u8 (const u8 x)  {UNIMPLEMENTED_FUNCTION}
    void GXColor1u32(const u32 r)  {UNIMPLEMENTED_FUNCTION}
    void GXColor4u8 (const u8 r, const u8 g, const u8 b, const u8 a)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition1x8(const u8 x)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition2f32(const f32 x, const f32 y)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition2u16(const u16 x, const u16 y)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition3f32(const f32 x, const f32 y, const f32 z)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition3s16(const s16 x, const s16 y, const s16 z)  {UNIMPLEMENTED_FUNCTION}
    void GXPosition3u8(const u8 x, const u8 y, const u8 z)  {UNIMPLEMENTED_FUNCTION}
    void GXNormal3f32(const f32 x, const f32 y, const f32 z) {UNIMPLEMENTED_FUNCTION}
    void GXTexModeSync(void) {UNIMPLEMENTED_FUNCTION}

    void KPADInit() {UNIMPLEMENTED_FUNCTION}
    s32 KPADRead(s32, KPADStatus[], u32) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void KPADReset(void) {UNIMPLEMENTED_FUNCTION}
    void KPADSetAccParam(s32 chan, f32 playRadius, f32 sensitivity) {UNIMPLEMENTED_FUNCTION}
    void KPADSetBtnRepeat(s32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void KPADSetDistParam(s32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void KPADSetHoriParam(s32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void KPADSetPosParam(s32, f32, f32)  {UNIMPLEMENTED_FUNCTION}
    void KPADSetSensorHeight(s32, f32)   {UNIMPLEMENTED_FUNCTION}

    void LCEnable(void) {UNIMPLEMENTED_FUNCTION}
    void LCDisable(void) {UNIMPLEMENTED_FUNCTION}

    void* MEMAllocFromAllocator(MEMAllocator *, u32) {UNIMPLEMENTED_FUNCTION_RET(NULL)}
    void MEMFreeToAllocator(MEMAllocator *, void *) {UNIMPLEMENTED_FUNCTION}

    void NANDInitBanner(NANDBanner*, u32, const u16*, const u16*) {UNIMPLEMENTED_FUNCTION}
    s32 NANDCheck(u32, u32, u32*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDClose(NANDFileInfo*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDCreate(const char*, u8, u8) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDDelete(const char*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDGetHomeDir(char[NAND_MAX_PATH]) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDGetLength(NANDFileInfo*, u32*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDMove(const char*, const char*) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDOpen(const char*, NANDFileInfo*, u8) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDRead(NANDFileInfo*, void*, u32) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 NANDWrite(NANDFileInfo*, const void*, u32) {UNIMPLEMENTED_FUNCTION_RET(0)}

    NWC24Err NWC24CloseLib(void) {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24CommitMsg(NWC24MsgObj* pMsg) {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    s32 NWC24GetErrorCode(void) {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24GetMsgSize(const NWC24MsgObj* pMsg, u32* size)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24GetMyUserId(NWC24UserId* pUserId)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24InitMsgObj(NWC24MsgObj* pMsg, NWC24MsgType type)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24OpenLib(void* pWork)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgAltName(NWC24MsgObj* pMsg, const u16* pName, u32 len)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgAttached(NWC24MsgObj* pMsg, const char* data, u32 size, NWC24MIMEType type)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgLedPattern(NWC24MsgObj* pMsg, u16 pattern)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgMBDelay(NWC24MsgObj* pMsg, u8 delay)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgMBNoReply(NWC24MsgObj* pMsg, BOOL enable)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgTag(NWC24MsgObj* pMsg, u16 tag)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgText(NWC24MsgObj* pMsg, const char* pText, u32 len, NWC24Charset charset, NWC24Encoding encoding)  {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}
    NWC24Err NWC24SetMsgToId(NWC24MsgObj* pMsg, NWC24UserId userId) {UNIMPLEMENTED_FUNCTION_RET(NWC24_OK)}


    void OSCancelAlarm(OSAlarm *) {UNIMPLEMENTED_FUNCTION}
    void OSCancelThread(OSThread *){UNIMPLEMENTED_FUNCTION}
    void OSClearContext(OSContext *){UNIMPLEMENTED_FUNCTION}
    void OSCreateAlarm(OSAlarm *){UNIMPLEMENTED_FUNCTION}
    BOOL OSCreateThread(OSThread * thread, void* (*func)(void*), 
    void * param, void *stack, u32 stackSize, OSPriority prio, u16 attr) {
        memset(thread, 0, sizeof(OSThread));

        thread->state    = OS_THREAD_STATE_READY;
        thread->attr     = attr & 1u;
        thread->base     = prio;
        thread->priority = prio;
        thread->suspend  = 0;  // Created unsuspended (SDL behavior)
        thread->value    = (void*)(intptr_t)-1;
        thread->mutex    = nullptr;

        OSInitThreadQueue(&thread->queueJoin);
        thread->queueMutex.head = thread->queueMutex.tail = nullptr;
        thread->link.next = thread->link.prev = nullptr;
        thread->linkActive.next = thread->linkActive.prev = nullptr;

        // Stack (stack points to TOP on GameCube)
        thread->stackBase = (u8*)stack;
        thread->stackEnd  = (u32*)((uintptr_t)stack - stackSize);
        *thread->stackEnd = 0xDEADBABE;

        OSClearContext(&thread->context);

        thread->error = 0;
        thread->specific[0] = nullptr;
        thread->specific[1] = nullptr;

        const SDL_PropertiesID props = SDL_CreateProperties();
        SDL_SetPointerProperty(props, SDL_PROP_THREAD_CREATE_ENTRY_FUNCTION_POINTER, (void *) func);
        SDL_SetPointerProperty(props, SDL_PROP_THREAD_CREATE_USERDATA_POINTER, param);
        SDL_SetNumberProperty(props, SDL_PROP_THREAD_CREATE_STACKSIZE_NUMBER, (Sint64) stackSize);
        SDL_LockMutex(gOSThreadsMutex);
        hmput(gOSThreads, thread, SDL_CreateThreadWithProperties(props));
        SDL_UnlockMutex(gOSThreadsMutex);
        return true;
    }
    void OSDetachThread(OSThread * thread) {
        SDL_LockMutex(gOSThreadsMutex);
        SDL_DetachThread(hmget(gOSThreads, thread));
        SDL_UnlockMutex(gOSThreadsMutex);
    }
    BOOL OSDisableInterrupts(void) {UNIMPLEMENTED_FUNCTION_RET(false)}
    BOOL OSEnableInterrupts(void) {UNIMPLEMENTED_FUNCTION_RET(false)}
    s32 OSDisableScheduler(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    s32 OSEnableScheduler(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void OSExitThread(void *) {UNIMPLEMENTED_FUNCTION}
    void OSFillFPUContext(OSContext* context) {UNIMPLEMENTED_FUNCTION}
    OSContext* OSGetCurrentContext(void) {UNIMPLEMENTED_FUNCTION_RET(NULL)}
    void OSInitMutexes(void);
    OSThread* OSGetCurrentThread(void) {
        SDL_ThreadID id = SDL_GetCurrentThreadID();
        for(size_t i = 0; i < hmlen(gOSThreads); i++) {
            if(SDL_GetThreadID(gOSThreads[i].value) == id) {
                return gOSThreads[i].key;
            }
        }
        return NULL;
    }
    BOOL OSGetResetButtonState(void) {UNIMPLEMENTED_FUNCTION_RET(false)}
    u32 OSGetStackPointer(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    OSPriority OSGetThreadPriority(OSThread *) {UNIMPLEMENTED_FUNCTION_RET(0)}
    OSTime OSGetTime(void) {
        u64 gamecubeEpochStartTicks = OSSecondsToTicks(946684800); /* 1 Jan, 2000 00:00:00*/
	
        SDL_Time nowTv;
        SDL_GetCurrentTime(&nowTv);
        
        u64 nowTicks = OSNanosecondsToTicks(nowTv);
        return (OSTime)(nowTicks - gamecubeEpochStartTicks);
    }
    OSTick OSGetTick(void) { return OSMillisecondsToTicks(SDL_GetTicks()); }
    void OSInitMutex(OSMutex* mutex) {
        OSInitThreadQueue(&mutex->queue);
        mutex->thread = NULL;
        mutex->count = 0;
        SDL_LockMutex(gOSMutexesMutex);
        hmput(gOSMutexes, mutex, SDL_CreateMutex());
        SDL_UnlockMutex(gOSMutexesMutex);
    }
    BOOL OSIsThreadSuspended(OSThread *)  {UNIMPLEMENTED_FUNCTION_RET(false)}
    BOOL OSIsThreadTerminated(OSThread *)  {UNIMPLEMENTED_FUNCTION_RET(false)}
    BOOL OSJoinThread(OSThread * thred, void **)  {
        SDL_LockMutex(gOSThreadsMutex);
        SDL_WaitThread(hmget(gOSThreads, thred), NULL); 
        SDL_UnlockMutex(gOSThreadsMutex);
        return true;
    }
    void OSLockMutex(OSMutex * mutex) {
        SDL_LockMutex(gOSMutexesMutex);
        SDL_LockMutex(hmget(gOSMutexes, mutex));
        SDL_UnlockMutex(gOSMutexesMutex);
    }
    void OSPanic(const char* file, int line, const char* message, ...) {
        fprintf(stderr, "%s:%d: ", file, line);
        va_list args;
        va_start(args, message);
        vfprintf(stderr, message, args);
        va_end(args);
        fflush(stderr);
        abort();
    }
    void OSProtectRange(u32, void*, u32, u32) {UNIMPLEMENTED_FUNCTION}
    void OSRebootSystem(void) {UNIMPLEMENTED_FUNCTION}
    void OSRegisterVersion(const char*) {UNIMPLEMENTED_FUNCTION}
    void OSReport(const char* message, ...) {
        va_list args;
        va_start(args, message);
        OSVReport(message, args);
        va_end(args);
    }
    void OSRestart(u32) {UNIMPLEMENTED_FUNCTION}
    BOOL OSRestoreInterrupts(BOOL)  {UNIMPLEMENTED_FUNCTION_RET(false)}
    s32 OSResumeThread(OSThread *)  {UNIMPLEMENTED_FUNCTION_RET(false)}
    void OSReturnToMenu(void) {UNIMPLEMENTED_FUNCTION}
    void OSSetAlarm(OSAlarm *, OSTime, OSAlarmHandler) {UNIMPLEMENTED_FUNCTION}
    void OSSetCurrentContext(OSContext *) {UNIMPLEMENTED_FUNCTION}
    OSErrorHandler OSSetErrorHandler(OSError, OSErrorHandler cb) {UNIMPLEMENTED_FUNCTION_RET(cb)}
    void OSSetPeriodicAlarm(OSAlarm *, OSTime, OSTime, OSAlarmHandler) {UNIMPLEMENTED_FUNCTION}
    OSPowerCallback OSSetPowerCallback(OSPowerCallback cb) {UNIMPLEMENTED_FUNCTION_RET(cb)}
    BOOL OSSetThreadPriority(OSThread *, OSPriority) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void OSShutdownSystem(void) {UNIMPLEMENTED_FUNCTION}
    
    void OSSleepThread(OSThreadQueue* queue) {
        if (!queue) return;

        SDL_LockMutex(gOSThreadsMutex);
        OSThread* currentThread = OSGetCurrentThread();
        SDL_UnlockMutex(gOSThreadsMutex);
        if (!currentThread) return;

        currentThread->state = OS_THREAD_STATE_WAITING;
        currentThread->queue = queue;

        // Enqueue into the thread queue
        OSThread* prev = queue->tail;
        if (prev == nullptr) {
            queue->head = currentThread;
        } else {
            prev->link.next = currentThread;
        }
        currentThread->link.prev = prev;
        currentThread->link.next = nullptr;
        queue->tail = currentThread;

        // Wait on the condition variable for this queue
        SDL_LockMutex(gOSQueueCondsMutex);
        SDL_WaitCondition( hmget(gOSQueueConds, queue), hmget(gOSQueueMutexes, queue));
        SDL_UnlockMutex(gOSQueueCondsMutex);
    }
    void OSSleepTicks(OSTime time) { SDL_Delay(OSTicksToMicroseconds(time)); }
    s32 OSSuspendThread(OSThread *) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void OSTicksToCalendarTime(OSTime, OSCalendarTime*) {UNIMPLEMENTED_FUNCTION}
    void OSUnlockMutex(OSMutex *mutex) {
        SDL_LockMutex(gOSMutexesMutex);
        SDL_UnlockMutex(hmget(gOSMutexes, mutex));
        SDL_UnlockMutex(gOSMutexesMutex);

    }
    void OSVReport(const char* message, va_list args) {
	    vfprintf(stdout, message, args);
	    fflush(stdout);
    }
    void OSYieldThread(void) { SDL_Delay(50); }
    void OSInitThreadQueue(OSThreadQueue* queue) {
        queue->head = queue->tail = 0;
        SDL_LockMutex(gOSQueueCondsMutex);
        hmput(gOSQueueConds, queue, SDL_CreateCondition());
        hmput(gOSQueueMutexes, queue, SDL_CreateMutex());
        SDL_UnlockMutex(gOSQueueCondsMutex);
    }
    void OSWakeupThread(OSThreadQueue* queue) {
    if (!queue) return;

    // Wake all threads in the queue
    OSThread* thread = queue->head;
    while (thread) {
        OSThread* next = thread->link.next;
        thread->state = OS_THREAD_STATE_READY;
        thread->link.next = nullptr;
        thread->link.prev = nullptr;
        thread->queue = nullptr;
        thread = next;
    }
    queue->head = queue->tail = nullptr;

    // Notify all waiters
    SDL_BroadcastCondition(hmget(gOSQueueConds, queue));
}

    void OSInitMutexes(void) {
        UNIMPLEMENTED_FUNCTION // Not implemented but useful for logging
        gOSThreadsMutex = SDL_CreateMutex();
        gOSMutexesMutex = SDL_CreateMutex();
        gOSQueueCondsMutex = SDL_CreateMutex();
    }

    static bool __OSInited = false;
    void OSInit(void) {
        if(__OSInited) return;
        __OSInited = true;
        OSInitMutexes();
        MEM1Start = malloc(MEM1_DEFAULT_SIZE);
        memset(MEM1Start, 0, MEM1_DEFAULT_SIZE);
        MEM1End = (void*)((uintptr_t)MEM1Start + MEM1_DEFAULT_SIZE);
        MEM1Arena.low = (uintptr_t)MEM1Start;
        MEM1Arena.high = (uintptr_t)MEM1End;

        MEM2Start = calloc(1, MEM2_DEFAULT_SIZE);
        memset(MEM2Start, 0, MEM2_DEFAULT_SIZE);
        MEM2End = (void*)((uintptr_t)MEM2Start + MEM2_DEFAULT_SIZE);
        MEM2Arena.low = (uintptr_t)MEM2Start;
        MEM2Arena.high = (uintptr_t)MEM2End;
    }

    void* OSGetMEM1ArenaHi(void) { return (void*)MEM1Arena.high; }
    void* OSGetMEM1ArenaLo(void) { return (void*)MEM1Arena.low; }
    void* OSGetArenaHi(void) { return OSGetMEM1ArenaHi(); }
    void* OSGetArenaLo(void) { return OSGetMEM1ArenaLo(); }
    void* OSGetMEM2ArenaHi(void) { return (void*)MEM2Arena.high;  }
    void* OSGetMEM2ArenaLo(void) { return (void*)MEM2Arena.low; }
    static void SetBound(uintptr_t& bound, void* value, void* start, void* end) {
	const auto address = reinterpret_cast<uintptr_t>(value);

	if (address < reinterpret_cast<uintptr_t>(start) || address > reinterpret_cast<uintptr_t>(end)) {
		OSReport("Arena boundary is outside its memory region\n"); abort();
	}

	bound = address;
}
    void OSSetMEM1ArenaHi(void* value) {SetBound(MEM1Arena.high, value, MEM1Start, MEM1End);}
    void OSSetMEM1ArenaLo(void* value) {SetBound(MEM1Arena.low, value, MEM1Start, MEM1End);}
    void OSSetArenaHi(void* value) { return OSSetMEM1ArenaHi(value); }
    void OSSetArenaLo(void* value) { return OSSetMEM1ArenaLo(value); }
    void OSSetMEM2ArenaHi(void* value) {SetBound(MEM2Arena.high, value, MEM2Start, MEM2End);}
    
    constexpr u32 kAlignment = 32;
    constexpr u32 kHeaderSize = 32;
    constexpr u32 kMinObjectSize = 64;
    struct HeapDesc;
    struct alignas(32) Cell {
        Cell* prev;
        Cell* next;
        s32 size;
        HeapDesc* owner;
    };
    struct HeapDesc {
        s32 size;
        Cell* freeList;
        Cell* allocated;
    };
    static HeapDesc* sHeapArray = nullptr;
    static int sNumHeaps = 0;
    static u8* sArenaStart = nullptr;
    static u8* sArenaEnd = nullptr;
    
    static uintptr_t roundUp32(const uintptr_t value) {
    return (value + (kAlignment - 1)) & ~(static_cast<uintptr_t>(kAlignment - 1));
    }

    static uintptr_t roundDown32(const uintptr_t value) {
    return value & ~(static_cast<uintptr_t>(kAlignment - 1));
    }
    volatile int __OSCurrHeap;
    void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps) {
        if (arenaStart == nullptr || arenaEnd == nullptr || maxHeaps <= 0) {
            return nullptr;
        }

        auto start = reinterpret_cast<uintptr_t>(arenaStart);
        auto end = reinterpret_cast<uintptr_t>(arenaEnd);
        if (start >= end) {
            return nullptr;
        }

        const auto arrayBytes = static_cast<uintptr_t>(maxHeaps) * sizeof(HeapDesc);
        if ((end - start) < arrayBytes + kMinObjectSize) {
            return nullptr;
        }

        sHeapArray = reinterpret_cast<HeapDesc*>(arenaStart);
        sNumHeaps = maxHeaps;
        for (int i = 0; i < sNumHeaps; ++i) {
            sHeapArray[i].size = -1;
            sHeapArray[i].freeList = nullptr;
            sHeapArray[i].allocated = nullptr;
        }

        __OSCurrHeap = -1;
        sArenaStart = reinterpret_cast<u8*>(roundUp32(start + arrayBytes));
        sArenaEnd = reinterpret_cast<u8*>(roundDown32(end));
        if (sArenaEnd <= sArenaStart || static_cast<uintptr_t>(sArenaEnd - sArenaStart) < kMinObjectSize) {
            sHeapArray = nullptr;
            sNumHeaps = 0;
            sArenaStart = nullptr;
            sArenaEnd = nullptr;
            return nullptr;
        }

        return sArenaStart;
    }

    void* OSPhysicalToCached(u32 paddr) {
        if(paddr >= MEM1_DEFAULT_SIZE) {printf("This shouldn't happpeennnnn\n"); abort();}
            return (void*)((uintptr_t)MEM1Start + paddr);
    }

    u32 OSCachedToPhysical(void* caddr) {
        return (u32)((uintptr_t)caddr - (uintptr_t)MEM1End);
    }


    void OSInitMessageQueue(OSMessageQueue *mq, OSMessage* msgArray, s32 msgCount) {
        OSInitThreadQueue(&mq->queueSend);
        OSInitThreadQueue(&mq->queueReceive);
        mq->msgArray = msgArray;
        mq->msgCount = msgCount;
        mq->firstIndex = 0;
        mq->usedCount = 0;
    }

    BOOL OSSendMessage(OSMessageQueue* mq, OSMessage msg, s32 flags) {
        BOOL enabled;
        s32 lastIndex;

        enabled = OSDisableInterrupts();

        while (mq->msgCount <= mq->usedCount) {
            if (!(flags & OS_MESSAGE_BLOCK)) {
                OSRestoreInterrupts(enabled);
                return FALSE;
            }
            else {
                OSSleepThread(&mq->queueSend);
            }
        }

        lastIndex = (mq->firstIndex + mq->usedCount) % mq->msgCount;
        mq->msgArray[lastIndex] = msg;
        mq->usedCount++;
        OSWakeupThread(&mq->queueReceive);
        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    BOOL OSReceiveMessage(OSMessageQueue* mq, OSMessage* msg, s32 flags) {
        BOOL enabled = OSDisableInterrupts();

        while (mq->usedCount == 0) {
            if (!(flags & OS_MESSAGE_BLOCK)) {
                OSRestoreInterrupts(enabled);
                return FALSE;
            }
            else {
                OSSleepThread(&mq->queueReceive);
            }
        }

        if (msg != NULL) {
            *msg = mq->msgArray[mq->firstIndex];
        }

        mq->firstIndex = (mq->firstIndex + 1) % mq->msgCount;
        mq->usedCount--;

        OSWakeupThread(&mq->queueSend);
        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    BOOL OSJamMessage(OSMessageQueue* mq, OSMessage msg, s32 flags) {
        BOOL enabled = OSDisableInterrupts();

        while (mq->msgCount <= mq->usedCount) {
            if (!(flags & OS_MESSAGE_BLOCK)) {
                OSRestoreInterrupts(enabled);
                return FALSE;
            }
            else {
                OSSleepThread(&mq->queueSend);
            }
        }

        mq->firstIndex = (mq->firstIndex + mq->msgCount - 1) % mq->msgCount;
        mq->msgArray[mq->firstIndex] = msg;
        mq->usedCount++;

        OSWakeupThread(&mq->queueReceive);
        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    void PPCHalt(void) {UNIMPLEMENTED_FUNCTION}
    u32 PPCMfmsr(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void PPCMtmsr(u32) {UNIMPLEMENTED_FUNCTION}
    void PPCSync() {UNIMPLEMENTED_FUNCTION}

    void C_MTXCopy(const Mtx, Mtx) {UNIMPLEMENTED_FUNCTION}
    void C_MTXLightOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 scaleS, f32 scaleT, f32 transS, f32 transT) {UNIMPLEMENTED_FUNCTION}
    void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT) {UNIMPLEMENTED_FUNCTION}
    void C_MTXOrtho(Mtx44, f32, f32, f32, f32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void C_QUATMtx(Quaternion* r, const Mtx m) {UNIMPLEMENTED_FUNCTION}
    void C_QUATSlerp(const Quaternion* p, const Quaternion* q, Quaternion* r, f32 t) {UNIMPLEMENTED_FUNCTION}
    f32 C_VECMag(const Vec*) {UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    void PSMTX44Copy(const Mtx44 m, Mtx44 dst) {UNIMPLEMENTED_FUNCTION}
    void PSMTX44Identity(Mtx44 m) {UNIMPLEMENTED_FUNCTION}
    void PSMTXConcat(const Mtx, const Mtx, Mtx) {UNIMPLEMENTED_FUNCTION}
    void PSMTXCopy(const Mtx, Mtx) {UNIMPLEMENTED_FUNCTION}
    void PSMTXIdentity(Mtx m) {
        m[0][0] = 1;
        m[0][1] = 0;
        m[0][2] = 0;
        m[0][3] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
        m[1][2] = 0;
        m[1][3] = 0;
        m[2][0] = 0;
        m[2][1] = 0;
        m[2][2] = 1;
        m[2][3] = 0;
    }
    u32 PSMTXInverse(const Mtx, Mtx) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void PSMTXMultVec(const Mtx, const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}
    void PSMTXMultVecArraySR(const Mtx, const Vec*, Vec*, u32) {UNIMPLEMENTED_FUNCTION}
    void PSMTXMultVecSR(const Mtx, const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}
    void PSMTXQuat(Mtx dst, const Quaternion* quat) {UNIMPLEMENTED_FUNCTION}
    void PSMTXRotAxisRad(Mtx dst, const Vec*, f32) {UNIMPLEMENTED_FUNCTION}
    void PSMTXRotTrig(Mtx, char, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT) {UNIMPLEMENTED_FUNCTION}
    void PSMTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT) {UNIMPLEMENTED_FUNCTION}
    void PSMTXScaleApply(const Mtx, Mtx, f32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    void PSMTXScale(Mtx, f32, f32, f32) {UNIMPLEMENTED_FUNCTION}
    f32 PSQUATDotProduct(const Quaternion*, const Quaternion*) {UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    void PSQUATMultiply(const Quaternion*, const Quaternion*, Quaternion*) {UNIMPLEMENTED_FUNCTION}
    void PSVECAdd(const Vec*, const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}
    void PSVECCrossProduct(const Vec*, const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}
    f32 PSVECDistance(const Vec*, const Vec*) {UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    f32 PSVECDotProduct(const Vec*, const Vec*) {UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    f32 PSVECMag(const Vec*) {UNIMPLEMENTED_FUNCTION_RET(0.0f)}
    void PSVECNormalize(const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}
    void PSVECScale(const Vec*, Vec*, f32) {UNIMPLEMENTED_FUNCTION}
    void PSVECSubtract(const Vec*, const Vec*, Vec*) {UNIMPLEMENTED_FUNCTION}

    void RFLDrawOpa(const RFLCharModel* model) {UNIMPLEMENTED_FUNCTION}
    void RFLDrawOpaCore(const RFLCharModel* model, const RFLDrawCoreSetting* setting) {UNIMPLEMENTED_FUNCTION}
    void RFLDrawXlu(const RFLCharModel* model) {UNIMPLEMENTED_FUNCTION}
    void RFLDrawXluCore(const RFLCharModel* model, const RFLDrawCoreSetting* setting) {UNIMPLEMENTED_FUNCTION}
    void RFLExit(void) {UNIMPLEMENTED_FUNCTION} 
    RFLErrcode RFLGetAdditionalInfo(RFLAdditionalInfo* info, RFLDataSource source, struct RFLMiddleDB* db,
                                    u16 index) {UNIMPLEMENTED_FUNCTION_RET(RFLErrcode_Success)} 
    RFLErrcode RFLGetAsyncStatus(void) {UNIMPLEMENTED_FUNCTION_RET(RFLErrcode_Success)} 
    s32 RFLGetLastReason(void) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    u32 RFLGetModelBufferSize(RFLResolution res, u32 exprFlags) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    u32 RFLGetWorkSize(BOOL deluxeTex) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    RFLErrcode RFLInitCharModel(RFLCharModel* model, RFLDataSource src, struct RFLMiddleDB* db, u16 id, void* work, RFLResolution res,
                        u32 exprFlags) {UNIMPLEMENTED_FUNCTION_RET(RFLErrcode_Success)} 
    RFLErrcode RFLInitResAsync(void* workBuffer, void* resBuffer, u32 resSize, BOOL deluxeTex) {UNIMPLEMENTED_FUNCTION_RET(RFLErrcode_Success)} 
    BOOL RFLIsAvailableOfficialData(u16 index) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void RFLLoadMaterialSetting(const RFLDrawCoreSetting* setting) {UNIMPLEMENTED_FUNCTION}
    void RFLLoadVertexSetting(const RFLDrawCoreSetting* setting) {UNIMPLEMENTED_FUNCTION} 
    RFLErrcode RFLMakeIcon(void* buf, RFLDataSource source, RFLMiddleDB* middleDB, u16 index, RFLExpression expression, const RFLIconSetting* setting) {UNIMPLEMENTED_FUNCTION_RET(RFLErrcode_Success)} 
    BOOL RFLSearchOfficialData(const RFLCreateID* id, u16* index) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void RFLSetExpression(RFLCharModel* model, RFLExpression expr) {UNIMPLEMENTED_FUNCTION}
    void RFLSetMtx(RFLCharModel* model, const Mtx mvMtx) {UNIMPLEMENTED_FUNCTION}

    // NO-OP, used for Home Button Menu only
    void* RSOFindExportSymbolAddr(const RSOObjectHeader*, const char*) {UNIMPLEMENTED_FUNCTION_RET(nullptr)}
    int RSOGetJumpCodeSize(const RSOObjectHeader*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    BOOL RSOIsImportSymbolResolvedAll(const RSOObjectHeader*) {UNIMPLEMENTED_FUNCTION_RET(false)}
    int RSOLinkJump(RSOObjectHeader*, const RSOObjectHeader*, void*) {UNIMPLEMENTED_FUNCTION_RET(0)} 
    BOOL RSOLinkList(void*, void*) {UNIMPLEMENTED_FUNCTION_RET(false)}
    BOOL RSOListInit(void*) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void RSOMakeJumpCode(const RSOObjectHeader*, void*) {UNIMPLEMENTED_FUNCTION}

    u8 SCGetAspectRatio(void) {return SC_ASPECT_RATIO_16x9;}
    u8 SCGetEuRgb60Mode(void) {return SC_EURGB60_MODE_ON;}
    u8 SCGetLanguage(void) {return SC_LANG_ENGLISH;}
    u8 SCGetProgressiveMode(void) {return SC_PROGRESSIVE_MODE_ON;}
    u8 SCGetSoundMode(void) {return SC_SOUND_MODE_DEFAULT;}

    s32 THPVideoDecode(void* file, void* tileY, void* tileU, void* tileV, void* work) {UNIMPLEMENTED_FUNCTION_RET(0)} u32
        THPAudioDecode(s16*, u8*, s32) {UNIMPLEMENTED_FUNCTION_RET(0)} BOOL THPInit(void) {UNIMPLEMENTED_FUNCTION_RET(false)}

    void TPLBind(TPLPalettePtr) {UNIMPLEMENTED_FUNCTION} TPLDescriptorPtr TPLGet(TPLPalettePtr, u32) {UNIMPLEMENTED_FUNCTION_RET(nullptr)}

    void VFInitEx(void* i_heap_start_address_p, u32 i_size) {UNIMPLEMENTED_FUNCTION}

    void VIConfigure(const GXRenderModeObj*) {UNIMPLEMENTED_FUNCTION}
    BOOL VIEnableDimming(BOOL) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void VIFlush() {UNIMPLEMENTED_FUNCTION}
    void* VIGetCurrentFrameBuffer(void) {UNIMPLEMENTED_FUNCTION_RET(nullptr)}
    u32 VIGetDTVStatus(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    u32 VIGetDimmingCount(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void* VIGetNextFrameBuffer(void) {UNIMPLEMENTED_FUNCTION_RET(nullptr)}
    u32 VIGetRetraceCount(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    u32 VIGetTvFormat(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void VIInit(void) {UNIMPLEMENTED_FUNCTION}
    void VISetBlack(BOOL){UNIMPLEMENTED_FUNCTION}
    void VISetNextFrameBuffer(void*){UNIMPLEMENTED_FUNCTION}
    VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback cb) {UNIMPLEMENTED_FUNCTION_RET(cb)}
    VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback cb) {UNIMPLEMENTED_FUNCTION_RET(cb)}
    void VISetTrapFilter(VIBool) {UNIMPLEMENTED_FUNCTION}
    void VIWaitForRetrace() {UNIMPLEMENTED_FUNCTION}

    s32 WENCGetEncodeData(WENCInfo*, u32, const s16*, s32, u8*) {UNIMPLEMENTED_FUNCTION_RET(0)}

    BOOL WPADCanSendStreamData(s32) {UNIMPLEMENTED_FUNCTION_RET(false)}
    void WPADControlMotor(s32, u32) {UNIMPLEMENTED_FUNCTION} s32 WPADControlSpeaker(s32, u32, WPADCallback) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void WPADDisconnect(s32) {UNIMPLEMENTED_FUNCTION} 
    s32 WPADGetInfoAsync(s32, WPADInfo*, WPADCallback) {UNIMPLEMENTED_FUNCTION_RET(0)}
    u8 WPADGetSensorBarPosition(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    u8 WPADGetSpeakerVolume(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    u32 WPADGetWorkMemorySize(void) {UNIMPLEMENTED_FUNCTION_RET(0)}
    BOOL WPADIsSpeakerEnabled(s32) {UNIMPLEMENTED_FUNCTION_RET(false)}
    s32 WPADProbe(s32 chan, u32* type) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void WPADRegisterAlSetZMlocator(WPADAlloc, WPADFree) {UNIMPLEMENTED_FUNCTION} 
    s32 WPADSendStreamData(s32, void*, u16) {UNIMPLEMENTED_FUNCTION_RET(0)}
    void WPADSetAutoSleepTime(u8) {UNIMPLEMENTED_FUNCTION} 
    WPADConnectCallback WPADSetConnectCallback(s32, WPADConnectCallback callback) {UNIMPLEMENTED_FUNCTION_RET(callback)}
    WPADExtensionCallback WPADSetExtensionCallback(s32, WPADExtensionCallback callback) {UNIMPLEMENTED_FUNCTION_RET(callback)}
    void WPADRegisterAllocator(WPADAlloc, WPADFree) {UNIMPLEMENTED_FUNCTION}


    void __DSP_boot_task(DSPTaskInfo*) {UNIMPLEMENTED_FUNCTION}
    void __DSP_exec_task(DSPTaskInfo*, DSPTaskInfo*) {UNIMPLEMENTED_FUNCTION}
    void __DSP_remove_task(DSPTaskInfo*) {UNIMPLEMENTED_FUNCTION}

    u64 __cvt_dbl_usll(double a) {
        return *((u64*)&a);
    }
}
