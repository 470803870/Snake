#include "vector.hpp"

bool Vector::operator==(const Vector &other)
{
    return x == other.x && y == other.y;
}

bool Vector::operator!=(const Vector &other)
{
    return !(x == other.x && y == other.y);
}

void Vector::operator=(const Vector &other)
{
    x = other.x;
    y = other.y;
}