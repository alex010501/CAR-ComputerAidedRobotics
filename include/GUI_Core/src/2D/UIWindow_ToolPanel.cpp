#include <2D/UIWindow_ToolPanel.h>

UIWindow_ToolPanel::UIWindow_ToolPanel(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_ToolPanel::draw()
{
    UIWindow::draw();
    ImGui::ImageButton()

    ImGui::Image()
    ImGui::InputFloat2("Speed", &m_speed);
    ImGui::InputFloat2("Frequency", &m_frequency);
    ImGui::InputFloat2("Duration", &m_duration);
    ImGui::End();
}