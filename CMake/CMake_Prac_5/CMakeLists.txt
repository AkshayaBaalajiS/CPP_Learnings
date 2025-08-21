cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

add_definitions(-DENABLE_DEBUG)


# include_directories(output.txt
# ${CMAKE_SOURCE_DIR}/DequeQueue.h
# )

add_executable(output.txt 
${CMAKE_SOURCE_DIR}/main.cpp
)


target_include_directories(output.txt PRIVATE
${CMAKE_SOURCE_DIR}/DequeQueue.h
)

