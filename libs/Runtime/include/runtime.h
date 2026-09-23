#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long u32;
typedef unsigned long long u64;

#ifdef __MWERKS
#define ASM asm
#else
#define ASM
#endif

u32 __cvt_fp2unsigned(double);
ASM void __div2u(void);
ASM void __div2i(void);
ASM void __mod2u(void);
ASM void __mod2i(void);
ASM void __shl2i(void);
ASM void __shr2u(void);
u64 __cvt_dbl_usll(double);
ASM void __cvt_dbl_ull(void);

#ifdef __cplusplus
}
#endif
