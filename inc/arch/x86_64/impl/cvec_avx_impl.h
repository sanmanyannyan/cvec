#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

/// aligned_malloc / free
static inline void* amalloc(size_t size, size_t alignement){ return _mm_malloc(size, alignement); }
static inline void  afree(void* addr){ _mm_free(addr); }

/// load / store instructions
// setzero
static inline vi8  setzero_vi8(){  return _mm256_setzero_si256(); }
static inline vu8  setzero_vu8(){  return _mm256_setzero_si256(); }
static inline vi16 setzero_vi16(){ return _mm256_setzero_si256(); }
static inline vu16 setzero_vu16(){ return _mm256_setzero_si256(); }
static inline vi32 setzero_vi32(){ return _mm256_setzero_si256(); }
static inline vu32 setzero_vu32(){ return _mm256_setzero_si256(); }
static inline vi64 setzero_vi64(){ return _mm256_setzero_si256(); }
static inline vu64 setzero_vu64(){ return _mm256_setzero_si256(); }
static inline vflt setzero_vflt(){ return _mm256_setzero_ps(); }
static inline vdbl setzero_vdbl(){ return _mm256_setzero_pd(); }
// set1
static inline vi8  set1_vi8( const   int8_t scalar){ return _mm256_set1_epi8(            (char)scalar ); }
static inline vu8  set1_vu8( const  uint8_t scalar){ return _mm256_set1_epi8(       *((char *)&scalar)); }
static inline vi16 set1_vi16(const  int16_t scalar){ return _mm256_set1_epi16(          (short)scalar ); }
static inline vu16 set1_vu16(const uint16_t scalar){ return _mm256_set1_epi16(     *((short *)&scalar)); }
static inline vi32 set1_vi32(const  int32_t scalar){ return _mm256_set1_epi32(            (int)scalar ); }
static inline vu32 set1_vu32(const uint32_t scalar){ return _mm256_set1_epi32(       *((int *)&scalar)); }
static inline vi64 set1_vi64(const  int64_t scalar){ return _mm256_set1_epi64x(     (long long)scalar ); }
static inline vu64 set1_vu64(const uint64_t scalar){ return _mm256_set1_epi64x(*((long long *)&scalar)); }
static inline vflt set1_vflt(const    float scalar){ return _mm256_set1_ps(scalar); }
static inline vdbl set1_vdbl(const   double scalar){ return _mm256_set1_pd(scalar); }
// aligned load
static inline vi8  load_vi8( void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vu8  load_vu8( void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vi16 load_vi16(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vu16 load_vu16(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vi32 load_vi32(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vu32 load_vu32(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vi64 load_vi64(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vu64 load_vu64(void* addr){ return _mm256_load_si256((__m256i *)addr); }
static inline vflt load_vflt(void* addr){ return _mm256_load_ps((float *)addr); }
static inline vdbl load_vdbl(void* addr){ return _mm256_load_pd((double *)addr); }
// unaligned load
static inline vi8  loadu_vi8( void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vu8  loadu_vu8( void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vi16 loadu_vi16(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vu16 loadu_vu16(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vi32 loadu_vi32(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vu32 loadu_vu32(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vi64 loadu_vi64(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vu64 loadu_vu64(void* addr){ return _mm256_lddqu_si256((__m256i *)addr); }
static inline vflt loadu_vflt(void* addr){ return _mm256_castsi256_ps(_mm256_lddqu_si256((__m256i *)addr)); }
static inline vdbl loadu_vdbl(void* addr){ return _mm256_castsi256_pd(_mm256_lddqu_si256((__m256i *)addr)); }
// aligned store
static inline void store_vi8( const vi8  v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vu8( const vu8  v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vi16(const vi16 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vu16(const vu16 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vi32(const vi32 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vu32(const vu32 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vi64(const vi64 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vu64(const vu64 v, void* addr){ _mm256_store_si256((__m256i *)addr, v); }
static inline void store_vflt(const vflt v, void* addr){ _mm256_store_ps((float *)addr, v); }
static inline void store_vdbl(const vdbl v, void* addr){ _mm256_store_pd((double *)addr, v); }
// unaligned store
static inline void storeu_vi8( const vi8  v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vu8( const vu8  v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vi16(const vi16 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vu16(const vu16 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vi32(const vi32 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vu32(const vu32 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vi64(const vi64 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vu64(const vu64 v, void* addr){ _mm256_storeu_si256((__m256i *)addr, v); }
static inline void storeu_vflt(const vflt v, void* addr){ _mm256_storeu_ps((float *)addr, v); }
static inline void storeu_vdbl(const vdbl v, void* addr){ _mm256_storeu_pd((double *)addr, v); }


/// arithmetic instructions
// add
static inline vi8  add_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_add_epi8( lhs, rhs); }
static inline vu8  add_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_add_epi8( lhs, rhs); }
static inline vi16 add_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_add_epi16(lhs, rhs); }
static inline vu16 add_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_add_epi16(lhs, rhs); }
static inline vi32 add_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_add_epi32(lhs, rhs); }
static inline vu32 add_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_add_epi32(lhs, rhs); }
static inline vi64 add_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_add_epi64(lhs, rhs); }
static inline vu64 add_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_add_epi64(lhs, rhs); }
static inline vflt add_vflt(const vflt lhs, const vflt rhs){ return _mm256_add_ps(lhs, rhs); }
static inline vdbl add_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_add_pd(lhs, rhs); }
// sub
static inline vi8  sub_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_sub_epi8( lhs, rhs); }
static inline vu8  sub_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_sub_epi8( lhs, rhs); }
static inline vi16 sub_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_sub_epi16(lhs, rhs); }
static inline vu16 sub_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_sub_epi16(lhs, rhs); }
static inline vi32 sub_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_sub_epi32(lhs, rhs); }
static inline vu32 sub_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_sub_epi32(lhs, rhs); }
static inline vi64 sub_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_sub_epi64(lhs, rhs); }
static inline vu64 sub_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_sub_epi64(lhs, rhs); }
static inline vflt sub_vflt(const vflt lhs, const vflt rhs){ return _mm256_sub_ps(lhs, rhs); }
static inline vdbl sub_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_sub_pd(lhs, rhs); }
// mul
// static inline vi8  mul_vi8(const vi8 lhs, const vi8 rhs);
// static inline vu8  mul_vu8(const vu8 lhs, const vu8 rhs);
// static inline vi16 mul_vi16(const vi16 lhs, const vi16 rhs);
// static inline vu16 mul_vu16(const vu16 lhs, const vu16 rhs);
static inline vi32 mul_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_mul_epi32(lhs, rhs); }
static inline vu32 mul_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_mul_epu32(lhs, rhs); }
// static inline vi64 mul_vi64(const vi64 lhs, const vi64 rhs);
// static inline vu64 mul_vu64(const vu64 lhs, const vu64 rhs);
static inline vflt mul_vflt(const vflt lhs, const vflt rhs){ return _mm256_mul_ps(lhs, rhs); }
static inline vdbl mul_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_mul_pd(lhs, rhs); }
// div
// static inline vi8  div_vi8(const vi8 lhs, const vi8 rhs);
// static inline vu8  div_vu8(const vu8 lhs, const vu8 rhs);
// static inline vi16 div_vi16(const vi16 lhs, const vi16 rhs);
// static inline vu16 div_vu16(const vu16 lhs, const vu16 rhs);
// static inline vi32 div_vi32(const vi32 lhs, const vi32 rhs);
// static inline vu32 div_vu32(const vu32 lhs, const vu32 rhs);
// static inline vi64 div_vi64(const vi64 lhs, const vi64 rhs);
// static inline vu64 div_vu64(const vu64 lhs, const vu64 rhs);
static inline vflt div_vflt(const vflt lhs, const vflt rhs){ return _mm256_div_ps(lhs, rhs); }
static inline vdbl div_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_div_pd(lhs, rhs); }
// max
static inline vi8  max_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_max_epi8( lhs, rhs); }
static inline vu8  max_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_max_epu8( lhs, rhs); }
static inline vi16 max_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_max_epi16(lhs, rhs); }
static inline vu16 max_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_max_epu16(lhs, rhs); }
static inline vi32 max_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_max_epi32(lhs, rhs); }
static inline vu32 max_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_max_epu32(lhs, rhs); }
// static inline vi64 max_vi64(const vi64 lhs, const vi64 rhs);
// static inline vu64 max_vu64(const vu64 lhs, const vu64 rhs);
static inline vflt max_vflt(const vflt lhs, const vflt rhs){ return _mm256_max_ps(lhs, rhs); }
static inline vdbl max_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_max_pd(lhs, rhs); }
// min
static inline vi8  min_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_min_epi8( lhs, rhs); }
static inline vu8  min_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_min_epu8( lhs, rhs); }
static inline vi16 min_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_min_epi16(lhs, rhs); }
static inline vu16 min_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_min_epu16(lhs, rhs); }
static inline vi32 min_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_min_epi32(lhs, rhs); }
static inline vu32 min_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_min_epu32(lhs, rhs); }
// static inline vi64 min_vi64(const vi64 lhs, const vi64 rhs);
// static inline vu64 min_vu64(const vu64 lhs, const vu64 rhs);
static inline vflt min_vflt(const vflt lhs, const vflt rhs){ return _mm256_min_ps(lhs, rhs); }
static inline vdbl min_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_min_pd(lhs, rhs); }

