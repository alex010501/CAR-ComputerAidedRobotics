#pragma once

#include <string>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_bgfx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>
#include <bx/math.h>

#include "stb_image.h"

class UIWindow {
protected:
    const char* m_title;
public:
    UIWindow(const char* p_title);
    virtual void draw();
    virtual void shutdown();
};

namespace GUI_Helper
{
    struct ImageData
    {
        int width;
        int height;
        int channels;
        unsigned char* data;
    };

    struct ImageTexture
    {
        ImTextureID texture;
        int width;
        int height;
    };
    
    ImageData loadImageToRAM(const char* filename);

    ImTextureID loadImageToGPU(ImageData imageData);

    void freeImageMemory(ImageData imageMemory);
}