#pragma once

#include "JSystem/JGeometry/TVec.hpp"
#include "JSystem/JGeometry/TQuat.hpp"
#include <cmath>

namespace JGeometry {
    template<typename T>
    struct SMatrix34C {
    public:
        void set(const MtxPtr);
        void set(const SMatrix34C<T> &rSrc);
        void set(T rxx, T ryx, T rzx, T tx, T rxy, T ryy, T rzy, T ty, T rxz, T ryz, T rzz, T tz);

        void scale(T);

        inline void setInline(const SMatrix34C<T> &rSrc) {
            register const SMatrix34C<T> *pSrc = &rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
        }

        inline void setInline(const MtxPtr rSrc) {
            register const MtxPtr pSrc = rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
        }

        inline void setInline_2(MtxPtr rSrc) {
            register MtxPtr pSrc = rSrc;
            register SMatrix34C<T> *pDest = this;
            register f32 rzztz;
            register f32 rxzyz;
            register f32 rzyty;
            register f32 rxyyy;
            register f32 rzxtx;
            register f32 rxxyx;

            __asm {
                psq_l     rxxyx, 0(pSrc), 0, 0
                psq_l     rzxtx, 8(pSrc), 0, 0
                psq_l     rxyyy, 0x10(pSrc), 0, 0
                psq_st    rxxyx, 0(pDest), 0, 0
                psq_l     rzyty, 0x18(pSrc), 0, 0
                psq_st    rzxtx, 8(pDest), 0, 0
                psq_l     rxzyz, 0x20(pSrc), 0, 0
                psq_st    rxyyy, 0x10(pDest), 0, 0
                psq_l     rzztz, 0x28(pSrc), 0, 0
                psq_st    rzyty, 0x18(pDest), 0, 0
                psq_st    rxzyz, 0x20(pDest), 0, 0
                psq_st    rzztz, 0x28(pDest), 0, 0
            };
        }

        inline Mtx* toMtx() {
            return (Mtx*)mMtx;
        }

        inline const Mtx* toCMtx() const {
            return (const Mtx*)mMtx;
        }

        inline MtxPtr toMtxPtr() {
            return (MtxPtr)mMtx;
        }

        T mMtx[3][4];
        typedef T type;
    };

    template<typename T>
    struct TMatrix34 : public T {
    public:
        void identity();
        void concat(const T &rSrcA, const T &rSrcB);
        void concat(const T &rSrc);
        void invert(const TMatrix34<T> &rDest);

        void mult(const TVec3f &rSrc, TVec3f &rDest) const;

        void multTranspose(const TVec3f &a1, const TVec3f &a2) const;
        typedef T::type type;
    };
    template<class T>
    struct TRotation3 : public T {
    public:
    typedef T::type type;
        void identity33();

        void getXDir(TVec3f &rDest) const NO_INLINE {
            rDest.set<f32>(mMtx[0][0], mMtx[1][0], mMtx[2][0]);
        };

        void getYDir(TVec3f &rDest) const NO_INLINE {
            rDest.set<f32>(mMtx[0][1], mMtx[1][1], mMtx[2][1]);
        };

        void getZDir(TVec3f &rDest) const NO_INLINE {
            rDest.set<f32>(mMtx[0][2], mMtx[1][2], mMtx[2][2]);
        };

        void getXYZDir(TVec3f &rDestX, TVec3f &rDestY, TVec3f &rDestZ) const;
        void setXDir(const TVec3f &rSrc);
        void setXDir(f32 x, f32 y, f32 z);
        void setYDir(const TVec3f &rSrc);
        void setYDir(f32 x, f32 y, f32 z);
        void setZDir(const TVec3f &rSrc);
        void setZDir(f32 x, f32 y, f32 z);
        void setXYZDir(const TVec3f &rSrcX, const TVec3f &rSrcY, const TVec3f &rSrcZ);

        void getEuler(TVec3f &rDest) const;
        void getEulerXYZ(TVec3f &rDest) const;
        void setEulerY(f32 val);
        void setEulerZ(f32 val);

        void getQuat(TQuat4f &rDest) const;
        void setQuat(const TQuat4f &rSrc);

        void getScale(TVec3f &rDest) const;
        void setScale(const TVec3f &rSrc);
        void setRotate(const TVec3f &, f32);
        void INLINE_FUNC_DECL(setRotate, const TVec3f &mLocalDirection, f32 fr1e) {
            TVec3f stack_8;
            stack_8.set(mLocalDirection);
            PSVECMag(stack_8.toCVec());
            PSVECNormalize(stack_8.toCVec(), stack_8.toVec());
            f32 fr1ey = sin(fr1e), fr1ex = cos(fr1e);
            f32 x, y, z;
            x = stack_8.x;
            y = stack_8.y;
            z = stack_8.z;
            f32 xx = x * x;
            f32 yx = y * y;
            f32 zz = z * z;
            mMtx[0][0] = fr1ex + (1.0f - fr1ex) * (x * x);
            mMtx[0][1] = (1.0f - fr1ex) * x * y - fr1ey * z;
            mMtx[0][2] = (1.0f - fr1ex) * x * z + fr1ey * y;
            mMtx[1][0] = (1.0f - fr1ex) * x * y + fr1ey * z;
            mMtx[1][1] = fr1ex + (1.0f - fr1ex) * (y * y);
            mMtx[1][2] = (1.0f - fr1ex) * y * z - fr1ey * x;
            mMtx[2][0] = (1.0f - fr1ex) * x * z - fr1ey * y;
            mMtx[2][1] = (1.0f - fr1ex) * y * z + fr1ey * x;
            mMtx[2][2] = fr1ex + (1.0f - fr1ex) * (z * z);
        }

