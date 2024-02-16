#pragma once

#include "UIWindow.h"

class UIWindow_ToolPanel: public UIWindow {
private:
    GUI_Helper::ImageData NewFileIcon;
    GUI_Helper::ImageData OpenFileIcon;
    GUI_Helper::ImageData SaveIcon;
    GUI_Helper::ImageData SaveAsIcon;
    GUI_Helper::ImageData CutIcon;
    GUI_Helper::ImageData CopyIcon;
    GUI_Helper::ImageData PasteIcon;

public:
    ImTextureID NewFileIconTexture;
    ImTextureID OpenFileIconTexture;
    ImTextureID SaveIconTexture;
    ImTextureID SaveAsIconTexture;
    ImTextureID CutIconTexture;
    ImTextureID CopyIconTexture;
    ImTextureID PasteIconTexture;

    // Add variables here
    float m_speed;
    int m_frequency;
    float m_duration;

    // Add class methods here
    UIWindow_ToolPanel(const char* p_title);
    void draw();
    void shutdown();
};