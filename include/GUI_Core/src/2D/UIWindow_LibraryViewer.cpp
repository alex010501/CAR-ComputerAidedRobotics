#include <2D/UIWindow_LibraryViewer.h>

UIWindow_LibraryViewer::UIWindow_LibraryViewer(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_LibraryViewer::draw()
{
    UIWindow::draw();
    ImGui::Button("Library Viewer");
    ImGui::End();
}

void UIWindow_LibraryViewer::shutdown()
{
    
}