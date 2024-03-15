#include <UIWindow_PlotingWorkspace.h>

UIWindow_PlotingWorkspace::UIWindow_PlotingWorkspace(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PlotingWorkspace::init()
{

}

void UIWindow_PlotingWorkspace::draw()
{
    ImGui::Begin(m_title);

    if (ImGui::Button("Add Oscilloscope"))
    {
        this->addOscilloscope();
    }

    /*for (Oscilloscope oscilloscope : this->m_plottingOscilloscope)
    {
        oscilloscope.show();
    }*/

    this->exampleOsc.show();

    ImGui::End();
}

void UIWindow_PlotingWorkspace::update()
{
    this->exampleOsc.update();
    /*for (Oscilloscope oscilloscope : this->m_plottingOscilloscope)
    {
        oscilloscope.update();
    }*/
}

void UIWindow_PlotingWorkspace::shutdown()
{
    
}

void UIWindow_PlotingWorkspace::addOscilloscope()
{
    std::string label = "Oscilloscope " + std::to_string(this->m_plottingOscilloscope.size());
    Oscilloscope oscilloscope = Oscilloscope(label);
    this->m_plottingOscilloscope.push_back(oscilloscope);
}

void UIWindow_PlotingWorkspace::startSimulation(double p_dt, double p_duration)
{
    // std::cout << "Start simulation" << std::endl;
    std::vector<double> timeLine;
    timeLine = MathAdditions::make_vector(0, p_duration, p_dt);
    this->exampleOsc.eraseData();
    this->exampleOsc.initXAxis(timeLine);
    /*for (Oscilloscope oscilloscope : this->m_plottingOscilloscope)
    {
        

        // std::cout << "Size " << timeLine.size() << std::endl;
        
        oscilloscope.initXAxis(timeLine);
    }*/
}

void UIWindow_PlotingWorkspace::addGraph(Graph* p_graph)
{
    this->exampleOsc.addPlot(p_graph);
    // for (Oscilloscope oscilloscope : this->m_plottingOscilloscope)
    // {
    //     oscilloscope.addPlot(p_graph);
    // }
}