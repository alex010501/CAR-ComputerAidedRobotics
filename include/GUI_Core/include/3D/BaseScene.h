#pragma once

#include <iostream>
#include <string>
#include <cstring>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <stb_image.h>

class BaseScene
{
protected:
    GLuint VAO, VBO, FBO, RBO;
    GLuint shader_id;

    const char *vertex_shader_code = R"*(
    #version 330

    layout (location = 0) in vec3 pos;

    void main()
    {
    	gl_Position = vec4(0.9*pos.x, 0.9*pos.y, 0.5*pos.z, 1.0);
    }
    )*";

    const char *fragment_shader_code = R"*(
    #version 330

    out vec4 color;

    void main()
    {
	    color = vec4(0.0, 1.0, 0.0, 1.0);
    }
    )*";

public:    
    GLuint texture_id;

    BaseScene();
    ~BaseScene();

    void create_triangle();
    void add_shader(GLuint program, const char* shader_code, GLenum type);
    void create_shaders();
    void create_framebuffer(int WIDTH, int HEIGHT);
    void bind_framebuffer();
    void unbind_framebuffer();
    void render_framebuffer();
    void rescale_framebuffer(float width, float height);
};