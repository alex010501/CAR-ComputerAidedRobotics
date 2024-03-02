#pragma once

#include <vector>

#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <implot_internal.h>

class Graph
{
private:
    double* m_current_value;
public:
    const char* m_label;
    std::vector<double> m_data;
    Graph(const char* p_label, double* p_current_value);
    void update();
};

class Oscilloscope
{
private:
    const char* m_label;
    std::vector<Graph*> m_plotList;
    std::vector<double> m_x_data;
    int m_x_size;

public:
    Oscilloscope(const char* p_label, std::vector<double> p_x_data);
    void addPlot(Graph* p_plot);
    void show();
};