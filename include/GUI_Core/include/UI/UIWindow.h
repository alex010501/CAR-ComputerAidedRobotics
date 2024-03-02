#pragma once

#include <string>

#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <implot_internal.h>

class UIWindow {
protected:
    const char* m_title;
public:
    UIWindow(const char* p_title);

    virtual ~UIWindow()
    {}

    virtual void init();
    virtual void draw(bool isSimulationMode = false);
    virtual void update(bool isSimulationMode = false);
    virtual void shutdown();
    virtual void error_callback(int error, const char* description);
};