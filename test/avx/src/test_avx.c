#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define RANDOM_TEST_DATA
#include "test_helpers.h"


#define CVEC256
#include "cvec.h"


int test_load_store(void) {
	uint8_t *td;
    td = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_256(td);
    vi8x32  tdvi8  = load_vi8x32 (td); vu8x32  tdvu8  = load_vu8x32 (td);
    vi16x16 tdvi16 = load_vi16x16(td); vu16x16 tdvu16 = load_vu16x16(td);
    vi32x8  tdvi32 = load_vi32x8 (td); vu32x8  tdvu32 = load_vu32x8 (td);
    vi64x4  tdvi64 = load_vi64x4 (td); vu64x4  tdvu64 = load_vu64x4 (td);
    vf32x8  tdvf32 = load_vf32x8 (td); vf64x4  tdvf64 = load_vf64x4 (td);
	int8_t  *buff_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint8_t  *buff_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int16_t *buff_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint16_t *buff_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int32_t *buff_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint32_t *buff_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int64_t *buff_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint64_t *buff_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	float   *buff_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);   double *buff_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	store_vi8x32 (tdvi8 , buff_i8 ); store_vi8x32 (tdvu8 , buff_u8 );
	store_vi16x16(tdvi16, buff_i16); store_vu16x16(tdvu16, buff_u16);
	store_vi32x8 (tdvi32, buff_i32); store_vu32x8 (tdvu32, buff_u32);
	store_vi64x4 (tdvi64, buff_i64); store_vu64x4 (tdvu64, buff_u64);
	store_vf32x8 (tdvf32, buff_f32); store_vf64x4 (tdvf64, buff_f64);
	if (!equals(buff_i8 , td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u8 , td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i16, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u16, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i64, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u64, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_f32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_f64, td, CVEC256_VECTOR_SIZE)) return 0;
	afree(td);
	afree(buff_i8);  afree(buff_u8);
	afree(buff_i16); afree(buff_u16);
	afree(buff_i32); afree(buff_u32);
	afree(buff_i64); afree(buff_u64);
	afree(buff_f32); afree(buff_f64);
	return 1;
}
int test_loadu_storeu(void) {
	uint8_t *td, *ptr;
	td = ptr = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); ++td;
	fill_test_data_256(td);
    vi8x32  tdvi8  = load_vi8x32 (td); vu8x32  tdvu8  = load_vu8x32 (td);
    vi16x16 tdvi16 = load_vi16x16(td); vu16x16 tdvu16 = load_vu16x16(td);
    vi32x8  tdvi32 = load_vi32x8 (td); vu32x8  tdvu32 = load_vu32x8 (td);
    vi64x4  tdvi64 = load_vi64x4 (td); vu64x4  tdvu64 = load_vu64x4 (td);
    vf32x8  tdvf32 = load_vf32x8 (td); vf64x4  tdvf64 = load_vf64x4 (td);
	int8_t  *b_i8  = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint8_t  *b_u8  = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int16_t *b_i16 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint16_t *b_u16 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int32_t *b_i32 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint32_t *b_u32 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int64_t *b_i64 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint64_t *b_u64 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	float   *b_f32 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);   double *b_f64 = amalloc(2 * CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int8_t  *buff_i8  =                       b_i8  + 1;  uint8_t  *buff_u8  =                        b_u8  + 1;
	int16_t *buff_i16 = (int16_t *)((int8_t *)b_i16 + 1); uint16_t *buff_u16 = (uint16_t *)((int8_t *)b_u16 + 1);
	int32_t *buff_i32 = (int32_t *)((int8_t *)b_i32 + 1); uint32_t *buff_u32 = (uint32_t *)((int8_t *)b_u32 + 1);
	int64_t *buff_i64 = (int64_t *)((int8_t *)b_i64 + 1); uint64_t *buff_u64 = (uint64_t *)((int8_t *)b_u64 + 1);
	float   *buff_f32 = (float   *)((int8_t *)b_f32 + 1);   double *buff_f64 = (double   *)((int8_t *)b_f64 + 1);

	storeu_vi8x32 (tdvi8 , buff_i8 ); storeu_vi8x32 (tdvu8 , buff_u8 );
	storeu_vi16x16(tdvi16, buff_i16); storeu_vu16x16(tdvu16, buff_u16);
	storeu_vi32x8 (tdvi32, buff_i32); storeu_vu32x8 (tdvu32, buff_u32);
	storeu_vi64x4 (tdvi64, buff_i64); storeu_vu64x4 (tdvu64, buff_u64);
	storeu_vf32x8 (tdvf32, buff_f32); storeu_vf64x4 (tdvf64, buff_f64);
	if (!equals(buff_i8 , td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u8 , td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i16, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u16, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_i64, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_u64, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_f32, td, CVEC256_VECTOR_SIZE)) return 0;
	if (!equals(buff_f64, td, CVEC256_VECTOR_SIZE)) return 0;
	afree(td);
	afree(b_i8 ); afree(b_u8 );
	afree(b_i16); afree(b_u16);
	afree(b_i32); afree(b_u32);
	afree(b_i64); afree(b_u64);
	afree(b_f32); afree(b_f64);
	return 1;
}

