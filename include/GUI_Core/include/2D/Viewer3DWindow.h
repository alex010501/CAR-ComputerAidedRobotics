#include "UIWindow.h"

class Viewer3DWindow: public UIWindow {
private:
    
public:
    char * m_input;

    Viewer3DWindow(const char* p_title);
    void draw();
};