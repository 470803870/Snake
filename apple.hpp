#pragma once
#include <deque>
#include "Vector.hpp" 
class Apple
{
private:
    Vector m_apple;

public:
    Apple(const std::deque<Vector> &m_snake, const short &height, const short &width);
    Vector &getVector() const;
    void operator=(const Apple &apple);
};