/// bit manipulation
#ifndef CVEC_AVX2
// or
static inline vi8  or_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu8  or_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi16 or_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu16 or_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi32 or_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu32 or_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi64 or_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu64 or_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_castps_si256(_mm256_or_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vflt or_vflt(const vflt lhs, const vflt rhs){ return _mm256_or_ps(lhs, rhs); }
static inline vdbl or_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_or_pd(lhs, rhs); }
// and
static inline vi8  and_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu8  and_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi16 and_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu16 and_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi32 and_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu32 and_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi64 and_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu64 and_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_castps_si256(_mm256_and_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vflt and_vflt(const vflt lhs, const vflt rhs){ return _mm256_and_ps(lhs, rhs); }
static inline vdbl and_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_and_pd(lhs, rhs); }
// not
static inline vi8  not_vi8( const vi8  rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vu8  not_vu8( const vu8  rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vi16 not_vi16(const vi16 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vu16 not_vu16(const vu16 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vi32 not_vi32(const vi32 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vu32 not_vu32(const vu32 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vi64 not_vi64(const vi64 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vu64 not_vu64(const vu64 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(rhs), _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0))))); }
static inline vflt not_vflt(const vflt rhs){ return                     _mm256_xor_ps(                    rhs , _mm256_castsi256_ps(_mm256_set1_epi32(~((int)0)))); }
static inline vdbl not_vdbl(const vdbl rhs){ return                     _mm256_xor_pd(                    rhs , _mm256_castsi256_pd(_mm256_set1_epi32(~((int)0)))); }
// xor
static inline vi8  xor_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu8  xor_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi16 xor_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu16 xor_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi32 xor_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu32 xor_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vi64 xor_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vu64 xor_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_castps_si256(_mm256_xor_ps(_mm256_castsi256_ps(lhs), _mm256_castsi256_ps(rhs)); }
static inline vflt xor_vflt(const vflt lhs, const vflt rhs){ return _mm256_xor_ps(lhs, rhs); }
static inline vdbl xor_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_xor_pd(lhs, rhs); }
#endif
