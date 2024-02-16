cmake_minimum_required(VERSION 3.13)

# set the project name and version
project(CAR VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set libraries variables
set(SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/CAR_App.cpp)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# include directories for my libraries
include_directories(${INCLUDE_DIR}/RobotArmLib/include)
include_directories(${INCLUDE_DIR}/GUI_Core/include)

# include directories for external libraries
include_directories(${INCLUDE_DIR}/RobotArmLib/extern/Eigen)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/imgui)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/GLFW/include)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bgfx/include)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bgfx/3rdparty)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bgfx/3rdparty/khronos)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bgfx/examples)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bx/include)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bx/3rdparty)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bimg/include)
include_directories(${INCLUDE_DIR}/GUI_Core/extern/bgfx.cmake/bimg/3rdparty)

add_subdirectory(${INCLUDE_DIR}/RobotArmLib)
add_subdirectory(${INCLUDE_DIR}/GUI_Core)

# add the executable
if (WIN32)
    # add_executable(CAR_App WIN32 ${SOURCE_FILE})
    add_executable(CAR_App ${SOURCE_FILE})
else ()
    add_executable(CAR_App ${SOURCE_FILE})
endif ()

# target my libraries
target_link_libraries(CAR_App PRIVATE RobotArmLib GUI_Core)

# target Windows libraries
if (WIN32)
    target_link_libraries(CAR_App PRIVATE -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl, -Bdynamic)
endif (WIN32)