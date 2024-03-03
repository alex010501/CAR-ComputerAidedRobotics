#pragma once

#include <string>

#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <implot_internal.h>

class UIWindow {
protected:
    const char* m_title;
    signal<const char*> m_eventSender;
    slot m_eventHandler;
public:
    UIWindow(const char* p_title): m_title(p_title) {}
    ~UIWindow(){}

    virtual void init(){}
    virtual void draw(bool isSimulationMode = false){}
    virtual void update(bool isSimulationMode = false){}
    virtual void shutdown(){}
    virtual void error_callback(int error, const char* description){}

    virtual void raiseEvent(const char* p_event){}

    virtual void onEvent(const char* p_event){}

    void initEventHandler(signal<const char*> p_eventSender)
    {
        m_eventHandler.init(p_eventSender, onEvent, this);
    }
};