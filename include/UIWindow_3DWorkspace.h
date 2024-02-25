#pragma once

#include <UI/UIWindow.h>
#include <3D/BaseScene.h>

class UIWindow_3DWorkSpace: public UIWindow {
private:
    // Add variables here
    BaseScene m_scene;
    
public:
    // Add variables here


    // Add class methods here
    UIWindow_3DWorkSpace(const char* p_title, BaseScene p_scene);
    void init();
    void draw();
    void update();
    void shutdown();
};