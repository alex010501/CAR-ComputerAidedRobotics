#include <UIWindow_3DWorkspace.h>

UIWindow_3DWorkSpace::UIWindow_3DWorkSpace(const char* p_title): UIWindow(p_title)
{}

void UIWindow_3DWorkSpace::loadScene(BaseScene* p_scene)
{
    m_scene = p_scene;
}

void UIWindow_3DWorkSpace::init()
{
    m_scene->create_triangle();
    m_scene->create_shaders();

    m_scene->create_framebuffer(1600, 900);
}

void UIWindow_3DWorkSpace::draw()
{
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
    ImGui::SetNextWindowClass(&window_class);
    ImGui::Begin(m_title);

    // we access the ImGui window size
    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    // we rescale the framebuffer to the actual window size here and reset the glViewport
    m_scene->rescale_framebuffer(window_width, window_height);
    glViewport(0, 0, window_width, window_height);

    // we get the screen position of the window
    ImVec2 pos = ImGui::GetCursorScreenPos();

    // and here we can add our created texture as image to ImGui
    // unfortunately we need to use the cast to void* or I didn't find another way tbh
    ImGui::GetWindowDrawList()->AddImage(
        (void*)(intptr_t)m_scene->texture_id,
        ImVec2(pos.x, pos.y),
        ImVec2(pos.x + window_width, pos.y + window_height),
        ImVec2(0, 1),
        ImVec2(1, 0));

    ImGui::End();
}

void UIWindow_3DWorkSpace::update()
{
    m_scene->bind_framebuffer();

    m_scene->render_framebuffer();

    m_scene->unbind_framebuffer();
}

void UIWindow_3DWorkSpace::shutdown()
{
    
}