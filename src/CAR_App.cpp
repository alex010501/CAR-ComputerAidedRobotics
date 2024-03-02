#include <iostream>
// Add my libraries
#include <RobotArmLib.h>
#include <GUI_Core.h>

// Classes
#include <CAR_MainWindow.h>
#include <UIWindow_3DWorkspace.h>
#include <UIWindow_Console.h>
#include <UIWindow_LibraryViewer.h>
#include <UIWindow_PlotingWorkspace.h>
#include <UIWindow_PropertiesViewer.h>
#include <UIWindow_SceneTreeViewer.h>
#include <UIWindow_ToolPanel.h>

int main()
{
    CAR_MainWindow testWindow("Computer Aided Robotics", "resources/Icons/RA_Icon.png");

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
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    testWindow.shutdown();
    return 0;
}