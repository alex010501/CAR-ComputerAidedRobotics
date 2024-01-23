#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

#include <RobotArmLib.h>
#include <GUI_Core.h>


int main()
{
    std::cout << "Using GLFW" << std::endl;

    int width, height, channels;
    unsigned char* iconData = stbi_load("resources/RA_Icon.png", &width, &height, &channels, 0);
    GLFWimage icon[1];
    icon[0].width = width;
    icon[0].height = height;
    icon[0].pixels = iconData;
	// return windowGLFW();
    // CoreWindow testWindow("Computer Aided Robotics", 1920, 990, true);
    CoreWindow testWindow("Computer Aided Robotics", 1920, 990, false, icon);
    testWindow.init();
    testWindow.update();
    testWindow.shutdown();
    // std::cout << "Rate application by 1 to 10" << std::endl;
    // getchar();
    return 0;
}