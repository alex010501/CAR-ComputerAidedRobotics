#pragma once

#include <GUI_Core.h>
#include <UI/UIGraph.h>

#include <UIWindow_3DWorkspace.h>
#include <UIWindow_Console.h>
#include <UIWindow_LibraryViewer.h>
#include <UIWindow_PlotingWorkspace.h>
#include <UIWindow_PropertiesViewer.h>
#include <UIWindow_SceneTreeViewer.h>
#include <UIWindow_ToolPanel.h>

class CAR_MainWindow : public CoreWindow
{
private:
    /* Add variables below*/

    // Variables for simulation tracking
    bool m_isSimulating;
    bool m_isPaused;
    unsigned int m_simFrequency;
    unsigned int m_simTickCount;
    unsigned int m_currentTick;

    // Variables for 3D workspace
    BaseScene m_scene;
    std::vector<UIWindow*> m_UIWindows;

    // Variables for plotting
    std::vector<Oscilloscope*> m_plottingOscilloscope                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;

    // Private methods
    void initChildWindows();

    void initDockspace();

    void OpenGLRender();

    void showChildWindows();

    void updateChildWindows();

    void shutdownChildWindows();

public:
    // Public methods
    CAR_MainWindow(const char* p_title, const char* p_iconPath = nullptr, int p_width = 1280, int p_height = 720);
};