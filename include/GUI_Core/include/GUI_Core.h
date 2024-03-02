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

    
    void ResizeCallback(int p_width, int p_height);

    void PosCallback(int p_xpos, int p_ypos);

protected:
    virtual void initDockspace(){};

    void setBackgroundColour(float p_red = 0.0f, float p_green = 0.2f, float p_blue = 0.4f, float p_alpha = 0.5f);

    void startFrame();

    void endFrame();
    
public:
    CoreWindow(const char* p_title, std::vector<UIWindow*> p_childWindows = {}, const char* p_iconPath = nullptr, int p_width = 1280, int p_height = 720);

    int init();

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