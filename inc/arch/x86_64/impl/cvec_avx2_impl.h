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
// sub
// mul
// div
// max
// min

/// bit manipulation
// or
static inline vi8  or_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vu8  or_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vi16 or_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vu16 or_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vi32 or_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vu32 or_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vi64 or_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vu64 or_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_or_si256(lhs, rhs); }
static inline vflt or_vflt(const vflt lhs, const vflt rhs){ return _mm256_castsi256_ps(_mm256_or_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
static inline vdbl or_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_castsi256_pd(_mm256_or_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// and
static inline vi8  and_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vu8  and_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vi16 and_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vu16 and_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vi32 and_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vu32 and_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vi64 and_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vu64 and_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_and_si256(lhs, rhs); }
static inline vflt and_vflt(const vflt lhs, const vflt rhs){ return _mm256_castsi256_ps(_mm256_and_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
static inline vdbl and_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_castsi256_pd(_mm256_and_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
// not
static inline vi8  not_vi8( const vi8  rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vu8  not_vu8( const vu8  rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vi16 not_vi16(const vi16 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vu16 not_vu16(const vu16 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vi32 not_vi32(const vi32 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vu32 not_vu32(const vu32 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vi64 not_vi64(const vi64 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vu64 not_vu64(const vu64 rhs){ return _mm256_xor_si256(rhs, _mm256_set1_epi32(~((int)0))); }
static inline vflt not_vflt(const vflt rhs){ return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
static inline vdbl not_vdbl(const vdbl rhs){ return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(rhs), _mm256_set1_epi32(~((int)0)))); }
// xor
static inline vi8  xor_vi8( const vi8  lhs, const vi8  rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vu8  xor_vu8( const vu8  lhs, const vu8  rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vi16 xor_vi16(const vi16 lhs, const vi16 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vu16 xor_vu16(const vu16 lhs, const vu16 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vi32 xor_vi32(const vi32 lhs, const vi32 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vu32 xor_vu32(const vu32 lhs, const vu32 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vi64 xor_vi64(const vi64 lhs, const vi64 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vu64 xor_vu64(const vu64 lhs, const vu64 rhs){ return _mm256_xor_si256(rhs, lhs); }
static inline vflt xor_vflt(const vflt lhs, const vflt rhs){ return _mm256_castsi256_ps(_mm256_xor_si256(_mm256_castps_si256(lhs), _mm256_castps_si256(rhs))); }
static inline vdbl xor_vdbl(const vdbl lhs, const vdbl rhs){ return _mm256_castsi256_pd(_mm256_xor_si256(_mm256_castpd_si256(lhs), _mm256_castpd_si256(rhs))); }
