cmake_minimum_required(VERSION 3.20)
project(Lab02_Projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Lab02_Projekt matrixApp/main.cpp matrixLib/matrixLib.cpp)
