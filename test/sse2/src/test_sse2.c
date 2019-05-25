#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "test_helpers.h"


#define CVEC128
#include "cvec.h"

void set_test_data(void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0xFF; buff[ 9] = 0xFE; buff[10] = 0xFD; buff[11] = 0xFC;
    buff[12] = 0xFB; buff[13] = 0xFA; buff[14] = 0xF9; buff[15] = 0xF8;
}
void set_test_data1_vf32(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] = 13019.f / 60520.f; buff[1] =  9497.f / 49875.f;
	buff[2] = 20204.f / 37479.f; buff[3] = 15512.f / 34346.f;
}
void set_test_data2_vf32(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] =  5336.f / 10925.f; buff[1] = 40659.f / 28889.f;
	buff[2] = 19322.f / 34130.f; buff[3] = 18976.f / 54979.f;
}

float test_data_f32(void* ptr, size_t lane) { return ((   float *)ptr)[lane]; }
int equals(void* ptr1, void* ptr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (((uint8_t*)ptr1)[i] != ((uint8_t*)ptr2)[i]) {
			return 0;
		}
	}
	return 1;
}

int test_amalloc(void) {
	uintptr_t ptr = (uintptr_t)amalloc(sizeof(double), CVEC128_MEMORY_ALIGNMENT);
	uintptr_t alignment = ptr & (CVEC128_MEMORY_ALIGNMENT - 1);
	afree((void *)ptr);
	return alignment == 0;
}
int test_afree(void) {
	uintptr_t ptr = (uintptr_t)amalloc(sizeof(double), CVEC128_MEMORY_ALIGNMENT);
	afree((void *)ptr);
	return 1;
}
int test_load_store(void) {
	uint8_t *td;
    td = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data(td);
    vf32x4  tdvf32 = load_vf32x4 (td);
	float   *buff_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	store_vf32x4(tdvf32, buff_f32);
	if (!equals(buff_f32, td, CVEC128_VECTOR_SIZE)) return 0;
	afree(td);
	afree(buff_f32);
	return 1;
}
int test_loadu_storeu(void) {
	uint8_t *td, *ptr;
	td = ptr = amalloc(2 * CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); ++td;
	set_test_data(td);
    vf32x4  tdvf32 = load_vf32x4 (td);
	float   *b_f32 = amalloc(2 * CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	float   *buff_f32 = (float   *)((int8_t *)b_f32 + 1);

	storeu_vf32x4 (tdvf32, buff_f32);
	if (!equals(buff_f32, td, CVEC128_VECTOR_SIZE)) return 0;
	afree(td);
	afree(b_f32);
	return 1;
}

int test_at(void) {
    uint8_t *td;
    td = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data(td);
    vf32x4  tdvf32 = load_vf32x4 (td);
	if (at_vf32x4(tdvf32,  0) != test_data_f32(td,  0) || at_vf32x4(tdvf32,  1) != test_data_f32(td,  1) || at_vf32x4(tdvf32,  2) != test_data_f32(td,  2) || at_vf32x4(tdvf32,  3) != test_data_f32(td,  3)){
        return 0;
    }
    afree(td);
    return 1;
}
int test_setzero(void) {
	vf32x4  tdvf32 = setzero_vf32x4 ();
	float   *buff_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	store_vf32x4 (tdvf32, buff_f32);
	for (size_t i = 0; i < CVEC128_VECTOR_SIZE; ++i) {
		if (((uint8_t *)buff_f32)[i] != 0) return 0;
	}
	afree(buff_f32);
	return 1;
}
int test_set1(void) {
	vf32x4  tdvf32 = set1_vf32x4 (-127.f);
	
	if (at_vf32x4(tdvf32, 0) != -127.f) return 0;
	if (at_vf32x4(tdvf32, 1) != -127.f) return 0;
	if (at_vf32x4(tdvf32, 2) != -127.f) return 0;
	if (at_vf32x4(tdvf32, 3) != -127.f) return 0;
	return 1;
}

int test_add(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] + td_t_f32[i];
	vf32x4 dst_vf32 = add_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_sub(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] - td_t_f32[i];
	vf32x4 dst_vf32 = sub_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_mul(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] * td_t_f32[i];
	vf32x4 dst_vf32 = mul_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_div(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);
	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] / td_t_f32[i];
	vf32x4 dst_vf32 = div_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32); 
	return 1;
}
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int test_max(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = MAX(td_s_f32[i], td_t_f32[i]);
	vf32x4 dst_vf32 = max_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int test_min(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	set_test_data1_vf32(td_s_f32); set_test_data2_vf32(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = MIN(td_s_f32[i], td_t_f32[i]);
	vf32x4 dst_vf32 = min_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (at_vf32x4(dst_vf32, i) != td_d_f32[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int main(int argc, char* argv[]){
	UNUSED(argc); UNUSED(argv);
	TEST_CASE(amalloc);
	TEST_CASE(afree);
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
