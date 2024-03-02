#include <UI/UIGraph.h>

Graph::Graph(const char* p_label, double* p_current_value): m_label(p_label), m_current_value(p_current_value)
{

}

void Graph::update()
{
    this->m_data.push_back(*this->m_current_value);
}

Oscilloscope::Oscilloscope(const char* p_label, std::vector<double> p_x_data): m_label(p_label)
{
    this->m_x_data = p_x_data;
    this->m_x_size = p_x_data.size();
}

void Oscilloscope::addPlot(Graph* p_plot)
{
    this->m_plotList.push_back(p_plot);
}

void Oscilloscope::show()
{
    if (ImPlot::BeginPlot("Example plot"))
    {
        for (Graph* plot : this->m_plotList)
        {
            ImPlot::PlotLine(plot->m_label, this->m_x_data.data(), plot->m_data.data(), this->m_x_size);
        }
        ImPlot::EndPlot();
    }
}