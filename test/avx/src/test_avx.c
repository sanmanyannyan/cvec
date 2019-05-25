#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "test_helpers.h"


#define CVEC256
#include "cvec.h"

void set_test_data(void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0x08; buff[ 9] = 0x09; buff[10] = 0x0A; buff[11] = 0x0B;
    buff[12] = 0x0C; buff[13] = 0x0D; buff[14] = 0x0E; buff[15] = 0x0F;
    buff[16] = 0xFF; buff[17] = 0xFE; buff[18] = 0xFD; buff[19] = 0xFC;
    buff[20] = 0xFB; buff[21] = 0xFA; buff[22] = 0xF9; buff[23] = 0xF8;
    buff[24] = 0xF7; buff[25] = 0xF6; buff[26] = 0xF5; buff[27] = 0xF4;
    buff[28] = 0xF3; buff[29] = 0xF2; buff[30] = 0xF1; buff[31] = 0xF0;
}
void set_test_data1_vf32(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] = 13019.f / 60520.f; buff[1] =  9497.f / 49875.f;
	buff[2] = 20204.f / 37479.f; buff[3] = 15512.f / 34346.f;
	buff[4] =  7974.f /  4123.f; buff[5] = 16267.f / 34951.f;
	buff[6] = 49203.f / 20624.f; buff[7] = 46469.f / 61280.f;
}
void set_test_data2_vf32(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] =  5336.f / 10925.f; buff[1] = 40659.f / 28889.f;
	buff[2] = 19322.f / 34130.f; buff[3] = 18976.f / 54979.f;
	buff[4] = 42847.f /  9629.f; buff[5] = 35927.f / 13327.f;
	buff[6] = 55302.f / 50863.f; buff[7] = 52181.f / 37305.f;
}
void set_test_data1_vf64(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] = 1484247589. / 1125869882.; buff[1] = 2300945531. / 2377086944.;
	buff[2] = 4252797847. / 1547484551.; buff[3] = 3750258763. /  423635020.;
}
void set_test_data2_vf64(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] = 3719188231. / 3935180964.; buff[1] = 2347073493. /  344925761.;
	buff[2] =   52388287. / 2420590488.; buff[3] = 3818747595. / 1910194483.;
}

  int8_t test_data_i8 (void* ptr, size_t lane) { return ((  int8_t *)ptr)[lane]; }
 uint8_t test_data_u8 (void* ptr, size_t lane) { return (( uint8_t *)ptr)[lane]; }
 int16_t test_data_i16(void* ptr, size_t lane) { return (( int16_t *)ptr)[lane]; }
uint16_t test_data_u16(void* ptr, size_t lane) { return ((uint16_t *)ptr)[lane]; }
 int32_t test_data_i32(void* ptr, size_t lane) { return (( int32_t *)ptr)[lane]; }
uint32_t test_data_u32(void* ptr, size_t lane) { return ((uint32_t *)ptr)[lane]; }
 int64_t test_data_i64(void* ptr, size_t lane) { return (( int64_t *)ptr)[lane]; }
uint64_t test_data_u64(void* ptr, size_t lane) { return ((uint64_t *)ptr)[lane]; }
   float test_data_f32(void* ptr, size_t lane) { return ((   float *)ptr)[lane]; }
  double test_data_f64(void* ptr, size_t lane) { return ((  double *)ptr)[lane]; }
int equals(void* ptr1, void* ptr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (((uint8_t*)ptr1)[i] != ((uint8_t*)ptr2)[i]) {
			return 0;
		}
	}
	return 1;
}

