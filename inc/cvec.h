#include "platform.h"

#if (defined(CVEC_AVX) || defined(CVEC_AVX2)) && defined(CVEC256)
    #include "arch/x86/cvec_x86_256b.h"
    #ifdef CVEC_AVX2
        #include "arch/x86/impl/cvec_avx2_impl.h"
    #endif
    #include "arch/x86/impl/cvec_avx_impl.h"
#endif

#if (defined(CVEC_SSE4_2) || defined(CVEC_SSE4_1) || defined(CVEC_SSSE3) || defined(CVEC_SSE3) || defined(CVEC_SSE2) || defined(CVEC_SSE)) && defined(CVEC128)
    // #include "arch/x86_64/cvec_x86_128b.h"
    #ifdef CVEC_SSE4_2
    // #include "arch/x86_64/cvec_sse4_2.h"
    #endif
    #ifdef CVEC_SSE4_1
    // #include "arch/x86_64/cvec_sse4_1.h"
    #endif
    #ifdef CVEC_SSSE3
    // #include "arch/x86_64/cvec_ssse3.h"
    #endif
    #ifdef CVEC_SSE3
    // #include "arch/x86_64/cvec_sse3.h"
    #endif
    #ifdef CVEC_SSE2
    // #include "arch/x86_64/cvec_sse2.h"
    #endif
    #ifdef CVEC_SSE
    // #include "arch/x86_64/cvec_sse.h"
    #endif
#endif

#if (defined(CVEC_NEON)) && defined(CVEC128)
    #include "arch/arm/cvec_arm_128b.h"
    #ifdef CVEC_AARCH64_NEON
        #include "arch/arm/impl/cvec_aarch64_armv8_neon_impl.h"
    #endif
    #ifdef CVEC_AARCH32_NEON
        #include "arch/arm/impl/cvec_aarch32_armv7_neon_impl.h"
    #endif
#endif
