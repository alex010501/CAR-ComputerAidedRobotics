#pragma once

#include <UI/UIWindow.h>

class UIWindow_Console: public UIWindow {
private:
    
public:
    // Add variables here


    // Add class methods here
    UIWindow_Console(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();
};