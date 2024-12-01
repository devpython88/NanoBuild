cmake_minimum_required(VERSION 3.16)
project(nano_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O1 -g0")

add_executable(NanoBuild_x64 src/main.cpp src/block.h src/block.cpp src/player.h src/player.cpp
    src/other.h src/other.cpp)
target_link_libraries(NanoBuild_x64 raylib)