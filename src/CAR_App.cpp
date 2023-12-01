// #include <SDL3/SDL.h>
// #include <SDL3/SDL_syswm.h>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_syswm.h>

#define WNDW_WIDTH 800//1600
#define WNDW_HEIGHT 450//900

#define GLFW_INCLUDE_NONE

#if defined(_WIN32)
#define GLFW_EXPOSE_NATIVE_WIN32
#elif defined(__linux__)
#define GLFW_EXPOSE_NATIVE_X11
#elif defined(__APPLE__)
#define GLFW_EXPOSE_NATIVE_COCOA
#endif

#include <iostream>

#include <RobotArm.h>
#include <GUI_Core.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_syswm.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/uint32_t.h>

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

int windowSDL()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("BGFX Window",
                                          //   SDL_WINDOWPOS_UNDEFINED,
                                          //   SDL_WINDOWPOS_UNDEFINED,
                                          WNDW_WIDTH, WNDW_HEIGHT,
                                          SDL_WINDOW_RESIZABLE); // SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    // Check that the window was successfully created
    if (window == NULL)
    {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SysWMinfo wmi;
    // SDL_VERSION(&wmi.version);
    if (SDL_GetWindowWMInfo(window, &wmi, SDL_SYSWM_CURRENT_VERSION) < 0)
        return 1;

	bgfx::PlatformData pd;
    #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	pd.ndt = wmi.info.x11.display;
	pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
	#elif BX_PLATFORM_OSX
	pd.nwh = wmi.info.cocoa.window;
	#elif BX_PLATFORM_WINDOWS
	pd.nwh = wmi.info.win.window;
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
    // cout << "Success of BGFX" << endl;

    // Reset window
    bgfx::reset(WNDW_WIDTH, WNDW_HEIGHT, BGFX_RESET_VSYNC);

    // Enable debug text.
    bgfx::setDebug(BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, WNDW_WIDTH, WNDW_HEIGHT);

    bgfx::renderFrame();

    // Set empty primitive on screen
    bgfx::touch(0);

    unsigned int counter = 0;
    while (true)
    {
		bgfx::touch(0);
        // Get the next event
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                // Break out of the loop on quit
                break;
            }
        }
        bgfx::frame();
        counter++;
        std::cout << counter << std::endl;
    }
    bgfx::shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int main()
{
	int c;
	std::cout << "0: SDL | " << "1: GLFW" << ">";
	std::cin >> c;

	switch (c)
	{
	case 0:
		std::cout << "Using SDL" << std::endl;
		return windowSDL();
		break;
	case 1:
		std::cout << "Using GLFW" << std::endl;
		return windowGLFW();
		break;
	default:
		std::cout << "Unknown" << std::endl;
		getchar();
		getchar();
		return 1;
		break;
	}
}