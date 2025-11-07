cmake_minimum_required(VERSION 3.10)

project(SampleCMakeProject)

if(NOT DEFINED FILE)
    message("FILE is not given at CMake please give -D FILE= filename.cpp at time of CMake")
endif()

add_definitions(-DCPP)

add_executable(output.out ${FILE})