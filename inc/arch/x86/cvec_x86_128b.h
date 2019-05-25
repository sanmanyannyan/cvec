#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

#define CVEC128_VECTOR_SIZE ((size_t)(16))
#define CVEC128_MEMORY_ALIGNMENT 16u

SSE2_TYPE_DECL(vi8x16, __m128i);
SSE2_TYPE_DECL(vu8x16, __m128i);
SSE2_TYPE_DECL(vi16x8, __m128i);
SSE2_TYPE_DECL(vu16x8, __m128i);
SSE2_TYPE_DECL(vi32x4, __m128i);
SSE2_TYPE_DECL(vu32x4, __m128i);
SSE2_TYPE_DECL(vi64x2, __m128i);
SSE2_TYPE_DECL(vu64x2, __m128i);
SSE_TYPE_DECL (vf32x4, __m128 );
SSE2_TYPE_DECL(vf64x2, __m128d);

#define VI8X16_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(  int8_t))
#define VU8X16_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof( uint8_t))
#define VI16X8_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof( int16_t))
#define VU16X8_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(uint16_t))
#define VI32X4_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof( int32_t))
#define VU32X4_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(uint32_t))
#define VI64X2_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof( int64_t))
#define VU64X2_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(uint64_t))
#define VF32X4_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(   float))
#define VF64X2_NUM_ELEMENT (CVEC128_VECTOR_SIZE / sizeof(  double))

/// aligned_malloc / free
          SSE_FUNC_DECL(CVEC_FORCE_INLINE void* amalloc(size_t size, size_t alignement));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE void  afree(void* addr));

/// load / store instructions
// setzero
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 setzero_vi8x16() );
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 setzero_vu8x16() );
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 setzero_vi16x8());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 setzero_vu16x8());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 setzero_vi32x4());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 setzero_vu32x4());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 setzero_vi64x2());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 setzero_vu64x2());
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 setzero_vf32x4());
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 setzero_vf64x2());
// set1
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 set1_vi8x16(const   int8_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 set1_vu8x16(const  uint8_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 set1_vi16x8(const  int16_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 set1_vu16x8(const uint16_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 set1_vi32x4(const  int32_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 set1_vu32x4(const uint32_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 set1_vi64x2(const  int64_t scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 set1_vu64x2(const uint64_t scalar));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 set1_vf32x4(const    float scalar));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 set1_vf64x2(const   double scalar));
// aligned load
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 load_vi8x16(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 load_vu8x16(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 load_vi16x8(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 load_vu16x8(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 load_vi32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 load_vu32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 load_vi64x2(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 load_vu64x2(void* addr));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 load_vf32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 load_vf64x2(void* addr));
// unaligned load
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 loadu_vi8x16(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 loadu_vu8x16(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 loadu_vi16x8(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 loadu_vu16x8(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 loadu_vi32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 loadu_vu32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 loadu_vi64x2(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 loadu_vu64x2(void* addr));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 loadu_vf32x4(void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 loadu_vf64x2(void* addr));
// aligned store
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vi8x16(const vi8x16 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vu8x16(const vu8x16 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vi16x8(const vi16x8 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vu16x8(const vu16x8 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vi32x4(const vi32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vu32x4(const vu32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vi64x2(const vi64x2 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vu64x2(const vu64x2 v, void* addr));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE void store_vf32x4(const vf32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void store_vf64x2(const vf64x2 v, void* addr));
// unaligned store
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi8x16(const vi8x16 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu8x16(const vu8x16 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi16x8(const vi16x8 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu16x8(const vu16x8 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi32x4(const vi32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu32x4(const vu32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vi64x2(const vi64x2 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vu64x2(const vu64x2 v, void* addr));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vf32x4(const vf32x4 v, void* addr));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE void storeu_vf64x2(const vf64x2 v, void* addr));
// extract scalar
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE   int8_t at_vi8x16(const vi8x16 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE  uint8_t at_vu8x16(const vu8x16 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE  int16_t at_vi16x8(const vi16x8 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE uint16_t at_vu16x8(const vu16x8 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE  int32_t at_vi32x4(const vi32x4 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE uint32_t at_vu32x4(const vu32x4 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE  int64_t at_vi64x2(const vi64x2 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE uint64_t at_vu64x2(const vu64x2 v, size_t lane));
		 SSE_FUNC_DECL(CVEC_FORCE_INLINE    float at_vf32x4(const vf32x4 v, size_t lane));
		SSE2_FUNC_DECL(CVEC_FORCE_INLINE   double at_vf64x2(const vf64x2 v, size_t lane));



/// arithmetic instructions
// add
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 add_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 add_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 add_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 add_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 add_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 add_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 add_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 add_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 add_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 add_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// sub
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 sub_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 sub_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 sub_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 sub_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 sub_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 sub_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 sub_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 sub_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 sub_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 sub_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// mul
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 mul_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 mul_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 mul_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 mul_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 mul_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 mul_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 mul_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 mul_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 mul_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 mul_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// div
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 div_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 div_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 div_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 div_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 div_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 div_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 div_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 div_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 div_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 div_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// max
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 max_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 max_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 max_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 max_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 max_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 max_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 max_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 max_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 max_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 max_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// min
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 min_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 min_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 min_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 min_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 min_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
       SSE4_1_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 min_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 min_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 min_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 min_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 min_vf64x2(const vf64x2 lhs, const vf64x2 rhs));

/// elementary math functions
// reciprocal estimation
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 arcp_vf32x4(const vf32x4 rhs));
NOT_SUPPORTED_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 arcp_vf64x2(const vf64x2 rhs));
// sqrt
          SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 sqrt_vf32x4(const vf32x4 rhs));
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 sqrt_vf64x2(const vf64x2 rhs));

/// bit manipulation
// or
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 or_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 or_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 or_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 or_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 or_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 or_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 or_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 or_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
		  SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 or_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 or_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// and
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 and_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 and_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 and_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 and_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 and_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 and_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 and_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 and_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
		  SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 and_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 and_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
// not
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 not_vi8x16(const vi8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 not_vu8x16(const vu8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 not_vi16x8(const vi16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 not_vu16x8(const vu16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 not_vi32x4(const vi32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 not_vu32x4(const vu32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 not_vi64x2(const vi64x2 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 not_vu64x2(const vu64x2 rhs));
		  SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 not_vf32x4(const vf32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 not_vf64x2(const vf64x2 rhs));
// xor
         SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi8x16 xor_vi8x16(const vi8x16 lhs, const vi8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu8x16 xor_vu8x16(const vu8x16 lhs, const vu8x16 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi16x8 xor_vi16x8(const vi16x8 lhs, const vi16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu16x8 xor_vu16x8(const vu16x8 lhs, const vu16x8 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi32x4 xor_vi32x4(const vi32x4 lhs, const vi32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu32x4 xor_vu32x4(const vu32x4 lhs, const vu32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vi64x2 xor_vi64x2(const vi64x2 lhs, const vi64x2 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vu64x2 xor_vu64x2(const vu64x2 lhs, const vu64x2 rhs));
		  SSE_FUNC_DECL(CVEC_FORCE_INLINE vf32x4 xor_vf32x4(const vf32x4 lhs, const vf32x4 rhs));
		 SSE2_FUNC_DECL(CVEC_FORCE_INLINE vf64x2 xor_vf64x2(const vf64x2 lhs, const vf64x2 rhs));
