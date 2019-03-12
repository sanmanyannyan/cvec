#include <xmmintrin.h>
#include <immintrin.h>
#include <stdint.h>

#define CVEC_VECTOR_SIZE ((size_t)(32))
#define MEMORY_ALIGNMENT 32u

AVX_TYPE_DECL(vi8 , __m256i);
AVX_TYPE_DECL(vu8 , __m256i);
AVX_TYPE_DECL(vi16, __m256i);
AVX_TYPE_DECL(vu16, __m256i);
AVX_TYPE_DECL(vi32, __m256i);
AVX_TYPE_DECL(vu32, __m256i);
AVX_TYPE_DECL(vi64, __m256i);
AVX_TYPE_DECL(vu64, __m256i);
AVX_TYPE_DECL(vflt, __m256 );
AVX_TYPE_DECL(vdbl, __m256d);

#define VI8_NUM_ELEMENT  (CVEC_VECTOR_SIZE / sizeof(  int8_t))
#define VU8_NUM_ELEMENT  (CVEC_VECTOR_SIZE / sizeof( uint8_t))
#define VI16_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int16_t))
#define VU16_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint16_t))
#define VI32_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int32_t))
#define VU32_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint32_t))
#define VI64_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof( int64_t))
#define VU64_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(uint64_t))
#define VFLT_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(   float))
#define VDBL_NUM_ELEMENT (CVEC_VECTOR_SIZE / sizeof(  double))

/// aligned_malloc / free
          AVX_FUNC_DECL(static inline void* amalloc(size_t size, size_t alignement));
          AVX_FUNC_DECL(static inline void  afree(void* addr));

/// load / store instructions
// setzero
          AVX_FUNC_DECL(static inline vi8  setzero_vi8() );
          AVX_FUNC_DECL(static inline vu8  setzero_vu8() );
          AVX_FUNC_DECL(static inline vi16 setzero_vi16());
          AVX_FUNC_DECL(static inline vu16 setzero_vu16());
          AVX_FUNC_DECL(static inline vi32 setzero_vi32());
          AVX_FUNC_DECL(static inline vu32 setzero_vu32());
          AVX_FUNC_DECL(static inline vi64 setzero_vi64());
          AVX_FUNC_DECL(static inline vu64 setzero_vu64());
          AVX_FUNC_DECL(static inline vflt setzero_vflt());
          AVX_FUNC_DECL(static inline vdbl setzero_vdbl());
// set1
          AVX_FUNC_DECL(static inline vi8  set1_vi8( const   int8_t scalar));
          AVX_FUNC_DECL(static inline vu8  set1_vu8( const  uint8_t scalar));
          AVX_FUNC_DECL(static inline vi16 set1_vi16(const  int16_t scalar));
          AVX_FUNC_DECL(static inline vu16 set1_vu16(const uint16_t scalar));
          AVX_FUNC_DECL(static inline vi32 set1_vi32(const  int32_t scalar));
          AVX_FUNC_DECL(static inline vu32 set1_vu32(const uint32_t scalar));
          AVX_FUNC_DECL(static inline vi64 set1_vi64(const  int64_t scalar));
          AVX_FUNC_DECL(static inline vu64 set1_vu64(const uint64_t scalar));
          AVX_FUNC_DECL(static inline vflt set1_vflt(const    float scalar));
          AVX_FUNC_DECL(static inline vdbl set1_vdbl(const   double scalar));
// aligned load
          AVX_FUNC_DECL(static inline vi8  load_vi8( void* addr));
          AVX_FUNC_DECL(static inline vu8  load_vu8( void* addr));
          AVX_FUNC_DECL(static inline vi16 load_vi16(void* addr));
          AVX_FUNC_DECL(static inline vu16 load_vu16(void* addr));
          AVX_FUNC_DECL(static inline vi32 load_vi32(void* addr));
          AVX_FUNC_DECL(static inline vu32 load_vu32(void* addr));
          AVX_FUNC_DECL(static inline vi64 load_vi64(void* addr));
          AVX_FUNC_DECL(static inline vu64 load_vu64(void* addr));
          AVX_FUNC_DECL(static inline vflt load_vflt(void* addr));
          AVX_FUNC_DECL(static inline vdbl load_vdbl(void* addr));
// unaligned load
          AVX_FUNC_DECL(static inline vi8  loadu_vi8( void* addr));
          AVX_FUNC_DECL(static inline vu8  loadu_vu8( void* addr));
          AVX_FUNC_DECL(static inline vi16 loadu_vi16(void* addr));
          AVX_FUNC_DECL(static inline vu16 loadu_vu16(void* addr));
          AVX_FUNC_DECL(static inline vi32 loadu_vi32(void* addr));
          AVX_FUNC_DECL(static inline vu32 loadu_vu32(void* addr));
          AVX_FUNC_DECL(static inline vi64 loadu_vi64(void* addr));
          AVX_FUNC_DECL(static inline vu64 loadu_vu64(void* addr));
          AVX_FUNC_DECL(static inline vflt loadu_vflt(void* addr));
          AVX_FUNC_DECL(static inline vdbl loadu_vdbl(void* addr));
