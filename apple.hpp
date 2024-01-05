#pragma once
#include <deque>
#include "vector.hpp"
class apple
{
public:
    static Vector createApple(const std::deque<Vector> &snake, const short &height, const short &width);
};