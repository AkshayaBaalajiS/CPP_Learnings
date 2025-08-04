cmake_minimum_required(VERSION 3.10)

project(Sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(lib STATIC src/problem_class.cpp)

add_executable(app main.cpp)

target_link_libraries(app lib)

