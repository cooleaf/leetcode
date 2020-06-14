cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(LeetCode)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(testee ${CMAKE_PROJECT_NAME}_lib)

enable_testing()

include_directories(include)
link_directories(${CMAKE_BINARY_DIR}/lib)
add_subdirectory(src)
add_subdirectory(test)

