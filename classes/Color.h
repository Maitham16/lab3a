// header class for color
#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    float r, g, b;
    Color() : r(0), g(0), b(0) {}
    Color(float r, float g, float b) : r(r), g(g), b(b) {}

    // color operations
    Color operator+(const Color &c) const
    {
        return Color(r + c.r, g + c.g, b + c.b);
    }

    Color operator*(float scalar) const
    {
        return Color(r * scalar, g * scalar, b * scalar);
    }

    Color operator*(const Color &other) const
    {
        return Color(r * other.r, g * other.g, b * other.b);
    }

    Color operator/(float f) const
    {
        return Color(r / f, g / f, b / f);
    }

    Color &operator+=(const Color &c)
    {
        r += c.r;
        g += c.g;
        b += c.b;
        return *this;
    }

    Color &operator*=(const Color &c)
    {
        r *= c.r;
        g *= c.g;
        b *= c.b;
        return *this;
    }

    Color &operator*=(float f)
    {
        r *= f;
        g *= f;
        b *= f;
        return *this;
    }

    Color &operator/=(float f)
    {
        r /= f;
        g /= f;
        b /= f;
        return *this;
    }
};
#endif