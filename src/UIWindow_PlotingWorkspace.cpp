#include <UIWindow_PlotingWorkspace.h>

UIWindow_PlotingWorkspace::UIWindow_PlotingWorkspace(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_PlotingWorkspace::init()
{

}

void UIWindow_PlotingWorkspace::draw(bool isSimulationMode)
{
    ImGui::Begin(m_title);
    
    ImGui::End();
}

void UIWindow_PlotingWorkspace::update(bool isSimulationMode)
{
    
}

void UIWindow_PlotingWorkspace::shutdown()
{
    
}