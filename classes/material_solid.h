// header for material solid class
#ifndef MATERIAL_SOLID_H
#define MATERIAL_SOLID_H

#include "Color.h"
#include "Material.h"
#include "Vec3.h"

class MaterialSolid : public Material
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
    Color specularColor;

    // Default constructor 
    MaterialSolid()
    {
        this->color = Color(0.0f, 0.0f, 0.0f);
        this->ka = 0.0f;
        this->kd = 0.0f;
        this->ks = 0.0f;
        this->exponent = 0.0f;
        this->reflectance = 0.0f;
        this->transmittance = 0.0f;
        this->iof = 0.0f;
        this->specularColor = Color(1.0f, 1.0f, 1.0f);
    }

    MaterialSolid(Color color, float ka, float kd, float ks, float exponent, float reflectance, float transmittance, float iof, Color specularColor)
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

       Color shade(Vec3 intersection, Vec3 normal, Vec3 lightDirection, Vec3 viewDirection, Color lightColor);
};

Color MaterialSolid::shade(Vec3 intersection, Vec3 normal, Vec3 lightDirection, Vec3 viewDirection, Color lightColor)
{
    normal = normal.normalize();
    lightDirection = lightDirection.normalize();
    viewDirection = viewDirection.normalize();

    Color ambient = color * ka;

    float dotNL = normal.dot(lightDirection);
    Color diffuse = (dotNL > 0.0f) ? color * lightColor * (kd * dotNL) : Color(0, 0, 0);

    Vec3 reflectedLight = -lightDirection.reflect(normal);
    float dotRV = reflectedLight.dot(viewDirection);
    Color specular = (dotRV > 0.0f) ? specularColor * (ks * pow(dotRV, exponent)) : Color(0, 0, 0);

    Color resultColor = ambient + diffuse + specular;

    resultColor *= 0.9f;
    
    // Clamping color values to [0,1]
    resultColor.r = resultColor.r > 1.0f ? 1.0f : resultColor.r < 0.0f ? 0.0f : resultColor.r;
    resultColor.g = resultColor.g > 1.0f ? 1.0f : resultColor.g < 0.0f ? 0.0f : resultColor.g;
    resultColor.b = resultColor.b > 1.0f ? 1.0f : resultColor.b < 0.0f ? 0.0f : resultColor.b;

    return resultColor;
};

#endif