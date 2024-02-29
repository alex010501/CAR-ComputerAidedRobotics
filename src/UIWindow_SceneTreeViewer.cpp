#include <UIWindow_SceneTreeViewer.h>

UIWindow_SceneTreeViewer::UIWindow_SceneTreeViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_SceneTreeViewer::init()
{
    
}

void UIWindow_SceneTreeViewer::draw(bool isSimulationMode)
{
    ImGui::Begin(m_title);
    ImGui::Button("Scene Tree Viewer");
    ImGui::End();
}

void UIWindow_SceneTreeViewer::update(bool isSimulationMode)
{
    
}

void UIWindow_SceneTreeViewer::shutdown()
{
    
}