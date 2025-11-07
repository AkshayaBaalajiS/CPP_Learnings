cmake_minimum_required(VERSION 3.10)

set (CXX_STANDARD_VERSION 17)
set (CXX_STANDARD_REQUIRED True)

add_executable(thread_out lockguard_with_threading.cpp)
