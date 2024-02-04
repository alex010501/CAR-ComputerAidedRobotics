#include <2D/Viewer3DWindow.h>

Viewer3DWindow::Viewer3DWindow(const char* p_title): UIWindow(p_title)
{
    this->m_input = new char[256];
    // this->m_input = "Hello World!";
}

void Viewer3DWindow::draw()
{
    UIWindow::draw();
    std::string lv_input = "Hello World!";
    ImGui::InputText("Input", lv_input.data(), 256);
    ImGui::InputText("Input", this->m_input, 256);
    ImGui::End();
}