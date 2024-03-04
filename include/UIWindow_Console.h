#pragma once

#include <GUI_Core.h>
#include <UI/UIWindow.h>
#include <vector>

class UIWindow_Console: public UIWindow {
private:
    // Add variables here
    char m_commandBuffer[256];
    std::vector<char*> m_pLines;

    void comandCallback();    
public:
    // Add variables here


    // Add class methods here
    UIWindow_Console(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();
    void error_callback(int error, const char* description);
};