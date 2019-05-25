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
void set_test_data1_vi8x32 (void* ptr) {
	int8_t *buff = (int8_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0x08; buff[ 9] = 0x09; buff[10] = 0x0A; buff[11] = 0x0B;
    buff[12] = 0x0C; buff[13] = 0x0D; buff[14] = 0x0E; buff[15] = 0x0F;
    buff[16] =   -1; buff[17] =   -2; buff[18] =   -3; buff[19] =   -4;
    buff[20] =   -5; buff[21] =   -6; buff[22] =   -7; buff[23] =   -8;
    buff[24] =   -9; buff[25] =  -10; buff[26] =  -11; buff[27] =  -12;
    buff[28] =  -13; buff[29] =  -14; buff[30] =  -15; buff[31] =  -16;
}
void set_test_data2_vi8x32 (void* ptr) {
	int8_t *buff = (int8_t *)ptr;
    buff[ 0] =  -13; buff[ 1] =  -14; buff[ 2] =  -15; buff[ 3] =  -16;
    buff[ 4] =   -9; buff[ 5] =  -10; buff[ 6] =  -11; buff[ 7] =  -12;
    buff[ 8] =   -5; buff[ 9] =   -6; buff[10] =   -7; buff[11] =   -8;
    buff[12] =   -1; buff[13] =   -2; buff[14] =   -3; buff[15] =   -4;
	buff[16] = 0x0C; buff[17] = 0x0D; buff[18] = 0x0E; buff[19] = 0x0F;
	buff[20] = 0x08; buff[21] = 0x09; buff[22] = 0x0A; buff[23] = 0x0B;
	buff[24] = 0x04; buff[25] = 0x05; buff[26] = 0x06; buff[27] = 0x07;
	buff[28] = 0x00; buff[29] = 0x01; buff[30] = 0x02; buff[31] = 0x03;
}
void set_test_data1_vu8x32 (void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0x08; buff[ 9] = 0x09; buff[10] = 0x0A; buff[11] = 0x0B;
    buff[12] = 0x0C; buff[13] = 0x0D; buff[14] = 0x0E; buff[15] = 0x0F;
	buff[16] = 0x18; buff[17] = 0x19; buff[18] = 0x1A; buff[19] = 0x1B;
	buff[20] = 0x1C; buff[21] = 0x1D; buff[22] = 0x1E; buff[23] = 0x1F;
	buff[24] = 0x10; buff[25] = 0x11; buff[26] = 0x12; buff[27] = 0x13;
    buff[28] = 0x14; buff[29] = 0x15; buff[30] = 0x16; buff[31] = 0x17;
}
void set_test_data2_vu8x32 (void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
	buff[ 0] = 0x01; buff[ 1] = 0x02; buff[ 2] = 0x03; buff[ 3] = 0x04;
    buff[ 4] = 0x05; buff[ 5] = 0x06; buff[ 6] = 0x07; buff[ 7] = 0x08;
    buff[ 8] = 0x09; buff[ 9] = 0x0A; buff[10] = 0x0B; buff[11] = 0x0C;
    buff[12] = 0x0D; buff[13] = 0x0E; buff[14] = 0x0F; buff[15] = 0x10;
    buff[16] = 0x11; buff[17] = 0x12; buff[18] = 0x13; buff[19] = 0x14;
    buff[20] = 0x15; buff[21] = 0x16; buff[22] = 0x17; buff[23] = 0x18;
    buff[24] = 0x19; buff[25] = 0x1A; buff[26] = 0x1B; buff[27] = 0x1C;
    buff[28] = 0x1D; buff[29] = 0x1E; buff[30] = 0x1F; buff[31] = 0x20;
}
void set_test_data1_vi16x16(void* ptr) {
	int16_t *buff = (int16_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] =   -1; buff[ 9] =   -2; buff[10] =   -3; buff[11] =   -4;
    buff[12] =   -5; buff[13] =   -6; buff[14] =   -7; buff[15] =   -8;
}
void set_test_data2_vi16x16(void* ptr) {
	int16_t *buff = (int16_t *)ptr;
    buff[ 0] =   -1; buff[ 1] =   -2; buff[ 2] =   -3; buff[ 3] =   -4;
    buff[ 4] =   -5; buff[ 5] =   -6; buff[ 6] =   -7; buff[ 7] =   -8;
	buff[ 8] = 0x00; buff[ 9] = 0x01; buff[10] = 0x02; buff[11] = 0x03;
    buff[12] = 0x04; buff[13] = 0x05; buff[14] = 0x06; buff[15] = 0x07;
}
void set_test_data1_vu16x16(void* ptr) {
	uint16_t *buff = (uint16_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0x08; buff[ 9] = 0x09; buff[10] = 0x0A; buff[11] = 0x0B;
    buff[12] = 0x0C; buff[13] = 0x0D; buff[14] = 0x0E; buff[15] = 0x0F;
}
void set_test_data2_vu16x16(void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
    buff[ 0] = 0x08; buff[ 1] = 0x07; buff[ 2] = 0x06; buff[ 3] = 0x05;
	buff[ 4] = 0x04; buff[ 5] = 0x03; buff[ 6] = 0x02; buff[ 7] = 0x01;
	buff[ 8] = 0x10; buff[ 9] = 0x0F; buff[10] = 0x0E; buff[11] = 0x0D;
	buff[12] = 0x0C; buff[13] = 0x0B; buff[14] = 0x0A; buff[15] = 0x09;
}
void set_test_data1_vi32x8(void* ptr) {
	int32_t *buff = (int32_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
}
void set_test_data2_vi32x8(void* ptr) {
	int32_t *buff = (int32_t *)ptr;
    buff[ 0] =   -1; buff[ 1] =   -2; buff[ 2] =   -3; buff[ 3] =   -4;
    buff[ 4] =    3; buff[ 5] =    4; buff[ 6] =    5; buff[ 7] =    6;
}
void set_test_data1_vu32x8(void* ptr) {
	uint32_t *buff = (uint32_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
}
void set_test_data2_vu32x8(void* ptr) {
	uint32_t *buff = (uint32_t *)ptr;
	buff[ 0] = 0x04; buff[ 1] = 0x03; buff[ 2] = 0x02; buff[ 3] = 0x01;
    buff[ 4] = 0x08; buff[ 5] = 0x07; buff[ 6] = 0x06; buff[ 7] = 0x05;
}
void set_test_data1_vi64x4(void* ptr) {
	int64_t *buff = (int64_t *)ptr;
	buff[0] = 0x00; buff[1] = 0x01; buff[2] = 0x02; buff[3] = 0x03;
}
void set_test_data2_vi64x4(void* ptr) {
	int64_t *buff = (int64_t *)ptr;
	buff[0] = -1; buff[1] = -2; buff[2] =  3; buff[3] =  4;
}
void set_test_data1_vu64x4(void* ptr) {
	uint64_t *buff = (uint64_t *)ptr;
	buff[0] = 0x00; buff[1] = 0x01; buff[2] = 0x02; buff[3] = 0x03;
}
void set_test_data2_vu64x4(void* ptr) {
	uint64_t *buff = (uint64_t *)ptr;
	buff[0] = 0x04; buff[1] = 0x03; buff[2] = 0x02; buff[3] = 0x01;
}

void set_test_data1_vf32x8(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] = 13019.f / 60520.f; buff[1] =  9497.f / 49875.f;
	buff[2] = 20204.f / 37479.f; buff[3] = 15512.f / 34346.f;
	buff[4] =  7974.f /  4123.f; buff[5] = 16267.f / 34951.f;
	buff[6] = 49203.f / 20624.f; buff[7] = 46469.f / 61280.f;
}
void set_test_data2_vf32x8(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] =  5336.f / 10925.f; buff[1] = 40659.f / 28889.f;
	buff[2] = 19322.f / 34130.f; buff[3] = 18976.f / 54979.f;
	buff[4] = 42847.f /  9629.f; buff[5] = 35927.f / 13327.f;
	buff[6] = 55302.f / 50863.f; buff[7] = 52181.f / 37305.f;
}
void set_test_data1_vf64x4(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] = 1484247589. / 1125869882.; buff[1] = 2300945531. / 2377086944.;
	buff[2] = 4252797847. / 1547484551.; buff[3] = 3750258763. /  423635020.;
}
void set_test_data2_vf64x4(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] = 3719188231. / 3935180964.; buff[1] = 2347073493. /  344925761.;
	buff[2] =   52388287. / 2420590488.; buff[3] = 3818747595. / 1910194483.;
}


