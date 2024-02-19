cmake_minimum_required(VERSION 3.13)

# set the project name and version
project(CAR VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "include/*.h"
                                            "src/*.cpp")


# include directories for my libraries
include_directories(include/RobotArmLib/include/)
include_directories(include/GUI_Core/include/)

# Subprojects
add_subdirectory(include/RobotArmLib)
add_subdirectory(include/GUI_Core)

# add the executable
if (WIN32)
    # add_executable(CAR_App WIN32 ${SOURCE_FILE})
    add_executable(CAR_App ${SOURCES} resources/CAR_App.rc)
else ()
    add_executable(CAR_App ${SOURCES})
endif ()

# target my libraries
target_link_libraries(CAR_App PRIVATE RobotArmLib GUI_Core)

# target Windows libraries
if (WIN32)
    target_link_libraries(CAR_App PRIVATE -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl, -Bdynamic)
endif (WIN32)

# Copy Resources
file(COPY resources/ DESTINATION ${PROJECT_BINARY_DIR}/resources/)

# Symlink Resources
# add_custom_command(TARGET CAR_App PRE_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/resources ${PROJECT_BINARY_DIR}/resources)