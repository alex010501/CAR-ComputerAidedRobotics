#include <iostream>

#include <RobotArmLib.h>
#include <GUI_Core.h>

int main()
{
    std::cout << "Using GLFW" << std::endl;
	// return windowGLFW();
    GUIWindow testWindow("Testing", 1280, 720);
    std::cout << "Press enter to continue" << std::endl;
    getchar();
    testWindow.update();

    testWindow.shutdown();
    std::cout << "Rate application by 1 to 10" << std::endl;
    getchar();
    return 0;
}