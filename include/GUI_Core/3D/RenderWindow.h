#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_syswm.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>

class RenderWindow
{
public:
    RenderWindow() = default;
    RenderWindow(uint16_t width, uint16_t height);
    ~RenderWindow();
    void beginFrame();
    void endFrame();

private:
    uint16_t m_width;
    uint16_t m_height;
};