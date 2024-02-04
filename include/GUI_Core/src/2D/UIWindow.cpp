#include <2D/UIWindow.h>

UIWindow::UIWindow(const char* p_title): m_title(p_title)
{
    
}

void UIWindow::draw()
{
    ImGui::Begin(m_title);
}