// aligned store
          AVX_FUNC_DECL(static inline void store_vi8( const vi8  v, void* addr));
          AVX_FUNC_DECL(static inline void store_vu8( const vu8  v, void* addr));
          AVX_FUNC_DECL(static inline void store_vi16(const vi16 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vu16(const vu16 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vi32(const vi32 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vu32(const vu32 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vi64(const vi64 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vu64(const vu64 v, void* addr));
          AVX_FUNC_DECL(static inline void store_vflt(const vflt v, void* addr));
          AVX_FUNC_DECL(static inline void store_vdbl(const vdbl v, void* addr));
// unaligned store
          AVX_FUNC_DECL(static inline void storeu_vi8( const vi8  v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vu8( const vu8  v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vi16(const vi16 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vu16(const vu16 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vi32(const vi32 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vu32(const vu32 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vi64(const vi64 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vu64(const vu64 v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vflt(const vflt v, void* addr));
          AVX_FUNC_DECL(static inline void storeu_vdbl(const vdbl v, void* addr));


/// arithmetic instructions
// add
         AVX2_FUNC_DECL(static inline vi8  add_vi8( const vi8  lhs, const vi8  rhs));
         AVX2_FUNC_DECL(static inline vu8  add_vu8( const vu8  lhs, const vu8  rhs));
         AVX2_FUNC_DECL(static inline vi16 add_vi16(const vi16 lhs, const vi16 rhs));
         AVX2_FUNC_DECL(static inline vu16 add_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 add_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 add_vu32(const vu32 lhs, const vu32 rhs));
         AVX2_FUNC_DECL(static inline vi64 add_vi64(const vi64 lhs, const vi64 rhs));
         AVX2_FUNC_DECL(static inline vu64 add_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt add_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl add_vdbl(const vdbl lhs, const vdbl rhs));
// sub
         AVX2_FUNC_DECL(static inline vi8  sub_vi8( const vi8  lhs, const vi8  rhs));
         AVX2_FUNC_DECL(static inline vu8  sub_vu8( const vu8  lhs, const vu8  rhs));
         AVX2_FUNC_DECL(static inline vi16 sub_vi16(const vi16 lhs, const vi16 rhs));
         AVX2_FUNC_DECL(static inline vu16 sub_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 sub_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 sub_vu32(const vu32 lhs, const vu32 rhs));
         AVX2_FUNC_DECL(static inline vi64 sub_vi64(const vi64 lhs, const vi64 rhs));
         AVX2_FUNC_DECL(static inline vu64 sub_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt sub_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl sub_vdbl(const vdbl lhs, const vdbl rhs));
// mul
NOT_SUPPORTED_FUNC_DECL(static inline vi8  mul_vi8( const vi8  lhs, const vi8  rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu8  mul_vu8( const vu8  lhs, const vu8  rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi16 mul_vi16(const vi16 lhs, const vi16 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu16 mul_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 mul_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 mul_vu32(const vu32 lhs, const vu32 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi64 mul_vi64(const vi64 lhs, const vi64 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu64 mul_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt mul_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl mul_vdbl(const vdbl lhs, const vdbl rhs));
// div
NOT_SUPPORTED_FUNC_DECL(static inline vi8  div_vi8( const vi8  lhs, const vi8  rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu8  div_vu8( const vu8  lhs, const vu8  rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi16 div_vi16(const vi16 lhs, const vi16 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu16 div_vu16(const vu16 lhs, const vu16 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi32 div_vi32(const vi32 lhs, const vi32 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu32 div_vu32(const vu32 lhs, const vu32 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi64 div_vi64(const vi64 lhs, const vi64 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu64 div_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt div_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl div_vdbl(const vdbl lhs, const vdbl rhs));
// max
         AVX2_FUNC_DECL(static inline vi8  max_vi8( const vi8  lhs, const vi8  rhs));
         AVX2_FUNC_DECL(static inline vu8  max_vu8( const vu8  lhs, const vu8  rhs));
         AVX2_FUNC_DECL(static inline vi16 max_vi16(const vi16 lhs, const vi16 rhs));
         AVX2_FUNC_DECL(static inline vu16 max_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 max_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 max_vu32(const vu32 lhs, const vu32 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi64 max_vi64(const vi64 lhs, const vi64 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu64 max_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt max_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl max_vdbl(const vdbl lhs, const vdbl rhs));
// min
         AVX2_FUNC_DECL(static inline vi8  min_vi8( const vi8  lhs, const vi8  rhs));
         AVX2_FUNC_DECL(static inline vu8  min_vu8( const vu8  lhs, const vu8  rhs));
         AVX2_FUNC_DECL(static inline vi16 min_vi16(const vi16 lhs, const vi16 rhs));
         AVX2_FUNC_DECL(static inline vu16 min_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 min_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 min_vu32(const vu32 lhs, const vu32 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vi64 min_vi64(const vi64 lhs, const vi64 rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vu64 min_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt min_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl min_vdbl(const vdbl lhs, const vdbl rhs));

/// elementary math functions
// reciprocal estimation
          AVX_FUNC_DECL(static inline vflt rcp_vflt(const vflt lhs, const vflt rhs));
NOT_SUPPORTED_FUNC_DECL(static inline vdbl rcp_vdbl(const vdbl lhs, const vdbl rhs));

/// bit manipulation
// or
          AVX_FUNC_DECL(static inline vi8  or_vi8( const vi8  lhs, const vi8  rhs));
          AVX_FUNC_DECL(static inline vu8  or_vu8( const vu8  lhs, const vu8  rhs));
          AVX_FUNC_DECL(static inline vi16 or_vi16(const vi16 lhs, const vi16 rhs));
          AVX_FUNC_DECL(static inline vu16 or_vu16(const vu16 lhs, const vu16 rhs));
          AVX_FUNC_DECL(static inline vi32 or_vi32(const vi32 lhs, const vi32 rhs));
          AVX_FUNC_DECL(static inline vu32 or_vu32(const vu32 lhs, const vu32 rhs));
          AVX_FUNC_DECL(static inline vi64 or_vi64(const vi64 lhs, const vi64 rhs));
          AVX_FUNC_DECL(static inline vu64 or_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt or_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl or_vdbl(const vdbl lhs, const vdbl rhs));
// and
         AVX2_FUNC_DECL(static inline vi8  and_vi8( const vi8  lhs, const vi8  rhs));
         AVX2_FUNC_DECL(static inline vu8  and_vu8( const vu8  lhs, const vu8  rhs));
         AVX2_FUNC_DECL(static inline vi16 and_vi16(const vi16 lhs, const vi16 rhs));
         AVX2_FUNC_DECL(static inline vu16 and_vu16(const vu16 lhs, const vu16 rhs));
         AVX2_FUNC_DECL(static inline vi32 and_vi32(const vi32 lhs, const vi32 rhs));
         AVX2_FUNC_DECL(static inline vu32 and_vu32(const vu32 lhs, const vu32 rhs));
         AVX2_FUNC_DECL(static inline vi64 and_vi64(const vi64 lhs, const vi64 rhs));
         AVX2_FUNC_DECL(static inline vu64 and_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt and_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl and_vdbl(const vdbl lhs, const vdbl rhs));
// not
          AVX_FUNC_DECL(static inline vi8  not_vi8( const vi8  rhs));
          AVX_FUNC_DECL(static inline vu8  not_vu8( const vu8  rhs));
          AVX_FUNC_DECL(static inline vi16 not_vi16(const vi16 rhs));
          AVX_FUNC_DECL(static inline vu16 not_vu16(const vu16 rhs));
          AVX_FUNC_DECL(static inline vi32 not_vi32(const vi32 rhs));
          AVX_FUNC_DECL(static inline vu32 not_vu32(const vu32 rhs));
          AVX_FUNC_DECL(static inline vi64 not_vi64(const vi64 rhs));
          AVX_FUNC_DECL(static inline vu64 not_vu64(const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt not_vflt(const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl not_vdbl(const vdbl rhs));
// xor
          AVX_FUNC_DECL(static inline vi8  xor_vi8( const vi8  lhs, const vi8  rhs));
          AVX_FUNC_DECL(static inline vu8  xor_vu8( const vu8  lhs, const vu8  rhs));
          AVX_FUNC_DECL(static inline vi16 xor_vi16(const vi16 lhs, const vi16 rhs));
          AVX_FUNC_DECL(static inline vu16 xor_vu16(const vu16 lhs, const vu16 rhs));
          AVX_FUNC_DECL(static inline vi32 xor_vi32(const vi32 lhs, const vi32 rhs));
          AVX_FUNC_DECL(static inline vu32 xor_vu32(const vu32 lhs, const vu32 rhs));
          AVX_FUNC_DECL(static inline vi64 xor_vi64(const vi64 lhs, const vi64 rhs));
          AVX_FUNC_DECL(static inline vu64 xor_vu64(const vu64 lhs, const vu64 rhs));
          AVX_FUNC_DECL(static inline vflt xor_vflt(const vflt lhs, const vflt rhs));
          AVX_FUNC_DECL(static inline vdbl xor_vdbl(const vdbl lhs, const vdbl rhs));
