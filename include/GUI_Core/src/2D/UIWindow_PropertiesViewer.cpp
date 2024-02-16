#include <2D/UIWindow_PropertiesViewer.h>

UIWindow_PropertiesViewer::UIWindow_PropertiesViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PropertiesViewer::draw()
{
    UIWindow::draw();
    std::string lv_input = "Properties";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::End();
}

void UIWindow_PropertiesViewer::shutdown()
{
    
}