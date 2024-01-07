#pragma once
struct Vector
{
    short x, y;
    Vector() : x(0), y(0) {}
    Vector(const short &x, const short &y) : x(x), y(y) {}
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;
    void operator=(const Vector &other);
};