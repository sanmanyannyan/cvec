#ifndef CVEC_SSE4_1_IMPL_H
#define CVEC_SSE4_1_IMPL_H

#include <smmintrin.h>

/// aligned_malloc / free

/// load / store instructions
// setzero
// set1
// aligned load
// unaligned load
// aligned store
// unaligned store
// extract scalar


/// arithmetic instructions
// add
// sub
// mul
CVEC_FORCE_INLINE vi32x4 mul_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_mullo_epi32(lhs, rhs); }
// div
// max
CVEC_FORCE_INLINE vi8x16 max_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_max_epi8 (lhs, rhs); }
CVEC_FORCE_INLINE vu16x8 max_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_max_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x4 max_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_max_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x4 max_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_max_epu32(lhs, rhs); }
// min
CVEC_FORCE_INLINE vi8x16 min_vi8x16(const vi8x16 lhs, const vi8x16 rhs) { return _mm_min_epi8(lhs, rhs); }
CVEC_FORCE_INLINE vu16x8 min_vu16x8(const vu16x8 lhs, const vu16x8 rhs) { return _mm_min_epu16(lhs, rhs); }
CVEC_FORCE_INLINE vi32x4 min_vi32x4(const vi32x4 lhs, const vi32x4 rhs) { return _mm_min_epi32(lhs, rhs); }
CVEC_FORCE_INLINE vu32x4 min_vu32x4(const vu32x4 lhs, const vu32x4 rhs) { return _mm_min_epu32(lhs, rhs); }

/// bit manipulation
// or
// and
// not
// xor

/// Swizzle
// blend
CVEC_FORCE_INLINE vi8x16 blend_vi8x16(const vi8x16 lhs, const vi8x16 rhs, mask_vi8x16 mask) { return _mm_blendv_epi8(lhs, rhs, mask); }
CVEC_FORCE_INLINE vu8x16 blend_vu8x16(const vu8x16 lhs, const vu8x16 rhs, mask_vu8x16 mask) { return _mm_blendv_epi8(lhs, rhs, mask); }
CVEC_FORCE_INLINE vf32x4 blend_vf32x4(const vf32x4 lhs, const vf32x4 rhs, mask_vf32x4 mask) { return _mm_blendv_ps  (lhs, rhs, mask); }
CVEC_FORCE_INLINE vf64x2 blend_vf64x2(const vf64x2 lhs, const vf64x2 rhs, mask_vf64x2 mask) { return _mm_blendv_pd  (lhs, rhs, mask); }

/// mask
// eq
CVEC_FORCE_INLINE mask_vi64x2 eq_vi64x2(const vi64x2 lhs,const vi64x2 rhs) { return _mm_cmpeq_epi64(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu64x2 eq_vu64x2(const vu64x2 lhs,const vu64x2 rhs) { return _mm_cmpeq_epi64(lhs, rhs); }
// neq
CVEC_FORCE_INLINE mask_vi64x2 neq_vi64x2(const vi64x2 lhs,const vi64x2 rhs) { return not_vi64x2(_mm_cmpeq_epi64(rhs, lhs)); }
CVEC_FORCE_INLINE mask_vu64x2 neq_vu64x2(const vu64x2 lhs,const vu64x2 rhs) { return not_vu64x2(_mm_cmpeq_epi64(rhs, lhs)); }
// iszero
CVEC_FORCE_INLINE mask_vi64x2 iszero_vi64x2(const vi64x2 rhs) { return _mm_cmpeq_epi64(rhs, _mm_setzero_si128()); }
CVEC_FORCE_INLINE mask_vu64x2 iszero_vu64x2(const vu64x2 rhs) { return _mm_cmpeq_epi64(rhs, _mm_setzero_si128()); }

#endif
