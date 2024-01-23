#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

#include <RobotArmLib.h>
#include <GUI_Core.h>


int main()
{
    std::cout << "Welcome to Computer Aided Robotics" << std::endl;
    std::cout << "Choose screen mode: 1 = fullscreen, 0 = windowed" << std::endl;
    int mode;
    do
    {
        std::cin >> mode;
        getchar();
        if (mode != 0 && mode != 1)
        {
            std::cout << "Invalid mode, please enter 0 or 1" << std::endl;
        }
    } while (mode != 0 && mode != 1);
    
    int width, height, channels;
    unsigned char* iconData = stbi_load("resources/RA_Icon.png", &width, &height, &channels, 0);
    GLFWimage icon[1];
    icon[0].width = width;
    icon[0].height = height;
    icon[0].pixels = iconData;

    CoreWindow testWindow("Computer Aided Robotics", icon);

    if (mode)
    {
        testWindow.setFullscreen(true);
    }

    std::cout << "Starting application" << std::endl;
    std::cout << "Press enter to continue" << std::endl;
    getchar();

    testWindow.init();
    while (!glfwWindowShouldClose(testWindow.getWindow()))
    {
        testWindow.update();
    }
    testWindow.shutdown();
    // std::cout << "Rate application by 1 to 10" << std::endl;
    // getchar();
    return 0;
}