#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RANDOM_TEST_DATA

#include "test_helpers.h"


#include "cvec.h"


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
	fill_test_data_128(td);
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
	fill_test_data_128(td);
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
	fill_test_data_128(td);
    vf32x4  tdvf32 = load_vf32x4 (td);
	if ( neq_f32(at_vf32x4(tdvf32, 0), at_f32(td, 0)) ) return 0;
	if ( neq_f32(at_vf32x4(tdvf32, 1), at_f32(td, 1)) ) return 0;
	if ( neq_f32(at_vf32x4(tdvf32, 2), at_f32(td, 2)) ) return 0;
	if ( neq_f32(at_vf32x4(tdvf32, 3), at_f32(td, 3)) ) return 0;
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
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] + td_t_f32[i];
	vf32x4 dst_vf32 = add_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_sub(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] - td_t_f32[i];
	vf32x4 dst_vf32 = sub_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_mul(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] * td_t_f32[i];
	vf32x4 dst_vf32 = mul_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_div(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);
	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = td_s_f32[i] / td_t_f32[i];
	vf32x4 dst_vf32 = div_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;

	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32); 
	return 1;
}
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int test_max(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = MAX(td_s_f32[i], td_t_f32[i]);
	vf32x4 dst_vf32 = max_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int test_min(void) {
	float  *td_s_f32, *td_t_f32, *td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = MIN(td_s_f32[i], td_t_f32[i]);
	vf32x4 dst_vf32 = min_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]))
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	return 1;
}

int test_arcp(void) {
	float* td_s_f32, * td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	
	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_s_f32[i] = i + 2.f;
	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = 1.f / td_s_f32[i];
	vf32x4 dst_vf32 = arcp_vf32x4(load_vf32x4(td_s_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
	{
		double relative_error = (at_vf32x4(dst_vf32, i) - td_d_f32[i]) / td_d_f32[i];
		if (relative_error < 0.0) relative_error *= -1.0;
		if (relative_error >= 1.5 / 4096.0) return 0;
	}
	afree(td_s_f32);afree(td_d_f32);
	return 1;
}

int test_sqrt(void) {
	float* td_s_f32, * td_d_f32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_s_f32[i] = i + 2.f;
	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		td_d_f32[i] = sqrtf(td_s_f32[i]);
	vf32x4 dst_vf32 = sqrt_vf32x4(load_vf32x4(td_s_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
	{
		if ( neq_f32(at_vf32x4(dst_vf32, i), td_d_f32[i]) ) return 0;
	}
	afree(td_s_f32); afree(td_d_f32);
	return 1;
}

int test_or(void) {
	float* td_s_f32, * td_t_f32, * td_d_f32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_s_u32[i] = read_f32_as_u32(td_s_f32[i]);
		td_t_u32[i] = read_f32_as_u32(td_t_f32[i]);
	}


	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_d_u32[i] = td_s_u32[i] | td_t_u32[i];
		td_d_f32[i] = read_u32_as_f32(td_d_u32[i]);
	}
	vf32x4 dst_vf32 = or_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (read_f32_as_u32(at_vf32x4(dst_vf32, i)) != td_d_u32[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	return 1;
}

int test_and(void) {
	float* td_s_f32, * td_t_f32, * td_d_f32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_s_u32[i] = read_f32_as_u32(td_s_f32[i]);
		td_t_u32[i] = read_f32_as_u32(td_t_f32[i]);
	}


	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_d_u32[i] = td_s_u32[i] & td_t_u32[i];
		td_d_f32[i] = read_u32_as_f32(td_d_u32[i]);
	}
	vf32x4 dst_vf32 = and_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (read_f32_as_u32(at_vf32x4(dst_vf32, i)) != td_d_u32[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
	return 1;
}

int test_not(void) {
	float* td_s_f32, * td_d_f32;
	uint32_t* td_s_u32, * td_d_u32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_s_u32[i] = read_f32_as_u32(td_s_f32[i]);
	}


	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_d_u32[i] = ~td_s_u32[i];
		td_d_f32[i] = read_u32_as_f32(td_d_u32[i]);
	}
	vf32x4 dst_vf32 = not_vf32x4(load_vf32x4(td_s_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (read_f32_as_u32(at_vf32x4(dst_vf32, i)) != td_d_u32[i])
			return 0;
	afree(td_s_f32); afree(td_d_f32);
	afree(td_s_u32); afree(td_d_u32);
	return 1;
}

int test_xor(void) {
	float* td_s_f32, * td_t_f32, * td_d_f32;
	uint32_t* td_s_u32, * td_t_u32, * td_d_u32;
	td_s_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_f32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	td_s_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_t_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT); td_d_u32 = amalloc(CVEC128_VECTOR_SIZE, CVEC128_MEMORY_ALIGNMENT);
	fill_test_data_1_f32x4(td_s_f32); fill_test_data_2_f32x4(td_t_f32);

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_s_u32[i] = read_f32_as_u32(td_s_f32[i]);
		td_t_u32[i] = read_f32_as_u32(td_t_f32[i]);
	}


	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i) {
		td_d_u32[i] = td_s_u32[i] ^ td_t_u32[i];
		td_d_f32[i] = read_u32_as_f32(td_d_u32[i]);
	}
	vf32x4 dst_vf32 = xor_vf32x4(load_vf32x4(td_s_f32), load_vf32x4(td_t_f32));

	for (size_t i = 0; i < VF32X4_NUM_ELEMENT; ++i)
		if (read_f32_as_u32(at_vf32x4(dst_vf32, i)) != td_d_u32[i])
			return 0;
	afree(td_s_f32); afree(td_t_f32); afree(td_d_f32);
	afree(td_s_u32); afree(td_t_u32); afree(td_d_u32);
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
	TEST_CASE(arcp);
	TEST_CASE(sqrt);
	TEST_CASE(or);
	TEST_CASE(and);
	TEST_CASE(not);
	TEST_CASE(xor);
    return 0;
}