        void setRotateInline2(const TVec3f &mLocalDirection, f32 fr1e) {
            // The only difference from the first setRotate is that we use setInline instead of set
            TVec3f stack_8;
            stack_8.setInline(mLocalDirection);
            PSVECMag(stack_8.toCVec());
            PSVECNormalize(stack_8.toCVec(), stack_8.toVec());
            f32 fr1ey = sin(fr1e), fr1ex = cos(fr1e);
            x = stack_8.x;
            y = stack_8.y;
            z = stack_8.z;
            f32 xx = x * x;
            f32 yx = y * y;
            f32 zz = z * z;
            mMtx[0][0] = fr1ex + (1.0f - fr1ex) * (x * x);
            mMtx[0][1] = (1.0f - fr1ex) * x * y - fr1ey * z;
            mMtx[0][2] = (1.0f - fr1ex) * x * z + fr1ey * y;
            mMtx[1][0] = (1.0f - fr1ex) * x * y + fr1ey * z;
            mMtx[1][1] = fr1ex + (1.0f - fr1ex) * (y * y);
            mMtx[1][2] = (1.0f - fr1ex) * y * z - fr1ey * x;
            mMtx[2][0] = (1.0f - fr1ex) * x * z - fr1ey * y;
            mMtx[2][1] = (1.0f - fr1ex) * y * z + fr1ey * x;
            mMtx[2][2] = fr1ex + (1.0f - fr1ex) * (z * z);
        }

        void mult33(TVec3f &) const;
        void mult33(const TVec3f &rDst, TVec3f &rSrc) const;

        inline void getXDirInline(TVec3f &rDest) const {
            f32 z = mMtx[2][0];
            f32 y = mMtx[1][0];
            f32 x = mMtx[0][0];
            rDest.set(x, y, z);
        }

        inline void mult33Inline(const TVec3f &rSrc, TVec3f &rDst) const {
            f32 a32, a22, a12, a11, a21, vx, a31, vy, a23, a33, a13;
            a32 = mMtx[2][1];
            a22 = mMtx[1][1];
            a12 = mMtx[0][1];
            a31 = mMtx[2][0];
            a21 = mMtx[1][0];
            a11 = mMtx[0][0];
            a33 = mMtx[2][2];
            a13 = mMtx[0][2];
            a23 = mMtx[1][2];
            f32 x, y;
            vx = rSrc.x;
            vy = rSrc.y;
            x = (vx * a11 + vy * a12);
            rDst.set(rSrc.z * a13 + (vx * a11 + vy * a12), rSrc.z * a23 + (vx * a21 + vy * a22), rSrc.z * a33 + (rSrc.x * a31 + rSrc.y * a32));
        }
    };

    inline f32 dot(f32 x, f32 y, f32 z, f32 x2, f32 y2, f32 z2) {
        return x2 * x + y2 * y + z2 * z;
    }

inline f32 yy(f32 y) {
    return y * y;
}
inline f32 g(f32 x) {
    return cos(x);
}
    
        inline f32 helper(const Vec &rSrc, const Vec &mtx) {
            return rSrc.y * mtx.y + rSrc.x  * mtx.x + rSrc.z * mtx.z;
        }

    template<class T>
    struct TPosition3 : public TRotation3<T> {
    public:
        void getTrans(TVec3f &rDest) const;
        void setTrans(const TVec3f &rSrc);
        void setTrans(f32 x, f32 y, f32 z);
        void zeroTrans();

        void makeRotate(const TVec3f &, f32);
        void makeQuat(const TQuat4f &rSrc);
        void setPositionFromLookAt(const TPosition3<T> &rLookAt);
        void setQT(const TQuat4f &rSrcQuat, const TVec3f &rSrcTrans);

        inline void getTransInline(TVec3f &rDest) const {
            f32 z = mMtx[2][3];
            f32 y = mMtx[1][3];
            f32 x = mMtx[0][3];
            rDest.set(x, y, z);
        }
    };
};

typedef JGeometry::SMatrix34C<f32> TSMtxf;
typedef JGeometry::TMatrix34<TSMtxf> TMtx34f;
typedef JGeometry::TRotation3<TMtx34f> TRot3f;
typedef JGeometry::TPosition3<TMtx34f> TPos3f;
