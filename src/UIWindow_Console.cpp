#include <UIWindow_Console.h>

UIWindow_Console::UIWindow_Console(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_Console::draw()
{
    UIWindow::draw();
    ImGui::Button("Console");
    ImGui::End();
}

void UIWindow_Console::shutdown()
{
    
}