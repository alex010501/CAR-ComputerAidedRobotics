#pragma once

#include <string>

#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <implot_internal.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <stb_image.h>

class UIWindow {
protected:
    const char* m_title;
public:
    UIWindow(const char* p_title);

    virtual ~UIWindow()
    {}

    virtual void init();
    virtual void draw(bool isSimulationMode = false);
    virtual void update(bool isSimulationMode = false);
    virtual void shutdown();
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
}