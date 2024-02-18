#include <2D/UIWindow_ToolPanel.h>

UIWindow_ToolPanel::UIWindow_ToolPanel(const char* p_title): UIWindow(p_title)
{
    this->m_speed = 1.0f;
    this->m_frequency = 100;
    this->m_duration = 10;
    
    this->NewFileIcon  = GUI_Helper::loadImageToRAM("resources\\New.png");
    this->OpenFileIcon = GUI_Helper::loadImageToRAM("resources\\Open.png");
    this->SaveIcon     = GUI_Helper::loadImageToRAM("resources\\Save.png");
    this->SaveAsIcon   = GUI_Helper::loadImageToRAM("resources\\SaveAs.png");
    this->CutIcon      = GUI_Helper::loadImageToRAM("resources\\Cut.png");
    this->CopyIcon     = GUI_Helper::loadImageToRAM("resources\\Copy.png");
    this->PasteIcon    = GUI_Helper::loadImageToRAM("resources\\Paste.png");    
}

void UIWindow_ToolPanel::draw()
{
    this->NewFileIconTexture  = GUI_Helper::loadImageToGPU(this->NewFileIcon);
    this->OpenFileIconTexture = GUI_Helper::loadImageToGPU(this->OpenFileIcon);
    this->SaveIconTexture     = GUI_Helper::loadImageToGPU(this->SaveIcon);
    this->SaveAsIconTexture   = GUI_Helper::loadImageToGPU(this->SaveAsIcon);
    this->CutIconTexture      = GUI_Helper::loadImageToGPU(this->CutIcon);
    this->CopyIconTexture     = GUI_Helper::loadImageToGPU(this->CopyIcon);
    this->PasteIconTexture    = GUI_Helper::loadImageToGPU(this->PasteIcon);

    ImGui::Begin(m_title, nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
    // UIWindow::draw();
    ImGui::ShowMetricsWindow();

    ImGui::ImageButton(this->NewFileIconTexture, ImVec2(this->NewFileIcon.width, this->NewFileIcon.height));
    ImGui::SameLine();
    ImGui::ImageButton(this->OpenFileIconTexture, ImVec2(this->OpenFileIcon.width, this->OpenFileIcon.height));
    ImGui::SameLine();
    ImGui::ImageButton(this->SaveIconTexture, ImVec2(this->SaveIcon.width, this->SaveIcon.height));
    ImGui::SameLine();
    ImGui::ImageButton(this->SaveAsIconTexture, ImVec2(this->SaveAsIcon.width, this->SaveAsIcon.height));
    ImGui::SameLine(0, 50);
    ImGui::ImageButton(this->CutIconTexture, ImVec2(this->CutIcon.width, this->CutIcon.height));
    ImGui::SameLine();
    ImGui::ImageButton(this->CopyIconTexture, ImVec2(this->CopyIcon.width, this->CopyIcon.height));
    ImGui::SameLine();
    ImGui::ImageButton(this->PasteIconTexture, ImVec2(this->PasteIcon.width, this->PasteIcon.height));
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
    GUI_Helper::freeImageMemory(this->NewFileIcon);
    GUI_Helper::freeImageMemory(this->OpenFileIcon);
    GUI_Helper::freeImageMemory(this->SaveIcon);
    GUI_Helper::freeImageMemory(this->SaveAsIcon);
    GUI_Helper::freeImageMemory(this->CutIcon);
    GUI_Helper::freeImageMemory(this->CopyIcon);
    GUI_Helper::freeImageMemory(this->PasteIcon);
}