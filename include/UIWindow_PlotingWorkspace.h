#pragma once

#include <UI/UIWindow.h>
#include <cmath>
#include <vector>

#include <MathAdditions.h>

class UIWindow_PlotingWorkspace: public UIWindow {
private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> y_deriv;
    std::vector<double> y_integ;
    MathAdditions::Derivator derivator;
    MathAdditions::Integrator integrator;
public:
    // Add variables here


    // Add class methods here
    UIWindow_PlotingWorkspace(const char* p_title);
    void init();
    void draw(bool isSimulationMode = false);
    void update(bool isSimulationMode = false);
    void shutdown();
};