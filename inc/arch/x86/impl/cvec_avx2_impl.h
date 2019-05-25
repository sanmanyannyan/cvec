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
CVEC_FORCE_INLINE vi8x32  add_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_add_epi8(lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  add_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_add_epi8(lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 add_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 add_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_add_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  add_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  add_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_add_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64x4  add_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_add_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64x4  add_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_add_epi64(lhs, rhs); }

// sub
CVEC_FORCE_INLINE vi8x32  sub_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_sub_epi8(lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  sub_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_sub_epi8(lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 sub_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 sub_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_sub_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  sub_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  sub_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_sub_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vi64x4  sub_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_sub_epi64(lhs, rhs); }
CVEC_FORCE_INLINE vu64x4  sub_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_sub_epi64(lhs, rhs); }

// mul
CVEC_FORCE_INLINE vi16x16 mul_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_mullo_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  mul_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_mullo_epi32(lhs, rhs); }

// div
// max
CVEC_FORCE_INLINE vi8x32  max_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_max_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  max_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_max_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 max_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_max_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 max_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_max_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  max_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_max_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  max_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_max_epu32(lhs, rhs); }

// min
CVEC_FORCE_INLINE vi8x32  min_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_min_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  min_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_min_epu8 (lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 min_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_min_epi16(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 min_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_min_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  min_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_min_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  min_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_min_epu32(lhs, rhs); }

/// bit manipulation
// or
CVEC_FORCE_INLINE vi8x32  or_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  or_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 or_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 or_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  or_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  or_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi64x4  or_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu64x4  or_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_or_si256(lhs, rhs); }
CVEC_FORCE_INLINE vf32x8  or_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_castsi256_ps(_mm256_or_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64x4  or_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_castsi256_pd(_mm256_or_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// and
CVEC_FORCE_INLINE vi8x32  and_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu8x32  and_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi16x16 and_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu16x16 and_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi32x8  and_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu32x8  and_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vi64x4  and_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vu64x4  and_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_and_si256(lhs, rhs); }
CVEC_FORCE_INLINE vf32x8  and_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_castsi256_ps(_mm256_and_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64x4  and_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_castsi256_pd(_mm256_and_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// not
CVEC_FORCE_INLINE vi8x32  not_vi8x32 (const vi8x32  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu8x32  not_vu8x32 (const vu8x32  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi16x16 not_vi16x16(const vi16x16 rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu16x16 not_vu16x16(const vu16x16 rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi32x8  not_vi32x8 (const vi32x8  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu32x8  not_vu32x8 (const vu32x8  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vi64x4  not_vi64x4 (const vi64x4  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vu64x4  not_vu64x4 (const vu64x4  rhs) { return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
CVEC_FORCE_INLINE vf32x8  not_vf32x8 (const vf32x8  rhs) { return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
CVEC_FORCE_INLINE vf64x4  not_vf64x4 (const vf64x4  rhs) { return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
// xor
CVEC_FORCE_INLINE vi8x32  xor_vi8x32 (const vi8x32  lhs, const vi8x32  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu8x32  xor_vu8x32 (const vu8x32  lhs, const vu8x32  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi16x16 xor_vi16x16(const vi16x16 lhs, const vi16x16 rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu16x16 xor_vu16x16(const vu16x16 lhs, const vu16x16 rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi32x8  xor_vi32x8 (const vi32x8  lhs, const vi32x8  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu32x8  xor_vu32x8 (const vu32x8  lhs, const vu32x8  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vi64x4  xor_vi64x4 (const vi64x4  lhs, const vi64x4  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vu64x4  xor_vu64x4 (const vu64x4  lhs, const vu64x4  rhs) { return _mm256_xor_si256(rhs, lhs); }
CVEC_FORCE_INLINE vf32x8  xor_vf32x8 (const vf32x8  lhs, const vf32x8  rhs) { return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
CVEC_FORCE_INLINE vf64x4  xor_vf64x4 (const vf64x4  lhs, const vf64x4  rhs) { return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
