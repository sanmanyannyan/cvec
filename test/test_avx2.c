#include <assert.h>
#include <stdio.h>
#include <stdint.h>


#define CVEC256
#include "cvec.h"

// test for aligned malloc and free
int test1(){
    uintptr_t ptr = (uintptr_t)amalloc(sizeof(double), MEMORY_ALIGNMENT);
    uintptr_t alignment = ptr & (MEMORY_ALIGNMENT - 1);
    afree((void *)ptr);
    return alignment == 0;
}

// test for load
int test2(){
    int32_t *src;
    src = (int32_t *)amalloc(sizeof(vi32), MEMORY_ALIGNMENT);
    src[0] = 0; src[1] = 1; src[2] = 2; src[3] = 3;
    src[4] = 4; src[5] = 5; src[6] = 6; src[7] = 7;
    //vi32 vec = load_vi32(src);
    //__m256i vec = _mm256_load_si256((__m256i *)src);
    __m256i vec = load_vi32(src);
    int result =
        src[0] == ((int32_t *)(&vec))[0] &&
        src[1] == ((int32_t *)(&vec))[1] &&
        src[2] == ((int32_t *)(&vec))[2] &&
        src[3] == ((int32_t *)(&vec))[3] &&
        src[4] == ((int32_t *)(&vec))[4] &&
        src[5] == ((int32_t *)(&vec))[5] &&
        src[6] == ((int32_t *)(&vec))[6] &&
        src[7] == ((int32_t *)(&vec))[7];
    afree(src);
    return result;
}

// test for loadu
int test3(){
    int32_t src[] = {0, 1, 2, 3, 4, 5, 6, 7};
    vi32 vec = loadu_vi32(src);
    return
        src[0] == ((int32_t *)(&vec))[0] &&
        src[1] == ((int32_t *)(&vec))[1] &&
        src[2] == ((int32_t *)(&vec))[2] &&
        src[3] == ((int32_t *)(&vec))[3] &&
        src[4] == ((int32_t *)(&vec))[4] &&
        src[5] == ((int32_t *)(&vec))[5] &&
        src[6] == ((int32_t *)(&vec))[6] &&
        src[7] == ((int32_t *)(&vec))[7];
}

// test for add
int test4(){
    int32_t arg1[] = {0, 1, 2, 3, 4,  5,  6,  7};
    int32_t arg2[] = {1, 2, 3, 4, 5,  6,  7,  8};
    int32_t res[] =  {1, 3, 5, 7, 9, 11, 13, 15};
    vi32 s1 = loadu_vi32(arg1);
    vi32 s2 = loadu_vi32(arg2);
	vi32 s3 = add_vi32(s1,s2);
    return
        res[0] == ((int32_t *)(&s3))[0] &&
        res[1] == ((int32_t *)(&s3))[1] &&
        res[2] == ((int32_t *)(&s3))[2] &&
        res[3] == ((int32_t *)(&s3))[3] &&
        res[4] == ((int32_t *)(&s3))[4] &&
        res[5] == ((int32_t *)(&s3))[5] &&
        res[6] == ((int32_t *)(&s3))[6] &&
        res[7] == ((int32_t *)(&s3))[7];
}

// test for sub
int test5(){
    int32_t arg1[] = { 0,  1,  2,  3,  4,  5,  6,  7};
    int32_t arg2[] = { 1,  2,  3,  4,  5,  6,  7,  8};
    int32_t res[] =  {-1, -1, -1, -1, -1, -1, -1, -1};
    vi32 s1 = loadu_vi32(arg1);
    vi32 s2 = loadu_vi32(arg2);
	vi32 s3 = sub_vi32(s1,s2);
    return
        res[0] == ((int32_t *)(&s3))[0] &&
        res[1] == ((int32_t *)(&s3))[1] &&
        res[2] == ((int32_t *)(&s3))[2] &&
        res[3] == ((int32_t *)(&s3))[3] &&
        res[4] == ((int32_t *)(&s3))[4] &&
        res[5] == ((int32_t *)(&s3))[5] &&
        res[6] == ((int32_t *)(&s3))[6] &&
        res[7] == ((int32_t *)(&s3))[7];
}

// test for div
int test6(){
    float arg1[] = { 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f};
    float arg2[] = { 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f};
    float res[] =  { 1.f / 2.f, 1.f / 3.f, 1.f / 4.f, 1.f / 5.f,
	                 1.f / 6.f, 1.f / 7.f, 1.f / 8.f, 1.f / 9.f};
    vflt s1 = loadu_vi32(arg1);
	vflt s2 = loadu_vi32(arg2);
	vflt s3 = div_vflt(s1,s2);
    return
        res[0] == ((float *)(&s3))[0] &&
        res[1] == ((float *)(&s3))[1] &&
        res[2] == ((float *)(&s3))[2] &&
        res[3] == ((float *)(&s3))[3] &&
        res[4] == ((float *)(&s3))[4] &&
        res[5] == ((float *)(&s3))[5] &&
        res[6] == ((float *)(&s3))[6] &&
        res[7] == ((float *)(&s3))[7];
}

int main(int argc, char* argv[]){
    assert(test1() && "testcase for aligned malloc");
    assert(test2() && "testcase for load");
    assert(test3() && "testcase for loadu");
    assert(test4() && "testcase for add");
    assert(test5() && "testcase for sub");
    assert(test6() && "testcase for div");
    return 0;
}
