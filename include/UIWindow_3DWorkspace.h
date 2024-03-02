#pragma once

#include <UI/UIWindow.h>
#include <3D/BaseScene.h>

class UIWindow_3DWorkSpace: public UIWindow {
private:
    // Add variables here
    BaseScene* m_scene;
    
public:
    // Add variables here


    // Add class methods here
    UIWindow_3DWorkSpace(const char* p_title);
    void init();
    void loadScene(BaseScene* p_scene);
    void draw(bool isSimulationMode = false);
    void update(bool isSimulationMode = false);
    void shutdown();
};