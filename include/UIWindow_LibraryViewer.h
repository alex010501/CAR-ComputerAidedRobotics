#pragma once

#include <UI/UIWindow.h>

class UIWindow_LibraryViewer: public UIWindow {
private:

public:
    // Add variables here


    // Add class methods here
    UIWindow_LibraryViewer(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();
};