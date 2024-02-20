#include "GUI_Core.h"

CoreWindow::CoreWindow(const char *p_title, std::vector<UIWindow*> p_childWindows, const char* p_iconPath, int p_width, int p_height): m_title(p_title)
{
    if (p_iconPath)
    {
        int width, height, channels;
        unsigned char* iconData = stbi_load(p_iconPath, &width, &height, &channels, 0);
        this->m_icon[0].width = width;
        this->m_icon[0].height = height;
        this->m_icon[0].pixels = iconData;
    }
    else
    {
        this->m_icon = nullptr;
    }
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
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(this->m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
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
    ImGui::DockSpaceOverViewport(NULL, ImGuiDockNodeFlags_PassthruCentralNode);
    for (UIWindow* window : this->m_childWindows)
    {
        window->draw();
    }
    ImGui::Render();
    ImGui::UpdatePlatformWindows();

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.2f, 0.4f, 0.5f);

    
    /* ImGui Render */
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    /* Swap front and back buffers */
    glfwSwapBuffers(this->m_window);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
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