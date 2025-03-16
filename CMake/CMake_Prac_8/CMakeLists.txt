cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

add_definitions(-DCPP)
add_definitions(-DINTERFACE)

# add_library(<library_name> [STATIC|SHARED|MODULE] <source_files>)
add_library(library STATIC ${CMAKE_SOURCE_DIR}/InterfaceClass.cpp)

# Set the output directory for the static library (.a)
# set_target_properties(MyLibrary PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/static  # For static (.a) library
# )

# # If you are building a shared library (.so), you can use LIBRARY_OUTPUT_DIRECTORY:
# # set_target_properties(MyLibrary PROPERTIES
# #     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/shared  # For shared (.so) library
# # )

set_target_properties(library PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)

add_executable(output.out 
${CMAKE_SOURCE_DIR}/unique_ptr.cpp
)

target_include_directories(output.out PRIVATE 
${CMAKE_SOURCE_DIR}/InterfaceClass.h
)

target_link_libraries(output.out
${CMAKE_SOURCE_DIR}/lib/liblibrary.a
)

message("CMAKE Run Successfully ")