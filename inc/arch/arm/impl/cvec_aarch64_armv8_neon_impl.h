#include <arm_neon.h>
#include <stdint.h>

/// aligned_malloc / free
/// load / store instructions
// setzero
 CVEC_FORCE_INLINE v64 setzero_vf64(){ return vdupq_n_f64(0.0); }
// set1
 CVEC_FORCE_INLINE vf64 set1_vf64(const   double scalar){ return vdupq_n_f64(scalar); }
// aligned load
 CVEC_FORCE_INLINE vf64 load_vf64(const void* addr){ return vld1q_f64(addr); }
// unaligned load
 CVEC_FORCE_INLINE vf64 loadu_vf64(const void* addr){ return vld1q_f64(addr); }
// aligned store
 CVEC_FORCE_INLINE void store_vf64(const vf64 v, void* addr){ return vst1q_f64(addr, v); }
// unaligned store
 CVEC_FORCE_INLINE void storeu_vf64(const vf64 v, void* addr){ return vst1q_f64(addr, v); }

/// arithmetic instructions
// add
 CVEC_FORCE_INLINE vf64 add_vf64(const vf64 lhs, const vf64 rhs){ return vaddq_f64(lhs, rhs); }
// sub
 CVEC_FORCE_INLINE vf64 sub_vf64(const vf64 lhs, const vf64 rhs){ return vsubq_f64(lhs, rhs); }
// mul
 CVEC_FORCE_INLINE vf64 mul_vf64(const vf64 lhs, const vf64 rhs){ return vmulq_f64(lhs, rhs); }
// div
 CVEC_FORCE_INLINE vf32 div_vf32(const vf32 lhs, const vf32 rhs){ return vdivq_f32(lhs, rhs); }
 CVEC_FORCE_INLINE vf64 div_vf64(const vf64 lhs, const vf64 rhs){ return vdivq_f64(lhs, rhs); }
// max
 CVEC_FORCE_INLINE vf64 max_vf64(const vf64 lhs, const vf64 rhs){ return vmaxq_f64(lhs, rhs); }
// min
 CVEC_FORCE_INLINE vf64 min_vf64(const vf64 lhs, const vf64 rhs){ return vminq_f64(lhs, rhs); }

/// elementary math functions
// reciprocal estimation
 CVEC_FORCE_INLINE vf64 rcp_vf64(const vf64 rhs){
     // need to evaluate !!
     vf64 recp = vrecpe_f64(rhs);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     recp = vmulq_f64(vrecpsq_f64(rhs, recp), recp);
     return recp;
 }

/// bit manipulation
// or
 CVEC_FORCE_INLINE vf64 or_vf64(const vf64 lhs, const vf64 rhs){ return vreinterpretq_f64_s8(vorrq_s8(vreinterpretq_s8_f64(lhs), vreinterpretq_s8_f64(rhs))); }
// and
 CVEC_FORCE_INLINE vf64 and_vf64(const vf64 lhs, const vf64 rhs){ return vreinterpretq_f64_s8(vandq_s8(vreinterpretq_s8_f64(lhs), vreinterpretq_s8_f64(rhs))); }
// not
 CVEC_FORCE_INLINE vf64 not_vf64(const vf64 rhs){ return vreinterpretq_f64_s8(vmvnq_s8(vreinterpretq_s8_f64(rhs))); }
// xor
 CVEC_FORCE_INLINE vf64 xor_vf64(const vf64 lhs, const vf64 rhs){ return vreinterpretq_f64_s8(veorq_s8(vreinterpretq_s8_f64(lhs), vreinterpretq_s8_f64(rhs))); }
