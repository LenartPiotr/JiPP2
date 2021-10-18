cmake_minimum_required(VERSION 3.20)
project(Lab03)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Lab03 main.cpp include/lib.h src/PrzeciazanieFunkcji.cpp src/Tablice.cpp src/Wskazniki.cpp)
