cmake_minimum_required(VERSION 3.20)
project(Lab04)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Lab04 src/main.cpp src/struktury.cpp src/klasy.cpp)
