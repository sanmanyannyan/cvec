#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif


#if defined(__x86_64__) || defined(_M_AMD64)
// AMD64
#define X86_64
#elif defined(__i386) || defined(_M_IX86)
// intel x86
#define X86
#endif

#if defined(__aarch64__)
// aarch64
#define AARCH64
#elif defined(__arm__)
// aarch32
#define AARCH32
#endif

#define NOT_SUPPORTED_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
#define NOT_SUPPORTED_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
#if defined(X86_64) || defined(X86)
	#define SIMD_INSTRCUTION_NOT_SPECIFIED
    #ifdef __AVX2__
        #define CVEC_AVX2
        #define AVX2_FUNC_DECL(func_sign) func_sign
        #define AVX2_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif

    #else
        #define AVX2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define AVX2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__AVX__) || defined(CVEC_AVX2)
        #define CVEC_AVX
        #define AVX_FUNC_DECL(func_sign) func_sign
        #define AVX_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
	#else
        #define AVX_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define AVX_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSE4_2__) || defined(CVEC_AVX)
        #define CVEC_SSE4_2
        #define SSE4_2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE4_2_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
    #else
        #define SSE4_2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE4_2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSE4_1__) || defined(CVEC_SSE4_2)
        #define CVEC_SSE4_1
        #define SSE4_1_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE4_1_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
    #else
        #define SSE4_1_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE4_1_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSSE3__) || defined(CVEC_SSE4_1)
        #define CVEC_SSSE3
        #define SSSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSSE3_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
	#else
        #define SSSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSSE3_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSE3__) || defined(CVEC_SSSE3)
        #define CVEC_SSE3
        #define SSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE3_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
	#else
        #define SSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE3_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSE2__) || defined(CVEC_SSE3)
        #define CVEC_SSE2
        #define SSE2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE2_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
	#else
        #define SSE2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
    #if defined(__SSE__) || defined(CVEC_SSE2)
        #define CVEC_SSE
        #define SSE_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE_TYPE_DECL(alias, original) typedef original alias
		#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
		#undef SIMD_INSTRCUTION_NOT_SPECIFIED
		#endif
	#else
        #define SSE_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define SSE_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
	#ifdef SIMD_INSTRCUTION_NOT_SPECIFIED
	#error not specified SIMD instruction
	#endif
#endif

#if defined(AARCH32)
    #if defined(__ARM_NEON__)
        #define CVEC_NEON
        #if __ARM_ARCH >= 7
            #define CVEC_AARCH32_ARMV7_NEON
            #define AARCH32_ARMV7_NEON_FUNC_DECL(func_sign) func_sign
            #define AARCH32_ARMV7_NEON_TYPE_DECL(alias, original) typedef original alias
        #else
            #define AARCH32_ARMV7_NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
            #define AARCH32_ARMV7_NEON_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
        #endif
        #define AARCH64_ARMV8_NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define AARCH64_ARMV8_NEON_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
        #define AARCH64_ARMV8_2_NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
        #define AARCH64_ARMV8_2_NEON_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
    #endif
#elif defined(AARCH64)
    #if defined(__ARM_NEON__)
        #define CVEC_NEON
        #define CVEC_AARCH32_ARMV7_NEON
        #define AARCH32_ARMV7_NEON_FUNC_DECL(func_sign) func_sign
        #define AARCH32_ARMV7_NEON_TYPE_DECL(alias, original) typedef original alias
        #define CVEC_AARCH64_ARMV8_NEON
        #define AARCH64_ARMV8_NEON_FUNC_DECL(func_sign) func_sign
        #define AARCH64_ARMV8_NEON_TYPE_DECL(alias, original) typedef original alias
        #if defined(__ARM_ARCH_8_2A__)
            #define CVEC_AARCH64_ARMV8_2_NEON
            #define AARCH64_ARMV8_2_NEON_FUNC_DECL(func_sign) func_sign
            #define AARCH64_ARMV8_2_NEON_TYPE_DECL(alias, original) typedef original alias
        #else
            #define AARCH64_ARMV8_2_NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION(void)
            #define AARCH64_ARMV8_2_NEON_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION(void)
        #endif
    #endif
#endif

#if defined(__STDC_VERSION__)
    #define CVEC_FORCE_INLINE static inline
#else
    #if defined(_MSC_VER)
        #define CVEC_FORCE_INLINE __forceinline
     #elif defined(__GNUC__)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #elif defined(__clang__)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #elif defined(__INTEL_COMPILER)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #elif defined(__MINGW32__)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #elif defined(__MINGW32__)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #elif defined(__MINGW64__)
        #define CVEC_FORCE_INLINE __attribute__((always_inline))
    #else
        #error unrecognized
    #endif
#endif

void CVEC_VOID_FUNCTION(void){}
