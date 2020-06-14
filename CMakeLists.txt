cmake_minimum_required(VERSION 3.10)
project(LeetCode)

add_subdirectory(src src)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#add_library(test SHARED src/test.cpp)
