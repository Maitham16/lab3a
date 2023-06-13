// create a header for vector3 class
#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class Vec3
{
public:
    float x, y, z;
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    // vector addition
    Vec3 operator+(const Vec3 &v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    // vector subtraction
    Vec3 operator-(const Vec3 &v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    // vector multiplication
    Vec3 operator*(double scalar) const
    {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // vector division
    Vec3 operator/(float f) const
    {
        return Vec3(x / f, y / f, z / f);
    }

    // dot product
    float dot(const Vec3 &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    // cross product
    Vec3 cross(const Vec3 &v) const
    {
        return Vec3(y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
    }

    // vector normalization
    Vec3 normalize() const
    {
        float mag2 = x * x + y * y + z * z;
        if (mag2 > 0)
        {
            float invMag = 1 / sqrt(mag2);
            return Vec3(x * invMag, y * invMag, z * invMag);
        }

        return Vec3();
    }

    // vector output
    friend std::ostream &operator<<(std::ostream &os, const Vec3 &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    Vec3 reflect(const Vec3 &normal) const
    {
        return *this - normal * 2.0f * this->dot(normal);
    }

    // vector negation
    Vec3 operator-() const
    {
        return Vec3(-x, -y, -z);
    }
};

#endif