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
#include <vector>

#include <glad/glad.h>
#include <stb_image.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <UI/UIWindow.h>

#include <EventHandler/sigslot.h>

class CoreWindow {
private:
    GLFWwindow* m_window;
    GLFWimage* m_icon;
    int m_width;
    int m_height;
    const char* m_title;
    const char* m_iconPath;

protected:
    virtual void initDockspace(){};

    virtual void initChildWindows(){};

    virtual void drawChildWindows(){};

    virtual void updateChildWindows(){};

    virtual void shutdownChildWindows(){};

    virtual void OpenGLRender(){};

    void setCallbacks();

    void ResizeCallback(int p_width, int p_height);

    void PosCallback(int p_xpos, int p_ypos);

public:
    CoreWindow(const char* p_title, const char* p_iconPath = nullptr, int p_width = 1280, int p_height = 720);

    int init();

    void draw();

    void update();

    void shutdown();

    bool isOpen();

    void pollEvents();
};


namespace GUI_Helper
{
    struct ImageData
    {
        ImTextureID texture;
        int width;
        int height;
    };
    
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

    ImageData LoadImage(const char* filename);

    bool ImGui_imageButton(ImageData imageData);

    void ImGui_picture(ImageData imageData);
};