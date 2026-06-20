cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(
    include
    ${SDL2_INCLUDE_DIRS}
)

add_executable(
    GameOfLife
    src/main.cpp
    src/application.cpp
    src/grid.cpp
    src/renderer.cpp
    src/simulation.cpp
    src/counter.cpp
)

target_link_libraries(
    GameOfLife
    ${SDL2_LIBRARIES}
)