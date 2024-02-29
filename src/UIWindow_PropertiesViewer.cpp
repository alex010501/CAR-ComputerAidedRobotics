#include <UIWindow_PropertiesViewer.h>

UIWindow_PropertiesViewer::UIWindow_PropertiesViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PropertiesViewer::init()
{
    
}

void UIWindow_PropertiesViewer::draw(bool isSimulationMode)
{
    ImGui::Begin(m_title);
    ImGui::Button("Properties Viewer");
    ImGui::End();
}

void UIWindow_PropertiesViewer::update(bool isSimulationMode)
{
    
}

void UIWindow_PropertiesViewer::shutdown()
{
    
}