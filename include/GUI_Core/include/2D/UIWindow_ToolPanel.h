#pragma once

#include "UIWindow.h"

class UIWindow_ToolPanel: public UIWindow {
private:

public:
    // Add variables here
    float m_speed;
    float m_frequency;
    float m_duration;

    // Add class methods here
    UIWindow_ToolPanel(const char* p_title);
    void draw();
};