int test_at(void) {
    uint8_t *td;
    td = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_256(td);
	vi8x32  tdvi8  = load_vi8x32 (td); vu8x32  tdvu8  = load_vu8x32 (td);
    vi16x16 tdvi16 = load_vi16x16(td); vu16x16 tdvu16 = load_vu16x16(td);
    vi32x8  tdvi32 = load_vi32x8 (td); vu32x8  tdvu32 = load_vu32x8 (td);
    vi64x4  tdvi64 = load_vi64x4 (td); vu64x4  tdvu64 = load_vu64x4 (td);
    vf32x8  tdvf32 = load_vf32x8 (td); vf64x4  tdvf64 = load_vf64x4 (td);
    if (at_vi8x32(tdvi8 ,  0) != at_i8(td,  0) || at_vi8x32(tdvi8 ,  1) != at_i8(td,  1) || at_vi8x32(tdvi8 ,  2) != at_i8(td,  2) || at_vi8x32(tdvi8 ,  3) != at_i8(td,  3)
     || at_vi8x32(tdvi8 ,  4) != at_i8(td,  4) || at_vi8x32(tdvi8 ,  5) != at_i8(td,  5) || at_vi8x32(tdvi8 ,  6) != at_i8(td,  6) || at_vi8x32(tdvi8 ,  7) != at_i8(td,  7)
     || at_vi8x32(tdvi8 ,  8) != at_i8(td,  8) || at_vi8x32(tdvi8 ,  9) != at_i8(td,  9) || at_vi8x32(tdvi8 , 10) != at_i8(td, 10) || at_vi8x32(tdvi8 , 11) != at_i8(td, 11)
     || at_vi8x32(tdvi8 , 12) != at_i8(td, 12) || at_vi8x32(tdvi8 , 13) != at_i8(td, 13) || at_vi8x32(tdvi8 , 14) != at_i8(td, 14) || at_vi8x32(tdvi8 , 15) != at_i8(td, 15)
     || at_vi8x32(tdvi8 , 16) != at_i8(td, 16) || at_vi8x32(tdvi8 , 17) != at_i8(td, 17) || at_vi8x32(tdvi8 , 18) != at_i8(td, 18) || at_vi8x32(tdvi8 , 19) != at_i8(td, 19)
     || at_vi8x32(tdvi8 , 20) != at_i8(td, 20) || at_vi8x32(tdvi8 , 21) != at_i8(td, 21) || at_vi8x32(tdvi8 , 22) != at_i8(td, 22) || at_vi8x32(tdvi8 , 23) != at_i8(td, 23)
     || at_vi8x32(tdvi8 , 24) != at_i8(td, 24) || at_vi8x32(tdvi8 , 25) != at_i8(td, 25) || at_vi8x32(tdvi8 , 26) != at_i8(td, 26) || at_vi8x32(tdvi8 , 27) != at_i8(td, 27)
     || at_vi8x32(tdvi8 , 28) != at_i8(td, 28) || at_vi8x32(tdvi8 , 29) != at_i8(td, 29) || at_vi8x32(tdvi8 , 30) != at_i8(td, 30) || at_vi8x32(tdvi8 , 31) != at_i8(td, 31)){
        return 0;
    }
	if (at_vu8x32(tdvu8 ,  0) != at_u8(td,  0) || at_vu8x32(tdvu8 ,  1) != at_u8(td,  1) || at_vu8x32(tdvu8 ,  2) != at_u8(td,  2) || at_vu8x32(tdvu8 ,  3) != at_u8(td,  3)
     || at_vu8x32(tdvu8 ,  4) != at_u8(td,  4) || at_vu8x32(tdvu8 ,  5) != at_u8(td,  5) || at_vu8x32(tdvu8 ,  6) != at_u8(td,  6) || at_vu8x32(tdvu8 ,  7) != at_u8(td,  7)
     || at_vu8x32(tdvu8 ,  8) != at_u8(td,  8) || at_vu8x32(tdvu8 ,  9) != at_u8(td,  9) || at_vu8x32(tdvu8 , 10) != at_u8(td, 10) || at_vu8x32(tdvu8 , 11) != at_u8(td, 11)
     || at_vu8x32(tdvu8 , 12) != at_u8(td, 12) || at_vu8x32(tdvu8 , 13) != at_u8(td, 13) || at_vu8x32(tdvu8 , 14) != at_u8(td, 14) || at_vu8x32(tdvu8 , 15) != at_u8(td, 15)
     || at_vu8x32(tdvu8 , 16) != at_u8(td, 16) || at_vu8x32(tdvu8 , 17) != at_u8(td, 17) || at_vu8x32(tdvu8 , 18) != at_u8(td, 18) || at_vu8x32(tdvu8 , 19) != at_u8(td, 19)
     || at_vu8x32(tdvu8 , 20) != at_u8(td, 20) || at_vu8x32(tdvu8 , 21) != at_u8(td, 21) || at_vu8x32(tdvu8 , 22) != at_u8(td, 22) || at_vu8x32(tdvu8 , 23) != at_u8(td, 23)
     || at_vu8x32(tdvu8 , 24) != at_u8(td, 24) || at_vu8x32(tdvu8 , 25) != at_u8(td, 25) || at_vu8x32(tdvu8 , 26) != at_u8(td, 26) || at_vu8x32(tdvu8 , 27) != at_u8(td, 27)
     || at_vu8x32(tdvu8 , 28) != at_u8(td, 28) || at_vu8x32(tdvu8 , 29) != at_u8(td, 29) || at_vu8x32(tdvu8 , 30) != at_u8(td, 30) || at_vu8x32(tdvu8 , 31) != at_u8(td, 31)){
        return 0;
    }
    if (at_vi16x16(tdvi16,  0) != at_i16(td,  0) || at_vi16x16(tdvi16,  1) != at_i16(td,  1) || at_vi16x16(tdvi16,  2) != at_i16(td,  2) || at_vi16x16(tdvi16,  3) != at_i16(td,  3)
     || at_vi16x16(tdvi16,  4) != at_i16(td,  4) || at_vi16x16(tdvi16,  5) != at_i16(td,  5) || at_vi16x16(tdvi16,  6) != at_i16(td,  6) || at_vi16x16(tdvi16,  7) != at_i16(td,  7)
     || at_vi16x16(tdvi16,  8) != at_i16(td,  8) || at_vi16x16(tdvi16,  9) != at_i16(td,  9) || at_vi16x16(tdvi16, 10) != at_i16(td, 10) || at_vi16x16(tdvi16, 11) != at_i16(td, 11)
     || at_vi16x16(tdvi16, 12) != at_i16(td, 12) || at_vi16x16(tdvi16, 13) != at_i16(td, 13) || at_vi16x16(tdvi16, 14) != at_i16(td, 14) || at_vi16x16(tdvi16, 15) != at_i16(td, 15)) {
         return 0;
    }
	if (at_vu16x16(tdvu16,  0) != at_u16(td,  0) || at_vu16x16(tdvu16,  1) != at_u16(td,  1) || at_vu16x16(tdvu16,  2) != at_u16(td,  2) || at_vu16x16(tdvu16,  3) != at_u16(td,  3)
     || at_vu16x16(tdvu16,  4) != at_u16(td,  4) || at_vu16x16(tdvu16,  5) != at_u16(td,  5) || at_vu16x16(tdvu16,  6) != at_u16(td,  6) || at_vu16x16(tdvu16,  7) != at_u16(td,  7)
     || at_vu16x16(tdvu16,  8) != at_u16(td,  8) || at_vu16x16(tdvu16,  9) != at_u16(td,  9) || at_vu16x16(tdvu16, 10) != at_u16(td, 10) || at_vu16x16(tdvu16, 11) != at_u16(td, 11)
     || at_vu16x16(tdvu16, 12) != at_u16(td, 12) || at_vu16x16(tdvu16, 13) != at_u16(td, 13) || at_vu16x16(tdvu16, 14) != at_u16(td, 14) || at_vu16x16(tdvu16, 15) != at_u16(td, 15)) {
         return 0;
    }
    if (at_vi32x8(tdvi32,  0) != at_i32(td,  0) || at_vi32x8(tdvi32,  1) != at_i32(td,  1) || at_vi32x8(tdvi32,  2) != at_i32(td,  2) || at_vi32x8(tdvi32,  3) != at_i32(td,  3)
     || at_vi32x8(tdvi32,  4) != at_i32(td,  4) || at_vi32x8(tdvi32,  5) != at_i32(td,  5) || at_vi32x8(tdvi32,  6) != at_i32(td,  6) || at_vi32x8(tdvi32,  7) != at_i32(td,  7)){
        return 0;
    }
	if (at_vu32x8(tdvu32,  0) != at_u32(td,  0) || at_vu32x8(tdvu32,  1) != at_u32(td,  1) || at_vu32x8(tdvu32,  2) != at_u32(td,  2) || at_vu32x8(tdvu32,  3) != at_u32(td,  3)
     || at_vu32x8(tdvu32,  4) != at_u32(td,  4) || at_vu32x8(tdvu32,  5) != at_u32(td,  5) || at_vu32x8(tdvu32,  6) != at_u32(td,  6) || at_vu32x8(tdvu32,  7) != at_u32(td,  7)){
        return 0;
    }
    if (at_vi64x4(tdvi64,  0) != at_i64(td,  0) || at_vi64x4(tdvi64,  1) != at_i64(td,  1) || at_vi64x4(tdvi64,  2) != at_i64(td,  2) || at_vi64x4(tdvi64,  3) != at_i64(td,  3)){
        return 0;
    }
    if (at_vu64x4(tdvu64,  0) != at_u64(td,  0) || at_vu64x4(tdvu64,  1) != at_u64(td,  1) || at_vu64x4(tdvu64,  2) != at_u64(td,  2) || at_vu64x4(tdvu64,  3) != at_u64(td,  3)){
        return 0;
    }
	if (neq_f32(at_vf32x8(tdvf32, 0), at_f32(td, 0))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 1), at_f32(td, 1))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 2), at_f32(td, 2))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 3), at_f32(td, 3))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 4), at_f32(td, 4))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 5), at_f32(td, 5))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 6), at_f32(td, 6))) { return 0; }
	if (neq_f32(at_vf32x8(tdvf32, 7), at_f32(td, 7))) { return 0; }

	if (neq_f64(at_vf64x4(tdvf64, 0), at_f64(td, 0))) { return 0; }
	if (neq_f64(at_vf64x4(tdvf64, 1), at_f64(td, 1))) { return 0; }
	if (neq_f64(at_vf64x4(tdvf64, 2), at_f64(td, 2))) { return 0; }
	if (neq_f64(at_vf64x4(tdvf64, 3), at_f64(td, 3))) { return 0; }

	afree(td);
    return 1;
}
int test_setzero(void) {
	vi8x32  tdvi8  = setzero_vi8x32 (); vu8x32  tdvu8  = setzero_vu8x32 ();
	vi16x16 tdvi16 = setzero_vi16x16(); vu16x16 tdvu16 = setzero_vu16x16();
	vi32x8  tdvi32 = setzero_vi32x8 (); vu32x8  tdvu32 = setzero_vu32x8 ();
	vi64x4  tdvi64 = setzero_vi64x4 (); vu64x4  tdvu64 = setzero_vu64x4 ();
	vf32x8  tdvf32 = setzero_vf32x8 (); vf64x4  tdvf64 = setzero_vf64x4 ();
	int8_t  *buff_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint8_t  *buff_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int16_t *buff_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint16_t *buff_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int32_t *buff_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint32_t *buff_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	int64_t *buff_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); uint64_t *buff_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	float   *buff_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);   double *buff_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	store_vi8x32 (tdvi8 , buff_i8 ); store_vi8x32 (tdvu8 , buff_u8 );
	store_vi16x16(tdvi16, buff_i16); store_vu16x16(tdvu16, buff_u16);
	store_vi32x8 (tdvi32, buff_i32); store_vu32x8 (tdvu32, buff_u32);
	store_vi64x4 (tdvi64, buff_i64); store_vu64x4 (tdvu64, buff_u64);
	store_vf32x8 (tdvf32, buff_f32); store_vf64x4 (tdvf64, buff_f64);
	for (size_t i = 0; i < CVEC256_VECTOR_SIZE; ++i) {
		if (((uint8_t *)buff_i8 )[i] != 0) return 0;
		if (((uint8_t *)buff_u8 )[i] != 0) return 0;
		if (((uint8_t *)buff_i16)[i] != 0) return 0;
		if (((uint8_t *)buff_u16)[i] != 0) return 0;
		if (((uint8_t *)buff_i32)[i] != 0) return 0;
		if (((uint8_t *)buff_u32)[i] != 0) return 0;
		if (((uint8_t *)buff_i64)[i] != 0) return 0;
		if (((uint8_t *)buff_u64)[i] != 0) return 0;
		if (((uint8_t *)buff_f32)[i] != 0) return 0;
		if (((uint8_t *)buff_f64)[i] != 0) return 0;
	}
	afree(buff_i8 ); afree(buff_u8 );
	afree(buff_i16); afree(buff_u16);
	afree(buff_i32); afree(buff_u32);
	afree(buff_i64); afree(buff_u64);
	afree(buff_f32); afree(buff_f64);
	return 1;
}
int test_set1(void) {
	vi8x32  tdvi8  = set1_vi8x32 (-127  ); vu8x32  tdvu8  = set1_vu8x32 ( 127 );
	vi16x16 tdvi16 = set1_vi16x16(-127  ); vu16x16 tdvu16 = set1_vu16x16( 127 );
	vi32x8  tdvi32 = set1_vi32x8 (-127  ); vu32x8  tdvu32 = set1_vu32x8 ( 127 );
	vi64x4  tdvi64 = set1_vi64x4 (-127  ); vu64x4  tdvu64 = set1_vu64x4 ( 127 );
	vf32x8  tdvf32 = set1_vf32x8 (-127.f); vf64x4  tdvf64 = set1_vf64x4 (-127.);
	
	if (at_vi8x32(tdvi8 ,  0) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  0) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  1) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  1) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  2) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  2) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  3) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  3) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  4) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  4) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  5) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  5) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  6) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  6) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  7) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  7) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  8) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  8) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 ,  9) != -127  ) return 0; if (at_vu8x32(tdvu8 ,  9) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 10) != -127  ) return 0; if (at_vu8x32(tdvu8 , 10) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 11) != -127  ) return 0; if (at_vu8x32(tdvu8 , 11) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 12) != -127  ) return 0; if (at_vu8x32(tdvu8 , 12) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 13) != -127  ) return 0; if (at_vu8x32(tdvu8 , 13) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 14) != -127  ) return 0; if (at_vu8x32(tdvu8 , 14) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 15) != -127  ) return 0; if (at_vu8x32(tdvu8 , 15) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 16) != -127  ) return 0; if (at_vu8x32(tdvu8 , 16) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 17) != -127  ) return 0; if (at_vu8x32(tdvu8 , 17) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 18) != -127  ) return 0; if (at_vu8x32(tdvu8 , 18) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 19) != -127  ) return 0; if (at_vu8x32(tdvu8 , 19) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 20) != -127  ) return 0; if (at_vu8x32(tdvu8 , 20) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 21) != -127  ) return 0; if (at_vu8x32(tdvu8 , 21) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 22) != -127  ) return 0; if (at_vu8x32(tdvu8 , 22) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 23) != -127  ) return 0; if (at_vu8x32(tdvu8 , 23) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 24) != -127  ) return 0; if (at_vu8x32(tdvu8 , 24) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 25) != -127  ) return 0; if (at_vu8x32(tdvu8 , 25) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 26) != -127  ) return 0; if (at_vu8x32(tdvu8 , 26) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 27) != -127  ) return 0; if (at_vu8x32(tdvu8 , 27) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 28) != -127  ) return 0; if (at_vu8x32(tdvu8 , 28) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 29) != -127  ) return 0; if (at_vu8x32(tdvu8 , 29) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 30) != -127  ) return 0; if (at_vu8x32(tdvu8 , 30) !=  127 ) return 0;
	if (at_vi8x32(tdvi8 , 31) != -127  ) return 0; if (at_vu8x32(tdvu8 , 31) !=  127 ) return 0;
	
	if (at_vi16x16(tdvi16,  0) != -127  ) return 0; if (at_vu16x16(tdvu16,  0) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  1) != -127  ) return 0; if (at_vu16x16(tdvu16,  1) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  2) != -127  ) return 0; if (at_vu16x16(tdvu16,  2) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  3) != -127  ) return 0; if (at_vu16x16(tdvu16,  3) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  4) != -127  ) return 0; if (at_vu16x16(tdvu16,  4) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  5) != -127  ) return 0; if (at_vu16x16(tdvu16,  5) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  6) != -127  ) return 0; if (at_vu16x16(tdvu16,  6) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  7) != -127  ) return 0; if (at_vu16x16(tdvu16,  7) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  8) != -127  ) return 0; if (at_vu16x16(tdvu16,  8) !=  127 ) return 0;
	if (at_vi16x16(tdvi16,  9) != -127  ) return 0; if (at_vu16x16(tdvu16,  9) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 10) != -127  ) return 0; if (at_vu16x16(tdvu16, 10) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 11) != -127  ) return 0; if (at_vu16x16(tdvu16, 11) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 12) != -127  ) return 0; if (at_vu16x16(tdvu16, 12) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 13) != -127  ) return 0; if (at_vu16x16(tdvu16, 13) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 14) != -127  ) return 0; if (at_vu16x16(tdvu16, 14) !=  127 ) return 0;
	if (at_vi16x16(tdvi16, 15) != -127  ) return 0; if (at_vu16x16(tdvu16, 15) !=  127 ) return 0;

	if (at_vi32x8(tdvi32, 0) != -127) return 0; if (at_vu32x8(tdvu32, 0) != 127) return 0;
	if (at_vi32x8(tdvi32, 1) != -127) return 0; if (at_vu32x8(tdvu32, 1) != 127) return 0;
	if (at_vi32x8(tdvi32, 2) != -127) return 0; if (at_vu32x8(tdvu32, 2) != 127) return 0;
	if (at_vi32x8(tdvi32, 3) != -127) return 0; if (at_vu32x8(tdvu32, 3) != 127) return 0;
	if (at_vi32x8(tdvi32, 4) != -127) return 0; if (at_vu32x8(tdvu32, 4) != 127) return 0;
	if (at_vi32x8(tdvi32, 5) != -127) return 0; if (at_vu32x8(tdvu32, 5) != 127) return 0;
	if (at_vi32x8(tdvi32, 6) != -127) return 0; if (at_vu32x8(tdvu32, 6) != 127) return 0;
	if (at_vi32x8(tdvi32, 7) != -127) return 0; if (at_vu32x8(tdvu32, 7) != 127) return 0;
	
	if (at_vi64x4(tdvi64,  0) != -127  ) return 0; if (at_vu64x4(tdvu64,  0) !=  127 ) return 0;
	if (at_vi64x4(tdvi64,  1) != -127  ) return 0; if (at_vu64x4(tdvu64,  1) !=  127 ) return 0;
	if (at_vi64x4(tdvi64,  2) != -127  ) return 0; if (at_vu64x4(tdvu64,  2) !=  127 ) return 0;
	if (at_vi64x4(tdvi64,  3) != -127  ) return 0; if (at_vu64x4(tdvu64,  3) !=  127 ) return 0;
	
	if (at_vf32x8(tdvf32, 0) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 1) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 2) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 3) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 4) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 5) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 6) != -127.f) return 0;
	if (at_vf32x8(tdvf32, 7) != -127.f) return 0;
	
	if (at_vf64x4(tdvf64, 0) != -127.) return 0;
	if (at_vf64x4(tdvf64, 1) != -127.) return 0;
	if (at_vf64x4(tdvf64, 2) != -127.) return 0;
	if (at_vf64x4(tdvf64, 3) != -127.) return 0;
	return 1;
}

