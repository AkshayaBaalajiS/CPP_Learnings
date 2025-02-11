# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(DebugExample)

# Check if FILE is provided (the C++ source file)
if(DEFINED FILE)
    message(STATUS "Compiling: ${FILE}")
else()
    message(FATAL_ERROR "You must specify a source file with -D FILE=path_to_file.cpp")
endif()

# Add the specified file as the source
add_executable(debug_program ${FILE})

# Debug flags
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
