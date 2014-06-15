cmake_minimum_required(VERSION 2.6)

project(CodeFromAST)

#Library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE include_files include/*.h)

file(GLOB_RECURSE source_files src/*.cpp)

include_directories(${MetaCodeAST_SOURCE_DIR}/include include)

add_library(codefromast SHARED ${include_files} ${source_files})

#Example

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

link_directories(${CMAKE_BINARY_DIR}/lib)

add_executable(codegen_example examples/codegen_example.cpp)

target_link_libraries(codegen_example codefromast metacodeast)
