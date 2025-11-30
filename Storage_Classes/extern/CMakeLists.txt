cmake_minimum_required(VERSION 3.1)

include_directories (${CMAKE_SOURCE_DIR}/include)

add_executable (output.out ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/classb.cpp)
# add executable dont accept directories 