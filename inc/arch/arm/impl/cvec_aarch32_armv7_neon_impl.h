#include <stdlib.h>
#include <stdint.h>

/// aligned_malloc / free
 CVEC_FORCE_INLINE void* amalloc(size_t size, size_t alignement){
#if __STDC_VERSION__ >= 201112L
    return aligned_alloc(alignement, size);
#else
    void* ptr = malloc(size + 2 * MEMORY_ALIGNMENT;
    void* aligned_ptr;
    uintptr_t tmp;
    if ((tmp = (uintptr_t)ptr) & (MEMORY_ALIGNMENT) ){
        uintptr_t remainder = tmp % MEMORY_ALIGNMENT;
        aligned_ptr = ptr + MEMORY_ALIGNMENT - remainder;
        if ( MEMORY_ALIGNMENT - remainder < sizeof(uintptr_t) ){
          aligned_ptr += MEMORY_ALIGNMENT;
        }
        *(aligned_ptr - sizeof(uintptr_t)) = (uintptr_t)ptr;
    } else {
        aligned_ptr = ptr + MEMORY_ALIGNMENT;
        *(aligned_ptr - sizeof(uintptr_t)) = (uintptr_t)ptr;
    }
    return aligned_ptr;
#endif
 }
 CVEC_FORCE_INLINE void  afree(void* addr){
#if __STDC_VERSION__ >= 201112L
    free(addr);
#else
    uintptr_t free_ptr = *((uintptr_t *)(free_ptr - sizeof(uintptr_t)));
    free((void*)free_ptr);
#endif
 }

/// load / store instructions
// setzero
 CVEC_FORCE_INLINE  vi8 setzero_vi8 (){return vdupq_n_s8 (0  );}
 CVEC_FORCE_INLINE  vu8 setzero_vu8 (){return vdupq_n_u8 (0  );}
 CVEC_FORCE_INLINE vi16 setzero_vi16(){return vdupq_n_s16(0  );}
 CVEC_FORCE_INLINE vu16 setzero_vu16(){return vdupq_n_u16(0  );}
 CVEC_FORCE_INLINE vi32 setzero_vi32(){return vdupq_n_s32(0  );}
 CVEC_FORCE_INLINE vu32 setzero_vu32(){return vdupq_n_u32(0  );}
 CVEC_FORCE_INLINE vi64 setzero_vi64(){return vdupq_n_s64(0  );}
 CVEC_FORCE_INLINE vu64 setzero_vu64(){return vdupq_n_u64(0  );}
 CVEC_FORCE_INLINE vf32 setzero_vf32(){return vdupq_n_f32(0.f);}
// set1
 CVEC_FORCE_INLINE  vi8 set1_vi8 (const   int8_t scalar){return vdupq_n_s8 (scalar);}
 CVEC_FORCE_INLINE  vu8 set1_vu8 (const  uint8_t scalar){return vdupq_n_u8 (scalar);}
 CVEC_FORCE_INLINE vi16 set1_vi16(const  int16_t scalar){return vdupq_n_s16(scalar);}
 CVEC_FORCE_INLINE vu16 set1_vu16(const uint16_t scalar){return vdupq_n_u16(scalar);}
 CVEC_FORCE_INLINE vi32 set1_vi32(const  int32_t scalar){return vdupq_n_s32(scalar);}
 CVEC_FORCE_INLINE vu32 set1_vu32(const uint32_t scalar){return vdupq_n_u32(scalar);}
 CVEC_FORCE_INLINE vi64 set1_vi64(const  int64_t scalar){return vdupq_n_s64(scalar);}
 CVEC_FORCE_INLINE vu64 set1_vu64(const uint64_t scalar){return vdupq_n_u64(scalar);}
 CVEC_FORCE_INLINE vf32 set1_vf32(const    float scalar){return vdupq_n_f32(scalar);}
// aligned load
 CVEC_FORCE_INLINE vi8  load_vi8 (const void* addr){return vld1q_s8 (addr);}
 CVEC_FORCE_INLINE vu8  load_vu8 (const void* addr){return vld1q_u8 (addr);}
 CVEC_FORCE_INLINE vi16 load_vi16(const void* addr){return vld1q_s16(addr);}
 CVEC_FORCE_INLINE vu16 load_vu16(const void* addr){return vld1q_u16(addr);}
 CVEC_FORCE_INLINE vi32 load_vi32(const void* addr){return vld1q_s32(addr);}
 CVEC_FORCE_INLINE vu32 load_vu32(const void* addr){return vld1q_u32(addr);}
 CVEC_FORCE_INLINE vi64 load_vi64(const void* addr){return vld1q_s64(addr);}
 CVEC_FORCE_INLINE vu64 load_vu64(const void* addr){return vld1q_u64(addr);}
 CVEC_FORCE_INLINE vf32 load_vf32(const void* addr){return vld1q_f32(addr);}
// unaligned load
 CVEC_FORCE_INLINE vi8  loadu_vi8 (const void* addr){return vld1q_s8 (addr);}
 CVEC_FORCE_INLINE vu8  loadu_vu8 (const void* addr){return vld1q_u8 (addr);}
 CVEC_FORCE_INLINE vi16 loadu_vi16(const void* addr){return vld1q_s16(addr);}
 CVEC_FORCE_INLINE vu16 loadu_vu16(const void* addr){return vld1q_u16(addr);}
 CVEC_FORCE_INLINE vi32 loadu_vi32(const void* addr){return vld1q_s32(addr);}
 CVEC_FORCE_INLINE vu32 loadu_vu32(const void* addr){return vld1q_u32(addr);}
 CVEC_FORCE_INLINE vi64 loadu_vi64(const void* addr){return vld1q_s64(addr);}
 CVEC_FORCE_INLINE vu64 loadu_vu64(const void* addr){return vld1q_u64(addr);}
 CVEC_FORCE_INLINE vf32 loadu_vf32(const void* addr){return vld1q_f32(addr);}
// aligned store
 CVEC_FORCE_INLINE void store_vi8 (const vi8  v, void* addr){vst1q_s8 (addr, v);}
 CVEC_FORCE_INLINE void store_vu8 (const vu8  v, void* addr){vst1q_u8 (addr, v);}
 CVEC_FORCE_INLINE void store_vi16(const vi16 v, void* addr){vst1q_s16(addr, v);}
 CVEC_FORCE_INLINE void store_vu16(const vu16 v, void* addr){vst1q_u16(addr, v);}
 CVEC_FORCE_INLINE void store_vi32(const vi32 v, void* addr){vst1q_s32(addr, v);}
 CVEC_FORCE_INLINE void store_vu32(const vu32 v, void* addr){vst1q_u32(addr, v);}
 CVEC_FORCE_INLINE void store_vi64(const vi64 v, void* addr){vst1q_s64(addr, v);}
 CVEC_FORCE_INLINE void store_vu64(const vu64 v, void* addr){vst1q_u64(addr, v);}
 CVEC_FORCE_INLINE void store_vf32(const vf32 v, void* addr){vst1q_f32(addr, v);}
// unaligned store
 CVEC_FORCE_INLINE void storeu_vi8 (const vi8  v, void* addr){vst1q_s8 (addr, v);}
 CVEC_FORCE_INLINE void storeu_vu8 (const vu8  v, void* addr){vst1q_u8 (addr, v);}
 CVEC_FORCE_INLINE void storeu_vi16(const vi16 v, void* addr){vst1q_s16(addr, v);}
 CVEC_FORCE_INLINE void storeu_vu16(const vu16 v, void* addr){vst1q_u16(addr, v);}
 CVEC_FORCE_INLINE void storeu_vi32(const vi32 v, void* addr){vst1q_s32(addr, v);}
 CVEC_FORCE_INLINE void storeu_vu32(const vu32 v, void* addr){vst1q_u32(addr, v);}
 CVEC_FORCE_INLINE void storeu_vi64(const vi64 v, void* addr){vst1q_s64(addr, v);}
 CVEC_FORCE_INLINE void storeu_vu64(const vu64 v, void* addr){vst1q_u64(addr, v);}
 CVEC_FORCE_INLINE void storeu_vf32(const vf32 v, void* addr){vst1q_f32(addr, v);}


/// arithmetic instructions
// add
 CVEC_FORCE_INLINE vi8  add_vi8 (const vi8  lhs, const vi8  rhs){return vaddq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  add_vu8 (const vu8  lhs, const vu8  rhs){return vaddq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 add_vi16(const vi16 lhs, const vi16 rhs){return vaddq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 add_vu16(const vu16 lhs, const vu16 rhs){return vaddq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 add_vi32(const vi32 lhs, const vi32 rhs){return vaddq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 add_vu32(const vu32 lhs, const vu32 rhs){return vaddq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 add_vi64(const vi64 lhs, const vi64 rhs){return vaddq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 add_vu64(const vu64 lhs, const vu64 rhs){return vaddq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 add_vf32(const vf32 lhs, const vf32 rhs){return vaddq_f32(lhs, rhs);}
// sub
 CVEC_FORCE_INLINE vi8  sub_vi8 (const vi8  lhs, const vi8  rhs){return vsubq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  sub_vu8 (const vu8  lhs, const vu8  rhs){return vsubq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 sub_vi16(const vi16 lhs, const vi16 rhs){return vsubq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 sub_vu16(const vu16 lhs, const vu16 rhs){return vsubq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 sub_vi32(const vi32 lhs, const vi32 rhs){return vsubq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 sub_vu32(const vu32 lhs, const vu32 rhs){return vsubq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 sub_vi64(const vi64 lhs, const vi64 rhs){return vsubq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 sub_vu64(const vu64 lhs, const vu64 rhs){return vsubq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 sub_vf32(const vf32 lhs, const vf32 rhs){return vsubq_f32(lhs, rhs);}
// mul
 CVEC_FORCE_INLINE vi8  mul_vi8 (const vi8  lhs, const vi8  rhs){return vmulq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  mul_vu8 (const vu8  lhs, const vu8  rhs){return vmulq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 mul_vi16(const vi16 lhs, const vi16 rhs){return vmulq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 mul_vu16(const vu16 lhs, const vu16 rhs){return vmulq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 mul_vi32(const vi32 lhs, const vi32 rhs){return vmulq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 mul_vu32(const vu32 lhs, const vu32 rhs){return vmulq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 mul_vi64(const vi64 lhs, const vi64 rhs){return vmulq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 mul_vu64(const vu64 lhs, const vu64 rhs){return vmulq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 mul_vf32(const vf32 lhs, const vf32 rhs){return vmulq_f32(lhs, rhs);}
// div
 // CVEC_FORCE_INLINE vi8  div_vi8( const vi8  lhs, const vi8  rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vu8  div_vu8( const vu8  lhs, const vu8  rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vi16 div_vi16(const vi16 lhs, const vi16 rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vu16 div_vu16(const vu16 lhs, const vu16 rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vi32 div_vi32(const vi32 lhs, const vi32 rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vu32 div_vu32(const vu32 lhs, const vu32 rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vi64 div_vi64(const vi64 lhs, const vi64 rhs){return vdivq_f32(lhs, rhs);}
 // CVEC_FORCE_INLINE vu64 div_vu64(const vu64 lhs, const vu64 rhs){return vdivq_f32(lhs, rhs);}
 #ifndef CVEC_AARCH64_NEON
 CVEC_FORCE_INLINE vf32 div_vf32(const vf32 lhs, const vf32 rhs){
     vf32 recp = vrecpe_f32(rhs);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     return vmulq_f32(lhs, recp);
 }
 #endif
// max
 CVEC_FORCE_INLINE vi8  max_vi8 (const vi8  lhs, const vi8  rhs){return vmaxq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  max_vu8 (const vu8  lhs, const vu8  rhs){return vmaxq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 max_vi16(const vi16 lhs, const vi16 rhs){return vmaxq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 max_vu16(const vu16 lhs, const vu16 rhs){return vmaxq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 max_vi32(const vi32 lhs, const vi32 rhs){return vmaxq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 max_vu32(const vu32 lhs, const vu32 rhs){return vmaxq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 max_vi64(const vi64 lhs, const vi64 rhs){return vmaxq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 max_vu64(const vu64 lhs, const vu64 rhs){return vmaxq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 max_vf32(const vf32 lhs, const vf32 rhs){return vmaxq_f32(lhs, rhs);}
// min
 CVEC_FORCE_INLINE vi8  min_vi8 (const vi8  lhs, const vi8  rhs){return vminq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  min_vu8 (const vu8  lhs, const vu8  rhs){return vminq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 min_vi16(const vi16 lhs, const vi16 rhs){return vminq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 min_vu16(const vu16 lhs, const vu16 rhs){return vminq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 min_vi32(const vi32 lhs, const vi32 rhs){return vminq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 min_vu32(const vu32 lhs, const vu32 rhs){return vminq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 min_vi64(const vi64 lhs, const vi64 rhs){return vminq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 min_vu64(const vu64 lhs, const vu64 rhs){return vminq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 min_vf32(const vf32 lhs, const vf32 rhs){return vminq_f32(lhs, rhs);}

/// elementary math functions
// reciprocal estimation
 CVEC_FORCE_INLINE vf32 rcp_vf32(const vf32 rhs){
     vf32 recp = vrecpe_f32(rhs);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     recp = vmulq_f32(vrecpsq_f32(rhs, recp), recp);
     return recp;
 }

/// bit manipulation
// or
 CVEC_FORCE_INLINE vi8  or_vi8 (const vi8  lhs, const vi8  rhs){return vorrq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  or_vu8 (const vu8  lhs, const vu8  rhs){return vorrq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 or_vi16(const vi16 lhs, const vi16 rhs){return vorrq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 or_vu16(const vu16 lhs, const vu16 rhs){return vorrq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 or_vi32(const vi32 lhs, const vi32 rhs){return vorrq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 or_vu32(const vu32 lhs, const vu32 rhs){return vorrq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 or_vi64(const vi64 lhs, const vi64 rhs){return vorrq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 or_vu64(const vu64 lhs, const vu64 rhs){return vorrq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 or_vf32(const vf32 lhs, const vf32 rhs){return vreinterpretq_f32_s8(vorrq_s8(vreinterpretq_s8_f32(lhs), vreinterpretq_s8_f32(rhs)));}
// and
 CVEC_FORCE_INLINE vi8  and_vi8 (const vi8  lhs, const vi8  rhs){return vandq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  and_vu8 (const vu8  lhs, const vu8  rhs){return vandq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 and_vi16(const vi16 lhs, const vi16 rhs){return vandq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 and_vu16(const vu16 lhs, const vu16 rhs){return vandq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 and_vi32(const vi32 lhs, const vi32 rhs){return vandq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 and_vu32(const vu32 lhs, const vu32 rhs){return vandq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 and_vi64(const vi64 lhs, const vi64 rhs){return vandq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 and_vu64(const vu64 lhs, const vu64 rhs){return vandq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 and_vf32(const vf32 lhs, const vf32 rhs){return vreinterpretq_f32_s8(vandq_s8(vreinterpretq_s8_f32(lhs), vreinterpretq_s8_f32(rhs)));}
// not
 CVEC_FORCE_INLINE vi8  not_vi8 (const vi8  rhs){return vmvnq_s8 (rhs);}
 CVEC_FORCE_INLINE vu8  not_vu8 (const vu8  rhs){return vmvnq_u8 (rhs);}
 CVEC_FORCE_INLINE vi16 not_vi16(const vi16 rhs){return vmvnq_s16(rhs);}
 CVEC_FORCE_INLINE vu16 not_vu16(const vu16 rhs){return vmvnq_u16(rhs);}
 CVEC_FORCE_INLINE vi32 not_vi32(const vi32 rhs){return vmvnq_s32(rhs);}
 CVEC_FORCE_INLINE vu32 not_vu32(const vu32 rhs){return vmvnq_u32(rhs);}
 CVEC_FORCE_INLINE vi64 not_vi64(const vi64 rhs){return vreinterpretq_s64_s8(vmvnq_s8(vreinterpretq_s8_s64(rhs)));}
 CVEC_FORCE_INLINE vu64 not_vu64(const vu64 rhs){return vreinterpretq_u64_s8(vmvnq_s8(vreinterpretq_s8_u64(rhs)));}
 CVEC_FORCE_INLINE vf32 not_vf32(const vf32 rhs){return vreinterpretq_f32_s8(vmvnq_s8(vreinterpretq_s8_f32(rhs)));}
// xor
 CVEC_FORCE_INLINE vi8  xor_vi8 (const vi8  lhs, const vi8  rhs){return veorq_s8 (lhs, rhs);}
 CVEC_FORCE_INLINE vu8  xor_vu8 (const vu8  lhs, const vu8  rhs){return veorq_u8 (lhs, rhs);}
 CVEC_FORCE_INLINE vi16 xor_vi16(const vi16 lhs, const vi16 rhs){return veorq_s16(lhs, rhs);}
 CVEC_FORCE_INLINE vu16 xor_vu16(const vu16 lhs, const vu16 rhs){return veorq_u16(lhs, rhs);}
 CVEC_FORCE_INLINE vi32 xor_vi32(const vi32 lhs, const vi32 rhs){return veorq_s32(lhs, rhs);}
 CVEC_FORCE_INLINE vu32 xor_vu32(const vu32 lhs, const vu32 rhs){return veorq_u32(lhs, rhs);}
 CVEC_FORCE_INLINE vi64 xor_vi64(const vi64 lhs, const vi64 rhs){return veorq_s64(lhs, rhs);}
 CVEC_FORCE_INLINE vu64 xor_vu64(const vu64 lhs, const vu64 rhs){return veorq_u64(lhs, rhs);}
 CVEC_FORCE_INLINE vf32 xor_vf32(const vf32 lhs, const vf32 rhs){return vreinterpretq_f32_s8(veorq_s8(vreinterpretq_s8_f32(rhs)));}
