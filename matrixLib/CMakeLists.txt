add_library(matrixLib STATIC include/matrixLib.h src/matrixLib.cpp)
target_include_directories(matrixLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)