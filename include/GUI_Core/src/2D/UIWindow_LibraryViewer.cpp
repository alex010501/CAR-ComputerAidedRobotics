#include <2D/UIWindow_LibraryViewer.h>

UIWindow_LibraryViewer::UIWindow_LibraryViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_LibraryViewer::draw()
{
    UIWindow::draw();
    std::string lv_input = "Library";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::End();
}

void UIWindow_LibraryViewer::shutdown()
{
    
}