#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

class Material
{
public:
    Color color;
    Color diffuse_color;
    Color specular_color;
    float specular_exponent;

    // Default constructor
    Material()
    {
        diffuse_color = Color(0, 0, 0);
        specular_color = Color(0, 0, 0);
        specular_exponent = 0.0f;
    }

    Material(Color diffuse_color, Color specular_color, float specular_exponent)
    {
        this->diffuse_color = diffuse_color;
        this->specular_color = specular_color;
        this->specular_exponent = specular_exponent;
    }

    Color shade(Vec3 intersection, Vec3 normal, Vec3 light, Color light_color);
};

// Implement the shade function
Color Material::shade(Vec3 intersection, Vec3 normal, Vec3 light, Color light_color)
{
    // Implement the shading logic here
    // You can use the intersection, normal, light direction, and light color to calculate the shaded color

    // Example implementation: Calculate diffuse reflection
    float diffuse_factor = normal.dot(light);
    if (diffuse_factor < 0.0f)
    {
        diffuse_factor = 0.0f;
    }

    Color diffuse_color = this->diffuse_color * light_color * diffuse_factor;

    // Return the shaded color
    return diffuse_color;
}


#endif
