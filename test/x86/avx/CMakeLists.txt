cmake_minimum_required(VERSION 3.0)

add_executable(test_avx ./src/test_avx.c)
set_property(TARGET test_avx PROPERTY C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/../../inc)
include_directories(${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(test_avx m)
message("CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}")
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

if((CMAKE_C_COMPILER_ID MATCHES "GNU") OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
	set(CMAKE_C_FLAGS " -mavx -Wall")
elseif(CMAKE_C_COMPILER_ID MATCHES "Intel")
	set(CMAKE_C_FLAGS " /QxAVX")
elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_C_FLAGS " /arch:AVX /D__AVX__ /Wall")
endif()
message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
