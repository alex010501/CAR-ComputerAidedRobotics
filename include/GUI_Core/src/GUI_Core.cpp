#include <GUI_Core.h>

CoreWindow::CoreWindow(const char *p_title, const char* p_iconPath, int p_width, int p_height): m_title(p_title), m_iconPath(p_iconPath)
{
    this->m_width = p_width;
    this->m_height = p_height;
}

int CoreWindow::init()
{
    // Initialise GLFW
    if (!glfwInit())
    {
        // Handle initialization error
        return 1;
    }

    // Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 4.5
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
    ImGui_ImplOpenGL3_Init("#version 460 core");

    glfwMaximizeWindow(this->m_window);
    
    this->initChildWindows();

    return 0;
}

void CoreWindow::ResizeCallback(int p_width, int p_height)
{
    this->m_width = p_width;
    this->m_height = p_height;
    this->draw();
}

void CoreWindow::PosCallback(int p_x, int p_y)
{
    glfwSetWindowPos(this->m_window, p_x, p_y);
    this->draw();
}

void CoreWindow::setCallbacks()
{
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
}

void CoreWindow::draw()
{
    // Start ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Dockspace settings
    this->initDockspace();

    // Render subwindows
    this->drawChildWindows();

    // Prepare ImGui data for rendering
    ImGui::Render();
    ImGui::UpdatePlatformWindows();

    // OpenGL render
    this->OpenGLRender();

    // ImGui-OpenGL render
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    // Swap front and back buffers
    glfwSwapBuffers(this->m_window);
}

void CoreWindow::update()
{
    // Child windows information update
    this->updateChildWindows();
}

void CoreWindow::shutdown()
{
    // Shutdown child windows
    this->shutdownChildWindows();

    // ImGui backend shutdown
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();

    // Imgui shutdown
    ImGui::DestroyContext();
    ImPlot::DestroyContext();

    // GLFW shutdown
    stbi_image_free(this->m_icon[0].pixels);
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


// Addition helper functions
bool GUI_Helper::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

GUI_Helper::ImageData GUI_Helper::LoadImage(const char* filename)
{
    int my_image_width = 0;
    int my_image_height = 0;
    GLuint my_image_texture = 0;
    bool ret = GUI_Helper::LoadTextureFromFile(filename, &my_image_texture, &my_image_width, &my_image_height);
    IM_ASSERT(ret);

    GUI_Helper::ImageData imageData;
    imageData.texture = (void*)(intptr_t)my_image_texture;
    imageData.width = my_image_width;
    imageData.height = my_image_height;

    return imageData;
}

bool GUI_Helper::ImGui_imageButton(GUI_Helper::ImageData imageData, bool enabled)
{   
    ImGui::BeginDisabled(!enabled);
    bool ret = ImGui::IsItemClicked(ImGui::ImageButton(imageData.texture, ImVec2(imageData.width, imageData.height)));
    ImGui::EndDisabled();
    return ret;
}

void GUI_Helper::ImGui_picture(GUI_Helper::ImageData imageData)
{
    ImGui::Image(imageData.texture, ImVec2(imageData.width, imageData.height));
}