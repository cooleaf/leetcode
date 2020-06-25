cmake_minimum_required(VERSION 3.10)

#aux_source_directory(. srclist)

set(srclist Random.cpp NumberSolution.cpp)
add_library(${testee} STATIC ${srclist})
set(srclist ${srclist} main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${srclist})
