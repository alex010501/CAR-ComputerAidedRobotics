#pragma once

#include <string>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_bgfx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>
#include <bx/math.h>

class UIWindow {
protected:
    const char* m_title;
public:
    UIWindow(const char* p_title);
    virtual void draw();
};