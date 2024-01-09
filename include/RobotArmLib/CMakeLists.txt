cmake_minimum_required(VERSION 3.13)
project(RobotArmLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(RAL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RobotArmLib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RobotLink.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RobotJoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RobotAdditions.cpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MathAdditions.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/RobotArmLib.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/RobotLink.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/RobotJoint.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/RobotAdditions.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/MathAdditions.h
)

set(RAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(RAL_EXTERN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(EIGEN_DIR ${RAL_EXTERN_DIR}/Eigen)

# set(EIGEN3_DIR ${RAL_EXTERN_DIR}/Eigen/cmake)
# find_package(Eigen3)

include_directories(${RAL_INCLUDE_DIR})

# include_directories(${RAL_EXTERN_DIR}/Eigen)
include_directories(${EIGEN_DIR})
link_directories(${EIGEN_DIR})

# include_directories(${EIGEN3_INCLUDE_DIR})

add_subdirectory(${RAL_EXTERN_DIR}/Eigen)

add_library(RobotArmLib ${RAL_SOURCES})

# target_link_libraries(RobotArmLib PRIVATE Eigen3)