// header class for ray
#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray
{
    public:
        Vec3 origin, direction;
        Ray() : origin(Vec3()), direction(Vec3()) {}
        Ray(Vec3 origin, Vec3 direction) : origin(origin), direction(direction) {}
};

#endif