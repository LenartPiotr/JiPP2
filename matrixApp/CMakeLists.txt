include_directories(${CMAKE_SOURCE_DIR}/matrixLib/include)
add_executable(Lab02-Projekt src/main.cpp)
target_link_libraries(Lab02-Projekt matrixLib)
