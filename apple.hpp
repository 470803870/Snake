#pragma once
#include <deque>
#include "Vector.hpp" 
class Apple
{
private:
    Vector m_apple;

public:
    Apple(const std::deque<Vector> &m_snake, const Vector & map);
    const Vector &getVector() const; 
};