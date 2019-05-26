
#define TEST_CASE(func)                          \
do{                                              \
	if( TEST_FUNCTION(func)() ) {                \
		printf("test %s ", STR(func) );          \
		printf("passed");                        \
		printf(".\n")   ;                        \
	} else {                                     \
		printf("test %s ", STR(func) );          \
		printf("FAILED");                        \
		printf(".\n");                           \
	}                                            \
}while(0)

#define UNUSED(x) (void)(x)

#define STR(t) #t
#define TEST_FUNCTION(func) test_ ## func

union u32_f32 {
	float f32;
	uint32_t u32;
};

uint32_t read_f32_as_u32(float f) {
	union u32_f32 uf;
	uf.f32 = f;
	return uf.u32;
}

float read_u32_as_f32(uint32_t u) {
	union u32_f32 uf;
	uf.u32 = u;
	return uf.f32;
}

float load_test_data_f32(void* ptr, size_t lane) { return ((float*)ptr)[lane]; }

int equals(void* ptr1, void* ptr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (((uint8_t*)ptr1)[i] != ((uint8_t*)ptr2)[i]) {
			return 0;
		}
	}
	return 1;
}


#if defined(RANDOM_TEST_DATA)
void fill_test_data_128(void* ptr) {
	uint8_t* buff = (uint8_t*)ptr;
	buff[ 0] = rand() % (UINT8_MAX + 1);
	buff[ 1] = rand() % (UINT8_MAX + 1);
	buff[ 2] = rand() % (UINT8_MAX + 1);
	buff[ 3] = rand() % (UINT8_MAX + 1);
	buff[ 4] = rand() % (UINT8_MAX + 1);
	buff[ 5] = rand() % (UINT8_MAX + 1);
	buff[ 6] = rand() % (UINT8_MAX + 1);
	buff[ 7] = rand() % (UINT8_MAX + 1);
	buff[ 8] = rand() % (UINT8_MAX + 1);
	buff[ 9] = rand() % (UINT8_MAX + 1);
	buff[10] = rand() % (UINT8_MAX + 1);
	buff[11] = rand() % (UINT8_MAX + 1);
	buff[12] = rand() % (UINT8_MAX + 1);
	buff[13] = rand() % (UINT8_MAX + 1);
	buff[14] = rand() % (UINT8_MAX + 1);
	buff[15] = rand() % (UINT8_MAX + 1);
}
void fill_test_data_1_f32x4(float* addr) {
	addr[0] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[1] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[2] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[3] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
}
void fill_test_data_2_f32x4(float* addr) {
	addr[0] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[1] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[2] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
	addr[3] = (rand() & 1 ? -1.f : 1.f) * (rand() / ((float)rand() + 1.f));
}

#else
void fill_test_data_128(void* ptr) {
	uint8_t* buff = (uint8_t*)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
	buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
	buff[ 8] = 0xFF; buff[ 9] = 0xFE; buff[10] = 0xFD; buff[11] = 0xFC;
	buff[12] = 0xFB; buff[13] = 0xFA; buff[14] = 0xF9; buff[15] = 0xF8;
}
void fill_test_data_1_f32x4(float* addr) {
	addr[0] =  13019.f / 60520.f; addr[1] =   9497.f / 49875.f;
	addr[2] = -20204.f / 37479.f; addr[3] = -15512.f / 34346.f;
}
void fill_test_data_2_f32x4(float* addr) {
	addr[0] =  5336.f / 10925.f; addr[1] = -40659.f / 28889.f;
	addr[2] = 19322.f / 34130.f; addr[3] = -18976.f / 54979.f;
}
#endif

