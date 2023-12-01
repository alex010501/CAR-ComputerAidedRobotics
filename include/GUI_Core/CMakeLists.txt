cmake_minimum_required(VERSION 3.13)
project(GUI_Core)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GUI_SOURCES
    GUI_Core.cpp
    2D/BaseFigure.cpp
    2D/UIWindow.cpp
    3D/BaseObject.cpp
    3D/RenderWindow.cpp
)


add_library(GUI_Core ${GUI_SOURCES})

target_link_libraries(GUI_Core SDL3::SDL3)