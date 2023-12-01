#include "UIWindow.h"

void UI_Window::render()
{
    if (!ImGui::Begin(this->m_title, &(this->m_open)))
    {
        ImGui::End();
        return;
    }

    ImGui::End();
}