#include <2D/UIWindow_ToolPanel.h>

UIWindow_ToolPanel::UIWindow_ToolPanel(const char* p_title): UIWindow(p_title)
{
    this->m_speed = 1.0f;
    this->m_frequency = 100;
    this->m_duration = 10; 
}

void UIWindow_ToolPanel::draw()
{
    GUI_Helper::ImageData NewFileIcon = GUI_Helper::LoadImage("resources\\New.png");
    GUI_Helper::ImageData OpenFileIcon = GUI_Helper::LoadImage("resources\\Open.png");
    GUI_Helper::ImageData SaveIcon = GUI_Helper::LoadImage("resources\\Save.png");
    GUI_Helper::ImageData SaveAsIcon = GUI_Helper::LoadImage("resources\\SaveAs.png");
    GUI_Helper::ImageData CutIcon = GUI_Helper::LoadImage("resources\\Cut.png");
    GUI_Helper::ImageData CopyIcon = GUI_Helper::LoadImage("resources\\Copy.png");
    GUI_Helper::ImageData PasteIcon = GUI_Helper::LoadImage("resources\\Paste.png");

    // ImGui::Begin(m_title, nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::Begin(m_title, nullptr, ImGuiWindowFlags_DockNodeHost | ImGuiWindowFlags_AlwaysAutoResize);
    // UIWindow::draw();
    // ImGui::ShowMetricsWindow();

    GUI_Helper::ImGui_imageButton(NewFileIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(OpenFileIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(SaveIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(SaveAsIcon);
    ImGui::SameLine(0, 50);
    GUI_Helper::ImGui_imageButton(CutIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(CopyIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(PasteIcon);
    ImGui::SameLine(0, 50);
    ImGui::SliderFloat("Speed", &m_speed, 0.1f, 2.0f);
    ImGui::SameLine();
    ImGui::InputInt("Frequency", &m_frequency);
    ImGui::SameLine();
    ImGui::InputFloat("Duration", &m_duration);
    ImGui::End();
}

void UIWindow_ToolPanel::shutdown()
{

}