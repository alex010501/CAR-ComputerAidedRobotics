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
    ImGui::Button("PlottingWorkspace");
    ImGui::End();
}

void UIWindow_PlotingWorkspace::update()
{
    
}

void UIWindow_PlotingWorkspace::shutdown()
{
    
}