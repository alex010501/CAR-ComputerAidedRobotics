cmake_minimum_required(VERSION 3.13)
project(GUI_Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GUI_Core.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_3DWorkspace.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_Console.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_LibraryViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_PropertiesViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_SceneTreeViewer.cpp
    ${GUI_Core_SOURCE_DIR}/src/2D/UIWindow_ToolPanel.cpp
)

set(GUI_EXTERN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(GUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add OpenGL dependencies
find_package(OpenGL REQUIRED)

# Add external dependencies 
add_subdirectory(extern)

# include directories for my libraries
include_directories(include)

# include directories for external libraries
include_directories(
	extern/GLFW/include/
	external/GLM/
	external/GLEW/include/
	external/assimp/include/
	external/bullet3/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW
	GLEW
    imgui
    assimp
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# target GUI_Core
add_library(GUI_Core ${GUI_SOURCES})

# target libraries
target_link_libraries(GUI_Core ${ALL_LIBS})