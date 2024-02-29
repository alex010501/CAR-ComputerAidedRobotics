#include <UIWindow_Console.h>

UIWindow_Console::UIWindow_Console(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_Console::init()
{
    
}

void UIWindow_Console::draw(bool isSimulationMode)
{
    ImGui::Begin(m_title);
    ImGui::Button("Console");
    ImGui::End();
}

void UIWindow_Console::update(bool isSimulationMode)
{
    
}

void UIWindow_Console::shutdown()
{
    
}