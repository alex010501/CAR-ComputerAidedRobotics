#include <iostream>
#include <string>
#include <vector>
#include <UIWindow_ToolPanel.h>

UIWindow_ToolPanel::UIWindow_ToolPanel(const char* p_title): UIWindow(p_title)
{
    // Math variables
    this->m_state = SIM_STOP;
    this->m_duration = 10;
    this->m_frequencyItems = {25, 50, 100, 250, 500, 1000};
    this->m_frequencyIndex = 0;
}

void UIWindow_ToolPanel::init()
{
    
}

void UIWindow_ToolPanel::loadIcons()
{
    this->NewFileIcon   = GUI_Helper::LoadImage("resources/Images/New.png");
    this->OpenFileIcon  = GUI_Helper::LoadImage("resources/Images/Open.png");
    this->SaveIcon      = GUI_Helper::LoadImage("resources/Images/Save.png");
    this->SaveAsIcon    = GUI_Helper::LoadImage("resources/Images/SaveAs.png");
    this->UndoIcon      = GUI_Helper::LoadImage("resources/Images/Undo.png");
    this->RedoIcon      = GUI_Helper::LoadImage("resources/Images/Redo.png");
    this->CutIcon       = GUI_Helper::LoadImage("resources/Images/Cut.png");
    this->CopyIcon      = GUI_Helper::LoadImage("resources/Images/Copy.png");
    this->PasteIcon     = GUI_Helper::LoadImage("resources/Images/Paste.png");
    this->TimerIcon     = GUI_Helper::LoadImage("resources/Images/Timer.png");
    this->FrequencyIcon = GUI_Helper::LoadImage("resources/Images/Frequency.png");
    this->SpeedIcon     = GUI_Helper::LoadImage("resources/Images/Speed.png");
    this->CalculateIcon = GUI_Helper::LoadImage("resources/Images/Calculate.png");
    this->StopIcon      = GUI_Helper::LoadImage("resources/Images/Stop.png");

    switch (this->m_state)
    {
        case SIM_STOP:
            this->Play_PauseIcon = GUI_Helper::LoadImage("resources/Images/Play.png");
            break;
        case SIM_PAUSE:
            this->Play_PauseIcon = GUI_Helper::LoadImage("resources/Images/Play.png");
            break;
        case SIM_PLAY:
            this->Play_PauseIcon = GUI_Helper::LoadImage("resources/Images/Pause.png");
            break;
        default:
            break;
    }
}

void UIWindow_ToolPanel::fileButtons()
{
    bool lv_buttonEnabled = (this->m_state == SIM_STOP);

    if (GUI_Helper::ImGui_imageButton(this->NewFileIcon, lv_buttonEnabled))
    {
        this->signal_NewFile();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->OpenFileIcon, lv_buttonEnabled))
    {
        this->signal_OpenFile();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->SaveIcon, lv_buttonEnabled))
    {
        this->signal_Save();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->SaveAsIcon, lv_buttonEnabled))
    {
        this->signal_SaveAs();
    }
    ImGui::SameLine(0, 25);

    if (GUI_Helper::ImGui_imageButton(this->UndoIcon, lv_buttonEnabled))
    {
        this->signal_Undo();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->RedoIcon, lv_buttonEnabled))
    {
        this->signal_Redo();
    }
    ImGui::SameLine(0, 25);

    if (GUI_Helper::ImGui_imageButton(this->CutIcon, lv_buttonEnabled))
    {
        this->signal_Cut();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->CopyIcon, lv_buttonEnabled))
    {
        this->signal_Copy();
    }
    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->PasteIcon, lv_buttonEnabled))
    {
        this->signal_Paste();
    }
}

void UIWindow_ToolPanel::frequency_durationInput()
{
    bool lv_inputEnabled = (this->m_state == SIM_STOP);

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 2));
    GUI_Helper::ImGui_picture(this->FrequencyIcon);
    ImGui::SameLine();

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::Text("Frequency");
    ImGui::SameLine();

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));  
    ImGui::PushItemWidth(60);
    ImGui::BeginDisabled(!lv_inputEnabled);
    if (ImGui::BeginCombo("Hz", std::to_string(this->m_frequencyItems[this->m_frequencyIndex]).c_str()))
    {
        for (int i = 0; i < this->m_frequencyItems.size(); ++i)
        {
            const bool isSelected = (this->m_frequencyIndex == i);
            if (ImGui::Selectable(std::to_string(this->m_frequencyItems[i]).c_str(), isSelected))
            {
                this->m_frequencyIndex = i;
            }
            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::EndDisabled();
    ImGui::PopItemWidth();
    ImGui::SameLine(0, 25);
    
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 2));
    GUI_Helper::ImGui_picture(this->TimerIcon);
    ImGui::SameLine();

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::Text("Simulation time");
    ImGui::SameLine();

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + 5));
    ImGui::PushItemWidth(50);
    ImGui::BeginDisabled(!lv_inputEnabled);
    ImGui::InputFloat("sec", &this->m_duration, 0.0f, 0.0f, "%.1f");
    // Check that the duration is between 0.1 and 120.
    if (this->m_duration < 0.1f)
    {
        this->m_duration = 0.1f;
    }
    else if (this->m_duration > 120.0f)
    {
        this->m_duration = 120.0f;
    }
    ImGui::EndDisabled();
    ImGui::PopItemWidth();
}

void UIWindow_ToolPanel::playButtons()
{
    if (GUI_Helper::ImGui_imageButton(this->Play_PauseIcon, true))
        switch (this->m_state)
        {
            case SIM_STOP: case SIM_PAUSE:
                this->m_state = SIM_PLAY;
                this->signal_Play(this->m_frequencyItems[this->m_frequencyIndex], this->m_duration);
                break;
            case SIM_PLAY:
                this->m_state = SIM_PAUSE;
                this->signal_Pause();
                break;
            default:
                break;
        }

    ImGui::SameLine();
    if (GUI_Helper::ImGui_imageButton(this->StopIcon, true))
    {
        this->m_state = SIM_STOP;
        this->signal_Stop();
    }
}

void UIWindow_ToolPanel::draw()
{
    // Icons for the buttons
    this->loadIcons();

    // Set the window without the title bar
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
    ImGui::SetNextWindowClass(&window_class);

    ImGui::Begin(m_title, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

    // File, undo/redo, copy/paste buttons
    this->fileButtons();
    ImGui::SameLine(0, 50);

    // Frequency and duration input
    this->frequency_durationInput();
    ImGui::SameLine(0, 25);

    // Play/Pause/Stop buttons
    this->playButtons();

    // Add Neural Network stuff here
    
    
    ImGui::End();
}

void UIWindow_ToolPanel::update()
{
    
}

void UIWindow_ToolPanel::shutdown()
{
    
}