#include <2D/UIWindow_SceneTreeViewer.h>

UIWindow_SceneTreeViewer::UIWindow_SceneTreeViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_SceneTreeViewer::draw()
{
    UIWindow::draw();
    std::string lv_input = "Scene Tree";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::End();
}