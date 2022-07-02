cmake_minimum_required(VERSION 3.22)

project(nacos-sdk-cpp14)

set(CMAKE_CXX_FLAGS "/utf-8")
set(CMAKE_CXX_STANDARD 14)

include_directories (
.
include
)

aux_source_directory( src SRCS_DIRS)
aux_source_directory( src/utils SRCS_DIRS)

add_library(nacos-cli SHARED ${SRCS_DIRS})
add_library(nacos-cli-static STATIC ${SRCS_DIRS})

target_compile_definitions(nacos-cli PRIVATE SDK_SHARED)