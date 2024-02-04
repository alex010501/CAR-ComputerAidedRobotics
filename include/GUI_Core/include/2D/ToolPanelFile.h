#include "UIWindow.h"

class ToolPanelFile: public UIWindow {
private:
    
public:
    bool m_open;
    bool m_file;
    bool m_switch;

    ToolPanelFile(const char* p_title);
    void draw();
};