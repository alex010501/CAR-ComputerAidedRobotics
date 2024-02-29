#include <UIWindow_PlotingWorkspace.h>

UIWindow_PlotingWorkspace::UIWindow_PlotingWorkspace(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PlotingWorkspace::init()
{
    this->derivator.init();
    this->integrator.init(-1);
    for (int i = 0; i < 628; i++)
    {
        double t = i * 0.01;
        x.push_back(t);
        y.push_back(sin(t));
        y_deriv.push_back(derivator.calculate(sin(t), 0.01));
        y_integ.push_back(integrator.calculate(sin(t),0.01));
    }
}

void UIWindow_PlotingWorkspace::draw(bool isSimulationMode)
{
    ImGui::Begin(m_title);
    if (ImPlot::BeginPlot("Example plot"))
    {
        // ImPlot::PlotScatter("sin(x)", x.data(), y.data(), x.size());
        ImPlot::PlotLine("sin(x)", x.data(), y.data(), x.size());
        ImPlot::PlotLine("derivative", x.data(), y_deriv.data(), x.size());
        ImPlot::PlotLine("integral", x.data(), y_integ.data(), x.size());
        ImPlot::EndPlot();
    }

    ImGui::End();
}

void UIWindow_PlotingWorkspace::update(bool isSimulationMode)
{
    
}

void UIWindow_PlotingWorkspace::shutdown()
{
    
}