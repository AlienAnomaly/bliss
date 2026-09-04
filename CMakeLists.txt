cmake_minimum_required(VERSION 4.3)
project(bliss)

include_directories(C:/w64devkit/include headers external/include)

set(CMAKE_CXX_STANDARD 20)

add_executable(bliss src/main.cpp
        src/window.cpp
        headers/window.h
        src/renderer.cpp
        headers/renderer.h
        src/game.cpp
        headers/game.h
        headers/level.h
        src/level.cpp)

target_link_libraries(bliss PRIVATE SDL3 SDL3_image)
target_link_directories(bliss PRIVATE C:/w64devkit/lib)
