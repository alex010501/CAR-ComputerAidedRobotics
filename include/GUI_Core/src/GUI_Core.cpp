#include "GUI_Core.h"

CoreWindow::CoreWindow(const char *p_title, GLFWimage* p_icon, std::vector<UIWindow*> p_childWindows, int p_width, int p_height): m_title(p_title)
{
    this->m_icon = p_icon;
    this->m_width = p_width;
    this->m_height = p_height;
    this->m_childWindows = p_childWindows;
}

void CoreWindow::init()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        // Handle initialization error
        return;
    }

    // Configure GLFW window hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
    // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
   
    // Create GLFW window
    this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title, NULL, NULL);
    glfwSetWindowSizeLimits(this->m_window, 640, 360, GLFW_DONT_CARE, GLFW_DONT_CARE);
        // glfwSetWindowAspectRatio(this->m_window, 16, 9);
        // glfwMaximizeWindow(this->m_window);
        // glfwFocusWindow(this->m_window);

    if (!this->m_window)
    {
        // Handle window creation error
        glfwTerminate();
        return;
    }

    // Set Icon
    glfwSetWindowIcon(this->m_window, 1, this->m_icon);

    // Set GLFW window user pointer
    // CoreWindow* myWindow = this;
    glfwSetWindowUserPointer(this->m_window, this);

    // Set GLFW callbacks
    auto CoreWindowResizeCallback = [](GLFWwindow* p_window, int p_width, int p_height)
    {
        static_cast<CoreWindow*>(glfwGetWindowUserPointer(p_window))->ResizeCallback(p_width, p_height);
    };

    glfwSetWindowSizeCallback(this->m_window, CoreWindowResizeCallback);

    // Initialize BGFX
    bgfx::PlatformData lv_pd;
    #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	lv_pd.ndt = glfwGetX11Display();
	lv_pd.nwh = (void*)(uintptr_t)glfwGetX11Window(this->m_window);
	#elif BX_PLATFORM_OSX
	lv_pd.nwh = glfwGetCocoaWindow(this->m_window);
	#elif BX_PLATFORM_WINDOWS
    lv_pd.nwh = glfwGetWin32Window(this->m_window);
	#endif
    bgfx::setPlatformData(lv_pd);

    bgfx::Init lv_bgfx_init;
    // lv_bgfx_init.type = bgfx::RendererType::Count; // Automatically choose a renderer.
    #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	lv_bgfx_init.type = bgfx::RendererType::OpenGL;
	#elif BX_PLATFORM_OSX
    lv_bgfx_init.type = bgfx::RendererType::Metal;
	#elif BX_PLATFORM_WINDOWS
    lv_bgfx_init.type = bgfx::RendererType::OpenGL;
	#endif
    lv_bgfx_init.vendorId = BGFX_PCI_ID_NONE;
    lv_bgfx_init.resolution.width = this->m_width;
    lv_bgfx_init.resolution.height = this->m_height;
    lv_bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
    lv_bgfx_init.platformData = lv_pd;

    bgfx::init(lv_bgfx_init);

    // Reset window
    bgfx::reset(this->m_width, this->m_height, BGFX_RESET_VSYNC);

    // Enable debug text.
    // bgfx::setDebug(BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking

    // Setup Platform/Renderer backends
    lv_bgfx_init.type = bgfx::RendererType::OpenGL;
    ImGui_ImplGlfw_InitForOpenGL(this->m_window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_Implbgfx_Init(0);
}

void CoreWindow::ResizeCallback(int p_width, int p_height)
{
    this->m_width = p_width;
    this->m_height = p_height;
    bgfx::reset(this->m_width, this->m_height, BGFX_RESET_VSYNC);
    this->update();
}

void CoreWindow::update()
{
    char * lv_buf = new char[256];
    float lv_f;
    
    // Start the ImGui frame
    ImGui_Implbgfx_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Create ImGui GUI here

    // ImGuiViewport* viewport = ImGui::GetMainViewport();
    // ImGui::SetNextWindowSize(ImVec2(viewport->Size.x * 0.20f, viewport->Size.y));
    // ImGui::SetNextWindowPos(viewport->Pos);

    ImGui::DockSpaceOverViewport(NULL, ImGuiDockNodeFlags_PassthruCentralNode);

    for (UIWindow* window : this->m_childWindows)
    {
        window->draw();
    }
    /*ImGui::Begin("Dockable Window");//, nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    ImGui::Text("Hello, world %d", 123);
    if (ImGui::Button("Save"))
    {
        // Do something
    }
    ImGui::InputText("string", lv_buf, 256);
    ImGui::SliderFloat("float", &lv_f, 0.0f, 1.0f);
    ImGui::End();*/

    // Render ImGui
    ImGui::Render();

    // Clear the screen
    bgfx::touch(0);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x002137FF, 0.5f, 0);
    bgfx::setViewRect(0, 0, 0, this->m_width, this->m_height);
    ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());

    // Present the frame
    bgfx::frame();
    glfwSwapBuffers(this->m_window);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void CoreWindow::shutdown()
{
    ImGui_Implbgfx_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    bgfx::shutdown();
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

GLFWwindow* CoreWindow::getWindow()
{
    return this->m_window;
}
