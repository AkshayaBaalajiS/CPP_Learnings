cmake_minimum_required(VERSION 3.9)

project(Name_of_project)

include_directories(${CMAKE_SOURCE_DIR})

add_library(alib SHARED header.cpp)

add_executable(output main.cpp)

target_link_libraries(output alib )