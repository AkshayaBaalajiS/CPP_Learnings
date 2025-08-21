cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

add_definitions(-DCPP)
add_definitions(-DSOME_CLASS)


add_executable(output.out 
${CMAKE_SOURCE_DIR}/types_of_exceptions.cpp
)

target_include_directories(output.out PRIVATE
${CMAKE_SOURCE_DIR}
)

target_link_libraries(output.out PRIVATE
${CMAKE_SOURCE_DIR}/library.a
)