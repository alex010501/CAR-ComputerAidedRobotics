cmake_minimum_required(VERSION 3.13)
project(IMGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GUI_EXTERN_DIR ${GUI_Core_SOURCE_DIR}/extern)

set(IMGUI_SOURCES
    imconfig.h
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp
    imgui.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    backends/imgui_impl_bgfx.cpp
    backends/imgui_impl_bgfx.h
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_glfw.h
)

include_directories(${GUI_EXTERN_DIR}/GLFW/include)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bgfx/include)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bgfx/3rdparty)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bgfx/examples)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bx/include)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bx/3rdparty)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bimg/include)
include_directories(${GUI_EXTERN_DIR}/bgfx.cmake/bimg/3rdparty)

add_library(IMGUI ${IMGUI_SOURCES})

target_link_libraries(IMGUI INTERFACE bgfx glfw)