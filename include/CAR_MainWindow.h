#pragma once

#include <iostream>
#include <thread>
#include <chrono>

#include <GUI_Core.h>
#include <UI/UIGraph.h>

#include <UIWindow_3DWorkspace.h>
#include <UIWindow_Console.h>
#include <UIWindow_LibraryViewer.h>
#include <UIWindow_PlotingWorkspace.h>
#include <UIWindow_PropertiesViewer.h>
#include <UIWindow_SceneTreeViewer.h>
#include <UIWindow_ToolPanel.h>

#include "SimState.h"

class CAR_MainWindow : public CoreWindow
{
private:
    /* Add variables below*/

    // Variables for simulation tracking
    simState m_simState;
    bool m_isSimulating;
    bool m_isPaused;
    unsigned int m_simFrequency;
    unsigned int m_simTickCount;
    unsigned int m_currentTick;

    // Variables for 3D workspace
    BaseScene m_scene;

    // Variables for child windows
    UIWindow_3DWorkSpace      WorkspaceWindow;
    UIWindow_Console          ConsoleWindow;
    UIWindow_LibraryViewer    LibraryWindow;
    UIWindow_PropertiesViewer PropertiesWindow;
    UIWindow_SceneTreeViewer  SceneTreeWindow;
    UIWindow_ToolPanel        ToolPanel;
    UIWindow_PlotingWorkspace PlotingWindow;
    std::vector<UIWindow*> m_UIWindows;

    // Variables for plotting
    std::vector<Oscilloscope*> m_plottingOscilloscope                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;

    // Private methods
    void initChildWindows();

    void initDockspace();

    void OpenGLRender();

    void drawChildWindows();

    void updateChildWindows();

    void shutdownChildWindows();

public:
    // Public methods
    CAR_MainWindow(const char* p_title, const char* p_iconPath = nullptr, int p_width = 1280, int p_height = 720);

    int run();

    // Events
    void EventNewFile();
    void EventOpenFile();
    void EventSave();
    void EventSaveAs();

    void EventUndo();
    void EventRedo();

    void EventCut();
    void EventCopy();
    void EventPaste();

    void EventPlay(int p_frequency, float p_duration);
    void EventPause();
    void EventStop();
};