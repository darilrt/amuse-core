#pragma once

#include <vector>
#include <array>

#include "core/math.hpp"
#include "core/gfx.hpp"
#include "types.hpp"

#define LAYER(x) (1 << x)

class GraphicObject
{
public:
    Shared<Mesh> mesh;

    void render(const Mat4 &view, const Mat4 &projection);
};

class GraphicManager
{
public:
    std::vector<Shared<GraphicObject>> objects;

    void add(Shared<GraphicObject> object);

    void render(const Mat4 &view, const Mat4 &projection, gfx::Framebuffer &framebuffer);

    void present(const Texture &texture);
};