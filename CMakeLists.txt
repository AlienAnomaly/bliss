cmake_minimum_required(VERSION 3.25)

project(bliss)

include_directories(headers)

add_executable(bliss
    src/main.cpp
    src/window.cpp
    src/renderer.cpp)

target_link_libraries(bliss PRIVATE SDL3 SDL3_image m)