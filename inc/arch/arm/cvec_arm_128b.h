#include <arm_neon.h>
#include <stdint.h>

#define CVEC_VECTOR_SIZE ((size_t)(16))
#define MEMORY_ALIGNMENT 16u

AARCH32_ARMV7_NEON_TYPE_DECL(vi8 ,   int8x16_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vu8 ,  uint8x16_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vi16,   int16x8_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vu16,  uint16x8_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vi32,   int32x4_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vu32,  uint32x4_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vi64,   int64x2_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vu64,  uint64x2_t);
AARCH64_ARMV8_2_NEON_TYPE_DECL(vf16, float16x8_t);
AARCH32_ARMV7_NEON_TYPE_DECL(vf32, float32x4_t);
AARCH64_ARMV8_NEON_TYPE_DECL(vf64, float64x2_t);

#define  VI8_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(  int8_t))
#define  VU8_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( uint8_t))
#define VI16_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int16_t))
#define VU16_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint16_t))
#define VI32_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int32_t))
#define VU32_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint32_t))
#define VI64_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int64_t))
#define VU64_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint64_t))
#define VF16_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(  __fp16))
#define VF32_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(   float))
#define VF64_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(  double))

/// aligned_malloc / free
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE void* amalloc(size_t size, size_t alignement));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE void  afree(void* addr));

/// load / store instructions
// setzero
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE  vi8 setzero_vi8 ());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE  vu8 setzero_vu8 ());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi16 setzero_vi16());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu16 setzero_vu16());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi32 setzero_vi32());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu32 setzero_vu32());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi64 setzero_vi64());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu64 setzero_vu64());
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 setzero_vf16());
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf32 setzero_vf32());
 AARCH64_ARMV8_NEON_FUNC_DECL(CVEC_FORCE_INLINE v64 setzero_vf64());
// set1
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE  vi8 set1_vi8 (const   int8_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE  vu8 set1_vu8 (const  uint8_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 set1_vi16(const  int16_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 set1_vu16(const uint16_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 set1_vi32(const  int32_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 set1_vu32(const uint32_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 set1_vi64(const  int64_t scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 set1_vu64(const uint64_t scalar));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 set1_vf16(const   __fp16 scalar));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 set1_vf32(const    float scalar));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 set1_vf64(const   double scalar));
// aligned load
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  load_vi8( const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  load_vu8( const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 load_vi16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 load_vu16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 load_vi32(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 load_vu32(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 load_vi64(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 load_vu64(const void* addr));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 load_vf16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 load_vf32(const void* addr));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 load_vf64(const void* addr));
// unaligned load
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  loadu_vi8( const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  loadu_vu8( const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 loadu_vi16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 loadu_vu16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 loadu_vi32(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 loadu_vu32(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 loadu_vi64(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 loadu_vu64(const void* addr));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 loadu_vf16(const void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 loadu_vf32(const void* addr));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 loadu_vf64(const void* addr));
// aligned store
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vi8( const vi8  v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vu8( const vu8  v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vi16(const vi16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vu16(const vu16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vi32(const vi32 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vu32(const vu32 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vi64(const vi64 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vu64(const vu64 v, void* addr));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE void store_vf16(const vf16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vf32(const vf32 v, void* addr));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void store_vf64(const vf64 v, void* addr));
// unaligned store
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vi8( const vi8  v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vu8( const vu8  v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vi16(const vi16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vu16(const vu16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vi32(const vi32 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vu32(const vu32 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vi64(const vi64 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vu64(const vu64 v, void* addr));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vf16(const vf16 v, void* addr));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vf32(const vf32 v, void* addr));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE void storeu_vf64(const vf64 v, void* addr));


/// arithmetic instructions
// add
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  add_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  add_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 add_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 add_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 add_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 add_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 add_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 add_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 add_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 add_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 add_vf64(const vf64 lhs, const vf64 rhs));
// sub
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  sub_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  sub_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 sub_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 sub_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 sub_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 sub_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 sub_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 sub_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 sub_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 sub_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 sub_vf64(const vf64 lhs, const vf64 rhs));
// mul
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  mul_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  mul_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 mul_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 mul_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 mul_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 mul_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 mul_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 mul_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 mul_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 mul_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 mul_vf64(const vf64 lhs, const vf64 rhs));
// div
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vi8  div_vi8( const vi8  lhs, const vi8  rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vu8  div_vu8( const vu8  lhs, const vu8  rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vi16 div_vi16(const vi16 lhs, const vi16 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vu16 div_vu16(const vu16 lhs, const vu16 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vi32 div_vi32(const vi32 lhs, const vi32 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vu32 div_vu32(const vu32 lhs, const vu32 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vi64 div_vi64(const vi64 lhs, const vi64 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vu64 div_vu64(const vu64 lhs, const vu64 rhs));
 NOT_SUPPORTED_FUNC_DECL(     CVEC_FORCE_INLINE vf16 div_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf32 div_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf64 div_vf64(const vf64 lhs, const vf64 rhs));
// max
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  max_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  max_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 max_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 max_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 max_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 max_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 max_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 max_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 max_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 max_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 max_vf64(const vf64 lhs, const vf64 rhs));
// min
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  min_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  min_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 min_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 min_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 min_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 min_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 min_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 min_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 min_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 min_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 min_vf64(const vf64 lhs, const vf64 rhs));

/// elementary math functions
// reciprocal estimation
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 rcp_vf16(const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 rcp_vf32(const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 rcp_vf64(const vf64 rhs));

/// bit manipulation
// or
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  or_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  or_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 or_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 or_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 or_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 or_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 or_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 or_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 or_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 or_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 or_vf64(const vf64 lhs, const vf64 rhs));
// and
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi8  and_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu8  and_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi16 and_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu16 and_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi32 and_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu32 and_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vi64 and_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vu64 and_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 and_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf32 and_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(  CVEC_FORCE_INLINE vf64 and_vf64(const vf64 lhs, const vf64 rhs));
// not
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi8  not_vi8( const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu8  not_vu8( const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi16 not_vi16(const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu16 not_vu16(const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi32 not_vi32(const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu32 not_vu32(const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi64 not_vi64(const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu64 not_vu64(const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 not_vf16(const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf32 not_vf32(const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf64 not_vf64(const vf64 rhs));
// xor
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi8  xor_vi8( const vi8  lhs, const vi8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu8  xor_vu8( const vu8  lhs, const vu8  rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi16 xor_vi16(const vi16 lhs, const vi16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu16 xor_vu16(const vu16 lhs, const vu16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi32 xor_vi32(const vi32 lhs, const vi32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu32 xor_vu32(const vu32 lhs, const vu32 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vi64 xor_vi64(const vi64 lhs, const vi64 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vu64 xor_vu64(const vu64 lhs, const vu64 rhs));
 AARCH64_ARMV8_2_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf16 xor_vf16(const vf16 lhs, const vf16 rhs));
 AARCH32_ARMV7_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf32 xor_vf32(const vf32 lhs, const vf32 rhs));
 AARCH64_ARMV8_NEON_FUNC_DECL(CVEC_FORCE_INLINE vf64 xor_vf64(const vf64 lhs, const vf64 rhs));
