cmake_minimum_required(VERSION 3.5)

project(blatt6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(io io.cc)
add_library(statistics statistics.cc)

add_executable(readvector readvector.cc)
add_executable(normal normal.cc)
add_executable(uniform uniform.cc)

target_link_libraries(readvector PUBLIC io statistics)
target_link_libraries(normal PUBLIC io statistics)
target_link_libraries(uniform PUBLIC io statistics)

enable_testing()

add_executable(meantest meantest.cc)
target_link_libraries(meantest PUBLIC statistics io)
add_test(NAME meantest COMMAND meantest)

add_executable(mediantest mediantest.cc)
target_link_libraries(mediantest PUBLIC statistics io)
add_test(NAME mediantest COMMAND mediantest)