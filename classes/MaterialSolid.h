// header for material solid class
#ifndef MATERIALSOLID_H
#define MATERIALSOLID_H

#include "Color.h"
#include "Material.h"
#include "Vec3.h"

class MaterialSolidT3 : public Material
{
public:
    Color color;
    float ka;
    float kd;
    float ks;
    float exponent;
    float reflectance;
    float transmittance;
    float iof;
    float specularColor;

    // Default constructor 
    MaterialSolidT3()
    {
        this->color = Color(0.0f, 0.0f, 0.0f);
        this->ka = 0.0f;
        this->kd = 0.0f;
        this->ks = 0.0f;
        this->exponent = 0.0f;
        this->reflectance = 0.0f;
        this->transmittance = 0.0f;
        this->iof = 0.0f;
        this->specularColor = 0.0f;
    }

    MaterialSolidT3(Color color, float ka, float kd, float ks, float exponent, float reflectance, float transmittance, float iof, float specularColor)
    {
        this->color = color;
        this->ka = ka;
        this->kd = kd;
        this->ks = ks;
        this->exponent = exponent;
        this->reflectance = reflectance;
        this->transmittance = transmittance;
        this->iof = iof;
        this->specularColor = specularColor;
    }

    Color shade(Vec3 intersection, Vec3 normal, Vec3 light, Color light_color);
};

// Implement the shade function
Color MaterialSolidT3::shade(Vec3 intersection, Vec3 normal, Vec3 light, Color light_color)
{
    // Implement the shading logic here
    // You can use the intersection, normal, light direction, and light color to calculate the shaded color

    // Example implementation: Calculate diffuse reflection
    float diffuse_factor = normal.dot(light);
    if (diffuse_factor < 0.0f)
    {
        diffuse_factor = 0.0f;
    }

    Color diffuse_color = this->color * light_color * diffuse_factor;

    // Return the shaded color
    return diffuse_color;
};


#endif
