cmake_minimum_required(VERSION 3.0)

add_executable(test_sse2 ./src/test_sse2.c)
set_property(TARGET test_sse PROPERTY C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/../../inc)
include_directories(${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(test_sse2 m)
message("CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}")
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

if((CMAKE_C_COMPILER_ID MATCHES "GNU") OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
	set(CMAKE_C_FLAGS " -msse2 -Wall")
elseif(CMAKE_C_COMPILER_ID MATCHES "Intel")
	if (WIN32)
		set(CMAKE_C_FLAGS " /arch:sse2")
	endif (WIN32)

elseif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_C_FLAGS " /arch:SSE2 /D__SSE2__ /Wall")
endif()
message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
