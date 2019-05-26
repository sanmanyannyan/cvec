#ifndef CVEC_H
#define CVEC_H

#include "platform.h"

#if (defined(CVEC_AVX) || defined(CVEC_AVX2))
    #include "arch/x86/cvec_x86_256b.h"
    #ifdef CVEC_AVX2
        #include "arch/x86/impl/cvec_avx2_impl.h"
    #endif
    #include "arch/x86/impl/cvec_avx_impl.h"
#endif

#if (defined(CVEC_SSE) || defined(CVEC_SSE2) || defined(CVEC_SSE3) || defined(CVEC_SSSE3) || defined(CVEC_SSE4_1) || defined(CVEC_SSE4_2))
	#include "arch/x86/cvec_x86_128b.h"
	#ifdef CVEC_SSE4_2
		#include "arch/x86/impl/cvec_sse4_2_impl.h"
	#endif
	#ifdef CVEC_SSE4_1
		#include "arch/x86/impl/cvec_sse4_1_impl.h"
	#endif
	#ifdef CVEC_SSSE3
		#include "arch/x86/impl/cvec_ssse3_impl.h"
	#endif
	#ifdef CVEC_SSE3
		#include "arch/x86/impl/cvec_sse3_impl.h"
	#endif
	#ifdef CVEC_SSE2
		#include "arch/x86/impl/cvec_sse2_impl.h"
	#endif
	#include "arch/x86/impl/cvec_sse_impl.h"
#endif

#if (defined(CVEC_NEON))
    #include "arch/arm/cvec_arm_128b.h"
    #ifdef CVEC_AARCH64_NEON
        #include "arch/arm/impl/cvec_aarch64_armv8_neon_impl.h"
    #endif
    #ifdef CVEC_AARCH32_NEON
        #include "arch/arm/impl/cvec_aarch32_armv7_neon_impl.h"
    #endif
#endif

#endif
