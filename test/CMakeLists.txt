cmake_minimum_required(VERSION 3.0)

add_executable(test_avx2 test_avx2.c)
set_property(TARGET test_avx2 PROPERTY C_STANDARD 99)

set(INCLUDE_DIR
  ${PROJECT_SOURCE_DIR}/../inc
)
include_directories("${INCLUDE_DIR}")
message("CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}")

if((CMAKE_C_COMPILER_ID MATCHES "GNU") OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
	set(CMAKE_C_FLAGS "-mavx2")
elseif(CMAKE_C_COMPILER_ID MATCHES "Intel")
	set(CMAKE_C_FLAGS "/QxAVX2")
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
	target_compile_options(test_avx2 PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX2>)
endif()

