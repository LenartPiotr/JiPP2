cmake_minimum_required(VERSION 3.20)
project(Lab05)

set(CMAKE_CXX_STANDARD 14)

include_directories(KonstruktoryKopiujace/Zad1/include)
include_directories(KonstruktoryKopiujace/include)
include_directories(ConstStatic/include)

add_executable(Lab05 main.cpp KonstruktoryKopiujace/Zad1/src/Point.cpp KonstruktoryKopiujace/Zad1/src/main.cpp KonstruktoryKopiujace/Zad2/zad2.cpp ConstStatic/Zad1/zad1.cpp)