# CMake version
cmake_minimum_required(VERSION 3.13)
# Project name
project(RobotArmLib)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# External libraries
# Eigen
set(EIGEN_DIR ${RobotArmLib_SOURCE_DIR}/extern/Eigen)
add_subdirectory(extern/Eigen)

# Set 'RAL_SOURCES' variable
file(GLOB_RECURSE RAL_SOURCES CONFIGURE_DEPENDS "include/*.h"
                                                "src/*.cpp")

# Build RAL library 
add_library(RobotArmLib ${RAL_SOURCES})

# Link libraries
target_link_libraries(RobotArmLib Eigen3::Eigen)