#include <UIWindow_3DWorkspace.h>

UIWindow_3DWorkSpace::UIWindow_3DWorkSpace(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_3DWorkSpace::draw()
{
    UIWindow::draw();
    ImGui::End();
}

void UIWindow_3DWorkSpace::shutdown()
{
    
}