
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

  int8_t at_i8 (void* ptr, size_t lane) { return ((  int8_t *)ptr)[lane]; }
 uint8_t at_u8 (void* ptr, size_t lane) { return (( uint8_t *)ptr)[lane]; }
 int16_t at_i16(void* ptr, size_t lane) { return (( int16_t *)ptr)[lane]; }
uint16_t at_u16(void* ptr, size_t lane) { return ((uint16_t *)ptr)[lane]; }
 int32_t at_i32(void* ptr, size_t lane) { return (( int32_t *)ptr)[lane]; }
uint32_t at_u32(void* ptr, size_t lane) { return ((uint32_t *)ptr)[lane]; }
 int64_t at_i64(void* ptr, size_t lane) { return (( int64_t *)ptr)[lane]; }
uint64_t at_u64(void* ptr, size_t lane) { return ((uint64_t *)ptr)[lane]; }
   float at_f32(void* ptr, size_t lane) { return ((   float *)ptr)[lane]; }
  double at_f64(void* ptr, size_t lane) { return ((  double *)ptr)[lane]; }


int equals(void* ptr1, void* ptr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (((uint8_t*)ptr1)[i] != ((uint8_t*)ptr2)[i]) {
			return 0;
		}
	}
	return 1;
}

int neq_f32(float a, float b) {
	return (isnan(a) != isnan(b)) || (!isnan(a) && !isnan(b) && a != b);
}
int neq_f64(double a, double b) {
	return (isnan(a) != isnan(b)) || (!isnan(a) && !isnan(b) && a != b);
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

void fill_test_data_1_f32x4(void* ptr) {
	fill_test_data_128(ptr);
}
void fill_test_data_2_f32x4(void* ptr) {
	fill_test_data_128(ptr);
}
void fill_test_data_256(void* ptr) {
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
	buff[16] = rand() % (UINT8_MAX + 1);
	buff[17] = rand() % (UINT8_MAX + 1);
	buff[18] = rand() % (UINT8_MAX + 1);
	buff[19] = rand() % (UINT8_MAX + 1);
	buff[20] = rand() % (UINT8_MAX + 1);
	buff[21] = rand() % (UINT8_MAX + 1);
	buff[22] = rand() % (UINT8_MAX + 1);
	buff[23] = rand() % (UINT8_MAX + 1);
	buff[24] = rand() % (UINT8_MAX + 1);
	buff[25] = rand() % (UINT8_MAX + 1);
	buff[26] = rand() % (UINT8_MAX + 1);
	buff[27] = rand() % (UINT8_MAX + 1);
	buff[28] = rand() % (UINT8_MAX + 1);
	buff[29] = rand() % (UINT8_MAX + 1);
	buff[30] = rand() % (UINT8_MAX + 1);
	buff[31] = rand() % (UINT8_MAX + 1);
}
void fill_test_data_1_vi8x32 (void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vi8x32 (void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vu8x32 (void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vu8x32 (void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vi16x16(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vi16x16(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vu16x16(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vu16x16(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vi32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vi32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vu32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vu32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vi64x4(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vi64x4(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vu64x4(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vu64x4(void* ptr) {
	fill_test_data_256(ptr);
}

void fill_test_data_1_vf32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vf32x8(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_1_vf64x4(void* ptr) {
	fill_test_data_256(ptr);
}
void fill_test_data_2_vf64x4(void* ptr) {
	fill_test_data_256(ptr);
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
void fill_test_data_256(void* ptr) {
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
void fill_test_data_1_vi8x32 (void* ptr) {
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
void fill_test_data_2_vi8x32 (void* ptr) {
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
void fill_test_data_1_vu8x32 (void* ptr) {
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
void fill_test_data_2_vu8x32 (void* ptr) {
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
void fill_test_data_1_vi16x16(void* ptr) {
	int16_t *buff = (int16_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] =   -1; buff[ 9] =   -2; buff[10] =   -3; buff[11] =   -4;
    buff[12] =   -5; buff[13] =   -6; buff[14] =   -7; buff[15] =   -8;
}
void fill_test_data_2_vi16x16(void* ptr) {
	int16_t *buff = (int16_t *)ptr;
    buff[ 0] =   -1; buff[ 1] =   -2; buff[ 2] =   -3; buff[ 3] =   -4;
    buff[ 4] =   -5; buff[ 5] =   -6; buff[ 6] =   -7; buff[ 7] =   -8;
	buff[ 8] = 0x00; buff[ 9] = 0x01; buff[10] = 0x02; buff[11] = 0x03;
    buff[12] = 0x04; buff[13] = 0x05; buff[14] = 0x06; buff[15] = 0x07;
}
void fill_test_data_1_vu16x16(void* ptr) {
	uint16_t *buff = (uint16_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
    buff[ 8] = 0x08; buff[ 9] = 0x09; buff[10] = 0x0A; buff[11] = 0x0B;
    buff[12] = 0x0C; buff[13] = 0x0D; buff[14] = 0x0E; buff[15] = 0x0F;
}
void fill_test_data_2_vu16x16(void* ptr) {
	uint8_t *buff = (uint8_t *)ptr;
    buff[ 0] = 0x08; buff[ 1] = 0x07; buff[ 2] = 0x06; buff[ 3] = 0x05;
	buff[ 4] = 0x04; buff[ 5] = 0x03; buff[ 6] = 0x02; buff[ 7] = 0x01;
	buff[ 8] = 0x10; buff[ 9] = 0x0F; buff[10] = 0x0E; buff[11] = 0x0D;
	buff[12] = 0x0C; buff[13] = 0x0B; buff[14] = 0x0A; buff[15] = 0x09;
}
void fill_test_data_1_vi32x8(void* ptr) {
	int32_t *buff = (int32_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
}
void fill_test_data_2_vi32x8(void* ptr) {
	int32_t *buff = (int32_t *)ptr;
    buff[ 0] =   -1; buff[ 1] =   -2; buff[ 2] =   -3; buff[ 3] =   -4;
    buff[ 4] =    3; buff[ 5] =    4; buff[ 6] =    5; buff[ 7] =    6;
}
void fill_test_data_1_vu32x8(void* ptr) {
	uint32_t *buff = (uint32_t *)ptr;
	buff[ 0] = 0x00; buff[ 1] = 0x01; buff[ 2] = 0x02; buff[ 3] = 0x03;
    buff[ 4] = 0x04; buff[ 5] = 0x05; buff[ 6] = 0x06; buff[ 7] = 0x07;
}
void fill_test_data_2_vu32x8(void* ptr) {
	uint32_t *buff = (uint32_t *)ptr;
	buff[ 0] = 0x04; buff[ 1] = 0x03; buff[ 2] = 0x02; buff[ 3] = 0x01;
    buff[ 4] = 0x08; buff[ 5] = 0x07; buff[ 6] = 0x06; buff[ 7] = 0x05;
}
void fill_test_data_1_vi64x4(void* ptr) {
	int64_t *buff = (int64_t *)ptr;
	buff[0] = 0x00; buff[1] = 0x01; buff[2] = 0x02; buff[3] = 0x03;
}
void fill_test_data_2_vi64x4(void* ptr) {
	int64_t *buff = (int64_t *)ptr;
	buff[0] = -1; buff[1] = -2; buff[2] =  3; buff[3] =  4;
}
void fill_test_data_1_vu64x4(void* ptr) {
	uint64_t *buff = (uint64_t *)ptr;
	buff[0] = 0x00; buff[1] = 0x01; buff[2] = 0x02; buff[3] = 0x03;
}
void fill_test_data_2_vu64x4(void* ptr) {
	uint64_t *buff = (uint64_t *)ptr;
	buff[0] = 0x04; buff[1] = 0x03; buff[2] = 0x02; buff[3] = 0x01;
}

void fill_test_data_1_vf32x8(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] = 13019.f / 60520.f; buff[1] =  -9497.f / 49875.f;
	buff[2] = 20204.f / 37479.f; buff[3] = -15512.f / 34346.f;
	buff[4] =  7974.f /  4123.f; buff[5] = -16267.f / 34951.f;
	buff[6] = 49203.f / 20624.f; buff[7] = -46469.f / 61280.f;
}
void fill_test_data_2_vf32x8(void* ptr) {
	float *buff = (float *)ptr;
	buff[0] =   5336.f / 10925.f; buff[1] =  40659.f / 28889.f;
	buff[2] = -19322.f / 34130.f; buff[3] = -18976.f / 54979.f;
	buff[4] =  42847.f /  9629.f; buff[5] =  35927.f / 13327.f;
	buff[6] = -55302.f / 50863.f; buff[7] = -52181.f / 37305.f;
}
void fill_test_data_1_vf64x4(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] =  1484247589. / 1125869882.; buff[1] =  2300945531. / 2377086944.;
	buff[2] = -4252797847. / 1547484551.; buff[3] = -3750258763. /  423635020.;
}
void fill_test_data_2_vf64x4(void* ptr) {
	double *buff = (double *)ptr;
	buff[0] = 3719188231. / 3935180964.; buff[1] = -2347073493. /  344925761.;
	buff[2] =   52388287. / 2420590488.; buff[3] = -3818747595. / 1910194483.;
}


#endif