int test_load_store(void) {
	uint8_t *td;
    td = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data(td);
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
	set_test_data(td);
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
	set_test_data(td);
	vi8x32  tdvi8  = load_vi8x32 (td); vu8x32  tdvu8  = load_vu8x32 (td);
    vi16x16 tdvi16 = load_vi16x16(td); vu16x16 tdvu16 = load_vu16x16(td);
    vi32x8  tdvi32 = load_vi32x8 (td); vu32x8  tdvu32 = load_vu32x8 (td);
    vi64x4  tdvi64 = load_vi64x4 (td); vu64x4  tdvu64 = load_vu64x4 (td);
    vf32x8  tdvf32 = load_vf32x8 (td); vf64x4  tdvf64 = load_vf64x4 (td);
    if (at_vi8x32(tdvi8 ,  0) != test_data_i8(td,  0) || at_vi8x32(tdvi8 ,  1) != test_data_i8(td,  1) || at_vi8x32(tdvi8 ,  2) != test_data_i8(td,  2) || at_vi8x32(tdvi8 ,  3) != test_data_i8(td,  3)
     || at_vi8x32(tdvi8 ,  4) != test_data_i8(td,  4) || at_vi8x32(tdvi8 ,  5) != test_data_i8(td,  5) || at_vi8x32(tdvi8 ,  6) != test_data_i8(td,  6) || at_vi8x32(tdvi8 ,  7) != test_data_i8(td,  7)
     || at_vi8x32(tdvi8 ,  8) != test_data_i8(td,  8) || at_vi8x32(tdvi8 ,  9) != test_data_i8(td,  9) || at_vi8x32(tdvi8 , 10) != test_data_i8(td, 10) || at_vi8x32(tdvi8 , 11) != test_data_i8(td, 11)
     || at_vi8x32(tdvi8 , 12) != test_data_i8(td, 12) || at_vi8x32(tdvi8 , 13) != test_data_i8(td, 13) || at_vi8x32(tdvi8 , 14) != test_data_i8(td, 14) || at_vi8x32(tdvi8 , 15) != test_data_i8(td, 15)
     || at_vi8x32(tdvi8 , 16) != test_data_i8(td, 16) || at_vi8x32(tdvi8 , 17) != test_data_i8(td, 17) || at_vi8x32(tdvi8 , 18) != test_data_i8(td, 18) || at_vi8x32(tdvi8 , 19) != test_data_i8(td, 19)
     || at_vi8x32(tdvi8 , 20) != test_data_i8(td, 20) || at_vi8x32(tdvi8 , 21) != test_data_i8(td, 21) || at_vi8x32(tdvi8 , 22) != test_data_i8(td, 22) || at_vi8x32(tdvi8 , 23) != test_data_i8(td, 23)
     || at_vi8x32(tdvi8 , 24) != test_data_i8(td, 24) || at_vi8x32(tdvi8 , 25) != test_data_i8(td, 25) || at_vi8x32(tdvi8 , 26) != test_data_i8(td, 26) || at_vi8x32(tdvi8 , 27) != test_data_i8(td, 27)
     || at_vi8x32(tdvi8 , 28) != test_data_i8(td, 28) || at_vi8x32(tdvi8 , 29) != test_data_i8(td, 29) || at_vi8x32(tdvi8 , 30) != test_data_i8(td, 30) || at_vi8x32(tdvi8 , 31) != test_data_i8(td, 31)){
        return 0;
    }
	if (at_vu8x32(tdvu8 ,  0) != test_data_u8(td,  0) || at_vu8x32(tdvu8 ,  1) != test_data_u8(td,  1) || at_vu8x32(tdvu8 ,  2) != test_data_u8(td,  2) || at_vu8x32(tdvu8 ,  3) != test_data_u8(td,  3)
     || at_vu8x32(tdvu8 ,  4) != test_data_u8(td,  4) || at_vu8x32(tdvu8 ,  5) != test_data_u8(td,  5) || at_vu8x32(tdvu8 ,  6) != test_data_u8(td,  6) || at_vu8x32(tdvu8 ,  7) != test_data_u8(td,  7)
     || at_vu8x32(tdvu8 ,  8) != test_data_u8(td,  8) || at_vu8x32(tdvu8 ,  9) != test_data_u8(td,  9) || at_vu8x32(tdvu8 , 10) != test_data_u8(td, 10) || at_vu8x32(tdvu8 , 11) != test_data_u8(td, 11)
     || at_vu8x32(tdvu8 , 12) != test_data_u8(td, 12) || at_vu8x32(tdvu8 , 13) != test_data_u8(td, 13) || at_vu8x32(tdvu8 , 14) != test_data_u8(td, 14) || at_vu8x32(tdvu8 , 15) != test_data_u8(td, 15)
     || at_vu8x32(tdvu8 , 16) != test_data_u8(td, 16) || at_vu8x32(tdvu8 , 17) != test_data_u8(td, 17) || at_vu8x32(tdvu8 , 18) != test_data_u8(td, 18) || at_vu8x32(tdvu8 , 19) != test_data_u8(td, 19)
     || at_vu8x32(tdvu8 , 20) != test_data_u8(td, 20) || at_vu8x32(tdvu8 , 21) != test_data_u8(td, 21) || at_vu8x32(tdvu8 , 22) != test_data_u8(td, 22) || at_vu8x32(tdvu8 , 23) != test_data_u8(td, 23)
     || at_vu8x32(tdvu8 , 24) != test_data_u8(td, 24) || at_vu8x32(tdvu8 , 25) != test_data_u8(td, 25) || at_vu8x32(tdvu8 , 26) != test_data_u8(td, 26) || at_vu8x32(tdvu8 , 27) != test_data_u8(td, 27)
     || at_vu8x32(tdvu8 , 28) != test_data_u8(td, 28) || at_vu8x32(tdvu8 , 29) != test_data_u8(td, 29) || at_vu8x32(tdvu8 , 30) != test_data_u8(td, 30) || at_vu8x32(tdvu8 , 31) != test_data_u8(td, 31)){
        return 0;
    }
    if (at_vi16x16(tdvi16,  0) != test_data_i16(td,  0) || at_vi16x16(tdvi16,  1) != test_data_i16(td,  1) || at_vi16x16(tdvi16,  2) != test_data_i16(td,  2) || at_vi16x16(tdvi16,  3) != test_data_i16(td,  3)
     || at_vi16x16(tdvi16,  4) != test_data_i16(td,  4) || at_vi16x16(tdvi16,  5) != test_data_i16(td,  5) || at_vi16x16(tdvi16,  6) != test_data_i16(td,  6) || at_vi16x16(tdvi16,  7) != test_data_i16(td,  7)
     || at_vi16x16(tdvi16,  8) != test_data_i16(td,  8) || at_vi16x16(tdvi16,  9) != test_data_i16(td,  9) || at_vi16x16(tdvi16, 10) != test_data_i16(td, 10) || at_vi16x16(tdvi16, 11) != test_data_i16(td, 11)
     || at_vi16x16(tdvi16, 12) != test_data_i16(td, 12) || at_vi16x16(tdvi16, 13) != test_data_i16(td, 13) || at_vi16x16(tdvi16, 14) != test_data_i16(td, 14) || at_vi16x16(tdvi16, 15) != test_data_i16(td, 15)) {
         return 0;
    }
	if (at_vu16x16(tdvu16,  0) != test_data_u16(td,  0) || at_vu16x16(tdvu16,  1) != test_data_u16(td,  1) || at_vu16x16(tdvu16,  2) != test_data_u16(td,  2) || at_vu16x16(tdvu16,  3) != test_data_u16(td,  3)
     || at_vu16x16(tdvu16,  4) != test_data_u16(td,  4) || at_vu16x16(tdvu16,  5) != test_data_u16(td,  5) || at_vu16x16(tdvu16,  6) != test_data_u16(td,  6) || at_vu16x16(tdvu16,  7) != test_data_u16(td,  7)
     || at_vu16x16(tdvu16,  8) != test_data_u16(td,  8) || at_vu16x16(tdvu16,  9) != test_data_u16(td,  9) || at_vu16x16(tdvu16, 10) != test_data_u16(td, 10) || at_vu16x16(tdvu16, 11) != test_data_u16(td, 11)
     || at_vu16x16(tdvu16, 12) != test_data_u16(td, 12) || at_vu16x16(tdvu16, 13) != test_data_u16(td, 13) || at_vu16x16(tdvu16, 14) != test_data_u16(td, 14) || at_vu16x16(tdvu16, 15) != test_data_u16(td, 15)) {
         return 0;
    }
    if (at_vi32x8(tdvi32,  0) != test_data_i32(td,  0) || at_vi32x8(tdvi32,  1) != test_data_i32(td,  1) || at_vi32x8(tdvi32,  2) != test_data_i32(td,  2) || at_vi32x8(tdvi32,  3) != test_data_i32(td,  3)
     || at_vi32x8(tdvi32,  4) != test_data_i32(td,  4) || at_vi32x8(tdvi32,  5) != test_data_i32(td,  5) || at_vi32x8(tdvi32,  6) != test_data_i32(td,  6) || at_vi32x8(tdvi32,  7) != test_data_i32(td,  7)){
        return 0;
    }
	if (at_vu32x8(tdvu32,  0) != test_data_u32(td,  0) || at_vu32x8(tdvu32,  1) != test_data_u32(td,  1) || at_vu32x8(tdvu32,  2) != test_data_u32(td,  2) || at_vu32x8(tdvu32,  3) != test_data_u32(td,  3)
     || at_vu32x8(tdvu32,  4) != test_data_u32(td,  4) || at_vu32x8(tdvu32,  5) != test_data_u32(td,  5) || at_vu32x8(tdvu32,  6) != test_data_u32(td,  6) || at_vu32x8(tdvu32,  7) != test_data_u32(td,  7)){
        return 0;
    }
    if (at_vi64x4(tdvi64,  0) != test_data_i64(td,  0) || at_vi64x4(tdvi64,  1) != test_data_i64(td,  1) || at_vi64x4(tdvi64,  2) != test_data_i64(td,  2) || at_vi64x4(tdvi64,  3) != test_data_i64(td,  3)){
        return 0;
    }
    if (at_vu64x4(tdvu64,  0) != test_data_u64(td,  0) || at_vu64x4(tdvu64,  1) != test_data_u64(td,  1) || at_vu64x4(tdvu64,  2) != test_data_u64(td,  2) || at_vu64x4(tdvu64,  3) != test_data_u64(td,  3)){
        return 0;
    }
	if (at_vf32x8(tdvf32,  0) != test_data_f32(td,  0) || at_vf32x8(tdvf32,  1) != test_data_f32(td,  1) || at_vf32x8(tdvf32,  2) != test_data_f32(td,  2) || at_vf32x8(tdvf32,  3) != test_data_f32(td,  3)
     || at_vf32x8(tdvf32,  4) != test_data_f32(td,  4) || at_vf32x8(tdvf32,  5) != test_data_f32(td,  5) || at_vf32x8(tdvf32,  6) != test_data_f32(td,  6) || at_vf32x8(tdvf32,  7) != test_data_f32(td,  7)){
        return 0;
    }
	if (at_vf64x4(tdvf64,  0) != test_data_f64(td,  0) || at_vf64x4(tdvf64,  1) != test_data_f64(td,  1) || at_vf64x4(tdvf64,  2) != test_data_f64(td,  2) || at_vf64x4(tdvf64,  3) != test_data_f64(td,  3)){
        return 0;
    }
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] + td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] + td_t_f64[i];
	vf32x8 dst_vf32 = add_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = add_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] - td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] - td_t_f64[i];
	vf32x8 dst_vf32 = sub_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = sub_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] * td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] * td_t_f64[i];
	vf32x8 dst_vf32 = mul_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = mul_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] / td_t_f32[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = td_s_f64[i] / td_t_f64[i];
	vf32x8 dst_vf32 = div_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = div_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = MAX(td_s_f32[i], td_t_f32[i]);
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = MAX(td_s_f64[i], td_t_f64[i]);
	vf32x8 dst_vf32 = max_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = max_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
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
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	set_test_data1_vf64(td_s_f64); set_test_data2_vf64(td_t_f64);

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		td_d_f32[i] = MIN(td_s_f32[i], td_t_f32[i]);
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		td_d_f64[i] = MIN(td_s_f64[i], td_t_f64[i]);
	vf32x8 dst_vf32 = min_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64 = min_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i)
		if (at_vf32x8(dst_vf32, i) != td_d_f32[i])
			return 0;
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i)
		if (at_vf64x4(dst_vf64, i) != td_d_f64[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_f64); afree(td_t_f64); afree(td_d_f64);
	return 1;
}

int main(int argc, char* argv[]){
	UNUSED(argc); UNUSED(argv);
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
    return 0;
}
