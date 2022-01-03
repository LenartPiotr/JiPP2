cmake_minimum_required(VERSION 3.21)
project(10_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(10_1 src/main.cpp src/csv_lib.c src/csv_CSVReader.cpp)