int test_add(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] + td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] + td_t_f64[i];
	vf32x8 dst_vf32 = add_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = add_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int test_sub(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] - td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] - td_t_f64[i];
	vf32x8 dst_vf32 = sub_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = sub_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int test_mul(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] * td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] * td_t_f64[i];
	vf32x8 dst_vf32 = mul_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = mul_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int test_div(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] / td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] / td_t_f64[i];
	vf32x8 dst_vf32 = div_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = div_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32); 
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int test_max(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = MAX(td_s_f32[i], td_t_f32[i]);
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = MAX(td_s_f64[i], td_t_f64[i]);
	vf32x8 dst_vf32 = max_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = max_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int test_min(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	double *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_2_vf32x8(td_t_f32);
	fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = MIN(td_s_f32[i], td_t_f32[i]);
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = MIN(td_s_f64[i], td_t_f64[i]);
	vf32x8 dst_vf32 = min_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = min_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x8(dst_vf32, i), td_d_f32[i]))
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (neq_f64(at_vf64x4(dst_vf64, i), td_d_f64[i]))
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}
int test_or(void) {
	int8_t* td_s_i8, * td_t_i8, * td_d_i8;
	uint8_t* td_s_u8, * td_t_u8, * td_d_u8;
	int16_t* td_s_i16, * td_t_i16, * td_d_i16;
	uint16_t* td_s_u16, * td_t_u16, * td_d_u16;
	int32_t* td_s_i32, * td_t_i32, * td_d_i32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	int64_t* td_s_i64, * td_t_i64, * td_d_i64;
	uint64_t* td_s_u64, * td_t_u64, * td_d_u64;
	float* td_s_f32, * td_t_f32, * td_d_f32;
	double* td_s_f64, * td_t_f64, * td_d_f64;
	td_s_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vi8x32(td_s_i8); fill_test_data_1_vu8x32(td_s_u8); fill_test_data_2_vi8x32(td_t_i8); fill_test_data_2_vu8x32(td_t_u8);
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) td_d_i8[i] = td_s_i8[i] | td_t_i8[i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) td_d_u8[i] = td_s_u8[i] | td_t_u8[i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] | td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] | td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] | td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] | td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] | td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] | td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] | ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] | ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32 = or_vi8x32(load_vi8x32(td_s_i8), load_vi8x32(td_t_i8));
	vu8x32  dst_vu8x32 = or_vu8x32(load_vu8x32(td_s_u8), load_vu8x32(td_t_u8));
	vi16x16 dst_vi16x16 = or_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = or_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = or_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = or_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = or_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = or_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = or_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = or_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) if (at_vi8x32(dst_vi8x32, i) != td_d_i8[i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) if (at_vu8x32(dst_vu8x32, i) != td_d_u8[i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t*)& tmpf);
		uint32_t s2 = *((uint32_t*)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t*)& tmpf);
		uint64_t s2 = *((uint64_t*)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8); afree(td_t_i8); afree(td_d_i8);
	afree(td_s_u8); afree(td_t_u8); afree(td_d_u8);
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_t_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_t_u64); afree(td_d_u64);
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}
int test_and(void) {
	int8_t* td_s_i8, * td_t_i8, * td_d_i8;
	uint8_t* td_s_u8, * td_t_u8, * td_d_u8;
	int16_t* td_s_i16, * td_t_i16, * td_d_i16;
	uint16_t* td_s_u16, * td_t_u16, * td_d_u16;
	int32_t* td_s_i32, * td_t_i32, * td_d_i32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	int64_t* td_s_i64, * td_t_i64, * td_d_i64;
	uint64_t* td_s_u64, * td_t_u64, * td_d_u64;
	float* td_s_f32, * td_t_f32, * td_d_f32;
	double* td_s_f64, * td_t_f64, * td_d_f64;
	td_s_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vi8x32(td_s_i8); fill_test_data_1_vu8x32(td_s_u8); fill_test_data_2_vi8x32(td_t_i8); fill_test_data_2_vu8x32(td_t_u8);
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) td_d_i8[i] = td_s_i8[i] & td_t_i8[i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) td_d_u8[i] = td_s_u8[i] & td_t_u8[i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] & td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] & td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] & td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] & td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] & td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] & td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] & ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] & ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32 = and_vi8x32(load_vi8x32(td_s_i8), load_vi8x32(td_t_i8));
	vu8x32  dst_vu8x32 = and_vu8x32(load_vu8x32(td_s_u8), load_vu8x32(td_t_u8));
	vi16x16 dst_vi16x16 = and_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = and_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = and_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = and_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = and_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = and_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = and_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = and_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) if (at_vi8x32(dst_vi8x32, i) != td_d_i8[i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) if (at_vu8x32(dst_vu8x32, i) != td_d_u8[i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t*)& tmpf);
		uint32_t s2 = *((uint32_t*)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t*)& tmpf);
		uint64_t s2 = *((uint64_t*)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8); afree(td_t_i8); afree(td_d_i8);
	afree(td_s_u8); afree(td_t_u8); afree(td_d_u8);
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_t_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_t_u64); afree(td_d_u64);
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int test_not(void) {
	int8_t* td_s_i8, * td_d_i8;
	uint8_t* td_s_u8, * td_d_u8;
	int16_t* td_s_i16, * td_d_i16;
	uint16_t* td_s_u16, * td_d_u16;
	int32_t* td_s_i32, * td_d_i32;
	uint32_t* td_s_u32, * td_d_u32;
	int64_t* td_s_i64, * td_d_i64;
	uint64_t* td_s_u64, * td_d_u64;
	float* td_s_f32, * td_d_f32;
	double* td_s_f64, * td_d_f64;
	td_s_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vi8x32(td_s_i8); fill_test_data_1_vu8x32(td_s_u8);
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) td_d_i8[i] = ~td_s_i8[i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) td_d_u8[i] = ~td_s_u8[i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = ~td_s_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = ~td_s_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = ~td_s_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = ~td_s_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = ~td_s_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = ~td_s_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ~((uint32_t*)td_s_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ~((uint64_t*)td_s_f64)[i];
	vi8x32  dst_vi8x32 = not_vi8x32(load_vi8x32(td_s_i8));
	vu8x32  dst_vu8x32 = not_vu8x32(load_vu8x32(td_s_u8));
	vi16x16 dst_vi16x16 = not_vi16x16(load_vi16x16(td_s_i16));
	vu16x16 dst_vu16x16 = not_vu16x16(load_vu16x16(td_s_u16));
	vi32x8 dst_vi32x8 = not_vi32x8(load_vi32x8(td_s_i32));
	vu32x8 dst_vu32x8 = not_vu32x8(load_vu32x8(td_s_u32));
	vi64x4 dst_vi64x4 = not_vi64x4(load_vi64x4(td_s_i64));
	vu64x4 dst_vu64x4 = not_vu64x4(load_vu64x4(td_s_u64));
	vf32x8 dst_vf32x8 = not_vf32x8(load_vf32x8(td_s_f32));
	vf64x4 dst_vf64x4 = not_vf64x4(load_vf64x4(td_s_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) if (at_vi8x32(dst_vi8x32, i) != td_d_i8[i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) if (at_vu8x32(dst_vu8x32, i) != td_d_u8[i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t*)& tmpf);
		uint32_t s2 = *((uint32_t*)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t*)& tmpf);
		uint64_t s2 = *((uint64_t*)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8); afree(td_d_i8);
	afree(td_s_u8); afree(td_d_u8);
	afree(td_s_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_d_u64);
	afree(td_s_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_d_f64);
	return 1;
}
int test_xor(void) {
	int8_t* td_s_i8, * td_t_i8, * td_d_i8;
	uint8_t* td_s_u8, * td_t_u8, * td_d_u8;
	int16_t* td_s_i16, * td_t_i16, * td_d_i16;
	uint16_t* td_s_u16, * td_t_u16, * td_d_u16;
	int32_t* td_s_i32, * td_t_i32, * td_d_i32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	int64_t* td_s_i64, * td_t_i64, * td_d_i64;
	uint64_t* td_s_u64, * td_t_u64, * td_d_u64;
	float* td_s_f32, * td_t_f32, * td_d_f32;
	double* td_s_f64, * td_t_f64, * td_d_f64;
	td_s_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	fill_test_data_1_vi8x32(td_s_i8); fill_test_data_1_vu8x32(td_s_u8); fill_test_data_2_vi8x32(td_t_i8); fill_test_data_2_vu8x32(td_t_u8);
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) td_d_i8[i] = td_s_i8[i] ^ td_t_i8[i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) td_d_u8[i] = td_s_u8[i] ^ td_t_u8[i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] ^ td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] ^ td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] ^ td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] ^ td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] ^ td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] ^ td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] ^ ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] ^ ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32 = xor_vi8x32(load_vi8x32(td_s_i8), load_vi8x32(td_t_i8));
	vu8x32  dst_vu8x32 = xor_vu8x32(load_vu8x32(td_s_u8), load_vu8x32(td_t_u8));
	vi16x16 dst_vi16x16 = xor_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = xor_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = xor_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = xor_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = xor_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = xor_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = xor_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = xor_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT; ++i) if (at_vi8x32(dst_vi8x32, i) != td_d_i8[i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT; ++i) if (at_vu8x32(dst_vu8x32, i) != td_d_u8[i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t*)& tmpf);
		uint32_t s2 = *((uint32_t*)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t*)& tmpf);
		uint64_t s2 = *((uint64_t*)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8); afree(td_t_i8); afree(td_d_i8);
	afree(td_s_u8); afree(td_t_u8); afree(td_d_u8);
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_t_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_t_u64); afree(td_d_u64);
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int main(int argc, char* argv[]){
#if defined(RANDOM_TEST_DATA)
	unsigned seed;
	if (argc > 1) {
		if (argv[1][0] == '0') {
			if (argv[1][1] == 'x') {
				seed = strtoul(argv[1], NULL, 16);
			} else {
				seed = strtoul(argv[1], NULL, 8);
			}
		} else if ( isdigit(argv[1][0]) ) {
			seed = strtoul(argv[1], NULL, 10);
		} else {
			fprintf(stderr, "input seed is wrong\n");
			return 0;
		}
	} else {
		seed = (unsigned)time(NULL);
	}
	printf("seed:%u\n", seed);
	srand(seed);
#else
	UNUSED(argc); UNUSED(argv);
#endif
	TEST_CASE(load_store);
	TEST_CASE(loadu_storeu);
	TEST_CASE(at);
	TEST_CASE(setzero);
	TEST_CASE(set1);
	TEST_CASE(add);
	TEST_CASE(sub);
	TEST_CASE(mul);
	TEST_CASE(div);
	TEST_CASE(max);
	TEST_CASE(min);
	TEST_CASE(or );
	TEST_CASE(and);
	TEST_CASE(not);
	TEST_CASE(xor);
    return 0;
}
