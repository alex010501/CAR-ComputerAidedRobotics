#include <CAR_MainWindow.h>

CAR_MainWindow::CAR_MainWindow(const char* p_title, const char* p_iconPath, int p_width, int p_height):
                                                    CoreWindow(p_title, p_iconPath, p_width, p_height){}

void CAR_MainWindow::OpenGLRender()
{
    // Set background color
    float lv_red   = 0.0f;
    float lv_green = 0.2f;
    float lv_blue  = 0.4;
    float lv_alpha = 0.5f;
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(lv_red, lv_green, lv_blue, lv_alpha);
}

void CAR_MainWindow::initChildWindows()
{
    static UIWindow_3DWorkSpace      WorkspaceWindow("3d Workspace");
    static UIWindow_Console          ConsoleWindow("Console");
    static UIWindow_LibraryViewer    LibraryWindow("Library");
    static UIWindow_PropertiesViewer PropertiesWindow("Properties");
    static UIWindow_SceneTreeViewer  SceneTreeWindow("Scene Tree");
    static UIWindow_ToolPanel        ToolPanel("Tools");
    static UIWindow_PlotingWorkspace PlotingWindow("Plots");

    this->m_scene = BaseScene();

    WorkspaceWindow.loadScene(&(this->m_scene));

    this->m_UIWindows.push_back(&WorkspaceWindow);
    this->m_UIWindows.push_back(&ConsoleWindow);
    this->m_UIWindows.push_back(&LibraryWindow);
    this->m_UIWindows.push_back(&PropertiesWindow);
    this->m_UIWindows.push_back(&SceneTreeWindow);
    this->m_UIWindows.push_back(&ToolPanel);
    this->m_UIWindows.push_back(&PlotingWindow);    
        
    for(UIWindow* window : this->m_UIWindows)
        window->init();
}

void CAR_MainWindow::shutdownChildWindows()
{
    for(UIWindow* window : this->m_UIWindows)
        window->shutdown();
}

void CAR_MainWindow::showChildWindows()
{
    for(UIWindow* window : this->m_UIWindows)
        window->draw();
}

void CAR_MainWindow::updateChildWindows()
{
    for(UIWindow* window : this->m_UIWindows)
        window->update();
}

void CAR_MainWindow::initDockspace()
{    
    ImGuiID dockspace_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    static bool isInit = true;
    ImGuiID dock_id_up, dock_id_right, dock_id_leftUp, dock_id_leftBottom, dock_id_center, dock_id_bottom;
    if (isInit)
    {
        isInit = false;
        ImGui::DockBuilderRemoveNode(dockspace_id);
        ImGui::DockBuilderAddNode(dockspace_id);
        ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

        ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Up, 0.05f, &dock_id_up, &dock_id_center);
        ImGui::DockBuilderSplitNode(dock_id_center, ImGuiDir_Right, 0.2f, &dock_id_right, &dock_id_center);
        ImGui::DockBuilderSplitNode(dock_id_center, ImGuiDir_Left, 0.25f, &dock_id_leftUp, &dock_id_center);
        ImGui::DockBuilderSplitNode(dock_id_center, ImGuiDir_Down, 0.2f, &dock_id_bottom, &dock_id_center);
        ImGui::DockBuilderSplitNode(dock_id_leftUp, ImGuiDir_Down, 0.6f, &dock_id_leftBottom, &dock_id_leftUp);

        ImGui::DockBuilderDockWindow("Tools", dock_id_up);
        ImGui::DockBuilderDockWindow("Scene Tree", dock_id_leftUp);
        ImGui::DockBuilderDockWindow("Properties", dock_id_leftBottom);
        ImGui::DockBuilderDockWindow("Plots", dock_id_right);
        ImGui::DockBuilderDockWindow("3d Workspace", dock_id_center);
        ImGui::DockBuilderDockWindow("Console", dock_id_bottom);        
        ImGui::DockBuilderDockWindow("Library", dock_id_bottom);

        ImGui::DockBuilderFinish(dockspace_id);
    }
}