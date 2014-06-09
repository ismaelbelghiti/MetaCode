cmake_minimum_required(VERSION 2.6)

project(MetaCodeAST)

#Library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(include)

file(GLOB_RECURSE include_files include/*.h)

file(GLOB_RECURSE source_files src/*.cpp)

add_library(meta_code_ast ${include_files} ${source_files})
