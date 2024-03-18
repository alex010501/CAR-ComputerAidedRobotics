#include <UIWindow_3DWorkspace.h>

UIWindow_3DWorkSpace::UIWindow_3DWorkSpace(const char* p_title):
                      UIWindow(p_title),
                      graph_Q1("Signal", &(this->q1)),
                      graph_Q2("Derivative", &(this->q2)),
                      graph_Q3("Integral", &(this->q3)),
                      Q1(),
                      Q2(),
                      Q3()
{}

void UIWindow_3DWorkSpace::loadScene(BaseScene* p_scene)
{
    this->m_scene = p_scene;
}

void UIWindow_3DWorkSpace::init()
{
    this->m_scene->create_triangle();
    this->m_scene->create_shaders();

    this->m_scene->create_framebuffer(1600, 900);

    // this->Q1 = randSignal();
    // this->Q2 = randSignal();
    // this->Q3 = randSignal();

    this->q1 = 0;
    this->q2 = 0;
    this->q3 = 0;

    this->m_time = 0;
    this->m_dt = 0;
}

void UIWindow_3DWorkSpace::draw()
{
    this->m_scene->bind_framebuffer();

    this->m_scene->render_framebuffer();

    this->m_scene->unbind_framebuffer();

    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
    ImGui::SetNextWindowClass(&window_class);
    ImGui::Begin(m_title);

    // we access the ImGui window size
    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    // we rescale the framebuffer to the actual window size here and reset the glViewport
    this->m_scene->rescale_framebuffer(window_width, window_height);
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
    this->q1 = this->Q1.get_signal(this->m_time);
    this->q2 = this->derivator.calculate(this->q1, this->m_dt);
    this->q3 = this->integrator.calculate(this->q1, this->m_dt);

    this->m_time += this->m_dt;
}

void UIWindow_3DWorkSpace::startSimulation(double p_dt, double p_duration)
{
    this->m_dt = p_dt;
    this->m_time = 0;

    this->derivator.init();
    this->integrator.init(0);

    this->signal_addGraph(&this->graph_Q1);
    this->signal_addGraph(&this->graph_Q2);
    this->signal_addGraph(&this->graph_Q3);
}

void UIWindow_3DWorkSpace::resetSimulation()
{
    // this->m_time = 0;
    this->m_dt = 0;
}

void UIWindow_3DWorkSpace::shutdown()
{
    
}