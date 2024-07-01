#pragma once

#include "core.hpp"

class Transform : public Component
{
public:
    Vec3 position;
    Quat rotation;
    Vec3 _euler_angles;
    Vec3 scale;

    Transform();
};