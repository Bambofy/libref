cmake_minimum_required(VERSION 3.19)
project(libref)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.c*)
file(GLOB_RECURSE HEADER ${PROJECT_SOURCE_DIR}/include/*.h*)

add_library(libref ${SRC} ${HEADER})

target_include_directories(libref PUBLIC ${PROJECT_SOURCE_DIR}/include)