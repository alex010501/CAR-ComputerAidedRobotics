#pragma once

#include <GUI_Core.h>
#include <UI/UIWindow.h>
#include <UI/UIGraph.h>
#include <cmath>
#include <vector>

#include <MathAdditions.h>

class UIWindow_PlotingWorkspace: public UIWindow {
private:
    // Add variables here


    // Add class methods here
    void addOscilloscope(); 
public:
    // Add variables here
    std::vector<Oscilloscope> m_plottingOscilloscope;

    Oscilloscope exampleOsc = Oscilloscope("Example");

    // Add class methods here
    UIWindow_PlotingWorkspace(const char* p_title);
    void init();
    void draw();
    void update();
    void shutdown();

    void startSimulation(double p_dt, double p_duration);

    void addGraph(Graph* p_graph);
};