# CMakeList.txt : CMake project for libref, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("libref")


file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.c*)
file(GLOB_RECURSE HEADER ${PROJECT_SOURCE_DIR}/include/*.h*)

add_executable(libref ${SRC} ${HEADER})

target_include_directories(libref PUBLIC ${PROJECT_SOURCE_DIR}/include)