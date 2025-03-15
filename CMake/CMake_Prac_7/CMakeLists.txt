cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

add_definitions(-DCPP)
add_definitions(-DSTL)
add_definitions(-DABSTRACT_CLASS)

add_library(static_lib STATIC Abstraction.cpp)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_executable(output.out 
${CMAKE_SOURCE_DIR}/main.cpp
)

target_link_libraries(output.out PRIVATE 
${CMAKE_SOURCE_DIR}/lib/libstatic_lib.a
)