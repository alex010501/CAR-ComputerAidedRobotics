#include <iostream>

#include <RobotArmLib.h>
#include <GUI_Core.h>

int main()
{
    std::vector<UIWindow*> windowList;

    // Viewer3DWindow window1("Computer Aided Robotics");
    // ToolPanelFile window2("File");
    UIWindow_3DWorkSpace window1("3d Workspace");
    UIWindow_Console window2("Console");
    UIWindow_LibraryViewer window3("Library");
    UIWindow_PropertiesViewer window4("Properties");
    UIWindow_SceneTreeViewer window5("Scene Tree");
    UIWindow_ToolPanel window6("Tools");
    windowList.push_back(&window1);
    windowList.push_back(&window2);    
    windowList.push_back(&window3);
    windowList.push_back(&window4);
    windowList.push_back(&window5);
    windowList.push_back(&window6);

    // std::cout << "Welcome to Computer Aided Robotics" << std::endl;
    
    int width, height, channels;
    unsigned char* iconData = stbi_load("resources\\Images\\RA_Icon.png", &width, &height, &channels, 0);
    GLFWimage icon[1];
    icon[0].width = width;
    icon[0].height = height;
    icon[0].pixels = iconData;

    CoreWindow testWindow("Computer Aided Robotics", icon, windowList);

    if (testWindow.init())
    {
        std::cout << "Error initializing window" << std::endl;
        return 1;
    }
    while (testWindow.isOpen())
    {
        // Poll for and process events
        testWindow.pollEvents();
        testWindow.update();
    }
    testWindow.shutdown();
    return 0;
}