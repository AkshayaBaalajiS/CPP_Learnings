cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD_VERSION 17)
set(CXX_STANDARD_REQUIRED True)

set(WORK_DIR $(CMAKE_SOURCE_DIR))

add_executable (server.exe all_in_one.cpp)
add_executable (client.exe client_Code.cpp)