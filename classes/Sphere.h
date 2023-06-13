// sphere class header
#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.h"
#include "Ray.h"
#include "Material.h"
#include "Color.h"

class Sphere
{
public:
    Vec3 center;
    float radius;
    Material material;
    Color color;

// sphere class constructor center, radius, material, color
    Sphere(const Vec3 &center, float radius, const Material &material, const Color &color)
        : center(center), radius(radius), material(material), color(color)
    {
    }

    bool intersect(const Ray &ray, float &t) const
    {
        Vec3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0f * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
        {
            return false;
        }

        float sqrtDiscriminant = std::sqrt(discriminant);
        float t1 = (-b - sqrtDiscriminant) / (2 * a);
        float t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 > t2)
        {
            std::swap(t1, t2);
        }

        if (t1 < 0)
        {
            t1 = t2;
            if (t1 < 0)
            {
                return false;
            }
        }

        t = t1;
        return true;
    }
};

#endif