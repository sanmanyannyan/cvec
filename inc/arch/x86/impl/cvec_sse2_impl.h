#ifndef CVEC_SSE2_IMPL_H
#define CVEC_SSE2_IMPL_H

#include <emmintrin.h>
#include <stdint.h>

/// aligned_malloc / free

/// load / store instructions
// setzero
CVEC_FORCE_INLINE vi8x16 setzero_vi8x16(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vu8x16 setzero_vu8x16(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vi16x8 setzero_vi16x8(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vu16x8 setzero_vu16x8(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vi32x4 setzero_vi32x4(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vu32x4 setzero_vu32x4(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vi64x2 setzero_vi64x2(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vu64x2 setzero_vu64x2(void) { return _mm_castps_si128(_mm_setzero_ps()); }
CVEC_FORCE_INLINE vf64x2 setzero_vf64x2(void) { return _mm_castps_pd   (_mm_setzero_ps()); }
// set1
CVEC_FORCE_INLINE vi8x16 set1_vi8x16(const   int8_t scalar) { return _mm_set1_epi8  (*((const char    *)& scalar)); }
CVEC_FORCE_INLINE vu8x16 set1_vu8x16(const  uint8_t scalar) { return _mm_set1_epi8  (*((const char    *)& scalar)); }
CVEC_FORCE_INLINE vi16x8 set1_vi16x8(const  int16_t scalar) { return _mm_set1_epi16 (*((const short   *)& scalar)); }
CVEC_FORCE_INLINE vu16x8 set1_vu16x8(const uint16_t scalar) { return _mm_set1_epi16 (*((const short   *)& scalar)); }
CVEC_FORCE_INLINE vi32x4 set1_vi32x4(const  int32_t scalar) { return _mm_set1_epi32 (*((const int     *)& scalar)); }
CVEC_FORCE_INLINE vu32x4 set1_vu32x4(const uint32_t scalar) { return _mm_set1_epi32 (*((const int     *)& scalar)); }
CVEC_FORCE_INLINE vi64x2 set1_vi64x2(const  int64_t scalar) { return _mm_set1_epi64x(*((const int64_t *)& scalar)); }
CVEC_FORCE_INLINE vu64x2 set1_vu64x2(const uint64_t scalar) { return _mm_set1_epi64x(*((const int64_t *)& scalar)); }
CVEC_FORCE_INLINE vf64x2 set1_vf64x2(const   double scalar) { return _mm_set1_pd    (scalar); }
// aligned load
CVEC_FORCE_INLINE vi8x16 load_vi8x16(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vu8x16 load_vu8x16(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vi16x8 load_vi16x8(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vu16x8 load_vu16x8(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vi32x4 load_vi32x4(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vu32x4 load_vu32x4(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vi64x2 load_vi64x2(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vu64x2 load_vu64x2(void* addr) {return _mm_load_si128(addr);}
CVEC_FORCE_INLINE vf64x2 load_vf64x2(void* addr) {return _mm_load_pd   (addr);}
// unaligned load
CVEC_FORCE_INLINE vi8x16 loadu_vi8x16(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vu8x16 loadu_vu8x16(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vi16x8 loadu_vi16x8(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vu16x8 loadu_vu16x8(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vi32x4 loadu_vi32x4(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vu32x4 loadu_vu32x4(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vi64x2 loadu_vi64x2(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vu64x2 loadu_vu64x2(void* addr) { return _mm_loadu_si128(addr); }
CVEC_FORCE_INLINE vf64x2 loadu_vf64x2(void* addr) { return _mm_loadu_pd   (addr); }
// aligned store
CVEC_FORCE_INLINE void store_vi8x16(const vi8x16 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vu8x16(const vu8x16 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vi16x8(const vi16x8 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vu16x8(const vu16x8 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vi32x4(const vi32x4 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vu32x4(const vu32x4 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vi64x2(const vi64x2 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vu64x2(const vu64x2 v, void* addr) { _mm_store_si128(addr, v); }
CVEC_FORCE_INLINE void store_vf64x2(const vf64x2 v, void* addr) { _mm_store_pd   (addr, v); }
// unaligned store
CVEC_FORCE_INLINE void storeu_vi8x16(const vi8x16 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vu8x16(const vu8x16 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vi16x8(const vi16x8 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vu16x8(const vu16x8 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vi32x4(const vi32x4 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vu32x4(const vu32x4 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vi64x2(const vi64x2 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vu64x2(const vu64x2 v, void* addr) { _mm_storeu_si128(addr, v); }
CVEC_FORCE_INLINE void storeu_vf64x2(const vf64x2 v, void* addr) { _mm_storeu_pd   (addr, v); }
// extract scalar
CVEC_FORCE_INLINE   int8_t at_vi8x16(const vi8x16 v, int lane) { return ((const   int8_t *)&v)[lane]; }
CVEC_FORCE_INLINE  uint8_t at_vu8x16(const vu8x16 v, int lane) { return ((const  uint8_t *)&v)[lane]; }
CVEC_FORCE_INLINE  int16_t at_vi16x8(const vi16x8 v, int lane) { return ((const  int16_t *)&v)[lane]; }
CVEC_FORCE_INLINE uint16_t at_vu16x8(const vu16x8 v, int lane) { return ((const uint16_t *)&v)[lane]; }
CVEC_FORCE_INLINE  int32_t at_vi32x4(const vi32x4 v, int lane) { return ((const  int32_t *)&v)[lane]; }
CVEC_FORCE_INLINE uint32_t at_vu32x4(const vu32x4 v, int lane) { return ((const uint32_t *)&v)[lane]; }
CVEC_FORCE_INLINE  int64_t at_vi64x2(const vi64x2 v, int lane) { return ((const  int64_t *)&v)[lane]; }
CVEC_FORCE_INLINE uint64_t at_vu64x2(const vu64x2 v, int lane) { return ((const uint64_t *)&v)[lane]; }
CVEC_FORCE_INLINE   double at_vf64x2(const vf64x2 v, int lane) { return ((const   double *)&v)[lane]; }



/// arithmetic instructions
// add
CVEC_FORCE_INLINE vi8x16 add_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_add_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8x16 add_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_add_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x8 add_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x8 add_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x4 add_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x4 add_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64x2 add_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_add_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64x2 add_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_add_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vf64x2 add_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_add_pd   (lhs, rhs); }
// sub
CVEC_FORCE_INLINE vi8x16 sub_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_sub_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8x16 sub_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_sub_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x8 sub_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x8 sub_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x4 sub_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x4 sub_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64x2 sub_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_sub_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64x2 sub_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_sub_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vf64x2 sub_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_sub_pd   (lhs, rhs); }
// mul
CVEC_FORCE_INLINE vu32x4 mul_vu32x4(const vu32x4 lhs, const vu32x4 rhs) {return _mm_mul_epu32(lhs, rhs); }
CVEC_FORCE_INLINE vf64x2 mul_vf64x2(const vf64x2 lhs, const vf64x2 rhs) {return _mm_mul_pd   (lhs, rhs); }
// div
CVEC_FORCE_INLINE vf64x2 div_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_mul_pd(lhs, rhs); }
// max
CVEC_FORCE_INLINE vu8x16 max_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_max_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x8 max_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_max_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vf64x2 max_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_max_pd   (lhs, rhs); }
// min
CVEC_FORCE_INLINE vu8x16 min_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_min_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x8 min_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_min_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vf64x2 min_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_min_pd   (lhs, rhs); }

/// elementary math functions
// reciprocal estimation
// sqrt
CVEC_FORCE_INLINE vf64x2 sqrt_vf64x2(const vf64x2 rhs) { return _mm_sqrt_pd(rhs); }

/// bit manipulation
// or
CVEC_FORCE_INLINE mask_vi8x16 or_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu8x16 or_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi16x8 or_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu16x8 or_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi32x4 or_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu32x4 or_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi64x2 or_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu64x2 or_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_or_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vf64x2 or_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_or_pd   (lhs, rhs); }
// and
CVEC_FORCE_INLINE mask_vi8x16 and_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu8x16 and_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi16x8 and_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu16x8 and_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi32x4 and_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu32x4 and_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi64x2 and_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu64x2 and_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_and_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vf64x2 and_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_and_pd   (lhs, rhs); }
// not
CVEC_FORCE_INLINE mask_vi8x16 not_vi8x16(const vi8x16 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vu8x16 not_vu8x16(const vu8x16 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vi16x8 not_vi16x8(const vi16x8 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vu16x8 not_vu16x8(const vu16x8 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vi32x4 not_vi32x4(const vi32x4 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vu32x4 not_vu32x4(const vu32x4 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vi64x2 not_vi64x2(const vi64x2 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vu64x2 not_vu64x2(const vu64x2 rhs) { return _mm_xor_si128(rhs, _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())); }
CVEC_FORCE_INLINE mask_vf64x2 not_vf64x2(const vf64x2 rhs) { return _mm_xor_pd   (rhs, _mm_cmpeq_pd   (_mm_setzero_pd   (), _mm_setzero_pd   ()) ); }
// xor
CVEC_FORCE_INLINE mask_vi8x16 xor_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu8x16 xor_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi16x8 xor_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu16x8 xor_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi32x4 xor_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu32x4 xor_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi64x2 xor_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu64x2 xor_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_xor_si128(lhs, rhs); }
CVEC_FORCE_INLINE mask_vf64x2 xor_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_xor_pd   (lhs, rhs); }

/// Swizzle
// blend

/// mask
// eq
CVEC_FORCE_INLINE mask_vi8x16 eq_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_cmpeq_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE mask_vu8x16 eq_vu8x16(const vu8x16 lhs, const vu8x16 rhs) { return _mm_cmpeq_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE mask_vi16x8 eq_vi16x8(const vi16x8 lhs, const vi16x8 rhs) { return _mm_cmpeq_epi16(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu16x8 eq_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_cmpeq_epi16(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi32x4 eq_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_cmpeq_epi32(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu32x4 eq_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_cmpeq_epi32(lhs, rhs); }
CVEC_FORCE_INLINE mask_vf64x2 eq_vf64x2(const vf64x2 lhs, const vf64x2 rhs) { return _mm_cmpeq_pd   (lhs, rhs); }
// neq
CVEC_FORCE_INLINE mask_vi8x16 neq_vi8x16(const vi8x16 lhs,const vi8x16 rhs) { return not_vi8x16(eq_vi8x16(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vu8x16 neq_vu8x16(const vu8x16 lhs,const vu8x16 rhs) { return not_vu8x16(eq_vu8x16(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vi16x8 neq_vi16x8(const vi16x8 lhs,const vi16x8 rhs) { return not_vi16x8(eq_vi16x8(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vu16x8 neq_vu16x8(const vu16x8 lhs,const vu16x8 rhs) { return not_vu16x8(eq_vu16x8(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vi32x4 neq_vi32x4(const vi32x4 lhs,const vi32x4 rhs) { return not_vi32x4(eq_vi32x4(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vu32x4 neq_vu32x4(const vu32x4 lhs,const vu32x4 rhs) { return not_vu32x4(eq_vu32x4(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vf64x2 neq_vf64x2(const vf64x2 lhs,const vf64x2 rhs) { return _mm_cmpneq_pd(rhs, lhs); }
// lt
CVEC_FORCE_INLINE mask_vi8x16 lt_vi8x16(const vi8x16 lhs,const vi8x16 rhs) { return _mm_cmplt_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE mask_vu8x16 lt_vu8x16(const vu8x16 lhs,const vu8x16 rhs) { return _mm_cmplt_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE mask_vi16x8 lt_vi16x8(const vi16x8 lhs,const vi16x8 rhs) { return _mm_cmplt_epi16(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu16x8 lt_vu16x8(const vu16x8 lhs,const vu16x8 rhs) { return _mm_cmplt_epi16(lhs, rhs); }
CVEC_FORCE_INLINE mask_vi32x4 lt_vi32x4(const vi32x4 lhs,const vi32x4 rhs) { return _mm_cmplt_epi32(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu32x4 lt_vu32x4(const vu32x4 lhs,const vu32x4 rhs) { return _mm_cmplt_epi32(lhs, rhs); }
CVEC_FORCE_INLINE mask_vf64x2 lt_vf64x2(const vf64x2 lhs,const vf64x2 rhs) { return _mm_cmplt_pd   (lhs, rhs); }
// gt
CVEC_FORCE_INLINE mask_vi8x16 gt_vi8x16(const vi8x16 lhs,const vi8x16 rhs) { return _mm_cmplt_epi8 (rhs, lhs); }
CVEC_FORCE_INLINE mask_vu8x16 gt_vu8x16(const vu8x16 lhs,const vu8x16 rhs) { return _mm_cmplt_epi8 (rhs, lhs); }
CVEC_FORCE_INLINE mask_vi16x8 gt_vi16x8(const vi16x8 lhs,const vi16x8 rhs) { return _mm_cmplt_epi16(rhs, lhs); }
CVEC_FORCE_INLINE mask_vu16x8 gt_vu16x8(const vu16x8 lhs,const vu16x8 rhs) { return _mm_cmplt_epi16(rhs, lhs); }
CVEC_FORCE_INLINE mask_vi32x4 gt_vi32x4(const vi32x4 lhs,const vi32x4 rhs) { return _mm_cmplt_epi32(rhs, lhs); }
CVEC_FORCE_INLINE mask_vu32x4 gt_vu32x4(const vu32x4 lhs,const vu32x4 rhs) { return _mm_cmplt_epi32(rhs, lhs); }
CVEC_FORCE_INLINE mask_vf64x2 gt_vf64x2(const vf64x2 lhs,const vf64x2 rhs) { return _mm_cmplt_pd   (rhs, lhs); }
// le
CVEC_FORCE_INLINE mask_vi8x16 le_vi8x16(const vi8x16 lhs,const vi8x16 rhs) { return _mm_or_si128(_mm_cmplt_epi8 (lhs, rhs), _mm_cmpeq_epi8 (lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu8x16 le_vu8x16(const vu8x16 lhs,const vu8x16 rhs) { return _mm_or_si128(_mm_cmplt_epi8 (lhs, rhs), _mm_cmpeq_epi8 (lhs, rhs)); }
CVEC_FORCE_INLINE mask_vi16x8 le_vi16x8(const vi16x8 lhs,const vi16x8 rhs) { return _mm_or_si128(_mm_cmplt_epi16(lhs, rhs), _mm_cmpeq_epi16(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu16x8 le_vu16x8(const vu16x8 lhs,const vu16x8 rhs) { return _mm_or_si128(_mm_cmplt_epi16(lhs, rhs), _mm_cmpeq_epi16(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vi32x4 le_vi32x4(const vi32x4 lhs,const vi32x4 rhs) { return _mm_or_si128(_mm_cmplt_epi32(lhs, rhs), _mm_cmpeq_epi32(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu32x4 le_vu32x4(const vu32x4 lhs,const vu32x4 rhs) { return _mm_or_si128(_mm_cmplt_epi32(lhs, rhs), _mm_cmpeq_epi32(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vf64x2 le_vf64x2(const vf64x2 lhs,const vf64x2 rhs) { return _mm_cmple_pd   (lhs, rhs); }
// ge
CVEC_FORCE_INLINE mask_vi8x16 ge_vi8x16(const vi8x16 lhs,const vi8x16 rhs) { return _mm_or_si128(_mm_cmplt_epi8 (rhs, lhs), _mm_cmpeq_epi8 (lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu8x16 ge_vu8x16(const vu8x16 lhs,const vu8x16 rhs) { return _mm_or_si128(_mm_cmplt_epi8 (rhs, lhs), _mm_cmpeq_epi8 (lhs, rhs)); }
CVEC_FORCE_INLINE mask_vi16x8 ge_vi16x8(const vi16x8 lhs,const vi16x8 rhs) { return _mm_or_si128(_mm_cmplt_epi16(rhs, lhs), _mm_cmpeq_epi16(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu16x8 ge_vu16x8(const vu16x8 lhs,const vu16x8 rhs) { return _mm_or_si128(_mm_cmplt_epi16(rhs, lhs), _mm_cmpeq_epi16(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vi32x4 ge_vi32x4(const vi32x4 lhs,const vi32x4 rhs) { return _mm_or_si128(_mm_cmplt_epi32(rhs, lhs), _mm_cmpeq_epi32(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu32x4 ge_vu32x4(const vu32x4 lhs,const vu32x4 rhs) { return _mm_or_si128(_mm_cmplt_epi32(rhs, lhs), _mm_cmpeq_epi32(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vf64x2 ge_vf64x2(const vf64x2 lhs,const vf64x2 rhs) { return _mm_cmpge_pd   (lhs, rhs); }
// iszero
CVEC_FORCE_INLINE mask_vi8x16 iszero_vi8x16(const vi8x16 rhs) { return _mm_cmpeq_epi8 (_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vu8x16 iszero_vu8x16(const vu8x16 rhs) { return _mm_cmpeq_epi8 (_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vi16x8 iszero_vi16x8(const vi16x8 rhs) { return _mm_cmpeq_epi16(_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vu16x8 iszero_vu16x8(const vu16x8 rhs) { return _mm_cmpeq_epi16(_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vi32x4 iszero_vi32x4(const vi32x4 rhs) { return _mm_cmpeq_epi32(_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vu32x4 iszero_vu32x4(const vu32x4 rhs) { return _mm_cmpeq_epi32(_mm_setzero_si128(),rhs); }
CVEC_FORCE_INLINE mask_vf64x2 iszero_vf64x2(const vf64x2 rhs) { return _mm_cmpeq_pd   (_mm_setzero_pd   (),rhs); }
// isnan
CVEC_FORCE_INLINE mask_vf64x2 isnan_vf64x2(const vf64x2 rhs) { return _mm_cmpunord_pd(rhs, _mm_setzero_pd()); }

// cast2mask
CVEC_FORCE_INLINE smask16 cast2mask_vi8x16(const vi8x16 rhs) { return _mm_movemask_epi8(rhs); }
CVEC_FORCE_INLINE smask16 cast2mask_vu8x16(const vu8x16 rhs) { return _mm_movemask_epi8(rhs); }
CVEC_FORCE_INLINE smask4  cast2mask_vi32x4(const vi32x4 rhs) { return _mm_movemask_ps(_mm_castsi128_ps(rhs)); }
CVEC_FORCE_INLINE smask4  cast2mask_vu32x4(const vu32x4 rhs) { return _mm_movemask_ps(_mm_castsi128_ps(rhs)); }
CVEC_FORCE_INLINE smask2  cast2mask_vi64x2(const vi64x2 rhs) { return _mm_movemask_pd(_mm_castsi128_pd(rhs)); }
CVEC_FORCE_INLINE smask2  cast2mask_vu64x2(const vu64x2 rhs) { return _mm_movemask_pd(_mm_castsi128_pd(rhs)); }
CVEC_FORCE_INLINE smask2  cast2mask_vf64x2(const vf64x2 rhs) { return _mm_movemask_pd(rhs); }

#endif
