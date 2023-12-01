cmake_minimum_required(VERSION 3.13)

# set the project name and version
project(CAR VERSION 1.0)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set libraries variables
set(SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/CAR_App.cpp)
set(EXTERN_DIR ${PROJECT_SOURCE_DIR}/extern)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(EIGEN_DIR ${EXTERN_DIR}/Eigen)
set(SDL3_DIR ${EXTERN_DIR}/SDL3/lib/cmake/SDL3)
set(GLFW3_DIR ${EXTERN_DIR}/GLFW/lib/cmake/glfw3)
# set(SDL2_DIR ${EXTERN_DIR}/SDL2/lib/cmake/SDL2)
set(BGFX_C_DIR ${EXTERN_DIR}/bgfx.cmake)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(GLFW3 REQUIRED CONFIG REQUIRED COMPONENTS GLFW3-shared)
# find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2-static)
find_package(bgfx)

# include directories for my libraries
include_directories(${INCLUDE_DIR}/MathAdditions)
include_directories(${INCLUDE_DIR}/RobotArm)
include_directories(${INCLUDE_DIR}/GUI_Core)

# include directories for header files and Eigen library
include_directories(${EIGEN_DIR})

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

# include directories for SDL3 and GLFW files
include_directories(${EXTERN_DIR}/SDL3/include)
link_directories(${EXTERN_DIR}/SDL3/lib)
include_directories(${EXTERN_DIR}/GLFW/include)
link_directories(${EXTERN_DIR}/GLFW/lib)

# include directories for imgui files
include_directories(${EXTERN_DIR}/imgui)

add_subdirectory(${EXTERN_DIR}/bgfx.cmake)
add_subdirectory(${EXTERN_DIR}/imgui)
add_subdirectory(${INCLUDE_DIR}/MathAdditions)
add_subdirectory(${INCLUDE_DIR}/RobotArm)
add_subdirectory(${INCLUDE_DIR}/GUI_Core)


# add the executable
add_executable(CAR_App ${SOURCE_FILE})


# target my libraries
target_link_libraries(CAR_App RobotArm MathAdditions GUI_Core)

# target imgui library
target_link_libraries(CAR_App IMGUI)

# target graphic libraries and bgfx
target_link_libraries(CAR_App bgfx example-common)
target_link_libraries(CAR_App SDL3::SDL3 GLFW3)

# target windows libraries
target_link_libraries(CAR_App -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl, -Bdynamic)