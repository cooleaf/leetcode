aux_source_directory(. testfiles)

set(tester test${CMAKE_PROJECT_NAME})
add_executable(${tester} ${testfiles})
add_subdirectory(googletest)

include_directories(
    ${PROJECT_SOURCE_DIR}/test/googletest/googletest/include 
    ${PROJECT_SOURCE_DIR}/test/googletest/googlemock/include)

target_link_libraries(${tester} PUBLIC gmock gtest_main ${testee})

add_test(NAME ${tester} COMMAND ${CMAKE_BINARY_DIR}/bin/${tester})