// sphere class header
#ifndef SPHERET3_H
#define SPHERET3_H

#include "Vec3.h"
#include "Ray.h"
#include "MaterialSolid.h"
#include "Color.h"

class anotherSphere
{
public:
    Vec3 center;
    float radius;
    MaterialSolidT3 material;
    Color color;
    Vec3 position;

    // constructor center, radius, material, color
    anotherSphere(Vec3 center, float radius, MaterialSolidT3 material, Color color, Vec3 position)
    {
        this->center = center;
        this->radius = radius;
        this->material = material;
        this->color = color;
        this->position = position;
    }

    // intersect function
    bool intersect(const Ray &ray, float &t) const
    {
        Vec3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2 * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
        {
            return false;
        }

        float t0 = (-b - std::sqrt(discriminant)) / (2 * a);
        float t1 = (-b + std::sqrt(discriminant)) / (2 * a);

        if (t0 > t1)
        {
            std::swap(t0, t1);
        }

        if (t0 < 0)
        {
            t0 = t1;
        }

        if (t0 < 0)
        {
            return false;
        }

        t = t0;

        return true;
    }
};

#endif