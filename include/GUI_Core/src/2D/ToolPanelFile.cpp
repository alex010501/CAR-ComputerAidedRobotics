#include <2D/ToolPanelFile.h>

ToolPanelFile::ToolPanelFile(const char* p_title): UIWindow(p_title)
{
    this->m_file = false;
    this->m_open = false;
    this->m_switch = false;
}

void ToolPanelFile::draw()
{
    UIWindow::draw();
    if (ImGui::Button("Open"))
    {
        this->m_open = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Save"))
    {
        this->m_file = true;
    }
    ImGui::SameLine();
    if (ImGui::RadioButton("Switch", this->m_switch))
    {
        this->m_switch = !(this->m_switch);
    }
    ImGui::SameLine();
    ImGui::ArrowButton("Play", ImGuiDir_Right);
    ImGui::End();
}