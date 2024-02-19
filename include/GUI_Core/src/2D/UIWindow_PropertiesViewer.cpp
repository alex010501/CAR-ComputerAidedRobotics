#include <2D/UIWindow_PropertiesViewer.h>

UIWindow_PropertiesViewer::UIWindow_PropertiesViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PropertiesViewer::draw()
{
    UIWindow::draw();
    ImGui::Button("Properties Viewer");
    ImGui::End();
}

void UIWindow_PropertiesViewer::shutdown()
{
    
}