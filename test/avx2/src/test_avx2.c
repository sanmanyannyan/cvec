#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define RANDOM_TEST_DATA
#include "test_helpers.h"


#include "cvec.h"



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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8 (td_s_i32); fill_test_data_1_vu32x8 (td_s_u32); fill_test_data_2_vi32x8 (td_t_i32); fill_test_data_2_vu32x8 (td_t_u32);
	fill_test_data_1_vi64x4 (td_s_i64); fill_test_data_1_vu64x4 (td_s_u64); fill_test_data_2_vi64x4 (td_t_i64); fill_test_data_2_vu64x4 (td_t_u64);

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) td_d_i8 [i] = td_s_i8 [i] + td_t_i8 [i];
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) td_d_u8 [i] = td_s_u8 [i] + td_t_u8 [i];
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] + td_t_i16[i];
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) td_d_u16[i] = td_s_u16[i] + td_t_u16[i];
	for (int i = 0; i < VI32X8_NUM_ELEMENT ; ++i) td_d_i32[i] = td_s_i32[i] + td_t_i32[i];
	for (int i = 0; i < VU32X8_NUM_ELEMENT ; ++i) td_d_u32[i] = td_s_u32[i] + td_t_u32[i];
	for (int i = 0; i < VI64X4_NUM_ELEMENT ; ++i) td_d_i64[i] = td_s_i64[i] + td_t_i64[i];
	for (int i = 0; i < VU64X4_NUM_ELEMENT ; ++i) td_d_u64[i] = td_s_u64[i] + td_t_u64[i];
	vi8x32  dst_vi8x32  = add_vi8x32 (load_vi8x32 (td_s_i8 ), load_vi8x32 (td_t_i8 ));
	vu8x32  dst_vu8x32  = add_vu8x32 (load_vu8x32 (td_s_u8 ), load_vu8x32 (td_t_u8 ));
	vi16x16 dst_vi16x16 = add_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vu16x16 dst_vu16x16 = add_vu16x16(load_vu16x16(td_s_u16), load_vu16x16(td_t_u16));
	vi32x8 dst_vi32x8 = add_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));
	vu32x8 dst_vu32x8 = add_vu32x8(load_vu32x8(td_s_u32), load_vu32x8(td_t_u32));
	vi64x4 dst_vi64x4 = add_vi64x4(load_vi64x4(td_s_i64), load_vi64x4(td_t_i64));
	vu64x4 dst_vu64x4 = add_vu64x4(load_vu64x4(td_s_u64), load_vu64x4(td_t_u64));

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT ; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT ; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT ; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT ; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;

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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT ; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT ; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT ; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT ; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;

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
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_2_vi16x16(td_t_i16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_2_vi32x8(td_t_i32);

	for (size_t i = 0; i < VI16X16_NUM_ELEMENT; ++i) td_d_i16[i] = td_s_i16[i] * td_t_i16[i];
	for (size_t i = 0; i < VI32X8_NUM_ELEMENT; ++i) td_d_i32[i] = td_s_i32[i] * td_t_i32[i];
	vi16x16 dst_vi16x16 = mul_vi16x16(load_vi16x16(td_s_i16), load_vi16x16(td_t_i16));
	vi32x8 dst_vi32x8 = mul_vi32x8(load_vi32x8(td_s_i32), load_vi32x8(td_t_i32));

	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;

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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT ; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT ; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;

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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT ; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT ; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;

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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (int i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if ( s1 != s2 )
			return 0;
	}
	for (int i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (int i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (int i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); 
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); 
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); 
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); 
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); 

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (int i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (int i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
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
	fill_test_data_1_vi8x32 (td_s_i8 ); fill_test_data_1_vu8x32 (td_s_u8 ); fill_test_data_2_vi8x32 (td_t_i8 ); fill_test_data_2_vu8x32 (td_t_u8 );
	fill_test_data_1_vi16x16(td_s_i16); fill_test_data_1_vu16x16(td_s_u16); fill_test_data_2_vi16x16(td_t_i16); fill_test_data_2_vu16x16(td_t_u16);
	fill_test_data_1_vi32x8(td_s_i32); fill_test_data_1_vu32x8(td_s_u32); fill_test_data_2_vi32x8(td_t_i32); fill_test_data_2_vu32x8(td_t_u32);
	fill_test_data_1_vi64x4(td_s_i64); fill_test_data_1_vu64x4(td_s_u64); fill_test_data_2_vi64x4(td_t_i64); fill_test_data_2_vu64x4(td_t_u64);
	fill_test_data_1_vf32x8(td_s_f32); fill_test_data_1_vf64x4(td_s_f64); fill_test_data_2_vf32x8(td_t_f32); fill_test_data_2_vf64x4(td_t_f64);

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

	for (int i = 0; i < VI8X32_NUM_ELEMENT ; ++i) if (at_vi8x32 (dst_vi8x32 , i) != td_d_i8 [i]) return 0;
	for (int i = 0; i < VU8X32_NUM_ELEMENT ; ++i) if (at_vu8x32 (dst_vu8x32 , i) != td_d_u8 [i]) return 0;
	for (int i = 0; i < VI16X16_NUM_ELEMENT; ++i) if (at_vi16x16(dst_vi16x16, i) != td_d_i16[i]) return 0;
	for (int i = 0; i < VU16X16_NUM_ELEMENT; ++i) if (at_vu16x16(dst_vu16x16, i) != td_d_u16[i]) return 0;
	for (int i = 0; i < VI32X8_NUM_ELEMENT; ++i) if (at_vi32x8(dst_vi32x8, i) != td_d_i32[i]) return 0;
	for (int i = 0; i < VU32X8_NUM_ELEMENT; ++i) if (at_vu32x8(dst_vu32x8, i) != td_d_u32[i]) return 0;
	for (int i = 0; i < VI64X4_NUM_ELEMENT; ++i) if (at_vi64x4(dst_vi64x4, i) != td_d_i64[i]) return 0;
	for (int i = 0; i < VU64X4_NUM_ELEMENT; ++i) if (at_vu64x4(dst_vu64x4, i) != td_d_u64[i]) return 0;
	for (int i = 0; i < VF32X8_NUM_ELEMENT; ++i) {
		float tmpf = at_vf32x8(dst_vf32x8, i);
		uint32_t s1 = *((uint32_t *)&tmpf);
		uint32_t s2 = *((uint32_t *)(td_d_f32 + i));
		if (s1 != s2)
			return 0;
	}
	for (int i = 0; i < VF64X4_NUM_ELEMENT; ++i) {
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
#if defined(RANDOM_TEST_DATA)
	unsigned seed;
	if (argc > 1) {
		if (argv[1][0] == '0') {
			if (argv[1][1] == 'x') {
				seed = strtoul(argv[1], NULL, 16);
			}
			else {
				seed = strtoul(argv[1], NULL, 8);
			}
		}
		else if (isdigit(argv[1][0])) {
			seed = strtoul(argv[1], NULL, 10);
		}
		else {
			fprintf(stderr, "input seed is wrong\n");
			return 0;
		}
	}
	else {
		seed = (unsigned)time(NULL);
	}
	printf("seed:%u\n", seed);
	srand(seed);
#else
	UNUSED(argc); UNUSED(argv);
#endif
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
