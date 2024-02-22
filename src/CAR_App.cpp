#include <iostream>
// Add my libraries
#include <RobotArmLib.h>
#include <GUI_Core.h>

// Classes
#include <UIWindow_3DWorkspace.h>
#include <UIWindow_Console.h>
#include <UIWindow_LibraryViewer.h>
#include <UIWindow_PlotingWorkspace.h>
#include <UIWindow_PropertiesViewer.h>
#include <UIWindow_SceneTreeViewer.h>
#include <UIWindow_ToolPanel.h>

int main()
{
    std::vector<UIWindow*> windowList;

    // Viewer3DWindow window1("Computer Aided Robotics");
    // ToolPanelFile window2("File");
    UIWindow_3DWorkSpace      window1("3d Workspace");
    UIWindow_Console          window2("Console");
    UIWindow_LibraryViewer    window3("Library");
    UIWindow_PropertiesViewer window4("Properties");
    UIWindow_SceneTreeViewer  window5("Scene Tree");
    UIWindow_ToolPanel        window6("Tools");
    UIWindow_PlotingWorkspace window7("Plots");

    windowList.push_back(&window1);
    windowList.push_back(&window2);    
    windowList.push_back(&window3);
    windowList.push_back(&window4);
    windowList.push_back(&window5);
    windowList.push_back(&window6);
    windowList.push_back(&window7);

    
    
    CoreWindow testWindow("Computer Aided Robotics", windowList, "resources\\Icons\\RA_Icon.png");

    // std::cout << "Welcome to Computer Aided Robotics" << std::endl;
    // getchar();

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