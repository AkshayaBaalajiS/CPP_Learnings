cmake_minimum_required(VERSION 3.10)

project(Sample2)


#below is not recommended cause path should be relative 
#set(CUSTOM_PATH "/home/akshayabaalajis/Docker_Prac/prac_4/include")
#include_directories(${CUSTOM_PATH})

include_directories(${CMAKE_SOURCE_DIR}/include)

#the below is not correct cause cmake does not automatically expand *.cpp 
#add_library(library STATIC ${CMAKE_SOURCE_DIR}/src/*.cpp)


add_library(library STATIC ${CMAKE_SOURCE_DIR}/src/Solutions.cpp)


add_executable(problem_solution ${CMAKE_SOURCE_DIR}/test_dir/main.cpp)

target_link_libraries(problem_solution library)