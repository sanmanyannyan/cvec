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

#define NOT_SUPPORTED_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
#define NOT_SUPPORTED_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
#if defined(X86_64) || defined(X86)
    #ifdef __AVX2__
        #define CVEC_AVX2
        #define AVX2_FUNC_DECL(func_sign) func_sign
        #define AVX2_TYPE_DECL(alias, original) typedef original alias
    #else
        #define AVX2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define AVX2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __AVX__
        #define CVEC_AVX
        #define AVX_FUNC_DECL(func_sign) func_sign
        #define AVX_TYPE_DECL(alias, original) typedef original alias
    #else
        #define AVX_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define AVX_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSE4_2__
        #define CVEC_SSE4_2
        #define SSE4_2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE4_2_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSE4_2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE4_2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSE4_1__
        #define CVEC_SSE4_1
        #define SSE4_1_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE4_1_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSE4_1_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE4_1_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSSE3__
        #define CVEC_SSSE3
        #define SSSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSSE3_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSSE3_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSE3__
        #define CVEC_SSE3
        #define SSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE3_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSE3_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE3_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSE2__
        #define CVEC_SSE2
        #define SSE2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE2_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSE2_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE2_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
    #ifdef __SSE__
        #define CVEC_SSE
        #define SSE_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE_TYPE_DECL(alias, original) typedef original alias
    #else
        #define SSE_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define SSE_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
#elif defined(AARCH32) || defined(AARCH64)
    #ifdef __ARM_NEON__
        #define CVEC_NEON
        #define NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define NEON_TYPE_DECL(alias, original) typedef original alias
    #else
        #define NEON_FUNC_DECL(func_sign) void CVEC_VOID_FUNCTION()
        #define NEON_TYPE_DECL(alias, original) void CVEC_VOID_FUNCTION()
    #endif
#endif

//#if defined(_MSC_VER)
// Visual Studio
//#elif defined(__GNUC__)
// gcc
//#elif defined(__clang__)
// clang
//#elif defined(__INTEL_COMPILER)
// intel compiler
//#elif defined(__MINGW32__)
// MinGW 32
//#elif defined(__MINGW32__)
// MinGW-w64 32bit
//#elif defined(__MINGW64__)
// MinGW-w64 64bit
//#else
// unrecognized
//#enif

void CVEC_VOID_FUNCTION(){}
