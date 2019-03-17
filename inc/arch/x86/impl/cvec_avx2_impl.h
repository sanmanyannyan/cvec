#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

/// aligned_malloc / free
/// load / store instructions
// setzero
// set1
// aligned load
// unaligned load
// aligned store
// unaligned store


/// arithmetic instructions
// add
CVEC_FORCE_INLINE vi8  add_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_add_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8  add_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_add_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16 add_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16 add_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32 add_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32 add_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64 add_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_add_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64 add_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_add_epi64(lhs, rhs); }

// sub
CVEC_FORCE_INLINE vi8  sub_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_sub_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8  sub_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_sub_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16 sub_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16 sub_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32 sub_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32 sub_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64 sub_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_sub_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64 sub_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_sub_epi64(lhs, rhs); }

// mul
CVEC_FORCE_INLINE vi32 mul_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_mul_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32 mul_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_mul_epu32(lhs, rhs); }

// div
// max
CVEC_FORCE_INLINE vi8  max_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_max_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8  max_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_max_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16 max_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_max_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16 max_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_max_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32 max_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_max_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32 max_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_max_epu32(lhs, rhs); }

// min
CVEC_FORCE_INLINE vi8  min_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_min_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8  min_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_min_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16 min_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_min_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16 min_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_min_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32 min_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_min_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32 min_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_min_epu32(lhs, rhs); }

/// bit manipulation
// or
CVEC_FORCE_INLINE vi8  or_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu8  or_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi16 or_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu16 or_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi32 or_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu32 or_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi64 or_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu64 or_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vf32 or_vf32(const vf32 lhs, const vf32 rhs){ return _mm256_castsi256_ps(_mm256_or_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64 or_vf64(const vf64 lhs, const vf64 rhs){ return _mm256_castsi256_pd(_mm256_or_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// and
CVEC_FORCE_INLINE vi8  and_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu8  and_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi16 and_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu16 and_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi32 and_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu32 and_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi64 and_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu64 and_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vf32 and_vf32(const vf32 lhs, const vf32 rhs){ return _mm256_castsi256_ps(_mm256_and_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64 and_vf64(const vf64 lhs, const vf64 rhs){ return _mm256_castsi256_pd(_mm256_and_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// not
CVEC_FORCE_INLINE vi8  not_vi8 (const vi8  rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu8  not_vu8 (const vu8  rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi16 not_vi16(const vi16 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu16 not_vu16(const vu16 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi32 not_vi32(const vi32 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu32 not_vu32(const vu32 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi64 not_vi64(const vi64 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu64 not_vu64(const vu64 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vf32 not_vf32(const vf32 rhs){ return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
CVEC_FORCE_INLINE vf64 not_vf64(const vf64 rhs){ return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
// xor
CVEC_FORCE_INLINE vi8  xor_vi8 (const vi8  lhs, const vi8  rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu8  xor_vu8 (const vu8  lhs, const vu8  rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi16 xor_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu16 xor_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi32 xor_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu32 xor_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi64 xor_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu64 xor_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vf32 xor_vf32(const vf32 lhs, const vf32 rhs){ return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64 xor_vf64(const vf64 lhs, const vf64 rhs){ return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
