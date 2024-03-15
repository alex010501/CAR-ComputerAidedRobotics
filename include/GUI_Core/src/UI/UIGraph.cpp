#include <UI/UIGraph.h>

void Graph::update()
{
    double temp = *(this->m_current_value);
    this->m_data.push_back(temp);
}

void Graph::eraseData()
{
    this->m_data.clear();
}

void Oscilloscope::initXAxis(std::vector<double> p_x_data)
{
    this->m_x_data = p_x_data;
    this->m_x_size = p_x_data.size();
    this->isXAxisInit = true;
}

std::vector<double> Oscilloscope::fillZeros(std::vector<double> p_vector, int p_size)
{
    std::vector<double> temp;
    int size = p_vector.size();
    temp.reserve(p_size);
    for (int i = 0; i < p_size; i++)
    {
        if (i < size)
        {
            temp.push_back(p_vector[i]);
        }
        else
        {
            temp.push_back(0.0);
        }
    }
    return temp;
}

void Oscilloscope::eraseData()
{
    for (Graph* plot : this->m_plotList)
    {
        plot->eraseData();
    }
}

void Oscilloscope::addPlot(Graph* p_plot)
{
    Graph* temp = p_plot;
    m_plotList.push_back(p_plot);
    // for (Graph* plot : this->m_plotList)
    // {
    //     printf("Plot: %s, pointer %d\n", plot->m_label.c_str(), plot);
    // }
}

void Oscilloscope::show()
{
    if (ImPlot::BeginPlot(this->m_label.c_str()))
    {
        ImPlot::SetupAxes("Time", "Amplitude");
        // ImAxis x = ImAxis_X1;
        // x.AutoFitRange(this->m_x_data.data(), this->m_x_data.size());
        // ImPlot::SetAxes()
        /*if (this->isXAxisInit)
        {
            // ImPlot::SetupAxisLimits(ImAxis_X1, this->m_x_data[0], this->m_x_data[this->m_x_size - 1], ImPlotCond_Always);
            ImPlot::SetupAxes("Time", "Amplitude");
        }*/

        for (Graph* plot : this->m_plotList)
        {
            std::vector<double> temp = fillZeros(plot->m_data, this->m_x_size);
            ImPlot::PlotLine(plot->m_label.c_str(), this->m_x_data.data(), temp.data(), this->m_x_size);
        }
        ImPlot::EndPlot();
    }
}

void Oscilloscope::update()
{
    for (Graph* plot : this->m_plotList)
    {
        plot->update();
    }
}