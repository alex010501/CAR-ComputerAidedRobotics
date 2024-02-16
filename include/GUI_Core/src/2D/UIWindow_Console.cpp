#include <2D/UIWindow_Console.h>

UIWindow_Console::UIWindow_Console(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_Console::draw()
{
    UIWindow::draw();
    std::string lv_input = "Console";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::End();
}

void UIWindow_Console::shutdown()
{
    
}