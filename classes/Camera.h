// header class for camera
#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "Vec3.h"

#include <cmath>

class Camera
{
public:
    Vec3 position;
    Vec3 imageWidth;
    Vec3 imageHeight;
    Vec3 up;
    Vec3 right;
    Vec3 lookAt;
    float fov;
    float aspectRatio;
    int maxBounce;
    int imgWidth;
    int imgHeight;

    // Constructor
    Camera(Vec3 position, Vec3 lookAt, Vec3 up, float fov, float aspectRatio, int maxBounce, int imgHeight, int imgWidth)
    {
        this->position = position;
        this->lookAt = lookAt;
        this->up = up;
        this->fov = fov;
        this->aspectRatio = aspectRatio;
        this->maxBounce = maxBounce;

        this->imageWidth = (lookAt - position).normalize();
        this->imageHeight = this->imageWidth.cross(up).normalize();
        this->imageWidth = this->imageHeight.cross(this->imageWidth).normalize();

        this->imageWidth = this->imageWidth * std::tan(fov / 2);
        this->imageHeight = this->imageHeight * std::tan(fov / 2) / aspectRatio;
        this->imgHeight = 2 * std::tan(fov / 2);
        this->imgWidth = 2 * std::tan(fov / 2) / aspectRatio;
    }

    // default constructor
    Camera()
    {
        this->position = Vec3(0, 0, 0);
        this->lookAt = Vec3(0, 0, 0);
        this->up = Vec3(0, 0, 0);
        this->fov = 0;
        this->aspectRatio = 0;
        this->maxBounce = 0;
        this->imageWidth = Vec3(0, 0, 0);
        this->imageHeight = Vec3(0, 0, 0);
        this->imgHeight = 0;
        this->imgWidth = 0;
    }

    // getRay function
    Ray getRay(float x, float y) const
    {
        Vec3 dir = (this->imageWidth * (2 * x - 1) + this->imageHeight * (2 * y - 1) + lookAt - position).normalize();
        return Ray(position, dir);
    }
};

#endif