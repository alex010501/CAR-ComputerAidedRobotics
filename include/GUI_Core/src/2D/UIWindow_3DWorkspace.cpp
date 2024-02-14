#include <2D/UIWindow_3DWorkspace.h>

UIWindow_3DWorkSpace::UIWindow_3DWorkSpace(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_3DWorkSpace::draw()
{
    UIWindow::draw();
    std::string lv_input = "3DWorkspace";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::End();
}