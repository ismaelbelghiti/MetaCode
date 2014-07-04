cmake_minimum_required(VERSION 2.6)

project(MetaCodeAST)

#Library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE include_files include/*.h)

file(GLOB_RECURSE source_files src/*.cpp)

include_directories(include)

add_library(  metacodeast SHARED   ${include_files}   ${source_files} )

#Example

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

link_directories(${CMAKE_BINARY_DIR}/lib)

add_executable(basic_example1 examples/basic_example1.cpp)

target_link_libraries(basic_example1 metacodeast)

add_executable(test examples/test.cpp)

target_link_libraries(test metacodeast)