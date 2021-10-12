cmake_minimum_required(VERSION 3.20)
project(Lab02x)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(Lab02x src/main.cpp include/calc.h src/calc.cpp)
