cmake_minimum_required(VERSION 3.20)
project(Lab06)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Lab06 src/main.cpp include/node.h src/node.cpp src/vector.cpp src/ImaginaryNumber.cpp include/triangle.h src/triangle.cpp)