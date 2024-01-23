#include "GUI_Core.h"

CoreWindow::CoreWindow(const char *p_title, int p_width, int p_height, bool p_fullscreenSwitch, GLFWimage* p_icon): m_title(p_title)
{
    this->m_fullscreen = p_fullscreenSwitch;
    this->m_icon = p_icon;
    this->m_width = p_width;
    this->m_height = p_height;
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

    // Create GLFW window
    if (this->m_fullscreen)
    {
        GLFWmonitor * lv_monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode * lv_mode = glfwGetVideoMode(lv_monitor);
        this->m_window = glfwCreateWindow(lv_mode->width, lv_mode->height, this->m_title, lv_monitor, NULL);
    }
    else
    {
        this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title, NULL, NULL);
        glfwSetWindowSizeLimits(this->m_window, 640, 360, GLFW_DONT_CARE, GLFW_DONT_CARE);
        glfwMaximizeWindow(this->m_window);
    }

    if (!this->m_window)
    {
        // Handle window creation error
        glfwTerminate();
        return;
    }

    // Set Icon
    glfwSetWindowIcon(this->m_window, 1, this->m_icon);


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

void CoreWindow::update()
{
    char * lv_buf = new char[256];
    float lv_f; 
	// bgfx::renderFrame();
    while (!glfwWindowShouldClose(this->m_window))
    {
        // Clear the screen
        bgfx::touch(0);

        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x002137FF, 0.5f, 0);
        bgfx::setViewRect(0, 0, 0, this->m_width, this->m_height);

        // Poll for and process events
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_Implbgfx_NewFrame();
        ImGui_ImplGlfw_NewFrame();        
        ImGui::NewFrame();

        // Create ImGui GUI here

        ImGui::DockSpaceOverViewport(NULL, ImGuiDockNodeFlags_PassthruCentralNode);
        ImGui::Begin("Dockable Window");

        ImGui::Text("Hello, world %d", 123);
        if (ImGui::Button("Save"))
        {
            // Do something
        }
        ImGui::InputText("string", lv_buf, 256);
        ImGui::SliderFloat("float", &lv_f, 0.0f, 1.0f);
        ImGui::End();

        // Render ImGui
        ImGui::Render();
        int lv_display_w, lv_display_h;
        glfwGetFramebufferSize(this->m_window, &lv_display_w, &lv_display_h);
        bgfx::setViewRect(0, 0, 0, lv_display_w, lv_display_h);
        bgfx::touch(0);
        ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());

        // Present the frame
        bgfx::frame();
        glfwSwapBuffers(this->m_window);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

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
