// class Light header
#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3.h"
#include "Color.h"

class Light
{
public:
    Vec3 direction;
    Color color;

    Light(const Vec3 &direction, const Color &color)
        : direction(direction), color(color)
    {
    }

    // default constructor
    Light()
    {
        direction = Vec3();
        color = Color();
    }
};

#endif