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

#include <UI/UIWindow.h>
#include <3D/BaseScene.h>

class CoreWindow {
private:
    GLFWwindow* m_window;
    GLFWimage* m_icon;
    int m_width;
    int m_height;
    const char* m_title;
    const char* m_iconPath;
    std::vector<UIWindow*> m_childWindows;

public:
    CoreWindow(const char* p_title, std::vector<UIWindow*> p_childWindows = {}, const char* p_iconPath = nullptr, int p_width = 1280, int p_height = 720);

    int init();

    void update();

    void shutdown();

    void ResizeCallback(int p_width, int p_height);

    void PosCallback(int p_xpos, int p_ypos);

    bool isOpen();

    void pollEvents();
};