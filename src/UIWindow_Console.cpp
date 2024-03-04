#include <UIWindow_Console.h>

UIWindow_Console::UIWindow_Console(const char* p_title): UIWindow(p_title)
{

}

void UIWindow_Console::init()
{
    this->m_commandBuffer[0] = '\0';
}

void UIWindow_Console::draw()
{
    ImGui::Begin(m_title);

    ImGui::InputText(" ", m_commandBuffer, IM_ARRAYSIZE(m_commandBuffer));
    ImGui::SameLine();
    if (ImGui::Button("Enter"))
    {
        comandCallback();
    }
    ImGui::End();
}

void UIWindow_Console::comandCallback()
{
    this->m_commandBuffer[0] = '\0';
}

void UIWindow_Console::update()
{
    
}

void UIWindow_Console::shutdown()
{
    
}

void UIWindow_Console::error_callback(int error, const char* description)
{
    // fprintf(stderr, "Error: %s\n", description);
}