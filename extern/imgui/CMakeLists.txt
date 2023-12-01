cmake_minimum_required(VERSION 3.13)
project(IMGUI)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(IMGUI_SOURCES
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_widgets.cpp
    imgui_impl_bgfx.cpp
    imgui_impl_sdl.cpp
)

add_library(IMGUI ${IMGUI_SOURCES})

target_link_libraries(IMGUI SDL3::SDL3)