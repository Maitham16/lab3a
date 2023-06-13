#ifndef RAY_TRACE_H
#define RAY_TRACE_H

#include "sphereT3.h"
#include "Ray.h"
#include "Color.h"
#include "Vec3.h"
#include "MaterialSolid.h"
#include "Light.h"

#include <vector>
#include <iostream>
#include <cmath>

Color RayTrace(const Ray &ray, const std::vector<anotherSphere> &scene, const std::vector<Light> &lights, int maxDepth)
{
    if (maxDepth <= 0)
    {
        return Color(0.0f, 0.0f, 0.0f); // Return background color or terminate recursion
    }

    float t;
    int sphereIndex = -1;
    bool intersectionFound = false;

    // Find the closest intersection in the scene
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
        // Get the intersection point
        Vec3 intersection = ray.origin + ray.direction * t;

        // Get the normal at the intersection point
        Vec3 normal = (intersection - scene[sphereIndex].center).normalize();

        // Get the material of the intersected sphere
        MaterialSolidT3 material = scene[sphereIndex].material;

        // Calculate the color at the intersection point
        Color color = Color(0.0f, 0.0f, 0.0f);
        for (int i = 0; i < lights.size(); i++)
        {
            // Get the light direction
            Vec3 lightDirection = (lights[i].direction - intersection).normalize();
            Color lightColor = lights[i].color;

            // Calculate the shadow ray
            Ray shadowRay(intersection + lightDirection * 0.001f, lightDirection);

            // Check if the shadow ray intersects with any sphere
            bool shadowIntersectionFound = false;
            for (int j = 0; j < scene.size(); j++)
            {
                if (scene[j].intersect(shadowRay, t))
                {
                    shadowIntersectionFound = true;
                    break;
                }
            }

            // Calculate the color at the intersection point
            if (!shadowIntersectionFound)
            {
                color += material.shade(intersection, normal, lightDirection, lightColor);
            }
        }

        // Calculate the reflected ray
        Vec3 viewDirection = (Vec3(0, 0, 0) - intersection).normalize();
        Vec3 reflectedDirection = viewDirection.reflect(normal).normalize();
        Ray reflectedRay(intersection + reflectedDirection * 0.001f, reflectedDirection);

        // Calculate the color of the reflected ray
        Color reflectedColor = RayTrace(reflectedRay, scene, lights, maxDepth - 1);

        // Calculate the final color
        color += reflectedColor * material.specularColor;

        return color;
    }

    // Return background color if no intersection is found
    return Color(0.0f, 0.0f, 0.0f);
}

#endif