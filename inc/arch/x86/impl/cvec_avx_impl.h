#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

/// aligned_malloc / free
CVEC_FORCE_INLINE void* amalloc(size_t size, size_t alignement){ return _mm_malloc(size, alignement); }
CVEC_FORCE_INLINE void  afree(void* addr){ _mm_free(addr); }

/// load / store instructions
// setzero
CVEC_FORCE_INLINE vi8  setzero_vi8 (void) {  return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu8  setzero_vu8 (void) {  return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi16 setzero_vi16(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu16 setzero_vu16(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi32 setzero_vi32(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu32 setzero_vu32(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vi64 setzero_vi64(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vu64 setzero_vu64(void) { return _mm256_setzero_si256(); }
CVEC_FORCE_INLINE vf32 setzero_vf32(void) { return _mm256_setzero_ps(); }
CVEC_FORCE_INLINE vf64 setzero_vf64(void) { return _mm256_setzero_pd(); }
// set1
CVEC_FORCE_INLINE vi8  set1_vi8 (const   int8_t scalar) { return _mm256_set1_epi8  (          (char)scalar ); }
CVEC_FORCE_INLINE vu8  set1_vu8 (const  uint8_t scalar) { return _mm256_set1_epi8  (     *((char *)&scalar)); }
CVEC_FORCE_INLINE vi16 set1_vi16(const  int16_t scalar) { return _mm256_set1_epi16 (         (short)scalar ); }
CVEC_FORCE_INLINE vu16 set1_vu16(const uint16_t scalar) { return _mm256_set1_epi16 (    *((short *)&scalar)); }
CVEC_FORCE_INLINE vi32 set1_vi32(const  int32_t scalar) { return _mm256_set1_epi32 (           (int)scalar ); }
CVEC_FORCE_INLINE vu32 set1_vu32(const uint32_t scalar) { return _mm256_set1_epi32 (      *((int *)&scalar)); }
CVEC_FORCE_INLINE vi64 set1_vi64(const  int64_t scalar) { return _mm256_set1_epi64x(     (long long)scalar ); }
CVEC_FORCE_INLINE vu64 set1_vu64(const uint64_t scalar) { return _mm256_set1_epi64x(*((long long *)&scalar)); }
CVEC_FORCE_INLINE vf32 set1_vf32(const    float scalar) { return _mm256_set1_ps    (                scalar ); }
CVEC_FORCE_INLINE vf64 set1_vf64(const   double scalar) { return _mm256_set1_pd    (                scalar ); }
// aligned load
CVEC_FORCE_INLINE vi8  load_vi8 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu8  load_vu8 (void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi16 load_vi16(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu16 load_vu16(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi32 load_vi32(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu32 load_vu32(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi64 load_vi64(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu64 load_vu64(void* addr) { return _mm256_load_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vf32 load_vf32(void* addr) { return _mm256_load_ps   ((  float *)addr); }
CVEC_FORCE_INLINE vf64 load_vf64(void* addr) { return _mm256_load_pd   (( double *)addr); }
// unaligned load
CVEC_FORCE_INLINE vi8  loadu_vi8 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu8  loadu_vu8 (void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi16 loadu_vi16(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu16 loadu_vu16(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi32 loadu_vi32(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu32 loadu_vu32(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vi64 loadu_vi64(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vu64 loadu_vu64(void* addr) { return _mm256_lddqu_si256((__m256i *)addr); }
CVEC_FORCE_INLINE vf32 loadu_vf32(void* addr) { return _mm256_castsi256_ps(_mm256_lddqu_si256((__m256i *)addr)); }
CVEC_FORCE_INLINE vf64 loadu_vf64(void* addr) { return _mm256_castsi256_pd(_mm256_lddqu_si256((__m256i *)addr)); }
// aligned store
CVEC_FORCE_INLINE void store_vi8 (const vi8  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu8 (const vu8  v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi16(const vi16 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu16(const vu16 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi32(const vi32 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu32(const vu32 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vi64(const vi64 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vu64(const vu64 v, void* addr) { _mm256_store_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void store_vf32(const vf32 v, void* addr) { _mm256_store_ps   ((  float *)addr, v); }
CVEC_FORCE_INLINE void store_vf64(const vf64 v, void* addr) { _mm256_store_pd   (( double *)addr, v); }
// unaligned store
CVEC_FORCE_INLINE void storeu_vi8 (const vi8  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu8 (const vu8  v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi16(const vi16 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu16(const vu16 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi32(const vi32 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu32(const vu32 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vi64(const vi64 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vu64(const vu64 v, void* addr) { _mm256_storeu_si256((__m256i *)addr, v); }
CVEC_FORCE_INLINE void storeu_vf32(const vf32 v, void* addr) { _mm256_storeu_ps   ((  float *)addr, v); }
CVEC_FORCE_INLINE void storeu_vf64(const vf64 v, void* addr) { _mm256_storeu_pd   (( double *)addr, v); }
// extract scalar
CVEC_FORCE_INLINE   int8_t at_vi8 (const vi8  v, size_t lane) { return ((const   int8_t *)&v)[lane];}
CVEC_FORCE_INLINE  uint8_t at_vu8 (const vu8  v, size_t lane) { return ((const  uint8_t *)&v)[lane];}
CVEC_FORCE_INLINE  int16_t at_vi16(const vi16 v, size_t lane) { return ((const  int16_t *)&v)[lane];}
CVEC_FORCE_INLINE uint16_t at_vu16(const vu16 v, size_t lane) { return ((const uint16_t *)&v)[lane];}
CVEC_FORCE_INLINE  int32_t at_vi32(const vi32 v, size_t lane) { return ((const  int32_t *)&v)[lane];}
CVEC_FORCE_INLINE uint32_t at_vu32(const vu32 v, size_t lane) { return ((const uint32_t *)&v)[lane];}
CVEC_FORCE_INLINE  int64_t at_vi64(const vi64 v, size_t lane) { return ((const  int64_t *)&v)[lane];}
CVEC_FORCE_INLINE uint64_t at_vu64(const vu64 v, size_t lane) { return ((const uint64_t *)&v)[lane];}
CVEC_FORCE_INLINE    float at_vf32(const vf32 v, size_t lane) { return ((const    float *)&v)[lane];}
CVEC_FORCE_INLINE   double at_vf64(const vf64 v, size_t lane) { return ((const   double *)&v)[lane];}


/// arithmetic instructions
// add
CVEC_FORCE_INLINE vf32 add_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_add_ps   (lhs, rhs); }
CVEC_FORCE_INLINE vf64 add_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_add_pd   (lhs, rhs); }
// sub
CVEC_FORCE_INLINE vf32 sub_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_sub_ps   (lhs, rhs); }
CVEC_FORCE_INLINE vf64 sub_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_sub_pd   (lhs, rhs); }
// mul
CVEC_FORCE_INLINE vf32 mul_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_mul_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 mul_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_mul_pd(lhs, rhs); }
// div
CVEC_FORCE_INLINE vf32 div_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_div_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 div_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_div_pd(lhs, rhs); }
// max
CVEC_FORCE_INLINE vf32 max_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_max_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 max_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_max_pd(lhs, rhs); }
// min
CVEC_FORCE_INLINE vf32 min_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_min_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 min_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_min_pd(lhs, rhs); }

/// bit manipulation
#ifndef CVEC_AVX2
// or
CVEC_FORCE_INLINE vi8  or_vi8 (const vi8  lhs, const vi8  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8  or_vu8 (const vu8  lhs, const vu8  rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16 or_vi16(const vi16 lhs, const vi16 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16 or_vu16(const vu16 lhs, const vu16 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32 or_vi32(const vi32 lhs, const vi32 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32 or_vu32(const vu32 lhs, const vu32 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64 or_vi64(const vi64 lhs, const vi64 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64 or_vu64(const vu64 lhs, const vu64 rhs) { return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32 or_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_or_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 or_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_or_pd(lhs, rhs); }
// and
CVEC_FORCE_INLINE vi8  and_vi8 (const vi8  lhs, const vi8  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8  and_vu8 (const vu8  lhs, const vu8  rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16 and_vi16(const vi16 lhs, const vi16 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16 and_vu16(const vu16 lhs, const vu16 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32 and_vi32(const vi32 lhs, const vi32 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32 and_vu32(const vu32 lhs, const vu32 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64 and_vi64(const vi64 lhs, const vi64 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64 and_vu64(const vu64 lhs, const vu64 rhs) { return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32 and_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_and_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 and_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_and_pd(lhs, rhs); }
// not
CVEC_FORCE_INLINE vi8  not_vi8 (const vi8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu8  not_vu8 (const vu8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi16 not_vi16(const vi16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu16 not_vu16(const vu16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi32 not_vi32(const vi32 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu32 not_vu32(const vu32 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vi64 not_vi64(const vi64 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vu64 not_vu64(const vu64 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
CVEC_FORCE_INLINE vf32 not_vf32(const vf32 rhs) { return                     _mm256_xor_ps(                    rhs , _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0)))); }
CVEC_FORCE_INLINE vf64 not_vf64(const vf64 rhs) { return                     _mm256_xor_pd(                    rhs , _mm256_castsi256_pd(_mm256_set1_epi32(~((int)0)))); }
// xor
CVEC_FORCE_INLINE vi8  xor_vi8 (const vi8  lhs, const vi8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu8  xor_vu8 (const vu8  lhs, const vu8  rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi16 xor_vi16(const vi16 lhs, const vi16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu16 xor_vu16(const vu16 lhs, const vu16 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi32 xor_vi32(const vi32 lhs, const vi32 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu32 xor_vu32(const vu32 lhs, const vu32 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vi64 xor_vi64(const vi64 lhs, const vi64 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vu64 xor_vu64(const vu64 lhs, const vu64 rhs) { return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs))); }
CVEC_FORCE_INLINE vf32 xor_vf32(const vf32 lhs, const vf32 rhs) { return _mm256_xor_ps(lhs, rhs); }
CVEC_FORCE_INLINE vf64 xor_vf64(const vf64 lhs, const vf64 rhs) { return _mm256_xor_pd(lhs, rhs); }
#endif
