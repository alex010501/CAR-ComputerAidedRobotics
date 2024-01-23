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

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>

#include <2D/UIWindow.h>

class CoreWindow {
private:
    GLFWwindow* m_window;
    GLFWimage* m_icon;
    int m_width;
    int m_height;
    bool m_fullscreen;
    const char* m_title;

public:
    CoreWindow(const char* p_title, int p_width, int p_height, bool p_fullscreenSwitch = false, GLFWimage* p_icon = NULL);

    void init();

    void update();

    void shutdown();

    GLFWwindow* getWindow();
};