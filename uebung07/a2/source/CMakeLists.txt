cmake_minimum_required(VERSION 3.5)

project(blatt6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(point point.cc)
add_library(canvas canvas.cc)
add_library(pgm pgm.cc)

add_executable(main main.cc)
target_link_libraries(main PUBLIC point canvas)

add_executable(plot plot.cc)
target_link_libraries(canvas pgm point)
target_link_libraries(plot PUBLIC point canvas pgm)

enable_testing()

add_executable(ctest testcorners.cc)
target_link_libraries(ctest PUBLIC point canvas)
add_test(NAME ctest COMMAND ctest)