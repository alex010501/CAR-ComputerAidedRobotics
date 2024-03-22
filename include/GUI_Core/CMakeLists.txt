# CMake version
cmake_minimum_required(VERSION 3.13)
# Project name
project(GUI_Core)

# OpenGL adding
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
include_directories(src ${OPENGL_INCLUDE_DIRS})

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

### External libraries ###

## GLAD - OpenGL loader ##
add_subdirectory(extern/glad)

## GLFW - OpenGL window ##
add_subdirectory(extern/glfw)

## stb_image - image loading ##
add_subdirectory(extern/stb_image)

## glm - math ##
add_subdirectory(extern/glm)

## assimp - 3D model loading ##
set(BUILD_SHARED_LIBS FALSE CACHE BOOL "x" FORCE)
set(ASSIMP_NO_EXPORT TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_TESTS FALSE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT FALSE CACHE BOOL "x" FORCE)
set(ASSIMP_INSTALL_PDB FALSE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_ZLIB TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS FALSE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_COLLADA_IMPORTER TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_OBJ_IMPORTER TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_FBX_IMPORTER TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_BLEND_IMPORTER TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_STL_IMPORTER TRUE CACHE BOOL "x" FORCE)
set(ASSIMP_BUILD_IFC_IMPORTER TRUE CACHE BOOL "x" FORCE)
add_subdirectory(extern/assimp)

# ## Bullet - physics ##
set(BULLET_VERSION 2.88)
include_directories(extern/bullet/src)
add_subdirectory(extern/bullet/src/BulletCollision)
add_subdirectory(extern/bullet/src/BulletDynamics)
add_subdirectory(extern/bullet/src/BulletSoftBody)
add_subdirectory(extern/bullet/src/BulletInverseDynamics)
add_subdirectory(extern/bullet/src/LinearMath)

## ImGui - GUI ##
set(imgui-directory extern/imgui)
set(imgui-source ${imgui-directory}/imconfig.h
	             ${imgui-directory}/imgui.h
                 ${imgui-directory}/imgui.cpp
                 ${imgui-directory}/imgui_draw.cpp
                 ${imgui-directory}/imgui_internal.h
                 ${imgui-directory}/imgui_widgets.cpp
                 ${imgui-directory}/imstb_rectpack.h
                 ${imgui-directory}/imstb_textedit.h
                 ${imgui-directory}/imstb_truetype.h
                 ${imgui-directory}/imgui_tables.cpp
                 ${imgui-directory}/imgui_demo.cpp
                 ${imgui-directory}/implot.h
                 ${imgui-directory}/implot.cpp
                 ${imgui-directory}/implot_internal.h
                 ${imgui-directory}/implot_items.cpp
                 ${imgui-directory}/backends/imgui_impl_glfw.cpp
                 ${imgui-directory}/backends/imgui_impl_opengl3.cpp
)

# Set 'GUI_Source' variable 
file(GLOB_RECURSE GUI_Sources CONFIGURE_DEPENDS "include/*.h"
                                                "src/*.cpp"
                                                "include/EventHandler/*.h"
                                                "include/2D/*.h"
                                                "src/2D/*.cpp"
                                                "include/UI/*.h"
                                                "src/UI/*.cpp"
                                                "include/3D/*.h"                                            
                                                "src/3D/*.cpp"
                                                "include/ShadersBuffers/*.h"
                                                "src/ShadersBuffers/*.cpp")
                                                
# Build GUI_Core library
add_library(GUI_Core ${GUI_Sources} ${imgui-source})

# Link external libraries
target_link_libraries(GUI_Core ${OPENGL_LIBRARIES} glad glfw stb_image glm assimp BulletDynamics BulletCollision BulletSoftBody BulletInverseDynamics LinearMath)
target_include_directories(GUI_Core PUBLIC ${imgui-directory})
target_include_directories(GUI_Core PUBLIC extern/bullet/src)