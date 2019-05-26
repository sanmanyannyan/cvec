#ifndef CVEC_AVX_IMPL_H
#define CVEC_AVX_IMPL_H

#include <immintrin.h>
#include <stdint.h>

/// load / store instructions
// setzero
CVEC_FORCE_INLINE vi8x32  setzero_vi8x32 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu8x32  setzero_vu8x32 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi16x16 setzero_vi16x16(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu16x16 setzero_vu16x16(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi32x8  setzero_vi32x8 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu32x8  setzero_vu32x8 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi64x4  setzero_vi64x4 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu64x4  setzero_vu64x4 (void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vf32x8  setzero_vf32x8 (void) { return _mm256_setzero_ps(); }
CVEC_FORCE_INLINE vf64x4  setzero_vf64x4 (void) { return _mm256_setzero_pd(); }
// set1
CVEC_FORCE_INLINE vi8x32  set1_vi8x32 (const   int8_t scalar) { return _mm256_set1_epi8  (          (char)scalar ); }
CVEC_FORCE_INLINE vu8x32  set1_vu8x32 (const  uint8_t scalar) { return _mm256_set1_epi8  (     *((char *)&scalar)); }
CVEC_FORCE_INLINE vi16x16 set1_vi16x16(const  int16_t scalar) { return _mm256_set1_epi16 (         (short)scalar ); }
CVEC_FORCE_INLINE vu16x16 set1_vu16x16(const uint16_t scalar) { return _mm256_set1_epi16 (    *((short *)&scalar)); }
CVEC_FORCE_INLINE vi32x8  set1_vi32x8 (const  int32_t scalar) { return _mm256_set1_epi32 (           (int)scalar ); }
CVEC_FORCE_INLINE vu32x8  set1_vu32x8 (const uint32_t scalar) { return _mm256_set1_epi32 (      *((int *)&scalar)); }
CVEC_FORCE_INLINE vi64x4  set1_vi64x4 (const  int64_t scalar) { return _mm256_set1_epi64x(     (long long)scalar ); }
CVEC_FORCE_INLINE vu64x4  set1_vu64x4 (const uint64_t scalar) { return _mm256_set1_epi64x(*((long long *)&scalar)); }
CVEC_FORCE_INLINE vf32x8  set1_vf32x8 (const    float scalar) { return _mm256_set1_ps    (                scalar ); }
CVEC_FORCE_INLINE vf64x4  set1_vf64x4 (const   double scalar) { return _mm256_set1_pd    (                scalar ); }
// aligned load
CVEC_FORCE_INLINE vi8x32  load_vi8x32 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu8x32  load_vu8x32 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi16x16 load_vi16x16(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu16x16 load_vu16x16(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi32x8  load_vi32x8 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu32x8  load_vu32x8 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi64x4  load_vi64x4 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu64x4  load_vu64x4 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vf32x8  load_vf32x8 (void* addr) { return _mm256_load_ps   ((  float *)addr); }
CVEC_FORCE_INLINE vf64x4  load_vf64x4 (void* addr) { return _mm256_load_pd   (( double *)addr); }
// unaligned load
CVEC_FORCE_INLINE vi8x32  loadu_vi8x32 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu8x32  loadu_vu8x32 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi16x16 loadu_vi16x16(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu16x16 loadu_vu16x16(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi32x8  loadu_vi32x8 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu32x8  loadu_vu32x8 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi64x4  loadu_vi64x4 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu64x4  loadu_vu64x4 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vf32x8  loadu_vf32x8 (void* addr) { return _mm256_castsi256_ps(_mm256_lddqu_si256((__m256i *)addr)); }
CVEC_FORCE_INLINE vf64x4  loadu_vf64x4 (void* addr) { return _mm256_castsi256_pd(_mm256_lddqu_si256((__m256i *)addr)); }
// aligned store
CVEC_FORCE_INLINE void store_vi8x32 (const vi8x32  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu8x32 (const vu8x32  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi16x16(const vi16x16 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu16x16(const vu16x16 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi32x8 (const vi32x8  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu32x8 (const vu32x8  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi64x4 (const vi64x4  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu64x4 (const vu64x4  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vf32x8 (const vf32x8  v, void* addr) { _mm256_store_ps   ((  float *)addr, v); }
CVEC_FORCE_INLINE void store_vf64x4 (const vf64x4  v, void* addr) { _mm256_store_pd   (( double *)addr, v); }
// unaligned store
CVEC_FORCE_INLINE void storeu_vi8x32 (const vi8x32  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu8x32 (const vu8x32  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi16x16(const vi16x16 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu16x16(const vu16x16 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi32x8 (const vi32x8  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu32x8 (const vu32x8  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi64x4 (const vi64x4  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu64x4 (const vu64x4  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vf32x8 (const vf32x8  v, void* addr) { _mm256_storeu_ps   ((  float *)addr, v); }
CVEC_FORCE_INLINE void storeu_vf64x4 (const vf64x4  v, void* addr) { _mm256_storeu_pd   (( double *)addr, v); }
// extract scalar
CVEC_FORCE_INLINE   int8_t at_vi8x32 (const vi8x32  v, int lane) { assert(lane < VI8X32_NUM_ELEMENT);  return ((const   int8_t*)& v)[lane]; }
CVEC_FORCE_INLINE  uint8_t at_vu8x32 (const vu8x32  v, int lane) { assert(lane < VU8X32_NUM_ELEMENT);  return ((const  uint8_t*)& v)[lane]; }
CVEC_FORCE_INLINE  int16_t at_vi16x16(const vi16x16 v, int lane) { assert(lane < VI16X16_NUM_ELEMENT); return ((const  int16_t*)& v)[lane]; }
CVEC_FORCE_INLINE uint16_t at_vu16x16(const vu16x16 v, int lane) { assert(lane < VU16X16_NUM_ELEMENT); return ((const uint16_t*)& v)[lane]; }
CVEC_FORCE_INLINE  int32_t at_vi32x8 (const vi32x8  v, int lane) { assert(lane < VI32X8_NUM_ELEMENT);  return ((const  int32_t*)& v)[lane]; }
CVEC_FORCE_INLINE uint32_t at_vu32x8 (const vu32x8  v, int lane) { assert(lane < VU32X8_NUM_ELEMENT);  return ((const uint32_t*)& v)[lane]; }
CVEC_FORCE_INLINE  int64_t at_vi64x4 (const vi64x4  v, int lane) { assert(lane < VI64X4_NUM_ELEMENT);  return ((const  int64_t*)& v)[lane]; }
CVEC_FORCE_INLINE uint64_t at_vu64x4 (const vu64x4  v, int lane) { assert(lane < VU64X4_NUM_ELEMENT);  return ((const uint64_t*)& v)[lane]; }
CVEC_FORCE_INLINE    float at_vf32x8 (const vf32x8  v, int lane) { assert(lane < VF32X8_NUM_ELEMENT);  return ((const    float*)& v)[lane]; }
CVEC_FORCE_INLINE   double at_vf64x4 (const vf64x4  v, int lane) { assert(lane < VF64X4_NUM_ELEMENT);  return ((const   double *)&v)[lane];}


/// arithmetic instructions
// add
CVEC_FORCE_INLINE vf32x8 add_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_add_ps   (lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 add_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_add_pd   (lhs, rhs); }
// sub
CVEC_FORCE_INLINE vf32x8 sub_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_sub_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 sub_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_sub_pd   (lhs, rhs); }
// mul
CVEC_FORCE_INLINE vf32x8 mul_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_mul_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 mul_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_mul_pd(lhs, rhs); }
// div
CVEC_FORCE_INLINE vf32x8 div_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_div_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 div_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_div_pd(lhs, rhs); }
// max
CVEC_FORCE_INLINE vf32x8 max_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_max_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 max_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_max_pd(lhs, rhs); }
// min
CVEC_FORCE_INLINE vf32x8 min_vf32x8(const vf32x8 lhs, const vf32x8 rhs) { return _mm256_min_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4 min_vf64x4(const vf64x4 lhs, const vf64x4 rhs) { return _mm256_min_pd(lhs, rhs); }

/// elementary math functions
// reciprocal estimation
CVEC_FORCE_INLINE vf32x8 arcp_vf32x8(const vf32x8 rhs) { return _mm256_rcp_ps(rhs); }

/// bit manipulation
#ifndef CVEC_AVX2
// or
CVEC_FORCE_INLINE vi8x32  or_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8x32  or_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16x16 or_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16x16 or_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32x8  or_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32x8  or_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64x4  or_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64x4  or_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32x8  or_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_or_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  or_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_or_pd(lhs, rhs); }
// and
CVEC_FORCE_INLINE vi8x32  and_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8x32  and_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16x16 and_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16x16 and_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32x8  and_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32x8  and_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64x4  and_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64x4  and_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32x8  and_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_and_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  and_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_and_pd(lhs, rhs); }
// not
CVEC_FORCE_INLINE vi8x32  not_vi8x32 (const vi8x32  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu8x32  not_vu8x32 (const vu8x32  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi16x16 not_vi16x16(const vi16x16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu16x16 not_vu16x16(const vu16x16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi32x8  not_vi32x8 (const vi32x8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu32x8  not_vu32x8 (const vu32x8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi64x4  not_vi64x4 (const vi64x4  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu64x4  not_vu64x4 (const vu64x4  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vf32x8  not_vf32x8 (const vf32x8  rhs) { return                     _mm256_xor_ps(                    rhs , _mm256_cmp_ps(_mm256_setzero_ps(), _mm256_setzero_ps(), _CMP_EQ_OQ)); }
CVEC_FORCE_INLINE vf64x4  not_vf64x4 (const vf64x4  rhs) { return                     _mm256_xor_pd(                    rhs , _mm256_cmp_pd(_mm256_setzero_pd(), _mm256_setzero_pd(), _CMP_EQ_OQ) ); }
// xor
CVEC_FORCE_INLINE vi8x32  xor_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8x32  xor_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16x16 xor_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16x16 xor_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32x8  xor_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32x8  xor_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64x4  xor_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64x4  xor_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32x8  xor_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_xor_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  xor_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_xor_pd(lhs, rhs); }
#else
// or
CVEC_FORCE_INLINE vf32x8  or_vf32x8(const vf32x8  lhs, const vf32x8  rhs) { return _mm256_or_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  or_vf64x4(const vf64x4  lhs, const vf64x4  rhs) { return _mm256_or_pd(lhs, rhs); }
// and
CVEC_FORCE_INLINE vf32x8  and_vf32x8(const vf32x8  lhs, const vf32x8  rhs) { return _mm256_and_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  and_vf64x4(const vf64x4  lhs, const vf64x4  rhs) { return _mm256_and_pd(lhs, rhs); }
// not
CVEC_FORCE_INLINE vf32x8  not_vf32x8(const vf32x8  rhs) { return                     _mm256_xor_ps(rhs, _mm256_cmp_ps(_mm256_setzero_ps(), _mm256_setzero_ps(), _CMP_EQ_OQ)); }
CVEC_FORCE_INLINE vf64x4  not_vf64x4(const vf64x4  rhs) { return                     _mm256_xor_pd(rhs, _mm256_cmp_pd(_mm256_setzero_pd(), _mm256_setzero_pd(), _CMP_EQ_OQ)); }
// xor
CVEC_FORCE_INLINE vf32x8  xor_vf32x8(const vf32x8  lhs, const vf32x8  rhs) { return _mm256_xor_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64x4  xor_vf64x4(const vf64x4  lhs, const vf64x4  rhs) { return _mm256_xor_pd(lhs, rhs); }
#endif

#endif
