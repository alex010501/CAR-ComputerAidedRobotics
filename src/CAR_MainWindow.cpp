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
    this->m_simState = SIM_STOP;
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

    this->ToolPanel.signal_NewFile .connect(this, &CAR_MainWindow::EventNewFile);
    this->ToolPanel.signal_OpenFile.connect(this, &CAR_MainWindow::EventOpenFile);
    this->ToolPanel.signal_Save    .connect(this, &CAR_MainWindow::EventSave);
    this->ToolPanel.signal_SaveAs  .connect(this, &CAR_MainWindow::EventSaveAs);
    this->ToolPanel.signal_Undo    .connect(this, &CAR_MainWindow::EventUndo);
    this->ToolPanel.signal_Redo    .connect(this, &CAR_MainWindow::EventRedo);
    this->ToolPanel.signal_Cut     .connect(this, &CAR_MainWindow::EventCut);
    this->ToolPanel.signal_Copy    .connect(this, &CAR_MainWindow::EventCopy);
    this->ToolPanel.signal_Paste   .connect(this, &CAR_MainWindow::EventPaste);
    this->ToolPanel.signal_Play    .connect(this, &CAR_MainWindow::EventPlay);
    this->ToolPanel.signal_Pause   .connect(this, &CAR_MainWindow::EventPause);
    this->ToolPanel.signal_Stop    .connect(this, &CAR_MainWindow::EventStop);

    for (UIWindow* window : this->m_UIWindows)
    {
        window->signal_error.connect(this, &CAR_MainWindow::EventOnError);
    }

    this->signal_console.connect(&(this->ConsoleWindow), &UIWindow_Console::consoleCallback);
}

void CAR_MainWindow::EventNewFile()
{
    this->signal_console('b', std::time(nullptr), "Created new file");
}

void CAR_MainWindow::EventOpenFile()
{
    this->signal_console('g', std::time(nullptr), "Opened file");
}

void CAR_MainWindow::EventSave()
{
    this->signal_console('g', std::time(nullptr), "Saved file");
}

void CAR_MainWindow::EventSaveAs()
{
    this->signal_console('g', std::time(nullptr), "Saved file as");
}

void CAR_MainWindow::EventUndo()
{
    this->signal_console('b', std::time(nullptr), "Undid action");
}

void CAR_MainWindow::EventRedo()
{
    this->signal_console('b', std::time(nullptr), "Redid action");
}

void CAR_MainWindow::EventCut()
{
    this->signal_console('b', std::time(nullptr), "Cut selection");
}

void CAR_MainWindow::EventCopy()
{
    this->signal_console('b', std::time(nullptr), "Copied selection");
}

void CAR_MainWindow::EventPaste()
{
    this->signal_console('b', std::time(nullptr), "Pasted selection");
}

void CAR_MainWindow::EventPlay(int p_frequency, float p_duration)
{
    if (this->m_simState == SIM_PAUSE)
        this->signal_console('b', std::time(nullptr), "Resume simulation");
    else
    {
        this->m_simFrequency = p_frequency;
        this->m_simTickCount = p_duration * p_frequency;

        std::stringstream lv_stream;
        lv_stream << std::fixed << std::setprecision(1) << p_duration;

        std::string str = "Simulation started; Selected Frequency: " + std::to_string(p_frequency) + " Hz; Duration: " + lv_stream.str() + " s";
        this->signal_console('b', std::time(nullptr), str.c_str());
    }

    this->m_simState = SIM_PLAY;    
}

void CAR_MainWindow::EventPause()
{
    this->m_simState = SIM_PAUSE;
    this->signal_console('b', std::time(nullptr), "Simulation paused");
}

void CAR_MainWindow::EventStop()
{
    if (this->m_simState == SIM_STOP)
        return;    
    this->m_simState = SIM_STOP;
    this->signal_console('b', std::time(nullptr), "Simulation stopped");
}

void CAR_MainWindow::EventOnError(int p_error, std::string p_description)
{
    std::string lv_error_str = "Error #" + std::to_string(p_error) + ": " + p_description;
    this->signal_console('r', std::time(nullptr), lv_error_str.c_str());
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