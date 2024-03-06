#include <UI/UIWindow.h>

void UIWindow::error_callback(int p_error, std::string p_description)
{
    this->signal_error(p_error, p_description);
}