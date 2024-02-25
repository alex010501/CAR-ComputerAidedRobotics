#pragma once

#include <UI/UIWindow.h>

class UIWindow_ToolPanel: public UIWindow {
private:

public:
    // Add variables here
    float m_speed;
    int m_frequency;
    float m_duration;
    bool m_isPlaying;

    // Add class methods here
    UIWindow_ToolPanel(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();
};