#pragma once

#include <GUI_Core.h>
#include <UI/UIWindow.h>

#include "SimState.h"

class UIWindow_ToolPanel: public UIWindow {

private:

    // Event handlers
    // slot m_eventHandler;

    // Variables
    simState m_state;
    std::vector<int> m_frequencyItems;
    int m_frequencyIndex;

    // Icons
    GUI_Helper::ImageData NewFileIcon;
    GUI_Helper::ImageData OpenFileIcon;
    GUI_Helper::ImageData SaveIcon;
    GUI_Helper::ImageData SaveAsIcon;
    GUI_Helper::ImageData UndoIcon;
    GUI_Helper::ImageData RedoIcon;
    GUI_Helper::ImageData CutIcon;
    GUI_Helper::ImageData CopyIcon;
    GUI_Helper::ImageData PasteIcon;
    GUI_Helper::ImageData TimerIcon;
    GUI_Helper::ImageData FrequencyIcon;
    GUI_Helper::ImageData SpeedIcon;
    GUI_Helper::ImageData CalculateIcon;
    GUI_Helper::ImageData StopIcon;
    GUI_Helper::ImageData Play_PauseIcon;

    // Private methods
    void loadIcons();
    void fileButtons();
    void frequency_durationInput();
    void playButtons();

public:
    // Event senders
    sigslot::signal0<> eventSave;

    // Add variables here
    int m_frequency;
    float m_duration;
    bool m_isPlaying;

    // Add class methods here
    UIWindow_ToolPanel(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();

    
    /*void raiseEvent();

    void onEvent();

    void initEventHandler(Signal<const char*> p_eventSender)
    {
        m_eventHandler.init(p_eventSender, onEvent, this);
    }*/
};