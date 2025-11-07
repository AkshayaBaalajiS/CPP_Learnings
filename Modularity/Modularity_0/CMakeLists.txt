cmake_minimum_required(VERSION 3.10)

project(SampleCMake2)

add_definitions(-DHEADER) # for adding the macro

# include_directories(${CMAKE_SOURCE_DIR})  # for including the header file 

add_executable(output.out program.cpp) # for creating the executable 

target_include_directories(output.out PRIVATE
${CMAKE_SOURCE_DIR}
)
# target_include_directories() syntax 
# The target_include_directories() command in CMake is used to specify the directories that should be added to the include path for a specific target (like an executable or library) during compilation. It allows you to tell the compiler where to look for header files.

# Basic Syntax:
# cmake
# Copy
# target_include_directories(<target> <INTERFACE|PUBLIC|PRIVATE> <directories>)
# <target>: The name of the target (e.g., an executable or a library).

# <INTERFACE|PUBLIC|PRIVATE>: The scope for which the include directories should be applied:

# PRIVATE: The directories are used only for the target’s own compilation.
# PUBLIC: The directories are used both for the target’s compilation and by targets that link to it.
# INTERFACE: The directories are used only by targets that link to the target (but not for the target itself).
# <directories>: The directories you want to add to the include path.


message("SOURCE DIR  = "  "${CMAKE_SOURCE_DIR}")  # this is how we have to use the message 
