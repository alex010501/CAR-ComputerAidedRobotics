#include <iostream>
#include <string>
#include <vector>
#include <UIWindow_ToolPanel.h>

UIWindow_ToolPanel::UIWindow_ToolPanel(const char* p_title): UIWindow(p_title)
{
    // Math variables
    this->m_speed = 1.0f;
    this->m_frequency = 100;
    this->m_duration = 10;
    this->m_isPlaying = false;
}

void UIWindow_ToolPanel::init()
{
    
}

void UIWindow_ToolPanel::draw()
{
    std::vector items{25, 50, 100, 250, 500, 1000}; // defined somewhere
    static int selectedIndex = 0; // you need to store this state somewhere

    // Icons for the buttons
    GUI_Helper::ImageData NewFileIcon   = GUI_Helper::LoadImage("resources\\Images\\New.png");
    GUI_Helper::ImageData OpenFileIcon  = GUI_Helper::LoadImage("resources\\Images\\Open.png");
    GUI_Helper::ImageData SaveIcon      = GUI_Helper::LoadImage("resources\\Images\\Save.png");
    GUI_Helper::ImageData SaveAsIcon    = GUI_Helper::LoadImage("resources\\Images\\SaveAs.png");
    GUI_Helper::ImageData UndoIcon      = GUI_Helper::LoadImage("resources\\Images\\Undo.png");
    GUI_Helper::ImageData RedoIcon      = GUI_Helper::LoadImage("resources\\Images\\Redo.png");
    GUI_Helper::ImageData CutIcon       = GUI_Helper::LoadImage("resources\\Images\\Cut.png");
    GUI_Helper::ImageData CopyIcon      = GUI_Helper::LoadImage("resources\\Images\\Copy.png");
    GUI_Helper::ImageData PasteIcon     = GUI_Helper::LoadImage("resources\\Images\\Paste.png");

    GUI_Helper::ImageData TimerIcon     = GUI_Helper::LoadImage("resources\\Images\\Timer.png");
    GUI_Helper::ImageData FrequencyIcon = GUI_Helper::LoadImage("resources\\Images\\Frequency.png");
    GUI_Helper::ImageData SpeedIcon     = GUI_Helper::LoadImage("resources\\Images\\Speed.png");
    GUI_Helper::ImageData CalculateIcon = GUI_Helper::LoadImage("resources\\Images\\Calculate.png");
    GUI_Helper::ImageData StopIcon      = GUI_Helper::LoadImage("resources\\Images\\Stop.png");

    GUI_Helper::ImageData Play_PauseIcon;
    if (this->m_isPlaying)
    {
        Play_PauseIcon = GUI_Helper::LoadImage("resources\\Images\\Pause.png");
    }
    else
    {
        Play_PauseIcon = GUI_Helper::LoadImage("resources\\Images\\Play.png");
    }

    ImGui::Begin(m_title, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

    if (GUI_Helper::ImGui_imageButton(NewFileIcon))
    {
        std::cout << "New File" << std::endl;
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(OpenFileIcon))
    {
        std::cout << "Open File" << std::endl;
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(SaveIcon))
    {
        std::cout << "Save File" << std::endl;
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(SaveAsIcon))
    {
        std::cout << "Save File As" << std::endl;
    }
    ImGui::SameLine(0, 25);

    GUI_Helper::ImGui_imageButton(UndoIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(RedoIcon);
    ImGui::SameLine(0, 25);

    GUI_Helper::ImGui_imageButton(CutIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(CopyIcon);
    ImGui::SameLine();
    GUI_Helper::ImGui_imageButton(PasteIcon);
    ImGui::SameLine(0, 50);

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 2));
    GUI_Helper::ImGui_picture(FrequencyIcon);
    ImGui::SameLine();
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::Text("Frequency");
    ImGui::SameLine();
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));  
    ImGui::PushItemWidth(60);
    if (ImGui::BeginCombo("Hz", std::to_string(items[selectedIndex]).c_str()))
    {
        for (int i = 0; i < items.size(); ++i)
        {
            const bool isSelected = (selectedIndex == i);
            if (ImGui::Selectable(std::to_string(items[i]).c_str(), isSelected))
            {
                selectedIndex = i;
                this->m_frequency = items[i];
            }
            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();
    ImGui::SameLine(0, 25);
    
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 2));
    GUI_Helper::ImGui_picture(TimerIcon);
    ImGui::SameLine();
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::Text("Simulation time");
    ImGui::SameLine();
    ImGui::PushItemWidth(50);
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::InputFloat("sec", &this->m_duration, 0.0f, 0.0f, "%.1f");
    ImGui::PopItemWidth();
    ImGui::SameLine(0, 25);

    if (GUI_Helper::ImGui_imageButton(Play_PauseIcon))
    {
        this->m_isPlaying = !this->m_isPlaying;
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(StopIcon))
            this->m_isPlaying = false;

    // Add Neural Network stuff here
    
    
    ImGui::End();
}

void UIWindow_ToolPanel::update()
{
    
}

void UIWindow_ToolPanel::shutdown()
{
    
}