cmake_minimum_required(VERSION 3.13)
project(RobotArm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EIGEN_DIR ${CMAKE_SOURCE_DIR}/../../extern/Eigen)

link_directories(${EIGEN_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include/MathAdditions)

# add_subdirectory(${CMAKE_SOURCE_DIR}/include/MathAdditions)

add_library(RobotArm RobotArm.cpp RobotLink.cpp RobotJoint.cpp RobotAdditions.cpp)

target_link_libraries(RobotArm MathAdditions)