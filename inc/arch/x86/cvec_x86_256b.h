#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

#define CVEC256_VECTOR_SIZE ((size_t)(32))
#define CVEC256_MEMORY_ALIGNMENT 32u

AVX_TYPE_DECL(vi8x32 , __m256i);
AVX_TYPE_DECL(vu8x32 , __m256i);
AVX_TYPE_DECL(vi16x16, __m256i);
AVX_TYPE_DECL(vu16x16, __m256i);
AVX_TYPE_DECL(vi32x8 , __m256i);
AVX_TYPE_DECL(vu32x8 , __m256i);
AVX_TYPE_DECL(vi64x4 , __m256i);
AVX_TYPE_DECL(vu64x4 , __m256i);
AVX_TYPE_DECL(vf32x8 , __m256 );
AVX_TYPE_DECL(vf64x4 , __m256d);

#define VI8X32_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof(  int8_t))
#define VU8X32_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof( uint8_t))
#define VI16X16_NUM_ELEMENT (CVEC256_VECTOR_SIZE / sizeof( int16_t))
#define VU16X16_NUM_ELEMENT (CVEC256_VECTOR_SIZE / sizeof(uint16_t))
#define VI32X8_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof( int32_t))
#define VU32X8_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof(uint32_t))
#define VI64X4_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof( int64_t))
#define VU64X4_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof(uint64_t))
#define VF32X8_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof(   float))
#define VF64X4_NUM_ELEMENT  (CVEC256_VECTOR_SIZE / sizeof(  double))

/// load / store instructions
// setzero
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  setzero_vi8x32 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  setzero_vu8x32 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 setzero_vi16x16(void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 setzero_vu16x16(void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  setzero_vi32x8 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  setzero_vu32x8 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  setzero_vi64x4 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  setzero_vu64x4 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  setzero_vf32x8 (void));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  setzero_vf64x4 (void));
// set1
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  set1_vi8x32 (const   int8_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  set1_vu8x32 (const  uint8_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 set1_vi16x16(const  int16_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 set1_vu16x16(const uint16_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  set1_vi32x8 (const  int32_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  set1_vu32x8 (const uint32_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  set1_vi64x4 (const  int64_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  set1_vu64x4 (const uint64_t scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  set1_vf32x8 (const    float scalar));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  set1_vf64x4 (const   double scalar));
// aligned load
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  load_vi8x32 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  load_vu8x32 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 load_vi16x16(void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 load_vu16x16(void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  load_vi32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  load_vu32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  load_vi64x4 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  load_vu64x4 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  load_vf32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  load_vf64x4 (void* addr));
// unaligned load
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  loadu_vi8x32 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  loadu_vu8x32 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 loadu_vi16x16(void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 loadu_vu16x16(void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  loadu_vi32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  loadu_vu32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  loadu_vi64x4 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  loadu_vu64x4 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  loadu_vf32x8 (void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  loadu_vf64x4 (void* addr));
// aligned store
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vi8x32 (const vi8x32  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vu8x32 (const vu8x32  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vi16x16(const vi16x16 v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vu16x16(const vu16x16 v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vi32x8 (const vi32x8  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vu32x8 (const vu32x8  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vi64x4 (const vi64x4  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vu64x4 (const vu64x4  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vf32x8 (const vf32x8  v, void* addr));
		  AVX_FUNC_DECL(CVEC_FORCE_INLINE void store_vf64x4 (const vf64x4  v, void* addr));
// unaligned store
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi8x32 (const vi8x32  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu8x32 (const vu8x32  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi16x16(const vi16x16 v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu16x16(const vu16x16 v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi32x8 (const vi32x8  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu32x8 (const vu32x8  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi64x4 (const vi64x4  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu64x4 (const vu64x4  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vf32x8 (const vf32x8  v, void* addr));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vf64x4 (const vf64x4  v, void* addr));
 // extract scalar
          AVX_FUNC_DECL(CVEC_FORCE_INLINE   int8_t at_vi8x32 (const vi8x32  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE  uint8_t at_vu8x32 (const vu8x32  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE  int16_t at_vi16x16(const vi16x16 v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE uint16_t at_vu16x16(const vu16x16 v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE  int32_t at_vi32x8 (const vi32x8  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE uint32_t at_vu32x8 (const vu32x8  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE  int64_t at_vi64x4 (const vi64x4  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE uint64_t at_vu64x4 (const vu64x4  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE    float at_vf32x8 (const vf32x8  v, size_t lane));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE   double at_vf64x4 (const vf64x4  v, size_t lane));


/// arithmetic instructions
// add
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  add_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  add_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 add_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 add_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  add_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  add_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  add_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  add_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  add_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  add_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// sub
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  sub_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  sub_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 sub_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 sub_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  sub_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  sub_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  sub_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  sub_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  sub_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  sub_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// mul
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  mul_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  mul_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 mul_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 mul_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  mul_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  mul_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  mul_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  mul_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  mul_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  mul_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// div
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  div_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  div_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 div_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 div_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  div_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  div_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  div_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  div_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  div_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  div_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// max
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  max_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  max_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 max_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 max_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  max_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  max_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  max_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  max_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  max_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  max_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// min
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  min_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  min_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 min_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 min_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  min_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  min_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  min_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  min_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  min_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  min_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));

/// elementary math functions
// reciprocal estimation
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8 arcp_vf32x8(const vf32x8 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vf64x4 arcp_vf64x4(const vf64x4 rhs));

/// bit manipulation
// or
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  or_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  or_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 or_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 or_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  or_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  or_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  or_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  or_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  or_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  or_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// and
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  and_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  and_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 and_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 and_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  and_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  and_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  and_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
         AVX2_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  and_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  and_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  and_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
// not
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  not_vi8x32 (const vi8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  not_vu8x32 (const vu8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 not_vi16x16(const vi16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 not_vu16x16(const vu16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  not_vi32x8 (const vi32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  not_vu32x8 (const vu32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  not_vi64x4 (const vi64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  not_vu64x4 (const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  not_vf32x8 (const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  not_vf64x4 (const vf64x4  rhs));
// xor
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi8x32  xor_vi8x32 (const vi8x32  lhs, const vi8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu8x32  xor_vu8x32 (const vu8x32  lhs, const vu8x32  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi16x16 xor_vi16x16(const vi16x16 lhs, const vi16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu16x16 xor_vu16x16(const vu16x16 lhs, const vu16x16 rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi32x8  xor_vi32x8 (const vi32x8  lhs, const vi32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu32x8  xor_vu32x8 (const vu32x8  lhs, const vu32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vi64x4  xor_vi64x4 (const vi64x4  lhs, const vi64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vu64x4  xor_vu64x4 (const vu64x4  lhs, const vu64x4  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf32x8  xor_vf32x8 (const vf32x8  lhs, const vf32x8  rhs));
          AVX_FUNC_DECL(CVEC_FORCE_INLINE vf64x4  xor_vf64x4 (const vf64x4  lhs, const vf64x4  rhs));
