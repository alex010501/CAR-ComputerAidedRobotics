#pragma once

#define GLFW_INCLUDE_NONE

#if defined(_WIN32)
#define GLFW_EXPOSE_NATIVE_WIN32
#elif defined(__linux__)
#define GLFW_EXPOSE_NATIVE_X11
#elif defined(__APPLE__)
#define GLFW_EXPOSE_NATIVE_COCOA
#endif

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>

#include <2D/UIWindow.h>
#include <2D/UIWindow_3DWorkspace.h>
#include <2D/UIWindow_Console.h>
#include <2D/UIWindow_LibraryViewer.h>
#include <2D/UIWindow_PropertiesViewer.h>
#include <2D/UIWindow_SceneTreeViewer.h>
#include <2D/UIWindow_ToolPanel.h>

#include <2D/Viewer3DWindow.h>
#include <2D/ToolPanelFile.h>

class CoreWindow {
private:
    GLFWwindow* m_window;
    GLFWimage* m_icon;
    int m_width;
    int m_height;
    const char* m_title;
    std::vector<UIWindow*> m_childWindows;

public:
    CoreWindow(const char* p_title, GLFWimage* p_icon = NULL, std::vector<UIWindow*> p_childWindows = {}, int p_width = 1280, int p_height = 720);

    void init();

    void update();

    void shutdown();

    void ResizeCallback(int p_width, int p_height);

    GLFWwindow* getWindow();
};