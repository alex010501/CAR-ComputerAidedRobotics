#include "GUI_Core.h"

int windowGLFW()
{
	// Initialize glfw
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Hello, bgfx!", NULL, NULL);

	bgfx::PlatformData pd;
    #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	pd.ndt = glfwGetX11Display();
	pd.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
	#elif BX_PLATFORM_OSX
	pd.nwh = glfwGetCocoaWindow(window);
	#elif BX_PLATFORM_WINDOWS
    pd.nwh = glfwGetWin32Window(window);
	#endif
    bgfx::setPlatformData(pd);

    bgfx::Init bgfx_init;
    bgfx_init.type = bgfx::RendererType::Count; // Automatically choose a renderer.
    bgfx_init.vendorId = BGFX_PCI_ID_NONE;
    bgfx_init.resolution.width = WNDW_WIDTH;
    bgfx_init.resolution.height = WNDW_HEIGHT;
    bgfx_init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx_init.platformData = pd;
    if (!(bgfx::init(bgfx_init)))
    {
        std::cout << "Fail of BGFX" << std::endl;
        getchar();
        return 1;
    }

	// Reset window
    bgfx::reset(WNDW_WIDTH, WNDW_HEIGHT, BGFX_RESET_VSYNC);

    // Enable debug text.
    bgfx::setDebug(BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, WNDW_WIDTH, WNDW_HEIGHT);

	bgfx::renderFrame();

    // Set empty primitive on screen
    

    while (!glfwWindowShouldClose(window))
	{
		bgfx::touch(0);
        bgfx::frame();
        glfwPollEvents();
    }

    bgfx::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();

	return 0;
}

void initGUI()
{
    GUIWindow window("test", 1280, 720);

    window.update();

    window.shutdown();
}