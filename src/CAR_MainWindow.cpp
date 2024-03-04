#include <CAR_MainWindow.h>

CAR_MainWindow::CAR_MainWindow(const char* p_title, const char* p_iconPath, int p_width, int p_height):
                CoreWindow(p_title, p_iconPath, p_width, p_height),
                WorkspaceWindow("3d Workspace"),
                ConsoleWindow("Console"),
                LibraryWindow("Library"),
                PropertiesWindow("Properties"),
                SceneTreeWindow("Scene Tree"),
                ToolPanel("Tools"),
                PlotingWindow("Plots")
{
    
}


int CAR_MainWindow::run()
{
    if (this->init())
    {
        std::cout << "Error initializing window" << std::endl;
        return 1;
    }
    while (this->isOpen())
    {
        // Poll for and process events
        this->pollEvents();
        this->draw();
        this->update();
    }
    this->shutdown();
    return 0;
}










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

    this->m_scene = BaseScene();

    this->WorkspaceWindow.loadScene(&(this->m_scene));

    this->m_UIWindows = {&this->WorkspaceWindow, &this->ConsoleWindow, &this->LibraryWindow, &this->PropertiesWindow, &this->SceneTreeWindow, &this->ToolPanel, &this->PlotingWindow};    
        
    for(UIWindow* window : this->m_UIWindows)
        window->init();

    this->ToolPanel.signal_NewFile.connect(this, &CAR_MainWindow::EventNewFile);
    this->ToolPanel.signal_OpenFile.connect(this, &CAR_MainWindow::EventOpenFile);
    this->ToolPanel.signal_Save.connect(this, &CAR_MainWindow::EventSave);
    this->ToolPanel.signal_SaveAs.connect(this, &CAR_MainWindow::EventSaveAs);
    this->ToolPanel.signal_Undo.connect(this, &CAR_MainWindow::EventUndo);
    this->ToolPanel.signal_Redo.connect(this, &CAR_MainWindow::EventRedo);
    this->ToolPanel.signal_Cut.connect(this, &CAR_MainWindow::EventCut);
    this->ToolPanel.signal_Copy.connect(this, &CAR_MainWindow::EventCopy);
    this->ToolPanel.signal_Paste.connect(this, &CAR_MainWindow::EventPaste);
    this->ToolPanel.signal_Play.connect(this, &CAR_MainWindow::EventPlay);
    this->ToolPanel.signal_Pause.connect(this, &CAR_MainWindow::EventPause);
    this->ToolPanel.signal_Stop.connect(this, &CAR_MainWindow::EventStop);
}

void CAR_MainWindow::EventNewFile()
{
    std::cout << "New File" << std::endl;
}

void CAR_MainWindow::EventOpenFile()
{
    std::cout << "Open File" << std::endl;
}

void CAR_MainWindow::EventSave()
{
    std::cout << "EventSave" << std::endl;
}

void CAR_MainWindow::EventSaveAs()
{
    std::cout << "Save As" << std::endl;
}

void CAR_MainWindow::EventUndo()
{
    std::cout << "Undo" << std::endl;
}

void CAR_MainWindow::EventRedo()
{
    std::cout << "Redo" << std::endl;
}

void CAR_MainWindow::EventCut()
{
    std::cout << "Cut" << std::endl;
}

void CAR_MainWindow::EventCopy()
{
    std::cout << "Copy" << std::endl;
}

void CAR_MainWindow::EventPaste()
{
    std::cout << "Paste" << std::endl;
}

void CAR_MainWindow::EventPlay(int p_frequency, float p_duration)
{
    std::cout << "Play, frequency: " << p_frequency << ", duration: " << p_duration << std::endl;
}

void CAR_MainWindow::EventPause()
{
    std::cout << "Pause" << std::endl;
}

void CAR_MainWindow::EventStop()
{
    std::cout << "Stop" << std::endl;
}

void CAR_MainWindow::shutdownChildWindows()
{
    for(UIWindow* window : this->m_UIWindows)
        window->shutdown();
}

void CAR_MainWindow::drawChildWindows()
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