#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h> // Подключаем glew для того, чтобы получить все необходимые заголовочные файлы OpenGL

class Shader
{
public:
    // Идентификатор программы
    GLuint Program;
    // Конструктор считывает и собирает шейдер
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // Использование программы
    void Use();
};

#endif