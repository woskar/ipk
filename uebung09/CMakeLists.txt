cmake_minimum_required(VERSION 3.5)

project(Mandelbrot LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(libs canvas.hh pgm.cc point.cc iterationresult.cc)

add_executable(main main.cc)

target_link_libraries(main PUBLIC libs)