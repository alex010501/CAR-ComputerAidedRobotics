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

    void error_callback(int p_error, std::string p_description);
public:
    sigslot::signal2<int, std::string> signal_error;

    UIWindow(const char* p_title): m_title(p_title) {}
    ~UIWindow(){}

    virtual void init(){}
    virtual void draw(){}
    virtual void update(){}
    virtual void shutdown(){}
};