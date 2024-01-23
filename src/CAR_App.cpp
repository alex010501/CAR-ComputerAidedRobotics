#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

#include <RobotArmLib.h>
#include <GUI_Core.h>


int main()
{
    std::vector<UIWindow*> windowList;

    Viewer3DWindow window1("Computer Aided Robotics");
    Viewer3DWindow window2("CAR");
    windowList.push_back(&window1);
    windowList.push_back(&window2);

    std::cout << "Welcome to Computer Aided Robotics" << std::endl;
    
    int width, height, channels;
    unsigned char* iconData = stbi_load("resources/RA_Icon.png", &width, &height, &channels, 0);
    GLFWimage icon[1];
    icon[0].width = width;
    icon[0].height = height;
    icon[0].pixels = iconData;

    CoreWindow testWindow("Computer Aided Robotics", icon, windowList);

    std::cout << "Starting application" << std::endl;
    std::cout << "Press enter to continue" << std::endl;
    getchar();

    testWindow.init();
    while (!glfwWindowShouldClose(testWindow.getWindow()))
    {
        // Poll for and process events
        glfwPollEvents();
        testWindow.update();
    }
    testWindow.shutdown();
    // std::cout << "Rate application by 1 to 10" << std::endl;
    // getchar();
    return 0;
}