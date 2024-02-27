#include <GUI_Core.h>

CoreWindow::CoreWindow(const char *p_title, std::vector<UIWindow*> p_childWindows, const char* p_iconPath, int p_width, int p_height): m_title(p_title), m_iconPath(p_iconPath)
{
    this->m_width = p_width;
    this->m_height = p_height;
    this->m_childWindows = p_childWindows;
}

int CoreWindow::init()
{
    // Initialise GLFW
    if (!glfwInit())
    {
        // Handle initialization error
        return 1;
    }

    glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
   
    // Create GLFW window
    this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title, NULL, NULL);
    if (!this->m_window)
    {
        glfwTerminate();
        return 1;
    }
    
    glfwSetWindowSizeLimits(this->m_window, 640, 360, GLFW_DONT_CARE, GLFW_DONT_CARE);

    if (this->m_iconPath)
    {
        int lv_image_width, lv_image_height, lv_image_channels;
        unsigned char* lv_image_data = stbi_load(this->m_iconPath, &lv_image_width, &lv_image_height, &lv_image_channels, 0);
        if (lv_image_data)
        {
            this->m_icon = new GLFWimage;
            this->m_icon[0].width = lv_image_width;
            this->m_icon[0].height = lv_image_height;
            this->m_icon[0].pixels = lv_image_data;
        }
        else
        {
            std::cout << "Failed to load image: " << this->m_iconPath << std::endl;
            stbi_image_free(lv_image_data);
            this->m_icon = NULL;
        }
    }
    else
    {
        this->m_icon = NULL;
    }

    // Set Icon
    if (this->m_icon)
    {
        glfwSetWindowIcon(this->m_window, 1, this->m_icon);
    }
    else
    {
        glfwSetWindowIcon(this->m_window, 0, NULL);
    }
    
    
    // Set GLFW window user pointer
    glfwSetWindowUserPointer(this->m_window, this);
    
    // Set GLFW callbacks
    auto CoreWindowResizeCallback = [](GLFWwindow* p_window, int p_width, int p_height)
    {
        static_cast<CoreWindow*>(glfwGetWindowUserPointer(p_window))->ResizeCallback(p_width, p_height);
    };
    glfwSetWindowSizeCallback(this->m_window, CoreWindowResizeCallback);

    auto CoreWindowPosCallback = [](GLFWwindow* p_window, int p_x, int p_y)
    {
        static_cast<CoreWindow*>(glfwGetWindowUserPointer(p_window))->PosCallback(p_x, p_y);
    };
    glfwSetWindowPosCallback(this->m_window, CoreWindowPosCallback);

    glfwMakeContextCurrent(this->m_window);
    glfwSwapInterval(1); // Enable vsync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return 1;
    }

    // Setup Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(this->m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    for (UIWindow* window : this->m_childWindows)
    {
        window->init();
    }

    glfwMaximizeWindow(this->m_window);

    return 0;
}

void CoreWindow::ResizeCallback(int p_width, int p_height)
{
    this->m_width = p_width;
    this->m_height = p_height;
    this->update();
}

void CoreWindow::PosCallback(int p_x, int p_y)
{
    glfwSetWindowPos(this->m_window, p_x, p_y);
    this->update();
}

void CoreWindow::update()
{
    /* ImGui Frame */
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
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
    for (UIWindow* window : this->m_childWindows)
    {
        window->draw();
    }
    // ImGui::ShowDemoWindow();
    ImGui::Render();
    ImGui::UpdatePlatformWindows();

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.2f, 0.4f, 0.5f);

    for (UIWindow* window : this->m_childWindows)
    {
        window->update();
    }
    
    /* ImGui Render */
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    /* Swap front and back buffers */
    glfwSwapBuffers(this->m_window);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void CoreWindow::shutdown()
{
    for (UIWindow* window : this->m_childWindows)
    {
        window->shutdown();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    ImPlot::DestroyContext();
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

bool CoreWindow::isOpen()
{
    return !glfwWindowShouldClose(this->m_window);   
}

void CoreWindow::pollEvents()
{
    glfwPollEvents();
}