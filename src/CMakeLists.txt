cmake_minimum_required(VERSION 3.10)

aux_source_directory(. srclist)

add_executable(${CMAKE_PROJECT_NAME} ${srclist})
add_library(${testee} STATIC ${srclist})