int test_add(void) {
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_t_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_t_u64, *td_d_u64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); set_test_data2_vi64x4(td_t_i64); set_test_data2_vu64x4(td_t_u64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] + td_t_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] + td_t_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] + td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] + td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] + td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] + td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] + td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] + td_t_u64[i];
	vi8x32  dst_vi8x32  = add_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = add_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = add_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = add_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = add_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = add_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = add_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = add_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_t_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_t_u64); afree(td_d_u64);
	return 1;
}
int test_sub(void) {
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_t_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_t_u64, *td_d_u64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); set_test_data2_vi64x4(td_t_i64); set_test_data2_vu64x4(td_t_u64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] - td_t_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] - td_t_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] - td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] - td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] - td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] - td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] - td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] - td_t_u64[i];
	vi8x32  dst_vi8x32  = sub_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = sub_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = sub_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = sub_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = sub_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = sub_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = sub_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = sub_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	afree(td_s_i64); afree(td_t_i64); afree(td_d_i64);
	afree(td_s_u64); afree(td_t_u64); afree(td_d_u64);
	return 1;
}
int test_mul(void) {
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi16x16(td_s_i16); set_test_data2_vi16x16(td_t_i16);
	set_test_data1_vi32x8(td_s_i32); set_test_data2_vi32x8(td_t_i32);

	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] * td_t_i16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] * td_t_i32[i];
	vi16x16 dst_vi16x16 = mul_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vi32x8 dst_vi32x8 = mul_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));

	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;

	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	return 1;
}
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int test_max(void) {
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = MAX(td_s_i8 [i], td_t_i8 [i]);
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = MAX(td_s_u8 [i], td_t_u8 [i]);
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = MAX(td_s_i16[i], td_t_i16[i]);
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = MAX(td_s_u16[i], td_t_u16[i]);
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = MAX(td_s_i32[i], td_t_i32[i]);
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = MAX(td_s_u32[i], td_t_u32[i]);
	vi8x32  dst_vi8x32  = max_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = max_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = max_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = max_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = max_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = max_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	return 1;
}
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int test_min(void) {
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = MIN(td_s_i8 [i], td_t_i8 [i]);
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = MIN(td_s_u8 [i], td_t_u8 [i]);
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = MIN(td_s_i16[i], td_t_i16[i]);
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = MIN(td_s_u16[i], td_t_u16[i]);
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = MIN(td_s_i32[i], td_t_i32[i]);
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = MIN(td_s_u32[i], td_t_u32[i]);
	vi8x32  dst_vi8x32  = min_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = min_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = min_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = min_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = min_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = min_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
	afree(td_s_i16); afree(td_t_i16); afree(td_d_i16);
	afree(td_s_u16); afree(td_t_u16); afree(td_d_u16);
	afree(td_s_i32); afree(td_t_i32); afree(td_d_i32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	return 1;
}
int test_or(void) {
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_t_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_t_u64, *td_d_u64;
	float    *td_s_f32, *td_t_f32, *td_d_f32;
	double   *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); set_test_data2_vi64x4(td_t_i64); set_test_data2_vu64x4(td_t_u64);
	set_test_data1_vf32x8(td_s_f32); set_test_data1_vf64x4(td_s_f64); set_test_data2_vf32x8(td_t_f32); set_test_data2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] | td_t_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] | td_t_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] | td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] | td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] | td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] | td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] | td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] | td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] | ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] | ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32  = or_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = or_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = or_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = or_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = or_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = or_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = or_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = or_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = or_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = or_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if ( s1 != s2 )
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t *)&tmpf);
		uint64_t s2 = *((uint64_t *)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
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
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_t_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_t_u64, *td_d_u64;
	float    *td_s_f32, *td_t_f32, *td_d_f32;
	double   *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); set_test_data2_vi64x4(td_t_i64); set_test_data2_vu64x4(td_t_u64);
	set_test_data1_vf32x8(td_s_f32); set_test_data1_vf64x4(td_s_f64); set_test_data2_vf32x8(td_t_f32); set_test_data2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] & td_t_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] & td_t_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] & td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] & td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] & td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] & td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] & td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] & td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] & ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] & ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32  = and_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = and_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = and_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = and_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = and_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = and_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = and_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = and_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = and_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = and_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t *)&tmpf);
		uint64_t s2 = *((uint64_t *)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
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
	int8_t   *td_s_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_d_u64;
	float    *td_s_f32, *td_d_f32;
	double   *td_s_f64, *td_d_f64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); 
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); 
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); 
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); 
	set_test_data1_vf32x8(td_s_f32); set_test_data1_vf64x4(td_s_f64); 

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = ~td_s_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = ~td_s_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = ~td_s_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = ~td_s_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = ~td_s_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = ~td_s_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = ~td_s_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = ~td_s_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ~((uint32_t*)td_s_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ~((uint64_t*)td_s_f64)[i];
	vi8x32  dst_vi8x32  = not_vi8x32 (load_vi8x32 (td_s_i8 ));
	vu8x32  dst_vu8x32  = not_vu8x32 (load_vu8x32 (td_s_u8 ));
	vi16x16 dst_vi16x16 = not_vi16x16(load_vi16x16(td_s_i16));
	vu16x16 dst_vu16x16 = not_vu16x16(load_vu16x16(td_s_u16));
	vi32x8 dst_vi32x8 = not_vi32x8(load_vi32x8(td_s_i32));
	vu32x8 dst_vu32x8 = not_vu32x8(load_vu32x8(td_s_u32));
	vi64x4 dst_vi64x4 = not_vi64x4(load_vi64x4(td_s_i64));
	vu64x4 dst_vu64x4 = not_vu64x4(load_vu64x4(td_s_u64));
	vf32x8 dst_vf32x8 = not_vf32x8(load_vf32x8(td_s_f32));
	vf64x4 dst_vf64x4 = not_vf64x4(load_vf64x4(td_s_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t *)&tmpf);
		uint64_t s2 = *((uint64_t *)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_d_u8 );
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
	int8_t   *td_s_i8 , *td_t_i8 , *td_d_i8;
	uint8_t  *td_s_u8 , *td_t_u8 , *td_d_u8;
	int16_t  *td_s_i16, *td_t_i16, *td_d_i16;
	uint16_t *td_s_u16, *td_t_u16, *td_d_u16;
	int32_t  *td_s_i32, *td_t_i32, *td_d_i32;
	uint32_t *td_s_u32, *td_t_u32, *td_d_u32;
	int64_t  *td_s_i64, *td_t_i64, *td_d_i64;
	uint64_t *td_s_u64, *td_t_u64, *td_d_u64;
	float    *td_s_f32, *td_t_f32, *td_d_f32;
	double   *td_s_f64, *td_t_f64, *td_d_f64;
	td_s_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u8  = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u16 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_i64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_u64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	td_s_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_t_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT); td_d_f64 = amalloc(CVEC256_VECTOR_SIZE, CVEC256_MEMORY_ALIGNMENT);
	set_test_data1_vi8x32 (td_s_i8 ); set_test_data1_vu8x32 (td_s_u8 ); set_test_data2_vi8x32 (td_t_i8 ); set_test_data2_vu8x32 (td_t_u8 );
	set_test_data1_vi16x16(td_s_i16); set_test_data1_vu16x16(td_s_u16); set_test_data2_vi16x16(td_t_i16); set_test_data2_vu16x16(td_t_u16);
	set_test_data1_vi32x8(td_s_i32); set_test_data1_vu32x8(td_s_u32); set_test_data2_vi32x8(td_t_i32); set_test_data2_vu32x8(td_t_u32);
	set_test_data1_vi64x4(td_s_i64); set_test_data1_vu64x4(td_s_u64); set_test_data2_vi64x4(td_t_i64); set_test_data2_vu64x4(td_t_u64);
	set_test_data1_vf32x8(td_s_f32); set_test_data1_vf64x4(td_s_f64); set_test_data2_vf32x8(td_t_f32); set_test_data2_vf64x4(td_t_f64);

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] ^ td_t_i8 [i];
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] ^ td_t_u8 [i];
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] ^ td_t_i16[i];
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] ^ td_t_u16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] ^ td_t_i32[i];
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) td_d_u32[i] = td_s_u32[i] ^ td_t_u32[i];
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) td_d_i64[i] = td_s_i64[i] ^ td_t_i64[i];
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) td_d_u64[i] = td_s_u64[i] ^ td_t_u64[i];
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) ((uint32_t*)td_d_f32)[i] = ((uint32_t*)td_s_f32)[i] ^ ((uint32_t*)td_t_f32)[i];
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) ((uint64_t*)td_d_f64)[i] = ((uint64_t*)td_s_f64)[i] ^ ((uint64_t*)td_t_f64)[i];
	vi8x32  dst_vi8x32  = xor_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = xor_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = xor_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = xor_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = xor_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = xor_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = xor_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = xor_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));
	vf32x8 dst_vf32x8 = xor_vf32x8(load_vf32x8(td_s_f32), load_vf32x8(td_t_f32));
	vf64x4 dst_vf64x4 = xor_vf64x4(load_vf64x4(td_s_f64), load_vf64x4(td_t_f64));

	for (size_t i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (size_t i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (size_t i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (size_t i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (size_t i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (size_t i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (size_t i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (size_t i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
		double tmpf = at_vf64x4(dst_vf64x4, i);
		uint64_t s1 = *((uint64_t *)&tmpf);
		uint64_t s2 = *((uint64_t *)(td_d_f64 + i));
		if (s1 != s2)
			return 0;
	}

	afree(td_s_i8 ); afree(td_t_i8 ); afree(td_d_i8 );
	afree(td_s_u8 ); afree(td_t_u8 ); afree(td_d_u8 );
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
	UNUSED(argc); UNUSED(argv);
	TEST_CASE(add);
	TEST_CASE(sub);
	TEST_CASE(mul);
	TEST_CASE(max);
	TEST_CASE(min);
	TEST_CASE(or );
	TEST_CASE(and);
	TEST_CASE(not);
	TEST_CASE(xor);
    return 0;
}
