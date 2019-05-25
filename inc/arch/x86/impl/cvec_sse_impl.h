#include <xmmintrin.h>
#include <stdint.h>

/// aligned_malloc / free
CVEC_FORCE_INLINE void* amalloc(size_t size, size_t alignement){ return _mm_malloc(size, alignement); }
CVEC_FORCE_INLINE void  afree(void* addr){ _mm_free(addr); }

/// load / store instructions
// setzero
CVEC_FORCE_INLINE vf32x4 setzero_vf32x4() { return _mm_setzero_ps(); }
// set1
CVEC_FORCE_INLINE vf32x4 set1_vf32x4(const float scalar) { return _mm_set1_ps(scalar); }
// aligned load
CVEC_FORCE_INLINE vf32x4 load_vf32x4(void* addr) { return _mm_load_ps(addr);  }
// unaligned load
CVEC_FORCE_INLINE vf32x4 loadu_vf32x4(void* addr) { return _mm_loadu_ps(addr); }
// aligned store
CVEC_FORCE_INLINE void store_vf32x4(const vf32x4 v, void* addr) { _mm_store_ps(addr, v); }
// unaligned store
CVEC_FORCE_INLINE void storeu_vf32x4(const vf32x4 v, void* addr) { _mm_storeu_ps(addr, v); }
// extract scalar
CVEC_FORCE_INLINE    float at_vf32x4(const vf32x4 v, size_t lane) { assert(lane < VF32X4_NUM_ELEMENT); return ((const    float*)& v)[lane]; }


/// arithmetic instructions
// add
CVEC_FORCE_INLINE vf32x4 add_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_add_ps(lhs, rhs); }
// sub
CVEC_FORCE_INLINE vf32x4 sub_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_sub_ps(lhs, rhs); }
// mul
CVEC_FORCE_INLINE vf32x4 mul_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_mul_ps(lhs, rhs); }
// div
CVEC_FORCE_INLINE vf32x4 div_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_div_ps(lhs, rhs); }
// max
CVEC_FORCE_INLINE vf32x4 max_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_max_ps(lhs, rhs); }
// min
CVEC_FORCE_INLINE vf32x4 min_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_min_ps(lhs, rhs); }

/// elementary math functions
// reciprocal estimation
CVEC_FORCE_INLINE vf32x4 arcp_vf32x4(const vf32x4 rhs) { return _mm_rcp_ps(rhs); }
// sqrt
CVEC_FORCE_INLINE vf32x4 sqrt_vf32x4(const vf32x4 rhs) { return _mm_sqrt_ps(rhs); }

/// bit manipulation
// or
CVEC_FORCE_INLINE vf32x4 or_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_or_ps(lhs, rhs); }
// and
CVEC_FORCE_INLINE vf32x4 and_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_and_ps(lhs, rhs); }
// not
CVEC_FORCE_INLINE vf32x4 not_vf32x4(const vf32x4 rhs) { vf32x4 tmp = _mm_undefined_ps(); return _mm_andnot_ps(rhs, _mm_cmpeq_ps(tmp, tmp) ); }
// xor
CVEC_FORCE_INLINE vf32x4 xor_vf32x4(const vf32x4 lhs, const vf32x4 rhs) { return _mm_xor_ps(lhs, rhs); }
