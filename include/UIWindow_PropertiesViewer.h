#pragma once

#include <UI/UIWindow.h>

class UIWindow_PropertiesViewer: public UIWindow {
private:

public:
    // Add variables here


    // Add class methods here
    UIWindow_PropertiesViewer(const char* p_title);
    void init();
    void draw(bool isSimulationMode = false);
    void update(bool isSimulationMode = false);
    void shutdown();
};