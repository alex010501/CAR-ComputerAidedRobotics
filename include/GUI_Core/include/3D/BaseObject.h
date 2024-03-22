#pragma once

#include <ShadersBuffers/Shader.h>

struct mesh
{
};

struct axis
{
    double x;
};

class Base3DObject
{
public:
    Base3DObject();
    ~Base3DObject();

    bool update();

private:


};