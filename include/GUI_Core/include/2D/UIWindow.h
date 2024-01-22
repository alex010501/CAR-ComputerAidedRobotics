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

#include <imgui.h>
// #include <imgui_impl_sdl.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_bgfx.h>
// #include <SDL.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>
#include <bx/math.h>

class GUIWindow {
private:
    GLFWwindow* m_window;
    int m_width;
    int m_height;
    bool m_fullscreen;
    const char* m_title;

public:
    GUIWindow(const char* p_title, int p_width, int p_height, bool p_fullscreenSwitch = false);

    void update();

    GLFWwindow* getWindow();

    void shutdown();

    void addChildWindow(GUIWindow& childWindow);
};

// class UI_Window {
// public:
//     UI_Window(const char* title) : m_title(title) {}

//     void render();

//     bool IsOpen() const { return m_open; }

// private:
//     const char* m_title;
//     bool m_open = true;
// };