cmake_minimum_required(VERSION 3.0)

add_executable(test_avx2 ./src/test_avx2.c)
set_property(TARGET test_avx2 PROPERTY C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/../inc)
include_directories(${PROJECT_SOURCE_DIR}/inc)
message("CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}")
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

if((CMAKE_C_COMPILER_ID MATCHES "GNU") OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
	set(CMAKE_C_FLAGS "-mavx2 -pedantic -Wall")
elseif(CMAKE_C_COMPILER_ID MATCHES "Intel")
	set(CMAKE_C_FLAGS "/QxAVX2")
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_C_FLAGS " /arch:AVX2 /D__AVX2__ /Wall")
endif()
message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
