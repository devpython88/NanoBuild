cmake_minimum_required(VERSION 3.16)
project(nano_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O3")
set(RESOURCE_FILE res.rc)
set(ICON_FILE "NanoBuildIcon.ico")

add_executable(NanoBuild_x64 src/main.cpp src/block.h src/block.cpp src/player.h src/player.cpp
    src/other.h src/other.cpp src/raylib.h src/raymath.h src/rlgl.h src/structures.h src/structures.cpp)

target_sources(NanoBuild_x64 PRIVATE ${RESOURCE_FILE})

target_link_libraries(NanoBuild_x64 raylib)