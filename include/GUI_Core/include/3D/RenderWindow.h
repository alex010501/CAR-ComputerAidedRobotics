#pragma once

class RenderWindow
{
public:
    RenderWindow() = default;
    RenderWindow(int width, int height);
    ~RenderWindow();
    void beginFrame();
    void endFrame();

private:
    int m_width;
    int m_height;
};