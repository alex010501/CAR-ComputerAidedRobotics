#include <2D/UIWindow_SceneTreeViewer.h>

UIWindow_SceneTreeViewer::UIWindow_SceneTreeViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_SceneTreeViewer::draw()
{
    UIWindow::draw();
    ImGui::Button("Scene Tree Viewer");
    ImGui::End();
}

void UIWindow_SceneTreeViewer::shutdown()
{
    
}