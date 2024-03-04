#pragma once

#include <string>

#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <implot_internal.h>

#include <EventHandler/sigslot.h>

class UIWindow: public sigslot::has_slots<> {
protected:
    const char* m_title;
public:
    UIWindow(const char* p_title): m_title(p_title) {}
    ~UIWindow(){}

    virtual void init(){}
    virtual void draw(){}
    virtual void update(){}
    virtual void shutdown(){}
    virtual void error_callback(int error, const char* description){}
};