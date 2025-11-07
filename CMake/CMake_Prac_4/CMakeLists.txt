cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

add_definitions(-DCLASSIMP)

if (NOT DEFINED FOLDER)
    message("Please use cmake -D FOLDER= FOLDER_NAME")
endif()

add_executable(output.out 
${FOLDER}/SampleClass.cpp
${FOLDER}/main_program.cpp
)


if (DEFINED HEADER)
    target_include_directories(output.out PRIVATE ${HEADER})
else()
    message(FATAL_ERROR "HEADER is not defined.")
endif()


target_link_libraries(output.out PRIVATE ${CMAKE_SOURCE_DIR}/library.a)