cmake_minimum_required(VERSION 3.13)
project(GUI_Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI_Core.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/GUI_Core.h
    # ${GUI_Core_SOURCE_DIR}/src/2D/BaseFigure.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_3DWorkspace.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_Console.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_LibraryViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_PropertiesViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_SceneTreeViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_ToolPanel.cpp

    # ${GUI_Core_SOURCE_DIR}/src/3D/BaseObject.cpp
    # ${GUI_Core_SOURCE_DIR}/src/3D/RenderWindow.cpp
)

set(GUI_EXTERN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(GUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BGFX_C_DIR ${GUI_EXTERN_DIR}/bgfx.cmake)
set(BGFX_DIR ${BGFX_C_DIR}/bgfx)
set(BIMG_DIR ${BGFX_C_DIR}/bimg)
set(BX_DIR ${BGFX_C_DIR}/bx)

find_package(bgfx)

# add subdirectories for external libraries
add_subdirectory(${GUI_EXTERN_DIR}/bgfx.cmake)
add_subdirectory(${GUI_EXTERN_DIR}/imgui)
add_subdirectory(${GUI_EXTERN_DIR}/GLFW)

# include directories for my libraries
include_directories(${GUI_INCLUDE_DIR})

# include directories for GLFW files
include_directories(${GUI_EXTERN_DIR}/GLFW/include)

# include directories for imgui files
include_directories(${GUI_EXTERN_DIR}/imgui)

# include directories for bgfx files
include_directories(${BGFX_C_DIR}/bgfx/include)
include_directories(${BGFX_C_DIR}/bgfx/3rdparty)
include_directories(${BGFX_C_DIR}/bgfx/3rdparty/khronos)
include_directories(${BGFX_C_DIR}/bgfx/examples)
# include directories for bx files
include_directories(${BGFX_C_DIR}/bx/include)
include_directories(${BGFX_C_DIR}/bx/3rdparty)
# include directories for bimg files
include_directories(${BGFX_C_DIR}/bimg/include)
include_directories(${BGFX_C_DIR}/bimg/3rdparty)

add_library(GUI_Core ${GUI_SOURCES})

# target imgui
target_link_libraries(GUI_Core PRIVATE IMGUI)
# target glfw and bgfx
target_link_libraries(GUI_Core PRIVATE bgfx glfw)