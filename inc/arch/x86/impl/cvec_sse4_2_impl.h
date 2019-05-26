#include <nmmintrin.h>
#include <stdint.h>

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
// div
// max
// min

/// bit manipulation
// or
// and
// not
// xor

/// Swizzle
// blend

/// mask
// eq
// neq
// lt
CVEC_FORCE_INLINE mask_vi64x2 lt_vi64x2(const vi64x2 lhs,const vi64x2 rhs) { return _mm_cmpgt_epi64(rhs, lhs); }
CVEC_FORCE_INLINE mask_vu64x2 lt_vu64x2(const vu64x2 lhs,const vu64x2 rhs) { return _mm_cmpgt_epi64(rhs, lhs); }
// gt
CVEC_FORCE_INLINE mask_vi64x2 gt_vi64x2(const vi64x2 lhs,const vi64x2 rhs) { return _mm_cmpgt_epi64(lhs, rhs); }
CVEC_FORCE_INLINE mask_vu64x2 gt_vu64x2(const vu64x2 lhs,const vu64x2 rhs) { return _mm_cmpgt_epi64(lhs, rhs); }
// le
CVEC_FORCE_INLINE mask_vi64x2 le_vi64x2(const vi64x2 lhs, const vi64x2 rhs) { return _mm_or_si128(_mm_cmpgt_epi64(rhs, lhs), _mm_cmpeq_epi64(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu64x2 le_vu64x2(const vu64x2 lhs, const vu64x2 rhs) { return _mm_or_si128(_mm_cmpgt_epi64(rhs, lhs), _mm_cmpeq_epi64(lhs, rhs)); }
// ge
CVEC_FORCE_INLINE mask_vi64x2 ge_vi64x2(const vi64x2 lhs,const vi64x2 rhs) { return _mm_or_si128( _mm_cmpgt_epi64(lhs, rhs), _mm_cmpeq_epi64(lhs, rhs)); }
CVEC_FORCE_INLINE mask_vu64x2 ge_vu64x2(const vu64x2 lhs,const vu64x2 rhs) { return _mm_or_si128(_mm_cmpgt_epi64(lhs, rhs), _mm_cmpeq_epi64(lhs, rhs)); }
// iszero
// isnan

// cast2mask
