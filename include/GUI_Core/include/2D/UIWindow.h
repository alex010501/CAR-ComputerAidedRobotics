#pragma once

#include <iostream>

#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_bgfx.h>
#include <SDL.h>
#include <bx/math.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

class UI_Window {
public:
    UI_Window(const char* title) : m_title(title) {}

    void render();

    bool IsOpen() const { return m_open; }

private:
    const char* m_title;
    bool m_open = true;
};
