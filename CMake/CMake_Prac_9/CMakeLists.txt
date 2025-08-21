cmake_minimum_required(VERSION 3.10)

project(SampleCMake)

# set(CXX_FLAGS 17)

if(  NOT DEFINED FILE)
    message("PLEASE PROVIDE THE FILE ARGUMENT ON CMAKE ")
else()
    add_executable(output.txt ${FILE})
endif()