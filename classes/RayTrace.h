#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "another_sphere.h"
#include "Ray.h"
#include "Color.h"
#include "Vec3.h"
#include "material_solid.h"
#include "Light.h"

#include <vector>
#include <iostream>
#include <cmath>

Color RayTrace(const Ray &ray, const std::vector<anotherSphere> &scene, const std::vector<Light> &lights, int maxDepth)
{
    if (maxDepth <= 0)
    {
        return Color(0.0f, 0.0f, 0.0f); 
    }

    float t;
    int sphereIndex = -1;
    bool intersectionFound = false;

    for (int i = 0; i < scene.size(); i++)
    {
        if (scene[i].intersect(ray, t))
        {
            sphereIndex = i;
            intersectionFound = true;
        }
    }

    if (intersectionFound)
    {
        Vec3 intersection = ray.origin + ray.direction * t;
        Vec3 normal = (intersection - scene[sphereIndex].center).normalize();
        MaterialSolid material = scene[sphereIndex].material;
        Color color = Color(0.0f, 0.0f, 0.0f);

        for (int i = 0; i < lights.size(); i++)
        {
            Vec3 lightDirection = (lights[i].direction - intersection).normalize();
            Color lightColor = lights[i].color;

            Ray shadowRay(intersection + lightDirection * 0.001f, lightDirection);
            bool shadowIntersectionFound = false;

            for (int j = 0; j < scene.size(); j++)
            {
                if (scene[j].intersect(shadowRay, t))
                {
                    shadowIntersectionFound = true;
                    break;
                }
            }

            if (!shadowIntersectionFound)
            {
                Vec3 viewDirection = -ray.direction;
                color += material.shade(intersection, normal, lightDirection, viewDirection, lightColor);
            }
        }

        return color;
    }

    return Color(0.0f, 0.0f, 0.0f); 
}

#endif