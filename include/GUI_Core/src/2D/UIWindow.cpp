#include <2D/UIWindow.h>

GUIWindow::GUIWindow(const char *p_title, int p_width, int p_height, bool p_fullscreenSwitch): m_title(p_title)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        // Handle initialization error
        return;
    }

    // Configure GLFW window hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    this->m_fullscreen = p_fullscreenSwitch;

    // Create GLFW window
    if (p_fullscreenSwitch)
    {
        GLFWmonitor * lv_monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode * lv_mode = glfwGetVideoMode(lv_monitor);
        this->m_width = lv_mode->width;
        this->m_height = lv_mode->height;
        this->m_window = glfwCreateWindow(lv_mode->width, lv_mode->height, this->m_title,
                                        lv_monitor, NULL);
    }
    else
    {
        this->m_width = p_width;
        this->m_height = p_height;
        this->m_window = glfwCreateWindow(p_width, p_height, this->m_title, NULL, NULL);
    }

    if (!this->m_window)
    {
        // Handle window creation error
        glfwTerminate();
        return;
    }

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

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, this->m_width, this->m_height);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(this->m_window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_Implbgfx_Init(0);



/*
    // Initialize Imgui
    ImGui::CreateContext();
    ImGui_Implbgfx_Init(0);

    // const bgfx::Caps * lv_caps;
    // lv_caps = bgfx::getCaps();

    bgfx::RendererType::Enum lv_type;
    lv_type = bgfx::getRendererType();
    

    switch (lv_type)
    {
    case bgfx::RendererType::OpenGL:
    case bgfx::RendererType::OpenGLES:
        ImGui_ImplGlfw_InitForOpenGL(this->m_window, true);
        break;
    
    case bgfx::RendererType::Vulkan:
        ImGui_ImplGlfw_InitForVulkan(this->m_window, true);
        break;    

    case bgfx::RendererType::Agc:
    case bgfx::RendererType::Direct3D11:
    case bgfx::RendererType::Direct3D12:
    case bgfx::RendererType::Gnm:
    case bgfx::RendererType::Metal:
    case bgfx::RendererType::Nvn:    
        ImGui_ImplGlfw_InitForOther(this->m_window, true);
        break;

    case bgfx::RendererType::Noop:
        // Handle initialization error
        bgfx::shutdown();
        glfwDestroyWindow(this->m_window);
        glfwTerminate();
        return;
        break;
    
    default:
        break;
    }*/
}

GLFWwindow* GUIWindow::getWindow()
{
    return this->m_window;
}

void GUIWindow::update()
{
    char * lv_buf = new char[256];
    float lv_f; 
	// bgfx::renderFrame();
    while (!glfwWindowShouldClose(this->m_window))
    {
        // Clear the screen
        bgfx::touch(0);

        // Poll for and process events
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplGlfw_NewFrame();
        ImGui_Implbgfx_NewFrame();
        ImGui::NewFrame();

        // Create ImGui GUI here
        ImGui::Text("Hello, world %d", 123);
        if (ImGui::Button("Save"))
        {
            // Do something
        }
        ImGui::InputText("string", lv_buf, 256);
        ImGui::SliderFloat("float", &lv_f, 0.0f, 1.0f);

        // Render ImGui
        ImGui::Render();
        ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());

        // Present the frame
        bgfx::frame();
    }

}

void GUIWindow::shutdown()
{
    ImGui_Implbgfx_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    bgfx::shutdown();
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

// void UI_Window::render()
// {
//     if (!ImGui::Begin(this->m_title, &(this->m_open)))
//     {
//         ImGui::End();
//         return;
//     }

//     ImGui::End();
// }