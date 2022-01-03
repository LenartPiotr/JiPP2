cmake_minimum_required(VERSION 3.21)
project(10_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(10_1 src/main.cpp src/csv_lib.c)

include_directories(include)
