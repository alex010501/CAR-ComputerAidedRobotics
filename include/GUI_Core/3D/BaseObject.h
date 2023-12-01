#pragma once

#include <bgfx/bgfx.h>
#include <bx/uint32_t.h>

struct bgfx_mesh
{
    bgfx::VertexBufferHandle vbo;
    bgfx::IndexBufferHandle ibo;
    bgfx::VertexLayout layout;
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