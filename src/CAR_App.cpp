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

    BaseScene scene = BaseScene();

    UIWindow_3DWorkSpace      WorkspaceWindow("3d Workspace", scene);
    UIWindow_Console          ConsoleWindow("Console");
    UIWindow_LibraryViewer    LibraryWindow("Library");
    UIWindow_PropertiesViewer PropertiesWindow("Properties");
    UIWindow_SceneTreeViewer  SceneTreeWindow("Scene Tree");
    UIWindow_ToolPanel        ToolPanel("Tools");
    UIWindow_PlotingWorkspace PlotingWindow("Plots");

    windowList.push_back(&WorkspaceWindow);
    windowList.push_back(&ConsoleWindow);    
    windowList.push_back(&LibraryWindow);
    windowList.push_back(&PropertiesWindow);
    windowList.push_back(&SceneTreeWindow);
    windowList.push_back(&ToolPanel);
    windowList.push_back(&PlotingWindow);

    
    
    CoreWindow testWindow("Computer Aided Robotics", windowList, "resources/Icons/RA_Icon.png");

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